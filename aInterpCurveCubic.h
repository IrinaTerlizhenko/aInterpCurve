#ifndef _A_INTERPCURVE_CUBIC_H
#define _A_INTERPCURVE_CUBIC_H

#include <aInterpCurve.h>

/** \class aInterpCurveCubic
* \brief A cubic interpolation of 2D curve.
*
* Input coordinates of know curve points coordinates, the first derivatives are not applied.
* Output coordinates of interpolated curve points.
* \author Iryna Tserlizhenka
* \date 2016
*/
template <class T>
class aInterpCurveCubic : public aInterpCurveLinear<T> {

public:

	//! Default constructor. 
	aInterpCurveCubic() : aInterpCurveLinear() {
	};

	//! Virtual destructor.
	virtual ~aInterpCurveCubic() {
	};

	//! Calculate the interpolation on set of points f.
	virtual void make(const std::vector<aPoint<T> > &f, std::vector<aPoint<T> > &g);

}; // end of aInterpCurveCubic class description

#endif // _A_INTERPCURVE_CUBIC_H
