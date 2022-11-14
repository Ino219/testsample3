#pragma once
#include"Field.h"

namespace box_h {

	using namespace testsample3;

	ref class box:Field
	{
	protected:
		//基準点のx座標とy座標
		int bx_x;
		int bx_y;
	public:
		//コンストラクタ
		box();
		//ボックスの生成
		void create_box(int index);
	};

}