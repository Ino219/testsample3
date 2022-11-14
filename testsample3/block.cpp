#include "block.h"

using namespace block_h;
using namespace System;
using namespace System::Windows::Forms;


void block1::create_block(int index) {
	//indexを基準点として、ブロックを生成する
	//ランダムでパターンを作り、ブロックを生成する
	Random^ rdm = gcnew Random();
	//0以上、3未満の整数を生成
	bl_pattern = rdm->Next(0, 3);
	//indexは位置、bl_patternはブロックの種類、さらにブロックの状態を引数に追加すること
	block_pattern(index, bl_pattern);

	create_boxes(c_1, c_2, c_3,c_4);
	
}

void block::create_boxes(int c1, int c2, int c3,int c4) {
	create_box(c1);
	create_box(c2);
	create_box(c3);
	create_box(c4);
}
void block::set_flgs(int c1, int c2, int c3,int c4) {
	f_list[c1]->set_flg(false);
	f_list[c2]->set_flg(false);
	f_list[c3]->set_flg(false);
	f_list[c4]->set_flg(false);
}
void block::rotate() {
	//フラグのリセット
	set_flgs(c_1, c_2, c_3, c_4);
	//ローテーションを回して、パターンセットの準備
	if (rotation == 3) {
		rotation = 0;
	}
	else {
		rotation += 1;
	}
	//現在のブロックパターンに応じて、処理を呼び出す
	bl_pattern = 0;
	switch (bl_pattern) {
	case 0:
		zero_rotate(c_1, rotation);
	}

	//パターンセット
	create_boxes(c_1, c_2, c_3, c_4);
}
void block::zero_rotate(int index,int num) {
	//ランダムに生成された0から3の数字のどれかを記憶しておく。回転ボタンのタイミングで使う
	rotation = num;

	set_flgs(c_1, c_2, c_3, c_4);

	List<int>^ t_list = gcnew List<int>;
	int t_1;
	int t_2;
	int t_3;
	int t_4;

	//0ブロックの回転パターンの定義
	switch (num) {
	case 0:
		//一時変数に移動先を定義
		t_1 = index;
		t_2 = index + w_space;
		t_3 = index + w_space + 1;
		t_4 = index + w_space + 2;
		t_list->Add(t_1);
		t_list->Add(t_2);
		t_list->Add(t_3);
		t_list->Add(t_4);
		for (int i = 0; i < t_list->Count; i++) {
			if (get_flg_list()->Contains(t_list[i])) {
				//移動先にtrueボックスが含まれていた場合、ずらす処理が必要だが、実装は後
				return;
			}
		}
		//もし、trueボックスが含まれなかった場合
		//下端と右端に掛かっているか、左端に掛かっている場合
		/*if ((contains_check(f_right)&&contains_check(f_under))||contains_check(f_right)) {
			c_1 = index-1;
			c_2 = index-1+w_space;
			c_3 = index+w_space;
			c_4 = index + 1+w_space;
		}
		else {
			c_1 = index;
			c_2 = index + w_space;
			c_3 = index + w_space + 1;
			c_4 = index + w_space + 2;
		}*/
		if ((contains_check(f_right) && contains_check(f_under)) || contains_check(f_right)) {
			index = index - 1;
		}
			c_1 = index;
			c_2 = index + w_space;
			c_3 = index + w_space + 1;
			c_4 = index + w_space + 2;
		break;
	case 1:
		t_1 = index +w_space*2;
		t_2 = index +w_space*2+ 1;
		t_3 = index + w_space + 1;
		t_4 = index +1;
		t_list->Add(t_1);
		t_list->Add(t_2);
		t_list->Add(t_3);
		t_list->Add(t_4);
		
		for (int i = 0; i < t_list->Count; i++) {
			if (get_flg_list()->Contains(t_list[i])) {
				return;
			}
		}
		//もし、下端ブロックに当たっていれば、
		/*if (contains_check(f_under)) {
			c_1 = index+w_space;
			c_2 = index +w_space+ 1;
			c_3 = index + 1;
			c_4 = index + 1 - w_space;
		}
		else {
			//もし、下端ブロックに当たっていなければ、
			c_1 = index + w_space * 2;
			c_2 = index + w_space * 2 + 1;
			c_3 = index + w_space+1;
			c_4 = index + +1;
		}*/
		if (contains_check(f_under)) {
			index = index - w_space;
		}
		
			//もし、下端ブロックに当たっていなければ、
			c_1 = index + w_space * 2;
			c_2 = index + w_space * 2 + 1;
			c_3 = index + w_space + 1;
			c_4 = index + +1;
		
		break;
	case 2:
		//一時変数に移動先を定義
		t_1 = index;
		t_2 = index + 1;
		t_3 = index + 2;
		t_4 = index + 2 + w_space;
		t_list->Add(t_1);
		t_list->Add(t_2);
		t_list->Add(t_3);
		t_list->Add(t_4);
		for (int i = 0; i < t_list->Count; i++) {
			if (get_flg_list()->Contains(t_list[i])) {
				//移動先にtrueボックスが含まれていた場合、ずらす処理が必要だが、実装は後
				return;
			}
		}
		/*if ((contains_check(f_right)&&contains_check(f_under))||contains_check(f_right)) {
			c_1 = index-1;
			c_2 = index;
			c_3 = index + 1;
			c_4 = index + 1 + w_space;
		}
		else if (contains_check(f_under)) {
			c_1 = index-w_space;
			c_2 = index -w_space+ 1;
			c_3 = index -w_space+ 2;
			c_4 = index+ 2;
		
		}else {
			c_1 = index ;
			c_2 = index + 1;
			c_3 = index + 2;
			c_4 = index + 2 + w_space;
		}*/
		if ((contains_check(f_right) && contains_check(f_under)) || contains_check(f_right)) {
			index = index - 1;
		}
		else if (contains_check(f_under)) {
			index = index - w_space;

		}
		
			c_1 = index;
			c_2 = index + 1;
			c_3 = index + 2;
			c_4 = index + 2 + w_space;
		
		break;
	case 3:
		//一時変数に移動先を定義
		t_1 = index;
		t_2 = index + 1;
		t_3 = index + w_space;
		t_4 = index + w_space * 2;
		t_list->Add(t_1);
		t_list->Add(t_2);
		t_list->Add(t_3);
		t_list->Add(t_4);
		for (int i = 0; i < t_list->Count; i++) {
			if (get_flg_list()->Contains(t_list[i])) {
				//移動先にtrueボックスが含まれていた場合、ずらす処理が必要だが、実装は後
				return;
			}
		}
		/*if (contains_check(f_under)) {
			/*c_1 = index-w_space+1;
			c_2 = index -w_space;
			c_3 = index ;
			c_4 = index + w_space;*/
			/*c_1 = index - w_space;
			c_2 = index - w_space+1;
			c_3 = index;
			c_4 = index+w_space;
		}
		else {
			c_1 = index;
			c_2 = index+1;
			c_3 = index + w_space;
			c_4 = index + w_space * 2;
		}*/
		if (contains_check(f_under)) {
			index = index - w_space;
		}
		
			c_1 = index;
			c_2 = index+1;
			c_3 = index + w_space;
			c_4 = index + w_space * 2;
		
		break;
	default:
		break;
	}
}

