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
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_125 ) ;
int V_1 ;
int V_126 = 0 ;
char * V_10 = F_51 ( V_123 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_127 ;
V_124 = strchr ( V_10 , ':' ) ;
if ( V_124 ) {
* V_124 = '\0' ;
V_124 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_62 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_66 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_128 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_129 ;
else {
fprintf ( V_116 , L_51 ) ;
V_126 = - V_22 ;
goto V_130;
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
V_126 = - V_22 ;
goto V_130;
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
V_126 = - V_22 ;
goto V_130;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_131 & V_9 [ V_7 ] . V_6 ) {
F_53 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_131 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_116 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_126 = - V_22 ;
goto V_130;
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
V_130:
free ( V_10 ) ;
return V_126 ;
}
static int F_54 ( const char * V_132 , const struct V_133 * V_134 )
{
char V_135 [ V_119 ] ;
struct V_136 V_137 ;
sprintf ( V_135 , L_61 , V_132 , V_134 -> V_138 ) ;
if ( V_136 ( V_135 , & V_137 ) )
return 0 ;
return F_55 ( V_137 . V_139 ) ;
}
static struct V_140 * F_56 ( const char * V_117 )
{
struct V_140 * V_113 = F_57 ( sizeof( * V_113 ) ) ;
if ( V_113 != NULL && V_117 )
V_113 -> V_117 = F_51 ( V_117 ) ;
return V_113 ;
}
static void F_58 ( struct V_140 * V_113 )
{
free ( V_113 -> V_117 ) ;
free ( V_113 -> V_141 ) ;
free ( V_113 -> args ) ;
free ( V_113 ) ;
}
static void F_59 ( struct V_140 * V_113 )
{
F_43 ( & V_113 -> V_114 , & V_142 ) ;
}
static struct V_140 * F_60 ( const char * V_117 )
{
struct V_140 * V_113 ;
F_45 (s, &script_descs, node)
if ( strcasecmp ( V_113 -> V_117 , V_117 ) == 0 )
return V_113 ;
return NULL ;
}
static struct V_140 * F_61 ( const char * V_117 )
{
struct V_140 * V_113 = F_60 ( V_117 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_56 ( V_117 ) ;
if ( ! V_113 )
goto V_143;
F_59 ( V_113 ) ;
return V_113 ;
V_143:
F_58 ( V_113 ) ;
return NULL ;
}
static const char * F_62 ( const char * V_10 , const char * V_144 )
{
T_11 V_145 = strlen ( V_144 ) ;
const char * V_146 = V_10 ;
if ( strlen ( V_10 ) > V_145 ) {
V_146 = V_10 + strlen ( V_10 ) - V_145 ;
if ( ! strncmp ( V_146 , V_144 , V_145 ) )
return V_146 ;
}
return NULL ;
}
static char * F_63 ( char * V_10 )
{
int V_121 = strlen ( V_10 ) ;
while ( V_121 && isspace ( * V_10 ) ) {
V_121 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_64 ( struct V_140 * V_147 , const char * V_148 )
{
char line [ V_149 ] , * V_146 ;
T_12 * V_150 ;
V_150 = fopen ( V_148 , L_62 ) ;
if ( ! V_150 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_150 ) ) {
V_146 = F_63 ( line ) ;
if ( strlen ( V_146 ) == 0 )
continue;
if ( * V_146 != '#' )
continue;
V_146 ++ ;
if ( strlen ( V_146 ) && * V_146 == '!' )
continue;
V_146 = F_63 ( V_146 ) ;
if ( strlen ( V_146 ) && V_146 [ strlen ( V_146 ) - 1 ] == '\n' )
V_146 [ strlen ( V_146 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_146 , L_63 , strlen ( L_63 ) ) ) {
V_146 += strlen ( L_63 ) ;
V_147 -> V_141 = F_51 ( F_63 ( V_146 ) ) ;
continue;
}
if ( ! strncmp ( V_146 , L_64 , strlen ( L_64 ) ) ) {
V_146 += strlen ( L_64 ) ;
V_147 -> args = F_51 ( F_63 ( V_146 ) ) ;
continue;
}
}
fclose ( V_150 ) ;
return 0 ;
}
static char * F_65 ( struct V_133 * V_151 , const char * V_144 )
{
char * V_152 , * V_10 ;
V_152 = F_51 ( V_151 -> V_138 ) ;
if ( ! V_152 )
return NULL ;
V_10 = ( char * ) F_62 ( V_152 , V_144 ) ;
if ( ! V_10 ) {
free ( V_152 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_152 ;
}
static int F_66 ( const struct V_118 * T_9 V_88 ,
const char * V_113 V_88 ,
int T_10 V_88 )
{
struct V_133 * V_153 , * V_154 , V_151 , V_155 ;
char V_156 [ V_157 ] ;
T_13 * V_158 , * V_159 ;
char V_160 [ V_157 ] ;
char V_161 [ V_157 ] ;
struct V_140 * V_147 ;
char V_162 [ V_149 ] ;
char * V_152 ;
snprintf ( V_156 , V_157 , L_65 , F_67 () ) ;
V_158 = F_68 ( V_156 ) ;
if ( ! V_158 )
return - 1 ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_161 , V_157 , L_66 , V_156 ,
V_155 . V_138 ) ;
V_159 = F_68 ( V_161 ) ;
if ( ! V_159 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_152 = F_65 ( & V_151 , V_163 ) ;
if ( V_152 ) {
V_147 = F_61 ( V_152 ) ;
snprintf ( V_160 , V_157 , L_61 ,
V_161 , V_151 . V_138 ) ;
F_64 ( V_147 , V_160 ) ;
free ( V_152 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_45 (desc, &script_descs, node) {
sprintf ( V_162 , L_68 , V_147 -> V_117 ,
V_147 -> args ? V_147 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_162 ,
V_147 -> V_141 ? V_147 -> V_141 : L_1 ) ;
}
exit ( 0 ) ;
}
int F_71 ( char * * V_164 , char * * V_165 )
{
struct V_133 * V_153 , * V_154 , V_151 , V_155 ;
char V_156 [ V_157 ] ;
T_13 * V_158 , * V_159 ;
char V_161 [ V_157 ] ;
char * V_166 ;
int V_7 = 0 ;
snprintf ( V_156 , V_157 , L_65 , F_67 () ) ;
V_158 = F_68 ( V_156 ) ;
if ( ! V_158 )
return - 1 ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_161 , V_157 , L_61 , V_156 ,
V_155 . V_138 ) ;
#ifdef F_72
if ( strstr ( V_161 , L_70 ) )
continue;
#endif
#ifdef F_73
if ( strstr ( V_161 , L_71 ) )
continue;
#endif
V_159 = F_68 ( V_161 ) ;
if ( ! V_159 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_151 . V_138 , L_72 ) )
continue;
sprintf ( V_165 [ V_7 ] , L_61 , V_161 ,
V_151 . V_138 ) ;
V_166 = strchr ( V_151 . V_138 , '.' ) ;
snprintf ( V_164 [ V_7 ] ,
( V_166 - V_151 . V_138 ) + 1 ,
L_73 , V_151 . V_138 ) ;
V_7 ++ ;
}
}
return V_7 ;
}
static char * F_74 ( const char * V_152 , const char * V_144 )
{
struct V_133 * V_153 , * V_154 , V_151 , V_155 ;
char V_156 [ V_157 ] ;
char V_160 [ V_157 ] ;
T_13 * V_158 , * V_159 ;
char V_161 [ V_157 ] ;
char * V_167 ;
snprintf ( V_156 , V_157 , L_65 , F_67 () ) ;
V_158 = F_68 ( V_156 ) ;
if ( ! V_158 )
return NULL ;
F_69 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_161 , V_157 , L_66 , V_156 ,
V_155 . V_138 ) ;
V_159 = F_68 ( V_161 ) ;
if ( ! V_159 )
continue;
F_70 (lang_path, lang_dir, script_dirent, script_next) {
V_167 = F_65 ( & V_151 , V_144 ) ;
if ( V_167 && ! strcmp ( V_152 , V_167 ) ) {
free ( V_167 ) ;
F_75 ( V_159 ) ;
F_75 ( V_158 ) ;
snprintf ( V_160 , V_157 , L_61 ,
V_161 , V_151 . V_138 ) ;
return F_51 ( V_160 ) ;
}
free ( V_167 ) ;
}
F_75 ( V_159 ) ;
}
F_75 ( V_158 ) ;
return NULL ;
}
static bool F_76 ( const char * V_160 )
{
return F_62 ( V_160 , L_74 ) == NULL ? false : true ;
}
static int F_77 ( char * V_160 )
{
struct V_140 * V_147 ;
int V_168 = 0 ;
char * V_146 ;
V_147 = F_56 ( NULL ) ;
if ( F_64 ( V_147 , V_160 ) )
goto V_130;
if ( ! V_147 -> args )
goto V_130;
for ( V_146 = V_147 -> args ; * V_146 ; V_146 ++ )
if ( * V_146 == '<' )
V_168 ++ ;
V_130:
F_58 ( V_147 ) ;
return V_168 ;
}
static int F_78 ( int T_4 , const char * * T_5 )
{
char * * V_169 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_169 ) {
F_6 ( L_75 ) ;
return - 1 ;
}
memcpy ( V_169 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_79 ( T_4 , ( const char * * ) V_169 , V_170 ,
NULL , V_171 ) ;
free ( V_169 ) ;
V_172 = ( T_4 == 0 ) ;
return 0 ;
}
int F_80 ( int T_4 , const char * * T_5 , const char * T_14 V_88 )
{
bool V_173 = false ;
const char * V_174 = NULL ;
char * V_175 = NULL ;
char * V_176 = NULL ;
struct V_19 * V_20 ;
char * V_160 = NULL ;
const char * * V_169 ;
int V_7 , V_1 , V_177 ;
const struct V_118 V_178 [] = {
F_81 ( 'D' , L_76 , & V_179 ,
L_77 ) ,
F_82 ( 'v' , L_78 , & V_180 ,
L_79 ) ,
F_81 ( 'L' , L_80 , & V_54 ,
L_81 ) ,
F_83 ( 'l' , L_82 , NULL , NULL , L_83 ,
F_66 ) ,
F_84 ( 's' , L_84 , NULL , L_85 ,
L_86 ,
F_50 ) ,
F_85 ( 'g' , L_87 , & V_181 , L_44 ,
L_88 ) ,
F_85 ( 'i' , L_89 , & V_174 , L_90 , L_91 ) ,
F_81 ( 'd' , L_92 , & V_95 ,
L_93 ) ,
F_85 ( 'k' , L_94 , & V_28 . V_182 ,
L_90 , L_95 ) ,
F_85 ( 0 , L_96 , & V_28 . V_183 ,
L_90 , L_97 ) ,
F_81 ( 'G' , L_98 , & V_26 ,
L_99 ) ,
F_85 ( 0 , L_100 , & V_28 . V_184 , L_101 ,
L_102 ) ,
F_84 ( 'f' , L_103 , NULL , L_104 ,
L_105
L_106
L_107
L_108 , F_52 ) ,
F_81 ( 'a' , L_109 , & V_172 ,
L_110 ) ,
F_85 ( 'S' , L_111 , & V_28 . V_185 , L_112 ,
L_113 ) ,
F_85 ( 'C' , L_114 , & V_100 , L_114 , L_115 ) ,
F_85 ( 'c' , L_116 , & V_28 . V_186 , L_117 ,
L_118 ) ,
F_81 ( 'I' , L_119 , & V_173 ,
L_120 ) ,
F_81 ( '\0' , L_121 , & V_28 . V_187 ,
L_122 ) ,
F_86 ()
} ;
const char * const V_188 [] = {
L_123 ,
L_124 ,
L_125 ,
L_126 ,
L_127 ,
NULL
} ;
F_30 () ;
T_4 = F_79 ( T_4 , T_5 , V_178 , V_188 ,
V_171 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_128 , strlen ( L_128 ) ) ) {
V_175 = F_74 ( T_5 [ 1 ] , V_189 ) ;
if ( ! V_175 )
return F_87 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_129 , strlen ( L_129 ) ) ) {
V_176 = F_74 ( T_5 [ 1 ] , V_163 ) ;
if ( ! V_176 ) {
fprintf ( V_116 ,
L_130
L_131 ) ;
return - 1 ;
}
}
F_88 ( F_67 () ) ;
if ( T_4 && ! V_122 && ! V_175 && ! V_176 ) {
int V_190 [ 2 ] ;
int V_191 ;
T_15 V_56 ;
V_175 = F_74 ( T_5 [ 0 ] , V_189 ) ;
V_176 = F_74 ( T_5 [ 0 ] , V_163 ) ;
if ( ! V_175 && ! V_176 ) {
fprintf ( V_116 , L_132
L_133 , T_5 [ 0 ] ) ;
F_89 ( V_188 , V_178 ) ;
}
if ( F_76 ( T_5 [ 0 ] ) ) {
V_191 = T_4 - 1 ;
} else {
int V_192 ;
V_191 = F_77 ( V_176 ) ;
V_192 = ( T_4 - 1 ) - V_191 ;
if ( V_192 < 0 ) {
fprintf ( V_116 , L_134
L_135
L_136 , T_5 [ 0 ] ) ;
F_89 ( V_188 , V_178 ) ;
}
}
if ( F_90 ( V_190 ) < 0 ) {
perror ( L_137 ) ;
return - 1 ;
}
V_56 = F_91 () ;
if ( V_56 < 0 ) {
perror ( L_138 ) ;
return - 1 ;
}
if ( ! V_56 ) {
V_1 = 0 ;
F_92 ( V_190 [ 1 ] , 1 ) ;
F_93 ( V_190 [ 0 ] ) ;
if ( F_76 ( T_5 [ 0 ] ) ) {
V_172 = true ;
} else if ( ! V_172 ) {
if ( F_78 ( T_4 - V_191 , & T_5 [ V_191 ] ) != 0 ) {
V_177 = - 1 ;
goto V_130;
}
}
V_169 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_169 ) {
F_6 ( L_75 ) ;
V_177 = - V_127 ;
goto V_130;
}
V_169 [ V_1 ++ ] = L_139 ;
V_169 [ V_1 ++ ] = V_175 ;
if ( V_172 )
V_169 [ V_1 ++ ] = L_140 ;
V_169 [ V_1 ++ ] = L_141 ;
V_169 [ V_1 ++ ] = L_142 ;
V_169 [ V_1 ++ ] = L_143 ;
for ( V_7 = V_191 + 1 ; V_7 < T_4 ; V_7 ++ )
V_169 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_169 [ V_1 ++ ] = NULL ;
F_94 ( L_139 , ( char * * ) V_169 ) ;
free ( V_169 ) ;
exit ( - 1 ) ;
}
F_92 ( V_190 [ 0 ] , 0 ) ;
F_93 ( V_190 [ 1 ] ) ;
V_169 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_169 ) {
F_6 ( L_75 ) ;
V_177 = - V_127 ;
goto V_130;
}
V_1 = 0 ;
V_169 [ V_1 ++ ] = L_139 ;
V_169 [ V_1 ++ ] = V_176 ;
for ( V_7 = 1 ; V_7 < V_191 + 1 ; V_7 ++ )
V_169 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_169 [ V_1 ++ ] = L_144 ;
V_169 [ V_1 ++ ] = L_143 ;
V_169 [ V_1 ++ ] = NULL ;
F_94 ( L_139 , ( char * * ) V_169 ) ;
free ( V_169 ) ;
exit ( - 1 ) ;
}
if ( V_175 )
V_160 = V_175 ;
if ( V_176 )
V_160 = V_176 ;
if ( V_160 ) {
V_1 = 0 ;
if ( ! V_175 )
V_172 = false ;
else if ( ! V_172 ) {
if ( F_78 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_177 = - 1 ;
goto V_130;
}
}
V_169 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_169 ) {
F_6 ( L_75 ) ;
V_177 = - V_127 ;
goto V_130;
}
V_169 [ V_1 ++ ] = L_139 ;
V_169 [ V_1 ++ ] = V_160 ;
if ( V_172 )
V_169 [ V_1 ++ ] = L_140 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_169 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_169 [ V_1 ++ ] = NULL ;
F_94 ( L_139 , ( char * * ) V_169 ) ;
free ( V_169 ) ;
exit ( - 1 ) ;
}
if ( F_95 () < 0 )
return - 1 ;
if ( ! V_122 )
F_96 () ;
V_20 = F_97 ( V_174 , V_193 , 0 , false ,
& V_109 ) ;
if ( V_20 == NULL )
return - V_127 ;
if ( V_100 ) {
if ( F_98 ( V_20 , V_100 , V_101 ) )
return - 1 ;
}
F_99 ( V_20 , stdout , V_173 ) ;
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_181 ) {
struct V_136 V_194 ;
int V_195 ;
if ( F_1 () ) {
fprintf ( V_116 ,
L_145 ) ;
return - 1 ;
}
V_195 = F_100 ( V_20 -> V_148 , V_193 ) ;
if ( V_195 < 0 ) {
perror ( L_146 ) ;
return - 1 ;
}
V_177 = F_101 ( V_195 , & V_194 ) ;
if ( V_177 < 0 ) {
perror ( L_147 ) ;
return - 1 ;
}
if ( ! V_194 . V_196 ) {
fprintf ( V_116 , L_148 ) ;
return 0 ;
}
V_90 = F_48 ( V_181 ) ;
if ( ! V_90 ) {
fprintf ( V_116 , L_45 ) ;
return - 1 ;
}
V_177 = V_90 -> V_197 ( V_20 -> V_89 ,
L_149 ) ;
goto V_130;
}
if ( V_122 ) {
V_177 = V_90 -> V_198 ( V_122 , T_4 , T_5 ) ;
if ( V_177 )
goto V_130;
F_7 ( L_150 , V_122 ) ;
}
V_177 = F_11 ( V_20 ) ;
if ( V_177 < 0 )
goto V_130;
V_177 = F_39 ( V_20 ) ;
F_102 ( V_20 ) ;
F_33 () ;
V_130:
return V_177 ;
}
