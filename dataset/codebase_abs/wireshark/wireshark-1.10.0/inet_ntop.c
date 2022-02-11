const char *
F_1 ( T_1 , T_2 , T_3 , T_4 )
int T_1 ;
const void * T_2 ;
char * T_3 ;
T_5 T_4 ;
{
switch ( T_1 ) {
case V_1 :
return ( F_2 ( T_2 , T_3 , T_4 ) ) ;
case V_2 :
return ( F_3 ( T_2 , T_3 , T_4 ) ) ;
default:
V_3 = V_4 ;
return ( NULL ) ;
}
}
static const char *
F_2 ( T_2 , T_3 , T_4 )
const T_6 * T_2 ;
char * T_3 ;
T_5 T_4 ;
{
static const char V_5 [] = L_1 ;
char V_6 [ sizeof "255.255.255.255"];
int V_7 ;
V_7 = F_4 ( V_6 , sizeof( V_6 ) , V_5 , T_2 [ 0 ] , T_2 [ 1 ] , T_2 [ 2 ] , T_2 [ 3 ] ) ;
if ( ( T_5 ) V_7 >= T_4 ) {
V_3 = V_8 ;
return ( NULL ) ;
}
F_5 ( T_3 , V_6 , T_4 ) ;
return ( T_3 ) ;
}
static const char *
F_3 ( T_2 , T_3 , T_4 )
const T_6 * T_2 ;
char * T_3 ;
T_5 T_4 ;
{
char V_6 [ sizeof "ffff:ffff:ffff:ffff:ffff:ffff:255.255.255.255"] , * V_9 ;
struct { int V_10 , V_11 ; } V_12 , V_13 ;
T_7 V_14 [ V_15 / V_16 ] ;
int V_17 ;
memset ( V_14 , '\0' , sizeof V_14 ) ;
for ( V_17 = 0 ; V_17 < V_15 ; V_17 ++ )
V_14 [ V_17 / 2 ] |= ( T_2 [ V_17 ] << ( ( 1 - ( V_17 % 2 ) ) << 3 ) ) ;
V_12 . V_10 = - 1 ;
V_13 . V_10 = - 1 ;
for ( V_17 = 0 ; V_17 < ( V_15 / V_16 ) ; V_17 ++ ) {
if ( V_14 [ V_17 ] == 0 ) {
if ( V_13 . V_10 == - 1 )
V_13 . V_10 = V_17 , V_13 . V_11 = 1 ;
else
V_13 . V_11 ++ ;
} else {
if ( V_13 . V_10 != - 1 ) {
if ( V_12 . V_10 == - 1 || V_13 . V_11 > V_12 . V_11 )
V_12 = V_13 ;
V_13 . V_10 = - 1 ;
}
}
}
if ( V_13 . V_10 != - 1 ) {
if ( V_12 . V_10 == - 1 || V_13 . V_11 > V_12 . V_11 )
V_12 = V_13 ;
}
if ( V_12 . V_10 != - 1 && V_12 . V_11 < 2 )
V_12 . V_10 = - 1 ;
V_9 = V_6 ;
for ( V_17 = 0 ; V_17 < ( V_15 / V_16 ) ; V_17 ++ ) {
if ( V_12 . V_10 != - 1 && V_17 >= V_12 . V_10 &&
V_17 < ( V_12 . V_10 + V_12 . V_11 ) ) {
if ( V_17 == V_12 . V_10 )
* V_9 ++ = ':' ;
continue;
}
if ( V_17 != 0 )
* V_9 ++ = ':' ;
if ( V_17 == 6 && V_12 . V_10 == 0 &&
( V_12 . V_11 == 6 || ( V_12 . V_11 == 5 && V_14 [ 5 ] == 0xffff ) ) ) {
if ( ! F_2 ( T_2 + 12 , V_9 , sizeof V_6 - ( V_9 - V_6 ) ) )
return ( NULL ) ;
V_9 += strlen ( V_9 ) ;
break;
}
V_9 += F_4 ( V_9 , ( V_18 ) ( sizeof V_6 - ( V_9 - V_6 ) ) , L_2 , V_14 [ V_17 ] ) ;
}
if ( V_12 . V_10 != - 1 && ( V_12 . V_10 + V_12 . V_11 ) ==
( V_15 / V_16 ) )
* V_9 ++ = ':' ;
* V_9 ++ = '\0' ;
if ( ( T_5 ) ( V_9 - V_6 ) > T_4 ) {
V_3 = V_8 ;
return ( NULL ) ;
}
F_5 ( T_3 , V_6 , T_4 ) ;
return ( T_3 ) ;
}
