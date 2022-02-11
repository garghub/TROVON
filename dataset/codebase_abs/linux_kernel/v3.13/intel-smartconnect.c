static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 ;
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 , L_1 , NULL , & V_3 ) ;
if ( ! F_3 ( V_4 ) )
return - V_6 ;
if ( V_3 & 0x1 ) {
F_4 ( & V_2 -> V_7 , L_2 ) ;
V_4 = F_5 ( V_2 -> V_5 , L_3 , 0 ) ;
}
return 0 ;
}
