static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 * V_10 = V_9 -> V_10 ;
unsigned int V_11 = V_6 -> V_11 ;
unsigned int V_12 = V_6 -> V_13 ;
int V_14 ;
V_10 [ V_11 ] = 0 ;
V_10 [ V_12 ] = 0 ;
V_14 = F_3 ( V_2 , V_4 ) ;
if ( V_14 < 0 )
return V_14 ;
F_4 ( V_9 , V_11 , 0x100 , 0x100 ) ;
F_4 ( V_9 , V_12 , 0x100 , 0x100 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_15 * V_16 = & V_9 -> V_16 ;
F_6 ( V_16 , V_17 ,
F_7 ( V_17 ) ) ;
F_8 ( V_16 , V_18 , F_7 ( V_18 ) ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 , unsigned int V_21 ,
unsigned int V_22 )
{
T_2 V_23 ;
unsigned int V_24 , V_25 , V_26 ;
int V_27 ;
F_10 ( L_1 , V_22 , V_21 ) ;
for ( V_27 = 0 ; V_27 < F_7 ( V_28 ) ; V_27 ++ ) {
if ( V_21 * V_28 [ V_27 ] . div >= 90000000 &&
V_21 * V_28 [ V_27 ] . div <= 100000000 ) {
V_20 -> V_29 = V_28 [ V_27 ] . V_29 ;
V_20 -> V_30 = V_28 [ V_27 ] . V_30 ;
V_21 *= V_28 [ V_27 ] . div ;
break;
}
}
if ( V_27 == F_7 ( V_28 ) ) {
F_11 ( V_31 L_2
L_3 , V_21 ) ;
return - V_32 ;
}
V_25 = V_21 / V_22 ;
if ( V_25 < 5 ) {
V_22 /= 2 ;
V_20 -> V_33 = 1 ;
V_25 = V_21 / V_22 ;
} else
V_20 -> V_33 = 0 ;
if ( ( V_25 < 5 ) || ( V_25 > 13 ) ) {
F_11 ( V_31
L_4 , V_25 ) ;
return - V_32 ;
}
V_20 -> V_34 = V_25 ;
V_26 = V_21 % V_22 ;
V_23 = V_35 * ( long long ) V_26 ;
F_12 ( V_23 , V_22 ) ;
V_24 = V_23 & 0xFFFFFFFF ;
V_20 -> V_36 = V_24 ;
F_10 ( L_5 ,
V_20 -> V_34 , V_20 -> V_36 , V_20 -> V_33 , V_20 -> V_29 ,
V_20 -> V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_37 * V_38 , int V_39 ,
int V_22 , unsigned int V_40 , unsigned int V_41 )
{
int V_42 ;
struct V_8 * V_9 = V_38 -> V_9 ;
struct V_43 * V_44 = F_14 ( V_9 ) ;
struct V_45 * V_46 ;
struct V_19 V_20 ;
unsigned int V_11 ;
unsigned int V_47 ;
int V_14 ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
switch ( V_39 ) {
case V_48 :
V_46 = & V_44 -> V_49 ;
V_42 = 0 ;
V_47 = V_50 ;
break;
case V_51 :
V_46 = & V_44 -> V_52 ;
V_42 = 4 ;
V_47 = V_53 ;
break;
default:
return - V_54 ;
}
if ( V_40 && V_41 ) {
V_14 = F_9 ( & V_20 , V_41 , V_40 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_46 -> V_55 = V_40 ;
V_46 -> V_56 = V_41 ;
F_4 ( V_9 , V_57 , V_47 , V_47 ) ;
if ( ! V_40 || ! V_41 )
return 0 ;
F_15 ( V_9 , V_58 + V_42 , V_20 . V_36 & 0x1ff ) ;
F_15 ( V_9 , V_59 + V_42 , ( V_20 . V_36 >> 9 ) & 0x1ff ) ;
F_15 ( V_9 , V_60 + V_42 ,
( V_20 . V_36 >> 18 & 0xf ) | ( V_20 . V_34 << 4 ) ) ;
V_11 = F_16 ( V_9 , V_61 + V_42 ) ;
V_11 &= ~ 0x1b ;
V_11 |= V_20 . V_33 | V_20 . V_30 << 1 |
V_20 . V_29 << 3 ;
F_15 ( V_9 , V_61 + V_42 , V_11 ) ;
F_4 ( V_9 , V_57 , V_47 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_62 * V_63 ,
struct V_64 * V_65 ,
struct V_37 * V_66 )
{
struct V_67 * V_68 = V_63 -> V_69 ;
struct V_8 * V_9 = V_68 -> V_9 ;
struct V_43 * V_44 = F_14 ( V_9 ) ;
T_1 V_70 = 0 ;
T_1 V_71 = 0 ;
int V_27 , V_72 , V_73 ;
switch ( F_18 ( V_65 ) ) {
case V_74 :
V_70 |= 0x8 ;
break;
case V_75 :
V_70 |= 0x0 ;
V_71 |= V_76 ;
break;
case V_77 :
V_70 |= 0x0 ;
V_71 |= V_78 ;
break;
case V_79 :
V_70 |= 0x0 ;
V_71 |= V_80 ;
break;
default:
return - V_32 ;
}
V_72 = V_44 -> V_81 [ V_66 -> V_82 -> V_83 ] / F_19 ( V_65 ) ;
for ( V_27 = 0 ; V_27 < F_7 ( V_84 ) ; V_27 ++ )
if ( V_72 == V_84 [ V_27 ] )
break;
if ( V_27 == F_7 ( V_84 ) ) {
F_20 ( V_9 -> V_85 , L_6 ,
V_44 -> V_81 [ V_66 -> V_82 -> V_83 ] , F_19 ( V_65 ) ) ;
return - V_32 ;
}
V_70 |= V_27 ;
F_21 ( V_9 -> V_85 , L_7 ,
V_84 [ V_27 ] , V_44 -> V_81 [ V_66 -> V_82 -> V_83 ] ) ;
if ( V_63 -> V_86 == V_87 ) {
switch ( V_72 ) {
case 128 :
case 192 :
V_73 = V_88 ;
F_21 ( V_9 -> V_85 , L_8 ) ;
break;
default:
V_73 = 0 ;
F_21 ( V_9 -> V_85 , L_9 ) ;
break;
}
F_4 ( V_9 , V_89 , V_88 , V_73 ) ;
}
F_4 ( V_9 , V_90 + V_66 -> V_82 -> V_83 ,
V_91 | V_92 ,
V_70 ) ;
F_4 ( V_9 , V_89 + V_66 -> V_82 -> V_83 ,
V_93 , V_71 ) ;
return 0 ;
}
static int F_22 ( struct V_37 * V_38 ,
unsigned int V_94 )
{
struct V_8 * V_9 = V_38 -> V_9 ;
unsigned int V_95 ;
unsigned int V_96 ;
int V_97 ;
V_95 = F_16 ( V_9 , V_90 + V_38 -> V_82 -> V_83 ) ;
V_96 = F_16 ( V_9 , V_89 + V_38 -> V_82 -> V_83 ) ;
V_96 &= ~ ( V_98 | V_99 | V_100 ) ;
switch ( V_94 & V_101 ) {
case V_102 :
V_95 &= ~ V_103 ;
break;
case V_104 :
V_95 |= V_103 ;
break;
default:
return - V_32 ;
}
switch ( V_94 & V_105 ) {
case V_106 :
V_97 = 1 ;
V_96 |= V_107 ;
break;
case V_108 :
V_97 = 1 ;
V_96 |= V_109 ;
break;
case V_110 :
V_97 = 1 ;
V_96 |= V_111 ;
break;
case V_112 :
V_97 = 0 ;
V_96 |= V_113 ;
break;
case V_114 :
V_97 = 0 ;
V_96 |= V_113 ;
V_96 |= V_99 ;
break;
default:
return - V_32 ;
}
switch ( V_94 & V_115 ) {
case V_116 :
break;
case V_117 :
if ( ! V_97 )
return - V_32 ;
V_96 |= V_100 ;
V_96 |= V_99 ;
break;
case V_118 :
V_96 |= V_100 ;
break;
case V_119 :
if ( ! V_97 )
return - V_32 ;
V_96 |= V_99 ;
break;
default:
return - V_32 ;
}
F_15 ( V_9 , V_90 + V_38 -> V_82 -> V_83 , V_95 ) ;
F_15 ( V_9 , V_89 + V_38 -> V_82 -> V_83 , V_96 ) ;
return 0 ;
}
static int F_23 ( struct V_37 * V_38 ,
int V_120 , int div )
{
struct V_8 * V_9 = V_38 -> V_9 ;
unsigned int V_11 ;
switch ( V_120 ) {
case V_121 :
V_11 = F_16 ( V_9 , V_122 ) ;
V_11 &= ~ V_123 ;
switch ( div ) {
case V_124 :
break;
case V_125 :
V_11 |= V_126 ;
break;
case V_127 :
V_11 |= V_128 ;
break;
case V_129 :
V_11 |= V_130 ;
break;
default:
return - V_32 ;
}
F_15 ( V_9 , V_122 , V_11 ) ;
break;
case V_131 :
V_11 = F_16 ( V_9 , V_122 ) ;
V_11 &= ~ V_132 ;
switch ( div ) {
case V_133 :
break;
case V_125 :
V_11 |= V_134 ;
break;
case V_127 :
V_11 |= V_135 ;
break;
case V_129 :
V_11 |= V_136 ;
break;
default:
return - V_32 ;
}
F_15 ( V_9 , V_122 , V_11 ) ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_24 ( struct V_37 * V_66 , int V_137 ,
unsigned int V_138 , int V_139 )
{
struct V_8 * V_9 = V_66 -> V_9 ;
struct V_43 * V_44 = F_14 ( V_9 ) ;
int V_140 , V_141 , V_142 ;
switch ( V_66 -> V_82 -> V_83 ) {
case V_143 :
V_141 = 0x3 ;
V_142 = 0 ;
break;
case V_144 :
V_141 = 0xc ;
V_142 = 2 ;
break;
default:
F_25 ( L_10 ) ;
return - V_32 ;
}
switch ( V_137 ) {
case V_145 :
if ( V_66 -> V_82 -> V_83 != V_144 )
return - V_32 ;
V_140 = 0 << V_142 ;
break;
case V_125 :
V_140 = 1 << V_142 ;
break;
case V_127 :
V_140 = 2 << V_142 ;
break;
case V_124 :
V_140 = 3 << V_142 ;
break;
default:
F_20 ( V_9 -> V_85 , L_11 , V_137 ) ;
return - V_32 ;
}
V_44 -> V_81 [ V_66 -> V_82 -> V_83 ] = V_138 ;
return F_4 ( V_9 , V_146 , V_141 , V_140 ) ;
}
static int F_26 ( struct V_37 * V_38 , int V_147 )
{
struct V_8 * V_9 = V_38 -> V_9 ;
unsigned int V_11 ;
V_11 = F_16 ( V_9 , V_148 ) ;
if ( V_147 )
V_11 |= V_149 ;
else
V_11 &= ~ V_149 ;
F_15 ( V_9 , V_148 , V_11 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 ,
enum V_150 V_151 )
{
switch ( V_151 ) {
case V_152 :
case V_153 :
break;
case V_154 :
if ( V_9 -> V_16 . V_155 == V_156 ) {
F_4 ( V_9 , V_157 ,
V_158 |
V_159 , 0 ) ;
F_4 ( V_9 , V_160 ,
0x100 , 0 ) ;
}
break;
case V_156 :
F_4 ( V_9 , V_157 ,
V_158 , V_158 ) ;
break;
}
V_9 -> V_16 . V_155 = V_151 ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = F_14 ( V_9 ) ;
int V_14 = 0 , V_27 ;
V_14 = F_29 ( V_9 , 7 , 9 , V_44 -> V_161 ) ;
if ( V_14 < 0 ) {
F_20 ( V_9 -> V_85 , L_12 , V_14 ) ;
return V_14 ;
}
for ( V_27 = 0 ; V_27 < F_7 ( V_44 -> V_162 ) ; V_27 ++ )
V_44 -> V_162 [ V_27 ] . V_163 = V_164 [ V_27 ] ;
V_14 = F_30 ( V_9 -> V_85 , F_7 ( V_44 -> V_162 ) ,
V_44 -> V_162 ) ;
if ( V_14 != 0 ) {
F_20 ( V_9 -> V_85 , L_13 , V_14 ) ;
return V_14 ;
}
V_14 = F_31 ( F_7 ( V_44 -> V_162 ) ,
V_44 -> V_162 ) ;
if ( V_14 != 0 ) {
F_20 ( V_9 -> V_85 , L_14 , V_14 ) ;
goto V_165;
}
V_14 = F_15 ( V_9 , V_166 , 0 ) ;
if ( V_14 != 0 ) {
F_20 ( V_9 -> V_85 , L_15 , V_14 ) ;
goto V_167;
}
F_27 ( V_9 , V_154 ) ;
F_32 ( V_9 , V_168 ,
F_7 ( V_168 ) ) ;
F_5 ( V_9 ) ;
return 0 ;
V_167:
F_33 ( F_7 ( V_44 -> V_162 ) , V_44 -> V_162 ) ;
V_165:
F_34 ( F_7 ( V_44 -> V_162 ) , V_44 -> V_162 ) ;
return V_14 ;
}
static int F_35 ( struct V_8 * V_9 )
{
struct V_43 * V_44 = F_14 ( V_9 ) ;
F_27 ( V_9 , V_156 ) ;
F_33 ( F_7 ( V_44 -> V_162 ) , V_44 -> V_162 ) ;
F_34 ( F_7 ( V_44 -> V_162 ) , V_44 -> V_162 ) ;
return 0 ;
}
static int F_36 ( struct V_169 * V_170 ,
const struct V_171 * V_83 )
{
struct V_43 * V_44 ;
int V_14 ;
V_44 = F_37 ( sizeof( struct V_43 ) , V_172 ) ;
if ( V_44 == NULL )
return - V_173 ;
F_38 ( V_170 , V_44 ) ;
V_44 -> V_161 = V_174 ;
V_14 = F_39 ( & V_170 -> V_85 ,
& V_175 , V_176 , F_7 ( V_176 ) ) ;
if ( V_14 < 0 )
F_40 ( V_44 ) ;
return V_14 ;
}
static int F_41 ( struct V_169 * V_177 )
{
F_42 ( & V_177 -> V_85 ) ;
F_40 ( F_43 ( V_177 ) ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
int V_14 = 0 ;
#if F_45 ( V_178 ) || F_45 ( V_179 )
V_14 = F_46 ( & V_180 ) ;
if ( V_14 != 0 ) {
F_47 ( L_16 , V_14 ) ;
}
#endif
return V_14 ;
}
static void T_4 F_48 ( void )
{
#if F_45 ( V_178 ) || F_45 ( V_179 )
F_49 ( & V_180 ) ;
#endif
}
