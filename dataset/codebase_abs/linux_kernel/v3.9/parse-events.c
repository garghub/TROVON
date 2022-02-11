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
F_11 ( V_3 ) ;
return V_66 ;
}
static int F_29 ( struct V_27 * * V_36 , int * V_29 ,
char * V_63 , char * V_64 )
{
return strpbrk ( V_64 , L_16 ) ?
F_26 ( V_36 , V_29 , V_63 , V_64 ) :
F_24 ( V_36 , V_29 , V_63 , V_64 ) ;
}
static int F_30 ( struct V_27 * * V_36 , int * V_29 ,
char * V_63 , char * V_64 )
{
struct V_1 * V_67 ;
T_2 * V_68 ;
int V_66 = 0 ;
V_68 = F_6 ( V_7 ) ;
if ( ! V_68 ) {
perror ( L_11 ) ;
return - 1 ;
}
while ( ! V_66 && ( V_67 = F_27 ( V_68 ) ) ) {
if ( ! strcmp ( V_67 -> V_8 , L_12 )
|| ! strcmp ( V_67 -> V_8 , L_13 )
|| ! strcmp ( V_67 -> V_8 , L_14 )
|| ! strcmp ( V_67 -> V_8 , L_17 )
|| ! strcmp ( V_67 -> V_8 , L_18 ) )
continue;
if ( ! F_28 ( V_67 -> V_8 , V_63 ) )
continue;
V_66 = F_29 ( V_36 , V_29 , V_67 -> V_8 ,
V_64 ) ;
}
F_11 ( V_68 ) ;
return V_66 ;
}
int F_31 ( struct V_27 * * V_36 , int * V_29 ,
char * V_69 , char * V_70 )
{
int V_66 ;
V_66 = F_5 ( V_7 ) ;
if ( V_66 )
return V_66 ;
if ( strpbrk ( V_69 , L_16 ) )
return F_30 ( V_36 , V_29 , V_69 , V_70 ) ;
else
return F_29 ( V_36 , V_29 , V_69 , V_70 ) ;
}
static int
F_32 ( const char * type , struct V_30 * V_31 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
if ( ! type || ! type [ V_43 ] )
break;
#define F_33 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_43 ] ) {
case 'r' :
F_33 ( V_71 ) ;
break;
case 'w' :
F_33 ( V_72 ) ;
break;
case 'x' :
F_33 ( V_73 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_33
if ( ! V_31 -> V_74 )
V_31 -> V_74 = V_71 | V_72 ;
return 0 ;
}
int F_34 ( struct V_27 * * V_36 , int * V_29 ,
void * V_75 , char * type )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_76 = ( unsigned long ) V_75 ;
if ( F_32 ( type , & V_31 ) )
return - V_10 ;
if ( V_31 . V_74 == V_73 )
V_31 . V_77 = sizeof( long ) ;
else
V_31 . V_77 = V_78 ;
V_31 . type = V_79 ;
V_31 . V_80 = 1 ;
return F_20 ( V_36 , V_29 , & V_31 , NULL ) ;
}
static int F_35 ( struct V_30 * V_31 ,
struct V_81 * V_82 )
{
#define F_36 ( type ) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch ( V_82 -> V_83 ) {
case V_84 :
F_36 ( V_85 ) ;
V_31 -> V_12 = V_82 -> V_86 . V_87 ;
break;
case V_88 :
F_36 ( V_85 ) ;
V_31 -> V_89 = V_82 -> V_86 . V_87 ;
break;
case V_90 :
F_36 ( V_85 ) ;
V_31 -> V_91 = V_82 -> V_86 . V_87 ;
break;
case V_92 :
F_36 ( V_85 ) ;
V_31 -> V_80 = V_82 -> V_86 . V_87 ;
break;
case V_93 :
break;
case V_94 :
F_36 ( V_95 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
#undef F_36
}
static int F_37 ( struct V_30 * V_31 ,
struct V_27 * V_96 , int V_97 )
{
struct V_81 * V_82 ;
F_38 (term, head, list)
if ( F_35 ( V_31 , V_82 ) && V_97 )
return - V_10 ;
return 0 ;
}
int F_39 ( struct V_27 * * V_36 , int * V_29 ,
T_4 type , T_1 V_12 ,
struct V_27 * V_98 )
{
struct V_30 V_31 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . type = type ;
V_31 . V_12 = V_12 ;
if ( V_98 &&
F_37 ( & V_31 , V_98 , 1 ) )
return - V_10 ;
return F_20 ( V_36 , V_29 , & V_31 , NULL ) ;
}
static int F_40 ( struct V_81 * V_82 )
{
return V_82 -> V_83 == V_94 ;
}
static char * F_41 ( struct V_27 * V_99 )
{
struct V_81 * V_82 ;
F_38 (term, head_terms, list)
if ( F_40 ( V_82 ) )
return V_82 -> V_86 . V_39 ;
return NULL ;
}
int F_42 ( struct V_27 * * V_36 , int * V_29 ,
char * V_22 , struct V_27 * V_98 )
{
struct V_30 V_31 ;
struct V_100 * V_101 ;
V_101 = F_43 ( V_22 ) ;
if ( ! V_101 )
return - V_10 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
if ( F_44 ( V_101 , V_98 ) )
return - V_10 ;
F_37 ( & V_31 , V_98 , 0 ) ;
if ( F_45 ( V_101 , & V_31 , V_98 ) )
return - V_10 ;
return F_14 ( V_36 , V_29 , & V_31 , F_41 ( V_98 ) ,
V_101 -> V_33 ) ;
}
int F_46 ( struct V_27 * V_36 ,
char * V_102 )
{
return F_47 ( V_36 , V_102 , true ) ;
}
void F_48 ( char * V_22 , struct V_27 * V_36 )
{
struct V_34 * V_103 ;
F_49 ( V_36 ) ;
V_103 = F_50 ( V_36 -> V_104 , struct V_34 , V_38 ) ;
V_103 -> V_105 = V_22 ? F_18 ( V_22 ) : NULL ;
}
void F_51 ( struct V_27 * V_106 ,
struct V_27 * V_107 )
{
F_52 ( V_106 , V_107 ) ;
free ( V_106 ) ;
}
static int F_53 ( struct V_108 * V_109 , char * V_39 ,
struct V_34 * V_35 )
{
int V_110 = V_35 ? V_35 -> V_31 . V_111 : 0 ;
int V_112 = V_35 ? V_35 -> V_31 . V_113 : 0 ;
int V_114 = V_35 ? V_35 -> V_31 . V_115 : 0 ;
int V_116 = V_35 ? V_35 -> V_31 . V_117 : 0 ;
int V_118 = V_35 ? V_35 -> V_31 . V_119 : 0 ;
int V_120 = V_35 ? V_35 -> V_31 . V_121 : 0 ;
int V_122 = V_110 | V_112 | V_114 ;
int V_123 = V_35 ? V_35 -> V_123 : 0 ;
memset ( V_109 , 0 , sizeof( * V_109 ) ) ;
while ( * V_39 ) {
if ( * V_39 == 'u' ) {
if ( ! V_122 )
V_122 = V_110 = V_112 = V_114 = 1 ;
V_110 = 0 ;
} else if ( * V_39 == 'k' ) {
if ( ! V_122 )
V_122 = V_110 = V_112 = V_114 = 1 ;
V_112 = 0 ;
} else if ( * V_39 == 'h' ) {
if ( ! V_122 )
V_122 = V_110 = V_112 = V_114 = 1 ;
V_114 = 0 ;
} else if ( * V_39 == 'G' ) {
if ( ! V_123 )
V_123 = V_118 = V_116 = 1 ;
V_118 = 0 ;
} else if ( * V_39 == 'H' ) {
if ( ! V_123 )
V_123 = V_118 = V_116 = 1 ;
V_116 = 0 ;
} else if ( * V_39 == 'p' ) {
V_120 ++ ;
if ( ! V_123 )
V_118 = 1 ;
} else
break;
++ V_39 ;
}
if ( V_120 > 3 )
return - V_10 ;
V_109 -> V_110 = V_110 ;
V_109 -> V_112 = V_112 ;
V_109 -> V_114 = V_114 ;
V_109 -> V_116 = V_116 ;
V_109 -> V_118 = V_118 ;
V_109 -> V_120 = V_120 ;
V_109 -> V_123 = V_123 ;
return 0 ;
}
static int F_54 ( char * V_39 )
{
char * V_124 = V_39 ;
if ( strlen ( V_39 ) > ( sizeof( L_19 ) - 1 ) )
return - 1 ;
while ( * V_124 ) {
if ( * V_124 != 'p' && strchr ( V_124 + 1 , * V_124 ) )
return - 1 ;
V_124 ++ ;
}
return 0 ;
}
int F_47 ( struct V_27 * V_36 , char * V_39 , bool V_125 )
{
struct V_34 * V_35 ;
struct V_108 V_109 ;
if ( V_39 == NULL )
return 0 ;
if ( F_54 ( V_39 ) )
return - V_10 ;
if ( ! V_125 && F_53 ( & V_109 , V_39 , NULL ) )
return - V_10 ;
F_38 (evsel, list, node) {
if ( V_125 && F_53 ( & V_109 , V_39 , V_35 ) )
return - V_10 ;
V_35 -> V_31 . V_111 = V_109 . V_110 ;
V_35 -> V_31 . V_113 = V_109 . V_112 ;
V_35 -> V_31 . V_115 = V_109 . V_114 ;
V_35 -> V_31 . V_121 = V_109 . V_120 ;
V_35 -> V_31 . V_117 = V_109 . V_116 ;
V_35 -> V_31 . V_119 = V_109 . V_118 ;
V_35 -> V_123 = V_109 . V_123 ;
}
return 0 ;
}
int F_55 ( struct V_27 * V_36 , char * V_22 )
{
struct V_34 * V_35 ;
F_38 (evsel, list, node) {
if ( ! V_35 -> V_22 )
V_35 -> V_22 = F_18 ( V_22 ) ;
}
return 0 ;
}
static int F_56 ( const char * V_39 , void * V_126 , int V_127 )
{
T_5 V_128 ;
void * V_129 ;
int V_66 ;
V_66 = F_57 ( V_127 , & V_129 ) ;
if ( V_66 )
return V_66 ;
V_128 = F_58 ( V_39 , V_129 ) ;
#ifdef F_59
V_130 = 1 ;
#endif
V_66 = F_60 ( V_126 , V_129 ) ;
F_61 ( V_128 , V_129 ) ;
F_62 ( V_128 , V_129 ) ;
F_63 ( V_129 ) ;
return V_66 ;
}
int F_64 ( struct V_27 * V_131 , const char * V_39 )
{
struct F_64 V_126 = {
. V_131 = NULL ,
} ;
int V_66 ;
V_66 = F_56 ( V_39 , & V_126 , V_132 ) ;
if ( ! V_66 ) {
F_65 ( V_126 . V_131 , V_131 ) ;
free ( V_126 . V_131 ) ;
return 0 ;
}
F_66 ( V_126 . V_131 ) ;
return V_66 ;
}
int F_67 ( struct V_133 * V_134 , const char * V_39 )
{
struct V_135 V_126 = {
. V_36 = F_68 ( V_126 . V_36 ) ,
. V_29 = V_134 -> V_136 ,
} ;
int V_66 ;
V_66 = F_56 ( V_39 , & V_126 , V_137 ) ;
if ( ! V_66 ) {
int V_138 = V_126 . V_29 - V_134 -> V_136 ;
F_69 ( V_134 , & V_126 . V_36 , V_138 ) ;
V_134 -> V_139 += V_126 . V_139 ;
return 0 ;
}
return V_66 ;
}
int F_70 ( const struct V_140 * V_141 , const char * V_39 ,
int T_6 V_142 )
{
struct V_133 * V_134 = * (struct V_133 * * ) V_141 -> V_143 ;
int V_66 = F_67 ( V_134 , V_39 ) ;
if ( V_66 ) {
fprintf ( V_144 , L_20 , V_39 ) ;
fprintf ( V_144 , L_21 ) ;
}
return V_66 ;
}
int F_71 ( const struct V_140 * V_141 , const char * V_39 ,
int T_6 V_142 )
{
struct V_133 * V_134 = * (struct V_133 * * ) V_141 -> V_143 ;
struct V_34 * V_145 = NULL ;
if ( V_134 -> V_136 > 0 )
V_145 = F_72 ( V_134 ) ;
if ( V_145 == NULL || V_145 -> V_31 . type != V_25 ) {
fprintf ( V_144 ,
L_22 ) ;
return - 1 ;
}
V_145 -> V_146 = F_18 ( V_39 ) ;
if ( V_145 -> V_146 == NULL ) {
fprintf ( V_144 , L_23 ) ;
return - 1 ;
}
return 0 ;
}
void F_73 ( const char * V_147 , const char * V_148 ,
bool V_149 )
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
if ( V_147 != NULL &&
! F_28 ( V_16 . V_8 , V_147 ) )
continue;
snprintf ( V_20 , V_5 , L_2 , V_7 ,
V_16 . V_8 ) ;
V_3 = F_6 ( V_20 ) ;
if ( ! V_3 )
continue;
F_8 (sys_dirent, evt_dir, evt_dirent, evt_next) {
if ( V_148 != NULL &&
! F_28 ( V_17 . V_8 , V_148 ) )
continue;
if ( V_149 ) {
printf ( L_24 , V_16 . V_8 , V_17 . V_8 ) ;
continue;
}
snprintf ( V_4 , V_5 , L_25 ,
V_16 . V_8 , V_17 . V_8 ) ;
printf ( L_26 , V_4 ,
V_150 [ V_25 ] ) ;
}
F_11 ( V_3 ) ;
}
F_11 ( V_2 ) ;
}
int F_74 ( const char * V_151 )
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
snprintf ( V_4 , V_5 , L_25 ,
V_16 . V_8 , V_17 . V_8 ) ;
if ( ! strcmp ( V_4 , V_151 ) ) {
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
static void F_75 ( T_7 type , struct V_152 * V_153 ,
unsigned V_154 )
{
char V_22 [ 64 ] ;
unsigned V_43 ;
for ( V_43 = 0 ; V_43 < V_154 ; V_43 ++ , V_153 ++ ) {
if ( strlen ( V_153 -> V_155 ) )
snprintf ( V_22 , sizeof( V_22 ) , L_27 ,
V_153 -> V_156 , V_153 -> V_155 ) ;
else
snprintf ( V_22 , sizeof( V_22 ) , L_9 , V_153 -> V_156 ) ;
printf ( L_26 , V_22 ,
V_150 [ type ] ) ;
}
}
void F_76 ( T_7 type )
{
if ( type == V_24 )
F_75 ( type , V_157 , V_158 ) ;
else
F_75 ( type , V_159 , V_160 ) ;
}
int F_77 ( const char * V_148 , bool V_149 )
{
unsigned int type , V_161 , V_43 , V_162 = 0 ;
char V_22 [ 64 ] ;
for ( type = 0 ; type < V_55 ; type ++ ) {
for ( V_161 = 0 ; V_161 < V_57 ; V_161 ++ ) {
if ( ! F_23 ( type , V_161 ) )
continue;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ ) {
F_78 ( type , V_161 , V_43 ,
V_22 , sizeof( V_22 ) ) ;
if ( V_148 != NULL && ! F_28 ( V_22 , V_148 ) )
continue;
if ( V_149 )
printf ( L_28 , V_22 ) ;
else
printf ( L_26 , V_22 ,
V_150 [ V_26 ] ) ;
++ V_162 ;
}
}
}
return V_162 ;
}
static void F_79 ( const char * V_148 , unsigned type ,
struct V_152 * V_153 , unsigned V_154 ,
bool V_149 )
{
unsigned V_43 , V_162 = 0 ;
char V_22 [ V_49 ] ;
for ( V_43 = 0 ; V_43 < V_154 ; V_43 ++ , V_153 ++ ) {
if ( V_148 != NULL &&
! ( F_28 ( V_153 -> V_156 , V_148 ) ||
( V_153 -> V_155 && F_28 ( V_153 -> V_155 , V_148 ) ) ) )
continue;
if ( V_149 ) {
printf ( L_28 , V_153 -> V_156 ) ;
continue;
}
if ( strlen ( V_153 -> V_155 ) )
snprintf ( V_22 , V_49 , L_27 , V_153 -> V_156 , V_153 -> V_155 ) ;
else
strncpy ( V_22 , V_153 -> V_156 , V_49 ) ;
printf ( L_26 , V_22 , V_150 [ type ] ) ;
V_162 ++ ;
}
if ( V_162 )
printf ( L_29 ) ;
}
void F_80 ( const char * V_148 , bool V_149 )
{
if ( ! V_149 ) {
printf ( L_29 ) ;
printf ( L_30 ) ;
}
F_79 ( V_148 , V_23 ,
V_159 , V_160 , V_149 ) ;
F_79 ( V_148 , V_24 ,
V_157 , V_158 , V_149 ) ;
F_77 ( V_148 , V_149 ) ;
if ( V_148 != NULL )
return;
if ( ! V_149 ) {
printf ( L_29 ) ;
printf ( L_26 ,
L_31 ,
V_150 [ V_163 ] ) ;
printf ( L_26 ,
L_32 ,
V_150 [ V_163 ] ) ;
printf ( L_33 ) ;
printf ( L_29 ) ;
printf ( L_26 ,
L_34 ,
V_150 [ V_79 ] ) ;
printf ( L_29 ) ;
}
F_73 ( NULL , NULL , V_149 ) ;
}
int F_81 ( struct V_81 * V_82 )
{
return V_82 -> V_83 != V_164 ;
}
static int F_82 ( struct V_81 * * V_165 , int V_166 ,
int V_83 , char * V_12 ,
char * V_39 , T_1 V_87 )
{
struct V_81 * V_82 ;
V_82 = F_12 ( sizeof( * V_82 ) ) ;
if ( ! V_82 )
return - V_37 ;
F_15 ( & V_82 -> V_36 ) ;
V_82 -> V_166 = V_166 ;
V_82 -> V_83 = V_83 ;
V_82 -> V_12 = V_12 ;
switch ( V_166 ) {
case V_167 :
V_82 -> V_86 . V_87 = V_87 ;
break;
case V_168 :
V_82 -> V_86 . V_39 = V_39 ;
break;
default:
return - V_10 ;
}
* V_165 = V_82 ;
return 0 ;
}
int F_83 ( struct V_81 * * V_82 ,
int V_83 , char * V_12 , T_1 V_87 )
{
return F_82 ( V_82 , V_167 , V_83 ,
V_12 , NULL , V_87 ) ;
}
int F_84 ( struct V_81 * * V_82 ,
int V_83 , char * V_12 , char * V_39 )
{
return F_82 ( V_82 , V_168 , V_83 ,
V_12 , V_39 , 0 ) ;
}
int F_85 ( struct V_81 * * V_82 ,
char * V_12 , unsigned V_29 )
{
struct V_152 * V_169 ;
F_86 ( V_29 >= V_160 ) ;
V_169 = & V_159 [ V_29 ] ;
if ( V_12 )
return F_82 ( V_82 , V_168 ,
V_164 , V_12 ,
( char * ) V_169 -> V_156 , 0 ) ;
else
return F_82 ( V_82 , V_168 ,
V_164 ,
( char * ) L_35 , ( char * ) V_169 -> V_156 , 0 ) ;
}
int F_87 ( struct V_81 * * V_170 ,
struct V_81 * V_82 )
{
return F_82 ( V_170 , V_82 -> V_166 , V_82 -> V_83 , V_82 -> V_12 ,
V_82 -> V_86 . V_39 , V_82 -> V_86 . V_87 ) ;
}
void F_66 ( struct V_27 * V_131 )
{
struct V_81 * V_82 , * V_171 ;
F_88 (term, h, terms, list)
free ( V_82 ) ;
free ( V_131 ) ;
}
