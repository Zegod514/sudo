#include"widget.h"
#include"sudoku.h"
int main() {
	Widget w(9 * WIDTH, 9 * HEIGHT);
	w.Show();
	Sudoku* pS = new Sudoku;
	ExMessage msg;
	BeginBatchDraw();
	while (1) {
		cleardevice();
		pS->DrawMap(); 
		FlushBatchDraw();
		while (peekmessage(&msg,EM_MOUSE)) {
			pS->MouseEvent(msg);
		}
	}
	EndBatchDraw();
	printf("ÓÎÏ·³É¹¦£¡\n");
	return 0;
}