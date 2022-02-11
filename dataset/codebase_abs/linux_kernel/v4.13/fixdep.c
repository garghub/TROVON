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
static void F_9 ( const char * V_21 )
{
const char * V_22 , * V_23 ;
while ( ( V_21 = strstr ( V_21 , L_8 ) ) ) {
V_21 += 7 ;
V_22 = V_21 ;
while ( * V_22 && ( isalnum ( * V_22 ) || * V_22 == '_' ) )
V_22 ++ ;
if ( memcmp ( V_22 - 7 , L_9 , 7 ) == 0 )
V_23 = V_22 - 7 ;
else
V_23 = V_22 ;
if ( V_23 > V_21 )
F_8 ( V_21 , V_23 - V_21 ) ;
V_21 = V_22 ;
}
}
static int F_10 ( const char * V_24 , const char * V_25 )
{
int V_5 = strlen ( V_24 ) ;
int V_26 = strlen ( V_25 ) ;
if ( V_26 > V_5 )
return 1 ;
return memcmp ( V_24 + V_5 - V_26 , V_25 , V_26 ) ;
}
static void F_11 ( const char * V_27 )
{
struct V_28 V_29 ;
int V_30 ;
char * V_31 ;
V_30 = F_12 ( V_27 , V_32 ) ;
if ( V_30 < 0 ) {
fprintf ( V_1 , L_10 ) ;
perror ( V_27 ) ;
exit ( 2 ) ;
}
if ( F_13 ( V_30 , & V_29 ) < 0 ) {
fprintf ( V_1 , L_11 ) ;
perror ( V_27 ) ;
exit ( 2 ) ;
}
if ( V_29 . V_33 == 0 ) {
F_14 ( V_30 ) ;
return;
}
V_31 = malloc ( V_29 . V_33 + 1 ) ;
if ( ! V_31 ) {
perror ( L_12 ) ;
F_14 ( V_30 ) ;
return;
}
if ( F_15 ( V_30 , V_31 , V_29 . V_33 ) != V_29 . V_33 ) {
perror ( L_13 ) ;
F_14 ( V_30 ) ;
return;
}
V_31 [ V_29 . V_33 ] = '\0' ;
F_14 ( V_30 ) ;
F_9 ( V_31 ) ;
free ( V_31 ) ;
}
static void F_16 ( void * V_31 , T_1 V_11 )
{
char * V_4 = V_31 ;
char * V_34 = V_4 + V_11 ;
char * V_21 ;
char V_24 [ V_35 ] ;
int V_36 ;
int V_37 = 0 ;
int V_38 = 0 ;
while ( V_4 < V_34 ) {
while ( V_4 < V_34 && ( * V_4 == ' ' || * V_4 == '\\' || * V_4 == '\n' ) )
V_4 ++ ;
V_21 = V_4 ;
while ( V_21 < V_34 && * V_21 != ' ' && * V_21 != '\\' && * V_21 != '\n' )
V_21 ++ ;
V_36 = ( * ( V_21 - 1 ) == ':' ) ;
if ( V_36 ) {
V_38 = 1 ;
} else {
memcpy ( V_24 , V_4 , V_21 - V_4 ) ;
V_24 [ V_21 - V_4 ] = 0 ;
if ( F_10 ( V_24 , L_14 ) &&
F_10 ( V_24 , L_15 ) &&
F_10 ( V_24 , L_16 ) &&
F_10 ( V_24 , L_17 ) &&
F_10 ( V_24 , L_18 ) ) {
if ( V_38 ) {
if ( ! V_37 ) {
V_37 = 1 ;
printf ( L_19 ,
V_2 , V_24 ) ;
printf ( L_20 ,
V_2 ) ;
}
V_38 = 0 ;
} else
printf ( L_21 , V_24 ) ;
F_11 ( V_24 ) ;
}
}
V_4 = V_21 + 1 ;
}
if ( ! V_37 ) {
fprintf ( V_1 , L_22 ) ;
exit ( 1 ) ;
}
F_4 () ;
printf ( L_23 , V_2 , V_2 ) ;
printf ( L_24 , V_2 ) ;
}
static void F_17 ( void )
{
struct V_28 V_29 ;
int V_30 ;
void * V_31 ;
V_30 = F_12 ( V_39 , V_32 ) ;
if ( V_30 < 0 ) {
fprintf ( V_1 , L_25 ) ;
perror ( V_39 ) ;
exit ( 2 ) ;
}
if ( F_13 ( V_30 , & V_29 ) < 0 ) {
fprintf ( V_1 , L_26 ) ;
perror ( V_39 ) ;
exit ( 2 ) ;
}
if ( V_29 . V_33 == 0 ) {
fprintf ( V_1 , L_27 , V_39 ) ;
F_14 ( V_30 ) ;
return;
}
V_31 = F_18 ( NULL , V_29 . V_33 , V_40 , V_41 , V_30 , 0 ) ;
if ( ( long ) V_31 == - 1 ) {
perror ( L_28 ) ;
F_14 ( V_30 ) ;
return;
}
F_16 ( V_31 , V_29 . V_33 ) ;
F_19 ( V_31 , V_29 . V_33 ) ;
F_14 ( V_30 ) ;
}
int main ( int V_42 , char * V_43 [] )
{
if ( V_42 == 5 && ! strcmp ( V_43 [ 1 ] , L_29 ) ) {
V_8 = 1 ;
V_43 ++ ;
} else if ( V_42 != 4 )
F_1 () ;
V_39 = V_43 [ 1 ] ;
V_2 = V_43 [ 2 ] ;
V_3 = V_43 [ 3 ] ;
F_2 () ;
F_17 () ;
return 0 ;
}
