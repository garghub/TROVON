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
#if F_6 ( V_10 )
memcpy ( V_8 , ( char * ) 0xf0004000 , V_9 ) ;
V_8 [ V_9 - 1 ] = 0 ;
#endif
V_11 = V_12 ;
F_4 ( 25 , V_13 ) ;
F_4 ( 28 , V_14 ) ;
F_4 ( 31 , V_15 ) ;
F_1 () ;
}
