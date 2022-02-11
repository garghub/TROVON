static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_4 ( V_4 , V_3 , V_6 ) ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_4 * V_4 = V_7 -> V_4 ;
int V_10 = 0 , V_11 = 0 ;
T_1 V_3 , V_12 ;
V_3 = F_2 ( V_4 , V_13 ) ;
V_12 = ( V_3 & V_14 ) >> V_15 ;
if ( V_9 -> V_16 == V_17 ) {
if ( V_12 < V_9 -> V_18 ) {
V_12 ++ ;
V_3 &= ~ V_14 ;
F_4 ( V_4 , V_13 ,
V_3 | ( V_12 << V_15 ) ) ;
} else
V_10 = 1 ;
} else if ( V_9 -> V_16 == V_19 ) {
if ( V_12 > 0 ) {
V_12 -- ;
V_3 &= ~ V_14 ;
F_4 ( V_4 , V_13 ,
V_3 | ( V_12 << V_15 ) ) ;
} else
V_10 = 1 ;
} else
return 1 ;
V_3 = F_2 ( V_4 , V_20 ) ;
V_12 = ( V_3 & V_21 ) >> V_22 ;
if ( V_9 -> V_16 == V_17 ) {
if ( V_12 < V_9 -> V_23 ) {
V_12 ++ ;
V_3 &= ~ V_21 ;
F_4 ( V_4 , V_20 ,
V_3 | ( V_12 << V_22 ) ) ;
} else
V_11 = 1 ;
} else if ( V_9 -> V_16 == V_19 ) {
if ( V_12 > 0 ) {
V_12 -- ;
V_3 &= ~ V_21 ;
F_4 ( V_4 , V_20 ,
V_3 | ( V_12 << V_22 ) ) ;
} else
V_11 = 1 ;
}
if ( ! V_10 || ! V_11 )
F_7 ( V_4 , V_13 , V_24 ) ;
return V_10 & V_11 ;
}
static inline int F_8 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_8 * V_25 = & V_7 -> V_25 ;
struct V_4 * V_4 = V_7 -> V_4 ;
int V_10 = 0 , V_11 = 0 ;
T_1 V_3 , V_12 ;
V_3 = F_2 ( V_4 , V_26 ) ;
V_12 = ( V_3 & V_27 ) >> V_15 ;
if ( V_25 -> V_16 == V_17 ) {
if ( V_12 < V_25 -> V_18 ) {
V_12 ++ ;
V_3 &= ~ V_27 ;
F_4 ( V_4 , V_26 ,
V_3 | ( V_12 << V_15 ) ) ;
} else
V_10 = 1 ;
} else if ( V_25 -> V_16 == V_19 ) {
if ( V_12 > 0 ) {
V_12 -- ;
V_3 &= ~ V_27 ;
F_4 ( V_4 , V_26 ,
V_3 | ( V_12 << V_15 ) ) ;
} else
V_10 = 1 ;
} else
return 1 ;
V_3 = F_2 ( V_4 , V_28 ) ;
V_12 = ( V_3 & V_29 ) >> V_22 ;
if ( V_25 -> V_16 == V_17 ) {
if ( V_12 < V_25 -> V_23 ) {
V_12 ++ ;
V_3 &= ~ V_29 ;
F_4 ( V_4 , V_28 ,
V_3 | ( V_12 << V_22 ) ) ;
} else
V_11 = 1 ;
} else if ( V_25 -> V_16 == V_19 ) {
if ( V_12 > 0 ) {
V_12 -- ;
V_3 &= ~ V_29 ;
F_4 ( V_4 , V_28 ,
V_3 | ( V_12 << V_22 ) ) ;
} else
V_11 = 1 ;
}
if ( ! V_10 || ! V_11 )
F_7 ( V_4 , V_26 , V_30 ) ;
return V_10 & V_11 ;
}
static void F_9 ( struct V_31 * V_32 )
{
struct V_33 * V_34 =
F_10 ( V_32 , struct V_33 , V_35 . V_32 ) ;
struct V_1 * V_2 = V_34 -> V_2 ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_8 * V_9 = & V_7 -> V_9 ,
* V_25 = & V_7 -> V_25 ;
int V_36 , V_37 , V_38 ;
if ( V_9 -> V_16 == V_39 && V_25 -> V_16 == V_39 )
return;
for ( V_36 = 0 ; V_36 <= 63 ; V_36 ++ ) {
V_37 = 1 , V_38 = 1 ;
if ( V_9 -> V_16 != V_39 )
V_37 = F_5 ( V_2 ) ;
if ( V_25 -> V_16 != V_39 )
V_38 = F_8 ( V_2 ) ;
if ( V_37 && V_38 )
break;
if ( V_9 -> V_16 == V_17 ||
V_25 -> V_16 == V_17 ) {
if ( V_36 >= V_40 )
F_11 ( F_12
( 2 ) ) ;
else
F_11 ( F_12
( 1 ) ) ;
} else
F_13 ( 50 ) ;
}
V_9 -> V_16 = V_39 ;
V_25 -> V_16 = V_39 ;
}
static int F_14 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_8 * V_46 ;
switch ( V_42 -> V_47 ) {
case 0 :
case 1 :
V_46 = & V_7 -> V_9 ;
break;
case 2 :
case 3 :
V_46 = & V_7 -> V_25 ;
break;
default:
F_15 () ;
return - 1 ;
}
switch ( V_45 ) {
case V_48 :
V_46 -> V_16 = V_17 ;
V_46 -> V_49 = 1 ;
if ( ! F_16 ( & V_2 -> V_34 . V_35 ) )
F_17 ( & V_2 -> V_34 . V_35 ,
F_12 ( 1 ) ) ;
break;
case V_50 :
V_46 -> V_16 = V_19 ;
V_46 -> V_49 = 0 ;
if ( ! F_16 ( & V_2 -> V_34 . V_35 ) )
F_17 ( & V_2 -> V_34 . V_35 ,
F_12 ( 1 ) ) ;
break;
}
return 0 ;
}
static int F_18 ( struct V_43 * V_44 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_19 ( V_44 ) ;
struct V_7 * V_53 = F_6 ( V_2 ) ;
struct V_8 * V_46 = NULL ;
struct V_54 * V_55 =
(struct V_54 * ) V_44 -> V_56 ;
int V_57 ;
unsigned int V_3 = V_55 -> V_3 ;
T_1 V_12 ;
switch ( V_3 ) {
case V_13 :
V_46 = & V_53 -> V_9 ;
break;
case V_26 :
V_46 = & V_53 -> V_25 ;
break;
default:
break;
}
if ( V_46 ) {
V_46 -> V_18 = V_52 -> V_6 . integer . V_6 [ 0 ] ;
V_46 -> V_23 = V_52 -> V_6 . integer . V_6 [ 1 ] ;
if ( ! V_46 -> V_49 )
return 1 ;
}
V_57 = F_20 ( V_44 , V_52 ) ;
if ( V_57 < 0 )
return V_57 ;
V_12 = F_21 ( V_2 , V_3 ) ;
F_22 ( V_2 , V_3 , V_12 | V_24 ) ;
return 1 ;
}
static int F_23 ( struct V_43 * V_44 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_19 ( V_44 ) ;
struct V_7 * V_53 = F_6 ( V_2 ) ;
struct V_8 * V_9 = & V_53 -> V_9 ;
struct V_8 * V_25 = & V_53 -> V_25 ;
struct V_54 * V_55 =
(struct V_54 * ) V_44 -> V_56 ;
unsigned int V_3 = V_55 -> V_3 ;
switch ( V_3 ) {
case V_13 :
V_52 -> V_6 . integer . V_6 [ 0 ] = V_9 -> V_18 ;
V_52 -> V_6 . integer . V_6 [ 1 ] = V_9 -> V_23 ;
return 0 ;
case V_26 :
V_52 -> V_6 . integer . V_6 [ 0 ] = V_25 -> V_18 ;
V_52 -> V_6 . integer . V_6 [ 1 ] = V_25 -> V_23 ;
return 0 ;
default:
break;
}
return F_24 ( V_44 , V_52 ) ;
}
static int F_25 ( struct V_58 * V_59 ,
int V_60 , unsigned int V_61 , int V_62 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_7 -> V_4 ;
T_1 V_63 ;
switch ( V_60 ) {
case V_64 :
F_26 ( V_4 , V_65 ,
V_66 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
F_7 ( V_4 , V_65 ,
V_66 ) ;
V_63 = F_21 ( V_2 , V_71 ) &
~ V_72 ;
F_22 ( V_2 , V_71 , V_63 | V_60 ) ;
break;
}
if ( V_62 == V_73 )
F_7 ( V_4 , V_74 ,
V_75 ) ;
else
F_26 ( V_4 , V_74 ,
V_75 ) ;
return 0 ;
}
static int F_27 ( struct V_58 * V_59 , int V_76 , int div )
{
struct V_1 * V_2 = V_59 -> V_2 ;
T_1 V_12 ;
switch ( V_76 ) {
case V_77 :
V_12 = F_21 ( V_2 , V_78 ) &
~ V_79 ;
F_22 ( V_2 , V_78 , V_12 | div ) ;
break;
case V_80 :
V_12 = F_21 ( V_2 , V_81 ) &
~ V_82 ;
F_22 ( V_2 , V_81 , V_12 | div ) ;
break;
case V_83 :
V_12 = F_21 ( V_2 , V_65 ) &
~ V_84 ;
F_22 ( V_2 , V_65 , V_12 | div ) ;
break;
case V_85 :
V_12 = F_21 ( V_2 , V_65 ) &
~ V_86 ;
F_22 ( V_2 , V_65 , V_12 | div ) ;
break;
case V_87 :
V_12 = F_21 ( V_2 , V_65 ) &
~ V_88 ;
F_22 ( V_2 , V_65 , V_12 | div ) ;
break;
case V_89 :
V_12 = F_21 ( V_2 , V_90 ) &
~ V_91 ;
F_22 ( V_2 , V_90 , V_12 | div ) ;
break;
case V_92 :
V_12 = F_21 ( V_2 , V_93 ) &
~ V_94 ;
F_22 ( V_2 , V_93 , V_12 | div ) ;
break;
default:
return - V_95 ;
}
return 0 ;
}
static int F_28 ( struct V_58 * V_59 , unsigned int V_96 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
T_1 V_97 = F_21 ( V_2 , V_98 ) &
~ ( V_99 | V_100 | V_101 ) ;
T_1 V_102 = F_21 ( V_2 , V_103 ) &
~ V_104 ;
T_1 V_105 = F_21 ( V_2 , V_90 ) &
~ V_106 ;
T_1 V_107 = F_21 ( V_2 , V_93 ) &
~ V_108 ;
switch ( V_96 & V_109 ) {
case V_110 :
V_102 |= V_104 ;
V_105 |= V_106 ;
V_107 |= V_108 ;
break;
case V_111 :
break;
default:
return - V_95 ;
}
switch ( V_96 & V_112 ) {
case V_113 :
V_97 |= 0x2 << 8 ;
break;
case V_114 :
break;
case V_115 :
V_97 |= 0x1 << 8 ;
break;
case V_116 :
V_97 |= 0x3 << 8 ;
break;
case V_117 :
V_97 |= 0x3 << 8 | V_100 ;
break;
default:
return - V_95 ;
}
switch ( V_96 & V_118 ) {
case V_119 :
break;
case V_120 :
V_97 |= V_100 | V_99 ;
break;
case V_121 :
V_97 |= V_99 ;
break;
case V_122 :
V_97 |= V_100 ;
break;
default:
return - V_95 ;
}
F_22 ( V_2 , V_98 , V_97 ) ;
F_22 ( V_2 , V_103 , V_102 ) ;
F_22 ( V_2 , V_90 , V_105 ) ;
F_22 ( V_2 , V_93 , V_107 ) ;
return 0 ;
}
static int F_29 ( struct V_123 * V_124 ,
struct V_125 * V_126 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_7 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_7 -> V_4 ;
T_1 V_97 = F_21 ( V_2 , V_98 ) &
~ V_127 ;
switch ( F_30 ( V_126 ) ) {
case V_128 :
break;
case V_129 :
V_97 |= 0x1 << 10 ;
break;
case V_130 :
V_97 |= 0x2 << 10 ;
break;
case V_131 :
V_97 |= 0x3 << 10 ;
break;
}
F_22 ( V_2 , V_98 , V_97 ) ;
if ( V_124 -> V_132 == V_133 ) {
if ( F_31 ( V_126 ) < 24000 )
F_7 ( V_4 , V_134 ,
V_135 ) ;
else
F_26 ( V_4 , V_134 ,
V_135 ) ;
}
return 0 ;
}
static int F_32 ( struct V_58 * V_136 , int V_137 )
{
struct V_1 * V_2 = V_136 -> V_2 ;
unsigned int V_12 ;
if ( V_137 )
V_12 = V_138 ;
else
V_12 = 0 ;
F_33 ( V_2 , V_139 , V_138 , V_12 ) ;
return 0 ;
}
static inline int F_34 ( struct V_140 * V_141 , unsigned int V_142 ,
unsigned int V_143 )
{
T_2 V_144 ;
unsigned int V_145 , V_146 , V_147 , V_148 ;
if ( V_143 >= 2815250 && V_143 <= 3125000 )
V_141 -> div = 0x4 ;
else if ( V_143 >= 5625000 && V_143 <= 6250000 )
V_141 -> div = 0x3 ;
else if ( V_143 >= 11250000 && V_143 <= 12500000 )
V_141 -> div = 0x2 ;
else if ( V_143 >= 22500000 && V_143 <= 25000000 )
V_141 -> div = 0x1 ;
else {
F_35 ( V_149 L_1 , V_143 ) ;
return - V_95 ;
}
if ( V_142 > 48000 )
V_141 -> V_150 = 1 ;
else
V_141 -> V_150 = 8 ;
V_145 = V_143 * ( 1 << ( V_141 -> div + 1 ) ) ;
V_146 = V_142 * V_141 -> V_150 ;
V_141 -> V_151 = V_145 / V_146 ;
V_148 = V_145 % V_146 ;
if ( V_148 ) {
V_144 = V_152 * ( long long ) V_148 ;
F_36 ( V_144 , V_146 ) ;
V_147 = V_144 & 0xFFFFFFFF ;
if ( ( V_147 % 10 ) >= 5 )
V_147 += 5 ;
V_147 /= 10 ;
V_141 -> V_153 = V_147 ;
} else
V_141 -> V_153 = 0 ;
return 0 ;
}
static int F_37 ( struct V_58 * V_59 ,
int V_154 , int V_155 , unsigned int V_156 ,
unsigned int V_157 )
{
struct V_1 * V_2 = V_59 -> V_2 ;
struct V_7 * V_158 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_158 -> V_4 ;
struct V_140 V_141 ;
int V_57 = 0 ;
T_1 V_159 , V_63 ;
if ( V_156 == V_158 -> V_160 && V_157 == V_158 -> V_161 )
return 0 ;
F_26 ( V_4 , V_162 ,
V_163 | V_164 ) ;
if ( V_157 == 0 || V_156 == 0 )
return V_57 ;
V_57 = F_34 ( & V_141 , V_156 , V_157 ) ;
if ( V_57 < 0 )
return V_57 ;
F_38 ( V_4 -> V_165 ,
L_2 ,
V_156 , V_157 , V_141 . V_151 , V_141 . V_153 , V_141 . div ,
V_141 . V_150 ) ;
V_159 = F_21 ( V_2 , V_166 ) &
~ ( V_167 | V_168 | 0xc000 ) ;
F_22 ( V_2 , V_166 ,
V_159 | ( V_141 . div << 8 ) | 0x50 ) ;
F_22 ( V_2 , V_169 ,
( V_141 . V_150 << 11 ) | ( V_141 .
V_151 & V_170 ) ) ;
F_22 ( V_2 , V_171 , V_141 . V_153 ) ;
V_63 = F_21 ( V_2 , V_71 ) &
~ ( V_172 | V_173 ) ;
F_22 ( V_2 , V_71 ,
V_63 | ( V_141 . V_153 ? V_172 : 0 ) |
( V_141 . V_150 == 8 ? V_173 : 0 ) ) ;
F_7 ( V_4 , V_162 , V_164 ) ;
F_7 ( V_4 , V_162 , V_163 ) ;
V_158 -> V_161 = V_157 ;
V_158 -> V_160 = V_156 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
enum V_174 V_175 )
{
struct V_7 * V_158 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_158 -> V_4 ;
struct V_176 * V_177 =
V_4 -> V_2 . V_178 ;
T_1 V_179 ;
int V_57 ;
switch ( V_175 ) {
case V_180 :
V_179 = F_2 ( V_4 , V_181 ) &
~ ( V_182 | V_183 ) ;
F_4 ( V_4 , V_181 ,
V_179 | V_184 |
V_177 -> V_185 << 14 ) ;
break;
case V_186 :
V_179 = F_2 ( V_4 , V_181 ) ;
V_179 &= ~ V_182 ;
F_4 ( V_4 , V_181 ,
V_179 | V_184 ) ;
break;
case V_187 :
if ( V_2 -> V_34 . V_188 == V_189 ) {
V_57 = F_40 ( F_41 ( V_158 -> V_190 ) ,
V_158 -> V_190 ) ;
if ( V_57 != 0 )
return V_57 ;
F_7 ( V_4 , V_162 ,
V_191 ) ;
F_7 ( V_4 , V_139 ,
V_138 ) ;
F_4 ( V_4 , V_192 ,
V_177 -> V_193 |
( V_177 -> V_194 << 2 ) |
( V_177 -> V_195 << 4 ) |
( V_177 -> V_196 << 6 ) ) ;
F_11 ( F_12
( V_177 ->
V_197 ) ) ;
F_4 ( V_4 , V_192 ,
( V_177 -> V_198 << 8 ) ) ;
F_4 ( V_4 , V_181 ,
( V_177 ->
V_199 << 14 ) |
V_200 | V_201 |
V_202 ) ;
F_11 ( F_12
( V_177 ->
V_203 ) ) ;
V_179 = F_2 ( V_4 , V_181 ) &
~ ( V_182 | V_183 ) ;
V_179 |= V_204 |
( V_177 -> V_205 << 14 ) ;
F_4 ( V_4 , V_181 ,
V_179 ) ;
V_179 |= V_206 ;
F_4 ( V_4 , V_181 , V_179 ) ;
F_4 ( V_4 , V_192 , 0 ) ;
} else {
V_179 = F_2 ( V_4 , V_181 ) &
~ ( V_182 | V_183 ) ;
F_4 ( V_4 , V_181 ,
V_179 | V_204 |
( V_177 ->
V_205 << 14 ) ) ;
}
break;
case V_189 :
F_7 ( V_4 , V_139 , V_138 ) ;
F_7 ( V_4 , V_207 ,
V_208 | V_209 |
V_210 | V_211 ) ;
F_4 ( V_4 , V_192 ,
( V_177 -> V_198 << 8 ) ) ;
V_179 = F_2 ( V_4 , V_181 ) &
~ V_201 ;
F_4 ( V_4 , V_181 , V_179 ) ;
F_11 ( F_12
( V_177 ->
V_212 ) ) ;
F_4 ( V_4 , V_192 ,
( V_177 -> V_198 << 8 ) |
V_177 -> V_193 |
( V_177 -> V_194 << 2 ) |
( V_177 -> V_195 << 4 ) |
( V_177 -> V_196 << 6 ) ) ;
V_179 = F_2 ( V_4 , V_181 ) &
~ ( V_202 | V_182 ) ;
F_4 ( V_4 , V_181 ,
V_179 | V_213 ) ;
F_11 ( F_12
( V_177 -> V_214 ) ) ;
V_179 &= ~ V_206 ;
F_4 ( V_4 , V_181 , V_179 ) ;
F_4 ( V_4 , V_192 , 0 ) ;
F_26 ( V_4 , V_13 ,
V_208 ) ;
F_26 ( V_4 , V_20 ,
V_209 ) ;
F_26 ( V_4 , V_26 ,
V_210 ) ;
F_26 ( V_4 , V_28 ,
V_211 ) ;
F_26 ( V_4 , V_162 ,
V_191 ) ;
F_42 ( F_41 ( V_158 -> V_190 ) ,
V_158 -> V_190 ) ;
break;
}
V_2 -> V_34 . V_188 = V_175 ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_189 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
F_39 ( V_2 , V_187 ) ;
return 0 ;
}
static void F_45 ( struct V_7 * V_158 ,
struct V_215 * V_216 ,
T_1 V_217 )
{
struct V_4 * V_4 = V_158 -> V_4 ;
T_1 V_3 ;
int V_218 ;
V_3 = F_2 ( V_4 , V_219 ) ;
if ( V_3 & V_217 )
V_218 = V_216 -> V_218 ;
else
V_218 = 0 ;
F_46 ( V_216 -> V_216 , V_218 , V_216 -> V_218 ) ;
}
static void F_47 ( struct V_31 * V_32 )
{
struct V_7 * V_158 =
F_10 ( V_32 , struct V_7 , V_220 . V_32 . V_32 ) ;
F_45 ( V_158 , & V_158 -> V_220 , V_221 ) ;
}
static void F_48 ( struct V_31 * V_32 )
{
struct V_7 * V_158 =
F_10 ( V_32 , struct V_7 , V_222 . V_32 . V_32 ) ;
F_45 ( V_158 , & V_158 -> V_222 , V_223 ) ;
}
static T_3 F_49 ( int V_224 , void * V_225 )
{
struct V_7 * V_158 = V_225 ;
struct V_4 * V_4 = V_158 -> V_4 ;
#ifndef F_50
F_51 ( L_3 ) ;
#endif
if ( F_52 ( V_4 -> V_165 ) )
F_53 ( V_4 -> V_165 , 250 ) ;
F_17 ( & V_158 -> V_220 . V_32 , 200 ) ;
return V_226 ;
}
static T_3 F_54 ( int V_224 , void * V_225 )
{
struct V_7 * V_158 = V_225 ;
struct V_4 * V_4 = V_158 -> V_4 ;
#ifndef F_50
F_51 ( L_4 ) ;
#endif
if ( F_52 ( V_4 -> V_165 ) )
F_53 ( V_4 -> V_165 , 250 ) ;
F_17 ( & V_158 -> V_222 . V_32 , 200 ) ;
return V_226 ;
}
int F_55 ( struct V_1 * V_2 , enum V_227 V_228 ,
struct V_229 * V_216 , int V_218 )
{
struct V_7 * V_158 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_158 -> V_4 ;
int V_224 ;
int V_230 ;
switch ( V_228 ) {
case V_231 :
V_158 -> V_220 . V_216 = V_216 ;
V_158 -> V_220 . V_218 = V_218 ;
V_224 = V_232 ;
V_230 = V_233 ;
break;
case V_234 :
V_158 -> V_222 . V_216 = V_216 ;
V_158 -> V_222 . V_218 = V_218 ;
V_224 = V_235 ;
V_230 = V_236 ;
break;
default:
return - V_95 ;
}
if ( V_218 ) {
F_7 ( V_4 , V_162 , V_237 ) ;
F_7 ( V_4 , V_238 , V_230 ) ;
} else {
F_26 ( V_4 , V_238 , V_230 ) ;
}
switch ( V_228 ) {
case V_231 :
F_49 ( 0 , V_158 ) ;
break;
case V_234 :
F_54 ( 0 , V_158 ) ;
break;
}
return 0 ;
}
static T_3 F_56 ( int V_224 , void * V_225 )
{
struct V_7 * V_158 = V_225 ;
struct V_4 * V_4 = V_158 -> V_4 ;
T_1 V_3 ;
int V_218 = 0 ;
#ifndef F_50
F_51 ( L_5 ) ;
#endif
V_3 = F_2 ( V_4 , V_219 ) ;
if ( V_3 & V_239 )
V_218 |= V_158 -> V_240 . V_241 ;
if ( V_3 & V_242 )
V_218 |= V_158 -> V_240 . V_218 ;
F_46 ( V_158 -> V_240 . V_216 , V_218 ,
V_158 -> V_240 . V_218 | V_158 -> V_240 . V_241 ) ;
return V_226 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_229 * V_216 ,
int V_243 , int V_241 )
{
struct V_7 * V_158 = F_6 ( V_2 ) ;
struct V_4 * V_4 = V_158 -> V_4 ;
V_158 -> V_240 . V_216 = V_216 ;
V_158 -> V_240 . V_218 = V_243 ;
V_158 -> V_240 . V_241 = V_241 ;
if ( V_243 || V_241 ) {
F_7 ( V_4 , V_162 , V_237 ) ;
F_7 ( V_4 , V_181 ,
V_244 ) ;
} else {
F_26 ( V_4 , V_181 ,
V_244 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_59 ( V_2 -> V_165 ) ;
struct V_7 * V_158 ;
struct V_8 * V_9 ;
struct V_8 * V_25 ;
int V_57 , V_36 ;
if ( V_4 -> V_2 . V_178 == NULL ) {
F_60 ( V_2 -> V_165 , L_6 ) ;
return - V_95 ;
}
V_158 = F_61 ( V_2 -> V_165 , sizeof( struct V_7 ) ,
V_245 ) ;
if ( V_158 == NULL )
return - V_246 ;
F_62 ( V_2 , V_158 ) ;
V_158 -> V_4 = V_4 ;
for ( V_36 = 0 ; V_36 < F_41 ( V_247 ) ; V_36 ++ )
V_158 -> V_190 [ V_36 ] . V_248 = V_247 [ V_36 ] ;
V_57 = F_63 ( V_4 -> V_165 , F_41 ( V_158 -> V_190 ) ,
V_158 -> V_190 ) ;
if ( V_57 != 0 )
return V_57 ;
V_2 -> V_5 = V_4 ;
F_26 ( V_4 , V_249 , V_250 ) ;
F_64 ( & V_2 -> V_34 . V_35 , F_9 ) ;
F_64 ( & V_158 -> V_220 . V_32 , F_47 ) ;
F_64 ( & V_158 -> V_222 . V_32 , F_48 ) ;
F_7 ( V_4 , V_249 , V_250 ) ;
F_22 ( V_2 , V_251 , 0xa7 ) ;
F_22 ( V_2 , 0xde , 0x13 ) ;
F_22 ( V_2 , V_251 , 0 ) ;
V_9 = & V_158 -> V_9 ;
V_25 = & V_158 -> V_25 ;
V_9 -> V_18 = ( F_2 ( V_4 , V_13 ) &
V_14 ) >> V_15 ;
V_9 -> V_23 = ( F_2 ( V_4 , V_20 ) &
V_21 ) >> V_22 ;
V_25 -> V_18 = ( F_2 ( V_4 , V_26 ) &
V_27 ) >> V_15 ;
V_25 -> V_23 = ( F_2 ( V_4 , V_28 ) &
V_29 ) >> V_22 ;
F_4 ( V_4 , V_13 , 0 ) ;
F_4 ( V_4 , V_20 , 0 ) ;
F_4 ( V_4 , V_26 , 0 ) ;
F_4 ( V_4 , V_28 , 0 ) ;
F_7 ( V_4 , V_13 ,
V_24 | V_252 ) ;
F_7 ( V_4 , V_26 ,
V_30 | V_253 ) ;
F_7 ( V_4 , V_20 ,
V_24 | V_254 ) ;
F_7 ( V_4 , V_28 ,
V_30 | V_255 ) ;
F_26 ( V_4 , V_98 , V_256 ) ;
F_26 ( V_4 , V_257 ,
V_258 | V_259 ) ;
F_26 ( V_4 , V_238 ,
V_233 | V_236 ) ;
F_65 ( V_4 , V_232 ,
F_49 , 0 , L_7 ,
V_158 ) ;
F_65 ( V_4 , V_235 ,
F_54 , 0 , L_8 ,
V_158 ) ;
F_65 ( V_4 , V_260 ,
F_56 , 0 , L_9 , V_158 ) ;
F_65 ( V_4 , V_261 ,
F_56 , 0 , L_10 , V_158 ) ;
F_39 ( V_2 , V_187 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_158 = F_6 ( V_2 ) ;
struct V_4 * V_4 = F_59 ( V_2 -> V_165 ) ;
F_26 ( V_4 , V_238 ,
V_233 | V_236 ) ;
F_26 ( V_4 , V_162 , V_237 ) ;
F_67 ( V_4 , V_261 , V_158 ) ;
F_67 ( V_4 , V_260 , V_158 ) ;
F_67 ( V_4 , V_232 , V_158 ) ;
F_67 ( V_4 , V_235 , V_158 ) ;
V_158 -> V_220 . V_216 = NULL ;
V_158 -> V_222 . V_216 = NULL ;
V_158 -> V_240 . V_216 = NULL ;
F_68 ( & V_158 -> V_220 . V_32 ) ;
F_68 ( & V_158 -> V_222 . V_32 ) ;
F_69 ( & V_2 -> V_34 . V_35 ) ;
F_39 ( V_2 , V_189 ) ;
F_26 ( V_4 , V_249 , V_250 ) ;
F_70 ( F_41 ( V_158 -> V_190 ) , V_158 -> V_190 ) ;
return 0 ;
}
static int T_4 F_71 ( struct V_262 * V_263 )
{
return F_72 ( & V_263 -> V_165 , & V_264 ,
& V_265 , 1 ) ;
}
static int T_5 F_73 ( struct V_262 * V_263 )
{
F_74 ( & V_263 -> V_165 ) ;
return 0 ;
}
