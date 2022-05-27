#include<iostream>
#include<fstream>
#include"FordFulkerson.h"
#include"..\\Lab 1 real real\List.h"

using namespace std;

int main() {
	List<Arc*>* arcs = getArcs("Input.txt");
	List<string>* vertices = getVertices(arcs);

	cout << "Arcs in the graph: " << endl;
	Element_List<Arc*>* tempArc = arcs->head;
	while (tempArc != NULL) {
		cout << tempArc->data->vertex1 << "->" << tempArc->data->vertex2 << ": " << tempArc->data->flow << "/" << tempArc->data->throughput << endl;
		tempArc = tempArc->next;
	}

	int maxFlow = FordFulkerson(arcs, vertices);
	cout << "\nArcs in the graph after applying the Ford-Fulkerson algorithm: " << endl;
	tempArc = arcs->head;
	while (tempArc != NULL) {
		cout << tempArc->data->vertex1 << "->" << tempArc->data->vertex2 << ": " << tempArc->data->flow << "/" << tempArc->data->throughput << endl;
		tempArc = tempArc->next;
	}

	cout << "\nMaximum flow: " << maxFlow << endl;

	return 0;
}