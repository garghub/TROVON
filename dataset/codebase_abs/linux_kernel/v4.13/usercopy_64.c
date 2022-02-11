unsigned long F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
long V_3 ;
F_2 () ;
F_3 () ;
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
F_4 () ;
return V_2 ;
}
unsigned long F_5 ( void T_1 * V_4 , unsigned long V_5 )
{
if ( F_6 ( V_6 , V_4 , V_5 ) )
return F_1 ( V_4 , V_5 ) ;
return V_5 ;
}
T_2 unsigned long
F_7 ( char * V_4 , char * V_7 , unsigned V_8 )
{
for (; V_8 ; -- V_8 , V_4 ++ ) {
char V_9 ;
if ( F_8 ( V_9 , V_7 ++ , sizeof( char ) ) )
break;
if ( F_9 ( V_9 , V_4 , sizeof( char ) ) )
break;
}
F_4 () ;
return V_8 ;
}
static void F_10 ( void * V_1 , T_3 V_2 )
{
T_4 V_10 = V_11 . V_10 ;
unsigned long V_12 = V_10 - 1 ;
void * V_13 = V_1 + V_2 ;
void * V_14 ;
for ( V_14 = ( void * ) ( ( unsigned long ) V_1 & ~ V_12 ) ;
V_14 < V_13 ; V_14 += V_10 )
F_11 ( V_14 ) ;
}
void F_12 ( void * V_1 , T_3 V_2 )
{
F_10 ( V_1 , V_2 ) ;
}
long F_13 ( void * V_15 , const void T_1 * V_16 , unsigned V_2 )
{
unsigned long V_17 , V_18 = ( unsigned long ) V_15 ;
long V_19 = F_14 ( V_15 , V_16 , V_2 , 0 ) ;
if ( V_2 < 8 ) {
if ( ! F_15 ( V_18 , 4 ) || V_2 != 4 )
F_10 ( V_15 , 1 ) ;
} else {
if ( ! F_15 ( V_18 , 8 ) ) {
V_18 = F_16 ( V_18 , V_11 . V_10 ) ;
F_10 ( V_15 , 1 ) ;
}
V_17 = V_18 - ( unsigned long ) V_15 ;
if ( V_2 > V_17 && ! F_15 ( V_2 - V_17 , 8 ) )
F_10 ( V_15 + V_2 - 1 , 1 ) ;
}
return V_19 ;
}
void F_17 ( void * V_20 , const void * V_21 , T_3 V_2 )
{
unsigned long V_18 = ( unsigned long ) V_20 ;
unsigned long V_22 = ( unsigned long ) V_21 ;
if ( ! F_15 ( V_18 , 8 ) ) {
unsigned V_8 = F_18 ( unsigned , V_2 , F_16 ( V_18 , 8 ) - V_18 ) ;
memcpy ( ( void * ) V_18 , ( void * ) V_22 , V_8 ) ;
F_10 ( ( void * ) V_18 , V_8 ) ;
V_18 += V_8 ;
V_22 += V_8 ;
V_2 -= V_8 ;
if ( ! V_2 )
return;
}
while ( V_2 >= 32 ) {
asm("movq (%0), %%r8\n"
"movq 8(%0), %%r9\n"
"movq 16(%0), %%r10\n"
"movq 24(%0), %%r11\n"
"movnti %%r8, (%1)\n"
"movnti %%r9, 8(%1)\n"
"movnti %%r10, 16(%1)\n"
"movnti %%r11, 24(%1)\n"
:: "r" (source), "r" (dest)
: "memory", "r8", "r9", "r10", "r11");
V_18 += 32 ;
V_22 += 32 ;
V_2 -= 32 ;
}
while ( V_2 >= 8 ) {
asm("movq (%0), %%r8\n"
"movnti %%r8, (%1)\n"
:: "r" (source), "r" (dest)
: "memory", "r8");
V_18 += 8 ;
V_22 += 8 ;
V_2 -= 8 ;
}
while ( V_2 >= 4 ) {
asm("movl (%0), %%r8d\n"
"movnti %%r8d, (%1)\n"
:: "r" (source), "r" (dest)
: "memory", "r8");
V_18 += 4 ;
V_22 += 4 ;
V_2 -= 4 ;
}
if ( V_2 ) {
memcpy ( ( void * ) V_18 , ( void * ) V_22 , V_2 ) ;
F_10 ( ( void * ) V_18 , V_2 ) ;
}
}
void F_19 ( char * V_4 , struct V_23 * V_23 , T_3 V_24 ,
T_3 V_8 )
{
char * V_7 = F_20 ( V_23 ) ;
F_17 ( V_4 , V_7 + V_24 , V_8 ) ;
F_21 ( V_7 ) ;
}
