T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
T_2 V_5 = F_2 ( V_4 , 0x021c00 ) ;
T_2 V_6 = F_2 ( V_4 , 0x021c04 ) ;
T_1 V_7 = 0ULL ;
if ( V_5 & 0x00000001 )
V_7 |= ( 1ULL << V_8 ) ;
if ( V_5 & 0x00000004 )
V_7 |= ( 1ULL << V_9 ) ;
if ( V_6 & 0x00000001 )
V_7 |= ( 1ULL << V_10 ) ;
return V_7 ;
}
