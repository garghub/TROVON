static void F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( ! V_4 [ V_2 ] )
continue;
if ( strcmp ( V_1 , V_4 [ V_2 ] ) )
continue;
V_4 [ V_2 ] = NULL ;
break;
}
}
static void F_2 ( void )
{
fprintf ( V_5 , L_1 ) ;
fprintf ( V_5 , L_2 ) ;
fprintf ( V_5 , L_3 ) ;
fprintf ( V_5 , L_4 ) ;
fprintf ( V_5 , L_5 ) ;
fprintf ( V_5 , L_6 ) ;
}
static void F_3 ( char * * V_6 )
{
T_1 V_7 ;
int V_8 ;
char V_9 [ V_10 + 1 ] ;
fflush ( stdout ) ;
switch ( V_7 = F_4 () ) {
case - 1 :
perror ( L_7 ) ;
exit ( 1 ) ;
case 0 :
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
strncat ( V_9 , V_11 , V_10 ) ;
strncat (real_filename, L_8 KERNELDOCPATH KERNELDOC,
PATH_MAX - strlen(real_filename)) ;
F_5 ( V_9 , V_6 ) ;
fprintf ( V_5 , L_9 ) ;
perror ( V_9 ) ;
exit ( 1 ) ;
default:
F_6 ( V_7 , & V_8 , 0 ) ;
}
if ( F_7 ( V_8 ) )
V_12 |= F_8 ( V_8 ) ;
else
V_12 = 0xff ;
}
static void F_9 ( struct V_13 * V_1 , char * V_14 )
{
V_1 -> V_15 =
realloc ( V_1 -> V_15 , ( V_1 -> V_16 + 1 ) * sizeof( char * ) ) ;
V_1 -> V_15 [ V_1 -> V_16 ++ ] . V_17 = F_10 ( V_14 ) ;
}
static struct V_13 * F_11 ( char * V_18 )
{
V_19 [ V_20 ++ ] . V_18 = F_10 ( V_18 ) ;
return & V_19 [ V_20 - 1 ] ;
}
static struct V_13 * F_12 ( char * V_18 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_20 ; V_2 ++ )
if ( strcmp ( V_19 [ V_2 ] . V_18 , V_18 ) == 0 )
return & V_19 [ V_2 ] ;
return NULL ;
}
static void F_13 ( char * V_21 ) { printf ( L_10 , V_21 ) ; }
static void F_14 ( char * V_21 , char * line ) { line = line ; F_13 ( V_21 ) ; }
static void F_15 ( char * line ) { line = line ; }
static void F_16 ( char * V_21 , char * line ) { V_21 = V_21 ; line = line ; }
static void F_17 ( char * line ) { printf ( L_11 , line ) ; }
static void F_18 ( char * V_18 )
{
T_2 * V_22 ;
struct V_13 * V_1 ;
char line [ V_23 ] ;
if ( F_12 ( V_18 ) == NULL ) {
char V_9 [ V_10 + 1 ] ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
strncat ( V_9 , V_24 , V_10 ) ;
strncat ( V_9 , L_8 , V_10 - strlen ( V_9 ) ) ;
strncat ( V_9 , V_18 ,
V_10 - strlen ( V_9 ) ) ;
V_1 = F_11 ( V_18 ) ;
V_22 = fopen ( V_9 , L_12 ) ;
if ( V_22 == NULL )
{
fprintf ( V_5 , L_13 ) ;
perror ( V_9 ) ;
exit ( 1 ) ;
}
while ( fgets ( line , V_23 , V_22 ) ) {
char * V_25 ;
char * V_26 ;
if ( ( ( V_25 = strstr ( line , L_14 ) ) != NULL ) ||
( ( V_25 = strstr ( line , L_15 ) ) != NULL ) ) {
while ( isalnum ( * V_25 ) || * V_25 == '_' )
V_25 ++ ;
while ( isspace ( * V_25 ) )
V_25 ++ ;
if ( * V_25 != '(' )
continue;
else
V_25 ++ ;
while ( isspace ( * V_25 ) )
V_25 ++ ;
V_26 = V_25 ;
while ( isalnum ( * V_26 ) || * V_26 == '_' )
V_26 ++ ;
* V_26 = '\0' ;
F_9 ( V_1 , V_25 ) ;
}
}
fclose ( V_22 ) ;
}
}
static void F_19 ( char * V_18 , char * type )
{
int V_2 , V_27 ;
int V_28 = 0 ;
int V_29 = 0 ;
char * * V_30 ;
for ( V_2 = 0 ; V_2 <= V_20 ; V_2 ++ )
V_28 += V_19 [ V_2 ] . V_16 ;
V_30 = malloc ( ( 2 + 2 * V_28 + 3 ) * sizeof( char * ) ) ;
if ( V_30 == NULL ) {
perror ( L_13 ) ;
exit ( 1 ) ;
}
V_30 [ V_29 ++ ] = V_31 ;
V_30 [ V_29 ++ ] = V_32 ;
V_30 [ V_29 ++ ] = V_33 ;
for ( V_2 = 0 ; V_2 < V_20 ; V_2 ++ ) {
struct V_13 * V_1 = & V_19 [ V_2 ] ;
for ( V_27 = 0 ; V_27 < V_1 -> V_16 ; V_27 ++ ) {
V_30 [ V_29 ++ ] = type ;
F_1 ( V_1 -> V_15 [ V_27 ] . V_17 ) ;
V_30 [ V_29 ++ ] = V_1 -> V_15 [ V_27 ] . V_17 ;
}
}
V_30 [ V_29 ++ ] = V_18 ;
V_30 [ V_29 ] = NULL ;
printf ( L_16 , V_18 ) ;
F_3 ( V_30 ) ;
fflush ( stdout ) ;
free ( V_30 ) ;
}
static void F_20 ( char * V_18 ) { F_19 ( V_18 , V_34 ) ; }
static void F_21 ( char * V_18 ) { F_19 ( V_18 , V_35 ) ; }
static void F_22 ( char * V_18 , char * line )
{
char * V_30 [ 200 ] ;
int V_2 , V_29 = 0 ;
int V_36 = 1 ;
V_30 [ V_29 ++ ] = V_31 ;
V_30 [ V_29 ++ ] = V_32 ;
for ( V_2 = 0 ; line [ V_2 ] ; V_2 ++ ) {
if ( isspace ( line [ V_2 ] ) ) {
line [ V_2 ] = '\0' ;
V_36 = 1 ;
continue;
}
if ( V_36 ) {
V_36 = 0 ;
V_30 [ V_29 ++ ] = V_35 ;
V_30 [ V_29 ++ ] = & line [ V_2 ] ;
}
}
for ( V_2 = 0 ; V_2 < V_29 ; V_2 ++ ) {
if ( strcmp ( V_30 [ V_2 ] , V_35 ) )
continue;
F_1 ( V_30 [ V_2 + 1 ] ) ;
}
V_30 [ V_29 ++ ] = V_18 ;
V_30 [ V_29 ] = NULL ;
F_3 ( V_30 ) ;
}
static void F_23 ( char * V_18 , char * line )
{
char * V_30 [ 6 ] ;
char * V_37 ;
for ( V_37 = line ; * V_37 ; V_37 ++ )
if ( * V_37 == '\n' )
* V_37 = '\0' ;
if ( F_24 ( & V_37 , L_17 , line ) < 0 ) {
perror ( L_18 ) ;
exit ( 1 ) ;
}
F_1 ( V_37 ) ;
free ( V_37 ) ;
V_30 [ 0 ] = V_31 ;
V_30 [ 1 ] = V_32 ;
V_30 [ 2 ] = V_35 ;
V_30 [ 3 ] = line ;
V_30 [ 4 ] = V_18 ;
V_30 [ 5 ] = NULL ;
F_3 ( V_30 ) ;
}
static void F_25 ( char * V_18 )
{
char * V_30 [ 4 ] ;
T_1 V_7 ;
int V_8 , V_2 , V_38 , V_39 ;
char V_9 [ V_10 + 1 ] ;
int V_40 [ 2 ] ;
char * V_41 , * V_42 ;
T_3 V_43 = 0 ;
V_30 [ 0 ] = V_31 ;
V_30 [ 1 ] = V_44 ;
V_30 [ 2 ] = V_18 ;
V_30 [ 3 ] = NULL ;
if ( F_26 ( V_40 ) ) {
perror ( L_19 ) ;
exit ( 1 ) ;
}
switch ( V_7 = F_4 () ) {
case - 1 :
perror ( L_7 ) ;
exit ( 1 ) ;
case 0 :
F_27 ( V_40 [ 0 ] ) ;
F_28 ( V_40 [ 1 ] , 1 ) ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
strncat ( V_9 , V_11 , V_10 ) ;
strncat (real_filename, L_8 KERNELDOCPATH KERNELDOC,
PATH_MAX - strlen(real_filename)) ;
F_5 ( V_9 , V_30 ) ;
fprintf ( V_5 , L_9 ) ;
perror ( V_9 ) ;
exit ( 1 ) ;
default:
F_27 ( V_40 [ 1 ] ) ;
V_41 = malloc ( 4096 ) ;
do {
while ( ( V_8 = F_29 ( V_40 [ 0 ] ,
V_41 + V_43 ,
4096 ) ) > 0 ) {
V_43 += V_8 ;
V_41 = realloc ( V_41 , V_43 + 4096 ) ;
}
} while ( V_8 == - V_45 );
if ( V_8 != 0 ) {
perror ( L_20 ) ;
exit ( 1 ) ;
}
F_6 ( V_7 , & V_8 , 0 ) ;
}
if ( F_7 ( V_8 ) )
V_12 |= F_8 ( V_8 ) ;
else
V_12 = 0xff ;
V_38 = 0 ;
for ( V_2 = 0 ; V_2 < V_43 ; V_2 ++ ) {
if ( V_41 [ V_2 ] == '\n' ) {
V_38 ++ ;
V_41 [ V_2 ] = '\0' ;
}
}
V_39 = V_3 ;
V_3 += V_38 ;
V_4 = realloc ( V_4 , sizeof( char * ) * V_3 ) ;
V_42 = V_41 ;
for ( V_2 = 0 ; V_2 < V_43 && V_39 != V_3 ; V_2 ++ ) {
if ( V_41 [ V_2 ] == '\0' ) {
V_4 [ V_39 ] = V_42 ;
V_42 = V_41 + V_2 + 1 ;
V_39 ++ ;
}
}
}
static void F_30 ( T_2 * V_46 )
{
char line [ V_23 ] ;
char * V_37 ;
while ( fgets ( line , V_23 , V_46 ) ) {
if ( line [ 0 ] == '!' ) {
V_37 = line + 2 ;
switch ( line [ 1 ] ) {
case 'E' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 = '\0' ;
F_31 ( line + 2 ) ;
break;
case 'I' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 = '\0' ;
F_32 ( line + 2 ) ;
break;
case 'D' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 = '\0' ;
F_33 ( line + 2 ) ;
break;
case 'F' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 ++ = '\0' ;
while ( isspace ( * V_37 ) )
V_37 ++ ;
F_34 ( line + 2 , V_37 ) ;
break;
case 'P' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 ++ = '\0' ;
while ( isspace ( * V_37 ) )
V_37 ++ ;
F_35 ( line + 2 , V_37 ) ;
break;
case 'C' :
while ( * V_37 && ! isspace ( * V_37 ) ) V_37 ++ ;
* V_37 = '\0' ;
if ( V_47 )
V_47 ( line + 2 ) ;
break;
default:
F_36 ( line ) ;
}
}
else {
F_36 ( line ) ;
}
}
fflush ( stdout ) ;
}
int main ( int V_48 , char * V_49 [] )
{
T_2 * V_46 ;
int V_2 ;
V_24 = getenv ( L_21 ) ;
if ( ! V_24 )
V_24 = F_37 ( NULL , 0 ) ;
V_11 = getenv ( L_22 ) ;
if ( ! V_11 || ! * V_11 )
V_11 = V_24 ;
if ( V_48 != 3 ) {
F_2 () ;
exit ( 1 ) ;
}
V_46 = fopen ( V_49 [ 2 ] , L_12 ) ;
if ( V_46 == NULL ) {
fprintf ( V_5 , L_13 ) ;
perror ( V_49 [ 2 ] ) ;
exit ( 2 ) ;
}
if ( strcmp ( L_23 , V_49 [ 1 ] ) == 0 )
{
F_36 = F_15 ;
F_32 = F_18 ;
F_31 = F_18 ;
F_33 = F_18 ;
F_34 = F_16 ;
F_35 = F_16 ;
V_47 = F_25 ;
F_30 ( V_46 ) ;
fseek ( V_46 , 0 , V_50 ) ;
F_36 = F_17 ;
F_32 = F_20 ;
F_31 = F_21 ;
F_33 = F_17 ;
F_34 = F_22 ;
F_35 = F_23 ;
V_47 = NULL ;
F_30 ( V_46 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( ! V_4 [ V_2 ] )
continue;
fprintf ( V_5 , L_24 ,
V_4 [ V_2 ] ) ;
}
}
else if ( strcmp ( L_25 , V_49 [ 1 ] ) == 0 )
{
printf ( L_26 , V_49 [ 2 ] ) ;
F_36 = F_15 ;
F_32 = F_13 ;
F_31 = F_13 ;
F_33 = F_13 ;
F_34 = F_14 ;
F_35 = F_14 ;
V_47 = F_13 ;
F_30 ( V_46 ) ;
printf ( L_27 ) ;
}
else
{
fprintf ( V_5 , L_28 , V_49 [ 1 ] ) ;
exit ( 1 ) ;
}
fclose ( V_46 ) ;
fflush ( stdout ) ;
return V_12 ;
}
