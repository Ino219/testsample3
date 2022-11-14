#pragma once

namespace testsample3 {

	//List���g�p���邽�߂̐錾
	using namespace System::Collections::Generic;

	//�t�B�[���h�ԍ��̏��������f�[�^�N���X
	ref class f_number {
	private:
		//x���W��y���W�ƃt���O
		int f_x;
		int f_y;
		bool flag;
	public:
		void f_set(int fx, int fy);
		void set_flg(bool flg);
		int get_fx();
		int get_fy();
		bool get_flg();
	};

	ref class Field
	{
	protected:
		//�����`�}�X�̈�ӂ̒���
		const int space = 10;
		//�t�B�[���h�̉���
		const int width=150;
		//�t�B�[���h�̏c��
		const int height=200;
		//�t�B�[���h�̉����̃}�X��
		int w_space=width / space;
		//�t�B�[���h�̏c���̃}�X��
		int h_space = height / space;
		//�t�B�[���h�ԍ��̃f�[�^���X�g
		List<f_number^>^ f_list;
		//�t�B�[���h�̉��[
		List<int>^ f_under;
		//�t�B�[���h�̍��[
		List<int>^ f_left;
		//�t�B�[���h�̉E�[
		List<int>^ f_right;
	public:
		//�R���X�g���N�^
		Field();
		//�t�B�[���h�ԍ�����x���W��y���W���擾
		int get_fld_x(int index);
		int get_fld_y(int index);
		//�t���O��true�̃��X�g��Ԃ�
		List<int>^ get_flg_list();
		//�}�X�̑傫����Ԃ�
		int get_space();

	};
}
