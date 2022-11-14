#pragma once
#include"box.h"


namespace block_h {

	using namespace box_h;

	ref class block abstract :box
	{
	protected:
		//�u���b�N�̊e�{�b�N�X�̊i�[�ʒu���擾
		//c_1�͊�_
		int c_1;
		int c_2;
		int c_3;
		int c_4;
		//�u���b�N�̃p�^�[�����L�����Ă���
		int bl_pattern;
		//��]��Ԃ��L�����Ă���
		int rotation;
	public:
		virtual void create_block(int index) abstract = 0;
		//�u���b�N����
		void down_bl();
		//�u���b�N���i�s
		void left_bl();
		//�u���b�N�E�i�s
		void right_bl();
		//�����`�F�b�N
		bool down_isChecked();
		//���i�s�`�F�b�N
		bool left_isChecked();
		//�E�i�s�`�F�b�N
		bool right_isChecked();
		//�u���b�N�����`�F�b�N
		void delete_check(int c);
		//�u���b�N�̎�ނ��`
		void block_pattern(int index,int num);
		//�u���b�N�ړ�����̃{�b�N�X�d���`�F�b�N
		bool dupli_check(int c);
		bool contains_check(List<int>^ list);
		void create_boxes(int c1, int c2, int c3,int c4);
		void set_flgs(int c1, int c2, int c3,int c4);
		void rotate();
		void zero_rotate(int index,int num);
	};
	ref class block1 :block {
	public:
		void create_block(int index) override;
	};
}