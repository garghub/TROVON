static void F_1 ( void * V_1 , const void * V_2 , unsigned long V_3 )
{
F_2 () ;
V_3 >>= 4 ;
while ( V_3 >= 4 ) {
asm("movntdqa (%0), %%xmm0\n"
"movntdqa 16(%0), %%xmm1\n"
"movntdqa 32(%0), %%xmm2\n"
"movntdqa 48(%0), %%xmm3\n"
"movaps %%xmm0, (%1)\n"
"movaps %%xmm1, 16(%1)\n"
"movaps %%xmm2, 32(%1)\n"
"movaps %%xmm3, 48(%1)\n"
:: "r" (src), "r" (dst) : "memory");
V_2 += 64 ;
V_1 += 64 ;
V_3 -= 4 ;
}
while ( V_3 -- ) {
asm("movntdqa (%0), %%xmm0\n"
"movaps %%xmm0, (%1)\n"
:: "r" (src), "r" (dst) : "memory");
V_2 += 16 ;
V_1 += 16 ;
}
F_3 () ;
}
bool F_4 ( void * V_1 , const void * V_2 , unsigned long V_3 )
{
if ( F_5 ( ( ( unsigned long ) V_1 | ( unsigned long ) V_2 | V_3 ) & 15 ) )
return false ;
#ifdef F_6
if ( F_7 ( & V_4 ) ) {
if ( F_8 ( V_3 ) )
F_1 ( V_1 , V_2 , V_3 ) ;
return true ;
}
#endif
return false ;
}
void F_9 ( struct V_5 * V_6 )
{
if ( F_10 ( V_7 ) )
F_11 ( & V_4 ) ;
}
