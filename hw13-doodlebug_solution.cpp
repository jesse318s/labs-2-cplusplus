#include <iostream>
#include <cstdlib>
#include <ctime>

const int GRID_SIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS = 5;

enum OrganismType { EMPTY, ANT, DOODLEBUG };

class Organism {
public:
	Organism(int x, int y) : x(x), y(y), moved(false), breedCounter(0) {}
	virtual ~Organism() {}

	virtual void move(Organism* grid[GRID_SIZE][GRID_SIZE]) = 0;

	virtual void breed(Organism* grid[GRID_SIZE][GRID_SIZE]) = 0;

	virtual OrganismType getType() = 0;

	bool hasMoved() const { return moved; }

	void setMoved(bool moved) { this->moved = moved; }

	int getX() const { return x; }

	int getY() const { return y; }

protected:
	int x, y;
	bool moved;
	int breedCounter;
};

class Ant : public Organism {
public:
	Ant(int x, int y) : Organism(x, y) {}

	void move(Organism* grid[GRID_SIZE][GRID_SIZE]) override;

	void breed(Organism* grid[GRID_SIZE][GRID_SIZE]) override;

	OrganismType getType() override { return ANT; }
};

class Doodlebug : public Organism {
public:
	Doodlebug(int x, int y) : Organism(x, y), starveCounter(0) {}

	void move(Organism* grid[GRID_SIZE][GRID_SIZE]) override;

	void breed(Organism* grid[GRID_SIZE][GRID_SIZE]) override;

	OrganismType getType() override { return DOODLEBUG; }

	bool isStarving() const { return starveCounter >= 3; }

private:
	int starveCounter;
};

void Ant::move(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	int direction = rand() % 4;
	int newX = x, newY = y;

	switch (direction) {
	case 0: newX = x - 1; break; // Up
	case 1: newX = x + 1; break; // Down
	case 2: newY = y - 1; break; // Left
	case 3: newY = y + 1; break; // Right
	}

	if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
		grid[newX][newY] = this;
		grid[x][y] = nullptr;
		x = newX;
		y = newY;
	}

	moved = true;
	breedCounter++;
}

void Ant::breed(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	if (breedCounter >= 3) {
		int direction = rand() % 4;
		int newX = x, newY = y;

		switch (direction) {
		case 0: newX = x - 1; break; // Up
		case 1: newX = x + 1; break; // Down
		case 2: newY = y - 1; break; // Left
		case 3: newY = y + 1; break; // Right
		}

		if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
			grid[newX][newY] = new Ant(newX, newY);
			breedCounter = 0;
		}
	}
}

void Doodlebug::move(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	int direction = rand() % 4;
	int newX = x, newY = y;
	bool ateAnt = false;

	for (int i = 0; i < 4; ++i) {
		switch (i) {
		case 0: newX = x - 1; newY = y; break; // Up
		case 1: newX = x + 1; newY = y; break; // Down
		case 2: newX = x; newY = y - 1; break; // Left
		case 3: newX = x; newY = y + 1; break; // Right
		}

		if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] != nullptr
			&& grid[newX][newY]->getType() == ANT) {
			delete grid[newX][newY];
			grid[newX][newY] = this;
			grid[x][y] = nullptr;
			x = newX;
			y = newY;
			ateAnt = true;
			starveCounter = 0;
			break;
		}
	}

	if (!ateAnt) {
		newX = x;
		newY = y;

		switch (direction) {
		case 0: newX = x - 1; break; // Up
		case 1: newX = x + 1; break; // Down
		case 2: newY = y - 1; break; // Left
		case 3: newY = y + 1; break; // Right
		}

		if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
			grid[newX][newY] = this;
			grid[x][y] = nullptr;
			x = newX;
			y = newY;
		}

		starveCounter++;
	}

	moved = true;
	breedCounter++;
}

void Doodlebug::breed(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	if (breedCounter >= 8) {
		int direction = rand() % 4;
		int newX = x, newY = y;

		switch (direction) {
		case 0: newX = x - 1; break; // Up
		case 1: newX = x + 1; break; // Down
		case 2: newY = y - 1; break; // Left
		case 3: newY = y + 1; break; // Right
		}

		if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE && grid[newX][newY] == nullptr) {
			grid[newX][newY] = new Doodlebug(newX, newY);
			breedCounter = 0;
		}
	}
}

void initializeGrid(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			grid[i][j] = nullptr;
		}
	}

	int antsPlaced = 0;

	while (antsPlaced < INITIAL_ANTS) {
		int x = rand() % GRID_SIZE;
		int y = rand() % GRID_SIZE;

		if (grid[x][y] == nullptr) {
			grid[x][y] = new Ant(x, y);
			antsPlaced++;
		}
	}

	int doodlebugsPlaced = 0;

	while (doodlebugsPlaced < INITIAL_DOODLEBUGS) {
		int x = rand() % GRID_SIZE;
		int y = rand() % GRID_SIZE;

		if (grid[x][y] == nullptr) {
			grid[x][y] = new Doodlebug(x, y);
			doodlebugsPlaced++;
		}
	}
}

void printGrid(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] == nullptr) {
				std::cout << "-";
			}
			else if (grid[i][j]->getType() == ANT) {
				std::cout << "o";
			}
			else if (grid[i][j]->getType() == DOODLEBUG) {
				std::cout << "X";
			}
		}

		std::cout << std::endl;
	}
}

void simulateStep(Organism* grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr && grid[i][j]->getType() == DOODLEBUG) grid[i][j]->setMoved(false);
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr && grid[i][j]->getType() == DOODLEBUG && !grid[i][j]->hasMoved())
				grid[i][j]->move(grid);
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr && grid[i][j]->getType() == ANT) grid[i][j]->setMoved(false);
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr && grid[i][j]->getType() == ANT && !grid[i][j]->hasMoved())
				grid[i][j]->move(grid);
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr) grid[i][j]->breed(grid);
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (grid[i][j] != nullptr && grid[i][j]->getType() == DOODLEBUG &&
				static_cast<Doodlebug*>(grid[i][j])->isStarving()) {
				delete grid[i][j];
				grid[i][j] = nullptr;
			}
		}
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));

	Organism* grid[GRID_SIZE][GRID_SIZE];

	initializeGrid(grid);

	while (true) {
		printGrid(grid);
		std::cout << "Press Enter to move to the next time step..." << std::endl;
		std::cin.get();
		simulateStep(grid);
	}

	return 0;
}
