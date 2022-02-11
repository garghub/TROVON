static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 [ V_3 ] ;
}
static unsigned int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_3 ( V_4 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_5 ( V_4 , V_3 , V_7 ) ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_7 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_11 = 0 , V_12 = 0 ;
T_1 V_3 , V_13 ;
V_3 = F_3 ( V_4 , V_14 ) ;
V_13 = ( V_3 & V_15 ) >> V_16 ;
if ( V_10 -> V_17 == V_18 ) {
if ( V_13 < V_10 -> V_19 ) {
V_13 ++ ;
V_3 &= ~ V_15 ;
F_5 ( V_4 , V_14 ,
V_3 | ( V_13 << V_16 ) ) ;
} else
V_11 = 1 ;
} else if ( V_10 -> V_17 == V_20 ) {
if ( V_13 > 0 ) {
V_13 -- ;
V_3 &= ~ V_15 ;
F_5 ( V_4 , V_14 ,
V_3 | ( V_13 << V_16 ) ) ;
} else
V_11 = 1 ;
} else
return 1 ;
V_3 = F_3 ( V_4 , V_21 ) ;
V_13 = ( V_3 & V_22 ) >> V_23 ;
if ( V_10 -> V_17 == V_18 ) {
if ( V_13 < V_10 -> V_24 ) {
V_13 ++ ;
V_3 &= ~ V_22 ;
F_5 ( V_4 , V_21 ,
V_3 | ( V_13 << V_23 ) ) ;
} else
V_12 = 1 ;
} else if ( V_10 -> V_17 == V_20 ) {
if ( V_13 > 0 ) {
V_13 -- ;
V_3 &= ~ V_22 ;
F_5 ( V_4 , V_21 ,
V_3 | ( V_13 << V_23 ) ) ;
} else
V_12 = 1 ;
}
if ( ! V_11 || ! V_12 )
F_8 ( V_4 , V_14 , V_25 ) ;
return V_11 & V_12 ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_7 ( V_2 ) ;
struct V_9 * V_26 = & V_8 -> V_26 ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_11 = 0 , V_12 = 0 ;
T_1 V_3 , V_13 ;
V_3 = F_3 ( V_4 , V_27 ) ;
V_13 = ( V_3 & V_28 ) >> V_16 ;
if ( V_26 -> V_17 == V_18 ) {
if ( V_13 < V_26 -> V_19 ) {
V_13 ++ ;
V_3 &= ~ V_28 ;
F_5 ( V_4 , V_27 ,
V_3 | ( V_13 << V_16 ) ) ;
} else
V_11 = 1 ;
} else if ( V_26 -> V_17 == V_20 ) {
if ( V_13 > 0 ) {
V_13 -- ;
V_3 &= ~ V_28 ;
F_5 ( V_4 , V_27 ,
V_3 | ( V_13 << V_16 ) ) ;
} else
V_11 = 1 ;
} else
return 1 ;
V_3 = F_3 ( V_4 , V_29 ) ;
V_13 = ( V_3 & V_30 ) >> V_23 ;
if ( V_26 -> V_17 == V_18 ) {
if ( V_13 < V_26 -> V_24 ) {
V_13 ++ ;
V_3 &= ~ V_30 ;
F_5 ( V_4 , V_29 ,
V_3 | ( V_13 << V_23 ) ) ;
} else
V_12 = 1 ;
} else if ( V_26 -> V_17 == V_20 ) {
if ( V_13 > 0 ) {
V_13 -- ;
V_3 &= ~ V_30 ;
F_5 ( V_4 , V_29 ,
V_3 | ( V_13 << V_23 ) ) ;
} else
V_12 = 1 ;
}
if ( ! V_11 || ! V_12 )
F_8 ( V_4 , V_27 , V_31 ) ;
return V_11 & V_12 ;
}
static void F_10 ( struct V_32 * V_33 )
{
struct V_34 * V_35 =
F_11 ( V_33 , struct V_34 , V_36 . V_33 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_8 * V_8 = F_7 ( V_2 ) ;
struct V_9 * V_10 = & V_8 -> V_10 ,
* V_26 = & V_8 -> V_26 ;
int V_37 , V_38 , V_39 ;
if ( V_10 -> V_17 == V_40 && V_26 -> V_17 == V_40 )
return;
for ( V_37 = 0 ; V_37 <= 63 ; V_37 ++ ) {
V_38 = 1 , V_39 = 1 ;
if ( V_10 -> V_17 != V_40 )
V_38 = F_6 ( V_2 ) ;
if ( V_26 -> V_17 != V_40 )
V_39 = F_9 ( V_2 ) ;
if ( V_38 && V_39 )
break;
if ( V_10 -> V_17 == V_18 ||
V_26 -> V_17 == V_18 ) {
if ( V_37 >= V_41 )
F_12 ( F_13
( 2 ) ) ;
else
F_12 ( F_13
( 1 ) ) ;
} else
F_14 ( 50 ) ;
}
V_10 -> V_17 = V_40 ;
V_26 -> V_17 = V_40 ;
}
static int F_15 ( struct V_42 * V_43 ,
struct V_44 * V_45 , int V_46 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
struct V_8 * V_8 = F_7 ( V_2 ) ;
struct V_9 * V_47 ;
switch ( V_43 -> V_48 ) {
case 0 :
case 1 :
V_47 = & V_8 -> V_10 ;
break;
case 2 :
case 3 :
V_47 = & V_8 -> V_26 ;
break;
default:
F_16 () ;
return - 1 ;
}
switch ( V_46 ) {
case V_49 :
V_47 -> V_17 = V_18 ;
V_47 -> V_50 = 1 ;
if ( ! F_17 ( & V_2 -> V_35 . V_36 ) )
F_18 ( & V_2 -> V_35 . V_36 ,
F_13 ( 1 ) ) ;
break;
case V_51 :
V_47 -> V_17 = V_20 ;
V_47 -> V_50 = 0 ;
if ( ! F_17 ( & V_2 -> V_35 . V_36 ) )
F_18 ( & V_2 -> V_35 . V_36 ,
F_13 ( 1 ) ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_20 ( V_45 ) ;
struct V_8 * V_54 = F_7 ( V_2 ) ;
struct V_9 * V_47 = NULL ;
struct V_55 * V_56 =
(struct V_55 * ) V_45 -> V_57 ;
int V_58 ;
unsigned int V_3 = V_56 -> V_3 ;
T_1 V_13 ;
switch ( V_3 ) {
case V_14 :
V_47 = & V_54 -> V_10 ;
break;
case V_27 :
V_47 = & V_54 -> V_26 ;
break;
default:
break;
}
if ( V_47 ) {
V_47 -> V_19 = V_53 -> V_7 . integer . V_7 [ 0 ] ;
V_47 -> V_24 = V_53 -> V_7 . integer . V_7 [ 1 ] ;
if ( ! V_47 -> V_50 )
return 1 ;
}
V_58 = F_21 ( V_45 , V_53 ) ;
if ( V_58 < 0 )
return V_58 ;
V_13 = F_2 ( V_2 , V_3 ) ;
F_4 ( V_2 , V_3 , V_13 | V_25 ) ;
return 1 ;
}
static int F_22 ( struct V_44 * V_45 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_20 ( V_45 ) ;
struct V_8 * V_54 = F_7 ( V_2 ) ;
struct V_9 * V_10 = & V_54 -> V_10 ;
struct V_9 * V_26 = & V_54 -> V_26 ;
struct V_55 * V_56 =
(struct V_55 * ) V_45 -> V_57 ;
unsigned int V_3 = V_56 -> V_3 ;
switch ( V_3 ) {
case V_14 :
V_53 -> V_7 . integer . V_7 [ 0 ] = V_10 -> V_19 ;
V_53 -> V_7 . integer . V_7 [ 1 ] = V_10 -> V_24 ;
return 0 ;
case V_27 :
V_53 -> V_7 . integer . V_7 [ 0 ] = V_26 -> V_19 ;
V_53 -> V_7 . integer . V_7 [ 1 ] = V_26 -> V_24 ;
return 0 ;
default:
break;
}
return F_23 ( V_45 , V_53 ) ;
}
static int F_24 ( struct V_59 * V_60 ,
int V_61 , unsigned int V_62 , int V_63 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_64 ;
switch ( V_61 ) {
case V_65 :
F_25 ( V_4 , V_66 ,
V_67 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
F_8 ( V_4 , V_66 ,
V_67 ) ;
V_64 = F_2 ( V_2 , V_72 ) &
~ V_73 ;
F_4 ( V_2 , V_72 , V_64 | V_61 ) ;
break;
}
if ( V_63 == V_74 )
F_8 ( V_4 , V_75 ,
V_76 ) ;
else
F_25 ( V_4 , V_75 ,
V_76 ) ;
return 0 ;
}
static int F_26 ( struct V_59 * V_60 , int V_77 , int div )
{
struct V_1 * V_2 = V_60 -> V_2 ;
T_1 V_13 ;
switch ( V_77 ) {
case V_78 :
V_13 = F_2 ( V_2 , V_79 ) &
~ V_80 ;
F_4 ( V_2 , V_79 , V_13 | div ) ;
break;
case V_81 :
V_13 = F_2 ( V_2 , V_82 ) &
~ V_83 ;
F_4 ( V_2 , V_82 , V_13 | div ) ;
break;
case V_84 :
V_13 = F_2 ( V_2 , V_66 ) &
~ V_85 ;
F_4 ( V_2 , V_66 , V_13 | div ) ;
break;
case V_86 :
V_13 = F_2 ( V_2 , V_66 ) &
~ V_87 ;
F_4 ( V_2 , V_66 , V_13 | div ) ;
break;
case V_88 :
V_13 = F_2 ( V_2 , V_66 ) &
~ V_89 ;
F_4 ( V_2 , V_66 , V_13 | div ) ;
break;
case V_90 :
V_13 = F_2 ( V_2 , V_91 ) &
~ V_92 ;
F_4 ( V_2 , V_91 , V_13 | div ) ;
break;
case V_93 :
V_13 = F_2 ( V_2 , V_94 ) &
~ V_95 ;
F_4 ( V_2 , V_94 , V_13 | div ) ;
break;
default:
return - V_96 ;
}
return 0 ;
}
static int F_27 ( struct V_59 * V_60 , unsigned int V_97 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
T_1 V_98 = F_2 ( V_2 , V_99 ) &
~ ( V_100 | V_101 | V_102 ) ;
T_1 V_103 = F_2 ( V_2 , V_104 ) &
~ V_105 ;
T_1 V_106 = F_2 ( V_2 , V_91 ) &
~ V_107 ;
T_1 V_108 = F_2 ( V_2 , V_94 ) &
~ V_109 ;
switch ( V_97 & V_110 ) {
case V_111 :
V_103 |= V_105 ;
V_106 |= V_107 ;
V_108 |= V_109 ;
break;
case V_112 :
break;
default:
return - V_96 ;
}
switch ( V_97 & V_113 ) {
case V_114 :
V_98 |= 0x2 << 8 ;
break;
case V_115 :
break;
case V_116 :
V_98 |= 0x1 << 8 ;
break;
case V_117 :
V_98 |= 0x3 << 8 ;
break;
case V_118 :
V_98 |= 0x3 << 8 | V_101 ;
break;
default:
return - V_96 ;
}
switch ( V_97 & V_119 ) {
case V_120 :
break;
case V_121 :
V_98 |= V_101 | V_100 ;
break;
case V_122 :
V_98 |= V_100 ;
break;
case V_123 :
V_98 |= V_101 ;
break;
default:
return - V_96 ;
}
F_4 ( V_2 , V_99 , V_98 ) ;
F_4 ( V_2 , V_104 , V_103 ) ;
F_4 ( V_2 , V_91 , V_106 ) ;
F_4 ( V_2 , V_94 , V_108 ) ;
return 0 ;
}
static int F_28 ( struct V_124 * V_125 ,
int V_126 , struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
int V_103 = F_1 ( V_2 , V_104 ) &
V_105 ;
int V_127 = 0 ;
if ( ! V_103 || V_126 != V_128 )
return 0 ;
if ( V_125 -> V_129 == V_130 ) {
V_127 = F_1 ( V_2 , V_131 ) &
( V_132 | V_133 ) ;
} else {
V_127 = F_1 ( V_2 , V_131 ) &
( V_134 | V_135 ) ;
}
if ( ! V_127 ) {
F_29 ( V_2 -> V_136 ,
L_1 ,
V_137 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_30 ( struct V_124 * V_125 ,
struct V_138 * V_139 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_98 = F_2 ( V_2 , V_99 ) &
~ V_140 ;
switch ( F_31 ( V_139 ) ) {
case V_141 :
break;
case V_142 :
V_98 |= 0x1 << 10 ;
break;
case V_143 :
V_98 |= 0x2 << 10 ;
break;
case V_144 :
V_98 |= 0x3 << 10 ;
break;
}
F_4 ( V_2 , V_99 , V_98 ) ;
if ( V_125 -> V_129 == V_145 ) {
if ( F_32 ( V_139 ) < 24000 )
F_8 ( V_4 , V_146 ,
V_147 ) ;
else
F_25 ( V_4 , V_146 ,
V_147 ) ;
}
return 0 ;
}
static int F_33 ( struct V_59 * V_148 , int V_149 )
{
struct V_1 * V_2 = V_148 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
if ( V_149 )
F_8 ( V_4 , V_150 , V_151 ) ;
else
F_25 ( V_4 , V_150 , V_151 ) ;
return 0 ;
}
static inline int F_34 ( struct V_152 * V_153 , unsigned int V_154 ,
unsigned int V_155 )
{
T_2 V_156 ;
unsigned int V_157 , V_158 , V_159 , V_160 ;
if ( V_155 >= 2815250 && V_155 <= 3125000 )
V_153 -> div = 0x4 ;
else if ( V_155 >= 5625000 && V_155 <= 6250000 )
V_153 -> div = 0x3 ;
else if ( V_155 >= 11250000 && V_155 <= 12500000 )
V_153 -> div = 0x2 ;
else if ( V_155 >= 22500000 && V_155 <= 25000000 )
V_153 -> div = 0x1 ;
else {
F_35 ( V_161 L_2 , V_155 ) ;
return - V_96 ;
}
if ( V_154 > 48000 )
V_153 -> V_162 = 1 ;
else
V_153 -> V_162 = 8 ;
V_157 = V_155 * ( 1 << ( V_153 -> div + 1 ) ) ;
V_158 = V_154 * V_153 -> V_162 ;
V_153 -> V_163 = V_157 / V_158 ;
V_160 = V_157 % V_158 ;
if ( V_160 ) {
V_156 = V_164 * ( long long ) V_160 ;
F_36 ( V_156 , V_158 ) ;
V_159 = V_156 & 0xFFFFFFFF ;
if ( ( V_159 % 10 ) >= 5 )
V_159 += 5 ;
V_159 /= 10 ;
V_153 -> V_165 = V_159 ;
} else
V_153 -> V_165 = 0 ;
return 0 ;
}
static int F_37 ( struct V_59 * V_60 ,
int V_166 , int V_167 , unsigned int V_168 ,
unsigned int V_169 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
struct V_8 * V_170 = F_7 ( V_2 ) ;
struct V_152 V_153 ;
int V_58 = 0 ;
T_1 V_171 , V_64 ;
if ( V_168 == V_170 -> V_172 && V_169 == V_170 -> V_173 )
return 0 ;
F_25 ( V_4 , V_131 ,
V_174 | V_175 ) ;
if ( V_169 == 0 || V_168 == 0 )
return V_58 ;
V_58 = F_34 ( & V_153 , V_168 , V_169 ) ;
if ( V_58 < 0 )
return V_58 ;
F_38 ( V_4 -> V_136 ,
L_3 ,
V_168 , V_169 , V_153 . V_163 , V_153 . V_165 , V_153 . div ,
V_153 . V_162 ) ;
V_171 = F_2 ( V_2 , V_176 ) &
~ ( V_177 | V_178 | 0xc000 ) ;
F_4 ( V_2 , V_176 ,
V_171 | ( V_153 . div << 8 ) | 0x50 ) ;
F_4 ( V_2 , V_179 ,
( V_153 . V_162 << 11 ) | ( V_153 .
V_163 & V_180 ) ) ;
F_4 ( V_2 , V_181 , V_153 . V_165 ) ;
V_64 = F_2 ( V_2 , V_72 ) &
~ ( V_182 | V_183 ) ;
F_4 ( V_2 , V_72 ,
V_64 | ( V_153 . V_165 ? V_182 : 0 ) |
( V_153 . V_162 == 8 ? V_183 : 0 ) ) ;
F_8 ( V_4 , V_131 , V_175 ) ;
F_8 ( V_4 , V_131 , V_174 ) ;
V_170 -> V_173 = V_169 ;
V_170 -> V_172 = V_168 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
enum V_184 V_185 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
struct V_8 * V_170 = F_7 ( V_2 ) ;
struct V_186 * V_187 =
V_4 -> V_2 . V_188 ;
T_1 V_189 ;
int V_58 ;
switch ( V_185 ) {
case V_190 :
V_189 = F_3 ( V_4 , V_191 ) &
~ ( V_192 | V_193 ) ;
F_5 ( V_4 , V_191 ,
V_189 | V_194 |
V_187 -> V_195 << 14 ) ;
break;
case V_196 :
V_189 = F_3 ( V_4 , V_191 ) ;
V_189 &= ~ V_192 ;
F_5 ( V_4 , V_191 ,
V_189 | V_194 ) ;
break;
case V_197 :
if ( V_2 -> V_35 . V_198 == V_199 ) {
V_58 = F_40 ( F_41 ( V_170 -> V_200 ) ,
V_170 -> V_200 ) ;
if ( V_58 != 0 )
return V_58 ;
F_8 ( V_4 , V_131 ,
V_201 ) ;
F_8 ( V_4 , V_150 ,
V_151 ) ;
F_5 ( V_4 , V_202 ,
V_187 -> V_203 |
( V_187 -> V_204 << 2 ) |
( V_187 -> V_205 << 4 ) |
( V_187 -> V_206 << 6 ) ) ;
F_12 ( F_13
( V_187 ->
V_207 ) ) ;
F_5 ( V_4 , V_202 ,
( V_187 -> V_208 << 8 ) ) ;
F_5 ( V_4 , V_191 ,
( V_187 ->
V_209 << 14 ) |
V_210 | V_211 |
V_212 ) ;
F_12 ( F_13
( V_187 ->
V_213 ) ) ;
V_189 = F_3 ( V_4 , V_191 ) &
~ ( V_192 | V_193 ) ;
V_189 |= V_214 |
( V_187 -> V_215 << 14 ) ;
F_5 ( V_4 , V_191 ,
V_189 ) ;
V_189 |= V_216 ;
F_5 ( V_4 , V_191 , V_189 ) ;
F_5 ( V_4 , V_202 , 0 ) ;
} else {
V_189 = F_3 ( V_4 , V_191 ) &
~ ( V_192 | V_193 ) ;
F_5 ( V_4 , V_191 ,
V_189 | V_214 |
( V_187 ->
V_215 << 14 ) ) ;
}
break;
case V_199 :
F_8 ( V_4 , V_150 , V_151 ) ;
F_8 ( V_4 , V_217 ,
V_218 | V_219 |
V_220 | V_221 ) ;
F_5 ( V_4 , V_202 ,
( V_187 -> V_208 << 8 ) ) ;
V_189 = F_3 ( V_4 , V_191 ) &
~ V_211 ;
F_5 ( V_4 , V_191 , V_189 ) ;
F_12 ( F_13
( V_187 ->
V_222 ) ) ;
F_5 ( V_4 , V_202 ,
( V_187 -> V_208 << 8 ) |
V_187 -> V_203 |
( V_187 -> V_204 << 2 ) |
( V_187 -> V_205 << 4 ) |
( V_187 -> V_206 << 6 ) ) ;
V_189 = F_3 ( V_4 , V_191 ) &
~ ( V_212 | V_192 ) ;
F_5 ( V_4 , V_191 ,
V_189 | V_223 ) ;
F_12 ( F_13
( V_187 -> V_224 ) ) ;
V_189 &= ~ V_216 ;
F_5 ( V_4 , V_191 , V_189 ) ;
F_5 ( V_4 , V_202 , 0 ) ;
F_25 ( V_4 , V_14 ,
V_218 ) ;
F_25 ( V_4 , V_21 ,
V_219 ) ;
F_25 ( V_4 , V_27 ,
V_220 ) ;
F_25 ( V_4 , V_29 ,
V_221 ) ;
F_25 ( V_4 , V_131 ,
V_201 ) ;
F_42 ( F_41 ( V_170 -> V_200 ) ,
V_170 -> V_200 ) ;
break;
}
V_2 -> V_35 . V_198 = V_185 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_199 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_197 ) ;
return 0 ;
}
static void F_45 ( struct V_8 * V_170 ,
struct V_225 * V_226 ,
T_1 V_227 )
{
struct V_4 * V_4 = V_170 -> V_2 . V_5 ;
T_1 V_3 ;
int V_228 ;
V_3 = F_3 ( V_4 , V_229 ) ;
if ( V_3 & V_227 )
V_228 = V_226 -> V_228 ;
else
V_228 = 0 ;
F_46 ( V_226 -> V_226 , V_228 , V_226 -> V_228 ) ;
}
static void F_47 ( struct V_32 * V_33 )
{
struct V_8 * V_170 =
F_11 ( V_33 , struct V_8 , V_230 . V_33 . V_33 ) ;
F_45 ( V_170 , & V_170 -> V_230 , V_231 ) ;
}
static void F_48 ( struct V_32 * V_33 )
{
struct V_8 * V_170 =
F_11 ( V_33 , struct V_8 , V_232 . V_33 . V_33 ) ;
F_45 ( V_170 , & V_170 -> V_232 , V_233 ) ;
}
static T_3 F_49 ( int V_234 , void * V_235 )
{
struct V_8 * V_170 = V_235 ;
struct V_4 * V_4 = V_170 -> V_2 . V_5 ;
struct V_225 * V_226 = NULL ;
switch ( V_234 - V_4 -> V_236 ) {
case V_237 :
#ifndef F_50
F_51 ( L_4 ) ;
#endif
V_226 = & V_170 -> V_230 ;
break;
case V_238 :
#ifndef F_50
F_51 ( L_5 ) ;
#endif
V_226 = & V_170 -> V_232 ;
break;
default:
F_16 () ;
}
if ( F_52 ( V_4 -> V_136 ) )
F_53 ( V_4 -> V_136 , 250 ) ;
F_18 ( & V_226 -> V_33 , 200 ) ;
return V_239 ;
}
int F_54 ( struct V_1 * V_2 , enum V_240 V_241 ,
struct V_242 * V_226 , int V_228 )
{
struct V_8 * V_170 = F_7 ( V_2 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_234 ;
int V_243 ;
switch ( V_241 ) {
case V_244 :
V_170 -> V_230 . V_226 = V_226 ;
V_170 -> V_230 . V_228 = V_228 ;
V_234 = V_237 ;
V_243 = V_245 ;
break;
case V_246 :
V_170 -> V_232 . V_226 = V_226 ;
V_170 -> V_232 . V_228 = V_228 ;
V_234 = V_238 ;
V_243 = V_247 ;
break;
default:
return - V_96 ;
}
if ( V_228 ) {
F_8 ( V_4 , V_131 , V_248 ) ;
F_8 ( V_4 , V_249 , V_243 ) ;
} else {
F_25 ( V_4 , V_249 , V_243 ) ;
}
F_49 ( V_234 + V_4 -> V_236 , V_170 ) ;
return 0 ;
}
static T_3 F_55 ( int V_234 , void * V_235 )
{
struct V_8 * V_170 = V_235 ;
struct V_4 * V_4 = V_170 -> V_2 . V_5 ;
T_1 V_3 ;
int V_228 = 0 ;
#ifndef F_50
F_51 ( L_6 ) ;
#endif
V_3 = F_3 ( V_4 , V_229 ) ;
if ( V_3 & V_250 )
V_228 |= V_170 -> V_251 . V_252 ;
if ( V_3 & V_253 )
V_228 |= V_170 -> V_251 . V_228 ;
F_46 ( V_170 -> V_251 . V_226 , V_228 ,
V_170 -> V_251 . V_228 | V_170 -> V_251 . V_252 ) ;
return V_239 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_242 * V_226 ,
int V_254 , int V_252 )
{
struct V_8 * V_170 = F_7 ( V_2 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
V_170 -> V_251 . V_226 = V_226 ;
V_170 -> V_251 . V_228 = V_254 ;
V_170 -> V_251 . V_252 = V_252 ;
if ( V_254 || V_252 ) {
F_8 ( V_4 , V_131 , V_248 ) ;
F_8 ( V_4 , V_191 ,
V_255 ) ;
} else {
F_25 ( V_4 , V_191 ,
V_255 ) ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_58 ( V_2 -> V_136 ) ;
struct V_8 * V_170 ;
struct V_9 * V_10 ;
struct V_9 * V_26 ;
int V_58 , V_37 ;
if ( V_4 -> V_2 . V_188 == NULL ) {
F_29 ( V_2 -> V_136 , L_7 ) ;
return - V_96 ;
}
V_170 = F_59 ( V_2 -> V_136 , sizeof( struct V_8 ) ,
V_256 ) ;
if ( V_170 == NULL )
return - V_257 ;
F_60 ( V_2 , V_170 ) ;
for ( V_37 = 0 ; V_37 < F_41 ( V_258 ) ; V_37 ++ )
V_170 -> V_200 [ V_37 ] . V_259 = V_258 [ V_37 ] ;
V_58 = F_61 ( V_4 -> V_136 , F_41 ( V_170 -> V_200 ) ,
V_170 -> V_200 ) ;
if ( V_58 != 0 )
return V_58 ;
V_4 -> V_2 . V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
F_25 ( V_4 , V_260 , V_261 ) ;
F_62 ( & V_2 -> V_35 . V_36 , F_10 ) ;
F_62 ( & V_170 -> V_230 . V_33 , F_47 ) ;
F_62 ( & V_170 -> V_232 . V_33 , F_48 ) ;
F_8 ( V_4 , V_260 , V_261 ) ;
F_4 ( V_2 , V_262 , 0xa7 ) ;
F_4 ( V_2 , 0xde , 0x13 ) ;
F_4 ( V_2 , V_262 , 0 ) ;
V_10 = & V_170 -> V_10 ;
V_26 = & V_170 -> V_26 ;
V_10 -> V_19 = ( F_3 ( V_4 , V_14 ) &
V_15 ) >> V_16 ;
V_10 -> V_24 = ( F_3 ( V_4 , V_21 ) &
V_22 ) >> V_23 ;
V_26 -> V_19 = ( F_3 ( V_4 , V_27 ) &
V_28 ) >> V_16 ;
V_26 -> V_24 = ( F_3 ( V_4 , V_29 ) &
V_30 ) >> V_23 ;
F_5 ( V_4 , V_14 , 0 ) ;
F_5 ( V_4 , V_21 , 0 ) ;
F_5 ( V_4 , V_27 , 0 ) ;
F_5 ( V_4 , V_29 , 0 ) ;
F_8 ( V_4 , V_14 ,
V_25 | V_263 ) ;
F_8 ( V_4 , V_27 ,
V_31 | V_264 ) ;
F_8 ( V_4 , V_21 ,
V_25 | V_265 ) ;
F_8 ( V_4 , V_29 ,
V_31 | V_266 ) ;
F_25 ( V_4 , V_99 , V_267 ) ;
F_25 ( V_4 , V_268 ,
V_269 | V_270 ) ;
F_25 ( V_4 , V_249 ,
V_245 | V_247 ) ;
F_63 ( V_4 , V_237 ,
F_49 , 0 , L_8 ,
V_170 ) ;
F_63 ( V_4 , V_238 ,
F_49 , 0 , L_9 ,
V_170 ) ;
F_63 ( V_4 , V_271 ,
F_55 , 0 , L_10 , V_170 ) ;
F_63 ( V_4 , V_272 ,
F_55 , 0 , L_11 , V_170 ) ;
F_39 ( V_2 , V_197 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_8 * V_170 = F_7 ( V_2 ) ;
struct V_4 * V_4 = F_58 ( V_2 -> V_136 ) ;
F_25 ( V_4 , V_249 ,
V_245 | V_247 ) ;
F_25 ( V_4 , V_131 , V_248 ) ;
F_65 ( V_4 , V_272 , V_170 ) ;
F_65 ( V_4 , V_271 , V_170 ) ;
F_65 ( V_4 , V_237 , V_170 ) ;
F_65 ( V_4 , V_238 , V_170 ) ;
V_170 -> V_230 . V_226 = NULL ;
V_170 -> V_232 . V_226 = NULL ;
V_170 -> V_251 . V_226 = NULL ;
F_66 ( & V_170 -> V_230 . V_33 ) ;
F_66 ( & V_170 -> V_232 . V_33 ) ;
F_67 ( & V_2 -> V_35 . V_36 ) ;
F_39 ( V_2 , V_199 ) ;
F_25 ( V_4 , V_260 , V_261 ) ;
F_68 ( F_41 ( V_170 -> V_200 ) , V_170 -> V_200 ) ;
return 0 ;
}
static int T_4 F_69 ( struct V_273 * V_274 )
{
return F_70 ( & V_274 -> V_136 , & V_275 ,
& V_276 , 1 ) ;
}
static int T_5 F_71 ( struct V_273 * V_274 )
{
F_72 ( & V_274 -> V_136 ) ;
return 0 ;
}