void block::block_pattern(int index,int num) {
	//0から3までの乱数を生成し、それぞれのrotateメソッドに渡す
	Random^ rnd = gcnew Random();
	int r = rnd->Next(0, 4);
	//indexはcreate_blockの引数を渡す
	//numの範囲は0から2まで。順次追加していく
	switch (num) {
	case 0:
		//zero_rotateでは、ランダムで生成されたパターンにc_1からc_4を設定し、現在の状態を専用変数に設定する
		c_1 = index;
		c_2 = index + w_space;
		c_3 = index + w_space + 1;
		c_4=index+w_space+2;
		//zero_rotate(index, r);
		break;
	case 1:
		c_1 = index;
		c_2 = index + 1;
		c_3 = index + w_space + 1;
		c_4=index+w_space*2+1;
		break;
	case 2:
		c_1 = index;
		c_2 = index + w_space;
		c_3 = index + w_space*2;
		c_4=index+w_space*3;
		break;
	default:
		break;
	}
}

void block::down_bl() {
	//現在座標より一段下の座標(c_1+=w_space)がc_2かc_3ではなく、trueであれば、同じ処理をする
	//現在座標が端ブロックリストに含まれていれば、初期位置にブロックを生成して、処理を終了
	if(contains_check(f_under)||down_isChecked()){
		//もし、列数すべてがtrueであれば、一斉フラグ反転処理
		delete_check(c_1);
		delete_check(c_2);
		delete_check(c_3);
		delete_check(c_4);

		create_block(3);
		return;
	}
	else {
		set_flgs(c_1, c_2, c_3,c_4);

		c_1 += w_space;
		c_2 += w_space;
		c_3 += w_space;
		c_4 += w_space;

		create_boxes(c_1, c_2, c_3,c_4);
	}
}
void block::left_bl() {
	if (contains_check(f_left)||left_isChecked()) {
		return;
	}
	else {
		set_flgs(c_1, c_2, c_3,c_4);

		c_1 -=1;
		c_2 -=1;
		c_3 -=1;
		c_4 -= 1;

		create_boxes(c_1, c_2, c_3,c_4);
	}	
}
void block::right_bl() {
	//if (f_right->Contains(c_1) || f_right->Contains(c_2) || f_right->Contains(c_3)||right_isChecked()) {
	if (contains_check(f_right) || right_isChecked()) {
		return;
	}
	else {
		set_flgs(c_1, c_2, c_3,c_4);

		c_1 += 1;
		c_2 += 1;
		c_3 += 1;
		c_4 += 1;

		create_boxes(c_1, c_2, c_3,c_4);
	}
}

