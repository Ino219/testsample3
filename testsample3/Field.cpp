#include "Field.h"

using namespace testsample3;
using namespace System::Windows::Forms;

void f_number::f_set(int x, int y) {
	f_x = x;
	f_y = y;
}
void f_number::set_flg(bool flg) {
	flag = flg;
}
int f_number::get_fx() {
	return f_x;
}
int f_number::get_fy() {
	return f_y;
}
bool f_number::get_flg() {
	return flag;
}

//�R���X�g���N�^
Field::Field() {
	//���X�g�̃C���X�^���X����
	f_list = gcnew List<f_number^>;
	//�t�B�[���h�ԍ����`
	for (int i = 0; i < w_space*h_space; i++) {
		f_number^ f = gcnew f_number();
		int temp_x = i % w_space*space;
		int temp_y = i / w_space*space;
		f->f_set(temp_x, temp_y);
		f->set_flg(false);
		f_list->Add(f);
	}
	//�[�u���b�N�̃t�B�[���h�ԍ����`
	f_left = gcnew List<int>;
	for (int i = 0; i < h_space; i++) {
		f_left->Add(i*w_space);
	}
	f_right = gcnew List<int>;
	for (int i = 0; i < h_space; i++) {
		f_right->Add(i*w_space + (w_space - 1));
		
	}
	f_under = gcnew List<int>;
	for (int i = 0; i < w_space; i++) {
		f_under->Add(w_space*(h_space - 1)+i);
		//MessageBox::Show("list�̑傫��:" + f_under.Count + "list�̃f�[�^:" + f_under[i]);
	}
}
List<int>^ Field::get_flg_list() {
	List<int>^ flag_list=gcnew List<int>;
	for (int i = 0; i < f_list->Count; i++) {
		//�t���O��true�̃��X�g�f�[�^�̃C���f�b�N�X���t���O���X�g�Ɋi�[
		if (f_list[i]->get_flg() == true) {
			flag_list->Add(i);
		}
	}
	return flag_list;
}
int Field::get_fld_x(int index) {
	return f_list[index]->get_fx();
}
int Field::get_fld_y(int index) {
	return f_list[index]->get_fy();
}
int Field::get_space() {
	return space;
}