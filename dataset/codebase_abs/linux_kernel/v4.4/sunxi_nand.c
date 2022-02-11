static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_7 ) ;
}
static T_1 F_4 ( int V_8 , void * V_9 )
{
struct V_4 * V_10 = V_9 ;
T_2 V_11 = F_5 ( V_10 -> V_12 + V_13 ) ;
T_2 V_14 = F_5 ( V_10 -> V_12 + V_15 ) ;
if ( ! ( V_14 & V_11 ) )
return V_16 ;
if ( ( V_14 & V_11 ) == V_14 )
F_6 ( & V_10 -> F_6 ) ;
F_7 ( V_11 & V_17 , V_10 -> V_12 + V_13 ) ;
F_7 ( ~ V_11 & V_14 & V_17 , V_10 -> V_12 + V_15 ) ;
return V_18 ;
}
static int F_8 ( struct V_4 * V_10 , T_2 V_19 ,
unsigned int V_20 )
{
F_9 ( & V_10 -> F_6 ) ;
F_7 ( V_19 , V_10 -> V_12 + V_15 ) ;
if ( ! V_20 )
V_20 = V_21 ;
if ( ! F_10 ( & V_10 -> F_6 ,
F_11 ( V_20 ) ) ) {
F_12 ( V_10 -> V_22 , L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_10 )
{
unsigned long V_24 = V_25 +
F_11 ( V_21 ) ;
do {
if ( ! ( F_5 ( V_10 -> V_12 + V_13 ) & V_26 ) )
return 0 ;
} while ( F_14 ( V_25 , V_24 ) );
F_12 ( V_10 -> V_22 , L_2 ) ;
return - V_23 ;
}
static int F_15 ( struct V_4 * V_10 )
{
unsigned long V_24 = V_25 +
F_11 ( V_21 ) ;
F_7 ( 0 , V_10 -> V_12 + V_27 ) ;
F_7 ( V_28 , V_10 -> V_12 + V_29 ) ;
do {
if ( ! ( F_5 ( V_10 -> V_12 + V_29 ) & V_28 ) )
return 0 ;
} while ( F_14 ( V_25 , V_24 ) );
F_12 ( V_10 -> V_22 , L_3 ) ;
return - V_23 ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
struct V_34 * V_35 ;
unsigned long V_36 = ( V_33 -> V_3 . V_37 == V_38 ? 400 : 20 ) ;
int V_39 ;
if ( V_33 -> V_40 < 0 )
return 0 ;
V_35 = & V_33 -> V_41 [ V_33 -> V_40 ] . V_35 ;
switch ( V_35 -> type ) {
case V_42 :
V_39 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_17 ( V_35 -> V_43 . V_44 ) ) ;
if ( V_39 )
break;
F_8 ( V_10 , V_45 , V_36 ) ;
V_39 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_17 ( V_35 -> V_43 . V_44 ) ) ;
break;
case V_46 :
V_39 = F_18 ( V_35 -> V_43 . V_47 ) ;
break;
case V_48 :
default:
V_39 = 0 ;
F_12 ( V_10 -> V_22 , L_4 ) ;
break;
}
return V_39 ;
}
static void F_19 ( struct V_30 * V_31 , int V_49 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
struct V_50 * V_51 ;
T_2 V_52 ;
if ( V_49 > 0 && V_49 >= V_33 -> V_53 )
return;
if ( V_49 == V_33 -> V_40 )
return;
V_52 = F_5 ( V_10 -> V_12 + V_29 ) &
~ ( V_54 | V_55 | V_56 | V_57 ) ;
if ( V_49 >= 0 ) {
V_51 = & V_33 -> V_41 [ V_49 ] ;
V_52 |= F_20 ( V_51 -> V_58 ) | V_57 |
F_21 ( V_3 -> V_59 - 10 ) ;
if ( V_51 -> V_35 . type == V_48 ) {
V_3 -> V_60 = NULL ;
} else {
V_3 -> V_60 = F_16 ;
if ( V_51 -> V_35 . type == V_42 )
V_52 |= F_22 ( V_51 -> V_35 . V_43 . V_44 ) ;
}
F_7 ( V_31 -> V_61 , V_10 -> V_12 + V_62 ) ;
if ( V_10 -> V_63 != V_33 -> V_63 ) {
F_23 ( V_10 -> V_64 , V_33 -> V_63 ) ;
V_10 -> V_63 = V_33 -> V_63 ;
}
}
F_7 ( V_33 -> V_65 , V_10 -> V_12 + V_66 ) ;
F_7 ( V_33 -> V_67 , V_10 -> V_12 + V_68 ) ;
F_7 ( V_52 , V_10 -> V_12 + V_29 ) ;
V_33 -> V_40 = V_49 ;
}
static void F_24 ( struct V_30 * V_31 , T_3 * V_69 , int V_70 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
int V_39 ;
int V_71 ;
int V_72 = 0 ;
T_2 V_73 ;
while ( V_70 > V_72 ) {
V_71 = F_25 ( V_70 - V_72 , V_74 ) ;
V_39 = F_13 ( V_10 ) ;
if ( V_39 )
break;
F_7 ( V_71 , V_10 -> V_12 + V_75 ) ;
V_73 = V_76 | V_77 ;
F_7 ( V_73 , V_10 -> V_12 + V_78 ) ;
V_39 = F_8 ( V_10 , V_79 , 0 ) ;
if ( V_39 )
break;
if ( V_69 )
F_26 ( V_69 + V_72 , V_10 -> V_12 + V_80 ,
V_71 ) ;
V_72 += V_71 ;
}
}
static void F_27 ( struct V_30 * V_31 , const T_3 * V_69 ,
int V_70 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
int V_39 ;
int V_71 ;
int V_72 = 0 ;
T_2 V_73 ;
while ( V_70 > V_72 ) {
V_71 = F_25 ( V_70 - V_72 , V_74 ) ;
V_39 = F_13 ( V_10 ) ;
if ( V_39 )
break;
F_7 ( V_71 , V_10 -> V_12 + V_75 ) ;
F_28 ( V_10 -> V_12 + V_80 , V_69 + V_72 , V_71 ) ;
V_73 = V_76 | V_77 |
V_81 ;
F_7 ( V_73 , V_10 -> V_12 + V_78 ) ;
V_39 = F_8 ( V_10 , V_79 , 0 ) ;
if ( V_39 )
break;
V_72 += V_71 ;
}
}
static T_3 F_29 ( struct V_30 * V_31 )
{
T_3 V_39 ;
F_24 ( V_31 , & V_39 , 1 ) ;
return V_39 ;
}
static void F_30 ( struct V_30 * V_31 , int V_82 ,
unsigned int V_6 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
int V_39 ;
T_2 V_73 ;
V_39 = F_13 ( V_10 ) ;
if ( V_39 )
return;
if ( V_6 & V_83 ) {
V_73 = F_5 ( V_10 -> V_12 + V_29 ) ;
if ( V_6 & V_84 )
V_73 |= V_85 ;
else
V_73 &= ~ V_85 ;
F_7 ( V_73 , V_10 -> V_12 + V_29 ) ;
}
if ( V_82 == V_86 )
return;
if ( V_6 & V_87 ) {
F_7 ( V_88 | V_82 , V_10 -> V_12 + V_78 ) ;
} else {
F_7 ( V_82 , V_10 -> V_12 + V_89 ) ;
F_7 ( V_90 , V_10 -> V_12 + V_78 ) ;
}
F_8 ( V_10 , V_79 , 0 ) ;
}
static void F_31 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_91 * V_92 = V_3 -> V_93 . V_32 ;
T_2 V_94 ;
V_94 = F_5 ( V_10 -> V_12 + V_27 ) ;
V_94 &= ~ ( V_95 | V_96 |
V_97 ) ;
V_94 |= V_98 | F_32 ( V_92 -> V_99 ) | V_100 ;
F_7 ( V_94 , V_10 -> V_12 + V_27 ) ;
}
static void F_33 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
F_7 ( F_5 ( V_10 -> V_12 + V_27 ) & ~ V_98 ,
V_10 -> V_12 + V_27 ) ;
}
static inline void F_34 ( T_2 V_101 , T_4 * V_69 )
{
V_69 [ 0 ] = V_101 ;
V_69 [ 1 ] = V_101 >> 8 ;
V_69 [ 2 ] = V_101 >> 16 ;
V_69 [ 3 ] = V_101 >> 24 ;
}
static int F_35 ( struct V_30 * V_31 ,
T_4 * V_92 , int V_102 ,
T_4 * V_103 , int V_104 ,
int * V_105 ,
unsigned int * V_106 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_107 * V_93 = & V_3 -> V_93 ;
T_2 V_108 ;
int V_39 ;
if ( * V_105 != V_102 )
V_3 -> V_109 ( V_31 , V_110 , V_102 , - 1 ) ;
F_24 ( V_31 , NULL , V_93 -> V_111 ) ;
if ( V_102 + V_93 -> V_111 != V_104 )
V_3 -> V_109 ( V_31 , V_110 , V_104 , - 1 ) ;
V_39 = F_13 ( V_10 ) ;
if ( V_39 )
return V_39 ;
F_7 ( V_76 | V_77 | V_112 ,
V_10 -> V_12 + V_78 ) ;
V_39 = F_8 ( V_10 , V_79 , 0 ) ;
if ( V_39 )
return V_39 ;
V_108 = F_5 ( V_10 -> V_12 + V_113 ) ;
V_39 = F_36 ( 0 , F_5 ( V_10 -> V_12 + F_37 ( 0 ) ) ) ;
F_26 ( V_92 , V_10 -> V_12 + V_80 , V_93 -> V_111 ) ;
V_3 -> V_109 ( V_31 , V_110 , V_104 , - 1 ) ;
F_24 ( V_31 , V_103 , V_93 -> V_114 + 4 ) ;
if ( V_108 & F_38 ( 0 ) ) {
V_39 = F_39 ( V_92 , V_93 -> V_111 ,
V_103 , V_93 -> V_114 + 4 ,
NULL , 0 , V_93 -> V_115 ) ;
} else {
F_34 ( F_5 ( V_10 -> V_12 + F_40 ( 0 ) ) ,
V_103 ) ;
}
if ( V_39 < 0 ) {
V_31 -> V_116 . V_117 ++ ;
} else {
V_31 -> V_116 . V_118 += V_39 ;
* V_106 = F_41 (unsigned int, *max_bitflips, ret) ;
}
* V_105 = V_104 + V_93 -> V_114 + 4 ;
return 0 ;
}
static void F_42 ( struct V_30 * V_31 ,
T_4 * V_103 , int * V_105 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_107 * V_93 = & V_3 -> V_93 ;
int V_119 = ( ( V_93 -> V_114 + 4 ) * V_93 -> V_120 ) ;
int V_70 = V_31 -> V_121 - V_119 ;
if ( V_70 <= 0 )
return;
if ( * V_105 != V_119 )
V_3 -> V_109 ( V_31 , V_110 ,
V_119 + V_31 -> V_61 , - 1 ) ;
F_24 ( V_31 , V_103 + V_119 , V_70 ) ;
* V_105 = V_31 -> V_121 + V_31 -> V_61 ;
}
static inline T_2 F_43 ( const T_4 * V_69 )
{
return V_69 [ 0 ] | ( V_69 [ 1 ] << 8 ) | ( V_69 [ 2 ] << 16 ) | ( V_69 [ 3 ] << 24 ) ;
}
static int F_44 ( struct V_30 * V_31 ,
const T_4 * V_92 , int V_102 ,
const T_4 * V_103 , int V_104 ,
int * V_105 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_107 * V_93 = & V_3 -> V_93 ;
int V_39 ;
if ( V_102 != * V_105 )
V_3 -> V_109 ( V_31 , V_122 , V_102 , - 1 ) ;
F_27 ( V_31 , V_92 , V_93 -> V_111 ) ;
F_7 ( F_43 ( V_103 ) ,
V_10 -> V_12 + F_40 ( 0 ) ) ;
if ( V_102 + V_93 -> V_111 != V_104 )
V_3 -> V_109 ( V_31 , V_122 , V_104 , - 1 ) ;
V_39 = F_13 ( V_10 ) ;
if ( V_39 )
return V_39 ;
F_7 ( V_76 | V_77 |
V_81 | V_112 ,
V_10 -> V_12 + V_78 ) ;
V_39 = F_8 ( V_10 , V_79 , 0 ) ;
if ( V_39 )
return V_39 ;
* V_105 = V_104 + V_93 -> V_114 + 4 ;
return 0 ;
}
static void F_45 ( struct V_30 * V_31 ,
T_4 * V_103 , int * V_105 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_107 * V_93 = & V_3 -> V_93 ;
int V_119 = ( ( V_93 -> V_114 + 4 ) * V_93 -> V_120 ) ;
int V_70 = V_31 -> V_121 - V_119 ;
if ( V_70 <= 0 )
return;
if ( * V_105 != V_119 )
V_3 -> V_109 ( V_31 , V_122 ,
V_119 + V_31 -> V_61 , - 1 ) ;
F_27 ( V_31 , V_103 + V_119 , V_70 ) ;
* V_105 = V_31 -> V_121 + V_31 -> V_61 ;
}
static int F_46 ( struct V_30 * V_31 ,
struct V_2 * V_49 , T_3 * V_69 ,
int V_123 , int V_124 )
{
struct V_107 * V_93 = & V_49 -> V_93 ;
unsigned int V_106 = 0 ;
int V_39 , V_125 , V_105 = 0 ;
F_31 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_93 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * V_93 -> V_111 ;
int V_104 = V_125 * ( V_93 -> V_114 + 4 ) ;
T_4 * V_92 = V_69 + V_102 ;
T_4 * V_103 = V_49 -> V_126 + V_104 ;
V_39 = F_35 ( V_31 , V_92 , V_102 , V_103 ,
V_104 + V_31 -> V_61 ,
& V_105 , & V_106 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_123 )
F_42 ( V_31 , V_49 -> V_126 , & V_105 ) ;
F_33 ( V_31 ) ;
return V_106 ;
}
static int F_47 ( struct V_30 * V_31 ,
struct V_2 * V_49 ,
const T_3 * V_69 , int V_123 ,
int V_124 )
{
struct V_107 * V_93 = & V_49 -> V_93 ;
int V_39 , V_125 , V_105 = 0 ;
F_31 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_93 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * V_93 -> V_111 ;
int V_104 = V_125 * ( V_93 -> V_114 + 4 ) ;
const T_4 * V_92 = V_69 + V_102 ;
const T_4 * V_103 = V_49 -> V_126 + V_104 ;
V_39 = F_44 ( V_31 , V_92 , V_102 , V_103 ,
V_104 + V_31 -> V_61 ,
& V_105 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_123 )
F_45 ( V_31 , V_49 -> V_126 , & V_105 ) ;
F_33 ( V_31 ) ;
return 0 ;
}
static int F_48 ( struct V_30 * V_31 ,
struct V_2 * V_49 ,
T_3 * V_69 , int V_123 ,
int V_124 )
{
struct V_107 * V_93 = & V_49 -> V_93 ;
unsigned int V_106 = 0 ;
int V_39 , V_125 , V_105 = 0 ;
F_31 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_93 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * ( V_93 -> V_111 + V_93 -> V_114 + 4 ) ;
int V_104 = V_102 + V_93 -> V_111 ;
T_4 * V_92 = V_69 + ( V_125 * V_93 -> V_111 ) ;
T_4 * V_103 = V_49 -> V_126 + ( V_125 * ( V_93 -> V_114 + 4 ) ) ;
V_39 = F_35 ( V_31 , V_92 , V_102 , V_103 ,
V_104 , & V_105 ,
& V_106 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_123 )
F_42 ( V_31 , V_49 -> V_126 , & V_105 ) ;
F_33 ( V_31 ) ;
return V_106 ;
}
static int F_49 ( struct V_30 * V_31 ,
struct V_2 * V_49 ,
const T_3 * V_69 ,
int V_123 , int V_124 )
{
struct V_107 * V_93 = & V_49 -> V_93 ;
int V_39 , V_125 , V_105 = 0 ;
F_31 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_93 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * ( V_93 -> V_111 + V_93 -> V_114 + 4 ) ;
int V_104 = V_102 + V_93 -> V_111 ;
const T_4 * V_92 = V_69 + ( V_125 * V_93 -> V_111 ) ;
const T_4 * V_103 = V_49 -> V_126 + ( V_125 * ( V_93 -> V_114 + 4 ) ) ;
V_39 = F_44 ( V_31 , V_92 , V_102 ,
V_103 , V_104 , & V_105 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_123 )
F_45 ( V_31 , V_49 -> V_126 , & V_105 ) ;
F_33 ( V_31 ) ;
return 0 ;
}
static int F_50 ( const T_5 * V_127 , int V_128 , T_2 V_129 ,
T_2 V_130 )
{
T_2 V_131 = F_51 ( V_129 , V_130 ) ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
if ( V_131 <= V_127 [ V_125 ] )
return V_125 ;
}
return - V_132 ;
}
static int F_52 ( struct V_1 * V_49 ,
const struct V_133 * V_134 )
{
struct V_4 * V_10 = F_3 ( V_49 -> V_3 . V_7 ) ;
T_2 V_135 = 0 ;
T_5 V_136 , V_137 , V_138 , V_139 , V_140 ;
if ( V_134 -> V_141 > V_135 )
V_135 = V_134 -> V_141 ;
if ( V_134 -> V_142 > V_135 )
V_135 = V_134 -> V_142 ;
if ( V_134 -> V_143 > V_135 )
V_135 = V_134 -> V_143 ;
if ( V_134 -> V_144 > V_135 )
V_135 = V_134 -> V_144 ;
if ( V_134 -> V_145 > V_135 )
V_135 = V_134 -> V_145 ;
if ( V_134 -> V_146 > V_135 )
V_135 = V_134 -> V_146 ;
if ( V_134 -> V_147 > V_135 )
V_135 = V_134 -> V_147 ;
if ( V_134 -> V_148 > V_135 )
V_135 = V_134 -> V_148 ;
if ( V_134 -> V_149 > V_135 )
V_135 = V_134 -> V_149 ;
if ( V_134 -> V_150 > ( V_135 * 3 ) )
V_135 = F_51 ( V_134 -> V_150 , 3 ) ;
if ( V_134 -> V_151 > V_135 )
V_135 = V_134 -> V_151 ;
if ( V_134 -> V_152 > V_135 )
V_135 = V_134 -> V_152 ;
if ( V_134 -> V_153 > V_135 )
V_135 = V_134 -> V_153 ;
if ( V_134 -> V_154 > ( V_135 * 2 ) )
V_135 = F_51 ( V_134 -> V_154 , 2 ) ;
if ( V_134 -> V_155 > ( V_135 * 2 ) )
V_135 = F_51 ( V_134 -> V_155 , 2 ) ;
V_136 = F_53 ( V_156 , V_134 -> V_157 ,
V_135 ) ;
if ( V_136 < 0 ) {
F_12 ( V_10 -> V_22 , L_5 ) ;
return V_136 ;
}
V_137 = F_51 ( V_134 -> V_158 , V_135 ) >> 3 ;
if ( V_137 > 3 ) {
F_12 ( V_10 -> V_22 , L_6 ) ;
return - V_132 ;
}
V_138 = F_51 ( V_134 -> V_159 , V_135 ) >> 3 ;
if ( V_138 > 3 ) {
F_12 ( V_10 -> V_22 , L_7 ) ;
return - V_132 ;
}
V_139 = F_53 ( V_160 , V_134 -> V_161 ,
V_135 ) ;
if ( V_139 < 0 ) {
F_12 ( V_10 -> V_22 , L_8 ) ;
return V_139 ;
}
V_140 = 0x7 ;
V_49 -> V_67 = F_54 ( V_136 , V_137 , V_138 , V_139 , V_140 ) ;
V_49 -> V_65 = ( V_134 -> V_154 < 30000 ) ? V_162 : 0 ;
V_135 = F_51 ( V_135 , 1000 ) ;
V_49 -> V_63 = ( 2 * V_163 ) / V_135 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_49 ,
struct V_164 * V_165 )
{
const struct V_133 * V_134 ;
int V_39 ;
int V_99 ;
V_99 = F_56 ( & V_49 -> V_3 ) ;
if ( V_99 == V_166 ) {
V_99 = V_49 -> V_3 . V_167 ;
} else {
T_3 V_168 [ V_169 ] = {} ;
int V_125 ;
V_99 = F_57 ( V_99 ) - 1 ;
if ( V_99 < 0 )
V_99 = 0 ;
V_168 [ 0 ] = V_99 ;
for ( V_125 = 0 ; V_125 < V_49 -> V_53 ; V_125 ++ ) {
V_49 -> V_3 . V_170 ( & V_49 -> V_31 , V_125 ) ;
V_39 = V_49 -> V_3 . V_171 ( & V_49 -> V_31 ,
& V_49 -> V_3 ,
V_172 ,
V_168 ) ;
V_49 -> V_3 . V_170 ( & V_49 -> V_31 , - 1 ) ;
if ( V_39 )
return V_39 ;
}
}
V_134 = F_58 ( V_99 ) ;
if ( F_59 ( V_134 ) )
return F_60 ( V_134 ) ;
return F_52 ( V_49 , V_134 ) ;
}
static int F_61 ( struct V_30 * V_31 ,
struct V_107 * V_93 ,
struct V_164 * V_165 )
{
static const T_4 V_173 [] = { 16 , 24 , 28 , 32 , 40 , 48 , 56 , 60 , 64 } ;
struct V_2 * V_3 = V_31 -> V_32 ;
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_33 -> V_3 . V_7 ) ;
struct V_91 * V_92 ;
struct V_174 * V_175 ;
int V_176 ;
int V_39 ;
int V_125 ;
V_92 = F_62 ( sizeof( * V_92 ) , V_177 ) ;
if ( ! V_92 )
return - V_178 ;
for ( V_125 = 0 ; V_125 < F_63 ( V_173 ) ; V_125 ++ ) {
if ( V_93 -> V_115 <= V_173 [ V_125 ] )
break;
}
if ( V_125 >= F_63 ( V_173 ) ) {
F_12 ( V_10 -> V_22 , L_9 ) ;
V_39 = - V_179 ;
goto V_180;
}
V_92 -> V_99 = V_125 ;
V_93 -> V_114 = F_51 ( V_93 -> V_115 * F_57 ( 8 * 1024 ) , 8 ) ;
V_93 -> V_114 = F_64 ( V_93 -> V_114 , 2 ) ;
V_175 = & V_92 -> V_175 ;
V_176 = V_31 -> V_61 / V_93 -> V_111 ;
if ( V_31 -> V_121 < ( ( V_93 -> V_114 + 4 ) * V_176 ) ) {
V_39 = - V_132 ;
goto V_180;
}
V_175 -> V_181 = ( V_93 -> V_114 * V_176 ) ;
V_93 -> V_175 = V_175 ;
V_93 -> V_32 = V_92 ;
return 0 ;
V_180:
F_65 ( V_92 ) ;
return V_39 ;
}
static void F_66 ( struct V_107 * V_93 )
{
F_65 ( V_93 -> V_32 ) ;
}
static int F_67 ( struct V_30 * V_31 ,
struct V_107 * V_93 ,
struct V_164 * V_165 )
{
struct V_174 * V_175 ;
int V_176 ;
int V_125 , V_182 ;
int V_39 ;
V_39 = F_61 ( V_31 , V_93 , V_165 ) ;
if ( V_39 )
return V_39 ;
V_93 -> V_183 = F_46 ;
V_93 -> V_184 = F_47 ;
V_175 = V_93 -> V_175 ;
V_176 = V_31 -> V_61 / V_93 -> V_111 ;
for ( V_125 = 0 ; V_125 < V_176 ; V_125 ++ ) {
if ( V_125 ) {
V_175 -> V_185 [ V_125 ] . V_119 =
V_175 -> V_185 [ V_125 - 1 ] . V_119 +
V_175 -> V_185 [ V_125 - 1 ] . V_186 +
V_93 -> V_114 ;
V_175 -> V_185 [ V_125 ] . V_186 = 4 ;
} else {
V_175 -> V_185 [ V_125 ] . V_186 = 2 ;
V_175 -> V_185 [ V_125 ] . V_119 = 2 ;
}
for ( V_182 = 0 ; V_182 < V_93 -> V_114 ; V_182 ++ )
V_175 -> V_187 [ ( V_93 -> V_114 * V_125 ) + V_182 ] =
V_175 -> V_185 [ V_125 ] . V_119 +
V_175 -> V_185 [ V_125 ] . V_186 + V_182 ;
}
if ( V_31 -> V_121 > ( V_93 -> V_114 + 4 ) * V_176 ) {
V_175 -> V_185 [ V_176 ] . V_119 =
V_175 -> V_185 [ V_176 - 1 ] . V_119 +
V_175 -> V_185 [ V_176 - 1 ] . V_186 +
V_93 -> V_114 ;
V_175 -> V_185 [ V_176 ] . V_186 = V_31 -> V_121 -
( ( V_93 -> V_114 + 4 ) * V_176 ) ;
}
return 0 ;
}
static int F_68 ( struct V_30 * V_31 ,
struct V_107 * V_93 ,
struct V_164 * V_165 )
{
struct V_174 * V_175 ;
int V_176 ;
int V_125 ;
int V_39 ;
V_39 = F_61 ( V_31 , V_93 , V_165 ) ;
if ( V_39 )
return V_39 ;
V_93 -> V_188 = 4 ;
V_93 -> V_183 = F_48 ;
V_93 -> V_184 = F_49 ;
V_175 = V_93 -> V_175 ;
V_176 = V_31 -> V_61 / V_93 -> V_111 ;
for ( V_125 = 0 ; V_125 < ( V_93 -> V_114 * V_176 ) ; V_125 ++ )
V_175 -> V_187 [ V_125 ] = V_125 ;
V_175 -> V_185 [ 0 ] . V_186 = V_31 -> V_121 - V_125 ;
V_175 -> V_185 [ 0 ] . V_119 = V_125 ;
return 0 ;
}
static void F_69 ( struct V_107 * V_93 )
{
switch ( V_93 -> V_99 ) {
case V_189 :
case V_190 :
F_66 ( V_93 ) ;
break;
case V_191 :
F_65 ( V_93 -> V_175 ) ;
default:
break;
}
}
static int F_70 ( struct V_30 * V_31 , struct V_107 * V_93 ,
struct V_164 * V_165 )
{
struct V_2 * V_3 = V_31 -> V_32 ;
int V_39 ;
if ( ! V_93 -> V_111 ) {
V_93 -> V_111 = V_3 -> V_192 ;
V_93 -> V_115 = V_3 -> V_193 ;
}
if ( ! V_93 -> V_111 || ! V_93 -> V_115 )
return - V_132 ;
switch ( V_93 -> V_99 ) {
case V_194 :
break;
case V_189 :
V_39 = F_67 ( V_31 , V_93 , V_165 ) ;
if ( V_39 )
return V_39 ;
break;
case V_190 :
V_39 = F_68 ( V_31 , V_93 , V_165 ) ;
if ( V_39 )
return V_39 ;
break;
case V_191 :
V_93 -> V_175 = F_62 ( sizeof( * V_93 -> V_175 ) , V_177 ) ;
if ( ! V_93 -> V_175 )
return - V_178 ;
V_93 -> V_175 -> V_185 [ 0 ] . V_186 = V_31 -> V_121 ;
case V_195 :
break;
default:
return - V_132 ;
}
return 0 ;
}
static int F_71 ( struct V_196 * V_22 , struct V_4 * V_10 ,
struct V_164 * V_165 )
{
const struct V_133 * V_134 ;
struct V_1 * V_49 ;
struct V_197 V_198 ;
struct V_30 * V_31 ;
struct V_2 * V_3 ;
int V_53 ;
int V_39 ;
int V_125 ;
T_2 V_73 ;
if ( ! F_72 ( V_165 , L_10 , & V_53 ) )
return - V_132 ;
V_53 /= sizeof( T_2 ) ;
if ( ! V_53 ) {
F_12 ( V_22 , L_11 ) ;
return - V_132 ;
}
V_49 = F_73 ( V_22 ,
sizeof( * V_49 ) +
( V_53 * sizeof( struct V_50 ) ) ,
V_177 ) ;
if ( ! V_49 ) {
F_12 ( V_22 , L_12 ) ;
return - V_178 ;
}
V_49 -> V_53 = V_53 ;
V_49 -> V_40 = - 1 ;
for ( V_125 = 0 ; V_125 < V_53 ; V_125 ++ ) {
V_39 = F_74 ( V_165 , L_10 , V_125 , & V_73 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_13 ,
V_39 ) ;
return V_39 ;
}
if ( V_73 > V_199 ) {
F_12 ( V_22 ,
L_14 ,
V_73 ) ;
return - V_132 ;
}
if ( F_75 ( V_73 , & V_10 -> V_200 ) ) {
F_12 ( V_22 , L_15 , V_73 ) ;
return - V_132 ;
}
V_49 -> V_41 [ V_125 ] . V_58 = V_73 ;
if ( ! F_74 ( V_165 , L_16 , V_125 , & V_73 ) &&
V_73 < 2 ) {
V_49 -> V_41 [ V_125 ] . V_35 . type = V_42 ;
V_49 -> V_41 [ V_125 ] . V_35 . V_43 . V_44 = V_73 ;
} else {
V_39 = F_76 ( V_165 , L_17 , V_125 ) ;
if ( V_39 >= 0 ) {
V_73 = V_39 ;
V_49 -> V_41 [ V_125 ] . V_35 . type = V_46 ;
V_49 -> V_41 [ V_125 ] . V_35 . V_43 . V_47 = V_73 ;
V_39 = F_77 ( V_22 , V_73 , L_18 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_78 ( V_73 ) ;
if ( V_39 )
return V_39 ;
} else {
V_49 -> V_41 [ V_125 ] . V_35 . type = V_48 ;
}
}
}
V_134 = F_58 ( 0 ) ;
if ( F_59 ( V_134 ) ) {
V_39 = F_60 ( V_134 ) ;
F_12 ( V_22 ,
L_19 ,
V_39 ) ;
return V_39 ;
}
V_39 = F_52 ( V_49 , V_134 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_20 , V_39 ) ;
return V_39 ;
}
V_3 = & V_49 -> V_3 ;
V_3 -> V_201 = 200 ;
V_3 -> V_7 = & V_10 -> V_7 ;
V_3 -> V_93 . V_99 = V_189 ;
V_3 -> V_202 = V_165 ;
V_3 -> V_170 = F_19 ;
V_3 -> V_203 = F_30 ;
V_3 -> V_204 = F_24 ;
V_3 -> V_205 = F_27 ;
V_3 -> V_206 = F_29 ;
V_31 = & V_49 -> V_31 ;
V_31 -> V_22 . V_207 = V_22 ;
V_31 -> V_32 = V_3 ;
V_39 = F_79 ( V_31 , V_53 , NULL ) ;
if ( V_39 )
return V_39 ;
if ( V_3 -> V_208 & V_209 )
V_3 -> V_208 |= V_210 ;
V_39 = F_55 ( V_49 , V_165 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_20 , V_39 ) ;
return V_39 ;
}
V_39 = F_70 ( V_31 , & V_3 -> V_93 , V_165 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_21 , V_39 ) ;
return V_39 ;
}
V_39 = F_80 ( V_31 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_22 , V_39 ) ;
return V_39 ;
}
V_198 . V_211 = V_165 ;
V_39 = F_81 ( V_31 , NULL , & V_198 , NULL , 0 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_23 , V_39 ) ;
F_82 ( V_31 ) ;
return V_39 ;
}
F_83 ( & V_49 -> V_212 , & V_10 -> V_213 ) ;
return 0 ;
}
static int F_84 ( struct V_196 * V_22 , struct V_4 * V_10 )
{
struct V_164 * V_165 = V_22 -> V_211 ;
struct V_164 * V_214 ;
int V_215 = F_85 ( V_165 ) ;
int V_39 ;
if ( V_215 > 8 ) {
F_12 ( V_22 , L_24 , V_215 ) ;
return - V_132 ;
}
F_86 (np, nand_np) {
V_39 = F_71 ( V_22 , V_10 , V_214 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
static void F_87 ( struct V_4 * V_10 )
{
struct V_1 * V_49 ;
while ( ! F_88 ( & V_10 -> V_213 ) ) {
V_49 = F_89 ( & V_10 -> V_213 , struct V_1 ,
V_212 ) ;
F_82 ( & V_49 -> V_31 ) ;
F_69 ( & V_49 -> V_3 . V_93 ) ;
F_90 ( & V_49 -> V_212 ) ;
}
}
static int F_91 ( struct V_216 * V_217 )
{
struct V_196 * V_22 = & V_217 -> V_22 ;
struct V_218 * V_219 ;
struct V_4 * V_10 ;
int V_8 ;
int V_39 ;
V_10 = F_73 ( V_22 , sizeof( * V_10 ) , V_177 ) ;
if ( ! V_10 )
return - V_178 ;
V_10 -> V_22 = V_22 ;
F_92 ( & V_10 -> V_7 . V_220 ) ;
F_93 ( & V_10 -> V_7 . V_221 ) ;
F_94 ( & V_10 -> V_213 ) ;
V_219 = F_95 ( V_217 , V_222 , 0 ) ;
V_10 -> V_12 = F_96 ( V_22 , V_219 ) ;
if ( F_59 ( V_10 -> V_12 ) )
return F_60 ( V_10 -> V_12 ) ;
V_8 = F_97 ( V_217 , 0 ) ;
if ( V_8 < 0 ) {
F_12 ( V_22 , L_25 ) ;
return V_8 ;
}
V_10 -> V_223 = F_98 ( V_22 , L_26 ) ;
if ( F_59 ( V_10 -> V_223 ) ) {
F_12 ( V_22 , L_27 ) ;
return F_60 ( V_10 -> V_223 ) ;
}
V_39 = F_99 ( V_10 -> V_223 ) ;
if ( V_39 )
return V_39 ;
V_10 -> V_64 = F_98 ( V_22 , L_28 ) ;
if ( F_59 ( V_10 -> V_64 ) ) {
F_12 ( V_22 , L_29 ) ;
V_39 = F_60 ( V_10 -> V_64 ) ;
goto V_224;
}
V_39 = F_99 ( V_10 -> V_64 ) ;
if ( V_39 )
goto V_224;
V_39 = F_15 ( V_10 ) ;
if ( V_39 )
goto V_225;
F_7 ( 0 , V_10 -> V_12 + V_15 ) ;
V_39 = F_100 ( V_22 , V_8 , F_4 ,
0 , L_30 , V_10 ) ;
if ( V_39 )
goto V_225;
F_101 ( V_217 , V_10 ) ;
V_39 = F_84 ( V_22 , V_10 ) ;
if ( V_39 ) {
F_12 ( V_22 , L_31 ) ;
goto V_225;
}
return 0 ;
V_225:
F_102 ( V_10 -> V_64 ) ;
V_224:
F_102 ( V_10 -> V_223 ) ;
return V_39 ;
}
static int F_103 ( struct V_216 * V_217 )
{
struct V_4 * V_10 = F_104 ( V_217 ) ;
F_87 ( V_10 ) ;
return 0 ;
}
