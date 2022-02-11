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
case V_70 :
V_66 |= 0x8 ;
break;
case V_71 :
V_66 |= 0x0 ;
V_67 |= V_72 ;
break;
case V_73 :
V_66 |= 0x0 ;
V_67 |= V_74 ;
break;
case V_75 :
V_66 |= 0x0 ;
V_67 |= V_76 ;
break;
default:
return - V_33 ;
}
V_68 = V_15 -> V_77 [ V_65 -> V_78 -> V_79 ] / F_19 ( V_64 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_80 ) ; V_28 ++ )
if ( V_68 == V_80 [ V_28 ] )
break;
if ( V_28 == F_11 ( V_80 ) ) {
F_20 ( V_13 -> V_2 , L_6 ,
V_15 -> V_77 [ V_65 -> V_78 -> V_79 ] , F_19 ( V_64 ) ) ;
return - V_33 ;
}
V_66 |= V_28 ;
F_21 ( V_13 -> V_2 , L_7 ,
V_80 [ V_28 ] , V_15 -> V_77 [ V_65 -> V_78 -> V_79 ] ) ;
if ( V_62 -> V_81 == V_82 ) {
switch ( V_68 ) {
case 128 :
case 192 :
V_69 = V_83 ;
F_21 ( V_13 -> V_2 , L_8 ) ;
break;
default:
V_69 = 0 ;
F_21 ( V_13 -> V_2 , L_9 ) ;
break;
}
F_8 ( V_13 , V_84 , V_83 , V_69 ) ;
}
F_8 ( V_13 , V_85 + V_65 -> V_78 -> V_79 ,
V_86 | V_87 ,
V_66 ) ;
F_8 ( V_13 , V_84 + V_65 -> V_78 -> V_79 ,
V_88 , V_67 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 ,
unsigned int V_89 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_90 ;
unsigned int V_91 ;
int V_92 ;
V_90 = F_16 ( V_13 , V_85 + V_39 -> V_78 -> V_79 ) ;
V_91 = F_16 ( V_13 , V_84 + V_39 -> V_78 -> V_79 ) ;
V_91 &= ~ ( V_93 | V_94 | V_95 ) ;
switch ( V_89 & V_96 ) {
case V_97 :
V_90 &= ~ V_98 ;
break;
case V_99 :
V_90 |= V_98 ;
break;
default:
return - V_33 ;
}
switch ( V_89 & V_100 ) {
case V_101 :
V_92 = 1 ;
V_91 |= V_102 ;
break;
case V_103 :
V_92 = 1 ;
V_91 |= V_104 ;
break;
case V_105 :
V_92 = 1 ;
V_91 |= V_106 ;
break;
case V_107 :
V_92 = 0 ;
V_91 |= V_108 ;
break;
case V_109 :
V_92 = 0 ;
V_91 |= V_108 ;
V_91 |= V_94 ;
break;
default:
return - V_33 ;
}
switch ( V_89 & V_110 ) {
case V_111 :
break;
case V_112 :
if ( ! V_92 )
return - V_33 ;
V_91 |= V_95 ;
V_91 |= V_94 ;
break;
case V_113 :
V_91 |= V_95 ;
break;
case V_114 :
if ( ! V_92 )
return - V_33 ;
V_91 |= V_94 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_85 + V_39 -> V_78 -> V_79 , V_90 ) ;
F_15 ( V_13 , V_84 + V_39 -> V_78 -> V_79 , V_91 ) ;
return 0 ;
}
static int F_23 ( struct V_38 * V_39 ,
int V_115 , int div )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
switch ( V_115 ) {
case V_116 :
V_3 = F_16 ( V_13 , V_117 ) ;
V_3 &= ~ V_118 ;
switch ( div ) {
case V_119 :
break;
case V_120 :
V_3 |= V_121 ;
break;
case V_122 :
V_3 |= V_123 ;
break;
case V_124 :
V_3 |= V_125 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_117 , V_3 ) ;
break;
case V_126 :
V_3 = F_16 ( V_13 , V_117 ) ;
V_3 &= ~ V_127 ;
switch ( div ) {
case V_128 :
break;
case V_120 :
V_3 |= V_129 ;
break;
case V_122 :
V_3 |= V_130 ;
break;
case V_124 :
V_3 |= V_131 ;
break;
default:
return - V_33 ;
}
F_15 ( V_13 , V_117 , V_3 ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_24 ( struct V_38 * V_65 , int V_132 ,
unsigned int V_133 , int V_134 )
{
struct V_12 * V_13 = V_65 -> V_13 ;
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_18 , V_135 , V_136 , V_137 ;
switch ( V_65 -> V_78 -> V_79 ) {
case V_138 :
V_136 = 0x3 ;
V_137 = 0 ;
break;
case V_139 :
V_136 = 0xc ;
V_137 = 2 ;
break;
default:
F_25 ( 1 , L_10 ) ;
return - V_33 ;
}
switch ( V_132 ) {
case V_140 :
if ( V_65 -> V_78 -> V_79 != V_139 )
return - V_33 ;
V_135 = 0 << V_137 ;
break;
case V_120 :
V_135 = 1 << V_137 ;
break;
case V_122 :
V_135 = 2 << V_137 ;
break;
case V_119 :
V_135 = 3 << V_137 ;
break;
default:
F_20 ( V_13 -> V_2 , L_11 , V_132 ) ;
return - V_33 ;
}
V_15 -> V_77 [ V_65 -> V_78 -> V_79 ] = V_133 ;
V_18 = F_8 ( V_13 , V_141 , V_136 , V_135 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_26 ( struct V_38 * V_39 , int V_142 )
{
struct V_12 * V_13 = V_39 -> V_13 ;
unsigned int V_3 ;
V_3 = F_16 ( V_13 , V_143 ) ;
if ( V_142 )
V_3 |= V_144 ;
else
V_3 &= ~ V_144 ;
F_15 ( V_13 , V_143 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_12 * V_13 ,
enum V_145 V_146 )
{
switch ( V_146 ) {
case V_147 :
case V_148 :
break;
case V_149 :
if ( V_13 -> V_150 . V_151 == V_152 ) {
F_8 ( V_13 , V_153 ,
V_154 |
V_155 , 0 ) ;
F_8 ( V_13 , V_156 ,
0x100 , 0 ) ;
}
break;
case V_152 :
F_8 ( V_13 , V_153 ,
V_154 , V_154 ) ;
break;
}
V_13 -> V_150 . V_151 = V_146 ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
int V_18 = 0 ;
V_18 = F_29 ( F_11 ( V_15 -> V_157 ) ,
V_15 -> V_157 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_12 , V_18 ) ;
goto V_158;
}
V_18 = F_15 ( V_13 , V_4 , 0 ) ;
if ( V_18 != 0 ) {
F_20 ( V_13 -> V_2 , L_13 , V_18 ) ;
goto V_159;
}
F_27 ( V_13 , V_149 ) ;
return 0 ;
V_159:
F_30 ( F_11 ( V_15 -> V_157 ) , V_15 -> V_157 ) ;
V_158:
return V_18 ;
}
static int F_31 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
F_27 ( V_13 , V_152 ) ;
F_30 ( F_11 ( V_15 -> V_157 ) , V_15 -> V_157 ) ;
return 0 ;
}
static int F_32 ( struct V_160 * V_161 ,
const struct V_162 * V_79 )
{
struct V_14 * V_15 ;
int V_18 , V_28 ;
V_15 = F_33 ( & V_161 -> V_2 , sizeof( struct V_14 ) ,
V_163 ) ;
if ( V_15 == NULL )
return - V_164 ;
V_15 -> V_19 = F_34 ( V_161 , & V_165 ) ;
if ( F_35 ( V_15 -> V_19 ) )
return F_36 ( V_15 -> V_19 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_15 -> V_157 ) ; V_28 ++ )
V_15 -> V_157 [ V_28 ] . V_166 = V_167 [ V_28 ] ;
V_18 = F_37 ( & V_161 -> V_2 , F_11 ( V_15 -> V_157 ) ,
V_15 -> V_157 ) ;
if ( V_18 != 0 ) {
F_20 ( & V_161 -> V_2 , L_14 , V_18 ) ;
return V_18 ;
}
F_38 ( V_161 , V_15 ) ;
V_18 = F_39 ( & V_161 -> V_2 ,
& V_168 , V_169 , F_11 ( V_169 ) ) ;
return V_18 ;
}
static int F_40 ( struct V_160 * V_170 )
{
F_41 ( & V_170 -> V_2 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
int V_18 = 0 ;
#if F_43 ( V_171 )
V_18 = F_44 ( & V_172 ) ;
if ( V_18 != 0 ) {
F_45 ( L_15 , V_18 ) ;
}
#endif
return V_18 ;
}
static void T_4 F_46 ( void )
{
#if F_43 ( V_171 )
F_47 ( & V_172 ) ;
#endif
}
