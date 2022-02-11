static void F_1 ( int V_1 )
{
F_2 ( V_2 , - 1 , V_3 ) ;
exit ( 0 ) ;
}
static void F_3 ( int V_4 )
{
unsigned int V_5 = F_4 () ;
const unsigned int V_6 = 256 ;
T_1 V_7 [ V_5 ] , V_8 [ V_6 ] [ V_5 ] ;
T_2 V_9 ;
int V_10 ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
while ( 1 ) {
F_5 ( V_4 ) ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ ) {
T_1 V_11 = 0 ;
assert ( F_6 ( V_12 [ 0 ] , & V_9 , V_7 ) == 0 ) ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ )
V_11 += ( V_7 [ V_10 ] - V_8 [ V_9 ] [ V_10 ] ) ;
if ( V_11 )
printf ( L_1 ,
V_9 , V_11 / V_4 ) ;
memcpy ( V_8 [ V_9 ] , V_7 , sizeof( V_7 ) ) ;
}
}
}
static void F_7 ( const char * V_13 )
{
fprintf ( V_14 ,
L_2
L_3
L_4
L_5 ,
V_13 ) ;
}
int main ( int V_15 , char * * V_16 )
{
const char * V_17 = L_6 ;
char V_18 [ 256 ] ;
int V_19 ;
while ( ( V_19 = F_8 ( V_15 , V_16 , V_17 ) ) != - 1 ) {
switch ( V_19 ) {
case 'S' :
V_3 |= V_20 ;
break;
case 'N' :
V_3 |= V_21 ;
break;
default:
F_7 ( F_9 ( V_16 [ 0 ] ) ) ;
return 1 ;
}
}
if ( V_22 == V_15 ) {
F_7 ( F_9 ( V_16 [ 0 ] ) ) ;
return 1 ;
}
V_2 = strtoul ( V_16 [ V_22 ] , NULL , 0 ) ;
snprintf ( V_18 , sizeof( V_18 ) , L_7 , V_16 [ 0 ] ) ;
if ( F_10 ( V_18 ) ) {
printf ( L_8 , V_23 ) ;
return 1 ;
}
if ( ! V_24 [ 0 ] ) {
printf ( L_9 , strerror ( V_25 ) ) ;
return 1 ;
}
signal ( V_26 , F_1 ) ;
signal ( V_27 , F_1 ) ;
if ( F_2 ( V_2 , V_24 [ 0 ] , V_3 ) < 0 ) {
printf ( L_10 ) ;
return 1 ;
}
F_3 ( 2 ) ;
return 0 ;
}
