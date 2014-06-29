#pragma once
#ifndef __PROJECT_BUILD_SETTINGS_LAST_H_
#define __PROJECT_BUILD_SETTINGS_LAST_H_

//--------------------------------------------------------------------------------
// last_settings.h
// プロジェクト固有のコンパイル設定（最終設定）
//
// Gakimaru's researched and standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license.
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//※以下、プロジェクトの都合に合わせて設定を選択・変更して使用する。

//--------------------------------------------------------------------------------
//【全体設定：SSE命令設定】
//※ライブラリの再ビルド必要

#ifdef GASHA_IS_X86//x86,x64系CPUの場合のみ設定可

	//※基本的に、使用するバージョン以前のマクロは全て有効にする
	
	#define GASHA_USE_SSE//SSE命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_SSE2//SSE2命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_SSE3//SSE3命令を使用する場合、このマクロを有効にする
	//#define GASHA_USE_SSE4A//SSE4a命令(AMD)を使用する場合、このマクロを有効にする
	#define GASHA_USE_SSE4_1//SSE4.1命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_SSE4_2//SSE4.2命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_POPCNT//POPCNT命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_AES//AES命令を使用する場合、このマクロを有効にする
	#define GASHA_USE_AVX//AVX命令を使用する場合、このマクロを有効にする
	//#define GASHA_USE_AVX2//AVX2命令を使用する場合、このマクロを有効にする

#endif//GASHA_IS_X86

//--------------------------------------------------------------------------------
//【CRC32設定】
//※ライブラリの再ビルド必要

#define GASHA_CRC32_IS_CRC32C//CRC32計算（多項式）を、CRC-32C(Castagnoli)にする場合、このマクロを有効にする
                             //※無効化時は、標準的なIEEE802.3のCRC-32を使用する。
                             //※CRC-32Cの方が衝突の機会が少なく優れている。
                             //※CRC-32C有効化＋SSE4.2使用で計算が高速化される。

#define GASHA_CRC32_USE_STATIC_TABLE//CRC32計算に、事前計算済みの多項式テーブルを用いる場合、このマクロを有効にする
                                    //※4×256=1024バイトのメモリを要するが、高速に処理できる。
                                    //※CRC-32C有効化＋SSE4.2使用時は、このマクロの指定に関係なく、
                                    //　ランタイム時にはSSE命令を使用する（その方が高速）

//--------------------------------------------------------------------------------
//【汎用ユーティリティ設定】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_SWAP_VALUES_USE_MEMCPY//swapValues/rotateValues関数でmemcpyを使用する場合、このマクロを有効化する（通常はムーブコンストラクタ／ムーブオペレータ使用）

//--------------------------------------------------------------------------------
//【アルゴリズム設定：ソート】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_QUICK_SORT_USE_RECURSIVE_CALL//クイックソートの再帰処理版を使用にする場合は、このマクロを有効にする

//#define GASHA_RADIX_SORT_USE_RECURSIVE_CALL//基数ソートの再帰処理版を使用にする場合は、このマクロを有効にする

#ifdef _OPENMP//OpenMP有効時

	#define GASHA_ODD_EVEN_SORT_USE_OPENMP//奇遇転置ソート：OpenMPを使用する場合は、このマクロを有効にする

	#define GASHA_SHEAR_SORT_USE_OPENMP//シェアソート：OpenMPを使用する場合は、このマクロを有効にする
	//#define GASHA_SHEAR_SORT_USE_OPENMP_NEST//シェアソート：OpenMPのparallelの入れ子処理を使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる、もしくは、正常に動作しない

	//#define GASHA_INPLACE_MERGE_SORT_USE_OPENMP//インプレースマージソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にすると遅くなることがある

	//#define GASHA_QUICK_SORT_USE_OPENMP//クイックソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる

