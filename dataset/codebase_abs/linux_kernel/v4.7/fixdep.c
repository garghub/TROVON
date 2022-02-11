static void F_1 ( void )
{
fprintf ( V_1 , L_1 ) ;
fprintf ( V_1 , L_2 ) ;
exit ( 1 ) ;
}
static void F_2 ( void )
{
printf ( L_3 , V_2 , V_3 ) ;
}
static void F_3 ( const char * V_4 , int V_5 )
{
int V_6 , V_7 ;
printf ( L_4 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
V_6 = V_4 [ V_7 ] ;
if ( V_6 == '_' )
V_6 = '/' ;
else
V_6 = tolower ( V_6 ) ;
putchar ( V_6 ) ;
}
printf ( L_5 ) ;
}
static void F_4 ( void )
{
if ( V_8 ) {
char V_9 [ 80 ] ;
while( fgets ( V_9 , sizeof( V_9 ) , V_10 ) ) {
int V_11 = strlen ( V_9 ) ;
if ( V_11 < 2 || V_9 [ V_11 - 1 ] != '\n' ) {
fprintf ( V_1 , L_6 ) ;
exit ( 1 ) ;
}
F_3 ( V_9 , V_11 - 1 ) ;
}
}
}
static unsigned int F_5 ( const char * V_12 , unsigned int V_13 )
{
unsigned int V_7 , V_14 = 2166136261U ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ )
V_14 = ( V_14 ^ V_12 [ V_7 ] ) * 0x01000193 ;
return V_14 ;
}
static int F_6 ( const char * V_15 , int V_11 , unsigned int V_14 )
{
struct V_16 * V_17 ;
for ( V_17 = V_18 [ V_14 % V_19 ] ; V_17 ; V_17 = V_17 -> V_20 ) {
if ( V_17 -> V_14 == V_14 && V_17 -> V_11 == V_11 &&
memcmp ( V_17 -> V_15 , V_15 , V_11 ) == 0 )
return 1 ;
}
return 0 ;
}
static void F_7 ( const char * V_15 , int V_11 , unsigned int V_14 )
{
struct V_16 * V_17 = malloc ( sizeof( * V_17 ) + V_11 ) ;
if ( ! V_17 ) {
perror ( L_7 ) ;
exit ( 1 ) ;
}
memcpy ( V_17 -> V_15 , V_15 , V_11 ) ;
V_17 -> V_11 = V_11 ;
V_17 -> V_14 = V_14 ;
V_17 -> V_20 = V_18 [ V_14 % V_19 ] ;
V_18 [ V_14 % V_19 ] = V_17 ;
}
static void F_8 ( const char * V_4 , int V_5 )
{
unsigned int V_14 = F_5 ( V_4 , V_5 ) ;
if ( F_6 ( V_4 , V_5 , V_14 ) )
return;
F_7 ( V_4 , V_5 , V_14 ) ;
F_3 ( V_4 , V_5 ) ;
}
static void F_9 ( const char * V_21 , T_1 V_11 )
{
const int * V_22 = ( const int * ) ( V_21 + V_11 ) ;
const int * V_4 = ( const int * ) V_21 + 1 ;
const char * V_23 , * V_24 ;
for (; V_4 < V_22 ; V_4 ++ ) {
if ( * V_4 == V_25 ) { V_23 = ( char * ) V_4 ; goto V_26; }
if ( * V_4 == V_27 ) { V_23 = ( char * ) V_4 - 1 ; goto V_26; }
if ( * V_4 == V_28 ) { V_23 = ( char * ) V_4 - 2 ; goto V_26; }
if ( * V_4 == V_29 ) { V_23 = ( char * ) V_4 - 3 ; goto V_26; }
continue;
V_26:
if ( V_23 > V_21 + V_11 - 7 )
continue;
if ( memcmp ( V_23 , L_8 , 7 ) )
continue;
V_23 += 7 ;
for ( V_24 = V_23 ; V_24 < V_21 + V_11 ; V_24 ++ ) {
if ( ! ( isalnum ( * V_24 ) || * V_24 == '_' ) )
goto V_30;
}
continue;
V_30:
if ( ! memcmp ( V_24 - 7 , L_9 , 7 ) )
V_24 -= 7 ;
if ( V_24 - V_23 < 0 )
continue;
F_8 ( V_23 , V_24 - V_23 ) ;
}
}
static int F_10 ( const char * V_31 , const char * V_32 )
{
int V_5 = strlen ( V_31 ) ;
int V_33 = strlen ( V_32 ) ;
if ( V_33 > V_5 )
return 1 ;
return memcmp ( V_31 + V_5 - V_33 , V_32 , V_33 ) ;
}
static void F_11 ( const char * V_34 )
{
struct V_35 V_36 ;
int V_37 ;
void * V_21 ;
V_37 = F_12 ( V_34 , V_38 ) ;
if ( V_37 < 0 ) {
fprintf ( V_1 , L_10 ) ;
perror ( V_34 ) ;
exit ( 2 ) ;
}
if ( F_13 ( V_37 , & V_36 ) < 0 ) {
fprintf ( V_1 , L_11 ) ;
perror ( V_34 ) ;
exit ( 2 ) ;
}
if ( V_36 . V_39 == 0 ) {
F_14 ( V_37 ) ;
return;
}
V_21 = F_15 ( NULL , V_36 . V_39 , V_40 , V_41 , V_37 , 0 ) ;
if ( ( long ) V_21 == - 1 ) {
perror ( L_12 ) ;
F_14 ( V_37 ) ;
return;
}
F_9 ( V_21 , V_36 . V_39 ) ;
F_16 ( V_21 , V_36 . V_39 ) ;
F_14 ( V_37 ) ;
}
static void F_17 ( void * V_21 , T_1 V_11 )
{
char * V_4 = V_21 ;
char * V_22 = V_4 + V_11 ;
char * V_23 ;
char V_31 [ V_42 ] ;
int V_43 ;
int V_44 = 0 ;
int V_45 = 0 ;
while ( V_4 < V_22 ) {
while ( V_4 < V_22 && ( * V_4 == ' ' || * V_4 == '\\' || * V_4 == '\n' ) )
V_4 ++ ;
V_23 = V_4 ;
while ( V_23 < V_22 && * V_23 != ' ' && * V_23 != '\\' && * V_23 != '\n' )
V_23 ++ ;
V_43 = ( * ( V_23 - 1 ) == ':' ) ;
if ( V_43 ) {
V_45 = 1 ;
} else {
memcpy ( V_31 , V_4 , V_23 - V_4 ) ;
V_31 [ V_23 - V_4 ] = 0 ;
if ( F_10 ( V_31 , L_13 ) &&
F_10 ( V_31 , L_14 ) &&
F_10 ( V_31 , L_15 ) &&
F_10 ( V_31 , L_16 ) &&
F_10 ( V_31 , L_17 ) ) {
if ( V_45 ) {
if ( ! V_44 ) {
V_44 = 1 ;
printf ( L_18 ,
V_2 , V_31 ) ;
printf ( L_19 ,
V_2 ) ;
}
V_45 = 0 ;
} else
printf ( L_20 , V_31 ) ;
F_11 ( V_31 ) ;
}
}
V_4 = V_23 + 1 ;
}
if ( ! V_44 ) {
fprintf ( V_1 , L_21 ) ;
exit ( 1 ) ;
}
F_4 () ;
printf ( L_22 , V_2 , V_2 ) ;
printf ( L_23 , V_2 ) ;
}
static void F_18 ( void )
{
struct V_35 V_36 ;
int V_37 ;
void * V_21 ;
V_37 = F_12 ( V_46 , V_38 ) ;
if ( V_37 < 0 ) {
fprintf ( V_1 , L_24 ) ;
perror ( V_46 ) ;
exit ( 2 ) ;
}
if ( F_13 ( V_37 , & V_36 ) < 0 ) {
fprintf ( V_1 , L_25 ) ;
perror ( V_46 ) ;
exit ( 2 ) ;
}
if ( V_36 . V_39 == 0 ) {
fprintf ( V_1 , L_26 , V_46 ) ;
F_14 ( V_37 ) ;
return;
}
V_21 = F_15 ( NULL , V_36 . V_39 , V_40 , V_41 , V_37 , 0 ) ;
if ( ( long ) V_21 == - 1 ) {
perror ( L_12 ) ;
F_14 ( V_37 ) ;
return;
}
F_17 ( V_21 , V_36 . V_39 ) ;
F_16 ( V_21 , V_36 . V_39 ) ;
F_14 ( V_37 ) ;
}
static void F_19 ( void )
{
static char V_47 [] V_48 ( ( F_20 ( sizeof( int ) ) ) ) = L_27 ;
int * V_23 = ( int * ) V_47 ;
if ( * V_23 != V_25 ) {
fprintf ( V_1 , L_28 ,
* V_23 ) ;
exit ( 2 ) ;
}
}
int main ( int V_49 , char * V_50 [] )
{
F_19 () ;
if ( V_49 == 5 && ! strcmp ( V_50 [ 1 ] , L_29 ) ) {
V_8 = 1 ;
V_50 ++ ;
} else if ( V_49 != 4 )
F_1 () ;
V_46 = V_50 [ 1 ] ;
V_2 = V_50 [ 2 ] ;
V_3 = V_50 [ 3 ] ;
F_2 () ;
F_18 () ;
return 0 ;
}
