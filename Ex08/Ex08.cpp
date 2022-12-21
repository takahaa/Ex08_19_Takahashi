﻿// Ex08.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :public Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return width;
    }
    double GetHeight() {
        return height;
    }
    double GetDepth() {
        return depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

/// <summary>
/// 円柱
/// </summary>
class Cylinder :public Solid {
private:
    double radius;
    double height;
public:
    Cylinder(
        double radius,   //半径
        double height) {  //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return radius;
    }
    double GetHeight() {
        return height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height;
    }
    double GetSurface() {
        return radius * radius * M_PI * 2 + radius * 2 * M_PI * height;
    }

};

/// <summary>
/// 円錐
/// </summary>
class Cone :public Solid {
private:
    double radius;
    double height;
public:
    Cone(
        double radius,   //半径
        double height) { //高さ
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return radius;
    }
    double GetHeight() {
        return height;
    }
    double GetVolume() {
        return radius * radius * M_PI * height / 3;
    }
    double GetSurface() {
        return radius * radius * M_PI + sqrt(radius * radius + height * height) * radius * M_PI;
    }
};

/// <summary>
/// 球
/// </summary>
class Sphere :public Solid {
private:
    double radius;
public:
    Sphere(double radius) { //半径
        this->radius = radius;
    }
    double GetRadius() {
        return radius;
    }
    double GetVolume() {
        return M_PI * radius * radius * radius * (4.0 / 3);
    }
    double GetSurface() {
        return radius * radius * M_PI * 4;
    }
};

void DisplayVolumeSurface(Solid* solid) {
    cout << "\n体積=" << solid->GetVolume() << endl;
    cout << "表面積=" << solid->GetSurface() << endl;
}


int main()
{
    Box box{ 30,50,2.5 };
    Cylinder cylinder{ 23,10.2 };
    Cone cone{ 3.1,20 };
    Sphere sphere{ 50 };
    int i;
    const int N_TABLE = 4;
    Solid* solid[N_TABLE] = { &box,&cylinder,&cone,&sphere };
    //体積＆表面積の表示
    for (i = 0; i < N_TABLE; i++) {
        DisplayVolumeSurface(solid[i]);
    }
    int kuronekoSize[] = { 60, 80, 100, 120, 140, 160, 180, 200 };
    int yupackSize[] = { 60, 80, 100, 120, 140, 160, 170 };
    double size;

    //Box
    //サイズを求める
    size = box.GetWidth() + box.GetHeight() + box.GetDepth();
    //クロネコ
    for (i = 0; _countof(kuronekoSize); i++) {
        if (size <= kuronekoSize[i]) {
            break;
        }
    }
    //breakした時点のiの数値で判定
    if (i < _countof(kuronekoSize)) {
        cout << "\nこの箱型はクロネコヤマトでは" << kuronekoSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "\nこの箱型はクロネコヤマトの宅急便では送れません。" << endl;
    }
    //ゆうパック
    for (i = 0; _countof(yupackSize); i++) {
        if (size <= yupackSize[i]) {
            break;
        }
    }
    if (i < _countof(yupackSize)) {
        cout << "この箱型はゆうパックでは" << yupackSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "この箱型はゆうパックの宅急便では送れません。" << endl;
    }


    //Cylinder
    size = cylinder.GetRadius() * 2 * 2 + cylinder.GetHeight();
    //クロネコ
    for (i = 0; _countof(kuronekoSize); i++) {
        if (size <= kuronekoSize[i]) {
            break;
        }
    }
    if (i < _countof(kuronekoSize)) {
        cout << "\nこの円柱はクロネコヤマトでは" << kuronekoSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "\nこの円柱はクロネコヤマトの宅急便では送れません。" << endl;
    }
    //ゆうパック
    for (i = 0; _countof(yupackSize); i++) {
        if (size <= yupackSize[i]) {
            break;
        }
    }
    if (i < _countof(yupackSize)) {
        cout << "この円柱はゆうパックでは" << yupackSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "この円柱はゆうパックの宅急便では送れません。" << endl;
    }


    //Cone
    size = cone.GetRadius() * 2 * 2 + cone.GetHeight();
    //クロネコ
    for (i = 0; _countof(kuronekoSize); i++) {
        if (size <= kuronekoSize[i]) {
            break;
        }
    }
    if (i < _countof(kuronekoSize)) {
        cout << "\nこの円錐はクロネコヤマトでは" << kuronekoSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "\nこの円錐はクロネコヤマトの宅急便では送れません。" << endl;
    }
    //ゆうパック
    for (i = 0; _countof(yupackSize); i++) {
        if (size <= yupackSize[i]) {
            break;
        }
    }
    if (i < _countof(yupackSize)) {
        cout << "この円錐はゆうパックでは" << yupackSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "この円錐はゆうパックの宅急便では送れません。" << endl;
    }


    //Sphere
    size = sphere.GetRadius() * 2 * 3;
    //クロネコ
    for (i = 0; _countof(kuronekoSize); i++) {
        if (size <= kuronekoSize[i]) {
            break;
        }
    }
    if (i < _countof(kuronekoSize)) {
        cout << "\nこの球はクロネコヤマトでは" << kuronekoSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "\nこの球はクロネコヤマトの宅急便では送れません。" << endl;
    }
    //ゆうパック
    for (i = 0; _countof(yupackSize); i++) {
        if (size <= yupackSize[i]) {
            break;
        }
    }
    if (i < _countof(yupackSize)) {
        cout << "この球はゆうパックでは" << yupackSize[i] << "サイズで送れます。" << endl;
    }
    else {
        cout << "この球はゆうパックの宅急便では送れません。" << endl;
    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
