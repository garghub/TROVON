int F_1 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * T_2 V_2 ,
struct V_8 * V_8 )
{
struct V_9 V_10 ;
struct V_11 * V_11 = F_2 ( V_8 , V_6 -> V_12 ,
V_6 -> V_13 ) ;
if ( V_11 == NULL ) {
F_3 ( L_1 ,
V_4 -> V_14 . type ) ;
return - 1 ;
}
F_4 ( V_11 , V_6 -> V_15 , V_16 , V_6 -> V_17 , & V_10 ) ;
if ( V_10 . V_18 != NULL )
V_10 . V_18 -> V_19 -> V_20 = 1 ;
F_5 ( V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * T_1 V_2 ,
union V_3 * V_4 ,
struct V_5 * V_6
V_2 ,
struct V_8 * V_8 )
{
struct V_11 * V_11 = F_2 ( V_8 ,
V_4 -> V_21 . V_12 ,
V_4 -> V_21 . V_13 ) ;
F_7 ( L_2 , V_4 -> V_21 . V_12 , V_4 -> V_21 . V_13 ,
V_4 -> V_21 . V_22 , V_4 -> V_21 . V_23 ) ;
if ( V_11 ) {
F_8 ( V_8 , V_11 ) ;
F_5 ( V_11 ) ;
}
return 0 ;
}
int F_9 ( const T_3 * V_24 , int V_25 , char * V_26 )
{
char * V_27 = V_26 ;
const T_3 * V_28 = V_24 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; ++ V_29 ) {
sprintf ( V_27 , L_3 , * V_28 ) ;
++ V_28 ;
V_27 += 2 ;
}
return ( V_27 - V_26 ) + 1 ;
}
int F_10 ( const char * V_30 , char * V_31 )
{
char V_32 [ V_33 ] ;
T_3 V_24 [ V_34 ] ;
int V_35 ;
if ( ! V_30 )
V_30 = L_4 ;
F_11 ( V_32 , sizeof( V_32 ) , L_5 , V_30 ) ;
V_35 = F_12 ( V_32 , V_24 , sizeof( V_24 ) ) ;
if ( V_35 < 0 )
return V_35 ;
return F_9 ( V_24 , sizeof( V_24 ) , V_31 ) ;
}
int F_13 ( const char * V_36 , char * V_31 )
{
T_3 V_24 [ V_34 ] ;
int V_35 ;
V_35 = F_14 ( V_36 , V_24 , sizeof( V_24 ) ) ;
if ( V_35 < 0 )
return V_35 ;
else if ( V_35 != sizeof( V_24 ) )
return - V_37 ;
return F_9 ( V_24 , sizeof( V_24 ) , V_31 ) ;
}
static int F_15 ( char * * V_38 , T_4 V_39 , const char * V_40 , ... )
{
T_5 V_41 ;
int V_35 ;
if ( ! V_38 )
return - V_37 ;
va_start ( V_41 , V_40 ) ;
if ( * V_38 )
V_35 = vsnprintf ( * V_38 , V_39 , V_40 , V_41 ) ;
else
V_35 = F_16 ( V_38 , V_40 , V_41 ) ;
va_end ( V_41 ) ;
return V_35 ;
}
char * F_17 ( const char * V_31 , char * V_26 ,
T_4 V_39 )
{
bool V_42 = true ;
snprintf ( V_26 , V_39 , L_6 ,
V_43 , V_44 , V_31 ) ;
V_45:
if ( ! F_18 ( V_26 , V_46 ) )
return V_26 ;
if ( V_42 ) {
snprintf ( V_26 , V_39 , L_7 ,
V_43 , V_44 , V_31 ) ;
V_42 = false ;
goto V_45;
}
return NULL ;
}
char * F_19 ( const char * V_31 , char * V_26 , T_4 V_39 )
{
char * V_47 = V_26 ;
int V_35 = F_15 ( & V_26 , V_39 , L_8 , V_43 ,
V_31 , V_31 + 2 ) ;
if ( V_35 < 0 || ( V_47 && V_39 < ( unsigned int ) V_35 ) )
return NULL ;
return V_26 ;
}
char * F_20 ( const char * V_31 )
{
char * V_48 ;
char V_49 [ V_33 ] ;
char * V_35 = NULL , * V_50 ;
T_4 V_51 = 5 ;
T_6 V_25 ;
V_48 = F_19 ( V_31 , NULL , 0 ) ;
if ( ! V_48 )
return NULL ;
V_25 = F_21 ( V_48 , V_49 , sizeof( V_49 ) - 1 ) ;
if ( V_25 <= 0 )
goto V_52;
V_49 [ V_25 ] = '\0' ;
V_50 = strrchr ( V_49 , '/' ) ;
if ( V_50 && ( V_50 > V_49 + V_51 ) ) {
* V_50 = '\0' ;
if ( V_49 [ V_51 + 1 ] == '[' )
V_51 ++ ;
V_35 = F_22 ( V_49 + V_51 ) ;
}
V_52:
free ( V_48 ) ;
return V_35 ;
}
static bool F_23 ( char * V_31 )
{
char V_53 [ V_54 ] = L_4 ;
char * V_36 ;
int V_35 = 0 ;
bool V_55 = false ;
V_36 = F_20 ( V_31 ) ;
if ( ! V_36 )
return false ;
if ( ! strcmp ( V_36 , V_44 ) )
V_35 = F_10 ( L_9 , V_53 ) ;
else if ( V_36 [ 0 ] == '/' )
V_35 = F_13 ( V_36 , V_53 ) ;
else
V_35 = - V_37 ;
if ( V_35 >= 0 )
V_55 = ( strcmp ( V_31 , V_53 ) == 0 ) ;
free ( V_36 ) ;
return V_55 ;
}
static const char * F_24 ( bool V_56 , bool V_57 ,
bool V_58 )
{
return V_56 ? L_10 : ( V_57 ? L_11 : ( V_58 ?
L_12 : L_13 ) ) ;
}
char * F_25 ( const struct V_19 * V_19 , char * V_26 , T_4 V_39 ,
bool V_58 )
{
bool V_56 = F_26 ( (struct V_19 * ) V_19 ) ;
bool V_57 = F_27 ( (struct V_19 * ) V_19 ) ;
char V_31 [ V_54 ] ;
char * V_48 ;
bool V_59 = ( V_26 == NULL ) ;
int V_35 ;
if ( ! V_19 -> V_60 )
return NULL ;
F_9 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_31 ) ;
V_48 = F_19 ( V_31 , NULL , 0 ) ;
if ( ! V_48 )
return NULL ;
if ( F_28 ( V_48 ) )
V_35 = F_15 ( & V_26 , V_39 , L_14 , V_48 ) ;
else
V_35 = F_15 ( & V_26 , V_39 , L_15 , V_48 ,
F_24 ( V_56 , V_57 ,
V_58 ) ) ;
if ( V_35 < 0 || ( ! V_59 && V_39 < ( unsigned int ) V_35 ) )
V_26 = NULL ;
free ( V_48 ) ;
return V_26 ;
}
static int F_29 ( const char * V_61 , T_4 V_62 , T_3 * V_24 ,
T_7 V_12 , T_8 V_63 , struct V_64 * V_65 )
{
int V_66 ;
struct V_67 V_68 ;
T_4 V_25 ;
V_25 = V_62 + 1 ;
V_25 = F_30 ( V_25 , V_69 ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
memcpy ( & V_68 . V_24 , V_24 , V_34 ) ;
V_68 . V_12 = V_12 ;
V_68 . V_14 . V_63 = V_63 ;
V_68 . V_14 . V_39 = sizeof( V_68 ) + V_25 ;
V_66 = F_31 ( V_65 , & V_68 , sizeof( V_68 ) ) ;
if ( V_66 < 0 )
return V_66 ;
return F_32 ( V_65 , V_61 , V_62 + 1 , V_25 ) ;
}
static int F_33 ( struct V_8 * V_8 ,
struct V_64 * V_65 )
{
int V_66 = 0 ;
char V_70 [ V_33 ] ;
struct V_19 * V_71 ;
T_8 V_72 = V_73 ,
V_74 = V_75 ;
if ( ! F_34 ( V_8 ) ) {
V_72 = V_76 ;
V_74 = V_77 ;
}
F_35 (pos, &machine->dsos.head) {
const char * V_61 ;
T_4 V_62 ;
bool V_78 = false ;
if ( ! V_71 -> V_20 && ! F_27 ( V_71 ) )
continue;
if ( F_27 ( V_71 ) ) {
V_61 = V_71 -> V_79 ;
V_62 = V_71 -> V_80 ;
} else if ( F_36 ( V_71 ) ) {
F_37 ( V_8 , V_70 , sizeof( V_70 ) ) ;
V_61 = V_70 ;
V_62 = strlen ( V_70 ) ;
} else {
V_61 = V_71 -> V_81 ;
V_62 = V_71 -> V_82 ;
}
V_78 = V_71 -> V_83 ||
F_38 ( V_61 ,
V_84 ) ;
V_66 = F_29 ( V_61 , V_62 , V_71 -> V_24 , V_8 -> V_12 ,
V_78 ? V_72 : V_74 , V_65 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
int F_39 ( struct V_85 * V_86 ,
struct V_64 * V_65 )
{
struct V_87 * V_88 ;
int V_66 = F_33 ( & V_86 -> V_89 . V_90 , V_65 ) ;
if ( V_66 )
return V_66 ;
for ( V_88 = F_40 ( & V_86 -> V_89 . V_91 ) ; V_88 ; V_88 = F_41 ( V_88 ) ) {
struct V_8 * V_71 = F_42 ( V_88 , struct V_8 , V_87 ) ;
V_66 = F_33 ( V_71 , V_65 ) ;
if ( V_66 )
break;
}
return V_66 ;
}
static int F_43 ( struct V_92 * V_93 )
{
struct V_19 * V_71 ;
F_44 (pos, head, node)
V_71 -> V_20 = true ;
return 0 ;
}
static int F_45 ( struct V_8 * V_8 )
{
return F_43 ( & V_8 -> V_94 . V_93 ) ;
}
int F_46 ( struct V_85 * V_86 )
{
struct V_87 * V_88 ;
int V_66 ;
V_66 = F_45 ( & V_86 -> V_89 . V_90 ) ;
if ( V_66 )
return V_66 ;
for ( V_88 = F_40 ( & V_86 -> V_89 . V_91 ) ; V_88 ; V_88 = F_41 ( V_88 ) ) {
struct V_8 * V_71 = F_42 ( V_88 , struct V_8 , V_87 ) ;
V_66 = F_45 ( V_71 ) ;
if ( V_66 )
return V_66 ;
}
return 0 ;
}
void F_47 ( void )
{
V_95 = true ;
}
static bool F_48 ( const char * V_61 V_2 ,
struct V_96 * V_97 )
{
return ( strlen ( V_97 -> V_98 ) == 2 ) &&
isxdigit ( V_97 -> V_98 [ 0 ] ) && isxdigit ( V_97 -> V_98 [ 1 ] ) ;
}
static bool F_49 ( const char * V_61 V_2 ,
struct V_96 * V_97 )
{
int V_29 = 0 ;
while ( isxdigit ( V_97 -> V_98 [ V_29 ] ) && V_29 < V_54 - 3 )
V_29 ++ ;
return ( V_29 == V_54 - 3 ) && ( V_97 -> V_98 [ V_29 ] == '\0' ) ;
}
struct V_99 * F_50 ( bool V_100 )
{
struct V_99 * V_101 , * V_102 = NULL , * V_103 ;
struct V_104 * V_88 , * V_105 ;
char * V_106 , * V_107 = NULL ;
char V_31 [ V_54 ] ;
if ( V_100 )
F_51 ( NULL ) ;
if ( F_52 ( & V_106 , L_16 , V_43 ) < 0 )
return NULL ;
V_103 = F_53 ( NULL , NULL ) ;
if ( ! V_103 )
goto V_52;
V_101 = F_54 ( V_106 , F_48 ) ;
if ( ! V_101 ) {
F_55 ( L_17 , V_106 , V_108 ) ;
if ( V_108 == V_109 )
goto V_52;
goto V_110;
}
F_56 (nd, toplist) {
if ( F_52 ( & V_107 , L_15 , V_106 , V_88 -> V_111 ) < 0 )
goto V_110;
V_102 = F_54 ( V_107 , F_49 ) ;
if ( ! V_102 ) {
F_55 ( L_17 , V_107 , V_108 ) ;
goto V_110;
}
F_56 (nd2, linklist) {
if ( snprintf ( V_31 , V_54 , L_18 ,
V_88 -> V_111 , V_105 -> V_111 ) != V_54 - 1 )
goto V_110;
if ( V_100 && ! F_23 ( V_31 ) )
continue;
if ( F_57 ( V_103 , V_31 ) < 0 )
goto V_110;
}
F_58 ( V_102 ) ;
F_59 ( & V_107 ) ;
}
V_112:
F_58 ( V_101 ) ;
V_52:
free ( V_106 ) ;
return V_103 ;
V_110:
F_58 ( V_102 ) ;
F_59 ( & V_107 ) ;
F_58 ( V_103 ) ;
V_103 = NULL ;
goto V_112;
}
static bool F_60 ( const char * V_113 , T_4 V_25 )
{
T_4 V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
if ( ! isxdigit ( V_113 [ V_29 ] ) )
return false ;
}
return true ;
}
char * F_61 ( const char * V_114 )
{
struct V_99 * V_103 ;
struct V_104 * V_88 , * V_115 = NULL ;
char * V_31 = NULL ;
T_4 V_25 = strlen ( V_114 ) ;
if ( V_25 >= V_54 ||
! F_60 ( V_114 , V_25 ) )
return NULL ;
V_103 = F_50 ( true ) ;
if ( ! V_103 )
return NULL ;
F_56 (nd, bidlist) {
if ( strncmp ( V_88 -> V_111 , V_114 , V_25 ) != 0 )
continue;
if ( V_115 ) {
V_115 = NULL ;
break;
}
V_115 = V_88 ;
}
if ( V_115 )
V_31 = F_22 ( V_115 -> V_111 ) ;
F_58 ( V_103 ) ;
return V_31 ;
}
char * F_62 ( const char * V_31 , const char * V_61 ,
struct V_116 * V_117 , bool V_56 ,
bool V_57 )
{
char * V_118 = ( char * ) V_61 , * V_119 ;
bool V_120 = V_56 || V_57 ;
if ( ! V_120 ) {
V_118 = F_63 ( V_61 , V_117 ) ;
if ( ! V_118 )
return NULL ;
}
if ( F_52 ( & V_119 , L_19 , V_43 , V_120 ? L_9 : L_4 ,
V_57 ? V_121 : V_118 ,
V_31 ? L_9 : L_4 , V_31 ? : L_4 ) < 0 )
V_119 = NULL ;
if ( ! V_120 )
free ( V_118 ) ;
return V_119 ;
}
int F_64 ( const char * V_36 , struct V_116 * V_117 ,
struct V_99 * * V_55 )
{
char * V_122 ;
int V_35 = 0 ;
V_122 = F_62 ( NULL , V_36 , V_117 , false , false ) ;
if ( ! V_122 )
return - V_123 ;
* V_55 = F_54 ( V_122 , V_124 ) ;
if ( ! * V_55 )
V_35 = - V_108 ;
free ( V_122 ) ;
return V_35 ;
}
static int F_65 ( const char * V_31 ,
const char * V_118 ,
struct V_116 * V_117 )
{
struct V_125 * V_126 ;
int V_35 ;
struct V_127 V_128 ;
V_126 = F_66 ( V_31 , V_117 ) ;
if ( ! V_126 )
return - 1 ;
F_67 ( V_117 , & V_128 ) ;
V_35 = F_68 ( V_126 , V_118 ) ;
F_69 ( & V_128 ) ;
if ( V_35 >= 0 ) {
F_70 ( L_20 , V_35 , V_118 ) ;
if ( F_71 ( V_126 ) < 0 )
V_35 = - 1 ;
}
F_72 ( V_126 ) ;
return V_35 ;
}
static char * F_73 ( const char * V_31 ,
struct V_116 * V_117 )
{
char * V_118 = NULL ;
char * V_129 ;
struct V_127 V_128 ;
T_4 V_25 = 0 ;
V_129 = calloc ( 1 , V_33 ) ;
if ( ! V_129 )
goto V_52;
V_25 = F_74 ( V_129 , V_33 ,
L_21 ) ;
snprintf ( V_129 + V_25 , V_33 - V_25 , L_22 , V_31 ,
V_31 + 2 ) ;
F_67 ( V_117 , & V_128 ) ;
V_118 = F_75 ( V_129 , NULL ) ;
if ( V_118 && F_18 ( V_118 , V_130 ) )
F_59 ( & V_118 ) ;
F_69 ( & V_128 ) ;
V_52:
free ( V_129 ) ;
return V_118 ;
}
int F_76 ( const char * V_31 , const char * V_61 ,
struct V_116 * V_117 , bool V_56 , bool V_57 )
{
const T_4 V_39 = V_33 ;
char * V_118 = NULL , * V_119 = NULL , * V_122 = NULL ,
* V_48 = F_77 ( V_39 ) , * V_47 ;
char * V_129 = NULL ;
int V_66 = - 1 ;
if ( ! V_56 ) {
if ( ! V_57 )
V_118 = F_63 ( V_61 , V_117 ) ;
else
V_118 = F_75 ( V_61 , NULL ) ;
if ( ! V_118 )
goto V_112;
}
V_122 = F_62 ( V_31 , V_61 , V_117 , V_56 ,
V_57 ) ;
if ( ! V_122 )
goto V_112;
if ( F_28 ( V_122 ) )
if ( F_78 ( V_122 ) )
goto V_112;
if ( F_79 ( V_122 , 0755 ) )
goto V_112;
if ( F_52 ( & V_119 , L_15 , V_122 ,
F_24 ( V_56 , V_57 ,
false ) ) < 0 ) {
V_119 = NULL ;
goto V_112;
}
if ( F_18 ( V_119 , V_46 ) ) {
if ( V_56 ) {
if ( F_80 ( L_23 , V_119 ) )
goto V_112;
} else if ( V_117 && V_117 -> V_131 ) {
if ( F_81 ( V_61 , V_119 , V_117 ) )
goto V_112;
} else if ( F_82 ( V_118 , V_119 ) && V_108 != V_132 &&
F_80 ( V_61 , V_119 ) )
goto V_112;
}
if ( ! V_56 && ! V_57 &&
strncmp ( L_24 , V_61 + strlen ( V_61 ) - 3 , 3 ) ) {
V_129 = F_73 ( V_31 , V_117 ) ;
if ( V_129 ) {
F_59 ( & V_119 ) ;
if ( F_52 ( & V_119 , L_15 , V_122 ,
F_24 ( false , false , true ) ) < 0 ) {
V_119 = NULL ;
goto V_112;
}
if ( F_18 ( V_119 , V_46 ) ) {
if ( V_117 && V_117 -> V_131 ) {
if ( F_81 ( V_129 , V_119 ,
V_117 ) )
goto V_112;
} else if ( F_82 ( V_129 , V_119 ) &&
V_108 != V_132 &&
F_80 ( V_129 , V_119 ) )
goto V_112;
}
}
}
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_112;
V_47 = strrchr ( V_48 , '/' ) ;
* V_47 = '\0' ;
if ( F_18 ( V_48 , V_133 ) && F_79 ( V_48 , 0755 ) )
goto V_112;
* V_47 = '/' ;
V_47 = V_122 + strlen ( V_43 ) - 5 ;
memcpy ( V_47 , L_25 , 5 ) ;
if ( F_83 ( V_47 , V_48 ) == 0 )
V_66 = 0 ;
if ( V_118 &&
F_65 ( V_31 , V_118 , V_117 ) < 0 )
F_70 ( L_26 , V_118 ) ;
V_112:
if ( ! V_56 )
free ( V_118 ) ;
free ( V_119 ) ;
free ( V_129 ) ;
free ( V_122 ) ;
free ( V_48 ) ;
return V_66 ;
}
static int F_84 ( const T_3 * V_24 , T_4 V_134 ,
const char * V_61 , struct V_116 * V_117 ,
bool V_56 , bool V_57 )
{
char V_31 [ V_54 ] ;
F_9 ( V_24 , V_134 , V_31 ) ;
return F_76 ( V_31 , V_61 , V_117 , V_56 ,
V_57 ) ;
}
bool F_85 ( const char * V_31 )
{
bool V_35 = false ;
char * V_119 = F_19 ( V_31 , NULL , 0 ) ;
if ( V_119 && ! F_18 ( V_119 , V_46 ) )
V_35 = true ;
free ( V_119 ) ;
return V_35 ;
}
int F_86 ( const char * V_31 )
{
const T_4 V_39 = V_33 ;
char * V_119 = F_77 ( V_39 ) ,
* V_48 = F_77 ( V_39 ) , * V_47 ;
int V_66 = - 1 ;
if ( V_119 == NULL || V_48 == NULL )
goto V_112;
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_112;
if ( F_18 ( V_48 , V_46 ) )
goto V_112;
if ( F_21 ( V_48 , V_119 , V_39 - 1 ) < 0 )
goto V_112;
if ( F_78 ( V_48 ) )
goto V_112;
V_47 = strrchr ( V_48 , '/' ) + 1 ;
snprintf ( V_47 , V_39 - ( V_47 - V_48 ) , L_14 , V_119 ) ;
if ( F_87 ( V_48 ) )
goto V_112;
V_66 = 0 ;
V_112:
free ( V_119 ) ;
free ( V_48 ) ;
return V_66 ;
}
static int F_88 ( struct V_19 * V_19 , struct V_8 * V_8 )
{
bool V_56 = F_26 ( V_19 ) ;
bool V_57 = F_27 ( V_19 ) ;
const char * V_61 = V_19 -> V_81 ;
char V_70 [ V_33 ] ;
if ( F_36 ( V_19 ) ) {
V_56 = true ;
F_37 ( V_8 , V_70 , sizeof( V_70 ) ) ;
V_61 = V_70 ;
}
return F_84 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_61 ,
V_19 -> V_116 , V_56 , V_57 ) ;
}
static int F_89 ( struct V_92 * V_93 ,
struct V_8 * V_8 )
{
struct V_19 * V_71 ;
int V_66 = 0 ;
F_35 (pos, head)
if ( F_88 ( V_71 , V_8 ) )
V_66 = - 1 ;
return V_66 ;
}
static int F_90 ( struct V_8 * V_8 )
{
return F_89 ( & V_8 -> V_94 . V_93 , V_8 ) ;
}
int F_91 ( struct V_85 * V_86 )
{
struct V_87 * V_88 ;
int V_35 ;
if ( V_95 )
return 0 ;
if ( F_92 ( V_43 , 0755 ) != 0 && V_108 != V_132 )
return - 1 ;
V_35 = F_90 ( & V_86 -> V_89 . V_90 ) ;
for ( V_88 = F_40 ( & V_86 -> V_89 . V_91 ) ; V_88 ; V_88 = F_41 ( V_88 ) ) {
struct V_8 * V_71 = F_42 ( V_88 , struct V_8 , V_87 ) ;
V_35 |= F_90 ( V_71 ) ;
}
return V_35 ? - 1 : 0 ;
}
static bool F_93 ( struct V_8 * V_8 , bool V_135 )
{
return F_94 ( & V_8 -> V_94 . V_93 , V_135 ) ;
}
bool F_95 ( struct V_85 * V_86 , bool V_135 )
{
struct V_87 * V_88 ;
bool V_35 = F_93 ( & V_86 -> V_89 . V_90 , V_135 ) ;
for ( V_88 = F_40 ( & V_86 -> V_89 . V_91 ) ; V_88 ; V_88 = F_41 ( V_88 ) ) {
struct V_8 * V_71 = F_42 ( V_88 , struct V_8 , V_87 ) ;
V_35 |= F_93 ( V_71 , V_135 ) ;
}
return V_35 ;
}
