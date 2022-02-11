static inline int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
#ifdef F_2
if ( V_3 >= 64 && ( ( V_1 ^ V_2 ) & V_4 . V_5 ) )
return 0 ;
#endif
return 1 ;
}
long
F_3 ( char * V_6 , const char T_1 * V_7 , long V_8 )
{
long V_9 ;
F_4 ( V_6 , V_7 , V_8 , V_9 ) ;
return V_9 ;
}
long
F_5 ( char * V_6 , const char T_1 * V_7 , long V_8 )
{
long V_9 = - V_10 ;
if ( F_6 ( V_11 , V_7 , 1 ) )
F_4 ( V_6 , V_7 , V_8 , V_9 ) ;
return V_9 ;
}
unsigned long
F_7 ( void T_1 * V_12 , unsigned long V_3 )
{
F_8 () ;
if ( F_6 ( V_13 , V_12 , V_3 ) )
F_9 ( V_12 , V_3 ) ;
return V_3 ;
}
unsigned long
F_10 ( void T_1 * V_12 , unsigned long V_3 )
{
F_9 ( V_12 , V_3 ) ;
return V_3 ;
}
long F_11 ( const char T_1 * V_14 , long V_3 )
{
unsigned long V_5 = - F_12 ( V_14 ) ;
unsigned long V_9 , V_15 ;
F_8 () ;
__asm__ __volatile__(
" testl %0, %0\n"
" jz 3f\n"
" andl %0,%%ecx\n"
"0: repne; scasb\n"
" setne %%al\n"
" subl %%ecx,%0\n"
" addl %0,%%eax\n"
"1:\n"
".section .fixup,\"ax\"\n"
"2: xorl %%eax,%%eax\n"
" jmp 1b\n"
"3: movb $1,%%al\n"
" jmp 1b\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .align 4\n"
" .long 0b,2b\n"
".previous"
:"=&r" (n), "=&D" (s), "=&a" (res), "=&c" (tmp)
:"0" (n), "1" (s), "2" (0), "3" (mask)
:"cc");
return V_9 & V_5 ;
}
static unsigned long
F_13 ( void T_1 * V_12 , const void * V_16 , unsigned long V_17 )
{
int V_18 , V_19 ;
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
".section __ex_table,\"a\"\n"
" .align 4\n"
" .long 1b,100b\n"
" .long 2b,100b\n"
" .long 3b,100b\n"
" .long 4b,100b\n"
" .long 5b,100b\n"
" .long 6b,100b\n"
" .long 7b,100b\n"
" .long 8b,100b\n"
" .long 9b,100b\n"
" .long 10b,100b\n"
" .long 11b,100b\n"
" .long 12b,100b\n"
" .long 13b,100b\n"
" .long 14b,100b\n"
" .long 15b,100b\n"
" .long 16b,100b\n"
" .long 17b,100b\n"
" .long 18b,100b\n"
" .long 19b,100b\n"
" .long 20b,100b\n"
" .long 21b,100b\n"
" .long 22b,100b\n"
" .long 23b,100b\n"
" .long 24b,100b\n"
" .long 25b,100b\n"
" .long 26b,100b\n"
" .long 27b,100b\n"
" .long 28b,100b\n"
" .long 29b,100b\n"
" .long 30b,100b\n"
" .long 31b,100b\n"
" .long 32b,100b\n"
" .long 33b,100b\n"
" .long 34b,100b\n"
" .long 35b,100b\n"
" .long 36b,100b\n"
" .long 37b,100b\n"
" .long 99b,101b\n"
".previous"
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_17 ;
}
static unsigned long
F_14 ( void * V_12 , const void T_1 * V_16 , unsigned long V_17 )
{
int V_18 , V_19 ;
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
".section __ex_table,\"a\"\n"
" .align 4\n"
" .long 0b,16b\n"
" .long 1b,16b\n"
" .long 2b,16b\n"
" .long 21b,16b\n"
" .long 3b,16b\n"
" .long 31b,16b\n"
" .long 4b,16b\n"
" .long 41b,16b\n"
" .long 10b,16b\n"
" .long 51b,16b\n"
" .long 11b,16b\n"
" .long 61b,16b\n"
" .long 12b,16b\n"
" .long 71b,16b\n"
" .long 13b,16b\n"
" .long 81b,16b\n"
" .long 14b,16b\n"
" .long 91b,16b\n"
" .long 6b,9b\n"
" .long 7b,16b\n"
".previous"
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_17 ;
}
static unsigned long F_15 ( void * V_12 ,
const void T_1 * V_16 , unsigned long V_17 )
{
int V_18 , V_19 ;
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
".section __ex_table,\"a\"\n"
" .align 4\n"
" .long 0b,16b\n"
" .long 1b,16b\n"
" .long 2b,16b\n"
" .long 21b,16b\n"
" .long 3b,16b\n"
" .long 31b,16b\n"
" .long 4b,16b\n"
" .long 41b,16b\n"
" .long 10b,16b\n"
" .long 51b,16b\n"
" .long 11b,16b\n"
" .long 61b,16b\n"
" .long 12b,16b\n"
" .long 71b,16b\n"
" .long 13b,16b\n"
" .long 81b,16b\n"
" .long 14b,16b\n"
" .long 91b,16b\n"
" .long 6b,9b\n"
" .long 7b,16b\n"
".previous"
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_17 ;
}
static unsigned long F_16 ( void * V_12 ,
const void T_1 * V_16 , unsigned long V_17 )
{
int V_18 , V_19 ;
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
".section __ex_table,\"a\"\n"
" .align 4\n"
" .long 0b,16b\n"
" .long 1b,16b\n"
" .long 2b,16b\n"
" .long 21b,16b\n"
" .long 3b,16b\n"
" .long 31b,16b\n"
" .long 4b,16b\n"
" .long 41b,16b\n"
" .long 10b,16b\n"
" .long 51b,16b\n"
" .long 11b,16b\n"
" .long 61b,16b\n"
" .long 12b,16b\n"
" .long 71b,16b\n"
" .long 13b,16b\n"
" .long 81b,16b\n"
" .long 14b,16b\n"
" .long 91b,16b\n"
" .long 6b,9b\n"
" .long 7b,16b\n"
".previous"
: "=&c"(size), "=&D" (d0), "=&S" (d1)
: "1"(to), "2"(from), "0"(size)
: "eax", "edx", "memory");
return V_17 ;
}
unsigned long F_17 ( void T_1 * V_12 , const void * V_16 ,
unsigned long V_3 )
{
#ifndef F_18
if ( F_19 ( V_20 . V_21 == 0 ) &&
( ( unsigned long ) V_12 ) < V_22 ) {
if ( F_20 () )
return V_3 ;
while ( V_3 ) {
unsigned long V_23 = ( ( unsigned long ) V_12 ) % V_24 ;
unsigned long V_25 = V_24 - V_23 ;
int V_26 ;
struct V_27 * V_28 ;
void * V_29 ;
if ( V_25 > V_3 )
V_25 = V_3 ;
V_30:
F_21 ( & V_31 -> V_32 -> V_33 ) ;
V_26 = F_22 ( V_31 , V_31 -> V_32 ,
( unsigned long ) V_12 , 1 , 1 , 0 , & V_28 , NULL ) ;
if ( V_26 == - V_34 && F_23 ( V_31 ) ) {
F_24 ( & V_31 -> V_32 -> V_33 ) ;
F_25 ( V_35 , V_36 / 50 ) ;
goto V_30;
}
if ( V_26 != 1 ) {
F_24 ( & V_31 -> V_32 -> V_33 ) ;
break;
}
V_29 = F_26 ( V_28 , V_37 ) ;
memcpy ( V_29 + V_23 , V_16 , V_25 ) ;
F_27 ( V_29 , V_37 ) ;
F_28 ( V_28 ) ;
F_29 ( V_28 ) ;
F_24 ( & V_31 -> V_32 -> V_33 ) ;
V_16 += V_25 ;
V_12 += V_25 ;
V_3 -= V_25 ;
}
return V_3 ;
}
#endif
if ( F_30 ( V_12 , V_16 , V_3 ) )
F_31 ( V_12 , V_16 , V_3 ) ;
else
V_3 = F_13 ( V_12 , V_16 , V_3 ) ;
return V_3 ;
}
unsigned long F_32 ( void * V_12 , const void T_1 * V_16 ,
unsigned long V_3 )
{
if ( F_30 ( V_12 , V_16 , V_3 ) )
F_33 ( V_12 , V_16 , V_3 ) ;
else
V_3 = F_14 ( V_12 , V_16 , V_3 ) ;
return V_3 ;
}
unsigned long F_34 ( void * V_12 , const void T_1 * V_16 ,
unsigned long V_3 )
{
if ( F_30 ( V_12 , V_16 , V_3 ) )
F_31 ( V_12 , V_16 , V_3 ) ;
else
V_3 = F_13 ( ( void T_1 * ) V_12 ,
( const void * ) V_16 , V_3 ) ;
return V_3 ;
}
unsigned long F_35 ( void * V_12 , const void T_1 * V_16 ,
unsigned long V_3 )
{
#ifdef F_2
if ( V_3 > 64 && V_38 )
V_3 = F_15 ( V_12 , V_16 , V_3 ) ;
else
F_33 ( V_12 , V_16 , V_3 ) ;
#else
F_33 ( V_12 , V_16 , V_3 ) ;
#endif
return V_3 ;
}
unsigned long F_36 ( void * V_12 , const void T_1 * V_16 ,
unsigned long V_3 )
{
#ifdef F_2
if ( V_3 > 64 && V_38 )
V_3 = F_16 ( V_12 , V_16 , V_3 ) ;
else
F_31 ( V_12 , V_16 , V_3 ) ;
#else
F_31 ( V_12 , V_16 , V_3 ) ;
#endif
return V_3 ;
}
unsigned long
F_37 ( void T_1 * V_12 , const void * V_16 , unsigned long V_3 )
{
if ( F_6 ( V_13 , V_12 , V_3 ) )
V_3 = F_38 ( V_12 , V_16 , V_3 ) ;
return V_3 ;
}
unsigned long
F_39 ( void * V_12 , const void T_1 * V_16 , unsigned long V_3 )
{
if ( F_6 ( V_11 , V_16 , V_3 ) )
V_3 = F_40 ( V_12 , V_16 , V_3 ) ;
else
memset ( V_12 , 0 , V_3 ) ;
return V_3 ;
}
void F_41 ( void )
{
F_42 ( 1 , L_1 ) ;
}
