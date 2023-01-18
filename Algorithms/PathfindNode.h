#pragma once
#include "MyMath.h"

class PathfindNode
{
public:
	PathfindNode()
	{
		m_IsVisited = false;
		m_PreviousNode = nullptr;

		m_North = nullptr;
		m_South = nullptr;
		m_East = nullptr;
		m_West = nullptr;

		m_NW = nullptr;
		m_NE = nullptr;
		m_SW = nullptr;
		m_SE = nullptr;

		m_TotalCost = 0;
		m_IsActive = true;
		m_MarkedAsFastest = false;


	}	

	PathfindNode(Vec2 pos)
		: m_Position(pos)
	{
		m_IsVisited = false;
		m_PreviousNode = nullptr;

		m_North = nullptr;
		m_South = nullptr;
		m_East = nullptr;
		m_West = nullptr;

		m_NW = nullptr;
		m_NE = nullptr;
		m_SW = nullptr;
		m_SE = nullptr;

		m_TotalCost = 0;
		m_IsActive = true;
		m_MarkedAsFastest = false;


	}

	// SETTERS
	void SetPosition(int x, int y) { m_Position = Vec2(x, y); }
	void SetIsVisted(bool visited) { m_IsVisited = visited; }
	void SetIsActive(bool active) { m_IsActive = active; }
	void SetIsMarkedAsFastest(bool markedAsFastest) { m_MarkedAsFastest = markedAsFastest; }
	void SetPreviousNode(PathfindNode* node) { m_PreviousNode = node; }

	void SetNorth(PathfindNode* north) { m_North = north; }
	void SetSouth(PathfindNode* south) { m_South = south; }
	void SetEast(PathfindNode* east) { m_East = east; }
	void SetWest(PathfindNode* west) { m_West = west; }

	void SetNW(PathfindNode* nw) { m_NW = nw; }
	void SetNE(PathfindNode* ne) { m_NE = ne; }
	void SetSW(PathfindNode* sw) { m_SW = sw; }
	void SetSE(PathfindNode* se) { m_SE = se; }

	void SetTotalCost(int totalCost) { m_TotalCost = totalCost; }



	// GETTERS
	Vec2 GetPosition() { return m_Position; }
	bool GetVisited() { return m_IsVisited; }
	bool GetIsActive() { return m_IsActive; }
	bool GetIsMarkedAsFastest() { return m_MarkedAsFastest; }
	PathfindNode* GetPreviousNode() { return m_PreviousNode; }

	PathfindNode* GetNorth() { return m_North; }
	PathfindNode* GetSouth() { return m_South; }
	PathfindNode* GetEast() { return m_East; }
	PathfindNode* GetWest() { return m_West; }

	PathfindNode* GetNW() { return m_NW; }
	PathfindNode* GetNE() { return m_NE; }
	PathfindNode* GetSW() { return m_SW; }
	PathfindNode* GetSE() { return m_SE; }

	int GetTotalCost() { return m_TotalCost; }



private:
	Vec2 m_Position;
	bool m_IsActive;
	bool m_MarkedAsFastest;


	PathfindNode* m_North;
	PathfindNode* m_South;
	PathfindNode* m_East;
	PathfindNode* m_West;

	PathfindNode* m_NW;
	PathfindNode* m_NE;
	PathfindNode* m_SW;
	PathfindNode* m_SE;

	// Dijkstra
	bool m_IsVisited;
	PathfindNode* m_PreviousNode;
	int m_TotalCost;
};