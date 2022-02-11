static void F_1 ( void )
{
int V_1 = F_2 ( V_2 ) ;
int * V_3 = malloc ( V_1 * sizeof( int ) ) ;
int V_4 , V_5 ;
struct V_6 V_7 = {
. V_8 = 0 ,
. V_9 = V_10 ,
. V_11 = 0 ,
. type = V_12 ,
. V_13 = 0 ,
. V_14 = 0 ,
. V_15 = 0 ,
} ;
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
V_3 [ V_5 ] = F_3 ( & V_7 , - 1 , V_5 , - 1 , 0 ) ;
if ( V_3 [ V_5 ] < 0 ) {
printf ( L_1 ) ;
goto exit;
}
F_4 ( V_16 [ 0 ] , & V_5 , & V_3 [ V_5 ] , V_17 ) ;
F_5 ( V_3 [ V_5 ] , V_18 , 0 ) ;
}
V_4 = system ( L_2 ) ;
if ( V_4 )
goto exit;
V_4 = system ( L_3 ) ;
if ( V_4 )
goto exit;
exit:
for ( V_5 = 0 ; V_5 < V_1 ; V_5 ++ )
F_6 ( V_3 [ V_5 ] ) ;
F_6 ( V_16 [ 0 ] ) ;
free ( V_3 ) ;
}
int main ( int V_19 , char * * V_20 )
{
char V_21 [ 256 ] ;
snprintf ( V_21 , sizeof( V_21 ) , L_4 , V_20 [ 0 ] ) ;
if ( F_7 ( V_21 ) ) {
printf ( L_5 , V_22 ) ;
return 1 ;
}
F_1 () ;
F_8 () ;
return 0 ;
}
