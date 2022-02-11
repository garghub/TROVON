char * F_1 ( const T_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 = 0 ;
char * V_6 ;
char * V_7 ;
if ( V_1 -> V_8 && F_2 ( V_1 ) ) {
V_6 = F_3 ( 3 ) ;
} else {
V_6 = F_3 ( V_1 -> V_9 * V_10 * 2 + 2 ) ;
}
if ( V_6 == NULL ) {
F_4 ( V_11 , V_12 ) ;
goto V_13;
}
V_7 = V_6 ;
if ( V_1 -> V_8 )
* ( V_7 ++ ) = '-' ;
if ( F_2 ( V_1 ) )
* ( V_7 ++ ) = '0' ;
for ( V_2 = V_1 -> V_9 - 1 ; V_2 >= 0 ; V_2 -- ) {
for ( V_3 = V_14 - 8 ; V_3 >= 0 ; V_3 -= 8 ) {
V_4 = ( ( int ) ( V_1 -> V_15 [ V_2 ] >> ( long ) V_3 ) ) & 0xff ;
if ( V_5 || ( V_4 != 0 ) ) {
* ( V_7 ++ ) = V_16 [ V_4 >> 4 ] ;
* ( V_7 ++ ) = V_16 [ V_4 & 0x0f ] ;
V_5 = 1 ;
}
}
}
* V_7 = '\0' ;
V_13:
return ( V_6 ) ;
}
char * F_5 ( const T_1 * V_1 )
{
int V_2 = 0 , V_17 , V_18 = 0 ;
char * V_6 = NULL ;
char * V_7 ;
T_1 * V_19 = NULL ;
T_2 * V_20 = NULL , * V_21 ;
int V_22 ;
V_2 = F_6 ( V_1 ) * 3 ;
V_17 = ( V_2 / 10 + V_2 / 1000 + 1 ) + 1 ;
V_22 = V_17 / V_23 + 1 ;
V_20 = F_3 ( V_22 * sizeof( T_2 ) ) ;
V_6 = F_3 ( V_17 + 3 ) ;
if ( ( V_6 == NULL ) || ( V_20 == NULL ) ) {
F_4 ( V_24 , V_12 ) ;
goto V_13;
}
if ( ( V_19 = F_7 ( V_1 ) ) == NULL )
goto V_13;
#define F_8 (num+3 - (size_t)(p - buf))
V_7 = V_6 ;
V_21 = V_20 ;
if ( F_2 ( V_19 ) ) {
* ( V_7 ++ ) = '0' ;
* ( V_7 ++ ) = '\0' ;
} else {
if ( F_9 ( V_19 ) )
* V_7 ++ = '-' ;
while ( ! F_2 ( V_19 ) ) {
if ( V_21 - V_20 >= V_22 )
goto V_13;
* V_21 = F_10 ( V_19 , V_25 ) ;
if ( * V_21 == ( T_2 ) - 1 )
goto V_13;
V_21 ++ ;
}
V_21 -- ;
F_11 ( V_7 , F_8 , V_26 , * V_21 ) ;
while ( * V_7 )
V_7 ++ ;
while ( V_21 != V_20 ) {
V_21 -- ;
F_11 ( V_7 , F_8 , V_27 , * V_21 ) ;
while ( * V_7 )
V_7 ++ ;
}
}
V_18 = 1 ;
V_13:
F_12 ( V_20 ) ;
F_13 ( V_19 ) ;
if ( V_18 )
return V_6 ;
F_12 ( V_6 ) ;
return NULL ;
}
int F_14 ( T_1 * * V_28 , const char * V_1 )
{
T_1 * V_29 = NULL ;
T_2 V_30 = 0 ;
int V_8 = 0 , V_31 , V_32 , V_2 , V_3 , V_33 , V_34 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) )
return ( 0 ) ;
if ( * V_1 == '-' ) {
V_8 = 1 ;
V_1 ++ ;
}
for ( V_2 = 0 ; V_2 <= ( V_35 / 4 ) && isxdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
continue;
if ( V_2 == 0 || V_2 > V_35 / 4 )
goto V_13;
V_17 = V_2 + V_8 ;
if ( V_28 == NULL )
return ( V_17 ) ;
if ( * V_28 == NULL ) {
if ( ( V_29 = F_15 () ) == NULL )
return ( 0 ) ;
} else {
V_29 = * V_28 ;
F_16 ( V_29 ) ;
}
if ( F_17 ( V_29 , V_2 * 4 ) == NULL )
goto V_13;
V_3 = V_2 ;
V_32 = 0 ;
V_31 = 0 ;
while ( V_3 > 0 ) {
V_32 = ( ( V_10 * 2 ) <= V_3 ) ? ( V_10 * 2 ) : V_3 ;
V_30 = 0 ;
for (; ; ) {
V_34 = V_1 [ V_3 - V_32 ] ;
V_33 = F_18 ( V_34 ) ;
if ( V_33 < 0 )
V_33 = 0 ;
V_30 = ( V_30 << 4 ) | V_33 ;
if ( -- V_32 <= 0 ) {
V_29 -> V_15 [ V_31 ++ ] = V_30 ;
break;
}
}
V_3 -= ( V_10 * 2 ) ;
}
V_29 -> V_9 = V_31 ;
F_19 ( V_29 ) ;
V_29 -> V_8 = V_8 ;
* V_28 = V_29 ;
F_20 ( V_29 ) ;
return ( V_17 ) ;
V_13:
if ( * V_28 == NULL )
F_13 ( V_29 ) ;
return ( 0 ) ;
}
int F_21 ( T_1 * * V_28 , const char * V_1 )
{
T_1 * V_29 = NULL ;
T_2 V_30 = 0 ;
int V_8 = 0 , V_2 , V_3 ;
int V_17 ;
if ( ( V_1 == NULL ) || ( * V_1 == '\0' ) )
return ( 0 ) ;
if ( * V_1 == '-' ) {
V_8 = 1 ;
V_1 ++ ;
}
for ( V_2 = 0 ; V_2 <= ( V_35 / 4 ) && isdigit ( ( unsigned char ) V_1 [ V_2 ] ) ; V_2 ++ )
continue;
if ( V_2 == 0 || V_2 > V_35 / 4 )
goto V_13;
V_17 = V_2 + V_8 ;
if ( V_28 == NULL )
return ( V_17 ) ;
if ( * V_28 == NULL ) {
if ( ( V_29 = F_15 () ) == NULL )
return ( 0 ) ;
} else {
V_29 = * V_28 ;
F_16 ( V_29 ) ;
}
if ( F_17 ( V_29 , V_2 * 4 ) == NULL )
goto V_13;
V_3 = V_23 - ( V_2 % V_23 ) ;
if ( V_3 == V_23 )
V_3 = 0 ;
V_30 = 0 ;
while ( * V_1 ) {
V_30 *= 10 ;
V_30 += * V_1 - '0' ;
V_1 ++ ;
if ( ++ V_3 == V_23 ) {
if ( ! F_22 ( V_29 , V_25 )
|| ! F_23 ( V_29 , V_30 ) )
goto V_13;
V_30 = 0 ;
V_3 = 0 ;
}
}
V_29 -> V_8 = V_8 ;
F_19 ( V_29 ) ;
* V_28 = V_29 ;
F_20 ( V_29 ) ;
return ( V_17 ) ;
V_13:
if ( * V_28 == NULL )
F_13 ( V_29 ) ;
return ( 0 ) ;
}
int F_24 ( T_1 * * V_28 , const char * V_1 )
{
const char * V_7 = V_1 ;
if ( * V_7 == '-' )
V_7 ++ ;
if ( V_7 [ 0 ] == '0' && ( V_7 [ 1 ] == 'X' || V_7 [ 1 ] == 'x' ) ) {
if ( ! F_14 ( V_28 , V_7 + 2 ) )
return 0 ;
} else {
if ( ! F_21 ( V_28 , V_7 ) )
return 0 ;
}
if ( * V_1 == '-' )
( * V_28 ) -> V_8 = 1 ;
return 1 ;
}
int F_25 ( T_3 * V_36 , const T_1 * V_1 )
{
T_4 * V_37 ;
int V_29 ;
if ( ( V_37 = F_26 ( F_27 () ) ) == NULL )
return ( 0 ) ;
F_28 ( V_37 , V_36 , V_38 ) ;
V_29 = F_29 ( V_37 , V_1 ) ;
F_30 ( V_37 ) ;
return ( V_29 ) ;
}
int F_29 ( T_4 * V_39 , const T_1 * V_1 )
{
int V_2 , V_3 , V_4 , V_5 = 0 ;
int V_29 = 0 ;
if ( ( V_1 -> V_8 ) && ( F_31 ( V_39 , L_1 , 1 ) != 1 ) )
goto V_40;
if ( F_2 ( V_1 ) && ( F_31 ( V_39 , L_2 , 1 ) != 1 ) )
goto V_40;
for ( V_2 = V_1 -> V_9 - 1 ; V_2 >= 0 ; V_2 -- ) {
for ( V_3 = V_14 - 4 ; V_3 >= 0 ; V_3 -= 4 ) {
V_4 = ( ( int ) ( V_1 -> V_15 [ V_2 ] >> ( long ) V_3 ) ) & 0x0f ;
if ( V_5 || ( V_4 != 0 ) ) {
if ( F_31 ( V_39 , & ( V_16 [ V_4 ] ) , 1 ) != 1 )
goto V_40;
V_5 = 1 ;
}
}
}
V_29 = 1 ;
V_40:
return ( V_29 ) ;
}
char * F_32 ( void )
{
static int V_41 = 0 ;
static char V_42 [ 16 ] ;
if ( ! V_41 ) {
V_41 ++ ;
#ifdef F_33
F_11 ( V_42 , sizeof V_42 , L_3 ,
( int ) sizeof( V_43 ) * 8 , ( int ) sizeof( T_2 ) * 8 ) ;
#else
F_11 ( V_42 , sizeof V_42 , L_3 ,
( int ) sizeof( T_2 ) * 8 , ( int ) sizeof( T_2 ) * 8 ) ;
#endif
}
return ( V_42 ) ;
}
