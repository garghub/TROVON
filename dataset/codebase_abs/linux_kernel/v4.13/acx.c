int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_7 ) ;
if ( ! V_5 ) {
V_6 = - V_8 ;
goto V_9;
}
V_5 -> V_3 = F_3 ( V_3 ) ;
V_6 = F_4 ( V_2 , V_10 ,
V_5 , sizeof( * V_5 ) ) ;
if ( V_6 < 0 ) {
F_5 ( L_1 , V_6 ) ;
goto V_9;
}
V_9:
F_6 ( V_5 ) ;
return V_6 ;
}
