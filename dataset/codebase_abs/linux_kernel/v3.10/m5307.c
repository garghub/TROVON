void T_1 F_1 ( char * V_1 , int V_2 )
{
#if F_2 ( V_3 ) || \
F_2 ( V_4 ) || F_2 ( V_5 )
memcpy ( V_1 , ( char * ) 0xf0004000 , V_2 ) ;
V_1 [ V_2 - 1 ] = 0 ;
#endif
V_6 = V_7 ;
F_3 ( 25 , V_8 ) ;
F_3 ( 27 , V_9 ) ;
F_3 ( 29 , V_10 ) ;
F_3 ( 31 , V_11 ) ;
#ifdef F_4
F_5 ( V_12 , V_13 ) ;
#endif
}
