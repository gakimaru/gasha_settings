#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_LAST_H_
#define __PROJECT_BUILD_SETTINGS_LAST_H_

//--------------------------------------------------------------------------------
// project_build_settings.h
// プロジェクト固有のコンパイル設定
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license.
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//※以下、プロジェクトの都合に合わせて設定を選択・変更して使用する。

//--------------------------------------------------------------------------------
//SSE命令設定
#ifdef GASHA_IS_X86//x86,x64系CPUの場合のみ設定可
//※使用するバージョン以前のマクロは全て有効化すること
#define GASHA_USE_SSE//SSE命令を使用
#define GASHA_USE_SSE2//SSE2命令を使用
#define GASHA_USE_SSE3//SSE3命令を使用
//#define GASHA_USE_SSE4A//SSE4a命令(AMD)を使用
#define GASHA_USE_SSE4_1//SSE4.1命令を使用
#define GASHA_USE_SSE4_2//SSE4.2命令を使用
#define GASHA_USE_POPCNT//POPCNT命令を使用
#define GASHA_USE_AES//AES命令を使用
#define GASHA_USE_AVX//AVX命令を使用
//#define GASHA_USE_AVX2//AVX2命令を使用
#endif//GASHA_IS_X86

//--------------------------------------------------------------------------------
//CRC32設定
#define GASHA_CRC32_IS_CRC32C//CRC32計算（多項式）を、CRC-32C(Castagnoli)にする場合、このマクロを有効化する
                             //※無効化時は、標準的なIEEE802.3のCRC-32を使用する。
                             //※CRC-32Cの方が衝突の機会が少なく優れている。
                             //※CRC-32C有効化＋SSE4.2使用で計算が高速化される。

#define GASHA_CRC32_USE_STATIC_TABLE//CRC32計算に、事前計算済みの多項式テーブルを用いる場合、このマクロを有効化する
                                    //※4×256=1024バイトのメモリを要するが、高速に処理できる。
                                    //※CRC-32C有効化＋SSE4.2使用時は、このマクロの指定に関係なく、
                                    //　ランタイム時にはSSE命令を使用する（その方が高速）

//--------------------------------------------------------------------------------
//値交換設定
//#define GASHA_SWAP_VALUES_USE_MEMCPY//swapValues/rotateValues関数でmemcpyを使用する場合、このマクロを有効化する（通常はムーブコンストラクタ／ムーブオペレータ使用）

//--------------------------------------------------------------------------------
//ソート設定

#define GASHA_QUICK_SORT_NO_USE_RECURSIVE_CALL//クイックソートの再帰処理版を無効にする場合は、このマクロを有効にする

#ifdef _OPENMP//OpenMP有効時

	#define GASHA_ODD_EVEN_SORT_USE_OPENMP//奇遇転置ソート：OpenMPを使用する場合は、このマクロを有効にする

	#define GASHA_SHEAR_SORT_USE_OPENMP//シェアソート：OpenMPを使用する場合は、このマクロを有効にする
	//#define GASHA_SHEAR_SORT_USE_OPENMP_NEST//シェアソート：OpenMPのparallelの入れ子処理を使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる、もしくは、正常に動作しない

	//#define GASHA_INPLACE_MERGE_SORT_USE_OPENMP//インプレースマージソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にすると遅くなることがある

	//#define GASHA_QUICK_SORT_USE_OPENMP//クイックソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる

#endif//_OPENMP

#endif//__PROJECT_BUILD_SETTINGS_LAST_H_

// End of file
