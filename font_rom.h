#define CHAR_HEIGHT 14
#define CHAR_WIDTH 8

/*
	These are the character sprites that will go
	into the code page, they are 8x14 bytes each.
*/
const BYTE A[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,255 ,255 ,255 ,255 ,0 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 255 ,255 ,255 ,255 ,255 ,255 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 255 ,255 ,0 ,0 ,255 ,255 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE B[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE C[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE D[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE E[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE F[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE G[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE H[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE I[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE J[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE K[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE L[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE M[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE N[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE O[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE P[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE Q[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE R[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE S[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE T[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE U[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE V[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE W[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE X[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE Y[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};

const BYTE Z[CHAR_HEIGHT][CHAR_WIDTH] = {
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
	{0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
};


/*
	The code page mentioned earlier. Given the 
	appropriate ASCII value, it will return the
	correct char sprite. 
*/
const BYTE** codePage[0xFF] = {
	A, B, C
};

