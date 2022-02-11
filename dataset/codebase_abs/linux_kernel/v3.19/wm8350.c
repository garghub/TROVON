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
struct V_1 * V_2 = F_9 ( V_32 ) ;
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
F_10 ( F_11
( 2 ) ) ;
else
F_10 ( F_11
( 1 ) ) ;
} else
F_12 ( 50 ) ;
}
V_5 -> V_14 = V_37 ;
V_23 -> V_14 = V_37 ;
}
static int F_13 ( struct V_39 * V_40 ,
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
F_14 ( 1 , L_1 , V_40 -> V_45 ) ;
return - 1 ;
}
switch ( V_43 ) {
case V_46 :
V_44 -> V_14 = V_15 ;
V_44 -> V_47 = 1 ;
F_15 ( & V_2 -> V_32 . V_33 ,
F_11 ( 1 ) ) ;
break;
case V_48 :
V_44 -> V_14 = V_17 ;
V_44 -> V_47 = 0 ;
F_15 ( & V_2 -> V_32 . V_33 ,
F_11 ( 1 ) ) ;
break;
}
return 0 ;
}
static int F_16 ( struct V_41 * V_42 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_17 ( V_42 ) ;
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
V_55 = F_18 ( V_42 , V_50 ) ;
if ( V_55 < 0 )
return V_55 ;
V_10 = F_19 ( V_2 , V_9 ) ;
F_20 ( V_2 , V_9 , V_10 | V_22 ) ;
return 1 ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_17 ( V_42 ) ;
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
return F_22 ( V_42 , V_50 ) ;
}
static int F_23 ( struct V_57 * V_58 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
T_1 V_62 ;
switch ( V_59 ) {
case V_63 :
F_24 ( V_6 , V_64 ,
V_65 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
F_5 ( V_6 , V_64 ,
V_65 ) ;
V_62 = F_19 ( V_2 , V_70 ) &
~ V_71 ;
F_20 ( V_2 , V_70 , V_62 | V_59 ) ;
break;
}
if ( V_61 == V_72 )
F_5 ( V_6 , V_73 ,
V_74 ) ;
else
F_24 ( V_6 , V_73 ,
V_74 ) ;
return 0 ;
}
static int F_25 ( struct V_57 * V_58 , int V_75 , int div )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_10 ;
switch ( V_75 ) {
case V_76 :
V_10 = F_19 ( V_2 , V_77 ) &
~ V_78 ;
F_20 ( V_2 , V_77 , V_10 | div ) ;
break;
case V_79 :
V_10 = F_19 ( V_2 , V_80 ) &
~ V_81 ;
F_20 ( V_2 , V_80 , V_10 | div ) ;
break;
case V_82 :
V_10 = F_19 ( V_2 , V_64 ) &
~ V_83 ;
F_20 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_84 :
V_10 = F_19 ( V_2 , V_64 ) &
~ V_85 ;
F_20 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_86 :
V_10 = F_19 ( V_2 , V_64 ) &
~ V_87 ;
F_20 ( V_2 , V_64 , V_10 | div ) ;
break;
case V_88 :
V_10 = F_19 ( V_2 , V_89 ) &
~ V_90 ;
F_20 ( V_2 , V_89 , V_10 | div ) ;
break;
case V_91 :
V_10 = F_19 ( V_2 , V_92 ) &
~ V_93 ;
F_20 ( V_2 , V_92 , V_10 | div ) ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_26 ( struct V_57 * V_58 , unsigned int V_95 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
T_1 V_96 = F_19 ( V_2 , V_97 ) &
~ ( V_98 | V_99 | V_100 ) ;
T_1 V_101 = F_19 ( V_2 , V_102 ) &
~ V_103 ;
T_1 V_104 = F_19 ( V_2 , V_89 ) &
~ V_105 ;
T_1 V_106 = F_19 ( V_2 , V_92 ) &
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
F_20 ( V_2 , V_97 , V_96 ) ;
F_20 ( V_2 , V_102 , V_101 ) ;
F_20 ( V_2 , V_89 , V_104 ) ;
F_20 ( V_2 , V_92 , V_106 ) ;
return 0 ;
}
static int F_27 ( struct V_122 * V_123 ,
struct V_124 * V_125 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_3 -> V_6 ;
T_1 V_96 = F_19 ( V_2 , V_97 ) &
~ V_126 ;
switch ( F_28 ( V_125 ) ) {
case 16 :
break;
case 20 :
V_96 |= 0x1 << 10 ;
break;
case 24 :
V_96 |= 0x2 << 10 ;
break;
case 32 :
V_96 |= 0x3 << 10 ;
break;
}
F_20 ( V_2 , V_97 , V_96 ) ;
if ( V_123 -> V_127 == V_128 ) {
if ( F_29 ( V_125 ) < 24000 )
F_5 ( V_6 , V_129 ,
V_130 ) ;
else
F_24 ( V_6 , V_129 ,
V_130 ) ;
}
return 0 ;
}
static int F_30 ( struct V_57 * V_131 , int V_132 )
{
struct V_1 * V_2 = V_131 -> V_2 ;
unsigned int V_10 ;
if ( V_132 )
V_10 = V_133 ;
else
V_10 = 0 ;
F_31 ( V_2 , V_134 , V_133 , V_10 ) ;
return 0 ;
}
static inline int F_32 ( struct V_135 * V_136 , unsigned int V_137 ,
unsigned int V_138 )
{
T_2 V_139 ;
unsigned int V_140 , V_141 , V_142 , V_143 ;
if ( V_138 >= 2815250 && V_138 <= 3125000 )
V_136 -> div = 0x4 ;
else if ( V_138 >= 5625000 && V_138 <= 6250000 )
V_136 -> div = 0x3 ;
else if ( V_138 >= 11250000 && V_138 <= 12500000 )
V_136 -> div = 0x2 ;
else if ( V_138 >= 22500000 && V_138 <= 25000000 )
V_136 -> div = 0x1 ;
else {
F_33 ( V_144 L_2 , V_138 ) ;
return - V_94 ;
}
if ( V_137 > 48000 )
V_136 -> V_145 = 1 ;
else
V_136 -> V_145 = 8 ;
V_140 = V_138 * ( 1 << ( V_136 -> div + 1 ) ) ;
V_141 = V_137 * V_136 -> V_145 ;
V_136 -> V_146 = V_140 / V_141 ;
V_143 = V_140 % V_141 ;
if ( V_143 ) {
V_139 = V_147 * ( long long ) V_143 ;
F_34 ( V_139 , V_141 ) ;
V_142 = V_139 & 0xFFFFFFFF ;
if ( ( V_142 % 10 ) >= 5 )
V_142 += 5 ;
V_142 /= 10 ;
V_136 -> V_148 = V_142 ;
} else
V_136 -> V_148 = 0 ;
return 0 ;
}
static int F_35 ( struct V_57 * V_58 ,
int V_149 , int V_150 , unsigned int V_151 ,
unsigned int V_152 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_3 * V_153 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_153 -> V_6 ;
struct V_135 V_136 ;
int V_55 = 0 ;
T_1 V_154 , V_62 ;
if ( V_151 == V_153 -> V_155 && V_152 == V_153 -> V_156 )
return 0 ;
F_24 ( V_6 , V_157 ,
V_158 | V_159 ) ;
if ( V_152 == 0 || V_151 == 0 )
return V_55 ;
V_55 = F_32 ( & V_136 , V_151 , V_152 ) ;
if ( V_55 < 0 )
return V_55 ;
F_36 ( V_6 -> V_160 ,
L_3 ,
V_151 , V_152 , V_136 . V_146 , V_136 . V_148 , V_136 . div ,
V_136 . V_145 ) ;
V_154 = F_19 ( V_2 , V_161 ) &
~ ( V_162 | V_163 | 0xc000 ) ;
F_20 ( V_2 , V_161 ,
V_154 | ( V_136 . div << 8 ) | 0x50 ) ;
F_20 ( V_2 , V_164 ,
( V_136 . V_145 << 11 ) | ( V_136 .
V_146 & V_165 ) ) ;
F_20 ( V_2 , V_166 , V_136 . V_148 ) ;
V_62 = F_19 ( V_2 , V_70 ) &
~ ( V_167 | V_168 ) ;
F_20 ( V_2 , V_70 ,
V_62 | ( V_136 . V_148 ? V_167 : 0 ) |
( V_136 . V_145 == 8 ? V_168 : 0 ) ) ;
F_5 ( V_6 , V_157 , V_159 ) ;
F_5 ( V_6 , V_157 , V_158 ) ;
V_153 -> V_156 = V_152 ;
V_153 -> V_155 = V_151 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
enum V_169 V_170 )
{
struct V_3 * V_153 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_153 -> V_6 ;
struct V_171 * V_172 =
V_6 -> V_2 . V_173 ;
T_1 V_174 ;
int V_55 ;
switch ( V_170 ) {
case V_175 :
V_174 = F_3 ( V_6 , V_176 ) &
~ ( V_177 | V_178 ) ;
F_4 ( V_6 , V_176 ,
V_174 | V_179 |
V_172 -> V_180 << 14 ) ;
break;
case V_181 :
V_174 = F_3 ( V_6 , V_176 ) ;
V_174 &= ~ V_177 ;
F_4 ( V_6 , V_176 ,
V_174 | V_179 ) ;
break;
case V_182 :
if ( V_2 -> V_32 . V_183 == V_184 ) {
V_55 = F_38 ( F_39 ( V_153 -> V_185 ) ,
V_153 -> V_185 ) ;
if ( V_55 != 0 )
return V_55 ;
F_5 ( V_6 , V_157 ,
V_186 ) ;
F_5 ( V_6 , V_134 ,
V_133 ) ;
F_4 ( V_6 , V_187 ,
V_172 -> V_188 |
( V_172 -> V_189 << 2 ) |
( V_172 -> V_190 << 4 ) |
( V_172 -> V_191 << 6 ) ) ;
F_10 ( F_11
( V_172 ->
V_192 ) ) ;
F_4 ( V_6 , V_187 ,
( V_172 -> V_193 << 8 ) ) ;
F_4 ( V_6 , V_176 ,
( V_172 ->
V_194 << 14 ) |
V_195 | V_196 |
V_197 ) ;
F_10 ( F_11
( V_172 ->
V_198 ) ) ;
V_174 = F_3 ( V_6 , V_176 ) &
~ ( V_177 | V_178 ) ;
V_174 |= V_199 |
( V_172 -> V_200 << 14 ) ;
F_4 ( V_6 , V_176 ,
V_174 ) ;
V_174 |= V_201 ;
F_4 ( V_6 , V_176 , V_174 ) ;
F_4 ( V_6 , V_187 , 0 ) ;
} else {
V_174 = F_3 ( V_6 , V_176 ) &
~ ( V_177 | V_178 ) ;
F_4 ( V_6 , V_176 ,
V_174 | V_199 |
( V_172 ->
V_200 << 14 ) ) ;
}
break;
case V_184 :
F_5 ( V_6 , V_134 , V_133 ) ;
F_5 ( V_6 , V_202 ,
V_203 | V_204 |
V_205 | V_206 ) ;
F_4 ( V_6 , V_187 ,
( V_172 -> V_193 << 8 ) ) ;
V_174 = F_3 ( V_6 , V_176 ) &
~ V_196 ;
F_4 ( V_6 , V_176 , V_174 ) ;
F_10 ( F_11
( V_172 ->
V_207 ) ) ;
F_4 ( V_6 , V_187 ,
( V_172 -> V_193 << 8 ) |
V_172 -> V_188 |
( V_172 -> V_189 << 2 ) |
( V_172 -> V_190 << 4 ) |
( V_172 -> V_191 << 6 ) ) ;
V_174 = F_3 ( V_6 , V_176 ) &
~ ( V_197 | V_177 ) ;
F_4 ( V_6 , V_176 ,
V_174 | V_208 ) ;
F_10 ( F_11
( V_172 -> V_209 ) ) ;
V_174 &= ~ V_201 ;
F_4 ( V_6 , V_176 , V_174 ) ;
F_4 ( V_6 , V_187 , 0 ) ;
F_24 ( V_6 , V_11 ,
V_203 ) ;
F_24 ( V_6 , V_18 ,
V_204 ) ;
F_24 ( V_6 , V_24 ,
V_205 ) ;
F_24 ( V_6 , V_26 ,
V_206 ) ;
F_24 ( V_6 , V_157 ,
V_186 ) ;
F_40 ( F_39 ( V_153 -> V_185 ) ,
V_153 -> V_185 ) ;
break;
}
V_2 -> V_32 . V_183 = V_170 ;
return 0 ;
}
static void F_41 ( struct V_3 * V_153 ,
struct V_210 * V_211 ,
T_1 V_212 )
{
struct V_6 * V_6 = V_153 -> V_6 ;
T_1 V_9 ;
int V_213 ;
V_9 = F_3 ( V_6 , V_214 ) ;
if ( V_9 & V_212 )
V_213 = V_211 -> V_213 ;
else
V_213 = 0 ;
F_42 ( V_211 -> V_211 , V_213 , V_211 -> V_213 ) ;
}
static void F_43 ( struct V_29 * V_30 )
{
struct V_3 * V_153 =
F_8 ( V_30 , struct V_3 , V_215 . V_30 . V_30 ) ;
F_41 ( V_153 , & V_153 -> V_215 , V_216 ) ;
}
static void F_44 ( struct V_29 * V_30 )
{
struct V_3 * V_153 =
F_8 ( V_30 , struct V_3 , V_217 . V_30 . V_30 ) ;
F_41 ( V_153 , & V_153 -> V_217 , V_218 ) ;
}
static T_3 F_45 ( int V_219 , void * V_220 )
{
struct V_3 * V_153 = V_220 ;
struct V_6 * V_6 = V_153 -> V_6 ;
#ifndef F_46
F_47 ( L_4 ) ;
#endif
if ( F_48 ( V_6 -> V_160 ) )
F_49 ( V_6 -> V_160 , 250 ) ;
F_50 ( V_221 ,
& V_153 -> V_215 . V_30 , F_11 ( 200 ) ) ;
return V_222 ;
}
static T_3 F_51 ( int V_219 , void * V_220 )
{
struct V_3 * V_153 = V_220 ;
struct V_6 * V_6 = V_153 -> V_6 ;
#ifndef F_46
F_47 ( L_5 ) ;
#endif
if ( F_48 ( V_6 -> V_160 ) )
F_49 ( V_6 -> V_160 , 250 ) ;
F_50 ( V_221 ,
& V_153 -> V_217 . V_30 , F_11 ( 200 ) ) ;
return V_222 ;
}
int F_52 ( struct V_1 * V_2 , enum V_223 V_224 ,
struct V_225 * V_211 , int V_213 )
{
struct V_3 * V_153 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_153 -> V_6 ;
int V_226 ;
switch ( V_224 ) {
case V_227 :
V_153 -> V_215 . V_211 = V_211 ;
V_153 -> V_215 . V_213 = V_213 ;
V_226 = V_228 ;
break;
case V_229 :
V_153 -> V_217 . V_211 = V_211 ;
V_153 -> V_217 . V_213 = V_213 ;
V_226 = V_230 ;
break;
default:
return - V_94 ;
}
if ( V_213 ) {
F_5 ( V_6 , V_157 , V_231 ) ;
F_5 ( V_6 , V_232 , V_226 ) ;
} else {
F_24 ( V_6 , V_232 , V_226 ) ;
}
switch ( V_224 ) {
case V_227 :
F_45 ( 0 , V_153 ) ;
break;
case V_229 :
F_51 ( 0 , V_153 ) ;
break;
}
return 0 ;
}
static T_3 F_53 ( int V_219 , void * V_220 )
{
struct V_3 * V_153 = V_220 ;
struct V_6 * V_6 = V_153 -> V_6 ;
T_1 V_9 ;
int V_213 = 0 ;
#ifndef F_46
F_47 ( L_6 ) ;
#endif
V_9 = F_3 ( V_6 , V_214 ) ;
if ( V_9 & V_233 )
V_213 |= V_153 -> V_234 . V_235 ;
if ( V_9 & V_236 )
V_213 |= V_153 -> V_234 . V_213 ;
F_42 ( V_153 -> V_234 . V_211 , V_213 ,
V_153 -> V_234 . V_213 | V_153 -> V_234 . V_235 ) ;
return V_222 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_225 * V_211 ,
int V_237 , int V_235 )
{
struct V_3 * V_153 = F_2 ( V_2 ) ;
struct V_6 * V_6 = V_153 -> V_6 ;
V_153 -> V_234 . V_211 = V_211 ;
V_153 -> V_234 . V_213 = V_237 ;
V_153 -> V_234 . V_235 = V_235 ;
if ( V_237 || V_235 ) {
F_5 ( V_6 , V_157 , V_231 ) ;
F_5 ( V_6 , V_176 ,
V_238 ) ;
} else {
F_24 ( V_6 , V_176 ,
V_238 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_56 ( V_2 -> V_160 ) ;
struct V_3 * V_153 ;
struct V_4 * V_5 ;
struct V_4 * V_23 ;
int V_55 , V_34 ;
if ( V_6 -> V_2 . V_173 == NULL ) {
F_57 ( V_2 -> V_160 , L_7 ) ;
return - V_94 ;
}
V_153 = F_58 ( V_2 -> V_160 , sizeof( struct V_3 ) ,
V_239 ) ;
if ( V_153 == NULL )
return - V_240 ;
F_59 ( V_2 , V_153 ) ;
V_153 -> V_6 = V_6 ;
for ( V_34 = 0 ; V_34 < F_39 ( V_241 ) ; V_34 ++ )
V_153 -> V_185 [ V_34 ] . V_242 = V_241 [ V_34 ] ;
V_55 = F_60 ( V_6 -> V_160 , F_39 ( V_153 -> V_185 ) ,
V_153 -> V_185 ) ;
if ( V_55 != 0 )
return V_55 ;
F_24 ( V_6 , V_243 , V_244 ) ;
F_61 ( & V_2 -> V_32 . V_33 , F_7 ) ;
F_61 ( & V_153 -> V_215 . V_30 , F_43 ) ;
F_61 ( & V_153 -> V_217 . V_30 , F_44 ) ;
F_5 ( V_6 , V_243 , V_244 ) ;
F_20 ( V_2 , V_245 , 0xa7 ) ;
F_20 ( V_2 , 0xde , 0x13 ) ;
F_20 ( V_2 , V_245 , 0 ) ;
V_5 = & V_153 -> V_5 ;
V_23 = & V_153 -> V_23 ;
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
V_22 | V_246 ) ;
F_5 ( V_6 , V_24 ,
V_28 | V_247 ) ;
F_5 ( V_6 , V_18 ,
V_22 | V_248 ) ;
F_5 ( V_6 , V_26 ,
V_28 | V_249 ) ;
F_24 ( V_6 , V_97 , V_250 ) ;
F_24 ( V_6 , V_251 ,
V_252 | V_253 ) ;
F_24 ( V_6 , V_232 ,
V_228 | V_230 ) ;
F_62 ( V_6 , V_254 ,
F_45 , 0 , L_8 ,
V_153 ) ;
F_62 ( V_6 , V_255 ,
F_51 , 0 , L_9 ,
V_153 ) ;
F_62 ( V_6 , V_256 ,
F_53 , 0 , L_10 , V_153 ) ;
F_62 ( V_6 , V_257 ,
F_53 , 0 , L_11 , V_153 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_153 = F_2 ( V_2 ) ;
struct V_6 * V_6 = F_56 ( V_2 -> V_160 ) ;
F_24 ( V_6 , V_232 ,
V_228 | V_230 ) ;
F_24 ( V_6 , V_157 , V_231 ) ;
F_64 ( V_6 , V_257 , V_153 ) ;
F_64 ( V_6 , V_256 , V_153 ) ;
F_64 ( V_6 , V_254 , V_153 ) ;
F_64 ( V_6 , V_255 , V_153 ) ;
V_153 -> V_215 . V_211 = NULL ;
V_153 -> V_217 . V_211 = NULL ;
V_153 -> V_234 . V_211 = NULL ;
F_65 ( & V_153 -> V_215 . V_30 ) ;
F_65 ( & V_153 -> V_217 . V_30 ) ;
F_66 ( & V_2 -> V_32 . V_33 ) ;
F_24 ( V_6 , V_243 , V_244 ) ;
return 0 ;
}
static struct V_258 * F_67 ( struct V_259 * V_160 )
{
struct V_6 * V_6 = F_56 ( V_160 ) ;
return V_6 -> V_258 ;
}
static int F_68 ( struct V_260 * V_261 )
{
return F_69 ( & V_261 -> V_160 , & V_262 ,
& V_263 , 1 ) ;
}
static int F_70 ( struct V_260 * V_261 )
{
F_71 ( & V_261 -> V_160 ) ;
return 0 ;
}
