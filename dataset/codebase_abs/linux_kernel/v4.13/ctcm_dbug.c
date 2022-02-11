void F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
F_2 ( V_3 [ V_1 ] . V_4 ) ;
V_3 [ V_1 ] . V_4 = NULL ;
}
}
int F_3 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
V_3 [ V_1 ] . V_4 = F_4 ( V_3 [ V_1 ] . V_5 ,
V_3 [ V_1 ] . V_6 ,
V_3 [ V_1 ] . V_7 ,
V_3 [ V_1 ] . V_8 ) ;
if ( V_3 [ V_1 ] . V_4 == NULL ) {
F_1 () ;
return - V_9 ;
}
F_5 ( V_3 [ V_1 ] . V_4 , & V_10 ) ;
F_6 ( V_3 [ V_1 ] . V_4 , V_3 [ V_1 ] . V_11 ) ;
}
return 0 ;
}
void F_7 ( enum V_12 V_13 , int V_11 , char * V_14 , ... )
{
char V_15 [ 64 ] ;
T_1 args ;
if ( ! F_8 ( V_3 [ V_13 ] . V_4 , V_11 ) )
return;
va_start ( args , V_14 ) ;
vsnprintf ( V_15 , sizeof( V_15 ) , V_14 , args ) ;
va_end ( args ) ;
F_9 ( V_3 [ V_13 ] . V_4 , V_11 , V_15 ) ;
}
