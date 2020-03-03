#ifndef mat_h
#define mat_h


#include <vector>

template<class DType> class mat {

protected:
	int lenRow, lenCol;
public:
	mat(int r, int c) : lenRow(r), lenCol(c) {}

};

#endif
/* End of File */