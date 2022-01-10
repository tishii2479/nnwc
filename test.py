import os
import glob
from subprocess import run


def init_test():
    """
    Setup for test
    """
    test_out_dir = 'out/tests/'
    if not os.path.exists(test_out_dir):
        os.makedirs(test_out_dir)


def get_test_files():
    """
    [Return]
    list<string> test_files: paths of test src files
    """
    return glob.glob("tests/*.cpp")


def run_test(test_file):
    """
    [Params]
    string test_file: path to test file
    [Return]
    integer returncode: the return code of the result of running the test
    """
    src_file = test_file
    out_file = 'out/' + test_file.removesuffix('.cpp') + '.o'
    run(['g++', '-std=c++17', src_file, '-o', out_file])
    return run([out_file]).returncode


def main():
    init_test()
    test_files = get_test_files()
    for test_file in test_files:
        print('Testing:', test_file)
        result = run_test(test_file)
        if result != 0:
            print('Test failed:', test_file, ', return code:', result)
            break
        else:
            print('Test passed:', test_file, ', return code:', result)

    print()
    print('----------------------------------------')
    print('All test passed!')
    print('Test count:', len(test_files))
    print('----------------------------------------')
    print()


if __name__ == '__main__':
    main()
