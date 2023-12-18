#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_ROWS = 5;
const int MAX_COLS = 10;

// ������� ��� �������� ���������
void createMaze(char maze[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            if (rand() % 10 < 3) { // 30% ����������� ��������� ������ ������
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = ' ';
            }
        }
    }
    maze[0][0] = 'S'; // ��������� �������
    maze[MAX_ROWS - 1][MAX_COLS - 1] = 'E'; // �������� �������
}

// ������� ��� ����������� ��������� � ���������
void printMaze(char maze[MAX_ROWS][MAX_COLS]) {
    system("clear"); // ������� ������ (��� UNIX-�������� ������)
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// ������� ��� �������� �� ���������
void move(char maze[MAX_ROWS][MAX_COLS], string direction) {
    pair<int, int> currentPosition;
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            if (maze[i][j] == 'S') {
                currentPosition = make_pair(i, j);
            }
        }
    }

    if (direction == "UP" && currentPosition.first > 0 && maze[currentPosition.first - 1][currentPosition.second] != '#') {
        maze[currentPosition.first][currentPosition.second] = ' ';
        maze[currentPosition.first - 1][currentPosition.second] = 'S';
    }
    else if (direction == "DOWN" && currentPosition.first < MAX_ROWS - 1 && maze[currentPosition.first + 1][currentPosition.second] != '#') {
        maze[currentPosition.first][currentPosition.second] = ' ';
        maze[currentPosition.first + 1][currentPosition.second] = 'S';
    }
    else if (direction == "LEFT" && currentPosition.second > 0 && maze[currentPosition.first][currentPosition.second - 1] != '#') {
        maze[currentPosition.first][currentPosition.second] = ' ';
        maze[currentPosition.first][currentPosition.second - 1] = 'S';
    }
    else if (direction == "RIGHT" && currentPosition.second < MAX_COLS - 1 && maze[currentPosition.first][currentPosition.second + 1] != '#') {
        maze[currentPosition.first][currentPosition.second] = ' ';
        maze[currentPosition.first][currentPosition.second + 1] = 'S';
    }
}

// �������� �������
int main() {
    srand(time(0)); // ������������� ���������� ��������� �����

    char maze[MAX_ROWS][MAX_COLS];
    createMaze(maze);

    while (true) {
        printMaze(maze);

        string userInput;
        cout << "������� ����������� (UP/DOWN/LEFT/RIGHT): ";
        cin >> userInput;

        if (userInput == "QUIT") {
            break;
        }

        move(maze, userInput);

        pair<int, int> startPosition, endPosition;
        for (int i = 0; i < MAX_ROWS; ++i) {
            for (int j = 0; j < MAX_COLS; ++j) {
                if (maze[i][j] == 'S') {
                    startPosition = make_pair(i, j);
                }
                else if (maze[i][j] == 'E') {
                    endPosition = make_pair(i, j);
                }
            }
        }

        if (startPosition == endPosition) {
            cout << "�����������! �� �������� �������� �����!" << endl;
            break;
        }
    }

    return 0;
}
