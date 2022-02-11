int F_1 ( int V_1 , int V_2 , const char * V_3 , ... )
{
int V_4 ;
T_1 args ;
if ( V_2 < V_1 )
return 0 ;
va_start ( args , V_3 ) ;
V_4 = vfprintf ( V_5 , V_3 , args ) ;
va_end ( args ) ;
return V_4 ;
}
char * F_2 ( void )
{
return NULL ;
}
static void F_3 ( char * V_6 , char * * V_7 , const char * V_8 ,
const char * V_9 , T_2 * V_10 )
{
unsigned int V_11 = strlen ( V_9 ) + 1 + strlen ( V_8 ) ;
int V_12 = * V_7 ? strlen ( * V_7 ) : 0 ;
int V_13 = V_10 ? F_4 ( V_10 ) : 0 ;
char * V_14 ;
V_14 = realloc ( * V_7 , V_11 + V_12 + V_13 ) ;
if ( ! V_14 ) {
return;
}
* V_7 = V_14 ;
if ( ! V_12 )
* ( * V_7 ) = 0 ;
else
strcat ( * V_7 , V_8 ) ;
strcat ( * V_7 , V_9 ) ;
if ( V_10 )
strncat ( * V_7 , V_6 + V_10 -> V_15 , V_13 ) ;
}
static void F_5 ( char * V_16 )
{
for (; * V_16 ; V_16 ++ )
* V_16 = tolower ( * V_16 ) ;
}
static void F_6 ( char * V_16 )
{
char * V_17 = V_16 + strlen ( V_16 ) ;
-- V_17 ;
while ( V_17 >= V_16 && isspace ( * V_17 ) )
-- V_17 ;
if ( * V_17 == '.' )
* V_17 = 0 ;
}
static void F_7 ( char * V_6 , T_2 * V_18 )
{
int V_19 ;
for ( V_19 = V_18 -> V_15 ; V_19 < V_18 -> V_20 ; V_19 ++ ) {
if ( V_6 [ V_19 ] == ',' )
V_18 -> V_20 = V_19 ;
}
}
static int F_8 ( char * V_6 , T_2 * V_21 , int V_22 ,
char * * V_23 , T_2 * V_24 )
{
struct V_21 * V_25 ;
T_2 V_18 = * V_24 ;
for ( V_25 = V_26 ; V_25 -> V_21 ; V_25 ++ )
if ( F_9 ( V_6 , V_21 , V_25 -> V_21 ) && V_22 ) {
F_7 ( V_6 , & V_18 ) ;
F_3 ( V_6 , V_23 , L_1 , V_25 -> V_27 , & V_18 ) ;
return 1 ;
}
return 0 ;
}
static struct V_28 * F_10 ( char * V_6 , T_2 * V_24 )
{
T_2 V_18 = * V_24 ;
static bool V_29 ;
int V_19 ;
F_7 ( V_6 , & V_18 ) ;
for ( V_19 = 0 ; V_28 [ V_19 ] . V_30 ; V_19 ++ )
if ( F_9 ( V_6 , & V_18 , V_28 [ V_19 ] . V_30 ) )
return & V_28 [ V_19 ] ;
if ( ! V_29 ) {
V_29 = true ;
F_11 ( L_2 , V_31 ,
F_4 ( V_24 ) , V_6 + V_24 -> V_15 ) ;
}
return NULL ;
}
static const char * F_12 ( struct V_6 * V_32 , char * V_6 , T_2 * V_24 )
{
int V_19 ;
for ( V_19 = 0 ; V_32 [ V_19 ] . V_33 ; V_19 ++ ) {
if ( F_9 ( V_6 , V_24 , V_32 [ V_19 ] . V_33 ) )
return V_32 [ V_19 ] . V_34 ;
}
return NULL ;
}
static char * F_13 ( void )
{
char * V_35 , * V_36 = NULL ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_37 + 1 ; V_19 ++ ) {
int V_38 ;
V_35 = V_36 ;
V_38 = F_14 ( & V_36 , L_3 , V_36 ? : L_4 , V_39 [ V_19 ] ) ;
if ( V_38 < 0 ) {
F_15 ( L_5 , V_31 ) ;
return NULL ;
}
free ( V_35 ) ;
}
for ( V_19 = 0 ; V_19 < ( int ) strlen ( V_36 ) ; V_19 ++ ) {
char V_40 = V_36 [ V_19 ] ;
if ( V_40 == '-' )
V_36 [ V_19 ] = ' ' ;
else if ( V_40 == '.' ) {
V_36 [ V_19 ] = '\0' ;
break;
}
}
return V_36 ;
}
static int F_16 ( int V_1 , char * V_41 )
{
char * V_42 ;
V_1 -= 2 ;
if ( V_1 >= V_43 )
return - V_44 ;
V_42 = F_17 ( V_41 ) ;
if ( ! V_42 ) {
F_15 ( L_6 , V_31 ,
strerror ( V_45 ) , V_41 ) ;
return - V_46 ;
}
free ( V_39 [ V_37 ] ) ;
V_39 [ V_37 ] = V_42 ;
V_37 = V_1 ;
return 0 ;
}
static void F_18 ( T_3 * V_47 , const char * V_48 )
{
fprintf ( V_47 , L_7 , V_48 ) ;
V_49 = 1 ;
}
static int F_19 ( void * V_50 , char * V_51 , char * V_23 ,
char * V_52 , char * V_53 ,
char * V_54 , char * V_55 , char * V_56 )
{
struct V_57 * V_58 = V_50 ;
T_3 * V_59 = V_58 -> V_59 ;
char * V_42 = V_58 -> V_42 ;
fprintf ( V_59 , L_8 ) ;
fprintf ( V_59 , L_9 , V_51 ) ;
fprintf ( V_59 , L_10 , V_23 ) ;
fprintf ( V_59 , L_11 , V_52 ) ;
fprintf ( V_59 , L_12 , V_42 ) ;
if ( V_53 && V_53 [ 0 ] )
fprintf ( V_59 , L_13 , V_53 ) ;
if ( V_54 )
fprintf ( V_59 , L_14 , V_54 ) ;
if ( V_55 )
fprintf ( V_59 , L_15 , V_55 ) ;
if ( V_56 )
fprintf ( V_59 , L_16 , V_56 ) ;
fprintf ( V_59 , L_17 ) ;
return 0 ;
}
static void F_20 ( T_3 * V_59 )
{
fprintf ( V_59 , L_8 ) ;
fprintf ( V_59 , L_18 ) ;
fprintf ( V_59 , L_19 ) ;
fprintf ( V_59 , L_20 ) ;
fprintf ( V_59 , L_17 ) ;
fprintf ( V_59 , L_21 ) ;
V_49 = 0 ;
}
static char * F_21 ( const char * V_51 , char * V_23 )
{
int V_19 ;
for ( V_19 = 0 ; V_60 [ V_19 ] . V_51 ; V_19 ++ )
if ( ! strcasecmp ( V_51 , V_60 [ V_19 ] . V_51 ) )
return ( char * ) V_60 [ V_19 ] . V_23 ;
return V_23 ;
}
int F_22 ( const char * V_61 ,
int (* F_23)( void * V_50 , char * V_51 , char * V_23 , char * V_52 ,
char * V_53 ,
char * V_54 , char * V_55 , char * V_56 ) ,
void * V_50 )
{
int V_62 = - V_63 ;
T_4 V_64 ;
T_2 * V_65 , * V_66 ;
int V_19 , V_67 , V_11 ;
char * V_6 ;
char V_68 [ 128 ] ;
if ( ! V_61 )
return - V_69 ;
V_65 = F_24 ( V_61 , & V_6 , & V_64 , & V_11 ) ;
if ( ! V_65 )
return - V_63 ;
F_25 ( V_65 -> type == V_70 , V_65 , L_22 ) ;
V_66 = V_65 + 1 ;
for ( V_19 = 0 ; V_19 < V_65 -> V_64 ; V_19 ++ ) {
char * V_23 = NULL , * V_52 = NULL , * V_51 = NULL ;
char * V_53 = NULL ;
char * V_71 = NULL ;
char * V_54 = NULL ;
char * V_72 = NULL ;
char * V_56 = NULL ;
char * V_55 = NULL ;
unsigned long long V_73 = 0 ;
struct V_28 * V_74 = NULL ;
T_2 * V_75 = NULL ;
T_2 * V_76 = NULL ;
T_2 * V_77 = V_66 ++ ;
F_25 ( V_77 -> type == V_78 , V_77 , L_23 ) ;
for ( V_67 = 0 ; V_67 < V_77 -> V_64 ; V_67 += 2 ) {
T_2 * V_21 , * V_24 ;
int V_22 ;
V_21 = V_66 + V_67 ;
F_25 ( V_21 -> type == V_79 , V_66 + V_67 ,
L_24 ) ;
V_24 = V_66 + V_67 + 1 ;
F_25 ( V_24 -> type == V_79 , V_66 + V_67 + 1 ,
L_25 ) ;
V_22 = ! F_9 ( V_6 , V_24 , L_26 ) ;
if ( F_8 ( V_6 , V_21 , V_22 , & V_23 , V_24 ) ) {
} else if ( F_9 ( V_6 , V_21 , L_27 ) ) {
char * V_80 = NULL ;
F_3 ( V_6 , & V_80 , L_4 , L_4 , V_24 ) ;
V_73 |= strtoul ( V_80 , NULL , 0 ) ;
free ( V_80 ) ;
} else if ( F_9 ( V_6 , V_21 , L_28 ) ) {
char * V_80 = NULL ;
F_3 ( V_6 , & V_80 , L_4 , L_4 , V_24 ) ;
V_73 |= strtoul ( V_80 , NULL , 0 ) << 21 ;
free ( V_80 ) ;
} else if ( F_9 ( V_6 , V_21 , L_29 ) ) {
F_3 ( V_6 , & V_51 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_30 ) ) {
F_3 ( V_6 , & V_52 , L_4 , L_4 , V_24 ) ;
F_6 ( V_52 ) ;
} else if ( F_9 ( V_6 , V_21 ,
L_31 ) ) {
F_3 ( V_6 , & V_53 , L_4 , L_4 , V_24 ) ;
F_6 ( V_53 ) ;
} else if ( F_9 ( V_6 , V_21 , L_32 ) && V_22 ) {
V_76 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_33 ) && V_22 ) {
V_74 = F_10 ( V_6 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_34 ) ) {
V_75 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_35 ) &&
! F_9 ( V_6 , V_24 , L_36 ) ) {
F_3 ( V_6 , & V_71 , L_37 ,
L_38 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_39 ) && V_22 ) {
F_3 ( V_6 , & V_71 , L_37 ,
L_40 ,
NULL ) ;
} else if ( F_9 ( V_6 , V_21 , L_41 ) ) {
const char * V_81 ;
char * V_16 ;
V_81 = F_12 ( V_82 , V_6 , V_24 ) ;
if ( V_81 ) {
V_54 = F_17 ( V_81 ) ;
} else {
if ( ! V_54 )
V_54 = F_17 ( L_42 ) ;
F_3 ( V_6 , & V_54 , L_4 , L_4 , V_24 ) ;
for ( V_16 = V_54 ; * V_16 ; V_16 ++ )
* V_16 = tolower ( * V_16 ) ;
}
F_3 ( V_6 , & V_52 , L_37 , L_43 , NULL ) ;
F_3 ( V_6 , & V_52 , L_4 , V_54 , NULL ) ;
} else if ( F_9 ( V_6 , V_21 , L_44 ) ) {
F_3 ( V_6 , & V_72 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_45 ) ) {
F_3 ( V_6 , & V_55 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_46 ) ) {
F_3 ( V_6 , & V_56 , L_4 , L_4 , V_24 ) ;
}
}
if ( V_76 && V_52 && ! strstr ( V_52 , L_47 ) ) {
if ( F_9 ( V_6 , V_76 , L_48 ) )
F_3 ( V_6 , & V_71 , L_49 ,
L_50 , NULL ) ;
else
F_3 ( V_6 , & V_71 , L_49 ,
L_51 , NULL ) ;
}
snprintf ( V_68 , sizeof V_68 , L_52 , V_73 ) ;
F_3 ( V_6 , & V_23 , L_1 , V_68 , NULL ) ;
if ( V_52 && V_71 )
F_3 ( V_6 , & V_52 , L_49 , V_71 , NULL ) ;
if ( V_53 && V_71 )
F_3 ( V_6 , & V_53 , L_49 , V_71 , NULL ) ;
if ( V_72 )
F_3 ( V_6 , & V_23 , L_1 , V_72 , NULL ) ;
if ( V_74 != NULL )
F_3 ( V_6 , & V_23 , L_1 , V_74 -> V_83 , V_75 ) ;
F_5 ( V_51 ) ;
V_62 = F_23 ( V_50 , V_51 , F_21 ( V_51 , V_23 ) , V_52 , V_53 ,
V_54 , V_55 , V_56 ) ;
free ( V_23 ) ;
free ( V_52 ) ;
free ( V_51 ) ;
free ( V_53 ) ;
free ( V_71 ) ;
free ( V_54 ) ;
free ( V_72 ) ;
free ( V_56 ) ;
free ( V_55 ) ;
if ( V_62 )
break;
V_66 += V_67 ;
}
F_25 ( V_66 - V_65 == V_11 , V_66 , L_53 ) ;
V_62 = 0 ;
V_84:
F_26 ( V_6 , V_64 , V_65 ) ;
return V_62 ;
}
static char * F_27 ( char * V_85 )
{
unsigned int V_19 ;
int V_38 ;
int V_40 ;
char * V_48 ;
V_38 = F_14 ( & V_48 , L_54 , F_28 ( V_85 ) ) ;
if ( V_38 < 0 ) {
F_15 ( L_55 , V_31 ,
strerror ( V_45 ) , V_85 ) ;
return NULL ;
}
for ( V_19 = 0 ; V_19 < strlen ( V_48 ) ; V_19 ++ ) {
V_40 = V_48 [ V_19 ] ;
if ( V_40 == '-' )
V_48 [ V_19 ] = '_' ;
else if ( V_40 == '.' ) {
V_48 [ V_19 ] = '\0' ;
break;
} else if ( ! isalnum ( V_40 ) && V_40 != '_' ) {
F_11 ( L_56 ,
V_31 , V_40 , F_28 ( V_85 ) ) ;
free ( V_48 ) ;
V_48 = NULL ;
break;
}
}
return V_48 ;
}
static void F_29 ( T_3 * V_59 )
{
fprintf ( V_59 , L_57 ) ;
}
static void F_30 ( T_3 * V_59 )
{
fprintf ( V_59 , L_8 ) ;
fprintf ( V_59 , L_58 ) ;
fprintf ( V_59 , L_59 ) ;
fprintf ( V_59 , L_60 ) ;
fprintf ( V_59 , L_61 ) ;
fprintf ( V_59 , L_17 ) ;
fprintf ( V_59 , L_21 ) ;
}
static int F_31 ( T_3 * V_59 , char * V_86 )
{
int V_38 = 16384 ;
T_3 * V_87 ;
char * V_88 = NULL ;
char * line , * V_89 ;
int V_90 ;
char * V_48 ;
F_15 ( L_62 , V_31 , V_86 ) ;
line = malloc ( V_38 ) ;
if ( ! line )
return - 1 ;
V_87 = fopen ( V_86 , L_63 ) ;
if ( ! V_87 ) {
F_15 ( L_64 , V_31 , strerror ( V_45 ) ,
V_86 ) ;
return - 1 ;
}
F_29 ( V_59 ) ;
V_89 = fgets ( line , V_38 , V_87 ) ;
if ( ! V_89 )
goto V_14;
V_90 = 1 ;
while ( 1 ) {
char * V_91 , * V_92 , * type , * V_85 ;
V_90 ++ ;
V_89 = fgets ( line , V_38 , V_87 ) ;
if ( ! V_89 )
break;
if ( line [ 0 ] == '#' || line [ 0 ] == '\n' )
continue;
if ( line [ strlen ( line ) - 1 ] != '\n' ) {
F_15 ( L_65 ,
V_31 , V_86 , V_90 ) ;
return - 1 ;
}
line [ strlen ( line ) - 1 ] = '\0' ;
V_91 = strtok_r ( V_89 , L_1 , & V_88 ) ;
V_92 = strtok_r ( NULL , L_1 , & V_88 ) ;
V_85 = strtok_r ( NULL , L_1 , & V_88 ) ;
type = strtok_r ( NULL , L_1 , & V_88 ) ;
V_48 = F_27 ( V_85 ) ;
fprintf ( V_59 , L_8 ) ;
fprintf ( V_59 , L_66 , V_91 ) ;
fprintf ( V_59 , L_67 , V_92 ) ;
fprintf ( V_59 , L_68 , type ) ;
fprintf ( V_59 , L_69 , V_48 ) ;
fprintf ( V_59 , L_17 ) ;
}
V_14:
F_30 ( V_59 ) ;
return 0 ;
}
static void F_32 ( const char * V_93 )
{
T_3 * V_59 ;
F_15 ( L_70 , V_31 ) ;
V_59 = fopen ( V_93 , L_71 ) ;
if ( ! V_59 ) {
perror ( L_72 ) ;
F_33 ( 1 ) ;
}
fprintf ( V_59 , L_73 ) ;
F_29 ( V_59 ) ;
F_30 ( V_59 ) ;
fclose ( V_59 ) ;
}
static int F_34 ( void )
{
struct V_94 V_95 ;
if ( F_35 ( V_96 , & V_95 ) == 0 )
return F_36 ( ( int ) V_95 . V_97 / 2 , 512 ) ;
return 512 ;
}
static int F_37 ( const char * V_86 , const struct V_98 * V_99 ,
int V_100 , struct V_101 * V_102 )
{
char * V_48 , * V_41 = ( char * ) V_86 + V_102 -> V_103 ;
int V_104 = V_100 == V_105 ;
int V_106 = V_100 == V_107 ;
int V_1 = V_102 -> V_1 ;
int V_62 = 0 ;
F_38 ( L_74 ,
V_106 ? L_75 : V_104 ? L_76 : L_77 ,
V_1 , V_99 -> V_108 , V_41 , V_86 ) ;
if ( V_1 == 0 )
return 0 ;
if ( V_1 == 1 && V_104 ) {
if ( V_49 )
F_20 ( V_109 ) ;
V_48 = F_27 ( V_41 ) ;
if ( ! V_48 ) {
F_15 ( L_78 , V_31 ,
V_41 ) ;
return - 1 ;
}
F_18 ( V_109 , V_48 ) ;
return 0 ;
}
if ( V_1 == 1 && V_106 ) {
if ( ! strncmp ( V_41 , L_79 , 11 ) ) {
if ( V_110 ) {
F_15 ( L_80 ,
V_31 , V_110 , V_86 ) ;
} else {
V_110 = F_17 ( V_86 ) ;
}
return 0 ;
}
F_15 ( L_81 , V_31 , V_86 ) ;
return 0 ;
}
if ( V_106 ) {
char * V_111 = V_41 + strlen ( V_41 ) - 5 ;
if ( strncmp ( V_111 , L_82 , 5 ) ) {
F_15 ( L_83 , V_31 ,
V_86 ) ;
return 0 ;
}
}
if ( V_1 > 1 && F_16 ( V_1 , V_41 ) )
return - V_46 ;
if ( V_106 ) {
struct V_57 V_50 = {
. V_42 = F_13 () ,
. V_59 = V_109 ,
} ;
V_62 = F_22 ( V_86 , F_19 , & V_50 ) ;
free ( V_50 . V_42 ) ;
}
return V_62 ;
}
int main ( int V_112 , char * V_113 [] )
{
int V_114 ;
int V_115 ;
char V_116 [ V_117 ] ;
const char * V_118 ;
const char * V_93 ;
const char * V_119 ;
V_31 = F_28 ( V_113 [ 0 ] ) ;
if ( V_112 < 4 ) {
F_11 ( L_84 , V_31 ) ;
return 1 ;
}
V_118 = V_113 [ 1 ] ;
V_119 = V_113 [ 2 ] ;
V_93 = V_113 [ 3 ] ;
if ( V_112 > 4 )
V_120 = atoi ( V_113 [ 4 ] ) ;
V_109 = fopen ( V_93 , L_71 ) ;
if ( ! V_109 ) {
F_11 ( L_85 ,
V_31 , V_93 , strerror ( V_45 ) ) ;
return 2 ;
}
fprintf ( V_109 , L_73 ) ;
sprintf ( V_116 , L_86 , V_119 , V_118 ) ;
V_115 = F_34 () ;
V_110 = NULL ;
V_114 = F_39 ( V_116 , F_37 , V_115 , 0 ) ;
if ( V_114 && V_120 ) {
F_15 ( L_87 , V_31 , V_116 ) ;
goto V_121;
} else if ( V_114 ) {
goto V_121;
}
if ( V_49 )
F_20 ( V_109 ) ;
if ( ! V_110 ) {
F_15 ( L_88 , V_31 ) ;
goto V_121;
}
if ( F_31 ( V_109 , V_110 ) ) {
F_15 ( L_89 , V_31 , V_110 ) ;
goto V_121;
}
return 0 ;
V_121:
fclose ( V_109 ) ;
F_32 ( V_93 ) ;
return 0 ;
}
