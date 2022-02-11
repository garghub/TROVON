void T_1 F_1 ( void )
{
T_2 V_1 ;
T_3 V_2 = F_2 ( V_3 - V_4 ) ;
V_1 = F_3 ( 0 , 1 << 20 , V_2 , V_5 ) ;
if ( V_1 == V_6 )
F_4 ( L_1 ) ;
V_7 = F_5 ( V_1 ) ;
F_6 ( V_1 , V_1 + V_2 , L_2 ) ;
F_7 ( V_8 L_3 ,
V_7 , ( unsigned long long ) V_1 , V_2 ) ;
memcpy ( V_7 , V_4 , V_2 ) ;
}
static int T_1 F_8 ( void )
{
T_3 V_2 = F_2 ( V_3 - V_4 ) ;
F_9 ( ( unsigned long ) V_7 , V_2 >> V_9 ) ;
return 0 ;
}
