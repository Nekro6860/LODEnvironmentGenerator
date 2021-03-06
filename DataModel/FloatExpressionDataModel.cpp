#include "stdafx.h"
#include "FloatExpressionDataModel.h"

#include "UtilityReaderWriter.h"


namespace DataModel
{
	FloatExpressionDataModel::FloatExpressionDataModel()
	{
	}


	FloatExpressionDataModel::~FloatExpressionDataModel()
	{
	}
	
	FloatExpression* FloatExpressionDataModel::Read(ifstream* stream, unordered_map<string, FloatExpression*>* previousExpressions)
	{
		// Set the name of the float expression, to be stored in the map.
		getline(*stream, _name);

		// Read the specific content of the float expression.
		// The concrete implementation is supposed to fill the _expression field.
		_expression = InternalRead(stream, previousExpressions);

		// The InternalRead has to have read something.
		if (_name.length() > 0 && _expression != NULL)
		{
			if (previousExpressions->find(_name) == previousExpressions->end())
			{
				// The values read are stored in the expressions map, with the name of the expression as the key.
				previousExpressions->insert(std::pair<string, FloatExpression*>(_name, _expression));
			}
			else
			{
				throw new std::invalid_argument("This float expression already exists.");
			}
		}
		else
		{
			// Otherwise, an exception is thrown.
			throw new std::invalid_argument("The float expression has not been read correctly.");
		}

		return _expression;
	}

	void FloatExpressionDataModel::Write(ofstream * stream, FloatExpression * expressionToWrite)
	{
	}

	FloatExpression * FloatExpressionDataModel::GetFloatExpressionByName(const string& name, unordered_map<string, FloatExpression*>* previousExpressions)
	{
		// If this factory is supposed to have a child.
		if (name != "NULL")
		{
			// Then look if this factory has been previously loaded.
			unordered_map<string, FloatExpression*>::iterator expressionIt = previousExpressions->find(name);
			if (expressionIt == previousExpressions->end())
			{
				throw new std::invalid_argument("Children float expression not previously read.");
			}

			// Register the found factory as the sublevel of future factory.
			return (*expressionIt).second;
		}

		return NULL;
	}
}