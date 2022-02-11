static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_4 , 0 ) ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned int V_3 ;
V_3 = F_6 ( V_2 , V_9 ) ;
if ( V_3 & V_10 )
V_8 -> V_11 . integer . V_11 [ 0 ] = 1 ;
else
V_8 -> V_11 . integer . V_11 [ 0 ] = 0 ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
unsigned int V_12 = F_6 ( V_2 , V_13 ) ;
unsigned int V_14 = F_6 ( V_2 , V_9 ) ;
if ( V_8 -> V_11 . integer . V_11 [ 0 ] ==
( ( V_14 & V_10 ) != 0 ) )
return 0 ;
if ( V_12 & V_15 )
return - V_16 ;
if ( V_8 -> V_11 . integer . V_11 [ 0 ] ) {
V_14 &= ~ ( V_17 | V_18 ) ;
V_14 |= V_10 ;
} else {
V_14 |= V_17 | V_18 ;
V_14 &= ~ V_10 ;
}
F_3 ( V_2 , V_9 , V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 , unsigned int V_21 ,
unsigned int V_22 )
{
T_1 V_23 ;
unsigned int V_24 , V_25 , V_26 , V_27 ;
unsigned int div ;
int V_28 ;
div = 1 ;
while ( ( V_21 / div ) > 13500000 ) {
div *= 2 ;
if ( div > 8 ) {
F_9 ( L_1 ,
V_21 ) ;
return - V_16 ;
}
}
V_20 -> V_29 = div / 2 ;
F_10 ( L_2 , V_21 , V_22 ) ;
V_21 /= div ;
div = 0 ;
V_27 = V_22 * 2 ;
while ( V_27 < 90000000 ) {
div ++ ;
V_27 *= 2 ;
if ( div > 7 ) {
F_9 ( L_3 ,
V_22 ) ;
return - V_16 ;
}
}
V_20 -> V_30 = div ;
F_10 ( L_4 , V_27 ) ;
for ( V_28 = 0 ; V_28 < F_11 ( V_31 ) ; V_28 ++ ) {
if ( V_31 [ V_28 ] . V_32 <= V_21 && V_21 <= V_31 [ V_28 ] . V_33 ) {
V_20 -> V_34 = V_31 [ V_28 ] . V_34 ;
V_27 /= V_31 [ V_28 ] . V_35 ;
break;
}
}
if ( V_28 == F_11 ( V_31 ) ) {
F_9 ( L_5 , V_21 ) ;
return - V_16 ;
}
V_25 = V_27 / V_21 ;
V_20 -> V_36 = V_25 ;
V_26 = V_27 % V_21 ;
F_10 ( L_6 , V_26 ) ;
V_23 = V_37 * ( long long ) V_26 ;
F_12 ( V_23 , V_21 ) ;
V_24 = V_23 & 0xFFFFFFFF ;
if ( ( V_24 % 10 ) >= 5 )
V_24 += 5 ;
V_20 -> V_38 = V_24 / 10 ;
F_10 ( L_7 ,
V_20 -> V_36 , V_20 -> V_38 ,
V_20 -> V_34 , V_20 -> V_30 ,
V_20 -> V_29 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_39 ,
unsigned int V_21 , unsigned int V_22 )
{
struct V_40 * V_41 = F_14 ( V_2 ) ;
T_2 V_42 , V_43 , V_44 ;
struct V_19 V_20 ;
int V_45 ;
int V_46 ;
if ( V_21 == V_41 -> V_47 && V_22 == V_41 -> V_48 )
return 0 ;
if ( V_22 == 0 ) {
F_15 ( V_2 -> V_49 , L_8 ) ;
V_41 -> V_47 = 0 ;
V_41 -> V_48 = 0 ;
return 0 ;
}
V_45 = F_8 ( & V_20 , V_21 , V_22 ) ;
if ( V_45 != 0 )
return V_45 ;
V_44 = F_6 ( V_2 , V_50 ) ;
V_44 &= ~ V_51 ;
switch ( V_39 ) {
case V_52 :
V_44 |= 0x1 ;
break;
default:
F_16 ( V_2 -> V_49 , L_9 , V_39 ) ;
return - V_16 ;
}
V_46 = F_6 ( V_2 , V_53 ) ;
if ( V_46 & V_54 )
F_3 ( V_2 , V_53 ,
V_46 & ~ V_54 ) ;
V_42 = F_6 ( V_2 , V_55 ) ;
V_42 &= ~ V_56 ;
F_3 ( V_2 , V_55 , V_42 ) ;
if ( V_20 . V_38 )
V_42 |= V_57 ;
else
V_42 &= ~ V_57 ;
F_3 ( V_2 , V_55 , V_42 ) ;
F_3 ( V_2 , V_58 ,
( V_20 . V_30 << V_59 ) |
( V_20 . V_34 << V_60 ) ) ;
F_3 ( V_2 , V_61 , V_20 . V_38 ) ;
V_43 = F_6 ( V_2 , V_62 ) ;
V_43 &= ~ V_63 ;
V_43 |= V_20 . V_36 << V_64 ;
F_3 ( V_2 , V_62 , V_43 ) ;
V_44 &= ~ V_65 ;
V_44 |= V_20 . V_29 << V_66 ;
F_3 ( V_2 , V_50 , V_44 ) ;
F_17 ( V_2 , V_62 ,
V_67 , 0 ) ;
F_3 ( V_2 , V_55 , V_42 | V_56 ) ;
if ( V_46 & V_54 )
F_3 ( V_2 , V_53 , V_46 ) ;
F_15 ( V_2 -> V_49 , L_10 , V_21 , V_22 ) ;
V_41 -> V_47 = V_21 ;
V_41 -> V_48 = V_22 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_14 ( V_2 ) ;
int V_68 , V_28 , V_27 ;
unsigned int V_3 ;
int V_45 = 0 ;
int V_69 = 0 ;
int V_70 = 0 ;
switch ( V_41 -> V_71 ) {
case V_72 :
if ( V_41 -> V_73 > 12225000 ) {
V_69 = 1 ;
V_41 -> V_74 = V_41 -> V_73 / 2 ;
} else {
V_41 -> V_74 = V_41 -> V_73 ;
}
F_13 ( V_2 , V_52 , 0 , 0 ) ;
break;
case V_52 :
if ( V_41 -> V_75 && V_41 -> V_76 ) {
for ( V_28 = 0 ; V_28 < F_11 ( V_77 ) ; V_28 ++ ) {
V_27 = V_41 -> V_78 * V_77 [ V_28 ] . V_35 ;
V_68 = V_27 ;
if ( V_27 >= V_41 -> V_76 &&
V_27 > 3000000 )
break;
}
if ( V_28 == F_11 ( V_77 ) )
return - V_16 ;
} else if ( V_41 -> V_78 ) {
for ( V_28 = 0 ; V_28 < F_11 ( V_77 ) ; V_28 ++ ) {
V_68 = V_77 [ V_28 ] . V_35
* V_41 -> V_78 ;
if ( V_68 > 3000000 )
break;
}
if ( V_28 == F_11 ( V_77 ) )
return - V_16 ;
} else {
V_68 = 12288000 ;
}
V_45 = F_13 ( V_2 , V_52 ,
V_41 -> V_73 , V_68 ) ;
if ( V_45 == 0 ) {
V_41 -> V_74 = V_68 ;
V_70 = 1 ;
} else {
V_41 -> V_74 = V_41 -> V_73 ;
}
break;
default:
return - V_16 ;
}
V_3 = F_6 ( V_2 , V_79 ) ;
if ( V_69 )
V_3 |= V_80 ;
else
V_3 &= ~ V_80 ;
F_3 ( V_2 , V_79 , V_3 ) ;
V_3 = F_6 ( V_2 , V_53 ) ;
if ( V_70 )
V_3 |= V_81 ;
else
V_3 &= ~ V_81 ;
F_3 ( V_2 , V_53 , V_3 ) ;
F_15 ( V_2 -> V_49 , L_11 , V_41 -> V_74 ) ;
return V_45 ;
}
static int F_19 ( struct V_82 * V_83 ,
struct V_5 * V_6 , int V_84 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_40 * V_41 = F_14 ( V_2 ) ;
switch ( V_41 -> V_71 ) {
case V_72 :
F_15 ( V_2 -> V_49 , L_12 , V_41 -> V_73 ) ;
break;
case V_52 :
F_15 ( V_2 -> V_49 , L_13 ,
V_41 -> V_73 ) ;
break;
default:
F_16 ( V_2 -> V_49 , L_14 ) ;
return - V_16 ;
}
switch ( V_84 ) {
case V_85 :
F_18 ( V_2 ) ;
break;
case V_86 :
F_13 ( V_2 , 0 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_87 V_88 )
{
T_2 V_3 ;
switch ( V_88 ) {
case V_89 :
break;
case V_90 :
V_3 = F_6 ( V_2 , V_91 ) ;
V_3 &= ~ V_92 ;
V_3 |= 0x2 ;
F_3 ( V_2 , V_91 , V_3 ) ;
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 &= ~ V_94 ;
F_3 ( V_2 , V_93 , V_3 ) ;
break;
case V_95 :
if ( V_2 -> V_96 . V_97 == V_98 ) {
V_3 = F_6 ( V_2 , V_99 ) ;
V_3 &= ~ V_100 ;
F_3 ( V_2 , V_99 , V_3 ) ;
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 |= V_101 | V_102 ;
F_3 ( V_2 , V_93 , V_3 ) ;
V_3 = F_6 ( V_2 , V_91 ) ;
V_3 |= V_103 | 0x6 ;
F_3 ( V_2 , V_91 , V_3 ) ;
F_21 ( 100 ) ;
V_3 |= V_102 ;
V_3 &= ~ V_103 ;
F_3 ( V_2 , V_91 , V_3 ) ;
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 &= ~ V_101 ;
F_3 ( V_2 , V_93 , V_3 ) ;
}
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 &= ~ V_92 ;
V_3 |= 0x40 ;
F_3 ( V_2 , V_91 , V_3 ) ;
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 |= V_94 ;
F_3 ( V_2 , V_93 , V_3 ) ;
break;
case V_98 :
V_3 = F_6 ( V_2 , V_93 ) ;
V_3 |= V_101 ;
F_3 ( V_2 , V_93 , V_3 ) ;
V_3 = F_6 ( V_2 , V_91 ) ;
V_3 &= ~ ( V_92 | V_102 ) ;
V_3 |= V_103 ;
F_3 ( V_2 , V_91 , V_3 ) ;
V_3 = F_6 ( V_2 , V_99 ) ;
V_3 |= V_100 ;
F_3 ( V_2 , V_99 , V_3 ) ;
break;
}
V_2 -> V_96 . V_97 = V_88 ;
return 0 ;
}
static int F_22 ( struct V_104 * V_105 ,
unsigned int V_106 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_40 * V_41 = F_14 ( V_2 ) ;
unsigned int V_107 = F_6 ( V_2 , V_108 ) ;
V_107 &= ~ ( V_109 | V_110 |
V_111 | V_112 | V_113 ) ;
switch ( V_106 & V_114 ) {
case V_115 :
V_41 -> V_75 = 0 ;
break;
case V_116 :
V_107 |= V_112 ;
V_41 -> V_75 = 1 ;
break;
case V_117 :
V_107 |= V_111 ;
V_41 -> V_75 = 1 ;
break;
case V_118 :
V_107 |= V_112 | V_111 ;
V_41 -> V_75 = 1 ;
break;
default:
return - V_16 ;
}
switch ( V_106 & V_119 ) {
case V_120 :
V_107 |= V_110 ;
case V_121 :
V_107 |= 0x3 ;
break;
case V_122 :
V_107 |= 0x2 ;
break;
case V_123 :
break;
case V_124 :
V_107 |= 0x1 ;
break;
default:
return - V_16 ;
}
switch ( V_106 & V_119 ) {
case V_121 :
case V_120 :
switch ( V_106 & V_125 ) {
case V_126 :
break;
case V_127 :
V_107 |= V_109 ;
break;
default:
return - V_16 ;
}
break;
case V_122 :
case V_123 :
case V_124 :
switch ( V_106 & V_125 ) {
case V_126 :
break;
case V_128 :
V_107 |= V_109 | V_110 ;
break;
case V_127 :
V_107 |= V_109 ;
break;
case V_129 :
V_107 |= V_110 ;
break;
default:
return - V_16 ;
}
break;
default:
return - V_16 ;
}
F_3 ( V_2 , V_108 , V_107 ) ;
return 0 ;
}
static int F_23 ( struct V_130 * V_131 ,
struct V_132 * V_133 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_40 * V_41 = F_14 ( V_2 ) ;
int V_45 , V_28 , V_134 , V_135 , V_136 ;
unsigned int V_137 , V_138 , V_107 , V_139 , V_140 ;
V_137 = F_6 ( V_2 , V_141 ) ;
V_137 &= ~ ( V_142 | V_143 ) ;
V_138 = F_6 ( V_2 , V_144 ) ;
V_107 = F_6 ( V_2 , V_108 ) ;
V_107 &= ~ V_145 ;
V_139 = F_6 ( V_2 , V_146 ) ;
V_139 &= ~ V_147 ;
V_140 = F_6 ( V_2 , V_148 ) ;
V_140 &= ~ V_149 ;
V_41 -> V_78 = F_24 ( V_133 ) ;
if ( V_41 -> V_150 ) {
int V_151 = ( ( V_138 & V_152 ) >>
V_153 ) + 1 ;
V_41 -> V_76 = V_41 -> V_78 * V_41 -> V_150 * V_151 ;
} else {
V_41 -> V_76 = 2 * V_41 -> V_78 ;
switch ( F_25 ( V_133 ) ) {
case V_154 :
V_41 -> V_76 *= 16 ;
break;
case V_155 :
V_41 -> V_76 *= 20 ;
V_107 |= 0x4 ;
break;
case V_156 :
V_41 -> V_76 *= 24 ;
V_107 |= 0x8 ;
break;
case V_157 :
V_41 -> V_76 *= 32 ;
V_107 |= 0xc ;
break;
default:
return - V_16 ;
}
}
F_15 ( V_2 -> V_49 , L_15 , V_41 -> V_76 ) ;
V_45 = F_18 ( V_2 ) ;
if ( V_45 != 0 )
return V_45 ;
V_134 = 0 ;
V_135 = abs ( ( V_41 -> V_74 / V_77 [ 0 ] . V_35 )
- V_41 -> V_78 ) ;
for ( V_28 = 1 ; V_28 < F_11 ( V_77 ) ; V_28 ++ ) {
V_136 = abs ( ( V_41 -> V_74 /
V_77 [ V_28 ] . V_35 ) - V_41 -> V_78 ) ;
if ( V_136 < V_135 ) {
V_134 = V_28 ;
V_135 = V_136 ;
}
}
F_15 ( V_2 -> V_49 , L_16 ,
V_77 [ V_134 ] . V_35 ) ;
V_137 |= ( V_77 [ V_134 ] . V_158
<< V_159 ) ;
V_134 = 0 ;
V_135 = abs ( V_41 -> V_78 - V_160 [ 0 ] . V_161 ) ;
for ( V_28 = 1 ; V_28 < F_11 ( V_160 ) ; V_28 ++ ) {
V_136 = abs ( V_41 -> V_78 - V_160 [ V_28 ] . V_161 ) ;
if ( V_136 < V_135 ) {
V_134 = V_28 ;
V_135 = V_136 ;
}
}
F_15 ( V_2 -> V_49 , L_17 ,
V_160 [ V_134 ] . V_161 ) ;
V_137 |= ( V_160 [ V_134 ] . V_162
<< V_163 ) ;
V_134 = 0 ;
V_135 = V_164 ;
for ( V_28 = 0 ; V_28 < F_11 ( V_165 ) ; V_28 ++ ) {
V_136 = ( ( V_41 -> V_74 * 10 ) / V_165 [ V_28 ] . div )
- V_41 -> V_76 ;
if ( V_136 < 0 )
break;
if ( V_136 < V_135 ) {
V_134 = V_28 ;
V_135 = V_136 ;
}
}
V_41 -> V_76 = ( V_41 -> V_74 * 10 ) / V_165 [ V_134 ] . div ;
F_15 ( V_2 -> V_49 , L_18 ,
V_165 [ V_134 ] . div , V_41 -> V_76 ) ;
V_139 |= V_165 [ V_134 ] . V_166 ;
F_15 ( V_2 -> V_49 , L_19 , V_41 -> V_76 / V_41 -> V_78 ) ;
V_140 |= V_41 -> V_76 / V_41 -> V_78 ;
if ( V_41 -> V_167 . V_168 ) {
struct V_169 * V_167 = & V_41 -> V_167 ;
struct V_170 * V_171 ;
int V_172 ;
V_134 = 0 ;
V_135 = abs ( V_167 -> V_173 [ 0 ] . V_161 - V_41 -> V_78 ) ;
for ( V_28 = 0 ; V_28 < V_167 -> V_168 ; V_28 ++ ) {
V_136 = abs ( V_167 -> V_173 [ V_28 ] . V_161 -
V_41 -> V_78 ) ;
if ( V_136 < V_135 ) {
V_135 = V_136 ;
V_134 = V_28 ;
}
}
V_171 = & V_167 -> V_173 [ V_134 ] ;
F_15 ( V_2 -> V_49 , L_20 ,
V_171 -> V_174 , V_171 -> V_161 ) ;
V_172 = F_6 ( V_2 , V_175 ) & V_176 ;
if ( V_172 & V_176 )
F_3 ( V_2 , V_175 , 0 ) ;
for ( V_28 = 1 ; V_28 < F_11 ( V_171 -> V_177 ) ; V_28 ++ )
F_3 ( V_2 , V_175 + V_28 , V_171 -> V_177 [ V_28 ] ) ;
V_172 |= ( V_171 -> V_177 [ 0 ] & ~ V_176 ) ;
F_3 ( V_2 , V_175 , V_172 ) ;
}
F_3 ( V_2 , V_141 , V_137 ) ;
F_3 ( V_2 , V_108 , V_107 ) ;
F_3 ( V_2 , V_146 , V_139 ) ;
F_3 ( V_2 , V_148 , V_140 ) ;
return 0 ;
}
static int F_26 ( struct V_104 * V_178 , int V_179 )
{
struct V_1 * V_2 = V_178 -> V_2 ;
unsigned int V_3 ;
V_3 = F_6 ( V_2 , V_180 ) ;
if ( V_179 )
V_3 |= V_181 ;
else
V_3 &= ~ V_181 ;
F_3 ( V_2 , V_180 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
int V_182 , unsigned int V_183 , int V_184 )
{
struct V_40 * V_41 = F_14 ( V_2 ) ;
switch ( V_182 ) {
case V_72 :
case V_52 :
V_41 -> V_71 = V_182 ;
V_41 -> V_73 = V_183 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_28 ( struct V_104 * V_105 ,
unsigned int V_185 , unsigned int V_186 , int V_151 , int V_187 )
{
struct V_1 * V_2 = V_105 -> V_2 ;
struct V_40 * V_41 = F_14 ( V_2 ) ;
unsigned int V_138 = F_6 ( V_2 , V_144 ) ;
V_138 &= ~ ( V_188 | V_152 ) ;
if ( V_151 < 0 || V_151 > 4 )
return - V_16 ;
V_41 -> V_150 = V_187 ;
if ( V_151 == 0 )
V_151 = 1 ;
V_138 |= ( V_151 - 1 ) << V_153 ;
switch ( V_186 ) {
case 1 :
break;
case 2 :
V_138 |= 0x10 ;
break;
case 4 :
V_138 |= 0x20 ;
break;
case 8 :
V_138 |= 0x30 ;
break;
default:
return - V_16 ;
}
F_3 ( V_2 , V_144 , V_138 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_14 ( V_2 ) ;
int V_45 ;
T_2 V_3 ;
V_2 -> V_189 = V_41 -> V_189 ;
V_45 = F_30 ( V_2 , 8 , 16 , V_41 -> V_190 ) ;
if ( V_45 != 0 ) {
F_16 ( V_2 -> V_49 , L_21 , V_45 ) ;
return V_45 ;
}
V_3 = F_6 ( V_2 , V_4 ) ;
if ( V_3 != 0x9081 ) {
F_16 ( V_2 -> V_49 , L_22 , V_3 ) ;
V_45 = - V_16 ;
return V_45 ;
}
V_45 = F_2 ( V_2 ) ;
if ( V_45 < 0 ) {
F_16 ( V_2 -> V_49 , L_23 ) ;
return V_45 ;
}
V_3 = 0 ;
if ( V_41 -> V_167 . V_191 )
V_3 |= V_192 ;
if ( ! V_41 -> V_167 . V_193 )
V_3 |= V_194 ;
F_17 ( V_2 , V_195 ,
V_192 | V_194 , V_3 ) ;
F_20 ( V_2 , V_95 ) ;
V_3 = F_6 ( V_2 , V_196 ) ;
F_3 ( V_2 , V_196 , V_3 | V_197 ) ;
V_3 = F_6 ( V_2 , V_198 ) ;
F_3 ( V_2 , V_198 ,
V_3 | V_199 ) ;
F_31 ( V_2 , V_200 ,
F_11 ( V_200 ) ) ;
if ( ! V_41 -> V_167 . V_168 ) {
F_15 ( V_2 -> V_49 ,
L_24 ) ;
F_31 ( V_2 , V_201 ,
F_11 ( V_201 ) ) ;
}
return V_45 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_98 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_202 )
{
F_20 ( V_2 , V_98 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 * V_203 = V_2 -> V_203 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_204 -> V_205 ; V_28 ++ ) {
if ( V_28 == V_4 )
continue;
F_3 ( V_2 , V_28 , V_203 [ V_28 ] ) ;
}
F_20 ( V_2 , V_95 ) ;
return 0 ;
}
static T_4 int F_35 ( struct V_206 * V_207 ,
const struct V_208 * V_209 )
{
struct V_40 * V_41 ;
int V_45 ;
V_41 = F_36 ( sizeof( struct V_40 ) , V_210 ) ;
if ( V_41 == NULL )
return - V_211 ;
F_37 ( V_207 , V_41 ) ;
V_41 -> V_190 = V_212 ;
V_41 -> V_189 = V_207 ;
if ( F_38 ( & V_207 -> V_49 ) )
memcpy ( & V_41 -> V_167 , F_38 ( & V_207 -> V_49 ) ,
sizeof( V_41 -> V_167 ) ) ;
V_45 = F_39 ( & V_207 -> V_49 ,
& V_213 , & V_214 , 1 ) ;
if ( V_45 < 0 )
F_40 ( V_41 ) ;
return V_45 ;
}
static T_5 int F_41 ( struct V_206 * V_215 )
{
F_42 ( & V_215 -> V_49 ) ;
F_40 ( F_43 ( V_215 ) ) ;
return 0 ;
}
static int T_6 F_44 ( void )
{
int V_45 = 0 ;
#if F_45 ( V_216 ) || F_45 ( V_217 )
V_45 = F_46 ( & V_218 ) ;
if ( V_45 != 0 ) {
F_47 ( V_219 L_25 ,
V_45 ) ;
}
#endif
return V_45 ;
}
static void T_7 F_48 ( void )
{
#if F_45 ( V_216 ) || F_45 ( V_217 )
F_49 ( & V_218 ) ;
#endif
}
