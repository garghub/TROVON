int F_1 ( const unsigned char * V_1 , int V_2 )
{
int V_3 ;
int V_4 = 0 ;
int V_5 = 0 ;
if ( V_2 <= 0 )
V_2 = - 1 ;
if ( V_1 == NULL )
return ( V_6 ) ;
while ( ( * V_1 ) && ( V_2 -- != 0 ) ) {
V_3 = * ( V_1 ++ ) ;
#ifndef F_2
if ( ! ( ( ( V_3 >= 'a' ) && ( V_3 <= 'z' ) ) ||
( ( V_3 >= 'A' ) && ( V_3 <= 'Z' ) ) ||
( ( V_3 >= '0' ) && ( V_3 <= '9' ) ) ||
( V_3 == ' ' ) || ( V_3 == '\'' ) ||
( V_3 == '(' ) || ( V_3 == ')' ) ||
( V_3 == '+' ) || ( V_3 == ',' ) ||
( V_3 == '-' ) || ( V_3 == '.' ) ||
( V_3 == '/' ) || ( V_3 == ':' ) || ( V_3 == '=' ) || ( V_3 == '?' ) ) )
V_4 = 1 ;
if ( V_3 & 0x80 )
V_5 = 1 ;
#else
if ( ! isalnum ( V_3 ) && ( V_3 != ' ' ) && strchr ( L_1 , V_3 ) == NULL )
V_4 = 1 ;
if ( V_7 [ V_3 ] & 0x80 )
V_5 = 1 ;
#endif
}
if ( V_5 )
return ( V_8 ) ;
if ( V_4 )
return ( V_9 ) ;
return ( V_6 ) ;
}
int F_3 ( T_1 * V_1 )
{
int V_10 ;
unsigned char * V_11 ;
if ( V_1 -> type != V_12 )
return ( 0 ) ;
if ( ( V_1 -> V_13 % 4 ) != 0 )
return ( 0 ) ;
V_11 = V_1 -> V_14 ;
for ( V_10 = 0 ; V_10 < V_1 -> V_13 ; V_10 += 4 ) {
if ( ( V_11 [ 0 ] != '\0' ) || ( V_11 [ 1 ] != '\0' ) || ( V_11 [ 2 ] != '\0' ) )
break;
else
V_11 += 4 ;
}
if ( V_10 < V_1 -> V_13 )
return ( 0 ) ;
V_11 = V_1 -> V_14 ;
for ( V_10 = 3 ; V_10 < V_1 -> V_13 ; V_10 += 4 ) {
* ( V_11 ++ ) = V_1 -> V_14 [ V_10 ] ;
}
* ( V_11 ) = '\0' ;
V_1 -> V_13 /= 4 ;
V_1 -> type = F_1 ( V_1 -> V_14 , V_1 -> V_13 ) ;
return ( 1 ) ;
}
int F_4 ( T_2 * V_15 , const T_3 * V_16 )
{
int V_10 , V_17 ;
char V_18 [ 80 ] ;
const char * V_11 ;
if ( V_16 == NULL )
return ( 0 ) ;
V_17 = 0 ;
V_11 = ( const char * ) V_16 -> V_14 ;
for ( V_10 = 0 ; V_10 < V_16 -> V_13 ; V_10 ++ ) {
if ( ( V_11 [ V_10 ] > '~' ) || ( ( V_11 [ V_10 ] < ' ' ) &&
( V_11 [ V_10 ] != '\n' ) && ( V_11 [ V_10 ] != '\r' ) ) )
V_18 [ V_17 ] = '.' ;
else
V_18 [ V_17 ] = V_11 [ V_10 ] ;
V_17 ++ ;
if ( V_17 >= 80 ) {
if ( F_5 ( V_15 , V_18 , V_17 ) <= 0 )
return ( 0 ) ;
V_17 = 0 ;
}
}
if ( V_17 > 0 )
if ( F_5 ( V_15 , V_18 , V_17 ) <= 0 )
return ( 0 ) ;
return ( 1 ) ;
}
