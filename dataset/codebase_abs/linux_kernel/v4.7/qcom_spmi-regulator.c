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
int V_22 , int V_23 )
{
const struct V_24 * V_25 ;
int V_26 = V_22 ;
int V_27 , V_28 , V_29 , V_30 , V_31 ;
int V_32 , V_33 ;
V_27 = V_2 -> V_34 -> V_25 [ 0 ] . V_35 ;
V_28 =
V_2 -> V_34 -> V_25 [ V_2 -> V_34 -> V_36 - 1 ] . V_37 ;
if ( V_26 < V_27 && V_23 >= V_27 )
V_26 = V_27 ;
if ( V_26 < V_27 || V_26 > V_28 ) {
F_15 ( V_2 -> V_38 ,
L_1 ,
V_22 , V_23 , V_27 , V_28 ) ;
return - V_39 ;
}
for ( V_29 = V_2 -> V_34 -> V_36 - 1 ; V_29 > 0 ; V_29 -- ) {
V_31 = V_2 -> V_34 -> V_25 [ V_29 - 1 ] . V_37 ;
if ( V_26 > V_31 && V_31 > 0 )
break;
}
V_30 = V_29 ;
V_25 = & V_2 -> V_34 -> V_25 [ V_30 ] ;
V_33 = F_16 ( V_26 - V_25 -> V_22 , V_25 -> V_40 ) ;
V_26 = V_33 * V_25 -> V_40 + V_25 -> V_22 ;
if ( V_26 > V_23 ) {
F_15 ( V_2 -> V_38 ,
L_2
L_3 ,
V_22 , V_23 , V_26 ) ;
return - V_39 ;
}
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
V_32 += V_2 -> V_34 -> V_25 [ V_29 ] . V_41 ;
V_32 += ( V_26 - V_25 -> V_35 ) / V_25 -> V_40 ;
return V_32 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned V_32 , T_2 * V_42 ,
T_2 * V_33 )
{
const struct V_24 * V_25 , * V_43 ;
V_25 = V_2 -> V_34 -> V_25 ;
V_43 = V_25 + V_2 -> V_34 -> V_36 ;
for (; V_25 < V_43 ; V_25 ++ ) {
if ( V_32 < V_25 -> V_41 ) {
* V_33 = V_32 ;
* V_42 = V_25 -> V_42 ;
return 0 ;
}
V_32 -= V_25 -> V_41 ;
}
return - V_39 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_44 ,
const struct V_24 * V_25 )
{
int V_45 = V_44 ;
const struct V_24 * V_46 = V_2 -> V_34 -> V_25 ;
while ( V_46 != V_25 ) {
V_45 += V_46 -> V_41 ;
V_46 ++ ;
}
return V_45 ;
}
static const struct V_24 *
F_19 ( struct V_1 * V_2 )
{
T_2 V_42 ;
const struct V_24 * V_25 , * V_43 ;
V_25 = V_2 -> V_34 -> V_25 ;
V_43 = V_25 + V_2 -> V_34 -> V_36 ;
F_1 ( V_2 , V_47 , & V_42 , 1 ) ;
for (; V_25 < V_43 ; V_25 ++ )
if ( V_25 -> V_42 == V_42 )
return V_25 ;
return NULL ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_22 , int V_23 )
{
const struct V_24 * V_25 ;
int V_26 = V_22 ;
int V_29 , V_32 ;
V_25 = F_19 ( V_2 ) ;
if ( ! V_25 )
goto V_48;
if ( V_26 < V_25 -> V_22 && V_23 >= V_25 -> V_22 )
V_26 = V_25 -> V_22 ;
if ( V_26 < V_25 -> V_22 || V_26 > V_25 -> V_23 ) {
goto V_48;
}
V_26 = F_16 ( V_26 - V_25 -> V_22 , V_25 -> V_40 ) ;
V_26 = V_26 * V_25 -> V_40 + V_25 -> V_22 ;
if ( V_26 > V_23 ) {
goto V_48;
}
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_34 -> V_36 ; V_29 ++ ) {
if ( V_26 >= V_2 -> V_34 -> V_25 [ V_29 ] . V_35
&& V_26 <= V_2 -> V_34 -> V_25 [ V_29 ] . V_37 ) {
V_32 +=
( V_26 - V_2 -> V_34 -> V_25 [ V_29 ] . V_35 )
/ V_2 -> V_34 -> V_25 [ V_29 ] . V_40 ;
break;
}
V_32 += V_2 -> V_34 -> V_25 [ V_29 ] . V_41 ;
}
if ( V_32 >= V_2 -> V_34 -> V_41 )
goto V_48;
return V_32 ;
V_48:
return F_14 ( V_2 , V_22 , V_23 ) ;
}
static int F_21 ( struct V_10 * V_11 ,
int V_22 , int V_23 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
return F_20 ( V_2 , V_22 , V_23 ) ;
}
static int
F_22 ( struct V_10 * V_11 , unsigned V_32 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_49 ;
T_2 V_4 [ 2 ] ;
T_2 V_42 , V_33 ;
V_49 = F_17 ( V_2 , V_32 , & V_42 , & V_33 ) ;
if ( V_49 )
return V_49 ;
V_4 [ 0 ] = V_42 ;
V_4 [ 1 ] = V_33 ;
return F_3 ( V_2 , V_47 , V_4 , 2 ) ;
}
static int F_23 ( struct V_10 * V_11 ,
unsigned int V_50 , unsigned int V_51 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_24 * V_25 ;
int V_52 ;
V_25 = F_19 ( V_2 ) ;
if ( ! V_25 )
return - V_39 ;
V_52 = abs ( V_51 - V_50 ) * V_25 -> V_40 ;
return F_16 ( V_52 , V_2 -> V_53 ) ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_24 * V_25 ;
T_2 V_33 ;
F_1 ( V_2 , V_54 , & V_33 , 1 ) ;
V_25 = F_19 ( V_2 ) ;
if ( ! V_25 )
return - V_39 ;
return F_18 ( V_2 , V_33 , V_25 ) ;
}
static int F_25 ( struct V_10 * V_11 ,
int V_22 , int V_23 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
return F_14 ( V_2 , V_22 , V_23 ) ;
}
static int F_26 ( struct V_10 * V_11 ,
unsigned V_32 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_55 = V_32 ;
return F_3 ( V_2 , V_54 , & V_55 , 1 ) ;
}
static int F_27 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_32 ;
int V_49 ;
V_49 = F_1 ( V_2 , V_54 , & V_32 , 1 ) ;
if ( V_49 )
return V_49 ;
return V_32 ;
}
static int F_28 ( struct V_10 * V_11 ,
unsigned V_32 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_49 ;
T_2 V_42 , V_33 ;
V_49 = F_17 ( V_2 , V_32 , & V_42 , & V_33 ) ;
if ( V_49 )
return V_49 ;
if ( V_42 == 1 )
V_33 |= V_56 ;
return F_5 ( V_2 , V_54 ,
V_33 , 0xff ) ;
}
static int F_29 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_24 * V_25 ;
T_2 V_33 ;
F_1 ( V_2 , V_54 , & V_33 , 1 ) ;
V_25 = F_19 ( V_2 ) ;
if ( ! V_25 )
return - V_39 ;
if ( V_25 -> V_42 == 1 )
V_33 &= ~ V_56 ;
return F_18 ( V_2 , V_33 , V_25 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
unsigned V_32 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_26 = 0 ;
int V_29 ;
if ( V_32 >= V_2 -> V_34 -> V_41 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_34 -> V_36 ; V_29 ++ ) {
if ( V_32 < V_2 -> V_34 -> V_25 [ V_29 ] . V_41 ) {
V_26 = V_32 * V_2 -> V_34 -> V_25 [ V_29 ] . V_40
+ V_2 -> V_34 -> V_25 [ V_29 ] . V_35 ;
break;
}
V_32 -= V_2 -> V_34 -> V_25 [ V_29 ] . V_41 ;
}
return V_26 ;
}
static int
F_31 ( struct V_10 * V_11 , bool V_57 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_58 ;
T_2 V_8 = 0 ;
if ( V_57 )
V_8 = V_9 ;
return F_5 ( V_2 , V_59 , V_8 , V_9 ) ;
}
static int
F_32 ( struct V_10 * V_11 , bool * V_57 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_8 ;
int V_49 ;
V_49 = F_1 ( V_2 , V_59 , & V_8 , 1 ) ;
* V_57 = V_8 & V_58 ;
return V_49 ;
}
static unsigned int F_33 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_12 ;
F_1 ( V_2 , V_59 , & V_12 , 1 ) ;
if ( V_12 & V_60 )
return V_61 ;
if ( V_12 & V_62 )
return V_63 ;
return V_64 ;
}
static int
F_34 ( struct V_10 * V_11 , unsigned int V_65 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_60 | V_62 ;
T_2 V_8 = 0 ;
if ( V_65 == V_61 )
V_8 = V_60 ;
else if ( V_65 == V_63 )
V_8 = V_62 ;
return F_5 ( V_2 , V_59 , V_8 , V_9 ) ;
}
static int
F_35 ( struct V_10 * V_11 , int V_66 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_65 ;
if ( V_66 >= V_2 -> V_67 )
V_65 = V_61 ;
else
V_65 = V_64 ;
return F_34 ( V_11 , V_65 ) ;
}
static int F_36 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_68 ;
return F_5 ( V_2 , V_69 ,
V_9 , V_9 ) ;
}
static int F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_70 ;
return F_5 ( V_2 , V_71 ,
V_9 , V_9 ) ;
}
static int F_38 ( struct V_10 * V_11 , int V_72 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
enum V_73 type = V_2 -> V_74 ;
unsigned int V_75 ;
T_2 V_12 ;
T_2 V_9 = V_76 |
V_77 ;
int V_78 = ( V_76 + 1 ) * 500 ;
if ( type == V_79 )
V_75 = V_80 ;
else
V_75 = V_81 ;
if ( V_72 > V_78 || V_72 <= 0 )
return - V_39 ;
V_12 = ( V_72 - 1 ) / 500 ;
V_12 |= V_77 ;
return F_5 ( V_2 , V_75 , V_12 , V_9 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_49 ;
V_49 = F_5 ( V_2 , V_13 ,
V_21 , V_14 ) ;
V_2 -> V_18 = F_11 () ;
V_49 = F_5 ( V_2 , V_13 ,
V_15 , V_14 ) ;
return V_49 ;
}
static void F_40 ( struct V_82 * V_83 )
{
struct V_84 * V_85 = F_41 ( V_83 ) ;
struct V_1 * V_2
= F_42 ( V_85 , struct V_1 , V_86 ) ;
F_39 ( V_2 ) ;
}
static T_3 F_43 ( int V_87 , void * V_88 )
{
struct V_1 * V_2 = V_88 ;
T_4 V_89 ;
T_5 V_90 ;
V_89 = F_11 () ;
V_90 = F_44 ( V_89 ,
V_2 -> V_18 ) ;
if ( V_90 > V_91 )
V_2 -> V_17 = 0 ;
F_45 ( V_92 ) ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_17 == 1 ) {
F_39 ( V_2 ) ;
} else if ( V_2 -> V_17 <= V_2 -> V_93 ) {
F_46 ( & V_2 -> V_86 ,
F_47 ( V_2 -> V_94 ) + 1 ) ;
} else {
F_15 ( V_2 -> V_38 ,
L_4 ,
V_2 -> V_17 ) ;
}
return V_95 ;
}
static void F_48 ( struct V_96 * V_97 )
{
unsigned int V_98 ;
struct V_24 * V_25 = V_97 -> V_25 ;
for (; V_25 < V_97 -> V_25 + V_97 -> V_36 ; V_25 ++ ) {
V_98 = 0 ;
if ( V_25 -> V_37 ) {
V_98 = V_25 -> V_37 - V_25 -> V_35 ;
V_98 = ( V_98 / V_25 -> V_40 ) + 1 ;
}
V_25 -> V_41 = V_98 ;
V_97 -> V_41 += V_98 ;
}
}
static int F_49 ( struct V_1 * V_2 , T_1 V_99 )
{
const struct V_100 * V_101 ;
int V_49 , V_29 ;
T_6 V_102 ;
T_2 V_103 [ V_104 - V_105 + 1 ] ;
T_2 type , V_106 ;
V_49 = F_1 ( V_2 , V_105 , V_103 ,
F_50 ( V_103 ) ) ;
if ( V_49 ) {
F_51 ( V_2 -> V_38 , L_5 ) ;
return V_49 ;
}
V_102 = V_103 [ V_105
- V_105 ] ;
if ( ! V_99 ) {
type = V_103 [ V_107 -
V_105 ] ;
V_106 = V_103 [ V_104 -
V_105 ] ;
} else {
type = V_99 >> 8 ;
V_106 = V_99 ;
}
for ( V_29 = 0 ; V_29 < F_50 ( V_108 ) ; V_29 ++ ) {
V_101 = & V_108 [ V_29 ] ;
if ( V_101 -> type == type && V_101 -> V_106 == V_106
&& V_101 -> V_109 <= V_102
&& V_101 -> V_110 >= V_102 )
goto V_111;
}
F_15 ( V_2 -> V_38 ,
L_6 ,
V_2 -> V_112 . V_113 , type , V_106 , V_102 ) ;
return - V_114 ;
V_111:
V_2 -> V_74 = V_101 -> V_74 ;
V_2 -> V_34 = V_101 -> V_34 ;
V_2 -> V_67 = V_101 -> V_67 ;
V_2 -> V_112 . V_115 = V_101 -> V_115 ;
if ( V_101 -> V_34 ) {
if ( ! V_101 -> V_34 -> V_41 )
F_48 ( V_101 -> V_34 ) ;
V_2 -> V_112 . V_41 = V_101 -> V_34 -> V_41 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_49 ;
T_2 V_12 = 0 ;
int V_116 , V_117 , V_53 , V_118 ;
const struct V_24 * V_25 ;
V_49 = F_1 ( V_2 , V_119 , & V_12 , 1 ) ;
if ( V_49 ) {
F_15 ( V_2 -> V_38 , L_7 , V_49 ) ;
return V_49 ;
}
V_25 = F_19 ( V_2 ) ;
if ( ! V_25 )
return - V_39 ;
switch ( V_2 -> V_74 ) {
case V_120 :
V_118 = V_121 ;
break;
default:
V_118 = V_122 ;
break;
}
V_116 = V_12 & V_123 ;
V_116 >>= V_124 ;
V_117 = V_12 & V_125 ;
V_117 >>= V_126 ;
V_53 = V_127 * V_25 -> V_40 * ( 1 << V_116 ) ;
V_53 /= 1000 * ( V_118 << V_117 ) ;
V_53 *= V_128 ;
V_53 /= V_129 ;
V_2 -> V_53 = V_78 ( V_53 , 1 ) ;
return V_49 ;
}
static int F_53 ( struct V_1 * V_2 ,
const struct V_130 * V_88 )
{
int V_49 ;
enum V_73 type ;
T_2 V_131 [ 8 ] , V_12 , V_9 ;
type = V_2 -> V_74 ;
V_49 = F_1 ( V_2 , V_47 , V_131 , 8 ) ;
if ( V_49 )
return V_49 ;
if ( ( type == V_132
|| type == V_133
|| type == V_134 )
&& ! ( V_88 -> V_135
& V_136 ) ) {
V_131 [ V_137 ] &=
~ V_138 ;
V_131 [ V_137 ] |=
V_88 -> V_135 & V_138 ;
}
if ( ( type == V_132
|| type == V_133 )
&& ! ( V_88 -> V_139
& V_140 ) ) {
V_131 [ V_141 ] &=
~ V_142 ;
V_131 [ V_141 ] |=
V_88 -> V_139 & V_142 ;
}
if ( type == V_134
&& ! ( V_88 -> V_139 & V_140 ) ) {
V_131 [ V_141 ] &=
~ V_143 ;
V_131 [ V_141 ] |=
V_88 -> V_139 & V_143 ;
}
if ( ( type == V_144
|| type == V_145
|| type == V_146 )
&& ! ( V_88 -> V_139
& V_140 ) ) {
V_131 [ V_141 ] &=
~ V_143 ;
V_131 [ V_141 ] |=
V_88 -> V_139 & V_143 ;
}
V_49 = F_3 ( V_2 , V_47 , V_131 , 8 ) ;
if ( V_49 )
return V_49 ;
if ( type == V_134 ) {
if ( V_88 -> V_147
!= V_148 ) {
V_12 = V_88 -> V_147
& V_149 ;
V_9 = V_149 ;
return F_5 ( V_2 ,
V_150 ,
V_12 , V_9 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_151 * V_152 , struct V_130 * V_88 )
{
V_88 -> V_135 = V_136 ;
V_88 -> V_139 = V_140 ;
V_88 -> V_147 = V_148 ;
F_55 ( V_152 , L_8 ,
& V_2 -> V_93 ) ;
F_55 ( V_152 , L_9 ,
& V_2 -> V_94 ) ;
F_55 ( V_152 , L_10 ,
& V_88 -> V_135 ) ;
F_55 ( V_152 , L_11 , & V_88 -> V_139 ) ;
F_55 ( V_152 , L_12 ,
& V_88 -> V_147 ) ;
}
static unsigned int F_56 ( unsigned int V_65 )
{
if ( V_65 == 1 )
return V_61 ;
if ( V_65 == 2 )
return V_63 ;
return V_64 ;
}
static int F_57 ( struct V_151 * V_152 ,
const struct V_153 * V_112 ,
struct V_154 * V_155 )
{
struct V_130 V_88 = { } ;
struct V_1 * V_2 = V_155 -> V_156 ;
struct V_157 * V_38 = V_155 -> V_38 ;
int V_49 ;
F_54 ( V_2 , V_152 , & V_88 ) ;
if ( ! V_2 -> V_93 )
V_2 -> V_93 = V_158 ;
if ( ! V_2 -> V_94 )
V_2 -> V_94 = V_159 ;
V_49 = F_53 ( V_2 , & V_88 ) ;
if ( V_49 ) {
F_15 ( V_38 , L_13 , V_49 ) ;
return V_49 ;
}
switch ( V_2 -> V_74 ) {
case V_120 :
case V_144 :
case V_145 :
case V_132 :
V_49 = F_52 ( V_2 ) ;
if ( V_49 )
return V_49 ;
default:
break;
}
if ( V_2 -> V_74 != V_134 )
V_2 -> V_16 = 0 ;
if ( V_2 -> V_16 ) {
V_49 = F_58 ( V_38 , V_2 -> V_16 ,
F_43 , V_160 , L_14 ,
V_2 ) ;
if ( V_49 < 0 ) {
F_15 ( V_38 , L_15 ,
V_2 -> V_16 , V_49 ) ;
return V_49 ;
}
F_59 ( & V_2 -> V_86 , F_40 ) ;
}
return 0 ;
}
static int F_60 ( struct V_161 * V_162 )
{
const struct V_163 * V_12 ;
const struct V_164 * V_165 ;
struct V_154 V_155 = { } ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
const char * V_113 ;
struct V_157 * V_38 = & V_162 -> V_38 ;
int V_49 ;
struct V_166 * V_167 ;
V_167 = F_61 ( V_38 , sizeof( * V_167 ) , V_168 ) ;
if ( ! V_167 )
return - V_169 ;
F_62 ( V_167 ) ;
F_63 ( V_162 , V_167 ) ;
V_6 = F_64 ( V_38 -> V_170 , NULL ) ;
if ( ! V_6 )
return - V_114 ;
V_165 = F_65 ( V_171 , & V_162 -> V_38 ) ;
if ( ! V_165 )
return - V_114 ;
for ( V_12 = V_165 -> V_88 ; V_12 -> V_113 ; V_12 ++ ) {
V_2 = F_61 ( V_38 , sizeof( * V_2 ) , V_168 ) ;
if ( ! V_2 )
return - V_169 ;
V_2 -> V_38 = V_38 ;
V_2 -> V_7 = V_12 -> V_7 ;
V_2 -> V_6 = V_6 ;
if ( V_12 -> V_172 ) {
V_2 -> V_16 = F_66 ( V_162 , V_12 -> V_172 ) ;
if ( V_2 -> V_16 < 0 ) {
V_49 = V_2 -> V_16 ;
goto V_173;
}
}
V_2 -> V_112 . V_174 = - 1 ;
V_2 -> V_112 . V_175 = V_176 ;
V_2 -> V_112 . type = V_177 ;
V_2 -> V_112 . V_113 = V_113 = V_12 -> V_113 ;
V_2 -> V_112 . V_178 = V_12 -> V_179 ;
V_2 -> V_112 . V_180 = V_12 -> V_113 ;
V_2 -> V_112 . V_181 = F_57 ;
V_2 -> V_112 . V_182 = F_56 ;
V_49 = F_49 ( V_2 , V_12 -> V_99 ) ;
if ( V_49 )
continue;
V_155 . V_38 = V_38 ;
V_155 . V_156 = V_2 ;
V_11 = F_67 ( V_38 , & V_2 -> V_112 , & V_155 ) ;
if ( F_68 ( V_11 ) ) {
F_15 ( V_38 , L_16 , V_113 ) ;
V_49 = F_69 ( V_11 ) ;
goto V_173;
}
F_62 ( & V_2 -> V_152 ) ;
F_70 ( & V_2 -> V_152 , V_167 ) ;
}
return 0 ;
V_173:
F_71 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_72 ( & V_2 -> V_86 ) ;
return V_49 ;
}
static int F_73 ( struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_166 * V_167 = F_74 ( V_162 ) ;
F_71 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_72 ( & V_2 -> V_86 ) ;
return 0 ;
}
