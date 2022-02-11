static int F_1 ( int V_1 , int V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; V_4 ++ ) {
if ( V_1 <= V_5 [ V_4 ] && V_2 >= V_5 [ V_4 ] ) {
* V_3 = V_4 ;
return 0 ;
}
}
return - V_6 ;
}
static int F_3 ( struct V_7 * V_8 , int V_1 ,
int V_2 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
T_1 V_11 , V_3 ;
int V_12 ;
V_12 = F_1 ( V_1 , V_2 , & V_3 ) ;
if ( V_12 != 0 )
return V_12 ;
switch ( V_10 ) {
case V_13 :
V_11 = F_6 ( V_9 , V_14 ) &
~ V_15 ;
F_7 ( V_9 , V_14 ,
V_11 | V_3 ) ;
break;
case V_16 :
V_11 = F_6 ( V_9 , V_17 ) &
~ V_15 ;
F_7 ( V_9 , V_17 ,
V_11 | V_3 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_10 ) {
case V_13 :
V_11 = F_6 ( V_9 , V_14 ) &
V_15 ;
break;
case V_16 :
V_11 = F_6 ( V_9 , V_17 ) &
V_15 ;
break;
default:
return 0 ;
}
return V_5 [ V_11 ] ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
switch ( V_10 ) {
case V_13 :
switch ( V_9 -> V_18 . V_19 ) {
case V_20 :
case V_21 :
F_10 ( V_9 , V_22 ,
V_23 ) ;
F_10 ( V_9 , V_24 ,
V_25 ) ;
F_10 ( V_9 , V_26 ,
1 << ( V_9 -> V_18 . V_19 -
V_27 ) ) ;
break;
default:
return - V_6 ;
}
break;
case V_16 :
switch ( V_9 -> V_18 . V_28 ) {
case V_20 :
case V_21 :
F_10 ( V_9 , V_22 ,
V_29 ) ;
F_10 ( V_9 , V_30 ,
V_31 ) ;
F_10 ( V_9 , V_26 ,
1 << ( V_9 -> V_18 . V_28 -
V_27 ) ) ;
break;
default:
return - V_6 ;
}
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
switch ( V_10 ) {
case V_13 :
switch ( V_9 -> V_18 . V_19 ) {
case V_20 :
case V_21 :
F_12 ( V_9 , V_26 ,
1 << ( V_9 -> V_18 . V_19 -
V_27 ) ) ;
F_12 ( V_9 , V_22 ,
V_23 ) ;
break;
default:
return - V_6 ;
}
break;
case V_16 :
switch ( V_9 -> V_18 . V_28 ) {
case V_20 :
case V_21 :
F_12 ( V_9 , V_26 ,
1 << ( V_9 -> V_18 . V_28 -
V_27 ) ) ;
F_12 ( V_9 , V_22 ,
V_29 ) ;
break;
default:
return - V_6 ;
}
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
switch ( V_10 ) {
case V_13 :
return F_6 ( V_9 , V_14 ) &
0x8000 ;
case V_16 :
return F_6 ( V_9 , V_17 ) &
0x8000 ;
}
return - V_6 ;
}
static int F_14 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_10 = F_5 ( V_8 ) ;
int V_32 ;
switch ( V_10 ) {
case V_13 :
V_32 = F_6 ( V_9 , V_24 ) ;
break;
case V_16 :
V_32 = F_6 ( V_9 , V_30 ) ;
break;
default:
return - V_6 ;
}
if ( V_32 & V_33 ) {
switch ( V_32 & V_34 ) {
case 0 :
return 0 ;
case 1 :
return 1950 ;
case 2 :
return 3910 ;
case 3 :
return 7800 ;
}
} else {
switch ( V_32 & V_34 ) {
case 0 :
return 0 ;
case 1 :
return 250000 ;
case 2 :
return 500000 ;
case 3 :
return 1000000 ;
}
}
return - V_6 ;
}
int F_15 ( struct V_9 * V_9 , int V_10 , T_1 V_35 ,
T_1 V_36 , T_1 V_37 , T_1 V_38 , T_1 V_39 ,
T_1 V_40 )
{
switch ( V_10 ) {
case V_13 :
F_7 ( V_9 , V_24 ,
( V_35 ? V_33 : 0 ) |
( V_36 ? V_41 : 0 ) |
V_37 | V_38 | V_39 | V_40 ) ;
break;
case V_16 :
F_7 ( V_9 , V_30 ,
( V_35 ? V_42 : 0 ) |
( V_36 ? V_43 : 0 ) |
V_37 | V_38 | V_39 | V_40 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_8 , int V_44 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_45 , V_46 , V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_1 , V_49 , V_47 , V_44 / 1000 ) ;
switch ( V_47 ) {
case V_27 :
V_46 = V_50 ;
break;
case V_51 :
V_46 = V_52 ;
break;
case V_53 :
V_46 = V_54 ;
break;
case V_55 :
V_46 = V_56 ;
break;
case V_20 :
case V_21 :
default:
return - V_6 ;
}
V_45 = F_18 ( V_8 , V_44 , V_44 ) ;
if ( V_45 < 0 )
return - V_6 ;
V_11 = F_6 ( V_9 , V_46 ) & ~ V_57 ;
F_7 ( V_9 , V_46 , V_11 | V_45 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_47 ) {
case V_27 :
V_11 = F_6 ( V_9 , V_50 )
& ~ V_58 ;
F_7 ( V_9 , V_50 ,
V_11 | V_9 -> V_18 . V_59 ) ;
break;
case V_51 :
V_11 = F_6 ( V_9 , V_52 )
& ~ V_58 ;
F_7 ( V_9 , V_52 ,
V_11 | V_9 -> V_18 . V_60 ) ;
break;
case V_53 :
V_11 = F_6 ( V_9 , V_54 )
& ~ V_58 ;
F_7 ( V_9 , V_54 ,
V_11 | V_9 -> V_18 . V_61 ) ;
break;
case V_55 :
V_11 = F_6 ( V_9 , V_56 )
& ~ V_58 ;
F_7 ( V_9 , V_56 ,
V_11 | V_9 -> V_18 . V_62 ) ;
break;
case V_20 :
case V_21 :
default:
return - V_6 ;
}
return 0 ;
}
static int F_20 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_47 ) {
case V_27 :
V_11 = F_6 ( V_9 , V_50 ) ;
V_9 -> V_18 . V_59 = V_11 & V_58 ;
F_7 ( V_9 , V_50 ,
V_11 | V_63 ) ;
break;
case V_51 :
V_11 = F_6 ( V_9 , V_52 ) ;
V_9 -> V_18 . V_60 = V_11 & V_58 ;
F_7 ( V_9 , V_52 ,
V_11 | V_63 ) ;
break;
case V_53 :
V_11 = F_6 ( V_9 , V_54 ) ;
V_9 -> V_18 . V_61 = V_11 & V_58 ;
F_7 ( V_9 , V_54 ,
V_11 | V_63 ) ;
break;
case V_55 :
V_11 = F_6 ( V_9 , V_56 ) ;
V_9 -> V_18 . V_62 = V_11 & V_58 ;
F_7 ( V_9 , V_56 ,
V_11 | V_63 ) ;
break;
case V_20 :
case V_21 :
default:
return - V_6 ;
}
return 0 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_47 ) {
case V_20 :
V_11 = F_6 ( V_9 , V_64 )
& ~ V_65 ;
F_7 ( V_9 , V_64 , V_11 |
( V_66 << V_67 ) ) ;
break;
case V_21 :
V_11 = F_6 ( V_9 , V_68 )
& ~ V_69 ;
F_7 ( V_9 , V_68 , V_11 |
( V_70 << V_71 ) ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_47 ) {
case V_20 :
V_11 = F_6 ( V_9 , V_64 )
& ~ V_65 ;
F_7 ( V_9 , V_64 , V_11 |
( V_72 << V_67 ) ) ;
break;
case V_21 :
V_11 = F_6 ( V_9 , V_68 )
& ~ V_69 ;
F_7 ( V_9 , V_68 , V_11 |
( V_73 << V_71 ) ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_23 ( struct V_7 * V_8 ,
unsigned int V_35 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 * V_74 ;
switch ( V_47 ) {
case V_27 :
V_74 = & V_9 -> V_18 . V_59 ;
break;
case V_51 :
V_74 = & V_9 -> V_18 . V_60 ;
break;
case V_53 :
V_74 = & V_9 -> V_18 . V_61 ;
break;
case V_55 :
V_74 = & V_9 -> V_18 . V_62 ;
break;
case V_20 :
case V_21 :
default:
return - V_6 ;
}
switch ( V_35 ) {
case V_75 :
* V_74 = V_76 ;
break;
case V_77 :
* V_74 = V_78 ;
break;
case V_79 :
* V_74 = V_80 ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_24 ( struct V_7 * V_8 ,
unsigned V_81 )
{
if ( V_81 > V_82 )
return - V_6 ;
if ( V_81 < 16 )
return ( V_81 * 50000 ) + 900000 ;
else
return ( ( V_81 - 16 ) * 100000 ) + 1800000 ;
}
static int F_25 ( struct V_7 * V_8 , int V_83 ,
int V_84 )
{
int V_85 , V_45 ;
int V_86 = V_83 / 1000 ;
int V_87 = V_84 / 1000 ;
if ( V_86 < 900 || V_86 > 3300 )
return - V_6 ;
if ( V_87 < 900 || V_87 > 3300 )
return - V_6 ;
if ( V_86 < 1800 )
V_45 = F_26 ( V_83 - 900 , 50 ) ;
else
V_45 = F_26 ( V_83 - 1800 , 100 ) + 16 ;
V_85 = F_24 ( V_8 , V_45 ) ;
if ( V_85 < V_83 || V_85 > V_84 )
return - V_6 ;
return V_45 ;
}
static int F_27 ( struct V_7 * V_8 , int V_44 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_45 , V_46 , V_88 = F_5 ( V_8 ) ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_1 , V_49 , V_88 , V_44 / 1000 ) ;
switch ( V_88 ) {
case V_89 :
V_46 = V_90 ;
break;
case V_91 :
V_46 = V_92 ;
break;
case V_93 :
V_46 = V_94 ;
break;
case V_95 :
V_46 = V_96 ;
break;
default:
return - V_6 ;
}
V_45 = F_25 ( V_8 , V_44 , V_44 ) ;
if ( V_45 < 0 )
return - V_6 ;
V_11 = F_6 ( V_9 , V_46 ) & ~ V_82 ;
F_7 ( V_9 , V_46 , V_11 | V_45 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_46 , V_88 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_88 ) {
case V_89 :
V_46 = V_90 ;
break;
case V_91 :
V_46 = V_92 ;
break;
case V_93 :
V_46 = V_94 ;
break;
case V_95 :
V_46 = V_96 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_46 ) & ~ V_97 ;
F_7 ( V_9 , V_46 , V_11 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_46 , V_88 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_88 ) {
case V_89 :
V_46 = V_90 ;
break;
case V_91 :
V_46 = V_92 ;
break;
case V_93 :
V_46 = V_94 ;
break;
case V_95 :
V_46 = V_96 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_46 ) & ~ V_97 ;
F_7 ( V_9 , V_46 , V_11 | V_98 ) ;
return 0 ;
}
int F_30 ( struct V_9 * V_9 , int V_47 , T_1 V_99 ,
T_1 V_100 , T_1 V_101 )
{
int V_102 ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_2 ,
V_49 , V_47 , V_99 , V_100 ) ;
if ( V_99 > 15 || V_100 > 15 )
return - V_6 ;
switch ( V_47 ) {
case V_27 :
V_102 = V_103 ;
break;
case V_20 :
V_102 = V_104 ;
break;
case V_51 :
V_102 = V_105 ;
break;
case V_53 :
V_102 = V_106 ;
break;
case V_21 :
V_102 = V_107 ;
break;
case V_55 :
V_102 = V_108 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_102 ) &
~ ( V_109 | V_110 |
V_111 ) ;
F_7 ( V_9 , V_102 ,
V_11 | ( V_99 << V_112 ) |
( V_100 << V_113 ) |
( V_101 << V_114 ) ) ;
return 0 ;
}
int F_31 ( struct V_9 * V_9 , int V_88 , T_1 V_99 , T_1 V_100 )
{
int V_102 ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_2 ,
V_49 , V_88 , V_99 , V_100 ) ;
if ( V_99 > 15 || V_100 > 15 )
return - V_6 ;
switch ( V_88 ) {
case V_89 :
V_102 = V_115 ;
break;
case V_91 :
V_102 = V_116 ;
break;
case V_93 :
V_102 = V_117 ;
break;
case V_95 :
V_102 = V_118 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_102 ) & ~ V_119 ;
F_7 ( V_9 , V_102 , V_11 | ( ( V_99 << 10 ) | ( V_100 << 6 ) ) ) ;
return 0 ;
}
int F_32 ( struct V_9 * V_9 , int V_47 , T_1 V_35 ,
T_1 V_120 , T_1 V_121 , T_1 V_122 )
{
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_3 , V_49 , V_47 ,
V_35 ? L_4 : L_5 , V_120 ? L_6 : L_4 ) ;
switch ( V_47 ) {
case V_20 :
V_11 = F_6 ( V_9 , V_64 )
& ~ ( V_123 | V_124 |
V_125 | V_126 ) ;
F_7 ( V_9 , V_64 , V_11 |
( V_35 << V_127 ) |
( V_120 << V_128 ) |
( V_121 << V_129 ) |
( V_122 << V_130 ) ) ;
break;
case V_21 :
V_11 = F_6 ( V_9 , V_68 )
& ~ ( V_131 | V_132 |
V_133 | V_134 ) ;
F_7 ( V_9 , V_68 , V_11 |
( V_35 << V_135 ) |
( V_120 << V_136 ) |
( V_121 << V_137 ) |
( V_122 << V_138 ) ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_33 ( struct V_9 * V_9 , int V_47 , int V_139 )
{
int V_32 = 0 , V_12 ;
switch ( V_47 ) {
case V_27 :
V_32 = V_140 ;
break;
case V_51 :
V_32 = V_141 ;
break;
case V_53 :
V_32 = V_142 ;
break;
case V_55 :
V_32 = V_143 ;
break;
default:
return - V_6 ;
}
if ( V_139 )
V_12 = F_10 ( V_9 , V_32 ,
V_144 ) ;
else
V_12 = F_12 ( V_9 , V_32 ,
V_144 ) ;
return V_12 ;
}
static int F_34 ( struct V_7 * V_8 , unsigned int V_35 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_11 ;
if ( V_47 < V_27 || V_47 > V_55 )
return - V_6 ;
if ( V_47 == V_20 || V_47 == V_21 )
return - V_6 ;
V_11 = 1 << ( V_47 - V_27 ) ;
switch ( V_35 ) {
case V_145 :
F_10 ( V_9 , V_146 , V_11 ) ;
F_12 ( V_9 , V_147 , V_11 ) ;
F_33 ( V_9 , V_47 , 1 ) ;
break;
case V_75 :
F_10 ( V_9 , V_146 , V_11 ) ;
F_12 ( V_9 , V_147 , V_11 ) ;
F_33 ( V_9 , V_47 , 0 ) ;
break;
case V_77 :
F_33 ( V_9 , V_47 , 0 ) ;
F_12 ( V_9 , V_147 , V_11 ) ;
F_12 ( V_9 , V_146 , V_11 ) ;
break;
case V_79 :
F_33 ( V_9 , V_47 , 0 ) ;
F_10 ( V_9 , V_147 , V_11 ) ;
break;
}
return 0 ;
}
static unsigned int F_35 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_148 , V_149 , V_150 , V_151 ;
int V_35 = V_75 ;
int V_32 ;
switch ( V_47 ) {
case V_27 :
V_32 = V_140 ;
break;
case V_51 :
V_32 = V_141 ;
break;
case V_53 :
V_32 = V_142 ;
break;
case V_55 :
V_32 = V_143 ;
break;
default:
return - V_6 ;
}
V_148 = 1 << ( V_47 - V_27 ) ;
V_150 = F_6 ( V_9 , V_146 ) & V_148 ;
V_151 = F_6 ( V_9 , V_32 ) & V_144 ;
V_149 = F_6 ( V_9 , V_147 ) & V_148 ;
F_17 ( V_9 -> V_48 , L_7 ,
V_148 , V_150 , V_149 , V_151 ) ;
if ( V_150 && ! V_149 ) {
if ( V_151 )
V_35 = V_145 ;
else
V_35 = V_75 ;
} else if ( ! V_150 && ! V_149 )
V_35 = V_77 ;
else if ( V_149 )
V_35 = V_79 ;
return V_35 ;
}
static unsigned int F_36 ( struct V_7 * V_8 )
{
return V_75 ;
}
static unsigned int F_37 ( int V_152 , const struct V_153 * V_154 )
{
int V_4 = 0 ;
while ( V_154 [ V_4 ] . V_155 != - 1 ) {
if ( V_152 >= V_154 [ V_4 ] . V_155 && V_152 <= V_154 [ V_4 ] . V_156 )
return V_154 [ V_4 ] . V_35 ;
}
return V_75 ;
}
static unsigned int F_38 ( struct V_7 * V_8 ,
int V_157 , int V_158 ,
int V_159 )
{
int V_47 = F_5 ( V_8 ) , V_35 ;
switch ( V_47 ) {
case V_27 :
case V_55 :
V_35 = F_37 ( V_159 , V_160 ) ;
break;
case V_51 :
case V_53 :
V_35 = F_37 ( V_159 , V_161 ) ;
break;
default:
V_35 = V_75 ;
break;
}
return V_35 ;
}
static T_2 F_39 ( int V_162 , void * V_163 )
{
struct V_7 * V_8 = (struct V_7 * ) V_163 ;
struct V_9 * V_9 = F_4 ( V_8 ) ;
F_40 ( & V_8 -> V_164 ) ;
if ( V_162 == V_165 || V_162 == V_166 )
F_41 ( V_8 ,
V_167 ,
V_9 ) ;
else
F_41 ( V_8 ,
V_168 ,
V_9 ) ;
F_42 ( & V_8 -> V_164 ) ;
return V_169 ;
}
static int F_43 ( struct V_170 * V_171 )
{
struct V_9 * V_9 = F_44 ( & V_171 -> V_48 ) ;
struct V_172 V_173 = { } ;
struct V_7 * V_8 ;
int V_12 ;
T_1 V_11 ;
if ( V_171 -> V_174 < V_27 || V_171 -> V_174 > V_16 )
return - V_175 ;
switch ( V_171 -> V_174 ) {
case V_27 :
V_11 = F_6 ( V_9 , V_50 ) ;
V_9 -> V_18 . V_59 = V_11 & V_58 ;
break;
case V_51 :
V_11 = F_6 ( V_9 , V_52 ) ;
V_9 -> V_18 . V_60 = V_11 & V_58 ;
break;
case V_53 :
V_11 = F_6 ( V_9 , V_54 ) ;
V_9 -> V_18 . V_61 = V_11 & V_58 ;
break;
case V_55 :
V_11 = F_6 ( V_9 , V_56 ) ;
V_9 -> V_18 . V_62 = V_11 & V_58 ;
break;
}
V_173 . V_48 = & V_171 -> V_48 ;
V_173 . V_176 = V_171 -> V_48 . V_177 ;
V_173 . V_178 = F_44 ( & V_171 -> V_48 ) ;
V_173 . V_179 = V_9 -> V_179 ;
V_8 = F_45 ( & V_180 [ V_171 -> V_174 ] , & V_173 ) ;
if ( F_46 ( V_8 ) ) {
F_47 ( & V_171 -> V_48 , L_8 ,
V_180 [ V_171 -> V_174 ] . V_181 ) ;
return F_48 ( V_8 ) ;
}
V_12 = F_49 ( V_9 , V_180 [ V_171 -> V_174 ] . V_162 ,
F_39 , 0 , L_9 , V_8 ) ;
if ( V_12 < 0 ) {
F_50 ( V_8 ) ;
F_47 ( & V_171 -> V_48 , L_10 ,
V_180 [ V_171 -> V_174 ] . V_181 ) ;
return V_12 ;
}
return 0 ;
}
static int F_51 ( struct V_170 * V_171 )
{
struct V_7 * V_8 = F_52 ( V_171 ) ;
struct V_9 * V_9 = F_4 ( V_8 ) ;
F_53 ( V_9 , V_180 [ V_171 -> V_174 ] . V_162 , V_8 ) ;
F_50 ( V_8 ) ;
return 0 ;
}
int F_54 ( struct V_9 * V_9 , int V_32 ,
struct V_182 * V_183 )
{
struct V_170 * V_171 ;
int V_12 ;
if ( V_32 < 0 || V_32 >= V_184 )
return - V_6 ;
if ( V_9 -> V_18 . V_171 [ V_32 ] )
return - V_185 ;
if ( V_32 >= V_27 && V_32 <= V_55 &&
V_32 > V_9 -> V_18 . V_186 )
return - V_175 ;
if ( V_32 >= V_13 && V_32 <= V_16 &&
V_32 > V_9 -> V_18 . V_187 )
return - V_175 ;
V_171 = F_55 ( L_11 , V_32 ) ;
if ( ! V_171 )
return - V_188 ;
V_9 -> V_18 . V_171 [ V_32 ] = V_171 ;
V_183 -> V_178 = V_9 ;
V_171 -> V_48 . V_177 = V_183 ;
V_171 -> V_48 . V_189 = V_9 -> V_48 ;
F_56 ( V_171 , V_9 ) ;
V_12 = F_57 ( V_171 ) ;
if ( V_12 != 0 ) {
F_47 ( V_9 -> V_48 , L_12 ,
V_32 , V_12 ) ;
F_58 ( V_171 ) ;
V_9 -> V_18 . V_171 [ V_32 ] = NULL ;
}
return V_12 ;
}
int F_59 ( struct V_9 * V_9 , int V_190 , int V_47 , int V_10 ,
struct V_191 * V_192 )
{
struct V_193 * V_194 ;
struct V_170 * V_171 ;
int V_12 ;
if ( V_190 >= F_2 ( V_9 -> V_18 . V_194 ) || V_190 < 0 ) {
F_47 ( V_9 -> V_48 , L_13 , V_190 ) ;
return - V_175 ;
}
V_194 = & V_9 -> V_18 . V_194 [ V_190 ] ;
if ( V_194 -> V_171 ) {
F_47 ( V_9 -> V_48 , L_14 , V_190 ) ;
return - V_6 ;
}
V_171 = F_55 ( L_15 , V_190 ) ;
if ( V_171 == NULL ) {
F_47 ( V_9 -> V_48 , L_16 , V_190 ) ;
return - V_188 ;
}
V_194 -> V_195 . V_196 = V_196 ( & V_171 -> V_48 ) ;
V_194 -> V_195 . V_197 = L_17 ;
V_194 -> V_198 . V_199 = 1 ;
V_194 -> V_198 . V_200 = & V_194 -> V_195 ;
V_194 -> V_198 . V_201 . V_1 = 0 ;
V_194 -> V_198 . V_201 . V_2 = V_192 -> V_2 ;
V_194 -> V_198 . V_201 . V_202
= V_203 | V_204 ;
V_194 -> V_198 . V_201 . V_205 = V_75 ;
V_12 = F_54 ( V_9 , V_10 , & V_194 -> V_198 ) ;
if ( V_12 != 0 ) {
F_58 ( V_171 ) ;
return V_12 ;
}
V_194 -> V_206 . V_196 = V_196 ( & V_171 -> V_48 ) ;
V_194 -> V_206 . V_197 = L_18 ;
V_194 -> V_207 . V_199 = 1 ;
V_194 -> V_207 . V_200 = & V_194 -> V_206 ;
V_194 -> V_207 . V_201 . V_205 = V_75 ;
V_194 -> V_207 . V_201 . V_202 = V_204 ;
V_12 = F_54 ( V_9 , V_47 , & V_194 -> V_207 ) ;
if ( V_12 != 0 ) {
F_58 ( V_171 ) ;
return V_12 ;
}
switch ( V_10 ) {
case V_13 :
V_9 -> V_18 . V_19 = V_47 ;
break;
case V_16 :
V_9 -> V_18 . V_28 = V_47 ;
break;
}
V_171 -> V_48 . V_177 = V_192 ;
V_171 -> V_48 . V_189 = V_9 -> V_48 ;
V_12 = F_57 ( V_171 ) ;
if ( V_12 != 0 ) {
F_47 ( V_9 -> V_48 , L_19 ,
V_190 , V_12 ) ;
F_58 ( V_171 ) ;
return V_12 ;
}
V_194 -> V_171 = V_171 ;
return 0 ;
}
static int T_3 F_60 ( void )
{
return F_61 ( & V_208 ) ;
}
static void T_4 F_62 ( void )
{
F_63 ( & V_208 ) ;
}
