#include <ncurses.h>

int input_number(int row, char *label) {
    int n;
    mvprintw(row, 0, "%s", label);
    echo();
    scanw("%d", &n);
    return n;
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    int selected = 0;
    int menu;

    while(1) {
        clear();
        mvprintw(0, 0, "========TerminalOS version 1.0 development=======");

        mvprintw(2, 0, selected == 0 ? "> Exit" : "  Exit");
        mvprintw(3, 0, selected == 1 ? "> Calculator" : "  Calculator");

        menu = getch();

        if (menu == KEY_UP) selected--;
        if (menu == KEY_DOWN) selected++;
        if (selected < 0) selected = 2;
        if (selected > 1) selected = 0;

        if (menu == 10 && selected == 0) break; // exit
        if (menu == 10 && selected == 1) { // calculator
            clear();

            int calc_selected = 0;
            int calc_menu;
            int running = 1;

            while(running) {

                mvprintw(0, 0, "Select calculator mode: ");

                mvprintw(2, 0, calc_selected == 0 ? "> Exit calculator" : "  Exit calculator");
                mvprintw(3, 0, calc_selected == 1 ? "> Plus" : "  Plus");
                mvprintw(4, 0, calc_selected == 2 ? "> Minus" : "  Minus");
                mvprintw(5, 0, calc_selected == 3 ? "> Multiplication" : "  Multiplication");
                mvprintw(6, 0, calc_selected == 4 ? "> Division" : "  Division");

                calc_menu = getch();

                if (calc_menu == KEY_UP) calc_selected--;
                if (calc_menu == KEY_DOWN) calc_selected++;
                if (calc_selected < 0) calc_selected = 4;
                if (calc_selected > 4) calc_selected = 0;

                if (calc_menu == 10) {
                    if (calc_selected == 0) {
                        running = 0;
                    } else {
                        clear();
                        int a = input_number(0, "Enter a: ");
                        int b = input_number(1, "Enter b: ");

                        int result;
                        switch (calc_selected) {
                            case 1: result = a + b; break;
                            case 2: result = a - b; break;
                            case 3: result = a * b; break;
                            case 4:
                                if (b == 0) { mvprintw(2, 0, "Error: div by 0"); getch(); continue; }
                                result = a / b; break;
                        }
                        mvprintw(2, 0, "Result: %d", result);
                        getch();
                        clear();
                    }
                }
            }
        }
    }
    endwin();
    return 0;
}
