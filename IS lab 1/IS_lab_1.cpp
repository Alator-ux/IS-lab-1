#include <iostream>
#include "Structs.h"
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <chrono>

int plus3(int x) {
	return x + 3;
}
int mult2(int x) {
	return x * 2;
}
int minus2(int x) {
	return x - 2;
}
int minus3(int x) {
	return x - 3;
}
int div2(int x) {
	return x / 2;
}
int plus2(int x) {
	return x + 2;
}
inline long long milliseconds(std::chrono::steady_clock::time_point end, std::chrono::steady_clock::time_point begin)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}
void build_forward_way(State<int>* last) {
	auto st = std::stack<State<int>*>();
	st.push(last);
	while (last->parent != nullptr) {
		last = last->parent;
		st.push(last);
	}
	std::cout << "Way length = " << st.size() - 1 << std::endl;
	while (!st.empty()) {
		auto state = st.top();
		st.pop();
		if (st.size() > 0) {
			auto top = st.top();
			std::cout << state->data << " " << top->action->str_value() << " ->" << std::endl;
		}
		else {
			std::cout << state->data << std::endl;
		}
	}
}
void build_reverse_way(State<int>* first){
	size_t count = 0;
	while (first->parent != nullptr) {
		count++;
		std::cout << first->data << " <- " << first->action->str_value() << std::endl;
		first = first->parent;
	}
	std::cout << first->data << std::endl;
	std::cout << "Way length = " << count << std::endl;
}

void task1(int, int);
void task2(int, int);
void task3(int, int);

int main()
{
	//task1(1, 100);
	//task1(2, 55);
	//task1(2, 100);
	//task1(1, 97);
	//task1(2, 1000);
	//task1(3, 1001);
	//task1(3, 3001);
	task1(1, 10000001);

	//task2(1, 100);
	task2(1, 10000001);

	//task3(1, 100);
	task3(1, 10000001);
}

/*Time: 192640
Active states count: 3962455
Way length = 30
1 +3 ->
4 *2 ->
8 *2 ->
16 +3 ->
19 *2 ->
38 *2 ->
76 *2 ->
152 *2 ->
304 *2 ->
608 *2 ->
1216 +3 ->
1219 *2 ->
2438 +3 ->
2441 *2 ->
4882 *2 ->
9764 *2 ->
19528 +3 ->
19531 *2 ->
39062 *2 ->
78124 *2 ->
156248 *2 ->
312496 +3 ->
312499 *2 ->
624998 *2 ->
1249996 +3 ->
1249999 *2 ->
2499998 *2 ->
4999996 +3 ->
4999999 *2 ->
9999998 +3 ->
10000001
Time: 13
Active states count 103
1 <- -3
4 <- /2
8 <- /2
16 <- -3
19 <- /2
38 <- /2
76 <- /2
152 <- /2
304 <- /2
608 <- /2
1216 <- -3
1219 <- /2
2438 <- -3
2441 <- /2
4882 <- /2
9764 <- /2
19528 <- -3
19531 <- /2
39062 <- /2
78124 <- /2
156248 <- /2
312496 <- -3
312499 <- /2
624998 <- /2
1249996 <- -3
1249999 <- /2
2499998 <- /2
4999996 <- -3
4999999 <- /2
9999998 <- -3
10000001
Way length = 30
Time: 13
Active states count 466
Way length = 11
1 +3 ->
4 *2 ->
8 *2 ->
16 +3 ->
19 *2 ->
38 *2 ->
76 *2 ->
152 *2 ->
304 *2 ->
608 *2 ->
1216 +3 ->
1219
1219 <- /2
2438 <- -3
2441 <- /2
4882 <- /2
9764 <- /2
19528 <- -3
19531 <- /2
39062 <- /2
78124 <- /2
156248 <- /2
312496 <- -3
312499 <- /2
624998 <- /2
1249996 <- -3
1249999 <- /2
2499998 <- /2
4999996 <- -3
4999999 <- /2
9999998 <- -3
10000001
Way length = 19*/

