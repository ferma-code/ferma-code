#include <ncurses.h>

void calc_exit_warning() {
    printw("Press any key to exit...\n");

    getch();
    clear();
    noecho();
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    // Warp
    int menu = 0;
    int menu_selected = 0;

    // For calculator
    cbreak();
    char op;
    int a, b;

    while (1) {
        clear();
        printw("Welcome to TUI-OS! (beta version)\n");

        mvprintw(2, 0, menu_selected == 0 ? "> Utilities" : "  Utilities");
        mvprintw(3, 0, menu_selected == 1 ? "> Games" : "  Games");
        mvprintw(4, 0, menu_selected == 2 ? "> Exit" : "  Exit");

        menu = getch();

        switch (menu) {
            case KEY_UP:
                menu_selected--;
                break;
            case KEY_DOWN:
                menu_selected++;
                break;
            case '\n':
                if (menu_selected == 2) {
                    clear();
                    endwin();
                    return 0;
                }
                if (menu_selected == 0) {

                    int menu_utilities = 0;
                    int utilities_selected = 0;

                    while (1) {
                        clear();

                        printw("Tab: Utilities");

                        mvprintw(2, 0, utilities_selected == 0 ? "> Calculator" : "  Calculator");
                        mvprintw(3, 0, utilities_selected == 1 ? "> Exit: Utilities" : "  Exit: Utilities");

                        menu_utilities = getch();

                        switch (menu_utilities) {
                            case KEY_UP:
                                utilities_selected--;
                                break;
                            case KEY_DOWN:
                                utilities_selected++;
                                break;
                            case '\n':
                                if (utilities_selected == 1)
                                if (utilities_selected == 0) {
                                    echo();
                                    clear();

                                    printw("Enter a example: ");
                                    scanw("%d %c %d", &a, &op, &b);

                                    switch (op) {
                                        case '+':
                                            printw("Answer: %d\n", a + b);
                                            calc_exit_warning();
                                            break;
                                        case '-':
                                            printw("Answer: %d\n", a - b);
                                            calc_exit_warning();
                                            break;
                                        case '*':
                                            printw("Answer: %d\n", a * b);
                                            calc_exit_warning();
                                            break;
                                        case '/':
                                            if (b == 0) {
                                                printw("You cannot divide by zero!\n");
                                                printw("Press any key to exit...\n");

                                                getch();
                                                clear();
                                                break;
                                            } else {
                                                printw("Answer: %d\n", a / b);
                                                calc_exit_warning();
                                                break;
                                            }
                                        default:
                                            printw("Error!\n");
                                            calc_exit_warning();
                                            break;
                                    }
                                }
                        }
                        if (menu_selected < 0) {
                            menu_selected = 0;
                        }
                        if (menu_selected > 0) {
                            menu_selected = 0;
                        }
                    }
                }
        }
        if (menu_selected < 0) {
            menu_selected = 2;
        }
        if (menu_selected > 2) {
            menu_selected = 0;
        }
        refresh();
    }
    endwin();
    return 0;
}
