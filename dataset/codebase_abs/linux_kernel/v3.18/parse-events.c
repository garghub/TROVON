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
}
return V_36 ? 0 : - V_38 ;
}
int F_48 ( struct V_29 * V_30 ,
char * V_105 )
{
return F_49 ( V_30 , V_105 , true ) ;
}
void F_50 ( char * V_22 , struct V_29 * V_30 )
{
struct V_28 * V_106 ;
F_51 ( V_30 ) ;
V_106 = F_52 ( V_30 -> V_107 , struct V_28 , V_37 ) ;
V_106 -> V_108 = V_22 ? F_16 ( V_22 ) : NULL ;
}
void F_53 ( struct V_29 * V_109 ,
struct V_29 * V_110 )
{
F_54 ( V_109 , V_110 ) ;
free ( V_109 ) ;
}
static int F_55 ( struct V_111 * V_112 , char * V_23 ,
struct V_28 * V_36 )
{
int V_113 = V_36 ? V_36 -> V_33 . V_114 : 0 ;
int V_115 = V_36 ? V_36 -> V_33 . V_116 : 0 ;
int V_117 = V_36 ? V_36 -> V_33 . V_118 : 0 ;
int V_119 = V_36 ? V_36 -> V_33 . V_120 : 0 ;
int V_121 = V_36 ? V_36 -> V_33 . V_122 : 0 ;
int V_123 = V_36 ? V_36 -> V_33 . V_124 : 0 ;
int V_125 = 0 ;
int V_126 = V_36 ? V_36 -> V_33 . V_126 : 0 ;
int V_127 = V_113 | V_115 | V_117 ;
int V_128 = V_36 ? V_36 -> V_128 : 0 ;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_127 )
V_127 = V_113 = V_115 = V_117 = 1 ;
V_113 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_127 )
V_127 = V_113 = V_115 = V_117 = 1 ;
V_115 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_127 )
V_127 = V_113 = V_115 = V_117 = 1 ;
V_117 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_128 )
V_128 = V_121 = V_119 = 1 ;
V_121 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_128 )
V_128 = V_121 = V_119 = 1 ;
V_119 = 0 ;
} else if ( * V_23 == 'p' ) {
V_123 ++ ;
if ( ! V_128 )
V_121 = 1 ;
} else if ( * V_23 == 'S' ) {
V_125 = 1 ;
} else if ( * V_23 == 'D' ) {
V_126 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_123 > 3 )
return - V_10 ;
V_112 -> V_113 = V_113 ;
V_112 -> V_115 = V_115 ;
V_112 -> V_117 = V_117 ;
V_112 -> V_119 = V_119 ;
V_112 -> V_121 = V_121 ;
V_112 -> V_123 = V_123 ;
V_112 -> V_128 = V_128 ;
V_112 -> V_125 = V_125 ;
V_112 -> V_126 = V_126 ;
return 0 ;
}
static int F_56 ( char * V_23 )
{
char * V_129 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_19 ) - 1 ) )
return - 1 ;
while ( * V_129 ) {
if ( * V_129 != 'p' && strchr ( V_129 + 1 , * V_129 ) )
return - 1 ;
V_129 ++ ;
}
return 0 ;
}
int F_49 ( struct V_29 * V_30 , char * V_23 , bool V_130 )
{
struct V_28 * V_36 ;
struct V_111 V_112 ;
if ( V_23 == NULL )
return 0 ;
if ( F_56 ( V_23 ) )
return - V_10 ;
if ( ! V_130 && F_55 ( & V_112 , V_23 , NULL ) )
return - V_10 ;
F_57 (list, evsel) {
if ( V_130 && F_55 ( & V_112 , V_23 , V_36 ) )
return - V_10 ;
V_36 -> V_33 . V_114 = V_112 . V_113 ;
V_36 -> V_33 . V_116 = V_112 . V_115 ;
V_36 -> V_33 . V_118 = V_112 . V_117 ;
V_36 -> V_33 . V_124 = V_112 . V_123 ;
V_36 -> V_33 . V_120 = V_112 . V_119 ;
V_36 -> V_33 . V_122 = V_112 . V_121 ;
V_36 -> V_128 = V_112 . V_128 ;
V_36 -> V_125 = V_112 . V_125 ;
if ( F_58 ( V_36 ) )
V_36 -> V_33 . V_126 = V_112 . V_126 ;
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
F_60 ( const void * V_131 , const void * V_132 )
{
struct V_133 * V_134 = (struct V_133 * ) V_131 ;
struct V_133 * V_135 = (struct V_133 * ) V_132 ;
return strcmp ( V_134 -> V_136 , V_135 -> V_136 ) ;
}
static void F_61 ( void )
{
if ( V_137 > 0 ) {
struct V_133 * V_129 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_137 ; V_42 ++ ) {
V_129 = V_138 + V_42 ;
free ( V_129 -> V_136 ) ;
}
free ( V_138 ) ;
V_138 = NULL ;
V_137 = 0 ;
}
}
static void F_62 ( void )
{
struct V_100 * V_101 = NULL ;
struct V_139 * V_140 ;
int V_141 = 0 ;
V_101 = F_45 ( L_20 ) ;
if ( ( V_101 == NULL ) || F_63 ( & V_101 -> V_142 ) ) {
V_137 = - 1 ;
return;
}
F_40 (alias, &pmu->aliases, list) {
if ( strchr ( V_140 -> V_22 , '-' ) )
V_141 ++ ;
V_141 ++ ;
}
V_138 = malloc ( sizeof( struct V_133 ) * V_141 ) ;
if ( ! V_138 )
return;
V_137 = V_141 ;
V_141 = 0 ;
F_40 (alias, &pmu->aliases, list) {
struct V_133 * V_129 = V_138 + V_141 ;
char * V_143 = strchr ( V_140 -> V_22 , '-' ) ;
if ( V_143 != NULL ) {
F_64 ( F_15 ( V_140 -> V_22 , V_143 - V_140 -> V_22 ) ,
V_144 ) ;
V_129 ++ ;
F_64 ( F_16 ( ++ V_143 ) , V_145 ) ;
V_141 += 2 ;
} else {
F_64 ( F_16 ( V_140 -> V_22 ) , V_146 ) ;
V_141 ++ ;
}
}
qsort ( V_138 , V_141 ,
sizeof( struct V_133 ) , F_60 ) ;
return;
V_147:
F_61 () ;
}
enum V_148
F_65 ( const char * V_22 )
{
struct V_133 V_129 , * V_149 ;
if ( V_137 == 0 )
F_62 () ;
if ( ( V_137 <= 0 ) || ! strcmp ( V_22 , L_20 ) )
return V_150 ;
V_129 . V_136 = F_16 ( V_22 ) ;
V_149 = bsearch ( & V_129 , V_138 ,
( V_151 ) V_137 ,
sizeof( struct V_133 ) , F_60 ) ;
free ( V_129 . V_136 ) ;
return V_149 ? V_149 -> type : V_150 ;
}
static int F_66 ( const char * V_23 , void * V_152 , int V_153 )
{
T_5 V_154 ;
void * V_155 ;
int V_64 ;
V_64 = F_67 ( V_153 , & V_155 ) ;
if ( V_64 )
return V_64 ;
V_154 = F_68 ( V_23 , V_155 ) ;
#ifdef F_69
V_156 = 1 ;
#endif
V_64 = F_70 ( V_152 , V_155 ) ;
F_71 ( V_154 , V_155 ) ;
F_72 ( V_154 , V_155 ) ;
F_73 ( V_155 ) ;
return V_64 ;
}
int F_74 ( struct V_29 * V_157 , const char * V_23 )
{
struct F_74 V_152 = {
. V_157 = NULL ,
} ;
int V_64 ;
V_64 = F_66 ( V_23 , & V_152 , V_158 ) ;
if ( ! V_64 ) {
F_75 ( V_152 . V_157 , V_157 ) ;
F_13 ( & V_152 . V_157 ) ;
return 0 ;
}
if ( V_152 . V_157 )
F_76 ( V_152 . V_157 ) ;
return V_64 ;
}
int F_77 ( struct V_159 * V_160 , const char * V_23 )
{
struct V_161 V_152 = {
. V_30 = F_78 ( V_152 . V_30 ) ,
. V_31 = V_160 -> V_162 ,
} ;
int V_64 ;
V_64 = F_66 ( V_23 , & V_152 , V_163 ) ;
F_61 () ;
if ( ! V_64 ) {
int V_164 = V_152 . V_31 - V_160 -> V_162 ;
F_79 ( V_160 , & V_152 . V_30 , V_164 ) ;
V_160 -> V_165 += V_152 . V_165 ;
return 0 ;
}
return V_64 ;
}
int F_80 ( const struct V_166 * V_167 , const char * V_23 ,
int T_6 V_168 )
{
struct V_159 * V_160 = * (struct V_159 * * ) V_167 -> V_169 ;
int V_64 = F_77 ( V_160 , V_23 ) ;
if ( V_64 ) {
fprintf ( V_170 , L_21 , V_23 ) ;
fprintf ( V_170 , L_22 ) ;
}
return V_64 ;
}
int F_81 ( const struct V_166 * V_167 , const char * V_23 ,
int T_6 V_168 )
{
struct V_159 * V_160 = * (struct V_159 * * ) V_167 -> V_169 ;
struct V_28 * V_171 = NULL ;
if ( V_160 -> V_162 > 0 )
V_171 = F_82 ( V_160 ) ;
if ( V_171 == NULL || V_171 -> V_33 . type != V_26 ) {
fprintf ( V_170 ,
L_23 ) ;
return - 1 ;
}
V_171 -> V_172 = F_16 ( V_23 ) ;
if ( V_171 -> V_172 == NULL ) {
fprintf ( V_170 , L_24 ) ;
return - 1 ;
}
return 0 ;
}
void F_83 ( const char * V_173 , const char * V_174 ,
bool V_175 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
char V_176 [ V_177 ] ;
if ( F_5 ( V_7 ) ) {
printf ( L_25 ,
F_84 ( V_178 , V_176 , sizeof( V_176 ) ) ) ;
return;
}
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return;
F_7 (sys_dir, sys_dirent, sys_next) {
if ( V_173 != NULL &&
! F_30 ( V_16 . V_8 , V_173 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_174 != NULL &&
! F_30 ( V_17 . V_8 , V_174 ) )
continue;
if ( V_175 ) {
printf ( L_26 , V_16 . V_8 , V_17 . V_8 ) ;
continue;
}
snprintf ( V_4 , V_5 , L_27 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_28 , V_4 ,
V_179 [ V_26 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_85 ( const char * V_180 )
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
if ( ! strcmp ( V_4 , V_180 ) ) {
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
int V_181 ;
struct V_28 * V_36 ;
struct V_32 V_33 = {
. type = type ,
. V_12 = V_12 ,
. V_182 = 1 ,
} ;
struct {
struct V_183 V_184 ;
int V_185 [ 1 ] ;
} V_186 = {
. V_184 . V_187 = 1 ,
. V_185 = { 0 } ,
} ;
V_36 = F_87 ( & V_33 ) ;
if ( V_36 ) {
V_181 = F_88 ( V_36 , NULL , & V_186 . V_184 ) ;
V_64 = V_181 >= 0 ;
if ( V_181 == - V_188 ) {
V_36 -> V_33 . V_116 = 1 ;
V_64 = F_88 ( V_36 , NULL , & V_186 . V_184 ) >= 0 ;
}
F_89 ( V_36 ) ;
}
return V_64 ;
}
static void F_90 ( T_7 type , struct V_189 * V_190 ,
unsigned V_191 )
{
char V_22 [ 64 ] ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_191 ; V_42 ++ , V_190 ++ ) {
if ( ! F_86 ( type , V_42 ) )
continue;
if ( strlen ( V_190 -> V_140 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_29 ,
V_190 -> V_136 , V_190 -> V_140 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_190 -> V_136 ) ;
printf ( L_28 , V_22 , V_179 [ type ] ) ;
}
}
void F_91 ( T_7 type )
{
if ( type == V_25 )
F_90 ( type , V_192 , V_193 ) ;
else
F_90 ( type , V_194 , V_195 ) ;
}
int F_92 ( const char * V_174 , bool V_175 )
{
unsigned int type , V_196 , V_42 , V_197 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_54 ; type ++ ) {
for ( V_196 = 0 ; V_196 < V_56 ; V_196 ++ ) {
if ( ! F_25 ( type , V_196 ) )
continue;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
F_93 ( type , V_196 , V_42 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_174 != NULL && ! F_30 ( V_22 , V_174 ) )
continue;
if ( ! F_86 ( V_27 ,
type | ( V_196 << 8 ) | ( V_42 << 16 ) ) )
continue;
if ( V_175 )
printf ( L_30 , V_22 ) ;
else
printf ( L_28 , V_22 ,
V_179 [ V_27 ] ) ;
++ V_197 ;
}
}
}
if ( V_197 )
printf ( L_31 ) ;
return V_197 ;
}
static void F_94 ( const char * V_174 , unsigned type ,
struct V_189 * V_190 , unsigned V_191 ,
bool V_175 )
{
unsigned V_42 , V_197 = 0 ;
char V_22 [ V_48 ] ;
for ( V_42 = 0 ; V_42 < V_191 ; V_42 ++ , V_190 ++ ) {
if ( V_174 != NULL &&
! ( F_30 ( V_190 -> V_136 , V_174 ) ||
( V_190 -> V_140 && F_30 ( V_190 -> V_140 , V_174 ) ) ) )
continue;
if ( ! F_86 ( type , V_42 ) )
continue;
if ( V_175 ) {
printf ( L_30 , V_190 -> V_136 ) ;
continue;
}
if ( strlen ( V_190 -> V_140 ) )
snprintf ( V_22 , V_48 , L_29 , V_190 -> V_136 , V_190 -> V_140 ) ;
else
strncpy ( V_22 , V_190 -> V_136 , V_48 ) ;
printf ( L_28 , V_22 , V_179 [ type ] ) ;
V_197 ++ ;
}
if ( V_197 )
printf ( L_31 ) ;
}
void F_95 ( const char * V_174 , bool V_175 )
{
if ( ! V_175 ) {
printf ( L_31 ) ;
printf ( L_32 ) ;
}
F_94 ( V_174 , V_24 ,
V_194 , V_195 , V_175 ) ;
F_94 ( V_174 , V_25 ,
V_192 , V_193 , V_175 ) ;
F_92 ( V_174 , V_175 ) ;
F_96 ( V_174 , V_175 ) ;
if ( V_174 != NULL )
return;
if ( ! V_175 ) {
printf ( L_28 ,
L_33 ,
V_179 [ V_198 ] ) ;
printf ( L_28 ,
L_34 ,
V_179 [ V_198 ] ) ;
printf ( L_35 ) ;
printf ( L_31 ) ;
printf ( L_28 ,
L_36 ,
V_179 [ V_77 ] ) ;
printf ( L_31 ) ;
}
F_83 ( NULL , NULL , V_175 ) ;
}
int F_97 ( struct V_79 * V_80 )
{
return V_80 -> V_81 != V_199 ;
}
static int F_98 ( struct V_79 * * V_200 , int V_201 ,
int V_81 , char * V_12 ,
char * V_23 , T_1 V_85 )
{
struct V_79 * V_80 ;
V_80 = F_12 ( sizeof( * V_80 ) ) ;
if ( ! V_80 )
return - V_38 ;
F_99 ( & V_80 -> V_30 ) ;
V_80 -> V_201 = V_201 ;
V_80 -> V_81 = V_81 ;
V_80 -> V_12 = V_12 ;
switch ( V_201 ) {
case V_202 :
V_80 -> V_84 . V_85 = V_85 ;
break;
case V_203 :
V_80 -> V_84 . V_23 = V_23 ;
break;
default:
free ( V_80 ) ;
return - V_10 ;
}
* V_200 = V_80 ;
return 0 ;
}
int F_100 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , T_1 V_85 )
{
return F_98 ( V_80 , V_202 , V_81 ,
V_12 , NULL , V_85 ) ;
}
int F_101 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , char * V_23 )
{
return F_98 ( V_80 , V_203 , V_81 ,
V_12 , V_23 , 0 ) ;
}
int F_102 ( struct V_79 * * V_80 ,
char * V_12 , unsigned V_31 )
{
struct V_189 * V_204 ;
F_103 ( V_31 >= V_195 ) ;
V_204 = & V_194 [ V_31 ] ;
if ( V_12 )
return F_98 ( V_80 , V_203 ,
V_199 , V_12 ,
( char * ) V_204 -> V_136 , 0 ) ;
else
return F_98 ( V_80 , V_203 ,
V_199 ,
( char * ) L_37 , ( char * ) V_204 -> V_136 , 0 ) ;
}
int F_104 ( struct V_79 * * V_205 ,
struct V_79 * V_80 )
{
return F_98 ( V_205 , V_80 -> V_201 , V_80 -> V_81 , V_80 -> V_12 ,
V_80 -> V_84 . V_23 , V_80 -> V_84 . V_85 ) ;
}
void F_76 ( struct V_29 * V_157 )
{
struct V_79 * V_80 , * V_206 ;
F_105 (term, h, terms, list)
free ( V_80 ) ;
}
