static inline void F_1 ( unsigned int V_1 )
{
F_2 () ;
for (; ; ) {
__asm__ __volatile__("dsb\n\t" "wfi\n\t"
: : : "memory");
if ( V_2 == F_3 ( V_1 ) ) {
break;
}
}
}
void T_1 F_4 ( unsigned int V_1 )
{
F_1 ( V_1 ) ;
}
