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
static int F_24 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_35 ;
int V_58 ;
V_58 = F_25 ( V_35 ,
V_59 ,
F_26 ( V_59 ) ) ;
if ( V_58 != 0 ) {
F_27 ( V_2 -> V_60 , L_1 ) ;
return V_58 ;
}
V_58 = F_28 ( V_35 , V_61 , F_26 ( V_61 ) ) ;
if ( V_58 != 0 ) {
F_27 ( V_2 -> V_60 , L_2 ) ;
return V_58 ;
}
return 0 ;
}
static int F_29 ( struct V_62 * V_63 ,
int V_64 , unsigned int V_65 , int V_66 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_67 ;
switch ( V_64 ) {
case V_68 :
F_30 ( V_4 , V_69 ,
V_70 ) ;
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
F_8 ( V_4 , V_69 ,
V_70 ) ;
V_67 = F_2 ( V_2 , V_75 ) &
~ V_76 ;
F_4 ( V_2 , V_75 , V_67 | V_64 ) ;
break;
}
if ( V_66 == V_77 )
F_8 ( V_4 , V_78 ,
V_79 ) ;
else
F_30 ( V_4 , V_78 ,
V_79 ) ;
return 0 ;
}
static int F_31 ( struct V_62 * V_63 , int V_80 , int div )
{
struct V_1 * V_2 = V_63 -> V_2 ;
T_1 V_13 ;
switch ( V_80 ) {
case V_81 :
V_13 = F_2 ( V_2 , V_82 ) &
~ V_83 ;
F_4 ( V_2 , V_82 , V_13 | div ) ;
break;
case V_84 :
V_13 = F_2 ( V_2 , V_85 ) &
~ V_86 ;
F_4 ( V_2 , V_85 , V_13 | div ) ;
break;
case V_87 :
V_13 = F_2 ( V_2 , V_69 ) &
~ V_88 ;
F_4 ( V_2 , V_69 , V_13 | div ) ;
break;
case V_89 :
V_13 = F_2 ( V_2 , V_69 ) &
~ V_90 ;
F_4 ( V_2 , V_69 , V_13 | div ) ;
break;
case V_91 :
V_13 = F_2 ( V_2 , V_69 ) &
~ V_92 ;
F_4 ( V_2 , V_69 , V_13 | div ) ;
break;
case V_93 :
V_13 = F_2 ( V_2 , V_94 ) &
~ V_95 ;
F_4 ( V_2 , V_94 , V_13 | div ) ;
break;
case V_96 :
V_13 = F_2 ( V_2 , V_97 ) &
~ V_98 ;
F_4 ( V_2 , V_97 , V_13 | div ) ;
break;
default:
return - V_99 ;
}
return 0 ;
}
static int F_32 ( struct V_62 * V_63 , unsigned int V_100 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
T_1 V_101 = F_2 ( V_2 , V_102 ) &
~ ( V_103 | V_104 | V_105 ) ;
T_1 V_106 = F_2 ( V_2 , V_107 ) &
~ V_108 ;
T_1 V_109 = F_2 ( V_2 , V_94 ) &
~ V_110 ;
T_1 V_111 = F_2 ( V_2 , V_97 ) &
~ V_112 ;
switch ( V_100 & V_113 ) {
case V_114 :
V_106 |= V_108 ;
V_109 |= V_110 ;
V_111 |= V_112 ;
break;
case V_115 :
break;
default:
return - V_99 ;
}
switch ( V_100 & V_116 ) {
case V_117 :
V_101 |= 0x2 << 8 ;
break;
case V_118 :
break;
case V_119 :
V_101 |= 0x1 << 8 ;
break;
case V_120 :
V_101 |= 0x3 << 8 ;
break;
case V_121 :
V_101 |= 0x3 << 8 | V_104 ;
break;
default:
return - V_99 ;
}
switch ( V_100 & V_122 ) {
case V_123 :
break;
case V_124 :
V_101 |= V_104 | V_103 ;
break;
case V_125 :
V_101 |= V_103 ;
break;
case V_126 :
V_101 |= V_104 ;
break;
default:
return - V_99 ;
}
F_4 ( V_2 , V_102 , V_101 ) ;
F_4 ( V_2 , V_107 , V_106 ) ;
F_4 ( V_2 , V_94 , V_109 ) ;
F_4 ( V_2 , V_97 , V_111 ) ;
return 0 ;
}
static int F_33 ( struct V_127 * V_128 ,
int V_129 , struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
int V_106 = F_1 ( V_2 , V_107 ) &
V_108 ;
int V_130 = 0 ;
if ( ! V_106 || V_129 != V_131 )
return 0 ;
if ( V_128 -> V_132 == V_133 ) {
V_130 = F_1 ( V_2 , V_134 ) &
( V_135 | V_136 ) ;
} else {
V_130 = F_1 ( V_2 , V_134 ) &
( V_137 | V_138 ) ;
}
if ( ! V_130 ) {
F_27 ( V_2 -> V_60 ,
L_3 ,
V_139 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_34 ( struct V_127 * V_128 ,
struct V_140 * V_141 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
T_1 V_101 = F_2 ( V_2 , V_102 ) &
~ V_142 ;
switch ( F_35 ( V_141 ) ) {
case V_143 :
break;
case V_144 :
V_101 |= 0x1 << 10 ;
break;
case V_145 :
V_101 |= 0x2 << 10 ;
break;
case V_146 :
V_101 |= 0x3 << 10 ;
break;
}
F_4 ( V_2 , V_102 , V_101 ) ;
if ( V_128 -> V_132 == V_147 ) {
if ( F_36 ( V_141 ) < 24000 )
F_8 ( V_4 , V_148 ,
V_149 ) ;
else
F_30 ( V_4 , V_148 ,
V_149 ) ;
}
return 0 ;
}
static int F_37 ( struct V_62 * V_150 , int V_151 )
{
struct V_1 * V_2 = V_150 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
if ( V_151 )
F_8 ( V_4 , V_152 , V_153 ) ;
else
F_30 ( V_4 , V_152 , V_153 ) ;
return 0 ;
}
static inline int F_38 ( struct V_154 * V_155 , unsigned int V_156 ,
unsigned int V_157 )
{
T_2 V_158 ;
unsigned int V_159 , V_160 , V_161 , V_162 ;
if ( V_157 >= 2815250 && V_157 <= 3125000 )
V_155 -> div = 0x4 ;
else if ( V_157 >= 5625000 && V_157 <= 6250000 )
V_155 -> div = 0x3 ;
else if ( V_157 >= 11250000 && V_157 <= 12500000 )
V_155 -> div = 0x2 ;
else if ( V_157 >= 22500000 && V_157 <= 25000000 )
V_155 -> div = 0x1 ;
else {
F_39 ( V_163 L_4 , V_157 ) ;
return - V_99 ;
}
if ( V_156 > 48000 )
V_155 -> V_164 = 1 ;
else
V_155 -> V_164 = 8 ;
V_159 = V_157 * ( 1 << ( V_155 -> div + 1 ) ) ;
V_160 = V_156 * V_155 -> V_164 ;
V_155 -> V_165 = V_159 / V_160 ;
V_162 = V_159 % V_160 ;
if ( V_162 ) {
V_158 = V_166 * ( long long ) V_162 ;
F_40 ( V_158 , V_160 ) ;
V_161 = V_158 & 0xFFFFFFFF ;
if ( ( V_161 % 10 ) >= 5 )
V_161 += 5 ;
V_161 /= 10 ;
V_155 -> V_167 = V_161 ;
} else
V_155 -> V_167 = 0 ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 ,
int V_168 , int V_169 , unsigned int V_170 ,
unsigned int V_171 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
struct V_8 * V_172 = F_7 ( V_2 ) ;
struct V_154 V_155 ;
int V_58 = 0 ;
T_1 V_173 , V_67 ;
if ( V_170 == V_172 -> V_174 && V_171 == V_172 -> V_175 )
return 0 ;
F_30 ( V_4 , V_134 ,
V_176 | V_177 ) ;
if ( V_171 == 0 || V_170 == 0 )
return V_58 ;
V_58 = F_38 ( & V_155 , V_170 , V_171 ) ;
if ( V_58 < 0 )
return V_58 ;
F_42 ( V_4 -> V_60 ,
L_5 ,
V_170 , V_171 , V_155 . V_165 , V_155 . V_167 , V_155 . div ,
V_155 . V_164 ) ;
V_173 = F_2 ( V_2 , V_178 ) &
~ ( V_179 | V_180 | 0xc000 ) ;
F_4 ( V_2 , V_178 ,
V_173 | ( V_155 . div << 8 ) | 0x50 ) ;
F_4 ( V_2 , V_181 ,
( V_155 . V_164 << 11 ) | ( V_155 .
V_165 & V_182 ) ) ;
F_4 ( V_2 , V_183 , V_155 . V_167 ) ;
V_67 = F_2 ( V_2 , V_75 ) &
~ ( V_184 | V_185 ) ;
F_4 ( V_2 , V_75 ,
V_67 | ( V_155 . V_167 ? V_184 : 0 ) |
( V_155 . V_164 == 8 ? V_185 : 0 ) ) ;
F_8 ( V_4 , V_134 , V_177 ) ;
F_8 ( V_4 , V_134 , V_176 ) ;
V_172 -> V_175 = V_171 ;
V_172 -> V_174 = V_170 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
enum V_186 V_187 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
struct V_8 * V_172 = F_7 ( V_2 ) ;
struct V_188 * V_189 =
V_4 -> V_2 . V_190 ;
T_1 V_191 ;
int V_58 ;
switch ( V_187 ) {
case V_192 :
V_191 = F_3 ( V_4 , V_193 ) &
~ ( V_194 | V_195 ) ;
F_5 ( V_4 , V_193 ,
V_191 | V_196 |
V_189 -> V_197 << 14 ) ;
break;
case V_198 :
V_191 = F_3 ( V_4 , V_193 ) ;
V_191 &= ~ V_194 ;
F_5 ( V_4 , V_193 ,
V_191 | V_196 ) ;
break;
case V_199 :
if ( V_2 -> V_35 . V_200 == V_201 ) {
V_58 = F_44 ( F_26 ( V_172 -> V_202 ) ,
V_172 -> V_202 ) ;
if ( V_58 != 0 )
return V_58 ;
F_8 ( V_4 , V_134 ,
V_203 ) ;
F_8 ( V_4 , V_152 ,
V_153 ) ;
F_5 ( V_4 , V_204 ,
V_189 -> V_205 |
( V_189 -> V_206 << 2 ) |
( V_189 -> V_207 << 4 ) |
( V_189 -> V_208 << 6 ) ) ;
F_12 ( F_13
( V_189 ->
V_209 ) ) ;
F_5 ( V_4 , V_204 ,
( V_189 -> V_210 << 8 ) ) ;
F_5 ( V_4 , V_193 ,
( V_189 ->
V_211 << 14 ) |
V_212 | V_213 |
V_214 ) ;
F_12 ( F_13
( V_189 ->
V_215 ) ) ;
V_191 = F_3 ( V_4 , V_193 ) &
~ ( V_194 | V_195 ) ;
V_191 |= V_216 |
( V_189 -> V_217 << 14 ) ;
F_5 ( V_4 , V_193 ,
V_191 ) ;
V_191 |= V_218 ;
F_5 ( V_4 , V_193 , V_191 ) ;
F_5 ( V_4 , V_204 , 0 ) ;
} else {
V_191 = F_3 ( V_4 , V_193 ) &
~ ( V_194 | V_195 ) ;
F_5 ( V_4 , V_193 ,
V_191 | V_216 |
( V_189 ->
V_217 << 14 ) ) ;
}
break;
case V_201 :
F_8 ( V_4 , V_152 , V_153 ) ;
F_8 ( V_4 , V_219 ,
V_220 | V_221 |
V_222 | V_223 ) ;
F_5 ( V_4 , V_204 ,
( V_189 -> V_210 << 8 ) ) ;
V_191 = F_3 ( V_4 , V_193 ) &
~ V_213 ;
F_5 ( V_4 , V_193 , V_191 ) ;
F_12 ( F_13
( V_189 ->
V_224 ) ) ;
F_5 ( V_4 , V_204 ,
( V_189 -> V_210 << 8 ) |
V_189 -> V_205 |
( V_189 -> V_206 << 2 ) |
( V_189 -> V_207 << 4 ) |
( V_189 -> V_208 << 6 ) ) ;
V_191 = F_3 ( V_4 , V_193 ) &
~ ( V_214 | V_194 ) ;
F_5 ( V_4 , V_193 ,
V_191 | V_225 ) ;
F_12 ( F_13
( V_189 -> V_226 ) ) ;
V_191 &= ~ V_218 ;
F_5 ( V_4 , V_193 , V_191 ) ;
F_5 ( V_4 , V_204 , 0 ) ;
F_30 ( V_4 , V_14 ,
V_220 ) ;
F_30 ( V_4 , V_21 ,
V_221 ) ;
F_30 ( V_4 , V_27 ,
V_222 ) ;
F_30 ( V_4 , V_29 ,
V_223 ) ;
F_30 ( V_4 , V_134 ,
V_203 ) ;
F_45 ( F_26 ( V_172 -> V_202 ) ,
V_172 -> V_202 ) ;
break;
}
V_2 -> V_35 . V_200 = V_187 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , T_3 V_227 )
{
F_43 ( V_2 , V_201 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
F_43 ( V_2 , V_199 ) ;
return 0 ;
}
static void F_48 ( struct V_8 * V_172 ,
struct V_228 * V_229 ,
T_1 V_230 )
{
struct V_4 * V_4 = V_172 -> V_2 . V_5 ;
T_1 V_3 ;
int V_231 ;
V_3 = F_3 ( V_4 , V_232 ) ;
if ( V_3 & V_230 )
V_231 = V_229 -> V_231 ;
else
V_231 = 0 ;
F_49 ( V_229 -> V_229 , V_231 , V_229 -> V_231 ) ;
}
static void F_50 ( struct V_32 * V_33 )
{
struct V_8 * V_172 =
F_11 ( V_33 , struct V_8 , V_233 . V_33 . V_33 ) ;
F_48 ( V_172 , & V_172 -> V_233 , V_234 ) ;
}
static void F_51 ( struct V_32 * V_33 )
{
struct V_8 * V_172 =
F_11 ( V_33 , struct V_8 , V_235 . V_33 . V_33 ) ;
F_48 ( V_172 , & V_172 -> V_235 , V_236 ) ;
}
static T_4 F_52 ( int V_237 , void * V_238 )
{
struct V_8 * V_172 = V_238 ;
struct V_4 * V_4 = V_172 -> V_2 . V_5 ;
struct V_228 * V_229 = NULL ;
switch ( V_237 - V_4 -> V_239 ) {
case V_240 :
#ifndef F_53
F_54 ( L_6 ) ;
#endif
V_229 = & V_172 -> V_233 ;
break;
case V_241 :
#ifndef F_53
F_54 ( L_7 ) ;
#endif
V_229 = & V_172 -> V_235 ;
break;
default:
F_16 () ;
}
if ( F_55 ( V_4 -> V_60 ) )
F_56 ( V_4 -> V_60 , 250 ) ;
F_18 ( & V_229 -> V_33 , 200 ) ;
return V_242 ;
}
int F_57 ( struct V_1 * V_2 , enum V_243 V_244 ,
struct V_245 * V_229 , int V_231 )
{
struct V_8 * V_172 = F_7 ( V_2 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
int V_237 ;
int V_246 ;
switch ( V_244 ) {
case V_247 :
V_172 -> V_233 . V_229 = V_229 ;
V_172 -> V_233 . V_231 = V_231 ;
V_237 = V_240 ;
V_246 = V_248 ;
break;
case V_249 :
V_172 -> V_235 . V_229 = V_229 ;
V_172 -> V_235 . V_231 = V_231 ;
V_237 = V_241 ;
V_246 = V_250 ;
break;
default:
return - V_99 ;
}
if ( V_231 ) {
F_8 ( V_4 , V_134 , V_251 ) ;
F_8 ( V_4 , V_252 , V_246 ) ;
} else {
F_30 ( V_4 , V_252 , V_246 ) ;
}
F_52 ( V_237 + V_4 -> V_239 , V_172 ) ;
return 0 ;
}
static T_4 F_58 ( int V_237 , void * V_238 )
{
struct V_8 * V_172 = V_238 ;
struct V_4 * V_4 = V_172 -> V_2 . V_5 ;
T_1 V_3 ;
int V_231 = 0 ;
#ifndef F_53
F_54 ( L_8 ) ;
#endif
V_3 = F_3 ( V_4 , V_232 ) ;
if ( V_3 & V_253 )
V_231 |= V_172 -> V_254 . V_255 ;
if ( V_3 & V_256 )
V_231 |= V_172 -> V_254 . V_231 ;
F_49 ( V_172 -> V_254 . V_229 , V_231 ,
V_172 -> V_254 . V_231 | V_172 -> V_254 . V_255 ) ;
return V_242 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_245 * V_229 ,
int V_257 , int V_255 )
{
struct V_8 * V_172 = F_7 ( V_2 ) ;
struct V_4 * V_4 = V_2 -> V_5 ;
V_172 -> V_254 . V_229 = V_229 ;
V_172 -> V_254 . V_231 = V_257 ;
V_172 -> V_254 . V_255 = V_255 ;
if ( V_257 || V_255 ) {
F_8 ( V_4 , V_134 , V_251 ) ;
F_8 ( V_4 , V_193 ,
V_258 ) ;
} else {
F_30 ( V_4 , V_193 ,
V_258 ) ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_61 ( V_2 -> V_60 ) ;
struct V_8 * V_172 ;
struct V_9 * V_10 ;
struct V_9 * V_26 ;
int V_58 , V_37 ;
if ( V_4 -> V_2 . V_190 == NULL ) {
F_27 ( V_2 -> V_60 , L_9 ) ;
return - V_99 ;
}
V_172 = F_62 ( sizeof( struct V_8 ) , V_259 ) ;
if ( V_172 == NULL )
return - V_260 ;
F_63 ( V_2 , V_172 ) ;
for ( V_37 = 0 ; V_37 < F_26 ( V_261 ) ; V_37 ++ )
V_172 -> V_202 [ V_37 ] . V_262 = V_261 [ V_37 ] ;
V_58 = F_64 ( V_4 -> V_60 , F_26 ( V_172 -> V_202 ) ,
V_172 -> V_202 ) ;
if ( V_58 != 0 )
goto V_263;
V_4 -> V_2 . V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
F_30 ( V_4 , V_264 , V_265 ) ;
F_65 ( & V_2 -> V_35 . V_36 , F_10 ) ;
F_65 ( & V_172 -> V_233 . V_33 , F_50 ) ;
F_65 ( & V_172 -> V_235 . V_33 , F_51 ) ;
F_8 ( V_4 , V_264 , V_265 ) ;
F_4 ( V_2 , V_266 , 0xa7 ) ;
F_4 ( V_2 , 0xde , 0x13 ) ;
F_4 ( V_2 , V_266 , 0 ) ;
V_10 = & V_172 -> V_10 ;
V_26 = & V_172 -> V_26 ;
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
V_25 | V_267 ) ;
F_8 ( V_4 , V_27 ,
V_31 | V_268 ) ;
F_8 ( V_4 , V_21 ,
V_25 | V_269 ) ;
F_8 ( V_4 , V_29 ,
V_31 | V_270 ) ;
F_30 ( V_4 , V_102 , V_271 ) ;
F_30 ( V_4 , V_272 ,
V_273 | V_274 ) ;
F_30 ( V_4 , V_252 ,
V_248 | V_250 ) ;
F_66 ( V_4 , V_240 ,
F_52 , 0 , L_10 ,
V_172 ) ;
F_66 ( V_4 , V_241 ,
F_52 , 0 , L_11 ,
V_172 ) ;
F_66 ( V_4 , V_275 ,
F_58 , 0 , L_12 , V_172 ) ;
F_66 ( V_4 , V_276 ,
F_58 , 0 , L_13 , V_172 ) ;
F_67 ( V_2 , V_277 ,
F_26 ( V_277 ) ) ;
F_24 ( V_2 ) ;
F_43 ( V_2 , V_199 ) ;
return 0 ;
V_263:
F_68 ( V_172 ) ;
return V_58 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_172 = F_7 ( V_2 ) ;
struct V_4 * V_4 = F_61 ( V_2 -> V_60 ) ;
F_30 ( V_4 , V_252 ,
V_248 | V_250 ) ;
F_30 ( V_4 , V_134 , V_251 ) ;
F_70 ( V_4 , V_276 , V_172 ) ;
F_70 ( V_4 , V_275 , V_172 ) ;
F_70 ( V_4 , V_240 , V_172 ) ;
F_70 ( V_4 , V_241 , V_172 ) ;
V_172 -> V_233 . V_229 = NULL ;
V_172 -> V_235 . V_229 = NULL ;
V_172 -> V_254 . V_229 = NULL ;
F_71 ( & V_172 -> V_233 . V_33 ) ;
F_71 ( & V_172 -> V_235 . V_33 ) ;
F_72 ( & V_2 -> V_35 . V_36 ) ;
F_43 ( V_2 , V_201 ) ;
F_30 ( V_4 , V_264 , V_265 ) ;
F_73 ( F_26 ( V_172 -> V_202 ) , V_172 -> V_202 ) ;
F_68 ( V_172 ) ;
return 0 ;
}
static int T_5 F_74 ( struct V_278 * V_279 )
{
return F_75 ( & V_279 -> V_60 , & V_280 ,
& V_281 , 1 ) ;
}
static int T_6 F_76 ( struct V_278 * V_279 )
{
F_77 ( & V_279 -> V_60 ) ;
return 0 ;
}
static T_7 int F_78 ( void )
{
return F_79 ( & V_282 ) ;
}
static T_8 void F_80 ( void )
{
F_81 ( & V_282 ) ;
}
