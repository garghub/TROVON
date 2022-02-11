static void T_1 F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 = ( V_1 & ~ 0x000000ff ) | 0x00000055 ;
F_3 ( V_1 , V_2 ) ;
V_1 = F_2 ( V_3 ) ;
V_1 = ( V_1 & ~ 0x000003fc ) | 0x000002a8 ;
F_3 ( V_1 , V_3 ) ;
}
static void F_4 ( void )
{
F_5 () ;
F_6 ( 0 , V_4 ) ;
F_6 ( 1 , V_5 ) ;
F_6 ( 0 , V_6 ) ;
for (; ; )
;
}
void T_1 F_7 ( char * V_7 , int V_8 )
{
#if F_8 ( V_9 )
F_9 ( 0x40 , V_10 ) ;
#endif
#if F_8 ( V_11 ) || F_8 ( V_12 )
memcpy ( V_7 , ( char * ) 0xf0004000 , V_8 ) ;
V_7 [ V_8 - 1 ] = 0 ;
#elif F_8 ( V_13 )
memcpy ( V_7 , ( char * ) 0xf0010000 , V_8 ) ;
V_7 [ V_8 - 1 ] = 0 ;
#endif
V_14 = F_4 ;
V_15 = V_16 ;
}
static int T_1 F_10 ( void )
{
F_1 () ;
F_11 ( V_17 , 0 , & V_18 , - 1 ) ;
return 0 ;
}
