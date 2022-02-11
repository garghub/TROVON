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
const T_2 * V_11 = ( const T_2 * ) V_7 ;
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
const T_2 * V_11 = ( const T_2 * ) V_7 ;
const T_2 * V_21 = ( const T_2 * ) V_20 ;
V_8 = V_11 -> type - V_21 -> type ;
if ( V_8 ) return ( V_8 ) ;
V_1 = V_11 -> V_12 ;
V_2 = V_21 -> V_12 ;
switch ( V_11 -> type )
{
case V_13 :
V_8 = ( V_1 -> V_14 - V_2 -> V_14 ) ;
if ( V_8 ) return ( V_8 ) ;
return ( memcmp ( V_1 -> V_15 , V_2 -> V_15 , ( V_22 ) V_1 -> V_14 ) ) ;
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
if ( V_23 != NULL ) return ( 1 ) ;
V_23 = F_7 ( F_3 , F_5 ) ;
return ( V_23 != NULL ) ;
}
static void F_8 ( T_2 * V_1 )
{
V_1 -> V_12 -> V_19 = 0 ;
V_1 -> V_12 -> V_24 |= V_25 |
V_26 |
V_27 ;
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
T_1 * V_28 ;
T_2 * V_29 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_30 ;
int V_8 ;
if ( V_23 == NULL )
if ( ! F_6 () ) return ( 0 ) ;
if ( ( V_28 = F_14 ( V_12 ) ) == NULL ) goto V_31;
if ( ! ( V_29 [ V_18 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ) ) goto V_32;
if ( ( V_28 -> V_14 != 0 ) && ( V_12 -> V_15 != NULL ) )
if ( ! ( V_29 [ V_13 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ) ) goto V_32;
if ( V_28 -> V_5 != NULL )
if ( ! ( V_29 [ V_16 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ) ) goto V_32;
if ( V_28 -> V_6 != NULL )
if ( ! ( V_29 [ V_17 ] = ( T_2 * ) F_15 ( sizeof( T_2 ) ) ) ) goto V_32;
for ( V_8 = V_13 ; V_8 <= V_18 ; V_8 ++ )
{
if ( V_29 [ V_8 ] != NULL )
{
V_29 [ V_8 ] -> type = V_8 ;
V_29 [ V_8 ] -> V_12 = V_28 ;
V_30 = ( T_2 * ) F_16 ( V_23 , V_29 [ V_8 ] ) ;
if ( V_30 != NULL )
F_12 ( V_30 ) ;
}
}
V_28 -> V_24 &= ~ ( V_25 | V_26 |
V_27 ) ;
return ( V_28 -> V_19 ) ;
V_32:
F_17 ( V_33 , V_34 ) ;
V_31:
for ( V_8 = V_13 ; V_8 <= V_18 ; V_8 ++ )
if ( V_29 [ V_8 ] != NULL ) F_12 ( V_29 [ V_8 ] ) ;
if ( V_28 != NULL ) F_12 ( V_28 ) ;
return ( V_35 ) ;
}
T_1 * F_18 ( int V_36 )
{
T_2 V_37 , * V_38 ;
T_1 V_39 ;
if ( ( V_36 >= 0 ) && ( V_36 < V_40 ) )
{
if ( ( V_36 != V_35 ) && ( V_41 [ V_36 ] . V_19 == V_35 ) )
{
F_17 ( V_42 , V_43 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_41 [ V_36 ] ) ) ;
}
else if ( V_23 == NULL )
return ( NULL ) ;
else
{
V_37 . type = V_18 ;
V_37 . V_12 = & V_39 ;
V_39 . V_19 = V_36 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL )
return ( V_38 -> V_12 ) ;
else
{
F_17 ( V_42 , V_43 ) ;
return ( NULL ) ;
}
}
}
const char * F_20 ( int V_36 )
{
T_2 V_37 , * V_38 ;
T_1 V_39 ;
if ( ( V_36 >= 0 ) && ( V_36 < V_40 ) )
{
if ( ( V_36 != V_35 ) && ( V_41 [ V_36 ] . V_19 == V_35 ) )
{
F_17 ( V_44 , V_43 ) ;
return ( NULL ) ;
}
return ( V_41 [ V_36 ] . V_5 ) ;
}
else if ( V_23 == NULL )
return ( NULL ) ;
else
{
V_37 . type = V_18 ;
V_37 . V_12 = & V_39 ;
V_39 . V_19 = V_36 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL )
return ( V_38 -> V_12 -> V_5 ) ;
else
{
F_17 ( V_44 , V_43 ) ;
return ( NULL ) ;
}
}
}
const char * F_21 ( int V_36 )
{
T_2 V_37 , * V_38 ;
T_1 V_39 ;
if ( ( V_36 >= 0 ) && ( V_36 < V_40 ) )
{
if ( ( V_36 != V_35 ) && ( V_41 [ V_36 ] . V_19 == V_35 ) )
{
F_17 ( V_45 , V_43 ) ;
return ( NULL ) ;
}
return ( V_41 [ V_36 ] . V_6 ) ;
}
else if ( V_23 == NULL )
return ( NULL ) ;
else
{
V_37 . type = V_18 ;
V_37 . V_12 = & V_39 ;
V_39 . V_19 = V_36 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL )
return ( V_38 -> V_12 -> V_6 ) ;
else
{
F_17 ( V_45 , V_43 ) ;
return ( NULL ) ;
}
}
}
int F_22 ( const T_1 * V_1 )
{
T_1 * * V_46 ;
T_2 V_37 , * V_38 ;
if ( V_1 == NULL )
return ( V_35 ) ;
if ( V_1 -> V_19 != 0 )
return ( V_1 -> V_19 ) ;
if ( V_23 != NULL )
{
V_37 . type = V_13 ;
V_37 . V_12 = ( T_1 * ) V_1 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL ) return ( V_38 -> V_12 -> V_19 ) ;
}
V_46 = ( T_1 * * ) F_23 ( ( const char * ) & V_1 , ( const char * ) V_47 ,
V_48 , sizeof( T_1 * ) , V_49 ) ;
if ( V_46 == NULL )
return ( V_35 ) ;
return ( ( * V_46 ) -> V_19 ) ;
}
T_1 * F_24 ( const char * V_50 , int V_51 )
{
int V_19 = V_35 ;
T_1 * V_46 = NULL ;
unsigned char * V_52 ;
unsigned char * V_10 ;
const unsigned char * V_53 ;
int V_8 , V_54 ;
if( ! V_51 ) {
if( ( ( V_19 = F_25 ( V_50 ) ) != V_35 ) ||
( ( V_19 = F_26 ( V_50 ) ) != V_35 ) )
return F_18 ( V_19 ) ;
}
V_8 = F_27 ( NULL , 0 , V_50 , - 1 ) ;
if ( V_8 <= 0 ) {
F_28 () ;
return NULL ;
}
V_54 = F_29 ( 0 , V_8 , V_55 ) ;
if( ( V_52 = ( unsigned char * ) F_15 ( V_54 ) ) == NULL ) return NULL ;
V_10 = V_52 ;
F_30 ( & V_10 , 0 , V_8 , V_55 , V_56 ) ;
F_27 ( V_10 , V_8 , V_50 , - 1 ) ;
V_53 = V_52 ;
V_46 = F_31 ( NULL , & V_53 , V_54 ) ;
F_12 ( V_52 ) ;
return V_46 ;
}
int F_32 ( char * V_52 , int V_57 , const T_1 * V_1 , int V_51 )
{
int V_8 , V_58 = 0 , V_36 = 0 , V_59 , V_19 ;
unsigned long V_60 ;
unsigned char * V_10 ;
const char * V_50 ;
char V_61 [ F_33 ( V_8 ) + F_33 ( V_60 ) + 2 ] ;
if ( V_57 <= 0 ) return ( 0 ) ;
if ( ( V_1 == NULL ) || ( V_1 -> V_15 == NULL ) ) {
V_52 [ 0 ] = '\0' ;
return ( 0 ) ;
}
if ( V_51 || ( V_19 = F_22 ( V_1 ) ) == V_35 ) {
V_59 = V_1 -> V_14 ;
V_10 = V_1 -> V_15 ;
V_58 = 0 ;
V_60 = 0 ;
while ( V_58 < V_1 -> V_14 ) {
V_60 |= ( V_10 [ V_58 ] & 0x7f ) ;
if ( ! ( V_10 [ V_58 ] & 0x80 ) ) break;
V_60 <<= 7L ;
V_58 ++ ;
}
V_58 ++ ;
V_8 = ( int ) ( V_60 / 40 ) ;
if ( V_8 > 2 ) V_8 = 2 ;
V_60 -= ( long ) ( V_8 * 40 ) ;
F_34 ( V_61 , sizeof V_61 , L_1 , V_8 , V_60 ) ;
V_8 = strlen ( V_61 ) ;
F_35 ( V_52 , V_61 , V_57 ) ;
V_57 -= V_8 ;
V_52 += V_8 ;
V_36 += V_8 ;
V_60 = 0 ;
for (; V_58 < V_59 ; V_58 ++ ) {
V_60 |= V_10 [ V_58 ] & 0x7f ;
if ( ! ( V_10 [ V_58 ] & 0x80 ) ) {
F_34 ( V_61 , sizeof V_61 , L_2 , V_60 ) ;
V_8 = strlen ( V_61 ) ;
if ( V_57 > 0 )
F_35 ( V_52 , V_61 , V_57 ) ;
V_57 -= V_8 ;
V_52 += V_8 ;
V_36 += V_8 ;
V_60 = 0 ;
}
V_60 <<= 7L ;
}
} else {
V_50 = F_21 ( V_19 ) ;
if ( V_50 == NULL )
V_50 = F_20 ( V_19 ) ;
F_35 ( V_52 , V_50 , V_57 ) ;
V_36 = strlen ( V_50 ) ;
}
return ( V_36 ) ;
}
int F_36 ( const char * V_50 )
{
T_1 * V_12 ;
int V_19 ;
V_12 = F_24 ( V_50 , 0 ) ;
V_19 = F_22 ( V_12 ) ;
F_11 ( V_12 ) ;
return V_19 ;
}
int F_26 ( const char * V_50 )
{
T_1 V_28 , * V_62 = & V_28 , * * V_46 ;
T_2 V_37 , * V_38 ;
V_28 . V_6 = V_50 ;
if ( V_23 != NULL )
{
V_37 . type = V_17 ;
V_37 . V_12 = & V_28 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL ) return ( V_38 -> V_12 -> V_19 ) ;
}
V_46 = ( T_1 * * ) F_23 ( ( char * ) & V_62 , ( char * ) V_63 , V_64 ,
sizeof( T_1 * ) , F_2 ) ;
if ( V_46 == NULL ) return ( V_35 ) ;
return ( ( * V_46 ) -> V_19 ) ;
}
int F_25 ( const char * V_50 )
{
T_1 V_28 , * V_62 = & V_28 , * * V_46 ;
T_2 V_37 , * V_38 ;
V_28 . V_5 = V_50 ;
if ( V_23 != NULL )
{
V_37 . type = V_16 ;
V_37 . V_12 = & V_28 ;
V_38 = ( T_2 * ) F_19 ( V_23 , & V_37 ) ;
if ( V_38 != NULL ) return ( V_38 -> V_12 -> V_19 ) ;
}
V_46 = ( T_1 * * ) F_23 ( ( char * ) & V_62 , ( char * ) V_65 , V_66 ,
sizeof( T_1 * ) , F_1 ) ;
if ( V_46 == NULL ) return ( V_35 ) ;
return ( ( * V_46 ) -> V_19 ) ;
}
static int V_49 ( const void * V_3 , const void * V_4 )
{
int V_54 ;
const T_1 * V_1 = * ( T_1 * const * ) V_3 ;
const T_1 * V_2 = * ( T_1 * const * ) V_4 ;
V_54 = ( V_1 -> V_14 - V_2 -> V_14 ) ;
if ( V_54 ) return ( V_54 ) ;
return ( memcmp ( V_1 -> V_15 , V_2 -> V_15 , V_1 -> V_14 ) ) ;
}
const char * F_23 ( const char * V_67 , const char * V_68 , int V_69 , int V_70 ,
int (* F_37)( const void * , const void * ) )
{
return F_38 ( V_67 , V_68 , V_69 , V_70 , F_37 , 0 ) ;
}
const char * F_38 ( const char * V_67 , const char * V_68 , int V_69 ,
int V_70 , int (* F_37)( const void * , const void * ) , int V_24 )
{
int V_60 , V_71 , V_8 = 0 , V_72 = 0 ;
const char * V_10 = NULL ;
if ( V_69 == 0 ) return ( NULL ) ;
V_60 = 0 ;
V_71 = V_69 ;
while ( V_60 < V_71 )
{
V_8 = ( V_60 + V_71 ) / 2 ;
V_10 = & ( V_68 [ V_8 * V_70 ] ) ;
V_72 = (* F_37)( V_67 , V_10 ) ;
if ( V_72 < 0 )
V_71 = V_8 ;
else if ( V_72 > 0 )
V_60 = V_8 + 1 ;
else
break;
}
#ifdef F_39
if ( V_72 != 0 )
{
for ( V_8 = 0 ; V_8 < V_69 ; ++ V_8 )
{
V_10 = & ( V_68 [ V_8 * V_70 ] ) ;
V_72 = (* F_37)( V_67 , V_10 ) ;
if ( V_72 == 0 || ( V_72 < 0 && ( V_24 & V_73 ) ) )
return V_10 ;
}
}
#endif
if ( V_72 != 0 && ! ( V_24 & V_73 ) )
V_10 = NULL ;
else if ( V_72 == 0 && ( V_24 & V_74 ) )
{
while( V_8 > 0 && (* F_37)( V_67 , & ( V_68 [ ( V_8 - 1 ) * V_70 ] ) ) == 0 )
V_8 -- ;
V_10 = & ( V_68 [ V_8 * V_70 ] ) ;
}
return ( V_10 ) ;
}
int F_40 ( T_3 * V_75 )
{
T_4 char V_52 [ 512 ] ;
int V_8 , V_69 = 0 ;
char * V_28 , * V_50 , * V_60 = NULL ;
for (; ; )
{
V_50 = V_28 = NULL ;
V_8 = F_41 ( V_75 , V_52 , 512 ) ;
if ( V_8 <= 0 ) return ( V_69 ) ;
V_52 [ V_8 - 1 ] = '\0' ;
if ( ! isalnum ( ( unsigned char ) V_52 [ 0 ] ) ) return ( V_69 ) ;
V_28 = V_50 = V_52 ;
while ( isdigit ( ( unsigned char ) * V_50 ) || ( * V_50 == '.' ) )
V_50 ++ ;
if ( * V_50 != '\0' )
{
* ( V_50 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_50 ) )
V_50 ++ ;
if ( * V_50 == '\0' )
V_50 = NULL ;
else
{
V_60 = V_50 ;
while ( ( * V_60 != '\0' ) && ! isspace ( ( unsigned char ) * V_60 ) )
V_60 ++ ;
if ( * V_60 != '\0' )
{
* ( V_60 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_60 ) )
V_60 ++ ;
if ( * V_60 == '\0' ) V_60 = NULL ;
}
else
V_60 = NULL ;
}
}
else
V_50 = NULL ;
if ( ( V_28 == NULL ) || ( * V_28 == '\0' ) ) return ( V_69 ) ;
if ( ! F_42 ( V_28 , V_50 , V_60 ) ) return ( V_69 ) ;
V_69 ++ ;
}
}
int F_42 ( const char * V_76 , const char * V_5 , const char * V_6 )
{
int V_77 = 0 ;
T_1 * V_46 = NULL ;
unsigned char * V_52 ;
int V_8 ;
V_8 = F_27 ( NULL , 0 , V_76 , - 1 ) ;
if ( V_8 <= 0 ) return ( 0 ) ;
if ( ( V_52 = ( unsigned char * ) F_15 ( V_8 ) ) == NULL )
{
F_17 ( V_78 , V_34 ) ;
return ( 0 ) ;
}
V_8 = F_27 ( V_52 , V_8 , V_76 , - 1 ) ;
if ( V_8 == 0 )
goto V_31;
V_46 = ( T_1 * ) F_43 ( F_44 ( 1 ) , V_52 , V_8 , V_5 , V_6 ) ;
if ( V_46 == NULL )
goto V_31;
V_77 = F_13 ( V_46 ) ;
V_31:
F_11 ( V_46 ) ;
F_12 ( V_52 ) ;
return ( V_77 ) ;
}
