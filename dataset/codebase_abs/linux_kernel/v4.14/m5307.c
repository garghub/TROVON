static void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 ( V_2 | V_3 | V_4 ,
V_5 ) ;
F_4 ( V_6 , V_7 ) ;
#endif
}
void T_1 F_5 ( char * V_8 , int V_9 )
{
#if F_6 ( V_10 ) || \
F_6 ( V_11 ) || F_6 ( V_12 )
memcpy ( V_8 , ( char * ) 0xf0004000 , V_9 ) ;
V_8 [ V_9 - 1 ] = 0 ;
#endif
V_13 = V_14 ;
F_4 ( 25 , V_15 ) ;
F_4 ( 27 , V_16 ) ;
F_4 ( 29 , V_17 ) ;
F_4 ( 31 , V_18 ) ;
#ifdef F_7
F_8 ( V_19 , V_20 ) ;
#endif
F_1 () ;
}
