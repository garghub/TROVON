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
break;
case V_142 :
F_74 ( V_136 ) ;
if ( V_27 -> V_32 . V_137 > 1 ) {
V_55 -> V_21 = F_15 ( L_40 ) ;
V_55 -> V_35 = V_27 -> V_108 ;
return - V_10 ;
}
break;
case V_143 :
F_74 ( V_144 ) ;
break;
case V_145 :
F_74 ( V_136 ) ;
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
case V_29 :
F_74 ( V_144 ) ;
break;
case V_150 :
F_74 ( V_136 ) ;
break;
default:
V_55 -> V_21 = F_15 ( L_41 ) ;
V_55 -> V_35 = V_27 -> V_106 ;
V_55 -> V_74 = F_75 ( NULL ) ;
return - V_10 ;
}
if ( ! F_71 ( V_27 -> V_28 , V_55 ) )
return - V_10 ;
return 0 ;
#undef F_74
}
static int F_76 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
if ( V_27 -> V_28 == V_105 ||
V_27 -> V_28 == V_151 )
return 0 ;
else
return V_71 ( V_37 , V_27 , V_55 ) ;
}
static int F_77 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
switch ( V_27 -> V_28 ) {
case V_143 :
case V_145 :
case V_146 :
case V_147 :
case V_150 :
case V_148 :
case V_149 :
return V_71 ( V_37 , V_27 , V_55 ) ;
default:
if ( V_55 ) {
V_55 -> V_35 = V_27 -> V_106 ;
V_55 -> V_21 = F_15 ( L_41 ) ;
V_55 -> V_74 = F_15 ( L_42 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_30 * V_152 ,
struct V_54 * V_55 ,
T_4 V_153 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_153 ( V_37 , V_27 , V_55 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_56 ,
struct V_30 * V_31 V_154 )
{
#define F_78 ( T_5 , T_6 , T_7 ) \
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
F_78 ( V_155 , V_156 , V_27 -> V_32 . V_137 ) ;
break;
case V_140 :
F_78 ( V_157 , V_158 , V_27 -> V_32 . V_137 ) ;
break;
case V_142 :
F_78 ( TIME , time , V_27 -> V_32 . V_137 ) ;
break;
case V_143 :
F_78 ( V_159 , V_160 , V_27 -> V_32 . V_21 ) ;
break;
case V_145 :
F_78 ( V_161 , V_162 , V_27 -> V_32 . V_137 ) ;
break;
case V_146 :
F_78 ( V_163 , V_164 , V_27 -> V_32 . V_137 ? 1 : 0 ) ;
break;
case V_147 :
F_78 ( V_163 , V_164 , V_27 -> V_32 . V_137 ? 0 : 1 ) ;
break;
case V_150 :
F_78 ( V_165 , V_166 , V_27 -> V_32 . V_137 ) ;
break;
case V_148 :
F_78 ( V_167 , V_168 , V_27 -> V_32 . V_137 ? 1 : 0 ) ;
break;
case V_149 :
F_78 ( V_167 , V_168 , V_27 -> V_32 . V_137 ? 0 : 1 ) ;
break;
case V_151 :
F_78 ( V_169 , V_170 , V_27 -> V_32 . V_21 ) ;
break;
default:
break;
}
}
#undef V_171
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
F_77 ) )
return - V_10 ;
}
if ( strpbrk ( V_73 , L_18 ) )
return F_43 ( V_34 , V_35 , V_73 , V_87 ,
V_55 , V_56 ) ;
else
return F_42 ( V_34 , V_35 , V_73 , V_87 ,
V_55 , V_56 ) ;
}
int F_79 ( struct V_92 * V_94 ,
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
int F_80 ( struct V_92 * V_94 ,
struct V_30 * V_34 , char * V_20 ,
struct V_30 * V_56 )
{
struct V_36 V_37 ;
struct V_172 V_173 ;
struct V_174 * V_175 ;
struct V_33 * V_41 ;
F_29 ( V_40 ) ;
V_175 = F_81 ( V_20 ) ;
if ( ! V_175 )
return - V_10 ;
if ( V_175 -> V_176 ) {
memcpy ( & V_37 , V_175 -> V_176 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_56 ) {
V_37 . type = V_175 -> type ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 , NULL , V_175 -> V_39 , NULL ) ;
return V_41 ? 0 : - V_44 ;
}
if ( F_82 ( V_175 , V_56 , & V_173 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_56 , V_94 -> error , F_76 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
if ( F_83 ( V_175 , & V_37 , V_56 , V_94 -> error ) )
return - V_10 ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 ,
F_18 ( V_56 ) , V_175 -> V_39 ,
& V_40 ) ;
if ( V_41 ) {
V_41 -> V_177 = V_173 . V_177 ;
V_41 -> V_178 = V_173 . V_178 ;
V_41 -> V_179 = V_173 . V_179 ;
V_41 -> V_180 = V_173 . V_180 ;
}
return V_41 ? 0 : - V_44 ;
}
int F_84 ( struct V_30 * V_34 ,
char * V_181 )
{
return F_85 ( V_34 , V_181 , true ) ;
}
void F_86 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_182 ;
if ( F_57 ( V_34 ) ) {
F_87 ( true , L_43 ) ;
return;
}
F_88 ( V_34 ) ;
V_182 = F_89 ( V_34 -> V_183 , struct V_33 , V_43 ) ;
V_182 -> V_184 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_90 ( struct V_30 * V_185 ,
struct V_30 * V_186 )
{
F_66 ( V_185 , V_186 ) ;
free ( V_185 ) ;
}
static int F_91 ( struct V_187 * V_188 , char * V_21 ,
struct V_33 * V_41 )
{
int V_189 = V_41 ? V_41 -> V_37 . V_190 : 0 ;
int V_191 = V_41 ? V_41 -> V_37 . V_192 : 0 ;
int V_193 = V_41 ? V_41 -> V_37 . V_194 : 0 ;
int V_195 = V_41 ? V_41 -> V_37 . V_196 : 0 ;
int V_197 = V_41 ? V_41 -> V_37 . V_198 : 0 ;
int V_199 = V_41 ? V_41 -> V_37 . V_200 : 0 ;
int V_201 = V_41 ? V_41 -> V_37 . V_202 : 0 ;
int V_203 = 0 ;
int V_204 = 0 ;
int V_205 = V_41 ? V_41 -> V_37 . V_205 : 0 ;
int V_206 = V_189 | V_191 | V_193 ;
int V_207 = V_41 ? V_41 -> V_207 : 0 ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_206 )
V_206 = V_189 = V_191 = V_193 = 1 ;
V_189 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_206 )
V_206 = V_189 = V_191 = V_193 = 1 ;
V_191 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_206 )
V_206 = V_189 = V_191 = V_193 = 1 ;
V_193 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_207 )
V_207 = V_197 = V_195 = 1 ;
V_197 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_207 )
V_207 = V_197 = V_195 = 1 ;
V_195 = 0 ;
} else if ( * V_21 == 'I' ) {
V_199 = 1 ;
} else if ( * V_21 == 'p' ) {
V_201 ++ ;
if ( ! V_207 )
V_197 = 1 ;
} else if ( * V_21 == 'P' ) {
V_203 = 1 ;
} else if ( * V_21 == 'S' ) {
V_204 = 1 ;
} else if ( * V_21 == 'D' ) {
V_205 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_201 > 3 )
return - V_10 ;
V_188 -> V_189 = V_189 ;
V_188 -> V_191 = V_191 ;
V_188 -> V_193 = V_193 ;
V_188 -> V_195 = V_195 ;
V_188 -> V_197 = V_197 ;
V_188 -> V_199 = V_199 ;
V_188 -> V_201 = V_201 ;
V_188 -> V_203 = V_203 ;
V_188 -> V_207 = V_207 ;
V_188 -> V_204 = V_204 ;
V_188 -> V_205 = V_205 ;
return 0 ;
}
static int F_92 ( char * V_21 )
{
char * V_208 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_44 ) - 1 ) )
return - 1 ;
while ( * V_208 ) {
if ( * V_208 != 'p' && strchr ( V_208 + 1 , * V_208 ) )
return - 1 ;
V_208 ++ ;
}
return 0 ;
}
int F_85 ( struct V_30 * V_34 , char * V_21 , bool V_209 )
{
struct V_33 * V_41 ;
struct V_187 V_188 ;
if ( V_21 == NULL )
return 0 ;
if ( F_92 ( V_21 ) )
return - V_10 ;
if ( ! V_209 && F_91 ( & V_188 , V_21 , NULL ) )
return - V_10 ;
F_93 (list, evsel) {
if ( V_209 && F_91 ( & V_188 , V_21 , V_41 ) )
return - V_10 ;
V_41 -> V_37 . V_190 = V_188 . V_189 ;
V_41 -> V_37 . V_192 = V_188 . V_191 ;
V_41 -> V_37 . V_194 = V_188 . V_193 ;
V_41 -> V_37 . V_202 = V_188 . V_201 ;
V_41 -> V_37 . V_196 = V_188 . V_195 ;
V_41 -> V_37 . V_198 = V_188 . V_197 ;
V_41 -> V_37 . V_200 = V_188 . V_199 ;
V_41 -> V_207 = V_188 . V_207 ;
V_41 -> V_204 = V_188 . V_204 ;
V_41 -> V_203 = V_188 . V_203 ;
if ( F_94 ( V_41 ) )
V_41 -> V_37 . V_205 = V_188 . V_205 ;
}
return 0 ;
}
int F_95 ( struct V_30 * V_34 , char * V_20 )
{
struct V_33 * V_41 ;
F_93 (list, evsel) {
if ( ! V_41 -> V_20 )
V_41 -> V_20 = F_15 ( V_20 ) ;
}
return 0 ;
}
static int
F_96 ( const void * V_210 , const void * V_211 )
{
struct V_212 * V_213 = (struct V_212 * ) V_210 ;
struct V_212 * V_214 = (struct V_212 * ) V_211 ;
return strcasecmp ( V_213 -> V_215 , V_214 -> V_215 ) ;
}
static void F_97 ( void )
{
if ( V_216 > 0 ) {
struct V_212 * V_208 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_216 ; V_48 ++ ) {
V_208 = V_217 + V_48 ;
free ( V_208 -> V_215 ) ;
}
free ( V_217 ) ;
V_217 = NULL ;
V_216 = 0 ;
}
}
static void F_98 ( void )
{
struct V_174 * V_175 = NULL ;
struct V_218 * V_219 ;
int V_120 = 0 ;
V_175 = F_81 ( L_45 ) ;
if ( ( V_175 == NULL ) || F_57 ( & V_175 -> V_220 ) ) {
V_216 = - 1 ;
return;
}
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_219 -> V_20 , '-' ) )
V_120 ++ ;
V_120 ++ ;
}
V_217 = malloc ( sizeof( struct V_212 ) * V_120 ) ;
if ( ! V_217 )
return;
V_216 = V_120 ;
V_120 = 0 ;
F_19 (alias, &pmu->aliases, list) {
struct V_212 * V_208 = V_217 + V_120 ;
char * V_96 = strchr ( V_219 -> V_20 , '-' ) ;
if ( V_96 != NULL ) {
F_99 ( F_14 ( V_219 -> V_20 , V_96 - V_219 -> V_20 ) ,
V_221 ) ;
V_208 ++ ;
F_99 ( F_15 ( ++ V_96 ) , V_222 ) ;
V_120 += 2 ;
} else {
F_99 ( F_15 ( V_219 -> V_20 ) , V_223 ) ;
V_120 ++ ;
}
}
qsort ( V_217 , V_120 ,
sizeof( struct V_212 ) , F_96 ) ;
return;
V_55:
F_97 () ;
}
enum V_224
F_100 ( const char * V_20 )
{
struct V_212 V_208 , * V_225 ;
if ( V_216 == 0 )
F_98 () ;
if ( ( V_216 <= 0 ) || ! strcmp ( V_20 , L_45 ) )
return V_226 ;
V_208 . V_215 = F_15 ( V_20 ) ;
V_225 = bsearch ( & V_208 , V_217 ,
( V_227 ) V_216 ,
sizeof( struct V_212 ) , F_96 ) ;
free ( V_208 . V_215 ) ;
return V_225 ? V_225 -> type : V_226 ;
}
static int F_101 ( const char * V_21 , void * V_94 , int V_228 )
{
T_9 V_229 ;
void * V_230 ;
int V_81 ;
V_81 = F_102 ( V_228 , & V_230 ) ;
if ( V_81 )
return V_81 ;
V_229 = F_103 ( V_21 , V_230 ) ;
#ifdef F_104
V_231 = 1 ;
#endif
V_81 = F_105 ( V_94 , V_230 ) ;
F_106 ( V_229 , V_230 ) ;
F_107 ( V_229 , V_230 ) ;
F_108 ( V_230 ) ;
return V_81 ;
}
int F_109 ( struct V_30 * V_232 , const char * V_21 )
{
struct F_109 V_94 = {
. V_232 = NULL ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_233 ) ;
if ( ! V_81 ) {
F_24 ( V_94 . V_232 , V_232 ) ;
F_12 ( & V_94 . V_232 ) ;
return 0 ;
}
F_110 ( V_94 . V_232 ) ;
return V_81 ;
}
int F_111 ( struct V_234 * V_93 , const char * V_21 ,
struct V_54 * V_55 )
{
struct V_92 V_94 = {
. V_34 = F_112 ( V_94 . V_34 ) ,
. V_35 = V_93 -> V_235 ,
. error = V_55 ,
. V_93 = V_93 ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_236 ) ;
F_97 () ;
if ( ! V_81 ) {
struct V_33 * V_237 ;
if ( F_57 ( & V_94 . V_34 ) ) {
F_87 ( true , L_46 ) ;
return - 1 ;
}
F_113 ( V_93 , & V_94 . V_34 ) ;
V_93 -> V_238 += V_94 . V_238 ;
V_237 = F_114 ( V_93 ) ;
V_237 -> V_239 = true ;
return 0 ;
}
return V_81 ;
}
static int F_115 ( void )
{
struct V_240 V_241 ;
F_116 ( & V_241 ) ;
return V_241 . V_242 > V_243 ? V_243 : V_241 . V_242 ;
}
static void F_117 ( struct V_54 * V_55 ,
const char * V_87 )
{
const char * V_21 = L_47 ;
char V_244 [ V_243 ] ;
char * V_245 = ( char * ) V_87 ;
int V_35 = 0 ;
if ( V_55 -> V_21 ) {
int V_246 = F_115 () - 2 ;
int V_247 = strlen ( V_87 ) ;
int V_248 , V_249 , V_250 = 0 ;
int V_251 = 13 ;
V_21 = L_48 ;
V_248 = strlen ( V_21 ) ;
V_249 = V_246 - V_248 ;
V_245 = V_244 ;
if ( V_55 -> V_35 > V_251 )
V_250 = V_55 -> V_35 - V_251 ;
strncpy ( V_245 , V_87 + V_250 , V_249 ) ;
if ( V_250 )
V_245 [ 0 ] = V_245 [ 1 ] = '.' ;
if ( ( V_247 - V_250 ) > V_249 ) {
V_245 [ V_249 - 1 ] = V_245 [ V_249 - 2 ] = '.' ;
V_245 [ V_249 ] = 0 ;
}
V_35 = V_248 + V_55 -> V_35 - V_250 ;
}
fprintf ( V_252 , L_49 , V_21 , V_245 ) ;
if ( V_35 ) {
fprintf ( V_252 , L_50 , V_35 + 1 , L_51 , V_55 -> V_21 ) ;
if ( V_55 -> V_74 )
fprintf ( V_252 , L_52 , V_55 -> V_74 ) ;
free ( V_55 -> V_21 ) ;
free ( V_55 -> V_74 ) ;
}
fprintf ( V_252 , L_53 ) ;
}
int F_118 ( const struct V_253 * V_254 , const char * V_21 ,
int T_10 V_154 )
{
struct V_234 * V_93 = * (struct V_234 * * ) V_254 -> V_255 ;
struct V_54 V_55 = { . V_35 = 0 , } ;
int V_81 = F_111 ( V_93 , V_21 , & V_55 ) ;
if ( V_81 )
F_117 ( & V_55 , V_21 ) ;
return V_81 ;
}
static int
F_119 ( struct V_234 * V_93 ,
int (* F_120)( struct V_33 * V_41 ,
const void * V_256 ) ,
const void * V_256 )
{
struct V_33 * V_237 = NULL ;
int V_55 ;
if ( V_93 -> V_235 > 0 )
V_237 = F_114 ( V_93 ) ;
do {
V_55 = (* F_120)( V_237 , V_256 ) ;
if ( V_55 )
return - 1 ;
if ( ! V_237 )
return 0 ;
if ( V_237 -> V_43 . V_257 == & V_93 -> V_258 )
return 0 ;
V_237 = F_89 ( V_237 -> V_43 . V_257 , struct V_33 , V_43 ) ;
} while ( ! V_237 -> V_239 );
return 0 ;
}
static int F_121 ( struct V_33 * V_41 , const void * V_256 )
{
const char * V_21 = V_256 ;
bool V_82 = false ;
int V_259 = 0 ;
struct V_174 * V_175 = NULL ;
if ( V_41 == NULL )
goto V_55;
if ( V_41 -> V_37 . type == V_24 ) {
if ( F_122 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_252 ,
L_54 ) ;
return - 1 ;
}
return 0 ;
}
while ( ( V_175 = F_123 ( V_175 ) ) != NULL )
if ( V_175 -> type == V_41 -> V_37 . type ) {
V_82 = true ;
break;
}
if ( V_82 )
F_124 ( V_175 , L_55 ,
L_56 , & V_259 ) ;
if ( ! V_259 )
goto V_55;
if ( F_125 ( V_41 , V_21 ) < 0 ) {
fprintf ( V_252 ,
L_54 ) ;
return - 1 ;
}
return 0 ;
V_55:
fprintf ( V_252 ,
L_57 ) ;
return - 1 ;
}
int F_126 ( const struct V_253 * V_254 , const char * V_21 ,
int T_10 V_154 )
{
struct V_234 * V_93 = * (struct V_234 * * ) V_254 -> V_255 ;
return F_119 ( V_93 , F_121 ,
( const void * ) V_21 ) ;
}
static int F_127 ( struct V_33 * V_41 ,
const void * V_256 V_154 )
{
char V_260 [ 64 ] ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_252 ,
L_58 ) ;
return - 1 ;
}
snprintf ( V_260 , sizeof( V_260 ) , L_59 , F_128 () ) ;
if ( F_122 ( V_41 , V_260 ) < 0 ) {
fprintf ( V_252 ,
L_54 ) ;
return - 1 ;
}
return 0 ;
}
int F_129 ( const struct V_253 * V_254 ,
const char * V_256 V_154 ,
int T_10 V_154 )
{
struct V_234 * V_93 = * (struct V_234 * * ) V_254 -> V_255 ;
return F_119 ( V_93 , F_127 ,
NULL ) ;
}
static int F_130 ( const void * V_261 , const void * V_262 )
{
const char * const * V_263 = V_261 ;
const char * const * V_264 = V_262 ;
return strcmp ( * V_263 , * V_264 ) ;
}
void F_131 ( const char * V_265 , const char * V_266 ,
bool V_267 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_268 = NULL ;
unsigned int V_269 = 0 , V_270 = 0 ;
bool V_271 = false ;
V_272:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_271 ) {
V_268 = F_11 ( sizeof( char * ) * V_270 ) ;
if ( ! V_268 )
goto V_273;
}
F_6 (sys_dir, sys_dirent) {
if ( V_265 != NULL &&
! F_41 ( V_14 -> V_8 , V_265 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_266 != NULL &&
! F_41 ( V_15 -> V_8 , V_266 ) )
continue;
if ( ! V_271 ) {
V_270 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_60 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_268 [ V_269 ] = F_15 ( V_4 ) ;
if ( V_268 [ V_269 ] == NULL )
goto V_274;
V_269 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_271 ) {
V_271 = true ;
goto V_272;
}
qsort ( V_268 , V_270 , sizeof( char * ) , F_130 ) ;
V_269 = 0 ;
while ( V_269 < V_270 ) {
if ( V_267 ) {
printf ( L_61 , V_268 [ V_269 ++ ] ) ;
continue;
}
printf ( L_62 , V_268 [ V_269 ++ ] ,
V_275 [ V_24 ] ) ;
}
if ( V_270 && F_132 () )
printf ( L_32 ) ;
V_276:
V_270 = V_269 ;
for ( V_269 = 0 ; V_269 < V_270 ; V_269 ++ )
F_12 ( & V_268 [ V_269 ] ) ;
F_12 ( & V_268 ) ;
return;
V_274:
F_10 ( V_3 ) ;
V_273:
F_10 ( V_2 ) ;
printf ( L_63 ,
V_275 [ V_24 ] ) ;
if ( V_268 )
goto V_276;
}
int F_133 ( const char * V_277 )
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
snprintf ( V_4 , V_5 , L_60 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
if ( ! strcmp ( V_4 , V_277 ) ) {
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
static bool F_134 ( T_11 type , unsigned V_12 )
{
bool V_81 = true ;
int V_278 ;
struct V_33 * V_41 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_279 = 1 ,
} ;
struct {
struct V_280 V_281 ;
int V_282 [ 1 ] ;
} V_283 = {
. V_281 . V_284 = 1 ,
. V_282 = { 0 } ,
} ;
V_41 = F_135 ( & V_37 ) ;
if ( V_41 ) {
V_278 = F_136 ( V_41 , NULL , & V_283 . V_281 ) ;
V_81 = V_278 >= 0 ;
if ( V_278 == - V_76 ) {
V_41 -> V_37 . V_192 = 1 ;
V_81 = F_136 ( V_41 , NULL , & V_283 . V_281 ) >= 0 ;
}
F_49 ( V_41 ) ;
}
return V_81 ;
}
void F_137 ( const char * V_265 , const char * V_266 ,
bool V_267 )
{
struct V_285 * V_286 ;
struct V_287 * V_288 ;
struct V_289 * V_290 , * V_291 ;
struct V_292 V_293 = { . V_294 = true } ;
struct V_295 * V_296 , * V_297 ;
char * V_245 , * V_13 , * V_119 = NULL ;
bool V_298 = false ;
int V_81 ;
V_291 = F_138 ( NULL , & V_293 ) ;
if ( ! V_291 ) {
F_45 ( L_64 ) ;
return;
}
V_290 = F_139 ( true ) ;
if ( ! V_290 ) {
F_45 ( L_65 , V_83 ) ;
return;
}
F_140 (nd, bidlist) {
V_286 = F_141 ( V_296 -> V_299 ) ;
if ( ! V_286 )
continue;
F_19 (ent, &pcache->entries, node) {
if ( ! V_288 -> V_300 )
continue;
if ( V_265 &&
! F_41 ( V_288 -> V_301 . V_86 , V_265 ) )
continue;
if ( V_266 &&
! F_41 ( V_288 -> V_301 . V_87 , V_266 ) )
continue;
V_81 = F_72 ( & V_245 , L_66 , V_288 -> V_301 . V_86 ,
V_288 -> V_301 . V_87 , V_296 -> V_299 ) ;
if ( V_81 > 0 )
F_142 ( V_291 , V_245 ) ;
}
F_143 ( V_286 ) ;
}
F_144 ( V_290 ) ;
F_140 (nd, sdtlist) {
V_245 = strchr ( V_296 -> V_299 , '@' ) ;
if ( V_245 )
* ( V_245 ++ ) = '\0' ;
if ( V_267 ) {
printf ( L_61 , V_296 -> V_299 ) ;
continue;
}
V_297 = F_145 ( V_296 ) ;
if ( V_297 ) {
V_119 = strchr ( V_297 -> V_299 , '@' ) ;
if ( V_119 )
* V_119 = '\0' ;
if ( strcmp ( V_296 -> V_299 , V_297 -> V_299 ) == 0 )
V_298 = true ;
}
if ( V_298 ) {
V_13 = F_146 ( V_245 ) ;
V_81 = F_72 ( & V_245 , L_67 , V_296 -> V_299 , V_13 , V_245 ) ;
if ( V_81 > 0 ) {
printf ( L_62 , V_245 , L_68 ) ;
free ( V_245 ) ;
}
} else
printf ( L_62 , V_296 -> V_299 , L_68 ) ;
if ( V_297 ) {
if ( strcmp ( V_296 -> V_299 , V_297 -> V_299 ) != 0 )
V_298 = false ;
if ( V_119 )
* V_119 = '@' ;
}
}
F_144 ( V_291 ) ;
}
int F_147 ( const char * V_266 , bool V_267 )
{
unsigned int type , V_302 , V_48 , V_269 = 0 , V_270 = 0 ;
char V_20 [ 64 ] ;
char * * V_268 = NULL ;
bool V_271 = false ;
V_272:
if ( V_271 ) {
V_268 = F_11 ( sizeof( char * ) * V_270 ) ;
if ( ! V_268 )
goto V_303;
}
for ( type = 0 ; type < V_64 ; type ++ ) {
for ( V_302 = 0 ; V_302 < V_66 ; V_302 ++ ) {
if ( ! F_30 ( type , V_302 ) )
continue;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
F_148 ( type , V_302 , V_48 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_266 != NULL && ! F_41 ( V_20 , V_266 ) )
continue;
if ( ! F_134 ( V_25 ,
type | ( V_302 << 8 ) | ( V_48 << 16 ) ) )
continue;
if ( ! V_271 ) {
V_270 ++ ;
continue;
}
V_268 [ V_269 ] = F_15 ( V_20 ) ;
if ( V_268 [ V_269 ] == NULL )
goto V_303;
V_269 ++ ;
}
}
}
if ( ! V_271 ) {
V_271 = true ;
goto V_272;
}
qsort ( V_268 , V_270 , sizeof( char * ) , F_130 ) ;
V_269 = 0 ;
while ( V_269 < V_270 ) {
if ( V_267 ) {
printf ( L_61 , V_268 [ V_269 ++ ] ) ;
continue;
}
printf ( L_62 , V_268 [ V_269 ++ ] ,
V_275 [ V_25 ] ) ;
}
if ( V_270 && F_132 () )
printf ( L_32 ) ;
V_276:
V_270 = V_269 ;
for ( V_269 = 0 ; V_269 < V_270 ; V_269 ++ )
F_12 ( & V_268 [ V_269 ] ) ;
F_12 ( & V_268 ) ;
return V_270 ;
V_303:
printf ( L_63 , V_275 [ V_25 ] ) ;
if ( V_268 )
goto V_276;
return V_270 ;
}
void F_149 ( const char * V_266 , unsigned type ,
struct V_304 * V_305 , unsigned V_306 ,
bool V_267 )
{
unsigned int V_48 , V_269 = 0 , V_270 = 0 ;
char V_20 [ V_57 ] ;
char * * V_268 = NULL ;
bool V_271 = false ;
V_272:
if ( V_271 ) {
V_268 = F_11 ( sizeof( char * ) * V_270 ) ;
if ( ! V_268 )
goto V_303;
V_305 -= V_306 ;
}
for ( V_48 = 0 ; V_48 < V_306 ; V_48 ++ , V_305 ++ ) {
if ( V_266 != NULL && V_305 -> V_215 != NULL &&
! ( F_41 ( V_305 -> V_215 , V_266 ) ||
( V_305 -> V_219 && F_41 ( V_305 -> V_219 , V_266 ) ) ) )
continue;
if ( ! F_134 ( type , V_48 ) )
continue;
if ( ! V_271 ) {
V_270 ++ ;
continue;
}
if ( ! V_267 && strlen ( V_305 -> V_219 ) )
snprintf ( V_20 , V_57 , L_69 , V_305 -> V_215 , V_305 -> V_219 ) ;
else
strncpy ( V_20 , V_305 -> V_215 , V_57 ) ;
V_268 [ V_269 ] = F_15 ( V_20 ) ;
if ( V_268 [ V_269 ] == NULL )
goto V_303;
V_269 ++ ;
}
if ( ! V_271 ) {
V_271 = true ;
goto V_272;
}
qsort ( V_268 , V_270 , sizeof( char * ) , F_130 ) ;
V_269 = 0 ;
while ( V_269 < V_270 ) {
if ( V_267 ) {
printf ( L_61 , V_268 [ V_269 ++ ] ) ;
continue;
}
printf ( L_62 , V_268 [ V_269 ++ ] , V_275 [ type ] ) ;
}
if ( V_270 && F_132 () )
printf ( L_32 ) ;
V_276:
V_270 = V_269 ;
for ( V_269 = 0 ; V_269 < V_270 ; V_269 ++ )
F_12 ( & V_268 [ V_269 ] ) ;
F_12 ( & V_268 ) ;
return;
V_303:
printf ( L_63 , V_275 [ type ] ) ;
if ( V_268 )
goto V_276;
}
void F_150 ( const char * V_266 , bool V_267 , bool V_307 ,
bool V_308 )
{
F_149 ( V_266 , V_22 ,
V_309 , V_310 , V_267 ) ;
F_149 ( V_266 , V_23 ,
V_311 , V_312 , V_267 ) ;
F_147 ( V_266 , V_267 ) ;
F_151 ( V_266 , V_267 , V_307 , V_308 ) ;
if ( V_266 != NULL )
return;
if ( ! V_267 ) {
printf ( L_62 ,
L_70 ,
V_275 [ V_313 ] ) ;
printf ( L_62 ,
L_71 ,
V_275 [ V_313 ] ) ;
if ( F_132 () )
printf ( L_72 ) ;
printf ( L_62 ,
L_73 ,
V_275 [ V_124 ] ) ;
if ( F_132 () )
printf ( L_32 ) ;
}
F_131 ( NULL , NULL , V_267 ) ;
F_137 ( NULL , NULL , V_267 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_105 ;
}
static int F_152 ( struct V_26 * * V_314 , int V_126 ,
int V_28 , char * V_12 ,
char * V_21 , T_1 V_137 , int V_106 , int V_108 )
{
struct V_26 * V_27 ;
V_27 = F_11 ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_44 ;
F_153 ( & V_27 -> V_34 ) ;
V_27 -> V_126 = V_126 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_106 = V_106 ;
V_27 -> V_108 = V_108 ;
switch ( V_126 ) {
case V_127 :
V_27 -> V_32 . V_137 = V_137 ;
break;
case V_315 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_314 = V_27 ;
return 0 ;
}
int F_154 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_137 ,
void * V_316 , void * V_317 )
{
T_12 * V_318 = V_316 ;
T_12 * V_319 = V_317 ;
return F_152 ( V_27 , V_127 , V_28 ,
V_12 , NULL , V_137 ,
V_318 ? V_318 -> V_320 : 0 ,
V_319 ? V_319 -> V_320 : 0 ) ;
}
int F_155 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_316 , void * V_317 )
{
T_12 * V_318 = V_316 ;
T_12 * V_319 = V_317 ;
return F_152 ( V_27 , V_315 , V_28 ,
V_12 , V_21 , 0 ,
V_318 ? V_318 -> V_320 : 0 ,
V_319 ? V_319 -> V_320 : 0 ) ;
}
int F_156 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_304 * V_321 ;
F_157 ( V_35 >= V_310 ) ;
V_321 = & V_309 [ V_35 ] ;
if ( V_12 )
return F_152 ( V_27 , V_315 ,
V_105 , V_12 ,
( char * ) V_321 -> V_215 , 0 , 0 , 0 ) ;
else
return F_152 ( V_27 , V_315 ,
V_105 ,
( char * ) L_74 , ( char * ) V_321 -> V_215 ,
0 , 0 , 0 ) ;
}
int F_158 ( struct V_26 * * V_322 ,
struct V_26 * V_27 )
{
return F_152 ( V_322 , V_27 -> V_126 , V_27 -> V_28 , V_27 -> V_12 ,
V_27 -> V_32 . V_21 , V_27 -> V_32 . V_137 ,
V_27 -> V_106 , V_27 -> V_108 ) ;
}
void F_159 ( struct V_30 * V_232 )
{
struct V_26 * V_27 , * V_323 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_324 . V_325 )
free ( V_27 -> V_324 . V_326 ) ;
F_160 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_110 ( struct V_30 * V_232 )
{
if ( ! V_232 )
return;
F_159 ( V_232 ) ;
free ( V_232 ) ;
}
void F_161 ( struct V_327 * V_261 )
{
free ( V_261 -> V_326 ) ;
}
void F_162 ( struct V_92 * V_94 ,
int V_35 , const char * V_21 )
{
struct V_54 * V_55 = V_94 -> error ;
if ( ! V_55 )
return;
V_55 -> V_35 = V_35 ;
V_55 -> V_21 = F_15 ( V_21 ) ;
F_87 ( ! V_55 -> V_21 , L_75 ) ;
}
static void F_163 ( char * V_245 , V_227 V_328 )
{
int V_48 ;
bool V_329 = true ;
V_245 [ 0 ] = '\0' ;
for ( V_48 = 0 ; V_48 < V_129 ; V_48 ++ ) {
const char * V_20 = V_135 [ V_48 ] ;
if ( ! F_71 ( V_48 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_245 ) + strlen ( V_20 ) + 2 >= V_328 )
return;
if ( ! V_329 )
strcat ( V_245 , L_76 ) ;
else
V_329 = false ;
strcat ( V_245 , V_20 ) ;
}
}
char * F_75 ( char * V_330 )
{
char * V_21 ;
char V_331 [ V_129 *
( sizeof( L_77 ) - 1 ) ] ;
F_163 ( V_331 , sizeof( V_331 ) ) ;
if ( V_330 ) {
if ( F_72 ( & V_21 , L_78 ,
V_330 , V_331 ) < 0 )
goto V_332;
} else {
if ( F_72 ( & V_21 , L_79 , V_331 ) < 0 )
goto V_332;
}
return V_21 ;
V_332:
return NULL ;
}
