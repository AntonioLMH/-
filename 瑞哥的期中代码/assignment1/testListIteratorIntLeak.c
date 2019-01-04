//
// Created by 牟瑞 on 2018-12-19.
//

#include "listIteratorInt.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * 测试添加的方法
 * @param _i
 */
// START_TEST(test_add)
void test_add()
{
    // test
    int val, result;
    int *vp1;

    int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 9; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);

        // 判断没有next的操作
        result = hasNext(it1);
        // fail_unless(result == 0, "error, hasNext(it1) != 0");

        // 判断是否存在Previous的数据
        result = hasPrevious(it1);
        // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

        vp1 = next(it1);
        // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

        vp1 = previous(it1);
        // fail_unless(*vp1 == params[i], "error, previous(it1) != %d", params[i]);

        vp1 = next(it1);
        // fail_unless(*vp1 == params[i], "error, next(it1) != %d", params[i]);
    }

    // release
    freeIt(it1);
}
// END_TEST

/**
 * 测试添加的方法
 * @param _i
 */
// START_TEST(test_iterator_init_null)
void test_iterator_init_null()
{
    // test
    int val, result;
    int *vp1;
    // value
    IteratorInt it1 = NULL;

    // 判断添加
    result = add(it1, 1);
    // fail_unless(result == 0, "error, add(it1, 1) != 0");

    // 判断没有next的操作
    result = hasNext(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0");

    // 判断是否存在Previous的数据
    result = hasPrevious(it1);
    // fail_unless(result == 0, "error, hasPrevious(it1) != 0");

    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    vp1 = previous(it1);
    // fail_unless(vp1 == NULL, "error, previous(it1) != NULL");

    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    vp1 = findPrevious(it1, 1);
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,1) != NULL");

    vp1 = findNext(it1, 1);
    // fail_unless(vp1 == NULL, "error, findNext(it1,1) != NULL");

    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    freeIt(it1);

}
// END_TEST

/**
 * 重点测试老师给的测试case
 * @param _i
 */
// START_TEST(test_teacher_given_cases)
void test_teacher_given_cases()
{
    // test
    int val, result;
    int *vp1;

    // value
    IteratorInt it1 = IteratorIntNew();

    /**
    add 20, returns 1
    ............................
    20   ^
    ............................
    */
    val = 20;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);
    /**
    add 12, returns 1
    ............................
    20   12   ^
    ............................
    */
    val = 12;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    /**
    add 33, returns 1
    ............................
    20   12   33   ^
    ............................
    */
    val = 33;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    /**
    add 25, returns 1
    ............................
    20   12   33   25   ^
    ............................
    */
    val = 25;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    /**
    previous, returns 25
    ............................
    20   12   33   ^   25
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 25, "error, previous(it1) != 25");
    /**
    previous, returns 33
    ............................
    20   12   ^   33   25
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 33, "error, previous(it1) != 33");

    /**
    next, returns 33
    ............................
    20   12   33   ^   25
    ............................
    */
    vp1 = next(it1);
    // fail_unless(*vp1 == 33, "error, next(it1) != 33");
    /**
    delete, returns 1
    ............................
    20   12   ^   25
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    previous, returns 12
    ............................
    20   ^   12   25
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 12, "error, previous(it1) != 12");

    /**
    delete, returns 1
    ............................
    20   ^   25
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    previous, returns 20
    ............................
    ^   20   25
     ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 20, "error, previous(it1) != 12");
    /**
    delete, returns 1
    ............................
    ^   25
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    next, returns 25
    ............................
    25   ^
    ............................
    */
    vp1 = next(it1);
    // fail_unless(*vp1 == 25, "error, next(it1) != 25");

    /**
    delete, returns 1
    ............................
    ^
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");
    /**
    add 55, returns 1
    ............................
    55   ^
    ............................
    */
    val = 55;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);
    /**
    add 29, returns 1
    ............................
    55   29   ^
    ............................
    */
    val = 29;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    /**
    reset
    ............................
    ^   55   29
    ............................
    */
    reset(it1);

    /**
    next, returns 55
    ............................
    55   ^   29
    ............................
    */
    // print(it1);
    vp1 = next(it1);
    // fail_unless(*vp1 == 55, "error, next(it1) != 55");

    /**
    add 62, returns 1
    ............................
    55   62   ^   29
    ............................
    */
    val = 62;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);
    /**
    add 44, returns 1
    ............................
    55   62   44   ^   29
    ............................
    */
    val = 44;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);
    /**
    previous, returns 44
    ............................
    55   62   ^   44   29
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 44, "error, previous(it1) != 12");

    /**
    next, returns 44
    ............................
    55   62   44   ^   29
    ............................
    */
    vp1 = next(it1);
    // fail_unless(*vp1 == 44, "error, next(it1) != 55");
    /**
    delete, returns 1
    ............................
    55   62   ^   29
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    previous, returns 62
    ............................
    55   ^   62   29
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 62, "error, previous(it1) != 12");
    /**
    next, returns 62
    ............................
    55   62   ^   29
    ............................
    */
    vp1 = next(it1);
    // fail_unless(*vp1 == 62, "error, next(it1) != 55");
    /**
    delete, returns 1
    ............................
    55   ^   29
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    delete, returns 0
    ............................
    55   ^   29
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");
    /**
    next, returns 29
    ............................
    55   29   ^
    ............................
    */
    vp1 = next(it1);
    // fail_unless(*vp1 == 29, "error, next(it1) != 55");
    /**
    delete, returns 1
    ............................
    55   ^
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    /**
    previous, returns 55
    ............................
    ^   55
    ............................
    */
    vp1 = previous(it1);
    // fail_unless(*vp1 == 55, "error, previous(it1) != 12");
    /**
    delete, returns 1
    ............................
    ^
    ............................
    */
    result = deleteElm(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    freeIt(it1);
}
// END_TEST

