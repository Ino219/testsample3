#pragma once
#include"box.h"


namespace block_h {

	using namespace box_h;

	ref class block abstract :box
	{
	protected:
		//ブロックの各ボックスの格納位置を取得
		//c_1は基準点
		int c_1;
		int c_2;
		int c_3;
		int c_4;
		//ブロックのパターンを記憶しておく
		int bl_pattern;
		//回転状態を記憶しておく
		int rotation;
	public:
		virtual void create_block(int index) abstract = 0;
		//ブロック落下
		void down_bl();
		//ブロック左進行
		void left_bl();
		//ブロック右進行
		void right_bl();
		//落下チェック
		bool down_isChecked();
		//左進行チェック
		bool left_isChecked();
		//右進行チェック
		bool right_isChecked();
		//ブロック消去チェック
		void delete_check(int c);
		//ブロックの種類を定義
		void block_pattern(int index,int num);
		//ブロック移動判定のボックス重複チェック
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