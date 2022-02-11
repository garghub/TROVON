static void F_1 ( void )
{
fprintf ( V_1 , L_1
L_2
L_3 ) ;
exit ( 1 ) ;
}
static inline int F_2 ( const char * V_2 )
{
return V_2 [ 0 ] == '$' && strchr ( L_4 , V_2 [ 1 ] )
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
V_18 = fscanf ( V_14 , L_5 , & V_16 -> V_4 , & V_17 , V_2 ) ;
if ( V_18 != 3 ) {
if ( V_18 != V_19 && fgets ( V_2 , 500 , V_14 ) == NULL )
fprintf ( V_1 , L_6 ) ;
return - 1 ;
}
if ( strlen ( V_2 ) > V_20 ) {
fprintf ( V_1 , L_7
L_8 ,
V_2 , strlen ( V_2 ) , V_20 ) ;
return - 1 ;
}
V_3 = V_2 ;
if ( V_21 && V_2 [ 0 ] == V_21 )
V_3 ++ ;
if ( strcmp ( V_3 , L_9 ) == 0 )
V_22 = V_16 -> V_4 ;
else if ( F_3 ( V_3 , V_16 -> V_4 , V_23 ,
F_5 ( V_23 ) ) == 0 )
;
else if ( toupper ( V_17 ) == 'A' )
{
if ( strcmp ( V_3 , L_10 ) &&
strcmp ( V_3 , L_11 ) &&
strcmp ( V_3 , L_12 ) &&
strcmp ( V_3 , L_13 ) )
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
fprintf ( V_1 , L_14
L_15 ) ;
exit ( V_25 ) ;
}
strcpy ( ( char * ) V_16 -> V_3 + 1 , V_2 ) ;
V_16 -> V_3 [ 0 ] = V_17 ;
V_16 -> V_26 = 0 ;
F_3 ( V_3 , V_16 -> V_4 , & V_27 , 1 ) ;
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
static char * V_28 [] = {
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
NULL } ;
static char * V_29 [] = {
L_26 ,
NULL } ;
static char * V_30 [] = {
L_27 ,
L_28 ,
L_29 ,
NULL } ;
int V_8 ;
char * V_31 = ( char * ) V_16 -> V_3 + 1 ;
if ( V_21 && * V_31 == V_21 )
V_31 ++ ;
if ( ! V_32 ) {
if ( F_6 ( V_16 , V_23 ,
F_5 ( V_23 ) ) == 0 )
return 0 ;
if ( ( V_16 -> V_4 == V_33 -> V_13 &&
strcmp ( V_31 ,
V_33 -> V_12 ) ) ||
( V_16 -> V_4 == V_34 -> V_13 &&
strcmp ( V_31 ,
V_34 -> V_12 ) ) )
return 0 ;
}
for ( V_8 = 0 ; V_28 [ V_8 ] ; V_8 ++ )
if ( strcmp ( V_31 , V_28 [ V_8 ] ) == 0 )
return 0 ;
for ( V_8 = 0 ; V_29 [ V_8 ] ; V_8 ++ ) {
int V_35 = strlen ( V_29 [ V_8 ] ) ;
if ( V_35 <= strlen ( V_31 ) &&
strncmp ( V_31 , V_29 [ V_8 ] , V_35 ) == 0 )
return 0 ;
}
for ( V_8 = 0 ; V_30 [ V_8 ] ; V_8 ++ ) {
int V_35 = strlen ( V_31 ) - strlen ( V_30 [ V_8 ] ) ;
if ( V_35 >= 0 && strcmp ( V_31 + V_35 , V_30 [ V_8 ] ) == 0 )
return 0 ;
}
return 1 ;
}
static void F_8 ( T_2 * V_14 )
{
while ( ! feof ( V_14 ) ) {
if ( V_36 >= V_37 ) {
V_37 += 10000 ;
V_38 = realloc ( V_38 , sizeof( * V_38 ) * V_37 ) ;
if ( ! V_38 ) {
fprintf ( V_1 , L_30 ) ;
exit ( 1 ) ;
}
}
if ( F_4 ( V_14 , & V_38 [ V_36 ] ) == 0 ) {
V_38 [ V_36 ] . V_39 = V_36 ;
V_36 ++ ;
}
}
}
static void F_9 ( char * V_40 )
{
if ( V_21 )
printf ( L_31 , V_21 , V_40 ) ;
else
printf ( L_32 , V_40 ) ;
printf ( L_33 ) ;
if ( V_21 )
printf ( L_34 , V_21 , V_40 ) ;
else
printf ( L_35 , V_40 ) ;
}
static int F_10 ( unsigned char * V_41 , int V_24 , char * V_42 )
{
int V_43 , V_44 , V_45 = 0 ;
while ( V_24 ) {
V_43 = * V_41 ;
if ( V_46 [ V_43 ] [ 0 ] == V_43 && V_47 [ V_43 ] == 1 ) {
* V_42 ++ = V_43 ;
V_45 ++ ;
} else {
V_44 = F_10 ( V_46 [ V_43 ] , V_47 [ V_43 ] , V_42 ) ;
V_45 += V_44 ;
V_42 += V_44 ;
}
V_41 ++ ;
V_24 -- ;
}
* V_42 = 0 ;
return V_45 ;
}
static int F_11 ( struct V_15 * V_16 )
{
return V_16 -> V_26 ;
}
static void F_12 ( void )
{
unsigned int V_8 , V_48 , V_49 ;
unsigned int V_50 [ 256 ] ;
unsigned int * V_51 ;
char V_52 [ V_20 ] ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
printf ( L_39 ) ;
printf ( L_40 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ) ;
printf ( L_44 ) ;
if ( ! V_53 )
F_9 ( L_16 ) ;
else
F_9 ( L_17 ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
if ( V_53 ) {
long long V_54 ;
int V_55 ;
if ( ! V_56 ) {
V_54 = V_38 [ V_8 ] . V_4 - V_57 ;
V_55 = ( V_54 < 0 || V_54 > V_58 ) ;
} else if ( F_11 ( & V_38 [ V_8 ] ) ) {
V_54 = V_38 [ V_8 ] . V_4 ;
V_55 = ( V_54 < 0 || V_54 > V_59 ) ;
} else {
V_54 = V_57 - V_38 [ V_8 ] . V_4 - 1 ;
V_55 = ( V_54 < V_60 || V_54 >= 0 ) ;
}
if ( V_55 ) {
fprintf ( V_1 , L_14
L_45 ,
F_11 ( & V_38 [ V_8 ] ) ? L_46 : L_47 ,
V_38 [ V_8 ] . V_4 ) ;
exit ( V_25 ) ;
}
printf ( L_48 , ( int ) V_54 ) ;
} else if ( ! F_11 ( & V_38 [ V_8 ] ) ) {
if ( V_22 <= V_38 [ V_8 ] . V_4 )
printf ( L_49 ,
V_38 [ V_8 ] . V_4 - V_22 ) ;
else
printf ( L_50 ,
V_22 - V_38 [ V_8 ] . V_4 ) ;
} else {
printf ( L_51 , V_38 [ V_8 ] . V_4 ) ;
}
}
printf ( L_52 ) ;
if ( V_53 ) {
F_9 ( L_18 ) ;
printf ( L_50 , V_22 - V_57 ) ;
printf ( L_52 ) ;
}
F_9 ( L_19 ) ;
printf ( L_53 , V_36 ) ;
printf ( L_52 ) ;
V_51 = malloc ( sizeof( unsigned int ) * ( ( V_36 + 255 ) / 256 ) ) ;
if ( ! V_51 ) {
fprintf ( V_1 , L_14
L_54 ) ;
exit ( V_25 ) ;
}
F_9 ( L_20 ) ;
V_49 = 0 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
if ( ( V_8 & 0xFF ) == 0 )
V_51 [ V_8 >> 8 ] = V_49 ;
printf ( L_55 , V_38 [ V_8 ] . V_24 ) ;
for ( V_48 = 0 ; V_48 < V_38 [ V_8 ] . V_24 ; V_48 ++ )
printf ( L_56 , V_38 [ V_8 ] . V_3 [ V_48 ] ) ;
printf ( L_52 ) ;
V_49 += V_38 [ V_8 ] . V_24 + 1 ;
}
printf ( L_52 ) ;
F_9 ( L_21 ) ;
for ( V_8 = 0 ; V_8 < ( ( V_36 + 255 ) >> 8 ) ; V_8 ++ )
printf ( L_53 , V_51 [ V_8 ] ) ;
printf ( L_52 ) ;
free ( V_51 ) ;
F_9 ( L_22 ) ;
V_49 = 0 ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ ) {
V_50 [ V_8 ] = V_49 ;
F_10 ( V_46 [ V_8 ] , V_47 [ V_8 ] , V_52 ) ;
printf ( L_57 , V_52 ) ;
V_49 += strlen ( V_52 ) + 1 ;
}
printf ( L_52 ) ;
F_9 ( L_23 ) ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ )
printf ( L_58 , V_50 [ V_8 ] ) ;
printf ( L_52 ) ;
}
static void F_13 ( unsigned char * V_61 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_62 [ V_61 [ V_8 ] + ( V_61 [ V_8 + 1 ] << 8 ) ] ++ ;
}
static void F_14 ( unsigned char * V_61 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_62 [ V_61 [ V_8 ] + ( V_61 [ V_8 + 1 ] << 8 ) ] -- ;
}
static void F_15 ( void )
{
unsigned int V_8 , V_63 ;
V_63 = 0 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
if ( F_7 ( & V_38 [ V_8 ] ) ) {
if ( V_63 != V_8 )
V_38 [ V_63 ] = V_38 [ V_8 ] ;
F_13 ( V_38 [ V_63 ] . V_3 , V_38 [ V_63 ] . V_24 ) ;
V_63 ++ ;
}
}
V_36 = V_63 ;
}
static void * F_16 ( unsigned char * V_2 , int V_24 , unsigned char * V_64 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ ) {
if ( V_2 [ V_8 ] == V_64 [ 0 ] && V_2 [ V_8 + 1 ] == V_64 [ 1 ] )
return & V_2 [ V_8 ] ;
}
return NULL ;
}
static void F_17 ( unsigned char * V_2 , int V_65 )
{
unsigned int V_8 , V_24 , V_66 ;
unsigned char * V_67 , * V_68 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
V_24 = V_38 [ V_8 ] . V_24 ;
V_67 = V_38 [ V_8 ] . V_3 ;
V_68 = F_16 ( V_67 , V_24 , V_2 ) ;
if ( ! V_68 ) continue;
F_14 ( V_38 [ V_8 ] . V_3 , V_24 ) ;
V_66 = V_24 ;
do {
* V_68 = V_65 ;
V_68 ++ ;
V_66 -= ( V_68 - V_67 ) ;
memmove ( V_68 , V_68 + 1 , V_66 ) ;
V_67 = V_68 ;
V_24 -- ;
if ( V_66 < 2 ) break;
V_68 = F_16 ( V_67 , V_66 , V_2 ) ;
} while ( V_68 );
V_38 [ V_8 ] . V_24 = V_24 ;
F_13 ( V_38 [ V_8 ] . V_3 , V_24 ) ;
}
}
static int F_18 ( void )
{
int V_8 , V_69 , V_70 ;
V_70 = - 10000 ;
V_69 = 0 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ ) {
if ( V_62 [ V_8 ] > V_70 ) {
V_69 = V_8 ;
V_70 = V_62 [ V_8 ] ;
}
}
return V_69 ;
}
static void F_19 ( void )
{
int V_8 , V_69 ;
for ( V_8 = 255 ; V_8 >= 0 ; V_8 -- ) {
if ( ! V_47 [ V_8 ] ) {
V_69 = F_18 () ;
if ( V_62 [ V_69 ] == 0 )
break;
V_47 [ V_8 ] = 2 ;
V_46 [ V_8 ] [ 0 ] = V_69 & 0xFF ;
V_46 [ V_8 ] [ 1 ] = ( V_69 >> 8 ) & 0xFF ;
F_17 ( V_46 [ V_8 ] , V_8 ) ;
}
}
}
static void F_20 ( void )
{
unsigned int V_8 , V_71 , V_43 ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ ) {
for ( V_71 = 0 ; V_71 < V_38 [ V_8 ] . V_24 ; V_71 ++ ) {
V_43 = V_38 [ V_8 ] . V_3 [ V_71 ] ;
V_46 [ V_43 ] [ 0 ] = V_43 ;
V_47 [ V_43 ] = 1 ;
}
}
}
static void F_21 ( void )
{
F_15 () ;
F_20 () ;
if ( ! V_36 ) {
fprintf ( V_1 , L_59 ) ;
exit ( 1 ) ;
}
F_19 () ;
}
static int F_22 ( const struct V_15 * V_72 )
{
const char * V_61 = ( char * ) V_72 -> V_3 + 1 ;
int V_24 = V_72 -> V_24 - 1 ;
if ( V_24 < 8 )
return 0 ;
if ( V_61 [ 0 ] != '_' || V_61 [ 1 ] != '_' )
return 0 ;
if ( ! memcmp ( V_61 + 2 , L_60 , 6 ) )
return 1 ;
if ( ! memcmp ( V_61 + 2 , L_61 , 5 ) )
return 1 ;
if ( ! memcmp ( V_61 + 2 , L_62 , 4 ) )
return 1 ;
if ( ! memcmp ( V_61 + V_24 - 6 , L_63 , 6 ) )
return 1 ;
if ( ! memcmp ( V_61 + V_24 - 4 , L_64 , 4 ) )
return 1 ;
return 0 ;
}
static int F_23 ( const char * V_2 )
{
const char * V_73 = V_2 ;
while ( * V_73 == '_' )
V_73 ++ ;
return V_73 - V_2 ;
}
static int F_24 ( const void * V_74 , const void * V_75 )
{
const struct V_15 * V_76 ;
const struct V_15 * V_77 ;
int V_78 , V_79 ;
V_76 = V_74 ;
V_77 = V_75 ;
if ( V_76 -> V_4 > V_77 -> V_4 )
return 1 ;
if ( V_76 -> V_4 < V_77 -> V_4 )
return - 1 ;
V_78 = ( V_76 -> V_3 [ 0 ] == 'w' ) || ( V_76 -> V_3 [ 0 ] == 'W' ) ;
V_79 = ( V_77 -> V_3 [ 0 ] == 'w' ) || ( V_77 -> V_3 [ 0 ] == 'W' ) ;
if ( V_78 != V_79 )
return V_78 - V_79 ;
V_78 = F_22 ( V_76 ) ;
V_79 = F_22 ( V_77 ) ;
if ( V_78 != V_79 )
return V_78 - V_79 ;
V_78 = F_23 ( ( const char * ) V_76 -> V_3 + 1 ) ;
V_79 = F_23 ( ( const char * ) V_77 -> V_3 + 1 ) ;
if ( V_78 != V_79 )
return V_78 - V_79 ;
return V_76 -> V_39 - V_77 -> V_39 ;
}
static void F_25 ( void )
{
qsort ( V_38 , V_36 , sizeof( struct V_15 ) , F_24 ) ;
}
static void F_26 ( void )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
if ( F_6 ( & V_38 [ V_8 ] , & V_27 , 1 ) ) {
V_38 [ V_8 ] . V_3 [ 0 ] = 'A' ;
V_38 [ V_8 ] . V_26 = 1 ;
}
}
static void F_27 ( void )
{
unsigned int V_8 ;
V_57 = - 1ULL ;
for ( V_8 = 0 ; V_8 < V_36 ; V_8 ++ )
if ( ! F_11 ( & V_38 [ V_8 ] ) &&
V_38 [ V_8 ] . V_4 < V_57 )
V_57 = V_38 [ V_8 ] . V_4 ;
}
int main ( int V_80 , char * * V_81 )
{
if ( V_80 >= 2 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_80 ; V_8 ++ ) {
if( strcmp ( V_81 [ V_8 ] , L_65 ) == 0 )
V_32 = 1 ;
else if ( strcmp ( V_81 [ V_8 ] , L_66 ) == 0 )
V_56 = 1 ;
else if ( strncmp ( V_81 [ V_8 ] , L_67 , 16 ) == 0 ) {
char * V_82 = & V_81 [ V_8 ] [ 16 ] ;
if ( ( * V_82 == '"' && * ( V_82 + 2 ) == '"' ) || ( * V_82 == '\'' && * ( V_82 + 2 ) == '\'' ) )
V_82 ++ ;
V_21 = * V_82 ;
} else if ( strcmp ( V_81 [ V_8 ] , L_68 ) == 0 )
V_53 = 1 ;
else
F_1 () ;
}
} else if ( V_80 != 1 )
F_1 () ;
F_8 ( V_83 ) ;
if ( V_56 )
F_26 () ;
if ( V_53 )
F_27 () ;
F_25 () ;
F_21 () ;
F_12 () ;
return 0 ;
}
