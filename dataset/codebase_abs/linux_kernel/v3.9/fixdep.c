static void F_1 ( void )
{
fprintf ( V_1 , L_1 ) ;
exit ( 1 ) ;
}
static void F_2 ( void )
{
printf ( L_2 , V_2 , V_3 ) ;
}
static unsigned int F_3 ( const char * V_4 , unsigned int V_5 )
{
unsigned int V_6 , V_7 = 2166136261U ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
V_7 = ( V_7 ^ V_4 [ V_6 ] ) * 0x01000193 ;
return V_7 ;
}
static int F_4 ( const char * V_8 , int V_9 , unsigned int V_7 )
{
struct V_10 * V_11 ;
for ( V_11 = V_12 [ V_7 % V_13 ] ; V_11 ; V_11 = V_11 -> V_14 ) {
if ( V_11 -> V_7 == V_7 && V_11 -> V_9 == V_9 &&
memcmp ( V_11 -> V_8 , V_8 , V_9 ) == 0 )
return 1 ;
}
return 0 ;
}
static void F_5 ( const char * V_8 , int V_9 , unsigned int V_7 )
{
struct V_10 * V_11 = malloc ( sizeof( * V_11 ) + V_9 ) ;
if ( ! V_11 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
memcpy ( V_11 -> V_8 , V_8 , V_9 ) ;
V_11 -> V_9 = V_9 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_14 = V_12 [ V_7 % V_13 ] ;
V_12 [ V_7 % V_13 ] = V_11 ;
}
static void F_6 ( void )
{
struct V_10 * V_11 , * V_14 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_13 ; V_6 ++ ) {
for ( V_11 = V_12 [ V_6 ] ; V_11 ; V_11 = V_14 ) {
V_14 = V_11 -> V_14 ;
free ( V_11 ) ;
}
V_12 [ V_6 ] = NULL ;
}
}
static void F_7 ( const char * V_15 , int V_16 )
{
unsigned int V_7 = F_3 ( V_15 , V_16 ) ;
int V_17 , V_6 ;
if ( F_4 ( V_15 , V_16 , V_7 ) )
return;
F_5 ( V_15 , V_16 , V_7 ) ;
printf ( L_4 ) ;
for ( V_6 = 0 ; V_6 < V_16 ; V_6 ++ ) {
V_17 = V_15 [ V_6 ] ;
if ( V_17 == '_' )
V_17 = '/' ;
else
V_17 = tolower ( V_17 ) ;
putchar ( V_17 ) ;
}
printf ( L_5 ) ;
}
static void F_8 ( const char * V_18 , T_1 V_9 )
{
const int * V_19 = ( const int * ) ( V_18 + V_9 ) ;
const int * V_15 = ( const int * ) V_18 + 1 ;
const char * V_20 , * V_21 ;
for (; V_15 < V_19 ; V_15 ++ ) {
if ( * V_15 == V_22 ) { V_20 = ( char * ) V_15 ; goto V_23; }
if ( * V_15 == V_24 ) { V_20 = ( char * ) V_15 - 1 ; goto V_23; }
if ( * V_15 == V_25 ) { V_20 = ( char * ) V_15 - 2 ; goto V_23; }
if ( * V_15 == V_26 ) { V_20 = ( char * ) V_15 - 3 ; goto V_23; }
continue;
V_23:
if ( V_20 > V_18 + V_9 - 7 )
continue;
if ( memcmp ( V_20 , L_6 , 7 ) )
continue;
for ( V_21 = V_20 + 7 ; V_21 < V_18 + V_9 ; V_21 ++ ) {
if ( ! ( isalnum ( * V_21 ) || * V_21 == '_' ) )
goto V_27;
}
continue;
V_27:
if ( ! memcmp ( V_21 - 7 , L_7 , 7 ) )
V_21 -= 7 ;
if( ( V_21 - V_20 - 7 ) < 0 )
continue;
F_7 ( V_20 + 7 , V_21 - V_20 - 7 ) ;
}
}
static int F_9 ( char * V_28 , char * V_29 )
{
int V_16 = strlen ( V_28 ) ;
int V_30 = strlen ( V_29 ) ;
if ( V_30 > V_16 )
return 1 ;
return memcmp ( V_28 + V_16 - V_30 , V_29 , V_30 ) ;
}
static void F_10 ( const char * V_31 )
{
struct V_32 V_33 ;
int V_34 ;
void * V_18 ;
V_34 = F_11 ( V_31 , V_35 ) ;
if ( V_34 < 0 ) {
fprintf ( V_1 , L_8 ) ;
perror ( V_31 ) ;
exit ( 2 ) ;
}
F_12 ( V_34 , & V_33 ) ;
if ( V_33 . V_36 == 0 ) {
F_13 ( V_34 ) ;
return;
}
V_18 = F_14 ( NULL , V_33 . V_36 , V_37 , V_38 , V_34 , 0 ) ;
if ( ( long ) V_18 == - 1 ) {
perror ( L_9 ) ;
F_13 ( V_34 ) ;
return;
}
F_8 ( V_18 , V_33 . V_36 ) ;
F_15 ( V_18 , V_33 . V_36 ) ;
F_13 ( V_34 ) ;
}
static void F_16 ( void * V_18 , T_1 V_9 )
{
char * V_15 = V_18 ;
char * V_19 = V_15 + V_9 ;
char * V_20 ;
char V_28 [ V_39 ] ;
int V_40 ;
V_20 = strchr ( V_15 , ':' ) ;
if ( ! V_20 ) {
fprintf ( V_1 , L_10 ) ;
exit ( 1 ) ;
}
memcpy ( V_28 , V_15 , V_20 - V_15 ) ; V_28 [ V_20 - V_15 ] = 0 ;
V_15 = V_20 + 1 ;
F_6 () ;
V_40 = 1 ;
while ( V_15 < V_19 ) {
while ( V_15 < V_19 && ( * V_15 == ' ' || * V_15 == '\\' || * V_15 == '\n' ) )
V_15 ++ ;
V_20 = V_15 ;
while ( V_20 < V_19 && * V_20 != ' ' ) V_20 ++ ;
if ( V_20 == V_19 ) {
do V_20 -- ; while ( ! isalnum ( * V_20 ) );
V_20 ++ ;
}
memcpy ( V_28 , V_15 , V_20 - V_15 ) ; V_28 [ V_20 - V_15 ] = 0 ;
if ( F_9 ( V_28 , L_11 ) &&
F_9 ( V_28 , L_12 ) &&
F_9 ( V_28 , L_13 ) &&
F_9 ( V_28 , L_14 ) ) {
if ( V_40 ) {
printf ( L_15 , V_2 , V_28 ) ;
printf ( L_16 , V_2 ) ;
} else
printf ( L_17 , V_28 ) ;
F_10 ( V_28 ) ;
}
V_40 = 0 ;
V_15 = V_20 + 1 ;
}
printf ( L_18 , V_2 , V_2 ) ;
printf ( L_19 , V_2 ) ;
}
static void F_17 ( void )
{
struct V_32 V_33 ;
int V_34 ;
void * V_18 ;
V_34 = F_11 ( V_41 , V_35 ) ;
if ( V_34 < 0 ) {
fprintf ( V_1 , L_20 ) ;
perror ( V_41 ) ;
exit ( 2 ) ;
}
if ( F_12 ( V_34 , & V_33 ) < 0 ) {
fprintf ( V_1 , L_21 ) ;
perror ( V_41 ) ;
exit ( 2 ) ;
}
if ( V_33 . V_36 == 0 ) {
fprintf ( V_1 , L_22 , V_41 ) ;
F_13 ( V_34 ) ;
return;
}
V_18 = F_14 ( NULL , V_33 . V_36 , V_37 , V_38 , V_34 , 0 ) ;
if ( ( long ) V_18 == - 1 ) {
perror ( L_9 ) ;
F_13 ( V_34 ) ;
return;
}
F_16 ( V_18 , V_33 . V_36 ) ;
F_15 ( V_18 , V_33 . V_36 ) ;
F_13 ( V_34 ) ;
}
static void F_18 ( void )
{
static char V_42 [] V_43 ( ( F_19 ( sizeof( int ) ) ) ) = L_23 ;
int * V_20 = ( int * ) V_42 ;
if ( * V_20 != V_22 ) {
fprintf ( V_1 , L_24 ,
* V_20 ) ;
exit ( 2 ) ;
}
}
int main ( int V_44 , char * V_45 [] )
{
F_18 () ;
if ( V_44 != 4 )
F_1 () ;
V_41 = V_45 [ 1 ] ;
V_2 = V_45 [ 2 ] ;
V_3 = V_45 [ 3 ] ;
F_2 () ;
F_17 () ;
return 0 ;
}
