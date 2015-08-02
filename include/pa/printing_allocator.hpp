#ifndef PA_PRINTING_ALLOCATOR_HPP
#define PA_PRINTING_ALLOCATOR_HPP

#include <cstdint>
#include <iostream>

namespace pa {

template<typename T>
class printing_allocator {
public:
	typedef T value_type;

	printing_allocator() = default;

	template <class Other>
	printing_allocator(const printing_allocator<Other>&) {}
	T* allocate(std::size_t n) {
		std::cout << "allocating " << n << " * " << sizeof(T) << " = " << n * sizeof(T) << "bytes\n";
		return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
	}
	void deallocate(T* p, std::size_t n) {
		std::cout << "deallocating " << n << " objects of " << sizeof(T) << " bytes size (=" << n * sizeof(T) << ")\n";
		::operator delete(p, n);
	}
};

template <class T, class U>
bool operator==(const printing_allocator<T>&, const printing_allocator<U>&) {
	return true;
}

template <class T, class U>
bool operator!=(const printing_allocator<T>&, const printing_allocator<U>&) {
	return false;
}


}



#endif
