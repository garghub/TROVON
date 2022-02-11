static int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 , V_5 ;
T_2 V_6 ;
V_4 = F_2 ( V_1 ) ;
V_5 = F_2 ( V_1 + sizeof( T_1 ) ) ;
V_6 = ( ( T_2 ) V_4 << 32 ) | V_5 ;
memcpy ( V_3 , & V_6 , sizeof( T_2 ) ) ;
return 0 ;
}
static int F_3 ( unsigned long V_1 , struct V_2 V_3 )
{
T_2 V_6 = * ( T_2 * ) & V_3 ;
F_4 ( ( V_6 >> 32 ) & 0xffffffff , V_1 ) ;
F_4 ( V_6 & 0xffffffff , V_1 + sizeof( T_1 ) ) ;
return 0 ;
}
int T_3 F_5 ( struct V_7 * V_8 )
{
return F_6 ( V_8 , V_9 ,
F_7 ( V_9 ) ) ;
}