// START_TEST(test_next_case)
void test_next_case()
{
    // test
    int val, result;
    int *vp1;

    // value
    IteratorInt it1 = IteratorIntNew();

    /**
    add 20, returns 1
    ............................
    20   ^
    ............................
    */
    val = 20;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);
    /**
    add 12, returns 1
    ............................
    20   12   ^
    ............................
    */
    val = 12;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    result = hasNext(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0", val);

    vp1 = previous(it1);
    // fail_unless(*vp1 == 12, "error, previous(it1) != 12");

    result = hasNext(it1);
    // fail_unless(result == 1, "error, hasNext(it1) != 1");
    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

    vp1 = previous(it1);
    // fail_unless(*vp1 == 20, "error, previous(it1) != 22");

    result = hasNext(it1);
    // fail_unless(result == 1, "error, hasNext(it1) != 1");
    result = hasPrevious(it1);
    // fail_unless(result == 0, "error, hasPrevious(it1) != 0");

    freeIt(it1);
}
// END_TEST

// START_TEST(test_find_next_case)
void test_find_next_case()
{
    // test
    int val, result;
    int *vp1;

    int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 9; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    // 重置数据
    reset(it1);

    result = hasNext(it1);
    // fail_unless(result == 1, "error, hasNext(it1) != 1");

    val = 20;
    result = add(it1, val);
    // fail_unless(result == 1, "error, add(it1, %d) != 1", val);

    vp1 = next(it1);
    // fail_unless(*vp1 == 20, "error, next(it1) != 20");

    vp1 = findNext(it1, 5);
    // fail_unless(*vp1 == 5, "error, findNext(it1) != 5");

    vp1 = next(it1);
    // fail_unless(*vp1 == 14, "error, next(it1) != 14");

    vp1 = previous(it1);
    // fail_unless(*vp1 == 14, "error, previous(it1) != 14, current value is :%d", *vp1);

    vp1 = previous(it1);
    // fail_unless(*vp1 == 5, "error, previous(it1) != 5");

    freeIt(it1);

}
// END_TEST


