static void F_1 ( void )
{
if ( ! V_1 ) {
F_2 ( & V_2 ) ;
V_1 = 1 ;
}
}
void F_3 ( T_1 V_3 )
{
F_1 () ;
if ( F_4 ( & V_2 ) != 0 )
return;
if ( V_4 )
V_3 () ;
else {
if ( V_5 >= V_6 )
F_5 ( V_7 ,
L_1
L_2 ,
V_5 ) ;
else {
V_8 [ V_5 ] =
V_3 ;
V_5 ++ ;
}
}
F_6 ( & V_2 ) ;
}
void F_7 ( void )
{
int V_9 ;
F_1 () ;
if ( F_4 ( & V_2 ) != 0 )
return;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 ++ )
V_8 [ V_9 ] ( ) ;
V_5 = 0 ;
V_4 = 1 ;
F_6 ( & V_2 ) ;
}
