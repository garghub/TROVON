static T_1 F_1 ( int V_1 , void * V_2 )
{
static int V_3 = 0 ;
if ( V_3 == 0 ) {
F_2 ( V_4 L_1 ,
V_1 ) ;
V_3 ++ ;
}
return V_5 ;
}
static int T_2 F_3 ( void )
{
if ( V_1 < 0 ) {
F_2 ( V_6 L_2 ) ;
return - V_7 ;
}
if ( F_4 ( V_1 , & F_1 , V_8 , L_3 , & V_1 ) ) {
F_2 ( V_6 L_4 , V_1 ) ;
return - V_7 ;
}
F_2 ( V_4 L_5 , V_1 ) ;
return 0 ;
}
static void T_3 F_5 ( void )
{
F_2 ( V_4 L_6 ) ;
F_6 ( V_1 , & V_1 ) ;
}
