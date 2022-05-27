#include "pch.h"
#include "gtest/gtest.h"
#include "..\Курсовая работа\FordFulkerson.h"

TEST(First_Test) {
	List<Arc*>* arcs = getArcs("test1.txt");
	List<string>* vertices = getVertices(arcs);
	int maxFlow = FordFulkerson(arcs, vertices);
	ASSERT_EQ(maxFlow, 5);
	Element_List<Arc*>* tempArc = arcs->head;
	ASSERT_EQ(tempArc->data->vertex1, "S");
	ASSERT_EQ(tempArc->data->vertex2, "O");
	ASSERT_EQ(tempArc->data->flow, 3);
	ASSERT_EQ(tempArc->data->throughput, 3);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "S");
	ASSERT_EQ(tempArc->data->vertex2, "P");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 3);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "O");
	ASSERT_EQ(tempArc->data->vertex2, "Q");
	ASSERT_EQ(tempArc->data->flow, 3);
	ASSERT_EQ(tempArc->data->throughput, 3);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "O");
	ASSERT_EQ(tempArc->data->vertex2, "P");
	ASSERT_EQ(tempArc->data->flow, 0);
	ASSERT_EQ(tempArc->data->throughput, 2);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "P");
	ASSERT_EQ(tempArc->data->vertex2, "R");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 2);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "Q");
	ASSERT_EQ(tempArc->data->vertex2, "R");
	ASSERT_EQ(tempArc->data->flow, 1);
	ASSERT_EQ(tempArc->data->throughput, 4);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "Q");
	ASSERT_EQ(tempArc->data->vertex2, "T");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 2);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "R");
	ASSERT_EQ(tempArc->data->vertex2, "T");
	ASSERT_EQ(tempArc->data->flow, 3);
	ASSERT_EQ(tempArc->data->throughput, 3);
}

TEST(Second_Test) {
	List<Arc*>* arcs = getArcs("test2.txt");
	List<string>* vertices = getVertices(arcs);
	int maxFlow = FordFulkerson(arcs, vertices);
	ASSERT_EQ(maxFlow, 4);
	Element_List<Arc*>* tempArc = arcs->head;
	ASSERT_EQ(tempArc->data->vertex1, "S");
	ASSERT_EQ(tempArc->data->vertex2, "O");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 2);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "S");
	ASSERT_EQ(tempArc->data->vertex2, "P");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 6);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "O");
	ASSERT_EQ(tempArc->data->vertex2, "Q");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 5);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "O");
	ASSERT_EQ(tempArc->data->vertex2, "R");
	ASSERT_EQ(tempArc->data->flow, 0);
	ASSERT_EQ(tempArc->data->throughput, 3);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "P");
	ASSERT_EQ(tempArc->data->vertex2, "R");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 2);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "Q");
	ASSERT_EQ(tempArc->data->vertex2, "R");
	ASSERT_EQ(tempArc->data->flow, 0);
	ASSERT_EQ(tempArc->data->throughput, 4);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "Q");
	ASSERT_EQ(tempArc->data->vertex2, "T");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 7);
	tempArc = tempArc->next;
	ASSERT_EQ(tempArc->data->vertex1, "R");
	ASSERT_EQ(tempArc->data->vertex2, "T");
	ASSERT_EQ(tempArc->data->flow, 2);
	ASSERT_EQ(tempArc->data->throughput, 3);
}