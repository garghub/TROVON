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
if ( V_35 )
V_36 -> V_35 = F_20 ( V_35 ) ;
if ( V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
F_21 ( & V_36 -> V_37 , V_30 ) ;
return V_36 ;
}
static int F_22 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 , char * V_22 )
{
return F_17 ( V_30 , V_31 , V_33 , V_22 , NULL ) ? 0 : - V_38 ;
}
static int F_23 ( char * V_23 , const char * V_39 [] [ V_40 ] , int V_41 )
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
int F_24 ( struct V_29 * V_30 , int * V_31 ,
char * type , char * V_46 , char * V_47 )
{
struct V_32 V_33 ;
char V_22 [ V_48 ] ;
int V_49 = - 1 , V_50 = - 1 , V_51 = - 1 ;
char * V_52 [ 2 ] = { V_46 , V_47 } ;
int V_42 , V_44 ;
V_49 = F_23 ( type , V_53 ,
V_54 ) ;
if ( V_49 == - 1 )
return - V_10 ;
V_44 = snprintf ( V_22 , V_48 , L_9 , type ) ;
for ( V_42 = 0 ; ( V_42 < 2 ) && ( V_52 [ V_42 ] ) ; V_42 ++ ) {
char * V_23 = V_52 [ V_42 ] ;
V_44 += snprintf ( V_22 + V_44 , V_48 - V_44 , L_10 , V_23 ) ;
if ( V_50 == - 1 ) {
V_50 = F_23 ( V_23 , V_55 ,
V_56 ) ;
if ( V_50 >= 0 ) {
if ( ! F_25 ( V_49 , V_50 ) )
return - V_10 ;
continue;
}
}
if ( V_51 == - 1 ) {
V_51 = F_23 ( V_23 , V_57 ,
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
return F_22 ( V_30 , V_31 , & V_33 , V_22 ) ;
}
static int F_26 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
struct V_28 * V_36 ;
V_36 = F_27 ( V_61 , V_62 , ( * V_31 ) ++ ) ;
if ( ! V_36 )
return - V_38 ;
F_21 ( & V_36 -> V_37 , V_30 ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_30 , int * V_31 ,
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
while ( ! V_64 && ( V_63 = F_29 ( V_3 ) ) ) {
if ( ! strcmp ( V_63 -> V_8 , L_12 )
|| ! strcmp ( V_63 -> V_8 , L_13 )
|| ! strcmp ( V_63 -> V_8 , L_14 )
|| ! strcmp ( V_63 -> V_8 , L_15 ) )
continue;
if ( ! F_30 ( V_63 -> V_8 , V_62 ) )
continue;
V_64 = F_26 ( V_30 , V_31 , V_61 , V_63 -> V_8 ) ;
}
F_10 ( V_3 ) ;
return V_64 ;
}
static int F_31 ( struct V_29 * V_30 , int * V_31 ,
char * V_61 , char * V_62 )
{
return strpbrk ( V_62 , L_16 ) ?
F_28 ( V_30 , V_31 , V_61 , V_62 ) :
F_26 ( V_30 , V_31 , V_61 , V_62 ) ;
}
static int F_32 ( struct V_29 * V_30 , int * V_31 ,
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
while ( ! V_64 && ( V_65 = F_29 ( V_66 ) ) ) {
if ( ! strcmp ( V_65 -> V_8 , L_12 )
|| ! strcmp ( V_65 -> V_8 , L_13 )
|| ! strcmp ( V_65 -> V_8 , L_14 )
|| ! strcmp ( V_65 -> V_8 , L_17 )
|| ! strcmp ( V_65 -> V_8 , L_18 ) )
continue;
if ( ! F_30 ( V_65 -> V_8 , V_61 ) )
continue;
V_64 = F_31 ( V_30 , V_31 , V_65 -> V_8 ,
V_62 ) ;
}
F_10 ( V_66 ) ;
return V_64 ;
}
int F_33 ( struct V_29 * V_30 , int * V_31 ,
char * V_67 , char * V_68 )
{
if ( strpbrk ( V_67 , L_16 ) )
return F_32 ( V_30 , V_31 , V_67 , V_68 ) ;
else
return F_31 ( V_30 , V_31 , V_67 , V_68 ) ;
}
static int
F_34 ( const char * type , struct V_32 * V_33 )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
if ( ! type || ! type [ V_42 ] )
break;
#define F_35 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_42 ] ) {
case 'r' :
F_35 ( V_69 ) ;
break;
case 'w' :
F_35 ( V_70 ) ;
break;
case 'x' :
F_35 ( V_71 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_35
if ( ! V_33 -> V_72 )
V_33 -> V_72 = V_69 | V_70 ;
return 0 ;
}
int F_36 ( struct V_29 * V_30 , int * V_31 ,
void * V_73 , char * type , T_1 V_74 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_75 = ( unsigned long ) V_73 ;
if ( F_34 ( type , & V_33 ) )
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
return F_22 ( V_30 , V_31 , & V_33 , NULL ) ;
}
static int F_37 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
int type )
{
if ( type == V_81 -> V_84 )
return 0 ;
if ( V_83 ) {
V_83 -> V_31 = V_81 -> V_85 ;
if ( type == V_86 )
V_83 -> V_23 = F_15 ( L_19 ) ;
else
V_83 -> V_23 = F_15 ( L_20 ) ;
}
return - V_10 ;
}
static int F_38 ( struct V_32 * V_33 ,
struct V_80 * V_81 ,
struct V_82 * V_83 )
{
#define F_39 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_81 -> V_87 ) {
case V_88 :
return 0 ;
case V_89 :
F_39 ( V_90 ) ;
V_33 -> V_12 = V_81 -> V_91 . V_92 ;
break;
case V_93 :
F_39 ( V_90 ) ;
V_33 -> V_94 = V_81 -> V_91 . V_92 ;
break;
case V_95 :
F_39 ( V_90 ) ;
V_33 -> V_96 = V_81 -> V_91 . V_92 ;
break;
case V_97 :
F_39 ( V_90 ) ;
V_33 -> V_79 = V_81 -> V_91 . V_92 ;
break;
case V_98 :
break;
case V_99 :
F_39 ( V_100 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_39
}
static int F_40 ( struct V_32 * V_33 ,
struct V_29 * V_101 ,
struct V_82 * V_83 )
{
struct V_80 * V_81 ;
F_41 (term, head, list)
if ( F_38 ( V_33 , V_81 , V_83 ) )
return - V_10 ;
return 0 ;
}
int F_42 ( struct V_102 * V_103 ,
struct V_29 * V_30 ,
T_4 type , T_1 V_12 ,
struct V_29 * V_104 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . type = type ;
V_33 . V_12 = V_12 ;
if ( V_104 &&
F_40 ( & V_33 , V_104 , V_103 -> error ) )
return - V_10 ;
return F_22 ( V_30 , & V_103 -> V_31 , & V_33 , NULL ) ;
}
static int F_43 ( struct V_80 * V_81 )
{
return V_81 -> V_87 == V_99 ;
}
static char * F_44 ( struct V_29 * V_105 )
{
struct V_80 * V_81 ;
F_41 (term, head_terms, list)
if ( F_43 ( V_81 ) )
return V_81 -> V_91 . V_23 ;
return NULL ;
}
int F_45 ( struct V_102 * V_103 ,
struct V_29 * V_30 , char * V_22 ,
struct V_29 * V_104 )
{
struct V_32 V_33 ;
struct V_106 V_107 ;
struct V_108 * V_109 ;
struct V_28 * V_36 ;
V_109 = F_46 ( V_22 ) ;
if ( ! V_109 )
return - V_10 ;
if ( V_109 -> V_110 ) {
memcpy ( & V_33 , V_109 -> V_110 ,
sizeof( struct V_32 ) ) ;
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( ! V_104 ) {
V_33 . type = V_109 -> type ;
V_36 = F_17 ( V_30 , & V_103 -> V_31 , & V_33 , NULL , V_109 -> V_35 ) ;
return V_36 ? 0 : - V_38 ;
}
if ( F_47 ( V_109 , V_104 , & V_107 ) )
return - V_10 ;
if ( F_40 ( & V_33 , V_104 , V_103 -> error ) )
return - V_10 ;
if ( F_48 ( V_109 , & V_33 , V_104 , V_103 -> error ) )
return - V_10 ;
V_36 = F_17 ( V_30 , & V_103 -> V_31 , & V_33 ,
F_44 ( V_104 ) , V_109 -> V_35 ) ;
if ( V_36 ) {
V_36 -> V_111 = V_107 . V_111 ;
V_36 -> V_112 = V_107 . V_112 ;
V_36 -> V_113 = V_107 . V_113 ;
V_36 -> V_114 = V_107 . V_114 ;
}
return V_36 ? 0 : - V_38 ;
}
int F_49 ( struct V_29 * V_30 ,
char * V_115 )
{
return F_50 ( V_30 , V_115 , true ) ;
}
void F_51 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_116 ;
F_52 ( V_30 ) ;
V_116 = F_53 ( V_30 -> V_117 , struct V_28 , V_37 ) ;
V_116 -> V_118 = V_22 ? F_15 ( V_22 ) : NULL ;
}
void F_54 ( struct V_29 * V_119 ,
struct V_29 * V_120 )
{
F_55 ( V_119 , V_120 ) ;
free ( V_119 ) ;
}
static int F_56 ( struct V_121 * V_122 , char * V_23 ,
struct V_28 * V_36 )
{
int V_123 = V_36 ? V_36 -> V_33 . V_124 : 0 ;
int V_125 = V_36 ? V_36 -> V_33 . V_126 : 0 ;
int V_127 = V_36 ? V_36 -> V_33 . V_128 : 0 ;
int V_129 = V_36 ? V_36 -> V_33 . V_130 : 0 ;
int V_131 = V_36 ? V_36 -> V_33 . V_132 : 0 ;
int V_133 = V_36 ? V_36 -> V_33 . V_134 : 0 ;
int V_135 = V_36 ? V_36 -> V_33 . V_136 : 0 ;
int V_137 = 0 ;
int V_138 = V_36 ? V_36 -> V_33 . V_138 : 0 ;
int V_139 = V_123 | V_125 | V_127 ;
int V_140 = V_36 ? V_36 -> V_140 : 0 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_139 )
V_139 = V_123 = V_125 = V_127 = 1 ;
V_123 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_139 )
V_139 = V_123 = V_125 = V_127 = 1 ;
V_125 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_139 )
V_139 = V_123 = V_125 = V_127 = 1 ;
V_127 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_140 )
V_140 = V_131 = V_129 = 1 ;
V_131 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_140 )
V_140 = V_131 = V_129 = 1 ;
V_129 = 0 ;
} else if ( * V_23 == 'I' ) {
V_133 = 1 ;
} else if ( * V_23 == 'p' ) {
V_135 ++ ;
if ( ! V_140 )
V_131 = 1 ;
} else if ( * V_23 == 'S' ) {
V_137 = 1 ;
} else if ( * V_23 == 'D' ) {
V_138 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_135 > 3 )
return - V_10 ;
V_122 -> V_123 = V_123 ;
V_122 -> V_125 = V_125 ;
V_122 -> V_127 = V_127 ;
V_122 -> V_129 = V_129 ;
V_122 -> V_131 = V_131 ;
V_122 -> V_133 = V_133 ;
V_122 -> V_135 = V_135 ;
V_122 -> V_140 = V_140 ;
V_122 -> V_137 = V_137 ;
V_122 -> V_138 = V_138 ;
return 0 ;
}
static int F_57 ( char * V_23 )
{
char * V_141 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_21 ) - 1 ) )
return - 1 ;
while ( * V_141 ) {
if ( * V_141 != 'p' && strchr ( V_141 + 1 , * V_141 ) )
return - 1 ;
V_141 ++ ;
}
return 0 ;
}
int F_50 ( struct V_29 * V_30 , char * V_23 , bool V_142 )
{
struct V_28 * V_36 ;
struct V_121 V_122 ;
if ( V_23 == NULL )
return 0 ;
if ( F_57 ( V_23 ) )
return - V_10 ;
if ( ! V_142 && F_56 ( & V_122 , V_23 , NULL ) )
return - V_10 ;
F_58 (list, evsel) {
if ( V_142 && F_56 ( & V_122 , V_23 , V_36 ) )
return - V_10 ;
V_36 -> V_33 . V_124 = V_122 . V_123 ;
V_36 -> V_33 . V_126 = V_122 . V_125 ;
V_36 -> V_33 . V_128 = V_122 . V_127 ;
V_36 -> V_33 . V_136 = V_122 . V_135 ;
V_36 -> V_33 . V_130 = V_122 . V_129 ;
V_36 -> V_33 . V_132 = V_122 . V_131 ;
V_36 -> V_33 . V_134 = V_122 . V_133 ;
V_36 -> V_140 = V_122 . V_140 ;
V_36 -> V_137 = V_122 . V_137 ;
if ( F_59 ( V_36 ) )
V_36 -> V_33 . V_138 = V_122 . V_138 ;
}
return 0 ;
}
int F_60 ( struct V_29 * V_30 , char * V_22 )
{
struct V_28 * V_36 ;
F_58 (list, evsel) {
if ( ! V_36 -> V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
}
return 0 ;
}
static int
F_61 ( const void * V_143 , const void * V_144 )
{
struct V_145 * V_146 = (struct V_145 * ) V_143 ;
struct V_145 * V_147 = (struct V_145 * ) V_144 ;
return strcmp ( V_146 -> V_148 , V_147 -> V_148 ) ;
}
static void F_62 ( void )
{
if ( V_149 > 0 ) {
struct V_145 * V_141 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_149 ; V_42 ++ ) {
V_141 = V_150 + V_42 ;
free ( V_141 -> V_148 ) ;
}
free ( V_150 ) ;
V_150 = NULL ;
V_149 = 0 ;
}
}
static void F_63 ( void )
{
struct V_108 * V_109 = NULL ;
struct V_151 * V_152 ;
int V_74 = 0 ;
V_109 = F_46 ( L_22 ) ;
if ( ( V_109 == NULL ) || F_64 ( & V_109 -> V_153 ) ) {
V_149 = - 1 ;
return;
}
F_41 (alias, &pmu->aliases, list) {
if ( strchr ( V_152 -> V_22 , '-' ) )
V_74 ++ ;
V_74 ++ ;
}
V_150 = malloc ( sizeof( struct V_145 ) * V_74 ) ;
if ( ! V_150 )
return;
V_149 = V_74 ;
V_74 = 0 ;
F_41 (alias, &pmu->aliases, list) {
struct V_145 * V_141 = V_150 + V_74 ;
char * V_154 = strchr ( V_152 -> V_22 , '-' ) ;
if ( V_154 != NULL ) {
F_65 ( F_14 ( V_152 -> V_22 , V_154 - V_152 -> V_22 ) ,
V_155 ) ;
V_141 ++ ;
F_65 ( F_15 ( ++ V_154 ) , V_156 ) ;
V_74 += 2 ;
} else {
F_65 ( F_15 ( V_152 -> V_22 ) , V_157 ) ;
V_74 ++ ;
}
}
qsort ( V_150 , V_74 ,
sizeof( struct V_145 ) , F_61 ) ;
return;
V_83:
F_62 () ;
}
enum V_158
F_66 ( const char * V_22 )
{
struct V_145 V_141 , * V_159 ;
if ( V_149 == 0 )
F_63 () ;
if ( ( V_149 <= 0 ) || ! strcmp ( V_22 , L_22 ) )
return V_160 ;
V_141 . V_148 = F_15 ( V_22 ) ;
V_159 = bsearch ( & V_141 , V_150 ,
( V_161 ) V_149 ,
sizeof( struct V_145 ) , F_61 ) ;
free ( V_141 . V_148 ) ;
return V_159 ? V_159 -> type : V_160 ;
}
static int F_67 ( const char * V_23 , void * V_103 , int V_162 )
{
T_5 V_163 ;
void * V_164 ;
int V_64 ;
V_64 = F_68 ( V_162 , & V_164 ) ;
if ( V_64 )
return V_64 ;
V_163 = F_69 ( V_23 , V_164 ) ;
#ifdef F_70
V_165 = 1 ;
#endif
V_64 = F_71 ( V_103 , V_164 ) ;
F_72 ( V_163 , V_164 ) ;
F_73 ( V_163 , V_164 ) ;
F_74 ( V_164 ) ;
return V_64 ;
}
int F_75 ( struct V_29 * V_166 , const char * V_23 )
{
struct F_75 V_103 = {
. V_166 = NULL ,
} ;
int V_64 ;
V_64 = F_67 ( V_23 , & V_103 , V_167 ) ;
if ( ! V_64 ) {
F_76 ( V_103 . V_166 , V_166 ) ;
F_12 ( & V_103 . V_166 ) ;
return 0 ;
}
if ( V_103 . V_166 )
F_77 ( V_103 . V_166 ) ;
return V_64 ;
}
int F_78 ( struct V_168 * V_169 , const char * V_23 ,
struct V_82 * V_83 )
{
struct V_102 V_103 = {
. V_30 = F_79 ( V_103 . V_30 ) ,
. V_31 = V_169 -> V_170 ,
. error = V_83 ,
} ;
int V_64 ;
V_64 = F_67 ( V_23 , & V_103 , V_171 ) ;
F_62 () ;
if ( ! V_64 ) {
int V_172 = V_103 . V_31 - V_169 -> V_170 ;
F_80 ( V_169 , & V_103 . V_30 , V_172 ) ;
V_169 -> V_173 += V_103 . V_173 ;
return 0 ;
}
return V_64 ;
}
static int F_81 ( void )
{
struct V_174 V_175 ;
F_82 ( & V_175 ) ;
return V_175 . V_176 > V_177 ? V_177 : V_175 . V_176 ;
}
static void F_83 ( struct V_82 * V_83 ,
const char * V_68 )
{
const char * V_23 = L_23 ;
char V_178 [ V_177 ] ;
char * V_179 = ( char * ) V_68 ;
int V_31 = 0 ;
if ( V_83 -> V_23 ) {
int V_180 = F_81 () - 2 ;
int V_181 = strlen ( V_68 ) ;
int V_182 , V_183 , V_184 = 0 ;
int V_185 = 10 ;
V_23 = L_24 ;
V_182 = strlen ( V_23 ) ;
V_183 = V_180 - V_182 ;
V_179 = V_178 ;
if ( V_83 -> V_31 > V_185 )
V_184 = V_83 -> V_31 - V_185 ;
strncpy ( V_179 , V_68 + V_184 , V_183 ) ;
if ( V_184 )
V_179 [ 0 ] = V_179 [ 1 ] = '.' ;
if ( ( V_181 - V_184 ) > V_183 ) {
V_179 [ V_183 - 1 ] = V_179 [ V_183 - 2 ] = '.' ;
V_179 [ V_183 ] = 0 ;
}
V_31 = V_182 + V_83 -> V_31 - V_184 ;
}
fprintf ( V_186 , L_25 , V_23 , V_179 ) ;
if ( V_31 ) {
fprintf ( V_186 , L_26 , V_31 + 1 , L_27 , V_83 -> V_23 ) ;
if ( V_83 -> V_187 )
fprintf ( V_186 , L_28 , V_83 -> V_187 ) ;
free ( V_83 -> V_23 ) ;
free ( V_83 -> V_187 ) ;
}
fprintf ( V_186 , L_29 ) ;
}
int F_84 ( const struct V_188 * V_189 , const char * V_23 ,
int T_6 V_190 )
{
struct V_168 * V_169 = * (struct V_168 * * ) V_189 -> V_191 ;
struct V_82 V_83 = { . V_31 = 0 , } ;
int V_64 = F_78 ( V_169 , V_23 , & V_83 ) ;
if ( V_64 )
F_83 ( & V_83 , V_23 ) ;
return V_64 ;
}
int F_85 ( const struct V_188 * V_189 , const char * V_23 ,
int T_6 V_190 )
{
struct V_168 * V_169 = * (struct V_168 * * ) V_189 -> V_191 ;
struct V_28 * V_192 = NULL ;
if ( V_169 -> V_170 > 0 )
V_192 = F_86 ( V_169 ) ;
if ( V_192 == NULL || V_192 -> V_33 . type != V_26 ) {
fprintf ( V_186 ,
L_30 ) ;
return - 1 ;
}
V_192 -> V_193 = F_15 ( V_23 ) ;
if ( V_192 -> V_193 == NULL ) {
fprintf ( V_186 , L_31 ) ;
return - 1 ;
}
return 0 ;
}
static int F_87 ( const void * V_194 , const void * V_195 )
{
const char * const * V_196 = V_194 ;
const char * const * V_197 = V_195 ;
return strcmp ( * V_196 , * V_197 ) ;
}
void F_88 ( const char * V_198 , const char * V_199 ,
bool V_200 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char * * V_201 = NULL ;
unsigned int V_202 = 0 , V_203 = 0 ;
bool V_204 = false ;
V_205:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_204 ) {
V_201 = F_11 ( sizeof( char * ) * V_203 ) ;
if ( ! V_201 )
goto V_206;
}
F_6 (sys_dir, sys_dirent, sys_next) {
if ( V_198 != NULL &&
! F_30 ( V_16 . V_8 , V_198 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_5 ( V_20 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_199 != NULL &&
! F_30 ( V_17 . V_8 , V_199 ) )
continue;
if ( ! V_204 ) {
V_203 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_32 ,
V_16 . V_8 , V_17 . V_8 ) ;
V_201 [ V_202 ] = F_15 ( V_4 ) ;
if ( V_201 [ V_202 ] == NULL )
goto V_207;
V_202 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_204 ) {
V_204 = true ;
goto V_205;
}
qsort ( V_201 , V_203 , sizeof( char * ) , F_87 ) ;
V_202 = 0 ;
while ( V_202 < V_203 ) {
if ( V_200 ) {
printf ( L_33 , V_201 [ V_202 ++ ] ) ;
continue;
}
printf ( L_34 , V_201 [ V_202 ++ ] ,
V_208 [ V_26 ] ) ;
}
if ( V_203 )
printf ( L_35 ) ;
V_209:
V_203 = V_202 ;
for ( V_202 = 0 ; V_202 < V_203 ; V_202 ++ )
F_12 ( & V_201 [ V_202 ] ) ;
F_12 ( & V_201 ) ;
return;
V_207:
F_10 ( V_3 ) ;
V_206:
F_10 ( V_2 ) ;
printf ( L_36 ,
V_208 [ V_26 ] ) ;
if ( V_201 )
goto V_209;
}
int F_89 ( const char * V_210 )
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
snprintf ( V_4 , V_5 , L_32 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_210 ) ) {
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
static bool F_90 ( T_7 type , unsigned V_12 )
{
bool V_64 = true ;
int V_211 ;
struct V_28 * V_36 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_212 = 1 ,
} ;
struct {
struct V_213 V_214 ;
int V_215 [ 1 ] ;
} V_216 = {
. V_214 . V_217 = 1 ,
. V_215 = { 0 } ,
} ;
V_36 = F_91 ( & V_33 ) ;
if ( V_36 ) {
V_211 = F_92 ( V_36 , NULL , & V_216 . V_214 ) ;
V_64 = V_211 >= 0 ;
if ( V_211 == - V_218 ) {
V_36 -> V_33 . V_126 = 1 ;
V_64 = F_92 ( V_36 , NULL , & V_216 . V_214 ) >= 0 ;
}
F_93 ( V_36 ) ;
}
return V_64 ;
}
int F_94 ( const char * V_199 , bool V_200 )
{
unsigned int type , V_219 , V_42 , V_202 = 0 , V_203 = 0 ;
char V_22 [ 64 ] ;
char * * V_201 = NULL ;
bool V_204 = false ;
V_205:
if ( V_204 ) {
V_201 = F_11 ( sizeof( char * ) * V_203 ) ;
if ( ! V_201 )
goto V_220;
}
for ( type = 0 ; type < V_54 ; type ++ ) {
for ( V_219 = 0 ; V_219 < V_56 ; V_219 ++ ) {
if ( ! F_25 ( type , V_219 ) )
continue;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
F_95 ( type , V_219 , V_42 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_199 != NULL && ! F_30 ( V_22 , V_199 ) )
continue;
if ( ! F_90 ( V_27 ,
type | ( V_219 << 8 ) | ( V_42 << 16 ) ) )
continue;
if ( ! V_204 ) {
V_203 ++ ;
continue;
}
V_201 [ V_202 ] = F_15 ( V_22 ) ;
if ( V_201 [ V_202 ] == NULL )
goto V_220;
V_202 ++ ;
}
}
}
if ( ! V_204 ) {
V_204 = true ;
goto V_205;
}
qsort ( V_201 , V_203 , sizeof( char * ) , F_87 ) ;
V_202 = 0 ;
while ( V_202 < V_203 ) {
if ( V_200 ) {
printf ( L_33 , V_201 [ V_202 ++ ] ) ;
continue;
}
printf ( L_34 , V_201 [ V_202 ++ ] ,
V_208 [ V_27 ] ) ;
}
if ( V_203 )
printf ( L_35 ) ;
V_209:
V_203 = V_202 ;
for ( V_202 = 0 ; V_202 < V_203 ; V_202 ++ )
F_12 ( & V_201 [ V_202 ] ) ;
F_12 ( & V_201 ) ;
return V_203 ;
V_220:
printf ( L_36 , V_208 [ V_27 ] ) ;
if ( V_201 )
goto V_209;
return V_203 ;
}
void F_96 ( const char * V_199 , unsigned type ,
struct V_221 * V_222 , unsigned V_223 ,
bool V_200 )
{
unsigned int V_42 , V_202 = 0 , V_203 = 0 ;
char V_22 [ V_48 ] ;
char * * V_201 = NULL ;
bool V_204 = false ;
V_205:
if ( V_204 ) {
V_201 = F_11 ( sizeof( char * ) * V_203 ) ;
if ( ! V_201 )
goto V_220;
V_222 -= V_223 ;
}
for ( V_42 = 0 ; V_42 < V_223 ; V_42 ++ , V_222 ++ ) {
if ( V_199 != NULL &&
! ( F_30 ( V_222 -> V_148 , V_199 ) ||
( V_222 -> V_152 && F_30 ( V_222 -> V_152 , V_199 ) ) ) )
continue;
if ( ! F_90 ( type , V_42 ) )
continue;
if ( ! V_204 ) {
V_203 ++ ;
continue;
}
if ( ! V_200 && strlen ( V_222 -> V_152 ) )
snprintf ( V_22 , V_48 , L_37 , V_222 -> V_148 , V_222 -> V_152 ) ;
else
strncpy ( V_22 , V_222 -> V_148 , V_48 ) ;
V_201 [ V_202 ] = F_15 ( V_22 ) ;
if ( V_201 [ V_202 ] == NULL )
goto V_220;
V_202 ++ ;
}
if ( ! V_204 ) {
V_204 = true ;
goto V_205;
}
qsort ( V_201 , V_203 , sizeof( char * ) , F_87 ) ;
V_202 = 0 ;
while ( V_202 < V_203 ) {
if ( V_200 ) {
printf ( L_33 , V_201 [ V_202 ++ ] ) ;
continue;
}
printf ( L_34 , V_201 [ V_202 ++ ] , V_208 [ type ] ) ;
}
if ( V_203 )
printf ( L_35 ) ;
V_209:
V_203 = V_202 ;
for ( V_202 = 0 ; V_202 < V_203 ; V_202 ++ )
F_12 ( & V_201 [ V_202 ] ) ;
F_12 ( & V_201 ) ;
return;
V_220:
printf ( L_36 , V_208 [ type ] ) ;
if ( V_201 )
goto V_209;
}
void F_97 ( const char * V_199 , bool V_200 )
{
F_96 ( V_199 , V_24 ,
V_224 , V_225 , V_200 ) ;
F_96 ( V_199 , V_25 ,
V_226 , V_227 , V_200 ) ;
F_94 ( V_199 , V_200 ) ;
F_98 ( V_199 , V_200 ) ;
if ( V_199 != NULL )
return;
if ( ! V_200 ) {
printf ( L_34 ,
L_38 ,
V_208 [ V_228 ] ) ;
printf ( L_34 ,
L_39 ,
V_208 [ V_228 ] ) ;
printf ( L_40 ) ;
printf ( L_35 ) ;
printf ( L_34 ,
L_41 ,
V_208 [ V_78 ] ) ;
printf ( L_35 ) ;
}
F_88 ( NULL , NULL , V_200 ) ;
}
int F_99 ( struct V_80 * V_81 )
{
return V_81 -> V_87 != V_88 ;
}
static int F_100 ( struct V_80 * * V_229 , int V_84 ,
int V_87 , char * V_12 ,
char * V_23 , T_1 V_92 , int V_230 , int V_85 )
{
struct V_80 * V_81 ;
V_81 = F_11 ( sizeof( * V_81 ) ) ;
if ( ! V_81 )
return - V_38 ;
F_101 ( & V_81 -> V_30 ) ;
V_81 -> V_84 = V_84 ;
V_81 -> V_87 = V_87 ;
V_81 -> V_12 = V_12 ;
V_81 -> V_230 = V_230 ;
V_81 -> V_85 = V_85 ;
switch ( V_84 ) {
case V_86 :
V_81 -> V_91 . V_92 = V_92 ;
break;
case V_231 :
V_81 -> V_91 . V_23 = V_23 ;
break;
default:
free ( V_81 ) ;
return - V_10 ;
}
* V_229 = V_81 ;
return 0 ;
}
int F_102 ( struct V_80 * * V_81 ,
int V_87 , char * V_12 , T_1 V_92 ,
void * V_232 , void * V_233 )
{
T_8 * V_234 = V_232 ;
T_8 * V_235 = V_233 ;
return F_100 ( V_81 , V_86 , V_87 ,
V_12 , NULL , V_92 ,
V_234 ? V_234 -> V_236 : 0 ,
V_235 ? V_235 -> V_236 : 0 ) ;
}
int F_103 ( struct V_80 * * V_81 ,
int V_87 , char * V_12 , char * V_23 ,
void * V_232 , void * V_233 )
{
T_8 * V_234 = V_232 ;
T_8 * V_235 = V_233 ;
return F_100 ( V_81 , V_231 , V_87 ,
V_12 , V_23 , 0 ,
V_234 ? V_234 -> V_236 : 0 ,
V_235 ? V_235 -> V_236 : 0 ) ;
}
int F_104 ( struct V_80 * * V_81 ,
char * V_12 , unsigned V_31 )
{
struct V_221 * V_237 ;
F_105 ( V_31 >= V_225 ) ;
V_237 = & V_224 [ V_31 ] ;
if ( V_12 )
return F_100 ( V_81 , V_231 ,
V_88 , V_12 ,
( char * ) V_237 -> V_148 , 0 , 0 , 0 ) ;
else
return F_100 ( V_81 , V_231 ,
V_88 ,
( char * ) L_42 , ( char * ) V_237 -> V_148 ,
0 , 0 , 0 ) ;
}
int F_106 ( struct V_80 * * V_238 ,
struct V_80 * V_81 )
{
return F_100 ( V_238 , V_81 -> V_84 , V_81 -> V_87 , V_81 -> V_12 ,
V_81 -> V_91 . V_23 , V_81 -> V_91 . V_92 ,
V_81 -> V_230 , V_81 -> V_85 ) ;
}
void F_77 ( struct V_29 * V_166 )
{
struct V_80 * V_81 , * V_239 ;
F_107 (term, h, terms, list)
free ( V_81 ) ;
}
void F_108 ( struct V_102 * V_103 ,
int V_31 , const char * V_23 )
{
struct V_82 * V_83 = V_103 -> error ;
if ( ! V_83 )
return;
V_83 -> V_31 = V_31 ;
V_83 -> V_23 = F_15 ( V_23 ) ;
F_109 ( ! V_83 -> V_23 , L_43 ) ;
}
