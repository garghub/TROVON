static bool F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_4 )
return true ;
}
return false ;
}
static const char * F_2 ( enum V_5 V_6 )
{
int V_7 , V_8 = F_3 ( V_9 ) ;
const char * V_10 = L_1 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( V_9 [ V_7 ] . V_6 == V_6 ) {
V_10 = V_9 [ V_7 ] . V_10 ;
break;
}
}
return V_10 ;
}
static int F_4 ( struct V_11 * V_12 ,
T_1 V_13 , const char * V_14 ,
enum V_5 V_6 )
{
int type = V_12 -> type ;
const char * V_15 ;
if ( V_12 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
F_6 ( L_2
L_3 ,
V_15 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_17 &= ~ V_6 ;
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
F_7 ( L_2
L_4 ,
V_15 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( F_9 ( V_22 ) &&
! F_10 ( V_21 , L_5 ) )
return - V_23 ;
if ( F_9 ( V_24 ) ) {
if ( F_4 ( V_12 , V_25 , L_6 ,
V_26 ) )
return - V_23 ;
if ( ! V_27 &&
! ( V_12 -> V_13 & V_28 ) )
V_29 . V_30 = false ;
}
if ( ( F_9 ( V_31 ) || F_9 ( V_32 ) ) &&
F_4 ( V_12 , V_33 , L_7 ,
V_34 | V_35 ) )
return - V_23 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_36 , L_8 ,
V_37 ) )
return - V_23 ;
if ( F_9 ( V_38 ) &&
F_4 ( V_12 , V_39 , L_9 ,
V_40 ) )
return - V_23 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_18 * V_19 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_19 = F_12 ( V_21 , V_1 ) ;
if ( ! V_19 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_41 ) {
F_6 ( L_10
L_11 ,
F_13 ( V_1 ) ) ;
return - 1 ;
}
if ( V_19 && V_3 [ V_1 ] . V_17 &&
F_8 ( V_19 , V_21 ) )
return - 1 ;
}
return 0 ;
}
static void F_14 ( struct V_42 * V_43 ,
struct V_44 * V_44 ,
struct V_11 * V_12 )
{
int type ;
struct V_45 * V_45 ;
const char * V_15 = NULL ;
unsigned long V_46 ;
unsigned long V_47 ;
unsigned long long V_48 ;
if ( F_9 ( V_49 ) ) {
if ( V_50 )
printf ( L_12 , V_44 -> V_51 ) ;
else if ( F_9 ( V_24 ) && V_29 . V_30 )
printf ( L_13 , V_44 -> V_51 ) ;
else
printf ( L_14 , V_44 -> V_51 ) ;
}
if ( F_9 ( V_31 ) && F_9 ( V_32 ) )
printf ( L_15 , V_43 -> V_52 , V_43 -> V_53 ) ;
else if ( F_9 ( V_31 ) )
printf ( L_16 , V_43 -> V_52 ) ;
else if ( F_9 ( V_32 ) )
printf ( L_16 , V_43 -> V_53 ) ;
if ( F_9 ( V_38 ) ) {
if ( V_50 )
printf ( L_17 , V_43 -> V_54 ) ;
else
printf ( L_18 , V_43 -> V_54 ) ;
}
if ( F_9 ( TIME ) ) {
V_48 = V_43 -> time ;
V_46 = V_48 / V_55 ;
V_48 -= V_46 * V_55 ;
V_47 = V_48 / V_56 ;
printf ( L_19 , V_46 , V_47 ) ;
}
if ( F_9 ( V_57 ) ) {
if ( V_12 -> type == V_58 ) {
type = F_15 ( V_43 -> V_59 ) ;
V_45 = F_16 ( type ) ;
if ( V_45 )
V_15 = V_45 -> V_60 ;
} else
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
printf ( L_20 , V_15 ? V_15 : L_21 ) ;
}
}
static void F_17 ( union V_61 * V_45 V_62 ,
struct V_42 * V_43 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_44 * V_44 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( V_3 [ V_12 -> type ] . V_17 == 0 )
return;
F_14 ( V_43 , V_44 , V_12 ) ;
if ( F_9 ( V_22 ) )
F_18 ( V_43 -> V_54 , V_43 -> V_59 ,
V_43 -> V_63 ) ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_22 ) ;
else
printf ( L_23 ) ;
F_19 ( V_45 , V_43 , V_21 ) ;
}
printf ( L_23 ) ;
}
static int F_20 ( const char * T_2 V_62 ,
int T_3 V_62 ,
const char * * T_4 V_62 )
{
return 0 ;
}
static int F_21 ( void )
{
return 0 ;
}
static int F_22 ( const char * T_5 V_62 )
{
return 0 ;
}
static void F_23 ( void )
{
F_24 () ;
F_25 () ;
V_64 = & V_65 ;
}
static int F_26 ( void )
{
F_7 ( L_24 ) ;
return V_64 -> V_66 () ;
}
static int F_27 ( union V_61 * V_45 ,
struct V_42 * V_43 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_44 * V_44 = F_28 ( V_21 , V_45 -> V_67 . V_52 ) ;
if ( V_44 == NULL ) {
F_7 ( L_25 ,
V_45 -> V_68 . type ) ;
return - 1 ;
}
if ( V_69 ) {
if ( V_43 -> time < V_70 ) {
F_6 ( L_26 V_71
L_27 V_71 L_23 , V_70 ,
V_43 -> time ) ;
V_72 ++ ;
}
V_70 = V_43 -> time ;
return 0 ;
}
V_64 -> F_17 ( V_45 , V_43 , V_19 , V_21 , V_44 ) ;
V_21 -> V_73 . V_74 . V_75 += V_43 -> V_76 ;
return 0 ;
}
static void F_29 ( int T_6 V_62 )
{
V_77 = 1 ;
}
static int F_30 ( struct V_20 * V_21 )
{
int V_78 ;
signal ( V_79 , F_29 ) ;
V_78 = F_31 ( V_21 , & V_80 ) ;
if ( V_69 )
F_6 ( L_28 V_71 L_23 , V_72 ) ;
return V_78 ;
}
static struct V_81 * F_32 ( const char * V_82 ,
struct V_64 * V_83 )
{
struct V_81 * V_84 = malloc ( sizeof( * V_84 ) + strlen ( V_82 ) + 1 ) ;
if ( V_84 != NULL ) {
strcpy ( V_84 -> V_82 , V_82 ) ;
V_84 -> V_83 = V_83 ;
}
return V_84 ;
}
static void F_33 ( struct V_81 * V_84 )
{
free ( V_84 -> V_82 ) ;
free ( V_84 ) ;
}
static void F_34 ( struct V_81 * V_84 )
{
F_35 ( & V_84 -> V_85 , & V_86 ) ;
}
static struct V_81 * F_36 ( const char * V_82 )
{
struct V_81 * V_84 ;
F_37 (s, &script_specs, node)
if ( strcasecmp ( V_84 -> V_82 , V_82 ) == 0 )
return V_84 ;
return NULL ;
}
static struct V_81 * F_38 ( const char * V_82 ,
struct V_64 * V_83 )
{
struct V_81 * V_84 = F_36 ( V_82 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_32 ( V_82 , V_83 ) ;
if ( ! V_84 )
goto V_87;
F_34 ( V_84 ) ;
return V_84 ;
V_87:
F_33 ( V_84 ) ;
return NULL ;
}
int F_39 ( const char * V_82 , struct V_64 * V_83 )
{
struct V_81 * V_84 ;
V_84 = F_36 ( V_82 ) ;
if ( V_84 )
return - 1 ;
V_84 = F_38 ( V_82 , V_83 ) ;
if ( ! V_84 )
return - 1 ;
return 0 ;
}
static struct V_64 * F_40 ( const char * V_82 )
{
struct V_81 * V_84 = F_36 ( V_82 ) ;
if ( ! V_84 )
return NULL ;
return V_84 -> V_83 ;
}
static void F_41 ( void )
{
struct V_81 * V_84 ;
fprintf ( V_88 , L_23 ) ;
fprintf ( V_88 , L_29
L_30 ) ;
F_37 (s, &script_specs, node)
fprintf ( V_88 , L_31 , V_84 -> V_82 , V_84 -> V_83 -> V_60 ) ;
fprintf ( V_88 , L_23 ) ;
}
static int F_42 ( const struct V_89 * T_7 V_90 ,
const char * V_10 , int T_8 V_90 )
{
char V_82 [ V_91 ] ;
const char * T_2 , * V_92 ;
int V_93 ;
if ( strcmp ( V_10 , L_32 ) == 0 ) {
F_41 () ;
exit ( 0 ) ;
}
T_2 = strchr ( V_10 , ':' ) ;
if ( T_2 ) {
V_93 = T_2 - V_10 ;
if ( V_93 >= V_91 ) {
fprintf ( V_88 , L_33 ) ;
return - 1 ;
}
strncpy ( V_82 , V_10 , V_93 ) ;
V_82 [ V_93 ] = '\0' ;
V_64 = F_40 ( V_82 ) ;
if ( ! V_64 ) {
fprintf ( V_88 , L_33 ) ;
return - 1 ;
}
T_2 ++ ;
} else {
T_2 = V_10 ;
V_92 = strrchr ( T_2 , '.' ) ;
if ( ! V_92 ) {
fprintf ( V_88 , L_34 ) ;
return - 1 ;
}
V_64 = F_40 ( ++ V_92 ) ;
if ( ! V_64 ) {
fprintf ( V_88 , L_34 ) ;
return - 1 ;
}
}
V_94 = F_43 ( T_2 ) ;
return 0 ;
}
static int F_44 ( const struct V_89 * T_7 V_90 ,
const char * V_95 , int T_8 V_90 )
{
char * V_96 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_97 ) ;
int V_1 ;
int V_98 = 0 ;
char * V_10 = F_43 ( V_95 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_99 ;
V_96 = strchr ( V_10 , ':' ) ;
if ( V_96 ) {
* V_96 = '\0' ;
V_96 ++ ;
if ( ! strcmp ( V_10 , L_35 ) )
type = V_100 ;
else if ( ! strcmp ( V_10 , L_36 ) )
type = V_101 ;
else if ( ! strcmp ( V_10 , L_37 ) )
type = V_58 ;
else if ( ! strcmp ( V_10 , L_38 ) )
type = V_102 ;
else {
fprintf ( V_88 , L_39 ) ;
return - V_23 ;
}
if ( V_3 [ type ] . V_4 )
F_45 ( L_40 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_17 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_41 = false ;
} else {
V_96 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_88 ,
L_41 ) ;
V_98 = - V_23 ;
goto V_103;
}
if ( F_1 () )
F_45 ( L_42 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_17 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_41 = true ;
}
}
V_96 = strtok ( V_96 , L_43 ) ;
while ( V_96 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_96 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_88 , L_44 ) ;
V_98 = - V_23 ;
goto V_103;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_104 & V_9 [ V_7 ] . V_6 ) {
F_45 ( L_45 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_104 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_88 , L_46 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_98 = - V_23 ;
goto V_103;
}
V_3 [ type ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
V_96 = strtok ( NULL , L_43 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_17 == 0 ) {
F_7 ( L_47
L_48 , F_13 ( type ) ) ;
}
}
V_103:
free ( V_10 ) ;
return V_98 ;
}
static int F_46 ( const char * V_105 , const struct V_106 * V_107 )
{
char V_108 [ V_91 ] ;
struct V_109 V_110 ;
sprintf ( V_108 , L_49 , V_105 , V_107 -> V_111 ) ;
if ( V_109 ( V_108 , & V_110 ) )
return 0 ;
return F_47 ( V_110 . V_112 ) ;
}
static struct V_113 * F_48 ( const char * V_60 )
{
struct V_113 * V_84 = F_49 ( sizeof( * V_84 ) ) ;
if ( V_84 != NULL && V_60 )
V_84 -> V_60 = F_43 ( V_60 ) ;
return V_84 ;
}
static void F_50 ( struct V_113 * V_84 )
{
free ( V_84 -> V_60 ) ;
free ( V_84 -> V_114 ) ;
free ( V_84 -> args ) ;
free ( V_84 ) ;
}
static void F_51 ( struct V_113 * V_84 )
{
F_35 ( & V_84 -> V_85 , & V_115 ) ;
}
static struct V_113 * F_52 ( const char * V_60 )
{
struct V_113 * V_84 ;
F_37 (s, &script_descs, node)
if ( strcasecmp ( V_84 -> V_60 , V_60 ) == 0 )
return V_84 ;
return NULL ;
}
static struct V_113 * F_53 ( const char * V_60 )
{
struct V_113 * V_84 = F_52 ( V_60 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_48 ( V_60 ) ;
if ( ! V_84 )
goto V_116;
F_51 ( V_84 ) ;
return V_84 ;
V_116:
F_50 ( V_84 ) ;
return NULL ;
}
static const char * F_54 ( const char * V_10 , const char * V_117 )
{
T_9 V_118 = strlen ( V_117 ) ;
const char * V_119 = V_10 ;
if ( strlen ( V_10 ) > V_118 ) {
V_119 = V_10 + strlen ( V_10 ) - V_118 ;
if ( ! strncmp ( V_119 , V_117 , V_118 ) )
return V_119 ;
}
return NULL ;
}
static char * F_55 ( char * V_10 )
{
int V_93 = strlen ( V_10 ) ;
while ( V_93 && isspace ( * V_10 ) ) {
V_93 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_56 ( struct V_113 * V_120 , const char * V_121 )
{
char line [ V_122 ] , * V_119 ;
T_10 * V_123 ;
V_123 = fopen ( V_121 , L_50 ) ;
if ( ! V_123 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_123 ) ) {
V_119 = F_55 ( line ) ;
if ( strlen ( V_119 ) == 0 )
continue;
if ( * V_119 != '#' )
continue;
V_119 ++ ;
if ( strlen ( V_119 ) && * V_119 == '!' )
continue;
V_119 = F_55 ( V_119 ) ;
if ( strlen ( V_119 ) && V_119 [ strlen ( V_119 ) - 1 ] == '\n' )
V_119 [ strlen ( V_119 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_119 , L_51 , strlen ( L_51 ) ) ) {
V_119 += strlen ( L_51 ) ;
V_120 -> V_114 = F_43 ( F_55 ( V_119 ) ) ;
continue;
}
if ( ! strncmp ( V_119 , L_52 , strlen ( L_52 ) ) ) {
V_119 += strlen ( L_52 ) ;
V_120 -> args = F_43 ( F_55 ( V_119 ) ) ;
continue;
}
}
fclose ( V_123 ) ;
return 0 ;
}
static int F_57 ( const struct V_89 * T_7 V_90 ,
const char * V_84 V_90 , int T_8 V_90 )
{
struct V_106 * V_124 , * V_125 , V_126 , V_127 ;
char V_128 [ V_129 ] ;
T_11 * V_130 , * V_131 ;
char V_132 [ V_129 ] ;
char V_133 [ V_129 ] ;
struct V_113 * V_120 ;
char V_134 [ V_122 ] ;
char * V_135 ;
char * V_10 ;
snprintf ( V_128 , V_129 , L_53 , F_58 () ) ;
V_130 = F_59 ( V_128 ) ;
if ( ! V_130 )
return - 1 ;
F_60 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_133 , V_129 , L_54 , V_128 ,
V_127 . V_111 ) ;
V_131 = F_59 ( V_133 ) ;
if ( ! V_131 )
continue;
F_61 (lang_path, lang_dir, script_dirent, script_next) {
V_135 = F_43 ( V_126 . V_111 ) ;
V_10 = ( char * ) F_54 ( V_135 , V_136 ) ;
if ( V_10 ) {
* V_10 = '\0' ;
V_120 = F_53 ( V_135 ) ;
snprintf ( V_132 , V_129 , L_49 ,
V_133 , V_126 . V_111 ) ;
F_56 ( V_120 , V_132 ) ;
}
free ( V_135 ) ;
}
}
fprintf ( stdout , L_55 ) ;
F_37 (desc, &script_descs, node) {
sprintf ( V_134 , L_56 , V_120 -> V_60 ,
V_120 -> args ? V_120 -> args : L_1 ) ;
fprintf ( stdout , L_57 , V_134 ,
V_120 -> V_114 ? V_120 -> V_114 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_62 ( const char * V_135 , const char * V_117 )
{
struct V_106 * V_124 , * V_125 , V_126 , V_127 ;
char V_128 [ V_129 ] ;
char V_132 [ V_129 ] ;
T_11 * V_130 , * V_131 ;
char V_133 [ V_129 ] ;
char * V_10 , * V_137 ;
char * V_108 = NULL ;
snprintf ( V_128 , V_129 , L_53 , F_58 () ) ;
V_130 = F_59 ( V_128 ) ;
if ( ! V_130 )
return NULL ;
F_60 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_133 , V_129 , L_54 , V_128 ,
V_127 . V_111 ) ;
V_131 = F_59 ( V_133 ) ;
if ( ! V_131 )
continue;
F_61 (lang_path, lang_dir, script_dirent, script_next) {
V_137 = F_43 ( V_126 . V_111 ) ;
V_10 = ( char * ) F_54 ( V_137 , V_117 ) ;
if ( V_10 ) {
* V_10 = '\0' ;
if ( strcmp ( V_137 , V_135 ) )
continue;
snprintf ( V_132 , V_129 , L_49 ,
V_133 , V_126 . V_111 ) ;
V_108 = F_43 ( V_132 ) ;
free ( V_137 ) ;
break;
}
free ( V_137 ) ;
}
}
return V_108 ;
}
static bool F_63 ( const char * V_132 )
{
return F_54 ( V_132 , L_58 ) == NULL ? false : true ;
}
static int F_64 ( char * V_132 )
{
struct V_113 * V_120 ;
int V_138 = 0 ;
char * V_119 ;
V_120 = F_48 ( NULL ) ;
if ( F_56 ( V_120 , V_132 ) )
goto V_103;
if ( ! V_120 -> args )
goto V_103;
for ( V_119 = V_120 -> args ; * V_119 ; V_119 ++ )
if ( * V_119 == '<' )
V_138 ++ ;
V_103:
F_50 ( V_120 ) ;
return V_138 ;
}
static bool F_65 ( int T_3 , const char * * T_4 )
{
char * * V_139 = malloc ( sizeof( const char * ) * T_3 ) ;
if ( ! V_139 )
F_66 ( L_59 ) ;
memcpy ( V_139 , T_4 , sizeof( const char * ) * T_3 ) ;
T_3 = F_67 ( T_3 , ( const char * * ) V_139 , V_140 ,
NULL , V_141 ) ;
free ( V_139 ) ;
return T_3 != 0 ;
}
int F_68 ( int T_3 , const char * * T_4 , const char * T_12 V_90 )
{
char * V_142 = NULL ;
char * V_143 = NULL ;
struct V_20 * V_21 ;
char * V_132 = NULL ;
const char * * V_139 ;
bool V_144 ;
int V_7 , V_1 , V_145 ;
F_23 () ;
T_3 = F_67 ( T_3 , T_4 , V_146 , V_147 ,
V_141 ) ;
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_60 , strlen ( L_60 ) ) ) {
V_142 = F_62 ( T_4 [ 1 ] , V_148 ) ;
if ( ! V_142 )
return F_69 ( T_3 , T_4 , NULL ) ;
}
if ( T_3 > 1 && ! strncmp ( T_4 [ 0 ] , L_61 , strlen ( L_61 ) ) ) {
V_143 = F_62 ( T_4 [ 1 ] , V_136 ) ;
if ( ! V_143 ) {
fprintf ( V_88 ,
L_62
L_63 ) ;
return - 1 ;
}
}
F_70 ( F_58 () ) ;
if ( T_3 && ! V_94 && ! V_142 && ! V_143 ) {
int V_149 [ 2 ] ;
int V_150 ;
T_13 V_52 ;
V_142 = F_62 ( T_4 [ 0 ] , V_148 ) ;
V_143 = F_62 ( T_4 [ 0 ] , V_136 ) ;
if ( ! V_142 && ! V_143 ) {
fprintf ( V_88 , L_64
L_65 , T_4 [ 0 ] ) ;
F_71 ( V_147 , V_146 ) ;
}
if ( F_63 ( T_4 [ 0 ] ) ) {
V_150 = T_3 - 1 ;
} else {
int V_151 ;
V_150 = F_64 ( V_143 ) ;
V_151 = ( T_3 - 1 ) - V_150 ;
if ( V_151 < 0 ) {
fprintf ( V_88 , L_66
L_67
L_68 , T_4 [ 0 ] ) ;
F_71 ( V_147 , V_146 ) ;
}
}
if ( F_72 ( V_149 ) < 0 ) {
perror ( L_69 ) ;
exit ( - 1 ) ;
}
V_52 = F_73 () ;
if ( V_52 < 0 ) {
perror ( L_70 ) ;
exit ( - 1 ) ;
}
if ( ! V_52 ) {
V_144 = true ;
V_1 = 0 ;
F_74 ( V_149 [ 1 ] , 1 ) ;
F_75 ( V_149 [ 0 ] ) ;
if ( ! F_63 ( T_4 [ 0 ] ) )
V_144 = ! F_65 ( T_3 - V_150 ,
& T_4 [ V_150 ] ) ;
V_139 = malloc ( ( T_3 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_139 )
F_66 ( L_59 ) ;
V_139 [ V_1 ++ ] = L_71 ;
V_139 [ V_1 ++ ] = V_142 ;
if ( V_144 )
V_139 [ V_1 ++ ] = L_72 ;
V_139 [ V_1 ++ ] = L_73 ;
V_139 [ V_1 ++ ] = L_74 ;
V_139 [ V_1 ++ ] = L_75 ;
for ( V_7 = V_150 + 1 ; V_7 < T_3 ; V_7 ++ )
V_139 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_139 [ V_1 ++ ] = NULL ;
F_76 ( L_71 , ( char * * ) V_139 ) ;
free ( V_139 ) ;
exit ( - 1 ) ;
}
F_74 ( V_149 [ 0 ] , 0 ) ;
F_75 ( V_149 [ 1 ] ) ;
V_139 = malloc ( ( T_3 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_139 )
F_66 ( L_59 ) ;
V_1 = 0 ;
V_139 [ V_1 ++ ] = L_71 ;
V_139 [ V_1 ++ ] = V_143 ;
for ( V_7 = 1 ; V_7 < V_150 + 1 ; V_7 ++ )
V_139 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_139 [ V_1 ++ ] = L_76 ;
V_139 [ V_1 ++ ] = L_75 ;
V_139 [ V_1 ++ ] = NULL ;
F_76 ( L_71 , ( char * * ) V_139 ) ;
free ( V_139 ) ;
exit ( - 1 ) ;
}
if ( V_142 )
V_132 = V_142 ;
if ( V_143 )
V_132 = V_143 ;
if ( V_132 ) {
V_144 = false ;
V_1 = 0 ;
if ( V_142 )
V_144 = ! F_65 ( T_3 - 1 , & T_4 [ 1 ] ) ;
V_139 = malloc ( ( T_3 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_139 )
F_66 ( L_59 ) ;
V_139 [ V_1 ++ ] = L_71 ;
V_139 [ V_1 ++ ] = V_132 ;
if ( V_144 )
V_139 [ V_1 ++ ] = L_72 ;
for ( V_7 = 2 ; V_7 < T_3 ; V_7 ++ )
V_139 [ V_1 ++ ] = T_4 [ V_7 ] ;
V_139 [ V_1 ++ ] = NULL ;
F_76 ( L_71 , ( char * * ) V_139 ) ;
free ( V_139 ) ;
exit ( - 1 ) ;
}
if ( F_77 () < 0 )
return - 1 ;
if ( ! V_94 )
F_78 () ;
V_21 = F_79 ( V_152 , V_153 , 0 , false , & V_80 ) ;
if ( V_21 == NULL )
return - V_99 ;
if ( ! V_27 )
V_29 . V_30 = true ;
else
V_29 . V_30 = false ;
if ( V_154 ) {
struct V_109 V_155 ;
int V_156 ;
if ( F_1 () ) {
fprintf ( V_88 ,
L_77 ) ;
return - 1 ;
}
V_156 = F_80 ( V_152 , V_153 ) ;
if ( V_156 < 0 ) {
perror ( L_78 ) ;
exit ( - 1 ) ;
}
V_145 = F_81 ( V_156 , & V_155 ) ;
if ( V_145 < 0 ) {
perror ( L_79 ) ;
exit ( - 1 ) ;
}
if ( ! V_155 . V_157 ) {
fprintf ( V_88 , L_80 ) ;
exit ( 0 ) ;
}
V_64 = F_40 ( V_154 ) ;
if ( ! V_64 ) {
fprintf ( V_88 , L_33 ) ;
return - 1 ;
}
V_145 = V_64 -> V_158 ( L_81 ) ;
goto V_103;
}
if ( V_94 ) {
V_145 = V_64 -> V_159 ( V_94 , T_3 , T_4 ) ;
if ( V_145 )
goto V_103;
F_7 ( L_82 , V_94 ) ;
}
V_145 = F_11 ( V_21 ) ;
if ( V_145 < 0 )
goto V_103;
V_145 = F_30 ( V_21 ) ;
F_82 ( V_21 ) ;
F_26 () ;
V_103:
return V_145 ;
}
