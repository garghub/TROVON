static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ) ;
}
static int F_3 ( struct V_4 * V_5 ,
int V_6 , int V_7 , struct V_8 * V_9 )
{
T_1 V_10 ;
unsigned int V_11 , V_12 , V_13 , V_14 ;
F_4 ( V_5 , L_1 , V_6 , V_7 ) ;
V_14 = V_7 * 4 ;
if ( V_14 < 90000000 ) {
V_9 -> V_15 = 1 ;
V_14 *= 2 ;
} else {
V_9 -> V_15 = 0 ;
}
F_5 ( V_14 < 90000000 || V_14 > 100000000 ) ;
F_4 ( V_5 , L_2 , V_14 ) ;
V_12 = V_14 / V_6 ;
V_9 -> V_16 = V_12 ;
V_13 = V_14 % V_6 ;
F_4 ( V_5 , L_3 , V_13 ) ;
V_10 = V_17 * ( long long ) V_13 ;
F_6 ( V_10 , V_6 ) ;
V_11 = V_10 & 0xFFFFFFFF ;
if ( ( V_11 % 10 ) >= 5 )
V_11 += 5 ;
V_9 -> V_18 = V_11 / 10 ;
F_4 ( V_5 , L_4 , V_9 -> V_16 , V_9 -> V_18 , V_9 -> V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
int V_21 , V_22 , V_23 ;
int V_24 = 0 ;
int V_25 = 0 ;
int V_26 = - 1 ;
struct V_8 V_9 ;
if ( V_20 -> V_27 == 0 )
V_20 -> V_27 = 8000 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_28 ) ; V_21 ++ ) {
if ( V_20 -> V_27 != V_28 [ V_21 ] . V_27 )
continue;
V_26 = V_21 ;
if ( V_20 -> V_29 == V_28 [ V_21 ] . V_30 )
break;
}
if ( V_26 == - 1 ) {
F_10 ( V_2 -> V_5 , L_5 ,
V_20 -> V_27 ) ;
F_5 ( V_26 == - 1 ) ;
return - V_31 ;
}
if ( V_21 == F_9 ( V_28 ) ) {
V_24 |= V_32 ;
V_22 = F_3 ( V_2 -> V_5 , V_20 -> V_29 ,
V_28 [ V_26 ] . V_30 , & V_9 ) ;
if ( V_22 != 0 ) {
F_10 ( V_2 -> V_5 ,
L_6 ,
V_20 -> V_27 , V_20 -> V_29 ) ;
return - V_31 ;
}
F_11 ( V_2 , V_33 ,
V_34 | V_35 ,
( V_9 . V_16 << V_36 ) |
V_9 . V_18 >> 18 ) ;
F_11 ( V_2 , V_37 ,
V_38 ,
( V_9 . V_18 >> 9 ) & V_38 ) ;
F_11 ( V_2 , V_37 ,
V_39 ,
V_9 . V_18 & V_39 ) ;
if ( V_9 . V_18 )
F_11 ( V_2 , V_40 ,
V_41 , V_41 ) ;
else
F_11 ( V_2 , V_40 ,
V_41 , 0 ) ;
if ( V_9 . V_15 )
V_23 = V_42 | V_43 ;
else
V_23 = V_42 ;
F_11 ( V_2 , V_44 ,
V_42 | V_43 , V_23 ) ;
F_11 ( V_2 , V_44 ,
V_45 , V_45 ) ;
}
V_25 = V_28 [ V_26 ] . V_46 | ( V_28 [ V_26 ] . V_26 << V_47 ) ;
F_11 ( V_2 , V_48 ,
V_49 | V_50 , V_25 ) ;
F_11 ( V_2 , V_44 ,
V_32 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_51 * V_52 ,
struct V_53 * V_54 , int V_55 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
int V_22 = 0 ;
F_11 ( V_2 , V_56 ,
V_57 , 0 ) ;
F_11 ( V_2 , V_44 ,
V_42 | V_45 , 0 ) ;
switch ( V_55 ) {
case V_58 :
break;
case V_59 :
V_22 = F_7 ( V_2 ) ;
break;
default:
V_22 = - V_31 ;
break;
}
return V_22 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
int V_23 , V_21 , V_60 ;
if ( V_20 -> V_61 ) {
V_60 = 1 ;
for ( V_21 = 2 ; V_21 < F_9 ( V_62 ) ; V_21 ++ ) {
if ( abs ( V_62 [ V_21 ] - V_20 -> V_27 ) <
abs ( V_62 [ V_60 ] - V_20 -> V_27 ) )
V_60 = V_21 ;
}
V_23 = V_60 << V_63 ;
} else {
V_23 = 0 ;
}
F_4 ( V_2 -> V_5 , L_7 , V_23 ) ;
return F_11 ( V_2 , V_64 ,
V_65 , V_23 ) ;
}
static int F_14 ( struct V_53 * V_54 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_19 * V_20 = F_8 ( V_2 ) ;
V_67 -> V_68 . V_69 . V_70 [ 0 ] = V_20 -> V_61 ;
return 0 ;
}
static int F_16 ( struct V_53 * V_54 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_19 * V_20 = F_8 ( V_2 ) ;
int V_61 = V_67 -> V_68 . V_69 . V_70 [ 0 ] ;
if ( V_61 > 1 )
return - V_31 ;
V_20 -> V_61 = V_61 ;
return F_13 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_71 * V_72 = & V_2 -> V_72 ;
F_18 ( V_2 , V_73 ,
F_9 ( V_73 ) ) ;
F_19 ( V_72 , V_74 ,
F_9 ( V_74 ) ) ;
F_20 ( V_72 , V_75 ,
F_9 ( V_75 ) ) ;
return 0 ;
}
static int F_21 ( struct V_76 * V_77 ,
struct V_78 * V_79 ,
struct V_80 * V_81 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
struct V_19 * V_20 = F_8 ( V_2 ) ;
int V_22 ;
int V_82 ;
switch ( F_22 ( V_79 ) ) {
case V_83 :
V_82 = 0 ;
break;
case V_84 :
V_82 = 0x4 ;
break;
case V_85 :
V_82 = 0x8 ;
break;
case V_86 :
V_82 = 0xc ;
break;
default:
return - V_31 ;
}
F_11 ( V_2 , V_87 ,
V_88 , V_82 ) ;
V_20 -> V_27 = F_23 ( V_79 ) ;
F_13 ( V_2 ) ;
V_22 = F_24 ( V_2 , V_56 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_22 & V_57 ) {
F_11 ( V_2 , V_56 ,
V_57 , 0 ) ;
F_11 ( V_2 , V_44 ,
V_42 | V_45 , 0 ) ;
F_7 ( V_2 ) ;
}
return 0 ;
}
static int F_25 ( struct V_80 * V_81 , int V_89 ,
unsigned int V_90 , int V_91 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
struct V_19 * V_92 = F_8 ( V_2 ) ;
int div ;
switch ( V_89 ) {
case V_93 :
if ( V_90 > 15000000 ) {
V_92 -> V_29 = V_90 /= 2 ;
div = V_94 ;
} else {
V_92 -> V_29 = V_90 ;
div = 0 ;
}
F_11 ( V_2 , V_48 ,
V_94 , div ) ;
break;
default:
return - V_31 ;
}
F_4 ( V_81 -> V_5 , L_8 , V_89 , V_90 ) ;
return 0 ;
}
static int F_26 ( struct V_80 * V_81 , unsigned int V_95 )
{
struct V_1 * V_2 = V_81 -> V_2 ;
T_2 V_96 = 0 ;
switch ( V_95 & V_97 ) {
case V_98 :
break;
case V_99 :
V_96 |= V_100 ;
break;
default:
return - V_31 ;
}
switch ( V_95 & V_101 ) {
case V_102 :
V_96 |= V_103 ;
case V_104 :
V_96 |= 0x3 ;
break;
case V_105 :
V_96 |= 0x2 ;
break;
case V_106 :
break;
case V_107 :
V_96 |= 0x1 ;
break;
default:
return - V_31 ;
}
switch ( V_95 & V_101 ) {
case V_104 :
case V_102 :
switch ( V_95 & V_108 ) {
case V_109 :
break;
case V_110 :
V_96 |= V_111 ;
break;
default:
return - V_31 ;
}
break;
case V_105 :
case V_106 :
case V_107 :
switch ( V_95 & V_108 ) {
case V_109 :
break;
case V_112 :
V_96 |= V_111 | V_103 ;
break;
case V_110 :
V_96 |= V_111 ;
break;
case V_113 :
V_96 |= V_103 ;
break;
default:
return - V_31 ;
}
break;
default:
return - V_31 ;
}
F_11 ( V_2 , V_87 ,
V_100 | V_114 | V_111 |
V_103 , V_96 ) ;
return 0 ;
}
static int F_27 ( struct V_80 * V_115 , int V_116 )
{
struct V_1 * V_2 = V_115 -> V_2 ;
int V_23 ;
if ( V_116 )
V_23 = V_117 ;
else
V_23 = 0 ;
F_11 ( V_2 , V_64 , V_117 , V_23 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
T_2 * V_120 = V_2 -> V_120 ;
int V_22 , V_21 ;
switch ( V_119 ) {
case V_121 :
break;
case V_122 :
F_11 ( V_2 , V_56 ,
V_123 ,
0x1 << V_124 ) ;
F_11 ( V_2 , V_125 ,
V_126 ,
0x2 << V_127 ) ;
break;
case V_128 :
if ( V_2 -> V_72 . V_129 == V_130 ) {
V_22 = F_29 ( F_9 ( V_20 -> V_131 ) ,
V_20 -> V_131 ) ;
if ( V_22 != 0 ) {
F_10 ( V_2 -> V_5 ,
L_9 ,
V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < V_2 -> V_132 -> V_133 ; V_21 ++ ) {
if ( V_21 == V_3 )
continue;
if ( V_120 [ V_21 ] == V_134 [ V_21 ] )
continue;
F_2 ( V_2 , V_21 , V_120 [ V_21 ] ) ;
}
F_11 ( V_2 , V_56 ,
V_135 |
V_123 ,
V_135 |
0x3 << V_136 ) ;
F_30 ( 500 ) ;
F_11 ( V_2 ,
V_137 ,
V_138 , V_138 ) ;
}
F_11 ( V_2 , V_56 ,
V_123 ,
0x2 << V_124 ) ;
F_11 ( V_2 , V_125 ,
V_126 , 0 ) ;
break;
case V_130 :
F_11 ( V_2 ,
V_137 ,
V_138 , 0 ) ;
F_11 ( V_2 , V_56 ,
V_135 |
V_123 , 0 ) ;
F_31 ( F_9 ( V_20 -> V_131 ) ,
V_20 -> V_131 ) ;
break;
}
V_2 -> V_72 . V_129 = V_119 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_130 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_128 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
struct V_139 * V_140 = F_35 ( V_2 -> V_5 ) ;
T_2 * V_120 = V_2 -> V_120 ;
int V_22 , V_21 ;
V_22 = F_36 ( V_2 , 7 , 9 , V_20 -> V_141 ) ;
if ( V_22 != 0 ) {
F_10 ( V_2 -> V_5 , L_10 , V_22 ) ;
return V_22 ;
}
for ( V_21 = 0 ; V_21 < F_9 ( V_20 -> V_131 ) ; V_21 ++ )
V_20 -> V_131 [ V_21 ] . V_142 = V_143 [ V_21 ] ;
V_22 = F_37 ( V_2 -> V_5 , F_9 ( V_20 -> V_131 ) ,
V_20 -> V_131 ) ;
if ( V_22 != 0 ) {
F_10 ( V_2 -> V_5 , L_11 , V_22 ) ;
return V_22 ;
}
V_22 = F_29 ( F_9 ( V_20 -> V_131 ) ,
V_20 -> V_131 ) ;
if ( V_22 != 0 ) {
F_10 ( V_2 -> V_5 , L_9 , V_22 ) ;
goto V_144;
}
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 ) {
F_10 ( V_2 -> V_5 , L_12 , V_22 ) ;
goto V_145;
}
F_11 ( V_2 , V_146 ,
V_147 , V_147 ) ;
F_11 ( V_2 , V_148 ,
V_149 , V_149 ) ;
F_11 ( V_2 , V_150 ,
V_151 | V_152 ,
V_151 | V_152 ) ;
F_11 ( V_2 , V_153 ,
V_154 | V_155 ,
V_154 | V_155 ) ;
F_11 ( V_2 , V_156 ,
V_157 | V_158 ,
V_157 | V_158 ) ;
F_11 ( V_2 , V_159 ,
V_160 | V_161 ,
V_160 | V_161 ) ;
F_11 ( V_2 , V_162 ,
V_163 , V_163 ) ;
F_11 ( V_2 , V_164 , V_165 , V_165 ) ;
if ( V_140 ) {
if ( V_140 -> V_166 )
V_120 [ V_167 ]
|= V_168 ;
if ( V_140 -> V_169 )
V_120 [ V_170 ]
|= V_171 ;
}
F_28 ( V_2 , V_128 ) ;
F_31 ( F_9 ( V_20 -> V_131 ) , V_20 -> V_131 ) ;
F_17 ( V_2 ) ;
return 0 ;
V_145:
F_31 ( F_9 ( V_20 -> V_131 ) , V_20 -> V_131 ) ;
V_144:
F_38 ( F_9 ( V_20 -> V_131 ) , V_20 -> V_131 ) ;
return V_22 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = F_8 ( V_2 ) ;
F_28 ( V_2 , V_130 ) ;
F_38 ( F_9 ( V_20 -> V_131 ) , V_20 -> V_131 ) ;
return 0 ;
}
static T_3 int F_40 ( struct V_172 * V_173 ,
const struct V_174 * V_175 )
{
struct V_19 * V_20 ;
int V_22 ;
V_20 = F_41 ( sizeof( struct V_19 ) , V_176 ) ;
if ( V_20 == NULL )
return - V_177 ;
F_42 ( V_173 , V_20 ) ;
V_20 -> V_141 = V_178 ;
V_22 = F_43 ( & V_173 -> V_5 ,
& V_179 , & V_180 , 1 ) ;
if ( V_22 < 0 )
F_44 ( V_20 ) ;
return V_22 ;
}
static T_4 int F_45 ( struct V_172 * V_181 )
{
F_46 ( & V_181 -> V_5 ) ;
F_44 ( F_47 ( V_181 ) ) ;
return 0 ;
}
static int T_5 F_48 ( void )
{
int V_22 = 0 ;
#if F_49 ( V_182 ) || F_49 ( V_183 )
V_22 = F_50 ( & V_184 ) ;
if ( V_22 != 0 ) {
F_51 ( V_185 L_13 ,
V_22 ) ;
}
#endif
return V_22 ;
}
static void T_6 F_52 ( void )
{
#if F_49 ( V_182 ) || F_49 ( V_183 )
F_53 ( & V_184 ) ;
#endif
}
