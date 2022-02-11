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
char * V_22 , struct V_34 * V_35 ,
struct V_29 * V_36 )
{
struct V_28 * V_37 ;
F_18 ( V_33 ) ;
V_37 = F_19 ( V_33 , ( * V_31 ) ++ ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_35 = F_20 ( V_35 ) ;
V_37 -> V_38 = F_20 ( V_35 ) ;
if ( V_22 )
V_37 -> V_22 = F_15 ( V_22 ) ;
if ( V_36 )
F_21 ( V_36 , & V_37 -> V_36 ) ;
F_22 ( & V_37 -> V_39 , V_30 ) ;
return V_37 ;
}
static int F_23 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 , char * V_22 ,
struct V_29 * V_36 )
{
return F_17 ( V_30 , V_31 , V_33 , V_22 , NULL , V_36 ) ? 0 : - V_40 ;
}
static int F_24 ( char * V_23 , const char * V_41 [] [ V_42 ] , int V_43 )
{
int V_44 , V_45 ;
int V_46 , V_47 = - 1 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
for ( V_45 = 0 ; V_45 < V_42 && V_41 [ V_44 ] [ V_45 ] ; V_45 ++ ) {
V_46 = strlen ( V_41 [ V_44 ] [ V_45 ] ) ;
if ( V_46 > V_47 && ! strncasecmp ( V_23 , V_41 [ V_44 ] [ V_45 ] , V_46 ) )
V_47 = V_46 ;
}
if ( V_47 > 0 )
return V_44 ;
}
return - 1 ;
}
int F_25 ( struct V_29 * V_30 , int * V_31 ,
char * type , char * V_48 , char * V_49 )
{
struct V_32 V_33 ;
char V_22 [ V_50 ] ;
int V_51 = - 1 , V_52 = - 1 , V_53 = - 1 ;
char * V_54 [ 2 ] = { V_48 , V_49 } ;
int V_44 , V_46 ;
V_51 = F_24 ( type , V_55 ,
V_56 ) ;
if ( V_51 == - 1 )
return - V_10 ;
V_46 = snprintf ( V_22 , V_50 , L_9 , type ) ;
for ( V_44 = 0 ; ( V_44 < 2 ) && ( V_54 [ V_44 ] ) ; V_44 ++ ) {
char * V_23 = V_54 [ V_44 ] ;
V_46 += snprintf ( V_22 + V_46 , V_50 - V_46 , L_10 , V_23 ) ;
if ( V_52 == - 1 ) {
V_52 = F_24 ( V_23 , V_57 ,
V_58 ) ;
if ( V_52 >= 0 ) {
if ( ! F_26 ( V_51 , V_52 ) )
return - V_10 ;
continue;
}
}
if ( V_53 == - 1 ) {
V_53 = F_24 ( V_23 , V_59 ,
V_60 ) ;
if ( V_53 >= 0 )
continue;
}
}
if ( V_52 == - 1 )
V_52 = V_61 ;
if ( V_53 == - 1 )
V_53 = V_62 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_12 = V_51 | ( V_52 << 8 ) | ( V_53 << 16 ) ;
V_33 . type = V_27 ;
return F_23 ( V_30 , V_31 , & V_33 , V_22 , NULL ) ;
}
static int F_27 ( struct V_29 * V_30 , int * V_31 ,
char * V_63 , char * V_64 )
{
struct V_28 * V_37 ;
V_37 = F_28 ( V_63 , V_64 , ( * V_31 ) ++ ) ;
if ( ! V_37 )
return - V_40 ;
F_22 ( & V_37 -> V_39 , V_30 ) ;
return 0 ;
}
static int F_29 ( struct V_29 * V_30 , int * V_31 ,
char * V_63 , char * V_64 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_65 ;
T_2 * V_3 ;
int V_66 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_63 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_66 && ( V_65 = F_30 ( V_3 ) ) ) {
if ( ! strcmp ( V_65 -> V_8 , L_12 )
|| ! strcmp ( V_65 -> V_8 , L_13 )
|| ! strcmp ( V_65 -> V_8 , L_14 )
|| ! strcmp ( V_65 -> V_8 , L_15 ) )
continue;
if ( ! F_31 ( V_65 -> V_8 , V_64 ) )
continue;
V_66 = F_27 ( V_30 , V_31 , V_63 , V_65 -> V_8 ) ;
}
F_10 ( V_3 ) ;
return V_66 ;
}
static int F_32 ( struct V_29 * V_30 , int * V_31 ,
char * V_63 , char * V_64 )
{
return strpbrk ( V_64 , L_16 ) ?
F_29 ( V_30 , V_31 , V_63 , V_64 ) :
F_27 ( V_30 , V_31 , V_63 , V_64 ) ;
}
static int F_33 ( struct V_29 * V_30 , int * V_31 ,
char * V_63 , char * V_64 )
{
struct V_1 * V_67 ;
T_2 * V_68 ;
int V_66 = 0 ;
V_68 = F_5 ( V_7 ) ;
if ( ! V_68 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_66 && ( V_67 = F_30 ( V_68 ) ) ) {
if ( ! strcmp ( V_67 -> V_8 , L_12 )
|| ! strcmp ( V_67 -> V_8 , L_13 )
|| ! strcmp ( V_67 -> V_8 , L_14 )
|| ! strcmp ( V_67 -> V_8 , L_17 )
|| ! strcmp ( V_67 -> V_8 , L_18 ) )
continue;
if ( ! F_31 ( V_67 -> V_8 , V_63 ) )
continue;
V_66 = F_32 ( V_30 , V_31 , V_67 -> V_8 ,
V_64 ) ;
}
F_10 ( V_68 ) ;
return V_66 ;
}
int F_34 ( struct V_29 * V_30 , int * V_31 ,
char * V_69 , char * V_70 )
{
if ( strpbrk ( V_69 , L_16 ) )
return F_33 ( V_30 , V_31 , V_69 , V_70 ) ;
else
return F_32 ( V_30 , V_31 , V_69 , V_70 ) ;
}
static int
F_35 ( const char * type , struct V_32 * V_33 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
if ( ! type || ! type [ V_44 ] )
break;
#define F_36 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_44 ] ) {
case 'r' :
F_36 ( V_71 ) ;
break;
case 'w' :
F_36 ( V_72 ) ;
break;
case 'x' :
F_36 ( V_73 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_36
if ( ! V_33 -> V_74 )
V_33 -> V_74 = V_71 | V_72 ;
return 0 ;
}
int F_37 ( struct V_29 * V_30 , int * V_31 ,
void * V_75 , char * type , T_1 V_76 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_77 = ( unsigned long ) V_75 ;
if ( F_35 ( type , & V_33 ) )
return - V_10 ;
if ( ! V_76 ) {
if ( V_33 . V_74 == V_73 )
V_76 = sizeof( long ) ;
else
V_76 = V_78 ;
}
V_33 . V_79 = V_76 ;
V_33 . type = V_80 ;
V_33 . V_81 = 1 ;
return F_23 ( V_30 , V_31 , & V_33 , NULL , NULL ) ;
}
static int F_38 ( struct V_82 * V_83 ,
struct V_84 * V_85 ,
int type )
{
if ( type == V_83 -> V_86 )
return 0 ;
if ( V_85 ) {
V_85 -> V_31 = V_83 -> V_87 ;
if ( type == V_88 )
V_85 -> V_23 = F_15 ( L_19 ) ;
else
V_85 -> V_23 = F_15 ( L_20 ) ;
}
return - V_10 ;
}
static int F_39 ( struct V_32 * V_33 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
#define F_40 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_83 -> V_89 ) {
case V_90 :
return 0 ;
case V_91 :
F_40 ( V_92 ) ;
V_33 -> V_12 = V_83 -> V_93 . V_94 ;
break;
case V_95 :
F_40 ( V_92 ) ;
V_33 -> V_96 = V_83 -> V_93 . V_94 ;
break;
case V_97 :
F_40 ( V_92 ) ;
V_33 -> V_98 = V_83 -> V_93 . V_94 ;
break;
case V_99 :
F_40 ( V_92 ) ;
break;
case V_100 :
F_40 ( V_92 ) ;
break;
case V_101 :
break;
case V_102 :
F_40 ( V_92 ) ;
if ( V_83 -> V_93 . V_94 > 1 ) {
V_85 -> V_23 = F_15 ( L_21 ) ;
V_85 -> V_31 = V_83 -> V_87 ;
return - V_10 ;
}
break;
case V_103 :
F_40 ( V_104 ) ;
break;
case V_105 :
F_40 ( V_92 ) ;
break;
case V_106 :
F_40 ( V_104 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_40
}
static int F_41 ( struct V_32 * V_33 ,
struct V_29 * V_107 ,
struct V_84 * V_85 )
{
struct V_82 * V_83 ;
F_42 (term, head, list)
if ( F_39 ( V_33 , V_83 , V_85 ) )
return - V_10 ;
return 0 ;
}
static int F_43 ( struct V_29 * V_108 ,
struct V_29 * T_4 V_109 )
{
#define F_44 ( T_5 , T_6 , T_7 ) \
do { \
struct perf_evsel_config_term *__t; \
\
__t = zalloc(sizeof(*__t)); \
if (!__t) \
return -ENOMEM; \
\
INIT_LIST_HEAD(&__t->list); \
__t->type = PERF_EVSEL__CONFIG_TERM_ ## __type; \
__t->val.__name = __val; \
list_add_tail(&__t->list, head_terms); \
} while (0)
struct V_82 * V_83 ;
F_42 (term, head_config, list) {
switch ( V_83 -> V_89 ) {
case V_99 :
F_44 ( V_110 , V_111 , V_83 -> V_93 . V_94 ) ;
break;
case V_100 :
F_44 ( V_112 , V_113 , V_83 -> V_93 . V_94 ) ;
break;
case V_102 :
F_44 ( TIME , time , V_83 -> V_93 . V_94 ) ;
break;
case V_103 :
F_44 ( V_114 , V_115 , V_83 -> V_93 . V_23 ) ;
break;
case V_105 :
F_44 ( V_116 , V_117 , V_83 -> V_93 . V_94 ) ;
break;
default:
break;
}
}
#undef V_118
return 0 ;
}
int F_45 ( struct V_119 * V_120 ,
struct V_29 * V_30 ,
T_8 type , T_1 V_12 ,
struct V_29 * V_108 )
{
struct V_32 V_33 ;
F_46 ( V_36 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . type = type ;
V_33 . V_12 = V_12 ;
if ( V_108 ) {
if ( F_41 ( & V_33 , V_108 , V_120 -> error ) )
return - V_10 ;
if ( F_43 ( V_108 , & V_36 ) )
return - V_40 ;
}
return F_23 ( V_30 , & V_120 -> V_31 , & V_33 , NULL , & V_36 ) ;
}
static int F_47 ( struct V_82 * V_83 )
{
return V_83 -> V_89 == V_106 ;
}
static char * F_48 ( struct V_29 * T_4 )
{
struct V_82 * V_83 ;
F_42 (term, head_terms, list)
if ( F_47 ( V_83 ) )
return V_83 -> V_93 . V_23 ;
return NULL ;
}
int F_49 ( struct V_119 * V_120 ,
struct V_29 * V_30 , char * V_22 ,
struct V_29 * V_108 )
{
struct V_32 V_33 ;
struct V_121 V_122 ;
struct V_123 * V_124 ;
struct V_28 * V_37 ;
F_46 ( V_36 ) ;
V_124 = F_50 ( V_22 ) ;
if ( ! V_124 )
return - V_10 ;
if ( V_124 -> V_125 ) {
memcpy ( & V_33 , V_124 -> V_125 ,
sizeof( struct V_32 ) ) ;
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( ! V_108 ) {
V_33 . type = V_124 -> type ;
V_37 = F_17 ( V_30 , & V_120 -> V_31 , & V_33 , NULL , V_124 -> V_35 , NULL ) ;
return V_37 ? 0 : - V_40 ;
}
if ( F_51 ( V_124 , V_108 , & V_122 ) )
return - V_10 ;
if ( F_41 ( & V_33 , V_108 , V_120 -> error ) )
return - V_10 ;
if ( F_43 ( V_108 , & V_36 ) )
return - V_40 ;
if ( F_52 ( V_124 , & V_33 , V_108 , V_120 -> error ) )
return - V_10 ;
V_37 = F_17 ( V_30 , & V_120 -> V_31 , & V_33 ,
F_48 ( V_108 ) , V_124 -> V_35 ,
& V_36 ) ;
if ( V_37 ) {
V_37 -> V_126 = V_122 . V_126 ;
V_37 -> V_127 = V_122 . V_127 ;
V_37 -> V_128 = V_122 . V_128 ;
V_37 -> V_129 = V_122 . V_129 ;
}
return V_37 ? 0 : - V_40 ;
}
int F_53 ( struct V_29 * V_30 ,
char * V_130 )
{
return F_54 ( V_30 , V_130 , true ) ;
}
void F_55 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_131 ;
F_56 ( V_30 ) ;
V_131 = F_57 ( V_30 -> V_132 , struct V_28 , V_39 ) ;
V_131 -> V_133 = V_22 ? F_15 ( V_22 ) : NULL ;
}
void F_58 ( struct V_29 * V_134 ,
struct V_29 * V_135 )
{
F_59 ( V_134 , V_135 ) ;
free ( V_134 ) ;
}
static int F_60 ( struct V_136 * V_137 , char * V_23 ,
struct V_28 * V_37 )
{
int V_138 = V_37 ? V_37 -> V_33 . V_139 : 0 ;
int V_140 = V_37 ? V_37 -> V_33 . V_141 : 0 ;
int V_142 = V_37 ? V_37 -> V_33 . V_143 : 0 ;
int V_144 = V_37 ? V_37 -> V_33 . V_145 : 0 ;
int V_146 = V_37 ? V_37 -> V_33 . V_147 : 0 ;
int V_148 = V_37 ? V_37 -> V_33 . V_149 : 0 ;
int V_150 = V_37 ? V_37 -> V_33 . V_151 : 0 ;
int V_152 = 0 ;
int V_153 = V_37 ? V_37 -> V_33 . V_153 : 0 ;
int V_154 = V_138 | V_140 | V_142 ;
int V_155 = V_37 ? V_37 -> V_155 : 0 ;
memset ( V_137 , 0 , sizeof( * V_137 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_154 )
V_154 = V_138 = V_140 = V_142 = 1 ;
V_138 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_154 )
V_154 = V_138 = V_140 = V_142 = 1 ;
V_140 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_154 )
V_154 = V_138 = V_140 = V_142 = 1 ;
V_142 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_155 )
V_155 = V_146 = V_144 = 1 ;
V_146 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_155 )
V_155 = V_146 = V_144 = 1 ;
V_144 = 0 ;
} else if ( * V_23 == 'I' ) {
V_148 = 1 ;
} else if ( * V_23 == 'p' ) {
V_150 ++ ;
if ( ! V_155 )
V_146 = 1 ;
} else if ( * V_23 == 'S' ) {
V_152 = 1 ;
} else if ( * V_23 == 'D' ) {
V_153 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_150 > 3 )
return - V_10 ;
V_137 -> V_138 = V_138 ;
V_137 -> V_140 = V_140 ;
V_137 -> V_142 = V_142 ;
V_137 -> V_144 = V_144 ;
V_137 -> V_146 = V_146 ;
V_137 -> V_148 = V_148 ;
V_137 -> V_150 = V_150 ;
V_137 -> V_155 = V_155 ;
V_137 -> V_152 = V_152 ;
V_137 -> V_153 = V_153 ;
return 0 ;
}
static int F_61 ( char * V_23 )
{
char * V_156 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_22 ) - 1 ) )
return - 1 ;
while ( * V_156 ) {
if ( * V_156 != 'p' && strchr ( V_156 + 1 , * V_156 ) )
return - 1 ;
V_156 ++ ;
}
return 0 ;
}
int F_54 ( struct V_29 * V_30 , char * V_23 , bool V_157 )
{
struct V_28 * V_37 ;
struct V_136 V_137 ;
if ( V_23 == NULL )
return 0 ;
if ( F_61 ( V_23 ) )
return - V_10 ;
if ( ! V_157 && F_60 ( & V_137 , V_23 , NULL ) )
return - V_10 ;
F_62 (list, evsel) {
if ( V_157 && F_60 ( & V_137 , V_23 , V_37 ) )
return - V_10 ;
V_37 -> V_33 . V_139 = V_137 . V_138 ;
V_37 -> V_33 . V_141 = V_137 . V_140 ;
V_37 -> V_33 . V_143 = V_137 . V_142 ;
V_37 -> V_33 . V_151 = V_137 . V_150 ;
V_37 -> V_33 . V_145 = V_137 . V_144 ;
V_37 -> V_33 . V_147 = V_137 . V_146 ;
V_37 -> V_33 . V_149 = V_137 . V_148 ;
V_37 -> V_155 = V_137 . V_155 ;
V_37 -> V_152 = V_137 . V_152 ;
if ( F_63 ( V_37 ) )
V_37 -> V_33 . V_153 = V_137 . V_153 ;
}
return 0 ;
}
int F_64 ( struct V_29 * V_30 , char * V_22 )
{
struct V_28 * V_37 ;
F_62 (list, evsel) {
if ( ! V_37 -> V_22 )
V_37 -> V_22 = F_15 ( V_22 ) ;
}
return 0 ;
}
static int
F_65 ( const void * V_158 , const void * V_159 )
{
struct V_160 * V_161 = (struct V_160 * ) V_158 ;
struct V_160 * V_162 = (struct V_160 * ) V_159 ;
return strcmp ( V_161 -> V_163 , V_162 -> V_163 ) ;
}
static void F_66 ( void )
{
if ( V_164 > 0 ) {
struct V_160 * V_156 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_164 ; V_44 ++ ) {
V_156 = V_165 + V_44 ;
free ( V_156 -> V_163 ) ;
}
free ( V_165 ) ;
V_165 = NULL ;
V_164 = 0 ;
}
}
static void F_67 ( void )
{
struct V_123 * V_124 = NULL ;
struct V_166 * V_167 ;
int V_76 = 0 ;
V_124 = F_50 ( L_23 ) ;
if ( ( V_124 == NULL ) || F_68 ( & V_124 -> V_168 ) ) {
V_164 = - 1 ;
return;
}
F_42 (alias, &pmu->aliases, list) {
if ( strchr ( V_167 -> V_22 , '-' ) )
V_76 ++ ;
V_76 ++ ;
}
V_165 = malloc ( sizeof( struct V_160 ) * V_76 ) ;
if ( ! V_165 )
return;
V_164 = V_76 ;
V_76 = 0 ;
F_42 (alias, &pmu->aliases, list) {
struct V_160 * V_156 = V_165 + V_76 ;
char * V_169 = strchr ( V_167 -> V_22 , '-' ) ;
if ( V_169 != NULL ) {
F_69 ( F_14 ( V_167 -> V_22 , V_169 - V_167 -> V_22 ) ,
V_170 ) ;
V_156 ++ ;
F_69 ( F_15 ( ++ V_169 ) , V_171 ) ;
V_76 += 2 ;
} else {
F_69 ( F_15 ( V_167 -> V_22 ) , V_172 ) ;
V_76 ++ ;
}
}
qsort ( V_165 , V_76 ,
sizeof( struct V_160 ) , F_65 ) ;
return;
V_85:
F_66 () ;
}
enum V_173
F_70 ( const char * V_22 )
{
struct V_160 V_156 , * V_174 ;
if ( V_164 == 0 )
F_67 () ;
if ( ( V_164 <= 0 ) || ! strcmp ( V_22 , L_23 ) )
return V_175 ;
V_156 . V_163 = F_15 ( V_22 ) ;
V_174 = bsearch ( & V_156 , V_165 ,
( V_176 ) V_164 ,
sizeof( struct V_160 ) , F_65 ) ;
free ( V_156 . V_163 ) ;
return V_174 ? V_174 -> type : V_175 ;
}
static int F_71 ( const char * V_23 , void * V_120 , int V_177 )
{
T_9 V_178 ;
void * V_179 ;
int V_66 ;
V_66 = F_72 ( V_177 , & V_179 ) ;
if ( V_66 )
return V_66 ;
V_178 = F_73 ( V_23 , V_179 ) ;
#ifdef F_74
V_180 = 1 ;
#endif
V_66 = F_75 ( V_120 , V_179 ) ;
F_76 ( V_178 , V_179 ) ;
F_77 ( V_178 , V_179 ) ;
F_78 ( V_179 ) ;
return V_66 ;
}
int F_79 ( struct V_29 * V_181 , const char * V_23 )
{
struct F_79 V_120 = {
. V_181 = NULL ,
} ;
int V_66 ;
V_66 = F_71 ( V_23 , & V_120 , V_182 ) ;
if ( ! V_66 ) {
F_21 ( V_120 . V_181 , V_181 ) ;
F_12 ( & V_120 . V_181 ) ;
return 0 ;
}
if ( V_120 . V_181 )
F_80 ( V_120 . V_181 ) ;
return V_66 ;
}
int F_81 ( struct V_183 * V_184 , const char * V_23 ,
struct V_84 * V_85 )
{
struct V_119 V_120 = {
. V_30 = F_82 ( V_120 . V_30 ) ,
. V_31 = V_184 -> V_185 ,
. error = V_85 ,
} ;
int V_66 ;
V_66 = F_71 ( V_23 , & V_120 , V_186 ) ;
F_66 () ;
if ( ! V_66 ) {
struct V_28 * V_187 ;
F_83 ( V_184 , & V_120 . V_30 ) ;
V_184 -> V_188 += V_120 . V_188 ;
V_187 = F_84 ( V_184 ) ;
V_187 -> V_189 = true ;
return 0 ;
}
return V_66 ;
}
static int F_85 ( void )
{
struct V_190 V_191 ;
F_86 ( & V_191 ) ;
return V_191 . V_192 > V_193 ? V_193 : V_191 . V_192 ;
}
static void F_87 ( struct V_84 * V_85 ,
const char * V_70 )
{
const char * V_23 = L_24 ;
char V_194 [ V_193 ] ;
char * V_195 = ( char * ) V_70 ;
int V_31 = 0 ;
if ( V_85 -> V_23 ) {
int V_196 = F_85 () - 2 ;
int V_197 = strlen ( V_70 ) ;
int V_198 , V_199 , V_200 = 0 ;
int V_201 = 13 ;
V_23 = L_25 ;
V_198 = strlen ( V_23 ) ;
V_199 = V_196 - V_198 ;
V_195 = V_194 ;
if ( V_85 -> V_31 > V_201 )
V_200 = V_85 -> V_31 - V_201 ;
strncpy ( V_195 , V_70 + V_200 , V_199 ) ;
if ( V_200 )
V_195 [ 0 ] = V_195 [ 1 ] = '.' ;
if ( ( V_197 - V_200 ) > V_199 ) {
V_195 [ V_199 - 1 ] = V_195 [ V_199 - 2 ] = '.' ;
V_195 [ V_199 ] = 0 ;
}
V_31 = V_198 + V_85 -> V_31 - V_200 ;
}
fprintf ( V_202 , L_26 , V_23 , V_195 ) ;
if ( V_31 ) {
fprintf ( V_202 , L_27 , V_31 + 1 , L_28 , V_85 -> V_23 ) ;
if ( V_85 -> V_203 )
fprintf ( V_202 , L_29 , V_85 -> V_203 ) ;
free ( V_85 -> V_23 ) ;
free ( V_85 -> V_203 ) ;
}
fprintf ( V_202 , L_30 ) ;
}
int F_88 ( const struct V_204 * V_205 , const char * V_23 ,
int T_10 V_109 )
{
struct V_183 * V_184 = * (struct V_183 * * ) V_205 -> V_206 ;
struct V_84 V_85 = { . V_31 = 0 , } ;
int V_66 = F_81 ( V_184 , V_23 , & V_85 ) ;
if ( V_66 )
F_87 ( & V_85 , V_23 ) ;
return V_66 ;
}
static int
F_89 ( struct V_183 * V_184 ,
int (* F_90)( struct V_28 * V_37 ,
const void * V_207 ) ,
const void * V_207 )
{
struct V_28 * V_187 = NULL ;
int V_85 ;
if ( V_184 -> V_185 > 0 )
V_187 = F_84 ( V_184 ) ;
do {
V_85 = (* F_90)( V_187 , V_207 ) ;
if ( V_85 )
return - 1 ;
if ( ! V_187 )
return 0 ;
if ( V_187 -> V_39 . V_208 == & V_184 -> V_209 )
return 0 ;
V_187 = F_57 ( V_187 -> V_39 . V_208 , struct V_28 , V_39 ) ;
} while ( ! V_187 -> V_189 );
return 0 ;
}
static int F_91 ( struct V_28 * V_37 , const void * V_207 )
{
const char * V_23 = V_207 ;
if ( V_37 == NULL || V_37 -> V_33 . type != V_26 ) {
fprintf ( V_202 ,
L_31 ) ;
return - 1 ;
}
if ( F_92 ( V_37 , L_32 , V_23 ) < 0 ) {
fprintf ( V_202 ,
L_33 ) ;
return - 1 ;
}
return 0 ;
}
int F_93 ( const struct V_204 * V_205 , const char * V_23 ,
int T_10 V_109 )
{
struct V_183 * V_184 = * (struct V_183 * * ) V_205 -> V_206 ;
return F_89 ( V_184 , F_91 ,
( const void * ) V_23 ) ;
}
static int F_94 ( struct V_28 * V_37 ,
const void * V_207 V_109 )
{
char V_210 [ 64 ] ;
if ( V_37 == NULL || V_37 -> V_33 . type != V_26 ) {
fprintf ( V_202 ,
L_34 ) ;
return - 1 ;
}
snprintf ( V_210 , sizeof( V_210 ) , L_35 , F_95 () ) ;
if ( F_92 ( V_37 , L_32 , V_210 ) < 0 ) {
fprintf ( V_202 ,
L_33 ) ;
return - 1 ;
}
return 0 ;
}
int F_96 ( const struct V_204 * V_205 ,
const char * V_207 V_109 ,
int T_10 V_109 )
{
struct V_183 * V_184 = * (struct V_183 * * ) V_205 -> V_206 ;
return F_89 ( V_184 , F_94 ,
NULL ) ;
}
static int F_97 ( const void * V_211 , const void * V_212 )
{
const char * const * V_213 = V_211 ;
const char * const * V_214 = V_212 ;
return strcmp ( * V_213 , * V_214 ) ;
}
void F_98 ( const char * V_215 , const char * V_216 ,
bool V_217 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char * * V_218 = NULL ;
unsigned int V_219 = 0 , V_220 = 0 ;
bool V_221 = false ;
V_222:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_221 ) {
V_218 = F_11 ( sizeof( char * ) * V_220 ) ;
if ( ! V_218 )
goto V_223;
}
F_6 (sys_dir, sys_dirent, sys_next) {
if ( V_215 != NULL &&
! F_31 ( V_16 . V_8 , V_215 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_216 != NULL &&
! F_31 ( V_17 . V_8 , V_216 ) )
continue;
if ( ! V_221 ) {
V_220 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_36 ,
V_16 . V_8 , V_17 . V_8 ) ;
V_218 [ V_219 ] = F_15 ( V_4 ) ;
if ( V_218 [ V_219 ] == NULL )
goto V_224;
V_219 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_221 ) {
V_221 = true ;
goto V_222;
}
qsort ( V_218 , V_220 , sizeof( char * ) , F_97 ) ;
V_219 = 0 ;
while ( V_219 < V_220 ) {
if ( V_217 ) {
printf ( L_37 , V_218 [ V_219 ++ ] ) ;
continue;
}
printf ( L_38 , V_218 [ V_219 ++ ] ,
V_225 [ V_26 ] ) ;
}
if ( V_220 )
printf ( L_39 ) ;
V_226:
V_220 = V_219 ;
for ( V_219 = 0 ; V_219 < V_220 ; V_219 ++ )
F_12 ( & V_218 [ V_219 ] ) ;
F_12 ( & V_218 ) ;
return;
V_224:
F_10 ( V_3 ) ;
V_223:
F_10 ( V_2 ) ;
printf ( L_40 ,
V_225 [ V_26 ] ) ;
if ( V_218 )
goto V_226;
}
int F_99 ( const char * V_227 )
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
snprintf ( V_4 , V_5 , L_36 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_227 ) ) {
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
static bool F_100 ( T_11 type , unsigned V_12 )
{
bool V_66 = true ;
int V_228 ;
struct V_28 * V_37 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_229 = 1 ,
} ;
struct {
struct V_230 V_231 ;
int V_232 [ 1 ] ;
} V_233 = {
. V_231 . V_234 = 1 ,
. V_232 = { 0 } ,
} ;
V_37 = F_101 ( & V_33 ) ;
if ( V_37 ) {
V_228 = F_102 ( V_37 , NULL , & V_233 . V_231 ) ;
V_66 = V_228 >= 0 ;
if ( V_228 == - V_235 ) {
V_37 -> V_33 . V_141 = 1 ;
V_66 = F_102 ( V_37 , NULL , & V_233 . V_231 ) >= 0 ;
}
F_103 ( V_37 ) ;
}
return V_66 ;
}
int F_104 ( const char * V_216 , bool V_217 )
{
unsigned int type , V_236 , V_44 , V_219 = 0 , V_220 = 0 ;
char V_22 [ 64 ] ;
char * * V_218 = NULL ;
bool V_221 = false ;
V_222:
if ( V_221 ) {
V_218 = F_11 ( sizeof( char * ) * V_220 ) ;
if ( ! V_218 )
goto V_237;
}
for ( type = 0 ; type < V_56 ; type ++ ) {
for ( V_236 = 0 ; V_236 < V_58 ; V_236 ++ ) {
if ( ! F_26 ( type , V_236 ) )
continue;
for ( V_44 = 0 ; V_44 < V_60 ; V_44 ++ ) {
F_105 ( type , V_236 , V_44 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_216 != NULL && ! F_31 ( V_22 , V_216 ) )
continue;
if ( ! F_100 ( V_27 ,
type | ( V_236 << 8 ) | ( V_44 << 16 ) ) )
continue;
if ( ! V_221 ) {
V_220 ++ ;
continue;
}
V_218 [ V_219 ] = F_15 ( V_22 ) ;
if ( V_218 [ V_219 ] == NULL )
goto V_237;
V_219 ++ ;
}
}
}
if ( ! V_221 ) {
V_221 = true ;
goto V_222;
}
qsort ( V_218 , V_220 , sizeof( char * ) , F_97 ) ;
V_219 = 0 ;
while ( V_219 < V_220 ) {
if ( V_217 ) {
printf ( L_37 , V_218 [ V_219 ++ ] ) ;
continue;
}
printf ( L_38 , V_218 [ V_219 ++ ] ,
V_225 [ V_27 ] ) ;
}
if ( V_220 )
printf ( L_39 ) ;
V_226:
V_220 = V_219 ;
for ( V_219 = 0 ; V_219 < V_220 ; V_219 ++ )
F_12 ( & V_218 [ V_219 ] ) ;
F_12 ( & V_218 ) ;
return V_220 ;
V_237:
printf ( L_40 , V_225 [ V_27 ] ) ;
if ( V_218 )
goto V_226;
return V_220 ;
}
void F_106 ( const char * V_216 , unsigned type ,
struct V_238 * V_239 , unsigned V_240 ,
bool V_217 )
{
unsigned int V_44 , V_219 = 0 , V_220 = 0 ;
char V_22 [ V_50 ] ;
char * * V_218 = NULL ;
bool V_221 = false ;
V_222:
if ( V_221 ) {
V_218 = F_11 ( sizeof( char * ) * V_220 ) ;
if ( ! V_218 )
goto V_237;
V_239 -= V_240 ;
}
for ( V_44 = 0 ; V_44 < V_240 ; V_44 ++ , V_239 ++ ) {
if ( V_216 != NULL &&
! ( F_31 ( V_239 -> V_163 , V_216 ) ||
( V_239 -> V_167 && F_31 ( V_239 -> V_167 , V_216 ) ) ) )
continue;
if ( ! F_100 ( type , V_44 ) )
continue;
if ( ! V_221 ) {
V_220 ++ ;
continue;
}
if ( ! V_217 && strlen ( V_239 -> V_167 ) )
snprintf ( V_22 , V_50 , L_41 , V_239 -> V_163 , V_239 -> V_167 ) ;
else
strncpy ( V_22 , V_239 -> V_163 , V_50 ) ;
V_218 [ V_219 ] = F_15 ( V_22 ) ;
if ( V_218 [ V_219 ] == NULL )
goto V_237;
V_219 ++ ;
}
if ( ! V_221 ) {
V_221 = true ;
goto V_222;
}
qsort ( V_218 , V_220 , sizeof( char * ) , F_97 ) ;
V_219 = 0 ;
while ( V_219 < V_220 ) {
if ( V_217 ) {
printf ( L_37 , V_218 [ V_219 ++ ] ) ;
continue;
}
printf ( L_38 , V_218 [ V_219 ++ ] , V_225 [ type ] ) ;
}
if ( V_220 )
printf ( L_39 ) ;
V_226:
V_220 = V_219 ;
for ( V_219 = 0 ; V_219 < V_220 ; V_219 ++ )
F_12 ( & V_218 [ V_219 ] ) ;
F_12 ( & V_218 ) ;
return;
V_237:
printf ( L_40 , V_225 [ type ] ) ;
if ( V_218 )
goto V_226;
}
void F_107 ( const char * V_216 , bool V_217 )
{
F_106 ( V_216 , V_24 ,
V_241 , V_242 , V_217 ) ;
F_106 ( V_216 , V_25 ,
V_243 , V_244 , V_217 ) ;
F_104 ( V_216 , V_217 ) ;
F_108 ( V_216 , V_217 ) ;
if ( V_216 != NULL )
return;
if ( ! V_217 ) {
printf ( L_38 ,
L_42 ,
V_225 [ V_245 ] ) ;
printf ( L_38 ,
L_43 ,
V_225 [ V_245 ] ) ;
printf ( L_44 ) ;
printf ( L_39 ) ;
printf ( L_38 ,
L_45 ,
V_225 [ V_80 ] ) ;
printf ( L_39 ) ;
}
F_98 ( NULL , NULL , V_217 ) ;
}
int F_109 ( struct V_82 * V_83 )
{
return V_83 -> V_89 != V_90 ;
}
static int F_110 ( struct V_82 * * V_246 , int V_86 ,
int V_89 , char * V_12 ,
char * V_23 , T_1 V_94 , int V_247 , int V_87 )
{
struct V_82 * V_83 ;
V_83 = F_11 ( sizeof( * V_83 ) ) ;
if ( ! V_83 )
return - V_40 ;
F_111 ( & V_83 -> V_30 ) ;
V_83 -> V_86 = V_86 ;
V_83 -> V_89 = V_89 ;
V_83 -> V_12 = V_12 ;
V_83 -> V_247 = V_247 ;
V_83 -> V_87 = V_87 ;
switch ( V_86 ) {
case V_88 :
V_83 -> V_93 . V_94 = V_94 ;
break;
case V_248 :
V_83 -> V_93 . V_23 = V_23 ;
break;
default:
free ( V_83 ) ;
return - V_10 ;
}
* V_246 = V_83 ;
return 0 ;
}
int F_112 ( struct V_82 * * V_83 ,
int V_89 , char * V_12 , T_1 V_94 ,
void * V_249 , void * V_250 )
{
T_12 * V_251 = V_249 ;
T_12 * V_252 = V_250 ;
return F_110 ( V_83 , V_88 , V_89 ,
V_12 , NULL , V_94 ,
V_251 ? V_251 -> V_253 : 0 ,
V_252 ? V_252 -> V_253 : 0 ) ;
}
int F_113 ( struct V_82 * * V_83 ,
int V_89 , char * V_12 , char * V_23 ,
void * V_249 , void * V_250 )
{
T_12 * V_251 = V_249 ;
T_12 * V_252 = V_250 ;
return F_110 ( V_83 , V_248 , V_89 ,
V_12 , V_23 , 0 ,
V_251 ? V_251 -> V_253 : 0 ,
V_252 ? V_252 -> V_253 : 0 ) ;
}
int F_114 ( struct V_82 * * V_83 ,
char * V_12 , unsigned V_31 )
{
struct V_238 * V_254 ;
F_115 ( V_31 >= V_242 ) ;
V_254 = & V_241 [ V_31 ] ;
if ( V_12 )
return F_110 ( V_83 , V_248 ,
V_90 , V_12 ,
( char * ) V_254 -> V_163 , 0 , 0 , 0 ) ;
else
return F_110 ( V_83 , V_248 ,
V_90 ,
( char * ) L_46 , ( char * ) V_254 -> V_163 ,
0 , 0 , 0 ) ;
}
int F_116 ( struct V_82 * * V_255 ,
struct V_82 * V_83 )
{
return F_110 ( V_255 , V_83 -> V_86 , V_83 -> V_89 , V_83 -> V_12 ,
V_83 -> V_93 . V_23 , V_83 -> V_93 . V_94 ,
V_83 -> V_247 , V_83 -> V_87 ) ;
}
void F_80 ( struct V_29 * V_181 )
{
struct V_82 * V_83 , * V_256 ;
F_117 (term, h, terms, list)
free ( V_83 ) ;
}
void F_118 ( struct V_119 * V_120 ,
int V_31 , const char * V_23 )
{
struct V_84 * V_85 = V_120 -> error ;
if ( ! V_85 )
return;
V_85 -> V_31 = V_31 ;
V_85 -> V_23 = F_15 ( V_23 ) ;
F_119 ( ! V_85 -> V_23 , L_47 ) ;
}
