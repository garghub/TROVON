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
return ( V_10 & ( V_12 | V_13 ) ) == V_12 ;
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
F_1 ( V_2 , V_57 , 0x7fff ) ;
F_1 ( V_2 , V_5 ,
V_58 | V_59 ) ;
V_56 = F_4 ( V_2 , V_5 ) ;
if ( ( V_56 & ( V_60 | V_59 ) ) != V_59 ) {
F_18 ( V_2 -> V_23 , L_3 ) ;
return - V_61 ;
}
return 0 ;
}
static T_3 F_19 ( struct V_62 * V_63 )
{
struct V_7 * V_8 = F_20 ( V_63 -> V_8 ) ;
struct V_14 * V_15 = F_21 ( V_63 ) ;
unsigned long V_64 ;
T_3 V_65 ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
V_65 = F_23 ( V_63 ) ;
F_12 ( V_8 -> V_8 . V_22 -> V_23 , L_4 ,
V_8 -> V_24 , V_63 -> V_65 , V_15 ) ;
F_24 ( & V_15 -> V_33 , & V_8 -> V_15 . V_67 ) ;
V_15 -> V_16 = F_15 ( & V_15 -> V_32 ,
struct V_20 , V_33 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
return V_65 ;
}
static int F_26 ( struct V_7 * V_8 , T_4 V_68 )
{
struct V_69 * V_70 ;
unsigned long V_64 ;
F_27 ( V_71 ) ;
unsigned int V_72 ;
V_70 = ( void * ) F_28 ( V_68 ) ;
if ( ! V_70 )
return - V_73 ;
for ( V_72 = 0 ; V_72 < V_74 ; ++ V_72 ) {
struct V_14 * V_15 = & V_70 -> V_75 [ V_72 ] ;
F_29 ( & V_15 -> V_44 , & V_8 -> V_8 ) ;
V_15 -> V_44 . V_76 = F_19 ;
F_30 ( & V_15 -> V_32 ) ;
F_24 ( & V_15 -> V_33 , & V_71 ) ;
}
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_31 ( & V_71 , & V_8 -> V_15 . free ) ;
F_24 ( & V_70 -> V_33 , & V_8 -> V_15 . V_77 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
return 0 ;
}
static void F_32 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
unsigned long V_64 ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_33 ( & V_15 -> V_32 , & V_8 -> V_15 . V_78 ) ;
F_24 ( & V_15 -> V_33 , & V_8 -> V_15 . free ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
struct V_14 * V_15 , * V_79 ;
unsigned long V_64 ;
F_27 ( V_71 ) ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_35 ( & V_8 -> V_15 . V_80 , & V_71 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
F_36 (desc, _desc, &list, node) {
if ( F_37 ( & V_15 -> V_44 ) ) {
F_38 ( & V_15 -> V_33 ) ;
F_32 ( V_8 , V_15 ) ;
}
}
if ( F_39 ( & V_71 ) )
return;
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_40 ( & V_71 , & V_8 -> V_15 . V_80 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
}
static struct V_14 * F_41 ( struct V_7 * V_8 )
{
struct V_14 * V_15 ;
unsigned long V_64 ;
int V_81 ;
F_34 ( V_8 ) ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
while ( F_39 ( & V_8 -> V_15 . free ) ) {
F_25 ( & V_8 -> V_66 , V_64 ) ;
V_81 = F_26 ( V_8 , V_82 ) ;
if ( V_81 < 0 )
return NULL ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
}
V_15 = F_15 ( & V_8 -> V_15 . free , struct V_14 , V_33 ) ;
F_38 ( & V_15 -> V_33 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
return V_15 ;
}
static int F_42 ( struct V_7 * V_8 , T_4 V_68 )
{
struct V_69 * V_70 ;
unsigned long V_64 ;
F_27 ( V_71 ) ;
unsigned int V_72 ;
V_70 = ( void * ) F_28 ( V_68 ) ;
if ( ! V_70 )
return - V_73 ;
for ( V_72 = 0 ; V_72 < V_83 ; ++ V_72 ) {
struct V_20 * V_21 = & V_70 -> V_32 [ V_72 ] ;
F_24 ( & V_21 -> V_33 , & V_71 ) ;
}
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_31 ( & V_71 , & V_8 -> V_15 . V_78 ) ;
F_24 ( & V_70 -> V_33 , & V_8 -> V_15 . V_77 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
return 0 ;
}
static struct V_20 *
F_43 ( struct V_7 * V_8 )
{
struct V_20 * V_21 ;
unsigned long V_64 ;
int V_81 ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
while ( F_39 ( & V_8 -> V_15 . V_78 ) ) {
F_25 ( & V_8 -> V_66 , V_64 ) ;
V_81 = F_42 ( V_8 , V_82 ) ;
if ( V_81 < 0 )
return NULL ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
}
V_21 = F_15 ( & V_8 -> V_15 . V_78 ,
struct V_20 , V_33 ) ;
F_38 ( & V_21 -> V_33 ) ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
return V_21 ;
}
static void F_44 ( struct V_7 * V_8 ,
struct V_14 * V_15 , T_5 V_48 )
{
V_48 = F_45 ( V_48 ) ;
if ( V_15 -> V_18 . V_48 == V_48 )
return;
if ( V_15 -> V_18 . V_84 ) {
F_46 ( V_8 -> V_8 . V_22 -> V_23 , V_15 -> V_18 . V_48 ,
V_15 -> V_18 . V_84 , V_15 -> V_18 . V_26 ) ;
V_15 -> V_18 . V_84 = NULL ;
V_15 -> V_18 . V_48 = 0 ;
}
if ( ! V_48 )
return;
V_15 -> V_18 . V_84 = F_47 ( V_8 -> V_8 . V_22 -> V_23 , V_48 ,
& V_15 -> V_18 . V_26 , V_82 ) ;
if ( ! V_15 -> V_18 . V_84 )
return;
V_15 -> V_18 . V_48 = V_48 ;
}
static int F_48 ( struct V_7 * V_8 ,
struct V_14 * V_15 )
{
struct V_20 * V_21 ;
struct V_85 * V_86 ;
F_44 ( V_8 , V_15 , V_15 -> V_25 * sizeof( * V_86 ) ) ;
V_86 = V_15 -> V_18 . V_84 ;
if ( ! V_86 )
return - V_73 ;
F_49 (chunk, &desc->chunks, node) {
V_86 -> V_87 = V_21 -> V_49 ;
V_86 -> V_88 = V_21 -> V_35 ;
V_86 -> V_89 = V_21 -> V_48 >> V_15 -> V_54 ;
V_86 ++ ;
}
return 0 ;
}
static void F_50 ( struct V_7 * V_8 )
{
T_1 V_10 = F_7 ( V_8 , V_11 ) ;
V_10 &= ~ ( V_90 | V_47 | V_43 |
V_13 | V_12 ) ;
F_8 ( V_8 , V_11 , V_10 ) ;
}
static void F_51 ( struct V_7 * V_8 )
{
struct V_14 * V_15 , * V_79 ;
unsigned long V_64 ;
F_27 ( V_75 ) ;
F_22 ( & V_8 -> V_66 , V_64 ) ;
F_35 ( & V_8 -> V_15 . V_67 , & V_75 ) ;
F_35 ( & V_8 -> V_15 . V_91 , & V_75 ) ;
F_35 ( & V_8 -> V_15 . V_92 , & V_75 ) ;
F_35 ( & V_8 -> V_15 . V_80 , & V_75 ) ;
V_8 -> V_15 . V_16 = NULL ;
F_25 ( & V_8 -> V_66 , V_64 ) ;
F_36 (desc, _desc, &descs, node) {
F_38 ( & V_15 -> V_33 ) ;
F_32 ( V_8 , V_15 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_5 , 0 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < V_2 -> V_93 ; ++ V_72 ) {
struct V_7 * V_8 = & V_2 -> V_94 [ V_72 ] ;
F_54 ( & V_8 -> V_66 ) ;
F_50 ( V_8 ) ;
F_55 ( & V_8 -> V_66 ) ;
F_51 ( V_8 ) ;
}
}
static void F_56 ( struct V_7 * V_8 ,
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
V_103 = V_8 -> V_109 ;
break;
case V_110 :
V_10 = V_111 | V_112
| V_108 ;
V_103 = V_8 -> V_113 ;
break;
case V_114 :
default:
V_10 = V_106 | V_112
| V_115 ;
V_103 = V_116 ;
break;
}
V_15 -> V_54 = F_57 ( V_103 ) ;
V_15 -> V_10 = V_10 | V_95 [ V_15 -> V_54 ] ;
}
static struct V_62 *
F_58 ( struct V_7 * V_8 , struct V_117 * V_118 ,
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
unsigned int V_72 ;
V_15 = F_41 ( V_8 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_44 . V_64 = V_123 ;
V_15 -> V_44 . V_65 = - V_128 ;
V_15 -> V_41 = V_41 ;
V_15 -> V_104 = V_122 ;
F_56 ( V_8 , V_15 ) ;
V_125 = ( V_129 + 1 ) << V_15 -> V_54 ;
F_59 (sgl, sg, sg_len, i) {
T_6 V_130 = F_60 ( V_124 ) ;
unsigned int V_131 = F_61 ( V_124 ) ;
V_126 += V_131 ;
while ( V_131 ) {
unsigned int V_48 = F_62 ( V_131 , V_125 ) ;
#ifdef F_13
if ( V_120 >> 32 != ( V_120 + V_48 - 1 ) >> 32 )
V_48 = F_63 ( V_120 , 1ULL << 32 ) - V_120 ;
if ( V_130 >> 32 != ( V_130 + V_48 - 1 ) >> 32 )
V_48 = F_63 ( V_130 , 1ULL << 32 ) - V_130 ;
if ( V_120 >> 32 || V_130 >> 32 )
V_127 = true ;
#endif
V_21 = F_43 ( V_8 ) ;
if ( ! V_21 ) {
F_32 ( V_8 , V_15 ) ;
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
V_8 -> V_24 , V_21 , V_15 , V_72 , V_124 , V_48 , V_131 ,
& V_21 -> V_49 , & V_21 -> V_35 ) ;
V_130 += V_48 ;
if ( V_122 == V_114 )
V_120 += V_48 ;
V_131 -= V_48 ;
F_24 ( & V_21 -> V_33 , & V_15 -> V_32 ) ;
V_25 ++ ;
}
}
V_15 -> V_25 = V_25 ;
V_15 -> V_48 = V_126 ;
V_15 -> V_18 . V_19 = ! V_127 && V_25 > 1 ;
if ( V_15 -> V_18 . V_19 ) {
if ( F_48 ( V_8 , V_15 ) < 0 )
V_15 -> V_18 . V_19 = false ;
}
return & V_15 -> V_44 ;
}
static int F_64 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
int V_81 ;
F_30 ( & V_133 -> V_15 . V_78 ) ;
F_30 ( & V_133 -> V_15 . V_77 ) ;
V_81 = F_42 ( V_133 , V_134 ) ;
if ( V_81 < 0 )
return - V_73 ;
V_81 = F_26 ( V_133 , V_134 ) ;
if ( V_81 < 0 )
return - V_73 ;
return F_65 ( V_8 -> V_22 -> V_23 ) ;
}
static void F_66 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_67 ( V_8 -> V_22 ) ;
struct V_69 * V_70 , * V_135 ;
struct V_14 * V_15 ;
F_27 ( V_71 ) ;
F_68 ( & V_133 -> V_66 ) ;
F_50 ( V_133 ) ;
F_69 ( & V_133 -> V_66 ) ;
if ( V_133 -> V_17 >= 0 ) {
F_70 ( V_133 -> V_17 , V_2 -> V_136 ) ;
V_133 -> V_17 = - V_137 ;
}
F_35 ( & V_133 -> V_15 . free , & V_71 ) ;
F_35 ( & V_133 -> V_15 . V_67 , & V_71 ) ;
F_35 ( & V_133 -> V_15 . V_91 , & V_71 ) ;
F_35 ( & V_133 -> V_15 . V_92 , & V_71 ) ;
F_35 ( & V_133 -> V_15 . V_80 , & V_71 ) ;
F_49 (desc, &list, node)
F_44 ( V_133 , V_15 , 0 ) ;
F_36 (page, _page, &rchan->desc.pages, node) {
F_38 ( & V_70 -> V_33 ) ;
F_71 ( ( unsigned long ) V_70 ) ;
}
F_72 ( V_8 -> V_22 -> V_23 ) ;
}
static struct V_62 *
F_73 ( struct V_132 * V_8 , T_6 V_138 ,
T_6 V_139 , T_5 V_131 , unsigned long V_64 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
struct V_117 V_118 ;
if ( ! V_131 )
return NULL ;
F_74 ( & V_118 , 1 ) ;
F_75 ( & V_118 , F_76 ( F_77 ( V_139 ) ) , V_131 ,
F_78 ( V_139 ) ) ;
F_60 ( & V_118 ) = V_139 ;
F_61 ( & V_118 ) = V_131 ;
return F_58 ( V_133 , & V_118 , 1 , V_138 ,
V_114 , V_64 , false ) ;
}
static struct V_62 *
F_79 ( struct V_132 * V_8 , struct V_117 * V_118 ,
unsigned int V_119 , enum V_121 V_122 ,
unsigned long V_64 , void * V_140 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
T_6 V_120 ;
if ( V_133 -> V_17 < 0 || ! V_119 ) {
F_18 ( V_8 -> V_22 -> V_23 ,
L_6 ,
V_141 , V_119 , V_133 -> V_17 ) ;
return NULL ;
}
V_120 = V_122 == V_105
? V_133 -> V_142 : V_133 -> V_143 ;
return F_58 ( V_133 , V_118 , V_119 , V_120 ,
V_122 , V_64 , false ) ;
}
static struct V_62 *
F_80 ( struct V_132 * V_8 , T_6 V_144 ,
T_5 V_145 , T_5 V_146 ,
enum V_121 V_122 , unsigned long V_64 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
struct V_62 * V_15 ;
struct V_117 * V_118 ;
T_6 V_120 ;
unsigned int V_119 ;
unsigned int V_72 ;
if ( V_133 -> V_17 < 0 || V_145 < V_146 ) {
F_18 ( V_8 -> V_22 -> V_23 ,
L_7 ,
V_141 , V_145 , V_146 , V_133 -> V_17 ) ;
return NULL ;
}
V_119 = V_145 / V_146 ;
if ( V_119 > V_147 ) {
F_81 ( V_8 -> V_22 -> V_23 ,
L_8 ,
V_133 -> V_24 , V_119 , V_147 ) ;
return NULL ;
}
V_118 = F_82 ( V_119 , sizeof( * V_118 ) , V_82 ) ;
if ( ! V_118 )
return NULL ;
F_74 ( V_118 , V_119 ) ;
for ( V_72 = 0 ; V_72 < V_119 ; ++ V_72 ) {
T_6 V_148 = V_144 + ( V_146 * V_72 ) ;
F_75 ( & V_118 [ V_72 ] , F_76 ( F_77 ( V_148 ) ) , V_146 ,
F_78 ( V_148 ) ) ;
F_60 ( & V_118 [ V_72 ] ) = V_148 ;
F_61 ( & V_118 [ V_72 ] ) = V_146 ;
}
V_120 = V_122 == V_105
? V_133 -> V_142 : V_133 -> V_143 ;
V_15 = F_58 ( V_133 , V_118 , V_119 , V_120 ,
V_122 , V_64 , true ) ;
F_83 ( V_118 ) ;
return V_15 ;
}
static int F_84 ( struct V_132 * V_8 ,
struct V_149 * V_150 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
V_133 -> V_142 = V_150 -> V_49 ;
V_133 -> V_143 = V_150 -> V_35 ;
V_133 -> V_109 = V_150 -> V_151 ;
V_133 -> V_113 = V_150 -> V_152 ;
return 0 ;
}
static int F_85 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
unsigned long V_64 ;
F_22 ( & V_133 -> V_66 , V_64 ) ;
F_50 ( V_133 ) ;
F_25 ( & V_133 -> V_66 , V_64 ) ;
F_51 ( V_133 ) ;
return 0 ;
}
static unsigned int F_86 ( struct V_7 * V_8 ,
T_3 V_65 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
struct V_20 * V_16 = NULL ;
struct V_20 * V_21 ;
unsigned int V_153 = 0 ;
unsigned int V_154 = 0 ;
if ( ! V_15 )
return 0 ;
if ( V_65 != V_15 -> V_44 . V_65 )
return V_15 -> V_48 ;
if ( V_15 -> V_18 . V_19 ) {
V_154 = ( F_7 ( V_8 , V_30 ) &
V_155 ) >> V_156 ;
F_87 ( V_154 >= V_15 -> V_25 ) ;
} else {
V_16 = V_15 -> V_16 ;
}
F_88 (chunk, &desc->chunks, node) {
if ( V_21 == V_16 || ++ V_154 == V_15 -> V_25 )
break;
V_153 += V_21 -> V_48 ;
}
V_153 += F_7 ( V_8 , V_53 ) << V_15 -> V_54 ;
return V_153 ;
}
static enum V_157 F_89 ( struct V_132 * V_8 ,
T_3 V_65 ,
struct V_158 * V_159 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
enum V_157 V_160 ;
unsigned long V_64 ;
unsigned int V_153 ;
V_160 = F_90 ( V_8 , V_65 , V_159 ) ;
if ( V_160 == V_161 || ! V_159 )
return V_160 ;
F_22 ( & V_133 -> V_66 , V_64 ) ;
V_153 = F_86 ( V_133 , V_65 ) ;
F_25 ( & V_133 -> V_66 , V_64 ) ;
F_91 ( V_159 , V_153 ) ;
return V_160 ;
}
static void F_92 ( struct V_132 * V_8 )
{
struct V_7 * V_133 = F_20 ( V_8 ) ;
unsigned long V_64 ;
F_22 ( & V_133 -> V_66 , V_64 ) ;
if ( F_39 ( & V_133 -> V_15 . V_67 ) )
goto V_92;
F_33 ( & V_133 -> V_15 . V_67 , & V_133 -> V_15 . V_91 ) ;
if ( ! V_133 -> V_15 . V_16 ) {
struct V_14 * V_15 ;
V_15 = F_15 ( & V_133 -> V_15 . V_91 ,
struct V_14 , V_33 ) ;
V_133 -> V_15 . V_16 = V_15 ;
F_10 ( V_133 ) ;
}
V_92:
F_25 ( & V_133 -> V_66 , V_64 ) ;
}
static T_7 F_93 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
unsigned int V_162 ;
if ( F_87 ( ! V_15 || ! V_15 -> V_41 ) ) {
return V_163 ;
}
V_162 = ( F_7 ( V_8 , V_30 ) &
V_155 ) >> V_156 ;
F_8 ( V_8 , V_36 , F_16 ( V_162 ) ) ;
return V_164 ;
}
static T_7 F_94 ( struct V_7 * V_8 )
{
struct V_14 * V_15 = V_8 -> V_15 . V_16 ;
T_7 V_81 = V_164 ;
if ( F_11 ( ! V_15 ) ) {
return V_163 ;
}
if ( ! V_15 -> V_18 . V_19 ) {
if ( ! F_95 ( & V_15 -> V_16 -> V_33 , & V_15 -> V_32 ) ) {
V_15 -> V_16 = F_96 ( V_15 -> V_16 , V_33 ) ;
if ( ! V_15 -> V_41 )
V_81 = V_165 ;
goto V_92;
}
if ( V_15 -> V_41 ) {
V_15 -> V_16 =
F_15 ( & V_15 -> V_32 ,
struct V_20 ,
V_33 ) ;
goto V_92;
}
}
F_97 ( & V_15 -> V_33 , & V_8 -> V_15 . V_92 ) ;
if ( ! F_39 ( & V_8 -> V_15 . V_91 ) )
V_8 -> V_15 . V_16 = F_15 ( & V_8 -> V_15 . V_91 ,
struct V_14 ,
V_33 ) ;
else
V_8 -> V_15 . V_16 = NULL ;
V_92:
if ( V_8 -> V_15 . V_16 )
F_10 ( V_8 ) ;
return V_81 ;
}
static T_7 F_98 ( int V_166 , void * V_23 )
{
T_1 V_167 = V_90 | V_13 ;
struct V_7 * V_8 = V_23 ;
T_7 V_81 = V_163 ;
T_1 V_10 ;
F_54 ( & V_8 -> V_66 ) ;
V_10 = F_7 ( V_8 , V_11 ) ;
if ( V_10 & V_13 )
V_167 |= V_12 ;
F_8 ( V_8 , V_11 , V_10 & ~ V_167 ) ;
if ( V_10 & V_90 )
V_81 |= F_93 ( V_8 ) ;
if ( V_10 & V_13 )
V_81 |= F_94 ( V_8 ) ;
F_55 ( & V_8 -> V_66 ) ;
return V_81 ;
}
static T_7 F_99 ( int V_166 , void * V_23 )
{
struct V_7 * V_8 = V_23 ;
struct V_14 * V_15 ;
F_68 ( & V_8 -> V_66 ) ;
if ( V_8 -> V_15 . V_16 && V_8 -> V_15 . V_16 -> V_41 ) {
T_8 V_45 ;
void * V_168 ;
V_15 = V_8 -> V_15 . V_16 ;
V_45 = V_15 -> V_44 . V_45 ;
V_168 = V_15 -> V_44 . V_168 ;
if ( V_45 ) {
F_69 ( & V_8 -> V_66 ) ;
V_45 ( V_168 ) ;
F_68 ( & V_8 -> V_66 ) ;
}
}
while ( ! F_39 ( & V_8 -> V_15 . V_92 ) ) {
V_15 = F_15 ( & V_8 -> V_15 . V_92 , struct V_14 ,
V_33 ) ;
F_100 ( & V_15 -> V_44 ) ;
F_38 ( & V_15 -> V_33 ) ;
if ( V_15 -> V_44 . V_45 ) {
F_69 ( & V_8 -> V_66 ) ;
V_15 -> V_44 . V_45 ( V_15 -> V_44 . V_168 ) ;
F_68 ( & V_8 -> V_66 ) ;
}
F_24 ( & V_15 -> V_33 , & V_8 -> V_15 . V_80 ) ;
}
F_69 ( & V_8 -> V_66 ) ;
F_34 ( V_8 ) ;
return V_165 ;
}
static T_7 F_101 ( int V_166 , void * V_4 )
{
struct V_1 * V_2 = V_4 ;
if ( ! ( F_4 ( V_2 , V_5 ) & V_60 ) )
return V_163 ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
F_17 ( V_2 ) ;
return V_165 ;
}
static bool F_102 ( struct V_132 * V_8 , void * V_169 )
{
struct V_1 * V_2 = F_67 ( V_8 -> V_22 ) ;
struct V_170 * V_171 = V_169 ;
if ( V_8 -> V_22 -> V_172 != F_84 ||
V_171 -> V_173 != V_8 -> V_22 -> V_23 -> V_174 )
return false ;
return ! F_103 ( V_171 -> args [ 0 ] , V_2 -> V_136 ) ;
}
static struct V_132 * F_104 ( struct V_170 * V_171 ,
struct V_175 * V_176 )
{
struct V_7 * V_133 ;
struct V_132 * V_8 ;
T_9 V_167 ;
if ( V_171 -> V_177 != 1 )
return NULL ;
F_105 ( V_167 ) ;
F_106 ( V_178 , V_167 ) ;
V_8 = F_107 ( V_167 , F_102 , V_171 ) ;
if ( ! V_8 )
return NULL ;
V_133 = F_20 ( V_8 ) ;
V_133 -> V_17 = V_171 -> args [ 0 ] ;
return V_8 ;
}
static int F_108 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_109 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_110 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_111 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_112 ( V_23 ) ;
return F_17 ( V_2 ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_7 * V_133 ,
unsigned int V_24 )
{
struct V_179 * V_180 = F_114 ( V_2 -> V_23 ) ;
struct V_132 * V_8 = & V_133 -> V_8 ;
char V_181 [ 5 ] ;
char * V_182 ;
int V_166 ;
int V_81 ;
V_133 -> V_24 = V_24 ;
V_133 -> V_6 = V_2 -> V_6 + F_115 ( V_24 ) ;
V_133 -> V_17 = - V_137 ;
F_116 ( & V_133 -> V_66 ) ;
F_30 ( & V_133 -> V_15 . free ) ;
F_30 ( & V_133 -> V_15 . V_67 ) ;
F_30 ( & V_133 -> V_15 . V_91 ) ;
F_30 ( & V_133 -> V_15 . V_92 ) ;
F_30 ( & V_133 -> V_15 . V_80 ) ;
sprintf ( V_181 , L_9 , V_24 ) ;
V_166 = F_117 ( V_180 , V_181 ) ;
if ( V_166 < 0 ) {
F_81 ( V_2 -> V_23 , L_10 , V_24 ) ;
return - V_183 ;
}
V_182 = F_118 ( V_2 -> V_23 , V_134 , L_11 ,
F_119 ( V_2 -> V_23 ) , V_24 ) ;
if ( ! V_182 )
return - V_73 ;
V_81 = F_120 ( V_2 -> V_23 , V_166 , F_98 ,
F_99 , 0 ,
V_182 , V_133 ) ;
if ( V_81 ) {
F_81 ( V_2 -> V_23 , L_12 , V_166 , V_81 ) ;
return V_81 ;
}
V_8 -> V_22 = & V_2 -> V_184 ;
F_121 ( V_8 ) ;
F_24 ( & V_8 -> V_185 , & V_2 -> V_184 . V_94 ) ;
return 0 ;
}
static int F_122 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
struct V_185 * V_173 = V_23 -> V_174 ;
int V_81 ;
V_81 = F_123 ( V_173 , L_13 , & V_2 -> V_93 ) ;
if ( V_81 < 0 ) {
F_81 ( V_23 , L_14 ) ;
return V_81 ;
}
if ( V_2 -> V_93 <= 0 || V_2 -> V_93 >= 100 ) {
F_81 ( V_23 , L_15 ,
V_2 -> V_93 ) ;
return - V_137 ;
}
return 0 ;
}
static int F_124 ( struct V_179 * V_180 )
{
const enum V_186 V_187 = V_188 |
V_189 | V_190 |
V_191 | V_192 |
V_193 | V_194 ;
unsigned int V_195 = 0 ;
struct V_196 * V_184 ;
struct V_1 * V_2 ;
struct V_197 * V_84 ;
unsigned int V_72 ;
char * V_182 ;
int V_166 ;
int V_81 ;
V_2 = F_125 ( & V_180 -> V_23 , sizeof( * V_2 ) , V_134 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_23 = & V_180 -> V_23 ;
F_126 ( V_180 , V_2 ) ;
V_81 = F_122 ( & V_180 -> V_23 , V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_180 -> V_23 . V_198 ) {
V_2 -> V_93 -- ;
V_195 = 1 ;
}
V_2 -> V_94 = F_127 ( & V_180 -> V_23 , V_2 -> V_93 ,
sizeof( * V_2 -> V_94 ) , V_134 ) ;
if ( ! V_2 -> V_94 )
return - V_73 ;
V_84 = F_128 ( V_180 , V_199 , 0 ) ;
V_2 -> V_6 = F_129 ( & V_180 -> V_23 , V_84 ) ;
if ( F_130 ( V_2 -> V_6 ) )
return F_131 ( V_2 -> V_6 ) ;
V_166 = F_117 ( V_180 , L_16 ) ;
if ( V_166 < 0 ) {
F_81 ( & V_180 -> V_23 , L_17 ) ;
return - V_183 ;
}
V_182 = F_118 ( V_2 -> V_23 , V_134 , L_18 ,
F_119 ( V_2 -> V_23 ) ) ;
if ( ! V_182 )
return - V_73 ;
V_81 = F_132 ( & V_180 -> V_23 , V_166 , F_101 , 0 ,
V_182 , V_2 ) ;
if ( V_81 ) {
F_81 ( & V_180 -> V_23 , L_12 ,
V_166 , V_81 ) ;
return V_81 ;
}
F_133 ( & V_180 -> V_23 ) ;
V_81 = F_65 ( & V_180 -> V_23 ) ;
if ( V_81 < 0 ) {
F_81 ( & V_180 -> V_23 , L_19 , V_81 ) ;
return V_81 ;
}
V_81 = F_17 ( V_2 ) ;
F_72 ( & V_180 -> V_23 ) ;
if ( V_81 ) {
F_81 ( & V_180 -> V_23 , L_20 ) ;
goto error;
}
F_30 ( & V_2 -> V_184 . V_94 ) ;
for ( V_72 = 0 ; V_72 < V_2 -> V_93 ; ++ V_72 ) {
V_81 = F_113 ( V_2 , & V_2 -> V_94 [ V_72 ] ,
V_72 + V_195 ) ;
if ( V_81 < 0 )
goto error;
}
V_81 = F_134 ( V_180 -> V_23 . V_174 , F_104 ,
NULL ) ;
if ( V_81 < 0 )
goto error;
V_184 = & V_2 -> V_184 ;
F_106 ( V_200 , V_184 -> V_201 ) ;
F_106 ( V_178 , V_184 -> V_201 ) ;
V_184 -> V_23 = & V_180 -> V_23 ;
V_184 -> V_202 = F_57 ( V_116 ) ;
V_184 -> V_203 = V_187 ;
V_184 -> V_204 = V_187 ;
V_184 -> V_205 = F_135 ( V_110 ) | F_135 ( V_105 ) ;
V_184 -> V_206 = V_207 ;
V_184 -> V_208 = F_64 ;
V_184 -> V_209 = F_66 ;
V_184 -> V_210 = F_73 ;
V_184 -> V_211 = F_79 ;
V_184 -> V_212 = F_80 ;
V_184 -> V_172 = F_84 ;
V_184 -> V_213 = F_85 ;
V_184 -> V_214 = F_89 ;
V_184 -> V_215 = F_92 ;
V_81 = F_136 ( V_184 ) ;
if ( V_81 < 0 )
goto error;
return 0 ;
error:
F_137 ( V_180 -> V_23 . V_174 ) ;
F_138 ( & V_180 -> V_23 ) ;
return V_81 ;
}
static int F_139 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_140 ( V_180 ) ;
F_137 ( V_180 -> V_23 . V_174 ) ;
F_141 ( & V_2 -> V_184 ) ;
F_138 ( & V_180 -> V_23 ) ;
return 0 ;
}
static void F_142 ( struct V_179 * V_180 )
{
struct V_1 * V_2 = F_140 ( V_180 ) ;
F_52 ( V_2 ) ;
}
