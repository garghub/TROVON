int F_1 ( T_1 V_1 , const char * V_2 )
{
if ( strlen ( V_2 ) > V_3 )
F_2 ( L_1 , V_2 ) ;
if ( ! V_4 ) {
V_4 = malloc ( sizeof( struct V_5 ) ) ;
if ( V_4 == NULL )
return - V_6 ;
} else {
struct V_5 * V_7 ;
V_7 = realloc ( V_4 , ( V_8 + 1 ) * sizeof( * V_4 ) ) ;
if ( V_7 == NULL )
return - V_6 ;
V_4 = V_7 ;
}
memset ( & V_4 [ V_8 ] , 0 , sizeof( struct V_5 ) ) ;
V_4 [ V_8 ] . V_9 = V_1 ;
strncpy ( V_4 [ V_8 ] . V_2 , V_2 , V_3 - 1 ) ;
V_8 ++ ;
return 0 ;
}
char * F_3 ( T_1 V_1 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
if ( V_4 [ V_10 ] . V_9 == V_1 )
return V_4 [ V_10 ] . V_2 ;
}
return NULL ;
}
void F_4 ( struct V_11 * V_12 , int V_13 )
{
F_5 ( V_13 , V_12 -> V_14 ) ;
}
void F_6 ( struct V_11 * V_12 , int V_13 )
{
F_7 ( V_13 , V_12 -> V_14 ) ;
}
bool F_8 ( const struct V_11 * V_12 , int V_13 )
{
return F_9 ( V_13 , V_12 -> V_14 ) ;
}
static int F_10 ( int V_15 , const void * V_16 , T_2 V_17 )
{
while ( V_17 ) {
int V_18 = F_11 ( V_15 , V_16 , V_17 ) ;
if ( V_18 < 0 )
return - V_19 ;
V_17 -= V_18 ;
V_16 += V_18 ;
}
return 0 ;
}
static int F_12 ( int V_15 , const void * V_20 , T_2 V_21 ,
T_2 V_22 )
{
static const char V_23 [ V_24 ] ;
int V_25 = F_10 ( V_15 , V_20 , V_21 ) ;
if ( ! V_25 )
V_25 = F_10 ( V_15 , V_23 , V_22 - V_21 ) ;
return V_25 ;
}
static int F_13 ( int V_15 , const char * V_26 )
{
T_3 V_27 , V_28 ;
int V_18 ;
V_28 = strlen ( V_26 ) + 1 ;
V_27 = F_14 ( V_28 , V_24 ) ;
V_18 = F_10 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_12 ( V_15 , V_26 , V_28 , V_27 ) ;
}
static char * F_15 ( int V_15 , struct V_11 * V_29 )
{
T_4 V_30 , V_18 ;
T_3 V_27 ;
char * V_16 ;
V_30 = F_16 ( V_15 , & V_27 , sizeof( V_27 ) ) ;
if ( V_30 < ( T_4 ) sizeof( V_27 ) )
return NULL ;
if ( V_29 -> V_31 )
V_27 = F_17 ( V_27 ) ;
V_16 = malloc ( V_27 ) ;
if ( ! V_16 )
return NULL ;
V_18 = F_16 ( V_15 , V_16 , V_27 ) ;
if ( V_18 == ( T_4 ) V_27 ) {
return V_16 ;
}
free ( V_16 ) ;
return NULL ;
}
int
F_18 ( int V_32 , const char * * V_33 )
{
int V_10 ;
V_34 = ( T_3 ) V_32 ;
V_35 = calloc ( V_32 , sizeof( char * ) ) ;
if ( ! V_35 )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_32 ; V_10 ++ )
V_35 [ V_10 ] = V_33 [ V_10 ] ;
return 0 ;
}
static int F_19 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 )
{
return F_20 ( V_15 , & V_38 -> V_39 ) ;
}
static int F_21 ( int V_15 , struct V_11 * T_5 ,
struct V_37 * V_38 V_36 )
{
struct V_40 * V_41 ;
int V_25 ;
V_41 = F_22 ( T_5 , struct V_40 , V_12 ) ;
V_25 = F_23 ( T_5 , V_15 ) ;
if ( V_25 < 0 ) {
F_24 ( L_2 ) ;
return V_25 ;
}
if ( ! V_42 )
F_25 ( V_41 ) ;
return 0 ;
}
static int F_26 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
struct V_43 V_44 ;
int V_18 ;
V_18 = F_27 ( & V_44 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_44 . V_45 ) ;
}
static int F_28 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
struct V_43 V_44 ;
int V_18 ;
V_18 = F_27 ( & V_44 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_44 . V_46 ) ;
}
static int F_29 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
struct V_43 V_44 ;
int V_18 ;
V_18 = F_27 ( & V_44 ) ;
if ( V_18 < 0 )
return - 1 ;
return F_13 ( V_15 , V_44 . V_47 ) ;
}
static int F_30 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
return F_13 ( V_15 , V_48 ) ;
}
static int F_31 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
#ifndef F_32
#define F_32 NULL
#endif
T_6 * V_49 ;
char * V_16 = NULL ;
char * V_50 , * V_51 ;
const char * V_52 = F_32 ;
T_2 V_27 = 0 ;
int V_18 = - 1 ;
if ( ! V_52 )
return - 1 ;
V_49 = fopen ( L_3 , L_4 ) ;
if ( ! V_49 )
return - 1 ;
while ( F_33 ( & V_16 , & V_27 , V_49 ) > 0 ) {
V_18 = strncmp ( V_16 , V_52 , strlen ( V_52 ) ) ;
if ( ! V_18 )
break;
}
if ( V_18 )
goto V_53;
V_50 = V_16 ;
V_51 = strchr ( V_16 , ':' ) ;
if ( V_51 && * ( V_51 + 1 ) == ' ' && * ( V_51 + 2 ) )
V_50 = V_51 + 2 ;
V_51 = strchr ( V_50 , '\n' ) ;
if ( V_51 )
* V_51 = '\0' ;
V_51 = V_50 ;
while ( * V_51 ) {
if ( isspace ( * V_51 ) ) {
char * V_54 = V_51 + 1 ;
char * V_55 = V_54 ;
* V_51 = ' ' ;
while ( * V_55 && isspace ( * V_55 ) )
V_55 ++ ;
if ( V_55 != ( V_51 + 1 ) )
while ( ( * V_54 ++ = * V_55 ++ ) ) ;
}
V_51 ++ ;
}
V_18 = F_13 ( V_15 , V_50 ) ;
V_53:
free ( V_16 ) ;
fclose ( V_49 ) ;
return V_18 ;
}
static int F_34 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
long V_56 ;
T_3 V_57 , V_58 ;
int V_18 ;
V_56 = F_35 ( V_59 ) ;
if ( V_56 < 0 )
return - 1 ;
V_57 = ( T_3 ) ( V_56 & V_60 ) ;
V_56 = F_35 ( V_61 ) ;
if ( V_56 < 0 )
return - 1 ;
V_58 = ( T_3 ) ( V_56 & V_60 ) ;
V_18 = F_10 ( V_15 , & V_57 , sizeof( V_57 ) ) ;
if ( V_18 < 0 )
return V_18 ;
return F_10 ( V_15 , & V_58 , sizeof( V_58 ) ) ;
}
static int F_36 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 )
{
struct V_62 * V_63 ;
T_3 V_64 = 0 , V_65 , V_30 ;
int V_18 ;
F_37 (attr, &evlist->entries, node)
V_64 ++ ;
V_18 = F_10 ( V_15 , & V_64 , sizeof( V_64 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_30 = ( T_3 ) sizeof( V_63 -> V_63 ) ;
V_18 = F_10 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 < 0 )
return V_18 ;
F_37 (attr, &evlist->entries, node) {
V_18 = F_10 ( V_15 , & V_63 -> V_63 , V_30 ) ;
if ( V_18 < 0 )
return V_18 ;
V_65 = V_63 -> V_66 ;
V_18 = F_10 ( V_15 , & V_65 , sizeof( V_65 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , F_38 ( V_63 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_15 , V_63 -> V_1 , V_63 -> V_66 * sizeof( T_1 ) ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_39 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
char V_16 [ V_67 ] ;
char V_68 [ 32 ] ;
T_3 V_10 , V_69 ;
int V_18 ;
sprintf ( V_68 , L_5 , F_40 () ) ;
V_18 = F_41 ( V_68 , V_16 , sizeof( V_16 ) ) ;
if ( V_18 <= 0 )
return - 1 ;
V_16 [ V_18 ] = '\0' ;
V_69 = V_34 + 1 ;
V_18 = F_10 ( V_15 , & V_69 , sizeof( V_69 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_15 , V_16 ) ;
if ( V_18 < 0 )
return V_18 ;
for ( V_10 = 0 ; V_10 < V_34 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_35 [ V_10 ] ) ;
if ( V_18 < 0 )
return V_18 ;
}
return 0 ;
}
static int F_42 ( struct V_70 * V_71 , int V_72 )
{
T_6 * V_73 ;
char V_74 [ V_67 ] ;
char * V_16 = NULL , * V_51 ;
T_2 V_27 = 0 ;
T_3 V_10 = 0 ;
int V_18 = - 1 ;
sprintf ( V_74 , V_75 , V_72 ) ;
V_73 = fopen ( V_74 , L_4 ) ;
if ( ! V_73 )
return - 1 ;
if ( F_33 ( & V_16 , & V_27 , V_73 ) <= 0 )
goto V_53;
fclose ( V_73 ) ;
V_51 = strchr ( V_16 , '\n' ) ;
if ( V_51 )
* V_51 = '\0' ;
for ( V_10 = 0 ; V_10 < V_71 -> V_76 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_71 -> V_77 [ V_10 ] ) )
break;
}
if ( V_10 == V_71 -> V_76 ) {
V_71 -> V_77 [ V_10 ] = V_16 ;
V_71 -> V_76 ++ ;
V_16 = NULL ;
V_27 = 0 ;
}
sprintf ( V_74 , V_78 , V_72 ) ;
V_73 = fopen ( V_74 , L_4 ) ;
if ( ! V_73 )
goto V_53;
if ( F_33 ( & V_16 , & V_27 , V_73 ) <= 0 )
goto V_53;
V_51 = strchr ( V_16 , '\n' ) ;
if ( V_51 )
* V_51 = '\0' ;
for ( V_10 = 0 ; V_10 < V_71 -> V_79 ; V_10 ++ ) {
if ( ! strcmp ( V_16 , V_71 -> V_80 [ V_10 ] ) )
break;
}
if ( V_10 == V_71 -> V_79 ) {
V_71 -> V_80 [ V_10 ] = V_16 ;
V_71 -> V_79 ++ ;
V_16 = NULL ;
}
V_18 = 0 ;
V_53:
if( V_73 )
fclose ( V_73 ) ;
free ( V_16 ) ;
return V_18 ;
}
static void F_43 ( struct V_70 * V_71 )
{
T_3 V_10 ;
if ( ! V_71 )
return;
for ( V_10 = 0 ; V_10 < V_71 -> V_76 ; V_10 ++ )
free ( V_71 -> V_77 [ V_10 ] ) ;
for ( V_10 = 0 ; V_10 < V_71 -> V_79 ; V_10 ++ )
free ( V_71 -> V_80 [ V_10 ] ) ;
free ( V_71 ) ;
}
static struct V_70 * F_44 ( void )
{
struct V_70 * V_71 ;
void * V_81 ;
T_3 V_56 , V_10 ;
T_2 V_30 ;
long V_82 ;
int V_18 = - 1 ;
V_82 = F_35 ( V_59 ) ;
if ( V_82 < 0 )
return NULL ;
V_56 = ( T_3 ) ( V_82 & V_60 ) ;
V_30 = V_56 * sizeof( char * ) ;
V_81 = calloc ( 1 , sizeof( * V_71 ) + 2 * V_30 ) ;
if ( ! V_81 )
return NULL ;
V_71 = V_81 ;
V_81 += sizeof( * V_71 ) ;
V_71 -> V_77 = V_81 ;
V_81 += V_30 ;
V_71 -> V_80 = V_81 ;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_18 = F_42 ( V_71 , V_10 ) ;
if ( V_18 < 0 )
break;
}
if ( V_18 ) {
F_43 ( V_71 ) ;
V_71 = NULL ;
}
return V_71 ;
}
static int F_45 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
struct V_70 * V_71 ;
T_3 V_10 ;
int V_18 ;
V_71 = F_44 () ;
if ( ! V_71 )
return - 1 ;
V_18 = F_10 ( V_15 , & V_71 -> V_76 , sizeof( V_71 -> V_76 ) ) ;
if ( V_18 < 0 )
goto V_53;
for ( V_10 = 0 ; V_10 < V_71 -> V_76 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_71 -> V_77 [ V_10 ] ) ;
if ( V_18 < 0 )
goto V_53;
}
V_18 = F_10 ( V_15 , & V_71 -> V_79 , sizeof( V_71 -> V_79 ) ) ;
if ( V_18 < 0 )
goto V_53;
for ( V_10 = 0 ; V_10 < V_71 -> V_79 ; V_10 ++ ) {
V_18 = F_13 ( V_15 , V_71 -> V_80 [ V_10 ] ) ;
if ( V_18 < 0 )
break;
}
V_53:
F_43 ( V_71 ) ;
return V_18 ;
}
static int F_46 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
char * V_16 = NULL ;
T_6 * V_73 ;
T_2 V_27 = 0 ;
int V_18 = - 1 , V_69 ;
T_7 V_83 ;
V_73 = fopen ( L_6 , L_4 ) ;
if ( ! V_73 )
return - 1 ;
while ( F_33 ( & V_16 , & V_27 , V_73 ) > 0 ) {
V_18 = strncmp ( V_16 , L_7 , 9 ) ;
if ( ! V_18 )
break;
}
if ( ! V_18 ) {
V_69 = sscanf ( V_16 , L_8 V_84 , & V_83 ) ;
if ( V_69 == 1 )
V_18 = F_10 ( V_15 , & V_83 , sizeof( V_83 ) ) ;
}
free ( V_16 ) ;
fclose ( V_73 ) ;
return V_18 ;
}
static int F_47 ( int V_15 , int V_85 )
{
char V_26 [ V_67 ] ;
char V_86 [ 32 ] ;
char * V_16 = NULL , * V_51 ;
T_2 V_27 = 0 ;
T_6 * V_73 ;
T_1 V_87 , V_88 , V_83 ;
int V_18 = - 1 ;
sprintf ( V_26 , L_9 , V_85 ) ;
V_73 = fopen ( V_26 , L_4 ) ;
if ( ! V_73 )
return - 1 ;
while ( F_33 ( & V_16 , & V_27 , V_73 ) > 0 ) {
if ( ! strchr ( V_16 , ':' ) )
continue;
if ( sscanf ( V_16 , L_10 V_84 , V_86 , & V_83 ) != 2 )
goto V_53;
if ( ! strcmp ( V_86 , L_7 ) )
V_87 = V_83 ;
if ( ! strcmp ( V_86 , L_11 ) )
V_88 = V_83 ;
}
fclose ( V_73 ) ;
V_18 = F_10 ( V_15 , & V_87 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_53;
V_18 = F_10 ( V_15 , & V_88 , sizeof( T_1 ) ) ;
if ( V_18 )
goto V_53;
V_18 = - 1 ;
sprintf ( V_26 , L_12 , V_85 ) ;
V_73 = fopen ( V_26 , L_4 ) ;
if ( ! V_73 )
goto V_53;
if ( F_33 ( & V_16 , & V_27 , V_73 ) <= 0 )
goto V_53;
V_51 = strchr ( V_16 , '\n' ) ;
if ( V_51 )
* V_51 = '\0' ;
V_18 = F_13 ( V_15 , V_16 ) ;
V_53:
free ( V_16 ) ;
fclose ( V_73 ) ;
return V_18 ;
}
static int F_48 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
char * V_16 = NULL ;
T_2 V_27 = 0 ;
T_6 * V_73 ;
struct V_89 * V_90 = NULL ;
char * V_91 ;
T_3 V_56 , V_10 , V_92 ;
int V_18 = - 1 ;
V_73 = fopen ( L_13 , L_4 ) ;
if ( ! V_73 )
return - 1 ;
if ( F_33 ( & V_16 , & V_27 , V_73 ) <= 0 )
goto V_53;
V_91 = strchr ( V_16 , '\n' ) ;
if ( V_91 )
* V_91 = '\0' ;
V_90 = F_49 ( V_16 ) ;
if ( ! V_90 )
goto V_53;
V_56 = ( T_3 ) V_90 -> V_56 ;
V_18 = F_10 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 < 0 )
goto V_53;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_92 = ( T_3 ) V_90 -> V_93 [ V_10 ] ;
V_18 = F_10 ( V_15 , & V_92 , sizeof( V_92 ) ) ;
if ( V_18 < 0 )
break;
V_18 = F_47 ( V_15 , V_10 ) ;
if ( V_18 < 0 )
break;
}
V_53:
free ( V_16 ) ;
fclose ( V_73 ) ;
free ( V_90 ) ;
return V_18 ;
}
static int F_50 ( int V_15 , struct V_11 * T_5 V_36 ,
struct V_37 * V_38 V_36 )
{
char V_94 [ 64 ] ;
int V_18 ;
V_18 = F_51 ( V_94 , sizeof( V_94 ) ) ;
if ( ! V_18 )
goto V_95;
return - 1 ;
V_95:
return F_13 ( V_15 , V_94 ) ;
}
static void F_52 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_14 , V_26 ) ;
free ( V_26 ) ;
}
static void F_53 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_15 , V_26 ) ;
free ( V_26 ) ;
}
static void F_54 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_16 , V_26 ) ;
free ( V_26 ) ;
}
static void F_55 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_17 , V_26 ) ;
free ( V_26 ) ;
}
static void F_56 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
T_4 V_18 ;
T_3 V_56 ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
V_56 = - 1 ;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
fprintf ( V_73 , L_18 , V_56 ) ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
V_56 = - 1 ;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
fprintf ( V_73 , L_19 , V_56 ) ;
}
static void F_57 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_20 , V_26 ) ;
free ( V_26 ) ;
}
static void F_58 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
T_4 V_18 ;
char * V_26 ;
T_3 V_56 , V_10 ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
return;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
fprintf ( V_73 , L_21 ) ;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_22 , V_26 ) ;
free ( V_26 ) ;
}
fputc ( '\n' , V_73 ) ;
}
static void F_59 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
T_4 V_18 ;
T_3 V_56 , V_10 ;
char * V_26 ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
return;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_23 , V_26 ) ;
free ( V_26 ) ;
}
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
return;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_24 , V_26 ) ;
free ( V_26 ) ;
}
}
static void F_60 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
struct V_96 V_63 ;
T_7 V_1 ;
void * V_16 = NULL ;
char * V_26 ;
T_3 V_64 , V_30 , V_56 , V_10 , V_92 , V_97 ;
int V_18 ;
V_18 = F_16 ( V_15 , & V_64 , sizeof( V_64 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_64 ) )
goto error;
if ( V_29 -> V_31 )
V_64 = F_17 ( V_64 ) ;
V_18 = F_16 ( V_15 , & V_30 , sizeof( V_30 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_30 ) )
goto error;
if ( V_29 -> V_31 )
V_30 = F_17 ( V_30 ) ;
if ( V_30 < ( T_3 ) sizeof( V_63 ) )
goto error;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_16 = malloc ( V_30 ) ;
if ( ! V_16 )
goto error;
V_97 = sizeof( V_63 ) ;
if ( V_30 < V_97 )
V_97 = V_30 ;
for ( V_10 = 0 ; V_10 < V_64 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , V_16 , V_30 ) ;
if ( V_18 != ( T_4 ) V_30 )
goto error;
if ( V_29 -> V_31 )
F_61 ( V_16 ) ;
memcpy ( & V_63 , V_16 , V_97 ) ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
goto error;
if ( V_29 -> V_31 )
V_56 = F_17 ( V_56 ) ;
V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_25 , V_26 ) ;
free ( V_26 ) ;
fprintf ( V_73 , L_26 V_98
L_27 V_98 L_28 V_98 ,
V_63 . type ,
( T_1 ) V_63 . V_99 ,
( T_1 ) V_63 . V_100 ,
( T_1 ) V_63 . V_101 ) ;
fprintf ( V_73 , L_29 ,
V_63 . V_102 ,
V_63 . V_103 ) ;
if ( V_56 )
fprintf ( V_73 , L_30 ) ;
for ( V_92 = 0 ; V_92 < V_56 ; V_92 ++ ) {
V_18 = F_16 ( V_15 , & V_1 , sizeof( V_1 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_1 ) )
goto error;
if ( V_29 -> V_31 )
V_1 = F_62 ( V_1 ) ;
if ( V_92 )
fputc ( ',' , V_73 ) ;
fprintf ( V_73 , L_31 V_84 , V_1 ) ;
}
if ( V_56 && V_92 == V_56 )
fprintf ( V_73 , L_32 ) ;
fputc ( '\n' , V_73 ) ;
}
free ( V_16 ) ;
return;
error:
fprintf ( V_73 , L_33 ) ;
}
static void F_63 ( struct V_11 * T_5 V_36 , int V_15 , T_6 * V_73 )
{
T_7 V_83 ;
T_4 V_18 ;
V_18 = F_16 ( V_15 , & V_83 , sizeof( V_83 ) ) ;
if ( V_18 != sizeof( V_83 ) )
goto error;
if ( T_5 -> V_31 )
V_83 = F_62 ( V_83 ) ;
fprintf ( V_73 , L_34 V_84 L_35 , V_83 ) ;
return;
error:
fprintf ( V_73 , L_36 ) ;
}
static void F_64 ( struct V_11 * T_5 V_36 , int V_15 , T_6 * V_73 )
{
T_4 V_18 ;
T_3 V_56 , V_91 , V_10 ;
char * V_26 ;
T_7 V_87 , V_88 ;
V_18 = F_16 ( V_15 , & V_56 , sizeof( V_56 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_56 ) )
goto error;
if ( T_5 -> V_31 )
V_56 = F_17 ( V_56 ) ;
for ( V_10 = 0 ; V_10 < V_56 ; V_10 ++ ) {
V_18 = F_16 ( V_15 , & V_91 , sizeof( V_91 ) ) ;
if ( V_18 != ( T_4 ) sizeof( V_91 ) )
goto error;
if ( T_5 -> V_31 )
V_91 = F_17 ( V_91 ) ;
V_18 = F_16 ( V_15 , & V_87 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
V_18 = F_16 ( V_15 , & V_88 , sizeof( T_1 ) ) ;
if ( V_18 != sizeof( T_1 ) )
goto error;
if ( T_5 -> V_31 ) {
V_87 = F_62 ( V_87 ) ;
V_88 = F_62 ( V_88 ) ;
}
fprintf ( V_73 , L_37 V_84 L_38
L_39 V_84 L_35 ,
V_91 ,
V_87 ,
V_88 ) ;
V_26 = F_15 ( V_15 , T_5 ) ;
fprintf ( V_73 , L_40 , V_91 , V_26 ) ;
free ( V_26 ) ;
}
return;
error:
fprintf ( V_73 , L_41 ) ;
}
static void F_65 ( struct V_11 * V_29 , int V_15 , T_6 * V_73 )
{
char * V_26 = F_15 ( V_15 , V_29 ) ;
fprintf ( V_73 , L_42 , V_26 ) ;
free ( V_26 ) ;
}
static int F_66 ( struct V_104 * V_105 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
if ( F_67 ( V_15 , V_105 -> V_109 , V_110 ) == ( V_111 ) - 1 ) {
F_24 ( L_43 V_84 L_44
L_45 , V_105 -> V_109 , V_13 ) ;
return 0 ;
}
if ( V_13 < V_112 || V_13 >= V_113 ) {
F_2 ( L_46 , V_13 ) ;
return - 1 ;
}
if ( ! V_114 [ V_13 ] . V_115 )
return 0 ;
if ( ! V_114 [ V_13 ] . V_116 || V_108 -> V_117 )
V_114 [ V_13 ] . V_115 ( V_29 , V_15 , V_108 -> V_73 ) ;
else
fprintf ( V_108 -> V_73 , L_47 ,
V_114 [ V_13 ] . V_2 ) ;
return 0 ;
}
int F_68 ( struct V_40 * V_41 , T_6 * V_73 , bool V_117 )
{
struct V_107 V_108 ;
struct V_11 * V_12 = & V_41 -> V_12 ;
int V_15 = V_41 -> V_15 ;
V_108 . V_73 = V_73 ;
V_108 . V_117 = V_117 ;
F_69 ( V_12 , V_15 , & V_108 ,
F_66 ) ;
return 0 ;
}
static int F_70 ( struct V_118 * V_119 , T_8 V_120 ,
T_9 V_121 , int V_15 )
{
struct V_122 * V_123 ;
F_71 (pos, head) {
int V_25 ;
struct V_124 V_125 ;
T_2 V_27 ;
if ( ! V_123 -> V_126 )
continue;
V_27 = V_123 -> V_127 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
memcpy ( & V_125 . V_128 , V_123 -> V_128 , sizeof( V_123 -> V_128 ) ) ;
V_125 . V_120 = V_120 ;
V_125 . V_12 . V_121 = V_121 ;
V_125 . V_12 . V_17 = sizeof( V_125 ) + V_27 ;
V_25 = F_10 ( V_15 , & V_125 , sizeof( V_125 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_12 ( V_15 , V_123 -> V_129 ,
V_123 -> V_127 + 1 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_72 ( struct V_47 * V_47 , int V_15 )
{
int V_25 ;
T_9 V_130 = V_131 ,
V_132 = V_133 ;
if ( ! F_73 ( V_47 ) ) {
V_130 = V_134 ;
V_132 = V_135 ;
}
V_25 = F_70 ( & V_47 -> V_136 , V_47 -> V_120 ,
V_130 , V_15 ) ;
if ( V_25 == 0 )
V_25 = F_70 ( & V_47 -> V_137 ,
V_47 -> V_120 , V_132 , V_15 ) ;
return V_25 ;
}
static int F_23 ( struct V_11 * V_12 , int V_15 )
{
struct V_40 * V_41 = F_22 ( V_12 ,
struct V_40 , V_12 ) ;
struct V_138 * V_139 ;
int V_25 = F_72 ( & V_41 -> V_140 , V_15 ) ;
if ( V_25 )
return V_25 ;
for ( V_139 = F_74 ( & V_41 -> V_141 ) ; V_139 ; V_139 = F_75 ( V_139 ) ) {
struct V_47 * V_123 = F_76 ( V_139 , struct V_47 , V_138 ) ;
V_25 = F_72 ( V_123 , V_15 ) ;
if ( V_25 )
break;
}
return V_25 ;
}
int F_77 ( const char * V_142 , const char * V_143 ,
const char * V_2 , bool V_144 )
{
const T_2 V_17 = V_145 ;
char * V_146 , * V_74 = F_78 ( V_17 ) ,
* V_147 = F_78 ( V_17 ) , * V_148 ;
int V_27 , V_25 = - 1 ;
if ( V_144 ) {
if ( V_149 . V_150 ) {
F_24 ( L_48 ) ;
return 0 ;
}
V_146 = ( char * ) V_2 ;
} else
V_146 = F_79 ( V_2 , NULL ) ;
if ( V_146 == NULL || V_74 == NULL || V_147 == NULL )
goto V_151;
V_27 = snprintf ( V_74 , V_17 , L_49 ,
V_143 , V_144 ? L_50 : L_51 , V_146 ) ;
if ( F_80 ( V_74 , 0755 ) )
goto V_151;
snprintf ( V_74 + V_27 , sizeof( V_74 ) - V_27 , L_52 , V_142 ) ;
if ( F_81 ( V_74 , V_152 ) ) {
if ( V_144 ) {
if ( F_82 ( L_53 , V_74 ) )
goto V_151;
} else if ( F_83 ( V_146 , V_74 ) && F_82 ( V_2 , V_74 ) )
goto V_151;
}
V_27 = snprintf ( V_147 , V_17 , L_54 ,
V_143 , V_142 ) ;
if ( F_81 ( V_147 , V_153 ) && F_80 ( V_147 , 0755 ) )
goto V_151;
snprintf ( V_147 + V_27 , V_17 - V_27 , L_52 , V_142 + 2 ) ;
V_148 = V_74 + strlen ( V_143 ) - 5 ;
memcpy ( V_148 , L_55 , 5 ) ;
if ( F_84 ( V_148 , V_147 ) == 0 )
V_25 = 0 ;
V_151:
if ( ! V_144 )
free ( V_146 ) ;
free ( V_74 ) ;
free ( V_147 ) ;
return V_25 ;
}
static int F_85 ( const T_10 * V_128 , T_2 V_154 ,
const char * V_2 , const char * V_143 ,
bool V_144 )
{
char V_142 [ V_155 * 2 + 1 ] ;
F_86 ( V_128 , V_154 , V_142 ) ;
return F_77 ( V_142 , V_143 , V_2 , V_144 ) ;
}
int F_87 ( const char * V_142 , const char * V_143 )
{
const T_2 V_17 = V_145 ;
char * V_74 = F_78 ( V_17 ) ,
* V_147 = F_78 ( V_17 ) ;
int V_25 = - 1 ;
if ( V_74 == NULL || V_147 == NULL )
goto V_151;
snprintf ( V_147 , V_17 , L_56 ,
V_143 , V_142 , V_142 + 2 ) ;
if ( F_81 ( V_147 , V_152 ) )
goto V_151;
if ( F_41 ( V_147 , V_74 , V_17 - 1 ) < 0 )
goto V_151;
if ( F_88 ( V_147 ) )
goto V_151;
snprintf ( V_147 , V_17 , L_56 ,
V_143 , V_142 , V_74 ) ;
if ( F_88 ( V_147 ) )
goto V_151;
V_25 = 0 ;
V_151:
free ( V_74 ) ;
free ( V_147 ) ;
return V_25 ;
}
static int F_89 ( struct V_122 * V_122 , const char * V_143 )
{
bool V_144 = V_122 -> V_156 && V_122 -> V_129 [ 0 ] != '/' ;
return F_85 ( V_122 -> V_128 , sizeof( V_122 -> V_128 ) ,
V_122 -> V_129 , V_143 , V_144 ) ;
}
static int F_90 ( struct V_118 * V_119 , const char * V_143 )
{
struct V_122 * V_123 ;
int V_25 = 0 ;
F_71 (pos, head)
if ( F_89 ( V_123 , V_143 ) )
V_25 = - 1 ;
return V_25 ;
}
static int F_91 ( struct V_47 * V_47 , const char * V_143 )
{
int V_18 = F_90 ( & V_47 -> V_136 , V_143 ) ;
V_18 |= F_90 ( & V_47 -> V_137 , V_143 ) ;
return V_18 ;
}
static int F_25 ( struct V_40 * V_41 )
{
struct V_138 * V_139 ;
int V_18 ;
char V_143 [ V_145 ] ;
snprintf ( V_143 , sizeof( V_143 ) , L_57 , V_157 ) ;
if ( F_92 ( V_143 , 0755 ) != 0 && V_19 != V_158 )
return - 1 ;
V_18 = F_91 ( & V_41 -> V_140 , V_143 ) ;
for ( V_139 = F_74 ( & V_41 -> V_141 ) ; V_139 ; V_139 = F_75 ( V_139 ) ) {
struct V_47 * V_123 = F_76 ( V_139 , struct V_47 , V_138 ) ;
V_18 |= F_91 ( V_123 , V_143 ) ;
}
return V_18 ? - 1 : 0 ;
}
static bool F_93 ( struct V_47 * V_47 , bool V_159 )
{
bool V_18 = F_94 ( & V_47 -> V_136 , V_159 ) ;
V_18 |= F_94 ( & V_47 -> V_137 , V_159 ) ;
return V_18 ;
}
static bool F_95 ( struct V_40 * V_41 , bool V_159 )
{
struct V_138 * V_139 ;
bool V_18 = F_93 ( & V_41 -> V_140 , V_159 ) ;
for ( V_139 = F_74 ( & V_41 -> V_141 ) ; V_139 ; V_139 = F_75 ( V_139 ) ) {
struct V_47 * V_123 = F_76 ( V_139 , struct V_47 , V_138 ) ;
V_18 |= F_93 ( V_123 , V_159 ) ;
}
return V_18 ;
}
static int F_96 ( int V_15 , struct V_11 * T_5 , int type ,
struct V_104 * * V_51 ,
struct V_37 * V_38 )
{
int V_25 ;
int V_18 = 0 ;
if ( F_8 ( T_5 , type ) ) {
( * V_51 ) -> V_109 = F_67 ( V_15 , 0 , V_160 ) ;
V_25 = V_114 [ type ] . F_11 ( V_15 , T_5 , V_38 ) ;
if ( V_25 < 0 ) {
F_24 ( L_58 , type ) ;
F_67 ( V_15 , ( * V_51 ) -> V_109 , V_110 ) ;
return - 1 ;
}
( * V_51 ) -> V_17 = F_67 ( V_15 , 0 , V_160 ) - ( * V_51 ) -> V_109 ;
( * V_51 ) ++ ;
}
return V_18 ;
}
static int F_97 ( struct V_11 * V_12 ,
struct V_37 * V_38 , int V_15 )
{
int V_161 ;
struct V_40 * V_41 ;
struct V_104 * V_162 , * V_51 ;
int V_163 ;
T_1 V_164 ;
int V_25 ;
V_41 = F_22 ( V_12 , struct V_40 , V_12 ) ;
if ( F_8 ( V_12 , V_165 &&
! F_95 ( V_41 , true ) ) )
F_6 ( V_12 , V_165 ) ;
V_161 = F_98 ( V_12 -> V_14 , V_166 ) ;
if ( ! V_161 )
return 0 ;
V_162 = V_51 = calloc ( sizeof( * V_162 ) , V_161 ) ;
if ( V_162 == NULL )
return - V_6 ;
V_163 = sizeof( * V_162 ) * V_161 ;
V_164 = V_12 -> V_167 + V_12 -> V_168 ;
F_67 ( V_15 , V_164 + V_163 , V_110 ) ;
V_25 = F_96 ( V_15 , V_12 , V_112 , & V_51 , V_38 ) ;
if ( V_25 )
goto V_151;
V_25 = F_96 ( V_15 , V_12 , V_165 , & V_51 , V_38 ) ;
if ( V_25 ) {
F_6 ( V_12 , V_165 ) ;
goto V_151;
}
V_25 = F_96 ( V_15 , V_12 , V_169 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_169 ) ;
V_25 = F_96 ( V_15 , V_12 , V_170 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_170 ) ;
V_25 = F_96 ( V_15 , V_12 , V_171 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_171 ) ;
V_25 = F_96 ( V_15 , V_12 , V_172 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_172 ) ;
V_25 = F_96 ( V_15 , V_12 , V_173 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_173 ) ;
V_25 = F_96 ( V_15 , V_12 , V_174 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_174 ) ;
V_25 = F_96 ( V_15 , V_12 , V_175 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_175 ) ;
V_25 = F_96 ( V_15 , V_12 , V_176 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_176 ) ;
V_25 = F_96 ( V_15 , V_12 , V_177 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_177 ) ;
V_25 = F_96 ( V_15 , V_12 , V_178 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_178 ) ;
V_25 = F_96 ( V_15 , V_12 , V_179 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_179 ) ;
V_25 = F_96 ( V_15 , V_12 , V_180 , & V_51 , V_38 ) ;
if ( V_25 )
F_6 ( V_12 , V_180 ) ;
F_67 ( V_15 , V_164 , V_110 ) ;
V_25 = F_10 ( V_15 , V_162 , V_163 ) ;
if ( V_25 < 0 )
F_24 ( L_59 ) ;
V_151:
free ( V_162 ) ;
return V_25 ;
}
int F_99 ( int V_15 )
{
struct V_181 V_182 ;
int V_25 ;
V_182 = (struct V_181 ) {
. V_183 = V_184 ,
. V_17 = sizeof( V_182 ) ,
} ;
V_25 = F_10 ( V_15 , & V_182 , sizeof( V_182 ) ) ;
if ( V_25 < 0 ) {
F_24 ( L_60 ) ;
return V_25 ;
}
return 0 ;
}
int F_100 ( struct V_40 * V_41 ,
struct V_37 * V_38 ,
int V_15 , bool V_185 )
{
struct V_186 V_182 ;
struct V_187 V_188 ;
struct V_11 * V_12 = & V_41 -> V_12 ;
struct V_62 * V_63 , * V_189 = NULL ;
int V_25 ;
F_67 ( V_15 , sizeof( V_182 ) , V_110 ) ;
if ( V_41 -> V_38 != V_38 )
V_189 = F_101 ( V_41 -> V_38 -> V_39 . V_190 , struct V_62 , V_85 ) ;
F_37 (attr, &evlist->entries, node) {
V_63 -> V_191 = F_67 ( V_15 , 0 , V_160 ) ;
V_25 = F_10 ( V_15 , V_63 -> V_1 , V_63 -> V_66 * sizeof( T_1 ) ) ;
if ( V_25 < 0 ) {
V_192:
F_24 ( L_61 ) ;
return V_25 ;
}
if ( V_41 -> V_38 != V_38 ) {
V_25 = F_10 ( V_15 , V_189 -> V_1 , V_189 -> V_66 * sizeof( T_1 ) ) ;
if ( V_25 < 0 )
goto V_192;
V_63 -> V_66 += V_189 -> V_66 ;
V_189 = F_101 ( V_189 -> V_85 . V_190 , struct V_62 , V_85 ) ;
}
}
V_12 -> V_193 = F_67 ( V_15 , 0 , V_160 ) ;
F_37 (attr, &evlist->entries, node) {
V_188 = (struct V_187 ) {
. V_63 = V_63 -> V_63 ,
. V_66 = {
. V_109 = V_63 -> V_191 ,
. V_17 = V_63 -> V_66 * sizeof( T_1 ) ,
}
} ;
V_25 = F_10 ( V_15 , & V_188 , sizeof( V_188 ) ) ;
if ( V_25 < 0 ) {
F_24 ( L_62 ) ;
return V_25 ;
}
}
V_12 -> V_194 = F_67 ( V_15 , 0 , V_160 ) ;
V_12 -> V_195 = V_8 * sizeof( struct V_5 ) ;
if ( V_4 ) {
V_25 = F_10 ( V_15 , V_4 , V_12 -> V_195 ) ;
if ( V_25 < 0 ) {
F_24 ( L_63 ) ;
return V_25 ;
}
}
V_12 -> V_167 = F_67 ( V_15 , 0 , V_160 ) ;
if ( V_185 ) {
V_25 = F_97 ( V_12 , V_38 , V_15 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_182 = (struct V_186 ) {
. V_183 = V_184 ,
. V_17 = sizeof( V_182 ) ,
. V_196 = sizeof( V_188 ) ,
. V_197 = {
. V_109 = V_12 -> V_193 ,
. V_17 = V_38 -> V_198 * sizeof( V_188 ) ,
} ,
. V_106 = {
. V_109 = V_12 -> V_167 ,
. V_17 = V_12 -> V_168 ,
} ,
. V_199 = {
. V_109 = V_12 -> V_194 ,
. V_17 = V_12 -> V_195 ,
} ,
} ;
memcpy ( & V_182 . V_14 , & V_12 -> V_14 , sizeof( V_12 -> V_14 ) ) ;
F_67 ( V_15 , 0 , V_110 ) ;
V_25 = F_10 ( V_15 , & V_182 , sizeof( V_182 ) ) ;
if ( V_25 < 0 ) {
F_24 ( L_61 ) ;
return V_25 ;
}
F_67 ( V_15 , V_12 -> V_167 + V_12 -> V_168 , V_110 ) ;
V_12 -> V_200 = 1 ;
return 0 ;
}
static int F_102 ( struct V_11 * V_12 ,
int V_15 , void * V_16 , T_2 V_17 )
{
if ( F_103 ( V_15 , V_16 , V_17 ) <= 0 )
return - 1 ;
if ( V_12 -> V_31 )
F_104 ( V_16 , V_17 ) ;
return 0 ;
}
int F_69 ( struct V_11 * V_12 , int V_15 ,
void * V_106 ,
int (* F_105)( struct V_104 * V_105 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_106 ) )
{
struct V_104 * V_162 ;
int V_161 ;
int V_163 ;
int V_201 = 0 ;
int V_25 = - 1 , V_13 = 1 ;
V_161 = F_98 ( V_12 -> V_14 , V_166 ) ;
if ( ! V_161 )
return 0 ;
V_162 = calloc ( sizeof( * V_162 ) , V_161 ) ;
if ( ! V_162 )
return - 1 ;
V_163 = sizeof( * V_162 ) * V_161 ;
F_67 ( V_15 , V_12 -> V_167 + V_12 -> V_168 , V_110 ) ;
if ( F_102 ( V_12 , V_15 , V_162 , V_163 ) )
goto V_151;
V_25 = 0 ;
while ( V_201 < V_161 && V_13 < V_113 ) {
if ( F_8 ( V_12 , V_13 ) ) {
struct V_104 * V_202 = & V_162 [ V_201 ++ ] ;
V_25 = F_105 ( V_202 , V_12 , V_13 , V_15 , V_106 ) ;
if ( V_25 < 0 )
break;
}
++ V_13 ;
}
V_151:
free ( V_162 ) ;
return V_25 ;
}
int F_106 ( struct V_186 * V_12 ,
struct V_11 * V_29 , int V_15 )
{
F_67 ( V_15 , 0 , V_110 ) ;
if ( F_103 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_183 , V_203 , sizeof( V_12 -> V_183 ) ) )
return - 1 ;
if ( V_12 -> V_196 != sizeof( struct V_187 ) ) {
T_1 V_196 = F_62 ( V_12 -> V_196 ) ;
if ( V_196 != sizeof( struct V_187 ) )
return - 1 ;
F_104 ( V_12 , F_107 ( struct V_186 ,
V_14 ) ) ;
V_29 -> V_31 = true ;
}
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
if ( V_12 -> V_17 == F_107 ( F_108 ( * V_12 ) , V_14 ) )
F_109 ( V_12 -> V_14 , V_166 ) ;
else
return - 1 ;
} else if ( V_29 -> V_31 ) {
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < F_110 ( V_166 ) ; ++ V_10 )
V_12 -> V_14 [ V_10 ] = F_62 ( V_12 -> V_14 [ V_10 ] ) ;
if ( ! F_9 ( V_169 , V_12 -> V_14 ) ) {
for ( V_10 = 0 ; V_10 < F_110 ( V_166 ) ; ++ V_10 ) {
V_12 -> V_14 [ V_10 ] = F_62 ( V_12 -> V_14 [ V_10 ] ) ;
V_12 -> V_14 [ V_10 ] = F_17 ( V_12 -> V_14 [ V_10 ] ) ;
}
}
if ( ! F_9 ( V_169 , V_12 -> V_14 ) ) {
F_109 ( V_12 -> V_14 , V_166 ) ;
F_5 ( V_165 , V_12 -> V_14 ) ;
}
}
memcpy ( & V_29 -> V_14 , & V_12 -> V_14 ,
sizeof( V_29 -> V_14 ) ) ;
V_29 -> V_194 = V_12 -> V_199 . V_109 ;
V_29 -> V_195 = V_12 -> V_199 . V_17 ;
V_29 -> V_167 = V_12 -> V_106 . V_109 ;
V_29 -> V_168 = V_12 -> V_106 . V_17 ;
return 0 ;
}
static int F_111 ( struct V_124 * V_204 ,
char * V_74 ,
struct V_40 * V_41 )
{
int V_25 = - 1 ;
struct V_118 * V_119 ;
struct V_47 * V_47 ;
T_9 V_121 ;
struct V_122 * V_122 ;
enum V_205 V_206 ;
V_47 = F_112 ( V_41 , V_204 -> V_120 ) ;
if ( ! V_47 )
goto V_207;
V_121 = V_204 -> V_12 . V_121 & V_208 ;
switch ( V_121 ) {
case V_131 :
V_206 = V_209 ;
V_119 = & V_47 -> V_136 ;
break;
case V_134 :
V_206 = V_210 ;
V_119 = & V_47 -> V_136 ;
break;
case V_133 :
case V_135 :
V_206 = V_211 ;
V_119 = & V_47 -> V_137 ;
break;
default:
goto V_207;
}
V_122 = F_113 ( V_119 , V_74 ) ;
if ( V_122 != NULL ) {
char V_142 [ V_155 * 2 + 1 ] ;
F_114 ( V_122 , & V_204 -> V_128 ) ;
if ( V_74 [ 0 ] == '[' )
V_122 -> V_156 = V_206 ;
F_86 ( V_122 -> V_128 , sizeof( V_122 -> V_128 ) ,
V_142 ) ;
F_24 ( L_64 ,
V_122 -> V_129 , V_142 ) ;
}
V_25 = 0 ;
V_207:
return V_25 ;
}
static int F_115 ( struct V_11 * V_12 ,
int V_212 , T_1 V_109 , T_1 V_17 )
{
struct V_40 * V_41 = F_22 ( V_12 , struct V_40 , V_12 ) ;
struct {
struct V_213 V_12 ;
T_10 V_128 [ F_14 ( V_155 , sizeof( T_1 ) ) ] ;
char V_74 [ 0 ] ;
} V_214 ;
struct V_124 V_204 ;
char V_74 [ V_145 ] ;
T_1 V_215 = V_109 + V_17 ;
while ( V_109 < V_215 ) {
T_4 V_27 ;
if ( F_16 ( V_212 , & V_214 , sizeof( V_214 ) ) != sizeof( V_214 ) )
return - 1 ;
if ( V_12 -> V_31 )
F_116 ( & V_214 . V_12 ) ;
V_27 = V_214 . V_12 . V_17 - sizeof( V_214 ) ;
if ( F_16 ( V_212 , V_74 , V_27 ) != V_27 )
return - 1 ;
V_204 . V_12 = V_214 . V_12 ;
V_204 . V_120 = V_216 ;
if ( V_204 . V_12 . V_121 == V_135 ||
V_204 . V_12 . V_121 == V_134 )
V_204 . V_120 = V_217 ;
memcpy ( V_204 . V_128 , V_214 . V_128 , sizeof( V_204 . V_128 ) ) ;
F_111 ( & V_204 , V_74 , V_41 ) ;
V_109 += V_204 . V_12 . V_17 ;
}
return 0 ;
}
static int F_117 ( struct V_11 * V_12 ,
int V_212 , T_1 V_109 , T_1 V_17 )
{
struct V_40 * V_41 = F_22 ( V_12 , struct V_40 , V_12 ) ;
struct V_124 V_204 ;
char V_74 [ V_145 ] ;
T_1 V_215 = V_109 + V_17 , V_218 = V_109 ;
int V_25 = - 1 ;
while ( V_109 < V_215 ) {
T_4 V_27 ;
if ( F_16 ( V_212 , & V_204 , sizeof( V_204 ) ) != sizeof( V_204 ) )
goto V_207;
if ( V_12 -> V_31 )
F_116 ( & V_204 . V_12 ) ;
V_27 = V_204 . V_12 . V_17 - sizeof( V_204 ) ;
if ( F_16 ( V_212 , V_74 , V_27 ) != V_27 )
goto V_207;
if ( memcmp ( V_74 , L_65 , 13 ) == 0 ) {
if ( F_67 ( V_212 , V_218 , V_110 ) == ( V_111 ) - 1 )
return - 1 ;
return F_115 ( V_12 , V_212 , V_109 , V_17 ) ;
}
F_111 ( & V_204 , V_74 , V_41 ) ;
V_109 += V_204 . V_12 . V_17 ;
}
V_25 = 0 ;
V_207:
return V_25 ;
}
static int F_118 ( struct V_104 * V_105 ,
struct V_11 * V_29 ,
int V_13 , int V_15 , void * V_106 V_36 )
{
if ( F_67 ( V_15 , V_105 -> V_109 , V_110 ) == ( V_111 ) - 1 ) {
F_24 ( L_43 V_84 L_44
L_45 , V_105 -> V_109 , V_13 ) ;
return 0 ;
}
switch ( V_13 ) {
case V_112 :
F_119 ( V_15 , false ) ;
break;
case V_165 :
if ( F_117 ( V_29 , V_15 , V_105 -> V_109 , V_105 -> V_17 ) )
F_24 ( L_66 ) ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
break;
default:
F_24 ( L_67 , V_13 ) ;
}
return 0 ;
}
static int F_120 ( struct V_181 * V_12 ,
struct V_11 * V_29 , int V_15 ,
bool V_219 )
{
if ( F_103 ( V_15 , V_12 , sizeof( * V_12 ) ) <= 0 ||
memcmp ( & V_12 -> V_183 , V_203 , sizeof( V_12 -> V_183 ) ) )
return - 1 ;
if ( V_219 && F_10 ( V_220 , V_12 , sizeof( * V_12 ) ) < 0 )
return - 1 ;
if ( V_12 -> V_17 != sizeof( * V_12 ) ) {
T_1 V_17 = F_62 ( V_12 -> V_17 ) ;
if ( V_17 != sizeof( * V_12 ) )
return - 1 ;
V_29 -> V_31 = true ;
}
return 0 ;
}
static int F_121 ( struct V_40 * V_41 , int V_15 )
{
struct V_11 * V_12 = & V_41 -> V_12 ;
struct V_181 V_182 ;
if ( F_120 ( & V_182 , V_12 , V_15 ,
V_41 -> V_219 ) < 0 ) {
F_24 ( L_68 ) ;
return - V_221 ;
}
V_41 -> V_15 = V_15 ;
return 0 ;
}
int F_122 ( struct V_40 * V_41 , int V_15 )
{
struct V_11 * V_12 = & V_41 -> V_12 ;
struct V_186 V_182 ;
struct V_187 V_188 ;
T_1 V_222 ;
int V_223 , V_224 , V_10 , V_92 ;
V_41 -> V_38 = F_123 ( NULL , NULL ) ;
if ( V_41 -> V_38 == NULL )
return - V_6 ;
if ( V_41 -> V_225 )
return F_121 ( V_41 , V_15 ) ;
if ( F_106 ( & V_182 , V_12 , V_15 ) < 0 ) {
F_24 ( L_68 ) ;
return - V_221 ;
}
V_223 = V_182 . V_197 . V_17 / sizeof( V_188 ) ;
F_67 ( V_15 , V_182 . V_197 . V_109 , V_110 ) ;
for ( V_10 = 0 ; V_10 < V_223 ; V_10 ++ ) {
struct V_62 * V_226 ;
V_111 V_227 ;
if ( F_103 ( V_15 , & V_188 , sizeof( V_188 ) ) <= 0 )
goto V_228;
if ( V_12 -> V_31 )
F_61 ( & V_188 . V_63 ) ;
V_227 = F_67 ( V_15 , 0 , V_160 ) ;
V_226 = F_124 ( & V_188 . V_63 , V_10 ) ;
if ( V_226 == NULL )
goto V_229;
F_125 ( V_41 -> V_38 , V_226 ) ;
V_224 = V_188 . V_66 . V_17 / sizeof( T_1 ) ;
if ( F_126 ( V_226 , 1 , V_224 ) )
goto V_229;
F_67 ( V_15 , V_188 . V_66 . V_109 , V_110 ) ;
for ( V_92 = 0 ; V_92 < V_224 ; V_92 ++ ) {
if ( F_102 ( V_12 , V_15 , & V_222 , sizeof( V_222 ) ) )
goto V_228;
F_127 ( V_41 -> V_38 , V_226 , 0 , V_92 , V_222 ) ;
}
F_67 ( V_15 , V_227 , V_110 ) ;
}
if ( V_182 . V_199 . V_17 ) {
F_67 ( V_15 , V_182 . V_199 . V_109 , V_110 ) ;
V_4 = malloc ( V_182 . V_199 . V_17 ) ;
if ( V_4 == NULL )
return - V_6 ;
if ( F_102 ( V_12 , V_15 , V_4 ,
V_182 . V_199 . V_17 ) )
goto V_228;
V_8 = V_182 . V_199 . V_17 / sizeof( struct V_5 ) ;
}
F_69 ( V_12 , V_15 , NULL ,
F_118 ) ;
F_67 ( V_15 , V_12 -> V_167 , V_110 ) ;
V_12 -> V_200 = 1 ;
return 0 ;
V_228:
return - V_19 ;
V_229:
F_128 ( V_41 -> V_38 ) ;
V_41 -> V_38 = NULL ;
return - V_6 ;
}
int F_129 ( struct V_96 * V_63 , T_9 V_66 , T_1 * V_1 ,
T_11 F_105 ,
struct V_40 * V_41 )
{
union V_230 * V_231 ;
T_2 V_17 ;
int V_25 ;
V_17 = sizeof( struct V_96 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_17 += sizeof( struct V_213 ) ;
V_17 += V_66 * sizeof( T_1 ) ;
V_231 = malloc ( V_17 ) ;
if ( V_231 == NULL )
return - V_6 ;
V_231 -> V_63 . V_63 = * V_63 ;
memcpy ( V_231 -> V_63 . V_1 , V_1 , V_66 * sizeof( T_1 ) ) ;
V_231 -> V_63 . V_12 . type = V_232 ;
V_231 -> V_63 . V_12 . V_17 = V_17 ;
V_25 = F_105 ( V_231 , NULL , V_41 ) ;
free ( V_231 ) ;
return V_25 ;
}
int F_130 ( struct V_40 * V_41 ,
T_11 F_105 )
{
struct V_62 * V_63 ;
int V_25 = 0 ;
F_37 (attr, &session->evlist->entries, node) {
V_25 = F_129 ( & V_63 -> V_63 , V_63 -> V_66 ,
V_63 -> V_1 , F_105 , V_41 ) ;
if ( V_25 ) {
F_24 ( L_69 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_131 ( union V_230 * V_233 ,
struct V_40 * V_41 )
{
unsigned int V_10 , V_66 , V_234 ;
struct V_62 * V_226 ;
if ( V_41 -> V_38 == NULL ) {
V_41 -> V_38 = F_123 ( NULL , NULL ) ;
if ( V_41 -> V_38 == NULL )
return - V_6 ;
}
V_226 = F_124 ( & V_233 -> V_63 . V_63 ,
V_41 -> V_38 -> V_198 ) ;
if ( V_226 == NULL )
return - V_6 ;
F_125 ( V_41 -> V_38 , V_226 ) ;
V_66 = V_233 -> V_12 . V_17 ;
V_66 -= ( void * ) & V_233 -> V_63 . V_1 - ( void * ) V_233 ;
V_234 = V_66 / sizeof( T_1 ) ;
if ( F_126 ( V_226 , 1 , V_234 ) )
return - V_6 ;
for ( V_10 = 0 ; V_10 < V_234 ; V_10 ++ ) {
F_127 ( V_41 -> V_38 , V_226 , 0 , V_10 ,
V_233 -> V_63 . V_1 [ V_10 ] ) ;
}
F_132 ( V_41 ) ;
return 0 ;
}
int F_133 ( T_1 V_9 , char * V_2 ,
T_11 F_105 ,
struct V_40 * V_41 )
{
union V_230 V_231 ;
T_2 V_17 = 0 ;
int V_25 = 0 ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . V_235 . V_235 . V_9 = V_9 ;
memset ( V_231 . V_235 . V_235 . V_2 , 0 , V_3 ) ;
strncpy ( V_231 . V_235 . V_235 . V_2 , V_2 , V_3 - 1 ) ;
V_231 . V_235 . V_12 . type = V_236 ;
V_17 = strlen ( V_2 ) ;
V_17 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_231 . V_235 . V_12 . V_17 = sizeof( V_231 . V_235 ) -
( sizeof( V_231 . V_235 . V_235 . V_2 ) - V_17 ) ;
V_25 = F_105 ( & V_231 , NULL , V_41 ) ;
return V_25 ;
}
int F_134 ( T_11 F_105 ,
struct V_40 * V_41 )
{
struct V_5 * type ;
int V_10 , V_25 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
type = & V_4 [ V_10 ] ;
V_25 = F_133 ( type -> V_9 ,
type -> V_2 , F_105 ,
V_41 ) ;
if ( V_25 ) {
F_24 ( L_70 ) ;
return V_25 ;
}
}
return V_25 ;
}
int F_135 ( union V_230 * V_233 ,
struct V_40 * V_41 V_237 )
{
if ( F_1 ( V_233 -> V_235 . V_235 . V_9 ,
V_233 -> V_235 . V_235 . V_2 ) < 0 )
return - V_6 ;
return 0 ;
}
int F_136 ( int V_15 , struct V_37 * V_38 ,
T_11 F_105 ,
struct V_40 * V_41 V_237 )
{
union V_230 V_231 ;
struct V_238 * V_239 ;
T_4 V_17 = 0 , V_240 = 0 , V_241 ;
int V_25 V_36 = 0 ;
V_239 = F_137 ( & V_38 -> V_39 , V_15 , true ) ;
if ( ! V_239 )
return - 1 ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_231 . V_238 . V_12 . type = V_242 ;
V_17 = V_239 -> V_17 ;
V_240 = F_14 ( V_17 , sizeof( T_1 ) ) ;
V_241 = V_240 - V_17 ;
V_231 . V_238 . V_12 . V_17 = sizeof( V_231 . V_238 ) ;
V_231 . V_238 . V_17 = V_240 ;
F_105 ( & V_231 , NULL , V_41 ) ;
F_138 ( V_239 ) ;
F_12 ( V_15 , NULL , 0 , V_241 ) ;
return V_240 ;
}
int F_139 ( union V_230 * V_233 ,
struct V_40 * V_41 )
{
T_4 V_243 , V_241 , V_17 = V_233 -> V_238 . V_17 ;
V_111 V_109 = F_67 ( V_41 -> V_15 , 0 , V_160 ) ;
char V_16 [ V_244 ] ;
F_67 ( V_41 -> V_15 , V_109 + sizeof( struct V_245 ) ,
V_110 ) ;
V_243 = F_119 ( V_41 -> V_15 , V_41 -> V_219 ) ;
V_241 = F_14 ( V_243 , sizeof( T_1 ) ) - V_243 ;
if ( F_16 ( V_41 -> V_15 , V_16 , V_241 ) < 0 )
F_140 ( L_71 ) ;
if ( V_41 -> V_219 ) {
int V_246 = F_11 ( V_220 , V_16 , V_241 ) ;
if ( V_246 <= 0 || V_246 != V_241 )
F_140 ( L_72 ) ;
}
if ( V_243 + V_241 != V_17 )
F_140 ( L_73 ) ;
return V_243 + V_241 ;
}
int F_141 ( struct V_122 * V_123 , T_9 V_121 ,
T_11 F_105 ,
struct V_47 * V_47 ,
struct V_40 * V_41 )
{
union V_230 V_231 ;
T_2 V_27 ;
int V_25 = 0 ;
if ( ! V_123 -> V_126 )
return V_25 ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
V_27 = V_123 -> V_127 + 1 ;
V_27 = F_14 ( V_27 , V_24 ) ;
memcpy ( & V_231 . V_128 . V_128 , V_123 -> V_128 , sizeof( V_123 -> V_128 ) ) ;
V_231 . V_128 . V_12 . type = V_247 ;
V_231 . V_128 . V_12 . V_121 = V_121 ;
V_231 . V_128 . V_120 = V_47 -> V_120 ;
V_231 . V_128 . V_12 . V_17 = sizeof( V_231 . V_128 ) + V_27 ;
memcpy ( & V_231 . V_128 . V_74 , V_123 -> V_129 , V_123 -> V_127 ) ;
V_25 = F_105 ( & V_231 , NULL , V_41 ) ;
return V_25 ;
}
int F_142 ( union V_230 * V_233 ,
struct V_40 * V_41 )
{
F_111 ( & V_233 -> V_128 ,
V_233 -> V_128 . V_74 ,
V_41 ) ;
return 0 ;
}
void F_143 ( void )
{
V_42 = true ;
}
