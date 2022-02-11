void * F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
void * V_4 ;
int V_5 ;
if ( F_2 ( F_3 () ) )
return F_4 ( V_1 , V_2 , V_3 ) ;
V_4 = V_1 ;
V_5 = V_3 >> 6 ;
F_5 () ;
__asm__ __volatile__ (
"1: prefetch (%0)\n"
" prefetch 64(%0)\n"
" prefetch 128(%0)\n"
" prefetch 192(%0)\n"
" prefetch 256(%0)\n"
"2: \n"
".section .fixup, \"ax\"\n"
"3: movw $0x1AEB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b)
: : "r" (from));
for ( ; V_5 > 5 ; V_5 -- ) {
__asm__ __volatile__ (
"1: prefetch 320(%0)\n"
"2: movq (%0), %%mm0\n"
" movq 8(%0), %%mm1\n"
" movq 16(%0), %%mm2\n"
" movq 24(%0), %%mm3\n"
" movq %%mm0, (%1)\n"
" movq %%mm1, 8(%1)\n"
" movq %%mm2, 16(%1)\n"
" movq %%mm3, 24(%1)\n"
" movq 32(%0), %%mm0\n"
" movq 40(%0), %%mm1\n"
" movq 48(%0), %%mm2\n"
" movq 56(%0), %%mm3\n"
" movq %%mm0, 32(%1)\n"
" movq %%mm1, 40(%1)\n"
" movq %%mm2, 48(%1)\n"
" movq %%mm3, 56(%1)\n"
".section .fixup, \"ax\"\n"
"3: movw $0x05EB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b)
: : "r" (from), "r" (to) : "memory");
V_2 += 64 ;
V_1 += 64 ;
}
for ( ; V_5 > 0 ; V_5 -- ) {
__asm__ __volatile__ (
" movq (%0), %%mm0\n"
" movq 8(%0), %%mm1\n"
" movq 16(%0), %%mm2\n"
" movq 24(%0), %%mm3\n"
" movq %%mm0, (%1)\n"
" movq %%mm1, 8(%1)\n"
" movq %%mm2, 16(%1)\n"
" movq %%mm3, 24(%1)\n"
" movq 32(%0), %%mm0\n"
" movq 40(%0), %%mm1\n"
" movq 48(%0), %%mm2\n"
" movq 56(%0), %%mm3\n"
" movq %%mm0, 32(%1)\n"
" movq %%mm1, 40(%1)\n"
" movq %%mm2, 48(%1)\n"
" movq %%mm3, 56(%1)\n"
: : "r" (from), "r" (to) : "memory");
V_2 += 64 ;
V_1 += 64 ;
}
F_4 ( V_1 , V_2 , V_3 & 63 ) ;
F_6 () ;
return V_4 ;
}
static void F_7 ( void * V_6 )
{
int V_5 ;
F_5 () ;
__asm__ __volatile__ (
" pxor %%mm0, %%mm0\n" : :
);
for ( V_5 = 0 ; V_5 < 4096 / 64 ; V_5 ++ ) {
__asm__ __volatile__ (
" movntq %%mm0, (%0)\n"
" movntq %%mm0, 8(%0)\n"
" movntq %%mm0, 16(%0)\n"
" movntq %%mm0, 24(%0)\n"
" movntq %%mm0, 32(%0)\n"
" movntq %%mm0, 40(%0)\n"
" movntq %%mm0, 48(%0)\n"
" movntq %%mm0, 56(%0)\n"
: : "r" (page) : "memory");
V_6 += 64 ;
}
__asm__ __volatile__("sfence\n"::);
F_6 () ;
}
static void F_8 ( void * V_1 , void * V_2 )
{
int V_5 ;
F_5 () ;
__asm__ __volatile__(
"1: prefetch (%0)\n"
" prefetch 64(%0)\n"
" prefetch 128(%0)\n"
" prefetch 192(%0)\n"
" prefetch 256(%0)\n"
"2: \n"
".section .fixup, \"ax\"\n"
"3: movw $0x1AEB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b) : : "r" (from));
for ( V_5 = 0 ; V_5 < ( 4096 - 320 ) / 64 ; V_5 ++ ) {
__asm__ __volatile__ (
"1: prefetch 320(%0)\n"
"2: movq (%0), %%mm0\n"
" movntq %%mm0, (%1)\n"
" movq 8(%0), %%mm1\n"
" movntq %%mm1, 8(%1)\n"
" movq 16(%0), %%mm2\n"
" movntq %%mm2, 16(%1)\n"
" movq 24(%0), %%mm3\n"
" movntq %%mm3, 24(%1)\n"
" movq 32(%0), %%mm4\n"
" movntq %%mm4, 32(%1)\n"
" movq 40(%0), %%mm5\n"
" movntq %%mm5, 40(%1)\n"
" movq 48(%0), %%mm6\n"
" movntq %%mm6, 48(%1)\n"
" movq 56(%0), %%mm7\n"
" movntq %%mm7, 56(%1)\n"
".section .fixup, \"ax\"\n"
"3: movw $0x05EB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b) : : "r" (from), "r" (to) : "memory");
V_2 += 64 ;
V_1 += 64 ;
}
for ( V_5 = ( 4096 - 320 ) / 64 ; V_5 < 4096 / 64 ; V_5 ++ ) {
__asm__ __volatile__ (
"2: movq (%0), %%mm0\n"
" movntq %%mm0, (%1)\n"
" movq 8(%0), %%mm1\n"
" movntq %%mm1, 8(%1)\n"
" movq 16(%0), %%mm2\n"
" movntq %%mm2, 16(%1)\n"
" movq 24(%0), %%mm3\n"
" movntq %%mm3, 24(%1)\n"
" movq 32(%0), %%mm4\n"
" movntq %%mm4, 32(%1)\n"
" movq 40(%0), %%mm5\n"
" movntq %%mm5, 40(%1)\n"
" movq 48(%0), %%mm6\n"
" movntq %%mm6, 48(%1)\n"
" movq 56(%0), %%mm7\n"
" movntq %%mm7, 56(%1)\n"
: : "r" (from), "r" (to) : "memory");
V_2 += 64 ;
V_1 += 64 ;
}
__asm__ __volatile__("sfence \n"::);
F_6 () ;
}
static void F_7 ( void * V_6 )
{
int V_5 ;
F_5 () ;
__asm__ __volatile__ (
" pxor %%mm0, %%mm0\n" : :
);
for ( V_5 = 0 ; V_5 < 4096 / 128 ; V_5 ++ ) {
__asm__ __volatile__ (
" movq %%mm0, (%0)\n"
" movq %%mm0, 8(%0)\n"
" movq %%mm0, 16(%0)\n"
" movq %%mm0, 24(%0)\n"
" movq %%mm0, 32(%0)\n"
" movq %%mm0, 40(%0)\n"
" movq %%mm0, 48(%0)\n"
" movq %%mm0, 56(%0)\n"
" movq %%mm0, 64(%0)\n"
" movq %%mm0, 72(%0)\n"
" movq %%mm0, 80(%0)\n"
" movq %%mm0, 88(%0)\n"
" movq %%mm0, 96(%0)\n"
" movq %%mm0, 104(%0)\n"
" movq %%mm0, 112(%0)\n"
" movq %%mm0, 120(%0)\n"
: : "r" (page) : "memory");
V_6 += 128 ;
}
F_6 () ;
}
static void F_8 ( void * V_1 , void * V_2 )
{
int V_5 ;
F_5 () ;
__asm__ __volatile__ (
"1: prefetch (%0)\n"
" prefetch 64(%0)\n"
" prefetch 128(%0)\n"
" prefetch 192(%0)\n"
" prefetch 256(%0)\n"
"2: \n"
".section .fixup, \"ax\"\n"
"3: movw $0x1AEB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b) : : "r" (from));
for ( V_5 = 0 ; V_5 < 4096 / 64 ; V_5 ++ ) {
__asm__ __volatile__ (
"1: prefetch 320(%0)\n"
"2: movq (%0), %%mm0\n"
" movq 8(%0), %%mm1\n"
" movq 16(%0), %%mm2\n"
" movq 24(%0), %%mm3\n"
" movq %%mm0, (%1)\n"
" movq %%mm1, 8(%1)\n"
" movq %%mm2, 16(%1)\n"
" movq %%mm3, 24(%1)\n"
" movq 32(%0), %%mm0\n"
" movq 40(%0), %%mm1\n"
" movq 48(%0), %%mm2\n"
" movq 56(%0), %%mm3\n"
" movq %%mm0, 32(%1)\n"
" movq %%mm1, 40(%1)\n"
" movq %%mm2, 48(%1)\n"
" movq %%mm3, 56(%1)\n"
".section .fixup, \"ax\"\n"
"3: movw $0x05EB, 1b\n"
" jmp 2b\n"
".previous\n"
_ASM_EXTABLE(1b, 3b)
: : "r" (from), "r" (to) : "memory");
V_2 += 64 ;
V_1 += 64 ;
}
F_6 () ;
}
static void F_9 ( void * V_6 )
{
int V_7 , V_8 ;
__asm__ __volatile__(
"cld\n\t"
"rep ; stosl"
: "=&c" (d0), "=&D" (d1)
:"a" (0), "1" (page), "0" (1024)
:"memory");
}
void F_10 ( void * V_6 )
{
if ( F_2 ( F_3 () ) )
F_9 ( V_6 ) ;
else
F_7 ( V_6 ) ;
}
static void F_11 ( void * V_1 , void * V_2 )
{
int V_7 , V_8 , V_9 ;
__asm__ __volatile__(
"cld\n\t"
"rep ; movsl"
: "=&c" (d0), "=&D" (d1), "=&S" (d2)
: "0" (1024), "1" ((long) to), "2" ((long) from)
: "memory");
}
void F_12 ( void * V_1 , void * V_2 )
{
if ( F_2 ( F_3 () ) )
F_11 ( V_1 , V_2 ) ;
else
F_8 ( V_1 , V_2 ) ;
}
