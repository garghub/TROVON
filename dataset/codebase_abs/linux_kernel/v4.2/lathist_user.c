static void F_1 ( char * V_1 , long V_2 , long V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < ( V_4 * V_2 / V_3 ) - 1 && V_5 < V_4 - 1 ; V_5 ++ )
V_1 [ V_5 ] = '*' ;
if ( V_2 > V_3 )
V_1 [ V_5 - 1 ] = '+' ;
V_1 [ V_5 ] = '\0' ;
}
static void F_2 ( void )
{
char V_6 [ V_7 ] ;
struct V_8 * V_9 ;
int V_5 , V_10 ;
printf ( L_1 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_9 = & V_8 [ V_10 ] ;
if ( V_9 -> V_3 == 0 )
continue;
printf ( L_2 , V_10 ) ;
printf ( L_3 ) ;
for ( V_5 = 1 ; V_5 <= V_12 ; V_5 ++ ) {
F_1 ( V_6 , V_9 -> V_13 [ V_5 - 1 ] , V_9 -> V_3 , V_7 ) ;
printf ( L_4 ,
( 1l << V_5 ) >> 1 , ( 1l << V_5 ) - 1 ,
V_9 -> V_13 [ V_5 - 1 ] , V_7 , V_6 ) ;
}
}
}
static void F_3 ( int V_14 )
{
long V_15 , V_16 ;
int V_17 , V_5 ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ )
V_8 [ V_5 ] . V_3 = 0 ;
for ( V_17 = 0 ; V_17 < V_11 ; V_17 ++ ) {
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
V_15 = V_17 * V_12 + V_5 ;
F_4 ( V_14 , & V_15 , & V_16 ) ;
V_8 [ V_17 ] . V_13 [ V_5 ] = V_16 ;
if ( V_16 > V_8 [ V_17 ] . V_3 )
V_8 [ V_17 ] . V_3 = V_16 ;
}
}
}
int main ( int V_18 , char * * V_19 )
{
char V_20 [ 256 ] ;
snprintf ( V_20 , sizeof( V_20 ) , L_5 , V_19 [ 0 ] ) ;
if ( F_5 ( V_20 ) ) {
printf ( L_6 , V_21 ) ;
return 1 ;
}
while ( 1 ) {
F_3 ( V_22 [ 1 ] ) ;
F_2 () ;
F_6 ( 5 ) ;
}
return 0 ;
}
