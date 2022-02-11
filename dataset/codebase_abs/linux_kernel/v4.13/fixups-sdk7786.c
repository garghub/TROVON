char * T_1 F_1 ( char * V_1 )
{
if ( strcmp ( V_1 , L_1 ) == 0 ) {
V_2 = 1 ;
return NULL ;
}
return V_1 ;
}
static int T_1 F_2 ( void )
{
T_2 V_3 = F_3 ( V_4 ) ;
V_2 ? : ( ! ( V_3 & V_5 ) && ( V_3 & V_6 ) ) ;
if ( V_2 ) {
F_4 ( L_2 ) ;
V_3 &= ~ V_7 ;
F_5 ( V_3 , V_4 ) ;
if ( ( V_3 & V_6 ) == 0 ) {
F_6 ( L_3 ) ;
return - V_8 ;
}
} else
F_4 ( L_4 ) ;
return 0 ;
}
