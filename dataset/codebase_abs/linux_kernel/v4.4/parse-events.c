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
static void F_27 ( struct V_63 * V_64 , int V_65 ,
char * V_66 , char * V_22 )
{
char V_67 [ V_68 ] ;
V_65 = abs ( V_65 ) ;
switch ( V_65 ) {
case V_69 :
V_64 -> V_23 = F_15 ( L_11 ) ;
break;
case V_70 :
V_64 -> V_23 = F_15 ( L_12 ) ;
break;
default:
V_64 -> V_23 = F_15 ( L_13 ) ;
break;
}
F_28 ( V_65 , V_67 , sizeof( V_67 ) , V_66 , V_22 ) ;
V_64 -> V_67 = F_15 ( V_67 ) ;
}
static int F_29 ( struct V_29 * V_30 , int * V_31 ,
char * V_71 , char * V_72 ,
struct V_63 * V_65 ,
struct V_29 * V_73 )
{
struct V_28 * V_37 ;
V_37 = F_30 ( V_71 , V_72 , ( * V_31 ) ++ ) ;
if ( F_31 ( V_37 ) ) {
F_27 ( V_65 , F_32 ( V_37 ) , V_71 , V_72 ) ;
return F_32 ( V_37 ) ;
}
if ( V_73 ) {
F_33 ( V_36 ) ;
if ( F_34 ( V_73 , & V_36 ) )
return - V_40 ;
F_21 ( & V_36 , & V_37 -> V_36 ) ;
}
F_22 ( & V_37 -> V_39 , V_30 ) ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 , int * V_31 ,
char * V_71 , char * V_72 ,
struct V_63 * V_65 ,
struct V_29 * V_73 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_74 ;
T_2 * V_3 ;
int V_75 = 0 , V_76 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_71 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
F_27 ( V_65 , V_77 , V_71 , V_72 ) ;
return - 1 ;
}
while ( ! V_75 && ( V_74 = F_36 ( V_3 ) ) ) {
if ( ! strcmp ( V_74 -> V_8 , L_14 )
|| ! strcmp ( V_74 -> V_8 , L_15 )
|| ! strcmp ( V_74 -> V_8 , L_16 )
|| ! strcmp ( V_74 -> V_8 , L_17 ) )
continue;
if ( ! F_37 ( V_74 -> V_8 , V_72 ) )
continue;
V_76 ++ ;
V_75 = F_29 ( V_30 , V_31 , V_71 , V_74 -> V_8 ,
V_65 , V_73 ) ;
}
if ( ! V_76 ) {
F_27 ( V_65 , V_70 , V_71 , V_72 ) ;
V_75 = - 1 ;
}
F_10 ( V_3 ) ;
return V_75 ;
}
static int F_38 ( struct V_29 * V_30 , int * V_31 ,
char * V_71 , char * V_72 ,
struct V_63 * V_65 ,
struct V_29 * V_73 )
{
return strpbrk ( V_72 , L_18 ) ?
F_35 ( V_30 , V_31 , V_71 , V_72 ,
V_65 , V_73 ) :
F_29 ( V_30 , V_31 , V_71 , V_72 ,
V_65 , V_73 ) ;
}
static int F_39 ( struct V_29 * V_30 , int * V_31 ,
char * V_71 , char * V_72 ,
struct V_63 * V_65 ,
struct V_29 * V_73 )
{
struct V_1 * V_78 ;
T_2 * V_79 ;
int V_75 = 0 ;
V_79 = F_5 ( V_7 ) ;
if ( ! V_79 ) {
F_27 ( V_65 , V_77 , V_71 , V_72 ) ;
return - 1 ;
}
while ( ! V_75 && ( V_78 = F_36 ( V_79 ) ) ) {
if ( ! strcmp ( V_78 -> V_8 , L_14 )
|| ! strcmp ( V_78 -> V_8 , L_15 )
|| ! strcmp ( V_78 -> V_8 , L_16 )
|| ! strcmp ( V_78 -> V_8 , L_19 )
|| ! strcmp ( V_78 -> V_8 , L_20 ) )
continue;
if ( ! F_37 ( V_78 -> V_8 , V_71 ) )
continue;
V_75 = F_38 ( V_30 , V_31 , V_78 -> V_8 ,
V_72 , V_65 , V_73 ) ;
}
F_10 ( V_79 ) ;
return V_75 ;
}
static int F_40 ( struct V_80 * V_81 , int V_6 ,
void * V_82 )
{
F_33 ( V_83 ) ;
struct V_84 * V_85 = V_82 ;
struct V_86 * V_87 = V_85 -> V_88 ;
struct V_29 * V_30 = V_85 -> V_30 ;
struct V_28 * V_89 ;
int V_65 ;
F_41 ( L_21 ,
V_81 -> V_90 , V_81 -> V_91 , V_6 ) ;
V_65 = F_42 ( & V_83 , & V_87 -> V_31 , V_81 -> V_90 ,
V_81 -> V_91 , V_87 -> error , NULL ) ;
if ( V_65 ) {
struct V_28 * V_37 , * V_92 ;
F_41 ( L_22 ,
V_81 -> V_90 , V_81 -> V_91 ) ;
F_43 (evsel, tmp, &new_evsels, node) {
F_44 ( & V_37 -> V_39 ) ;
F_45 ( V_37 ) ;
}
return V_65 ;
}
F_41 ( L_23 , V_81 -> V_90 , V_81 -> V_91 ) ;
F_46 (pos, &new_evsels, node) {
F_41 ( L_24 ,
V_81 -> V_90 , V_81 -> V_91 , V_89 ) ;
V_89 -> V_93 = V_6 ;
}
F_21 ( & V_83 , V_30 ) ;
return 0 ;
}
int F_47 ( struct V_86 * V_88 ,
struct V_29 * V_30 ,
struct V_94 * V_95 )
{
int V_65 ;
char V_96 [ V_68 ] ;
struct V_84 V_85 = { V_88 , V_30 } ;
static bool V_97 = false ;
if ( F_31 ( V_95 ) || ! V_95 ) {
snprintf ( V_96 , sizeof( V_96 ) ,
L_25 ) ;
V_65 = - V_10 ;
goto V_98;
}
if ( ! V_97 ) {
atexit ( V_99 ) ;
V_97 = true ;
}
V_65 = F_48 ( V_95 ) ;
if ( V_65 ) {
F_49 ( V_95 , V_65 , V_96 , sizeof( V_96 ) ) ;
goto V_98;
}
V_65 = F_50 ( V_95 ) ;
if ( V_65 ) {
F_51 ( V_95 , V_65 , V_96 , sizeof( V_96 ) ) ;
goto V_98;
}
V_65 = F_52 ( V_95 , F_40 , & V_85 ) ;
if ( V_65 ) {
snprintf ( V_96 , sizeof( V_96 ) ,
L_26 ) ;
goto V_98;
}
return 0 ;
V_98:
V_88 -> error -> V_67 = F_15 ( L_27 ) ;
V_88 -> error -> V_23 = F_15 ( V_96 ) ;
return V_65 ;
}
int F_53 ( struct V_86 * V_88 ,
struct V_29 * V_30 ,
char * V_100 ,
bool V_101 )
{
struct V_94 * V_95 ;
V_95 = F_54 ( V_100 , V_101 ) ;
if ( F_31 ( V_95 ) ) {
char V_96 [ V_68 ] ;
int V_65 ;
V_65 = F_32 ( V_95 ) ;
if ( V_65 == - V_102 )
snprintf ( V_96 , sizeof( V_96 ) ,
L_28 ) ;
else
F_55 ( V_100 ,
V_101 ,
- V_65 , V_96 ,
sizeof( V_96 ) ) ;
V_88 -> error -> V_67 = F_15 ( L_27 ) ;
V_88 -> error -> V_23 = F_15 ( V_96 ) ;
return V_65 ;
}
return F_47 ( V_88 , V_30 , V_95 ) ;
}
static int
F_56 ( const char * type , struct V_32 * V_33 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < 3 ; V_44 ++ ) {
if ( ! type || ! type [ V_44 ] )
break;
#define F_57 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_44 ] ) {
case 'r' :
F_57 ( V_103 ) ;
break;
case 'w' :
F_57 ( V_104 ) ;
break;
case 'x' :
F_57 ( V_105 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_57
if ( ! V_33 -> V_106 )
V_33 -> V_106 = V_103 | V_104 ;
return 0 ;
}
int F_58 ( struct V_29 * V_30 , int * V_31 ,
void * V_107 , char * type , T_1 V_108 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_109 = ( unsigned long ) V_107 ;
if ( F_56 ( type , & V_33 ) )
return - V_10 ;
if ( ! V_108 ) {
if ( V_33 . V_106 == V_105 )
V_108 = sizeof( long ) ;
else
V_108 = V_110 ;
}
V_33 . V_111 = V_108 ;
V_33 . type = V_112 ;
V_33 . V_113 = 1 ;
return F_23 ( V_30 , V_31 , & V_33 , NULL , NULL ) ;
}
static int F_59 ( struct V_114 * V_115 ,
struct V_63 * V_65 ,
int type )
{
if ( type == V_115 -> V_116 )
return 0 ;
if ( V_65 ) {
V_65 -> V_31 = V_115 -> V_117 ;
if ( type == V_118 )
V_65 -> V_23 = F_15 ( L_29 ) ;
else
V_65 -> V_23 = F_15 ( L_30 ) ;
}
return - V_10 ;
}
static int F_60 ( struct V_32 * V_33 ,
struct V_114 * V_115 ,
struct V_63 * V_65 )
{
#define F_61 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_115 -> V_119 ) {
case V_120 :
F_61 ( V_121 ) ;
V_33 -> V_12 = V_115 -> V_122 . V_123 ;
break;
case V_124 :
F_61 ( V_121 ) ;
V_33 -> V_125 = V_115 -> V_122 . V_123 ;
break;
case V_126 :
F_61 ( V_121 ) ;
V_33 -> V_127 = V_115 -> V_122 . V_123 ;
break;
case V_128 :
F_61 ( V_121 ) ;
break;
case V_129 :
F_61 ( V_121 ) ;
break;
case V_130 :
break;
case V_131 :
F_61 ( V_121 ) ;
if ( V_115 -> V_122 . V_123 > 1 ) {
V_65 -> V_23 = F_15 ( L_31 ) ;
V_65 -> V_31 = V_115 -> V_117 ;
return - V_10 ;
}
break;
case V_132 :
F_61 ( V_133 ) ;
break;
case V_134 :
F_61 ( V_121 ) ;
break;
case V_135 :
F_61 ( V_121 ) ;
break;
case V_136 :
F_61 ( V_121 ) ;
break;
case V_137 :
F_61 ( V_133 ) ;
break;
default:
V_65 -> V_23 = F_15 ( L_32 ) ;
V_65 -> V_31 = V_115 -> V_138 ;
V_65 -> V_67 = F_62 ( NULL ) ;
return - V_10 ;
}
return 0 ;
#undef F_61
}
static int F_63 ( struct V_32 * V_33 ,
struct V_114 * V_115 ,
struct V_63 * V_65 )
{
if ( V_115 -> V_119 == V_139 )
return 0 ;
else
return F_60 ( V_33 , V_115 , V_65 ) ;
}
static int F_64 ( struct V_32 * V_33 ,
struct V_114 * V_115 ,
struct V_63 * V_65 )
{
switch ( V_115 -> V_119 ) {
case V_132 :
case V_134 :
case V_135 :
case V_136 :
return F_60 ( V_33 , V_115 , V_65 ) ;
default:
if ( V_65 ) {
V_65 -> V_31 = V_115 -> V_138 ;
V_65 -> V_23 = F_15 ( L_32 ) ;
V_65 -> V_67 = F_15 ( L_33 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_65 ( struct V_32 * V_33 ,
struct V_29 * V_140 ,
struct V_63 * V_65 ,
T_4 V_141 )
{
struct V_114 * V_115 ;
F_46 (term, head, list)
if ( V_141 ( V_33 , V_115 , V_65 ) )
return - V_10 ;
return 0 ;
}
static int F_34 ( struct V_29 * V_73 ,
struct V_29 * T_5 V_142 )
{
#define F_66 ( T_6 , T_7 , T_8 ) \
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
struct V_114 * V_115 ;
F_46 (term, head_config, list) {
switch ( V_115 -> V_119 ) {
case V_128 :
F_66 ( V_143 , V_144 , V_115 -> V_122 . V_123 ) ;
break;
case V_129 :
F_66 ( V_145 , V_146 , V_115 -> V_122 . V_123 ) ;
break;
case V_131 :
F_66 ( TIME , time , V_115 -> V_122 . V_123 ) ;
break;
case V_132 :
F_66 ( V_147 , V_148 , V_115 -> V_122 . V_23 ) ;
break;
case V_134 :
F_66 ( V_149 , V_150 , V_115 -> V_122 . V_123 ) ;
break;
case V_135 :
F_66 ( V_151 , V_152 , V_115 -> V_122 . V_123 ? 1 : 0 ) ;
break;
case V_136 :
F_66 ( V_151 , V_152 , V_115 -> V_122 . V_123 ? 0 : 1 ) ;
break;
default:
break;
}
}
#undef V_153
return 0 ;
}
int F_42 ( struct V_29 * V_30 , int * V_31 ,
char * V_66 , char * V_91 ,
struct V_63 * V_65 ,
struct V_29 * V_73 )
{
if ( V_73 ) {
struct V_32 V_33 ;
if ( F_65 ( & V_33 , V_73 , V_65 ,
F_64 ) )
return - V_10 ;
}
if ( strpbrk ( V_66 , L_18 ) )
return F_39 ( V_30 , V_31 , V_66 , V_91 ,
V_65 , V_73 ) ;
else
return F_38 ( V_30 , V_31 , V_66 , V_91 ,
V_65 , V_73 ) ;
}
int F_67 ( struct V_86 * V_88 ,
struct V_29 * V_30 ,
T_9 type , T_1 V_12 ,
struct V_29 * V_73 )
{
struct V_32 V_33 ;
F_33 ( V_36 ) ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . type = type ;
V_33 . V_12 = V_12 ;
if ( V_73 ) {
if ( F_65 ( & V_33 , V_73 , V_88 -> error ,
F_60 ) )
return - V_10 ;
if ( F_34 ( V_73 , & V_36 ) )
return - V_40 ;
}
return F_23 ( V_30 , & V_88 -> V_31 , & V_33 , NULL , & V_36 ) ;
}
static int F_68 ( struct V_114 * V_115 )
{
return V_115 -> V_119 == V_137 ;
}
static char * F_69 ( struct V_29 * T_5 )
{
struct V_114 * V_115 ;
F_46 (term, head_terms, list)
if ( F_68 ( V_115 ) )
return V_115 -> V_122 . V_23 ;
return NULL ;
}
int F_70 ( struct V_86 * V_88 ,
struct V_29 * V_30 , char * V_22 ,
struct V_29 * V_73 )
{
struct V_32 V_33 ;
struct V_154 V_155 ;
struct V_156 * V_157 ;
struct V_28 * V_37 ;
F_33 ( V_36 ) ;
V_157 = F_71 ( V_22 ) ;
if ( ! V_157 )
return - V_10 ;
if ( V_157 -> V_158 ) {
memcpy ( & V_33 , V_157 -> V_158 ,
sizeof( struct V_32 ) ) ;
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( ! V_73 ) {
V_33 . type = V_157 -> type ;
V_37 = F_17 ( V_30 , & V_88 -> V_31 , & V_33 , NULL , V_157 -> V_35 , NULL ) ;
return V_37 ? 0 : - V_40 ;
}
if ( F_72 ( V_157 , V_73 , & V_155 ) )
return - V_10 ;
if ( F_65 ( & V_33 , V_73 , V_88 -> error , F_63 ) )
return - V_10 ;
if ( F_34 ( V_73 , & V_36 ) )
return - V_40 ;
if ( F_73 ( V_157 , & V_33 , V_73 , V_88 -> error ) )
return - V_10 ;
V_37 = F_17 ( V_30 , & V_88 -> V_31 , & V_33 ,
F_69 ( V_73 ) , V_157 -> V_35 ,
& V_36 ) ;
if ( V_37 ) {
V_37 -> V_159 = V_155 . V_159 ;
V_37 -> V_160 = V_155 . V_160 ;
V_37 -> V_161 = V_155 . V_161 ;
V_37 -> V_162 = V_155 . V_162 ;
}
return V_37 ? 0 : - V_40 ;
}
int F_74 ( struct V_29 * V_30 ,
char * V_163 )
{
return F_75 ( V_30 , V_163 , true ) ;
}
void F_76 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_164 ;
if ( F_77 ( V_30 ) ) {
F_78 ( true , L_34 ) ;
return;
}
F_79 ( V_30 ) ;
V_164 = F_80 ( V_30 -> V_165 , struct V_28 , V_39 ) ;
V_164 -> V_166 = V_22 ? F_15 ( V_22 ) : NULL ;
}
void F_81 ( struct V_29 * V_167 ,
struct V_29 * V_168 )
{
F_82 ( V_167 , V_168 ) ;
free ( V_167 ) ;
}
static int F_83 ( struct V_169 * V_170 , char * V_23 ,
struct V_28 * V_37 )
{
int V_171 = V_37 ? V_37 -> V_33 . V_172 : 0 ;
int V_173 = V_37 ? V_37 -> V_33 . V_174 : 0 ;
int V_175 = V_37 ? V_37 -> V_33 . V_176 : 0 ;
int V_177 = V_37 ? V_37 -> V_33 . V_178 : 0 ;
int V_179 = V_37 ? V_37 -> V_33 . V_180 : 0 ;
int V_181 = V_37 ? V_37 -> V_33 . V_182 : 0 ;
int V_183 = V_37 ? V_37 -> V_33 . V_184 : 0 ;
int V_185 = 0 ;
int V_186 = 0 ;
int V_187 = V_37 ? V_37 -> V_33 . V_187 : 0 ;
int V_188 = V_171 | V_173 | V_175 ;
int V_189 = V_37 ? V_37 -> V_189 : 0 ;
memset ( V_170 , 0 , sizeof( * V_170 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_188 )
V_188 = V_171 = V_173 = V_175 = 1 ;
V_171 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_188 )
V_188 = V_171 = V_173 = V_175 = 1 ;
V_173 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_188 )
V_188 = V_171 = V_173 = V_175 = 1 ;
V_175 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_189 )
V_189 = V_179 = V_177 = 1 ;
V_179 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_189 )
V_189 = V_179 = V_177 = 1 ;
V_177 = 0 ;
} else if ( * V_23 == 'I' ) {
V_181 = 1 ;
} else if ( * V_23 == 'p' ) {
V_183 ++ ;
if ( ! V_189 )
V_179 = 1 ;
} else if ( * V_23 == 'P' ) {
V_185 = 1 ;
} else if ( * V_23 == 'S' ) {
V_186 = 1 ;
} else if ( * V_23 == 'D' ) {
V_187 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_183 > 3 )
return - V_10 ;
V_170 -> V_171 = V_171 ;
V_170 -> V_173 = V_173 ;
V_170 -> V_175 = V_175 ;
V_170 -> V_177 = V_177 ;
V_170 -> V_179 = V_179 ;
V_170 -> V_181 = V_181 ;
V_170 -> V_183 = V_183 ;
V_170 -> V_185 = V_185 ;
V_170 -> V_189 = V_189 ;
V_170 -> V_186 = V_186 ;
V_170 -> V_187 = V_187 ;
return 0 ;
}
static int F_84 ( char * V_23 )
{
char * V_190 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_35 ) - 1 ) )
return - 1 ;
while ( * V_190 ) {
if ( * V_190 != 'p' && strchr ( V_190 + 1 , * V_190 ) )
return - 1 ;
V_190 ++ ;
}
return 0 ;
}
int F_75 ( struct V_29 * V_30 , char * V_23 , bool V_191 )
{
struct V_28 * V_37 ;
struct V_169 V_170 ;
if ( V_23 == NULL )
return 0 ;
if ( F_84 ( V_23 ) )
return - V_10 ;
if ( ! V_191 && F_83 ( & V_170 , V_23 , NULL ) )
return - V_10 ;
F_85 (list, evsel) {
if ( V_191 && F_83 ( & V_170 , V_23 , V_37 ) )
return - V_10 ;
V_37 -> V_33 . V_172 = V_170 . V_171 ;
V_37 -> V_33 . V_174 = V_170 . V_173 ;
V_37 -> V_33 . V_176 = V_170 . V_175 ;
V_37 -> V_33 . V_184 = V_170 . V_183 ;
V_37 -> V_33 . V_178 = V_170 . V_177 ;
V_37 -> V_33 . V_180 = V_170 . V_179 ;
V_37 -> V_33 . V_182 = V_170 . V_181 ;
V_37 -> V_189 = V_170 . V_189 ;
V_37 -> V_186 = V_170 . V_186 ;
V_37 -> V_185 = V_170 . V_185 ;
if ( F_86 ( V_37 ) )
V_37 -> V_33 . V_187 = V_170 . V_187 ;
}
return 0 ;
}
int F_87 ( struct V_29 * V_30 , char * V_22 )
{
struct V_28 * V_37 ;
F_85 (list, evsel) {
if ( ! V_37 -> V_22 )
V_37 -> V_22 = F_15 ( V_22 ) ;
}
return 0 ;
}
static int
F_88 ( const void * V_192 , const void * V_193 )
{
struct V_194 * V_195 = (struct V_194 * ) V_192 ;
struct V_194 * V_196 = (struct V_194 * ) V_193 ;
return strcmp ( V_195 -> V_197 , V_196 -> V_197 ) ;
}
static void F_89 ( void )
{
if ( V_198 > 0 ) {
struct V_194 * V_190 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_198 ; V_44 ++ ) {
V_190 = V_199 + V_44 ;
free ( V_190 -> V_197 ) ;
}
free ( V_199 ) ;
V_199 = NULL ;
V_198 = 0 ;
}
}
static void F_90 ( void )
{
struct V_156 * V_157 = NULL ;
struct V_200 * V_201 ;
int V_108 = 0 ;
V_157 = F_71 ( L_36 ) ;
if ( ( V_157 == NULL ) || F_77 ( & V_157 -> V_202 ) ) {
V_198 = - 1 ;
return;
}
F_46 (alias, &pmu->aliases, list) {
if ( strchr ( V_201 -> V_22 , '-' ) )
V_108 ++ ;
V_108 ++ ;
}
V_199 = malloc ( sizeof( struct V_194 ) * V_108 ) ;
if ( ! V_199 )
return;
V_198 = V_108 ;
V_108 = 0 ;
F_46 (alias, &pmu->aliases, list) {
struct V_194 * V_190 = V_199 + V_108 ;
char * V_92 = strchr ( V_201 -> V_22 , '-' ) ;
if ( V_92 != NULL ) {
F_91 ( F_14 ( V_201 -> V_22 , V_92 - V_201 -> V_22 ) ,
V_203 ) ;
V_190 ++ ;
F_91 ( F_15 ( ++ V_92 ) , V_204 ) ;
V_108 += 2 ;
} else {
F_91 ( F_15 ( V_201 -> V_22 ) , V_205 ) ;
V_108 ++ ;
}
}
qsort ( V_199 , V_108 ,
sizeof( struct V_194 ) , F_88 ) ;
return;
V_65:
F_89 () ;
}
enum V_206
F_92 ( const char * V_22 )
{
struct V_194 V_190 , * V_207 ;
if ( V_198 == 0 )
F_90 () ;
if ( ( V_198 <= 0 ) || ! strcmp ( V_22 , L_36 ) )
return V_208 ;
V_190 . V_197 = F_15 ( V_22 ) ;
V_207 = bsearch ( & V_190 , V_199 ,
( V_209 ) V_198 ,
sizeof( struct V_194 ) , F_88 ) ;
free ( V_190 . V_197 ) ;
return V_207 ? V_207 -> type : V_208 ;
}
static int F_93 ( const char * V_23 , void * V_88 , int V_210 )
{
T_10 V_211 ;
void * V_212 ;
int V_75 ;
V_75 = F_94 ( V_210 , & V_212 ) ;
if ( V_75 )
return V_75 ;
V_211 = F_95 ( V_23 , V_212 ) ;
#ifdef F_96
V_213 = 1 ;
#endif
V_75 = F_97 ( V_88 , V_212 ) ;
F_98 ( V_211 , V_212 ) ;
F_99 ( V_211 , V_212 ) ;
F_100 ( V_212 ) ;
return V_75 ;
}
int F_101 ( struct V_29 * V_214 , const char * V_23 )
{
struct F_101 V_88 = {
. V_214 = NULL ,
} ;
int V_75 ;
V_75 = F_93 ( V_23 , & V_88 , V_215 ) ;
if ( ! V_75 ) {
F_21 ( V_88 . V_214 , V_214 ) ;
F_12 ( & V_88 . V_214 ) ;
return 0 ;
}
if ( V_88 . V_214 )
F_102 ( V_88 . V_214 ) ;
return V_75 ;
}
int F_103 ( struct V_216 * V_87 , const char * V_23 ,
struct V_63 * V_65 )
{
struct V_86 V_88 = {
. V_30 = F_104 ( V_88 . V_30 ) ,
. V_31 = V_87 -> V_217 ,
. error = V_65 ,
} ;
int V_75 ;
V_75 = F_93 ( V_23 , & V_88 , V_218 ) ;
F_89 () ;
if ( ! V_75 ) {
struct V_28 * V_219 ;
if ( F_77 ( & V_88 . V_30 ) ) {
F_78 ( true , L_37 ) ;
return - 1 ;
}
F_105 ( V_87 , & V_88 . V_30 ) ;
V_87 -> V_220 += V_88 . V_220 ;
V_219 = F_106 ( V_87 ) ;
V_219 -> V_221 = true ;
return 0 ;
}
return V_75 ;
}
static int F_107 ( void )
{
struct V_222 V_223 ;
F_108 ( & V_223 ) ;
return V_223 . V_224 > V_225 ? V_225 : V_223 . V_224 ;
}
static void F_109 ( struct V_63 * V_65 ,
const char * V_91 )
{
const char * V_23 = L_38 ;
char V_226 [ V_225 ] ;
char * V_227 = ( char * ) V_91 ;
int V_31 = 0 ;
if ( V_65 -> V_23 ) {
int V_228 = F_107 () - 2 ;
int V_229 = strlen ( V_91 ) ;
int V_230 , V_231 , V_232 = 0 ;
int V_233 = 13 ;
V_23 = L_39 ;
V_230 = strlen ( V_23 ) ;
V_231 = V_228 - V_230 ;
V_227 = V_226 ;
if ( V_65 -> V_31 > V_233 )
V_232 = V_65 -> V_31 - V_233 ;
strncpy ( V_227 , V_91 + V_232 , V_231 ) ;
if ( V_232 )
V_227 [ 0 ] = V_227 [ 1 ] = '.' ;
if ( ( V_229 - V_232 ) > V_231 ) {
V_227 [ V_231 - 1 ] = V_227 [ V_231 - 2 ] = '.' ;
V_227 [ V_231 ] = 0 ;
}
V_31 = V_230 + V_65 -> V_31 - V_232 ;
}
fprintf ( V_234 , L_40 , V_23 , V_227 ) ;
if ( V_31 ) {
fprintf ( V_234 , L_41 , V_31 + 1 , L_42 , V_65 -> V_23 ) ;
if ( V_65 -> V_67 )
fprintf ( V_234 , L_43 , V_65 -> V_67 ) ;
free ( V_65 -> V_23 ) ;
free ( V_65 -> V_67 ) ;
}
fprintf ( V_234 , L_44 ) ;
}
int F_110 ( const struct V_235 * V_236 , const char * V_23 ,
int T_11 V_142 )
{
struct V_216 * V_87 = * (struct V_216 * * ) V_236 -> V_237 ;
struct V_63 V_65 = { . V_31 = 0 , } ;
int V_75 = F_103 ( V_87 , V_23 , & V_65 ) ;
if ( V_75 )
F_109 ( & V_65 , V_23 ) ;
return V_75 ;
}
static int
F_111 ( struct V_216 * V_87 ,
int (* F_112)( struct V_28 * V_37 ,
const void * V_238 ) ,
const void * V_238 )
{
struct V_28 * V_219 = NULL ;
int V_65 ;
if ( V_87 -> V_217 > 0 )
V_219 = F_106 ( V_87 ) ;
do {
V_65 = (* F_112)( V_219 , V_238 ) ;
if ( V_65 )
return - 1 ;
if ( ! V_219 )
return 0 ;
if ( V_219 -> V_39 . V_239 == & V_87 -> V_240 )
return 0 ;
V_219 = F_80 ( V_219 -> V_39 . V_239 , struct V_28 , V_39 ) ;
} while ( ! V_219 -> V_221 );
return 0 ;
}
static int F_113 ( struct V_28 * V_37 , const void * V_238 )
{
const char * V_23 = V_238 ;
if ( V_37 == NULL || V_37 -> V_33 . type != V_26 ) {
fprintf ( V_234 ,
L_45 ) ;
return - 1 ;
}
if ( F_114 ( V_37 , L_46 , V_23 ) < 0 ) {
fprintf ( V_234 ,
L_47 ) ;
return - 1 ;
}
return 0 ;
}
int F_115 ( const struct V_235 * V_236 , const char * V_23 ,
int T_11 V_142 )
{
struct V_216 * V_87 = * (struct V_216 * * ) V_236 -> V_237 ;
return F_111 ( V_87 , F_113 ,
( const void * ) V_23 ) ;
}
static int F_116 ( struct V_28 * V_37 ,
const void * V_238 V_142 )
{
char V_241 [ 64 ] ;
if ( V_37 == NULL || V_37 -> V_33 . type != V_26 ) {
fprintf ( V_234 ,
L_48 ) ;
return - 1 ;
}
snprintf ( V_241 , sizeof( V_241 ) , L_49 , F_117 () ) ;
if ( F_114 ( V_37 , L_46 , V_241 ) < 0 ) {
fprintf ( V_234 ,
L_47 ) ;
return - 1 ;
}
return 0 ;
}
int F_118 ( const struct V_235 * V_236 ,
const char * V_238 V_142 ,
int T_11 V_142 )
{
struct V_216 * V_87 = * (struct V_216 * * ) V_236 -> V_237 ;
return F_111 ( V_87 , F_116 ,
NULL ) ;
}
static int F_119 ( const void * V_242 , const void * V_243 )
{
const char * const * V_244 = V_242 ;
const char * const * V_245 = V_243 ;
return strcmp ( * V_244 , * V_245 ) ;
}
void F_120 ( const char * V_246 , const char * V_247 ,
bool V_248 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char * * V_249 = NULL ;
unsigned int V_250 = 0 , V_251 = 0 ;
bool V_252 = false ;
V_253:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_252 ) {
V_249 = F_11 ( sizeof( char * ) * V_251 ) ;
if ( ! V_249 )
goto V_254;
}
F_6 (sys_dir, sys_dirent, sys_next) {
if ( V_246 != NULL &&
! F_37 ( V_16 . V_8 , V_246 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_247 != NULL &&
! F_37 ( V_17 . V_8 , V_247 ) )
continue;
if ( ! V_252 ) {
V_251 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_50 ,
V_16 . V_8 , V_17 . V_8 ) ;
V_249 [ V_250 ] = F_15 ( V_4 ) ;
if ( V_249 [ V_250 ] == NULL )
goto V_255;
V_250 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_252 ) {
V_252 = true ;
goto V_253;
}
qsort ( V_249 , V_251 , sizeof( char * ) , F_119 ) ;
V_250 = 0 ;
while ( V_250 < V_251 ) {
if ( V_248 ) {
printf ( L_51 , V_249 [ V_250 ++ ] ) ;
continue;
}
printf ( L_52 , V_249 [ V_250 ++ ] ,
V_256 [ V_26 ] ) ;
}
if ( V_251 && F_121 () )
printf ( L_53 ) ;
V_257:
V_251 = V_250 ;
for ( V_250 = 0 ; V_250 < V_251 ; V_250 ++ )
F_12 ( & V_249 [ V_250 ] ) ;
F_12 ( & V_249 ) ;
return;
V_255:
F_10 ( V_3 ) ;
V_254:
F_10 ( V_2 ) ;
printf ( L_54 ,
V_256 [ V_26 ] ) ;
if ( V_249 )
goto V_257;
}
int F_122 ( const char * V_258 )
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
snprintf ( V_4 , V_5 , L_50 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_258 ) ) {
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
static bool F_123 ( T_12 type , unsigned V_12 )
{
bool V_75 = true ;
int V_259 ;
struct V_28 * V_37 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_260 = 1 ,
} ;
struct {
struct V_261 V_262 ;
int V_263 [ 1 ] ;
} V_264 = {
. V_262 . V_265 = 1 ,
. V_263 = { 0 } ,
} ;
V_37 = F_124 ( & V_33 ) ;
if ( V_37 ) {
V_259 = F_125 ( V_37 , NULL , & V_264 . V_262 ) ;
V_75 = V_259 >= 0 ;
if ( V_259 == - V_69 ) {
V_37 -> V_33 . V_174 = 1 ;
V_75 = F_125 ( V_37 , NULL , & V_264 . V_262 ) >= 0 ;
}
F_45 ( V_37 ) ;
}
return V_75 ;
}
int F_126 ( const char * V_247 , bool V_248 )
{
unsigned int type , V_266 , V_44 , V_250 = 0 , V_251 = 0 ;
char V_22 [ 64 ] ;
char * * V_249 = NULL ;
bool V_252 = false ;
V_253:
if ( V_252 ) {
V_249 = F_11 ( sizeof( char * ) * V_251 ) ;
if ( ! V_249 )
goto V_267;
}
for ( type = 0 ; type < V_56 ; type ++ ) {
for ( V_266 = 0 ; V_266 < V_58 ; V_266 ++ ) {
if ( ! F_26 ( type , V_266 ) )
continue;
for ( V_44 = 0 ; V_44 < V_60 ; V_44 ++ ) {
F_127 ( type , V_266 , V_44 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_247 != NULL && ! F_37 ( V_22 , V_247 ) )
continue;
if ( ! F_123 ( V_27 ,
type | ( V_266 << 8 ) | ( V_44 << 16 ) ) )
continue;
if ( ! V_252 ) {
V_251 ++ ;
continue;
}
V_249 [ V_250 ] = F_15 ( V_22 ) ;
if ( V_249 [ V_250 ] == NULL )
goto V_267;
V_250 ++ ;
}
}
}
if ( ! V_252 ) {
V_252 = true ;
goto V_253;
}
qsort ( V_249 , V_251 , sizeof( char * ) , F_119 ) ;
V_250 = 0 ;
while ( V_250 < V_251 ) {
if ( V_248 ) {
printf ( L_51 , V_249 [ V_250 ++ ] ) ;
continue;
}
printf ( L_52 , V_249 [ V_250 ++ ] ,
V_256 [ V_27 ] ) ;
}
if ( V_251 && F_121 () )
printf ( L_53 ) ;
V_257:
V_251 = V_250 ;
for ( V_250 = 0 ; V_250 < V_251 ; V_250 ++ )
F_12 ( & V_249 [ V_250 ] ) ;
F_12 ( & V_249 ) ;
return V_251 ;
V_267:
printf ( L_54 , V_256 [ V_27 ] ) ;
if ( V_249 )
goto V_257;
return V_251 ;
}
void F_128 ( const char * V_247 , unsigned type ,
struct V_268 * V_269 , unsigned V_270 ,
bool V_248 )
{
unsigned int V_44 , V_250 = 0 , V_251 = 0 ;
char V_22 [ V_50 ] ;
char * * V_249 = NULL ;
bool V_252 = false ;
V_253:
if ( V_252 ) {
V_249 = F_11 ( sizeof( char * ) * V_251 ) ;
if ( ! V_249 )
goto V_267;
V_269 -= V_270 ;
}
for ( V_44 = 0 ; V_44 < V_270 ; V_44 ++ , V_269 ++ ) {
if ( V_247 != NULL && V_269 -> V_197 != NULL &&
! ( F_37 ( V_269 -> V_197 , V_247 ) ||
( V_269 -> V_201 && F_37 ( V_269 -> V_201 , V_247 ) ) ) )
continue;
if ( ! F_123 ( type , V_44 ) )
continue;
if ( ! V_252 ) {
V_251 ++ ;
continue;
}
if ( ! V_248 && strlen ( V_269 -> V_201 ) )
snprintf ( V_22 , V_50 , L_55 , V_269 -> V_197 , V_269 -> V_201 ) ;
else
strncpy ( V_22 , V_269 -> V_197 , V_50 ) ;
V_249 [ V_250 ] = F_15 ( V_22 ) ;
if ( V_249 [ V_250 ] == NULL )
goto V_267;
V_250 ++ ;
}
if ( ! V_252 ) {
V_252 = true ;
goto V_253;
}
qsort ( V_249 , V_251 , sizeof( char * ) , F_119 ) ;
V_250 = 0 ;
while ( V_250 < V_251 ) {
if ( V_248 ) {
printf ( L_51 , V_249 [ V_250 ++ ] ) ;
continue;
}
printf ( L_52 , V_249 [ V_250 ++ ] , V_256 [ type ] ) ;
}
if ( V_251 && F_121 () )
printf ( L_53 ) ;
V_257:
V_251 = V_250 ;
for ( V_250 = 0 ; V_250 < V_251 ; V_250 ++ )
F_12 ( & V_249 [ V_250 ] ) ;
F_12 ( & V_249 ) ;
return;
V_267:
printf ( L_54 , V_256 [ type ] ) ;
if ( V_249 )
goto V_257;
}
void F_129 ( const char * V_247 , bool V_248 )
{
F_128 ( V_247 , V_24 ,
V_271 , V_272 , V_248 ) ;
F_128 ( V_247 , V_25 ,
V_273 , V_274 , V_248 ) ;
F_126 ( V_247 , V_248 ) ;
F_130 ( V_247 , V_248 ) ;
if ( V_247 != NULL )
return;
if ( ! V_248 ) {
printf ( L_52 ,
L_56 ,
V_256 [ V_275 ] ) ;
printf ( L_52 ,
L_57 ,
V_256 [ V_275 ] ) ;
if ( F_121 () )
printf ( L_58 ) ;
printf ( L_52 ,
L_59 ,
V_256 [ V_112 ] ) ;
if ( F_121 () )
printf ( L_53 ) ;
}
F_120 ( NULL , NULL , V_248 ) ;
}
int F_131 ( struct V_114 * V_115 )
{
return V_115 -> V_119 != V_139 ;
}
static int F_132 ( struct V_114 * * V_276 , int V_116 ,
int V_119 , char * V_12 ,
char * V_23 , T_1 V_123 , int V_138 , int V_117 )
{
struct V_114 * V_115 ;
V_115 = F_11 ( sizeof( * V_115 ) ) ;
if ( ! V_115 )
return - V_40 ;
F_133 ( & V_115 -> V_30 ) ;
V_115 -> V_116 = V_116 ;
V_115 -> V_119 = V_119 ;
V_115 -> V_12 = V_12 ;
V_115 -> V_138 = V_138 ;
V_115 -> V_117 = V_117 ;
switch ( V_116 ) {
case V_118 :
V_115 -> V_122 . V_123 = V_123 ;
break;
case V_277 :
V_115 -> V_122 . V_23 = V_23 ;
break;
default:
free ( V_115 ) ;
return - V_10 ;
}
* V_276 = V_115 ;
return 0 ;
}
int F_134 ( struct V_114 * * V_115 ,
int V_119 , char * V_12 , T_1 V_123 ,
void * V_278 , void * V_279 )
{
T_13 * V_280 = V_278 ;
T_13 * V_281 = V_279 ;
return F_132 ( V_115 , V_118 , V_119 ,
V_12 , NULL , V_123 ,
V_280 ? V_280 -> V_282 : 0 ,
V_281 ? V_281 -> V_282 : 0 ) ;
}
int F_135 ( struct V_114 * * V_115 ,
int V_119 , char * V_12 , char * V_23 ,
void * V_278 , void * V_279 )
{
T_13 * V_280 = V_278 ;
T_13 * V_281 = V_279 ;
return F_132 ( V_115 , V_277 , V_119 ,
V_12 , V_23 , 0 ,
V_280 ? V_280 -> V_282 : 0 ,
V_281 ? V_281 -> V_282 : 0 ) ;
}
int F_136 ( struct V_114 * * V_115 ,
char * V_12 , unsigned V_31 )
{
struct V_268 * V_283 ;
F_137 ( V_31 >= V_272 ) ;
V_283 = & V_271 [ V_31 ] ;
if ( V_12 )
return F_132 ( V_115 , V_277 ,
V_139 , V_12 ,
( char * ) V_283 -> V_197 , 0 , 0 , 0 ) ;
else
return F_132 ( V_115 , V_277 ,
V_139 ,
( char * ) L_60 , ( char * ) V_283 -> V_197 ,
0 , 0 , 0 ) ;
}
int F_138 ( struct V_114 * * V_284 ,
struct V_114 * V_115 )
{
return F_132 ( V_284 , V_115 -> V_116 , V_115 -> V_119 , V_115 -> V_12 ,
V_115 -> V_122 . V_23 , V_115 -> V_122 . V_123 ,
V_115 -> V_138 , V_115 -> V_117 ) ;
}
void F_102 ( struct V_29 * V_214 )
{
struct V_114 * V_115 , * V_285 ;
F_43 (term, h, terms, list)
free ( V_115 ) ;
}
void F_139 ( struct V_86 * V_88 ,
int V_31 , const char * V_23 )
{
struct V_63 * V_65 = V_88 -> error ;
if ( ! V_65 )
return;
V_65 -> V_31 = V_31 ;
V_65 -> V_23 = F_15 ( V_23 ) ;
F_78 ( ! V_65 -> V_23 , L_61 ) ;
}
char * F_62 ( char * V_286 )
{
char * V_23 ;
static const char * V_287 = L_62
L_63
L_64 ;
if ( V_286 ) {
if ( ! F_140 ( & V_23 , L_65 ,
V_286 , V_287 ) )
goto V_288;
} else {
if ( ! F_140 ( & V_23 , L_66 , V_287 ) )
goto V_288;
}
return V_23 ;
V_288:
return NULL ;
}
