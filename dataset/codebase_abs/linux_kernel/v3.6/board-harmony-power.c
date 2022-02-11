int T_1 F_1 ( void )
{
F_2 ( 0 , L_1 ,
NULL , 0 , 5000000 ) ;
if ( F_3 () ) {
F_4 ( 3 , V_1 , 1 ) ;
} else {
struct V_2 * V_3 ;
struct V_4 * V_5 ;
V_3 = F_5 ( L_2 ) ;
if ( V_3 == NULL ) {
F_6 ( L_3 ) ;
return - V_6 ;
}
V_5 = F_7 ( V_3 ) ;
if ( ! V_5 ) {
F_6 ( L_4 ) ;
return - V_6 ;
}
F_8 ( V_5 , V_1 ) ;
}
return 0 ;
}
