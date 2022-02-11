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
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_33 * V_34 ;
unsigned long V_35 = ( V_32 -> V_3 . V_36 == V_37 ? 400 : 20 ) ;
int V_38 ;
if ( V_32 -> V_39 < 0 )
return 0 ;
V_34 = & V_32 -> V_40 [ V_32 -> V_39 ] . V_34 ;
switch ( V_34 -> type ) {
case V_41 :
V_38 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_18 ( V_34 -> V_42 . V_43 ) ) ;
if ( V_38 )
break;
F_8 ( V_10 , V_44 , V_35 ) ;
V_38 = ! ! ( F_5 ( V_10 -> V_12 + V_13 ) &
F_18 ( V_34 -> V_42 . V_43 ) ) ;
break;
case V_45 :
V_38 = F_19 ( V_34 -> V_42 . V_46 ) ;
break;
case V_47 :
default:
V_38 = 0 ;
F_12 ( V_10 -> V_22 , L_4 ) ;
break;
}
return V_38 ;
}
static void F_20 ( struct V_30 * V_31 , int V_48 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_49 * V_50 ;
T_2 V_51 ;
if ( V_48 > 0 && V_48 >= V_32 -> V_52 )
return;
if ( V_48 == V_32 -> V_39 )
return;
V_51 = F_5 ( V_10 -> V_12 + V_29 ) &
~ ( V_53 | V_54 | V_55 | V_56 ) ;
if ( V_48 >= 0 ) {
V_50 = & V_32 -> V_40 [ V_48 ] ;
V_51 |= F_21 ( V_50 -> V_57 ) | V_56 |
F_22 ( V_3 -> V_58 - 10 ) ;
if ( V_50 -> V_34 . type == V_47 ) {
V_3 -> V_59 = NULL ;
} else {
V_3 -> V_59 = F_16 ;
if ( V_50 -> V_34 . type == V_41 )
V_51 |= F_23 ( V_50 -> V_34 . V_42 . V_43 ) ;
}
F_7 ( V_31 -> V_60 , V_10 -> V_12 + V_61 ) ;
if ( V_10 -> V_62 != V_32 -> V_62 ) {
F_24 ( V_10 -> V_63 , V_32 -> V_62 ) ;
V_10 -> V_62 = V_32 -> V_62 ;
}
}
F_7 ( V_32 -> V_64 , V_10 -> V_12 + V_65 ) ;
F_7 ( V_32 -> V_66 , V_10 -> V_12 + V_67 ) ;
F_7 ( V_51 , V_10 -> V_12 + V_29 ) ;
V_32 -> V_39 = V_48 ;
}
static void F_25 ( struct V_30 * V_31 , T_3 * V_68 , int V_69 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
int V_70 ;
int V_71 = 0 ;
T_2 V_72 ;
while ( V_69 > V_71 ) {
V_70 = F_26 ( V_69 - V_71 , V_73 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
break;
F_7 ( V_70 , V_10 -> V_12 + V_74 ) ;
V_72 = V_75 | V_76 ;
F_7 ( V_72 , V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
break;
if ( V_68 )
F_27 ( V_68 + V_71 , V_10 -> V_12 + V_79 ,
V_70 ) ;
V_71 += V_70 ;
}
}
static void F_28 ( struct V_30 * V_31 , const T_3 * V_68 ,
int V_69 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
int V_70 ;
int V_71 = 0 ;
T_2 V_72 ;
while ( V_69 > V_71 ) {
V_70 = F_26 ( V_69 - V_71 , V_73 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
break;
F_7 ( V_70 , V_10 -> V_12 + V_74 ) ;
F_29 ( V_10 -> V_12 + V_79 , V_68 + V_71 , V_70 ) ;
V_72 = V_75 | V_76 |
V_80 ;
F_7 ( V_72 , V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
break;
V_71 += V_70 ;
}
}
static T_3 F_30 ( struct V_30 * V_31 )
{
T_3 V_38 ;
F_25 ( V_31 , & V_38 , 1 ) ;
return V_38 ;
}
static void F_31 ( struct V_30 * V_31 , int V_81 ,
unsigned int V_6 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
int V_38 ;
T_2 V_72 ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return;
if ( V_6 & V_82 ) {
V_72 = F_5 ( V_10 -> V_12 + V_29 ) ;
if ( V_6 & V_83 )
V_72 |= V_84 ;
else
V_72 &= ~ V_84 ;
F_7 ( V_72 , V_10 -> V_12 + V_29 ) ;
}
if ( V_81 == V_85 )
return;
if ( V_6 & V_86 ) {
F_7 ( V_87 | V_81 , V_10 -> V_12 + V_77 ) ;
} else {
F_7 ( V_81 , V_10 -> V_12 + V_88 ) ;
F_7 ( V_89 , V_10 -> V_12 + V_77 ) ;
}
F_8 ( V_10 , V_78 , 0 ) ;
}
static void F_32 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_90 * V_91 = V_3 -> V_92 . V_93 ;
T_2 V_94 ;
V_94 = F_5 ( V_10 -> V_12 + V_27 ) ;
V_94 &= ~ ( V_95 | V_96 |
V_97 ) ;
V_94 |= V_98 | F_33 ( V_91 -> V_99 ) | V_100 ;
F_7 ( V_94 , V_10 -> V_12 + V_27 ) ;
}
static void F_34 ( struct V_30 * V_31 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
F_7 ( F_5 ( V_10 -> V_12 + V_27 ) & ~ V_98 ,
V_10 -> V_12 + V_27 ) ;
}
static inline void F_35 ( T_2 V_101 , T_4 * V_68 )
{
V_68 [ 0 ] = V_101 ;
V_68 [ 1 ] = V_101 >> 8 ;
V_68 [ 2 ] = V_101 >> 16 ;
V_68 [ 3 ] = V_101 >> 24 ;
}
static int F_36 ( struct V_30 * V_31 ,
T_4 * V_91 , int V_102 ,
T_4 * V_103 , int V_104 ,
int * V_105 ,
unsigned int * V_106 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_107 * V_92 = & V_3 -> V_92 ;
T_2 V_108 ;
int V_38 ;
if ( * V_105 != V_102 )
V_3 -> V_109 ( V_31 , V_110 , V_102 , - 1 ) ;
F_25 ( V_31 , NULL , V_92 -> V_111 ) ;
if ( V_102 + V_92 -> V_111 != V_104 )
V_3 -> V_109 ( V_31 , V_110 , V_104 , - 1 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return V_38 ;
F_7 ( V_75 | V_76 | V_112 ,
V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
return V_38 ;
V_108 = F_5 ( V_10 -> V_12 + V_113 ) ;
V_38 = F_37 ( 0 , F_5 ( V_10 -> V_12 + F_38 ( 0 ) ) ) ;
F_27 ( V_91 , V_10 -> V_12 + V_79 , V_92 -> V_111 ) ;
V_3 -> V_109 ( V_31 , V_110 , V_104 , - 1 ) ;
F_25 ( V_31 , V_103 , V_92 -> V_114 + 4 ) ;
if ( V_108 & F_39 ( 0 ) ) {
V_38 = F_40 ( V_91 , V_92 -> V_111 ,
V_103 , V_92 -> V_114 + 4 ,
NULL , 0 , V_92 -> V_115 ) ;
} else {
F_35 ( F_5 ( V_10 -> V_12 + F_41 ( 0 ) ) ,
V_103 ) ;
}
if ( V_38 < 0 ) {
V_31 -> V_116 . V_117 ++ ;
} else {
V_31 -> V_116 . V_118 += V_38 ;
* V_106 = F_42 (unsigned int, *max_bitflips, ret) ;
}
* V_105 = V_104 + V_92 -> V_114 + 4 ;
return 0 ;
}
static void F_43 ( struct V_30 * V_31 ,
T_4 * V_103 , int * V_105 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_107 * V_92 = & V_3 -> V_92 ;
int V_119 = ( ( V_92 -> V_114 + 4 ) * V_92 -> V_120 ) ;
int V_69 = V_31 -> V_121 - V_119 ;
if ( V_69 <= 0 )
return;
if ( * V_105 != V_119 )
V_3 -> V_109 ( V_31 , V_110 ,
V_119 + V_31 -> V_60 , - 1 ) ;
F_25 ( V_31 , V_103 + V_119 , V_69 ) ;
* V_105 = V_31 -> V_121 + V_31 -> V_60 ;
}
static inline T_2 F_44 ( const T_4 * V_68 )
{
return V_68 [ 0 ] | ( V_68 [ 1 ] << 8 ) | ( V_68 [ 2 ] << 16 ) | ( V_68 [ 3 ] << 24 ) ;
}
static int F_45 ( struct V_30 * V_31 ,
const T_4 * V_91 , int V_102 ,
const T_4 * V_103 , int V_104 ,
int * V_105 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_4 * V_10 = F_3 ( V_3 -> V_7 ) ;
struct V_107 * V_92 = & V_3 -> V_92 ;
int V_38 ;
if ( V_102 != * V_105 )
V_3 -> V_109 ( V_31 , V_122 , V_102 , - 1 ) ;
F_28 ( V_31 , V_91 , V_92 -> V_111 ) ;
F_7 ( F_44 ( V_103 ) ,
V_10 -> V_12 + F_41 ( 0 ) ) ;
if ( V_102 + V_92 -> V_111 != V_104 )
V_3 -> V_109 ( V_31 , V_122 , V_104 , - 1 ) ;
V_38 = F_13 ( V_10 ) ;
if ( V_38 )
return V_38 ;
F_7 ( V_75 | V_76 |
V_80 | V_112 ,
V_10 -> V_12 + V_77 ) ;
V_38 = F_8 ( V_10 , V_78 , 0 ) ;
if ( V_38 )
return V_38 ;
* V_105 = V_104 + V_92 -> V_114 + 4 ;
return 0 ;
}
static void F_46 ( struct V_30 * V_31 ,
T_4 * V_103 , int * V_105 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_107 * V_92 = & V_3 -> V_92 ;
int V_119 = ( ( V_92 -> V_114 + 4 ) * V_92 -> V_120 ) ;
int V_69 = V_31 -> V_121 - V_119 ;
if ( V_69 <= 0 )
return;
if ( * V_105 != V_119 )
V_3 -> V_109 ( V_31 , V_122 ,
V_119 + V_31 -> V_60 , - 1 ) ;
F_28 ( V_31 , V_103 + V_119 , V_69 ) ;
* V_105 = V_31 -> V_121 + V_31 -> V_60 ;
}
static int F_47 ( struct V_30 * V_31 ,
struct V_2 * V_48 , T_3 * V_68 ,
int V_123 , int V_124 )
{
struct V_107 * V_92 = & V_48 -> V_92 ;
unsigned int V_106 = 0 ;
int V_38 , V_125 , V_105 = 0 ;
F_32 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_92 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * V_92 -> V_111 ;
int V_104 = V_125 * ( V_92 -> V_114 + 4 ) ;
T_4 * V_91 = V_68 + V_102 ;
T_4 * V_103 = V_48 -> V_126 + V_104 ;
V_38 = F_36 ( V_31 , V_91 , V_102 , V_103 ,
V_104 + V_31 -> V_60 ,
& V_105 , & V_106 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_123 )
F_43 ( V_31 , V_48 -> V_126 , & V_105 ) ;
F_34 ( V_31 ) ;
return V_106 ;
}
static int F_48 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
const T_3 * V_68 , int V_123 ,
int V_124 )
{
struct V_107 * V_92 = & V_48 -> V_92 ;
int V_38 , V_125 , V_105 = 0 ;
F_32 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_92 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * V_92 -> V_111 ;
int V_104 = V_125 * ( V_92 -> V_114 + 4 ) ;
const T_4 * V_91 = V_68 + V_102 ;
const T_4 * V_103 = V_48 -> V_126 + V_104 ;
V_38 = F_45 ( V_31 , V_91 , V_102 , V_103 ,
V_104 + V_31 -> V_60 ,
& V_105 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_123 )
F_46 ( V_31 , V_48 -> V_126 , & V_105 ) ;
F_34 ( V_31 ) ;
return 0 ;
}
static int F_49 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
T_3 * V_68 , int V_123 ,
int V_124 )
{
struct V_107 * V_92 = & V_48 -> V_92 ;
unsigned int V_106 = 0 ;
int V_38 , V_125 , V_105 = 0 ;
F_32 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_92 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * ( V_92 -> V_111 + V_92 -> V_114 + 4 ) ;
int V_104 = V_102 + V_92 -> V_111 ;
T_4 * V_91 = V_68 + ( V_125 * V_92 -> V_111 ) ;
T_4 * V_103 = V_48 -> V_126 + ( V_125 * ( V_92 -> V_114 + 4 ) ) ;
V_38 = F_36 ( V_31 , V_91 , V_102 , V_103 ,
V_104 , & V_105 ,
& V_106 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_123 )
F_43 ( V_31 , V_48 -> V_126 , & V_105 ) ;
F_34 ( V_31 ) ;
return V_106 ;
}
static int F_50 ( struct V_30 * V_31 ,
struct V_2 * V_48 ,
const T_3 * V_68 ,
int V_123 , int V_124 )
{
struct V_107 * V_92 = & V_48 -> V_92 ;
int V_38 , V_125 , V_105 = 0 ;
F_32 ( V_31 ) ;
for ( V_125 = 0 ; V_125 < V_92 -> V_120 ; V_125 ++ ) {
int V_102 = V_125 * ( V_92 -> V_111 + V_92 -> V_114 + 4 ) ;
int V_104 = V_102 + V_92 -> V_111 ;
const T_4 * V_91 = V_68 + ( V_125 * V_92 -> V_111 ) ;
const T_4 * V_103 = V_48 -> V_126 + ( V_125 * ( V_92 -> V_114 + 4 ) ) ;
V_38 = F_45 ( V_31 , V_91 , V_102 ,
V_103 , V_104 , & V_105 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_123 )
F_46 ( V_31 , V_48 -> V_126 , & V_105 ) ;
F_34 ( V_31 ) ;
return 0 ;
}
static int F_51 ( const T_5 * V_127 , int V_128 , T_2 V_129 ,
T_2 V_130 )
{
T_2 V_131 = F_52 ( V_129 , V_130 ) ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_128 ; V_125 ++ ) {
if ( V_131 <= V_127 [ V_125 ] )
return V_125 ;
}
return - V_132 ;
}
static int F_53 ( struct V_1 * V_48 ,
const struct V_133 * V_134 )
{
struct V_4 * V_10 = F_3 ( V_48 -> V_3 . V_7 ) ;
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
V_135 = F_52 ( V_134 -> V_150 , 3 ) ;
if ( V_134 -> V_151 > V_135 )
V_135 = V_134 -> V_151 ;
if ( V_134 -> V_152 > V_135 )
V_135 = V_134 -> V_152 ;
if ( V_134 -> V_153 > V_135 )
V_135 = V_134 -> V_153 ;
if ( V_134 -> V_154 > ( V_135 * 2 ) )
V_135 = F_52 ( V_134 -> V_154 , 2 ) ;
if ( V_134 -> V_155 > ( V_135 * 2 ) )
V_135 = F_52 ( V_134 -> V_155 , 2 ) ;
V_136 = F_54 ( V_156 , V_134 -> V_157 ,
V_135 ) ;
if ( V_136 < 0 ) {
F_12 ( V_10 -> V_22 , L_5 ) ;
return V_136 ;
}
V_137 = F_52 ( V_134 -> V_158 , V_135 ) >> 3 ;
if ( V_137 > 3 ) {
F_12 ( V_10 -> V_22 , L_6 ) ;
return - V_132 ;
}
V_138 = F_52 ( V_134 -> V_159 , V_135 ) >> 3 ;
if ( V_138 > 3 ) {
F_12 ( V_10 -> V_22 , L_7 ) ;
return - V_132 ;
}
V_139 = F_54 ( V_160 , V_134 -> V_161 ,
V_135 ) ;
if ( V_139 < 0 ) {
F_12 ( V_10 -> V_22 , L_8 ) ;
return V_139 ;
}
V_140 = 0x7 ;
V_48 -> V_66 = F_55 ( V_136 , V_137 , V_138 , V_139 , V_140 ) ;
V_48 -> V_64 = ( V_134 -> V_154 < 30000 ) ? V_162 : 0 ;
V_135 = F_52 ( V_135 , 1000 ) ;
V_48 -> V_62 = ( 2 * V_163 ) / V_135 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_48 ,
struct V_164 * V_165 )
{
struct V_30 * V_31 = F_57 ( & V_48 -> V_3 ) ;
const struct V_133 * V_134 ;
int V_38 ;
int V_99 ;
V_99 = F_58 ( & V_48 -> V_3 ) ;
if ( V_99 == V_166 ) {
V_99 = V_48 -> V_3 . V_167 ;
} else {
T_3 V_168 [ V_169 ] = {} ;
int V_125 ;
V_99 = F_59 ( V_99 ) - 1 ;
if ( V_99 < 0 )
V_99 = 0 ;
V_168 [ 0 ] = V_99 ;
for ( V_125 = 0 ; V_125 < V_48 -> V_52 ; V_125 ++ ) {
V_48 -> V_3 . V_170 ( V_31 , V_125 ) ;
V_38 = V_48 -> V_3 . V_171 ( V_31 , & V_48 -> V_3 ,
V_172 ,
V_168 ) ;
V_48 -> V_3 . V_170 ( V_31 , - 1 ) ;
if ( V_38 )
return V_38 ;
}
}
V_134 = F_60 ( V_99 ) ;
if ( F_61 ( V_134 ) )
return F_62 ( V_134 ) ;
return F_53 ( V_48 , V_134 ) ;
}
static int F_63 ( struct V_30 * V_31 ,
struct V_107 * V_92 ,
struct V_164 * V_165 )
{
static const T_4 V_173 [] = { 16 , 24 , 28 , 32 , 40 , 48 , 56 , 60 , 64 } ;
struct V_2 * V_3 = F_17 ( V_31 ) ;
struct V_1 * V_32 = F_1 ( V_3 ) ;
struct V_4 * V_10 = F_3 ( V_32 -> V_3 . V_7 ) ;
struct V_90 * V_91 ;
struct V_174 * V_175 ;
int V_176 ;
int V_38 ;
int V_125 ;
V_91 = F_64 ( sizeof( * V_91 ) , V_177 ) ;
if ( ! V_91 )
return - V_178 ;
for ( V_125 = 0 ; V_125 < F_65 ( V_173 ) ; V_125 ++ ) {
if ( V_92 -> V_115 <= V_173 [ V_125 ] )
break;
}
if ( V_125 >= F_65 ( V_173 ) ) {
F_12 ( V_10 -> V_22 , L_9 ) ;
V_38 = - V_179 ;
goto V_180;
}
V_91 -> V_99 = V_125 ;
V_92 -> V_114 = F_52 ( V_92 -> V_115 * F_59 ( 8 * 1024 ) , 8 ) ;
V_92 -> V_114 = F_66 ( V_92 -> V_114 , 2 ) ;
V_175 = & V_91 -> V_175 ;
V_176 = V_31 -> V_60 / V_92 -> V_111 ;
if ( V_31 -> V_121 < ( ( V_92 -> V_114 + 4 ) * V_176 ) ) {
V_38 = - V_132 ;
goto V_180;
}
V_175 -> V_181 = ( V_92 -> V_114 * V_176 ) ;
V_92 -> V_175 = V_175 ;
V_92 -> V_93 = V_91 ;
return 0 ;
V_180:
F_67 ( V_91 ) ;
return V_38 ;
}
static void F_68 ( struct V_107 * V_92 )
{
F_67 ( V_92 -> V_93 ) ;
}
static int F_69 ( struct V_30 * V_31 ,
struct V_107 * V_92 ,
struct V_164 * V_165 )
{
struct V_174 * V_175 ;
int V_176 ;
int V_125 , V_182 ;
int V_38 ;
V_38 = F_63 ( V_31 , V_92 , V_165 ) ;
if ( V_38 )
return V_38 ;
V_92 -> V_183 = F_47 ;
V_92 -> V_184 = F_48 ;
V_175 = V_92 -> V_175 ;
V_176 = V_31 -> V_60 / V_92 -> V_111 ;
for ( V_125 = 0 ; V_125 < V_176 ; V_125 ++ ) {
if ( V_125 ) {
V_175 -> V_185 [ V_125 ] . V_119 =
V_175 -> V_185 [ V_125 - 1 ] . V_119 +
V_175 -> V_185 [ V_125 - 1 ] . V_186 +
V_92 -> V_114 ;
V_175 -> V_185 [ V_125 ] . V_186 = 4 ;
} else {
V_175 -> V_185 [ V_125 ] . V_186 = 2 ;
V_175 -> V_185 [ V_125 ] . V_119 = 2 ;
}
for ( V_182 = 0 ; V_182 < V_92 -> V_114 ; V_182 ++ )
V_175 -> V_187 [ ( V_92 -> V_114 * V_125 ) + V_182 ] =
V_175 -> V_185 [ V_125 ] . V_119 +
V_175 -> V_185 [ V_125 ] . V_186 + V_182 ;
}
if ( V_31 -> V_121 > ( V_92 -> V_114 + 4 ) * V_176 ) {
V_175 -> V_185 [ V_176 ] . V_119 =
V_175 -> V_185 [ V_176 - 1 ] . V_119 +
V_175 -> V_185 [ V_176 - 1 ] . V_186 +
V_92 -> V_114 ;
V_175 -> V_185 [ V_176 ] . V_186 = V_31 -> V_121 -
( ( V_92 -> V_114 + 4 ) * V_176 ) ;
}
return 0 ;
}
static int F_70 ( struct V_30 * V_31 ,
struct V_107 * V_92 ,
struct V_164 * V_165 )
{
struct V_174 * V_175 ;
int V_176 ;
int V_125 ;
int V_38 ;
V_38 = F_63 ( V_31 , V_92 , V_165 ) ;
if ( V_38 )
return V_38 ;
V_92 -> V_188 = 4 ;
V_92 -> V_183 = F_49 ;
V_92 -> V_184 = F_50 ;
V_175 = V_92 -> V_175 ;
V_176 = V_31 -> V_60 / V_92 -> V_111 ;
for ( V_125 = 0 ; V_125 < ( V_92 -> V_114 * V_176 ) ; V_125 ++ )
V_175 -> V_187 [ V_125 ] = V_125 ;
V_175 -> V_185 [ 0 ] . V_186 = V_31 -> V_121 - V_125 ;
V_175 -> V_185 [ 0 ] . V_119 = V_125 ;
return 0 ;
}
static void F_71 ( struct V_107 * V_92 )
{
switch ( V_92 -> V_99 ) {
case V_189 :
case V_190 :
F_68 ( V_92 ) ;
break;
case V_191 :
F_67 ( V_92 -> V_175 ) ;
default:
break;
}
}
static int F_72 ( struct V_30 * V_31 , struct V_107 * V_92 ,
struct V_164 * V_165 )
{
struct V_2 * V_3 = F_17 ( V_31 ) ;
int V_38 ;
if ( ! V_92 -> V_111 ) {
V_92 -> V_111 = V_3 -> V_192 ;
V_92 -> V_115 = V_3 -> V_193 ;
}
if ( ! V_92 -> V_111 || ! V_92 -> V_115 )
return - V_132 ;
switch ( V_92 -> V_99 ) {
case V_194 :
break;
case V_189 :
V_38 = F_69 ( V_31 , V_92 , V_165 ) ;
if ( V_38 )
return V_38 ;
break;
case V_190 :
V_38 = F_70 ( V_31 , V_92 , V_165 ) ;
if ( V_38 )
return V_38 ;
break;
case V_191 :
V_92 -> V_175 = F_64 ( sizeof( * V_92 -> V_175 ) , V_177 ) ;
if ( ! V_92 -> V_175 )
return - V_178 ;
V_92 -> V_175 -> V_185 [ 0 ] . V_186 = V_31 -> V_121 ;
case V_195 :
break;
default:
return - V_132 ;
}
return 0 ;
}
static int F_73 ( struct V_196 * V_22 , struct V_4 * V_10 ,
struct V_164 * V_165 )
{
const struct V_133 * V_134 ;
struct V_1 * V_48 ;
struct V_30 * V_31 ;
struct V_2 * V_3 ;
int V_52 ;
int V_38 ;
int V_125 ;
T_2 V_72 ;
if ( ! F_74 ( V_165 , L_10 , & V_52 ) )
return - V_132 ;
V_52 /= sizeof( T_2 ) ;
if ( ! V_52 ) {
F_12 ( V_22 , L_11 ) ;
return - V_132 ;
}
V_48 = F_75 ( V_22 ,
sizeof( * V_48 ) +
( V_52 * sizeof( struct V_49 ) ) ,
V_177 ) ;
if ( ! V_48 ) {
F_12 ( V_22 , L_12 ) ;
return - V_178 ;
}
V_48 -> V_52 = V_52 ;
V_48 -> V_39 = - 1 ;
for ( V_125 = 0 ; V_125 < V_52 ; V_125 ++ ) {
V_38 = F_76 ( V_165 , L_10 , V_125 , & V_72 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_13 ,
V_38 ) ;
return V_38 ;
}
if ( V_72 > V_197 ) {
F_12 ( V_22 ,
L_14 ,
V_72 ) ;
return - V_132 ;
}
if ( F_77 ( V_72 , & V_10 -> V_198 ) ) {
F_12 ( V_22 , L_15 , V_72 ) ;
return - V_132 ;
}
V_48 -> V_40 [ V_125 ] . V_57 = V_72 ;
if ( ! F_76 ( V_165 , L_16 , V_125 , & V_72 ) &&
V_72 < 2 ) {
V_48 -> V_40 [ V_125 ] . V_34 . type = V_41 ;
V_48 -> V_40 [ V_125 ] . V_34 . V_42 . V_43 = V_72 ;
} else {
V_38 = F_78 ( V_165 , L_17 , V_125 ) ;
if ( V_38 >= 0 ) {
V_72 = V_38 ;
V_48 -> V_40 [ V_125 ] . V_34 . type = V_45 ;
V_48 -> V_40 [ V_125 ] . V_34 . V_42 . V_46 = V_72 ;
V_38 = F_79 ( V_22 , V_72 , L_18 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_80 ( V_72 ) ;
if ( V_38 )
return V_38 ;
} else {
V_48 -> V_40 [ V_125 ] . V_34 . type = V_47 ;
}
}
}
V_134 = F_60 ( 0 ) ;
if ( F_61 ( V_134 ) ) {
V_38 = F_62 ( V_134 ) ;
F_12 ( V_22 ,
L_19 ,
V_38 ) ;
return V_38 ;
}
V_38 = F_53 ( V_48 , V_134 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_20 , V_38 ) ;
return V_38 ;
}
V_3 = & V_48 -> V_3 ;
V_3 -> V_199 = 200 ;
V_3 -> V_7 = & V_10 -> V_7 ;
V_3 -> V_92 . V_99 = V_189 ;
F_81 ( V_3 , V_165 ) ;
V_3 -> V_170 = F_20 ;
V_3 -> V_200 = F_31 ;
V_3 -> V_201 = F_25 ;
V_3 -> V_202 = F_28 ;
V_3 -> V_203 = F_30 ;
V_31 = F_57 ( V_3 ) ;
V_31 -> V_22 . V_204 = V_22 ;
V_38 = F_82 ( V_31 , V_52 , NULL ) ;
if ( V_38 )
return V_38 ;
if ( V_3 -> V_205 & V_206 )
V_3 -> V_205 |= V_207 ;
V_38 = F_56 ( V_48 , V_165 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_20 , V_38 ) ;
return V_38 ;
}
V_38 = F_72 ( V_31 , & V_3 -> V_92 , V_165 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_21 , V_38 ) ;
return V_38 ;
}
V_38 = F_83 ( V_31 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_22 , V_38 ) ;
return V_38 ;
}
V_38 = F_84 ( V_31 , NULL , 0 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_23 , V_38 ) ;
F_85 ( V_31 ) ;
return V_38 ;
}
F_86 ( & V_48 -> V_208 , & V_10 -> V_209 ) ;
return 0 ;
}
static int F_87 ( struct V_196 * V_22 , struct V_4 * V_10 )
{
struct V_164 * V_165 = V_22 -> V_210 ;
struct V_164 * V_211 ;
int V_212 = F_88 ( V_165 ) ;
int V_38 ;
if ( V_212 > 8 ) {
F_12 ( V_22 , L_24 , V_212 ) ;
return - V_132 ;
}
F_89 (np, nand_np) {
V_38 = F_73 ( V_22 , V_10 , V_211 ) ;
if ( V_38 ) {
F_90 ( V_211 ) ;
return V_38 ;
}
}
return 0 ;
}
static void F_91 ( struct V_4 * V_10 )
{
struct V_1 * V_48 ;
while ( ! F_92 ( & V_10 -> V_209 ) ) {
V_48 = F_93 ( & V_10 -> V_209 , struct V_1 ,
V_208 ) ;
F_85 ( F_57 ( & V_48 -> V_3 ) ) ;
F_71 ( & V_48 -> V_3 . V_92 ) ;
F_94 ( & V_48 -> V_208 ) ;
}
}
static int F_95 ( struct V_213 * V_214 )
{
struct V_196 * V_22 = & V_214 -> V_22 ;
struct V_215 * V_216 ;
struct V_4 * V_10 ;
int V_8 ;
int V_38 ;
V_10 = F_75 ( V_22 , sizeof( * V_10 ) , V_177 ) ;
if ( ! V_10 )
return - V_178 ;
V_10 -> V_22 = V_22 ;
F_96 ( & V_10 -> V_7 . V_217 ) ;
F_97 ( & V_10 -> V_7 . V_218 ) ;
F_98 ( & V_10 -> V_209 ) ;
V_216 = F_99 ( V_214 , V_219 , 0 ) ;
V_10 -> V_12 = F_100 ( V_22 , V_216 ) ;
if ( F_61 ( V_10 -> V_12 ) )
return F_62 ( V_10 -> V_12 ) ;
V_8 = F_101 ( V_214 , 0 ) ;
if ( V_8 < 0 ) {
F_12 ( V_22 , L_25 ) ;
return V_8 ;
}
V_10 -> V_220 = F_102 ( V_22 , L_26 ) ;
if ( F_61 ( V_10 -> V_220 ) ) {
F_12 ( V_22 , L_27 ) ;
return F_62 ( V_10 -> V_220 ) ;
}
V_38 = F_103 ( V_10 -> V_220 ) ;
if ( V_38 )
return V_38 ;
V_10 -> V_63 = F_102 ( V_22 , L_28 ) ;
if ( F_61 ( V_10 -> V_63 ) ) {
F_12 ( V_22 , L_29 ) ;
V_38 = F_62 ( V_10 -> V_63 ) ;
goto V_221;
}
V_38 = F_103 ( V_10 -> V_63 ) ;
if ( V_38 )
goto V_221;
V_38 = F_15 ( V_10 ) ;
if ( V_38 )
goto V_222;
F_7 ( 0 , V_10 -> V_12 + V_15 ) ;
V_38 = F_104 ( V_22 , V_8 , F_4 ,
0 , L_30 , V_10 ) ;
if ( V_38 )
goto V_222;
F_105 ( V_214 , V_10 ) ;
V_38 = F_87 ( V_22 , V_10 ) ;
if ( V_38 ) {
F_12 ( V_22 , L_31 ) ;
goto V_222;
}
return 0 ;
V_222:
F_106 ( V_10 -> V_63 ) ;
V_221:
F_106 ( V_10 -> V_220 ) ;
return V_38 ;
}
static int F_107 ( struct V_213 * V_214 )
{
struct V_4 * V_10 = F_108 ( V_214 ) ;
F_91 ( V_10 ) ;
return 0 ;
}
