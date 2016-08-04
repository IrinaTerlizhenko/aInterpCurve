#include "aInterpCurveCubic.h"

/**
* Cubic interpolation of curve.
* \param f, const std::vector<aPoint<T> > & - input known (sorted by x-coordinate) curve points.
* \param g, std::vector<aPoint<T> > & - output (sorted by x-coordinate) interpolated curve points.
*/
template<class T>
void aInterpCurveCubic<T>::make(const std::vector<aPoint<T> > &f, std::vector<aPoint<T> > &g) {
	std::cout << "Todo cubic curve make..." << std::endl;

	const int MIN_NODES = 4;

	if (f.size() < MIN_NODES) {
		m_isOK = false;
		m_lastError = "Too few points found to interpolate.";
		return;
	}

	m_isOK = true;
	g.clear();

	T a, b, c, d, y;
	aPoint<T> newPoint;
	int n = f.size();

	g.push_back(f[0]);
	
	T diff = f[1].x - f[0].x;
	for (int j = 1; j < diff; j++) {
		newPoint.x = f[0].x + j;
		a = f[2].y - f[0].y;
		b = f[0].y - f[1].y - a;
		c = 2 * (f[1].y - f[0].y); // (f[1].y - f[0].y) >> 1;
		d = f[0].y;
		T x = j / diff;
		T x2 = x * x;
		newPoint.y = a *x2 * x + b * x2 + c * x + d;
		g.push_back(newPoint);
	}


	for (int i = 1; i < n - 1; i++) {
		g.push_back(f[i]);
		diff = f[i + 1].x - f[i].x;
		for (int j = 1; j < diff; j++) {
			newPoint.x = f[i].x + j;
			a = f[i + 2].y - f[i + 1].y - f[i - 1].y + f[i].y;
			b = f[i - 1].y - f[i].y - a;
			c = f[i + 1].y - f[i - 1].y;
			d = f[i].y;
			T x = j / diff;
			T x2 = x * x;
			newPoint.y = a *x2 * x + b * x2 + c * x + d;
			g.push_back(newPoint);
		}
	}

	diff = f[n - 1].x - f[n - 2].x;
	for (int j = 1; j < diff; j++) {
		newPoint.x = f[n - 2].x + j;
		a = f[n - 1].y - f[n - 3].y;
		b = f[n - 3].y - f[n - 2].y - a;
		c = f[n - 1].y - f[n - 3].y;
		d = f[n - 2].y;
		T x = j / diff;
		T x2 = x * x;
		newPoint.y = a *x2 * x + b * x2 + c * x + d;
		g.push_back(newPoint);
	}

	g.push_back(f[n - 1]);
}

template class aInterpCurveCubic<float>;
template class aInterpCurveCubic<double>;