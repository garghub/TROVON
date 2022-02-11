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
const char * F_13 ( int type )
{
switch ( type ) {
case V_23 :
return L_4 ;
case V_24 :
return L_5 ;
case V_25 :
return L_6 ;
case V_26 :
return L_7 ;
default:
break;
}
return L_8 ;
}
static int F_14 ( struct V_27 * * V_28 , int * V_29 ,
struct V_30 * V_31 ,
char * V_22 , struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_27 * V_36 = * V_28 ;
if ( ! V_36 ) {
V_36 = malloc ( sizeof( * V_36 ) ) ;
if ( ! V_36 )
return - V_37 ;
F_15 ( V_36 ) ;
}
F_16 ( V_31 ) ;
V_35 = F_17 ( V_31 , ( * V_29 ) ++ ) ;
if ( ! V_35 ) {
free ( V_36 ) ;
return - V_37 ;
}
V_35 -> V_33 = V_33 ;
if ( V_22 )
V_35 -> V_22 = F_18 ( V_22 ) ;
F_19 ( & V_35 -> V_38 , V_36 ) ;
* V_28 = V_36 ;
return 0 ;
}
static int F_20 ( struct V_27 * * V_28 , int * V_29 ,
struct V_30 * V_31 , char * V_22 )
{
return F_14 ( V_28 , V_29 , V_31 , V_22 , NULL ) ;
}
static int F_21 ( char * V_39 , const char * V_40 [] [ V_41 ] , int V_42 )
{
int V_43 , V_44 ;
int V_45 , V_46 = - 1 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
for ( V_44 = 0 ; V_44 < V_41 && V_40 [ V_43 ] [ V_44 ] ; V_44 ++ ) {
V_45 = strlen ( V_40 [ V_43 ] [ V_44 ] ) ;
if ( V_45 > V_46 && ! strncasecmp ( V_39 , V_40 [ V_43 ] [ V_44 ] , V_45 ) )
V_46 = V_45 ;
}
if ( V_46 > 0 )
return V_43 ;
}
return - 1 ;
}
int F_22 ( struct V_27 * * V_36 , int * V_29 ,
char * type , char * V_47 , char * V_48 )
{
struct V_30 V_31 ;
char V_22 [ V_49 ] ;
int V_50 = - 1 , V_51 = - 1 , V_52 = - 1 ;
char * V_53 [ 2 ] = { V_47 , V_48 } ;
int V_43 , V_45 ;
V_50 = F_21 ( type , V_54 ,
V_55 ) ;
if ( V_50 == - 1 )
return - V_10 ;
V_45 = snprintf ( V_22 , V_49 , L_9 , type ) ;
for ( V_43 = 0 ; ( V_43 < 2 ) && ( V_53 [ V_43 ] ) ; V_43 ++ ) {
char * V_39 = V_53 [ V_43 ] ;
V_45 += snprintf ( V_22 + V_45 , V_49 - V_45 , L_10 , V_39 ) ;
if ( V_51 == - 1 ) {
V_51 = F_21 ( V_39 , V_56 ,
V_57 ) ;
if ( V_51 >= 0 ) {
if ( ! F_23 ( V_50 , V_51 ) )
return - V_10 ;
continue;
}
}
if ( V_52 == - 1 ) {
V_52 = F_21 ( V_39 , V_58 ,
V_59 ) ;
if ( V_52 >= 0 )
continue;
}
}
if ( V_51 == - 1 )
V_51 = V_60 ;
if ( V_52 == - 1 )
V_52 = V_61 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_12 = V_50 | ( V_51 << 8 ) | ( V_52 << 16 ) ;
V_31 . type = V_26 ;
return F_20 ( V_36 , V_29 , & V_31 , V_22 ) ;
}
static int F_24 ( struct V_27 * * V_62 , int * V_29 ,
char * V_63 , char * V_64 )
{
struct V_34 * V_35 ;
struct V_27 * V_36 = * V_62 ;
if ( ! V_36 ) {
V_36 = malloc ( sizeof( * V_36 ) ) ;
if ( ! V_36 )
return - V_37 ;
F_15 ( V_36 ) ;
}
V_35 = F_25 ( V_63 , V_64 , ( * V_29 ) ++ ) ;
if ( ! V_35 ) {
free ( V_36 ) ;
return - V_37 ;
}
F_19 ( & V_35 -> V_38 , V_36 ) ;
* V_62 = V_36 ;
return 0 ;
}
static int F_26 ( struct V_27 * * V_36 , int * V_29 ,
char * V_63 , char * V_64 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_65 ;
T_2 * V_3 ;
int V_66 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_63 ) ;
V_3 = F_6 ( V_4 ) ;
if ( ! V_3 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_66 && ( V_65 = F_27 ( V_3 ) ) ) {
if ( ! strcmp ( V_65 -> V_8 , L_12 )
|| ! strcmp ( V_65 -> V_8 , L_13 )
|| ! strcmp ( V_65 -> V_8 , L_14 )
|| ! strcmp ( V_65 -> V_8 , L_15 ) )
continue;
if ( ! F_28 ( V_65 -> V_8 , V_64 ) )
continue;
V_66 = F_24 ( V_36 , V_29 , V_63 , V_65 -> V_8 ) ;
}
return V_66 ;
}
int F_29 ( struct V_27 * * V_36 , int * V_29 ,
char * V_67 , char * V_68 )
{
int V_66 ;
V_66 = F_5 ( V_7 ) ;
if ( V_66 )
return V_66 ;
return strpbrk ( V_68 , L_16 ) ?
F_26 ( V_36 , V_29 , V_67 , V_68 ) :
F_24 ( V_36 , V_29 , V_67 , V_68 ) ;
}
static int
F_30 ( const char * type , struct V_30 * V_31 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
if ( ! type || ! type [ V_43 ] )
break;
#define F_31 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_43 ] ) {
case 'r' :
F_31 ( V_69 ) ;
break;
case 'w' :
F_31 ( V_70 ) ;
break;
case 'x' :
F_31 ( V_71 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_31
if ( ! V_31 -> V_72 )
V_31 -> V_72 = V_69 | V_70 ;
return 0 ;
}
int F_32 ( struct V_27 * * V_36 , int * V_29 ,
void * V_73 , char * type )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_74 = ( unsigned long ) V_73 ;
if ( F_30 ( type , & V_31 ) )
return - V_10 ;
if ( V_31 . V_72 == V_71 )
V_31 . V_75 = sizeof( long ) ;
else
V_31 . V_75 = V_76 ;
V_31 . type = V_77 ;
V_31 . V_78 = 1 ;
return F_20 ( V_36 , V_29 , & V_31 , NULL ) ;
}
static int F_33 ( struct V_30 * V_31 ,
struct V_79 * V_80 )
{
#define F_34 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_80 -> V_81 ) {
case V_82 :
F_34 ( V_83 ) ;
V_31 -> V_12 = V_80 -> V_84 . V_85 ;
break;
case V_86 :
F_34 ( V_83 ) ;
V_31 -> V_87 = V_80 -> V_84 . V_85 ;
break;
case V_88 :
F_34 ( V_83 ) ;
V_31 -> V_89 = V_80 -> V_84 . V_85 ;
break;
case V_90 :
F_34 ( V_83 ) ;
V_31 -> V_78 = V_80 -> V_84 . V_85 ;
break;
case V_91 :
break;
case V_92 :
F_34 ( V_93 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_34
}
static int F_35 ( struct V_30 * V_31 ,
struct V_27 * V_94 , int V_95 )
{
struct V_79 * V_80 ;
F_36 (term, head, list)
if ( F_33 ( V_31 , V_80 ) && V_95 )
return - V_10 ;
return 0 ;
}
int F_37 ( struct V_27 * * V_36 , int * V_29 ,
T_4 type , T_1 V_12 ,
struct V_27 * V_96 )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . type = type ;
V_31 . V_12 = V_12 ;
if ( V_96 &&
F_35 ( & V_31 , V_96 , 1 ) )
return - V_10 ;
return F_20 ( V_36 , V_29 , & V_31 , NULL ) ;
}
static int F_38 ( struct V_79 * V_80 )
{
return V_80 -> V_81 == V_92 ;
}
static char * F_39 ( struct V_27 * V_97 )
{
struct V_79 * V_80 ;
F_36 (term, head_terms, list)
if ( F_38 ( V_80 ) )
return V_80 -> V_84 . V_39 ;
return NULL ;
}
int F_40 ( struct V_27 * * V_36 , int * V_29 ,
char * V_22 , struct V_27 * V_96 )
{
struct V_30 V_31 ;
struct V_98 * V_99 ;
V_99 = F_41 ( V_22 ) ;
if ( ! V_99 )
return - V_10 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_42 ( V_99 , V_96 ) )
return - V_10 ;
F_35 ( & V_31 , V_96 , 0 ) ;
if ( F_43 ( V_99 , & V_31 , V_96 ) )
return - V_10 ;
return F_14 ( V_36 , V_29 , & V_31 , F_39 ( V_96 ) ,
V_99 -> V_33 ) ;
}
int F_44 ( struct V_27 * V_36 ,
char * V_100 )
{
return F_45 ( V_36 , V_100 , true ) ;
}
void F_46 ( char * V_22 , struct V_27 * V_36 )
{
struct V_34 * V_101 ;
F_47 ( V_36 ) ;
V_101 = F_48 ( V_36 -> V_102 , struct V_34 , V_38 ) ;
V_101 -> V_103 = V_22 ? F_18 ( V_22 ) : NULL ;
}
void F_49 ( struct V_27 * V_104 ,
struct V_27 * V_105 )
{
F_50 ( V_104 , V_105 ) ;
free ( V_104 ) ;
}
static int F_51 ( struct V_106 * V_107 , char * V_39 ,
struct V_34 * V_35 )
{
int V_108 = V_35 ? V_35 -> V_31 . V_109 : 0 ;
int V_110 = V_35 ? V_35 -> V_31 . V_111 : 0 ;
int V_112 = V_35 ? V_35 -> V_31 . V_113 : 0 ;
int V_114 = V_35 ? V_35 -> V_31 . V_115 : 0 ;
int V_116 = V_35 ? V_35 -> V_31 . V_117 : 0 ;
int V_118 = V_35 ? V_35 -> V_31 . V_119 : 0 ;
int V_120 = V_108 | V_110 | V_112 ;
int V_121 = V_35 ? V_35 -> V_121 : 0 ;
if ( V_35 && ! V_121 )
V_114 = V_116 = 0 ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
while ( * V_39 ) {
if ( * V_39 == 'u' ) {
if ( ! V_120 )
V_120 = V_108 = V_110 = V_112 = 1 ;
V_108 = 0 ;
} else if ( * V_39 == 'k' ) {
if ( ! V_120 )
V_120 = V_108 = V_110 = V_112 = 1 ;
V_110 = 0 ;
} else if ( * V_39 == 'h' ) {
if ( ! V_120 )
V_120 = V_108 = V_110 = V_112 = 1 ;
V_112 = 0 ;
} else if ( * V_39 == 'G' ) {
if ( ! V_121 )
V_121 = V_116 = V_114 = 1 ;
V_116 = 0 ;
} else if ( * V_39 == 'H' ) {
if ( ! V_121 )
V_121 = V_116 = V_114 = 1 ;
V_114 = 0 ;
} else if ( * V_39 == 'p' ) {
V_118 ++ ;
if ( ! V_121 )
V_116 = 1 ;
} else
break;
++ V_39 ;
}
if ( V_118 > 3 )
return - V_10 ;
V_107 -> V_108 = V_108 ;
V_107 -> V_110 = V_110 ;
V_107 -> V_112 = V_112 ;
V_107 -> V_114 = V_114 ;
V_107 -> V_116 = V_116 ;
V_107 -> V_118 = V_118 ;
V_107 -> V_121 = V_121 ;
return 0 ;
}
static int F_52 ( char * V_39 )
{
char * V_122 = V_39 ;
if ( strlen ( V_39 ) > ( sizeof( L_17 ) - 1 ) )
return - 1 ;
while ( * V_122 ) {
if ( * V_122 != 'p' && strchr ( V_122 + 1 , * V_122 ) )
return - 1 ;
V_122 ++ ;
}
return 0 ;
}
int F_45 ( struct V_27 * V_36 , char * V_39 , bool V_123 )
{
struct V_34 * V_35 ;
struct V_106 V_107 ;
if ( V_39 == NULL )
return 0 ;
if ( F_52 ( V_39 ) )
return - V_10 ;
if ( ! V_123 && F_51 ( & V_107 , V_39 , NULL ) )
return - V_10 ;
F_36 (evsel, list, node) {
if ( V_123 && F_51 ( & V_107 , V_39 , V_35 ) )
return - V_10 ;
V_35 -> V_31 . V_109 = V_107 . V_108 ;
V_35 -> V_31 . V_111 = V_107 . V_110 ;
V_35 -> V_31 . V_113 = V_107 . V_112 ;
V_35 -> V_31 . V_119 = V_107 . V_118 ;
V_35 -> V_31 . V_115 = V_107 . V_114 ;
V_35 -> V_31 . V_117 = V_107 . V_116 ;
V_35 -> V_121 = V_107 . V_121 ;
}
return 0 ;
}
int F_53 ( struct V_27 * V_36 , char * V_22 )
{
struct V_34 * V_35 ;
F_36 (evsel, list, node) {
if ( ! V_35 -> V_22 )
V_35 -> V_22 = F_18 ( V_22 ) ;
}
return 0 ;
}
static int F_54 ( const char * V_39 , void * V_124 , int V_125 )
{
T_5 V_126 ;
void * V_127 ;
int V_66 ;
V_66 = F_55 ( V_125 , & V_127 ) ;
if ( V_66 )
return V_66 ;
V_126 = F_56 ( V_39 , V_127 ) ;
#ifdef F_57
V_128 = 1 ;
#endif
V_66 = F_58 ( V_124 , V_127 ) ;
F_59 ( V_126 , V_127 ) ;
F_60 ( V_126 , V_127 ) ;
F_61 ( V_127 ) ;
return V_66 ;
}
int F_62 ( struct V_27 * V_129 , const char * V_39 )
{
struct V_130 V_124 = {
. V_129 = NULL ,
} ;
int V_66 ;
V_66 = F_54 ( V_39 , & V_124 , V_131 ) ;
if ( ! V_66 ) {
F_63 ( V_124 . V_129 , V_129 ) ;
free ( V_124 . V_129 ) ;
return 0 ;
}
F_64 ( V_124 . V_129 ) ;
return V_66 ;
}
int F_65 ( struct V_132 * V_133 , const char * V_39 ,
int T_6 V_134 )
{
struct V_135 V_124 = {
. V_36 = F_66 ( V_124 . V_36 ) ,
. V_29 = V_133 -> V_136 ,
} ;
int V_66 ;
V_66 = F_54 ( V_39 , & V_124 , V_137 ) ;
if ( ! V_66 ) {
int V_138 = V_124 . V_29 - V_133 -> V_136 ;
F_67 ( V_133 , & V_124 . V_36 , V_138 ) ;
return 0 ;
}
return V_66 ;
}
int F_68 ( const struct V_139 * V_140 , const char * V_39 ,
int T_6 V_134 )
{
struct V_132 * V_133 = * (struct V_132 * * ) V_140 -> V_141 ;
int V_66 = F_65 ( V_133 , V_39 , T_6 ) ;
if ( V_66 ) {
fprintf ( V_142 , L_18 , V_39 ) ;
fprintf ( V_142 , L_19 ) ;
}
return V_66 ;
}
int F_69 ( const struct V_139 * V_140 , const char * V_39 ,
int T_6 V_134 )
{
struct V_132 * V_133 = * (struct V_132 * * ) V_140 -> V_141 ;
struct V_34 * V_143 = NULL ;
if ( V_133 -> V_136 > 0 )
V_143 = F_70 ( V_133 ) ;
if ( V_143 == NULL || V_143 -> V_31 . type != V_25 ) {
fprintf ( V_142 ,
L_20 ) ;
return - 1 ;
}
V_143 -> V_144 = F_18 ( V_39 ) ;
if ( V_143 -> V_144 == NULL ) {
fprintf ( V_142 , L_21 ) ;
return - 1 ;
}
return 0 ;
}
void F_71 ( const char * V_145 , const char * V_146 ,
bool V_147 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 , V_16 , V_17 ;
char V_4 [ V_5 ] ;
char V_20 [ V_5 ] ;
if ( F_5 ( V_7 ) )
return;
V_2 = F_6 ( V_7 ) ;
if ( ! V_2 )
return;
F_7 (sys_dir, sys_dirent, sys_next) {
if ( V_145 != NULL &&
! F_28 ( V_16 . V_8 , V_145 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_146 != NULL &&
! F_28 ( V_17 . V_8 , V_146 ) )
continue;
if ( V_147 ) {
printf ( L_22 , V_16 . V_8 , V_17 . V_8 ) ;
continue;
}
snprintf ( V_4 , V_5 , L_23 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_24 , V_4 ,
V_148 [ V_25 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_72 ( const char * V_149 )
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
snprintf ( V_4 , V_5 , L_23 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_149 ) ) {
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
static void F_73 ( T_7 type , struct V_150 * V_151 ,
unsigned V_152 )
{
char V_22 [ 64 ] ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < V_152 ; V_43 ++ , V_151 ++ ) {
if ( strlen ( V_151 -> V_153 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_25 ,
V_151 -> V_154 , V_151 -> V_153 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_151 -> V_154 ) ;
printf ( L_24 , V_22 ,
V_148 [ type ] ) ;
}
}
void F_74 ( T_7 type )
{
if ( type == V_24 )
F_73 ( type , V_155 , V_156 ) ;
else
F_73 ( type , V_157 , V_158 ) ;
}
int F_75 ( const char * V_146 , bool V_147 )
{
unsigned int type , V_159 , V_43 , V_160 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_55 ; type ++ ) {
for ( V_159 = 0 ; V_159 < V_57 ; V_159 ++ ) {
if ( ! F_23 ( type , V_159 ) )
continue;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ ) {
F_76 ( type , V_159 , V_43 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_146 != NULL && ! F_28 ( V_22 , V_146 ) )
continue;
if ( V_147 )
printf ( L_26 , V_22 ) ;
else
printf ( L_24 , V_22 ,
V_148 [ V_26 ] ) ;
++ V_160 ;
}
}
}
return V_160 ;
}
static void F_77 ( const char * V_146 , unsigned type ,
struct V_150 * V_151 , unsigned V_152 ,
bool V_147 )
{
unsigned V_43 , V_160 = 0 ;
char V_22 [ V_49 ] ;
for ( V_43 = 0 ; V_43 < V_152 ; V_43 ++ , V_151 ++ ) {
if ( V_146 != NULL &&
! ( F_28 ( V_151 -> V_154 , V_146 ) ||
( V_151 -> V_153 && F_28 ( V_151 -> V_153 , V_146 ) ) ) )
continue;
if ( V_147 ) {
printf ( L_26 , V_151 -> V_154 ) ;
continue;
}
if ( strlen ( V_151 -> V_153 ) )
snprintf ( V_22 , V_49 , L_25 , V_151 -> V_154 , V_151 -> V_153 ) ;
else
strncpy ( V_22 , V_151 -> V_154 , V_49 ) ;
printf ( L_24 , V_22 , V_148 [ type ] ) ;
V_160 ++ ;
}
if ( V_160 )
printf ( L_27 ) ;
}
void F_78 ( const char * V_146 , bool V_147 )
{
if ( ! V_147 ) {
printf ( L_27 ) ;
printf ( L_28 ) ;
}
F_77 ( V_146 , V_23 ,
V_157 , V_158 , V_147 ) ;
F_77 ( V_146 , V_24 ,
V_155 , V_156 , V_147 ) ;
F_75 ( V_146 , V_147 ) ;
if ( V_146 != NULL )
return;
if ( ! V_147 ) {
printf ( L_27 ) ;
printf ( L_24 ,
L_29 ,
V_148 [ V_161 ] ) ;
printf ( L_24 ,
L_30 ,
V_148 [ V_161 ] ) ;
printf ( L_31 ) ;
printf ( L_27 ) ;
printf ( L_24 ,
L_32 ,
V_148 [ V_77 ] ) ;
printf ( L_27 ) ;
}
F_71 ( NULL , NULL , V_147 ) ;
}
int F_79 ( struct V_79 * V_80 )
{
return V_80 -> V_81 != V_162 ;
}
static int F_80 ( struct V_79 * * V_163 , int V_164 ,
int V_81 , char * V_12 ,
char * V_39 , T_1 V_85 )
{
struct V_79 * V_80 ;
V_80 = F_12 ( sizeof( * V_80 ) ) ;
if ( ! V_80 )
return - V_37 ;
F_15 ( & V_80 -> V_36 ) ;
V_80 -> V_164 = V_164 ;
V_80 -> V_81 = V_81 ;
V_80 -> V_12 = V_12 ;
switch ( V_164 ) {
case V_165 :
V_80 -> V_84 . V_85 = V_85 ;
break;
case V_166 :
V_80 -> V_84 . V_39 = V_39 ;
break;
default:
return - V_10 ;
}
* V_163 = V_80 ;
return 0 ;
}
int F_81 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , T_1 V_85 )
{
return F_80 ( V_80 , V_165 , V_81 ,
V_12 , NULL , V_85 ) ;
}
int F_82 ( struct V_79 * * V_80 ,
int V_81 , char * V_12 , char * V_39 )
{
return F_80 ( V_80 , V_166 , V_81 ,
V_12 , V_39 , 0 ) ;
}
int F_83 ( struct V_79 * * V_80 ,
char * V_12 , unsigned V_29 )
{
struct V_150 * V_167 ;
F_84 ( V_29 >= V_158 ) ;
V_167 = & V_157 [ V_29 ] ;
if ( V_12 )
return F_80 ( V_80 , V_166 ,
V_162 , V_12 ,
( char * ) V_167 -> V_154 , 0 ) ;
else
return F_80 ( V_80 , V_166 ,
V_162 ,
( char * ) L_33 , ( char * ) V_167 -> V_154 , 0 ) ;
}
int F_85 ( struct V_79 * * V_168 ,
struct V_79 * V_80 )
{
return F_80 ( V_168 , V_80 -> V_164 , V_80 -> V_81 , V_80 -> V_12 ,
V_80 -> V_84 . V_39 , V_80 -> V_84 . V_85 ) ;
}
void F_64 ( struct V_27 * V_129 )
{
struct V_79 * V_80 , * V_169 ;
F_86 (term, h, terms, list)
free ( V_80 ) ;
free ( V_129 ) ;
}
