static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
void T_2 * V_4 ;
T_3 V_5 ;
int V_6 ;
V_4 = F_2 ( V_2 , 0 ) ;
if ( ! V_4 ) {
F_3 ( L_1 ) ;
return;
}
V_6 = F_4 ( V_2 , L_2 , & V_5 ) ;
if ( V_6 ) {
V_3 = F_5 ( V_2 , 0 ) ;
if ( F_6 ( V_3 ) )
goto V_7;
V_6 = F_7 ( V_3 ) ;
if ( V_6 )
goto V_8;
V_5 = F_8 ( V_3 ) ;
if ( ! V_5 )
goto V_9;
}
F_9 ( V_10 , V_4 + V_11 ) ;
F_9 ( V_12 , V_4 + V_13 ) ;
V_6 = F_10 ( V_4 + V_14 , L_3 , V_5 ,
200 , 24 , V_15 ) ;
if ( V_6 ) {
F_11 ( L_4 , V_6 ) ;
if ( V_3 )
goto V_9;
else
goto V_7;
}
F_12 ( L_5 ) ;
return;
V_9:
F_13 ( V_3 ) ;
V_8:
F_14 ( V_3 ) ;
V_7:
F_15 ( V_4 ) ;
F_3 ( L_6 , V_6 ) ;
}
