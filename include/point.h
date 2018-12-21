#ifndef POINT_H
#define POINT_H

#include "coordinate.h"

namespace geodesy
{

class Point
{
public:
  Point(const Latitude &latitude, const Longitude &longitude);

  const Latitude &latitude() const;
  const Longitude &longitude() const;

  /// Returns the distance from this point to destination point(using haversine formula).
  /*!
    This function uses calculations on the basis of a spherical earth
    (ignoring ellipsoidal effects) � which is accurate enough for most purposes.

    \param point Latitude / longitude of destination point.
    \param radius (Mean)radius of earth(defaults to radius in 6371.0 metres).
    \returns Distance between this point and destination point, in same units as radius.

    @example
      Point p1{ 52.205, 0.119 };
      Point p2{ 48.857, 2.351 };
      auto d = p1.sphericalDistanceTo(p2); // 404.3 km
  */
  double sphericalDistanceTo(const Point &point, double radius = 6371.0);

private:
  Latitude m_latitude;
  Longitude m_longitude;
};

}

#endif // POINT_H
