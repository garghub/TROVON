static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_9 * V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
T_1 V_13 ;
unsigned int V_14 , V_15 , V_16 , V_17 ;
unsigned int div ;
int V_18 ;
div = 1 ;
V_10 -> V_19 = 0 ;
while ( ( V_11 / div ) > 13500000 ) {
div *= 2 ;
V_10 -> V_19 ++ ;
if ( div > 8 ) {
F_3 ( L_1 ,
V_11 ) ;
return - V_20 ;
}
}
F_4 ( L_2 , V_11 , V_12 ) ;
V_11 /= div ;
div = 0 ;
V_17 = V_12 * 2 ;
while ( V_17 < 90000000 ) {
div ++ ;
V_17 *= 2 ;
if ( div > 7 ) {
F_3 ( L_3 ,
V_12 ) ;
return - V_20 ;
}
}
V_10 -> V_21 = div ;
F_4 ( L_4 , V_17 ) ;
for ( V_18 = 0 ; V_18 < F_5 ( V_22 ) ; V_18 ++ ) {
if ( V_22 [ V_18 ] . V_23 <= V_11 && V_11 <= V_22 [ V_18 ] . V_24 ) {
V_10 -> V_25 = V_22 [ V_18 ] . V_25 ;
V_17 /= V_22 [ V_18 ] . V_26 ;
break;
}
}
if ( V_18 == F_5 ( V_22 ) ) {
F_3 ( L_5 , V_11 ) ;
return - V_20 ;
}
V_15 = V_17 / V_11 ;
V_10 -> V_27 = V_15 ;
V_16 = V_17 % V_11 ;
F_4 ( L_6 , V_16 ) ;
V_13 = V_28 * ( long long ) V_16 ;
F_6 ( V_13 , V_11 ) ;
V_14 = V_13 & 0xFFFFFFFF ;
if ( ( V_14 % 10 ) >= 5 )
V_14 += 5 ;
V_10 -> V_29 = V_14 / 10 ;
F_4 ( L_7 ,
V_10 -> V_27 , V_10 -> V_29 ,
V_10 -> V_25 , V_10 -> V_21 ,
V_10 -> V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_30 , int V_31 ,
unsigned int V_11 , unsigned int V_12 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
T_2 V_34 , V_35 , V_36 ;
struct V_9 V_10 ;
int V_37 ;
if ( V_11 == V_33 -> V_38 && V_12 == V_33 -> V_39 )
return 0 ;
if ( V_12 == 0 ) {
F_9 ( V_2 -> V_40 , L_8 ) ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_34 = F_10 ( V_2 , V_41 ) ;
V_34 &= ~ V_42 ;
F_11 ( V_2 , V_41 , V_34 ) ;
return 0 ;
}
V_37 = F_2 ( & V_10 , V_11 , V_12 ) ;
if ( V_37 != 0 )
return V_37 ;
V_36 = F_10 ( V_2 , V_43 ) ;
V_36 &= ~ V_44 ;
switch ( V_30 ) {
case V_45 :
break;
case V_46 :
V_36 |= 1 ;
break;
case V_47 :
V_36 |= 2 ;
break;
default:
F_12 ( V_2 -> V_40 , L_9 , V_30 ) ;
return - V_20 ;
}
V_34 = F_10 ( V_2 , V_41 ) ;
V_34 &= ~ V_42 ;
F_11 ( V_2 , V_41 , V_34 ) ;
if ( V_10 . V_29 )
V_34 |= V_48 ;
else
V_34 &= ~ V_48 ;
F_11 ( V_2 , V_41 , V_34 ) ;
F_11 ( V_2 , V_49 ,
( V_10 . V_21 << V_50 ) |
( V_10 . V_25 << V_51 ) ) ;
F_11 ( V_2 , V_52 , V_10 . V_29 ) ;
V_35 = F_10 ( V_2 , V_53 ) ;
V_35 &= ~ V_54 ;
V_35 |= V_10 . V_27 << V_55 ;
F_11 ( V_2 , V_53 , V_35 ) ;
V_36 &= ~ V_56 ;
V_36 |= V_10 . V_19 << V_57 ;
F_11 ( V_2 , V_43 , V_36 ) ;
F_11 ( V_2 , V_41 , V_34 | V_42 ) ;
F_9 ( V_2 -> V_40 , L_10 , V_11 , V_12 ) ;
V_33 -> V_38 = V_11 ;
V_33 -> V_39 = V_12 ;
V_33 -> V_58 = V_31 ;
return 0 ;
}
static int F_13 ( struct V_59 * V_60 , int V_30 , int V_31 ,
unsigned int V_11 , unsigned int V_12 )
{
return F_7 ( V_60 -> V_2 , V_30 , V_31 , V_11 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
unsigned int V_3 ;
switch ( V_33 -> V_61 ) {
case V_62 :
F_9 ( V_2 -> V_40 , L_11 , V_33 -> V_63 ) ;
V_3 = F_10 ( V_2 , V_64 ) ;
V_3 &= ~ ( V_65 | V_66 ) ;
if ( V_33 -> V_63 > 13500000 ) {
V_3 |= V_65 ;
V_33 -> V_67 = V_33 -> V_63 / 2 ;
} else {
V_3 &= ~ V_65 ;
V_33 -> V_67 = V_33 -> V_63 ;
}
F_11 ( V_2 , V_64 , V_3 ) ;
break;
case V_68 :
F_9 ( V_2 -> V_40 , L_12 ,
V_33 -> V_39 ) ;
V_3 = F_10 ( V_2 , V_64 ) ;
V_3 |= V_66 ;
if ( V_33 -> V_39 > 13500000 ) {
V_3 |= V_65 ;
V_33 -> V_67 = V_33 -> V_39 / 2 ;
} else {
V_3 &= ~ V_65 ;
V_33 -> V_67 = V_33 -> V_39 ;
}
F_11 ( V_2 , V_64 , V_3 ) ;
break;
default:
F_12 ( V_2 -> V_40 , L_13 ) ;
return - V_20 ;
}
F_9 ( V_2 -> V_40 , L_14 , V_33 -> V_67 ) ;
return 0 ;
}
static int F_15 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 = V_70 -> V_2 ;
switch ( V_73 ) {
case V_74 :
return F_14 ( V_2 ) ;
case V_75 :
break;
}
return 0 ;
}
static int F_16 ( struct V_71 * V_72 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_17 ( V_72 ) ;
struct V_69 * V_80 = V_79 -> V_81 [ 0 ] ;
struct V_1 * V_2 = V_80 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
if ( V_77 -> V_82 . integer . V_82 [ 0 ] == 0 ) {
if ( V_33 -> V_83 == 0 ) {
F_9 ( V_2 -> V_40 , L_15 ) ;
F_18 ( V_2 , V_84 ,
V_85 |
V_86 ,
0 ) ;
}
V_33 -> V_83 ++ ;
V_33 -> V_87 . V_88 = true ;
}
V_37 = F_19 ( V_72 , V_77 ) ;
if ( V_77 -> V_82 . integer . V_82 [ 0 ] == 1 ) {
if ( V_33 -> V_83 == 1 ) {
F_9 ( V_2 -> V_40 , L_16 ) ;
F_18 ( V_2 , V_84 ,
V_85 |
V_86 ,
V_85 |
V_86 ) ;
}
V_33 -> V_83 -- ;
V_33 -> V_87 . V_88 = false ;
}
F_9 ( V_2 -> V_40 , L_17 ,
V_33 -> V_83 ) ;
return V_37 ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 * V_89 = V_2 -> V_90 ;
int V_18 ;
if ( ! V_2 -> V_91 )
return;
V_2 -> V_92 = 0 ;
for ( V_18 = 1 ; V_18 < V_93 ; V_18 ++ ) {
if ( V_89 [ V_18 ] == V_94 [ V_18 ] )
continue;
F_11 ( V_2 , V_18 , V_89 [ V_18 ] ) ;
}
V_2 -> V_91 = 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_95 V_96 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
switch ( V_96 ) {
case V_97 :
case V_98 :
F_18 ( V_2 , V_99 ,
V_100 , 0x2 ) ;
F_18 ( V_2 , V_101 ,
V_102 , V_102 ) ;
break;
case V_103 :
if ( V_2 -> V_104 . V_105 == V_106 ) {
V_37 = F_22 ( F_5 ( V_33 -> V_107 ) ,
V_33 -> V_107 ) ;
if ( V_37 != 0 )
return V_37 ;
F_20 ( V_2 ) ;
F_11 ( V_2 , 0x44 , 3 ) ;
F_11 ( V_2 , 0x56 , 3 ) ;
F_11 ( V_2 , 0x44 , 0 ) ;
F_18 ( V_2 , V_108 ,
V_109 |
V_110 |
V_111 |
V_112 ,
V_109 |
V_110 |
V_111 |
V_112 ) ;
if ( ! V_33 -> V_113 . V_114 ||
! V_33 -> V_113 . V_115 )
F_18 ( V_2 , V_116 ,
V_117 ,
V_117 ) ;
F_18 ( V_2 , V_99 ,
V_100 |
V_118 ,
V_118 | 0x2 ) ;
F_23 ( 32 ) ;
F_18 ( V_2 , V_108 ,
V_112 |
V_109 , 0 ) ;
}
F_18 ( V_2 , V_99 ,
V_100 , 0x4 ) ;
F_18 ( V_2 , V_101 ,
V_102 , 0 ) ;
break;
case V_106 :
F_18 ( V_2 , V_116 ,
V_117 , 0 ) ;
F_18 ( V_2 , V_99 ,
V_100 | V_118 ,
0 ) ;
F_18 ( V_2 , V_108 ,
V_109 |
V_110 |
V_111 |
V_112 , 0 ) ;
#ifdef F_24
V_2 -> V_91 = 1 ;
#endif
F_25 ( F_5 ( V_33 -> V_107 ) ,
V_33 -> V_107 ) ;
break;
}
V_2 -> V_104 . V_105 = V_96 ;
return 0 ;
}
static int F_26 ( struct V_59 * V_119 ,
int V_120 , unsigned int V_121 , int V_122 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
switch ( V_120 ) {
case V_62 :
V_33 -> V_63 = V_121 ;
case V_68 :
V_33 -> V_61 = V_120 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_27 ( struct V_59 * V_60 ,
unsigned int V_123 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
unsigned int V_124 = F_10 ( V_2 , V_125 ) ;
unsigned int V_126 = F_10 ( V_2 , V_127 ) ;
V_124 &= ~ ( V_128 | V_129 |
V_130 | V_131 ) ;
V_126 &= ~ V_132 ;
switch ( V_123 & V_133 ) {
case V_134 :
V_33 -> V_135 = 0 ;
break;
case V_136 :
V_126 |= V_132 ;
V_33 -> V_135 = 1 ;
break;
case V_137 :
V_124 |= V_128 ;
V_33 -> V_135 = 1 ;
break;
case V_138 :
V_124 |= V_128 ;
V_126 |= V_132 ;
V_33 -> V_135 = 1 ;
break;
default:
return - V_20 ;
}
switch ( V_123 & V_139 ) {
case V_140 :
V_124 |= V_130 ;
case V_141 :
V_124 |= 0x18 ;
break;
case V_142 :
V_124 |= 0x10 ;
break;
case V_143 :
break;
case V_144 :
V_124 |= 0x8 ;
break;
default:
return - V_20 ;
}
switch ( V_123 & V_139 ) {
case V_141 :
case V_140 :
switch ( V_123 & V_145 ) {
case V_146 :
break;
case V_147 :
V_124 |= V_129 ;
break;
default:
return - V_20 ;
}
break;
case V_142 :
case V_143 :
case V_144 :
switch ( V_123 & V_145 ) {
case V_146 :
break;
case V_148 :
V_124 |= V_129 | V_130 ;
break;
case V_147 :
V_124 |= V_129 ;
break;
case V_149 :
V_124 |= V_130 ;
break;
default:
return - V_20 ;
}
break;
default:
return - V_20 ;
}
F_11 ( V_2 , V_125 , V_124 ) ;
F_11 ( V_2 , V_127 , V_126 ) ;
return 0 ;
}
static int F_28 ( struct V_150 * V_151 ,
struct V_152 * V_153 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 , V_18 , V_154 , V_155 , V_156 ;
unsigned int V_157 , V_158 , V_124 , V_126 ;
V_157 = F_10 ( V_2 , V_159 ) ;
V_157 &= ~ V_160 ;
V_158 = F_10 ( V_2 , V_161 ) ;
V_158 &= ~ ( V_162 | V_163 ) ;
V_124 = F_10 ( V_2 , V_125 ) ;
V_124 &= ~ V_164 ;
V_126 = F_10 ( V_2 , V_127 ) ;
V_126 &= ~ V_165 ;
V_33 -> V_166 = F_29 ( V_153 ) ;
V_33 -> V_167 = 2 * V_33 -> V_166 ;
if ( V_33 -> V_168 ) {
F_9 ( V_2 -> V_40 , L_18 ,
V_33 -> V_168 , V_33 -> V_169 ) ;
V_33 -> V_167 *= V_33 -> V_169 * V_33 -> V_168 ;
} else {
switch ( F_30 ( V_153 ) ) {
case V_170 :
V_33 -> V_167 *= 16 ;
break;
case V_171 :
V_33 -> V_167 *= 20 ;
V_124 |= 0x8 ;
break;
case V_172 :
V_33 -> V_167 *= 24 ;
V_124 |= 0x10 ;
break;
case V_173 :
V_33 -> V_167 *= 32 ;
V_124 |= 0x18 ;
break;
default:
return - V_20 ;
}
}
F_9 ( V_2 -> V_40 , L_19 , V_33 -> V_167 ) ;
V_37 = F_14 ( V_2 ) ;
if ( V_37 != 0 )
return V_37 ;
V_154 = 0 ;
V_155 = abs ( ( V_33 -> V_67 / V_174 [ 0 ] . V_26 )
- V_33 -> V_166 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_174 ) ; V_18 ++ ) {
V_156 = abs ( ( V_33 -> V_67 /
V_174 [ V_18 ] . V_26 ) - V_33 -> V_166 ) ;
if ( V_156 < V_155 ) {
V_154 = V_18 ;
V_155 = V_156 ;
}
}
F_9 ( V_2 -> V_40 , L_20 ,
V_174 [ V_154 ] . V_26 ) ;
V_158 |= ( V_174 [ V_154 ] . V_175
<< V_176 ) ;
V_154 = 0 ;
V_155 = abs ( V_33 -> V_166 - V_177 [ 0 ] . V_178 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_177 ) ; V_18 ++ ) {
V_156 = abs ( V_33 -> V_166 - V_177 [ V_18 ] . V_178 ) ;
if ( V_156 < V_155 ) {
V_154 = V_18 ;
V_155 = V_156 ;
}
}
F_9 ( V_2 -> V_40 , L_21 ,
V_177 [ V_154 ] . V_178 ) ;
V_158 |= ( V_177 [ V_154 ] . V_179
<< V_180 ) ;
V_154 = 0 ;
V_155 = V_181 ;
for ( V_18 = 0 ; V_18 < F_5 ( V_182 ) ; V_18 ++ ) {
V_156 = ( ( V_33 -> V_67 * 10 ) / V_182 [ V_18 ] . div )
- V_33 -> V_167 ;
if ( V_156 < 0 )
break;
if ( V_156 < V_155 ) {
V_154 = V_18 ;
V_155 = V_156 ;
}
}
V_33 -> V_167 = ( V_33 -> V_67 * 10 ) / V_182 [ V_154 ] . div ;
F_9 ( V_2 -> V_40 , L_22 ,
V_182 [ V_154 ] . div , V_33 -> V_167 ) ;
V_157 |= V_182 [ V_154 ] . V_183 << V_184 ;
F_9 ( V_2 -> V_40 , L_23 , V_33 -> V_167 / V_33 -> V_166 ) ;
V_126 |= V_33 -> V_167 / V_33 -> V_166 ;
F_11 ( V_2 , V_159 , V_157 ) ;
F_11 ( V_2 , V_161 , V_158 ) ;
F_11 ( V_2 , V_125 , V_124 ) ;
F_11 ( V_2 , V_127 , V_126 ) ;
if ( V_33 -> V_113 . V_185 ) {
T_2 V_186 = F_10 ( V_2 , V_187 ) ;
struct V_188 * V_189 ;
V_154 = 0 ;
V_155 = abs ( V_33 -> V_113 . V_190 [ 0 ] . V_178
- V_33 -> V_166 ) ;
for ( V_18 = 0 ; V_18 < V_33 -> V_113 . V_185 ; V_18 ++ ) {
V_156 = abs ( V_33 -> V_113 . V_190 [ V_18 ] . V_178
- V_33 -> V_166 ) ;
if ( V_156 < V_155 ) {
V_155 = V_156 ;
V_154 = V_18 ;
}
}
V_189 = & V_33 -> V_113 . V_190 [ V_154 ] ;
F_9 ( V_2 -> V_40 , L_24 ,
V_189 -> V_191 , V_189 -> V_178 ) ;
F_18 ( V_2 , V_187 , V_192 , 0 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_189 -> V_193 ) ; V_18 ++ )
F_11 ( V_2 , V_187 + V_18 , V_189 -> V_193 [ V_18 ] ) ;
F_18 ( V_2 , V_187 , V_192 , V_186 ) ;
}
return 0 ;
}
static int F_31 ( struct V_59 * V_119 , int V_194 )
{
struct V_1 * V_2 = V_119 -> V_2 ;
unsigned int V_3 ;
V_3 = F_10 ( V_2 , V_195 ) ;
if ( V_194 )
V_3 |= V_196 ;
else
V_3 &= ~ V_196 ;
F_11 ( V_2 , V_195 , V_3 ) ;
return 0 ;
}
static int F_32 ( struct V_59 * V_60 , unsigned int V_197 ,
unsigned int V_198 , int V_199 , int V_200 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_124 = 0 ;
int V_201 = 0 ;
if ( V_199 == 0 ) {
V_33 -> V_168 = 0 ;
goto V_202;
}
V_124 |= V_203 ;
V_201 |= V_204 ;
switch ( V_198 ) {
case 3 :
break;
case 0xc :
V_124 |= V_205 ;
break;
default:
return - V_20 ;
}
switch ( V_197 ) {
case 3 :
break;
case 0xc :
V_201 |= V_206 ;
break;
default:
return - V_20 ;
}
V_202:
V_33 -> V_169 = V_200 ;
V_33 -> V_168 = V_199 / 2 ;
F_18 ( V_2 , V_125 ,
V_203 | V_205 , V_124 ) ;
F_18 ( V_2 , V_207 ,
V_204 | V_206 , V_201 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
struct V_208 * V_104 = & V_2 -> V_104 ;
int V_37 , V_18 , V_209 ;
V_33 -> V_87 . V_210 = 1 ;
V_33 -> V_87 . V_211 = - 2 ;
V_33 -> V_87 . V_212 = 1 ;
V_37 = F_34 ( V_2 , 8 , 16 , V_213 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_25 , V_37 ) ;
return V_37 ;
}
for ( V_18 = 0 ; V_18 < F_5 ( V_33 -> V_107 ) ; V_18 ++ )
V_33 -> V_107 [ V_18 ] . V_214 = V_215 [ V_18 ] ;
V_37 = F_35 ( V_2 -> V_40 , F_5 ( V_33 -> V_107 ) ,
V_33 -> V_107 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_26 , V_37 ) ;
return V_37 ;
}
V_37 = F_22 ( F_5 ( V_33 -> V_107 ) ,
V_33 -> V_107 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_27 , V_37 ) ;
goto V_216;
}
V_209 = F_10 ( V_2 , V_4 ) ;
if ( V_209 != V_94 [ V_4 ] ) {
F_12 ( V_2 -> V_40 , L_28 , V_209 ) ;
V_37 = - V_20 ;
goto V_217;
}
V_37 = F_11 ( V_2 , V_4 , 0xffff ) ;
if ( V_37 != 0 )
goto V_217;
V_2 -> V_92 = 1 ;
V_33 -> V_83 = 2 ;
F_18 ( V_2 , V_218 ,
V_219 , V_219 ) ;
F_18 ( V_2 , V_220 ,
V_221 , V_221 ) ;
F_18 ( V_2 , V_222 ,
V_223 , 0 ) ;
F_18 ( V_2 , V_224 , V_225 , 0 ) ;
F_36 ( V_2 , V_33 -> V_113 . V_114 ,
V_33 -> V_113 . V_115 ,
V_33 -> V_113 . V_226 ,
V_33 -> V_113 . V_227 ,
V_33 -> V_113 . V_228 ,
V_33 -> V_113 . V_229 ,
V_33 -> V_113 . V_230 ,
V_33 -> V_113 . V_231 ) ;
V_37 = F_21 ( V_2 , V_103 ) ;
if ( V_37 != 0 )
goto V_217;
F_37 ( V_2 , V_232 ,
F_5 ( V_232 ) ) ;
if ( V_33 -> V_113 . V_185 != 0 ) {
F_9 ( V_2 -> V_40 , L_29 ) ;
} else {
F_9 ( V_2 -> V_40 , L_30 ) ;
F_37 ( V_2 , V_233 ,
F_5 ( V_233 ) ) ;
}
F_38 ( V_104 , V_234 ,
F_5 ( V_234 ) ) ;
F_39 ( V_2 ) ;
F_40 ( V_104 , V_235 , F_5 ( V_235 ) ) ;
F_41 ( V_2 , V_33 -> V_113 . V_114 ,
V_33 -> V_113 . V_115 ) ;
return 0 ;
V_217:
F_25 ( F_5 ( V_33 -> V_107 ) , V_33 -> V_107 ) ;
V_216:
F_42 ( F_5 ( V_33 -> V_107 ) , V_33 -> V_107 ) ;
return V_37 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
F_21 ( V_2 , V_106 ) ;
F_42 ( F_5 ( V_33 -> V_107 ) , V_33 -> V_107 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , T_3 V_236 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_39 = V_33 -> V_39 ;
int V_38 = V_33 -> V_38 ;
int V_37 ;
V_37 = F_7 ( V_2 , 0 , 0 , 0 , 0 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_31 ) ;
return V_37 ;
}
V_33 -> V_39 = V_39 ;
V_33 -> V_38 = V_38 ;
F_21 ( V_2 , V_106 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
F_21 ( V_2 , V_103 ) ;
if ( V_33 -> V_39 ) {
int V_39 = V_33 -> V_39 ;
int V_38 = V_33 -> V_38 ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_37 = F_7 ( V_2 , 0 , V_33 -> V_58 ,
V_38 , V_39 ) ;
if ( V_37 != 0 )
F_12 ( V_2 -> V_40 , L_32 ) ;
}
return 0 ;
}
static T_4 int F_46 ( struct V_237 * V_238 ,
const struct V_239 * V_240 )
{
struct V_32 * V_33 ;
int V_37 ;
V_33 = F_47 ( sizeof( struct V_32 ) , V_241 ) ;
if ( V_33 == NULL )
return - V_242 ;
F_48 ( V_238 , V_33 ) ;
V_37 = F_49 ( & V_238 -> V_40 ,
& V_243 , & V_244 , 1 ) ;
if ( V_37 < 0 )
F_50 ( V_33 ) ;
return V_37 ;
}
static T_5 int F_51 ( struct V_237 * V_245 )
{
F_52 ( & V_245 -> V_40 ) ;
F_50 ( F_53 ( V_245 ) ) ;
return 0 ;
}
static int T_6 F_54 ( void )
{
int V_37 = 0 ;
#if F_55 ( V_246 ) || F_55 ( V_247 )
V_37 = F_56 ( & V_248 ) ;
if ( V_37 != 0 ) {
F_3 ( L_33 ,
V_37 ) ;
}
#endif
return V_37 ;
}
static void T_7 F_57 ( void )
{
#if F_55 ( V_246 ) || F_55 ( V_247 )
F_58 ( & V_248 ) ;
#endif
}
