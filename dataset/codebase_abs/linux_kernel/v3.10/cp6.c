static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
asm volatile (
"mrc p15, 0, %0, c15, c1, 0\n\t"
"orr %0, %0, #(1 << 6)\n\t"
"mcr p15, 0, %0, c15, c1, 0\n\t"
: "=r"(temp));
return 0 ;
}
void T_2 F_2 ( void )
{
F_3 ( & V_5 ) ;
}
