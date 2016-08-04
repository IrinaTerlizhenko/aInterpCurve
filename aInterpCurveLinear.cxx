#include <aInterpCurveLinear.h>

/**
* Linear interpolation of curve.
* \param f, const std::vector<aPoint<T> > & - input known (sorted by x-coordinate) curve points.
* \param g, std::vector<aPoint<T> > & - output (sorted by x-coordinate) interpolated curve points.
*/
template<class T>
void aInterpCurveLinear<T>::make(const std::vector<aPoint<T> > &f, std::vector<aPoint<T> > &g) {
	std::cout << "Todo linear curve make..." << std::endl;

	const int MIN_NODES = 2;

	if (f.size() < MIN_NODES) {
		m_isOK = false;
		m_lastError = "Too few points found to interpolate.";
		return;
	}

	m_isOK = true;
	g.clear();

	std::vector<aPoint<T> >::const_iterator it = f.begin();
	while (it != f.end() && it != f.end() - 1) {
		aPoint<T> curr = *it;
		g.push_back(curr);
		++it;
		T diff = it->x - curr.x;
		for (int i = 1; i < diff; i++) {
			aPoint<T> newPoint;
			newPoint.x = curr.x + i;
			newPoint.y = (curr.y * (diff - i) + it->y * i) / diff;
			g.push_back(newPoint);
		}
	}
}

template class aInterpCurveLinear<float>;
template class aInterpCurveLinear<double>;
