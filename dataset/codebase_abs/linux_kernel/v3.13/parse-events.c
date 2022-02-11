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
free ( V_13 -> system ) ;
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
struct V_11 * F_13 ( const char * V_22 )
{
struct V_11 * V_13 = F_12 ( sizeof( * V_13 ) ) ;
char * V_23 = strchr ( V_22 , ':' ) ;
if ( V_13 == NULL || V_23 == NULL ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> system = F_14 ( V_22 , V_23 - V_22 ) ;
V_13 -> V_22 = F_15 ( V_23 + 1 ) ;
if ( V_13 -> system == NULL || V_13 -> V_22 == NULL ) {
free ( V_13 -> system ) ;
free ( V_13 -> V_22 ) ;
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
static int F_17 ( struct V_28 * V_29 , int * V_30 ,
struct V_31 * V_32 ,
char * V_22 , struct V_33 * V_34 )
{
struct V_35 * V_36 ;
F_18 ( V_32 ) ;
V_36 = F_19 ( V_32 , ( * V_30 ) ++ ) ;
if ( ! V_36 )
return - V_37 ;
V_36 -> V_34 = V_34 ;
if ( V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
F_20 ( & V_36 -> V_38 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int * V_30 ,
struct V_31 * V_32 , char * V_22 )
{
return F_17 ( V_29 , V_30 , V_32 , V_22 , NULL ) ;
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
int F_23 ( struct V_28 * V_29 , int * V_30 ,
char * type , char * V_46 , char * V_47 )
{
struct V_31 V_32 ;
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
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_12 = V_49 | ( V_50 << 8 ) | ( V_51 << 16 ) ;
V_32 . type = V_27 ;
return F_21 ( V_29 , V_30 , & V_32 , V_22 ) ;
}
static int F_25 ( struct V_28 * V_29 , int * V_30 ,
char * V_61 , char * V_62 )
{
struct V_35 * V_36 ;
V_36 = F_26 ( V_61 , V_62 , ( * V_30 ) ++ ) ;
if ( ! V_36 )
return - V_37 ;
F_20 ( & V_36 -> V_38 , V_29 ) ;
return 0 ;
}
static int F_27 ( struct V_28 * V_29 , int * V_30 ,
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
while ( ! V_64 && ( V_63 = F_28 ( V_3 ) ) ) {
if ( ! strcmp ( V_63 -> V_8 , L_12 )
|| ! strcmp ( V_63 -> V_8 , L_13 )
|| ! strcmp ( V_63 -> V_8 , L_14 )
|| ! strcmp ( V_63 -> V_8 , L_15 ) )
continue;
if ( ! F_29 ( V_63 -> V_8 , V_62 ) )
continue;
V_64 = F_25 ( V_29 , V_30 , V_61 , V_63 -> V_8 ) ;
}
F_11 ( V_3 ) ;
return V_64 ;
}
static int F_30 ( struct V_28 * V_29 , int * V_30 ,
char * V_61 , char * V_62 )
{
return strpbrk ( V_62 , L_16 ) ?
F_27 ( V_29 , V_30 , V_61 , V_62 ) :
F_25 ( V_29 , V_30 , V_61 , V_62 ) ;
}
static int F_31 ( struct V_28 * V_29 , int * V_30 ,
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
while ( ! V_64 && ( V_65 = F_28 ( V_66 ) ) ) {
if ( ! strcmp ( V_65 -> V_8 , L_12 )
|| ! strcmp ( V_65 -> V_8 , L_13 )
|| ! strcmp ( V_65 -> V_8 , L_14 )
|| ! strcmp ( V_65 -> V_8 , L_17 )
|| ! strcmp ( V_65 -> V_8 , L_18 ) )
continue;
if ( ! F_29 ( V_65 -> V_8 , V_61 ) )
continue;
V_64 = F_30 ( V_29 , V_30 , V_65 -> V_8 ,
V_62 ) ;
}
F_11 ( V_66 ) ;
return V_64 ;
}
int F_32 ( struct V_28 * V_29 , int * V_30 ,
char * V_67 , char * V_68 )
{
int V_64 ;
V_64 = F_5 ( V_7 ) ;
if ( V_64 )
return V_64 ;
if ( strpbrk ( V_67 , L_16 ) )
return F_31 ( V_29 , V_30 , V_67 , V_68 ) ;
else
return F_30 ( V_29 , V_30 , V_67 , V_68 ) ;
}
static int
F_33 ( const char * type , struct V_31 * V_32 )
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
if ( ! V_32 -> V_72 )
V_32 -> V_72 = V_69 | V_70 ;
return 0 ;
}
int F_35 ( struct V_28 * V_29 , int * V_30 ,
void * V_73 , char * type )
{
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_74 = ( unsigned long ) V_73 ;
if ( F_33 ( type , & V_32 ) )
return - V_10 ;
if ( V_32 . V_72 == V_71 )
V_32 . V_75 = sizeof( long ) ;
else
V_32 . V_75 = V_76 ;
V_32 . type = V_77 ;
V_32 . V_78 = 1 ;
return F_21 ( V_29 , V_30 , & V_32 , NULL ) ;
}
static int F_36 ( struct V_31 * V_32 ,
struct V_79 * V_80 )
{
#define F_37 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_80 -> V_81 ) {
case V_82 :
F_37 ( V_83 ) ;
V_32 -> V_12 = V_80 -> V_84 . V_85 ;
break;
case V_86 :
F_37 ( V_83 ) ;
V_32 -> V_87 = V_80 -> V_84 . V_85 ;
break;
case V_88 :
F_37 ( V_83 ) ;
V_32 -> V_89 = V_80 -> V_84 . V_85 ;
break;
case V_90 :
F_37 ( V_83 ) ;
V_32 -> V_78 = V_80 -> V_84 . V_85 ;
break;
case V_91 :
break;
case V_92 :
F_37 ( V_93 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_37
}
static int F_38 ( struct V_31 * V_32 ,
struct V_28 * V_94 , int V_95 )
{
struct V_79 * V_80 ;
F_39 (term, head, list)
if ( F_36 ( V_32 , V_80 ) && V_95 )
return - V_10 ;
return 0 ;
}
int F_40 ( struct V_28 * V_29 , int * V_30 ,
T_4 type , T_1 V_12 ,
struct V_28 * V_96 )
{
struct V_31 V_32 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . type = type ;
V_32 . V_12 = V_12 ;
if ( V_96 &&
F_38 ( & V_32 , V_96 , 1 ) )
return - V_10 ;
return F_21 ( V_29 , V_30 , & V_32 , NULL ) ;
}
static int F_41 ( struct V_79 * V_80 )
{
return V_80 -> V_81 == V_92 ;
}
static char * F_42 ( struct V_28 * V_97 )
{
struct V_79 * V_80 ;
F_39 (term, head_terms, list)
if ( F_41 ( V_80 ) )
return V_80 -> V_84 . V_23 ;
return NULL ;
}
int F_43 ( struct V_28 * V_29 , int * V_30 ,
char * V_22 , struct V_28 * V_96 )
{
struct V_31 V_32 ;
struct V_98 * V_99 ;
V_99 = F_44 ( V_22 ) ;
if ( ! V_99 )
return - V_10 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
if ( F_45 ( V_99 , V_96 ) )
return - V_10 ;
F_38 ( & V_32 , V_96 , 0 ) ;
if ( F_46 ( V_99 , & V_32 , V_96 ) )
return - V_10 ;
return F_17 ( V_29 , V_30 , & V_32 , F_42 ( V_96 ) ,
V_99 -> V_34 ) ;
}
int F_47 ( struct V_28 * V_29 ,
char * V_100 )
{
return F_48 ( V_29 , V_100 , true ) ;
}
void F_49 ( char * V_22 , struct V_28 * V_29 )
{
struct V_35 * V_101 ;
F_50 ( V_29 ) ;
V_101 = F_51 ( V_29 -> V_102 , struct V_35 , V_38 ) ;
V_101 -> V_103 = V_22 ? F_15 ( V_22 ) : NULL ;
}
void F_52 ( struct V_28 * V_104 ,
struct V_28 * V_105 )
{
F_53 ( V_104 , V_105 ) ;
free ( V_104 ) ;
}
static int F_54 ( struct V_106 * V_107 , char * V_23 ,
struct V_35 * V_36 )
{
int V_108 = V_36 ? V_36 -> V_32 . V_109 : 0 ;
int V_110 = V_36 ? V_36 -> V_32 . V_111 : 0 ;
int V_112 = V_36 ? V_36 -> V_32 . V_113 : 0 ;
int V_114 = V_36 ? V_36 -> V_32 . V_115 : 0 ;
int V_116 = V_36 ? V_36 -> V_32 . V_117 : 0 ;
int V_118 = V_36 ? V_36 -> V_32 . V_119 : 0 ;
int V_120 = 0 ;
int V_121 = V_36 ? V_36 -> V_32 . V_121 : 0 ;
int V_122 = V_108 | V_110 | V_112 ;
int V_123 = V_36 ? V_36 -> V_123 : 0 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
while ( * V_23 ) {
if ( * V_23 == 'u' ) {
if ( ! V_122 )
V_122 = V_108 = V_110 = V_112 = 1 ;
V_108 = 0 ;
} else if ( * V_23 == 'k' ) {
if ( ! V_122 )
V_122 = V_108 = V_110 = V_112 = 1 ;
V_110 = 0 ;
} else if ( * V_23 == 'h' ) {
if ( ! V_122 )
V_122 = V_108 = V_110 = V_112 = 1 ;
V_112 = 0 ;
} else if ( * V_23 == 'G' ) {
if ( ! V_123 )
V_123 = V_116 = V_114 = 1 ;
V_116 = 0 ;
} else if ( * V_23 == 'H' ) {
if ( ! V_123 )
V_123 = V_116 = V_114 = 1 ;
V_114 = 0 ;
} else if ( * V_23 == 'p' ) {
V_118 ++ ;
if ( ! V_123 )
V_116 = 1 ;
} else if ( * V_23 == 'S' ) {
V_120 = 1 ;
} else if ( * V_23 == 'D' ) {
V_121 = 1 ;
} else
break;
++ V_23 ;
}
if ( V_118 > 3 )
return - V_10 ;
V_107 -> V_108 = V_108 ;
V_107 -> V_110 = V_110 ;
V_107 -> V_112 = V_112 ;
V_107 -> V_114 = V_114 ;
V_107 -> V_116 = V_116 ;
V_107 -> V_118 = V_118 ;
V_107 -> V_123 = V_123 ;
V_107 -> V_120 = V_120 ;
V_107 -> V_121 = V_121 ;
return 0 ;
}
static int F_55 ( char * V_23 )
{
char * V_124 = V_23 ;
if ( strlen ( V_23 ) > ( sizeof( L_19 ) - 1 ) )
return - 1 ;
while ( * V_124 ) {
if ( * V_124 != 'p' && strchr ( V_124 + 1 , * V_124 ) )
return - 1 ;
V_124 ++ ;
}
return 0 ;
}
int F_48 ( struct V_28 * V_29 , char * V_23 , bool V_125 )
{
struct V_35 * V_36 ;
struct V_106 V_107 ;
if ( V_23 == NULL )
return 0 ;
if ( F_55 ( V_23 ) )
return - V_10 ;
if ( ! V_125 && F_54 ( & V_107 , V_23 , NULL ) )
return - V_10 ;
F_39 (evsel, list, node) {
if ( V_125 && F_54 ( & V_107 , V_23 , V_36 ) )
return - V_10 ;
V_36 -> V_32 . V_109 = V_107 . V_108 ;
V_36 -> V_32 . V_111 = V_107 . V_110 ;
V_36 -> V_32 . V_113 = V_107 . V_112 ;
V_36 -> V_32 . V_119 = V_107 . V_118 ;
V_36 -> V_32 . V_115 = V_107 . V_114 ;
V_36 -> V_32 . V_117 = V_107 . V_116 ;
V_36 -> V_123 = V_107 . V_123 ;
V_36 -> V_120 = V_107 . V_120 ;
if ( F_56 ( V_36 ) )
V_36 -> V_32 . V_121 = V_107 . V_121 ;
}
return 0 ;
}
int F_57 ( struct V_28 * V_29 , char * V_22 )
{
struct V_35 * V_36 ;
F_39 (evsel, list, node) {
if ( ! V_36 -> V_22 )
V_36 -> V_22 = F_15 ( V_22 ) ;
}
return 0 ;
}
static int F_58 ( int V_64 , const char * V_23 , void * V_126 ,
int V_127 )
{
char * V_128 = F_15 ( V_23 ) ;
char * V_129 = NULL ;
char * V_130 = V_128 ;
char * V_124 ;
int V_131 = 0 ;
if ( ! V_128 )
return V_64 ;
while ( ( V_124 = F_59 ( & V_130 , L_20 ) ) != NULL ) {
if ( V_129 )
F_60 ( & V_129 , & V_131 , L_20 ) ;
F_60 ( & V_129 , & V_131 , L_21 ) ;
F_60 ( & V_129 , & V_131 , V_124 ) ;
F_60 ( & V_129 , & V_131 , L_22 ) ;
}
free ( V_128 ) ;
if ( ! V_129 )
return - V_37 ;
return F_61 ( V_129 , V_126 , V_127 ) ;
}
static int F_61 ( const char * V_23 , void * V_126 , int V_127 )
{
T_5 V_132 ;
void * V_133 ;
int V_64 ;
V_64 = F_62 ( V_127 , & V_133 ) ;
if ( V_64 )
return V_64 ;
V_132 = F_63 ( V_23 , V_133 ) ;
#ifdef F_64
V_134 = 1 ;
#endif
V_64 = F_65 ( V_126 , V_133 ) ;
F_66 ( V_132 , V_133 ) ;
F_67 ( V_132 , V_133 ) ;
F_68 ( V_133 ) ;
if ( V_64 && ! strchr ( V_23 , '/' ) )
V_64 = F_58 ( V_64 , V_23 , V_126 , V_127 ) ;
return V_64 ;
}
int F_69 ( struct V_28 * V_135 , const char * V_23 )
{
struct F_69 V_126 = {
. V_135 = NULL ,
} ;
int V_64 ;
V_64 = F_61 ( V_23 , & V_126 , V_136 ) ;
if ( ! V_64 ) {
F_70 ( V_126 . V_135 , V_135 ) ;
free ( V_126 . V_135 ) ;
return 0 ;
}
if ( V_126 . V_135 )
F_71 ( V_126 . V_135 ) ;
return V_64 ;
}
int F_72 ( struct V_137 * V_138 , const char * V_23 )
{
struct V_139 V_126 = {
. V_29 = F_73 ( V_126 . V_29 ) ,
. V_30 = V_138 -> V_140 ,
} ;
int V_64 ;
V_64 = F_61 ( V_23 , & V_126 , V_141 ) ;
if ( ! V_64 ) {
int V_142 = V_126 . V_30 - V_138 -> V_140 ;
F_74 ( V_138 , & V_126 . V_29 , V_142 ) ;
V_138 -> V_143 += V_126 . V_143 ;
return 0 ;
}
return V_64 ;
}
int F_75 ( const struct V_144 * V_145 , const char * V_23 ,
int T_6 V_146 )
{
struct V_137 * V_138 = * (struct V_137 * * ) V_145 -> V_147 ;
int V_64 = F_72 ( V_138 , V_23 ) ;
if ( V_64 ) {
fprintf ( V_148 , L_23 , V_23 ) ;
fprintf ( V_148 , L_24 ) ;
}
return V_64 ;
}
int F_76 ( const struct V_144 * V_145 , const char * V_23 ,
int T_6 V_146 )
{
struct V_137 * V_138 = * (struct V_137 * * ) V_145 -> V_147 ;
struct V_35 * V_149 = NULL ;
if ( V_138 -> V_140 > 0 )
V_149 = F_77 ( V_138 ) ;
if ( V_149 == NULL || V_149 -> V_32 . type != V_26 ) {
fprintf ( V_148 ,
L_25 ) ;
return - 1 ;
}
V_149 -> V_150 = F_15 ( V_23 ) ;
if ( V_149 -> V_150 == NULL ) {
fprintf ( V_148 , L_26 ) ;
return - 1 ;
}
return 0 ;
}
void F_78 ( const char * V_151 , const char * V_152 ,
bool V_153 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) ) {
printf ( L_27 , strerror ( V_154 ) ) ;
return;
}
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return;
F_7 (sys_dir, sys_dirent, sys_next) {
if ( V_151 != NULL &&
! F_29 ( V_16 . V_8 , V_151 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_152 != NULL &&
! F_29 ( V_17 . V_8 , V_152 ) )
continue;
if ( V_153 ) {
printf ( L_28 , V_16 . V_8 , V_17 . V_8 ) ;
continue;
}
snprintf ( V_4 , V_5 , L_29 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_30 , V_4 ,
V_155 [ V_26 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_79 ( const char * V_156 )
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
snprintf ( V_4 , V_5 , L_29 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_156 ) ) {
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
static bool F_80 ( T_7 type , unsigned V_12 )
{
bool V_64 = true ;
struct V_35 * V_36 ;
struct V_31 V_32 = {
. type = type ,
. V_12 = V_12 ,
. V_157 = 1 ,
. V_111 = 1 ,
} ;
struct {
struct V_158 V_159 ;
int V_160 [ 1 ] ;
} V_161 = {
. V_159 . V_162 = 1 ,
. V_160 = { 0 } ,
} ;
V_36 = F_81 ( & V_32 ) ;
if ( V_36 ) {
V_64 = F_82 ( V_36 , NULL , & V_161 . V_159 ) >= 0 ;
F_83 ( V_36 ) ;
}
return V_64 ;
}
static void F_84 ( T_7 type , struct V_163 * V_164 ,
unsigned V_165 )
{
char V_22 [ 64 ] ;
unsigned V_42 ;
for ( V_42 = 0 ; V_42 < V_165 ; V_42 ++ , V_164 ++ ) {
if ( ! F_80 ( type , V_42 ) )
continue;
if ( strlen ( V_164 -> V_166 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_31 ,
V_164 -> V_167 , V_164 -> V_166 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_164 -> V_167 ) ;
printf ( L_30 , V_22 , V_155 [ type ] ) ;
}
}
void F_85 ( T_7 type )
{
if ( type == V_25 )
F_84 ( type , V_168 , V_169 ) ;
else
F_84 ( type , V_170 , V_171 ) ;
}
int F_86 ( const char * V_152 , bool V_153 )
{
unsigned int type , V_172 , V_42 , V_173 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_54 ; type ++ ) {
for ( V_172 = 0 ; V_172 < V_56 ; V_172 ++ ) {
if ( ! F_24 ( type , V_172 ) )
continue;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
F_87 ( type , V_172 , V_42 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_152 != NULL && ! F_29 ( V_22 , V_152 ) )
continue;
if ( ! F_80 ( V_27 ,
type | ( V_172 << 8 ) | ( V_42 << 16 ) ) )
continue;
if ( V_153 )
printf ( L_32 , V_22 ) ;
else
printf ( L_30 , V_22 ,
V_155 [ V_27 ] ) ;
++ V_173 ;
}
}
}
if ( V_173 )
printf ( L_33 ) ;
return V_173 ;
}
static void F_88 ( const char * V_152 , unsigned type ,
struct V_163 * V_164 , unsigned V_165 ,
bool V_153 )
{
unsigned V_42 , V_173 = 0 ;
char V_22 [ V_48 ] ;
for ( V_42 = 0 ; V_42 < V_165 ; V_42 ++ , V_164 ++ ) {
if ( V_152 != NULL &&
! ( F_29 ( V_164 -> V_167 , V_152 ) ||
( V_164 -> V_166 && F_29 ( V_164 -> V_166 , V_152 ) ) ) )
continue;
if ( ! F_80 ( type , V_42 ) )
continue;
if ( V_153 ) {
printf ( L_32 , V_164 -> V_167 ) ;
continue;
}
if ( strlen ( V_164 -> V_166 ) )
snprintf ( V_22 , V_48 , L_31 , V_164 -> V_167 , V_164 -> V_166 ) ;
else
strncpy ( V_22 , V_164 -> V_167 , V_48 ) ;
printf ( L_30 , V_22 , V_155 [ type ] ) ;
V_173 ++ ;
}
if ( V_173 )
printf ( L_33 ) ;
}
void F_89 ( const char * V_152 , bool V_153 )
{
if ( ! V_153 ) {
printf ( L_33 ) ;
printf ( L_34 ) ;
}
F_88 ( V_152 , V_24 ,
V_170 , V_171 , V_153 ) ;
F_88 ( V_152 , V_25 ,
V_168 , V_169 , V_153 ) ;
F_86 ( V_152 , V_153 ) ;
F_90 ( V_152 , V_153 ) ;
if ( V_152 != NULL )
return;
if ( ! V_153 ) {
printf ( L_30 ,
L_35 ,
V_155 [ V_174 ] ) ;
printf ( L_30 ,
L_36 ,
V_155 [ V_174 ] ) ;
printf ( L_37 ) ;
printf ( L_33 ) ;
printf ( L_30 ,
L_38 ,
V_155 [ V_77 ] ) ;
printf ( L_33 ) ;
}
F_78 ( NULL , NULL , V_153 ) ;
}
int F_91 ( struct V_79 * V_80 )
{
return V_80 -> V_81 != V_175 ;
}
static int F_92 ( struct V_79 * * V_176 , int V_177 ,
int V_81 , char * V_12 ,
char * V_23 , T_1 V_85 )
{
struct V_79 * V_80 ;
V_80 = F_12 ( sizeof( * V_80 ) ) ;
if ( ! V_80 )
return - V_37 ;
F_93 ( & V_80 -> V_29 ) ;
V_80 -> V_177 = V_177 ;
V_80 -> V_81 = V_81 ;
V_80 -> V_12 = V_12 ;
switch ( V_177 ) {
case V_178 :
V_80 -> V_84 . V_85 = V_85 ;
break;
case V_179 :
V_80 -> V_84 . V_23 = V_23 ;
break;
default:
free ( V_80 ) ;
return - V_10 ;
}
* V_176 = V_80 ;
return 0 ;
}
int F_94 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , T_1 V_85 )
{
return F_92 ( V_80 , V_178 , V_81 ,
V_12 , NULL , V_85 ) ;
}
int F_95 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , char * V_23 )
{
return F_92 ( V_80 , V_179 , V_81 ,
V_12 , V_23 , 0 ) ;
}
int F_96 ( struct V_79 * * V_80 ,
char * V_12 , unsigned V_30 )
{
struct V_163 * V_180 ;
F_97 ( V_30 >= V_171 ) ;
V_180 = & V_170 [ V_30 ] ;
if ( V_12 )
return F_92 ( V_80 , V_179 ,
V_175 , V_12 ,
( char * ) V_180 -> V_167 , 0 ) ;
else
return F_92 ( V_80 , V_179 ,
V_175 ,
( char * ) L_39 , ( char * ) V_180 -> V_167 , 0 ) ;
}
int F_98 ( struct V_79 * * V_181 ,
struct V_79 * V_80 )
{
return F_92 ( V_181 , V_80 -> V_177 , V_80 -> V_81 , V_80 -> V_12 ,
V_80 -> V_84 . V_23 , V_80 -> V_84 . V_85 ) ;
}
void F_71 ( struct V_28 * V_135 )
{
struct V_79 * V_80 , * V_182 ;
F_99 (term, h, terms, list)
free ( V_80 ) ;
}
