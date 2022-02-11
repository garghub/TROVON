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
V_25 = F_24 ;
}
void F_27 ( int (* F_24)( int * V_26 , int V_27 , int type ,
const char * V_23 , int line ) )
{
V_28 = F_24 ;
}
void F_28 ( T_2 * V_29 , unsigned long V_30 )
{
memset ( V_29 , 0 , sizeof( * V_29 ) ) ;
V_29 -> V_30 = V_30 ;
}
void F_29 ( T_2 * V_29 , void * V_31 )
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
int F_30 ( void (* F_24)( T_2 * ) )
{
if ( V_38 )
return 0 ;
V_38 = F_24 ;
return 1 ;
}
void F_31 ( T_2 * V_29 )
{
if ( V_38 )
{
V_38 ( V_29 ) ;
return;
}
#ifndef F_32
if ( V_39 )
{
F_28 ( V_29 , V_39 () ) ;
return;
}
#endif
#ifdef V_5
F_28 ( V_29 , ( unsigned long ) F_33 () ) ;
#elif F_2 ( V_4 )
F_28 ( V_29 , ( unsigned long ) F_34 () ) ;
#elif F_2 ( V_40 )
F_28 ( V_29 , ( unsigned long ) F_35 ( NULL ) ) ;
#else
F_29 ( V_29 , & V_41 ) ;
#endif
}
int F_36 ( const T_2 * V_42 , const T_2 * V_43 )
{
return memcmp ( V_42 , V_43 , sizeof( * V_42 ) ) ;
}
void F_37 ( T_2 * V_32 , const T_2 * V_35 )
{
memcpy ( V_32 , V_35 , sizeof( * V_35 ) ) ;
}
unsigned long F_38 ( const T_2 * V_29 )
{
return V_29 -> V_30 ;
}
unsigned long F_39 ( void )
{
unsigned long V_44 = 0 ;
if ( V_39 == NULL )
{
#ifdef V_5
V_44 = ( unsigned long ) F_33 () ;
#elif F_2 ( V_4 )
V_44 = ( unsigned long ) F_34 () ;
#elif F_2 ( V_45 )
V_44 = 1L ;
#elif F_2 ( V_40 )
V_44 = ( unsigned long ) F_35 ( NULL ) ;
#else
V_44 = ( unsigned long ) F_40 () ;
#endif
}
else
V_44 = V_39 () ;
return ( V_44 ) ;
}
void F_41 ( int V_21 , int type , const char * V_23 , int line )
{
#ifdef F_42
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
F_31 ( & V_29 ) ;
fprintf ( V_19 , L_8 ,
F_38 ( & V_29 ) , V_46 , V_47 ,
F_43 ( type ) , V_23 , line ) ;
}
#endif
if ( type < 0 )
{
if ( V_24 != NULL )
{
struct V_20 * V_11
= F_22 ( type ) ;
F_44 ( V_11 != NULL ) ;
V_24 ( V_21 , V_11 , V_23 , line ) ;
F_18 ( type ) ;
}
}
else
if ( V_25 != NULL )
V_25 ( V_21 , type , V_23 , line ) ;
}
int F_45 ( int * V_11 , int V_52 , int type , const char * V_23 ,
int line )
{
int V_44 = 0 ;
if ( V_28 != NULL )
{
#ifdef F_42
int V_53 = * V_11 ;
#endif
V_44 = V_28 ( V_11 , V_52 , type , V_23 , line ) ;
#ifdef F_42
{
T_2 V_29 ;
F_31 ( & V_29 ) ;
fprintf ( V_19 , L_9 ,
F_38 ( & V_29 ) , V_53 , V_52 , V_44 ,
F_43 ( type ) ,
V_23 , line ) ;
}
#endif
}
else
{
F_41 ( V_48 | V_51 , type , V_23 , line ) ;
V_44 = * V_11 + V_52 ;
#ifdef F_42
{
T_2 V_29 ;
F_31 ( & V_29 ) ;
fprintf ( V_19 , L_9 ,
F_38 ( & V_29 ) ,
* V_11 , V_52 , V_44 ,
F_43 ( type ) ,
V_23 , line ) ;
}
#endif
* V_11 = V_44 ;
F_41 ( V_49 | V_51 , type , V_23 , line ) ;
}
return ( V_44 ) ;
}
const char * F_43 ( int type )
{
if ( type < 0 )
return ( L_10 ) ;
else if ( type < V_10 )
return ( V_54 [ type ] ) ;
else if ( type - V_10 > F_46 ( V_7 ) )
return ( L_7 ) ;
else
return ( F_47 ( V_7 , type - V_10 ) ) ;
}
unsigned long * F_48 ( void ) { return & V_55 ; }
void F_49 ( void )
{ static int V_56 = 0 ;
unsigned long V_57 ( void ) ;
char * V_58 ;
if ( V_56 ) return;
V_56 = 1 ;
if ( ( V_58 = getenv ( L_11 ) ) )
V_55 = strtoul ( V_58 , NULL , 0 ) | ( 1 << 10 ) ;
else
V_55 = V_57 () | ( 1 << 10 ) ;
}
unsigned long * F_48 ( void ) { return NULL ; }
void F_49 ( void ) {}
BOOL T_3 F_50 ( T_4 V_59 , T_5 V_60 ,
T_6 V_61 )
{
switch( V_60 )
{
case V_62 :
F_49 () ;
#if F_2 ( V_63 )
{
T_7 * V_64 = ( T_7 * ) V_59 ;
T_8 * V_65 ;
if ( V_64 -> V_66 == V_67 )
{
V_65 = ( T_8 * ) ( ( char * ) V_64
+ V_64 -> V_68 ) ;
if ( V_65 -> V_69 == V_70 &&
V_59 != ( T_4 ) ( V_65 -> V_71 . V_72 ) )
V_73 = 1 ;
}
}
#endif
break;
case V_74 :
break;
case V_75 :
F_51 ( 0 ) ;
break;
case V_76 :
break;
}
return ( TRUE ) ;
}
int F_52 ( void )
{ T_9 V_77 ;
T_5 V_78 ;
T_10 * V_1 ;
( void ) F_53 () ;
V_77 = F_54 () ;
if ( V_77 == NULL ) return - 1 ;
if ( F_55 ( V_77 , V_79 , NULL , 0 , & V_78 ) ||
F_56 () != V_80 )
return - 1 ;
if ( V_78 > 512 ) return - 1 ;
V_78 ++ , V_78 &= ~ 1 ;
#ifdef F_57
V_1 = ( T_10 * ) F_58 ( V_78 + sizeof( T_10 ) ) ;
#else
V_1 = ( T_10 * ) F_59 ( V_78 + sizeof( T_10 ) ) ;
#endif
if ( ! F_55 ( V_77 , V_79 , V_1 , V_78 , & V_78 ) )
return - 1 ;
V_78 ++ , V_78 &= ~ 1 ;
V_1 [ V_78 / sizeof( T_10 ) ] = V_81 '\0' ;
#if 1
if ( wcsstr ( V_1 , L_12 ) ) return 1 ;
#else
if ( ! wcsstr ( V_1 , L_13 ) ) return 1 ;
#endif
else return 0 ;
}
int F_52 ( void ) { return 0 ; }
void F_60 ( const char * V_82 , ... )
{ T_11 V_83 ;
T_12 V_84 [ 256 ] ;
const T_12 * V_85 ;
#ifdef F_61
T_13 V_77 ;
if ( ( V_77 = F_62 ( F_61 ) ) != NULL &&
F_63 ( V_77 ) != V_86 )
{
va_start ( V_83 , V_82 ) ;
vfprintf ( V_19 , V_82 , V_83 ) ;
va_end ( V_83 ) ;
return;
}
#endif
if ( sizeof( T_12 ) == sizeof( char ) )
V_85 = ( const T_12 * ) V_82 ;
else do
{ int V_87 ;
T_14 V_88 = strlen ( V_82 ) + 1 , V_3 ;
T_10 * V_89 ;
#ifdef F_57
V_89 = ( T_10 * ) F_58 ( V_88 * sizeof( T_10 ) ) ;
#else
V_89 = ( T_10 * ) F_59 ( V_88 * sizeof( T_10 ) ) ;
#endif
if ( V_89 == NULL ) { V_85 = ( const T_12 * ) L_14 ; break; }
#ifndef F_64
if ( ! F_65 ( V_90 , 0 , V_82 , V_88 , V_89 , V_88 ) )
#endif
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ ) V_89 [ V_3 ] = ( T_10 ) V_82 [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_88 ; V_3 ++ )
{ if ( V_89 [ V_3 ] == V_81 '%' ) do
{ V_87 = 0 ;
switch ( V_89 [ V_3 + 1 ] )
{ case V_81 '0' : case V_81 '1' : case V_81 '2' : case V_81 '3' : case V_81 '4' :
case V_81 '5' : case V_81 '6' : case V_81 '7' : case V_81 '8' : case V_81 '9' :
case V_81 '.' : case V_81 '*' :
case V_81 '-' : V_3 ++ ; V_87 = 1 ; break;
case V_81 's' : V_89 [ V_3 + 1 ] = V_81 'S' ; break;
case V_81 'S' : V_89 [ V_3 + 1 ] = V_81 's' ; break;
case V_81 'c' : V_89 [ V_3 + 1 ] = V_81 'C' ; break;
case V_81 'C' : V_89 [ V_3 + 1 ] = V_81 'c' ; break;
}
} while ( V_87 );
}
V_85 = ( const T_12 * ) V_89 ;
} while ( 0 );
va_start ( V_83 , V_82 ) ;
F_66 ( V_84 , sizeof( V_84 ) / sizeof( T_12 ) - 1 , V_85 , V_83 ) ;
V_84 [ sizeof( V_84 ) / sizeof( T_12 ) - 1 ] = F_67 ( '\0' ) ;
va_end ( V_83 ) ;
#if F_2 ( V_63 ) && V_63 >= 0x0333
if ( F_68 () < 0x80000000 && F_52 () > 0 )
{ T_13 V_77 = F_69 ( 0 , F_67 ( L_15 ) ) ;
const T_12 * V_91 = V_84 ;
F_70 ( V_77 , V_92 , 0 , 0 , 0 , 1 , 0 , & V_91 , 0 ) ;
F_71 ( V_77 ) ;
}
else
#endif
F_72 ( NULL , V_84 , F_67 ( L_16 ) , V_93 | V_94 ) ;
}
void F_60 ( const char * V_82 , ... )
{ T_11 V_83 ;
va_start ( V_83 , V_82 ) ;
vfprintf ( V_19 , V_82 , V_83 ) ;
va_end ( V_83 ) ;
}
int F_52 ( void ) { return 0 ; }
void F_73 ( const char * V_23 , int line , const char * V_95 )
{
F_60 (
L_17 ,
V_23 , line , V_95 ) ;
#if ! F_2 ( V_96 ) || F_2 ( V_97 )
abort () ;
#else
raise ( V_98 ) ;
F_74 ( 3 ) ;
#endif
}
void * F_75 ( void ) { return V_19 ; }
