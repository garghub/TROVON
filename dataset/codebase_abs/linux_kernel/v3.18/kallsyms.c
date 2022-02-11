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
static int F_3 ( const char * V_3 , unsigned long long V_4 ,
struct V_5 * V_6 , int V_7 )
{
T_1 V_8 ;
struct V_5 * V_9 ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 ) {
V_9 = & V_6 [ V_8 ] ;
if ( strcmp ( V_3 , V_9 -> V_10 ) == 0 ) {
V_9 -> V_11 = V_4 ;
return 0 ;
} else if ( strcmp ( V_3 , V_9 -> V_12 ) == 0 ) {
V_9 -> V_13 = V_4 ;
return 0 ;
}
}
return 1 ;
}
static int F_4 ( T_2 * V_14 , struct V_15 * V_16 )
{
char V_2 [ 500 ] ;
char * V_3 , V_17 ;
int V_18 ;
V_18 = fscanf ( V_14 , L_6 , & V_16 -> V_4 , & V_17 , V_2 ) ;
if ( V_18 != 3 ) {
if ( V_18 != V_19 && fgets ( V_2 , 500 , V_14 ) == NULL )
fprintf ( V_1 , L_7 ) ;
return - 1 ;
}
if ( strlen ( V_2 ) > V_20 ) {
fprintf ( V_1 , L_8
L_9 ,
V_2 , strlen ( V_2 ) , V_20 ) ;
return - 1 ;
}
V_3 = V_2 ;
if ( V_21 && V_2 [ 0 ] == V_21 )
V_3 ++ ;
if ( strcmp ( V_3 , L_10 ) == 0 )
V_22 = V_16 -> V_4 ;
else if ( F_3 ( V_3 , V_16 -> V_4 , V_23 ,
F_5 ( V_23 ) ) == 0 )
;
else if ( toupper ( V_17 ) == 'A' )
{
if ( strcmp ( V_3 , L_11 ) &&
strcmp ( V_3 , L_12 ) &&
strcmp ( V_3 , L_13 ) &&
strcmp ( V_3 , L_14 ) )
return - 1 ;
}
else if ( toupper ( V_17 ) == 'U' ||
F_2 ( V_3 ) )
return - 1 ;
else if ( V_2 [ 0 ] == '$' )
return - 1 ;
else if ( V_17 == 'N' )
return - 1 ;
V_16 -> V_24 = strlen ( V_2 ) + 1 ;
V_16 -> V_3 = malloc ( V_16 -> V_24 + 1 ) ;
if ( ! V_16 -> V_3 ) {
fprintf ( V_1 , L_15
L_16 ) ;
exit ( V_25 ) ;
}
strcpy ( ( char * ) V_16 -> V_3 + 1 , V_2 ) ;
V_16 -> V_3 [ 0 ] = V_17 ;
F_3 ( V_3 , V_16 -> V_4 , & V_26 , 1 ) ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , struct V_5 * V_6 ,
int V_7 )
{
T_1 V_8 ;
struct V_5 * V_9 ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 ) {
V_9 = & V_6 [ V_8 ] ;
if ( V_16 -> V_4 >= V_9 -> V_11 && V_16 -> V_4 <= V_9 -> V_13 )
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
static char * V_27 [] = {
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
NULL } ;
int V_8 ;
int V_28 = 1 ;
if ( V_16 -> V_4 < V_29 )
return 0 ;
if ( V_21 && * ( V_16 -> V_3 + 1 ) == V_21 )
V_28 ++ ;
if ( ! V_30 ) {
if ( F_6 ( V_16 , V_23 ,
F_5 ( V_23 ) ) == 0 )
return 0 ;
if ( ( V_16 -> V_4 == V_31 -> V_13 &&
strcmp ( ( char * ) V_16 -> V_3 + V_28 ,
V_31 -> V_12 ) ) ||
( V_16 -> V_4 == V_32 -> V_13 &&
strcmp ( ( char * ) V_16 -> V_3 + V_28 ,
V_32 -> V_12 ) ) )
return 0 ;
}
if ( strstr ( ( char * ) V_16 -> V_3 + V_28 , L_25 ) )
return 0 ;
for ( V_8 = 0 ; V_27 [ V_8 ] ; V_8 ++ )
if( strcmp ( ( char * ) V_16 -> V_3 + V_28 , V_27 [ V_8 ] ) == 0 )
return 0 ;
return 1 ;
}
static void F_8 ( T_2 * V_14 )
{
while ( ! feof ( V_14 ) ) {
if ( V_33 >= V_34 ) {
V_34 += 10000 ;
V_35 = realloc ( V_35 , sizeof( * V_35 ) * V_34 ) ;
if ( ! V_35 ) {
fprintf ( V_1 , L_26 ) ;
exit ( 1 ) ;
}
}
if ( F_4 ( V_14 , & V_35 [ V_33 ] ) == 0 ) {
V_35 [ V_33 ] . V_36 = V_33 ;
V_33 ++ ;
}
}
}
static void F_9 ( char * V_37 )
{
if ( V_21 )
printf ( L_27 , V_21 , V_37 ) ;
else
printf ( L_28 , V_37 ) ;
printf ( L_29 ) ;
if ( V_21 )
printf ( L_30 , V_21 , V_37 ) ;
else
printf ( L_31 , V_37 ) ;
}
static int F_10 ( unsigned char * V_38 , int V_24 , char * V_39 )
{
int V_40 , V_41 , V_42 = 0 ;
while ( V_24 ) {
V_40 = * V_38 ;
if ( V_43 [ V_40 ] [ 0 ] == V_40 && V_44 [ V_40 ] == 1 ) {
* V_39 ++ = V_40 ;
V_42 ++ ;
} else {
V_41 = F_10 ( V_43 [ V_40 ] , V_44 [ V_40 ] , V_39 ) ;
V_42 += V_41 ;
V_39 += V_41 ;
}
V_38 ++ ;
V_24 -- ;
}
* V_39 = 0 ;
return V_42 ;
}
static int F_11 ( struct V_15 * V_16 )
{
return toupper ( V_16 -> V_3 [ 0 ] ) == 'A' ;
}
static void F_12 ( void )
{
unsigned int V_8 , V_45 , V_46 ;
unsigned int V_47 [ 256 ] ;
unsigned int * V_48 ;
char V_49 [ V_20 ] ;
printf ( L_32 ) ;
printf ( L_33 ) ;
printf ( L_34 ) ;
printf ( L_35 ) ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
printf ( L_39 ) ;
printf ( L_40 ) ;
F_9 ( L_17 ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
if ( ! F_11 ( & V_35 [ V_8 ] ) ) {
if ( V_22 <= V_35 [ V_8 ] . V_4 )
printf ( L_41 ,
V_35 [ V_8 ] . V_4 - V_22 ) ;
else
printf ( L_42 ,
V_22 - V_35 [ V_8 ] . V_4 ) ;
} else {
printf ( L_43 , V_35 [ V_8 ] . V_4 ) ;
}
}
printf ( L_44 ) ;
F_9 ( L_18 ) ;
printf ( L_45 , V_33 ) ;
printf ( L_44 ) ;
V_48 = malloc ( sizeof( unsigned int ) * ( ( V_33 + 255 ) / 256 ) ) ;
if ( ! V_48 ) {
fprintf ( V_1 , L_15
L_46 ) ;
exit ( V_25 ) ;
}
F_9 ( L_19 ) ;
V_46 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
if ( ( V_8 & 0xFF ) == 0 )
V_48 [ V_8 >> 8 ] = V_46 ;
printf ( L_47 , V_35 [ V_8 ] . V_24 ) ;
for ( V_45 = 0 ; V_45 < V_35 [ V_8 ] . V_24 ; V_45 ++ )
printf ( L_48 , V_35 [ V_8 ] . V_3 [ V_45 ] ) ;
printf ( L_44 ) ;
V_46 += V_35 [ V_8 ] . V_24 + 1 ;
}
printf ( L_44 ) ;
F_9 ( L_20 ) ;
for ( V_8 = 0 ; V_8 < ( ( V_33 + 255 ) >> 8 ) ; V_8 ++ )
printf ( L_45 , V_48 [ V_8 ] ) ;
printf ( L_44 ) ;
free ( V_48 ) ;
F_9 ( L_21 ) ;
V_46 = 0 ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ ) {
V_47 [ V_8 ] = V_46 ;
F_10 ( V_43 [ V_8 ] , V_44 [ V_8 ] , V_49 ) ;
printf ( L_49 , V_49 ) ;
V_46 += strlen ( V_49 ) + 1 ;
}
printf ( L_44 ) ;
F_9 ( L_22 ) ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ )
printf ( L_50 , V_47 [ V_8 ] ) ;
printf ( L_44 ) ;
}
static void F_13 ( unsigned char * V_50 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_51 [ V_50 [ V_8 ] + ( V_50 [ V_8 + 1 ] << 8 ) ] ++ ;
}
static void F_14 ( unsigned char * V_50 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_51 [ V_50 [ V_8 ] + ( V_50 [ V_8 + 1 ] << 8 ) ] -- ;
}
static void F_15 ( void )
{
unsigned int V_8 , V_52 ;
V_52 = 0 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
if ( F_7 ( & V_35 [ V_8 ] ) ) {
if ( V_52 != V_8 )
V_35 [ V_52 ] = V_35 [ V_8 ] ;
F_13 ( V_35 [ V_52 ] . V_3 , V_35 [ V_52 ] . V_24 ) ;
V_52 ++ ;
}
}
V_33 = V_52 ;
}
static void * F_16 ( unsigned char * V_2 , int V_24 , unsigned char * V_53 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ ) {
if ( V_2 [ V_8 ] == V_53 [ 0 ] && V_2 [ V_8 + 1 ] == V_53 [ 1 ] )
return & V_2 [ V_8 ] ;
}
return NULL ;
}
static void F_17 ( unsigned char * V_2 , int V_54 )
{
unsigned int V_8 , V_24 , V_55 ;
unsigned char * V_56 , * V_57 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
V_24 = V_35 [ V_8 ] . V_24 ;
V_56 = V_35 [ V_8 ] . V_3 ;
V_57 = F_16 ( V_56 , V_24 , V_2 ) ;
if ( ! V_57 ) continue;
F_14 ( V_35 [ V_8 ] . V_3 , V_24 ) ;
V_55 = V_24 ;
do {
* V_57 = V_54 ;
V_57 ++ ;
V_55 -= ( V_57 - V_56 ) ;
memmove ( V_57 , V_57 + 1 , V_55 ) ;
V_56 = V_57 ;
V_24 -- ;
if ( V_55 < 2 ) break;
V_57 = F_16 ( V_56 , V_55 , V_2 ) ;
} while ( V_57 );
V_35 [ V_8 ] . V_24 = V_24 ;
F_13 ( V_35 [ V_8 ] . V_3 , V_24 ) ;
}
}
static int F_18 ( void )
{
int V_8 , V_58 , V_59 ;
V_59 = - 10000 ;
V_58 = 0 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ ) {
if ( V_51 [ V_8 ] > V_59 ) {
V_58 = V_8 ;
V_59 = V_51 [ V_8 ] ;
}
}
return V_58 ;
}
static void F_19 ( void )
{
int V_8 , V_58 ;
for ( V_8 = 255 ; V_8 >= 0 ; V_8 -- ) {
if ( ! V_44 [ V_8 ] ) {
V_58 = F_18 () ;
if ( V_51 [ V_58 ] == 0 )
break;
V_44 [ V_8 ] = 2 ;
V_43 [ V_8 ] [ 0 ] = V_58 & 0xFF ;
V_43 [ V_8 ] [ 1 ] = ( V_58 >> 8 ) & 0xFF ;
F_17 ( V_43 [ V_8 ] , V_8 ) ;
}
}
}
static void F_20 ( void )
{
unsigned int V_8 , V_60 , V_40 ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ ) {
for ( V_60 = 0 ; V_60 < V_35 [ V_8 ] . V_24 ; V_60 ++ ) {
V_40 = V_35 [ V_8 ] . V_3 [ V_60 ] ;
V_43 [ V_40 ] [ 0 ] = V_40 ;
V_44 [ V_40 ] = 1 ;
}
}
}
static void F_21 ( void )
{
F_15 () ;
F_20 () ;
if ( ! V_33 ) {
fprintf ( V_1 , L_51 ) ;
exit ( 1 ) ;
}
F_19 () ;
}
static int F_22 ( const struct V_15 * V_61 )
{
const char * V_50 = ( char * ) V_61 -> V_3 + 1 ;
int V_24 = V_61 -> V_24 - 1 ;
if ( V_24 < 8 )
return 0 ;
if ( V_50 [ 0 ] != '_' || V_50 [ 1 ] != '_' )
return 0 ;
if ( ! memcmp ( V_50 + 2 , L_52 , 6 ) )
return 1 ;
if ( ! memcmp ( V_50 + 2 , L_53 , 5 ) )
return 1 ;
if ( ! memcmp ( V_50 + 2 , L_54 , 4 ) )
return 1 ;
if ( ! memcmp ( V_50 + V_24 - 6 , L_55 , 6 ) )
return 1 ;
if ( ! memcmp ( V_50 + V_24 - 4 , L_56 , 4 ) )
return 1 ;
return 0 ;
}
static int F_23 ( const char * V_2 )
{
const char * V_62 = V_2 ;
while ( * V_62 == '_' )
V_62 ++ ;
return V_62 - V_2 ;
}
static int F_24 ( const void * V_63 , const void * V_64 )
{
const struct V_15 * V_65 ;
const struct V_15 * V_66 ;
int V_67 , V_68 ;
V_65 = V_63 ;
V_66 = V_64 ;
if ( V_65 -> V_4 > V_66 -> V_4 )
return 1 ;
if ( V_65 -> V_4 < V_66 -> V_4 )
return - 1 ;
V_67 = ( V_65 -> V_3 [ 0 ] == 'w' ) || ( V_65 -> V_3 [ 0 ] == 'W' ) ;
V_68 = ( V_66 -> V_3 [ 0 ] == 'w' ) || ( V_66 -> V_3 [ 0 ] == 'W' ) ;
if ( V_67 != V_68 )
return V_67 - V_68 ;
V_67 = F_22 ( V_65 ) ;
V_68 = F_22 ( V_66 ) ;
if ( V_67 != V_68 )
return V_67 - V_68 ;
V_67 = F_23 ( ( const char * ) V_65 -> V_3 + 1 ) ;
V_68 = F_23 ( ( const char * ) V_66 -> V_3 + 1 ) ;
if ( V_67 != V_68 )
return V_67 - V_68 ;
return V_65 -> V_36 - V_66 -> V_36 ;
}
static void F_25 ( void )
{
qsort ( V_35 , V_33 , sizeof( struct V_15 ) , F_24 ) ;
}
static void F_26 ( void )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_33 ; V_8 ++ )
if ( F_6 ( & V_35 [ V_8 ] , & V_26 , 1 ) )
V_35 [ V_8 ] . V_3 [ 0 ] = 'A' ;
}
int main ( int V_69 , char * * V_70 )
{
if ( V_69 >= 2 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_69 ; V_8 ++ ) {
if( strcmp ( V_70 [ V_8 ] , L_57 ) == 0 )
V_30 = 1 ;
else if ( strcmp ( V_70 [ V_8 ] , L_58 ) == 0 )
V_71 = 1 ;
else if ( strncmp ( V_70 [ V_8 ] , L_59 , 16 ) == 0 ) {
char * V_72 = & V_70 [ V_8 ] [ 16 ] ;
if ( ( * V_72 == '"' && * ( V_72 + 2 ) == '"' ) || ( * V_72 == '\'' && * ( V_72 + 2 ) == '\'' ) )
V_72 ++ ;
V_21 = * V_72 ;
} else if ( strncmp ( V_70 [ V_8 ] , L_60 , 14 ) == 0 ) {
const char * V_72 = & V_70 [ V_8 ] [ 14 ] ;
V_29 = F_27 ( V_72 , NULL , 16 ) ;
} else
F_1 () ;
}
} else if ( V_69 != 1 )
F_1 () ;
F_8 ( V_73 ) ;
if ( V_71 )
F_26 () ;
F_25 () ;
F_21 () ;
F_12 () ;
return 0 ;
}
