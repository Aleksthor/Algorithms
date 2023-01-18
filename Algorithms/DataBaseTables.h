#pragma once

std::string;

class Fruits
{
public:
	Fruits()
		: m_Name(""), m_Index(NULL)
	{

	}

	Fruits(std::string name, int amount)
		: m_Name(name), m_Index(amount)
	{

	}

	std::string GetName() { return m_Name; }
	int GetIndex() { return m_Index; }

	bool operator==(const Fruits& Other) const
	{
		return Other.m_Name == m_Name;
	}

public:
	std::string m_Name;
	int m_Index;
};