bool block::down_isChecked() {
	//各ボックスの移動先マスを定義
	int c_f = c_1 + w_space;
	int c_s = c_2 + w_space;
	int c_t = c_3 + w_space;
	int c_f2 = c_4 + w_space;
	List<int>^ list = gcnew List<int>;
	list->Add(c_f);
	list->Add(c_s);
	list->Add(c_t);
	list->Add(c_f2);
	for (int n = 0; n < get_flg_list()->Count; n++) {
		//if (list->Contains(get_flg_list()[n]) && (get_flg_list()[n] != c_1 && get_flg_list()[n] != c_2 && get_flg_list()[n] != c_3)) {
		if (list->Contains(get_flg_list()[n]) && dupli_check(get_flg_list()[n])) {
		return true;
		}
	}
	/*for (int i = 0; i < list->Count; i++) {
		for (int n = 0; n < get_flg_list()->Count; n++) {
			if (list[i] == get_flg_list()[n]&& (get_flg_list()[n] != c_1 && get_flg_list()[n] != c_2 && get_flg_list()[n] != c_3)) {
					return true;
			}
		}
	}*/
	return false;
}

bool block::left_isChecked() {
	int c_f = c_1-1;
	int c_s = c_2-1;
	int c_t = c_3-1;
	int c_f2 = c_4 - 1;
	List<int>^ list = gcnew List<int>;
	list->Add(c_f);
	list->Add(c_s);
	list->Add(c_t);
	list->Add(c_f2);
	for (int n = 0; n < get_flg_list()->Count; n++) {
		if (list->Contains(get_flg_list()[n]) && dupli_check(get_flg_list()[n])) {
			return true;
		}
	}
	return false;
}
bool block::right_isChecked() {
	int c_f = c_1 + 1;
	int c_s = c_2 + 1;
	int c_t = c_3 + 1;
	int c_f2 = c_4 + 1;
	List<int>^ list = gcnew List<int>;
	list->Add(c_f);
	list->Add(c_s);
	list->Add(c_t);
	list->Add(c_f2);
	for (int n = 0; n < get_flg_list()->Count; n++) {
		if (list->Contains(get_flg_list()[n]) && dupli_check(get_flg_list()[n])) {
			return true;
		}
	}
	return false;
}

//引数はc_1,c_2..などのフィールド番号
void block::delete_check(int c) {
	//cの処理
	//開始のフィールド番号を定義
	int first = c / w_space * w_space;
	//最後のひとつ後のフィールド番号を定義
	int last = first + w_space;
	//真偽判定のための変数
	bool f = true;
	//該当列を先頭から処理
	for (int i = first; i < last; i++) {
		//もし、該当列のフラグにfalseが含まれていたら、fをfalseに変更し、ループを抜ける
		if (f_list[i]->get_flg() == false) {
			f = false;
			break;
		}
	}
	if (f == true) {
		//すべてがtrueだったときの処理
		for (int i = first; i < last; i++) {
			f_list[i]->set_flg(false);

			//上にtrueボックスがある場合は位置がずれる
			//iの変数を一時変数へ代入。iをいじると、ループがおかしくなる
			int c_temp = i;
			//回数判定用の変数で、初期値は0
			int count=0;
			//先頭ボックスを見つけて、フラグがtrueになるまで繰り返し処理を続ける
			while(1){
				//次の一時変数がゼロ以下になれば、その時点で先頭ボックスを認定
				if (c_temp-w_space < 0) {
					//先頭ボックスをfalseにする
					f_list[c_temp]->set_flg(false);
					//最下層ボックスをtrueにする
					f_list[i]->set_flg(true);
					break;
				}
				else {
					//判定対象のボックスを一段上に進める
					c_temp -= w_space;
					//もし、最初のループで一段上のボックスのフラグがfalseなら、ループを抜ける
					if (count == 0 && f_list[c_temp]->get_flg() == false) {
						//ループを抜ける処理
						break;
					}
					//最初以降のループでfalseのボックスがあれば、その下のボックスを先頭ボックス処理
					else if (f_list[c_temp]->get_flg() == false) {
						f_list[c_temp + w_space]->set_flg(false);
						f_list[i]->set_flg(true);
						break;
					}
				}
				count++;
			}
		}
	}
}
bool block::dupli_check(int check) {
	if (check != c_1 && check != c_2 && check != c_3&& check != c_4) {
		return true;
	}
	else {
		return false;
	}
}

bool block::contains_check(List<int>^ list) {
	if (list->Contains(c_1) || list->Contains(c_2) || list->Contains(c_3)||list->Contains(c_4)) {
		return true;
	}
	else {
		return false;
	}
}