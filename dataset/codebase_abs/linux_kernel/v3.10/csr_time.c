T_1 F_1 ( T_1 * V_1 )
{
struct V_2 V_3 ;
T_2 time ;
T_1 V_4 ;
V_3 = F_2 () ;
time = ( T_2 ) V_3 . V_5 * 1000000 + V_3 . V_6 / 1000 ;
if ( V_1 != NULL )
* V_1 = ( T_1 ) ( ( time >> 32 ) & 0xFFFFFFFF ) ;
V_4 = ( T_1 ) ( time & 0xFFFFFFFF ) ;
return V_4 ;
}
