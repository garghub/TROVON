static int F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
char V_4 [ V_5 ] ;
int V_6 ;
snprintf ( V_4 , V_5 , L_1 , V_7 ,
V_2 -> V_8 , V_3 -> V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
return - V_10 ;
F_3 ( V_6 ) ;
return 0 ;
}
struct V_11 * F_4 ( T_1 V_12 )
{
struct V_11 * V_13 = NULL ;
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_18 [ 24 ] ;
int V_6 ;
T_1 V_19 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return NULL ;
F_6 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_3 , V_20 ,
V_17 . V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( F_8 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
continue;
}
F_3 ( V_6 ) ;
V_19 = F_9 ( V_18 ) ;
if ( V_19 == V_12 ) {
F_10 ( V_3 ) ;
F_10 ( V_2 ) ;
V_13 = F_11 ( sizeof( * V_13 ) ) ;
V_13 -> system = malloc ( V_21 ) ;
if ( ! V_13 -> system ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> V_22 = malloc ( V_21 ) ;
if ( ! V_13 -> V_22 ) {
F_12 ( & V_13 -> system ) ;
free ( V_13 ) ;
return NULL ;
}
strncpy ( V_13 -> system , V_16 . V_8 ,
V_21 ) ;
strncpy ( V_13 -> V_22 , V_17 . V_8 ,
V_21 ) ;
return V_13 ;
}
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
return NULL ;
}
struct V_11 * F_13 ( const char * V_22 )
{
struct V_11 * V_13 = F_11 ( sizeof( * V_13 ) ) ;
char * V_23 = strchr ( V_22 , ':' ) ;
if ( V_13 == NULL || V_23 == NULL ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> system = F_14 ( V_22 , V_23 - V_22 ) ;
V_13 -> V_22 = F_15 ( V_23 + 1 ) ;
if ( V_13 -> system == NULL || V_13 -> V_22 == NULL ) {
F_12 ( & V_13 -> system ) ;
F_12 ( & V_13 -> V_22 ) ;
free ( V_13 ) ;
V_13 = NULL ;
}
return V_13 ;
}
const char * F_16 ( int type )
{
switch ( type ) {
case V_24 :
return L_4 ;
case V_25 :
return L_5 ;
case V_26 :
return L_6 ;
case V_27 :
return L_7 ;
default:
break;
}
return L_8 ;
}
static struct V_28 *
F_17 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 ,
char * V_22 , struct V_34 * V_35 )
{
struct V_28 * V_36 ;
F_18 ( V_33 ) ;
V_36 = F_19 ( V_33 , ( * V_31 ) ++ ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_35 = V_35 ;
if ( V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
F_20 ( & V_36 -> V_37 , V_30 ) ;
return V_36 ;
}
static int F_21 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 , char * V_22 )
{
return F_17 ( V_30 , V_31 , V_33 , V_22 , NULL ) ? 0 : - V_38 ;
}
static int F_22 ( char * V_23 , const char * V_39 [] [ V_40 ] , int V_41 )
{
int V_42 , V_43 ;
int V_44 , V_45 = - 1 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
for ( V_43 = 0 ; V_43 < V_40 && V_39 [ V_42 ] [ V_43 ] ; V_43 ++ ) {
V_44 = strlen ( V_39 [ V_42 ] [ V_43 ] ) ;
if ( V_44 > V_45 && ! strncasecmp ( V_23 , V_39 [ V_42 ] [ V_43 ] , V_44 ) )
V_45 = V_44 ;
}
if ( V_45 > 0 )
return V_42 ;
}
return - 1 ;
}
int F_23 ( struct V_29 * V_30 , int * V_31 ,
char * type , char * V_46 , char * V_47 )
{
struct V_32 V_33 ;
char V_22 [ V_48 ] ;
int V_49 = - 1 , V_50 = - 1 , V_51 = - 1 ;
char * V_52 [ 2 ] = { V_46 , V_47 } ;
int V_42 , V_44 ;
V_49 = F_22 ( type , V_53 ,
V_54 ) ;
if ( V_49 == - 1 )
return - V_10 ;
V_44 = snprintf ( V_22 , V_48 , L_9 , type ) ;
for ( V_42 = 0 ; ( V_42 < 2 ) && ( V_52 [ V_42 ] ) ; V_42 ++ ) {
char * V_23 = V_52 [ V_42 ] ;
V_44 += snprintf ( V_22 + V_44 , V_48 - V_44 , L_10 , V_23 ) ;
if ( V_50 == - 1 ) {
V_50 = F_22 ( V_23 , V_55 ,
V_56 ) ;
if ( V_50 >= 0 ) {
if ( ! F_24 ( V_49 , V_50 ) )
return - V_10 ;
continue;
}
}
if ( V_51 == - 1 ) {
V_51 = F_22 ( V_23 , V_57 ,
V_58 ) ;
if ( V_51 >= 0 )
continue;
}
}
if ( V_50 == - 1 )
V_50 = V_59 ;
if ( V_51 == - 1 )
V_51 = V_60 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_12 = V_49 | ( V_50 << 8 ) | ( V_51 << 16 ) ;
V_33 . type = V_27 ;
return F_21 ( V_30 , V_31 , & V_33 , V_22 ) ;
}
static int F_25 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
struct V_28 * V_36 ;
V_36 = F_26 ( V_61 , V_62 , ( * V_31 ) ++ ) ;
if ( ! V_36 )
return - V_38 ;
F_20 ( & V_36 -> V_37 , V_30 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_63 ;
T_2 * V_3 ;
int V_64 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_61 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_64 && ( V_63 = F_28 ( V_3 ) ) ) {
if ( ! strcmp ( V_63 -> V_8 , L_12 )
|| ! strcmp ( V_63 -> V_8 , L_13 )
|| ! strcmp ( V_63 -> V_8 , L_14 )
|| ! strcmp ( V_63 -> V_8 , L_15 ) )
continue;
if ( ! F_29 ( V_63 -> V_8 , V_62 ) )
continue;
V_64 = F_25 ( V_30 , V_31 , V_61 , V_63 -> V_8 ) ;
}
F_10 ( V_3 ) ;
return V_64 ;
}
static int F_30 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
return strpbrk ( V_62 , L_16 ) ?
F_27 ( V_30 , V_31 , V_61 , V_62 ) :
F_25 ( V_30 , V_31 , V_61 , V_62 ) ;
}
static int F_31 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
struct V_1 * V_65 ;
T_2 * V_66 ;
int V_64 = 0 ;
V_66 = F_5 ( V_7 ) ;
if ( ! V_66 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_64 && ( V_65 = F_28 ( V_66 ) ) ) {
if ( ! strcmp ( V_65 -> V_8 , L_12 )
|| ! strcmp ( V_65 -> V_8 , L_13 )
|| ! strcmp ( V_65 -> V_8 , L_14 )
|| ! strcmp ( V_65 -> V_8 , L_17 )
|| ! strcmp ( V_65 -> V_8 , L_18 ) )
continue;
if ( ! F_29 ( V_65 -> V_8 , V_61 ) )
continue;
V_64 = F_30 ( V_30 , V_31 , V_65 -> V_8 ,
V_62 ) ;
}
F_10 ( V_66 ) ;
return V_64 ;
}
int F_32 ( struct V_29 * V_30 , int * V_31 ,
char * V_67 , char * V_68 )
{
if ( strpbrk ( V_67 , L_16 ) )
return F_31 ( V_30 , V_31 , V_67 , V_68 ) ;
else
return F_30 ( V_30 , V_31 , V_67 , V_68 ) ;
}
static int
F_33 ( const char * type , struct V_32 * V_33 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
if ( ! type || ! type [ V_42 ] )
break;
#define F_34 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_42 ] ) {
case 'r' :
F_34 ( V_69 ) ;
break;
case 'w' :
F_34 ( V_70 ) ;
break;
case 'x' :
F_34 ( V_71 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_34
if ( ! V_33 -> V_72 )
V_33 -> V_72 = V_69 | V_70 ;
return 0 ;
}
int F_35 ( struct V_29 * V_30 , int * V_31 ,
void * V_73 , char * type , T_1 V_74 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_75 = ( unsigned long ) V_73 ;
if ( F_33 ( type , & V_33 ) )
return - V_10 ;
if ( ! V_74 ) {
if ( V_33 . V_72 == V_71 )
V_74 = sizeof( long ) ;
else
V_74 = V_76 ;
}
V_33 . V_77 = V_74 ;
V_33 . type = V_78 ;
V_33 . V_79 = 1 ;
return F_21 ( V_30 , V_31 , & V_33 , NULL ) ;
}
static int F_36 ( struct V_32 * V_33 ,
struct V_80 * V_81 )
{
#define F_37 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_81 -> V_82 ) {
case V_83 :
F_37 ( V_84 ) ;
V_33 -> V_12 = V_81 -> V_85 . V_86 ;
break;
case V_87 :
F_37 ( V_84 ) ;
V_33 -> V_88 = V_81 -> V_85 . V_86 ;
break;
case V_89 :
F_37 ( V_84 ) ;
V_33 -> V_90 = V_81 -> V_85 . V_86 ;
break;
case V_91 :
F_37 ( V_84 ) ;
V_33 -> V_79 = V_81 -> V_85 . V_86 ;
break;
case V_92 :
break;
case V_93 :
F_37 ( V_94 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_37
}
static int F_38 ( struct V_32 * V_33 ,
struct V_29 * V_95 , int V_96 )
{
struct V_80 * V_81 ;
F_39 (term, head, list)
if ( F_36 ( V_33 , V_81 ) && V_96 )
return - V_10 ;
return 0 ;
}
int F_40 ( struct V_29 * V_30 , int * V_31 ,
T_4 type , T_1 V_12 ,
struct V_29 * V_97 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . type = type ;
V_33 . V_12 = V_12 ;
if ( V_97 &&
F_38 ( & V_33 , V_97 , 1 ) )
return - V_10 ;
return F_21 ( V_30 , V_31 , & V_33 , NULL ) ;
}
static int F_41 ( struct V_80 * V_81 )
{
return V_81 -> V_82 == V_93 ;
}
static char * F_42 ( struct V_29 * V_98 )
{
struct V_80 * V_81 ;
F_39 (term, head_terms, list)
if ( F_41 ( V_81 ) )
return V_81 -> V_85 . V_23 ;
return NULL ;
}
int F_43 ( struct V_29 * V_30 , int * V_31 ,
char * V_22 , struct V_29 * V_97 )
{
struct V_32 V_33 ;
struct V_99 V_100 ;
struct V_101 * V_102 ;
struct V_28 * V_36 ;
V_102 = F_44 ( V_22 ) ;
if ( ! V_102 )
return - V_10 ;
if ( V_102 -> V_103 ) {
memcpy ( & V_33 , V_102 -> V_103 ,
sizeof( struct V_32 ) ) ;
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( ! V_97 ) {
V_33 . type = V_102 -> type ;
V_36 = F_17 ( V_30 , V_31 , & V_33 , NULL , V_102 -> V_35 ) ;
return V_36 ? 0 : - V_38 ;
}
if ( F_45 ( V_102 , V_97 , & V_100 ) )
return - V_10 ;
F_38 ( & V_33 , V_97 , 0 ) ;
if ( F_46 ( V_102 , & V_33 , V_97 ) )
return - V_10 ;
V_36 = F_17 ( V_30 , V_31 , & V_33 , F_42 ( V_97 ) ,
V_102 -> V_35 ) ;
if ( V_36 ) {
V_36 -> V_104 = V_100 . V_104 ;
V_36 -> V_105 = V_100 . V_105 ;
V_36 -> V_106 = V_100 . V_106 ;
V_36 -> V_107 = V_100 . V_107 ;
}
return V_36 ? 0 : - V_38 ;
}
int F_47 ( struct V_29 * V_30 ,
char * V_108 )
{
return F_48 ( V_30 , V_108 , true ) ;
}
void F_49 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_109 ;
F_50 ( V_30 ) ;
V_109 = F_51 ( V_30 -> V_110 , struct V_28 , V_37 ) ;
V_109 -> V_111 = V_22 ? F_15 ( V_22 ) : NULL ;
}
void F_52 ( struct V_29 * V_112 ,
struct V_29 * V_113 )
{
F_53 ( V_112 , V_113 ) ;
free ( V_112 ) ;
}
static int F_54 ( struct V_114 * V_115 , char * V_23 ,
struct V_28 * V_36 )
{
int V_116 = V_36 ? V_36 -> V_33 . V_117 : 0 ;
int V_118 = V_36 ? V_36 -> V_33 . V_119 : 0 ;
int V_120 = V_36 ? V_36 -> V_33 . V_121 : 0 ;
int V_122 = V_36 ? V_36 -> V_33 . V_123 : 0 ;
int V_124 = V_36 ? V_36 -> V_33 . V_125 : 0 ;
int V_126 = V_36 ? V_36 -> V_33 . V_127 : 0 ;
int V_128 = V_36 ? V_36 -> V_33 . V_129 : 0 ;
int V_130 = 0 ;
int V_131 = V_36 ? V_36 -> V_33 . V_131 : 0 ;
int V_132 = V_116 | V_118 | V_120 ;
int V_133 = V_36 ? V_36 -> V_133 : 0 ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_132 )
V_132 = V_116 = V_118 = V_120 = 1 ;
V_116 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_132 )
V_132 = V_116 = V_118 = V_120 = 1 ;
V_118 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_132 )
V_132 = V_116 = V_118 = V_120 = 1 ;
V_120 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_133 )
V_133 = V_124 = V_122 = 1 ;
V_124 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_133 )
V_133 = V_124 = V_122 = 1 ;
V_122 = 0 ;
} else if ( * V_23 == 'I' ) {
V_126 = 1 ;
} else if ( * V_23 == 'p' ) {
V_128 ++ ;
if ( ! V_133 )
V_124 = 1 ;
} else if ( * V_23 == 'S' ) {
V_130 = 1 ;
} else if ( * V_23 == 'D' ) {
V_131 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_128 > 3 )
return - V_10 ;
V_115 -> V_116 = V_116 ;
V_115 -> V_118 = V_118 ;
V_115 -> V_120 = V_120 ;
V_115 -> V_122 = V_122 ;
V_115 -> V_124 = V_124 ;
V_115 -> V_126 = V_126 ;
V_115 -> V_128 = V_128 ;
V_115 -> V_133 = V_133 ;
V_115 -> V_130 = V_130 ;
V_115 -> V_131 = V_131 ;
return 0 ;
}
static int F_55 ( char * V_23 )
{
char * V_134 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_19 ) - 1 ) )
return - 1 ;
while ( * V_134 ) {
if ( * V_134 != 'p' && strchr ( V_134 + 1 , * V_134 ) )
return - 1 ;
V_134 ++ ;
}
return 0 ;
}
int F_48 ( struct V_29 * V_30 , char * V_23 , bool V_135 )
{
struct V_28 * V_36 ;
struct V_114 V_115 ;
if ( V_23 == NULL )
return 0 ;
if ( F_55 ( V_23 ) )
return - V_10 ;
if ( ! V_135 && F_54 ( & V_115 , V_23 , NULL ) )
return - V_10 ;
F_56 (list, evsel) {
if ( V_135 && F_54 ( & V_115 , V_23 , V_36 ) )
return - V_10 ;
V_36 -> V_33 . V_117 = V_115 . V_116 ;
V_36 -> V_33 . V_119 = V_115 . V_118 ;
V_36 -> V_33 . V_121 = V_115 . V_120 ;
V_36 -> V_33 . V_129 = V_115 . V_128 ;
V_36 -> V_33 . V_123 = V_115 . V_122 ;
V_36 -> V_33 . V_125 = V_115 . V_124 ;
V_36 -> V_33 . V_127 = V_115 . V_126 ;
V_36 -> V_133 = V_115 . V_133 ;
V_36 -> V_130 = V_115 . V_130 ;
if ( F_57 ( V_36 ) )
V_36 -> V_33 . V_131 = V_115 . V_131 ;
}
return 0 ;
}
int F_58 ( struct V_29 * V_30 , char * V_22 )
{
struct V_28 * V_36 ;
F_56 (list, evsel) {
if ( ! V_36 -> V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
}
return 0 ;
}
static int
F_59 ( const void * V_136 , const void * V_137 )
{
struct V_138 * V_139 = (struct V_138 * ) V_136 ;
struct V_138 * V_140 = (struct V_138 * ) V_137 ;
return strcmp ( V_139 -> V_141 , V_140 -> V_141 ) ;
}
static void F_60 ( void )
{
if ( V_142 > 0 ) {
struct V_138 * V_134 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_142 ; V_42 ++ ) {
V_134 = V_143 + V_42 ;
free ( V_134 -> V_141 ) ;
}
free ( V_143 ) ;
V_143 = NULL ;
V_142 = 0 ;
}
}
static void F_61 ( void )
{
struct V_101 * V_102 = NULL ;
struct V_144 * V_145 ;
int V_74 = 0 ;
V_102 = F_44 ( L_20 ) ;
if ( ( V_102 == NULL ) || F_62 ( & V_102 -> V_146 ) ) {
V_142 = - 1 ;
return;
}
F_39 (alias, &pmu->aliases, list) {
if ( strchr ( V_145 -> V_22 , '-' ) )
V_74 ++ ;
V_74 ++ ;
}
V_143 = malloc ( sizeof( struct V_138 ) * V_74 ) ;
if ( ! V_143 )
return;
V_142 = V_74 ;
V_74 = 0 ;
F_39 (alias, &pmu->aliases, list) {
struct V_138 * V_134 = V_143 + V_74 ;
char * V_147 = strchr ( V_145 -> V_22 , '-' ) ;
if ( V_147 != NULL ) {
F_63 ( F_14 ( V_145 -> V_22 , V_147 - V_145 -> V_22 ) ,
V_148 ) ;
V_134 ++ ;
F_63 ( F_15 ( ++ V_147 ) , V_149 ) ;
V_74 += 2 ;
} else {
F_63 ( F_15 ( V_145 -> V_22 ) , V_150 ) ;
V_74 ++ ;
}
}
qsort ( V_143 , V_74 ,
sizeof( struct V_138 ) , F_59 ) ;
return;
V_151:
F_60 () ;
}
enum V_152
F_64 ( const char * V_22 )
{
struct V_138 V_134 , * V_153 ;
if ( V_142 == 0 )
F_61 () ;
if ( ( V_142 <= 0 ) || ! strcmp ( V_22 , L_20 ) )
return V_154 ;
V_134 . V_141 = F_15 ( V_22 ) ;
V_153 = bsearch ( & V_134 , V_143 ,
( V_155 ) V_142 ,
sizeof( struct V_138 ) , F_59 ) ;
free ( V_134 . V_141 ) ;
return V_153 ? V_153 -> type : V_154 ;
}
static int F_65 ( const char * V_23 , void * V_156 , int V_157 )
{
T_5 V_158 ;
void * V_159 ;
int V_64 ;
V_64 = F_66 ( V_157 , & V_159 ) ;
if ( V_64 )
return V_64 ;
V_158 = F_67 ( V_23 , V_159 ) ;
#ifdef F_68
V_160 = 1 ;
#endif
V_64 = F_69 ( V_156 , V_159 ) ;
F_70 ( V_158 , V_159 ) ;
F_71 ( V_158 , V_159 ) ;
F_72 ( V_159 ) ;
return V_64 ;
}
int F_73 ( struct V_29 * V_161 , const char * V_23 )
{
struct F_73 V_156 = {
. V_161 = NULL ,
} ;
int V_64 ;
V_64 = F_65 ( V_23 , & V_156 , V_162 ) ;
if ( ! V_64 ) {
F_74 ( V_156 . V_161 , V_161 ) ;
F_12 ( & V_156 . V_161 ) ;
return 0 ;
}
if ( V_156 . V_161 )
F_75 ( V_156 . V_161 ) ;
return V_64 ;
}
int F_76 ( struct V_163 * V_164 , const char * V_23 )
{
struct V_165 V_156 = {
. V_30 = F_77 ( V_156 . V_30 ) ,
. V_31 = V_164 -> V_166 ,
} ;
int V_64 ;
V_64 = F_65 ( V_23 , & V_156 , V_167 ) ;
F_60 () ;
if ( ! V_64 ) {
int V_168 = V_156 . V_31 - V_164 -> V_166 ;
F_78 ( V_164 , & V_156 . V_30 , V_168 ) ;
V_164 -> V_169 += V_156 . V_169 ;
return 0 ;
}
return V_64 ;
}
int F_79 ( const struct V_170 * V_171 , const char * V_23 ,
int T_6 V_172 )
{
struct V_163 * V_164 = * (struct V_163 * * ) V_171 -> V_173 ;
int V_64 = F_76 ( V_164 , V_23 ) ;
if ( V_64 ) {
fprintf ( V_174 , L_21 , V_23 ) ;
fprintf ( V_174 , L_22 ) ;
}
return V_64 ;
}
int F_80 ( const struct V_170 * V_171 , const char * V_23 ,
int T_6 V_172 )
{
struct V_163 * V_164 = * (struct V_163 * * ) V_171 -> V_173 ;
struct V_28 * V_175 = NULL ;
if ( V_164 -> V_166 > 0 )
V_175 = F_81 ( V_164 ) ;
if ( V_175 == NULL || V_175 -> V_33 . type != V_26 ) {
fprintf ( V_174 ,
L_23 ) ;
return - 1 ;
}
V_175 -> V_176 = F_15 ( V_23 ) ;
if ( V_175 -> V_176 == NULL ) {
fprintf ( V_174 , L_24 ) ;
return - 1 ;
}
return 0 ;
}
static int F_82 ( const void * V_177 , const void * V_178 )
{
const char * const * V_179 = V_177 ;
const char * const * V_180 = V_178 ;
return strcmp ( * V_179 , * V_180 ) ;
}
void F_83 ( const char * V_181 , const char * V_182 ,
bool V_183 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char * * V_184 = NULL ;
unsigned int V_185 = 0 , V_186 = 0 ;
bool V_187 = false ;
V_188:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_187 ) {
V_184 = F_11 ( sizeof( char * ) * V_186 ) ;
if ( ! V_184 )
goto V_189;
}
F_6 (sys_dir, sys_dirent, sys_next) {
if ( V_181 != NULL &&
! F_29 ( V_16 . V_8 , V_181 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_182 != NULL &&
! F_29 ( V_17 . V_8 , V_182 ) )
continue;
if ( ! V_187 ) {
V_186 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_25 ,
V_16 . V_8 , V_17 . V_8 ) ;
V_184 [ V_185 ] = F_15 ( V_4 ) ;
if ( V_184 [ V_185 ] == NULL )
goto V_190;
V_185 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_187 ) {
V_187 = true ;
goto V_188;
}
qsort ( V_184 , V_186 , sizeof( char * ) , F_82 ) ;
V_185 = 0 ;
while ( V_185 < V_186 ) {
if ( V_183 ) {
printf ( L_26 , V_184 [ V_185 ++ ] ) ;
continue;
}
printf ( L_27 , V_184 [ V_185 ++ ] ,
V_191 [ V_26 ] ) ;
}
if ( V_186 )
printf ( L_28 ) ;
V_192:
V_186 = V_185 ;
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ )
F_12 ( & V_184 [ V_185 ] ) ;
F_12 ( & V_184 ) ;
return;
V_190:
F_10 ( V_3 ) ;
V_189:
F_10 ( V_2 ) ;
printf ( L_29 ,
V_191 [ V_26 ] ) ;
if ( V_184 )
goto V_192;
}
int F_84 ( const char * V_193 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return 0 ;
F_6 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_25 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_193 ) ) {
F_10 ( V_3 ) ;
F_10 ( V_2 ) ;
return 1 ;
}
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static bool F_85 ( T_7 type , unsigned V_12 )
{
bool V_64 = true ;
int V_194 ;
struct V_28 * V_36 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_195 = 1 ,
} ;
struct {
struct V_196 V_197 ;
int V_198 [ 1 ] ;
} V_199 = {
. V_197 . V_200 = 1 ,
. V_198 = { 0 } ,
} ;
V_36 = F_86 ( & V_33 ) ;
if ( V_36 ) {
V_194 = F_87 ( V_36 , NULL , & V_199 . V_197 ) ;
V_64 = V_194 >= 0 ;
if ( V_194 == - V_201 ) {
V_36 -> V_33 . V_119 = 1 ;
V_64 = F_87 ( V_36 , NULL , & V_199 . V_197 ) >= 0 ;
}
F_88 ( V_36 ) ;
}
return V_64 ;
}
int F_89 ( const char * V_182 , bool V_183 )
{
unsigned int type , V_202 , V_42 , V_185 = 0 , V_186 = 0 ;
char V_22 [ 64 ] ;
char * * V_184 = NULL ;
bool V_187 = false ;
V_188:
if ( V_187 ) {
V_184 = F_11 ( sizeof( char * ) * V_186 ) ;
if ( ! V_184 )
goto V_203;
}
for ( type = 0 ; type < V_54 ; type ++ ) {
for ( V_202 = 0 ; V_202 < V_56 ; V_202 ++ ) {
if ( ! F_24 ( type , V_202 ) )
continue;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
F_90 ( type , V_202 , V_42 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_182 != NULL && ! F_29 ( V_22 , V_182 ) )
continue;
if ( ! F_85 ( V_27 ,
type | ( V_202 << 8 ) | ( V_42 << 16 ) ) )
continue;
if ( ! V_187 ) {
V_186 ++ ;
continue;
}
V_184 [ V_185 ] = F_15 ( V_22 ) ;
if ( V_184 [ V_185 ] == NULL )
goto V_203;
V_185 ++ ;
}
}
}
if ( ! V_187 ) {
V_187 = true ;
goto V_188;
}
qsort ( V_184 , V_186 , sizeof( char * ) , F_82 ) ;
V_185 = 0 ;
while ( V_185 < V_186 ) {
if ( V_183 ) {
printf ( L_26 , V_184 [ V_185 ++ ] ) ;
continue;
}
printf ( L_27 , V_184 [ V_185 ++ ] ,
V_191 [ V_27 ] ) ;
}
if ( V_186 )
printf ( L_28 ) ;
V_192:
V_186 = V_185 ;
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ )
F_12 ( & V_184 [ V_185 ] ) ;
F_12 ( & V_184 ) ;
return V_186 ;
V_203:
printf ( L_29 , V_191 [ V_27 ] ) ;
if ( V_184 )
goto V_192;
return V_186 ;
}
void F_91 ( const char * V_182 , unsigned type ,
struct V_204 * V_205 , unsigned V_206 ,
bool V_183 )
{
unsigned int V_42 , V_185 = 0 , V_186 = 0 ;
char V_22 [ V_48 ] ;
char * * V_184 = NULL ;
bool V_187 = false ;
V_188:
if ( V_187 ) {
V_184 = F_11 ( sizeof( char * ) * V_186 ) ;
if ( ! V_184 )
goto V_203;
V_205 -= V_206 ;
}
for ( V_42 = 0 ; V_42 < V_206 ; V_42 ++ , V_205 ++ ) {
if ( V_182 != NULL &&
! ( F_29 ( V_205 -> V_141 , V_182 ) ||
( V_205 -> V_145 && F_29 ( V_205 -> V_145 , V_182 ) ) ) )
continue;
if ( ! F_85 ( type , V_42 ) )
continue;
if ( ! V_187 ) {
V_186 ++ ;
continue;
}
if ( ! V_183 && strlen ( V_205 -> V_145 ) )
snprintf ( V_22 , V_48 , L_30 , V_205 -> V_141 , V_205 -> V_145 ) ;
else
strncpy ( V_22 , V_205 -> V_141 , V_48 ) ;
V_184 [ V_185 ] = F_15 ( V_22 ) ;
if ( V_184 [ V_185 ] == NULL )
goto V_203;
V_185 ++ ;
}
if ( ! V_187 ) {
V_187 = true ;
goto V_188;
}
qsort ( V_184 , V_186 , sizeof( char * ) , F_82 ) ;
V_185 = 0 ;
while ( V_185 < V_186 ) {
if ( V_183 ) {
printf ( L_26 , V_184 [ V_185 ++ ] ) ;
continue;
}
printf ( L_27 , V_184 [ V_185 ++ ] , V_191 [ type ] ) ;
}
if ( V_186 )
printf ( L_28 ) ;
V_192:
V_186 = V_185 ;
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ )
F_12 ( & V_184 [ V_185 ] ) ;
F_12 ( & V_184 ) ;
return;
V_203:
printf ( L_29 , V_191 [ type ] ) ;
if ( V_184 )
goto V_192;
}
void F_92 ( const char * V_182 , bool V_183 )
{
F_91 ( V_182 , V_24 ,
V_207 , V_208 , V_183 ) ;
F_91 ( V_182 , V_25 ,
V_209 , V_210 , V_183 ) ;
F_89 ( V_182 , V_183 ) ;
F_93 ( V_182 , V_183 ) ;
if ( V_182 != NULL )
return;
if ( ! V_183 ) {
printf ( L_27 ,
L_31 ,
V_191 [ V_211 ] ) ;
printf ( L_27 ,
L_32 ,
V_191 [ V_211 ] ) ;
printf ( L_33 ) ;
printf ( L_28 ) ;
printf ( L_27 ,
L_34 ,
V_191 [ V_78 ] ) ;
printf ( L_28 ) ;
}
F_83 ( NULL , NULL , V_183 ) ;
}
int F_94 ( struct V_80 * V_81 )
{
return V_81 -> V_82 != V_212 ;
}
static int F_95 ( struct V_80 * * V_213 , int V_214 ,
int V_82 , char * V_12 ,
char * V_23 , T_1 V_86 )
{
struct V_80 * V_81 ;
V_81 = F_11 ( sizeof( * V_81 ) ) ;
if ( ! V_81 )
return - V_38 ;
F_96 ( & V_81 -> V_30 ) ;
V_81 -> V_214 = V_214 ;
V_81 -> V_82 = V_82 ;
V_81 -> V_12 = V_12 ;
switch ( V_214 ) {
case V_215 :
V_81 -> V_85 . V_86 = V_86 ;
break;
case V_216 :
V_81 -> V_85 . V_23 = V_23 ;
break;
default:
free ( V_81 ) ;
return - V_10 ;
}
* V_213 = V_81 ;
return 0 ;
}
int F_97 ( struct V_80 * * V_81 ,
int V_82 , char * V_12 , T_1 V_86 )
{
return F_95 ( V_81 , V_215 , V_82 ,
V_12 , NULL , V_86 ) ;
}
int F_98 ( struct V_80 * * V_81 ,
int V_82 , char * V_12 , char * V_23 )
{
return F_95 ( V_81 , V_216 , V_82 ,
V_12 , V_23 , 0 ) ;
}
int F_99 ( struct V_80 * * V_81 ,
char * V_12 , unsigned V_31 )
{
struct V_204 * V_217 ;
F_100 ( V_31 >= V_208 ) ;
V_217 = & V_207 [ V_31 ] ;
if ( V_12 )
return F_95 ( V_81 , V_216 ,
V_212 , V_12 ,
( char * ) V_217 -> V_141 , 0 ) ;
else
return F_95 ( V_81 , V_216 ,
V_212 ,
( char * ) L_35 , ( char * ) V_217 -> V_141 , 0 ) ;
}
int F_101 ( struct V_80 * * V_218 ,
struct V_80 * V_81 )
{
return F_95 ( V_218 , V_81 -> V_214 , V_81 -> V_82 , V_81 -> V_12 ,
V_81 -> V_85 . V_23 , V_81 -> V_85 . V_86 ) ;
}
void F_75 ( struct V_29 * V_161 )
{
struct V_80 * V_81 , * V_219 ;
F_102 (term, h, terms, list)
free ( V_81 ) ;
}