// START_TEST(test_find_previous_case)
void test_find_previous_case()
{
    // test
    int val, result;
    int *vp1;

    int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 9; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    result = hasNext(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0");

    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

    vp1 = findPrevious(it1, 5);
    // fail_unless(*vp1 == 5, "error, findPrevious(it1) != 5");

    vp1 = previous(it1);
    // fail_unless(*vp1 == 10, "error, previous(it1) != 14, current value is :%d", *vp1);

    vp1 = findPrevious(it1, 5);
    // fail_unless(*vp1 == 5, "error, findPrevious(it1) != 5");

    freeIt(it1);

}
// END_TEST

// START_TEST(test_find_previous_next_case)
void test_find_previous_next_case()
{
    // test
    int val, result;
    int *vp1;

    int params[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 10; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    // 1 2 3 4 5 6 7 8 9 10 ^
    result = hasNext(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0");

    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, hasPrevious(it1) != 1");


    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    for (int i = 9; i >= 0; i--) {
        result = hasPrevious(it1);
        // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

        vp1 = previous(it1);
        // fail_unless(*vp1 == params[i], "error, previous(it1) != %d, current value is %d,", params[i], *vp1);
    }
    // ^ 1 2 3 4 5 6 7 8 9 10

    result = hasPrevious(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0");

    result = hasNext(it1);
    // fail_unless(result == 1, "error, hasNext(it1) != 1");


    for (int i = 0; i < 10; i ++) {
        result = hasNext(it1);
        // fail_unless(result == 1, "error, hasNext(it1) != 1");

        vp1 = next(it1);
        // fail_unless(*vp1 == params[i], "error, previous(it1) != %d, current value is %d,", params[i], *vp1);
    }

    // 1 2 3 4 5 6 7 8 9 10 ^
    // 之前的next的内容需要保留，因此还是原来的next查询的结果：10
    vp1 = findNext(it1,2);
    // fail_unless(vp1 == NULL, "error, findNext(it1,2) != NULL");

    vp1 = findPrevious(it1,2);
    // 1 ^ 2 3 4 5 6 7 8 9 10
    // fail_unless(*vp1 == 2, "error, findPrevious(it1,2) != 2,current value is %d",*vp1);


    vp1 = findNext(it1,10);
    // 1 2 3 4 5 6 7 8 9 10 ^
    // fail_unless(*vp1 == 10, "error, findNext(it1,10) != 10,current value is %d",*vp1);
    // print(it1);
    vp1 = findNext(it1,10);
    // fail_unless(vp1 == NULL, "error, findNext(it1,10) != NULL");
    vp1 = findNext(it1,1000);
    // fail_unless(vp1 == NULL, "error, findNext(it1,1000) != NULL");

    vp1 = findPrevious(it1,1);
    // ^ 1 2 3 4 5 6 7 8 9 10
    // fail_unless(*vp1 == 1, "error, findPrevious(it1,1) != 1,current value is %d",*vp1);

    vp1 = findPrevious(it1,1);
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,1) != NULL");

    vp1 = findPrevious(it1,1000);
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,1000) != NULL");

    freeIt(it1);

}
// END_TEST

// START_TEST(test_set_cases)
void test_set_cases()
{
    // test
    int val, result;
    int *vp1;

    int params[9] = {20, 12, 15, 5, 14, 10, 5, 9, 3};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 9; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    // 20 12 15 5 14 10 5 9 3 ^
    // set
    result = set(it1, 1000);
    // fail_unless(result == 0, "error, set(it1,1000) != 0");

    // check has previous
    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

    // 20 12 15 5 14 10 5 9 ^ 3
    vp1 = previous(it1);
    // fail_unless(*vp1 == 3, "error, previous(it1) != 3, current value is :%d", *vp1);

    // set
    // 20 12 15 5 14 10 5 9 ^ 1000
    result = set(it1, 1000);
    // fail_unless(result == 1, "error, set(it1,1000) != 1");

    // set
    result = set(it1, 1000);
    // fail_unless(result == 0, "error, set(it1,1000) != 0");

    // check has previous
    result = hasNext(it1);
    // fail_unless(result == 1, "error, hasNext(it1) != 1");

    vp1 = next(it1);
    // 20 12 15 5 14 10 5 9 1000 ^
    // fail_unless(*vp1 == 1000, "error, next(it1) != 1000, current value is :%d", *vp1);


    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, hasPrevious(it1) != 1");

    result = set(it1, 1001);
    // fail_unless(result == 0, "error, set(it1,1000) != 0");

    // ^ 20 12 15 5 14 10 5 9 1000
    reset(it1);

    result = set(it1, 1001);
    // fail_unless(result == 0, "error, set(it1,1000) != 0");

    vp1 = next(it1);
    // 20 ^ 12 15 5 14 10 5 9 1000
    // fail_unless(*vp1 == 20, "error, next(it1) != 20, current value is :%d", *vp1);

    result = set(it1, 1001);
    // 1001 ^ 12 15 5 14 10 5 9 1000
    // fail_unless(result == 1, "error, set(it1,1000) != 1");

    vp1 = previous(it1);
    // ^ 1001 12 15 5 14 10 5 9 1000
    // fail_unless(*vp1 == 1001, "error, previous(it1) != 1001, current value is :%d", *vp1);

    vp1 = findNext(it1, 15);
    // 1001 12 15 ^ 5 14 10 5 9 1000
    // fail_unless(*vp1 == 15, "error, findNext(it1,15) != 15, current value is :%d", *vp1);

    result = set(it1, 1100);
    // 1001 12 1100 ^ 5 14 10 5 9 1000
    // fail_unless(result == 1, "error, set(it1,1100) != 1");

    vp1 = previous(it1);
    // 1001 12 ^ 1100 5 14 10 5 9 1000
    // fail_unless(*vp1 == 1100, "error, previous(it1) != 1100, current value is :%d", *vp1);

    vp1 = findPrevious(it1, 12);
    // 1001 ^ 12 1100 5 14 10 5 9 1000
    // fail_unless(*vp1 == 12, "error, findPrevious(it1,12) != 12, current value is :%d", *vp1);

    result = set(it1, 1200);
    // 1001 1200 1100 ^ 5 14 10 5 9 1000
    // fail_unless(result == 1, "error, set(it1,1200) != 1");

    result = set(it1, 1500);
    // 1001 1200 1100 ^ 5 14 10 5 9 1000
    // fail_unless(result == 0, "error, set(it1,1500) != 0");

    vp1 = findNext(it1, 1000);
    // 1001 1200 1100 5 14 10 5 9 1000 ^
    // fail_unless(*vp1 == 1000, "error, findNext(it1,1000) != 1000, current value is :%d", *vp1);

    vp1 = findPrevious(it1, 5000);
    // 1001 1200 1100 5 14 10 5 9 1000 ^
    // 因为没有找到，所以原来的位置不变
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,5000) != NULL");

    result = set(it1, 1500);
    // 1001 1200 1100 5 14 10 5 9 1000 ^
    // fail_unless(result == 0, "error, set(it1,1500) != 0");

    vp1 = previous(it1);
    // 1001 1200 1100 5 14 10 5 9 ^ 1000
    // fail_unless(*vp1 == 1000, "error, previous(it1) != 1000, current value is :%d", *vp1);


    result = add(it1, 10000);
    // 1001 1200 1100 5 14 10 5 9 10000 ^ 1500
    // fail_unless(result == 1, "error, set(it1,1200) != 1");

    result = set(it1, 20000);
    // 1001 1200 1100 5 14 10 5 9 10000 ^ 1500
    // fail_unless(result == 0, "error, set(it1,20000) != 0");

    freeIt(it1);

}
// END_TEST

// START_TEST(test_delete_case)
void test_delete_case()
{
    // test
    int val, result;
    int *vp1;

    int params[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // value
    IteratorInt it1 = IteratorIntNew();

    for (int i = 0; i < 10; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    // 1 2 3 4 5 6 7 8 9 10 ^
    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    // 1 2 3 4 5 6 7 8 9 10 ^
    result = hasNext(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    result = hasPrevious(it1);
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    vp1 = previous(it1);
    // 1 2 3 4 5 6 7 8 9 ^ 10
    // fail_unless(*vp1 == 10, "error, previous(it1) != 10, current value is :%d", *vp1);

    result = set(it1, 1000);
    // 1 2 3 4 5 6 7 8 9 ^ 1000
    // fail_unless(result == 1, "error, set(it1, 1000) != 1");

    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    vp1 = next(it1);
    // 1 2 3 4 5 6 7 8 9 1000 ^
    // fail_unless(*vp1 == 1000, "error, previous(it1) != 1000, current value is :%d", *vp1);

    result = deleteElm(it1);
    // 1 2 3 4 5 6 7 8 9 ^
    // fail_unless(result == 1, "error, deleteElm(it1) != 0");

    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    vp1 = previous(it1);
    // 1 2 3 4 5 6 7 8 ^ 9
    // fail_unless(*vp1 == 9, "error, previous(it1) != 10, current value is :%d", *vp1);

    result = deleteElm(it1);
    // 1 2 3 4 5 6 7 8 ^
    // fail_unless(result == 1, "error, deleteElm(it1) != 1");

    result = set(it1, 2000);
    // fail_unless(result == 0, "error, set(it1, 2000) != 0");

    freeIt(it1);
}
// END_TEST

// START_TEST(test_free_case)
void test_free_case()
{
    // test
    int val, result;
    int *vp1;

    int params[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // value
    IteratorInt it1 = IteratorIntNew();

    // free
    freeIt(it1);

    it1 = NULL;

    reset(it1);
    // printf("address of it1 %p\n",&it1);
    result = hasNext(it1);
    // fail_unless(result == 0, "error, hasNext(it1) != 0");

    // printf("address of it1 %p \n",&it1);
    result = hasPrevious(it1);
    // printf("address of it1 %p \n",&it1);
    // print(it1);
    // fail_unless(result == 0, "error, hasPrevious(it1) != 0,result value is %d",result);

    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    vp1 = previous(it1);
    // fail_unless(vp1 == NULL, "error, previous(it1) != NULL");

    vp1 = findNext(it1,1000);
    // fail_unless(vp1 == NULL, "error, findNext(it1,1000 != NULL");

    vp1 = findPrevious(it1,1000);
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,1000 != NULL");

    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    result = set(it1,1);
    // fail_unless(result == 0, "error, set(it1,1)!= 0");

    // add
    result = add(it1,1);
    // fail_unless(result == 0, "error, add(it1,1)!= 0");

    // 再次free
    freeIt(it1);
    it1 = NULL;

    reset(it1);


    // ren new again
    it1 = IteratorIntNew();

    for (int i = 0; i < 10; i++) {
        result = add(it1, params[i]);
        // fail_unless(result == 1, "error, add(it1, %d) != 1", params[i]);
    }

    reset(it1);

    // free
    freeIt(it1);
    it1 = NULL;

    reset(it1);

    result = hasNext(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    result = hasPrevious(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    vp1 = next(it1);
    // fail_unless(vp1 == NULL, "error, next(it1) != NULL");

    vp1 = previous(it1);
    // fail_unless(vp1 == NULL, "error, previous(it1) != NULL");

    vp1 = previous(it1);
    // fail_unless(vp1 == NULL, "error, previous(it1) != NULL");

    vp1 = findNext(it1,1000);
    // fail_unless(vp1 == NULL, "error, findNext(it1,1000 != NULL");

    vp1 = findPrevious(it1,1000);
    // fail_unless(vp1 == NULL, "error, findPrevious(it1,1000 != NULL");

    result = deleteElm(it1);
    // fail_unless(result == 0, "error, deleteElm(it1) != 0");

    result = set(it1,1);
    // fail_unless(result == 0, "error, set(it1,1)!= 0");

    // add
    result = add(it1,1);
    // fail_unless(result == 0, "error, add(it1,1)!= 0");

    reset(it1);

    freeIt(it1);

    it1 = NULL;

    reset(it1);

    it1 = NULL;
}
// END_TEST



int main(void) {


    // 测试用例加到测试集中
    // 测试添加数据
    // tcase_add_test(tc_case, test_add);
    test_add();

    // 测试初始化为空的情况
    // tcase_add_test(tc_case, test_iterator_init_null);
    test_iterator_init_null();
    // 测试老师给定的case
    // tcase_add_test(tc_case, test_teacher_given_cases);
    test_teacher_given_cases();
    // 测试用例加到测试集中
    // tcase_add_test(tc_case, test_next_case);
    test_next_case();
    // 测试find next
    // tcase_add_test(tc_case, test_find_next_case);

    test_find_next_case();

    // 测试set 的操作
    // tcase_add_test(tc_case, test_set_cases);
    test_set_cases();

    // 测试delete
    // tcase_add_test(tc_case, test_delete_case);
    test_delete_case();

    // 测试free
    // tcase_add_test(tc_case, test_free_case);
    test_free_case();

    // 测试next,previous,find next,find previous 的操作
    // tcase_add_test(tc_case, test_find_previous_next_case);
    test_find_previous_next_case();

    // test find previous
    // tcase_add_test(tc_case, test_find_previous_case);
    test_find_previous_case();

    return 0;
}