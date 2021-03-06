#pragma once
#include "LevelFactory.h"

#include <tuple>
#include <memory>

using std::tuple;

#ifdef GENERATOR_EXPORTS
#define GENERATOR_API __declspec(dllexport)
#else
#define GENERATOR_API __declspec(dllimport)
#endif

namespace Generator
{
	class GENERATOR_API RandomObjectFactory :
		public LevelFactory
	{
	public:
		RandomObjectFactory();
		~RandomObjectFactory();

		void AddAlternativeFactory(float probability, LevelFactory* alternativeFactory);

		// Generates children for the parent
		virtual void GenerateLevel(shared_ptr<Item> parent, int childrenNumber, const Math::Matrix4& futureTransformation, const Math::Matrix4& worldMatrix, vector<shared_ptr<Item>>* itemVector);

	private:
		float _totalProbability;
		vector<tuple< float, LevelFactory*>> _alternativeFactories; // List of objects that might be created, the first element of the tuple is the probability of the object to be chosen, the second is factory to create the object
	};
}