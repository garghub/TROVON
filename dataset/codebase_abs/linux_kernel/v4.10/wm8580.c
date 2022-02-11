static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_6 ) ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
unsigned int V_3 = V_10 -> V_3 ;
unsigned int V_16 = V_10 -> V_17 ;
int V_18 ;
F_5 ( V_15 -> V_19 , true ) ;
F_6 ( V_15 -> V_19 , V_3 , 0x100 , 0x000 ) ;
F_6 ( V_15 -> V_19 , V_16 , 0x100 , 0x000 ) ;
F_5 ( V_15 -> V_19 , false ) ;
V_18 = F_7 ( V_6 , V_8 ) ;
if ( V_18 < 0 )
return V_18 ;
F_8 ( V_13 , V_3 , 0x100 , 0x100 ) ;
F_8 ( V_13 , V_16 , 0x100 , 0x100 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , unsigned int V_22 ,
unsigned int V_23 )
{
T_1 V_24 ;
unsigned int V_25 , V_26 , V_27 ;
int V_28 ;
F_10 ( L_1 , V_23 , V_22 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_29 ) ; V_28 ++ ) {
if ( V_22 * V_29 [ V_28 ] . div >= 90000000 &&
V_22 * V_29 [ V_28 ] . div <= 100000000 ) {
V_21 -> V_30 = V_29 [ V_28 ] . V_30 ;
V_21 -> V_31 = V_29 [ V_28 ] . V_31 ;
V_22 *= V_29 [ V_28 ] . div ;
break;
}
}
if ( V_28 == F_11 ( V_29 ) ) {
F_12 ( V_32 L_2
L_3 , V_22 ) ;
return - V_33 ;
}
V_26 = V_22 / V_23 ;
if ( V_26 < 5 ) {
V_23 /= 2 ;
V_21 -> V_34 = 1 ;
V_26 = V_22 / V_23 ;
} else
V_21 -> V_34 = 0 ;
if ( ( V_26 < 5 ) || ( V_26 > 13 ) ) {
F_12 ( V_32
L_4 , V_26 ) ;
return - V_33 ;
}
V_21 -> V_35 = V_26 ;
V_27 = V_22 % V_23 ;
V_24 = V_36 * ( long long ) V_27 ;
F_13 ( V_24 , V_23 ) ;
V_25 = V_24 & 0xFFFFFFFF ;
V_21 -> V_37 = V_25 ;
F_10 ( L_5 ,
V_21 -> V_35 , V_21 -> V_37 , V_21 -> V_34 , V_21 -> V_30 ,
V_21 -> V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 , int V_40 ,
int V_23 , unsigned int V_41 , unsigned int V_42 )
{
int V_43 ;
struct V_12 * V_13 = V_39 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_44 * V_45 ;
struct V_20 V_21 ;
unsigned int V_3 ;
unsigned int V_46 ;
int V_18 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
switch ( V_40 ) {
case V_47 :
V_45 = & V_15 -> V_48 ;
V_43 = 0 ;
V_46 = V_49 ;
break;
case V_50 :
V_45 = & V_15 -> V_51 ;
V_43 = 4 ;
V_46 = V_52 ;
break;
default:
return - V_53 ;
}
if ( V_41 && V_42 ) {
V_18 = F_9 ( & V_21 , V_42 , V_41 ) ;
if ( V_18 != 0 )
return V_18 ;
}
V_45 -> V_54 = V_41 ;
V_45 -> V_55 = V_42 ;
F_8 ( V_13 , V_56 , V_46 , V_46 ) ;
if ( ! V_41 || ! V_42 )
return 0 ;
F_15 ( V_13 , V_57 + V_43 , V_21 . V_37 & 0x1ff ) ;
F_15 ( V_13 , V_58 + V_43 , ( V_21 . V_37 >> 9 ) & 0x1ff ) ;
F_15 ( V_13 , V_59 + V_43 ,
( V_21 . V_37 >> 18 & 0xf ) | ( V_21 . V_35 << 4 ) ) ;
V_3 = F_16 ( V_13 , V_60 + V_43 ) ;
V_3 &= ~ 0x1b ;
V_3 |= V_21 . V_34 | V_21 . V_31 << 1 |
V_21 . V_30 << 3 ;
F_15 ( V_13 , V_60 + V_43 , V_3 ) ;
F_8 ( V_13 , V_56 , V_46 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_38 * V_65 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
T_2 V_66 = 0 ;
T_2 V_67 = 0 ;
int V_28 , V_68 , V_69 ;
switch ( F_18 ( V_64 ) ) {
case 16 :
V_66 |= 0x8 ;
break;
case 20 :
V_66 |= 0x0 ;
V_67 |= V_70 ;
break;
case 24 :
V_66 |= 0x0 ;
V_67 |= V_71 ;
break;
case 32 :
V_66 |= 0x0 ;
V_67 |= V_72 ;
break;
default:
return - V_33 ;
}
V_68 = V_15 -> V_73 [ V_65 -> V_74 -> V_75 ] / F_19 ( V_64 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_76 ) ; V_28 ++ )
if ( V_68 == V_76 [ V_28 ] )
break;
if ( V_28 == F_11 ( V_76 ) ) {
F_20 ( V_13 -> V_2 , L_6 ,
V_15 -> V_73 [ V_65 -> V_74 -> V_75 ] , F_19 ( V_64 ) ) ;
return - V_33 ;
}
V_66 |= V_28 ;
F_21 ( V_13 -> V_2 , L_7 ,
V_76 [ V_28 ] , V_15 -> V_73 [ V_65 -> V_74 -> V_75 ] ) ;
if ( V_62 -> V_77 == V_78 ) {
switch ( V_68 ) {
case 128 :
case 192 :
V_69 = V_79 ;
F_21 ( V_13 -> V_2 , L_8 ) ;
break;
default:
V_69 = 0 ;
F_21 ( V_13 -> V_2 , L_9 ) ;
break;
}
F_8 ( V_13 , V_80 , V_79 , V_69 ) ;
}
F_8 ( V_13 , V_81 + V_65 -> V_74 -> V_75 ,
V_82 | V_83 ,
V_66 ) ;
F_8 ( V_13 , V_80 + V_65 -> V_74 -> V_75 ,
V_84 , V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned int V_85 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_86 ;
unsigned int V_87 ;
int V_88 ;
V_86 = F_16 ( V_13 , V_81 + V_39 -> V_74 -> V_75 ) ;
V_87 = F_16 ( V_13 , V_80 + V_39 -> V_74 -> V_75 ) ;
V_87 &= ~ ( V_89 | V_90 | V_91 ) ;
switch ( V_85 & V_92 ) {
case V_93 :
V_86 &= ~ V_94 ;
break;
case V_95 :
V_86 |= V_94 ;
break;
default:
return - V_33 ;
}
switch ( V_85 & V_96 ) {
case V_97 :
V_88 = 1 ;
V_87 |= V_98 ;
break;
case V_99 :
V_88 = 1 ;
V_87 |= V_100 ;
break;
case V_101 :
V_88 = 1 ;
V_87 |= V_102 ;
break;
case V_103 :
V_88 = 0 ;
V_87 |= V_104 ;
break;
case V_105 :
V_88 = 0 ;
V_87 |= V_104 ;
V_87 |= V_90 ;
break;
default:
return - V_33 ;
}
switch ( V_85 & V_106 ) {
case V_107 :
break;
case V_108 :
if ( ! V_88 )
return - V_33 ;
V_87 |= V_91 ;
V_87 |= V_90 ;
break;
case V_109 :
V_87 |= V_91 ;
break;
case V_110 :
if ( ! V_88 )
return - V_33 ;
V_87 |= V_90 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_81 + V_39 -> V_74 -> V_75 , V_86 ) ;
F_15 ( V_13 , V_80 + V_39 -> V_74 -> V_75 , V_87 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 ,
int V_111 , int div )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
switch ( V_111 ) {
case V_112 :
V_3 = F_16 ( V_13 , V_113 ) ;
V_3 &= ~ V_114 ;
switch ( div ) {
case V_115 :
break;
case V_116 :
V_3 |= V_117 ;
break;
case V_118 :
V_3 |= V_119 ;
break;
case V_120 :
V_3 |= V_121 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_113 , V_3 ) ;
break;
case V_122 :
V_3 = F_16 ( V_13 , V_113 ) ;
V_3 &= ~ V_123 ;
switch ( div ) {
case V_124 :
break;
case V_116 :
V_3 |= V_125 ;
break;
case V_118 :
V_3 |= V_126 ;
break;
case V_120 :
V_3 |= V_127 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_113 , V_3 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_24 ( struct V_38 * V_65 , int V_128 ,
unsigned int V_129 , int V_130 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_18 , V_131 , V_132 , V_133 ;
switch ( V_65 -> V_74 -> V_75 ) {
case V_134 :
V_132 = 0x3 ;
V_133 = 0 ;
break;
case V_135 :
V_132 = 0xc ;
V_133 = 2 ;
break;
default:
F_25 ( 1 , L_10 ) ;
return - V_33 ;
}
switch ( V_128 ) {
case V_136 :
if ( V_65 -> V_74 -> V_75 != V_135 )
return - V_33 ;
V_131 = 0 << V_133 ;
break;
case V_116 :
V_131 = 1 << V_133 ;
break;
case V_118 :
V_131 = 2 << V_133 ;
break;
case V_115 :
V_131 = 3 << V_133 ;
break;
default:
F_20 ( V_13 -> V_2 , L_11 , V_128 ) ;
return - V_33 ;
}
V_15 -> V_73 [ V_65 -> V_74 -> V_75 ] = V_129 ;
V_18 = F_8 ( V_13 , V_137 , V_132 , V_131 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_26 ( struct V_38 * V_39 , int V_138 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
V_3 = F_16 ( V_13 , V_139 ) ;
if ( V_138 )
V_3 |= V_140 ;
else
V_3 &= ~ V_140 ;
F_15 ( V_13 , V_139 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_141 V_142 )
{
switch ( V_142 ) {
case V_143 :
case V_144 :
break;
case V_145 :
if ( F_28 ( V_13 ) == V_146 ) {
F_8 ( V_13 , V_147 ,
V_148 |
V_149 , 0 ) ;
F_8 ( V_13 , V_150 ,
0x100 , 0 ) ;
}
break;
case V_146 :
F_8 ( V_13 , V_147 ,
V_148 , V_148 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_61 * V_62 ,
struct V_38 * V_65 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
return F_30 ( V_62 -> V_151 ,
V_152 , 1 , V_15 -> V_153 -> V_154 * 2 ) ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_155 * V_156 = F_32 ( V_13 ) ;
int V_18 = 0 ;
switch ( V_15 -> V_153 -> V_154 ) {
case 4 :
F_33 ( V_13 , V_157 ,
F_11 ( V_157 ) ) ;
F_34 ( V_156 , V_158 ,
F_11 ( V_158 ) ) ;
F_35 ( V_156 , V_159 ,
F_11 ( V_159 ) ) ;
break;
default:
break;
}
V_18 = F_36 ( F_11 ( V_15 -> V_160 ) ,
V_15 -> V_160 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_12 , V_18 ) ;
goto V_161;
}
V_18 = F_15 ( V_13 , V_4 , 0 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_13 , V_18 ) ;
goto V_162;
}
return 0 ;
V_162:
F_37 ( F_11 ( V_15 -> V_160 ) , V_15 -> V_160 ) ;
V_161:
return V_18 ;
}
static int F_38 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
F_37 ( F_11 ( V_15 -> V_160 ) , V_15 -> V_160 ) ;
return 0 ;
}
static int F_39 ( struct V_163 * V_164 ,
const struct V_165 * V_75 )
{
const struct V_166 * V_167 ;
struct V_14 * V_15 ;
int V_18 , V_28 ;
V_15 = F_40 ( & V_164 -> V_2 , sizeof( struct V_14 ) ,
V_168 ) ;
if ( V_15 == NULL )
return - V_169 ;
V_15 -> V_19 = F_41 ( V_164 , & V_170 ) ;
if ( F_42 ( V_15 -> V_19 ) )
return F_43 ( V_15 -> V_19 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_15 -> V_160 ) ; V_28 ++ )
V_15 -> V_160 [ V_28 ] . V_171 = V_172 [ V_28 ] ;
V_18 = F_44 ( & V_164 -> V_2 , F_11 ( V_15 -> V_160 ) ,
V_15 -> V_160 ) ;
if ( V_18 != 0 ) {
F_20 ( & V_164 -> V_2 , L_14 , V_18 ) ;
return V_18 ;
}
F_45 ( V_164 , V_15 ) ;
V_167 = F_46 ( V_173 , & V_164 -> V_2 ) ;
if ( V_167 )
V_15 -> V_153 = V_167 -> V_174 ;
if ( ! V_15 -> V_153 ) {
F_20 ( & V_164 -> V_2 , L_15 ) ;
return - V_33 ;
}
V_18 = F_47 ( & V_164 -> V_2 ,
& V_175 , V_176 , F_11 ( V_176 ) ) ;
return V_18 ;
}
static int F_48 ( struct V_163 * V_177 )
{
F_49 ( & V_177 -> V_2 ) ;
return 0 ;
}
