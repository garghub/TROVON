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
char * V_54 , char * V_55 , char * V_56 ,
char * V_57 ,
char * V_58 )
{
struct V_59 * V_60 = V_50 ;
T_3 * V_61 = V_60 -> V_61 ;
char * V_42 = V_60 -> V_42 ;
fprintf ( V_61 , L_8 ) ;
fprintf ( V_61 , L_9 , V_51 ) ;
fprintf ( V_61 , L_10 , V_23 ) ;
fprintf ( V_61 , L_11 , V_52 ) ;
fprintf ( V_61 , L_12 , V_42 ) ;
if ( V_53 && V_53 [ 0 ] )
fprintf ( V_61 , L_13 , V_53 ) ;
if ( V_54 )
fprintf ( V_61 , L_14 , V_54 ) ;
if ( V_55 )
fprintf ( V_61 , L_15 , V_55 ) ;
if ( V_56 )
fprintf ( V_61 , L_16 , V_56 ) ;
if ( V_57 )
fprintf ( V_61 , L_17 , V_57 ) ;
if ( V_58 )
fprintf ( V_61 , L_18 , V_58 ) ;
fprintf ( V_61 , L_19 ) ;
return 0 ;
}
static void F_20 ( T_3 * V_61 )
{
fprintf ( V_61 , L_8 ) ;
fprintf ( V_61 , L_20 ) ;
fprintf ( V_61 , L_21 ) ;
fprintf ( V_61 , L_22 ) ;
fprintf ( V_61 , L_19 ) ;
fprintf ( V_61 , L_23 ) ;
V_49 = 0 ;
}
static char * F_21 ( const char * V_51 , char * V_23 )
{
int V_19 ;
for ( V_19 = 0 ; V_62 [ V_19 ] . V_51 ; V_19 ++ )
if ( ! strcasecmp ( V_51 , V_62 [ V_19 ] . V_51 ) )
return ( char * ) V_62 [ V_19 ] . V_23 ;
return V_23 ;
}
int F_22 ( const char * V_63 ,
int (* F_23)( void * V_50 , char * V_51 , char * V_23 , char * V_52 ,
char * V_53 ,
char * V_54 , char * V_55 , char * V_56 ,
char * V_57 ,
char * V_58 ) ,
void * V_50 )
{
int V_64 = - V_65 ;
T_4 V_66 ;
T_2 * V_67 , * V_68 ;
int V_19 , V_69 , V_11 ;
char * V_6 ;
char V_70 [ 128 ] ;
if ( ! V_63 )
return - V_71 ;
V_67 = F_24 ( V_63 , & V_6 , & V_66 , & V_11 ) ;
if ( ! V_67 )
return - V_65 ;
F_25 ( V_67 -> type == V_72 , V_67 , L_24 ) ;
V_68 = V_67 + 1 ;
for ( V_19 = 0 ; V_19 < V_67 -> V_66 ; V_19 ++ ) {
char * V_23 = NULL , * V_52 = NULL , * V_51 = NULL ;
char * V_53 = NULL ;
char * V_73 = NULL ;
char * V_54 = NULL ;
char * V_74 = NULL ;
char * V_56 = NULL ;
char * V_55 = NULL ;
char * V_57 = NULL ;
char * V_58 = NULL ;
unsigned long long V_75 = 0 ;
struct V_28 * V_76 = NULL ;
T_2 * V_77 = NULL ;
T_2 * V_78 = NULL ;
T_2 * V_79 = V_68 ++ ;
F_25 ( V_79 -> type == V_80 , V_79 , L_25 ) ;
for ( V_69 = 0 ; V_69 < V_79 -> V_66 ; V_69 += 2 ) {
T_2 * V_21 , * V_24 ;
int V_22 ;
char * V_16 ;
V_21 = V_68 + V_69 ;
F_25 ( V_21 -> type == V_81 , V_68 + V_69 ,
L_26 ) ;
V_24 = V_68 + V_69 + 1 ;
F_25 ( V_24 -> type == V_81 , V_68 + V_69 + 1 ,
L_27 ) ;
V_22 = ! F_9 ( V_6 , V_24 , L_28 ) ;
if ( F_8 ( V_6 , V_21 , V_22 , & V_23 , V_24 ) ) {
} else if ( F_9 ( V_6 , V_21 , L_29 ) ) {
char * V_82 = NULL ;
F_3 ( V_6 , & V_82 , L_4 , L_4 , V_24 ) ;
V_75 |= strtoul ( V_82 , NULL , 0 ) ;
free ( V_82 ) ;
} else if ( F_9 ( V_6 , V_21 , L_30 ) ) {
char * V_82 = NULL ;
F_3 ( V_6 , & V_82 , L_4 , L_4 , V_24 ) ;
V_75 |= strtoul ( V_82 , NULL , 0 ) << 21 ;
free ( V_82 ) ;
} else if ( F_9 ( V_6 , V_21 , L_31 ) ) {
F_3 ( V_6 , & V_51 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_32 ) ) {
F_3 ( V_6 , & V_52 , L_4 , L_4 , V_24 ) ;
F_6 ( V_52 ) ;
} else if ( F_9 ( V_6 , V_21 ,
L_33 ) ) {
F_3 ( V_6 , & V_53 , L_4 , L_4 , V_24 ) ;
F_6 ( V_53 ) ;
} else if ( F_9 ( V_6 , V_21 , L_34 ) && V_22 ) {
V_78 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_35 ) && V_22 ) {
V_76 = F_10 ( V_6 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_36 ) ) {
V_77 = V_24 ;
} else if ( F_9 ( V_6 , V_21 , L_37 ) &&
! F_9 ( V_6 , V_24 , L_38 ) ) {
F_3 ( V_6 , & V_73 , L_39 ,
L_40 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_41 ) && V_22 ) {
F_3 ( V_6 , & V_73 , L_39 ,
L_42 ,
NULL ) ;
} else if ( F_9 ( V_6 , V_21 , L_43 ) ) {
const char * V_83 ;
V_83 = F_12 ( V_84 , V_6 , V_24 ) ;
if ( V_83 ) {
V_54 = F_17 ( V_83 ) ;
} else {
if ( ! V_54 )
V_54 = F_17 ( L_44 ) ;
F_3 ( V_6 , & V_54 , L_4 , L_4 , V_24 ) ;
for ( V_16 = V_54 ; * V_16 ; V_16 ++ )
* V_16 = tolower ( * V_16 ) ;
}
F_3 ( V_6 , & V_52 , L_39 , L_45 , NULL ) ;
F_3 ( V_6 , & V_52 , L_4 , V_54 , NULL ) ;
F_3 ( V_6 , & V_52 , L_4 , L_46 , NULL ) ;
} else if ( F_9 ( V_6 , V_21 , L_47 ) ) {
F_3 ( V_6 , & V_74 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_48 ) ) {
F_3 ( V_6 , & V_55 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_49 ) ) {
F_3 ( V_6 , & V_56 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_50 ) ) {
F_3 ( V_6 , & V_58 , L_4 , L_4 , V_24 ) ;
} else if ( F_9 ( V_6 , V_21 , L_51 ) ) {
F_3 ( V_6 , & V_57 , L_4 , L_4 , V_24 ) ;
for ( V_16 = V_57 ; * V_16 ; V_16 ++ )
* V_16 = tolower ( * V_16 ) ;
}
}
if ( V_78 && V_52 && ! strstr ( V_52 , L_52 ) ) {
if ( F_9 ( V_6 , V_78 , L_53 ) )
F_3 ( V_6 , & V_73 , L_46 ,
L_54 , NULL ) ;
else
F_3 ( V_6 , & V_73 , L_46 ,
L_55 , NULL ) ;
}
snprintf ( V_70 , sizeof V_70 , L_56 , V_75 ) ;
F_3 ( V_6 , & V_23 , L_1 , V_70 , NULL ) ;
if ( V_52 && V_73 )
F_3 ( V_6 , & V_52 , L_46 , V_73 , NULL ) ;
if ( V_53 && V_73 )
F_3 ( V_6 , & V_53 , L_46 , V_73 , NULL ) ;
if ( V_74 )
F_3 ( V_6 , & V_23 , L_1 , V_74 , NULL ) ;
if ( V_76 != NULL )
F_3 ( V_6 , & V_23 , L_1 , V_76 -> V_85 , V_77 ) ;
F_5 ( V_51 ) ;
V_64 = F_23 ( V_50 , V_51 , F_21 ( V_51 , V_23 ) , V_52 , V_53 ,
V_54 , V_55 , V_56 , V_57 , V_58 ) ;
free ( V_23 ) ;
free ( V_52 ) ;
free ( V_51 ) ;
free ( V_53 ) ;
free ( V_73 ) ;
free ( V_54 ) ;
free ( V_74 ) ;
free ( V_56 ) ;
free ( V_55 ) ;
free ( V_57 ) ;
free ( V_58 ) ;
if ( V_64 )
break;
V_68 += V_69 ;
}
F_25 ( V_68 - V_67 == V_11 , V_68 , L_57 ) ;
V_64 = 0 ;
V_86:
F_26 ( V_6 , V_66 , V_67 ) ;
return V_64 ;
}
static char * F_27 ( char * V_87 )
{
unsigned int V_19 ;
int V_38 ;
int V_40 ;
char * V_48 ;
V_38 = F_14 ( & V_48 , L_58 , F_28 ( V_87 ) ) ;
if ( V_38 < 0 ) {
F_15 ( L_59 , V_31 ,
strerror ( V_45 ) , V_87 ) ;
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
F_11 ( L_60 ,
V_31 , V_40 , F_28 ( V_87 ) ) ;
free ( V_48 ) ;
V_48 = NULL ;
break;
}
}
return V_48 ;
}
static void F_29 ( T_3 * V_61 )
{
fprintf ( V_61 , L_61 ) ;
}
static void F_30 ( T_3 * V_61 )
{
fprintf ( V_61 , L_8 ) ;
fprintf ( V_61 , L_62 ) ;
fprintf ( V_61 , L_63 ) ;
fprintf ( V_61 , L_64 ) ;
fprintf ( V_61 , L_65 ) ;
fprintf ( V_61 , L_19 ) ;
fprintf ( V_61 , L_23 ) ;
}
static int F_31 ( T_3 * V_61 , char * V_88 )
{
int V_38 = 16384 ;
T_3 * V_89 ;
char * V_90 = NULL ;
char * line , * V_91 ;
int V_92 ;
char * V_48 ;
F_15 ( L_66 , V_31 , V_88 ) ;
line = malloc ( V_38 ) ;
if ( ! line )
return - 1 ;
V_89 = fopen ( V_88 , L_67 ) ;
if ( ! V_89 ) {
F_15 ( L_68 , V_31 , strerror ( V_45 ) ,
V_88 ) ;
return - 1 ;
}
F_29 ( V_61 ) ;
V_91 = fgets ( line , V_38 , V_89 ) ;
if ( ! V_91 )
goto V_14;
V_92 = 1 ;
while ( 1 ) {
char * V_93 , * V_94 , * type , * V_87 ;
V_92 ++ ;
V_91 = fgets ( line , V_38 , V_89 ) ;
if ( ! V_91 )
break;
if ( line [ 0 ] == '#' || line [ 0 ] == '\n' )
continue;
if ( line [ strlen ( line ) - 1 ] != '\n' ) {
F_15 ( L_69 ,
V_31 , V_88 , V_92 ) ;
return - 1 ;
}
line [ strlen ( line ) - 1 ] = '\0' ;
V_93 = strtok_r ( V_91 , L_1 , & V_90 ) ;
V_94 = strtok_r ( NULL , L_1 , & V_90 ) ;
V_87 = strtok_r ( NULL , L_1 , & V_90 ) ;
type = strtok_r ( NULL , L_1 , & V_90 ) ;
V_48 = F_27 ( V_87 ) ;
fprintf ( V_61 , L_8 ) ;
fprintf ( V_61 , L_70 , V_93 ) ;
fprintf ( V_61 , L_71 , V_94 ) ;
fprintf ( V_61 , L_72 , type ) ;
fprintf ( V_61 , L_73 , V_48 ) ;
fprintf ( V_61 , L_19 ) ;
}
V_14:
F_30 ( V_61 ) ;
return 0 ;
}
static void F_32 ( const char * V_95 )
{
T_3 * V_61 ;
F_15 ( L_74 , V_31 ) ;
V_61 = fopen ( V_95 , L_75 ) ;
if ( ! V_61 ) {
perror ( L_76 ) ;
F_33 ( 1 ) ;
}
fprintf ( V_61 , L_77 ) ;
F_29 ( V_61 ) ;
F_30 ( V_61 ) ;
fclose ( V_61 ) ;
}
static int F_34 ( void )
{
struct V_96 V_97 ;
if ( F_35 ( V_98 , & V_97 ) == 0 )
return F_36 ( ( int ) V_97 . V_99 / 2 , 512 ) ;
return 512 ;
}
static int F_37 ( const char * V_88 , const struct V_100 * V_101 ,
int V_102 , struct V_103 * V_104 )
{
char * V_48 , * V_41 = ( char * ) V_88 + V_104 -> V_105 ;
int V_106 = V_102 == V_107 ;
int V_108 = V_102 == V_109 ;
int V_1 = V_104 -> V_1 ;
int V_64 = 0 ;
F_38 ( L_78 ,
V_108 ? L_79 : V_106 ? L_80 : L_81 ,
V_1 , V_101 -> V_110 , V_41 , V_88 ) ;
if ( V_1 == 0 )
return 0 ;
if ( V_1 == 1 && V_106 ) {
if ( V_49 )
F_20 ( V_111 ) ;
V_48 = F_27 ( V_41 ) ;
if ( ! V_48 ) {
F_15 ( L_82 , V_31 ,
V_41 ) ;
return - 1 ;
}
F_18 ( V_111 , V_48 ) ;
return 0 ;
}
if ( V_1 == 1 && V_108 ) {
if ( ! strncmp ( V_41 , L_83 , 11 ) ) {
if ( V_112 ) {
F_15 ( L_84 ,
V_31 , V_112 , V_88 ) ;
} else {
V_112 = F_17 ( V_88 ) ;
}
return 0 ;
}
F_15 ( L_85 , V_31 , V_88 ) ;
return 0 ;
}
if ( V_108 ) {
char * V_113 = V_41 + strlen ( V_41 ) - 5 ;
if ( strncmp ( V_113 , L_86 , 5 ) ) {
F_15 ( L_87 , V_31 ,
V_88 ) ;
return 0 ;
}
}
if ( V_1 > 1 && F_16 ( V_1 , V_41 ) )
return - V_46 ;
if ( V_108 ) {
struct V_59 V_50 = {
. V_42 = F_13 () ,
. V_61 = V_111 ,
} ;
V_64 = F_22 ( V_88 , F_19 , & V_50 ) ;
free ( V_50 . V_42 ) ;
}
return V_64 ;
}
int main ( int V_114 , char * V_115 [] )
{
int V_116 ;
int V_117 ;
char V_118 [ V_119 ] ;
const char * V_120 ;
const char * V_95 ;
const char * V_121 ;
V_31 = F_28 ( V_115 [ 0 ] ) ;
if ( V_114 < 4 ) {
F_11 ( L_88 , V_31 ) ;
return 1 ;
}
V_120 = V_115 [ 1 ] ;
V_121 = V_115 [ 2 ] ;
V_95 = V_115 [ 3 ] ;
if ( V_114 > 4 )
V_122 = atoi ( V_115 [ 4 ] ) ;
V_111 = fopen ( V_95 , L_75 ) ;
if ( ! V_111 ) {
F_11 ( L_89 ,
V_31 , V_95 , strerror ( V_45 ) ) ;
return 2 ;
}
fprintf ( V_111 , L_77 ) ;
sprintf ( V_118 , L_90 , V_121 , V_120 ) ;
V_117 = F_34 () ;
V_112 = NULL ;
V_116 = F_39 ( V_118 , F_37 , V_117 , 0 ) ;
if ( V_116 && V_122 ) {
F_15 ( L_91 , V_31 , V_118 ) ;
goto V_123;
} else if ( V_116 ) {
goto V_123;
}
if ( V_49 )
F_20 ( V_111 ) ;
if ( ! V_112 ) {
F_15 ( L_92 , V_31 ) ;
goto V_123;
}
if ( F_31 ( V_111 , V_112 ) ) {
F_15 ( L_93 , V_31 , V_112 ) ;
goto V_123;
}
return 0 ;
V_123:
fclose ( V_111 ) ;
F_32 ( V_95 ) ;
return 0 ;
}
