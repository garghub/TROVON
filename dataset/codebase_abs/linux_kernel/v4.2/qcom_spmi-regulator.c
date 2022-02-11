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
return F_5 ( V_2 , V_13 ,
V_19 , V_14 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_20 , int V_21 , T_2 * V_22 , T_2 * V_23 ,
unsigned * V_24 )
{
const struct V_25 * V_26 ;
int V_27 = V_20 ;
int V_28 , V_29 , V_30 , V_31 , V_32 ;
V_28 = V_2 -> V_33 -> V_26 [ 0 ] . V_34 ;
V_29 =
V_2 -> V_33 -> V_26 [ V_2 -> V_33 -> V_35 - 1 ] . V_36 ;
if ( V_27 < V_28 && V_21 >= V_28 )
V_27 = V_28 ;
if ( V_27 < V_28 || V_27 > V_29 ) {
F_14 ( V_2 -> V_37 ,
L_1 ,
V_20 , V_21 , V_28 , V_29 ) ;
return - V_38 ;
}
for ( V_30 = V_2 -> V_33 -> V_35 - 1 ; V_30 > 0 ; V_30 -- ) {
V_32 = V_2 -> V_33 -> V_26 [ V_30 - 1 ] . V_36 ;
if ( V_27 > V_32 && V_32 > 0 )
break;
}
V_31 = V_30 ;
V_26 = & V_2 -> V_33 -> V_26 [ V_31 ] ;
* V_22 = V_26 -> V_22 ;
* V_23 = ( V_27 - V_26 -> V_20 + V_26 -> V_39 - 1 )
/ V_26 -> V_39 ;
V_27 = * V_23 * V_26 -> V_39 + V_26 -> V_20 ;
if ( V_27 > V_21 ) {
F_14 ( V_2 -> V_37 ,
L_2
L_3 ,
V_20 , V_21 , V_27 ) ;
return - V_38 ;
}
* V_24 = 0 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
* V_24 += V_2 -> V_33 -> V_26 [ V_30 ] . V_40 ;
* V_24 += ( V_27 - V_26 -> V_34 ) / V_26 -> V_39 ;
return 0 ;
}
static const struct V_25 *
F_15 ( struct V_1 * V_2 )
{
T_2 V_22 ;
const struct V_25 * V_26 , * V_41 ;
V_26 = V_2 -> V_33 -> V_26 ;
V_41 = V_26 + V_2 -> V_33 -> V_35 ;
F_1 ( V_2 , V_42 , & V_22 , 1 ) ;
for (; V_26 < V_41 ; V_26 ++ )
if ( V_26 -> V_22 == V_22 )
return V_26 ;
return NULL ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_20 , int V_21 , T_2 * V_22 , T_2 * V_23 ,
unsigned * V_24 )
{
const struct V_25 * V_26 ;
int V_27 = V_20 ;
int V_30 ;
V_26 = F_15 ( V_2 ) ;
if ( ! V_26 )
goto V_43;
if ( V_27 < V_26 -> V_20 && V_21 >= V_26 -> V_20 )
V_27 = V_26 -> V_20 ;
if ( V_27 < V_26 -> V_20 || V_27 > V_26 -> V_21 ) {
goto V_43;
}
* V_23 = F_17 ( V_27 - V_26 -> V_20 , V_26 -> V_39 ) ;
V_27 = * V_23 * V_26 -> V_39 + V_26 -> V_20 ;
if ( V_27 > V_21 ) {
goto V_43;
}
* V_24 = 0 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_33 -> V_35 ; V_30 ++ ) {
if ( V_27 >= V_2 -> V_33 -> V_26 [ V_30 ] . V_34
&& V_27 <= V_2 -> V_33 -> V_26 [ V_30 ] . V_36 ) {
* V_24 +=
( V_27 - V_2 -> V_33 -> V_26 [ V_30 ] . V_34 )
/ V_2 -> V_33 -> V_26 [ V_30 ] . V_39 ;
break;
}
* V_24 += V_2 -> V_33 -> V_26 [ V_30 ] . V_40 ;
}
if ( * V_24 >= V_2 -> V_33 -> V_40 )
goto V_43;
return 0 ;
V_43:
return F_13 ( V_2 , V_20 , V_21 ,
V_22 , V_23 , V_24 ) ;
}
static int F_18 ( struct V_10 * V_11 ,
int V_20 , int V_21 , unsigned * V_24 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_44 ;
T_2 V_4 [ 2 ] ;
T_2 V_22 , V_23 ;
V_44 = F_16 ( V_2 , V_20 , V_21 ,
& V_22 , & V_23 , V_24 ) ;
if ( V_44 )
return V_44 ;
V_4 [ 0 ] = V_22 ;
V_4 [ 1 ] = V_23 ;
return F_3 ( V_2 , V_42 , V_4 , 2 ) ;
}
static int F_19 ( struct V_10 * V_11 ,
unsigned int V_45 , unsigned int V_46 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_25 * V_26 ;
int V_47 ;
V_26 = F_15 ( V_2 ) ;
if ( ! V_26 )
return - V_38 ;
V_47 = abs ( V_46 - V_45 ) * V_26 -> V_39 ;
return F_17 ( V_47 , V_2 -> V_48 ) ;
}
static int F_20 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_25 * V_26 ;
T_2 V_23 ;
F_1 ( V_2 , V_49 , & V_23 , 1 ) ;
V_26 = F_15 ( V_2 ) ;
if ( ! V_26 )
return V_50 ;
return V_26 -> V_39 * V_23 + V_26 -> V_20 ;
}
static int F_21 ( struct V_10 * V_11 ,
int V_20 , int V_21 , unsigned * V_24 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_44 ;
T_2 V_22 , V_51 ;
V_44 = F_13 ( V_2 , V_20 , V_21 , & V_22 ,
& V_51 , V_24 ) ;
if ( V_44 ) {
F_14 ( V_2 -> V_37 , L_4 , V_44 ) ;
return V_44 ;
}
return F_3 ( V_2 , V_49 , & V_51 , 1 ) ;
}
static int F_22 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_25 * V_26 = V_2 -> V_33 -> V_26 ;
T_2 V_23 ;
F_1 ( V_2 , V_49 , & V_23 , 1 ) ;
return V_26 -> V_39 * V_23 + V_26 -> V_20 ;
}
static int F_23 ( struct V_10 * V_11 ,
int V_20 , int V_21 , unsigned * V_24 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_44 ;
T_2 V_22 , V_23 ;
V_44 = F_16 ( V_2 , V_20 , V_21 ,
& V_22 , & V_23 , V_24 ) ;
if ( V_44 )
return V_44 ;
if ( V_22 == 1 )
V_23 |= V_52 ;
return F_5 ( V_2 , V_49 ,
V_23 , 0xff ) ;
}
static int F_24 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
const struct V_25 * V_26 ;
T_2 V_23 ;
F_1 ( V_2 , V_49 , & V_23 , 1 ) ;
V_26 = F_15 ( V_2 ) ;
if ( ! V_26 )
return V_50 ;
if ( V_26 -> V_22 == 1 )
V_23 &= ~ V_52 ;
return V_26 -> V_39 * V_23 + V_26 -> V_20 ;
}
static int F_25 ( struct V_10 * V_11 ,
unsigned V_24 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
int V_27 = 0 ;
int V_30 ;
if ( V_24 >= V_2 -> V_33 -> V_40 )
return 0 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_33 -> V_35 ; V_30 ++ ) {
if ( V_24 < V_2 -> V_33 -> V_26 [ V_30 ] . V_40 ) {
V_27 = V_24 * V_2 -> V_33 -> V_26 [ V_30 ] . V_39
+ V_2 -> V_33 -> V_26 [ V_30 ] . V_34 ;
break;
}
V_24 -= V_2 -> V_33 -> V_26 [ V_30 ] . V_40 ;
}
return V_27 ;
}
static int
F_26 ( struct V_10 * V_11 , bool V_53 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_54 ;
T_2 V_8 = 0 ;
if ( V_53 )
V_8 = V_9 ;
return F_5 ( V_2 , V_55 , V_8 , V_9 ) ;
}
static int
F_27 ( struct V_10 * V_11 , bool * V_53 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_8 ;
int V_44 ;
V_44 = F_1 ( V_2 , V_55 , & V_8 , 1 ) ;
* V_53 = V_8 & V_54 ;
return V_44 ;
}
static unsigned int F_28 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_12 ;
F_1 ( V_2 , V_55 , & V_12 , 1 ) ;
if ( V_12 & V_56 )
return V_57 ;
return V_58 ;
}
static int
F_29 ( struct V_10 * V_11 , unsigned int V_59 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_2 V_9 = V_56 ;
T_2 V_8 = 0 ;
if ( V_59 == V_57 )
V_8 = V_9 ;
return F_5 ( V_2 , V_55 , V_8 , V_9 ) ;
}
static int
F_30 ( struct V_10 * V_11 , int V_60 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_59 ;
if ( V_60 >= V_2 -> V_61 )
V_59 = V_57 ;
else
V_59 = V_58 ;
return F_29 ( V_11 , V_59 ) ;
}
static int F_31 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_62 ;
return F_5 ( V_2 , V_63 ,
V_9 , V_9 ) ;
}
static int F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
unsigned int V_9 = V_64 ;
return F_5 ( V_2 , V_65 ,
V_9 , V_9 ) ;
}
static int F_33 ( struct V_10 * V_11 , int V_66 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
enum V_67 type = V_2 -> V_68 ;
unsigned int V_69 ;
T_2 V_12 ;
T_2 V_9 = V_70 |
V_71 ;
int V_72 = ( V_70 + 1 ) * 500 ;
if ( type == V_73 )
V_69 = V_74 ;
else
V_69 = V_75 ;
if ( V_66 > V_72 || V_66 <= 0 )
return - V_38 ;
V_12 = ( V_66 - 1 ) / 500 ;
V_12 |= V_71 ;
return F_5 ( V_2 , V_69 , V_12 , V_9 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_44 ;
V_44 = F_5 ( V_2 , V_13 ,
V_19 , V_14 ) ;
V_2 -> V_18 = F_11 () ;
V_44 = F_5 ( V_2 , V_13 ,
V_15 , V_14 ) ;
return V_44 ;
}
static void F_35 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = F_36 ( V_77 ) ;
struct V_1 * V_2
= F_37 ( V_79 , struct V_1 , V_80 ) ;
F_34 ( V_2 ) ;
}
static T_3 F_38 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
T_4 V_83 ;
T_5 V_84 ;
V_83 = F_11 () ;
V_84 = F_39 ( V_83 ,
V_2 -> V_18 ) ;
if ( V_84 > V_85 )
V_2 -> V_17 = 0 ;
F_40 ( V_86 ) ;
V_2 -> V_17 ++ ;
if ( V_2 -> V_17 == 1 ) {
F_34 ( V_2 ) ;
} else if ( V_2 -> V_17 <= V_2 -> V_87 ) {
F_41 ( & V_2 -> V_80 ,
F_42 ( V_2 -> V_88 ) + 1 ) ;
} else {
F_14 ( V_2 -> V_37 ,
L_5 ,
V_2 -> V_17 ) ;
}
return V_89 ;
}
static void F_43 ( struct V_90 * V_91 )
{
unsigned int V_92 ;
struct V_25 * V_26 = V_91 -> V_26 ;
for (; V_26 < V_91 -> V_26 + V_91 -> V_35 ; V_26 ++ ) {
V_92 = 0 ;
if ( V_26 -> V_36 ) {
V_92 = V_26 -> V_36 - V_26 -> V_34 ;
V_92 = ( V_92 / V_26 -> V_39 ) + 1 ;
}
V_26 -> V_40 = V_92 ;
V_91 -> V_40 += V_92 ;
}
}
static int F_44 ( struct V_1 * V_2 , T_1 V_93 )
{
const struct V_94 * V_95 ;
int V_44 , V_30 ;
T_6 V_96 ;
T_2 V_97 [ V_98 - V_99 + 1 ] ;
T_2 type , V_100 ;
V_44 = F_1 ( V_2 , V_99 , V_97 ,
F_45 ( V_97 ) ) ;
if ( V_44 ) {
F_14 ( V_2 -> V_37 , L_6 ) ;
return V_44 ;
}
V_96 = V_97 [ V_99
- V_99 ] ;
if ( ! V_93 ) {
type = V_97 [ V_101 -
V_99 ] ;
V_100 = V_97 [ V_98 -
V_99 ] ;
} else {
type = V_93 >> 8 ;
V_100 = V_93 ;
}
for ( V_30 = 0 ; V_30 < F_45 ( V_102 ) ; V_30 ++ ) {
V_95 = & V_102 [ V_30 ] ;
if ( V_95 -> type == type && V_95 -> V_100 == V_100
&& V_95 -> V_103 <= V_96
&& V_95 -> V_104 >= V_96 )
goto V_105;
}
F_14 ( V_2 -> V_37 ,
L_7 ,
V_2 -> V_106 . V_107 , type , V_100 , V_96 ) ;
return - V_108 ;
V_105:
V_2 -> V_68 = V_95 -> V_68 ;
V_2 -> V_33 = V_95 -> V_33 ;
V_2 -> V_61 = V_95 -> V_61 ;
V_2 -> V_106 . V_109 = V_95 -> V_109 ;
if ( V_95 -> V_33 ) {
if ( ! V_95 -> V_33 -> V_40 )
F_43 ( V_95 -> V_33 ) ;
V_2 -> V_106 . V_40 = V_95 -> V_33 -> V_40 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_44 ;
T_2 V_12 = 0 ;
int V_110 , V_111 , V_48 ;
const struct V_25 * V_26 ;
V_44 = F_1 ( V_2 , V_112 , & V_12 , 1 ) ;
if ( V_44 ) {
F_14 ( V_2 -> V_37 , L_8 , V_44 ) ;
return V_44 ;
}
V_26 = F_15 ( V_2 ) ;
if ( ! V_26 )
return - V_38 ;
V_110 = V_12 & V_113 ;
V_110 >>= V_114 ;
V_111 = V_12 & V_115 ;
V_111 >>= V_116 ;
V_48 = V_117 * V_26 -> V_39 * ( 1 << V_110 ) ;
V_48 /= 1000 * ( V_118 << V_111 ) ;
V_48 *= V_119 ;
V_48 /= V_120 ;
V_2 -> V_48 = V_72 ( V_48 , 1 ) ;
return V_44 ;
}
static unsigned int F_47 ( unsigned int V_59 )
{
if ( V_59 )
return V_57 ;
return V_58 ;
}
static int F_48 ( struct V_121 * V_122 ,
const struct V_123 * V_106 ,
struct V_124 * V_125 )
{
struct V_1 * V_2 = V_125 -> V_126 ;
struct V_127 * V_37 = V_125 -> V_37 ;
int V_44 ;
V_2 -> V_87 = V_128 ;
V_2 -> V_88 = V_129 ;
if ( V_2 -> V_68 == V_130 ) {
V_44 = F_46 ( V_2 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_2 -> V_68 != V_131 )
V_2 -> V_16 = 0 ;
if ( V_2 -> V_16 ) {
V_44 = F_49 ( V_37 , V_2 -> V_16 ,
F_38 , V_132 , L_9 ,
V_2 ) ;
if ( V_44 < 0 ) {
F_14 ( V_37 , L_10 ,
V_2 -> V_16 , V_44 ) ;
return V_44 ;
}
F_50 ( & V_2 -> V_80 , F_35 ) ;
}
return 0 ;
}
static int F_51 ( struct V_133 * V_134 )
{
const struct V_135 * V_12 ;
const struct V_136 * V_137 ;
struct V_124 V_125 = { } ;
struct V_10 * V_11 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
const char * V_107 ;
struct V_127 * V_37 = & V_134 -> V_37 ;
int V_44 ;
struct V_138 * V_139 ;
V_139 = F_52 ( V_37 , sizeof( * V_139 ) , V_140 ) ;
if ( ! V_139 )
return - V_141 ;
F_53 ( V_139 ) ;
F_54 ( V_134 , V_139 ) ;
V_6 = F_55 ( V_37 -> V_142 , NULL ) ;
if ( ! V_6 )
return - V_108 ;
V_137 = F_56 ( V_143 , & V_134 -> V_37 ) ;
if ( ! V_137 )
return - V_108 ;
for ( V_12 = V_137 -> V_82 ; V_12 -> V_107 ; V_12 ++ ) {
V_2 = F_52 ( V_37 , sizeof( * V_2 ) , V_140 ) ;
if ( ! V_2 )
return - V_141 ;
V_2 -> V_37 = V_37 ;
V_2 -> V_7 = V_12 -> V_7 ;
V_2 -> V_6 = V_6 ;
if ( V_12 -> V_144 ) {
V_2 -> V_16 = F_57 ( V_134 , V_12 -> V_144 ) ;
if ( V_2 -> V_16 < 0 ) {
V_44 = V_2 -> V_16 ;
goto V_145;
}
}
V_2 -> V_106 . V_146 = - 1 ;
V_2 -> V_106 . V_147 = V_148 ;
V_2 -> V_106 . type = V_149 ;
V_2 -> V_106 . V_107 = V_107 = V_12 -> V_107 ;
V_2 -> V_106 . V_150 = V_12 -> V_151 ;
V_2 -> V_106 . V_152 = V_12 -> V_107 ;
V_2 -> V_106 . V_153 = F_48 ;
V_2 -> V_106 . V_154 = F_47 ;
V_44 = F_44 ( V_2 , V_12 -> V_93 ) ;
if ( V_44 )
goto V_145;
V_125 . V_37 = V_37 ;
V_125 . V_126 = V_2 ;
V_11 = F_58 ( V_37 , & V_2 -> V_106 , & V_125 ) ;
if ( F_59 ( V_11 ) ) {
F_14 ( V_37 , L_11 , V_107 ) ;
V_44 = F_60 ( V_11 ) ;
goto V_145;
}
F_53 ( & V_2 -> V_122 ) ;
F_61 ( & V_2 -> V_122 , V_139 ) ;
}
return 0 ;
V_145:
F_62 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_63 ( & V_2 -> V_80 ) ;
return V_44 ;
}
static int F_64 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 = F_65 ( V_134 ) ;
F_62 (vreg, vreg_list, node)
if ( V_2 -> V_16 )
F_63 ( & V_2 -> V_80 ) ;
return 0 ;
}