#endif//_OPENMP

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：共有プールアロケータ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_SHARED_POOL_ALLOCATOR_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_SHARED_POOL_ALLOCATOR_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：共有スタック】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_SHARED_STACK_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_SHARED_STACK_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：共有キュー】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_SHARED_QUEUE_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_SHARED_QUEUE_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：ロックフリープールアロケータ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_LF_POOL_ALLOCATOR_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_LF_POOL_ALLOCATOR_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：ロックフリースタック】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_LF_STACK_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_LF_STACK_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【マルチスレッド共有データ設定：ロックフリーキュー】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_LF_QUEUE_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_LF_QUEUE_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：動的配列コンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_DYNAMIC_ARRAY_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_DYNAMIC_ARRAY_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：リングバッファコンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_RING_BUFFER_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_RING_BUFFER_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：双方向連結リストコンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_LINKED_LIST_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_LINKED_LIST_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#define GASHA_LINKED_LIST_ENABLE_RANDOM_ACCESS_INTERFACE//コンテナのランダムアクセスインターフェースを有効にする場合は、このマクロを有効化する
#define GASHA_LINKED_LIST_ENABLE_BINARY_SEARCH//コンテナの二分探索メソッドを有効にする場合は、このマクロを有効にする
#define GASHA_LINKED_LIST_ENABLE_STABLE_SORT//安定ソートメソッドを有効にする場合は、このマクロを有効にする
#define GASHA_LINKED_LIST_USE_SHELL_SORT//通常ソートにシェルソートを使用する場合は、このマクロを有効にする（無効化時は挿入ソートを使用）

//--------------------------------------------------------------------------------
//【コンテナ設定：片方向連結リストコンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_SINGLY_LINKED_LIST_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_SINGLY_LINKED_LIST_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#define GASHA_SINGLY_LINKED_LIST_ENABLE_RANDOM_ACCESS_INTERFACE//コンテナのランダムアクセスインターフェースを有効にする場合は、このマクロを有効化する
#define GASHA_SINGLY_LINKED_LIST_ENABLE_REVERSE_ITERATOR//リバースイテレータを有効にする場合は、このマクロを有効にする【注意】かなりの低速処理
#define GASHA_SINGLY_LINKED_LIST_ENABLE_BINARY_SEARCH//コンテナの二分探索メソッドを有効にする場合は、このマクロを有効にする ※リバースイテレータ無効化時は無効
#define GASHA_SINGLY_LINKED_LIST_ENABLE_STABLE_SORT//安定ソートメソッドを有効にする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：赤黒木コンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_RB_TREE_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_RB_TREE_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#define GASHA_RB_TREE_ENABLE_RANDOM_ACCESS_INTERFACE//コンテナのランダムアクセスインターフェースを有効にする場合は、このマクロを有効化する
#define GASHA_RB_TREE_DISABLE_COLOR_FOR_ADD//ノード追加時の色操作と回転処理を無効にする場合は、このマクロを有効にする
#define GASHA_RB_TREE_DISABLE_COLOR_FOR_REMOVE//ノード削除時の色操作と回転処理を無効にする場合は、このマクロを有効にする
#define GASHA_RB_TREE_USE_DEBUG_PRINT_FOR_ADD//ノード追加時のデバッグ情報表示を使用する場合は、このマクロを有効にする
#define GASHA_RB_TREE_USE_DEBUG_PRINT_FOR_REMOVE//ノード削除時のデバッグ情報表示を使用する場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：開番地法ハッシュテーブルコンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_HASH_TABLE_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_HASH_TABLE_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#define GASHA_HASH_TABLE_ENABLE_RANDOM_ACCESS_INTERFACE//コンテナのランダムアクセスインターフェースを有効にする場合は、このマクロを有効化する
#define GASHA_HASH_TABLE_ENABLE_REVERSE_ITERATOR//リバースイテレータを有効にする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：二分ヒープコンテナ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_BINARY_HEAP_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_BINARY_HEAP_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#define GASHA_BINARY_HEAP_ENABLE_RANDOM_ACCESS_INTERFACE//コンテナのランダムアクセスインターフェースを有効にする場合は、このマクロを有効化する
#define GASHA_BINARY_HEAP_ENABLE_REVERSE_ITERATOR//リバースイテレータを有効にする場合は、このマクロを有効にする

//--------------------------------------------------------------------------------
//【コンテナ設定：優先度付きキューコンテナアダプタ】
//※ライブラリの再ビルド不要（ただし、ライブラリ内で使用している可能性があるため、できるだけ再ビルドした方が良い）

//#define GASHA_PRIORITY_QUEUE_ALLWAYS_TOGETHER_INL//.hファイルのインクルードに伴い、常に.inlファイルを自動インクルードする場合は、このマクロを有効にする
//#define GASHA_PRIORITY_QUEUE_ALLWAYS_TOGETHER_CPP_H//.hファイルのインクルードに伴い、常に.cp.hファイル（および.inlファイル）を自動インクルードする場合は、このマクロを有効にする

#endif//__PROJECT_BUILD_SETTINGS_LAST_H_

// End of file
