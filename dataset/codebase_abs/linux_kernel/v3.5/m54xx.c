static void T_1 F_1 ( void )
{
F_2 ( V_1 | V_2 ,
V_3 + F_3 ( 0 ) ) ;
F_2 ( V_1 | V_2 | V_4 ,
V_3 + F_3 ( 1 ) ) ;
F_2 ( V_1 | V_2 | V_4 |
V_5 , V_3 + F_3 ( 2 ) ) ;
F_2 ( V_1 | V_2 ,
V_3 + F_3 ( 3 ) ) ;
}
static void F_4 ( void )
{
asm("movew #0x2700, %sr\n");
F_5 ( 0 , V_3 + V_6 ) ;
F_5 ( F_6 ( 1 ) , V_3 + V_7 ) ;
F_5 ( V_8 | V_9 | F_7 ( 4 ) ,
V_3 + V_6 ) ;
}
static void T_1 F_8 ( void )
{
unsigned long V_10 ;
unsigned long V_11 ;
V_12 [ 0 ] . V_13 = V_14 ;
V_12 [ 0 ] . V_15 = V_16 - V_14 ;
V_17 = ( V_16 - V_14 ) >> V_18 ;
V_11 = F_9 ( V_19 ) ;
V_20 = V_14 >> V_18 ;
V_10 = V_11 >> V_18 ;
V_21 = V_16 >> V_18 ;
V_22 = ( void * ) V_16 ;
V_23 = F_10 ( V_16 - V_14 - 1 ) - 6 ;
F_11 ( NULL , V_24 , V_25 ) ;
F_12 ( 0 ) ;
V_11 += F_13 ( F_14 ( 0 ) , V_10 ,
V_20 , V_21 ) ;
F_15 ( F_14 ( 0 ) , V_11 , V_16 - V_11 ) ;
}
void T_1 F_16 ( char * V_26 , int V_15 )
{
#ifdef F_17
F_8 () ;
F_18 () ;
#endif
V_27 = F_4 ;
V_28 = V_29 ;
F_1 () ;
}
