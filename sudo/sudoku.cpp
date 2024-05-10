#include "sudoku.h"
#include"button.h"
#include"timer.h"

Sudoku::Sudoku()
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            int x = WIDTH * j;
            int y = HEIGHT * i;
            if (map[i][j] != 0) {
                rect.push_back(make_pair(false, new Button(x, y, WIDTH, HEIGHT, WHITE, to_string(map[i][j]))));
            }
            else {
                rect.push_back(make_pair(true, new Button(x, y, WIDTH, HEIGHT, LIGHTGRAY, to_string(map[i][j]))));
            }
        }
    }
}

void Sudoku::DrawMap()
{
    for (auto v : rect) {
        v.second->Show();
    }
    setlinestyle(PS_SOLID, 4);
    setlinecolor(BLACK);
    line(3 * WIDTH, 0, 3 * WIDTH, HEIGHT * 9);
    line(6 * WIDTH, 0, 6 * WIDTH, HEIGHT * 9);
    line(0, 3 * HEIGHT, WIDTH * 9, 3 * HEIGHT);
    line(0, 6 * HEIGHT, WIDTH * 9, 6 * HEIGHT);
}

int Sudoku::ClickButton(ExMessage& msg)
{
    for (int i = 0; i < rect.size(); i++) {
        if (rect[i].second->MouseEvent(msg) == true) {
            return i;
        }
    }
    return -1;
}

void Sudoku::MouseEvent(ExMessage& msg)
{
    int pos = ClickButton(msg);
    if (pos != -1 && rect[pos].first == true&&Timer::OnTimer(100,0)) {

        rect[pos].second->SetText();
    }
}

bool Sudoku::GameOver()
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            for (int n = 0; n < 9; n++) {
                if (n != j && map[i][n] == map[i][j])
                    return false;
            }
            for (int m = 0; m < 9; m++) {
                if (m != i && map[m][j] == map[i][j])
                    return false;
            }
            int p = i / 3 * 3;
            int q = j / 3 * 3;
            for (int x = p; x < p + 3; x++) {
                for (int y = q; y < q + 3; y++) {
                    if (x != i && j != y && map[x][y] == map[i][j])
                        return false;
                }
            }
        }
    }
    return true;
}
