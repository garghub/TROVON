unsigned long __clear_user(void __user *addr, unsigned long size)
{
long __d0;
might_fault();
stac();
asm volatile(
" testq %[size8],%[size8]\n"
" jz 4f\n"
"0: movq %[zero],(%[dst])\n"
" addq %[eight],%[dst]\n"
" decl %%ecx ; jnz 0b\n"
"4: movq %[size1],%%rcx\n"
" testl %%ecx,%%ecx\n"
" jz 2f\n"
"1: movb %b[zero],(%[dst])\n"
" incq %[dst]\n"
" decl %%ecx ; jnz 1b\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: lea 0(%[size1],%[size8],8),%[size8]\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(0b,3b)
_ASM_EXTABLE(1b,2b)
: [size8] "=&c"(size), [dst] "=&D" (__d0)
: [size1] "r"(size & 7), "[size8]" (size / 8), "[dst]"(addr),
[zero] "r" (0UL), [eight] "r" (8UL));
clac();
return size;
}
unsigned long clear_user(void __user *to, unsigned long n)
{
if (access_ok(VERIFY_WRITE, to, n))
return __clear_user(to, n);
return n;
}
__visible unsigned long
copy_user_handle_tail(char *to, char *from, unsigned len)
{
for (; len; --len, to++) {
char c;
if (__get_user_nocheck(c, from++, sizeof(char)))
break;
if (__put_user_nocheck(c, to, sizeof(char)))
break;
}
clac();
return len;
}
