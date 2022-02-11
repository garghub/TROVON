void F_1 ( void )
{
static int V_1 = 0 ;
T_1 V_2 ( unsigned int * ) ;
T_1 V_3 ;
char * V_4 ;
if ( V_1 )
return;
V_1 = 1 ;
if ( ( V_4 = getenv ( L_1 ) ) ) {
int V_5 = ( V_4 [ 0 ] == '~' ) ? 1 : 0 ;
# if F_2 ( V_6 )
if ( ! sscanf ( V_4 + V_5 , L_2 , & V_3 ) )
V_3 = strtoul ( V_4 + V_5 , NULL , 0 ) ;
# else
if ( ! sscanf ( V_4 + V_5 , L_3 , ( long long * ) & V_3 ) )
V_3 = strtoul ( V_4 + V_5 , NULL , 0 ) ;
# endif
if ( V_5 )
V_3 = V_2 ( V_7 ) & ~ V_3 ;
else if ( V_4 [ 0 ] == ':' )
V_3 = V_2 ( V_7 ) ;
V_7 [ 2 ] = 0 ;
if ( ( V_4 = strchr ( V_4 , ':' ) ) ) {
unsigned int V_8 ;
V_4 ++ ;
V_5 = ( V_4 [ 0 ] == '~' ) ? 1 : 0 ;
V_8 = strtoul ( V_4 + V_5 , NULL , 0 ) ;
if ( V_5 )
V_7 [ 2 ] &= ~ V_8 ;
else
V_7 [ 2 ] = V_8 ;
}
} else
V_3 = V_2 ( V_7 ) ;
V_7 [ 0 ] = ( unsigned int ) V_3 | ( 1 << 10 ) ;
V_7 [ 1 ] = ( unsigned int ) ( V_3 >> 32 ) ;
}
void F_1 ( void )
{
}
int F_3 ( void )
{
T_2 V_9 ;
T_3 V_10 ;
T_4 * V_11 ;
static union {
void * V_12 ;
T_5 V_13 ;
} V_14 = {
NULL
} ;
if ( V_14 . V_12 == NULL ) {
T_6 V_15 = F_4 ( NULL ) ;
if ( V_15 != NULL )
V_14 . V_13 = F_5 ( V_15 , L_4 ) ;
if ( V_14 . V_12 == NULL )
V_14 . V_12 = ( void * ) - 1 ;
}
if ( V_14 . V_12 != ( void * ) - 1 )
return (* V_14 . V_13 ) () ;
V_9 = F_6 () ;
if ( V_9 == NULL )
return - 1 ;
if ( F_7 ( V_9 , V_16 , NULL , 0 , & V_10 ) ||
F_8 () != V_17 )
return - 1 ;
if ( V_10 > 512 )
return - 1 ;
V_10 ++ , V_10 &= ~ 1 ;
V_11 = ( T_4 * ) F_9 ( V_10 + sizeof( T_4 ) ) ;
if ( ! F_7 ( V_9 , V_16 , V_11 , V_10 , & V_10 ) )
return - 1 ;
V_10 ++ , V_10 &= ~ 1 ;
V_11 [ V_10 / sizeof( T_4 ) ] = V_18 '\0' ;
# if 1
if ( wcsstr ( V_11 , L_5 ) )
return 1 ;
# else
if ( ! wcsstr ( V_11 , L_6 ) )
return 1 ;
# endif
else
return 0 ;
}
int F_3 ( void )
{
return 0 ;
}
void F_10 ( const char * V_19 , ... )
{
T_7 V_20 ;
T_8 V_21 [ 256 ] ;
const T_8 * V_22 ;
# ifdef F_11
T_6 V_9 ;
if ( ( V_9 = F_12 ( F_11 ) ) != NULL &&
F_13 ( V_9 ) != V_23 ) {
int V_10 ;
T_3 V_24 ;
va_start ( V_20 , V_19 ) ;
V_10 = F_14 ( ( char * ) V_21 , sizeof( V_21 ) , V_19 , V_20 ) ;
F_15 ( V_9 , V_21 , V_10 < 0 ? sizeof( V_21 ) : ( T_3 ) V_10 , & V_24 , NULL ) ;
va_end ( V_20 ) ;
return;
}
# endif
if ( sizeof( T_8 ) == sizeof( char ) )
V_22 = ( const T_8 * ) V_19 ;
else
do {
int V_25 ;
T_9 V_26 = strlen ( V_19 ) + 1 , V_27 ;
T_4 * V_28 ;
V_28 = ( T_4 * ) F_9 ( V_26 * sizeof( T_4 ) ) ;
if ( V_28 == NULL ) {
V_22 = ( const T_8 * ) L_7 ;
break;
}
if ( ! F_16 ( V_29 , 0 , V_19 , V_26 , V_28 , V_26 ) )
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
V_28 [ V_27 ] = ( T_4 ) V_19 [ V_27 ] ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( V_28 [ V_27 ] == V_18 '%' )
do {
V_25 = 0 ;
switch ( V_28 [ V_27 + 1 ] ) {
case V_18 '0' :
case V_18 '1' :
case V_18 '2' :
case V_18 '3' :
case V_18 '4' :
case V_18 '5' :
case V_18 '6' :
case V_18 '7' :
case V_18 '8' :
case V_18 '9' :
case V_18 '.' :
case V_18 '*' :
case V_18 '-' :
V_27 ++ ;
V_25 = 1 ;
break;
case V_18 's' :
V_28 [ V_27 + 1 ] = V_18 'S' ;
break;
case V_18 'S' :
V_28 [ V_27 + 1 ] = V_18 's' ;
break;
case V_18 'c' :
V_28 [ V_27 + 1 ] = V_18 'C' ;
break;
case V_18 'C' :
V_28 [ V_27 + 1 ] = V_18 'c' ;
break;
}
} while ( V_25 );
}
V_22 = ( const T_8 * ) V_28 ;
} while ( 0 );
va_start ( V_20 , V_19 ) ;
F_17 ( V_21 , F_18 ( V_21 ) - 1 , V_22 , V_20 ) ;
V_21 [ F_18 ( V_21 ) - 1 ] = F_19 ( '\0' ) ;
va_end ( V_20 ) ;
# if F_2 ( V_30 ) && V_30 >= 0x0333
if ( F_20 () && F_3 () > 0 ) {
T_6 V_31 = F_21 ( NULL , F_19 ( L_8 ) ) ;
if ( V_31 != NULL ) {
const T_8 * V_32 = V_21 ;
if ( ! F_22 ( V_31 , V_33 , 0 , 0 , NULL ,
1 , 0 , & V_32 , NULL ) ) {
#if F_2 ( V_34 )
F_23 ( V_32 ) ;
#endif
}
( void ) F_24 ( V_31 ) ;
}
} else
# endif
F_25 ( NULL , V_21 , F_19 ( L_9 ) , V_35 | V_36 ) ;
}
void F_10 ( const char * V_19 , ... )
{
#ifndef F_26
T_7 V_20 ;
va_start ( V_20 , V_19 ) ;
vfprintf ( V_37 , V_19 , V_20 ) ;
va_end ( V_20 ) ;
#endif
}
int F_3 ( void )
{
return 0 ;
}
void F_27 ( const char * V_38 , const char * V_39 , int line )
{
F_10 ( L_10 ,
V_39 , line , V_38 ) ;
#if ! F_2 ( V_6 ) || F_2 ( V_40 )
abort () ;
#else
# if ! F_2 ( V_41 )
raise ( V_42 ) ;
# endif
F_28 ( 3 ) ;
#endif
}
int F_29 ( const volatile void * volatile V_43 ,
const volatile void * volatile V_44 ,
T_9 V_10 )
{
T_9 V_27 ;
const volatile unsigned char * V_45 = V_43 ;
const volatile unsigned char * V_46 = V_44 ;
unsigned char V_47 = 0 ;
for ( V_27 = 0 ; V_27 < V_10 ; V_27 ++ )
V_47 |= V_45 [ V_27 ] ^ V_46 [ V_27 ] ;
return V_47 ;
}
