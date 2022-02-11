static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) V_2 ;
T_1 V_5 = F_2 ( V_4 -> V_6 ) ;
T_1 V_7 = F_3 ( V_4 -> V_6 ) ;
int V_8 ;
V_8 = F_4 ( & V_4 -> V_9 ) ;
if ( V_8 )
return V_8 ;
F_5 ( V_4 , L_1 , V_7 ) ;
F_5 ( V_4 , L_2 , V_5 ) ;
F_6 ( V_4 , V_10 , V_5 ) ;
F_6 ( V_4 , V_11 , V_7 ) ;
return 0 ;
}
