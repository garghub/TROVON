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
V_48 = F_19 ( V_31 , NULL , 0 ) ;
if ( ! V_48 )
return NULL ;
if ( F_21 ( V_48 , V_49 , V_33 ) < 0 )
goto V_52;
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
static const char * F_24 ( bool V_56 , bool V_57 )
{
return V_56 ? L_10 : ( V_57 ? L_11 : L_12 ) ;
}
char * F_25 ( const struct V_19 * V_19 , char * V_26 , T_4 V_39 )
{
bool V_56 = F_26 ( (struct V_19 * ) V_19 ) ;
bool V_57 = F_27 ( (struct V_19 * ) V_19 ) ;
char V_31 [ V_54 ] ;
char * V_48 ;
bool V_58 = ( V_26 == NULL ) ;
int V_35 ;
if ( ! V_19 -> V_59 )
return NULL ;
F_9 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_31 ) ;
V_48 = F_19 ( V_31 , NULL , 0 ) ;
if ( ! V_48 )
return NULL ;
if ( F_28 ( V_48 ) )
V_35 = F_15 ( & V_26 , V_39 , L_13 , V_48 ) ;
else
V_35 = F_15 ( & V_26 , V_39 , L_14 , V_48 ,
F_24 ( V_56 , V_57 ) ) ;
if ( V_35 < 0 || ( ! V_58 && V_39 < ( unsigned int ) V_35 ) )
V_26 = NULL ;
free ( V_48 ) ;
return V_26 ;
}
bool F_29 ( const struct V_19 * V_19 , char * V_26 , T_4 V_39 )
{
char * V_60 = NULL , * V_61 ;
struct V_62 V_63 ;
char V_31 [ V_54 ] ;
if ( ! V_19 -> V_59 )
goto V_64;
F_9 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_31 ) ;
V_60 = F_19 ( V_31 , NULL , 0 ) ;
if ( ! V_60 )
goto V_64;
if ( F_18 ( V_60 , V_46 ) )
goto V_64;
if ( F_30 ( V_60 , & V_63 ) == - 1 )
goto V_64;
if ( ( T_4 ) V_63 . V_65 > V_39 - 1 )
goto V_64;
if ( F_21 ( V_60 , V_26 , V_39 - 1 ) < 0 )
goto V_64;
V_26 [ V_63 . V_65 ] = '\0' ;
V_61 = strrchr ( V_26 , '/' ) ;
if ( ! V_61 )
goto V_64;
if ( V_61 - 3 < V_26 )
goto V_64;
free ( V_60 ) ;
return strncmp ( L_15 , V_61 - 3 , 3 ) == 0 ;
V_64:
F_3 ( L_16 , V_60 ? :
V_19 -> V_66 ? :
V_19 -> V_67 ? :
L_17 ) ;
free ( V_60 ) ;
return false ;
}
static int F_31 ( const char * V_68 , T_4 V_69 , T_3 * V_24 ,
T_6 V_12 , T_7 V_70 , int V_71 )
{
int V_64 ;
struct V_72 V_73 ;
T_4 V_25 ;
V_25 = V_69 + 1 ;
V_25 = F_32 ( V_25 , V_74 ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
memcpy ( & V_73 . V_24 , V_24 , V_34 ) ;
V_73 . V_12 = V_12 ;
V_73 . V_14 . V_70 = V_70 ;
V_73 . V_14 . V_39 = sizeof( V_73 ) + V_25 ;
V_64 = F_33 ( V_71 , & V_73 , sizeof( V_73 ) ) ;
if ( V_64 < 0 )
return V_64 ;
return F_34 ( V_71 , V_68 , V_69 + 1 , V_25 ) ;
}
static int F_35 ( struct V_8 * V_8 , int V_71 )
{
int V_64 = 0 ;
char V_75 [ V_33 ] ;
struct V_19 * V_76 ;
T_7 V_77 = V_78 ,
V_79 = V_80 ;
if ( ! F_36 ( V_8 ) ) {
V_77 = V_81 ;
V_79 = V_82 ;
}
F_37 (pos, &machine->dsos.head) {
const char * V_68 ;
T_4 V_69 ;
bool V_83 = false ;
if ( ! V_76 -> V_20 && ! F_27 ( V_76 ) )
continue;
if ( F_27 ( V_76 ) ) {
V_68 = V_76 -> V_67 ;
V_69 = V_76 -> V_84 ;
} else if ( F_38 ( V_76 ) ) {
F_39 ( V_8 , V_75 , sizeof( V_75 ) ) ;
V_68 = V_75 ;
V_69 = strlen ( V_75 ) ;
} else {
V_68 = V_76 -> V_66 ;
V_69 = V_76 -> V_85 ;
}
V_83 = V_76 -> V_86 ||
F_40 ( V_68 ,
V_87 ) ;
V_64 = F_31 ( V_68 , V_69 , V_76 -> V_24 , V_8 -> V_12 ,
V_83 ? V_77 : V_79 , V_71 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
int F_41 ( struct V_88 * V_89 , int V_71 )
{
struct V_90 * V_91 ;
int V_64 = F_35 ( & V_89 -> V_92 . V_93 , V_71 ) ;
if ( V_64 )
return V_64 ;
for ( V_91 = F_42 ( & V_89 -> V_92 . V_94 ) ; V_91 ; V_91 = F_43 ( V_91 ) ) {
struct V_8 * V_76 = F_44 ( V_91 , struct V_8 , V_90 ) ;
V_64 = F_35 ( V_76 , V_71 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
static int F_45 ( struct V_95 * V_96 )
{
struct V_19 * V_76 ;
F_46 (pos, head, node)
V_76 -> V_20 = true ;
return 0 ;
}
static int F_47 ( struct V_8 * V_8 )
{
return F_45 ( & V_8 -> V_97 . V_96 ) ;
}
int F_48 ( struct V_88 * V_89 )
{
struct V_90 * V_91 ;
int V_64 ;
V_64 = F_47 ( & V_89 -> V_92 . V_93 ) ;
if ( V_64 )
return V_64 ;
for ( V_91 = F_42 ( & V_89 -> V_92 . V_94 ) ; V_91 ; V_91 = F_43 ( V_91 ) ) {
struct V_8 * V_76 = F_44 ( V_91 , struct V_8 , V_90 ) ;
V_64 = F_47 ( V_76 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
void F_49 ( void )
{
V_98 = true ;
}
static bool F_50 ( const char * V_68 V_2 ,
struct V_99 * T_8 V_2 )
{
return ( strlen ( T_8 -> V_100 ) == 2 ) &&
isxdigit ( T_8 -> V_100 [ 0 ] ) && isxdigit ( T_8 -> V_100 [ 1 ] ) ;
}
static bool F_51 ( const char * V_68 V_2 ,
struct V_99 * T_8 V_2 )
{
int V_29 = 0 ;
while ( isxdigit ( T_8 -> V_100 [ V_29 ] ) && V_29 < V_54 - 3 )
V_29 ++ ;
return ( V_29 == V_54 - 3 ) && ( T_8 -> V_100 [ V_29 ] == '\0' ) ;
}
struct V_101 * F_52 ( bool V_102 )
{
struct V_101 * V_103 , * V_104 = NULL , * V_105 ;
struct V_106 * V_91 , * V_107 ;
char * V_108 , * V_109 = NULL ;
char V_31 [ V_54 ] ;
if ( V_102 )
F_53 ( NULL ) ;
if ( F_54 ( & V_108 , L_18 , V_43 ) < 0 )
return NULL ;
V_105 = F_55 ( NULL , NULL ) ;
if ( ! V_105 )
goto V_52;
V_103 = F_56 ( V_108 , F_50 ) ;
if ( ! V_103 ) {
F_57 ( L_19 , V_108 , V_110 ) ;
if ( V_110 == V_111 )
goto V_52;
goto V_112;
}
F_58 (nd, toplist) {
if ( F_54 ( & V_109 , L_14 , V_108 , V_91 -> V_113 ) < 0 )
goto V_112;
V_104 = F_56 ( V_109 , F_51 ) ;
if ( ! V_104 ) {
F_57 ( L_19 , V_109 , V_110 ) ;
goto V_112;
}
F_58 (nd2, linklist) {
if ( snprintf ( V_31 , V_54 , L_20 ,
V_91 -> V_113 , V_107 -> V_113 ) != V_54 - 1 )
goto V_112;
if ( V_102 && ! F_23 ( V_31 ) )
continue;
if ( F_59 ( V_105 , V_31 ) < 0 )
goto V_112;
}
F_60 ( V_104 ) ;
F_61 ( & V_109 ) ;
}
V_114:
F_60 ( V_103 ) ;
V_52:
free ( V_108 ) ;
return V_105 ;
V_112:
F_60 ( V_104 ) ;
F_61 ( & V_109 ) ;
F_60 ( V_105 ) ;
V_105 = NULL ;
goto V_114;
}
static bool F_62 ( const char * V_115 , T_4 V_25 )
{
T_4 V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
if ( ! isxdigit ( V_115 [ V_29 ] ) )
return false ;
}
return true ;
}
char * F_63 ( const char * V_116 )
{
struct V_101 * V_105 ;
struct V_106 * V_91 , * V_117 = NULL ;
char * V_31 = NULL ;
T_4 V_25 = strlen ( V_116 ) ;
if ( V_25 >= V_54 ||
! F_62 ( V_116 , V_25 ) )
return NULL ;
V_105 = F_52 ( true ) ;
if ( ! V_105 )
return NULL ;
F_58 (nd, bidlist) {
if ( strncmp ( V_91 -> V_113 , V_116 , V_25 ) != 0 )
continue;
if ( V_117 ) {
V_117 = NULL ;
break;
}
V_117 = V_91 ;
}
if ( V_117 )
V_31 = F_22 ( V_117 -> V_113 ) ;
F_60 ( V_105 ) ;
return V_31 ;
}
char * F_64 ( const char * V_31 , const char * V_68 ,
bool V_56 , bool V_57 )
{
char * V_118 = ( char * ) V_68 , * V_119 ;
bool V_120 = V_56 || V_57 ;
if ( ! V_120 ) {
V_118 = F_65 ( V_68 , NULL ) ;
if ( ! V_118 )
return NULL ;
}
if ( F_54 ( & V_119 , L_21 , V_43 , V_120 ? L_9 : L_4 ,
V_57 ? V_121 : V_118 ,
V_31 ? L_9 : L_4 , V_31 ? : L_4 ) < 0 )
V_119 = NULL ;
if ( ! V_120 )
free ( V_118 ) ;
return V_119 ;
}
int F_66 ( const char * V_36 ,
struct V_101 * * V_55 )
{
char * V_122 ;
int V_35 = 0 ;
V_122 = F_64 ( NULL , V_36 , false , false ) ;
if ( ! V_122 )
return - V_123 ;
* V_55 = F_56 ( V_122 , V_124 ) ;
if ( ! * V_55 )
V_35 = - V_110 ;
free ( V_122 ) ;
return V_35 ;
}
static int F_67 ( const char * V_31 ,
const char * V_118 )
{
struct V_125 * V_126 ;
int V_35 ;
V_126 = F_68 ( V_31 ) ;
if ( ! V_126 )
return - 1 ;
V_35 = F_69 ( V_126 , V_118 ) ;
if ( V_35 >= 0 ) {
F_57 ( L_22 , V_35 , V_118 ) ;
if ( F_70 ( V_126 ) < 0 )
V_35 = - 1 ;
}
F_71 ( V_126 ) ;
return V_35 ;
}
int F_72 ( const char * V_31 , const char * V_68 ,
bool V_56 , bool V_57 )
{
const T_4 V_39 = V_33 ;
char * V_118 = NULL , * V_119 = NULL , * V_122 = NULL ,
* V_48 = F_73 ( V_39 ) , * V_47 ;
int V_64 = - 1 ;
if ( ! V_56 ) {
V_118 = F_65 ( V_68 , NULL ) ;
if ( ! V_118 )
goto V_114;
}
V_122 = F_64 ( V_31 , V_68 ,
V_56 , V_57 ) ;
if ( ! V_122 )
goto V_114;
if ( F_28 ( V_122 ) )
if ( F_74 ( V_122 ) )
goto V_114;
if ( F_75 ( V_122 , 0755 ) )
goto V_114;
if ( F_54 ( & V_119 , L_14 , V_122 ,
F_24 ( V_56 , V_57 ) ) < 0 ) {
V_119 = NULL ;
goto V_114;
}
if ( F_18 ( V_119 , V_46 ) ) {
if ( V_56 ) {
if ( F_76 ( L_23 , V_119 ) )
goto V_114;
} else if ( F_77 ( V_118 , V_119 ) && V_110 != V_127 &&
F_76 ( V_68 , V_119 ) )
goto V_114;
}
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_114;
V_47 = strrchr ( V_48 , '/' ) ;
* V_47 = '\0' ;
if ( F_18 ( V_48 , V_128 ) && F_75 ( V_48 , 0755 ) )
goto V_114;
* V_47 = '/' ;
V_47 = V_122 + strlen ( V_43 ) - 5 ;
memcpy ( V_47 , L_24 , 5 ) ;
if ( F_78 ( V_47 , V_48 ) == 0 )
V_64 = 0 ;
if ( F_67 ( V_31 , V_118 ) < 0 )
F_57 ( L_25 , V_118 ) ;
V_114:
if ( ! V_56 )
free ( V_118 ) ;
free ( V_119 ) ;
free ( V_122 ) ;
free ( V_48 ) ;
return V_64 ;
}
static int F_79 ( const T_3 * V_24 , T_4 V_129 ,
const char * V_68 , bool V_56 ,
bool V_57 )
{
char V_31 [ V_54 ] ;
F_9 ( V_24 , V_129 , V_31 ) ;
return F_72 ( V_31 , V_68 , V_56 , V_57 ) ;
}
bool F_80 ( const char * V_31 )
{
bool V_35 = false ;
char * V_119 = F_19 ( V_31 , NULL , 0 ) ;
if ( V_119 && ! F_18 ( V_119 , V_46 ) )
V_35 = true ;
free ( V_119 ) ;
return V_35 ;
}
int F_81 ( const char * V_31 )
{
const T_4 V_39 = V_33 ;
char * V_119 = F_73 ( V_39 ) ,
* V_48 = F_73 ( V_39 ) , * V_47 ;
int V_64 = - 1 ;
if ( V_119 == NULL || V_48 == NULL )
goto V_114;
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_114;
if ( F_18 ( V_48 , V_46 ) )
goto V_114;
if ( F_21 ( V_48 , V_119 , V_39 - 1 ) < 0 )
goto V_114;
if ( F_74 ( V_48 ) )
goto V_114;
V_47 = strrchr ( V_48 , '/' ) + 1 ;
snprintf ( V_47 , V_39 - ( V_47 - V_48 ) , L_13 , V_119 ) ;
if ( F_82 ( V_48 ) )
goto V_114;
V_64 = 0 ;
V_114:
free ( V_119 ) ;
free ( V_48 ) ;
return V_64 ;
}
static int F_83 ( struct V_19 * V_19 , struct V_8 * V_8 )
{
bool V_56 = F_26 ( V_19 ) ;
bool V_57 = F_27 ( V_19 ) ;
const char * V_68 = V_19 -> V_66 ;
char V_75 [ V_33 ] ;
if ( F_38 ( V_19 ) ) {
V_56 = true ;
F_39 ( V_8 , V_75 , sizeof( V_75 ) ) ;
V_68 = V_75 ;
}
return F_79 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_68 ,
V_56 , V_57 ) ;
}
static int F_84 ( struct V_95 * V_96 ,
struct V_8 * V_8 )
{
struct V_19 * V_76 ;
int V_64 = 0 ;
F_37 (pos, head)
if ( F_83 ( V_76 , V_8 ) )
V_64 = - 1 ;
return V_64 ;
}
static int F_85 ( struct V_8 * V_8 )
{
return F_84 ( & V_8 -> V_97 . V_96 , V_8 ) ;
}
int F_86 ( struct V_88 * V_89 )
{
struct V_90 * V_91 ;
int V_35 ;
if ( V_98 )
return 0 ;
if ( F_87 ( V_43 , 0755 ) != 0 && V_110 != V_127 )
return - 1 ;
V_35 = F_85 ( & V_89 -> V_92 . V_93 ) ;
for ( V_91 = F_42 ( & V_89 -> V_92 . V_94 ) ; V_91 ; V_91 = F_43 ( V_91 ) ) {
struct V_8 * V_76 = F_44 ( V_91 , struct V_8 , V_90 ) ;
V_35 |= F_85 ( V_76 ) ;
}
return V_35 ? - 1 : 0 ;
}
static bool F_88 ( struct V_8 * V_8 , bool V_130 )
{
return F_89 ( & V_8 -> V_97 . V_96 , V_130 ) ;
}
bool F_90 ( struct V_88 * V_89 , bool V_130 )
{
struct V_90 * V_91 ;
bool V_35 = F_88 ( & V_89 -> V_92 . V_93 , V_130 ) ;
for ( V_91 = F_42 ( & V_89 -> V_92 . V_94 ) ; V_91 ; V_91 = F_43 ( V_91 ) ) {
struct V_8 * V_76 = F_44 ( V_91 , struct V_8 , V_90 ) ;
V_35 |= F_88 ( V_76 , V_130 ) ;
}
return V_35 ;
}
