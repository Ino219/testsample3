#include "box.h"
#include"Field.h"

using namespace box_h;
using namespace testsample3;
using namespace System::Windows::Forms;

box::box() {
}

//�t�B�[���h�ԍ��̊�_����{�b�N�X��`�悷��
void box:: create_box(int index) {
	//�Y������t�B�[���h�ԍ��̃t���O��true�ɃZ�b�g����
	if (index < w_space*h_space) {
		f_list[index]->set_flg(true);
	}
	else {
		return;
	}
}