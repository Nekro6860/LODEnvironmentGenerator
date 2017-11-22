#pragma once
#include "LevelFactory.h"
#include "Matrix4.h"

using namespace Math;

#ifdef GENERATOR_EXPORTS
#define GENERATOR_API __declspec(dllexport)
#else
#define GENERATOR_API __declspec(dllimport)
#endif

namespace Generator
{
	class GENERATOR_API TransformationFactory :
		public LevelFactory
	{
	public:
		TransformationFactory();
		TransformationFactory(LevelFactory* factory, Matrix4 transformation);
		~TransformationFactory();

		// Generates children for the parent
		virtual vector<Item*> GenerateLevel(Item* parent, int childrenNumber, const Matrix4* futureTransformation, const Matrix4* worldMatrix);

	private:
		LevelFactory* _factory;
		Matrix4 _transformation;
	};


}