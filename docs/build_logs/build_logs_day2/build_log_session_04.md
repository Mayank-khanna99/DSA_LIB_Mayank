# Build Log – Session 4 (Bug Fixes & Testing)

**Date:** 2 July 2026 | **Time:** 5:00 PM – 6:00 PM

## Objective

This session focused on debugging the `LinkedList<T>` implementation and validating all implemented functionality through comprehensive test cases.

---

## Bugs Fixed

- Fixed incorrect allocator object name (`allocate` → `allocator`).
- Corrected the return type of `pop_back()` from `void` to `T`.
- Fixed boundary conditions in `remove()` for first and last element removal.
- Added exception handling in `front()` and `back()` to prevent null pointer dereferencing on empty lists.
- Corrected memory deallocation logic in `pop_front()` and `pop_back()`.
- Fixed issues related to list size updates after insertion and deletion.
- Verified that the copy constructor performs a deep copy instead of copying node pointers.

---

## Testing Performed

Created a dedicated test program to verify:

- Empty list operations
- Single element operations
- `push_front()` / `push_back()`
- `pop_front()` / `pop_back()`
- `insert()`
- `remove()`
- `find()`
- `operator[]`
- `front()` / `back()`
- `clear()`
- Copy constructor
- Exception handling for invalid operations

All implemented test cases passed successfully.

---

## Outcome

The linked list implementation is now stable for all currently implemented operations and correctly handles both normal and edge-case scenarios. The project is ready for implementing the remaining Rule of Five functions and iterator support in the next development session.