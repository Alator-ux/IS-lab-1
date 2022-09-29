#pragma once
#include <string>

template <typename T>
class Action {
	T (*func)(T);
	bool (*cba)(T);
	std::string string_value;
	bool is_empty;
public:
	Action(bool is_empty) {
		is_empty = true;
		string_value = "empty_action";
	}
	Action(T (*func)(T), const std::string& string_value, bool (*cba)(T) = nullptr) {
		this->func = func;
		this->cba = cba;
		this->string_value = string_value;
		this->is_empty = false;
	}
	T apply(T x) {
		if (is_empty) {
			return x;
		}
		else {
			return (*func)(x);
		}
	}
	bool can_be_applied(T x) {
		return (*cba)(x);
	}
	std::string str_value() {
		return string_value;
	}
};

template <typename T>
struct State {
	T data;
	State<T>* parent;
	Action<T>* action;
	State(T data, State<T>* parent, Action<T>* action) {
		this->data = data;
		this->parent = parent;
		this->action = action;
	}
};
