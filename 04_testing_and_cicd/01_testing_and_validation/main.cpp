#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stdexcept>


/*----これらの関数を変更する必要はありません----*/

std::vector<std::string> names {"Nick", "Lewis", "Nikos"};

bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
    return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}

std::string get_name(const std::string& name, const std::vector<std::string>& list_of_names) {
    if (contains(name, list_of_names)) {
        return name;
    } else {
        return "";
    }
}

void add_name(const std::string& name, std::vector<std::string>& list_of_names) {
    list_of_names.push_back(name);
}

int add_two(int num) {
    return num + 2;
}

double divide_by_two(double num) {
    return num / 2;
}

std::string greeting(const std::string& name, double num) {
    std::string message {"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
    std::cout << message << std::endl;
    return message;
}

/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/
// `my_assert` をここに定義し、以降のテストに使用してください。
void my_assert(bool expr, std::string msg){
    if(!expr){
        throw std::runtime_error(msg);
    } else{
        std::cout <<  " Passed the test!" << std::endl;
    }
}

// `contains` 用のテスト `test_contains` を作成してください
void test_contains(){

    std::vector<std::string> names {"Nick", "Lewis", "Nikos"};
    my_assert(contains("Nick", names) == true, "Ontput of function contains was not expected " );
    my_assert(contains("Mike", names) == false, "Ontput of function contains was not expected " );

}

// `get_name` 用のテスト `test_get_name` を作成してください

void test_get_name(){

    std::vector<std::string> names {"Nick", "Lewis", "Nikos"};
    my_assert(get_name("Nick", names) == "Nick", "Ontput of function get_name was not expected " );
    my_assert(get_name("Mike", names) == "", "Ontput of function get_name was not expected " );

}

// `add_name` 用のテスト `test_add_name` を作成してください

void test_add_name(){

    std::vector<std::string> names {"Nick", "Lewis", "Nikos"};
    try{
        int nameSize = names.size();
        add_name("Mike",names);
        my_assert(names.size() == nameSize + 1, "Ontput of function test_add_name was not expected");
        my_assert(names[3] == "Mike", "The unexpected name was added");
    } catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

}

// `add_two` 用のテスト `test_add_two` を作成してください
void test_add_two(){

    int a = 0;
    my_assert(add_two(a) == 2, "Ontput of function add_two was not expected " );

}

// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください
void test_divide_by_two(){

    int a = 2;
    my_assert(divide_by_two(a) == 1, "Ontput of function divide_by_two was not expected " );

}

// `greeting` 用のテスト `test_greeting` を作成してください
void test_greeting(){

    std::vector<std::string> names {"Nick", "Lewis", "Nikos"};
    std::string expected_msg = "Hello, Nick. It is 2.000000 degrees warmer today than yesterday";
    my_assert(greeting("Nick", 2) == expected_msg,"Ontput of function greeting was not expected ");

}

int main() {
    try{
        test_contains();
        test_get_name();
        test_add_name();
        test_add_two();
        test_divide_by_two();
        test_greeting();
    }catch(std::runtime_error e){
        std::cerr << "FAILD: " << e.what() << std::endl;
    }
    

    return 0;
}

/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg` を適切に返すかどうかをチェックしてください。

// `my_assert` 用のテスト `test_my_assert_true` を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。

/*----難易度: エベレスト----*/

// 次の式全体をテストする `test_complex_greeting` を `my_assert` を使用して作成してください。式がエラーになった場合は、エラーの理由がわかるメッセージを `msg` に指定してください。
// greeting(get_name("Frosty the Snowman", {"Oatmeal", "Prancer", "Rudolph", "Andy"}), divide_by_two(add_two(2)));
