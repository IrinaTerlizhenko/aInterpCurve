#ifndef _A_INTERPCURVE_LINEAR_H
#define _A_INTERPCURVE_LINEAR_H

#include <aInterpCurve.h>

/** \class aInterpCurveLinear
* \brief A linear interpolation of 2D curve.
*
* Input coordinates of know curve points coordinates, the first derivatives are not applied.
* Output coordinates of interpolated curve points.
* \author Iryna Tserlizhenka
* \date 2016
*/
template <class T>
class aInterpCurveLinear : public aInterpCurve<T> {

public:

	//! Default constructor. 
	aInterpCurveLinear() {
		Init();
	};

	//! Virtual destructor.
	virtual ~aInterpCurveLinear() {
	};

	//! Calculate the interpolation on set of points f.
	virtual void make(const std::vector<aPoint<T> > &f, std::vector<aPoint<T> > &g);

	//!
	virtual bool isOK() {
		return m_isOK;
	};

	//!
	virtual std::string getLastError() {
		return m_lastError;
	};

	//! Set first derivative for the first point. Not used in this class.
	virtual void setDrvFirstPoint(T val) {
		//m_drvP1 = val; // not applied for this class
	};

	//! Set first derivative for the last point. Not used in this class.
	virtual void setDrvLastPoint(T val) {
		//m_drvP2 = val; // not applied for this class
	};

protected:

	//! State.
	int m_isOK;

	//! Last message.
	std::string m_lastError;

	void Init() { // Init method
				  //m_drvP1     = (T)0.0;
				  //m_drvP2     = (T)0.0;
		m_isOK = true;
		m_lastError = "";
	};

}; // end of aInterpCurveLinear class description

#endif // _A_INTERPCURVE_LINEAR_H
