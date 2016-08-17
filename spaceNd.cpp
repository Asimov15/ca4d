#include "shared.h"

spaceNd::spaceNd(int dimensions, int* extents, bool isWrapped)
{
	this->dimensions = dimensions;
	this->extents = new int[dimensions];
	memcpy(this->extents, extents, sizeof(int)*dimensions);

	dimensionProducts = new int[dimensions];

	int cumulativeProducts = 1;
	for (int d = dimensions - 1; d >= 0; d--)
	{
		dimensionProducts[d] = cumulativeProducts;
		cumulativeProducts *= extents[d];
	}

	this->isWrapped = isWrapped;
	
	matrixSize = 1;
	for (int i = 0; i < dimensions; i++)
	{
		matrixSize *= extents[i];
	}
	
	bufferSize = matrixSize * 2 + 1;
	buffer = new unsigned char [bufferSize];
	memset(buffer, 0, sizeof(unsigned char)* bufferSize);

	nullCellIndex = bufferSize - 1;

	isSwapped = false;

	initializeAdjacencies();
}

inline bool spaceNd::allAreEqualTo(int* ordinates, int value)
{
	for (int dimension = 0; dimension < dimensions; dimension++)
	{
		if (ordinates[dimension] != value)
			return false;
	}
	return true;
}

inline void spaceNd::iterateOverOrdinates(int* ordinates, int* minimumOrdinates, int* maximumOrdinates)
{
	for (int dimension = dimensions - 1; dimension >= 0; dimension--)
	{
		if (ordinates[dimension] < (maximumOrdinates[dimension] - 1))
		{
			ordinates[dimension]++;
			break;
		}

		ordinates[dimension] = minimumOrdinates[dimension];
	}
}

inline int* spaceNd::createOrdinates(int defaultValue)
{
	int* ordinates = new int[dimensions];
	resetOrdinates(ordinates, defaultValue);
	return ordinates;
}

inline void spaceNd::resetOrdinates(int* ordinates, int defaultValue)
{
	for (int ordinate = 0; ordinate < dimensions; ordinate++)
		ordinates[ordinate] = defaultValue;
}

inline void spaceNd::addOrdinates(int* ordinates1, int* ordinates2, int* ordinatesSum)
{
	for (int ordinate = 0; ordinate < dimensions; ordinate++)
		ordinatesSum[ordinate] = ordinates1[ordinate] + ordinates2[ordinate];
}

void spaceNd::initializeAdjacencies()
{
	int nearbyCellCount = pow(3, dimensions);
	adjacenciesPerCellCount = nearbyCellCount - 1;
	cellAdjacencies = new int*[matrixSize * 2];

	int* ordinates = createOrdinates();
	int* adjacencyRelativeOrdinates = createOrdinates();
	int* adjacencyOrdinates = createOrdinates();

	int* minimumExtents = createOrdinates(0);
	int* minimumRelativeAdjacent = createOrdinates(-1);
	int* maximumRelativeAdjacent = createOrdinates(2);

	for (int useSwapped = 0; useSwapped < 2; useSwapped++) 
	{	
		resetOrdinates(ordinates, 0);
		for (int cellIndex = 0; cellIndex < matrixSize; cellIndex++)
		{
			int cellRealIndex = cellIndex + matrixSize * useSwapped;
			int* cellAdjacencyArray = cellAdjacencies[cellRealIndex] = new int[adjacenciesPerCellCount];		

			resetOrdinates(adjacencyRelativeOrdinates, -1);
			int adjacentOrdinateIndex = 0;
			for (int nearbyCellIndex = 0; nearbyCellIndex < nearbyCellCount; nearbyCellIndex++)
			{
				if (!allAreEqualTo(adjacencyRelativeOrdinates, 0))
				{
					addOrdinates(ordinates, adjacencyRelativeOrdinates, adjacencyOrdinates);

					int adjacentCellIndex = getIndex(adjacencyOrdinates, (bool)useSwapped);
					cellAdjacencyArray[adjacentOrdinateIndex] = adjacentCellIndex;
					adjacentOrdinateIndex++;
				}
				iterateOverOrdinates(adjacencyRelativeOrdinates, minimumRelativeAdjacent, maximumRelativeAdjacent);
			}
			iterateOverOrdinates(ordinates, minimumExtents, extents);
		}
	}

	delete ordinates;
	delete adjacencyRelativeOrdinates;
	delete adjacencyOrdinates;
	delete minimumExtents;
	delete minimumRelativeAdjacent;
	delete maximumRelativeAdjacent;
}


spaceNd::~spaceNd()
{
	delete buffer;

	for (int i = 0; i < matrixSize * 2; i++)
	{
		delete cellAdjacencies[i];
	}

	delete cellAdjacencies;

	delete dimensionProducts;
}

inline int spaceNd::getIndex(int* ordinates, bool useSwapped, bool check)
{
	if (isWrapped)
	{
		for (int d = 0; d < dimensions; d++)
		{
			ordinates[d] = (ordinates[d] + extents[d]) % extents[d];
		}
	}
	else if (check)
	{
		for (int d = 0; d < dimensions; d++)
		{
			if (ordinates[d] < 0 || ordinates[d] >= extents[d])
			{
				return nullCellIndex;
			}
		}
	}

	int index = 0;
	for (int d = 0; d < dimensions; d++)
	{
		index += ordinates[d] * dimensionProducts[d];
	}

	if (useSwapped) 
	{
		index += matrixSize;
	}

	return index;
}

unsigned char spaceNd::getCell(int* ordinates)
{
	return buffer[getIndex(ordinates, isSwapped)];
}

unsigned char spaceNd::getCell(int index)
{
	return buffer[getIndex(index, isSwapped)];
}

void spaceNd::setCell(int index, unsigned char newState)
{
	buffer[getIndex(index, !isSwapped)] = newState;
}

void spaceNd::setCell(int* ordinates, unsigned char newState)
{
	buffer[getIndex(ordinates, !isSwapped)] = newState;
}

void spaceNd::swap()
{
	isSwapped = !isSwapped;
}

float spaceNd::calculateAlivePercent()
{
	int zero = isSwapped ? matrixSize : 0;

	int count = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		count += buffer[zero + i];
	}

	return (float)count / (float)matrixSize;
}

float spaceNd::calculateChangePercent()
{
	int zero1 = 0;
	int zero2 = matrixSize;

	int count = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		bool isChanged = buffer[zero1 + i] != buffer[zero2 + i];
		count += (int)isChanged;
	}

	return (float)count / (float)matrixSize;
}

bool spaceNd::isDead()
{
	return calculateAlivePercent() < 0.00001;
}

bool spaceNd::isFilled()
{
	return calculateAlivePercent() > 0.99999;
}

int spaceNd::getIndex(int i, bool useSwapped)
{
	int index = matrixSize * (int)useSwapped + i;
	return index;
}

int* spaceNd::getAdjacencies(int i, bool useSwapped)
{
	return cellAdjacencies[getIndex(i, useSwapped)];
}


int spaceNd::countLiveAdjacencies(int index)
{
	int realIndex = getIndex(index, isSwapped);
	int* adj = cellAdjacencies[realIndex];

	int neighbours = 0;
	for (int i = 0; i < adjacenciesPerCellCount; i++)
	{
		neighbours += buffer[adj[i]];
	}

	return neighbours;
}