/*
Time: 5716
Active states count: 1495415
Way length = 30
1 +3 ->
4 *2 ->
8 *2 ->
16 +3 ->
19 *2 ->
38 *2 ->
76 *2 ->
152 *2 ->
304 *2 ->
608 *2 ->
1216 +3 ->
1219 *2 ->
2438 +3 ->
2441 *2 ->
4882 *2 ->
9764 *2 ->
19528 +3 ->
19531 *2 ->
39062 *2 ->
78124 *2 ->
156248 *2 ->
312496 +3 ->
312499 *2 ->
624998 *2 ->
1249996 +3 ->
1249999 *2 ->
2499998 *2 ->
4999996 +3 ->
4999999 *2 ->
9999998 +3 ->
10000001
Time: 0
Active states count 103
1 <- -3
4 <- /2
8 <- /2
16 <- -3
19 <- /2
38 <- /2
76 <- /2
152 <- /2
304 <- /2
608 <- /2
1216 <- -3
1219 <- /2
2438 <- -3
2441 <- /2
4882 <- /2
9764 <- /2
19528 <- -3
19531 <- /2
39062 <- /2
78124 <- /2
156248 <- /2
312496 <- -3
312499 <- /2
624998 <- /2
1249996 <- -3
1249999 <- /2
2499998 <- /2
4999996 <- -3
4999999 <- /2
9999998 <- -3
10000001
Way length = 30
Time: 0
Active states count 459
Way length = 11
1 +3 ->
4 *2 ->
8 *2 ->
16 +3 ->
19 *2 ->
38 *2 ->
76 *2 ->
152 *2 ->
304 *2 ->
608 *2 ->
1216 +3 ->
1219
1219 <- /2
2438 <- -3
2441 <- /2
4882 <- /2
9764 <- /2
19528 <- -3
19531 <- /2
39062 <- /2
78124 <- /2
156248 <- /2
312496 <- -3
312499 <- /2
624998 <- /2
1249996 <- -3
1249999 <- /2
2499998 <- /2
4999996 <- -3
4999999 <- /2
9999998 <- -3
10000001
Way length = 19
*/

void task1(int begin, int end) {
	auto actions = std::vector<Action<int>>();

	std::string str_value = "*2";
	auto act = Action<int>(&mult2, str_value, [](int x) {return x > 0;});
	actions.push_back(act);

	str_value = "+3";
	act = Action<int>(&plus3, str_value, [](int x) {return true;});
	actions.push_back(act);

	str_value = "-2";
	act = Action<int>(&minus2, str_value, [](int x) {return x > 1;});
	actions.push_back(act);
	
	auto emp = Action<int>(true);


	std::set<int> visited = std::set<int>();
	std::vector<State<int>*> all_states = std::vector<State<int>*>();
	std::queue<State<int>*> active_states = std::queue<State<int>*>();
	active_states.push(new State<int>(begin, nullptr, &emp));

	auto time_start = std::chrono::high_resolution_clock::now();
	while (!active_states.empty()) {
		State<int>* parent = active_states.front();
		active_states.pop();

		State<int>* new_state;
		for (size_t i = 0; i < actions.size(); i++) {
			if (!actions[i].can_be_applied(parent->data)) {
				continue;
			}
			int new_data = actions[i].apply(parent->data);
			if (visited.find(new_data) == visited.end()) {
				if (new_data <= end) {
					new_state = new State<int>(new_data, parent, &actions[i]);
					active_states.push(new_state);
					all_states.push_back(new_state);
					visited.insert(new_data);
					if (new_data == end) {
						auto time_end = std::chrono::high_resolution_clock::now();
						std::cout << "Time: " << milliseconds(time_end, time_start) << std::endl;
						std::cout << "Active states count: " << active_states.size() << std::endl;
						build_forward_way(new_state);
						return;
					}
				}
			}
		}
	}
	std::cout << "Результат не был найден\n";
}

void task2(int begin, int end) {
	auto actions = std::vector<Action<int>>();

	std::string str_value = "/2";
	auto act = Action<int>(&div2, str_value, [](int x) {return x % 2 == 0;});
	actions.push_back(act);

	str_value = "-3";
	act = Action<int>(&minus3, str_value, [](int x) {return x > 2;});
	actions.push_back(act);

	str_value = "+2";
	act = Action<int>(&plus2, str_value, [](int x) {return true;});
	actions.push_back(act);

	auto emp = Action<int>(true);


	std::set<int> visited = std::set<int>();
	std::vector<State<int>*> all_states = std::vector<State<int>*>();
	std::queue<State<int>*> active_states = std::queue<State<int>*>();
	active_states.push(new State<int>(end, nullptr, &emp));

	auto time_start = std::chrono::high_resolution_clock::now();
	while (!active_states.empty()) {
		State<int>* parent = active_states.front();
		active_states.pop();

		State<int>* new_state;
		for (size_t i = 0; i < actions.size(); i++) {
			if (!actions[i].can_be_applied(parent->data)) {
				continue;
			}
			int new_data = actions[i].apply(parent->data);
			if (visited.find(new_data) == visited.end()) {
				if (new_data >= begin) {
					new_state = new State<int>(new_data, parent, &actions[i]);
					active_states.push(new_state);
					all_states.push_back(new_state);
					visited.insert(new_data);
					if (new_data == begin) {
						auto time_end = std::chrono::high_resolution_clock::now();
						std::cout << "Time: " << milliseconds(time_end, time_start) << std::endl;
						std::cout << "Active states count " << active_states.size() << std::endl;
						build_reverse_way(new_state);
						return;
					}
				}
			}
		}
	}
	std::cout << "Результат не был найден\n";
}

