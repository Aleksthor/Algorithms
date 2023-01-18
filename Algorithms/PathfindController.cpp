#include "PathfindingController.h"
#include <iostream>
#include "Termcolor.h"


PathfindingController::PathfindingController()
	: m_Height(0), m_Width(0), m_DijkstraRunning(false), m_CurrentNode(nullptr), start(0), end(0), m_Iterations(0)
{
	
}

PathfindingController::PathfindingController(int width, int height)
	: m_Width(width), m_Height(height), m_DijkstraRunning(false), m_CurrentNode(nullptr), start(0), end(0), m_Iterations(0)
{

}

void PathfindingController::Init(int width, int height)
{
	for (int i{}; i < height; i++)
	{
		for (int j{}; j < width; j++)
		{
			double seed1 = std::rand() % 50;
			double seed2 = std::rand() % 50;
			double seed3 = std::rand() % 50;

			m_Nodes.push_back(new PathfindNode(Vec2(j, i)));
			double x1 = m_Nodes[m_Nodes.size() - 1]->GetPosition().x + seed1 / 1000.f;
			double y1 = m_Nodes[m_Nodes.size() - 1]->GetPosition().y + seed1 / 1000.f;
			double n1 = m_Pn.noise(x1 * 3333.f, y1 * 3333.f, 100.f);

			if (n1 < 0.4f)
			{
				m_Nodes[(i * m_Width) + j]->SetIsActive(false);
			}
		}
	}
}

void PathfindingController::Print()
{
	for (int i{}; i < m_Nodes.size(); i++)
	{
		if (i % m_Width == 0 && i != 0)
		{
			std::cout << std::endl << std::endl;
		}
		if (m_Nodes[i]->GetIsActive())
		{
			if (i == start)
			{
				std::cout << termcolor::green << " * " << termcolor::reset;
			}
			else if (i == end)
			{
				std::cout << termcolor::red << " * " << termcolor::reset;
			}
			else if (m_Nodes[i]->GetIsMarkedAsFastest())
			{
				std::cout << termcolor::blue << " * " << termcolor::reset;
			}
			else
			{
				std::cout << " * ";

			}
		}
		else
		{
			std::cout << "   ";
		}
	}
}

void PathfindingController::Connect()
{
	for (int i{}; i < m_Nodes.size(); i++)
	{

		//North
		if ((i - m_Width) >= 0)
		{
			if (m_Nodes[i - m_Width]->GetIsActive())
				m_Nodes[i]->SetNorth(m_Nodes[i - m_Width]);
		}
		//South
		if (i + m_Width < m_Nodes.size())
		{
			if (m_Nodes[i + m_Width]->GetIsActive())
				m_Nodes[i]->SetSouth(m_Nodes[i + m_Width]);
		}
		//East
		if (i + 1 < m_Nodes.size() && (i + 1) % m_Width != 0)
		{
			if (m_Nodes[i + 1]->GetIsActive())
				m_Nodes[i]->SetEast(m_Nodes[i + 1]);
		}
		//West
		if (i - 1 >= 0 && (i - 1) % m_Width != m_Width - 1)
		{
			if (m_Nodes[i - 1]->GetIsActive())
				m_Nodes[i]->SetWest(m_Nodes[i - 1]);
		}



		//NorthWest
		if (i - m_Width - 1 >= 0 && (i - m_Width - 1) % m_Width != m_Width - 1)
		{
			if (m_Nodes[i - m_Width - 1]->GetIsActive())
				m_Nodes[i]->SetNW(m_Nodes[i - m_Width - 1]);
		}
		//NorthEast
		if (i - m_Width + 1 >= 0 && (i + 1 + m_Width) % m_Width != 0)
		{
			if (m_Nodes[i - m_Width + 1]->GetIsActive())
				m_Nodes[i]->SetNE(m_Nodes[i - m_Width + 1]);
		}
		//SouthEast
		if (i + m_Width + 1 < m_Nodes.size() - 1 && (i + 1 + m_Width) % m_Width != 0)
		{
			if (m_Nodes[i + m_Width + 1]->GetIsActive())
				m_Nodes[i]->SetSW(m_Nodes[i + m_Width + 1]);
		}
		//SouthWest
		if (i + m_Width - 1 < m_Nodes.size() && !((i - 1 + m_Width) % m_Width == m_Width - 1))
		{
			if (m_Nodes[i + m_Width - 1]->GetIsActive())
				m_Nodes[i]->SetSW(m_Nodes[i + m_Width - 1]);
		}
	}
}

