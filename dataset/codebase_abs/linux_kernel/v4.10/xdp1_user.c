static void F_1 ( int V_1 )
{
F_2 ( V_2 , - 1 ) ;
exit ( 0 ) ;
}
static void F_3 ( int V_3 )
{
unsigned int V_4 = F_4 () ;
const unsigned int V_5 = 256 ;
T_1 V_6 [ V_4 ] , V_7 [ V_5 ] [ V_4 ] ;
T_2 V_8 ;
int V_9 ;
memset ( V_7 , 0 , sizeof( V_7 ) ) ;
while ( 1 ) {
F_5 ( V_3 ) ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ ) {
T_1 V_10 = 0 ;
assert ( F_6 ( V_11 [ 0 ] , & V_8 , V_6 ) == 0 ) ;
for ( V_9 = 0 ; V_9 < V_4 ; V_9 ++ )
V_10 += ( V_6 [ V_9 ] - V_7 [ V_8 ] [ V_9 ] ) ;
if ( V_10 )
printf ( L_1 ,
V_8 , V_10 / V_3 ) ;
memcpy ( V_7 [ V_8 ] , V_6 , sizeof( V_6 ) ) ;
}
}
}
int main ( int V_12 , char * * V_13 )
{
char V_14 [ 256 ] ;
snprintf ( V_14 , sizeof( V_14 ) , L_2 , V_13 [ 0 ] ) ;
if ( V_12 != 2 ) {
printf ( L_3 , V_13 [ 0 ] ) ;
return 1 ;
}
V_2 = strtoul ( V_13 [ 1 ] , NULL , 0 ) ;
if ( F_7 ( V_14 ) ) {
printf ( L_4 , V_15 ) ;
return 1 ;
}
if ( ! V_16 [ 0 ] ) {
printf ( L_5 , strerror ( V_17 ) ) ;
return 1 ;
}
signal ( V_18 , F_1 ) ;
if ( F_2 ( V_2 , V_16 [ 0 ] ) < 0 ) {
printf ( L_6 ) ;
return 1 ;
}
F_3 ( 2 ) ;
return 0 ;
}
