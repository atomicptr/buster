project('buster', 'cpp', default_options : ['cpp_std=c++23'])

buster = include_directories('src')

test_expect = executable('test_expect', 'tests/test_expect.cpp', include_directories : buster)
test('test_expect', test_expect)
