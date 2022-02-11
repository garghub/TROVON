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
struct V_51 * V_51 ;
const char * V_15 = NULL ;
unsigned long V_52 ;
unsigned long V_53 ;
unsigned long long V_54 ;
if ( F_9 ( V_55 ) ) {
if ( V_56 )
printf ( L_20 , V_50 -> V_57 ) ;
else if ( F_9 ( V_24 ) && V_29 . V_30 )
printf ( L_21 , V_50 -> V_57 ) ;
else
printf ( L_22 , V_50 -> V_57 ) ;
}
if ( F_9 ( V_37 ) && F_9 ( V_38 ) )
printf ( L_23 , V_49 -> V_58 , V_49 -> V_59 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_49 -> V_58 ) ;
else if ( F_9 ( V_38 ) )
printf ( L_24 , V_49 -> V_59 ) ;
if ( F_9 ( V_44 ) ) {
if ( V_56 )
printf ( L_25 , V_49 -> V_60 ) ;
else
printf ( L_26 , V_49 -> V_60 ) ;
}
if ( F_9 ( TIME ) ) {
V_54 = V_49 -> time ;
V_52 = V_54 / V_61 ;
V_54 -= V_52 * V_61 ;
V_53 = V_54 / V_62 ;
printf ( L_27 , V_52 , V_53 ) ;
}
if ( F_9 ( V_63 ) ) {
if ( V_12 -> type == V_64 ) {
type = F_15 ( V_49 -> V_65 ) ;
V_51 = F_16 ( type ) ;
if ( V_51 )
V_15 = V_51 -> V_66 ;
} else
V_15 = F_5 ( V_12 -> type , V_12 -> V_16 ) ;
printf ( L_28 , V_15 ? V_15 : L_29 ) ;
}
}
static bool F_17 ( struct V_11 * V_12 )
{
return ( ( V_12 -> type == V_67 ) &&
( V_12 -> V_16 & V_68 ) &&
( V_12 -> V_69 == 1 ) ) ;
}
static bool F_18 ( struct V_11 * V_12 )
{
if ( ( V_12 -> type == V_70 ) &&
( ( V_12 -> V_16 == V_71 ) ||
( V_12 -> V_16 == V_72 ) ||
( V_12 -> V_16 == V_73 ) ) )
return true ;
if ( F_17 ( V_12 ) )
return true ;
return false ;
}
static void F_19 ( union V_74 * V_51 ,
struct V_48 * V_49 ,
struct V_75 * V_75 ,
struct V_50 * V_50 ,
struct V_11 * V_12 )
{
struct V_76 V_77 ;
T_2 V_78 = V_51 -> V_79 . V_80 & V_81 ;
printf ( L_30 V_82 , V_49 -> V_83 ) ;
if ( ! F_18 ( V_12 ) )
return;
F_20 ( V_50 , V_75 , V_78 , V_84 ,
V_49 -> V_83 , & V_77 ) ;
if ( ! V_77 . V_85 )
F_20 ( V_50 , V_75 , V_78 , V_86 ,
V_49 -> V_83 , & V_77 ) ;
V_77 . V_60 = V_49 -> V_60 ;
V_77 . V_87 = NULL ;
if ( V_77 . V_85 )
V_77 . V_87 = F_21 ( V_77 . V_85 , V_77 . V_83 , NULL ) ;
if ( F_9 ( V_34 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_35 ) )
F_22 ( V_77 . V_87 , & V_77 , stdout ) ;
else
F_23 ( V_77 . V_87 , stdout ) ;
}
if ( F_9 ( V_36 ) ) {
printf ( L_32 ) ;
F_24 ( V_77 . V_85 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_25 ( union V_74 * V_51 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_75 * V_75 ,
struct V_50 * V_50 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_51 , V_49 , V_75 , V_19 ,
F_9 ( V_34 ) , F_9 ( V_36 ) ,
F_9 ( V_35 ) ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_31 ) )
F_19 ( V_51 , V_49 , V_75 , V_50 , V_12 ) ;
printf ( L_34 ) ;
}
static void F_27 ( union V_74 * V_51 V_88 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_75 * V_75 ,
struct V_50 * V_50 )
{
struct V_11 * V_12 = & V_19 -> V_12 ;
if ( V_3 [ V_12 -> type ] . V_17 == 0 )
return;
F_14 ( V_49 , V_50 , V_12 ) ;
if ( F_17 ( V_12 ) ) {
F_25 ( V_51 , V_49 , V_19 , V_75 , V_50 ) ;
return;
}
if ( F_9 ( V_22 ) )
F_28 ( V_49 -> V_60 , V_49 -> V_65 ,
V_49 -> V_89 ) ;
if ( F_9 ( V_31 ) )
F_19 ( V_51 , V_49 , V_75 , V_50 , V_12 ) ;
if ( F_9 ( V_24 ) ) {
if ( ! V_29 . V_30 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_51 , V_49 , V_75 , V_19 ,
F_9 ( V_34 ) , F_9 ( V_36 ) ,
F_9 ( V_35 ) ) ;
}
printf ( L_34 ) ;
}
static int F_29 ( const char * T_3 V_88 ,
int T_4 V_88 ,
const char * * T_5 V_88 )
{
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( const char * T_6 V_88 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_90 = & V_91 ;
}
static int F_35 ( void )
{
F_7 ( L_36 ) ;
return V_90 -> V_92 () ;
}
static int F_36 ( struct V_93 * T_7 V_94 ,
union V_74 * V_51 ,
struct V_48 * V_49 ,
struct V_18 * V_19 ,
struct V_75 * V_75 )
{
struct V_76 V_77 ;
struct V_50 * V_50 = F_37 ( V_75 , V_51 -> V_95 . V_59 ) ;
if ( V_50 == NULL ) {
F_7 ( L_37 ,
V_51 -> V_79 . type ) ;
return - 1 ;
}
if ( V_96 ) {
if ( V_49 -> time < V_97 ) {
F_6 ( L_38 V_98
L_39 V_98 L_34 , V_97 ,
V_49 -> time ) ;
V_99 ++ ;
}
V_97 = V_49 -> time ;
return 0 ;
}
if ( F_38 ( V_51 , V_75 , & V_77 , V_49 , 0 ) < 0 ) {
F_6 ( L_37 ,
V_51 -> V_79 . type ) ;
return - 1 ;
}
if ( V_77 . V_100 )
return 0 ;
if ( V_101 && ! F_39 ( V_49 -> V_60 , V_102 ) )
return 0 ;
V_90 -> F_27 ( V_51 , V_49 , V_19 , V_75 , V_50 ) ;
V_19 -> V_103 . V_104 . V_105 += V_49 -> V_106 ;
return 0 ;
}
static void F_40 ( int T_8 V_88 )
{
V_107 = 1 ;
}
static int F_41 ( struct V_20 * V_21 )
{
int V_108 ;
signal ( V_109 , F_40 ) ;
V_108 = F_42 ( V_21 , & V_110 ) ;
if ( V_96 )
F_6 ( L_40 V_98 L_34 , V_99 ) ;
return V_108 ;
}
static struct V_111 * F_43 ( const char * V_112 ,
struct V_90 * V_113 )
{
struct V_111 * V_114 = malloc ( sizeof( * V_114 ) + strlen ( V_112 ) + 1 ) ;
if ( V_114 != NULL ) {
strcpy ( V_114 -> V_112 , V_112 ) ;
V_114 -> V_113 = V_113 ;
}
return V_114 ;
}
static void F_44 ( struct V_111 * V_114 )
{
F_45 ( & V_114 -> V_115 , & V_116 ) ;
}
static struct V_111 * F_46 ( const char * V_112 )
{
struct V_111 * V_114 ;
F_47 (s, &script_specs, node)
if ( strcasecmp ( V_114 -> V_112 , V_112 ) == 0 )
return V_114 ;
return NULL ;
}
static struct V_111 * F_48 ( const char * V_112 ,
struct V_90 * V_113 )
{
struct V_111 * V_114 = F_46 ( V_112 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_43 ( V_112 , V_113 ) ;
if ( ! V_114 )
return NULL ;
F_44 ( V_114 ) ;
return V_114 ;
}
int F_49 ( const char * V_112 , struct V_90 * V_113 )
{
struct V_111 * V_114 ;
V_114 = F_46 ( V_112 ) ;
if ( V_114 )
return - 1 ;
V_114 = F_48 ( V_112 , V_113 ) ;
if ( ! V_114 )
return - 1 ;
return 0 ;
}
static struct V_90 * F_50 ( const char * V_112 )
{
struct V_111 * V_114 = F_46 ( V_112 ) ;
if ( ! V_114 )
return NULL ;
return V_114 -> V_113 ;
}
static void F_51 ( void )
{
struct V_111 * V_114 ;
fprintf ( V_117 , L_34 ) ;
fprintf ( V_117 , L_41
L_42 ) ;
F_47 (s, &script_specs, node)
fprintf ( V_117 , L_43 , V_114 -> V_112 , V_114 -> V_113 -> V_66 ) ;
fprintf ( V_117 , L_34 ) ;
}
static int F_52 ( const struct V_118 * T_9 V_94 ,
const char * V_10 , int T_10 V_94 )
{
char V_112 [ V_119 ] ;
const char * T_3 , * V_120 ;
int V_121 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_51 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_121 = T_3 - V_10 ;
if ( V_121 >= V_119 ) {
fprintf ( V_117 , L_45 ) ;
return - 1 ;
}
strncpy ( V_112 , V_10 , V_121 ) ;
V_112 [ V_121 ] = '\0' ;
V_90 = F_50 ( V_112 ) ;
if ( ! V_90 ) {
fprintf ( V_117 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_120 = strrchr ( T_3 , '.' ) ;
if ( ! V_120 ) {
fprintf ( V_117 , L_46 ) ;
return - 1 ;
}
V_90 = F_50 ( ++ V_120 ) ;
if ( ! V_90 ) {
fprintf ( V_117 , L_46 ) ;
return - 1 ;
}
}
V_122 = F_53 ( T_3 ) ;
return 0 ;
}
static int F_54 ( const struct V_118 * T_9 V_94 ,
const char * V_123 , int T_10 V_94 )
{
char * V_124 ;
int V_7 , V_8 = sizeof( V_9 ) / sizeof( struct V_125 ) ;
int V_1 ;
int V_126 = 0 ;
char * V_10 = F_53 ( V_123 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_127 ;
V_124 = strchr ( V_10 , ':' ) ;
if ( V_124 ) {
* V_124 = '\0' ;
V_124 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_67 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_70 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_64 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_128 ;
else {
fprintf ( V_117 , L_51 ) ;
V_126 = - V_23 ;
goto V_129;
}
if ( V_3 [ type ] . V_4 )
F_55 ( L_52 ,
F_13 ( type ) ) ;
V_3 [ type ] . V_17 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_47 = false ;
} else {
V_124 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_117 ,
L_53 ) ;
V_126 = - V_23 ;
goto V_129;
}
if ( F_1 () )
F_55 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_17 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_47 = true ;
}
}
V_124 = strtok ( V_124 , L_55 ) ;
while ( V_124 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_124 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_117 , L_56 ) ;
V_126 = - V_23 ;
goto V_129;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_130 & V_9 [ V_7 ] . V_6 ) {
F_55 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_13 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_130 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_117 , L_58 ,
V_9 [ V_7 ] . V_10 , F_13 ( type ) ) ;
V_126 = - V_23 ;
goto V_129;
}
V_3 [ type ] . V_17 |= V_9 [ V_7 ] . V_6 ;
}
V_124 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_17 == 0 ) {
F_7 ( L_59
L_60 , F_13 ( type ) ) ;
}
}
V_129:
free ( V_10 ) ;
return V_126 ;
}
static int F_56 ( const char * V_131 , const struct V_132 * V_133 )
{
char V_134 [ V_119 ] ;
struct V_135 V_136 ;
sprintf ( V_134 , L_61 , V_131 , V_133 -> V_137 ) ;
if ( V_135 ( V_134 , & V_136 ) )
return 0 ;
return F_57 ( V_136 . V_138 ) ;
}
static struct V_139 * F_58 ( const char * V_66 )
{
struct V_139 * V_114 = F_59 ( sizeof( * V_114 ) ) ;
if ( V_114 != NULL && V_66 )
V_114 -> V_66 = F_53 ( V_66 ) ;
return V_114 ;
}
static void F_60 ( struct V_139 * V_114 )
{
free ( V_114 -> V_66 ) ;
free ( V_114 -> V_140 ) ;
free ( V_114 -> args ) ;
free ( V_114 ) ;
}
static void F_61 ( struct V_139 * V_114 )
{
F_45 ( & V_114 -> V_115 , & V_141 ) ;
}
static struct V_139 * F_62 ( const char * V_66 )
{
struct V_139 * V_114 ;
F_47 (s, &script_descs, node)
if ( strcasecmp ( V_114 -> V_66 , V_66 ) == 0 )
return V_114 ;
return NULL ;
}
static struct V_139 * F_63 ( const char * V_66 )
{
struct V_139 * V_114 = F_62 ( V_66 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_58 ( V_66 ) ;
if ( ! V_114 )
goto V_142;
F_61 ( V_114 ) ;
return V_114 ;
V_142:
F_60 ( V_114 ) ;
return NULL ;
}
static const char * F_64 ( const char * V_10 , const char * V_143 )
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
static char * F_65 ( char * V_10 )
{
int V_121 = strlen ( V_10 ) ;
while ( V_121 && isspace ( * V_10 ) ) {
V_121 -- ;
V_10 ++ ;
}
return V_10 ;
}
static int F_66 ( struct V_139 * V_146 , const char * V_147 )
{
char line [ V_148 ] , * V_145 ;
T_12 * V_149 ;
V_149 = fopen ( V_147 , L_62 ) ;
if ( ! V_149 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_149 ) ) {
V_145 = F_65 ( line ) ;
if ( strlen ( V_145 ) == 0 )
continue;
if ( * V_145 != '#' )
continue;
V_145 ++ ;
if ( strlen ( V_145 ) && * V_145 == '!' )
continue;
V_145 = F_65 ( V_145 ) ;
if ( strlen ( V_145 ) && V_145 [ strlen ( V_145 ) - 1 ] == '\n' )
V_145 [ strlen ( V_145 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_145 , L_63 , strlen ( L_63 ) ) ) {
V_145 += strlen ( L_63 ) ;
V_146 -> V_140 = F_53 ( F_65 ( V_145 ) ) ;
continue;
}
if ( ! strncmp ( V_145 , L_64 , strlen ( L_64 ) ) ) {
V_145 += strlen ( L_64 ) ;
V_146 -> args = F_53 ( F_65 ( V_145 ) ) ;
continue;
}
}
fclose ( V_149 ) ;
return 0 ;
}
static char * F_67 ( struct V_132 * V_150 , const char * V_143 )
{
char * V_151 , * V_10 ;
V_151 = F_53 ( V_150 -> V_137 ) ;
if ( ! V_151 )
return NULL ;
V_10 = ( char * ) F_64 ( V_151 , V_143 ) ;
if ( ! V_10 ) {
free ( V_151 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_151 ;
}
static int F_68 ( const struct V_118 * T_9 V_94 ,
const char * V_114 V_94 , int T_10 V_94 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_159 [ V_156 ] ;
char V_160 [ V_156 ] ;
struct V_139 * V_146 ;
char V_161 [ V_148 ] ;
char * V_151 ;
snprintf ( V_155 , V_156 , L_65 , F_69 () ) ;
V_157 = F_70 ( V_155 ) ;
if ( ! V_157 )
return - 1 ;
F_71 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_66 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_70 ( V_160 ) ;
if ( ! V_158 )
continue;
F_72 (lang_path, lang_dir, script_dirent, script_next) {
V_151 = F_67 ( & V_150 , V_162 ) ;
if ( V_151 ) {
V_146 = F_63 ( V_151 ) ;
snprintf ( V_159 , V_156 , L_61 ,
V_160 , V_150 . V_137 ) ;
F_66 ( V_146 , V_159 ) ;
free ( V_151 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_47 (desc, &script_descs, node) {
sprintf ( V_161 , L_68 , V_146 -> V_66 ,
V_146 -> args ? V_146 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_161 ,
V_146 -> V_140 ? V_146 -> V_140 : L_1 ) ;
}
exit ( 0 ) ;
}
static char * F_73 ( const char * V_151 , const char * V_143 )
{
struct V_132 * V_152 , * V_153 , V_150 , V_154 ;
char V_155 [ V_156 ] ;
char V_159 [ V_156 ] ;
T_13 * V_157 , * V_158 ;
char V_160 [ V_156 ] ;
char * V_163 ;
snprintf ( V_155 , V_156 , L_65 , F_69 () ) ;
V_157 = F_70 ( V_155 ) ;
if ( ! V_157 )
return NULL ;
F_71 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_160 , V_156 , L_66 , V_155 ,
V_154 . V_137 ) ;
V_158 = F_70 ( V_160 ) ;
if ( ! V_158 )
continue;
F_72 (lang_path, lang_dir, script_dirent, script_next) {
V_163 = F_67 ( & V_150 , V_143 ) ;
if ( V_163 && ! strcmp ( V_151 , V_163 ) ) {
free ( V_163 ) ;
F_74 ( V_158 ) ;
F_74 ( V_157 ) ;
snprintf ( V_159 , V_156 , L_61 ,
V_160 , V_150 . V_137 ) ;
return F_53 ( V_159 ) ;
}
free ( V_163 ) ;
}
F_74 ( V_158 ) ;
}
F_74 ( V_157 ) ;
return NULL ;
}
static bool F_75 ( const char * V_159 )
{
return F_64 ( V_159 , L_70 ) == NULL ? false : true ;
}
static int F_76 ( char * V_159 )
{
struct V_139 * V_146 ;
int V_164 = 0 ;
char * V_145 ;
V_146 = F_58 ( NULL ) ;
if ( F_66 ( V_146 , V_159 ) )
goto V_129;
if ( ! V_146 -> args )
goto V_129;
for ( V_145 = V_146 -> args ; * V_145 ; V_145 ++ )
if ( * V_145 == '<' )
V_164 ++ ;
V_129:
F_60 ( V_146 ) ;
return V_164 ;
}
static bool F_77 ( int T_4 , const char * * T_5 )
{
char * * V_165 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_165 )
F_78 ( L_71 ) ;
memcpy ( V_165 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_79 ( T_4 , ( const char * * ) V_165 , V_166 ,
NULL , V_167 ) ;
free ( V_165 ) ;
return T_4 != 0 ;
}
int F_80 ( int T_4 , const char * * T_5 , const char * T_14 V_94 )
{
char * V_168 = NULL ;
char * V_169 = NULL ;
struct V_20 * V_21 ;
char * V_159 = NULL ;
const char * * V_165 ;
int V_7 , V_1 , V_170 ;
F_32 () ;
T_4 = F_79 ( T_4 , T_5 , V_171 , V_172 ,
V_167 ) ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_72 , strlen ( L_72 ) ) ) {
V_168 = F_73 ( T_5 [ 1 ] , V_173 ) ;
if ( ! V_168 )
return F_81 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_73 , strlen ( L_73 ) ) ) {
V_169 = F_73 ( T_5 [ 1 ] , V_162 ) ;
if ( ! V_169 ) {
fprintf ( V_117 ,
L_74
L_75 ) ;
return - 1 ;
}
}
F_82 ( F_69 () ) ;
if ( T_4 && ! V_122 && ! V_168 && ! V_169 ) {
int V_174 [ 2 ] ;
int V_175 ;
T_15 V_58 ;
V_168 = F_73 ( T_5 [ 0 ] , V_173 ) ;
V_169 = F_73 ( T_5 [ 0 ] , V_162 ) ;
if ( ! V_168 && ! V_169 ) {
fprintf ( V_117 , L_76
L_77 , T_5 [ 0 ] ) ;
F_83 ( V_172 , V_171 ) ;
}
if ( F_75 ( T_5 [ 0 ] ) ) {
V_175 = T_4 - 1 ;
} else {
int V_176 ;
V_175 = F_76 ( V_169 ) ;
V_176 = ( T_4 - 1 ) - V_175 ;
if ( V_176 < 0 ) {
fprintf ( V_117 , L_78
L_79
L_80 , T_5 [ 0 ] ) ;
F_83 ( V_172 , V_171 ) ;
}
}
if ( F_84 ( V_174 ) < 0 ) {
perror ( L_81 ) ;
exit ( - 1 ) ;
}
V_58 = F_85 () ;
if ( V_58 < 0 ) {
perror ( L_82 ) ;
exit ( - 1 ) ;
}
if ( ! V_58 ) {
V_1 = 0 ;
F_86 ( V_174 [ 1 ] , 1 ) ;
F_87 ( V_174 [ 0 ] ) ;
if ( F_75 ( T_5 [ 0 ] ) ) {
V_177 = true ;
} else if ( ! V_177 ) {
V_177 = ! F_77 ( T_4 - V_175 ,
& T_5 [ V_175 ] ) ;
}
V_165 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_78 ( L_71 ) ;
V_165 [ V_1 ++ ] = L_83 ;
V_165 [ V_1 ++ ] = V_168 ;
if ( V_177 )
V_165 [ V_1 ++ ] = L_84 ;
V_165 [ V_1 ++ ] = L_85 ;
V_165 [ V_1 ++ ] = L_86 ;
V_165 [ V_1 ++ ] = L_87 ;
for ( V_7 = V_175 + 1 ; V_7 < T_4 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_165 ) ;
free ( V_165 ) ;
exit ( - 1 ) ;
}
F_86 ( V_174 [ 0 ] , 0 ) ;
F_87 ( V_174 [ 1 ] ) ;
V_165 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_78 ( L_71 ) ;
V_1 = 0 ;
V_165 [ V_1 ++ ] = L_83 ;
V_165 [ V_1 ++ ] = V_169 ;
for ( V_7 = 1 ; V_7 < V_175 + 1 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = L_88 ;
V_165 [ V_1 ++ ] = L_87 ;
V_165 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_165 ) ;
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
V_177 = ! F_77 ( T_4 - 1 , & T_5 [ 1 ] ) ;
V_165 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_165 )
F_78 ( L_71 ) ;
V_165 [ V_1 ++ ] = L_83 ;
V_165 [ V_1 ++ ] = V_159 ;
if ( V_177 )
V_165 [ V_1 ++ ] = L_84 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_165 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_165 [ V_1 ++ ] = NULL ;
F_88 ( L_83 , ( char * * ) V_165 ) ;
free ( V_165 ) ;
exit ( - 1 ) ;
}
if ( F_89 () < 0 )
return - 1 ;
if ( ! V_122 )
F_90 () ;
V_21 = F_91 ( V_178 , V_179 , 0 , false , & V_110 ) ;
if ( V_21 == NULL )
return - V_127 ;
if ( V_101 ) {
if ( F_92 ( V_21 , V_101 , V_102 ) )
return - 1 ;
}
F_93 ( V_21 , stdout , V_180 ) ;
if ( ! V_27 )
V_29 . V_30 = true ;
else
V_29 . V_30 = false ;
if ( V_181 ) {
struct V_135 V_182 ;
int V_183 ;
if ( F_1 () ) {
fprintf ( V_117 ,
L_89 ) ;
return - 1 ;
}
V_183 = F_94 ( V_21 -> V_147 , V_179 ) ;
if ( V_183 < 0 ) {
perror ( L_90 ) ;
exit ( - 1 ) ;
}
V_170 = F_95 ( V_183 , & V_182 ) ;
if ( V_170 < 0 ) {
perror ( L_91 ) ;
exit ( - 1 ) ;
}
if ( ! V_182 . V_184 ) {
fprintf ( V_117 , L_92 ) ;
exit ( 0 ) ;
}
V_90 = F_50 ( V_181 ) ;
if ( ! V_90 ) {
fprintf ( V_117 , L_45 ) ;
return - 1 ;
}
V_170 = V_90 -> V_185 ( L_93 ) ;
goto V_129;
}
if ( V_122 ) {
V_170 = V_90 -> V_186 ( V_122 , T_4 , T_5 ) ;
if ( V_170 )
goto V_129;
F_7 ( L_94 , V_122 ) ;
}
V_170 = F_11 ( V_21 ) ;
if ( V_170 < 0 )
goto V_129;
V_170 = F_41 ( V_21 ) ;
F_96 ( V_21 ) ;
F_35 () ;
V_129:
return V_170 ;
}