void PathfindingController::StartDijkstra()
{
	m_Nodes.clear();

	Init(m_Width, m_Height);
	Connect();
	size_t size = m_Nodes.size();

	m_Iterations = 0;

	for (int i{}; i < size; i++)
	{
		m_Nodes[i]->SetTotalCost(INT_MAX);
		m_Nodes[i]->SetIsVisted(false);
		m_Nodes[i]->SetPreviousNode(nullptr);
		m_Nodes[i]->SetIsMarkedAsFastest(false);
	}

	start = std::rand() % size;
	while (!m_Nodes[start]->GetIsActive())
	{
		start = std::rand() % size;
	}
	end = std::rand() % size;
	while (!m_Nodes[end]->GetIsActive() && end != start)
	{
		end = std::rand() % size;
	}
	
	std::cout << Vec2::Length(m_Nodes[start]->GetPosition(), m_Nodes[end]->GetPosition());


	m_CurrentNode = m_Nodes[start];
	m_CurrentNode->SetTotalCost(0);
	m_DijkstraRunning = true;
}

bool PathfindingController::RunningDijsktra()
{
	if (m_Iterations > m_Nodes.size() * 5)
	{
		std::cout << "Can't find the target" << std::endl;
		m_DijkstraRunning = false;
		return true;
	}

	m_Iterations++;
	PathfindNode* CheckingNode;
	if (m_CurrentNode->GetNorth() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetNorth();
		int cost = m_CurrentNode->GetTotalCost()  + 10;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetSouth() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetSouth();
		int cost = m_CurrentNode->GetTotalCost()  + 10;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetEast() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetEast();
		int cost = m_CurrentNode->GetTotalCost()  + 10;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetWest() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetWest();
		int cost = m_CurrentNode->GetTotalCost()  + 10;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetNW() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetNW();
		int cost = m_CurrentNode->GetTotalCost()  + 14;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetNE() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetNE();
		int cost = m_CurrentNode->GetTotalCost()  + 14;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetSW() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetSW();
		int cost = m_CurrentNode->GetTotalCost()  + 14;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}
	if (m_CurrentNode->GetSE() != nullptr)
	{
		CheckingNode = m_CurrentNode->GetSE();
		int cost = m_CurrentNode->GetTotalCost()  + 14;
		if (cost < CheckingNode->GetTotalCost())
		{
			CheckingNode->SetTotalCost(cost);
			CheckingNode->SetPreviousNode(m_CurrentNode);
		}
	}

	m_CurrentNode->SetIsVisted(true);

	bool isDone = true;
	for (int i{}; i < m_Nodes.size(); i++)
	{
		if (!m_Nodes[i]->GetVisited() && m_Nodes[i]->GetIsActive())
		{
			isDone = false;
		}
	}

	if (!isDone)
	{
		int bestIndex{};
		int best = INT_MAX;


		for (int i{}; i < m_Nodes.size(); i++)
		{
			if (!m_Nodes[i]->GetVisited() && m_Nodes[i]->GetIsActive())
			{
				if (m_Nodes[i]->GetTotalCost() < best)
				{
					best = m_Nodes[i]->GetTotalCost();
					bestIndex = i;
				}
			}
		}

		m_CurrentNode = m_Nodes[bestIndex];
		return false;
	}
	else
	{
		int iterations{};
		m_CurrentNode = m_Nodes[end];
		while (m_CurrentNode != m_Nodes[start] && !(iterations > m_Nodes.size()))
		{
			iterations++;
			m_CurrentNode->SetIsMarkedAsFastest(true);
			m_CurrentNode = m_CurrentNode->GetPreviousNode();
		}
		if (iterations > m_Nodes.size())
		{
			std::cout << "couldnt connect" << std::endl;
		}

		m_DijkstraRunning = false;
		return true;
	}


	
}


