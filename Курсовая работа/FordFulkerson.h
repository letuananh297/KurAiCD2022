#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include "..\\Lab 1 real real\List.h"

class Arc {
public:
	string vertex1;
	string vertex2;
	int flow;
	int throughput;
	int rest;

	Arc() {
		this->vertex1 = "";
		this->vertex2 = "";
		this->flow = 0;
		this->throughput = 0;
		this->rest = 0;
	}
};

List<Arc*>* getArcs(string fileName) {
	fstream f;
	List<Arc*>* arcs = new List<Arc*>();
	f.open(fileName, ios::in);
	if (f.bad())
		cout << "Error while read file.";
	else {
		string line;
		string subLine;
		string::size_type pos = 0;
		while (getline(f, line)) {
			Arc* arc = new Arc();
			subLine = line;
			pos = line.find(' ');
			subLine.resize(pos);
			arc->vertex1 = subLine;
			line.erase(0, pos + 1);
			subLine = line;
			pos = line.find(' ');
			subLine.resize(pos);
			arc->vertex2 = subLine;
			line.erase(0, pos + 1);
			arc->throughput = stoi(line);
			arc->rest = stoi(line);
			arcs->pushback(arc);
		}
	}
	f.close();
	return arcs;
}

List<string>* getVertices(List<Arc*>* arcs) {
	List<string>* vertices = new List<string>();
	Element_List<Arc*>* temp = arcs->head;
	while (temp != NULL) {
		if (!vertices->contain(temp->data->vertex1))
			vertices->pushback(temp->data->vertex1);
		if (!vertices->contain(temp->data->vertex2))
			vertices->pushback(temp->data->vertex2);
		temp = temp->next;
	}
	return vertices;
}

string getSource(List<Arc*>* arcs, List<string>* vertices) {
	Element_List<string>* tempVertex = vertices->head;
	while (tempVertex != NULL) {
		bool check = 1;
		Element_List<Arc*>* tempArc = arcs->head;
		while (tempArc != NULL) {
			if (tempArc->data->vertex2 == tempVertex->data) {
				check = 0;
				break;
			}
			else
				tempArc = tempArc->next;
		}
		if (!check)
			tempVertex = tempVertex->next;
		else
			return tempVertex->data;
	}
	return "";
}

string getSink(List<Arc*>* arcs, List<string>* vertices) {
	Element_List<string>* tempVertex = vertices->head;
	while (tempVertex != NULL) {
		bool check = 1;
		Element_List<Arc*>* tempArc = arcs->head;
		while (tempArc != NULL) {
			if (tempArc->data->vertex1 == tempVertex->data) {
				check = 0;
				break;
			}
			else
				tempArc = tempArc->next;
		}
		if (!check)
			tempVertex = tempVertex->next;
		else
			return tempVertex->data;
	}
	return "";
}

bool haveWayFromSource(List<Arc*>* arcs, string source) {
	Element_List<Arc*>* tempArc = arcs->head;
	bool check = 0;
	while (tempArc != NULL) {
		if (tempArc->data->vertex1 == source) {
			if (tempArc->data->rest > 0) {
				check = 1;
				break;
			}
		}
		tempArc = tempArc->next;
	}
	return check;
}

bool haveWayToSink(List<Arc*>* arcs, string sink) {
	Element_List<Arc*>* tempArc = arcs->head;
	bool check = 0;
	while (tempArc != NULL) {
		if (tempArc->data->vertex2 == sink) {
			if (tempArc->data->rest > 0) {
				check = 1;
				break;
			}
		}
		tempArc = tempArc->next;
	}
	return check;
}

Arc* getArc(List<Arc*>* arcs, string vertex, string sink) {
	Element_List<Arc*>* tempArc = arcs->tail;
	Arc* result = NULL;
	while (tempArc != NULL) {
		if (tempArc->data->vertex1 == vertex) {
			if (tempArc->data->vertex2 == sink && tempArc->data->rest > 0) {
				result = tempArc->data;
				break;
			}
			else {
				if (tempArc->data->rest > 0)
					result = tempArc->data;
			}
		}
		tempArc = tempArc->prev;
	}
	return result;
}

List<Arc*>* getMinWay(List<Arc*>* arcs, List<string>* vertices) {
	string source = getSource(arcs, vertices);
	string sink = getSink(arcs, vertices);
	List<Arc*>* result = new List<Arc*>();
	string tempString = source;
	Arc* arc = new Arc();
	do {
		arc = getArc(arcs, tempString, sink);
		if (arc == NULL) {
			result->clear();
			break;
		}
		else {
			result->pushback(arc);
			tempString = arc->vertex2;
		}
	} while (arc->vertex2 != sink);
	return result;
}

int FordFulkerson(List<Arc*>* arcs, List<string>* vertices) {
	string source = getSource(arcs, vertices);
	string sink = getSink(arcs, vertices);
	int maxFlow = 0;
	while (haveWayFromSource(arcs, source) && haveWayToSink(arcs, sink)) {
		List<Arc*>* way = getMinWay(arcs, vertices);
		if (way->isEmpty())
			break;
		else {
			Element_List<Arc*>* tempWay = way->head;
			int min = tempWay->data->rest;
			while (tempWay != NULL) {
				if (tempWay->data->rest < min)
					min = tempWay->data->rest;
				tempWay = tempWay->next;
			}
			maxFlow += min;
			tempWay = way->head;
			while (tempWay != NULL) {
				Element_List<Arc*>* tempArc = arcs->head;
				while (tempArc != NULL) {
					if (tempWay->data->vertex1 == tempArc->data->vertex1 &&
						tempWay->data->vertex2 == tempArc->data->vertex2 &&
						tempWay->data->flow == tempArc->data->flow &&
						tempWay->data->throughput == tempArc->data->throughput &&
						tempWay->data->rest == tempArc->data->rest) {
						tempArc->data->flow += min;
						tempArc->data->rest -= min;
					}
					tempArc = tempArc->next;
				}
				tempWay = tempWay->next;
			}
		}
	}
	return maxFlow;
}