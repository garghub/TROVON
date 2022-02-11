static void T_1 F_1 ( void )
{
T_2 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 = ( V_1 & ~ 0x000000ff ) | 0x00000055 ;
F_3 ( V_1 , V_2 + V_3 ) ;
V_1 = F_2 ( V_2 + V_4 ) ;
V_1 = ( V_1 & ~ 0x000003fc ) | 0x000002a8 ;
F_3 ( V_1 , V_2 + V_4 ) ;
}
static void F_4 ( void )
{
F_5 () ;
F_6 ( 0 , V_2 + V_5 ) ;
F_6 ( 1 , V_2 + V_6 ) ;
F_6 ( 0 , V_2 + V_7 ) ;
for (; ; )
;
}
void T_1 F_7 ( char * V_8 , int V_9 )
{
#if F_8 ( V_10 )
volatile unsigned char * V_11 ;
V_11 = ( volatile unsigned char * ) ( V_2 + V_12 ) ;
* V_11 = 0x40 ;
#endif
#if F_8 ( V_13 ) || F_8 ( V_14 )
memcpy ( V_8 , ( char * ) 0xf0004000 , V_9 ) ;
V_8 [ V_9 - 1 ] = 0 ;
#elif F_8 ( V_15 )
memcpy ( V_8 , ( char * ) 0xf0010000 , V_9 ) ;
V_8 [ V_9 - 1 ] = 0 ;
#endif
V_16 = F_4 ;
V_17 = V_18 ;
}
static int T_1 F_9 ( void )
{
F_1 () ;
F_10 ( V_19 , 0 , & V_20 ) ;
return 0 ;
}
