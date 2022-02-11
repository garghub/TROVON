T_1 F_1 ( void )
{
if ( F_2 () )
return F_3 () ;
else if ( F_4 () )
return V_1 ;
return V_2 ;
}
static int T_2 F_5 ( void )
{
int V_3 ;
int error ;
V_3 = F_6 () ;
if ( V_3 < V_4 ) {
F_7 ( L_1 ,
V_3 ) ;
return - V_5 ;
}
if ( ! V_6 ) {
error = F_8 () ;
if ( error ) {
F_9 ( L_2 ,
error ) ;
} else {
V_7 = true ;
F_10 ( L_3 ,
F_2 () ?
L_4 : L_5 ) ;
}
}
if ( ! V_8 ) {
error = F_11 () ;
if ( error ) {
F_9 ( L_6 ,
error ) ;
} else {
V_9 = true ;
F_10 ( L_7 ) ;
}
}
if ( ! V_7 &&
! V_9 ) {
F_12 () ;
return - V_10 ;
}
return 0 ;
}
static void T_3 F_13 ( void )
{
if ( V_7 )
F_14 () ;
if ( V_9 )
F_15 () ;
F_12 () ;
}
