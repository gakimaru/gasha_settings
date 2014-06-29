#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_FIRST_H_
#define __PROJECT_BUILD_SETTINGS_FIRST_H_

//--------------------------------------------------------------------------------
// first_settings.h
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

#define GASHA_USE_NAME_SPACE//GASHA用のネームスペースを使用する場合、このマクロを有効化する

#ifdef GASHA_USE_NAME_SPACE//以下、ネームスペースを使用する場合

	#define GASHA_NAMESPACE_NAME gasha//ネームスペース名　※ネームスペースを変更したい場合、このマクロを書き換える

	#define GASHA_NAMESPACE_BEGIN namespace GASHA_NAMESPACE_NAME {//ネームスペース開始宣言
	#define GASHA_NAMESPACE_END }//ネームスペース終了宣言

	#define GASHA_USING_NAMESPACE using namespace GASHA_NAMESPACE_NAME//ネームスペース使用宣言
	
	#define GASHA_ GASHA_NAMESPACE_NAME:://ネームスペース指定

#else//GASHA_USE_NAME_SPACE//以下、ネームスペースを使用しない場合の設定

	#define GASHA_NAMESPACE_NAME//ネームスペース名

	#define GASHA_NAMESPACE_BEGIN//ネームスペース開始宣言
	#define GASHA_NAMESPACE_END//ネームスペース終了宣言

	#define GASHA_USING_NAMESPACE;//ネームスペース使用宣言

	#define GASHA_//ネームスペース指定

#endif//GASHA_USE_NAME_SPACE

#endif//__PROJECT_BUILD_SETTINGS_FIRST_H_

// End of file
