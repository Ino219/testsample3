#include "box.h"
#include"Field.h"

using namespace box_h;
using namespace testsample3;
using namespace System::Windows::Forms;

box::box() {
}

//フィールド番号の基準点からボックスを描画する
void box:: create_box(int index) {
	//該当するフィールド番号のフラグをtrueにセットする
	if (index < w_space*h_space) {
		f_list[index]->set_flg(true);
	}
	else {
		return;
	}
}