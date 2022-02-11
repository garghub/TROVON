static inline void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 ;
__asm__ __volatile__(
".set\tpush\t\t\t# indy_sc_wipe\n\t"
".set\tnoreorder\n\t"
".set\tmips3\n\t"
".set\tnoat\n\t"
"mfc0\t%2, $12\n\t"
"li\t$1, 0x80\t\t\t# Go 64 bit\n\t"
"mtc0\t$1, $12\n\t"
"dli\t$1, 0x9000000080000000\n\t"
"or\t%0, $1\t\t\t# first line to flush\n\t"
"or\t%1, $1\t\t\t# last line to flush\n\t"
".set\tat\n\t"
"1:\tsw\t$0, 0(%0)\n\t"
"bne\t%0, %1, 1b\n\t"
" daddu\t%0, 32\n\t"
"mtc0\t%2, $12\t\t\t# Back to 32 bit\n\t"
"nop; nop; nop; nop;\n\t"
".set\tpop"
: "=r" (first), "=r" (last), "=&r" (tmp)
: "0" (first), "1" (last));
}
static void F_2 ( unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_6 , V_7 ;
unsigned long V_8 ;
#ifdef F_3
F_4 ( L_1 , V_4 , V_5 ) ;
#endif
F_5 ( V_5 == 0 ) ;
V_6 = F_6 ( V_4 ) ;
V_7 = F_6 ( V_4 + V_5 - 1 ) ;
F_7 ( V_8 ) ;
if ( V_6 <= V_7 ) {
F_1 ( V_6 , V_7 ) ;
goto V_9;
}
F_1 ( V_6 , V_10 - V_11 ) ;
F_1 ( 0 , V_7 ) ;
V_9:
F_8 ( V_8 ) ;
}
static void F_9 ( void )
{
unsigned long V_4 , V_12 , V_13 ;
#ifdef F_3
F_4 ( L_2 ) ;
#endif
__asm__ __volatile__(
".set\tpush\n\t"
".set\tnoreorder\n\t"
".set\tmips3\n\t"
"mfc0\t%2, $12\n\t"
"nop; nop; nop; nop;\n\t"
"li\t%1, 0x80\n\t"
"mtc0\t%1, $12\n\t"
"nop; nop; nop; nop;\n\t"
"li\t%0, 0x1\n\t"
"dsll\t%0, 31\n\t"
"lui\t%1, 0x9000\n\t"
"dsll32\t%1, 0\n\t"
"or\t%0, %1, %0\n\t"
"sb\t$0, 0(%0)\n\t"
"mtc0\t$0, $12\n\t"
"nop; nop; nop; nop;\n\t"
"mtc0\t%2, $12\n\t"
"nop; nop; nop; nop;\n\t"
".set\tpop"
: "=r" (tmp1), "=r" (tmp2), "=r" (addr));
}
static void F_10 ( void )
{
unsigned long V_12 , V_13 , V_14 ;
#ifdef F_3
F_4 ( L_3 ) ;
#endif
__asm__ __volatile__(
".set\tpush\n\t"
".set\tnoreorder\n\t"
".set\tmips3\n\t"
"li\t%0, 0x1\n\t"
"dsll\t%0, 31\n\t"
"lui\t%1, 0x9000\n\t"
"dsll32\t%1, 0\n\t"
"or\t%0, %1, %0\n\t"
"mfc0\t%2, $12\n\t"
"nop; nop; nop; nop\n\t"
"li\t%1, 0x80\n\t"
"mtc0\t%1, $12\n\t"
"nop; nop; nop; nop\n\t"
"sh\t$0, 0(%0)\n\t"
"mtc0\t$0, $12\n\t"
"nop; nop; nop; nop\n\t"
"mtc0\t%2, $12\n\t"
"nop; nop; nop; nop\n\t"
".set\tpop"
: "=r" (tmp1), "=r" (tmp2), "=r" (tmp3));
}
static inline int T_1 F_11 ( void )
{
unsigned int V_5 = F_12 ( & V_15 -> V_16 , 17 ) ;
if ( V_5 == 0 )
return 0 ;
V_5 <<= V_17 ;
F_4 ( V_18 L_4 ,
V_5 >> 10 ) ;
V_19 = V_5 ;
return 1 ;
}
void F_13 ( void )
{
if ( F_11 () ) {
F_9 () ;
V_20 = & V_21 ;
}
}
