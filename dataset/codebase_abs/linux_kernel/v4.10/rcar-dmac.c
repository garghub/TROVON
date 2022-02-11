static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 == V_5 )
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
else
F_3 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_3 == V_5 )
return F_5 ( V_2 -> V_6 + V_3 ) ;
else
return F_6 ( V_2 -> V_6 + V_3 ) ;
}
static T_1 F_7 ( struct V_7 * V_8 , T_1 V_3 )
{
if ( V_3 == V_9 )
return F_5 ( V_8 -> V_6 + V_3 ) ;
else
return F_6 ( V_8 -> V_6 + V_3 ) ;
}
static void F_8 ( struct V_7 * V_8 , T_1 V_3 , T_1 V_4 )
{
if ( V_3 == V_9 )
F_2 ( V_4 , V_8 -> V_6 + V_3 ) ;
else
F_3 ( V_4 , V_8 -> V_6 + V_3 ) ;
}
static bool F_9 ( struct V_7 * V_8 )
{
T_1 V_10 = F_7 ( V_8 , V_11 ) ;
return ! ! ( V_10 & ( V_12 | V_13 ) ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
T_1 V_10 = V_15 -> V_10 ;
F_11 ( F_9 ( V_8 ) ) ;
if ( V_8 -> V_17 >= 0 )
F_8 ( V_8 , V_9 , V_8 -> V_17 ) ;
if ( V_15 -> V_18 . V_19 ) {
struct V_20 * V_21 ;
F_12 ( V_8 -> V_8 . V_22 -> V_23 ,
L_1 ,
V_8 -> V_24 , V_15 , V_15 -> V_25 , & V_15 -> V_18 . V_26 ) ;
#ifdef F_13
F_8 ( V_8 , V_27 ,
V_15 -> V_18 . V_26 >> 32 ) ;
#endif
F_8 ( V_8 , V_28 ,
( V_15 -> V_18 . V_26 & 0xfffffff0 ) |
V_29 ) ;
F_8 ( V_8 , V_30 ,
F_14 ( V_15 -> V_25 - 1 ) |
V_31 ) ;
V_21 = F_15 ( & V_15 -> V_32 ,
struct V_20 , V_33 ) ;
F_8 ( V_8 , V_34 ,
V_21 -> V_35 & 0xffffffff ) ;
F_8 ( V_8 , V_36 , F_16 ( 1 ) ) ;
V_10 |= V_37 | V_38
| V_39 | V_40 ;
if ( ! V_15 -> V_41 )
V_10 |= V_42 | V_43 ;
else if ( V_15 -> V_44 . V_45 )
V_10 |= V_46 | V_47 ;
else
V_10 |= V_46 ;
} else {
struct V_20 * V_21 = V_15 -> V_16 ;
F_12 ( V_8 -> V_8 . V_22 -> V_23 ,
L_2 ,
V_8 -> V_24 , V_21 , V_21 -> V_48 , & V_21 -> V_49 ,
& V_21 -> V_35 ) ;
#ifdef F_13
F_8 ( V_8 , V_50 ,
V_21 -> V_49 >> 32 ) ;
F_8 ( V_8 , V_51 ,
V_21 -> V_35 >> 32 ) ;
#endif
F_8 ( V_8 , V_52 ,
V_21 -> V_49 & 0xffffffff ) ;
F_8 ( V_8 , V_34 ,
V_21 -> V_35 & 0xffffffff ) ;
F_8 ( V_8 , V_53 ,
V_21 -> V_48 >> V_15 -> V_54 ) ;
V_10 |= V_55 | V_43 ;
}
F_8 ( V_8 , V_11 , V_10 | V_12 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 V_56 ;
F_1 ( V_2 , V_57 , F_18 ( V_2 -> V_58 - 1 , 0 ) ) ;
F_1 ( V_2 , V_5 ,
V_59 | V_60 ) ;
V_56 = F_4 ( V_2 , V_5 ) ;
if ( ( V_56 & ( V_61 | V_60 ) ) != V_60 ) {
F_19 ( V_2 -> V_23 , L_3 ) ;
return - V_62 ;
}
return 0 ;
}
static T_3 F_20 ( struct V_63 * V_64 )
{
struct V_7 * V_8 = F_21 ( V_64 -> V_8 ) ;
struct V_14 * V_15 = F_22 ( V_64 ) ;
unsigned long V_65 ;
T_3 V_66 ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
V_66 = F_24 ( V_64 ) ;
F_12 ( V_8 -> V_8 . V_22 -> V_23 , L_4 ,
V_8 -> V_24 , V_64 -> V_66 , V_15 ) ;
F_25 ( & V_15 -> V_33 , & V_8 -> V_15 . V_68 ) ;
V_15 -> V_16 = F_15 ( & V_15 -> V_32 ,
struct V_20 , V_33 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return V_66 ;
}
static int F_27 ( struct V_7 * V_8 , T_4 V_69 )
{
struct V_70 * V_71 ;
unsigned long V_65 ;
F_28 ( V_72 ) ;
unsigned int V_73 ;
V_71 = ( void * ) F_29 ( V_69 ) ;
if ( ! V_71 )
return - V_74 ;
for ( V_73 = 0 ; V_73 < V_75 ; ++ V_73 ) {
struct V_14 * V_15 = & V_71 -> V_76 [ V_73 ] ;
F_30 ( & V_15 -> V_44 , & V_8 -> V_8 ) ;
V_15 -> V_44 . V_77 = F_20 ;
F_31 ( & V_15 -> V_32 ) ;
F_25 ( & V_15 -> V_33 , & V_72 ) ;
}
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_32 ( & V_72 , & V_8 -> V_15 . free ) ;
F_25 ( & V_71 -> V_33 , & V_8 -> V_15 . V_78 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return 0 ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
unsigned long V_65 ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_34 ( & V_15 -> V_32 , & V_8 -> V_15 . V_79 ) ;
F_35 ( & V_15 -> V_33 , & V_8 -> V_15 . free ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_14 * V_15 , * V_80 ;
unsigned long V_65 ;
F_28 ( V_72 ) ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_37 ( & V_8 -> V_15 . V_81 , & V_72 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
F_38 (desc, _desc, &list, node) {
if ( F_39 ( & V_15 -> V_44 ) ) {
F_40 ( & V_15 -> V_33 ) ;
F_33 ( V_8 , V_15 ) ;
}
}
if ( F_41 ( & V_72 ) )
return;
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_42 ( & V_72 , & V_8 -> V_15 . V_81 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
}
static struct V_14 * F_43 ( struct V_7 * V_8 )
{
struct V_14 * V_15 ;
unsigned long V_65 ;
int V_82 ;
F_36 ( V_8 ) ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
while ( F_41 ( & V_8 -> V_15 . free ) ) {
F_26 ( & V_8 -> V_67 , V_65 ) ;
V_82 = F_27 ( V_8 , V_83 ) ;
if ( V_82 < 0 )
return NULL ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
}
V_15 = F_15 ( & V_8 -> V_15 . free , struct V_14 , V_33 ) ;
F_40 ( & V_15 -> V_33 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return V_15 ;
}
static int F_44 ( struct V_7 * V_8 , T_4 V_69 )
{
struct V_70 * V_71 ;
unsigned long V_65 ;
F_28 ( V_72 ) ;
unsigned int V_73 ;
V_71 = ( void * ) F_29 ( V_69 ) ;
if ( ! V_71 )
return - V_74 ;
for ( V_73 = 0 ; V_73 < V_84 ; ++ V_73 ) {
struct V_20 * V_21 = & V_71 -> V_32 [ V_73 ] ;
F_25 ( & V_21 -> V_33 , & V_72 ) ;
}
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_32 ( & V_72 , & V_8 -> V_15 . V_79 ) ;
F_25 ( & V_71 -> V_33 , & V_8 -> V_15 . V_78 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return 0 ;
}
static struct V_20 *
F_45 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
unsigned long V_65 ;
int V_82 ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
while ( F_41 ( & V_8 -> V_15 . V_79 ) ) {
F_26 ( & V_8 -> V_67 , V_65 ) ;
V_82 = F_44 ( V_8 , V_83 ) ;
if ( V_82 < 0 )
return NULL ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
}
V_21 = F_15 ( & V_8 -> V_15 . V_79 ,
struct V_20 , V_33 ) ;
F_40 ( & V_21 -> V_33 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return V_21 ;
}
static void F_46 ( struct V_7 * V_8 ,
struct V_14 * V_15 , T_5 V_48 )
{
V_48 = F_47 ( V_48 ) ;
if ( V_15 -> V_18 . V_48 == V_48 )
return;
if ( V_15 -> V_18 . V_85 ) {
F_48 ( V_8 -> V_8 . V_22 -> V_23 , V_15 -> V_18 . V_48 ,
V_15 -> V_18 . V_85 , V_15 -> V_18 . V_26 ) ;
V_15 -> V_18 . V_85 = NULL ;
V_15 -> V_18 . V_48 = 0 ;
}
if ( ! V_48 )
return;
V_15 -> V_18 . V_85 = F_49 ( V_8 -> V_8 . V_22 -> V_23 , V_48 ,
& V_15 -> V_18 . V_26 , V_83 ) ;
if ( ! V_15 -> V_18 . V_85 )
return;
V_15 -> V_18 . V_48 = V_48 ;
}
static int F_50 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_20 * V_21 ;
struct V_86 * V_87 ;
F_46 ( V_8 , V_15 , V_15 -> V_25 * sizeof( * V_87 ) ) ;
V_87 = V_15 -> V_18 . V_85 ;
if ( ! V_87 )
return - V_74 ;
F_51 (chunk, &desc->chunks, node) {
V_87 -> V_88 = V_21 -> V_49 ;
V_87 -> V_89 = V_21 -> V_35 ;
V_87 -> V_90 = V_21 -> V_48 >> V_15 -> V_54 ;
V_87 ++ ;
}
return 0 ;
}
static void F_52 ( struct V_7 * V_8 )
{
T_1 V_10 = F_7 ( V_8 , V_11 ) ;
V_10 &= ~ ( V_91 | V_47 | V_43 |
V_13 | V_12 ) ;
F_8 ( V_8 , V_11 , V_10 ) ;
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_14 * V_15 , * V_80 ;
unsigned long V_65 ;
F_28 ( V_76 ) ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_37 ( & V_8 -> V_15 . V_68 , & V_76 ) ;
F_37 ( & V_8 -> V_15 . V_92 , & V_76 ) ;
F_37 ( & V_8 -> V_15 . V_93 , & V_76 ) ;
F_37 ( & V_8 -> V_15 . V_81 , & V_76 ) ;
V_8 -> V_15 . V_16 = NULL ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
F_38 (desc, _desc, &descs, node) {
F_40 ( & V_15 -> V_33 ) ;
F_33 ( V_8 , V_15 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_5 , 0 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_73 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_58 ; ++ V_73 ) {
struct V_7 * V_8 = & V_2 -> V_94 [ V_73 ] ;
F_56 ( & V_8 -> V_67 ) ;
F_52 ( V_8 ) ;
F_57 ( & V_8 -> V_67 ) ;
F_53 ( V_8 ) ;
}
}
static void F_58 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
static const T_1 V_95 [] = {
V_96 , V_97 ,
V_98 , V_99 ,
V_100 , V_101 ,
V_102 ,
} ;
unsigned int V_103 ;
T_1 V_10 ;
switch ( V_15 -> V_104 ) {
case V_105 :
V_10 = V_106 | V_107
| V_108 ;
V_103 = V_8 -> V_109 . V_103 ;
break;
case V_110 :
V_10 = V_111 | V_112
| V_108 ;
V_103 = V_8 -> V_113 . V_103 ;
break;
case V_114 :
default:
V_10 = V_106 | V_112
| V_115 ;
V_103 = V_116 ;
break;
}
V_15 -> V_54 = F_59 ( V_103 ) ;
V_15 -> V_10 = V_10 | V_95 [ V_15 -> V_54 ] ;
}
static struct V_63 *
F_60 ( struct V_7 * V_8 , struct V_117 * V_118 ,
unsigned int V_119 , T_6 V_120 ,
enum V_121 V_122 , unsigned long V_123 ,
bool V_41 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
struct V_117 * V_124 ;
unsigned int V_25 = 0 ;
unsigned int V_125 ;
unsigned int V_126 = 0 ;
bool V_127 = false ;
unsigned int V_73 ;
V_15 = F_43 ( V_8 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_44 . V_65 = V_123 ;
V_15 -> V_44 . V_66 = - V_128 ;
V_15 -> V_41 = V_41 ;
V_15 -> V_104 = V_122 ;
F_58 ( V_8 , V_15 ) ;
V_125 = ( V_129 + 1 ) << V_15 -> V_54 ;
F_61 (sgl, sg, sg_len, i) {
T_6 V_130 = F_62 ( V_124 ) ;
unsigned int V_131 = F_63 ( V_124 ) ;
V_126 += V_131 ;
while ( V_131 ) {
unsigned int V_48 = F_64 ( V_131 , V_125 ) ;
#ifdef F_13
if ( V_120 >> 32 != ( V_120 + V_48 - 1 ) >> 32 )
V_48 = F_65 ( V_120 , 1ULL << 32 ) - V_120 ;
if ( V_130 >> 32 != ( V_130 + V_48 - 1 ) >> 32 )
V_48 = F_65 ( V_130 , 1ULL << 32 ) - V_130 ;
if ( V_120 >> 32 || V_130 >> 32 )
V_127 = true ;
#endif
V_21 = F_45 ( V_8 ) ;
if ( ! V_21 ) {
F_33 ( V_8 , V_15 ) ;
return NULL ;
}
if ( V_122 == V_105 ) {
V_21 -> V_49 = V_120 ;
V_21 -> V_35 = V_130 ;
} else {
V_21 -> V_49 = V_130 ;
V_21 -> V_35 = V_120 ;
}
V_21 -> V_48 = V_48 ;
F_12 ( V_8 -> V_8 . V_22 -> V_23 ,
L_5 ,
V_8 -> V_24 , V_21 , V_15 , V_73 , V_124 , V_48 , V_131 ,
& V_21 -> V_49 , & V_21 -> V_35 ) ;
V_130 += V_48 ;
if ( V_122 == V_114 )
V_120 += V_48 ;
V_131 -= V_48 ;
F_25 ( & V_21 -> V_33 , & V_15 -> V_32 ) ;
V_25 ++ ;
}
}
V_15 -> V_25 = V_25 ;
V_15 -> V_48 = V_126 ;
V_15 -> V_18 . V_19 = ! V_127 && V_25 > 1 ;
if ( V_15 -> V_18 . V_19 ) {
if ( F_50 ( V_8 , V_15 ) < 0 )
V_15 -> V_18 . V_19 = false ;
}
return & V_15 -> V_44 ;
}
static int F_66 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
int V_82 ;
F_31 ( & V_133 -> V_15 . V_79 ) ;
F_31 ( & V_133 -> V_15 . V_78 ) ;
V_82 = F_44 ( V_133 , V_134 ) ;
if ( V_82 < 0 )
return - V_74 ;
V_82 = F_27 ( V_133 , V_134 ) ;
if ( V_82 < 0 )
return - V_74 ;
return F_67 ( V_8 -> V_22 -> V_23 ) ;
}
static void F_68 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_69 ( V_8 -> V_22 ) ;
struct V_135 * V_136 = & V_133 -> V_136 ;
struct V_70 * V_71 , * V_137 ;
struct V_14 * V_15 ;
F_28 ( V_72 ) ;
F_70 ( & V_133 -> V_67 ) ;
F_52 ( V_133 ) ;
F_71 ( & V_133 -> V_67 ) ;
if ( V_133 -> V_17 >= 0 ) {
F_72 ( V_133 -> V_17 , V_2 -> V_138 ) ;
V_133 -> V_17 = - V_139 ;
}
F_37 ( & V_133 -> V_15 . free , & V_72 ) ;
F_37 ( & V_133 -> V_15 . V_68 , & V_72 ) ;
F_37 ( & V_133 -> V_15 . V_92 , & V_72 ) ;
F_37 ( & V_133 -> V_15 . V_93 , & V_72 ) ;
F_37 ( & V_133 -> V_15 . V_81 , & V_72 ) ;
V_133 -> V_15 . V_16 = NULL ;
F_51 (desc, &list, node)
F_46 ( V_133 , V_15 , 0 ) ;
F_38 (page, _page, &rchan->desc.pages, node) {
F_40 ( & V_71 -> V_33 ) ;
F_73 ( ( unsigned long ) V_71 ) ;
}
if ( V_136 -> V_140 . V_103 ) {
F_74 ( V_8 -> V_22 -> V_23 , V_136 -> V_141 ,
V_136 -> V_140 . V_103 , V_136 -> V_122 , 0 ) ;
V_136 -> V_140 . V_103 = 0 ;
}
F_75 ( V_8 -> V_22 -> V_23 ) ;
}
static struct V_63 *
F_76 ( struct V_132 * V_8 , T_6 V_142 ,
T_6 V_143 , T_5 V_131 , unsigned long V_65 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
struct V_117 V_118 ;
if ( ! V_131 )
return NULL ;
F_77 ( & V_118 , 1 ) ;
F_78 ( & V_118 , F_79 ( F_80 ( V_143 ) ) , V_131 ,
F_81 ( V_143 ) ) ;
F_62 ( & V_118 ) = V_143 ;
F_63 ( & V_118 ) = V_131 ;
return F_60 ( V_133 , & V_118 , 1 , V_142 ,
V_114 , V_65 , false ) ;
}
static int F_82 ( struct V_132 * V_8 ,
enum V_121 V_122 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
struct V_135 * V_136 = & V_133 -> V_136 ;
T_7 V_120 ;
T_5 V_144 ;
enum V_145 V_146 ;
if ( V_122 == V_105 ) {
V_120 = V_133 -> V_109 . V_147 ;
V_144 = V_133 -> V_109 . V_103 ;
V_146 = V_148 ;
} else {
V_120 = V_133 -> V_113 . V_147 ;
V_144 = V_133 -> V_113 . V_103 ;
V_146 = V_149 ;
}
if ( V_120 == V_136 -> V_140 . V_147 &&
V_144 == V_136 -> V_140 . V_103 &&
V_146 == V_136 -> V_122 )
return 0 ;
if ( V_136 -> V_140 . V_103 )
F_74 ( V_8 -> V_22 -> V_23 , V_136 -> V_141 ,
V_136 -> V_140 . V_103 , V_136 -> V_122 , 0 ) ;
V_136 -> V_140 . V_103 = 0 ;
V_136 -> V_141 = F_83 ( V_8 -> V_22 -> V_23 , V_120 , V_144 ,
V_146 , 0 ) ;
if ( F_84 ( V_8 -> V_22 -> V_23 , V_136 -> V_141 ) ) {
F_85 ( V_8 -> V_22 -> V_23 ,
L_6 , V_133 -> V_24 ,
V_144 , & V_120 ) ;
return - V_62 ;
}
F_12 ( V_8 -> V_22 -> V_23 , L_7 ,
V_133 -> V_24 , V_144 , & V_120 , & V_136 -> V_141 ,
V_146 == V_148 ? L_8 : L_9 ) ;
V_136 -> V_140 . V_147 = V_120 ;
V_136 -> V_140 . V_103 = V_144 ;
V_136 -> V_122 = V_146 ;
return 0 ;
}
static struct V_63 *
F_86 ( struct V_132 * V_8 , struct V_117 * V_118 ,
unsigned int V_119 , enum V_121 V_122 ,
unsigned long V_65 , void * V_150 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
if ( V_133 -> V_17 < 0 || ! V_119 ) {
F_19 ( V_8 -> V_22 -> V_23 ,
L_10 ,
V_151 , V_119 , V_133 -> V_17 ) ;
return NULL ;
}
if ( F_82 ( V_8 , V_122 ) )
return NULL ;
return F_60 ( V_133 , V_118 , V_119 , V_133 -> V_136 . V_141 ,
V_122 , V_65 , false ) ;
}
static struct V_63 *
F_87 ( struct V_132 * V_8 , T_6 V_152 ,
T_5 V_153 , T_5 V_154 ,
enum V_121 V_122 , unsigned long V_65 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
struct V_63 * V_15 ;
struct V_117 * V_118 ;
unsigned int V_119 ;
unsigned int V_73 ;
if ( V_133 -> V_17 < 0 || V_153 < V_154 ) {
F_19 ( V_8 -> V_22 -> V_23 ,
L_11 ,
V_151 , V_153 , V_154 , V_133 -> V_17 ) ;
return NULL ;
}
if ( F_82 ( V_8 , V_122 ) )
return NULL ;
V_119 = V_153 / V_154 ;
if ( V_119 > V_155 ) {
F_85 ( V_8 -> V_22 -> V_23 ,
L_12 ,
V_133 -> V_24 , V_119 , V_155 ) ;
return NULL ;
}
V_118 = F_88 ( V_119 , sizeof( * V_118 ) , V_83 ) ;
if ( ! V_118 )
return NULL ;
F_77 ( V_118 , V_119 ) ;
for ( V_73 = 0 ; V_73 < V_119 ; ++ V_73 ) {
T_6 V_109 = V_152 + ( V_154 * V_73 ) ;
F_78 ( & V_118 [ V_73 ] , F_79 ( F_80 ( V_109 ) ) , V_154 ,
F_81 ( V_109 ) ) ;
F_62 ( & V_118 [ V_73 ] ) = V_109 ;
F_63 ( & V_118 [ V_73 ] ) = V_154 ;
}
V_15 = F_60 ( V_133 , V_118 , V_119 , V_133 -> V_136 . V_141 ,
V_122 , V_65 , true ) ;
F_89 ( V_118 ) ;
return V_15 ;
}
static int F_90 ( struct V_132 * V_8 ,
struct V_156 * V_157 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
V_133 -> V_109 . V_147 = V_157 -> V_49 ;
V_133 -> V_113 . V_147 = V_157 -> V_35 ;
V_133 -> V_109 . V_103 = V_157 -> V_158 ;
V_133 -> V_113 . V_103 = V_157 -> V_159 ;
return 0 ;
}
static int F_91 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
unsigned long V_65 ;
F_23 ( & V_133 -> V_67 , V_65 ) ;
F_52 ( V_133 ) ;
F_26 ( & V_133 -> V_67 , V_65 ) ;
F_53 ( V_133 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_7 * V_8 ,
T_3 V_66 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
struct V_20 * V_16 = NULL ;
struct V_20 * V_21 ;
enum V_160 V_161 ;
unsigned int V_162 = 0 ;
unsigned int V_163 = 0 ;
if ( ! V_15 )
return 0 ;
V_161 = F_93 ( & V_8 -> V_8 , V_66 , NULL ) ;
if ( V_161 == V_164 )
return 0 ;
if ( V_66 != V_15 -> V_44 . V_66 ) {
F_51 (desc, &chan->desc.pending, node) {
if ( V_66 == V_15 -> V_44 . V_66 )
return V_15 -> V_48 ;
}
F_51 (desc, &chan->desc.active, node) {
if ( V_66 == V_15 -> V_44 . V_66 )
return V_15 -> V_48 ;
}
F_94 ( 1 , L_13 ) ;
return 0 ;
}
if ( V_15 -> V_18 . V_19 ) {
V_163 = ( F_7 ( V_8 , V_30 ) &
V_165 ) >> V_166 ;
F_95 ( V_163 >= V_15 -> V_25 ) ;
} else {
V_16 = V_15 -> V_16 ;
}
F_96 (chunk, &desc->chunks, node) {
if ( V_21 == V_16 || ++ V_163 == V_15 -> V_25 )
break;
V_162 += V_21 -> V_48 ;
}
V_162 += F_7 ( V_8 , V_53 ) << V_15 -> V_54 ;
return V_162 ;
}
static enum V_160 F_97 ( struct V_132 * V_8 ,
T_3 V_66 ,
struct V_167 * V_168 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
enum V_160 V_161 ;
unsigned long V_65 ;
unsigned int V_162 ;
V_161 = F_93 ( V_8 , V_66 , V_168 ) ;
if ( V_161 == V_164 || ! V_168 )
return V_161 ;
F_23 ( & V_133 -> V_67 , V_65 ) ;
V_162 = F_92 ( V_133 , V_66 ) ;
F_26 ( & V_133 -> V_67 , V_65 ) ;
if ( ! V_162 )
return V_164 ;
F_98 ( V_168 , V_162 ) ;
return V_161 ;
}
static void F_99 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_21 ( V_8 ) ;
unsigned long V_65 ;
F_23 ( & V_133 -> V_67 , V_65 ) ;
if ( F_41 ( & V_133 -> V_15 . V_68 ) )
goto V_93;
F_34 ( & V_133 -> V_15 . V_68 , & V_133 -> V_15 . V_92 ) ;
if ( ! V_133 -> V_15 . V_16 ) {
struct V_14 * V_15 ;
V_15 = F_15 ( & V_133 -> V_15 . V_92 ,
struct V_14 , V_33 ) ;
V_133 -> V_15 . V_16 = V_15 ;
F_10 ( V_133 ) ;
}
V_93:
F_26 ( & V_133 -> V_67 , V_65 ) ;
}
static T_8 F_100 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
unsigned int V_169 ;
if ( F_95 ( ! V_15 || ! V_15 -> V_41 ) ) {
return V_170 ;
}
V_169 = ( F_7 ( V_8 , V_30 ) &
V_165 ) >> V_166 ;
F_8 ( V_8 , V_36 , F_16 ( V_169 ) ) ;
return V_171 ;
}
static T_8 F_101 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
T_8 V_82 = V_171 ;
if ( F_11 ( ! V_15 ) ) {
return V_170 ;
}
if ( ! V_15 -> V_18 . V_19 ) {
if ( ! F_102 ( & V_15 -> V_16 -> V_33 , & V_15 -> V_32 ) ) {
V_15 -> V_16 = F_103 ( V_15 -> V_16 , V_33 ) ;
if ( ! V_15 -> V_41 )
V_82 = V_172 ;
goto V_93;
}
if ( V_15 -> V_41 ) {
V_15 -> V_16 =
F_15 ( & V_15 -> V_32 ,
struct V_20 ,
V_33 ) ;
goto V_93;
}
}
F_104 ( & V_15 -> V_33 , & V_8 -> V_15 . V_93 ) ;
if ( ! F_41 ( & V_8 -> V_15 . V_92 ) )
V_8 -> V_15 . V_16 = F_15 ( & V_8 -> V_15 . V_92 ,
struct V_14 ,
V_33 ) ;
else
V_8 -> V_15 . V_16 = NULL ;
V_93:
if ( V_8 -> V_15 . V_16 )
F_10 ( V_8 ) ;
return V_82 ;
}
static T_8 F_105 ( int V_173 , void * V_23 )
{
T_1 V_174 = V_91 | V_13 ;
struct V_7 * V_8 = V_23 ;
T_8 V_82 = V_170 ;
T_1 V_10 ;
F_56 ( & V_8 -> V_67 ) ;
V_10 = F_7 ( V_8 , V_11 ) ;
if ( V_10 & V_13 )
V_174 |= V_12 ;
F_8 ( V_8 , V_11 , V_10 & ~ V_174 ) ;
if ( V_10 & V_91 )
V_82 |= F_100 ( V_8 ) ;
if ( V_10 & V_13 )
V_82 |= F_101 ( V_8 ) ;
F_57 ( & V_8 -> V_67 ) ;
return V_82 ;
}
static T_8 F_106 ( int V_173 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
struct V_14 * V_15 ;
struct V_175 V_176 ;
F_70 ( & V_8 -> V_67 ) ;
if ( V_8 -> V_15 . V_16 && V_8 -> V_15 . V_16 -> V_41 ) {
V_15 = V_8 -> V_15 . V_16 ;
F_107 ( & V_15 -> V_44 , & V_176 ) ;
if ( F_108 ( & V_176 ) ) {
F_71 ( & V_8 -> V_67 ) ;
F_109 ( & V_176 , NULL ) ;
F_70 ( & V_8 -> V_67 ) ;
}
}
while ( ! F_41 ( & V_8 -> V_15 . V_93 ) ) {
V_15 = F_15 ( & V_8 -> V_15 . V_93 , struct V_14 ,
V_33 ) ;
F_110 ( & V_15 -> V_44 ) ;
F_40 ( & V_15 -> V_33 ) ;
F_107 ( & V_15 -> V_44 , & V_176 ) ;
if ( F_108 ( & V_176 ) ) {
F_71 ( & V_8 -> V_67 ) ;
F_109 ( & V_176 , NULL ) ;
F_70 ( & V_8 -> V_67 ) ;
}
F_25 ( & V_15 -> V_33 , & V_8 -> V_15 . V_81 ) ;
}
F_71 ( & V_8 -> V_67 ) ;
F_36 ( V_8 ) ;
return V_172 ;
}
static T_8 F_111 ( int V_173 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
if ( ! ( F_4 ( V_2 , V_5 ) & V_61 ) )
return V_170 ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_172 ;
}
static bool F_112 ( struct V_132 * V_8 , void * V_177 )
{
struct V_1 * V_2 = F_69 ( V_8 -> V_22 ) ;
struct V_178 * V_179 = V_177 ;
if ( V_8 -> V_22 -> V_180 != F_90 ||
V_179 -> V_181 != V_8 -> V_22 -> V_23 -> V_182 )
return false ;
return ! F_113 ( V_179 -> args [ 0 ] , V_2 -> V_138 ) ;
}
static struct V_132 * F_114 ( struct V_178 * V_179 ,
struct V_183 * V_184 )
{
struct V_7 * V_133 ;
struct V_132 * V_8 ;
T_9 V_174 ;
if ( V_179 -> V_185 != 1 )
return NULL ;
F_115 ( V_174 ) ;
F_116 ( V_186 , V_174 ) ;
V_8 = F_117 ( V_174 , F_112 , V_179 ) ;
if ( ! V_8 )
return NULL ;
V_133 = F_21 ( V_8 ) ;
V_133 -> V_17 = V_179 -> args [ 0 ] ;
return V_8 ;
}
static int F_118 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_119 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_120 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_121 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_122 ( V_23 ) ;
return F_17 ( V_2 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_7 * V_133 ,
unsigned int V_24 )
{
struct V_187 * V_188 = F_124 ( V_2 -> V_23 ) ;
struct V_132 * V_8 = & V_133 -> V_8 ;
char V_189 [ 5 ] ;
char * V_190 ;
int V_173 ;
int V_82 ;
V_133 -> V_24 = V_24 ;
V_133 -> V_6 = V_2 -> V_6 + F_125 ( V_24 ) ;
V_133 -> V_17 = - V_139 ;
F_126 ( & V_133 -> V_67 ) ;
F_31 ( & V_133 -> V_15 . free ) ;
F_31 ( & V_133 -> V_15 . V_68 ) ;
F_31 ( & V_133 -> V_15 . V_92 ) ;
F_31 ( & V_133 -> V_15 . V_93 ) ;
F_31 ( & V_133 -> V_15 . V_81 ) ;
sprintf ( V_189 , L_14 , V_24 ) ;
V_173 = F_127 ( V_188 , V_189 ) ;
if ( V_173 < 0 ) {
F_85 ( V_2 -> V_23 , L_15 , V_24 ) ;
return - V_191 ;
}
V_190 = F_128 ( V_2 -> V_23 , V_134 , L_16 ,
F_129 ( V_2 -> V_23 ) , V_24 ) ;
if ( ! V_190 )
return - V_74 ;
V_82 = F_130 ( V_2 -> V_23 , V_173 , F_105 ,
F_106 , 0 ,
V_190 , V_133 ) ;
if ( V_82 ) {
F_85 ( V_2 -> V_23 , L_17 , V_173 , V_82 ) ;
return V_82 ;
}
V_8 -> V_22 = & V_2 -> V_192 ;
F_131 ( V_8 ) ;
F_25 ( & V_8 -> V_193 , & V_2 -> V_192 . V_94 ) ;
return 0 ;
}
static int F_132 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_193 * V_181 = V_23 -> V_182 ;
int V_82 ;
V_82 = F_133 ( V_181 , L_18 , & V_2 -> V_58 ) ;
if ( V_82 < 0 ) {
F_85 ( V_23 , L_19 ) ;
return V_82 ;
}
if ( V_2 -> V_58 <= 0 || V_2 -> V_58 >= 100 ) {
F_85 ( V_23 , L_20 ,
V_2 -> V_58 ) ;
return - V_139 ;
}
return 0 ;
}
static int F_134 ( struct V_187 * V_188 )
{
const enum V_194 V_195 = V_196 |
V_197 | V_198 |
V_199 | V_200 |
V_201 | V_202 ;
unsigned int V_203 = 0 ;
struct V_204 * V_192 ;
struct V_1 * V_2 ;
struct V_205 * V_85 ;
unsigned int V_73 ;
char * V_190 ;
int V_173 ;
int V_82 ;
V_2 = F_135 ( & V_188 -> V_23 , sizeof( * V_2 ) , V_134 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_23 = & V_188 -> V_23 ;
F_136 ( V_188 , V_2 ) ;
V_82 = F_132 ( & V_188 -> V_23 , V_2 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_188 -> V_23 . V_206 ) {
V_2 -> V_58 -- ;
V_203 = 1 ;
}
V_2 -> V_94 = F_137 ( & V_188 -> V_23 , V_2 -> V_58 ,
sizeof( * V_2 -> V_94 ) , V_134 ) ;
if ( ! V_2 -> V_94 )
return - V_74 ;
V_85 = F_138 ( V_188 , V_207 , 0 ) ;
V_2 -> V_6 = F_139 ( & V_188 -> V_23 , V_85 ) ;
if ( F_140 ( V_2 -> V_6 ) )
return F_141 ( V_2 -> V_6 ) ;
V_173 = F_127 ( V_188 , L_21 ) ;
if ( V_173 < 0 ) {
F_85 ( & V_188 -> V_23 , L_22 ) ;
return - V_191 ;
}
V_190 = F_128 ( V_2 -> V_23 , V_134 , L_23 ,
F_129 ( V_2 -> V_23 ) ) ;
if ( ! V_190 )
return - V_74 ;
V_82 = F_142 ( & V_188 -> V_23 , V_173 , F_111 , 0 ,
V_190 , V_2 ) ;
if ( V_82 ) {
F_85 ( & V_188 -> V_23 , L_17 ,
V_173 , V_82 ) ;
return V_82 ;
}
F_143 ( & V_188 -> V_23 ) ;
V_82 = F_67 ( & V_188 -> V_23 ) ;
if ( V_82 < 0 ) {
F_85 ( & V_188 -> V_23 , L_24 , V_82 ) ;
return V_82 ;
}
V_82 = F_17 ( V_2 ) ;
F_75 ( & V_188 -> V_23 ) ;
if ( V_82 ) {
F_85 ( & V_188 -> V_23 , L_25 ) ;
goto error;
}
F_31 ( & V_2 -> V_192 . V_94 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_58 ; ++ V_73 ) {
V_82 = F_123 ( V_2 , & V_2 -> V_94 [ V_73 ] ,
V_73 + V_203 ) ;
if ( V_82 < 0 )
goto error;
}
V_82 = F_144 ( V_188 -> V_23 . V_182 , F_114 ,
NULL ) ;
if ( V_82 < 0 )
goto error;
V_192 = & V_2 -> V_192 ;
F_116 ( V_208 , V_192 -> V_209 ) ;
F_116 ( V_186 , V_192 -> V_209 ) ;
V_192 -> V_23 = & V_188 -> V_23 ;
V_192 -> V_210 = F_59 ( V_116 ) ;
V_192 -> V_211 = V_195 ;
V_192 -> V_212 = V_195 ;
V_192 -> V_213 = F_145 ( V_110 ) | F_145 ( V_105 ) ;
V_192 -> V_214 = V_215 ;
V_192 -> V_216 = F_66 ;
V_192 -> V_217 = F_68 ;
V_192 -> V_218 = F_76 ;
V_192 -> V_219 = F_86 ;
V_192 -> V_220 = F_87 ;
V_192 -> V_180 = F_90 ;
V_192 -> V_221 = F_91 ;
V_192 -> V_222 = F_97 ;
V_192 -> V_223 = F_99 ;
V_82 = F_146 ( V_192 ) ;
if ( V_82 < 0 )
goto error;
return 0 ;
error:
F_147 ( V_188 -> V_23 . V_182 ) ;
F_148 ( & V_188 -> V_23 ) ;
return V_82 ;
}
static int F_149 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_150 ( V_188 ) ;
F_147 ( V_188 -> V_23 . V_182 ) ;
F_151 ( & V_2 -> V_192 ) ;
F_148 ( & V_188 -> V_23 ) ;
return 0 ;
}
static void F_152 ( struct V_187 * V_188 )
{
struct V_1 * V_2 = F_150 ( V_188 ) ;
F_54 ( V_2 ) ;
}
