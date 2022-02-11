static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = & V_3 -> V_5 ;
struct V_6 * V_6 = V_3 -> V_6 ;
int V_7 = 0 , V_8 = 0 ;
T_1 V_9 , V_10 ;
V_9 = F_3 ( V_6 , V_11 ) ;
V_10 = ( V_9 & V_12 ) >> V_13 ;
if ( V_5 -> V_14 == V_15 ) {
if ( V_10 < V_5 -> V_16 ) {
V_10 ++ ;
V_9 &= ~ V_12 ;
F_4 ( V_6 , V_11 ,
V_9 | ( V_10 << V_13 ) ) ;
} else
V_7 = 1 ;
} else if ( V_5 -> V_14 == V_17 ) {
if ( V_10 > 0 ) {
V_10 -- ;
V_9 &= ~ V_12 ;
F_4 ( V_6 , V_11 ,
V_9 | ( V_10 << V_13 ) ) ;
} else
V_7 = 1 ;
} else
return 1 ;
V_9 = F_3 ( V_6 , V_18 ) ;
V_10 = ( V_9 & V_19 ) >> V_20 ;
if ( V_5 -> V_14 == V_15 ) {
if ( V_10 < V_5 -> V_21 ) {
V_10 ++ ;
V_9 &= ~ V_19 ;
F_4 ( V_6 , V_18 ,
V_9 | ( V_10 << V_20 ) ) ;
} else
V_8 = 1 ;
} else if ( V_5 -> V_14 == V_17 ) {
if ( V_10 > 0 ) {
V_10 -- ;
V_9 &= ~ V_19 ;
F_4 ( V_6 , V_18 ,
V_9 | ( V_10 << V_20 ) ) ;
} else
V_8 = 1 ;
}
if ( ! V_7 || ! V_8 )
F_5 ( V_6 , V_11 , V_22 ) ;
return V_7 & V_8 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_23 = & V_3 -> V_23 ;
struct V_6 * V_6 = V_3 -> V_6 ;
int V_7 = 0 , V_8 = 0 ;
T_1 V_9 , V_10 ;
V_9 = F_3 ( V_6 , V_24 ) ;
V_10 = ( V_9 & V_25 ) >> V_13 ;
if ( V_23 -> V_14 == V_15 ) {
if ( V_10 < V_23 -> V_16 ) {
V_10 ++ ;
V_9 &= ~ V_25 ;
F_4 ( V_6 , V_24 ,
V_9 | ( V_10 << V_13 ) ) ;
} else
V_7 = 1 ;
} else if ( V_23 -> V_14 == V_17 ) {
if ( V_10 > 0 ) {
V_10 -- ;
V_9 &= ~ V_25 ;
F_4 ( V_6 , V_24 ,
V_9 | ( V_10 << V_13 ) ) ;
} else
V_7 = 1 ;
} else
return 1 ;
V_9 = F_3 ( V_6 , V_26 ) ;
V_10 = ( V_9 & V_27 ) >> V_20 ;
if ( V_23 -> V_14 == V_15 ) {
if ( V_10 < V_23 -> V_21 ) {
V_10 ++ ;
V_9 &= ~ V_27 ;
F_4 ( V_6 , V_26 ,
V_9 | ( V_10 << V_20 ) ) ;
} else
V_8 = 1 ;
} else if ( V_23 -> V_14 == V_17 ) {
if ( V_10 > 0 ) {
V_10 -- ;
V_9 &= ~ V_27 ;
F_4 ( V_6 , V_26 ,
V_9 | ( V_10 << V_20 ) ) ;
} else
V_8 = 1 ;
}
if ( ! V_7 || ! V_8 )
F_5 ( V_6 , V_24 , V_28 ) ;
return V_7 & V_8 ;
}
static void F_7 ( struct V_29 * V_30 )
{
struct V_31 * V_32 =
F_8 ( V_30 , struct V_31 , V_33 . V_30 ) ;
struct V_1 * V_2 = V_32 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_5 = & V_3 -> V_5 ,
* V_23 = & V_3 -> V_23 ;
int V_34 , V_35 , V_36 ;
if ( V_5 -> V_14 == V_37 && V_23 -> V_14 == V_37 )
return;
for ( V_34 = 0 ; V_34 <= 63 ; V_34 ++ ) {
V_35 = 1 , V_36 = 1 ;
if ( V_5 -> V_14 != V_37 )
V_35 = F_1 ( V_2 ) ;
if ( V_23 -> V_14 != V_37 )
V_36 = F_6 ( V_2 ) ;
if ( V_35 && V_36 )
break;
if ( V_5 -> V_14 == V_15 ||
V_23 -> V_14 == V_15 ) {
if ( V_34 >= V_38 )
F_9 ( F_10
( 2 ) ) ;
else
F_9 ( F_10
( 1 ) ) ;
} else
F_11 ( 50 ) ;
}
V_5 -> V_14 = V_37 ;
V_23 -> V_14 = V_37 ;
}
static int F_12 ( struct V_39 * V_40 ,
struct V_41 * V_42 , int V_43 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_4 * V_44 ;
switch ( V_40 -> V_45 ) {
case 0 :
case 1 :
V_44 = & V_3 -> V_5 ;
break;
case 2 :
case 3 :
V_44 = & V_3 -> V_23 ;
break;
default:
F_13 ( 1 , L_1 , V_40 -> V_45 ) ;
return - 1 ;
}
switch ( V_43 ) {
case V_46 :
V_44 -> V_14 = V_15 ;
V_44 -> V_47 = 1 ;
F_14 ( & V_2 -> V_32 . V_33 ,
F_10 ( 1 ) ) ;
break;
case V_48 :
V_44 -> V_14 = V_17 ;
V_44 -> V_47 = 0 ;
F_14 ( & V_2 -> V_32 . V_33 ,
F_10 ( 1 ) ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_41 * V_42 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
struct V_3 * V_51 = F_2 ( V_2 ) ;
struct V_4 * V_44 = NULL ;
struct V_52 * V_53 =
(struct V_52 * ) V_42 -> V_54 ;
int V_55 ;
unsigned int V_9 = V_53 -> V_9 ;
T_1 V_10 ;
switch ( V_9 ) {
case V_11 :
V_44 = & V_51 -> V_5 ;
break;
case V_24 :
V_44 = & V_51 -> V_23 ;
break;
default:
break;
}
if ( V_44 ) {
V_44 -> V_16 = V_50 -> V_56 . integer . V_56 [ 0 ] ;
V_44 -> V_21 = V_50 -> V_56 . integer . V_56 [ 1 ] ;
if ( ! V_44 -> V_47 )
return 1 ;
}
V_55 = F_17 ( V_42 , V_50 ) ;
if ( V_55 < 0 )
return V_55 ;
V_10 = F_18 ( V_2 , V_9 ) ;
F_19 ( V_2 , V_9 , V_10 | V_22 ) ;
return 1 ;
}
static int F_20 ( struct V_41 * V_42 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_16 ( V_42 ) ;
struct V_3 * V_51 = F_2 ( V_2 ) ;
struct V_4 * V_5 = & V_51 -> V_5 ;
struct V_4 * V_23 = & V_51 -> V_23 ;
struct V_52 * V_53 =
(struct V_52 * ) V_42 -> V_54 ;
unsigned int V_9 = V_53 -> V_9 ;
switch ( V_9 ) {
case V_11 :
V_50 -> V_56 . integer . V_56 [ 0 ] = V_5 -> V_16 ;
V_50 -> V_56 . integer . V_56 [ 1 ] = V_5 -> V_21 ;
return 0 ;
case V_24 :
V_50 -> V_56 . integer . V_56 [ 0 ] = V_23 -> V_16 ;
V_50 -> V_56 . integer . V_56 [ 1 ] = V_23 -> V_21 ;
return 0 ;
default:
break;
}
return F_21 ( V_42 , V_50 ) ;
}
static int F_22 ( struct V_57 * V_58 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
T_1 V_62 ;
switch ( V_59 ) {
case V_63 :
F_23 ( V_6 , V_64 ,
V_65 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
F_5 ( V_6 , V_64 ,
V_65 ) ;
V_62 = F_18 ( V_2 , V_70 ) &
~ V_71 ;
F_19 ( V_2 , V_70 , V_62 | V_59 ) ;
break;
}
if ( V_61 == V_72 )
F_5 ( V_6 , V_73 ,
V_74 ) ;
else
F_23 ( V_6 , V_73 ,
V_74 ) ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 , int V_75 , int div )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_10 ;
switch ( V_75 ) {
case V_76 :
V_10 = F_18 ( V_2 , V_77 ) &
~ V_78 ;
F_19 ( V_2 , V_77 , V_10 | div ) ;
break;
case V_79 :
V_10 = F_18 ( V_2 , V_80 ) &
~ V_81 ;
F_19 ( V_2 , V_80 , V_10 | div ) ;
break;
case V_82 :
V_10 = F_18 ( V_2 , V_64 ) &
~ V_83 ;
F_19 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_84 :
V_10 = F_18 ( V_2 , V_64 ) &
~ V_85 ;
F_19 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_86 :
V_10 = F_18 ( V_2 , V_64 ) &
~ V_87 ;
F_19 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_88 :
V_10 = F_18 ( V_2 , V_89 ) &
~ V_90 ;
F_19 ( V_2 , V_89 , V_10 | div ) ;
break;
case V_91 :
V_10 = F_18 ( V_2 , V_92 ) &
~ V_93 ;
F_19 ( V_2 , V_92 , V_10 | div ) ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_25 ( struct V_57 * V_58 , unsigned int V_95 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_96 = F_18 ( V_2 , V_97 ) &
~ ( V_98 | V_99 | V_100 ) ;
T_1 V_101 = F_18 ( V_2 , V_102 ) &
~ V_103 ;
T_1 V_104 = F_18 ( V_2 , V_89 ) &
~ V_105 ;
T_1 V_106 = F_18 ( V_2 , V_92 ) &
~ V_107 ;
switch ( V_95 & V_108 ) {
case V_109 :
V_101 |= V_103 ;
V_104 |= V_105 ;
V_106 |= V_107 ;
break;
case V_110 :
break;
default:
return - V_94 ;
}
switch ( V_95 & V_111 ) {
case V_112 :
V_96 |= 0x2 << 8 ;
break;
case V_113 :
break;
case V_114 :
V_96 |= 0x1 << 8 ;
break;
case V_115 :
V_96 |= 0x3 << 8 ;
break;
case V_116 :
V_96 |= 0x3 << 8 | V_99 ;
break;
default:
return - V_94 ;
}
switch ( V_95 & V_117 ) {
case V_118 :
break;
case V_119 :
V_96 |= V_99 | V_98 ;
break;
case V_120 :
V_96 |= V_98 ;
break;
case V_121 :
V_96 |= V_99 ;
break;
default:
return - V_94 ;
}
F_19 ( V_2 , V_97 , V_96 ) ;
F_19 ( V_2 , V_102 , V_101 ) ;
F_19 ( V_2 , V_89 , V_104 ) ;
F_19 ( V_2 , V_92 , V_106 ) ;
return 0 ;
}
static int F_26 ( struct V_122 * V_123 ,
struct V_124 * V_125 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
T_1 V_96 = F_18 ( V_2 , V_97 ) &
~ V_126 ;
switch ( F_27 ( V_125 ) ) {
case V_127 :
break;
case V_128 :
V_96 |= 0x1 << 10 ;
break;
case V_129 :
V_96 |= 0x2 << 10 ;
break;
case V_130 :
V_96 |= 0x3 << 10 ;
break;
}
F_19 ( V_2 , V_97 , V_96 ) ;
if ( V_123 -> V_131 == V_132 ) {
if ( F_28 ( V_125 ) < 24000 )
F_5 ( V_6 , V_133 ,
V_134 ) ;
else
F_23 ( V_6 , V_133 ,
V_134 ) ;
}
return 0 ;
}
static int F_29 ( struct V_57 * V_135 , int V_136 )
{
struct V_1 * V_2 = V_135 -> V_2 ;
unsigned int V_10 ;
if ( V_136 )
V_10 = V_137 ;
else
V_10 = 0 ;
F_30 ( V_2 , V_138 , V_137 , V_10 ) ;
return 0 ;
}
static inline int F_31 ( struct V_139 * V_140 , unsigned int V_141 ,
unsigned int V_142 )
{
T_2 V_143 ;
unsigned int V_144 , V_145 , V_146 , V_147 ;
if ( V_142 >= 2815250 && V_142 <= 3125000 )
V_140 -> div = 0x4 ;
else if ( V_142 >= 5625000 && V_142 <= 6250000 )
V_140 -> div = 0x3 ;
else if ( V_142 >= 11250000 && V_142 <= 12500000 )
V_140 -> div = 0x2 ;
else if ( V_142 >= 22500000 && V_142 <= 25000000 )
V_140 -> div = 0x1 ;
else {
F_32 ( V_148 L_2 , V_142 ) ;
return - V_94 ;
}
if ( V_141 > 48000 )
V_140 -> V_149 = 1 ;
else
V_140 -> V_149 = 8 ;
V_144 = V_142 * ( 1 << ( V_140 -> div + 1 ) ) ;
V_145 = V_141 * V_140 -> V_149 ;
V_140 -> V_150 = V_144 / V_145 ;
V_147 = V_144 % V_145 ;
if ( V_147 ) {
V_143 = V_151 * ( long long ) V_147 ;
F_33 ( V_143 , V_145 ) ;
V_146 = V_143 & 0xFFFFFFFF ;
if ( ( V_146 % 10 ) >= 5 )
V_146 += 5 ;
V_146 /= 10 ;
V_140 -> V_152 = V_146 ;
} else
V_140 -> V_152 = 0 ;
return 0 ;
}
static int F_34 ( struct V_57 * V_58 ,
int V_153 , int V_154 , unsigned int V_155 ,
unsigned int V_156 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_157 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_157 -> V_6 ;
struct V_139 V_140 ;
int V_55 = 0 ;
T_1 V_158 , V_62 ;
if ( V_155 == V_157 -> V_159 && V_156 == V_157 -> V_160 )
return 0 ;
F_23 ( V_6 , V_161 ,
V_162 | V_163 ) ;
if ( V_156 == 0 || V_155 == 0 )
return V_55 ;
V_55 = F_31 ( & V_140 , V_155 , V_156 ) ;
if ( V_55 < 0 )
return V_55 ;
F_35 ( V_6 -> V_164 ,
L_3 ,
V_155 , V_156 , V_140 . V_150 , V_140 . V_152 , V_140 . div ,
V_140 . V_149 ) ;
V_158 = F_18 ( V_2 , V_165 ) &
~ ( V_166 | V_167 | 0xc000 ) ;
F_19 ( V_2 , V_165 ,
V_158 | ( V_140 . div << 8 ) | 0x50 ) ;
F_19 ( V_2 , V_168 ,
( V_140 . V_149 << 11 ) | ( V_140 .
V_150 & V_169 ) ) ;
F_19 ( V_2 , V_170 , V_140 . V_152 ) ;
V_62 = F_18 ( V_2 , V_70 ) &
~ ( V_171 | V_172 ) ;
F_19 ( V_2 , V_70 ,
V_62 | ( V_140 . V_152 ? V_171 : 0 ) |
( V_140 . V_149 == 8 ? V_172 : 0 ) ) ;
F_5 ( V_6 , V_161 , V_163 ) ;
F_5 ( V_6 , V_161 , V_162 ) ;
V_157 -> V_160 = V_156 ;
V_157 -> V_159 = V_155 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_173 V_174 )
{
struct V_3 * V_157 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_157 -> V_6 ;
struct V_175 * V_176 =
V_6 -> V_2 . V_177 ;
T_1 V_178 ;
int V_55 ;
switch ( V_174 ) {
case V_179 :
V_178 = F_3 ( V_6 , V_180 ) &
~ ( V_181 | V_182 ) ;
F_4 ( V_6 , V_180 ,
V_178 | V_183 |
V_176 -> V_184 << 14 ) ;
break;
case V_185 :
V_178 = F_3 ( V_6 , V_180 ) ;
V_178 &= ~ V_181 ;
F_4 ( V_6 , V_180 ,
V_178 | V_183 ) ;
break;
case V_186 :
if ( V_2 -> V_32 . V_187 == V_188 ) {
V_55 = F_37 ( F_38 ( V_157 -> V_189 ) ,
V_157 -> V_189 ) ;
if ( V_55 != 0 )
return V_55 ;
F_5 ( V_6 , V_161 ,
V_190 ) ;
F_5 ( V_6 , V_138 ,
V_137 ) ;
F_4 ( V_6 , V_191 ,
V_176 -> V_192 |
( V_176 -> V_193 << 2 ) |
( V_176 -> V_194 << 4 ) |
( V_176 -> V_195 << 6 ) ) ;
F_9 ( F_10
( V_176 ->
V_196 ) ) ;
F_4 ( V_6 , V_191 ,
( V_176 -> V_197 << 8 ) ) ;
F_4 ( V_6 , V_180 ,
( V_176 ->
V_198 << 14 ) |
V_199 | V_200 |
V_201 ) ;
F_9 ( F_10
( V_176 ->
V_202 ) ) ;
V_178 = F_3 ( V_6 , V_180 ) &
~ ( V_181 | V_182 ) ;
V_178 |= V_203 |
( V_176 -> V_204 << 14 ) ;
F_4 ( V_6 , V_180 ,
V_178 ) ;
V_178 |= V_205 ;
F_4 ( V_6 , V_180 , V_178 ) ;
F_4 ( V_6 , V_191 , 0 ) ;
} else {
V_178 = F_3 ( V_6 , V_180 ) &
~ ( V_181 | V_182 ) ;
F_4 ( V_6 , V_180 ,
V_178 | V_203 |
( V_176 ->
V_204 << 14 ) ) ;
}
break;
case V_188 :
F_5 ( V_6 , V_138 , V_137 ) ;
F_5 ( V_6 , V_206 ,
V_207 | V_208 |
V_209 | V_210 ) ;
F_4 ( V_6 , V_191 ,
( V_176 -> V_197 << 8 ) ) ;
V_178 = F_3 ( V_6 , V_180 ) &
~ V_200 ;
F_4 ( V_6 , V_180 , V_178 ) ;
F_9 ( F_10
( V_176 ->
V_211 ) ) ;
F_4 ( V_6 , V_191 ,
( V_176 -> V_197 << 8 ) |
V_176 -> V_192 |
( V_176 -> V_193 << 2 ) |
( V_176 -> V_194 << 4 ) |
( V_176 -> V_195 << 6 ) ) ;
V_178 = F_3 ( V_6 , V_180 ) &
~ ( V_201 | V_181 ) ;
F_4 ( V_6 , V_180 ,
V_178 | V_212 ) ;
F_9 ( F_10
( V_176 -> V_213 ) ) ;
V_178 &= ~ V_205 ;
F_4 ( V_6 , V_180 , V_178 ) ;
F_4 ( V_6 , V_191 , 0 ) ;
F_23 ( V_6 , V_11 ,
V_207 ) ;
F_23 ( V_6 , V_18 ,
V_208 ) ;
F_23 ( V_6 , V_24 ,
V_209 ) ;
F_23 ( V_6 , V_26 ,
V_210 ) ;
F_23 ( V_6 , V_161 ,
V_190 ) ;
F_39 ( F_38 ( V_157 -> V_189 ) ,
V_157 -> V_189 ) ;
break;
}
V_2 -> V_32 . V_187 = V_174 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_188 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
F_36 ( V_2 , V_186 ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_157 ,
struct V_214 * V_215 ,
T_1 V_216 )
{
struct V_6 * V_6 = V_157 -> V_6 ;
T_1 V_9 ;
int V_217 ;
V_9 = F_3 ( V_6 , V_218 ) ;
if ( V_9 & V_216 )
V_217 = V_215 -> V_217 ;
else
V_217 = 0 ;
F_43 ( V_215 -> V_215 , V_217 , V_215 -> V_217 ) ;
}
static void F_44 ( struct V_29 * V_30 )
{
struct V_3 * V_157 =
F_8 ( V_30 , struct V_3 , V_219 . V_30 . V_30 ) ;
F_42 ( V_157 , & V_157 -> V_219 , V_220 ) ;
}
static void F_45 ( struct V_29 * V_30 )
{
struct V_3 * V_157 =
F_8 ( V_30 , struct V_3 , V_221 . V_30 . V_30 ) ;
F_42 ( V_157 , & V_157 -> V_221 , V_222 ) ;
}
static T_3 F_46 ( int V_223 , void * V_224 )
{
struct V_3 * V_157 = V_224 ;
struct V_6 * V_6 = V_157 -> V_6 ;
#ifndef F_47
F_48 ( L_4 ) ;
#endif
if ( F_49 ( V_6 -> V_164 ) )
F_50 ( V_6 -> V_164 , 250 ) ;
F_51 ( V_225 ,
& V_157 -> V_219 . V_30 , F_10 ( 200 ) ) ;
return V_226 ;
}
static T_3 F_52 ( int V_223 , void * V_224 )
{
struct V_3 * V_157 = V_224 ;
struct V_6 * V_6 = V_157 -> V_6 ;
#ifndef F_47
F_48 ( L_5 ) ;
#endif
if ( F_49 ( V_6 -> V_164 ) )
F_50 ( V_6 -> V_164 , 250 ) ;
F_51 ( V_225 ,
& V_157 -> V_221 . V_30 , F_10 ( 200 ) ) ;
return V_226 ;
}
int F_53 ( struct V_1 * V_2 , enum V_227 V_228 ,
struct V_229 * V_215 , int V_217 )
{
struct V_3 * V_157 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_157 -> V_6 ;
int V_223 ;
int V_230 ;
switch ( V_228 ) {
case V_231 :
V_157 -> V_219 . V_215 = V_215 ;
V_157 -> V_219 . V_217 = V_217 ;
V_223 = V_232 ;
V_230 = V_233 ;
break;
case V_234 :
V_157 -> V_221 . V_215 = V_215 ;
V_157 -> V_221 . V_217 = V_217 ;
V_223 = V_235 ;
V_230 = V_236 ;
break;
default:
return - V_94 ;
}
if ( V_217 ) {
F_5 ( V_6 , V_161 , V_237 ) ;
F_5 ( V_6 , V_238 , V_230 ) ;
} else {
F_23 ( V_6 , V_238 , V_230 ) ;
}
switch ( V_228 ) {
case V_231 :
F_46 ( 0 , V_157 ) ;
break;
case V_234 :
F_52 ( 0 , V_157 ) ;
break;
}
return 0 ;
}
static T_3 F_54 ( int V_223 , void * V_224 )
{
struct V_3 * V_157 = V_224 ;
struct V_6 * V_6 = V_157 -> V_6 ;
T_1 V_9 ;
int V_217 = 0 ;
#ifndef F_47
F_48 ( L_6 ) ;
#endif
V_9 = F_3 ( V_6 , V_218 ) ;
if ( V_9 & V_239 )
V_217 |= V_157 -> V_240 . V_241 ;
if ( V_9 & V_242 )
V_217 |= V_157 -> V_240 . V_217 ;
F_43 ( V_157 -> V_240 . V_215 , V_217 ,
V_157 -> V_240 . V_217 | V_157 -> V_240 . V_241 ) ;
return V_226 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_229 * V_215 ,
int V_243 , int V_241 )
{
struct V_3 * V_157 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_157 -> V_6 ;
V_157 -> V_240 . V_215 = V_215 ;
V_157 -> V_240 . V_217 = V_243 ;
V_157 -> V_240 . V_241 = V_241 ;
if ( V_243 || V_241 ) {
F_5 ( V_6 , V_161 , V_237 ) ;
F_5 ( V_6 , V_180 ,
V_244 ) ;
} else {
F_23 ( V_6 , V_180 ,
V_244 ) ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_57 ( V_2 -> V_164 ) ;
struct V_3 * V_157 ;
struct V_4 * V_5 ;
struct V_4 * V_23 ;
int V_55 , V_34 ;
if ( V_6 -> V_2 . V_177 == NULL ) {
F_58 ( V_2 -> V_164 , L_7 ) ;
return - V_94 ;
}
V_157 = F_59 ( V_2 -> V_164 , sizeof( struct V_3 ) ,
V_245 ) ;
if ( V_157 == NULL )
return - V_246 ;
F_60 ( V_2 , V_157 ) ;
V_157 -> V_6 = V_6 ;
for ( V_34 = 0 ; V_34 < F_38 ( V_247 ) ; V_34 ++ )
V_157 -> V_189 [ V_34 ] . V_248 = V_247 [ V_34 ] ;
V_55 = F_61 ( V_6 -> V_164 , F_38 ( V_157 -> V_189 ) ,
V_157 -> V_189 ) ;
if ( V_55 != 0 )
return V_55 ;
F_23 ( V_6 , V_249 , V_250 ) ;
F_62 ( & V_2 -> V_32 . V_33 , F_7 ) ;
F_62 ( & V_157 -> V_219 . V_30 , F_44 ) ;
F_62 ( & V_157 -> V_221 . V_30 , F_45 ) ;
F_5 ( V_6 , V_249 , V_250 ) ;
F_19 ( V_2 , V_251 , 0xa7 ) ;
F_19 ( V_2 , 0xde , 0x13 ) ;
F_19 ( V_2 , V_251 , 0 ) ;
V_5 = & V_157 -> V_5 ;
V_23 = & V_157 -> V_23 ;
V_5 -> V_16 = ( F_3 ( V_6 , V_11 ) &
V_12 ) >> V_13 ;
V_5 -> V_21 = ( F_3 ( V_6 , V_18 ) &
V_19 ) >> V_20 ;
V_23 -> V_16 = ( F_3 ( V_6 , V_24 ) &
V_25 ) >> V_13 ;
V_23 -> V_21 = ( F_3 ( V_6 , V_26 ) &
V_27 ) >> V_20 ;
F_4 ( V_6 , V_11 , 0 ) ;
F_4 ( V_6 , V_18 , 0 ) ;
F_4 ( V_6 , V_24 , 0 ) ;
F_4 ( V_6 , V_26 , 0 ) ;
F_5 ( V_6 , V_11 ,
V_22 | V_252 ) ;
F_5 ( V_6 , V_24 ,
V_28 | V_253 ) ;
F_5 ( V_6 , V_18 ,
V_22 | V_254 ) ;
F_5 ( V_6 , V_26 ,
V_28 | V_255 ) ;
F_23 ( V_6 , V_97 , V_256 ) ;
F_23 ( V_6 , V_257 ,
V_258 | V_259 ) ;
F_23 ( V_6 , V_238 ,
V_233 | V_236 ) ;
F_63 ( V_6 , V_232 ,
F_46 , 0 , L_8 ,
V_157 ) ;
F_63 ( V_6 , V_235 ,
F_52 , 0 , L_9 ,
V_157 ) ;
F_63 ( V_6 , V_260 ,
F_54 , 0 , L_10 , V_157 ) ;
F_63 ( V_6 , V_261 ,
F_54 , 0 , L_11 , V_157 ) ;
F_36 ( V_2 , V_186 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_157 = F_2 ( V_2 ) ;
struct V_6 * V_6 = F_57 ( V_2 -> V_164 ) ;
F_23 ( V_6 , V_238 ,
V_233 | V_236 ) ;
F_23 ( V_6 , V_161 , V_237 ) ;
F_65 ( V_6 , V_261 , V_157 ) ;
F_65 ( V_6 , V_260 , V_157 ) ;
F_65 ( V_6 , V_232 , V_157 ) ;
F_65 ( V_6 , V_235 , V_157 ) ;
V_157 -> V_219 . V_215 = NULL ;
V_157 -> V_221 . V_215 = NULL ;
V_157 -> V_240 . V_215 = NULL ;
F_66 ( & V_157 -> V_219 . V_30 ) ;
F_66 ( & V_157 -> V_221 . V_30 ) ;
F_67 ( & V_2 -> V_32 . V_33 ) ;
F_36 ( V_2 , V_188 ) ;
F_23 ( V_6 , V_249 , V_250 ) ;
return 0 ;
}
static struct V_262 * F_68 ( struct V_263 * V_164 )
{
struct V_6 * V_6 = F_57 ( V_164 ) ;
return V_6 -> V_262 ;
}
static int F_69 ( struct V_264 * V_265 )
{
return F_70 ( & V_265 -> V_164 , & V_266 ,
& V_267 , 1 ) ;
}
static int F_71 ( struct V_264 * V_265 )
{
F_72 ( & V_265 -> V_164 ) ;
return 0 ;
}
