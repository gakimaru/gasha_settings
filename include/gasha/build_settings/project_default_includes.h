﻿#pragma once
#ifndef GASHA_INCLUDED_PROJECT_DEFAULT_INCLUDES_H
#define GASHA_INCLUDED_PROJECT_DEFAULT_INCLUDES_H

//--------------------------------------------------------------------------------
// build_settings/project_default_includes.h
// プロジェクト固有のデフォルトインクルードファイル
//
// 依存するヘッダー：project_first_settings.h//プロジェクト固有のビルド設定（先行設定）
//                   compiler_auto_settings.h//コンパイラ自動判別・設定
//                   platform_auto_settings.h//プラットフォーム自動判別・設定
//                   language_auto_settings.h//言語機能自動判別・設定
//                   build_configuration.h//ビルド構成
//                   project_last_settings.h//プロジェクト固有のビルド設定（最終設定）
//                   adjust_build_settings.h//ビルド設定調整
//                   builtin_functions.h//組み込み関数・マクロ
//                   ※build_settings.h により、依存関係順にインクルード
//
// Gakimaru's standard library for C++ - GASHA
//   Copyright (c) 2014 Itagaki Mamoru
//   Released under the MIT license.
//     https://github.com/gakimaru/gasha_settings/blob/master/LICENSE
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//※以下、デフォルトのインクルードを設定する

//#include <gasha/type_traits.h>//型特性ユーティリティ：extentof(), rankof(), toStr()
//#include <gasha/limits.h>//限界値：numeric_limits<T>
//#include <gasha/chrono.h>//時間処理ユーティリティ：elapsedTime, nowElapsedTime()

//#include <gasha/new.h>//多態アロケータ対応標準new/delete

//#include <gasha/print.h>//ログ出力操作
//#include <gasha/assert.h>//アサーション／ブレークポイント／ウォッチポイント
//#include <gasha/simple_assert.h>//シンプルアサーション／ブレークポイント／ウォッチポイント

//#include <cstddef>//std::size_t, std::ptrdiff_t
//#include <cstdint>//std::intptr_t, std::uintptr_t, C++11 std::int*_t, std::uint*_t

#endif//GASHA_INCLUDED_PROJECT_DEFAULT_INCLUDES_H

// End of file
