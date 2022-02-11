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
return - V_14 ;
return V_2 -> V_3 -> V_4 -> V_15 != NULL ?
V_2 -> V_3 -> V_4 -> V_15 ( V_2 , V_10 , V_11 ) :
- V_16 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_2 -> V_3 -> V_4 -> V_20 != NULL ) {
F_6 ( & V_18 -> V_21 ) ;
V_2 -> V_3 -> V_4 -> V_20 ( V_2 ) ;
F_7 ( & V_18 -> V_21 ) ;
}
F_3 ( F_8 ( & V_2 -> V_22 ) ) ;
F_3 ( V_2 -> V_7 == 0 &&
V_2 -> V_23 == 0 ) ;
V_2 -> V_24 = NULL ;
V_2 -> V_12 = V_13 ;
if ( F_9 ( & V_2 -> V_3 -> V_25 ) )
F_10 ( V_2 -> V_3 -> V_26 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_18 -> V_27 == V_2 && ! V_18 -> V_28 )
return - V_29 ;
if ( V_2 -> V_12 == V_30 )
return - V_31 ;
if ( V_2 -> V_12 != V_32 )
return 0 ;
V_2 -> V_12 = V_33 ;
if ( V_18 -> V_34 == V_2 ) {
V_18 -> V_34 = NULL ;
} else {
F_3 ( V_18 -> V_27 == V_2 ) ;
V_18 -> V_27 = NULL ;
}
if ( V_2 -> V_6 == 1 )
F_5 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_17 * V_18 )
{
struct V_1 * V_35 = V_18 -> V_34 ;
if ( V_35 == NULL ) {
return;
}
V_18 -> V_34 = NULL ;
F_3 ( V_35 -> V_12 == V_32 ) ;
V_35 -> V_12 = V_33 ;
if ( V_35 -> V_6 == 0 )
F_5 ( V_35 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = V_2 -> V_19 ;
int V_36 = 0 ;
if ( V_18 -> V_37 )
return - V_31 ;
F_3 ( V_2 -> V_12 != V_30 ) ;
if ( V_2 -> V_12 == V_33 )
return - V_31 ;
if ( V_2 -> V_38 & V_39 ) {
if ( V_2 == V_18 -> V_27 ) {
F_12 ( V_18 ) ;
return 0 ;
}
F_3 ( V_18 -> V_27 == NULL ) ;
} else {
if ( V_18 -> V_27 == NULL )
return - V_29 ;
if ( V_2 -> V_12 == V_32 )
return 0 ;
}
if ( F_14 ( & V_2 -> V_3 -> V_25 ) == 1 &&
! F_15 ( V_2 -> V_3 -> V_26 ) ) {
F_16 ( & V_2 -> V_3 -> V_25 ) ;
F_17 ( L_1 ,
V_2 -> V_3 -> V_40 ) ;
return - V_14 ;
}
V_18 -> V_37 = 1 ;
V_2 -> V_12 = V_30 ;
if ( V_2 -> V_3 -> V_4 -> V_41 ) {
F_6 ( & V_18 -> V_21 ) ;
V_36 = V_2 -> V_3 -> V_4 -> V_41 ( V_2 ) ;
F_7 ( & V_18 -> V_21 ) ;
if ( V_36 != 0 ) {
if ( F_9 ( & V_2 -> V_3 -> V_25 ) )
F_10 ( V_2 -> V_3 -> V_26 ) ;
V_2 -> V_12 = V_13 ;
goto V_42;
}
}
V_2 -> V_12 = V_32 ;
if ( V_2 -> V_38 & V_39 ) {
V_18 -> V_27 = V_2 ;
} else {
F_12 ( V_18 ) ;
V_18 -> V_34 = V_2 ;
}
V_42:
V_18 -> V_37 = 0 ;
return V_36 ;
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
V_2 -> V_12 == V_33 ) )
F_5 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_19 -> V_21 ) ;
F_19 ( V_2 ) ;
F_6 ( & V_2 -> V_19 -> V_21 ) ;
}
static struct V_1 * F_22 ( struct V_17 * V_18 ,
char * V_43 )
{
struct V_1 * V_35 ;
F_23 (tmp, &nrs->nrs_policy_list, pol_list) {
if ( strncmp ( V_35 -> V_3 -> V_40 , V_43 ,
V_44 ) == 0 ) {
F_18 ( V_35 ) ;
return V_35 ;
}
}
return NULL ;
}
static void F_24 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_47 ;
if ( V_2 -> V_3 -> V_4 -> V_48 != NULL ) {
struct V_45 * V_49 ;
for (; V_46 != NULL ; V_46 = V_49 ) {
V_49 = V_46 -> V_50 ;
V_2 -> V_3 -> V_4 -> V_48 ( V_2 , V_46 ) ;
}
}
}
static
struct V_45 * F_25 ( struct V_1 * V_2 ,
struct V_51 * V_52 ,
bool V_53 )
{
struct V_45 * V_46 = NULL ;
struct V_45 * V_35 = NULL ;
int V_36 ;
while ( 1 ) {
V_36 = V_2 -> V_3 -> V_4 -> V_54 ( V_2 , V_52 , V_46 ,
& V_35 , V_53 ) ;
if ( V_36 < 0 ) {
if ( V_46 != NULL )
F_24 ( V_46 ) ;
return NULL ;
}
F_3 ( V_35 != NULL ) ;
V_35 -> V_50 = V_46 ;
V_35 -> V_47 = V_2 ;
V_46 = V_35 ;
V_35 = NULL ;
if ( V_36 > 0 )
return V_46 ;
}
}
static void F_26 ( struct V_17 * V_18 ,
struct V_51 * V_52 ,
struct V_45 * * V_55 ,
bool V_53 )
{
struct V_1 * V_56 = NULL ;
struct V_1 * V_57 = NULL ;
memset ( V_55 , 0 , sizeof( V_55 [ 0 ] ) * V_58 ) ;
F_7 ( & V_18 -> V_21 ) ;
V_57 = V_18 -> V_27 ;
F_18 ( V_57 ) ;
V_56 = V_18 -> V_34 ;
if ( V_56 != NULL )
F_18 ( V_56 ) ;
F_6 ( & V_18 -> V_21 ) ;
V_55 [ V_59 ] = F_25 ( V_57 , V_52 , V_53 ) ;
F_3 ( V_55 [ V_59 ] != NULL ) ;
if ( V_56 != NULL ) {
V_55 [ V_60 ] = F_25 ( V_56 , V_52 ,
V_53 ) ;
if ( V_55 [ V_60 ] == NULL )
F_21 ( V_56 ) ;
}
}
static void F_27 ( struct V_45 * * V_55 )
{
struct V_1 * V_61 [ V_58 ] ;
struct V_17 * V_18 = NULL ;
int V_62 ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
if ( V_55 [ V_62 ] != NULL ) {
V_61 [ V_62 ] = V_55 [ V_62 ] -> V_47 ;
F_24 ( V_55 [ V_62 ] ) ;
V_55 [ V_62 ] = NULL ;
} else {
V_61 [ V_62 ] = NULL ;
}
}
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
if ( V_61 [ V_62 ] == NULL )
continue;
if ( V_18 == NULL ) {
V_18 = V_61 [ V_62 ] -> V_19 ;
F_7 ( & V_18 -> V_21 ) ;
}
F_19 ( V_61 [ V_62 ] ) ;
}
if ( V_18 != NULL )
F_6 ( & V_18 -> V_21 ) ;
}
static inline
struct V_51 * F_28 ( struct V_1 * V_2 ,
bool V_63 , bool V_64 )
{
struct V_51 * V_52 ;
F_3 ( V_2 -> V_7 > 0 ) ;
V_52 = V_2 -> V_3 -> V_4 -> V_65 ( V_2 , V_63 , V_64 ) ;
F_3 ( F_29 ( V_52 != NULL , F_30 ( V_52 ) == V_2 ) ) ;
return V_52 ;
}
static inline void F_31 ( struct V_51 * V_52 )
{
struct V_1 * V_2 ;
int V_36 ;
int V_62 ;
for ( V_62 = V_58 - 1 ; V_62 >= 0 ; V_62 -- ) {
if ( V_52 -> V_66 [ V_62 ] == NULL )
continue;
V_52 -> V_67 = V_62 ;
V_2 = V_52 -> V_66 [ V_62 ] -> V_47 ;
V_36 = V_2 -> V_3 -> V_4 -> V_68 ( V_2 , V_52 ) ;
if ( V_36 == 0 ) {
V_2 -> V_19 -> V_69 ++ ;
V_2 -> V_7 ++ ;
return;
}
}
F_32 () ;
}
static inline void F_33 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_30 ( V_52 ) ;
if ( V_2 -> V_3 -> V_4 -> V_70 )
V_2 -> V_3 -> V_4 -> V_70 ( V_2 , V_52 ) ;
F_3 ( V_2 -> V_19 -> V_71 > 0 ) ;
F_3 ( V_2 -> V_23 > 0 ) ;
V_2 -> V_19 -> V_71 -- ;
V_2 -> V_23 -- ;
}
static int F_34 ( struct V_17 * V_18 , char * V_43 ,
enum V_9 V_10 , void * V_11 )
{
struct V_1 * V_2 ;
int V_36 = 0 ;
F_7 ( & V_18 -> V_21 ) ;
V_2 = F_22 ( V_18 , V_43 ) ;
if ( V_2 == NULL ) {
V_36 = - V_72 ;
goto V_42;
}
switch ( V_10 ) {
default:
V_36 = F_4 ( V_2 , V_10 , V_11 ) ;
break;
case V_73 :
V_36 = F_13 ( V_2 ) ;
break;
}
V_42:
if ( V_2 != NULL )
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_21 ) ;
return V_36 ;
}
static int F_35 ( struct V_17 * V_18 , char * V_43 )
{
struct V_1 * V_2 = NULL ;
F_7 ( & V_18 -> V_21 ) ;
V_2 = F_22 ( V_18 , V_43 ) ;
if ( V_2 == NULL ) {
F_6 ( & V_18 -> V_21 ) ;
F_17 ( L_2 , V_43 ) ;
return - V_72 ;
}
if ( V_2 -> V_6 > 1 ) {
F_17 ( L_3 , V_43 ,
( int ) V_2 -> V_6 ) ;
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_21 ) ;
return - V_74 ;
}
F_3 ( V_2 -> V_7 == 0 ) ;
F_3 ( V_2 -> V_23 == 0 ) ;
if ( V_2 -> V_12 != V_13 ) {
F_11 ( V_2 ) ;
F_3 ( V_2 -> V_12 == V_13 ) ;
}
F_36 ( & V_2 -> V_75 ) ;
V_18 -> V_76 -- ;
F_19 ( V_2 ) ;
F_6 ( & V_18 -> V_21 ) ;
F_2 ( V_2 ) ;
F_3 ( V_2 -> V_24 == NULL ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_17 * V_18 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 ;
struct V_1 * V_35 ;
struct V_79 * V_80 = V_18 -> V_81 ;
int V_36 ;
F_3 ( V_80 != NULL ) ;
F_3 ( V_78 -> V_4 != NULL ) ;
F_3 ( V_78 -> V_4 -> V_54 != NULL ) ;
F_3 ( V_78 -> V_4 -> V_65 != NULL ) ;
F_3 ( V_78 -> V_4 -> V_68 != NULL ) ;
F_3 ( V_78 -> V_4 -> V_82 != NULL ) ;
F_3 ( V_78 -> V_83 != NULL ) ;
F_39 ( V_2 , V_80 -> V_84 -> V_85 ,
V_80 -> V_86 , sizeof( * V_2 ) , V_87 ) ;
if ( V_2 == NULL )
return - V_88 ;
V_2 -> V_19 = V_18 ;
V_2 -> V_3 = V_78 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_38 = V_78 -> V_89 ;
F_40 ( & V_2 -> V_75 ) ;
F_40 ( & V_2 -> V_22 ) ;
V_36 = F_1 ( V_2 ) ;
if ( V_36 != 0 ) {
F_37 ( V_2 ) ;
return V_36 ;
}
F_7 ( & V_18 -> V_21 ) ;
V_35 = F_22 ( V_18 , V_2 -> V_3 -> V_40 ) ;
if ( V_35 != NULL ) {
F_17 ( L_4 ,
V_2 -> V_3 -> V_40 ,
V_80 -> V_84 -> V_90 ) ;
F_19 ( V_35 ) ;
F_6 ( & V_18 -> V_21 ) ;
F_2 ( V_2 ) ;
F_37 ( V_2 ) ;
return - V_91 ;
}
F_41 ( & V_2 -> V_75 , & V_18 -> V_92 ) ;
V_18 -> V_76 ++ ;
if ( V_2 -> V_38 & V_93 )
V_36 = F_13 ( V_2 ) ;
F_6 ( & V_18 -> V_21 ) ;
if ( V_36 != 0 )
( void ) F_35 ( V_18 , V_2 -> V_3 -> V_40 ) ;
return V_36 ;
}
static void F_42 ( struct V_94 * V_95 )
{
struct V_1 * V_2 ;
F_3 ( V_95 -> V_96 . V_97 ) ;
F_3 ( ! V_95 -> V_96 . V_98 ) ;
F_31 ( & V_95 -> V_96 ) ;
V_95 -> V_96 . V_98 = 1 ;
V_2 = F_30 ( & V_95 -> V_96 ) ;
if ( F_20 ( F_8 ( & V_2 -> V_22 ) ) )
F_41 ( & V_2 -> V_22 ,
& V_2 -> V_19 -> V_99 ) ;
}
static void F_43 ( struct V_94 * V_95 )
{
int V_10 = F_44 ( V_95 -> V_100 ) ;
F_7 ( & V_95 -> V_101 ) ;
V_95 -> V_102 = 1 ;
F_42 ( V_95 ) ;
if ( V_10 != V_103 )
F_45 ( V_104 , V_95 , L_5 ) ;
F_6 ( & V_95 -> V_101 ) ;
}
static inline bool F_46 ( const struct V_105 * V_106 ,
const struct V_77 * V_78 )
{
return V_78 -> V_83 ( V_106 , V_78 ) ;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_77 * V_78 ;
struct V_79 * V_80 = V_18 -> V_81 ;
struct V_105 * V_106 = V_80 -> V_84 ;
int V_36 = - V_107 ;
F_3 ( F_48 ( & V_108 . V_109 ) ) ;
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( F_46 ( V_106 , V_78 ) ) {
V_36 = F_38 ( V_18 , V_78 ) ;
if ( V_36 != 0 ) {
F_17 ( L_6 ,
V_78 -> V_40 , V_80 -> V_86 ,
V_106 -> V_90 , V_36 ) ;
break;
}
}
}
return V_36 ;
}
static int F_49 ( struct V_17 * V_18 ,
struct V_79 * V_80 )
{
int V_36 ;
enum V_110 V_111 ;
F_3 ( F_48 ( & V_108 . V_109 ) ) ;
if ( V_18 == & V_80 -> V_112 )
V_111 = V_113 ;
else if ( V_18 == V_80 -> V_114 )
V_111 = V_115 ;
else
F_32 () ;
V_18 -> V_81 = V_80 ;
V_18 -> V_116 = V_111 ;
F_50 ( & V_18 -> V_21 ) ;
F_40 ( & V_18 -> V_92 ) ;
F_40 ( & V_18 -> V_99 ) ;
V_36 = F_47 ( V_18 ) ;
return V_36 ;
}
static int F_51 ( struct V_79 * V_80 )
{
struct V_17 * V_18 ;
int V_36 ;
F_3 ( F_48 ( & V_108 . V_109 ) ) ;
V_18 = F_52 ( V_80 , false ) ;
V_36 = F_49 ( V_18 , V_80 ) ;
if ( V_36 < 0 )
goto V_42;
if ( V_80 -> V_84 -> V_117 . V_118 == NULL )
goto V_42;
F_53 ( V_80 -> V_114 ,
V_80 -> V_84 -> V_85 ,
V_80 -> V_86 ) ;
if ( V_80 -> V_114 == NULL ) {
V_36 = - V_88 ;
goto V_42;
}
V_18 = F_52 ( V_80 , true ) ;
V_36 = F_49 ( V_18 , V_80 ) ;
V_42:
return V_36 ;
}
static void F_54 ( struct V_79 * V_80 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_1 * V_35 ;
int V_36 ;
bool V_119 = false ;
F_3 ( F_48 ( & V_108 . V_109 ) ) ;
V_120:
V_18 = F_52 ( V_80 , V_119 ) ;
V_18 -> V_28 = 1 ;
F_55 (policy, tmp, &nrs->nrs_policy_list,
pol_list) {
V_36 = F_35 ( V_18 , V_2 -> V_3 -> V_40 ) ;
F_3 ( V_36 == 0 ) ;
}
if ( ! V_119 && F_56 ( V_80 ) ) {
V_119 = true ;
goto V_120;
}
if ( V_119 )
F_37 ( V_18 ) ;
}
static struct V_77 * F_57 ( const char * V_43 )
{
struct V_77 * V_35 ;
F_23 (tmp, &nrs_core.nrs_policies, pd_list) {
if ( strncmp ( V_35 -> V_40 , V_43 , V_44 ) == 0 )
return V_35 ;
}
return NULL ;
}
static int F_58 ( struct V_77 * V_78 )
{
struct V_17 * V_18 ;
struct V_105 * V_106 ;
struct V_79 * V_80 ;
int V_62 ;
int V_36 = 0 ;
F_3 ( F_48 ( & V_108 . V_109 ) ) ;
F_3 ( F_48 ( & V_121 ) ) ;
F_23 (svc, &ptlrpc_all_services, srv_list) {
if ( ! F_46 ( V_106 , V_78 ) ||
F_20 ( V_106 -> V_122 ) )
continue;
F_59 (svcpt, i, svc) {
bool V_119 = false ;
V_120:
V_18 = F_52 ( V_80 , V_119 ) ;
V_36 = F_35 ( V_18 , V_78 -> V_40 ) ;
if ( V_36 == - V_72 ) {
V_36 = 0 ;
} else if ( V_36 != 0 ) {
F_17 ( L_7 ,
V_78 -> V_40 , V_80 -> V_86 ,
V_80 -> V_84 -> V_90 , V_36 ) ;
return V_36 ;
}
if ( ! V_119 && F_60 ( V_106 ) ) {
V_119 = true ;
goto V_120;
}
}
if ( V_78 -> V_4 -> V_123 != NULL )
V_78 -> V_4 -> V_123 ( V_106 ) ;
}
return V_36 ;
}
int F_61 ( struct V_124 * V_125 )
{
struct V_105 * V_106 ;
struct V_77 * V_78 ;
int V_36 = 0 ;
F_3 ( V_125 != NULL ) ;
F_3 ( V_125 -> V_126 != NULL ) ;
F_3 ( V_125 -> V_127 != NULL ) ;
F_3 ( F_29 ( V_125 -> V_127 == V_128 ,
V_125 -> V_129 != NULL ) ) ;
F_3 ( F_29 ( ( V_125 -> V_130 & V_131 ) != 0 ,
V_125 -> V_132 != NULL ) ) ;
V_125 -> V_133 [ V_44 - 1 ] = '\0' ;
if ( ( V_125 -> V_130 & V_131 ) &&
( V_125 -> V_130 & ( V_39 |
V_93 ) ) ) {
F_17 ( L_8 ,
V_125 -> V_133 ) ;
return - V_107 ;
}
F_62 ( & V_108 . V_109 ) ;
if ( F_57 ( V_125 -> V_133 ) != NULL ) {
F_17 ( L_9 ,
V_125 -> V_133 ) ;
V_36 = - V_91 ;
goto V_134;
}
F_63 ( V_78 ) ;
if ( V_78 == NULL ) {
V_36 = - V_88 ;
goto V_134;
}
strncpy ( V_78 -> V_40 , V_125 -> V_133 , V_44 ) ;
V_78 -> V_4 = V_125 -> V_126 ;
V_78 -> V_83 = V_125 -> V_127 ;
V_78 -> V_135 = V_125 -> V_129 ;
if ( ( V_125 -> V_130 & V_131 ) != 0 )
V_78 -> V_26 = V_125 -> V_132 ;
V_78 -> V_89 = V_125 -> V_130 ;
F_64 ( & V_78 -> V_25 , 0 ) ;
if ( ( V_125 -> V_130 & V_131 ) == 0 )
goto V_136;
F_62 ( & V_121 ) ;
F_23 (svc, &ptlrpc_all_services, srv_list) {
struct V_79 * V_80 ;
int V_62 ;
int V_137 ;
if ( ! F_46 ( V_106 , V_78 ) ||
F_20 ( V_106 -> V_122 ) )
continue;
F_59 (svcpt, i, svc) {
struct V_17 * V_18 ;
bool V_119 = false ;
V_120:
V_18 = F_52 ( V_80 , V_119 ) ;
V_36 = F_38 ( V_18 , V_78 ) ;
if ( V_36 != 0 ) {
F_17 ( L_6 ,
V_78 -> V_40 , V_80 -> V_86 ,
V_80 -> V_84 -> V_90 , V_36 ) ;
V_137 = F_58 ( V_78 ) ;
F_3 ( V_137 == 0 ) ;
F_65 ( & V_121 ) ;
F_37 ( V_78 ) ;
goto V_134;
}
if ( ! V_119 && F_60 ( V_106 ) ) {
V_119 = true ;
goto V_120;
}
}
if ( V_78 -> V_4 -> V_138 != NULL ) {
V_36 = V_78 -> V_4 -> V_138 ( V_106 ) ;
if ( V_36 != 0 ) {
V_137 = F_58 ( V_78 ) ;
F_3 ( V_137 == 0 ) ;
F_65 ( & V_121 ) ;
F_37 ( V_78 ) ;
goto V_134;
}
}
}
F_65 ( & V_121 ) ;
V_136:
F_41 ( & V_78 -> V_139 , & V_108 . V_140 ) ;
V_134:
F_65 ( & V_108 . V_109 ) ;
return V_36 ;
}
int F_66 ( struct V_124 * V_125 )
{
struct V_77 * V_78 ;
int V_36 ;
F_3 ( V_125 != NULL ) ;
if ( V_125 -> V_130 & V_39 ) {
F_17 ( L_10 ) ;
return - V_29 ;
}
V_125 -> V_133 [ V_44 - 1 ] = '\0' ;
F_62 ( & V_108 . V_109 ) ;
V_78 = F_57 ( V_125 -> V_133 ) ;
if ( V_78 == NULL ) {
F_17 ( L_11 ,
V_125 -> V_133 ) ;
V_36 = - V_72 ;
goto V_141;
}
F_62 ( & V_121 ) ;
V_36 = F_58 ( V_78 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_74 )
F_17 ( L_12 ,
V_125 -> V_133 ) ;
goto V_134;
}
F_67 ( V_142 , L_13 ,
V_125 -> V_133 ) ;
F_36 ( & V_78 -> V_139 ) ;
F_37 ( V_78 ) ;
V_134:
F_65 ( & V_121 ) ;
V_141:
F_65 ( & V_108 . V_109 ) ;
return V_36 ;
}
int F_68 ( struct V_105 * V_106 )
{
struct V_79 * V_80 ;
const struct V_77 * V_78 ;
int V_62 ;
int V_36 = 0 ;
F_62 ( & V_108 . V_109 ) ;
F_59 (svcpt, i, svc) {
V_36 = F_51 ( V_80 ) ;
if ( V_36 != 0 )
goto V_143;
}
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( ! F_46 ( V_106 , V_78 ) )
continue;
if ( V_78 -> V_4 -> V_138 != NULL ) {
V_36 = V_78 -> V_4 -> V_138 ( V_106 ) ;
if ( V_36 != 0 )
goto V_143;
}
}
V_143:
F_65 ( & V_108 . V_109 ) ;
return V_36 ;
}
void F_69 ( struct V_105 * V_106 )
{
struct V_79 * V_80 ;
const struct V_77 * V_78 ;
int V_62 ;
F_62 ( & V_108 . V_109 ) ;
F_59 (svcpt, i, svc)
F_54 ( V_80 ) ;
F_23 (desc, &nrs_core.nrs_policies, pd_list) {
if ( ! F_46 ( V_106 , V_78 ) )
continue;
if ( V_78 -> V_4 -> V_123 != NULL )
V_78 -> V_4 -> V_123 ( V_106 ) ;
}
F_65 ( & V_108 . V_109 ) ;
}
void F_70 ( struct V_79 * V_80 ,
struct V_94 * V_95 , bool V_119 )
{
struct V_17 * V_18 = F_52 ( V_80 , V_119 ) ;
memset ( & V_95 -> V_96 , 0 , sizeof( V_95 -> V_96 ) ) ;
F_26 ( V_18 , & V_95 -> V_96 , V_95 -> V_96 . V_66 ,
false ) ;
V_95 -> V_96 . V_97 = 1 ;
}
void F_71 ( struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_97 ) {
F_27 ( V_95 -> V_96 . V_66 ) ;
V_95 -> V_96 . V_144 = 1 ;
}
}
void F_72 ( struct V_94 * V_95 )
{
if ( V_95 -> V_96 . V_145 )
F_33 ( & V_95 -> V_96 ) ;
}
void F_73 ( struct V_79 * V_80 ,
struct V_94 * V_95 , bool V_119 )
{
F_7 ( & V_80 -> V_146 ) ;
if ( V_119 )
F_43 ( V_95 ) ;
else
F_42 ( V_95 ) ;
F_6 ( & V_80 -> V_146 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_19 -> V_69 > 0 ) ;
F_3 ( V_2 -> V_7 > 0 ) ;
V_2 -> V_19 -> V_69 -- ;
V_2 -> V_7 -- ;
if ( F_20 ( V_2 -> V_7 == 0 ) ) {
F_75 ( & V_2 -> V_22 ) ;
} else if ( V_2 -> V_7 != V_2 -> V_19 -> V_69 ) {
F_3 ( V_2 -> V_7 <
V_2 -> V_19 -> V_69 ) ;
F_76 ( & V_2 -> V_22 ,
& V_2 -> V_19 -> V_99 ) ;
}
}
struct V_94 *
F_77 ( struct V_79 * V_80 , bool V_119 ,
bool V_63 , bool V_64 )
{
struct V_17 * V_18 = F_52 ( V_80 , V_119 ) ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
F_23 (policy, &nrs->nrs_policy_queued,
pol_list_queued) {
V_52 = F_28 ( V_2 , V_63 , V_64 ) ;
if ( V_52 != NULL ) {
if ( F_78 ( ! V_63 ) ) {
V_52 -> V_145 = 1 ;
V_2 -> V_23 ++ ;
V_2 -> V_19 -> V_71 ++ ;
F_74 ( V_2 ) ;
}
return F_79 ( V_52 , struct V_94 , V_96 ) ;
}
}
return NULL ;
}
void F_80 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_30 ( & V_95 -> V_96 ) ;
V_2 -> V_3 -> V_4 -> V_82 ( V_2 , & V_95 -> V_96 ) ;
V_95 -> V_96 . V_98 = 0 ;
F_74 ( V_2 ) ;
}
bool F_81 ( struct V_79 * V_80 , bool V_119 )
{
struct V_17 * V_18 = F_52 ( V_80 , V_119 ) ;
return V_18 -> V_69 > 0 ;
}
void F_82 ( struct V_94 * V_95 )
{
struct V_79 * V_80 = V_95 -> V_147 -> V_148 ;
struct V_51 * V_52 = & V_95 -> V_96 ;
struct V_45 * V_149 [ V_58 ] ;
struct V_45 * V_150 [ V_58 ] ;
F_26 ( F_52 ( V_80 , true ) , V_52 , V_149 , true ) ;
F_7 ( & V_80 -> V_146 ) ;
if ( ! F_83 ( V_95 ) )
goto V_42;
F_80 ( V_95 ) ;
memcpy ( V_150 , V_52 -> V_66 , V_58 * sizeof( V_150 [ 0 ] ) ) ;
memcpy ( V_52 -> V_66 , V_149 , V_58 * sizeof( V_149 [ 0 ] ) ) ;
F_43 ( V_95 ) ;
memcpy ( V_149 , V_150 , V_58 * sizeof( V_149 [ 0 ] ) ) ;
V_42:
F_6 ( & V_80 -> V_146 ) ;
F_27 ( V_149 ) ;
}
int F_84 ( const struct V_105 * V_106 ,
enum V_110 V_111 , char * V_43 ,
enum V_9 V_10 , bool V_151 , void * V_11 )
{
struct V_79 * V_80 ;
int V_62 ;
int V_36 = 0 ;
F_3 ( V_10 != V_152 ) ;
if ( ( V_111 & V_153 ) == 0 )
return - V_107 ;
F_59 (svcpt, i, svc) {
if ( ( V_111 & V_113 ) != 0 ) {
V_36 = F_34 ( F_52 ( V_80 , false ) , V_43 ,
V_10 , V_11 ) ;
if ( V_36 != 0 || ( V_111 == V_113 &&
V_151 ) )
goto V_42;
}
if ( ( V_111 & V_115 ) != 0 ) {
V_36 = F_34 ( F_52 ( V_80 , true ) , V_43 ,
V_10 , V_11 ) ;
if ( V_36 != 0 || V_151 )
goto V_42;
}
}
V_42:
return V_36 ;
}
int F_85 ( void )
{
int V_36 ;
F_86 ( & V_108 . V_109 ) ;
F_40 ( & V_108 . V_140 ) ;
V_36 = F_61 ( & V_154 ) ;
if ( V_36 != 0 )
goto V_134;
return V_36 ;
V_134:
F_87 () ;
return V_36 ;
}
void F_87 ( void )
{
struct V_77 * V_78 ;
struct V_77 * V_35 ;
F_55 (desc, tmp, &nrs_core.nrs_policies,
pd_list) {
F_75 ( & V_78 -> V_139 ) ;
F_37 ( V_78 ) ;
}
}
