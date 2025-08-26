#include "ui.h"
#include "io.h"
#include "analyze.h"
#include <stdbool.h>
#include <stdio.h>

//
// Private
//
static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];
	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}


static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", 'a'+i, options[i]);
	}
}

void print_result(result_t result[RESULT_ROWS], int n){
	printf("Size\t\tTime T(s)\t\tT/log(n)\t\tT/(n)\t\t\tT/n*log(n)\t\tT/(n^2)\t\t\tT/(n^3)\n");
	int i=0; 
	while (i<RESULT_ROWS){
	printf("%d\t\t%.8lf\t\t%.8e\t\t%.8e\t\t%.8e\t\t%.8e\t\t%.8e \n", result[i].size, result[i].time, result[i].time / log(result[i].size), result[i].time / result[i].size, result[i].time / result[i].size * log(result[i].size),   result[i].time /(pow(result[i].size, 2)), result[i].time / (pow(result[i].size, 3)));
	i++;
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu",
		"Exit\n",
		"Bubble sort best case",
		"Bubble sort worst case",
		"Bubble sort average case\n",
		"Insertion sort best case",
		"Insertion sort worst case", 
		"Insertion sort average case\n", 
		"Quick sort best case", 
		"Quick sort worst case",
		"Quick sort average case\n",
		"Linear search best case",
		"Linear search worst case",
		"Linear search average case\n",
		"Binary search best case", 
		"Binary search worst case", 
		"Binary search average",
	
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);

}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	result_t result[RESULT_ROWS];

	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case 'a':
				show_menu = true;
				break;

			case 'b':
				running = false;
				break;

			case 'c':
				benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				printf("Bubble sort best case\n\n"); 
				print_result(result, RESULT_ROWS);
				break;
				
			case 'd': 
				benchmark(bubble_sort_t, worst_t, result, RESULT_ROWS);
				printf("Bubble sort worst case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'e': 
				benchmark(bubble_sort_t, average_t, result, RESULT_ROWS);
				printf("Bubble sort average case\n\n");
				print_result(result,RESULT_ROWS);
				break;
				
			case 'f': 
				benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);	
				printf("Insertion sort best case\n\n");			
				print_result(result, RESULT_ROWS);
				break;
				
			case 'g': 
				benchmark(insertion_sort_t, worst_t, result, RESULT_ROWS);
				printf("Insertion sort worst case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'h': 
				benchmark(insertion_sort_t, average_t, result, RESULT_ROWS);
				printf("Insertion sort average case\n\n");
				print_result(result, RESULT_ROWS);
				break;
			
			case 'i': 
				benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				printf("Quick sort best case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'j': 
				benchmark(quick_sort_t, worst_t, result, RESULT_ROWS);
				printf("Quick sort worst case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'k': 
				benchmark(quick_sort_t, average_t, result, RESULT_ROWS);
				printf("Quick sort average case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'l': 
				benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				printf("Linear search best case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'm': 
				benchmark(linear_search_t, worst_t, result, RESULT_ROWS);
				printf("Linear search worst case\n\n");
				print_result(result, RESULT_ROWS);
				break;

			case 'n': 
				benchmark(linear_search_t, average_t, result, RESULT_ROWS);
				printf("Linear search average case\n\n");
				print_result(result, RESULT_ROWS);
				break;
				
			case 'o':
				benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				printf("binary search best case\n\n");
				print_result(result, RESULT_ROWS);
				break;
				
			case 'p':
				benchmark(binary_search_t, worst_t, result, RESULT_ROWS);
				printf("Binary search worst case\n\n");
				print_result(result, RESULT_ROWS);
				break;
				
			case 'q':
				//type = "binary search : average";
				benchmark(binary_search_t, average_t, result, RESULT_ROWS);
				printf("Binary search average case\n\n");
				print_result(result, RESULT_ROWS);
			
				break;
			
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
