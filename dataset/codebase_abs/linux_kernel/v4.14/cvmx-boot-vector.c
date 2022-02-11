static void F_1 ( void * V_1 )
{
T_1 V_2 ;
int V_3 ;
memset ( V_1 , 0 , V_4 ) ;
V_2 = F_2 ( V_1 ) | 0x8000000000000000ull ;
for ( V_3 = 0 ; V_3 < 15 ; V_3 ++ ) {
T_1 V_5 = V_6 [ V_3 ] ;
if ( F_3 () && ( V_3 == 0 || V_3 == 7 ) )
V_5 &= 0xffffffff00000000ull ;
F_4 ( V_7 , V_3 * 8 ) ;
F_4 ( V_8 , V_5 ) ;
}
F_4 ( V_7 , 15 * 8 ) ;
F_4 ( V_8 , V_2 ) ;
F_4 ( F_5 ( 0 ) , 0x81fc0000 ) ;
}
struct V_9 * F_6 ( void )
{
struct V_9 * V_10 ;
V_10 = F_7 ( V_4 , 0 ,
( 1ull << 32 ) - 1 , 8 , L_1 , F_1 ) ;
return V_10 ;
}
