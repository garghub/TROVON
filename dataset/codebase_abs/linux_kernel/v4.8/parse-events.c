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
return true ;
default:
if ( ! V_55 )
return false ;
if ( F_72 ( & V_55 -> V_21 , L_39 ,
V_134 [ V_128 ] ) < 0 )
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
F_74 ( V_135 ) ;
V_37 -> V_12 = V_27 -> V_32 . V_136 ;
break;
case V_132 :
F_74 ( V_135 ) ;
V_37 -> V_137 = V_27 -> V_32 . V_136 ;
break;
case V_133 :
F_74 ( V_135 ) ;
V_37 -> V_138 = V_27 -> V_32 . V_136 ;
break;
case V_139 :
F_74 ( V_135 ) ;
break;
case V_140 :
F_74 ( V_135 ) ;
break;
case V_141 :
break;
case V_142 :
F_74 ( V_135 ) ;
if ( V_27 -> V_32 . V_136 > 1 ) {
V_55 -> V_21 = F_15 ( L_40 ) ;
V_55 -> V_35 = V_27 -> V_108 ;
return - V_10 ;
}
break;
case V_143 :
F_74 ( V_144 ) ;
break;
case V_145 :
F_74 ( V_135 ) ;
break;
case V_146 :
F_74 ( V_135 ) ;
break;
case V_147 :
F_74 ( V_135 ) ;
break;
case V_148 :
F_74 ( V_135 ) ;
break;
case V_149 :
F_74 ( V_135 ) ;
break;
case V_29 :
F_74 ( V_144 ) ;
break;
case V_150 :
F_74 ( V_135 ) ;
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
if ( V_27 -> V_28 == V_105 )
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
struct V_30 * V_151 ,
struct V_54 * V_55 ,
T_4 V_152 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_152 ( V_37 , V_27 , V_55 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_56 ,
struct V_30 * V_31 V_153 )
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
case V_139 :
F_78 ( V_154 , V_155 , V_27 -> V_32 . V_136 ) ;
break;
case V_140 :
F_78 ( V_156 , V_157 , V_27 -> V_32 . V_136 ) ;
break;
case V_142 :
F_78 ( TIME , time , V_27 -> V_32 . V_136 ) ;
break;
case V_143 :
F_78 ( V_158 , V_159 , V_27 -> V_32 . V_21 ) ;
break;
case V_145 :
F_78 ( V_160 , V_161 , V_27 -> V_32 . V_136 ) ;
break;
case V_146 :
F_78 ( V_162 , V_163 , V_27 -> V_32 . V_136 ? 1 : 0 ) ;
break;
case V_147 :
F_78 ( V_162 , V_163 , V_27 -> V_32 . V_136 ? 0 : 1 ) ;
break;
case V_150 :
F_78 ( V_164 , V_165 , V_27 -> V_32 . V_136 ) ;
break;
case V_148 :
F_78 ( V_166 , V_167 , V_27 -> V_32 . V_136 ? 1 : 0 ) ;
break;
case V_149 :
F_78 ( V_166 , V_167 , V_27 -> V_32 . V_136 ? 0 : 1 ) ;
break;
default:
break;
}
}
#undef V_168
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
struct V_169 V_170 ;
struct V_171 * V_172 ;
struct V_33 * V_41 ;
F_29 ( V_40 ) ;
V_172 = F_81 ( V_20 ) ;
if ( ! V_172 )
return - V_10 ;
if ( V_172 -> V_173 ) {
memcpy ( & V_37 , V_172 -> V_173 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_56 ) {
V_37 . type = V_172 -> type ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 , NULL , V_172 -> V_39 , NULL ) ;
return V_41 ? 0 : - V_44 ;
}
if ( F_82 ( V_172 , V_56 , & V_170 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_56 , V_94 -> error , F_76 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
if ( F_83 ( V_172 , & V_37 , V_56 , V_94 -> error ) )
return - V_10 ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 ,
F_18 ( V_56 ) , V_172 -> V_39 ,
& V_40 ) ;
if ( V_41 ) {
V_41 -> V_174 = V_170 . V_174 ;
V_41 -> V_175 = V_170 . V_175 ;
V_41 -> V_176 = V_170 . V_176 ;
V_41 -> V_177 = V_170 . V_177 ;
}
return V_41 ? 0 : - V_44 ;
}
int F_84 ( struct V_30 * V_34 ,
char * V_178 )
{
return F_85 ( V_34 , V_178 , true ) ;
}
void F_86 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_179 ;
if ( F_57 ( V_34 ) ) {
F_87 ( true , L_43 ) ;
return;
}
F_88 ( V_34 ) ;
V_179 = F_89 ( V_34 -> V_180 , struct V_33 , V_43 ) ;
V_179 -> V_181 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_90 ( struct V_30 * V_182 ,
struct V_30 * V_183 )
{
F_66 ( V_182 , V_183 ) ;
free ( V_182 ) ;
}
static int F_91 ( struct V_184 * V_185 , char * V_21 ,
struct V_33 * V_41 )
{
int V_186 = V_41 ? V_41 -> V_37 . V_187 : 0 ;
int V_188 = V_41 ? V_41 -> V_37 . V_189 : 0 ;
int V_190 = V_41 ? V_41 -> V_37 . V_191 : 0 ;
int V_192 = V_41 ? V_41 -> V_37 . V_193 : 0 ;
int V_194 = V_41 ? V_41 -> V_37 . V_195 : 0 ;
int V_196 = V_41 ? V_41 -> V_37 . V_197 : 0 ;
int V_198 = V_41 ? V_41 -> V_37 . V_199 : 0 ;
int V_200 = 0 ;
int V_201 = 0 ;
int V_202 = V_41 ? V_41 -> V_37 . V_202 : 0 ;
int V_203 = V_186 | V_188 | V_190 ;
int V_204 = V_41 ? V_41 -> V_204 : 0 ;
memset ( V_185 , 0 , sizeof( * V_185 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_203 )
V_203 = V_186 = V_188 = V_190 = 1 ;
V_186 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_203 )
V_203 = V_186 = V_188 = V_190 = 1 ;
V_188 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_203 )
V_203 = V_186 = V_188 = V_190 = 1 ;
V_190 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_204 )
V_204 = V_194 = V_192 = 1 ;
V_194 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_204 )
V_204 = V_194 = V_192 = 1 ;
V_192 = 0 ;
} else if ( * V_21 == 'I' ) {
V_196 = 1 ;
} else if ( * V_21 == 'p' ) {
V_198 ++ ;
if ( ! V_204 )
V_194 = 1 ;
} else if ( * V_21 == 'P' ) {
V_200 = 1 ;
} else if ( * V_21 == 'S' ) {
V_201 = 1 ;
} else if ( * V_21 == 'D' ) {
V_202 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_198 > 3 )
return - V_10 ;
V_185 -> V_186 = V_186 ;
V_185 -> V_188 = V_188 ;
V_185 -> V_190 = V_190 ;
V_185 -> V_192 = V_192 ;
V_185 -> V_194 = V_194 ;
V_185 -> V_196 = V_196 ;
V_185 -> V_198 = V_198 ;
V_185 -> V_200 = V_200 ;
V_185 -> V_204 = V_204 ;
V_185 -> V_201 = V_201 ;
V_185 -> V_202 = V_202 ;
return 0 ;
}
static int F_92 ( char * V_21 )
{
char * V_205 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_44 ) - 1 ) )
return - 1 ;
while ( * V_205 ) {
if ( * V_205 != 'p' && strchr ( V_205 + 1 , * V_205 ) )
return - 1 ;
V_205 ++ ;
}
return 0 ;
}
int F_85 ( struct V_30 * V_34 , char * V_21 , bool V_206 )
{
struct V_33 * V_41 ;
struct V_184 V_185 ;
if ( V_21 == NULL )
return 0 ;
if ( F_92 ( V_21 ) )
return - V_10 ;
if ( ! V_206 && F_91 ( & V_185 , V_21 , NULL ) )
return - V_10 ;
F_93 (list, evsel) {
if ( V_206 && F_91 ( & V_185 , V_21 , V_41 ) )
return - V_10 ;
V_41 -> V_37 . V_187 = V_185 . V_186 ;
V_41 -> V_37 . V_189 = V_185 . V_188 ;
V_41 -> V_37 . V_191 = V_185 . V_190 ;
V_41 -> V_37 . V_199 = V_185 . V_198 ;
V_41 -> V_37 . V_193 = V_185 . V_192 ;
V_41 -> V_37 . V_195 = V_185 . V_194 ;
V_41 -> V_37 . V_197 = V_185 . V_196 ;
V_41 -> V_204 = V_185 . V_204 ;
V_41 -> V_201 = V_185 . V_201 ;
V_41 -> V_200 = V_185 . V_200 ;
if ( F_94 ( V_41 ) )
V_41 -> V_37 . V_202 = V_185 . V_202 ;
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
F_96 ( const void * V_207 , const void * V_208 )
{
struct V_209 * V_210 = (struct V_209 * ) V_207 ;
struct V_209 * V_211 = (struct V_209 * ) V_208 ;
return strcmp ( V_210 -> V_212 , V_211 -> V_212 ) ;
}
static void F_97 ( void )
{
if ( V_213 > 0 ) {
struct V_209 * V_205 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_213 ; V_48 ++ ) {
V_205 = V_214 + V_48 ;
free ( V_205 -> V_212 ) ;
}
free ( V_214 ) ;
V_214 = NULL ;
V_213 = 0 ;
}
}
static void F_98 ( void )
{
struct V_171 * V_172 = NULL ;
struct V_215 * V_216 ;
int V_120 = 0 ;
V_172 = F_81 ( L_45 ) ;
if ( ( V_172 == NULL ) || F_57 ( & V_172 -> V_217 ) ) {
V_213 = - 1 ;
return;
}
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_216 -> V_20 , '-' ) )
V_120 ++ ;
V_120 ++ ;
}
V_214 = malloc ( sizeof( struct V_209 ) * V_120 ) ;
if ( ! V_214 )
return;
V_213 = V_120 ;
V_120 = 0 ;
F_19 (alias, &pmu->aliases, list) {
struct V_209 * V_205 = V_214 + V_120 ;
char * V_96 = strchr ( V_216 -> V_20 , '-' ) ;
if ( V_96 != NULL ) {
F_99 ( F_14 ( V_216 -> V_20 , V_96 - V_216 -> V_20 ) ,
V_218 ) ;
V_205 ++ ;
F_99 ( F_15 ( ++ V_96 ) , V_219 ) ;
V_120 += 2 ;
} else {
F_99 ( F_15 ( V_216 -> V_20 ) , V_220 ) ;
V_120 ++ ;
}
}
qsort ( V_214 , V_120 ,
sizeof( struct V_209 ) , F_96 ) ;
return;
V_55:
F_97 () ;
}
enum V_221
F_100 ( const char * V_20 )
{
struct V_209 V_205 , * V_222 ;
if ( V_213 == 0 )
F_98 () ;
if ( ( V_213 <= 0 ) || ! strcmp ( V_20 , L_45 ) )
return V_223 ;
V_205 . V_212 = F_15 ( V_20 ) ;
V_222 = bsearch ( & V_205 , V_214 ,
( V_224 ) V_213 ,
sizeof( struct V_209 ) , F_96 ) ;
free ( V_205 . V_212 ) ;
return V_222 ? V_222 -> type : V_223 ;
}
static int F_101 ( const char * V_21 , void * V_94 , int V_225 )
{
T_9 V_226 ;
void * V_227 ;
int V_81 ;
V_81 = F_102 ( V_225 , & V_227 ) ;
if ( V_81 )
return V_81 ;
V_226 = F_103 ( V_21 , V_227 ) ;
#ifdef F_104
V_228 = 1 ;
#endif
V_81 = F_105 ( V_94 , V_227 ) ;
F_106 ( V_226 , V_227 ) ;
F_107 ( V_226 , V_227 ) ;
F_108 ( V_227 ) ;
return V_81 ;
}
int F_109 ( struct V_30 * V_229 , const char * V_21 )
{
struct F_109 V_94 = {
. V_229 = NULL ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_230 ) ;
if ( ! V_81 ) {
F_24 ( V_94 . V_229 , V_229 ) ;
F_12 ( & V_94 . V_229 ) ;
return 0 ;
}
F_110 ( V_94 . V_229 ) ;
return V_81 ;
}
int F_111 ( struct V_231 * V_93 , const char * V_21 ,
struct V_54 * V_55 )
{
struct V_92 V_94 = {
. V_34 = F_112 ( V_94 . V_34 ) ,
. V_35 = V_93 -> V_232 ,
. error = V_55 ,
. V_93 = V_93 ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_233 ) ;
F_97 () ;
if ( ! V_81 ) {
struct V_33 * V_234 ;
if ( F_57 ( & V_94 . V_34 ) ) {
F_87 ( true , L_46 ) ;
return - 1 ;
}
F_113 ( V_93 , & V_94 . V_34 ) ;
V_93 -> V_235 += V_94 . V_235 ;
V_234 = F_114 ( V_93 ) ;
V_234 -> V_236 = true ;
return 0 ;
}
return V_81 ;
}
static int F_115 ( void )
{
struct V_237 V_238 ;
F_116 ( & V_238 ) ;
return V_238 . V_239 > V_240 ? V_240 : V_238 . V_239 ;
}
static void F_117 ( struct V_54 * V_55 ,
const char * V_87 )
{
const char * V_21 = L_47 ;
char V_241 [ V_240 ] ;
char * V_242 = ( char * ) V_87 ;
int V_35 = 0 ;
if ( V_55 -> V_21 ) {
int V_243 = F_115 () - 2 ;
int V_244 = strlen ( V_87 ) ;
int V_245 , V_246 , V_247 = 0 ;
int V_248 = 13 ;
V_21 = L_48 ;
V_245 = strlen ( V_21 ) ;
V_246 = V_243 - V_245 ;
V_242 = V_241 ;
if ( V_55 -> V_35 > V_248 )
V_247 = V_55 -> V_35 - V_248 ;
strncpy ( V_242 , V_87 + V_247 , V_246 ) ;
if ( V_247 )
V_242 [ 0 ] = V_242 [ 1 ] = '.' ;
if ( ( V_244 - V_247 ) > V_246 ) {
V_242 [ V_246 - 1 ] = V_242 [ V_246 - 2 ] = '.' ;
V_242 [ V_246 ] = 0 ;
}
V_35 = V_245 + V_55 -> V_35 - V_247 ;
}
fprintf ( V_249 , L_49 , V_21 , V_242 ) ;
if ( V_35 ) {
fprintf ( V_249 , L_50 , V_35 + 1 , L_51 , V_55 -> V_21 ) ;
if ( V_55 -> V_74 )
fprintf ( V_249 , L_52 , V_55 -> V_74 ) ;
free ( V_55 -> V_21 ) ;
free ( V_55 -> V_74 ) ;
}
fprintf ( V_249 , L_53 ) ;
}
int F_118 ( const struct V_250 * V_251 , const char * V_21 ,
int T_10 V_153 )
{
struct V_231 * V_93 = * (struct V_231 * * ) V_251 -> V_252 ;
struct V_54 V_55 = { . V_35 = 0 , } ;
int V_81 = F_111 ( V_93 , V_21 , & V_55 ) ;
if ( V_81 )
F_117 ( & V_55 , V_21 ) ;
return V_81 ;
}
static int
F_119 ( struct V_231 * V_93 ,
int (* F_120)( struct V_33 * V_41 ,
const void * V_253 ) ,
const void * V_253 )
{
struct V_33 * V_234 = NULL ;
int V_55 ;
if ( V_93 -> V_232 > 0 )
V_234 = F_114 ( V_93 ) ;
do {
V_55 = (* F_120)( V_234 , V_253 ) ;
if ( V_55 )
return - 1 ;
if ( ! V_234 )
return 0 ;
if ( V_234 -> V_43 . V_254 == & V_93 -> V_255 )
return 0 ;
V_234 = F_89 ( V_234 -> V_43 . V_254 , struct V_33 , V_43 ) ;
} while ( ! V_234 -> V_236 );
return 0 ;
}
static int F_121 ( struct V_33 * V_41 , const void * V_253 )
{
const char * V_21 = V_253 ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_249 ,
L_54 ) ;
return - 1 ;
}
if ( F_122 ( V_41 , L_55 , V_21 ) < 0 ) {
fprintf ( V_249 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
int F_123 ( const struct V_250 * V_251 , const char * V_21 ,
int T_10 V_153 )
{
struct V_231 * V_93 = * (struct V_231 * * ) V_251 -> V_252 ;
return F_119 ( V_93 , F_121 ,
( const void * ) V_21 ) ;
}
static int F_124 ( struct V_33 * V_41 ,
const void * V_253 V_153 )
{
char V_256 [ 64 ] ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_249 ,
L_57 ) ;
return - 1 ;
}
snprintf ( V_256 , sizeof( V_256 ) , L_58 , F_125 () ) ;
if ( F_122 ( V_41 , L_55 , V_256 ) < 0 ) {
fprintf ( V_249 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
int F_126 ( const struct V_250 * V_251 ,
const char * V_253 V_153 ,
int T_10 V_153 )
{
struct V_231 * V_93 = * (struct V_231 * * ) V_251 -> V_252 ;
return F_119 ( V_93 , F_124 ,
NULL ) ;
}
static int F_127 ( const void * V_257 , const void * V_258 )
{
const char * const * V_259 = V_257 ;
const char * const * V_260 = V_258 ;
return strcmp ( * V_259 , * V_260 ) ;
}
void F_128 ( const char * V_261 , const char * V_262 ,
bool V_263 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_264 = NULL ;
unsigned int V_265 = 0 , V_266 = 0 ;
bool V_267 = false ;
V_268:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_267 ) {
V_264 = F_11 ( sizeof( char * ) * V_266 ) ;
if ( ! V_264 )
goto V_269;
}
F_6 (sys_dir, sys_dirent) {
if ( V_261 != NULL &&
! F_41 ( V_14 -> V_8 , V_261 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_262 != NULL &&
! F_41 ( V_15 -> V_8 , V_262 ) )
continue;
if ( ! V_267 ) {
V_266 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_59 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_264 [ V_265 ] = F_15 ( V_4 ) ;
if ( V_264 [ V_265 ] == NULL )
goto V_270;
V_265 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_267 ) {
V_267 = true ;
goto V_268;
}
qsort ( V_264 , V_266 , sizeof( char * ) , F_127 ) ;
V_265 = 0 ;
while ( V_265 < V_266 ) {
if ( V_263 ) {
printf ( L_60 , V_264 [ V_265 ++ ] ) ;
continue;
}
printf ( L_61 , V_264 [ V_265 ++ ] ,
V_271 [ V_24 ] ) ;
}
if ( V_266 && F_129 () )
printf ( L_32 ) ;
V_272:
V_266 = V_265 ;
for ( V_265 = 0 ; V_265 < V_266 ; V_265 ++ )
F_12 ( & V_264 [ V_265 ] ) ;
F_12 ( & V_264 ) ;
return;
V_270:
F_10 ( V_3 ) ;
V_269:
F_10 ( V_2 ) ;
printf ( L_62 ,
V_271 [ V_24 ] ) ;
if ( V_264 )
goto V_272;
}
int F_130 ( const char * V_273 )
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
snprintf ( V_4 , V_5 , L_59 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
if ( ! strcmp ( V_4 , V_273 ) ) {
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
static bool F_131 ( T_11 type , unsigned V_12 )
{
bool V_81 = true ;
int V_274 ;
struct V_33 * V_41 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_275 = 1 ,
} ;
struct {
struct V_276 V_277 ;
int V_278 [ 1 ] ;
} V_279 = {
. V_277 . V_280 = 1 ,
. V_278 = { 0 } ,
} ;
V_41 = F_132 ( & V_37 ) ;
if ( V_41 ) {
V_274 = F_133 ( V_41 , NULL , & V_279 . V_277 ) ;
V_81 = V_274 >= 0 ;
if ( V_274 == - V_76 ) {
V_41 -> V_37 . V_189 = 1 ;
V_81 = F_133 ( V_41 , NULL , & V_279 . V_277 ) >= 0 ;
}
F_49 ( V_41 ) ;
}
return V_81 ;
}
void F_134 ( const char * V_261 , const char * V_262 ,
bool V_263 )
{
struct V_281 * V_282 ;
struct V_283 * V_284 ;
struct V_285 * V_286 , * V_287 ;
struct V_288 V_289 = { . V_290 = true } ;
struct V_291 * V_292 , * V_293 ;
char * V_242 , * V_13 , * V_119 = NULL ;
bool V_294 = false ;
int V_81 ;
V_287 = F_135 ( NULL , & V_289 ) ;
if ( ! V_287 ) {
F_45 ( L_63 ) ;
return;
}
V_286 = F_136 ( true ) ;
if ( ! V_286 ) {
F_45 ( L_64 , V_83 ) ;
return;
}
F_137 (nd, bidlist) {
V_282 = F_138 ( V_292 -> V_295 ) ;
if ( ! V_282 )
continue;
F_19 (ent, &pcache->entries, node) {
if ( ! V_284 -> V_296 )
continue;
if ( V_261 &&
! F_41 ( V_284 -> V_297 . V_86 , V_261 ) )
continue;
if ( V_262 &&
! F_41 ( V_284 -> V_297 . V_87 , V_262 ) )
continue;
V_81 = F_72 ( & V_242 , L_65 , V_284 -> V_297 . V_86 ,
V_284 -> V_297 . V_87 , V_292 -> V_295 ) ;
if ( V_81 > 0 )
F_139 ( V_287 , V_242 ) ;
}
F_140 ( V_282 ) ;
}
F_141 ( V_286 ) ;
F_137 (nd, sdtlist) {
V_242 = strchr ( V_292 -> V_295 , '@' ) ;
if ( V_242 )
* ( V_242 ++ ) = '\0' ;
if ( V_263 ) {
printf ( L_60 , V_292 -> V_295 ) ;
continue;
}
V_293 = F_142 ( V_292 ) ;
if ( V_293 ) {
V_119 = strchr ( V_293 -> V_295 , '@' ) ;
if ( V_119 )
* V_119 = '\0' ;
if ( strcmp ( V_292 -> V_295 , V_293 -> V_295 ) == 0 )
V_294 = true ;
}
if ( V_294 ) {
V_13 = F_143 ( V_242 ) ;
V_81 = F_72 ( & V_242 , L_66 , V_292 -> V_295 , V_13 , V_242 ) ;
if ( V_81 > 0 ) {
printf ( L_61 , V_242 , L_67 ) ;
free ( V_242 ) ;
}
} else
printf ( L_61 , V_292 -> V_295 , L_67 ) ;
if ( V_293 ) {
if ( strcmp ( V_292 -> V_295 , V_293 -> V_295 ) != 0 )
V_294 = false ;
if ( V_119 )
* V_119 = '@' ;
}
}
F_141 ( V_287 ) ;
}
int F_144 ( const char * V_262 , bool V_263 )
{
unsigned int type , V_298 , V_48 , V_265 = 0 , V_266 = 0 ;
char V_20 [ 64 ] ;
char * * V_264 = NULL ;
bool V_267 = false ;
V_268:
if ( V_267 ) {
V_264 = F_11 ( sizeof( char * ) * V_266 ) ;
if ( ! V_264 )
goto V_299;
}
for ( type = 0 ; type < V_64 ; type ++ ) {
for ( V_298 = 0 ; V_298 < V_66 ; V_298 ++ ) {
if ( ! F_30 ( type , V_298 ) )
continue;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
F_145 ( type , V_298 , V_48 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_262 != NULL && ! F_41 ( V_20 , V_262 ) )
continue;
if ( ! F_131 ( V_25 ,
type | ( V_298 << 8 ) | ( V_48 << 16 ) ) )
continue;
if ( ! V_267 ) {
V_266 ++ ;
continue;
}
V_264 [ V_265 ] = F_15 ( V_20 ) ;
if ( V_264 [ V_265 ] == NULL )
goto V_299;
V_265 ++ ;
}
}
}
if ( ! V_267 ) {
V_267 = true ;
goto V_268;
}
qsort ( V_264 , V_266 , sizeof( char * ) , F_127 ) ;
V_265 = 0 ;
while ( V_265 < V_266 ) {
if ( V_263 ) {
printf ( L_60 , V_264 [ V_265 ++ ] ) ;
continue;
}
printf ( L_61 , V_264 [ V_265 ++ ] ,
V_271 [ V_25 ] ) ;
}
if ( V_266 && F_129 () )
printf ( L_32 ) ;
V_272:
V_266 = V_265 ;
for ( V_265 = 0 ; V_265 < V_266 ; V_265 ++ )
F_12 ( & V_264 [ V_265 ] ) ;
F_12 ( & V_264 ) ;
return V_266 ;
V_299:
printf ( L_62 , V_271 [ V_25 ] ) ;
if ( V_264 )
goto V_272;
return V_266 ;
}
void F_146 ( const char * V_262 , unsigned type ,
struct V_300 * V_301 , unsigned V_302 ,
bool V_263 )
{
unsigned int V_48 , V_265 = 0 , V_266 = 0 ;
char V_20 [ V_57 ] ;
char * * V_264 = NULL ;
bool V_267 = false ;
V_268:
if ( V_267 ) {
V_264 = F_11 ( sizeof( char * ) * V_266 ) ;
if ( ! V_264 )
goto V_299;
V_301 -= V_302 ;
}
for ( V_48 = 0 ; V_48 < V_302 ; V_48 ++ , V_301 ++ ) {
if ( V_262 != NULL && V_301 -> V_212 != NULL &&
! ( F_41 ( V_301 -> V_212 , V_262 ) ||
( V_301 -> V_216 && F_41 ( V_301 -> V_216 , V_262 ) ) ) )
continue;
if ( ! F_131 ( type , V_48 ) )
continue;
if ( ! V_267 ) {
V_266 ++ ;
continue;
}
if ( ! V_263 && strlen ( V_301 -> V_216 ) )
snprintf ( V_20 , V_57 , L_68 , V_301 -> V_212 , V_301 -> V_216 ) ;
else
strncpy ( V_20 , V_301 -> V_212 , V_57 ) ;
V_264 [ V_265 ] = F_15 ( V_20 ) ;
if ( V_264 [ V_265 ] == NULL )
goto V_299;
V_265 ++ ;
}
if ( ! V_267 ) {
V_267 = true ;
goto V_268;
}
qsort ( V_264 , V_266 , sizeof( char * ) , F_127 ) ;
V_265 = 0 ;
while ( V_265 < V_266 ) {
if ( V_263 ) {
printf ( L_60 , V_264 [ V_265 ++ ] ) ;
continue;
}
printf ( L_61 , V_264 [ V_265 ++ ] , V_271 [ type ] ) ;
}
if ( V_266 && F_129 () )
printf ( L_32 ) ;
V_272:
V_266 = V_265 ;
for ( V_265 = 0 ; V_265 < V_266 ; V_265 ++ )
F_12 ( & V_264 [ V_265 ] ) ;
F_12 ( & V_264 ) ;
return;
V_299:
printf ( L_62 , V_271 [ type ] ) ;
if ( V_264 )
goto V_272;
}
void F_147 ( const char * V_262 , bool V_263 )
{
F_146 ( V_262 , V_22 ,
V_303 , V_304 , V_263 ) ;
F_146 ( V_262 , V_23 ,
V_305 , V_306 , V_263 ) ;
F_144 ( V_262 , V_263 ) ;
F_148 ( V_262 , V_263 ) ;
if ( V_262 != NULL )
return;
if ( ! V_263 ) {
printf ( L_61 ,
L_69 ,
V_271 [ V_307 ] ) ;
printf ( L_61 ,
L_70 ,
V_271 [ V_307 ] ) ;
if ( F_129 () )
printf ( L_71 ) ;
printf ( L_61 ,
L_72 ,
V_271 [ V_124 ] ) ;
if ( F_129 () )
printf ( L_32 ) ;
}
F_128 ( NULL , NULL , V_263 ) ;
F_134 ( NULL , NULL , V_263 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_105 ;
}
static int F_149 ( struct V_26 * * V_308 , int V_126 ,
int V_28 , char * V_12 ,
char * V_21 , T_1 V_136 , int V_106 , int V_108 )
{
struct V_26 * V_27 ;
V_27 = F_11 ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_44 ;
F_150 ( & V_27 -> V_34 ) ;
V_27 -> V_126 = V_126 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_106 = V_106 ;
V_27 -> V_108 = V_108 ;
switch ( V_126 ) {
case V_127 :
V_27 -> V_32 . V_136 = V_136 ;
break;
case V_309 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_308 = V_27 ;
return 0 ;
}
int F_151 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_136 ,
void * V_310 , void * V_311 )
{
T_12 * V_312 = V_310 ;
T_12 * V_313 = V_311 ;
return F_149 ( V_27 , V_127 , V_28 ,
V_12 , NULL , V_136 ,
V_312 ? V_312 -> V_314 : 0 ,
V_313 ? V_313 -> V_314 : 0 ) ;
}
int F_152 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_310 , void * V_311 )
{
T_12 * V_312 = V_310 ;
T_12 * V_313 = V_311 ;
return F_149 ( V_27 , V_309 , V_28 ,
V_12 , V_21 , 0 ,
V_312 ? V_312 -> V_314 : 0 ,
V_313 ? V_313 -> V_314 : 0 ) ;
}
int F_153 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_300 * V_315 ;
F_154 ( V_35 >= V_304 ) ;
V_315 = & V_303 [ V_35 ] ;
if ( V_12 )
return F_149 ( V_27 , V_309 ,
V_105 , V_12 ,
( char * ) V_315 -> V_212 , 0 , 0 , 0 ) ;
else
return F_149 ( V_27 , V_309 ,
V_105 ,
( char * ) L_73 , ( char * ) V_315 -> V_212 ,
0 , 0 , 0 ) ;
}
int F_155 ( struct V_26 * * V_316 ,
struct V_26 * V_27 )
{
return F_149 ( V_316 , V_27 -> V_126 , V_27 -> V_28 , V_27 -> V_12 ,
V_27 -> V_32 . V_21 , V_27 -> V_32 . V_136 ,
V_27 -> V_106 , V_27 -> V_108 ) ;
}
void F_156 ( struct V_30 * V_229 )
{
struct V_26 * V_27 , * V_317 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_318 . V_319 )
free ( V_27 -> V_318 . V_320 ) ;
F_157 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_110 ( struct V_30 * V_229 )
{
if ( ! V_229 )
return;
F_156 ( V_229 ) ;
free ( V_229 ) ;
}
void F_158 ( struct V_321 * V_257 )
{
free ( V_257 -> V_320 ) ;
}
void F_159 ( struct V_92 * V_94 ,
int V_35 , const char * V_21 )
{
struct V_54 * V_55 = V_94 -> error ;
if ( ! V_55 )
return;
V_55 -> V_35 = V_35 ;
V_55 -> V_21 = F_15 ( V_21 ) ;
F_87 ( ! V_55 -> V_21 , L_74 ) ;
}
static void F_160 ( char * V_242 , V_224 V_322 )
{
int V_48 ;
bool V_323 = true ;
V_242 [ 0 ] = '\0' ;
for ( V_48 = 0 ; V_48 < V_129 ; V_48 ++ ) {
const char * V_20 = V_134 [ V_48 ] ;
if ( ! F_71 ( V_48 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_242 ) + strlen ( V_20 ) + 2 >= V_322 )
return;
if ( ! V_323 )
strcat ( V_242 , L_75 ) ;
else
V_323 = false ;
strcat ( V_242 , V_20 ) ;
}
}
char * F_75 ( char * V_324 )
{
char * V_21 ;
char V_325 [ V_129 *
( sizeof( L_76 ) - 1 ) ] ;
F_160 ( V_325 , sizeof( V_325 ) ) ;
if ( V_324 ) {
if ( F_72 ( & V_21 , L_77 ,
V_324 , V_325 ) < 0 )
goto V_326;
} else {
if ( F_72 ( & V_21 , L_78 , V_325 ) < 0 )
goto V_326;
}
return V_21 ;
V_326:
return NULL ;
}
