#pragma once
#include "FloatExpressionDataModel.h"
namespace DataModel
{
	class YCylinderDataModel :
		public FloatExpressionDataModel
	{
	public:
		YCylinderDataModel();
		~YCylinderDataModel();

	protected:
		// Concrete read, has to be implemented by any class implementing FloatExpressionDataModel.
		virtual FloatExpression* InternalRead(ifstream* stream, unordered_map<string, FloatExpression*>* previousExpressions);
		// Concrete write, has to be implemented by any class implementing FloatExpressionDataModel.
		virtual void InternalWrite(ofstream* stream, FloatExpression* expressionToWrite);
	};

}
