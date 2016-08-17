
class spaceNd
{

public:

	int bufferSize;

	int nullCellIndex;	

	bool isWrapped;

	bool isSwapped;

	int * dimensionProducts;

	void initializeAdjacencies();

	int * * cellAdjacencies;

	int adjacenciesPerCellCount;

	int* getAdjacencies(int index, bool useSwapped);

	inline int getIndex(int* ordinates, bool useSwapped, bool checkOrdinates = true);

	inline int getIndex(int index, bool useSwapped);



	spaceNd(int dimensions, int* extents, bool wrap = true);

	~spaceNd();

	inline int* createOrdinates(int defaultValue = 0);

	void resetOrdinates(int* ordinates, int defaultValue = 0);

	void addOrdinates(int* ordinates1, int* ordinates2, int* ordinatesSum);

	inline void iterateOverOrdinates(int* ordinates, int* minimumOrdinates, int* maximumOrdinates);

	inline bool allAreEqualTo(int* ordinates, int value);

	unsigned char* buffer;

	int dimensions;

	int matrixSize;

	int* extents;

	void swap();

	unsigned char getCell(int* ordinates);

	unsigned char getCell(int index);

	void setCell(int* ordinates, unsigned char newState);

	void setCell(int index, unsigned char newState);

	float calculateAlivePercent();

	float calculateChangePercent();

	bool isDead();

	bool isFilled();

	int countLiveAdjacencies(int index);

	
};

