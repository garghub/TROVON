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
if ( F_5 ( V_7 ) )
return NULL ;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return NULL ;
F_7 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_3 , V_20 ,
V_17 . V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( F_9 ( V_6 , V_18 , sizeof( V_18 ) ) < 0 ) {
F_3 ( V_6 ) ;
continue;
}
F_3 ( V_6 ) ;
V_19 = F_10 ( V_18 ) ;
if ( V_19 == V_12 ) {
F_11 ( V_3 ) ;
F_11 ( V_2 ) ;
V_13 = F_12 ( sizeof( * V_13 ) ) ;
V_13 -> system = malloc ( V_21 ) ;
if ( ! V_13 -> system ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> V_22 = malloc ( V_21 ) ;
if ( ! V_13 -> V_22 ) {
F_13 ( & V_13 -> system ) ;
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
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
return NULL ;
}
struct V_11 * F_14 ( const char * V_22 )
{
struct V_11 * V_13 = F_12 ( sizeof( * V_13 ) ) ;
char * V_23 = strchr ( V_22 , ':' ) ;
if ( V_13 == NULL || V_23 == NULL ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> system = F_15 ( V_22 , V_23 - V_22 ) ;
V_13 -> V_22 = F_16 ( V_23 + 1 ) ;
if ( V_13 -> system == NULL || V_13 -> V_22 == NULL ) {
F_13 ( & V_13 -> system ) ;
F_13 ( & V_13 -> V_22 ) ;
free ( V_13 ) ;
V_13 = NULL ;
}
return V_13 ;
}
const char * F_17 ( int type )
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
F_18 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 ,
char * V_22 , struct V_34 * V_35 )
{
struct V_28 * V_36 ;
F_19 ( V_33 ) ;
V_36 = F_20 ( V_33 , ( * V_31 ) ++ ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_35 = V_35 ;
if ( V_22 )
V_36 -> V_22 = F_16 ( V_22 ) ;
F_21 ( & V_36 -> V_37 , V_30 ) ;
return V_36 ;
}
static int F_22 ( struct V_29 * V_30 , int * V_31 ,
struct V_32 * V_33 , char * V_22 )
{
return F_18 ( V_30 , V_31 , V_33 , V_22 , NULL ) ? 0 : - V_38 ;
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
V_3 = F_6 ( V_4 ) ;
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
F_11 ( V_3 ) ;
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
V_66 = F_6 ( V_7 ) ;
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
F_11 ( V_66 ) ;
return V_64 ;
}
int F_33 ( struct V_29 * V_30 , int * V_31 ,
char * V_67 , char * V_68 )
{
int V_64 ;
V_64 = F_5 ( V_7 ) ;
if ( V_64 )
return V_64 ;
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
void * V_73 , char * type )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_74 = ( unsigned long ) V_73 ;
if ( F_34 ( type , & V_33 ) )
return - V_10 ;
if ( V_33 . V_72 == V_71 )
V_33 . V_75 = sizeof( long ) ;
else
V_33 . V_75 = V_76 ;
V_33 . type = V_77 ;
V_33 . V_78 = 1 ;
return F_22 ( V_30 , V_31 , & V_33 , NULL ) ;
}
static int F_37 ( struct V_32 * V_33 ,
struct V_79 * V_80 )
{
#define F_38 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_80 -> V_81 ) {
case V_82 :
F_38 ( V_83 ) ;
V_33 -> V_12 = V_80 -> V_84 . V_85 ;
break;
case V_86 :
F_38 ( V_83 ) ;
V_33 -> V_87 = V_80 -> V_84 . V_85 ;
break;
case V_88 :
F_38 ( V_83 ) ;
V_33 -> V_89 = V_80 -> V_84 . V_85 ;
break;
case V_90 :
F_38 ( V_83 ) ;
V_33 -> V_78 = V_80 -> V_84 . V_85 ;
break;
case V_91 :
break;
case V_92 :
F_38 ( V_93 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_38
}
static int F_39 ( struct V_32 * V_33 ,
struct V_29 * V_94 , int V_95 )
{
struct V_79 * V_80 ;
F_40 (term, head, list)
if ( F_37 ( V_33 , V_80 ) && V_95 )
return - V_10 ;
return 0 ;
}
int F_41 ( struct V_29 * V_30 , int * V_31 ,
T_4 type , T_1 V_12 ,
struct V_29 * V_96 )
{
struct V_32 V_33 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . type = type ;
V_33 . V_12 = V_12 ;
if ( V_96 &&
F_39 ( & V_33 , V_96 , 1 ) )
return - V_10 ;
return F_22 ( V_30 , V_31 , & V_33 , NULL ) ;
}
static int F_42 ( struct V_79 * V_80 )
{
return V_80 -> V_81 == V_92 ;
}
static char * F_43 ( struct V_29 * V_97 )
{
struct V_79 * V_80 ;
F_40 (term, head_terms, list)
if ( F_42 ( V_80 ) )
return V_80 -> V_84 . V_23 ;
return NULL ;
}
int F_44 ( struct V_29 * V_30 , int * V_31 ,
char * V_22 , struct V_29 * V_96 )
{
struct V_32 V_33 ;
struct V_98 V_99 ;
struct V_100 * V_101 ;
struct V_28 * V_36 ;
V_101 = F_45 ( V_22 ) ;
if ( ! V_101 )
return - V_10 ;
if ( V_101 -> V_102 ) {
memcpy ( & V_33 , V_101 -> V_102 ,
sizeof( struct V_32 ) ) ;
} else {
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
}
if ( ! V_96 ) {
V_33 . type = V_101 -> type ;
V_36 = F_18 ( V_30 , V_31 , & V_33 , NULL , V_101 -> V_35 ) ;
return V_36 ? 0 : - V_38 ;
}
if ( F_46 ( V_101 , V_96 , & V_99 ) )
return - V_10 ;
F_39 ( & V_33 , V_96 , 0 ) ;
if ( F_47 ( V_101 , & V_33 , V_96 ) )
return - V_10 ;
V_36 = F_18 ( V_30 , V_31 , & V_33 , F_43 ( V_96 ) ,
V_101 -> V_35 ) ;
if ( V_36 ) {
V_36 -> V_103 = V_99 . V_103 ;
V_36 -> V_104 = V_99 . V_104 ;
V_36 -> V_105 = V_99 . V_105 ;
V_36 -> V_106 = V_99 . V_106 ;
}
return V_36 ? 0 : - V_38 ;
}
int F_48 ( struct V_29 * V_30 ,
char * V_107 )
{
return F_49 ( V_30 , V_107 , true ) ;
}
void F_50 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_108 ;
F_51 ( V_30 ) ;
V_108 = F_52 ( V_30 -> V_109 , struct V_28 , V_37 ) ;
V_108 -> V_110 = V_22 ? F_16 ( V_22 ) : NULL ;
}
void F_53 ( struct V_29 * V_111 ,
struct V_29 * V_112 )
{
F_54 ( V_111 , V_112 ) ;
free ( V_111 ) ;
}
static int F_55 ( struct V_113 * V_114 , char * V_23 ,
struct V_28 * V_36 )
{
int V_115 = V_36 ? V_36 -> V_33 . V_116 : 0 ;
int V_117 = V_36 ? V_36 -> V_33 . V_118 : 0 ;
int V_119 = V_36 ? V_36 -> V_33 . V_120 : 0 ;
int V_121 = V_36 ? V_36 -> V_33 . V_122 : 0 ;
int V_123 = V_36 ? V_36 -> V_33 . V_124 : 0 ;
int V_125 = V_36 ? V_36 -> V_33 . V_126 : 0 ;
int V_127 = 0 ;
int V_128 = V_36 ? V_36 -> V_33 . V_128 : 0 ;
int V_129 = V_115 | V_117 | V_119 ;
int V_130 = V_36 ? V_36 -> V_130 : 0 ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_129 )
V_129 = V_115 = V_117 = V_119 = 1 ;
V_115 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_129 )
V_129 = V_115 = V_117 = V_119 = 1 ;
V_117 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_129 )
V_129 = V_115 = V_117 = V_119 = 1 ;
V_119 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_130 )
V_130 = V_123 = V_121 = 1 ;
V_123 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_130 )
V_130 = V_123 = V_121 = 1 ;
V_121 = 0 ;
} else if ( * V_23 == 'p' ) {
V_125 ++ ;
if ( ! V_130 )
V_123 = 1 ;
} else if ( * V_23 == 'S' ) {
V_127 = 1 ;
} else if ( * V_23 == 'D' ) {
V_128 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_125 > 3 )
return - V_10 ;
V_114 -> V_115 = V_115 ;
V_114 -> V_117 = V_117 ;
V_114 -> V_119 = V_119 ;
V_114 -> V_121 = V_121 ;
V_114 -> V_123 = V_123 ;
V_114 -> V_125 = V_125 ;
V_114 -> V_130 = V_130 ;
V_114 -> V_127 = V_127 ;
V_114 -> V_128 = V_128 ;
return 0 ;
}
static int F_56 ( char * V_23 )
{
char * V_131 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_19 ) - 1 ) )
return - 1 ;
while ( * V_131 ) {
if ( * V_131 != 'p' && strchr ( V_131 + 1 , * V_131 ) )
return - 1 ;
V_131 ++ ;
}
return 0 ;
}
int F_49 ( struct V_29 * V_30 , char * V_23 , bool V_132 )
{
struct V_28 * V_36 ;
struct V_113 V_114 ;
if ( V_23 == NULL )
return 0 ;
if ( F_56 ( V_23 ) )
return - V_10 ;
if ( ! V_132 && F_55 ( & V_114 , V_23 , NULL ) )
return - V_10 ;
F_57 (list, evsel) {
if ( V_132 && F_55 ( & V_114 , V_23 , V_36 ) )
return - V_10 ;
V_36 -> V_33 . V_116 = V_114 . V_115 ;
V_36 -> V_33 . V_118 = V_114 . V_117 ;
V_36 -> V_33 . V_120 = V_114 . V_119 ;
V_36 -> V_33 . V_126 = V_114 . V_125 ;
V_36 -> V_33 . V_122 = V_114 . V_121 ;
V_36 -> V_33 . V_124 = V_114 . V_123 ;
V_36 -> V_130 = V_114 . V_130 ;
V_36 -> V_127 = V_114 . V_127 ;
if ( F_58 ( V_36 ) )
V_36 -> V_33 . V_128 = V_114 . V_128 ;
}
return 0 ;
}
int F_59 ( struct V_29 * V_30 , char * V_22 )
{
struct V_28 * V_36 ;
F_57 (list, evsel) {
if ( ! V_36 -> V_22 )
V_36 -> V_22 = F_16 ( V_22 ) ;
}
return 0 ;
}
static int
F_60 ( const void * V_133 , const void * V_134 )
{
struct V_135 * V_136 = (struct V_135 * ) V_133 ;
struct V_135 * V_137 = (struct V_135 * ) V_134 ;
return strcmp ( V_136 -> V_138 , V_137 -> V_138 ) ;
}
static void F_61 ( void )
{
if ( V_139 > 0 ) {
struct V_135 * V_131 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_139 ; V_42 ++ ) {
V_131 = V_140 + V_42 ;
free ( V_131 -> V_138 ) ;
}
free ( V_140 ) ;
V_140 = NULL ;
V_139 = 0 ;
}
}
static void F_62 ( void )
{
struct V_100 * V_101 = NULL ;
struct V_141 * V_142 ;
int V_143 = 0 ;
V_101 = F_45 ( L_20 ) ;
if ( ( V_101 == NULL ) || F_63 ( & V_101 -> V_144 ) ) {
V_139 = - 1 ;
return;
}
F_40 (alias, &pmu->aliases, list) {
if ( strchr ( V_142 -> V_22 , '-' ) )
V_143 ++ ;
V_143 ++ ;
}
V_140 = malloc ( sizeof( struct V_135 ) * V_143 ) ;
if ( ! V_140 )
return;
V_139 = V_143 ;
V_143 = 0 ;
F_40 (alias, &pmu->aliases, list) {
struct V_135 * V_131 = V_140 + V_143 ;
char * V_145 = strchr ( V_142 -> V_22 , '-' ) ;
if ( V_145 != NULL ) {
F_64 ( F_15 ( V_142 -> V_22 , V_145 - V_142 -> V_22 ) ,
V_146 ) ;
V_131 ++ ;
F_64 ( F_16 ( ++ V_145 ) , V_147 ) ;
V_143 += 2 ;
} else {
F_64 ( F_16 ( V_142 -> V_22 ) , V_148 ) ;
V_143 ++ ;
}
}
qsort ( V_140 , V_143 ,
sizeof( struct V_135 ) , F_60 ) ;
return;
V_149:
F_61 () ;
}
enum V_150
F_65 ( const char * V_22 )
{
struct V_135 V_131 , * V_151 ;
if ( V_139 == 0 )
F_62 () ;
if ( ( V_139 <= 0 ) || ! strcmp ( V_22 , L_20 ) )
return V_152 ;
V_131 . V_138 = F_16 ( V_22 ) ;
V_151 = bsearch ( & V_131 , V_140 ,
( V_153 ) V_139 ,
sizeof( struct V_135 ) , F_60 ) ;
free ( V_131 . V_138 ) ;
return V_151 ? V_151 -> type : V_152 ;
}
static int F_66 ( const char * V_23 , void * V_154 , int V_155 )
{
T_5 V_156 ;
void * V_157 ;
int V_64 ;
V_64 = F_67 ( V_155 , & V_157 ) ;
if ( V_64 )
return V_64 ;
V_156 = F_68 ( V_23 , V_157 ) ;
#ifdef F_69
V_158 = 1 ;
#endif
V_64 = F_70 ( V_154 , V_157 ) ;
F_71 ( V_156 , V_157 ) ;
F_72 ( V_156 , V_157 ) ;
F_73 ( V_157 ) ;
return V_64 ;
}
int F_74 ( struct V_29 * V_159 , const char * V_23 )
{
struct F_74 V_154 = {
. V_159 = NULL ,
} ;
int V_64 ;
V_64 = F_66 ( V_23 , & V_154 , V_160 ) ;
if ( ! V_64 ) {
F_75 ( V_154 . V_159 , V_159 ) ;
F_13 ( & V_154 . V_159 ) ;
return 0 ;
}
if ( V_154 . V_159 )
F_76 ( V_154 . V_159 ) ;
return V_64 ;
}
int F_77 ( struct V_161 * V_162 , const char * V_23 )
{
struct V_163 V_154 = {
. V_30 = F_78 ( V_154 . V_30 ) ,
. V_31 = V_162 -> V_164 ,
} ;
int V_64 ;
V_64 = F_66 ( V_23 , & V_154 , V_165 ) ;
F_61 () ;
if ( ! V_64 ) {
int V_166 = V_154 . V_31 - V_162 -> V_164 ;
F_79 ( V_162 , & V_154 . V_30 , V_166 ) ;
V_162 -> V_167 += V_154 . V_167 ;
return 0 ;
}
return V_64 ;
}
int F_80 ( const struct V_168 * V_169 , const char * V_23 ,
int T_6 V_170 )
{
struct V_161 * V_162 = * (struct V_161 * * ) V_169 -> V_171 ;
int V_64 = F_77 ( V_162 , V_23 ) ;
if ( V_64 ) {
fprintf ( V_172 , L_21 , V_23 ) ;
fprintf ( V_172 , L_22 ) ;
}
return V_64 ;
}
int F_81 ( const struct V_168 * V_169 , const char * V_23 ,
int T_6 V_170 )
{
struct V_161 * V_162 = * (struct V_161 * * ) V_169 -> V_171 ;
struct V_28 * V_173 = NULL ;
if ( V_162 -> V_164 > 0 )
V_173 = F_82 ( V_162 ) ;
if ( V_173 == NULL || V_173 -> V_33 . type != V_26 ) {
fprintf ( V_172 ,
L_23 ) ;
return - 1 ;
}
V_173 -> V_174 = F_16 ( V_23 ) ;
if ( V_173 -> V_174 == NULL ) {
fprintf ( V_172 , L_24 ) ;
return - 1 ;
}
return 0 ;
}
void F_83 ( const char * V_175 , const char * V_176 ,
bool V_177 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char V_178 [ V_179 ] ;
if ( F_5 ( V_7 ) ) {
printf ( L_25 ,
F_84 ( V_180 , V_178 , sizeof( V_178 ) ) ) ;
return;
}
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return;
F_7 (sys_dir, sys_dirent, sys_next) {
if ( V_175 != NULL &&
! F_30 ( V_16 . V_8 , V_175 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_176 != NULL &&
! F_30 ( V_17 . V_8 , V_176 ) )
continue;
if ( V_177 ) {
printf ( L_26 , V_16 . V_8 , V_17 . V_8 ) ;
continue;
}
snprintf ( V_4 , V_5 , L_27 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_28 , V_4 ,
V_181 [ V_26 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_85 ( const char * V_182 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) )
return 0 ;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return 0 ;
F_7 (sys_dir, sys_dirent, sys_next) {
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf ( V_4 , V_5 , L_27 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_182 ) ) {
F_11 ( V_3 ) ;
F_11 ( V_2 ) ;
return 1 ;
}
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static bool F_86 ( T_7 type , unsigned V_12 )
{
bool V_64 = true ;
int V_183 ;
struct V_28 * V_36 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_184 = 1 ,
} ;
struct {
struct V_185 V_186 ;
int V_187 [ 1 ] ;
} V_188 = {
. V_186 . V_189 = 1 ,
. V_187 = { 0 } ,
} ;
V_36 = F_87 ( & V_33 ) ;
if ( V_36 ) {
V_183 = F_88 ( V_36 , NULL , & V_188 . V_186 ) ;
V_64 = V_183 >= 0 ;
if ( V_183 == - V_190 ) {
V_36 -> V_33 . V_118 = 1 ;
V_64 = F_88 ( V_36 , NULL , & V_188 . V_186 ) >= 0 ;
}
F_89 ( V_36 ) ;
}
return V_64 ;
}
static void F_90 ( T_7 type , struct V_191 * V_192 ,
unsigned V_193 )
{
char V_22 [ 64 ] ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_193 ; V_42 ++ , V_192 ++ ) {
if ( ! F_86 ( type , V_42 ) )
continue;
if ( strlen ( V_192 -> V_142 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_29 ,
V_192 -> V_138 , V_192 -> V_142 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_192 -> V_138 ) ;
printf ( L_28 , V_22 , V_181 [ type ] ) ;
}
}
void F_91 ( T_7 type )
{
if ( type == V_25 )
F_90 ( type , V_194 , V_195 ) ;
else
F_90 ( type , V_196 , V_197 ) ;
}
int F_92 ( const char * V_176 , bool V_177 )
{
unsigned int type , V_198 , V_42 , V_199 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_54 ; type ++ ) {
for ( V_198 = 0 ; V_198 < V_56 ; V_198 ++ ) {
if ( ! F_25 ( type , V_198 ) )
continue;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
F_93 ( type , V_198 , V_42 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_176 != NULL && ! F_30 ( V_22 , V_176 ) )
continue;
if ( ! F_86 ( V_27 ,
type | ( V_198 << 8 ) | ( V_42 << 16 ) ) )
continue;
if ( V_177 )
printf ( L_30 , V_22 ) ;
else
printf ( L_28 , V_22 ,
V_181 [ V_27 ] ) ;
++ V_199 ;
}
}
}
if ( V_199 )
printf ( L_31 ) ;
return V_199 ;
}
static void F_94 ( const char * V_176 , unsigned type ,
struct V_191 * V_192 , unsigned V_193 ,
bool V_177 )
{
unsigned V_42 , V_199 = 0 ;
char V_22 [ V_48 ] ;
for ( V_42 = 0 ; V_42 < V_193 ; V_42 ++ , V_192 ++ ) {
if ( V_176 != NULL &&
! ( F_30 ( V_192 -> V_138 , V_176 ) ||
( V_192 -> V_142 && F_30 ( V_192 -> V_142 , V_176 ) ) ) )
continue;
if ( ! F_86 ( type , V_42 ) )
continue;
if ( V_177 ) {
printf ( L_30 , V_192 -> V_138 ) ;
continue;
}
if ( strlen ( V_192 -> V_142 ) )
snprintf ( V_22 , V_48 , L_29 , V_192 -> V_138 , V_192 -> V_142 ) ;
else
strncpy ( V_22 , V_192 -> V_138 , V_48 ) ;
printf ( L_28 , V_22 , V_181 [ type ] ) ;
V_199 ++ ;
}
if ( V_199 )
printf ( L_31 ) ;
}
void F_95 ( const char * V_176 , bool V_177 )
{
if ( ! V_177 ) {
printf ( L_31 ) ;
printf ( L_32 ) ;
}
F_94 ( V_176 , V_24 ,
V_196 , V_197 , V_177 ) ;
F_94 ( V_176 , V_25 ,
V_194 , V_195 , V_177 ) ;
F_92 ( V_176 , V_177 ) ;
F_96 ( V_176 , V_177 ) ;
if ( V_176 != NULL )
return;
if ( ! V_177 ) {
printf ( L_28 ,
L_33 ,
V_181 [ V_200 ] ) ;
printf ( L_28 ,
L_34 ,
V_181 [ V_200 ] ) ;
printf ( L_35 ) ;
printf ( L_31 ) ;
printf ( L_28 ,
L_36 ,
V_181 [ V_77 ] ) ;
printf ( L_31 ) ;
}
F_83 ( NULL , NULL , V_177 ) ;
}
int F_97 ( struct V_79 * V_80 )
{
return V_80 -> V_81 != V_201 ;
}
static int F_98 ( struct V_79 * * V_202 , int V_203 ,
int V_81 , char * V_12 ,
char * V_23 , T_1 V_85 )
{
struct V_79 * V_80 ;
V_80 = F_12 ( sizeof( * V_80 ) ) ;
if ( ! V_80 )
return - V_38 ;
F_99 ( & V_80 -> V_30 ) ;
V_80 -> V_203 = V_203 ;
V_80 -> V_81 = V_81 ;
V_80 -> V_12 = V_12 ;
switch ( V_203 ) {
case V_204 :
V_80 -> V_84 . V_85 = V_85 ;
break;
case V_205 :
V_80 -> V_84 . V_23 = V_23 ;
break;
default:
free ( V_80 ) ;
return - V_10 ;
}
* V_202 = V_80 ;
return 0 ;
}
int F_100 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , T_1 V_85 )
{
return F_98 ( V_80 , V_204 , V_81 ,
V_12 , NULL , V_85 ) ;
}
int F_101 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , char * V_23 )
{
return F_98 ( V_80 , V_205 , V_81 ,
V_12 , V_23 , 0 ) ;
}
int F_102 ( struct V_79 * * V_80 ,
char * V_12 , unsigned V_31 )
{
struct V_191 * V_206 ;
F_103 ( V_31 >= V_197 ) ;
V_206 = & V_196 [ V_31 ] ;
if ( V_12 )
return F_98 ( V_80 , V_205 ,
V_201 , V_12 ,
( char * ) V_206 -> V_138 , 0 ) ;
else
return F_98 ( V_80 , V_205 ,
V_201 ,
( char * ) L_37 , ( char * ) V_206 -> V_138 , 0 ) ;
}
int F_104 ( struct V_79 * * V_207 ,
struct V_79 * V_80 )
{
return F_98 ( V_207 , V_80 -> V_203 , V_80 -> V_81 , V_80 -> V_12 ,
V_80 -> V_84 . V_23 , V_80 -> V_84 . V_85 ) ;
}
void F_76 ( struct V_29 * V_159 )
{
struct V_79 * V_80 , * V_208 ;
F_105 (term, h, terms, list)
free ( V_80 ) ;
}
