static bool
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
unsigned char V_4 ;
F_2 (prefix, prefix_usage1) {
if ( ! F_3 ( V_4 , V_3 -> V_5 ) )
return false ;
}
return true ;
}
static bool
F_4 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return ! memcmp ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
static bool
F_5 ( struct V_1 * V_6 )
{
struct V_1 V_7 = { { 0 } } ;
return F_4 ( V_6 , & V_7 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
memcpy ( V_2 , V_3 , sizeof( * V_2 ) ) ;
}
static void
F_7 ( struct V_1 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
}
static void
F_8 ( struct V_1 * V_6 ,
unsigned char V_8 )
{
F_9 ( V_8 , V_6 -> V_5 ) ;
}
static void
F_10 ( struct V_1 * V_6 ,
unsigned char V_8 )
{
F_11 ( V_8 , V_6 -> V_5 ) ;
}
static struct V_9 * F_12 ( void )
{
struct V_9 * V_10 ;
int V_11 ;
V_10 = F_13 ( sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return F_14 ( - V_13 ) ;
V_11 = F_15 ( & V_10 -> V_14 , & V_15 ) ;
if ( V_11 )
goto V_16;
F_16 ( & V_10 -> V_17 ) ;
return V_10 ;
V_16:
F_17 ( V_10 ) ;
return F_14 ( V_11 ) ;
}
static void F_18 ( struct V_9 * V_10 )
{
F_19 ( ! F_20 ( & V_10 -> V_17 ) ) ;
F_21 ( & V_10 -> V_14 ) ;
F_17 ( V_10 ) ;
}
static struct V_18 *
F_22 ( struct V_19 * V_19 , bool V_20 )
{
static struct V_18 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_21 = & V_19 -> V_24 . V_25 [ V_22 ] ;
if ( V_21 -> V_26 == 0 ) {
if ( V_20 )
V_20 = false ;
else
return V_21 ;
}
}
return NULL ;
}
static int F_23 ( struct V_19 * V_19 ,
struct V_18 * V_21 )
{
char V_27 [ V_28 ] ;
F_24 ( V_27 , true ,
(enum V_29 ) V_21 -> V_30 ,
V_21 -> V_31 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_33 ) , V_27 ) ;
}
static int F_27 ( struct V_19 * V_19 ,
struct V_18 * V_21 )
{
char V_27 [ V_28 ] ;
F_24 ( V_27 , false ,
(enum V_29 ) V_21 -> V_30 ,
V_21 -> V_31 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_33 ) , V_27 ) ;
}
static int
F_28 ( struct V_19 * V_19 ,
struct V_1 * V_6 ,
struct V_18 * V_21 )
{
char V_34 [ V_35 ] ;
T_1 V_36 = 0 ;
T_1 V_4 ;
T_1 V_37 = V_38 ;
F_2 (prefix, prefix_usage)
V_36 = V_4 ;
F_29 ( V_34 , V_36 , V_21 -> V_31 ) ;
F_2 (prefix, prefix_usage) {
if ( V_4 == 0 )
continue;
F_30 ( V_34 , V_4 , V_37 ,
V_38 ) ;
V_37 = V_4 ;
}
return F_25 ( V_19 -> V_32 , F_26 ( V_39 ) , V_34 ) ;
}
static struct V_18 *
F_31 ( struct V_19 * V_19 ,
struct V_1 * V_6 ,
enum V_40 V_30 , bool V_20 )
{
struct V_18 * V_21 ;
int V_11 ;
V_21 = F_22 ( V_19 , V_20 ) ;
if ( ! V_21 )
return F_14 ( - V_41 ) ;
V_21 -> V_30 = V_30 ;
V_11 = F_23 ( V_19 , V_21 ) ;
if ( V_11 )
return F_14 ( V_11 ) ;
V_11 = F_28 ( V_19 , V_6 ,
V_21 ) ;
if ( V_11 )
goto V_42;
memcpy ( & V_21 -> V_6 , V_6 ,
sizeof( V_21 -> V_6 ) ) ;
return V_21 ;
V_42:
F_27 ( V_19 , V_21 ) ;
return F_14 ( V_11 ) ;
}
static int F_32 ( struct V_19 * V_19 ,
struct V_18 * V_21 )
{
return F_27 ( V_19 , V_21 ) ;
}
static struct V_18 *
F_33 ( struct V_19 * V_19 ,
struct V_1 * V_6 ,
enum V_40 V_30 , bool V_20 )
{
struct V_18 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_21 = & V_19 -> V_24 . V_25 [ V_22 ] ;
if ( V_21 -> V_26 != 0 &&
V_21 -> V_30 == V_30 &&
F_4 ( & V_21 -> V_6 ,
V_6 ) )
goto V_43;
}
V_21 = F_31 ( V_19 , V_6 ,
V_30 , V_20 ) ;
if ( F_34 ( V_21 ) )
return V_21 ;
V_43:
V_21 -> V_26 ++ ;
return V_21 ;
}
static int F_35 ( struct V_19 * V_19 ,
struct V_18 * V_21 )
{
if ( -- V_21 -> V_26 == 0 )
return F_32 ( V_19 , V_21 ) ;
return 0 ;
}
static void F_36 ( struct V_19 * V_19 )
{
struct V_18 * V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_21 = & V_19 -> V_24 . V_25 [ V_22 ] ;
V_21 -> V_31 = V_22 + V_44 ;
}
}
static struct V_45 * F_37 ( struct V_19 * V_19 )
{
struct V_45 * V_46 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_38 ( V_19 -> V_32 , V_47 ) ; V_22 ++ ) {
V_46 = & V_19 -> V_24 . V_48 [ V_22 ] ;
if ( ! V_46 -> V_49 )
return V_46 ;
}
return NULL ;
}
static int F_39 ( struct V_19 * V_19 ,
struct V_45 * V_46 )
{
char V_50 [ V_51 ] ;
F_40 ( V_50 , V_46 -> V_31 ,
(enum V_29 ) V_46 -> V_30 ,
V_46 -> V_21 -> V_31 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_52 ) , V_50 ) ;
}
static int F_41 ( struct V_19 * V_19 ,
struct V_45 * V_46 )
{
char V_50 [ V_51 ] ;
F_40 ( V_50 , V_46 -> V_31 ,
(enum V_29 ) V_46 -> V_30 , 0 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_52 ) , V_50 ) ;
}
static T_2 F_42 ( T_2 V_53 )
{
if ( V_53 == V_54 )
V_53 = V_55 ;
return V_53 ;
}
static struct V_45 * F_43 ( struct V_19 * V_19 ,
T_2 V_53 ,
enum V_40 V_30 )
{
struct V_45 * V_46 ;
int V_22 ;
V_53 = F_42 ( V_53 ) ;
for ( V_22 = 0 ; V_22 < F_38 ( V_19 -> V_32 , V_47 ) ; V_22 ++ ) {
V_46 = & V_19 -> V_24 . V_48 [ V_22 ] ;
if ( V_46 -> V_49 && V_46 -> V_30 == V_30 && V_46 -> V_53 == V_53 )
return V_46 ;
}
return NULL ;
}
static struct V_45 * F_44 ( struct V_19 * V_19 ,
unsigned char V_8 ,
T_2 V_53 ,
enum V_40 V_30 )
{
struct V_1 V_56 ;
struct V_18 * V_21 ;
struct V_45 * V_46 ;
int V_11 ;
V_46 = F_37 ( V_19 ) ;
if ( ! V_46 )
return F_14 ( - V_41 ) ;
V_46 -> V_10 = F_12 () ;
if ( F_34 ( V_46 -> V_10 ) )
return F_45 ( V_46 -> V_10 ) ;
V_46 -> V_30 = V_30 ;
V_46 -> V_53 = V_53 ;
F_7 ( & V_56 ) ;
F_8 ( & V_56 , V_8 ) ;
V_21 = F_33 ( V_19 , & V_56 ,
V_30 , true ) ;
if ( F_34 ( V_21 ) ) {
V_11 = F_46 ( V_21 ) ;
goto V_57;
}
V_46 -> V_21 = V_21 ;
V_11 = F_39 ( V_19 , V_46 ) ;
if ( V_11 )
goto V_58;
V_46 -> V_49 = true ;
return V_46 ;
V_58:
F_35 ( V_19 , V_46 -> V_21 ) ;
V_57:
F_18 ( V_46 -> V_10 ) ;
return F_14 ( V_11 ) ;
}
static void F_47 ( struct V_19 * V_19 ,
struct V_45 * V_46 )
{
F_41 ( V_19 , V_46 ) ;
F_35 ( V_19 , V_46 -> V_21 ) ;
F_18 ( V_46 -> V_10 ) ;
V_46 -> V_49 = false ;
}
static int
F_48 ( struct V_19 * V_19 , struct V_45 * V_46 ,
struct V_1 * V_56 )
{
struct V_18 * V_21 = V_46 -> V_21 ;
struct V_18 * V_59 ;
int V_11 ;
if ( F_4 ( V_56 , & V_21 -> V_6 ) )
return 0 ;
V_59 = F_33 ( V_19 , V_56 ,
V_46 -> V_30 , false ) ;
if ( F_34 ( V_59 ) ) {
if ( F_1 ( V_56 ,
& V_21 -> V_6 ) )
return 0 ;
return F_46 ( V_59 ) ;
}
V_46 -> V_21 = V_59 ;
V_11 = F_39 ( V_19 , V_46 ) ;
if ( V_11 )
goto V_58;
F_35 ( V_19 , V_21 ) ;
return 0 ;
V_58:
V_46 -> V_21 = V_21 ;
F_35 ( V_19 , V_59 ) ;
return V_11 ;
}
static struct V_45 * F_49 ( struct V_19 * V_19 ,
unsigned char V_8 ,
T_2 V_53 ,
enum V_40 V_30 )
{
struct V_45 * V_46 ;
int V_11 ;
V_53 = F_42 ( V_53 ) ;
V_46 = F_43 ( V_19 , V_53 , V_30 ) ;
if ( ! V_46 ) {
V_46 = F_44 ( V_19 , V_8 , V_53 , V_30 ) ;
if ( F_34 ( V_46 ) )
return V_46 ;
} else {
struct V_1 V_56 ;
F_6 ( & V_56 ,
& V_46 -> V_10 -> V_6 ) ;
F_8 ( & V_56 , V_8 ) ;
V_11 = F_48 ( V_19 , V_46 ,
& V_56 ) ;
if ( V_11 )
return F_14 ( V_11 ) ;
}
return V_46 ;
}
static void F_50 ( struct V_19 * V_19 , struct V_45 * V_46 )
{
if ( F_5 ( & V_46 -> V_10 -> V_6 ) )
F_47 ( V_19 , V_46 ) ;
else
F_48 ( V_19 , V_46 ,
& V_46 -> V_10 -> V_6 ) ;
}
static int F_51 ( struct V_19 * V_19 )
{
struct V_45 * V_46 ;
T_3 V_60 ;
int V_22 ;
if ( ! F_52 ( V_19 -> V_32 , V_47 ) )
return - V_61 ;
V_60 = F_38 ( V_19 -> V_32 , V_47 ) ;
V_19 -> V_24 . V_48 = F_53 ( V_60 , sizeof( struct V_45 ) ,
V_12 ) ;
if ( ! V_19 -> V_24 . V_48 )
return - V_13 ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ ) {
V_46 = & V_19 -> V_24 . V_48 [ V_22 ] ;
V_46 -> V_31 = V_22 ;
}
return 0 ;
}
static void F_54 ( struct V_19 * V_19 )
{
F_55 () ;
F_56 ( V_19 ) ;
F_17 ( V_19 -> V_24 . V_48 ) ;
}
static struct V_62 *
F_57 ( struct V_19 * V_19 , struct V_63 * V_64 ,
T_4 V_65 )
{
struct V_62 * V_66 ;
V_66 = F_13 ( sizeof( * V_66 ) , V_12 ) ;
if ( ! V_66 )
return NULL ;
V_66 -> V_67 . V_64 = V_64 ;
V_66 -> V_65 = V_65 ;
F_16 ( & V_66 -> V_68 ) ;
return V_66 ;
}
static void F_58 ( struct V_62 * V_66 )
{
F_17 ( V_66 ) ;
}
static int
F_59 ( struct V_19 * V_19 ,
struct V_62 * V_66 )
{
return F_60 ( & V_19 -> V_24 . V_69 ,
& V_66 -> V_70 ,
V_71 ) ;
}
static void
F_61 ( struct V_19 * V_19 ,
struct V_62 * V_66 )
{
F_62 ( & V_19 -> V_24 . V_69 ,
& V_66 -> V_70 ,
V_71 ) ;
}
static struct V_62 *
F_63 ( struct V_19 * V_19 , struct V_63 * V_64 )
{
struct V_62 * V_66 ;
struct V_72 * V_73 ;
int V_11 ;
V_73 = F_64 ( V_19 , V_64 -> V_74 ) ;
if ( ! V_73 )
return F_14 ( - V_75 ) ;
V_66 = F_57 ( V_19 , V_64 , V_73 -> V_65 ) ;
if ( ! V_66 )
return F_14 ( - V_13 ) ;
V_11 = F_59 ( V_19 , V_66 ) ;
if ( V_11 )
goto V_76;
F_65 ( & V_66 -> V_77 , & V_73 -> V_78 ) ;
return V_66 ;
V_76:
F_58 ( V_66 ) ;
return F_14 ( V_11 ) ;
}
static void
F_66 ( struct V_19 * V_19 ,
struct V_62 * V_66 )
{
F_67 ( & V_66 -> V_77 ) ;
F_61 ( V_19 , V_66 ) ;
F_58 ( V_66 ) ;
}
static struct V_62 *
F_68 ( struct V_19 * V_19 , struct V_63 * V_64 )
{
struct V_79 V_67 ;
V_67 . V_64 = V_64 ;
return F_69 ( & V_19 -> V_24 . V_69 ,
& V_67 , V_71 ) ;
}
static void
F_70 ( struct V_19 * V_19 )
{
unsigned long V_80 = F_71 ( & V_81 . V_82 , V_83 ) ;
V_19 -> V_24 . V_84 . V_80 = F_72 ( V_80 ) ;
}
static void F_73 ( struct V_19 * V_19 ,
char * V_85 ,
int V_86 )
{
struct V_87 * V_74 ;
struct V_63 * V_64 ;
T_5 V_88 ;
T_2 V_89 ;
T_4 V_65 ;
F_74 ( V_85 , V_86 , & V_65 , & V_89 ) ;
if ( ! V_19 -> V_90 [ V_65 ] ) {
F_75 ( V_19 -> V_91 -> V_74 , L_1 ) ;
return;
}
V_88 = F_76 ( V_89 ) ;
V_74 = V_19 -> V_90 [ V_65 ] -> V_74 ;
V_64 = F_77 ( & V_81 , & V_88 , V_74 ) ;
if ( ! V_64 ) {
F_78 ( V_74 , L_2 ,
& V_89 ) ;
return;
}
F_79 ( V_74 , L_3 , & V_89 ) ;
F_80 ( V_64 , NULL ) ;
F_81 ( V_64 ) ;
}
static void F_82 ( struct V_19 * V_19 ,
char * V_85 ,
int V_92 )
{
T_1 V_93 ;
int V_22 ;
V_93 = F_83 ( V_85 ,
V_92 ) ;
V_93 ++ ;
for ( V_22 = 0 ; V_22 < V_93 ; V_22 ++ ) {
int V_86 ;
V_86 = V_92 * V_94 + V_22 ;
F_73 ( V_19 , V_85 ,
V_86 ) ;
}
}
static void F_84 ( struct V_19 * V_19 ,
char * V_85 , int V_92 )
{
switch ( F_85 ( V_85 , V_92 ) ) {
case V_95 :
F_82 ( V_19 , V_85 ,
V_92 ) ;
break;
case V_96 :
F_86 ( 1 ) ;
break;
}
}
static bool F_87 ( char * V_85 )
{
T_1 V_97 , V_98 , V_93 ;
V_97 = F_88 ( V_85 ) ;
V_98 = V_97 - 1 ;
if ( V_97 < V_99 )
return false ;
if ( F_85 ( V_85 , V_98 ) ==
V_96 )
return true ;
V_93 = F_83 ( V_85 ,
V_98 ) ;
if ( ++ V_93 == V_94 )
return true ;
return false ;
}
static int F_89 ( struct V_19 * V_19 )
{
char * V_85 ;
T_1 V_97 ;
int V_22 , V_11 ;
V_85 = F_90 ( V_100 , V_12 ) ;
if ( ! V_85 )
return - V_13 ;
F_91 () ;
do {
F_92 ( V_85 , V_95 ) ;
V_11 = F_93 ( V_19 -> V_32 , F_26 ( V_101 ) ,
V_85 ) ;
if ( V_11 ) {
F_75 ( V_19 -> V_91 -> V_74 , L_4 ) ;
break;
}
V_97 = F_88 ( V_85 ) ;
for ( V_22 = 0 ; V_22 < V_97 ; V_22 ++ )
F_84 ( V_19 , V_85 ,
V_22 ) ;
} while ( F_87 ( V_85 ) );
F_94 () ;
F_17 ( V_85 ) ;
return V_11 ;
}
static void F_95 ( struct V_19 * V_19 )
{
struct V_62 * V_66 ;
F_91 () ;
F_96 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node)
F_80 ( V_66 -> V_67 . V_64 , NULL ) ;
F_94 () ;
}
static void
F_97 ( struct V_19 * V_19 )
{
unsigned long V_80 = V_19 -> V_24 . V_84 . V_80 ;
F_98 ( & V_19 -> V_24 . V_84 . V_102 ,
F_99 ( V_80 ) ) ;
}
static void F_100 ( struct V_103 * V_104 )
{
struct V_19 * V_19 = F_101 ( V_104 , struct V_19 ,
V_24 . V_84 . V_102 . V_104 ) ;
int V_11 ;
V_11 = F_89 ( V_19 ) ;
if ( V_11 )
F_102 ( V_19 -> V_91 -> V_74 , L_5 ) ;
F_95 ( V_19 ) ;
F_97 ( V_19 ) ;
}
static void F_103 ( struct V_103 * V_104 )
{
struct V_62 * V_66 ;
struct V_19 * V_19 = F_101 ( V_104 , struct V_19 ,
V_24 . V_105 . V_104 ) ;
F_91 () ;
F_96 (neigh_entry, &mlxsw_sp->router.nexthop_neighs_list,
nexthop_neighs_list_node)
if ( ! V_66 -> V_106 )
F_80 ( V_66 -> V_67 . V_64 , NULL ) ;
F_94 () ;
F_98 ( & V_19 -> V_24 . V_105 ,
V_107 ) ;
}
static enum V_108 F_104 ( bool V_109 )
{
return V_109 ? V_110 :
V_111 ;
}
static void
F_105 ( struct V_19 * V_19 ,
struct V_62 * V_66 ,
enum V_108 V_112 )
{
struct V_63 * V_64 = V_66 -> V_67 . V_64 ;
T_2 V_89 = F_106 ( * ( ( T_5 * ) V_64 -> V_113 ) ) ;
char V_114 [ V_115 ] ;
F_107 ( V_114 , V_112 , V_66 -> V_65 , V_66 -> V_116 ,
V_89 ) ;
F_25 ( V_19 -> V_32 , F_26 ( V_117 ) , V_114 ) ;
}
static void
F_108 ( struct V_19 * V_19 ,
struct V_62 * V_66 ,
bool V_109 )
{
if ( ! V_109 && ! V_66 -> V_106 )
return;
V_66 -> V_106 = V_109 ;
if ( V_66 -> V_67 . V_64 -> V_118 == & V_81 )
F_105 ( V_19 , V_66 ,
F_104 ( V_109 ) ) ;
else
F_86 ( 1 ) ;
}
static void F_109 ( struct V_103 * V_104 )
{
struct V_119 * V_120 =
F_101 ( V_104 , struct V_119 , V_104 ) ;
struct V_19 * V_19 = V_120 -> V_19 ;
struct V_62 * V_66 ;
struct V_63 * V_64 = V_120 -> V_64 ;
unsigned char V_116 [ V_121 ] ;
bool V_122 ;
T_1 V_123 , V_124 ;
F_110 ( & V_64 -> V_125 ) ;
memcpy ( V_116 , V_64 -> V_116 , V_121 ) ;
V_123 = V_64 -> V_123 ;
V_124 = V_64 -> V_124 ;
F_111 ( & V_64 -> V_125 ) ;
F_91 () ;
V_122 = V_123 & V_126 && ! V_124 ;
V_66 = F_68 ( V_19 , V_64 ) ;
if ( ! V_122 && ! V_66 )
goto V_127;
if ( ! V_66 ) {
V_66 = F_63 ( V_19 , V_64 ) ;
if ( F_34 ( V_66 ) )
goto V_127;
}
memcpy ( V_66 -> V_116 , V_116 , V_121 ) ;
F_108 ( V_19 , V_66 , V_122 ) ;
F_112 ( V_19 , V_66 , ! V_122 ) ;
if ( ! V_66 -> V_106 && F_20 ( & V_66 -> V_68 ) )
F_66 ( V_19 , V_66 ) ;
V_127:
F_94 () ;
F_81 ( V_64 ) ;
F_17 ( V_120 ) ;
}
int F_113 ( struct V_128 * V_129 ,
unsigned long V_130 , void * V_131 )
{
struct V_119 * V_120 ;
struct V_132 * V_132 ;
struct V_19 * V_19 ;
unsigned long V_80 ;
struct V_133 * V_134 ;
struct V_63 * V_64 ;
switch ( V_130 ) {
case V_135 :
V_134 = V_131 ;
if ( ! V_134 -> V_74 || V_134 -> V_118 != & V_81 )
return V_136 ;
V_132 = F_114 ( V_134 -> V_74 ) ;
if ( ! V_132 )
return V_136 ;
V_19 = V_132 -> V_19 ;
V_80 = F_72 ( F_71 ( V_134 , V_83 ) ) ;
V_19 -> V_24 . V_84 . V_80 = V_80 ;
F_115 ( V_132 ) ;
break;
case V_137 :
V_64 = V_131 ;
if ( V_64 -> V_118 != & V_81 )
return V_136 ;
V_132 = F_114 ( V_64 -> V_74 ) ;
if ( ! V_132 )
return V_136 ;
V_120 = F_13 ( sizeof( * V_120 ) , V_138 ) ;
if ( ! V_120 ) {
F_115 ( V_132 ) ;
return V_139 ;
}
F_116 ( & V_120 -> V_104 , F_109 ) ;
V_120 -> V_19 = V_132 -> V_19 ;
V_120 -> V_64 = V_64 ;
F_117 ( V_64 ) ;
F_118 ( & V_120 -> V_104 ) ;
F_115 ( V_132 ) ;
break;
}
return V_136 ;
}
static int F_119 ( struct V_19 * V_19 )
{
int V_11 ;
V_11 = F_15 ( & V_19 -> V_24 . V_69 ,
& V_71 ) ;
if ( V_11 )
return V_11 ;
F_70 ( V_19 ) ;
F_120 ( & V_19 -> V_24 . V_84 . V_102 ,
F_100 ) ;
F_120 ( & V_19 -> V_24 . V_105 ,
F_103 ) ;
F_98 ( & V_19 -> V_24 . V_84 . V_102 , 0 ) ;
F_98 ( & V_19 -> V_24 . V_105 , 0 ) ;
return 0 ;
}
static void F_121 ( struct V_19 * V_19 )
{
F_122 ( & V_19 -> V_24 . V_84 . V_102 ) ;
F_122 ( & V_19 -> V_24 . V_105 ) ;
F_21 ( & V_19 -> V_24 . V_69 ) ;
}
static int F_123 ( struct V_19 * V_19 ,
const struct V_72 * V_73 )
{
char V_114 [ V_115 ] ;
F_124 ( V_114 , V_140 ,
V_73 -> V_65 , V_73 -> V_141 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_117 ) , V_114 ) ;
}
static void F_125 ( struct V_19 * V_19 ,
struct V_72 * V_73 )
{
struct V_62 * V_66 , * V_142 ;
F_123 ( V_19 , V_73 ) ;
F_126 (neigh_entry, tmp, &r->neigh_list,
rif_list_node)
F_66 ( V_19 , V_66 ) ;
}
static int F_127 ( struct V_19 * V_19 ,
struct V_143 * V_144 )
{
return F_60 ( & V_19 -> V_24 . V_145 ,
& V_144 -> V_70 ,
V_146 ) ;
}
static void F_128 ( struct V_19 * V_19 ,
struct V_143 * V_144 )
{
F_62 ( & V_19 -> V_24 . V_145 ,
& V_144 -> V_70 ,
V_146 ) ;
}
static struct V_143 *
F_129 ( struct V_19 * V_19 ,
struct V_147 V_67 )
{
return F_69 ( & V_19 -> V_24 . V_145 , & V_67 ,
V_146 ) ;
}
static int F_130 ( struct V_19 * V_19 ,
struct V_148 * V_149 )
{
return F_60 ( & V_19 -> V_24 . V_150 ,
& V_149 -> V_70 , V_151 ) ;
}
static void F_131 ( struct V_19 * V_19 ,
struct V_148 * V_149 )
{
F_62 ( & V_19 -> V_24 . V_150 , & V_149 -> V_70 ,
V_151 ) ;
}
static struct V_148 *
F_132 ( struct V_19 * V_19 ,
struct V_152 V_67 )
{
return F_69 ( & V_19 -> V_24 . V_150 , & V_67 ,
V_151 ) ;
}
static int F_133 ( struct V_19 * V_19 ,
struct V_45 * V_46 ,
T_2 V_153 , T_4 V_154 ,
T_2 V_155 ,
T_4 V_156 )
{
char V_157 [ V_158 ] ;
F_134 ( V_157 ,
(enum V_29 ) V_46 -> V_30 , V_46 -> V_31 ,
V_153 , V_154 , V_155 ,
V_156 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_159 ) , V_157 ) ;
}
static int F_135 ( struct V_19 * V_19 ,
struct V_143 * V_144 ,
T_2 V_160 , T_4 V_161 )
{
struct V_162 * V_163 ;
struct V_45 * V_46 = NULL ;
int V_11 ;
F_96 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
if ( V_46 == V_163 -> V_164 -> V_46 )
continue;
V_46 = V_163 -> V_164 -> V_46 ;
V_11 = F_133 ( V_19 , V_46 ,
V_160 ,
V_161 ,
V_144 -> V_153 ,
V_144 -> V_154 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_136 ( struct V_19 * V_19 , T_2 V_153 ,
struct V_148 * V_149 )
{
struct V_62 * V_66 = V_149 -> V_66 ;
char V_165 [ V_166 ] ;
F_137 ( V_165 , V_167 ,
true , V_153 , V_66 -> V_65 ) ;
F_138 ( V_165 , V_66 -> V_116 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_168 ) , V_165 ) ;
}
static int
F_139 ( struct V_19 * V_19 ,
struct V_143 * V_144 ,
bool V_169 )
{
T_2 V_153 = V_144 -> V_153 ;
struct V_148 * V_149 ;
int V_22 ;
int V_11 ;
for ( V_22 = 0 ; V_22 < V_144 -> V_170 ; V_22 ++ ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
if ( ! V_149 -> V_172 ) {
V_149 -> V_173 = 0 ;
continue;
}
if ( V_149 -> V_174 || V_169 ) {
V_11 = F_136 ( V_19 ,
V_153 , V_149 ) ;
if ( V_11 )
return V_11 ;
V_149 -> V_174 = 0 ;
V_149 -> V_173 = 1 ;
}
V_153 ++ ;
}
return 0 ;
}
static int
F_140 ( struct V_19 * V_19 ,
struct V_143 * V_144 )
{
struct V_162 * V_163 ;
int V_11 ;
F_96 (fib_entry, &nh_grp->fib_list, nexthop_group_node) {
V_11 = F_141 ( V_19 , V_163 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static void
F_142 ( struct V_19 * V_19 ,
struct V_143 * V_144 )
{
struct V_148 * V_149 ;
bool V_175 = false ;
T_2 V_153 ;
T_4 V_154 = 0 ;
bool V_176 ;
T_2 V_160 ;
T_4 V_161 ;
int V_177 ;
int V_22 ;
int V_11 ;
if ( ! V_144 -> V_178 ) {
F_140 ( V_19 , V_144 ) ;
return;
}
for ( V_22 = 0 ; V_22 < V_144 -> V_170 ; V_22 ++ ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
if ( V_149 -> V_172 ^ V_149 -> V_173 ) {
V_175 = true ;
if ( V_149 -> V_172 )
V_149 -> V_174 = 1 ;
}
if ( V_149 -> V_172 )
V_154 ++ ;
}
if ( ! V_175 ) {
V_11 = F_139 ( V_19 , V_144 ,
false ) ;
if ( V_11 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_6 ) ;
goto V_179;
}
return;
}
if ( ! V_154 )
goto V_179;
V_177 = F_144 ( V_19 , V_154 ) ;
if ( V_177 < 0 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_7 ) ;
goto V_179;
}
V_153 = V_177 ;
V_176 = V_144 -> V_180 ;
V_160 = V_144 -> V_153 ;
V_161 = V_144 -> V_154 ;
V_144 -> V_180 = 1 ;
V_144 -> V_153 = V_153 ;
V_144 -> V_154 = V_154 ;
V_11 = F_139 ( V_19 , V_144 , true ) ;
if ( V_11 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_6 ) ;
goto V_179;
}
if ( ! V_176 ) {
V_11 = F_140 ( V_19 , V_144 ) ;
if ( V_11 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_8 ) ;
goto V_179;
}
return;
}
V_11 = F_135 ( V_19 , V_144 ,
V_160 , V_161 ) ;
F_145 ( V_19 , V_160 ) ;
if ( V_11 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_9 ) ;
goto V_179;
}
return;
V_179:
V_176 = V_144 -> V_180 ;
V_144 -> V_180 = 0 ;
for ( V_22 = 0 ; V_22 < V_144 -> V_170 ; V_22 ++ ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
V_149 -> V_173 = 0 ;
}
V_11 = F_140 ( V_19 , V_144 ) ;
if ( V_11 )
F_143 ( V_19 -> V_91 -> V_74 , L_10 ) ;
if ( V_176 )
F_145 ( V_19 , V_144 -> V_153 ) ;
}
static void F_146 ( struct V_148 * V_149 ,
bool V_181 )
{
if ( ! V_181 && ! V_149 -> V_172 )
V_149 -> V_172 = 1 ;
else if ( V_181 && V_149 -> V_173 )
V_149 -> V_172 = 0 ;
V_149 -> V_174 = 1 ;
}
static void
F_112 ( struct V_19 * V_19 ,
struct V_62 * V_66 ,
bool V_181 )
{
struct V_148 * V_149 ;
F_96 (nh, &neigh_entry->nexthop_list,
neigh_list_node) {
F_146 ( V_149 , V_181 ) ;
F_142 ( V_19 , V_149 -> V_144 ) ;
}
}
static void F_147 ( struct V_148 * V_149 ,
struct V_72 * V_73 )
{
if ( V_149 -> V_73 )
return;
V_149 -> V_73 = V_73 ;
F_65 ( & V_149 -> V_77 , & V_73 -> V_68 ) ;
}
static void F_148 ( struct V_148 * V_149 )
{
if ( ! V_149 -> V_73 )
return;
F_67 ( & V_149 -> V_77 ) ;
V_149 -> V_73 = NULL ;
}
static int F_149 ( struct V_19 * V_19 ,
struct V_148 * V_149 )
{
struct V_62 * V_66 ;
struct V_182 * V_182 = V_149 -> V_67 . V_182 ;
struct V_63 * V_64 ;
T_1 V_123 , V_124 ;
int V_11 ;
if ( ! V_149 -> V_144 -> V_178 || V_149 -> V_66 )
return 0 ;
V_64 = F_77 ( & V_81 , & V_182 -> V_183 , V_182 -> V_184 ) ;
if ( ! V_64 ) {
V_64 = F_150 ( & V_81 , & V_182 -> V_183 , V_182 -> V_184 ) ;
if ( F_34 ( V_64 ) )
return F_46 ( V_64 ) ;
F_80 ( V_64 , NULL ) ;
}
V_66 = F_68 ( V_19 , V_64 ) ;
if ( ! V_66 ) {
V_66 = F_63 ( V_19 , V_64 ) ;
if ( F_34 ( V_66 ) ) {
V_11 = - V_75 ;
goto V_185;
}
}
if ( F_20 ( & V_66 -> V_68 ) )
F_151 ( & V_66 -> V_186 ,
& V_19 -> V_24 . V_187 ) ;
V_149 -> V_66 = V_66 ;
F_151 ( & V_149 -> V_188 , & V_66 -> V_68 ) ;
F_110 ( & V_64 -> V_125 ) ;
V_123 = V_64 -> V_123 ;
V_124 = V_64 -> V_124 ;
F_111 ( & V_64 -> V_125 ) ;
F_146 ( V_149 , ! ( V_123 & V_126 && ! V_124 ) ) ;
return 0 ;
V_185:
F_81 ( V_64 ) ;
return V_11 ;
}
static void F_152 ( struct V_19 * V_19 ,
struct V_148 * V_149 )
{
struct V_62 * V_66 = V_149 -> V_66 ;
struct V_63 * V_64 ;
if ( ! V_66 )
return;
V_64 = V_66 -> V_67 . V_64 ;
F_146 ( V_149 , true ) ;
F_67 ( & V_149 -> V_188 ) ;
V_149 -> V_66 = NULL ;
if ( F_20 ( & V_66 -> V_68 ) )
F_67 ( & V_66 -> V_186 ) ;
if ( ! V_66 -> V_106 && F_20 ( & V_66 -> V_68 ) )
F_66 ( V_19 , V_66 ) ;
F_81 ( V_64 ) ;
}
static int F_153 ( struct V_19 * V_19 ,
struct V_143 * V_144 ,
struct V_148 * V_149 ,
struct V_182 * V_182 )
{
struct V_87 * V_74 = V_182 -> V_184 ;
struct V_189 * V_190 ;
struct V_72 * V_73 ;
int V_11 ;
V_149 -> V_144 = V_144 ;
V_149 -> V_67 . V_182 = V_182 ;
V_11 = F_130 ( V_19 , V_149 ) ;
if ( V_11 )
return V_11 ;
V_190 = F_154 ( V_74 ) ;
if ( V_190 && F_155 ( V_190 ) &&
V_182 -> V_191 & V_192 )
return 0 ;
V_73 = F_64 ( V_19 , V_74 ) ;
if ( ! V_73 )
return 0 ;
F_147 ( V_149 , V_73 ) ;
V_11 = F_149 ( V_19 , V_149 ) ;
if ( V_11 )
goto V_193;
return 0 ;
V_193:
F_131 ( V_19 , V_149 ) ;
return V_11 ;
}
static void F_156 ( struct V_19 * V_19 ,
struct V_148 * V_149 )
{
F_152 ( V_19 , V_149 ) ;
F_148 ( V_149 ) ;
F_131 ( V_19 , V_149 ) ;
}
static void F_157 ( struct V_19 * V_19 ,
unsigned long V_130 , struct V_182 * V_182 )
{
struct V_152 V_67 ;
struct V_148 * V_149 ;
struct V_72 * V_73 ;
if ( V_19 -> V_24 . V_194 )
return;
V_67 . V_182 = V_182 ;
V_149 = F_132 ( V_19 , V_67 ) ;
if ( F_86 ( ! V_149 ) )
return;
V_73 = F_64 ( V_19 , V_182 -> V_184 ) ;
if ( ! V_73 )
return;
switch ( V_130 ) {
case V_195 :
F_147 ( V_149 , V_73 ) ;
F_149 ( V_19 , V_149 ) ;
break;
case V_196 :
F_152 ( V_19 , V_149 ) ;
F_148 ( V_149 ) ;
break;
}
F_142 ( V_19 , V_149 -> V_144 ) ;
}
static void F_158 ( struct V_19 * V_19 ,
struct V_72 * V_73 )
{
struct V_148 * V_149 , * V_142 ;
F_126 (nh, tmp, &r->nexthop_list, rif_list_node) {
F_152 ( V_19 , V_149 ) ;
F_148 ( V_149 ) ;
F_142 ( V_19 , V_149 -> V_144 ) ;
}
}
static struct V_143 *
F_159 ( struct V_19 * V_19 , struct V_197 * V_198 )
{
struct V_143 * V_144 ;
struct V_148 * V_149 ;
struct V_182 * V_182 ;
T_6 V_199 ;
int V_22 ;
int V_11 ;
V_199 = sizeof( * V_144 ) +
V_198 -> V_200 * sizeof( struct V_148 ) ;
V_144 = F_13 ( V_199 , V_12 ) ;
if ( ! V_144 )
return F_14 ( - V_13 ) ;
F_16 ( & V_144 -> V_201 ) ;
V_144 -> V_178 = V_198 -> V_182 -> V_202 == V_203 ;
V_144 -> V_170 = V_198 -> V_200 ;
V_144 -> V_67 . V_198 = V_198 ;
for ( V_22 = 0 ; V_22 < V_144 -> V_170 ; V_22 ++ ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
V_182 = & V_198 -> V_182 [ V_22 ] ;
V_11 = F_153 ( V_19 , V_144 , V_149 , V_182 ) ;
if ( V_11 )
goto V_204;
}
V_11 = F_127 ( V_19 , V_144 ) ;
if ( V_11 )
goto V_205;
F_142 ( V_19 , V_144 ) ;
return V_144 ;
V_205:
V_204:
for ( V_22 -- ; V_22 >= 0 ; V_22 -- ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
F_156 ( V_19 , V_149 ) ;
}
F_17 ( V_144 ) ;
return F_14 ( V_11 ) ;
}
static void
F_160 ( struct V_19 * V_19 ,
struct V_143 * V_144 )
{
struct V_148 * V_149 ;
int V_22 ;
F_128 ( V_19 , V_144 ) ;
for ( V_22 = 0 ; V_22 < V_144 -> V_170 ; V_22 ++ ) {
V_149 = & V_144 -> V_171 [ V_22 ] ;
F_156 ( V_19 , V_149 ) ;
}
F_142 ( V_19 , V_144 ) ;
F_86 ( V_144 -> V_180 ) ;
F_17 ( V_144 ) ;
}
static int F_161 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
struct V_197 * V_198 )
{
struct V_147 V_67 ;
struct V_143 * V_144 ;
V_67 . V_198 = V_198 ;
V_144 = F_129 ( V_19 , V_67 ) ;
if ( ! V_144 ) {
V_144 = F_159 ( V_19 , V_198 ) ;
if ( F_34 ( V_144 ) )
return F_46 ( V_144 ) ;
}
F_151 ( & V_163 -> V_206 , & V_144 -> V_201 ) ;
V_163 -> V_207 = V_144 ;
return 0 ;
}
static void F_162 ( struct V_19 * V_19 ,
struct V_162 * V_163 )
{
struct V_143 * V_144 = V_163 -> V_207 ;
F_67 ( & V_163 -> V_206 ) ;
if ( ! F_20 ( & V_144 -> V_201 ) )
return;
F_160 ( V_19 , V_144 ) ;
}
static bool
F_163 ( const struct V_162 * V_163 )
{
struct V_143 * V_207 = V_163 -> V_207 ;
if ( V_163 -> V_208 . V_209 )
return false ;
switch ( V_163 -> type ) {
case V_210 :
return ! ! V_207 -> V_180 ;
case V_211 :
return ! ! V_207 -> V_212 ;
default:
return false ;
}
}
static void F_164 ( struct V_162 * V_163 )
{
V_163 -> V_173 = true ;
switch ( V_163 -> V_164 -> V_46 -> V_30 ) {
case V_213 :
F_165 ( V_163 -> V_207 -> V_67 . V_198 ) ;
break;
case V_214 :
F_86 ( 1 ) ;
}
}
static void
F_166 ( struct V_162 * V_163 )
{
switch ( V_163 -> V_164 -> V_46 -> V_30 ) {
case V_213 :
F_167 ( V_163 -> V_207 -> V_67 . V_198 ) ;
break;
case V_214 :
F_86 ( 1 ) ;
}
V_163 -> V_173 = false ;
}
static void
F_168 ( struct V_162 * V_163 ,
enum V_215 V_112 , int V_11 )
{
switch ( V_112 ) {
case V_216 :
if ( ! V_163 -> V_173 )
return;
return F_166 ( V_163 ) ;
case V_217 :
if ( V_11 )
return;
if ( F_163 ( V_163 ) &&
! V_163 -> V_173 )
F_164 ( V_163 ) ;
else if ( ! F_163 ( V_163 ) &&
V_163 -> V_173 )
F_166 ( V_163 ) ;
return;
default:
return;
}
}
static int F_169 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
enum V_215 V_112 )
{
char V_218 [ V_219 ] ;
T_2 * V_220 = ( T_2 * ) V_163 -> V_164 -> V_67 . V_141 ;
struct V_45 * V_46 = V_163 -> V_164 -> V_46 ;
enum V_221 V_222 ;
T_4 V_223 = 0 ;
T_2 V_224 = 0 ;
T_4 V_154 = 0 ;
if ( F_163 ( V_163 ) ) {
V_222 = V_225 ;
V_224 = V_163 -> V_207 -> V_153 ;
V_154 = V_163 -> V_207 -> V_154 ;
} else {
V_222 = V_226 ;
V_223 = V_227 ;
}
F_170 ( V_218 ,
(enum V_29 ) V_46 -> V_30 , V_112 ,
V_46 -> V_31 , V_163 -> V_164 -> V_67 . V_8 ,
* V_220 ) ;
F_171 ( V_218 , V_222 , V_223 ,
V_224 , V_154 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_228 ) , V_218 ) ;
}
static int F_172 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
enum V_215 V_112 )
{
struct V_72 * V_73 = V_163 -> V_207 -> V_212 ;
enum V_221 V_222 ;
char V_218 [ V_219 ] ;
T_2 * V_220 = ( T_2 * ) V_163 -> V_164 -> V_67 . V_141 ;
struct V_45 * V_46 = V_163 -> V_164 -> V_46 ;
T_4 V_223 = 0 ;
T_4 V_65 = 0 ;
if ( F_163 ( V_163 ) ) {
V_222 = V_225 ;
V_65 = V_73 -> V_65 ;
} else {
V_222 = V_226 ;
V_223 = V_227 ;
}
F_170 ( V_218 ,
(enum V_29 ) V_46 -> V_30 , V_112 ,
V_46 -> V_31 , V_163 -> V_164 -> V_67 . V_8 ,
* V_220 ) ;
F_173 ( V_218 , V_222 , V_223 , V_65 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_228 ) , V_218 ) ;
}
static int F_174 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
enum V_215 V_112 )
{
char V_218 [ V_219 ] ;
T_2 * V_220 = ( T_2 * ) V_163 -> V_164 -> V_67 . V_141 ;
struct V_45 * V_46 = V_163 -> V_164 -> V_46 ;
F_170 ( V_218 ,
(enum V_29 ) V_46 -> V_30 , V_112 ,
V_46 -> V_31 , V_163 -> V_164 -> V_67 . V_8 ,
* V_220 ) ;
F_175 ( V_218 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_228 ) , V_218 ) ;
}
static int F_176 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
enum V_215 V_112 )
{
switch ( V_163 -> type ) {
case V_210 :
return F_169 ( V_19 , V_163 , V_112 ) ;
case V_211 :
return F_172 ( V_19 , V_163 , V_112 ) ;
case V_229 :
return F_174 ( V_19 , V_163 , V_112 ) ;
}
return - V_75 ;
}
static int F_177 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
enum V_215 V_112 )
{
int V_11 = - V_75 ;
switch ( V_163 -> V_164 -> V_46 -> V_30 ) {
case V_213 :
V_11 = F_176 ( V_19 , V_163 , V_112 ) ;
break;
case V_214 :
return V_11 ;
}
F_168 ( V_163 , V_112 , V_11 ) ;
return V_11 ;
}
static int F_141 ( struct V_19 * V_19 ,
struct V_162 * V_163 )
{
return F_177 ( V_19 , V_163 ,
V_217 ) ;
}
static int F_178 ( struct V_19 * V_19 ,
struct V_162 * V_163 )
{
return F_177 ( V_19 , V_163 ,
V_216 ) ;
}
static int
F_179 ( struct V_19 * V_19 ,
const struct V_230 * V_231 ,
struct V_162 * V_163 )
{
struct V_197 * V_198 = V_231 -> V_198 ;
if ( V_231 -> type == V_232 || V_231 -> type == V_233 ) {
V_163 -> type = V_229 ;
return 0 ;
}
if ( V_231 -> type != V_234 )
return - V_75 ;
if ( V_198 -> V_182 -> V_202 != V_203 )
V_163 -> type = V_211 ;
else
V_163 -> type = V_210 ;
return 0 ;
}
static struct V_162 *
F_180 ( struct V_19 * V_19 ,
struct V_235 * V_164 ,
const struct V_230 * V_231 )
{
struct V_162 * V_163 ;
int V_11 ;
V_163 = F_13 ( sizeof( * V_163 ) , V_12 ) ;
if ( ! V_163 ) {
V_11 = - V_13 ;
goto V_236;
}
V_11 = F_179 ( V_19 , V_231 , V_163 ) ;
if ( V_11 )
goto V_237;
V_11 = F_161 ( V_19 , V_163 , V_231 -> V_198 ) ;
if ( V_11 )
goto V_238;
V_163 -> V_208 . V_239 = V_231 -> V_198 -> V_240 ;
V_163 -> V_208 . V_53 = V_231 -> V_53 ;
V_163 -> V_208 . type = V_231 -> type ;
V_163 -> V_208 . V_209 = V_231 -> V_209 ;
V_163 -> V_164 = V_164 ;
return V_163 ;
V_238:
V_237:
F_17 ( V_163 ) ;
V_236:
return F_14 ( V_11 ) ;
}
static void F_181 ( struct V_19 * V_19 ,
struct V_162 * V_163 )
{
F_162 ( V_19 , V_163 ) ;
F_17 ( V_163 ) ;
}
static struct V_162 *
F_182 ( struct V_19 * V_19 ,
const struct V_230 * V_231 )
{
struct V_162 * V_163 ;
struct V_235 * V_164 ;
V_164 = F_183 ( V_19 , V_231 ) ;
if ( F_34 ( V_164 ) )
return NULL ;
F_96 (fib_entry, &fib_node->entry_list, list) {
if ( V_163 -> V_208 . V_53 == V_231 -> V_53 &&
V_163 -> V_208 . V_209 == V_231 -> V_209 &&
V_163 -> V_208 . type == V_231 -> type &&
V_163 -> V_207 -> V_67 . V_198 == V_231 -> V_198 ) {
return V_163 ;
}
}
return NULL ;
}
static int F_184 ( struct V_9 * V_10 ,
struct V_235 * V_164 )
{
return F_60 ( & V_10 -> V_14 , & V_164 -> V_70 ,
V_15 ) ;
}
static void F_185 ( struct V_9 * V_10 ,
struct V_235 * V_164 )
{
F_62 ( & V_10 -> V_14 , & V_164 -> V_70 ,
V_15 ) ;
}
static struct V_235 *
F_186 ( struct V_9 * V_10 , const void * V_141 ,
T_6 V_241 , unsigned char V_8 )
{
struct V_242 V_67 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
memcpy ( V_67 . V_141 , V_141 , V_241 ) ;
V_67 . V_8 = V_8 ;
return F_69 ( & V_10 -> V_14 , & V_67 , V_15 ) ;
}
static struct V_235 *
F_187 ( struct V_45 * V_46 , const void * V_141 ,
T_6 V_241 , unsigned char V_8 )
{
struct V_235 * V_164 ;
V_164 = F_13 ( sizeof( * V_164 ) , V_12 ) ;
if ( ! V_164 )
return NULL ;
F_16 ( & V_164 -> V_243 ) ;
F_65 ( & V_164 -> V_244 , & V_46 -> V_10 -> V_17 ) ;
memcpy ( V_164 -> V_67 . V_141 , V_141 , V_241 ) ;
V_164 -> V_67 . V_8 = V_8 ;
F_184 ( V_46 -> V_10 , V_164 ) ;
V_164 -> V_46 = V_46 ;
return V_164 ;
}
static void F_188 ( struct V_235 * V_164 )
{
F_185 ( V_164 -> V_46 -> V_10 , V_164 ) ;
F_67 ( & V_164 -> V_244 ) ;
F_19 ( ! F_20 ( & V_164 -> V_243 ) ) ;
F_17 ( V_164 ) ;
}
static bool
F_189 ( const struct V_235 * V_164 ,
const struct V_162 * V_163 )
{
return F_190 ( & V_164 -> V_243 ,
struct V_162 , V_244 ) == V_163 ;
}
static void F_191 ( struct V_235 * V_164 )
{
unsigned char V_8 = V_164 -> V_67 . V_8 ;
struct V_9 * V_10 = V_164 -> V_46 -> V_10 ;
if ( V_10 -> V_245 [ V_8 ] ++ == 0 )
F_8 ( & V_10 -> V_6 , V_8 ) ;
}
static void F_192 ( struct V_235 * V_164 )
{
unsigned char V_8 = V_164 -> V_67 . V_8 ;
struct V_9 * V_10 = V_164 -> V_46 -> V_10 ;
if ( -- V_10 -> V_245 [ V_8 ] == 0 )
F_10 ( & V_10 -> V_6 , V_8 ) ;
}
static struct V_235 *
F_183 ( struct V_19 * V_19 ,
const struct V_230 * V_231 )
{
struct V_235 * V_164 ;
struct V_45 * V_46 ;
int V_11 ;
V_46 = F_49 ( V_19 , V_231 -> V_246 , V_231 -> V_53 ,
V_213 ) ;
if ( F_34 ( V_46 ) )
return F_45 ( V_46 ) ;
V_164 = F_186 ( V_46 -> V_10 , & V_231 -> V_247 ,
sizeof( V_231 -> V_247 ) ,
V_231 -> V_246 ) ;
if ( V_164 )
return V_164 ;
V_164 = F_187 ( V_46 , & V_231 -> V_247 ,
sizeof( V_231 -> V_247 ) ,
V_231 -> V_246 ) ;
if ( ! V_164 ) {
V_11 = - V_13 ;
goto V_248;
}
return V_164 ;
V_248:
F_50 ( V_19 , V_46 ) ;
return F_14 ( V_11 ) ;
}
static void F_193 ( struct V_19 * V_19 ,
struct V_235 * V_164 )
{
struct V_45 * V_46 = V_164 -> V_46 ;
if ( ! F_20 ( & V_164 -> V_243 ) )
return;
F_188 ( V_164 ) ;
F_50 ( V_19 , V_46 ) ;
}
static struct V_162 *
F_194 ( const struct V_235 * V_164 ,
const struct V_249 * V_208 )
{
struct V_162 * V_163 ;
F_96 (fib_entry, &fib_node->entry_list, list) {
if ( V_163 -> V_208 . V_53 > V_208 -> V_53 )
continue;
if ( V_163 -> V_208 . V_53 != V_208 -> V_53 )
break;
if ( V_163 -> V_208 . V_209 > V_208 -> V_209 )
continue;
if ( V_163 -> V_208 . V_239 >= V_208 -> V_239 ||
V_163 -> V_208 . V_209 < V_208 -> V_209 )
return V_163 ;
}
return NULL ;
}
static int F_195 ( struct V_162 * V_163 ,
struct V_162 * V_250 )
{
struct V_235 * V_164 ;
if ( F_19 ( ! V_163 ) )
return - V_75 ;
V_164 = V_163 -> V_164 ;
F_196 (fib_entry, &fib_node->entry_list, list) {
if ( V_163 -> V_208 . V_53 != V_250 -> V_208 . V_53 ||
V_163 -> V_208 . V_209 != V_250 -> V_208 . V_209 ||
V_163 -> V_208 . V_239 != V_250 -> V_208 . V_239 )
break;
}
F_151 ( & V_250 -> V_244 , & V_163 -> V_244 ) ;
return 0 ;
}
static int
F_197 ( struct V_235 * V_164 ,
struct V_162 * V_250 ,
bool V_251 , bool V_252 )
{
struct V_162 * V_163 ;
V_163 = F_194 ( V_164 , & V_250 -> V_208 ) ;
if ( V_252 )
return F_195 ( V_163 , V_250 ) ;
if ( V_251 && F_19 ( ! V_163 ) )
return - V_75 ;
if ( V_163 ) {
F_151 ( & V_250 -> V_244 , & V_163 -> V_244 ) ;
} else {
struct V_162 * V_253 ;
F_96 (last, &fib_node->entry_list, list) {
if ( V_250 -> V_208 . V_53 > V_253 -> V_208 . V_53 )
break;
V_163 = V_253 ;
}
if ( V_163 )
F_65 ( & V_250 -> V_244 , & V_163 -> V_244 ) ;
else
F_65 ( & V_250 -> V_244 , & V_164 -> V_243 ) ;
}
return 0 ;
}
static void
F_198 ( struct V_162 * V_163 )
{
F_67 ( & V_163 -> V_244 ) ;
}
static int
F_199 ( struct V_19 * V_19 ,
const struct V_235 * V_164 ,
struct V_162 * V_163 )
{
if ( ! F_189 ( V_164 , V_163 ) )
return 0 ;
if ( ! F_200 ( & V_164 -> V_243 ) ) {
enum V_215 V_112 = V_216 ;
struct V_162 * V_64 = F_201 ( V_163 , V_244 ) ;
F_168 ( V_64 , V_112 , 0 ) ;
}
return F_141 ( V_19 , V_163 ) ;
}
static void
F_202 ( struct V_19 * V_19 ,
const struct V_235 * V_164 ,
struct V_162 * V_163 )
{
if ( ! F_189 ( V_164 , V_163 ) )
return;
if ( ! F_200 ( & V_164 -> V_243 ) ) {
struct V_162 * V_64 = F_201 ( V_163 , V_244 ) ;
enum V_215 V_112 = V_216 ;
F_141 ( V_19 , V_64 ) ;
F_168 ( V_163 , V_112 , 0 ) ;
return;
}
F_178 ( V_19 , V_163 ) ;
}
static int F_203 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
bool V_251 , bool V_252 )
{
struct V_235 * V_164 = V_163 -> V_164 ;
int V_11 ;
V_11 = F_197 ( V_164 , V_163 , V_251 ,
V_252 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_199 ( V_19 , V_164 , V_163 ) ;
if ( V_11 )
goto V_254;
F_191 ( V_164 ) ;
return 0 ;
V_254:
F_198 ( V_163 ) ;
return V_11 ;
}
static void
F_204 ( struct V_19 * V_19 ,
struct V_162 * V_163 )
{
struct V_235 * V_164 = V_163 -> V_164 ;
F_192 ( V_164 ) ;
F_202 ( V_19 , V_164 , V_163 ) ;
F_198 ( V_163 ) ;
}
static void F_205 ( struct V_19 * V_19 ,
struct V_162 * V_163 ,
bool V_251 )
{
struct V_235 * V_164 = V_163 -> V_164 ;
struct V_162 * V_255 ;
if ( ! V_251 )
return;
V_255 = F_201 ( V_163 , V_244 ) ;
F_204 ( V_19 , V_255 ) ;
F_181 ( V_19 , V_255 ) ;
F_193 ( V_19 , V_164 ) ;
}
static int
F_206 ( struct V_19 * V_19 ,
const struct V_230 * V_231 ,
bool V_251 , bool V_252 )
{
struct V_162 * V_163 ;
struct V_235 * V_164 ;
int V_11 ;
if ( V_19 -> V_24 . V_194 )
return 0 ;
V_164 = F_183 ( V_19 , V_231 ) ;
if ( F_34 ( V_164 ) ) {
F_143 ( V_19 -> V_91 -> V_74 , L_11 ) ;
return F_46 ( V_164 ) ;
}
V_163 = F_180 ( V_19 , V_164 , V_231 ) ;
if ( F_34 ( V_163 ) ) {
F_143 ( V_19 -> V_91 -> V_74 , L_12 ) ;
V_11 = F_46 ( V_163 ) ;
goto V_256;
}
V_11 = F_203 ( V_19 , V_163 , V_251 ,
V_252 ) ;
if ( V_11 ) {
F_143 ( V_19 -> V_91 -> V_74 , L_13 ) ;
goto V_257;
}
F_205 ( V_19 , V_163 , V_251 ) ;
return 0 ;
V_257:
F_181 ( V_19 , V_163 ) ;
V_256:
F_193 ( V_19 , V_164 ) ;
return V_11 ;
}
static void F_207 ( struct V_19 * V_19 ,
struct V_230 * V_231 )
{
struct V_162 * V_163 ;
struct V_235 * V_164 ;
if ( V_19 -> V_24 . V_194 )
return;
V_163 = F_182 ( V_19 , V_231 ) ;
if ( F_19 ( ! V_163 ) )
return;
V_164 = V_163 -> V_164 ;
F_204 ( V_19 , V_163 ) ;
F_181 ( V_19 , V_163 ) ;
F_193 ( V_19 , V_164 ) ;
}
static int F_208 ( struct V_19 * V_19 )
{
char V_27 [ V_28 ] ;
char V_34 [ V_35 ] ;
char V_50 [ V_51 ] ;
char V_218 [ V_219 ] ;
int V_11 ;
F_24 ( V_27 , true , V_258 ,
V_44 ) ;
V_11 = F_25 ( V_19 -> V_32 , F_26 ( V_33 ) , V_27 ) ;
if ( V_11 )
return V_11 ;
F_29 ( V_34 , 0xff , V_44 ) ;
V_11 = F_25 ( V_19 -> V_32 , F_26 ( V_39 ) , V_34 ) ;
if ( V_11 )
return V_11 ;
F_40 ( V_50 , 0 , V_258 ,
V_44 ) ;
V_11 = F_25 ( V_19 -> V_32 , F_26 ( V_52 ) , V_50 ) ;
if ( V_11 )
return V_11 ;
F_170 ( V_218 , V_213 ,
V_217 , 0 , 0 , 0 ) ;
F_175 ( V_218 ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_228 ) , V_218 ) ;
}
static void F_209 ( struct V_19 * V_19 ,
struct V_235 * V_164 )
{
struct V_162 * V_163 , * V_142 ;
F_126 (fib_entry, tmp, &fib_node->entry_list, list) {
bool V_259 = & V_142 -> V_244 == & V_164 -> V_243 ;
F_204 ( V_19 , V_163 ) ;
F_181 ( V_19 , V_163 ) ;
F_193 ( V_19 , V_164 ) ;
if ( V_259 )
break;
}
}
static void F_210 ( struct V_19 * V_19 ,
struct V_235 * V_164 )
{
switch ( V_164 -> V_46 -> V_30 ) {
case V_213 :
F_209 ( V_19 , V_164 ) ;
break;
case V_214 :
F_86 ( 1 ) ;
break;
}
}
static void F_56 ( struct V_19 * V_19 )
{
struct V_235 * V_164 , * V_142 ;
struct V_45 * V_46 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_38 ( V_19 -> V_32 , V_47 ) ; V_22 ++ ) {
V_46 = & V_19 -> V_24 . V_48 [ V_22 ] ;
if ( ! V_46 -> V_49 )
continue;
F_126 (fib_node, tmp, &vr->fib->node_list,
list) {
bool V_259 = & V_142 -> V_244 == & V_46 -> V_10 -> V_17 ;
F_210 ( V_19 , V_164 ) ;
if ( V_259 )
break;
}
}
}
static void F_211 ( struct V_19 * V_19 )
{
int V_11 ;
if ( V_19 -> V_24 . V_194 )
return;
F_143 ( V_19 -> V_91 -> V_74 , L_14 ) ;
F_56 ( V_19 ) ;
V_19 -> V_24 . V_194 = true ;
V_11 = F_208 ( V_19 ) ;
if ( V_11 )
F_143 ( V_19 -> V_91 -> V_74 , L_15 ) ;
}
static int F_212 ( struct V_19 * V_19 , T_4 V_65 )
{
char V_260 [ V_261 ] ;
int V_11 ;
F_213 ( V_260 , V_65 ) ;
V_11 = F_93 ( V_19 -> V_32 , F_26 ( V_262 ) , V_260 ) ;
if ( F_86 ( V_11 ) )
return V_11 ;
F_214 ( V_260 , false ) ;
return F_25 ( V_19 -> V_32 , F_26 ( V_262 ) , V_260 ) ;
}
void F_215 ( struct V_19 * V_19 ,
struct V_72 * V_73 )
{
F_212 ( V_19 , V_73 -> V_65 ) ;
F_158 ( V_19 , V_73 ) ;
F_125 ( V_19 , V_73 ) ;
}
static int F_216 ( struct V_19 * V_19 )
{
char V_263 [ V_264 ] ;
T_3 V_265 ;
int V_11 ;
if ( ! F_52 ( V_19 -> V_32 , V_266 ) )
return - V_61 ;
V_265 = F_38 ( V_19 -> V_32 , V_266 ) ;
V_19 -> V_90 = F_53 ( V_265 , sizeof( struct V_72 * ) ,
V_12 ) ;
if ( ! V_19 -> V_90 )
return - V_13 ;
F_217 ( V_263 , true ) ;
F_218 ( V_263 , V_265 ) ;
V_11 = F_25 ( V_19 -> V_32 , F_26 ( V_267 ) , V_263 ) ;
if ( V_11 )
goto V_268;
return 0 ;
V_268:
F_17 ( V_19 -> V_90 ) ;
return V_11 ;
}
static void F_219 ( struct V_19 * V_19 )
{
char V_263 [ V_264 ] ;
int V_22 ;
F_217 ( V_263 , false ) ;
F_25 ( V_19 -> V_32 , F_26 ( V_267 ) , V_263 ) ;
for ( V_22 = 0 ; V_22 < F_38 ( V_19 -> V_32 , V_266 ) ; V_22 ++ )
F_86 ( V_19 -> V_90 [ V_22 ] ) ;
F_17 ( V_19 -> V_90 ) ;
}
static void F_220 ( struct V_103 * V_104 )
{
struct V_269 * V_270 =
F_101 ( V_104 , struct V_269 , V_104 ) ;
struct V_19 * V_19 = V_270 -> V_19 ;
bool V_251 , V_252 ;
int V_11 ;
F_91 () ;
switch ( V_270 -> V_130 ) {
case V_271 :
case V_272 :
case V_273 :
V_251 = V_270 -> V_130 == V_271 ;
V_252 = V_270 -> V_130 == V_272 ;
V_11 = F_206 ( V_19 , & V_270 -> V_231 ,
V_251 , V_252 ) ;
if ( V_11 )
F_211 ( V_19 ) ;
F_221 ( V_270 -> V_231 . V_198 ) ;
break;
case V_274 :
F_207 ( V_19 , & V_270 -> V_231 ) ;
F_221 ( V_270 -> V_231 . V_198 ) ;
break;
case V_275 :
case V_276 :
F_211 ( V_19 ) ;
break;
case V_195 :
case V_196 :
F_157 ( V_19 , V_270 -> V_130 ,
V_270 -> V_277 . V_182 ) ;
F_221 ( V_270 -> V_277 . V_182 -> V_278 ) ;
break;
}
F_94 () ;
F_17 ( V_270 ) ;
}
static int F_222 ( struct V_128 * V_279 ,
unsigned long V_130 , void * V_131 )
{
struct V_19 * V_19 = F_101 ( V_279 , struct V_19 , V_280 ) ;
struct V_269 * V_270 ;
struct V_281 * V_282 = V_131 ;
if ( ! F_223 ( V_282 -> V_283 , & V_284 ) )
return V_136 ;
V_270 = F_13 ( sizeof( * V_270 ) , V_138 ) ;
if ( F_19 ( ! V_270 ) )
return V_139 ;
F_116 ( & V_270 -> V_104 , F_220 ) ;
V_270 -> V_19 = V_19 ;
V_270 -> V_130 = V_130 ;
switch ( V_130 ) {
case V_271 :
case V_272 :
case V_273 :
case V_274 :
memcpy ( & V_270 -> V_231 , V_131 , sizeof( V_270 -> V_231 ) ) ;
F_224 ( V_270 -> V_231 . V_198 ) ;
break;
case V_195 :
case V_196 :
memcpy ( & V_270 -> V_277 , V_131 , sizeof( V_270 -> V_277 ) ) ;
F_224 ( V_270 -> V_277 . V_182 -> V_278 ) ;
break;
}
F_118 ( & V_270 -> V_104 ) ;
return V_136 ;
}
static void F_225 ( struct V_128 * V_279 )
{
struct V_19 * V_19 = F_101 ( V_279 , struct V_19 , V_280 ) ;
F_55 () ;
F_56 ( V_19 ) ;
}
int F_226 ( struct V_19 * V_19 )
{
int V_11 ;
F_16 ( & V_19 -> V_24 . V_187 ) ;
V_11 = F_216 ( V_19 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_15 ( & V_19 -> V_24 . V_150 ,
& V_151 ) ;
if ( V_11 )
goto V_285;
V_11 = F_15 ( & V_19 -> V_24 . V_145 ,
& V_146 ) ;
if ( V_11 )
goto V_286;
F_36 ( V_19 ) ;
V_11 = F_51 ( V_19 ) ;
if ( V_11 )
goto V_287;
V_11 = F_119 ( V_19 ) ;
if ( V_11 )
goto V_288;
V_19 -> V_280 . V_289 = F_222 ;
V_11 = F_227 ( & V_19 -> V_280 ,
F_225 ) ;
if ( V_11 )
goto V_290;
return 0 ;
V_290:
F_121 ( V_19 ) ;
V_288:
F_54 ( V_19 ) ;
V_287:
F_21 ( & V_19 -> V_24 . V_145 ) ;
V_286:
F_21 ( & V_19 -> V_24 . V_150 ) ;
V_285:
F_219 ( V_19 ) ;
return V_11 ;
}
void F_228 ( struct V_19 * V_19 )
{
F_229 ( & V_19 -> V_280 ) ;
F_121 ( V_19 ) ;
F_54 ( V_19 ) ;
F_21 ( & V_19 -> V_24 . V_145 ) ;
F_21 ( & V_19 -> V_24 . V_150 ) ;
F_219 ( V_19 ) ;
}
