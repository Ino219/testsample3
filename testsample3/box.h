#pragma once
#include"Field.h"

namespace box_h {

	using namespace testsample3;

	ref class box:Field
	{
	protected:
		//��_��x���W��y���W
		int bx_x;
		int bx_y;
	public:
		//�R���X�g���N�^
		box();
		//�{�b�N�X�̐���
		void create_box(int index);
	};

}