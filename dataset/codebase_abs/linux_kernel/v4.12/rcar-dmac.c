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
struct V_20 * V_21 =
F_12 ( & V_15 -> V_22 ,
struct V_20 , V_23 ) ;
F_13 ( V_8 -> V_8 . V_24 -> V_25 ,
L_1 ,
V_8 -> V_26 , V_15 , V_15 -> V_27 , & V_15 -> V_18 . V_28 ) ;
#ifdef F_14
F_8 ( V_8 , V_29 ,
V_21 -> V_30 >> 32 ) ;
F_8 ( V_8 , V_31 ,
V_21 -> V_32 >> 32 ) ;
F_8 ( V_8 , V_33 ,
V_15 -> V_18 . V_28 >> 32 ) ;
#endif
F_8 ( V_8 , V_34 ,
( V_15 -> V_18 . V_28 & 0xfffffff0 ) |
V_35 ) ;
F_8 ( V_8 , V_36 ,
F_15 ( V_15 -> V_27 - 1 ) |
V_37 ) ;
F_8 ( V_8 , V_38 ,
V_21 -> V_32 & 0xffffffff ) ;
F_8 ( V_8 , V_39 , F_16 ( 1 ) ) ;
V_10 |= V_40 | V_41
| V_42 | V_43 ;
if ( ! V_15 -> V_44 )
V_10 |= V_45 | V_46 ;
else if ( V_15 -> V_47 . V_48 )
V_10 |= V_49 | V_50 ;
else
V_10 |= V_49 ;
} else {
struct V_20 * V_21 = V_15 -> V_16 ;
F_13 ( V_8 -> V_8 . V_24 -> V_25 ,
L_2 ,
V_8 -> V_26 , V_21 , V_21 -> V_51 , & V_21 -> V_30 ,
& V_21 -> V_32 ) ;
#ifdef F_14
F_8 ( V_8 , V_29 ,
V_21 -> V_30 >> 32 ) ;
F_8 ( V_8 , V_31 ,
V_21 -> V_32 >> 32 ) ;
#endif
F_8 ( V_8 , V_52 ,
V_21 -> V_30 & 0xffffffff ) ;
F_8 ( V_8 , V_38 ,
V_21 -> V_32 & 0xffffffff ) ;
F_8 ( V_8 , V_53 ,
V_21 -> V_51 >> V_15 -> V_54 ) ;
V_10 |= V_55 | V_46 ;
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
F_19 ( V_2 -> V_25 , L_3 ) ;
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
F_13 ( V_8 -> V_8 . V_24 -> V_25 , L_4 ,
V_8 -> V_26 , V_64 -> V_66 , V_15 ) ;
F_25 ( & V_15 -> V_23 , & V_8 -> V_15 . V_68 ) ;
V_15 -> V_16 = F_12 ( & V_15 -> V_22 ,
struct V_20 , V_23 ) ;
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
F_30 ( & V_15 -> V_47 , & V_8 -> V_8 ) ;
V_15 -> V_47 . V_77 = F_20 ;
F_31 ( & V_15 -> V_22 ) ;
F_25 ( & V_15 -> V_23 , & V_72 ) ;
}
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_32 ( & V_72 , & V_8 -> V_15 . free ) ;
F_25 ( & V_71 -> V_23 , & V_8 -> V_15 . V_78 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return 0 ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
unsigned long V_65 ;
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_34 ( & V_15 -> V_22 , & V_8 -> V_15 . V_79 ) ;
F_35 ( & V_15 -> V_23 , & V_8 -> V_15 . free ) ;
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
if ( F_39 ( & V_15 -> V_47 ) ) {
F_40 ( & V_15 -> V_23 ) ;
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
V_15 = F_12 ( & V_8 -> V_15 . free , struct V_14 , V_23 ) ;
F_40 ( & V_15 -> V_23 ) ;
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
struct V_20 * V_21 = & V_71 -> V_22 [ V_73 ] ;
F_25 ( & V_21 -> V_23 , & V_72 ) ;
}
F_23 ( & V_8 -> V_67 , V_65 ) ;
F_32 ( & V_72 , & V_8 -> V_15 . V_79 ) ;
F_25 ( & V_71 -> V_23 , & V_8 -> V_15 . V_78 ) ;
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
V_21 = F_12 ( & V_8 -> V_15 . V_79 ,
struct V_20 , V_23 ) ;
F_40 ( & V_21 -> V_23 ) ;
F_26 ( & V_8 -> V_67 , V_65 ) ;
return V_21 ;
}
static void F_46 ( struct V_7 * V_8 ,
struct V_14 * V_15 , T_5 V_51 )
{
V_51 = F_47 ( V_51 ) ;
if ( V_15 -> V_18 . V_51 == V_51 )
return;
if ( V_15 -> V_18 . V_85 ) {
F_48 ( V_8 -> V_8 . V_24 -> V_25 , V_15 -> V_18 . V_51 ,
V_15 -> V_18 . V_85 , V_15 -> V_18 . V_28 ) ;
V_15 -> V_18 . V_85 = NULL ;
V_15 -> V_18 . V_51 = 0 ;
}
if ( ! V_51 )
return;
V_15 -> V_18 . V_85 = F_49 ( V_8 -> V_8 . V_24 -> V_25 , V_51 ,
& V_15 -> V_18 . V_28 , V_83 ) ;
if ( ! V_15 -> V_18 . V_85 )
return;
V_15 -> V_18 . V_51 = V_51 ;
}
static int F_50 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_20 * V_21 ;
struct V_86 * V_87 ;
F_46 ( V_8 , V_15 , V_15 -> V_27 * sizeof( * V_87 ) ) ;
V_87 = V_15 -> V_18 . V_85 ;
if ( ! V_87 )
return - V_74 ;
F_51 (chunk, &desc->chunks, node) {
V_87 -> V_88 = V_21 -> V_30 ;
V_87 -> V_89 = V_21 -> V_32 ;
V_87 -> V_90 = V_21 -> V_51 >> V_15 -> V_54 ;
V_87 ++ ;
}
return 0 ;
}
static void F_52 ( struct V_7 * V_8 )
{
T_1 V_10 = F_7 ( V_8 , V_11 ) ;
V_10 &= ~ ( V_91 | V_50 | V_46 |
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
F_40 ( & V_15 -> V_23 ) ;
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
bool V_44 )
{
struct V_20 * V_21 ;
struct V_14 * V_15 ;
struct V_117 * V_124 ;
unsigned int V_27 = 0 ;
unsigned int V_125 ;
unsigned int V_126 = 0 ;
bool V_127 = false ;
unsigned int V_73 ;
#ifdef F_14
T_1 V_128 ;
T_1 V_129 ;
#endif
V_15 = F_43 ( V_8 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_47 . V_65 = V_123 ;
V_15 -> V_47 . V_66 = - V_130 ;
V_15 -> V_44 = V_44 ;
V_15 -> V_104 = V_122 ;
F_58 ( V_8 , V_15 ) ;
V_125 = ( V_131 + 1 ) << V_15 -> V_54 ;
F_61 (sgl, sg, sg_len, i) {
T_6 V_132 = F_62 ( V_124 ) ;
unsigned int V_133 = F_63 ( V_124 ) ;
V_126 += V_133 ;
#ifdef F_14
if ( V_73 == 0 ) {
V_128 = V_120 >> 32 ;
V_129 = V_132 >> 32 ;
}
if ( ( V_120 >> 32 != V_128 ) ||
( V_132 >> 32 != V_129 ) )
V_127 = true ;
#endif
while ( V_133 ) {
unsigned int V_51 = F_64 ( V_133 , V_125 ) ;
#ifdef F_14
if ( V_120 >> 32 != ( V_120 + V_51 - 1 ) >> 32 ) {
V_51 = F_65 ( V_120 , 1ULL << 32 ) - V_120 ;
V_127 = true ;
}
if ( V_132 >> 32 != ( V_132 + V_51 - 1 ) >> 32 ) {
V_51 = F_65 ( V_132 , 1ULL << 32 ) - V_132 ;
V_127 = true ;
}
#endif
V_21 = F_45 ( V_8 ) ;
if ( ! V_21 ) {
F_33 ( V_8 , V_15 ) ;
return NULL ;
}
if ( V_122 == V_105 ) {
V_21 -> V_30 = V_120 ;
V_21 -> V_32 = V_132 ;
} else {
V_21 -> V_30 = V_132 ;
V_21 -> V_32 = V_120 ;
}
V_21 -> V_51 = V_51 ;
F_13 ( V_8 -> V_8 . V_24 -> V_25 ,
L_5 ,
V_8 -> V_26 , V_21 , V_15 , V_73 , V_124 , V_51 , V_133 ,
& V_21 -> V_30 , & V_21 -> V_32 ) ;
V_132 += V_51 ;
if ( V_122 == V_114 )
V_120 += V_51 ;
V_133 -= V_51 ;
F_25 ( & V_21 -> V_23 , & V_15 -> V_22 ) ;
V_27 ++ ;
}
}
V_15 -> V_27 = V_27 ;
V_15 -> V_51 = V_126 ;
V_15 -> V_18 . V_19 = ! V_127 && V_27 > 1 ;
if ( V_15 -> V_18 . V_19 ) {
if ( F_50 ( V_8 , V_15 ) < 0 )
V_15 -> V_18 . V_19 = false ;
}
return & V_15 -> V_47 ;
}
static int F_66 ( struct V_134 * V_8 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
int V_82 ;
F_31 ( & V_135 -> V_15 . V_79 ) ;
F_31 ( & V_135 -> V_15 . V_78 ) ;
V_82 = F_44 ( V_135 , V_136 ) ;
if ( V_82 < 0 )
return - V_74 ;
V_82 = F_27 ( V_135 , V_136 ) ;
if ( V_82 < 0 )
return - V_74 ;
return F_67 ( V_8 -> V_24 -> V_25 ) ;
}
static void F_68 ( struct V_134 * V_8 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
struct V_1 * V_2 = F_69 ( V_8 -> V_24 ) ;
struct V_137 * V_138 = & V_135 -> V_138 ;
struct V_70 * V_71 , * V_139 ;
struct V_14 * V_15 ;
F_28 ( V_72 ) ;
F_70 ( & V_135 -> V_67 ) ;
F_52 ( V_135 ) ;
F_71 ( & V_135 -> V_67 ) ;
if ( V_135 -> V_17 >= 0 ) {
F_72 ( V_135 -> V_17 , V_2 -> V_140 ) ;
V_135 -> V_17 = - V_141 ;
}
F_37 ( & V_135 -> V_15 . free , & V_72 ) ;
F_37 ( & V_135 -> V_15 . V_68 , & V_72 ) ;
F_37 ( & V_135 -> V_15 . V_92 , & V_72 ) ;
F_37 ( & V_135 -> V_15 . V_93 , & V_72 ) ;
F_37 ( & V_135 -> V_15 . V_81 , & V_72 ) ;
V_135 -> V_15 . V_16 = NULL ;
F_51 (desc, &list, node)
F_46 ( V_135 , V_15 , 0 ) ;
F_38 (page, _page, &rchan->desc.pages, node) {
F_40 ( & V_71 -> V_23 ) ;
F_73 ( ( unsigned long ) V_71 ) ;
}
if ( V_138 -> V_142 . V_103 ) {
F_74 ( V_8 -> V_24 -> V_25 , V_138 -> V_143 ,
V_138 -> V_142 . V_103 , V_138 -> V_122 , 0 ) ;
V_138 -> V_142 . V_103 = 0 ;
}
F_75 ( V_8 -> V_24 -> V_25 ) ;
}
static struct V_63 *
F_76 ( struct V_134 * V_8 , T_6 V_144 ,
T_6 V_145 , T_5 V_133 , unsigned long V_65 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
struct V_117 V_118 ;
if ( ! V_133 )
return NULL ;
F_77 ( & V_118 , 1 ) ;
F_78 ( & V_118 , F_79 ( F_80 ( V_145 ) ) , V_133 ,
F_81 ( V_145 ) ) ;
F_62 ( & V_118 ) = V_145 ;
F_63 ( & V_118 ) = V_133 ;
return F_60 ( V_135 , & V_118 , 1 , V_144 ,
V_114 , V_65 , false ) ;
}
static int F_82 ( struct V_134 * V_8 ,
enum V_121 V_122 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
struct V_137 * V_138 = & V_135 -> V_138 ;
T_7 V_120 ;
T_5 V_146 ;
enum V_147 V_148 ;
if ( V_122 == V_105 ) {
V_120 = V_135 -> V_109 . V_149 ;
V_146 = V_135 -> V_109 . V_103 ;
V_148 = V_150 ;
} else {
V_120 = V_135 -> V_113 . V_149 ;
V_146 = V_135 -> V_113 . V_103 ;
V_148 = V_151 ;
}
if ( V_120 == V_138 -> V_142 . V_149 &&
V_146 == V_138 -> V_142 . V_103 &&
V_148 == V_138 -> V_122 )
return 0 ;
if ( V_138 -> V_142 . V_103 )
F_74 ( V_8 -> V_24 -> V_25 , V_138 -> V_143 ,
V_138 -> V_142 . V_103 , V_138 -> V_122 , 0 ) ;
V_138 -> V_142 . V_103 = 0 ;
V_138 -> V_143 = F_83 ( V_8 -> V_24 -> V_25 , V_120 , V_146 ,
V_148 , 0 ) ;
if ( F_84 ( V_8 -> V_24 -> V_25 , V_138 -> V_143 ) ) {
F_85 ( V_8 -> V_24 -> V_25 ,
L_6 , V_135 -> V_26 ,
V_146 , & V_120 ) ;
return - V_62 ;
}
F_13 ( V_8 -> V_24 -> V_25 , L_7 ,
V_135 -> V_26 , V_146 , & V_120 , & V_138 -> V_143 ,
V_148 == V_150 ? L_8 : L_9 ) ;
V_138 -> V_142 . V_149 = V_120 ;
V_138 -> V_142 . V_103 = V_146 ;
V_138 -> V_122 = V_148 ;
return 0 ;
}
static struct V_63 *
F_86 ( struct V_134 * V_8 , struct V_117 * V_118 ,
unsigned int V_119 , enum V_121 V_122 ,
unsigned long V_65 , void * V_152 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
if ( V_135 -> V_17 < 0 || ! V_119 ) {
F_19 ( V_8 -> V_24 -> V_25 ,
L_10 ,
V_153 , V_119 , V_135 -> V_17 ) ;
return NULL ;
}
if ( F_82 ( V_8 , V_122 ) )
return NULL ;
return F_60 ( V_135 , V_118 , V_119 , V_135 -> V_138 . V_143 ,
V_122 , V_65 , false ) ;
}
static struct V_63 *
F_87 ( struct V_134 * V_8 , T_6 V_154 ,
T_5 V_155 , T_5 V_156 ,
enum V_121 V_122 , unsigned long V_65 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
struct V_63 * V_15 ;
struct V_117 * V_118 ;
unsigned int V_119 ;
unsigned int V_73 ;
if ( V_135 -> V_17 < 0 || V_155 < V_156 ) {
F_19 ( V_8 -> V_24 -> V_25 ,
L_11 ,
V_153 , V_155 , V_156 , V_135 -> V_17 ) ;
return NULL ;
}
if ( F_82 ( V_8 , V_122 ) )
return NULL ;
V_119 = V_155 / V_156 ;
if ( V_119 > V_157 ) {
F_85 ( V_8 -> V_24 -> V_25 ,
L_12 ,
V_135 -> V_26 , V_119 , V_157 ) ;
return NULL ;
}
V_118 = F_88 ( V_119 , sizeof( * V_118 ) , V_83 ) ;
if ( ! V_118 )
return NULL ;
F_77 ( V_118 , V_119 ) ;
for ( V_73 = 0 ; V_73 < V_119 ; ++ V_73 ) {
T_6 V_109 = V_154 + ( V_156 * V_73 ) ;
F_78 ( & V_118 [ V_73 ] , F_79 ( F_80 ( V_109 ) ) , V_156 ,
F_81 ( V_109 ) ) ;
F_62 ( & V_118 [ V_73 ] ) = V_109 ;
F_63 ( & V_118 [ V_73 ] ) = V_156 ;
}
V_15 = F_60 ( V_135 , V_118 , V_119 , V_135 -> V_138 . V_143 ,
V_122 , V_65 , true ) ;
F_89 ( V_118 ) ;
return V_15 ;
}
static int F_90 ( struct V_134 * V_8 ,
struct V_158 * V_159 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
V_135 -> V_109 . V_149 = V_159 -> V_30 ;
V_135 -> V_113 . V_149 = V_159 -> V_32 ;
V_135 -> V_109 . V_103 = V_159 -> V_160 ;
V_135 -> V_113 . V_103 = V_159 -> V_161 ;
return 0 ;
}
static int F_91 ( struct V_134 * V_8 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
unsigned long V_65 ;
F_23 ( & V_135 -> V_67 , V_65 ) ;
F_52 ( V_135 ) ;
F_26 ( & V_135 -> V_67 , V_65 ) ;
F_53 ( V_135 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_7 * V_8 ,
T_3 V_66 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
struct V_20 * V_16 = NULL ;
struct V_20 * V_21 ;
enum V_162 V_163 ;
unsigned int V_164 = 0 ;
unsigned int V_165 = 0 ;
if ( ! V_15 )
return 0 ;
V_163 = F_93 ( & V_8 -> V_8 , V_66 , NULL ) ;
if ( V_163 == V_166 )
return 0 ;
if ( V_66 != V_15 -> V_47 . V_66 ) {
F_51 (desc, &chan->desc.pending, node) {
if ( V_66 == V_15 -> V_47 . V_66 )
return V_15 -> V_51 ;
}
F_51 (desc, &chan->desc.active, node) {
if ( V_66 == V_15 -> V_47 . V_66 )
return V_15 -> V_51 ;
}
F_94 ( 1 , L_13 ) ;
return 0 ;
}
if ( V_15 -> V_18 . V_19 ) {
V_165 = ( F_7 ( V_8 , V_36 ) &
V_167 ) >> V_168 ;
if ( V_165 == 0 )
V_165 = V_15 -> V_27 ;
V_165 -- ;
F_95 ( V_165 >= V_15 -> V_27 ) ;
} else {
V_16 = V_15 -> V_16 ;
}
F_96 (chunk, &desc->chunks, node) {
if ( V_21 == V_16 || ++ V_165 == V_15 -> V_27 )
break;
V_164 += V_21 -> V_51 ;
}
V_164 += F_7 ( V_8 , V_53 ) << V_15 -> V_54 ;
return V_164 ;
}
static enum V_162 F_97 ( struct V_134 * V_8 ,
T_3 V_66 ,
struct V_169 * V_170 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
enum V_162 V_163 ;
unsigned long V_65 ;
unsigned int V_164 ;
V_163 = F_93 ( V_8 , V_66 , V_170 ) ;
if ( V_163 == V_166 || ! V_170 )
return V_163 ;
F_23 ( & V_135 -> V_67 , V_65 ) ;
V_164 = F_92 ( V_135 , V_66 ) ;
F_26 ( & V_135 -> V_67 , V_65 ) ;
if ( ! V_164 )
return V_166 ;
F_98 ( V_170 , V_164 ) ;
return V_163 ;
}
static void F_99 ( struct V_134 * V_8 )
{
struct V_7 * V_135 = F_21 ( V_8 ) ;
unsigned long V_65 ;
F_23 ( & V_135 -> V_67 , V_65 ) ;
if ( F_41 ( & V_135 -> V_15 . V_68 ) )
goto V_93;
F_34 ( & V_135 -> V_15 . V_68 , & V_135 -> V_15 . V_92 ) ;
if ( ! V_135 -> V_15 . V_16 ) {
struct V_14 * V_15 ;
V_15 = F_12 ( & V_135 -> V_15 . V_92 ,
struct V_14 , V_23 ) ;
V_135 -> V_15 . V_16 = V_15 ;
F_10 ( V_135 ) ;
}
V_93:
F_26 ( & V_135 -> V_67 , V_65 ) ;
}
static T_8 F_100 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
unsigned int V_171 ;
if ( F_95 ( ! V_15 || ! V_15 -> V_44 ) ) {
return V_172 ;
}
V_171 = ( F_7 ( V_8 , V_36 ) &
V_167 ) >> V_168 ;
F_8 ( V_8 , V_39 , F_16 ( V_171 ) ) ;
return V_173 ;
}
static T_8 F_101 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
T_8 V_82 = V_173 ;
if ( F_11 ( ! V_15 ) ) {
return V_172 ;
}
if ( ! V_15 -> V_18 . V_19 ) {
if ( ! F_102 ( & V_15 -> V_16 -> V_23 , & V_15 -> V_22 ) ) {
V_15 -> V_16 = F_103 ( V_15 -> V_16 , V_23 ) ;
if ( ! V_15 -> V_44 )
V_82 = V_174 ;
goto V_93;
}
if ( V_15 -> V_44 ) {
V_15 -> V_16 =
F_12 ( & V_15 -> V_22 ,
struct V_20 ,
V_23 ) ;
goto V_93;
}
}
F_104 ( & V_15 -> V_23 , & V_8 -> V_15 . V_93 ) ;
if ( ! F_41 ( & V_8 -> V_15 . V_92 ) )
V_8 -> V_15 . V_16 = F_12 ( & V_8 -> V_15 . V_92 ,
struct V_14 ,
V_23 ) ;
else
V_8 -> V_15 . V_16 = NULL ;
V_93:
if ( V_8 -> V_15 . V_16 )
F_10 ( V_8 ) ;
return V_82 ;
}
static T_8 F_105 ( int V_175 , void * V_25 )
{
T_1 V_176 = V_91 | V_13 ;
struct V_7 * V_8 = V_25 ;
T_8 V_82 = V_172 ;
T_1 V_10 ;
F_56 ( & V_8 -> V_67 ) ;
V_10 = F_7 ( V_8 , V_11 ) ;
if ( V_10 & V_13 )
V_176 |= V_12 ;
F_8 ( V_8 , V_11 , V_10 & ~ V_176 ) ;
if ( V_10 & V_91 )
V_82 |= F_100 ( V_8 ) ;
if ( V_10 & V_13 )
V_82 |= F_101 ( V_8 ) ;
F_57 ( & V_8 -> V_67 ) ;
return V_82 ;
}
static T_8 F_106 ( int V_175 , void * V_25 )
{
struct V_7 * V_8 = V_25 ;
struct V_14 * V_15 ;
struct V_177 V_178 ;
F_70 ( & V_8 -> V_67 ) ;
if ( V_8 -> V_15 . V_16 && V_8 -> V_15 . V_16 -> V_44 ) {
V_15 = V_8 -> V_15 . V_16 ;
F_107 ( & V_15 -> V_47 , & V_178 ) ;
if ( F_108 ( & V_178 ) ) {
F_71 ( & V_8 -> V_67 ) ;
F_109 ( & V_178 , NULL ) ;
F_70 ( & V_8 -> V_67 ) ;
}
}
while ( ! F_41 ( & V_8 -> V_15 . V_93 ) ) {
V_15 = F_12 ( & V_8 -> V_15 . V_93 , struct V_14 ,
V_23 ) ;
F_110 ( & V_15 -> V_47 ) ;
F_40 ( & V_15 -> V_23 ) ;
F_107 ( & V_15 -> V_47 , & V_178 ) ;
if ( F_108 ( & V_178 ) ) {
F_71 ( & V_8 -> V_67 ) ;
F_109 ( & V_178 , NULL ) ;
F_70 ( & V_8 -> V_67 ) ;
}
F_25 ( & V_15 -> V_23 , & V_8 -> V_15 . V_81 ) ;
}
F_71 ( & V_8 -> V_67 ) ;
F_36 ( V_8 ) ;
return V_174 ;
}
static T_8 F_111 ( int V_175 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
if ( ! ( F_4 ( V_2 , V_5 ) & V_61 ) )
return V_172 ;
F_54 ( V_2 ) ;
F_55 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_174 ;
}
static bool F_112 ( struct V_134 * V_8 , void * V_179 )
{
struct V_1 * V_2 = F_69 ( V_8 -> V_24 ) ;
struct V_180 * V_181 = V_179 ;
if ( V_8 -> V_24 -> V_182 != F_90 ||
V_181 -> V_183 != V_8 -> V_24 -> V_25 -> V_184 )
return false ;
return ! F_113 ( V_181 -> args [ 0 ] , V_2 -> V_140 ) ;
}
static struct V_134 * F_114 ( struct V_180 * V_181 ,
struct V_185 * V_186 )
{
struct V_7 * V_135 ;
struct V_134 * V_8 ;
T_9 V_176 ;
if ( V_181 -> V_187 != 1 )
return NULL ;
F_115 ( V_176 ) ;
F_116 ( V_188 , V_176 ) ;
V_8 = F_117 ( V_176 , F_112 , V_181 ) ;
if ( ! V_8 )
return NULL ;
V_135 = F_21 ( V_8 ) ;
V_135 -> V_17 = V_181 -> args [ 0 ] ;
return V_8 ;
}
static int F_118 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_119 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_120 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_121 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = F_122 ( V_25 ) ;
return F_17 ( V_2 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_7 * V_135 ,
unsigned int V_26 )
{
struct V_189 * V_190 = F_124 ( V_2 -> V_25 ) ;
struct V_134 * V_8 = & V_135 -> V_8 ;
char V_191 [ 5 ] ;
char * V_192 ;
int V_175 ;
int V_82 ;
V_135 -> V_26 = V_26 ;
V_135 -> V_6 = V_2 -> V_6 + F_125 ( V_26 ) ;
V_135 -> V_17 = - V_141 ;
F_126 ( & V_135 -> V_67 ) ;
F_31 ( & V_135 -> V_15 . free ) ;
F_31 ( & V_135 -> V_15 . V_68 ) ;
F_31 ( & V_135 -> V_15 . V_92 ) ;
F_31 ( & V_135 -> V_15 . V_93 ) ;
F_31 ( & V_135 -> V_15 . V_81 ) ;
sprintf ( V_191 , L_14 , V_26 ) ;
V_175 = F_127 ( V_190 , V_191 ) ;
if ( V_175 < 0 ) {
F_85 ( V_2 -> V_25 , L_15 , V_26 ) ;
return - V_193 ;
}
V_192 = F_128 ( V_2 -> V_25 , V_136 , L_16 ,
F_129 ( V_2 -> V_25 ) , V_26 ) ;
if ( ! V_192 )
return - V_74 ;
V_82 = F_130 ( V_2 -> V_25 , V_175 , F_105 ,
F_106 , 0 ,
V_192 , V_135 ) ;
if ( V_82 ) {
F_85 ( V_2 -> V_25 , L_17 , V_175 , V_82 ) ;
return V_82 ;
}
V_8 -> V_24 = & V_2 -> V_194 ;
F_131 ( V_8 ) ;
F_25 ( & V_8 -> V_195 , & V_2 -> V_194 . V_94 ) ;
return 0 ;
}
static int F_132 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
struct V_195 * V_183 = V_25 -> V_184 ;
int V_82 ;
V_82 = F_133 ( V_183 , L_18 , & V_2 -> V_58 ) ;
if ( V_82 < 0 ) {
F_85 ( V_25 , L_19 ) ;
return V_82 ;
}
if ( V_2 -> V_58 <= 0 || V_2 -> V_58 >= 100 ) {
F_85 ( V_25 , L_20 ,
V_2 -> V_58 ) ;
return - V_141 ;
}
return 0 ;
}
static int F_134 ( struct V_189 * V_190 )
{
const enum V_196 V_197 = V_198 |
V_199 | V_200 |
V_201 | V_202 |
V_203 | V_204 ;
unsigned int V_205 = 0 ;
struct V_206 * V_194 ;
struct V_1 * V_2 ;
struct V_207 * V_85 ;
unsigned int V_73 ;
char * V_192 ;
int V_175 ;
int V_82 ;
V_2 = F_135 ( & V_190 -> V_25 , sizeof( * V_2 ) , V_136 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_25 = & V_190 -> V_25 ;
F_136 ( V_190 , V_2 ) ;
F_137 ( V_2 -> V_25 , F_138 ( 40 ) ) ;
V_82 = F_132 ( & V_190 -> V_25 , V_2 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_190 -> V_25 . V_208 ) {
V_2 -> V_58 -- ;
V_205 = 1 ;
}
V_2 -> V_94 = F_139 ( & V_190 -> V_25 , V_2 -> V_58 ,
sizeof( * V_2 -> V_94 ) , V_136 ) ;
if ( ! V_2 -> V_94 )
return - V_74 ;
V_85 = F_140 ( V_190 , V_209 , 0 ) ;
V_2 -> V_6 = F_141 ( & V_190 -> V_25 , V_85 ) ;
if ( F_142 ( V_2 -> V_6 ) )
return F_143 ( V_2 -> V_6 ) ;
V_175 = F_127 ( V_190 , L_21 ) ;
if ( V_175 < 0 ) {
F_85 ( & V_190 -> V_25 , L_22 ) ;
return - V_193 ;
}
V_192 = F_128 ( V_2 -> V_25 , V_136 , L_23 ,
F_129 ( V_2 -> V_25 ) ) ;
if ( ! V_192 )
return - V_74 ;
V_82 = F_144 ( & V_190 -> V_25 , V_175 , F_111 , 0 ,
V_192 , V_2 ) ;
if ( V_82 ) {
F_85 ( & V_190 -> V_25 , L_17 ,
V_175 , V_82 ) ;
return V_82 ;
}
F_145 ( & V_190 -> V_25 ) ;
V_82 = F_67 ( & V_190 -> V_25 ) ;
if ( V_82 < 0 ) {
F_85 ( & V_190 -> V_25 , L_24 , V_82 ) ;
return V_82 ;
}
V_82 = F_17 ( V_2 ) ;
F_75 ( & V_190 -> V_25 ) ;
if ( V_82 ) {
F_85 ( & V_190 -> V_25 , L_25 ) ;
goto error;
}
F_31 ( & V_2 -> V_194 . V_94 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_58 ; ++ V_73 ) {
V_82 = F_123 ( V_2 , & V_2 -> V_94 [ V_73 ] ,
V_73 + V_205 ) ;
if ( V_82 < 0 )
goto error;
}
V_82 = F_146 ( V_190 -> V_25 . V_184 , F_114 ,
NULL ) ;
if ( V_82 < 0 )
goto error;
V_194 = & V_2 -> V_194 ;
F_116 ( V_210 , V_194 -> V_211 ) ;
F_116 ( V_188 , V_194 -> V_211 ) ;
V_194 -> V_25 = & V_190 -> V_25 ;
V_194 -> V_212 = F_59 ( V_116 ) ;
V_194 -> V_213 = V_197 ;
V_194 -> V_214 = V_197 ;
V_194 -> V_215 = F_147 ( V_110 ) | F_147 ( V_105 ) ;
V_194 -> V_216 = V_217 ;
V_194 -> V_218 = F_66 ;
V_194 -> V_219 = F_68 ;
V_194 -> V_220 = F_76 ;
V_194 -> V_221 = F_86 ;
V_194 -> V_222 = F_87 ;
V_194 -> V_182 = F_90 ;
V_194 -> V_223 = F_91 ;
V_194 -> V_224 = F_97 ;
V_194 -> V_225 = F_99 ;
V_82 = F_148 ( V_194 ) ;
if ( V_82 < 0 )
goto error;
return 0 ;
error:
F_149 ( V_190 -> V_25 . V_184 ) ;
F_150 ( & V_190 -> V_25 ) ;
return V_82 ;
}
static int F_151 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_152 ( V_190 ) ;
F_149 ( V_190 -> V_25 . V_184 ) ;
F_153 ( & V_2 -> V_194 ) ;
F_150 ( & V_190 -> V_25 ) ;
return 0 ;
}
static void F_154 ( struct V_189 * V_190 )
{
struct V_1 * V_2 = F_152 ( V_190 ) ;
F_54 ( V_2 ) ;
}
