static void T_1 F_1 ( void )
{
F_2 ( V_1 | V_2 , V_3 ) ;
F_2 ( V_1 | V_2 | V_4 ,
V_5 ) ;
F_2 ( V_1 | V_2 | V_4 |
V_6 , V_7 ) ;
F_2 ( V_1 | V_2 , V_8 ) ;
}
static void F_3 ( void )
{
asm("movew #0x2700, %sr\n");
F_4 ( 0 , V_9 ) ;
F_4 ( F_5 ( 1 ) , V_10 ) ;
F_4 ( V_11 | V_12 | F_6 ( 4 ) ,
V_9 ) ;
}
void T_1 F_7 ( char * V_13 , int V_14 )
{
#ifdef F_8
F_9 () ;
F_10 () ;
#endif
V_15 = F_3 ;
V_16 = V_17 ;
F_1 () ;
}
