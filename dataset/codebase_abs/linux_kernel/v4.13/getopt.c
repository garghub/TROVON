int F_1 ( int V_1 , char * * V_2 )
{
V_3 -- ;
V_4 ++ ;
if ( V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] != '\0' ) {
V_5 =
& V_2 [ V_3 ++ ] [ ( int ) ( V_4 + 1 ) ] ;
} else if ( ++ V_3 >= V_1 ) {
F_2 ( L_1 , 0 ) ;
V_4 = 1 ;
return ( - 1 ) ;
} else {
V_5 = V_2 [ V_3 ++ ] ;
}
V_4 = 1 ;
return ( 0 ) ;
}
int F_3 ( int V_1 , char * * V_2 , char * V_6 )
{
int V_7 ;
char * V_8 ;
if ( V_4 == 1 ) {
if ( V_3 >= V_1 ||
V_2 [ V_3 ] [ 0 ] != '-' ||
V_2 [ V_3 ] [ 1 ] == '\0' ) {
return ( V_9 ) ;
} else if ( strcmp ( V_2 [ V_3 ] , L_2 ) == 0 ) {
V_3 ++ ;
return ( V_9 ) ;
}
}
V_7 = V_2 [ V_3 ] [ V_4 ] ;
if ( V_7 == ':' ||
( V_8 = strchr ( V_6 , V_7 ) ) == NULL ) {
F_2 ( L_3 , V_7 ) ;
if ( V_2 [ V_3 ] [ ++ V_4 ] == '\0' ) {
V_3 ++ ;
V_4 = 1 ;
}
return ( '?' ) ;
}
if ( * ++ V_8 == ':' ) {
if ( V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] != '\0' ) {
V_5 =
& V_2 [ V_3 ++ ] [ ( int )
( V_4 + 1 ) ] ;
} else if ( ++ V_3 >= V_1 ) {
F_2 ( L_4 ,
V_7 ) ;
V_4 = 1 ;
return ( '?' ) ;
} else {
V_5 = V_2 [ V_3 ++ ] ;
}
V_4 = 1 ;
}
else if ( * V_8 == '+' ) {
if ( V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] != '\0' ) {
V_5 =
& V_2 [ V_3 ++ ] [ ( int )
( V_4 + 1 ) ] ;
} else if ( ++ V_3 >= V_1 ) {
V_5 = NULL ;
} else {
V_5 = V_2 [ V_3 ++ ] ;
}
V_4 = 1 ;
}
else if ( * V_8 == '^' ) {
if ( V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] != '\0' ) {
V_5 =
& V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] ;
} else {
V_5 = L_5 ;
}
V_10 = V_5 [ 0 ] ;
V_3 ++ ;
V_4 = 1 ;
}
else if ( * V_8 == '|' ) {
if ( V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] != '\0' ) {
V_5 =
& V_2 [ V_3 ] [ ( int ) ( V_4 + 1 ) ] ;
} else {
F_2
( L_6 ,
V_7 ) ;
V_4 = 1 ;
return ( '?' ) ;
}
V_10 = V_5 [ 0 ] ;
V_3 ++ ;
V_4 = 1 ;
}
else {
if ( V_2 [ V_3 ] [ ++ V_4 ] == '\0' ) {
V_4 = 1 ;
V_3 ++ ;
}
V_5 = NULL ;
}
return ( V_7 ) ;
}
