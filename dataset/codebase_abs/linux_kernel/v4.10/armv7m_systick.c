static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
void T_2 * V_4 ;
T_3 V_5 ;
int V_6 ;
V_4 = F_2 ( V_2 , 0 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
V_6 = F_4 ( V_2 , L_2 , & V_5 ) ;
if ( V_6 ) {
V_3 = F_5 ( V_2 , 0 ) ;
if ( F_6 ( V_3 ) ) {
V_6 = F_7 ( V_3 ) ;
goto V_8;
}
V_6 = F_8 ( V_3 ) ;
if ( V_6 )
goto V_9;
V_5 = F_9 ( V_3 ) ;
if ( ! V_5 ) {
V_6 = - V_10 ;
goto V_11;
}
}
F_10 ( V_12 , V_4 + V_13 ) ;
F_10 ( V_14 , V_4 + V_15 ) ;
V_6 = F_11 ( V_4 + V_16 , L_3 , V_5 ,
200 , 24 , V_17 ) ;
if ( V_6 ) {
F_12 ( L_4 , V_6 ) ;
if ( V_3 )
goto V_11;
else
goto V_8;
}
F_13 ( L_5 ) ;
return 0 ;
V_11:
F_14 ( V_3 ) ;
V_9:
F_15 ( V_3 ) ;
V_8:
F_16 ( V_4 ) ;
F_3 ( L_6 , V_6 ) ;
return V_6 ;
}
