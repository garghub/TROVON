static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_4 , 0 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_3 ;
V_3 = F_6 ( V_2 , V_10 ) ;
if ( V_3 & V_11 )
V_9 -> V_12 . integer . V_12 [ 0 ] = 1 ;
else
V_9 -> V_12 . integer . V_12 [ 0 ] = 0 ;
return 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_13 = F_6 ( V_2 , V_14 ) ;
unsigned int V_15 = F_6 ( V_2 , V_10 ) ;
if ( V_9 -> V_12 . integer . V_12 [ 0 ] ==
( ( V_15 & V_11 ) != 0 ) )
return 0 ;
if ( V_13 & V_16 )
return - V_17 ;
if ( V_9 -> V_12 . integer . V_12 [ 0 ] ) {
V_15 &= ~ ( V_18 | V_19 ) ;
V_15 |= V_11 ;
} else {
V_15 |= V_18 | V_19 ;
V_15 &= ~ V_11 ;
}
F_3 ( V_2 , V_10 , V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 , unsigned int V_22 ,
unsigned int V_23 )
{
T_1 V_24 ;
unsigned int V_25 , V_26 , V_27 , V_28 ;
unsigned int div ;
int V_29 ;
div = 1 ;
while ( ( V_22 / div ) > 13500000 ) {
div *= 2 ;
if ( div > 8 ) {
F_9 ( L_1 ,
V_22 ) ;
return - V_17 ;
}
}
V_21 -> V_30 = div / 2 ;
F_10 ( L_2 , V_22 , V_23 ) ;
V_22 /= div ;
div = 0 ;
V_28 = V_23 * 2 ;
while ( V_28 < 90000000 ) {
div ++ ;
V_28 *= 2 ;
if ( div > 7 ) {
F_9 ( L_3 ,
V_23 ) ;
return - V_17 ;
}
}
V_21 -> V_31 = div ;
F_10 ( L_4 , V_28 ) ;
for ( V_29 = 0 ; V_29 < F_11 ( V_32 ) ; V_29 ++ ) {
if ( V_32 [ V_29 ] . V_33 <= V_22 && V_22 <= V_32 [ V_29 ] . V_34 ) {
V_21 -> V_35 = V_32 [ V_29 ] . V_35 ;
V_28 /= V_32 [ V_29 ] . V_36 ;
break;
}
}
if ( V_29 == F_11 ( V_32 ) ) {
F_9 ( L_5 , V_22 ) ;
return - V_17 ;
}
V_26 = V_28 / V_22 ;
V_21 -> V_37 = V_26 ;
V_27 = V_28 % V_22 ;
F_10 ( L_6 , V_27 ) ;
V_24 = V_38 * ( long long ) V_27 ;
F_12 ( V_24 , V_22 ) ;
V_25 = V_24 & 0xFFFFFFFF ;
if ( ( V_25 % 10 ) >= 5 )
V_25 += 5 ;
V_21 -> V_39 = V_25 / 10 ;
F_10 ( L_7 ,
V_21 -> V_37 , V_21 -> V_39 ,
V_21 -> V_35 , V_21 -> V_31 ,
V_21 -> V_30 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_40 ,
unsigned int V_22 , unsigned int V_23 )
{
struct V_41 * V_42 = F_14 ( V_2 ) ;
T_2 V_43 , V_44 , V_45 ;
struct V_20 V_21 ;
int V_46 ;
int V_47 ;
if ( V_22 == V_42 -> V_48 && V_23 == V_42 -> V_49 )
return 0 ;
if ( V_23 == 0 ) {
F_15 ( V_2 -> V_50 , L_8 ) ;
V_42 -> V_48 = 0 ;
V_42 -> V_49 = 0 ;
return 0 ;
}
V_46 = F_8 ( & V_21 , V_22 , V_23 ) ;
if ( V_46 != 0 )
return V_46 ;
V_45 = F_6 ( V_2 , V_51 ) ;
V_45 &= ~ V_52 ;
switch ( V_40 ) {
case V_53 :
V_45 |= 0x1 ;
break;
default:
F_16 ( V_2 -> V_50 , L_9 , V_40 ) ;
return - V_17 ;
}
V_47 = F_6 ( V_2 , V_54 ) ;
if ( V_47 & V_55 )
F_3 ( V_2 , V_54 ,
V_47 & ~ V_55 ) ;
V_43 = F_6 ( V_2 , V_56 ) ;
V_43 &= ~ V_57 ;
F_3 ( V_2 , V_56 , V_43 ) ;
if ( V_21 . V_39 )
V_43 |= V_58 ;
else
V_43 &= ~ V_58 ;
F_3 ( V_2 , V_56 , V_43 ) ;
F_3 ( V_2 , V_59 ,
( V_21 . V_31 << V_60 ) |
( V_21 . V_35 << V_61 ) ) ;
F_3 ( V_2 , V_62 , V_21 . V_39 ) ;
V_44 = F_6 ( V_2 , V_63 ) ;
V_44 &= ~ V_64 ;
V_44 |= V_21 . V_37 << V_65 ;
F_3 ( V_2 , V_63 , V_44 ) ;
V_45 &= ~ V_66 ;
V_45 |= V_21 . V_30 << V_67 ;
F_3 ( V_2 , V_51 , V_45 ) ;
F_17 ( V_2 , V_63 ,
V_68 , 0 ) ;
F_3 ( V_2 , V_56 , V_43 | V_57 ) ;
if ( V_47 & V_55 )
F_3 ( V_2 , V_54 , V_47 ) ;
F_15 ( V_2 -> V_50 , L_10 , V_22 , V_23 ) ;
V_42 -> V_48 = V_22 ;
V_42 -> V_49 = V_23 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_14 ( V_2 ) ;
int V_69 , V_29 , V_28 ;
unsigned int V_3 ;
int V_46 = 0 ;
int V_70 = 0 ;
int V_71 = 0 ;
switch ( V_42 -> V_72 ) {
case V_73 :
if ( V_42 -> V_74 > 12225000 ) {
V_70 = 1 ;
V_42 -> V_75 = V_42 -> V_74 / 2 ;
} else {
V_42 -> V_75 = V_42 -> V_74 ;
}
F_13 ( V_2 , V_53 , 0 , 0 ) ;
break;
case V_53 :
if ( V_42 -> V_76 && V_42 -> V_77 ) {
for ( V_29 = 0 ; V_29 < F_11 ( V_78 ) ; V_29 ++ ) {
V_28 = V_42 -> V_79 * V_78 [ V_29 ] . V_36 ;
V_69 = V_28 ;
if ( V_28 >= V_42 -> V_77 &&
V_28 > 3000000 )
break;
}
if ( V_29 == F_11 ( V_78 ) )
return - V_17 ;
} else if ( V_42 -> V_79 ) {
for ( V_29 = 0 ; V_29 < F_11 ( V_78 ) ; V_29 ++ ) {
V_69 = V_78 [ V_29 ] . V_36
* V_42 -> V_79 ;
if ( V_69 > 3000000 )
break;
}
if ( V_29 == F_11 ( V_78 ) )
return - V_17 ;
} else {
V_69 = 12288000 ;
}
V_46 = F_13 ( V_2 , V_53 ,
V_42 -> V_74 , V_69 ) ;
if ( V_46 == 0 ) {
V_42 -> V_75 = V_69 ;
V_71 = 1 ;
} else {
V_42 -> V_75 = V_42 -> V_74 ;
}
break;
default:
return - V_17 ;
}
V_3 = F_6 ( V_2 , V_80 ) ;
if ( V_70 )
V_3 |= V_81 ;
else
V_3 &= ~ V_81 ;
F_3 ( V_2 , V_80 , V_3 ) ;
V_3 = F_6 ( V_2 , V_54 ) ;
if ( V_71 )
V_3 |= V_82 ;
else
V_3 &= ~ V_82 ;
F_3 ( V_2 , V_54 , V_3 ) ;
F_15 ( V_2 -> V_50 , L_11 , V_42 -> V_75 ) ;
return V_46 ;
}
static int F_19 ( struct V_83 * V_84 ,
struct V_6 * V_7 , int V_85 )
{
struct V_1 * V_2 = V_84 -> V_2 ;
struct V_41 * V_42 = F_14 ( V_2 ) ;
switch ( V_42 -> V_72 ) {
case V_73 :
F_15 ( V_2 -> V_50 , L_12 , V_42 -> V_74 ) ;
break;
case V_53 :
F_15 ( V_2 -> V_50 , L_13 ,
V_42 -> V_74 ) ;
break;
default:
F_16 ( V_2 -> V_50 , L_14 ) ;
return - V_17 ;
}
switch ( V_85 ) {
case V_86 :
F_18 ( V_2 ) ;
break;
case V_87 :
F_13 ( V_2 , 0 , 0 , 0 ) ;
break;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
T_2 V_3 ;
switch ( V_89 ) {
case V_90 :
break;
case V_91 :
V_3 = F_6 ( V_2 , V_92 ) ;
V_3 &= ~ V_93 ;
V_3 |= 0x2 ;
F_3 ( V_2 , V_92 , V_3 ) ;
V_3 = F_6 ( V_2 , V_94 ) ;
V_3 &= ~ V_95 ;
F_3 ( V_2 , V_94 , V_3 ) ;
break;
case V_96 :
if ( V_2 -> V_97 . V_98 == V_99 ) {
V_3 = F_6 ( V_2 , V_100 ) ;
V_3 &= ~ V_101 ;
F_3 ( V_2 , V_100 , V_3 ) ;
V_3 = F_6 ( V_2 , V_94 ) ;
V_3 |= V_102 | V_103 ;
F_3 ( V_2 , V_94 , V_3 ) ;
V_3 = F_6 ( V_2 , V_92 ) ;
V_3 |= V_104 | 0x6 ;
F_3 ( V_2 , V_92 , V_3 ) ;
F_21 ( 100 ) ;
V_3 &= ~ V_104 ;
F_3 ( V_2 , V_92 , V_3 ) ;
V_3 = F_6 ( V_2 , V_94 ) ;
V_3 &= ~ V_102 ;
F_3 ( V_2 , V_94 , V_3 ) ;
}
V_3 = F_6 ( V_2 , V_92 ) ;
V_3 &= ~ V_93 ;
V_3 |= 0x04 ;
F_3 ( V_2 , V_92 , V_3 ) ;
V_3 = F_6 ( V_2 , V_94 ) ;
V_3 |= V_95 ;
F_3 ( V_2 , V_94 , V_3 ) ;
break;
case V_99 :
V_3 = F_6 ( V_2 , V_94 ) ;
V_3 |= V_102 ;
V_3 &= ~ V_103 ;
F_3 ( V_2 , V_94 , V_3 ) ;
V_3 = F_6 ( V_2 , V_92 ) ;
V_3 &= ~ V_93 ;
V_3 |= V_104 ;
F_3 ( V_2 , V_92 , V_3 ) ;
V_3 = F_6 ( V_2 , V_100 ) ;
V_3 |= V_101 ;
F_3 ( V_2 , V_100 , V_3 ) ;
break;
}
V_2 -> V_97 . V_98 = V_89 ;
return 0 ;
}
static int F_22 ( struct V_105 * V_106 ,
unsigned int V_107 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_41 * V_42 = F_14 ( V_2 ) ;
unsigned int V_108 = F_6 ( V_2 , V_109 ) ;
V_108 &= ~ ( V_110 | V_111 |
V_112 | V_113 | V_114 ) ;
switch ( V_107 & V_115 ) {
case V_116 :
V_42 -> V_76 = 0 ;
break;
case V_117 :
V_108 |= V_113 ;
V_42 -> V_76 = 1 ;
break;
case V_118 :
V_108 |= V_112 ;
V_42 -> V_76 = 1 ;
break;
case V_119 :
V_108 |= V_113 | V_112 ;
V_42 -> V_76 = 1 ;
break;
default:
return - V_17 ;
}
switch ( V_107 & V_120 ) {
case V_121 :
V_108 |= V_111 ;
case V_122 :
V_108 |= 0x3 ;
break;
case V_123 :
V_108 |= 0x2 ;
break;
case V_124 :
break;
case V_125 :
V_108 |= 0x1 ;
break;
default:
return - V_17 ;
}
switch ( V_107 & V_120 ) {
case V_122 :
case V_121 :
switch ( V_107 & V_126 ) {
case V_127 :
break;
case V_128 :
V_108 |= V_110 ;
break;
default:
return - V_17 ;
}
break;
case V_123 :
case V_124 :
case V_125 :
switch ( V_107 & V_126 ) {
case V_127 :
break;
case V_129 :
V_108 |= V_110 | V_111 ;
break;
case V_128 :
V_108 |= V_110 ;
break;
case V_130 :
V_108 |= V_111 ;
break;
default:
return - V_17 ;
}
break;
default:
return - V_17 ;
}
F_3 ( V_2 , V_109 , V_108 ) ;
return 0 ;
}
static int F_23 ( struct V_131 * V_132 ,
struct V_133 * V_134 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_41 * V_42 = F_14 ( V_2 ) ;
int V_46 , V_29 , V_135 , V_136 , V_137 ;
unsigned int V_138 , V_139 , V_108 , V_140 , V_141 ;
V_138 = F_6 ( V_2 , V_142 ) ;
V_138 &= ~ ( V_143 | V_144 ) ;
V_139 = F_6 ( V_2 , V_145 ) ;
V_108 = F_6 ( V_2 , V_109 ) ;
V_108 &= ~ V_146 ;
V_140 = F_6 ( V_2 , V_147 ) ;
V_140 &= ~ V_148 ;
V_141 = F_6 ( V_2 , V_149 ) ;
V_141 &= ~ V_150 ;
V_42 -> V_79 = F_24 ( V_134 ) ;
if ( V_42 -> V_151 ) {
int V_152 = ( ( V_139 & V_153 ) >>
V_154 ) + 1 ;
V_42 -> V_77 = V_42 -> V_79 * V_42 -> V_151 * V_152 ;
} else {
V_42 -> V_77 = 2 * V_42 -> V_79 ;
switch ( F_25 ( V_134 ) ) {
case V_155 :
V_42 -> V_77 *= 16 ;
break;
case V_156 :
V_42 -> V_77 *= 20 ;
V_108 |= 0x4 ;
break;
case V_157 :
V_42 -> V_77 *= 24 ;
V_108 |= 0x8 ;
break;
case V_158 :
V_42 -> V_77 *= 32 ;
V_108 |= 0xc ;
break;
default:
return - V_17 ;
}
}
F_15 ( V_2 -> V_50 , L_15 , V_42 -> V_77 ) ;
V_46 = F_18 ( V_2 ) ;
if ( V_46 != 0 )
return V_46 ;
V_135 = 0 ;
V_136 = abs ( ( V_42 -> V_75 / V_78 [ 0 ] . V_36 )
- V_42 -> V_79 ) ;
for ( V_29 = 1 ; V_29 < F_11 ( V_78 ) ; V_29 ++ ) {
V_137 = abs ( ( V_42 -> V_75 /
V_78 [ V_29 ] . V_36 ) - V_42 -> V_79 ) ;
if ( V_137 < V_136 ) {
V_135 = V_29 ;
V_136 = V_137 ;
}
}
F_15 ( V_2 -> V_50 , L_16 ,
V_78 [ V_135 ] . V_36 ) ;
V_138 |= ( V_78 [ V_135 ] . V_159
<< V_160 ) ;
V_135 = 0 ;
V_136 = abs ( V_42 -> V_79 - V_161 [ 0 ] . V_162 ) ;
for ( V_29 = 1 ; V_29 < F_11 ( V_161 ) ; V_29 ++ ) {
V_137 = abs ( V_42 -> V_79 - V_161 [ V_29 ] . V_162 ) ;
if ( V_137 < V_136 ) {
V_135 = V_29 ;
V_136 = V_137 ;
}
}
F_15 ( V_2 -> V_50 , L_17 ,
V_161 [ V_135 ] . V_162 ) ;
V_138 |= ( V_161 [ V_135 ] . V_163
<< V_164 ) ;
V_135 = 0 ;
V_136 = V_165 ;
for ( V_29 = 0 ; V_29 < F_11 ( V_166 ) ; V_29 ++ ) {
V_137 = ( ( V_42 -> V_75 * 10 ) / V_166 [ V_29 ] . div )
- V_42 -> V_77 ;
if ( V_137 < 0 )
break;
if ( V_137 < V_136 ) {
V_135 = V_29 ;
V_136 = V_137 ;
}
}
V_42 -> V_77 = ( V_42 -> V_75 * 10 ) / V_166 [ V_135 ] . div ;
F_15 ( V_2 -> V_50 , L_18 ,
V_166 [ V_135 ] . div , V_42 -> V_77 ) ;
V_140 |= V_166 [ V_135 ] . V_167 ;
F_15 ( V_2 -> V_50 , L_19 , V_42 -> V_77 / V_42 -> V_79 ) ;
V_141 |= V_42 -> V_77 / V_42 -> V_79 ;
if ( V_42 -> V_168 . V_169 ) {
struct V_170 * V_168 = & V_42 -> V_168 ;
struct V_171 * V_172 ;
int V_173 ;
V_135 = 0 ;
V_136 = abs ( V_168 -> V_174 [ 0 ] . V_162 - V_42 -> V_79 ) ;
for ( V_29 = 0 ; V_29 < V_168 -> V_169 ; V_29 ++ ) {
V_137 = abs ( V_168 -> V_174 [ V_29 ] . V_162 -
V_42 -> V_79 ) ;
if ( V_137 < V_136 ) {
V_136 = V_137 ;
V_135 = V_29 ;
}
}
V_172 = & V_168 -> V_174 [ V_135 ] ;
F_15 ( V_2 -> V_50 , L_20 ,
V_172 -> V_175 , V_172 -> V_162 ) ;
V_173 = F_6 ( V_2 , V_176 ) & V_177 ;
if ( V_173 & V_177 )
F_3 ( V_2 , V_176 , 0 ) ;
for ( V_29 = 1 ; V_29 < F_11 ( V_172 -> V_178 ) ; V_29 ++ )
F_3 ( V_2 , V_176 + V_29 , V_172 -> V_178 [ V_29 ] ) ;
V_173 |= ( V_172 -> V_178 [ 0 ] & ~ V_177 ) ;
F_3 ( V_2 , V_176 , V_173 ) ;
}
F_3 ( V_2 , V_142 , V_138 ) ;
F_3 ( V_2 , V_109 , V_108 ) ;
F_3 ( V_2 , V_147 , V_140 ) ;
F_3 ( V_2 , V_149 , V_141 ) ;
return 0 ;
}
static int F_26 ( struct V_105 * V_179 , int V_180 )
{
struct V_1 * V_2 = V_179 -> V_2 ;
unsigned int V_3 ;
V_3 = F_6 ( V_2 , V_181 ) ;
if ( V_180 )
V_3 |= V_182 ;
else
V_3 &= ~ V_182 ;
F_3 ( V_2 , V_181 , V_3 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_183 ,
int V_184 , unsigned int V_185 , int V_186 )
{
struct V_41 * V_42 = F_14 ( V_2 ) ;
switch ( V_183 ) {
case V_73 :
case V_53 :
V_42 -> V_72 = V_183 ;
V_42 -> V_74 = V_185 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
static int F_28 ( struct V_105 * V_106 ,
unsigned int V_187 , unsigned int V_188 , int V_152 , int V_189 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_41 * V_42 = F_14 ( V_2 ) ;
unsigned int V_139 = F_6 ( V_2 , V_145 ) ;
V_139 &= ~ ( V_190 | V_153 ) ;
if ( V_152 < 0 || V_152 > 4 )
return - V_17 ;
V_42 -> V_151 = V_189 ;
if ( V_152 == 0 )
V_152 = 1 ;
V_139 |= ( V_152 - 1 ) << V_154 ;
switch ( V_188 ) {
case 1 :
break;
case 2 :
V_139 |= 0x10 ;
break;
case 4 :
V_139 |= 0x20 ;
break;
case 8 :
V_139 |= 0x30 ;
break;
default:
return - V_17 ;
}
F_3 ( V_2 , V_145 , V_139 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_14 ( V_2 ) ;
int V_46 ;
T_2 V_3 ;
V_46 = F_30 ( V_2 , 8 , 16 , V_42 -> V_191 ) ;
if ( V_46 != 0 ) {
F_16 ( V_2 -> V_50 , L_21 , V_46 ) ;
return V_46 ;
}
V_3 = F_6 ( V_2 , V_4 ) ;
if ( V_3 != 0x9081 ) {
F_16 ( V_2 -> V_50 , L_22 , V_3 ) ;
V_46 = - V_17 ;
return V_46 ;
}
V_46 = F_2 ( V_2 ) ;
if ( V_46 < 0 ) {
F_16 ( V_2 -> V_50 , L_23 ) ;
return V_46 ;
}
V_3 = 0 ;
if ( V_42 -> V_168 . V_192 )
V_3 |= V_193 ;
if ( ! V_42 -> V_168 . V_194 )
V_3 |= V_195 ;
F_17 ( V_2 , V_196 ,
V_193 | V_195 , V_3 ) ;
F_20 ( V_2 , V_96 ) ;
V_3 = F_6 ( V_2 , V_197 ) ;
F_3 ( V_2 , V_197 , V_3 | V_198 ) ;
V_3 = F_6 ( V_2 , V_199 ) ;
F_3 ( V_2 , V_199 ,
V_3 | V_200 ) ;
if ( ! V_42 -> V_168 . V_169 ) {
F_15 ( V_2 -> V_50 ,
L_24 ) ;
F_31 ( V_2 , V_201 ,
F_11 ( V_201 ) ) ;
}
return V_46 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_99 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , T_3 V_202 )
{
F_20 ( V_2 , V_99 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 * V_203 = V_2 -> V_203 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_204 -> V_205 ; V_29 ++ ) {
if ( V_29 == V_4 )
continue;
F_3 ( V_2 , V_29 , V_203 [ V_29 ] ) ;
}
F_20 ( V_2 , V_96 ) ;
return 0 ;
}
static T_4 int F_35 ( struct V_206 * V_207 ,
const struct V_208 * V_209 )
{
struct V_41 * V_42 ;
int V_46 ;
V_42 = F_36 ( sizeof( struct V_41 ) , V_210 ) ;
if ( V_42 == NULL )
return - V_211 ;
F_37 ( V_207 , V_42 ) ;
V_42 -> V_191 = V_212 ;
if ( F_38 ( & V_207 -> V_50 ) )
memcpy ( & V_42 -> V_168 , F_38 ( & V_207 -> V_50 ) ,
sizeof( V_42 -> V_168 ) ) ;
V_46 = F_39 ( & V_207 -> V_50 ,
& V_213 , & V_214 , 1 ) ;
if ( V_46 < 0 )
F_40 ( V_42 ) ;
return V_46 ;
}
static T_5 int F_41 ( struct V_206 * V_215 )
{
F_42 ( & V_215 -> V_50 ) ;
F_40 ( F_43 ( V_215 ) ) ;
return 0 ;
}
static int T_6 F_44 ( void )
{
int V_46 = 0 ;
#if F_45 ( V_216 ) || F_45 ( V_217 )
V_46 = F_46 ( & V_218 ) ;
if ( V_46 != 0 ) {
F_47 ( V_219 L_25 ,
V_46 ) ;
}
#endif
return V_46 ;
}
static void T_7 F_48 ( void )
{
#if F_45 ( V_216 ) || F_45 ( V_217 )
F_49 ( & V_218 ) ;
#endif
}
