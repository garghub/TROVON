int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
struct V_4 * V_4 = NULL ;
int V_5 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 , V_6 ) ;
return - V_7 ;
}
V_3 = F_4 ( V_2 , L_3 , 0 ) ;
if ( V_3 < 0 ) {
F_3 ( L_4 , V_6 ,
V_3 ) ;
return V_3 ;
}
V_5 = F_5 ( V_3 , L_5 ) ;
if ( V_5 ) {
F_3 ( L_6 , V_6 , V_5 ) ;
return V_5 ;
}
F_6 ( V_3 , 1 ) ;
V_4 = F_7 ( NULL , L_7 ) ;
if ( F_8 ( V_4 ) ) {
F_3 ( L_8 , V_6 ,
( int ) F_9 ( V_4 ) ) ;
goto V_8;
}
F_10 ( V_4 ) ;
V_5 = F_11 ( true , true ) ;
if ( V_5 ) {
F_3 ( L_9 , V_6 , V_5 ) ;
goto V_9;
}
return 0 ;
V_9:
F_12 ( V_4 ) ;
F_13 ( V_4 ) ;
V_8:
F_14 ( V_3 ) ;
return V_5 ;
}
