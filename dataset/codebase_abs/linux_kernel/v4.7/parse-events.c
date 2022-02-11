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
char * V_73 , char * V_20 )
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
char * V_78 , char * V_79 ,
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
char * V_78 , char * V_79 ,
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
char * V_78 , char * V_79 ,
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
char * V_78 , char * V_79 ,
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
static int F_44 ( struct V_86 * V_87 , int V_6 ,
void * V_88 )
{
F_29 ( V_89 ) ;
struct V_90 * V_91 = V_88 ;
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_30 * V_34 = V_91 -> V_34 ;
struct V_33 * V_95 ;
int V_55 ;
F_45 ( L_21 ,
V_87 -> V_96 , V_87 -> V_97 , V_6 ) ;
V_55 = F_46 ( & V_89 , & V_93 -> V_35 , V_87 -> V_96 ,
V_87 -> V_97 , V_93 -> error ,
V_91 -> V_56 ) ;
if ( V_55 ) {
struct V_33 * V_41 , * V_98 ;
F_45 ( L_22 ,
V_87 -> V_96 , V_87 -> V_97 ) ;
F_47 (evsel, tmp, &new_evsels, node) {
F_48 ( & V_41 -> V_43 ) ;
F_49 ( V_41 ) ;
}
return V_55 ;
}
F_45 ( L_23 , V_87 -> V_96 , V_87 -> V_97 ) ;
F_19 (pos, &new_evsels, node) {
F_45 ( L_24 ,
V_87 -> V_96 , V_87 -> V_97 , V_95 ) ;
V_95 -> V_99 = V_6 ;
}
F_24 ( & V_89 , V_34 ) ;
return 0 ;
}
int F_50 ( struct V_92 * V_94 ,
struct V_30 * V_34 ,
struct V_100 * V_101 ,
struct V_30 * V_56 )
{
int V_55 ;
char V_102 [ V_75 ] ;
struct V_90 V_91 = { V_94 , V_34 , V_56 } ;
static bool V_103 = false ;
if ( F_37 ( V_101 ) || ! V_101 ) {
snprintf ( V_102 , sizeof( V_102 ) ,
L_25 ) ;
V_55 = - V_10 ;
goto V_104;
}
if ( ! V_103 ) {
atexit ( V_105 ) ;
V_103 = true ;
}
V_55 = F_51 ( V_101 ) ;
if ( V_55 ) {
F_52 ( V_101 , V_55 , V_102 , sizeof( V_102 ) ) ;
goto V_104;
}
V_55 = F_53 ( V_101 ) ;
if ( V_55 ) {
F_54 ( V_101 , V_55 , V_102 , sizeof( V_102 ) ) ;
goto V_104;
}
V_55 = F_55 ( V_101 , F_44 , & V_91 ) ;
if ( V_55 ) {
snprintf ( V_102 , sizeof( V_102 ) ,
L_26 ) ;
goto V_104;
}
return 0 ;
V_104:
V_94 -> error -> V_74 = F_15 ( L_27 ) ;
V_94 -> error -> V_21 = F_15 ( V_102 ) ;
return V_55 ;
}
static int
F_56 ( struct V_92 * V_94 ,
struct V_100 * V_101 ,
struct V_30 * V_56 )
{
struct V_26 * V_27 ;
int V_106 ;
if ( ! V_56 || F_57 ( V_56 ) )
return 0 ;
F_19 (term, head_config, list) {
char V_102 [ V_75 ] ;
int V_55 ;
if ( V_27 -> V_28 != V_107 ) {
snprintf ( V_102 , sizeof( V_102 ) ,
L_28 ) ;
V_102 [ V_75 - 1 ] = '\0' ;
V_94 -> error -> V_35 = V_27 -> V_108 ;
V_94 -> error -> V_21 = F_15 ( V_102 ) ;
return - V_10 ;
}
V_55 = F_58 ( V_101 , V_27 , V_94 -> V_93 , & V_106 ) ;
if ( V_55 ) {
F_59 ( V_101 , V_27 , V_94 -> V_93 ,
& V_106 , V_55 , V_102 ,
sizeof( V_102 ) ) ;
V_94 -> error -> V_74 = F_15 (
L_29
L_30
L_31
L_32
L_33
L_34 ) ;
V_94 -> error -> V_21 = F_15 ( V_102 ) ;
if ( V_55 == - V_109 )
V_94 -> error -> V_35 = V_27 -> V_110 ;
else
V_94 -> error -> V_35 = V_27 -> V_108 + V_106 ;
return V_55 ;
}
}
return 0 ;
}
static void
F_60 ( struct V_30 * V_111 ,
struct V_30 * V_112 )
{
struct V_26 * V_27 , * V_113 ;
F_47 (term, temp, evt_head_config, list)
if ( ! F_61 ( V_27 ) )
F_62 ( & V_27 -> V_34 , V_112 ) ;
}
int F_63 ( struct V_92 * V_94 ,
struct V_30 * V_34 ,
char * V_114 ,
bool V_115 ,
struct V_30 * V_56 )
{
int V_55 ;
struct V_100 * V_101 ;
F_29 ( V_112 ) ;
if ( V_56 )
F_60 ( V_56 , & V_112 ) ;
V_101 = F_64 ( V_114 , V_115 ) ;
if ( F_37 ( V_101 ) ) {
char V_102 [ V_75 ] ;
V_55 = F_38 ( V_101 ) ;
if ( V_55 == - V_116 )
snprintf ( V_102 , sizeof( V_102 ) ,
L_35 ) ;
else
F_65 ( V_114 ,
V_115 ,
- V_55 , V_102 ,
sizeof( V_102 ) ) ;
V_94 -> error -> V_74 = F_15 ( L_27 ) ;
V_94 -> error -> V_21 = F_15 ( V_102 ) ;
return V_55 ;
}
V_55 = F_50 ( V_94 , V_34 , V_101 , V_56 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_56 ( V_94 , V_101 , & V_112 ) ;
if ( V_56 )
F_66 ( & V_112 , V_56 ) ;
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
F_68 ( V_117 ) ;
break;
case 'w' :
F_68 ( V_118 ) ;
break;
case 'x' :
F_68 ( V_119 ) ;
break;
default:
return - V_10 ;
}
}
#undef F_68
if ( ! V_37 -> V_120 )
V_37 -> V_120 = V_117 | V_118 ;
return 0 ;
}
int F_69 ( struct V_30 * V_34 , int * V_35 ,
void * V_121 , char * type , T_1 V_122 )
{
struct V_36 V_37 ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_123 = ( unsigned long ) V_121 ;
if ( F_67 ( type , & V_37 ) )
return - V_10 ;
if ( ! V_122 ) {
if ( V_37 . V_120 == V_119 )
V_122 = sizeof( long ) ;
else
V_122 = V_124 ;
}
V_37 . V_125 = V_122 ;
V_37 . type = V_126 ;
V_37 . V_127 = 1 ;
return F_26 ( V_34 , V_35 , & V_37 , NULL , NULL ) ;
}
static int F_70 ( struct V_26 * V_27 ,
struct V_54 * V_55 ,
int type )
{
if ( type == V_27 -> V_128 )
return 0 ;
if ( V_55 ) {
V_55 -> V_35 = V_27 -> V_110 ;
if ( type == V_129 )
V_55 -> V_21 = F_15 ( L_36 ) ;
else
V_55 -> V_21 = F_15 ( L_37 ) ;
}
return - V_10 ;
}
static bool
F_71 ( int V_130 , struct V_54 * V_55 )
{
if ( V_130 < 0 || V_130 >= V_131 ) {
V_55 -> V_21 = F_15 ( L_38 ) ;
return false ;
}
if ( ! V_132 )
return true ;
switch ( V_130 ) {
case V_133 :
case V_134 :
case V_135 :
case V_29 :
return true ;
default:
if ( ! V_55 )
return false ;
if ( F_72 ( & V_55 -> V_21 , L_39 ,
V_136 [ V_130 ] ) < 0 )
V_55 -> V_21 = NULL ;
return false ;
}
}
void F_73 ( void )
{
V_132 = true ;
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
case V_133 :
F_74 ( V_137 ) ;
V_37 -> V_12 = V_27 -> V_32 . V_138 ;
break;
case V_134 :
F_74 ( V_137 ) ;
V_37 -> V_139 = V_27 -> V_32 . V_138 ;
break;
case V_135 :
F_74 ( V_137 ) ;
V_37 -> V_140 = V_27 -> V_32 . V_138 ;
break;
case V_141 :
F_74 ( V_137 ) ;
break;
case V_142 :
F_74 ( V_137 ) ;
break;
case V_143 :
break;
case V_144 :
F_74 ( V_137 ) ;
if ( V_27 -> V_32 . V_138 > 1 ) {
V_55 -> V_21 = F_15 ( L_40 ) ;
V_55 -> V_35 = V_27 -> V_110 ;
return - V_10 ;
}
break;
case V_145 :
F_74 ( V_146 ) ;
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
case V_29 :
F_74 ( V_146 ) ;
break;
default:
V_55 -> V_21 = F_15 ( L_41 ) ;
V_55 -> V_35 = V_27 -> V_108 ;
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
if ( V_27 -> V_28 == V_107 )
return 0 ;
else
return V_71 ( V_37 , V_27 , V_55 ) ;
}
static int F_77 ( struct V_36 * V_37 ,
struct V_26 * V_27 ,
struct V_54 * V_55 )
{
switch ( V_27 -> V_28 ) {
case V_145 :
case V_147 :
case V_148 :
case V_149 :
return V_71 ( V_37 , V_27 , V_55 ) ;
default:
if ( V_55 ) {
V_55 -> V_35 = V_27 -> V_108 ;
V_55 -> V_21 = F_15 ( L_41 ) ;
V_55 -> V_74 = F_15 ( L_42 ) ;
}
return - V_10 ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_30 * V_150 ,
struct V_54 * V_55 ,
T_4 V_151 )
{
struct V_26 * V_27 ;
F_19 (term, head, list)
if ( V_151 ( V_37 , V_27 , V_55 ) )
return - V_10 ;
return 0 ;
}
static int F_32 ( struct V_30 * V_56 ,
struct V_30 * V_31 V_152 )
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
case V_141 :
F_78 ( V_153 , V_154 , V_27 -> V_32 . V_138 ) ;
break;
case V_142 :
F_78 ( V_155 , V_156 , V_27 -> V_32 . V_138 ) ;
break;
case V_144 :
F_78 ( TIME , time , V_27 -> V_32 . V_138 ) ;
break;
case V_145 :
F_78 ( V_157 , V_158 , V_27 -> V_32 . V_21 ) ;
break;
case V_147 :
F_78 ( V_159 , V_160 , V_27 -> V_32 . V_138 ) ;
break;
case V_148 :
F_78 ( V_161 , V_162 , V_27 -> V_32 . V_138 ? 1 : 0 ) ;
break;
case V_149 :
F_78 ( V_161 , V_162 , V_27 -> V_32 . V_138 ? 0 : 1 ) ;
break;
default:
break;
}
}
#undef V_163
return 0 ;
}
int F_46 ( struct V_30 * V_34 , int * V_35 ,
char * V_73 , char * V_97 ,
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
return F_43 ( V_34 , V_35 , V_73 , V_97 ,
V_55 , V_56 ) ;
else
return F_42 ( V_34 , V_35 , V_73 , V_97 ,
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
struct V_164 V_165 ;
struct V_166 * V_167 ;
struct V_33 * V_41 ;
F_29 ( V_40 ) ;
V_167 = F_81 ( V_20 ) ;
if ( ! V_167 )
return - V_10 ;
if ( V_167 -> V_168 ) {
memcpy ( & V_37 , V_167 -> V_168 ,
sizeof( struct V_36 ) ) ;
} else {
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
}
if ( ! V_56 ) {
V_37 . type = V_167 -> type ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 , NULL , V_167 -> V_39 , NULL ) ;
return V_41 ? 0 : - V_44 ;
}
if ( F_82 ( V_167 , V_56 , & V_165 ) )
return - V_10 ;
if ( F_31 ( & V_37 , V_56 , V_94 -> error , F_76 ) )
return - V_10 ;
if ( F_32 ( V_56 , & V_40 ) )
return - V_44 ;
if ( F_83 ( V_167 , & V_37 , V_56 , V_94 -> error ) )
return - V_10 ;
V_41 = F_20 ( V_34 , & V_94 -> V_35 , & V_37 ,
F_18 ( V_56 ) , V_167 -> V_39 ,
& V_40 ) ;
if ( V_41 ) {
V_41 -> V_169 = V_165 . V_169 ;
V_41 -> V_170 = V_165 . V_170 ;
V_41 -> V_171 = V_165 . V_171 ;
V_41 -> V_172 = V_165 . V_172 ;
}
return V_41 ? 0 : - V_44 ;
}
int F_84 ( struct V_30 * V_34 ,
char * V_173 )
{
return F_85 ( V_34 , V_173 , true ) ;
}
void F_86 ( char * V_20 , struct V_30 * V_34 )
{
struct V_33 * V_174 ;
if ( F_57 ( V_34 ) ) {
F_87 ( true , L_43 ) ;
return;
}
F_88 ( V_34 ) ;
V_174 = F_89 ( V_34 -> V_175 , struct V_33 , V_43 ) ;
V_174 -> V_176 = V_20 ? F_15 ( V_20 ) : NULL ;
}
void F_90 ( struct V_30 * V_177 ,
struct V_30 * V_178 )
{
F_66 ( V_177 , V_178 ) ;
free ( V_177 ) ;
}
static int F_91 ( struct V_179 * V_180 , char * V_21 ,
struct V_33 * V_41 )
{
int V_181 = V_41 ? V_41 -> V_37 . V_182 : 0 ;
int V_183 = V_41 ? V_41 -> V_37 . V_184 : 0 ;
int V_185 = V_41 ? V_41 -> V_37 . V_186 : 0 ;
int V_187 = V_41 ? V_41 -> V_37 . V_188 : 0 ;
int V_189 = V_41 ? V_41 -> V_37 . V_190 : 0 ;
int V_191 = V_41 ? V_41 -> V_37 . V_192 : 0 ;
int V_193 = V_41 ? V_41 -> V_37 . V_194 : 0 ;
int V_195 = 0 ;
int V_196 = 0 ;
int V_197 = V_41 ? V_41 -> V_37 . V_197 : 0 ;
int V_198 = V_181 | V_183 | V_185 ;
int V_199 = V_41 ? V_41 -> V_199 : 0 ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
while ( * V_21 ) {
if ( * V_21 == 'u' ) {
if ( ! V_198 )
V_198 = V_181 = V_183 = V_185 = 1 ;
V_181 = 0 ;
} else if ( * V_21 == 'k' ) {
if ( ! V_198 )
V_198 = V_181 = V_183 = V_185 = 1 ;
V_183 = 0 ;
} else if ( * V_21 == 'h' ) {
if ( ! V_198 )
V_198 = V_181 = V_183 = V_185 = 1 ;
V_185 = 0 ;
} else if ( * V_21 == 'G' ) {
if ( ! V_199 )
V_199 = V_189 = V_187 = 1 ;
V_189 = 0 ;
} else if ( * V_21 == 'H' ) {
if ( ! V_199 )
V_199 = V_189 = V_187 = 1 ;
V_187 = 0 ;
} else if ( * V_21 == 'I' ) {
V_191 = 1 ;
} else if ( * V_21 == 'p' ) {
V_193 ++ ;
if ( ! V_199 )
V_189 = 1 ;
} else if ( * V_21 == 'P' ) {
V_195 = 1 ;
} else if ( * V_21 == 'S' ) {
V_196 = 1 ;
} else if ( * V_21 == 'D' ) {
V_197 = 1 ;
} else
break;
++ V_21 ;
}
if ( V_193 > 3 )
return - V_10 ;
V_180 -> V_181 = V_181 ;
V_180 -> V_183 = V_183 ;
V_180 -> V_185 = V_185 ;
V_180 -> V_187 = V_187 ;
V_180 -> V_189 = V_189 ;
V_180 -> V_191 = V_191 ;
V_180 -> V_193 = V_193 ;
V_180 -> V_195 = V_195 ;
V_180 -> V_199 = V_199 ;
V_180 -> V_196 = V_196 ;
V_180 -> V_197 = V_197 ;
return 0 ;
}
static int F_92 ( char * V_21 )
{
char * V_200 = V_21 ;
if ( strlen ( V_21 ) > ( sizeof( L_44 ) - 1 ) )
return - 1 ;
while ( * V_200 ) {
if ( * V_200 != 'p' && strchr ( V_200 + 1 , * V_200 ) )
return - 1 ;
V_200 ++ ;
}
return 0 ;
}
int F_85 ( struct V_30 * V_34 , char * V_21 , bool V_201 )
{
struct V_33 * V_41 ;
struct V_179 V_180 ;
if ( V_21 == NULL )
return 0 ;
if ( F_92 ( V_21 ) )
return - V_10 ;
if ( ! V_201 && F_91 ( & V_180 , V_21 , NULL ) )
return - V_10 ;
F_93 (list, evsel) {
if ( V_201 && F_91 ( & V_180 , V_21 , V_41 ) )
return - V_10 ;
V_41 -> V_37 . V_182 = V_180 . V_181 ;
V_41 -> V_37 . V_184 = V_180 . V_183 ;
V_41 -> V_37 . V_186 = V_180 . V_185 ;
V_41 -> V_37 . V_194 = V_180 . V_193 ;
V_41 -> V_37 . V_188 = V_180 . V_187 ;
V_41 -> V_37 . V_190 = V_180 . V_189 ;
V_41 -> V_37 . V_192 = V_180 . V_191 ;
V_41 -> V_199 = V_180 . V_199 ;
V_41 -> V_196 = V_180 . V_196 ;
V_41 -> V_195 = V_180 . V_195 ;
if ( F_94 ( V_41 ) )
V_41 -> V_37 . V_197 = V_180 . V_197 ;
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
F_96 ( const void * V_202 , const void * V_203 )
{
struct V_204 * V_205 = (struct V_204 * ) V_202 ;
struct V_204 * V_206 = (struct V_204 * ) V_203 ;
return strcmp ( V_205 -> V_207 , V_206 -> V_207 ) ;
}
static void F_97 ( void )
{
if ( V_208 > 0 ) {
struct V_204 * V_200 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_208 ; V_48 ++ ) {
V_200 = V_209 + V_48 ;
free ( V_200 -> V_207 ) ;
}
free ( V_209 ) ;
V_209 = NULL ;
V_208 = 0 ;
}
}
static void F_98 ( void )
{
struct V_166 * V_167 = NULL ;
struct V_210 * V_211 ;
int V_122 = 0 ;
V_167 = F_81 ( L_45 ) ;
if ( ( V_167 == NULL ) || F_57 ( & V_167 -> V_212 ) ) {
V_208 = - 1 ;
return;
}
F_19 (alias, &pmu->aliases, list) {
if ( strchr ( V_211 -> V_20 , '-' ) )
V_122 ++ ;
V_122 ++ ;
}
V_209 = malloc ( sizeof( struct V_204 ) * V_122 ) ;
if ( ! V_209 )
return;
V_208 = V_122 ;
V_122 = 0 ;
F_19 (alias, &pmu->aliases, list) {
struct V_204 * V_200 = V_209 + V_122 ;
char * V_98 = strchr ( V_211 -> V_20 , '-' ) ;
if ( V_98 != NULL ) {
F_99 ( F_14 ( V_211 -> V_20 , V_98 - V_211 -> V_20 ) ,
V_213 ) ;
V_200 ++ ;
F_99 ( F_15 ( ++ V_98 ) , V_214 ) ;
V_122 += 2 ;
} else {
F_99 ( F_15 ( V_211 -> V_20 ) , V_215 ) ;
V_122 ++ ;
}
}
qsort ( V_209 , V_122 ,
sizeof( struct V_204 ) , F_96 ) ;
return;
V_55:
F_97 () ;
}
enum V_216
F_100 ( const char * V_20 )
{
struct V_204 V_200 , * V_217 ;
if ( V_208 == 0 )
F_98 () ;
if ( ( V_208 <= 0 ) || ! strcmp ( V_20 , L_45 ) )
return V_218 ;
V_200 . V_207 = F_15 ( V_20 ) ;
V_217 = bsearch ( & V_200 , V_209 ,
( V_219 ) V_208 ,
sizeof( struct V_204 ) , F_96 ) ;
free ( V_200 . V_207 ) ;
return V_217 ? V_217 -> type : V_218 ;
}
static int F_101 ( const char * V_21 , void * V_94 , int V_220 )
{
T_9 V_221 ;
void * V_222 ;
int V_81 ;
V_81 = F_102 ( V_220 , & V_222 ) ;
if ( V_81 )
return V_81 ;
V_221 = F_103 ( V_21 , V_222 ) ;
#ifdef F_104
V_223 = 1 ;
#endif
V_81 = F_105 ( V_94 , V_222 ) ;
F_106 ( V_221 , V_222 ) ;
F_107 ( V_221 , V_222 ) ;
F_108 ( V_222 ) ;
return V_81 ;
}
int F_109 ( struct V_30 * V_224 , const char * V_21 )
{
struct F_109 V_94 = {
. V_224 = NULL ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_225 ) ;
if ( ! V_81 ) {
F_24 ( V_94 . V_224 , V_224 ) ;
F_12 ( & V_94 . V_224 ) ;
return 0 ;
}
F_110 ( V_94 . V_224 ) ;
return V_81 ;
}
int F_111 ( struct V_226 * V_93 , const char * V_21 ,
struct V_54 * V_55 )
{
struct V_92 V_94 = {
. V_34 = F_112 ( V_94 . V_34 ) ,
. V_35 = V_93 -> V_227 ,
. error = V_55 ,
. V_93 = V_93 ,
} ;
int V_81 ;
V_81 = F_101 ( V_21 , & V_94 , V_228 ) ;
F_97 () ;
if ( ! V_81 ) {
struct V_33 * V_229 ;
if ( F_57 ( & V_94 . V_34 ) ) {
F_87 ( true , L_46 ) ;
return - 1 ;
}
F_113 ( V_93 , & V_94 . V_34 ) ;
V_93 -> V_230 += V_94 . V_230 ;
V_229 = F_114 ( V_93 ) ;
V_229 -> V_231 = true ;
return 0 ;
}
return V_81 ;
}
static int F_115 ( void )
{
struct V_232 V_233 ;
F_116 ( & V_233 ) ;
return V_233 . V_234 > V_235 ? V_235 : V_233 . V_234 ;
}
static void F_117 ( struct V_54 * V_55 ,
const char * V_97 )
{
const char * V_21 = L_47 ;
char V_236 [ V_235 ] ;
char * V_237 = ( char * ) V_97 ;
int V_35 = 0 ;
if ( V_55 -> V_21 ) {
int V_238 = F_115 () - 2 ;
int V_239 = strlen ( V_97 ) ;
int V_240 , V_241 , V_242 = 0 ;
int V_243 = 13 ;
V_21 = L_48 ;
V_240 = strlen ( V_21 ) ;
V_241 = V_238 - V_240 ;
V_237 = V_236 ;
if ( V_55 -> V_35 > V_243 )
V_242 = V_55 -> V_35 - V_243 ;
strncpy ( V_237 , V_97 + V_242 , V_241 ) ;
if ( V_242 )
V_237 [ 0 ] = V_237 [ 1 ] = '.' ;
if ( ( V_239 - V_242 ) > V_241 ) {
V_237 [ V_241 - 1 ] = V_237 [ V_241 - 2 ] = '.' ;
V_237 [ V_241 ] = 0 ;
}
V_35 = V_240 + V_55 -> V_35 - V_242 ;
}
fprintf ( V_244 , L_49 , V_21 , V_237 ) ;
if ( V_35 ) {
fprintf ( V_244 , L_50 , V_35 + 1 , L_51 , V_55 -> V_21 ) ;
if ( V_55 -> V_74 )
fprintf ( V_244 , L_52 , V_55 -> V_74 ) ;
free ( V_55 -> V_21 ) ;
free ( V_55 -> V_74 ) ;
}
fprintf ( V_244 , L_53 ) ;
}
int F_118 ( const struct V_245 * V_246 , const char * V_21 ,
int T_10 V_152 )
{
struct V_226 * V_93 = * (struct V_226 * * ) V_246 -> V_247 ;
struct V_54 V_55 = { . V_35 = 0 , } ;
int V_81 = F_111 ( V_93 , V_21 , & V_55 ) ;
if ( V_81 )
F_117 ( & V_55 , V_21 ) ;
return V_81 ;
}
static int
F_119 ( struct V_226 * V_93 ,
int (* F_120)( struct V_33 * V_41 ,
const void * V_248 ) ,
const void * V_248 )
{
struct V_33 * V_229 = NULL ;
int V_55 ;
if ( V_93 -> V_227 > 0 )
V_229 = F_114 ( V_93 ) ;
do {
V_55 = (* F_120)( V_229 , V_248 ) ;
if ( V_55 )
return - 1 ;
if ( ! V_229 )
return 0 ;
if ( V_229 -> V_43 . V_249 == & V_93 -> V_250 )
return 0 ;
V_229 = F_89 ( V_229 -> V_43 . V_249 , struct V_33 , V_43 ) ;
} while ( ! V_229 -> V_231 );
return 0 ;
}
static int F_121 ( struct V_33 * V_41 , const void * V_248 )
{
const char * V_21 = V_248 ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_244 ,
L_54 ) ;
return - 1 ;
}
if ( F_122 ( V_41 , L_55 , V_21 ) < 0 ) {
fprintf ( V_244 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
int F_123 ( const struct V_245 * V_246 , const char * V_21 ,
int T_10 V_152 )
{
struct V_226 * V_93 = * (struct V_226 * * ) V_246 -> V_247 ;
return F_119 ( V_93 , F_121 ,
( const void * ) V_21 ) ;
}
static int F_124 ( struct V_33 * V_41 ,
const void * V_248 V_152 )
{
char V_251 [ 64 ] ;
if ( V_41 == NULL || V_41 -> V_37 . type != V_24 ) {
fprintf ( V_244 ,
L_57 ) ;
return - 1 ;
}
snprintf ( V_251 , sizeof( V_251 ) , L_58 , F_125 () ) ;
if ( F_122 ( V_41 , L_55 , V_251 ) < 0 ) {
fprintf ( V_244 ,
L_56 ) ;
return - 1 ;
}
return 0 ;
}
int F_126 ( const struct V_245 * V_246 ,
const char * V_248 V_152 ,
int T_10 V_152 )
{
struct V_226 * V_93 = * (struct V_226 * * ) V_246 -> V_247 ;
return F_119 ( V_93 , F_124 ,
NULL ) ;
}
static int F_127 ( const void * V_252 , const void * V_253 )
{
const char * const * V_254 = V_252 ;
const char * const * V_255 = V_253 ;
return strcmp ( * V_254 , * V_255 ) ;
}
void F_128 ( const char * V_256 , const char * V_257 ,
bool V_258 )
{
T_2 * V_2 , * V_3 ;
struct V_1 * V_14 , * V_15 ;
char V_4 [ V_5 ] ;
char V_18 [ V_5 ] ;
char * * V_259 = NULL ;
unsigned int V_260 = 0 , V_261 = 0 ;
bool V_262 = false ;
V_263:
V_2 = F_5 ( V_7 ) ;
if ( ! V_2 )
return;
if ( V_262 ) {
V_259 = F_11 ( sizeof( char * ) * V_261 ) ;
if ( ! V_259 )
goto V_264;
}
F_6 (sys_dir, sys_dirent) {
if ( V_256 != NULL &&
! F_41 ( V_14 -> V_8 , V_256 ) )
continue;
snprintf ( V_18 , V_5 , L_2 , V_7 ,
V_14 -> V_8 ) ;
V_3 = F_5 ( V_18 ) ;
if ( ! V_3 )
continue;
F_7 (sys_dirent, evt_dir, evt_dirent) {
if ( V_257 != NULL &&
! F_41 ( V_15 -> V_8 , V_257 ) )
continue;
if ( ! V_262 ) {
V_261 ++ ;
continue;
}
snprintf ( V_4 , V_5 , L_59 ,
V_14 -> V_8 , V_15 -> V_8 ) ;
V_259 [ V_260 ] = F_15 ( V_4 ) ;
if ( V_259 [ V_260 ] == NULL )
goto V_265;
V_260 ++ ;
}
F_10 ( V_3 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_262 ) {
V_262 = true ;
goto V_263;
}
qsort ( V_259 , V_261 , sizeof( char * ) , F_127 ) ;
V_260 = 0 ;
while ( V_260 < V_261 ) {
if ( V_258 ) {
printf ( L_60 , V_259 [ V_260 ++ ] ) ;
continue;
}
printf ( L_61 , V_259 [ V_260 ++ ] ,
V_266 [ V_24 ] ) ;
}
if ( V_261 && F_129 () )
printf ( L_32 ) ;
V_267:
V_261 = V_260 ;
for ( V_260 = 0 ; V_260 < V_261 ; V_260 ++ )
F_12 ( & V_259 [ V_260 ] ) ;
F_12 ( & V_259 ) ;
return;
V_265:
F_10 ( V_3 ) ;
V_264:
F_10 ( V_2 ) ;
printf ( L_62 ,
V_266 [ V_24 ] ) ;
if ( V_259 )
goto V_267;
}
int F_130 ( const char * V_268 )
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
if ( ! strcmp ( V_4 , V_268 ) ) {
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
int V_269 ;
struct V_33 * V_41 ;
struct V_36 V_37 = {
. type = type ,
. V_12 = V_12 ,
. V_270 = 1 ,
} ;
struct {
struct V_271 V_272 ;
int V_273 [ 1 ] ;
} V_274 = {
. V_272 . V_275 = 1 ,
. V_273 = { 0 } ,
} ;
V_41 = F_132 ( & V_37 ) ;
if ( V_41 ) {
V_269 = F_133 ( V_41 , NULL , & V_274 . V_272 ) ;
V_81 = V_269 >= 0 ;
if ( V_269 == - V_76 ) {
V_41 -> V_37 . V_184 = 1 ;
V_81 = F_133 ( V_41 , NULL , & V_274 . V_272 ) >= 0 ;
}
F_49 ( V_41 ) ;
}
return V_81 ;
}
int F_134 ( const char * V_257 , bool V_258 )
{
unsigned int type , V_276 , V_48 , V_260 = 0 , V_261 = 0 ;
char V_20 [ 64 ] ;
char * * V_259 = NULL ;
bool V_262 = false ;
V_263:
if ( V_262 ) {
V_259 = F_11 ( sizeof( char * ) * V_261 ) ;
if ( ! V_259 )
goto V_277;
}
for ( type = 0 ; type < V_64 ; type ++ ) {
for ( V_276 = 0 ; V_276 < V_66 ; V_276 ++ ) {
if ( ! F_30 ( type , V_276 ) )
continue;
for ( V_48 = 0 ; V_48 < V_68 ; V_48 ++ ) {
F_135 ( type , V_276 , V_48 ,
V_20 , sizeof( V_20 ) ) ;
if ( V_257 != NULL && ! F_41 ( V_20 , V_257 ) )
continue;
if ( ! F_131 ( V_25 ,
type | ( V_276 << 8 ) | ( V_48 << 16 ) ) )
continue;
if ( ! V_262 ) {
V_261 ++ ;
continue;
}
V_259 [ V_260 ] = F_15 ( V_20 ) ;
if ( V_259 [ V_260 ] == NULL )
goto V_277;
V_260 ++ ;
}
}
}
if ( ! V_262 ) {
V_262 = true ;
goto V_263;
}
qsort ( V_259 , V_261 , sizeof( char * ) , F_127 ) ;
V_260 = 0 ;
while ( V_260 < V_261 ) {
if ( V_258 ) {
printf ( L_60 , V_259 [ V_260 ++ ] ) ;
continue;
}
printf ( L_61 , V_259 [ V_260 ++ ] ,
V_266 [ V_25 ] ) ;
}
if ( V_261 && F_129 () )
printf ( L_32 ) ;
V_267:
V_261 = V_260 ;
for ( V_260 = 0 ; V_260 < V_261 ; V_260 ++ )
F_12 ( & V_259 [ V_260 ] ) ;
F_12 ( & V_259 ) ;
return V_261 ;
V_277:
printf ( L_62 , V_266 [ V_25 ] ) ;
if ( V_259 )
goto V_267;
return V_261 ;
}
void F_136 ( const char * V_257 , unsigned type ,
struct V_278 * V_279 , unsigned V_280 ,
bool V_258 )
{
unsigned int V_48 , V_260 = 0 , V_261 = 0 ;
char V_20 [ V_57 ] ;
char * * V_259 = NULL ;
bool V_262 = false ;
V_263:
if ( V_262 ) {
V_259 = F_11 ( sizeof( char * ) * V_261 ) ;
if ( ! V_259 )
goto V_277;
V_279 -= V_280 ;
}
for ( V_48 = 0 ; V_48 < V_280 ; V_48 ++ , V_279 ++ ) {
if ( V_257 != NULL && V_279 -> V_207 != NULL &&
! ( F_41 ( V_279 -> V_207 , V_257 ) ||
( V_279 -> V_211 && F_41 ( V_279 -> V_211 , V_257 ) ) ) )
continue;
if ( ! F_131 ( type , V_48 ) )
continue;
if ( ! V_262 ) {
V_261 ++ ;
continue;
}
if ( ! V_258 && strlen ( V_279 -> V_211 ) )
snprintf ( V_20 , V_57 , L_63 , V_279 -> V_207 , V_279 -> V_211 ) ;
else
strncpy ( V_20 , V_279 -> V_207 , V_57 ) ;
V_259 [ V_260 ] = F_15 ( V_20 ) ;
if ( V_259 [ V_260 ] == NULL )
goto V_277;
V_260 ++ ;
}
if ( ! V_262 ) {
V_262 = true ;
goto V_263;
}
qsort ( V_259 , V_261 , sizeof( char * ) , F_127 ) ;
V_260 = 0 ;
while ( V_260 < V_261 ) {
if ( V_258 ) {
printf ( L_60 , V_259 [ V_260 ++ ] ) ;
continue;
}
printf ( L_61 , V_259 [ V_260 ++ ] , V_266 [ type ] ) ;
}
if ( V_261 && F_129 () )
printf ( L_32 ) ;
V_267:
V_261 = V_260 ;
for ( V_260 = 0 ; V_260 < V_261 ; V_260 ++ )
F_12 ( & V_259 [ V_260 ] ) ;
F_12 ( & V_259 ) ;
return;
V_277:
printf ( L_62 , V_266 [ type ] ) ;
if ( V_259 )
goto V_267;
}
void F_137 ( const char * V_257 , bool V_258 )
{
F_136 ( V_257 , V_22 ,
V_281 , V_282 , V_258 ) ;
F_136 ( V_257 , V_23 ,
V_283 , V_284 , V_258 ) ;
F_134 ( V_257 , V_258 ) ;
F_138 ( V_257 , V_258 ) ;
if ( V_257 != NULL )
return;
if ( ! V_258 ) {
printf ( L_61 ,
L_64 ,
V_266 [ V_285 ] ) ;
printf ( L_61 ,
L_65 ,
V_266 [ V_285 ] ) ;
if ( F_129 () )
printf ( L_66 ) ;
printf ( L_61 ,
L_67 ,
V_266 [ V_126 ] ) ;
if ( F_129 () )
printf ( L_32 ) ;
}
F_128 ( NULL , NULL , V_258 ) ;
}
int F_61 ( struct V_26 * V_27 )
{
return V_27 -> V_28 != V_107 ;
}
static int F_139 ( struct V_26 * * V_286 , int V_128 ,
int V_28 , char * V_12 ,
char * V_21 , T_1 V_138 , int V_108 , int V_110 )
{
struct V_26 * V_27 ;
V_27 = F_11 ( sizeof( * V_27 ) ) ;
if ( ! V_27 )
return - V_44 ;
F_140 ( & V_27 -> V_34 ) ;
V_27 -> V_128 = V_128 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_12 = V_12 ;
V_27 -> V_108 = V_108 ;
V_27 -> V_110 = V_110 ;
switch ( V_128 ) {
case V_129 :
V_27 -> V_32 . V_138 = V_138 ;
break;
case V_287 :
V_27 -> V_32 . V_21 = V_21 ;
break;
default:
free ( V_27 ) ;
return - V_10 ;
}
* V_286 = V_27 ;
return 0 ;
}
int F_141 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , T_1 V_138 ,
void * V_288 , void * V_289 )
{
T_12 * V_290 = V_288 ;
T_12 * V_291 = V_289 ;
return F_139 ( V_27 , V_129 , V_28 ,
V_12 , NULL , V_138 ,
V_290 ? V_290 -> V_292 : 0 ,
V_291 ? V_291 -> V_292 : 0 ) ;
}
int F_142 ( struct V_26 * * V_27 ,
int V_28 , char * V_12 , char * V_21 ,
void * V_288 , void * V_289 )
{
T_12 * V_290 = V_288 ;
T_12 * V_291 = V_289 ;
return F_139 ( V_27 , V_287 , V_28 ,
V_12 , V_21 , 0 ,
V_290 ? V_290 -> V_292 : 0 ,
V_291 ? V_291 -> V_292 : 0 ) ;
}
int F_143 ( struct V_26 * * V_27 ,
char * V_12 , unsigned V_35 )
{
struct V_278 * V_293 ;
F_144 ( V_35 >= V_282 ) ;
V_293 = & V_281 [ V_35 ] ;
if ( V_12 )
return F_139 ( V_27 , V_287 ,
V_107 , V_12 ,
( char * ) V_293 -> V_207 , 0 , 0 , 0 ) ;
else
return F_139 ( V_27 , V_287 ,
V_107 ,
( char * ) L_68 , ( char * ) V_293 -> V_207 ,
0 , 0 , 0 ) ;
}
int F_145 ( struct V_26 * * V_294 ,
struct V_26 * V_27 )
{
return F_139 ( V_294 , V_27 -> V_128 , V_27 -> V_28 , V_27 -> V_12 ,
V_27 -> V_32 . V_21 , V_27 -> V_32 . V_138 ,
V_27 -> V_108 , V_27 -> V_110 ) ;
}
void F_146 ( struct V_30 * V_224 )
{
struct V_26 * V_27 , * V_295 ;
F_47 (term, h, terms, list) {
if ( V_27 -> V_296 . V_297 )
free ( V_27 -> V_296 . V_298 ) ;
F_147 ( & V_27 -> V_34 ) ;
free ( V_27 ) ;
}
}
void F_110 ( struct V_30 * V_224 )
{
if ( ! V_224 )
return;
F_146 ( V_224 ) ;
free ( V_224 ) ;
}
void F_148 ( struct V_299 * V_252 )
{
free ( V_252 -> V_298 ) ;
}
void F_149 ( struct V_92 * V_94 ,
int V_35 , const char * V_21 )
{
struct V_54 * V_55 = V_94 -> error ;
if ( ! V_55 )
return;
V_55 -> V_35 = V_35 ;
V_55 -> V_21 = F_15 ( V_21 ) ;
F_87 ( ! V_55 -> V_21 , L_69 ) ;
}
static void F_150 ( char * V_237 , V_219 V_300 )
{
int V_48 ;
bool V_301 = true ;
V_237 [ 0 ] = '\0' ;
for ( V_48 = 0 ; V_48 < V_131 ; V_48 ++ ) {
const char * V_20 = V_136 [ V_48 ] ;
if ( ! F_71 ( V_48 , NULL ) )
continue;
if ( ! V_20 )
continue;
if ( V_20 [ 0 ] == '<' )
continue;
if ( strlen ( V_237 ) + strlen ( V_20 ) + 2 >= V_300 )
return;
if ( ! V_301 )
strcat ( V_237 , L_70 ) ;
else
V_301 = false ;
strcat ( V_237 , V_20 ) ;
}
}
char * F_75 ( char * V_302 )
{
char * V_21 ;
char V_303 [ V_131 *
( sizeof( L_71 ) - 1 ) ] ;
F_150 ( V_303 , sizeof( V_303 ) ) ;
if ( V_302 ) {
if ( F_72 ( & V_21 , L_72 ,
V_302 , V_303 ) < 0 )
goto V_304;
} else {
if ( F_72 ( & V_21 , L_73 , V_303 ) < 0 )
goto V_304;
}
return V_21 ;
V_304:
return NULL ;
}
