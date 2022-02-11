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
static int F_29 ( const char * V_60 , T_4 V_61 , T_3 * V_24 ,
T_7 V_12 , T_8 V_62 , int V_63 )
{
int V_64 ;
struct V_65 V_66 ;
T_4 V_25 ;
V_25 = V_61 + 1 ;
V_25 = F_30 ( V_25 , V_67 ) ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memcpy ( & V_66 . V_24 , V_24 , V_34 ) ;
V_66 . V_12 = V_12 ;
V_66 . V_14 . V_62 = V_62 ;
V_66 . V_14 . V_39 = sizeof( V_66 ) + V_25 ;
V_64 = F_31 ( V_63 , & V_66 , sizeof( V_66 ) ) ;
if ( V_64 < 0 )
return V_64 ;
return F_32 ( V_63 , V_60 , V_61 + 1 , V_25 ) ;
}
static int F_33 ( struct V_8 * V_8 , int V_63 )
{
int V_64 = 0 ;
char V_68 [ V_33 ] ;
struct V_19 * V_69 ;
T_8 V_70 = V_71 ,
V_72 = V_73 ;
if ( ! F_34 ( V_8 ) ) {
V_70 = V_74 ;
V_72 = V_75 ;
}
F_35 (pos, &machine->dsos.head) {
const char * V_60 ;
T_4 V_61 ;
bool V_76 = false ;
if ( ! V_69 -> V_20 && ! F_27 ( V_69 ) )
continue;
if ( F_27 ( V_69 ) ) {
V_60 = V_69 -> V_77 ;
V_61 = V_69 -> V_78 ;
} else if ( F_36 ( V_69 ) ) {
F_37 ( V_8 , V_68 , sizeof( V_68 ) ) ;
V_60 = V_68 ;
V_61 = strlen ( V_68 ) ;
} else {
V_60 = V_69 -> V_79 ;
V_61 = V_69 -> V_80 ;
}
V_76 = V_69 -> V_81 ||
F_38 ( V_60 ,
V_82 ) ;
V_64 = F_29 ( V_60 , V_61 , V_69 -> V_24 , V_8 -> V_12 ,
V_76 ? V_70 : V_72 , V_63 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
int F_39 ( struct V_83 * V_84 , int V_63 )
{
struct V_85 * V_86 ;
int V_64 = F_33 ( & V_84 -> V_87 . V_88 , V_63 ) ;
if ( V_64 )
return V_64 ;
for ( V_86 = F_40 ( & V_84 -> V_87 . V_89 ) ; V_86 ; V_86 = F_41 ( V_86 ) ) {
struct V_8 * V_69 = F_42 ( V_86 , struct V_8 , V_85 ) ;
V_64 = F_33 ( V_69 , V_63 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
static int F_43 ( struct V_90 * V_91 )
{
struct V_19 * V_69 ;
F_44 (pos, head, node)
V_69 -> V_20 = true ;
return 0 ;
}
static int F_45 ( struct V_8 * V_8 )
{
return F_43 ( & V_8 -> V_92 . V_91 ) ;
}
int F_46 ( struct V_83 * V_84 )
{
struct V_85 * V_86 ;
int V_64 ;
V_64 = F_45 ( & V_84 -> V_87 . V_88 ) ;
if ( V_64 )
return V_64 ;
for ( V_86 = F_40 ( & V_84 -> V_87 . V_89 ) ; V_86 ; V_86 = F_41 ( V_86 ) ) {
struct V_8 * V_69 = F_42 ( V_86 , struct V_8 , V_85 ) ;
V_64 = F_45 ( V_69 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
void F_47 ( void )
{
V_93 = true ;
}
static bool F_48 ( const char * V_60 V_2 ,
struct V_94 * V_95 )
{
return ( strlen ( V_95 -> V_96 ) == 2 ) &&
isxdigit ( V_95 -> V_96 [ 0 ] ) && isxdigit ( V_95 -> V_96 [ 1 ] ) ;
}
static bool F_49 ( const char * V_60 V_2 ,
struct V_94 * V_95 )
{
int V_29 = 0 ;
while ( isxdigit ( V_95 -> V_96 [ V_29 ] ) && V_29 < V_54 - 3 )
V_29 ++ ;
return ( V_29 == V_54 - 3 ) && ( V_95 -> V_96 [ V_29 ] == '\0' ) ;
}
struct V_97 * F_50 ( bool V_98 )
{
struct V_97 * V_99 , * V_100 = NULL , * V_101 ;
struct V_102 * V_86 , * V_103 ;
char * V_104 , * V_105 = NULL ;
char V_31 [ V_54 ] ;
if ( V_98 )
F_51 ( NULL ) ;
if ( F_52 ( & V_104 , L_15 , V_43 ) < 0 )
return NULL ;
V_101 = F_53 ( NULL , NULL ) ;
if ( ! V_101 )
goto V_52;
V_99 = F_54 ( V_104 , F_48 ) ;
if ( ! V_99 ) {
F_55 ( L_16 , V_104 , V_106 ) ;
if ( V_106 == V_107 )
goto V_52;
goto V_108;
}
F_56 (nd, toplist) {
if ( F_52 ( & V_105 , L_14 , V_104 , V_86 -> V_109 ) < 0 )
goto V_108;
V_100 = F_54 ( V_105 , F_49 ) ;
if ( ! V_100 ) {
F_55 ( L_16 , V_105 , V_106 ) ;
goto V_108;
}
F_56 (nd2, linklist) {
if ( snprintf ( V_31 , V_54 , L_17 ,
V_86 -> V_109 , V_103 -> V_109 ) != V_54 - 1 )
goto V_108;
if ( V_98 && ! F_23 ( V_31 ) )
continue;
if ( F_57 ( V_101 , V_31 ) < 0 )
goto V_108;
}
F_58 ( V_100 ) ;
F_59 ( & V_105 ) ;
}
V_110:
F_58 ( V_99 ) ;
V_52:
free ( V_104 ) ;
return V_101 ;
V_108:
F_58 ( V_100 ) ;
F_59 ( & V_105 ) ;
F_58 ( V_101 ) ;
V_101 = NULL ;
goto V_110;
}
static bool F_60 ( const char * V_111 , T_4 V_25 )
{
T_4 V_29 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
if ( ! isxdigit ( V_111 [ V_29 ] ) )
return false ;
}
return true ;
}
char * F_61 ( const char * V_112 )
{
struct V_97 * V_101 ;
struct V_102 * V_86 , * V_113 = NULL ;
char * V_31 = NULL ;
T_4 V_25 = strlen ( V_112 ) ;
if ( V_25 >= V_54 ||
! F_60 ( V_112 , V_25 ) )
return NULL ;
V_101 = F_50 ( true ) ;
if ( ! V_101 )
return NULL ;
F_56 (nd, bidlist) {
if ( strncmp ( V_86 -> V_109 , V_112 , V_25 ) != 0 )
continue;
if ( V_113 ) {
V_113 = NULL ;
break;
}
V_113 = V_86 ;
}
if ( V_113 )
V_31 = F_22 ( V_113 -> V_109 ) ;
F_58 ( V_101 ) ;
return V_31 ;
}
char * F_62 ( const char * V_31 , const char * V_60 ,
bool V_56 , bool V_57 )
{
char * V_114 = ( char * ) V_60 , * V_115 ;
bool V_116 = V_56 || V_57 ;
if ( ! V_116 ) {
V_114 = F_63 ( V_60 , NULL ) ;
if ( ! V_114 )
return NULL ;
}
if ( F_52 ( & V_115 , L_18 , V_43 , V_116 ? L_9 : L_4 ,
V_57 ? V_117 : V_114 ,
V_31 ? L_9 : L_4 , V_31 ? : L_4 ) < 0 )
V_115 = NULL ;
if ( ! V_116 )
free ( V_114 ) ;
return V_115 ;
}
int F_64 ( const char * V_36 ,
struct V_97 * * V_55 )
{
char * V_118 ;
int V_35 = 0 ;
V_118 = F_62 ( NULL , V_36 , false , false ) ;
if ( ! V_118 )
return - V_119 ;
* V_55 = F_54 ( V_118 , V_120 ) ;
if ( ! * V_55 )
V_35 = - V_106 ;
free ( V_118 ) ;
return V_35 ;
}
static int F_65 ( const char * V_31 ,
const char * V_114 )
{
struct V_121 * V_122 ;
int V_35 ;
V_122 = F_66 ( V_31 ) ;
if ( ! V_122 )
return - 1 ;
V_35 = F_67 ( V_122 , V_114 ) ;
if ( V_35 >= 0 ) {
F_68 ( L_19 , V_35 , V_114 ) ;
if ( F_69 ( V_122 ) < 0 )
V_35 = - 1 ;
}
F_70 ( V_122 ) ;
return V_35 ;
}
int F_71 ( const char * V_31 , const char * V_60 ,
bool V_56 , bool V_57 )
{
const T_4 V_39 = V_33 ;
char * V_114 = NULL , * V_115 = NULL , * V_118 = NULL ,
* V_48 = F_72 ( V_39 ) , * V_47 ;
int V_64 = - 1 ;
if ( ! V_56 ) {
V_114 = F_63 ( V_60 , NULL ) ;
if ( ! V_114 )
goto V_110;
}
V_118 = F_62 ( V_31 , V_60 ,
V_56 , V_57 ) ;
if ( ! V_118 )
goto V_110;
if ( F_28 ( V_118 ) )
if ( F_73 ( V_118 ) )
goto V_110;
if ( F_74 ( V_118 , 0755 ) )
goto V_110;
if ( F_52 ( & V_115 , L_14 , V_118 ,
F_24 ( V_56 , V_57 ) ) < 0 ) {
V_115 = NULL ;
goto V_110;
}
if ( F_18 ( V_115 , V_46 ) ) {
if ( V_56 ) {
if ( F_75 ( L_20 , V_115 ) )
goto V_110;
} else if ( F_76 ( V_114 , V_115 ) && V_106 != V_123 &&
F_75 ( V_60 , V_115 ) )
goto V_110;
}
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_110;
V_47 = strrchr ( V_48 , '/' ) ;
* V_47 = '\0' ;
if ( F_18 ( V_48 , V_124 ) && F_74 ( V_48 , 0755 ) )
goto V_110;
* V_47 = '/' ;
V_47 = V_118 + strlen ( V_43 ) - 5 ;
memcpy ( V_47 , L_21 , 5 ) ;
if ( F_77 ( V_47 , V_48 ) == 0 )
V_64 = 0 ;
if ( V_114 && F_65 ( V_31 , V_114 ) < 0 )
F_68 ( L_22 , V_114 ) ;
V_110:
if ( ! V_56 )
free ( V_114 ) ;
free ( V_115 ) ;
free ( V_118 ) ;
free ( V_48 ) ;
return V_64 ;
}
static int F_78 ( const T_3 * V_24 , T_4 V_125 ,
const char * V_60 , bool V_56 ,
bool V_57 )
{
char V_31 [ V_54 ] ;
F_9 ( V_24 , V_125 , V_31 ) ;
return F_71 ( V_31 , V_60 , V_56 , V_57 ) ;
}
bool F_79 ( const char * V_31 )
{
bool V_35 = false ;
char * V_115 = F_19 ( V_31 , NULL , 0 ) ;
if ( V_115 && ! F_18 ( V_115 , V_46 ) )
V_35 = true ;
free ( V_115 ) ;
return V_35 ;
}
int F_80 ( const char * V_31 )
{
const T_4 V_39 = V_33 ;
char * V_115 = F_72 ( V_39 ) ,
* V_48 = F_72 ( V_39 ) , * V_47 ;
int V_64 = - 1 ;
if ( V_115 == NULL || V_48 == NULL )
goto V_110;
if ( ! F_19 ( V_31 , V_48 , V_39 ) )
goto V_110;
if ( F_18 ( V_48 , V_46 ) )
goto V_110;
if ( F_21 ( V_48 , V_115 , V_39 - 1 ) < 0 )
goto V_110;
if ( F_73 ( V_48 ) )
goto V_110;
V_47 = strrchr ( V_48 , '/' ) + 1 ;
snprintf ( V_47 , V_39 - ( V_47 - V_48 ) , L_13 , V_115 ) ;
if ( F_81 ( V_48 ) )
goto V_110;
V_64 = 0 ;
V_110:
free ( V_115 ) ;
free ( V_48 ) ;
return V_64 ;
}
static int F_82 ( struct V_19 * V_19 , struct V_8 * V_8 )
{
bool V_56 = F_26 ( V_19 ) ;
bool V_57 = F_27 ( V_19 ) ;
const char * V_60 = V_19 -> V_79 ;
char V_68 [ V_33 ] ;
if ( F_36 ( V_19 ) ) {
V_56 = true ;
F_37 ( V_8 , V_68 , sizeof( V_68 ) ) ;
V_60 = V_68 ;
}
return F_78 ( V_19 -> V_24 , sizeof( V_19 -> V_24 ) , V_60 ,
V_56 , V_57 ) ;
}
static int F_83 ( struct V_90 * V_91 ,
struct V_8 * V_8 )
{
struct V_19 * V_69 ;
int V_64 = 0 ;
F_35 (pos, head)
if ( F_82 ( V_69 , V_8 ) )
V_64 = - 1 ;
return V_64 ;
}
static int F_84 ( struct V_8 * V_8 )
{
return F_83 ( & V_8 -> V_92 . V_91 , V_8 ) ;
}
int F_85 ( struct V_83 * V_84 )
{
struct V_85 * V_86 ;
int V_35 ;
if ( V_93 )
return 0 ;
if ( F_86 ( V_43 , 0755 ) != 0 && V_106 != V_123 )
return - 1 ;
V_35 = F_84 ( & V_84 -> V_87 . V_88 ) ;
for ( V_86 = F_40 ( & V_84 -> V_87 . V_89 ) ; V_86 ; V_86 = F_41 ( V_86 ) ) {
struct V_8 * V_69 = F_42 ( V_86 , struct V_8 , V_85 ) ;
V_35 |= F_84 ( V_69 ) ;
}
return V_35 ? - 1 : 0 ;
}
static bool F_87 ( struct V_8 * V_8 , bool V_126 )
{
return F_88 ( & V_8 -> V_92 . V_91 , V_126 ) ;
}
bool F_89 ( struct V_83 * V_84 , bool V_126 )
{
struct V_85 * V_86 ;
bool V_35 = F_87 ( & V_84 -> V_87 . V_88 , V_126 ) ;
for ( V_86 = F_40 ( & V_84 -> V_87 . V_89 ) ; V_86 ; V_86 = F_41 ( V_86 ) ) {
struct V_8 * V_69 = F_42 ( V_86 , struct V_8 , V_85 ) ;
V_35 |= F_87 ( V_69 , V_126 ) ;
}
return V_35 ;
}
