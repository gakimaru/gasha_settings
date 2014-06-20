#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_FIRST_H_
#define __PROJECT_BUILD_SETTINGS_FIRST_H_

//--------------------------------------------------------------------------------
// project_build_settings_first.h
// プロジェクト固有のコンパイル設定（先行設定）
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//ネームスペース定義
//※プロジェクトの都合により、ライブラリのネームスペースを変更もしくは削除したい場合は、
//　このマクロを書き換えて使用する

#if 1//ネームスペースを使用する場合は 1 を、無効化する場合は 0 を指定する

#define NAMESPACE_NAME_GASHA gasha//ネームスペース名　※ネームスペースを変更したい場合、このマクロを書き換える

#define NAMESPACE_GASHA_BEGIN namespace NAMESPACE_NAME_GASHA {
#define NAMESPACE_GASHA_END }
#define USING_NAMESPACE_GASHA using namespace NAMESPACE_NAME_GASHA;
#define GASHA_ NAMESPACE_NAME_GASHA::

#else//以下、ネームスペースを使用しない場合の設定

#define NAMESPACE_NAME_GASHA

#define NAMESPACE_GASHA_BEGIN
#define NAMESPACE_GASHA_END
#define USING_NAMESPACE_GASHA
#define GASHA_

#endif

#endif//__PROJECT_BUILD_SETTINGS_FIRST_H_

// End of file
