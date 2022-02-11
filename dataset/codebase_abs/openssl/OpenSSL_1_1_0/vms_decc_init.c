char * * F_1 ( int * V_1 , char * V_2 [] )
{
int V_3 , V_4 = * V_1 ;
char * * V_5 = F_2 ( sizeof( * V_5 ) * ( V_4 + 1 ) , L_1 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_5 [ V_3 ] = V_2 [ V_3 ] ;
V_5 [ V_3 ] = NULL ;
* V_1 = V_3 ;
return V_5 ;
}
static void F_3 ( void )
{
char * V_6 ;
int V_7 = 0 ;
int V_8 ;
int V_9 ;
int V_10 ;
int V_11 ;
int V_3 ;
int V_12 ;
V_6 = getenv ( L_2 ) ;
if ( V_6 != NULL ) {
V_7 = strtol ( V_6 , NULL , 10 ) ;
if ( V_7 <= 0 ) {
V_7 = 1 ;
}
}
V_13 = 1 ;
for ( V_3 = 0 ; V_14 [ V_3 ] . V_15 != NULL ; V_3 ++ ) {
V_8 = F_4 ( V_14 [ V_3 ] . V_15 ) ;
if ( V_8 >= 0 ) {
V_9 = F_5 ( V_8 , 1 ) ;
V_11 = F_5 ( V_8 , 2 ) ;
V_10 = F_5 ( V_8 , 3 ) ;
if ( ( V_14 [ V_3 ] . V_16 >= V_11 ) &&
( V_14 [ V_3 ] . V_16 <= V_10 ) ) {
if ( V_9 != V_14 [ V_3 ] . V_16 ) {
V_12 = F_6 ( V_8 ,
1 , V_14 [ V_3 ] . V_16 ) ;
if ( V_7 > 1 ) {
fprintf ( V_17 , L_3 ,
V_14 [ V_3 ] . V_15 ,
V_14 [ V_3 ] . V_16 , V_12 ) ;
}
}
} else {
fprintf ( V_17 ,
L_4 ,
V_9 ,
V_11 , V_14 [ V_3 ] . V_15 ,
V_10 ) ;
}
} else {
fprintf ( V_17 ,
L_5 , V_14 [ V_3 ] . V_15 ) ;
}
}
if ( V_7 > 0 ) {
fprintf ( V_17 , L_6 ) ;
}
}
