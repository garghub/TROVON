int F_1 ( char * V_1 )
{
char * V_2 ;
int V_3 ;
#if F_2 ( V_4 ) || F_2 ( V_5 )
V_6 = ( double ) V_1 [ 0 ] * ( double ) V_1 [ 1 ] ;
#endif
if ( ( V_7 == NULL ) && ( ( V_7 = F_3 () ) == NULL ) )
{
F_4 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
if ( ( V_2 = F_5 ( V_1 ) ) == NULL )
{
F_4 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
V_3 = F_6 ( V_7 , V_2 ) ;
if ( ! V_3 )
F_7 ( V_2 ) ;
else
V_3 += V_10 ;
return ( V_3 ) ;
}
int F_8 ( void )
{
return V_10 ;
}
int F_9 ( void )
{
int V_3 = 0 ;
T_1 * V_11 = NULL ;
if ( V_12 == NULL )
{
F_4 ( V_13 , V_14 ) ;
return ( 0 ) ;
}
F_10 ( V_15 ) ;
if ( ( V_16 == NULL )
&& ( ( V_16 = F_11 () ) == NULL ) )
{
F_12 ( V_15 ) ;
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
F_12 ( V_15 ) ;
V_11 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
V_11 -> V_17 = 1 ;
V_11 -> V_18 = V_12 ( __FILE__ , __LINE__ ) ;
if ( V_11 -> V_18 == NULL )
{
F_7 ( V_11 ) ;
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
F_10 ( V_15 ) ;
V_3 = F_14 ( V_16 , NULL ) ;
if ( V_3 == - 1 )
V_3 = F_15 ( V_16 , V_11 ) - 1 ;
else
( void ) F_16 ( V_16 , V_3 , V_11 ) ;
F_12 ( V_15 ) ;
if ( V_3 == - 1 )
{
F_17 ( V_11 -> V_18 , __FILE__ , __LINE__ ) ;
F_7 ( V_11 ) ;
}
else
V_3 += 1 ;
return - V_3 ;
}
void F_18 ( int V_3 )
{
T_1 * V_11 = NULL ;
if ( V_3 )
V_3 = - V_3 - 1 ;
if ( F_17 == NULL )
return;
F_10 ( V_15 ) ;
if ( V_16 == NULL || V_3 >= F_19 ( V_16 ) )
{
F_12 ( V_15 ) ;
return;
}
V_11 = F_20 ( V_16 , V_3 ) ;
if ( V_11 != NULL )
{
-- V_11 -> V_17 ;
#ifdef F_21
if ( V_11 -> V_17 < 0 )
{
fprintf ( V_19 , L_1 ) ;
abort () ;
}
else
#endif
if ( V_11 -> V_17 <= 0 )
{
( void ) F_16 ( V_16 , V_3 , NULL ) ;
}
else
V_11 = NULL ;
}
F_12 ( V_15 ) ;
if ( V_11 )
{
F_17 ( V_11 -> V_18 , __FILE__ , __LINE__ ) ;
F_7 ( V_11 ) ;
}
}
struct V_20 * F_22 ( int V_3 )
{
T_1 * V_11 = NULL ;
if ( V_3 )
V_3 = - V_3 - 1 ;
F_10 ( V_15 ) ;
if ( V_16 != NULL && V_3 < F_19 ( V_16 ) )
V_11 = F_20 ( V_16 , V_3 ) ;
if ( V_11 )
V_11 -> V_17 ++ ;
F_12 ( V_15 ) ;
if ( V_11 )
return V_11 -> V_18 ;
return NULL ;
}
void F_23 ( void (* F_24)( int V_21 ,
struct V_20 * V_22 , const char * V_23 , int line ) )
{
V_24 = F_24 ;
}
void F_25 ( void (* F_24)
( struct V_20 * V_22 , const char * V_23 , int line ) )
{
F_17 = F_24 ;
}
void F_26 ( void (* F_24)( int V_21 , int type ,
const char * V_23 , int line ) )
{
F_27 () ;
V_25 = F_24 ;
}
void F_28 ( int (* F_24)( int * V_26 , int V_27 , int type ,
const char * V_23 , int line ) )
{
V_28 = F_24 ;
}
void F_29 ( T_2 * V_29 , unsigned long V_30 )
{
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_30 = V_30 ;
}
void F_30 ( T_2 * V_29 , void * V_31 )
{
unsigned char * V_32 = ( void * ) & V_29 -> V_30 ;
unsigned int V_33 = 0 ;
unsigned char V_34 = sizeof( V_29 -> V_30 ) ;
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_31 = V_31 ;
if ( sizeof( V_29 -> V_30 ) >= sizeof( V_29 -> V_31 ) )
{
V_29 -> V_30 = ( unsigned long ) V_29 -> V_31 ;
return;
}
while ( V_34 -- )
{
const unsigned char * V_35 = ( void * ) & V_29 -> V_31 ;
unsigned char V_36 = sizeof( V_29 -> V_31 ) ;
while ( V_36 -- )
V_33 += * ( V_35 ++ ) * V_37 [ ( V_36 + V_34 ) & 7 ] ;
V_33 += V_34 ;
* ( V_32 ++ ) = V_33 & 255 ;
}
}
int F_31 ( void (* F_24)( T_2 * ) )
{
if ( V_38 )
return 0 ;
V_38 = F_24 ;
return 1 ;
}
void F_32 ( T_2 * V_29 )
{
if ( V_38 )
{
V_38 ( V_29 ) ;
return;
}
#ifndef F_33
if ( V_39 )
{
F_29 ( V_29 , V_39 () ) ;
return;
}
#endif
#ifdef V_5
F_29 ( V_29 , ( unsigned long ) F_34 () ) ;
#elif F_2 ( V_4 )
F_29 ( V_29 , ( unsigned long ) F_35 () ) ;
#elif F_2 ( V_40 )
F_29 ( V_29 , ( unsigned long ) F_36 ( NULL ) ) ;
#else
F_30 ( V_29 , & V_41 ) ;
#endif
}
int F_37 ( const T_2 * V_42 , const T_2 * V_43 )
{
return memcmp ( V_42 , V_43 , sizeof( * V_42 ) ) ;
}
void F_38 ( T_2 * V_32 , const T_2 * V_35 )
{
memcpy ( V_32 , V_35 , sizeof( * V_35 ) ) ;
}
unsigned long F_39 ( const T_2 * V_29 )
{
return V_29 -> V_30 ;
}
unsigned long F_40 ( void )
{
unsigned long V_44 = 0 ;
if ( V_39 == NULL )
{
#ifdef V_5
V_44 = ( unsigned long ) F_34 () ;
#elif F_2 ( V_4 )
V_44 = ( unsigned long ) F_35 () ;
#elif F_2 ( V_45 )
V_44 = 1L ;
#elif F_2 ( V_40 )
V_44 = ( unsigned long ) F_36 ( NULL ) ;
#else
V_44 = ( unsigned long ) F_41 () ;
#endif
}
else
V_44 = V_39 () ;
return ( V_44 ) ;
}
void F_42 ( int V_21 , int type , const char * V_23 , int line )
{
#ifdef F_43
{
T_2 V_29 ;
char * V_46 , * V_47 ;
if ( V_21 & V_48 )
V_47 = L_2 ;
else if ( V_21 & V_49 )
V_47 = L_3 ;
else
V_47 = L_4 ;
if ( V_21 & V_50 )
V_46 = L_5 ;
else if ( V_21 & V_51 )
V_46 = L_6 ;
else
V_46 = L_7 ;
F_32 ( & V_29 ) ;
fprintf ( V_19 , L_8 ,
F_39 ( & V_29 ) , V_46 , V_47 ,
F_44 ( type ) , V_23 , line ) ;
}
#endif
if ( type < 0 )
{
if ( V_24 != NULL )
{
struct V_20 * V_11
= F_22 ( type ) ;
F_45 ( V_11 != NULL ) ;
V_24 ( V_21 , V_11 , V_23 , line ) ;
F_18 ( type ) ;
}
}
else
if ( V_25 != NULL )
V_25 ( V_21 , type , V_23 , line ) ;
}
int F_46 ( int * V_11 , int V_52 , int type , const char * V_23 ,
int line )
{
int V_44 = 0 ;
if ( V_28 != NULL )
{
#ifdef F_43
int V_53 = * V_11 ;
#endif
V_44 = V_28 ( V_11 , V_52 , type , V_23 , line ) ;
#ifdef F_43
{
T_2 V_29 ;
F_32 ( & V_29 ) ;
fprintf ( V_19 , L_9 ,
F_39 ( & V_29 ) , V_53 , V_52 , V_44 ,
F_44 ( type ) ,
V_23 , line ) ;
}
#endif
}
else
{
F_42 ( V_48 | V_51 , type , V_23 , line ) ;
V_44 = * V_11 + V_52 ;
#ifdef F_43
{
T_2 V_29 ;
F_32 ( & V_29 ) ;
fprintf ( V_19 , L_9 ,
F_39 ( & V_29 ) ,
* V_11 , V_52 , V_44 ,
F_44 ( type ) ,
V_23 , line ) ;
}
#endif
* V_11 = V_44 ;
F_42 ( V_49 | V_51 , type , V_23 , line ) ;
}
return ( V_44 ) ;
}
const char * F_44 ( int type )
{
if ( type < 0 )
return ( L_10 ) ;
else if ( type < V_10 )
return ( V_54 [ type ] ) ;
else if ( type - V_10 > F_47 ( V_7 ) )
return ( L_7 ) ;
else
return ( F_48 ( V_7 , type - V_10 ) ) ;
}
unsigned long * F_49 ( void )
{ if ( sizeof( long ) == 4 )
V_55 [ 1 ] = 0 ;
return ( unsigned long * ) V_55 ;
}
void F_50 ( void )
{ static int V_56 = 0 ;
T_3 V_57 ( void ) ;
T_3 V_58 ;
char * V_59 ;
if ( V_56 ) return;
V_56 = 1 ;
if ( ( V_59 = getenv ( L_11 ) ) ) {
int V_60 = ( V_59 [ 0 ] == '~' ) ? 1 : 0 ;
#if F_2 ( V_61 )
if ( ! sscanf ( V_59 + V_60 , L_12 , & V_58 ) ) V_58 = strtoul ( V_59 + V_60 , NULL , 0 ) ;
#else
if ( ! sscanf ( V_59 + V_60 , L_13 , ( long long * ) & V_58 ) ) V_58 = strtoul ( V_59 + V_60 , NULL , 0 ) ;
#endif
if ( V_60 ) V_58 = V_57 () & ~ V_58 ;
}
else
V_58 = V_57 () ;
V_55 [ 0 ] = ( unsigned int ) V_58 | ( 1 << 10 ) ;
V_55 [ 1 ] = ( unsigned int ) ( V_58 >> 32 ) ;
}
unsigned long * F_49 ( void ) { return NULL ; }
void F_50 ( void ) {}
BOOL T_4 F_51 ( T_5 V_62 , T_6 V_63 ,
T_7 V_64 )
{
switch( V_63 )
{
case V_65 :
F_50 () ;
#if F_2 ( V_66 )
{
T_8 * V_67 = ( T_8 * ) V_62 ;
T_9 * V_68 ;
if ( V_67 -> V_69 == V_70 )
{
V_68 = ( T_9 * ) ( ( char * ) V_67
+ V_67 -> V_71 ) ;
if ( V_68 -> V_72 == V_73 &&
V_62 != ( T_5 ) ( V_68 -> V_74 . V_75 ) )
V_76 = 1 ;
}
}
#endif
break;
case V_77 :
break;
case V_78 :
break;
case V_79 :
break;
}
return ( TRUE ) ;
}
int F_52 ( void )
{ T_10 V_80 ;
T_6 V_81 ;
T_11 * V_1 ;
static union { void * V_82 ; int (* F_53)( void ); } V_83 = { NULL } ;
if ( V_83 . V_82 == NULL ) {
T_12 V_80 = F_54 ( NULL ) ;
if ( V_80 != NULL )
V_83 . V_82 = F_55 ( V_80 , L_14 ) ;
if ( V_83 . V_82 == NULL )
V_83 . V_82 = ( void * ) - 1 ;
}
if ( V_83 . V_82 != ( void * ) - 1 )
return (* V_83 . F_53 )() ;
( void ) F_56 () ;
V_80 = F_57 () ;
if ( V_80 == NULL ) return - 1 ;
if ( F_58 ( V_80 , V_84 , NULL , 0 , & V_81 ) ||
F_59 () != V_85 )
return - 1 ;
if ( V_81 > 512 ) return - 1 ;
V_81 ++ , V_81 &= ~ 1 ;
V_1 = ( T_11 * ) F_60 ( V_81 + sizeof( T_11 ) ) ;
if ( ! F_58 ( V_80 , V_84 , V_1 , V_81 , & V_81 ) )
return - 1 ;
V_81 ++ , V_81 &= ~ 1 ;
V_1 [ V_81 / sizeof( T_11 ) ] = V_86 '\0' ;
#if 1
if ( wcsstr ( V_1 , L_15 ) ) return 1 ;
#else
if ( ! wcsstr ( V_1 , L_16 ) ) return 1 ;
#endif
else return 0 ;
}
int F_52 ( void ) { return 0 ; }
void F_61 ( const char * V_87 , ... )
{ T_13 V_88 ;
T_14 V_89 [ 256 ] ;
const T_14 * V_90 ;
#ifdef F_62
T_12 V_80 ;
if ( ( V_80 = F_63 ( F_62 ) ) != NULL &&
F_64 ( V_80 ) != V_91 )
{
va_start ( V_88 , V_87 ) ;
vfprintf ( V_19 , V_87 , V_88 ) ;
va_end ( V_88 ) ;
return;
}
#endif
if ( sizeof( T_14 ) == sizeof( char ) )
V_90 = ( const T_14 * ) V_87 ;
else do
{ int V_92 ;
T_15 V_93 = strlen ( V_87 ) + 1 , V_3 ;
T_11 * V_94 ;
V_94 = ( T_11 * ) F_60 ( V_93 * sizeof( T_11 ) ) ;
if ( V_94 == NULL ) { V_90 = ( const T_14 * ) L_17 ; break; }
#ifndef F_65
if ( ! F_66 ( V_95 , 0 , V_87 , V_93 , V_94 , V_93 ) )
#endif
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ ) V_94 [ V_3 ] = ( T_11 ) V_87 [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ )
{ if ( V_94 [ V_3 ] == V_86 '%' ) do
{ V_92 = 0 ;
switch ( V_94 [ V_3 + 1 ] )
{ case V_86 '0' : case V_86 '1' : case V_86 '2' : case V_86 '3' : case V_86 '4' :
case V_86 '5' : case V_86 '6' : case V_86 '7' : case V_86 '8' : case V_86 '9' :
case V_86 '.' : case V_86 '*' :
case V_86 '-' : V_3 ++ ; V_92 = 1 ; break;
case V_86 's' : V_94 [ V_3 + 1 ] = V_86 'S' ; break;
case V_86 'S' : V_94 [ V_3 + 1 ] = V_86 's' ; break;
case V_86 'c' : V_94 [ V_3 + 1 ] = V_86 'C' ; break;
case V_86 'C' : V_94 [ V_3 + 1 ] = V_86 'c' ; break;
}
} while ( V_92 );
}
V_90 = ( const T_14 * ) V_94 ;
} while ( 0 );
va_start ( V_88 , V_87 ) ;
F_67 ( V_89 , sizeof( V_89 ) / sizeof( T_14 ) - 1 , V_90 , V_88 ) ;
V_89 [ sizeof( V_89 ) / sizeof( T_14 ) - 1 ] = F_68 ( '\0' ) ;
va_end ( V_88 ) ;
#if F_2 ( V_66 ) && V_66 >= 0x0333
if ( F_69 () < 0x80000000 && F_52 () > 0 )
{ T_12 V_80 = F_70 ( 0 , F_68 ( L_18 ) ) ;
const T_14 * V_96 = V_89 ;
F_71 ( V_80 , V_97 , 0 , 0 , 0 , 1 , 0 , & V_96 , 0 ) ;
F_72 ( V_80 ) ;
}
else
#endif
F_73 ( NULL , V_89 , F_68 ( L_19 ) , V_98 | V_99 ) ;
}
void F_61 ( const char * V_87 , ... )
{ T_13 V_88 ;
va_start ( V_88 , V_87 ) ;
vfprintf ( V_19 , V_87 , V_88 ) ;
va_end ( V_88 ) ;
}
int F_52 ( void ) { return 0 ; }
void F_74 ( const char * V_23 , int line , const char * V_100 )
{
F_61 (
L_20 ,
V_23 , line , V_100 ) ;
#if ! F_2 ( V_61 ) || F_2 ( V_101 )
abort () ;
#else
raise ( V_102 ) ;
F_75 ( 3 ) ;
#endif
}
void * F_76 ( void ) { return V_19 ; }
