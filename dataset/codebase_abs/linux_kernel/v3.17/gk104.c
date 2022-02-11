static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
T_1 V_5 = ! ( F_2 ( V_4 , 0x100c80 ) & 0x00000001 ) ;
int V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 )
return V_6 ;
F_4 ( V_4 , 0x17e8d8 , V_4 -> V_7 ) ;
F_4 ( V_4 , 0x17e000 , V_4 -> V_7 ) ;
F_4 ( V_4 , 0x17e8d4 , V_4 -> V_8 ) ;
F_5 ( V_4 , 0x17e8c0 , 0x00000002 , V_5 ? 0x00000002 : 0x00000000 ) ;
return 0 ;
}
