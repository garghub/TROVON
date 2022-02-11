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
struct V_15 * V_16 ;
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
if ( V_12 == NULL )
continue;
V_16 = & V_12 -> V_16 ;
V_3 [ V_1 ] . V_47 = 0 ;
if ( F_9 ( V_23 ) )
V_3 [ V_1 ] . V_47 |= V_48 ;
if ( F_9 ( V_33 ) )
V_3 [ V_1 ] . V_47 |= V_49 ;
if ( F_9 ( V_35 ) )
V_3 [ V_1 ] . V_47 |= V_50 ;
if ( F_9 ( V_34 ) )
V_3 [ V_1 ] . V_47 |= V_51 ;
}
return 0 ;
}
static void F_14 ( struct V_52 * V_53 ,
struct V_54 * V_54 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
const char * V_17 = NULL ;
unsigned long V_55 ;
unsigned long V_56 ;
unsigned long long V_57 ;
if ( F_9 ( V_58 ) ) {
if ( V_59 )
printf ( L_20 , V_54 -> V_60 ) ;
else if ( F_9 ( V_23 ) && V_28 . V_29 )
printf ( L_21 , V_54 -> V_60 ) ;
else
printf ( L_22 , V_54 -> V_60 ) ;
}
if ( F_9 ( V_36 ) && F_9 ( V_37 ) )
printf ( L_23 , V_53 -> V_61 , V_53 -> V_62 ) ;
else if ( F_9 ( V_36 ) )
printf ( L_24 , V_53 -> V_61 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_53 -> V_62 ) ;
if ( F_9 ( V_43 ) ) {
if ( V_59 )
printf ( L_25 , V_53 -> V_63 ) ;
else
printf ( L_26 , V_53 -> V_63 ) ;
}
if ( F_9 ( TIME ) ) {
V_57 = V_53 -> time ;
V_55 = V_57 / V_64 ;
V_57 -= V_55 * V_64 ;
V_56 = V_57 / V_65 ;
printf ( L_27 , V_55 , V_56 ) ;
}
if ( F_9 ( V_66 ) ) {
V_17 = F_5 ( V_12 ) ;
printf ( L_28 , V_17 ? V_17 : L_29 ) ;
}
}
static bool F_15 ( struct V_15 * V_16 )
{
return ( ( V_16 -> type == V_67 ) &&
( V_16 -> V_68 & V_69 ) &&
( V_16 -> V_70 == 1 ) ) ;
}
static bool F_16 ( struct V_15 * V_16 )
{
if ( ( V_16 -> type == V_71 ) &&
( ( V_16 -> V_68 == V_72 ) ||
( V_16 -> V_68 == V_73 ) ||
( V_16 -> V_68 == V_74 ) ) )
return true ;
if ( F_15 ( V_16 ) )
return true ;
return false ;
}
static void F_17 ( union V_75 * V_76 ,
struct V_52 * V_53 ,
struct V_77 * V_77 ,
struct V_54 * V_54 ,
struct V_15 * V_16 )
{
struct V_78 V_79 ;
T_2 V_80 = V_76 -> V_81 . V_82 & V_83 ;
printf ( L_30 V_84 , V_53 -> V_85 ) ;
if ( ! F_16 ( V_16 ) )
return;
F_18 ( V_54 , V_77 , V_80 , V_86 ,
V_53 -> V_85 , & V_79 ) ;
if ( ! V_79 . V_87 )
F_18 ( V_54 , V_77 , V_80 , V_88 ,
V_53 -> V_85 , & V_79 ) ;
V_79 . V_63 = V_53 -> V_63 ;
V_79 . V_89 = NULL ;
if ( V_79 . V_87 )
V_79 . V_89 = F_19 ( V_79 . V_87 , V_79 . V_85 , NULL ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_20 ( V_79 . V_89 , & V_79 , stdout ) ;
else
F_21 ( V_79 . V_89 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_22 ( V_79 . V_87 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_23 ( union V_75 * V_76 ,
struct V_52 * V_53 ,
struct V_11 * V_12 ,
struct V_77 * V_77 ,
struct V_54 * V_54 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_24 ( V_12 , V_76 , V_53 , V_77 ,
V_3 [ V_16 -> type ] . V_47 ,
V_90 ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_30 ) )
F_17 ( V_76 , V_53 , V_77 , V_54 , V_16 ) ;
printf ( L_34 ) ;
}
static void F_25 ( union V_75 * V_76 , struct V_52 * V_53 ,
struct V_11 * V_12 , struct V_77 * V_77 ,
struct V_54 * V_54 ,
struct V_78 * V_79 V_91 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_14 ( V_53 , V_54 , V_12 ) ;
if ( F_15 ( V_16 ) ) {
F_23 ( V_76 , V_53 , V_12 , V_77 , V_54 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_26 ( V_12 -> V_92 , V_53 -> V_63 ,
V_53 -> V_93 , V_53 -> V_94 ) ;
if ( F_9 ( V_30 ) )
F_17 ( V_76 , V_53 , V_77 , V_54 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_24 ( V_12 , V_76 , V_53 , V_77 ,
V_3 [ V_16 -> type ] . V_47 ,
V_90 ) ;
}
printf ( L_34 ) ;
}
static int F_27 ( const char * T_3 V_91 ,
int T_4 V_91 ,
const char * * T_5 V_91 )
{
return 0 ;
}
static int F_28 ( void )
{
return 0 ;
}
static int F_29 ( struct V_95 * V_95 V_91 ,
const char * T_6 V_91 )
{
return 0 ;
}
static void F_30 ( void )
{
F_31 () ;
F_32 () ;
V_96 = & V_97 ;
}
static int F_33 ( void )
{
F_7 ( L_36 ) ;
return V_96 -> V_98 () ;
}
static int F_34 ( struct V_99 * T_7 V_91 ,
union V_75 * V_76 ,
struct V_52 * V_53 ,
struct V_11 * V_12 ,
struct V_77 * V_77 )
{
struct V_78 V_79 ;
struct V_54 * V_54 = F_35 ( V_77 , V_53 -> V_61 ,
V_53 -> V_62 ) ;
if ( V_54 == NULL ) {
F_7 ( L_37 ,
V_76 -> V_81 . type ) ;
return - 1 ;
}
if ( V_100 ) {
if ( V_53 -> time < V_101 ) {
F_6 ( L_38 V_102
L_39 V_102 L_34 , V_101 ,
V_53 -> time ) ;
V_103 ++ ;
}
V_101 = V_53 -> time ;
return 0 ;
}
if ( F_36 ( V_76 , V_77 , & V_79 , V_53 ) < 0 ) {
F_6 ( L_37 ,
V_76 -> V_81 . type ) ;
return - 1 ;
}
if ( V_79 . V_104 )
return 0 ;
if ( V_105 && ! F_37 ( V_53 -> V_63 , V_106 ) )
return 0 ;
V_96 -> F_25 ( V_76 , V_53 , V_12 , V_77 , V_54 , & V_79 ) ;
V_12 -> V_107 . V_108 . V_109 += V_53 -> V_110 ;
return 0 ;
}
static void F_38 ( int T_8 V_91 )
{
V_111 = 1 ;
}
static int F_39 ( struct V_19 * V_20 )
{
int V_112 ;
signal ( V_113 , F_38 ) ;
V_112 = F_40 ( V_20 , & V_114 ) ;
if ( V_100 )
F_6 ( L_40 V_102 L_34 , V_103 ) ;
return V_112 ;
}
static struct V_115 * F_41 ( const char * V_116 ,
struct V_96 * V_117 )
{
struct V_115 * V_118 = malloc ( sizeof( * V_118 ) + strlen ( V_116 ) + 1 ) ;
if ( V_118 != NULL ) {
strcpy ( V_118 -> V_116 , V_116 ) ;
V_118 -> V_117 = V_117 ;
}
return V_118 ;
}
static void F_42 ( struct V_115 * V_118 )
{
F_43 ( & V_118 -> V_119 , & V_120 ) ;
}
static struct V_115 * F_44 ( const char * V_116 )
{
struct V_115 * V_118 ;
F_45 (s, &script_specs, node)
if ( strcasecmp ( V_118 -> V_116 , V_116 ) == 0 )
return V_118 ;
return NULL ;
}
static struct V_115 * F_46 ( const char * V_116 ,
struct V_96 * V_117 )
{
struct V_115 * V_118 = F_44 ( V_116 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_41 ( V_116 , V_117 ) ;
if ( ! V_118 )
return NULL ;
F_42 ( V_118 ) ;
return V_118 ;
}
int F_47 ( const char * V_116 , struct V_96 * V_117 )
{
struct V_115 * V_118 ;
V_118 = F_44 ( V_116 ) ;
if ( V_118 )
return - 1 ;
V_118 = F_46 ( V_116 , V_117 ) ;
if ( ! V_118 )
return - 1 ;
return 0 ;
}
static struct V_96 * F_48 ( const char * V_116 )
{
struct V_115 * V_118 = F_44 ( V_116 ) ;
if ( ! V_118 )
return NULL ;
return V_118 -> V_117 ;
}
static void F_49 ( void )
{
struct V_115 * V_118 ;
fprintf ( V_121 , L_34 ) ;
fprintf ( V_121 , L_41
L_42 ) ;
F_45 (s, &script_specs, node)
fprintf ( V_121 , L_43 , V_118 -> V_116 , V_118 -> V_117 -> V_122 ) ;
fprintf ( V_121 , L_34 ) ;
}
static int F_50 ( const struct V_123 * T_9 V_91 ,
const char * V_10 , int T_10 V_91 )
{
char V_116 [ V_124 ] ;
const char * T_3 , * V_125 ;
int V_126 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_49 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_126 = T_3 - V_10 ;
if ( V_126 >= V_124 ) {
fprintf ( V_121 , L_45 ) ;
return - 1 ;
}
strncpy ( V_116 , V_10 , V_126 ) ;
V_116 [ V_126 ] = '\0' ;
V_96 = F_48 ( V_116 ) ;
if ( ! V_96 ) {
fprintf ( V_121 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_125 = strrchr ( T_3 , '.' ) ;
if ( ! V_125 ) {
fprintf ( V_121 , L_46 ) ;
return - 1 ;
}
V_96 = F_48 ( ++ V_125 ) ;
if ( ! V_96 ) {
fprintf ( V_121 , L_46 ) ;
return - 1 ;
}
}
V_127 = F_51 ( T_3 ) ;
return 0 ;
}
static int F_52 ( const struct V_123 * T_9 V_91 ,
const char * V_128 , int T_10 V_91 )
{
char * V_129 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_130 = 0 ;
char * V_10 = F_51 ( V_128 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_131 ;
V_129 = strchr ( V_10 , ':' ) ;
if ( V_129 ) {
* V_129 = '\0' ;
V_129 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_67 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_71 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_132 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_133 ;
else {
fprintf ( V_121 , L_51 ) ;
V_130 = - V_22 ;
goto V_134;
}
if ( V_3 [ type ] . V_4 )
F_53 ( L_52 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_46 = false ;
} else {
V_129 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_121 ,
L_53 ) ;
V_130 = - V_22 ;
goto V_134;
}
if ( F_1 () )
F_53 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_46 = true ;
}
}
V_129 = strtok ( V_129 , L_55 ) ;
while ( V_129 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_129 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_121 , L_56 ) ;
V_130 = - V_22 ;
goto V_134;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_135 & V_9 [ V_7 ] . V_6 ) {
F_53 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_135 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_121 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_130 = - V_22 ;
goto V_134;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_129 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_59
L_60 , F_13 ( type ) ) ;
}
}
V_134:
free ( V_10 ) ;
return V_130 ;
}
static int F_54 ( const char * V_136 , const struct V_137 * V_138 )
{
char V_139 [ V_124 ] ;
struct V_140 V_141 ;
sprintf ( V_139 , L_61 , V_136 , V_138 -> V_142 ) ;
if ( V_140 ( V_139 , & V_141 ) )
return 0 ;
return F_55 ( V_141 . V_143 ) ;
}
static struct V_144 * F_56 ( const char * V_122 )
{
struct V_144 * V_118 = F_57 ( sizeof( * V_118 ) ) ;
if ( V_118 != NULL && V_122 )
V_118 -> V_122 = F_51 ( V_122 ) ;
return V_118 ;
}
static void F_58 ( struct V_144 * V_118 )
{
free ( V_118 -> V_122 ) ;
free ( V_118 -> V_145 ) ;
free ( V_118 -> args ) ;
free ( V_118 ) ;
}
static void F_59 ( struct V_144 * V_118 )
{
F_43 ( & V_118 -> V_119 , & V_146 ) ;
}
static struct V_144 * F_60 ( const char * V_122 )
{
struct V_144 * V_118 ;
F_45 (s, &script_descs, node)
if ( strcasecmp ( V_118 -> V_122 , V_122 ) == 0 )
return V_118 ;
return NULL ;
}
static struct V_144 * F_61 ( const char * V_122 )
{
struct V_144 * V_118 = F_60 ( V_122 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_56 ( V_122 ) ;
if ( ! V_118 )
goto V_147;
F_59 ( V_118 ) ;
return V_118 ;
V_147:
F_58 ( V_118 ) ;
return NULL ;
}
static const char * F_62 ( const char * V_10 , const char * V_148 )
{
T_11 V_149 = strlen ( V_148 ) ;
const char * V_150 = V_10 ;
if ( strlen ( V_10 ) > V_149 ) {
V_150 = V_10 + strlen ( V_10 ) - V_149 ;
if ( ! strncmp ( V_150 , V_148 , V_149 ) )
return V_150 ;
}
return NULL ;
}
static int F_63 ( struct V_144 * V_151 , const char * V_152 )
{
char line [ V_153 ] , * V_150 ;
T_12 * V_154 ;
V_154 = fopen ( V_152 , L_62 ) ;
if ( ! V_154 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_154 ) ) {
V_150 = F_64 ( line ) ;
if ( strlen ( V_150 ) == 0 )
continue;
if ( * V_150 != '#' )
continue;
V_150 ++ ;
if ( strlen ( V_150 ) && * V_150 == '!' )
continue;
V_150 = F_64 ( V_150 ) ;
if ( strlen ( V_150 ) && V_150 [ strlen ( V_150 ) - 1 ] == '\n' )
V_150 [ strlen ( V_150 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_150 , L_63 , strlen ( L_63 ) ) ) {
V_150 += strlen ( L_63 ) ;
V_151 -> V_145 = F_51 ( F_64 ( V_150 ) ) ;
continue;
}
if ( ! strncmp ( V_150 , L_64 , strlen ( L_64 ) ) ) {
V_150 += strlen ( L_64 ) ;
V_151 -> args = F_51 ( F_64 ( V_150 ) ) ;
continue;
}
}
fclose ( V_154 ) ;
return 0 ;
}
static char * F_65 ( struct V_137 * V_155 , const char * V_148 )
{
char * V_156 , * V_10 ;
V_156 = F_51 ( V_155 -> V_142 ) ;
if ( ! V_156 )
return NULL ;
V_10 = ( char * ) F_62 ( V_156 , V_148 ) ;
if ( ! V_10 ) {
free ( V_156 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_156 ;
}
static int F_66 ( const struct V_123 * T_9 V_91 ,
const char * V_118 V_91 ,
int T_10 V_91 )
{
struct V_137 * V_157 , * V_158 , V_155 , V_159 ;
char V_160 [ V_161 ] ;
T_13 * V_162 , * V_163 ;
char V_164 [ V_161 ] ;
char V_165 [ V_161 ] ;
struct V_144 * V_151 ;
char V_166 [ V_153 ] ;
char * V_156 ;
snprintf ( V_160 , V_161 , L_65 , F_67 () ) ;
V_162 = F_68 ( V_160 ) ;
if ( ! V_162 )
return - 1 ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_165 , V_161 , L_66 , V_160 ,
V_159 . V_142 ) ;
V_163 = F_68 ( V_165 ) ;
if ( ! V_163 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_156 = F_65 ( & V_155 , V_167 ) ;
if ( V_156 ) {
V_151 = F_61 ( V_156 ) ;
snprintf ( V_164 , V_161 , L_61 ,
V_165 , V_155 . V_142 ) ;
F_63 ( V_151 , V_164 ) ;
free ( V_156 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_45 (desc, &script_descs, node) {
sprintf ( V_166 , L_68 , V_151 -> V_122 ,
V_151 -> args ? V_151 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_166 ,
V_151 -> V_145 ? V_151 -> V_145 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_71 ( char * V_168 , char * V_169 ,
struct V_19 * V_20 )
{
char V_152 [ V_161 ] , V_17 [ 128 ] ;
char line [ V_153 ] , * V_150 ;
struct V_11 * V_170 ;
int V_171 , V_126 ;
T_12 * V_154 ;
sprintf ( V_152 , L_70 , V_168 , V_169 ) ;
V_154 = fopen ( V_152 , L_62 ) ;
if ( ! V_154 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_154 ) ) {
V_150 = F_64 ( line ) ;
if ( * V_150 == '#' )
continue;
while ( strlen ( V_150 ) ) {
V_150 = strstr ( V_150 , L_71 ) ;
if ( ! V_150 )
break;
V_150 += 2 ;
V_150 = F_64 ( V_150 ) ;
V_126 = strcspn ( V_150 , L_72 ) ;
if ( ! V_126 )
break;
snprintf ( V_17 , V_126 + 1 , L_73 , V_150 ) ;
V_171 = 0 ;
F_45 (pos,
&session->evlist->entries, node) {
if ( ! strcmp ( F_5 ( V_170 ) , V_17 ) ) {
V_171 = 1 ;
break;
}
}
if ( ! V_171 ) {
fclose ( V_154 ) ;
return - 1 ;
}
}
}
fclose ( V_154 ) ;
return 0 ;
}
int F_72 ( char * * V_172 , char * * V_173 )
{
struct V_137 * V_157 , * V_158 , V_155 , V_159 ;
char V_160 [ V_161 ] , V_165 [ V_161 ] ;
T_13 * V_162 , * V_163 ;
struct V_19 * V_20 ;
char * V_174 ;
int V_7 = 0 ;
V_20 = F_73 ( V_175 , V_176 , 0 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_160 , V_161 , L_65 , F_67 () ) ;
V_162 = F_68 ( V_160 ) ;
if ( ! V_162 ) {
F_74 ( V_20 ) ;
return - 1 ;
}
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_165 , V_161 , L_61 , V_160 ,
V_159 . V_142 ) ;
#ifdef F_75
if ( strstr ( V_165 , L_74 ) )
continue;
#endif
#ifdef F_76
if ( strstr ( V_165 , L_75 ) )
continue;
#endif
V_163 = F_68 ( V_165 ) ;
if ( ! V_163 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_155 . V_142 , L_76 ) )
continue;
sprintf ( V_173 [ V_7 ] , L_61 , V_165 ,
V_155 . V_142 ) ;
V_174 = strchr ( V_155 . V_142 , '.' ) ;
snprintf ( V_172 [ V_7 ] ,
( V_174 - V_155 . V_142 ) + 1 ,
L_73 , V_155 . V_142 ) ;
if ( F_71 ( V_165 ,
V_172 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_77 ( V_163 ) ;
}
F_77 ( V_162 ) ;
F_74 ( V_20 ) ;
return V_7 ;
}
static char * F_78 ( const char * V_156 , const char * V_148 )
{
struct V_137 * V_157 , * V_158 , V_155 , V_159 ;
char V_160 [ V_161 ] ;
char V_164 [ V_161 ] ;
T_13 * V_162 , * V_163 ;
char V_165 [ V_161 ] ;
char * V_177 ;
snprintf ( V_160 , V_161 , L_65 , F_67 () ) ;
V_162 = F_68 ( V_160 ) ;
if ( ! V_162 )
return NULL ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_165 , V_161 , L_66 , V_160 ,
V_159 . V_142 ) ;
V_163 = F_68 ( V_165 ) ;
if ( ! V_163 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_177 = F_65 ( & V_155 , V_148 ) ;
if ( V_177 && ! strcmp ( V_156 , V_177 ) ) {
free ( V_177 ) ;
F_77 ( V_163 ) ;
F_77 ( V_162 ) ;
snprintf ( V_164 , V_161 , L_61 ,
V_165 , V_155 . V_142 ) ;
return F_51 ( V_164 ) ;
}
free ( V_177 ) ;
}
F_77 ( V_163 ) ;
}
F_77 ( V_162 ) ;
return NULL ;
}
static bool F_79 ( const char * V_164 )
{
return F_62 ( V_164 , L_77 ) == NULL ? false : true ;
}
static int F_80 ( char * V_164 )
{
struct V_144 * V_151 ;
int V_178 = 0 ;
char * V_150 ;
V_151 = F_56 ( NULL ) ;
if ( F_63 ( V_151 , V_164 ) )
goto V_134;
if ( ! V_151 -> args )
goto V_134;
for ( V_150 = V_151 -> args ; * V_150 ; V_150 ++ )
if ( * V_150 == '<' )
V_178 ++ ;
V_134:
F_58 ( V_151 ) ;
return V_178 ;
}
static int F_81 ( int T_4 , const char * * T_5 )
{
char * * V_179 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_179 ) {
F_6 ( L_78 ) ;
return - 1 ;
}
memcpy ( V_179 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_82 ( T_4 , ( const char * * ) V_179 , V_180 ,
NULL , V_181 ) ;
free ( V_179 ) ;
V_182 = ( T_4 == 0 ) ;
return 0 ;
}
int F_83 ( int T_4 , const char * * T_5 , const char * T_14 V_91 )
{
bool V_183 = false ;
char * V_184 = NULL ;
char * V_185 = NULL ;
struct V_19 * V_20 ;
char * V_164 = NULL ;
const char * * V_179 ;
int V_7 , V_1 , V_186 ;
const struct V_123 V_187 [] = {
F_84 ( 'D' , L_79 , & V_188 ,
L_80 ) ,
F_85 ( 'v' , L_81 , & V_189 ,
L_82 ) ,
F_84 ( 'L' , L_83 , & V_59 ,
L_84 ) ,
F_86 ( 'l' , L_85 , NULL , NULL , L_86 ,
F_66 ) ,
F_87 ( 's' , L_87 , NULL , L_88 ,
L_89 ,
F_50 ) ,
F_88 ( 'g' , L_90 , & V_190 , L_44 ,
L_91 ) ,
F_88 ( 'i' , L_92 , & V_175 , L_93 , L_94 ) ,
F_84 ( 'd' , L_95 , & V_100 ,
L_96 ) ,
F_88 ( 'k' , L_97 , & V_28 . V_191 ,
L_93 , L_98 ) ,
F_88 ( 0 , L_99 , & V_28 . V_192 ,
L_93 , L_100 ) ,
F_84 ( 'G' , L_101 , & V_26 ,
L_102 ) ,
F_88 ( 0 , L_103 , & V_28 . V_193 , L_104 ,
L_105 ) ,
F_87 ( 'f' , L_106 , NULL , L_107 ,
L_108
L_109
L_110
L_111 , F_52 ) ,
F_84 ( 'a' , L_112 , & V_182 ,
L_113 ) ,
F_88 ( 'S' , L_114 , & V_28 . V_194 , L_115 ,
L_116 ) ,
F_88 ( 'C' , L_117 , & V_105 , L_117 , L_118 ) ,
F_88 ( 'c' , L_119 , & V_28 . V_195 , L_120 ,
L_121 ) ,
F_84 ( 'I' , L_122 , & V_183 ,
L_123 ) ,
F_84 ( '\0' , L_124 , & V_28 . V_196 ,
L_125 ) ,
F_89 ()
} ;
const char * const V_197 [] = {
L_126 ,
L_127 ,
L_128 ,
L_129 ,
L_130 ,
NULL
} ;
F_30 () ;
T_4 = F_82 ( T_4 , T_5 , V_187 , V_197 ,
V_181 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_131 , strlen ( L_131 ) ) ) {
V_184 = F_78 ( T_5 [ 1 ] , V_198 ) ;
if ( ! V_184 )
return F_90 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_132 , strlen ( L_132 ) ) ) {
V_185 = F_78 ( T_5 [ 1 ] , V_167 ) ;
if ( ! V_185 ) {
fprintf ( V_121 ,
L_133
L_134 ) ;
return - 1 ;
}
}
F_91 ( F_67 () ) ;
if ( T_4 && ! V_127 && ! V_184 && ! V_185 ) {
int V_199 [ 2 ] ;
int V_200 ;
T_15 V_61 ;
V_184 = F_78 ( T_5 [ 0 ] , V_198 ) ;
V_185 = F_78 ( T_5 [ 0 ] , V_167 ) ;
if ( ! V_184 && ! V_185 ) {
fprintf ( V_121 , L_135
L_136 , T_5 [ 0 ] ) ;
F_92 ( V_197 , V_187 ) ;
}
if ( F_79 ( T_5 [ 0 ] ) ) {
V_200 = T_4 - 1 ;
} else {
int V_201 ;
V_200 = F_80 ( V_185 ) ;
V_201 = ( T_4 - 1 ) - V_200 ;
if ( V_201 < 0 ) {
fprintf ( V_121 , L_137
L_138
L_139 , T_5 [ 0 ] ) ;
F_92 ( V_197 , V_187 ) ;
}
}
if ( F_93 ( V_199 ) < 0 ) {
perror ( L_140 ) ;
return - 1 ;
}
V_61 = F_94 () ;
if ( V_61 < 0 ) {
perror ( L_141 ) ;
return - 1 ;
}
if ( ! V_61 ) {
V_1 = 0 ;
F_95 ( V_199 [ 1 ] , 1 ) ;
F_96 ( V_199 [ 0 ] ) ;
if ( F_79 ( T_5 [ 0 ] ) ) {
V_182 = true ;
} else if ( ! V_182 ) {
if ( F_81 ( T_4 - V_200 , & T_5 [ V_200 ] ) != 0 ) {
V_186 = - 1 ;
goto V_134;
}
}
V_179 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_179 ) {
F_6 ( L_78 ) ;
V_186 = - V_131 ;
goto V_134;
}
V_179 [ V_1 ++ ] = L_142 ;
V_179 [ V_1 ++ ] = V_184 ;
if ( V_182 )
V_179 [ V_1 ++ ] = L_143 ;
V_179 [ V_1 ++ ] = L_144 ;
V_179 [ V_1 ++ ] = L_145 ;
V_179 [ V_1 ++ ] = L_146 ;
for ( V_7 = V_200 + 1 ; V_7 < T_4 ; V_7 ++ )
V_179 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_179 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_179 ) ;
free ( V_179 ) ;
exit ( - 1 ) ;
}
F_95 ( V_199 [ 0 ] , 0 ) ;
F_96 ( V_199 [ 1 ] ) ;
V_179 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_179 ) {
F_6 ( L_78 ) ;
V_186 = - V_131 ;
goto V_134;
}
V_1 = 0 ;
V_179 [ V_1 ++ ] = L_142 ;
V_179 [ V_1 ++ ] = V_185 ;
for ( V_7 = 1 ; V_7 < V_200 + 1 ; V_7 ++ )
V_179 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_179 [ V_1 ++ ] = L_147 ;
V_179 [ V_1 ++ ] = L_146 ;
V_179 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_179 ) ;
free ( V_179 ) ;
exit ( - 1 ) ;
}
if ( V_184 )
V_164 = V_184 ;
if ( V_185 )
V_164 = V_185 ;
if ( V_164 ) {
V_1 = 0 ;
if ( ! V_184 )
V_182 = false ;
else if ( ! V_182 ) {
if ( F_81 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_186 = - 1 ;
goto V_134;
}
}
V_179 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_179 ) {
F_6 ( L_78 ) ;
V_186 = - V_131 ;
goto V_134;
}
V_179 [ V_1 ++ ] = L_142 ;
V_179 [ V_1 ++ ] = V_164 ;
if ( V_182 )
V_179 [ V_1 ++ ] = L_143 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_179 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_179 [ V_1 ++ ] = NULL ;
F_97 ( L_142 , ( char * * ) V_179 ) ;
free ( V_179 ) ;
exit ( - 1 ) ;
}
if ( F_98 () < 0 )
return - 1 ;
if ( ! V_127 )
F_99 () ;
V_20 = F_73 ( V_175 , V_176 , 0 , false ,
& V_114 ) ;
if ( V_20 == NULL )
return - V_131 ;
if ( V_105 ) {
if ( F_100 ( V_20 , V_105 , V_106 ) )
return - 1 ;
}
if ( ! V_127 && ! V_190 )
F_101 ( V_20 , stdout , V_183 ) ;
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_190 ) {
struct V_140 V_202 ;
int V_203 ;
if ( F_1 () ) {
fprintf ( V_121 ,
L_148 ) ;
return - 1 ;
}
V_203 = F_102 ( V_20 -> V_152 , V_176 ) ;
if ( V_203 < 0 ) {
perror ( L_149 ) ;
return - 1 ;
}
V_186 = F_103 ( V_203 , & V_202 ) ;
if ( V_186 < 0 ) {
perror ( L_150 ) ;
return - 1 ;
}
if ( ! V_202 . V_204 ) {
fprintf ( V_121 , L_151 ) ;
return 0 ;
}
V_96 = F_48 ( V_190 ) ;
if ( ! V_96 ) {
fprintf ( V_121 , L_45 ) ;
return - 1 ;
}
V_186 = V_96 -> V_205 ( V_20 -> V_95 ,
L_152 ) ;
goto V_134;
}
if ( V_127 ) {
V_186 = V_96 -> V_206 ( V_127 , T_4 , T_5 ) ;
if ( V_186 )
goto V_134;
F_7 ( L_153 , V_127 ) ;
}
V_186 = F_11 ( V_20 ) ;
if ( V_186 < 0 )
goto V_134;
V_186 = F_39 ( V_20 ) ;
F_74 ( V_20 ) ;
F_33 () ;
V_134:
return V_186 ;
}
