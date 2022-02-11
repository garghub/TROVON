int
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0x00000000 ) ;
F_2 ( V_2 , V_4 , 0xFFFFFFFF ) ;
if ( ! F_3 ( V_2 , V_5 ) ||
! F_3 ( V_2 , V_6 ) ) {
F_2 ( V_2 , V_5 , 0x00000008 ) ;
F_2 ( V_2 , V_6 , 0x00000003 ) ;
}
return 0 ;
}
T_1
F_4 ( struct V_1 * V_2 )
{
T_2 V_7 ;
T_2 V_8 = F_3 ( V_2 , V_9 ) ;
T_2 V_10 ;
do {
V_10 = V_8 ;
V_7 = F_3 ( V_2 , V_11 ) ;
V_8 = F_3 ( V_2 , V_9 ) ;
} while ( V_10 != V_8 );
return ( ( ( T_1 ) V_8 ) << 32 ) | ( T_1 ) V_7 ;
}
void
F_5 ( struct V_1 * V_2 )
{
}
