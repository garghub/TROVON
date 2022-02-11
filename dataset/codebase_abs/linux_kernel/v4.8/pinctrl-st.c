static struct V_1 * F_1 (
struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 =
F_2 ( V_3 , V_4 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
return & V_8 -> V_9 ;
}
static inline int V_7 ( int V_10 )
{
return V_10 / V_11 ;
}
static inline int F_4 ( int V_10 )
{
return V_10 % V_11 ;
}
static void F_5 ( struct V_1 * V_9 ,
int V_4 , unsigned long V_12 )
{
struct V_13 * V_14 = V_9 -> V_15 ;
struct V_13 * V_16 = V_9 -> V_17 ;
struct V_13 * V_18 = V_9 -> V_19 ;
unsigned int V_20 , V_21 , V_22 ;
unsigned long V_23 = F_6 ( V_4 ) ;
if ( V_14 ) {
F_7 ( V_14 , & V_20 ) ;
V_20 &= ~ V_23 ;
if ( V_12 & V_24 )
V_20 |= V_23 ;
F_8 ( V_14 , V_20 ) ;
}
if ( V_16 ) {
F_7 ( V_16 , & V_21 ) ;
V_21 &= ~ V_23 ;
if ( V_12 & V_25 )
V_21 |= V_23 ;
F_8 ( V_16 , V_21 ) ;
}
if ( V_18 ) {
F_7 ( V_18 , & V_22 ) ;
V_22 &= ~ V_23 ;
if ( V_12 & V_26 )
V_22 |= V_23 ;
F_8 ( V_18 , V_22 ) ;
}
}
static void F_9 ( struct V_1 * V_9 ,
int V_27 , int V_28 )
{
struct V_13 * V_29 = V_9 -> V_29 ;
unsigned int V_30 ;
int V_4 = F_4 ( V_27 ) ;
int V_31 = V_4 * 4 ;
if ( ! V_29 )
return;
F_7 ( V_29 , & V_30 ) ;
V_30 &= ~ ( 0xf << V_31 ) ;
V_30 |= V_28 << V_31 ;
F_8 ( V_29 , V_30 ) ;
}
static unsigned int F_10 ( struct V_1 * V_9 , int V_4 )
{
struct V_13 * V_29 = V_9 -> V_29 ;
unsigned int V_30 ;
int V_31 = V_4 * 4 ;
if ( ! V_29 )
return 0 ;
F_7 ( V_29 , & V_30 ) ;
return ( V_30 >> V_31 ) & 0xf ;
}
static unsigned long F_11 ( unsigned int V_32 ,
const struct V_33 * V_34 , unsigned long V_12 )
{
const unsigned int * V_35 ;
int V_36 , V_37 , V_38 = - 1 ;
unsigned int V_39 = V_40 ;
if ( F_12 ( V_12 ) ) {
V_35 = V_34 -> V_41 ;
V_36 = V_34 -> V_42 ;
} else {
V_35 = V_34 -> V_43 ;
V_36 = V_34 -> V_44 ;
}
for ( V_37 = 0 ; V_37 < V_36 ; V_37 ++ ) {
unsigned int V_45 = abs ( V_32 - V_35 [ V_37 ] ) ;
if ( V_45 == 0 )
return V_37 ;
if ( V_45 < V_39 ) {
V_39 = V_45 ;
V_38 = V_37 ;
}
}
F_13 ( L_1 ,
V_32 , V_35 [ V_38 ] ) ;
return V_38 ;
}
static unsigned long F_14 ( unsigned int V_46 ,
const struct V_33 * V_34 , unsigned long V_47 )
{
const unsigned int * V_35 ;
int V_36 ;
if ( V_47 ) {
V_35 = V_34 -> V_41 ;
V_36 = V_34 -> V_42 ;
} else {
V_35 = V_34 -> V_43 ;
V_36 = V_34 -> V_44 ;
}
if ( V_46 < V_36 ) {
return V_35 [ V_46 ] ;
} else {
F_13 ( L_2 ) ;
return 0 ;
}
}
static void F_15 ( struct V_13 * V_48 ,
int V_49 , int V_4 )
{
unsigned int V_30 = 0 ;
F_7 ( V_48 , & V_30 ) ;
if ( V_49 )
V_30 |= F_6 ( V_4 ) ;
else
V_30 &= ~ F_6 ( V_4 ) ;
F_8 ( V_48 , V_30 ) ;
}
static void F_16 ( struct V_50 * V_51 ,
struct V_1 * V_9 , unsigned long V_12 , int V_4 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
unsigned int V_32 ;
F_15 ( V_53 -> V_55 ,
F_17 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_56 ,
F_18 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_57 ,
F_19 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_58 ,
F_20 ( V_12 ) , V_4 ) ;
F_15 ( V_53 -> V_59 ,
F_21 ( V_12 ) , V_4 ) ;
V_32 = F_11 ( F_22 ( V_12 ) ,
V_34 , V_12 ) ;
F_15 ( V_53 -> V_60 , V_32 & 0x1 , V_4 ) ;
F_15 ( V_53 -> V_61 , V_32 & 0x2 , V_4 ) ;
}
static void F_23 ( struct V_50 * V_51 ,
struct V_1 * V_9 , unsigned long V_12 , int V_4 )
{
int V_62 = F_12 ( V_12 ) ? 0 : 1 ;
int V_63 = F_17 ( V_12 ) ;
int V_56 = F_18 ( V_12 ) ;
int V_57 = F_19 ( V_12 ) ;
int V_58 = F_20 ( V_12 ) ;
int V_59 = F_21 ( V_12 ) ;
unsigned long V_32 = F_11 (
F_22 ( V_12 ) ,
V_51 -> V_34 , V_12 ) ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
unsigned long V_66 =
( ( V_63 ) << V_67 ) |
( ( V_32 ) << V_68 ) |
( ( V_62 ) << V_69 ) |
( ( V_59 ) << V_70 ) |
( ( V_56 ) << V_71 ) |
( ( V_58 ) << V_72 ) |
( ( V_57 ) << V_73 ) ;
F_8 ( V_65 -> V_54 [ V_4 ] , V_66 ) ;
}
static void F_24 ( struct V_1 * V_9 ,
int V_4 , unsigned long * V_12 )
{
unsigned int V_20 , V_21 , V_22 ;
if ( V_9 -> V_15 ) {
F_7 ( V_9 -> V_15 , & V_20 ) ;
if ( V_20 & F_6 ( V_4 ) )
F_25 ( * V_12 ) ;
}
if ( V_9 -> V_17 ) {
F_7 ( V_9 -> V_17 , & V_21 ) ;
if ( V_21 & F_6 ( V_4 ) )
F_26 ( * V_12 ) ;
}
if ( V_9 -> V_19 ) {
F_7 ( V_9 -> V_19 , & V_22 ) ;
if ( V_22 & F_6 ( V_4 ) )
F_27 ( * V_12 ) ;
}
}
static int F_28 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
unsigned int V_74 , V_32 , V_75 , V_76 , V_30 ;
int V_47 = F_12 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_59 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_29 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_55 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_30 ( * V_12 , 1 ) ;
if ( ! F_7 ( V_53 -> V_56 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_31 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_57 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_32 ( * V_12 ) ;
if ( ! F_7 ( V_53 -> V_58 , & V_30 ) && ( V_30 & F_6 ( V_4 ) ) )
F_33 ( * V_12 ) ;
F_7 ( V_53 -> V_60 , & V_75 ) ;
F_7 ( V_53 -> V_61 , & V_76 ) ;
V_74 = ( ( ( V_76 & F_6 ( V_4 ) ) ? 1 : 0 ) << 1 ) |
( ( ( V_75 & F_6 ( V_4 ) ) ? 1 : 0 ) ) ;
V_32 = F_14 ( V_74 , V_34 , V_47 ) ;
F_34 ( * V_12 , V_32 ) ;
return 0 ;
}
static int F_35 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
unsigned int V_77 ;
unsigned long V_74 , V_32 , V_78 ;
int V_47 = F_12 ( * V_12 ) ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
F_7 ( V_65 -> V_54 [ V_4 ] , & V_77 ) ;
V_78 = ( V_77 & V_79 ) >> V_67 ;
F_30 ( * V_12 , V_78 ) ;
V_74 = ( V_77 & V_80 ) >> V_68 ;
V_32 = F_14 ( V_74 , V_51 -> V_34 , V_47 ) ;
F_34 ( * V_12 , V_32 ) ;
if ( V_77 & V_81 )
F_31 ( * V_12 ) ;
if ( V_77 & V_82 )
F_32 ( * V_12 ) ;
if ( V_77 & V_83 )
F_33 ( * V_12 ) ;
if ( V_77 & V_84 )
F_29 ( * V_12 ) ;
return 0 ;
}
static inline void F_36 ( struct V_7 * V_8 ,
unsigned V_31 , int V_77 )
{
if ( V_77 )
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + V_86 ) ;
else
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + V_87 ) ;
}
static void F_38 ( struct V_7 * V_8 ,
unsigned int V_10 , unsigned int V_88 )
{
int V_31 = F_4 ( V_10 ) ;
int V_37 = 0 ;
for ( V_37 = 0 ; V_37 <= 2 ; V_37 ++ ) {
if ( V_88 & F_6 ( V_37 ) )
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + F_39 ( V_37 ) ) ;
else
F_37 ( F_6 ( V_31 ) , V_8 -> V_85 + F_40 ( V_37 ) ) ;
}
}
static int F_41 ( struct V_89 * V_90 , unsigned V_31 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
return ! ! ( F_43 ( V_8 -> V_85 + V_91 ) & F_6 ( V_31 ) ) ;
}
static void F_44 ( struct V_89 * V_90 , unsigned V_31 , int V_77 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
F_36 ( V_8 , V_31 , V_77 ) ;
}
static int F_45 ( struct V_89 * V_90 , unsigned V_31 )
{
F_46 ( V_90 -> V_85 + V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_90 ,
unsigned V_31 , int V_77 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
F_36 ( V_8 , V_31 , V_77 ) ;
F_48 ( V_90 -> V_85 + V_31 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_90 , unsigned V_31 )
{
struct V_7 * V_8 = F_42 ( V_90 ) ;
struct V_1 V_9 = V_8 -> V_9 ;
unsigned long V_12 ;
unsigned int V_88 = 0 ;
unsigned int V_28 ;
unsigned int V_77 ;
int V_37 = 0 ;
V_28 = F_10 ( & V_9 , V_31 ) ;
if ( V_28 ) {
F_24 ( & V_9 , V_31 , & V_12 ) ;
return ! F_12 ( V_12 ) ;
}
for ( V_37 = 0 ; V_37 <= 2 ; V_37 ++ ) {
V_77 = F_43 ( V_8 -> V_85 + F_50 ( V_37 ) ) ;
V_88 |= ( ( V_77 >> V_31 ) & 0x1 ) << V_37 ;
}
return ( V_88 == V_92 ) ;
}
static int F_51 ( struct V_89 * V_93 ,
const struct V_94 * V_95 , T_1 * V_96 )
{
if ( F_52 ( V_93 -> V_97 < 1 ) )
return - V_98 ;
if ( F_52 ( V_95 -> V_99 < V_93 -> V_97 ) )
return - V_98 ;
if ( V_95 -> args [ 0 ] > V_93 -> V_100 )
return - V_98 ;
return V_95 -> args [ 0 ] ;
}
static int F_53 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
return V_51 -> V_101 ;
}
static const char * F_55 ( struct V_2 * V_3 ,
unsigned V_102 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
return V_51 -> V_103 [ V_102 ] . V_104 ;
}
static int F_56 ( struct V_2 * V_3 ,
unsigned V_102 , const unsigned * * V_105 , unsigned * V_106 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
if ( V_102 >= V_51 -> V_101 )
return - V_98 ;
* V_105 = V_51 -> V_103 [ V_102 ] . V_105 ;
* V_106 = V_51 -> V_103 [ V_102 ] . V_106 ;
return 0 ;
}
static inline const struct V_107 * F_57 (
const struct V_50 * V_51 , const char * V_104 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < V_51 -> V_101 ; V_37 ++ ) {
if ( ! strcmp ( V_51 -> V_103 [ V_37 ] . V_104 , V_104 ) )
return & V_51 -> V_103 [ V_37 ] ;
}
return NULL ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_108 * V_109 , struct V_110 * * V_111 , unsigned * V_112 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
const struct V_107 * V_113 ;
struct V_110 * V_114 ;
struct V_108 * V_115 ;
int V_116 , V_37 ;
V_113 = F_57 ( V_51 , V_109 -> V_104 ) ;
if ( ! V_113 ) {
F_59 ( V_51 -> V_117 , L_3 ,
V_109 -> V_104 ) ;
return - V_98 ;
}
V_116 = V_113 -> V_106 + 1 ;
V_114 = F_60 ( V_3 -> V_117 ,
sizeof( * V_114 ) * V_116 , V_118 ) ;
if ( ! V_114 )
return - V_119 ;
V_115 = F_61 ( V_109 ) ;
if ( ! V_115 ) {
F_62 ( V_3 -> V_117 , V_114 ) ;
return - V_98 ;
}
* V_111 = V_114 ;
* V_112 = V_116 ;
V_114 [ 0 ] . type = V_120 ;
V_114 [ 0 ] . V_34 . V_121 . V_28 = V_115 -> V_104 ;
V_114 [ 0 ] . V_34 . V_121 . V_122 = V_109 -> V_104 ;
F_63 ( V_115 ) ;
V_114 ++ ;
for ( V_37 = 0 ; V_37 < V_113 -> V_106 ; V_37 ++ ) {
V_114 [ V_37 ] . type = V_123 ;
V_114 [ V_37 ] . V_34 . V_124 . V_125 =
F_64 ( V_3 , V_113 -> V_105 [ V_37 ] ) ;
V_114 [ V_37 ] . V_34 . V_124 . V_124 = & V_113 -> V_126 [ V_37 ] . V_12 ;
V_114 [ V_37 ] . V_34 . V_124 . V_127 = 1 ;
}
F_65 ( V_3 -> V_117 , L_4 ,
( * V_111 ) -> V_34 . V_121 . V_28 , V_113 -> V_104 , V_116 ) ;
return 0 ;
}
static void F_66 ( struct V_2 * V_3 ,
struct V_110 * V_111 , unsigned V_112 )
{
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
return V_51 -> V_128 ;
}
static const char * F_68 ( struct V_2 * V_3 ,
unsigned V_102 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
return V_51 -> V_129 [ V_102 ] . V_104 ;
}
static int F_69 ( struct V_2 * V_3 ,
unsigned V_102 , const char * const * * V_130 , unsigned * const V_131 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
* V_130 = V_51 -> V_129 [ V_102 ] . V_103 ;
* V_131 = V_51 -> V_129 [ V_102 ] . V_101 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 , unsigned V_132 ,
unsigned V_122 )
{
struct V_50 * V_51 = F_54 ( V_3 ) ;
struct V_133 * V_134 = V_51 -> V_103 [ V_122 ] . V_126 ;
struct V_1 * V_9 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_51 -> V_103 [ V_122 ] . V_106 ; V_37 ++ ) {
V_9 = F_1 ( V_3 , V_134 [ V_37 ] . V_4 ) ;
F_9 ( V_9 , V_134 [ V_37 ] . V_4 , V_134 [ V_37 ] . V_135 ) ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_5 * V_6 , unsigned V_10 ,
bool V_62 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
F_9 ( & V_8 -> V_9 , V_10 , 0 ) ;
F_38 ( V_8 , V_10 , V_62 ?
V_92 : V_136 ) ;
return 0 ;
}
static void F_72 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long * V_12 )
{
if ( V_51 -> V_34 -> V_137 == V_138 )
F_28 ( V_51 , V_9 , V_4 , V_12 ) ;
else if ( V_51 -> V_34 -> V_137 == V_139 )
if ( ( F_6 ( V_4 ) & V_9 -> V_140 ) )
F_35 ( V_51 , V_9 ,
V_4 , V_12 ) ;
}
static void F_73 ( struct V_50 * V_51 ,
struct V_1 * V_9 , int V_4 , unsigned long V_12 )
{
if ( V_51 -> V_34 -> V_137 == V_138 )
F_16 ( V_51 , V_9 , V_12 , V_4 ) ;
else if ( V_51 -> V_34 -> V_137 == V_139 )
if ( ( F_6 ( V_4 ) & V_9 -> V_140 ) )
F_23 ( V_51 , V_9 ,
V_12 , V_4 ) ;
}
static int F_74 ( struct V_2 * V_3 , unsigned V_27 ,
unsigned long * V_124 , unsigned V_127 )
{
int V_4 = F_4 ( V_27 ) ;
struct V_50 * V_51 = F_54 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_27 ) ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_127 ; V_37 ++ ) {
F_5 ( V_9 , V_4 , V_124 [ V_37 ] ) ;
F_73 ( V_51 , V_9 , V_4 , V_124 [ V_37 ] ) ;
}
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
unsigned V_27 , unsigned long * V_12 )
{
int V_4 = F_4 ( V_27 ) ;
struct V_50 * V_51 = F_54 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_27 ) ;
* V_12 = 0 ;
F_24 ( V_9 , V_4 , V_12 ) ;
F_72 ( V_51 , V_9 , V_4 , V_12 ) ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 ,
struct V_141 * V_142 , unsigned V_27 )
{
struct V_1 * V_9 ;
unsigned long V_12 ;
unsigned int V_28 ;
int V_31 = F_4 ( V_27 ) ;
char V_143 [ 16 ] ;
F_77 ( & V_3 -> V_144 ) ;
V_9 = F_1 ( V_3 , V_27 ) ;
F_75 ( V_3 , V_27 , & V_12 ) ;
F_78 ( & V_3 -> V_144 ) ;
V_28 = F_10 ( V_9 , V_31 ) ;
if ( V_28 )
snprintf ( V_143 , 10 , L_5 , V_28 ) ;
else
snprintf ( V_143 , 5 , L_6 ) ;
F_79 ( V_142 , L_7
L_8
L_9 ,
! F_49 ( & F_80 ( V_9 ) -> V_89 , V_31 ) ,
F_81 ( V_12 ) ,
F_82 ( V_12 ) ,
V_143 ,
F_21 ( V_12 ) ,
F_20 ( V_12 ) ,
F_18 ( V_12 ) ,
F_19 ( V_12 ) ,
F_17 ( V_12 ) ,
F_22 ( V_12 ) ) ;
}
static void F_83 ( struct V_50 * V_51 ,
struct V_108 * V_109 )
{
struct V_108 * V_145 ;
F_84 (np, child) {
if ( F_85 ( V_145 , L_10 ) ) {
V_51 -> V_146 ++ ;
} else {
V_51 -> V_128 ++ ;
V_51 -> V_101 += F_86 ( V_145 ) ;
}
}
}
static int F_87 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
struct V_147 * V_117 = V_51 -> V_117 ;
struct V_148 * V_149 = V_51 -> V_148 ;
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_150 = ( V_34 -> V_54 + V_8 * V_151 ) * 4 ;
struct V_52 * V_53 = & V_9 -> V_54 . V_53 ;
struct V_152 V_55 = F_88 ( V_150 ) ;
struct V_152 V_60 = F_89 ( V_150 ) ;
struct V_152 V_61 = F_90 ( V_150 ) ;
struct V_152 V_58 = F_91 ( V_150 + 4 ) ;
struct V_152 V_59 = F_92 ( V_150 + 4 ) ;
struct V_152 V_56 = F_93 ( V_150 + 4 ) ;
struct V_152 V_57 = F_94 ( V_150 + 4 ) ;
V_53 -> V_55 = F_95 ( V_117 , V_149 , V_55 ) ;
V_53 -> V_60 = F_95 ( V_117 , V_149 , V_60 ) ;
V_53 -> V_61 = F_95 ( V_117 , V_149 , V_61 ) ;
V_53 -> V_58 = F_95 ( V_117 , V_149 , V_58 ) ;
V_53 -> V_59 = F_95 ( V_117 , V_149 , V_59 ) ;
V_53 -> V_56 = F_95 ( V_117 , V_149 , V_56 ) ;
V_53 -> V_57 = F_95 ( V_117 , V_149 , V_57 ) ;
if ( F_96 ( V_53 -> V_55 ) || F_96 ( V_53 -> V_60 ) ||
F_96 ( V_53 -> V_61 ) || F_96 ( V_53 -> V_58 ) ||
F_96 ( V_53 -> V_59 ) || F_96 ( V_53 -> V_56 ) ||
F_96 ( V_53 -> V_57 ) )
return - V_98 ;
return 0 ;
}
static int F_97 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
struct V_147 * V_117 = V_51 -> V_117 ;
struct V_148 * V_149 = V_51 -> V_148 ;
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_153 = ( V_34 -> V_54 + V_8 * V_154 ) * 4 ;
struct V_64 * V_65 = & V_9 -> V_54 . V_65 ;
unsigned int V_155 ;
T_1 V_156 = V_9 -> V_140 ;
for ( V_155 = 0 ; V_155 < V_154 ; V_155 ++ ) {
if ( F_6 ( V_155 ) & V_156 ) {
struct V_152 V_150 = F_98 ( V_153 , 0 , 31 ) ;
V_65 -> V_54 [ V_155 ] = F_95 ( V_117 , V_149 , V_150 ) ;
if ( F_96 ( V_65 -> V_54 [ V_155 ] ) )
return - V_98 ;
V_153 += 4 ;
}
}
return 0 ;
}
static int F_99 ( struct V_50 * V_51 ,
int V_8 , struct V_1 * V_9 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
if ( V_34 -> V_137 == V_138 )
return F_87 ( V_51 , V_8 , V_9 ) ;
else if ( V_34 -> V_137 == V_139 )
return F_97 ( V_51 , V_8 , V_9 ) ;
return - V_98 ;
}
static struct V_13 * F_100 ( struct V_147 * V_117 ,
struct V_148 * V_148 , int V_8 ,
int V_34 , int V_157 , int V_158 )
{
struct V_152 V_150 = F_98 ( ( V_34 + V_8 ) * 4 , V_157 , V_158 ) ;
if ( V_34 < 0 )
return NULL ;
return F_95 ( V_117 , V_148 , V_150 ) ;
}
static void F_101 ( struct V_50 * V_51 , int V_8 ,
struct V_108 * V_109 )
{
const struct V_33 * V_34 = V_51 -> V_34 ;
int V_157 = ( V_8 % 4 ) * V_11 ;
int V_158 = V_157 + V_11 - 1 ;
struct V_1 * V_9 = & V_51 -> V_159 [ V_8 ] . V_9 ;
struct V_147 * V_117 = V_51 -> V_117 ;
struct V_148 * V_148 = V_51 -> V_148 ;
V_9 -> V_29 = F_100 ( V_117 , V_148 , V_8 , V_34 -> V_29 , 0 , 31 ) ;
V_9 -> V_15 = F_100 ( V_117 , V_148 , V_8 / 4 , V_34 -> V_15 , V_157 , V_158 ) ;
V_9 -> V_17 = F_100 ( V_117 , V_148 , V_8 / 4 , V_34 -> V_17 , V_157 , V_158 ) ;
V_9 -> V_19 = F_100 ( V_117 , V_148 , V_8 / 4 , V_34 -> V_19 , V_157 , V_158 ) ;
V_9 -> V_140 = 0xff ;
F_102 ( V_109 , L_11 , & V_9 -> V_140 ) ;
F_99 ( V_51 , V_8 , V_9 ) ;
return;
}
static int F_103 ( struct V_108 * V_109 ,
struct V_107 * V_113 , struct V_50 * V_51 , int V_160 )
{
const T_2 * V_161 ;
struct V_162 * V_163 ;
struct V_133 * V_134 ;
struct V_108 * V_105 ;
int V_37 = 0 , V_106 = 0 , V_164 ;
V_105 = F_104 ( V_109 , L_12 ) ;
if ( ! V_105 )
return - V_165 ;
F_105 (pins, pp) {
if ( ! strcmp ( V_163 -> V_104 , L_13 ) )
continue;
if ( V_163 && ( V_163 -> V_166 / sizeof( T_2 ) ) >= V_167 ) {
V_106 ++ ;
} else {
F_13 ( L_14 , V_109 -> V_104 ) ;
return - V_98 ;
}
}
V_113 -> V_106 = V_106 ;
V_113 -> V_104 = V_109 -> V_104 ;
V_113 -> V_105 = F_60 ( V_51 -> V_117 , V_106 * sizeof( T_1 ) , V_118 ) ;
V_113 -> V_126 = F_60 ( V_51 -> V_117 ,
V_106 * sizeof( * V_134 ) , V_118 ) ;
if ( ! V_113 -> V_105 || ! V_113 -> V_126 )
return - V_119 ;
F_105 (pins, pp) {
if ( ! strcmp ( V_163 -> V_104 , L_13 ) )
continue;
V_164 = V_163 -> V_166 / sizeof( T_1 ) ;
V_161 = V_163 -> V_77 ;
V_134 = & V_113 -> V_126 [ V_37 ] ;
F_106 ( V_161 ++ ) ;
F_106 ( V_161 ++ ) ;
V_134 -> V_4 = F_107 ( V_105 , V_163 -> V_104 , 0 ) ;
V_134 -> V_104 = V_163 -> V_104 ;
V_113 -> V_105 [ V_37 ] = V_134 -> V_4 ;
V_134 -> V_135 = F_106 ( V_161 ++ ) ;
V_134 -> V_12 = 0 ;
V_134 -> V_12 |= F_106 ( V_161 ++ ) ;
if ( V_164 >= V_167 + V_168 ) {
V_134 -> V_12 |= F_106 ( V_161 ++ ) ;
V_134 -> V_12 |= F_106 ( V_161 ++ ) ;
if ( V_164 > V_167 + V_168 )
V_134 -> V_12 |= F_106 ( V_161 ++ ) ;
}
V_37 ++ ;
}
F_63 ( V_105 ) ;
return 0 ;
}
static int F_108 ( struct V_108 * V_109 ,
struct V_50 * V_51 , T_1 V_46 , int * V_169 )
{
struct V_108 * V_145 ;
struct V_170 * V_171 ;
struct V_107 * V_113 ;
int V_172 , V_37 ;
V_171 = & V_51 -> V_129 [ V_46 ] ;
V_171 -> V_104 = V_109 -> V_104 ;
V_171 -> V_101 = F_86 ( V_109 ) ;
if ( V_171 -> V_101 == 0 ) {
F_59 ( V_51 -> V_117 , L_15 ) ;
return - V_98 ;
}
V_171 -> V_103 = F_60 ( V_51 -> V_117 ,
V_171 -> V_101 * sizeof( char * ) , V_118 ) ;
if ( ! V_171 -> V_103 )
return - V_119 ;
V_37 = 0 ;
F_84 (np, child) {
V_171 -> V_103 [ V_37 ] = V_145 -> V_104 ;
V_113 = & V_51 -> V_103 [ * V_169 ] ;
* V_169 += 1 ;
V_172 = F_103 ( V_145 , V_113 , V_51 , V_37 ++ ) ;
if ( V_172 )
return V_172 ;
}
F_65 ( V_51 -> V_117 , L_16 ,
V_46 , V_171 -> V_104 , V_171 -> V_101 ) ;
return 0 ;
}
static void F_109 ( struct V_173 * V_174 )
{
struct V_89 * V_93 = F_110 ( V_174 ) ;
struct V_7 * V_8 = F_42 ( V_93 ) ;
F_37 ( F_6 ( V_174 -> V_175 ) , V_8 -> V_85 + V_176 ) ;
}
static void F_111 ( struct V_173 * V_174 )
{
struct V_89 * V_93 = F_110 ( V_174 ) ;
struct V_7 * V_8 = F_42 ( V_93 ) ;
F_37 ( F_6 ( V_174 -> V_175 ) , V_8 -> V_85 + V_177 ) ;
}
static int F_112 ( struct V_173 * V_174 , unsigned type )
{
struct V_89 * V_93 = F_110 ( V_174 ) ;
struct V_7 * V_8 = F_42 ( V_93 ) ;
unsigned long V_96 ;
int V_178 , V_4 = V_174 -> V_175 ;
T_1 V_30 ;
T_1 V_179 = 0 ;
switch ( type ) {
case V_180 :
V_178 = 0 ;
break;
case V_181 :
V_178 = 0 ;
V_179 = F_113 ( V_4 ) ;
break;
case V_182 :
V_178 = 1 ;
break;
case V_183 :
V_178 = 1 ;
V_179 = F_114 ( V_4 ) ;
break;
case V_184 :
V_178 = F_41 ( & V_8 -> V_89 , V_4 ) ;
V_179 = F_115 ( V_4 ) ;
break;
default:
return - V_98 ;
}
F_116 ( & V_8 -> V_185 , V_96 ) ;
V_8 -> V_186 &= ~ ( V_187 << (
V_4 * V_188 ) ) ;
V_8 -> V_186 |= V_179 ;
F_117 ( & V_8 -> V_185 , V_96 ) ;
V_30 = F_43 ( V_8 -> V_85 + V_189 ) ;
V_30 &= ~ F_6 ( V_4 ) ;
V_30 |= ( V_178 << V_4 ) ;
F_37 ( V_30 , V_8 -> V_85 + V_189 ) ;
return 0 ;
}
static void F_118 ( struct V_7 * V_8 )
{
unsigned long V_190 , V_191 , V_192 , V_193 ;
unsigned long V_194 , V_96 ;
int V_195 , V_30 , V_196 ;
F_116 ( & V_8 -> V_185 , V_96 ) ;
V_194 = V_8 -> V_186 ;
F_117 ( & V_8 -> V_185 , V_96 ) ;
for (; ; ) {
V_190 = F_43 ( V_8 -> V_85 + V_91 ) ;
V_192 = F_43 ( V_8 -> V_85 + V_189 ) ;
V_191 = F_43 ( V_8 -> V_85 + V_197 ) ;
V_193 = ( V_190 ^ V_192 ) & V_191 ;
if ( V_193 == 0 )
break;
F_119 (n, &active_irqs, BITS_PER_LONG) {
V_196 = F_120 ( V_194 , V_195 ) ;
if ( V_196 ) {
V_30 = F_41 ( & V_8 -> V_89 , V_195 ) ;
F_37 ( F_6 ( V_195 ) ,
V_30 ? V_8 -> V_85 + V_198 :
V_8 -> V_85 + V_199 ) ;
if ( V_196 != V_200 &&
! ( ( V_196 & V_201 ) ^ V_30 ) )
continue;
}
F_121 ( F_122 ( V_8 -> V_89 . V_202 , V_195 ) ) ;
}
}
}
static void F_123 ( struct V_203 * V_204 )
{
struct V_205 * V_90 = F_124 ( V_204 ) ;
struct V_89 * V_93 = F_125 ( V_204 ) ;
struct V_7 * V_8 = F_42 ( V_93 ) ;
F_126 ( V_90 , V_204 ) ;
F_118 ( V_8 ) ;
F_127 ( V_90 , V_204 ) ;
}
static void F_128 ( struct V_203 * V_204 )
{
struct V_205 * V_90 = F_124 ( V_204 ) ;
struct V_50 * V_51 = F_125 ( V_204 ) ;
unsigned long V_206 ;
int V_195 ;
F_126 ( V_90 , V_204 ) ;
V_206 = F_43 ( V_51 -> V_207 ) ;
F_119 (n, &status, info->nbanks)
F_118 ( & V_51 -> V_159 [ V_195 ] ) ;
F_127 ( V_90 , V_204 ) ;
}
static int F_129 ( struct V_50 * V_51 ,
int V_208 , struct V_108 * V_109 )
{
struct V_7 * V_8 = & V_51 -> V_159 [ V_208 ] ;
struct V_5 * V_6 = & V_8 -> V_6 ;
struct V_147 * V_117 = V_51 -> V_117 ;
int V_209 = F_130 ( V_109 , L_17 ) ;
struct V_210 V_211 , V_212 ;
int V_213 = 0 , V_214 ;
if ( F_131 ( V_109 , 0 , & V_211 ) )
return - V_215 ;
V_8 -> V_85 = F_132 ( V_117 , & V_211 ) ;
if ( F_96 ( V_8 -> V_85 ) )
return F_133 ( V_8 -> V_85 ) ;
V_8 -> V_89 = V_216 ;
V_8 -> V_89 . V_85 = V_209 * V_11 ;
V_8 -> V_89 . V_100 = V_11 ;
V_8 -> V_89 . V_217 = V_109 ;
V_8 -> V_89 . V_115 = V_117 ;
F_134 ( & V_8 -> V_185 ) ;
F_135 ( V_109 , L_18 , & V_6 -> V_104 ) ;
V_8 -> V_89 . V_218 = V_6 -> V_104 ;
V_6 -> V_219 = V_209 ;
V_6 -> V_220 = V_6 -> V_85 = V_6 -> V_219 * V_11 ;
V_6 -> V_106 = V_8 -> V_89 . V_100 ;
V_6 -> V_93 = & V_8 -> V_89 ;
V_214 = F_136 ( & V_8 -> V_89 , V_8 ) ;
if ( V_214 ) {
F_59 ( V_117 , L_19 , V_209 ) ;
return V_214 ;
}
F_65 ( V_117 , L_20 , V_6 -> V_104 ) ;
if ( F_137 ( V_109 , 0 , & V_212 ) ) {
V_213 = V_212 . V_221 ;
F_138 ( & V_8 -> V_89 , & V_222 ,
V_213 , F_123 ) ;
}
if ( V_51 -> V_207 || V_213 > 0 ) {
V_214 = F_139 ( & V_8 -> V_89 , & V_222 ,
0 , V_223 ,
V_182 ) ;
if ( V_214 ) {
F_140 ( & V_8 -> V_89 ) ;
F_65 ( V_117 , L_21 ) ;
return V_214 ;
}
} else {
F_65 ( V_117 , L_22 , V_109 -> V_224 ) ;
}
return 0 ;
}
static int F_141 ( struct V_225 * V_226 ,
struct V_227 * V_228 , struct V_50 * V_51 )
{
int V_172 = 0 ;
int V_37 = 0 , V_155 = 0 , V_229 = 0 , V_8 ;
struct V_230 * V_231 ;
struct V_108 * V_109 = V_226 -> V_117 . V_217 ;
struct V_108 * V_145 ;
int V_169 = 0 ;
int V_232 = 0 ;
struct V_210 * V_211 ;
F_83 ( V_51 , V_109 ) ;
if ( ! V_51 -> V_146 ) {
F_59 ( & V_226 -> V_117 , L_23 ) ;
return - V_98 ;
}
F_65 ( & V_226 -> V_117 , L_24 , V_51 -> V_146 ) ;
F_65 ( & V_226 -> V_117 , L_25 , V_51 -> V_128 ) ;
F_65 ( & V_226 -> V_117 , L_26 , V_51 -> V_101 ) ;
V_51 -> V_129 = F_60 ( & V_226 -> V_117 ,
V_51 -> V_128 * sizeof( * V_51 -> V_129 ) , V_118 ) ;
V_51 -> V_103 = F_60 ( & V_226 -> V_117 ,
V_51 -> V_101 * sizeof( * V_51 -> V_103 ) , V_118 ) ;
V_51 -> V_159 = F_60 ( & V_226 -> V_117 ,
V_51 -> V_146 * sizeof( * V_51 -> V_159 ) , V_118 ) ;
if ( ! V_51 -> V_129 || ! V_51 -> V_103 || ! V_51 -> V_159 )
return - V_119 ;
V_51 -> V_148 = F_142 ( V_109 , L_27 ) ;
if ( F_96 ( V_51 -> V_148 ) ) {
F_59 ( V_51 -> V_117 , L_28 ) ;
return F_133 ( V_51 -> V_148 ) ;
}
V_51 -> V_34 = F_143 ( V_233 , V_109 ) -> V_34 ;
V_232 = F_144 ( V_226 , 0 ) ;
if ( V_232 > 0 ) {
V_211 = F_145 ( V_226 ,
V_234 , L_29 ) ;
V_51 -> V_207 = F_132 ( & V_226 -> V_117 , V_211 ) ;
if ( F_96 ( V_51 -> V_207 ) )
return F_133 ( V_51 -> V_207 ) ;
F_146 ( V_232 , F_128 ,
V_51 ) ;
}
V_228 -> V_106 = V_51 -> V_146 * V_11 ;
V_231 = F_60 ( & V_226 -> V_117 ,
sizeof( * V_231 ) * V_228 -> V_106 , V_118 ) ;
if ( ! V_231 )
return - V_119 ;
V_228 -> V_105 = V_231 ;
V_8 = 0 ;
F_84 (np, child) {
if ( F_85 ( V_145 , L_10 ) ) {
const char * V_235 = NULL ;
V_172 = F_129 ( V_51 , V_8 , V_145 ) ;
if ( V_172 )
return V_172 ;
V_229 = V_51 -> V_159 [ V_8 ] . V_6 . V_220 ;
V_235 = V_51 -> V_159 [ V_8 ] . V_6 . V_104 ;
for ( V_155 = 0 ; V_155 < V_11 ; V_155 ++ , V_229 ++ ) {
V_231 -> V_236 = V_229 ;
V_231 -> V_104 = F_147 ( V_118 , L_30 ,
V_235 , V_155 ) ;
V_231 ++ ;
}
F_101 ( V_51 , V_8 , V_145 ) ;
V_8 ++ ;
} else {
V_172 = F_108 ( V_145 , V_51 ,
V_37 ++ , & V_169 ) ;
if ( V_172 ) {
F_59 ( & V_226 -> V_117 , L_31 ) ;
return V_172 ;
}
}
}
return 0 ;
}
static int F_148 ( struct V_225 * V_226 )
{
struct V_50 * V_51 ;
struct V_227 * V_228 ;
int V_172 , V_37 ;
if ( ! V_226 -> V_117 . V_217 ) {
F_59 ( & V_226 -> V_117 , L_32 ) ;
return - V_98 ;
}
V_228 = F_60 ( & V_226 -> V_117 , sizeof( * V_228 ) , V_118 ) ;
if ( ! V_228 )
return - V_119 ;
V_51 = F_60 ( & V_226 -> V_117 , sizeof( * V_51 ) , V_118 ) ;
if ( ! V_51 )
return - V_119 ;
V_51 -> V_117 = & V_226 -> V_117 ;
F_149 ( V_226 , V_51 ) ;
V_172 = F_141 ( V_226 , V_228 , V_51 ) ;
if ( V_172 )
return V_172 ;
V_228 -> V_237 = V_238 ;
V_228 -> V_239 = & V_240 ;
V_228 -> V_241 = & V_242 ;
V_228 -> V_243 = & V_244 ;
V_228 -> V_104 = F_150 ( & V_226 -> V_117 ) ;
V_51 -> V_245 = F_151 ( & V_226 -> V_117 , V_228 , V_51 ) ;
if ( F_96 ( V_51 -> V_245 ) ) {
F_59 ( & V_226 -> V_117 , L_33 ) ;
return F_133 ( V_51 -> V_245 ) ;
}
for ( V_37 = 0 ; V_37 < V_51 -> V_146 ; V_37 ++ )
F_152 ( V_51 -> V_245 , & V_51 -> V_159 [ V_37 ] . V_6 ) ;
return 0 ;
}
static int T_3 F_153 ( void )
{
return F_154 ( & V_246 ) ;
}
