#pragma once
#include "PathfindNode.h"
#include <vector>
#include "ppm.h"
#include "PerlinNoise.h"

class PathfindingController
{
public:
	PathfindingController();
	PathfindingController(int width, int height);

	void Init(int width, int height);

	void Print();
	void Connect();

	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }
	bool GetIsDijkstraRunning() { return m_DijkstraRunning; }

	void StartDijkstra();
	bool RunningDijsktra();

private:
	int m_Width, m_Height;
	PerlinNoise m_Pn;
	std::vector<PathfindNode*> m_Nodes;
	bool m_DijkstraRunning;
	size_t start, end;

	int m_Iterations;

	PathfindNode* m_CurrentNode;


};