void task3(int begin, int end) {
	auto forward_acts = std::vector<Action<int>>();
	auto reverse_acts = std::vector<Action<int>>();

	std::string str_value = "*2";
	auto act = Action<int>(&mult2, str_value, [](int x) {return x > 0;});
	forward_acts.push_back(act);
	str_value = "+3";
	act = Action<int>(&plus3, str_value, [](int x) {return true;});
	forward_acts.push_back(act);
	str_value = "-2";
	act = Action<int>(&minus2, str_value, [](int x) {return x > 1;});
	forward_acts.push_back(act);

	str_value = "/2";
	act = Action<int>(&div2, str_value, [](int x) {return x % 2 == 0;});
	reverse_acts.push_back(act);
	str_value = "-3";
	act = Action<int>(&minus3, str_value, [](int x) {return x > 2;});
	reverse_acts.push_back(act);
	str_value = "+2";
	act = Action<int>(&plus2, str_value, [](int x) {return true;});
	reverse_acts.push_back(act);

	auto emp = Action<int>(true);


	std::set<int> forward_visited = std::set<int>();
	std::set<int> reverse_visited = std::set<int>();
	std::vector<State<int>*> all_states = std::vector<State<int>*>();
	std::queue<State<int>*> fas = std::queue<State<int>*>(); // forward_active_states 
	std::queue<State<int>*> ras = std::queue<State<int>*>(); // reverse_active_states 
	fas.push(new State<int>(begin, nullptr, &emp));
	ras.push(new State<int>(end, nullptr, &emp));

	State<int>* border_state;
	auto time_start = std::chrono::high_resolution_clock::now();
	while (!fas.empty() && !ras.empty()) {
		State<int>* parent = fas.front();
		fas.pop();

		State<int>* new_state;

		for (size_t i = 0; i < forward_acts.size(); i++) {
			if (!forward_acts[i].can_be_applied(parent->data)) {
				continue;
			}
			int new_data = forward_acts[i].apply(parent->data);
			if (forward_visited.find(new_data) == forward_visited.end()) {
				if (reverse_visited.find(new_data) != reverse_visited.end()) {
					border_state = *std::find_if(all_states.begin(), all_states.end(),
						[&new_data](const State<int>* st) {return st->data == new_data;});
					new_state = new State<int>(new_data, parent, &forward_acts[i]);
					auto time_end = std::chrono::high_resolution_clock::now();
					std::cout << "Time: " << milliseconds(time_end, time_start) << std::endl;
					std::cout << "Active states count " << fas.size() + ras.size() << std::endl;
					build_forward_way(new_state);
					build_reverse_way(border_state);
					return;
				}
				if (new_data <= end) {
					new_state = new State<int>(new_data, parent, &forward_acts[i]);
					fas.push(new_state);
					all_states.push_back(new_state);
					forward_visited.insert(new_data);
				}
			}
		}

		parent = ras.front();
		ras.pop();
		for (size_t i = 0; i < reverse_acts.size(); i++) {
			if (!reverse_acts[i].can_be_applied(parent->data)) {
				continue;
			}
			int new_data = reverse_acts[i].apply(parent->data);
			if (reverse_visited.find(new_data) == reverse_visited.end()) {
				if (forward_visited.find(new_data) != forward_visited.end()) {
					border_state = *std::find_if(all_states.begin(), all_states.end(),
						[&new_data](const State<int>* st) {return st->data == new_data;});
					new_state = new State<int>(new_data, parent, &reverse_acts[i]);
					auto time_end = std::chrono::high_resolution_clock::now();
					std::cout << "Time: " << milliseconds(time_end, time_start) << std::endl;
					std::cout << "Active states count " << fas.size() + ras.size() << std::endl;
					build_forward_way(border_state);
					build_reverse_way(new_state);
					return;
				}
				if (new_data >= begin) {
					new_state = new State<int>(new_data, parent, &reverse_acts[i]);
					ras.push(new_state);
					all_states.push_back(new_state);
					reverse_visited.insert(new_data);
				}
			}
		}
	}
	std::cout << "Результат не был найден\n";
}