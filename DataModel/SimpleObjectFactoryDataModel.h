#pragma once
#include "LevelFactoryDataModel.h"

#ifdef DATAMODEL_EXPORTS
#define DATAMODEL_API __declspec(dllexport)
#else
#define DATAMODEL_API __declspec(dllimport)
#endif

namespace DataModel
{
	class DATAMODEL_API SimpleObjectFactoryDataModel :
		public LevelFactoryDataModel
	{
	public:
		SimpleObjectFactoryDataModel();
		~SimpleObjectFactoryDataModel();

	protected:
		virtual LevelFactory* InternalRead(ifstream* stream, map<string, LevelFactory*>* previousFactories);
		virtual void InternalWrite(ofstream* stream, LevelFactory* factoryToWrite);
	};
}
