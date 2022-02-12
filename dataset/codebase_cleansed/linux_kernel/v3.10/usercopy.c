unsigned long
__generic_copy_to_user(void *to, const void *from, unsigned long n)
{
if (access_ok(VERIFY_WRITE, to, n))
__copy_user(to, from, n);
return n;
}
unsigned long
__generic_copy_from_user(void *to, const void *from, unsigned long n)
{
if (access_ok(VERIFY_READ, from, n))
__copy_user_zeroing(to, from, n);
return n;
}
long
__strncpy_from_user(char *dst, const char *src, long count)
{
long res;
__do_strncpy_from_user(dst, src, count, res);
return res;
}
long
strncpy_from_user(char *dst, const char *src, long count)
{
long res = -EFAULT;
if (access_ok(VERIFY_READ, src, 1))
__do_strncpy_from_user(dst, src, count, res);
return res;
}
unsigned long
__clear_user(void *to, unsigned long n)
{
__do_clear_user(to, n);
return n;
}
unsigned long
clear_user(void *to, unsigned long n)
{
if (access_ok(VERIFY_WRITE, to, n))
__do_clear_user(to, n);
return n;
}
long strnlen_user(const char *s, long n)
{
unsigned long res, w;
if (!__addr_ok(s))
return 0;
if (n < 0 || n + (u_long) s > current_thread_info()->addr_limit.seg)
n = current_thread_info()->addr_limit.seg - (u_long)s;
asm volatile(
"0: cmp %4,%0\n"
" beq 2f\n"
"1: movbu (%0,%3),%1\n"
" inc %0\n"
" cmp 0,%1\n"
" beq 3f\n"
" bra 0b\n"
"2: clr %0\n"
"3:\n"
".section .fixup,\"ax\"\n"
"4: jmp 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .balign 4\n"
" .long 1b,4b\n"
".previous\n"
:"=d"(res), "=&r"(w)
:"0"(0), "a"(s), "r"(n)
: "memory", "cc");
return res;
}
