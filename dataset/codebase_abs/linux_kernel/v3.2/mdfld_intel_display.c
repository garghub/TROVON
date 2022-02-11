void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
T_1 V_6 = V_7 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_6 = V_8 ;
break;
case 2 :
V_6 = V_9 ;
break;
default:
F_2 ( L_1 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_11 ) == 0 )
break;
}
}
void F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
T_1 V_6 = V_7 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_6 = V_8 ;
break;
case 2 :
V_6 = V_9 ;
break;
default:
F_6 ( V_2 -> V_2 , L_2 ) ;
return;
}
F_3 ( V_2 ) ;
return;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_11 ) == 1 )
break;
}
}
static int F_7 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
T_2 V_16 ,
T_2 V_17 , T_2 V_18 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_19 * V_19 = F_8 ( V_13 ) ;
int V_3 = V_19 -> V_3 ;
T_2 V_20 = V_21 ;
T_2 V_22 = V_23 ;
T_2 V_5 ;
T_3 V_24 = 0 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
int V_29 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_20 = V_30 ;
V_22 = V_31 ;
break;
case 2 :
V_20 = V_32 ;
V_22 = V_33 ;
break;
default:
F_6 ( V_2 -> V_2 , L_1 ) ;
return - V_34 ;
}
#if 1
if ( V_3 != 0 )
return 0 ;
#endif
if ( ! V_16 ) {
F_9 ( V_2 -> V_2 , L_3 ) ;
V_5 = 0 ;
V_5 |= V_35 ;
if ( F_10 ( V_2 , true ) ) {
F_11 ( V_20 , V_5 ) ;
F_11 ( V_22 , 0 ) ;
F_12 ( V_2 ) ;
}
if ( V_19 -> V_36 ) {
V_26 = F_13 ( V_19 -> V_36 ,
struct V_25 , V_37 ) ;
F_14 ( V_26 ) ;
F_15 ( V_19 -> V_36 ) ;
V_19 -> V_36 = NULL ;
}
return 0 ;
}
if ( V_17 != 64 || V_18 != 64 ) {
F_2 ( L_4 ) ;
return - V_34 ;
}
V_28 = F_16 ( V_2 , V_15 , V_16 ) ;
if ( ! V_28 )
return - V_38 ;
if ( V_28 -> V_39 < V_17 * V_18 * 4 ) {
F_9 ( V_2 -> V_2 , L_5 ) ;
return - V_40 ;
}
V_26 = F_13 ( V_28 , struct V_25 , V_37 ) ;
V_29 = F_17 ( V_26 ) ;
if ( V_29 ) {
F_6 ( V_2 -> V_2 , L_6 , V_16 ) ;
return V_29 ;
}
V_24 = V_26 -> V_41 ;
V_19 -> V_42 = V_24 ;
V_5 = 0 ;
V_5 |= ( V_3 << 28 ) ;
V_5 |= V_43 | V_44 ;
if ( F_10 ( V_2 , true ) ) {
F_11 ( V_20 , V_5 ) ;
F_11 ( V_22 , V_24 ) ;
F_12 ( V_2 ) ;
}
if ( V_19 -> V_36 ) {
V_26 = F_13 ( V_19 -> V_36 ,
struct V_25 , V_37 ) ;
F_14 ( V_26 ) ;
F_15 ( V_19 -> V_36 ) ;
V_19 -> V_36 = V_28 ;
}
return 0 ;
}
static int F_18 ( struct V_12 * V_13 , int V_45 , int V_46 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_47 * V_48 = (struct V_47 * ) V_2 -> V_49 ;
struct V_50 * V_51 = V_48 -> V_52 ;
struct V_53 V_54 ;
struct V_19 * V_19 = F_8 ( V_13 ) ;
int V_3 = V_19 -> V_3 ;
T_2 V_55 = V_56 ;
T_2 V_22 = V_23 ;
T_2 V_5 = 0 ;
T_2 V_24 ;
switch ( V_3 ) {
case 0 :
if ( V_51 ) {
V_54 . V_45 = V_45 ;
V_54 . V_46 = V_46 ;
F_19 ( V_2 , V_57 , & V_54 ) ;
F_20 ( V_2 ) ;
} else if ( ! ( V_48 -> V_58 & V_59 ) )
F_21 ( V_2 , V_59 ) ;
break;
case 1 :
V_55 = V_60 ;
V_22 = V_31 ;
break;
case 2 :
if ( V_51 ) {
F_19 ( V_2 , V_61 , & V_54 ) ;
F_20 ( V_2 ) ;
} else if ( ! ( V_48 -> V_58 & V_62 ) )
F_21 ( V_2 , V_62 ) ;
V_55 = V_63 ;
V_22 = V_33 ;
break;
default:
F_2 ( L_1 ) ;
return - V_34 ;
}
#if 1
if ( V_3 != 0 )
return 0 ;
#endif
if ( V_45 < 0 ) {
V_5 |= ( V_64 << V_65 ) ;
V_45 = - V_45 ;
}
if ( V_46 < 0 ) {
V_5 |= ( V_64 << V_66 ) ;
V_46 = - V_46 ;
}
V_5 |= ( ( V_45 & V_67 ) << V_65 ) ;
V_5 |= ( ( V_46 & V_67 ) << V_66 ) ;
V_24 = V_19 -> V_42 ;
if ( F_10 ( V_2 , true ) ) {
F_11 ( V_55 , V_5 ) ;
F_11 ( V_22 , V_24 ) ;
F_12 ( V_2 ) ;
}
return 0 ;
}
void F_22 ( int V_68 )
{
struct V_1 * V_2 = & V_69 ;
int V_70 = V_71 ;
T_1 V_72 ;
V_72 = F_4 ( V_70 ) ;
if ( V_68 ) {
V_72 &= ~ V_73 ;
V_72 |= V_74 ;
} else {
V_72 &= ~ V_74 ;
V_72 |= V_73 ;
}
F_11 ( V_70 , V_72 ) ;
}
int F_23 ( struct V_12 * V_13 , int V_45 , int V_46 , struct V_75 * V_76 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_19 * V_19 = F_8 ( V_13 ) ;
struct V_77 * V_78 = F_24 ( V_13 -> V_79 ) ;
int V_3 = V_19 -> V_3 ;
unsigned long V_80 , V_41 ;
int V_81 = V_82 ;
int V_83 = V_84 ;
int V_85 = V_86 ;
int V_70 = V_71 ;
T_1 V_72 ;
int V_29 = 0 ;
memcpy ( & V_69 , V_2 , sizeof( struct V_1 ) ) ;
if ( ! F_10 ( V_2 , true ) )
return 0 ;
if ( ! V_13 -> V_79 ) {
F_6 ( V_2 -> V_2 , L_7 ) ;
goto V_87;
}
switch ( V_3 ) {
case 0 :
V_81 = V_82 ;
break;
case 1 :
V_81 = V_88 ;
V_83 = V_89 ;
V_85 = V_90 ;
V_70 = V_91 ;
break;
case 2 :
V_81 = V_92 ;
V_83 = V_93 ;
V_85 = V_94 ;
V_70 = V_95 ;
break;
default:
F_6 ( V_2 -> V_2 , L_2 ) ;
return - V_34 ;
}
V_29 = F_17 ( V_78 -> V_96 ) ;
if ( V_29 < 0 )
goto V_97;
V_80 = V_78 -> V_96 -> V_41 ;
V_41 = V_46 * V_13 -> V_79 -> V_98 + V_45 * ( V_13 -> V_79 -> V_99 / 8 ) ;
F_11 ( V_85 , V_13 -> V_79 -> V_98 ) ;
V_72 = F_4 ( V_70 ) ;
V_72 &= ~ V_100 ;
switch ( V_13 -> V_79 -> V_99 ) {
case 8 :
V_72 |= V_101 ;
break;
case 16 :
if ( V_13 -> V_79 -> V_102 == 15 )
V_72 |= V_103 ;
else
V_72 |= V_104 ;
break;
case 24 :
case 32 :
V_72 |= V_73 ;
break;
default:
F_6 ( V_2 -> V_2 , L_8 ) ;
V_29 = - V_34 ;
goto V_97;
}
F_11 ( V_70 , V_72 ) ;
F_9 ( V_2 -> V_2 , L_9 ,
V_80 , V_41 , V_45 , V_46 ) ;
F_11 ( V_81 , V_41 ) ;
F_4 ( V_81 ) ;
F_11 ( V_83 , V_80 ) ;
F_4 ( V_83 ) ;
V_87:
if ( V_76 )
F_14 ( F_24 ( V_76 ) -> V_96 ) ;
V_97:
F_12 ( V_2 ) ;
return V_29 ;
}
void F_25 ( struct V_1 * V_2 , int V_3 )
{
int V_105 = V_106 ;
int V_70 = V_71 ;
int V_107 = V_108 ;
int V_6 = V_7 ;
T_1 V_109 = V_110 ;
T_1 V_5 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_105 = V_111 ;
V_70 = V_91 ;
V_107 = V_89 ;
V_6 = V_8 ;
break;
case 2 :
V_105 = V_106 ;
V_70 = V_95 ;
V_107 = V_112 ;
V_6 = V_9 ;
V_109 = V_110 + V_113 ;
break;
default:
F_6 ( V_2 -> V_2 , L_1 ) ;
return;
}
if ( V_3 != 1 )
F_26 ( V_2 , V_109 , V_114 | V_115 ) ;
V_5 = F_4 ( V_70 ) ;
if ( ( V_5 & V_116 ) != 0 ) {
F_11 ( V_70 ,
V_5 & ~ V_116 ) ;
F_11 ( V_107 , F_4 ( V_107 ) ) ;
F_4 ( V_107 ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_117 ) != 0 ) {
V_5 &= ~ V_117 ;
V_5 |= V_118 | V_119 ;
F_11 ( V_6 , V_5 ) ;
F_4 ( V_6 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_5 = F_4 ( V_105 ) ;
if ( V_5 & V_120 ) {
if ( ( ( V_3 != 1 ) && ! ( ( F_4 ( V_7 ) | F_4 ( V_9 ) ) & V_117 ) )
|| ( V_3 == 1 ) ) {
V_5 &= ~ ( V_120 ) ;
F_11 ( V_105 , V_5 ) ;
F_4 ( V_105 ) ;
F_27 ( 500 ) ;
if ( ! ( V_5 & V_121 ) ) {
F_11 ( V_105 , V_5 | V_121 ) ;
F_27 ( 5000 ) ;
}
}
}
}
static void F_28 ( struct V_12 * V_13 , int V_122 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_47 * V_48 = V_2 -> V_49 ;
struct V_19 * V_19 = F_8 ( V_13 ) ;
int V_3 = V_19 -> V_3 ;
int V_105 = V_106 ;
int V_70 = V_71 ;
int V_107 = V_108 ;
int V_6 = V_7 ;
T_1 V_123 = V_124 ;
T_1 V_109 = V_110 ;
T_1 V_125 = V_48 -> V_125 ;
T_1 V_72 = V_48 -> V_72 ;
T_1 V_126 = V_127 ;
T_1 V_5 ;
bool V_128 ;
int V_129 = 0 ;
if ( ! F_10 ( V_2 , true ) )
return;
if( 0 && V_48 -> V_130 == false && V_122 == 3 ) {
if( V_48 -> V_131 && V_3 == 1 ) {
F_29 ( & V_2 -> V_132 -> V_2 ) ;
}
return;
} else if( V_122 == 0 ) {
}
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_105 = V_133 ;
V_70 = V_91 ;
V_107 = V_134 ;
V_6 = V_8 ;
V_125 = V_48 -> V_135 ;
V_72 = V_48 -> V_136 ;
V_105 = V_111 ;
break;
case 2 :
V_105 = V_106 ;
V_70 = V_95 ;
V_107 = V_112 ;
V_6 = V_9 ;
V_123 = V_137 ;
V_125 = V_48 -> V_138 ;
V_72 = V_48 -> V_139 ;
V_109 = V_110 + V_113 ;
V_126 = V_127 + V_113 ;
break;
default:
F_6 ( V_2 -> V_2 , L_2 ) ;
return;
}
switch ( V_122 ) {
case V_140 :
case V_141 :
case V_142 :
V_5 = F_4 ( V_105 ) ;
if ( ( V_5 & V_120 ) == 0 ) {
if ( V_5 & V_121 ) {
V_5 &= ~ V_121 ;
F_11 ( V_105 , V_5 ) ;
F_27 ( 500 ) ;
}
F_11 ( V_105 , V_5 ) ;
F_4 ( V_105 ) ;
F_27 ( 500 ) ;
F_11 ( V_105 , V_5 | V_120 ) ;
F_4 ( V_105 ) ;
while ( ( V_3 != 2 ) && ( V_129 < 20000 ) && ! ( F_4 ( V_6 ) & V_143 ) ) {
F_27 ( 150 ) ;
V_129 ++ ;
}
}
V_5 = F_4 ( V_70 ) ;
if ( ( V_5 & V_116 ) == 0 ) {
F_11 ( V_70 ,
V_5 | V_116 ) ;
F_11 ( V_107 , F_4 ( V_107 ) ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_117 ) == 0 ) {
F_11 ( V_6 , V_125 ) ;
F_5 ( V_2 , V_3 ) ;
}
if ( ( V_3 == 0 || V_3 == 2 ) &&
( F_30 ( V_2 ) == true ) ) {
F_11 ( V_123 , F_4 ( V_123 ) ) ;
F_31 ( 100 ) ;
if( V_144 & F_4 ( V_123 ) ) {
F_32 ( V_145 L_10 ) ;
} else {
F_32 ( V_145 L_11 ) ;
V_5 = F_4 ( V_70 ) ;
F_11 ( V_70 , V_5 & ~ V_116 ) ;
F_11 ( V_107 , F_4 ( V_107 ) ) ;
F_11 ( 0xb048 , 1 ) ;
F_31 ( 100 ) ;
V_5 = F_4 ( V_6 ) ;
V_5 &= ~ V_117 ;
F_11 ( V_6 , V_5 ) ;
F_31 ( 100 ) ;
F_11 ( V_126 , 0 ) ;
F_31 ( 100 ) ;
F_32 ( V_145 L_12 , F_4 ( 0x70008 ) ) ;
F_32 ( V_145 L_13 , F_4 ( 0xb074 ) ) ;
F_11 ( 0xb004 , F_4 ( 0xb004 ) ) ;
F_11 ( V_126 , 1 ) ;
V_5 = F_4 ( V_70 ) ;
F_11 ( V_70 , V_5 | V_116 ) ;
F_11 ( V_107 , F_4 ( V_107 ) ) ;
F_11 ( 0xb048 , 2 ) ;
F_31 ( 100 ) ;
V_5 = F_4 ( V_6 ) ;
V_5 |= V_117 ;
F_11 ( V_6 , V_5 ) ;
}
}
F_33 ( V_13 ) ;
break;
case V_146 :
if ( V_3 != 1 )
F_26 ( V_2 , V_109 , V_114 | V_115 ) ;
F_11 ( V_147 , V_148 ) ;
V_5 = F_4 ( V_70 ) ;
if ( ( V_5 & V_116 ) != 0 ) {
F_11 ( V_70 ,
V_5 & ~ V_116 ) ;
F_11 ( V_107 , F_4 ( V_107 ) ) ;
F_4 ( V_107 ) ;
}
V_5 = F_4 ( V_6 ) ;
if ( ( V_5 & V_117 ) != 0 ) {
V_5 &= ~ V_117 ;
V_5 |= V_118 | V_119 ;
F_11 ( V_6 , V_5 ) ;
F_4 ( V_6 ) ;
F_1 ( V_2 , V_3 ) ;
}
V_5 = F_4 ( V_105 ) ;
if ( V_5 & V_120 ) {
if ( ( ( V_3 != 1 ) && ! ( ( F_4 ( V_7 ) | F_4 ( V_9 ) ) & V_117 ) )
|| ( V_3 == 1 ) ) {
V_5 &= ~ ( V_120 ) ;
F_11 ( V_105 , V_5 ) ;
F_4 ( V_105 ) ;
F_27 ( 500 ) ;
#if 0
if (!(temp & MDFLD_PWR_GATE_EN)) {
REG_WRITE(dpll_reg, temp | MDFLD_PWR_GATE_EN);
udelay(5000);
}
#endif
}
}
break;
}
V_128 = V_13 -> V_128 && V_122 != V_146 ;
#if 0
if (enabled)
dev_priv->vblank_pipe |= (1 << pipe);
else
dev_priv->vblank_pipe &= ~(1 << pipe);
#endif
F_12 ( V_2 ) ;
}
static const struct V_149 * F_34 ( struct V_12 * V_13 )
{
const struct V_149 * V_150 = NULL ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_47 * V_48 = V_2 -> V_49 ;
if ( F_35 ( V_13 , V_151 )
|| F_35 ( V_13 , V_152 ) ) {
if ( ( V_153 == V_154 ) || ( V_153 == V_155 ) )
V_150 = & V_156 [ V_157 ] ;
else if ( V_153 == V_158 )
V_150 = & V_156 [ V_159 ] ;
else if ( ( V_153 == V_160 ) && ( V_48 -> V_161 == 166 ) )
V_150 = & V_156 [ V_162 ] ;
else if ( ( V_153 == V_160 ) &&
( V_48 -> V_161 == 100 || V_48 -> V_161 == 200 ) )
V_150 = & V_156 [ V_163 ] ;
} else if ( F_35 ( V_13 , V_164 ) ) {
if ( ( V_153 == V_154 ) || ( V_153 == V_155 ) )
V_150 = & V_156 [ V_165 ] ;
else if ( V_153 == V_158 )
V_150 = & V_156 [ V_166 ] ;
else if ( ( V_153 == V_160 ) && ( V_48 -> V_161 == 166 ) )
V_150 = & V_156 [ V_167 ] ;
else if ( ( V_153 == V_160 ) &&
( V_48 -> V_161 == 100 || V_48 -> V_161 == 200 ) )
V_150 = & V_156 [ V_168 ] ;
} else {
V_150 = NULL ;
F_6 ( V_2 -> V_2 , L_14 ) ;
}
return V_150 ;
}
static void F_36 ( int V_169 , struct V_170 * clock )
{
clock -> V_171 = ( V_169 * clock -> V_172 ) / clock -> V_173 ;
}
static bool
F_37 ( struct V_12 * V_13 , int V_174 , int V_169 ,
struct V_170 * V_175 )
{
struct V_170 clock ;
const struct V_149 * V_150 = F_34 ( V_13 ) ;
int V_176 = V_174 ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
for ( clock . V_172 = V_150 -> V_172 . V_177 ; clock . V_172 <= V_150 -> V_172 . V_178 ; clock . V_172 ++ ) {
for ( clock . V_173 = V_150 -> V_173 . V_177 ; clock . V_173 <= V_150 -> V_173 . V_178 ;
clock . V_173 ++ ) {
int V_179 ;
F_36 ( V_169 , & clock ) ;
V_179 = abs ( clock . V_171 - V_174 ) ;
if ( V_179 < V_176 ) {
* V_175 = clock ;
V_176 = V_179 ;
}
}
}
return V_176 != V_174 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_180 ;
V_180 = F_4 ( V_181 ) ;
if ( ( V_180 & V_182 ) == 0 )
return - 1 ;
return ( V_180 >> 29 ) & 3 ;
}
static int F_39 ( struct V_12 * V_13 ,
struct V_183 * V_122 ,
struct V_183 * V_184 ,
int V_45 , int V_46 ,
struct V_75 * V_76 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_19 * V_19 = F_8 ( V_13 ) ;
struct V_47 * V_48 = V_2 -> V_49 ;
int V_3 = V_19 -> V_3 ;
int V_185 = V_186 ;
int V_105 = V_106 ;
int V_70 = V_71 ;
int V_6 = V_7 ;
int V_187 = V_188 ;
int V_189 = V_190 ;
int V_191 = V_192 ;
int V_193 = V_194 ;
int V_195 = V_196 ;
int V_197 = V_198 ;
int V_199 = V_200 ;
int V_201 = V_202 ;
int V_203 = V_204 ;
T_1 * V_125 = & V_48 -> V_125 ;
T_1 * V_72 = & V_48 -> V_72 ;
int V_169 = 0 ;
int V_205 = 0 , V_206 = 0 , V_207 = 1 , V_208 = 0 , V_209 = 0 , V_210 = 0 ;
struct V_170 clock ;
bool V_211 ;
T_1 V_212 = 0 , V_213 = 0 ;
bool V_214 = false , V_215 = false , V_216 = false ;
bool V_217 = false , V_218 = false , V_219 = false ;
struct V_220 * V_221 = & V_2 -> V_221 ;
struct V_222 * V_222 = NULL ;
T_4 V_223 = V_224 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
int V_129 = 0 ;
F_9 ( V_2 -> V_2 , L_15 , V_3 ) ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_185 = V_229 ;
V_105 = V_133 ;
V_70 = V_91 ;
V_6 = V_8 ;
V_187 = V_230 ;
V_189 = V_231 ;
V_191 = V_232 ;
V_193 = V_233 ;
V_195 = V_234 ;
V_197 = V_235 ;
V_199 = V_236 ;
V_201 = V_237 ;
V_203 = V_238 ;
V_125 = & V_48 -> V_135 ;
V_72 = & V_48 -> V_136 ;
V_185 = V_239 ;
V_105 = V_111 ;
break;
case 2 :
V_105 = V_106 ;
V_70 = V_95 ;
V_6 = V_9 ;
V_187 = V_240 ;
V_189 = V_241 ;
V_191 = V_242 ;
V_193 = V_243 ;
V_195 = V_244 ;
V_197 = V_245 ;
V_199 = V_246 ;
V_201 = V_247 ;
V_203 = V_248 ;
V_125 = & V_48 -> V_138 ;
V_72 = & V_48 -> V_139 ;
break;
default:
F_2 ( L_1 ) ;
return 0 ;
}
F_9 ( V_2 -> V_2 , L_16 ,
V_184 -> V_249 ) ;
F_9 ( V_2 -> V_2 , L_17 ,
V_184 -> V_250 ) ;
F_9 ( V_2 -> V_2 , L_18 ,
V_184 -> V_251 ) ;
F_9 ( V_2 -> V_2 , L_19 ,
V_184 -> V_252 ) ;
F_9 ( V_2 -> V_2 , L_20 ,
V_184 -> V_253 ) ;
F_9 ( V_2 -> V_2 , L_21 ,
V_184 -> V_254 ) ;
F_9 ( V_2 -> V_2 , L_22 ,
V_184 -> V_255 ) ;
F_9 ( V_2 -> V_2 , L_23 ,
V_184 -> V_256 ) ;
F_9 ( V_2 -> V_2 , L_24 ,
V_184 -> clock ) ;
F_9 ( V_2 -> V_2 , L_25 ,
V_122 -> V_249 ) ;
F_9 ( V_2 -> V_2 , L_26 ,
V_122 -> V_250 ) ;
if ( ! F_10 ( V_2 , true ) )
return 0 ;
memcpy ( & V_19 -> V_257 , V_122 , sizeof( struct V_183 ) ) ;
memcpy ( & V_19 -> V_258 , V_184 , sizeof( struct V_183 ) ) ;
F_40 (connector, &mode_config->connector_list, head) {
V_226 = V_228 -> V_226 ;
if( ! V_226 )
continue;
if ( V_226 -> V_13 != V_13 )
continue;
V_222 = F_41 ( V_228 ) ;
F_9 ( V_2 -> V_2 , L_27 , V_222 -> type ) ;
switch ( V_222 -> type ) {
case V_259 :
V_215 = true ;
break;
case V_260 :
V_216 = true ;
break;
case V_261 :
V_214 = true ;
break;
case V_151 :
V_217 = true ;
break;
case V_152 :
V_218 = true ;
break;
case V_164 :
V_219 = true ;
break;
}
}
F_11 ( V_147 , V_148 ) ;
if ( F_38 ( V_2 ) == V_3 )
F_11 ( V_181 , 0 ) ;
if ( V_3 == 1 ) {
F_11 ( V_199 , ( ( F_42 ( V_122 -> V_262 , V_184 -> V_262 ) - 1 ) << 16 )
| ( F_42 ( V_122 -> V_263 , V_184 -> V_263 ) - 1 ) ) ;
F_11 ( V_203 , ( ( V_122 -> V_263 - 1 ) << 16 )
| ( V_122 -> V_262 - 1 ) ) ;
} else {
F_11 ( V_199 , ( ( V_122 -> V_262 - 1 ) << 16 ) | ( V_122 -> V_263 - 1 ) ) ;
F_11 ( V_203 , ( ( V_122 -> V_263 - 1 ) << 16 ) | ( V_122 -> V_262 - 1 ) ) ;
}
F_11 ( V_201 , 0 ) ;
if ( V_222 )
F_43 ( & V_222 -> V_22 ,
V_2 -> V_221 . V_264 , & V_223 ) ;
if ( V_223 == V_265 ) {
int V_266 = 0 , V_267 = 0 ;
V_266 = ( V_184 -> V_263 - V_122 -> V_263 ) / 2 ;
V_267 = ( V_184 -> V_262 - V_122 -> V_262 ) / 2 ;
F_11 ( V_187 , ( V_122 -> V_263 - 1 ) |
( ( V_184 -> V_268 - 1 ) << 16 ) ) ;
F_11 ( V_193 , ( V_122 -> V_262 - 1 ) |
( ( V_184 -> V_269 - 1 ) << 16 ) ) ;
F_11 ( V_189 , ( V_184 -> V_270 - V_266 - 1 ) |
( ( V_184 -> V_271 - V_266 - 1 ) << 16 ) ) ;
F_11 ( V_191 , ( V_184 -> V_272 - V_266 - 1 ) |
( ( V_184 -> V_273 - V_266 - 1 ) << 16 ) ) ;
F_11 ( V_195 , ( V_184 -> V_274 - V_267 - 1 ) |
( ( V_184 -> V_275 - V_267 - 1 ) << 16 ) ) ;
F_11 ( V_197 , ( V_184 -> V_276 - V_267 - 1 ) |
( ( V_184 -> V_277 - V_267 - 1 ) << 16 ) ) ;
} else {
F_11 ( V_187 , ( V_184 -> V_263 - 1 ) |
( ( V_184 -> V_268 - 1 ) << 16 ) ) ;
F_11 ( V_193 , ( V_184 -> V_262 - 1 ) |
( ( V_184 -> V_269 - 1 ) << 16 ) ) ;
F_11 ( V_189 , ( V_184 -> V_270 - 1 ) |
( ( V_184 -> V_271 - 1 ) << 16 ) ) ;
F_11 ( V_191 , ( V_184 -> V_272 - 1 ) |
( ( V_184 -> V_273 - 1 ) << 16 ) ) ;
F_11 ( V_195 , ( V_184 -> V_274 - 1 ) |
( ( V_184 -> V_275 - 1 ) << 16 ) ) ;
F_11 ( V_197 , ( V_184 -> V_276 - 1 ) |
( ( V_184 -> V_277 - 1 ) << 16 ) ) ;
}
{
struct V_278 * V_279 =
V_13 -> V_280 ;
V_279 -> V_281 ( V_13 , V_45 , V_46 , V_76 ) ;
}
* V_125 = V_117 ;
* V_72 = F_4 ( V_70 ) ;
* V_72 |= V_3 << V_282 ;
* V_72 |= V_116 ;
if ( V_218 )
{
goto V_283;
}
V_208 = V_184 -> clock ;
if ( V_219 ) {
if ( ( V_153 == V_154 ) || ( V_153 == V_155 ) )
{
V_169 = 19200 ;
if ( V_217 || V_218 )
{
V_205 = 1 , V_206 = 8 ;
} else if ( V_219 ) {
V_205 = 1 , V_206 = 10 ;
}
} else if ( V_153 == V_158 ) {
V_169 = 25000 ;
if ( V_217 || V_218 )
{
V_205 = 1 , V_206 = 8 ;
} else if ( V_219 ) {
V_205 = 1 , V_206 = 10 ;
}
} else if ( ( V_153 == V_160 ) && ( V_48 -> V_161 == 166 ) ) {
V_169 = 83000 ;
if ( V_217 || V_218 )
{
V_205 = 4 , V_206 = 8 ;
} else if ( V_219 ) {
V_205 = 4 , V_206 = 10 ;
}
} else if ( ( V_153 == V_160 ) &&
( V_48 -> V_161 == 100 || V_48 -> V_161 == 200 ) ) {
V_169 = 100000 ;
if ( V_217 || V_218 )
{
V_205 = 4 , V_206 = 8 ;
} else if ( V_219 ) {
V_205 = 4 , V_206 = 10 ;
}
}
if ( V_217 )
V_207 = V_48 -> V_284 / 8 ;
else if ( V_218 )
V_207 = V_48 -> V_285 / 8 ;
V_210 = V_208 * V_205 * V_206 * V_207 ;
F_9 ( V_2 -> V_2 , L_28 , V_208 , V_205 , V_206 ) ;
F_9 ( V_2 -> V_2 , L_29 , V_184 -> clock , V_210 ) ;
V_211 = F_37 ( V_13 , V_210 , V_169 , & clock ) ;
if ( ! V_211 ) {
F_6 ( V_2 -> V_2 ,
L_30 ) ;
} else {
V_209 = V_286 [ ( clock . V_172 - V_287 ) ] ;
F_9 ( V_2 -> V_2 , L_31
L_32 , clock . V_171 , clock . V_172 ,
clock . V_173 , V_209 ) ;
}
V_212 = F_4 ( V_105 ) ;
if ( V_212 & V_120 ) {
V_212 &= ~ V_120 ;
F_11 ( V_105 , V_212 ) ;
F_4 ( V_105 ) ;
F_27 ( 500 ) ;
F_11 ( V_185 , 0 ) ;
V_212 &= ~ V_288 ;
F_11 ( V_105 , V_212 ) ;
F_27 ( 500 ) ;
}
if ( V_212 & V_121 ) {
V_212 &= ~ V_121 ;
F_11 ( V_105 , V_212 ) ;
F_27 ( 500 ) ;
}
V_212 = 0 ;
#if 0
if ((ksel == KSEL_CRYSTAL_19) || (ksel == KSEL_BYPASS_19) || (ksel == KSEL_BYPASS_25)) {
dpll &= ~MDFLD_INPUT_REF_SEL;
} else if (ksel == KSEL_BYPASS_83_100) {
dpll |= MDFLD_INPUT_REF_SEL;
}
#endif
if ( V_219 )
V_212 |= V_289 ;
V_213 = ( V_205 / 2 ) << 16 ;
V_213 |= V_209 ;
V_212 |= ( 1 << ( clock . V_173 - 2 ) ) << 17 ;
#if 0
dpll = 0x00050000;
fp = 0x000001be;
#endif
#if 0
dpll = 0x02010000;
fp = 0x000000d2;
#endif
} else {
#if 0
dpll = 0x00020000;
fp = 0x00000156;
#endif
V_212 = 0x00800000 ;
V_213 = 0x000000c1 ;
}
F_11 ( V_185 , V_213 ) ;
F_11 ( V_105 , V_212 ) ;
F_27 ( 500 ) ;
V_212 |= V_120 ;
F_11 ( V_105 , V_212 ) ;
F_4 ( V_105 ) ;
while ( ( V_129 < 20000 ) && ! ( F_4 ( V_6 ) & V_143 ) ) {
F_27 ( 150 ) ;
V_129 ++ ;
}
if ( V_217 )
goto V_283;
F_9 ( V_2 -> V_2 , L_33 , V_217 ) ;
F_11 ( V_6 , * V_125 ) ;
F_4 ( V_6 ) ;
F_11 ( V_70 , * V_72 ) ;
F_3 ( V_2 ) ;
V_283:
F_12 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_12 * V_13 )
{
struct V_278 * V_279 = V_13 -> V_280 ;
V_279 -> V_290 ( V_13 , V_146 ) ;
}
static void F_45 ( struct V_12 * V_13 )
{
struct V_278 * V_279 = V_13 -> V_280 ;
V_279 -> V_290 ( V_13 , V_140 ) ;
}
static bool F_46 ( struct V_12 * V_13 ,
struct V_183 * V_122 ,
struct V_183 * V_184 )
{
return true ;
}
