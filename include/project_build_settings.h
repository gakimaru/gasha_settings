﻿#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_H_
#define __PROJECT_BUILD_SETTINGS_H_

//--------------------------------------------------------------------------------
// project_build_settings.h
// プロジェクト固有のコンパイル設定
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//※以下、プロジェクトの都合に合わせて設定を選択・変更して使用する。

//--------------------------------------------------------------------------------
//SSE命令設定
#ifdef IS_X86//x86,x64系CPUの場合のみ設定可
//※使用するバージョン以前のマクロは全て有効化すること
#define USE_SSE//SSE使用
#define USE_SSE2//SSE2使用
#define USE_SSE3//SSE3使用
#define USE_SSE4//SSE4使用
#define USE_SSE4_1//SSE4.1使用
#define USE_SSE4_2//SSE4.2使用
#define USE_AVX//AVX使用
//#define USE_AVX2//AVX2使用
#endif//IS_X86

//--------------------------------------------------------------------------------
//CRC32設定
#define CRC32_IS_CRC32C//CRC32計算（多項式）を、CRC-32C(Castagnoli)にする場合、このマクロを有効化する
                       //※無効化時は、標準的なIEEE802.3のCRC-32を使用する。
                       //※CRC-32Cの方が衝突の機会が少なく優れている。
                       //※CRC-32C有効化＋SSE4.2使用で計算が高速化される。

#define CRC32_USE_STATIC_TABLE//CRC32計算に、事前計算済みの多項式テーブルを用いる場合、このマクロを有効化する
                              //※4×256=1024バイトのメモリを要するが、高速に処理できる。
                              //※CRC-32C有効化＋SSE4.2使用時は、このマクロの指定に関係なく、
                              //　ランタイム時にはSSE命令を使用する（その方が高速）

#endif//__PROJECT_BUILD_SETTINGS_H_

// End of file
