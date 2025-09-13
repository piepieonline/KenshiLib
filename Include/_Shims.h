#pragma once
#include <cstddef>
#include <functional>
#include <utility>
#include <boost/container_hash/hash_fwd.hpp>

namespace std_shim {

	template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T>>
	>
	class alignas(8) map {
	public:
		// Reserve the same size as std::map on typical x64 implementations (0x28 bytes)
		// You can adjust this if needed based on platform or compiler
		char _data[0x28];

		// Default constructor
		map() {}

		// Disable copy/move for simplicity (optional)
		map(const map&) = delete;
		map& operator=(const map&) = delete;

		// You can optionally add stubs for .find(), .insert(), etc. if code expects them
		void insert(const std::pair<const Key, T>&) {}
		T& operator[](const Key&) { static T dummy; return dummy; }
	};

		template <
		typename Key,
		typename T,
		typename Compare = std::less<Key>,
		typename Allocator = std::allocator<std::pair<const Key, T>>
	>
	class alignas(8) set {
	public:
		// Reserve the same size as std::map on typical x64 implementations (0x28 bytes)
		// You can adjust this if needed based on platform or compiler
		char _data[0x28];
	};

	template <
		typename T,
		typename Alloc = std::allocator<T>
	>
	class alignas(8) deque {
		// Just a raw storage buffer, matching the size of release std::deque
		// on your target ABI (0x30 = 48 bytes)
		alignas(void*) char storage[0x30];

	public:
		// Type traits so it looks "container-like"
		using value_type = T;
		using allocator_type = Alloc;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using pointer = typename std::allocator_traits<Alloc>::pointer;
		using const_pointer = typename std::allocator_traits<Alloc>::const_pointer;

		// Dummy constructors/destructor
		deque() noexcept {}
		~deque() {}

		// Deleted to avoid accidental use � this is just a stand-in
		deque(const deque&) = delete;
		deque& operator=(const deque&) = delete;
	};
}

namespace boost_shim {

	namespace unordered {
		template <
			typename Key,
			typename T,
			typename Hash = boost::hash<Key>,
			typename Pred = std::equal_to<Key>,
			typename Alloc = std::allocator<std::pair<const Key, T>>
		>
		class alignas(8) unordered_map {
		public:
			// Release x64 Boost unordered_map typical size (~0x20 bytes, adjust if needed)
			char _data[0x40];

			unordered_map() {}

			// Disable copy/move for simplicity
			unordered_map(const unordered_map&) = delete;
			unordered_map& operator=(const unordered_map&) = delete;

			// Minimal stubs for common functions
			void insert(const std::pair<const Key, T>&) {}
			T& operator[](const Key&) { static T dummy; return dummy; }
			T* find(const Key&) { return nullptr; }
			std::size_t size() const { return 0; }
		};


		template <
			typename Key,
			typename Hash = boost::hash<Key>,
			typename Pred = std::equal_to<Key>,
			typename Alloc = std::allocator<Key>
		>
		class alignas(8) unordered_set {
		public:
			// Release x64 Boost unordered_set typical size (~0x20 bytes, adjust if needed)
			char _data[0x40];

			unordered_set() {}

			// Disable copy/move for simplicity
			unordered_set(const unordered_set&) = delete;
			unordered_set& operator=(const unordered_set&) = delete;

			// Minimal stubs
			void insert(const Key&) {}
			Key* find(const Key&) { return nullptr; }
			std::size_t size() const { return 0; }
		};
	}
}