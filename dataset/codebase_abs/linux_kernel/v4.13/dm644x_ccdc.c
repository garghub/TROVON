static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_3 ( T_1 V_4 , T_1 V_1 )
{
F_4 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static void F_5 ( int V_5 )
{
F_3 ( V_5 , V_6 ) ;
}
static void F_6 ( int V_5 )
{
if ( V_5 )
F_3 ( V_7 , V_8 ) ;
else
F_3 ( V_9 , V_8 ) ;
}
static void F_7 ( struct V_10 * V_11 ,
enum V_12 V_13 ,
int V_14 )
{
int V_15 , V_16 ;
int V_17 , V_18 ;
int V_4 = 0 , V_19 = 0 ;
F_8 ( V_2 . V_20 , L_1 ) ;
V_15 = V_11 -> V_21 << ( V_14 - 1 ) ;
V_16 = ( V_11 -> V_22 << ( V_14 - 1 ) ) - 1 ;
F_3 ( ( V_15 << V_23 ) | V_16 ,
V_24 ) ;
V_17 = V_11 -> V_25 ;
if ( V_13 == V_26 ) {
V_18 = ( V_11 -> V_27 >> 1 ) - 1 ;
V_17 >>= 1 ;
V_17 += 1 ;
V_4 = ( V_17 << V_28 ) ;
F_3 ( V_4 , V_29 ) ;
} else {
V_17 += 1 ;
V_18 = V_11 -> V_27 - 1 ;
V_19 = V_17 + ( V_11 -> V_27 / 2 ) ;
V_4 = ( V_17 << V_28 ) |
( V_19 & V_30 ) ;
F_3 ( V_4 , V_29 ) ;
}
F_3 ( ( V_17 << V_31 ) | V_17 ,
V_32 ) ;
F_3 ( V_18 , V_33 ) ;
F_8 ( V_2 . V_20 , L_2 ) ;
}
static void F_9 ( void )
{
unsigned int V_4 = 0 ;
V_4 = F_1 ( V_34 ) ;
F_10 ( V_2 . V_20 , L_3 , V_4 ) ;
V_4 = F_1 ( V_35 ) ;
F_10 ( V_2 . V_20 , L_4 , V_4 ) ;
V_4 = F_1 ( V_36 ) ;
F_10 ( V_2 . V_20 , L_5 , V_4 ) ;
V_4 = F_1 ( V_37 ) ;
F_10 ( V_2 . V_20 , L_6 , V_4 ) ;
V_4 = F_1 ( V_38 ) ;
F_10 ( V_2 . V_20 , L_7 , V_4 ) ;
V_4 = F_1 ( V_39 ) ;
F_10 ( V_2 . V_20 , L_8 , V_4 ) ;
V_4 = F_1 ( V_8 ) ;
F_10 ( V_2 . V_20 , L_9 , V_4 ) ;
V_4 = F_1 ( V_40 ) ;
F_10 ( V_2 . V_20 , L_10 , V_4 ) ;
V_4 = F_1 ( V_41 ) ;
F_10 ( V_2 . V_20 , L_11 , V_4 ) ;
V_4 = F_1 ( V_42 ) ;
F_10 ( V_2 . V_20 , L_12 , V_4 ) ;
V_4 = F_1 ( V_43 ) ;
F_10 ( V_2 . V_20 , L_13 , V_4 ) ;
V_4 = F_1 ( V_44 ) ;
F_10 ( V_2 . V_20 , L_14 , V_4 ) ;
V_4 = F_1 ( V_45 ) ;
F_10 ( V_2 . V_20 , L_15 , V_4 ) ;
V_4 = F_1 ( V_46 ) ;
F_10 ( V_2 . V_20 , L_16 , V_4 ) ;
V_4 = F_1 ( V_24 ) ;
F_10 ( V_2 . V_20 , L_17 , V_4 ) ;
V_4 = F_1 ( V_32 ) ;
F_10 ( V_2 . V_20 , L_18 , V_4 ) ;
V_4 = F_1 ( V_33 ) ;
F_10 ( V_2 . V_20 , L_19 , V_4 ) ;
}
static int F_11 ( struct V_47 * V_20 )
{
return 0 ;
}
static void F_12 ( void )
{
int V_48 ;
F_5 ( 0 ) ;
for ( V_48 = 4 ; V_48 <= 0x94 ; V_48 += 4 )
F_3 ( 0 , V_48 ) ;
F_3 ( V_49 , V_50 ) ;
F_3 ( V_51 , V_34 ) ;
}
static int F_13 ( struct V_47 * V_47 )
{
F_12 () ;
if ( V_2 . V_52 == V_53 )
F_6 ( 1 ) ;
return 0 ;
}
static void F_14 ( void )
{
F_15 ( V_54 ) ;
}
static void F_16 ( void )
{
struct V_55 * V_56 = & V_2 . V_57 ;
T_1 V_58 ;
F_8 ( V_2 . V_20 , L_20 ) ;
F_12 () ;
V_58 = ( ( ( V_56 -> V_59 & V_60 ) <<
V_61 ) |
( ( V_56 -> V_13 & V_62 ) <<
V_63 ) | V_64 |
V_65 | V_66 ) ;
if ( V_56 -> V_67 ) {
F_3 ( V_68 , V_69 ) ;
V_58 |= V_70 ;
if ( V_2 . V_52 == V_71 )
V_58 |= V_72 ;
else
V_58 |= V_73 ;
} else {
V_58 |= ( ( ( V_56 -> V_74 & V_75 ) <<
V_76 ) |
( ( V_56 -> V_77 & V_78 ) <<
V_79 ) |
( ( V_56 -> V_80 & V_81 ) <<
V_82 ) ) ;
}
F_3 ( V_58 , V_46 ) ;
F_7 ( & V_56 -> V_83 , V_56 -> V_13 , 2 ) ;
if ( V_2 . V_52 == V_71 )
F_3 ( ( V_56 -> V_84 << V_85 ) |
V_86 | V_87 ,
V_88 ) ;
else
F_3 ( ( V_56 -> V_84 << V_85 ) |
V_86 , V_88 ) ;
F_3 ( ( ( V_56 -> V_83 . V_22 * 2 + 31 ) & ~ 0x1f ) , V_43 ) ;
if ( V_56 -> V_89 == V_90 )
F_3 ( V_91 , V_44 ) ;
F_14 () ;
F_8 ( V_2 . V_20 , L_21 ) ;
}
static void F_17 ( struct V_92 * V_93 )
{
T_1 V_4 ;
if ( ! V_93 -> V_94 ) {
V_4 = ( V_93 -> V_95 ) & V_96 ;
F_3 ( V_4 , V_36 ) ;
F_8 ( V_2 . V_20 , L_22 , V_4 ) ;
F_3 ( V_97 , V_35 ) ;
F_8 ( V_2 . V_20 , L_23 ) ;
return;
}
V_4 = ( ( V_93 -> V_98 & V_99 ) |
( ( V_93 -> V_100 & V_101 ) <<
V_102 ) |
( ( V_93 -> V_103 & V_104 ) <<
V_105 ) |
( ( V_93 -> V_106 & V_107 ) <<
V_108 ) | V_109 ) ;
F_3 ( V_4 , V_35 ) ;
F_8 ( V_2 . V_20 , L_24 , V_4 ) ;
F_3 ( V_110 , V_36 ) ;
F_8 ( V_2 . V_20 , L_25 ) ;
}
static void F_18 ( struct V_111 * V_112 )
{
T_1 V_4 ;
V_4 = ( ( V_112 -> V_113 & V_114 ) |
( ( V_112 -> V_115 & V_114 ) <<
V_116 ) |
( ( V_112 -> V_117 & V_114 ) <<
V_118 ) |
( ( V_112 -> V_119 & V_114 ) <<
V_120 ) ) ;
F_3 ( V_4 , V_37 ) ;
}
static void F_19 ( void )
{
struct V_121 * V_56 = & V_2 . V_122 ;
struct V_123 * V_124 =
& V_2 . V_122 . V_124 ;
unsigned int V_58 = 0 ;
unsigned int V_4 ;
F_8 ( V_2 . V_20 , L_26 ) ;
F_12 () ;
F_3 ( V_86 , V_88 ) ;
V_58 =
( ( ( V_56 -> V_80 & V_81 ) << V_82 ) |
( ( V_56 -> V_77 & V_78 ) << V_79 ) |
( ( V_56 -> V_74 & V_75 ) << V_76 ) |
( ( V_56 -> V_13 & V_125 ) << V_126 ) |
( ( V_124 -> V_127 & V_128 ) <<
V_129 ) |
( ( V_56 -> V_59 & V_130 ) << V_131 ) |
V_65 | V_64 ) ;
if ( V_124 -> V_132 . V_94 ) {
V_4 = ( ( V_124 -> V_132 . V_133 &
V_134 ) | V_135 ) ;
F_3 ( V_4 , V_34 ) ;
F_8 ( V_2 . V_20 , L_27 , V_4 ) ;
}
F_7 ( & V_56 -> V_83 , V_56 -> V_13 , V_136 ) ;
F_17 ( & V_124 -> V_137 ) ;
F_18 ( & V_124 -> V_138 ) ;
if ( ( V_124 -> V_127 == V_139 ) ||
V_124 -> V_132 . V_94 )
V_58 |= V_66 ;
V_4 = V_9 ;
if ( V_124 -> V_127 == V_139 )
V_4 |= ( V_140 & V_141 )
<< V_142 ;
else
V_4 |= ( V_124 -> V_127 & V_141 )
<< V_142 ;
F_3 ( V_4 , V_8 ) ;
F_8 ( V_2 . V_20 , L_28 , V_4 ) ;
F_3 ( V_143 , V_40 ) ;
F_8 ( V_2 . V_20 , L_29 ) ;
V_4 = ( ( V_56 -> V_83 . V_21 & V_144 ) <<
V_145 ) |
( V_56 -> V_83 . V_22 & V_146 ) ;
F_3 ( V_4 , V_41 ) ;
F_8 ( V_2 . V_20 , L_30 , V_4 ) ;
V_4 = ( V_56 -> V_83 . V_25 & V_147 )
<< V_148 ;
if ( V_56 -> V_13 == V_149 )
V_4 |= ( V_56 -> V_83 . V_27 ) & V_150 ;
else
V_4 |= ( V_56 -> V_83 . V_27 >> 1 ) & V_150 ;
F_8 ( V_2 . V_20 , L_31 ,
V_56 -> V_83 . V_27 ) ;
F_3 ( V_4 , V_42 ) ;
F_8 ( V_2 . V_20 , L_32 , V_4 ) ;
F_8 ( V_2 . V_20 , L_33 ) ;
if ( ( V_124 -> V_127 == V_139 ) ||
V_124 -> V_132 . V_94 )
F_3 ( ( V_56 -> V_83 . V_22 + V_151 ) &
V_152 , V_43 ) ;
else
F_3 ( ( ( V_56 -> V_83 . V_22 * V_153 ) +
V_151 ) & V_152 ,
V_43 ) ;
if ( V_56 -> V_13 == V_26 ) {
if ( V_56 -> V_154 ) {
F_3 ( V_155 , V_44 ) ;
F_8 ( V_2 . V_20 , L_34 ) ;
}
else {
F_3 ( V_156 , V_44 ) ;
F_8 ( V_2 . V_20 , L_35 ) ;
}
} else if ( V_56 -> V_13 == V_149 ) {
F_3 ( V_157 , V_44 ) ;
F_8 ( V_2 . V_20 , L_36 ) ;
}
if ( V_56 -> V_13 == V_149 )
V_4 = ( ( ( V_56 -> V_83 . V_27 - 1 ) & V_158 ) )
<< V_159 ;
else
V_4 =
( ( ( ( V_56 -> V_83 . V_27 >> V_160 ) -
1 ) & V_158 ) ) <<
V_159 ;
V_4 |= ( ( ( ( V_56 -> V_83 . V_22 ) ) ) & V_161 )
<< V_162 ;
V_4 |= ( V_56 -> V_83 . V_21 ) & V_163 ;
F_3 ( V_4 , V_45 ) ;
F_8 ( V_2 . V_20 , L_37 , V_4 ) ;
F_3 ( V_58 , V_46 ) ;
F_8 ( V_2 . V_20 , L_38 , V_58 ) ;
F_14 () ;
F_8 ( V_2 . V_20 , L_39 ) ;
F_9 () ;
}
static int F_20 ( void )
{
if ( V_2 . V_52 == V_53 )
F_19 () ;
else
F_16 () ;
return 0 ;
}
static int F_21 ( enum V_164 V_89 )
{
if ( V_2 . V_52 == V_53 )
V_2 . V_122 . V_89 = V_89 ;
else
V_2 . V_57 . V_89 = V_89 ;
return 0 ;
}
static enum V_164 F_22 ( void )
{
if ( V_2 . V_52 == V_53 )
return V_2 . V_122 . V_89 ;
return V_2 . V_57 . V_89 ;
}
static int F_23 ( T_1 * V_165 , int V_48 )
{
int V_166 = - V_167 ;
if ( V_2 . V_52 == V_53 ) {
if ( V_48 < F_24 ( V_168 ) ) {
* V_165 = V_168 [ V_48 ] ;
V_166 = 0 ;
}
} else {
if ( V_48 < F_24 ( V_169 ) ) {
* V_165 = V_169 [ V_48 ] ;
V_166 = 0 ;
}
}
return V_166 ;
}
static int F_25 ( T_1 V_170 )
{
if ( V_2 . V_52 == V_53 ) {
V_2 . V_122 . V_59 = V_171 ;
if ( V_170 == V_172 )
V_2 . V_122 . V_124 . V_132 . V_94 = 1 ;
else if ( V_170 != V_173 )
return - V_167 ;
} else {
if ( V_170 == V_174 )
V_2 . V_57 . V_84 = V_175 ;
else if ( V_170 == V_176 )
V_2 . V_57 . V_84 = V_177 ;
else
return - V_167 ;
}
return 0 ;
}
static T_1 F_26 ( void )
{
struct V_178 * V_132 = & V_2 . V_122 . V_124 . V_132 ;
T_1 V_170 ;
if ( V_2 . V_52 == V_53 )
if ( V_132 -> V_94 )
V_170 = V_172 ;
else
V_170 = V_173 ;
else {
if ( V_2 . V_57 . V_84 == V_175 )
V_170 = V_174 ;
else
V_170 = V_176 ;
}
return V_170 ;
}
static int F_27 ( struct V_10 * V_83 )
{
if ( V_2 . V_52 == V_53 )
V_2 . V_122 . V_83 = * V_83 ;
else
V_2 . V_57 . V_83 = * V_83 ;
return 0 ;
}
static void F_28 ( struct V_10 * V_83 )
{
if ( V_2 . V_52 == V_53 )
* V_83 = V_2 . V_122 . V_83 ;
else
* V_83 = V_2 . V_57 . V_83 ;
}
static unsigned int F_29 ( void )
{
struct V_123 * V_124 =
& V_2 . V_122 . V_124 ;
unsigned int V_179 ;
if ( V_2 . V_52 == V_53 ) {
if ( ( V_124 -> V_132 . V_94 ) ||
( V_124 -> V_127 == V_139 ) )
V_179 = V_2 . V_122 . V_83 . V_22 ;
else
V_179 = V_2 . V_122 . V_83 . V_22 * 2 ;
} else
V_179 = V_2 . V_57 . V_83 . V_22 * 2 ;
return F_30 ( V_179 , 32 ) ;
}
static int F_31 ( enum V_12 V_13 )
{
if ( V_2 . V_52 == V_53 )
V_2 . V_122 . V_13 = V_13 ;
else
V_2 . V_57 . V_13 = V_13 ;
return 0 ;
}
static enum V_12 F_32 ( void )
{
if ( V_2 . V_52 == V_53 )
return V_2 . V_122 . V_13 ;
else
return V_2 . V_57 . V_13 ;
}
static int F_33 ( void )
{
return ( F_1 ( V_46 ) >> 15 ) & 1 ;
}
static inline void F_34 ( unsigned long V_180 )
{
F_3 ( V_180 & 0xffffffe0 , V_181 ) ;
}
static int F_35 ( struct V_182 * V_56 )
{
V_2 . V_52 = V_56 -> V_52 ;
switch ( V_56 -> V_52 ) {
case V_183 :
case V_184 :
case V_185 :
case V_71 :
V_2 . V_57 . V_80 = V_56 -> V_186 ;
V_2 . V_57 . V_77 = V_56 -> V_187 ;
break;
default:
return - V_167 ;
}
return 0 ;
}
static void F_36 ( void )
{
V_188 [ V_6 >> 2 ] = F_1 ( V_6 ) ;
V_188 [ V_46 >> 2 ] = F_1 ( V_46 ) ;
V_188 [ V_189 >> 2 ] = F_1 ( V_189 ) ;
V_188 [ V_190 >> 2 ] = F_1 ( V_190 ) ;
V_188 [ V_24 >> 2 ] = F_1 ( V_24 ) ;
V_188 [ V_32 >> 2 ] = F_1 ( V_32 ) ;
V_188 [ V_33 >> 2 ] = F_1 ( V_33 ) ;
V_188 [ V_50 >> 2 ] = F_1 ( V_50 ) ;
V_188 [ V_43 >> 2 ] = F_1 ( V_43 ) ;
V_188 [ V_44 >> 2 ] = F_1 ( V_44 ) ;
V_188 [ V_181 >> 2 ] = F_1 ( V_181 ) ;
V_188 [ V_35 >> 2 ] = F_1 ( V_35 ) ;
V_188 [ V_36 >> 2 ] = F_1 ( V_36 ) ;
V_188 [ V_40 >> 2 ] = F_1 ( V_40 ) ;
V_188 [ V_37 >> 2 ] = F_1 ( V_37 ) ;
V_188 [ V_39 >> 2 ] = F_1 ( V_39 ) ;
V_188 [ V_38 >> 2 ] = F_1 ( V_38 ) ;
V_188 [ V_29 >> 2 ] = F_1 ( V_29 ) ;
V_188 [ V_34 >> 2 ] = F_1 ( V_34 ) ;
V_188 [ V_69 >> 2 ] = F_1 ( V_69 ) ;
V_188 [ V_88 >> 2 ] = F_1 ( V_88 ) ;
V_188 [ V_8 >> 2 ] = F_1 ( V_8 ) ;
V_188 [ V_41 >> 2 ] = F_1 ( V_41 ) ;
V_188 [ V_42 >> 2 ] = F_1 ( V_42 ) ;
V_188 [ V_191 >> 2 ] = F_1 ( V_191 ) ;
V_188 [ V_192 >> 2 ] = F_1 ( V_192 ) ;
V_188 [ V_193 >> 2 ] = F_1 ( V_193 ) ;
V_188 [ V_194 >> 2 ] = F_1 ( V_194 ) ;
V_188 [ V_195 >> 2 ] = F_1 ( V_195 ) ;
V_188 [ V_196 >> 2 ] = F_1 ( V_196 ) ;
V_188 [ V_197 >> 2 ] = F_1 ( V_197 ) ;
V_188 [ V_198 >> 2 ] = F_1 ( V_198 ) ;
V_188 [ V_199 >> 2 ] = F_1 ( V_199 ) ;
V_188 [ V_200 >> 2 ] = F_1 ( V_200 ) ;
V_188 [ V_201 >> 2 ] = F_1 ( V_201 ) ;
V_188 [ V_202 >> 2 ] = F_1 ( V_202 ) ;
V_188 [ V_45 >> 2 ] = F_1 ( V_45 ) ;
}
static void F_37 ( void )
{
F_3 ( V_188 [ V_46 >> 2 ] , V_46 ) ;
F_3 ( V_188 [ V_189 >> 2 ] , V_189 ) ;
F_3 ( V_188 [ V_190 >> 2 ] , V_190 ) ;
F_3 ( V_188 [ V_24 >> 2 ] , V_24 ) ;
F_3 ( V_188 [ V_32 >> 2 ] , V_32 ) ;
F_3 ( V_188 [ V_33 >> 2 ] , V_33 ) ;
F_3 ( V_188 [ V_50 >> 2 ] , V_50 ) ;
F_3 ( V_188 [ V_43 >> 2 ] , V_43 ) ;
F_3 ( V_188 [ V_44 >> 2 ] , V_44 ) ;
F_3 ( V_188 [ V_181 >> 2 ] , V_181 ) ;
F_3 ( V_188 [ V_35 >> 2 ] , V_35 ) ;
F_3 ( V_188 [ V_36 >> 2 ] , V_36 ) ;
F_3 ( V_188 [ V_40 >> 2 ] , V_40 ) ;
F_3 ( V_188 [ V_37 >> 2 ] , V_37 ) ;
F_3 ( V_188 [ V_39 >> 2 ] , V_39 ) ;
F_3 ( V_188 [ V_38 >> 2 ] , V_38 ) ;
F_3 ( V_188 [ V_29 >> 2 ] , V_29 ) ;
F_3 ( V_188 [ V_34 >> 2 ] , V_34 ) ;
F_3 ( V_188 [ V_69 >> 2 ] , V_69 ) ;
F_3 ( V_188 [ V_88 >> 2 ] , V_88 ) ;
F_3 ( V_188 [ V_8 >> 2 ] , V_8 ) ;
F_3 ( V_188 [ V_41 >> 2 ] , V_41 ) ;
F_3 ( V_188 [ V_42 >> 2 ] , V_42 ) ;
F_3 ( V_188 [ V_191 >> 2 ] , V_191 ) ;
F_3 ( V_188 [ V_192 >> 2 ] , V_192 ) ;
F_3 ( V_188 [ V_193 >> 2 ] , V_193 ) ;
F_3 ( V_188 [ V_194 >> 2 ] , V_194 ) ;
F_3 ( V_188 [ V_195 >> 2 ] , V_195 ) ;
F_3 ( V_188 [ V_196 >> 2 ] , V_196 ) ;
F_3 ( V_188 [ V_197 >> 2 ] , V_197 ) ;
F_3 ( V_188 [ V_198 >> 2 ] , V_198 ) ;
F_3 ( V_188 [ V_199 >> 2 ] , V_199 ) ;
F_3 ( V_188 [ V_200 >> 2 ] , V_200 ) ;
F_3 ( V_188 [ V_201 >> 2 ] , V_201 ) ;
F_3 ( V_188 [ V_202 >> 2 ] , V_202 ) ;
F_3 ( V_188 [ V_45 >> 2 ] , V_45 ) ;
F_3 ( V_188 [ V_6 >> 2 ] , V_6 ) ;
}
static int F_38 ( struct V_203 * V_204 )
{
struct V_205 * V_206 ;
int V_207 = 0 ;
V_207 = F_39 ( & V_208 ) ;
if ( V_207 < 0 )
return V_207 ;
V_206 = F_40 ( V_204 , V_209 , 0 ) ;
if ( ! V_206 ) {
V_207 = - V_210 ;
goto V_211;
}
V_206 = F_41 ( V_206 -> V_212 , F_42 ( V_206 ) , V_206 -> V_213 ) ;
if ( ! V_206 ) {
V_207 = - V_214 ;
goto V_211;
}
V_2 . V_3 = F_43 ( V_206 -> V_212 , F_42 ( V_206 ) ) ;
if ( ! V_2 . V_3 ) {
V_207 = - V_215 ;
goto V_216;
}
V_2 . V_20 = & V_204 -> V_20 ;
F_44 ( V_217 L_40 , V_208 . V_213 ) ;
return 0 ;
V_216:
F_45 ( V_206 -> V_212 , F_42 ( V_206 ) ) ;
V_211:
F_46 ( & V_208 ) ;
return V_207 ;
}
static int F_47 ( struct V_203 * V_204 )
{
struct V_205 * V_206 ;
F_48 ( V_2 . V_3 ) ;
V_206 = F_40 ( V_204 , V_209 , 0 ) ;
if ( V_206 )
F_45 ( V_206 -> V_212 , F_42 ( V_206 ) ) ;
F_46 ( & V_208 ) ;
return 0 ;
}
static int F_49 ( struct V_47 * V_20 )
{
F_36 () ;
F_5 ( 0 ) ;
return 0 ;
}
static int F_50 ( struct V_47 * V_20 )
{
F_37 () ;
return 0 ;
}
