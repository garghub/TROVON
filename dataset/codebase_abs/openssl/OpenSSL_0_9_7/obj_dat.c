static int F_1 ( const void * V_1 , const void * V_2 )
{
const T_1 * const * V_3 = V_1 , * const * V_4 = V_2 ;
return ( strcmp ( ( * V_3 ) -> V_5 , ( * V_4 ) -> V_5 ) ) ;
}
static int F_2 ( const void * V_1 , const void * V_2 )
{
const T_1 * const * V_3 = V_1 , * const * V_4 = V_2 ;
return ( strcmp ( ( * V_3 ) -> V_6 , ( * V_4 ) -> V_6 ) ) ;
}
static unsigned long F_3 ( const void * V_7 )
{
const T_1 * V_1 ;
int V_8 ;
unsigned long V_9 = 0 ;
unsigned char * V_10 ;
T_2 * V_11 = ( T_2 * ) V_7 ;
V_1 = V_11 -> V_12 ;
switch ( V_11 -> type )
{
case V_13 :
V_9 = V_1 -> V_14 << 20L ;
V_10 = ( unsigned char * ) V_1 -> V_15 ;
for ( V_8 = 0 ; V_8 < V_1 -> V_14 ; V_8 ++ )
V_9 ^= V_10 [ V_8 ] << ( ( V_8 * 3 ) % 24 ) ;
break;
case V_16 :
V_9 = F_4 ( V_1 -> V_5 ) ;
break;
case V_17 :
V_9 = F_4 ( V_1 -> V_6 ) ;
break;
case V_18 :
V_9 = V_1 -> V_19 ;
break;
default:
return 0 ;
}
V_9 &= 0x3fffffffL ;
V_9 |= V_11 -> type << 30L ;
return ( V_9 ) ;
}
static int F_5 ( const void * V_7 , const void * V_20 )
{
T_1 * V_1 , * V_2 ;
int V_8 ;
T_2 * V_11 = ( T_2 * ) V_7 ;
T_2 * V_21 = ( T_2 * ) V_20 ;
V_8 = V_11 -> type - V_21 -> type ;
if ( V_8 ) return ( V_8 ) ;
V_1 = V_11 -> V_12 ;
V_2 = V_21 -> V_12 ;
switch ( V_11 -> type )
{
case V_13 :
V_8 = ( V_1 -> V_14 - V_2 -> V_14 ) ;
if ( V_8 ) return ( V_8 ) ;
return ( memcmp ( V_1 -> V_15 , V_2 -> V_15 , V_1 -> V_14 ) ) ;
case V_16 :
if ( V_1 -> V_5 == NULL ) return ( - 1 ) ;
else if ( V_2 -> V_5 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_1 -> V_5 , V_2 -> V_5 ) ) ;
case V_17 :
if ( V_1 -> V_6 == NULL ) return ( - 1 ) ;
else if ( V_2 -> V_6 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_1 -> V_6 , V_2 -> V_6 ) ) ;
case V_18 :
return ( V_1 -> V_19 - V_2 -> V_19 ) ;
default:
return 0 ;
}
}
static int F_6 ( void )
{
if ( V_22 != NULL ) return ( 1 ) ;
V_22 = F_7 ( F_3 , F_5 ) ;
return ( V_22 != NULL ) ;
}
static void F_8 ( T_2 * V_1 )
{
V_1 -> V_12 -> V_19 = 0 ;
V_1 -> V_12 -> V_23 |= V_24 |
V_25 |
V_26 ;
}
static void F_9 ( T_2 * V_1 )
{ V_1 -> V_12 -> V_19 ++ ; }
static void F_10 ( T_2 * V_1 )
{
if ( -- V_1 -> V_12 -> V_19 == 0 )
F_11 ( V_1 -> V_12 ) ;
F_12 ( V_1 ) ;
}
int F_13 ( const T_1 * V_12 )
{
T_1 * V_27 ;
T_2 * V_28 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_29 ;
int V_8 ;
if ( V_22 == NULL )
if ( ! F_6 () ) return ( 0 ) ;
if ( ( V_27 = F_14 ( V_12 ) ) == NULL ) goto V_30;
if ( ! ( V_28 [ V_18 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ) ) goto V_30;
if ( ( V_27 -> V_14 != 0 ) && ( V_12 -> V_15 != NULL ) )
V_28 [ V_13 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ;
if ( V_27 -> V_5 != NULL )
V_28 [ V_16 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ;
if ( V_27 -> V_6 != NULL )
V_28 [ V_17 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ;
for ( V_8 = V_13 ; V_8 <= V_18 ; V_8 ++ )
{
if ( V_28 [ V_8 ] != NULL )
{
V_28 [ V_8 ] -> type = V_8 ;
V_28 [ V_8 ] -> V_12 = V_27 ;
V_29 = ( T_2 * ) F_16 ( V_22 , V_28 [ V_8 ] ) ;
if ( V_29 != NULL )
F_12 ( V_29 ) ;
}
}
V_27 -> V_23 &= ~ ( V_24 | V_25 |
V_26 ) ;
return ( V_27 -> V_19 ) ;
V_30:
for ( V_8 = V_13 ; V_8 <= V_18 ; V_8 ++ )
if ( V_28 [ V_8 ] != NULL ) F_12 ( V_28 [ V_8 ] ) ;
if ( V_27 != NULL ) F_12 ( V_27 ) ;
return ( V_31 ) ;
}
T_1 * F_17 ( int V_32 )
{
T_2 V_33 , * V_34 ;
T_1 V_35 ;
if ( ( V_32 >= 0 ) && ( V_32 < V_36 ) )
{
if ( ( V_32 != V_31 ) && ( V_37 [ V_32 ] . V_19 == V_31 ) )
{
F_18 ( V_38 , V_39 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_37 [ V_32 ] ) ) ;
}
else if ( V_22 == NULL )
return ( NULL ) ;
else
{
V_33 . type = V_18 ;
V_33 . V_12 = & V_35 ;
V_35 . V_19 = V_32 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL )
return ( V_34 -> V_12 ) ;
else
{
F_18 ( V_38 , V_39 ) ;
return ( NULL ) ;
}
}
}
const char * F_20 ( int V_32 )
{
T_2 V_33 , * V_34 ;
T_1 V_35 ;
if ( ( V_32 >= 0 ) && ( V_32 < V_36 ) )
{
if ( ( V_32 != V_31 ) && ( V_37 [ V_32 ] . V_19 == V_31 ) )
{
F_18 ( V_40 , V_39 ) ;
return ( NULL ) ;
}
return ( V_37 [ V_32 ] . V_5 ) ;
}
else if ( V_22 == NULL )
return ( NULL ) ;
else
{
V_33 . type = V_18 ;
V_33 . V_12 = & V_35 ;
V_35 . V_19 = V_32 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL )
return ( V_34 -> V_12 -> V_5 ) ;
else
{
F_18 ( V_40 , V_39 ) ;
return ( NULL ) ;
}
}
}
const char * F_21 ( int V_32 )
{
T_2 V_33 , * V_34 ;
T_1 V_35 ;
if ( ( V_32 >= 0 ) && ( V_32 < V_36 ) )
{
if ( ( V_32 != V_31 ) && ( V_37 [ V_32 ] . V_19 == V_31 ) )
{
F_18 ( V_41 , V_39 ) ;
return ( NULL ) ;
}
return ( V_37 [ V_32 ] . V_6 ) ;
}
else if ( V_22 == NULL )
return ( NULL ) ;
else
{
V_33 . type = V_18 ;
V_33 . V_12 = & V_35 ;
V_35 . V_19 = V_32 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL )
return ( V_34 -> V_12 -> V_6 ) ;
else
{
F_18 ( V_41 , V_39 ) ;
return ( NULL ) ;
}
}
}
int F_22 ( const T_1 * V_1 )
{
T_1 * * V_42 ;
T_2 V_33 , * V_34 ;
if ( V_1 == NULL )
return ( V_31 ) ;
if ( V_1 -> V_19 != 0 )
return ( V_1 -> V_19 ) ;
if ( V_22 != NULL )
{
V_33 . type = V_13 ;
V_33 . V_12 = ( T_1 * ) V_1 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL ) return ( V_34 -> V_12 -> V_19 ) ;
}
V_42 = ( T_1 * * ) F_23 ( ( char * ) & V_1 , ( char * ) V_43 , V_44 ,
sizeof( T_1 * ) , V_45 ) ;
if ( V_42 == NULL )
return ( V_31 ) ;
return ( ( * V_42 ) -> V_19 ) ;
}
T_1 * F_24 ( const char * V_46 , int V_47 )
{
int V_19 = V_31 ;
T_1 * V_42 = NULL ;
unsigned char * V_48 , * V_10 ;
int V_8 , V_49 ;
if( ! V_47 ) {
if( ( ( V_19 = F_25 ( V_46 ) ) != V_31 ) ||
( ( V_19 = F_26 ( V_46 ) ) != V_31 ) )
return F_17 ( V_19 ) ;
}
V_8 = F_27 ( NULL , 0 , V_46 , - 1 ) ;
if ( V_8 <= 0 ) {
F_28 () ;
return NULL ;
}
V_49 = F_29 ( 0 , V_8 , V_50 ) ;
if( ( V_48 = ( unsigned char * ) F_15 ( V_49 ) ) == NULL ) return NULL ;
V_10 = V_48 ;
F_30 ( & V_10 , 0 , V_8 , V_50 , V_51 ) ;
F_27 ( V_10 , V_8 , V_46 , - 1 ) ;
V_10 = V_48 ;
V_42 = F_31 ( NULL , & V_10 , V_49 ) ;
F_12 ( V_48 ) ;
return V_42 ;
}
int F_32 ( char * V_48 , int V_52 , const T_1 * V_1 , int V_47 )
{
int V_8 , V_53 = 0 , V_32 = 0 , V_54 , V_19 ;
unsigned long V_55 ;
unsigned char * V_10 ;
const char * V_46 ;
char V_56 [ F_33 ( V_8 ) + F_33 ( V_55 ) + 2 ] ;
if ( V_52 <= 0 ) return ( 0 ) ;
if ( ( V_1 == NULL ) || ( V_1 -> V_15 == NULL ) ) {
V_48 [ 0 ] = '\0' ;
return ( 0 ) ;
}
if ( V_47 || ( V_19 = F_22 ( V_1 ) ) == V_31 ) {
V_54 = V_1 -> V_14 ;
V_10 = V_1 -> V_15 ;
V_53 = 0 ;
V_55 = 0 ;
while ( V_53 < V_1 -> V_14 ) {
V_55 |= ( V_10 [ V_53 ] & 0x7f ) ;
if ( ! ( V_10 [ V_53 ] & 0x80 ) ) break;
V_55 <<= 7L ;
V_53 ++ ;
}
V_53 ++ ;
V_8 = ( int ) ( V_55 / 40 ) ;
if ( V_8 > 2 ) V_8 = 2 ;
V_55 -= ( long ) ( V_8 * 40 ) ;
sprintf ( V_56 , L_1 , V_8 , V_55 ) ;
V_8 = strlen ( V_56 ) ;
F_34 ( V_48 , V_56 , V_52 ) ;
V_52 -= V_8 ;
V_48 += V_8 ;
V_32 += V_8 ;
V_55 = 0 ;
for (; V_53 < V_54 ; V_53 ++ ) {
V_55 |= V_10 [ V_53 ] & 0x7f ;
if ( ! ( V_10 [ V_53 ] & 0x80 ) ) {
sprintf ( V_56 , L_2 , V_55 ) ;
V_8 = strlen ( V_56 ) ;
if ( V_52 > 0 )
F_34 ( V_48 , V_56 , V_52 ) ;
V_52 -= V_8 ;
V_48 += V_8 ;
V_32 += V_8 ;
V_55 = 0 ;
}
V_55 <<= 7L ;
}
} else {
V_46 = F_21 ( V_19 ) ;
if ( V_46 == NULL )
V_46 = F_20 ( V_19 ) ;
F_34 ( V_48 , V_46 , V_52 ) ;
V_32 = strlen ( V_46 ) ;
}
return ( V_32 ) ;
}
int F_35 ( const char * V_46 )
{
T_1 * V_12 ;
int V_19 ;
V_12 = F_24 ( V_46 , 0 ) ;
V_19 = F_22 ( V_12 ) ;
F_11 ( V_12 ) ;
return V_19 ;
}
int F_26 ( const char * V_46 )
{
T_1 V_27 , * V_57 = & V_27 , * * V_42 ;
T_2 V_33 , * V_34 ;
V_27 . V_6 = V_46 ;
if ( V_22 != NULL )
{
V_33 . type = V_17 ;
V_33 . V_12 = & V_27 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL ) return ( V_34 -> V_12 -> V_19 ) ;
}
V_42 = ( T_1 * * ) F_23 ( ( char * ) & V_57 , ( char * ) V_58 , V_59 ,
sizeof( T_1 * ) , F_2 ) ;
if ( V_42 == NULL ) return ( V_31 ) ;
return ( ( * V_42 ) -> V_19 ) ;
}
int F_25 ( const char * V_46 )
{
T_1 V_27 , * V_57 = & V_27 , * * V_42 ;
T_2 V_33 , * V_34 ;
V_27 . V_5 = V_46 ;
if ( V_22 != NULL )
{
V_33 . type = V_16 ;
V_33 . V_12 = & V_27 ;
V_34 = ( T_2 * ) F_19 ( V_22 , & V_33 ) ;
if ( V_34 != NULL ) return ( V_34 -> V_12 -> V_19 ) ;
}
V_42 = ( T_1 * * ) F_23 ( ( char * ) & V_57 , ( char * ) V_60 , V_61 ,
sizeof( T_1 * ) , F_1 ) ;
if ( V_42 == NULL ) return ( V_31 ) ;
return ( ( * V_42 ) -> V_19 ) ;
}
static int V_45 ( const void * V_3 , const void * V_4 )
{
int V_49 ;
T_1 * V_1 = * ( T_1 * * ) V_3 ;
T_1 * V_2 = * ( T_1 * * ) V_4 ;
V_49 = ( V_1 -> V_14 - V_2 -> V_14 ) ;
if ( V_49 ) return ( V_49 ) ;
return ( memcmp ( V_1 -> V_15 , V_2 -> V_15 , V_1 -> V_14 ) ) ;
}
const char * F_23 ( const char * V_62 , const char * V_63 , int V_64 , int V_65 ,
int (* F_36)( const void * , const void * ) )
{
int V_55 , V_66 , V_8 , V_67 ;
const char * V_10 ;
if ( V_64 == 0 ) return ( NULL ) ;
V_55 = 0 ;
V_66 = V_64 ;
while ( V_55 < V_66 )
{
V_8 = ( V_55 + V_66 ) / 2 ;
V_10 = & ( V_63 [ V_8 * V_65 ] ) ;
V_67 = (* F_36)( V_62 , V_10 ) ;
if ( V_67 < 0 )
V_66 = V_8 ;
else if ( V_67 > 0 )
V_55 = V_8 + 1 ;
else
return ( V_10 ) ;
}
#ifdef F_37
for ( V_8 = 0 ; V_8 < V_64 ; ++ V_8 ) {
V_10 = & ( V_63 [ V_8 * V_65 ] ) ;
if ( (* F_36)( V_62 , V_10 ) == 0 )
return V_10 ;
}
#endif
return ( NULL ) ;
}
int F_38 ( T_3 * V_68 )
{
T_4 char V_48 [ 512 ] ;
int V_8 , V_64 = 0 ;
char * V_27 , * V_46 , * V_55 = NULL ;
for (; ; )
{
V_46 = V_27 = NULL ;
V_8 = F_39 ( V_68 , V_48 , 512 ) ;
if ( V_8 <= 0 ) return ( V_64 ) ;
V_48 [ V_8 - 1 ] = '\0' ;
if ( ! isalnum ( ( unsigned char ) V_48 [ 0 ] ) ) return ( V_64 ) ;
V_27 = V_46 = V_48 ;
while ( isdigit ( ( unsigned char ) * V_46 ) || ( * V_46 == '.' ) )
V_46 ++ ;
if ( * V_46 != '\0' )
{
* ( V_46 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_46 ) )
V_46 ++ ;
if ( * V_46 == '\0' )
V_46 = NULL ;
else
{
V_55 = V_46 ;
while ( ( * V_55 != '\0' ) && ! isspace ( ( unsigned char ) * V_55 ) )
V_55 ++ ;
if ( * V_55 != '\0' )
{
* ( V_55 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_55 ) )
V_55 ++ ;
if ( * V_55 == '\0' ) V_55 = NULL ;
}
else
V_55 = NULL ;
}
}
else
V_46 = NULL ;
if ( ( V_27 == NULL ) || ( * V_27 == '\0' ) ) return ( V_64 ) ;
if ( ! F_40 ( V_27 , V_46 , V_55 ) ) return ( V_64 ) ;
V_64 ++ ;
}
}
int F_40 ( const char * V_69 , const char * V_5 , const char * V_6 )
{
int V_70 = 0 ;
T_1 * V_42 = NULL ;
unsigned char * V_48 ;
int V_8 ;
V_8 = F_27 ( NULL , 0 , V_69 , - 1 ) ;
if ( V_8 <= 0 ) return ( 0 ) ;
if ( ( V_48 = ( unsigned char * ) F_15 ( V_8 ) ) == NULL )
{
F_18 ( V_71 , V_72 ) ;
return ( 0 ) ;
}
V_8 = F_27 ( V_48 , V_8 , V_69 , - 1 ) ;
if ( V_8 == 0 )
goto V_30;
V_42 = ( T_1 * ) F_41 ( F_42 ( 1 ) , V_48 , V_8 , V_5 , V_6 ) ;
if ( V_42 == NULL )
goto V_30;
V_70 = F_13 ( V_42 ) ;
V_30:
F_11 ( V_42 ) ;
F_12 ( V_48 ) ;
return ( V_70 ) ;
}
