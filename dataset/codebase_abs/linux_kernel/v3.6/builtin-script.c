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
static void F_14 ( struct V_47 * V_47 ,
struct V_48 * V_49 ,
struct V_50 * V_50 ,
struct V_11 * V_12 )
{
int type ;
struct V_15 * V_16 = & V_12 -> V_16 ;
struct V_51 * V_52 ;
const char * V_17 = NULL ;
unsigned long V_53 ;
unsigned long V_54 ;
unsigned long long V_55 ;
if ( F_9 ( V_56 ) ) {
if ( V_57 )
printf ( L_20 , V_50 -> V_58 ) ;
else if ( F_9 ( V_23 ) && V_28 . V_29 )
printf ( L_21 , V_50 -> V_58 ) ;
else
printf ( L_22 , V_50 -> V_58 ) ;
}
if ( F_9 ( V_36 ) && F_9 ( V_37 ) )
printf ( L_23 , V_49 -> V_59 , V_49 -> V_60 ) ;
else if ( F_9 ( V_36 ) )
printf ( L_24 , V_49 -> V_59 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_49 -> V_60 ) ;
if ( F_9 ( V_43 ) ) {
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
if ( V_16 -> type == V_65 ) {
type = F_15 ( V_47 ,
V_49 -> V_66 ) ;
V_52 = F_16 ( V_47 , type ) ;
if ( V_52 )
V_17 = V_52 -> V_67 ;
} else
V_17 = F_5 ( V_12 ) ;
printf ( L_28 , V_17 ? V_17 : L_29 ) ;
}
}
static bool F_17 ( struct V_15 * V_16 )
{
return ( ( V_16 -> type == V_68 ) &&
( V_16 -> V_69 & V_70 ) &&
( V_16 -> V_71 == 1 ) ) ;
}
static bool F_18 ( struct V_15 * V_16 )
{
if ( ( V_16 -> type == V_72 ) &&
( ( V_16 -> V_69 == V_73 ) ||
( V_16 -> V_69 == V_74 ) ||
( V_16 -> V_69 == V_75 ) ) )
return true ;
if ( F_17 ( V_16 ) )
return true ;
return false ;
}
static void F_19 ( union V_76 * V_52 ,
struct V_48 * V_49 ,
struct V_77 * V_77 ,
struct V_50 * V_50 ,
struct V_15 * V_16 )
{
struct V_78 V_79 ;
T_2 V_80 = V_52 -> V_81 . V_82 & V_83 ;
printf ( L_30 V_84 , V_49 -> V_85 ) ;
if ( ! F_18 ( V_16 ) )
return;
F_20 ( V_50 , V_77 , V_80 , V_86 ,
V_49 -> V_85 , & V_79 ) ;
if ( ! V_79 . V_87 )
F_20 ( V_50 , V_77 , V_80 , V_88 ,
V_49 -> V_85 , & V_79 ) ;
V_79 . V_61 = V_49 -> V_61 ;
V_79 . V_89 = NULL ;
if ( V_79 . V_87 )
V_79 . V_89 = F_21 ( V_79 . V_87 , V_79 . V_85 , NULL ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_22 ( V_79 . V_89 , & V_79 , stdout ) ;
else
F_23 ( V_79 . V_89 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_24 ( V_79 . V_87 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_25 ( union V_76 * V_52 ,
struct V_48 * V_49 ,
struct V_11 * V_12 ,
struct V_77 * V_77 ,
struct V_50 * V_50 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_52 , V_49 , V_77 ,
F_9 ( V_33 ) , F_9 ( V_35 ) ,
F_9 ( V_34 ) ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_30 ) )
F_19 ( V_52 , V_49 , V_77 , V_50 , V_16 ) ;
printf ( L_34 ) ;
}
static void F_27 ( union V_76 * V_52 V_90 ,
struct V_47 * V_47 ,
struct V_48 * V_49 ,
struct V_11 * V_12 ,
struct V_77 * V_77 ,
struct V_50 * V_50 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_14 ( V_47 , V_49 , V_50 , V_12 ) ;
if ( F_17 ( V_16 ) ) {
F_25 ( V_52 , V_49 , V_12 , V_77 , V_50 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_28 ( V_47 , V_49 -> V_61 , V_49 -> V_66 ,
V_49 -> V_91 ) ;
if ( F_9 ( V_30 ) )
F_19 ( V_52 , V_49 , V_77 , V_50 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_52 , V_49 , V_77 ,
F_9 ( V_33 ) , F_9 ( V_35 ) ,
F_9 ( V_34 ) ) ;
}
printf ( L_34 ) ;
}
static int F_29 ( const char * T_3 V_90 ,
int T_4 V_90 ,
const char * * T_5 V_90 )
{
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( struct V_47 * V_47 V_90 ,
const char * T_6 V_90 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_92 = & V_93 ;
}
static int F_35 ( void )
{
F_7 ( L_36 ) ;
return V_92 -> V_94 () ;
}
static int F_36 ( struct V_95 * T_7 V_96 ,
union V_76 * V_52 ,
struct V_48 * V_49 ,
struct V_11 * V_12 ,
struct V_77 * V_77 )
{
struct V_78 V_79 ;
struct V_97 * V_98 = F_37 ( T_7 , struct V_97 , T_7 ) ;
struct V_50 * V_50 = F_38 ( V_77 , V_52 -> V_99 . V_60 ) ;
if ( V_50 == NULL ) {
F_7 ( L_37 ,
V_52 -> V_81 . type ) ;
return - 1 ;
}
if ( V_100 ) {
if ( V_49 -> time < V_101 ) {
F_6 ( L_38 V_102
L_39 V_102 L_34 , V_101 ,
V_49 -> time ) ;
V_103 ++ ;
}
V_101 = V_49 -> time ;
return 0 ;
}
if ( F_39 ( V_52 , V_77 , & V_79 , V_49 , 0 ) < 0 ) {
F_6 ( L_37 ,
V_52 -> V_81 . type ) ;
return - 1 ;
}
if ( V_79 . V_104 )
return 0 ;
if ( V_105 && ! F_40 ( V_49 -> V_61 , V_106 ) )
return 0 ;
V_92 -> F_27 ( V_52 , V_98 -> V_20 -> V_47 ,
V_49 , V_12 , V_77 , V_50 ) ;
V_12 -> V_107 . V_108 . V_109 += V_49 -> V_110 ;
return 0 ;
}
static void F_41 ( int T_8 V_90 )
{
V_111 = 1 ;
}
static int F_42 ( struct V_19 * V_20 )
{
int V_112 ;
signal ( V_113 , F_41 ) ;
V_112 = F_43 ( V_20 , & V_97 . T_7 ) ;
if ( V_100 )
F_6 ( L_40 V_102 L_34 , V_103 ) ;
return V_112 ;
}
static struct V_114 * F_44 ( const char * V_115 ,
struct V_92 * V_116 )
{
struct V_114 * V_117 = malloc ( sizeof( * V_117 ) + strlen ( V_115 ) + 1 ) ;
if ( V_117 != NULL ) {
strcpy ( V_117 -> V_115 , V_115 ) ;
V_117 -> V_116 = V_116 ;
}
return V_117 ;
}
static void F_45 ( struct V_114 * V_117 )
{
F_46 ( & V_117 -> V_118 , & V_119 ) ;
}
static struct V_114 * F_47 ( const char * V_115 )
{
struct V_114 * V_117 ;
F_48 (s, &script_specs, node)
if ( strcasecmp ( V_117 -> V_115 , V_115 ) == 0 )
return V_117 ;
return NULL ;
}
static struct V_114 * F_49 ( const char * V_115 ,
struct V_92 * V_116 )
{
struct V_114 * V_117 = F_47 ( V_115 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_44 ( V_115 , V_116 ) ;
if ( ! V_117 )
return NULL ;
F_45 ( V_117 ) ;
return V_117 ;
}
int F_50 ( const char * V_115 , struct V_92 * V_116 )
{
struct V_114 * V_117 ;
V_117 = F_47 ( V_115 ) ;
if ( V_117 )
return - 1 ;
V_117 = F_49 ( V_115 , V_116 ) ;
if ( ! V_117 )
return - 1 ;
return 0 ;
}
static struct V_92 * F_51 ( const char * V_115 )
{
struct V_114 * V_117 = F_47 ( V_115 ) ;
if ( ! V_117 )
return NULL ;
return V_117 -> V_116 ;
}
static void F_52 ( void )
{
struct V_114 * V_117 ;
fprintf ( V_120 , L_34 ) ;
fprintf ( V_120 , L_41
L_42 ) ;
F_48 (s, &script_specs, node)
fprintf ( V_120 , L_43 , V_117 -> V_115 , V_117 -> V_116 -> V_67 ) ;
fprintf ( V_120 , L_34 ) ;
}
static int F_53 ( const struct V_121 * T_9 V_96 ,
const char * V_10 , int T_10 V_96 )
{
char V_115 [ V_122 ] ;
const char * T_3 , * V_123 ;
int V_124 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_52 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_124 = T_3 - V_10 ;
if ( V_124 >= V_122 ) {
fprintf ( V_120 , L_45 ) ;
return - 1 ;
}
strncpy ( V_115 , V_10 , V_124 ) ;
V_115 [ V_124 ] = '\0' ;
V_92 = F_51 ( V_115 ) ;
if ( ! V_92 ) {
fprintf ( V_120 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_123 = strrchr ( T_3 , '.' ) ;
if ( ! V_123 ) {
fprintf ( V_120 , L_46 ) ;
return - 1 ;
}
V_92 = F_51 ( ++ V_123 ) ;
if ( ! V_92 ) {
fprintf ( V_120 , L_46 ) ;
return - 1 ;
}
}
V_125 = F_54 ( T_3 ) ;
return 0 ;
}
static int F_55 ( const struct V_121 * T_9 V_96 ,
const char * V_126 , int T_10 V_96 )
{
char * V_127 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_128 ) ;
int V_1 ;
int V_129 = 0 ;
char * V_10 = F_54 ( V_126 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_130 ;
V_127 = strchr ( V_10 , ':' ) ;
if ( V_127 ) {
* V_127 = '\0' ;
V_127 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_68 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_72 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_65 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_131 ;
else {
fprintf ( V_120 , L_51 ) ;
V_129 = - V_22 ;
goto V_132;
}
if ( V_3 [ type ] . V_4 )
F_56 ( L_52 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_46 = false ;
} else {
V_127 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_120 ,
L_53 ) ;
V_129 = - V_22 ;
goto V_132;
}
if ( F_1 () )
F_56 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_46 = true ;
}
}
V_127 = strtok ( V_127 , L_55 ) ;
while ( V_127 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_127 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_120 , L_56 ) ;
V_129 = - V_22 ;
goto V_132;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_133 & V_9 [ V_7 ] . V_6 ) {
F_56 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_133 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_120 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_129 = - V_22 ;
goto V_132;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_127 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_59
L_60 , F_13 ( type ) ) ;
}
}
V_132:
free ( V_10 ) ;
return V_129 ;
}
static int F_57 ( const char * V_134 , const struct V_135 * V_136 )
{
char V_137 [ V_122 ] ;
struct V_138 V_139 ;
sprintf ( V_137 , L_61 , V_134 , V_136 -> V_140 ) ;
if ( V_138 ( V_137 , & V_139 ) )
return 0 ;
return F_58 ( V_139 . V_141 ) ;
}
static struct V_142 * F_59 ( const char * V_67 )
{
struct V_142 * V_117 = F_60 ( sizeof( * V_117 ) ) ;
if ( V_117 != NULL && V_67 )
V_117 -> V_67 = F_54 ( V_67 ) ;
return V_117 ;
}
static void F_61 ( struct V_142 * V_117 )
{
free ( V_117 -> V_67 ) ;
free ( V_117 -> V_143 ) ;
free ( V_117 -> args ) ;
free ( V_117 ) ;
}
static void F_62 ( struct V_142 * V_117 )
{
F_46 ( & V_117 -> V_118 , & V_144 ) ;
}
static struct V_142 * F_63 ( const char * V_67 )
{
struct V_142 * V_117 ;
F_48 (s, &script_descs, node)
if ( strcasecmp ( V_117 -> V_67 , V_67 ) == 0 )
return V_117 ;
return NULL ;
}
static struct V_142 * F_64 ( const char * V_67 )
{
struct V_142 * V_117 = F_63 ( V_67 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_59 ( V_67 ) ;
if ( ! V_117 )
goto V_145;
F_62 ( V_117 ) ;
return V_117 ;
V_145:
F_61 ( V_117 ) ;
return NULL ;
}
static const char * F_65 ( const char * V_10 , const char * V_146 )
{
T_11 V_147 = strlen ( V_146 ) ;
const char * V_148 = V_10 ;
if ( strlen ( V_10 ) > V_147 ) {
V_148 = V_10 + strlen ( V_10 ) - V_147 ;
if ( ! strncmp ( V_148 , V_146 , V_147 ) )
return V_148 ;
}
return NULL ;
}
static char * F_66 ( char * V_10 )
{
int V_124 = strlen ( V_10 ) ;
while ( V_124 && isspace ( * V_10 ) ) {
V_124 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_67 ( struct V_142 * V_149 , const char * V_150 )
{
char line [ V_151 ] , * V_148 ;
T_12 * V_152 ;
V_152 = fopen ( V_150 , L_62 ) ;
if ( ! V_152 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_152 ) ) {
V_148 = F_66 ( line ) ;
if ( strlen ( V_148 ) == 0 )
continue;
if ( * V_148 != '#' )
continue;
V_148 ++ ;
if ( strlen ( V_148 ) && * V_148 == '!' )
continue;
V_148 = F_66 ( V_148 ) ;
if ( strlen ( V_148 ) && V_148 [ strlen ( V_148 ) - 1 ] == '\n' )
V_148 [ strlen ( V_148 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_148 , L_63 , strlen ( L_63 ) ) ) {
V_148 += strlen ( L_63 ) ;
V_149 -> V_143 = F_54 ( F_66 ( V_148 ) ) ;
continue;
}
if ( ! strncmp ( V_148 , L_64 , strlen ( L_64 ) ) ) {
V_148 += strlen ( L_64 ) ;
V_149 -> args = F_54 ( F_66 ( V_148 ) ) ;
continue;
}
}
fclose ( V_152 ) ;
return 0 ;
}
static char * F_68 ( struct V_135 * V_153 , const char * V_146 )
{
char * V_154 , * V_10 ;
V_154 = F_54 ( V_153 -> V_140 ) ;
if ( ! V_154 )
return NULL ;
V_10 = ( char * ) F_65 ( V_154 , V_146 ) ;
if ( ! V_10 ) {
free ( V_154 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_154 ;
}
static int F_69 ( const struct V_121 * T_9 V_96 ,
const char * V_117 V_96 , int T_10 V_96 )
{
struct V_135 * V_155 , * V_156 , V_153 , V_157 ;
char V_158 [ V_159 ] ;
T_13 * V_160 , * V_161 ;
char V_162 [ V_159 ] ;
char V_163 [ V_159 ] ;
struct V_142 * V_149 ;
char V_164 [ V_151 ] ;
char * V_154 ;
snprintf ( V_158 , V_159 , L_65 , F_70 () ) ;
V_160 = F_71 ( V_158 ) ;
if ( ! V_160 )
return - 1 ;
F_72 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_163 , V_159 , L_66 , V_158 ,
V_157 . V_140 ) ;
V_161 = F_71 ( V_163 ) ;
if ( ! V_161 )
continue;
F_73 (lang_path, lang_dir, script_dirent, script_next) {
V_154 = F_68 ( & V_153 , V_165 ) ;
if ( V_154 ) {
V_149 = F_64 ( V_154 ) ;
snprintf ( V_162 , V_159 , L_61 ,
V_163 , V_153 . V_140 ) ;
F_67 ( V_149 , V_162 ) ;
free ( V_154 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_48 (desc, &script_descs, node) {
sprintf ( V_164 , L_68 , V_149 -> V_67 ,
V_149 -> args ? V_149 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_164 ,
V_149 -> V_143 ? V_149 -> V_143 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_74 ( const char * V_154 , const char * V_146 )
{
struct V_135 * V_155 , * V_156 , V_153 , V_157 ;
char V_158 [ V_159 ] ;
char V_162 [ V_159 ] ;
T_13 * V_160 , * V_161 ;
char V_163 [ V_159 ] ;
char * V_166 ;
snprintf ( V_158 , V_159 , L_65 , F_70 () ) ;
V_160 = F_71 ( V_158 ) ;
if ( ! V_160 )
return NULL ;
F_72 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_163 , V_159 , L_66 , V_158 ,
V_157 . V_140 ) ;
V_161 = F_71 ( V_163 ) ;
if ( ! V_161 )
continue;
F_73 (lang_path, lang_dir, script_dirent, script_next) {
V_166 = F_68 ( & V_153 , V_146 ) ;
if ( V_166 && ! strcmp ( V_154 , V_166 ) ) {
free ( V_166 ) ;
F_75 ( V_161 ) ;
F_75 ( V_160 ) ;
snprintf ( V_162 , V_159 , L_61 ,
V_163 , V_153 . V_140 ) ;
return F_54 ( V_162 ) ;
}
free ( V_166 ) ;
}
F_75 ( V_161 ) ;
}
F_75 ( V_160 ) ;
return NULL ;
}
static bool F_76 ( const char * V_162 )
{
return F_65 ( V_162 , L_70 ) == NULL ? false : true ;
}
static int F_77 ( char * V_162 )
{
struct V_142 * V_149 ;
int V_167 = 0 ;
char * V_148 ;
V_149 = F_59 ( NULL ) ;
if ( F_67 ( V_149 , V_162 ) )
goto V_132;
if ( ! V_149 -> args )
goto V_132;
for ( V_148 = V_149 -> args ; * V_148 ; V_148 ++ )
if ( * V_148 == '<' )
V_167 ++ ;
V_132:
F_61 ( V_149 ) ;
return V_167 ;
}
static bool F_78 ( int T_4 , const char * * T_5 )
{
char * * V_168 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_168 )
F_79 ( L_71 ) ;
memcpy ( V_168 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_80 ( T_4 , ( const char * * ) V_168 , V_169 ,
NULL , V_170 ) ;
free ( V_168 ) ;
return T_4 != 0 ;
}
int F_81 ( int T_4 , const char * * T_5 , const char * T_14 V_96 )
{
char * V_171 = NULL ;
char * V_172 = NULL ;
struct V_19 * V_20 ;
char * V_162 = NULL ;
const char * * V_168 ;
int V_7 , V_1 , V_173 ;
F_32 () ;
T_4 = F_80 ( T_4 , T_5 , V_174 , V_175 ,
V_170 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_72 , strlen ( L_72 ) ) ) {
V_171 = F_74 ( T_5 [ 1 ] , V_176 ) ;
if ( ! V_171 )
return F_82 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_73 , strlen ( L_73 ) ) ) {
V_172 = F_74 ( T_5 [ 1 ] , V_165 ) ;
if ( ! V_172 ) {
fprintf ( V_120 ,
L_74
L_75 ) ;
return - 1 ;
}
}
F_83 ( F_70 () ) ;
if ( T_4 && ! V_125 && ! V_171 && ! V_172 ) {
int V_177 [ 2 ] ;
int V_178 ;
T_15 V_59 ;
V_171 = F_74 ( T_5 [ 0 ] , V_176 ) ;
V_172 = F_74 ( T_5 [ 0 ] , V_165 ) ;
if ( ! V_171 && ! V_172 ) {
fprintf ( V_120 , L_76
L_77 , T_5 [ 0 ] ) ;
F_84 ( V_175 , V_174 ) ;
}
if ( F_76 ( T_5 [ 0 ] ) ) {
V_178 = T_4 - 1 ;
} else {
int V_179 ;
V_178 = F_77 ( V_172 ) ;
V_179 = ( T_4 - 1 ) - V_178 ;
if ( V_179 < 0 ) {
fprintf ( V_120 , L_78
L_79
L_80 , T_5 [ 0 ] ) ;
F_84 ( V_175 , V_174 ) ;
}
}
if ( F_85 ( V_177 ) < 0 ) {
perror ( L_81 ) ;
exit ( - 1 ) ;
}
V_59 = F_86 () ;
if ( V_59 < 0 ) {
perror ( L_82 ) ;
exit ( - 1 ) ;
}
if ( ! V_59 ) {
V_1 = 0 ;
F_87 ( V_177 [ 1 ] , 1 ) ;
F_88 ( V_177 [ 0 ] ) ;
if ( F_76 ( T_5 [ 0 ] ) ) {
V_180 = true ;
} else if ( ! V_180 ) {
V_180 = ! F_78 ( T_4 - V_178 ,
& T_5 [ V_178 ] ) ;
}
V_168 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_168 )
F_79 ( L_71 ) ;
V_168 [ V_1 ++ ] = L_83 ;
V_168 [ V_1 ++ ] = V_171 ;
if ( V_180 )
V_168 [ V_1 ++ ] = L_84 ;
V_168 [ V_1 ++ ] = L_85 ;
V_168 [ V_1 ++ ] = L_86 ;
V_168 [ V_1 ++ ] = L_87 ;
for ( V_7 = V_178 + 1 ; V_7 < T_4 ; V_7 ++ )
V_168 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_168 [ V_1 ++ ] = NULL ;
F_89 ( L_83 , ( char * * ) V_168 ) ;
free ( V_168 ) ;
exit ( - 1 ) ;
}
F_87 ( V_177 [ 0 ] , 0 ) ;
F_88 ( V_177 [ 1 ] ) ;
V_168 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_168 )
F_79 ( L_71 ) ;
V_1 = 0 ;
V_168 [ V_1 ++ ] = L_83 ;
V_168 [ V_1 ++ ] = V_172 ;
for ( V_7 = 1 ; V_7 < V_178 + 1 ; V_7 ++ )
V_168 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_168 [ V_1 ++ ] = L_88 ;
V_168 [ V_1 ++ ] = L_87 ;
V_168 [ V_1 ++ ] = NULL ;
F_89 ( L_83 , ( char * * ) V_168 ) ;
free ( V_168 ) ;
exit ( - 1 ) ;
}
if ( V_171 )
V_162 = V_171 ;
if ( V_172 )
V_162 = V_172 ;
if ( V_162 ) {
V_1 = 0 ;
if ( ! V_171 )
V_180 = false ;
else if ( ! V_180 )
V_180 = ! F_78 ( T_4 - 1 , & T_5 [ 1 ] ) ;
V_168 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_168 )
F_79 ( L_71 ) ;
V_168 [ V_1 ++ ] = L_83 ;
V_168 [ V_1 ++ ] = V_162 ;
if ( V_180 )
V_168 [ V_1 ++ ] = L_84 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_168 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_168 [ V_1 ++ ] = NULL ;
F_89 ( L_83 , ( char * * ) V_168 ) ;
free ( V_168 ) ;
exit ( - 1 ) ;
}
if ( F_90 () < 0 )
return - 1 ;
if ( ! V_125 )
F_91 () ;
V_20 = F_92 ( V_181 , V_182 , 0 , false ,
& V_97 . T_7 ) ;
if ( V_20 == NULL )
return - V_130 ;
V_97 . V_20 = V_20 ;
if ( V_105 ) {
if ( F_93 ( V_20 , V_105 , V_106 ) )
return - 1 ;
}
F_94 ( V_20 , stdout , V_183 ) ;
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_184 ) {
struct V_138 V_185 ;
int V_186 ;
if ( F_1 () ) {
fprintf ( V_120 ,
L_89 ) ;
return - 1 ;
}
V_186 = F_95 ( V_20 -> V_150 , V_182 ) ;
if ( V_186 < 0 ) {
perror ( L_90 ) ;
exit ( - 1 ) ;
}
V_173 = F_96 ( V_186 , & V_185 ) ;
if ( V_173 < 0 ) {
perror ( L_91 ) ;
exit ( - 1 ) ;
}
if ( ! V_185 . V_187 ) {
fprintf ( V_120 , L_92 ) ;
exit ( 0 ) ;
}
V_92 = F_51 ( V_184 ) ;
if ( ! V_92 ) {
fprintf ( V_120 , L_45 ) ;
return - 1 ;
}
V_173 = V_92 -> V_188 ( V_20 -> V_47 ,
L_93 ) ;
goto V_132;
}
if ( V_125 ) {
V_173 = V_92 -> V_189 ( V_125 , T_4 , T_5 ) ;
if ( V_173 )
goto V_132;
F_7 ( L_94 , V_125 ) ;
}
V_173 = F_11 ( V_20 ) ;
if ( V_173 < 0 )
goto V_132;
V_173 = F_42 ( V_20 ) ;
F_97 ( V_20 ) ;
F_35 () ;
V_132:
return V_173 ;
}
