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
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
NULL } ;
static char * V_29 [] = {
L_27 ,
L_28 ,
L_29 ,
NULL } ;
int V_8 ;
char * V_30 = ( char * ) V_16 -> V_3 + 1 ;
if ( V_21 && * V_30 == V_21 )
V_30 ++ ;
if ( ! V_31 ) {
if ( F_6 ( V_16 , V_23 ,
F_5 ( V_23 ) ) == 0 )
return 0 ;
if ( ( V_16 -> V_4 == V_32 -> V_13 &&
strcmp ( V_30 ,
V_32 -> V_12 ) ) ||
( V_16 -> V_4 == V_33 -> V_13 &&
strcmp ( V_30 ,
V_33 -> V_12 ) ) )
return 0 ;
}
for ( V_8 = 0 ; V_28 [ V_8 ] ; V_8 ++ )
if ( strcmp ( V_30 , V_28 [ V_8 ] ) == 0 )
return 0 ;
for ( V_8 = 0 ; V_29 [ V_8 ] ; V_8 ++ ) {
int V_34 = strlen ( V_30 ) - strlen ( V_29 [ V_8 ] ) ;
if ( V_34 >= 0 && strcmp ( V_30 + V_34 , V_29 [ V_8 ] ) == 0 )
return 0 ;
}
return 1 ;
}
static void F_8 ( T_2 * V_14 )
{
while ( ! feof ( V_14 ) ) {
if ( V_35 >= V_36 ) {
V_36 += 10000 ;
V_37 = realloc ( V_37 , sizeof( * V_37 ) * V_36 ) ;
if ( ! V_37 ) {
fprintf ( V_1 , L_30 ) ;
exit ( 1 ) ;
}
}
if ( F_4 ( V_14 , & V_37 [ V_35 ] ) == 0 ) {
V_37 [ V_35 ] . V_38 = V_35 ;
V_35 ++ ;
}
}
}
static void F_9 ( char * V_39 )
{
if ( V_21 )
printf ( L_31 , V_21 , V_39 ) ;
else
printf ( L_32 , V_39 ) ;
printf ( L_33 ) ;
if ( V_21 )
printf ( L_34 , V_21 , V_39 ) ;
else
printf ( L_35 , V_39 ) ;
}
static int F_10 ( unsigned char * V_40 , int V_24 , char * V_41 )
{
int V_42 , V_43 , V_44 = 0 ;
while ( V_24 ) {
V_42 = * V_40 ;
if ( V_45 [ V_42 ] [ 0 ] == V_42 && V_46 [ V_42 ] == 1 ) {
* V_41 ++ = V_42 ;
V_44 ++ ;
} else {
V_43 = F_10 ( V_45 [ V_42 ] , V_46 [ V_42 ] , V_41 ) ;
V_44 += V_43 ;
V_41 += V_43 ;
}
V_40 ++ ;
V_24 -- ;
}
* V_41 = 0 ;
return V_44 ;
}
static int F_11 ( struct V_15 * V_16 )
{
return V_16 -> V_26 ;
}
static void F_12 ( void )
{
unsigned int V_8 , V_47 , V_48 ;
unsigned int V_49 [ 256 ] ;
unsigned int * V_50 ;
char V_51 [ V_20 ] ;
printf ( L_36 ) ;
printf ( L_37 ) ;
printf ( L_38 ) ;
printf ( L_39 ) ;
printf ( L_40 ) ;
printf ( L_41 ) ;
printf ( L_42 ) ;
printf ( L_43 ) ;
printf ( L_44 ) ;
if ( ! V_52 )
F_9 ( L_17 ) ;
else
F_9 ( L_18 ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
if ( V_52 ) {
long long V_53 ;
int V_54 ;
if ( ! V_55 ) {
V_53 = V_37 [ V_8 ] . V_4 - V_56 ;
V_54 = ( V_53 < 0 || V_53 > V_57 ) ;
} else if ( F_11 ( & V_37 [ V_8 ] ) ) {
V_53 = V_37 [ V_8 ] . V_4 ;
V_54 = ( V_53 < 0 || V_53 > V_58 ) ;
} else {
V_53 = V_56 - V_37 [ V_8 ] . V_4 - 1 ;
V_54 = ( V_53 < V_59 || V_53 >= 0 ) ;
}
if ( V_54 ) {
fprintf ( V_1 , L_15
L_45 ,
F_11 ( & V_37 [ V_8 ] ) ? L_46 : L_47 ,
V_37 [ V_8 ] . V_4 ) ;
exit ( V_25 ) ;
}
printf ( L_48 , ( int ) V_53 ) ;
} else if ( ! F_11 ( & V_37 [ V_8 ] ) ) {
if ( V_22 <= V_37 [ V_8 ] . V_4 )
printf ( L_49 ,
V_37 [ V_8 ] . V_4 - V_22 ) ;
else
printf ( L_50 ,
V_22 - V_37 [ V_8 ] . V_4 ) ;
} else {
printf ( L_51 , V_37 [ V_8 ] . V_4 ) ;
}
}
printf ( L_52 ) ;
if ( V_52 ) {
F_9 ( L_19 ) ;
printf ( L_50 , V_22 - V_56 ) ;
printf ( L_52 ) ;
}
F_9 ( L_20 ) ;
printf ( L_53 , V_35 ) ;
printf ( L_52 ) ;
V_50 = malloc ( sizeof( unsigned int ) * ( ( V_35 + 255 ) / 256 ) ) ;
if ( ! V_50 ) {
fprintf ( V_1 , L_15
L_54 ) ;
exit ( V_25 ) ;
}
F_9 ( L_21 ) ;
V_48 = 0 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
if ( ( V_8 & 0xFF ) == 0 )
V_50 [ V_8 >> 8 ] = V_48 ;
printf ( L_55 , V_37 [ V_8 ] . V_24 ) ;
for ( V_47 = 0 ; V_47 < V_37 [ V_8 ] . V_24 ; V_47 ++ )
printf ( L_56 , V_37 [ V_8 ] . V_3 [ V_47 ] ) ;
printf ( L_52 ) ;
V_48 += V_37 [ V_8 ] . V_24 + 1 ;
}
printf ( L_52 ) ;
F_9 ( L_22 ) ;
for ( V_8 = 0 ; V_8 < ( ( V_35 + 255 ) >> 8 ) ; V_8 ++ )
printf ( L_53 , V_50 [ V_8 ] ) ;
printf ( L_52 ) ;
free ( V_50 ) ;
F_9 ( L_23 ) ;
V_48 = 0 ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ ) {
V_49 [ V_8 ] = V_48 ;
F_10 ( V_45 [ V_8 ] , V_46 [ V_8 ] , V_51 ) ;
printf ( L_57 , V_51 ) ;
V_48 += strlen ( V_51 ) + 1 ;
}
printf ( L_52 ) ;
F_9 ( L_24 ) ;
for ( V_8 = 0 ; V_8 < 256 ; V_8 ++ )
printf ( L_58 , V_49 [ V_8 ] ) ;
printf ( L_52 ) ;
}
static void F_13 ( unsigned char * V_60 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_61 [ V_60 [ V_8 ] + ( V_60 [ V_8 + 1 ] << 8 ) ] ++ ;
}
static void F_14 ( unsigned char * V_60 , int V_24 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ )
V_61 [ V_60 [ V_8 ] + ( V_60 [ V_8 + 1 ] << 8 ) ] -- ;
}
static void F_15 ( void )
{
unsigned int V_8 , V_62 ;
V_62 = 0 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
if ( F_7 ( & V_37 [ V_8 ] ) ) {
if ( V_62 != V_8 )
V_37 [ V_62 ] = V_37 [ V_8 ] ;
F_13 ( V_37 [ V_62 ] . V_3 , V_37 [ V_62 ] . V_24 ) ;
V_62 ++ ;
}
}
V_35 = V_62 ;
}
static void * F_16 ( unsigned char * V_2 , int V_24 , unsigned char * V_63 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_24 - 1 ; V_8 ++ ) {
if ( V_2 [ V_8 ] == V_63 [ 0 ] && V_2 [ V_8 + 1 ] == V_63 [ 1 ] )
return & V_2 [ V_8 ] ;
}
return NULL ;
}
static void F_17 ( unsigned char * V_2 , int V_64 )
{
unsigned int V_8 , V_24 , V_65 ;
unsigned char * V_66 , * V_67 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
V_24 = V_37 [ V_8 ] . V_24 ;
V_66 = V_37 [ V_8 ] . V_3 ;
V_67 = F_16 ( V_66 , V_24 , V_2 ) ;
if ( ! V_67 ) continue;
F_14 ( V_37 [ V_8 ] . V_3 , V_24 ) ;
V_65 = V_24 ;
do {
* V_67 = V_64 ;
V_67 ++ ;
V_65 -= ( V_67 - V_66 ) ;
memmove ( V_67 , V_67 + 1 , V_65 ) ;
V_66 = V_67 ;
V_24 -- ;
if ( V_65 < 2 ) break;
V_67 = F_16 ( V_66 , V_65 , V_2 ) ;
} while ( V_67 );
V_37 [ V_8 ] . V_24 = V_24 ;
F_13 ( V_37 [ V_8 ] . V_3 , V_24 ) ;
}
}
static int F_18 ( void )
{
int V_8 , V_68 , V_69 ;
V_69 = - 10000 ;
V_68 = 0 ;
for ( V_8 = 0 ; V_8 < 0x10000 ; V_8 ++ ) {
if ( V_61 [ V_8 ] > V_69 ) {
V_68 = V_8 ;
V_69 = V_61 [ V_8 ] ;
}
}
return V_68 ;
}
static void F_19 ( void )
{
int V_8 , V_68 ;
for ( V_8 = 255 ; V_8 >= 0 ; V_8 -- ) {
if ( ! V_46 [ V_8 ] ) {
V_68 = F_18 () ;
if ( V_61 [ V_68 ] == 0 )
break;
V_46 [ V_8 ] = 2 ;
V_45 [ V_8 ] [ 0 ] = V_68 & 0xFF ;
V_45 [ V_8 ] [ 1 ] = ( V_68 >> 8 ) & 0xFF ;
F_17 ( V_45 [ V_8 ] , V_8 ) ;
}
}
}
static void F_20 ( void )
{
unsigned int V_8 , V_70 , V_42 ;
memset ( V_45 , 0 , sizeof( V_45 ) ) ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ ) {
for ( V_70 = 0 ; V_70 < V_37 [ V_8 ] . V_24 ; V_70 ++ ) {
V_42 = V_37 [ V_8 ] . V_3 [ V_70 ] ;
V_45 [ V_42 ] [ 0 ] = V_42 ;
V_46 [ V_42 ] = 1 ;
}
}
}
static void F_21 ( void )
{
F_15 () ;
F_20 () ;
if ( ! V_35 ) {
fprintf ( V_1 , L_59 ) ;
exit ( 1 ) ;
}
F_19 () ;
}
static int F_22 ( const struct V_15 * V_71 )
{
const char * V_60 = ( char * ) V_71 -> V_3 + 1 ;
int V_24 = V_71 -> V_24 - 1 ;
if ( V_24 < 8 )
return 0 ;
if ( V_60 [ 0 ] != '_' || V_60 [ 1 ] != '_' )
return 0 ;
if ( ! memcmp ( V_60 + 2 , L_60 , 6 ) )
return 1 ;
if ( ! memcmp ( V_60 + 2 , L_61 , 5 ) )
return 1 ;
if ( ! memcmp ( V_60 + 2 , L_62 , 4 ) )
return 1 ;
if ( ! memcmp ( V_60 + V_24 - 6 , L_63 , 6 ) )
return 1 ;
if ( ! memcmp ( V_60 + V_24 - 4 , L_64 , 4 ) )
return 1 ;
return 0 ;
}
static int F_23 ( const char * V_2 )
{
const char * V_72 = V_2 ;
while ( * V_72 == '_' )
V_72 ++ ;
return V_72 - V_2 ;
}
static int F_24 ( const void * V_73 , const void * V_74 )
{
const struct V_15 * V_75 ;
const struct V_15 * V_76 ;
int V_77 , V_78 ;
V_75 = V_73 ;
V_76 = V_74 ;
if ( V_75 -> V_4 > V_76 -> V_4 )
return 1 ;
if ( V_75 -> V_4 < V_76 -> V_4 )
return - 1 ;
V_77 = ( V_75 -> V_3 [ 0 ] == 'w' ) || ( V_75 -> V_3 [ 0 ] == 'W' ) ;
V_78 = ( V_76 -> V_3 [ 0 ] == 'w' ) || ( V_76 -> V_3 [ 0 ] == 'W' ) ;
if ( V_77 != V_78 )
return V_77 - V_78 ;
V_77 = F_22 ( V_75 ) ;
V_78 = F_22 ( V_76 ) ;
if ( V_77 != V_78 )
return V_77 - V_78 ;
V_77 = F_23 ( ( const char * ) V_75 -> V_3 + 1 ) ;
V_78 = F_23 ( ( const char * ) V_76 -> V_3 + 1 ) ;
if ( V_77 != V_78 )
return V_77 - V_78 ;
return V_75 -> V_38 - V_76 -> V_38 ;
}
static void F_25 ( void )
{
qsort ( V_37 , V_35 , sizeof( struct V_15 ) , F_24 ) ;
}
static void F_26 ( void )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ )
if ( F_6 ( & V_37 [ V_8 ] , & V_27 , 1 ) ) {
V_37 [ V_8 ] . V_3 [ 0 ] = 'A' ;
V_37 [ V_8 ] . V_26 = 1 ;
}
}
static void F_27 ( void )
{
unsigned int V_8 ;
V_56 = - 1ULL ;
for ( V_8 = 0 ; V_8 < V_35 ; V_8 ++ )
if ( ! F_11 ( & V_37 [ V_8 ] ) &&
V_37 [ V_8 ] . V_4 < V_56 )
V_56 = V_37 [ V_8 ] . V_4 ;
}
int main ( int V_79 , char * * V_80 )
{
if ( V_79 >= 2 ) {
int V_8 ;
for ( V_8 = 1 ; V_8 < V_79 ; V_8 ++ ) {
if( strcmp ( V_80 [ V_8 ] , L_65 ) == 0 )
V_31 = 1 ;
else if ( strcmp ( V_80 [ V_8 ] , L_66 ) == 0 )
V_55 = 1 ;
else if ( strncmp ( V_80 [ V_8 ] , L_67 , 16 ) == 0 ) {
char * V_81 = & V_80 [ V_8 ] [ 16 ] ;
if ( ( * V_81 == '"' && * ( V_81 + 2 ) == '"' ) || ( * V_81 == '\'' && * ( V_81 + 2 ) == '\'' ) )
V_81 ++ ;
V_21 = * V_81 ;
} else if ( strcmp ( V_80 [ V_8 ] , L_68 ) == 0 )
V_52 = 1 ;
else
F_1 () ;
}
} else if ( V_79 != 1 )
F_1 () ;
F_8 ( V_82 ) ;
if ( V_55 )
F_26 () ;
if ( V_52 )
F_27 () ;
F_25 () ;
F_21 () ;
F_12 () ;
return 0 ;
}
