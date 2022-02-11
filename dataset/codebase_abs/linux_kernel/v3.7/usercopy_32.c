static inline int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
#ifdef F_2
if ( V_3 >= 64 && ( ( V_1 ^ V_2 ) & V_4 . V_5 ) )
return 0 ;
#endif
return 1 ;
}
unsigned long
F_3 ( void T_1 * V_6 , unsigned long V_3 )
{
F_4 () ;
if ( F_5 ( V_7 , V_6 , V_3 ) )
F_6 ( V_6 , V_3 ) ;
return V_3 ;
}
unsigned long
F_7 ( void T_1 * V_6 , unsigned long V_3 )
{
F_6 ( V_6 , V_3 ) ;
return V_3 ;
}
static unsigned long
F_8 ( void T_1 * V_6 , const void * V_8 , unsigned long V_9 )
{
int V_10 , V_11 ;
__asm__ __volatile__(
" .align 2,0x90\n"
"1: movl 32(%4), %%eax\n"
" cmpl $67, %0\n"
" jbe 3f\n"
"2: movl 64(%4), %%eax\n"
" .align 2,0x90\n"
"3: movl 0(%4), %%eax\n"
"4: movl 4(%4), %%edx\n"
"5: movl %%eax, 0(%3)\n"
"6: movl %%edx, 4(%3)\n"
"7: movl 8(%4), %%eax\n"
"8: movl 12(%4),%%edx\n"
"9: movl %%eax, 8(%3)\n"
"10: movl %%edx, 12(%3)\n"
"11: movl 16(%4), %%eax\n"
"12: movl 20(%4), %%edx\n"
"13: movl %%eax, 16(%3)\n"
"14: movl %%edx, 20(%3)\n"
"15: movl 24(%4), %%eax\n"
"16: movl 28(%4), %%edx\n"
"17: movl %%eax, 24(%3)\n"
"18: movl %%edx, 28(%3)\n"
"19: movl 32(%4), %%eax\n"
"20: movl 36(%4), %%edx\n"
"21: movl %%eax, 32(%3)\n"
"22: movl %%edx, 36(%3)\n"
"23: movl 40(%4), %%eax\n"
"24: movl 44(%4), %%edx\n"
"25: movl %%eax, 40(%3)\n"
"26: movl %%edx, 44(%3)\n"
"27: movl 48(%4), %%eax\n"
"28: movl 52(%4), %%edx\n"
"29: movl %%eax, 48(%3)\n"
"30: movl %%edx, 52(%3)\n"
"31: movl 56(%4), %%eax\n"
"32: movl 60(%4), %%edx\n"
"33: movl %%eax, 56(%3)\n"
"34: movl %%edx, 60(%3)\n"
" addl $-64, %0\n"
" addl $64, %4\n"
" addl $64, %3\n"
" cmpl $63, %0\n"
" ja 1b\n"
"35: movl %0, %%eax\n"
" shrl $2, %0\n"
" andl $3, %%eax\n"
" cld\n"
"99: rep; movsl\n"
"36: movl %%eax, %0\n"
"37: rep; movsb\n"
"100:\n"
".section .fixup,\"ax\"\n"
"101: lea 0(%%eax,%0,4),%0\n"
" jmp 100b\n"
".previous\n"
_ASM_EXTABLE(1b,100b)
_ASM_EXTABLE(2b,100b)
_ASM_EXTABLE(3b,100b)
_ASM_EXTABLE(4b,100b)
_ASM_EXTABLE(5b,100b)
_ASM_EXTABLE(6b,100b)
_ASM_EXTABLE(7b,100b)
_ASM_EXTABLE(8b,100b)
_ASM_EXTABLE(9b,100b)
_ASM_EXTABLE(10b,100b)
_ASM_EXTABLE(11b,100b)
_ASM_EXTABLE(12b,100b)
_ASM_EXTABLE(13b,100b)
_ASM_EXTABLE(14b,100b)
_ASM_EXTABLE(15b,100b)
_ASM_EXTABLE(16b,100b)
_ASM_EXTABLE(17b,100b)
_ASM_EXTABLE(18b,100b)
_ASM_EXTABLE(19b,100b)
_ASM_EXTABLE(20b,100b)
_ASM_EXTABLE(21b,100b)
_ASM_EXTABLE(22b,100b)
_ASM_EXTABLE(23b,100b)
_ASM_EXTABLE(24b,100b)
_ASM_EXTABLE(25b,100b)
_ASM_EXTABLE(26b,100b)
_ASM_EXTABLE(27b,100b)
_ASM_EXTABLE(28b,100b)
_ASM_EXTABLE(29b,100b)
_ASM_EXTABLE(30b,100b)
_ASM_EXTABLE(31b,100b)
_ASM_EXTABLE(32b,100b)
_ASM_EXTABLE(33b,100b)
_ASM_EXTABLE(34b,100b)
_ASM_EXTABLE(35b,100b)
_ASM_EXTABLE(36b,100b)
_ASM_EXTABLE(37b,100b)
_ASM_EXTABLE(99b,101b)
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_9 ;
}
static unsigned long
F_9 ( void * V_6 , const void T_1 * V_8 , unsigned long V_9 )
{
int V_10 , V_11 ;
__asm__ __volatile__(
" .align 2,0x90\n"
"0: movl 32(%4), %%eax\n"
" cmpl $67, %0\n"
" jbe 2f\n"
"1: movl 64(%4), %%eax\n"
" .align 2,0x90\n"
"2: movl 0(%4), %%eax\n"
"21: movl 4(%4), %%edx\n"
" movl %%eax, 0(%3)\n"
" movl %%edx, 4(%3)\n"
"3: movl 8(%4), %%eax\n"
"31: movl 12(%4),%%edx\n"
" movl %%eax, 8(%3)\n"
" movl %%edx, 12(%3)\n"
"4: movl 16(%4), %%eax\n"
"41: movl 20(%4), %%edx\n"
" movl %%eax, 16(%3)\n"
" movl %%edx, 20(%3)\n"
"10: movl 24(%4), %%eax\n"
"51: movl 28(%4), %%edx\n"
" movl %%eax, 24(%3)\n"
" movl %%edx, 28(%3)\n"
"11: movl 32(%4), %%eax\n"
"61: movl 36(%4), %%edx\n"
" movl %%eax, 32(%3)\n"
" movl %%edx, 36(%3)\n"
"12: movl 40(%4), %%eax\n"
"71: movl 44(%4), %%edx\n"
" movl %%eax, 40(%3)\n"
" movl %%edx, 44(%3)\n"
"13: movl 48(%4), %%eax\n"
"81: movl 52(%4), %%edx\n"
" movl %%eax, 48(%3)\n"
" movl %%edx, 52(%3)\n"
"14: movl 56(%4), %%eax\n"
"91: movl 60(%4), %%edx\n"
" movl %%eax, 56(%3)\n"
" movl %%edx, 60(%3)\n"
" addl $-64, %0\n"
" addl $64, %4\n"
" addl $64, %3\n"
" cmpl $63, %0\n"
" ja 0b\n"
"5: movl %0, %%eax\n"
" shrl $2, %0\n"
" andl $3, %%eax\n"
" cld\n"
"6: rep; movsl\n"
" movl %%eax,%0\n"
"7: rep; movsb\n"
"8:\n"
".section .fixup,\"ax\"\n"
"9: lea 0(%%eax,%0,4),%0\n"
"16: pushl %0\n"
" pushl %%eax\n"
" xorl %%eax,%%eax\n"
" rep; stosb\n"
" popl %%eax\n"
" popl %0\n"
" jmp 8b\n"
".previous\n"
_ASM_EXTABLE(0b,16b)
_ASM_EXTABLE(1b,16b)
_ASM_EXTABLE(2b,16b)
_ASM_EXTABLE(21b,16b)
_ASM_EXTABLE(3b,16b)
_ASM_EXTABLE(31b,16b)
_ASM_EXTABLE(4b,16b)
_ASM_EXTABLE(41b,16b)
_ASM_EXTABLE(10b,16b)
_ASM_EXTABLE(51b,16b)
_ASM_EXTABLE(11b,16b)
_ASM_EXTABLE(61b,16b)
_ASM_EXTABLE(12b,16b)
_ASM_EXTABLE(71b,16b)
_ASM_EXTABLE(13b,16b)
_ASM_EXTABLE(81b,16b)
_ASM_EXTABLE(14b,16b)
_ASM_EXTABLE(91b,16b)
_ASM_EXTABLE(6b,9b)
_ASM_EXTABLE(7b,16b)
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_9 ;
}
static unsigned long F_10 ( void * V_6 ,
const void T_1 * V_8 , unsigned long V_9 )
{
int V_10 , V_11 ;
__asm__ __volatile__(
" .align 2,0x90\n"
"0: movl 32(%4), %%eax\n"
" cmpl $67, %0\n"
" jbe 2f\n"
"1: movl 64(%4), %%eax\n"
" .align 2,0x90\n"
"2: movl 0(%4), %%eax\n"
"21: movl 4(%4), %%edx\n"
" movnti %%eax, 0(%3)\n"
" movnti %%edx, 4(%3)\n"
"3: movl 8(%4), %%eax\n"
"31: movl 12(%4),%%edx\n"
" movnti %%eax, 8(%3)\n"
" movnti %%edx, 12(%3)\n"
"4: movl 16(%4), %%eax\n"
"41: movl 20(%4), %%edx\n"
" movnti %%eax, 16(%3)\n"
" movnti %%edx, 20(%3)\n"
"10: movl 24(%4), %%eax\n"
"51: movl 28(%4), %%edx\n"
" movnti %%eax, 24(%3)\n"
" movnti %%edx, 28(%3)\n"
"11: movl 32(%4), %%eax\n"
"61: movl 36(%4), %%edx\n"
" movnti %%eax, 32(%3)\n"
" movnti %%edx, 36(%3)\n"
"12: movl 40(%4), %%eax\n"
"71: movl 44(%4), %%edx\n"
" movnti %%eax, 40(%3)\n"
" movnti %%edx, 44(%3)\n"
"13: movl 48(%4), %%eax\n"
"81: movl 52(%4), %%edx\n"
" movnti %%eax, 48(%3)\n"
" movnti %%edx, 52(%3)\n"
"14: movl 56(%4), %%eax\n"
"91: movl 60(%4), %%edx\n"
" movnti %%eax, 56(%3)\n"
" movnti %%edx, 60(%3)\n"
" addl $-64, %0\n"
" addl $64, %4\n"
" addl $64, %3\n"
" cmpl $63, %0\n"
" ja 0b\n"
" sfence \n"
"5: movl %0, %%eax\n"
" shrl $2, %0\n"
" andl $3, %%eax\n"
" cld\n"
"6: rep; movsl\n"
" movl %%eax,%0\n"
"7: rep; movsb\n"
"8:\n"
".section .fixup,\"ax\"\n"
"9: lea 0(%%eax,%0,4),%0\n"
"16: pushl %0\n"
" pushl %%eax\n"
" xorl %%eax,%%eax\n"
" rep; stosb\n"
" popl %%eax\n"
" popl %0\n"
" jmp 8b\n"
".previous\n"
_ASM_EXTABLE(0b,16b)
_ASM_EXTABLE(1b,16b)
_ASM_EXTABLE(2b,16b)
_ASM_EXTABLE(21b,16b)
_ASM_EXTABLE(3b,16b)
_ASM_EXTABLE(31b,16b)
_ASM_EXTABLE(4b,16b)
_ASM_EXTABLE(41b,16b)
_ASM_EXTABLE(10b,16b)
_ASM_EXTABLE(51b,16b)
_ASM_EXTABLE(11b,16b)
_ASM_EXTABLE(61b,16b)
_ASM_EXTABLE(12b,16b)
_ASM_EXTABLE(71b,16b)
_ASM_EXTABLE(13b,16b)
_ASM_EXTABLE(81b,16b)
_ASM_EXTABLE(14b,16b)
_ASM_EXTABLE(91b,16b)
_ASM_EXTABLE(6b,9b)
_ASM_EXTABLE(7b,16b)
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_9 ;
}
static unsigned long F_11 ( void * V_6 ,
const void T_1 * V_8 , unsigned long V_9 )
{
int V_10 , V_11 ;
__asm__ __volatile__(
" .align 2,0x90\n"
"0: movl 32(%4), %%eax\n"
" cmpl $67, %0\n"
" jbe 2f\n"
"1: movl 64(%4), %%eax\n"
" .align 2,0x90\n"
"2: movl 0(%4), %%eax\n"
"21: movl 4(%4), %%edx\n"
" movnti %%eax, 0(%3)\n"
" movnti %%edx, 4(%3)\n"
"3: movl 8(%4), %%eax\n"
"31: movl 12(%4),%%edx\n"
" movnti %%eax, 8(%3)\n"
" movnti %%edx, 12(%3)\n"
"4: movl 16(%4), %%eax\n"
"41: movl 20(%4), %%edx\n"
" movnti %%eax, 16(%3)\n"
" movnti %%edx, 20(%3)\n"
"10: movl 24(%4), %%eax\n"
"51: movl 28(%4), %%edx\n"
" movnti %%eax, 24(%3)\n"
" movnti %%edx, 28(%3)\n"
"11: movl 32(%4), %%eax\n"
"61: movl 36(%4), %%edx\n"
" movnti %%eax, 32(%3)\n"
" movnti %%edx, 36(%3)\n"
"12: movl 40(%4), %%eax\n"
"71: movl 44(%4), %%edx\n"
" movnti %%eax, 40(%3)\n"
" movnti %%edx, 44(%3)\n"
"13: movl 48(%4), %%eax\n"
"81: movl 52(%4), %%edx\n"
" movnti %%eax, 48(%3)\n"
" movnti %%edx, 52(%3)\n"
"14: movl 56(%4), %%eax\n"
"91: movl 60(%4), %%edx\n"
" movnti %%eax, 56(%3)\n"
" movnti %%edx, 60(%3)\n"
" addl $-64, %0\n"
" addl $64, %4\n"
" addl $64, %3\n"
" cmpl $63, %0\n"
" ja 0b\n"
" sfence \n"
"5: movl %0, %%eax\n"
" shrl $2, %0\n"
" andl $3, %%eax\n"
" cld\n"
"6: rep; movsl\n"
" movl %%eax,%0\n"
"7: rep; movsb\n"
"8:\n"
".section .fixup,\"ax\"\n"
"9: lea 0(%%eax,%0,4),%0\n"
"16: jmp 8b\n"
".previous\n"
_ASM_EXTABLE(0b,16b)
_ASM_EXTABLE(1b,16b)
_ASM_EXTABLE(2b,16b)
_ASM_EXTABLE(21b,16b)
_ASM_EXTABLE(3b,16b)
_ASM_EXTABLE(31b,16b)
_ASM_EXTABLE(4b,16b)
_ASM_EXTABLE(41b,16b)
_ASM_EXTABLE(10b,16b)
_ASM_EXTABLE(51b,16b)
_ASM_EXTABLE(11b,16b)
_ASM_EXTABLE(61b,16b)
_ASM_EXTABLE(12b,16b)
_ASM_EXTABLE(71b,16b)
_ASM_EXTABLE(13b,16b)
_ASM_EXTABLE(81b,16b)
_ASM_EXTABLE(14b,16b)
_ASM_EXTABLE(91b,16b)
_ASM_EXTABLE(6b,9b)
_ASM_EXTABLE(7b,16b)
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_9 ;
}
unsigned long F_12 ( void T_1 * V_6 , const void * V_8 ,
unsigned long V_3 )
{
#ifndef F_13
if ( F_14 ( V_12 . V_13 == 0 ) &&
( ( unsigned long ) V_6 ) < V_14 ) {
if ( F_15 () )
return V_3 ;
while ( V_3 ) {
unsigned long V_15 = ( ( unsigned long ) V_6 ) % V_16 ;
unsigned long V_17 = V_16 - V_15 ;
int V_18 ;
struct V_19 * V_20 ;
void * V_21 ;
if ( V_17 > V_3 )
V_17 = V_3 ;
V_22:
F_16 ( & V_23 -> V_24 -> V_25 ) ;
V_18 = F_17 ( V_23 , V_23 -> V_24 ,
( unsigned long ) V_6 , 1 , 1 , 0 , & V_20 , NULL ) ;
if ( V_18 == - V_26 && F_18 ( V_23 ) ) {
F_19 ( & V_23 -> V_24 -> V_25 ) ;
F_20 ( V_27 , V_28 / 50 ) ;
goto V_22;
}
if ( V_18 != 1 ) {
F_19 ( & V_23 -> V_24 -> V_25 ) ;
break;
}
V_21 = F_21 ( V_20 ) ;
memcpy ( V_21 + V_15 , V_8 , V_17 ) ;
F_22 ( V_21 ) ;
F_23 ( V_20 ) ;
F_24 ( V_20 ) ;
F_19 ( & V_23 -> V_24 -> V_25 ) ;
V_8 += V_17 ;
V_6 += V_17 ;
V_3 -= V_17 ;
}
return V_3 ;
}
#endif
F_25 () ;
if ( F_26 ( V_6 , V_8 , V_3 ) )
F_27 ( V_6 , V_8 , V_3 ) ;
else
V_3 = F_8 ( V_6 , V_8 , V_3 ) ;
F_28 () ;
return V_3 ;
}
unsigned long F_29 ( void * V_6 , const void T_1 * V_8 ,
unsigned long V_3 )
{
F_25 () ;
if ( F_26 ( V_6 , V_8 , V_3 ) )
F_30 ( V_6 , V_8 , V_3 ) ;
else
V_3 = F_9 ( V_6 , V_8 , V_3 ) ;
F_28 () ;
return V_3 ;
}
unsigned long F_31 ( void * V_6 , const void T_1 * V_8 ,
unsigned long V_3 )
{
F_25 () ;
if ( F_26 ( V_6 , V_8 , V_3 ) )
F_27 ( V_6 , V_8 , V_3 ) ;
else
V_3 = F_8 ( ( void T_1 * ) V_6 ,
( const void * ) V_8 , V_3 ) ;
F_28 () ;
return V_3 ;
}
unsigned long F_32 ( void * V_6 , const void T_1 * V_8 ,
unsigned long V_3 )
{
F_25 () ;
#ifdef F_2
if ( V_3 > 64 && V_29 )
V_3 = F_10 ( V_6 , V_8 , V_3 ) ;
else
F_30 ( V_6 , V_8 , V_3 ) ;
#else
F_30 ( V_6 , V_8 , V_3 ) ;
#endif
F_28 () ;
return V_3 ;
}
unsigned long F_33 ( void * V_6 , const void T_1 * V_8 ,
unsigned long V_3 )
{
F_25 () ;
#ifdef F_2
if ( V_3 > 64 && V_29 )
V_3 = F_11 ( V_6 , V_8 , V_3 ) ;
else
F_27 ( V_6 , V_8 , V_3 ) ;
#else
F_27 ( V_6 , V_8 , V_3 ) ;
#endif
F_28 () ;
return V_3 ;
}
unsigned long
F_34 ( void T_1 * V_6 , const void * V_8 , unsigned long V_3 )
{
if ( F_5 ( V_7 , V_6 , V_3 ) )
V_3 = F_35 ( V_6 , V_8 , V_3 ) ;
return V_3 ;
}
unsigned long
F_36 ( void * V_6 , const void T_1 * V_8 , unsigned long V_3 )
{
if ( F_5 ( V_30 , V_8 , V_3 ) )
V_3 = F_37 ( V_6 , V_8 , V_3 ) ;
else
memset ( V_6 , 0 , V_3 ) ;
return V_3 ;
}
void F_38 ( void )
{
F_39 ( 1 , L_1 ) ;
}
