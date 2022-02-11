static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 ,
int V_5 )
{
return F_2 ( V_2 -> V_6 , V_2 -> V_7 + V_3 , V_4 , V_5 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , int V_5 )
{
return F_4 ( V_2 -> V_6 , V_2 -> V_7 + V_3 , V_4 , V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_8 ,
T_2 V_9 )
{
return F_6 ( V_2 -> V_6 , V_2 -> V_7 + V_3 , V_9 , V_8 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_12 ;
F_1 ( V_2 , V_13 , & V_12 , 1 ) ;
return ( V_12 & V_14 ) == V_15 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
return F_5 ( V_2 , V_13 ,
V_15 , V_14 ) ;
}
static int F_10 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
if ( V_2 -> V_16 ) {
V_2 -> V_17 = 0 ;
V_2 -> V_18 = F_11 () ;
}
return F_9 ( V_11 ) ;
}
static int F_12 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_12 = V_19 ;
return F_3 ( V_2 , V_20 , & V_12 , 1 ) ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
return F_5 ( V_2 , V_13 ,
V_21 , V_14 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
int V_22 , int V_23 , T_2 * V_24 , T_2 * V_25 ,
unsigned * V_26 )
{
const struct V_27 * V_28 ;
int V_29 = V_22 ;
int V_30 , V_31 , V_32 , V_33 , V_34 ;
V_30 = V_2 -> V_35 -> V_28 [ 0 ] . V_36 ;
V_31 =
V_2 -> V_35 -> V_28 [ V_2 -> V_35 -> V_37 - 1 ] . V_38 ;
if ( V_29 < V_30 && V_23 >= V_30 )
V_29 = V_30 ;
if ( V_29 < V_30 || V_29 > V_31 ) {
F_15 ( V_2 -> V_39 ,
L_1 ,
V_22 , V_23 , V_30 , V_31 ) ;
return - V_40 ;
}
for ( V_32 = V_2 -> V_35 -> V_37 - 1 ; V_32 > 0 ; V_32 -- ) {
V_34 = V_2 -> V_35 -> V_28 [ V_32 - 1 ] . V_38 ;
if ( V_29 > V_34 && V_34 > 0 )
break;
}
V_33 = V_32 ;
V_28 = & V_2 -> V_35 -> V_28 [ V_33 ] ;
* V_24 = V_28 -> V_24 ;
* V_25 = F_16 ( V_29 - V_28 -> V_22 , V_28 -> V_41 ) ;
V_29 = * V_25 * V_28 -> V_41 + V_28 -> V_22 ;
if ( V_29 > V_23 ) {
F_15 ( V_2 -> V_39 ,
L_2
L_3 ,
V_22 , V_23 , V_29 ) ;
return - V_40 ;
}
* V_26 = 0 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
* V_26 += V_2 -> V_35 -> V_28 [ V_32 ] . V_42 ;
* V_26 += ( V_29 - V_28 -> V_36 ) / V_28 -> V_41 ;
return 0 ;
}
static const struct V_27 *
F_17 ( struct V_1 * V_2 )
{
T_2 V_24 ;
const struct V_27 * V_28 , * V_43 ;
V_28 = V_2 -> V_35 -> V_28 ;
V_43 = V_28 + V_2 -> V_35 -> V_37 ;
F_1 ( V_2 , V_44 , & V_24 , 1 ) ;
for (; V_28 < V_43 ; V_28 ++ )
if ( V_28 -> V_24 == V_24 )
return V_28 ;
return NULL ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_22 , int V_23 , T_2 * V_24 , T_2 * V_25 ,
unsigned * V_26 )
{
const struct V_27 * V_28 ;
int V_29 = V_22 ;
int V_32 ;
V_28 = F_17 ( V_2 ) ;
if ( ! V_28 )
goto V_45;
if ( V_29 < V_28 -> V_22 && V_23 >= V_28 -> V_22 )
V_29 = V_28 -> V_22 ;
if ( V_29 < V_28 -> V_22 || V_29 > V_28 -> V_23 ) {
goto V_45;
}
* V_25 = F_16 ( V_29 - V_28 -> V_22 , V_28 -> V_41 ) ;
V_29 = * V_25 * V_28 -> V_41 + V_28 -> V_22 ;
if ( V_29 > V_23 ) {
goto V_45;
}
* V_26 = 0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_35 -> V_37 ; V_32 ++ ) {
if ( V_29 >= V_2 -> V_35 -> V_28 [ V_32 ] . V_36
&& V_29 <= V_2 -> V_35 -> V_28 [ V_32 ] . V_38 ) {
* V_26 +=
( V_29 - V_2 -> V_35 -> V_28 [ V_32 ] . V_36 )
/ V_2 -> V_35 -> V_28 [ V_32 ] . V_41 ;
break;
}
* V_26 += V_2 -> V_35 -> V_28 [ V_32 ] . V_42 ;
}
if ( * V_26 >= V_2 -> V_35 -> V_42 )
goto V_45;
return 0 ;
V_45:
return F_14 ( V_2 , V_22 , V_23 ,
V_24 , V_25 , V_26 ) ;
}
static int F_19 ( struct V_10 * V_11 ,
int V_22 , int V_23 , unsigned * V_26 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_46 ;
T_2 V_4 [ 2 ] ;
T_2 V_24 , V_25 ;
V_46 = F_18 ( V_2 , V_22 , V_23 ,
& V_24 , & V_25 , V_26 ) ;
if ( V_46 )
return V_46 ;
V_4 [ 0 ] = V_24 ;
V_4 [ 1 ] = V_25 ;
return F_3 ( V_2 , V_44 , V_4 , 2 ) ;
}
static int F_20 ( struct V_10 * V_11 ,
unsigned int V_47 , unsigned int V_48 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_27 * V_28 ;
int V_49 ;
V_28 = F_17 ( V_2 ) ;
if ( ! V_28 )
return - V_40 ;
V_49 = abs ( V_48 - V_47 ) * V_28 -> V_41 ;
return F_16 ( V_49 , V_2 -> V_50 ) ;
}
static int F_21 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_27 * V_28 ;
T_2 V_25 ;
F_1 ( V_2 , V_51 , & V_25 , 1 ) ;
V_28 = F_17 ( V_2 ) ;
if ( ! V_28 )
return V_52 ;
return V_28 -> V_41 * V_25 + V_28 -> V_22 ;
}
static int F_22 ( struct V_10 * V_11 ,
int V_22 , int V_23 , unsigned * V_26 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_46 ;
T_2 V_24 , V_53 ;
V_46 = F_14 ( V_2 , V_22 , V_23 , & V_24 ,
& V_53 , V_26 ) ;
if ( V_46 ) {
F_15 ( V_2 -> V_39 , L_4 , V_46 ) ;
return V_46 ;
}
return F_3 ( V_2 , V_51 , & V_53 , 1 ) ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_27 * V_28 = V_2 -> V_35 -> V_28 ;
T_2 V_25 ;
F_1 ( V_2 , V_51 , & V_25 , 1 ) ;
return V_28 -> V_41 * V_25 + V_28 -> V_22 ;
}
static int F_24 ( struct V_10 * V_11 ,
int V_22 , int V_23 , unsigned * V_26 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_46 ;
T_2 V_24 , V_25 ;
V_46 = F_18 ( V_2 , V_22 , V_23 ,
& V_24 , & V_25 , V_26 ) ;
if ( V_46 )
return V_46 ;
if ( V_24 == 1 )
V_25 |= V_54 ;
return F_5 ( V_2 , V_51 ,
V_25 , 0xff ) ;
}
static int F_25 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_27 * V_28 ;
T_2 V_25 ;
F_1 ( V_2 , V_51 , & V_25 , 1 ) ;
V_28 = F_17 ( V_2 ) ;
if ( ! V_28 )
return V_52 ;
if ( V_28 -> V_24 == 1 )
V_25 &= ~ V_54 ;
return V_28 -> V_41 * V_25 + V_28 -> V_22 ;
}
static int F_26 ( struct V_10 * V_11 ,
unsigned V_26 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_29 = 0 ;
int V_32 ;
if ( V_26 >= V_2 -> V_35 -> V_42 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_2 -> V_35 -> V_37 ; V_32 ++ ) {
if ( V_26 < V_2 -> V_35 -> V_28 [ V_32 ] . V_42 ) {
V_29 = V_26 * V_2 -> V_35 -> V_28 [ V_32 ] . V_41
+ V_2 -> V_35 -> V_28 [ V_32 ] . V_36 ;
break;
}
V_26 -= V_2 -> V_35 -> V_28 [ V_32 ] . V_42 ;
}
return V_29 ;
}
static int
F_27 ( struct V_10 * V_11 , bool V_55 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_56 ;
T_2 V_8 = 0 ;
if ( V_55 )
V_8 = V_9 ;
return F_5 ( V_2 , V_57 , V_8 , V_9 ) ;
}
static int
F_28 ( struct V_10 * V_11 , bool * V_55 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_8 ;
int V_46 ;
V_46 = F_1 ( V_2 , V_57 , & V_8 , 1 ) ;
* V_55 = V_8 & V_56 ;
return V_46 ;
}
static unsigned int F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_12 ;
F_1 ( V_2 , V_57 , & V_12 , 1 ) ;
if ( V_12 & V_58 )
return V_59 ;
if ( V_12 & V_60 )
return V_61 ;
return V_62 ;
}
static int
F_30 ( struct V_10 * V_11 , unsigned int V_63 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_58 | V_60 ;
T_2 V_8 = 0 ;
if ( V_63 == V_59 )
V_8 = V_58 ;
else if ( V_63 == V_61 )
V_8 = V_60 ;
return F_5 ( V_2 , V_57 , V_8 , V_9 ) ;
}
static int
F_31 ( struct V_10 * V_11 , int V_64 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_63 ;
if ( V_64 >= V_2 -> V_65 )
V_63 = V_59 ;
else
V_63 = V_62 ;
return F_30 ( V_11 , V_63 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_66 ;
return F_5 ( V_2 , V_67 ,
V_9 , V_9 ) ;
}
static int F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_68 ;
return F_5 ( V_2 , V_69 ,
V_9 , V_9 ) ;
}
static int F_34 ( struct V_10 * V_11 , int V_70 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
enum V_71 type = V_2 -> V_72 ;
unsigned int V_73 ;
T_2 V_12 ;
T_2 V_9 = V_74 |
V_75 ;
int V_76 = ( V_74 + 1 ) * 500 ;
if ( type == V_77 )
V_73 = V_78 ;
else
V_73 = V_79 ;
if ( V_70 > V_76 || V_70 <= 0 )
return - V_40 ;
V_12 = ( V_70 - 1 ) / 500 ;
V_12 |= V_75 ;
return F_5 ( V_2 , V_73 , V_12 , V_9 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_46 ;
V_46 = F_5 ( V_2 , V_13 ,
V_21 , V_14 ) ;
V_2 -> V_18 = F_11 () ;
V_46 = F_5 ( V_2 , V_13 ,
V_15 , V_14 ) ;
return V_46 ;
}
static void F_36 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_37 ( V_81 ) ;
struct V_1 * V_2
= F_38 ( V_83 , struct V_1 , V_84 ) ;
F_35 ( V_2 ) ;
}
static T_3 F_39 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
T_4 V_87 ;
T_5 V_88 ;
V_87 = F_11 () ;
V_88 = F_40 ( V_87 ,
V_2 -> V_18 ) ;
if ( V_88 > V_89 )
V_2 -> V_17 = 0 ;
F_41 ( V_90 ) ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_17 == 1 ) {
F_35 ( V_2 ) ;
} else if ( V_2 -> V_17 <= V_2 -> V_91 ) {
F_42 ( & V_2 -> V_84 ,
F_43 ( V_2 -> V_92 ) + 1 ) ;
} else {
F_15 ( V_2 -> V_39 ,
L_5 ,
V_2 -> V_17 ) ;
}
return V_93 ;
}
static void F_44 ( struct V_94 * V_95 )
{
unsigned int V_96 ;
struct V_27 * V_28 = V_95 -> V_28 ;
for (; V_28 < V_95 -> V_28 + V_95 -> V_37 ; V_28 ++ ) {
V_96 = 0 ;
if ( V_28 -> V_38 ) {
V_96 = V_28 -> V_38 - V_28 -> V_36 ;
V_96 = ( V_96 / V_28 -> V_41 ) + 1 ;
}
V_28 -> V_42 = V_96 ;
V_95 -> V_42 += V_96 ;
}
}
static int F_45 ( struct V_1 * V_2 , T_1 V_97 )
{
const struct V_98 * V_99 ;
int V_46 , V_32 ;
T_6 V_100 ;
T_2 V_101 [ V_102 - V_103 + 1 ] ;
T_2 type , V_104 ;
V_46 = F_1 ( V_2 , V_103 , V_101 ,
F_46 ( V_101 ) ) ;
if ( V_46 ) {
F_15 ( V_2 -> V_39 , L_6 ) ;
return V_46 ;
}
V_100 = V_101 [ V_103
- V_103 ] ;
if ( ! V_97 ) {
type = V_101 [ V_105 -
V_103 ] ;
V_104 = V_101 [ V_102 -
V_103 ] ;
} else {
type = V_97 >> 8 ;
V_104 = V_97 ;
}
for ( V_32 = 0 ; V_32 < F_46 ( V_106 ) ; V_32 ++ ) {
V_99 = & V_106 [ V_32 ] ;
if ( V_99 -> type == type && V_99 -> V_104 == V_104
&& V_99 -> V_107 <= V_100
&& V_99 -> V_108 >= V_100 )
goto V_109;
}
F_15 ( V_2 -> V_39 ,
L_7 ,
V_2 -> V_110 . V_111 , type , V_104 , V_100 ) ;
return - V_112 ;
V_109:
V_2 -> V_72 = V_99 -> V_72 ;
V_2 -> V_35 = V_99 -> V_35 ;
V_2 -> V_65 = V_99 -> V_65 ;
V_2 -> V_110 . V_113 = V_99 -> V_113 ;
if ( V_99 -> V_35 ) {
if ( ! V_99 -> V_35 -> V_42 )
F_44 ( V_99 -> V_35 ) ;
V_2 -> V_110 . V_42 = V_99 -> V_35 -> V_42 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_46 ;
T_2 V_12 = 0 ;
int V_114 , V_115 , V_50 ;
const struct V_27 * V_28 ;
V_46 = F_1 ( V_2 , V_116 , & V_12 , 1 ) ;
if ( V_46 ) {
F_15 ( V_2 -> V_39 , L_8 , V_46 ) ;
return V_46 ;
}
V_28 = F_17 ( V_2 ) ;
if ( ! V_28 )
return - V_40 ;
V_114 = V_12 & V_117 ;
V_114 >>= V_118 ;
V_115 = V_12 & V_119 ;
V_115 >>= V_120 ;
V_50 = V_121 * V_28 -> V_41 * ( 1 << V_114 ) ;
V_50 /= 1000 * ( V_122 << V_115 ) ;
V_50 *= V_123 ;
V_50 /= V_124 ;
V_2 -> V_50 = V_76 ( V_50 , 1 ) ;
return V_46 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_125 * V_86 )
{
int V_46 ;
enum V_71 type ;
T_2 V_126 [ 8 ] , V_12 , V_9 ;
type = V_2 -> V_72 ;
V_46 = F_1 ( V_2 , V_44 , V_126 , 8 ) ;
if ( V_46 )
return V_46 ;
if ( ( type == V_127
|| type == V_128
|| type == V_129 )
&& ! ( V_86 -> V_130
& V_131 ) ) {
V_126 [ V_132 ] &=
~ V_133 ;
V_126 [ V_132 ] |=
V_86 -> V_130 & V_133 ;
}
if ( ( type == V_127
|| type == V_128 )
&& ! ( V_86 -> V_134
& V_135 ) ) {
V_126 [ V_136 ] &=
~ V_137 ;
V_126 [ V_136 ] |=
V_86 -> V_134 & V_137 ;
}
if ( type == V_129
&& ! ( V_86 -> V_134 & V_135 ) ) {
V_126 [ V_136 ] &=
~ V_138 ;
V_126 [ V_136 ] |=
V_86 -> V_134 & V_138 ;
}
if ( ( type == V_139
|| type == V_140
|| type == V_141 )
&& ! ( V_86 -> V_134
& V_135 ) ) {
V_126 [ V_136 ] &=
~ V_138 ;
V_126 [ V_136 ] |=
V_86 -> V_134 & V_138 ;
}
V_46 = F_3 ( V_2 , V_44 , V_126 , 8 ) ;
if ( V_46 )
return V_46 ;
if ( type == V_129 ) {
if ( V_86 -> V_142
!= V_143 ) {
V_12 = V_86 -> V_142
& V_144 ;
V_9 = V_144 ;
return F_5 ( V_2 ,
V_145 ,
V_12 , V_9 ) ;
}
}
return 0 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_146 * V_147 , struct V_125 * V_86 )
{
V_86 -> V_130 = V_131 ;
V_86 -> V_134 = V_135 ;
V_86 -> V_142 = V_143 ;
F_50 ( V_147 , L_9 ,
& V_2 -> V_91 ) ;
F_50 ( V_147 , L_10 ,
& V_2 -> V_92 ) ;
F_50 ( V_147 , L_11 ,
& V_86 -> V_130 ) ;
F_50 ( V_147 , L_12 , & V_86 -> V_134 ) ;
F_50 ( V_147 , L_13 ,
& V_86 -> V_142 ) ;
}
static unsigned int F_51 ( unsigned int V_63 )
{
if ( V_63 == 1 )
return V_59 ;
if ( V_63 == 2 )
return V_61 ;
return V_62 ;
}
static int F_52 ( struct V_146 * V_147 ,
const struct V_148 * V_110 ,
struct V_149 * V_150 )
{
struct V_125 V_86 = { } ;
struct V_1 * V_2 = V_150 -> V_151 ;
struct V_152 * V_39 = V_150 -> V_39 ;
int V_46 ;
F_49 ( V_2 , V_147 , & V_86 ) ;
if ( ! V_2 -> V_91 )
V_2 -> V_91 = V_153 ;
if ( ! V_2 -> V_92 )
V_2 -> V_92 = V_154 ;
V_46 = F_48 ( V_2 , & V_86 ) ;
if ( V_46 ) {
F_15 ( V_39 , L_14 , V_46 ) ;
return V_46 ;
}
if ( V_2 -> V_72 == V_155 ) {
V_46 = F_47 ( V_2 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_2 -> V_72 != V_129 )
V_2 -> V_16 = 0 ;
if ( V_2 -> V_16 ) {
V_46 = F_53 ( V_39 , V_2 -> V_16 ,
F_39 , V_156 , L_15 ,
V_2 ) ;
if ( V_46 < 0 ) {
F_15 ( V_39 , L_16 ,
V_2 -> V_16 , V_46 ) ;
return V_46 ;
}
F_54 ( & V_2 -> V_84 , F_36 ) ;
}
return 0 ;
}
static int F_55 ( struct V_157 * V_158 )
{
const struct V_159 * V_12 ;
const struct V_160 * V_161 ;
struct V_149 V_150 = { } ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
const char * V_111 ;
struct V_152 * V_39 = & V_158 -> V_39 ;
int V_46 ;
struct V_162 * V_163 ;
V_163 = F_56 ( V_39 , sizeof( * V_163 ) , V_164 ) ;
if ( ! V_163 )
return - V_165 ;
F_57 ( V_163 ) ;
F_58 ( V_158 , V_163 ) ;
V_6 = F_59 ( V_39 -> V_166 , NULL ) ;
if ( ! V_6 )
return - V_112 ;
V_161 = F_60 ( V_167 , & V_158 -> V_39 ) ;
if ( ! V_161 )
return - V_112 ;
for ( V_12 = V_161 -> V_86 ; V_12 -> V_111 ; V_12 ++ ) {
V_2 = F_56 ( V_39 , sizeof( * V_2 ) , V_164 ) ;
if ( ! V_2 )
return - V_165 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_7 = V_12 -> V_7 ;
V_2 -> V_6 = V_6 ;
if ( V_12 -> V_168 ) {
V_2 -> V_16 = F_61 ( V_158 , V_12 -> V_168 ) ;
if ( V_2 -> V_16 < 0 ) {
V_46 = V_2 -> V_16 ;
goto V_169;
}
}
V_2 -> V_110 . V_170 = - 1 ;
V_2 -> V_110 . V_171 = V_172 ;
V_2 -> V_110 . type = V_173 ;
V_2 -> V_110 . V_111 = V_111 = V_12 -> V_111 ;
V_2 -> V_110 . V_174 = V_12 -> V_175 ;
V_2 -> V_110 . V_176 = V_12 -> V_111 ;
V_2 -> V_110 . V_177 = F_52 ;
V_2 -> V_110 . V_178 = F_51 ;
V_46 = F_45 ( V_2 , V_12 -> V_97 ) ;
if ( V_46 )
goto V_169;
V_150 . V_39 = V_39 ;
V_150 . V_151 = V_2 ;
V_11 = F_62 ( V_39 , & V_2 -> V_110 , & V_150 ) ;
if ( F_63 ( V_11 ) ) {
F_15 ( V_39 , L_17 , V_111 ) ;
V_46 = F_64 ( V_11 ) ;
goto V_169;
}
F_57 ( & V_2 -> V_147 ) ;
F_65 ( & V_2 -> V_147 , V_163 ) ;
}
return 0 ;
V_169:
F_66 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_67 ( & V_2 -> V_84 ) ;
return V_46 ;
}
static int F_68 ( struct V_157 * V_158 )
{
struct V_1 * V_2 ;
struct V_162 * V_163 = F_69 ( V_158 ) ;
F_66 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_67 ( & V_2 -> V_84 ) ;
return 0 ;
}
