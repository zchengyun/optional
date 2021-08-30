#include <iostream>
#include <optional>

void  fun1(bool flag,std::string &hello1, std::string& hello2) {
    if (flag) {
		hello1 = "hello1";
		hello2 = "hello2";
    }
}

struct out {
	std::string out1{ "" };
	std::string out2{ "" };
};

std::optional<out> fun2() {//实际上用pair和tuple也可以,这里返回的是一个指针
	out o;
	o.out1 = "hello";
	o.out2 = "world";
	return { o };
}

int main()
{
    std::string hello1;
    std::string hello2;
    fun1(true, hello1, hello2);//以前采用传入引用的方式改变值
    std::cout << "hello1="<<hello1<<"\thello2="<<hello2<<"\n";

	auto ret = fun2();
	std::cout << "ret.out1=" << ret->out1 << "\tret.out2=" << ret->out2 << "\n";
}
