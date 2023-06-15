# Reproduce memory leak in Criterion

Usage:

``` sh
./reproduce.sh
```


Should give output similar to:

```
$ ./reproduce.sh
The Meson build system
Version: 0.64.1
Source dir: [...]/criterion-leak
Build dir: [...]/criterion-leak/build
Build type: native build
Project name: leaky
Project version: 0.1
C compiler for the host machine: cc (gcc 11.3.0 "cc (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0")
C linker for the host machine: cc ld.bfd 2.38
Host machine cpu family: x86_64
Host machine cpu: x86_64
Found pkg-config: /usr/bin/pkg-config (0.29.2)
Run-time dependency criterion found: YES 2.4.2
Build targets in project: 1

leaky 0.1

  User defined options
    b_sanitize: address

Found ninja-1.11.1.git.kitware.jobserver-1 at /usr/bin/ninja
INFO: autodetecting backend as ninja
INFO: calculating backend command to run: /usr/bin/ninja -C [...]/criterion-leak/build
ninja: Entering directory `[...]/criterion-leak/build'
[2/2] Linking target leaky
ninja: no work to do.
ninja: Entering directory `[...]/criterion-leak/build'
ninja: no work to do.
1/1 leaky-test RUNNING
>>> MALLOC_PERTURB_=47 [...]/criterion-leak/build/leaky
――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― ✀  ――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――

=================================================================
==208790==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 128 byte(s) in 1 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c6c6cc in cri_assert_node_add ../src/core/assert.c:49
    #2 0x562c60a2d37c in leaky_leaky_test_impl ../leaky.c:10
    #3 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #4 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #5 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #6 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #7 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 768 byte(s) in 1 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c6c6cc in cri_assert_node_add ../src/core/assert.c:49
    #2 0x562c60a2d7b5 in leaky_leaky_test_impl ../leaky.c:10
    #3 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #4 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #5 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #6 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #7 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 99 byte(s) in 3 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c8045e in cri_fmt_vbprintf ../src/string/fmt.c:70
    #2 0x7f3245c8061a in cr_vasprintf ../src/string/fmt.c:97
    #3 0x7f3245c8059e in cr_asprintf ../src/string/fmt.c:88
    #4 0x562c60a2d3d9 in leaky_leaky_test_impl ../leaky.c:10
    #5 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #6 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #7 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #8 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #9 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 43 byte(s) in 1 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c8045e in cri_fmt_vbprintf ../src/string/fmt.c:70
    #2 0x7f3245c80374 in cri_fmt_bprintf ../src/string/fmt.c:42
    #3 0x562c60a2cd39 in leaky_leaky_test_impl ../leaky.c:10
    #4 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #5 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #6 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #7 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #8 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 43 byte(s) in 1 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c8045e in cri_fmt_vbprintf ../src/string/fmt.c:70
    #2 0x7f3245c80374 in cri_fmt_bprintf ../src/string/fmt.c:42
    #3 0x562c60a2d1bb in leaky_leaky_test_impl ../leaky.c:10
    #4 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #5 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #6 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #7 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #8 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 6 byte(s) in 3 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c8045e in cri_fmt_vbprintf ../src/string/fmt.c:70
    #2 0x7f3245c8061a in cr_vasprintf ../src/string/fmt.c:97
    #3 0x7f3245c8059e in cr_asprintf ../src/string/fmt.c:88
    #4 0x562c60a2c60e in cr_user_int_tostr /usr/local/include/criterion/internal/assert/tag.h:247
    #5 0x562c60a2d5bc in leaky_leaky_test_impl ../leaky.c:10
    #6 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #7 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #8 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #9 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #10 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

Indirect leak of 6 byte(s) in 3 object(s) allocated from:
    #0 0x7f3245eb4c18 in __interceptor_realloc ../../../../src/libsanitizer/asan/asan_malloc_linux.cpp:164
    #1 0x7f3245c8045e in cri_fmt_vbprintf ../src/string/fmt.c:70
    #2 0x7f3245c8061a in cr_vasprintf ../src/string/fmt.c:97
    #3 0x7f3245c8059e in cr_asprintf ../src/string/fmt.c:88
    #4 0x562c60a2c60e in cr_user_int_tostr /usr/local/include/criterion/internal/assert/tag.h:247
    #5 0x562c60a2d44b in leaky_leaky_test_impl ../leaky.c:10
    #6 0x7f3245c7655a in criterion_internal_test_main ../src/core/test.c:94
    #7 0x562c60a2c6a9 in leaky_leaky_test_jmp ../leaky.c:5
    #8 0x7f3245c74b29 in run_test_child ../src/core/runner_coroutine.c:230
    #9 0x7f3245c86d72 in bxfi_main ../subprojects/boxfort/src/sandbox.c:57
    #10 0x7f3245a29d8f  (/lib/x86_64-linux-gnu/libc.so.6+0x29d8f)

SUMMARY: AddressSanitizer: 1093 byte(s) leaked in 13 allocation(s).
[====] Synthesis: Tested: 1 | Passing: 1 | Failing: 0 | Crashing: 0
―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――
1/1 leaky-test OK              0.03s


Ok:                 1
Expected Fail:      0
Fail:               0
Unexpected Pass:    0
Skipped:            0
Timeout:            0

Full log written to [...]/criterion-leak/build/meson-logs/testlog.txt
```
