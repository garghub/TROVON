static void F_1 ( void )
{
fprintf ( V_1 , L_1
L_2
L_3
L_4 ) ;
exit ( 1 ) ;
}
static inline int F_2 ( const char * V_2 )
{
return V_2 [ 0 ] == '$' && strchr ( L_5 , V_2 [ 1 ] )
&& ( V_2 [ 2 ] == '\0' || V_2 [ 2 ] == '.' ) ;
}
static int F_3 ( const char * V_3 , unsigned long long V_4 )
{
T_1 V_5 ;
struct V_6 * V_7 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_8 ) ; ++ V_5 ) {
V_7 = & V_8 [ V_5 ] ;
if ( strcmp ( V_3 , V_7 -> V_9 ) == 0 ) {
V_7 -> V_10 = V_4 ;
return 0 ;
} else if ( strcmp ( V_3 , V_7 -> V_11 ) == 0 ) {
V_7 -> V_12 = V_4 ;
return 0 ;
}
}
return 1 ;
}
static int F_5 ( T_2 * V_13 , struct V_14 * V_15 )
{
char V_2 [ 500 ] ;
char * V_3 , V_16 ;
int V_17 ;
V_17 = fscanf ( V_13 , L_6 , & V_15 -> V_4 , & V_16 , V_2 ) ;
if ( V_17 != 3 ) {
if ( V_17 != V_18 && fgets ( V_2 , 500 , V_13 ) == NULL )
fprintf ( V_1 , L_7 ) ;
return - 1 ;
}
V_3 = V_2 ;
if ( V_19 && V_2 [ 0 ] == V_19 )
V_3 ++ ;
if ( strcmp ( V_3 , L_8 ) == 0 )
V_20 = V_15 -> V_4 ;
else if ( F_3 ( V_3 , V_15 -> V_4 ) == 0 )
;
else if ( toupper ( V_16 ) == 'A' )
{
if ( strcmp ( V_3 , L_9 ) &&
strcmp ( V_3 , L_10 ) &&
strcmp ( V_3 , L_11 ) &&
strcmp ( V_3 , L_12 ) )
return - 1 ;
}
else if ( toupper ( V_16 ) == 'U' ||
F_2 ( V_3 ) )
return - 1 ;
else if ( V_2 [ 0 ] == '$' )
return - 1 ;
else if ( V_16 == 'N' )
return - 1 ;
V_15 -> V_21 = strlen ( V_2 ) + 1 ;
V_15 -> V_3 = malloc ( V_15 -> V_21 + 1 ) ;
if ( ! V_15 -> V_3 ) {
fprintf ( V_1 , L_13
L_14 ) ;
exit ( V_22 ) ;
}
strcpy ( ( char * ) V_15 -> V_3 + 1 , V_2 ) ;
V_15 -> V_3 [ 0 ] = V_16 ;
return 0 ;
}
static int F_6 ( struct V_14 * V_15 )
{
T_1 V_5 ;
struct V_6 * V_7 ;
for ( V_5 = 0 ; V_5 < F_4 ( V_8 ) ; ++ V_5 ) {
V_7 = & V_8 [ V_5 ] ;
if ( V_15 -> V_4 >= V_7 -> V_10 && V_15 -> V_4 <= V_7 -> V_12 )
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
static char * V_23 [] = {
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
NULL } ;
int V_5 ;
int V_24 = 1 ;
if ( V_15 -> V_4 < V_25 )
return 0 ;
if ( V_19 && * ( V_15 -> V_3 + 1 ) == V_19 )
V_24 ++ ;
if ( ! V_26 ) {
if ( F_6 ( V_15 ) == 0 )
return 0 ;
if ( ( V_15 -> V_4 == V_27 -> V_12 &&
strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_27 -> V_11 ) ) ||
( V_15 -> V_4 == V_28 -> V_12 &&
strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_28 -> V_11 ) ) )
return 0 ;
}
if ( strstr ( ( char * ) V_15 -> V_3 + V_24 , L_23 ) )
return 0 ;
for ( V_5 = 0 ; V_23 [ V_5 ] ; V_5 ++ )
if( strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_23 [ V_5 ] ) == 0 )
return 0 ;
return 1 ;
}
static void F_8 ( T_2 * V_13 )
{
while ( ! feof ( V_13 ) ) {
if ( V_29 >= V_30 ) {
V_30 += 10000 ;
V_31 = realloc ( V_31 , sizeof( * V_31 ) * V_30 ) ;
if ( ! V_31 ) {
fprintf ( V_1 , L_24 ) ;
exit ( 1 ) ;
}
}
if ( F_5 ( V_13 , & V_31 [ V_29 ] ) == 0 ) {
V_31 [ V_29 ] . V_32 = V_29 ;
V_29 ++ ;
}
}
}
static void F_9 ( char * V_33 )
{
if ( V_19 )
printf ( L_25 , V_19 , V_33 ) ;
else
printf ( L_26 , V_33 ) ;
printf ( L_27 ) ;
if ( V_19 )
printf ( L_28 , V_19 , V_33 ) ;
else
printf ( L_29 , V_33 ) ;
}
static int F_10 ( unsigned char * V_34 , int V_21 , char * V_35 )
{
int V_36 , V_37 , V_38 = 0 ;
while ( V_21 ) {
V_36 = * V_34 ;
if ( V_39 [ V_36 ] [ 0 ] == V_36 && V_40 [ V_36 ] == 1 ) {
* V_35 ++ = V_36 ;
V_38 ++ ;
} else {
V_37 = F_10 ( V_39 [ V_36 ] , V_40 [ V_36 ] , V_35 ) ;
V_38 += V_37 ;
V_35 += V_37 ;
}
V_34 ++ ;
V_21 -- ;
}
* V_35 = 0 ;
return V_38 ;
}
static void F_11 ( void )
{
unsigned int V_5 , V_41 , V_42 ;
unsigned int V_43 [ 256 ] ;
unsigned int * V_44 ;
char V_45 [ V_46 ] ;
printf ( L_30 ) ;
printf ( L_31 ) ;
printf ( L_32 ) ;
printf ( L_33 ) ;
printf ( L_34 ) ;
printf ( L_35 ) ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
F_9 ( L_15 ) ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( toupper ( V_31 [ V_5 ] . V_3 [ 0 ] ) != 'A' ) {
if ( V_20 <= V_31 [ V_5 ] . V_4 )
printf ( L_39 ,
V_31 [ V_5 ] . V_4 - V_20 ) ;
else
printf ( L_40 ,
V_20 - V_31 [ V_5 ] . V_4 ) ;
} else {
printf ( L_41 , V_31 [ V_5 ] . V_4 ) ;
}
}
printf ( L_42 ) ;
F_9 ( L_16 ) ;
printf ( L_43 , V_29 ) ;
printf ( L_42 ) ;
V_44 = malloc ( sizeof( unsigned int ) * ( ( V_29 + 255 ) / 256 ) ) ;
if ( ! V_44 ) {
fprintf ( V_1 , L_13
L_44 ) ;
exit ( V_22 ) ;
}
F_9 ( L_17 ) ;
V_42 = 0 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( ( V_5 & 0xFF ) == 0 )
V_44 [ V_5 >> 8 ] = V_42 ;
printf ( L_45 , V_31 [ V_5 ] . V_21 ) ;
for ( V_41 = 0 ; V_41 < V_31 [ V_5 ] . V_21 ; V_41 ++ )
printf ( L_46 , V_31 [ V_5 ] . V_3 [ V_41 ] ) ;
printf ( L_42 ) ;
V_42 += V_31 [ V_5 ] . V_21 + 1 ;
}
printf ( L_42 ) ;
F_9 ( L_18 ) ;
for ( V_5 = 0 ; V_5 < ( ( V_29 + 255 ) >> 8 ) ; V_5 ++ )
printf ( L_43 , V_44 [ V_5 ] ) ;
printf ( L_42 ) ;
free ( V_44 ) ;
F_9 ( L_19 ) ;
V_42 = 0 ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ ) {
V_43 [ V_5 ] = V_42 ;
F_10 ( V_39 [ V_5 ] , V_40 [ V_5 ] , V_45 ) ;
printf ( L_47 , V_45 ) ;
V_42 += strlen ( V_45 ) + 1 ;
}
printf ( L_42 ) ;
F_9 ( L_20 ) ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ )
printf ( L_48 , V_43 [ V_5 ] ) ;
printf ( L_42 ) ;
}
static void F_12 ( unsigned char * V_47 , int V_21 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ )
V_48 [ V_47 [ V_5 ] + ( V_47 [ V_5 + 1 ] << 8 ) ] ++ ;
}
static void F_13 ( unsigned char * V_47 , int V_21 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ )
V_48 [ V_47 [ V_5 ] + ( V_47 [ V_5 + 1 ] << 8 ) ] -- ;
}
static void F_14 ( void )
{
unsigned int V_5 , V_49 ;
V_49 = 0 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( F_7 ( & V_31 [ V_5 ] ) ) {
if ( V_49 != V_5 )
V_31 [ V_49 ] = V_31 [ V_5 ] ;
F_12 ( V_31 [ V_49 ] . V_3 , V_31 [ V_49 ] . V_21 ) ;
V_49 ++ ;
}
}
V_29 = V_49 ;
}
static void * F_15 ( unsigned char * V_2 , int V_21 , unsigned char * V_50 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ ) {
if ( V_2 [ V_5 ] == V_50 [ 0 ] && V_2 [ V_5 + 1 ] == V_50 [ 1 ] )
return & V_2 [ V_5 ] ;
}
return NULL ;
}
static void F_16 ( unsigned char * V_2 , int V_51 )
{
unsigned int V_5 , V_21 , V_52 ;
unsigned char * V_53 , * V_54 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
V_21 = V_31 [ V_5 ] . V_21 ;
V_53 = V_31 [ V_5 ] . V_3 ;
V_54 = F_15 ( V_53 , V_21 , V_2 ) ;
if ( ! V_54 ) continue;
F_13 ( V_31 [ V_5 ] . V_3 , V_21 ) ;
V_52 = V_21 ;
do {
* V_54 = V_51 ;
V_54 ++ ;
V_52 -= ( V_54 - V_53 ) ;
memmove ( V_54 , V_54 + 1 , V_52 ) ;
V_53 = V_54 ;
V_21 -- ;
if ( V_52 < 2 ) break;
V_54 = F_15 ( V_53 , V_52 , V_2 ) ;
} while ( V_54 );
V_31 [ V_5 ] . V_21 = V_21 ;
F_12 ( V_31 [ V_5 ] . V_3 , V_21 ) ;
}
}
static int F_17 ( void )
{
int V_5 , V_55 , V_56 ;
V_56 = - 10000 ;
V_55 = 0 ;
for ( V_5 = 0 ; V_5 < 0x10000 ; V_5 ++ ) {
if ( V_48 [ V_5 ] > V_56 ) {
V_55 = V_5 ;
V_56 = V_48 [ V_5 ] ;
}
}
return V_55 ;
}
static void F_18 ( void )
{
int V_5 , V_55 ;
for ( V_5 = 255 ; V_5 >= 0 ; V_5 -- ) {
if ( ! V_40 [ V_5 ] ) {
V_55 = F_17 () ;
if ( V_48 [ V_55 ] == 0 )
break;
V_40 [ V_5 ] = 2 ;
V_39 [ V_5 ] [ 0 ] = V_55 & 0xFF ;
V_39 [ V_5 ] [ 1 ] = ( V_55 >> 8 ) & 0xFF ;
F_16 ( V_39 [ V_5 ] , V_5 ) ;
}
}
}
static void F_19 ( void )
{
unsigned int V_5 , V_57 , V_36 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
memset ( V_40 , 0 , sizeof( V_40 ) ) ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
for ( V_57 = 0 ; V_57 < V_31 [ V_5 ] . V_21 ; V_57 ++ ) {
V_36 = V_31 [ V_5 ] . V_3 [ V_57 ] ;
V_39 [ V_36 ] [ 0 ] = V_36 ;
V_40 [ V_36 ] = 1 ;
}
}
}
static void F_20 ( void )
{
F_14 () ;
F_19 () ;
if ( ! V_29 ) {
fprintf ( V_1 , L_49 ) ;
exit ( 1 ) ;
}
F_18 () ;
}
static int F_21 ( const struct V_14 * V_58 )
{
const char * V_47 = ( char * ) V_58 -> V_3 + 1 ;
int V_21 = V_58 -> V_21 - 1 ;
if ( V_21 < 8 )
return 0 ;
if ( V_47 [ 0 ] != '_' || V_47 [ 1 ] != '_' )
return 0 ;
if ( ! memcmp ( V_47 + 2 , L_50 , 6 ) )
return 1 ;
if ( ! memcmp ( V_47 + 2 , L_51 , 5 ) )
return 1 ;
if ( ! memcmp ( V_47 + 2 , L_52 , 4 ) )
return 1 ;
if ( ! memcmp ( V_47 + V_21 - 6 , L_53 , 6 ) )
return 1 ;
if ( ! memcmp ( V_47 + V_21 - 4 , L_54 , 4 ) )
return 1 ;
return 0 ;
}
static int F_22 ( const char * V_2 )
{
const char * V_59 = V_2 ;
while ( * V_59 == '_' )
V_59 ++ ;
return V_59 - V_2 ;
}
static int F_23 ( const void * V_60 , const void * V_61 )
{
const struct V_14 * V_62 ;
const struct V_14 * V_63 ;
int V_64 , V_65 ;
V_62 = V_60 ;
V_63 = V_61 ;
if ( V_62 -> V_4 > V_63 -> V_4 )
return 1 ;
if ( V_62 -> V_4 < V_63 -> V_4 )
return - 1 ;
V_64 = ( V_62 -> V_3 [ 0 ] == 'w' ) || ( V_62 -> V_3 [ 0 ] == 'W' ) ;
V_65 = ( V_63 -> V_3 [ 0 ] == 'w' ) || ( V_63 -> V_3 [ 0 ] == 'W' ) ;
if ( V_64 != V_65 )
return V_64 - V_65 ;
V_64 = F_21 ( V_62 ) ;
V_65 = F_21 ( V_63 ) ;
if ( V_64 != V_65 )
return V_64 - V_65 ;
V_64 = F_22 ( ( const char * ) V_62 -> V_3 + 1 ) ;
V_65 = F_22 ( ( const char * ) V_63 -> V_3 + 1 ) ;
if ( V_64 != V_65 )
return V_64 - V_65 ;
return V_62 -> V_32 - V_63 -> V_32 ;
}
static void F_24 ( void )
{
qsort ( V_31 , V_29 , sizeof( struct V_14 ) , F_23 ) ;
}
int main ( int V_66 , char * * V_67 )
{
if ( V_66 >= 2 ) {
int V_5 ;
for ( V_5 = 1 ; V_5 < V_66 ; V_5 ++ ) {
if( strcmp ( V_67 [ V_5 ] , L_55 ) == 0 )
V_26 = 1 ;
else if ( strncmp ( V_67 [ V_5 ] , L_56 , 16 ) == 0 ) {
char * V_68 = & V_67 [ V_5 ] [ 16 ] ;
if ( ( * V_68 == '"' && * ( V_68 + 2 ) == '"' ) || ( * V_68 == '\'' && * ( V_68 + 2 ) == '\'' ) )
V_68 ++ ;
V_19 = * V_68 ;
} else if ( strncmp ( V_67 [ V_5 ] , L_57 , 14 ) == 0 ) {
const char * V_68 = & V_67 [ V_5 ] [ 14 ] ;
V_25 = F_25 ( V_68 , NULL , 16 ) ;
} else
F_1 () ;
}
} else if ( V_66 != 1 )
F_1 () ;
F_8 ( V_69 ) ;
F_24 () ;
F_20 () ;
F_11 () ;
return 0 ;
}
