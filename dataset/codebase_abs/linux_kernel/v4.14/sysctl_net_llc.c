int T_1 F_1 ( void )
{
V_1 = F_2 ( & V_2 , L_1 , V_3 ) ;
V_4 = F_2 ( & V_2 , L_2 , V_5 ) ;
if ( ! V_1 || ! V_4 ) {
F_3 () ;
return - V_6 ;
}
return 0 ;
}
void F_3 ( void )
{
if ( V_1 ) {
F_4 ( V_1 ) ;
V_1 = NULL ;
}
if ( V_4 ) {
F_4 ( V_4 ) ;
V_4 = NULL ;
}
}
