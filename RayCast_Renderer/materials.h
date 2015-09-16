//-------------------------------------------------------------------------------
///
/// \file       materials.h 
/// \author     Cem Yuksel (www.cemyuksel.com)
/// \version    2.0
/// \date       September 3, 2015
///
/// \brief Example source for CS 6620 - University of Utah.
///
//-------------------------------------------------------------------------------

#ifndef _MATERIALS_H_INCLUDED_
#define _MATERIALS_H_INCLUDED_

#include "scene.h"

//-------------------------------------------------------------------------------

class MtlBlinn : public Material
{
public:
	MtlBlinn() : diffuse(0.5f,0.5f,0.5f), specular(0.7f,0.7f,0.7f), glossiness(20.0f) {}
	Color Shade(const Ray &ray, const HitInfo &hInfo, const LightList &lights) const 
	{

	const Material *m = hInfo.node->GetMaterial();
	const Node *tNode = hInfo.node;
	Color color;
	color.Set(0.0, 0.0, 0.0);
	int numLights = lights.size();

	for (int i = 0; i < numLights; i++) {

		Light *light = lights[i];

		if (light->IsAmbient()) {
			Color intensity = light->Illuminate(hInfo.p, hInfo.N);
			color += intensity ;
		}
		else {
			Point3 l = -light->Direction(hInfo.p);
			l.Normalize();

			Point3 v = -ray.dir;
			v.Normalize();

			Point3 n = hInfo.N;
			n.Normalize();

			Point3 half = v + l;
			half.Normalize();

			float amountOfLight = n.Dot(l);
			
			float halfDotN = half.Dot(n);
			float s = pow(halfDotN, glossiness);
			
			Color intensity = light->Illuminate(hInfo.p, hInfo.N);
			if (amountOfLight > 0)  {
				Color diffuseTerm = intensity * diffuse;
				Color specularTerm = intensity * specular;
				color += (diffuseTerm + specularTerm*s)*amountOfLight;
			}

		}
	}
	return color;
	}

	void SetDiffuse(Color dif) { diffuse = dif; }
	void SetSpecular(Color spec) { specular = spec; }
	void SetGlossiness(float gloss) { glossiness = gloss; }

	virtual void SetViewportMaterial(int subMtlID=0) const;	// used for OpenGL display

private:
	Color diffuse, specular;
	float glossiness;
};

//-------------------------------------------------------------------------------

#endif
