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
static unsigned long F_3 ( T_2 * V_7 )
{
T_1 * V_1 ;
int V_8 ;
unsigned long V_9 = 0 ;
unsigned char * V_10 ;
V_1 = V_7 -> V_11 ;
switch ( V_7 -> type )
{
case V_12 :
V_9 = V_1 -> V_13 << 20L ;
V_10 = ( unsigned char * ) V_1 -> V_14 ;
for ( V_8 = 0 ; V_8 < V_1 -> V_13 ; V_8 ++ )
V_9 ^= V_10 [ V_8 ] << ( ( V_8 * 3 ) % 24 ) ;
break;
case V_15 :
V_9 = F_4 ( V_1 -> V_5 ) ;
break;
case V_16 :
V_9 = F_4 ( V_1 -> V_6 ) ;
break;
case V_17 :
V_9 = V_1 -> V_18 ;
break;
default:
return 0 ;
}
V_9 &= 0x3fffffffL ;
V_9 |= V_7 -> type << 30L ;
return ( V_9 ) ;
}
static int F_5 ( T_2 * V_7 , T_2 * V_19 )
{
T_1 * V_1 , * V_2 ;
int V_8 ;
V_8 = V_7 -> type - V_19 -> type ;
if ( V_8 ) return ( V_8 ) ;
V_1 = V_7 -> V_11 ;
V_2 = V_19 -> V_11 ;
switch ( V_7 -> type )
{
case V_12 :
V_8 = ( V_1 -> V_13 - V_2 -> V_13 ) ;
if ( V_8 ) return ( V_8 ) ;
return ( memcmp ( V_1 -> V_14 , V_2 -> V_14 , V_1 -> V_13 ) ) ;
case V_15 :
if ( V_1 -> V_5 == NULL ) return ( - 1 ) ;
else if ( V_2 -> V_5 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_1 -> V_5 , V_2 -> V_5 ) ) ;
case V_16 :
if ( V_1 -> V_6 == NULL ) return ( - 1 ) ;
else if ( V_2 -> V_6 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_1 -> V_6 , V_2 -> V_6 ) ) ;
case V_17 :
return ( V_1 -> V_18 - V_2 -> V_18 ) ;
default:
return 0 ;
}
return ( 1 ) ;
}
static int F_6 ( void )
{
if ( V_20 != NULL ) return ( 1 ) ;
V_20 = F_7 ( F_3 , F_5 ) ;
return ( V_20 != NULL ) ;
}
static void F_8 ( T_2 * V_1 )
{
V_1 -> V_11 -> V_18 = 0 ;
V_1 -> V_11 -> V_21 |= V_22 |
V_23 |
V_24 ;
}
static void F_9 ( T_2 * V_1 )
{ V_1 -> V_11 -> V_18 ++ ; }
static void F_10 ( T_2 * V_1 )
{
if ( -- V_1 -> V_11 -> V_18 == 0 )
F_11 ( V_1 -> V_11 ) ;
F_12 ( V_1 ) ;
}
void F_13 ( void )
{
if ( V_20 == NULL ) return;
V_20 -> V_25 = 0 ;
F_14 ( V_20 , F_8 ) ;
F_14 ( V_20 , F_9 ) ;
F_14 ( V_20 , F_10 ) ;
F_15 ( V_20 ) ;
V_20 = NULL ;
}
int F_16 ( int V_26 )
{
int V_8 ;
V_8 = V_27 ;
V_27 += V_26 ;
return ( V_8 ) ;
}
int F_17 ( T_1 * V_11 )
{
T_1 * V_28 ;
T_2 * V_29 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_30 ;
int V_8 ;
if ( V_20 == NULL )
if ( ! F_6 () ) return ( 0 ) ;
if ( ( V_28 = F_18 ( V_11 ) ) == NULL ) goto V_31;
V_29 [ V_17 ] = ( T_2 * ) F_19 ( sizeof( T_2 ) ) ;
if ( ( V_28 -> V_13 != 0 ) && ( V_11 -> V_14 != NULL ) )
V_29 [ V_12 ] = ( T_2 * ) F_19 ( sizeof( T_2 ) ) ;
if ( V_28 -> V_5 != NULL )
V_29 [ V_15 ] = ( T_2 * ) F_19 ( sizeof( T_2 ) ) ;
if ( V_28 -> V_6 != NULL )
V_29 [ V_16 ] = ( T_2 * ) F_19 ( sizeof( T_2 ) ) ;
for ( V_8 = V_12 ; V_8 <= V_17 ; V_8 ++ )
{
if ( V_29 [ V_8 ] != NULL )
{
V_29 [ V_8 ] -> type = V_8 ;
V_29 [ V_8 ] -> V_11 = V_28 ;
V_30 = ( T_2 * ) F_20 ( V_20 , V_29 [ V_8 ] ) ;
if ( V_30 != NULL )
F_12 ( V_30 ) ;
}
}
V_28 -> V_21 &= ~ ( V_22 | V_23 |
V_24 ) ;
return ( V_28 -> V_18 ) ;
V_31:
for ( V_8 = V_12 ; V_8 <= V_17 ; V_8 ++ )
if ( V_29 [ V_8 ] != NULL ) F_12 ( V_29 [ V_8 ] ) ;
if ( V_28 != NULL ) F_12 ( V_28 ) ;
return ( V_32 ) ;
}
T_1 * F_21 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_18 == V_32 ) )
{
F_22 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_38 [ V_33 ] ) ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_17 ;
V_34 . V_11 = & V_36 ;
V_36 . V_18 = V_33 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_11 ) ;
else
{
F_22 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
}
}
const char * F_24 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_18 == V_32 ) )
{
F_22 ( V_41 , V_40 ) ;
return ( NULL ) ;
}
return ( V_38 [ V_33 ] . V_5 ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_17 ;
V_34 . V_11 = & V_36 ;
V_36 . V_18 = V_33 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_11 -> V_5 ) ;
else
{
F_22 ( V_41 , V_40 ) ;
return ( NULL ) ;
}
}
}
const char * F_25 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_18 == V_32 ) )
{
F_22 ( V_42 , V_40 ) ;
return ( NULL ) ;
}
return ( V_38 [ V_33 ] . V_6 ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_17 ;
V_34 . V_11 = & V_36 ;
V_36 . V_18 = V_33 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_11 -> V_6 ) ;
else
{
F_22 ( V_42 , V_40 ) ;
return ( NULL ) ;
}
}
}
int F_26 ( T_1 * V_1 )
{
T_1 * * V_43 ;
T_2 V_34 , * V_35 ;
if ( V_1 == NULL )
return ( V_32 ) ;
if ( V_1 -> V_18 != 0 )
return ( V_1 -> V_18 ) ;
if ( V_20 != NULL )
{
V_34 . type = V_12 ;
V_34 . V_11 = V_1 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_11 -> V_18 ) ;
}
V_43 = ( T_1 * * ) F_27 ( ( char * ) & V_1 , ( char * ) V_44 , V_45 ,
sizeof( T_1 * ) , V_46 ) ;
if ( V_43 == NULL )
return ( V_32 ) ;
return ( ( * V_43 ) -> V_18 ) ;
}
T_1 * F_28 ( const char * V_47 , int V_48 )
{
int V_18 = V_32 ;
T_1 * V_43 = NULL ;
unsigned char * V_49 , * V_10 ;
int V_8 , V_50 ;
if( ! V_48 ) {
if( ( ( V_18 = F_29 ( V_47 ) ) != V_32 ) ||
( ( V_18 = F_30 ( V_47 ) ) != V_32 ) )
return F_21 ( V_18 ) ;
}
V_8 = F_31 ( NULL , 0 , V_47 , - 1 ) ;
if ( V_8 <= 0 ) {
F_32 () ;
return NULL ;
}
V_50 = F_33 ( 0 , V_8 , V_51 ) ;
if( ( V_49 = ( unsigned char * ) F_19 ( V_50 ) ) == NULL ) return NULL ;
V_10 = V_49 ;
F_34 ( & V_10 , 0 , V_8 , V_51 , V_52 ) ;
F_31 ( V_10 , V_8 , V_47 , - 1 ) ;
V_10 = V_49 ;
V_43 = F_35 ( NULL , & V_10 , V_8 ) ;
F_12 ( V_49 ) ;
return V_43 ;
}
int F_36 ( char * V_49 , int V_53 , T_1 * V_1 , int V_48 )
{
int V_8 , V_54 = 0 , V_33 = 0 , V_55 , V_18 ;
unsigned long V_56 ;
unsigned char * V_10 ;
const char * V_47 ;
char V_57 [ 32 ] ;
if ( V_53 <= 0 ) return ( 0 ) ;
if ( ( V_1 == NULL ) || ( V_1 -> V_14 == NULL ) ) {
V_49 [ 0 ] = '\0' ;
return ( 0 ) ;
}
V_18 = F_26 ( V_1 ) ;
if ( ( V_18 == V_32 ) || V_48 ) {
V_55 = V_1 -> V_13 ;
V_10 = V_1 -> V_14 ;
V_54 = 0 ;
V_56 = 0 ;
while ( V_54 < V_1 -> V_13 ) {
V_56 |= ( V_10 [ V_54 ] & 0x7f ) ;
if ( ! ( V_10 [ V_54 ] & 0x80 ) ) break;
V_56 <<= 7L ;
V_54 ++ ;
}
V_54 ++ ;
V_8 = ( int ) ( V_56 / 40 ) ;
if ( V_8 > 2 ) V_8 = 2 ;
V_56 -= ( long ) ( V_8 * 40 ) ;
sprintf ( V_57 , L_1 , V_8 , V_56 ) ;
V_8 = strlen ( V_57 ) ;
strncpy ( V_49 , V_57 , V_53 ) ;
V_53 -= V_8 ;
V_49 += V_8 ;
V_33 += V_8 ;
V_56 = 0 ;
for (; V_54 < V_55 ; V_54 ++ ) {
V_56 |= V_10 [ V_54 ] & 0x7f ;
if ( ! ( V_10 [ V_54 ] & 0x80 ) ) {
sprintf ( V_57 , L_2 , V_56 ) ;
V_8 = strlen ( V_57 ) ;
if ( V_53 > 0 )
strncpy ( V_49 , V_57 , V_53 ) ;
V_53 -= V_8 ;
V_49 += V_8 ;
V_33 += V_8 ;
V_56 = 0 ;
}
V_56 <<= 7L ;
}
} else {
V_47 = F_25 ( V_18 ) ;
if ( V_47 == NULL )
V_47 = F_24 ( V_18 ) ;
strncpy ( V_49 , V_47 , V_53 ) ;
V_33 = strlen ( V_47 ) ;
}
V_49 [ V_53 - 1 ] = '\0' ;
return ( V_33 ) ;
}
int F_37 ( char * V_47 )
{
T_1 * V_11 ;
int V_18 ;
V_11 = F_28 ( V_47 , 0 ) ;
V_18 = F_26 ( V_11 ) ;
F_11 ( V_11 ) ;
return V_18 ;
}
int F_30 ( const char * V_47 )
{
T_1 V_28 , * V_58 = & V_28 , * * V_43 ;
T_2 V_34 , * V_35 ;
V_28 . V_6 = V_47 ;
if ( V_20 != NULL )
{
V_34 . type = V_16 ;
V_34 . V_11 = & V_28 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_11 -> V_18 ) ;
}
V_43 = ( T_1 * * ) F_27 ( ( char * ) & V_58 , ( char * ) V_59 , V_60 ,
sizeof( T_1 * ) , F_2 ) ;
if ( V_43 == NULL ) return ( V_32 ) ;
return ( ( * V_43 ) -> V_18 ) ;
}
int F_29 ( const char * V_47 )
{
T_1 V_28 , * V_58 = & V_28 , * * V_43 ;
T_2 V_34 , * V_35 ;
V_28 . V_5 = V_47 ;
if ( V_20 != NULL )
{
V_34 . type = V_15 ;
V_34 . V_11 = & V_28 ;
V_35 = ( T_2 * ) F_23 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_11 -> V_18 ) ;
}
V_43 = ( T_1 * * ) F_27 ( ( char * ) & V_58 , ( char * ) V_61 , V_62 ,
sizeof( T_1 * ) , F_1 ) ;
if ( V_43 == NULL ) return ( V_32 ) ;
return ( ( * V_43 ) -> V_18 ) ;
}
static int V_46 ( const void * V_3 , const void * V_4 )
{
int V_50 ;
T_1 * V_1 = * ( T_1 * * ) V_3 ;
T_1 * V_2 = * ( T_1 * * ) V_4 ;
V_50 = ( V_1 -> V_13 - V_2 -> V_13 ) ;
if ( V_50 ) return ( V_50 ) ;
return ( memcmp ( V_1 -> V_14 , V_2 -> V_14 , V_1 -> V_13 ) ) ;
}
char * F_27 ( char * V_63 , char * V_64 , int V_26 , int V_65 , int (* F_38)( const void * , const void * ) )
{
int V_56 , V_66 , V_8 , V_67 ;
char * V_10 ;
if ( V_26 == 0 ) return ( NULL ) ;
V_56 = 0 ;
V_66 = V_26 ;
while ( V_56 < V_66 )
{
V_8 = ( V_56 + V_66 ) / 2 ;
V_10 = & ( V_64 [ V_8 * V_65 ] ) ;
V_67 = (* F_38)( V_63 , V_10 ) ;
if ( V_67 < 0 )
V_66 = V_8 ;
else if ( V_67 > 0 )
V_56 = V_8 + 1 ;
else
return ( V_10 ) ;
}
#ifdef F_39
for ( V_8 = 0 ; V_8 < V_26 ; ++ V_8 ) {
V_10 = & ( V_64 [ V_8 * V_65 ] ) ;
if ( (* F_38)( V_63 , V_10 ) == 0 )
return V_10 ;
}
#endif
return ( NULL ) ;
}
int F_40 ( T_3 * V_68 )
{
T_4 char V_49 [ 512 ] ;
int V_8 , V_26 = 0 ;
char * V_28 , * V_47 , * V_56 = NULL ;
for (; ; )
{
V_47 = V_28 = NULL ;
V_8 = F_41 ( V_68 , V_49 , 512 ) ;
if ( V_8 <= 0 ) return ( V_26 ) ;
V_49 [ V_8 - 1 ] = '\0' ;
if ( ! isalnum ( ( unsigned char ) V_49 [ 0 ] ) ) return ( V_26 ) ;
V_28 = V_47 = V_49 ;
while ( isdigit ( ( unsigned char ) * V_47 ) || ( * V_47 == '.' ) )
V_47 ++ ;
if ( * V_47 != '\0' )
{
* ( V_47 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_47 ) )
V_47 ++ ;
if ( * V_47 == '\0' )
V_47 = NULL ;
else
{
V_56 = V_47 ;
while ( ( * V_56 != '\0' ) && ! isspace ( ( unsigned char ) * V_56 ) )
V_56 ++ ;
if ( * V_56 != '\0' )
{
* ( V_56 ++ ) = '\0' ;
while ( isspace ( ( unsigned char ) * V_56 ) )
V_56 ++ ;
if ( * V_56 == '\0' ) V_56 = NULL ;
}
else
V_56 = NULL ;
}
}
else
V_47 = NULL ;
if ( ( V_28 == NULL ) || ( * V_28 == '\0' ) ) return ( V_26 ) ;
if ( ! F_42 ( V_28 , V_47 , V_56 ) ) return ( V_26 ) ;
V_26 ++ ;
}
}
int F_42 ( char * V_69 , char * V_5 , char * V_6 )
{
int V_70 = 0 ;
T_1 * V_43 = NULL ;
unsigned char * V_49 ;
int V_8 ;
V_8 = F_31 ( NULL , 0 , V_69 , - 1 ) ;
if ( V_8 <= 0 ) return ( 0 ) ;
if ( ( V_49 = ( unsigned char * ) F_19 ( V_8 ) ) == NULL )
{
F_22 ( V_71 , V_72 ) ;
return ( 0 ) ;
}
V_8 = F_31 ( V_49 , V_8 , V_69 , - 1 ) ;
V_43 = ( T_1 * ) F_43 ( F_16 ( 1 ) , V_49 , V_8 , V_5 , V_6 ) ;
if ( V_43 == NULL )
goto V_31;
V_70 = F_17 ( V_43 ) ;
V_31:
F_11 ( V_43 ) ;
F_12 ( V_49 ) ;
return ( V_70 ) ;
}
