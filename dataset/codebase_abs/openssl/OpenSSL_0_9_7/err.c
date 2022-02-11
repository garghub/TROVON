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
V_5 = V_14 ;
F_3 ( V_2 ) ;
return V_5 ;
}
static T_4 * F_22 ( const T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_17 ) ( 0 ) ;
if ( ! V_12 )
return NULL ;
F_14 ( V_2 ) ;
V_11 = ( T_4 * ) F_15 ( V_12 , V_10 ) ;
F_16 ( V_2 ) ;
return V_11 ;
}
static T_4 * F_23 ( T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_17 ) ( 1 ) ;
if ( ! V_12 )
return NULL ;
F_2 ( V_2 ) ;
V_11 = ( T_4 * ) F_18 ( V_12 , V_10 ) ;
F_3 ( V_2 ) ;
return V_11 ;
}
static void F_24 ( const T_4 * V_10 )
{
T_4 * V_11 ;
T_2 * V_12 ;
F_1 () ;
V_12 = F_13 ( V_17 ) ( 0 ) ;
if ( ! V_12 )
return;
F_2 ( V_2 ) ;
V_11 = ( T_4 * ) F_20 ( V_12 , V_10 ) ;
if ( V_14 && ( F_25 ( V_14 ) == 0 ) )
{
F_11 ( V_14 ) ;
V_14 = NULL ;
}
F_3 ( V_2 ) ;
if ( V_11 )
F_26 ( V_11 ) ;
}
static int F_27 ( void )
{
int V_5 ;
F_2 ( V_2 ) ;
V_5 = V_18 ++ ;
F_3 ( V_2 ) ;
return V_5 ;
}
static void F_28 ()
{
static char V_19 [ V_20 ] [ V_21 ] ;
int V_22 ;
static int V_23 = 1 ;
if ( ! V_23 ) return;
F_2 ( V_2 ) ;
for ( V_22 = 1 ; V_22 <= V_20 ; V_22 ++ )
{
T_3 * V_24 = & V_25 [ V_22 - 1 ] ;
V_24 -> error = ( unsigned long ) V_22 ;
if ( V_24 -> string == NULL )
{
char ( * V_26 ) [ V_21 ] = & ( V_19 [ V_22 - 1 ] ) ;
char * V_27 = strerror ( V_22 ) ;
if ( V_27 != NULL )
{
strncpy ( * V_26 , V_27 , sizeof *V_26 ) ;
( * V_26 ) [ sizeof *V_26 - 1] = '\0' ;
V_24 -> string = * V_26 ;
}
}
if ( V_24 -> string == NULL )
V_24 -> string = L_3 ;
}
V_23 = 0 ;
F_3 ( V_2 ) ;
}
static void F_26 ( T_4 * V_28 )
{
int V_22 ;
if ( V_28 == NULL )
return;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ )
{
F_29 ( V_28 , V_22 ) ;
}
F_30 ( V_28 ) ;
}
void F_31 ( void )
{
F_1 () ;
#ifndef F_32
F_33 ( 0 , V_30 ) ;
F_33 ( 0 , V_31 ) ;
F_33 ( V_32 , V_33 ) ;
F_28 () ;
F_33 ( V_32 , V_25 ) ;
#endif
}
static void F_33 ( int V_34 , T_3 * V_24 )
{
while ( V_24 -> error )
{
V_24 -> error |= F_34 ( V_34 , 0 , 0 ) ;
F_13 (F_35)( V_24 );
V_24 ++ ;
}
}
void F_36 ( int V_34 , T_3 * V_24 )
{
F_31 () ;
F_33 ( V_34 , V_24 ) ;
}
void F_37 ( int V_34 , T_3 * V_24 )
{
while ( V_24 -> error )
{
V_24 -> error |= F_34 ( V_34 , 0 , 0 ) ;
F_13 (F_38)( V_24 );
V_24 ++ ;
}
}
void F_39 ( void )
{
F_1 () ;
F_13 (F_40)();
}
void F_41 ( int V_34 , int V_35 , int V_36 , const char * V_37 ,
int line )
{
T_4 * V_38 ;
#ifdef F_42
if ( strncmp ( V_37 , L_4 , sizeof( L_4 ) - 1 ) == 0 ) {
char * V_39 ;
V_37 += sizeof( L_4 ) - 1 ;
V_39 = & V_37 [ strlen ( V_37 ) - 1 ] ;
if ( * V_39 == ')' )
* V_39 = '\0' ;
if ( ( V_39 = strrchr ( V_37 , '/' ) ) != NULL )
V_37 = & V_39 [ 1 ] ;
}
#endif
V_38 = F_43 () ;
V_38 -> V_40 = ( V_38 -> V_40 + 1 ) % V_29 ;
if ( V_38 -> V_40 == V_38 -> V_41 )
V_38 -> V_41 = ( V_38 -> V_41 + 1 ) % V_29 ;
V_38 -> V_42 [ V_38 -> V_40 ] = F_34 ( V_34 , V_35 , V_36 ) ;
V_38 -> V_43 [ V_38 -> V_40 ] = V_37 ;
V_38 -> V_44 [ V_38 -> V_40 ] = line ;
F_29 ( V_38 , V_38 -> V_40 ) ;
}
void F_44 ( void )
{
int V_22 ;
T_4 * V_38 ;
V_38 = F_43 () ;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ )
{
V_38 -> V_42 [ V_22 ] = 0 ;
F_29 ( V_38 , V_22 ) ;
V_38 -> V_43 [ V_22 ] = NULL ;
V_38 -> V_44 [ V_22 ] = - 1 ;
}
V_38 -> V_40 = V_38 -> V_41 = 0 ;
}
unsigned long F_45 ( void )
{ return ( F_46 ( 1 , 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_47 ( const char * * V_37 ,
int * line )
{ return ( F_46 ( 1 , 0 , V_37 , line , NULL , NULL ) ) ; }
unsigned long F_48 ( const char * * V_37 , int * line ,
const char * * V_45 , int * V_46 )
{ return ( F_46 ( 1 , 0 , V_37 , line , V_45 , V_46 ) ) ; }
unsigned long F_49 ( void )
{ return ( F_46 ( 0 , 0 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_50 ( const char * * V_37 , int * line )
{ return ( F_46 ( 0 , 0 , V_37 , line , NULL , NULL ) ) ; }
unsigned long F_51 ( const char * * V_37 , int * line ,
const char * * V_45 , int * V_46 )
{ return ( F_46 ( 0 , 0 , V_37 , line , V_45 , V_46 ) ) ; }
unsigned long F_52 ( void )
{ return ( F_46 ( 0 , 1 , NULL , NULL , NULL , NULL ) ) ; }
unsigned long F_53 ( const char * * V_37 , int * line )
{ return ( F_46 ( 0 , 1 , V_37 , line , NULL , NULL ) ) ; }
unsigned long F_54 ( const char * * V_37 , int * line ,
const char * * V_45 , int * V_46 )
{ return ( F_46 ( 0 , 1 , V_37 , line , V_45 , V_46 ) ) ; }
static unsigned long F_46 ( int V_47 , int V_40 , const char * * V_37 , int * line ,
const char * * V_45 , int * V_46 )
{
int V_22 = 0 ;
T_4 * V_38 ;
unsigned long V_5 ;
V_38 = F_43 () ;
if ( V_47 && V_40 )
{
if ( V_37 ) * V_37 = L_5 ;
if ( line ) * line = 0 ;
if ( V_45 ) * V_45 = L_5 ;
if ( V_46 ) * V_46 = 0 ;
return V_48 ;
}
if ( V_38 -> V_41 == V_38 -> V_40 ) return 0 ;
if ( V_40 )
V_22 = V_38 -> V_40 ;
else
V_22 = ( V_38 -> V_41 + 1 ) % V_29 ;
V_5 = V_38 -> V_42 [ V_22 ] ;
if ( V_47 )
{
V_38 -> V_41 = V_22 ;
V_38 -> V_42 [ V_22 ] = 0 ;
}
if ( ( V_37 != NULL ) && ( line != NULL ) )
{
if ( V_38 -> V_43 [ V_22 ] == NULL )
{
* V_37 = L_6 ;
if ( line != NULL ) * line = 0 ;
}
else
{
* V_37 = V_38 -> V_43 [ V_22 ] ;
if ( line != NULL ) * line = V_38 -> V_44 [ V_22 ] ;
}
}
if ( V_45 == NULL )
{
if ( V_47 )
{
F_29 ( V_38 , V_22 ) ;
}
}
else
{
if ( V_38 -> V_49 [ V_22 ] == NULL )
{
* V_45 = L_5 ;
if ( V_46 != NULL ) * V_46 = 0 ;
}
else
{
* V_45 = V_38 -> V_49 [ V_22 ] ;
if ( V_46 != NULL ) * V_46 = V_38 -> V_50 [ V_22 ] ;
}
}
return V_5 ;
}
void F_55 ( unsigned long V_51 , char * V_52 , T_5 V_53 )
{
char V_54 [ 64 ] , V_55 [ 64 ] , V_56 [ 64 ] ;
const char * V_57 , * V_58 , * V_59 ;
unsigned long V_60 , V_61 , V_62 ;
V_60 = F_56 ( V_51 ) ;
V_61 = F_57 ( V_51 ) ;
V_62 = F_58 ( V_51 ) ;
V_57 = F_59 ( V_51 ) ;
V_58 = F_60 ( V_51 ) ;
V_59 = F_61 ( V_51 ) ;
if ( V_57 == NULL )
F_62 ( V_54 , sizeof( V_54 ) , L_7 , V_60 ) ;
if ( V_58 == NULL )
F_62 ( V_55 , sizeof( V_55 ) , L_8 , V_61 ) ;
if ( V_59 == NULL )
F_62 ( V_56 , sizeof( V_56 ) , L_9 , V_62 ) ;
F_62 ( V_52 , V_53 , L_10 , V_51 , V_57 ? V_57 : V_54 ,
V_58 ? V_58 : V_55 , V_59 ? V_59 : V_56 ) ;
if ( strlen ( V_52 ) == V_53 - 1 )
{
#define F_63 4
if ( V_53 > F_63 )
{
int V_22 ;
char * V_28 = V_52 ;
for ( V_22 = 0 ; V_22 < F_63 ; V_22 ++ )
{
char * V_63 = strchr ( V_28 , ':' ) ;
if ( V_63 == NULL || V_63 > & V_52 [ V_53 - 1 ] - F_63 + V_22 )
{
V_63 = & V_52 [ V_53 - 1 ] - F_63 + V_22 ;
* V_63 = ':' ;
}
V_28 = V_63 + 1 ;
}
}
}
}
char * F_64 ( unsigned long V_51 , char * V_5 )
{
static char V_52 [ 256 ] ;
if ( V_5 == NULL ) V_5 = V_52 ;
F_55 ( V_51 , V_5 , 256 ) ;
return V_5 ;
}
T_2 * F_65 ( void )
{
F_1 () ;
return F_13 ( V_13 ) ( 0 ) ;
}
T_2 * F_66 ( void )
{
F_1 () ;
return F_13 ( V_17 ) ( 0 ) ;
}
const char * F_59 ( unsigned long V_51 )
{
T_3 V_10 , * V_11 ;
unsigned long V_60 ;
F_1 () ;
V_60 = F_56 ( V_51 ) ;
V_10 . error = F_34 ( V_60 , 0 , 0 ) ;
V_11 = F_13 ( V_64 ) ( & V_10 ) ;
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
const char * F_60 ( unsigned long V_51 )
{
T_3 V_10 , * V_11 ;
unsigned long V_60 , V_61 ;
F_1 () ;
V_60 = F_56 ( V_51 ) ;
V_61 = F_57 ( V_51 ) ;
V_10 . error = F_34 ( V_60 , V_61 , 0 ) ;
V_11 = F_13 ( V_64 ) ( & V_10 ) ;
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
const char * F_61 ( unsigned long V_51 )
{
T_3 V_10 , * V_11 = NULL ;
unsigned long V_60 , V_62 ;
F_1 () ;
V_60 = F_56 ( V_51 ) ;
V_62 = F_58 ( V_51 ) ;
V_10 . error = F_34 ( V_60 , 0 , V_62 ) ;
V_11 = F_13 ( V_64 ) ( & V_10 ) ;
if ( ! V_11 )
{
V_10 . error = F_34 ( 0 , 0 , V_62 ) ;
V_11 = F_13 ( V_64 ) ( & V_10 ) ;
}
return ( ( V_11 == NULL ) ? NULL : V_11 -> string ) ;
}
static unsigned long V_8 ( const void * V_65 )
{
unsigned long V_5 , V_60 ;
V_60 = ( ( T_3 * ) V_65 ) -> error ;
V_5 = V_60 ^ F_56 ( V_60 ) ^ F_57 ( V_60 ) ;
return ( V_5 ^ V_5 % 19 * 13 ) ;
}
static int V_9 ( const void * V_65 , const void * V_66 )
{
return ( ( int ) ( ( ( T_3 * ) V_65 ) -> error -
( ( T_3 * ) V_66 ) -> error ) ) ;
}
static unsigned long V_15 ( const void * V_65 )
{
return ( ( ( T_4 * ) V_65 ) -> V_67 * 13 ) ;
}
static int V_16 ( const void * V_65 , const void * V_66 )
{
return ( ( int ) ( ( long ) ( ( T_4 * ) V_65 ) -> V_67 -
( long ) ( ( T_4 * ) V_66 ) -> V_67 ) ) ;
}
void F_67 ( unsigned long V_67 )
{
T_4 V_68 ;
F_1 () ;
if ( V_67 == 0 )
V_67 = ( unsigned long ) F_68 () ;
V_68 . V_67 = V_67 ;
F_13 ( V_69 ) ( & V_68 ) ;
}
T_4 * F_43 ( void )
{
static T_4 V_70 ;
T_4 * V_5 , V_68 , * V_71 = NULL ;
int V_22 ;
unsigned long V_67 ;
F_1 () ;
V_67 = ( unsigned long ) F_68 () ;
V_68 . V_67 = V_67 ;
V_5 = F_13 ( V_72 ) ( & V_68 ) ;
if ( V_5 == NULL )
{
V_5 = ( T_4 * ) F_69 ( sizeof( T_4 ) ) ;
if ( V_5 == NULL ) return ( & V_70 ) ;
V_5 -> V_67 = V_67 ;
V_5 -> V_40 = 0 ;
V_5 -> V_41 = 0 ;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ )
{
V_5 -> V_49 [ V_22 ] = NULL ;
V_5 -> V_50 [ V_22 ] = 0 ;
}
V_71 = F_13 ( V_73 ) ( V_5 ) ;
if ( F_13 ( V_72 ) ( V_5 ) != V_5 )
{
F_26 ( V_5 ) ;
return ( & V_70 ) ;
}
if ( V_71 )
F_26 ( V_71 ) ;
}
return V_5 ;
}
int F_70 ( void )
{
F_1 () ;
return F_13 ( V_74 ) () ;
}
void F_71 ( char * V_45 , int V_46 )
{
T_4 * V_38 ;
int V_22 ;
V_38 = F_43 () ;
V_22 = V_38 -> V_40 ;
if ( V_22 == 0 )
V_22 = V_29 - 1 ;
F_29 ( V_38 , V_22 ) ;
V_38 -> V_49 [ V_22 ] = V_45 ;
V_38 -> V_50 [ V_22 ] = V_46 ;
}
void F_72 ( int V_75 , ... )
{
T_6 args ;
int V_22 , V_76 , V_28 ;
char * V_24 , * V_11 , * V_77 ;
V_28 = 80 ;
V_24 = F_69 ( V_28 + 1 ) ;
if ( V_24 == NULL ) return;
V_24 [ 0 ] = '\0' ;
va_start ( args , V_75 ) ;
V_76 = 0 ;
for ( V_22 = 0 ; V_22 < V_75 ; V_22 ++ )
{
V_77 = va_arg ( args , char * ) ;
if ( V_77 != NULL )
{
V_76 += strlen ( V_77 ) ;
if ( V_76 > V_28 )
{
V_28 = V_76 + 20 ;
V_11 = F_73 ( V_24 , V_28 + 1 ) ;
if ( V_11 == NULL )
{
F_30 ( V_24 ) ;
goto V_78;
}
else
V_24 = V_11 ;
}
strcat ( V_24 , V_77 ) ;
}
}
F_71 ( V_24 , V_79 | V_80 ) ;
V_78:
va_end ( args ) ;
}
