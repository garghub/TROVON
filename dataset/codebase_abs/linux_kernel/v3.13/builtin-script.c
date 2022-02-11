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
static void F_11 ( struct V_15 * V_16 )
{
unsigned int type = V_16 -> type ;
V_3 [ type ] . V_46 = 0 ;
if ( F_9 ( V_23 ) )
V_3 [ type ] . V_46 |= V_47 ;
if ( F_9 ( V_33 ) )
V_3 [ type ] . V_46 |= V_48 ;
if ( F_9 ( V_35 ) )
V_3 [ type ] . V_46 |= V_49 ;
if ( F_9 ( V_34 ) )
V_3 [ type ] . V_46 |= V_50 ;
}
static int F_12 ( struct V_19 * V_20 )
{
int V_1 ;
struct V_11 * V_12 ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_12 = F_13 ( V_20 , V_1 ) ;
if ( ! V_12 && V_3 [ V_1 ] . V_4 && ! V_3 [ V_1 ] . V_51 ) {
F_6 ( L_18
L_19 ,
F_14 ( V_1 ) ) ;
return - 1 ;
}
if ( V_12 && V_3 [ V_1 ] . V_18 &&
F_8 ( V_12 , V_20 ) )
return - 1 ;
if ( V_12 == NULL )
continue;
F_11 ( & V_12 -> V_16 ) ;
}
return 0 ;
}
static void F_15 ( struct V_52 * V_53 ,
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
printf ( L_20 , F_16 ( V_54 ) ) ;
else if ( F_9 ( V_23 ) && V_28 . V_29 )
printf ( L_21 , F_16 ( V_54 ) ) ;
else
printf ( L_22 , F_16 ( V_54 ) ) ;
}
if ( F_9 ( V_36 ) && F_9 ( V_37 ) )
printf ( L_23 , V_53 -> V_60 , V_53 -> V_61 ) ;
else if ( F_9 ( V_36 ) )
printf ( L_24 , V_53 -> V_60 ) ;
else if ( F_9 ( V_37 ) )
printf ( L_24 , V_53 -> V_61 ) ;
if ( F_9 ( V_43 ) ) {
if ( V_59 )
printf ( L_25 , V_53 -> V_62 ) ;
else
printf ( L_26 , V_53 -> V_62 ) ;
}
if ( F_9 ( TIME ) ) {
V_57 = V_53 -> time ;
V_55 = V_57 / V_63 ;
V_57 -= V_55 * V_63 ;
V_56 = V_57 / V_64 ;
printf ( L_27 , V_55 , V_56 ) ;
}
if ( F_9 ( V_65 ) ) {
V_17 = F_5 ( V_12 ) ;
printf ( L_28 , V_17 ? V_17 : L_29 ) ;
}
}
static bool F_17 ( struct V_15 * V_16 )
{
return ( ( V_16 -> type == V_66 ) &&
( V_16 -> V_67 & V_68 ) &&
( V_16 -> V_69 == 1 ) ) ;
}
static bool F_18 ( struct V_15 * V_16 )
{
if ( ( V_16 -> type == V_70 ) &&
( ( V_16 -> V_67 == V_71 ) ||
( V_16 -> V_67 == V_72 ) ||
( V_16 -> V_67 == V_73 ) ) )
return true ;
if ( F_17 ( V_16 ) )
return true ;
return false ;
}
static void F_19 ( union V_74 * V_75 ,
struct V_52 * V_53 ,
struct V_76 * V_76 ,
struct V_54 * V_54 ,
struct V_15 * V_16 )
{
struct V_77 V_78 ;
T_2 V_79 = V_75 -> V_80 . V_81 & V_82 ;
printf ( L_30 V_83 , V_53 -> V_84 ) ;
if ( ! F_18 ( V_16 ) )
return;
F_20 ( V_54 , V_76 , V_79 , V_85 ,
V_53 -> V_84 , & V_78 ) ;
if ( ! V_78 . V_86 )
F_20 ( V_54 , V_76 , V_79 , V_87 ,
V_53 -> V_84 , & V_78 ) ;
V_78 . V_62 = V_53 -> V_62 ;
V_78 . V_88 = NULL ;
if ( V_78 . V_86 )
V_78 . V_88 = F_21 ( V_78 . V_86 , V_78 . V_84 , NULL ) ;
if ( F_9 ( V_33 ) ) {
printf ( L_31 ) ;
if ( F_9 ( V_34 ) )
F_22 ( V_78 . V_88 , & V_78 , stdout ) ;
else
F_23 ( V_78 . V_88 , stdout ) ;
}
if ( F_9 ( V_35 ) ) {
printf ( L_32 ) ;
F_24 ( V_78 . V_86 , stdout ) ;
printf ( L_33 ) ;
}
}
static void F_25 ( union V_74 * V_75 ,
struct V_52 * V_53 ,
struct V_11 * V_12 ,
struct V_76 * V_76 ,
struct V_54 * V_54 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_12 , V_75 , V_53 , V_76 ,
V_3 [ V_16 -> type ] . V_46 ,
V_89 ) ;
}
printf ( L_35 ) ;
if ( F_9 ( V_30 ) ||
( ( V_12 -> V_16 . V_13 & V_31 ) &&
! V_3 [ V_16 -> type ] . V_4 ) )
F_19 ( V_75 , V_53 , V_76 , V_54 , V_16 ) ;
printf ( L_34 ) ;
}
static void F_27 ( union V_74 * V_75 , struct V_52 * V_53 ,
struct V_11 * V_12 , struct V_76 * V_76 ,
struct V_54 * V_54 ,
struct V_77 * V_78 V_90 )
{
struct V_15 * V_16 = & V_12 -> V_16 ;
if ( V_3 [ V_16 -> type ] . V_18 == 0 )
return;
F_15 ( V_53 , V_54 , V_12 ) ;
if ( F_17 ( V_16 ) ) {
F_25 ( V_75 , V_53 , V_12 , V_76 , V_54 ) ;
return;
}
if ( F_9 ( V_21 ) )
F_28 ( V_12 -> V_91 , V_53 -> V_62 ,
V_53 -> V_92 , V_53 -> V_93 ) ;
if ( F_9 ( V_30 ) )
F_19 ( V_75 , V_53 , V_76 , V_54 , V_16 ) ;
if ( F_9 ( V_23 ) ) {
if ( ! V_28 . V_29 )
printf ( L_31 ) ;
else
printf ( L_34 ) ;
F_26 ( V_12 , V_75 , V_53 , V_76 ,
V_3 [ V_16 -> type ] . V_46 ,
V_89 ) ;
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
static int F_31 ( struct V_94 * V_94 V_90 ,
const char * T_6 V_90 )
{
return 0 ;
}
static void F_32 ( void )
{
F_33 () ;
F_34 () ;
V_95 = & V_96 ;
}
static int F_35 ( void )
{
F_7 ( L_36 ) ;
return V_95 -> V_97 () ;
}
static int F_36 ( struct V_98 * T_7 V_90 ,
union V_74 * V_75 ,
struct V_52 * V_53 ,
struct V_11 * V_12 ,
struct V_76 * V_76 )
{
struct V_77 V_78 ;
struct V_54 * V_54 = F_37 ( V_76 , V_53 -> V_60 ,
V_53 -> V_61 ) ;
if ( V_54 == NULL ) {
F_7 ( L_37 ,
V_75 -> V_80 . type ) ;
return - 1 ;
}
if ( V_99 ) {
if ( V_53 -> time < V_100 ) {
F_6 ( L_38 V_101
L_39 V_101 L_34 , V_100 ,
V_53 -> time ) ;
V_102 ++ ;
}
V_100 = V_53 -> time ;
return 0 ;
}
if ( F_38 ( V_75 , V_76 , & V_78 , V_53 ) < 0 ) {
F_6 ( L_37 ,
V_75 -> V_80 . type ) ;
return - 1 ;
}
if ( V_78 . V_103 )
return 0 ;
if ( V_104 && ! F_39 ( V_53 -> V_62 , V_105 ) )
return 0 ;
V_95 -> F_27 ( V_75 , V_53 , V_12 , V_76 , V_54 , & V_78 ) ;
V_12 -> V_106 . V_107 . V_108 += V_53 -> V_109 ;
return 0 ;
}
static int F_40 ( struct V_98 * T_7 , union V_74 * V_75 ,
struct V_110 * * V_111 )
{
struct V_112 * V_113 = F_41 ( T_7 , struct V_112 , T_7 ) ;
struct V_110 * V_114 ;
struct V_11 * V_12 , * V_115 ;
int V_116 ;
V_116 = F_42 ( T_7 , V_75 , V_111 ) ;
if ( V_116 )
return V_116 ;
V_114 = * V_111 ;
V_12 = F_43 ( * V_111 ) ;
if ( V_12 -> V_16 . type >= V_2 )
return 0 ;
F_44 (pos, &evlist->entries, node) {
if ( V_115 -> V_16 . type == V_12 -> V_16 . type && V_115 != V_12 )
return 0 ;
}
F_11 ( & V_12 -> V_16 ) ;
return F_8 ( V_12 , V_113 -> V_20 ) ;
}
static void F_45 ( int T_8 V_90 )
{
V_117 = 1 ;
}
static int F_46 ( struct V_112 * T_3 )
{
int V_118 ;
signal ( V_119 , F_45 ) ;
V_118 = F_47 ( T_3 -> V_20 , & T_3 -> T_7 ) ;
if ( V_99 )
F_6 ( L_40 V_101 L_34 , V_102 ) ;
return V_118 ;
}
static struct V_120 * F_48 ( const char * V_121 ,
struct V_95 * V_122 )
{
struct V_120 * V_123 = malloc ( sizeof( * V_123 ) + strlen ( V_121 ) + 1 ) ;
if ( V_123 != NULL ) {
strcpy ( V_123 -> V_121 , V_121 ) ;
V_123 -> V_122 = V_122 ;
}
return V_123 ;
}
static void F_49 ( struct V_120 * V_123 )
{
F_50 ( & V_123 -> V_124 , & V_125 ) ;
}
static struct V_120 * F_51 ( const char * V_121 )
{
struct V_120 * V_123 ;
F_44 (s, &script_specs, node)
if ( strcasecmp ( V_123 -> V_121 , V_121 ) == 0 )
return V_123 ;
return NULL ;
}
static struct V_120 * F_52 ( const char * V_121 ,
struct V_95 * V_122 )
{
struct V_120 * V_123 = F_51 ( V_121 ) ;
if ( V_123 )
return V_123 ;
V_123 = F_48 ( V_121 , V_122 ) ;
if ( ! V_123 )
return NULL ;
F_49 ( V_123 ) ;
return V_123 ;
}
int F_53 ( const char * V_121 , struct V_95 * V_122 )
{
struct V_120 * V_123 ;
V_123 = F_51 ( V_121 ) ;
if ( V_123 )
return - 1 ;
V_123 = F_52 ( V_121 , V_122 ) ;
if ( ! V_123 )
return - 1 ;
return 0 ;
}
static struct V_95 * F_54 ( const char * V_121 )
{
struct V_120 * V_123 = F_51 ( V_121 ) ;
if ( ! V_123 )
return NULL ;
return V_123 -> V_122 ;
}
static void F_55 ( void )
{
struct V_120 * V_123 ;
fprintf ( V_126 , L_34 ) ;
fprintf ( V_126 , L_41
L_42 ) ;
F_44 (s, &script_specs, node)
fprintf ( V_126 , L_43 , V_123 -> V_121 , V_123 -> V_122 -> V_127 ) ;
fprintf ( V_126 , L_34 ) ;
}
static int F_56 ( const struct V_128 * T_9 V_90 ,
const char * V_10 , int T_10 V_90 )
{
char V_121 [ V_129 ] ;
const char * T_3 , * V_130 ;
int V_131 ;
if ( strcmp ( V_10 , L_44 ) == 0 ) {
F_55 () ;
exit ( 0 ) ;
}
T_3 = strchr ( V_10 , ':' ) ;
if ( T_3 ) {
V_131 = T_3 - V_10 ;
if ( V_131 >= V_129 ) {
fprintf ( V_126 , L_45 ) ;
return - 1 ;
}
strncpy ( V_121 , V_10 , V_131 ) ;
V_121 [ V_131 ] = '\0' ;
V_95 = F_54 ( V_121 ) ;
if ( ! V_95 ) {
fprintf ( V_126 , L_45 ) ;
return - 1 ;
}
T_3 ++ ;
} else {
T_3 = V_10 ;
V_130 = strrchr ( T_3 , '.' ) ;
if ( ! V_130 ) {
fprintf ( V_126 , L_46 ) ;
return - 1 ;
}
V_95 = F_54 ( ++ V_130 ) ;
if ( ! V_95 ) {
fprintf ( V_126 , L_46 ) ;
return - 1 ;
}
}
V_132 = F_57 ( T_3 ) ;
return 0 ;
}
static int F_58 ( const struct V_128 * T_9 V_90 ,
const char * V_133 , int T_10 V_90 )
{
char * V_134 ;
int V_7 , V_8 = F_3 ( V_9 ) ;
int V_1 ;
int V_135 = 0 ;
char * V_10 = F_57 ( V_133 ) ;
int type = - 1 ;
if ( ! V_10 )
return - V_136 ;
V_134 = strchr ( V_10 , ':' ) ;
if ( V_134 ) {
* V_134 = '\0' ;
V_134 ++ ;
if ( ! strcmp ( V_10 , L_47 ) )
type = V_66 ;
else if ( ! strcmp ( V_10 , L_48 ) )
type = V_70 ;
else if ( ! strcmp ( V_10 , L_49 ) )
type = V_137 ;
else if ( ! strcmp ( V_10 , L_50 ) )
type = V_138 ;
else {
fprintf ( V_126 , L_51 ) ;
V_135 = - V_22 ;
goto V_139;
}
if ( V_3 [ type ] . V_4 )
F_59 ( L_52 ,
F_14 ( type ) ) ;
V_3 [ type ] . V_18 = 0 ;
V_3 [ type ] . V_4 = true ;
V_3 [ type ] . V_51 = false ;
} else {
V_134 = V_10 ;
if ( strlen ( V_10 ) == 0 ) {
fprintf ( V_126 ,
L_53 ) ;
V_135 = - V_22 ;
goto V_139;
}
if ( F_1 () )
F_59 ( L_54 ) ;
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
V_3 [ V_1 ] . V_18 = 0 ;
V_3 [ V_1 ] . V_4 = true ;
V_3 [ V_1 ] . V_51 = true ;
}
}
V_134 = strtok ( V_134 , L_55 ) ;
while ( V_134 ) {
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 ) {
if ( strcmp ( V_134 , V_9 [ V_7 ] . V_10 ) == 0 )
break;
}
if ( V_7 == V_8 ) {
fprintf ( V_126 , L_56 ) ;
V_135 = - V_22 ;
goto V_139;
}
if ( type == - 1 ) {
for ( V_1 = 0 ; V_1 < V_2 ; ++ V_1 ) {
if ( V_3 [ V_1 ] . V_140 & V_9 [ V_7 ] . V_6 ) {
F_59 ( L_57 ,
V_9 [ V_7 ] . V_10 , F_14 ( V_1 ) ) ;
} else
V_3 [ V_1 ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
} else {
if ( V_3 [ type ] . V_140 & V_9 [ V_7 ] . V_6 ) {
fprintf ( V_126 , L_58 ,
V_9 [ V_7 ] . V_10 , F_14 ( type ) ) ;
V_135 = - V_22 ;
goto V_139;
}
V_3 [ type ] . V_18 |= V_9 [ V_7 ] . V_6 ;
}
V_134 = strtok ( NULL , L_55 ) ;
}
if ( type >= 0 ) {
if ( V_3 [ type ] . V_18 == 0 ) {
F_7 ( L_59
L_60 , F_14 ( type ) ) ;
}
}
V_139:
free ( V_10 ) ;
return V_135 ;
}
static int F_60 ( const char * V_141 , const struct V_142 * V_143 )
{
char V_144 [ V_129 ] ;
struct V_145 V_146 ;
sprintf ( V_144 , L_61 , V_141 , V_143 -> V_147 ) ;
if ( V_145 ( V_144 , & V_146 ) )
return 0 ;
return F_61 ( V_146 . V_148 ) ;
}
static struct V_149 * F_62 ( const char * V_127 )
{
struct V_149 * V_123 = F_63 ( sizeof( * V_123 ) ) ;
if ( V_123 != NULL && V_127 )
V_123 -> V_127 = F_57 ( V_127 ) ;
return V_123 ;
}
static void F_64 ( struct V_149 * V_123 )
{
free ( V_123 -> V_127 ) ;
free ( V_123 -> V_150 ) ;
free ( V_123 -> args ) ;
free ( V_123 ) ;
}
static void F_65 ( struct V_149 * V_123 )
{
F_50 ( & V_123 -> V_124 , & V_151 ) ;
}
static struct V_149 * F_66 ( const char * V_127 )
{
struct V_149 * V_123 ;
F_44 (s, &script_descs, node)
if ( strcasecmp ( V_123 -> V_127 , V_127 ) == 0 )
return V_123 ;
return NULL ;
}
static struct V_149 * F_67 ( const char * V_127 )
{
struct V_149 * V_123 = F_66 ( V_127 ) ;
if ( V_123 )
return V_123 ;
V_123 = F_62 ( V_127 ) ;
if ( ! V_123 )
goto V_152;
F_65 ( V_123 ) ;
return V_123 ;
V_152:
F_64 ( V_123 ) ;
return NULL ;
}
static const char * F_68 ( const char * V_10 , const char * V_153 )
{
T_11 V_154 = strlen ( V_153 ) ;
const char * V_155 = V_10 ;
if ( strlen ( V_10 ) > V_154 ) {
V_155 = V_10 + strlen ( V_10 ) - V_154 ;
if ( ! strncmp ( V_155 , V_153 , V_154 ) )
return V_155 ;
}
return NULL ;
}
static int F_69 ( struct V_149 * V_156 , const char * V_157 )
{
char line [ V_158 ] , * V_155 ;
T_12 * V_159 ;
V_159 = fopen ( V_157 , L_62 ) ;
if ( ! V_159 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_159 ) ) {
V_155 = F_70 ( line ) ;
if ( strlen ( V_155 ) == 0 )
continue;
if ( * V_155 != '#' )
continue;
V_155 ++ ;
if ( strlen ( V_155 ) && * V_155 == '!' )
continue;
V_155 = F_70 ( V_155 ) ;
if ( strlen ( V_155 ) && V_155 [ strlen ( V_155 ) - 1 ] == '\n' )
V_155 [ strlen ( V_155 ) - 1 ] = '\0' ;
if ( ! strncmp ( V_155 , L_63 , strlen ( L_63 ) ) ) {
V_155 += strlen ( L_63 ) ;
V_156 -> V_150 = F_57 ( F_70 ( V_155 ) ) ;
continue;
}
if ( ! strncmp ( V_155 , L_64 , strlen ( L_64 ) ) ) {
V_155 += strlen ( L_64 ) ;
V_156 -> args = F_57 ( F_70 ( V_155 ) ) ;
continue;
}
}
fclose ( V_159 ) ;
return 0 ;
}
static char * F_71 ( struct V_142 * V_160 , const char * V_153 )
{
char * V_161 , * V_10 ;
V_161 = F_57 ( V_160 -> V_147 ) ;
if ( ! V_161 )
return NULL ;
V_10 = ( char * ) F_68 ( V_161 , V_153 ) ;
if ( ! V_10 ) {
free ( V_161 ) ;
return NULL ;
}
* V_10 = '\0' ;
return V_161 ;
}
static int F_72 ( const struct V_128 * T_9 V_90 ,
const char * V_123 V_90 ,
int T_10 V_90 )
{
struct V_142 * V_162 , * V_163 , V_160 , V_164 ;
char V_165 [ V_166 ] ;
T_13 * V_167 , * V_168 ;
char V_169 [ V_166 ] ;
char V_170 [ V_166 ] ;
struct V_149 * V_156 ;
char V_171 [ V_158 ] ;
char * V_161 ;
snprintf ( V_165 , V_166 , L_65 , F_73 () ) ;
V_167 = F_74 ( V_165 ) ;
if ( ! V_167 )
return - 1 ;
F_75 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_170 , V_166 , L_66 , V_165 ,
V_164 . V_147 ) ;
V_168 = F_74 ( V_170 ) ;
if ( ! V_168 )
continue;
F_76 (lang_path, lang_dir, script_dirent, script_next) {
V_161 = F_71 ( & V_160 , V_172 ) ;
if ( V_161 ) {
V_156 = F_67 ( V_161 ) ;
snprintf ( V_169 , V_166 , L_61 ,
V_170 , V_160 . V_147 ) ;
F_69 ( V_156 , V_169 ) ;
free ( V_161 ) ;
}
}
}
fprintf ( stdout , L_67 ) ;
F_44 (desc, &script_descs, node) {
sprintf ( V_171 , L_68 , V_156 -> V_127 ,
V_156 -> args ? V_156 -> args : L_1 ) ;
fprintf ( stdout , L_69 , V_171 ,
V_156 -> V_150 ? V_156 -> V_150 : L_1 ) ;
}
exit ( 0 ) ;
}
static int F_77 ( char * V_173 , char * V_174 ,
struct V_19 * V_20 )
{
char V_157 [ V_166 ] , V_17 [ 128 ] ;
char line [ V_158 ] , * V_155 ;
struct V_11 * V_115 ;
int V_175 , V_131 ;
T_12 * V_159 ;
sprintf ( V_157 , L_70 , V_173 , V_174 ) ;
V_159 = fopen ( V_157 , L_62 ) ;
if ( ! V_159 )
return - 1 ;
while ( fgets ( line , sizeof( line ) , V_159 ) ) {
V_155 = F_70 ( line ) ;
if ( * V_155 == '#' )
continue;
while ( strlen ( V_155 ) ) {
V_155 = strstr ( V_155 , L_71 ) ;
if ( ! V_155 )
break;
V_155 += 2 ;
V_155 = F_70 ( V_155 ) ;
V_131 = strcspn ( V_155 , L_72 ) ;
if ( ! V_131 )
break;
snprintf ( V_17 , V_131 + 1 , L_73 , V_155 ) ;
V_175 = 0 ;
F_44 (pos,
&session->evlist->entries, node) {
if ( ! strcmp ( F_5 ( V_115 ) , V_17 ) ) {
V_175 = 1 ;
break;
}
}
if ( ! V_175 ) {
fclose ( V_159 ) ;
return - 1 ;
}
}
}
fclose ( V_159 ) ;
return 0 ;
}
int F_78 ( char * * V_176 , char * * V_177 )
{
struct V_142 * V_162 , * V_163 , V_160 , V_164 ;
char V_165 [ V_166 ] , V_170 [ V_166 ] ;
T_13 * V_167 , * V_168 ;
struct V_19 * V_20 ;
struct V_178 V_179 = {
. V_144 = V_180 ,
. V_181 = V_182 ,
} ;
char * V_183 ;
int V_7 = 0 ;
V_20 = F_79 ( & V_179 , false , NULL ) ;
if ( ! V_20 )
return - 1 ;
snprintf ( V_165 , V_166 , L_65 , F_73 () ) ;
V_167 = F_74 ( V_165 ) ;
if ( ! V_167 ) {
F_80 ( V_20 ) ;
return - 1 ;
}
F_75 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_170 , V_166 , L_61 , V_165 ,
V_164 . V_147 ) ;
#ifdef F_81
if ( strstr ( V_170 , L_74 ) )
continue;
#endif
#ifdef F_82
if ( strstr ( V_170 , L_75 ) )
continue;
#endif
V_168 = F_74 ( V_170 ) ;
if ( ! V_168 )
continue;
F_76 (lang_path, lang_dir, script_dirent, script_next) {
if ( strstr ( V_160 . V_147 , L_76 ) )
continue;
sprintf ( V_177 [ V_7 ] , L_61 , V_170 ,
V_160 . V_147 ) ;
V_183 = strchr ( V_160 . V_147 , '.' ) ;
snprintf ( V_176 [ V_7 ] ,
( V_183 - V_160 . V_147 ) + 1 ,
L_73 , V_160 . V_147 ) ;
if ( F_77 ( V_170 ,
V_176 [ V_7 ] , V_20 ) )
continue;
V_7 ++ ;
}
F_83 ( V_168 ) ;
}
F_83 ( V_167 ) ;
F_80 ( V_20 ) ;
return V_7 ;
}
static char * F_84 ( const char * V_161 , const char * V_153 )
{
struct V_142 * V_162 , * V_163 , V_160 , V_164 ;
char V_165 [ V_166 ] ;
char V_169 [ V_166 ] ;
T_13 * V_167 , * V_168 ;
char V_170 [ V_166 ] ;
char * V_184 ;
snprintf ( V_165 , V_166 , L_65 , F_73 () ) ;
V_167 = F_74 ( V_165 ) ;
if ( ! V_167 )
return NULL ;
F_75 (scripts_path, scripts_dir, lang_dirent, lang_next) {
snprintf ( V_170 , V_166 , L_66 , V_165 ,
V_164 . V_147 ) ;
V_168 = F_74 ( V_170 ) ;
if ( ! V_168 )
continue;
F_76 (lang_path, lang_dir, script_dirent, script_next) {
V_184 = F_71 ( & V_160 , V_153 ) ;
if ( V_184 && ! strcmp ( V_161 , V_184 ) ) {
free ( V_184 ) ;
F_83 ( V_168 ) ;
F_83 ( V_167 ) ;
snprintf ( V_169 , V_166 , L_61 ,
V_170 , V_160 . V_147 ) ;
return F_57 ( V_169 ) ;
}
free ( V_184 ) ;
}
F_83 ( V_168 ) ;
}
F_83 ( V_167 ) ;
return NULL ;
}
static bool F_85 ( const char * V_169 )
{
return F_68 ( V_169 , L_77 ) == NULL ? false : true ;
}
static int F_86 ( char * V_169 )
{
struct V_149 * V_156 ;
int V_185 = 0 ;
char * V_155 ;
V_156 = F_62 ( NULL ) ;
if ( F_69 ( V_156 , V_169 ) )
goto V_139;
if ( ! V_156 -> args )
goto V_139;
for ( V_155 = V_156 -> args ; * V_155 ; V_155 ++ )
if ( * V_155 == '<' )
V_185 ++ ;
V_139:
F_64 ( V_156 ) ;
return V_185 ;
}
static int F_87 ( int T_4 , const char * * T_5 )
{
char * * V_186 = malloc ( sizeof( const char * ) * T_4 ) ;
if ( ! V_186 ) {
F_6 ( L_78 ) ;
return - 1 ;
}
memcpy ( V_186 , T_5 , sizeof( const char * ) * T_4 ) ;
T_4 = F_88 ( T_4 , ( const char * * ) V_186 , V_187 ,
NULL , V_188 ) ;
free ( V_186 ) ;
V_189 = ( T_4 == 0 ) ;
return 0 ;
}
int F_89 ( int T_4 , const char * * T_5 , const char * T_14 V_90 )
{
bool V_190 = false ;
char * V_191 = NULL ;
char * V_192 = NULL ;
struct V_19 * V_20 ;
char * V_169 = NULL ;
const char * * V_186 ;
int V_7 , V_1 , V_116 ;
struct V_112 T_3 = {
. T_7 = {
. V_53 = F_36 ,
. V_193 = V_194 ,
. V_195 = V_196 ,
. V_197 = V_198 ,
. exit = V_199 ,
. V_200 = V_201 ,
. V_16 = F_40 ,
. V_202 = V_203 ,
. V_204 = V_205 ,
. V_206 = true ,
. V_207 = true ,
} ,
} ;
const struct V_128 V_208 [] = {
F_90 ( 'D' , L_79 , & V_209 ,
L_80 ) ,
F_91 ( 'v' , L_81 , & V_210 ,
L_82 ) ,
F_90 ( 'L' , L_83 , & V_59 ,
L_84 ) ,
F_92 ( 'l' , L_85 , NULL , NULL , L_86 ,
F_72 ) ,
F_93 ( 's' , L_87 , NULL , L_88 ,
L_89 ,
F_56 ) ,
F_94 ( 'g' , L_90 , & V_211 , L_44 ,
L_91 ) ,
F_94 ( 'i' , L_92 , & V_180 , L_93 , L_94 ) ,
F_90 ( 'd' , L_95 , & V_99 ,
L_96 ) ,
F_94 ( 'k' , L_97 , & V_28 . V_212 ,
L_93 , L_98 ) ,
F_94 ( 0 , L_99 , & V_28 . V_213 ,
L_93 , L_100 ) ,
F_90 ( 'G' , L_101 , & V_26 ,
L_102 ) ,
F_94 ( 0 , L_103 , & V_28 . V_214 , L_104 ,
L_105 ) ,
F_93 ( 'f' , L_106 , NULL , L_107 ,
L_108
L_109
L_110
L_111 , F_58 ) ,
F_90 ( 'a' , L_112 , & V_189 ,
L_113 ) ,
F_94 ( 'S' , L_114 , & V_28 . V_215 , L_115 ,
L_116 ) ,
F_94 ( 'C' , L_117 , & V_104 , L_117 , L_118 ) ,
F_94 ( 'c' , L_119 , & V_28 . V_216 , L_120 ,
L_121 ) ,
F_90 ( 'I' , L_122 , & V_190 ,
L_123 ) ,
F_90 ( '\0' , L_124 , & V_28 . V_217 ,
L_125 ) ,
F_95 ()
} ;
const char * const V_218 [] = {
L_126 ,
L_127 ,
L_128 ,
L_129 ,
L_130 ,
NULL
} ;
struct V_178 V_179 = {
. V_181 = V_182 ,
} ;
F_32 () ;
T_4 = F_88 ( T_4 , T_5 , V_208 , V_218 ,
V_188 ) ;
V_179 . V_144 = V_180 ;
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_131 , strlen ( L_131 ) ) ) {
V_191 = F_84 ( T_5 [ 1 ] , V_219 ) ;
if ( ! V_191 )
return F_96 ( T_4 , T_5 , NULL ) ;
}
if ( T_4 > 1 && ! strncmp ( T_5 [ 0 ] , L_132 , strlen ( L_132 ) ) ) {
V_192 = F_84 ( T_5 [ 1 ] , V_172 ) ;
if ( ! V_192 ) {
fprintf ( V_126 ,
L_133
L_134 ) ;
return - 1 ;
}
}
F_97 ( F_73 () ) ;
if ( T_4 && ! V_132 && ! V_191 && ! V_192 ) {
int V_220 [ 2 ] ;
int V_221 ;
T_15 V_60 ;
V_191 = F_84 ( T_5 [ 0 ] , V_219 ) ;
V_192 = F_84 ( T_5 [ 0 ] , V_172 ) ;
if ( ! V_191 && ! V_192 ) {
fprintf ( V_126 , L_135
L_136 , T_5 [ 0 ] ) ;
F_98 ( V_218 , V_208 ) ;
}
if ( F_85 ( T_5 [ 0 ] ) ) {
V_221 = T_4 - 1 ;
} else {
int V_222 ;
V_221 = F_86 ( V_192 ) ;
V_222 = ( T_4 - 1 ) - V_221 ;
if ( V_222 < 0 ) {
fprintf ( V_126 , L_137
L_138
L_139 , T_5 [ 0 ] ) ;
F_98 ( V_218 , V_208 ) ;
}
}
if ( F_99 ( V_220 ) < 0 ) {
perror ( L_140 ) ;
return - 1 ;
}
V_60 = V_200 () ;
if ( V_60 < 0 ) {
perror ( L_141 ) ;
return - 1 ;
}
if ( ! V_60 ) {
V_1 = 0 ;
F_100 ( V_220 [ 1 ] , 1 ) ;
F_101 ( V_220 [ 0 ] ) ;
if ( F_85 ( T_5 [ 0 ] ) ) {
V_189 = true ;
} else if ( ! V_189 ) {
if ( F_87 ( T_4 - V_221 , & T_5 [ V_221 ] ) != 0 ) {
V_116 = - 1 ;
goto V_139;
}
}
V_186 = malloc ( ( T_4 + 6 ) * sizeof( const char * ) ) ;
if ( ! V_186 ) {
F_6 ( L_78 ) ;
V_116 = - V_136 ;
goto V_139;
}
V_186 [ V_1 ++ ] = L_142 ;
V_186 [ V_1 ++ ] = V_191 ;
if ( V_189 )
V_186 [ V_1 ++ ] = L_143 ;
V_186 [ V_1 ++ ] = L_144 ;
V_186 [ V_1 ++ ] = L_145 ;
V_186 [ V_1 ++ ] = L_146 ;
for ( V_7 = V_221 + 1 ; V_7 < T_4 ; V_7 ++ )
V_186 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_186 [ V_1 ++ ] = NULL ;
F_102 ( L_142 , ( char * * ) V_186 ) ;
free ( V_186 ) ;
exit ( - 1 ) ;
}
F_100 ( V_220 [ 0 ] , 0 ) ;
F_101 ( V_220 [ 1 ] ) ;
V_186 = malloc ( ( T_4 + 4 ) * sizeof( const char * ) ) ;
if ( ! V_186 ) {
F_6 ( L_78 ) ;
V_116 = - V_136 ;
goto V_139;
}
V_1 = 0 ;
V_186 [ V_1 ++ ] = L_142 ;
V_186 [ V_1 ++ ] = V_192 ;
for ( V_7 = 1 ; V_7 < V_221 + 1 ; V_7 ++ )
V_186 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_186 [ V_1 ++ ] = L_147 ;
V_186 [ V_1 ++ ] = L_146 ;
V_186 [ V_1 ++ ] = NULL ;
F_102 ( L_142 , ( char * * ) V_186 ) ;
free ( V_186 ) ;
exit ( - 1 ) ;
}
if ( V_191 )
V_169 = V_191 ;
if ( V_192 )
V_169 = V_192 ;
if ( V_169 ) {
V_1 = 0 ;
if ( ! V_191 )
V_189 = false ;
else if ( ! V_189 ) {
if ( F_87 ( T_4 - 1 , & T_5 [ 1 ] ) != 0 ) {
V_116 = - 1 ;
goto V_139;
}
}
V_186 = malloc ( ( T_4 + 2 ) * sizeof( const char * ) ) ;
if ( ! V_186 ) {
F_6 ( L_78 ) ;
V_116 = - V_136 ;
goto V_139;
}
V_186 [ V_1 ++ ] = L_142 ;
V_186 [ V_1 ++ ] = V_169 ;
if ( V_189 )
V_186 [ V_1 ++ ] = L_143 ;
for ( V_7 = 2 ; V_7 < T_4 ; V_7 ++ )
V_186 [ V_1 ++ ] = T_5 [ V_7 ] ;
V_186 [ V_1 ++ ] = NULL ;
F_102 ( L_142 , ( char * * ) V_186 ) ;
free ( V_186 ) ;
exit ( - 1 ) ;
}
if ( F_103 () < 0 )
return - 1 ;
if ( ! V_132 )
F_104 () ;
V_20 = F_79 ( & V_179 , false , & T_3 . T_7 ) ;
if ( V_20 == NULL )
return - V_136 ;
T_3 . V_20 = V_20 ;
if ( V_104 ) {
if ( F_105 ( V_20 , V_104 , V_105 ) )
return - 1 ;
}
if ( ! V_132 && ! V_211 )
F_106 ( V_20 , stdout , V_190 ) ;
if ( ! V_26 )
V_28 . V_29 = true ;
else
V_28 . V_29 = false ;
if ( V_211 ) {
struct V_145 V_223 ;
int V_224 ;
if ( F_1 () ) {
fprintf ( V_126 ,
L_148 ) ;
return - 1 ;
}
V_224 = F_107 ( V_179 . V_144 , V_225 ) ;
if ( V_224 < 0 ) {
perror ( L_149 ) ;
return - 1 ;
}
V_116 = F_108 ( V_224 , & V_223 ) ;
if ( V_116 < 0 ) {
perror ( L_150 ) ;
return - 1 ;
}
if ( ! V_223 . V_226 ) {
fprintf ( V_126 , L_151 ) ;
return 0 ;
}
V_95 = F_54 ( V_211 ) ;
if ( ! V_95 ) {
fprintf ( V_126 , L_45 ) ;
return - 1 ;
}
V_116 = V_95 -> V_227 ( V_20 -> V_94 ,
L_152 ) ;
goto V_139;
}
if ( V_132 ) {
V_116 = V_95 -> V_228 ( V_132 , T_4 , T_5 ) ;
if ( V_116 )
goto V_139;
F_7 ( L_153 , V_132 ) ;
}
V_116 = F_12 ( V_20 ) ;
if ( V_116 < 0 )
goto V_139;
V_116 = F_46 ( & T_3 ) ;
F_80 ( V_20 ) ;
F_35 () ;
V_139:
return V_116 ;
}
