static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
if ( ! V_7 || V_7 -> V_8 != & V_9 )
return NULL ;
return V_7 -> V_10 ;
}
static struct V_11 * F_4 ( struct V_6 * V_7 , unsigned V_12 )
{
struct V_5 * V_13 = F_3 ( V_7 ) ;
if ( ! V_13 )
return NULL ;
return V_13 -> V_14 [ V_12 - 1 ] ;
}
static inline void
F_5 ( struct V_11 * V_15 , unsigned V_16 , T_1 V_17 )
{
F_6 ( V_17 , V_15 -> V_18 + V_16 ) ;
}
static inline void
F_7 ( struct V_11 * V_15 , unsigned V_16 , T_2 V_17 )
{
F_8 ( V_17 , V_15 -> V_18 + V_16 ) ;
}
static inline T_1
F_9 ( struct V_11 * V_15 , unsigned V_16 )
{
return F_10 ( V_15 -> V_18 + V_16 ) ;
}
static inline T_2
F_11 ( struct V_11 * V_15 , unsigned V_16 )
{
return F_12 ( V_15 -> V_18 + V_16 ) ;
}
static void F_13 ( void * V_19 )
{
struct V_6 * V_7 = V_19 ;
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
struct V_11 * V_15 = F_4 ( V_7 , V_7 -> V_22 [ V_20 ] ) ;
unsigned int V_17 , V_23 ;
F_5 ( V_15 , V_24 , 0 ) ;
V_23 = F_14 ( V_15 -> V_18 + V_25 , V_17 ,
( V_17 & 0x1 ) == 0 , 0 , 5000000 ) ;
if ( V_23 )
F_15 ( V_15 -> V_26 , L_1 ) ;
}
}
static void F_16 ( void * V_19 )
{
struct V_6 * V_7 = V_19 ;
unsigned V_20 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
struct V_11 * V_15 = F_4 ( V_7 , V_7 -> V_22 [ V_20 ] ) ;
F_5 ( V_15 , V_27 , V_15 -> V_12 ) ;
}
F_13 ( V_19 ) ;
}
static void F_17 ( unsigned long V_28 , T_3 V_29 ,
T_3 V_30 , bool V_31 , void * V_19 )
{
struct V_6 * V_7 = V_19 ;
unsigned V_20 , V_16 ;
V_16 = V_31 ? V_32 : V_33 ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
struct V_11 * V_15 = F_4 ( V_7 , V_7 -> V_22 [ V_20 ] ) ;
T_3 V_34 = V_29 ;
V_28 &= ~ 12UL ;
V_28 |= V_15 -> V_12 ;
do {
F_5 ( V_15 , V_16 , V_28 ) ;
V_28 += V_30 ;
} while ( V_34 -= V_30 );
}
}
static T_4 F_18 ( int V_35 , void * V_26 )
{
struct V_11 * V_15 = V_26 ;
T_1 V_36 , V_37 ;
T_2 V_28 ;
V_36 = F_9 ( V_15 , V_38 ) ;
if ( ! ( V_36 & V_39 ) )
return V_40 ;
V_37 = F_9 ( V_15 , V_41 ) ;
V_28 = F_11 ( V_15 , V_42 ) ;
F_19 ( V_15 -> V_26 ,
L_2
L_3 ,
V_36 , V_28 , V_37 , V_15 -> V_12 ) ;
F_5 ( V_15 , V_38 , V_36 ) ;
return V_43 ;
}
static int F_20 ( struct V_2 * V_4 ,
struct V_5 * V_13 ,
struct V_6 * V_7 )
{
struct V_1 * V_44 = F_1 ( V_4 ) ;
struct V_45 * V_46 ;
struct V_47 V_48 ;
int V_20 , V_23 = 0 ;
T_1 V_16 ;
F_21 ( & V_44 -> V_49 ) ;
if ( V_44 -> V_50 )
goto V_51;
V_48 = (struct V_47 ) {
. V_52 = V_9 . V_52 ,
. V_53 = 32 ,
. V_54 = 40 ,
. V_55 = & V_56 ,
. V_57 = V_13 -> V_26 ,
} ;
V_44 -> V_50 = V_13 ;
V_46 = F_22 ( V_58 , & V_48 , V_7 ) ;
if ( ! V_46 ) {
F_15 ( V_13 -> V_26 , L_4 ) ;
V_23 = - V_59 ;
goto V_60;
}
V_4 -> V_52 = V_48 . V_52 ;
V_4 -> V_61 . V_62 = ( 1ULL << V_48 . V_53 ) - 1 ;
V_4 -> V_61 . V_63 = true ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
struct V_11 * V_15 = F_4 ( V_7 , V_7 -> V_22 [ V_20 ] ) ;
if ( ! V_15 -> V_64 ) {
V_23 = F_23 ( V_13 -> V_65 , V_15 -> V_12 ) ;
if ( V_23 ) {
F_15 ( V_13 -> V_26 , L_5 , V_23 ) ;
goto V_60;
}
V_15 -> V_64 = true ;
}
F_7 ( V_15 , V_66 ,
V_48 . V_67 . V_68 [ 0 ] |
( ( T_2 ) V_15 -> V_12 << V_69 ) ) ;
F_7 ( V_15 , V_70 ,
V_48 . V_67 . V_68 [ 1 ] |
( ( T_2 ) V_15 -> V_12 << V_69 ) ) ;
F_5 ( V_15 , V_71 ,
( V_48 . V_67 . V_72 >> 32 ) |
V_73 ) ;
F_5 ( V_15 , V_74 ,
V_48 . V_67 . V_72 ) ;
F_5 ( V_15 , V_75 ,
V_48 . V_67 . V_76 [ 0 ] ) ;
F_5 ( V_15 , V_77 ,
V_48 . V_67 . V_76 [ 1 ] ) ;
V_16 = V_78 | V_79 | V_80 | V_81 |
V_82 | V_83 ;
if ( F_24 ( V_84 ) )
V_16 |= V_85 ;
F_5 ( V_15 , V_86 , V_16 ) ;
}
F_25 ( & V_44 -> V_49 ) ;
V_44 -> V_46 = V_46 ;
return 0 ;
V_60:
V_44 -> V_50 = NULL ;
V_51:
F_25 ( & V_44 -> V_49 ) ;
return V_23 ;
}
static struct V_2 * F_26 ( unsigned type )
{
struct V_1 * V_44 ;
if ( type != V_87 && type != V_88 )
return NULL ;
V_44 = F_27 ( sizeof( * V_44 ) , V_89 ) ;
if ( ! V_44 )
return NULL ;
if ( type == V_88 &&
F_28 ( & V_44 -> V_4 ) ) {
F_29 ( V_44 ) ;
return NULL ;
}
F_30 ( & V_44 -> V_49 ) ;
F_31 ( & V_44 -> V_90 ) ;
return & V_44 -> V_4 ;
}
static void F_32 ( struct V_2 * V_4 )
{
struct V_1 * V_44 = F_1 ( V_4 ) ;
if ( F_33 ( V_44 -> V_50 ) )
return;
F_34 ( V_4 ) ;
F_35 ( V_44 -> V_50 -> V_26 ) ;
F_36 ( V_44 -> V_46 ) ;
F_37 ( V_44 -> V_50 -> V_26 ) ;
F_29 ( V_44 ) ;
}
static int F_38 ( struct V_2 * V_4 , struct V_91 * V_26 )
{
struct V_5 * V_13 = F_3 ( V_26 -> V_6 ) ;
struct V_1 * V_44 = F_1 ( V_4 ) ;
int V_23 ;
if ( ! V_13 ) {
F_15 ( V_26 , L_6 ) ;
return - V_92 ;
}
F_35 ( V_13 -> V_26 ) ;
V_23 = F_20 ( V_4 , V_13 , V_26 -> V_6 ) ;
F_37 ( V_13 -> V_26 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_44 -> V_50 != V_13 ) {
F_15 ( V_26 , L_7
L_8 ,
F_39 ( V_44 -> V_50 -> V_26 ) ,
F_39 ( V_13 -> V_26 ) ) ;
return - V_93 ;
}
return 0 ;
}
static void F_40 ( struct V_2 * V_4 , struct V_91 * V_26 )
{
struct V_6 * V_7 = V_26 -> V_6 ;
struct V_5 * V_13 = F_3 ( V_7 ) ;
struct V_1 * V_44 = F_1 ( V_4 ) ;
unsigned V_20 ;
if ( ! V_44 -> V_50 )
return;
F_35 ( V_13 -> V_26 ) ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
struct V_11 * V_15 = F_4 ( V_7 , V_7 -> V_22 [ V_20 ] ) ;
F_5 ( V_15 , V_86 , 0 ) ;
}
F_37 ( V_13 -> V_26 ) ;
V_44 -> V_50 = NULL ;
}
static int F_41 ( struct V_2 * V_4 , unsigned long V_28 ,
T_5 V_94 , T_3 V_29 , int V_95 )
{
int V_23 ;
unsigned long V_96 ;
struct V_1 * V_44 = F_1 ( V_4 ) ;
struct V_45 * V_8 = V_44 -> V_46 ;
if ( ! V_8 )
return - V_97 ;
F_42 ( & V_44 -> V_90 , V_96 ) ;
V_23 = V_8 -> V_98 ( V_8 , V_28 , V_94 , V_29 , V_95 ) ;
F_43 ( & V_44 -> V_90 , V_96 ) ;
return V_23 ;
}
static T_3 F_44 ( struct V_2 * V_4 , unsigned long V_28 ,
T_3 V_29 )
{
T_3 V_23 ;
unsigned long V_96 ;
struct V_1 * V_44 = F_1 ( V_4 ) ;
struct V_45 * V_8 = V_44 -> V_46 ;
if ( ! V_8 )
return 0 ;
F_35 ( V_44 -> V_50 -> V_26 ) ;
F_42 ( & V_44 -> V_90 , V_96 ) ;
V_23 = V_8 -> V_99 ( V_8 , V_28 , V_29 ) ;
F_43 ( & V_44 -> V_90 , V_96 ) ;
F_37 ( V_44 -> V_50 -> V_26 ) ;
return V_23 ;
}
static T_5 F_45 ( struct V_2 * V_4 ,
T_6 V_28 )
{
T_5 V_23 ;
unsigned long V_96 ;
struct V_1 * V_44 = F_1 ( V_4 ) ;
struct V_45 * V_8 = V_44 -> V_46 ;
if ( ! V_8 )
return 0 ;
F_42 ( & V_44 -> V_90 , V_96 ) ;
V_23 = V_8 -> V_100 ( V_8 , V_28 ) ;
F_43 ( & V_44 -> V_90 , V_96 ) ;
return V_23 ;
}
static bool F_46 ( enum V_101 V_102 )
{
switch ( V_102 ) {
case V_103 :
return true ;
case V_104 :
return true ;
default:
return false ;
}
}
static int F_47 ( struct V_91 * V_26 )
{
struct V_5 * V_13 = F_3 ( V_26 -> V_6 ) ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
if ( ! V_13 )
return - V_97 ;
V_108 = F_48 ( V_26 , V_13 -> V_26 , V_109 ) ;
if ( ! V_108 ) {
F_15 ( V_13 -> V_26 , L_9 ,
F_39 ( V_13 -> V_26 ) , F_39 ( V_26 ) ) ;
return - V_97 ;
}
V_106 = F_49 ( V_26 ) ;
if ( F_50 ( V_106 ) )
return F_51 ( V_106 ) ;
F_52 ( V_106 ) ;
F_53 ( & V_13 -> V_50 , V_26 ) ;
return 0 ;
}
static void F_54 ( struct V_91 * V_26 )
{
struct V_5 * V_13 = F_3 ( V_26 -> V_6 ) ;
if ( ! V_13 )
return;
F_55 ( & V_13 -> V_50 , V_26 ) ;
F_56 ( V_26 ) ;
F_57 ( V_26 ) ;
}
static int F_58 ( struct V_91 * V_26 , struct V_110 * args )
{
struct V_5 * V_13 ;
struct V_111 * V_112 ;
unsigned V_12 = args -> args [ 0 ] ;
if ( args -> V_113 != 1 ) {
F_15 ( V_26 , L_10
L_11 ,
args -> V_114 -> V_115 , args -> V_113 ) ;
return - V_93 ;
}
V_112 = F_59 ( args -> V_114 ) ;
if ( F_33 ( ! V_112 ) )
return - V_93 ;
V_13 = F_60 ( V_112 ) ;
if ( F_33 ( V_12 < 1 ) ||
F_33 ( V_12 > V_13 -> V_116 ) )
return - V_93 ;
if ( ! V_26 -> V_6 -> V_10 ) {
V_26 -> V_6 -> V_10 = V_13 ;
} else {
if ( F_33 ( V_13 != V_26 -> V_6 -> V_10 ) )
return - V_93 ;
}
return F_61 ( V_26 , & V_12 , 1 ) ;
}
static int F_62 ( struct V_5 * V_13 )
{
int V_23 ;
V_23 = F_63 ( V_13 -> V_117 ) ;
if ( V_23 ) {
F_15 ( V_13 -> V_26 , L_12 ) ;
return V_23 ;
}
V_23 = F_63 ( V_13 -> V_118 ) ;
if ( V_23 ) {
F_15 ( V_13 -> V_26 , L_13 ) ;
F_64 ( V_13 -> V_117 ) ;
return V_23 ;
}
return 0 ;
}
static void F_65 ( struct V_5 * V_13 )
{
F_64 ( V_13 -> V_118 ) ;
F_64 ( V_13 -> V_117 ) ;
}
static int F_66 ( struct V_91 * V_26 )
{
T_3 V_119 = 0 ;
unsigned int V_120 = 0 ;
void * V_121 ;
T_6 V_94 ;
unsigned long V_122 ;
static bool V_123 = false ;
int V_23 ;
if ( V_123 )
return 0 ;
V_23 = F_67 ( V_120 , & V_119 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_14 ,
V_23 ) ;
return V_23 ;
}
F_68 ( V_26 , L_15 , V_119 ) ;
V_122 = V_124 ;
V_121 = F_69 ( V_26 , V_119 , & V_94 , V_89 , V_122 ) ;
if ( ! V_121 ) {
F_15 ( V_26 , L_16 ,
V_119 ) ;
return - V_59 ;
}
V_23 = F_70 ( V_94 , V_119 , V_120 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_17 , V_23 ) ;
goto V_125;
}
V_123 = true ;
return 0 ;
V_125:
F_71 ( V_26 , V_119 , V_121 , V_94 , V_122 ) ;
return V_23 ;
}
static int F_72 ( const struct V_126 * V_114 )
{
T_1 V_16 ;
if ( F_73 ( V_114 , L_18 , 0 , & V_16 ) )
return - V_97 ;
return V_16 / 0x1000 ;
}
static int F_74 ( struct V_111 * V_127 )
{
struct V_11 * V_15 ;
struct V_91 * V_26 = & V_127 -> V_26 ;
struct V_5 * V_13 = F_75 ( V_26 -> V_128 ) ;
struct V_129 * V_130 ;
int V_23 , V_35 ;
V_15 = F_76 ( V_26 , sizeof( * V_15 ) , V_89 ) ;
if ( ! V_15 )
return - V_59 ;
V_15 -> V_26 = V_26 ;
F_77 ( V_127 , V_15 ) ;
V_130 = F_78 ( V_127 , V_131 , 0 ) ;
V_15 -> V_18 = F_79 ( V_26 , V_130 ) ;
if ( F_80 ( V_15 -> V_18 ) )
return F_81 ( V_15 -> V_18 ) ;
V_35 = F_82 ( V_127 , 0 ) ;
if ( V_35 < 0 ) {
F_15 ( V_26 , L_19 ) ;
return - V_97 ;
}
F_5 ( V_15 , V_38 , F_9 ( V_15 , V_38 ) ) ;
V_23 = F_83 ( V_26 , V_35 ,
F_18 ,
V_132 ,
L_20 ,
V_15 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_21 , V_35 ) ;
return V_23 ;
}
V_23 = F_72 ( V_26 -> V_133 ) ;
if ( V_23 < 0 ) {
F_15 ( V_26 , L_22 ) ;
return V_23 ;
}
V_15 -> V_12 = V_23 ;
F_84 ( V_26 , L_23 , V_15 -> V_12 ) ;
V_13 -> V_14 [ V_15 -> V_12 - 1 ] = V_15 ;
return 0 ;
}
static int F_85 ( struct V_111 * V_127 )
{
struct V_5 * V_13 = F_75 ( V_127 -> V_26 . V_128 ) ;
struct V_11 * V_15 = F_60 ( V_127 ) ;
F_77 ( V_127 , NULL ) ;
V_13 -> V_14 [ V_15 -> V_12 - 1 ] = NULL ;
return 0 ;
}
static bool F_86 ( struct V_5 * V_13 )
{
struct V_126 * V_134 ;
F_87 (qcom_iommu->dev->of_node, child)
if ( F_88 ( V_134 , L_24 ) )
return true ;
return false ;
}
static int F_89 ( struct V_111 * V_127 )
{
struct V_126 * V_134 ;
struct V_5 * V_13 ;
struct V_91 * V_26 = & V_127 -> V_26 ;
struct V_129 * V_130 ;
int V_23 , V_135 , V_136 = 0 ;
F_87 (dev->of_node, child)
V_136 = F_90 ( V_136 , F_72 ( V_134 ) ) ;
V_135 = sizeof( * V_13 ) + ( V_136 * sizeof( V_13 -> V_14 [ 0 ] ) ) ;
V_13 = F_76 ( V_26 , V_135 , V_89 ) ;
if ( ! V_13 )
return - V_59 ;
V_13 -> V_116 = V_136 ;
V_13 -> V_26 = V_26 ;
V_130 = F_78 ( V_127 , V_131 , 0 ) ;
if ( V_130 )
V_13 -> V_137 = F_79 ( V_26 , V_130 ) ;
V_13 -> V_117 = F_91 ( V_26 , L_25 ) ;
if ( F_80 ( V_13 -> V_117 ) ) {
F_15 ( V_26 , L_26 ) ;
return F_81 ( V_13 -> V_117 ) ;
}
V_13 -> V_118 = F_91 ( V_26 , L_27 ) ;
if ( F_80 ( V_13 -> V_118 ) ) {
F_15 ( V_26 , L_28 ) ;
return F_81 ( V_13 -> V_118 ) ;
}
if ( F_92 ( V_26 -> V_133 , L_29 ,
& V_13 -> V_65 ) ) {
F_15 ( V_26 , L_30 ) ;
return - V_97 ;
}
if ( F_86 ( V_13 ) ) {
V_23 = F_66 ( V_26 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_31 , V_23 ) ;
return V_23 ;
}
}
F_77 ( V_127 , V_13 ) ;
F_93 ( V_26 ) ;
V_23 = F_94 ( V_26 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_32 ) ;
return V_23 ;
}
V_23 = F_95 ( & V_13 -> V_50 , V_26 , NULL ,
F_39 ( V_26 ) ) ;
if ( V_23 ) {
F_15 ( V_26 , L_33 ) ;
return V_23 ;
}
F_96 ( & V_13 -> V_50 , & V_9 ) ;
F_97 ( & V_13 -> V_50 , V_26 -> V_138 ) ;
V_23 = F_98 ( & V_13 -> V_50 ) ;
if ( V_23 ) {
F_15 ( V_26 , L_34 ) ;
return V_23 ;
}
F_99 ( & V_139 , & V_9 ) ;
if ( V_13 -> V_137 ) {
F_35 ( V_26 ) ;
F_6 ( 0xffffffff , V_13 -> V_137 + V_140 ) ;
F_37 ( V_26 ) ;
}
return 0 ;
}
static int F_100 ( struct V_111 * V_127 )
{
struct V_5 * V_13 = F_60 ( V_127 ) ;
F_99 ( & V_139 , NULL ) ;
F_101 ( & V_127 -> V_26 ) ;
F_77 ( V_127 , NULL ) ;
F_102 ( & V_13 -> V_50 ) ;
F_103 ( & V_13 -> V_50 ) ;
return 0 ;
}
static int T_7 F_104 ( struct V_91 * V_26 )
{
struct V_111 * V_127 = F_105 ( V_26 ) ;
struct V_5 * V_13 = F_60 ( V_127 ) ;
return F_62 ( V_13 ) ;
}
static int T_7 F_106 ( struct V_91 * V_26 )
{
struct V_111 * V_127 = F_105 ( V_26 ) ;
struct V_5 * V_13 = F_60 ( V_127 ) ;
F_65 ( V_13 ) ;
return 0 ;
}
static int T_8 F_107 ( void )
{
int V_23 ;
V_23 = F_108 ( & V_141 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_108 ( & V_142 ) ;
if ( V_23 )
F_109 ( & V_141 ) ;
return V_23 ;
}
static void T_9 F_110 ( void )
{
F_109 ( & V_142 ) ;
F_109 ( & V_141 ) ;
}
