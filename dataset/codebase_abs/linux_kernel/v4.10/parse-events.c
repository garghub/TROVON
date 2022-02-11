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
free ( V_13 ) ;
V_13 = NULL ;
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
V_41 = F_22 ( V_37 , ( * V_35 ) ++ ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_39 = F_23 ( V_39 ) ;
V_41 -> V_42 = F_23 ( V_39 ) ;
if ( V_20 )
V_41 -> V_20 = F_15 ( V_20 ) ;
if ( V_40 )
F_24 ( V_40 , & V_41 -> V_40 ) ;
F_25 ( & V_41 -> V_43 , V_34 ) ;
return V_41 ;
}
static int F_26 ( struct V_30 * V_34 , int * V_35 ,
struct V_36 * V_37 , char * V_20 ,
struct V_30 * V_40 )
{
return F_20 ( V_34 , V_35 , V_37 , V_20 , NULL , V_40 ) ? 0 : - V_44 ;
}
static int F_27 ( char * V_21 , const char * V_45 [] [ V_46 ] , int V_47 )
{
int V_48 , V_49 ;
int V_50 , V_51 = - 1 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
for ( V_49 = 0 ; V_49 < V_46 && V_45 [ V_48 ] [ V_49 ] ; V_49 ++ ) {
V_50 = strlen ( V_45 [ V_48 ] [ V_49 ] ) ;
if ( V_50 > V_51 && ! strncasecmp ( V_21 , V_45 [ V_48 ] [ V_49 ] , V_50 ) )
V_51 = V_50 ;
}
if ( V_51 > 0 )
return V_48 ;
}
return - 1 ;
}
int F_28 ( struct V_30 * V_34 , int * V_35 ,
char * type , char * V_52 , char * V_53 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
char V_20 [ V_57 ] , * V_58 ;
int V_59 = - 1 , V_60 = - 1 , V_61 = - 1 ;
char * V_62 [ 2 ] = { V_52 , V_53 } ;
int V_48 , V_50 ;
V_59 = F_27 ( type , V_63 ,
V_64 ) ;
if ( V_59 == - 1 )
return - V_10 ;
V_58 = F_18 ( V_56 ) ;
V_50 = snprintf ( V_20 , V_57 , L_9 , type ) ;
for ( V_48 = 0 ; ( V_48 < 2 ) && ( V_62 [ V_48 ] ) ; V_48 ++ ) {
char * V_21 = V_62 [ V_48 ] ;
V_50 += snprintf ( V_20 + V_50 , V_57 - V_50 , L_10 , V_21 ) ;
if ( V_60 == - 1 ) {
V_60 = F_27 ( V_21 , V_65 ,
V_66 ) ;
if ( V_60 >= 0 ) {
if ( ! F_30 ( V_59 , V_60 ) )
return - V_10 ;
continue;
}
}
if ( V_61 == - 1 ) {
V_61 = F_27 ( V_21 , V_67 ,
V_68 ) ;
if ( V_61 >= 0 )
continue;
}
}
if ( V_60 == - 1 )
V_60 = V_69 ;
if ( V_61 == - 1 )
V_61 = V_70 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_12 = V_59 | ( V_60 << 8 ) | ( V_61 << 16 ) ;
V_37 . type = V_25 ;
if ( V_56 ) {
if ( F_31 ( & V_37 , V_56 , V_55 ,
V_71 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
}
return F_26 ( V_34 , V_35 , & V_37 , V_58 ? : V_20 , & V_40 ) ;
}
static void F_33 ( struct V_54 * V_72 , int V_55 ,
const char * V_73 , const char * V_20 )
{
char V_74 [ V_75 ] ;
if ( ! V_72 )
return;
V_55 = abs ( V_55 ) ;
switch ( V_55 ) {
case V_76 :
V_72 -> V_21 = F_15 ( L_11 ) ;
break;
case V_77 :
V_72 -> V_21 = F_15 ( L_12 ) ;
break;
default:
V_72 -> V_21 = F_15 ( L_13 ) ;
break;
}
F_34 ( V_55 , V_74 , sizeof( V_74 ) , V_73 , V_20 ) ;
V_72 -> V_74 = F_15 ( V_74 ) ;
}
static int F_35 ( struct V_30 * V_34 , int * V_35 ,
const char * V_78 , const char * V_79 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
struct V_33 * V_41 ;
V_41 = F_36 ( V_78 , V_79 , ( * V_35 ) ++ ) ;
if ( F_37 ( V_41 ) ) {
F_33 ( V_55 , F_38 ( V_41 ) , V_78 , V_79 ) ;
return F_38 ( V_41 ) ;
}
if ( V_56 ) {
F_29 ( V_40 ) ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
F_24 ( & V_40 , & V_41 -> V_40 ) ;
}
F_25 ( & V_41 -> V_43 , V_34 ) ;
return 0 ;
}
static int F_39 ( struct V_30 * V_34 , int * V_35 ,
const char * V_78 , const char * V_79 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
char V_4 [ V_5 ] ;
struct V_1 * V_80 ;
T_2 * V_3 ;
int V_81 = 0 , V_82 = 0 ;
snprintf ( V_4 , V_5 , L_2 , V_7 , V_78 ) ;
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 ) {
F_33 ( V_55 , V_83 , V_78 , V_79 ) ;
return - 1 ;
}
while ( ! V_81 && ( V_80 = F_40 ( V_3 ) ) ) {
if ( ! strcmp ( V_80 -> V_8 , L_14 )
|| ! strcmp ( V_80 -> V_8 , L_15 )
|| ! strcmp ( V_80 -> V_8 , L_16 )
|| ! strcmp ( V_80 -> V_8 , L_17 ) )
continue;
if ( ! F_41 ( V_80 -> V_8 , V_79 ) )
continue;
V_82 ++ ;
V_81 = F_35 ( V_34 , V_35 , V_78 , V_80 -> V_8 ,
V_55 , V_56 ) ;
}
if ( ! V_82 ) {
F_33 ( V_55 , V_77 , V_78 , V_79 ) ;
V_81 = - 1 ;
}
F_10 ( V_3 ) ;
return V_81 ;
}
static int F_42 ( struct V_30 * V_34 , int * V_35 ,
const char * V_78 , const char * V_79 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
return strpbrk ( V_79 , L_18 ) ?
F_39 ( V_34 , V_35 , V_78 , V_79 ,
V_55 , V_56 ) :
F_35 ( V_34 , V_35 , V_78 , V_79 ,
V_55 , V_56 ) ;
}
static int F_43 ( struct V_30 * V_34 , int * V_35 ,
const char * V_78 , const char * V_79 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
struct V_1 * V_84 ;
T_2 * V_85 ;
int V_81 = 0 ;
V_85 = F_5 ( V_7 ) ;
if ( ! V_85 ) {
F_33 ( V_55 , V_83 , V_78 , V_79 ) ;
return - 1 ;
}
while ( ! V_81 && ( V_84 = F_40 ( V_85 ) ) ) {
if ( ! strcmp ( V_84 -> V_8 , L_14 )
|| ! strcmp ( V_84 -> V_8 , L_15 )
|| ! strcmp ( V_84 -> V_8 , L_16 )
|| ! strcmp ( V_84 -> V_8 , L_19 )
|| ! strcmp ( V_84 -> V_8 , L_20 ) )
continue;
if ( ! F_41 ( V_84 -> V_8 , V_78 ) )
continue;
V_81 = F_42 ( V_34 , V_35 , V_84 -> V_8 ,
V_79 , V_55 , V_56 ) ;
}
F_10 ( V_85 ) ;
return V_81 ;
}
static int F_44 ( const char * V_86 , const char * V_87 , int V_6 ,
void * V_88 )
{
F_29 ( V_89 ) ;
struct V_90 * V_91 = V_88 ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_30 * V_34 = V_91 -> V_34 ;
struct V_33 * V_95 ;
int V_55 ;
F_45 ( L_21 ,
V_86 , V_87 , V_6 ) ;
V_55 = F_46 ( & V_89 , & V_93 -> V_35 , V_86 ,
V_87 , V_93 -> error ,
V_91 -> V_56 ) ;
if ( V_55 ) {
struct V_33 * V_41 , * V_96 ;
F_45 ( L_22 ,
V_86 , V_87 ) ;
F_47 (evsel, tmp, &new_evsels, node) {
F_48 ( & V_41 -> V_43 ) ;
F_49 ( V_41 ) ;
}
return V_55 ;
}
F_45 ( L_23 , V_86 , V_87 ) ;
F_19 (pos, &new_evsels, node) {
F_45 ( L_24 ,
V_86 , V_87 , V_95 ) ;
V_95 -> V_97 = V_6 ;
}
F_24 ( & V_89 , V_34 ) ;
return 0 ;
}
int F_50 ( struct V_92 * V_94 ,
struct V_30 * V_34 ,
struct V_98 * V_99 ,
struct V_30 * V_56 )
{
int V_55 ;
char V_100 [ V_75 ] ;
struct V_90 V_91 = { V_94 , V_34 , V_56 } ;
static bool V_101 = false ;
if ( F_37 ( V_99 ) || ! V_99 ) {
snprintf ( V_100 , sizeof( V_100 ) ,
L_25 ) ;
V_55 = - V_10 ;
goto V_102;
}
if ( ! V_101 ) {
atexit ( V_103 ) ;
V_101 = true ;
}
V_55 = F_51 ( V_99 ) ;
if ( V_55 ) {
F_52 ( V_99 , V_55 , V_100 , sizeof( V_100 ) ) ;
goto V_102;
}
V_55 = F_53 ( V_99 ) ;
if ( V_55 ) {
F_54 ( V_99 , V_55 , V_100 , sizeof( V_100 ) ) ;
goto V_102;
}
V_55 = F_55 ( V_99 , F_44 , & V_91 ) ;
if ( V_55 ) {
snprintf ( V_100 , sizeof( V_100 ) ,
L_26 ) ;
goto V_102;
}
return 0 ;
V_102:
V_94 -> error -> V_74 = F_15 ( L_27 ) ;
V_94 -> error -> V_21 = F_15 ( V_100 ) ;
return V_55 ;
}
static int
F_56 ( struct V_92 * V_94 ,
struct V_98 * V_99 ,
struct V_30 * V_56 )
{
struct V_26 * V_27 ;
int V_104 ;
if ( ! V_56 || F_57 ( V_56 ) )
return 0 ;
F_19 (term, head_config, list) {
char V_100 [ V_75 ] ;
int V_55 ;
if ( V_27 -> V_28 != V_105 ) {
snprintf ( V_100 , sizeof( V_100 ) ,
L_28 ) ;
V_100 [ V_75 - 1 ] = '\0' ;
V_94 -> error -> V_35 = V_27 -> V_106 ;
V_94 -> error -> V_21 = F_15 ( V_100 ) ;
return - V_10 ;
}
V_55 = F_58 ( V_99 , V_27 , V_94 -> V_93 , & V_104 ) ;
if ( V_55 ) {
F_59 ( V_99 , V_27 , V_94 -> V_93 ,
& V_104 , V_55 , V_100 ,
sizeof( V_100 ) ) ;
V_94 -> error -> V_74 = F_15 (
L_29
L_30
L_31
L_32
L_33
L_34 ) ;
V_94 -> error -> V_21 = F_15 ( V_100 ) ;
if ( V_55 == - V_107 )
V_94 -> error -> V_35 = V_27 -> V_108 ;
else
V_94 -> error -> V_35 = V_27 -> V_106 + V_104 ;
return V_55 ;
}
}
return 0 ;
}
static void
F_60 ( struct V_30 * V_109 ,
struct V_30 * V_110 )
{
struct V_26 * V_27 , * V_111 ;
F_47 (term, temp, evt_head_config, list)
if ( ! F_61 ( V_27 ) )
F_62 ( & V_27 -> V_34 , V_110 ) ;
}
int F_63 ( struct V_92 * V_94 ,
struct V_30 * V_34 ,
char * V_112 ,
bool V_113 ,
struct V_30 * V_56 )
{
int V_55 ;
struct V_98 * V_99 ;
F_29 ( V_110 ) ;
if ( V_56 )
F_60 ( V_56 , & V_110 ) ;
V_99 = F_64 ( V_112 , V_113 ) ;
if ( F_37 ( V_99 ) ) {
char V_100 [ V_75 ] ;
V_55 = F_38 ( V_99 ) ;
if ( V_55 == - V_114 )
snprintf ( V_100 , sizeof( V_100 ) ,
L_35 ) ;
else
F_65 ( V_112 ,
V_113 ,
- V_55 , V_100 ,
sizeof( V_100 ) ) ;
V_94 -> error -> V_74 = F_15 ( L_27 ) ;
V_94 -> error -> V_21 = F_15 ( V_100 ) ;
return V_55 ;
}
V_55 = F_50 ( V_94 , V_34 , V_99 , V_56 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_56 ( V_94 , V_99 , & V_110 ) ;
if ( V_56 )
F_66 ( & V_110 , V_56 ) ;
return V_55 ;
}
static int
F_67 ( const char * type , struct V_36 * V_37 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
if ( ! type || ! type [ V_48 ] )
break;
#define F_68 ( T_3 ) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch ( type [ V_48 ] ) {
case 'r' :
F_68 ( V_115 ) ;
break;
case 'w' :
F_68 ( V_116 ) ;
break;
case 'x' :
F_68 ( V_117 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_68
if ( ! V_37 -> V_118 )
V_37 -> V_118 = V_115 | V_116 ;
return 0 ;
}
int F_69 ( struct V_30 * V_34 , int * V_35 ,
void * V_119 , char * type , T_1 V_120 )
{
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_121 = ( unsigned long ) V_119 ;
if ( F_67 ( type , & V_37 ) )
return - V_10 ;
if ( ! V_120 ) {
if ( V_37 . V_118 == V_117 )
V_120 = sizeof( long ) ;
else
V_120 = V_122 ;
}
V_37 . V_123 = V_120 ;
V_37 . type = V_124 ;
V_37 . V_125 = 1 ;
return F_26 ( V_34 , V_35 , & V_37 , NULL , NULL ) ;
}
static int F_70 ( struct V_26 * V_27 ,
struct V_54 * V_55 ,
int type )
{
if ( type == V_27 -> V_126 )
return 0 ;
if ( V_55 ) {
V_55 -> V_35 = V_27 -> V_108 ;
if ( type == V_127 )
V_55 -> V_21 = F_15 ( L_36 ) ;
else
V_55 -> V_21 = F_15 ( L_37 ) ;
}
return - V_10 ;
}
static bool
F_71 ( int V_128 , struct V_54 * V_55 )
{
if ( V_128 < 0 || V_128 >= V_129 ) {
V_55 -> V_21 = F_15 ( L_38 ) ;
return false ;
}
if ( ! V_130 )
return true ;
switch ( V_128 ) {
case V_131 :
case V_132 :
case V_133 :
case V_29 :
case V_134 :
return true ;
default:
if ( ! V_55 )
return false ;
if ( F_72 ( & V_55 -> V_21 , L_39 ,
V_135 [ V_128 ] ) < 0 )
V_55 -> V_21 = NULL ;
return false ;
}
}
void F_73 ( void )
{
V_130 = true ;
}
static int V_71 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
#define F_74 ( type ) \
do { \
if (check_type_val(term, err, PARSE_EVENTS__TERM_TYPE_ ## type)) \
return -EINVAL; \
} while (0)
switch ( V_27 -> V_28 ) {
case V_131 :
F_74 ( V_136 ) ;
V_37 -> V_12 = V_27 -> V_32 . V_137 ;
break;
case V_132 :
F_74 ( V_136 ) ;
V_37 -> V_138 = V_27 -> V_32 . V_137 ;
break;
case V_133 :
F_74 ( V_136 ) ;
V_37 -> V_139 = V_27 -> V_32 . V_137 ;
break;
case V_134 :
F_74 ( V_136 ) ;
break;
case V_140 :
F_74 ( V_136 ) ;
break;
case V_141 :
F_74 ( V_142 ) ;
if ( strcmp ( V_27 -> V_32 . V_21 , L_40 ) &&
F_75 ( V_27 -> V_32 . V_21 , & V_37 -> V_143 ) ) {
V_55 -> V_21 = F_15 ( L_41 ) ;
V_55 -> V_35 = V_27 -> V_108 ;
return - V_10 ;
}
break;
case V_144 :
F_74 ( V_136 ) ;
if ( V_27 -> V_32 . V_137 > 1 ) {
V_55 -> V_21 = F_15 ( L_42 ) ;
V_55 -> V_35 = V_27 -> V_108 ;
return - V_10 ;
}
break;
case V_145 :
F_74 ( V_142 ) ;
break;
case V_146 :
F_74 ( V_136 ) ;
break;
case V_147 :
F_74 ( V_136 ) ;
break;
case V_148 :
F_74 ( V_136 ) ;
break;
case V_149 :
F_74 ( V_136 ) ;
break;
case V_150 :
F_74 ( V_136 ) ;
break;
case V_29 :
F_74 ( V_142 ) ;
break;
case V_151 :
F_74 ( V_136 ) ;
break;
default:
V_55 -> V_21 = F_15 ( L_43 ) ;
V_55 -> V_35 = V_27 -> V_106 ;
V_55 -> V_74 = F_76 ( NULL ) ;
return - V_10 ;
}
if ( ! F_71 ( V_27 -> V_28 , V_55 ) )
return - V_10 ;
return 0 ;
#undef F_74
}
static int F_77 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
if ( V_27 -> V_28 == V_105 ||
V_27 -> V_28 == V_152 )
return 0 ;
else
return V_71 ( V_37 , V_27 , V_55 ) ;
}
static int F_78 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
switch ( V_27 -> V_28 ) {
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_151 :
case V_149 :
case V_150 :
return V_71 ( V_37 , V_27 , V_55 ) ;
default:
if ( V_55 ) {
V_55 -> V_35 = V_27 -> V_106 ;
V_55 -> V_21 = F_15 ( L_43 ) ;
V_55 -> V_74 = F_15 ( L_44 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_30 * V_153 ,
struct V_54 * V_55 ,
T_4 V_154 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_154 ( V_37 , V_27 , V_55 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_56 ,
struct V_30 * V_31 V_155 )
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
case V_134 :
F_79 ( V_156 , V_157 , V_27 -> V_32 . V_137 ) ;
break;
case V_140 :
F_79 ( V_158 , V_159 , V_27 -> V_32 . V_137 ) ;
break;
case V_144 :
F_79 ( TIME , time , V_27 -> V_32 . V_137 ) ;
break;
case V_145 :
F_79 ( V_160 , V_161 , V_27 -> V_32 . V_21 ) ;
break;
case V_141 :
F_79 ( V_162 , V_163 , V_27 -> V_32 . V_21 ) ;
break;
case V_146 :
F_79 ( V_164 , V_165 , V_27 -> V_32 . V_137 ) ;
break;
case V_147 :
F_79 ( V_166 , V_167 , V_27 -> V_32 . V_137 ? 1 : 0 ) ;
break;
case V_148 :
F_79 ( V_166 , V_167 , V_27 -> V_32 . V_137 ? 0 : 1 ) ;
break;
case V_151 :
F_79 ( V_168 , V_169 , V_27 -> V_32 . V_137 ) ;
break;
case V_149 :
F_79 ( V_170 , V_171 , V_27 -> V_32 . V_137 ? 1 : 0 ) ;
break;
case V_150 :
F_79 ( V_170 , V_171 , V_27 -> V_32 . V_137 ? 0 : 1 ) ;
break;
case V_152 :
F_79 ( V_172 , V_173 , V_27 -> V_32 . V_21 ) ;
break;
default:
break;
}
}
#undef V_174
return 0 ;
}
int F_46 ( struct V_30 * V_34 , int * V_35 ,
const char * V_73 , const char * V_87 ,
struct V_54 * V_55 ,
struct V_30 * V_56 )
{
if ( V_56 ) {
struct V_36 V_37 ;
if ( F_31 ( & V_37 , V_56 , V_55 ,
F_78 ) )
return - V_10 ;
}
if ( strpbrk ( V_73 , L_18 ) )
return F_43 ( V_34 , V_35 , V_73 , V_87 ,
V_55 , V_56 ) ;
else
return F_42 ( V_34 , V_35 , V_73 , V_87 ,
V_55 , V_56 ) ;
}
int F_80 ( struct V_92 * V_94 ,
struct V_30 * V_34 ,
T_8 type , T_1 V_12 ,
struct V_30 * V_56 )
{
struct V_36 V_37 ;
F_29 ( V_40 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . type = type ;
V_37 . V_12 = V_12 ;
if ( V_56 ) {
if ( F_31 ( & V_37 , V_56 , V_94 -> error ,
V_71 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
}
return F_26 ( V_34 , & V_94 -> V_35 , & V_37 ,
F_18 ( V_56 ) , & V_40 ) ;
}
int F_81 ( struct V_92 * V_94 ,
struct V_30 * V_34 , char * V_20 ,
struct V_30 * V_56 )
{
struct V_36 V_37 ;
struct V_175 V_176 ;
struct V_177 * V_178 ;
struct V_33 * V_41 ;
F_29 ( V_40 ) ;
V_178 = F_82 ( V_20 ) ;
if ( ! V_178 )
return - V_10 ;
if ( V_178 -> V_179 ) {
memcpy ( & V_37 , V_178 -> V_179 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_56 ) {
V_37 . type = V_178 -> type ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 , NULL , V_178 -> V_39 , NULL ) ;
return V_41 ? 0 : - V_44 ;
}
if ( F_83 ( V_178 , V_56 , & V_176 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_56 , V_94 -> error , F_77 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
if ( F_84 ( V_178 , & V_37 , V_56 , V_94 -> error ) )
return - V_10 ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 ,
F_18 ( V_56 ) , V_178 -> V_39 ,
& V_40 ) ;
if ( V_41 ) {
V_41 -> V_180 = V_176 . V_180 ;
V_41 -> V_181 = V_176 . V_181 ;
V_41 -> V_182 = V_176 . V_182 ;
V_41 -> V_183 = V_176 . V_183 ;
}
return V_41 ? 0 : - V_44 ;
}
int F_85 ( struct V_30 * V_34 ,
char * V_184 )
{
return F_86 ( V_34 , V_184 , true ) ;
}
void F_87 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_185 ;
if ( F_57 ( V_34 ) ) {
F_88 ( true , L_45 ) ;
return;
}
F_89 ( V_34 ) ;
V_185 = F_90 ( V_34 -> V_186 , struct V_33 , V_43 ) ;
V_185 -> V_187 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_91 ( struct V_30 * V_188 ,
struct V_30 * V_189 )
{
F_66 ( V_188 , V_189 ) ;
free ( V_188 ) ;
}
static int F_92 ( struct V_190 * V_191 , char * V_21 ,
struct V_33 * V_41 )
{
int V_192 = V_41 ? V_41 -> V_37 . V_193 : 0 ;
int V_194 = V_41 ? V_41 -> V_37 . V_195 : 0 ;
int V_196 = V_41 ? V_41 -> V_37 . V_197 : 0 ;
int V_198 = V_41 ? V_41 -> V_37 . V_199 : 0 ;
int V_200 = V_41 ? V_41 -> V_37 . V_201 : 0 ;
int V_202 = V_41 ? V_41 -> V_37 . V_203 : 0 ;
int V_204 = V_41 ? V_41 -> V_37 . V_205 : 0 ;
int V_206 = 0 ;
int V_207 = 0 ;
int V_208 = V_41 ? V_41 -> V_37 . V_208 : 0 ;
int V_209 = V_192 | V_194 | V_196 ;
int V_210 = V_41 ? V_41 -> V_210 : 0 ;
memset ( V_191 , 0 , sizeof( * V_191 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_209 )
V_209 = V_192 = V_194 = V_196 = 1 ;
V_192 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_209 )
V_209 = V_192 = V_194 = V_196 = 1 ;
V_194 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_209 )
V_209 = V_192 = V_194 = V_196 = 1 ;
V_196 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_210 )
V_210 = V_200 = V_198 = 1 ;
V_200 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_210 )
V_210 = V_200 = V_198 = 1 ;
V_198 = 0 ;
} else if ( * V_21 == 'I' ) {
V_202 = 1 ;
} else if ( * V_21 == 'p' ) {
V_204 ++ ;
if ( ! V_210 )
V_200 = 1 ;
} else if ( * V_21 == 'P' ) {
V_206 = 1 ;
} else if ( * V_21 == 'S' ) {
V_207 = 1 ;
} else if ( * V_21 == 'D' ) {
V_208 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_204 > 3 )
return - V_10 ;
V_191 -> V_192 = V_192 ;
V_191 -> V_194 = V_194 ;
V_191 -> V_196 = V_196 ;
V_191 -> V_198 = V_198 ;
V_191 -> V_200 = V_200 ;
V_191 -> V_202 = V_202 ;
V_191 -> V_204 = V_204 ;
V_191 -> V_206 = V_206 ;
V_191 -> V_210 = V_210 ;
V_191 -> V_207 = V_207 ;
V_191 -> V_208 = V_208 ;
return 0 ;
}
static int F_93 ( char * V_21 )
{
char * V_211 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_46 ) - 1 ) )
return - 1 ;
while ( * V_211 ) {
if ( * V_211 != 'p' && strchr ( V_211 + 1 , * V_211 ) )
return - 1 ;
V_211 ++ ;
}
return 0 ;
}
int F_86 ( struct V_30 * V_34 , char * V_21 , bool V_212 )
{
struct V_33 * V_41 ;
struct V_190 V_191 ;
if ( V_21 == NULL )
return 0 ;
if ( F_93 ( V_21 ) )
return - V_10 ;
if ( ! V_212 && F_92 ( & V_191 , V_21 , NULL ) )
return - V_10 ;
F_94 (list, evsel) {
if ( V_212 && F_92 ( & V_191 , V_21 , V_41 ) )
return - V_10 ;
V_41 -> V_37 . V_193 = V_191 . V_192 ;
V_41 -> V_37 . V_195 = V_191 . V_194 ;
V_41 -> V_37 . V_197 = V_191 . V_196 ;
V_41 -> V_37 . V_205 = V_191 . V_204 ;
V_41 -> V_37 . V_199 = V_191 . V_198 ;
V_41 -> V_37 . V_201 = V_191 . V_200 ;
V_41 -> V_37 . V_203 = V_191 . V_202 ;
V_41 -> V_210 = V_191 . V_210 ;
V_41 -> V_207 = V_191 . V_207 ;
V_41 -> V_206 = V_191 . V_206 ;
if ( F_95 ( V_41 ) )
V_41 -> V_37 . V_208 = V_191 . V_208 ;
}
return 0 ;
}
int F_96 ( struct V_30 * V_34 , char * V_20 )
{
struct V_33 * V_41 ;
F_94 (list, evsel) {
if ( ! V_41 -> V_20 )
V_41 -> V_20 = F_15 ( V_20 ) ;
}
return 0 ;
}
static int
F_97 ( const void * V_213 , const void * V_214 )
{
struct V_215 * V_216 = (struct V_215 * ) V_213 ;
struct V_215 * V_217 = (struct V_215 * ) V_214 ;
return strcasecmp ( V_216 -> V_218 , V_217 -> V_218 ) ;
}
static void F_98 ( void )
{
if ( V_219 > 0 ) {
struct V_215 * V_211 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_219 ; V_48 ++ ) {
V_211 = V_220 + V_48 ;
free ( V_211 -> V_218 ) ;
}
free ( V_220 ) ;
V_220 = NULL ;
V_219 = 0 ;
}
}
static void F_99 ( void )
{
struct V_177 * V_178 = NULL ;
struct V_221 * V_222 ;
int V_120 = 0 ;
V_178 = F_82 ( L_47 ) ;
if ( ( V_178 == NULL ) || F_57 ( & V_178 -> V_223 ) ) {
V_219 = - 1 ;
return;
}
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_222 -> V_20 , '-' ) )
V_120 ++ ;
V_120 ++ ;
}
V_220 = malloc ( sizeof( struct V_215 ) * V_120 ) ;
if ( ! V_220 )
return;
V_219 = V_120 ;
V_120 = 0 ;
F_19 (alias, &pmu->aliases, list) {
struct V_215 * V_211 = V_220 + V_120 ;
char * V_96 = strchr ( V_222 -> V_20 , '-' ) ;
if ( V_96 != NULL ) {
F_100 ( F_14 ( V_222 -> V_20 , V_96 - V_222 -> V_20 ) ,
V_224 ) ;
V_211 ++ ;
F_100 ( F_15 ( ++ V_96 ) , V_225 ) ;
V_120 += 2 ;
} else {
F_100 ( F_15 ( V_222 -> V_20 ) , V_226 ) ;
V_120 ++ ;
}
}
qsort ( V_220 , V_120 ,
sizeof( struct V_215 ) , F_97 ) ;
return;
V_55:
F_98 () ;
}
enum V_227
F_101 ( const char * V_20 )
{
struct V_215 V_211 , * V_228 ;
if ( V_219 == 0 )
F_99 () ;
if ( ( V_219 <= 0 ) || ! strcmp ( V_20 , L_47 ) )
return V_229 ;
V_211 . V_218 = F_15 ( V_20 ) ;
V_228 = bsearch ( & V_211 , V_220 ,
( V_230 ) V_219 ,
sizeof( struct V_215 ) , F_97 ) ;
free ( V_211 . V_218 ) ;
return V_228 ? V_228 -> type : V_229 ;
}
static int F_102 ( const char * V_21 , void * V_94 , int V_231 )
{
T_9 V_232 ;
void * V_233 ;
int V_81 ;
V_81 = F_103 ( V_231 , & V_233 ) ;
if ( V_81 )
return V_81 ;
V_232 = F_104 ( V_21 , V_233 ) ;
#ifdef F_105
V_234 = 1 ;
#endif
V_81 = F_106 ( V_94 , V_233 ) ;
F_107 ( V_232 , V_233 ) ;
F_108 ( V_232 , V_233 ) ;
F_109 ( V_233 ) ;
return V_81 ;
}
int F_110 ( struct V_30 * V_235 , const char * V_21 )
{
struct F_110 V_94 = {
. V_235 = NULL ,
} ;
int V_81 ;
V_81 = F_102 ( V_21 , & V_94 , V_236 ) ;
if ( ! V_81 ) {
F_24 ( V_94 . V_235 , V_235 ) ;
F_12 ( & V_94 . V_235 ) ;
return 0 ;
}
F_111 ( V_94 . V_235 ) ;
return V_81 ;
}
int F_112 ( struct V_237 * V_93 , const char * V_21 ,
struct V_54 * V_55 )
{
struct V_92 V_94 = {
. V_34 = F_113 ( V_94 . V_34 ) ,
. V_35 = V_93 -> V_238 ,
. error = V_55 ,
. V_93 = V_93 ,
} ;
int V_81 ;
V_81 = F_102 ( V_21 , & V_94 , V_239 ) ;
F_98 () ;
if ( ! V_81 ) {
struct V_33 * V_240 ;
if ( F_57 ( & V_94 . V_34 ) ) {
F_88 ( true , L_48 ) ;
return - 1 ;
}
F_114 ( V_93 , & V_94 . V_34 ) ;
V_93 -> V_241 += V_94 . V_241 ;
V_240 = F_115 ( V_93 ) ;
V_240 -> V_242 = true ;
return 0 ;
}
return V_81 ;
}
static int F_116 ( void )
{
struct V_243 V_244 ;
F_117 ( & V_244 ) ;
return V_244 . V_245 > V_246 ? V_246 : V_244 . V_245 ;
}
static void F_118 ( struct V_54 * V_55 ,
const char * V_87 )
{
const char * V_21 = L_49 ;
char V_247 [ V_246 ] ;
char * V_248 = ( char * ) V_87 ;
int V_35 = 0 ;
if ( V_55 -> V_21 ) {
int V_249 = F_116 () - 2 ;
int V_250 = strlen ( V_87 ) ;
int V_251 , V_252 , V_253 = 0 ;
int V_254 = 13 ;
V_21 = L_50 ;
V_251 = strlen ( V_21 ) ;
V_252 = V_249 - V_251 ;
V_248 = V_247 ;
if ( V_55 -> V_35 > V_254 )
V_253 = V_55 -> V_35 - V_254 ;
strncpy ( V_248 , V_87 + V_253 , V_252 ) ;
if ( V_253 )
V_248 [ 0 ] = V_248 [ 1 ] = '.' ;
if ( ( V_250 - V_253 ) > V_252 ) {
V_248 [ V_252 - 1 ] = V_248 [ V_252 - 2 ] = '.' ;
V_248 [ V_252 ] = 0 ;
}
V_35 = V_251 + V_55 -> V_35 - V_253 ;
}
fprintf ( V_255 , L_51 , V_21 , V_248 ) ;
if ( V_35 ) {
fprintf ( V_255 , L_52 , V_35 + 1 , L_53 , V_55 -> V_21 ) ;
if ( V_55 -> V_74 )
fprintf ( V_255 , L_54 , V_55 -> V_74 ) ;
free ( V_55 -> V_21 ) ;
free ( V_55 -> V_74 ) ;
}
fprintf ( V_255 , L_55 ) ;
}
int F_119 ( const struct V_256 * V_257 , const char * V_21 ,
int T_10 V_155 )
{
struct V_237 * V_93 = * (struct V_237 * * ) V_257 -> V_258 ;
struct V_54 V_55 = { . V_35 = 0 , } ;
int V_81 = F_112 ( V_93 , V_21 , & V_55 ) ;
if ( V_81 )
F_118 ( & V_55 , V_21 ) ;
return V_81 ;
}
static int
F_120 ( struct V_237 * V_93 ,
int (* F_121)( struct V_33 * V_41 ,
const void * V_259 ) ,
const void * V_259 )
{
struct V_33 * V_240 = NULL ;
int V_55 ;
if ( V_93 -> V_238 > 0 )
V_240 = F_115 ( V_93 ) ;
do {
V_55 = (* F_121)( V_240 , V_259 ) ;
if ( V_55 )
return - 1 ;
if ( ! V_240 )
return 0 ;
if ( V_240 -> V_43 . V_260 == & V_93 -> V_261 )
return 0 ;
V_240 = F_90 ( V_240 -> V_43 . V_260 , struct V_33 , V_43 ) ;
} while ( ! V_240 -> V_242 );
return 0 ;
}
static int F_122 ( struct V_33 * V_41 , const void * V_259 )
{
const char * V_21 = V_259 ;
bool V_82 = false ;
int V_262 = 0 ;
struct V_177 * V_178 = NULL ;
if ( V_41 == NULL )
goto V_55;
if ( V_41 -> V_37 . type == V_24 ) {
if ( F_123 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_255 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
while ( ( V_178 = F_124 ( V_178 ) ) != NULL )
if ( V_178 -> type == V_41 -> V_37 . type ) {
V_82 = true ;
break;
}
if ( V_82 )
F_125 ( V_178 , L_57 ,
L_58 , & V_262 ) ;
if ( ! V_262 )
goto V_55;
if ( F_126 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_255 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
V_55:
fprintf ( V_255 ,
L_59 ) ;
return - 1 ;
}
int F_127 ( const struct V_256 * V_257 , const char * V_21 ,
int T_10 V_155 )
{
struct V_237 * V_93 = * (struct V_237 * * ) V_257 -> V_258 ;
return F_120 ( V_93 , F_122 ,
( const void * ) V_21 ) ;
}
static int F_128 ( struct V_33 * V_41 ,
const void * V_259 V_155 )
{
char V_263 [ 64 ] ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_255 ,
L_60 ) ;
return - 1 ;
}
snprintf ( V_263 , sizeof( V_263 ) , L_61 , F_129 () ) ;
if ( F_123 ( V_41 , V_263 ) < 0 ) {
fprintf ( V_255 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
int F_130 ( const struct V_256 * V_257 ,
const char * V_259 V_155 ,
int T_10 V_155 )
{
struct V_237 * V_93 = * (struct V_237 * * ) V_257 -> V_258 ;
return F_120 ( V_93 , F_128 ,
NULL ) ;
}
static int F_131 ( const void * V_264 , const void * V_265 )
{
const char * const * V_266 = V_264 ;
const char * const * V_267 = V_265 ;
return strcmp ( * V_266 , * V_267 ) ;
}
void F_132 ( const char * V_268 , const char * V_269 ,
bool V_270 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_271 = NULL ;
unsigned int V_272 = 0 , V_273 = 0 ;
bool V_274 = false ;
V_275:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_274 ) {
V_271 = F_11 ( sizeof( char * ) * V_273 ) ;
if ( ! V_271 )
goto V_276;
}
F_6 (sys_dir, sys_dirent) {
if ( V_268 != NULL &&
! F_41 ( V_14 -> V_8 , V_268 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_269 != NULL &&
! F_41 ( V_15 -> V_8 , V_269 ) )
continue;
if ( ! V_274 ) {
V_273 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_62 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_271 [ V_272 ] = F_15 ( V_4 ) ;
if ( V_271 [ V_272 ] == NULL )
goto V_277;
V_272 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_274 ) {
V_274 = true ;
goto V_275;
}
qsort ( V_271 , V_273 , sizeof( char * ) , F_131 ) ;
V_272 = 0 ;
while ( V_272 < V_273 ) {
if ( V_270 ) {
printf ( L_63 , V_271 [ V_272 ++ ] ) ;
continue;
}
printf ( L_64 , V_271 [ V_272 ++ ] ,
V_278 [ V_24 ] ) ;
}
if ( V_273 && F_133 () )
printf ( L_32 ) ;
V_279:
V_273 = V_272 ;
for ( V_272 = 0 ; V_272 < V_273 ; V_272 ++ )
F_12 ( & V_271 [ V_272 ] ) ;
F_12 ( & V_271 ) ;
return;
V_277:
F_10 ( V_3 ) ;
V_276:
F_10 ( V_2 ) ;
printf ( L_65 ,
V_278 [ V_24 ] ) ;
if ( V_271 )
goto V_279;
}
int F_134 ( const char * V_280 )
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
snprintf ( V_4 , V_5 , L_62 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
if ( ! strcmp ( V_4 , V_280 ) ) {
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
static bool F_135 ( T_11 type , unsigned V_12 )
{
bool V_81 = true ;
int V_281 ;
struct V_33 * V_41 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_282 = 1 ,
} ;
struct {
struct V_283 V_284 ;
int V_285 [ 1 ] ;
} V_286 = {
. V_284 . V_287 = 1 ,
. V_285 = { 0 } ,
} ;
V_41 = F_136 ( & V_37 ) ;
if ( V_41 ) {
V_281 = F_137 ( V_41 , NULL , & V_286 . V_284 ) ;
V_81 = V_281 >= 0 ;
if ( V_281 == - V_76 ) {
V_41 -> V_37 . V_195 = 1 ;
V_81 = F_137 ( V_41 , NULL , & V_286 . V_284 ) >= 0 ;
}
F_49 ( V_41 ) ;
}
return V_81 ;
}
void F_138 ( const char * V_268 , const char * V_269 ,
bool V_270 )
{
struct V_288 * V_289 ;
struct V_290 * V_291 ;
struct V_292 * V_293 , * V_294 ;
struct V_295 V_296 = { . V_297 = true } ;
struct V_298 * V_299 , * V_300 ;
char * V_248 , * V_13 , * V_119 = NULL ;
bool V_301 = false ;
int V_81 ;
V_294 = F_139 ( NULL , & V_296 ) ;
if ( ! V_294 ) {
F_45 ( L_66 ) ;
return;
}
V_293 = F_140 ( true ) ;
if ( ! V_293 ) {
F_45 ( L_67 , V_83 ) ;
return;
}
F_141 (nd, bidlist) {
V_289 = F_142 ( V_299 -> V_302 ) ;
if ( ! V_289 )
continue;
F_19 (ent, &pcache->entries, node) {
if ( ! V_291 -> V_303 )
continue;
if ( V_268 &&
! F_41 ( V_291 -> V_304 . V_86 , V_268 ) )
continue;
if ( V_269 &&
! F_41 ( V_291 -> V_304 . V_87 , V_269 ) )
continue;
V_81 = F_72 ( & V_248 , L_68 , V_291 -> V_304 . V_86 ,
V_291 -> V_304 . V_87 , V_299 -> V_302 ) ;
if ( V_81 > 0 )
F_143 ( V_294 , V_248 ) ;
}
F_144 ( V_289 ) ;
}
F_145 ( V_293 ) ;
F_141 (nd, sdtlist) {
V_248 = strchr ( V_299 -> V_302 , '@' ) ;
if ( V_248 )
* ( V_248 ++ ) = '\0' ;
if ( V_270 ) {
printf ( L_63 , V_299 -> V_302 ) ;
continue;
}
V_300 = F_146 ( V_299 ) ;
if ( V_300 ) {
V_119 = strchr ( V_300 -> V_302 , '@' ) ;
if ( V_119 )
* V_119 = '\0' ;
if ( strcmp ( V_299 -> V_302 , V_300 -> V_302 ) == 0 )
V_301 = true ;
}
if ( V_301 ) {
V_13 = F_147 ( V_248 ) ;
V_81 = F_72 ( & V_248 , L_69 , V_299 -> V_302 , V_13 , V_248 ) ;
if ( V_81 > 0 ) {
printf ( L_64 , V_248 , L_70 ) ;
free ( V_248 ) ;
}
} else
printf ( L_64 , V_299 -> V_302 , L_70 ) ;
if ( V_300 ) {
if ( strcmp ( V_299 -> V_302 , V_300 -> V_302 ) != 0 )
V_301 = false ;
if ( V_119 )
* V_119 = '@' ;
}
}
F_145 ( V_294 ) ;
}
int F_148 ( const char * V_269 , bool V_270 )
{
unsigned int type , V_305 , V_48 , V_272 = 0 , V_273 = 0 ;
char V_20 [ 64 ] ;
char * * V_271 = NULL ;
bool V_274 = false ;
V_275:
if ( V_274 ) {
V_271 = F_11 ( sizeof( char * ) * V_273 ) ;
if ( ! V_271 )
goto V_306;
}
for ( type = 0 ; type < V_64 ; type ++ ) {
for ( V_305 = 0 ; V_305 < V_66 ; V_305 ++ ) {
if ( ! F_30 ( type , V_305 ) )
continue;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
F_149 ( type , V_305 , V_48 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_269 != NULL && ! F_41 ( V_20 , V_269 ) )
continue;
if ( ! F_135 ( V_25 ,
type | ( V_305 << 8 ) | ( V_48 << 16 ) ) )
continue;
if ( ! V_274 ) {
V_273 ++ ;
continue;
}
V_271 [ V_272 ] = F_15 ( V_20 ) ;
if ( V_271 [ V_272 ] == NULL )
goto V_306;
V_272 ++ ;
}
}
}
if ( ! V_274 ) {
V_274 = true ;
goto V_275;
}
qsort ( V_271 , V_273 , sizeof( char * ) , F_131 ) ;
V_272 = 0 ;
while ( V_272 < V_273 ) {
if ( V_270 ) {
printf ( L_63 , V_271 [ V_272 ++ ] ) ;
continue;
}
printf ( L_64 , V_271 [ V_272 ++ ] ,
V_278 [ V_25 ] ) ;
}
if ( V_273 && F_133 () )
printf ( L_32 ) ;
V_279:
V_273 = V_272 ;
for ( V_272 = 0 ; V_272 < V_273 ; V_272 ++ )
F_12 ( & V_271 [ V_272 ] ) ;
F_12 ( & V_271 ) ;
return V_273 ;
V_306:
printf ( L_65 , V_278 [ V_25 ] ) ;
if ( V_271 )
goto V_279;
return V_273 ;
}
void F_150 ( const char * V_269 , unsigned type ,
struct V_307 * V_308 , unsigned V_309 ,
bool V_270 )
{
unsigned int V_48 , V_272 = 0 , V_273 = 0 ;
char V_20 [ V_57 ] ;
char * * V_271 = NULL ;
bool V_274 = false ;
V_275:
if ( V_274 ) {
V_271 = F_11 ( sizeof( char * ) * V_273 ) ;
if ( ! V_271 )
goto V_306;
V_308 -= V_309 ;
}
for ( V_48 = 0 ; V_48 < V_309 ; V_48 ++ , V_308 ++ ) {
if ( V_269 != NULL && V_308 -> V_218 != NULL &&
! ( F_41 ( V_308 -> V_218 , V_269 ) ||
( V_308 -> V_222 && F_41 ( V_308 -> V_222 , V_269 ) ) ) )
continue;
if ( ! F_135 ( type , V_48 ) )
continue;
if ( ! V_274 ) {
V_273 ++ ;
continue;
}
if ( ! V_270 && strlen ( V_308 -> V_222 ) )
snprintf ( V_20 , V_57 , L_71 , V_308 -> V_218 , V_308 -> V_222 ) ;
else
strncpy ( V_20 , V_308 -> V_218 , V_57 ) ;
V_271 [ V_272 ] = F_15 ( V_20 ) ;
if ( V_271 [ V_272 ] == NULL )
goto V_306;
V_272 ++ ;
}
if ( ! V_274 ) {
V_274 = true ;
goto V_275;
}
qsort ( V_271 , V_273 , sizeof( char * ) , F_131 ) ;
V_272 = 0 ;
while ( V_272 < V_273 ) {
if ( V_270 ) {
printf ( L_63 , V_271 [ V_272 ++ ] ) ;
continue;
}
printf ( L_64 , V_271 [ V_272 ++ ] , V_278 [ type ] ) ;
}
if ( V_273 && F_133 () )
printf ( L_32 ) ;
V_279:
V_273 = V_272 ;
for ( V_272 = 0 ; V_272 < V_273 ; V_272 ++ )
F_12 ( & V_271 [ V_272 ] ) ;
F_12 ( & V_271 ) ;
return;
V_306:
printf ( L_65 , V_278 [ type ] ) ;
if ( V_271 )
goto V_279;
}
void F_151 ( const char * V_269 , bool V_270 , bool V_310 ,
bool V_311 )
{
F_150 ( V_269 , V_22 ,
V_312 , V_313 , V_270 ) ;
F_150 ( V_269 , V_23 ,
V_314 , V_315 , V_270 ) ;
F_148 ( V_269 , V_270 ) ;
F_152 ( V_269 , V_270 , V_310 , V_311 ) ;
if ( V_269 != NULL )
return;
if ( ! V_270 ) {
printf ( L_64 ,
L_72 ,
V_278 [ V_316 ] ) ;
printf ( L_64 ,
L_73 ,
V_278 [ V_316 ] ) ;
if ( F_133 () )
printf ( L_74 ) ;
printf ( L_64 ,
L_75 ,
V_278 [ V_124 ] ) ;
if ( F_133 () )
printf ( L_32 ) ;
}
F_132 ( NULL , NULL , V_270 ) ;
F_138 ( NULL , NULL , V_270 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_105 ;
}
static int F_153 ( struct V_26 * * V_317 , int V_126 ,
int V_28 , char * V_12 ,
char * V_21 , T_1 V_137 , int V_106 , int V_108 )
{
struct V_26 * V_27 ;
V_27 = F_11 ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_44 ;
F_154 ( & V_27 -> V_34 ) ;
V_27 -> V_126 = V_126 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_106 = V_106 ;
V_27 -> V_108 = V_108 ;
switch ( V_126 ) {
case V_127 :
V_27 -> V_32 . V_137 = V_137 ;
break;
case V_318 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_317 = V_27 ;
return 0 ;
}
int F_155 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_137 ,
void * V_319 , void * V_320 )
{
T_12 * V_321 = V_319 ;
T_12 * V_322 = V_320 ;
return F_153 ( V_27 , V_127 , V_28 ,
V_12 , NULL , V_137 ,
V_321 ? V_321 -> V_323 : 0 ,
V_322 ? V_322 -> V_323 : 0 ) ;
}
int F_156 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_319 , void * V_320 )
{
T_12 * V_321 = V_319 ;
T_12 * V_322 = V_320 ;
return F_153 ( V_27 , V_318 , V_28 ,
V_12 , V_21 , 0 ,
V_321 ? V_321 -> V_323 : 0 ,
V_322 ? V_322 -> V_323 : 0 ) ;
}
int F_157 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_307 * V_324 ;
F_158 ( V_35 >= V_313 ) ;
V_324 = & V_312 [ V_35 ] ;
if ( V_12 )
return F_153 ( V_27 , V_318 ,
V_105 , V_12 ,
( char * ) V_324 -> V_218 , 0 , 0 , 0 ) ;
else
return F_153 ( V_27 , V_318 ,
V_105 ,
( char * ) L_76 , ( char * ) V_324 -> V_218 ,
0 , 0 , 0 ) ;
}
int F_159 ( struct V_26 * * V_325 ,
struct V_26 * V_27 )
{
return F_153 ( V_325 , V_27 -> V_126 , V_27 -> V_28 , V_27 -> V_12 ,
V_27 -> V_32 . V_21 , V_27 -> V_32 . V_137 ,
V_27 -> V_106 , V_27 -> V_108 ) ;
}
void F_160 ( struct V_30 * V_235 )
{
struct V_26 * V_27 , * V_326 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_327 . V_328 )
free ( V_27 -> V_327 . V_329 ) ;
F_161 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_111 ( struct V_30 * V_235 )
{
if ( ! V_235 )
return;
F_160 ( V_235 ) ;
free ( V_235 ) ;
}
void F_162 ( struct V_330 * V_264 )
{
free ( V_264 -> V_329 ) ;
}
void F_163 ( struct V_92 * V_94 ,
int V_35 , const char * V_21 )
{
struct V_54 * V_55 = V_94 -> error ;
if ( ! V_55 )
return;
V_55 -> V_35 = V_35 ;
V_55 -> V_21 = F_15 ( V_21 ) ;
F_88 ( ! V_55 -> V_21 , L_77 ) ;
}
static void F_164 ( char * V_248 , V_230 V_331 )
{
int V_48 ;
bool V_332 = true ;
V_248 [ 0 ] = '\0' ;
for ( V_48 = 0 ; V_48 < V_129 ; V_48 ++ ) {
const char * V_20 = V_135 [ V_48 ] ;
if ( ! F_71 ( V_48 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_248 ) + strlen ( V_20 ) + 2 >= V_331 )
return;
if ( ! V_332 )
strcat ( V_248 , L_78 ) ;
else
V_332 = false ;
strcat ( V_248 , V_20 ) ;
}
}
char * F_76 ( char * V_333 )
{
char * V_21 ;
char V_334 [ V_129 *
( sizeof( L_79 ) - 1 ) ] ;
F_164 ( V_334 , sizeof( V_334 ) ) ;
if ( V_333 ) {
if ( F_72 ( & V_21 , L_80 ,
V_333 , V_334 ) < 0 )
goto V_335;
} else {
if ( F_72 ( & V_21 , L_81 , V_334 ) < 0 )
goto V_335;
}
return V_21 ;
V_335:
return NULL ;
}
