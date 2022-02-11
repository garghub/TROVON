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
struct V_30 * V_40 )
{
struct V_33 * V_41 ;
F_21 ( V_37 ) ;
V_41 = F_22 ( V_37 , * V_35 ) ;
if ( ! V_41 )
return NULL ;
( * V_35 ) ++ ;
V_41 -> V_39 = F_23 ( V_39 ) ;
V_41 -> V_42 = F_23 ( V_39 ) ;
V_41 -> V_43 = ! ! V_39 ;
if ( V_20 )
V_41 -> V_20 = F_15 ( V_20 ) ;
if ( V_40 )
F_24 ( V_40 , & V_41 -> V_40 ) ;
F_25 ( & V_41 -> V_44 , V_34 ) ;
return V_41 ;
}
static int F_26 ( struct V_30 * V_34 , int * V_35 ,
struct V_36 * V_37 , char * V_20 ,
struct V_30 * V_40 )
{
return F_20 ( V_34 , V_35 , V_37 , V_20 , NULL , V_40 ) ? 0 : - V_45 ;
}
static int F_27 ( char * V_21 , const char * V_46 [] [ V_47 ] , int V_48 )
{
int V_49 , V_50 ;
int V_51 , V_52 = - 1 ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
for ( V_50 = 0 ; V_50 < V_47 && V_46 [ V_49 ] [ V_50 ] ; V_50 ++ ) {
V_51 = strlen ( V_46 [ V_49 ] [ V_50 ] ) ;
if ( V_51 > V_52 && ! strncasecmp ( V_21 , V_46 [ V_49 ] [ V_50 ] , V_51 ) )
V_52 = V_51 ;
}
if ( V_52 > 0 )
return V_49 ;
}
return - 1 ;
}
int F_28 ( struct V_30 * V_34 , int * V_35 ,
char * type , char * V_53 , char * V_54 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
char V_20 [ V_58 ] , * V_59 ;
int V_60 = - 1 , V_61 = - 1 , V_62 = - 1 ;
char * V_63 [ 2 ] = { V_53 , V_54 } ;
int V_49 , V_51 ;
V_60 = F_27 ( type , V_64 ,
V_65 ) ;
if ( V_60 == - 1 )
return - V_10 ;
V_59 = F_18 ( V_57 ) ;
V_51 = snprintf ( V_20 , V_58 , L_9 , type ) ;
for ( V_49 = 0 ; ( V_49 < 2 ) && ( V_63 [ V_49 ] ) ; V_49 ++ ) {
char * V_21 = V_63 [ V_49 ] ;
V_51 += snprintf ( V_20 + V_51 , V_58 - V_51 , L_10 , V_21 ) ;
if ( V_61 == - 1 ) {
V_61 = F_27 ( V_21 , V_66 ,
V_67 ) ;
if ( V_61 >= 0 ) {
if ( ! F_30 ( V_60 , V_61 ) )
return - V_10 ;
continue;
}
}
if ( V_62 == - 1 ) {
V_62 = F_27 ( V_21 , V_68 ,
V_69 ) ;
if ( V_62 >= 0 )
continue;
}
}
if ( V_61 == - 1 )
V_61 = V_70 ;
if ( V_62 == - 1 )
V_62 = V_71 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_12 = V_60 | ( V_61 << 8 ) | ( V_62 << 16 ) ;
V_37 . type = V_25 ;
if ( V_57 ) {
if ( F_31 ( & V_37 , V_57 , V_56 ,
V_72 ) )
return - V_10 ;
if ( F_32 ( V_57 , & V_40 ) )
return - V_45 ;
}
return F_26 ( V_34 , V_35 , & V_37 , V_59 ? : V_20 , & V_40 ) ;
}
static void F_33 ( struct V_55 * V_73 , int V_56 ,
const char * V_74 , const char * V_20 )
{
char V_75 [ V_76 ] ;
if ( ! V_73 )
return;
V_56 = abs ( V_56 ) ;
switch ( V_56 ) {
case V_77 :
V_73 -> V_21 = F_15 ( L_11 ) ;
break;
case V_78 :
V_73 -> V_21 = F_15 ( L_12 ) ;
break;
default:
V_73 -> V_21 = F_15 ( L_13 ) ;
break;
}
F_34 ( V_56 , V_75 , sizeof( V_75 ) , V_74 , V_20 ) ;
V_73 -> V_75 = F_15 ( V_75 ) ;
}
static int F_35 ( struct V_30 * V_34 , int * V_35 ,
const char * V_79 , const char * V_80 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
struct V_33 * V_41 ;
V_41 = F_36 ( V_79 , V_80 , ( * V_35 ) ++ ) ;
if ( F_37 ( V_41 ) ) {
F_33 ( V_56 , F_38 ( V_41 ) , V_79 , V_80 ) ;
return F_38 ( V_41 ) ;
}
if ( V_57 ) {
F_29 ( V_40 ) ;
if ( F_32 ( V_57 , & V_40 ) )
return - V_45 ;
F_24 ( & V_40 , & V_41 -> V_40 ) ;
}
F_25 ( & V_41 -> V_44 , V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_30 * V_34 , int * V_35 ,
const char * V_79 , const char * V_80 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_81 ;
T_2 * V_3 ;
int V_82 = 0 , V_83 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_79 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
F_33 ( V_56 , V_84 , V_79 , V_80 ) ;
return - 1 ;
}
while ( ! V_82 && ( V_81 = F_40 ( V_3 ) ) ) {
if ( ! strcmp ( V_81 -> V_8 , L_14 )
|| ! strcmp ( V_81 -> V_8 , L_15 )
|| ! strcmp ( V_81 -> V_8 , L_16 )
|| ! strcmp ( V_81 -> V_8 , L_17 ) )
continue;
if ( ! F_41 ( V_81 -> V_8 , V_80 ) )
continue;
V_83 ++ ;
V_82 = F_35 ( V_34 , V_35 , V_79 , V_81 -> V_8 ,
V_56 , V_57 ) ;
}
if ( ! V_83 ) {
F_33 ( V_56 , V_78 , V_79 , V_80 ) ;
V_82 = - 1 ;
}
F_10 ( V_3 ) ;
return V_82 ;
}
static int F_42 ( struct V_30 * V_34 , int * V_35 ,
const char * V_79 , const char * V_80 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
return strpbrk ( V_80 , L_18 ) ?
F_39 ( V_34 , V_35 , V_79 , V_80 ,
V_56 , V_57 ) :
F_35 ( V_34 , V_35 , V_79 , V_80 ,
V_56 , V_57 ) ;
}
static int F_43 ( struct V_30 * V_34 , int * V_35 ,
const char * V_79 , const char * V_80 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
struct V_1 * V_85 ;
T_2 * V_86 ;
int V_82 = 0 ;
V_86 = F_5 ( V_7 ) ;
if ( ! V_86 ) {
F_33 ( V_56 , V_84 , V_79 , V_80 ) ;
return - 1 ;
}
while ( ! V_82 && ( V_85 = F_40 ( V_86 ) ) ) {
if ( ! strcmp ( V_85 -> V_8 , L_14 )
|| ! strcmp ( V_85 -> V_8 , L_15 )
|| ! strcmp ( V_85 -> V_8 , L_16 )
|| ! strcmp ( V_85 -> V_8 , L_19 )
|| ! strcmp ( V_85 -> V_8 , L_20 ) )
continue;
if ( ! F_41 ( V_85 -> V_8 , V_79 ) )
continue;
V_82 = F_42 ( V_34 , V_35 , V_85 -> V_8 ,
V_80 , V_56 , V_57 ) ;
}
F_10 ( V_86 ) ;
return V_82 ;
}
static int F_44 ( const char * V_87 , const char * V_88 , int V_6 ,
void * V_89 )
{
F_29 ( V_90 ) ;
struct V_91 * V_92 = V_89 ;
struct V_93 * V_94 = V_92 -> V_95 ;
struct V_30 * V_34 = V_92 -> V_34 ;
struct V_33 * V_96 ;
int V_56 ;
F_45 ( L_21 ,
V_87 , V_88 , V_6 ) ;
V_56 = F_46 ( & V_90 , & V_94 -> V_35 , V_87 ,
V_88 , V_94 -> error ,
V_92 -> V_57 ) ;
if ( V_56 ) {
struct V_33 * V_41 , * V_97 ;
F_45 ( L_22 ,
V_87 , V_88 ) ;
F_47 (evsel, tmp, &new_evsels, node) {
F_48 ( & V_41 -> V_44 ) ;
F_49 ( V_41 ) ;
}
return V_56 ;
}
F_45 ( L_23 , V_87 , V_88 ) ;
F_19 (pos, &new_evsels, node) {
F_45 ( L_24 ,
V_87 , V_88 , V_96 ) ;
V_96 -> V_98 = V_6 ;
}
F_24 ( & V_90 , V_34 ) ;
return 0 ;
}
int F_50 ( struct V_93 * V_95 ,
struct V_30 * V_34 ,
struct V_99 * V_100 ,
struct V_30 * V_57 )
{
int V_56 ;
char V_101 [ V_76 ] ;
struct V_91 V_92 = { V_95 , V_34 , V_57 } ;
static bool V_102 = false ;
if ( F_37 ( V_100 ) || ! V_100 ) {
snprintf ( V_101 , sizeof( V_101 ) ,
L_25 ) ;
V_56 = - V_10 ;
goto V_103;
}
if ( ! V_102 ) {
atexit ( V_104 ) ;
V_102 = true ;
}
V_56 = F_51 ( V_100 ) ;
if ( V_56 ) {
F_52 ( V_100 , V_56 , V_101 , sizeof( V_101 ) ) ;
goto V_103;
}
V_56 = F_53 ( V_100 ) ;
if ( V_56 ) {
F_54 ( V_100 , V_56 , V_101 , sizeof( V_101 ) ) ;
goto V_103;
}
V_56 = F_55 ( V_100 , F_44 , & V_92 ) ;
if ( V_56 ) {
snprintf ( V_101 , sizeof( V_101 ) ,
L_26 ) ;
goto V_103;
}
return 0 ;
V_103:
V_95 -> error -> V_75 = F_15 ( L_27 ) ;
V_95 -> error -> V_21 = F_15 ( V_101 ) ;
return V_56 ;
}
static int
F_56 ( struct V_93 * V_95 ,
struct V_99 * V_100 ,
struct V_30 * V_57 )
{
struct V_26 * V_27 ;
int V_105 ;
if ( ! V_57 || F_57 ( V_57 ) )
return 0 ;
F_19 (term, head_config, list) {
char V_101 [ V_76 ] ;
int V_56 ;
if ( V_27 -> V_28 != V_106 ) {
snprintf ( V_101 , sizeof( V_101 ) ,
L_28 ) ;
V_101 [ V_76 - 1 ] = '\0' ;
V_95 -> error -> V_35 = V_27 -> V_107 ;
V_95 -> error -> V_21 = F_15 ( V_101 ) ;
return - V_10 ;
}
V_56 = F_58 ( V_100 , V_27 , V_95 -> V_94 , & V_105 ) ;
if ( V_56 ) {
F_59 ( V_100 , V_27 , V_95 -> V_94 ,
& V_105 , V_56 , V_101 ,
sizeof( V_101 ) ) ;
V_95 -> error -> V_75 = F_15 (
L_29
L_30
L_31
L_32
L_33
L_34 ) ;
V_95 -> error -> V_21 = F_15 ( V_101 ) ;
if ( V_56 == - V_108 )
V_95 -> error -> V_35 = V_27 -> V_109 ;
else
V_95 -> error -> V_35 = V_27 -> V_107 + V_105 ;
return V_56 ;
}
}
return 0 ;
}
static void
F_60 ( struct V_30 * V_110 ,
struct V_30 * V_111 )
{
struct V_26 * V_27 , * V_112 ;
F_47 (term, temp, evt_head_config, list)
if ( ! F_61 ( V_27 ) )
F_62 ( & V_27 -> V_34 , V_111 ) ;
}
int F_63 ( struct V_93 * V_95 ,
struct V_30 * V_34 ,
char * V_113 ,
bool V_114 ,
struct V_30 * V_57 )
{
int V_56 ;
struct V_99 * V_100 ;
F_29 ( V_111 ) ;
if ( V_57 )
F_60 ( V_57 , & V_111 ) ;
V_100 = F_64 ( V_113 , V_114 ) ;
if ( F_37 ( V_100 ) ) {
char V_101 [ V_76 ] ;
V_56 = F_38 ( V_100 ) ;
if ( V_56 == - V_115 )
snprintf ( V_101 , sizeof( V_101 ) ,
L_35 ) ;
else
F_65 ( V_113 ,
V_114 ,
- V_56 , V_101 ,
sizeof( V_101 ) ) ;
V_95 -> error -> V_75 = F_15 ( L_27 ) ;
V_95 -> error -> V_21 = F_15 ( V_101 ) ;
return V_56 ;
}
V_56 = F_50 ( V_95 , V_34 , V_100 , V_57 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_56 ( V_95 , V_100 , & V_111 ) ;
if ( V_57 )
F_66 ( & V_111 , V_57 ) ;
return V_56 ;
}
static int
F_67 ( const char * type , struct V_36 * V_37 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
if ( ! type || ! type [ V_49 ] )
break;
#define F_68 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_49 ] ) {
case 'r' :
F_68 ( V_116 ) ;
break;
case 'w' :
F_68 ( V_117 ) ;
break;
case 'x' :
F_68 ( V_118 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_68
if ( ! V_37 -> V_119 )
V_37 -> V_119 = V_116 | V_117 ;
return 0 ;
}
int F_69 ( struct V_30 * V_34 , int * V_35 ,
void * V_120 , char * type , T_1 V_121 )
{
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_122 = ( unsigned long ) V_120 ;
if ( F_67 ( type , & V_37 ) )
return - V_10 ;
if ( ! V_121 ) {
if ( V_37 . V_119 == V_118 )
V_121 = sizeof( long ) ;
else
V_121 = V_123 ;
}
V_37 . V_124 = V_121 ;
V_37 . type = V_125 ;
V_37 . V_126 = 1 ;
return F_26 ( V_34 , V_35 , & V_37 , NULL , NULL ) ;
}
static int F_70 ( struct V_26 * V_27 ,
struct V_55 * V_56 ,
int type )
{
if ( type == V_27 -> V_127 )
return 0 ;
if ( V_56 ) {
V_56 -> V_35 = V_27 -> V_109 ;
if ( type == V_128 )
V_56 -> V_21 = F_15 ( L_36 ) ;
else
V_56 -> V_21 = F_15 ( L_37 ) ;
}
return - V_10 ;
}
static bool
F_71 ( int V_129 , struct V_55 * V_56 )
{
if ( V_129 < 0 || V_129 >= V_130 ) {
V_56 -> V_21 = F_15 ( L_38 ) ;
return false ;
}
if ( ! V_131 )
return true ;
switch ( V_129 ) {
case V_132 :
case V_133 :
case V_134 :
case V_29 :
case V_135 :
return true ;
default:
if ( ! V_56 )
return false ;
if ( F_72 ( & V_56 -> V_21 , L_39 ,
V_136 [ V_129 ] ) < 0 )
V_56 -> V_21 = NULL ;
return false ;
}
}
void F_73 ( void )
{
V_131 = true ;
}
static int V_72 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_55 * V_56 )
{
#define F_74 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_27 -> V_28 ) {
case V_132 :
F_74 ( V_137 ) ;
V_37 -> V_12 = V_27 -> V_32 . V_138 ;
break;
case V_133 :
F_74 ( V_137 ) ;
V_37 -> V_139 = V_27 -> V_32 . V_138 ;
break;
case V_134 :
F_74 ( V_137 ) ;
V_37 -> V_140 = V_27 -> V_32 . V_138 ;
break;
case V_135 :
F_74 ( V_137 ) ;
break;
case V_141 :
F_74 ( V_137 ) ;
break;
case V_142 :
F_74 ( V_143 ) ;
if ( strcmp ( V_27 -> V_32 . V_21 , L_40 ) &&
F_75 ( V_27 -> V_32 . V_21 , & V_37 -> V_144 ) ) {
V_56 -> V_21 = F_15 ( L_41 ) ;
V_56 -> V_35 = V_27 -> V_109 ;
return - V_10 ;
}
break;
case V_145 :
F_74 ( V_137 ) ;
if ( V_27 -> V_32 . V_138 > 1 ) {
V_56 -> V_21 = F_15 ( L_42 ) ;
V_56 -> V_35 = V_27 -> V_109 ;
return - V_10 ;
}
break;
case V_146 :
F_74 ( V_143 ) ;
break;
case V_147 :
F_74 ( V_137 ) ;
break;
case V_148 :
F_74 ( V_137 ) ;
break;
case V_149 :
F_74 ( V_137 ) ;
break;
case V_150 :
F_74 ( V_137 ) ;
break;
case V_151 :
F_74 ( V_137 ) ;
break;
case V_29 :
F_74 ( V_143 ) ;
break;
case V_152 :
F_74 ( V_137 ) ;
break;
default:
V_56 -> V_21 = F_15 ( L_43 ) ;
V_56 -> V_35 = V_27 -> V_107 ;
V_56 -> V_75 = F_76 ( NULL ) ;
return - V_10 ;
}
if ( ! F_71 ( V_27 -> V_28 , V_56 ) )
return - V_10 ;
return 0 ;
#undef F_74
}
static int F_77 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_55 * V_56 )
{
if ( V_27 -> V_28 == V_106 ||
V_27 -> V_28 == V_153 )
return 0 ;
else
return V_72 ( V_37 , V_27 , V_56 ) ;
}
static int F_78 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_55 * V_56 )
{
switch ( V_27 -> V_28 ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_152 :
case V_150 :
case V_151 :
return V_72 ( V_37 , V_27 , V_56 ) ;
default:
if ( V_56 ) {
V_56 -> V_35 = V_27 -> V_107 ;
V_56 -> V_21 = F_15 ( L_43 ) ;
V_56 -> V_75 = F_15 ( L_44 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_30 * V_154 ,
struct V_55 * V_56 ,
T_4 V_155 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_155 ( V_37 , V_27 , V_56 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_57 ,
struct V_30 * V_31 V_156 )
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
case V_135 :
F_79 ( V_157 , V_158 , V_27 -> V_32 . V_138 ) ;
break;
case V_141 :
F_79 ( V_159 , V_160 , V_27 -> V_32 . V_138 ) ;
break;
case V_145 :
F_79 ( TIME , time , V_27 -> V_32 . V_138 ) ;
break;
case V_146 :
F_79 ( V_161 , V_162 , V_27 -> V_32 . V_21 ) ;
break;
case V_142 :
F_79 ( V_163 , V_164 , V_27 -> V_32 . V_21 ) ;
break;
case V_147 :
F_79 ( V_165 , V_166 , V_27 -> V_32 . V_138 ) ;
break;
case V_148 :
F_79 ( V_167 , V_168 , V_27 -> V_32 . V_138 ? 1 : 0 ) ;
break;
case V_149 :
F_79 ( V_167 , V_168 , V_27 -> V_32 . V_138 ? 0 : 1 ) ;
break;
case V_152 :
F_79 ( V_169 , V_170 , V_27 -> V_32 . V_138 ) ;
break;
case V_150 :
F_79 ( V_171 , V_172 , V_27 -> V_32 . V_138 ? 1 : 0 ) ;
break;
case V_151 :
F_79 ( V_171 , V_172 , V_27 -> V_32 . V_138 ? 0 : 1 ) ;
break;
case V_153 :
F_79 ( V_173 , V_174 , V_27 -> V_32 . V_21 ) ;
break;
default:
break;
}
}
#undef V_175
return 0 ;
}
int F_46 ( struct V_30 * V_34 , int * V_35 ,
const char * V_74 , const char * V_88 ,
struct V_55 * V_56 ,
struct V_30 * V_57 )
{
if ( V_57 ) {
struct V_36 V_37 ;
if ( F_31 ( & V_37 , V_57 , V_56 ,
F_78 ) )
return - V_10 ;
}
if ( strpbrk ( V_74 , L_18 ) )
return F_43 ( V_34 , V_35 , V_74 , V_88 ,
V_56 , V_57 ) ;
else
return F_42 ( V_34 , V_35 , V_74 , V_88 ,
V_56 , V_57 ) ;
}
int F_80 ( struct V_93 * V_95 ,
struct V_30 * V_34 ,
T_8 type , T_1 V_12 ,
struct V_30 * V_57 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . type = type ;
V_37 . V_12 = V_12 ;
if ( V_57 ) {
if ( F_31 ( & V_37 , V_57 , V_95 -> error ,
V_72 ) )
return - V_10 ;
if ( F_32 ( V_57 , & V_40 ) )
return - V_45 ;
}
return F_26 ( V_34 , & V_95 -> V_35 , & V_37 ,
F_18 ( V_57 ) , & V_40 ) ;
}
int F_81 ( struct V_93 * V_95 ,
struct V_30 * V_34 , char * V_20 ,
struct V_30 * V_57 )
{
struct V_36 V_37 ;
struct V_176 V_177 ;
struct V_178 * V_179 ;
struct V_33 * V_41 ;
F_29 ( V_40 ) ;
V_179 = F_82 ( V_20 ) ;
if ( ! V_179 )
return - V_10 ;
if ( V_179 -> V_180 ) {
memcpy ( & V_37 , V_179 -> V_180 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_57 ) {
V_37 . type = V_179 -> type ;
V_41 = F_20 ( V_34 , & V_95 -> V_35 , & V_37 , NULL , V_179 -> V_39 , NULL ) ;
return V_41 ? 0 : - V_45 ;
}
if ( F_83 ( V_179 , V_57 , & V_177 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_57 , V_95 -> error , F_77 ) )
return - V_10 ;
if ( F_32 ( V_57 , & V_40 ) )
return - V_45 ;
if ( F_84 ( V_179 , & V_37 , V_57 , V_95 -> error ) )
return - V_10 ;
V_41 = F_20 ( V_34 , & V_95 -> V_35 , & V_37 ,
F_18 ( V_57 ) , V_179 -> V_39 ,
& V_40 ) ;
if ( V_41 ) {
V_41 -> V_181 = V_177 . V_181 ;
V_41 -> V_182 = V_177 . V_182 ;
V_41 -> V_183 = V_177 . V_183 ;
V_41 -> V_184 = V_177 . V_184 ;
V_41 -> V_185 = V_177 . V_185 ;
V_41 -> V_186 = V_177 . V_186 ;
}
return V_41 ? 0 : - V_45 ;
}
int F_85 ( struct V_93 * V_95 ,
char * V_21 , struct V_30 * * V_187 )
{
struct V_30 * V_154 ;
struct V_26 * V_27 ;
struct V_30 * V_34 ;
struct V_178 * V_179 = NULL ;
int V_188 = 0 ;
* V_187 = NULL ;
V_34 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! V_34 )
return - 1 ;
F_86 ( V_34 ) ;
while ( ( V_179 = F_87 ( V_179 ) ) != NULL ) {
struct V_189 * V_190 ;
F_19 (alias, &pmu->aliases, list) {
if ( ! strcasecmp ( V_190 -> V_20 , V_21 ) ) {
V_154 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! V_154 )
return - 1 ;
F_86 ( V_154 ) ;
if ( F_88 ( & V_27 , V_106 ,
V_21 , 1 , false , & V_21 , NULL ) < 0 )
return - 1 ;
F_25 ( & V_27 -> V_34 , V_154 ) ;
if ( ! F_81 ( V_95 , V_34 ,
V_179 -> V_20 , V_154 ) ) {
F_45 ( L_45 , V_21 ,
V_179 -> V_20 , V_190 -> V_21 ) ;
V_188 ++ ;
}
F_89 ( V_154 ) ;
}
}
}
if ( ! V_188 )
return - 1 ;
* V_187 = V_34 ;
return 0 ;
}
int F_90 ( struct V_30 * V_34 ,
char * V_191 )
{
return F_91 ( V_34 , V_191 , true ) ;
}
void F_92 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_192 ;
if ( F_57 ( V_34 ) ) {
F_93 ( true , L_46 ) ;
return;
}
F_94 ( V_34 ) ;
V_192 = F_95 ( V_34 -> V_193 , struct V_33 , V_44 ) ;
V_192 -> V_194 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_96 ( struct V_30 * V_195 ,
struct V_30 * V_196 )
{
F_66 ( V_195 , V_196 ) ;
free ( V_195 ) ;
}
static int F_97 ( struct V_197 * V_198 , char * V_21 ,
struct V_33 * V_41 )
{
int V_199 = V_41 ? V_41 -> V_37 . V_200 : 0 ;
int V_201 = V_41 ? V_41 -> V_37 . V_202 : 0 ;
int V_203 = V_41 ? V_41 -> V_37 . V_204 : 0 ;
int V_205 = V_41 ? V_41 -> V_37 . V_206 : 0 ;
int V_207 = V_41 ? V_41 -> V_37 . V_208 : 0 ;
int V_209 = V_41 ? V_41 -> V_37 . V_210 : 0 ;
int V_211 = V_41 ? V_41 -> V_37 . V_212 : 0 ;
int V_213 = 0 ;
int V_214 = 0 ;
int V_215 = V_41 ? V_41 -> V_37 . V_215 : 0 ;
int V_216 = V_199 | V_201 | V_203 ;
int V_217 = V_41 ? V_41 -> V_217 : 0 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_216 )
V_216 = V_199 = V_201 = V_203 = 1 ;
V_199 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_216 )
V_216 = V_199 = V_201 = V_203 = 1 ;
V_201 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_216 )
V_216 = V_199 = V_201 = V_203 = 1 ;
V_203 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_217 )
V_217 = V_207 = V_205 = 1 ;
V_207 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_217 )
V_217 = V_207 = V_205 = 1 ;
V_205 = 0 ;
} else if ( * V_21 == 'I' ) {
V_209 = 1 ;
} else if ( * V_21 == 'p' ) {
V_211 ++ ;
if ( ! V_217 )
V_207 = 1 ;
} else if ( * V_21 == 'P' ) {
V_213 = 1 ;
} else if ( * V_21 == 'S' ) {
V_214 = 1 ;
} else if ( * V_21 == 'D' ) {
V_215 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_211 > 3 )
return - V_10 ;
V_198 -> V_199 = V_199 ;
V_198 -> V_201 = V_201 ;
V_198 -> V_203 = V_203 ;
V_198 -> V_205 = V_205 ;
V_198 -> V_207 = V_207 ;
V_198 -> V_209 = V_209 ;
V_198 -> V_211 = V_211 ;
V_198 -> V_213 = V_213 ;
V_198 -> V_217 = V_217 ;
V_198 -> V_214 = V_214 ;
V_198 -> V_215 = V_215 ;
return 0 ;
}
static int F_98 ( char * V_21 )
{
char * V_218 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_47 ) - 1 ) )
return - 1 ;
while ( * V_218 ) {
if ( * V_218 != 'p' && strchr ( V_218 + 1 , * V_218 ) )
return - 1 ;
V_218 ++ ;
}
return 0 ;
}
int F_91 ( struct V_30 * V_34 , char * V_21 , bool V_219 )
{
struct V_33 * V_41 ;
struct V_197 V_198 ;
if ( V_21 == NULL )
return 0 ;
if ( F_98 ( V_21 ) )
return - V_10 ;
if ( ! V_219 && F_97 ( & V_198 , V_21 , NULL ) )
return - V_10 ;
F_99 (list, evsel) {
if ( V_219 && F_97 ( & V_198 , V_21 , V_41 ) )
return - V_10 ;
V_41 -> V_37 . V_200 = V_198 . V_199 ;
V_41 -> V_37 . V_202 = V_198 . V_201 ;
V_41 -> V_37 . V_204 = V_198 . V_203 ;
V_41 -> V_37 . V_212 = V_198 . V_211 ;
V_41 -> V_37 . V_206 = V_198 . V_205 ;
V_41 -> V_37 . V_208 = V_198 . V_207 ;
V_41 -> V_37 . V_210 = V_198 . V_209 ;
V_41 -> V_217 = V_198 . V_217 ;
V_41 -> V_214 = V_198 . V_214 ;
V_41 -> V_213 = V_198 . V_213 ;
if ( F_100 ( V_41 ) )
V_41 -> V_37 . V_215 = V_198 . V_215 ;
}
return 0 ;
}
int F_101 ( struct V_30 * V_34 , char * V_20 )
{
struct V_33 * V_41 ;
F_99 (list, evsel) {
if ( ! V_41 -> V_20 )
V_41 -> V_20 = F_15 ( V_20 ) ;
}
return 0 ;
}
static int
F_102 ( const void * V_220 , const void * V_221 )
{
struct V_222 * V_223 = (struct V_222 * ) V_220 ;
struct V_222 * V_224 = (struct V_222 * ) V_221 ;
return strcasecmp ( V_223 -> V_225 , V_224 -> V_225 ) ;
}
static void F_103 ( void )
{
if ( V_226 > 0 ) {
struct V_222 * V_218 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_226 ; V_49 ++ ) {
V_218 = V_227 + V_49 ;
F_12 ( & V_218 -> V_225 ) ;
}
F_12 ( & V_227 ) ;
V_226 = 0 ;
}
}
static void F_104 ( void )
{
struct V_178 * V_179 = NULL ;
struct V_189 * V_190 ;
int V_121 = 0 ;
V_179 = NULL ;
while ( ( V_179 = F_87 ( V_179 ) ) != NULL ) {
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_190 -> V_20 , '-' ) )
V_121 ++ ;
V_121 ++ ;
}
}
if ( V_121 == 0 ) {
V_226 = - 1 ;
return;
}
V_227 = malloc ( sizeof( struct V_222 ) * V_121 ) ;
if ( ! V_227 )
return;
V_226 = V_121 ;
V_121 = 0 ;
V_179 = NULL ;
while ( ( V_179 = F_87 ( V_179 ) ) != NULL ) {
F_19 (alias, &pmu->aliases, list) {
struct V_222 * V_218 = V_227 + V_121 ;
char * V_97 = strchr ( V_190 -> V_20 , '-' ) ;
if ( V_97 != NULL ) {
F_105 ( F_14 ( V_190 -> V_20 , V_97 - V_190 -> V_20 ) ,
V_228 ) ;
V_218 ++ ;
F_105 ( F_15 ( ++ V_97 ) , V_229 ) ;
V_121 += 2 ;
} else {
F_105 ( F_15 ( V_190 -> V_20 ) , V_230 ) ;
V_121 ++ ;
}
}
}
qsort ( V_227 , V_121 ,
sizeof( struct V_222 ) , F_102 ) ;
return;
V_56:
F_103 () ;
}
enum V_231
F_106 ( const char * V_20 )
{
struct V_222 V_218 , * V_232 ;
if ( V_226 == 0 )
F_104 () ;
if ( ( V_226 <= 0 ) || ! strcmp ( V_20 , L_48 ) )
return V_233 ;
V_218 . V_225 = F_15 ( V_20 ) ;
V_232 = bsearch ( & V_218 , V_227 ,
( V_234 ) V_226 ,
sizeof( struct V_222 ) , F_102 ) ;
F_12 ( & V_218 . V_225 ) ;
return V_232 ? V_232 -> type : V_233 ;
}
static int F_107 ( const char * V_21 , void * V_95 , int V_235 )
{
T_9 V_236 ;
void * V_237 ;
int V_82 ;
V_82 = F_108 ( V_235 , & V_237 ) ;
if ( V_82 )
return V_82 ;
V_236 = F_109 ( V_21 , V_237 ) ;
#ifdef F_110
V_238 = 1 ;
#endif
V_82 = F_111 ( V_95 , V_237 ) ;
F_112 ( V_236 , V_237 ) ;
F_113 ( V_236 , V_237 ) ;
F_114 ( V_237 ) ;
return V_82 ;
}
int F_115 ( struct V_30 * V_239 , const char * V_21 )
{
struct F_115 V_95 = {
. V_239 = NULL ,
} ;
int V_82 ;
V_82 = F_107 ( V_21 , & V_95 , V_240 ) ;
if ( ! V_82 ) {
F_24 ( V_95 . V_239 , V_239 ) ;
F_12 ( & V_95 . V_239 ) ;
return 0 ;
}
F_89 ( V_95 . V_239 ) ;
return V_82 ;
}
int F_116 ( struct V_241 * V_94 , const char * V_21 ,
struct V_55 * V_56 )
{
struct V_93 V_95 = {
. V_34 = F_117 ( V_95 . V_34 ) ,
. V_35 = V_94 -> V_242 ,
. error = V_56 ,
. V_94 = V_94 ,
} ;
int V_82 ;
V_82 = F_107 ( V_21 , & V_95 , V_243 ) ;
F_103 () ;
if ( ! V_82 ) {
struct V_33 * V_244 ;
if ( F_57 ( & V_95 . V_34 ) ) {
F_93 ( true , L_49 ) ;
return - 1 ;
}
F_118 ( V_94 , & V_95 . V_34 ) ;
V_94 -> V_245 += V_95 . V_245 ;
V_244 = F_119 ( V_94 ) ;
V_244 -> V_246 = true ;
return 0 ;
}
return V_82 ;
}
static int F_120 ( void )
{
struct V_247 V_248 ;
F_121 ( & V_248 ) ;
return V_248 . V_249 > V_250 ? V_250 : V_248 . V_249 ;
}
static void F_122 ( struct V_55 * V_56 ,
const char * V_88 )
{
const char * V_21 = L_50 ;
char V_251 [ V_250 ] ;
char * V_252 = ( char * ) V_88 ;
int V_35 = 0 ;
if ( V_56 -> V_21 ) {
int V_253 = F_120 () - 2 ;
int V_254 = strlen ( V_88 ) ;
int V_255 , V_256 , V_257 = 0 ;
int V_258 = 13 ;
V_21 = L_51 ;
V_255 = strlen ( V_21 ) ;
V_256 = V_253 - V_255 ;
V_252 = V_251 ;
if ( V_56 -> V_35 > V_258 )
V_257 = V_56 -> V_35 - V_258 ;
strncpy ( V_252 , V_88 + V_257 , V_256 ) ;
if ( V_257 )
V_252 [ 0 ] = V_252 [ 1 ] = '.' ;
if ( ( V_254 - V_257 ) > V_256 ) {
V_252 [ V_256 - 1 ] = V_252 [ V_256 - 2 ] = '.' ;
V_252 [ V_256 ] = 0 ;
}
V_35 = V_255 + V_56 -> V_35 - V_257 ;
}
fprintf ( V_259 , L_52 , V_21 , V_252 ) ;
if ( V_35 ) {
fprintf ( V_259 , L_53 , V_35 + 1 , L_54 , V_56 -> V_21 ) ;
if ( V_56 -> V_75 )
fprintf ( V_259 , L_55 , V_56 -> V_75 ) ;
F_12 ( & V_56 -> V_21 ) ;
F_12 ( & V_56 -> V_75 ) ;
}
fprintf ( V_259 , L_56 ) ;
}
int F_123 ( const struct V_260 * V_261 , const char * V_21 ,
int T_10 V_156 )
{
struct V_241 * V_94 = * (struct V_241 * * ) V_261 -> V_262 ;
struct V_55 V_56 = { . V_35 = 0 , } ;
int V_82 = F_116 ( V_94 , V_21 , & V_56 ) ;
if ( V_82 )
F_122 ( & V_56 , V_21 ) ;
return V_82 ;
}
static int
F_124 ( struct V_241 * V_94 ,
int (* F_125)( struct V_33 * V_41 ,
const void * V_263 ) ,
const void * V_263 )
{
struct V_33 * V_244 = NULL ;
int V_56 ;
if ( V_94 -> V_242 > 0 )
V_244 = F_119 ( V_94 ) ;
do {
V_56 = (* F_125)( V_244 , V_263 ) ;
if ( V_56 )
return - 1 ;
if ( ! V_244 )
return 0 ;
if ( V_244 -> V_44 . V_264 == & V_94 -> V_265 )
return 0 ;
V_244 = F_95 ( V_244 -> V_44 . V_264 , struct V_33 , V_44 ) ;
} while ( ! V_244 -> V_246 );
return 0 ;
}
static int F_126 ( struct V_33 * V_41 , const void * V_263 )
{
const char * V_21 = V_263 ;
bool V_83 = false ;
int V_266 = 0 ;
struct V_178 * V_179 = NULL ;
if ( V_41 == NULL )
goto V_56;
if ( V_41 -> V_37 . type == V_24 ) {
if ( F_127 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_259 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
}
while ( ( V_179 = F_87 ( V_179 ) ) != NULL )
if ( V_179 -> type == V_41 -> V_37 . type ) {
V_83 = true ;
break;
}
if ( V_83 )
F_128 ( V_179 , L_58 ,
L_59 , & V_266 ) ;
if ( ! V_266 )
goto V_56;
if ( F_129 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_259 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
V_56:
fprintf ( V_259 ,
L_60 ) ;
return - 1 ;
}
int F_130 ( const struct V_260 * V_261 , const char * V_21 ,
int T_10 V_156 )
{
struct V_241 * V_94 = * (struct V_241 * * ) V_261 -> V_262 ;
return F_124 ( V_94 , F_126 ,
( const void * ) V_21 ) ;
}
static int F_131 ( struct V_33 * V_41 ,
const void * V_263 V_156 )
{
char V_267 [ 64 ] ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_259 ,
L_61 ) ;
return - 1 ;
}
snprintf ( V_267 , sizeof( V_267 ) , L_62 , F_132 () ) ;
if ( F_127 ( V_41 , V_267 ) < 0 ) {
fprintf ( V_259 ,
L_57 ) ;
return - 1 ;
}
return 0 ;
}
int F_133 ( const struct V_260 * V_261 ,
const char * V_263 V_156 ,
int T_10 V_156 )
{
struct V_241 * V_94 = * (struct V_241 * * ) V_261 -> V_262 ;
return F_124 ( V_94 , F_131 ,
NULL ) ;
}
static int F_134 ( const void * V_268 , const void * V_269 )
{
const char * const * V_270 = V_268 ;
const char * const * V_271 = V_269 ;
return strcmp ( * V_270 , * V_271 ) ;
}
void F_135 ( const char * V_272 , const char * V_273 ,
bool V_274 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_275 = NULL ;
unsigned int V_276 = 0 , V_277 = 0 ;
bool V_278 = false ;
V_279:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_278 ) {
V_275 = F_11 ( sizeof( char * ) * V_277 ) ;
if ( ! V_275 )
goto V_280;
}
F_6 (sys_dir, sys_dirent) {
if ( V_272 != NULL &&
! F_41 ( V_14 -> V_8 , V_272 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_273 != NULL &&
! F_41 ( V_15 -> V_8 , V_273 ) )
continue;
if ( ! V_278 ) {
V_277 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_63 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_275 [ V_276 ] = F_15 ( V_4 ) ;
if ( V_275 [ V_276 ] == NULL )
goto V_281;
V_276 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_278 ) {
V_278 = true ;
goto V_279;
}
qsort ( V_275 , V_277 , sizeof( char * ) , F_134 ) ;
V_276 = 0 ;
while ( V_276 < V_277 ) {
if ( V_274 ) {
printf ( L_64 , V_275 [ V_276 ++ ] ) ;
continue;
}
printf ( L_65 , V_275 [ V_276 ++ ] ,
V_282 [ V_24 ] ) ;
}
if ( V_277 && F_136 () )
printf ( L_32 ) ;
V_283:
V_277 = V_276 ;
for ( V_276 = 0 ; V_276 < V_277 ; V_276 ++ )
F_12 ( & V_275 [ V_276 ] ) ;
F_12 ( & V_275 ) ;
return;
V_281:
F_10 ( V_3 ) ;
V_280:
F_10 ( V_2 ) ;
printf ( L_66 ,
V_282 [ V_24 ] ) ;
if ( V_275 )
goto V_283;
}
int F_137 ( const char * V_284 )
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
if ( ! strcmp ( V_4 , V_284 ) ) {
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
static bool F_138 ( T_11 type , unsigned V_12 )
{
bool V_82 = true ;
int V_285 ;
struct V_33 * V_41 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_286 = 1 ,
} ;
struct V_287 * V_288 = F_139 ( 0 ) ;
if ( V_288 == NULL )
return false ;
V_41 = F_140 ( & V_37 ) ;
if ( V_41 ) {
V_285 = F_141 ( V_41 , NULL , V_288 ) ;
V_82 = V_285 >= 0 ;
if ( V_285 == - V_77 ) {
V_41 -> V_37 . V_202 = 1 ;
V_82 = F_141 ( V_41 , NULL , V_288 ) >= 0 ;
}
F_49 ( V_41 ) ;
}
return V_82 ;
}
void F_142 ( const char * V_272 , const char * V_273 ,
bool V_274 )
{
struct V_289 * V_290 ;
struct V_291 * V_292 ;
struct V_293 * V_294 , * V_295 ;
struct V_296 V_297 = { . V_298 = true } ;
struct V_299 * V_300 , * V_301 ;
char * V_252 , * V_13 , * V_120 = NULL ;
bool V_302 = false ;
int V_82 ;
V_295 = F_143 ( NULL , & V_297 ) ;
if ( ! V_295 ) {
F_45 ( L_67 ) ;
return;
}
V_294 = F_144 ( true ) ;
if ( ! V_294 ) {
F_45 ( L_68 , V_84 ) ;
return;
}
F_145 (nd, bidlist) {
V_290 = F_146 ( V_300 -> V_303 ) ;
if ( ! V_290 )
continue;
F_19 (ent, &pcache->entries, node) {
if ( ! V_292 -> V_304 )
continue;
if ( V_272 &&
! F_41 ( V_292 -> V_305 . V_87 , V_272 ) )
continue;
if ( V_273 &&
! F_41 ( V_292 -> V_305 . V_88 , V_273 ) )
continue;
V_82 = F_72 ( & V_252 , L_69 , V_292 -> V_305 . V_87 ,
V_292 -> V_305 . V_88 , V_300 -> V_303 ) ;
if ( V_82 > 0 )
F_147 ( V_295 , V_252 ) ;
}
F_148 ( V_290 ) ;
}
F_149 ( V_294 ) ;
F_145 (nd, sdtlist) {
V_252 = strchr ( V_300 -> V_303 , '@' ) ;
if ( V_252 )
* ( V_252 ++ ) = '\0' ;
if ( V_274 ) {
printf ( L_64 , V_300 -> V_303 ) ;
continue;
}
V_301 = F_150 ( V_300 ) ;
if ( V_301 ) {
V_120 = strchr ( V_301 -> V_303 , '@' ) ;
if ( V_120 )
* V_120 = '\0' ;
if ( strcmp ( V_300 -> V_303 , V_301 -> V_303 ) == 0 )
V_302 = true ;
}
if ( V_302 ) {
V_13 = F_151 ( V_252 ) ;
V_82 = F_72 ( & V_252 , L_70 , V_300 -> V_303 , V_13 , V_252 ) ;
if ( V_82 > 0 ) {
printf ( L_65 , V_252 , L_71 ) ;
free ( V_252 ) ;
}
} else
printf ( L_65 , V_300 -> V_303 , L_71 ) ;
if ( V_301 ) {
if ( strcmp ( V_300 -> V_303 , V_301 -> V_303 ) != 0 )
V_302 = false ;
if ( V_120 )
* V_120 = '@' ;
}
}
F_149 ( V_295 ) ;
}
int F_152 ( const char * V_273 , bool V_274 )
{
unsigned int type , V_306 , V_49 , V_276 = 0 , V_277 = 0 ;
char V_20 [ 64 ] ;
char * * V_275 = NULL ;
bool V_278 = false ;
V_279:
if ( V_278 ) {
V_275 = F_11 ( sizeof( char * ) * V_277 ) ;
if ( ! V_275 )
goto V_307;
}
for ( type = 0 ; type < V_65 ; type ++ ) {
for ( V_306 = 0 ; V_306 < V_67 ; V_306 ++ ) {
if ( ! F_30 ( type , V_306 ) )
continue;
for ( V_49 = 0 ; V_49 < V_69 ; V_49 ++ ) {
F_153 ( type , V_306 , V_49 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_273 != NULL && ! F_41 ( V_20 , V_273 ) )
continue;
if ( ! F_138 ( V_25 ,
type | ( V_306 << 8 ) | ( V_49 << 16 ) ) )
continue;
if ( ! V_278 ) {
V_277 ++ ;
continue;
}
V_275 [ V_276 ] = F_15 ( V_20 ) ;
if ( V_275 [ V_276 ] == NULL )
goto V_307;
V_276 ++ ;
}
}
}
if ( ! V_278 ) {
V_278 = true ;
goto V_279;
}
qsort ( V_275 , V_277 , sizeof( char * ) , F_134 ) ;
V_276 = 0 ;
while ( V_276 < V_277 ) {
if ( V_274 ) {
printf ( L_64 , V_275 [ V_276 ++ ] ) ;
continue;
}
printf ( L_65 , V_275 [ V_276 ++ ] ,
V_282 [ V_25 ] ) ;
}
if ( V_277 && F_136 () )
printf ( L_32 ) ;
V_283:
V_277 = V_276 ;
for ( V_276 = 0 ; V_276 < V_277 ; V_276 ++ )
F_12 ( & V_275 [ V_276 ] ) ;
F_12 ( & V_275 ) ;
return V_277 ;
V_307:
printf ( L_66 , V_282 [ V_25 ] ) ;
if ( V_275 )
goto V_283;
return V_277 ;
}
void F_154 ( const char * V_273 , unsigned type ,
struct V_308 * V_309 , unsigned V_310 ,
bool V_274 )
{
unsigned int V_49 , V_276 = 0 , V_277 = 0 ;
char V_20 [ V_58 ] ;
char * * V_275 = NULL ;
bool V_278 = false ;
V_279:
if ( V_278 ) {
V_275 = F_11 ( sizeof( char * ) * V_277 ) ;
if ( ! V_275 )
goto V_307;
V_309 -= V_310 ;
}
for ( V_49 = 0 ; V_49 < V_310 ; V_49 ++ , V_309 ++ ) {
if ( V_273 != NULL && V_309 -> V_225 != NULL &&
! ( F_41 ( V_309 -> V_225 , V_273 ) ||
( V_309 -> V_190 && F_41 ( V_309 -> V_190 , V_273 ) ) ) )
continue;
if ( ! F_138 ( type , V_49 ) )
continue;
if ( ! V_278 ) {
V_277 ++ ;
continue;
}
if ( ! V_274 && strlen ( V_309 -> V_190 ) )
snprintf ( V_20 , V_58 , L_72 , V_309 -> V_225 , V_309 -> V_190 ) ;
else
strncpy ( V_20 , V_309 -> V_225 , V_58 ) ;
V_275 [ V_276 ] = F_15 ( V_20 ) ;
if ( V_275 [ V_276 ] == NULL )
goto V_307;
V_276 ++ ;
}
if ( ! V_278 ) {
V_278 = true ;
goto V_279;
}
qsort ( V_275 , V_277 , sizeof( char * ) , F_134 ) ;
V_276 = 0 ;
while ( V_276 < V_277 ) {
if ( V_274 ) {
printf ( L_64 , V_275 [ V_276 ++ ] ) ;
continue;
}
printf ( L_65 , V_275 [ V_276 ++ ] , V_282 [ type ] ) ;
}
if ( V_277 && F_136 () )
printf ( L_32 ) ;
V_283:
V_277 = V_276 ;
for ( V_276 = 0 ; V_276 < V_277 ; V_276 ++ )
F_12 ( & V_275 [ V_276 ] ) ;
F_12 ( & V_275 ) ;
return;
V_307:
printf ( L_66 , V_282 [ type ] ) ;
if ( V_275 )
goto V_283;
}
void F_155 ( const char * V_273 , bool V_274 , bool V_311 ,
bool V_312 , bool V_313 )
{
F_154 ( V_273 , V_22 ,
V_314 , V_315 , V_274 ) ;
F_154 ( V_273 , V_23 ,
V_316 , V_317 , V_274 ) ;
F_152 ( V_273 , V_274 ) ;
F_156 ( V_273 , V_274 , V_311 , V_312 ,
V_313 ) ;
if ( V_273 != NULL )
return;
if ( ! V_274 ) {
printf ( L_65 ,
L_73 ,
V_282 [ V_318 ] ) ;
printf ( L_65 ,
L_74 ,
V_282 [ V_318 ] ) ;
if ( F_136 () )
printf ( L_75 ) ;
printf ( L_65 ,
L_76 ,
V_282 [ V_125 ] ) ;
if ( F_136 () )
printf ( L_32 ) ;
}
F_135 ( NULL , NULL , V_274 ) ;
F_142 ( NULL , NULL , V_274 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_106 ;
}
static int F_157 ( struct V_26 * * V_319 ,
struct V_26 * V_112 ,
char * V_21 , T_1 V_138 )
{
struct V_26 * V_27 ;
V_27 = malloc ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_45 ;
* V_27 = * V_112 ;
F_86 ( & V_27 -> V_34 ) ;
switch ( V_27 -> V_127 ) {
case V_128 :
V_27 -> V_32 . V_138 = V_138 ;
break;
case V_320 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_319 = V_27 ;
return 0 ;
}
int F_88 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_138 ,
bool V_321 ,
void * V_322 , void * V_323 )
{
T_12 * V_324 = V_322 ;
T_12 * V_325 = V_323 ;
struct V_26 V_112 = {
. V_127 = V_128 ,
. V_28 = V_28 ,
. V_12 = V_12 ,
. V_321 = V_321 ,
. V_107 = V_324 ? V_324 -> V_326 : 0 ,
. V_109 = V_325 ? V_325 -> V_326 : 0 ,
} ;
return F_157 ( V_27 , & V_112 , NULL , V_138 ) ;
}
int F_158 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_322 , void * V_323 )
{
T_12 * V_324 = V_322 ;
T_12 * V_325 = V_323 ;
struct V_26 V_112 = {
. V_127 = V_320 ,
. V_28 = V_28 ,
. V_12 = V_12 ,
. V_107 = V_324 ? V_324 -> V_326 : 0 ,
. V_109 = V_325 ? V_325 -> V_326 : 0 ,
} ;
return F_157 ( V_27 , & V_112 , V_21 , 0 ) ;
}
int F_159 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_308 * V_327 ;
struct V_26 V_112 = {
. V_127 = V_320 ,
. V_28 = V_106 ,
. V_12 = V_12 ? : ( char * ) L_77 ,
} ;
F_160 ( V_35 >= V_315 ) ;
V_327 = & V_314 [ V_35 ] ;
return F_157 ( V_27 , & V_112 , ( char * ) V_327 -> V_225 , 0 ) ;
}
int F_161 ( struct V_26 * * V_328 ,
struct V_26 * V_27 )
{
struct V_26 V_112 = {
. V_127 = V_27 -> V_127 ,
. V_28 = V_27 -> V_28 ,
. V_12 = V_27 -> V_12 ,
. V_107 = V_27 -> V_107 ,
. V_109 = V_27 -> V_109 ,
} ;
return F_157 ( V_328 , & V_112 , V_27 -> V_32 . V_21 , V_27 -> V_32 . V_138 ) ;
}
int F_162 ( struct V_30 * V_329 ,
struct V_30 * * V_328 )
{
struct V_26 * V_27 , * V_51 ;
int V_82 ;
if ( ! V_329 ) {
* V_328 = NULL ;
return 0 ;
}
* V_328 = malloc ( sizeof( struct V_30 ) ) ;
if ( ! * V_328 )
return - V_45 ;
F_86 ( * V_328 ) ;
F_19 (term, old, list) {
V_82 = F_161 ( & V_51 , V_27 ) ;
if ( V_82 )
return V_82 ;
F_25 ( & V_51 -> V_34 , * V_328 ) ;
}
return 0 ;
}
void F_163 ( struct V_30 * V_239 )
{
struct V_26 * V_27 , * V_330 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_331 . V_332 )
F_12 ( & V_27 -> V_331 . V_333 ) ;
F_164 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_89 ( struct V_30 * V_239 )
{
if ( ! V_239 )
return;
F_163 ( V_239 ) ;
free ( V_239 ) ;
}
void F_165 ( struct V_334 * V_268 )
{
F_12 ( & V_268 -> V_333 ) ;
}
void F_166 ( struct V_93 * V_95 ,
int V_35 , const char * V_21 )
{
struct V_55 * V_56 = V_95 -> error ;
if ( ! V_56 )
return;
V_56 -> V_35 = V_35 ;
V_56 -> V_21 = F_15 ( V_21 ) ;
F_93 ( ! V_56 -> V_21 , L_78 ) ;
}
static void F_167 ( char * V_252 , V_234 V_335 )
{
int V_49 ;
bool V_336 = true ;
V_252 [ 0 ] = '\0' ;
for ( V_49 = 0 ; V_49 < V_130 ; V_49 ++ ) {
const char * V_20 = V_136 [ V_49 ] ;
if ( ! F_71 ( V_49 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_252 ) + strlen ( V_20 ) + 2 >= V_335 )
return;
if ( ! V_336 )
strcat ( V_252 , L_79 ) ;
else
V_336 = false ;
strcat ( V_252 , V_20 ) ;
}
}
char * F_76 ( char * V_337 )
{
char * V_21 ;
char V_338 [ V_130 *
( sizeof( L_80 ) - 1 ) ] ;
F_167 ( V_338 , sizeof( V_338 ) ) ;
if ( V_337 ) {
if ( F_72 ( & V_21 , L_81 ,
V_337 , V_338 ) < 0 )
goto V_339;
} else {
if ( F_72 ( & V_21 , L_82 , V_338 ) < 0 )
goto V_339;
}
return V_21 ;
V_339:
return NULL ;
}
