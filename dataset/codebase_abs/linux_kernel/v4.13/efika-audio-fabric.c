static T_1 int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
if ( ! F_2 ( L_1 ) )
return - V_4 ;
V_2 = F_3 ( L_2 , 1 ) ;
if ( ! V_2 ) {
F_4 ( L_3 ) ;
return - V_4 ;
}
F_5 ( V_2 , & V_5 ) ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 ) {
F_4 ( L_4 ) ;
F_7 ( V_2 ) ;
return - V_4 ;
}
return 0 ;
}
