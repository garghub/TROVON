static inline int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = & V_1 -> V_3 ;
struct V_4 * V_4 = V_1 -> V_4 ;
int V_5 = 0 , V_6 = 0 ;
T_1 V_7 , V_8 ;
V_7 = F_2 ( V_4 , V_9 ) ;
V_8 = ( V_7 & V_10 ) >> V_11 ;
if ( V_3 -> V_12 == V_13 ) {
if ( V_8 < V_3 -> V_14 ) {
V_8 ++ ;
V_7 &= ~ V_10 ;
F_3 ( V_4 , V_9 ,
V_7 | ( V_8 << V_11 ) ) ;
} else
V_5 = 1 ;
} else if ( V_3 -> V_12 == V_15 ) {
if ( V_8 > 0 ) {
V_8 -- ;
V_7 &= ~ V_10 ;
F_3 ( V_4 , V_9 ,
V_7 | ( V_8 << V_11 ) ) ;
} else
V_5 = 1 ;
} else
return 1 ;
V_7 = F_2 ( V_4 , V_16 ) ;
V_8 = ( V_7 & V_17 ) >> V_18 ;
if ( V_3 -> V_12 == V_13 ) {
if ( V_8 < V_3 -> V_19 ) {
V_8 ++ ;
V_7 &= ~ V_17 ;
F_3 ( V_4 , V_16 ,
V_7 | ( V_8 << V_18 ) ) ;
} else
V_6 = 1 ;
} else if ( V_3 -> V_12 == V_15 ) {
if ( V_8 > 0 ) {
V_8 -- ;
V_7 &= ~ V_17 ;
F_3 ( V_4 , V_16 ,
V_7 | ( V_8 << V_18 ) ) ;
} else
V_6 = 1 ;
}
if ( ! V_5 || ! V_6 )
F_4 ( V_4 , V_9 , V_20 ) ;
return V_5 & V_6 ;
}
static inline int F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_21 = & V_1 -> V_21 ;
struct V_4 * V_4 = V_1 -> V_4 ;
int V_5 = 0 , V_6 = 0 ;
T_1 V_7 , V_8 ;
V_7 = F_2 ( V_4 , V_22 ) ;
V_8 = ( V_7 & V_23 ) >> V_11 ;
if ( V_21 -> V_12 == V_13 ) {
if ( V_8 < V_21 -> V_14 ) {
V_8 ++ ;
V_7 &= ~ V_23 ;
F_3 ( V_4 , V_22 ,
V_7 | ( V_8 << V_11 ) ) ;
} else
V_5 = 1 ;
} else if ( V_21 -> V_12 == V_15 ) {
if ( V_8 > 0 ) {
V_8 -- ;
V_7 &= ~ V_23 ;
F_3 ( V_4 , V_22 ,
V_7 | ( V_8 << V_11 ) ) ;
} else
V_5 = 1 ;
} else
return 1 ;
V_7 = F_2 ( V_4 , V_24 ) ;
V_8 = ( V_7 & V_25 ) >> V_18 ;
if ( V_21 -> V_12 == V_13 ) {
if ( V_8 < V_21 -> V_19 ) {
V_8 ++ ;
V_7 &= ~ V_25 ;
F_3 ( V_4 , V_24 ,
V_7 | ( V_8 << V_18 ) ) ;
} else
V_6 = 1 ;
} else if ( V_21 -> V_12 == V_15 ) {
if ( V_8 > 0 ) {
V_8 -- ;
V_7 &= ~ V_25 ;
F_3 ( V_4 , V_24 ,
V_7 | ( V_8 << V_18 ) ) ;
} else
V_6 = 1 ;
}
if ( ! V_5 || ! V_6 )
F_4 ( V_4 , V_22 , V_26 ) ;
return V_5 & V_6 ;
}
static void F_6 ( struct V_27 * V_28 )
{
struct V_1 * V_1 =
F_7 ( V_28 , struct V_1 , V_29 . V_28 ) ;
struct V_2 * V_3 = & V_1 -> V_3 ,
* V_21 = & V_1 -> V_21 ;
int V_30 , V_31 , V_32 ;
if ( V_3 -> V_12 == V_33 && V_21 -> V_12 == V_33 )
return;
for ( V_30 = 0 ; V_30 <= 63 ; V_30 ++ ) {
V_31 = 1 , V_32 = 1 ;
if ( V_3 -> V_12 != V_33 )
V_31 = F_1 ( V_1 ) ;
if ( V_21 -> V_12 != V_33 )
V_32 = F_5 ( V_1 ) ;
if ( V_31 && V_32 )
break;
if ( V_3 -> V_12 == V_13 ||
V_21 -> V_12 == V_13 ) {
if ( V_30 >= V_34 )
F_8 ( F_9
( 2 ) ) ;
else
F_8 ( F_9
( 1 ) ) ;
} else
F_10 ( 50 ) ;
}
V_3 -> V_12 = V_33 ;
V_21 -> V_12 = V_33 ;
}
static int F_11 ( struct V_35 * V_36 ,
struct V_37 * V_38 , int V_39 )
{
struct V_40 * V_41 = F_12 ( V_36 -> V_42 ) ;
struct V_1 * V_1 = F_13 ( V_41 ) ;
struct V_2 * V_43 ;
switch ( V_36 -> V_44 ) {
case 0 :
case 1 :
V_43 = & V_1 -> V_3 ;
break;
case 2 :
case 3 :
V_43 = & V_1 -> V_21 ;
break;
default:
F_14 ( 1 , L_1 , V_36 -> V_44 ) ;
return - 1 ;
}
switch ( V_39 ) {
case V_45 :
V_43 -> V_12 = V_13 ;
V_43 -> V_46 = 1 ;
F_15 ( & V_1 -> V_29 ,
F_9 ( 1 ) ) ;
break;
case V_47 :
V_43 -> V_12 = V_15 ;
V_43 -> V_46 = 0 ;
F_15 ( & V_1 -> V_29 ,
F_9 ( 1 ) ) ;
break;
}
return 0 ;
}
static int F_16 ( struct V_37 * V_38 ,
struct V_48 * V_49 )
{
struct V_40 * V_41 = F_17 ( V_38 ) ;
struct V_1 * V_50 = F_13 ( V_41 ) ;
struct V_2 * V_43 = NULL ;
struct V_51 * V_52 =
(struct V_51 * ) V_38 -> V_53 ;
int V_54 ;
unsigned int V_7 = V_52 -> V_7 ;
T_1 V_8 ;
switch ( V_7 ) {
case V_9 :
V_43 = & V_50 -> V_3 ;
break;
case V_22 :
V_43 = & V_50 -> V_21 ;
break;
default:
break;
}
if ( V_43 ) {
V_43 -> V_14 = V_49 -> V_55 . integer . V_55 [ 0 ] ;
V_43 -> V_19 = V_49 -> V_55 . integer . V_55 [ 1 ] ;
if ( ! V_43 -> V_46 )
return 1 ;
}
V_54 = F_18 ( V_38 , V_49 ) ;
if ( V_54 < 0 )
return V_54 ;
V_8 = F_19 ( V_41 , V_7 ) ;
F_20 ( V_41 , V_7 , V_8 | V_20 ) ;
return 1 ;
}
static int F_21 ( struct V_37 * V_38 ,
struct V_48 * V_49 )
{
struct V_40 * V_41 = F_17 ( V_38 ) ;
struct V_1 * V_50 = F_13 ( V_41 ) ;
struct V_2 * V_3 = & V_50 -> V_3 ;
struct V_2 * V_21 = & V_50 -> V_21 ;
struct V_51 * V_52 =
(struct V_51 * ) V_38 -> V_53 ;
unsigned int V_7 = V_52 -> V_7 ;
switch ( V_7 ) {
case V_9 :
V_49 -> V_55 . integer . V_55 [ 0 ] = V_3 -> V_14 ;
V_49 -> V_55 . integer . V_55 [ 1 ] = V_3 -> V_19 ;
return 0 ;
case V_22 :
V_49 -> V_55 . integer . V_55 [ 0 ] = V_21 -> V_14 ;
V_49 -> V_55 . integer . V_55 [ 1 ] = V_21 -> V_19 ;
return 0 ;
default:
break;
}
return F_22 ( V_38 , V_49 ) ;
}
static int F_23 ( struct V_56 * V_57 ,
int V_58 , unsigned int V_59 , int V_60 )
{
struct V_40 * V_41 = V_57 -> V_41 ;
struct V_1 * V_1 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_1 -> V_4 ;
T_1 V_61 ;
switch ( V_58 ) {
case V_62 :
F_24 ( V_4 , V_63 ,
V_64 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_4 ( V_4 , V_63 ,
V_64 ) ;
V_61 = F_19 ( V_41 , V_69 ) &
~ V_70 ;
F_20 ( V_41 , V_69 , V_61 | V_58 ) ;
break;
}
if ( V_60 == V_71 )
F_4 ( V_4 , V_72 ,
V_73 ) ;
else
F_24 ( V_4 , V_72 ,
V_73 ) ;
return 0 ;
}
static int F_25 ( struct V_56 * V_57 , int V_74 , int div )
{
struct V_40 * V_41 = V_57 -> V_41 ;
T_1 V_8 ;
switch ( V_74 ) {
case V_75 :
V_8 = F_19 ( V_41 , V_76 ) &
~ V_77 ;
F_20 ( V_41 , V_76 , V_8 | div ) ;
break;
case V_78 :
V_8 = F_19 ( V_41 , V_79 ) &
~ V_80 ;
F_20 ( V_41 , V_79 , V_8 | div ) ;
break;
case V_81 :
V_8 = F_19 ( V_41 , V_63 ) &
~ V_82 ;
F_20 ( V_41 , V_63 , V_8 | div ) ;
break;
case V_83 :
V_8 = F_19 ( V_41 , V_63 ) &
~ V_84 ;
F_20 ( V_41 , V_63 , V_8 | div ) ;
break;
case V_85 :
V_8 = F_19 ( V_41 , V_63 ) &
~ V_86 ;
F_20 ( V_41 , V_63 , V_8 | div ) ;
break;
case V_87 :
V_8 = F_19 ( V_41 , V_88 ) &
~ V_89 ;
F_20 ( V_41 , V_88 , V_8 | div ) ;
break;
case V_90 :
V_8 = F_19 ( V_41 , V_91 ) &
~ V_92 ;
F_20 ( V_41 , V_91 , V_8 | div ) ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_26 ( struct V_56 * V_57 , unsigned int V_94 )
{
struct V_40 * V_41 = V_57 -> V_41 ;
T_1 V_95 = F_19 ( V_41 , V_96 ) &
~ ( V_97 | V_98 | V_99 ) ;
T_1 V_100 = F_19 ( V_41 , V_101 ) &
~ V_102 ;
T_1 V_103 = F_19 ( V_41 , V_88 ) &
~ V_104 ;
T_1 V_105 = F_19 ( V_41 , V_91 ) &
~ V_106 ;
switch ( V_94 & V_107 ) {
case V_108 :
V_100 |= V_102 ;
V_103 |= V_104 ;
V_105 |= V_106 ;
break;
case V_109 :
break;
default:
return - V_93 ;
}
switch ( V_94 & V_110 ) {
case V_111 :
V_95 |= 0x2 << 8 ;
break;
case V_112 :
break;
case V_113 :
V_95 |= 0x1 << 8 ;
break;
case V_114 :
V_95 |= 0x3 << 8 ;
break;
case V_115 :
V_95 |= 0x3 << 8 | V_98 ;
break;
default:
return - V_93 ;
}
switch ( V_94 & V_116 ) {
case V_117 :
break;
case V_118 :
V_95 |= V_98 | V_97 ;
break;
case V_119 :
V_95 |= V_97 ;
break;
case V_120 :
V_95 |= V_98 ;
break;
default:
return - V_93 ;
}
F_20 ( V_41 , V_96 , V_95 ) ;
F_20 ( V_41 , V_101 , V_100 ) ;
F_20 ( V_41 , V_88 , V_103 ) ;
F_20 ( V_41 , V_91 , V_105 ) ;
return 0 ;
}
static int F_27 ( struct V_121 * V_122 ,
struct V_123 * V_124 ,
struct V_56 * V_57 )
{
struct V_40 * V_41 = V_57 -> V_41 ;
struct V_1 * V_1 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_1 -> V_4 ;
T_1 V_95 = F_19 ( V_41 , V_96 ) &
~ V_125 ;
switch ( F_28 ( V_124 ) ) {
case 16 :
break;
case 20 :
V_95 |= 0x1 << 10 ;
break;
case 24 :
V_95 |= 0x2 << 10 ;
break;
case 32 :
V_95 |= 0x3 << 10 ;
break;
}
F_20 ( V_41 , V_96 , V_95 ) ;
if ( V_122 -> V_126 == V_127 ) {
if ( F_29 ( V_124 ) < 24000 )
F_4 ( V_4 , V_128 ,
V_129 ) ;
else
F_24 ( V_4 , V_128 ,
V_129 ) ;
}
return 0 ;
}
static int F_30 ( struct V_56 * V_130 , int V_131 )
{
struct V_40 * V_41 = V_130 -> V_41 ;
unsigned int V_8 ;
if ( V_131 )
V_8 = V_132 ;
else
V_8 = 0 ;
F_31 ( V_41 , V_133 , V_132 , V_8 ) ;
return 0 ;
}
static inline int F_32 ( struct V_134 * V_135 , unsigned int V_136 ,
unsigned int V_137 )
{
T_2 V_138 ;
unsigned int V_139 , V_140 , V_141 , V_142 ;
if ( V_137 >= 2815250 && V_137 <= 3125000 )
V_135 -> div = 0x4 ;
else if ( V_137 >= 5625000 && V_137 <= 6250000 )
V_135 -> div = 0x3 ;
else if ( V_137 >= 11250000 && V_137 <= 12500000 )
V_135 -> div = 0x2 ;
else if ( V_137 >= 22500000 && V_137 <= 25000000 )
V_135 -> div = 0x1 ;
else {
F_33 ( V_143 L_2 , V_137 ) ;
return - V_93 ;
}
if ( V_136 > 48000 )
V_135 -> V_144 = 1 ;
else
V_135 -> V_144 = 8 ;
V_139 = V_137 * ( 1 << ( V_135 -> div + 1 ) ) ;
V_140 = V_136 * V_135 -> V_144 ;
V_135 -> V_145 = V_139 / V_140 ;
V_142 = V_139 % V_140 ;
if ( V_142 ) {
V_138 = V_146 * ( long long ) V_142 ;
F_34 ( V_138 , V_140 ) ;
V_141 = V_138 & 0xFFFFFFFF ;
if ( ( V_141 % 10 ) >= 5 )
V_141 += 5 ;
V_141 /= 10 ;
V_135 -> V_147 = V_141 ;
} else
V_135 -> V_147 = 0 ;
return 0 ;
}
static int F_35 ( struct V_56 * V_57 ,
int V_148 , int V_149 , unsigned int V_150 ,
unsigned int V_151 )
{
struct V_40 * V_41 = V_57 -> V_41 ;
struct V_1 * V_152 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_152 -> V_4 ;
struct V_134 V_135 ;
int V_54 = 0 ;
T_1 V_153 , V_61 ;
if ( V_150 == V_152 -> V_154 && V_151 == V_152 -> V_155 )
return 0 ;
F_24 ( V_4 , V_156 ,
V_157 | V_158 ) ;
if ( V_151 == 0 || V_150 == 0 )
return V_54 ;
V_54 = F_32 ( & V_135 , V_150 , V_151 ) ;
if ( V_54 < 0 )
return V_54 ;
F_36 ( V_4 -> V_159 ,
L_3 ,
V_150 , V_151 , V_135 . V_145 , V_135 . V_147 , V_135 . div ,
V_135 . V_144 ) ;
V_153 = F_19 ( V_41 , V_160 ) &
~ ( V_161 | V_162 | 0xc000 ) ;
F_20 ( V_41 , V_160 ,
V_153 | ( V_135 . div << 8 ) | 0x50 ) ;
F_20 ( V_41 , V_163 ,
( V_135 . V_144 << 11 ) | ( V_135 .
V_145 & V_164 ) ) ;
F_20 ( V_41 , V_165 , V_135 . V_147 ) ;
V_61 = F_19 ( V_41 , V_69 ) &
~ ( V_166 | V_167 ) ;
F_20 ( V_41 , V_69 ,
V_61 | ( V_135 . V_147 ? V_166 : 0 ) |
( V_135 . V_144 == 8 ? V_167 : 0 ) ) ;
F_4 ( V_4 , V_156 , V_158 ) ;
F_4 ( V_4 , V_156 , V_157 ) ;
V_152 -> V_155 = V_151 ;
V_152 -> V_154 = V_150 ;
return 0 ;
}
static int F_37 ( struct V_40 * V_41 ,
enum V_168 V_169 )
{
struct V_1 * V_152 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_152 -> V_4 ;
struct V_170 * V_171 =
V_4 -> V_41 . V_172 ;
T_1 V_173 ;
int V_54 ;
switch ( V_169 ) {
case V_174 :
V_173 = F_2 ( V_4 , V_175 ) &
~ ( V_176 | V_177 ) ;
F_3 ( V_4 , V_175 ,
V_173 | V_178 |
V_171 -> V_179 << 14 ) ;
break;
case V_180 :
V_173 = F_2 ( V_4 , V_175 ) ;
V_173 &= ~ V_176 ;
F_3 ( V_4 , V_175 ,
V_173 | V_178 ) ;
break;
case V_181 :
if ( F_38 ( V_41 ) == V_182 ) {
V_54 = F_39 ( F_40 ( V_152 -> V_183 ) ,
V_152 -> V_183 ) ;
if ( V_54 != 0 )
return V_54 ;
F_4 ( V_4 , V_156 ,
V_184 ) ;
F_4 ( V_4 , V_133 ,
V_132 ) ;
F_3 ( V_4 , V_185 ,
V_171 -> V_186 |
( V_171 -> V_187 << 2 ) |
( V_171 -> V_188 << 4 ) |
( V_171 -> V_189 << 6 ) ) ;
F_8 ( F_9
( V_171 ->
V_190 ) ) ;
F_3 ( V_4 , V_185 ,
( V_171 -> V_191 << 8 ) ) ;
F_3 ( V_4 , V_175 ,
( V_171 ->
V_192 << 14 ) |
V_193 | V_194 |
V_195 ) ;
F_8 ( F_9
( V_171 ->
V_196 ) ) ;
V_173 = F_2 ( V_4 , V_175 ) &
~ ( V_176 | V_177 ) ;
V_173 |= V_197 |
( V_171 -> V_198 << 14 ) ;
F_3 ( V_4 , V_175 ,
V_173 ) ;
V_173 |= V_199 ;
F_3 ( V_4 , V_175 , V_173 ) ;
F_3 ( V_4 , V_185 , 0 ) ;
} else {
V_173 = F_2 ( V_4 , V_175 ) &
~ ( V_176 | V_177 ) ;
F_3 ( V_4 , V_175 ,
V_173 | V_197 |
( V_171 ->
V_198 << 14 ) ) ;
}
break;
case V_182 :
F_4 ( V_4 , V_133 , V_132 ) ;
F_4 ( V_4 , V_200 ,
V_201 | V_202 |
V_203 | V_204 ) ;
F_3 ( V_4 , V_185 ,
( V_171 -> V_191 << 8 ) ) ;
V_173 = F_2 ( V_4 , V_175 ) &
~ V_194 ;
F_3 ( V_4 , V_175 , V_173 ) ;
F_8 ( F_9
( V_171 ->
V_205 ) ) ;
F_3 ( V_4 , V_185 ,
( V_171 -> V_191 << 8 ) |
V_171 -> V_186 |
( V_171 -> V_187 << 2 ) |
( V_171 -> V_188 << 4 ) |
( V_171 -> V_189 << 6 ) ) ;
V_173 = F_2 ( V_4 , V_175 ) &
~ ( V_195 | V_176 ) ;
F_3 ( V_4 , V_175 ,
V_173 | V_206 ) ;
F_8 ( F_9
( V_171 -> V_207 ) ) ;
V_173 &= ~ V_199 ;
F_3 ( V_4 , V_175 , V_173 ) ;
F_3 ( V_4 , V_185 , 0 ) ;
F_24 ( V_4 , V_9 ,
V_201 ) ;
F_24 ( V_4 , V_16 ,
V_202 ) ;
F_24 ( V_4 , V_22 ,
V_203 ) ;
F_24 ( V_4 , V_24 ,
V_204 ) ;
F_24 ( V_4 , V_156 ,
V_184 ) ;
F_41 ( F_40 ( V_152 -> V_183 ) ,
V_152 -> V_183 ) ;
break;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_152 ,
struct V_208 * V_209 ,
T_1 V_210 )
{
struct V_4 * V_4 = V_152 -> V_4 ;
T_1 V_7 ;
int V_211 ;
V_7 = F_2 ( V_4 , V_212 ) ;
if ( V_7 & V_210 )
V_211 = V_209 -> V_211 ;
else
V_211 = 0 ;
F_43 ( V_209 -> V_209 , V_211 , V_209 -> V_211 ) ;
}
static void F_44 ( struct V_27 * V_28 )
{
struct V_1 * V_152 =
F_7 ( V_28 , struct V_1 , V_213 . V_28 . V_28 ) ;
F_42 ( V_152 , & V_152 -> V_213 , V_214 ) ;
}
static void F_45 ( struct V_27 * V_28 )
{
struct V_1 * V_152 =
F_7 ( V_28 , struct V_1 , V_215 . V_28 . V_28 ) ;
F_42 ( V_152 , & V_152 -> V_215 , V_216 ) ;
}
static T_3 F_46 ( int V_217 , void * V_218 )
{
struct V_1 * V_152 = V_218 ;
struct V_4 * V_4 = V_152 -> V_4 ;
#ifndef F_47
F_48 ( L_4 ) ;
#endif
if ( F_49 ( V_4 -> V_159 ) )
F_50 ( V_4 -> V_159 , 250 ) ;
F_51 ( V_219 ,
& V_152 -> V_213 . V_28 , F_9 ( 200 ) ) ;
return V_220 ;
}
static T_3 F_52 ( int V_217 , void * V_218 )
{
struct V_1 * V_152 = V_218 ;
struct V_4 * V_4 = V_152 -> V_4 ;
#ifndef F_47
F_48 ( L_5 ) ;
#endif
if ( F_49 ( V_4 -> V_159 ) )
F_50 ( V_4 -> V_159 , 250 ) ;
F_51 ( V_219 ,
& V_152 -> V_215 . V_28 , F_9 ( 200 ) ) ;
return V_220 ;
}
int F_53 ( struct V_40 * V_41 , enum V_221 V_222 ,
struct V_223 * V_209 , int V_211 )
{
struct V_1 * V_152 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_152 -> V_4 ;
int V_224 ;
switch ( V_222 ) {
case V_225 :
V_152 -> V_213 . V_209 = V_209 ;
V_152 -> V_213 . V_211 = V_211 ;
V_224 = V_226 ;
break;
case V_227 :
V_152 -> V_215 . V_209 = V_209 ;
V_152 -> V_215 . V_211 = V_211 ;
V_224 = V_228 ;
break;
default:
return - V_93 ;
}
if ( V_211 ) {
F_4 ( V_4 , V_156 , V_229 ) ;
F_4 ( V_4 , V_230 , V_224 ) ;
} else {
F_24 ( V_4 , V_230 , V_224 ) ;
}
switch ( V_222 ) {
case V_225 :
F_46 ( 0 , V_152 ) ;
break;
case V_227 :
F_52 ( 0 , V_152 ) ;
break;
}
return 0 ;
}
static T_3 F_54 ( int V_217 , void * V_218 )
{
struct V_1 * V_152 = V_218 ;
struct V_4 * V_4 = V_152 -> V_4 ;
T_1 V_7 ;
int V_211 = 0 ;
#ifndef F_47
F_48 ( L_6 ) ;
#endif
V_7 = F_2 ( V_4 , V_212 ) ;
if ( V_7 & V_231 )
V_211 |= V_152 -> V_232 . V_233 ;
if ( V_7 & V_234 )
V_211 |= V_152 -> V_232 . V_211 ;
F_43 ( V_152 -> V_232 . V_209 , V_211 ,
V_152 -> V_232 . V_211 | V_152 -> V_232 . V_233 ) ;
return V_220 ;
}
int F_55 ( struct V_40 * V_41 ,
struct V_223 * V_209 ,
int V_235 , int V_233 )
{
struct V_1 * V_152 = F_13 ( V_41 ) ;
struct V_4 * V_4 = V_152 -> V_4 ;
V_152 -> V_232 . V_209 = V_209 ;
V_152 -> V_232 . V_211 = V_235 ;
V_152 -> V_232 . V_233 = V_233 ;
if ( V_235 || V_233 ) {
F_4 ( V_4 , V_156 , V_229 ) ;
F_4 ( V_4 , V_175 ,
V_236 ) ;
} else {
F_24 ( V_4 , V_175 ,
V_236 ) ;
}
return 0 ;
}
static int F_56 ( struct V_40 * V_41 )
{
struct V_4 * V_4 = F_57 ( V_41 -> V_159 ) ;
struct V_1 * V_152 ;
struct V_2 * V_3 ;
struct V_2 * V_21 ;
int V_54 , V_30 ;
if ( V_4 -> V_41 . V_172 == NULL ) {
F_58 ( V_41 -> V_159 , L_7 ) ;
return - V_93 ;
}
V_152 = F_59 ( V_41 -> V_159 , sizeof( struct V_1 ) ,
V_237 ) ;
if ( V_152 == NULL )
return - V_238 ;
F_60 ( V_41 , V_152 ) ;
V_152 -> V_4 = V_4 ;
for ( V_30 = 0 ; V_30 < F_40 ( V_239 ) ; V_30 ++ )
V_152 -> V_183 [ V_30 ] . V_240 = V_239 [ V_30 ] ;
V_54 = F_61 ( V_4 -> V_159 , F_40 ( V_152 -> V_183 ) ,
V_152 -> V_183 ) ;
if ( V_54 != 0 )
return V_54 ;
F_24 ( V_4 , V_241 , V_242 ) ;
F_62 ( & V_152 -> V_29 , F_6 ) ;
F_62 ( & V_152 -> V_213 . V_28 , F_44 ) ;
F_62 ( & V_152 -> V_215 . V_28 , F_45 ) ;
F_4 ( V_4 , V_241 , V_242 ) ;
F_20 ( V_41 , V_243 , 0xa7 ) ;
F_20 ( V_41 , 0xde , 0x13 ) ;
F_20 ( V_41 , V_243 , 0 ) ;
V_3 = & V_152 -> V_3 ;
V_21 = & V_152 -> V_21 ;
V_3 -> V_14 = ( F_2 ( V_4 , V_9 ) &
V_10 ) >> V_11 ;
V_3 -> V_19 = ( F_2 ( V_4 , V_16 ) &
V_17 ) >> V_18 ;
V_21 -> V_14 = ( F_2 ( V_4 , V_22 ) &
V_23 ) >> V_11 ;
V_21 -> V_19 = ( F_2 ( V_4 , V_24 ) &
V_25 ) >> V_18 ;
F_3 ( V_4 , V_9 , 0 ) ;
F_3 ( V_4 , V_16 , 0 ) ;
F_3 ( V_4 , V_22 , 0 ) ;
F_3 ( V_4 , V_24 , 0 ) ;
F_4 ( V_4 , V_9 ,
V_20 | V_244 ) ;
F_4 ( V_4 , V_22 ,
V_26 | V_245 ) ;
F_4 ( V_4 , V_16 ,
V_20 | V_246 ) ;
F_4 ( V_4 , V_24 ,
V_26 | V_247 ) ;
F_24 ( V_4 , V_96 , V_248 ) ;
F_24 ( V_4 , V_249 ,
V_250 | V_251 ) ;
F_24 ( V_4 , V_230 ,
V_226 | V_228 ) ;
F_63 ( V_4 , V_252 ,
F_46 , 0 , L_8 ,
V_152 ) ;
F_63 ( V_4 , V_253 ,
F_52 , 0 , L_9 ,
V_152 ) ;
F_63 ( V_4 , V_254 ,
F_54 , 0 , L_10 , V_152 ) ;
F_63 ( V_4 , V_255 ,
F_54 , 0 , L_11 , V_152 ) ;
return 0 ;
}
static int F_64 ( struct V_40 * V_41 )
{
struct V_1 * V_152 = F_13 ( V_41 ) ;
struct V_4 * V_4 = F_57 ( V_41 -> V_159 ) ;
F_24 ( V_4 , V_230 ,
V_226 | V_228 ) ;
F_24 ( V_4 , V_156 , V_229 ) ;
F_65 ( V_4 , V_255 , V_152 ) ;
F_65 ( V_4 , V_254 , V_152 ) ;
F_65 ( V_4 , V_252 , V_152 ) ;
F_65 ( V_4 , V_253 , V_152 ) ;
V_152 -> V_213 . V_209 = NULL ;
V_152 -> V_215 . V_209 = NULL ;
V_152 -> V_232 . V_209 = NULL ;
F_66 ( & V_152 -> V_213 . V_28 ) ;
F_66 ( & V_152 -> V_215 . V_28 ) ;
F_67 ( & V_152 -> V_29 ) ;
F_24 ( V_4 , V_241 , V_242 ) ;
return 0 ;
}
static struct V_256 * F_68 ( struct V_257 * V_159 )
{
struct V_4 * V_4 = F_57 ( V_159 ) ;
return V_4 -> V_256 ;
}
static int F_69 ( struct V_258 * V_259 )
{
return F_70 ( & V_259 -> V_159 , & V_260 ,
& V_261 , 1 ) ;
}
static int F_71 ( struct V_258 * V_259 )
{
F_72 ( & V_259 -> V_159 ) ;
return 0 ;
}
