void F_1 ( bool V_1 )
{
if ( ! V_2 || ! V_3 )
return;
F_2 ( L_1 ,
V_1 ? L_2 : L_3 ) ;
if ( V_1 )
V_2 () ;
else
V_3 () ;
}
int F_3 ( void )
{
int V_4 = 0 ;
V_2 = F_4 ( V_5 ) ;
if ( ! V_2 ) {
F_5 ( L_4 ) ;
return - V_6 ;
}
V_3 = F_4 ( V_7 ) ;
if ( ! V_3 ) {
F_6 ( V_5 ) ;
V_2 = NULL ;
return - V_6 ;
}
F_2 ( L_5 ) ;
return V_4 ;
}
int F_7 ( void )
{
if ( V_2 ) {
F_6 ( V_5 ) ;
V_2 = NULL ;
}
if ( V_3 ) {
F_6 ( V_7 ) ;
V_3 = NULL ;
}
return 0 ;
}
