static int F_1 ( T_1 * * V_1 , T_1 * * V_2 )
{ return ( strcmp ( ( * V_1 ) -> V_3 , ( * V_2 ) -> V_3 ) ) ; }
static int F_2 ( T_1 * * V_1 , T_1 * * V_2 )
{ return ( strcmp ( ( * V_1 ) -> V_4 , ( * V_2 ) -> V_4 ) ) ; }
static unsigned long F_3 ( T_2 * V_5 )
{
T_1 * V_6 ;
int V_7 ;
unsigned long V_8 = 0 ;
unsigned char * V_9 ;
V_6 = V_5 -> V_10 ;
switch ( V_5 -> type )
{
case V_11 :
V_8 = V_6 -> V_12 << 20L ;
V_9 = ( unsigned char * ) V_6 -> V_13 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_12 ; V_7 ++ )
V_8 ^= V_9 [ V_7 ] << ( ( V_7 * 3 ) % 24 ) ;
break;
case V_14 :
V_8 = F_4 ( V_6 -> V_3 ) ;
break;
case V_15 :
V_8 = F_4 ( V_6 -> V_4 ) ;
break;
case V_16 :
V_8 = V_6 -> V_17 ;
break;
default:
abort () ;
}
V_8 &= 0x3fffffffL ;
V_8 |= V_5 -> type << 30L ;
return ( V_8 ) ;
}
static int F_5 ( T_2 * V_5 , T_2 * V_18 )
{
T_1 * V_6 , * V_19 ;
int V_7 ;
V_7 = V_5 -> type - V_18 -> type ;
if ( V_7 ) return ( V_7 ) ;
V_6 = V_5 -> V_10 ;
V_19 = V_18 -> V_10 ;
switch ( V_5 -> type )
{
case V_11 :
V_7 = ( V_6 -> V_12 - V_19 -> V_12 ) ;
if ( V_7 ) return ( V_7 ) ;
return ( memcmp ( V_6 -> V_13 , V_19 -> V_13 , V_6 -> V_12 ) ) ;
case V_14 :
if ( V_6 -> V_3 == NULL ) return ( - 1 ) ;
else if ( V_19 -> V_3 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_6 -> V_3 , V_19 -> V_3 ) ) ;
case V_15 :
if ( V_6 -> V_4 == NULL ) return ( - 1 ) ;
else if ( V_19 -> V_4 == NULL ) return ( 1 ) ;
else return ( strcmp ( V_6 -> V_4 , V_19 -> V_4 ) ) ;
case V_16 :
return ( V_6 -> V_17 - V_19 -> V_17 ) ;
default:
abort () ;
}
return ( 1 ) ;
}
static int F_6 ( void )
{
if ( V_20 != NULL ) return ( 1 ) ;
V_20 = F_7 ( F_3 , F_5 ) ;
return ( V_20 != NULL ) ;
}
static void F_8 ( T_2 * V_6 )
{
V_6 -> V_10 -> V_17 = 0 ;
V_6 -> V_10 -> V_21 |= V_22 |
V_23 |
V_24 ;
}
static void F_9 ( T_2 * V_6 )
{ V_6 -> V_10 -> V_17 ++ ; }
static void F_10 ( T_2 * V_6 )
{
if ( -- V_6 -> V_10 -> V_17 == 0 )
F_11 ( V_6 -> V_10 ) ;
Free ( V_6 ) ;
}
void F_12 ( void )
{
if ( V_20 == NULL ) return;
V_20 -> V_25 = 0 ;
F_13 ( V_20 , F_8 ) ;
F_13 ( V_20 , F_9 ) ;
F_13 ( V_20 , F_10 ) ;
F_14 ( V_20 ) ;
V_20 = NULL ;
}
int F_15 ( int V_26 )
{
int V_7 ;
V_7 = V_27 ;
V_27 += V_26 ;
return ( V_7 ) ;
}
int F_16 ( T_1 * V_10 )
{
T_1 * V_28 ;
T_2 * V_29 [ 4 ] = { NULL , NULL , NULL , NULL } , * V_30 ;
int V_7 ;
if ( V_20 == NULL )
if ( ! F_6 () ) return ( 0 ) ;
if ( ( V_28 = F_17 ( V_10 ) ) == NULL ) goto V_31;
V_29 [ V_16 ] = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( ( V_28 -> V_12 != 0 ) && ( V_10 -> V_13 != NULL ) )
V_29 [ V_11 ] = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_28 -> V_3 != NULL )
V_29 [ V_14 ] = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
if ( V_28 -> V_4 != NULL )
V_29 [ V_15 ] = ( T_2 * ) Malloc ( sizeof( T_2 ) ) ;
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ )
{
if ( V_29 [ V_7 ] != NULL )
{
V_29 [ V_7 ] -> type = V_7 ;
V_29 [ V_7 ] -> V_10 = V_28 ;
V_30 = ( T_2 * ) F_18 ( V_20 , V_29 [ V_7 ] ) ;
if ( V_30 != NULL )
Free ( V_30 ) ;
}
}
V_28 -> V_21 &= ~ ( V_22 | V_23 |
V_24 ) ;
return ( V_28 -> V_17 ) ;
V_31:
for ( V_7 = V_11 ; V_7 <= V_16 ; V_7 ++ )
if ( V_29 [ V_7 ] != NULL ) Free ( V_29 [ V_7 ] ) ;
if ( V_28 != NULL ) Free ( V_28 ) ;
return ( V_32 ) ;
}
T_1 * F_19 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_17 == V_32 ) )
{
F_20 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
return ( ( T_1 * ) & ( V_38 [ V_33 ] ) ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_16 ;
V_34 . V_10 = & V_36 ;
V_36 . V_17 = V_33 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_10 ) ;
else
{
F_20 ( V_39 , V_40 ) ;
return ( NULL ) ;
}
}
}
const char * F_22 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_17 == V_32 ) )
{
F_20 ( V_41 , V_40 ) ;
return ( NULL ) ;
}
return ( V_38 [ V_33 ] . V_3 ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_16 ;
V_34 . V_10 = & V_36 ;
V_36 . V_17 = V_33 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_10 -> V_3 ) ;
else
{
F_20 ( V_41 , V_40 ) ;
return ( NULL ) ;
}
}
}
const char * F_23 ( int V_33 )
{
T_2 V_34 , * V_35 ;
T_1 V_36 ;
if ( ( V_33 >= 0 ) && ( V_33 < V_37 ) )
{
if ( ( V_33 != V_32 ) && ( V_38 [ V_33 ] . V_17 == V_32 ) )
{
F_20 ( V_42 , V_40 ) ;
return ( NULL ) ;
}
return ( V_38 [ V_33 ] . V_4 ) ;
}
else if ( V_20 == NULL )
return ( NULL ) ;
else
{
V_34 . type = V_16 ;
V_34 . V_10 = & V_36 ;
V_36 . V_17 = V_33 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL )
return ( V_35 -> V_10 -> V_4 ) ;
else
{
F_20 ( V_42 , V_40 ) ;
return ( NULL ) ;
}
}
}
int F_24 ( T_1 * V_6 )
{
T_1 * * V_43 ;
T_2 V_34 , * V_35 ;
if ( V_6 == NULL )
return ( V_32 ) ;
if ( V_6 -> V_17 != 0 )
return ( V_6 -> V_17 ) ;
if ( V_20 != NULL )
{
V_34 . type = V_11 ;
V_34 . V_10 = V_6 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_10 -> V_17 ) ;
}
V_43 = ( T_1 * * ) F_25 ( ( char * ) & V_6 , ( char * ) V_44 , V_45 ,
sizeof( T_1 * ) , ( int ( * ) () ) V_46 ) ;
if ( V_43 == NULL )
return ( V_32 ) ;
return ( ( * V_43 ) -> V_17 ) ;
}
T_1 * F_26 ( const char * V_47 , int V_48 )
{
int V_17 = V_32 ;
T_1 * V_43 = NULL ;
unsigned char * V_49 , * V_9 ;
int V_7 , V_50 ;
if( ! V_48 ) {
if( ( ( V_17 = F_27 ( V_47 ) ) != V_32 ) ||
( ( V_17 = F_28 ( V_47 ) ) != V_32 ) )
return F_19 ( V_17 ) ;
}
V_7 = F_29 ( NULL , 0 , V_47 , - 1 ) ;
if ( V_7 <= 0 ) {
F_30 () ;
return NULL ;
}
V_50 = F_31 ( 0 , V_7 , V_51 ) ;
if( ( V_49 = ( unsigned char * ) Malloc ( V_50 ) ) == NULL ) return NULL ;
V_9 = V_49 ;
F_32 ( & V_9 , 0 , V_7 , V_51 , V_52 ) ;
F_29 ( V_9 , V_7 , V_47 , - 1 ) ;
V_9 = V_49 ;
V_43 = F_33 ( NULL , & V_9 , V_7 ) ;
Free ( V_49 ) ;
return V_43 ;
}
int F_34 ( char * V_49 , int V_53 , T_1 * V_6 , int V_48 )
{
int V_7 , V_54 = 0 , V_33 = 0 , V_55 , V_17 ;
unsigned long V_56 ;
unsigned char * V_9 ;
const char * V_47 ;
char V_57 [ 32 ] ;
if ( V_53 <= 0 ) return ( 0 ) ;
if ( ( V_6 == NULL ) || ( V_6 -> V_13 == NULL ) ) {
V_49 [ 0 ] = '\0' ;
return ( 0 ) ;
}
V_17 = F_24 ( V_6 ) ;
if ( ( V_17 == V_32 ) || V_48 ) {
V_55 = V_6 -> V_12 ;
V_9 = V_6 -> V_13 ;
V_54 = 0 ;
V_56 = 0 ;
while ( V_54 < V_6 -> V_12 ) {
V_56 |= ( V_9 [ V_54 ] & 0x7f ) ;
if ( ! ( V_9 [ V_54 ] & 0x80 ) ) break;
V_56 <<= 7L ;
V_54 ++ ;
}
V_54 ++ ;
V_7 = ( int ) ( V_56 / 40 ) ;
if ( V_7 > 2 ) V_7 = 2 ;
V_56 -= ( long ) ( V_7 * 40 ) ;
sprintf ( V_57 , L_1 , V_7 , V_56 ) ;
V_7 = strlen ( V_57 ) ;
strncpy ( V_49 , V_57 , V_53 ) ;
V_53 -= V_7 ;
V_49 += V_7 ;
V_33 += V_7 ;
V_56 = 0 ;
for (; V_54 < V_55 ; V_54 ++ ) {
V_56 |= V_9 [ V_54 ] & 0x7f ;
if ( ! ( V_9 [ V_54 ] & 0x80 ) ) {
sprintf ( V_57 , L_2 , V_56 ) ;
V_7 = strlen ( V_57 ) ;
if ( V_53 > 0 )
strncpy ( V_49 , V_57 , V_53 ) ;
V_53 -= V_7 ;
V_49 += V_7 ;
V_33 += V_7 ;
V_56 = 0 ;
}
V_56 <<= 7L ;
}
} else {
V_47 = F_23 ( V_17 ) ;
if ( V_47 == NULL )
V_47 = F_22 ( V_17 ) ;
strncpy ( V_49 , V_47 , V_53 ) ;
V_33 = strlen ( V_47 ) ;
}
V_49 [ V_53 - 1 ] = '\0' ;
return ( V_33 ) ;
}
int F_35 ( char * V_47 )
{
T_1 * V_10 ;
int V_17 ;
V_10 = F_26 ( V_47 , 0 ) ;
V_17 = F_24 ( V_10 ) ;
F_11 ( V_10 ) ;
return V_17 ;
}
int F_28 ( const char * V_47 )
{
T_1 V_28 , * V_58 = & V_28 , * * V_43 ;
T_2 V_34 , * V_35 ;
V_28 . V_4 = V_47 ;
if ( V_20 != NULL )
{
V_34 . type = V_15 ;
V_34 . V_10 = & V_28 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_10 -> V_17 ) ;
}
V_43 = ( T_1 * * ) F_25 ( ( char * ) & V_58 , ( char * ) V_59 , V_60 ,
sizeof( T_1 * ) , ( int ( * ) () ) F_2 ) ;
if ( V_43 == NULL ) return ( V_32 ) ;
return ( ( * V_43 ) -> V_17 ) ;
}
int F_27 ( const char * V_47 )
{
T_1 V_28 , * V_58 = & V_28 , * * V_43 ;
T_2 V_34 , * V_35 ;
V_28 . V_3 = V_47 ;
if ( V_20 != NULL )
{
V_34 . type = V_14 ;
V_34 . V_10 = & V_28 ;
V_35 = ( T_2 * ) F_21 ( V_20 , & V_34 ) ;
if ( V_35 != NULL ) return ( V_35 -> V_10 -> V_17 ) ;
}
V_43 = ( T_1 * * ) F_25 ( ( char * ) & V_58 , ( char * ) V_61 , V_62 ,
sizeof( T_1 * ) , ( int ( * ) () ) F_1 ) ;
if ( V_43 == NULL ) return ( V_32 ) ;
return ( ( * V_43 ) -> V_17 ) ;
}
static int V_46 ( T_1 * * V_1 , T_1 * * V_2 )
{
int V_50 ;
T_1 * V_6 = * V_1 ;
T_1 * V_19 = * V_2 ;
V_50 = ( V_6 -> V_12 - V_19 -> V_12 ) ;
if ( V_50 ) return ( V_50 ) ;
return ( memcmp ( V_6 -> V_13 , V_19 -> V_13 , V_6 -> V_12 ) ) ;
}
char * F_25 ( char * V_63 , char * V_64 , int V_26 , int V_65 , int (* F_36)() )
{
int V_56 , V_66 , V_7 , V_67 ;
char * V_9 ;
if ( V_26 == 0 ) return ( NULL ) ;
V_56 = 0 ;
V_66 = V_26 ;
while ( V_56 < V_66 )
{
V_7 = ( V_56 + V_66 ) / 2 ;
V_9 = & ( V_64 [ V_7 * V_65 ] ) ;
V_67 = (* F_36)( V_63 , V_9 ) ;
if ( V_67 < 0 )
V_66 = V_7 ;
else if ( V_67 > 0 )
V_56 = V_7 + 1 ;
else
return ( V_9 ) ;
}
#ifdef F_37
for ( V_7 = 0 ; V_7 < V_26 ; ++ V_7 ) {
V_9 = & ( V_64 [ V_7 * V_65 ] ) ;
if ( (* F_36)( V_63 , V_9 ) == 0 )
return V_9 ;
}
#endif
return ( NULL ) ;
}
int F_38 ( T_3 * V_68 )
{
T_4 char V_49 [ 512 ] ;
int V_7 , V_26 = 0 ;
char * V_28 , * V_47 , * V_56 = NULL ;
for (; ; )
{
V_47 = V_28 = NULL ;
V_7 = F_39 ( V_68 , V_49 , 512 ) ;
if ( V_7 <= 0 ) return ( V_26 ) ;
V_49 [ V_7 - 1 ] = '\0' ;
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
if ( ! F_40 ( V_28 , V_47 , V_56 ) ) return ( V_26 ) ;
V_26 ++ ;
}
}
int F_40 ( char * V_69 , char * V_3 , char * V_4 )
{
int V_70 = 0 ;
T_1 * V_43 = NULL ;
unsigned char * V_49 ;
int V_7 ;
V_7 = F_29 ( NULL , 0 , V_69 , - 1 ) ;
if ( V_7 <= 0 ) return ( 0 ) ;
if ( ( V_49 = ( unsigned char * ) Malloc ( V_7 ) ) == NULL )
{
F_20 ( V_71 , V_72 ) ;
return ( 0 ) ;
}
V_7 = F_29 ( V_49 , V_7 , V_69 , - 1 ) ;
V_43 = ( T_1 * ) F_41 ( F_15 ( 1 ) , V_49 , V_7 , V_3 , V_4 ) ;
if ( V_43 == NULL )
goto V_31;
V_70 = F_16 ( V_43 ) ;
V_31:
F_11 ( V_43 ) ;
Free ( V_49 ) ;
return ( V_70 ) ;
}
