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
if ( F_9 ( V_35 ) && ! F_9 ( V_34 ) ) {
F_6 ( L_11
L_12 ) ;
return - V_23 ;
}
if ( F_9 ( V_36 ) && ! F_9 ( V_24 ) && ! F_9 ( V_31 ) ) {
F_6 ( L_13
L_9
L_14 ) ;
return - V_23 ;
}
if ( ( F_9 ( V_37 ) || F_9 ( V_38 ) ) &&
F_4 ( V_12 , V_39 , L_15 ,
V_40 | V_41 ) )
return - V_23 ;
if ( F_9 ( TIME ) &&
F_4 ( V_12 , V_42 , L_16 ,
V_43 ) )
return - V_23 ;
if ( F_9 ( V_44 ) &&
F_4 ( V_12 , V_45 , L_17 ,
V_46 ) )
return - V_23 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 )
{
int V_1 ;
struct V_18 * V_19 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_19 = F_12 ( V_21 , V_1 ) ;
if ( ! V_19 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_47 ) {
F_6 ( L_18
L_19 ,
F_13 ( V_1 ) ) ;
return - 1 ;
}
if ( V_19 && V_3 [ V_1 ] . V_17 &&
F_8 ( V_19 , V_21 ) )
return - 1 ;
}
return 0 ;
}
static void F_14 ( struct V_48 * V_49 ,
struct V_50 * V_50 ,
struct V_11 * V_12 )
{
int type ;
struct V_51 * V_52 ;
const char * V_15 = NULL ;
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long long V_55 ;
if ( F_9 ( V_56 ) ) {
if ( V_57 )
printf ( L_20 , V_50 -> V_58 ) ;
else if ( F_9 ( V_24 ) && V_29 . V_30 )
printf ( L_21 , V_50 -> V_58 ) ;
else
printf ( L_22 , V_50 -> V_58 ) ;
}
if ( F_9 ( V_37 ) && F_9 ( V_38 ) )
printf ( L_23 , V_49 -> V_59 , V_49 -> V_60 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_49 -> V_59 ) ;
else if ( F_9 ( V_38 ) )
printf ( L_24 , V_49 -> V_60 ) ;
if ( F_9 ( V_44 ) ) {
if ( V_57 )
printf ( L_25 , V_49 -> V_61 ) ;
else
printf ( L_26 , V_49 -> V_61 ) ;
}
if ( F_9 ( TIME ) ) {
V_55 = V_49 -> time ;
V_53 = V_55 / V_62 ;
V_55 -= V_53 * V_62 ;
V_54 = V_55 / V_63 ;
printf ( L_27 , V_53 , V_54 ) ;
}
if ( F_9 ( V_64 ) ) {
if ( V_12 -> type == V_65 ) {
type = F_15 ( V_49 -> V_66 ) ;
V_52 = F_16 ( type ) ;
if ( V_52 )
V_15 = V_52 -> V_67 ;
} else
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
printf ( L_28 , V_15 ? V_15 : L_29 ) ;
}
}
static bool F_17 ( struct V_11 * V_12 )
{
return ( ( V_12 -> type == V_68 ) &&
( V_12 -> V_16 & V_69 ) &&
( V_12 -> V_70 == 1 ) ) ;
}
static bool F_18 ( struct V_11 * V_12 )
{
if ( ( V_12 -> type == V_71 ) &&
( ( V_12 -> V_16 == V_72 ) ||
( V_12 -> V_16 == V_73 ) ||
( V_12 -> V_16 == V_74 ) ) )
return true ;
if ( F_17 ( V_12 ) )
return true ;
return false ;
}
static void F_19 ( union V_75 * V_52 ,
struct V_48 * V_49 ,
struct V_76 * V_76 ,
struct V_50 * V_50 ,
struct V_11 * V_12 )
{
struct V_77 V_78 ;
T_2 V_79 = V_52 -> V_80 . V_81 & V_82 ;
printf ( L_30 V_83 , V_49 -> V_84 ) ;
if ( ! F_18 ( V_12 ) )
return;
F_20 ( V_50 , V_76 , V_79 , V_85 ,
V_49 -> V_84 , & V_78 ) ;
if ( ! V_78 . V_86 )
F_20 ( V_50 , V_76 , V_79 , V_87 ,
V_49 -> V_84 , & V_78 ) ;
V_78 . V_61 = V_49 -> V_61 ;
V_78 . V_88 = NULL ;
if ( V_78 . V_86 )
V_78 . V_88 = F_21 ( V_78 . V_86 , V_78 . V_84 , NULL ) ;
if ( F_9 ( V_34 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_35 ) )
F_22 ( V_78 . V_88 , & V_78 , stdout ) ;
else
F_23 ( V_78 . V_88 , stdout ) ;
}
if ( F_9 ( V_36 ) ) {
printf ( L_32 ) ;
F_24 ( V_78 . V_86 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_25 ( union V_75 * V_52 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_76 * V_76 ,
struct V_50 * V_50 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_52 , V_49 , V_76 , V_19 ,
F_9 ( V_34 ) , F_9 ( V_36 ) ,
F_9 ( V_35 ) ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_31 ) )
F_19 ( V_52 , V_49 , V_76 , V_50 , V_12 ) ;
printf ( L_34 ) ;
}
static void F_27 ( union V_75 * V_52 V_89 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_76 * V_76 ,
struct V_50 * V_50 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( V_3 [ V_12 -> type ] . V_17 == 0 )
return;
F_14 ( V_49 , V_50 , V_12 ) ;
if ( F_17 ( V_12 ) ) {
F_25 ( V_52 , V_49 , V_19 , V_76 , V_50 ) ;
return;
}
if ( F_9 ( V_22 ) )
F_28 ( V_49 -> V_61 , V_49 -> V_66 ,
V_49 -> V_90 ) ;
if ( F_9 ( V_31 ) )
F_19 ( V_52 , V_49 , V_76 , V_50 , V_12 ) ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_52 , V_49 , V_76 , V_19 ,
F_9 ( V_34 ) , F_9 ( V_36 ) ,
F_9 ( V_35 ) ) ;
}
printf ( L_34 ) ;
}
static int F_29 ( const char * T_3 V_89 ,
int T_4 V_89 ,
const char * * T_5 V_89 )
{
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( const char * T_6 V_89 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_91 = & V_92 ;
}
static int F_35 ( void )
{
F_7 ( L_36 ) ;
return V_91 -> V_93 () ;
}
static int F_36 ( struct V_94 * T_7 V_95 ,
union V_75 * V_52 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_76 * V_76 )
{
struct V_77 V_78 ;
struct V_50 * V_50 = F_37 ( V_76 , V_52 -> V_96 . V_60 ) ;
if ( V_50 == NULL ) {
F_7 ( L_37 ,
V_52 -> V_80 . type ) ;
return - 1 ;
}
if ( V_97 ) {
if ( V_49 -> time < V_98 ) {
F_6 ( L_38 V_99
L_39 V_99 L_34 , V_98 ,
V_49 -> time ) ;
V_100 ++ ;
}
V_98 = V_49 -> time ;
return 0 ;
}
if ( F_38 ( V_52 , V_76 , & V_78 , V_49 , 0 ) < 0 ) {
F_6 ( L_37 ,
V_52 -> V_80 . type ) ;
return - 1 ;
}
if ( V_78 . V_101 )
return 0 ;
if ( V_102 && ! F_39 ( V_49 -> V_61 , V_103 ) )
return 0 ;
V_91 -> F_27 ( V_52 , V_49 , V_19 , V_76 , V_50 ) ;
V_19 -> V_104 . V_105 . V_106 += V_49 -> V_107 ;
return 0 ;
}
static void F_40 ( int T_8 V_89 )
{
V_108 = 1 ;
}
static int F_41 ( struct V_20 * V_21 )
{
int V_109 ;
signal ( V_110 , F_40 ) ;
V_109 = F_42 ( V_21 , & V_111 ) ;
if ( V_97 )
F_6 ( L_40 V_99 L_34 , V_100 ) ;
return V_109 ;
}
static struct V_112 * F_43 ( const char * V_113 ,
struct V_91 * V_114 )
{
struct V_112 * V_115 = malloc ( sizeof( * V_115 ) + strlen ( V_113 ) + 1 ) ;
if ( V_115 != NULL ) {
strcpy ( V_115 -> V_113 , V_113 ) ;
V_115 -> V_114 = V_114 ;
}
return V_115 ;
}
static void F_44 ( struct V_112 * V_115 )
{
F_45 ( & V_115 -> V_116 , & V_117 ) ;
}
static struct V_112 * F_46 ( const char * V_113 )
{
struct V_112 * V_115 ;
F_47 (s, &script_specs, node)
if ( strcasecmp ( V_115 -> V_113 , V_113 ) == 0 )
return V_115 ;
return NULL ;
}
static struct V_112 * F_48 ( const char * V_113 ,
struct V_91 * V_114 )
{
struct V_112 * V_115 = F_46 ( V_113 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_43 ( V_113 , V_114 ) ;
if ( ! V_115 )
return NULL ;
F_44 ( V_115 ) ;
return V_115 ;
}
int F_49 ( const char * V_113 , struct V_91 * V_114 )
{
struct V_112 * V_115 ;
V_115 = F_46 ( V_113 ) ;
if ( V_115 )
return - 1 ;
V_115 = F_48 ( V_113 , V_114 ) ;
if ( ! V_115 )
return - 1 ;
return 0 ;
}
static struct V_91 * F_50 ( const char * V_113 )
{
struct V_112 * V_115 = F_46 ( V_113 ) ;
if ( ! V_115 )
return NULL ;
return V_115 -> V_114 ;
}
static void F_51 ( void )
{
struct V_112 * V_115 ;
fprintf ( V_118 , L_34 ) ;
fprintf ( V_118 , L_41
L_42 ) ;
F_47 (s, &script_specs, node)
fprintf ( V_118 , L_43 , V_115 -> V_113 , V_115 -> V_114 -> V_67 ) ;
fprintf ( V_118 , L_34 ) ;
}
static int F_52 ( const struct V_119 * T_9 V_95 ,
const char * V_10 , int T_10 V_95 )
{
char V_113 [ V_120 ] ;
const char * T_3 , * V_121 ;
int V_122 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_51 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_122 = T_3 - V_10 ;
if ( V_122 >= V_120 ) {
fprintf ( V_118 , L_45 ) ;
return - 1 ;
}
strncpy ( V_113 , V_10 , V_122 ) ;
V_113 [ V_122 ] = '\0' ;
V_91 = F_50 ( V_113 ) ;
if ( ! V_91 ) {
fprintf ( V_118 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_121 = strrchr ( T_3 , '.' ) ;
if ( ! V_121 ) {
fprintf ( V_118 , L_46 ) ;
return - 1 ;
}
V_91 = F_50 ( ++ V_121 ) ;
if ( ! V_91 ) {
fprintf ( V_118 , L_46 ) ;
return - 1 ;
}
}
V_123 = F_53 ( T_3 ) ;
return 0 ;
}
static int F_54 ( const struct V_119 * T_9 V_95 ,
const char * V_124 , int T_10 V_95 )
{
char * V_125 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_126 ) ;
int V_1 ;
int V_127 = 0 ;
char * V_10 = F_53 ( V_124 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_128 ;
V_125 = strchr ( V_10 , ':' ) ;
if ( V_125 ) {
* V_125 = '\0' ;
V_125 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_68 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_71 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_65 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_129 ;
else {
fprintf ( V_118 , L_51 ) ;
V_127 = - V_23 ;
goto V_130;
}
if ( V_3 [ type ] . V_4 )
F_55 ( L_52 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_17 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_47 = false ;
} else {
V_125 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_118 ,
L_53 ) ;
V_127 = - V_23 ;
goto V_130;
}
if ( F_1 () )
F_55 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_17 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_47 = true ;
}
}
V_125 = strtok ( V_125 , L_55 ) ;
while ( V_125 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_125 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_118 , L_56 ) ;
V_127 = - V_23 ;
goto V_130;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_131 & V_9 [ V_7 ] . V_6 ) {
F_55 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_131 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_118 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_127 = - V_23 ;
goto V_130;
}
V_3 [ type ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
V_125 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_17 == 0 ) {
F_7 ( L_59
L_60 , F_13 ( type ) ) ;
}
}
V_130:
free ( V_10 ) ;
return V_127 ;
}
static int F_56 ( const char * V_132 , const struct V_133 * V_134 )
{
char V_135 [ V_120 ] ;
struct V_136 V_137 ;
sprintf ( V_135 , L_61 , V_132 , V_134 -> V_138 ) ;
if ( V_136 ( V_135 , & V_137 ) )
return 0 ;
return F_57 ( V_137 . V_139 ) ;
}
static struct V_140 * F_58 ( const char * V_67 )
{
struct V_140 * V_115 = F_59 ( sizeof( * V_115 ) ) ;
if ( V_115 != NULL && V_67 )
V_115 -> V_67 = F_53 ( V_67 ) ;
return V_115 ;
}
static void F_60 ( struct V_140 * V_115 )
{
free ( V_115 -> V_67 ) ;
free ( V_115 -> V_141 ) ;
free ( V_115 -> args ) ;
free ( V_115 ) ;
}
static void F_61 ( struct V_140 * V_115 )
{
F_45 ( & V_115 -> V_116 , & V_142 ) ;
}
static struct V_140 * F_62 ( const char * V_67 )
{
struct V_140 * V_115 ;
F_47 (s, &script_descs, node)
if ( strcasecmp ( V_115 -> V_67 , V_67 ) == 0 )
return V_115 ;
return NULL ;
}
static struct V_140 * F_63 ( const char * V_67 )
{
struct V_140 * V_115 = F_62 ( V_67 ) ;
if ( V_115 )
return V_115 ;
V_115 = F_58 ( V_67 ) ;
if ( ! V_115 )
goto V_143;
F_61 ( V_115 ) ;
return V_115 ;
V_143:
F_60 ( V_115 ) ;
return NULL ;
}
static const char * F_64 ( const char * V_10 , const char * V_144 )
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
static char * F_65 ( char * V_10 )
{
int V_122 = strlen ( V_10 ) ;
while ( V_122 && isspace ( * V_10 ) ) {
V_122 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_66 ( struct V_140 * V_147 , const char * V_148 )
{
char line [ V_149 ] , * V_146 ;
T_12 * V_150 ;
V_150 = fopen ( V_148 , L_62 ) ;
if ( ! V_150 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_150 ) ) {
V_146 = F_65 ( line ) ;
if ( strlen ( V_146 ) == 0 )
continue;
if ( * V_146 != '#' )
continue;
V_146 ++ ;
if ( strlen ( V_146 ) && * V_146 == '!' )
continue;
V_146 = F_65 ( V_146 ) ;
if ( strlen ( V_146 ) && V_146 [ strlen ( V_146 ) - 1 ] == '\n' )
V_146 [ strlen ( V_146 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_146 , L_63 , strlen ( L_63 ) ) ) {
V_146 += strlen ( L_63 ) ;
V_147 -> V_141 = F_53 ( F_65 ( V_146 ) ) ;
continue;
}
if ( ! strncmp ( V_146 , L_64 , strlen ( L_64 ) ) ) {
V_146 += strlen ( L_64 ) ;
V_147 -> args = F_53 ( F_65 ( V_146 ) ) ;
continue;
}
}
fclose ( V_150 ) ;
return 0 ;
}
static char * F_67 ( struct V_133 * V_151 , const char * V_144 )
{
char * V_152 , * V_10 ;
V_152 = F_53 ( V_151 -> V_138 ) ;
if ( ! V_152 )
return NULL ;
V_10 = ( char * ) F_64 ( V_152 , V_144 ) ;
if ( ! V_10 ) {
free ( V_152 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_152 ;
}
static int F_68 ( const struct V_119 * T_9 V_95 ,
const char * V_115 V_95 , int T_10 V_95 )
{
struct V_133 * V_153 , * V_154 , V_151 , V_155 ;
char V_156 [ V_157 ] ;
T_13 * V_158 , * V_159 ;
char V_160 [ V_157 ] ;
char V_161 [ V_157 ] ;
struct V_140 * V_147 ;
char V_162 [ V_149 ] ;
char * V_152 ;
snprintf ( V_156 , V_157 , L_65 , F_69 () ) ;
V_158 = F_70 ( V_156 ) ;
if ( ! V_158 )
return - 1 ;
F_71 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_161 , V_157 , L_66 , V_156 ,
V_155 . V_138 ) ;
V_159 = F_70 ( V_161 ) ;
if ( ! V_159 )
continue;
F_72 (lang_path, lang_dir, script_dirent, script_next) {
V_152 = F_67 ( & V_151 , V_163 ) ;
if ( V_152 ) {
V_147 = F_63 ( V_152 ) ;
snprintf ( V_160 , V_157 , L_61 ,
V_161 , V_151 . V_138 ) ;
F_66 ( V_147 , V_160 ) ;
free ( V_152 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_47 (desc, &script_descs, node) {
sprintf ( V_162 , L_68 , V_147 -> V_67 ,
V_147 -> args ? V_147 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_162 ,
V_147 -> V_141 ? V_147 -> V_141 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_73 ( const char * V_152 , const char * V_144 )
{
struct V_133 * V_153 , * V_154 , V_151 , V_155 ;
char V_156 [ V_157 ] ;
char V_160 [ V_157 ] ;
T_13 * V_158 , * V_159 ;
char V_161 [ V_157 ] ;
char * V_164 ;
snprintf ( V_156 , V_157 , L_65 , F_69 () ) ;
V_158 = F_70 ( V_156 ) ;
if ( ! V_158 )
return NULL ;
F_71 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_161 , V_157 , L_66 , V_156 ,
V_155 . V_138 ) ;
V_159 = F_70 ( V_161 ) ;
if ( ! V_159 )
continue;
F_72 (lang_path, lang_dir, script_dirent, script_next) {
V_164 = F_67 ( & V_151 , V_144 ) ;
if ( V_164 && ! strcmp ( V_152 , V_164 ) ) {
free ( V_164 ) ;
F_74 ( V_159 ) ;
F_74 ( V_158 ) ;
snprintf ( V_160 , V_157 , L_61 ,
V_161 , V_151 . V_138 ) ;
return F_53 ( V_160 ) ;
}
free ( V_164 ) ;
}
F_74 ( V_159 ) ;
}
F_74 ( V_158 ) ;
return NULL ;
}
static bool F_75 ( const char * V_160 )
{
return F_64 ( V_160 , L_70 ) == NULL ? false : true ;
}
static int F_76 ( char * V_160 )
{
struct V_140 * V_147 ;
int V_165 = 0 ;
char * V_146 ;
V_147 = F_58 ( NULL ) ;
if ( F_66 ( V_147 , V_160 ) )
goto V_130;
if ( ! V_147 -> args )
goto V_130;
for ( V_146 = V_147 -> args ; * V_146 ; V_146 ++ )
if ( * V_146 == '<' )
V_165 ++ ;
V_130:
F_60 ( V_147 ) ;
return V_165 ;
}
static bool F_77 ( int T_4 , const char * * T_5 )
{
char * * V_166 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_166 )
F_78 ( L_71 ) ;
memcpy ( V_166 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_79 ( T_4 , ( const char * * ) V_166 , V_167 ,
NULL , V_168 ) ;
free ( V_166 ) ;
return T_4 != 0 ;
}
int F_80 ( int T_4 , const char * * T_5 , const char * T_14 V_95 )
{
char * V_169 = NULL ;
char * V_170 = NULL ;
struct V_20 * V_21 ;
char * V_160 = NULL ;
const char * * V_166 ;
int V_7 , V_1 , V_171 ;
F_32 () ;
T_4 = F_79 ( T_4 , T_5 , V_172 , V_173 ,
V_168 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_72 , strlen ( L_72 ) ) ) {
V_169 = F_73 ( T_5 [ 1 ] , V_174 ) ;
if ( ! V_169 )
return F_81 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_73 , strlen ( L_73 ) ) ) {
V_170 = F_73 ( T_5 [ 1 ] , V_163 ) ;
if ( ! V_170 ) {
fprintf ( V_118 ,
L_74
L_75 ) ;
return - 1 ;
}
}
F_82 ( F_69 () ) ;
if ( T_4 && ! V_123 && ! V_169 && ! V_170 ) {
int V_175 [ 2 ] ;
int V_176 ;
T_15 V_59 ;
V_169 = F_73 ( T_5 [ 0 ] , V_174 ) ;
V_170 = F_73 ( T_5 [ 0 ] , V_163 ) ;
if ( ! V_169 && ! V_170 ) {
fprintf ( V_118 , L_76
L_77 , T_5 [ 0 ] ) ;
F_83 ( V_173 , V_172 ) ;
}
if ( F_75 ( T_5 [ 0 ] ) ) {
V_176 = T_4 - 1 ;
} else {
int V_177 ;
V_176 = F_76 ( V_170 ) ;
V_177 = ( T_4 - 1 ) - V_176 ;
if ( V_177 < 0 ) {
fprintf ( V_118 , L_78
L_79
L_80 , T_5 [ 0 ] ) ;
F_83 ( V_173 , V_172 ) ;
}
}
if ( F_84 ( V_175 ) < 0 ) {
perror ( L_81 ) ;
exit ( - 1 ) ;
}
V_59 = F_85 () ;
if ( V_59 < 0 ) {
perror ( L_82 ) ;
exit ( - 1 ) ;
}
if ( ! V_59 ) {
V_1 = 0 ;
F_86 ( V_175 [ 1 ] , 1 ) ;
F_87 ( V_175 [ 0 ] ) ;
if ( F_75 ( T_5 [ 0 ] ) ) {
V_178 = true ;
} else if ( ! V_178 ) {
V_178 = ! F_77 ( T_4 - V_176 ,
& T_5 [ V_176 ] ) ;
}
V_166 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_166 )
F_78 ( L_71 ) ;
V_166 [ V_1 ++ ] = L_83 ;
V_166 [ V_1 ++ ] = V_169 ;
if ( V_178 )
V_166 [ V_1 ++ ] = L_84 ;
V_166 [ V_1 ++ ] = L_85 ;
V_166 [ V_1 ++ ] = L_86 ;
V_166 [ V_1 ++ ] = L_87 ;
for ( V_7 = V_176 + 1 ; V_7 < T_4 ; V_7 ++ )
V_166 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_166 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_166 ) ;
free ( V_166 ) ;
exit ( - 1 ) ;
}
F_86 ( V_175 [ 0 ] , 0 ) ;
F_87 ( V_175 [ 1 ] ) ;
V_166 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_166 )
F_78 ( L_71 ) ;
V_1 = 0 ;
V_166 [ V_1 ++ ] = L_83 ;
V_166 [ V_1 ++ ] = V_170 ;
for ( V_7 = 1 ; V_7 < V_176 + 1 ; V_7 ++ )
V_166 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_166 [ V_1 ++ ] = L_88 ;
V_166 [ V_1 ++ ] = L_87 ;
V_166 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_166 ) ;
free ( V_166 ) ;
exit ( - 1 ) ;
}
if ( V_169 )
V_160 = V_169 ;
if ( V_170 )
V_160 = V_170 ;
if ( V_160 ) {
V_1 = 0 ;
if ( ! V_169 )
V_178 = false ;
else if ( ! V_178 )
V_178 = ! F_77 ( T_4 - 1 , & T_5 [ 1 ] ) ;
V_166 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_166 )
F_78 ( L_71 ) ;
V_166 [ V_1 ++ ] = L_83 ;
V_166 [ V_1 ++ ] = V_160 ;
if ( V_178 )
V_166 [ V_1 ++ ] = L_84 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_166 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_166 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_166 ) ;
free ( V_166 ) ;
exit ( - 1 ) ;
}
if ( F_89 () < 0 )
return - 1 ;
if ( ! V_123 )
F_90 () ;
V_21 = F_91 ( V_179 , V_180 , 0 , false , & V_111 ) ;
if ( V_21 == NULL )
return - V_128 ;
if ( V_102 ) {
if ( F_92 ( V_21 , V_102 , V_103 ) )
return - 1 ;
}
F_93 ( V_21 , stdout , V_181 ) ;
if ( ! V_27 )
V_29 . V_30 = true ;
else
V_29 . V_30 = false ;
if ( V_182 ) {
struct V_136 V_183 ;
int V_184 ;
if ( F_1 () ) {
fprintf ( V_118 ,
L_89 ) ;
return - 1 ;
}
V_184 = F_94 ( V_21 -> V_148 , V_180 ) ;
if ( V_184 < 0 ) {
perror ( L_90 ) ;
exit ( - 1 ) ;
}
V_171 = F_95 ( V_184 , & V_183 ) ;
if ( V_171 < 0 ) {
perror ( L_91 ) ;
exit ( - 1 ) ;
}
if ( ! V_183 . V_185 ) {
fprintf ( V_118 , L_92 ) ;
exit ( 0 ) ;
}
V_91 = F_50 ( V_182 ) ;
if ( ! V_91 ) {
fprintf ( V_118 , L_45 ) ;
return - 1 ;
}
V_171 = V_91 -> V_186 ( L_93 ) ;
goto V_130;
}
if ( V_123 ) {
V_171 = V_91 -> V_187 ( V_123 , T_4 , T_5 ) ;
if ( V_171 )
goto V_130;
F_7 ( L_94 , V_123 ) ;
}
V_171 = F_11 ( V_21 ) ;
if ( V_171 < 0 )
goto V_130;
V_171 = F_41 ( V_21 ) ;
F_96 ( V_21 ) ;
F_35 () ;
V_130:
return V_171 ;
}
