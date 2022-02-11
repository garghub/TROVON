static void F_1 ( void )
{
fprintf ( V_1 , L_1 ) ;
exit ( 1 ) ;
}
static inline int F_2 ( const char * V_2 )
{
return V_2 [ 0 ] == '$' && strchr ( L_2 , V_2 [ 1 ] )
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
V_17 = fscanf ( V_13 , L_3 , & V_15 -> V_4 , & V_16 , V_2 ) ;
if ( V_17 != 3 ) {
if ( V_17 != V_18 && fgets ( V_2 , 500 , V_13 ) == NULL )
fprintf ( V_1 , L_4 ) ;
return - 1 ;
}
V_3 = V_2 ;
if ( V_19 && V_2 [ 0 ] == V_19 )
V_3 ++ ;
if ( strcmp ( V_3 , L_5 ) == 0 )
V_20 = V_15 -> V_4 ;
else if ( F_3 ( V_3 , V_15 -> V_4 ) == 0 )
;
else if ( toupper ( V_16 ) == 'A' )
{
if ( strcmp ( V_3 , L_6 ) &&
strcmp ( V_3 , L_7 ) &&
strcmp ( V_3 , L_8 ) &&
strcmp ( V_3 , L_9 ) )
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
fprintf ( V_1 , L_10
L_11 ) ;
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
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
NULL } ;
int V_5 ;
int V_24 = 1 ;
if ( V_19 && * ( V_15 -> V_3 + 1 ) == V_19 )
V_24 ++ ;
if ( ! V_25 ) {
if ( F_6 ( V_15 ) == 0 )
return 0 ;
if ( ( V_15 -> V_4 == V_26 -> V_12 &&
strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_26 -> V_11 ) ) ||
( V_15 -> V_4 == V_27 -> V_12 &&
strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_27 -> V_11 ) ) )
return 0 ;
}
if ( strstr ( ( char * ) V_15 -> V_3 + V_24 , L_20 ) )
return 0 ;
for ( V_5 = 0 ; V_23 [ V_5 ] ; V_5 ++ )
if( strcmp ( ( char * ) V_15 -> V_3 + V_24 , V_23 [ V_5 ] ) == 0 )
return 0 ;
return 1 ;
}
static void F_8 ( T_2 * V_13 )
{
while ( ! feof ( V_13 ) ) {
if ( V_28 >= V_29 ) {
V_29 += 10000 ;
V_30 = realloc ( V_30 , sizeof( * V_30 ) * V_29 ) ;
if ( ! V_30 ) {
fprintf ( V_1 , L_21 ) ;
exit ( 1 ) ;
}
}
if ( F_5 ( V_13 , & V_30 [ V_28 ] ) == 0 ) {
V_30 [ V_28 ] . V_31 = V_28 ;
V_28 ++ ;
}
}
}
static void F_9 ( char * V_32 )
{
if ( V_19 )
printf ( L_22 , V_19 , V_32 ) ;
else
printf ( L_23 , V_32 ) ;
printf ( L_24 ) ;
if ( V_19 )
printf ( L_25 , V_19 , V_32 ) ;
else
printf ( L_26 , V_32 ) ;
}
static int F_10 ( unsigned char * V_33 , int V_21 , char * V_34 )
{
int V_35 , V_36 , V_37 = 0 ;
while ( V_21 ) {
V_35 = * V_33 ;
if ( V_38 [ V_35 ] [ 0 ] == V_35 && V_39 [ V_35 ] == 1 ) {
* V_34 ++ = V_35 ;
V_37 ++ ;
} else {
V_36 = F_10 ( V_38 [ V_35 ] , V_39 [ V_35 ] , V_34 ) ;
V_37 += V_36 ;
V_34 += V_36 ;
}
V_33 ++ ;
V_21 -- ;
}
* V_34 = 0 ;
return V_37 ;
}
static void F_11 ( void )
{
unsigned int V_5 , V_40 , V_41 ;
unsigned int V_42 [ 256 ] ;
unsigned int * V_43 ;
char V_44 [ V_45 ] ;
printf ( L_27 ) ;
printf ( L_28 ) ;
printf ( L_29 ) ;
printf ( L_30 ) ;
printf ( L_31 ) ;
printf ( L_32 ) ;
printf ( L_33 ) ;
printf ( L_34 ) ;
printf ( L_35 ) ;
F_9 ( L_12 ) ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
if ( toupper ( V_30 [ V_5 ] . V_3 [ 0 ] ) != 'A' ) {
if ( V_20 <= V_30 [ V_5 ] . V_4 )
printf ( L_36 ,
V_30 [ V_5 ] . V_4 - V_20 ) ;
else
printf ( L_37 ,
V_20 - V_30 [ V_5 ] . V_4 ) ;
} else {
printf ( L_38 , V_30 [ V_5 ] . V_4 ) ;
}
}
printf ( L_39 ) ;
F_9 ( L_13 ) ;
printf ( L_40 , V_28 ) ;
printf ( L_39 ) ;
V_43 = malloc ( sizeof( unsigned int ) * ( ( V_28 + 255 ) / 256 ) ) ;
if ( ! V_43 ) {
fprintf ( V_1 , L_10
L_41 ) ;
exit ( V_22 ) ;
}
F_9 ( L_14 ) ;
V_41 = 0 ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
if ( ( V_5 & 0xFF ) == 0 )
V_43 [ V_5 >> 8 ] = V_41 ;
printf ( L_42 , V_30 [ V_5 ] . V_21 ) ;
for ( V_40 = 0 ; V_40 < V_30 [ V_5 ] . V_21 ; V_40 ++ )
printf ( L_43 , V_30 [ V_5 ] . V_3 [ V_40 ] ) ;
printf ( L_39 ) ;
V_41 += V_30 [ V_5 ] . V_21 + 1 ;
}
printf ( L_39 ) ;
F_9 ( L_15 ) ;
for ( V_5 = 0 ; V_5 < ( ( V_28 + 255 ) >> 8 ) ; V_5 ++ )
printf ( L_40 , V_43 [ V_5 ] ) ;
printf ( L_39 ) ;
free ( V_43 ) ;
F_9 ( L_16 ) ;
V_41 = 0 ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ ) {
V_42 [ V_5 ] = V_41 ;
F_10 ( V_38 [ V_5 ] , V_39 [ V_5 ] , V_44 ) ;
printf ( L_44 , V_44 ) ;
V_41 += strlen ( V_44 ) + 1 ;
}
printf ( L_39 ) ;
F_9 ( L_17 ) ;
for ( V_5 = 0 ; V_5 < 256 ; V_5 ++ )
printf ( L_45 , V_42 [ V_5 ] ) ;
printf ( L_39 ) ;
}
static void F_12 ( unsigned char * V_46 , int V_21 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ )
V_47 [ V_46 [ V_5 ] + ( V_46 [ V_5 + 1 ] << 8 ) ] ++ ;
}
static void F_13 ( unsigned char * V_46 , int V_21 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ )
V_47 [ V_46 [ V_5 ] + ( V_46 [ V_5 + 1 ] << 8 ) ] -- ;
}
static void F_14 ( void )
{
unsigned int V_5 , V_48 ;
V_48 = 0 ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
if ( F_7 ( & V_30 [ V_5 ] ) ) {
if ( V_48 != V_5 )
V_30 [ V_48 ] = V_30 [ V_5 ] ;
F_12 ( V_30 [ V_48 ] . V_3 , V_30 [ V_48 ] . V_21 ) ;
V_48 ++ ;
}
}
V_28 = V_48 ;
}
static void * F_15 ( unsigned char * V_2 , int V_21 , unsigned char * V_49 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_21 - 1 ; V_5 ++ ) {
if ( V_2 [ V_5 ] == V_49 [ 0 ] && V_2 [ V_5 + 1 ] == V_49 [ 1 ] )
return & V_2 [ V_5 ] ;
}
return NULL ;
}
static void F_16 ( unsigned char * V_2 , int V_50 )
{
unsigned int V_5 , V_21 , V_51 ;
unsigned char * V_52 , * V_53 ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
V_21 = V_30 [ V_5 ] . V_21 ;
V_52 = V_30 [ V_5 ] . V_3 ;
V_53 = F_15 ( V_52 , V_21 , V_2 ) ;
if ( ! V_53 ) continue;
F_13 ( V_30 [ V_5 ] . V_3 , V_21 ) ;
V_51 = V_21 ;
do {
* V_53 = V_50 ;
V_53 ++ ;
V_51 -= ( V_53 - V_52 ) ;
memmove ( V_53 , V_53 + 1 , V_51 ) ;
V_52 = V_53 ;
V_21 -- ;
if ( V_51 < 2 ) break;
V_53 = F_15 ( V_52 , V_51 , V_2 ) ;
} while ( V_53 );
V_30 [ V_5 ] . V_21 = V_21 ;
F_12 ( V_30 [ V_5 ] . V_3 , V_21 ) ;
}
}
static int F_17 ( void )
{
int V_5 , V_54 , V_55 ;
V_55 = - 10000 ;
V_54 = 0 ;
for ( V_5 = 0 ; V_5 < 0x10000 ; V_5 ++ ) {
if ( V_47 [ V_5 ] > V_55 ) {
V_54 = V_5 ;
V_55 = V_47 [ V_5 ] ;
}
}
return V_54 ;
}
static void F_18 ( void )
{
int V_5 , V_54 ;
for ( V_5 = 255 ; V_5 >= 0 ; V_5 -- ) {
if ( ! V_39 [ V_5 ] ) {
V_54 = F_17 () ;
if ( V_47 [ V_54 ] == 0 )
break;
V_39 [ V_5 ] = 2 ;
V_38 [ V_5 ] [ 0 ] = V_54 & 0xFF ;
V_38 [ V_5 ] [ 1 ] = ( V_54 >> 8 ) & 0xFF ;
F_16 ( V_38 [ V_5 ] , V_5 ) ;
}
}
}
static void F_19 ( void )
{
unsigned int V_5 , V_56 , V_35 ;
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
for ( V_56 = 0 ; V_56 < V_30 [ V_5 ] . V_21 ; V_56 ++ ) {
V_35 = V_30 [ V_5 ] . V_3 [ V_56 ] ;
V_38 [ V_35 ] [ 0 ] = V_35 ;
V_39 [ V_35 ] = 1 ;
}
}
}
static void F_20 ( void )
{
F_14 () ;
F_19 () ;
if ( ! V_28 ) {
fprintf ( V_1 , L_46 ) ;
exit ( 1 ) ;
}
F_18 () ;
}
static int F_21 ( const struct V_14 * V_57 )
{
const char * V_46 = ( char * ) V_57 -> V_3 + 1 ;
int V_21 = V_57 -> V_21 - 1 ;
if ( V_21 < 8 )
return 0 ;
if ( V_46 [ 0 ] != '_' || V_46 [ 1 ] != '_' )
return 0 ;
if ( ! memcmp ( V_46 + 2 , L_47 , 6 ) )
return 1 ;
if ( ! memcmp ( V_46 + 2 , L_48 , 5 ) )
return 1 ;
if ( ! memcmp ( V_46 + 2 , L_49 , 4 ) )
return 1 ;
if ( ! memcmp ( V_46 + V_21 - 6 , L_50 , 6 ) )
return 1 ;
if ( ! memcmp ( V_46 + V_21 - 4 , L_51 , 4 ) )
return 1 ;
return 0 ;
}
static int F_22 ( const char * V_2 )
{
const char * V_58 = V_2 ;
while ( * V_58 == '_' )
V_58 ++ ;
return V_58 - V_2 ;
}
static int F_23 ( const void * V_59 , const void * V_60 )
{
const struct V_14 * V_61 ;
const struct V_14 * V_62 ;
int V_63 , V_64 ;
V_61 = V_59 ;
V_62 = V_60 ;
if ( V_61 -> V_4 > V_62 -> V_4 )
return 1 ;
if ( V_61 -> V_4 < V_62 -> V_4 )
return - 1 ;
V_63 = ( V_61 -> V_3 [ 0 ] == 'w' ) || ( V_61 -> V_3 [ 0 ] == 'W' ) ;
V_64 = ( V_62 -> V_3 [ 0 ] == 'w' ) || ( V_62 -> V_3 [ 0 ] == 'W' ) ;
if ( V_63 != V_64 )
return V_63 - V_64 ;
V_63 = F_21 ( V_61 ) ;
V_64 = F_21 ( V_62 ) ;
if ( V_63 != V_64 )
return V_63 - V_64 ;
V_63 = F_22 ( ( const char * ) V_61 -> V_3 + 1 ) ;
V_64 = F_22 ( ( const char * ) V_62 -> V_3 + 1 ) ;
if ( V_63 != V_64 )
return V_63 - V_64 ;
return V_61 -> V_31 - V_62 -> V_31 ;
}
static void F_24 ( void )
{
qsort ( V_30 , V_28 , sizeof( struct V_14 ) , F_23 ) ;
}
int main ( int V_65 , char * * V_66 )
{
if ( V_65 >= 2 ) {
int V_5 ;
for ( V_5 = 1 ; V_5 < V_65 ; V_5 ++ ) {
if( strcmp ( V_66 [ V_5 ] , L_52 ) == 0 )
V_25 = 1 ;
else if ( strncmp ( V_66 [ V_5 ] , L_53 , 16 ) == 0 ) {
char * V_67 = & V_66 [ V_5 ] [ 16 ] ;
if ( ( * V_67 == '"' && * ( V_67 + 2 ) == '"' ) || ( * V_67 == '\'' && * ( V_67 + 2 ) == '\'' ) )
V_67 ++ ;
V_19 = * V_67 ;
} else
F_1 () ;
}
} else if ( V_65 != 1 )
F_1 () ;
F_8 ( V_68 ) ;
F_24 () ;
F_20 () ;
F_11 () ;
return 0 ;
}
