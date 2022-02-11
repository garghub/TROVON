static inline int F_1 ( int V_1 )
{
return V_1 / V_2 ;
}
static inline int F_2 ( int V_1 )
{
return V_1 % V_2 ;
}
static void F_3 ( struct V_3 * V_4 ,
int V_5 , unsigned long V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_7 * V_10 = V_4 -> V_11 ;
struct V_7 * V_12 = V_4 -> V_13 ;
unsigned int V_14 , V_15 , V_16 ;
unsigned long V_17 = F_4 ( V_5 ) ;
if ( V_8 ) {
F_5 ( V_8 , & V_14 ) ;
V_14 &= ~ V_17 ;
if ( V_6 & V_18 )
V_14 |= V_17 ;
F_6 ( V_8 , V_14 ) ;
}
if ( V_10 ) {
F_5 ( V_10 , & V_15 ) ;
V_15 &= ~ V_17 ;
if ( V_6 & V_19 )
V_15 |= V_17 ;
F_6 ( V_10 , V_15 ) ;
}
if ( V_12 ) {
F_5 ( V_12 , & V_16 ) ;
V_16 &= ~ V_17 ;
if ( V_6 & V_20 )
V_16 |= V_17 ;
F_6 ( V_12 , V_16 ) ;
}
}
static void F_7 ( struct V_3 * V_4 ,
int V_21 , int V_22 )
{
struct V_7 * V_23 = V_4 -> V_23 ;
unsigned int V_24 ;
int V_5 = F_2 ( V_21 ) ;
int V_25 = V_5 * 4 ;
if ( ! V_23 )
return;
F_5 ( V_23 , & V_24 ) ;
V_24 &= ~ ( 0xf << V_25 ) ;
V_24 |= V_22 << V_25 ;
F_6 ( V_23 , V_24 ) ;
}
static unsigned long F_8 ( unsigned int V_26 ,
const struct V_27 * V_28 , unsigned long V_6 )
{
const unsigned int * V_29 ;
int V_30 , V_31 , V_32 = - 1 ;
unsigned int V_33 = V_34 ;
if ( F_9 ( V_6 ) ) {
V_29 = V_28 -> V_35 ;
V_30 = V_28 -> V_36 ;
} else {
V_29 = V_28 -> V_37 ;
V_30 = V_28 -> V_38 ;
}
for ( V_31 = 0 ; V_31 < V_30 ; V_31 ++ ) {
unsigned int V_39 = abs ( V_26 - V_29 [ V_31 ] ) ;
if ( V_39 == 0 )
return V_31 ;
if ( V_39 < V_33 ) {
V_33 = V_39 ;
V_32 = V_31 ;
}
}
F_10 ( L_1 ,
V_26 , V_29 [ V_32 ] ) ;
return V_32 ;
}
static unsigned long F_11 ( unsigned int V_40 ,
const struct V_27 * V_28 , unsigned long V_41 )
{
const unsigned int * V_29 ;
int V_30 ;
if ( V_41 ) {
V_29 = V_28 -> V_35 ;
V_30 = V_28 -> V_36 ;
} else {
V_29 = V_28 -> V_37 ;
V_30 = V_28 -> V_38 ;
}
if ( V_40 < V_30 ) {
return V_29 [ V_40 ] ;
} else {
F_10 ( L_2 ) ;
return 0 ;
}
}
static void F_12 ( struct V_7 * V_42 ,
int V_43 , int V_5 )
{
unsigned int V_24 = 0 ;
F_5 ( V_42 , & V_24 ) ;
if ( V_43 )
V_24 |= F_4 ( V_5 ) ;
else
V_24 &= ~ F_4 ( V_5 ) ;
F_6 ( V_42 , V_24 ) ;
}
static void F_13 ( struct V_44 * V_45 ,
struct V_3 * V_4 , unsigned long V_6 , int V_5 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
struct V_46 * V_47 = & V_4 -> V_48 . V_47 ;
unsigned int V_26 ;
F_12 ( V_47 -> V_49 ,
F_14 ( V_6 ) , V_5 ) ;
F_12 ( V_47 -> V_50 ,
F_15 ( V_6 ) , V_5 ) ;
F_12 ( V_47 -> V_51 ,
F_16 ( V_6 ) , V_5 ) ;
F_12 ( V_47 -> V_52 ,
F_17 ( V_6 ) , V_5 ) ;
F_12 ( V_47 -> V_53 ,
F_18 ( V_6 ) , V_5 ) ;
V_26 = F_8 ( F_19 ( V_6 ) ,
V_28 , V_6 ) ;
F_12 ( V_47 -> V_54 , V_26 & 0x1 , V_5 ) ;
F_12 ( V_47 -> V_55 , V_26 & 0x2 , V_5 ) ;
}
static void F_20 ( struct V_44 * V_45 ,
struct V_3 * V_4 , unsigned long V_6 , int V_5 )
{
int V_56 = F_9 ( V_6 ) ? 0 : 1 ;
int V_57 = F_14 ( V_6 ) ;
int V_50 = F_15 ( V_6 ) ;
int V_51 = F_16 ( V_6 ) ;
int V_52 = F_17 ( V_6 ) ;
int V_53 = F_18 ( V_6 ) ;
unsigned long V_26 = F_8 (
F_19 ( V_6 ) ,
V_45 -> V_28 , V_6 ) ;
struct V_58 * V_59 = & V_4 -> V_48 . V_59 ;
unsigned long V_60 =
( ( V_57 ) << V_61 ) |
( ( V_26 ) << V_62 ) |
( ( V_56 ) << V_63 ) |
( ( V_53 ) << V_64 ) |
( ( V_50 ) << V_65 ) |
( ( V_52 ) << V_66 ) |
( ( V_51 ) << V_67 ) ;
F_6 ( V_59 -> V_48 [ V_5 ] , V_60 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
int V_5 , unsigned long * V_6 )
{
unsigned int V_14 , V_15 , V_16 ;
if ( V_4 -> V_9 ) {
F_5 ( V_4 -> V_9 , & V_14 ) ;
if ( V_14 & F_4 ( V_5 ) )
F_22 ( * V_6 ) ;
}
if ( V_4 -> V_11 ) {
F_5 ( V_4 -> V_11 , & V_15 ) ;
if ( V_15 & F_4 ( V_5 ) )
F_23 ( * V_6 ) ;
}
if ( V_4 -> V_13 ) {
F_5 ( V_4 -> V_13 , & V_16 ) ;
if ( V_16 & F_4 ( V_5 ) )
F_24 ( * V_6 ) ;
}
}
static int F_25 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long * V_6 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
struct V_46 * V_47 = & V_4 -> V_48 . V_47 ;
unsigned int V_68 , V_26 , V_69 , V_70 , V_24 ;
int V_41 = F_9 ( * V_6 ) ;
if ( ! F_5 ( V_47 -> V_53 , & V_24 ) && ( V_24 & F_4 ( V_5 ) ) )
F_26 ( * V_6 ) ;
if ( ! F_5 ( V_47 -> V_49 , & V_24 ) && ( V_24 & F_4 ( V_5 ) ) )
F_27 ( * V_6 , 1 ) ;
if ( ! F_5 ( V_47 -> V_50 , & V_24 ) && ( V_24 & F_4 ( V_5 ) ) )
F_28 ( * V_6 ) ;
if ( ! F_5 ( V_47 -> V_51 , & V_24 ) && ( V_24 & F_4 ( V_5 ) ) )
F_29 ( * V_6 ) ;
if ( ! F_5 ( V_47 -> V_52 , & V_24 ) && ( V_24 & F_4 ( V_5 ) ) )
F_30 ( * V_6 ) ;
F_5 ( V_47 -> V_54 , & V_69 ) ;
F_5 ( V_47 -> V_55 , & V_70 ) ;
V_68 = ( ( ( V_70 & F_4 ( V_5 ) ) ? 1 : 0 ) << 1 ) |
( ( ( V_69 & F_4 ( V_5 ) ) ? 1 : 0 ) ) ;
V_26 = F_11 ( V_68 , V_28 , V_41 ) ;
F_31 ( * V_6 , V_26 ) ;
return 0 ;
}
static int F_32 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long * V_6 )
{
unsigned int V_71 ;
unsigned long V_68 , V_26 , V_72 ;
int V_41 = F_9 ( * V_6 ) ;
struct V_58 * V_59 = & V_4 -> V_48 . V_59 ;
F_5 ( V_59 -> V_48 [ V_5 ] , & V_71 ) ;
V_72 = ( V_71 & V_73 ) >> V_61 ;
F_27 ( * V_6 , V_72 ) ;
V_68 = ( V_71 & V_74 ) >> V_62 ;
V_26 = F_11 ( V_68 , V_45 -> V_28 , V_41 ) ;
F_31 ( * V_6 , V_26 ) ;
if ( V_71 & V_75 )
F_28 ( * V_6 ) ;
if ( V_71 & V_76 )
F_29 ( * V_6 ) ;
if ( V_71 & V_77 )
F_30 ( * V_6 ) ;
if ( V_71 & V_78 )
F_26 ( * V_6 ) ;
return 0 ;
}
static inline void F_33 ( struct F_1 * V_79 ,
unsigned V_25 , int V_71 )
{
if ( V_71 )
F_34 ( F_4 ( V_25 ) , V_79 -> V_80 + V_81 ) ;
else
F_34 ( F_4 ( V_25 ) , V_79 -> V_80 + V_82 ) ;
}
static void F_35 ( struct F_1 * V_79 ,
unsigned int V_1 , unsigned int V_83 )
{
int V_25 = F_2 ( V_1 ) ;
int V_31 = 0 ;
for ( V_31 = 0 ; V_31 <= 2 ; V_31 ++ ) {
if ( V_83 & F_4 ( V_31 ) )
F_34 ( F_4 ( V_25 ) , V_79 -> V_80 + F_36 ( V_31 ) ) ;
else
F_34 ( F_4 ( V_25 ) , V_79 -> V_80 + F_37 ( V_31 ) ) ;
}
}
static int F_38 ( struct V_84 * V_85 , unsigned V_25 )
{
return F_39 ( V_85 -> V_80 + V_25 ) ;
}
static void F_40 ( struct V_84 * V_85 , unsigned V_25 )
{
F_41 ( V_85 -> V_80 + V_25 ) ;
}
static int F_42 ( struct V_84 * V_85 , unsigned V_25 )
{
struct F_1 * V_79 = F_43 ( V_85 ) ;
return ! ! ( F_44 ( V_79 -> V_80 + V_86 ) & F_4 ( V_25 ) ) ;
}
static void F_45 ( struct V_84 * V_85 , unsigned V_25 , int V_71 )
{
struct F_1 * V_79 = F_43 ( V_85 ) ;
F_33 ( V_79 , V_25 , V_71 ) ;
}
static int F_46 ( struct V_84 * V_85 , unsigned V_25 )
{
F_47 ( V_85 -> V_80 + V_25 ) ;
return 0 ;
}
static int F_48 ( struct V_84 * V_85 ,
unsigned V_25 , int V_71 )
{
struct F_1 * V_79 = F_43 ( V_85 ) ;
F_33 ( V_79 , V_25 , V_71 ) ;
F_49 ( V_85 -> V_80 + V_25 ) ;
return 0 ;
}
static int F_50 ( struct V_84 * V_87 ,
const struct V_88 * V_89 , T_1 * V_90 )
{
if ( F_51 ( V_87 -> V_91 < 1 ) )
return - V_92 ;
if ( F_51 ( V_89 -> V_93 < V_87 -> V_91 ) )
return - V_92 ;
if ( V_89 -> args [ 0 ] > V_87 -> V_94 )
return - V_92 ;
return V_89 -> args [ 0 ] ;
}
static int F_52 ( struct V_95 * V_96 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
return V_45 -> V_97 ;
}
static const char * F_54 ( struct V_95 * V_96 ,
unsigned V_98 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
return V_45 -> V_99 [ V_98 ] . V_100 ;
}
static int F_55 ( struct V_95 * V_96 ,
unsigned V_98 , const unsigned * * V_101 , unsigned * V_102 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
if ( V_98 >= V_45 -> V_97 )
return - V_92 ;
* V_101 = V_45 -> V_99 [ V_98 ] . V_101 ;
* V_102 = V_45 -> V_99 [ V_98 ] . V_102 ;
return 0 ;
}
static const inline struct V_103 * F_56 (
const struct V_44 * V_45 , const char * V_100 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_45 -> V_97 ; V_31 ++ ) {
if ( ! strcmp ( V_45 -> V_99 [ V_31 ] . V_100 , V_100 ) )
return & V_45 -> V_99 [ V_31 ] ;
}
return NULL ;
}
static int F_57 ( struct V_95 * V_96 ,
struct V_104 * V_105 , struct V_106 * * V_107 , unsigned * V_108 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
const struct V_103 * V_109 ;
struct V_106 * V_110 ;
struct V_104 * V_111 ;
int V_112 , V_31 ;
V_109 = F_56 ( V_45 , V_105 -> V_100 ) ;
if ( ! V_109 ) {
F_58 ( V_45 -> V_113 , L_3 ,
V_105 -> V_100 ) ;
return - V_92 ;
}
V_112 = V_109 -> V_102 + 1 ;
V_110 = F_59 ( V_96 -> V_113 ,
sizeof( * V_110 ) * V_112 , V_114 ) ;
if ( ! V_110 )
return - V_115 ;
V_111 = F_60 ( V_105 ) ;
if ( ! V_111 ) {
F_61 ( V_96 -> V_113 , V_110 ) ;
return - V_92 ;
}
* V_107 = V_110 ;
* V_108 = V_112 ;
V_110 [ 0 ] . type = V_116 ;
V_110 [ 0 ] . V_28 . V_117 . V_22 = V_111 -> V_100 ;
V_110 [ 0 ] . V_28 . V_117 . V_118 = V_105 -> V_100 ;
F_62 ( V_111 ) ;
V_110 ++ ;
for ( V_31 = 0 ; V_31 < V_109 -> V_102 ; V_31 ++ ) {
V_110 [ V_31 ] . type = V_119 ;
V_110 [ V_31 ] . V_28 . V_120 . V_121 =
F_63 ( V_96 , V_109 -> V_101 [ V_31 ] ) ;
V_110 [ V_31 ] . V_28 . V_120 . V_120 = & V_109 -> V_122 [ V_31 ] . V_6 ;
V_110 [ V_31 ] . V_28 . V_120 . V_123 = 1 ;
}
F_64 ( V_96 -> V_113 , L_4 ,
( * V_107 ) -> V_28 . V_117 . V_22 , V_109 -> V_100 , V_112 ) ;
return 0 ;
}
static void F_65 ( struct V_95 * V_96 ,
struct V_106 * V_107 , unsigned V_108 )
{
}
static int F_66 ( struct V_95 * V_96 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
return V_45 -> V_124 ;
}
static const char * F_67 ( struct V_95 * V_96 ,
unsigned V_98 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
return V_45 -> V_125 [ V_98 ] . V_100 ;
}
static int F_68 ( struct V_95 * V_96 ,
unsigned V_98 , const char * const * * V_126 , unsigned * const V_127 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
* V_126 = V_45 -> V_125 [ V_98 ] . V_99 ;
* V_127 = V_45 -> V_125 [ V_98 ] . V_97 ;
return 0 ;
}
static struct V_3 * F_69 (
struct V_95 * V_96 , int V_5 )
{
struct V_128 * V_129 =
F_70 ( V_96 , V_5 ) ;
struct F_1 * V_79 = F_71 ( V_129 ) ;
return & V_79 -> V_4 ;
}
static int F_72 ( struct V_95 * V_96 , unsigned V_130 ,
unsigned V_118 )
{
struct V_44 * V_45 = F_53 ( V_96 ) ;
struct V_131 * V_132 = V_45 -> V_99 [ V_118 ] . V_122 ;
struct V_3 * V_4 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_45 -> V_99 [ V_118 ] . V_102 ; V_31 ++ ) {
V_4 = F_69 ( V_96 , V_132 [ V_31 ] . V_5 ) ;
F_7 ( V_4 , V_132 [ V_31 ] . V_5 , V_132 [ V_31 ] . V_133 ) ;
}
return 0 ;
}
static int F_73 ( struct V_95 * V_96 ,
struct V_128 * V_129 , unsigned V_1 ,
bool V_56 )
{
struct F_1 * V_79 = F_71 ( V_129 ) ;
F_7 ( & V_79 -> V_4 , V_1 , 0 ) ;
F_35 ( V_79 , V_1 , V_56 ?
V_134 : V_135 ) ;
return 0 ;
}
static void F_74 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long * V_6 )
{
if ( V_45 -> V_28 -> V_136 == V_137 )
F_25 ( V_45 , V_4 , V_5 , V_6 ) ;
else if ( V_45 -> V_28 -> V_136 == V_138 )
if ( ( F_4 ( V_5 ) & V_4 -> V_139 ) )
F_32 ( V_45 , V_4 ,
V_5 , V_6 ) ;
}
static void F_75 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long V_6 )
{
if ( V_45 -> V_28 -> V_136 == V_137 )
F_13 ( V_45 , V_4 , V_6 , V_5 ) ;
else if ( V_45 -> V_28 -> V_136 == V_138 )
if ( ( F_4 ( V_5 ) & V_4 -> V_139 ) )
F_20 ( V_45 , V_4 ,
V_6 , V_5 ) ;
}
static int F_76 ( struct V_95 * V_96 , unsigned V_21 ,
unsigned long * V_120 , unsigned V_123 )
{
int V_5 = F_2 ( V_21 ) ;
struct V_44 * V_45 = F_53 ( V_96 ) ;
struct V_3 * V_4 = F_69 ( V_96 , V_21 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_123 ; V_31 ++ ) {
F_3 ( V_4 , V_5 , V_120 [ V_31 ] ) ;
F_75 ( V_45 , V_4 , V_5 , V_120 [ V_31 ] ) ;
}
return 0 ;
}
static int F_77 ( struct V_95 * V_96 ,
unsigned V_21 , unsigned long * V_6 )
{
int V_5 = F_2 ( V_21 ) ;
struct V_44 * V_45 = F_53 ( V_96 ) ;
struct V_3 * V_4 = F_69 ( V_96 , V_21 ) ;
* V_6 = 0 ;
F_21 ( V_4 , V_5 , V_6 ) ;
F_74 ( V_45 , V_4 , V_5 , V_6 ) ;
return 0 ;
}
static void F_78 ( struct V_95 * V_96 ,
struct V_140 * V_141 , unsigned V_21 )
{
unsigned long V_6 ;
F_79 ( & V_96 -> V_142 ) ;
F_77 ( V_96 , V_21 , & V_6 ) ;
F_80 ( & V_96 -> V_142 ) ;
F_81 ( V_141 , L_5
L_6
L_7 ,
F_9 ( V_6 ) ,
F_82 ( V_6 ) ,
F_83 ( V_6 ) ,
F_18 ( V_6 ) ,
F_17 ( V_6 ) ,
F_15 ( V_6 ) ,
F_16 ( V_6 ) ,
F_14 ( V_6 ) ,
F_19 ( V_6 ) ) ;
}
static void F_84 ( struct V_44 * V_45 ,
struct V_104 * V_105 )
{
struct V_104 * V_143 ;
F_85 (np, child) {
if ( F_86 ( V_143 , L_8 ) ) {
V_45 -> V_144 ++ ;
} else {
V_45 -> V_124 ++ ;
V_45 -> V_97 += F_87 ( V_143 ) ;
}
}
}
static int F_88 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
struct V_145 * V_113 = V_45 -> V_113 ;
struct V_146 * V_147 = V_45 -> V_146 ;
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_148 = ( V_28 -> V_48 + V_79 * V_149 ) * 4 ;
struct V_46 * V_47 = & V_4 -> V_48 . V_47 ;
struct V_150 V_49 = F_89 ( V_148 ) ;
struct V_150 V_54 = F_90 ( V_148 ) ;
struct V_150 V_55 = F_91 ( V_148 ) ;
struct V_150 V_52 = F_92 ( V_148 + 4 ) ;
struct V_150 V_53 = F_93 ( V_148 + 4 ) ;
struct V_150 V_50 = F_94 ( V_148 + 4 ) ;
struct V_150 V_51 = F_95 ( V_148 + 4 ) ;
V_47 -> V_49 = F_96 ( V_113 , V_147 , V_49 ) ;
V_47 -> V_54 = F_96 ( V_113 , V_147 , V_54 ) ;
V_47 -> V_55 = F_96 ( V_113 , V_147 , V_55 ) ;
V_47 -> V_52 = F_96 ( V_113 , V_147 , V_52 ) ;
V_47 -> V_53 = F_96 ( V_113 , V_147 , V_53 ) ;
V_47 -> V_50 = F_96 ( V_113 , V_147 , V_50 ) ;
V_47 -> V_51 = F_96 ( V_113 , V_147 , V_51 ) ;
if ( F_97 ( V_47 -> V_49 ) || F_97 ( V_47 -> V_54 ) ||
F_97 ( V_47 -> V_55 ) || F_97 ( V_47 -> V_52 ) ||
F_97 ( V_47 -> V_53 ) || F_97 ( V_47 -> V_50 ) ||
F_97 ( V_47 -> V_51 ) )
return - V_92 ;
return 0 ;
}
static int F_98 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
struct V_145 * V_113 = V_45 -> V_113 ;
struct V_146 * V_147 = V_45 -> V_146 ;
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_151 = ( V_28 -> V_48 + V_79 * V_152 ) * 4 ;
struct V_58 * V_59 = & V_4 -> V_48 . V_59 ;
unsigned int V_153 ;
T_1 V_154 = V_4 -> V_139 ;
for ( V_153 = 0 ; V_153 < V_152 ; V_153 ++ ) {
if ( F_4 ( V_153 ) & V_154 ) {
struct V_150 V_148 = F_99 ( V_151 , 0 , 31 ) ;
V_59 -> V_48 [ V_153 ] = F_96 ( V_113 , V_147 , V_148 ) ;
if ( F_97 ( V_59 -> V_48 [ V_153 ] ) )
return - V_92 ;
V_151 += 4 ;
}
}
return 0 ;
}
static int F_100 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
if ( V_28 -> V_136 == V_137 )
return F_88 ( V_45 , V_79 , V_4 ) ;
else if ( V_28 -> V_136 == V_138 )
return F_98 ( V_45 , V_79 , V_4 ) ;
return - V_92 ;
}
static struct V_7 * F_101 ( struct V_145 * V_113 ,
struct V_146 * V_146 , int V_79 ,
int V_28 , int V_155 , int V_156 )
{
struct V_150 V_148 = F_99 ( ( V_28 + V_79 ) * 4 , V_155 , V_156 ) ;
if ( V_28 < 0 )
return NULL ;
return F_96 ( V_113 , V_146 , V_148 ) ;
}
static void F_102 ( struct V_44 * V_45 , int V_79 ,
struct V_104 * V_105 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_155 = ( V_79 % 4 ) * V_2 ;
int V_156 = V_155 + V_2 - 1 ;
struct V_3 * V_4 = & V_45 -> V_157 [ V_79 ] . V_4 ;
struct V_145 * V_113 = V_45 -> V_113 ;
struct V_146 * V_146 = V_45 -> V_146 ;
V_4 -> V_23 = F_101 ( V_113 , V_146 , V_79 , V_28 -> V_23 , 0 , 31 ) ;
V_4 -> V_9 = F_101 ( V_113 , V_146 , V_79 / 4 , V_28 -> V_9 , V_155 , V_156 ) ;
V_4 -> V_11 = F_101 ( V_113 , V_146 , V_79 / 4 , V_28 -> V_11 , V_155 , V_156 ) ;
V_4 -> V_13 = F_101 ( V_113 , V_146 , V_79 / 4 , V_28 -> V_13 , V_155 , V_156 ) ;
V_4 -> V_139 = 0xff ;
F_103 ( V_105 , L_9 , & V_4 -> V_139 ) ;
F_100 ( V_45 , V_79 , V_4 ) ;
return;
}
static int F_104 ( struct V_104 * V_105 ,
struct V_103 * V_109 , struct V_44 * V_45 , int V_158 )
{
const T_2 * V_159 ;
struct V_160 * V_161 ;
struct V_131 * V_132 ;
struct V_104 * V_101 ;
int V_31 = 0 , V_102 = 0 , V_162 ;
V_101 = F_105 ( V_105 , L_10 ) ;
if ( ! V_101 )
return - V_163 ;
F_106 (pins, pp) {
if ( ! strcmp ( V_161 -> V_100 , L_11 ) )
continue;
if ( V_161 && ( V_161 -> V_164 / sizeof( T_2 ) ) >= V_165 ) {
V_102 ++ ;
} else {
F_10 ( L_12 , V_105 -> V_100 ) ;
return - V_92 ;
}
}
V_109 -> V_102 = V_102 ;
V_109 -> V_100 = V_105 -> V_100 ;
V_109 -> V_101 = F_59 ( V_45 -> V_113 , V_102 * sizeof( T_1 ) , V_114 ) ;
V_109 -> V_122 = F_59 ( V_45 -> V_113 ,
V_102 * sizeof( * V_132 ) , V_114 ) ;
if ( ! V_109 -> V_101 || ! V_109 -> V_122 )
return - V_115 ;
F_106 (pins, pp) {
if ( ! strcmp ( V_161 -> V_100 , L_11 ) )
continue;
V_162 = V_161 -> V_164 / sizeof( T_1 ) ;
V_159 = V_161 -> V_71 ;
V_132 = & V_109 -> V_122 [ V_31 ] ;
F_107 ( V_159 ++ ) ;
F_107 ( V_159 ++ ) ;
V_132 -> V_5 = F_108 ( V_101 , V_161 -> V_100 , 0 ) ;
V_132 -> V_100 = V_161 -> V_100 ;
V_109 -> V_101 [ V_31 ] = V_132 -> V_5 ;
V_132 -> V_133 = F_107 ( V_159 ++ ) ;
V_132 -> V_6 = 0 ;
V_132 -> V_6 |= F_107 ( V_159 ++ ) ;
if ( V_162 >= V_165 + V_166 ) {
V_132 -> V_6 |= F_107 ( V_159 ++ ) ;
V_132 -> V_6 |= F_107 ( V_159 ++ ) ;
if ( V_162 > V_165 + V_166 )
V_132 -> V_6 |= F_107 ( V_159 ++ ) ;
}
V_31 ++ ;
}
F_62 ( V_101 ) ;
return 0 ;
}
static int F_109 ( struct V_104 * V_105 ,
struct V_44 * V_45 , T_1 V_40 , int * V_167 )
{
struct V_104 * V_143 ;
struct V_168 * V_169 ;
struct V_103 * V_109 ;
int V_170 , V_31 ;
V_169 = & V_45 -> V_125 [ V_40 ] ;
V_169 -> V_100 = V_105 -> V_100 ;
V_169 -> V_97 = F_87 ( V_105 ) ;
if ( V_169 -> V_97 == 0 ) {
F_58 ( V_45 -> V_113 , L_13 ) ;
return - V_92 ;
}
V_169 -> V_99 = F_59 ( V_45 -> V_113 ,
V_169 -> V_97 * sizeof( char * ) , V_114 ) ;
if ( ! V_169 -> V_99 )
return - V_115 ;
V_31 = 0 ;
F_85 (np, child) {
V_169 -> V_99 [ V_31 ] = V_143 -> V_100 ;
V_109 = & V_45 -> V_99 [ * V_167 ] ;
* V_167 += 1 ;
V_170 = F_104 ( V_143 , V_109 , V_45 , V_31 ++ ) ;
if ( V_170 )
return V_170 ;
}
F_64 ( V_45 -> V_113 , L_14 ,
V_40 , V_169 -> V_100 , V_169 -> V_97 ) ;
return 0 ;
}
static void F_110 ( struct V_171 * V_172 )
{
struct V_84 * V_87 = F_111 ( V_172 ) ;
struct F_1 * V_79 = F_43 ( V_87 ) ;
F_34 ( F_4 ( V_172 -> V_173 ) , V_79 -> V_80 + V_174 ) ;
}
static void F_112 ( struct V_171 * V_172 )
{
struct V_84 * V_87 = F_111 ( V_172 ) ;
struct F_1 * V_79 = F_43 ( V_87 ) ;
F_34 ( F_4 ( V_172 -> V_173 ) , V_79 -> V_80 + V_175 ) ;
}
static int F_113 ( struct V_171 * V_172 , unsigned type )
{
struct V_84 * V_87 = F_111 ( V_172 ) ;
struct F_1 * V_79 = F_43 ( V_87 ) ;
unsigned long V_90 ;
int V_176 , V_5 = V_172 -> V_173 ;
T_1 V_24 ;
T_1 V_177 = 0 ;
switch ( type ) {
case V_178 :
V_176 = 0 ;
break;
case V_179 :
V_176 = 0 ;
V_177 = F_114 ( V_5 ) ;
break;
case V_180 :
V_176 = 1 ;
break;
case V_181 :
V_176 = 1 ;
V_177 = F_115 ( V_5 ) ;
break;
case V_182 :
V_176 = F_42 ( & V_79 -> V_84 , V_5 ) ;
V_177 = F_116 ( V_5 ) ;
break;
default:
return - V_92 ;
}
F_117 ( & V_79 -> V_183 , V_90 ) ;
V_79 -> V_184 &= ~ ( V_185 << (
V_5 * V_186 ) ) ;
V_79 -> V_184 |= V_177 ;
F_118 ( & V_79 -> V_183 , V_90 ) ;
V_24 = F_44 ( V_79 -> V_80 + V_187 ) ;
V_24 &= ~ F_4 ( V_5 ) ;
V_24 |= ( V_176 << V_5 ) ;
F_34 ( V_24 , V_79 -> V_80 + V_187 ) ;
return 0 ;
}
static void F_119 ( struct F_1 * V_79 )
{
unsigned long V_188 , V_189 , V_190 , V_191 ;
unsigned long V_192 , V_90 ;
int V_193 , V_24 , V_194 ;
F_117 ( & V_79 -> V_183 , V_90 ) ;
V_192 = V_79 -> V_184 ;
F_118 ( & V_79 -> V_183 , V_90 ) ;
for (; ; ) {
V_188 = F_44 ( V_79 -> V_80 + V_86 ) ;
V_190 = F_44 ( V_79 -> V_80 + V_187 ) ;
V_189 = F_44 ( V_79 -> V_80 + V_195 ) ;
V_191 = ( V_188 ^ V_190 ) & V_189 ;
if ( V_191 == 0 )
break;
F_120 (n, &active_irqs, BITS_PER_LONG) {
V_194 = F_121 ( V_192 , V_193 ) ;
if ( V_194 ) {
V_24 = F_42 ( & V_79 -> V_84 , V_193 ) ;
F_34 ( F_4 ( V_193 ) ,
V_24 ? V_79 -> V_80 + V_196 :
V_79 -> V_80 + V_197 ) ;
if ( V_194 != V_198 &&
! ( ( V_194 & V_199 ) ^ V_24 ) )
continue;
}
F_122 ( F_123 ( V_79 -> V_84 . V_200 , V_193 ) ) ;
}
}
}
static void F_124 ( unsigned V_201 , struct V_202 * V_203 )
{
struct V_204 * V_85 = F_125 ( V_201 ) ;
struct V_84 * V_87 = F_126 ( V_203 ) ;
struct F_1 * V_79 = F_43 ( V_87 ) ;
F_127 ( V_85 , V_203 ) ;
F_119 ( V_79 ) ;
F_128 ( V_85 , V_203 ) ;
}
static void F_129 ( unsigned V_201 , struct V_202 * V_203 )
{
struct V_204 * V_85 = F_125 ( V_201 ) ;
struct V_44 * V_45 = F_130 ( V_201 ) ;
unsigned long V_205 ;
int V_193 ;
F_127 ( V_85 , V_203 ) ;
V_205 = F_44 ( V_45 -> V_206 ) ;
F_120 (n, &status, info->nbanks)
F_119 ( & V_45 -> V_157 [ V_193 ] ) ;
F_128 ( V_85 , V_203 ) ;
}
static int F_131 ( struct V_44 * V_45 ,
int V_207 , struct V_104 * V_105 )
{
struct F_1 * V_79 = & V_45 -> V_157 [ V_207 ] ;
struct V_128 * V_129 = & V_79 -> V_129 ;
struct V_145 * V_113 = V_45 -> V_113 ;
int V_208 = F_132 ( V_105 , L_15 ) ;
struct V_209 V_210 , V_211 ;
int V_212 = 0 , V_213 ;
if ( F_133 ( V_105 , 0 , & V_210 ) )
return - V_214 ;
V_79 -> V_80 = F_134 ( V_113 , & V_210 ) ;
if ( F_97 ( V_79 -> V_80 ) )
return F_135 ( V_79 -> V_80 ) ;
V_79 -> V_84 = V_215 ;
V_79 -> V_84 . V_80 = V_208 * V_2 ;
V_79 -> V_84 . V_94 = V_2 ;
V_79 -> V_84 . V_216 = V_105 ;
V_79 -> V_84 . V_113 = V_113 ;
F_136 ( & V_79 -> V_183 ) ;
F_137 ( V_105 , L_16 , & V_129 -> V_100 ) ;
V_79 -> V_84 . V_217 = V_129 -> V_100 ;
V_129 -> V_218 = V_208 ;
V_129 -> V_219 = V_129 -> V_80 = V_129 -> V_218 * V_2 ;
V_129 -> V_102 = V_79 -> V_84 . V_94 ;
V_129 -> V_87 = & V_79 -> V_84 ;
V_213 = F_138 ( & V_79 -> V_84 ) ;
if ( V_213 ) {
F_58 ( V_113 , L_17 , V_208 ) ;
return V_213 ;
}
F_64 ( V_113 , L_18 , V_129 -> V_100 ) ;
if ( F_139 ( V_105 , 0 , & V_211 ) ) {
V_212 = V_211 . V_220 ;
F_140 ( & V_79 -> V_84 , & V_221 ,
V_212 , F_124 ) ;
}
if ( V_45 -> V_206 || V_212 > 0 ) {
V_213 = F_141 ( & V_79 -> V_84 , & V_221 ,
0 , V_222 ,
V_180 ) ;
if ( V_213 ) {
F_142 ( & V_79 -> V_84 ) ;
F_64 ( V_113 , L_19 ) ;
return V_213 ;
}
} else {
F_64 ( V_113 , L_20 , V_105 -> V_223 ) ;
}
return 0 ;
}
static int F_143 ( struct V_224 * V_225 ,
struct V_226 * V_227 , struct V_44 * V_45 )
{
int V_170 = 0 ;
int V_31 = 0 , V_153 = 0 , V_228 = 0 , V_79 ;
struct V_229 * V_230 ;
struct V_104 * V_105 = V_225 -> V_113 . V_216 ;
struct V_104 * V_143 ;
int V_167 = 0 ;
int V_201 = 0 ;
struct V_209 * V_210 ;
F_84 ( V_45 , V_105 ) ;
if ( ! V_45 -> V_144 ) {
F_58 ( & V_225 -> V_113 , L_21 ) ;
return - V_92 ;
}
F_64 ( & V_225 -> V_113 , L_22 , V_45 -> V_144 ) ;
F_64 ( & V_225 -> V_113 , L_23 , V_45 -> V_124 ) ;
F_64 ( & V_225 -> V_113 , L_24 , V_45 -> V_97 ) ;
V_45 -> V_125 = F_59 ( & V_225 -> V_113 ,
V_45 -> V_124 * sizeof( * V_45 -> V_125 ) , V_114 ) ;
V_45 -> V_99 = F_59 ( & V_225 -> V_113 ,
V_45 -> V_97 * sizeof( * V_45 -> V_99 ) , V_114 ) ;
V_45 -> V_157 = F_59 ( & V_225 -> V_113 ,
V_45 -> V_144 * sizeof( * V_45 -> V_157 ) , V_114 ) ;
if ( ! V_45 -> V_125 || ! V_45 -> V_99 || ! V_45 -> V_157 )
return - V_115 ;
V_45 -> V_146 = F_144 ( V_105 , L_25 ) ;
if ( F_97 ( V_45 -> V_146 ) ) {
F_58 ( V_45 -> V_113 , L_26 ) ;
return F_135 ( V_45 -> V_146 ) ;
}
V_45 -> V_28 = F_145 ( V_231 , V_105 ) -> V_28 ;
V_201 = F_146 ( V_225 , 0 ) ;
if ( V_201 > 0 ) {
V_210 = F_147 ( V_225 ,
V_232 , L_27 ) ;
V_45 -> V_206 = F_134 ( & V_225 -> V_113 , V_210 ) ;
if ( F_97 ( V_45 -> V_206 ) )
return F_135 ( V_45 -> V_206 ) ;
F_148 ( V_201 , F_129 ) ;
F_149 ( V_201 , V_45 ) ;
}
V_227 -> V_102 = V_45 -> V_144 * V_2 ;
V_230 = F_59 ( & V_225 -> V_113 ,
sizeof( * V_230 ) * V_227 -> V_102 , V_114 ) ;
if ( ! V_230 )
return - V_115 ;
V_227 -> V_101 = V_230 ;
V_79 = 0 ;
F_85 (np, child) {
if ( F_86 ( V_143 , L_8 ) ) {
const char * V_233 = NULL ;
V_170 = F_131 ( V_45 , V_79 , V_143 ) ;
if ( V_170 )
return V_170 ;
V_228 = V_45 -> V_157 [ V_79 ] . V_129 . V_219 ;
V_233 = V_45 -> V_157 [ V_79 ] . V_129 . V_100 ;
for ( V_153 = 0 ; V_153 < V_2 ; V_153 ++ , V_228 ++ ) {
V_230 -> V_234 = V_228 ;
V_230 -> V_100 = F_150 ( V_114 , L_28 ,
V_233 , V_153 ) ;
V_230 ++ ;
}
F_102 ( V_45 , V_79 , V_143 ) ;
V_79 ++ ;
} else {
V_170 = F_109 ( V_143 , V_45 ,
V_31 ++ , & V_167 ) ;
if ( V_170 ) {
F_58 ( & V_225 -> V_113 , L_29 ) ;
return V_170 ;
}
}
}
return 0 ;
}
static int F_151 ( struct V_224 * V_225 )
{
struct V_44 * V_45 ;
struct V_226 * V_227 ;
int V_170 , V_31 ;
if ( ! V_225 -> V_113 . V_216 ) {
F_58 ( & V_225 -> V_113 , L_30 ) ;
return - V_92 ;
}
V_227 = F_59 ( & V_225 -> V_113 , sizeof( * V_227 ) , V_114 ) ;
if ( ! V_227 )
return - V_115 ;
V_45 = F_59 ( & V_225 -> V_113 , sizeof( * V_45 ) , V_114 ) ;
if ( ! V_45 )
return - V_115 ;
V_45 -> V_113 = & V_225 -> V_113 ;
F_152 ( V_225 , V_45 ) ;
V_170 = F_143 ( V_225 , V_227 , V_45 ) ;
if ( V_170 )
return V_170 ;
V_227 -> V_235 = V_236 ;
V_227 -> V_237 = & V_238 ;
V_227 -> V_239 = & V_240 ;
V_227 -> V_241 = & V_242 ;
V_227 -> V_100 = F_153 ( & V_225 -> V_113 ) ;
V_45 -> V_243 = F_154 ( V_227 , & V_225 -> V_113 , V_45 ) ;
if ( ! V_45 -> V_243 ) {
F_58 ( & V_225 -> V_113 , L_31 ) ;
return - V_92 ;
}
for ( V_31 = 0 ; V_31 < V_45 -> V_144 ; V_31 ++ )
F_155 ( V_45 -> V_243 , & V_45 -> V_157 [ V_31 ] . V_129 ) ;
return 0 ;
}
static int T_3 F_156 ( void )
{
return F_157 ( & V_244 ) ;
}
