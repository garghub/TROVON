static char * F_1 ( const char * V_1 , char * V_2 , int V_3 )
{
char * V_4 = V_2 ;
int V_5 = strchr ( V_1 , '\n' ) != NULL ;
int V_6 = 0 ;
int V_7 = strlen ( V_1 ) ;
if ( ( V_7 > 0 ) && ( V_1 [ V_7 - 1 ] == '\n' ) )
V_6 = 1 ;
* V_4 ++ = '"' ;
-- V_3 ;
if ( V_5 ) {
* V_4 ++ = '"' ;
* V_4 ++ = '\n' ;
* V_4 ++ = '"' ;
V_3 -= 3 ;
}
while ( * V_1 != '\0' && V_3 > 1 ) {
if ( * V_1 == '"' )
* V_4 ++ = '\\' ;
else if ( * V_1 == '\n' ) {
* V_4 ++ = '\\' ;
* V_4 ++ = 'n' ;
* V_4 ++ = '"' ;
* V_4 ++ = '\n' ;
* V_4 ++ = '"' ;
V_3 -= 5 ;
++ V_1 ;
goto V_8;
}
else if ( * V_1 == '\\' ) {
* V_4 ++ = '\\' ;
V_3 -- ;
}
* V_4 ++ = * V_1 ++ ;
V_8:
-- V_3 ;
}
if ( V_5 && V_6 )
V_4 -= 3 ;
* V_4 ++ = '"' ;
* V_4 = '\0' ;
return V_2 ;
}
static struct V_9 * F_2 ( const char * V_10 , int V_11 )
{
struct V_9 * V_12 = malloc ( sizeof( * V_12 ) ) ;
if ( V_12 == NULL )
goto V_13;
V_12 -> V_10 = V_10 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_8 = NULL ;
V_13:
return V_12 ;
}
static struct V_14 * F_3 ( const char * V_15 , char * V_16 ,
const char * V_10 , int V_11 )
{
struct V_14 * V_12 = malloc ( sizeof( * V_12 ) ) ;
if ( V_12 == NULL )
goto V_13;
V_12 -> V_17 = F_2 ( V_10 , V_11 ) ;
if ( V_12 -> V_17 == NULL )
goto V_18;
V_12 -> V_15 = F_4 ( V_15 ) ;
if ( V_12 -> V_15 == NULL )
goto V_19;
V_12 -> V_16 = V_16 ;
V_12 -> V_8 = NULL ;
V_13:
return V_12 ;
V_19:
free ( V_12 -> V_17 ) ;
V_18:
free ( V_12 ) ;
V_12 = NULL ;
goto V_13;
}
static struct V_14 * F_5 ( const char * V_15 )
{
struct V_14 * V_20 = V_21 ;
while ( V_20 != NULL ) {
if ( strcmp ( V_20 -> V_15 , V_15 ) == 0 )
break;
V_20 = V_20 -> V_8 ;
}
return V_20 ;
}
static int F_6 ( struct V_14 * V_12 , const char * V_10 ,
int V_11 )
{
int V_22 = - 1 ;
struct V_9 * V_23 = F_2 ( V_10 , V_11 ) ;
if ( V_23 == NULL )
goto V_13;
V_23 -> V_8 = V_12 -> V_17 ;
V_12 -> V_17 = V_23 ;
V_22 = 0 ;
V_13:
return V_22 ;
}
static int F_7 ( const char * V_15 , char * V_16 , const char * V_10 ,
int V_11 )
{
int V_22 = 0 ;
char V_2 [ 16384 ] ;
char * V_24 = F_1 ( V_15 , V_2 , sizeof( V_2 ) ) ;
struct V_14 * V_20 = F_5 ( V_24 ) ;
if ( V_20 != NULL )
V_22 = F_6 ( V_20 , V_10 , V_11 ) ;
else {
V_20 = F_3 ( V_24 , V_16 , V_10 , V_11 ) ;
if ( V_20 != NULL ) {
V_20 -> V_8 = V_21 ;
V_21 = V_20 ;
} else
V_22 = - 1 ;
}
return V_22 ;
}
static void F_8 ( struct V_25 * V_25 )
{
struct V_25 * V_26 ;
F_7 ( F_9 ( V_25 ) , NULL ,
V_25 -> V_10 == NULL ? L_1 : V_25 -> V_10 -> V_27 ,
V_25 -> V_11 ) ;
if ( V_25 -> V_28 != NULL && F_10 ( V_25 ) )
F_7 ( F_11 ( V_25 ) , V_25 -> V_28 -> V_27 ,
V_25 -> V_10 == NULL ? L_1 : V_25 -> V_10 -> V_27 ,
V_25 -> V_11 ) ;
for ( V_26 = V_25 -> V_29 ; V_26 != NULL ; V_26 = V_26 -> V_8 )
if ( V_26 -> V_30 != NULL )
F_8 ( V_26 ) ;
}
static void F_12 ( struct V_14 * V_12 )
{
struct V_9 * V_23 = V_12 -> V_17 ;
putchar ( '\n' ) ;
if ( V_12 -> V_16 != NULL )
printf ( L_2 , V_12 -> V_16 ) ;
printf ( L_3 , V_23 -> V_10 , V_23 -> V_11 ) ;
V_23 = V_23 -> V_8 ;
while ( V_23 != NULL ) {
printf ( L_4 , V_23 -> V_10 , V_23 -> V_11 ) ;
V_23 = V_23 -> V_8 ;
}
putchar ( '\n' ) ;
}
static void F_13 ( struct V_14 * V_12 )
{
F_12 ( V_12 ) ;
printf ( L_5
L_6 , V_12 -> V_15 ) ;
}
static void F_14 ( void )
{
struct V_14 * V_20 = V_21 ;
while ( V_20 != NULL ) {
if ( strlen ( V_20 -> V_15 ) > sizeof( L_7 ) )
F_13 ( V_20 ) ;
V_20 = V_20 -> V_8 ;
}
}
int main ( int V_31 , char * * V_32 )
{
F_15 ( V_32 [ 1 ] ) ;
F_8 ( F_16 ( NULL ) ) ;
F_14 () ;
return 0 ;
}
