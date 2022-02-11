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
static void F_19 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_33 * V_33 ;
V_33 = F_20 ( V_12 -> V_20 ) ;
if ( ! F_21 ( V_33 ,
V_34 ) )
return;
F_14 ( V_12 , V_2 , V_5 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
F_17 ( V_12 , V_2 , V_5 ) ;
}
static bool
F_23 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
unsigned char V_38 ;
F_24 (prefix, prefix_usage1) {
if ( ! F_25 ( V_38 , V_37 -> V_39 ) )
return false ;
}
return true ;
}
static bool
F_26 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
return ! memcmp ( V_36 , V_37 , sizeof( * V_36 ) ) ;
}
static bool
F_27 ( struct V_35 * V_40 )
{
struct V_35 V_41 = { { 0 } } ;
return F_26 ( V_40 , & V_41 ) ;
}
static void
F_28 ( struct V_35 * V_36 ,
struct V_35 * V_37 )
{
memcpy ( V_36 , V_37 , sizeof( * V_36 ) ) ;
}
static void
F_29 ( struct V_35 * V_40 ,
unsigned char V_42 )
{
F_30 ( V_42 , V_40 -> V_39 ) ;
}
static void
F_31 ( struct V_35 * V_40 ,
unsigned char V_42 )
{
F_32 ( V_42 , V_40 -> V_39 ) ;
}
static struct V_43 * F_33 ( struct V_44 * V_45 ,
enum V_46 V_47 )
{
struct V_43 * V_48 ;
int V_19 ;
V_48 = F_34 ( sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 )
return F_35 ( - V_50 ) ;
V_19 = F_36 ( & V_48 -> V_51 , & V_52 ) ;
if ( V_19 )
goto V_53;
F_37 ( & V_48 -> V_54 ) ;
V_48 -> V_47 = V_47 ;
V_48 -> V_45 = V_45 ;
return V_48 ;
V_53:
F_38 ( V_48 ) ;
return F_35 ( V_19 ) ;
}
static void F_39 ( struct V_43 * V_48 )
{
F_18 ( ! F_40 ( & V_48 -> V_54 ) ) ;
F_18 ( V_48 -> V_55 ) ;
F_41 ( & V_48 -> V_51 ) ;
F_38 ( V_48 ) ;
}
static struct V_56 *
F_42 ( struct V_12 * V_12 )
{
static struct V_56 * V_55 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_12 -> V_58 -> V_59 . V_60 ; V_57 ++ ) {
V_55 = & V_12 -> V_58 -> V_59 . V_61 [ V_57 ] ;
if ( V_55 -> V_62 == 0 )
return V_55 ;
}
return NULL ;
}
static int F_43 ( struct V_12 * V_12 ,
struct V_56 * V_55 )
{
char V_63 [ V_64 ] ;
F_44 ( V_63 , true ,
(enum V_65 ) V_55 -> V_47 ,
V_55 -> V_66 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_67 ) , V_63 ) ;
}
static int F_45 ( struct V_12 * V_12 ,
struct V_56 * V_55 )
{
char V_63 [ V_64 ] ;
F_44 ( V_63 , false ,
(enum V_65 ) V_55 -> V_47 ,
V_55 -> V_66 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_67 ) , V_63 ) ;
}
static int
F_46 ( struct V_12 * V_12 ,
struct V_35 * V_40 ,
struct V_56 * V_55 )
{
char V_68 [ V_69 ] ;
T_3 V_70 = 0 ;
T_3 V_38 ;
T_3 V_71 = V_72 ;
F_24 (prefix, prefix_usage)
V_70 = V_38 ;
F_47 ( V_68 , V_70 , V_55 -> V_66 ) ;
F_24 (prefix, prefix_usage) {
if ( V_38 == 0 )
continue;
F_48 ( V_68 , V_38 , V_71 ,
V_72 ) ;
V_71 = V_38 ;
}
return F_9 ( V_12 -> V_20 , F_7 ( V_73 ) , V_68 ) ;
}
static struct V_56 *
F_49 ( struct V_12 * V_12 ,
struct V_35 * V_40 ,
enum V_46 V_47 )
{
struct V_56 * V_55 ;
int V_19 ;
V_55 = F_42 ( V_12 ) ;
if ( ! V_55 )
return F_35 ( - V_74 ) ;
V_55 -> V_47 = V_47 ;
V_19 = F_43 ( V_12 , V_55 ) ;
if ( V_19 )
return F_35 ( V_19 ) ;
V_19 = F_46 ( V_12 , V_40 ,
V_55 ) ;
if ( V_19 )
goto V_75;
memcpy ( & V_55 -> V_40 , V_40 ,
sizeof( V_55 -> V_40 ) ) ;
return V_55 ;
V_75:
F_45 ( V_12 , V_55 ) ;
return F_35 ( V_19 ) ;
}
static int F_50 ( struct V_12 * V_12 ,
struct V_56 * V_55 )
{
return F_45 ( V_12 , V_55 ) ;
}
static struct V_56 *
F_51 ( struct V_12 * V_12 ,
struct V_35 * V_40 ,
enum V_46 V_47 )
{
struct V_56 * V_55 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_12 -> V_58 -> V_59 . V_60 ; V_57 ++ ) {
V_55 = & V_12 -> V_58 -> V_59 . V_61 [ V_57 ] ;
if ( V_55 -> V_62 != 0 &&
V_55 -> V_47 == V_47 &&
F_26 ( & V_55 -> V_40 ,
V_40 ) )
goto V_76;
}
V_55 = F_49 ( V_12 , V_40 ,
V_47 ) ;
if ( F_52 ( V_55 ) )
return V_55 ;
V_76:
V_55 -> V_62 ++ ;
return V_55 ;
}
static int F_53 ( struct V_12 * V_12 ,
struct V_56 * V_55 )
{
if ( -- V_55 -> V_62 == 0 )
return F_50 ( V_12 , V_55 ) ;
return 0 ;
}
static int F_54 ( struct V_12 * V_12 )
{
struct V_56 * V_55 ;
T_2 V_77 ;
int V_57 ;
if ( ! F_55 ( V_12 -> V_20 , V_78 ) )
return - V_79 ;
V_77 = F_56 ( V_12 -> V_20 , V_78 ) ;
V_12 -> V_58 -> V_59 . V_60 = V_77 - V_80 ;
V_12 -> V_58 -> V_59 . V_61 = F_57 ( V_12 -> V_58 -> V_59 . V_60 ,
sizeof( struct V_56 ) ,
V_49 ) ;
if ( ! V_12 -> V_58 -> V_59 . V_61 )
return - V_50 ;
for ( V_57 = 0 ; V_57 < V_12 -> V_58 -> V_59 . V_60 ; V_57 ++ ) {
V_55 = & V_12 -> V_58 -> V_59 . V_61 [ V_57 ] ;
V_55 -> V_66 = V_57 + V_80 ;
}
return 0 ;
}
static void F_58 ( struct V_12 * V_12 )
{
F_38 ( V_12 -> V_58 -> V_59 . V_61 ) ;
}
static bool F_59 ( const struct V_44 * V_45 )
{
return ! ! V_45 -> V_81 ;
}
static struct V_44 * F_60 ( struct V_12 * V_12 )
{
struct V_44 * V_45 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_82 ) ; V_57 ++ ) {
V_45 = & V_12 -> V_58 -> V_83 [ V_57 ] ;
if ( ! F_59 ( V_45 ) )
return V_45 ;
}
return NULL ;
}
static int F_61 ( struct V_12 * V_12 ,
const struct V_43 * V_48 )
{
char V_84 [ V_85 ] ;
F_62 ( V_84 , V_48 -> V_45 -> V_66 ,
(enum V_65 ) V_48 -> V_47 ,
V_48 -> V_55 -> V_66 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_86 ) , V_84 ) ;
}
static int F_63 ( struct V_12 * V_12 ,
const struct V_43 * V_48 )
{
char V_84 [ V_85 ] ;
F_62 ( V_84 , V_48 -> V_45 -> V_66 ,
(enum V_65 ) V_48 -> V_47 , 0 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_86 ) , V_84 ) ;
}
static T_4 F_64 ( T_4 V_87 )
{
if ( V_87 == V_88 )
V_87 = V_89 ;
return V_87 ;
}
static struct V_44 * F_65 ( struct V_12 * V_12 ,
T_4 V_87 )
{
struct V_44 * V_45 ;
int V_57 ;
V_87 = F_64 ( V_87 ) ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_82 ) ; V_57 ++ ) {
V_45 = & V_12 -> V_58 -> V_83 [ V_57 ] ;
if ( F_59 ( V_45 ) && V_45 -> V_87 == V_87 )
return V_45 ;
}
return NULL ;
}
static struct V_43 * F_66 ( const struct V_44 * V_45 ,
enum V_46 V_47 )
{
switch ( V_47 ) {
case V_90 :
return V_45 -> V_81 ;
case V_91 :
F_67 ( 1 ) ;
}
return NULL ;
}
static struct V_44 * F_68 ( struct V_12 * V_12 ,
T_4 V_87 )
{
struct V_44 * V_45 ;
V_45 = F_60 ( V_12 ) ;
if ( ! V_45 )
return F_35 ( - V_74 ) ;
V_45 -> V_81 = F_33 ( V_45 , V_90 ) ;
if ( F_52 ( V_45 -> V_81 ) )
return F_69 ( V_45 -> V_81 ) ;
V_45 -> V_87 = V_87 ;
return V_45 ;
}
static void F_70 ( struct V_44 * V_45 )
{
F_39 ( V_45 -> V_81 ) ;
V_45 -> V_81 = NULL ;
}
static int
F_71 ( struct V_12 * V_12 , struct V_43 * V_48 ,
struct V_35 * V_92 )
{
struct V_56 * V_55 = V_48 -> V_55 ;
struct V_56 * V_93 ;
int V_19 ;
if ( F_26 ( V_92 , & V_55 -> V_40 ) )
return 0 ;
V_93 = F_51 ( V_12 , V_92 ,
V_48 -> V_47 ) ;
if ( F_52 ( V_93 ) ) {
if ( F_23 ( V_92 ,
& V_55 -> V_40 ) )
return 0 ;
return F_72 ( V_93 ) ;
}
V_48 -> V_55 = V_93 ;
V_19 = F_61 ( V_12 , V_48 ) ;
if ( V_19 )
goto V_94;
F_53 ( V_12 , V_55 ) ;
return 0 ;
V_94:
V_48 -> V_55 = V_55 ;
F_53 ( V_12 , V_93 ) ;
return V_19 ;
}
static struct V_44 * F_73 ( struct V_12 * V_12 , T_4 V_87 )
{
struct V_44 * V_45 ;
V_87 = F_64 ( V_87 ) ;
V_45 = F_65 ( V_12 , V_87 ) ;
if ( ! V_45 )
V_45 = F_68 ( V_12 , V_87 ) ;
return V_45 ;
}
static void F_74 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_95 && F_40 ( & V_45 -> V_81 -> V_54 ) )
F_70 ( V_45 ) ;
}
static int F_75 ( struct V_12 * V_12 )
{
struct V_44 * V_45 ;
T_2 V_96 ;
int V_57 ;
if ( ! F_55 ( V_12 -> V_20 , V_82 ) )
return - V_79 ;
V_96 = F_56 ( V_12 -> V_20 , V_82 ) ;
V_12 -> V_58 -> V_83 = F_57 ( V_96 , sizeof( struct V_44 ) ,
V_49 ) ;
if ( ! V_12 -> V_58 -> V_83 )
return - V_50 ;
for ( V_57 = 0 ; V_57 < V_96 ; V_57 ++ ) {
V_45 = & V_12 -> V_58 -> V_83 [ V_57 ] ;
V_45 -> V_66 = V_57 ;
}
return 0 ;
}
static void F_76 ( struct V_12 * V_12 )
{
F_77 () ;
F_78 ( V_12 ) ;
F_38 ( V_12 -> V_58 -> V_83 ) ;
}
static struct V_97 *
F_79 ( struct V_12 * V_12 , struct V_98 * V_99 ,
T_1 V_2 )
{
struct V_97 * V_100 ;
V_100 = F_34 ( sizeof( * V_100 ) , V_49 ) ;
if ( ! V_100 )
return NULL ;
V_100 -> V_101 . V_99 = V_99 ;
V_100 -> V_2 = V_2 ;
F_37 ( & V_100 -> V_102 ) ;
return V_100 ;
}
static void F_80 ( struct V_97 * V_100 )
{
F_38 ( V_100 ) ;
}
static int
F_81 ( struct V_12 * V_12 ,
struct V_97 * V_100 )
{
return F_82 ( & V_12 -> V_58 -> V_103 ,
& V_100 -> V_104 ,
V_105 ) ;
}
static void
F_83 ( struct V_12 * V_12 ,
struct V_97 * V_100 )
{
F_84 ( & V_12 -> V_58 -> V_103 ,
& V_100 -> V_104 ,
V_105 ) ;
}
static struct V_97 *
F_85 ( struct V_12 * V_12 , struct V_98 * V_99 )
{
struct V_97 * V_100 ;
struct V_1 * V_2 ;
int V_19 ;
V_2 = F_86 ( V_12 , V_99 -> V_106 ) ;
if ( ! V_2 )
return F_35 ( - V_26 ) ;
V_100 = F_79 ( V_12 , V_99 , V_2 -> V_13 ) ;
if ( ! V_100 )
return F_35 ( - V_50 ) ;
V_19 = F_81 ( V_12 , V_100 ) ;
if ( V_19 )
goto V_107;
F_87 ( & V_100 -> V_108 , & V_2 -> V_109 ) ;
return V_100 ;
V_107:
F_80 ( V_100 ) ;
return F_35 ( V_19 ) ;
}
static void
F_88 ( struct V_12 * V_12 ,
struct V_97 * V_100 )
{
F_89 ( & V_100 -> V_108 ) ;
F_83 ( V_12 , V_100 ) ;
F_80 ( V_100 ) ;
}
static struct V_97 *
F_90 ( struct V_12 * V_12 , struct V_98 * V_99 )
{
struct V_110 V_101 ;
V_101 . V_99 = V_99 ;
return F_91 ( & V_12 -> V_58 -> V_103 ,
& V_101 , V_105 ) ;
}
static void
F_92 ( struct V_12 * V_12 )
{
unsigned long V_111 = F_93 ( & V_112 . V_113 , V_114 ) ;
V_12 -> V_58 -> V_115 . V_111 = F_94 ( V_111 ) ;
}
static void F_95 ( struct V_12 * V_12 ,
char * V_116 ,
int V_117 )
{
struct V_118 * V_106 ;
struct V_98 * V_99 ;
T_5 V_119 ;
T_4 V_120 ;
T_1 V_2 ;
F_96 ( V_116 , V_117 , & V_2 , & V_120 ) ;
if ( ! V_12 -> V_58 -> V_121 [ V_2 ] ) {
F_97 ( V_12 -> V_122 -> V_106 , L_1 ) ;
return;
}
V_119 = F_98 ( V_120 ) ;
V_106 = V_12 -> V_58 -> V_121 [ V_2 ] -> V_106 ;
V_99 = F_99 ( & V_112 , & V_119 , V_106 ) ;
if ( ! V_99 ) {
F_100 ( V_106 , L_2 ,
& V_120 ) ;
return;
}
F_101 ( V_106 , L_3 , & V_120 ) ;
F_102 ( V_99 , NULL ) ;
F_103 ( V_99 ) ;
}
static void F_104 ( struct V_12 * V_12 ,
char * V_116 ,
int V_123 )
{
T_3 V_124 ;
int V_57 ;
V_124 = F_105 ( V_116 ,
V_123 ) ;
V_124 ++ ;
for ( V_57 = 0 ; V_57 < V_124 ; V_57 ++ ) {
int V_117 ;
V_117 = V_123 * V_125 + V_57 ;
F_95 ( V_12 , V_116 ,
V_117 ) ;
}
}
static void F_106 ( struct V_12 * V_12 ,
char * V_116 , int V_123 )
{
switch ( F_107 ( V_116 , V_123 ) ) {
case V_126 :
F_104 ( V_12 , V_116 ,
V_123 ) ;
break;
case V_127 :
F_108 ( 1 ) ;
break;
}
}
static bool F_109 ( char * V_116 )
{
T_3 V_128 , V_129 , V_124 ;
V_128 = F_110 ( V_116 ) ;
V_129 = V_128 - 1 ;
if ( V_128 < V_130 )
return false ;
if ( F_107 ( V_116 , V_129 ) ==
V_127 )
return true ;
V_124 = F_105 ( V_116 ,
V_129 ) ;
if ( ++ V_124 == V_125 )
return true ;
return false ;
}
static int F_111 ( struct V_12 * V_12 )
{
char * V_116 ;
T_3 V_128 ;
int V_57 , V_19 ;
V_116 = F_112 ( V_131 , V_49 ) ;
if ( ! V_116 )
return - V_50 ;
F_113 () ;
do {
F_114 ( V_116 , V_126 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_132 ) ,
V_116 ) ;
if ( V_19 ) {
F_97 ( V_12 -> V_122 -> V_106 , L_4 ) ;
break;
}
V_128 = F_110 ( V_116 ) ;
for ( V_57 = 0 ; V_57 < V_128 ; V_57 ++ )
F_106 ( V_12 , V_116 ,
V_57 ) ;
} while ( F_109 ( V_116 ) );
F_115 () ;
F_38 ( V_116 ) ;
return V_19 ;
}
static void F_116 ( struct V_12 * V_12 )
{
struct V_97 * V_100 ;
F_113 () ;
F_117 (neigh_entry, &mlxsw_sp->router->nexthop_neighs_list,
nexthop_neighs_list_node)
F_102 ( V_100 -> V_101 . V_99 , NULL ) ;
F_115 () ;
}
static void
F_118 ( struct V_12 * V_12 )
{
unsigned long V_111 = V_12 -> V_58 -> V_115 . V_111 ;
F_119 ( & V_12 -> V_58 -> V_115 . V_133 ,
F_120 ( V_111 ) ) ;
}
static void F_121 ( struct V_134 * V_135 )
{
struct V_136 * V_58 ;
int V_19 ;
V_58 = F_122 ( V_135 , struct V_136 ,
V_115 . V_133 . V_135 ) ;
V_19 = F_111 ( V_58 -> V_12 ) ;
if ( V_19 )
F_123 ( V_58 -> V_12 -> V_122 -> V_106 , L_5 ) ;
F_116 ( V_58 -> V_12 ) ;
F_118 ( V_58 -> V_12 ) ;
}
static void F_124 ( struct V_134 * V_135 )
{
struct V_97 * V_100 ;
struct V_136 * V_58 ;
V_58 = F_122 ( V_135 , struct V_136 ,
V_137 . V_135 ) ;
F_113 () ;
F_117 (neigh_entry, &router->nexthop_neighs_list,
nexthop_neighs_list_node)
if ( ! V_100 -> V_138 )
F_102 ( V_100 -> V_101 . V_99 , NULL ) ;
F_115 () ;
F_119 ( & V_58 -> V_137 ,
V_139 ) ;
}
static enum V_140 F_125 ( bool V_141 )
{
return V_141 ? V_142 :
V_143 ;
}
static void
F_126 ( struct V_12 * V_12 ,
struct V_97 * V_100 ,
enum V_140 V_144 )
{
struct V_98 * V_99 = V_100 -> V_101 . V_99 ;
T_4 V_120 = F_127 ( * ( ( T_5 * ) V_99 -> V_145 ) ) ;
char V_146 [ V_147 ] ;
F_128 ( V_146 , V_144 , V_100 -> V_2 , V_100 -> V_148 ,
V_120 ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_149 ) , V_146 ) ;
}
static void
F_129 ( struct V_12 * V_12 ,
struct V_97 * V_100 ,
bool V_141 )
{
if ( ! V_141 && ! V_100 -> V_138 )
return;
V_100 -> V_138 = V_141 ;
if ( V_100 -> V_101 . V_99 -> V_150 == & V_112 )
F_126 ( V_12 , V_100 ,
F_125 ( V_141 ) ) ;
else
F_108 ( 1 ) ;
}
static void F_130 ( struct V_134 * V_135 )
{
struct V_151 * V_152 =
F_122 ( V_135 , struct V_151 , V_135 ) ;
struct V_12 * V_12 = V_152 -> V_12 ;
struct V_97 * V_100 ;
struct V_98 * V_99 = V_152 -> V_99 ;
unsigned char V_148 [ V_153 ] ;
bool V_154 ;
T_3 V_155 , V_156 ;
F_131 ( & V_99 -> V_157 ) ;
memcpy ( V_148 , V_99 -> V_148 , V_153 ) ;
V_155 = V_99 -> V_155 ;
V_156 = V_99 -> V_156 ;
F_132 ( & V_99 -> V_157 ) ;
F_113 () ;
V_154 = V_155 & V_158 && ! V_156 ;
V_100 = F_90 ( V_12 , V_99 ) ;
if ( ! V_154 && ! V_100 )
goto V_159;
if ( ! V_100 ) {
V_100 = F_85 ( V_12 , V_99 ) ;
if ( F_52 ( V_100 ) )
goto V_159;
}
memcpy ( V_100 -> V_148 , V_148 , V_153 ) ;
F_129 ( V_12 , V_100 , V_154 ) ;
F_133 ( V_12 , V_100 , ! V_154 ) ;
if ( ! V_100 -> V_138 && F_40 ( & V_100 -> V_102 ) )
F_88 ( V_12 , V_100 ) ;
V_159:
F_115 () ;
F_103 ( V_99 ) ;
F_38 ( V_152 ) ;
}
int F_134 ( struct V_160 * V_161 ,
unsigned long V_162 , void * V_163 )
{
struct V_151 * V_152 ;
struct V_164 * V_164 ;
struct V_12 * V_12 ;
unsigned long V_111 ;
struct V_165 * V_166 ;
struct V_98 * V_99 ;
switch ( V_162 ) {
case V_167 :
V_166 = V_163 ;
if ( ! V_166 -> V_106 || V_166 -> V_150 != & V_112 )
return V_168 ;
V_164 = F_135 ( V_166 -> V_106 ) ;
if ( ! V_164 )
return V_168 ;
V_12 = V_164 -> V_12 ;
V_111 = F_94 ( F_93 ( V_166 , V_114 ) ) ;
V_12 -> V_58 -> V_115 . V_111 = V_111 ;
F_136 ( V_164 ) ;
break;
case V_169 :
V_99 = V_163 ;
if ( V_99 -> V_150 != & V_112 )
return V_168 ;
V_164 = F_135 ( V_99 -> V_106 ) ;
if ( ! V_164 )
return V_168 ;
V_152 = F_34 ( sizeof( * V_152 ) , V_170 ) ;
if ( ! V_152 ) {
F_136 ( V_164 ) ;
return V_171 ;
}
F_137 ( & V_152 -> V_135 , F_130 ) ;
V_152 -> V_12 = V_164 -> V_12 ;
V_152 -> V_99 = V_99 ;
F_138 ( V_99 ) ;
F_139 ( & V_152 -> V_135 ) ;
F_136 ( V_164 ) ;
break;
}
return V_168 ;
}
static int F_140 ( struct V_12 * V_12 )
{
int V_19 ;
V_19 = F_36 ( & V_12 -> V_58 -> V_103 ,
& V_105 ) ;
if ( V_19 )
return V_19 ;
F_92 ( V_12 ) ;
F_141 ( & V_12 -> V_58 -> V_115 . V_133 ,
F_121 ) ;
F_141 ( & V_12 -> V_58 -> V_137 ,
F_124 ) ;
F_119 ( & V_12 -> V_58 -> V_115 . V_133 , 0 ) ;
F_119 ( & V_12 -> V_58 -> V_137 , 0 ) ;
return 0 ;
}
static void F_142 ( struct V_12 * V_12 )
{
F_143 ( & V_12 -> V_58 -> V_115 . V_133 ) ;
F_143 ( & V_12 -> V_58 -> V_137 ) ;
F_41 ( & V_12 -> V_58 -> V_103 ) ;
}
static int F_144 ( struct V_12 * V_12 ,
const struct V_1 * V_2 )
{
char V_146 [ V_147 ] ;
F_145 ( V_146 , V_172 ,
V_2 -> V_13 , V_2 -> V_173 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_149 ) , V_146 ) ;
}
static void F_146 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_97 * V_100 , * V_174 ;
F_144 ( V_12 , V_2 ) ;
F_147 (neigh_entry, tmp, &rif->neigh_list,
rif_list_node)
F_88 ( V_12 , V_100 ) ;
}
static int F_148 ( struct V_12 * V_12 ,
struct V_175 * V_176 )
{
return F_82 ( & V_12 -> V_58 -> V_177 ,
& V_176 -> V_104 ,
V_178 ) ;
}
static void F_149 ( struct V_12 * V_12 ,
struct V_175 * V_176 )
{
F_84 ( & V_12 -> V_58 -> V_177 ,
& V_176 -> V_104 ,
V_178 ) ;
}
static struct V_175 *
F_150 ( struct V_12 * V_12 ,
struct V_179 V_101 )
{
return F_91 ( & V_12 -> V_58 -> V_177 , & V_101 ,
V_178 ) ;
}
static int F_151 ( struct V_12 * V_12 ,
struct V_180 * V_181 )
{
return F_82 ( & V_12 -> V_58 -> V_182 ,
& V_181 -> V_104 , V_183 ) ;
}
static void F_152 ( struct V_12 * V_12 ,
struct V_180 * V_181 )
{
F_84 ( & V_12 -> V_58 -> V_182 , & V_181 -> V_104 ,
V_183 ) ;
}
static struct V_180 *
F_153 ( struct V_12 * V_12 ,
struct V_184 V_101 )
{
return F_91 ( & V_12 -> V_58 -> V_182 , & V_101 ,
V_183 ) ;
}
static int F_154 ( struct V_12 * V_12 ,
const struct V_43 * V_48 ,
T_4 V_185 , T_1 V_186 ,
T_4 V_187 ,
T_1 V_188 )
{
char V_189 [ V_190 ] ;
F_155 ( V_189 ,
(enum V_65 ) V_48 -> V_47 ,
V_48 -> V_45 -> V_66 , V_185 , V_186 , V_187 ,
V_188 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_191 ) , V_189 ) ;
}
static int F_156 ( struct V_12 * V_12 ,
struct V_175 * V_176 ,
T_4 V_192 , T_1 V_193 )
{
struct V_194 * V_195 ;
struct V_43 * V_48 = NULL ;
int V_19 ;
F_117 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_48 == V_195 -> V_196 -> V_48 )
continue;
V_48 = V_195 -> V_196 -> V_48 ;
V_19 = F_154 ( V_12 , V_48 ,
V_192 ,
V_193 ,
V_176 -> V_185 ,
V_176 -> V_186 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static int F_157 ( struct V_12 * V_12 , T_4 V_185 ,
struct V_180 * V_181 )
{
struct V_97 * V_100 = V_181 -> V_100 ;
char V_197 [ V_198 ] ;
F_158 ( V_197 , V_199 ,
true , V_185 , V_100 -> V_2 ) ;
F_159 ( V_197 , V_100 -> V_148 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_200 ) , V_197 ) ;
}
static int
F_160 ( struct V_12 * V_12 ,
struct V_175 * V_176 ,
bool V_201 )
{
T_4 V_185 = V_176 -> V_185 ;
struct V_180 * V_181 ;
int V_57 ;
int V_19 ;
for ( V_57 = 0 ; V_57 < V_176 -> V_202 ; V_57 ++ ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
if ( ! V_181 -> V_204 ) {
V_181 -> V_205 = 0 ;
continue;
}
if ( V_181 -> V_206 || V_201 ) {
V_19 = F_157 ( V_12 ,
V_185 , V_181 ) ;
if ( V_19 )
return V_19 ;
V_181 -> V_206 = 0 ;
V_181 -> V_205 = 1 ;
}
V_185 ++ ;
}
return 0 ;
}
static int
F_161 ( struct V_12 * V_12 ,
struct V_175 * V_176 )
{
struct V_194 * V_195 ;
int V_19 ;
F_117 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( ! F_162 ( V_195 -> V_196 ,
V_195 ) )
continue;
V_19 = F_163 ( V_12 , V_195 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void
F_164 ( struct V_12 * V_12 ,
struct V_175 * V_176 )
{
struct V_180 * V_181 ;
bool V_207 = false ;
T_4 V_185 ;
T_1 V_186 = 0 ;
bool V_208 ;
T_4 V_192 ;
T_1 V_193 ;
int V_57 ;
int V_19 ;
if ( ! V_176 -> V_209 ) {
F_161 ( V_12 , V_176 ) ;
return;
}
for ( V_57 = 0 ; V_57 < V_176 -> V_202 ; V_57 ++ ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
if ( V_181 -> V_204 ^ V_181 -> V_205 ) {
V_207 = true ;
if ( V_181 -> V_204 )
V_181 -> V_206 = 1 ;
}
if ( V_181 -> V_204 )
V_186 ++ ;
}
if ( ! V_207 ) {
V_19 = F_160 ( V_12 , V_176 ,
false ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_6 ) ;
goto V_210;
}
return;
}
if ( ! V_186 )
goto V_210;
V_19 = F_166 ( V_12 , V_186 , & V_185 ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_7 ) ;
goto V_210;
}
V_208 = V_176 -> V_211 ;
V_192 = V_176 -> V_185 ;
V_193 = V_176 -> V_186 ;
V_176 -> V_211 = 1 ;
V_176 -> V_185 = V_185 ;
V_176 -> V_186 = V_186 ;
V_19 = F_160 ( V_12 , V_176 , true ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_6 ) ;
goto V_210;
}
if ( ! V_208 ) {
V_19 = F_161 ( V_12 , V_176 ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_8 ) ;
goto V_210;
}
return;
}
V_19 = F_156 ( V_12 , V_176 ,
V_192 , V_193 ) ;
F_167 ( V_12 , V_192 ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_9 ) ;
goto V_210;
}
return;
V_210:
V_208 = V_176 -> V_211 ;
V_176 -> V_211 = 0 ;
for ( V_57 = 0 ; V_57 < V_176 -> V_202 ; V_57 ++ ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
V_181 -> V_205 = 0 ;
}
V_19 = F_161 ( V_12 , V_176 ) ;
if ( V_19 )
F_165 ( V_12 -> V_122 -> V_106 , L_10 ) ;
if ( V_208 )
F_167 ( V_12 , V_176 -> V_185 ) ;
}
static void F_168 ( struct V_180 * V_181 ,
bool V_212 )
{
if ( ! V_212 && ! V_181 -> V_204 )
V_181 -> V_204 = 1 ;
else if ( V_212 && V_181 -> V_205 )
V_181 -> V_204 = 0 ;
V_181 -> V_206 = 1 ;
}
static void
F_133 ( struct V_12 * V_12 ,
struct V_97 * V_100 ,
bool V_212 )
{
struct V_180 * V_181 ;
F_117 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_168 ( V_181 , V_212 ) ;
F_164 ( V_12 , V_181 -> V_176 ) ;
}
}
static void F_169 ( struct V_180 * V_181 ,
struct V_1 * V_2 )
{
if ( V_181 -> V_2 )
return;
V_181 -> V_2 = V_2 ;
F_87 ( & V_181 -> V_108 , & V_2 -> V_102 ) ;
}
static void F_170 ( struct V_180 * V_181 )
{
if ( ! V_181 -> V_2 )
return;
F_89 ( & V_181 -> V_108 ) ;
V_181 -> V_2 = NULL ;
}
static int F_171 ( struct V_12 * V_12 ,
struct V_180 * V_181 )
{
struct V_97 * V_100 ;
struct V_213 * V_213 = V_181 -> V_101 . V_213 ;
struct V_98 * V_99 ;
T_3 V_155 , V_156 ;
int V_19 ;
if ( ! V_181 -> V_176 -> V_209 || V_181 -> V_100 )
return 0 ;
V_99 = F_99 ( & V_112 , & V_213 -> V_214 , V_213 -> V_215 ) ;
if ( ! V_99 ) {
V_99 = F_172 ( & V_112 , & V_213 -> V_214 , V_213 -> V_215 ) ;
if ( F_52 ( V_99 ) )
return F_72 ( V_99 ) ;
F_102 ( V_99 , NULL ) ;
}
V_100 = F_90 ( V_12 , V_99 ) ;
if ( ! V_100 ) {
V_100 = F_85 ( V_12 , V_99 ) ;
if ( F_52 ( V_100 ) ) {
V_19 = - V_26 ;
goto V_216;
}
}
if ( F_40 ( & V_100 -> V_102 ) )
F_173 ( & V_100 -> V_217 ,
& V_12 -> V_58 -> V_218 ) ;
V_181 -> V_100 = V_100 ;
F_173 ( & V_181 -> V_219 , & V_100 -> V_102 ) ;
F_131 ( & V_99 -> V_157 ) ;
V_155 = V_99 -> V_155 ;
V_156 = V_99 -> V_156 ;
F_132 ( & V_99 -> V_157 ) ;
F_168 ( V_181 , ! ( V_155 & V_158 && ! V_156 ) ) ;
return 0 ;
V_216:
F_103 ( V_99 ) ;
return V_19 ;
}
static void F_174 ( struct V_12 * V_12 ,
struct V_180 * V_181 )
{
struct V_97 * V_100 = V_181 -> V_100 ;
struct V_98 * V_99 ;
if ( ! V_100 )
return;
V_99 = V_100 -> V_101 . V_99 ;
F_168 ( V_181 , true ) ;
F_89 ( & V_181 -> V_219 ) ;
V_181 -> V_100 = NULL ;
if ( F_40 ( & V_100 -> V_102 ) )
F_89 ( & V_100 -> V_217 ) ;
if ( ! V_100 -> V_138 && F_40 ( & V_100 -> V_102 ) )
F_88 ( V_12 , V_100 ) ;
F_103 ( V_99 ) ;
}
static int F_175 ( struct V_12 * V_12 ,
struct V_175 * V_176 ,
struct V_180 * V_181 ,
struct V_213 * V_213 )
{
struct V_118 * V_106 = V_213 -> V_215 ;
struct V_220 * V_221 ;
struct V_1 * V_2 ;
int V_19 ;
V_181 -> V_176 = V_176 ;
V_181 -> V_101 . V_213 = V_213 ;
V_19 = F_151 ( V_12 , V_181 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_106 )
return 0 ;
V_221 = F_176 ( V_106 ) ;
if ( V_221 && F_177 ( V_221 ) &&
V_213 -> V_222 & V_223 )
return 0 ;
V_2 = F_86 ( V_12 , V_106 ) ;
if ( ! V_2 )
return 0 ;
F_169 ( V_181 , V_2 ) ;
V_19 = F_171 ( V_12 , V_181 ) ;
if ( V_19 )
goto V_224;
return 0 ;
V_224:
F_170 ( V_181 ) ;
F_152 ( V_12 , V_181 ) ;
return V_19 ;
}
static void F_178 ( struct V_12 * V_12 ,
struct V_180 * V_181 )
{
F_174 ( V_12 , V_181 ) ;
F_170 ( V_181 ) ;
F_152 ( V_12 , V_181 ) ;
}
static void F_179 ( struct V_12 * V_12 ,
unsigned long V_162 , struct V_213 * V_213 )
{
struct V_184 V_101 ;
struct V_180 * V_181 ;
struct V_1 * V_2 ;
if ( V_12 -> V_58 -> V_225 )
return;
V_101 . V_213 = V_213 ;
V_181 = F_153 ( V_12 , V_101 ) ;
if ( F_108 ( ! V_181 ) )
return;
V_2 = F_86 ( V_12 , V_213 -> V_215 ) ;
if ( ! V_2 )
return;
switch ( V_162 ) {
case V_226 :
F_169 ( V_181 , V_2 ) ;
F_171 ( V_12 , V_181 ) ;
break;
case V_227 :
F_174 ( V_12 , V_181 ) ;
F_170 ( V_181 ) ;
break;
}
F_164 ( V_12 , V_181 -> V_176 ) ;
}
static void F_180 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_180 * V_181 , * V_174 ;
F_147 (nh, tmp, &rif->nexthop_list, rif_list_node) {
F_174 ( V_12 , V_181 ) ;
F_170 ( V_181 ) ;
F_164 ( V_12 , V_181 -> V_176 ) ;
}
}
static struct V_175 *
F_181 ( struct V_12 * V_12 , struct V_228 * V_229 )
{
struct V_175 * V_176 ;
struct V_180 * V_181 ;
struct V_213 * V_213 ;
T_6 V_230 ;
int V_57 ;
int V_19 ;
V_230 = sizeof( * V_176 ) +
V_229 -> V_231 * sizeof( struct V_180 ) ;
V_176 = F_34 ( V_230 , V_49 ) ;
if ( ! V_176 )
return F_35 ( - V_50 ) ;
F_37 ( & V_176 -> V_232 ) ;
V_176 -> V_209 = V_229 -> V_213 -> V_233 == V_234 ;
V_176 -> V_202 = V_229 -> V_231 ;
V_176 -> V_101 . V_229 = V_229 ;
F_182 ( V_229 ) ;
for ( V_57 = 0 ; V_57 < V_176 -> V_202 ; V_57 ++ ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
V_213 = & V_229 -> V_213 [ V_57 ] ;
V_19 = F_175 ( V_12 , V_176 , V_181 , V_213 ) ;
if ( V_19 )
goto V_235;
}
V_19 = F_148 ( V_12 , V_176 ) ;
if ( V_19 )
goto V_236;
F_164 ( V_12 , V_176 ) ;
return V_176 ;
V_236:
V_235:
for ( V_57 -- ; V_57 >= 0 ; V_57 -- ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
F_178 ( V_12 , V_181 ) ;
}
F_183 ( V_176 -> V_101 . V_229 ) ;
F_38 ( V_176 ) ;
return F_35 ( V_19 ) ;
}
static void
F_184 ( struct V_12 * V_12 ,
struct V_175 * V_176 )
{
struct V_180 * V_181 ;
int V_57 ;
F_149 ( V_12 , V_176 ) ;
for ( V_57 = 0 ; V_57 < V_176 -> V_202 ; V_57 ++ ) {
V_181 = & V_176 -> V_203 [ V_57 ] ;
F_178 ( V_12 , V_181 ) ;
}
F_164 ( V_12 , V_176 ) ;
F_108 ( V_176 -> V_211 ) ;
F_183 ( V_176 -> V_101 . V_229 ) ;
F_38 ( V_176 ) ;
}
static int F_185 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
struct V_228 * V_229 )
{
struct V_179 V_101 ;
struct V_175 * V_176 ;
V_101 . V_229 = V_229 ;
V_176 = F_150 ( V_12 , V_101 ) ;
if ( ! V_176 ) {
V_176 = F_181 ( V_12 , V_229 ) ;
if ( F_52 ( V_176 ) )
return F_72 ( V_176 ) ;
}
F_173 ( & V_195 -> V_237 , & V_176 -> V_232 ) ;
V_195 -> V_238 = V_176 ;
return 0 ;
}
static void F_186 ( struct V_12 * V_12 ,
struct V_194 * V_195 )
{
struct V_175 * V_176 = V_195 -> V_238 ;
F_89 ( & V_195 -> V_237 ) ;
if ( ! F_40 ( & V_176 -> V_232 ) )
return;
F_184 ( V_12 , V_176 ) ;
}
static bool
F_187 ( const struct V_194 * V_195 )
{
struct V_175 * V_238 = V_195 -> V_238 ;
if ( V_195 -> V_239 . V_240 )
return false ;
switch ( V_195 -> type ) {
case V_241 :
return ! ! V_238 -> V_211 ;
case V_242 :
return ! ! V_238 -> V_243 ;
default:
return false ;
}
}
static void F_188 ( struct V_194 * V_195 )
{
V_195 -> V_205 = true ;
switch ( V_195 -> V_196 -> V_48 -> V_47 ) {
case V_90 :
F_189 ( V_195 -> V_238 -> V_101 . V_229 ) ;
break;
case V_91 :
F_108 ( 1 ) ;
}
}
static void
F_190 ( struct V_194 * V_195 )
{
switch ( V_195 -> V_196 -> V_48 -> V_47 ) {
case V_90 :
F_191 ( V_195 -> V_238 -> V_101 . V_229 ) ;
break;
case V_91 :
F_108 ( 1 ) ;
}
V_195 -> V_205 = false ;
}
static void
F_192 ( struct V_194 * V_195 ,
enum V_244 V_144 , int V_19 )
{
switch ( V_144 ) {
case V_245 :
if ( ! V_195 -> V_205 )
return;
return F_190 ( V_195 ) ;
case V_246 :
if ( V_19 )
return;
if ( F_187 ( V_195 ) &&
! V_195 -> V_205 )
F_188 ( V_195 ) ;
else if ( ! F_187 ( V_195 ) &&
V_195 -> V_205 )
F_190 ( V_195 ) ;
return;
default:
return;
}
}
static int F_193 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
enum V_244 V_144 )
{
char V_247 [ V_248 ] ;
struct V_43 * V_48 = V_195 -> V_196 -> V_48 ;
T_4 * V_249 = ( T_4 * ) V_195 -> V_196 -> V_101 . V_173 ;
enum V_250 V_251 ;
T_1 V_252 = 0 ;
T_4 V_253 = 0 ;
T_1 V_186 = 0 ;
if ( F_187 ( V_195 ) ) {
V_251 = V_254 ;
V_253 = V_195 -> V_238 -> V_185 ;
V_186 = V_195 -> V_238 -> V_186 ;
} else {
V_251 = V_255 ;
V_252 = V_256 ;
}
F_194 ( V_247 ,
(enum V_65 ) V_48 -> V_47 , V_144 ,
V_48 -> V_45 -> V_66 , V_195 -> V_196 -> V_101 . V_42 ,
* V_249 ) ;
F_195 ( V_247 , V_251 , V_252 ,
V_253 , V_186 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_257 ) , V_247 ) ;
}
static int F_196 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
enum V_244 V_144 )
{
struct V_1 * V_2 = V_195 -> V_238 -> V_243 ;
struct V_43 * V_48 = V_195 -> V_196 -> V_48 ;
enum V_250 V_251 ;
char V_247 [ V_248 ] ;
T_4 * V_249 = ( T_4 * ) V_195 -> V_196 -> V_101 . V_173 ;
T_1 V_252 = 0 ;
T_1 V_13 = 0 ;
if ( F_187 ( V_195 ) ) {
V_251 = V_254 ;
V_13 = V_2 -> V_13 ;
} else {
V_251 = V_255 ;
V_252 = V_256 ;
}
F_194 ( V_247 ,
(enum V_65 ) V_48 -> V_47 , V_144 ,
V_48 -> V_45 -> V_66 , V_195 -> V_196 -> V_101 . V_42 ,
* V_249 ) ;
F_197 ( V_247 , V_251 , V_252 ,
V_13 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_257 ) , V_247 ) ;
}
static int F_198 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
enum V_244 V_144 )
{
struct V_43 * V_48 = V_195 -> V_196 -> V_48 ;
char V_247 [ V_248 ] ;
T_4 * V_249 = ( T_4 * ) V_195 -> V_196 -> V_101 . V_173 ;
F_194 ( V_247 ,
(enum V_65 ) V_48 -> V_47 , V_144 ,
V_48 -> V_45 -> V_66 , V_195 -> V_196 -> V_101 . V_42 ,
* V_249 ) ;
F_199 ( V_247 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_257 ) , V_247 ) ;
}
static int F_200 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
enum V_244 V_144 )
{
switch ( V_195 -> type ) {
case V_241 :
return F_193 ( V_12 , V_195 , V_144 ) ;
case V_242 :
return F_196 ( V_12 , V_195 , V_144 ) ;
case V_258 :
return F_198 ( V_12 , V_195 , V_144 ) ;
}
return - V_26 ;
}
static int F_201 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
enum V_244 V_144 )
{
int V_19 = - V_26 ;
switch ( V_195 -> V_196 -> V_48 -> V_47 ) {
case V_90 :
V_19 = F_200 ( V_12 , V_195 , V_144 ) ;
break;
case V_91 :
return V_19 ;
}
F_192 ( V_195 , V_144 , V_19 ) ;
return V_19 ;
}
static int F_163 ( struct V_12 * V_12 ,
struct V_194 * V_195 )
{
return F_201 ( V_12 , V_195 ,
V_246 ) ;
}
static int F_202 ( struct V_12 * V_12 ,
struct V_194 * V_195 )
{
return F_201 ( V_12 , V_195 ,
V_245 ) ;
}
static int
F_203 ( struct V_12 * V_12 ,
const struct V_259 * V_260 ,
struct V_194 * V_195 )
{
struct V_228 * V_229 = V_260 -> V_229 ;
switch ( V_260 -> type ) {
case V_261 :
case V_262 :
V_195 -> type = V_258 ;
return 0 ;
case V_263 :
case V_264 :
case V_265 :
V_195 -> type = V_242 ;
return 0 ;
case V_266 :
if ( V_229 -> V_213 -> V_233 != V_234 )
V_195 -> type = V_242 ;
else
V_195 -> type = V_241 ;
return 0 ;
default:
return - V_26 ;
}
}
static struct V_194 *
F_204 ( struct V_12 * V_12 ,
struct V_267 * V_196 ,
const struct V_259 * V_260 )
{
struct V_194 * V_195 ;
int V_19 ;
V_195 = F_34 ( sizeof( * V_195 ) , V_49 ) ;
if ( ! V_195 ) {
V_19 = - V_50 ;
goto V_268;
}
V_19 = F_203 ( V_12 , V_260 , V_195 ) ;
if ( V_19 )
goto V_269;
V_19 = F_185 ( V_12 , V_195 , V_260 -> V_229 ) ;
if ( V_19 )
goto V_270;
V_195 -> V_239 . V_271 = V_260 -> V_229 -> V_272 ;
V_195 -> V_239 . V_87 = V_260 -> V_87 ;
V_195 -> V_239 . type = V_260 -> type ;
V_195 -> V_239 . V_240 = V_260 -> V_240 ;
V_195 -> V_196 = V_196 ;
return V_195 ;
V_270:
V_269:
F_38 ( V_195 ) ;
V_268:
return F_35 ( V_19 ) ;
}
static void F_205 ( struct V_12 * V_12 ,
struct V_194 * V_195 )
{
F_186 ( V_12 , V_195 ) ;
F_38 ( V_195 ) ;
}
static struct V_194 *
F_206 ( struct V_12 * V_12 ,
const struct V_259 * V_260 )
{
struct V_194 * V_195 ;
struct V_267 * V_196 ;
V_196 = F_207 ( V_12 , V_260 ) ;
if ( F_52 ( V_196 ) )
return NULL ;
F_117 (fib_entry, &fib_node->entry_list, list) {
if ( V_195 -> V_239 . V_87 == V_260 -> V_87 &&
V_195 -> V_239 . V_240 == V_260 -> V_240 &&
V_195 -> V_239 . type == V_260 -> type &&
V_195 -> V_238 -> V_101 . V_229 == V_260 -> V_229 ) {
return V_195 ;
}
}
return NULL ;
}
static int F_208 ( struct V_43 * V_48 ,
struct V_267 * V_196 )
{
return F_82 ( & V_48 -> V_51 , & V_196 -> V_104 ,
V_52 ) ;
}
static void F_209 ( struct V_43 * V_48 ,
struct V_267 * V_196 )
{
F_84 ( & V_48 -> V_51 , & V_196 -> V_104 ,
V_52 ) ;
}
static struct V_267 *
F_210 ( struct V_43 * V_48 , const void * V_173 ,
T_6 V_273 , unsigned char V_42 )
{
struct V_274 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
memcpy ( V_101 . V_173 , V_173 , V_273 ) ;
V_101 . V_42 = V_42 ;
return F_91 ( & V_48 -> V_51 , & V_101 , V_52 ) ;
}
static struct V_267 *
F_211 ( struct V_43 * V_48 , const void * V_173 ,
T_6 V_273 , unsigned char V_42 )
{
struct V_267 * V_196 ;
V_196 = F_34 ( sizeof( * V_196 ) , V_49 ) ;
if ( ! V_196 )
return NULL ;
F_37 ( & V_196 -> V_275 ) ;
F_87 ( & V_196 -> V_276 , & V_48 -> V_54 ) ;
memcpy ( V_196 -> V_101 . V_173 , V_173 , V_273 ) ;
V_196 -> V_101 . V_42 = V_42 ;
return V_196 ;
}
static void F_212 ( struct V_267 * V_196 )
{
F_89 ( & V_196 -> V_276 ) ;
F_18 ( ! F_40 ( & V_196 -> V_275 ) ) ;
F_38 ( V_196 ) ;
}
static bool
F_162 ( const struct V_267 * V_196 ,
const struct V_194 * V_195 )
{
return F_213 ( & V_196 -> V_275 ,
struct V_194 , V_276 ) == V_195 ;
}
static void F_214 ( struct V_267 * V_196 )
{
unsigned char V_42 = V_196 -> V_101 . V_42 ;
struct V_43 * V_48 = V_196 -> V_48 ;
if ( V_48 -> V_277 [ V_42 ] ++ == 0 )
F_29 ( & V_48 -> V_40 , V_42 ) ;
}
static void F_215 ( struct V_267 * V_196 )
{
unsigned char V_42 = V_196 -> V_101 . V_42 ;
struct V_43 * V_48 = V_196 -> V_48 ;
if ( -- V_48 -> V_277 [ V_42 ] == 0 )
F_31 ( & V_48 -> V_40 , V_42 ) ;
}
static int F_216 ( struct V_12 * V_12 ,
struct V_267 * V_196 ,
struct V_43 * V_48 )
{
struct V_35 V_92 ;
struct V_56 * V_55 ;
int V_19 ;
V_19 = F_208 ( V_48 , V_196 ) ;
if ( V_19 )
return V_19 ;
V_196 -> V_48 = V_48 ;
F_28 ( & V_92 , & V_48 -> V_40 ) ;
F_29 ( & V_92 , V_196 -> V_101 . V_42 ) ;
if ( ! F_27 ( & V_48 -> V_40 ) ) {
V_19 = F_71 ( V_12 , V_48 ,
& V_92 ) ;
if ( V_19 )
goto V_278;
} else {
V_55 = F_51 ( V_12 , & V_92 ,
V_48 -> V_47 ) ;
if ( F_52 ( V_55 ) )
return F_72 ( V_55 ) ;
V_48 -> V_55 = V_55 ;
V_19 = F_61 ( V_12 , V_48 ) ;
if ( V_19 )
goto V_94;
}
F_214 ( V_196 ) ;
return 0 ;
V_94:
V_48 -> V_55 = NULL ;
F_53 ( V_12 , V_55 ) ;
V_278:
V_196 -> V_48 = NULL ;
F_209 ( V_48 , V_196 ) ;
return V_19 ;
}
static void F_217 ( struct V_12 * V_12 ,
struct V_267 * V_196 )
{
struct V_56 * V_55 = V_196 -> V_48 -> V_55 ;
struct V_43 * V_48 = V_196 -> V_48 ;
F_215 ( V_196 ) ;
if ( F_27 ( & V_48 -> V_40 ) ) {
F_63 ( V_12 , V_48 ) ;
V_48 -> V_55 = NULL ;
F_53 ( V_12 , V_55 ) ;
} else {
F_71 ( V_12 , V_48 , & V_48 -> V_40 ) ;
}
V_196 -> V_48 = NULL ;
F_209 ( V_48 , V_196 ) ;
}
static struct V_267 *
F_207 ( struct V_12 * V_12 ,
const struct V_259 * V_260 )
{
struct V_267 * V_196 ;
struct V_43 * V_48 ;
struct V_44 * V_45 ;
int V_19 ;
V_45 = F_73 ( V_12 , V_260 -> V_87 ) ;
if ( F_52 ( V_45 ) )
return F_69 ( V_45 ) ;
V_48 = F_66 ( V_45 , V_90 ) ;
V_196 = F_210 ( V_48 , & V_260 -> V_279 ,
sizeof( V_260 -> V_279 ) ,
V_260 -> V_280 ) ;
if ( V_196 )
return V_196 ;
V_196 = F_211 ( V_48 , & V_260 -> V_279 ,
sizeof( V_260 -> V_279 ) ,
V_260 -> V_280 ) ;
if ( ! V_196 ) {
V_19 = - V_50 ;
goto V_281;
}
V_19 = F_216 ( V_12 , V_196 , V_48 ) ;
if ( V_19 )
goto V_282;
return V_196 ;
V_282:
F_212 ( V_196 ) ;
V_281:
F_74 ( V_45 ) ;
return F_35 ( V_19 ) ;
}
static void F_218 ( struct V_12 * V_12 ,
struct V_267 * V_196 )
{
struct V_44 * V_45 = V_196 -> V_48 -> V_45 ;
if ( ! F_40 ( & V_196 -> V_275 ) )
return;
F_217 ( V_12 , V_196 ) ;
F_212 ( V_196 ) ;
F_74 ( V_45 ) ;
}
static struct V_194 *
F_219 ( const struct V_267 * V_196 ,
const struct V_283 * V_239 )
{
struct V_194 * V_195 ;
F_117 (fib_entry, &fib_node->entry_list, list) {
if ( V_195 -> V_239 . V_87 > V_239 -> V_87 )
continue;
if ( V_195 -> V_239 . V_87 != V_239 -> V_87 )
break;
if ( V_195 -> V_239 . V_240 > V_239 -> V_240 )
continue;
if ( V_195 -> V_239 . V_271 >= V_239 -> V_271 ||
V_195 -> V_239 . V_240 < V_239 -> V_240 )
return V_195 ;
}
return NULL ;
}
static int F_220 ( struct V_194 * V_195 ,
struct V_194 * V_284 )
{
struct V_267 * V_196 ;
if ( F_18 ( ! V_195 ) )
return - V_26 ;
V_196 = V_195 -> V_196 ;
F_221 (fib_entry, &fib_node->entry_list, list) {
if ( V_195 -> V_239 . V_87 != V_284 -> V_239 . V_87 ||
V_195 -> V_239 . V_240 != V_284 -> V_239 . V_240 ||
V_195 -> V_239 . V_271 != V_284 -> V_239 . V_271 )
break;
}
F_173 ( & V_284 -> V_276 , & V_195 -> V_276 ) ;
return 0 ;
}
static int
F_222 ( struct V_267 * V_196 ,
struct V_194 * V_284 ,
bool V_285 , bool V_286 )
{
struct V_194 * V_195 ;
V_195 = F_219 ( V_196 , & V_284 -> V_239 ) ;
if ( V_286 )
return F_220 ( V_195 , V_284 ) ;
if ( V_285 && F_18 ( ! V_195 ) )
return - V_26 ;
if ( V_195 ) {
F_173 ( & V_284 -> V_276 , & V_195 -> V_276 ) ;
} else {
struct V_194 * V_287 ;
F_117 (last, &fib_node->entry_list, list) {
if ( V_284 -> V_239 . V_87 > V_287 -> V_239 . V_87 )
break;
V_195 = V_287 ;
}
if ( V_195 )
F_87 ( & V_284 -> V_276 , & V_195 -> V_276 ) ;
else
F_87 ( & V_284 -> V_276 , & V_196 -> V_275 ) ;
}
return 0 ;
}
static void
F_223 ( struct V_194 * V_195 )
{
F_89 ( & V_195 -> V_276 ) ;
}
static int
F_224 ( struct V_12 * V_12 ,
const struct V_267 * V_196 ,
struct V_194 * V_195 )
{
if ( ! F_162 ( V_196 , V_195 ) )
return 0 ;
if ( ! F_225 ( & V_196 -> V_275 ) ) {
enum V_244 V_144 = V_245 ;
struct V_194 * V_99 = F_226 ( V_195 , V_276 ) ;
F_192 ( V_99 , V_144 , 0 ) ;
}
return F_163 ( V_12 , V_195 ) ;
}
static void
F_227 ( struct V_12 * V_12 ,
const struct V_267 * V_196 ,
struct V_194 * V_195 )
{
if ( ! F_162 ( V_196 , V_195 ) )
return;
if ( ! F_225 ( & V_196 -> V_275 ) ) {
struct V_194 * V_99 = F_226 ( V_195 , V_276 ) ;
enum V_244 V_144 = V_245 ;
F_163 ( V_12 , V_99 ) ;
F_192 ( V_195 , V_144 , 0 ) ;
return;
}
F_202 ( V_12 , V_195 ) ;
}
static int F_228 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
bool V_285 , bool V_286 )
{
struct V_267 * V_196 = V_195 -> V_196 ;
int V_19 ;
V_19 = F_222 ( V_196 , V_195 , V_285 ,
V_286 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_224 ( V_12 , V_196 , V_195 ) ;
if ( V_19 )
goto V_288;
return 0 ;
V_288:
F_223 ( V_195 ) ;
return V_19 ;
}
static void
F_229 ( struct V_12 * V_12 ,
struct V_194 * V_195 )
{
struct V_267 * V_196 = V_195 -> V_196 ;
F_227 ( V_12 , V_196 , V_195 ) ;
F_223 ( V_195 ) ;
}
static void F_230 ( struct V_12 * V_12 ,
struct V_194 * V_195 ,
bool V_285 )
{
struct V_267 * V_196 = V_195 -> V_196 ;
struct V_194 * V_289 ;
if ( ! V_285 )
return;
V_289 = F_226 ( V_195 , V_276 ) ;
F_229 ( V_12 , V_289 ) ;
F_205 ( V_12 , V_289 ) ;
F_218 ( V_12 , V_196 ) ;
}
static int
F_231 ( struct V_12 * V_12 ,
const struct V_259 * V_260 ,
bool V_285 , bool V_286 )
{
struct V_194 * V_195 ;
struct V_267 * V_196 ;
int V_19 ;
if ( V_12 -> V_58 -> V_225 )
return 0 ;
V_196 = F_207 ( V_12 , V_260 ) ;
if ( F_52 ( V_196 ) ) {
F_165 ( V_12 -> V_122 -> V_106 , L_11 ) ;
return F_72 ( V_196 ) ;
}
V_195 = F_204 ( V_12 , V_196 , V_260 ) ;
if ( F_52 ( V_195 ) ) {
F_165 ( V_12 -> V_122 -> V_106 , L_12 ) ;
V_19 = F_72 ( V_195 ) ;
goto V_290;
}
V_19 = F_228 ( V_12 , V_195 , V_285 ,
V_286 ) ;
if ( V_19 ) {
F_165 ( V_12 -> V_122 -> V_106 , L_13 ) ;
goto V_291;
}
F_230 ( V_12 , V_195 , V_285 ) ;
return 0 ;
V_291:
F_205 ( V_12 , V_195 ) ;
V_290:
F_218 ( V_12 , V_196 ) ;
return V_19 ;
}
static void F_232 ( struct V_12 * V_12 ,
struct V_259 * V_260 )
{
struct V_194 * V_195 ;
struct V_267 * V_196 ;
if ( V_12 -> V_58 -> V_225 )
return;
V_195 = F_206 ( V_12 , V_260 ) ;
if ( F_18 ( ! V_195 ) )
return;
V_196 = V_195 -> V_196 ;
F_229 ( V_12 , V_195 ) ;
F_205 ( V_12 , V_195 ) ;
F_218 ( V_12 , V_196 ) ;
}
static int F_233 ( struct V_12 * V_12 )
{
char V_63 [ V_64 ] ;
char V_68 [ V_69 ] ;
int V_57 , V_19 ;
F_44 ( V_63 , true , V_292 ,
V_80 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_67 ) , V_63 ) ;
if ( V_19 )
return V_19 ;
F_47 ( V_68 , 0xff , V_80 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_73 ) , V_68 ) ;
if ( V_19 )
return V_19 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_82 ) ; V_57 ++ ) {
struct V_44 * V_45 = & V_12 -> V_58 -> V_83 [ V_57 ] ;
char V_84 [ V_85 ] ;
char V_247 [ V_248 ] ;
if ( ! F_59 ( V_45 ) )
continue;
F_62 ( V_84 , V_45 -> V_66 ,
V_292 ,
V_80 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_86 ) ,
V_84 ) ;
if ( V_19 )
return V_19 ;
F_194 ( V_247 , V_90 ,
V_246 , V_45 -> V_66 , 0 ,
0 ) ;
F_199 ( V_247 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_257 ) ,
V_247 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
static void F_234 ( struct V_12 * V_12 ,
struct V_267 * V_196 )
{
struct V_194 * V_195 , * V_174 ;
F_147 (fib_entry, tmp, &fib_node->entry_list, list) {
bool V_293 = & V_174 -> V_276 == & V_196 -> V_275 ;
F_229 ( V_12 , V_195 ) ;
F_205 ( V_12 , V_195 ) ;
F_218 ( V_12 , V_196 ) ;
if ( V_293 )
break;
}
}
static void F_235 ( struct V_12 * V_12 ,
struct V_267 * V_196 )
{
switch ( V_196 -> V_48 -> V_47 ) {
case V_90 :
F_234 ( V_12 , V_196 ) ;
break;
case V_91 :
F_108 ( 1 ) ;
break;
}
}
static void F_236 ( struct V_12 * V_12 ,
struct V_44 * V_45 ,
enum V_46 V_47 )
{
struct V_43 * V_48 = F_66 ( V_45 , V_47 ) ;
struct V_267 * V_196 , * V_174 ;
F_147 (fib_node, tmp, &fib->node_list, list) {
bool V_293 = & V_174 -> V_276 == & V_48 -> V_54 ;
F_235 ( V_12 , V_196 ) ;
if ( V_293 )
break;
}
}
static void F_78 ( struct V_12 * V_12 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_82 ) ; V_57 ++ ) {
struct V_44 * V_45 = & V_12 -> V_58 -> V_83 [ V_57 ] ;
if ( ! F_59 ( V_45 ) )
continue;
F_236 ( V_12 , V_45 , V_90 ) ;
}
}
static void F_237 ( struct V_12 * V_12 )
{
int V_19 ;
if ( V_12 -> V_58 -> V_225 )
return;
F_165 ( V_12 -> V_122 -> V_106 , L_14 ) ;
F_78 ( V_12 ) ;
V_12 -> V_58 -> V_225 = true ;
V_19 = F_233 ( V_12 ) ;
if ( V_19 )
F_165 ( V_12 -> V_122 -> V_106 , L_15 ) ;
}
static void F_238 ( struct V_134 * V_135 )
{
struct V_294 * V_295 =
F_122 ( V_135 , struct V_294 , V_135 ) ;
struct V_12 * V_12 = V_295 -> V_12 ;
struct V_296 * V_297 ;
bool V_285 , V_286 ;
int V_19 ;
F_113 () ;
switch ( V_295 -> V_162 ) {
case V_298 :
case V_299 :
case V_300 :
V_285 = V_295 -> V_162 == V_298 ;
V_286 = V_295 -> V_162 == V_299 ;
V_19 = F_231 ( V_12 , & V_295 -> V_260 ,
V_285 , V_286 ) ;
if ( V_19 )
F_237 ( V_12 ) ;
F_183 ( V_295 -> V_260 . V_229 ) ;
break;
case V_301 :
F_232 ( V_12 , & V_295 -> V_260 ) ;
F_183 ( V_295 -> V_260 . V_229 ) ;
break;
case V_302 :
case V_303 :
V_297 = V_295 -> V_304 . V_297 ;
if ( ! F_239 ( V_297 ) && ! V_297 -> V_305 )
F_237 ( V_12 ) ;
F_240 ( V_297 ) ;
break;
case V_226 :
case V_227 :
F_179 ( V_12 , V_295 -> V_162 ,
V_295 -> V_306 . V_213 ) ;
F_183 ( V_295 -> V_306 . V_213 -> V_307 ) ;
break;
}
F_115 () ;
F_38 ( V_295 ) ;
}
static int F_241 ( struct V_160 * V_308 ,
unsigned long V_162 , void * V_163 )
{
struct V_294 * V_295 ;
struct V_309 * V_310 = V_163 ;
struct V_136 * V_58 ;
if ( ! F_242 ( V_310 -> V_311 , & V_312 ) )
return V_168 ;
V_295 = F_34 ( sizeof( * V_295 ) , V_170 ) ;
if ( F_18 ( ! V_295 ) )
return V_171 ;
F_137 ( & V_295 -> V_135 , F_238 ) ;
V_58 = F_122 ( V_308 , struct V_136 , V_313 ) ;
V_295 -> V_12 = V_58 -> V_12 ;
V_295 -> V_162 = V_162 ;
switch ( V_162 ) {
case V_298 :
case V_299 :
case V_300 :
case V_301 :
memcpy ( & V_295 -> V_260 , V_163 , sizeof( V_295 -> V_260 ) ) ;
F_182 ( V_295 -> V_260 . V_229 ) ;
break;
case V_302 :
case V_303 :
memcpy ( & V_295 -> V_304 , V_163 , sizeof( V_295 -> V_304 ) ) ;
F_243 ( V_295 -> V_304 . V_297 ) ;
break;
case V_226 :
case V_227 :
memcpy ( & V_295 -> V_306 , V_163 , sizeof( V_295 -> V_306 ) ) ;
F_182 ( V_295 -> V_306 . V_213 -> V_307 ) ;
break;
}
F_139 ( & V_295 -> V_135 ) ;
return V_168 ;
}
static struct V_1 *
F_86 ( const struct V_12 * V_12 ,
const struct V_118 * V_106 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_314 ) ; V_57 ++ )
if ( V_12 -> V_58 -> V_121 [ V_57 ] &&
V_12 -> V_58 -> V_121 [ V_57 ] -> V_106 == V_106 )
return V_12 -> V_58 -> V_121 [ V_57 ] ;
return NULL ;
}
static int F_244 ( struct V_12 * V_12 , T_1 V_2 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_2 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( F_108 ( V_19 ) )
return V_19 ;
F_245 ( V_16 , false ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static void F_246 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
F_244 ( V_12 , V_2 -> V_13 ) ;
F_180 ( V_12 , V_2 ) ;
F_146 ( V_12 , V_2 ) ;
}
static bool F_247 ( struct V_1 * V_2 ,
const struct V_220 * V_221 ,
unsigned long V_162 )
{
switch ( V_162 ) {
case V_315 :
if ( ! V_2 )
return true ;
return false ;
case V_316 :
if ( V_2 && ! V_221 -> V_317 &&
! F_248 ( V_2 -> V_106 ) )
return true ;
return false ;
}
return false ;
}
static enum V_318
F_249 ( const struct V_12 * V_12 ,
const struct V_118 * V_106 )
{
enum V_319 type ;
if ( F_250 ( V_106 ) && F_251 ( F_252 ( V_106 ) ) )
type = V_320 ;
else if ( F_251 ( V_106 ) && F_253 ( V_106 ) )
type = V_320 ;
else if ( F_251 ( V_106 ) )
type = V_321 ;
else
type = V_322 ;
return F_254 ( V_12 , type ) ;
}
static int F_255 ( struct V_12 * V_12 , T_1 * V_323 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_314 ) ; V_57 ++ ) {
if ( ! V_12 -> V_58 -> V_121 [ V_57 ] ) {
* V_323 = V_57 ;
return 0 ;
}
}
return - V_324 ;
}
static struct V_1 * F_256 ( T_6 V_325 , T_1 V_13 ,
T_1 V_326 ,
struct V_118 * V_327 )
{
struct V_1 * V_2 ;
V_2 = F_34 ( V_325 , V_49 ) ;
if ( ! V_2 )
return NULL ;
F_37 ( & V_2 -> V_102 ) ;
F_37 ( & V_2 -> V_109 ) ;
F_257 ( V_2 -> V_173 , V_327 -> V_328 ) ;
V_2 -> V_329 = V_327 -> V_329 ;
V_2 -> V_326 = V_326 ;
V_2 -> V_106 = V_327 ;
V_2 -> V_13 = V_13 ;
return V_2 ;
}
struct V_1 * F_258 ( const struct V_12 * V_12 ,
T_1 V_13 )
{
return V_12 -> V_58 -> V_121 [ V_13 ] ;
}
T_1 F_259 ( const struct V_1 * V_2 )
{
return V_2 -> V_13 ;
}
int F_260 ( const struct V_1 * V_2 )
{
return V_2 -> V_106 -> V_330 ;
}
static struct V_1 *
F_261 ( struct V_12 * V_12 ,
const struct V_331 * V_239 )
{
T_4 V_87 = F_262 ( V_239 -> V_106 ) ;
const struct V_332 * V_333 ;
enum V_318 type ;
struct V_1 * V_2 ;
struct V_334 * V_335 ;
struct V_44 * V_45 ;
T_1 V_13 ;
int V_19 ;
type = F_249 ( V_12 , V_239 -> V_106 ) ;
V_333 = V_12 -> V_58 -> V_336 [ type ] ;
V_45 = F_73 ( V_12 , V_87 ? : V_89 ) ;
if ( F_52 ( V_45 ) )
return F_69 ( V_45 ) ;
V_19 = F_255 ( V_12 , & V_13 ) ;
if ( V_19 )
goto V_337;
V_2 = F_256 ( V_333 -> V_325 , V_13 , V_45 -> V_66 , V_239 -> V_106 ) ;
if ( ! V_2 ) {
V_19 = - V_50 ;
goto V_338;
}
V_2 -> V_12 = V_12 ;
V_2 -> V_333 = V_333 ;
V_335 = V_333 -> V_339 ( V_2 ) ;
if ( F_52 ( V_335 ) ) {
V_19 = F_72 ( V_335 ) ;
goto V_340;
}
V_2 -> V_335 = V_335 ;
if ( V_333 -> V_341 )
V_333 -> V_341 ( V_2 , V_239 ) ;
V_19 = V_333 -> V_342 ( V_2 ) ;
if ( V_19 )
goto V_343;
V_19 = F_263 ( V_12 , V_239 -> V_106 -> V_328 ,
F_264 ( V_335 ) , true ) ;
if ( V_19 )
goto V_344;
F_19 ( V_2 ) ;
F_265 ( V_335 , V_2 ) ;
V_12 -> V_58 -> V_121 [ V_13 ] = V_2 ;
V_45 -> V_95 ++ ;
return V_2 ;
V_344:
V_333 -> V_345 ( V_2 ) ;
V_343:
F_266 ( V_335 ) ;
V_340:
F_38 ( V_2 ) ;
V_338:
V_337:
F_74 ( V_45 ) ;
return F_35 ( V_19 ) ;
}
void F_267 ( struct V_1 * V_2 )
{
const struct V_332 * V_333 = V_2 -> V_333 ;
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_334 * V_335 = V_2 -> V_335 ;
struct V_44 * V_45 ;
F_246 ( V_12 , V_2 ) ;
V_45 = & V_12 -> V_58 -> V_83 [ V_2 -> V_326 ] ;
V_45 -> V_95 -- ;
V_12 -> V_58 -> V_121 [ V_2 -> V_13 ] = NULL ;
F_265 ( V_335 , NULL ) ;
F_22 ( V_2 ) ;
F_263 ( V_12 , V_2 -> V_106 -> V_328 ,
F_264 ( V_335 ) , false ) ;
V_333 -> V_345 ( V_2 ) ;
F_266 ( V_335 ) ;
F_38 ( V_2 ) ;
F_74 ( V_45 ) ;
}
static void
F_268 ( struct V_331 * V_239 ,
struct V_346 * V_346 )
{
struct V_164 * V_164 = V_346 -> V_164 ;
V_239 -> V_347 = V_346 -> V_347 ;
V_239 -> V_348 = V_164 -> V_349 ;
if ( V_239 -> V_348 )
V_239 -> V_350 = V_164 -> V_350 ;
else
V_239 -> V_351 = V_164 -> V_352 ;
}
static int
F_269 ( struct V_346 * V_346 ,
struct V_118 * V_327 )
{
struct V_164 * V_164 = V_346 -> V_164 ;
struct V_12 * V_12 = V_164 -> V_12 ;
T_1 V_347 = V_346 -> V_347 ;
struct V_1 * V_2 ;
struct V_334 * V_335 ;
int V_19 ;
V_2 = F_86 ( V_12 , V_327 ) ;
if ( ! V_2 ) {
struct V_331 V_239 = {
. V_106 = V_327 ,
} ;
F_268 ( & V_239 , V_346 ) ;
V_2 = F_261 ( V_12 , & V_239 ) ;
if ( F_52 ( V_2 ) )
return F_72 ( V_2 ) ;
}
V_335 = V_2 -> V_333 -> V_339 ( V_2 ) ;
V_19 = F_270 ( V_335 , V_164 , V_347 ) ;
if ( V_19 )
goto V_353;
V_19 = F_271 ( V_164 , V_347 , false ) ;
if ( V_19 )
goto V_354;
V_19 = F_272 ( V_164 , V_347 ,
V_355 ) ;
if ( V_19 )
goto V_356;
V_346 -> V_335 = V_335 ;
return 0 ;
V_356:
F_271 ( V_164 , V_347 , true ) ;
V_354:
F_273 ( V_335 , V_164 , V_347 ) ;
V_353:
F_266 ( V_335 ) ;
return V_19 ;
}
void
F_274 ( struct V_346 * V_346 )
{
struct V_164 * V_164 = V_346 -> V_164 ;
struct V_334 * V_335 = V_346 -> V_335 ;
T_1 V_347 = V_346 -> V_347 ;
if ( F_18 ( V_319 ( V_335 ) != V_322 ) )
return;
V_346 -> V_335 = NULL ;
F_272 ( V_164 , V_347 , V_357 ) ;
F_271 ( V_164 , V_347 , true ) ;
F_273 ( V_335 , V_164 , V_347 ) ;
F_266 ( V_335 ) ;
}
static int F_275 ( struct V_118 * V_327 ,
struct V_118 * V_358 ,
unsigned long V_162 , T_1 V_347 )
{
struct V_164 * V_164 = F_276 ( V_358 ) ;
struct V_346 * V_346 ;
V_346 = F_277 ( V_164 , V_347 ) ;
if ( F_18 ( ! V_346 ) )
return - V_26 ;
switch ( V_162 ) {
case V_315 :
return F_269 ( V_346 ,
V_327 ) ;
case V_316 :
F_274 ( V_346 ) ;
break;
}
return 0 ;
}
static int F_278 ( struct V_118 * V_358 ,
unsigned long V_162 )
{
if ( F_279 ( V_358 ) ||
F_280 ( V_358 ) ||
F_281 ( V_358 ) )
return 0 ;
return F_275 ( V_358 , V_358 , V_162 , 1 ) ;
}
static int F_282 ( struct V_118 * V_327 ,
struct V_118 * V_359 ,
unsigned long V_162 , T_1 V_347 )
{
struct V_118 * V_358 ;
struct V_360 * V_361 ;
int V_19 ;
F_283 (lag_dev, port_dev, iter) {
if ( F_284 ( V_358 ) ) {
V_19 = F_275 ( V_327 ,
V_358 ,
V_162 , V_347 ) ;
if ( V_19 )
return V_19 ;
}
}
return 0 ;
}
static int F_285 ( struct V_118 * V_359 ,
unsigned long V_162 )
{
if ( F_279 ( V_359 ) )
return 0 ;
return F_282 ( V_359 , V_359 , V_162 , 1 ) ;
}
static int F_286 ( struct V_118 * V_327 ,
unsigned long V_162 )
{
struct V_12 * V_12 = F_287 ( V_327 ) ;
struct V_331 V_239 = {
. V_106 = V_327 ,
} ;
struct V_1 * V_2 ;
switch ( V_162 ) {
case V_315 :
V_2 = F_261 ( V_12 , & V_239 ) ;
if ( F_52 ( V_2 ) )
return F_72 ( V_2 ) ;
break;
case V_316 :
V_2 = F_86 ( V_12 , V_327 ) ;
F_267 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_288 ( struct V_118 * V_362 ,
unsigned long V_162 )
{
struct V_118 * V_363 = F_252 ( V_362 ) ;
T_1 V_347 = F_289 ( V_362 ) ;
if ( F_279 ( V_362 ) )
return 0 ;
if ( F_284 ( V_363 ) )
return F_275 ( V_362 , V_363 ,
V_162 , V_347 ) ;
else if ( F_290 ( V_363 ) )
return F_282 ( V_362 , V_363 , V_162 ,
V_347 ) ;
else if ( F_251 ( V_363 ) && F_253 ( V_363 ) )
return F_286 ( V_362 , V_162 ) ;
return 0 ;
}
static int F_291 ( struct V_118 * V_106 ,
unsigned long V_162 )
{
if ( F_284 ( V_106 ) )
return F_278 ( V_106 , V_162 ) ;
else if ( F_290 ( V_106 ) )
return F_285 ( V_106 , V_162 ) ;
else if ( F_251 ( V_106 ) )
return F_286 ( V_106 , V_162 ) ;
else if ( F_250 ( V_106 ) )
return F_288 ( V_106 , V_162 ) ;
else
return 0 ;
}
int F_292 ( struct V_160 * V_161 ,
unsigned long V_162 , void * V_163 )
{
struct V_364 * V_365 = (struct V_364 * ) V_163 ;
struct V_118 * V_106 = V_365 -> V_366 -> V_106 ;
struct V_12 * V_12 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_12 = F_287 ( V_106 ) ;
if ( ! V_12 )
goto V_159;
V_2 = F_86 ( V_12 , V_106 ) ;
if ( ! F_247 ( V_2 , V_365 -> V_366 , V_162 ) )
goto V_159;
V_19 = F_291 ( V_106 , V_162 ) ;
V_159:
return F_293 ( V_19 ) ;
}
static int F_294 ( struct V_12 * V_12 , T_1 V_13 ,
const char * V_367 , int V_329 )
{
char V_16 [ V_17 ] ;
int V_19 ;
F_5 ( V_16 , V_13 ) ;
V_19 = F_6 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
if ( V_19 )
return V_19 ;
F_295 ( V_16 , V_329 ) ;
F_296 ( V_16 , V_367 ) ;
F_297 ( V_16 , V_368 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
int F_298 ( struct V_118 * V_106 )
{
struct V_12 * V_12 ;
struct V_1 * V_2 ;
T_1 V_369 ;
int V_19 ;
V_12 = F_287 ( V_106 ) ;
if ( ! V_12 )
return 0 ;
V_2 = F_86 ( V_12 , V_106 ) ;
if ( ! V_2 )
return 0 ;
V_369 = F_264 ( V_2 -> V_335 ) ;
V_19 = F_263 ( V_12 , V_2 -> V_173 , V_369 , false ) ;
if ( V_19 )
return V_19 ;
V_19 = F_294 ( V_12 , V_2 -> V_13 , V_106 -> V_328 ,
V_106 -> V_329 ) ;
if ( V_19 )
goto V_370;
V_19 = F_263 ( V_12 , V_106 -> V_328 , V_369 , true ) ;
if ( V_19 )
goto V_344;
F_257 ( V_2 -> V_173 , V_106 -> V_328 ) ;
V_2 -> V_329 = V_106 -> V_329 ;
F_101 ( V_106 , L_16 , V_2 -> V_13 ) ;
return 0 ;
V_344:
F_294 ( V_12 , V_2 -> V_13 , V_2 -> V_173 , V_2 -> V_329 ) ;
V_370:
F_263 ( V_12 , V_2 -> V_173 , V_369 , true ) ;
return V_19 ;
}
static int F_299 ( struct V_12 * V_12 ,
struct V_118 * V_327 )
{
struct V_1 * V_2 ;
V_2 = F_86 ( V_12 , V_327 ) ;
if ( V_2 )
F_291 ( V_327 , V_316 ) ;
return F_291 ( V_327 , V_315 ) ;
}
static void F_300 ( struct V_12 * V_12 ,
struct V_118 * V_327 )
{
struct V_1 * V_2 ;
V_2 = F_86 ( V_12 , V_327 ) ;
if ( ! V_2 )
return;
F_291 ( V_327 , V_316 ) ;
}
int F_301 ( struct V_118 * V_327 , unsigned long V_162 ,
struct V_371 * V_310 )
{
struct V_12 * V_12 = F_287 ( V_327 ) ;
int V_19 = 0 ;
if ( ! V_12 )
return 0 ;
switch ( V_162 ) {
case V_372 :
return 0 ;
case V_373 :
if ( V_310 -> V_374 )
V_19 = F_299 ( V_12 , V_327 ) ;
else
F_300 ( V_12 , V_327 ) ;
break;
}
return V_19 ;
}
static struct V_375 *
F_302 ( const struct V_1 * V_2 )
{
return F_122 ( V_2 , struct V_375 , V_376 ) ;
}
static void F_303 ( struct V_1 * V_2 ,
const struct V_331 * V_239 )
{
struct V_375 * V_377 ;
V_377 = F_302 ( V_2 ) ;
V_377 -> V_347 = V_239 -> V_347 ;
V_377 -> V_348 = V_239 -> V_348 ;
if ( V_239 -> V_348 )
V_377 -> V_350 = V_239 -> V_350 ;
else
V_377 -> V_351 = V_239 -> V_351 ;
}
static int F_304 ( struct V_1 * V_2 , bool V_15 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
struct V_375 * V_377 ;
char V_16 [ V_17 ] ;
V_377 = F_302 ( V_2 ) ;
F_305 ( V_16 , V_15 , V_378 ,
V_2 -> V_13 , V_2 -> V_326 , V_2 -> V_106 -> V_329 ,
V_2 -> V_106 -> V_328 ) ;
F_306 ( V_16 , V_377 -> V_348 ,
V_377 -> V_348 ? V_377 -> V_350 :
V_377 -> V_351 ,
V_377 -> V_347 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static int F_307 ( struct V_1 * V_2 )
{
return F_304 ( V_2 , true ) ;
}
static void F_308 ( struct V_1 * V_2 )
{
F_304 ( V_2 , false ) ;
}
static struct V_334 *
F_309 ( struct V_1 * V_2 )
{
return F_310 ( V_2 -> V_12 , V_2 -> V_13 ) ;
}
static int F_311 ( struct V_1 * V_2 ,
enum V_379 type ,
T_1 V_380 , bool V_15 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
char V_16 [ V_17 ] ;
F_305 ( V_16 , V_15 , type , V_2 -> V_13 , V_2 -> V_326 ,
V_2 -> V_106 -> V_329 , V_2 -> V_106 -> V_328 ) ;
F_312 ( V_16 , type , V_380 ) ;
return F_9 ( V_12 -> V_20 , F_7 ( V_21 ) , V_16 ) ;
}
static T_3 F_313 ( const struct V_12 * V_12 )
{
return F_314 ( V_12 -> V_20 ) + 1 ;
}
static int F_315 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_347 = F_316 ( V_2 -> V_335 ) ;
int V_19 ;
V_19 = F_311 ( V_2 , V_381 , V_347 , true ) ;
if ( V_19 )
return V_19 ;
V_19 = F_317 ( V_2 -> V_335 , V_382 ,
F_313 ( V_12 ) , true ) ;
if ( V_19 )
goto V_383;
return 0 ;
V_383:
F_311 ( V_2 , V_381 , V_347 , false ) ;
return V_19 ;
}
static void F_318 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_347 = F_316 ( V_2 -> V_335 ) ;
F_317 ( V_2 -> V_335 , V_382 ,
F_313 ( V_12 ) , false ) ;
F_311 ( V_2 , V_381 , V_347 , false ) ;
}
static struct V_334 *
F_319 ( struct V_1 * V_2 )
{
T_1 V_347 = F_250 ( V_2 -> V_106 ) ? F_289 ( V_2 -> V_106 ) : 1 ;
return F_320 ( V_2 -> V_12 , V_347 ) ;
}
static int F_321 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_369 = F_264 ( V_2 -> V_335 ) ;
int V_19 ;
V_19 = F_311 ( V_2 , V_384 , V_369 ,
true ) ;
if ( V_19 )
return V_19 ;
V_19 = F_317 ( V_2 -> V_335 , V_382 ,
F_313 ( V_12 ) , true ) ;
if ( V_19 )
goto V_383;
return 0 ;
V_383:
F_311 ( V_2 , V_384 , V_369 , false ) ;
return V_19 ;
}
static void F_322 ( struct V_1 * V_2 )
{
struct V_12 * V_12 = V_2 -> V_12 ;
T_1 V_369 = F_264 ( V_2 -> V_335 ) ;
F_317 ( V_2 -> V_335 , V_382 ,
F_313 ( V_12 ) , false ) ;
F_311 ( V_2 , V_384 , V_369 , false ) ;
}
static struct V_334 *
F_323 ( struct V_1 * V_2 )
{
return F_324 ( V_2 -> V_12 , V_2 -> V_106 -> V_330 ) ;
}
static int F_325 ( struct V_12 * V_12 )
{
T_2 V_385 = F_56 ( V_12 -> V_20 , V_314 ) ;
V_12 -> V_58 -> V_121 = F_57 ( V_385 ,
sizeof( struct V_1 * ) ,
V_49 ) ;
if ( ! V_12 -> V_58 -> V_121 )
return - V_50 ;
V_12 -> V_58 -> V_336 = V_386 ;
return 0 ;
}
static void F_326 ( struct V_12 * V_12 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_56 ( V_12 -> V_20 , V_314 ) ; V_57 ++ )
F_108 ( V_12 -> V_58 -> V_121 [ V_57 ] ) ;
F_38 ( V_12 -> V_58 -> V_121 ) ;
}
static void F_327 ( struct V_160 * V_308 )
{
struct V_136 * V_58 ;
F_77 () ;
V_58 = F_122 ( V_308 , struct V_136 , V_313 ) ;
F_78 ( V_58 -> V_12 ) ;
}
static int F_328 ( struct V_12 * V_12 )
{
char V_387 [ V_388 ] ;
T_2 V_385 ;
int V_19 ;
if ( ! F_55 ( V_12 -> V_20 , V_314 ) )
return - V_79 ;
V_385 = F_56 ( V_12 -> V_20 , V_314 ) ;
F_329 ( V_387 , true ) ;
F_330 ( V_387 , V_385 ) ;
V_19 = F_9 ( V_12 -> V_20 , F_7 ( V_389 ) , V_387 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void F_331 ( struct V_12 * V_12 )
{
char V_387 [ V_388 ] ;
F_329 ( V_387 , false ) ;
F_9 ( V_12 -> V_20 , F_7 ( V_389 ) , V_387 ) ;
}
int F_332 ( struct V_12 * V_12 )
{
struct V_136 * V_58 ;
int V_19 ;
V_58 = F_34 ( sizeof( * V_12 -> V_58 ) , V_49 ) ;
if ( ! V_58 )
return - V_50 ;
V_12 -> V_58 = V_58 ;
V_58 -> V_12 = V_12 ;
F_37 ( & V_12 -> V_58 -> V_218 ) ;
V_19 = F_328 ( V_12 ) ;
if ( V_19 )
goto V_390;
V_19 = F_325 ( V_12 ) ;
if ( V_19 )
goto V_391;
V_19 = F_36 ( & V_12 -> V_58 -> V_182 ,
& V_183 ) ;
if ( V_19 )
goto V_392;
V_19 = F_36 ( & V_12 -> V_58 -> V_177 ,
& V_178 ) ;
if ( V_19 )
goto V_393;
V_19 = F_54 ( V_12 ) ;
if ( V_19 )
goto V_394;
V_19 = F_75 ( V_12 ) ;
if ( V_19 )
goto V_395;
V_19 = F_140 ( V_12 ) ;
if ( V_19 )
goto V_396;
V_12 -> V_58 -> V_313 . V_397 = F_241 ;
V_19 = F_333 ( & V_12 -> V_58 -> V_313 ,
F_327 ) ;
if ( V_19 )
goto V_398;
return 0 ;
V_398:
F_142 ( V_12 ) ;
V_396:
F_76 ( V_12 ) ;
V_395:
F_58 ( V_12 ) ;
V_394:
F_41 ( & V_12 -> V_58 -> V_177 ) ;
V_393:
F_41 ( & V_12 -> V_58 -> V_182 ) ;
V_392:
F_326 ( V_12 ) ;
V_391:
F_331 ( V_12 ) ;
V_390:
F_38 ( V_12 -> V_58 ) ;
return V_19 ;
}
void F_334 ( struct V_12 * V_12 )
{
F_335 ( & V_12 -> V_58 -> V_313 ) ;
F_142 ( V_12 ) ;
F_76 ( V_12 ) ;
F_58 ( V_12 ) ;
F_41 ( & V_12 -> V_58 -> V_177 ) ;
F_41 ( & V_12 -> V_58 -> V_182 ) ;
F_326 ( V_12 ) ;
F_331 ( V_12 ) ;
F_38 ( V_12 -> V_58 ) ;
}
