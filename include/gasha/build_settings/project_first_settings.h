#pragma once
#ifndef GASHA_INCLUDED_PROJECT_FIRST_SETTINGS_H
#define GASHA_INCLUDED_PROJECT_FIRST_SETTINGS_H

//--------------------------------------------------------------------------------
// build_settings/project_first_settings.h
// プロジェクト固有のコンパイル設定（先行設定）
//
// 依存するヘッダー：（なし）
//                   ※build_settings.h により、依存関係順にインクルード
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license.
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//【ネームスペース定義】

//※開発プロジェクトの都合により、GASHA のネームスペースを変更もしくは削除したい場合は、
//　以下のマクロを書き換えて使用する

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

	#define GASHA_USING_NAMESPACE//ネームスペース使用宣言

	#define GASHA_ :://ネームスペース指定

#endif//GASHA_USE_NAME_SPACE

//--------------------------------------------------------------------------------
//【キーワード偽装】

//【解説】GASHA では、使用するコンパイラおよびそのバージョンに応じて、下記のC++11キーワードもしくは
//        コンパイラ固有仕様定数／関数を、#define マクロで偽装する。
//        ・nullptr              ... 偽装（0で偽装）
//        ・override             ... ダミー（空のマクロ）
//        ・final                ... ダミー（空のマクロ）
//        ・constexpr            ... ダミー（空のマクロ）
//        ・static_assert        ... 制限付きで偽装（複数定義できない）
//        ・thread_local         ... 偽装（コンパイラ固有仕様で偽装）
//        ・noexcept             ... 制限付きで偽装（nothrow() で偽装）
//        ・alignas()            ... 制限付きで偽装（コンパイラ固有仕様で偽装、alignas(alignof(T)) 不可などの制限あり）
//        ・alignof()            ... 制限付きで偽装（同上）
//        ・__PRETTY_FUNCTION__  ... 偽装（__FUNCSIG__ で偽装） ※GCC固有仕様
//        ・__func__             ... 偽装（__FUNCTION__ で偽装） ※C99仕様だがVC++は未対応
//        ・__FUNCSIG__          ... 偽装（__PRETTY_FUNCTION__ で偽装） ※VC++固有仕様
//        ・__FUNCDNAME__        ... ダミー（"" にする） ※VC++固有仕様
//        ・_aligned_malloc()    ... 偽装（posix_memalign() で偽装） ※VC++固有仕様
//        ・_aligned_free()      ... 偽装（free() で偽装） ※VC++固有仕様
//        ・__cpuid(), _xgetbv(), _XCR_XFEATURE_ENABLED_MASK
//                               ... 偽装（0で偽装）※VC++固有の関数（x86系のCPU命令を組み込み関数化したもの）

//【補足】GASHAが定義するマクロは、基本的に GASHA_ で始まるため、GASHA の導入によるマクロの競合は
//        基本的に起こらないが、上記のマクロは例外として競合の可能性がある。

//【対応】もし、GASHA に上記の偽装マクロを定義させたくない場合、下記のマクロを個別に有効化する。

//#define GASHA_NODEF_NULLPTR//nullptr の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_OVERRIDE//overrideの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_FINAL//finalの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_CONSTEXPR//constexprの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_STATIC_ASSERT//static_assertの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_THREAD_LOCAL//thread_localの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_NOEXCEPT//noexceptの偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_ALIGNAS//alignas()の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_ALIGNOF//alignof()の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_PRETTY_FUNCTION//__PRETTY_FUNCTION__の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_func//__func__の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_FUNCSIG//__FUNCSIG__の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_FUNCDNAME//__FUNCDNAME__の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_ALIGNED_MALLOC//_aligned_malloc()の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_ALIGNED_FREE//_aligned_free()の偽装を許可しない場合は、このマクロを有効化する
//#define GASHA_NODEF_CPUID//__cpuid(), _xgetbv(), _XCR_XFEATURE_ENABLED_MASK の偽装を許可しない場合は、このマクロを有効化する

//【注意】ライブラリファイルのビルド時（GASHA_BUILD_FOR_LIB マクロが定義されている時）は、
//        この設定を無視して、常にキーワードの偽装を行う。

#endif//GASHA_INCLUDED_PROJECT_FIRST_SETTINGS_H

// End of file
