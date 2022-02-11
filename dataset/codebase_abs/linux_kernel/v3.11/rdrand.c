static int T_1 F_1 ( char * V_1 )
{
F_2 ( V_2 ) ;
return 1 ;
}
static inline int F_3 ( unsigned long * V_3 )
{
int V_4 ;
asm volatile("1: " RDRAND_LONG "\n\t"
"jc 2f\n\t"
"decl %0\n\t"
"jnz 1b\n\t"
"2:"
: "=r" (ok), "=a" (*v)
: "0" (RDRAND_RETRY_LOOPS));
return V_4 ;
}
void F_4 ( struct V_5 * V_6 )
{
#ifdef F_5
unsigned long V_7 ;
int V_8 , V_9 , V_4 ;
if ( ! F_6 ( V_6 , V_2 ) )
return;
for ( V_9 = V_8 = 0 ; V_8 < V_10 ; V_8 ++ ) {
V_4 = F_3 ( & V_7 ) ;
if ( V_4 )
V_9 ++ ;
}
if ( V_9 != V_10 )
F_7 ( V_6 , V_2 ) ;
#endif
}
