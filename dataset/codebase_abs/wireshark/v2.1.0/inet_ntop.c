const char *
F_1 ( int V_1 , const void * V_2 , char * V_3 , T_1 V_4 )
{
switch ( V_1 ) {
case V_5 :
return ( F_2 ( V_2 , V_3 , V_4 ) ) ;
case V_6 :
return ( F_3 ( V_2 , V_3 , V_4 ) ) ;
default:
V_7 = V_8 ;
return ( NULL ) ;
}
}
static const char *
F_2 ( const T_2 * V_2 , char * V_3 , T_1 V_4 )
{
static const char V_9 [] = L_1 ;
char V_10 [ sizeof "255.255.255.255"];
int V_11 ;
V_11 = F_4 ( V_10 , sizeof( V_10 ) , V_9 , V_2 [ 0 ] , V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] ) ;
if ( ( T_1 ) V_11 >= V_4 ) {
V_7 = V_12 ;
return ( NULL ) ;
}
F_5 ( V_3 , V_10 , V_4 ) ;
return ( V_3 ) ;
}
static const char *
F_3 ( const T_2 * V_2 , char * V_3 , T_1 V_4 )
{
char V_10 [ sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"] , * V_13 ;
struct { int V_14 , V_15 ; } V_16 , V_17 ;
T_3 V_18 [ V_19 / V_20 ] ;
int V_21 ;
memset ( & V_16 , 0 , sizeof V_16 ) ;
memset ( & V_17 , 0 , sizeof V_17 ) ;
memset ( V_18 , '\0' , sizeof V_18 ) ;
for ( V_21 = 0 ; V_21 < V_19 ; V_21 ++ )
V_18 [ V_21 / 2 ] |= ( V_2 [ V_21 ] << ( ( 1 - ( V_21 % 2 ) ) << 3 ) ) ;
V_16 . V_14 = - 1 ;
V_17 . V_14 = - 1 ;
for ( V_21 = 0 ; V_21 < ( V_19 / V_20 ) ; V_21 ++ ) {
if ( V_18 [ V_21 ] == 0 ) {
if ( V_17 . V_14 == - 1 )
V_17 . V_14 = V_21 , V_17 . V_15 = 1 ;
else
V_17 . V_15 ++ ;
} else {
if ( V_17 . V_14 != - 1 ) {
if ( V_16 . V_14 == - 1 || V_17 . V_15 > V_16 . V_15 )
V_16 = V_17 ;
V_17 . V_14 = - 1 ;
}
}
}
if ( V_17 . V_14 != - 1 ) {
if ( V_16 . V_14 == - 1 || V_17 . V_15 > V_16 . V_15 )
V_16 = V_17 ;
}
if ( V_16 . V_14 != - 1 && V_16 . V_15 < 2 )
V_16 . V_14 = - 1 ;
V_13 = V_10 ;
for ( V_21 = 0 ; V_21 < ( V_19 / V_20 ) ; V_21 ++ ) {
if ( V_16 . V_14 != - 1 && V_21 >= V_16 . V_14 &&
V_21 < ( V_16 . V_14 + V_16 . V_15 ) ) {
if ( V_21 == V_16 . V_14 )
* V_13 ++ = ':' ;
continue;
}
if ( V_21 != 0 )
* V_13 ++ = ':' ;
if ( V_21 == 6 && V_16 . V_14 == 0 &&
( V_16 . V_15 == 6 || ( V_16 . V_15 == 5 && V_18 [ 5 ] == 0xffff ) ) ) {
if ( ! F_2 ( V_2 + 12 , V_13 , sizeof V_10 - ( V_13 - V_10 ) ) )
return ( NULL ) ;
V_13 += strlen ( V_13 ) ;
break;
}
V_13 += F_4 ( V_13 , ( V_22 ) ( sizeof V_10 - ( V_13 - V_10 ) ) , L_2 , V_18 [ V_21 ] ) ;
}
if ( V_16 . V_14 != - 1 && ( V_16 . V_14 + V_16 . V_15 ) ==
( V_19 / V_20 ) )
* V_13 ++ = ':' ;
* V_13 ++ = '\0' ;
if ( ( T_1 ) ( V_13 - V_10 ) > V_4 ) {
V_7 = V_12 ;
return ( NULL ) ;
}
F_5 ( V_3 , V_10 , V_4 ) ;
return ( V_3 ) ;
}
