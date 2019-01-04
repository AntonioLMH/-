# 说明：

assignment1的测试，主要采用的是c语言的check测试框架
check测试框架的官方地址为：https://libcheck.github.io/check/

Mac操作系统的check安装命令：brew install check

其他的操作系统安装，如果官方网站没有的，就只能自求多福了。

针对assignment1的测试，将listIteratorInt.c文件到assignment1里面

该assignment的测试分为两个部分：make test的功能测试和make leak 的内存泄漏测试。

- make test 功能测试部分

测试环境：本地环境：linux系统或者mac系统（特别注意，学校机房不支持check，因此该脚本不支持学校机房check）

运行：make test

运行：./murui_test.out 即可出现测试结果

```
Running suite(s): COMP9024 Assignment 1
100%: Checks: 6, Failures: 0, Errors: 0
testListIteratorInt.c:45:P:test_cases:test_add:0: Passed
testListIteratorInt.c:90:P:test_cases:test_iterator_init_null:0: Passed
testListIteratorInt.c:379:P:test_cases:test_teacher_given_cases:0: Passed
testListIteratorInt.c:428:P:test_cases:test_next_case:0: Passed
testListIteratorInt.c:471:P:test_cases:test_find_next_case:0: Passed
testListIteratorInt.c:509:P:test_cases:test_find_previous_case:0: Passed
```
解释如下：

1.Checks    表示的是进行了6大项的check

2.Failures  表示测试失败。

3.Errors    表示测试出现了异常

4.Passed    表示当前的测试case全部通过

常见错误说明：

1.Segmentation fault
```
testListIteratorInt.c:15:E:test_cases:test_add:0: (after this point) Received signal 11 (Segmentation fault: 11)
```

出现Segmentation fault 绝对是C语言开发的噩梦，一般是指对一个无效的地址进行赋值，比如：
```
Node *new_node = NULL;
new_node->data = (int *) malloc(sizeof(int));
```
对数组的操作也特别容易出现Segmentation fault，比如数组越界：
```
int a[2] = {1,2};
int i=-1;
printf("%d",a[i++]);
```
上面的i++实际上是-1，此时越界，导致出现Segmentation fault

关于测试的时候出现异常的故障排除方式可以采用以下两种方式：

1.在listIteratorInt.h文件里面添加方法
```
void print(IteratorInt it);
```
在listIteratorInt.c文件里面按照老师的格式打印输出列表的内容：
```
1001 1200 1100 ^ 5 14 10 5 9 1000
```
然后在测试的脚本文件testListIteratorInt.c 调用print方法，实时输出结果
```
result = set(it1,1000);
print(it1);
fail_unless(result == 0, "error, set(it1,1000) != 0");
```
这样就可以看到每一步的数据情况

2.是将testListIteratorInt.c 中出错的测试case，拿出来单独测试。

即写到一个main方法里面，采用debug的方式单独调试该case。
```
int main(void) {
    // test
    int val, result;
    int *vp1;

    int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 9; i++) {
        result = add(it1, params[i]);
    }

    // 20 12 15 5 14 10 5 9 3 ^
    // set
    print(it1);
    result = set(it1,1000);

    print(it1);
    // check has previous
    result = hasPrevious(it1);

    print(it1);
    // 20 12 15 5 14 10 5 9 ^ 3
    vp1 = previous(it1);

    print(it1);

}
```

- make leak 内存泄漏测试

测试环境：学校机房环境

（特别注意，个人笔记本的C环境随着操作系统的不同，会做很多优化，特别是mac系统，因此不建议在本地做测试，请务必在学校机房通过该测试）

运行工具：valgrind 学校机房已经安装

运行：make leak

运行：valgrind --leak-check=full ./murui_leck.out 即可出现测试结果

```
==30325== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==30325== Command: ./murui_leck.out
==30325== 
==30325== 
==30325== HEAP SUMMARY:
==30325==     in use at exit: 0 bytes in 0 blocks
==30325==   total heap usage: 166 allocs, 166 frees, 1,408 bytes allocated
==30325== 
==30325== All heap blocks were freed -- no leaks are possible
==30325== 
==30325== For counts of detected and suppressed errors, rerun with: -v
==30325== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

出现上述的信息，即可表示测试通过，否则，代码存在内存泄漏，需要修改相关代码





