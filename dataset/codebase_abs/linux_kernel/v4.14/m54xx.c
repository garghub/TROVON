static void T_1 F_1 ( void )
{
F_2 ( V_1 | V_2 , V_3 ) ;
F_2 ( V_1 | V_2 | V_4 ,
V_5 ) ;
F_2 ( V_1 | V_2 | V_4 |
V_6 , V_7 ) ;
F_2 ( V_1 | V_2 , V_8 ) ;
}
static void T_1 F_3 ( void )
{
#if F_4 ( V_9 )
T_2 V_10 ;
V_10 = F_5 ( V_11 ) ;
V_10 |= V_12 | V_13 ;
F_6 ( V_10 , V_11 ) ;
#endif
}
static void F_7 ( void )
{
asm("movew #0x2700, %sr\n");
F_8 ( 0 , V_14 ) ;
F_8 ( F_9 ( 1 ) , V_15 ) ;
F_8 ( V_16 | V_17 | F_10 ( 4 ) ,
V_14 ) ;
}
void T_1 F_11 ( char * V_18 , int V_19 )
{
#ifdef F_12
F_13 () ;
F_14 () ;
#endif
V_20 = F_7 ;
V_21 = V_22 ;
F_1 () ;
F_3 () ;
}
