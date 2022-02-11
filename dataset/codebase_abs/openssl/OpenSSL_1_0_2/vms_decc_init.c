static void F_1 ( void )
{
char * V_1 ;
int V_2 = 0 ;
int V_3 ;
int V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
int V_8 ;
V_1 = getenv ( L_1 ) ;
if ( V_1 != NULL ) {
V_2 = strtol ( V_1 , NULL , 10 ) ;
if ( V_2 <= 0 ) {
V_2 = 1 ;
}
}
V_9 = 1 ;
for ( V_7 = 0 ; V_10 [ V_7 ] . V_11 != NULL ; V_7 ++ ) {
V_3 = F_2 ( V_10 [ V_7 ] . V_11 ) ;
if ( V_3 >= 0 ) {
V_4 = F_3 ( V_3 , 1 ) ;
V_6 = F_3 ( V_3 , 2 ) ;
V_5 = F_3 ( V_3 , 3 ) ;
if ( ( V_10 [ V_7 ] . V_12 >= V_6 ) &&
( V_10 [ V_7 ] . V_12 <= V_5 ) ) {
if ( V_4 != V_10 [ V_7 ] . V_12 ) {
V_8 = F_4 ( V_3 ,
1 , V_10 [ V_7 ] . V_12 ) ;
if ( V_2 > 1 ) {
fprintf ( V_13 , L_2 ,
V_10 [ V_7 ] . V_11 ,
V_10 [ V_7 ] . V_12 , V_8 ) ;
}
}
} else {
fprintf ( V_13 ,
L_3 ,
V_4 ,
V_6 , V_10 [ V_7 ] . V_11 ,
V_5 ) ;
}
} else {
fprintf ( V_13 ,
L_4 , V_10 [ V_7 ] . V_11 ) ;
}
}
if ( V_2 > 0 ) {
fprintf ( V_13 , L_5 ) ;
}
}
