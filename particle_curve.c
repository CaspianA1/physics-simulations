#include <curses.h>
#include <math.h>

const float ACCELERATION = -9.8;

// #define DEBUGGING
#define TRACE_PARTICLE

#ifdef DEBUGGING
#define debug(msg, ...) printf(msg, __VA_ARGS__)
#else
#define debug(msg, ...)
#endif

typedef struct {
	float y0, x0, v0y, v0x;
} Ball;

typedef struct {
	float y, x;
} Scalar;

#define get_pos(s0, v0s) b.s0 + (b.v0s * t) + (0.5 * ACCELERATION * (t * t))

int main() {
	int MAX_Y = 0, MAX_X = 0;
	#ifndef DEBUGGING
	initscr();
	cbreak();
	noecho();
	getmaxyx(stdscr, MAX_Y, MAX_X);
	#endif

	float t = 0;
	float y_begin = 0, x_begin = 0;
	float y_velocity_begin = 20, x_velocity_begin = 40;

	Ball b = {y_begin, x_begin, y_velocity_begin, x_velocity_begin};

	while (1) {
		#ifndef TRACE_PARTICLE
		clear();
		#endif

		Scalar s = {get_pos(y0, v0y), get_pos(x0, v0x)};
		debug("Scalar y and x: %f, %f\n", s.y, s.x);

		#ifndef DEBUGGING
		mvprintw(MAX_Y - (int) s.y, (int) s.x, "*");
		mvprintw(MAX_Y - 1, 0, "X and Y: %f, %f", s.x, s.y);
		refresh();
		#endif

		napms(1);
		t += 0.001;
	}

	#ifndef DEBUGGING
	endwin();
	#endif
}
