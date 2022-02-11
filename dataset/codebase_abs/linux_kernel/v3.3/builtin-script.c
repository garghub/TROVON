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
struct V_71 * V_71 ,
struct V_49 * V_49 ,
struct V_11 * V_12 )
{
struct V_72 V_73 ;
T_2 V_74 = V_50 -> V_75 . V_76 & V_77 ;
const char * V_78 , * V_79 ;
printf ( L_28 V_80 , V_48 -> V_81 ) ;
if ( ! F_17 ( V_12 ) )
return;
F_19 ( V_49 , V_71 , V_74 , V_82 ,
V_48 -> V_81 , & V_73 ) ;
if ( ! V_73 . V_83 )
F_19 ( V_49 , V_71 , V_74 , V_84 ,
V_48 -> V_81 , & V_73 ) ;
V_73 . V_59 = V_48 -> V_59 ;
V_73 . V_85 = NULL ;
if ( V_73 . V_83 )
V_73 . V_85 = F_20 ( V_73 . V_83 , V_73 . V_81 , NULL ) ;
if ( F_9 ( V_34 ) ) {
if ( V_73 . V_85 && V_73 . V_85 -> V_65 )
V_78 = V_73 . V_85 -> V_65 ;
else
V_78 = L_1 ;
printf ( L_29 , V_78 ) ;
}
if ( F_9 ( V_35 ) ) {
if ( V_73 . V_83 && V_73 . V_83 -> V_86 && V_73 . V_83 -> V_86 -> V_65 )
V_79 = V_73 . V_83 -> V_86 -> V_65 ;
else
V_79 = L_1 ;
printf ( L_30 , V_79 ) ;
}
}
static void F_21 ( union V_70 * V_50 V_87 ,
struct V_47 * V_48 ,
struct V_18 * V_19 ,
struct V_71 * V_71 ,
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
F_18 ( V_50 , V_48 , V_71 , V_49 , V_12 ) ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_32 ) ;
F_23 ( V_50 , V_48 , V_71 , V_19 ,
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
static int F_31 ( struct V_92 * T_7 V_93 ,
union V_70 * V_50 ,
struct V_47 * V_48 ,
struct V_18 * V_19 ,
struct V_71 * V_71 )
{
struct V_72 V_73 ;
struct V_49 * V_49 = F_32 ( V_71 , V_50 -> V_94 . V_58 ) ;
if ( V_49 == NULL ) {
F_7 ( L_34 ,
V_50 -> V_75 . type ) ;
return - 1 ;
}
if ( V_95 ) {
if ( V_48 -> time < V_96 ) {
F_6 ( L_35 V_97
L_36 V_97 L_32 , V_96 ,
V_48 -> time ) ;
V_98 ++ ;
}
V_96 = V_48 -> time ;
return 0 ;
}
if ( F_33 ( V_50 , V_71 , & V_73 , V_48 , 0 ) < 0 ) {
F_6 ( L_34 ,
V_50 -> V_75 . type ) ;
return - 1 ;
}
if ( V_73 . V_99 )
return 0 ;
if ( V_100 && ! F_34 ( V_48 -> V_59 , V_101 ) )
return 0 ;
V_89 -> F_21 ( V_50 , V_48 , V_19 , V_71 , V_49 ) ;
V_19 -> V_102 . V_103 . V_104 += V_48 -> V_105 ;
return 0 ;
}
static void F_35 ( int T_8 V_87 )
{
V_106 = 1 ;
}
static int F_36 ( struct V_20 * V_21 )
{
int V_107 ;
signal ( V_108 , F_35 ) ;
V_107 = F_37 ( V_21 , & V_109 ) ;
if ( V_95 )
F_6 ( L_37 V_97 L_32 , V_98 ) ;
return V_107 ;
}
static struct V_110 * F_38 ( const char * V_111 ,
struct V_89 * V_112 )
{
struct V_110 * V_113 = malloc ( sizeof( * V_113 ) + strlen ( V_111 ) + 1 ) ;
if ( V_113 != NULL ) {
strcpy ( V_113 -> V_111 , V_111 ) ;
V_113 -> V_112 = V_112 ;
}
return V_113 ;
}
static void F_39 ( struct V_110 * V_113 )
{
F_40 ( & V_113 -> V_114 , & V_115 ) ;
}
static struct V_110 * F_41 ( const char * V_111 )
{
struct V_110 * V_113 ;
F_42 (s, &script_specs, node)
if ( strcasecmp ( V_113 -> V_111 , V_111 ) == 0 )
return V_113 ;
return NULL ;
}
static struct V_110 * F_43 ( const char * V_111 ,
struct V_89 * V_112 )
{
struct V_110 * V_113 = F_41 ( V_111 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_38 ( V_111 , V_112 ) ;
if ( ! V_113 )
return NULL ;
F_39 ( V_113 ) ;
return V_113 ;
}
int F_44 ( const char * V_111 , struct V_89 * V_112 )
{
struct V_110 * V_113 ;
V_113 = F_41 ( V_111 ) ;
if ( V_113 )
return - 1 ;
V_113 = F_43 ( V_111 , V_112 ) ;
if ( ! V_113 )
return - 1 ;
return 0 ;
}
static struct V_89 * F_45 ( const char * V_111 )
{
struct V_110 * V_113 = F_41 ( V_111 ) ;
if ( ! V_113 )
return NULL ;
return V_113 -> V_112 ;
}
static void F_46 ( void )
{
struct V_110 * V_113 ;
fprintf ( V_116 , L_32 ) ;
fprintf ( V_116 , L_38
L_39 ) ;
F_42 (s, &script_specs, node)
fprintf ( V_116 , L_40 , V_113 -> V_111 , V_113 -> V_112 -> V_65 ) ;
fprintf ( V_116 , L_32 ) ;
}
static int F_47 ( const struct V_117 * T_9 V_93 ,
const char * V_10 , int T_10 V_93 )
{
char V_111 [ V_118 ] ;
const char * T_3 , * V_119 ;
int V_120 ;
if ( strcmp ( V_10 , L_41 ) == 0 ) {
F_46 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_120 = T_3 - V_10 ;
if ( V_120 >= V_118 ) {
fprintf ( V_116 , L_42 ) ;
return - 1 ;
}
strncpy ( V_111 , V_10 , V_120 ) ;
V_111 [ V_120 ] = '\0' ;
V_89 = F_45 ( V_111 ) ;
if ( ! V_89 ) {
fprintf ( V_116 , L_42 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_119 = strrchr ( T_3 , '.' ) ;
if ( ! V_119 ) {
fprintf ( V_116 , L_43 ) ;
return - 1 ;
}
V_89 = F_45 ( ++ V_119 ) ;
if ( ! V_89 ) {
fprintf ( V_116 , L_43 ) ;
return - 1 ;
}
}
V_121 = F_48 ( T_3 ) ;
return 0 ;
}
static int F_49 ( const struct V_117 * T_9 V_93 ,
const char * V_122 , int T_10 V_93 )
{
char * V_123 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_124 ) ;
int V_1 ;
int V_125 = 0 ;
char * V_10 = F_48 ( V_122 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_126 ;
V_123 = strchr ( V_10 , ':' ) ;
if ( V_123 ) {
* V_123 = '\0' ;
V_123 ++ ;
if ( ! strcmp ( V_10 , L_44 ) )
type = V_127 ;
else if ( ! strcmp ( V_10 , L_45 ) )
type = V_66 ;
else if ( ! strcmp ( V_10 , L_46 ) )
type = V_63 ;
else if ( ! strcmp ( V_10 , L_47 ) )
type = V_128 ;
else {
fprintf ( V_116 , L_48 ) ;
V_125 = - V_23 ;
goto V_129;
}
if ( V_3 [ type ] . V_4 )
F_50 ( L_49 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_17 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_46 = false ;
} else {
V_123 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_116 ,
L_50 ) ;
V_125 = - V_23 ;
goto V_129;
}
if ( F_1 () )
F_50 ( L_51 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_17 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_46 = true ;
}
}
V_123 = strtok ( V_123 , L_52 ) ;
while ( V_123 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_123 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_116 , L_53 ) ;
V_125 = - V_23 ;
goto V_129;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_130 & V_9 [ V_7 ] . V_6 ) {
F_50 ( L_54 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_130 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_116 , L_55 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_125 = - V_23 ;
goto V_129;
}
V_3 [ type ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
V_123 = strtok ( NULL , L_52 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_17 == 0 ) {
F_7 ( L_56
L_57 , F_13 ( type ) ) ;
}
}
V_129:
free ( V_10 ) ;
return V_125 ;
}
static int F_51 ( const char * V_131 , const struct V_132 * V_133 )
{
char V_134 [ V_118 ] ;
struct V_135 V_136 ;
sprintf ( V_134 , L_58 , V_131 , V_133 -> V_137 ) ;
if ( V_135 ( V_134 , & V_136 ) )
return 0 ;
return F_52 ( V_136 . V_138 ) ;
}
static struct V_139 * F_53 ( const char * V_65 )
{
struct V_139 * V_113 = F_54 ( sizeof( * V_113 ) ) ;
if ( V_113 != NULL && V_65 )
V_113 -> V_65 = F_48 ( V_65 ) ;
return V_113 ;
}
static void F_55 ( struct V_139 * V_113 )
{
free ( V_113 -> V_65 ) ;
free ( V_113 -> V_140 ) ;
free ( V_113 -> args ) ;
free ( V_113 ) ;
}
static void F_56 ( struct V_139 * V_113 )
{
F_40 ( & V_113 -> V_114 , & V_141 ) ;
}
static struct V_139 * F_57 ( const char * V_65 )
{
struct V_139 * V_113 ;
F_42 (s, &script_descs, node)
if ( strcasecmp ( V_113 -> V_65 , V_65 ) == 0 )
return V_113 ;
return NULL ;
}
static struct V_139 * F_58 ( const char * V_65 )
{
struct V_139 * V_113 = F_57 ( V_65 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_53 ( V_65 ) ;
if ( ! V_113 )
goto V_142;
F_56 ( V_113 ) ;
return V_113 ;
V_142:
F_55 ( V_113 ) ;
return NULL ;
}
static const char * F_59 ( const char * V_10 , const char * V_143 )
{
T_11 V_144 = strlen ( V_143 ) ;
const char * V_145 = V_10 ;
if ( strlen ( V_10 ) > V_144 ) {
V_145 = V_10 + strlen ( V_10 ) - V_144 ;
if ( ! strncmp ( V_145 , V_143 , V_144 ) )
return V_145 ;
}
return NULL ;
}
static char * F_60 ( char * V_10 )
{
int V_120 = strlen ( V_10 ) ;
while ( V_120 && isspace ( * V_10 ) ) {
V_120 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_61 ( struct V_139 * V_146 , const char * V_147 )
{
char line [ V_148 ] , * V_145 ;
T_12 * V_149 ;
V_149 = fopen ( V_147 , L_59 ) ;
if ( ! V_149 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_149 ) ) {
V_145 = F_60 ( line ) ;
if ( strlen ( V_145 ) == 0 )
continue;
if ( * V_145 != '#' )
continue;
V_145 ++ ;
if ( strlen ( V_145 ) && * V_145 == '!' )
continue;
V_145 = F_60 ( V_145 ) ;
if ( strlen ( V_145 ) && V_145 [ strlen ( V_145 ) - 1 ] == '\n' )
V_145 [ strlen ( V_145 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_145 , L_60 , strlen ( L_60 ) ) ) {
V_145 += strlen ( L_60 ) ;
V_146 -> V_140 = F_48 ( F_60 ( V_145 ) ) ;
continue;
}
if ( ! strncmp ( V_145 , L_61 , strlen ( L_61 ) ) ) {
V_145 += strlen ( L_61 ) ;
V_146 -> args = F_48 ( F_60 ( V_145 ) ) ;
continue;
}
}
fclose ( V_149 ) ;
return 0 ;
}
static char * F_62 ( struct V_132 * V_150 , const char * V_143 )
{
char * V_151 , * V_10 ;
V_151 = F_48 ( V_150 -> V_137 ) ;
if ( ! V_151 )
return NULL ;
V_10 = ( char * ) F_59 ( V_151 , V_143 ) ;
if ( ! V_10 ) {
free ( V_151 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_151 ;
}
static int F_63 ( const struct V_117 * T_9 V_93 ,
const char * V_113 V_93 , int T_10 V_93 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_159 [ V_156 ] ;
char V_160 [ V_156 ] ;
struct V_139 * V_146 ;
char V_161 [ V_148 ] ;
char * V_151 ;
snprintf ( V_155 , V_156 , L_62 , F_64 () ) ;
V_157 = F_65 ( V_155 ) ;
if ( ! V_157 )
return - 1 ;
F_66 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_63 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_65 ( V_160 ) ;
if ( ! V_158 )
continue;
F_67 (lang_path, lang_dir, script_dirent, script_next) {
V_151 = F_62 ( & V_150 , V_162 ) ;
if ( V_151 ) {
V_146 = F_58 ( V_151 ) ;
snprintf ( V_159 , V_156 , L_58 ,
V_160 , V_150 . V_137 ) ;
F_61 ( V_146 , V_159 ) ;
free ( V_151 ) ;
}
}
}
fprintf ( stdout , L_64 ) ;
F_42 (desc, &script_descs, node) {
sprintf ( V_161 , L_65 , V_146 -> V_65 ,
V_146 -> args ? V_146 -> args : L_1 ) ;
fprintf ( stdout , L_66 , V_161 ,
V_146 -> V_140 ? V_146 -> V_140 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_68 ( const char * V_151 , const char * V_143 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
char V_159 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_160 [ V_156 ] ;
char * V_163 ;
snprintf ( V_155 , V_156 , L_62 , F_64 () ) ;
V_157 = F_65 ( V_155 ) ;
if ( ! V_157 )
return NULL ;
F_66 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_63 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_65 ( V_160 ) ;
if ( ! V_158 )
continue;
F_67 (lang_path, lang_dir, script_dirent, script_next) {
V_163 = F_62 ( & V_150 , V_143 ) ;
if ( V_163 && ! strcmp ( V_151 , V_163 ) ) {
free ( V_163 ) ;
F_69 ( V_158 ) ;
F_69 ( V_157 ) ;
snprintf ( V_159 , V_156 , L_58 ,
V_160 , V_150 . V_137 ) ;
return F_48 ( V_159 ) ;
}
free ( V_163 ) ;
}
F_69 ( V_158 ) ;
}
F_69 ( V_157 ) ;
return NULL ;
}
static bool F_70 ( const char * V_159 )
{
return F_59 ( V_159 , L_67 ) == NULL ? false : true ;
}
static int F_71 ( char * V_159 )
{
struct V_139 * V_146 ;
int V_164 = 0 ;
char * V_145 ;
V_146 = F_53 ( NULL ) ;
if ( F_61 ( V_146 , V_159 ) )
goto V_129;
if ( ! V_146 -> args )
goto V_129;
for ( V_145 = V_146 -> args ; * V_145 ; V_145 ++ )
if ( * V_145 == '<' )
V_164 ++ ;
V_129:
F_55 ( V_146 ) ;
return V_164 ;
}
static bool F_72 ( int T_4 , const char * * T_5 )
{
char * * V_165 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_165 )
F_73 ( L_68 ) ;
memcpy ( V_165 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_74 ( T_4 , ( const char * * ) V_165 , V_166 ,
NULL , V_167 ) ;
free ( V_165 ) ;
return T_4 != 0 ;
}
int F_75 ( int T_4 , const char * * T_5 , const char * T_14 V_93 )
{
char * V_168 = NULL ;
char * V_169 = NULL ;
struct V_20 * V_21 ;
char * V_159 = NULL ;
const char * * V_165 ;
int V_7 , V_1 , V_170 ;
F_27 () ;
T_4 = F_74 ( T_4 , T_5 , V_171 , V_172 ,
V_167 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_69 , strlen ( L_69 ) ) ) {
V_168 = F_68 ( T_5 [ 1 ] , V_173 ) ;
if ( ! V_168 )
return F_76 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_70 , strlen ( L_70 ) ) ) {
V_169 = F_68 ( T_5 [ 1 ] , V_162 ) ;
if ( ! V_169 ) {
fprintf ( V_116 ,
L_71
L_72 ) ;
return - 1 ;
}
}
F_77 ( F_64 () ) ;
if ( T_4 && ! V_121 && ! V_168 && ! V_169 ) {
int V_174 [ 2 ] ;
int V_175 ;
T_15 V_57 ;
V_168 = F_68 ( T_5 [ 0 ] , V_173 ) ;
V_169 = F_68 ( T_5 [ 0 ] , V_162 ) ;
if ( ! V_168 && ! V_169 ) {
fprintf ( V_116 , L_73
L_74 , T_5 [ 0 ] ) ;
F_78 ( V_172 , V_171 ) ;
}
if ( F_70 ( T_5 [ 0 ] ) ) {
V_175 = T_4 - 1 ;
} else {
int V_176 ;
V_175 = F_71 ( V_169 ) ;
V_176 = ( T_4 - 1 ) - V_175 ;
if ( V_176 < 0 ) {
fprintf ( V_116 , L_75
L_76
L_77 , T_5 [ 0 ] ) ;
F_78 ( V_172 , V_171 ) ;
}
}
if ( F_79 ( V_174 ) < 0 ) {
perror ( L_78 ) ;
exit ( - 1 ) ;
}
V_57 = F_80 () ;
if ( V_57 < 0 ) {
perror ( L_79 ) ;
exit ( - 1 ) ;
}
if ( ! V_57 ) {
V_1 = 0 ;
F_81 ( V_174 [ 1 ] , 1 ) ;
F_82 ( V_174 [ 0 ] ) ;
if ( F_70 ( T_5 [ 0 ] ) ) {
V_177 = true ;
} else if ( ! V_177 ) {
V_177 = ! F_72 ( T_4 - V_175 ,
& T_5 [ V_175 ] ) ;
}
V_165 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_73 ( L_68 ) ;
V_165 [ V_1 ++ ] = L_80 ;
V_165 [ V_1 ++ ] = V_168 ;
if ( V_177 )
V_165 [ V_1 ++ ] = L_81 ;
V_165 [ V_1 ++ ] = L_82 ;
V_165 [ V_1 ++ ] = L_83 ;
V_165 [ V_1 ++ ] = L_84 ;
for ( V_7 = V_175 + 1 ; V_7 < T_4 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = NULL ;
F_83 ( L_80 , ( char * * ) V_165 ) ;
free ( V_165 ) ;
exit ( - 1 ) ;
}
F_81 ( V_174 [ 0 ] , 0 ) ;
F_82 ( V_174 [ 1 ] ) ;
V_165 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_73 ( L_68 ) ;
V_1 = 0 ;
V_165 [ V_1 ++ ] = L_80 ;
V_165 [ V_1 ++ ] = V_169 ;
for ( V_7 = 1 ; V_7 < V_175 + 1 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = L_85 ;
V_165 [ V_1 ++ ] = L_84 ;
V_165 [ V_1 ++ ] = NULL ;
F_83 ( L_80 , ( char * * ) V_165 ) ;
free ( V_165 ) ;
exit ( - 1 ) ;
}
if ( V_168 )
V_159 = V_168 ;
if ( V_169 )
V_159 = V_169 ;
if ( V_159 ) {
V_1 = 0 ;
if ( ! V_168 )
V_177 = false ;
else if ( ! V_177 )
V_177 = ! F_72 ( T_4 - 1 , & T_5 [ 1 ] ) ;
V_165 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_73 ( L_68 ) ;
V_165 [ V_1 ++ ] = L_80 ;
V_165 [ V_1 ++ ] = V_159 ;
if ( V_177 )
V_165 [ V_1 ++ ] = L_81 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = NULL ;
F_83 ( L_80 , ( char * * ) V_165 ) ;
free ( V_165 ) ;
exit ( - 1 ) ;
}
if ( F_84 () < 0 )
return - 1 ;
if ( ! V_121 )
F_85 () ;
V_21 = F_86 ( V_178 , V_179 , 0 , false , & V_109 ) ;
if ( V_21 == NULL )
return - V_126 ;
if ( V_100 ) {
if ( F_87 ( V_21 , V_100 , V_101 ) )
return - 1 ;
}
F_88 ( V_21 , stdout , V_180 ) ;
if ( ! V_27 )
V_29 . V_30 = true ;
else
V_29 . V_30 = false ;
if ( V_181 ) {
struct V_135 V_182 ;
int V_183 ;
if ( F_1 () ) {
fprintf ( V_116 ,
L_86 ) ;
return - 1 ;
}
V_183 = F_89 ( V_21 -> V_147 , V_179 ) ;
if ( V_183 < 0 ) {
perror ( L_87 ) ;
exit ( - 1 ) ;
}
V_170 = F_90 ( V_183 , & V_182 ) ;
if ( V_170 < 0 ) {
perror ( L_88 ) ;
exit ( - 1 ) ;
}
if ( ! V_182 . V_184 ) {
fprintf ( V_116 , L_89 ) ;
exit ( 0 ) ;
}
V_89 = F_45 ( V_181 ) ;
if ( ! V_89 ) {
fprintf ( V_116 , L_42 ) ;
return - 1 ;
}
V_170 = V_89 -> V_185 ( L_90 ) ;
goto V_129;
}
if ( V_121 ) {
V_170 = V_89 -> V_186 ( V_121 , T_4 , T_5 ) ;
if ( V_170 )
goto V_129;
F_7 ( L_91 , V_121 ) ;
}
V_170 = F_11 ( V_21 ) ;
if ( V_170 < 0 )
goto V_129;
V_170 = F_36 ( V_21 ) ;
F_91 ( V_21 ) ;
F_30 () ;
V_129:
return V_170 ;
}
