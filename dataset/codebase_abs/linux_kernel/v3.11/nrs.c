static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 -> V_5 != NULL ?
V_2 -> V_3 -> V_4 -> V_5 ( V_2 ) : 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_6 == 0 ) ;
F_3 ( V_2 -> V_7 == 0 ) ;
if ( V_2 -> V_3 -> V_4 -> V_8 != NULL )
V_2 -> V_3 -> V_4 -> V_8 ( V_2 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_9 V_10 , void * V_11 )
{
if ( V_2 -> V_12 == V_13 )
RETURN ( - V_14 ) ;
RETURN ( V_2 -> V_3 -> V_4 -> V_15 != NULL ?
V_2 -> V_3 -> V_4 -> V_15 ( V_2 , V_10 , V_11 ) :
- V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
V_20 ;
if ( V_2 -> V_3 -> V_4 -> V_21 != NULL ) {
F_6 ( & V_18 -> V_22 ) ;
V_2 -> V_3 -> V_4 -> V_21 ( V_2 ) ;
F_7 ( & V_18 -> V_22 ) ;
}
F_3 ( F_8 ( & V_2 -> V_23 ) ) ;
F_3 ( V_2 -> V_7 == 0 &&
V_2 -> V_24 == 0 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_12 = V_13 ;
if ( F_9 ( & V_2 -> V_3 -> V_26 ) )
F_10 ( V_2 -> V_3 -> V_27 ) ;
EXIT ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
V_20 ;
if ( V_18 -> V_28 == V_2 && ! V_18 -> V_29 )
RETURN ( - V_30 ) ;
if ( V_2 -> V_12 == V_31 )
RETURN ( - V_32 ) ;
if ( V_2 -> V_12 != V_33 )
RETURN ( 0 ) ;
V_2 -> V_12 = V_34 ;
if ( V_18 -> V_35 == V_2 ) {
V_18 -> V_35 = NULL ;
} else {
F_3 ( V_18 -> V_28 == V_2 ) ;
V_18 -> V_28 = NULL ;
}
if ( V_2 -> V_6 == 1 )
F_5 ( V_2 ) ;
RETURN ( 0 ) ;
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_36 = V_18 -> V_35 ;
V_20 ;
if ( V_36 == NULL ) {
EXIT ;
return;
}
V_18 -> V_35 = NULL ;
F_3 ( V_36 -> V_12 == V_33 ) ;
V_36 -> V_12 = V_34 ;
if ( V_36 -> V_6 == 0 )
F_5 ( V_36 ) ;
EXIT ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_37 = 0 ;
V_20 ;
if ( V_18 -> V_38 )
RETURN ( - V_32 ) ;
F_3 ( V_2 -> V_12 != V_31 ) ;
if ( V_2 -> V_12 == V_34 )
RETURN ( - V_32 ) ;
if ( V_2 -> V_39 & V_40 ) {
if ( V_2 == V_18 -> V_28 ) {
F_12 ( V_18 ) ;
RETURN ( 0 ) ;
}
F_3 ( V_18 -> V_28 == NULL ) ;
} else {
if ( V_18 -> V_28 == NULL )
RETURN ( - V_30 ) ;
if ( V_2 -> V_12 == V_33 )
RETURN ( 0 ) ;
}
if ( F_14 ( & V_2 -> V_3 -> V_26 ) == 1 &&
! F_15 ( V_2 -> V_3 -> V_27 ) ) {
F_16 ( & V_2 -> V_3 -> V_26 ) ;
F_17 ( L_1 ,
V_2 -> V_3 -> V_41 ) ;
RETURN ( - V_14 ) ;
}
V_18 -> V_38 = 1 ;
V_2 -> V_12 = V_31 ;
if ( V_2 -> V_3 -> V_4 -> V_42 ) {
F_6 ( & V_18 -> V_22 ) ;
V_37 = V_2 -> V_3 -> V_4 -> V_42 ( V_2 ) ;
F_7 ( & V_18 -> V_22 ) ;
if ( V_37 != 0 ) {
if ( F_9 ( & V_2 -> V_3 -> V_26 ) )
F_10 ( V_2 -> V_3 -> V_27 ) ;
V_2 -> V_12 = V_13 ;
GOTO ( V_43 , V_37 ) ;
}
}
V_2 -> V_12 = V_33 ;
if ( V_2 -> V_39 & V_40 ) {
V_18 -> V_28 = V_2 ;
} else {
F_12 ( V_18 ) ;
V_18 -> V_35 = V_2 ;
}
V_43:
V_18 -> V_38 = 0 ;
RETURN ( V_37 ) ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_6 ++ ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_6 > 0 ) ;
V_2 -> V_6 -- ;
if ( F_20 ( V_2 -> V_6 == 0 &&
V_2 -> V_12 == V_34 ) )
F_5 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_19 -> V_22 ) ;
F_19 ( V_2 ) ;
F_6 ( & V_2 -> V_19 -> V_22 ) ;
}
static struct V_1 * F_22 ( struct V_17 * V_18 ,
char * V_44 )
{
struct V_1 * V_36 ;
F_23 (tmp, &nrs->nrs_policy_list, pol_list) {
if ( strncmp ( V_36 -> V_3 -> V_41 , V_44 ,
V_45 ) == 0 ) {
F_18 ( V_36 ) ;
return V_36 ;
}
}
return NULL ;
}
static void F_24 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
if ( V_2 -> V_3 -> V_4 -> V_49 != NULL ) {
struct V_46 * V_50 ;
for (; V_47 != NULL ; V_47 = V_50 ) {
V_50 = V_47 -> V_51 ;
V_2 -> V_3 -> V_4 -> V_49 ( V_2 , V_47 ) ;
}
}
}
static
struct V_46 * F_25 ( struct V_1 * V_2 ,
struct V_52 * V_53 ,
bool V_54 )
{
struct V_46 * V_47 = NULL ;
struct V_46 * V_36 = NULL ;
int V_37 ;
while ( 1 ) {
V_37 = V_2 -> V_3 -> V_4 -> V_55 ( V_2 , V_53 , V_47 ,
& V_36 , V_54 ) ;
if ( V_37 < 0 ) {
if ( V_47 != NULL )
F_24 ( V_47 ) ;
return NULL ;
}
F_3 ( V_36 != NULL ) ;
V_36 -> V_51 = V_47 ;
V_36 -> V_48 = V_2 ;
V_47 = V_36 ;
V_36 = NULL ;
if ( V_37 > 0 )
return V_47 ;
}
}
static void F_26 ( struct V_17 * V_18 ,
struct V_52 * V_53 ,
struct V_46 * * V_56 ,
bool V_54 )
{
struct V_1 * V_57 = NULL ;
struct V_1 * V_58 = NULL ;
memset ( V_56 , 0 , sizeof( V_56 [ 0 ] ) * V_59 ) ;
F_7 ( & V_18 -> V_22 ) ;
V_58 = V_18 -> V_28 ;
F_18 ( V_58 ) ;
V_57 = V_18 -> V_35 ;
if ( V_57 != NULL )
F_18 ( V_57 ) ;
F_6 ( & V_18 -> V_22 ) ;
V_56 [ V_60 ] = F_25 ( V_58 , V_53 , V_54 ) ;
F_3 ( V_56 [ V_60 ] != NULL ) ;
if ( V_57 != NULL ) {
V_56 [ V_61 ] = F_25 ( V_57 , V_53 ,
V_54 ) ;
if ( V_56 [ V_61 ] == NULL )
F_21 ( V_57 ) ;
}
}
static void F_27 ( struct V_46 * * V_56 )
{
struct V_1 * V_62 [ V_59 ] ;
struct V_17 * V_18 = NULL ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
if ( V_56 [ V_63 ] != NULL ) {
V_62 [ V_63 ] = V_56 [ V_63 ] -> V_48 ;
F_24 ( V_56 [ V_63 ] ) ;
V_56 [ V_63 ] = NULL ;
} else {
V_62 [ V_63 ] = NULL ;
}
}
for ( V_63 = 0 ; V_63 < V_59 ; V_63 ++ ) {
if ( V_62 [ V_63 ] == NULL )
continue;
if ( V_18 == NULL ) {
V_18 = V_62 [ V_63 ] -> V_19 ;
F_7 ( & V_18 -> V_22 ) ;
}
F_19 ( V_62 [ V_63 ] ) ;
}
if ( V_18 != NULL )
F_6 ( & V_18 -> V_22 ) ;
}
static inline
struct V_52 * F_28 ( struct V_1 * V_2 ,
bool V_64 , bool V_65 )
{
struct V_52 * V_53 ;
F_3 ( V_2 -> V_7 > 0 ) ;
V_53 = V_2 -> V_3 -> V_4 -> V_66 ( V_2 , V_64 , V_65 ) ;
F_3 ( F_29 ( V_53 != NULL , F_30 ( V_53 ) == V_2 ) ) ;
return V_53 ;
}
static inline void F_31 ( struct V_52 * V_53 )
{
struct V_1 * V_2 ;
int V_37 ;
int V_63 ;
for ( V_63 = V_59 - 1 ; V_63 >= 0 ; V_63 -- ) {
if ( V_53 -> V_67 [ V_63 ] == NULL )
continue;
V_53 -> V_68 = V_63 ;
V_2 = V_53 -> V_67 [ V_63 ] -> V_48 ;
V_37 = V_2 -> V_3 -> V_4 -> V_69 ( V_2 , V_53 ) ;
if ( V_37 == 0 ) {
V_2 -> V_19 -> V_70 ++ ;
V_2 -> V_7 ++ ;
return;
}
}
F_32 () ;
}
static inline void F_33 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_30 ( V_53 ) ;
if ( V_2 -> V_3 -> V_4 -> V_71 )
V_2 -> V_3 -> V_4 -> V_71 ( V_2 , V_53 ) ;
F_3 ( V_2 -> V_19 -> V_72 > 0 ) ;
F_3 ( V_2 -> V_24 > 0 ) ;
V_2 -> V_19 -> V_72 -- ;
V_2 -> V_24 -- ;
}
static int F_34 ( struct V_17 * V_18 , char * V_44 ,
enum V_9 V_10 , void * V_11 )
{
struct V_1 * V_2 ;
int V_37 = 0 ;
V_20 ;
F_7 ( & V_18 -> V_22 ) ;
V_2 = F_22 ( V_18 , V_44 ) ;
if ( V_2 == NULL )
GOTO ( V_43 , V_37 = - V_73 ) ;
switch ( V_10 ) {
default:
V_37 = F_4 ( V_2 , V_10 , V_11 ) ;
break;
case V_74 :
V_37 = F_13 ( V_2 ) ;
break;
}
V_43:
if ( V_2 != NULL )
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_22 ) ;
RETURN ( V_37 ) ;
}
static int F_35 ( struct V_17 * V_18 , char * V_44 )
{
struct V_1 * V_2 = NULL ;
V_20 ;
F_7 ( & V_18 -> V_22 ) ;
V_2 = F_22 ( V_18 , V_44 ) ;
if ( V_2 == NULL ) {
F_6 ( & V_18 -> V_22 ) ;
F_17 ( L_2 , V_44 ) ;
RETURN ( - V_73 ) ;
}
if ( V_2 -> V_6 > 1 ) {
F_17 ( L_3 , V_44 ,
( int ) V_2 -> V_6 ) ;
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_22 ) ;
RETURN ( - V_75 ) ;
}
F_3 ( V_2 -> V_7 == 0 ) ;
F_3 ( V_2 -> V_24 == 0 ) ;
if ( V_2 -> V_12 != V_13 ) {
F_11 ( V_2 ) ;
F_3 ( V_2 -> V_12 == V_13 ) ;
}
F_36 ( & V_2 -> V_76 ) ;
V_18 -> V_77 -- ;
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_22 ) ;
F_2 ( V_2 ) ;
F_3 ( V_2 -> V_25 == NULL ) ;
F_37 ( V_2 ) ;
RETURN ( 0 ) ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 ;
struct V_1 * V_36 ;
struct V_80 * V_81 = V_18 -> V_82 ;
int V_37 ;
V_20 ;
F_3 ( V_81 != NULL ) ;
F_3 ( V_79 -> V_4 != NULL ) ;
F_3 ( V_79 -> V_4 -> V_55 != NULL ) ;
F_3 ( V_79 -> V_4 -> V_66 != NULL ) ;
F_3 ( V_79 -> V_4 -> V_69 != NULL ) ;
F_3 ( V_79 -> V_4 -> V_83 != NULL ) ;
F_3 ( V_79 -> V_84 != NULL ) ;
F_39 ( V_2 , V_81 -> V_85 -> V_86 ,
V_81 -> V_87 , sizeof( * V_2 ) , V_88 ) ;
if ( V_2 == NULL )
RETURN ( - V_89 ) ;
V_2 -> V_19 = V_18 ;
V_2 -> V_3 = V_79 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_39 = V_79 -> V_90 ;
F_40 ( & V_2 -> V_76 ) ;
F_40 ( & V_2 -> V_23 ) ;
V_37 = F_1 ( V_2 ) ;
if ( V_37 != 0 ) {
F_37 ( V_2 ) ;
RETURN ( V_37 ) ;
}
F_7 ( & V_18 -> V_22 ) ;
V_36 = F_22 ( V_18 , V_2 -> V_3 -> V_41 ) ;
if ( V_36 != NULL ) {
F_17 ( L_4
L_5 , V_2 -> V_3 -> V_41 ,
V_81 -> V_85 -> V_91 ) ;
F_19 ( V_36 ) ;
F_6 ( & V_18 -> V_22 ) ;
F_2 ( V_2 ) ;
F_37 ( V_2 ) ;
RETURN ( - V_92 ) ;
}
F_41 ( & V_2 -> V_76 , & V_18 -> V_93 ) ;
V_18 -> V_77 ++ ;
if ( V_2 -> V_39 & V_94 )
V_37 = F_13 ( V_2 ) ;
F_6 ( & V_18 -> V_22 ) ;
if ( V_37 != 0 )
( void ) F_35 ( V_18 , V_2 -> V_3 -> V_41 ) ;
RETURN ( V_37 ) ;
}
static void F_42 ( struct V_95 * V_96 )
{
struct V_1 * V_2 ;
F_3 ( V_96 -> V_97 . V_98 ) ;
F_3 ( ! V_96 -> V_97 . V_99 ) ;
F_31 ( & V_96 -> V_97 ) ;
V_96 -> V_97 . V_99 = 1 ;
V_2 = F_30 ( & V_96 -> V_97 ) ;
if ( F_20 ( F_8 ( & V_2 -> V_23 ) ) )
F_41 ( & V_2 -> V_23 ,
& V_2 -> V_19 -> V_100 ) ;
}
static void F_43 ( struct V_95 * V_96 )
{
int V_10 = F_44 ( V_96 -> V_101 ) ;
V_20 ;
F_7 ( & V_96 -> V_102 ) ;
V_96 -> V_103 = 1 ;
F_42 ( V_96 ) ;
if ( V_10 != V_104 )
F_45 ( V_105 , V_96 , L_6 ) ;
F_6 ( & V_96 -> V_102 ) ;
EXIT ;
}
static inline bool F_46 ( const struct V_106 * V_107 ,
const struct V_78 * V_79 )
{
return V_79 -> V_84 ( V_107 , V_79 ) ;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 = V_18 -> V_82 ;
struct V_106 * V_107 = V_81 -> V_85 ;
int V_37 = - V_108 ;
V_20 ;
F_3 ( F_48 ( & V_109 . V_110 ) ) ;
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( F_46 ( V_107 , V_79 ) ) {
V_37 = F_38 ( V_18 , V_79 ) ;
if ( V_37 != 0 ) {
F_17 ( L_7
L_8 ,
V_79 -> V_41 , V_81 -> V_87 ,
V_107 -> V_91 , V_37 ) ;
break;
}
}
}
RETURN ( V_37 ) ;
}
static int F_49 ( struct V_17 * V_18 ,
struct V_80 * V_81 )
{
int V_37 ;
enum V_111 V_112 ;
F_3 ( F_48 ( & V_109 . V_110 ) ) ;
if ( V_18 == & V_81 -> V_113 )
V_112 = V_114 ;
else if ( V_18 == V_81 -> V_115 )
V_112 = V_116 ;
else
F_32 () ;
V_18 -> V_82 = V_81 ;
V_18 -> V_117 = V_112 ;
F_50 ( & V_18 -> V_22 ) ;
F_40 ( & V_18 -> V_93 ) ;
F_40 ( & V_18 -> V_100 ) ;
V_37 = F_47 ( V_18 ) ;
RETURN ( V_37 ) ;
}
static int F_51 ( struct V_80 * V_81 )
{
struct V_17 * V_18 ;
int V_37 ;
V_20 ;
F_3 ( F_48 ( & V_109 . V_110 ) ) ;
V_18 = F_52 ( V_81 , false ) ;
V_37 = F_49 ( V_18 , V_81 ) ;
if ( V_37 < 0 )
GOTO ( V_43 , V_37 ) ;
if ( V_81 -> V_85 -> V_118 . V_119 == NULL )
GOTO ( V_43 , V_37 ) ;
F_53 ( V_81 -> V_115 ,
V_81 -> V_85 -> V_86 ,
V_81 -> V_87 ) ;
if ( V_81 -> V_115 == NULL )
GOTO ( V_43 , V_37 = - V_89 ) ;
V_18 = F_52 ( V_81 , true ) ;
V_37 = F_49 ( V_18 , V_81 ) ;
V_43:
RETURN ( V_37 ) ;
}
static void F_54 ( struct V_80 * V_81 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_1 * V_36 ;
int V_37 ;
bool V_120 = false ;
V_20 ;
F_3 ( F_48 ( & V_109 . V_110 ) ) ;
V_121:
V_18 = F_52 ( V_81 , V_120 ) ;
V_18 -> V_29 = 1 ;
F_55 (policy, tmp, &nrs->nrs_policy_list,
pol_list) {
V_37 = F_35 ( V_18 , V_2 -> V_3 -> V_41 ) ;
F_3 ( V_37 == 0 ) ;
}
if ( ! V_120 && F_56 ( V_81 ) ) {
V_120 = true ;
goto V_121;
}
if ( V_120 )
F_37 ( V_18 ) ;
EXIT ;
}
static struct V_78 * F_57 ( const char * V_44 )
{
struct V_78 * V_36 ;
V_20 ;
F_23 (tmp, &nrs_core.nrs_policies, pd_list) {
if ( strncmp ( V_36 -> V_41 , V_44 , V_45 ) == 0 )
RETURN ( V_36 ) ;
}
RETURN ( NULL ) ;
}
static int F_58 ( struct V_78 * V_79 )
{
struct V_17 * V_18 ;
struct V_106 * V_107 ;
struct V_80 * V_81 ;
int V_63 ;
int V_37 = 0 ;
V_20 ;
F_3 ( F_48 ( & V_109 . V_110 ) ) ;
F_3 ( F_48 ( & V_122 ) ) ;
F_23 (svc, &ptlrpc_all_services, srv_list) {
if ( ! F_46 ( V_107 , V_79 ) ||
F_20 ( V_107 -> V_123 ) )
continue;
F_59 (svcpt, i, svc) {
bool V_120 = false ;
V_121:
V_18 = F_52 ( V_81 , V_120 ) ;
V_37 = F_35 ( V_18 , V_79 -> V_41 ) ;
if ( V_37 == - V_73 ) {
V_37 = 0 ;
} else if ( V_37 != 0 ) {
F_17 ( L_9
L_8 ,
V_79 -> V_41 , V_81 -> V_87 ,
V_81 -> V_85 -> V_91 , V_37 ) ;
RETURN ( V_37 ) ;
}
if ( ! V_120 && F_60 ( V_107 ) ) {
V_120 = true ;
goto V_121;
}
}
if ( V_79 -> V_4 -> V_124 != NULL )
V_79 -> V_4 -> V_124 ( V_107 ) ;
}
RETURN ( V_37 ) ;
}
int F_61 ( struct V_125 * V_126 )
{
struct V_106 * V_107 ;
struct V_78 * V_79 ;
int V_37 = 0 ;
V_20 ;
F_3 ( V_126 != NULL ) ;
F_3 ( V_126 -> V_127 != NULL ) ;
F_3 ( V_126 -> V_128 != NULL ) ;
F_3 ( F_29 ( V_126 -> V_128 == V_129 ,
V_126 -> V_130 != NULL ) ) ;
F_3 ( F_29 ( ( V_126 -> V_131 & V_132 ) != 0 ,
V_126 -> V_133 != NULL ) ) ;
V_126 -> V_134 [ V_45 - 1 ] = '\0' ;
if ( ( V_126 -> V_131 & V_132 ) &&
( V_126 -> V_131 & ( V_40 |
V_94 ) ) ) {
F_17 ( L_10
L_11
L_12
L_13 , V_126 -> V_134 ) ;
RETURN ( - V_108 ) ;
}
F_62 ( & V_109 . V_110 ) ;
if ( F_57 ( V_126 -> V_134 ) != NULL ) {
F_17 ( L_14
L_15 ,
V_126 -> V_134 ) ;
GOTO ( V_135 , V_37 = - V_92 ) ;
}
F_63 ( V_79 ) ;
if ( V_79 == NULL )
GOTO ( V_135 , V_37 = - V_89 ) ;
strncpy ( V_79 -> V_41 , V_126 -> V_134 , V_45 ) ;
V_79 -> V_4 = V_126 -> V_127 ;
V_79 -> V_84 = V_126 -> V_128 ;
V_79 -> V_136 = V_126 -> V_130 ;
if ( ( V_126 -> V_131 & V_132 ) != 0 )
V_79 -> V_27 = V_126 -> V_133 ;
V_79 -> V_90 = V_126 -> V_131 ;
F_64 ( & V_79 -> V_26 , 0 ) ;
if ( ( V_126 -> V_131 & V_132 ) == 0 )
goto V_137;
F_62 ( & V_122 ) ;
F_23 (svc, &ptlrpc_all_services, srv_list) {
struct V_80 * V_81 ;
int V_63 ;
int V_138 ;
if ( ! F_46 ( V_107 , V_79 ) ||
F_20 ( V_107 -> V_123 ) )
continue;
F_59 (svcpt, i, svc) {
struct V_17 * V_18 ;
bool V_120 = false ;
V_121:
V_18 = F_52 ( V_81 , V_120 ) ;
V_37 = F_38 ( V_18 , V_79 ) ;
if ( V_37 != 0 ) {
F_17 ( L_7
L_8 ,
V_79 -> V_41 , V_81 -> V_87 ,
V_81 -> V_85 -> V_91 , V_37 ) ;
V_138 = F_58 ( V_79 ) ;
F_3 ( V_138 == 0 ) ;
F_65 ( & V_122 ) ;
F_37 ( V_79 ) ;
GOTO ( V_135 , V_37 ) ;
}
if ( ! V_120 && F_60 ( V_107 ) ) {
V_120 = true ;
goto V_121;
}
}
if ( V_79 -> V_4 -> V_139 != NULL ) {
V_37 = V_79 -> V_4 -> V_139 ( V_107 ) ;
if ( V_37 != 0 ) {
V_138 = F_58 ( V_79 ) ;
F_3 ( V_138 == 0 ) ;
F_65 ( & V_122 ) ;
F_37 ( V_79 ) ;
GOTO ( V_135 , V_37 ) ;
}
}
}
F_65 ( & V_122 ) ;
V_137:
F_41 ( & V_79 -> V_140 , & V_109 . V_141 ) ;
V_135:
F_65 ( & V_109 . V_110 ) ;
RETURN ( V_37 ) ;
}
int F_66 ( struct V_125 * V_126 )
{
struct V_78 * V_79 ;
int V_37 ;
V_20 ;
F_3 ( V_126 != NULL ) ;
if ( V_126 -> V_131 & V_40 ) {
F_17 ( L_16
L_17 ) ;
RETURN ( - V_30 ) ;
}
V_126 -> V_134 [ V_45 - 1 ] = '\0' ;
F_62 ( & V_109 . V_110 ) ;
V_79 = F_57 ( V_126 -> V_134 ) ;
if ( V_79 == NULL ) {
F_17 ( L_18
L_19 ,
V_126 -> V_134 ) ;
GOTO ( V_142 , V_37 = - V_73 ) ;
}
F_62 ( & V_122 ) ;
V_37 = F_58 ( V_79 ) ;
if ( V_37 < 0 ) {
if ( V_37 == - V_75 )
F_17 ( L_20
L_21
L_22 , V_126 -> V_134 ) ;
GOTO ( V_135 , V_37 ) ;
}
F_67 ( V_143 , L_23 ,
V_126 -> V_134 ) ;
F_36 ( & V_79 -> V_140 ) ;
F_37 ( V_79 ) ;
V_135:
F_65 ( & V_122 ) ;
V_142:
F_65 ( & V_109 . V_110 ) ;
RETURN ( V_37 ) ;
}
int F_68 ( struct V_106 * V_107 )
{
struct V_80 * V_81 ;
const struct V_78 * V_79 ;
int V_63 ;
int V_37 = 0 ;
F_62 ( & V_109 . V_110 ) ;
F_59 (svcpt, i, svc) {
V_37 = F_51 ( V_81 ) ;
if ( V_37 != 0 )
GOTO ( V_144 , V_37 ) ;
}
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( ! F_46 ( V_107 , V_79 ) )
continue;
if ( V_79 -> V_4 -> V_139 != NULL ) {
V_37 = V_79 -> V_4 -> V_139 ( V_107 ) ;
if ( V_37 != 0 )
GOTO ( V_144 , V_37 ) ;
}
}
V_144:
F_65 ( & V_109 . V_110 ) ;
RETURN ( V_37 ) ;
}
void F_69 ( struct V_106 * V_107 )
{
struct V_80 * V_81 ;
const struct V_78 * V_79 ;
int V_63 ;
F_62 ( & V_109 . V_110 ) ;
F_59 (svcpt, i, svc)
F_54 ( V_81 ) ;
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( ! F_46 ( V_107 , V_79 ) )
continue;
if ( V_79 -> V_4 -> V_124 != NULL )
V_79 -> V_4 -> V_124 ( V_107 ) ;
}
F_65 ( & V_109 . V_110 ) ;
}
void F_70 ( struct V_80 * V_81 ,
struct V_95 * V_96 , bool V_120 )
{
struct V_17 * V_18 = F_52 ( V_81 , V_120 ) ;
memset ( & V_96 -> V_97 , 0 , sizeof( V_96 -> V_97 ) ) ;
F_26 ( V_18 , & V_96 -> V_97 , V_96 -> V_97 . V_67 ,
false ) ;
V_96 -> V_97 . V_98 = 1 ;
}
void F_71 ( struct V_95 * V_96 )
{
if ( V_96 -> V_97 . V_98 ) {
F_27 ( V_96 -> V_97 . V_67 ) ;
V_96 -> V_97 . V_145 = 1 ;
}
}
void F_72 ( struct V_95 * V_96 )
{
if ( V_96 -> V_97 . V_146 )
F_33 ( & V_96 -> V_97 ) ;
}
void F_73 ( struct V_80 * V_81 ,
struct V_95 * V_96 , bool V_120 )
{
F_7 ( & V_81 -> V_147 ) ;
if ( V_120 )
F_43 ( V_96 ) ;
else
F_42 ( V_96 ) ;
F_6 ( & V_81 -> V_147 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_19 -> V_70 > 0 ) ;
F_3 ( V_2 -> V_7 > 0 ) ;
V_2 -> V_19 -> V_70 -- ;
V_2 -> V_7 -- ;
if ( F_20 ( V_2 -> V_7 == 0 ) ) {
F_75 ( & V_2 -> V_23 ) ;
} else if ( V_2 -> V_7 != V_2 -> V_19 -> V_70 ) {
F_3 ( V_2 -> V_7 <
V_2 -> V_19 -> V_70 ) ;
F_76 ( & V_2 -> V_23 ,
& V_2 -> V_19 -> V_100 ) ;
}
}
struct V_95 *
F_77 ( struct V_80 * V_81 , bool V_120 ,
bool V_64 , bool V_65 )
{
struct V_17 * V_18 = F_52 ( V_81 , V_120 ) ;
struct V_1 * V_2 ;
struct V_52 * V_53 ;
F_23 (policy, &nrs->nrs_policy_queued,
pol_list_queued) {
V_53 = F_28 ( V_2 , V_64 , V_65 ) ;
if ( V_53 != NULL ) {
if ( F_78 ( ! V_64 ) ) {
V_53 -> V_146 = 1 ;
V_2 -> V_24 ++ ;
V_2 -> V_19 -> V_72 ++ ;
F_74 ( V_2 ) ;
}
return F_79 ( V_53 , struct V_95 , V_97 ) ;
}
}
return NULL ;
}
void F_80 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_30 ( & V_96 -> V_97 ) ;
V_2 -> V_3 -> V_4 -> V_83 ( V_2 , & V_96 -> V_97 ) ;
V_96 -> V_97 . V_99 = 0 ;
F_74 ( V_2 ) ;
}
bool F_81 ( struct V_80 * V_81 , bool V_120 )
{
struct V_17 * V_18 = F_52 ( V_81 , V_120 ) ;
return V_18 -> V_70 > 0 ;
}
void F_82 ( struct V_95 * V_96 )
{
struct V_80 * V_81 = V_96 -> V_148 -> V_149 ;
struct V_52 * V_53 = & V_96 -> V_97 ;
struct V_46 * V_150 [ V_59 ] ;
struct V_46 * V_151 [ V_59 ] ;
V_20 ;
F_26 ( F_52 ( V_81 , true ) , V_53 , V_150 , true ) ;
F_7 ( & V_81 -> V_147 ) ;
if ( ! F_83 ( V_96 ) )
goto V_43;
F_80 ( V_96 ) ;
memcpy ( V_151 , V_53 -> V_67 , V_59 * sizeof( V_151 [ 0 ] ) ) ;
memcpy ( V_53 -> V_67 , V_150 , V_59 * sizeof( V_150 [ 0 ] ) ) ;
F_43 ( V_96 ) ;
memcpy ( V_150 , V_151 , V_59 * sizeof( V_150 [ 0 ] ) ) ;
V_43:
F_6 ( & V_81 -> V_147 ) ;
F_27 ( V_150 ) ;
EXIT ;
}
int F_84 ( const struct V_106 * V_107 ,
enum V_111 V_112 , char * V_44 ,
enum V_9 V_10 , bool V_152 , void * V_11 )
{
struct V_80 * V_81 ;
int V_63 ;
int V_37 = 0 ;
V_20 ;
F_3 ( V_10 != V_153 ) ;
if ( ( V_112 & V_154 ) == 0 )
return - V_108 ;
F_59 (svcpt, i, svc) {
if ( ( V_112 & V_114 ) != 0 ) {
V_37 = F_34 ( F_52 ( V_81 , false ) , V_44 ,
V_10 , V_11 ) ;
if ( V_37 != 0 || ( V_112 == V_114 &&
V_152 ) )
GOTO ( V_43 , V_37 ) ;
}
if ( ( V_112 & V_116 ) != 0 ) {
V_37 = F_34 ( F_52 ( V_81 , true ) , V_44 ,
V_10 , V_11 ) ;
if ( V_37 != 0 || V_152 )
GOTO ( V_43 , V_37 ) ;
}
}
V_43:
RETURN ( V_37 ) ;
}
int F_85 ( void )
{
int V_37 ;
V_20 ;
F_86 ( & V_109 . V_110 ) ;
F_40 ( & V_109 . V_141 ) ;
V_37 = F_61 ( & V_155 ) ;
if ( V_37 != 0 )
GOTO ( V_135 , V_37 ) ;
RETURN ( V_37 ) ;
V_135:
F_87 () ;
RETURN ( V_37 ) ;
}
void F_87 ( void )
{
struct V_78 * V_79 ;
struct V_78 * V_36 ;
F_55 (desc, tmp, &nrs_core.nrs_policies,
pd_list) {
F_75 ( & V_79 -> V_140 ) ;
F_37 ( V_79 ) ;
}
}
