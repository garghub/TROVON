void F_1 ( char * V_1 )
{
T_1 V_2 ;
T_1 V_3 ;
V_2 = ( T_1 ) strlen ( V_1 ) ;
if ( ! V_2 ) {
return;
}
if ( V_4 [ V_5 ] . V_6 !=
NULL ) {
V_3 =
( T_1 )
strlen ( V_4 [ V_5 ] .
V_6 ) ;
if ( V_2 > V_3 ) {
F_2 ( V_4
[ V_5 ] . V_6 ) ;
V_4 [ V_5 ] .
V_6 = F_3 ( V_2 + 1 ) ;
}
} else {
V_4 [ V_5 ] . V_6 =
F_3 ( V_2 + 1 ) ;
}
strcpy ( V_4 [ V_5 ] . V_6 ,
V_1 ) ;
V_4 [ V_5 ] . V_7 =
V_8 ;
if ( ( V_9 == V_10 ) &&
( V_5 == V_11 ) ) {
V_11 ++ ;
if ( V_11 >= V_10 ) {
V_11 = 0 ;
}
}
V_5 ++ ;
if ( V_5 >= V_10 ) {
V_5 = 0 ;
}
V_8 ++ ;
if ( V_9 < V_10 ) {
V_9 ++ ;
}
}
void F_4 ( void )
{
T_2 V_12 ;
T_1 V_13 ;
V_13 = V_11 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( V_4 [ V_13 ] . V_6 ) {
F_5 ( L_1 ,
V_4 [ V_13 ] .
V_7 ,
V_4 [ V_13 ] .
V_6 ) ;
}
V_13 ++ ;
if ( V_13 >= V_10 ) {
V_13 = 0 ;
}
}
}
char * F_6 ( char * V_14 )
{
T_2 V_7 ;
if ( V_14 == NULL ) {
V_7 = V_8 - 1 ;
}
else {
V_7 = strtoul ( V_14 , NULL , 0 ) ;
}
return ( F_7 ( V_7 ) ) ;
}
char * F_7 ( T_2 V_7 )
{
T_2 V_12 ;
T_1 V_13 ;
V_13 = V_11 ;
for ( V_12 = 0 ; V_12 < V_9 ; V_12 ++ ) {
if ( V_4 [ V_13 ] . V_7 == V_7 ) {
return ( V_4 [ V_13 ] . V_6 ) ;
}
V_13 ++ ;
if ( V_13 >= V_10 ) {
V_13 = 0 ;
}
}
F_5 ( L_2 , V_13 ) ;
return ( NULL ) ;
}
