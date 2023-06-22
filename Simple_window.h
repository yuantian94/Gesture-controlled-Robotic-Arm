
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include"function.h"


using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Drill_Window :Window {
	Drill_Window(Point xy, int w, int h, const string& title);
	bool click1{ false };
	
private:
	Button Button_1;
	Button Button_2;
	Out_box Box_Result;



	static void cb_Button_1(Address, Address);
	static void cb_Button_2(Address, Address);

	void Button1();
	void Button2();

};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD