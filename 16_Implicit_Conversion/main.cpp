//
//  main.cpp
//  16_Implicit_Conversion
//
//  Created by 세광 on 2021/07/03.
//

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    // 변환 생성자의 역할: 다른 타입을 자신의 타입으로 고쳐주는 역할
    // 똑같은 모양의 생성자이지만 역할에 따라 변환 생성자가 될 수도 있고 일반적인 생성자가 될 수도 있음
    // explicit을 사용할 경우 묵시적 형변환을 막음 (명시적으로 적지 않을 경우 에러 발생) (ex. explicit Item(int num) { })
    Item(int num) : num(num) { // 변환 생성자
        cout << "Item(int)" << endl;
    }
    Item(string name) : name(name) { // 변환 생성자
        cout << "Item(string)" << endl;
    }
    Item(int num, string name) : num(num), name(name) {
        cout << "Item(int, string)" << endl;
    }
    
    // C, C++에서 형변환은 연산자 -> 연산자 오버로딩
    // 형변환 연산자의 경우 처음에 반환 타입을 적지 않음
    // int로의 형변환 연산자 오버로딩
    operator int() const {
        return num;
    }
    
    // string으로의 형변환 연산자 오버로딩
    operator string() const {
        return to_string(num) + " : " + name; // to_string(): 숫자를 문자열로 바꿔주는 함수
    }
    
    void print() {
        cout << num << " : " << name << endl;
    }
    
private:
    int num;
    string name;
};

void println(string s) {
    cout << s << endl;
}

void println(int n) {
    cout << n << endl;
}

int main() {
    // 생성자(Item(int)) 호출
    Item i1 = Item(1);
    Item i2(2);
    Item i3 = 3;
    
    i3 = 3; // 묵시적 변환
    Item i4 = (Item)4; // 명시적 변환
    
    Item i5(5);
    i5 = (string)"stone"; // 명시적 변환
    // string("stone"); -> const char*를 string으로 바꾸는 변환 생성자를 호출하라는 의미
    // (string)"stone"; -> const char*를 string으로 형변환하라는 의미
    
    // 생성자(Item(int)) 호출
    Item i6(1, "grass");
    Item i7 = { 2, "dirt" };
    i7 = { 2, "dirt" }; // 묵시적 변환
    Item i8{ 3, "wood" };
    
    int itemNum1 = (int)i8; // 명시적 형변환
    int itemNum2 = i7; // 묵시적 형변환
    cout << itemNum1 << endl;
    cout << itemNum2 << endl;
    
    string itemName = (string)i7;
    
    println((string)i8); // 명시적 형변환
    println((int)i8); // 명시적 형변환
}
