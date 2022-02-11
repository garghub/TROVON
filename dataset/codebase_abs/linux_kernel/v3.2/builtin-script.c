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
if ( F_9 ( V_31 ) &&
F_4 ( V_12 , V_32 , L_7 ,
V_33 ) )
return - V_23 ;
if ( F_9 ( V_34 ) && ! F_9 ( V_24 ) && ! F_9 ( V_31 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_23 ;
}
if ( F_9 ( V_35 ) && ! F_9 ( V_24 ) && ! F_9 ( V_31 ) ) {
F_6 ( L_11
L_9
L_12 ) ;
return - V_23 ;
}
if ( ( F_9 ( V_36 ) || F_9 ( V_37 ) ) &&
F_4 ( V_12 , V_38 , L_13 ,
V_39 | V_40 ) )
return - V_23 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_41 , L_14 ,
V_42 ) )
return - V_23 ;
if ( F_9 ( V_43 ) &&
F_4 ( V_12 , V_44 , L_15 ,
V_45 ) )
return - V_23 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_18 * V_19 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_19 = F_12 ( V_21 , V_1 ) ;
if ( ! V_19 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_46 ) {
F_6 ( L_16
L_17 ,
F_13 ( V_1 ) ) ;
return - 1 ;
}
if ( V_19 && V_3 [ V_1 ] . V_17 &&
F_8 ( V_19 , V_21 ) )
return - 1 ;
}
return 0 ;
}
static void F_14 ( struct V_47 * V_48 ,
struct V_49 * V_49 ,
struct V_11 * V_12 )
{
int type ;
struct V_50 * V_50 ;
const char * V_15 = NULL ;
unsigned long V_51 ;
unsigned long V_52 ;
unsigned long long V_53 ;
if ( F_9 ( V_54 ) ) {
if ( V_55 )
printf ( L_18 , V_49 -> V_56 ) ;
else if ( F_9 ( V_24 ) && V_29 . V_30 )
printf ( L_19 , V_49 -> V_56 ) ;
else
printf ( L_20 , V_49 -> V_56 ) ;
}
if ( F_9 ( V_36 ) && F_9 ( V_37 ) )
printf ( L_21 , V_48 -> V_57 , V_48 -> V_58 ) ;
else if ( F_9 ( V_36 ) )
printf ( L_22 , V_48 -> V_57 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_22 , V_48 -> V_58 ) ;
if ( F_9 ( V_43 ) ) {
if ( V_55 )
printf ( L_23 , V_48 -> V_59 ) ;
else
printf ( L_24 , V_48 -> V_59 ) ;
}
if ( F_9 ( TIME ) ) {
V_53 = V_48 -> time ;
V_51 = V_53 / V_60 ;
V_53 -= V_51 * V_60 ;
V_52 = V_53 / V_61 ;
printf ( L_25 , V_51 , V_52 ) ;
}
if ( F_9 ( V_62 ) ) {
if ( V_12 -> type == V_63 ) {
type = F_15 ( V_48 -> V_64 ) ;
V_50 = F_16 ( type ) ;
if ( V_50 )
V_15 = V_50 -> V_65 ;
} else
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
printf ( L_26 , V_15 ? V_15 : L_27 ) ;
}
}
static bool F_17 ( struct V_11 * V_12 )
{
if ( ( V_12 -> type == V_66 ) &&
( ( V_12 -> V_16 == V_67 ) ||
( V_12 -> V_16 == V_68 ) ||
( V_12 -> V_16 == V_69 ) ) )
return true ;
return false ;
}
static void F_18 ( union V_70 * V_50 ,
struct V_47 * V_48 ,
struct V_20 * V_21 ,
struct V_49 * V_49 ,
struct V_11 * V_12 )
{
struct V_71 V_72 ;
T_2 V_73 = V_50 -> V_74 . V_75 & V_76 ;
const char * V_77 , * V_78 ;
printf ( L_28 V_79 , V_48 -> V_80 ) ;
if ( ! F_17 ( V_12 ) )
return;
F_19 ( V_49 , V_21 , V_73 , V_81 ,
V_50 -> V_82 . V_57 , V_48 -> V_80 , & V_72 ) ;
if ( ! V_72 . V_83 )
F_19 ( V_49 , V_21 , V_73 , V_84 ,
V_50 -> V_82 . V_57 , V_48 -> V_80 , & V_72 ) ;
V_72 . V_59 = V_48 -> V_59 ;
V_72 . V_85 = NULL ;
if ( V_72 . V_83 )
V_72 . V_85 = F_20 ( V_72 . V_83 , V_72 . V_80 , NULL ) ;
if ( F_9 ( V_34 ) ) {
if ( V_72 . V_85 && V_72 . V_85 -> V_65 )
V_77 = V_72 . V_85 -> V_65 ;
else
V_77 = L_1 ;
printf ( L_29 , V_77 ) ;
}
if ( F_9 ( V_35 ) ) {
if ( V_72 . V_83 && V_72 . V_83 -> V_86 && V_72 . V_83 -> V_86 -> V_65 )
V_78 = V_72 . V_83 -> V_86 -> V_65 ;
else
V_78 = L_1 ;
printf ( L_30 , V_78 ) ;
}
}
static void F_21 ( union V_70 * V_50 V_87 ,
struct V_47 * V_48 ,
struct V_18 * V_19 ,
struct V_20 * V_21 ,
struct V_49 * V_49 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( V_3 [ V_12 -> type ] . V_17 == 0 )
return;
F_14 ( V_48 , V_49 , V_12 ) ;
if ( F_9 ( V_22 ) )
F_22 ( V_48 -> V_59 , V_48 -> V_64 ,
V_48 -> V_88 ) ;
if ( F_9 ( V_31 ) )
F_18 ( V_50 , V_48 , V_21 , V_49 , V_12 ) ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_32 ) ;
F_23 ( V_50 , V_48 , V_21 ,
F_9 ( V_34 ) , F_9 ( V_35 ) ) ;
}
printf ( L_32 ) ;
}
static int F_24 ( const char * T_3 V_87 ,
int T_4 V_87 ,
const char * * T_5 V_87 )
{
return 0 ;
}
static int F_25 ( void )
{
return 0 ;
}
static int F_26 ( const char * T_6 V_87 )
{
return 0 ;
}
static void F_27 ( void )
{
F_28 () ;
F_29 () ;
V_89 = & V_90 ;
}
static int F_30 ( void )
{
F_7 ( L_33 ) ;
return V_89 -> V_91 () ;
}
static int F_31 ( union V_70 * V_50 ,
struct V_47 * V_48 ,
struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_49 * V_49 = F_32 ( V_21 , V_50 -> V_82 . V_57 ) ;
if ( V_49 == NULL ) {
F_7 ( L_34 ,
V_50 -> V_74 . type ) ;
return - 1 ;
}
if ( V_92 ) {
if ( V_48 -> time < V_93 ) {
F_6 ( L_35 V_94
L_36 V_94 L_32 , V_93 ,
V_48 -> time ) ;
V_95 ++ ;
}
V_93 = V_48 -> time ;
return 0 ;
}
if ( V_96 && ! F_33 ( V_48 -> V_59 , V_97 ) )
return 0 ;
V_89 -> F_21 ( V_50 , V_48 , V_19 , V_21 , V_49 ) ;
V_21 -> V_98 . V_99 . V_100 += V_48 -> V_101 ;
return 0 ;
}
static void F_34 ( int T_7 V_87 )
{
V_102 = 1 ;
}
static int F_35 ( struct V_20 * V_21 )
{
int V_103 ;
signal ( V_104 , F_34 ) ;
V_103 = F_36 ( V_21 , & V_105 ) ;
if ( V_92 )
F_6 ( L_37 V_94 L_32 , V_95 ) ;
return V_103 ;
}
static struct V_106 * F_37 ( const char * V_107 ,
struct V_89 * V_108 )
{
struct V_106 * V_109 = malloc ( sizeof( * V_109 ) + strlen ( V_107 ) + 1 ) ;
if ( V_109 != NULL ) {
strcpy ( V_109 -> V_107 , V_107 ) ;
V_109 -> V_108 = V_108 ;
}
return V_109 ;
}
static void F_38 ( struct V_106 * V_109 )
{
free ( V_109 -> V_107 ) ;
free ( V_109 ) ;
}
static void F_39 ( struct V_106 * V_109 )
{
F_40 ( & V_109 -> V_110 , & V_111 ) ;
}
static struct V_106 * F_41 ( const char * V_107 )
{
struct V_106 * V_109 ;
F_42 (s, &script_specs, node)
if ( strcasecmp ( V_109 -> V_107 , V_107 ) == 0 )
return V_109 ;
return NULL ;
}
static struct V_106 * F_43 ( const char * V_107 ,
struct V_89 * V_108 )
{
struct V_106 * V_109 = F_41 ( V_107 ) ;
if ( V_109 )
return V_109 ;
V_109 = F_37 ( V_107 , V_108 ) ;
if ( ! V_109 )
goto V_112;
F_39 ( V_109 ) ;
return V_109 ;
V_112:
F_38 ( V_109 ) ;
return NULL ;
}
int F_44 ( const char * V_107 , struct V_89 * V_108 )
{
struct V_106 * V_109 ;
V_109 = F_41 ( V_107 ) ;
if ( V_109 )
return - 1 ;
V_109 = F_43 ( V_107 , V_108 ) ;
if ( ! V_109 )
return - 1 ;
return 0 ;
}
static struct V_89 * F_45 ( const char * V_107 )
{
struct V_106 * V_109 = F_41 ( V_107 ) ;
if ( ! V_109 )
return NULL ;
return V_109 -> V_108 ;
}
static void F_46 ( void )
{
struct V_106 * V_109 ;
fprintf ( V_113 , L_32 ) ;
fprintf ( V_113 , L_38
L_39 ) ;
F_42 (s, &script_specs, node)
fprintf ( V_113 , L_40 , V_109 -> V_107 , V_109 -> V_108 -> V_65 ) ;
fprintf ( V_113 , L_32 ) ;
}
static int F_47 ( const struct V_114 * T_8 V_115 ,
const char * V_10 , int T_9 V_115 )
{
char V_107 [ V_116 ] ;
const char * T_3 , * V_117 ;
int V_118 ;
if ( strcmp ( V_10 , L_41 ) == 0 ) {
F_46 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_118 = T_3 - V_10 ;
if ( V_118 >= V_116 ) {
fprintf ( V_113 , L_42 ) ;
return - 1 ;
}
strncpy ( V_107 , V_10 , V_118 ) ;
V_107 [ V_118 ] = '\0' ;
V_89 = F_45 ( V_107 ) ;
if ( ! V_89 ) {
fprintf ( V_113 , L_42 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_117 = strrchr ( T_3 , '.' ) ;
if ( ! V_117 ) {
fprintf ( V_113 , L_43 ) ;
return - 1 ;
}
V_89 = F_45 ( ++ V_117 ) ;
if ( ! V_89 ) {
fprintf ( V_113 , L_43 ) ;
return - 1 ;
}
}
V_119 = F_48 ( T_3 ) ;
return 0 ;
}
static int F_49 ( const struct V_114 * T_8 V_115 ,
const char * V_120 , int T_9 V_115 )
{
char * V_121 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_122 ) ;
int V_1 ;
int V_123 = 0 ;
char * V_10 = F_48 ( V_120 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_124 ;
V_121 = strchr ( V_10 , ':' ) ;
if ( V_121 ) {
* V_121 = '\0' ;
V_121 ++ ;
if ( ! strcmp ( V_10 , L_44 ) )
type = V_125 ;
else if ( ! strcmp ( V_10 , L_45 ) )
type = V_66 ;
else if ( ! strcmp ( V_10 , L_46 ) )
type = V_63 ;
else if ( ! strcmp ( V_10 , L_47 ) )
type = V_126 ;
else {
fprintf ( V_113 , L_48 ) ;
return - V_23 ;
}
if ( V_3 [ type ] . V_4 )
F_50 ( L_49 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_17 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_46 = false ;
} else {
V_121 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_113 ,
L_50 ) ;
V_123 = - V_23 ;
goto V_127;
}
if ( F_1 () )
F_50 ( L_51 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_17 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_46 = true ;
}
}
V_121 = strtok ( V_121 , L_52 ) ;
while ( V_121 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_121 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_113 , L_53 ) ;
V_123 = - V_23 ;
goto V_127;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_128 & V_9 [ V_7 ] . V_6 ) {
F_50 ( L_54 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_128 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_113 , L_55 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_123 = - V_23 ;
goto V_127;
}
V_3 [ type ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
V_121 = strtok ( NULL , L_52 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_17 == 0 ) {
F_7 ( L_56
L_57 , F_13 ( type ) ) ;
}
}
V_127:
free ( V_10 ) ;
return V_123 ;
}
static int F_51 ( const char * V_129 , const struct V_130 * V_131 )
{
char V_132 [ V_116 ] ;
struct V_133 V_134 ;
sprintf ( V_132 , L_58 , V_129 , V_131 -> V_135 ) ;
if ( V_133 ( V_132 , & V_134 ) )
return 0 ;
return F_52 ( V_134 . V_136 ) ;
}
static struct V_137 * F_53 ( const char * V_65 )
{
struct V_137 * V_109 = F_54 ( sizeof( * V_109 ) ) ;
if ( V_109 != NULL && V_65 )
V_109 -> V_65 = F_48 ( V_65 ) ;
return V_109 ;
}
static void F_55 ( struct V_137 * V_109 )
{
free ( V_109 -> V_65 ) ;
free ( V_109 -> V_138 ) ;
free ( V_109 -> args ) ;
free ( V_109 ) ;
}
static void F_56 ( struct V_137 * V_109 )
{
F_40 ( & V_109 -> V_110 , & V_139 ) ;
}
static struct V_137 * F_57 ( const char * V_65 )
{
struct V_137 * V_109 ;
F_42 (s, &script_descs, node)
if ( strcasecmp ( V_109 -> V_65 , V_65 ) == 0 )
return V_109 ;
return NULL ;
}
static struct V_137 * F_58 ( const char * V_65 )
{
struct V_137 * V_109 = F_57 ( V_65 ) ;
if ( V_109 )
return V_109 ;
V_109 = F_53 ( V_65 ) ;
if ( ! V_109 )
goto V_140;
F_56 ( V_109 ) ;
return V_109 ;
V_140:
F_55 ( V_109 ) ;
return NULL ;
}
static const char * F_59 ( const char * V_10 , const char * V_141 )
{
T_10 V_142 = strlen ( V_141 ) ;
const char * V_143 = V_10 ;
if ( strlen ( V_10 ) > V_142 ) {
V_143 = V_10 + strlen ( V_10 ) - V_142 ;
if ( ! strncmp ( V_143 , V_141 , V_142 ) )
return V_143 ;
}
return NULL ;
}
static char * F_60 ( char * V_10 )
{
int V_118 = strlen ( V_10 ) ;
while ( V_118 && isspace ( * V_10 ) ) {
V_118 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_61 ( struct V_137 * V_144 , const char * V_145 )
{
char line [ V_146 ] , * V_143 ;
T_11 * V_147 ;
V_147 = fopen ( V_145 , L_59 ) ;
if ( ! V_147 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_147 ) ) {
V_143 = F_60 ( line ) ;
if ( strlen ( V_143 ) == 0 )
continue;
if ( * V_143 != '#' )
continue;
V_143 ++ ;
if ( strlen ( V_143 ) && * V_143 == '!' )
continue;
V_143 = F_60 ( V_143 ) ;
if ( strlen ( V_143 ) && V_143 [ strlen ( V_143 ) - 1 ] == '\n' )
V_143 [ strlen ( V_143 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_143 , L_60 , strlen ( L_60 ) ) ) {
V_143 += strlen ( L_60 ) ;
V_144 -> V_138 = F_48 ( F_60 ( V_143 ) ) ;
continue;
}
if ( ! strncmp ( V_143 , L_61 , strlen ( L_61 ) ) ) {
V_143 += strlen ( L_61 ) ;
V_144 -> args = F_48 ( F_60 ( V_143 ) ) ;
continue;
}
}
fclose ( V_147 ) ;
return 0 ;
}
static int F_62 ( const struct V_114 * T_8 V_115 ,
const char * V_109 V_115 , int T_9 V_115 )
{
struct V_130 * V_148 , * V_149 , V_150 , V_151 ;
char V_152 [ V_153 ] ;
T_12 * V_154 , * V_155 ;
char V_156 [ V_153 ] ;
char V_157 [ V_153 ] ;
struct V_137 * V_144 ;
char V_158 [ V_146 ] ;
char * V_159 ;
char * V_10 ;
snprintf ( V_152 , V_153 , L_62 , F_63 () ) ;
V_154 = F_64 ( V_152 ) ;
if ( ! V_154 )
return - 1 ;
F_65 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_157 , V_153 , L_63 , V_152 ,
V_151 . V_135 ) ;
V_155 = F_64 ( V_157 ) ;
if ( ! V_155 )
continue;
F_66 (lang_path, lang_dir, script_dirent, script_next) {
V_159 = F_48 ( V_150 . V_135 ) ;
V_10 = ( char * ) F_59 ( V_159 , V_160 ) ;
if ( V_10 ) {
* V_10 = '\0' ;
V_144 = F_58 ( V_159 ) ;
snprintf ( V_156 , V_153 , L_58 ,
V_157 , V_150 . V_135 ) ;
F_61 ( V_144 , V_156 ) ;
}
free ( V_159 ) ;
}
}
fprintf ( stdout , L_64 ) ;
F_42 (desc, &script_descs, node) {
sprintf ( V_158 , L_65 , V_144 -> V_65 ,
V_144 -> args ? V_144 -> args : L_1 ) ;
fprintf ( stdout , L_66 , V_158 ,
V_144 -> V_138 ? V_144 -> V_138 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_67 ( const char * V_159 , const char * V_141 )
{
struct V_130 * V_148 , * V_149 , V_150 , V_151 ;
char V_152 [ V_153 ] ;
char V_156 [ V_153 ] ;
T_12 * V_154 , * V_155 ;
char V_157 [ V_153 ] ;
char * V_10 , * V_161 ;
char * V_132 = NULL ;
snprintf ( V_152 , V_153 , L_62 , F_63 () ) ;
V_154 = F_64 ( V_152 ) ;
if ( ! V_154 )
return NULL ;
F_65 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_157 , V_153 , L_63 , V_152 ,
V_151 . V_135 ) ;
V_155 = F_64 ( V_157 ) ;
if ( ! V_155 )
continue;
F_66 (lang_path, lang_dir, script_dirent, script_next) {
V_161 = F_48 ( V_150 . V_135 ) ;
V_10 = ( char * ) F_59 ( V_161 , V_141 ) ;
if ( V_10 ) {
* V_10 = '\0' ;
if ( strcmp ( V_161 , V_159 ) )
continue;
snprintf ( V_156 , V_153 , L_58 ,
V_157 , V_150 . V_135 ) ;
V_132 = F_48 ( V_156 ) ;
free ( V_161 ) ;
break;
}
free ( V_161 ) ;
}
}
return V_132 ;
}
static bool F_68 ( const char * V_156 )
{
return F_59 ( V_156 , L_67 ) == NULL ? false : true ;
}
static int F_69 ( char * V_156 )
{
struct V_137 * V_144 ;
int V_162 = 0 ;
char * V_143 ;
V_144 = F_53 ( NULL ) ;
if ( F_61 ( V_144 , V_156 ) )
goto V_127;
if ( ! V_144 -> args )
goto V_127;
for ( V_143 = V_144 -> args ; * V_143 ; V_143 ++ )
if ( * V_143 == '<' )
V_162 ++ ;
V_127:
F_55 ( V_144 ) ;
return V_162 ;
}
static bool F_70 ( int T_4 , const char * * T_5 )
{
char * * V_163 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_163 )
F_71 ( L_68 ) ;
memcpy ( V_163 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_72 ( T_4 , ( const char * * ) V_163 , V_164 ,
NULL , V_165 ) ;
free ( V_163 ) ;
return T_4 != 0 ;
}
int F_73 ( int T_4 , const char * * T_5 , const char * T_13 V_115 )
{
char * V_166 = NULL ;
char * V_167 = NULL ;
struct V_20 * V_21 ;
char * V_156 = NULL ;
const char * * V_163 ;
bool V_168 ;
int V_7 , V_1 , V_169 ;
F_27 () ;
T_4 = F_72 ( T_4 , T_5 , V_170 , V_171 ,
V_165 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_69 , strlen ( L_69 ) ) ) {
V_166 = F_67 ( T_5 [ 1 ] , V_172 ) ;
if ( ! V_166 )
return F_74 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_70 , strlen ( L_70 ) ) ) {
V_167 = F_67 ( T_5 [ 1 ] , V_160 ) ;
if ( ! V_167 ) {
fprintf ( V_113 ,
L_71
L_72 ) ;
return - 1 ;
}
}
F_75 ( F_63 () ) ;
if ( T_4 && ! V_119 && ! V_166 && ! V_167 ) {
int V_173 [ 2 ] ;
int V_174 ;
T_14 V_57 ;
V_166 = F_67 ( T_5 [ 0 ] , V_172 ) ;
V_167 = F_67 ( T_5 [ 0 ] , V_160 ) ;
if ( ! V_166 && ! V_167 ) {
fprintf ( V_113 , L_73
L_74 , T_5 [ 0 ] ) ;
F_76 ( V_171 , V_170 ) ;
}
if ( F_68 ( T_5 [ 0 ] ) ) {
V_174 = T_4 - 1 ;
} else {
int V_175 ;
V_174 = F_69 ( V_167 ) ;
V_175 = ( T_4 - 1 ) - V_174 ;
if ( V_175 < 0 ) {
fprintf ( V_113 , L_75
L_76
L_77 , T_5 [ 0 ] ) ;
F_76 ( V_171 , V_170 ) ;
}
}
if ( F_77 ( V_173 ) < 0 ) {
perror ( L_78 ) ;
exit ( - 1 ) ;
}
V_57 = F_78 () ;
if ( V_57 < 0 ) {
perror ( L_79 ) ;
exit ( - 1 ) ;
}
if ( ! V_57 ) {
V_168 = true ;
V_1 = 0 ;
F_79 ( V_173 [ 1 ] , 1 ) ;
F_80 ( V_173 [ 0 ] ) ;
if ( ! F_68 ( T_5 [ 0 ] ) )
V_168 = ! F_70 ( T_4 - V_174 ,
& T_5 [ V_174 ] ) ;
V_163 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_163 )
F_71 ( L_68 ) ;
V_163 [ V_1 ++ ] = L_80 ;
V_163 [ V_1 ++ ] = V_166 ;
if ( V_168 )
V_163 [ V_1 ++ ] = L_81 ;
V_163 [ V_1 ++ ] = L_82 ;
V_163 [ V_1 ++ ] = L_83 ;
V_163 [ V_1 ++ ] = L_84 ;
for ( V_7 = V_174 + 1 ; V_7 < T_4 ; V_7 ++ )
V_163 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_163 [ V_1 ++ ] = NULL ;
F_81 ( L_80 , ( char * * ) V_163 ) ;
free ( V_163 ) ;
exit ( - 1 ) ;
}
F_79 ( V_173 [ 0 ] , 0 ) ;
F_80 ( V_173 [ 1 ] ) ;
V_163 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_163 )
F_71 ( L_68 ) ;
V_1 = 0 ;
V_163 [ V_1 ++ ] = L_80 ;
V_163 [ V_1 ++ ] = V_167 ;
for ( V_7 = 1 ; V_7 < V_174 + 1 ; V_7 ++ )
V_163 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_163 [ V_1 ++ ] = L_85 ;
V_163 [ V_1 ++ ] = L_84 ;
V_163 [ V_1 ++ ] = NULL ;
F_81 ( L_80 , ( char * * ) V_163 ) ;
free ( V_163 ) ;
exit ( - 1 ) ;
}
if ( V_166 )
V_156 = V_166 ;
if ( V_167 )
V_156 = V_167 ;
if ( V_156 ) {
V_168 = false ;
V_1 = 0 ;
if ( V_166 )
V_168 = ! F_70 ( T_4 - 1 , & T_5 [ 1 ] ) ;
V_163 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_163 )
F_71 ( L_68 ) ;
V_163 [ V_1 ++ ] = L_80 ;
V_163 [ V_1 ++ ] = V_156 ;
if ( V_168 )
V_163 [ V_1 ++ ] = L_81 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_163 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_163 [ V_1 ++ ] = NULL ;
F_81 ( L_80 , ( char * * ) V_163 ) ;
free ( V_163 ) ;
exit ( - 1 ) ;
}
if ( F_82 () < 0 )
return - 1 ;
if ( ! V_119 )
F_83 () ;
V_21 = F_84 ( V_176 , V_177 , 0 , false , & V_105 ) ;
if ( V_21 == NULL )
return - V_124 ;
if ( V_96 ) {
if ( F_85 ( V_21 , V_96 , V_97 ) )
return - 1 ;
}
F_86 ( V_21 , stdout , V_178 ) ;
if ( ! V_27 )
V_29 . V_30 = true ;
else
V_29 . V_30 = false ;
if ( V_179 ) {
struct V_133 V_180 ;
int V_181 ;
if ( F_1 () ) {
fprintf ( V_113 ,
L_86 ) ;
return - 1 ;
}
V_181 = F_87 ( V_176 , V_177 ) ;
if ( V_181 < 0 ) {
perror ( L_87 ) ;
exit ( - 1 ) ;
}
V_169 = F_88 ( V_181 , & V_180 ) ;
if ( V_169 < 0 ) {
perror ( L_88 ) ;
exit ( - 1 ) ;
}
if ( ! V_180 . V_182 ) {
fprintf ( V_113 , L_89 ) ;
exit ( 0 ) ;
}
V_89 = F_45 ( V_179 ) ;
if ( ! V_89 ) {
fprintf ( V_113 , L_42 ) ;
return - 1 ;
}
V_169 = V_89 -> V_183 ( L_90 ) ;
goto V_127;
}
if ( V_119 ) {
V_169 = V_89 -> V_184 ( V_119 , T_4 , T_5 ) ;
if ( V_169 )
goto V_127;
F_7 ( L_91 , V_119 ) ;
}
V_169 = F_11 ( V_21 ) ;
if ( V_169 < 0 )
goto V_127;
V_169 = F_35 ( V_21 ) ;
F_89 ( V_21 ) ;
F_30 () ;
V_127:
return V_169 ;
}
