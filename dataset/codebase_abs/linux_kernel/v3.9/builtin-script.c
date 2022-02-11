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
struct V_15 * V_16 = & V_12 -> V_16 ;
int type = V_16 -> type ;
const char * V_17 ;
if ( V_16 -> V_13 & V_13 )
return 0 ;
if ( V_3 [ type ] . V_4 ) {
V_17 = F_5 ( V_12 ) ;
F_6 ( L_2
L_3 ,
V_17 , V_14 , F_2 ( V_6 ) ) ;
return - 1 ;
}
V_3 [ type ] . V_18 &= ~ V_6 ;
V_17 = F_5 ( V_12 ) ;
F_7 ( L_2
L_4 ,
V_17 , V_14 , F_2 ( V_6 ) ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 ,
struct V_19 * V_20 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_21 ) &&
! F_10 ( V_20 , L_5 ) )
return - V_22 ;
if ( F_9 ( V_23 ) ) {
if ( F_4 ( V_12 , V_24 , L_6 ,
V_25 ) )
return - V_22 ;
if ( ! V_26 &&
! ( V_16 -> V_13 & V_27 ) )
V_28 . V_29 = false ;
}
if ( F_9 ( V_30 ) &&
F_4 ( V_12 , V_31 , L_7 ,
V_32 ) )
return - V_22 ;
if ( F_9 ( V_33 ) && ! F_9 ( V_23 ) && ! F_9 ( V_30 ) ) {
F_6 ( L_8
L_9
L_10 ) ;
return - V_22 ;
}
if ( F_9 ( V_34 ) && ! F_9 ( V_33 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_22 ;
}
if ( F_9 ( V_35 ) && ! F_9 ( V_23 ) && ! F_9 ( V_30 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_22 ;
}
if ( ( F_9 ( V_36 ) || F_9 ( V_37 ) ) &&
F_4 ( V_12 , V_38 , L_15 ,
V_39 | V_40 ) )
return - V_22 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_41 , L_16 ,
V_42 ) )
return - V_22 ;
if ( F_9 ( V_43 ) &&
F_4 ( V_12 , V_44 , L_17 ,
V_45 ) )
return - V_22 ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_12 ( V_20 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_46 ) {
F_6 ( L_18
L_19 ,
F_13 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_18 &&
F_8 ( V_12 , V_20 ) )
return - 1 ;
}
return 0 ;
}
static void F_14 ( struct V_47 * V_48 ,
struct V_49 * V_49 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
const char * V_17 = NULL ;
unsigned long V_50 ;
unsigned long V_51 ;
unsigned long long V_52 ;
if ( F_9 ( V_53 ) ) {
if ( V_54 )
printf ( L_20 , V_49 -> V_55 ) ;
else if ( F_9 ( V_23 ) && V_28 . V_29 )
printf ( L_21 , V_49 -> V_55 ) ;
else
printf ( L_22 , V_49 -> V_55 ) ;
}
if ( F_9 ( V_36 ) && F_9 ( V_37 ) )
printf ( L_23 , V_48 -> V_56 , V_48 -> V_57 ) ;
else if ( F_9 ( V_36 ) )
printf ( L_24 , V_48 -> V_56 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_48 -> V_57 ) ;
if ( F_9 ( V_43 ) ) {
if ( V_54 )
printf ( L_25 , V_48 -> V_58 ) ;
else
printf ( L_26 , V_48 -> V_58 ) ;
}
if ( F_9 ( TIME ) ) {
V_52 = V_48 -> time ;
V_50 = V_52 / V_59 ;
V_52 -= V_50 * V_59 ;
V_51 = V_52 / V_60 ;
printf ( L_27 , V_50 , V_51 ) ;
}
if ( F_9 ( V_61 ) ) {
V_17 = F_5 ( V_12 ) ;
printf ( L_28 , V_17 ? V_17 : L_29 ) ;
}
}
static bool F_15 ( struct V_15 * V_16 )
{
return ( ( V_16 -> type == V_62 ) &&
( V_16 -> V_63 & V_64 ) &&
( V_16 -> V_65 == 1 ) ) ;
}
static bool F_16 ( struct V_15 * V_16 )
{
if ( ( V_16 -> type == V_66 ) &&
( ( V_16 -> V_63 == V_67 ) ||
( V_16 -> V_63 == V_68 ) ||
( V_16 -> V_63 == V_69 ) ) )
return true ;
if ( F_15 ( V_16 ) )
return true ;
return false ;
}
static void F_17 ( union V_70 * V_71 ,
struct V_47 * V_48 ,
struct V_72 * V_72 ,
struct V_49 * V_49 ,
struct V_15 * V_16 )
{
struct V_73 V_74 ;
T_2 V_75 = V_71 -> V_76 . V_77 & V_78 ;
printf ( L_30 V_79 , V_48 -> V_80 ) ;
if ( ! F_16 ( V_16 ) )
return;
F_18 ( V_49 , V_72 , V_75 , V_81 ,
V_48 -> V_80 , & V_74 ) ;
if ( ! V_74 . V_82 )
F_18 ( V_49 , V_72 , V_75 , V_83 ,
V_48 -> V_80 , & V_74 ) ;
V_74 . V_58 = V_48 -> V_58 ;
V_74 . V_84 = NULL ;
if ( V_74 . V_82 )
V_74 . V_84 = F_19 ( V_74 . V_82 , V_74 . V_80 , NULL ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_20 ( V_74 . V_84 , & V_74 , stdout ) ;
else
F_21 ( V_74 . V_84 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_22 ( V_74 . V_82 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_23 ( union V_70 * V_71 ,
struct V_47 * V_48 ,
struct V_11 * V_12 ,
struct V_72 * V_72 ,
struct V_49 * V_49 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_24 ( V_12 , V_71 , V_48 , V_72 ,
F_9 ( V_33 ) , F_9 ( V_35 ) ,
F_9 ( V_34 ) ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_30 ) )
F_17 ( V_71 , V_48 , V_72 , V_49 , V_16 ) ;
printf ( L_34 ) ;
}
static void F_25 ( union V_70 * V_71 , struct V_47 * V_48 ,
struct V_11 * V_12 , struct V_72 * V_72 ,
struct V_73 * V_74 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
struct V_49 * V_49 = V_74 -> V_49 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_14 ( V_48 , V_49 , V_12 ) ;
if ( F_15 ( V_16 ) ) {
F_23 ( V_71 , V_48 , V_12 , V_72 , V_49 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_26 ( V_12 -> V_85 , V_48 -> V_58 ,
V_48 -> V_86 , V_48 -> V_87 ) ;
if ( F_9 ( V_30 ) )
F_17 ( V_71 , V_48 , V_72 , V_49 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_24 ( V_12 , V_71 , V_48 , V_72 ,
F_9 ( V_33 ) , F_9 ( V_35 ) ,
F_9 ( V_34 ) ) ;
}
printf ( L_34 ) ;
}
static int F_27 ( const char * T_3 V_88 ,
int T_4 V_88 ,
const char * * T_5 V_88 )
{
return 0 ;
}
static int F_28 ( void )
{
return 0 ;
}
static int F_29 ( struct V_89 * V_89 V_88 ,
const char * T_6 V_88 )
{
return 0 ;
}
static void F_30 ( void )
{
F_31 () ;
F_32 () ;
V_90 = & V_91 ;
}
static int F_33 ( void )
{
F_7 ( L_36 ) ;
return V_90 -> V_92 () ;
}
static int F_34 ( struct V_93 * T_7 V_88 ,
union V_70 * V_71 ,
struct V_47 * V_48 ,
struct V_11 * V_12 ,
struct V_72 * V_72 )
{
struct V_73 V_74 ;
struct V_49 * V_49 = F_35 ( V_72 , V_71 -> V_94 . V_57 ) ;
if ( V_49 == NULL ) {
F_7 ( L_37 ,
V_71 -> V_76 . type ) ;
return - 1 ;
}
if ( V_95 ) {
if ( V_48 -> time < V_96 ) {
F_6 ( L_38 V_97
L_39 V_97 L_34 , V_96 ,
V_48 -> time ) ;
V_98 ++ ;
}
V_96 = V_48 -> time ;
return 0 ;
}
if ( F_36 ( V_71 , V_72 , & V_74 , V_48 , 0 ) < 0 ) {
F_6 ( L_37 ,
V_71 -> V_76 . type ) ;
return - 1 ;
}
if ( V_74 . V_99 )
return 0 ;
if ( V_100 && ! F_37 ( V_48 -> V_58 , V_101 ) )
return 0 ;
V_90 -> F_25 ( V_71 , V_48 , V_12 , V_72 , & V_74 ) ;
V_12 -> V_102 . V_103 . V_104 += V_48 -> V_105 ;
return 0 ;
}
static void F_38 ( int T_8 V_88 )
{
V_106 = 1 ;
}
static int F_39 ( struct V_19 * V_20 )
{
int V_107 ;
signal ( V_108 , F_38 ) ;
V_107 = F_40 ( V_20 , & V_109 ) ;
if ( V_95 )
F_6 ( L_40 V_97 L_34 , V_98 ) ;
return V_107 ;
}
static struct V_110 * F_41 ( const char * V_111 ,
struct V_90 * V_112 )
{
struct V_110 * V_113 = malloc ( sizeof( * V_113 ) + strlen ( V_111 ) + 1 ) ;
if ( V_113 != NULL ) {
strcpy ( V_113 -> V_111 , V_111 ) ;
V_113 -> V_112 = V_112 ;
}
return V_113 ;
}
static void F_42 ( struct V_110 * V_113 )
{
F_43 ( & V_113 -> V_114 , & V_115 ) ;
}
static struct V_110 * F_44 ( const char * V_111 )
{
struct V_110 * V_113 ;
F_45 (s, &script_specs, node)
if ( strcasecmp ( V_113 -> V_111 , V_111 ) == 0 )
return V_113 ;
return NULL ;
}
static struct V_110 * F_46 ( const char * V_111 ,
struct V_90 * V_112 )
{
struct V_110 * V_113 = F_44 ( V_111 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_41 ( V_111 , V_112 ) ;
if ( ! V_113 )
return NULL ;
F_42 ( V_113 ) ;
return V_113 ;
}
int F_47 ( const char * V_111 , struct V_90 * V_112 )
{
struct V_110 * V_113 ;
V_113 = F_44 ( V_111 ) ;
if ( V_113 )
return - 1 ;
V_113 = F_46 ( V_111 , V_112 ) ;
if ( ! V_113 )
return - 1 ;
return 0 ;
}
static struct V_90 * F_48 ( const char * V_111 )
{
struct V_110 * V_113 = F_44 ( V_111 ) ;
if ( ! V_113 )
return NULL ;
return V_113 -> V_112 ;
}
static void F_49 ( void )
{
struct V_110 * V_113 ;
fprintf ( V_116 , L_34 ) ;
fprintf ( V_116 , L_41
L_42 ) ;
F_45 (s, &script_specs, node)
fprintf ( V_116 , L_43 , V_113 -> V_111 , V_113 -> V_112 -> V_117 ) ;
fprintf ( V_116 , L_34 ) ;
}
static int F_50 ( const struct V_118 * T_9 V_88 ,
const char * V_10 , int T_10 V_88 )
{
char V_111 [ V_119 ] ;
const char * T_3 , * V_120 ;
int V_121 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_49 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_121 = T_3 - V_10 ;
if ( V_121 >= V_119 ) {
fprintf ( V_116 , L_45 ) ;
return - 1 ;
}
strncpy ( V_111 , V_10 , V_121 ) ;
V_111 [ V_121 ] = '\0' ;
V_90 = F_48 ( V_111 ) ;
if ( ! V_90 ) {
fprintf ( V_116 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_120 = strrchr ( T_3 , '.' ) ;
if ( ! V_120 ) {
fprintf ( V_116 , L_46 ) ;
return - 1 ;
}
V_90 = F_48 ( ++ V_120 ) ;
if ( ! V_90 ) {
fprintf ( V_116 , L_46 ) ;
return - 1 ;
}
}
V_122 = F_51 ( T_3 ) ;
return 0 ;
}
static int F_52 ( const struct V_118 * T_9 V_88 ,
const char * V_123 , int T_10 V_88 )
{
char * V_124 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_125 = 0 ;
char * V_10 = F_51 ( V_123 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_126 ;
V_124 = strchr ( V_10 , ':' ) ;
if ( V_124 ) {
* V_124 = '\0' ;
V_124 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_62 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_66 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_127 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_128 ;
else {
fprintf ( V_116 , L_51 ) ;
V_125 = - V_22 ;
goto V_129;
}
if ( V_3 [ type ] . V_4 )
F_53 ( L_52 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_46 = false ;
} else {
V_124 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_116 ,
L_53 ) ;
V_125 = - V_22 ;
goto V_129;
}
if ( F_1 () )
F_53 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_46 = true ;
}
}
V_124 = strtok ( V_124 , L_55 ) ;
while ( V_124 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_124 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_116 , L_56 ) ;
V_125 = - V_22 ;
goto V_129;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_130 & V_9 [ V_7 ] . V_6 ) {
F_53 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_130 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_116 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_125 = - V_22 ;
goto V_129;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_124 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_59
L_60 , F_13 ( type ) ) ;
}
}
V_129:
free ( V_10 ) ;
return V_125 ;
}
static int F_54 ( const char * V_131 , const struct V_132 * V_133 )
{
char V_134 [ V_119 ] ;
struct V_135 V_136 ;
sprintf ( V_134 , L_61 , V_131 , V_133 -> V_137 ) ;
if ( V_135 ( V_134 , & V_136 ) )
return 0 ;
return F_55 ( V_136 . V_138 ) ;
}
static struct V_139 * F_56 ( const char * V_117 )
{
struct V_139 * V_113 = F_57 ( sizeof( * V_113 ) ) ;
if ( V_113 != NULL && V_117 )
V_113 -> V_117 = F_51 ( V_117 ) ;
return V_113 ;
}
static void F_58 ( struct V_139 * V_113 )
{
free ( V_113 -> V_117 ) ;
free ( V_113 -> V_140 ) ;
free ( V_113 -> args ) ;
free ( V_113 ) ;
}
static void F_59 ( struct V_139 * V_113 )
{
F_43 ( & V_113 -> V_114 , & V_141 ) ;
}
static struct V_139 * F_60 ( const char * V_117 )
{
struct V_139 * V_113 ;
F_45 (s, &script_descs, node)
if ( strcasecmp ( V_113 -> V_117 , V_117 ) == 0 )
return V_113 ;
return NULL ;
}
static struct V_139 * F_61 ( const char * V_117 )
{
struct V_139 * V_113 = F_60 ( V_117 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_56 ( V_117 ) ;
if ( ! V_113 )
goto V_142;
F_59 ( V_113 ) ;
return V_113 ;
V_142:
F_58 ( V_113 ) ;
return NULL ;
}
static const char * F_62 ( const char * V_10 , const char * V_143 )
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
static int F_63 ( struct V_139 * V_146 , const char * V_147 )
{
char line [ V_148 ] , * V_145 ;
T_12 * V_149 ;
V_149 = fopen ( V_147 , L_62 ) ;
if ( ! V_149 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_149 ) ) {
V_145 = F_64 ( line ) ;
if ( strlen ( V_145 ) == 0 )
continue;
if ( * V_145 != '#' )
continue;
V_145 ++ ;
if ( strlen ( V_145 ) && * V_145 == '!' )
continue;
V_145 = F_64 ( V_145 ) ;
if ( strlen ( V_145 ) && V_145 [ strlen ( V_145 ) - 1 ] == '\n' )
V_145 [ strlen ( V_145 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_145 , L_63 , strlen ( L_63 ) ) ) {
V_145 += strlen ( L_63 ) ;
V_146 -> V_140 = F_51 ( F_64 ( V_145 ) ) ;
continue;
}
if ( ! strncmp ( V_145 , L_64 , strlen ( L_64 ) ) ) {
V_145 += strlen ( L_64 ) ;
V_146 -> args = F_51 ( F_64 ( V_145 ) ) ;
continue;
}
}
fclose ( V_149 ) ;
return 0 ;
}
static char * F_65 ( struct V_132 * V_150 , const char * V_143 )
{
char * V_151 , * V_10 ;
V_151 = F_51 ( V_150 -> V_137 ) ;
if ( ! V_151 )
return NULL ;
V_10 = ( char * ) F_62 ( V_151 , V_143 ) ;
if ( ! V_10 ) {
free ( V_151 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_151 ;
}
static int F_66 ( const struct V_118 * T_9 V_88 ,
const char * V_113 V_88 ,
int T_10 V_88 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_159 [ V_156 ] ;
char V_160 [ V_156 ] ;
struct V_139 * V_146 ;
char V_161 [ V_148 ] ;
char * V_151 ;
snprintf ( V_155 , V_156 , L_65 , F_67 () ) ;
V_157 = F_68 ( V_155 ) ;
if ( ! V_157 )
return - 1 ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_66 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_68 ( V_160 ) ;
if ( ! V_158 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_151 = F_65 ( & V_150 , V_162 ) ;
if ( V_151 ) {
V_146 = F_61 ( V_151 ) ;
snprintf ( V_159 , V_156 , L_61 ,
V_160 , V_150 . V_137 ) ;
F_63 ( V_146 , V_159 ) ;
free ( V_151 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_45 (desc, &script_descs, node) {
sprintf ( V_161 , L_68 , V_146 -> V_117 ,
V_146 -> args ? V_146 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_161 ,
V_146 -> V_140 ? V_146 -> V_140 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_71 ( char * V_163 , char * V_164 ,
struct V_19 * V_20 )
{
char V_147 [ V_156 ] , V_17 [ 128 ] ;
char line [ V_148 ] , * V_145 ;
struct V_11 * V_165 ;
int V_166 , V_121 ;
T_12 * V_149 ;
sprintf ( V_147 , L_70 , V_163 , V_164 ) ;
V_149 = fopen ( V_147 , L_62 ) ;
if ( ! V_149 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_149 ) ) {
V_145 = F_64 ( line ) ;
if ( * V_145 == '#' )
continue;
while ( strlen ( V_145 ) ) {
V_145 = strstr ( V_145 , L_71 ) ;
if ( ! V_145 )
break;
V_145 += 2 ;
V_145 = F_64 ( V_145 ) ;
V_121 = strcspn ( V_145 , L_72 ) ;
if ( ! V_121 )
break;
snprintf ( V_17 , V_121 + 1 , L_73 , V_145 ) ;
V_166 = 0 ;
F_45 (pos,
&session->evlist->entries, node) {
if ( ! strcmp ( F_5 ( V_165 ) , V_17 ) ) {
V_166 = 1 ;
break;
}
}
if ( ! V_166 ) {
fclose ( V_149 ) ;
return - 1 ;
}
}
}
fclose ( V_149 ) ;
return 0 ;
}
int F_72 ( char * * V_167 , char * * V_168 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] , V_160 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
struct V_19 * V_20 ;
char * V_169 ;
int V_7 = 0 ;
V_20 = F_73 ( V_170 , V_171 , 0 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_155 , V_156 , L_65 , F_67 () ) ;
V_157 = F_68 ( V_155 ) ;
if ( ! V_157 ) {
F_74 ( V_20 ) ;
return - 1 ;
}
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_61 , V_155 ,
V_154 . V_137 ) ;
#ifdef F_75
if ( strstr ( V_160 , L_74 ) )
continue;
#endif
#ifdef F_76
if ( strstr ( V_160 , L_75 ) )
continue;
#endif
V_158 = F_68 ( V_160 ) ;
if ( ! V_158 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_150 . V_137 , L_76 ) )
continue;
sprintf ( V_168 [ V_7 ] , L_61 , V_160 ,
V_150 . V_137 ) ;
V_169 = strchr ( V_150 . V_137 , '.' ) ;
snprintf ( V_167 [ V_7 ] ,
( V_169 - V_150 . V_137 ) + 1 ,
L_73 , V_150 . V_137 ) ;
if ( F_71 ( V_160 ,
V_167 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_77 ( V_158 ) ;
}
F_77 ( V_157 ) ;
F_74 ( V_20 ) ;
return V_7 ;
}
static char * F_78 ( const char * V_151 , const char * V_143 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
char V_159 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_160 [ V_156 ] ;
char * V_172 ;
snprintf ( V_155 , V_156 , L_65 , F_67 () ) ;
V_157 = F_68 ( V_155 ) ;
if ( ! V_157 )
return NULL ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_66 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_68 ( V_160 ) ;
if ( ! V_158 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_172 = F_65 ( & V_150 , V_143 ) ;
if ( V_172 && ! strcmp ( V_151 , V_172 ) ) {
free ( V_172 ) ;
F_77 ( V_158 ) ;
F_77 ( V_157 ) ;
snprintf ( V_159 , V_156 , L_61 ,
V_160 , V_150 . V_137 ) ;
return F_51 ( V_159 ) ;
}
free ( V_172 ) ;
}
F_77 ( V_158 ) ;
}
F_77 ( V_157 ) ;
return NULL ;
}
static bool F_79 ( const char * V_159 )
{
return F_62 ( V_159 , L_77 ) == NULL ? false : true ;
}
static int F_80 ( char * V_159 )
{
struct V_139 * V_146 ;
int V_173 = 0 ;
char * V_145 ;
V_146 = F_56 ( NULL ) ;
if ( F_63 ( V_146 , V_159 ) )
goto V_129;
if ( ! V_146 -> args )
goto V_129;
for ( V_145 = V_146 -> args ; * V_145 ; V_145 ++ )
if ( * V_145 == '<' )
V_173 ++ ;
V_129:
F_58 ( V_146 ) ;
return V_173 ;
}
static int F_81 ( int T_4 , const char * * T_5 )
{
char * * V_174 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_174 ) {
F_6 ( L_78 ) ;
return - 1 ;
}
memcpy ( V_174 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_82 ( T_4 , ( const char * * ) V_174 , V_175 ,
NULL , V_176 ) ;
free ( V_174 ) ;
V_177 = ( T_4 == 0 ) ;
return 0 ;
}
int F_83 ( int T_4 , const char * * T_5 , const char * T_14 V_88 )
{
bool V_178 = false ;
char * V_179 = NULL ;
char * V_180 = NULL ;
struct V_19 * V_20 ;
char * V_159 = NULL ;
const char * * V_174 ;
int V_7 , V_1 , V_181 ;
const struct V_118 V_182 [] = {
F_84 ( 'D' , L_79 , & V_183 ,
L_80 ) ,
F_85 ( 'v' , L_81 , & V_184 ,
L_82 ) ,
F_84 ( 'L' , L_83 , & V_54 ,
L_84 ) ,
F_86 ( 'l' , L_85 , NULL , NULL , L_86 ,
F_66 ) ,
F_87 ( 's' , L_87 , NULL , L_88 ,
L_89 ,
F_50 ) ,
F_88 ( 'g' , L_90 , & V_185 , L_44 ,
L_91 ) ,
F_88 ( 'i' , L_92 , & V_170 , L_93 , L_94 ) ,
F_84 ( 'd' , L_95 , & V_95 ,
L_96 ) ,
F_88 ( 'k' , L_97 , & V_28 . V_186 ,
L_93 , L_98 ) ,
F_88 ( 0 , L_99 , & V_28 . V_187 ,
L_93 , L_100 ) ,
F_84 ( 'G' , L_101 , & V_26 ,
L_102 ) ,
F_88 ( 0 , L_103 , & V_28 . V_188 , L_104 ,
L_105 ) ,
F_87 ( 'f' , L_106 , NULL , L_107 ,
L_108
L_109
L_110
L_111 , F_52 ) ,
F_84 ( 'a' , L_112 , & V_177 ,
L_113 ) ,
F_88 ( 'S' , L_114 , & V_28 . V_189 , L_115 ,
L_116 ) ,
F_88 ( 'C' , L_117 , & V_100 , L_117 , L_118 ) ,
F_88 ( 'c' , L_119 , & V_28 . V_190 , L_120 ,
L_121 ) ,
F_84 ( 'I' , L_122 , & V_178 ,
L_123 ) ,
F_84 ( '\0' , L_124 , & V_28 . V_191 ,
L_125 ) ,
F_89 ()
} ;
const char * const V_192 [] = {
L_126 ,
L_127 ,
L_128 ,
L_129 ,
L_130 ,
NULL
} ;
F_30 () ;
T_4 = F_82 ( T_4 , T_5 , V_182 , V_192 ,
V_176 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_131 , strlen ( L_131 ) ) ) {
V_179 = F_78 ( T_5 [ 1 ] , V_193 ) ;
if ( ! V_179 )
return F_90 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_132 , strlen ( L_132 ) ) ) {
V_180 = F_78 ( T_5 [ 1 ] , V_162 ) ;
if ( ! V_180 ) {
fprintf ( V_116 ,
L_133
L_134 ) ;
return - 1 ;
}
}
F_91 ( F_67 () ) ;
if ( T_4 && ! V_122 && ! V_179 && ! V_180 ) {
int V_194 [ 2 ] ;
int V_195 ;
T_15 V_56 ;
V_179 = F_78 ( T_5 [ 0 ] , V_193 ) ;
V_180 = F_78 ( T_5 [ 0 ] , V_162 ) ;
if ( ! V_179 && ! V_180 ) {
fprintf ( V_116 , L_135
L_136 , T_5 [ 0 ] ) ;
F_92 ( V_192 , V_182 ) ;
}
if ( F_79 ( T_5 [ 0 ] ) ) {
V_195 = T_4 - 1 ;
} else {
int V_196 ;
V_195 = F_80 ( V_180 ) ;
V_196 = ( T_4 - 1 ) - V_195 ;
if ( V_196 < 0 ) {
fprintf ( V_116 , L_137
L_138
L_139 , T_5 [ 0 ] ) ;
F_92 ( V_192 , V_182 ) ;
}
}
if ( F_93 ( V_194 ) < 0 ) {
perror ( L_140 ) ;
return - 1 ;
}
V_56 = F_94 () ;
if ( V_56 < 0 ) {
perror ( L_141 ) ;
return - 1 ;
}
if ( ! V_56 ) {
V_1 = 0 ;
F_95 ( V_194 [ 1 ] , 1 ) ;
F_96 ( V_194 [ 0 ] ) ;
if ( F_79 ( T_5 [ 0 ] ) ) {
V_177 = true ;
} else if ( ! V_177 ) {
if ( F_81 ( T_4 - V_195 , & T_5 [ V_195 ] ) != 0 ) {
V_181 = - 1 ;
goto V_129;
}
}
V_174 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_174 ) {
F_6 ( L_78 ) ;
V_181 = - V_126 ;
goto V_129;
}
V_174 [ V_1 ++ ] = L_142 ;
V_174 [ V_1 ++ ] = V_179 ;
if ( V_177 )
V_174 [ V_1 ++ ] = L_143 ;
V_174 [ V_1 ++ ] = L_144 ;
V_174 [ V_1 ++ ] = L_145 ;
V_174 [ V_1 ++ ] = L_146 ;
for ( V_7 = V_195 + 1 ; V_7 < T_4 ; V_7 ++ )
V_174 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_174 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_174 ) ;
free ( V_174 ) ;
exit ( - 1 ) ;
}
F_95 ( V_194 [ 0 ] , 0 ) ;
F_96 ( V_194 [ 1 ] ) ;
V_174 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_174 ) {
F_6 ( L_78 ) ;
V_181 = - V_126 ;
goto V_129;
}
V_1 = 0 ;
V_174 [ V_1 ++ ] = L_142 ;
V_174 [ V_1 ++ ] = V_180 ;
for ( V_7 = 1 ; V_7 < V_195 + 1 ; V_7 ++ )
V_174 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_174 [ V_1 ++ ] = L_147 ;
V_174 [ V_1 ++ ] = L_146 ;
V_174 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_174 ) ;
free ( V_174 ) ;
exit ( - 1 ) ;
}
if ( V_179 )
V_159 = V_179 ;
if ( V_180 )
V_159 = V_180 ;
if ( V_159 ) {
V_1 = 0 ;
if ( ! V_179 )
V_177 = false ;
else if ( ! V_177 ) {
if ( F_81 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_181 = - 1 ;
goto V_129;
}
}
V_174 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_174 ) {
F_6 ( L_78 ) ;
V_181 = - V_126 ;
goto V_129;
}
V_174 [ V_1 ++ ] = L_142 ;
V_174 [ V_1 ++ ] = V_159 ;
if ( V_177 )
V_174 [ V_1 ++ ] = L_143 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_174 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_174 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_174 ) ;
free ( V_174 ) ;
exit ( - 1 ) ;
}
if ( F_98 () < 0 )
return - 1 ;
if ( ! V_122 )
F_99 () ;
V_20 = F_73 ( V_170 , V_171 , 0 , false ,
& V_109 ) ;
if ( V_20 == NULL )
return - V_126 ;
if ( V_100 ) {
if ( F_100 ( V_20 , V_100 , V_101 ) )
return - 1 ;
}
if ( ! V_122 && ! V_185 )
F_101 ( V_20 , stdout , V_178 ) ;
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_185 ) {
struct V_135 V_197 ;
int V_198 ;
if ( F_1 () ) {
fprintf ( V_116 ,
L_148 ) ;
return - 1 ;
}
V_198 = F_102 ( V_20 -> V_147 , V_171 ) ;
if ( V_198 < 0 ) {
perror ( L_149 ) ;
return - 1 ;
}
V_181 = F_103 ( V_198 , & V_197 ) ;
if ( V_181 < 0 ) {
perror ( L_150 ) ;
return - 1 ;
}
if ( ! V_197 . V_199 ) {
fprintf ( V_116 , L_151 ) ;
return 0 ;
}
V_90 = F_48 ( V_185 ) ;
if ( ! V_90 ) {
fprintf ( V_116 , L_45 ) ;
return - 1 ;
}
V_181 = V_90 -> V_200 ( V_20 -> V_89 ,
L_152 ) ;
goto V_129;
}
if ( V_122 ) {
V_181 = V_90 -> V_201 ( V_122 , T_4 , T_5 ) ;
if ( V_181 )
goto V_129;
F_7 ( L_153 , V_122 ) ;
}
V_181 = F_11 ( V_20 ) ;
if ( V_181 < 0 )
goto V_129;
V_181 = F_39 ( V_20 ) ;
F_74 ( V_20 ) ;
F_33 () ;
V_129:
return V_181 ;
}
