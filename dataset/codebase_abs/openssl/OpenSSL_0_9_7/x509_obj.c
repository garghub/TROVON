char * F_1 ( T_1 * V_1 , char * V_2 , int V_3 )
{
T_2 * V_4 ;
int V_5 ;
int V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , type ;
const char * V_13 ;
char * V_14 ;
unsigned char * V_15 ;
T_3 * V_16 = NULL ;
static char V_17 [ 17 ] = L_1 ;
int V_18 [ 4 ] ;
char V_19 [ 80 ] ;
#ifdef F_2
char V_20 [ 1024 ] ;
#endif
if ( V_2 == NULL )
{
if ( ( V_16 = F_3 () ) == NULL ) goto V_21;
if ( ! F_4 ( V_16 , 200 ) ) goto V_21;
V_16 -> V_22 [ 0 ] = '\0' ;
V_3 = 200 ;
}
if ( V_1 == NULL )
{
if( V_16 )
{
V_2 = V_16 -> V_22 ;
F_5 ( V_16 ) ;
}
strncpy ( V_2 , L_2 , V_3 ) ;
V_2 [ V_3 - 1 ] = '\0' ;
return V_2 ;
}
V_3 -- ;
V_8 = 0 ;
for ( V_5 = 0 ; V_5 < F_6 ( V_1 -> V_23 ) ; V_5 ++ )
{
V_4 = F_7 ( V_1 -> V_23 , V_5 ) ;
V_6 = F_8 ( V_4 -> V_24 ) ;
if ( ( V_6 == V_25 ) || ( ( V_13 = F_9 ( V_6 ) ) == NULL ) )
{
F_10 ( V_19 , sizeof( V_19 ) , V_4 -> V_24 ) ;
V_13 = V_19 ;
}
V_9 = strlen ( V_13 ) ;
type = V_4 -> V_26 -> type ;
V_11 = V_4 -> V_26 -> V_27 ;
V_15 = V_4 -> V_26 -> V_22 ;
#ifdef F_2
if ( type == V_28 ||
type == V_29 ||
type == V_30 ||
type == V_31 ||
type == V_29 ||
type == V_32 ) {
F_11 ( V_20 , V_15 ,
( V_11 > sizeof V_20 )
? sizeof V_20 : V_11 ) ;
V_15 = V_20 ;
}
#endif
if ( ( type == V_28 ) && ( ( V_11 % 4 ) == 0 ) )
{
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 0 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
if ( V_15 [ V_12 ] != 0 ) V_18 [ V_12 & 3 ] = 1 ;
if ( V_18 [ 0 ] | V_18 [ 1 ] | V_18 [ 2 ] )
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 1 ;
else
{
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = 0 ;
V_18 [ 3 ] = 1 ;
}
}
else
V_18 [ 0 ] = V_18 [ 1 ] = V_18 [ 2 ] = V_18 [ 3 ] = 1 ;
for ( V_10 = V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
{
if ( ! V_18 [ V_12 & 3 ] ) continue;
V_10 ++ ;
#ifndef F_2
if ( ( V_15 [ V_12 ] < ' ' ) || ( V_15 [ V_12 ] > '~' ) ) V_10 += 3 ;
#else
if ( ( V_33 [ V_15 [ V_12 ] ] < V_33 [ ' ' ] ) ||
( V_33 [ V_15 [ V_12 ] ] > V_33 [ '~' ] ) ) V_10 += 3 ;
#endif
}
V_7 = V_8 ;
V_8 += 1 + V_9 + 1 + V_10 ;
if ( V_16 != NULL )
{
if ( ! F_4 ( V_16 , V_8 + 1 ) ) goto V_21;
V_14 = & ( V_16 -> V_22 [ V_7 ] ) ;
}
else if ( V_8 > V_3 )
{
break;
}
else
V_14 = & ( V_2 [ V_7 ] ) ;
* ( V_14 ++ ) = '/' ;
memcpy ( V_14 , V_13 , ( unsigned int ) V_9 ) ; V_14 += V_9 ;
* ( V_14 ++ ) = '=' ;
#ifndef F_2
V_15 = V_4 -> V_26 -> V_22 ;
#endif
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ )
{
if ( ! V_18 [ V_12 & 3 ] ) continue;
#ifndef F_2
V_6 = V_15 [ V_12 ] ;
if ( ( V_6 < ' ' ) || ( V_6 > '~' ) )
{
* ( V_14 ++ ) = '\\' ;
* ( V_14 ++ ) = 'x' ;
* ( V_14 ++ ) = V_17 [ ( V_6 >> 4 ) & 0x0f ] ;
* ( V_14 ++ ) = V_17 [ V_6 & 0x0f ] ;
}
else
* ( V_14 ++ ) = V_6 ;
#else
V_6 = V_33 [ V_15 [ V_12 ] ] ;
if ( ( V_6 < V_33 [ ' ' ] ) ||
( V_6 > V_33 [ '~' ] ) )
{
* ( V_14 ++ ) = '\\' ;
* ( V_14 ++ ) = 'x' ;
* ( V_14 ++ ) = V_17 [ ( V_6 >> 4 ) & 0x0f ] ;
* ( V_14 ++ ) = V_17 [ V_6 & 0x0f ] ;
}
else
* ( V_14 ++ ) = V_15 [ V_12 ] ;
#endif
}
* V_14 = '\0' ;
}
if ( V_16 != NULL )
{
V_14 = V_16 -> V_22 ;
F_5 ( V_16 ) ;
}
else
V_14 = V_2 ;
if ( V_5 == 0 )
* V_14 = '\0' ;
return ( V_14 ) ;
V_21:
F_12 ( V_34 , V_35 ) ;
if ( V_16 != NULL ) F_13 ( V_16 ) ;
return ( NULL ) ;
}
