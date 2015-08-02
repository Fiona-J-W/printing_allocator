#include <map>
#include <string>
#include "pa/printing_allocator.hpp"

int main() {
	using namespace std::string_literals;
	std::map<std::string, std::string, std::less<>, pa::printing_allocator<std::pair<const std::string, std::string>>> m;
	std::cout << "sizeof std::map<K, V> = " << sizeof(m) << '\n';
	m["foo"s] = "bar"s;
}
