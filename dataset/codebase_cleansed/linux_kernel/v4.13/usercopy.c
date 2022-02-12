unsigned long raw_copy_to_user(void __user *pdst, const void *psrc,
unsigned long n)
{
register char __user *dst asm ("A0.2") = pdst;
register const char *src asm ("A1.2") = psrc;
unsigned long retn = 0;
if (n == 0)
return 0;
if ((unsigned long) src & 1) {
__asm_copy_to_user_1(dst, src, retn);
n--;
if (retn)
return retn + n;
}
if ((unsigned long) dst & 1) {
while (n > 0) {
__asm_copy_to_user_1(dst, src, retn);
n--;
if (retn)
return retn + n;
}
}
if (((unsigned long) src & 2) && n >= 2) {
__asm_copy_to_user_2(dst, src, retn);
n -= 2;
if (retn)
return retn + n;
}
if ((unsigned long) dst & 2) {
while (n >= 2) {
__asm_copy_to_user_2(dst, src, retn);
n -= 2;
if (retn)
return retn + n;
}
}
#ifdef USE_RAPF
if (!(((unsigned long) src | (__force unsigned long) dst) & 7)) {
if (n >= RAPF_MIN_BUF_SIZE) {
__asm_copy_to_user_64bit_rapf_loop(dst, src, retn,
n, "64cu");
}
while (n >= 8) {
__asm_copy_to_user_8x64(dst, src, retn);
n -= 8;
if (retn)
return retn + n;
}
}
if (n >= RAPF_MIN_BUF_SIZE) {
__asm_copy_to_user_32bit_rapf_loop(dst, src, retn, n, "32cu");
}
#else
if (!(((unsigned long) src | (__force unsigned long) dst) & 7)) {
while (n >= 8) {
__asm_copy_to_user_8x64(dst, src, retn);
n -= 8;
if (retn)
return retn + n;
}
}
#endif
while (n >= 16) {
__asm_copy_to_user_16(dst, src, retn);
n -= 16;
if (retn)
return retn + n;
}
while (n >= 4) {
__asm_copy_to_user_4(dst, src, retn);
n -= 4;
if (retn)
return retn + n;
}
switch (n) {
case 0:
break;
case 1:
__asm_copy_to_user_1(dst, src, retn);
break;
case 2:
__asm_copy_to_user_2(dst, src, retn);
break;
case 3:
__asm_copy_to_user_3(dst, src, retn);
break;
}
return retn;
}
unsigned long raw_copy_from_user(void *pdst, const void __user *psrc,
unsigned long n)
{
register char *dst asm ("A0.2") = pdst;
register const char __user *src asm ("A1.2") = psrc;
unsigned long retn = 0;
if (n == 0)
return 0;
if ((unsigned long) src & 1) {
__asm_copy_from_user_1(dst, src, retn);
n--;
if (retn)
return retn + n;
}
if ((unsigned long) dst & 1) {
while (n > 0) {
__asm_copy_from_user_1(dst, src, retn);
n--;
if (retn)
return retn + n;
}
}
if (((unsigned long) src & 2) && n >= 2) {
__asm_copy_from_user_2(dst, src, retn);
n -= 2;
if (retn)
return retn + n;
}
if ((unsigned long) dst & 2) {
while (n >= 2) {
__asm_copy_from_user_2(dst, src, retn);
n -= 2;
if (retn)
return retn + n;
}
}
#ifdef USE_RAPF
if (!(((unsigned long) src | (unsigned long) dst) & 7)) {
if (n >= RAPF_MIN_BUF_SIZE) {
__asm_copy_from_user_64bit_rapf_loop(dst, src, retn,
n, "64cuz");
}
while (n >= 8) {
__asm_copy_from_user_8x64(dst, src, retn);
n -= 8;
if (retn)
return retn + n;
}
}
if (n >= RAPF_MIN_BUF_SIZE) {
__asm_copy_from_user_32bit_rapf_loop(dst, src, retn,
n, "32cuz");
}
#else
if (!(((unsigned long) src | (unsigned long) dst) & 7)) {
while (n >= 8) {
__asm_copy_from_user_8x64(dst, src, retn);
n -= 8;
if (retn)
return retn + n;
}
}
#endif
while (n >= 4) {
__asm_copy_from_user_4(dst, src, retn);
n -= 4;
if (retn)
return retn + n;
}
switch (n) {
case 0:
break;
case 1:
__asm_copy_from_user_1(dst, src, retn);
break;
case 2:
__asm_copy_from_user_2(dst, src, retn);
break;
case 3:
__asm_copy_from_user_3(dst, src, retn);
break;
}
return retn;
}
unsigned long __do_clear_user(void __user *pto, unsigned long pn)
{
register char __user *dst asm ("D0Re0") = pto;
register unsigned long n asm ("D1Re0") = pn;
register unsigned long retn asm ("D0Ar6") = 0;
if ((unsigned long) dst & 1) {
__asm_clear_1(dst, retn);
n--;
}
if ((unsigned long) dst & 2) {
__asm_clear_2(dst, retn);
n -= 2;
}
if (!((__force unsigned long) dst & 7)) {
while (n >= 8) {
__asm_clear_8x64(dst, retn);
n -= 8;
}
}
while (n >= 16) {
__asm_clear_16(dst, retn);
n -= 16;
}
while (n >= 4) {
__asm_clear_4(dst, retn);
n -= 4;
}
switch (n) {
case 0:
break;
case 1:
__asm_clear_1(dst, retn);
break;
case 2:
__asm_clear_2(dst, retn);
break;
case 3:
__asm_clear_3(dst, retn);
break;
}
return retn;
}
unsigned char __get_user_asm_b(const void __user *addr, long *err)
{
register unsigned char x asm ("D0Re0") = 0;
asm volatile (
" GETB %0,[%2]\n"
"1:\n"
" GETB %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return x;
}
unsigned short __get_user_asm_w(const void __user *addr, long *err)
{
register unsigned short x asm ("D0Re0") = 0;
asm volatile (
" GETW %0,[%2]\n"
"1:\n"
" GETW %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return x;
}
unsigned int __get_user_asm_d(const void __user *addr, long *err)
{
register unsigned int x asm ("D0Re0") = 0;
asm volatile (
" GETD %0,[%2]\n"
"1:\n"
" GETD %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return x;
}
unsigned long long __get_user_asm_l(const void __user *addr, long *err)
{
register unsigned long long x asm ("D0Re0") = 0;
asm volatile (
" GETL %0,%t0,[%2]\n"
"1:\n"
" GETL %0,%t0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return x;
}
long __put_user_asm_b(unsigned int x, void __user *addr)
{
register unsigned int err asm ("D0Re0") = 0;
asm volatile (
" MOV %0,#0\n"
" SETB [%2],%1\n"
"1:\n"
" SETB [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return err;
}
long __put_user_asm_w(unsigned int x, void __user *addr)
{
register unsigned int err asm ("D0Re0") = 0;
asm volatile (
" MOV %0,#0\n"
" SETW [%2],%1\n"
"1:\n"
" SETW [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return err;
}
long __put_user_asm_d(unsigned int x, void __user *addr)
{
register unsigned int err asm ("D0Re0") = 0;
asm volatile (
" MOV %0,#0\n"
" SETD [%2],%1\n"
"1:\n"
" SETD [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return err;
}
long __put_user_asm_l(unsigned long long x, void __user *addr)
{
register unsigned int err asm ("D0Re0") = 0;
asm volatile (
" MOV %0,#0\n"
" SETL [%2],%1,%t1\n"
"1:\n"
" SETL [%2],%1,%t1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return err;
}
long strnlen_user(const char __user *src, long count)
{
long res;
if (!access_ok(VERIFY_READ, src, 0))
return 0;
asm volatile (" MOV D0Ar4, %1\n"
" MOV D0Ar6, %2\n"
"0:\n"
" SUBS D0FrT, D0Ar6, #0\n"
" SUB D0Ar6, D0Ar6, #1\n"
" BLE 2f\n"
" GETB D0FrT, [D0Ar4+#1++]\n"
"1:\n"
" TST D0FrT, #255\n"
" BNE 0b\n"
"2:\n"
" SUB %0, %2, D0Ar6\n"
"3:\n"
" .section .fixup,\"ax\"\n"
"4:\n"
" MOV %0, #0\n"
" MOVT D0FrT,#HI(3b)\n"
" JUMP D0FrT,#LO(3b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,4b\n"
" .previous\n"
: "=r" (res)
: "r" (src), "r" (count)
: "D0FrT", "D0Ar4", "D0Ar6", "cc");
return res;
}
long __strncpy_from_user(char *dst, const char __user *src, long count)
{
long res;
if (count == 0)
return 0;
asm volatile (" MOV %0,%3\n"
"1:\n"
" GETB D0FrT,[%2++]\n"
"2:\n"
" CMP D0FrT,#0\n"
" SETB [%1++],D0FrT\n"
" BEQ 3f\n"
" SUBS %0,%0,#1\n"
" BNZ 1b\n"
"3:\n"
" SUB %0,%3,%0\n"
"4:\n"
" .section .fixup,\"ax\"\n"
"5:\n"
" MOV %0,%7\n"
" MOVT D0FrT,#HI(4b)\n"
" JUMP D0FrT,#LO(4b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 2b,5b\n"
" .previous"
: "=r" (res), "=r" (dst), "=r" (src), "=r" (count)
: "3" (count), "1" (dst), "2" (src), "P" (-EFAULT)
: "D0FrT", "memory", "cc");
return res;
}
