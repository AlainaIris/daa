#include <cstdio>
#include <vector>
using namespace std;
struct Task {
	int start;
	int end;
};

vector<Task>* task_schedule(Task* tasks, int size) {
	int time = 0;
	vector<Task>* scheduledTasks = new vector<Task>;
	for (int i = 0; i < size; i++) {
		if (tasks[i].start >= time) {
			scheduledTasks->push_back(tasks[i]);
			time = tasks[i].end;
		}
	}
	return scheduledTasks;
}

int main() {
	Task* tasks;
	Task task1 = {0, 4};
	Task task2 = {1, 5};
	Task task3 = {4, 6};
	Task task4 = {5, 6};
	Task task5 = {5, 8};
	Task task6 = {8, 10};
	Task task7 = {11, 13};
	Task task8 = {14, 20};
	Task task9 = {16, 21};
	Task task10 = {24, 40};
	tasks = new Task[10] {task1, task2, task3, task4, task5, task6, task7, task8, task9, task10};
	vector<Task>* resultTasks = task_schedule(tasks, 10);
	int size = resultTasks->size();
	for (int i = 0; i < size; i++) {
		Task t = resultTasks->at(i);
		printf("Start: %d End: %d\n", t.start, t.end);
	}
	delete tasks;
	return 0;
}
