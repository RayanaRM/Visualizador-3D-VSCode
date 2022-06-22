#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;


class JsonParser
{
public:
	string FilePath;

	JsonParser(string filePath)
	{
		FilePath = filePath;
	}

	vector <Objeto> getObjetos()
	{
		vector <Objeto> objetos;

		std::ifstream i(FilePath);
		nlohmann::json j;
		i >> j;

		for (int i = 0; i < j["objeto"].size(); i++){
			glm::vec3 positionTranslate;	
			float lightColor[3];
			float lightPosition[3];
			
			positionTranslate[0] = j["objeto"][i]["positionTranslate"][0];
			positionTranslate[1] = j["objeto"][i]["positionTranslate"][1];
			positionTranslate[2] = j["objeto"][i]["positionTranslate"][2];

			lightColor[0] = j["objeto"][i]["lightColor"][0];
			lightColor[1] = j["objeto"][i]["lightColor"][1];
			lightColor[2] = j["objeto"][i]["lightColor"][2];

			lightPosition[0] = j["objeto"][i]["lightPosition"][0];
			lightPosition[1] = j["objeto"][i]["lightPosition"][1];
			lightPosition[2] = j["objeto"][i]["lightPosition"][2];

			objetos.push_back(Objeto((int)j["objeto"][i]["id"], (bool)j["objeto"][i]["isSelected"], 
				(bool)j["objeto"][i]["hasCurves"], (float)j["objeto"][i]["escala"], positionTranslate, 
				(string)j["objeto"][i]["path"], lightColor, lightPosition));
		}

		return objetos;
	}
};
