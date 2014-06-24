#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_FIRST_H_
#define __PROJECT_BUILD_SETTINGS_FIRST_H_

//--------------------------------------------------------------------------------
// project_build_settings_first.h
// プロジェクト固有のコンパイル設定（先行設定）
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license.
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//ネームスペース定義
//※プロジェクトの都合により、ライブラリのネームスペースを変更もしくは削除したい場合は、
//　このマクロを書き換えて使用する

#define USE_NAME_SPACE_GASHA//GASHA用のネームスペースを使用する場合、このマクロを有効化する

#ifdef USE_NAME_SPACE_GASHA//以下、ネームスペースを使用する場合

	#define NAMESPACE_NAME_GASHA gasha//ネームスペース名　※ネームスペースを変更したい場合、このマクロを書き換える

	#define NAMESPACE_GASHA_BEGIN namespace NAMESPACE_NAME_GASHA {//ネームスペース開始宣言
	#define NAMESPACE_GASHA_END }//ネームスペース終了宣言

	#define USING_NAMESPACE_GASHA using namespace NAMESPACE_NAME_GASHA//ネームスペース使用宣言
	
	#define GASHA_ NAMESPACE_NAME_GASHA:://ネームスペース指定

#else//USE_NAME_SPACE_GASHA//以下、ネームスペースを使用しない場合の設定

	#define NAMESPACE_NAME_GASHA//ネームスペース名

	#define NAMESPACE_GASHA_BEGIN//ネームスペース開始宣言
	#define NAMESPACE_GASHA_END//ネームスペース終了宣言

	#define USING_NAMESPACE_GASHA;//ネームスペース使用宣言

	#define GASHA_//ネームスペース指定

#endif//USE_NAME_SPACE_GASHA

#define INCLUDE_GASHA(file) <gasha/file> //インクルード

#endif//__PROJECT_BUILD_SETTINGS_FIRST_H_

// End of file
