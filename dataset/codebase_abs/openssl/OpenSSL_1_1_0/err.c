static unsigned long F_1 ( const T_1 * V_1 )
{
unsigned long V_2 , V_3 ;
V_3 = V_1 -> error ;
V_2 = V_3 ^ F_2 ( V_3 ) ^ F_3 ( V_3 ) ;
return ( V_2 ^ V_2 % 19 * 13 ) ;
}
static int F_4 ( const T_1 * V_1 ,
const T_1 * V_4 )
{
return ( int ) ( V_1 -> error - V_4 -> error ) ;
}
static T_1 * F_5 ( const T_1 * V_5 )
{
T_1 * V_6 = NULL ;
F_6 ( V_7 ) ;
if ( V_8 != NULL )
V_6 = F_7 ( V_8 , V_5 ) ;
F_8 ( V_7 ) ;
return V_6 ;
}
static void F_9 ( void )
{
static char V_9 [ V_10 ] [ V_11 ] ;
static int V_12 = 1 ;
int V_13 ;
F_10 ( V_7 ) ;
if ( ! V_12 ) {
F_8 ( V_7 ) ;
return;
}
for ( V_13 = 1 ; V_13 <= V_10 ; V_13 ++ ) {
T_1 * V_14 = & V_15 [ V_13 - 1 ] ;
V_14 -> error = ( unsigned long ) V_13 ;
if ( V_14 -> string == NULL ) {
char ( * V_16 ) [ V_11 ] = & ( V_9 [ V_13 - 1 ] ) ;
if ( F_11 ( V_13 , * V_16 , sizeof( * V_16 ) ) )
V_14 -> string = * V_16 ;
}
if ( V_14 -> string == NULL )
V_14 -> string = L_1 ;
}
V_12 = 0 ;
F_8 ( V_7 ) ;
}
static void F_12 ( T_2 * V_17 )
{
int V_13 ;
if ( V_17 == NULL )
return;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
F_13 ( V_17 , V_13 ) ;
}
F_14 ( V_17 ) ;
}
void F_15 ( void )
{
F_16 ( V_7 ) ;
V_7 = NULL ;
}
int F_17 ( void )
{
#ifndef F_18
if ( ! F_19 ( & V_19 , V_20 ) )
return 0 ;
F_20 ( 0 , V_21 ) ;
F_20 ( 0 , V_22 ) ;
F_20 ( V_23 , V_24 ) ;
F_9 () ;
F_20 ( V_23 , V_15 ) ;
#endif
return 1 ;
}
static void F_20 ( int V_25 , T_1 * V_14 )
{
F_10 ( V_7 ) ;
if ( V_8 == NULL )
V_8 = F_21 ( F_1 ,
F_4 ) ;
if ( V_8 != NULL ) {
for (; V_14 -> error ; V_14 ++ ) {
if ( V_25 )
V_14 -> error |= F_22 ( V_25 , 0 , 0 ) ;
( void ) F_23 ( V_8 , V_14 ) ;
}
}
F_8 ( V_7 ) ;
}
int F_24 ( int V_25 , T_1 * V_14 )
{
if ( F_17 () == 0 )
return 0 ;
F_20 ( V_25 , V_14 ) ;
return 1 ;
}
int F_25 ( int V_25 , T_1 * V_14 )
{
if ( ! F_19 ( & V_19 , V_20 ) )
return 0 ;
F_10 ( V_7 ) ;
if ( V_8 != NULL ) {
for (; V_14 -> error ; V_14 ++ ) {
if ( V_25 )
V_14 -> error |= F_22 ( V_25 , 0 , 0 ) ;
( void ) F_26 ( V_8 , V_14 ) ;
}
}
F_8 ( V_7 ) ;
return 1 ;
}
void F_27 ( void )
{
if ( ! F_19 ( & V_19 , V_20 ) )
return;
F_10 ( V_7 ) ;
F_28 ( V_8 ) ;
V_8 = NULL ;
F_8 ( V_7 ) ;
}
void F_29 ( int V_25 , int V_26 , int V_27 , const char * V_28 , int line )
{
T_2 * V_29 ;
#ifdef F_30
if ( strncmp ( V_28 , L_2 , sizeof( L_2 ) - 1 ) == 0 ) {
char * V_30 ;
V_28 += sizeof( L_2 ) - 1 ;
V_30 = & V_28 [ strlen ( V_28 ) - 1 ] ;
if ( * V_30 == ')' )
* V_30 = '\0' ;
if ( ( V_30 = strrchr ( V_28 , '/' ) ) != NULL )
V_28 = & V_30 [ 1 ] ;
}
#endif
V_29 = F_31 () ;
V_29 -> V_31 = ( V_29 -> V_31 + 1 ) % V_18 ;
if ( V_29 -> V_31 == V_29 -> V_32 )
V_29 -> V_32 = ( V_29 -> V_32 + 1 ) % V_18 ;
V_29 -> V_33 [ V_29 -> V_31 ] = 0 ;
V_29 -> V_34 [ V_29 -> V_31 ] = F_22 ( V_25 , V_26 , V_27 ) ;
V_29 -> V_35 [ V_29 -> V_31 ] = V_28 ;
V_29 -> V_36 [ V_29 -> V_31 ] = line ;
F_13 ( V_29 , V_29 -> V_31 ) ;
}
void F_32 ( void )
{
int V_13 ;
T_2 * V_29 ;
V_29 = F_31 () ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ ) {
F_33 ( V_29 , V_13 ) ;
}
V_29 -> V_31 = V_29 -> V_32 = 0 ;
}
unsigned long F_34 ( void )
{
return ( F_35 ( 1 , 0 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_36 ( const char * * V_28 , int * line )
{
return ( F_35 ( 1 , 0 , V_28 , line , NULL , NULL ) ) ;
}
unsigned long F_37 ( const char * * V_28 , int * line ,
const char * * V_37 , int * V_38 )
{
return ( F_35 ( 1 , 0 , V_28 , line , V_37 , V_38 ) ) ;
}
unsigned long F_38 ( void )
{
return ( F_35 ( 0 , 0 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_39 ( const char * * V_28 , int * line )
{
return ( F_35 ( 0 , 0 , V_28 , line , NULL , NULL ) ) ;
}
unsigned long F_40 ( const char * * V_28 , int * line ,
const char * * V_37 , int * V_38 )
{
return ( F_35 ( 0 , 0 , V_28 , line , V_37 , V_38 ) ) ;
}
unsigned long F_41 ( void )
{
return ( F_35 ( 0 , 1 , NULL , NULL , NULL , NULL ) ) ;
}
unsigned long F_42 ( const char * * V_28 , int * line )
{
return ( F_35 ( 0 , 1 , V_28 , line , NULL , NULL ) ) ;
}
unsigned long F_43 ( const char * * V_28 , int * line ,
const char * * V_37 , int * V_38 )
{
return ( F_35 ( 0 , 1 , V_28 , line , V_37 , V_38 ) ) ;
}
static unsigned long F_35 ( int V_39 , int V_31 , const char * * V_28 ,
int * line , const char * * V_37 ,
int * V_38 )
{
int V_13 = 0 ;
T_2 * V_29 ;
unsigned long V_2 ;
V_29 = F_31 () ;
if ( V_39 && V_31 ) {
if ( V_28 )
* V_28 = L_3 ;
if ( line )
* line = 0 ;
if ( V_37 )
* V_37 = L_3 ;
if ( V_38 )
* V_38 = 0 ;
return V_40 ;
}
if ( V_29 -> V_32 == V_29 -> V_31 )
return 0 ;
if ( V_31 )
V_13 = V_29 -> V_31 ;
else
V_13 = ( V_29 -> V_32 + 1 ) % V_18 ;
V_2 = V_29 -> V_34 [ V_13 ] ;
if ( V_39 ) {
V_29 -> V_32 = V_13 ;
V_29 -> V_34 [ V_13 ] = 0 ;
}
if ( ( V_28 != NULL ) && ( line != NULL ) ) {
if ( V_29 -> V_35 [ V_13 ] == NULL ) {
* V_28 = L_4 ;
if ( line != NULL )
* line = 0 ;
} else {
* V_28 = V_29 -> V_35 [ V_13 ] ;
if ( line != NULL )
* line = V_29 -> V_36 [ V_13 ] ;
}
}
if ( V_37 == NULL ) {
if ( V_39 ) {
F_13 ( V_29 , V_13 ) ;
}
} else {
if ( V_29 -> V_41 [ V_13 ] == NULL ) {
* V_37 = L_3 ;
if ( V_38 != NULL )
* V_38 = 0 ;
} else {
* V_37 = V_29 -> V_41 [ V_13 ] ;
if ( V_38 != NULL )
* V_38 = V_29 -> V_42 [ V_13 ] ;
}
}
return V_2 ;
}
void F_44 ( unsigned long V_43 , char * V_44 , T_3 V_45 )
{
char V_46 [ 64 ] , V_47 [ 64 ] , V_48 [ 64 ] ;
const char * V_49 , * V_50 , * V_51 ;
unsigned long V_3 , V_52 , V_53 ;
V_3 = F_2 ( V_43 ) ;
V_52 = F_3 ( V_43 ) ;
V_53 = F_45 ( V_43 ) ;
V_49 = F_46 ( V_43 ) ;
V_50 = F_47 ( V_43 ) ;
V_51 = F_48 ( V_43 ) ;
if ( V_49 == NULL )
F_49 ( V_46 , sizeof( V_46 ) , L_5 , V_3 ) ;
if ( V_50 == NULL )
F_49 ( V_47 , sizeof( V_47 ) , L_6 , V_52 ) ;
if ( V_51 == NULL )
F_49 ( V_48 , sizeof( V_48 ) , L_7 , V_53 ) ;
F_49 ( V_44 , V_45 , L_8 , V_43 , V_49 ? V_49 : V_46 ,
V_50 ? V_50 : V_47 , V_51 ? V_51 : V_48 ) ;
if ( strlen ( V_44 ) == V_45 - 1 ) {
#define F_50 4
if ( V_45 > F_50 ) {
int V_13 ;
char * V_17 = V_44 ;
for ( V_13 = 0 ; V_13 < F_50 ; V_13 ++ ) {
char * V_54 = strchr ( V_17 , ':' ) ;
if ( V_54 == NULL || V_54 > & V_44 [ V_45 - 1 ] - F_50 + V_13 ) {
V_54 = & V_44 [ V_45 - 1 ] - F_50 + V_13 ;
* V_54 = ':' ;
}
V_17 = V_54 + 1 ;
}
}
}
}
char * F_51 ( unsigned long V_43 , char * V_2 )
{
static char V_44 [ 256 ] ;
if ( V_2 == NULL )
V_2 = V_44 ;
F_44 ( V_43 , V_2 , 256 ) ;
return V_2 ;
}
const char * F_46 ( unsigned long V_43 )
{
T_1 V_5 , * V_6 ;
unsigned long V_3 ;
if ( ! F_19 ( & V_19 , V_20 ) ) {
return NULL ;
}
V_3 = F_2 ( V_43 ) ;
V_5 . error = F_22 ( V_3 , 0 , 0 ) ;
V_6 = F_5 ( & V_5 ) ;
return ( ( V_6 == NULL ) ? NULL : V_6 -> string ) ;
}
const char * F_47 ( unsigned long V_43 )
{
T_1 V_5 , * V_6 ;
unsigned long V_3 , V_52 ;
if ( ! F_19 ( & V_19 , V_20 ) ) {
return NULL ;
}
V_3 = F_2 ( V_43 ) ;
V_52 = F_3 ( V_43 ) ;
V_5 . error = F_22 ( V_3 , V_52 , 0 ) ;
V_6 = F_5 ( & V_5 ) ;
return ( ( V_6 == NULL ) ? NULL : V_6 -> string ) ;
}
const char * F_48 ( unsigned long V_43 )
{
T_1 V_5 , * V_6 = NULL ;
unsigned long V_3 , V_53 ;
if ( ! F_19 ( & V_19 , V_20 ) ) {
return NULL ;
}
V_3 = F_2 ( V_43 ) ;
V_53 = F_45 ( V_43 ) ;
V_5 . error = F_22 ( V_3 , 0 , V_53 ) ;
V_6 = F_5 ( & V_5 ) ;
if ( ! V_6 ) {
V_5 . error = F_22 ( 0 , 0 , V_53 ) ;
V_6 = F_5 ( & V_5 ) ;
}
return ( ( V_6 == NULL ) ? NULL : V_6 -> string ) ;
}
void F_52 ( void )
{
T_2 * V_55 = F_31 () ;
if ( V_55 == NULL )
return;
F_53 ( & V_56 , NULL ) ;
F_12 ( V_55 ) ;
}
void F_54 ( void * V_57 )
{
}
void F_55 ( unsigned long V_58 )
{
}
T_2 * F_31 ( void )
{
T_2 * V_55 = NULL ;
if ( ! F_19 ( & V_59 , V_60 ) )
return NULL ;
V_55 = F_56 ( & V_56 ) ;
if ( V_55 == NULL ) {
V_55 = F_57 ( sizeof( * V_55 ) ) ;
if ( V_55 == NULL )
return NULL ;
if ( ! F_53 ( & V_56 , V_55 ) ) {
F_12 ( V_55 ) ;
return NULL ;
}
F_58 ( V_61 , NULL ) ;
F_59 ( V_62 ) ;
}
return V_55 ;
}
int F_60 ( void )
{
int V_2 ;
if ( ! F_19 ( & V_19 , V_20 ) ) {
return 0 ;
}
F_10 ( V_7 ) ;
V_2 = V_63 ++ ;
F_8 ( V_7 ) ;
return V_2 ;
}
void F_61 ( char * V_37 , int V_38 )
{
T_2 * V_29 ;
int V_13 ;
V_29 = F_31 () ;
V_13 = V_29 -> V_31 ;
if ( V_13 == 0 )
V_13 = V_18 - 1 ;
F_13 ( V_29 , V_13 ) ;
V_29 -> V_41 [ V_13 ] = V_37 ;
V_29 -> V_42 [ V_13 ] = V_38 ;
}
void F_62 ( int V_64 , ... )
{
T_4 args ;
va_start ( args , V_64 ) ;
F_63 ( V_64 , args ) ;
va_end ( args ) ;
}
void F_63 ( int V_64 , T_4 args )
{
int V_13 , V_65 , V_17 ;
char * V_14 , * V_6 , * V_1 ;
V_17 = 80 ;
V_14 = F_64 ( V_17 + 1 ) ;
if ( V_14 == NULL )
return;
V_14 [ 0 ] = '\0' ;
V_65 = 0 ;
for ( V_13 = 0 ; V_13 < V_64 ; V_13 ++ ) {
V_1 = va_arg ( args , char * ) ;
if ( V_1 != NULL ) {
V_65 += strlen ( V_1 ) ;
if ( V_65 > V_17 ) {
V_17 = V_65 + 20 ;
V_6 = F_65 ( V_14 , V_17 + 1 ) ;
if ( V_6 == NULL ) {
F_14 ( V_14 ) ;
return;
}
V_14 = V_6 ;
}
F_66 ( V_14 , V_1 , ( T_3 ) V_17 + 1 ) ;
}
}
F_61 ( V_14 , V_66 | V_67 ) ;
}
int F_67 ( void )
{
T_2 * V_29 ;
V_29 = F_31 () ;
if ( V_29 -> V_32 == V_29 -> V_31 )
return 0 ;
V_29 -> V_33 [ V_29 -> V_31 ] |= V_68 ;
return 1 ;
}
int F_68 ( void )
{
T_2 * V_29 ;
V_29 = F_31 () ;
while ( V_29 -> V_32 != V_29 -> V_31
&& ( V_29 -> V_33 [ V_29 -> V_31 ] & V_68 ) == 0 ) {
F_33 ( V_29 , V_29 -> V_31 ) ;
V_29 -> V_31 -= 1 ;
if ( V_29 -> V_31 == - 1 )
V_29 -> V_31 = V_18 - 1 ;
}
if ( V_29 -> V_32 == V_29 -> V_31 )
return 0 ;
V_29 -> V_33 [ V_29 -> V_31 ] &= ~ V_68 ;
return 1 ;
}
