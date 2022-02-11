static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = V_3 / 10 ;
__asm__ volatile ("0:\n"
"subs %0, %1, #1\n"
"bge 0b\n"
:"=r" (cyc)
:"0"(cyc)
);
}
static void T_1 F_2 ( void )
{
F_3 ( V_5 L_1 ) ;
F_4 ( NULL ) ;
F_5 ( NULL ) ;
F_6 ( NULL ) ;
F_7 ( V_6 , F_8 ( V_6 ) ) ;
}
