static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 = F_2 ( V_2 ) ;
switch ( V_2 -> V_5 . V_6 [ V_4 ] . V_7 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
V_3 = V_12 ;
break;
case V_13 :
V_3 = V_14 ;
break;
case V_15 :
V_3 = V_16 ;
break;
case V_17 :
V_3 = V_18 ;
break;
case V_19 :
default:
V_3 = V_20 ;
break;
}
return V_3 ;
}
static int F_3 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_25 = F_5 ( V_2 ) ;
V_24 -> V_26 = V_2 -> V_27 . V_26 [ V_25 ] |
( V_2 -> V_27 . V_26 [ V_25 ^ 1 ] &
( V_28 | V_29 ) ) ;
V_24 -> V_30 = V_2 -> V_27 . V_30 [ V_25 ] ;
if ( ( V_2 -> V_31 == V_32 ) && ( V_2 -> V_33 . V_34 ) ) {
if ( ! ( V_2 -> V_35 & V_36 ) ) {
F_6 ( V_24 , V_2 -> V_33 . V_37 ) ;
V_24 -> V_38 = V_2 -> V_33 . V_38 ;
} else {
F_6 (
V_24 , V_2 -> V_5 . V_39 [ V_25 ] ) ;
V_24 -> V_38 = V_2 -> V_5 . V_40 [ V_25 ] ;
}
if ( F_7 ( V_2 ) && ! F_8 ( V_2 ) )
F_6 ( V_24 , F_9 ( V_2 ) ) ;
} else {
V_24 -> V_38 = V_41 ;
F_6 ( V_24 , V_42 ) ;
}
V_24 -> V_27 = F_1 ( V_2 ) ;
V_24 -> V_43 = V_2 -> V_44 . V_45 ;
V_24 -> V_46 = V_47 ;
if ( V_2 -> V_5 . V_39 [ V_25 ] == V_48 )
V_24 -> V_49 = V_50 ;
else
V_24 -> V_49 = V_51 ;
if ( V_2 -> V_33 . V_52 & V_53 ) {
T_1 V_54 = V_2 -> V_33 . V_52 ;
V_24 -> V_55 |= V_56 ;
if ( V_54 & V_57 )
V_24 -> V_55 |= V_58 ;
if ( V_54 & V_59 )
V_24 -> V_55 |= V_60 ;
if ( V_54 & V_61 )
V_24 -> V_55 |= V_62 ;
if ( V_54 & V_63 )
V_24 -> V_55 |= V_64 ;
if ( V_54 & V_65 )
V_24 -> V_55 |= V_66 ;
if ( V_54 & V_67 )
V_24 -> V_55 |= V_68 ;
if ( V_54 & V_69 )
V_24 -> V_55 |= V_70 ;
if ( V_54 & V_71 )
V_24 -> V_55 |= V_72 ;
if ( V_54 & V_73 )
V_24 -> V_55 |= V_74 ;
if ( V_54 & V_75 )
V_24 -> V_55 |= V_76 ;
}
V_24 -> V_77 = 0 ;
V_24 -> V_78 = 0 ;
F_10 ( V_79 , L_1
L_2
L_3
L_4 ,
V_24 -> V_24 , V_24 -> V_26 , V_24 -> V_30 ,
F_11 ( V_24 ) ,
V_24 -> V_38 , V_24 -> V_27 , V_24 -> V_43 , V_24 -> V_46 ,
V_24 -> V_49 , V_24 -> V_77 , V_24 -> V_78 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_1 V_30 , V_25 , V_80 , V_81 ;
T_1 V_82 ;
if ( F_13 ( V_2 ) )
return 0 ;
F_10 ( V_79 , L_1
L_2
L_3
L_4 ,
V_24 -> V_24 , V_24 -> V_26 , V_24 -> V_30 ,
F_11 ( V_24 ) ,
V_24 -> V_38 , V_24 -> V_27 , V_24 -> V_43 , V_24 -> V_46 ,
V_24 -> V_49 , V_24 -> V_77 , V_24 -> V_78 ) ;
V_82 = F_11 ( V_24 ) ;
if ( V_24 -> V_38 == V_41 )
V_24 -> V_38 = V_83 ;
if ( F_14 ( V_2 ) ) {
T_1 V_84 ;
T_1 V_37 = V_2 -> V_33 . V_37 ;
if ( ! V_37 )
V_37 = 10000 ;
if ( V_2 -> V_85 . V_86 < V_87 ) {
F_10 ( V_79 ,
L_5 ,
V_87 ) ;
return - V_88 ;
}
V_84 = ( V_82 * 100 ) / V_37 ;
if ( V_37 < V_82 || ! V_84 ) {
F_10 ( V_79 ,
L_6 ) ;
return - V_88 ;
}
if ( V_2 -> V_31 != V_32 )
V_2 -> V_89 = V_84 ;
else
F_15 ( V_2 , V_84 ) ;
return 0 ;
}
V_25 = F_5 ( V_2 ) ;
V_80 = V_2 -> V_5 . V_90 ;
switch ( V_24 -> V_27 ) {
case V_16 :
if ( V_2 -> V_27 . V_26 [ V_25 ] & V_28 )
break;
if ( ! ( V_2 -> V_27 . V_26 [ 0 ] & V_28 ||
V_2 -> V_27 . V_26 [ 1 ] & V_28 ) ) {
F_10 ( V_79 , L_7 ) ;
return - V_88 ;
}
V_2 -> V_5 . V_90 &=
~ V_91 ;
if ( V_2 -> V_5 . V_90 &
V_92 )
V_2 -> V_5 . V_90 |=
V_93 ;
else
V_2 -> V_5 . V_90 |=
V_94 ;
break;
case V_12 :
case V_14 :
if ( V_2 -> V_27 . V_26 [ V_25 ] & V_29 )
break;
if ( ! ( V_2 -> V_27 . V_26 [ 0 ] & V_29 ||
V_2 -> V_27 . V_26 [ 1 ] & V_29 ) ) {
F_10 ( V_79 , L_7 ) ;
return - V_88 ;
}
V_2 -> V_5 . V_90 &=
~ V_91 ;
if ( V_2 -> V_5 . V_90 &
V_92 )
V_2 -> V_5 . V_90 |=
V_94 ;
else
V_2 -> V_5 . V_90 |=
V_93 ;
break;
default:
F_10 ( V_79 , L_7 ) ;
return - V_88 ;
}
V_81 = V_2 -> V_5 . V_90 ;
V_25 = F_5 ( V_2 ) ;
V_2 -> V_5 . V_90 = V_80 ;
F_10 ( V_79 , L_8 , V_25 ) ;
if ( V_24 -> V_49 == V_50 ) {
T_1 V_95 = V_2 -> V_27 . V_26 [ V_25 ] ;
if ( V_2 -> V_5 . V_6 [ V_96 ] . type ==
V_97 )
V_95 |= ( V_98 |
V_99 ) ;
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] & V_100 ) ) {
F_10 ( V_79 , L_9 ) ;
return - V_88 ;
}
if ( V_24 -> V_30 & ~ V_95 ) {
F_10 ( V_79 ,
L_10 ) ;
return - V_88 ;
}
V_2 -> V_5 . V_39 [ V_25 ] = V_48 ;
V_2 -> V_5 . V_40 [ V_25 ] = V_24 -> V_38 ;
V_2 -> V_27 . V_30 [ V_25 ] = ( V_56 |
V_24 -> V_30 ) ;
if ( V_24 -> V_30 ) {
V_2 -> V_5 . V_101 [ V_25 ] = 0 ;
if ( V_24 -> V_30 & V_62 ) {
V_2 -> V_5 . V_101 [ V_25 ] |=
V_102 ;
}
if ( V_24 -> V_30 & V_64 )
V_2 -> V_5 . V_101 [ V_25 ] |=
V_103 ;
if ( V_24 -> V_30 & V_68 )
V_2 -> V_5 . V_101 [ V_25 ] |=
V_104 ;
if ( V_24 -> V_30 & V_66 ) {
V_2 -> V_5 . V_101 [ V_25 ] |=
V_105 ;
}
if ( V_24 -> V_30 & V_70 ) {
V_2 -> V_5 . V_101 [ V_25 ] |=
V_106 ;
}
if ( V_24 -> V_30 & ( V_72 |
V_107 ) )
V_2 -> V_5 . V_101 [ V_25 ] |=
V_106 ;
if ( V_24 -> V_30 & ( V_76 |
V_108 |
V_109 ) )
V_2 -> V_5 . V_101 [ V_25 ] |=
V_110 ;
}
} else {
switch ( V_82 ) {
case V_111 :
if ( V_24 -> V_38 == V_83 ) {
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] &
V_112 ) ) {
F_10 ( V_79 ,
L_11 ) ;
return - V_88 ;
}
V_30 = ( V_64 |
V_113 ) ;
} else {
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] &
V_114 ) ) {
F_10 ( V_79 ,
L_12 ) ;
return - V_88 ;
}
V_30 = ( V_62 |
V_113 ) ;
}
break;
case V_115 :
if ( V_24 -> V_38 == V_83 ) {
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] &
V_99 ) ) {
F_10 ( V_79 ,
L_13 ) ;
return - V_88 ;
}
V_30 = ( V_68 |
V_113 ) ;
} else {
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] &
V_98 ) ) {
F_10 ( V_79 ,
L_14 ) ;
return - V_88 ;
}
V_30 = ( V_66 |
V_113 ) ;
}
break;
case V_116 :
if ( V_24 -> V_38 != V_83 ) {
F_10 ( V_79 ,
L_15 ) ;
return - V_88 ;
}
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] &
V_117 ) ) {
F_10 ( V_79 ,
L_16 ) ;
return - V_88 ;
}
V_30 = ( V_72 |
V_113 ) ;
break;
case V_118 :
if ( V_24 -> V_38 != V_83 ) {
F_10 ( V_79 ,
L_17 ) ;
return - V_88 ;
}
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ]
& V_119 ) ) {
F_10 ( V_79 ,
L_18 ) ;
return - V_88 ;
}
V_30 = ( V_74 |
V_113 ) ;
break;
case V_120 :
if ( V_24 -> V_38 != V_83 ) {
F_10 ( V_79 ,
L_19 ) ;
return - V_88 ;
}
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ]
& V_121 ) ) {
F_10 ( V_79 ,
L_20 ) ;
return - V_88 ;
}
V_30 = ( V_76 |
V_122 ) ;
break;
default:
F_10 ( V_79 , L_21 , V_82 ) ;
return - V_88 ;
}
V_2 -> V_5 . V_39 [ V_25 ] = V_82 ;
V_2 -> V_5 . V_40 [ V_25 ] = V_24 -> V_38 ;
V_2 -> V_27 . V_30 [ V_25 ] = V_30 ;
}
F_10 ( V_79 , L_22
L_23 ,
V_2 -> V_5 . V_39 [ V_25 ] ,
V_2 -> V_5 . V_40 [ V_25 ] ,
V_2 -> V_27 . V_30 [ V_25 ] ) ;
V_2 -> V_5 . V_90 = V_81 ;
if ( F_16 ( V_22 ) ) {
F_17 ( V_2 , V_123 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static inline bool F_19 ( struct V_1 * V_2 ,
const struct V_124 * V_125 )
{
if ( F_20 ( V_2 ) )
return F_21 ( V_125 -> V_126 ) ;
else if ( F_22 ( V_2 ) )
return F_23 ( V_125 -> V_126 ) ;
else if ( F_24 ( V_2 ) )
return F_25 ( V_125 -> V_126 ) ;
else if ( F_26 ( V_2 ) )
return F_27 ( V_125 -> V_126 ) ;
else if ( F_28 ( V_2 ) )
return F_29 ( V_125 -> V_126 ) ;
else
return false ;
}
static inline const T_1 * F_30 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_127 ;
else if ( F_31 ( V_2 ) )
return V_128 ;
else
return NULL ;
}
static inline T_1 F_32 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_129 ;
else if ( F_31 ( V_2 ) )
return V_130 ;
else
return 0 ;
}
static inline const T_1 * F_33 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_131 ;
else if ( F_31 ( V_2 ) )
return V_132 ;
else
return NULL ;
}
static inline T_1 F_34 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_133 ;
else if ( F_31 ( V_2 ) )
return V_134 ;
else
return 0 ;
}
static inline const struct V_124 * F_35 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_135 ;
else if ( F_31 ( V_2 ) )
return V_136 ;
else
return NULL ;
}
static inline T_1 F_36 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return V_137 ;
else if ( F_31 ( V_2 ) )
return V_138 ;
else
return 0 ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
int V_139 = F_32 ( V_2 ) ;
int V_140 = F_34 ( V_2 ) ;
const struct V_124 * V_141 = F_35 ( V_2 ) ;
int V_142 = F_36 ( V_2 ) ;
int V_143 = 0 ;
int V_144 , V_145 , V_146 ;
for ( V_144 = 0 ; V_144 < V_147 ; V_144 ++ )
if ( F_19 ( V_2 , & V_148 [ V_144 ] ) )
V_143 += V_148 [ V_144 ] . V_149 ;
for ( V_144 = 0 ; V_144 < V_139 ; V_144 ++ )
for ( V_145 = 0 ; V_145 < V_140 ; V_145 ++ )
for ( V_146 = 0 ; V_146 < V_142 ; V_146 ++ )
if ( F_19 ( V_2 , & V_141 [ V_146 ] ) )
V_143 += V_141 [ V_146 ] . V_149 ;
return V_143 ;
}
static int F_38 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_143 = 0 ;
V_143 = F_37 ( V_2 ) ;
V_143 *= 4 ;
V_143 += sizeof( struct V_150 ) ;
return V_143 ;
}
static inline void F_39 ( struct V_1 * V_2 , T_1 * V_151 )
{
T_1 V_144 , V_145 , V_146 , V_152 ;
const T_1 * V_153 = F_30 ( V_2 ) ;
int V_139 = F_32 ( V_2 ) ;
const T_1 * V_154 = F_33 ( V_2 ) ;
int V_155 = F_34 ( V_2 ) ;
const struct V_124 * V_156 = F_35 ( V_2 ) ;
int V_157 = F_36 ( V_2 ) ;
for ( V_144 = 0 ; V_144 < V_139 ; V_144 ++ ) {
for ( V_145 = 0 ; V_145 < V_155 ; V_145 ++ ) {
F_40 ( V_2 , V_154 [ V_145 ] , V_153 [ V_144 ] ) ;
for ( V_146 = 0 ; V_146 < V_157 ; V_146 ++ )
if ( F_19 ( V_2 , & V_156 [ V_146 ] ) )
for ( V_152 = 0 ; V_152 <
V_156 [ V_146 ] . V_149 ; V_152 ++ )
* V_151 ++ = F_41 ( V_2 ,
V_156 [ V_146 ] . V_158 + V_152 * 4 ) ;
}
}
}
static inline void F_42 ( struct V_1 * V_2 , T_1 * V_151 )
{
T_1 V_144 , V_145 ;
for ( V_144 = 0 ; V_144 < V_147 ; V_144 ++ )
if ( F_19 ( V_2 , & V_148 [ V_144 ] ) )
for ( V_145 = 0 ; V_145 < V_148 [ V_144 ] . V_149 ; V_145 ++ )
* V_151 ++ = F_41 ( V_2 , V_148 [ V_144 ] . V_158 + V_145 * 4 ) ;
F_39 ( V_2 , V_151 ) ;
}
static void F_43 ( struct V_21 * V_22 ,
struct V_159 * V_160 , void * V_161 )
{
T_1 * V_151 = V_161 ;
struct V_1 * V_2 = F_4 ( V_22 ) ;
struct V_150 V_150 = { 0 } ;
V_160 -> V_162 = 0 ;
memset ( V_151 , 0 , V_160 -> V_163 ) ;
if ( ! F_16 ( V_2 -> V_22 ) )
return;
F_44 ( V_2 ) ;
V_150 . V_164 = ( sizeof( struct V_150 ) / 4 ) - 1 ;
V_150 . V_165 = V_166 ;
V_150 . V_167 = F_41 ( V_2 , V_168 ) ;
V_150 . V_169 = F_41 ( V_2 , V_170 ) ;
V_150 . V_171 = F_41 ( V_2 , V_172 ) ;
V_150 . V_173 = F_41 ( V_2 , V_174 ) ;
if ( F_20 ( V_2 ) )
V_150 . V_126 = V_175 ;
else if ( F_22 ( V_2 ) )
V_150 . V_126 = V_176 ;
else if ( ! F_45 ( V_2 ) )
V_150 . V_126 = V_177 |
( F_46 ( V_2 ) ? V_178 : V_179 ) ;
memcpy ( V_151 , & V_150 , sizeof( struct V_150 ) ) ;
V_151 += V_150 . V_164 + 1 ;
F_42 ( V_2 , V_151 ) ;
F_47 ( V_2 ) ;
F_48 ( V_2 ) ;
}
static void F_49 ( struct V_21 * V_22 ,
struct V_180 * V_126 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_2 V_181 [ V_182 ] ;
F_50 ( V_126 -> V_183 , V_184 , sizeof( V_126 -> V_183 ) ) ;
F_50 ( V_126 -> V_162 , V_185 , sizeof( V_126 -> V_162 ) ) ;
V_181 [ 0 ] = '\0' ;
F_51 ( & V_2 -> V_5 ,
V_181 , V_182 ) ;
F_50 ( V_126 -> V_186 , V_2 -> V_187 , sizeof( V_126 -> V_186 ) ) ;
snprintf ( V_126 -> V_186 + strlen ( V_2 -> V_187 ) , 32 - strlen ( V_2 -> V_187 ) ,
L_24 ,
( V_2 -> V_85 . V_86 & 0xff0000 ) >> 16 ,
( V_2 -> V_85 . V_86 & 0xff00 ) >> 8 ,
( V_2 -> V_85 . V_86 & 0xff ) ,
( ( V_181 [ 0 ] != '\0' ) ? L_25 : L_26 ) , V_181 ) ;
F_50 ( V_126 -> V_188 , F_52 ( V_2 -> V_189 ) , sizeof( V_126 -> V_188 ) ) ;
V_126 -> V_190 = V_191 ;
V_126 -> V_192 = V_193 ;
V_126 -> V_194 = V_2 -> V_85 . V_195 ;
V_126 -> V_143 = F_38 ( V_22 ) ;
}
static void F_53 ( struct V_21 * V_22 , struct V_196 * V_197 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( V_2 -> V_35 & V_198 ) {
V_197 -> V_26 = 0 ;
V_197 -> V_199 = 0 ;
} else {
V_197 -> V_26 = V_200 ;
if ( V_2 -> V_197 )
V_197 -> V_199 = V_200 ;
else
V_197 -> V_199 = 0 ;
}
memset ( & V_197 -> V_201 , 0 , sizeof( V_197 -> V_201 ) ) ;
}
static int F_54 ( struct V_21 * V_22 , struct V_196 * V_197 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( V_197 -> V_199 & ~ V_200 ) {
F_10 ( V_79 , L_27 ) ;
return - V_88 ;
}
if ( V_197 -> V_199 & V_200 ) {
if ( V_2 -> V_35 & V_198 ) {
F_10 ( V_79 , L_27 ) ;
return - V_88 ;
}
V_2 -> V_197 = 1 ;
} else
V_2 -> V_197 = 0 ;
return 0 ;
}
static T_1 F_55 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
return V_2 -> V_202 ;
}
static void F_56 ( struct V_21 * V_22 , T_1 V_203 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( F_57 ( V_204 ) ) {
if ( V_203 & V_205 )
F_58 ( V_2 , V_206 ) ;
V_2 -> V_202 = V_203 ;
}
}
static int F_59 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( ! V_2 -> V_27 . V_207 )
return 0 ;
if ( F_16 ( V_22 ) ) {
F_17 ( V_2 , V_123 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static T_1 F_60 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( V_2 -> V_35 & V_36 || ( V_2 -> V_31 != V_32 ) )
return 0 ;
return V_2 -> V_33 . V_34 ;
}
static int F_61 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
return V_2 -> V_85 . V_195 ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_27 = F_63 ( V_2 ) ;
int V_208 , V_144 ;
T_1 V_209 ;
F_64 ( V_2 , V_210 ) ;
V_208 = V_211 ;
if ( F_65 ( V_2 ) )
V_208 *= 100 ;
F_40 ( V_2 , V_212 ,
( V_213 << V_27 ) ) ;
for ( V_144 = 0 ; V_144 < V_208 * 10 ; V_144 ++ ) {
V_209 = F_41 ( V_2 , V_212 ) ;
if ( V_209 & ( V_214 << V_27 ) )
break;
F_66 ( 5 ) ;
}
if ( ! ( V_209 & ( V_214 << V_27 ) ) ) {
F_10 ( V_79 | V_215 ,
L_28 ) ;
return - V_216 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_27 = F_63 ( V_2 ) ;
int V_208 , V_144 ;
T_1 V_209 ;
V_208 = V_211 ;
if ( F_65 ( V_2 ) )
V_208 *= 100 ;
F_40 ( V_2 , V_212 ,
( V_217 << V_27 ) ) ;
for ( V_144 = 0 ; V_144 < V_208 * 10 ; V_144 ++ ) {
V_209 = F_41 ( V_2 , V_212 ) ;
if ( ! ( V_209 & ( V_214 << V_27 ) ) )
break;
F_66 ( 5 ) ;
}
if ( V_209 & ( V_214 << V_27 ) ) {
F_10 ( V_79 | V_215 ,
L_29 ) ;
return - V_216 ;
}
F_68 ( V_2 , V_210 ) ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 )
{
T_1 V_209 ;
V_209 = F_41 ( V_2 , V_218 ) ;
F_40 ( V_2 , V_218 ,
( V_209 | V_219 |
V_220 ) ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
T_1 V_209 ;
V_209 = F_41 ( V_2 , V_218 ) ;
F_40 ( V_2 , V_218 ,
( V_209 & ~ ( V_219 |
V_220 ) ) ) ;
}
static int F_71 ( struct V_1 * V_2 , T_1 V_221 , T_3 * V_222 ,
T_1 V_223 )
{
int V_208 , V_144 , V_224 ;
T_1 V_209 ;
V_223 |= V_225 ;
F_40 ( V_2 , V_226 , V_227 ) ;
F_40 ( V_2 , V_228 ,
( V_221 & V_229 ) ) ;
F_40 ( V_2 , V_226 , V_223 ) ;
V_208 = V_211 ;
if ( F_65 ( V_2 ) )
V_208 *= 100 ;
* V_222 = 0 ;
V_224 = - V_216 ;
for ( V_144 = 0 ; V_144 < V_208 ; V_144 ++ ) {
F_66 ( 5 ) ;
V_209 = F_41 ( V_2 , V_226 ) ;
if ( V_209 & V_227 ) {
V_209 = F_41 ( V_2 , V_230 ) ;
* V_222 = F_72 ( V_209 ) ;
V_224 = 0 ;
break;
}
}
if ( V_224 == - V_216 )
F_10 ( V_79 | V_215 ,
L_30 ) ;
return V_224 ;
}
static int F_73 ( struct V_1 * V_2 , T_1 V_221 , T_2 * V_231 ,
int V_232 )
{
int V_224 ;
T_1 V_223 ;
T_3 V_209 ;
if ( ( V_221 & 0x03 ) || ( V_232 & 0x03 ) || ( V_232 == 0 ) ) {
F_10 ( V_79 | V_215 ,
L_31 ,
V_221 , V_232 ) ;
return - V_88 ;
}
if ( V_221 + V_232 > V_2 -> V_85 . V_195 ) {
F_10 ( V_79 | V_215 ,
L_32 ,
V_221 , V_232 , V_2 -> V_85 . V_195 ) ;
return - V_88 ;
}
V_224 = F_62 ( V_2 ) ;
if ( V_224 )
return V_224 ;
F_69 ( V_2 ) ;
V_223 = V_233 ;
while ( ( V_232 > sizeof( T_1 ) ) && ( V_224 == 0 ) ) {
V_224 = F_71 ( V_2 , V_221 , & V_209 , V_223 ) ;
memcpy ( V_231 , & V_209 , 4 ) ;
V_221 += sizeof( T_1 ) ;
V_231 += sizeof( T_1 ) ;
V_232 -= sizeof( T_1 ) ;
V_223 = 0 ;
}
if ( V_224 == 0 ) {
V_223 |= V_234 ;
V_224 = F_71 ( V_2 , V_221 , & V_209 , V_223 ) ;
memcpy ( V_231 , & V_209 , 4 ) ;
}
F_70 ( V_2 ) ;
F_67 ( V_2 ) ;
return V_224 ;
}
static int F_74 ( struct V_21 * V_22 ,
struct V_235 * V_236 , T_2 * V_237 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_224 ;
if ( ! F_16 ( V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return - V_238 ;
}
F_10 ( V_79 | V_215 , L_34
L_35 ,
V_236 -> V_24 , V_236 -> V_239 , V_236 -> V_221 , V_236 -> V_221 ,
V_236 -> V_163 , V_236 -> V_163 ) ;
V_224 = F_73 ( V_2 , V_236 -> V_221 , V_237 , V_236 -> V_163 ) ;
return V_224 ;
}
static int F_75 ( struct V_1 * V_2 , T_1 V_221 , T_1 V_209 ,
T_1 V_223 )
{
int V_208 , V_144 , V_224 ;
V_223 |= V_225 | V_240 ;
F_40 ( V_2 , V_226 , V_227 ) ;
F_40 ( V_2 , V_241 , V_209 ) ;
F_40 ( V_2 , V_228 ,
( V_221 & V_229 ) ) ;
F_40 ( V_2 , V_226 , V_223 ) ;
V_208 = V_211 ;
if ( F_65 ( V_2 ) )
V_208 *= 100 ;
V_224 = - V_216 ;
for ( V_144 = 0 ; V_144 < V_208 ; V_144 ++ ) {
F_66 ( 5 ) ;
V_209 = F_41 ( V_2 , V_226 ) ;
if ( V_209 & V_227 ) {
V_224 = 0 ;
break;
}
}
if ( V_224 == - V_216 )
F_10 ( V_79 | V_215 ,
L_36 ) ;
return V_224 ;
}
static int F_76 ( struct V_1 * V_2 , T_1 V_221 , T_2 * V_242 ,
int V_232 )
{
int V_224 ;
T_1 V_223 ;
T_1 V_243 ;
T_3 V_209 ;
if ( V_221 + V_232 > V_2 -> V_85 . V_195 ) {
F_10 ( V_79 | V_215 ,
L_32 ,
V_221 , V_232 , V_2 -> V_85 . V_195 ) ;
return - V_88 ;
}
V_224 = F_62 ( V_2 ) ;
if ( V_224 )
return V_224 ;
F_69 ( V_2 ) ;
V_223 = ( V_233 | V_234 ) ;
V_243 = ( V_221 & ~ 0x03 ) ;
V_224 = F_71 ( V_2 , V_243 , & V_209 , V_223 ) ;
if ( V_224 == 0 ) {
V_209 &= ~ ( 0xff << F_77 ( V_221 ) ) ;
V_209 |= ( * V_242 << F_77 ( V_221 ) ) ;
V_209 = F_78 ( V_209 ) ;
V_224 = F_75 ( V_2 , V_243 , V_209 ,
V_223 ) ;
}
F_70 ( V_2 ) ;
F_67 ( V_2 ) ;
return V_224 ;
}
static int F_79 ( struct V_1 * V_2 , T_1 V_221 , T_2 * V_242 ,
int V_232 )
{
int V_224 ;
T_1 V_223 ;
T_1 V_209 ;
T_1 V_244 ;
if ( V_232 == 1 )
return F_76 ( V_2 , V_221 , V_242 , V_232 ) ;
if ( ( V_221 & 0x03 ) || ( V_232 & 0x03 ) || ( V_232 == 0 ) ) {
F_10 ( V_79 | V_215 ,
L_31 ,
V_221 , V_232 ) ;
return - V_88 ;
}
if ( V_221 + V_232 > V_2 -> V_85 . V_195 ) {
F_10 ( V_79 | V_215 ,
L_32 ,
V_221 , V_232 , V_2 -> V_85 . V_195 ) ;
return - V_88 ;
}
V_224 = F_62 ( V_2 ) ;
if ( V_224 )
return V_224 ;
F_69 ( V_2 ) ;
V_244 = 0 ;
V_223 = V_233 ;
while ( ( V_244 < V_232 ) && ( V_224 == 0 ) ) {
if ( V_244 == ( V_232 - sizeof( T_1 ) ) )
V_223 |= V_234 ;
else if ( ( ( V_221 + 4 ) % V_245 ) == 0 )
V_223 |= V_234 ;
else if ( ( V_221 % V_245 ) == 0 )
V_223 |= V_233 ;
memcpy ( & V_209 , V_242 , 4 ) ;
V_224 = F_75 ( V_2 , V_221 , V_209 , V_223 ) ;
V_221 += sizeof( T_1 ) ;
V_242 += sizeof( T_1 ) ;
V_244 += sizeof( T_1 ) ;
V_223 = 0 ;
}
F_70 ( V_2 ) ;
F_67 ( V_2 ) ;
return V_224 ;
}
static int F_80 ( struct V_21 * V_22 ,
struct V_235 * V_236 , T_2 * V_237 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_27 = F_63 ( V_2 ) ;
int V_224 = 0 ;
T_1 V_246 ;
if ( ! F_16 ( V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return - V_238 ;
}
F_10 ( V_79 | V_215 , L_34
L_35 ,
V_236 -> V_24 , V_236 -> V_239 , V_236 -> V_221 , V_236 -> V_221 ,
V_236 -> V_163 , V_236 -> V_163 ) ;
if ( ( V_236 -> V_239 >= 0x50485900 ) && ( V_236 -> V_239 <= 0x504859FF ) &&
! V_2 -> V_27 . V_207 ) {
F_10 ( V_79 | V_215 ,
L_37 ) ;
return - V_88 ;
}
V_246 =
F_81 ( V_2 ,
V_247 . V_248 [ V_27 ] . V_249 ) ;
if ( V_236 -> V_239 == 0x50485950 ) {
F_17 ( V_2 , V_123 ) ;
F_82 ( V_2 ) ;
V_224 |= F_83 ( & V_2 -> V_5 ,
& V_2 -> V_33 , 0 ) ;
if ( F_84 ( V_246 ) ==
V_250 )
F_85 ( V_2 , V_251 ,
V_252 , V_27 ) ;
F_86 ( V_2 ) ;
F_87 ( V_2 ) ;
} else if ( V_236 -> V_239 == 0x50485952 ) {
if ( V_2 -> V_31 == V_32 ) {
F_82 ( V_2 ) ;
V_224 |= F_83 ( & V_2 -> V_5 ,
& V_2 -> V_33 , 1 ) ;
V_224 |= F_88 ( & V_2 -> V_5 ,
& V_2 -> V_33 ) ;
F_86 ( V_2 ) ;
F_89 ( V_2 ) ;
}
} else if ( V_236 -> V_239 == 0x53985943 ) {
if ( F_84 ( V_246 ) ==
V_250 ) {
F_85 ( V_2 , V_251 ,
V_253 , V_27 ) ;
F_82 ( V_2 ) ;
F_90 ( V_2 ,
& V_2 -> V_5 . V_6 [ V_96 ] ) ;
F_91 ( 500 ) ;
F_92 ( V_2 , V_27 ) ;
F_91 ( 500 ) ;
F_86 ( V_2 ) ;
}
} else
V_224 = F_79 ( V_2 , V_236 -> V_221 , V_237 , V_236 -> V_163 ) ;
return V_224 ;
}
static int F_93 ( struct V_21 * V_22 ,
struct V_254 * V_255 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
memset ( V_255 , 0 , sizeof( struct V_254 ) ) ;
V_255 -> V_256 = V_2 -> V_257 ;
V_255 -> V_258 = V_2 -> V_259 ;
return 0 ;
}
static int F_94 ( struct V_21 * V_22 ,
struct V_254 * V_255 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
V_2 -> V_257 = ( V_260 ) V_255 -> V_256 ;
if ( V_2 -> V_257 > V_261 )
V_2 -> V_257 = V_261 ;
V_2 -> V_259 = ( V_260 ) V_255 -> V_258 ;
if ( V_2 -> V_259 > V_261 )
V_2 -> V_259 = V_261 ;
if ( F_16 ( V_22 ) )
F_95 ( V_2 ) ;
return 0 ;
}
static void F_96 ( struct V_21 * V_22 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
V_263 -> V_264 = V_265 ;
if ( V_2 -> V_266 )
V_263 -> V_267 = V_2 -> V_266 ;
else
V_263 -> V_267 = V_265 ;
V_263 -> V_268 = V_269 ;
V_263 -> V_270 = V_2 -> V_271 ;
}
static int F_97 ( struct V_21 * V_22 ,
struct V_262 * V_263 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( V_2 -> V_272 != V_273 ) {
F_10 ( V_79 ,
L_38 ) ;
return - V_238 ;
}
if ( ( V_263 -> V_267 > V_265 ) ||
( V_263 -> V_267 < ( V_2 -> V_274 ? V_275 :
V_276 ) ) ||
( V_263 -> V_270 > V_269 ) ||
( V_263 -> V_270 <= V_277 + 4 ) ) {
F_10 ( V_79 , L_39 ) ;
return - V_88 ;
}
V_2 -> V_266 = V_263 -> V_267 ;
V_2 -> V_271 = V_263 -> V_270 ;
return F_98 ( V_22 ) ;
}
static void F_99 ( struct V_21 * V_22 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_25 = F_5 ( V_2 ) ;
int V_280 ;
V_279 -> V_49 = ( V_2 -> V_5 . V_281 [ V_25 ] ==
V_282 ) ;
if ( ! V_279 -> V_49 )
V_280 = V_2 -> V_5 . V_281 [ V_25 ] ;
else
V_280 = V_2 -> V_5 . V_283 ;
V_279 -> V_284 = ( ( V_280 & V_285 ) ==
V_285 ) ;
V_279 -> V_286 = ( ( V_280 & V_287 ) ==
V_287 ) ;
F_10 ( V_79 , L_40
L_41 ,
V_279 -> V_24 , V_279 -> V_49 , V_279 -> V_284 , V_279 -> V_286 ) ;
}
static int F_100 ( struct V_21 * V_22 ,
struct V_278 * V_279 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_1 V_25 = F_5 ( V_2 ) ;
if ( F_7 ( V_2 ) )
return 0 ;
F_10 ( V_79 , L_40
L_41 ,
V_279 -> V_24 , V_279 -> V_49 , V_279 -> V_284 , V_279 -> V_286 ) ;
V_2 -> V_5 . V_281 [ V_25 ] = V_282 ;
if ( V_279 -> V_284 )
V_2 -> V_5 . V_281 [ V_25 ] |= V_285 ;
if ( V_279 -> V_286 )
V_2 -> V_5 . V_281 [ V_25 ] |= V_287 ;
if ( V_2 -> V_5 . V_281 [ V_25 ] == V_282 )
V_2 -> V_5 . V_281 [ V_25 ] = V_288 ;
if ( V_279 -> V_49 ) {
if ( ! ( V_2 -> V_27 . V_26 [ V_25 ] & V_100 ) ) {
F_10 ( V_79 , L_42 ) ;
return - V_88 ;
}
if ( V_2 -> V_5 . V_39 [ V_25 ] == V_48 ) {
V_2 -> V_5 . V_281 [ V_25 ] =
V_282 ;
}
}
F_10 ( V_79 ,
L_43 , V_2 -> V_5 . V_281 [ V_25 ] ) ;
if ( F_16 ( V_22 ) ) {
F_17 ( V_2 , V_123 ) ;
F_18 ( V_2 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_289 , V_144 , V_224 = - V_290 ;
T_1 V_291 = 0 , V_292 ;
int V_27 = F_63 ( V_2 ) ;
static const struct {
T_1 V_292 ;
T_1 V_293 ;
T_1 V_294 ;
T_1 V_295 ;
} V_296 [] = {
{ V_297 ,
V_298 , 4 , 0x000003ff } ,
{ V_297 ,
V_299 , 4 , 0xffffffff } ,
{ V_300 ,
V_301 , 4 , 0x000003ff } ,
{ V_297 ,
V_302 , 4 , 0x00000001 } ,
{ V_300 | V_303 | V_304 ,
V_305 , 4 , 0x000007ff } ,
{ V_306 ,
V_307 , 4 , 0x000007ff } ,
{ V_297 ,
V_308 , 4 , 0x00ffffff } ,
{ V_297 ,
V_309 , 4 , 0x000fffff } ,
{ V_297 ,
V_310 , 8 , 0x0003ffff } ,
{ V_297 ,
V_311 , 4 , 0x000fffff } ,
{ V_297 ,
V_312 , 8 , 0x0003ffff } ,
{ V_297 ,
V_313 , 4 , 0x000fffff } ,
{ V_297 ,
V_314 , 4 , 0x000fffff } ,
{ V_297 ,
V_315 , 4 , 0x0003ffff } ,
{ V_297 ,
V_316 , 40 , 0xffffffff } ,
{ V_297 ,
V_317 , 40 , 0xffffffff } ,
{ V_297 ,
V_318 , 4 , 0x00000001 } ,
{ V_297 ,
V_319 , 4 , 0x00000003 } ,
{ V_297 ,
V_320 , 4 , 0x000000ff } ,
{ V_297 ,
V_321 , 4 , 0x00000001 } ,
{ V_300 | V_303 ,
V_322 , 4 , 0x00000001 } ,
{ V_300 | V_303 ,
V_323 , 4 , 0x00000001 } ,
{ V_297 ,
V_324 , 4 , 0x00000001 } ,
{ V_297 ,
V_325 , 4 , 0x00000001 } ,
{ V_297 ,
V_326 , 4 , 0x00000007 } ,
{ V_297 ,
V_327 , 68 , 0x000000ff } ,
{ V_297 ,
V_328 , 68 , 0xffffffff } ,
{ V_297 ,
V_329 , 160 , 0xffffffff } ,
{ V_297 ,
V_330 , 160 , 0xffffffff } ,
{ V_297 ,
V_331 , 160 , 0x00000001 } ,
{ V_297 ,
V_332 , 160 , 0x0000ffff } ,
{ V_297 ,
V_333 , 160 , 0x0000ffff } ,
{ V_297 ,
V_334 , 160 , 0x00000fff } ,
{ V_300 | V_303 ,
V_335 , 4 , 0x00000001 } ,
{ V_297 ,
V_336 , 4 , 0x00000001 } ,
{ V_297 ,
V_337 , 4 , 0x07ffffff } ,
{ V_300 | V_303 ,
V_338 , 24 , 0x00000001 } ,
{ V_300 | V_303 ,
V_339 , 16 , 0x0000001f } ,
{ V_297 , 0xffffffff , 0 , 0x00000000 }
} ;
if ( ! F_16 ( V_2 -> V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return V_224 ;
}
if ( F_20 ( V_2 ) )
V_292 = V_340 ;
else if ( F_22 ( V_2 ) )
V_292 = V_341 ;
else if ( F_24 ( V_2 ) )
V_292 = V_303 ;
else if ( F_28 ( V_2 ) )
V_292 = V_306 ;
else
V_292 = V_304 ;
for ( V_289 = 0 ; V_289 < 2 ; V_289 ++ ) {
switch ( V_289 ) {
case 0 :
V_291 = 0 ;
break;
case 1 :
V_291 = 0xffffffff ;
break;
}
for ( V_144 = 0 ; V_296 [ V_144 ] . V_293 != 0xffffffff ; V_144 ++ ) {
T_1 V_221 , V_295 , V_342 , V_209 ;
if ( ! ( V_292 & V_296 [ V_144 ] . V_292 ) )
continue;
V_221 = V_296 [ V_144 ] . V_293 + V_27 * V_296 [ V_144 ] . V_294 ;
V_295 = V_296 [ V_144 ] . V_295 ;
V_342 = F_41 ( V_2 , V_221 ) ;
F_40 ( V_2 , V_221 , V_291 & V_295 ) ;
V_209 = F_41 ( V_2 , V_221 ) ;
F_40 ( V_2 , V_221 , V_342 ) ;
if ( ( V_209 & V_295 ) != ( V_291 & V_295 ) ) {
F_10 ( V_79 ,
L_44 ,
V_221 , V_209 , V_291 , V_295 ) ;
goto V_343;
}
}
}
V_224 = 0 ;
V_343:
return V_224 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_144 , V_145 , V_224 = - V_290 ;
T_1 V_209 , V_344 ;
static const struct {
T_1 V_221 ;
int V_149 ;
} V_345 [] = {
{ V_346 , V_347 } ,
{ V_348 , V_349 } ,
{ V_350 , V_351 } ,
{ V_352 , V_353 } ,
{ V_354 , V_355 } ,
{ V_356 , V_357 } ,
{ V_358 , V_359 } ,
{ 0xffffffff , 0 }
} ;
static const struct {
char * V_360 ;
T_1 V_221 ;
T_1 V_361 [ V_362 ] ;
} V_363 [] = {
{ L_45 , V_364 ,
{ 0x3ffc0 , 0 , 0 , 0 } } ,
{ L_46 , V_365 ,
{ 0x2 , 0x2 , 0 , 0 } } ,
{ L_47 , V_366 ,
{ 0 , 0 , 0 , 0 } } ,
{ L_48 , V_367 ,
{ 0x3ffc0 , 0 , 0 , 0 } } ,
{ L_49 , V_368 ,
{ 0x3ffc0 , 0 , 0 , 0 } } ,
{ L_50 , V_369 ,
{ 0x3ffc1 , 0 , 0 , 0 } } ,
{ NULL , 0xffffffff , { 0 , 0 , 0 , 0 } }
} ;
if ( ! F_16 ( V_2 -> V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return V_224 ;
}
if ( F_20 ( V_2 ) )
V_344 = V_370 ;
else if ( F_22 ( V_2 ) )
V_344 = V_371 ;
else if ( F_24 ( V_2 ) )
V_344 = V_372 ;
else
V_344 = V_373 ;
for ( V_144 = 0 ; V_363 [ V_144 ] . V_221 != 0xffffffff ; V_144 ++ ) {
V_209 = F_41 ( V_2 , V_363 [ V_144 ] . V_221 ) ;
if ( V_209 & ~ ( V_363 [ V_144 ] . V_361 [ V_344 ] ) ) {
F_10 ( V_79 ,
L_51 , V_363 [ V_144 ] . V_360 , V_209 ) ;
goto V_374;
}
}
for ( V_144 = 0 ; V_345 [ V_144 ] . V_221 != 0xffffffff ; V_144 ++ )
for ( V_145 = 0 ; V_145 < V_345 [ V_144 ] . V_149 ; V_145 ++ )
F_41 ( V_2 , V_345 [ V_144 ] . V_221 + V_145 * 4 ) ;
for ( V_144 = 0 ; V_363 [ V_144 ] . V_221 != 0xffffffff ; V_144 ++ ) {
V_209 = F_41 ( V_2 , V_363 [ V_144 ] . V_221 ) ;
if ( V_209 & ~ ( V_363 [ V_144 ] . V_361 [ V_344 ] ) ) {
F_10 ( V_79 ,
L_51 , V_363 [ V_144 ] . V_360 , V_209 ) ;
goto V_374;
}
}
V_224 = 0 ;
V_374:
return V_224 ;
}
static void F_103 ( struct V_1 * V_2 , T_2 V_34 , T_2 V_375 )
{
int V_376 = 1400 ;
if ( V_34 ) {
while ( F_104 ( V_2 , V_375 ) && V_376 -- )
F_91 ( 20 ) ;
if ( V_376 <= 0 && F_104 ( V_2 , V_375 ) )
F_10 ( V_79 , L_52 ) ;
}
}
static int F_105 ( struct V_1 * V_2 , int V_377 )
{
unsigned int V_378 , V_379 , V_144 ;
struct V_380 * V_381 ;
unsigned char * V_382 ;
struct V_383 * V_384 = & V_2 -> V_385 [ 0 ] ;
struct V_383 * V_386 = & V_2 -> V_385 [ 0 ] ;
struct V_387 * V_388 = & V_386 -> V_388 [ 0 ] ;
V_260 V_389 , V_390 ;
V_260 V_391 , V_392 ;
V_260 V_393 , V_394 ;
struct V_395 * V_396 ;
struct V_397 * V_398 ;
struct V_399 * V_400 = NULL ;
struct V_401 * V_402 = NULL ;
T_4 V_403 ;
union V_404 * V_405 ;
T_2 V_406 , V_407 ;
struct V_408 * V_409 ;
V_260 V_163 ;
int V_224 = - V_290 ;
T_2 * V_410 ;
struct V_411 * V_412 = F_106 ( V_2 -> V_22 , V_388 -> V_413 ) ;
switch ( V_377 ) {
case V_414 :
if ( V_2 -> V_5 . V_377 != V_415 )
return - V_88 ;
break;
case V_416 :
if ( F_31 ( V_2 ) ) {
int V_25 = F_5 ( V_2 ) ;
if ( V_2 -> V_27 . V_26 [ V_25 ] &
( V_121 |
V_417 |
V_418 ) )
V_2 -> V_5 . V_377 = V_419 ;
else
V_2 -> V_5 . V_377 = V_420 ;
} else
V_2 -> V_5 . V_377 = V_421 ;
F_88 ( & V_2 -> V_5 , & V_2 -> V_33 ) ;
break;
default:
F_10 ( V_79 , L_39 ) ;
return - V_88 ;
}
V_378 = ( ( ( V_2 -> V_22 -> V_422 < V_423 ) ?
V_2 -> V_22 -> V_422 : V_423 ) + V_424 ) ;
V_381 = F_107 ( V_2 -> V_22 , V_384 -> V_425 ) ;
if ( ! V_381 ) {
F_10 ( V_79 , L_53 ) ;
V_224 = - V_426 ;
goto V_427;
}
V_382 = F_108 ( V_381 , V_378 ) ;
memcpy ( V_382 , V_2 -> V_22 -> V_428 , V_429 ) ;
memset ( V_382 + V_429 , 0 , V_429 ) ;
memset ( V_382 + 2 * V_429 , 0x77 , ( V_424 - 2 * V_429 ) ) ;
for ( V_144 = V_424 ; V_144 < V_378 ; V_144 ++ )
V_382 [ V_144 ] = ( unsigned char ) ( V_144 & 0xff ) ;
V_403 = F_109 ( & V_2 -> V_189 -> V_22 , V_381 -> V_410 ,
F_110 ( V_381 ) , V_430 ) ;
if ( F_111 ( F_112 ( & V_2 -> V_189 -> V_22 , V_403 ) ) ) {
V_224 = - V_426 ;
F_113 ( V_381 ) ;
F_10 ( V_79 , L_54 ) ;
goto V_427;
}
V_379 = 0 ;
V_389 = F_114 ( * V_388 -> V_431 ) ;
V_391 = F_114 ( * V_384 -> V_432 ) ;
F_115 ( V_412 , V_381 -> V_163 ) ;
V_393 = V_388 -> V_433 ++ ;
V_396 = & V_388 -> V_434 [ F_116 ( V_393 ) ] ;
V_396 -> V_435 = V_388 -> V_436 ;
V_396 -> V_381 = V_381 ;
V_396 -> V_35 = 0 ;
V_394 = F_116 ( V_388 -> V_436 ) ;
V_398 = & V_388 -> V_437 [ V_394 ] . V_438 ;
V_398 -> V_439 = F_117 ( F_118 ( V_403 ) ) ;
V_398 -> V_440 = F_117 ( F_119 ( V_403 ) ) ;
V_398 -> V_441 = F_120 ( 2 ) ;
V_398 -> V_442 = F_120 ( F_110 ( V_381 ) ) ;
V_398 -> V_443 = F_120 ( V_393 ) ;
V_398 -> V_444 . V_445 = V_446 ;
F_121 ( V_398 -> V_447 ,
V_448 ,
V_449 ) ;
F_121 ( V_398 -> V_447 ,
V_450 ,
1 ) ;
V_394 = F_116 ( F_122 ( V_394 ) ) ;
V_400 = & V_388 -> V_437 [ V_394 ] . V_451 ;
V_402 = & V_388 -> V_437 [ V_394 ] . V_452 ;
memset ( V_402 , 0 , sizeof( struct V_401 ) ) ;
memset ( V_400 , 0 , sizeof( struct V_399 ) ) ;
F_123 () ;
V_388 -> V_453 . V_410 . V_454 += 2 ;
F_124 () ;
F_125 ( V_2 , V_388 -> V_455 , V_388 -> V_453 . V_456 ) ;
F_126 () ;
F_124 () ;
V_379 ++ ;
V_388 -> V_436 += 2 ;
F_66 ( 100 ) ;
V_390 = F_114 ( * V_388 -> V_431 ) ;
if ( V_390 != V_389 + V_379 )
goto V_427;
if ( V_2 -> V_85 . V_457 == V_458 ) {
F_127 () ;
F_128 ( V_2 , V_388 ) ;
F_129 () ;
}
V_392 = F_114 ( * V_384 -> V_432 ) ;
if ( V_392 != V_391 + V_379 )
goto V_427;
V_405 = & V_384 -> V_459 [ F_130 ( V_384 -> V_460 ) ] ;
V_406 = V_405 -> V_461 . V_462 ;
V_407 = V_406 & V_463 ;
if ( ! F_131 ( V_407 ) || ( V_406 & V_464 ) )
goto V_465;
V_163 = F_114 ( V_405 -> V_461 . V_466 ) ;
if ( V_163 != V_378 )
goto V_465;
V_409 = & V_384 -> V_467 [ F_132 ( V_384 -> V_468 ) ] ;
F_133 ( & V_2 -> V_189 -> V_22 ,
F_134 ( V_409 , V_403 ) ,
V_384 -> V_425 , V_469 ) ;
V_410 = V_409 -> V_410 + V_470 + V_405 -> V_461 . V_471 ;
for ( V_144 = V_424 ; V_144 < V_378 ; V_144 ++ )
if ( * ( V_410 + V_144 ) != ( unsigned char ) ( V_144 & 0xff ) )
goto V_465;
V_224 = 0 ;
V_465:
V_384 -> V_468 = F_135 ( V_384 -> V_468 ) ;
V_384 -> V_472 = F_135 ( V_384 -> V_472 ) ;
V_384 -> V_460 = F_136 ( V_384 -> V_460 ) ;
V_384 -> V_473 = F_136 ( V_384 -> V_473 ) ;
F_137 ( V_2 , V_384 , V_384 -> V_472 , V_384 -> V_473 ,
V_384 -> V_474 ) ;
V_427:
V_2 -> V_5 . V_377 = V_475 ;
return V_224 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_224 = 0 , V_476 ;
if ( F_8 ( V_2 ) )
return V_224 ;
if ( ! F_16 ( V_2 -> V_22 ) )
return V_477 ;
F_139 ( V_2 , 1 ) ;
F_82 ( V_2 ) ;
V_476 = F_105 ( V_2 , V_414 ) ;
if ( V_476 ) {
F_10 ( V_79 , L_55 , V_476 ) ;
V_224 |= V_478 ;
}
V_476 = F_105 ( V_2 , V_416 ) ;
if ( V_476 ) {
F_10 ( V_79 , L_56 , V_476 ) ;
V_224 |= V_479 ;
}
F_86 ( V_2 ) ;
F_140 ( V_2 ) ;
return V_224 ;
}
static int F_141 ( struct V_1 * V_2 )
{
static const struct {
int V_221 ;
int V_149 ;
} V_480 [] = {
{ 0 , 0x14 } ,
{ 0x14 , 0xec } ,
{ 0x100 , 0x350 } ,
{ 0x450 , 0xf0 } ,
{ 0x640 , 0x64 } ,
{ 0x708 , 0x70 } ,
{ 0 , 0 }
} ;
T_3 * V_481 ;
T_2 * V_410 ;
int V_144 , V_224 ;
T_1 V_239 , V_482 ;
if ( F_8 ( V_2 ) )
return 0 ;
V_481 = F_142 ( 0x350 , V_483 ) ;
if ( ! V_481 ) {
F_10 ( V_79 | V_215 , L_57 ) ;
V_224 = - V_426 ;
goto V_484;
}
V_410 = ( T_2 * ) V_481 ;
V_224 = F_73 ( V_2 , 0 , V_410 , 4 ) ;
if ( V_224 ) {
F_10 ( V_79 | V_215 ,
L_58 , V_224 ) ;
goto V_484;
}
V_239 = F_78 ( V_481 [ 0 ] ) ;
if ( V_239 != 0x669955aa ) {
F_10 ( V_79 | V_215 ,
L_59 , V_239 ) ;
V_224 = - V_290 ;
goto V_484;
}
for ( V_144 = 0 ; V_480 [ V_144 ] . V_149 ; V_144 ++ ) {
V_224 = F_73 ( V_2 , V_480 [ V_144 ] . V_221 , V_410 ,
V_480 [ V_144 ] . V_149 ) ;
if ( V_224 ) {
F_10 ( V_79 | V_215 ,
L_60 , V_144 , V_224 ) ;
goto V_484;
}
V_482 = F_143 ( V_480 [ V_144 ] . V_149 , V_410 ) ;
if ( V_482 != V_485 ) {
F_10 ( V_79 | V_215 ,
L_61 , V_144 , V_482 ) ;
V_224 = - V_290 ;
goto V_484;
}
}
V_484:
F_144 ( V_481 ) ;
return V_224 ;
}
static int F_145 ( struct V_1 * V_2 )
{
struct V_486 V_487 = { NULL } ;
if ( ! F_16 ( V_2 -> V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return - V_290 ;
}
V_487 . V_488 = & V_2 -> V_385 -> V_488 ;
V_487 . V_24 = V_489 ;
F_146 ( V_490 , & V_487 . V_491 ) ;
return F_147 ( V_2 , & V_487 ) ;
}
static void F_148 ( struct V_21 * V_22 ,
struct V_492 * V_493 , T_5 * V_481 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_2 V_375 ;
if ( V_2 -> V_272 != V_273 ) {
F_149 ( V_2 -> V_22 ,
L_38 ) ;
V_493 -> V_35 |= V_494 ;
return;
}
memset ( V_481 , 0 , sizeof( T_5 ) * V_193 ) ;
if ( ! F_16 ( V_22 ) )
return;
if ( F_7 ( V_2 ) )
V_493 -> V_35 &= ~ V_495 ;
V_375 = ( V_2 -> V_33 . V_52 & V_496 ) > 0 ;
if ( V_493 -> V_35 & V_495 ) {
int V_27 = F_63 ( V_2 ) ;
T_1 V_209 ;
T_2 V_34 ;
V_209 = F_41 ( V_2 , V_497 + V_27 * 4 ) ;
F_40 ( V_2 , V_497 + V_27 * 4 , 0 ) ;
V_34 = V_2 -> V_33 . V_34 ;
F_150 ( V_2 , V_498 ) ;
F_151 ( V_2 , V_499 ) ;
F_103 ( V_2 , 1 , V_375 ) ;
if ( F_101 ( V_2 ) != 0 ) {
V_481 [ 0 ] = 1 ;
V_493 -> V_35 |= V_494 ;
}
if ( F_102 ( V_2 ) != 0 ) {
V_481 [ 1 ] = 1 ;
V_493 -> V_35 |= V_494 ;
}
V_481 [ 2 ] = F_138 ( V_2 ) ;
if ( V_481 [ 2 ] != 0 )
V_493 -> V_35 |= V_494 ;
F_150 ( V_2 , V_498 ) ;
F_40 ( V_2 , V_497 + V_27 * 4 , V_209 ) ;
F_151 ( V_2 , V_500 ) ;
F_103 ( V_2 , V_34 , V_375 ) ;
}
if ( F_141 ( V_2 ) != 0 ) {
V_481 [ 3 ] = 1 ;
V_493 -> V_35 |= V_494 ;
}
if ( F_145 ( V_2 ) != 0 ) {
V_481 [ 4 ] = 1 ;
V_493 -> V_35 |= V_494 ;
}
if ( F_104 ( V_2 , V_375 ) != 0 ) {
V_481 [ 5 ] = 1 ;
V_493 -> V_35 |= V_494 ;
}
#ifdef F_152
F_153 ( V_2 ) ;
#endif
}
static inline int F_154 ( struct V_1 * V_2 )
{
return F_155 ( V_2 ) ;
}
static int F_156 ( struct V_21 * V_22 , int V_501 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_144 , V_502 ;
switch ( V_501 ) {
case V_503 :
if ( F_157 ( V_2 ) ) {
V_502 = F_154 ( V_2 ) *
V_504 ;
} else
V_502 = 0 ;
if ( F_158 ( V_2 ) ) {
for ( V_144 = 0 ; V_144 < V_191 ; V_144 ++ )
if ( F_159 ( V_144 ) )
V_502 ++ ;
} else
V_502 += V_191 ;
return V_502 ;
case V_505 :
return V_193 ;
default:
return - V_88 ;
}
}
static void F_160 ( struct V_21 * V_22 , T_1 V_501 , T_2 * V_481 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
int V_144 , V_145 , V_146 ;
char V_506 [ V_507 + 1 ] ;
switch ( V_501 ) {
case V_503 :
V_146 = 0 ;
if ( F_157 ( V_2 ) ) {
F_161 (bp, i) {
memset ( V_506 , 0 , sizeof( V_506 ) ) ;
sprintf ( V_506 , L_62 , V_144 ) ;
for ( V_145 = 0 ; V_145 < V_504 ; V_145 ++ )
snprintf ( V_481 + ( V_146 + V_145 ) * V_508 ,
V_508 ,
V_509 [ V_145 ] . string ,
V_506 ) ;
V_146 += V_504 ;
}
}
for ( V_144 = 0 , V_145 = 0 ; V_144 < V_191 ; V_144 ++ ) {
if ( F_158 ( V_2 ) && F_162 ( V_144 ) )
continue;
strcpy ( V_481 + ( V_146 + V_145 ) * V_508 ,
V_510 [ V_144 ] . string ) ;
V_145 ++ ;
}
break;
case V_505 :
memcpy ( V_481 , V_511 , sizeof( V_511 ) ) ;
break;
}
}
static void F_163 ( struct V_21 * V_22 ,
struct V_512 * V_513 , T_5 * V_481 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_1 * V_514 , * V_221 ;
int V_144 , V_145 , V_146 = 0 ;
if ( F_157 ( V_2 ) ) {
F_161 (bp, i) {
V_514 = ( T_1 * ) & V_2 -> V_385 [ V_144 ] . V_515 ;
for ( V_145 = 0 ; V_145 < V_504 ; V_145 ++ ) {
if ( V_509 [ V_145 ] . V_149 == 0 ) {
V_481 [ V_146 + V_145 ] = 0 ;
continue;
}
V_221 = ( V_514 +
V_509 [ V_145 ] . V_221 ) ;
if ( V_509 [ V_145 ] . V_149 == 4 ) {
V_481 [ V_146 + V_145 ] = ( T_5 ) * V_221 ;
continue;
}
V_481 [ V_146 + V_145 ] = F_164 ( * V_221 , * ( V_221 + 1 ) ) ;
}
V_146 += V_504 ;
}
}
V_514 = ( T_1 * ) & V_2 -> V_516 ;
for ( V_144 = 0 , V_145 = 0 ; V_144 < V_191 ; V_144 ++ ) {
if ( F_158 ( V_2 ) && F_162 ( V_144 ) )
continue;
if ( V_510 [ V_144 ] . V_149 == 0 ) {
V_481 [ V_146 + V_145 ] = 0 ;
V_145 ++ ;
continue;
}
V_221 = ( V_514 + V_510 [ V_144 ] . V_221 ) ;
if ( V_510 [ V_144 ] . V_149 == 4 ) {
V_481 [ V_146 + V_145 ] = ( T_5 ) * V_221 ;
V_145 ++ ;
continue;
}
V_481 [ V_146 + V_145 ] = F_164 ( * V_221 , * ( V_221 + 1 ) ) ;
V_145 ++ ;
}
}
static int F_165 ( struct V_21 * V_22 ,
enum V_517 V_31 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
if ( ! F_16 ( V_22 ) ) {
F_10 ( V_79 | V_215 ,
L_33 ) ;
return - V_238 ;
}
if ( ! V_2 -> V_27 . V_207 ) {
F_10 ( V_79 , L_63 ) ;
return - V_518 ;
}
switch ( V_31 ) {
case V_519 :
return 1 ;
case V_520 :
F_166 ( & V_2 -> V_5 , & V_2 -> V_33 ,
V_521 , V_116 ) ;
break;
case V_522 :
F_166 ( & V_2 -> V_5 , & V_2 -> V_33 ,
V_523 , 0 ) ;
break;
case V_524 :
F_166 ( & V_2 -> V_5 , & V_2 -> V_33 ,
V_525 ,
V_2 -> V_33 . V_37 ) ;
}
return 0 ;
}
static int F_167 ( struct V_21 * V_22 , struct V_526 * V_126 ,
T_1 * T_6 V_527 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
switch ( V_126 -> V_24 ) {
case V_528 :
V_126 -> V_410 = F_155 ( V_2 ) ;
return 0 ;
default:
F_10 ( V_79 , L_39 ) ;
return - V_518 ;
}
}
static T_1 F_168 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
return ( V_2 -> V_529 == V_530 ?
0 : V_531 ) ;
}
static int F_169 ( struct V_21 * V_22 , T_1 * V_532 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_2 V_533 [ V_531 ] = { 0 } ;
T_7 V_144 ;
F_170 ( & V_2 -> V_534 , V_533 ) ;
for ( V_144 = 0 ; V_144 < V_531 ; V_144 ++ )
V_532 [ V_144 ] = V_533 [ V_144 ] - V_2 -> V_385 -> V_535 ;
return 0 ;
}
static int F_171 ( struct V_21 * V_22 , const T_1 * V_532 )
{
struct V_1 * V_2 = F_4 ( V_22 ) ;
T_7 V_144 ;
T_2 V_533 [ V_531 ] = { 0 } ;
for ( V_144 = 0 ; V_144 < V_531 ; V_144 ++ ) {
V_533 [ V_144 ] = V_532 [ V_144 ] + V_2 -> V_385 -> V_535 ;
}
return F_172 ( V_2 , V_533 , false ) ;
}
void F_173 ( struct V_21 * V_536 )
{
F_174 ( V_536 , & V_537 ) ;
}
