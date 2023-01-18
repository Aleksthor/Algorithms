#pragma once
#include <vector>

class NeuralNetwork
{
public:
	NeuralNetwork()
	{
	}


	void Init();
	void Layer1();
	void Layer2();

	int WhatNumberAmI();

private:
	static const int m_Size = 16;
	float m_Image[m_Size][m_Size]{  0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,
					
									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,

									0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f,
	};


	std::vector<float> m_Neurons;
	
	std::vector<float> m_Layer1;
	std::vector<float> m_Outcomes;
};


void NeuralNetwork::Init()
{
	m_Neurons.clear();
	m_Layer1.clear();
	m_Outcomes.clear();

	for (int i{}; i < m_Size ; i++)
	{
		for (int j{}; j < m_Size; j++)
		{
			m_Neurons.push_back(m_Image[j][i]);
		}
	}


	m_Layer1 = std::vector<float>(11);
	m_Outcomes = std::vector<float>(9);


}

void NeuralNetwork::Layer1()
{


	// First Neuron
	float temp{};

	int height = 5;
	int width = 4;
	
	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 6) + 16 * (i + 3)];
		}
	}
	m_Layer1[0] = temp / (height * width);

	// Second Neuron
	temp = 0.f;

	height = 5;
	width = 4;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 6) + 16 * (i + 8)];
		}
	}
	m_Layer1[1] = temp / (height * width);

	// Third Neuron
	temp = 0.f;

	width = 8;
	height = 3;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 4) + 16 * (i + 2)];
		}
	}
	m_Layer1[2] = temp / (height * width);

	// Forth Neuron
	temp = 0.f;

	width = 4;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 10) + 16 * (i + 3)];
		}
	}
	m_Layer1[3] = temp / (height * width);

	// Fifth Neuron
	temp = 0.f;

	width = 4;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 10 - i) + 16 * (i + 3)];
		}
	}
	m_Layer1[4] = temp / (height * width);

	// Sixth Neuron
	temp = 0.f;

	width = 4;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 5 - i) + 16 * (i + 8)];
		}
	}
	m_Layer1[5] = temp / (height * width);

	// Seventh Neuron
	temp = 0.f;

	width = 8;
	height = 3;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 4) + 16 * (i + 11)];
		}
	}
	m_Layer1[6] = temp / (height * width);

	// Eigth Neuron
	temp = 0.f;

	width = 4;
	height = 6;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 5) + 16 * (i + 6)];
		}
	}
	m_Layer1[7] = temp / (height * width);

	// Ninth Neuron
	temp = 0.f;

	width = 3;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 10) + 16 * (i + 8)];
		}
	}
	m_Layer1[8] = temp / (height * width);


	// Tenth Neuron
	temp = 0.f;

	width = 3;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 3) + 16 * (i + 3)];
		}
	}
	m_Layer1[9] = temp / (height * width);

	// Eleventh Neuron
	temp = 0.f;

	width = 3;
	height = 5;

	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			temp += m_Neurons[(j + 3) + 16 * (i + 8)];
		}
	}
	m_Layer1[10] = temp / (height * width);
}

void NeuralNetwork::Layer2()
{
	// Number 1
	float outcome{};

	outcome += m_Layer1[0];
	outcome += m_Layer1[0];

	m_Outcomes[0] = outcome / 2;

	// Number 2
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[3];
	outcome += m_Layer1[4];
	outcome += m_Layer1[5];
	outcome += m_Layer1[6];

	m_Outcomes[1] = outcome / 5;

	// Number 3
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[3];
	outcome += m_Layer1[4];
	outcome += m_Layer1[6];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];

	m_Outcomes[2] = outcome / 6;

	// Number 4
	outcome = 0.f;

	outcome += m_Layer1[3];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];
	outcome += m_Layer1[9];

	m_Outcomes[3] = outcome / 4;

	// Number 5
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[6];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];
	outcome += m_Layer1[9];

	m_Outcomes[4] = outcome / 5;

	// Number 6
	outcome = 0.f;

	outcome += m_Layer1[4];
	outcome += m_Layer1[6];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];
	outcome += m_Layer1[9];
	outcome += m_Layer1[10];

	m_Outcomes[5] = outcome / 6;

	// Number 7
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[4];
	outcome += m_Layer1[5];
	outcome += m_Layer1[7];

	m_Outcomes[6] = outcome / 4;

	// Number 8
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[3];
	outcome += m_Layer1[6];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];
	outcome += m_Layer1[9];
	outcome += m_Layer1[10];

	m_Outcomes[7] = outcome / 7;

	// Number 9
	outcome = 0.f;

	outcome += m_Layer1[2];
	outcome += m_Layer1[3];
	outcome += m_Layer1[7];
	outcome += m_Layer1[8];
	outcome += m_Layer1[9];


	m_Outcomes[8] = outcome / 5;


}

int NeuralNetwork::WhatNumberAmI()
{
	Init();
	Layer1();
	Layer2();

	int best{};

	for (size_t i{}; i < m_Outcomes.size(); i++)
	{
		if (m_Outcomes[i] > m_Outcomes[best])
		{
			best = i;
		}
	}
	return best + 1;
}
