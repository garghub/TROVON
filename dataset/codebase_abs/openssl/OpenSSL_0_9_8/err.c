static void F_1 ( void )
{
if ( V_1 ) return;
F_2 ( V_2 ) ;
if ( ! V_1 )
V_1 = & V_3 ;
F_3 ( V_2 ) ;
}
const T_1 * F_4 ( void )
{
F_1 () ;
return V_1 ;
}
int F_5 ( const T_1 * V_4 )
{
int V_5 = 0 ;
F_2 ( V_2 ) ;
if ( ! V_1 )
{
V_1 = V_4 ;
V_5 = 1 ;
}
F_3 ( V_2 ) ;
return V_5 ;
}
static T_2 * F_6 ( int V_6 )
{
T_2 * V_5 = NULL ;
F_2 ( V_2 ) ;
if ( ! V_7 && V_6 )
{
F_7 ( L_1 ) ;
V_7 = F_8 ( V_8 , V_9 ) ;
F_9 () ;
}
if ( V_7 )
V_5 = V_7 ;
F_3 ( V_2 ) ;
return V_5 ;
}
static void F_10 ( void )
{
F_2 ( V_2 ) ;
if ( V_7 )
{
F_11 ( V_7 ) ;
V_7 = NULL ;
}
F_3 ( V_2 ) ;
}
static T_3 * F_12 ( const T_3 * V_10 )
{
T_3 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_13 ) ( 0 ) ;
if ( ! V_12 )
return NULL ;
F_14 ( V_2 ) ;
V_11 = ( T_3 * ) F_15 ( V_12 , V_10 ) ;
F_16 ( V_2 ) ;
return V_11 ;
}
static T_3 * F_17 ( T_3 * V_10 )
{
T_3 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_13 ) ( 1 ) ;
if ( ! V_12 )
return NULL ;
F_2 ( V_2 ) ;
V_11 = ( T_3 * ) F_18 ( V_12 , V_10 ) ;
F_3 ( V_2 ) ;
return V_11 ;
}
static T_3 * F_19 ( T_3 * V_10 )
{
T_3 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_13 ) ( 0 ) ;
if ( ! V_12 )
return NULL ;
F_2 ( V_2 ) ;
V_11 = ( T_3 * ) F_20 ( V_12 , V_10 ) ;
F_3 ( V_2 ) ;
return V_11 ;
}
static T_2 * F_21 ( int V_6 )
{
T_2 * V_5 = NULL ;
F_2 ( V_2 ) ;
if ( ! V_14 && V_6 )
{
F_7 ( L_2 ) ;
V_14 = F_8 ( V_15 , V_16 ) ;
F_9 () ;
}
if ( V_14 )
{
V_17 ++ ;
V_5 = V_14 ;
}
F_3 ( V_2 ) ;
return V_5 ;
}
static void F_22 ( T_2 * * V_12 )
{
int V_18 ;
if ( V_12 == NULL || * V_12 == NULL )
return;
V_18 = F_23 ( & V_17 , - 1 , V_2 ) ;
#ifdef F_24
fprintf ( V_19 , L_3 , V_17 , L_4 ) ;
#endif
if ( V_18 > 0 ) return;
#ifdef F_25
if ( V_18 < 0 )
{
fprintf ( V_19 , L_5 ) ;
abort () ;
}
#endif
* V_12 = NULL ;
}
static T_4 * F_26 ( const T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_20 ) ( 0 ) ;
if ( ! V_12 )
return NULL ;
F_14 ( V_2 ) ;
V_11 = ( T_4 * ) F_15 ( V_12 , V_10 ) ;
F_16 ( V_2 ) ;
F_13 ( V_21 ) ( & V_12 ) ;
return V_11 ;
}
static T_4 * F_27 ( T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_20 ) ( 1 ) ;
if ( ! V_12 )
return NULL ;
F_2 ( V_2 ) ;
V_11 = ( T_4 * ) F_18 ( V_12 , V_10 ) ;
F_3 ( V_2 ) ;
F_13 ( V_21 ) ( & V_12 ) ;
return V_11 ;
}
static void F_28 ( const T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_20 ) ( 0 ) ;
if ( ! V_12 )
return;
F_2 ( V_2 ) ;
V_11 = ( T_4 * ) F_20 ( V_12 , V_10 ) ;
if ( V_17 == 1
&& V_14 && ( F_29 ( V_14 ) == 0 ) )
{
F_11 ( V_14 ) ;
V_14 = NULL ;
}
F_3 ( V_2 ) ;
F_13 ( V_21 ) ( & V_12 ) ;
if ( V_11 )
F_30 ( V_11 ) ;
}
static int F_31 ( void )
{
int V_5 ;
F_2 ( V_2 ) ;
V_5 = V_22 ++ ;
F_3 ( V_2 ) ;
return V_5 ;
}
static void F_32 ( void )
{
static char V_23 [ V_24 ] [ V_25 ] ;
int V_18 ;
static int V_26 = 1 ;
if ( ! V_26 ) return;
F_2 ( V_2 ) ;
for ( V_18 = 1 ; V_18 <= V_24 ; V_18 ++ )
{
T_3 * V_27 = & V_28 [ V_18 - 1 ] ;
V_27 -> error = ( unsigned long ) V_18 ;
if ( V_27 -> string == NULL )
{
char ( * V_29 ) [ V_25 ] = & ( V_23 [ V_18 - 1 ] ) ;
char * V_30 = strerror ( V_18 ) ;
if ( V_30 != NULL )
{
strncpy ( * V_29 , V_30 , sizeof *V_29 ) ;
( * V_29 ) [ sizeof *V_29 - 1] = '\0' ;
V_27 -> string = * V_29 ;
}
}
if ( V_27 -> string == NULL )
V_27 -> string = L_6 ;
}
V_26 = 0 ;
F_3 ( V_2 ) ;
}
static void F_30 ( T_4 * V_31 )
{
int V_18 ;
if ( V_31 == NULL )
return;
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ )
{
F_33 ( V_31 , V_18 ) ;
}
F_34 ( V_31 ) ;
}
void F_35 ( void )
{
F_1 () ;
#ifndef F_36
F_37 ( 0 , V_33 ) ;
F_37 ( 0 , V_34 ) ;
F_37 ( V_35 , V_36 ) ;
F_32 () ;
F_37 ( V_35 , V_28 ) ;
#endif
}
static void F_37 ( int V_37 , T_3 * V_27 )
{
while ( V_27 -> error )
{
if ( V_37 )
V_27 -> error |= F_38 ( V_37 , 0 , 0 ) ;
F_13 (F_39)( V_27 );
V_27 ++ ;
}
}
void F_40 ( int V_37 , T_3 * V_27 )
{
F_35 () ;
F_37 ( V_37 , V_27 ) ;
}
void F_41 ( int V_37 , T_3 * V_27 )
{
while ( V_27 -> error )
{
if ( V_37 )
V_27 -> error |= F_38 ( V_37 , 0 , 0 ) ;
F_13 (F_42)( V_27 );
V_27 ++ ;
}
}
void F_43 ( void )
{
F_1 () ;
F_13 (F_44)();
}
void F_45 ( int V_37 , int V_38 , int V_39 , const char * V_40 ,
int line )
{
T_4 * V_41 ;
#ifdef F_46
if ( strncmp ( V_40 , L_7 , sizeof( L_7 ) - 1 ) == 0 ) {
char * V_42 ;
V_40 += sizeof( L_7 ) - 1 ;
V_42 = & V_40 [ strlen ( V_40 ) - 1 ] ;
if ( * V_42 == ')' )
* V_42 = '\0' ;
if ( ( V_42 = strrchr ( V_40 , '/' ) ) != NULL )
V_40 = & V_42 [ 1 ] ;
}
#endif
V_41 = F_47 () ;
V_41 -> V_43 = ( V_41 -> V_43 + 1 ) % V_32 ;
if ( V_41 -> V_43 == V_41 -> V_44 )
V_41 -> V_44 = ( V_41 -> V_44 + 1 ) % V_32 ;
V_41 -> V_45 [ V_41 -> V_43 ] = 0 ;
V_41 -> V_46 [ V_41 -> V_43 ] = F_38 ( V_37 , V_38 , V_39 ) ;
V_41 -> V_47 [ V_41 -> V_43 ] = V_40 ;
V_41 -> V_48 [ V_41 -> V_43 ] = line ;
F_33 ( V_41 , V_41 -> V_43 ) ;
}
void F_48 ( void )
{
int V_18 ;
T_4 * V_41 ;
V_41 = F_47 () ;
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ )
{
F_49 ( V_41 , V_18 ) ;
}
V_41 -> V_43 = V_41 -> V_44 = 0 ;
}
unsigned long F_50 ( void )
{ return ( F_51 ( 1 , 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_52 ( const char * * V_40 ,
int * line )
{ return ( F_51 ( 1 , 0 , V_40 , line , NULL , NULL ) ) ; }
unsigned long F_53 ( const char * * V_40 , int * line ,
const char * * V_49 , int * V_50 )
{ return ( F_51 ( 1 , 0 , V_40 , line , V_49 , V_50 ) ) ; }
unsigned long F_54 ( void )
{ return ( F_51 ( 0 , 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_55 ( const char * * V_40 , int * line )
{ return ( F_51 ( 0 , 0 , V_40 , line , NULL , NULL ) ) ; }
unsigned long F_56 ( const char * * V_40 , int * line ,
const char * * V_49 , int * V_50 )
{ return ( F_51 ( 0 , 0 , V_40 , line , V_49 , V_50 ) ) ; }
unsigned long F_57 ( void )
{ return ( F_51 ( 0 , 1 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_58 ( const char * * V_40 , int * line )
{ return ( F_51 ( 0 , 1 , V_40 , line , NULL , NULL ) ) ; }
unsigned long F_59 ( const char * * V_40 , int * line ,
const char * * V_49 , int * V_50 )
{ return ( F_51 ( 0 , 1 , V_40 , line , V_49 , V_50 ) ) ; }
static unsigned long F_51 ( int V_51 , int V_43 , const char * * V_40 , int * line ,
const char * * V_49 , int * V_50 )
{
int V_18 = 0 ;
T_4 * V_41 ;
unsigned long V_5 ;
V_41 = F_47 () ;
if ( V_51 && V_43 )
{
if ( V_40 ) * V_40 = L_8 ;
if ( line ) * line = 0 ;
if ( V_49 ) * V_49 = L_8 ;
if ( V_50 ) * V_50 = 0 ;
return V_52 ;
}
if ( V_41 -> V_44 == V_41 -> V_43 ) return 0 ;
if ( V_43 )
V_18 = V_41 -> V_43 ;
else
V_18 = ( V_41 -> V_44 + 1 ) % V_32 ;
V_5 = V_41 -> V_46 [ V_18 ] ;
if ( V_51 )
{
V_41 -> V_44 = V_18 ;
V_41 -> V_46 [ V_18 ] = 0 ;
}
if ( ( V_40 != NULL ) && ( line != NULL ) )
{
if ( V_41 -> V_47 [ V_18 ] == NULL )
{
* V_40 = L_9 ;
if ( line != NULL ) * line = 0 ;
}
else
{
* V_40 = V_41 -> V_47 [ V_18 ] ;
if ( line != NULL ) * line = V_41 -> V_48 [ V_18 ] ;
}
}
if ( V_49 == NULL )
{
if ( V_51 )
{
F_33 ( V_41 , V_18 ) ;
}
}
else
{
if ( V_41 -> V_53 [ V_18 ] == NULL )
{
* V_49 = L_8 ;
if ( V_50 != NULL ) * V_50 = 0 ;
}
else
{
* V_49 = V_41 -> V_53 [ V_18 ] ;
if ( V_50 != NULL ) * V_50 = V_41 -> V_54 [ V_18 ] ;
}
}
return V_5 ;
}
void F_60 ( unsigned long V_55 , char * V_56 , T_5 V_57 )
{
char V_58 [ 64 ] , V_59 [ 64 ] , V_60 [ 64 ] ;
const char * V_61 , * V_62 , * V_63 ;
unsigned long V_64 , V_65 , V_66 ;
V_64 = F_61 ( V_55 ) ;
V_65 = F_62 ( V_55 ) ;
V_66 = F_63 ( V_55 ) ;
V_61 = F_64 ( V_55 ) ;
V_62 = F_65 ( V_55 ) ;
V_63 = F_66 ( V_55 ) ;
if ( V_61 == NULL )
F_67 ( V_58 , sizeof( V_58 ) , L_10 , V_64 ) ;
if ( V_62 == NULL )
F_67 ( V_59 , sizeof( V_59 ) , L_11 , V_65 ) ;
if ( V_63 == NULL )
F_67 ( V_60 , sizeof( V_60 ) , L_12 , V_66 ) ;
F_67 ( V_56 , V_57 , L_13 , V_55 , V_61 ? V_61 : V_58 ,
V_62 ? V_62 : V_59 , V_63 ? V_63 : V_60 ) ;
if ( strlen ( V_56 ) == V_57 - 1 )
{
#define F_68 4
if ( V_57 > F_68 )
{
int V_18 ;
char * V_31 = V_56 ;
for ( V_18 = 0 ; V_18 < F_68 ; V_18 ++ )
{
char * V_67 = strchr ( V_31 , ':' ) ;
if ( V_67 == NULL || V_67 > & V_56 [ V_57 - 1 ] - F_68 + V_18 )
{
V_67 = & V_56 [ V_57 - 1 ] - F_68 + V_18 ;
* V_67 = ':' ;
}
V_31 = V_67 + 1 ;
}
}
}
}
char * F_69 ( unsigned long V_55 , char * V_5 )
{
static char V_56 [ 256 ] ;
if ( V_5 == NULL ) V_5 = V_56 ;
F_60 ( V_55 , V_5 , 256 ) ;
return V_5 ;
}
T_2 * F_70 ( void )
{
F_1 () ;
return F_13 ( V_13 ) ( 0 ) ;
}
T_2 * F_71 ( void )
{
F_1 () ;
return F_13 ( V_20 ) ( 0 ) ;
}
void F_72 ( T_2 * * V_12 )
{
F_1 () ;
F_13 (V_21)( V_12 );
}
const char * F_64 ( unsigned long V_55 )
{
T_3 V_10 , * V_11 ;
unsigned long V_64 ;
F_1 () ;
V_64 = F_61 ( V_55 ) ;
V_10 . error = F_38 ( V_64 , 0 , 0 ) ;
V_11 = F_13 ( V_68 ) ( & V_10 ) ;
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
const char * F_65 ( unsigned long V_55 )
{
T_3 V_10 , * V_11 ;
unsigned long V_64 , V_65 ;
F_1 () ;
V_64 = F_61 ( V_55 ) ;
V_65 = F_62 ( V_55 ) ;
V_10 . error = F_38 ( V_64 , V_65 , 0 ) ;
V_11 = F_13 ( V_68 ) ( & V_10 ) ;
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
const char * F_66 ( unsigned long V_55 )
{
T_3 V_10 , * V_11 = NULL ;
unsigned long V_64 , V_66 ;
F_1 () ;
V_64 = F_61 ( V_55 ) ;
V_66 = F_63 ( V_55 ) ;
V_10 . error = F_38 ( V_64 , 0 , V_66 ) ;
V_11 = F_13 ( V_68 ) ( & V_10 ) ;
if ( ! V_11 )
{
V_10 . error = F_38 ( 0 , 0 , V_66 ) ;
V_11 = F_13 ( V_68 ) ( & V_10 ) ;
}
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
static unsigned long V_8 ( const void * V_69 )
{
unsigned long V_5 , V_64 ;
V_64 = ( ( const T_3 * ) V_69 ) -> error ;
V_5 = V_64 ^ F_61 ( V_64 ) ^ F_62 ( V_64 ) ;
return ( V_5 ^ V_5 % 19 * 13 ) ;
}
static int V_9 ( const void * V_69 , const void * V_70 )
{
return ( ( int ) ( ( ( const T_3 * ) V_69 ) -> error -
( ( const T_3 * ) V_70 ) -> error ) ) ;
}
static unsigned long V_15 ( const void * V_69 )
{
return ( ( ( const T_4 * ) V_69 ) -> V_71 * 13 ) ;
}
static int V_16 ( const void * V_69 , const void * V_70 )
{
return ( ( int ) ( ( long ) ( ( const T_4 * ) V_69 ) -> V_71 -
( long ) ( ( const T_4 * ) V_70 ) -> V_71 ) ) ;
}
void F_73 ( unsigned long V_71 )
{
T_4 V_72 ;
F_1 () ;
if ( V_71 == 0 )
V_71 = ( unsigned long ) F_74 () ;
V_72 . V_71 = V_71 ;
F_13 ( V_73 ) ( & V_72 ) ;
}
T_4 * F_47 ( void )
{
static T_4 V_74 ;
T_4 * V_5 , V_72 , * V_75 = NULL ;
int V_18 ;
unsigned long V_71 ;
F_1 () ;
V_71 = ( unsigned long ) F_74 () ;
V_72 . V_71 = V_71 ;
V_5 = F_13 ( V_76 ) ( & V_72 ) ;
if ( V_5 == NULL )
{
V_5 = ( T_4 * ) F_75 ( sizeof( T_4 ) ) ;
if ( V_5 == NULL ) return ( & V_74 ) ;
V_5 -> V_71 = V_71 ;
V_5 -> V_43 = 0 ;
V_5 -> V_44 = 0 ;
for ( V_18 = 0 ; V_18 < V_32 ; V_18 ++ )
{
V_5 -> V_53 [ V_18 ] = NULL ;
V_5 -> V_54 [ V_18 ] = 0 ;
}
V_75 = F_13 ( V_77 ) ( V_5 ) ;
if ( F_13 ( V_76 ) ( V_5 ) != V_5 )
{
F_30 ( V_5 ) ;
return ( & V_74 ) ;
}
if ( V_75 )
F_30 ( V_75 ) ;
}
return V_5 ;
}
int F_76 ( void )
{
F_1 () ;
return F_13 ( V_78 ) () ;
}
void F_77 ( char * V_49 , int V_50 )
{
T_4 * V_41 ;
int V_18 ;
V_41 = F_47 () ;
V_18 = V_41 -> V_43 ;
if ( V_18 == 0 )
V_18 = V_32 - 1 ;
F_33 ( V_41 , V_18 ) ;
V_41 -> V_53 [ V_18 ] = V_49 ;
V_41 -> V_54 [ V_18 ] = V_50 ;
}
void F_78 ( int V_79 , ... )
{
T_6 args ;
int V_18 , V_80 , V_31 ;
char * V_27 , * V_11 , * V_81 ;
V_31 = 80 ;
V_27 = F_75 ( V_31 + 1 ) ;
if ( V_27 == NULL ) return;
V_27 [ 0 ] = '\0' ;
va_start ( args , V_79 ) ;
V_80 = 0 ;
for ( V_18 = 0 ; V_18 < V_79 ; V_18 ++ )
{
V_81 = va_arg ( args , char * ) ;
if ( V_81 != NULL )
{
V_80 += strlen ( V_81 ) ;
if ( V_80 > V_31 )
{
V_31 = V_80 + 20 ;
V_11 = F_79 ( V_27 , V_31 + 1 ) ;
if ( V_11 == NULL )
{
F_34 ( V_27 ) ;
goto V_82;
}
else
V_27 = V_11 ;
}
F_80 ( V_27 , V_81 , ( T_5 ) V_31 + 1 ) ;
}
}
F_77 ( V_27 , V_83 | V_84 ) ;
V_82:
va_end ( args ) ;
}
int F_81 ( void )
{
T_4 * V_41 ;
V_41 = F_47 () ;
if ( V_41 -> V_44 == V_41 -> V_43 ) return 0 ;
V_41 -> V_45 [ V_41 -> V_43 ] |= V_85 ;
return 1 ;
}
int F_82 ( void )
{
T_4 * V_41 ;
V_41 = F_47 () ;
while( V_41 -> V_44 != V_41 -> V_43
&& ( V_41 -> V_45 [ V_41 -> V_43 ] & V_85 ) == 0 )
{
F_49 ( V_41 , V_41 -> V_43 ) ;
V_41 -> V_43 -= 1 ;
if ( V_41 -> V_43 == - 1 ) V_41 -> V_43 = V_32 ;
}
if ( V_41 -> V_44 == V_41 -> V_43 ) return 0 ;
V_41 -> V_45 [ V_41 -> V_43 ] &= ~ V_85 ;
return 1 ;
}
