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
V_20 = F_8 ( V_19 - V_17 ) ;
V_14 = F_9 ( V_21 ) ;
V_22 = F_8 ( V_17 ) ;
V_13 = F_8 ( V_14 ) ;
V_23 = F_8 ( V_19 ) ;
V_24 = ( void * ) V_19 ;
V_25 = F_10 ( V_19 - V_17 - 1 ) - 6 ;
F_11 ( NULL , V_26 , V_27 ) ;
F_12 ( 0 ) ;
V_14 += F_13 ( F_14 ( 0 ) , V_13 ,
V_22 , V_23 ) ;
F_15 ( F_14 ( 0 ) , V_14 , V_19 - V_14 ) ;
}
void T_1 F_16 ( char * V_28 , int V_18 )
{
#ifdef F_17
F_7 () ;
F_18 () ;
#endif
V_29 = F_3 ;
V_30 = V_31 ;
F_1 () ;
}
