#include "Objects.h"
#include "scene.h"
extern Camera camera;
bool Sphere::IntersectRay(const Ray &ray, HitInfo &hInfo, int hitSide) const
{

	Point3 d = ray.p;
	float a = ray.dir.Dot(ray.dir);
	float b = 2 * (d.Dot(ray.dir));
	float c = (d.Dot(d)) - 1;
	float radicand = (b*b) - (4.0f*a*c);
	if (radicand <= 0.0f) {
		return false;
	}
	float discriminant = sqrt(radicand);
	float t1 = (-b + discriminant) / (2*a);
	float t2 = (-b - discriminant) / (2*a);

	if (t2 < hInfo.z) {
		hInfo.z = t2;
		hInfo.p = ray.p + hInfo.z*ray.dir;
		hInfo.N = (hInfo.p - Point3(0, 0, 0)).GetNormalized();
		return true;
	}
	return false;

}

