#include "block.h"

using namespace block_h;
using namespace System;
using namespace System::Windows::Forms;


void block1::create_block(int index) {
	//index����_�Ƃ��āA�u���b�N�𐶐�����
	//�����_���Ńp�^�[�������A�u���b�N�𐶐�����
	Random^ rdm = gcnew Random();
	//0�ȏ�A3�����̐����𐶐�
	bl_pattern = rdm->Next(0, 3);
	//index�͈ʒu�Abl_pattern�̓u���b�N�̎�ށA����Ƀu���b�N�̏�Ԃ������ɒǉ����邱��
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
	//�t���O�̃��Z�b�g
	set_flgs(c_1, c_2, c_3, c_4);
	//���[�e�[�V�������񂵂āA�p�^�[���Z�b�g�̏���
	if (rotation == 3) {
		rotation = 0;
	}
	else {
		rotation += 1;
	}
	//���݂̃u���b�N�p�^�[���ɉ����āA�������Ăяo��
	bl_pattern = 0;
	switch (bl_pattern) {
	case 0:
		zero_rotate(c_1, rotation);
	}

	//�p�^�[���Z�b�g
	create_boxes(c_1, c_2, c_3, c_4);
}
void block::zero_rotate(int index,int num) {
	//�����_���ɐ������ꂽ0����3�̐����̂ǂꂩ���L�����Ă����B��]�{�^���̃^�C�~���O�Ŏg��
	rotation = num;

	set_flgs(c_1, c_2, c_3, c_4);

	List<int>^ t_list = gcnew List<int>;
	int t_1;
	int t_2;
	int t_3;
	int t_4;

	//0�u���b�N�̉�]�p�^�[���̒�`
	switch (num) {
	case 0:
		//�ꎞ�ϐ��Ɉړ�����`
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
				//�ړ����true�{�b�N�X���܂܂�Ă����ꍇ�A���炷�������K�v�����A�����͌�
				return;
			}
		}
		//�����Atrue�{�b�N�X���܂܂�Ȃ������ꍇ
		//���[�ƉE�[�Ɋ|�����Ă��邩�A���[�Ɋ|�����Ă���ꍇ
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
		//�����A���[�u���b�N�ɓ������Ă���΁A
		/*if (contains_check(f_under)) {
			c_1 = index+w_space;
			c_2 = index +w_space+ 1;
			c_3 = index + 1;
			c_4 = index + 1 - w_space;
		}
		else {
			//�����A���[�u���b�N�ɓ������Ă��Ȃ���΁A
			c_1 = index + w_space * 2;
			c_2 = index + w_space * 2 + 1;
			c_3 = index + w_space+1;
			c_4 = index + +1;
		}*/
		if (contains_check(f_under)) {
			index = index - w_space;
		}
		
			//�����A���[�u���b�N�ɓ������Ă��Ȃ���΁A
			c_1 = index + w_space * 2;
			c_2 = index + w_space * 2 + 1;
			c_3 = index + w_space + 1;
			c_4 = index + +1;
		
		break;
	case 2:
		//�ꎞ�ϐ��Ɉړ�����`
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
				//�ړ����true�{�b�N�X���܂܂�Ă����ꍇ�A���炷�������K�v�����A�����͌�
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
		//�ꎞ�ϐ��Ɉړ�����`
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
				//�ړ����true�{�b�N�X���܂܂�Ă����ꍇ�A���炷�������K�v�����A�����͌�
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
	//0����3�܂ł̗����𐶐����A���ꂼ���rotate���\�b�h�ɓn��
	Random^ rnd = gcnew Random();
	int r = rnd->Next(0, 4);
	//index��create_block�̈�����n��
	//num�͈̔͂�0����2�܂ŁB�����ǉ����Ă���
	switch (num) {
	case 0:
		//zero_rotate�ł́A�����_���Ő������ꂽ�p�^�[����c_1����c_4��ݒ肵�A���݂̏�Ԃ��p�ϐ��ɐݒ肷��
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
	//���ݍ��W����i���̍��W(c_1+=w_space)��c_2��c_3�ł͂Ȃ��Atrue�ł���΁A��������������
	//���ݍ��W���[�u���b�N���X�g�Ɋ܂܂�Ă���΁A�����ʒu�Ƀu���b�N�𐶐����āA�������I��
	if(contains_check(f_under)||down_isChecked()){
		//�����A�񐔂��ׂĂ�true�ł���΁A��ăt���O���]����
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
	//�e�{�b�N�X�̈ړ���}�X���`
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

//������c_1,c_2..�Ȃǂ̃t�B�[���h�ԍ�
void block::delete_check(int c) {
	//c�̏���
	//�J�n�̃t�B�[���h�ԍ����`
	int first = c / w_space * w_space;
	//�Ō�̂ЂƂ�̃t�B�[���h�ԍ����`
	int last = first + w_space;
	//�^�U����̂��߂̕ϐ�
	bool f = true;
	//�Y�����擪���珈��
	for (int i = first; i < last; i++) {
		//�����A�Y����̃t���O��false���܂܂�Ă�����Af��false�ɕύX���A���[�v�𔲂���
		if (f_list[i]->get_flg() == false) {
			f = false;
			break;
		}
	}
	if (f == true) {
		//���ׂĂ�true�������Ƃ��̏���
		for (int i = first; i < last; i++) {
			f_list[i]->set_flg(false);

			//���true�{�b�N�X������ꍇ�͈ʒu�������
			//i�̕ϐ����ꎞ�ϐ��֑���Bi��������ƁA���[�v�����������Ȃ�
			int c_temp = i;
			//�񐔔���p�̕ϐ��ŁA�����l��0
			int count=0;
			//�擪�{�b�N�X�������āA�t���O��true�ɂȂ�܂ŌJ��Ԃ������𑱂���
			while(1){
				//���̈ꎞ�ϐ����[���ȉ��ɂȂ�΁A���̎��_�Ő擪�{�b�N�X��F��
				if (c_temp-w_space < 0) {
					//�擪�{�b�N�X��false�ɂ���
					f_list[c_temp]->set_flg(false);
					//�ŉ��w�{�b�N�X��true�ɂ���
					f_list[i]->set_flg(true);
					break;
				}
				else {
					//����Ώۂ̃{�b�N�X����i��ɐi�߂�
					c_temp -= w_space;
					//�����A�ŏ��̃��[�v�ň�i��̃{�b�N�X�̃t���O��false�Ȃ�A���[�v�𔲂���
					if (count == 0 && f_list[c_temp]->get_flg() == false) {
						//���[�v�𔲂��鏈��
						break;
					}
					//�ŏ��ȍ~�̃��[�v��false�̃{�b�N�X������΁A���̉��̃{�b�N�X��擪�{�b�N�X����
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