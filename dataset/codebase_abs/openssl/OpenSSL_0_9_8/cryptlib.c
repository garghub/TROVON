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
F_16 ( V_16 , V_3 , V_11 ) ;
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
F_16 ( V_16 , V_3 , NULL ) ;
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
unsigned long F_28 ( void )
{
unsigned long V_29 = 0 ;
if ( V_30 == NULL )
{
#ifdef V_5
V_29 = ( unsigned long ) F_29 () ;
#elif F_2 ( V_4 )
V_29 = ( unsigned long ) F_30 () ;
#elif F_2 ( V_31 )
V_29 = 1L ;
#else
V_29 = ( unsigned long ) F_31 () ;
#endif
}
else
V_29 = V_30 () ;
return ( V_29 ) ;
}
void F_32 ( int V_21 , int type , const char * V_23 , int line )
{
#ifdef F_33
{
char * V_32 , * V_33 ;
if ( V_21 & V_34 )
V_33 = L_2 ;
else if ( V_21 & V_35 )
V_33 = L_3 ;
else
V_33 = L_4 ;
if ( V_21 & V_36 )
V_32 = L_5 ;
else if ( V_21 & V_37 )
V_32 = L_6 ;
else
V_32 = L_7 ;
fprintf ( V_19 , L_8 ,
F_28 () , V_32 , V_33 ,
F_34 ( type ) , V_23 , line ) ;
}
#endif
if ( type < 0 )
{
if ( V_24 != NULL )
{
struct V_20 * V_11
= F_22 ( type ) ;
F_35 ( V_11 != NULL ) ;
V_24 ( V_21 , V_11 , V_23 , line ) ;
F_18 ( type ) ;
}
}
else
if ( V_25 != NULL )
V_25 ( V_21 , type , V_23 , line ) ;
}
int F_36 ( int * V_11 , int V_38 , int type , const char * V_23 ,
int line )
{
int V_29 = 0 ;
if ( V_28 != NULL )
{
#ifdef F_33
int V_39 = * V_11 ;
#endif
V_29 = V_28 ( V_11 , V_38 , type , V_23 , line ) ;
#ifdef F_33
fprintf ( V_19 , L_9 ,
F_28 () ,
V_39 , V_38 , V_29 ,
F_34 ( type ) ,
V_23 , line ) ;
#endif
}
else
{
F_32 ( V_34 | V_37 , type , V_23 , line ) ;
V_29 = * V_11 + V_38 ;
#ifdef F_33
fprintf ( V_19 , L_9 ,
F_28 () ,
* V_11 , V_38 , V_29 ,
F_34 ( type ) ,
V_23 , line ) ;
#endif
* V_11 = V_29 ;
F_32 ( V_35 | V_37 , type , V_23 , line ) ;
}
return ( V_29 ) ;
}
const char * F_34 ( int type )
{
if ( type < 0 )
return ( L_10 ) ;
else if ( type < V_10 )
return ( V_40 [ type ] ) ;
else if ( type - V_10 > F_37 ( V_7 ) )
return ( L_7 ) ;
else
return ( F_38 ( V_7 , type - V_10 ) ) ;
}
unsigned long * F_39 ( void ) { return & V_41 ; }
void F_40 ( void )
{ static int V_42 = 0 ;
unsigned long V_43 ( void ) ;
char * V_44 ;
if ( V_42 ) return;
V_42 = 1 ;
if ( ( V_44 = getenv ( L_11 ) ) )
V_41 = strtoul ( V_44 , NULL , 0 ) | ( 1 << 10 ) ;
else
V_41 = V_43 () | ( 1 << 10 ) ;
}
unsigned long * F_39 ( void ) { return NULL ; }
void F_40 ( void ) {}
BOOL T_2 F_41 ( T_3 V_45 , T_4 V_46 ,
T_5 V_47 )
{
switch( V_46 )
{
case V_48 :
F_40 () ;
#if F_2 ( V_49 )
{
T_6 * V_50 = ( T_6 * ) V_45 ;
T_7 * V_51 ;
if ( V_50 -> V_52 == V_53 )
{
V_51 = ( T_7 * ) ( ( char * ) V_50
+ V_50 -> V_54 ) ;
if ( V_51 -> V_55 == V_56 &&
V_45 != ( T_3 ) ( V_51 -> V_57 . V_58 ) )
V_59 = 1 ;
}
}
#endif
break;
case V_60 :
break;
case V_61 :
F_42 ( 0 ) ;
break;
case V_62 :
break;
}
return ( TRUE ) ;
}
int F_43 ( void )
{ T_8 V_63 ;
T_4 V_64 ;
T_9 * V_1 ;
( void ) F_44 () ;
V_63 = F_45 () ;
if ( V_63 == NULL ) return - 1 ;
if ( F_46 ( V_63 , V_65 , NULL , 0 , & V_64 ) ||
F_47 () != V_66 )
return - 1 ;
if ( V_64 > 512 ) return - 1 ;
V_64 ++ , V_64 &= ~ 1 ;
#ifdef F_48
V_1 = ( T_9 * ) F_49 ( V_64 + sizeof( T_9 ) ) ;
#else
V_1 = ( T_9 * ) F_50 ( V_64 + sizeof( T_9 ) ) ;
#endif
if ( ! F_46 ( V_63 , V_65 , V_1 , V_64 , & V_64 ) )
return - 1 ;
V_64 ++ , V_64 &= ~ 1 ;
V_1 [ V_64 / sizeof( T_9 ) ] = V_67 '\0' ;
#if 1
if ( wcsstr ( V_1 , L_12 ) ) return 1 ;
#else
if ( ! wcsstr ( V_1 , L_13 ) ) return 1 ;
#endif
else return 0 ;
}
void F_51 ( const char * V_68 , ... )
{ T_10 V_69 ;
T_11 V_70 [ 256 ] ;
const T_11 * V_71 ;
T_12 V_63 ;
if ( ( V_63 = F_52 ( V_72 ) ) != NULL &&
F_53 ( V_63 ) != V_73 )
{
va_start ( V_69 , V_68 ) ;
vfprintf ( V_19 , V_68 , V_69 ) ;
va_end ( V_69 ) ;
return;
}
if ( sizeof( T_11 ) == sizeof( char ) )
V_71 = V_68 ;
else do
{ int V_74 ;
T_13 V_75 = strlen ( V_68 ) + 1 , V_3 ;
T_9 * V_76 ;
#ifdef F_48
V_76 = ( T_9 * ) F_49 ( V_75 * sizeof( T_9 ) ) ;
#else
V_76 = ( T_9 * ) F_50 ( V_75 * sizeof( T_9 ) ) ;
#endif
if ( V_76 == NULL ) { V_71 = ( const T_11 * ) L_14 ; break; }
#ifndef F_54
if ( ! F_55 ( V_77 , 0 , V_68 , V_75 , V_76 , V_75 ) )
#endif
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ ) V_76 [ V_3 ] = ( T_9 ) V_68 [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
{ if ( V_76 [ V_3 ] == V_67 '%' ) do
{ V_74 = 0 ;
switch ( V_76 [ V_3 + 1 ] )
{ case V_67 '0' : case V_67 '1' : case V_67 '2' : case V_67 '3' : case V_67 '4' :
case V_67 '5' : case V_67 '6' : case V_67 '7' : case V_67 '8' : case V_67 '9' :
case V_67 '.' : case V_67 '*' :
case V_67 '-' : V_3 ++ ; V_74 = 1 ; break;
case V_67 's' : V_76 [ V_3 + 1 ] = V_67 'S' ; break;
case V_67 'S' : V_76 [ V_3 + 1 ] = V_67 's' ; break;
case V_67 'c' : V_76 [ V_3 + 1 ] = V_67 'C' ; break;
case V_67 'C' : V_76 [ V_3 + 1 ] = V_67 'c' ; break;
}
} while ( V_74 );
}
V_71 = ( const T_11 * ) V_76 ;
} while ( 0 );
va_start ( V_69 , V_68 ) ;
F_56 ( V_70 , sizeof( V_70 ) / sizeof( T_11 ) - 1 , V_71 , V_69 ) ;
V_70 [ sizeof( V_70 ) / sizeof( T_11 ) - 1 ] = F_57 ( '\0' ) ;
va_end ( V_69 ) ;
#if F_2 ( V_49 ) && V_49 >= 0x0333
if ( F_58 () < 0x80000000 && F_43 () )
{ T_12 V_63 = F_59 ( 0 , F_57 ( L_15 ) ) ;
const T_11 * V_78 = V_70 ;
F_60 ( V_63 , V_79 , 0 , 0 , 0 , 1 , 0 , & V_78 , 0 ) ;
F_61 ( V_63 ) ;
}
else
#endif
{ T_14 V_80 ;
V_80 . V_81 = sizeof( V_80 ) ;
V_80 . V_82 = NULL ;
V_80 . V_83 = F_57 ( L_16 ) ;
V_80 . V_84 = V_85 ;
V_80 . V_86 = NULL ;
V_80 . V_87 = V_88 ;
V_80 . V_89 = 0 ;
V_80 . V_90 = NULL ;
V_80 . V_91 = F_62 ( V_92 , V_93 ) ;
V_80 . V_94 = V_70 ;
F_63 ( & V_80 ) ;
}
}
void F_51 ( const char * V_68 , ... )
{ T_10 V_69 ;
va_start ( V_69 , V_68 ) ;
vfprintf ( V_19 , V_68 , V_69 ) ;
va_end ( V_69 ) ;
}
int F_43 ( void ) { return 0 ; }
void F_64 ( const char * V_23 , int line , const char * V_95 )
{
F_51 (
L_17 ,
V_23 , line , V_95 ) ;
abort () ;
}
void * F_65 ( void ) { return V_19 ; }
