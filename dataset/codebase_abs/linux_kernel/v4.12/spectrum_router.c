static unsigned int *
F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return & V_2 -> V_6 ;
case V_7 :
return & V_2 -> V_8 ;
}
return NULL ;
}
static bool
F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
switch ( V_4 ) {
case V_5 :
return V_2 -> V_9 ;
case V_7 :
return V_2 -> V_10 ;
}
return false ;
}
static void
F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
bool V_11 )
{
switch ( V_4 ) {
case V_5 :
V_2 -> V_9 = V_11 ;
break;
case V_7 :
V_2 -> V_10 = V_11 ;
break;
}
}
static int F_4 ( struct V_12 * V_12 , T_1 V_13 ,
unsigned int V_14 , bool V_15 ,
enum V_3 V_4 )
{
char V_16 [ V_17 ] ;
bool V_18 = false ;
int V_19 ;
if ( V_4 == V_5 )
V_18 = true ;
F_5 ( V_16 , V_13 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( V_19 )
return V_19 ;
F_8 ( V_16 , V_14 , V_15 ,
V_18 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
int F_10 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 , T_2 * V_22 )
{
char V_23 [ V_24 ] ;
unsigned int * V_25 ;
bool V_11 ;
int V_19 ;
V_11 = F_2 ( V_2 , V_4 ) ;
if ( ! V_11 )
return - V_26 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( ! V_25 )
return - V_26 ;
F_11 ( V_23 , * V_25 ,
V_27 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_28 ) , V_23 ) ;
if ( V_19 )
return V_19 ;
* V_22 = F_12 ( V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_12 ,
unsigned int V_14 )
{
char V_23 [ V_24 ] ;
F_11 ( V_23 , V_14 ,
V_29 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_28 ) , V_23 ) ;
}
int F_14 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned int * V_25 ;
int V_19 ;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( ! V_25 )
return - V_26 ;
V_19 = F_15 ( V_12 , V_30 ,
V_25 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_13 ( V_12 , * V_25 ) ;
if ( V_19 )
goto V_31;
V_19 = F_4 ( V_12 , V_2 -> V_13 ,
* V_25 , true , V_4 ) ;
if ( V_19 )
goto V_32;
F_3 ( V_2 , V_4 , true ) ;
return 0 ;
V_32:
V_31:
F_16 ( V_12 , V_30 ,
* V_25 ) ;
return V_19 ;
}
void F_17 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
enum V_3 V_4 )
{
unsigned int * V_25 ;
if ( ! F_2 ( V_2 , V_4 ) )
return;
V_25 = F_1 ( V_2 , V_4 ) ;
if ( F_18 ( ! V_25 ) )
return;
F_4 ( V_12 , V_2 -> V_13 ,
* V_25 , false , V_4 ) ;
F_16 ( V_12 , V_30 ,
* V_25 ) ;
F_3 ( V_2 , V_4 , false ) ;
}
static bool
F_19 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
unsigned char V_36 ;
F_20 (prefix, prefix_usage1) {
if ( ! F_21 ( V_36 , V_35 -> V_37 ) )
return false ;
}
return true ;
}
static bool
F_22 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
return ! memcmp ( V_34 , V_35 , sizeof( * V_34 ) ) ;
}
static bool
F_23 ( struct V_33 * V_38 )
{
struct V_33 V_39 = { { 0 } } ;
return F_22 ( V_38 , & V_39 ) ;
}
static void
F_24 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
memcpy ( V_34 , V_35 , sizeof( * V_34 ) ) ;
}
static void
F_25 ( struct V_33 * V_38 ,
unsigned char V_40 )
{
F_26 ( V_40 , V_38 -> V_37 ) ;
}
static void
F_27 ( struct V_33 * V_38 ,
unsigned char V_40 )
{
F_28 ( V_40 , V_38 -> V_37 ) ;
}
static struct V_41 * F_29 ( struct V_42 * V_43 ,
enum V_44 V_45 )
{
struct V_41 * V_46 ;
int V_19 ;
V_46 = F_30 ( sizeof( * V_46 ) , V_47 ) ;
if ( ! V_46 )
return F_31 ( - V_48 ) ;
V_19 = F_32 ( & V_46 -> V_49 , & V_50 ) ;
if ( V_19 )
goto V_51;
F_33 ( & V_46 -> V_52 ) ;
V_46 -> V_45 = V_45 ;
V_46 -> V_43 = V_43 ;
return V_46 ;
V_51:
F_34 ( V_46 ) ;
return F_31 ( V_19 ) ;
}
static void F_35 ( struct V_41 * V_46 )
{
F_18 ( ! F_36 ( & V_46 -> V_52 ) ) ;
F_18 ( V_46 -> V_53 ) ;
F_37 ( & V_46 -> V_49 ) ;
F_34 ( V_46 ) ;
}
static struct V_54 *
F_38 ( struct V_12 * V_12 )
{
static struct V_54 * V_53 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_12 -> V_56 . V_57 . V_58 ; V_55 ++ ) {
V_53 = & V_12 -> V_56 . V_57 . V_59 [ V_55 ] ;
if ( V_53 -> V_60 == 0 )
return V_53 ;
}
return NULL ;
}
static int F_39 ( struct V_12 * V_12 ,
struct V_54 * V_53 )
{
char V_61 [ V_62 ] ;
F_40 ( V_61 , true ,
(enum V_63 ) V_53 -> V_45 ,
V_53 -> V_64 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_65 ) , V_61 ) ;
}
static int F_41 ( struct V_12 * V_12 ,
struct V_54 * V_53 )
{
char V_61 [ V_62 ] ;
F_40 ( V_61 , false ,
(enum V_63 ) V_53 -> V_45 ,
V_53 -> V_64 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_65 ) , V_61 ) ;
}
static int
F_42 ( struct V_12 * V_12 ,
struct V_33 * V_38 ,
struct V_54 * V_53 )
{
char V_66 [ V_67 ] ;
T_3 V_68 = 0 ;
T_3 V_36 ;
T_3 V_69 = V_70 ;
F_20 (prefix, prefix_usage)
V_68 = V_36 ;
F_43 ( V_66 , V_68 , V_53 -> V_64 ) ;
F_20 (prefix, prefix_usage) {
if ( V_36 == 0 )
continue;
F_44 ( V_66 , V_36 , V_69 ,
V_70 ) ;
V_69 = V_36 ;
}
return F_9 ( V_12 -> V_20 , F_7 ( V_71 ) , V_66 ) ;
}
static struct V_54 *
F_45 ( struct V_12 * V_12 ,
struct V_33 * V_38 ,
enum V_44 V_45 )
{
struct V_54 * V_53 ;
int V_19 ;
V_53 = F_38 ( V_12 ) ;
if ( ! V_53 )
return F_31 ( - V_72 ) ;
V_53 -> V_45 = V_45 ;
V_19 = F_39 ( V_12 , V_53 ) ;
if ( V_19 )
return F_31 ( V_19 ) ;
V_19 = F_42 ( V_12 , V_38 ,
V_53 ) ;
if ( V_19 )
goto V_73;
memcpy ( & V_53 -> V_38 , V_38 ,
sizeof( V_53 -> V_38 ) ) ;
return V_53 ;
V_73:
F_41 ( V_12 , V_53 ) ;
return F_31 ( V_19 ) ;
}
static int F_46 ( struct V_12 * V_12 ,
struct V_54 * V_53 )
{
return F_41 ( V_12 , V_53 ) ;
}
static struct V_54 *
F_47 ( struct V_12 * V_12 ,
struct V_33 * V_38 ,
enum V_44 V_45 )
{
struct V_54 * V_53 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_12 -> V_56 . V_57 . V_58 ; V_55 ++ ) {
V_53 = & V_12 -> V_56 . V_57 . V_59 [ V_55 ] ;
if ( V_53 -> V_60 != 0 &&
V_53 -> V_45 == V_45 &&
F_22 ( & V_53 -> V_38 ,
V_38 ) )
goto V_74;
}
V_53 = F_45 ( V_12 , V_38 ,
V_45 ) ;
if ( F_48 ( V_53 ) )
return V_53 ;
V_74:
V_53 -> V_60 ++ ;
return V_53 ;
}
static int F_49 ( struct V_12 * V_12 ,
struct V_54 * V_53 )
{
if ( -- V_53 -> V_60 == 0 )
return F_46 ( V_12 , V_53 ) ;
return 0 ;
}
static int F_50 ( struct V_12 * V_12 )
{
struct V_54 * V_53 ;
T_2 V_75 ;
int V_55 ;
if ( ! F_51 ( V_12 -> V_20 , V_76 ) )
return - V_77 ;
V_75 = F_52 ( V_12 -> V_20 , V_76 ) ;
V_12 -> V_56 . V_57 . V_58 = V_75 - V_78 ;
V_12 -> V_56 . V_57 . V_59 = F_53 ( V_12 -> V_56 . V_57 . V_58 ,
sizeof( struct V_54 ) ,
V_47 ) ;
if ( ! V_12 -> V_56 . V_57 . V_59 )
return - V_48 ;
for ( V_55 = 0 ; V_55 < V_12 -> V_56 . V_57 . V_58 ; V_55 ++ ) {
V_53 = & V_12 -> V_56 . V_57 . V_59 [ V_55 ] ;
V_53 -> V_64 = V_55 + V_78 ;
}
return 0 ;
}
static void F_54 ( struct V_12 * V_12 )
{
F_34 ( V_12 -> V_56 . V_57 . V_59 ) ;
}
static bool F_55 ( const struct V_42 * V_43 )
{
return ! ! V_43 -> V_79 ;
}
static struct V_42 * F_56 ( struct V_12 * V_12 )
{
struct V_42 * V_43 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_80 ) ; V_55 ++ ) {
V_43 = & V_12 -> V_56 . V_81 [ V_55 ] ;
if ( ! F_55 ( V_43 ) )
return V_43 ;
}
return NULL ;
}
static int F_57 ( struct V_12 * V_12 ,
const struct V_41 * V_46 )
{
char V_82 [ V_83 ] ;
F_58 ( V_82 , V_46 -> V_43 -> V_64 ,
(enum V_63 ) V_46 -> V_45 ,
V_46 -> V_53 -> V_64 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_84 ) , V_82 ) ;
}
static int F_59 ( struct V_12 * V_12 ,
const struct V_41 * V_46 )
{
char V_82 [ V_83 ] ;
F_58 ( V_82 , V_46 -> V_43 -> V_64 ,
(enum V_63 ) V_46 -> V_45 , 0 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_84 ) , V_82 ) ;
}
static T_4 F_60 ( T_4 V_85 )
{
if ( V_85 == V_86 )
V_85 = V_87 ;
return V_85 ;
}
static struct V_42 * F_61 ( struct V_12 * V_12 ,
T_4 V_85 )
{
struct V_42 * V_43 ;
int V_55 ;
V_85 = F_60 ( V_85 ) ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_80 ) ; V_55 ++ ) {
V_43 = & V_12 -> V_56 . V_81 [ V_55 ] ;
if ( F_55 ( V_43 ) && V_43 -> V_85 == V_85 )
return V_43 ;
}
return NULL ;
}
static struct V_41 * F_62 ( const struct V_42 * V_43 ,
enum V_44 V_45 )
{
switch ( V_45 ) {
case V_88 :
return V_43 -> V_79 ;
case V_89 :
F_63 ( 1 ) ;
}
return NULL ;
}
static struct V_42 * F_64 ( struct V_12 * V_12 ,
T_4 V_85 )
{
struct V_42 * V_43 ;
V_43 = F_56 ( V_12 ) ;
if ( ! V_43 )
return F_31 ( - V_72 ) ;
V_43 -> V_79 = F_29 ( V_43 , V_88 ) ;
if ( F_48 ( V_43 -> V_79 ) )
return F_65 ( V_43 -> V_79 ) ;
V_43 -> V_85 = V_85 ;
return V_43 ;
}
static void F_66 ( struct V_42 * V_43 )
{
F_35 ( V_43 -> V_79 ) ;
V_43 -> V_79 = NULL ;
}
static int
F_67 ( struct V_12 * V_12 , struct V_41 * V_46 ,
struct V_33 * V_90 )
{
struct V_54 * V_53 = V_46 -> V_53 ;
struct V_54 * V_91 ;
int V_19 ;
if ( F_22 ( V_90 , & V_53 -> V_38 ) )
return 0 ;
V_91 = F_47 ( V_12 , V_90 ,
V_46 -> V_45 ) ;
if ( F_48 ( V_91 ) ) {
if ( F_19 ( V_90 ,
& V_53 -> V_38 ) )
return 0 ;
return F_68 ( V_91 ) ;
}
V_46 -> V_53 = V_91 ;
V_19 = F_57 ( V_12 , V_46 ) ;
if ( V_19 )
goto V_92;
F_49 ( V_12 , V_53 ) ;
return 0 ;
V_92:
V_46 -> V_53 = V_53 ;
F_49 ( V_12 , V_91 ) ;
return V_19 ;
}
static struct V_42 * F_69 ( struct V_12 * V_12 , T_4 V_85 )
{
struct V_42 * V_43 ;
V_85 = F_60 ( V_85 ) ;
V_43 = F_61 ( V_12 , V_85 ) ;
if ( ! V_43 )
V_43 = F_64 ( V_12 , V_85 ) ;
return V_43 ;
}
static void F_70 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_93 && F_36 ( & V_43 -> V_79 -> V_52 ) )
F_66 ( V_43 ) ;
}
static int F_71 ( struct V_12 * V_12 )
{
struct V_42 * V_43 ;
T_2 V_94 ;
int V_55 ;
if ( ! F_51 ( V_12 -> V_20 , V_80 ) )
return - V_77 ;
V_94 = F_52 ( V_12 -> V_20 , V_80 ) ;
V_12 -> V_56 . V_81 = F_53 ( V_94 , sizeof( struct V_42 ) ,
V_47 ) ;
if ( ! V_12 -> V_56 . V_81 )
return - V_48 ;
for ( V_55 = 0 ; V_55 < V_94 ; V_55 ++ ) {
V_43 = & V_12 -> V_56 . V_81 [ V_55 ] ;
V_43 -> V_64 = V_55 ;
}
return 0 ;
}
static void F_72 ( struct V_12 * V_12 )
{
F_73 () ;
F_74 ( V_12 ) ;
F_34 ( V_12 -> V_56 . V_81 ) ;
}
static struct V_95 *
F_75 ( struct V_12 * V_12 , struct V_96 * V_97 ,
T_1 V_2 )
{
struct V_95 * V_98 ;
V_98 = F_30 ( sizeof( * V_98 ) , V_47 ) ;
if ( ! V_98 )
return NULL ;
V_98 -> V_99 . V_97 = V_97 ;
V_98 -> V_2 = V_2 ;
F_33 ( & V_98 -> V_100 ) ;
return V_98 ;
}
static void F_76 ( struct V_95 * V_98 )
{
F_34 ( V_98 ) ;
}
static int
F_77 ( struct V_12 * V_12 ,
struct V_95 * V_98 )
{
return F_78 ( & V_12 -> V_56 . V_101 ,
& V_98 -> V_102 ,
V_103 ) ;
}
static void
F_79 ( struct V_12 * V_12 ,
struct V_95 * V_98 )
{
F_80 ( & V_12 -> V_56 . V_101 ,
& V_98 -> V_102 ,
V_103 ) ;
}
static struct V_95 *
F_81 ( struct V_12 * V_12 , struct V_96 * V_97 )
{
struct V_95 * V_98 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_82 ( V_12 , V_97 -> V_104 ) ;
if ( ! V_2 )
return F_31 ( - V_26 ) ;
V_98 = F_75 ( V_12 , V_97 , V_2 -> V_13 ) ;
if ( ! V_98 )
return F_31 ( - V_48 ) ;
V_19 = F_77 ( V_12 , V_98 ) ;
if ( V_19 )
goto V_105;
F_83 ( & V_98 -> V_106 , & V_2 -> V_107 ) ;
return V_98 ;
V_105:
F_76 ( V_98 ) ;
return F_31 ( V_19 ) ;
}
static void
F_84 ( struct V_12 * V_12 ,
struct V_95 * V_98 )
{
F_85 ( & V_98 -> V_106 ) ;
F_79 ( V_12 , V_98 ) ;
F_76 ( V_98 ) ;
}
static struct V_95 *
F_86 ( struct V_12 * V_12 , struct V_96 * V_97 )
{
struct V_108 V_99 ;
V_99 . V_97 = V_97 ;
return F_87 ( & V_12 -> V_56 . V_101 ,
& V_99 , V_103 ) ;
}
static void
F_88 ( struct V_12 * V_12 )
{
unsigned long V_109 = F_89 ( & V_110 . V_111 , V_112 ) ;
V_12 -> V_56 . V_113 . V_109 = F_90 ( V_109 ) ;
}
static void F_91 ( struct V_12 * V_12 ,
char * V_114 ,
int V_115 )
{
struct V_116 * V_104 ;
struct V_96 * V_97 ;
T_5 V_117 ;
T_4 V_118 ;
T_1 V_2 ;
F_92 ( V_114 , V_115 , & V_2 , & V_118 ) ;
if ( ! V_12 -> V_119 [ V_2 ] ) {
F_93 ( V_12 -> V_120 -> V_104 , L_1 ) ;
return;
}
V_117 = F_94 ( V_118 ) ;
V_104 = V_12 -> V_119 [ V_2 ] -> V_104 ;
V_97 = F_95 ( & V_110 , & V_117 , V_104 ) ;
if ( ! V_97 ) {
F_96 ( V_104 , L_2 ,
& V_118 ) ;
return;
}
F_97 ( V_104 , L_3 , & V_118 ) ;
F_98 ( V_97 , NULL ) ;
F_99 ( V_97 ) ;
}
static void F_100 ( struct V_12 * V_12 ,
char * V_114 ,
int V_121 )
{
T_3 V_122 ;
int V_55 ;
V_122 = F_101 ( V_114 ,
V_121 ) ;
V_122 ++ ;
for ( V_55 = 0 ; V_55 < V_122 ; V_55 ++ ) {
int V_115 ;
V_115 = V_121 * V_123 + V_55 ;
F_91 ( V_12 , V_114 ,
V_115 ) ;
}
}
static void F_102 ( struct V_12 * V_12 ,
char * V_114 , int V_121 )
{
switch ( F_103 ( V_114 , V_121 ) ) {
case V_124 :
F_100 ( V_12 , V_114 ,
V_121 ) ;
break;
case V_125 :
F_104 ( 1 ) ;
break;
}
}
static bool F_105 ( char * V_114 )
{
T_3 V_126 , V_127 , V_122 ;
V_126 = F_106 ( V_114 ) ;
V_127 = V_126 - 1 ;
if ( V_126 < V_128 )
return false ;
if ( F_103 ( V_114 , V_127 ) ==
V_125 )
return true ;
V_122 = F_101 ( V_114 ,
V_127 ) ;
if ( ++ V_122 == V_123 )
return true ;
return false ;
}
static int F_107 ( struct V_12 * V_12 )
{
char * V_114 ;
T_3 V_126 ;
int V_55 , V_19 ;
V_114 = F_108 ( V_129 , V_47 ) ;
if ( ! V_114 )
return - V_48 ;
F_109 () ;
do {
F_110 ( V_114 , V_124 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_130 ) ,
V_114 ) ;
if ( V_19 ) {
F_93 ( V_12 -> V_120 -> V_104 , L_4 ) ;
break;
}
V_126 = F_106 ( V_114 ) ;
for ( V_55 = 0 ; V_55 < V_126 ; V_55 ++ )
F_102 ( V_12 , V_114 ,
V_55 ) ;
} while ( F_105 ( V_114 ) );
F_111 () ;
F_34 ( V_114 ) ;
return V_19 ;
}
static void F_112 ( struct V_12 * V_12 )
{
struct V_95 * V_98 ;
F_109 () ;
F_113 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node)
F_98 ( V_98 -> V_99 . V_97 , NULL ) ;
F_111 () ;
}
static void
F_114 ( struct V_12 * V_12 )
{
unsigned long V_109 = V_12 -> V_56 . V_113 . V_109 ;
F_115 ( & V_12 -> V_56 . V_113 . V_131 ,
F_116 ( V_109 ) ) ;
}
static void F_117 ( struct V_132 * V_133 )
{
struct V_12 * V_12 = F_118 ( V_133 , struct V_12 ,
V_56 . V_113 . V_131 . V_133 ) ;
int V_19 ;
V_19 = F_107 ( V_12 ) ;
if ( V_19 )
F_119 ( V_12 -> V_120 -> V_104 , L_5 ) ;
F_112 ( V_12 ) ;
F_114 ( V_12 ) ;
}
static void F_120 ( struct V_132 * V_133 )
{
struct V_95 * V_98 ;
struct V_12 * V_12 = F_118 ( V_133 , struct V_12 ,
V_56 . V_134 . V_133 ) ;
F_109 () ;
F_113 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node)
if ( ! V_98 -> V_135 )
F_98 ( V_98 -> V_99 . V_97 , NULL ) ;
F_111 () ;
F_115 ( & V_12 -> V_56 . V_134 ,
V_136 ) ;
}
static enum V_137 F_121 ( bool V_138 )
{
return V_138 ? V_139 :
V_140 ;
}
static void
F_122 ( struct V_12 * V_12 ,
struct V_95 * V_98 ,
enum V_137 V_141 )
{
struct V_96 * V_97 = V_98 -> V_99 . V_97 ;
T_4 V_118 = F_123 ( * ( ( T_5 * ) V_97 -> V_142 ) ) ;
char V_143 [ V_144 ] ;
F_124 ( V_143 , V_141 , V_98 -> V_2 , V_98 -> V_145 ,
V_118 ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_146 ) , V_143 ) ;
}
static void
F_125 ( struct V_12 * V_12 ,
struct V_95 * V_98 ,
bool V_138 )
{
if ( ! V_138 && ! V_98 -> V_135 )
return;
V_98 -> V_135 = V_138 ;
if ( V_98 -> V_99 . V_97 -> V_147 == & V_110 )
F_122 ( V_12 , V_98 ,
F_121 ( V_138 ) ) ;
else
F_104 ( 1 ) ;
}
static void F_126 ( struct V_132 * V_133 )
{
struct V_148 * V_149 =
F_118 ( V_133 , struct V_148 , V_133 ) ;
struct V_12 * V_12 = V_149 -> V_12 ;
struct V_95 * V_98 ;
struct V_96 * V_97 = V_149 -> V_97 ;
unsigned char V_145 [ V_150 ] ;
bool V_151 ;
T_3 V_152 , V_153 ;
F_127 ( & V_97 -> V_154 ) ;
memcpy ( V_145 , V_97 -> V_145 , V_150 ) ;
V_152 = V_97 -> V_152 ;
V_153 = V_97 -> V_153 ;
F_128 ( & V_97 -> V_154 ) ;
F_109 () ;
V_151 = V_152 & V_155 && ! V_153 ;
V_98 = F_86 ( V_12 , V_97 ) ;
if ( ! V_151 && ! V_98 )
goto V_156;
if ( ! V_98 ) {
V_98 = F_81 ( V_12 , V_97 ) ;
if ( F_48 ( V_98 ) )
goto V_156;
}
memcpy ( V_98 -> V_145 , V_145 , V_150 ) ;
F_125 ( V_12 , V_98 , V_151 ) ;
F_129 ( V_12 , V_98 , ! V_151 ) ;
if ( ! V_98 -> V_135 && F_36 ( & V_98 -> V_100 ) )
F_84 ( V_12 , V_98 ) ;
V_156:
F_111 () ;
F_99 ( V_97 ) ;
F_34 ( V_149 ) ;
}
int F_130 ( struct V_157 * V_158 ,
unsigned long V_159 , void * V_160 )
{
struct V_148 * V_149 ;
struct V_161 * V_161 ;
struct V_12 * V_12 ;
unsigned long V_109 ;
struct V_162 * V_163 ;
struct V_96 * V_97 ;
switch ( V_159 ) {
case V_164 :
V_163 = V_160 ;
if ( ! V_163 -> V_104 || V_163 -> V_147 != & V_110 )
return V_165 ;
V_161 = F_131 ( V_163 -> V_104 ) ;
if ( ! V_161 )
return V_165 ;
V_12 = V_161 -> V_12 ;
V_109 = F_90 ( F_89 ( V_163 , V_112 ) ) ;
V_12 -> V_56 . V_113 . V_109 = V_109 ;
F_132 ( V_161 ) ;
break;
case V_166 :
V_97 = V_160 ;
if ( V_97 -> V_147 != & V_110 )
return V_165 ;
V_161 = F_131 ( V_97 -> V_104 ) ;
if ( ! V_161 )
return V_165 ;
V_149 = F_30 ( sizeof( * V_149 ) , V_167 ) ;
if ( ! V_149 ) {
F_132 ( V_161 ) ;
return V_168 ;
}
F_133 ( & V_149 -> V_133 , F_126 ) ;
V_149 -> V_12 = V_161 -> V_12 ;
V_149 -> V_97 = V_97 ;
F_134 ( V_97 ) ;
F_135 ( & V_149 -> V_133 ) ;
F_132 ( V_161 ) ;
break;
}
return V_165 ;
}
static int F_136 ( struct V_12 * V_12 )
{
int V_19 ;
V_19 = F_32 ( & V_12 -> V_56 . V_101 ,
& V_103 ) ;
if ( V_19 )
return V_19 ;
F_88 ( V_12 ) ;
F_137 ( & V_12 -> V_56 . V_113 . V_131 ,
F_117 ) ;
F_137 ( & V_12 -> V_56 . V_134 ,
F_120 ) ;
F_115 ( & V_12 -> V_56 . V_113 . V_131 , 0 ) ;
F_115 ( & V_12 -> V_56 . V_134 , 0 ) ;
return 0 ;
}
static void F_138 ( struct V_12 * V_12 )
{
F_139 ( & V_12 -> V_56 . V_113 . V_131 ) ;
F_139 ( & V_12 -> V_56 . V_134 ) ;
F_37 ( & V_12 -> V_56 . V_101 ) ;
}
static int F_140 ( struct V_12 * V_12 ,
const struct V_1 * V_2 )
{
char V_143 [ V_144 ] ;
F_141 ( V_143 , V_169 ,
V_2 -> V_13 , V_2 -> V_170 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_146 ) , V_143 ) ;
}
static void F_142 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_95 * V_98 , * V_171 ;
F_140 ( V_12 , V_2 ) ;
F_143 (neigh_entry, tmp, &rif->neigh_list,
rif_list_node)
F_84 ( V_12 , V_98 ) ;
}
static int F_144 ( struct V_12 * V_12 ,
struct V_172 * V_173 )
{
return F_78 ( & V_12 -> V_56 . V_174 ,
& V_173 -> V_102 ,
V_175 ) ;
}
static void F_145 ( struct V_12 * V_12 ,
struct V_172 * V_173 )
{
F_80 ( & V_12 -> V_56 . V_174 ,
& V_173 -> V_102 ,
V_175 ) ;
}
static struct V_172 *
F_146 ( struct V_12 * V_12 ,
struct V_176 V_99 )
{
return F_87 ( & V_12 -> V_56 . V_174 , & V_99 ,
V_175 ) ;
}
static int F_147 ( struct V_12 * V_12 ,
struct V_177 * V_178 )
{
return F_78 ( & V_12 -> V_56 . V_179 ,
& V_178 -> V_102 , V_180 ) ;
}
static void F_148 ( struct V_12 * V_12 ,
struct V_177 * V_178 )
{
F_80 ( & V_12 -> V_56 . V_179 , & V_178 -> V_102 ,
V_180 ) ;
}
static struct V_177 *
F_149 ( struct V_12 * V_12 ,
struct V_181 V_99 )
{
return F_87 ( & V_12 -> V_56 . V_179 , & V_99 ,
V_180 ) ;
}
static int F_150 ( struct V_12 * V_12 ,
const struct V_41 * V_46 ,
T_4 V_182 , T_1 V_183 ,
T_4 V_184 ,
T_1 V_185 )
{
char V_186 [ V_187 ] ;
F_151 ( V_186 ,
(enum V_63 ) V_46 -> V_45 ,
V_46 -> V_43 -> V_64 , V_182 , V_183 , V_184 ,
V_185 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_188 ) , V_186 ) ;
}
static int F_152 ( struct V_12 * V_12 ,
struct V_172 * V_173 ,
T_4 V_189 , T_1 V_190 )
{
struct V_191 * V_192 ;
struct V_41 * V_46 = NULL ;
int V_19 ;
F_113 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_46 == V_192 -> V_193 -> V_46 )
continue;
V_46 = V_192 -> V_193 -> V_46 ;
V_19 = F_150 ( V_12 , V_46 ,
V_189 ,
V_190 ,
V_173 -> V_182 ,
V_173 -> V_183 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_153 ( struct V_12 * V_12 , T_4 V_182 ,
struct V_177 * V_178 )
{
struct V_95 * V_98 = V_178 -> V_98 ;
char V_194 [ V_195 ] ;
F_154 ( V_194 , V_196 ,
true , V_182 , V_98 -> V_2 ) ;
F_155 ( V_194 , V_98 -> V_145 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_197 ) , V_194 ) ;
}
static int
F_156 ( struct V_12 * V_12 ,
struct V_172 * V_173 ,
bool V_198 )
{
T_4 V_182 = V_173 -> V_182 ;
struct V_177 * V_178 ;
int V_55 ;
int V_19 ;
for ( V_55 = 0 ; V_55 < V_173 -> V_199 ; V_55 ++ ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
if ( ! V_178 -> V_201 ) {
V_178 -> V_202 = 0 ;
continue;
}
if ( V_178 -> V_203 || V_198 ) {
V_19 = F_153 ( V_12 ,
V_182 , V_178 ) ;
if ( V_19 )
return V_19 ;
V_178 -> V_203 = 0 ;
V_178 -> V_202 = 1 ;
}
V_182 ++ ;
}
return 0 ;
}
static int
F_157 ( struct V_12 * V_12 ,
struct V_172 * V_173 )
{
struct V_191 * V_192 ;
int V_19 ;
F_113 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
V_19 = F_158 ( V_12 , V_192 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void
F_159 ( struct V_12 * V_12 ,
struct V_172 * V_173 )
{
struct V_177 * V_178 ;
bool V_204 = false ;
T_4 V_182 ;
T_1 V_183 = 0 ;
bool V_205 ;
T_4 V_189 ;
T_1 V_190 ;
int V_55 ;
int V_19 ;
if ( ! V_173 -> V_206 ) {
F_157 ( V_12 , V_173 ) ;
return;
}
for ( V_55 = 0 ; V_55 < V_173 -> V_199 ; V_55 ++ ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
if ( V_178 -> V_201 ^ V_178 -> V_202 ) {
V_204 = true ;
if ( V_178 -> V_201 )
V_178 -> V_203 = 1 ;
}
if ( V_178 -> V_201 )
V_183 ++ ;
}
if ( ! V_204 ) {
V_19 = F_156 ( V_12 , V_173 ,
false ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_6 ) ;
goto V_207;
}
return;
}
if ( ! V_183 )
goto V_207;
V_19 = F_161 ( V_12 , V_183 , & V_182 ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_7 ) ;
goto V_207;
}
V_205 = V_173 -> V_208 ;
V_189 = V_173 -> V_182 ;
V_190 = V_173 -> V_183 ;
V_173 -> V_208 = 1 ;
V_173 -> V_182 = V_182 ;
V_173 -> V_183 = V_183 ;
V_19 = F_156 ( V_12 , V_173 , true ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_6 ) ;
goto V_207;
}
if ( ! V_205 ) {
V_19 = F_157 ( V_12 , V_173 ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_8 ) ;
goto V_207;
}
return;
}
V_19 = F_152 ( V_12 , V_173 ,
V_189 , V_190 ) ;
F_162 ( V_12 , V_189 ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_9 ) ;
goto V_207;
}
return;
V_207:
V_205 = V_173 -> V_208 ;
V_173 -> V_208 = 0 ;
for ( V_55 = 0 ; V_55 < V_173 -> V_199 ; V_55 ++ ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
V_178 -> V_202 = 0 ;
}
V_19 = F_157 ( V_12 , V_173 ) ;
if ( V_19 )
F_160 ( V_12 -> V_120 -> V_104 , L_10 ) ;
if ( V_205 )
F_162 ( V_12 , V_173 -> V_182 ) ;
}
static void F_163 ( struct V_177 * V_178 ,
bool V_209 )
{
if ( ! V_209 && ! V_178 -> V_201 )
V_178 -> V_201 = 1 ;
else if ( V_209 && V_178 -> V_202 )
V_178 -> V_201 = 0 ;
V_178 -> V_203 = 1 ;
}
static void
F_129 ( struct V_12 * V_12 ,
struct V_95 * V_98 ,
bool V_209 )
{
struct V_177 * V_178 ;
F_113 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_163 ( V_178 , V_209 ) ;
F_159 ( V_12 , V_178 -> V_173 ) ;
}
}
static void F_164 ( struct V_177 * V_178 ,
struct V_1 * V_2 )
{
if ( V_178 -> V_2 )
return;
V_178 -> V_2 = V_2 ;
F_83 ( & V_178 -> V_106 , & V_2 -> V_100 ) ;
}
static void F_165 ( struct V_177 * V_178 )
{
if ( ! V_178 -> V_2 )
return;
F_85 ( & V_178 -> V_106 ) ;
V_178 -> V_2 = NULL ;
}
static int F_166 ( struct V_12 * V_12 ,
struct V_177 * V_178 )
{
struct V_95 * V_98 ;
struct V_210 * V_210 = V_178 -> V_99 . V_210 ;
struct V_96 * V_97 ;
T_3 V_152 , V_153 ;
int V_19 ;
if ( ! V_178 -> V_173 -> V_206 || V_178 -> V_98 )
return 0 ;
V_97 = F_95 ( & V_110 , & V_210 -> V_211 , V_210 -> V_212 ) ;
if ( ! V_97 ) {
V_97 = F_167 ( & V_110 , & V_210 -> V_211 , V_210 -> V_212 ) ;
if ( F_48 ( V_97 ) )
return F_68 ( V_97 ) ;
F_98 ( V_97 , NULL ) ;
}
V_98 = F_86 ( V_12 , V_97 ) ;
if ( ! V_98 ) {
V_98 = F_81 ( V_12 , V_97 ) ;
if ( F_48 ( V_98 ) ) {
V_19 = - V_26 ;
goto V_213;
}
}
if ( F_36 ( & V_98 -> V_100 ) )
F_168 ( & V_98 -> V_214 ,
& V_12 -> V_56 . V_215 ) ;
V_178 -> V_98 = V_98 ;
F_168 ( & V_178 -> V_216 , & V_98 -> V_100 ) ;
F_127 ( & V_97 -> V_154 ) ;
V_152 = V_97 -> V_152 ;
V_153 = V_97 -> V_153 ;
F_128 ( & V_97 -> V_154 ) ;
F_163 ( V_178 , ! ( V_152 & V_155 && ! V_153 ) ) ;
return 0 ;
V_213:
F_99 ( V_97 ) ;
return V_19 ;
}
static void F_169 ( struct V_12 * V_12 ,
struct V_177 * V_178 )
{
struct V_95 * V_98 = V_178 -> V_98 ;
struct V_96 * V_97 ;
if ( ! V_98 )
return;
V_97 = V_98 -> V_99 . V_97 ;
F_163 ( V_178 , true ) ;
F_85 ( & V_178 -> V_216 ) ;
V_178 -> V_98 = NULL ;
if ( F_36 ( & V_98 -> V_100 ) )
F_85 ( & V_98 -> V_214 ) ;
if ( ! V_98 -> V_135 && F_36 ( & V_98 -> V_100 ) )
F_84 ( V_12 , V_98 ) ;
F_99 ( V_97 ) ;
}
static int F_170 ( struct V_12 * V_12 ,
struct V_172 * V_173 ,
struct V_177 * V_178 ,
struct V_210 * V_210 )
{
struct V_116 * V_104 = V_210 -> V_212 ;
struct V_217 * V_218 ;
struct V_1 * V_2 ;
int V_19 ;
V_178 -> V_173 = V_173 ;
V_178 -> V_99 . V_210 = V_210 ;
V_19 = F_147 ( V_12 , V_178 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_104 )
return 0 ;
V_218 = F_171 ( V_104 ) ;
if ( V_218 && F_172 ( V_218 ) &&
V_210 -> V_219 & V_220 )
return 0 ;
V_2 = F_82 ( V_12 , V_104 ) ;
if ( ! V_2 )
return 0 ;
F_164 ( V_178 , V_2 ) ;
V_19 = F_166 ( V_12 , V_178 ) ;
if ( V_19 )
goto V_221;
return 0 ;
V_221:
F_148 ( V_12 , V_178 ) ;
return V_19 ;
}
static void F_173 ( struct V_12 * V_12 ,
struct V_177 * V_178 )
{
F_169 ( V_12 , V_178 ) ;
F_165 ( V_178 ) ;
F_148 ( V_12 , V_178 ) ;
}
static void F_174 ( struct V_12 * V_12 ,
unsigned long V_159 , struct V_210 * V_210 )
{
struct V_181 V_99 ;
struct V_177 * V_178 ;
struct V_1 * V_2 ;
if ( V_12 -> V_56 . V_222 )
return;
V_99 . V_210 = V_210 ;
V_178 = F_149 ( V_12 , V_99 ) ;
if ( F_104 ( ! V_178 ) )
return;
V_2 = F_82 ( V_12 , V_210 -> V_212 ) ;
if ( ! V_2 )
return;
switch ( V_159 ) {
case V_223 :
F_164 ( V_178 , V_2 ) ;
F_166 ( V_12 , V_178 ) ;
break;
case V_224 :
F_169 ( V_12 , V_178 ) ;
F_165 ( V_178 ) ;
break;
}
F_159 ( V_12 , V_178 -> V_173 ) ;
}
static void F_175 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_177 * V_178 , * V_171 ;
F_143 (nh, tmp, &rif->nexthop_list, rif_list_node) {
F_169 ( V_12 , V_178 ) ;
F_165 ( V_178 ) ;
F_159 ( V_12 , V_178 -> V_173 ) ;
}
}
static struct V_172 *
F_176 ( struct V_12 * V_12 , struct V_225 * V_226 )
{
struct V_172 * V_173 ;
struct V_177 * V_178 ;
struct V_210 * V_210 ;
T_6 V_227 ;
int V_55 ;
int V_19 ;
V_227 = sizeof( * V_173 ) +
V_226 -> V_228 * sizeof( struct V_177 ) ;
V_173 = F_30 ( V_227 , V_47 ) ;
if ( ! V_173 )
return F_31 ( - V_48 ) ;
F_33 ( & V_173 -> V_229 ) ;
V_173 -> V_206 = V_226 -> V_210 -> V_230 == V_231 ;
V_173 -> V_199 = V_226 -> V_228 ;
V_173 -> V_99 . V_226 = V_226 ;
for ( V_55 = 0 ; V_55 < V_173 -> V_199 ; V_55 ++ ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
V_210 = & V_226 -> V_210 [ V_55 ] ;
V_19 = F_170 ( V_12 , V_173 , V_178 , V_210 ) ;
if ( V_19 )
goto V_232;
}
V_19 = F_144 ( V_12 , V_173 ) ;
if ( V_19 )
goto V_233;
F_159 ( V_12 , V_173 ) ;
return V_173 ;
V_233:
V_232:
for ( V_55 -- ; V_55 >= 0 ; V_55 -- ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
F_173 ( V_12 , V_178 ) ;
}
F_34 ( V_173 ) ;
return F_31 ( V_19 ) ;
}
static void
F_177 ( struct V_12 * V_12 ,
struct V_172 * V_173 )
{
struct V_177 * V_178 ;
int V_55 ;
F_145 ( V_12 , V_173 ) ;
for ( V_55 = 0 ; V_55 < V_173 -> V_199 ; V_55 ++ ) {
V_178 = & V_173 -> V_200 [ V_55 ] ;
F_173 ( V_12 , V_178 ) ;
}
F_159 ( V_12 , V_173 ) ;
F_104 ( V_173 -> V_208 ) ;
F_34 ( V_173 ) ;
}
static int F_178 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
struct V_225 * V_226 )
{
struct V_176 V_99 ;
struct V_172 * V_173 ;
V_99 . V_226 = V_226 ;
V_173 = F_146 ( V_12 , V_99 ) ;
if ( ! V_173 ) {
V_173 = F_176 ( V_12 , V_226 ) ;
if ( F_48 ( V_173 ) )
return F_68 ( V_173 ) ;
}
F_168 ( & V_192 -> V_234 , & V_173 -> V_229 ) ;
V_192 -> V_235 = V_173 ;
return 0 ;
}
static void F_179 ( struct V_12 * V_12 ,
struct V_191 * V_192 )
{
struct V_172 * V_173 = V_192 -> V_235 ;
F_85 ( & V_192 -> V_234 ) ;
if ( ! F_36 ( & V_173 -> V_229 ) )
return;
F_177 ( V_12 , V_173 ) ;
}
static bool
F_180 ( const struct V_191 * V_192 )
{
struct V_172 * V_235 = V_192 -> V_235 ;
if ( V_192 -> V_236 . V_237 )
return false ;
switch ( V_192 -> type ) {
case V_238 :
return ! ! V_235 -> V_208 ;
case V_239 :
return ! ! V_235 -> V_240 ;
default:
return false ;
}
}
static void F_181 ( struct V_191 * V_192 )
{
V_192 -> V_202 = true ;
switch ( V_192 -> V_193 -> V_46 -> V_45 ) {
case V_88 :
F_182 ( V_192 -> V_235 -> V_99 . V_226 ) ;
break;
case V_89 :
F_104 ( 1 ) ;
}
}
static void
F_183 ( struct V_191 * V_192 )
{
switch ( V_192 -> V_193 -> V_46 -> V_45 ) {
case V_88 :
F_184 ( V_192 -> V_235 -> V_99 . V_226 ) ;
break;
case V_89 :
F_104 ( 1 ) ;
}
V_192 -> V_202 = false ;
}
static void
F_185 ( struct V_191 * V_192 ,
enum V_241 V_141 , int V_19 )
{
switch ( V_141 ) {
case V_242 :
if ( ! V_192 -> V_202 )
return;
return F_183 ( V_192 ) ;
case V_243 :
if ( V_19 )
return;
if ( F_180 ( V_192 ) &&
! V_192 -> V_202 )
F_181 ( V_192 ) ;
else if ( ! F_180 ( V_192 ) &&
V_192 -> V_202 )
F_183 ( V_192 ) ;
return;
default:
return;
}
}
static int F_186 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
enum V_241 V_141 )
{
char V_244 [ V_245 ] ;
struct V_41 * V_46 = V_192 -> V_193 -> V_46 ;
T_4 * V_246 = ( T_4 * ) V_192 -> V_193 -> V_99 . V_170 ;
enum V_247 V_248 ;
T_1 V_249 = 0 ;
T_4 V_250 = 0 ;
T_1 V_183 = 0 ;
if ( F_180 ( V_192 ) ) {
V_248 = V_251 ;
V_250 = V_192 -> V_235 -> V_182 ;
V_183 = V_192 -> V_235 -> V_183 ;
} else {
V_248 = V_252 ;
V_249 = V_253 ;
}
F_187 ( V_244 ,
(enum V_63 ) V_46 -> V_45 , V_141 ,
V_46 -> V_43 -> V_64 , V_192 -> V_193 -> V_99 . V_40 ,
* V_246 ) ;
F_188 ( V_244 , V_248 , V_249 ,
V_250 , V_183 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_254 ) , V_244 ) ;
}
static int F_189 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
enum V_241 V_141 )
{
struct V_1 * V_2 = V_192 -> V_235 -> V_240 ;
struct V_41 * V_46 = V_192 -> V_193 -> V_46 ;
enum V_247 V_248 ;
char V_244 [ V_245 ] ;
T_4 * V_246 = ( T_4 * ) V_192 -> V_193 -> V_99 . V_170 ;
T_1 V_249 = 0 ;
T_1 V_13 = 0 ;
if ( F_180 ( V_192 ) ) {
V_248 = V_251 ;
V_13 = V_2 -> V_13 ;
} else {
V_248 = V_252 ;
V_249 = V_253 ;
}
F_187 ( V_244 ,
(enum V_63 ) V_46 -> V_45 , V_141 ,
V_46 -> V_43 -> V_64 , V_192 -> V_193 -> V_99 . V_40 ,
* V_246 ) ;
F_190 ( V_244 , V_248 , V_249 ,
V_13 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_254 ) , V_244 ) ;
}
static int F_191 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
enum V_241 V_141 )
{
struct V_41 * V_46 = V_192 -> V_193 -> V_46 ;
char V_244 [ V_245 ] ;
T_4 * V_246 = ( T_4 * ) V_192 -> V_193 -> V_99 . V_170 ;
F_187 ( V_244 ,
(enum V_63 ) V_46 -> V_45 , V_141 ,
V_46 -> V_43 -> V_64 , V_192 -> V_193 -> V_99 . V_40 ,
* V_246 ) ;
F_192 ( V_244 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_254 ) , V_244 ) ;
}
static int F_193 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
enum V_241 V_141 )
{
switch ( V_192 -> type ) {
case V_238 :
return F_186 ( V_12 , V_192 , V_141 ) ;
case V_239 :
return F_189 ( V_12 , V_192 , V_141 ) ;
case V_255 :
return F_191 ( V_12 , V_192 , V_141 ) ;
}
return - V_26 ;
}
static int F_194 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
enum V_241 V_141 )
{
int V_19 = - V_26 ;
switch ( V_192 -> V_193 -> V_46 -> V_45 ) {
case V_88 :
V_19 = F_193 ( V_12 , V_192 , V_141 ) ;
break;
case V_89 :
return V_19 ;
}
F_185 ( V_192 , V_141 , V_19 ) ;
return V_19 ;
}
static int F_158 ( struct V_12 * V_12 ,
struct V_191 * V_192 )
{
return F_194 ( V_12 , V_192 ,
V_243 ) ;
}
static int F_195 ( struct V_12 * V_12 ,
struct V_191 * V_192 )
{
return F_194 ( V_12 , V_192 ,
V_242 ) ;
}
static int
F_196 ( struct V_12 * V_12 ,
const struct V_256 * V_257 ,
struct V_191 * V_192 )
{
struct V_225 * V_226 = V_257 -> V_226 ;
switch ( V_257 -> type ) {
case V_258 :
case V_259 :
V_192 -> type = V_255 ;
return 0 ;
case V_260 :
case V_261 :
case V_262 :
V_192 -> type = V_239 ;
return 0 ;
case V_263 :
if ( V_226 -> V_210 -> V_230 != V_231 )
V_192 -> type = V_239 ;
else
V_192 -> type = V_238 ;
return 0 ;
default:
return - V_26 ;
}
}
static struct V_191 *
F_197 ( struct V_12 * V_12 ,
struct V_264 * V_193 ,
const struct V_256 * V_257 )
{
struct V_191 * V_192 ;
int V_19 ;
V_192 = F_30 ( sizeof( * V_192 ) , V_47 ) ;
if ( ! V_192 ) {
V_19 = - V_48 ;
goto V_265;
}
V_19 = F_196 ( V_12 , V_257 , V_192 ) ;
if ( V_19 )
goto V_266;
V_19 = F_178 ( V_12 , V_192 , V_257 -> V_226 ) ;
if ( V_19 )
goto V_267;
V_192 -> V_236 . V_268 = V_257 -> V_226 -> V_269 ;
V_192 -> V_236 . V_85 = V_257 -> V_85 ;
V_192 -> V_236 . type = V_257 -> type ;
V_192 -> V_236 . V_237 = V_257 -> V_237 ;
V_192 -> V_193 = V_193 ;
return V_192 ;
V_267:
V_266:
F_34 ( V_192 ) ;
V_265:
return F_31 ( V_19 ) ;
}
static void F_198 ( struct V_12 * V_12 ,
struct V_191 * V_192 )
{
F_179 ( V_12 , V_192 ) ;
F_34 ( V_192 ) ;
}
static struct V_191 *
F_199 ( struct V_12 * V_12 ,
const struct V_256 * V_257 )
{
struct V_191 * V_192 ;
struct V_264 * V_193 ;
V_193 = F_200 ( V_12 , V_257 ) ;
if ( F_48 ( V_193 ) )
return NULL ;
F_113 (fib_entry, &fib_node->entry_list, list) {
if ( V_192 -> V_236 . V_85 == V_257 -> V_85 &&
V_192 -> V_236 . V_237 == V_257 -> V_237 &&
V_192 -> V_236 . type == V_257 -> type &&
V_192 -> V_235 -> V_99 . V_226 == V_257 -> V_226 ) {
return V_192 ;
}
}
return NULL ;
}
static int F_201 ( struct V_41 * V_46 ,
struct V_264 * V_193 )
{
return F_78 ( & V_46 -> V_49 , & V_193 -> V_102 ,
V_50 ) ;
}
static void F_202 ( struct V_41 * V_46 ,
struct V_264 * V_193 )
{
F_80 ( & V_46 -> V_49 , & V_193 -> V_102 ,
V_50 ) ;
}
static struct V_264 *
F_203 ( struct V_41 * V_46 , const void * V_170 ,
T_6 V_270 , unsigned char V_40 )
{
struct V_271 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
memcpy ( V_99 . V_170 , V_170 , V_270 ) ;
V_99 . V_40 = V_40 ;
return F_87 ( & V_46 -> V_49 , & V_99 , V_50 ) ;
}
static struct V_264 *
F_204 ( struct V_41 * V_46 , const void * V_170 ,
T_6 V_270 , unsigned char V_40 )
{
struct V_264 * V_193 ;
V_193 = F_30 ( sizeof( * V_193 ) , V_47 ) ;
if ( ! V_193 )
return NULL ;
F_33 ( & V_193 -> V_272 ) ;
F_83 ( & V_193 -> V_273 , & V_46 -> V_52 ) ;
memcpy ( V_193 -> V_99 . V_170 , V_170 , V_270 ) ;
V_193 -> V_99 . V_40 = V_40 ;
return V_193 ;
}
static void F_205 ( struct V_264 * V_193 )
{
F_85 ( & V_193 -> V_273 ) ;
F_18 ( ! F_36 ( & V_193 -> V_272 ) ) ;
F_34 ( V_193 ) ;
}
static bool
F_206 ( const struct V_264 * V_193 ,
const struct V_191 * V_192 )
{
return F_207 ( & V_193 -> V_272 ,
struct V_191 , V_273 ) == V_192 ;
}
static void F_208 ( struct V_264 * V_193 )
{
unsigned char V_40 = V_193 -> V_99 . V_40 ;
struct V_41 * V_46 = V_193 -> V_46 ;
if ( V_46 -> V_274 [ V_40 ] ++ == 0 )
F_25 ( & V_46 -> V_38 , V_40 ) ;
}
static void F_209 ( struct V_264 * V_193 )
{
unsigned char V_40 = V_193 -> V_99 . V_40 ;
struct V_41 * V_46 = V_193 -> V_46 ;
if ( -- V_46 -> V_274 [ V_40 ] == 0 )
F_27 ( & V_46 -> V_38 , V_40 ) ;
}
static int F_210 ( struct V_12 * V_12 ,
struct V_264 * V_193 ,
struct V_41 * V_46 )
{
struct V_33 V_90 ;
struct V_54 * V_53 ;
int V_19 ;
V_19 = F_201 ( V_46 , V_193 ) ;
if ( V_19 )
return V_19 ;
V_193 -> V_46 = V_46 ;
F_24 ( & V_90 , & V_46 -> V_38 ) ;
F_25 ( & V_90 , V_193 -> V_99 . V_40 ) ;
if ( ! F_23 ( & V_46 -> V_38 ) ) {
V_19 = F_67 ( V_12 , V_46 ,
& V_90 ) ;
if ( V_19 )
goto V_275;
} else {
V_53 = F_47 ( V_12 , & V_90 ,
V_46 -> V_45 ) ;
if ( F_48 ( V_53 ) )
return F_68 ( V_53 ) ;
V_46 -> V_53 = V_53 ;
V_19 = F_57 ( V_12 , V_46 ) ;
if ( V_19 )
goto V_92;
}
F_208 ( V_193 ) ;
return 0 ;
V_92:
V_46 -> V_53 = NULL ;
F_49 ( V_12 , V_53 ) ;
V_275:
V_193 -> V_46 = NULL ;
F_202 ( V_46 , V_193 ) ;
return V_19 ;
}
static void F_211 ( struct V_12 * V_12 ,
struct V_264 * V_193 )
{
struct V_54 * V_53 = V_193 -> V_46 -> V_53 ;
struct V_41 * V_46 = V_193 -> V_46 ;
F_209 ( V_193 ) ;
if ( F_23 ( & V_46 -> V_38 ) ) {
F_59 ( V_12 , V_46 ) ;
V_46 -> V_53 = NULL ;
F_49 ( V_12 , V_53 ) ;
} else {
F_67 ( V_12 , V_46 , & V_46 -> V_38 ) ;
}
V_193 -> V_46 = NULL ;
F_202 ( V_46 , V_193 ) ;
}
static struct V_264 *
F_200 ( struct V_12 * V_12 ,
const struct V_256 * V_257 )
{
struct V_264 * V_193 ;
struct V_41 * V_46 ;
struct V_42 * V_43 ;
int V_19 ;
V_43 = F_69 ( V_12 , V_257 -> V_85 ) ;
if ( F_48 ( V_43 ) )
return F_65 ( V_43 ) ;
V_46 = F_62 ( V_43 , V_88 ) ;
V_193 = F_203 ( V_46 , & V_257 -> V_276 ,
sizeof( V_257 -> V_276 ) ,
V_257 -> V_277 ) ;
if ( V_193 )
return V_193 ;
V_193 = F_204 ( V_46 , & V_257 -> V_276 ,
sizeof( V_257 -> V_276 ) ,
V_257 -> V_277 ) ;
if ( ! V_193 ) {
V_19 = - V_48 ;
goto V_278;
}
V_19 = F_210 ( V_12 , V_193 , V_46 ) ;
if ( V_19 )
goto V_279;
return V_193 ;
V_279:
F_205 ( V_193 ) ;
V_278:
F_70 ( V_43 ) ;
return F_31 ( V_19 ) ;
}
static void F_212 ( struct V_12 * V_12 ,
struct V_264 * V_193 )
{
struct V_42 * V_43 = V_193 -> V_46 -> V_43 ;
if ( ! F_36 ( & V_193 -> V_272 ) )
return;
F_211 ( V_12 , V_193 ) ;
F_205 ( V_193 ) ;
F_70 ( V_43 ) ;
}
static struct V_191 *
F_213 ( const struct V_264 * V_193 ,
const struct V_280 * V_236 )
{
struct V_191 * V_192 ;
F_113 (fib_entry, &fib_node->entry_list, list) {
if ( V_192 -> V_236 . V_85 > V_236 -> V_85 )
continue;
if ( V_192 -> V_236 . V_85 != V_236 -> V_85 )
break;
if ( V_192 -> V_236 . V_237 > V_236 -> V_237 )
continue;
if ( V_192 -> V_236 . V_268 >= V_236 -> V_268 ||
V_192 -> V_236 . V_237 < V_236 -> V_237 )
return V_192 ;
}
return NULL ;
}
static int F_214 ( struct V_191 * V_192 ,
struct V_191 * V_281 )
{
struct V_264 * V_193 ;
if ( F_18 ( ! V_192 ) )
return - V_26 ;
V_193 = V_192 -> V_193 ;
F_215 (fib_entry, &fib_node->entry_list, list) {
if ( V_192 -> V_236 . V_85 != V_281 -> V_236 . V_85 ||
V_192 -> V_236 . V_237 != V_281 -> V_236 . V_237 ||
V_192 -> V_236 . V_268 != V_281 -> V_236 . V_268 )
break;
}
F_168 ( & V_281 -> V_273 , & V_192 -> V_273 ) ;
return 0 ;
}
static int
F_216 ( struct V_264 * V_193 ,
struct V_191 * V_281 ,
bool V_282 , bool V_283 )
{
struct V_191 * V_192 ;
V_192 = F_213 ( V_193 , & V_281 -> V_236 ) ;
if ( V_283 )
return F_214 ( V_192 , V_281 ) ;
if ( V_282 && F_18 ( ! V_192 ) )
return - V_26 ;
if ( V_192 ) {
F_168 ( & V_281 -> V_273 , & V_192 -> V_273 ) ;
} else {
struct V_191 * V_284 ;
F_113 (last, &fib_node->entry_list, list) {
if ( V_281 -> V_236 . V_85 > V_284 -> V_236 . V_85 )
break;
V_192 = V_284 ;
}
if ( V_192 )
F_83 ( & V_281 -> V_273 , & V_192 -> V_273 ) ;
else
F_83 ( & V_281 -> V_273 , & V_193 -> V_272 ) ;
}
return 0 ;
}
static void
F_217 ( struct V_191 * V_192 )
{
F_85 ( & V_192 -> V_273 ) ;
}
static int
F_218 ( struct V_12 * V_12 ,
const struct V_264 * V_193 ,
struct V_191 * V_192 )
{
if ( ! F_206 ( V_193 , V_192 ) )
return 0 ;
if ( ! F_219 ( & V_193 -> V_272 ) ) {
enum V_241 V_141 = V_242 ;
struct V_191 * V_97 = F_220 ( V_192 , V_273 ) ;
F_185 ( V_97 , V_141 , 0 ) ;
}
return F_158 ( V_12 , V_192 ) ;
}
static void
F_221 ( struct V_12 * V_12 ,
const struct V_264 * V_193 ,
struct V_191 * V_192 )
{
if ( ! F_206 ( V_193 , V_192 ) )
return;
if ( ! F_219 ( & V_193 -> V_272 ) ) {
struct V_191 * V_97 = F_220 ( V_192 , V_273 ) ;
enum V_241 V_141 = V_242 ;
F_158 ( V_12 , V_97 ) ;
F_185 ( V_192 , V_141 , 0 ) ;
return;
}
F_195 ( V_12 , V_192 ) ;
}
static int F_222 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
bool V_282 , bool V_283 )
{
struct V_264 * V_193 = V_192 -> V_193 ;
int V_19 ;
V_19 = F_216 ( V_193 , V_192 , V_282 ,
V_283 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_218 ( V_12 , V_193 , V_192 ) ;
if ( V_19 )
goto V_285;
return 0 ;
V_285:
F_217 ( V_192 ) ;
return V_19 ;
}
static void
F_223 ( struct V_12 * V_12 ,
struct V_191 * V_192 )
{
struct V_264 * V_193 = V_192 -> V_193 ;
F_221 ( V_12 , V_193 , V_192 ) ;
F_217 ( V_192 ) ;
}
static void F_224 ( struct V_12 * V_12 ,
struct V_191 * V_192 ,
bool V_282 )
{
struct V_264 * V_193 = V_192 -> V_193 ;
struct V_191 * V_286 ;
if ( ! V_282 )
return;
V_286 = F_220 ( V_192 , V_273 ) ;
F_223 ( V_12 , V_286 ) ;
F_198 ( V_12 , V_286 ) ;
F_212 ( V_12 , V_193 ) ;
}
static int
F_225 ( struct V_12 * V_12 ,
const struct V_256 * V_257 ,
bool V_282 , bool V_283 )
{
struct V_191 * V_192 ;
struct V_264 * V_193 ;
int V_19 ;
if ( V_12 -> V_56 . V_222 )
return 0 ;
V_193 = F_200 ( V_12 , V_257 ) ;
if ( F_48 ( V_193 ) ) {
F_160 ( V_12 -> V_120 -> V_104 , L_11 ) ;
return F_68 ( V_193 ) ;
}
V_192 = F_197 ( V_12 , V_193 , V_257 ) ;
if ( F_48 ( V_192 ) ) {
F_160 ( V_12 -> V_120 -> V_104 , L_12 ) ;
V_19 = F_68 ( V_192 ) ;
goto V_287;
}
V_19 = F_222 ( V_12 , V_192 , V_282 ,
V_283 ) ;
if ( V_19 ) {
F_160 ( V_12 -> V_120 -> V_104 , L_13 ) ;
goto V_288;
}
F_224 ( V_12 , V_192 , V_282 ) ;
return 0 ;
V_288:
F_198 ( V_12 , V_192 ) ;
V_287:
F_212 ( V_12 , V_193 ) ;
return V_19 ;
}
static void F_226 ( struct V_12 * V_12 ,
struct V_256 * V_257 )
{
struct V_191 * V_192 ;
struct V_264 * V_193 ;
if ( V_12 -> V_56 . V_222 )
return;
V_192 = F_199 ( V_12 , V_257 ) ;
if ( F_18 ( ! V_192 ) )
return;
V_193 = V_192 -> V_193 ;
F_223 ( V_12 , V_192 ) ;
F_198 ( V_12 , V_192 ) ;
F_212 ( V_12 , V_193 ) ;
}
static int F_227 ( struct V_12 * V_12 )
{
char V_61 [ V_62 ] ;
char V_66 [ V_67 ] ;
int V_55 , V_19 ;
F_40 ( V_61 , true , V_289 ,
V_78 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_65 ) , V_61 ) ;
if ( V_19 )
return V_19 ;
F_43 ( V_66 , 0xff , V_78 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_71 ) , V_66 ) ;
if ( V_19 )
return V_19 ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_80 ) ; V_55 ++ ) {
struct V_42 * V_43 = & V_12 -> V_56 . V_81 [ V_55 ] ;
char V_82 [ V_83 ] ;
char V_244 [ V_245 ] ;
if ( ! F_55 ( V_43 ) )
continue;
F_58 ( V_82 , V_43 -> V_64 ,
V_289 ,
V_78 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_84 ) ,
V_82 ) ;
if ( V_19 )
return V_19 ;
F_187 ( V_244 , V_88 ,
V_243 , V_43 -> V_64 , 0 ,
0 ) ;
F_192 ( V_244 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_254 ) ,
V_244 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_228 ( struct V_12 * V_12 ,
struct V_264 * V_193 )
{
struct V_191 * V_192 , * V_171 ;
F_143 (fib_entry, tmp, &fib_node->entry_list, list) {
bool V_290 = & V_171 -> V_273 == & V_193 -> V_272 ;
F_223 ( V_12 , V_192 ) ;
F_198 ( V_12 , V_192 ) ;
F_212 ( V_12 , V_193 ) ;
if ( V_290 )
break;
}
}
static void F_229 ( struct V_12 * V_12 ,
struct V_264 * V_193 )
{
switch ( V_193 -> V_46 -> V_45 ) {
case V_88 :
F_228 ( V_12 , V_193 ) ;
break;
case V_89 :
F_104 ( 1 ) ;
break;
}
}
static void F_230 ( struct V_12 * V_12 ,
struct V_42 * V_43 ,
enum V_44 V_45 )
{
struct V_41 * V_46 = F_62 ( V_43 , V_45 ) ;
struct V_264 * V_193 , * V_171 ;
F_143 (fib_node, tmp, &fib->node_list, list) {
bool V_290 = & V_171 -> V_273 == & V_46 -> V_52 ;
F_229 ( V_12 , V_193 ) ;
if ( V_290 )
break;
}
}
static void F_74 ( struct V_12 * V_12 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_80 ) ; V_55 ++ ) {
struct V_42 * V_43 = & V_12 -> V_56 . V_81 [ V_55 ] ;
if ( ! F_55 ( V_43 ) )
continue;
F_230 ( V_12 , V_43 , V_88 ) ;
}
}
static void F_231 ( struct V_12 * V_12 )
{
int V_19 ;
if ( V_12 -> V_56 . V_222 )
return;
F_160 ( V_12 -> V_120 -> V_104 , L_14 ) ;
F_74 ( V_12 ) ;
V_12 -> V_56 . V_222 = true ;
V_19 = F_227 ( V_12 ) ;
if ( V_19 )
F_160 ( V_12 -> V_120 -> V_104 , L_15 ) ;
}
static void F_232 ( struct V_132 * V_133 )
{
struct V_291 * V_292 =
F_118 ( V_133 , struct V_291 , V_133 ) ;
struct V_12 * V_12 = V_292 -> V_12 ;
struct V_293 * V_294 ;
bool V_282 , V_283 ;
int V_19 ;
F_109 () ;
switch ( V_292 -> V_159 ) {
case V_295 :
case V_296 :
case V_297 :
V_282 = V_292 -> V_159 == V_295 ;
V_283 = V_292 -> V_159 == V_296 ;
V_19 = F_225 ( V_12 , & V_292 -> V_257 ,
V_282 , V_283 ) ;
if ( V_19 )
F_231 ( V_12 ) ;
F_233 ( V_292 -> V_257 . V_226 ) ;
break;
case V_298 :
F_226 ( V_12 , & V_292 -> V_257 ) ;
F_233 ( V_292 -> V_257 . V_226 ) ;
break;
case V_299 :
case V_300 :
V_294 = V_292 -> V_301 . V_294 ;
if ( ! F_234 ( V_294 ) && ! V_294 -> V_302 )
F_231 ( V_12 ) ;
F_235 ( V_294 ) ;
break;
case V_223 :
case V_224 :
F_174 ( V_12 , V_292 -> V_159 ,
V_292 -> V_303 . V_210 ) ;
F_233 ( V_292 -> V_303 . V_210 -> V_304 ) ;
break;
}
F_111 () ;
F_34 ( V_292 ) ;
}
static int F_236 ( struct V_157 * V_305 ,
unsigned long V_159 , void * V_160 )
{
struct V_12 * V_12 = F_118 ( V_305 , struct V_12 , V_306 ) ;
struct V_291 * V_292 ;
struct V_307 * V_308 = V_160 ;
if ( ! F_237 ( V_308 -> V_309 , & V_310 ) )
return V_165 ;
V_292 = F_30 ( sizeof( * V_292 ) , V_167 ) ;
if ( F_18 ( ! V_292 ) )
return V_168 ;
F_133 ( & V_292 -> V_133 , F_232 ) ;
V_292 -> V_12 = V_12 ;
V_292 -> V_159 = V_159 ;
switch ( V_159 ) {
case V_295 :
case V_296 :
case V_297 :
case V_298 :
memcpy ( & V_292 -> V_257 , V_160 , sizeof( V_292 -> V_257 ) ) ;
F_238 ( V_292 -> V_257 . V_226 ) ;
break;
case V_299 :
case V_300 :
memcpy ( & V_292 -> V_301 , V_160 , sizeof( V_292 -> V_301 ) ) ;
F_239 ( V_292 -> V_301 . V_294 ) ;
break;
case V_223 :
case V_224 :
memcpy ( & V_292 -> V_303 , V_160 , sizeof( V_292 -> V_303 ) ) ;
F_238 ( V_292 -> V_303 . V_210 -> V_304 ) ;
break;
}
F_135 ( & V_292 -> V_133 ) ;
return V_165 ;
}
static struct V_1 *
F_82 ( const struct V_12 * V_12 ,
const struct V_116 * V_104 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_311 ) ; V_55 ++ )
if ( V_12 -> V_119 [ V_55 ] && V_12 -> V_119 [ V_55 ] -> V_104 == V_104 )
return V_12 -> V_119 [ V_55 ] ;
return NULL ;
}
static int F_240 ( struct V_12 * V_12 , T_1 V_2 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_2 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( F_104 ( V_19 ) )
return V_19 ;
F_241 ( V_16 , false ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static void F_242 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
F_240 ( V_12 , V_2 -> V_13 ) ;
F_175 ( V_12 , V_2 ) ;
F_142 ( V_12 , V_2 ) ;
}
static bool F_243 ( struct V_1 * V_2 ,
const struct V_217 * V_218 ,
unsigned long V_159 )
{
switch ( V_159 ) {
case V_312 :
if ( ! V_2 )
return true ;
return false ;
case V_313 :
if ( V_2 && ! V_218 -> V_314 &&
! F_244 ( V_2 -> V_104 ) )
return true ;
return false ;
}
return false ;
}
static int F_245 ( struct V_12 * V_12 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_311 ) ; V_55 ++ )
if ( ! V_12 -> V_119 [ V_55 ] )
return V_55 ;
return V_315 ;
}
static void F_246 ( struct V_161 * V_316 ,
bool * V_317 , T_1 * V_318 )
{
T_3 V_319 = V_316 -> V_319 ;
* V_317 = V_316 -> V_320 ;
* V_318 = * V_317 ? V_316 -> V_321 : V_319 ;
}
static int F_247 ( struct V_161 * V_316 ,
T_1 V_322 , struct V_116 * V_323 ,
T_1 V_13 , bool V_324 )
{
struct V_12 * V_12 = V_316 -> V_12 ;
bool V_320 = V_316 -> V_320 ;
char V_16 [ V_17 ] ;
T_1 V_325 ;
F_248 ( V_16 , V_324 , V_326 , V_13 ,
V_322 , V_323 -> V_327 , V_323 -> V_328 ) ;
F_246 ( V_316 , & V_320 , & V_325 ) ;
F_249 ( V_16 , V_320 , V_325 ,
F_250 ( V_316 ) ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static T_1 F_251 ( T_1 V_13 )
{
return V_329 + V_13 ;
}
static struct V_330 *
F_252 ( T_1 V_331 , struct V_116 * V_323 )
{
struct V_330 * V_332 ;
V_332 = F_30 ( sizeof( * V_332 ) , V_47 ) ;
if ( ! V_332 )
return NULL ;
V_332 -> V_333 = V_334 ;
V_332 -> V_60 = 0 ;
V_332 -> V_104 = V_323 ;
V_332 -> V_331 = V_331 ;
return V_332 ;
}
static struct V_1 *
F_253 ( T_1 V_13 , T_1 V_322 , struct V_116 * V_323 ,
struct V_330 * V_332 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return NULL ;
F_33 ( & V_2 -> V_100 ) ;
F_33 ( & V_2 -> V_107 ) ;
F_254 ( V_2 -> V_170 , V_323 -> V_328 ) ;
V_2 -> V_327 = V_323 -> V_327 ;
V_2 -> V_322 = V_322 ;
V_2 -> V_104 = V_323 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_332 = V_332 ;
return V_2 ;
}
T_1 F_255 ( const struct V_1 * V_2 )
{
return V_2 -> V_13 ;
}
int F_256 ( const struct V_1 * V_2 )
{
return V_2 -> V_104 -> V_335 ;
}
static struct V_1 *
F_257 ( struct V_161 * V_316 ,
struct V_116 * V_323 )
{
struct V_12 * V_12 = V_316 -> V_12 ;
T_4 V_85 = F_258 ( V_323 ) ;
struct V_42 * V_43 ;
struct V_330 * V_332 ;
struct V_1 * V_2 ;
T_1 V_331 , V_13 ;
int V_19 ;
V_13 = F_245 ( V_12 ) ;
if ( V_13 == V_315 )
return F_31 ( - V_336 ) ;
V_43 = F_69 ( V_12 , V_85 ? : V_87 ) ;
if ( F_48 ( V_43 ) )
return F_65 ( V_43 ) ;
V_19 = F_247 ( V_316 , V_43 -> V_64 , V_323 ,
V_13 , true ) ;
if ( V_19 )
goto V_337;
V_331 = F_251 ( V_13 ) ;
V_19 = F_259 ( V_12 , V_323 -> V_328 , V_331 , true ) ;
if ( V_19 )
goto V_338;
V_332 = F_252 ( V_331 , V_323 ) ;
if ( ! V_332 ) {
V_19 = - V_48 ;
goto V_339;
}
V_2 = F_253 ( V_13 , V_43 -> V_64 , V_323 , V_332 ) ;
if ( ! V_2 ) {
V_19 = - V_48 ;
goto V_340;
}
if ( F_260 ( F_261 ( V_12 -> V_20 ) ,
V_341 ) ) {
V_19 = F_14 ( V_12 , V_2 ,
V_5 ) ;
if ( V_19 )
F_97 ( V_316 -> V_104 ,
L_16 , V_19 ) ;
}
V_332 -> V_2 = V_2 ;
V_12 -> V_119 [ V_13 ] = V_2 ;
V_43 -> V_93 ++ ;
return V_2 ;
V_340:
F_34 ( V_332 ) ;
V_339:
F_259 ( V_12 , V_323 -> V_328 , V_331 , false ) ;
V_338:
F_247 ( V_316 , V_43 -> V_64 , V_323 , V_13 ,
false ) ;
V_337:
F_70 ( V_43 ) ;
return F_31 ( V_19 ) ;
}
static void F_262 ( struct V_161 * V_316 ,
struct V_1 * V_2 )
{
struct V_12 * V_12 = V_316 -> V_12 ;
struct V_42 * V_43 = & V_12 -> V_56 . V_81 [ V_2 -> V_322 ] ;
struct V_116 * V_323 = V_2 -> V_104 ;
struct V_330 * V_332 = V_2 -> V_332 ;
T_1 V_13 = V_2 -> V_13 ;
T_1 V_331 = V_332 -> V_331 ;
F_242 ( V_12 , V_2 ) ;
F_17 ( V_12 , V_2 , V_5 ) ;
F_17 ( V_12 , V_2 , V_7 ) ;
V_43 -> V_93 -- ;
V_12 -> V_119 [ V_13 ] = NULL ;
V_332 -> V_2 = NULL ;
F_34 ( V_2 ) ;
F_34 ( V_332 ) ;
F_259 ( V_12 , V_323 -> V_328 , V_331 , false ) ;
F_247 ( V_316 , V_43 -> V_64 , V_323 , V_13 ,
false ) ;
F_70 ( V_43 ) ;
}
static int F_263 ( struct V_161 * V_316 ,
struct V_116 * V_323 )
{
struct V_12 * V_12 = V_316 -> V_12 ;
struct V_1 * V_2 ;
V_2 = F_82 ( V_12 , V_323 ) ;
if ( ! V_2 ) {
V_2 = F_257 ( V_316 , V_323 ) ;
if ( F_48 ( V_2 ) )
return F_68 ( V_2 ) ;
}
F_264 ( V_316 , V_2 -> V_332 ) ;
V_2 -> V_332 -> V_60 ++ ;
F_97 ( V_316 -> V_104 , L_17 , V_2 -> V_332 -> V_331 ) ;
return 0 ;
}
static void V_334 ( struct V_161 * V_316 )
{
struct V_330 * V_332 = F_265 ( V_316 ) ;
F_97 ( V_316 -> V_104 , L_18 , V_332 -> V_331 ) ;
F_264 ( V_316 , NULL ) ;
if ( -- V_332 -> V_60 == 0 )
F_262 ( V_316 , V_332 -> V_2 ) ;
}
static int F_266 ( struct V_116 * V_323 ,
struct V_116 * V_342 ,
unsigned long V_159 , T_1 V_343 )
{
struct V_161 * V_161 = F_267 ( V_342 ) ;
struct V_161 * V_316 ;
V_316 = F_268 ( V_161 , V_343 ) ;
if ( F_18 ( ! V_316 ) )
return - V_26 ;
switch ( V_159 ) {
case V_312 :
return F_263 ( V_316 , V_323 ) ;
case V_313 :
V_334 ( V_316 ) ;
break;
}
return 0 ;
}
static int F_269 ( struct V_116 * V_342 ,
unsigned long V_159 )
{
if ( F_270 ( V_342 ) ||
F_271 ( V_342 ) ||
F_272 ( V_342 ) )
return 0 ;
return F_266 ( V_342 , V_342 , V_159 , 1 ) ;
}
static int F_273 ( struct V_116 * V_323 ,
struct V_116 * V_344 ,
unsigned long V_159 , T_1 V_343 )
{
struct V_116 * V_342 ;
struct V_345 * V_346 ;
int V_19 ;
F_274 (lag_dev, port_dev, iter) {
if ( F_275 ( V_342 ) ) {
V_19 = F_266 ( V_323 , V_342 ,
V_159 , V_343 ) ;
if ( V_19 )
return V_19 ;
}
}
return 0 ;
}
static int F_276 ( struct V_116 * V_344 ,
unsigned long V_159 )
{
if ( F_270 ( V_344 ) )
return 0 ;
return F_273 ( V_344 , V_344 , V_159 , 1 ) ;
}
static struct V_330 * F_277 ( struct V_12 * V_12 ,
struct V_116 * V_323 )
{
T_1 V_331 ;
if ( F_278 ( V_323 ) )
V_331 = F_279 ( V_323 ) ;
else if ( V_12 -> V_347 . V_104 == V_323 )
V_331 = 1 ;
else
return F_280 ( V_12 , V_323 ) ;
return F_281 ( V_12 , V_331 ) ;
}
static T_3 F_282 ( const struct V_12 * V_12 )
{
return F_283 ( V_12 -> V_20 ) + 1 ;
}
static enum V_348 F_284 ( T_1 V_331 )
{
return F_285 ( V_331 ) ? V_349 :
V_350 ;
}
static T_1 F_286 ( T_1 V_331 )
{
return F_285 ( V_331 ) ? F_287 ( V_331 ) : V_331 ;
}
static int F_288 ( struct V_12 * V_12 , T_1 V_331 ,
bool V_351 )
{
T_3 V_352 = F_282 ( V_12 ) ;
enum V_348 V_353 ;
char * V_354 ;
T_1 V_355 ;
int V_19 ;
V_354 = F_108 ( V_356 , V_47 ) ;
if ( ! V_354 )
return - V_48 ;
V_353 = F_284 ( V_331 ) ;
V_355 = F_286 ( V_331 ) ;
F_289 ( V_354 , V_357 , V_355 , V_353 ,
1 , V_352 , V_351 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_358 ) , V_354 ) ;
F_34 ( V_354 ) ;
return V_19 ;
}
static enum V_359 F_290 ( T_1 V_331 )
{
if ( F_285 ( V_331 ) )
return V_360 ;
else
return V_361 ;
}
static int F_291 ( struct V_12 * V_12 , T_1 V_322 ,
struct V_116 * V_323 ,
T_1 V_331 , T_1 V_2 ,
bool V_324 )
{
enum V_359 V_362 ;
char V_16 [ V_17 ] ;
V_362 = F_290 ( V_331 ) ;
F_248 ( V_16 , V_324 , V_362 , V_2 , V_322 , V_323 -> V_327 ,
V_323 -> V_328 ) ;
F_292 ( V_16 , V_362 , V_331 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static int F_293 ( struct V_12 * V_12 ,
struct V_116 * V_323 ,
struct V_330 * V_332 )
{
T_4 V_85 = F_258 ( V_323 ) ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
T_1 V_13 ;
int V_19 ;
V_13 = F_245 ( V_12 ) ;
if ( V_13 == V_315 )
return - V_336 ;
V_43 = F_69 ( V_12 , V_85 ? : V_87 ) ;
if ( F_48 ( V_43 ) )
return F_68 ( V_43 ) ;
V_19 = F_288 ( V_12 , V_332 -> V_331 , true ) ;
if ( V_19 )
goto V_363;
V_19 = F_291 ( V_12 , V_43 -> V_64 , V_323 , V_332 -> V_331 ,
V_13 , true ) ;
if ( V_19 )
goto V_364;
V_19 = F_259 ( V_12 , V_323 -> V_328 , V_332 -> V_331 , true ) ;
if ( V_19 )
goto V_338;
V_2 = F_253 ( V_13 , V_43 -> V_64 , V_323 , V_332 ) ;
if ( ! V_2 ) {
V_19 = - V_48 ;
goto V_340;
}
V_332 -> V_2 = V_2 ;
V_12 -> V_119 [ V_13 ] = V_2 ;
V_43 -> V_93 ++ ;
F_97 ( V_323 , L_19 , V_13 ) ;
return 0 ;
V_340:
F_259 ( V_12 , V_323 -> V_328 , V_332 -> V_331 , false ) ;
V_338:
F_291 ( V_12 , V_43 -> V_64 , V_323 , V_332 -> V_331 , V_13 ,
false ) ;
V_364:
F_288 ( V_12 , V_332 -> V_331 , false ) ;
V_363:
F_70 ( V_43 ) ;
return V_19 ;
}
void F_294 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 = & V_12 -> V_56 . V_81 [ V_2 -> V_322 ] ;
struct V_116 * V_323 = V_2 -> V_104 ;
struct V_330 * V_332 = V_2 -> V_332 ;
T_1 V_13 = V_2 -> V_13 ;
F_242 ( V_12 , V_2 ) ;
V_43 -> V_93 -- ;
V_12 -> V_119 [ V_13 ] = NULL ;
V_332 -> V_2 = NULL ;
F_34 ( V_2 ) ;
F_259 ( V_12 , V_323 -> V_328 , V_332 -> V_331 , false ) ;
F_291 ( V_12 , V_43 -> V_64 , V_323 , V_332 -> V_331 , V_13 ,
false ) ;
F_288 ( V_12 , V_332 -> V_331 , false ) ;
F_70 ( V_43 ) ;
F_97 ( V_323 , L_20 , V_13 ) ;
}
static int F_295 ( struct V_116 * V_323 ,
struct V_116 * V_365 ,
unsigned long V_159 )
{
struct V_12 * V_12 = F_296 ( V_323 ) ;
struct V_330 * V_332 ;
V_332 = F_277 ( V_12 , V_323 ) ;
if ( F_18 ( ! V_332 ) )
return - V_26 ;
switch ( V_159 ) {
case V_312 :
return F_293 ( V_12 , V_323 , V_332 ) ;
case V_313 :
F_294 ( V_12 , V_332 -> V_2 ) ;
break;
}
return 0 ;
}
static int F_297 ( struct V_116 * V_366 ,
unsigned long V_159 )
{
struct V_116 * V_367 = F_298 ( V_366 ) ;
struct V_12 * V_12 = F_296 ( V_366 ) ;
T_1 V_343 = F_279 ( V_366 ) ;
if ( F_270 ( V_366 ) )
return 0 ;
if ( F_275 ( V_367 ) )
return F_266 ( V_366 , V_367 , V_159 ,
V_343 ) ;
else if ( F_299 ( V_367 ) )
return F_273 ( V_366 , V_367 , V_159 ,
V_343 ) ;
else if ( F_300 ( V_367 ) &&
V_12 -> V_347 . V_104 == V_367 )
return F_295 ( V_366 , V_367 ,
V_159 ) ;
return 0 ;
}
static int F_301 ( struct V_116 * V_104 ,
unsigned long V_159 )
{
if ( F_275 ( V_104 ) )
return F_269 ( V_104 , V_159 ) ;
else if ( F_299 ( V_104 ) )
return F_276 ( V_104 , V_159 ) ;
else if ( F_300 ( V_104 ) )
return F_295 ( V_104 , V_104 , V_159 ) ;
else if ( F_278 ( V_104 ) )
return F_297 ( V_104 , V_159 ) ;
else
return 0 ;
}
int F_302 ( struct V_157 * V_158 ,
unsigned long V_159 , void * V_160 )
{
struct V_368 * V_369 = (struct V_368 * ) V_160 ;
struct V_116 * V_104 = V_369 -> V_370 -> V_104 ;
struct V_12 * V_12 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_12 = F_296 ( V_104 ) ;
if ( ! V_12 )
goto V_156;
V_2 = F_82 ( V_12 , V_104 ) ;
if ( ! F_243 ( V_2 , V_369 -> V_370 , V_159 ) )
goto V_156;
V_19 = F_301 ( V_104 , V_159 ) ;
V_156:
return F_303 ( V_19 ) ;
}
static int F_304 ( struct V_12 * V_12 , T_1 V_13 ,
const char * V_371 , int V_327 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_13 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( V_19 )
return V_19 ;
F_305 ( V_16 , V_327 ) ;
F_306 ( V_16 , V_371 ) ;
F_307 ( V_16 , V_372 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
int F_308 ( struct V_116 * V_104 )
{
struct V_12 * V_12 ;
struct V_1 * V_2 ;
int V_19 ;
V_12 = F_296 ( V_104 ) ;
if ( ! V_12 )
return 0 ;
V_2 = F_82 ( V_12 , V_104 ) ;
if ( ! V_2 )
return 0 ;
V_19 = F_259 ( V_12 , V_2 -> V_170 , V_2 -> V_332 -> V_331 , false ) ;
if ( V_19 )
return V_19 ;
V_19 = F_304 ( V_12 , V_2 -> V_13 , V_104 -> V_328 ,
V_104 -> V_327 ) ;
if ( V_19 )
goto V_373;
V_19 = F_259 ( V_12 , V_104 -> V_328 , V_2 -> V_332 -> V_331 , true ) ;
if ( V_19 )
goto V_338;
F_254 ( V_2 -> V_170 , V_104 -> V_328 ) ;
V_2 -> V_327 = V_104 -> V_327 ;
F_97 ( V_104 , L_21 , V_2 -> V_13 ) ;
return 0 ;
V_338:
F_304 ( V_12 , V_2 -> V_13 , V_2 -> V_170 , V_2 -> V_327 ) ;
V_373:
F_259 ( V_12 , V_2 -> V_170 , V_2 -> V_332 -> V_331 , true ) ;
return V_19 ;
}
static int F_309 ( struct V_12 * V_12 ,
struct V_116 * V_323 )
{
struct V_1 * V_2 ;
V_2 = F_82 ( V_12 , V_323 ) ;
if ( V_2 )
F_301 ( V_323 , V_313 ) ;
return F_301 ( V_323 , V_312 ) ;
}
static void F_310 ( struct V_12 * V_12 ,
struct V_116 * V_323 )
{
struct V_1 * V_2 ;
V_2 = F_82 ( V_12 , V_323 ) ;
if ( ! V_2 )
return;
F_301 ( V_323 , V_313 ) ;
}
int F_311 ( struct V_116 * V_323 , unsigned long V_159 ,
struct V_374 * V_308 )
{
struct V_12 * V_12 = F_296 ( V_323 ) ;
int V_19 = 0 ;
if ( ! V_12 )
return 0 ;
switch ( V_159 ) {
case V_375 :
return 0 ;
case V_376 :
if ( V_308 -> V_377 )
V_19 = F_309 ( V_12 , V_323 ) ;
else
F_310 ( V_12 , V_323 ) ;
break;
}
return V_19 ;
}
static void F_312 ( struct V_157 * V_305 )
{
struct V_12 * V_12 = F_118 ( V_305 , struct V_12 , V_306 ) ;
F_73 () ;
F_74 ( V_12 ) ;
}
static int F_313 ( struct V_12 * V_12 )
{
char V_378 [ V_379 ] ;
T_2 V_380 ;
int V_19 ;
if ( ! F_51 ( V_12 -> V_20 , V_311 ) )
return - V_77 ;
V_380 = F_52 ( V_12 -> V_20 , V_311 ) ;
V_12 -> V_119 = F_53 ( V_380 , sizeof( struct V_1 * ) ,
V_47 ) ;
if ( ! V_12 -> V_119 )
return - V_48 ;
F_314 ( V_378 , true ) ;
F_315 ( V_378 , V_380 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_381 ) , V_378 ) ;
if ( V_19 )
goto V_382;
return 0 ;
V_382:
F_34 ( V_12 -> V_119 ) ;
return V_19 ;
}
static void F_316 ( struct V_12 * V_12 )
{
char V_378 [ V_379 ] ;
int V_55 ;
F_314 ( V_378 , false ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_381 ) , V_378 ) ;
for ( V_55 = 0 ; V_55 < F_52 ( V_12 -> V_20 , V_311 ) ; V_55 ++ )
F_104 ( V_12 -> V_119 [ V_55 ] ) ;
F_34 ( V_12 -> V_119 ) ;
}
int F_317 ( struct V_12 * V_12 )
{
int V_19 ;
F_33 ( & V_12 -> V_56 . V_215 ) ;
V_19 = F_313 ( V_12 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_32 ( & V_12 -> V_56 . V_179 ,
& V_180 ) ;
if ( V_19 )
goto V_383;
V_19 = F_32 ( & V_12 -> V_56 . V_174 ,
& V_175 ) ;
if ( V_19 )
goto V_384;
V_19 = F_50 ( V_12 ) ;
if ( V_19 )
goto V_385;
V_19 = F_71 ( V_12 ) ;
if ( V_19 )
goto V_386;
V_19 = F_136 ( V_12 ) ;
if ( V_19 )
goto V_387;
V_12 -> V_306 . V_388 = F_236 ;
V_19 = F_318 ( & V_12 -> V_306 ,
F_312 ) ;
if ( V_19 )
goto V_389;
return 0 ;
V_389:
F_138 ( V_12 ) ;
V_387:
F_72 ( V_12 ) ;
V_386:
F_54 ( V_12 ) ;
V_385:
F_37 ( & V_12 -> V_56 . V_174 ) ;
V_384:
F_37 ( & V_12 -> V_56 . V_179 ) ;
V_383:
F_316 ( V_12 ) ;
return V_19 ;
}
void F_319 ( struct V_12 * V_12 )
{
F_320 ( & V_12 -> V_306 ) ;
F_138 ( V_12 ) ;
F_72 ( V_12 ) ;
F_54 ( V_12 ) ;
F_37 ( & V_12 -> V_56 . V_174 ) ;
F_37 ( & V_12 -> V_56 . V_179 ) ;
F_316 ( V_12 ) ;
}
