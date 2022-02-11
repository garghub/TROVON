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
static int F_24 ( struct V_7 * V_8 , int V_44 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_45 , V_46 , V_81 = F_5 ( V_8 ) ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_1 , V_49 , V_81 , V_44 / 1000 ) ;
switch ( V_81 ) {
case V_82 :
V_46 = V_83 ;
break;
case V_84 :
V_46 = V_85 ;
break;
case V_86 :
V_46 = V_87 ;
break;
case V_88 :
V_46 = V_89 ;
break;
default:
return - V_6 ;
}
V_45 = F_25 ( V_8 , V_44 , V_44 ) ;
if ( V_45 < 0 )
return - V_6 ;
V_11 = F_6 ( V_9 , V_46 ) & ~ V_90 ;
F_7 ( V_9 , V_46 , V_11 | V_45 ) ;
return 0 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_46 , V_81 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_81 ) {
case V_82 :
V_46 = V_83 ;
break;
case V_84 :
V_46 = V_85 ;
break;
case V_86 :
V_46 = V_87 ;
break;
case V_88 :
V_46 = V_89 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_46 ) & ~ V_91 ;
F_7 ( V_9 , V_46 , V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_46 , V_81 = F_5 ( V_8 ) ;
T_1 V_11 ;
switch ( V_81 ) {
case V_82 :
V_46 = V_83 ;
break;
case V_84 :
V_46 = V_85 ;
break;
case V_86 :
V_46 = V_87 ;
break;
case V_88 :
V_46 = V_89 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_46 ) & ~ V_91 ;
F_7 ( V_9 , V_46 , V_11 | V_92 ) ;
return 0 ;
}
int F_28 ( struct V_9 * V_9 , int V_47 , T_1 V_93 ,
T_1 V_94 , T_1 V_95 )
{
int V_96 ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_2 ,
V_49 , V_47 , V_93 , V_94 ) ;
if ( V_93 > 15 || V_94 > 15 )
return - V_6 ;
switch ( V_47 ) {
case V_27 :
V_96 = V_97 ;
break;
case V_20 :
V_96 = V_98 ;
break;
case V_51 :
V_96 = V_99 ;
break;
case V_53 :
V_96 = V_100 ;
break;
case V_21 :
V_96 = V_101 ;
break;
case V_55 :
V_96 = V_102 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_96 ) &
~ ( V_103 | V_104 |
V_105 ) ;
F_7 ( V_9 , V_96 ,
V_11 | ( V_93 << V_106 ) |
( V_94 << V_107 ) |
( V_95 << V_108 ) ) ;
return 0 ;
}
int F_29 ( struct V_9 * V_9 , int V_81 , T_1 V_93 , T_1 V_94 )
{
int V_96 ;
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_2 ,
V_49 , V_81 , V_93 , V_94 ) ;
if ( V_93 > 15 || V_94 > 15 )
return - V_6 ;
switch ( V_81 ) {
case V_82 :
V_96 = V_109 ;
break;
case V_84 :
V_96 = V_110 ;
break;
case V_86 :
V_96 = V_111 ;
break;
case V_88 :
V_96 = V_112 ;
break;
default:
return - V_6 ;
}
V_11 = F_6 ( V_9 , V_96 ) & ~ V_113 ;
F_7 ( V_9 , V_96 , V_11 | ( ( V_93 << 10 ) | ( V_94 << 6 ) ) ) ;
return 0 ;
}
int F_30 ( struct V_9 * V_9 , int V_47 , T_1 V_35 ,
T_1 V_114 , T_1 V_115 , T_1 V_116 )
{
T_1 V_11 ;
F_17 ( V_9 -> V_48 , L_3 , V_49 , V_47 ,
V_35 ? L_4 : L_5 , V_114 ? L_6 : L_4 ) ;
switch ( V_47 ) {
case V_20 :
V_11 = F_6 ( V_9 , V_64 )
& ~ ( V_117 | V_118 |
V_119 | V_120 ) ;
F_7 ( V_9 , V_64 , V_11 |
( V_35 << V_121 ) |
( V_114 << V_122 ) |
( V_115 << V_123 ) |
( V_116 << V_124 ) ) ;
break;
case V_21 :
V_11 = F_6 ( V_9 , V_68 )
& ~ ( V_125 | V_126 |
V_127 | V_128 ) ;
F_7 ( V_9 , V_68 , V_11 |
( V_35 << V_129 ) |
( V_114 << V_130 ) |
( V_115 << V_131 ) |
( V_116 << V_132 ) ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_9 , int V_47 , int V_133 )
{
int V_32 = 0 , V_12 ;
switch ( V_47 ) {
case V_27 :
V_32 = V_134 ;
break;
case V_51 :
V_32 = V_135 ;
break;
case V_53 :
V_32 = V_136 ;
break;
case V_55 :
V_32 = V_137 ;
break;
default:
return - V_6 ;
}
if ( V_133 )
V_12 = F_10 ( V_9 , V_32 ,
V_138 ) ;
else
V_12 = F_12 ( V_9 , V_32 ,
V_138 ) ;
return V_12 ;
}
static int F_32 ( struct V_7 * V_8 , unsigned int V_35 )
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
case V_139 :
F_10 ( V_9 , V_140 , V_11 ) ;
F_12 ( V_9 , V_141 , V_11 ) ;
F_31 ( V_9 , V_47 , 1 ) ;
break;
case V_75 :
F_10 ( V_9 , V_140 , V_11 ) ;
F_12 ( V_9 , V_141 , V_11 ) ;
F_31 ( V_9 , V_47 , 0 ) ;
break;
case V_77 :
F_31 ( V_9 , V_47 , 0 ) ;
F_12 ( V_9 , V_141 , V_11 ) ;
F_12 ( V_9 , V_140 , V_11 ) ;
break;
case V_79 :
F_31 ( V_9 , V_47 , 0 ) ;
F_10 ( V_9 , V_141 , V_11 ) ;
break;
}
return 0 ;
}
static unsigned int F_33 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = F_4 ( V_8 ) ;
int V_47 = F_5 ( V_8 ) ;
T_1 V_142 , V_143 , V_144 , V_145 ;
int V_35 = V_75 ;
int V_32 ;
switch ( V_47 ) {
case V_27 :
V_32 = V_134 ;
break;
case V_51 :
V_32 = V_135 ;
break;
case V_53 :
V_32 = V_136 ;
break;
case V_55 :
V_32 = V_137 ;
break;
default:
return - V_6 ;
}
V_142 = 1 << ( V_47 - V_27 ) ;
V_144 = F_6 ( V_9 , V_140 ) & V_142 ;
V_145 = F_6 ( V_9 , V_32 ) & V_138 ;
V_143 = F_6 ( V_9 , V_141 ) & V_142 ;
F_17 ( V_9 -> V_48 , L_7 ,
V_142 , V_144 , V_143 , V_145 ) ;
if ( V_144 && ! V_143 ) {
if ( V_145 )
V_35 = V_139 ;
else
V_35 = V_75 ;
} else if ( ! V_144 && ! V_143 )
V_35 = V_77 ;
else if ( V_143 )
V_35 = V_79 ;
return V_35 ;
}
static unsigned int F_34 ( struct V_7 * V_8 )
{
return V_75 ;
}
static unsigned int F_35 ( int V_146 , const struct V_147 * V_148 )
{
int V_4 = 0 ;
while ( V_148 [ V_4 ] . V_149 != - 1 ) {
if ( V_146 >= V_148 [ V_4 ] . V_149 && V_146 <= V_148 [ V_4 ] . V_150 )
return V_148 [ V_4 ] . V_35 ;
}
return V_75 ;
}
static unsigned int F_36 ( struct V_7 * V_8 ,
int V_151 , int V_152 ,
int V_153 )
{
int V_47 = F_5 ( V_8 ) , V_35 ;
switch ( V_47 ) {
case V_27 :
case V_55 :
V_35 = F_35 ( V_153 , V_154 ) ;
break;
case V_51 :
case V_53 :
V_35 = F_35 ( V_153 , V_155 ) ;
break;
default:
V_35 = V_75 ;
break;
}
return V_35 ;
}
static T_2 F_37 ( int V_156 , void * V_157 )
{
struct V_7 * V_8 = (struct V_7 * ) V_157 ;
struct V_9 * V_9 = F_4 ( V_8 ) ;
F_38 ( & V_8 -> V_158 ) ;
if ( V_156 == V_159 || V_156 == V_160 )
F_39 ( V_8 ,
V_161 ,
V_9 ) ;
else
F_39 ( V_8 ,
V_162 ,
V_9 ) ;
F_40 ( & V_8 -> V_158 ) ;
return V_163 ;
}
static int F_41 ( struct V_164 * V_165 )
{
struct V_9 * V_9 = F_42 ( & V_165 -> V_48 ) ;
struct V_166 V_167 = { } ;
struct V_7 * V_8 ;
int V_12 ;
T_1 V_11 ;
if ( V_165 -> V_168 < V_27 || V_165 -> V_168 > V_16 )
return - V_169 ;
switch ( V_165 -> V_168 ) {
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
V_167 . V_48 = & V_165 -> V_48 ;
V_167 . V_170 = F_43 ( & V_165 -> V_48 ) ;
V_167 . V_171 = F_42 ( & V_165 -> V_48 ) ;
V_167 . V_172 = V_9 -> V_172 ;
V_8 = F_44 ( & V_165 -> V_48 , & V_173 [ V_165 -> V_168 ] ,
& V_167 ) ;
if ( F_45 ( V_8 ) ) {
F_46 ( & V_165 -> V_48 , L_8 ,
V_173 [ V_165 -> V_168 ] . V_174 ) ;
return F_47 ( V_8 ) ;
}
V_12 = F_48 ( V_9 , V_173 [ V_165 -> V_168 ] . V_156 ,
F_37 , 0 , L_9 , V_8 ) ;
if ( V_12 < 0 ) {
F_46 ( & V_165 -> V_48 , L_10 ,
V_173 [ V_165 -> V_168 ] . V_174 ) ;
return V_12 ;
}
return 0 ;
}
static int F_49 ( struct V_164 * V_165 )
{
struct V_7 * V_8 = F_50 ( V_165 ) ;
struct V_9 * V_9 = F_4 ( V_8 ) ;
F_51 ( V_9 , V_173 [ V_165 -> V_168 ] . V_156 , V_8 ) ;
return 0 ;
}
int F_52 ( struct V_9 * V_9 , int V_32 ,
struct V_175 * V_176 )
{
struct V_164 * V_165 ;
int V_12 ;
if ( V_32 < 0 || V_32 >= V_177 )
return - V_6 ;
if ( V_9 -> V_18 . V_165 [ V_32 ] )
return - V_178 ;
if ( V_32 >= V_27 && V_32 <= V_55 &&
V_32 > V_9 -> V_18 . V_179 )
return - V_169 ;
if ( V_32 >= V_13 && V_32 <= V_16 &&
V_32 > V_9 -> V_18 . V_180 )
return - V_169 ;
V_165 = F_53 ( L_11 , V_32 ) ;
if ( ! V_165 )
return - V_181 ;
V_9 -> V_18 . V_165 [ V_32 ] = V_165 ;
V_176 -> V_171 = V_9 ;
V_165 -> V_48 . V_182 = V_176 ;
V_165 -> V_48 . V_183 = V_9 -> V_48 ;
F_54 ( V_165 , V_9 ) ;
V_12 = F_55 ( V_165 ) ;
if ( V_12 != 0 ) {
F_46 ( V_9 -> V_48 , L_12 ,
V_32 , V_12 ) ;
F_56 ( V_165 ) ;
V_9 -> V_18 . V_165 [ V_32 ] = NULL ;
}
return V_12 ;
}
int F_57 ( struct V_9 * V_9 , int V_184 , int V_47 , int V_10 ,
struct V_185 * V_186 )
{
struct V_187 * V_188 ;
struct V_164 * V_165 ;
int V_12 ;
if ( V_184 >= F_2 ( V_9 -> V_18 . V_188 ) || V_184 < 0 ) {
F_46 ( V_9 -> V_48 , L_13 , V_184 ) ;
return - V_169 ;
}
V_188 = & V_9 -> V_18 . V_188 [ V_184 ] ;
if ( V_188 -> V_165 ) {
F_46 ( V_9 -> V_48 , L_14 , V_184 ) ;
return - V_6 ;
}
V_165 = F_53 ( L_15 , V_184 ) ;
if ( V_165 == NULL ) {
F_46 ( V_9 -> V_48 , L_16 , V_184 ) ;
return - V_181 ;
}
V_188 -> V_189 . V_190 = V_190 ( & V_165 -> V_48 ) ;
V_188 -> V_189 . V_191 = L_17 ;
V_188 -> V_192 . V_193 = 1 ;
V_188 -> V_192 . V_194 = & V_188 -> V_189 ;
V_188 -> V_192 . V_195 . V_1 = 0 ;
V_188 -> V_192 . V_195 . V_2 = V_186 -> V_2 ;
V_188 -> V_192 . V_195 . V_196
= V_197 | V_198 ;
V_188 -> V_192 . V_195 . V_199 = V_75 ;
V_12 = F_52 ( V_9 , V_10 , & V_188 -> V_192 ) ;
if ( V_12 != 0 ) {
F_56 ( V_165 ) ;
return V_12 ;
}
V_188 -> V_200 . V_190 = V_190 ( & V_165 -> V_48 ) ;
V_188 -> V_200 . V_191 = L_18 ;
V_188 -> V_201 . V_193 = 1 ;
V_188 -> V_201 . V_194 = & V_188 -> V_200 ;
V_188 -> V_201 . V_195 . V_199 = V_75 ;
V_188 -> V_201 . V_195 . V_196 = V_198 ;
V_12 = F_52 ( V_9 , V_47 , & V_188 -> V_201 ) ;
if ( V_12 != 0 ) {
F_56 ( V_165 ) ;
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
V_165 -> V_48 . V_182 = V_186 ;
V_165 -> V_48 . V_183 = V_9 -> V_48 ;
V_12 = F_55 ( V_165 ) ;
if ( V_12 != 0 ) {
F_46 ( V_9 -> V_48 , L_19 ,
V_184 , V_12 ) ;
F_56 ( V_165 ) ;
return V_12 ;
}
V_188 -> V_165 = V_165 ;
return 0 ;
}
static int T_3 F_58 ( void )
{
return F_59 ( & V_202 ) ;
}
static void T_4 F_60 ( void )
{
F_61 ( & V_202 ) ;
}
