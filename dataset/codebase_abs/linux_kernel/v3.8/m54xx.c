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
static void T_1 F_7 ( void )
{
unsigned long V_13 ;
unsigned long V_14 ;
V_15 [ 0 ] . V_16 = V_17 ;
V_15 [ 0 ] . V_18 = V_19 - V_17 ;
V_20 = ( V_19 - V_17 ) >> V_21 ;
V_14 = F_8 ( V_22 ) ;
V_23 = V_17 >> V_21 ;
V_13 = V_14 >> V_21 ;
V_24 = V_19 >> V_21 ;
V_25 = ( void * ) V_19 ;
V_26 = F_9 ( V_19 - V_17 - 1 ) - 6 ;
F_10 ( NULL , V_27 , V_28 ) ;
F_11 ( 0 ) ;
V_14 += F_12 ( F_13 ( 0 ) , V_13 ,
V_23 , V_24 ) ;
F_14 ( F_13 ( 0 ) , V_14 , V_19 - V_14 ) ;
}
void T_1 F_15 ( char * V_29 , int V_18 )
{
#ifdef F_16
F_7 () ;
F_17 () ;
#endif
V_30 = F_3 ;
V_31 = V_32 ;
F_1 () ;
}
