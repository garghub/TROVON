T_1 F_1 ( void )
{
return ( T_1 ) F_2 () ;
}
T_2 F_3 ( void )
{
if ( F_4 ( ! V_1 ) ) {
V_1 = F_5 ( 0 ) ;
if ( ! V_1 )
V_1 = V_2 ;
}
return V_1 ;
}
int F_6 ( struct V_3 * V_4 )
{
if ( ! V_5 )
return 0 ;
return V_5 ( V_6 ,
V_4 ) ;
}
void F_7 ( void )
{
if ( ! V_5 )
return;
V_5 ( V_7 , NULL ) ;
}
int T_3 F_8 ( void )
{
struct V_8 * V_9 ;
V_9 = F_9 ( NULL , V_10 ) ;
if ( ! V_9 ) {
F_10 ( L_1 ) ;
return 0 ;
}
if ( F_11 ( V_9 , L_2 ,
& V_1 ) ) {
F_12 ( L_3 ) ;
return - V_11 ;
}
return 0 ;
}
void F_13 ( void ) {}
