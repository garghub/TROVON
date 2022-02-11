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
struct V_1 * V_14 , * V_15 ;
char V_16 [ 24 ] ;
int V_6 ;
T_1 V_17 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return NULL ;
F_6 (sys_dir, sys_dirent) {
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
snprintf ( V_4 , V_5 , L_3 , V_18 ,
V_15 -> V_8 ) ;
V_6 = F_2 ( V_4 , V_9 ) ;
if ( V_6 < 0 )
continue;
if ( F_8 ( V_6 , V_16 , sizeof( V_16 ) ) < 0 ) {
F_3 ( V_6 ) ;
continue;
}
F_3 ( V_6 ) ;
V_17 = F_9 ( V_16 ) ;
if ( V_17 == V_12 ) {
F_10 ( V_3 ) ;
F_10 ( V_2 ) ;
V_13 = F_11 ( sizeof( * V_13 ) ) ;
if ( ! V_13 )
return NULL ;
V_13 -> system = malloc ( V_19 ) ;
if ( ! V_13 -> system ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> V_20 = malloc ( V_19 ) ;
if ( ! V_13 -> V_20 ) {
F_12 ( & V_13 -> system ) ;
free ( V_13 ) ;
return NULL ;
}
strncpy ( V_13 -> system , V_14 -> V_8 ,
V_19 ) ;
strncpy ( V_13 -> V_20 , V_15 -> V_8 ,
V_19 ) ;
return V_13 ;
}
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
return NULL ;
}
struct V_11 * F_13 ( const char * V_20 )
{
struct V_11 * V_13 = F_11 ( sizeof( * V_13 ) ) ;
char * V_21 = strchr ( V_20 , ':' ) ;
if ( V_13 == NULL || V_21 == NULL ) {
free ( V_13 ) ;
return NULL ;
}
V_13 -> system = F_14 ( V_20 , V_21 - V_20 ) ;
V_13 -> V_20 = F_15 ( V_21 + 1 ) ;
if ( V_13 -> system == NULL || V_13 -> V_20 == NULL ) {
F_12 ( & V_13 -> system ) ;
F_12 ( & V_13 -> V_20 ) ;
F_12 ( & V_13 ) ;
}
return V_13 ;
}
const char * F_16 ( int type )
{
switch ( type ) {
case V_22 :
return L_4 ;
case V_23 :
return L_5 ;
case V_24 :
return L_6 ;
case V_25 :
return L_7 ;
default:
break;
}
return L_8 ;
}
static int F_17 ( struct V_26 * V_27 )
{
return V_27 -> V_28 == V_29 ;
}
static char * F_18 ( struct V_30 * V_31 )
{
struct V_26 * V_27 ;
if ( ! V_31 )
return NULL ;
F_19 (term, head_terms, list)
if ( F_17 ( V_27 ) )
return V_27 -> V_32 . V_21 ;
return NULL ;
}
static struct V_33 *
F_20 ( struct V_30 * V_34 , int * V_35 ,
struct V_36 * V_37 ,
char * V_20 , struct V_38 * V_39 ,
struct V_30 * V_40 , bool V_41 )
{
struct V_33 * V_42 ;
struct V_43 * V_44 = V_39 ? V_39 -> V_44 : NULL ;
F_21 ( V_37 ) ;
V_42 = F_22 ( V_37 , * V_35 ) ;
if ( ! V_42 )
return NULL ;
( * V_35 ) ++ ;
V_42 -> V_44 = F_23 ( V_44 ) ;
V_42 -> V_45 = F_23 ( V_44 ) ;
V_42 -> V_46 = V_39 ? V_39 -> V_47 : false ;
V_42 -> V_41 = V_41 ;
if ( V_20 )
V_42 -> V_20 = F_15 ( V_20 ) ;
if ( V_40 )
F_24 ( V_40 , & V_42 -> V_40 ) ;
F_25 ( & V_42 -> V_48 , V_34 ) ;
return V_42 ;
}
static int F_26 ( struct V_30 * V_34 , int * V_35 ,
struct V_36 * V_37 , char * V_20 ,
struct V_30 * V_40 )
{
return F_20 ( V_34 , V_35 , V_37 , V_20 , NULL , V_40 , false ) ? 0 : - V_49 ;
}
static int F_27 ( char * V_21 , const char * V_50 [] [ V_51 ] , int V_52 )
{
int V_53 , V_54 ;
int V_55 , V_56 = - 1 ;
for ( V_53 = 0 ; V_53 < V_52 ; V_53 ++ ) {
for ( V_54 = 0 ; V_54 < V_51 && V_50 [ V_53 ] [ V_54 ] ; V_54 ++ ) {
V_55 = strlen ( V_50 [ V_53 ] [ V_54 ] ) ;
if ( V_55 > V_56 && ! strncasecmp ( V_21 , V_50 [ V_53 ] [ V_54 ] , V_55 ) )
V_56 = V_55 ;
}
if ( V_56 > 0 )
return V_53 ;
}
return - 1 ;
}
int F_28 ( struct V_30 * V_34 , int * V_35 ,
char * type , char * V_57 , char * V_58 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
char V_20 [ V_62 ] , * V_63 ;
int V_64 = - 1 , V_65 = - 1 , V_66 = - 1 ;
char * V_67 [ 2 ] = { V_57 , V_58 } ;
int V_53 , V_55 ;
V_64 = F_27 ( type , V_68 ,
V_69 ) ;
if ( V_64 == - 1 )
return - V_10 ;
V_63 = F_18 ( V_61 ) ;
V_55 = snprintf ( V_20 , V_62 , L_9 , type ) ;
for ( V_53 = 0 ; ( V_53 < 2 ) && ( V_67 [ V_53 ] ) ; V_53 ++ ) {
char * V_21 = V_67 [ V_53 ] ;
V_55 += snprintf ( V_20 + V_55 , V_62 - V_55 , L_10 , V_21 ) ;
if ( V_65 == - 1 ) {
V_65 = F_27 ( V_21 , V_70 ,
V_71 ) ;
if ( V_65 >= 0 ) {
if ( ! F_30 ( V_64 , V_65 ) )
return - V_10 ;
continue;
}
}
if ( V_66 == - 1 ) {
V_66 = F_27 ( V_21 , V_72 ,
V_73 ) ;
if ( V_66 >= 0 )
continue;
}
}
if ( V_65 == - 1 )
V_65 = V_74 ;
if ( V_66 == - 1 )
V_66 = V_75 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_12 = V_64 | ( V_65 << 8 ) | ( V_66 << 16 ) ;
V_37 . type = V_25 ;
if ( V_61 ) {
if ( F_31 ( & V_37 , V_61 , V_60 ,
V_76 ) )
return - V_10 ;
if ( F_32 ( V_61 , & V_40 ) )
return - V_49 ;
}
return F_26 ( V_34 , V_35 , & V_37 , V_63 ? : V_20 , & V_40 ) ;
}
static void F_33 ( struct V_59 * V_77 , int V_60 ,
const char * V_78 , const char * V_20 )
{
char V_79 [ V_80 ] ;
if ( ! V_77 )
return;
V_60 = abs ( V_60 ) ;
switch ( V_60 ) {
case V_81 :
V_77 -> V_21 = F_15 ( L_11 ) ;
break;
case V_82 :
V_77 -> V_21 = F_15 ( L_12 ) ;
break;
default:
V_77 -> V_21 = F_15 ( L_13 ) ;
break;
}
F_34 ( V_60 , V_79 , sizeof( V_79 ) , V_78 , V_20 ) ;
V_77 -> V_79 = F_15 ( V_79 ) ;
}
static int F_35 ( struct V_30 * V_34 , int * V_35 ,
const char * V_83 , const char * V_84 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
struct V_33 * V_42 ;
V_42 = F_36 ( V_83 , V_84 , ( * V_35 ) ++ ) ;
if ( F_37 ( V_42 ) ) {
F_33 ( V_60 , F_38 ( V_42 ) , V_83 , V_84 ) ;
return F_38 ( V_42 ) ;
}
if ( V_61 ) {
F_29 ( V_40 ) ;
if ( F_32 ( V_61 , & V_40 ) )
return - V_49 ;
F_24 ( & V_40 , & V_42 -> V_40 ) ;
}
F_25 ( & V_42 -> V_48 , V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_30 * V_34 , int * V_35 ,
const char * V_83 , const char * V_84 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_85 ;
T_2 * V_3 ;
int V_86 = 0 , V_87 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_83 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
F_33 ( V_60 , V_88 , V_83 , V_84 ) ;
return - 1 ;
}
while ( ! V_86 && ( V_85 = F_40 ( V_3 ) ) ) {
if ( ! strcmp ( V_85 -> V_8 , L_14 )
|| ! strcmp ( V_85 -> V_8 , L_15 )
|| ! strcmp ( V_85 -> V_8 , L_16 )
|| ! strcmp ( V_85 -> V_8 , L_17 ) )
continue;
if ( ! F_41 ( V_85 -> V_8 , V_84 ) )
continue;
V_87 ++ ;
V_86 = F_35 ( V_34 , V_35 , V_83 , V_85 -> V_8 ,
V_60 , V_61 ) ;
}
if ( ! V_87 ) {
F_33 ( V_60 , V_82 , V_83 , V_84 ) ;
V_86 = - 1 ;
}
F_10 ( V_3 ) ;
return V_86 ;
}
static int F_42 ( struct V_30 * V_34 , int * V_35 ,
const char * V_83 , const char * V_84 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
return strpbrk ( V_84 , L_18 ) ?
F_39 ( V_34 , V_35 , V_83 , V_84 ,
V_60 , V_61 ) :
F_35 ( V_34 , V_35 , V_83 , V_84 ,
V_60 , V_61 ) ;
}
static int F_43 ( struct V_30 * V_34 , int * V_35 ,
const char * V_83 , const char * V_84 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
struct V_1 * V_89 ;
T_2 * V_90 ;
int V_86 = 0 ;
V_90 = F_5 ( V_7 ) ;
if ( ! V_90 ) {
F_33 ( V_60 , V_88 , V_83 , V_84 ) ;
return - 1 ;
}
while ( ! V_86 && ( V_89 = F_40 ( V_90 ) ) ) {
if ( ! strcmp ( V_89 -> V_8 , L_14 )
|| ! strcmp ( V_89 -> V_8 , L_15 )
|| ! strcmp ( V_89 -> V_8 , L_16 )
|| ! strcmp ( V_89 -> V_8 , L_19 )
|| ! strcmp ( V_89 -> V_8 , L_20 ) )
continue;
if ( ! F_41 ( V_89 -> V_8 , V_83 ) )
continue;
V_86 = F_42 ( V_34 , V_35 , V_89 -> V_8 ,
V_84 , V_60 , V_61 ) ;
}
F_10 ( V_90 ) ;
return V_86 ;
}
static int F_44 ( const char * V_91 , const char * V_92 , int V_6 ,
void * V_93 )
{
F_29 ( V_94 ) ;
struct V_95 * V_96 = V_93 ;
struct V_97 * V_98 = V_96 -> V_98 ;
struct V_30 * V_34 = V_96 -> V_34 ;
struct V_33 * V_99 ;
int V_60 ;
F_45 ( L_21 ,
V_91 , V_92 , V_6 ) ;
V_60 = F_46 ( & V_94 , & V_98 -> V_35 , V_91 ,
V_92 , V_98 -> error ,
V_96 -> V_61 ) ;
if ( V_60 ) {
struct V_33 * V_42 , * V_100 ;
F_45 ( L_22 ,
V_91 , V_92 ) ;
F_47 (evsel, tmp, &new_evsels, node) {
F_48 ( & V_42 -> V_48 ) ;
F_49 ( V_42 ) ;
}
return V_60 ;
}
F_45 ( L_23 , V_91 , V_92 ) ;
F_19 (pos, &new_evsels, node) {
F_45 ( L_24 ,
V_91 , V_92 , V_99 ) ;
V_99 -> V_101 = V_6 ;
}
F_24 ( & V_94 , V_34 ) ;
return 0 ;
}
int F_50 ( struct V_97 * V_98 ,
struct V_30 * V_34 ,
struct V_102 * V_103 ,
struct V_30 * V_61 )
{
int V_60 ;
char V_104 [ V_80 ] ;
struct V_95 V_96 = { V_98 , V_34 , V_61 } ;
static bool V_105 = false ;
if ( F_37 ( V_103 ) || ! V_103 ) {
snprintf ( V_104 , sizeof( V_104 ) ,
L_25 ) ;
V_60 = - V_10 ;
goto V_106;
}
if ( ! V_105 ) {
atexit ( V_107 ) ;
V_105 = true ;
}
V_60 = F_51 ( V_103 ) ;
if ( V_60 ) {
F_52 ( V_103 , V_60 , V_104 , sizeof( V_104 ) ) ;
goto V_106;
}
V_60 = F_53 ( V_103 ) ;
if ( V_60 ) {
F_54 ( V_103 , V_60 , V_104 , sizeof( V_104 ) ) ;
goto V_106;
}
V_60 = F_55 ( V_103 , F_44 , & V_96 ) ;
if ( V_60 ) {
snprintf ( V_104 , sizeof( V_104 ) ,
L_26 ) ;
goto V_106;
}
return 0 ;
V_106:
V_98 -> error -> V_79 = F_15 ( L_27 ) ;
V_98 -> error -> V_21 = F_15 ( V_104 ) ;
return V_60 ;
}
static int
F_56 ( struct V_97 * V_98 ,
struct V_102 * V_103 ,
struct V_30 * V_61 )
{
struct V_26 * V_27 ;
int V_108 ;
if ( ! V_61 || F_57 ( V_61 ) )
return 0 ;
F_19 (term, head_config, list) {
char V_104 [ V_80 ] ;
int V_60 ;
if ( V_27 -> V_28 != V_109 ) {
snprintf ( V_104 , sizeof( V_104 ) ,
L_28 ) ;
V_104 [ V_80 - 1 ] = '\0' ;
V_98 -> error -> V_35 = V_27 -> V_110 ;
V_98 -> error -> V_21 = F_15 ( V_104 ) ;
return - V_10 ;
}
V_60 = F_58 ( V_103 , V_27 , V_98 -> V_111 , & V_108 ) ;
if ( V_60 ) {
F_59 ( V_103 , V_27 , V_98 -> V_111 ,
& V_108 , V_60 , V_104 ,
sizeof( V_104 ) ) ;
V_98 -> error -> V_79 = F_15 (
L_29
L_30
L_31
L_32
L_33
L_34 ) ;
V_98 -> error -> V_21 = F_15 ( V_104 ) ;
if ( V_60 == - V_112 )
V_98 -> error -> V_35 = V_27 -> V_113 ;
else
V_98 -> error -> V_35 = V_27 -> V_110 + V_108 ;
return V_60 ;
}
}
return 0 ;
}
static void
F_60 ( struct V_30 * V_114 ,
struct V_30 * V_115 )
{
struct V_26 * V_27 , * V_116 ;
F_47 (term, temp, evt_head_config, list)
if ( ! F_61 ( V_27 ) )
F_62 ( & V_27 -> V_34 , V_115 ) ;
}
int F_63 ( struct V_97 * V_98 ,
struct V_30 * V_34 ,
char * V_117 ,
bool V_118 ,
struct V_30 * V_61 )
{
int V_60 ;
struct V_102 * V_103 ;
F_29 ( V_115 ) ;
if ( V_61 )
F_60 ( V_61 , & V_115 ) ;
V_103 = F_64 ( V_117 , V_118 ) ;
if ( F_37 ( V_103 ) ) {
char V_104 [ V_80 ] ;
V_60 = F_38 ( V_103 ) ;
if ( V_60 == - V_119 )
snprintf ( V_104 , sizeof( V_104 ) ,
L_35 ) ;
else
F_65 ( V_117 ,
V_118 ,
- V_60 , V_104 ,
sizeof( V_104 ) ) ;
V_98 -> error -> V_79 = F_15 ( L_27 ) ;
V_98 -> error -> V_21 = F_15 ( V_104 ) ;
return V_60 ;
}
V_60 = F_50 ( V_98 , V_34 , V_103 , V_61 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_56 ( V_98 , V_103 , & V_115 ) ;
if ( V_61 )
F_66 ( & V_115 , V_61 ) ;
return V_60 ;
}
static int
F_67 ( const char * type , struct V_36 * V_37 )
{
int V_53 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( ! type || ! type [ V_53 ] )
break;
#define F_68 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_53 ] ) {
case 'r' :
F_68 ( V_120 ) ;
break;
case 'w' :
F_68 ( V_121 ) ;
break;
case 'x' :
F_68 ( V_122 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_68
if ( ! V_37 -> V_123 )
V_37 -> V_123 = V_120 | V_121 ;
return 0 ;
}
int F_69 ( struct V_30 * V_34 , int * V_35 ,
void * V_124 , char * type , T_1 V_125 )
{
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_126 = ( unsigned long ) V_124 ;
if ( F_67 ( type , & V_37 ) )
return - V_10 ;
if ( ! V_125 ) {
if ( V_37 . V_123 == V_122 )
V_125 = sizeof( long ) ;
else
V_125 = V_127 ;
}
V_37 . V_128 = V_125 ;
V_37 . type = V_129 ;
V_37 . V_130 = 1 ;
return F_26 ( V_34 , V_35 , & V_37 , NULL , NULL ) ;
}
static int F_70 ( struct V_26 * V_27 ,
struct V_59 * V_60 ,
int type )
{
if ( type == V_27 -> V_131 )
return 0 ;
if ( V_60 ) {
V_60 -> V_35 = V_27 -> V_113 ;
if ( type == V_132 )
V_60 -> V_21 = F_15 ( L_36 ) ;
else
V_60 -> V_21 = F_15 ( L_37 ) ;
}
return - V_10 ;
}
static bool
F_71 ( int V_133 , struct V_59 * V_60 )
{
if ( V_133 < 0 || V_133 >= V_134 ) {
V_60 -> V_21 = F_15 ( L_38 ) ;
return false ;
}
if ( ! V_135 )
return true ;
switch ( V_133 ) {
case V_136 :
case V_137 :
case V_138 :
case V_29 :
case V_139 :
return true ;
default:
if ( ! V_60 )
return false ;
if ( F_72 ( & V_60 -> V_21 , L_39 ,
V_140 [ V_133 ] ) < 0 )
V_60 -> V_21 = NULL ;
return false ;
}
}
void F_73 ( void )
{
V_135 = true ;
}
static int V_76 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_59 * V_60 )
{
#define F_74 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_27 -> V_28 ) {
case V_136 :
F_74 ( V_141 ) ;
V_37 -> V_12 = V_27 -> V_32 . V_142 ;
break;
case V_137 :
F_74 ( V_141 ) ;
V_37 -> V_143 = V_27 -> V_32 . V_142 ;
break;
case V_138 :
F_74 ( V_141 ) ;
V_37 -> V_144 = V_27 -> V_32 . V_142 ;
break;
case V_139 :
F_74 ( V_141 ) ;
break;
case V_145 :
F_74 ( V_141 ) ;
break;
case V_146 :
F_74 ( V_147 ) ;
if ( strcmp ( V_27 -> V_32 . V_21 , L_40 ) &&
F_75 ( V_27 -> V_32 . V_21 , & V_37 -> V_148 ) ) {
V_60 -> V_21 = F_15 ( L_41 ) ;
V_60 -> V_35 = V_27 -> V_113 ;
return - V_10 ;
}
break;
case V_149 :
F_74 ( V_141 ) ;
if ( V_27 -> V_32 . V_142 > 1 ) {
V_60 -> V_21 = F_15 ( L_42 ) ;
V_60 -> V_35 = V_27 -> V_113 ;
return - V_10 ;
}
break;
case V_150 :
F_74 ( V_147 ) ;
break;
case V_151 :
F_74 ( V_141 ) ;
break;
case V_152 :
F_74 ( V_141 ) ;
break;
case V_153 :
F_74 ( V_141 ) ;
break;
case V_154 :
F_74 ( V_141 ) ;
break;
case V_155 :
F_74 ( V_141 ) ;
break;
case V_29 :
F_74 ( V_147 ) ;
break;
case V_156 :
F_74 ( V_141 ) ;
break;
default:
V_60 -> V_21 = F_15 ( L_43 ) ;
V_60 -> V_35 = V_27 -> V_110 ;
V_60 -> V_79 = F_76 ( NULL ) ;
return - V_10 ;
}
if ( ! F_71 ( V_27 -> V_28 , V_60 ) )
return - V_10 ;
return 0 ;
#undef F_74
}
static int F_77 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_59 * V_60 )
{
if ( V_27 -> V_28 == V_109 ||
V_27 -> V_28 == V_157 )
return 0 ;
else
return V_76 ( V_37 , V_27 , V_60 ) ;
}
static int F_78 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_59 * V_60 )
{
switch ( V_27 -> V_28 ) {
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_156 :
case V_154 :
case V_155 :
return V_76 ( V_37 , V_27 , V_60 ) ;
default:
if ( V_60 ) {
V_60 -> V_35 = V_27 -> V_110 ;
V_60 -> V_21 = F_15 ( L_43 ) ;
V_60 -> V_79 = F_15 ( L_44 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_30 * V_158 ,
struct V_59 * V_60 ,
T_4 V_159 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_159 ( V_37 , V_27 , V_60 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_61 ,
struct V_30 * V_31 V_160 )
{
#define F_79 ( T_5 , T_6 , T_7 ) \
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
struct V_26 * V_27 ;
F_19 (term, head_config, list) {
switch ( V_27 -> V_28 ) {
case V_139 :
F_79 ( V_161 , V_162 , V_27 -> V_32 . V_142 ) ;
break;
case V_145 :
F_79 ( V_163 , V_164 , V_27 -> V_32 . V_142 ) ;
break;
case V_149 :
F_79 ( TIME , time , V_27 -> V_32 . V_142 ) ;
break;
case V_150 :
F_79 ( V_165 , V_166 , V_27 -> V_32 . V_21 ) ;
break;
case V_146 :
F_79 ( V_167 , V_168 , V_27 -> V_32 . V_21 ) ;
break;
case V_151 :
F_79 ( V_169 , V_170 , V_27 -> V_32 . V_142 ) ;
break;
case V_152 :
F_79 ( V_171 , V_172 , V_27 -> V_32 . V_142 ? 1 : 0 ) ;
break;
case V_153 :
F_79 ( V_171 , V_172 , V_27 -> V_32 . V_142 ? 0 : 1 ) ;
break;
case V_156 :
F_79 ( V_173 , V_174 , V_27 -> V_32 . V_142 ) ;
break;
case V_154 :
F_79 ( V_175 , V_176 , V_27 -> V_32 . V_142 ? 1 : 0 ) ;
break;
case V_155 :
F_79 ( V_175 , V_176 , V_27 -> V_32 . V_142 ? 0 : 1 ) ;
break;
case V_157 :
F_79 ( V_177 , V_178 , V_27 -> V_32 . V_21 ) ;
break;
default:
break;
}
}
#undef V_179
return 0 ;
}
int F_46 ( struct V_30 * V_34 , int * V_35 ,
const char * V_78 , const char * V_92 ,
struct V_59 * V_60 ,
struct V_30 * V_61 )
{
if ( V_61 ) {
struct V_36 V_37 ;
if ( F_31 ( & V_37 , V_61 , V_60 ,
F_78 ) )
return - V_10 ;
}
if ( strpbrk ( V_78 , L_18 ) )
return F_43 ( V_34 , V_35 , V_78 , V_92 ,
V_60 , V_61 ) ;
else
return F_42 ( V_34 , V_35 , V_78 , V_92 ,
V_60 , V_61 ) ;
}
int F_80 ( struct V_97 * V_98 ,
struct V_30 * V_34 ,
T_8 type , T_1 V_12 ,
struct V_30 * V_61 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . type = type ;
V_37 . V_12 = V_12 ;
if ( V_61 ) {
if ( F_31 ( & V_37 , V_61 , V_98 -> error ,
V_76 ) )
return - V_10 ;
if ( F_32 ( V_61 , & V_40 ) )
return - V_49 ;
}
return F_26 ( V_34 , & V_98 -> V_35 , & V_37 ,
F_18 ( V_61 ) , & V_40 ) ;
}
static int F_81 ( struct V_97 * V_98 ,
struct V_30 * V_34 , char * V_20 ,
struct V_30 * V_61 , bool V_41 )
{
struct V_36 V_37 ;
struct V_180 V_181 ;
struct V_38 * V_39 ;
struct V_33 * V_42 ;
F_29 ( V_40 ) ;
V_39 = F_82 ( V_20 ) ;
if ( ! V_39 )
return - V_10 ;
if ( V_39 -> V_182 ) {
memcpy ( & V_37 , V_39 -> V_182 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_61 ) {
V_37 . type = V_39 -> type ;
V_42 = F_20 ( V_34 , & V_98 -> V_35 , & V_37 , NULL , V_39 , NULL , V_41 ) ;
return V_42 ? 0 : - V_49 ;
}
if ( F_83 ( V_39 , V_61 , & V_181 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_61 , V_98 -> error , F_77 ) )
return - V_10 ;
if ( F_32 ( V_61 , & V_40 ) )
return - V_49 ;
if ( F_84 ( V_39 , & V_37 , V_61 , V_98 -> error ) )
return - V_10 ;
V_42 = F_20 ( V_34 , & V_98 -> V_35 , & V_37 ,
F_18 ( V_61 ) , V_39 ,
& V_40 , V_41 ) ;
if ( V_42 ) {
V_42 -> V_183 = V_181 . V_183 ;
V_42 -> V_184 = V_181 . V_184 ;
V_42 -> V_185 = V_181 . V_185 ;
V_42 -> V_186 = V_181 . V_186 ;
V_42 -> V_187 = V_181 . V_187 ;
V_42 -> V_188 = V_181 . V_188 ;
}
return V_42 ? 0 : - V_49 ;
}
int F_85 ( struct V_97 * V_98 ,
struct V_30 * V_34 , char * V_20 ,
struct V_30 * V_61 )
{
return F_81 ( V_98 , V_34 , V_20 , V_61 , false ) ;
}
int F_86 ( struct V_97 * V_98 ,
char * V_21 , struct V_30 * * V_189 )
{
struct V_30 * V_158 ;
struct V_26 * V_27 ;
struct V_30 * V_34 ;
struct V_38 * V_39 = NULL ;
int V_190 = 0 ;
* V_189 = NULL ;
V_34 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! V_34 )
return - 1 ;
F_87 ( V_34 ) ;
while ( ( V_39 = F_88 ( V_39 ) ) != NULL ) {
struct V_191 * V_192 ;
F_19 (alias, &pmu->aliases, list) {
if ( ! strcasecmp ( V_192 -> V_20 , V_21 ) ) {
V_158 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! V_158 )
return - 1 ;
F_87 ( V_158 ) ;
if ( F_89 ( & V_27 , V_109 ,
V_21 , 1 , false , & V_21 , NULL ) < 0 )
return - 1 ;
F_25 ( & V_27 -> V_34 , V_158 ) ;
if ( ! F_81 ( V_98 , V_34 ,
V_39 -> V_20 , V_158 , true ) ) {
F_45 ( L_45 , V_21 ,
V_39 -> V_20 , V_192 -> V_21 ) ;
V_190 ++ ;
}
F_90 ( V_158 ) ;
}
}
}
if ( ! V_190 )
return - 1 ;
* V_189 = V_34 ;
return 0 ;
}
int F_91 ( struct V_30 * V_34 ,
char * V_193 )
{
return F_92 ( V_34 , V_193 , true ) ;
}
void F_93 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_194 ;
if ( F_57 ( V_34 ) ) {
F_94 ( true , L_46 ) ;
return;
}
F_95 ( V_34 ) ;
V_194 = F_96 ( V_34 -> V_195 , struct V_33 , V_48 ) ;
V_194 -> V_196 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_97 ( struct V_30 * V_197 ,
struct V_30 * V_198 )
{
F_66 ( V_197 , V_198 ) ;
free ( V_197 ) ;
}
static int F_98 ( struct V_199 * V_200 , char * V_21 ,
struct V_33 * V_42 )
{
int V_201 = V_42 ? V_42 -> V_37 . V_202 : 0 ;
int V_203 = V_42 ? V_42 -> V_37 . V_204 : 0 ;
int V_205 = V_42 ? V_42 -> V_37 . V_206 : 0 ;
int V_207 = V_42 ? V_42 -> V_37 . V_208 : 0 ;
int V_209 = V_42 ? V_42 -> V_37 . V_210 : 0 ;
int V_211 = V_42 ? V_42 -> V_37 . V_212 : 0 ;
int V_213 = V_42 ? V_42 -> V_37 . V_214 : 0 ;
int V_215 = 0 ;
int V_216 = 0 ;
int V_217 = V_42 ? V_42 -> V_37 . V_217 : 0 ;
int V_218 = V_201 | V_203 | V_205 ;
int V_219 = V_42 ? V_42 -> V_219 : 0 ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_218 )
V_218 = V_201 = V_203 = V_205 = 1 ;
V_201 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_218 )
V_218 = V_201 = V_203 = V_205 = 1 ;
V_203 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_218 )
V_218 = V_201 = V_203 = V_205 = 1 ;
V_205 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_219 )
V_219 = V_209 = V_207 = 1 ;
V_209 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_219 )
V_219 = V_209 = V_207 = 1 ;
V_207 = 0 ;
} else if ( * V_21 == 'I' ) {
V_211 = 1 ;
} else if ( * V_21 == 'p' ) {
V_213 ++ ;
if ( ! V_219 )
V_209 = 1 ;
} else if ( * V_21 == 'P' ) {
V_215 = 1 ;
} else if ( * V_21 == 'S' ) {
V_216 = 1 ;
} else if ( * V_21 == 'D' ) {
V_217 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_213 > 3 )
return - V_10 ;
V_200 -> V_201 = V_201 ;
V_200 -> V_203 = V_203 ;
V_200 -> V_205 = V_205 ;
V_200 -> V_207 = V_207 ;
V_200 -> V_209 = V_209 ;
V_200 -> V_211 = V_211 ;
V_200 -> V_213 = V_213 ;
V_200 -> V_215 = V_215 ;
V_200 -> V_219 = V_219 ;
V_200 -> V_216 = V_216 ;
V_200 -> V_217 = V_217 ;
return 0 ;
}
static int F_99 ( char * V_21 )
{
char * V_220 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_47 ) - 1 ) )
return - 1 ;
while ( * V_220 ) {
if ( * V_220 != 'p' && strchr ( V_220 + 1 , * V_220 ) )
return - 1 ;
V_220 ++ ;
}
return 0 ;
}
int F_92 ( struct V_30 * V_34 , char * V_21 , bool V_221 )
{
struct V_33 * V_42 ;
struct V_199 V_200 ;
if ( V_21 == NULL )
return 0 ;
if ( F_99 ( V_21 ) )
return - V_10 ;
if ( ! V_221 && F_98 ( & V_200 , V_21 , NULL ) )
return - V_10 ;
F_100 (list, evsel) {
if ( V_221 && F_98 ( & V_200 , V_21 , V_42 ) )
return - V_10 ;
V_42 -> V_37 . V_202 = V_200 . V_201 ;
V_42 -> V_37 . V_204 = V_200 . V_203 ;
V_42 -> V_37 . V_206 = V_200 . V_205 ;
V_42 -> V_37 . V_214 = V_200 . V_213 ;
V_42 -> V_37 . V_208 = V_200 . V_207 ;
V_42 -> V_37 . V_210 = V_200 . V_209 ;
V_42 -> V_37 . V_212 = V_200 . V_211 ;
V_42 -> V_219 = V_200 . V_219 ;
V_42 -> V_216 = V_200 . V_216 ;
V_42 -> V_215 = V_200 . V_215 ;
if ( F_101 ( V_42 ) )
V_42 -> V_37 . V_217 = V_200 . V_217 ;
}
return 0 ;
}
int F_102 ( struct V_30 * V_34 , char * V_20 )
{
struct V_33 * V_42 ;
F_100 (list, evsel) {
if ( ! V_42 -> V_20 )
V_42 -> V_20 = F_15 ( V_20 ) ;
}
return 0 ;
}
static int
F_103 ( const void * V_222 , const void * V_223 )
{
struct V_224 * V_225 = (struct V_224 * ) V_222 ;
struct V_224 * V_226 = (struct V_224 * ) V_223 ;
return strcasecmp ( V_225 -> V_227 , V_226 -> V_227 ) ;
}
static void F_104 ( void )
{
if ( V_228 > 0 ) {
struct V_224 * V_220 ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_228 ; V_53 ++ ) {
V_220 = V_229 + V_53 ;
F_12 ( & V_220 -> V_227 ) ;
}
F_12 ( & V_229 ) ;
V_228 = 0 ;
}
}
static void F_105 ( void )
{
struct V_38 * V_39 = NULL ;
struct V_191 * V_192 ;
int V_125 = 0 ;
V_39 = NULL ;
while ( ( V_39 = F_88 ( V_39 ) ) != NULL ) {
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_192 -> V_20 , '-' ) )
V_125 ++ ;
V_125 ++ ;
}
}
if ( V_125 == 0 ) {
V_228 = - 1 ;
return;
}
V_229 = malloc ( sizeof( struct V_224 ) * V_125 ) ;
if ( ! V_229 )
return;
V_228 = V_125 ;
V_125 = 0 ;
V_39 = NULL ;
while ( ( V_39 = F_88 ( V_39 ) ) != NULL ) {
F_19 (alias, &pmu->aliases, list) {
struct V_224 * V_220 = V_229 + V_125 ;
char * V_100 = strchr ( V_192 -> V_20 , '-' ) ;
if ( V_100 != NULL ) {
F_106 ( F_14 ( V_192 -> V_20 , V_100 - V_192 -> V_20 ) ,
V_230 ) ;
V_220 ++ ;
F_106 ( F_15 ( ++ V_100 ) , V_231 ) ;
V_125 += 2 ;
} else {
F_106 ( F_15 ( V_192 -> V_20 ) , V_232 ) ;
V_125 ++ ;
}
}
}
qsort ( V_229 , V_125 ,
sizeof( struct V_224 ) , F_103 ) ;
return;
V_60:
F_104 () ;
}
enum V_233
F_107 ( const char * V_20 )
{
struct V_224 V_220 , * V_234 ;
if ( V_228 == 0 )
F_105 () ;
if ( ( V_228 <= 0 ) || ! strcmp ( V_20 , L_48 ) )
return V_235 ;
V_220 . V_227 = F_15 ( V_20 ) ;
V_234 = bsearch ( & V_220 , V_229 ,
( V_236 ) V_228 ,
sizeof( struct V_224 ) , F_103 ) ;
F_12 ( & V_220 . V_227 ) ;
return V_234 ? V_234 -> type : V_235 ;
}
static int F_108 ( const char * V_21 , void * V_98 , int V_237 )
{
T_9 V_238 ;
void * V_239 ;
int V_86 ;
V_86 = F_109 ( V_237 , & V_239 ) ;
if ( V_86 )
return V_86 ;
V_238 = F_110 ( V_21 , V_239 ) ;
#ifdef F_111
V_240 = 1 ;
#endif
V_86 = F_112 ( V_98 , V_239 ) ;
F_113 ( V_238 , V_239 ) ;
F_114 ( V_238 , V_239 ) ;
F_115 ( V_239 ) ;
return V_86 ;
}
int F_116 ( struct V_30 * V_241 , const char * V_21 )
{
struct V_97 V_98 = {
. V_241 = NULL ,
} ;
int V_86 ;
V_86 = F_108 ( V_21 , & V_98 , V_242 ) ;
if ( ! V_86 ) {
F_24 ( V_98 . V_241 , V_241 ) ;
F_12 ( & V_98 . V_241 ) ;
return 0 ;
}
F_90 ( V_98 . V_241 ) ;
return V_86 ;
}
int F_117 ( struct V_243 * V_111 , const char * V_21 ,
struct V_59 * V_60 )
{
struct V_97 V_98 = {
. V_34 = F_118 ( V_98 . V_34 ) ,
. V_35 = V_111 -> V_244 ,
. error = V_60 ,
. V_111 = V_111 ,
} ;
int V_86 ;
V_86 = F_108 ( V_21 , & V_98 , V_245 ) ;
F_104 () ;
if ( ! V_86 ) {
struct V_33 * V_246 ;
if ( F_57 ( & V_98 . V_34 ) ) {
F_94 ( true , L_49 ) ;
return - 1 ;
}
F_119 ( V_111 , & V_98 . V_34 ) ;
V_111 -> V_247 += V_98 . V_247 ;
V_246 = F_120 ( V_111 ) ;
V_246 -> V_248 = true ;
return 0 ;
}
return V_86 ;
}
static int F_121 ( void )
{
struct V_249 V_250 ;
F_122 ( & V_250 ) ;
return V_250 . V_251 > V_252 ? V_252 : V_250 . V_251 ;
}
static void F_123 ( struct V_59 * V_60 ,
const char * V_92 )
{
const char * V_21 = L_50 ;
char V_253 [ V_252 ] ;
char * V_254 = ( char * ) V_92 ;
int V_35 = 0 ;
if ( V_60 -> V_21 ) {
int V_255 = F_121 () - 2 ;
int V_256 = strlen ( V_92 ) ;
int V_257 , V_258 , V_259 = 0 ;
int V_260 = 13 ;
V_21 = L_51 ;
V_257 = strlen ( V_21 ) ;
V_258 = V_255 - V_257 ;
V_254 = V_253 ;
if ( V_60 -> V_35 > V_260 )
V_259 = V_60 -> V_35 - V_260 ;
strncpy ( V_254 , V_92 + V_259 , V_258 ) ;
if ( V_259 )
V_254 [ 0 ] = V_254 [ 1 ] = '.' ;
if ( ( V_256 - V_259 ) > V_258 ) {
V_254 [ V_258 - 1 ] = V_254 [ V_258 - 2 ] = '.' ;
V_254 [ V_258 ] = 0 ;
}
V_35 = V_257 + V_60 -> V_35 - V_259 ;
}
fprintf ( V_261 , L_52 , V_21 , V_254 ) ;
if ( V_35 ) {
fprintf ( V_261 , L_53 , V_35 + 1 , L_54 , V_60 -> V_21 ) ;
if ( V_60 -> V_79 )
fprintf ( V_261 , L_55 , V_60 -> V_79 ) ;
F_12 ( & V_60 -> V_21 ) ;
F_12 ( & V_60 -> V_79 ) ;
}
fprintf ( V_261 , L_56 ) ;
}
int F_124 ( const struct V_262 * V_263 , const char * V_21 ,
int T_10 V_160 )
{
struct V_243 * V_111 = * (struct V_243 * * ) V_263 -> V_264 ;
struct V_59 V_60 = { . V_35 = 0 , } ;
int V_86 = F_117 ( V_111 , V_21 , & V_60 ) ;
if ( V_86 )
F_123 ( & V_60 , V_21 ) ;
return V_86 ;
}
static int
F_125 ( struct V_243 * V_111 ,
int (* F_126)( struct V_33 * V_42 ,
const void * V_265 ) ,
const void * V_265 )
{
struct V_33 * V_246 = NULL ;
int V_60 ;
if ( V_111 -> V_244 > 0 )
V_246 = F_120 ( V_111 ) ;
do {
V_60 = (* F_126)( V_246 , V_265 ) ;
if ( V_60 )
return - 1 ;
if ( ! V_246 )
return 0 ;
if ( V_246 -> V_48 . V_266 == & V_111 -> V_267 )
return 0 ;
V_246 = F_96 ( V_246 -> V_48 . V_266 , struct V_33 , V_48 ) ;
} while ( ! V_246 -> V_248 );
return 0 ;
}
static int F_127 ( struct V_33 * V_42 , const void * V_265 )
{
const char * V_21 = V_265 ;
bool V_87 = false ;
int V_268 = 0 ;
struct V_38 * V_39 = NULL ;
if ( V_42 == NULL )
goto V_60;
if ( V_42 -> V_37 . type == V_24 ) {
if ( F_128 ( V_42 , V_21 ) < 0 ) {
fprintf ( V_261 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
}
while ( ( V_39 = F_88 ( V_39 ) ) != NULL )
if ( V_39 -> type == V_42 -> V_37 . type ) {
V_87 = true ;
break;
}
if ( V_87 )
F_129 ( V_39 , L_58 ,
L_59 , & V_268 ) ;
if ( ! V_268 )
goto V_60;
if ( F_130 ( V_42 , V_21 ) < 0 ) {
fprintf ( V_261 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
V_60:
fprintf ( V_261 ,
L_60 ) ;
return - 1 ;
}
int F_131 ( const struct V_262 * V_263 , const char * V_21 ,
int T_10 V_160 )
{
struct V_243 * V_111 = * (struct V_243 * * ) V_263 -> V_264 ;
return F_125 ( V_111 , F_127 ,
( const void * ) V_21 ) ;
}
static int F_132 ( struct V_33 * V_42 ,
const void * V_265 V_160 )
{
char V_269 [ 64 ] ;
if ( V_42 == NULL || V_42 -> V_37 . type != V_24 ) {
fprintf ( V_261 ,
L_61 ) ;
return - 1 ;
}
snprintf ( V_269 , sizeof( V_269 ) , L_62 , F_133 () ) ;
if ( F_128 ( V_42 , V_269 ) < 0 ) {
fprintf ( V_261 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
}
int F_134 ( const struct V_262 * V_263 ,
const char * V_265 V_160 ,
int T_10 V_160 )
{
struct V_243 * V_111 = * (struct V_243 * * ) V_263 -> V_264 ;
return F_125 ( V_111 , F_132 ,
NULL ) ;
}
static int F_135 ( const void * V_270 , const void * V_271 )
{
const char * const * V_272 = V_270 ;
const char * const * V_273 = V_271 ;
return strcmp ( * V_272 , * V_273 ) ;
}
void F_136 ( const char * V_274 , const char * V_275 ,
bool V_276 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_277 = NULL ;
unsigned int V_278 = 0 , V_279 = 0 ;
bool V_280 = false ;
V_281:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_280 ) {
V_277 = F_11 ( sizeof( char * ) * V_279 ) ;
if ( ! V_277 )
goto V_282;
}
F_6 (sys_dir, sys_dirent) {
if ( V_274 != NULL &&
! F_41 ( V_14 -> V_8 , V_274 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_275 != NULL &&
! F_41 ( V_15 -> V_8 , V_275 ) )
continue;
if ( ! V_280 ) {
V_279 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_63 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_277 [ V_278 ] = F_15 ( V_4 ) ;
if ( V_277 [ V_278 ] == NULL )
goto V_283;
V_278 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_280 ) {
V_280 = true ;
goto V_281;
}
qsort ( V_277 , V_279 , sizeof( char * ) , F_135 ) ;
V_278 = 0 ;
while ( V_278 < V_279 ) {
if ( V_276 ) {
printf ( L_64 , V_277 [ V_278 ++ ] ) ;
continue;
}
printf ( L_65 , V_277 [ V_278 ++ ] ,
V_284 [ V_24 ] ) ;
}
if ( V_279 && F_137 () )
printf ( L_32 ) ;
V_285:
V_279 = V_278 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ )
F_12 ( & V_277 [ V_278 ] ) ;
F_12 ( & V_277 ) ;
return;
V_283:
F_10 ( V_3 ) ;
V_282:
F_10 ( V_2 ) ;
printf ( L_66 ,
V_284 [ V_24 ] ) ;
if ( V_277 )
goto V_285;
}
int F_138 ( const char * V_286 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return 0 ;
F_6 (sys_dir, sys_dirent) {
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
snprintf ( V_4 , V_5 , L_63 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
if ( ! strcmp ( V_4 , V_286 ) ) {
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
static bool F_139 ( T_11 type , unsigned V_12 )
{
bool V_86 = true ;
int V_287 ;
struct V_33 * V_42 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_288 = 1 ,
} ;
struct V_289 * V_290 = F_140 ( 0 ) ;
if ( V_290 == NULL )
return false ;
V_42 = F_141 ( & V_37 ) ;
if ( V_42 ) {
V_287 = F_142 ( V_42 , NULL , V_290 ) ;
V_86 = V_287 >= 0 ;
if ( V_287 == - V_81 ) {
V_42 -> V_37 . V_204 = 1 ;
V_86 = F_142 ( V_42 , NULL , V_290 ) >= 0 ;
}
F_49 ( V_42 ) ;
}
return V_86 ;
}
void F_143 ( const char * V_274 , const char * V_275 ,
bool V_276 )
{
struct V_291 * V_292 ;
struct V_293 * V_294 ;
struct V_295 * V_296 , * V_297 ;
struct V_298 V_299 = { . V_300 = true } ;
struct V_301 * V_302 , * V_303 ;
char * V_254 , * V_13 , * V_124 = NULL ;
bool V_304 = false ;
int V_86 ;
V_297 = F_144 ( NULL , & V_299 ) ;
if ( ! V_297 ) {
F_45 ( L_67 ) ;
return;
}
V_296 = F_145 ( true ) ;
if ( ! V_296 ) {
F_45 ( L_68 , V_88 ) ;
return;
}
F_146 (nd, bidlist) {
V_292 = F_147 ( V_302 -> V_305 , NULL ) ;
if ( ! V_292 )
continue;
F_19 (ent, &pcache->entries, node) {
if ( ! V_294 -> V_306 )
continue;
if ( V_274 &&
! F_41 ( V_294 -> V_307 . V_91 , V_274 ) )
continue;
if ( V_275 &&
! F_41 ( V_294 -> V_307 . V_92 , V_275 ) )
continue;
V_86 = F_72 ( & V_254 , L_69 , V_294 -> V_307 . V_91 ,
V_294 -> V_307 . V_92 , V_302 -> V_305 ) ;
if ( V_86 > 0 )
F_148 ( V_297 , V_254 ) ;
}
F_149 ( V_292 ) ;
}
F_150 ( V_296 ) ;
F_146 (nd, sdtlist) {
V_254 = strchr ( V_302 -> V_305 , '@' ) ;
if ( V_254 )
* ( V_254 ++ ) = '\0' ;
if ( V_276 ) {
printf ( L_64 , V_302 -> V_305 ) ;
continue;
}
V_303 = F_151 ( V_302 ) ;
if ( V_303 ) {
V_124 = strchr ( V_303 -> V_305 , '@' ) ;
if ( V_124 )
* V_124 = '\0' ;
if ( strcmp ( V_302 -> V_305 , V_303 -> V_305 ) == 0 )
V_304 = true ;
}
if ( V_304 ) {
V_13 = F_152 ( V_254 ) ;
V_86 = F_72 ( & V_254 , L_70 , V_302 -> V_305 , V_13 , V_254 ) ;
if ( V_86 > 0 ) {
printf ( L_65 , V_254 , L_71 ) ;
free ( V_254 ) ;
}
} else
printf ( L_65 , V_302 -> V_305 , L_71 ) ;
if ( V_303 ) {
if ( strcmp ( V_302 -> V_305 , V_303 -> V_305 ) != 0 )
V_304 = false ;
if ( V_124 )
* V_124 = '@' ;
}
}
F_150 ( V_297 ) ;
}
int F_153 ( const char * V_275 , bool V_276 )
{
unsigned int type , V_308 , V_53 , V_278 = 0 , V_279 = 0 ;
char V_20 [ 64 ] ;
char * * V_277 = NULL ;
bool V_280 = false ;
V_281:
if ( V_280 ) {
V_277 = F_11 ( sizeof( char * ) * V_279 ) ;
if ( ! V_277 )
goto V_309;
}
for ( type = 0 ; type < V_69 ; type ++ ) {
for ( V_308 = 0 ; V_308 < V_71 ; V_308 ++ ) {
if ( ! F_30 ( type , V_308 ) )
continue;
for ( V_53 = 0 ; V_53 < V_73 ; V_53 ++ ) {
F_154 ( type , V_308 , V_53 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_275 != NULL && ! F_41 ( V_20 , V_275 ) )
continue;
if ( ! F_139 ( V_25 ,
type | ( V_308 << 8 ) | ( V_53 << 16 ) ) )
continue;
if ( ! V_280 ) {
V_279 ++ ;
continue;
}
V_277 [ V_278 ] = F_15 ( V_20 ) ;
if ( V_277 [ V_278 ] == NULL )
goto V_309;
V_278 ++ ;
}
}
}
if ( ! V_280 ) {
V_280 = true ;
goto V_281;
}
qsort ( V_277 , V_279 , sizeof( char * ) , F_135 ) ;
V_278 = 0 ;
while ( V_278 < V_279 ) {
if ( V_276 ) {
printf ( L_64 , V_277 [ V_278 ++ ] ) ;
continue;
}
printf ( L_65 , V_277 [ V_278 ++ ] ,
V_284 [ V_25 ] ) ;
}
if ( V_279 && F_137 () )
printf ( L_32 ) ;
V_285:
V_279 = V_278 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ )
F_12 ( & V_277 [ V_278 ] ) ;
F_12 ( & V_277 ) ;
return V_279 ;
V_309:
printf ( L_66 , V_284 [ V_25 ] ) ;
if ( V_277 )
goto V_285;
return V_279 ;
}
void F_155 ( const char * V_275 , unsigned type ,
struct V_310 * V_311 , unsigned V_312 ,
bool V_276 )
{
unsigned int V_53 , V_278 = 0 , V_279 = 0 ;
char V_20 [ V_62 ] ;
char * * V_277 = NULL ;
bool V_280 = false ;
V_281:
if ( V_280 ) {
V_277 = F_11 ( sizeof( char * ) * V_279 ) ;
if ( ! V_277 )
goto V_309;
V_311 -= V_312 ;
}
for ( V_53 = 0 ; V_53 < V_312 ; V_53 ++ , V_311 ++ ) {
if ( V_275 != NULL && V_311 -> V_227 != NULL &&
! ( F_41 ( V_311 -> V_227 , V_275 ) ||
( V_311 -> V_192 && F_41 ( V_311 -> V_192 , V_275 ) ) ) )
continue;
if ( ! F_139 ( type , V_53 ) )
continue;
if ( ! V_280 ) {
V_279 ++ ;
continue;
}
if ( ! V_276 && strlen ( V_311 -> V_192 ) )
snprintf ( V_20 , V_62 , L_72 , V_311 -> V_227 , V_311 -> V_192 ) ;
else
strncpy ( V_20 , V_311 -> V_227 , V_62 ) ;
V_277 [ V_278 ] = F_15 ( V_20 ) ;
if ( V_277 [ V_278 ] == NULL )
goto V_309;
V_278 ++ ;
}
if ( ! V_280 ) {
V_280 = true ;
goto V_281;
}
qsort ( V_277 , V_279 , sizeof( char * ) , F_135 ) ;
V_278 = 0 ;
while ( V_278 < V_279 ) {
if ( V_276 ) {
printf ( L_64 , V_277 [ V_278 ++ ] ) ;
continue;
}
printf ( L_65 , V_277 [ V_278 ++ ] , V_284 [ type ] ) ;
}
if ( V_279 && F_137 () )
printf ( L_32 ) ;
V_285:
V_279 = V_278 ;
for ( V_278 = 0 ; V_278 < V_279 ; V_278 ++ )
F_12 ( & V_277 [ V_278 ] ) ;
F_12 ( & V_277 ) ;
return;
V_309:
printf ( L_66 , V_284 [ type ] ) ;
if ( V_277 )
goto V_285;
}
void F_156 ( const char * V_275 , bool V_276 , bool V_313 ,
bool V_314 , bool V_315 )
{
F_155 ( V_275 , V_22 ,
V_316 , V_317 , V_276 ) ;
F_155 ( V_275 , V_23 ,
V_318 , V_319 , V_276 ) ;
F_153 ( V_275 , V_276 ) ;
F_157 ( V_275 , V_276 , V_313 , V_314 ,
V_315 ) ;
if ( V_275 != NULL )
return;
if ( ! V_276 ) {
printf ( L_65 ,
L_73 ,
V_284 [ V_320 ] ) ;
printf ( L_65 ,
L_74 ,
V_284 [ V_320 ] ) ;
if ( F_137 () )
printf ( L_75 ) ;
printf ( L_65 ,
L_76 ,
V_284 [ V_129 ] ) ;
if ( F_137 () )
printf ( L_32 ) ;
}
F_136 ( NULL , NULL , V_276 ) ;
F_143 ( NULL , NULL , V_276 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_109 ;
}
static int F_158 ( struct V_26 * * V_321 ,
struct V_26 * V_116 ,
char * V_21 , T_1 V_142 )
{
struct V_26 * V_27 ;
V_27 = malloc ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_49 ;
* V_27 = * V_116 ;
F_87 ( & V_27 -> V_34 ) ;
switch ( V_27 -> V_131 ) {
case V_132 :
V_27 -> V_32 . V_142 = V_142 ;
break;
case V_322 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_321 = V_27 ;
return 0 ;
}
int F_89 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_142 ,
bool V_323 ,
void * V_324 , void * V_325 )
{
T_12 * V_326 = V_324 ;
T_12 * V_327 = V_325 ;
struct V_26 V_116 = {
. V_131 = V_132 ,
. V_28 = V_28 ,
. V_12 = V_12 ,
. V_323 = V_323 ,
. V_110 = V_326 ? V_326 -> V_328 : 0 ,
. V_113 = V_327 ? V_327 -> V_328 : 0 ,
} ;
return F_158 ( V_27 , & V_116 , NULL , V_142 ) ;
}
int F_159 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_324 , void * V_325 )
{
T_12 * V_326 = V_324 ;
T_12 * V_327 = V_325 ;
struct V_26 V_116 = {
. V_131 = V_322 ,
. V_28 = V_28 ,
. V_12 = V_12 ,
. V_110 = V_326 ? V_326 -> V_328 : 0 ,
. V_113 = V_327 ? V_327 -> V_328 : 0 ,
} ;
return F_158 ( V_27 , & V_116 , V_21 , 0 ) ;
}
int F_160 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_310 * V_329 ;
struct V_26 V_116 = {
. V_131 = V_322 ,
. V_28 = V_109 ,
. V_12 = V_12 ? : ( char * ) L_77 ,
} ;
F_161 ( V_35 >= V_317 ) ;
V_329 = & V_316 [ V_35 ] ;
return F_158 ( V_27 , & V_116 , ( char * ) V_329 -> V_227 , 0 ) ;
}
int F_162 ( struct V_26 * * V_330 ,
struct V_26 * V_27 )
{
struct V_26 V_116 = {
. V_131 = V_27 -> V_131 ,
. V_28 = V_27 -> V_28 ,
. V_12 = V_27 -> V_12 ,
. V_110 = V_27 -> V_110 ,
. V_113 = V_27 -> V_113 ,
} ;
return F_158 ( V_330 , & V_116 , V_27 -> V_32 . V_21 , V_27 -> V_32 . V_142 ) ;
}
int F_163 ( struct V_30 * V_331 ,
struct V_30 * * V_330 )
{
struct V_26 * V_27 , * V_55 ;
int V_86 ;
if ( ! V_331 ) {
* V_330 = NULL ;
return 0 ;
}
* V_330 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! * V_330 )
return - V_49 ;
F_87 ( * V_330 ) ;
F_19 (term, old, list) {
V_86 = F_162 ( & V_55 , V_27 ) ;
if ( V_86 )
return V_86 ;
F_25 ( & V_55 -> V_34 , * V_330 ) ;
}
return 0 ;
}
void F_164 ( struct V_30 * V_241 )
{
struct V_26 * V_27 , * V_332 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_333 . V_334 )
F_12 ( & V_27 -> V_333 . V_335 ) ;
F_165 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_90 ( struct V_30 * V_241 )
{
if ( ! V_241 )
return;
F_164 ( V_241 ) ;
free ( V_241 ) ;
}
void F_166 ( struct V_336 * V_270 )
{
F_12 ( & V_270 -> V_335 ) ;
}
void F_167 ( struct V_97 * V_98 ,
int V_35 , const char * V_21 )
{
struct V_59 * V_60 = V_98 -> error ;
if ( ! V_60 )
return;
V_60 -> V_35 = V_35 ;
V_60 -> V_21 = F_15 ( V_21 ) ;
F_94 ( ! V_60 -> V_21 , L_78 ) ;
}
static void F_168 ( char * V_254 , V_236 V_337 )
{
int V_53 ;
bool V_338 = true ;
V_254 [ 0 ] = '\0' ;
for ( V_53 = 0 ; V_53 < V_134 ; V_53 ++ ) {
const char * V_20 = V_140 [ V_53 ] ;
if ( ! F_71 ( V_53 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_254 ) + strlen ( V_20 ) + 2 >= V_337 )
return;
if ( ! V_338 )
strcat ( V_254 , L_79 ) ;
else
V_338 = false ;
strcat ( V_254 , V_20 ) ;
}
}
char * F_76 ( char * V_339 )
{
char * V_21 ;
char V_340 [ V_134 *
( sizeof( L_80 ) - 1 ) ] ;
F_168 ( V_340 , sizeof( V_340 ) ) ;
if ( V_339 ) {
if ( F_72 ( & V_21 , L_81 ,
V_339 , V_340 ) < 0 )
goto V_341;
} else {
if ( F_72 ( & V_21 , L_82 , V_340 ) < 0 )
goto V_341;
}
return V_21 ;
V_341:
return NULL ;
}
