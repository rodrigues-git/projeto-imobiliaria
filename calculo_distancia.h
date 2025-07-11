#ifndef DISTANCIA_H
#define DISTANCIA_H

constexpr double EARTH_R = 6371.0; // Raio da Terra em km

double haversine(double lat1, double lon1, double lat2, double lon2);

#endif