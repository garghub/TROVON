static void F_1 ( void )
{
if ( V_1 )
return;
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
if ( ! V_1 ) {
V_1 = V_4 ;
V_5 = 1 ;
}
F_3 ( V_2 ) ;
return V_5 ;
}
static unsigned long F_6 ( const T_2 * V_6 )
{
unsigned long V_5 , V_7 ;
V_7 = V_6 -> error ;
V_5 = V_7 ^ F_7 ( V_7 ) ^ F_8 ( V_7 ) ;
return ( V_5 ^ V_5 % 19 * 13 ) ;
}
void F_9 ( void )
{
F_2 ( V_2 ) ;
if ( V_8 ) {
F_10 ( V_8 ) ;
V_8 = NULL ;
}
F_3 ( V_2 ) ;
}
static T_2 * F_11 ( const T_2 * V_9 )
{
T_2 * V_10 ;
F_12 ( T_2 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_12 ) ( 0 ) ;
if ( ! V_11 )
return NULL ;
F_14 ( V_2 ) ;
V_10 = F_15 ( V_11 , V_9 ) ;
F_16 ( V_2 ) ;
return V_10 ;
}
static T_2 * F_17 ( T_2 * V_9 )
{
T_2 * V_10 ;
F_12 ( T_2 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_12 ) ( 1 ) ;
if ( ! V_11 )
return NULL ;
F_2 ( V_2 ) ;
V_10 = F_18 ( V_11 , V_9 ) ;
F_3 ( V_2 ) ;
return V_10 ;
}
static T_2 * F_19 ( T_2 * V_9 )
{
T_2 * V_10 ;
F_12 ( T_2 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_12 ) ( 0 ) ;
if ( ! V_11 )
return NULL ;
F_2 ( V_2 ) ;
V_10 = F_20 ( V_11 , V_9 ) ;
F_3 ( V_2 ) ;
return V_10 ;
}
static unsigned long F_21 ( const T_3 * V_6 )
{
return F_22 ( & V_6 -> V_13 ) * 13 ;
}
static T_3 * F_23 ( const T_3 * V_9 )
{
T_3 * V_10 ;
F_12 ( T_3 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_14 ) ( 0 ) ;
if ( ! V_11 )
return NULL ;
F_14 ( V_2 ) ;
V_10 = F_24 ( V_11 , V_9 ) ;
F_16 ( V_2 ) ;
F_13 ( V_15 ) ( & V_11 ) ;
return V_10 ;
}
static T_3 * F_25 ( T_3 * V_9 )
{
T_3 * V_10 ;
F_12 ( T_3 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_14 ) ( 1 ) ;
if ( ! V_11 )
return NULL ;
F_2 ( V_2 ) ;
V_10 = F_26 ( V_11 , V_9 ) ;
F_3 ( V_2 ) ;
F_13 ( V_15 ) ( & V_11 ) ;
return V_10 ;
}
static void F_27 ( const T_3 * V_9 )
{
T_3 * V_10 ;
F_12 ( T_3 ) * V_11 ;
F_1 () ;
V_11 = F_13 ( V_14 ) ( 0 ) ;
if ( ! V_11 )
return;
F_2 ( V_2 ) ;
V_10 = F_28 ( V_11 , V_9 ) ;
if ( V_16 == 1
&& V_17 && F_29 ( V_17 ) == 0 ) {
F_30 ( V_17 ) ;
V_17 = NULL ;
}
F_3 ( V_2 ) ;
F_13 ( V_15 ) ( & V_11 ) ;
if ( V_10 )
F_31 ( V_10 ) ;
}
static int F_32 ( void )
{
int V_5 ;
F_2 ( V_2 ) ;
V_5 = V_18 ++ ;
F_3 ( V_2 ) ;
return V_5 ;
}
static void F_33 ( void )
{
static char V_19 [ V_20 ] [ V_21 ] ;
int V_22 ;
static int V_23 = 1 ;
F_14 ( V_2 ) ;
if ( ! V_23 ) {
F_16 ( V_2 ) ;
return;
}
F_16 ( V_2 ) ;
F_2 ( V_2 ) ;
if ( ! V_23 ) {
F_3 ( V_2 ) ;
return;
}
for ( V_22 = 1 ; V_22 <= V_20 ; V_22 ++ ) {
T_2 * V_24 = & V_25 [ V_22 - 1 ] ;
V_24 -> error = ( unsigned long ) V_22 ;
if ( V_24 -> string == NULL ) {
char ( * V_26 ) [ V_21 ] = & ( V_19 [ V_22 - 1 ] ) ;
char * V_27 = strerror ( V_22 ) ;
if ( V_27 != NULL ) {
strncpy ( * V_26 , V_27 , sizeof *V_26 ) ;
( * V_26 ) [ sizeof *V_26 - 1] = '\0' ;
V_24 -> string = * V_26 ;
}
}
if ( V_24 -> string == NULL )
V_24 -> string = L_1 ;
}
V_23 = 0 ;
F_3 ( V_2 ) ;
}
static void F_31 ( T_3 * V_28 )
{
int V_22 ;
if ( V_28 == NULL )
return;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ ) {
F_34 ( V_28 , V_22 ) ;
}
F_35 ( V_28 ) ;
}
void F_36 ( void )
{
F_1 () ;
#ifndef F_37
F_38 ( 0 , V_30 ) ;
F_38 ( 0 , V_31 ) ;
F_38 ( V_32 , V_33 ) ;
F_33 () ;
F_38 ( V_32 , V_25 ) ;
#endif
}
static void F_38 ( int V_34 , T_2 * V_24 )
{
while ( V_24 -> error ) {
if ( V_34 )
V_24 -> error |= F_39 ( V_34 , 0 , 0 ) ;
F_13 (F_40) ( V_24 );
V_24 ++ ;
}
}
void F_41 ( int V_34 , T_2 * V_24 )
{
F_36 () ;
F_38 ( V_34 , V_24 ) ;
}
void F_42 ( int V_34 , T_2 * V_24 )
{
while ( V_24 -> error ) {
if ( V_34 )
V_24 -> error |= F_39 ( V_34 , 0 , 0 ) ;
F_13 (F_43) ( V_24 );
V_24 ++ ;
}
}
void F_44 ( void )
{
F_1 () ;
F_13 (F_45) ();
}
void F_46 ( int V_34 , int V_35 , int V_36 , const char * V_37 , int line )
{
T_3 * V_38 ;
#ifdef F_47
if ( strncmp ( V_37 , L_2 , sizeof( L_2 ) - 1 ) == 0 ) {
char * V_39 ;
V_37 += sizeof( L_2 ) - 1 ;
V_39 = & V_37 [ strlen ( V_37 ) - 1 ] ;
if ( * V_39 == ')' )
* V_39 = '\0' ;
if ( ( V_39 = strrchr ( V_37 , '/' ) ) != NULL )
V_37 = & V_39 [ 1 ] ;
}
#endif
V_38 = F_48 () ;
V_38 -> V_40 = ( V_38 -> V_40 + 1 ) % V_29 ;
if ( V_38 -> V_40 == V_38 -> V_41 )
V_38 -> V_41 = ( V_38 -> V_41 + 1 ) % V_29 ;
V_38 -> V_42 [ V_38 -> V_40 ] = 0 ;
V_38 -> V_43 [ V_38 -> V_40 ] = F_39 ( V_34 , V_35 , V_36 ) ;
V_38 -> V_44 [ V_38 -> V_40 ] = V_37 ;
V_38 -> V_45 [ V_38 -> V_40 ] = line ;
F_34 ( V_38 , V_38 -> V_40 ) ;
}
void F_49 ( void )
{
int V_22 ;
T_3 * V_38 ;
V_38 = F_48 () ;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ ) {
F_50 ( V_38 , V_22 ) ;
}
V_38 -> V_40 = V_38 -> V_41 = 0 ;
}
unsigned long F_51 ( void )
{
return ( F_52 ( 1 , 0 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_53 ( const char * * V_37 , int * line )
{
return ( F_52 ( 1 , 0 , V_37 , line , NULL , NULL ) ) ;
}
unsigned long F_54 ( const char * * V_37 , int * line ,
const char * * V_46 , int * V_47 )
{
return ( F_52 ( 1 , 0 , V_37 , line , V_46 , V_47 ) ) ;
}
unsigned long F_55 ( void )
{
return ( F_52 ( 0 , 0 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_56 ( const char * * V_37 , int * line )
{
return ( F_52 ( 0 , 0 , V_37 , line , NULL , NULL ) ) ;
}
unsigned long F_57 ( const char * * V_37 , int * line ,
const char * * V_46 , int * V_47 )
{
return ( F_52 ( 0 , 0 , V_37 , line , V_46 , V_47 ) ) ;
}
unsigned long F_58 ( void )
{
return ( F_52 ( 0 , 1 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_59 ( const char * * V_37 , int * line )
{
return ( F_52 ( 0 , 1 , V_37 , line , NULL , NULL ) ) ;
}
unsigned long F_60 ( const char * * V_37 , int * line ,
const char * * V_46 , int * V_47 )
{
return ( F_52 ( 0 , 1 , V_37 , line , V_46 , V_47 ) ) ;
}
static unsigned long F_52 ( int V_48 , int V_40 , const char * * V_37 ,
int * line , const char * * V_46 ,
int * V_47 )
{
int V_22 = 0 ;
T_3 * V_38 ;
unsigned long V_5 ;
V_38 = F_48 () ;
if ( V_48 && V_40 ) {
if ( V_37 )
* V_37 = L_3 ;
if ( line )
* line = 0 ;
if ( V_46 )
* V_46 = L_3 ;
if ( V_47 )
* V_47 = 0 ;
return V_49 ;
}
if ( V_38 -> V_41 == V_38 -> V_40 )
return 0 ;
if ( V_40 )
V_22 = V_38 -> V_40 ;
else
V_22 = ( V_38 -> V_41 + 1 ) % V_29 ;
V_5 = V_38 -> V_43 [ V_22 ] ;
if ( V_48 ) {
V_38 -> V_41 = V_22 ;
V_38 -> V_43 [ V_22 ] = 0 ;
}
if ( ( V_37 != NULL ) && ( line != NULL ) ) {
if ( V_38 -> V_44 [ V_22 ] == NULL ) {
* V_37 = L_4 ;
if ( line != NULL )
* line = 0 ;
} else {
* V_37 = V_38 -> V_44 [ V_22 ] ;
if ( line != NULL )
* line = V_38 -> V_45 [ V_22 ] ;
}
}
if ( V_46 == NULL ) {
if ( V_48 ) {
F_34 ( V_38 , V_22 ) ;
}
} else {
if ( V_38 -> V_50 [ V_22 ] == NULL ) {
* V_46 = L_3 ;
if ( V_47 != NULL )
* V_47 = 0 ;
} else {
* V_46 = V_38 -> V_50 [ V_22 ] ;
if ( V_47 != NULL )
* V_47 = V_38 -> V_51 [ V_22 ] ;
}
}
return V_5 ;
}
void F_61 ( unsigned long V_52 , char * V_53 , T_4 V_54 )
{
char V_55 [ 64 ] , V_56 [ 64 ] , V_57 [ 64 ] ;
const char * V_58 , * V_59 , * V_60 ;
unsigned long V_7 , V_61 , V_62 ;
V_7 = F_7 ( V_52 ) ;
V_61 = F_8 ( V_52 ) ;
V_62 = F_62 ( V_52 ) ;
V_58 = F_63 ( V_52 ) ;
V_59 = F_64 ( V_52 ) ;
V_60 = F_65 ( V_52 ) ;
if ( V_58 == NULL )
F_66 ( V_55 , sizeof( V_55 ) , L_5 , V_7 ) ;
if ( V_59 == NULL )
F_66 ( V_56 , sizeof( V_56 ) , L_6 , V_61 ) ;
if ( V_60 == NULL )
F_66 ( V_57 , sizeof( V_57 ) , L_7 , V_62 ) ;
F_66 ( V_53 , V_54 , L_8 , V_52 , V_58 ? V_58 : V_55 ,
V_59 ? V_59 : V_56 , V_60 ? V_60 : V_57 ) ;
if ( strlen ( V_53 ) == V_54 - 1 ) {
#define F_67 4
if ( V_54 > F_67 ) {
int V_22 ;
char * V_28 = V_53 ;
for ( V_22 = 0 ; V_22 < F_67 ; V_22 ++ ) {
char * V_63 = strchr ( V_28 , ':' ) ;
if ( V_63 == NULL || V_63 > & V_53 [ V_54 - 1 ] - F_67 + V_22 ) {
V_63 = & V_53 [ V_54 - 1 ] - F_67 + V_22 ;
* V_63 = ':' ;
}
V_28 = V_63 + 1 ;
}
}
}
}
char * F_68 ( unsigned long V_52 , char * V_5 )
{
static char V_53 [ 256 ] ;
if ( V_5 == NULL )
V_5 = V_53 ;
F_61 ( V_52 , V_5 , 256 ) ;
return V_5 ;
}
const char * F_63 ( unsigned long V_52 )
{
T_2 V_9 , * V_10 ;
unsigned long V_7 ;
F_1 () ;
V_7 = F_7 ( V_52 ) ;
V_9 . error = F_39 ( V_7 , 0 , 0 ) ;
V_10 = F_13 ( V_64 ) ( & V_9 ) ;
return ( ( V_10 == NULL ) ? NULL : V_10 -> string ) ;
}
const char * F_64 ( unsigned long V_52 )
{
T_2 V_9 , * V_10 ;
unsigned long V_7 , V_61 ;
F_1 () ;
V_7 = F_7 ( V_52 ) ;
V_61 = F_8 ( V_52 ) ;
V_9 . error = F_39 ( V_7 , V_61 , 0 ) ;
V_10 = F_13 ( V_64 ) ( & V_9 ) ;
return ( ( V_10 == NULL ) ? NULL : V_10 -> string ) ;
}
const char * F_65 ( unsigned long V_52 )
{
T_2 V_9 , * V_10 = NULL ;
unsigned long V_7 , V_62 ;
F_1 () ;
V_7 = F_7 ( V_52 ) ;
V_62 = F_62 ( V_52 ) ;
V_9 . error = F_39 ( V_7 , 0 , V_62 ) ;
V_10 = F_13 ( V_64 ) ( & V_9 ) ;
if ( ! V_10 ) {
V_9 . error = F_39 ( 0 , 0 , V_62 ) ;
V_10 = F_13 ( V_64 ) ( & V_9 ) ;
}
return ( ( V_10 == NULL ) ? NULL : V_10 -> string ) ;
}
void F_69 ( const T_5 * V_65 )
{
T_3 V_66 ;
if ( V_65 )
F_70 ( & V_66 . V_13 , V_65 ) ;
else
F_71 ( & V_66 . V_13 ) ;
F_1 () ;
F_13 ( V_67 ) ( & V_66 ) ;
}
void F_72 ( unsigned long V_68 )
{
F_69 ( NULL ) ;
}
T_3 * F_48 ( void )
{
static T_3 V_69 ;
T_3 * V_5 , V_66 , * V_70 = NULL ;
int V_22 ;
T_5 V_13 ;
F_1 () ;
F_71 ( & V_13 ) ;
F_70 ( & V_66 . V_13 , & V_13 ) ;
V_5 = F_13 ( V_71 ) ( & V_66 ) ;
if ( V_5 == NULL ) {
V_5 = ( T_3 * ) F_73 ( sizeof( T_3 ) ) ;
if ( V_5 == NULL )
return ( & V_69 ) ;
F_70 ( & V_5 -> V_13 , & V_13 ) ;
V_5 -> V_40 = 0 ;
V_5 -> V_41 = 0 ;
for ( V_22 = 0 ; V_22 < V_29 ; V_22 ++ ) {
V_5 -> V_50 [ V_22 ] = NULL ;
V_5 -> V_51 [ V_22 ] = 0 ;
}
V_70 = F_13 ( V_72 ) ( V_5 ) ;
if ( F_13 ( V_71 ) ( V_5 ) != V_5 ) {
F_31 ( V_5 ) ;
return ( & V_69 ) ;
}
if ( V_70 )
F_31 ( V_70 ) ;
}
return V_5 ;
}
int F_74 ( void )
{
F_1 () ;
return F_13 ( V_73 ) () ;
}
void F_75 ( char * V_46 , int V_47 )
{
T_3 * V_38 ;
int V_22 ;
V_38 = F_48 () ;
V_22 = V_38 -> V_40 ;
if ( V_22 == 0 )
V_22 = V_29 - 1 ;
F_34 ( V_38 , V_22 ) ;
V_38 -> V_50 [ V_22 ] = V_46 ;
V_38 -> V_51 [ V_22 ] = V_47 ;
}
void F_76 ( int V_74 , ... )
{
T_6 args ;
va_start ( args , V_74 ) ;
F_77 ( V_74 , args ) ;
va_end ( args ) ;
}
void F_77 ( int V_74 , T_6 args )
{
int V_22 , V_75 , V_28 ;
char * V_24 , * V_10 , * V_6 ;
V_28 = 80 ;
V_24 = F_73 ( V_28 + 1 ) ;
if ( V_24 == NULL )
return;
V_24 [ 0 ] = '\0' ;
V_75 = 0 ;
for ( V_22 = 0 ; V_22 < V_74 ; V_22 ++ ) {
V_6 = va_arg ( args , char * ) ;
if ( V_6 != NULL ) {
V_75 += strlen ( V_6 ) ;
if ( V_75 > V_28 ) {
V_28 = V_75 + 20 ;
V_10 = F_78 ( V_24 , V_28 + 1 ) ;
if ( V_10 == NULL ) {
F_35 ( V_24 ) ;
return;
} else
V_24 = V_10 ;
}
F_79 ( V_24 , V_6 , ( T_4 ) V_28 + 1 ) ;
}
}
F_75 ( V_24 , V_76 | V_77 ) ;
}
int F_80 ( void )
{
T_3 * V_38 ;
V_38 = F_48 () ;
if ( V_38 -> V_41 == V_38 -> V_40 )
return 0 ;
V_38 -> V_42 [ V_38 -> V_40 ] |= V_78 ;
return 1 ;
}
int F_81 ( void )
{
T_3 * V_38 ;
V_38 = F_48 () ;
while ( V_38 -> V_41 != V_38 -> V_40
&& ( V_38 -> V_42 [ V_38 -> V_40 ] & V_78 ) == 0 ) {
F_50 ( V_38 , V_38 -> V_40 ) ;
V_38 -> V_40 -= 1 ;
if ( V_38 -> V_40 == - 1 )
V_38 -> V_40 = V_29 - 1 ;
}
if ( V_38 -> V_41 == V_38 -> V_40 )
return 0 ;
V_38 -> V_42 [ V_38 -> V_40 ] &= ~ V_78 ;
return 1 ;
}
