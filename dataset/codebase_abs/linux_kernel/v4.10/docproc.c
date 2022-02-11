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
if ( V_22 == NULL ) {
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
if ( V_34 == V_35 )
printf ( L_16 , V_18 ) ;
else
printf ( L_17 , V_18 ) ;
F_3 ( V_30 ) ;
fflush ( stdout ) ;
free ( V_30 ) ;
}
static void F_20 ( char * V_18 ) { F_19 ( V_18 , V_36 ) ; }
static void F_21 ( char * V_18 ) { F_19 ( V_18 , V_37 ) ; }
static void F_22 ( char * V_18 , char * line )
{
char * V_30 [ 200 ] ;
int V_2 , V_29 = 0 ;
int V_38 = 1 ;
V_30 [ V_29 ++ ] = V_31 ;
V_30 [ V_29 ++ ] = V_32 ;
V_30 [ V_29 ++ ] = V_39 ;
for ( V_2 = 0 ; line [ V_2 ] ; V_2 ++ ) {
if ( isspace ( line [ V_2 ] ) ) {
line [ V_2 ] = '\0' ;
V_38 = 1 ;
continue;
}
if ( V_38 ) {
V_38 = 0 ;
V_30 [ V_29 ++ ] = V_37 ;
V_30 [ V_29 ++ ] = & line [ V_2 ] ;
}
}
for ( V_2 = 0 ; V_2 < V_29 ; V_2 ++ ) {
if ( strcmp ( V_30 [ V_2 ] , V_37 ) )
continue;
F_1 ( V_30 [ V_2 + 1 ] ) ;
}
V_30 [ V_29 ++ ] = V_18 ;
V_30 [ V_29 ] = NULL ;
F_3 ( V_30 ) ;
}
static void F_23 ( char * V_18 , char * line )
{
char * V_30 [ 7 ] ;
char * V_40 ;
for ( V_40 = line ; * V_40 ; V_40 ++ )
if ( * V_40 == '\n' )
* V_40 = '\0' ;
if ( F_24 ( & V_40 , L_18 , line ) < 0 ) {
perror ( L_19 ) ;
exit ( 1 ) ;
}
F_1 ( V_40 ) ;
free ( V_40 ) ;
V_30 [ 0 ] = V_31 ;
V_30 [ 1 ] = V_32 ;
V_30 [ 2 ] = V_39 ;
V_30 [ 3 ] = V_37 ;
V_30 [ 4 ] = line ;
V_30 [ 5 ] = V_18 ;
V_30 [ 6 ] = NULL ;
F_3 ( V_30 ) ;
}
static void F_25 ( char * V_18 )
{
char * V_30 [ 4 ] ;
T_1 V_7 ;
int V_8 , V_2 , V_41 , V_42 ;
char V_9 [ V_10 + 1 ] ;
int V_43 [ 2 ] ;
char * V_44 , * V_45 ;
T_3 V_46 = 0 ;
V_30 [ 0 ] = V_31 ;
V_30 [ 1 ] = V_47 ;
V_30 [ 2 ] = V_18 ;
V_30 [ 3 ] = NULL ;
if ( F_26 ( V_43 ) ) {
perror ( L_20 ) ;
exit ( 1 ) ;
}
switch ( V_7 = F_4 () ) {
case - 1 :
perror ( L_7 ) ;
exit ( 1 ) ;
case 0 :
F_27 ( V_43 [ 0 ] ) ;
F_28 ( V_43 [ 1 ] , 1 ) ;
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
strncat ( V_9 , V_11 , V_10 ) ;
strncat (real_filename, L_8 KERNELDOCPATH KERNELDOC,
PATH_MAX - strlen(real_filename)) ;
F_5 ( V_9 , V_30 ) ;
fprintf ( V_5 , L_9 ) ;
perror ( V_9 ) ;
exit ( 1 ) ;
default:
F_27 ( V_43 [ 1 ] ) ;
V_44 = malloc ( 4096 ) ;
do {
while ( ( V_8 = F_29 ( V_43 [ 0 ] ,
V_44 + V_46 ,
4096 ) ) > 0 ) {
V_46 += V_8 ;
V_44 = realloc ( V_44 , V_46 + 4096 ) ;
}
} while ( V_8 == - V_48 );
if ( V_8 != 0 ) {
perror ( L_21 ) ;
exit ( 1 ) ;
}
F_6 ( V_7 , & V_8 , 0 ) ;
}
if ( F_7 ( V_8 ) )
V_12 |= F_8 ( V_8 ) ;
else
V_12 = 0xff ;
V_41 = 0 ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ ) {
if ( V_44 [ V_2 ] == '\n' ) {
V_41 ++ ;
V_44 [ V_2 ] = '\0' ;
}
}
V_42 = V_3 ;
V_3 += V_41 ;
V_4 = realloc ( V_4 , sizeof( char * ) * V_3 ) ;
V_45 = V_44 ;
for ( V_2 = 0 ; V_2 < V_46 && V_42 != V_3 ; V_2 ++ ) {
if ( V_44 [ V_2 ] == '\0' ) {
V_4 [ V_42 ] = V_45 ;
V_45 = V_44 + V_2 + 1 ;
V_42 ++ ;
}
}
}
static char * F_30 ( char * V_40 )
{
while ( * V_40 && ! isspace ( * V_40 ) )
V_40 ++ ;
if ( * V_40 )
* V_40 ++ = '\0' ;
return V_40 ;
}
static char * F_31 ( char * line )
{
if ( V_34 == V_49 && line [ 0 ] == '!' )
return line + 1 ;
else if ( V_34 == V_35 && ! strncmp ( line , L_22 , 4 ) )
return line + 4 ;
return NULL ;
}
static void F_32 ( T_2 * V_50 )
{
char line [ V_23 ] ;
char * V_25 , * V_40 ;
while ( fgets ( line , V_23 , V_50 ) ) {
V_25 = F_31 ( line ) ;
if ( ! V_25 ) {
F_33 ( line ) ;
continue;
}
switch ( * V_25 ++ ) {
case 'E' :
F_30 ( V_25 ) ;
F_34 ( V_25 ) ;
break;
case 'I' :
F_30 ( V_25 ) ;
F_35 ( V_25 ) ;
break;
case 'D' :
F_30 ( V_25 ) ;
F_36 ( V_25 ) ;
break;
case 'F' :
V_40 = F_30 ( V_25 ) ;
while ( isspace ( * V_40 ) )
V_40 ++ ;
F_37 ( V_25 , V_40 ) ;
break;
case 'P' :
V_40 = F_30 ( V_25 ) ;
while ( isspace ( * V_40 ) )
V_40 ++ ;
F_38 ( V_25 , V_40 ) ;
break;
case 'C' :
F_30 ( V_25 ) ;
if ( V_51 )
V_51 ( V_25 ) ;
break;
default:
F_33 ( line ) ;
}
}
fflush ( stdout ) ;
}
static int F_39 ( const char * V_21 )
{
char * V_52 = strrchr ( V_21 , '.' ) ;
return V_52 && ! strcmp ( V_52 + 1 , L_23 ) ;
}
int main ( int V_53 , char * V_54 [] )
{
const char * V_55 , * V_18 ;
T_2 * V_50 ;
int V_2 ;
V_24 = getenv ( L_24 ) ;
if ( ! V_24 )
V_24 = F_40 ( NULL , 0 ) ;
V_11 = getenv ( L_25 ) ;
if ( ! V_11 || ! * V_11 )
V_11 = V_24 ;
for (; ; ) {
int V_56 ;
struct V_57 V_58 [] = {
{ L_26 , V_59 , NULL , V_60 } ,
{ L_23 , V_59 , NULL , V_61 } ,
{ L_27 , V_59 , NULL , V_62 } ,
{}
} ;
V_56 = F_41 ( V_53 , V_54 , L_28 , V_58 , NULL ) ;
if ( V_56 == - 1 )
break;
switch ( V_56 ) {
case V_60 :
V_34 = V_49 ;
break;
case V_61 :
V_34 = V_35 ;
break;
case V_62 :
F_2 () ;
return 0 ;
default:
case '?' :
F_2 () ;
return 1 ;
}
}
V_53 -= V_63 ;
V_54 += V_63 ;
if ( V_53 != 2 ) {
F_2 () ;
exit ( 1 ) ;
}
V_55 = V_54 [ 0 ] ;
V_18 = V_54 [ 1 ] ;
if ( V_34 == V_64 )
V_34 = F_39 ( V_18 ) ? V_35 : V_49 ;
V_50 = fopen ( V_18 , L_12 ) ;
if ( V_50 == NULL ) {
fprintf ( V_5 , L_13 ) ;
perror ( V_18 ) ;
exit ( 2 ) ;
}
if ( strcmp ( L_29 , V_55 ) == 0 ) {
if ( V_34 == V_35 ) {
T_4 V_65 = time ( NULL ) ;
printf ( L_30 ,
V_18 , ctime ( & V_65 ) ) ;
}
F_33 = F_15 ;
F_35 = F_18 ;
F_34 = F_18 ;
F_36 = F_18 ;
F_37 = F_16 ;
F_38 = F_16 ;
V_51 = F_25 ;
F_32 ( V_50 ) ;
fseek ( V_50 , 0 , V_66 ) ;
F_33 = F_17 ;
F_35 = F_20 ;
F_34 = F_21 ;
F_36 = F_17 ;
F_37 = F_22 ;
F_38 = F_23 ;
V_51 = NULL ;
F_32 ( V_50 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( ! V_4 [ V_2 ] )
continue;
fprintf ( V_5 , L_31 ,
V_4 [ V_2 ] ) ;
}
} else if ( strcmp ( L_32 , V_55 ) == 0 ) {
printf ( L_33 , V_18 ) ;
F_33 = F_15 ;
F_35 = F_13 ;
F_34 = F_13 ;
F_36 = F_13 ;
F_37 = F_14 ;
F_38 = F_14 ;
V_51 = F_13 ;
F_32 ( V_50 ) ;
printf ( L_34 ) ;
} else {
fprintf ( V_5 , L_35 , V_55 ) ;
exit ( 1 ) ;
}
fclose ( V_50 ) ;
fflush ( stdout ) ;
return V_12 ;
}
