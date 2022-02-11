static inline void F_1 ( int V_1 )
{
unsigned long V_2 ;
asm volatile(
#ifdef F_2
"ldc %2, r6_bank\n\t"
#endif
"stc sr, %0\n\t"
"and #0xf0, %0\n\t"
"shlr2 %0\n\t"
"cmp/eq #0x3c, %0\n\t"
"bt/s 1f ! CLI-ed\n\t"
" stc sr, %0\n\t"
"and %1, %0\n\t"
"or %2, %0\n\t"
"ldc %0, sr\n"
"1:"
: "=&z" (__dummy)
: "r" (~0xf0), "r" (ip << 4)
: "t");
}
static void F_3 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
F_4 ( V_5 , V_6 ) ;
if ( V_7 < V_8 - V_5 )
V_7 = V_8 - V_5 ;
F_1 ( V_7 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
F_6 ( V_5 , V_6 ) ;
V_7 = V_8 -
F_7 ( V_6 , V_8 ) ;
F_1 ( V_7 ) ;
}
void F_8 ( unsigned int V_5 )
{
F_9 ( V_5 , & V_9 , V_10 ,
L_1 ) ;
}
