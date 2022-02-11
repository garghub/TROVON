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
struct V_66 * V_67 = V_62 -> V_68 ;
struct V_12 * V_13 = V_67 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
T_2 V_69 = 0 ;
T_2 V_70 = 0 ;
int V_28 , V_71 , V_72 ;
switch ( F_18 ( V_64 ) ) {
case V_73 :
V_69 |= 0x8 ;
break;
case V_74 :
V_69 |= 0x0 ;
V_70 |= V_75 ;
break;
case V_76 :
V_69 |= 0x0 ;
V_70 |= V_77 ;
break;
case V_78 :
V_69 |= 0x0 ;
V_70 |= V_79 ;
break;
default:
return - V_33 ;
}
V_71 = V_15 -> V_80 [ V_65 -> V_81 -> V_82 ] / F_19 ( V_64 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_83 ) ; V_28 ++ )
if ( V_71 == V_83 [ V_28 ] )
break;
if ( V_28 == F_11 ( V_83 ) ) {
F_20 ( V_13 -> V_2 , L_6 ,
V_15 -> V_80 [ V_65 -> V_81 -> V_82 ] , F_19 ( V_64 ) ) ;
return - V_33 ;
}
V_69 |= V_28 ;
F_21 ( V_13 -> V_2 , L_7 ,
V_83 [ V_28 ] , V_15 -> V_80 [ V_65 -> V_81 -> V_82 ] ) ;
if ( V_62 -> V_84 == V_85 ) {
switch ( V_71 ) {
case 128 :
case 192 :
V_72 = V_86 ;
F_21 ( V_13 -> V_2 , L_8 ) ;
break;
default:
V_72 = 0 ;
F_21 ( V_13 -> V_2 , L_9 ) ;
break;
}
F_8 ( V_13 , V_87 , V_86 , V_72 ) ;
}
F_8 ( V_13 , V_88 + V_65 -> V_81 -> V_82 ,
V_89 | V_90 ,
V_69 ) ;
F_8 ( V_13 , V_87 + V_65 -> V_81 -> V_82 ,
V_91 , V_70 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned int V_92 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_93 ;
unsigned int V_94 ;
int V_95 ;
V_93 = F_16 ( V_13 , V_88 + V_39 -> V_81 -> V_82 ) ;
V_94 = F_16 ( V_13 , V_87 + V_39 -> V_81 -> V_82 ) ;
V_94 &= ~ ( V_96 | V_97 | V_98 ) ;
switch ( V_92 & V_99 ) {
case V_100 :
V_93 &= ~ V_101 ;
break;
case V_102 :
V_93 |= V_101 ;
break;
default:
return - V_33 ;
}
switch ( V_92 & V_103 ) {
case V_104 :
V_95 = 1 ;
V_94 |= V_105 ;
break;
case V_106 :
V_95 = 1 ;
V_94 |= V_107 ;
break;
case V_108 :
V_95 = 1 ;
V_94 |= V_109 ;
break;
case V_110 :
V_95 = 0 ;
V_94 |= V_111 ;
break;
case V_112 :
V_95 = 0 ;
V_94 |= V_111 ;
V_94 |= V_97 ;
break;
default:
return - V_33 ;
}
switch ( V_92 & V_113 ) {
case V_114 :
break;
case V_115 :
if ( ! V_95 )
return - V_33 ;
V_94 |= V_98 ;
V_94 |= V_97 ;
break;
case V_116 :
V_94 |= V_98 ;
break;
case V_117 :
if ( ! V_95 )
return - V_33 ;
V_94 |= V_97 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_88 + V_39 -> V_81 -> V_82 , V_93 ) ;
F_15 ( V_13 , V_87 + V_39 -> V_81 -> V_82 , V_94 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 ,
int V_118 , int div )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
switch ( V_118 ) {
case V_119 :
V_3 = F_16 ( V_13 , V_120 ) ;
V_3 &= ~ V_121 ;
switch ( div ) {
case V_122 :
break;
case V_123 :
V_3 |= V_124 ;
break;
case V_125 :
V_3 |= V_126 ;
break;
case V_127 :
V_3 |= V_128 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_120 , V_3 ) ;
break;
case V_129 :
V_3 = F_16 ( V_13 , V_120 ) ;
V_3 &= ~ V_130 ;
switch ( div ) {
case V_131 :
break;
case V_123 :
V_3 |= V_132 ;
break;
case V_125 :
V_3 |= V_133 ;
break;
case V_127 :
V_3 |= V_134 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_120 , V_3 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_24 ( struct V_38 * V_65 , int V_135 ,
unsigned int V_136 , int V_137 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_18 , V_138 , V_139 , V_140 ;
switch ( V_65 -> V_81 -> V_82 ) {
case V_141 :
V_139 = 0x3 ;
V_140 = 0 ;
break;
case V_142 :
V_139 = 0xc ;
V_140 = 2 ;
break;
default:
F_25 ( 1 , L_10 ) ;
return - V_33 ;
}
switch ( V_135 ) {
case V_143 :
if ( V_65 -> V_81 -> V_82 != V_142 )
return - V_33 ;
V_138 = 0 << V_140 ;
break;
case V_123 :
V_138 = 1 << V_140 ;
break;
case V_125 :
V_138 = 2 << V_140 ;
break;
case V_122 :
V_138 = 3 << V_140 ;
break;
default:
F_20 ( V_13 -> V_2 , L_11 , V_135 ) ;
return - V_33 ;
}
V_15 -> V_80 [ V_65 -> V_81 -> V_82 ] = V_136 ;
V_18 = F_8 ( V_13 , V_144 , V_139 , V_138 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_26 ( struct V_38 * V_39 , int V_145 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
V_3 = F_16 ( V_13 , V_146 ) ;
if ( V_145 )
V_3 |= V_147 ;
else
V_3 &= ~ V_147 ;
F_15 ( V_13 , V_146 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_148 V_149 )
{
switch ( V_149 ) {
case V_150 :
case V_151 :
break;
case V_152 :
if ( V_13 -> V_153 . V_154 == V_155 ) {
F_8 ( V_13 , V_156 ,
V_157 |
V_158 , 0 ) ;
F_8 ( V_13 , V_159 ,
0x100 , 0 ) ;
}
break;
case V_155 :
F_8 ( V_13 , V_156 ,
V_157 , V_157 ) ;
break;
}
V_13 -> V_153 . V_154 = V_149 ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_18 = 0 ;
V_18 = F_29 ( V_13 , 7 , 9 , V_160 ) ;
if ( V_18 < 0 ) {
F_20 ( V_13 -> V_2 , L_12 , V_18 ) ;
return V_18 ;
}
V_18 = F_30 ( F_11 ( V_15 -> V_161 ) ,
V_15 -> V_161 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_13 , V_18 ) ;
goto V_162;
}
V_18 = F_15 ( V_13 , V_4 , 0 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_14 , V_18 ) ;
goto V_163;
}
F_27 ( V_13 , V_152 ) ;
return 0 ;
V_163:
F_31 ( F_11 ( V_15 -> V_161 ) , V_15 -> V_161 ) ;
V_162:
return V_18 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
F_27 ( V_13 , V_155 ) ;
F_31 ( F_11 ( V_15 -> V_161 ) , V_15 -> V_161 ) ;
return 0 ;
}
static int F_33 ( struct V_164 * V_165 ,
const struct V_166 * V_82 )
{
struct V_14 * V_15 ;
int V_18 , V_28 ;
V_15 = F_34 ( & V_165 -> V_2 , sizeof( struct V_14 ) ,
V_167 ) ;
if ( V_15 == NULL )
return - V_168 ;
V_15 -> V_19 = F_35 ( V_165 , & V_169 ) ;
if ( F_36 ( V_15 -> V_19 ) )
return F_37 ( V_15 -> V_19 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_15 -> V_161 ) ; V_28 ++ )
V_15 -> V_161 [ V_28 ] . V_170 = V_171 [ V_28 ] ;
V_18 = F_38 ( & V_165 -> V_2 , F_11 ( V_15 -> V_161 ) ,
V_15 -> V_161 ) ;
if ( V_18 != 0 ) {
F_20 ( & V_165 -> V_2 , L_15 , V_18 ) ;
return V_18 ;
}
F_39 ( V_165 , V_15 ) ;
V_18 = F_40 ( & V_165 -> V_2 ,
& V_172 , V_173 , F_11 ( V_173 ) ) ;
return V_18 ;
}
static int F_41 ( struct V_164 * V_174 )
{
F_42 ( & V_174 -> V_2 ) ;
return 0 ;
}
static int T_3 F_43 ( void )
{
int V_18 = 0 ;
#if F_44 ( V_175 )
V_18 = F_45 ( & V_176 ) ;
if ( V_18 != 0 ) {
F_46 ( L_16 , V_18 ) ;
}
#endif
return V_18 ;
}
static void T_4 F_47 ( void )
{
#if F_44 ( V_175 )
F_48 ( & V_176 ) ;
#endif
}
