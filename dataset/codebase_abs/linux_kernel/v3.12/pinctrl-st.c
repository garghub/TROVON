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
F_5 ( V_8 , & V_14 ) ;
F_5 ( V_10 , & V_15 ) ;
F_5 ( V_12 , & V_16 ) ;
V_14 &= ~ V_17 ;
V_15 &= ~ V_17 ;
V_16 &= ~ V_17 ;
if ( V_6 & V_18 )
V_14 |= V_17 ;
if ( V_6 & V_19 )
V_15 |= V_17 ;
if ( V_6 & V_20 )
V_16 |= V_17 ;
F_6 ( V_8 , V_14 ) ;
F_6 ( V_10 , V_15 ) ;
F_6 ( V_12 , V_16 ) ;
}
static void F_7 ( struct V_3 * V_4 ,
int V_21 , int V_22 )
{
struct V_7 * V_23 = V_4 -> V_23 ;
unsigned int V_24 ;
int V_5 = F_2 ( V_21 ) ;
int V_25 = V_5 * 4 ;
F_5 ( V_23 , & V_24 ) ;
V_24 &= ~ ( 0xf << V_25 ) ;
V_24 |= V_22 << V_25 ;
F_6 ( V_23 , V_24 ) ;
}
static unsigned long F_8 ( unsigned int V_26 ,
const struct V_27 * V_28 , unsigned long V_6 )
{
unsigned int * V_29 ;
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
unsigned int * V_29 ;
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
F_5 ( V_4 -> V_9 , & V_14 ) ;
F_5 ( V_4 -> V_11 , & V_15 ) ;
F_5 ( V_4 -> V_13 , & V_16 ) ;
if ( V_14 & F_4 ( V_5 ) )
F_22 ( * V_6 ) ;
if ( V_15 & F_4 ( V_5 ) )
F_23 ( * V_6 ) ;
if ( V_16 & F_4 ( V_5 ) )
F_24 ( * V_6 ) ;
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
static void F_73 ( struct V_95 * V_96 , unsigned V_98 ,
unsigned V_118 )
{
}
static int F_74 ( struct V_95 * V_96 ,
struct V_128 * V_129 , unsigned V_1 ,
bool V_56 )
{
struct F_1 * V_79 = F_71 ( V_129 ) ;
F_7 ( & V_79 -> V_4 , V_1 , 0 ) ;
F_35 ( V_79 , V_1 , V_56 ?
V_134 : V_135 ) ;
return 0 ;
}
static void F_75 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long * V_6 )
{
if ( V_45 -> V_28 -> V_136 == V_137 )
F_25 ( V_45 , V_4 , V_5 , V_6 ) ;
else if ( V_45 -> V_28 -> V_136 == V_138 )
if ( ( F_4 ( V_5 ) & V_4 -> V_139 ) )
F_32 ( V_45 , V_4 ,
V_5 , V_6 ) ;
}
static void F_76 ( struct V_44 * V_45 ,
struct V_3 * V_4 , int V_5 , unsigned long V_6 )
{
if ( V_45 -> V_28 -> V_136 == V_137 )
F_13 ( V_45 , V_4 , V_6 , V_5 ) ;
else if ( V_45 -> V_28 -> V_136 == V_138 )
if ( ( F_4 ( V_5 ) & V_4 -> V_139 ) )
F_20 ( V_45 , V_4 ,
V_6 , V_5 ) ;
}
static int F_77 ( struct V_95 * V_96 , unsigned V_21 ,
unsigned long * V_120 , unsigned V_123 )
{
int V_5 = F_2 ( V_21 ) ;
struct V_44 * V_45 = F_53 ( V_96 ) ;
struct V_3 * V_4 = F_69 ( V_96 , V_21 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_123 ; V_31 ++ ) {
F_3 ( V_4 , V_5 , V_120 [ V_31 ] ) ;
F_76 ( V_45 , V_4 , V_5 , V_120 [ V_31 ] ) ;
}
return 0 ;
}
static int F_78 ( struct V_95 * V_96 ,
unsigned V_21 , unsigned long * V_6 )
{
int V_5 = F_2 ( V_21 ) ;
struct V_44 * V_45 = F_53 ( V_96 ) ;
struct V_3 * V_4 = F_69 ( V_96 , V_21 ) ;
* V_6 = 0 ;
F_21 ( V_4 , V_5 , V_6 ) ;
F_75 ( V_45 , V_4 , V_5 , V_6 ) ;
return 0 ;
}
static void F_79 ( struct V_95 * V_96 ,
struct V_140 * V_141 , unsigned V_21 )
{
unsigned long V_6 ;
F_78 ( V_96 , V_21 , & V_6 ) ;
F_80 ( V_141 , L_5
L_6
L_7 ,
F_9 ( V_6 ) ,
F_81 ( V_6 ) ,
F_82 ( V_6 ) ,
F_18 ( V_6 ) ,
F_17 ( V_6 ) ,
F_15 ( V_6 ) ,
F_16 ( V_6 ) ,
F_14 ( V_6 ) ,
F_19 ( V_6 ) ) ;
}
static void F_83 ( struct V_44 * V_45 ,
struct V_104 * V_105 )
{
struct V_104 * V_142 ;
F_84 (np, child) {
if ( F_85 ( V_142 , L_8 ) ) {
V_45 -> V_143 ++ ;
} else {
V_45 -> V_124 ++ ;
V_45 -> V_97 += F_86 ( V_142 ) ;
}
}
}
static int F_87 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
struct V_144 * V_113 = V_45 -> V_113 ;
struct V_145 * V_146 = V_45 -> V_145 ;
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_147 = ( V_28 -> V_48 + V_79 * V_148 ) * 4 ;
struct V_46 * V_47 = & V_4 -> V_48 . V_47 ;
struct V_149 V_49 = F_88 ( V_147 ) ;
struct V_149 V_54 = F_89 ( V_147 ) ;
struct V_149 V_55 = F_90 ( V_147 ) ;
struct V_149 V_52 = F_91 ( V_147 + 4 ) ;
struct V_149 V_53 = F_92 ( V_147 + 4 ) ;
struct V_149 V_50 = F_93 ( V_147 + 4 ) ;
struct V_149 V_51 = F_94 ( V_147 + 4 ) ;
V_47 -> V_49 = F_95 ( V_113 , V_146 , V_49 ) ;
V_47 -> V_54 = F_95 ( V_113 , V_146 , V_54 ) ;
V_47 -> V_55 = F_95 ( V_113 , V_146 , V_55 ) ;
V_47 -> V_52 = F_95 ( V_113 , V_146 , V_52 ) ;
V_47 -> V_53 = F_95 ( V_113 , V_146 , V_53 ) ;
V_47 -> V_50 = F_95 ( V_113 , V_146 , V_50 ) ;
V_47 -> V_51 = F_95 ( V_113 , V_146 , V_51 ) ;
if ( F_96 ( V_47 -> V_49 ) || F_96 ( V_47 -> V_54 ) ||
F_96 ( V_47 -> V_55 ) || F_96 ( V_47 -> V_52 ) ||
F_96 ( V_47 -> V_53 ) || F_96 ( V_47 -> V_50 ) ||
F_96 ( V_47 -> V_51 ) )
return - V_92 ;
return 0 ;
}
static int F_97 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
struct V_144 * V_113 = V_45 -> V_113 ;
struct V_145 * V_146 = V_45 -> V_145 ;
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_150 = ( V_28 -> V_48 + V_79 * V_151 ) * 4 ;
struct V_58 * V_59 = & V_4 -> V_48 . V_59 ;
unsigned int V_152 ;
T_1 V_153 = V_4 -> V_139 ;
for ( V_152 = 0 ; V_152 < V_151 ; V_152 ++ ) {
if ( F_4 ( V_152 ) & V_153 ) {
struct V_149 V_147 = F_98 ( V_150 , 0 , 31 ) ;
V_59 -> V_48 [ V_152 ] = F_95 ( V_113 , V_146 , V_147 ) ;
if ( F_96 ( V_59 -> V_48 [ V_152 ] ) )
return - V_92 ;
V_150 += 4 ;
}
}
return 0 ;
}
static int F_99 ( struct V_44 * V_45 ,
int V_79 , struct V_3 * V_4 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
if ( V_28 -> V_136 == V_137 )
return F_87 ( V_45 , V_79 , V_4 ) ;
else if ( V_28 -> V_136 == V_138 )
return F_97 ( V_45 , V_79 , V_4 ) ;
return - V_92 ;
}
static int F_100 ( struct V_44 * V_45 ,
int V_79 , struct V_104 * V_105 )
{
const struct V_27 * V_28 = V_45 -> V_28 ;
int V_154 = ( V_79 % 4 ) * V_2 ;
int V_155 = V_154 + V_2 - 1 ;
struct V_149 V_156 = F_98 ( ( V_28 -> V_23 + V_79 ) * 4 , 0 , 31 ) ;
struct V_149 V_157 = F_98 ( ( V_28 -> V_9 + V_79 / 4 ) * 4 , V_154 , V_155 ) ;
struct V_149 V_158 = F_98 ( ( V_28 -> V_11 + V_79 / 4 ) * 4 , V_154 , V_155 ) ;
struct V_149 V_159 = F_98 ( ( V_28 -> V_13 + V_79 / 4 ) * 4 , V_154 , V_155 ) ;
struct V_3 * V_4 = & V_45 -> V_160 [ V_79 ] . V_4 ;
struct V_144 * V_113 = V_45 -> V_113 ;
struct V_145 * V_145 = V_45 -> V_145 ;
V_4 -> V_23 = F_95 ( V_113 , V_145 , V_156 ) ;
V_4 -> V_9 = F_95 ( V_113 , V_145 , V_157 ) ;
V_4 -> V_11 = F_95 ( V_113 , V_145 , V_158 ) ;
V_4 -> V_13 = F_95 ( V_113 , V_145 , V_159 ) ;
if ( F_96 ( V_4 -> V_23 ) || F_96 ( V_4 -> V_9 ) ||
F_96 ( V_4 -> V_11 ) || F_96 ( V_4 -> V_13 ) )
return - V_92 ;
V_4 -> V_139 = 0xff ;
F_101 ( V_105 , L_9 , & V_4 -> V_139 ) ;
F_99 ( V_45 , V_79 , V_4 ) ;
return 0 ;
}
static int F_102 ( struct V_104 * V_105 ,
struct V_103 * V_109 , struct V_44 * V_45 , int V_161 )
{
const T_2 * V_162 ;
struct V_163 * V_164 ;
struct V_131 * V_132 ;
T_3 T_3 ;
struct V_104 * V_101 ;
T_1 V_5 ;
int V_31 = 0 , V_102 = 0 , V_165 ;
V_101 = F_103 ( V_105 , L_10 ) ;
if ( ! V_101 )
return - V_166 ;
F_104 (pins, pp) {
if ( ! strcmp ( V_164 -> V_100 , L_11 ) )
continue;
if ( V_164 && ( V_164 -> V_167 / sizeof( T_2 ) ) >= V_168 ) {
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
F_104 (pins, pp) {
if ( ! strcmp ( V_164 -> V_100 , L_11 ) )
continue;
V_165 = V_164 -> V_167 / sizeof( T_1 ) ;
V_162 = V_164 -> V_71 ;
V_132 = & V_109 -> V_122 [ V_31 ] ;
T_3 = F_105 ( V_162 ++ ) ;
V_5 = F_105 ( V_162 ++ ) ;
V_132 -> V_5 = F_106 ( V_101 , V_164 -> V_100 , 0 ) ;
V_132 -> V_100 = V_164 -> V_100 ;
V_109 -> V_101 [ V_31 ] = V_132 -> V_5 ;
V_132 -> V_133 = F_105 ( V_162 ++ ) ;
V_132 -> V_6 = 0 ;
V_132 -> V_6 |= F_105 ( V_162 ++ ) ;
if ( V_165 >= V_168 + V_169 ) {
V_132 -> V_6 |= F_105 ( V_162 ++ ) ;
V_132 -> V_6 |= F_105 ( V_162 ++ ) ;
if ( V_165 > V_168 + V_169 )
V_132 -> V_6 |= F_105 ( V_162 ++ ) ;
}
V_31 ++ ;
}
F_62 ( V_101 ) ;
return 0 ;
}
static int F_107 ( struct V_104 * V_105 ,
struct V_44 * V_45 , T_1 V_40 , int * V_170 )
{
struct V_104 * V_142 ;
struct V_171 * V_172 ;
struct V_103 * V_109 ;
int V_173 , V_31 ;
V_172 = & V_45 -> V_125 [ V_40 ] ;
V_172 -> V_100 = V_105 -> V_100 ;
V_172 -> V_97 = F_86 ( V_105 ) ;
if ( V_172 -> V_97 <= 0 ) {
F_58 ( V_45 -> V_113 , L_13 ) ;
return - V_92 ;
}
V_172 -> V_99 = F_59 ( V_45 -> V_113 ,
V_172 -> V_97 * sizeof( char * ) , V_114 ) ;
if ( ! V_172 -> V_99 )
return - V_115 ;
V_31 = 0 ;
F_84 (np, child) {
V_172 -> V_99 [ V_31 ] = V_142 -> V_100 ;
V_109 = & V_45 -> V_99 [ * V_170 ] ;
* V_170 += 1 ;
V_173 = F_102 ( V_142 , V_109 , V_45 , V_31 ++ ) ;
if ( V_173 )
return V_173 ;
}
F_64 ( V_45 -> V_113 , L_14 ,
V_40 , V_172 -> V_100 , V_172 -> V_97 ) ;
return 0 ;
}
static int F_108 ( struct V_44 * V_45 ,
int V_174 , struct V_104 * V_105 )
{
struct F_1 * V_79 = & V_45 -> V_160 [ V_174 ] ;
struct V_128 * V_129 = & V_79 -> V_129 ;
struct V_144 * V_113 = V_45 -> V_113 ;
int V_175 = F_109 ( V_105 , L_15 ) ;
struct V_176 V_177 ;
int V_178 ;
if ( F_110 ( V_105 , 0 , & V_177 ) )
return - V_179 ;
V_79 -> V_80 = F_111 ( V_113 , & V_177 ) ;
if ( F_96 ( V_79 -> V_80 ) )
return F_112 ( V_79 -> V_80 ) ;
V_79 -> V_84 = V_180 ;
V_79 -> V_84 . V_80 = V_175 * V_2 ;
V_79 -> V_84 . V_94 = V_2 ;
V_79 -> V_84 . V_181 = V_105 ;
F_113 ( V_105 , L_16 , & V_129 -> V_100 ) ;
V_79 -> V_84 . V_182 = V_129 -> V_100 ;
V_129 -> V_183 = V_175 ;
V_129 -> V_184 = V_129 -> V_80 = V_129 -> V_183 * V_2 ;
V_129 -> V_102 = V_79 -> V_84 . V_94 ;
V_129 -> V_87 = & V_79 -> V_84 ;
V_178 = F_114 ( & V_79 -> V_84 ) ;
if ( V_178 ) {
F_58 ( V_113 , L_17 , V_175 ) ;
return V_178 ;
}
F_64 ( V_113 , L_18 , V_129 -> V_100 ) ;
return 0 ;
}
static int F_115 ( struct V_185 * V_186 ,
struct V_187 * V_188 , struct V_44 * V_45 )
{
int V_173 = 0 ;
int V_31 = 0 , V_152 = 0 , V_189 = 0 , V_79 ;
struct V_190 * V_191 ;
struct V_104 * V_105 = V_186 -> V_113 . V_181 ;
struct V_104 * V_142 ;
int V_170 = 0 ;
F_83 ( V_45 , V_105 ) ;
if ( ! V_45 -> V_143 ) {
F_58 ( & V_186 -> V_113 , L_19 ) ;
return - V_92 ;
}
F_64 ( & V_186 -> V_113 , L_20 , V_45 -> V_143 ) ;
F_64 ( & V_186 -> V_113 , L_21 , V_45 -> V_124 ) ;
F_64 ( & V_186 -> V_113 , L_22 , V_45 -> V_97 ) ;
V_45 -> V_125 = F_59 ( & V_186 -> V_113 ,
V_45 -> V_124 * sizeof( * V_45 -> V_125 ) , V_114 ) ;
V_45 -> V_99 = F_59 ( & V_186 -> V_113 ,
V_45 -> V_97 * sizeof( * V_45 -> V_99 ) , V_114 ) ;
V_45 -> V_160 = F_59 ( & V_186 -> V_113 ,
V_45 -> V_143 * sizeof( * V_45 -> V_160 ) , V_114 ) ;
if ( ! V_45 -> V_125 || ! V_45 -> V_99 || ! V_45 -> V_160 )
return - V_115 ;
V_45 -> V_145 = F_116 ( V_105 , L_23 ) ;
if ( F_96 ( V_45 -> V_145 ) ) {
F_58 ( V_45 -> V_113 , L_24 ) ;
return F_112 ( V_45 -> V_145 ) ;
}
V_45 -> V_28 = F_117 ( V_192 , V_105 ) -> V_28 ;
V_188 -> V_102 = V_45 -> V_143 * V_2 ;
V_191 = F_59 ( & V_186 -> V_113 ,
sizeof( * V_191 ) * V_188 -> V_102 , V_114 ) ;
if ( ! V_191 )
return - V_115 ;
V_188 -> V_101 = V_191 ;
V_79 = 0 ;
F_84 (np, child) {
if ( F_85 ( V_142 , L_8 ) ) {
const char * V_193 = NULL ;
V_173 = F_108 ( V_45 , V_79 , V_142 ) ;
if ( V_173 )
return V_173 ;
V_189 = V_45 -> V_160 [ V_79 ] . V_129 . V_184 ;
V_193 = V_45 -> V_160 [ V_79 ] . V_129 . V_100 ;
for ( V_152 = 0 ; V_152 < V_2 ; V_152 ++ , V_189 ++ ) {
V_191 -> V_194 = V_189 ;
V_191 -> V_100 = F_118 ( V_114 , L_25 ,
V_193 , V_152 ) ;
V_191 ++ ;
}
F_100 ( V_45 , V_79 , V_142 ) ;
V_79 ++ ;
} else {
V_173 = F_107 ( V_142 , V_45 ,
V_31 ++ , & V_170 ) ;
if ( V_173 ) {
F_58 ( & V_186 -> V_113 , L_26 ) ;
return V_173 ;
}
}
}
return 0 ;
}
static int F_119 ( struct V_185 * V_186 )
{
struct V_44 * V_45 ;
struct V_187 * V_188 ;
int V_173 , V_31 ;
if ( ! V_186 -> V_113 . V_181 ) {
F_58 ( & V_186 -> V_113 , L_27 ) ;
return - V_92 ;
}
V_188 = F_59 ( & V_186 -> V_113 , sizeof( * V_188 ) , V_114 ) ;
if ( ! V_188 )
return - V_115 ;
V_45 = F_59 ( & V_186 -> V_113 , sizeof( * V_45 ) , V_114 ) ;
if ( ! V_45 )
return - V_115 ;
V_45 -> V_113 = & V_186 -> V_113 ;
F_120 ( V_186 , V_45 ) ;
V_173 = F_115 ( V_186 , V_188 , V_45 ) ;
if ( V_173 )
return V_173 ;
V_188 -> V_195 = V_196 ,
V_188 -> V_197 = & V_198 ,
V_188 -> V_199 = & V_200 ,
V_188 -> V_201 = & V_202 ,
V_188 -> V_100 = F_121 ( & V_186 -> V_113 ) ;
V_45 -> V_203 = F_122 ( V_188 , & V_186 -> V_113 , V_45 ) ;
if ( ! V_45 -> V_203 ) {
F_58 ( & V_186 -> V_113 , L_28 ) ;
return - V_92 ;
}
for ( V_31 = 0 ; V_31 < V_45 -> V_143 ; V_31 ++ )
F_123 ( V_45 -> V_203 , & V_45 -> V_160 [ V_31 ] . V_129 ) ;
return 0 ;
}
static int T_4 F_124 ( void )
{
return F_125 ( & V_204 ) ;
}
