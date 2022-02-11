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
static int F_5 ( struct V_15 * V_16 , unsigned int V_17 ,
unsigned int V_18 )
{
T_2 V_19 ;
unsigned int V_20 , V_21 , V_22 ;
int V_23 ;
F_6 ( L_1 , V_18 , V_17 ) ;
for ( V_23 = 0 ; V_23 < F_7 ( V_24 ) ; V_23 ++ ) {
if ( V_17 * V_24 [ V_23 ] . div >= 90000000 &&
V_17 * V_24 [ V_23 ] . div <= 100000000 ) {
V_16 -> V_25 = V_24 [ V_23 ] . V_25 ;
V_16 -> V_26 = V_24 [ V_23 ] . V_26 ;
V_17 *= V_24 [ V_23 ] . div ;
break;
}
}
if ( V_23 == F_7 ( V_24 ) ) {
F_8 ( V_27 L_2
L_3 , V_17 ) ;
return - V_28 ;
}
V_21 = V_17 / V_18 ;
if ( V_21 < 5 ) {
V_18 /= 2 ;
V_16 -> V_29 = 1 ;
V_21 = V_17 / V_18 ;
} else
V_16 -> V_29 = 0 ;
if ( ( V_21 < 5 ) || ( V_21 > 13 ) ) {
F_8 ( V_27
L_4 , V_21 ) ;
return - V_28 ;
}
V_16 -> V_30 = V_21 ;
V_22 = V_17 % V_18 ;
V_19 = V_31 * ( long long ) V_22 ;
F_9 ( V_19 , V_18 ) ;
V_20 = V_19 & 0xFFFFFFFF ;
V_16 -> V_32 = V_20 ;
F_6 ( L_5 ,
V_16 -> V_30 , V_16 -> V_32 , V_16 -> V_29 , V_16 -> V_25 ,
V_16 -> V_26 ) ;
return 0 ;
}
static int F_10 ( struct V_33 * V_34 , int V_35 ,
int V_18 , unsigned int V_36 , unsigned int V_37 )
{
int V_38 ;
struct V_8 * V_9 = V_34 -> V_9 ;
struct V_39 * V_40 = F_11 ( V_9 ) ;
struct V_41 * V_42 ;
struct V_15 V_16 ;
unsigned int V_11 ;
unsigned int V_43 ;
int V_14 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
switch ( V_35 ) {
case V_44 :
V_42 = & V_40 -> V_45 ;
V_38 = 0 ;
V_43 = V_46 ;
break;
case V_47 :
V_42 = & V_40 -> V_48 ;
V_38 = 4 ;
V_43 = V_49 ;
break;
default:
return - V_50 ;
}
if ( V_36 && V_37 ) {
V_14 = F_5 ( & V_16 , V_37 , V_36 ) ;
if ( V_14 != 0 )
return V_14 ;
}
V_42 -> V_51 = V_36 ;
V_42 -> V_52 = V_37 ;
F_4 ( V_9 , V_53 , V_43 , V_43 ) ;
if ( ! V_36 || ! V_37 )
return 0 ;
F_12 ( V_9 , V_54 + V_38 , V_16 . V_32 & 0x1ff ) ;
F_12 ( V_9 , V_55 + V_38 , ( V_16 . V_32 >> 9 ) & 0x1ff ) ;
F_12 ( V_9 , V_56 + V_38 ,
( V_16 . V_32 >> 18 & 0xf ) | ( V_16 . V_30 << 4 ) ) ;
V_11 = F_13 ( V_9 , V_57 + V_38 ) ;
V_11 &= ~ 0x1b ;
V_11 |= V_16 . V_29 | V_16 . V_26 << 1 |
V_16 . V_25 << 3 ;
F_12 ( V_9 , V_57 + V_38 , V_11 ) ;
F_4 ( V_9 , V_53 , V_43 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_33 * V_62 )
{
struct V_63 * V_64 = V_59 -> V_65 ;
struct V_8 * V_9 = V_64 -> V_9 ;
struct V_39 * V_40 = F_11 ( V_9 ) ;
T_1 V_66 = 0 ;
T_1 V_67 = 0 ;
int V_23 , V_68 , V_69 ;
switch ( F_15 ( V_61 ) ) {
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
return - V_28 ;
}
V_68 = V_40 -> V_77 [ V_62 -> V_78 -> V_79 ] / F_16 ( V_61 ) ;
for ( V_23 = 0 ; V_23 < F_7 ( V_80 ) ; V_23 ++ )
if ( V_68 == V_80 [ V_23 ] )
break;
if ( V_23 == F_7 ( V_80 ) ) {
F_17 ( V_9 -> V_81 , L_6 ,
V_40 -> V_77 [ V_62 -> V_78 -> V_79 ] , F_16 ( V_61 ) ) ;
return - V_28 ;
}
V_66 |= V_23 ;
F_18 ( V_9 -> V_81 , L_7 ,
V_80 [ V_23 ] , V_40 -> V_77 [ V_62 -> V_78 -> V_79 ] ) ;
if ( V_59 -> V_82 == V_83 ) {
switch ( V_68 ) {
case 128 :
case 192 :
V_69 = V_84 ;
F_18 ( V_9 -> V_81 , L_8 ) ;
break;
default:
V_69 = 0 ;
F_18 ( V_9 -> V_81 , L_9 ) ;
break;
}
F_4 ( V_9 , V_85 , V_84 , V_69 ) ;
}
F_4 ( V_9 , V_86 + V_62 -> V_78 -> V_79 ,
V_87 | V_88 ,
V_66 ) ;
F_4 ( V_9 , V_85 + V_62 -> V_78 -> V_79 ,
V_89 , V_67 ) ;
return 0 ;
}
static int F_19 ( struct V_33 * V_34 ,
unsigned int V_90 )
{
struct V_8 * V_9 = V_34 -> V_9 ;
unsigned int V_91 ;
unsigned int V_92 ;
int V_93 ;
V_91 = F_13 ( V_9 , V_86 + V_34 -> V_78 -> V_79 ) ;
V_92 = F_13 ( V_9 , V_85 + V_34 -> V_78 -> V_79 ) ;
V_92 &= ~ ( V_94 | V_95 | V_96 ) ;
switch ( V_90 & V_97 ) {
case V_98 :
V_91 &= ~ V_99 ;
break;
case V_100 :
V_91 |= V_99 ;
break;
default:
return - V_28 ;
}
switch ( V_90 & V_101 ) {
case V_102 :
V_93 = 1 ;
V_92 |= V_103 ;
break;
case V_104 :
V_93 = 1 ;
V_92 |= V_105 ;
break;
case V_106 :
V_93 = 1 ;
V_92 |= V_107 ;
break;
case V_108 :
V_93 = 0 ;
V_92 |= V_109 ;
break;
case V_110 :
V_93 = 0 ;
V_92 |= V_109 ;
V_92 |= V_95 ;
break;
default:
return - V_28 ;
}
switch ( V_90 & V_111 ) {
case V_112 :
break;
case V_113 :
if ( ! V_93 )
return - V_28 ;
V_92 |= V_96 ;
V_92 |= V_95 ;
break;
case V_114 :
V_92 |= V_96 ;
break;
case V_115 :
if ( ! V_93 )
return - V_28 ;
V_92 |= V_95 ;
break;
default:
return - V_28 ;
}
F_12 ( V_9 , V_86 + V_34 -> V_78 -> V_79 , V_91 ) ;
F_12 ( V_9 , V_85 + V_34 -> V_78 -> V_79 , V_92 ) ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
int V_116 , int div )
{
struct V_8 * V_9 = V_34 -> V_9 ;
unsigned int V_11 ;
switch ( V_116 ) {
case V_117 :
V_11 = F_13 ( V_9 , V_118 ) ;
V_11 &= ~ V_119 ;
switch ( div ) {
case V_120 :
break;
case V_121 :
V_11 |= V_122 ;
break;
case V_123 :
V_11 |= V_124 ;
break;
case V_125 :
V_11 |= V_126 ;
break;
default:
return - V_28 ;
}
F_12 ( V_9 , V_118 , V_11 ) ;
break;
case V_127 :
V_11 = F_13 ( V_9 , V_118 ) ;
V_11 &= ~ V_128 ;
switch ( div ) {
case V_129 :
break;
case V_121 :
V_11 |= V_130 ;
break;
case V_123 :
V_11 |= V_131 ;
break;
case V_125 :
V_11 |= V_132 ;
break;
default:
return - V_28 ;
}
F_12 ( V_9 , V_118 , V_11 ) ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_62 , int V_133 ,
unsigned int V_134 , int V_135 )
{
struct V_8 * V_9 = V_62 -> V_9 ;
struct V_39 * V_40 = F_11 ( V_9 ) ;
int V_14 , V_136 , V_137 , V_138 ;
switch ( V_62 -> V_78 -> V_79 ) {
case V_139 :
V_137 = 0x3 ;
V_138 = 0 ;
break;
case V_140 :
V_137 = 0xc ;
V_138 = 2 ;
break;
default:
F_22 ( L_10 ) ;
return - V_28 ;
}
switch ( V_133 ) {
case V_141 :
if ( V_62 -> V_78 -> V_79 != V_140 )
return - V_28 ;
V_136 = 0 << V_138 ;
break;
case V_121 :
V_136 = 1 << V_138 ;
break;
case V_123 :
V_136 = 2 << V_138 ;
break;
case V_120 :
V_136 = 3 << V_138 ;
break;
default:
F_17 ( V_9 -> V_81 , L_11 , V_133 ) ;
return - V_28 ;
}
V_40 -> V_77 [ V_62 -> V_78 -> V_79 ] = V_134 ;
V_14 = F_4 ( V_9 , V_142 , V_137 , V_136 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 , int V_143 )
{
struct V_8 * V_9 = V_34 -> V_9 ;
unsigned int V_11 ;
V_11 = F_13 ( V_9 , V_144 ) ;
if ( V_143 )
V_11 |= V_145 ;
else
V_11 &= ~ V_145 ;
F_12 ( V_9 , V_144 , V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_8 * V_9 ,
enum V_146 V_147 )
{
switch ( V_147 ) {
case V_148 :
case V_149 :
break;
case V_150 :
if ( V_9 -> V_151 . V_152 == V_153 ) {
F_4 ( V_9 , V_154 ,
V_155 |
V_156 , 0 ) ;
F_4 ( V_9 , V_157 ,
0x100 , 0 ) ;
}
break;
case V_153 :
F_4 ( V_9 , V_154 ,
V_155 , V_155 ) ;
break;
}
V_9 -> V_151 . V_152 = V_147 ;
return 0 ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_39 * V_40 = F_11 ( V_9 ) ;
int V_14 = 0 , V_23 ;
V_14 = F_26 ( V_9 , 7 , 9 , V_40 -> V_158 ) ;
if ( V_14 < 0 ) {
F_17 ( V_9 -> V_81 , L_12 , V_14 ) ;
return V_14 ;
}
for ( V_23 = 0 ; V_23 < F_7 ( V_40 -> V_159 ) ; V_23 ++ )
V_40 -> V_159 [ V_23 ] . V_160 = V_161 [ V_23 ] ;
V_14 = F_27 ( V_9 -> V_81 , F_7 ( V_40 -> V_159 ) ,
V_40 -> V_159 ) ;
if ( V_14 != 0 ) {
F_17 ( V_9 -> V_81 , L_13 , V_14 ) ;
return V_14 ;
}
V_14 = F_28 ( F_7 ( V_40 -> V_159 ) ,
V_40 -> V_159 ) ;
if ( V_14 != 0 ) {
F_17 ( V_9 -> V_81 , L_14 , V_14 ) ;
goto V_162;
}
V_14 = F_12 ( V_9 , V_163 , 0 ) ;
if ( V_14 != 0 ) {
F_17 ( V_9 -> V_81 , L_15 , V_14 ) ;
goto V_164;
}
F_24 ( V_9 , V_150 ) ;
return 0 ;
V_164:
F_29 ( F_7 ( V_40 -> V_159 ) , V_40 -> V_159 ) ;
V_162:
F_30 ( F_7 ( V_40 -> V_159 ) , V_40 -> V_159 ) ;
return V_14 ;
}
static int F_31 ( struct V_8 * V_9 )
{
struct V_39 * V_40 = F_11 ( V_9 ) ;
F_24 ( V_9 , V_153 ) ;
F_29 ( F_7 ( V_40 -> V_159 ) , V_40 -> V_159 ) ;
F_30 ( F_7 ( V_40 -> V_159 ) , V_40 -> V_159 ) ;
return 0 ;
}
static int F_32 ( struct V_165 * V_166 ,
const struct V_167 * V_79 )
{
struct V_39 * V_40 ;
int V_14 ;
V_40 = F_33 ( sizeof( struct V_39 ) , V_168 ) ;
if ( V_40 == NULL )
return - V_169 ;
F_34 ( V_166 , V_40 ) ;
V_40 -> V_158 = V_170 ;
V_14 = F_35 ( & V_166 -> V_81 ,
& V_171 , V_172 , F_7 ( V_172 ) ) ;
if ( V_14 < 0 )
F_36 ( V_40 ) ;
return V_14 ;
}
static int F_37 ( struct V_165 * V_173 )
{
F_38 ( & V_173 -> V_81 ) ;
F_36 ( F_39 ( V_173 ) ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_14 = 0 ;
#if F_41 ( V_174 ) || F_41 ( V_175 )
V_14 = F_42 ( & V_176 ) ;
if ( V_14 != 0 ) {
F_43 ( L_16 , V_14 ) ;
}
#endif
return V_14 ;
}
static void T_4 F_44 ( void )
{
#if F_41 ( V_174 ) || F_41 ( V_175 )
F_45 ( & V_176 ) ;
#endif
}
