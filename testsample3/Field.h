#pragma once

namespace testsample3 {

	//Listを使用するための宣言
	using namespace System::Collections::Generic;

	//フィールド番号の情報を扱うデータクラス
	ref class f_number {
	private:
		//x座標とy座標とフラグ
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
		//正方形マスの一辺の長さ
		const int space = 10;
		//フィールドの横幅
		const int width=150;
		//フィールドの縦幅
		const int height=200;
		//フィールドの横幅のマス数
		int w_space=width / space;
		//フィールドの縦幅のマス数
		int h_space = height / space;
		//フィールド番号のデータリスト
		List<f_number^>^ f_list;
		//フィールドの下端
		List<int>^ f_under;
		//フィールドの左端
		List<int>^ f_left;
		//フィールドの右端
		List<int>^ f_right;
	public:
		//コンストラクタ
		Field();
		//フィールド番号からx座標とy座標を取得
		int get_fld_x(int index);
		int get_fld_y(int index);
		//フラグがtrueのリストを返す
		List<int>^ get_flg_list();
		//マスの大きさを返す
		int get_space();

	};
}
