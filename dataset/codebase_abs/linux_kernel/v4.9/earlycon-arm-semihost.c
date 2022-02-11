static void F_1 ( struct V_1 * V_2 , int V_3 )
{
#ifdef F_2
asm volatile("mov x1, %0\n"
"mov x0, #3\n"
"hlt 0xf000\n"
: : "r" (&c) : "x0", "x1", "memory");
#else
asm volatile("mov r1, %0\n"
"mov r0, #3\n"
"svc " SEMIHOST_SWI "\n"
: : "r" (&c) : "r0", "r1", "memory");
#endif
}
static void F_3 ( struct V_4 * V_5 , const char * V_6 , unsigned V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 ;
F_4 ( & V_9 -> V_2 , V_6 , V_7 , F_1 ) ;
}
static int
T_1 F_5 ( struct V_8 * V_11 , const char * V_12 )
{
V_11 -> V_5 -> V_13 = F_3 ;
return 0 ;
}
