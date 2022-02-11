static void F_1 ( char * V_1 , long V_2 , long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < ( V_4 * V_2 / V_3 ) - 1 && V_5 < V_4 - 1 ; V_5 ++ )
V_1 [ V_5 ] = '*' ;
if ( V_2 > V_3 )
V_1 [ V_5 - 1 ] = '+' ;
V_1 [ V_5 ] = '\0' ;
}
static void F_2 ( int V_6 )
{
int V_7 ;
long V_8 ;
long V_9 [ V_10 ] = {} ;
char V_11 [ V_12 ] ;
int V_5 ;
int V_13 = - 1 ;
long V_14 = 0 ;
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
F_3 ( V_6 , & V_7 , & V_8 ) ;
V_9 [ V_7 ] = V_8 ;
if ( V_8 && V_7 > V_13 )
V_13 = V_7 ;
if ( V_8 > V_14 )
V_14 = V_8 ;
}
printf ( L_1 ) ;
printf ( L_2 ) ;
for ( V_5 = 1 ; V_5 <= V_13 + 1 ; V_5 ++ ) {
F_1 ( V_11 , V_9 [ V_5 - 1 ] , V_14 , V_12 ) ;
printf ( L_3 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 , V_9 [ V_5 - 1 ] ,
V_12 , V_11 ) ;
}
}
static void F_4 ( int V_15 )
{
F_2 ( V_16 [ 1 ] ) ;
exit ( 0 ) ;
}
int main ( int V_17 , char * * V_18 )
{
char V_19 [ 256 ] ;
long V_7 , V_20 , V_8 ;
T_1 * V_21 ;
int V_5 ;
snprintf ( V_19 , sizeof( V_19 ) , L_4 , V_18 [ 0 ] ) ;
signal ( V_22 , F_4 ) ;
V_21 = F_5 ( L_5 , L_6 ) ;
( void ) V_21 ;
V_21 = F_5 ( L_7 , L_6 ) ;
( void ) V_21 ;
if ( F_6 ( V_19 ) ) {
printf ( L_8 , V_23 ) ;
return 1 ;
}
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
V_7 = 0 ;
while ( F_7 ( V_16 [ 0 ] , & V_7 , & V_20 ) == 0 ) {
F_3 ( V_16 [ 0 ] , & V_20 , & V_8 ) ;
printf ( L_9 , V_20 , V_8 ) ;
V_7 = V_20 ;
}
if ( V_7 )
printf ( L_10 ) ;
F_8 ( 1 ) ;
}
F_2 ( V_16 [ 1 ] ) ;
return 0 ;
}
