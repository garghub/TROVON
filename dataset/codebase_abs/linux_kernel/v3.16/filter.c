void * F_1 ( const struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
T_1 * V_5 = NULL ;
if ( V_3 >= V_6 )
V_5 = F_2 ( V_2 ) + V_3 - V_6 ;
else if ( V_3 >= V_7 )
V_5 = F_3 ( V_2 ) + V_3 - V_7 ;
if ( V_5 >= V_2 -> V_8 && V_5 + V_4 <= F_4 ( V_2 ) )
return V_5 ;
return NULL ;
}
static inline void * F_5 ( const struct V_1 * V_2 , int V_3 ,
unsigned int V_4 , void * V_9 )
{
if ( V_3 >= 0 )
return F_6 ( V_2 , V_3 , V_4 , V_9 ) ;
return F_1 ( V_2 , V_3 , V_4 ) ;
}
int F_7 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_12 ;
struct F_7 * V_13 ;
if ( F_8 ( V_2 ) && ! F_9 ( V_11 , V_14 ) )
return - V_15 ;
V_12 = F_10 ( V_11 , V_2 ) ;
if ( V_12 )
return V_12 ;
F_11 () ;
V_13 = F_12 ( V_11 -> F_7 ) ;
if ( V_13 ) {
unsigned int V_16 = F_13 ( V_13 , V_2 ) ;
V_12 = V_16 ? F_14 ( V_2 , V_16 ) : - V_17 ;
}
F_15 () ;
return V_12 ;
}
T_2 T_3 F_16 ( T_3 V_18 , T_3 V_19 , T_3 V_20 , T_3 V_21 , T_3 V_22 )
{
return 0 ;
}
static unsigned int F_17 ( void * V_23 , const struct V_24 * V_25 )
{
T_3 V_26 [ V_27 / sizeof( T_3 ) ] ;
T_3 V_28 [ V_29 ] , V_30 ;
static const void * V_31 [ 256 ] = {
[ 0 ... 255 ] = && V_32 ,
[ V_33 | V_34 | V_35 ] = && V_36 ,
[ V_33 | V_34 | V_37 ] = && V_38 ,
[ V_33 | V_39 | V_35 ] = && V_40 ,
[ V_33 | V_39 | V_37 ] = && V_41 ,
[ V_33 | V_42 | V_35 ] = && V_43 ,
[ V_33 | V_42 | V_37 ] = && V_44 ,
[ V_33 | V_45 | V_35 ] = && V_46 ,
[ V_33 | V_45 | V_37 ] = && V_47 ,
[ V_33 | V_48 | V_35 ] = && V_49 ,
[ V_33 | V_48 | V_37 ] = && V_50 ,
[ V_33 | V_51 | V_35 ] = && V_52 ,
[ V_33 | V_51 | V_37 ] = && V_53 ,
[ V_33 | V_54 | V_35 ] = && V_55 ,
[ V_33 | V_54 | V_37 ] = && V_56 ,
[ V_33 | V_57 | V_35 ] = && V_58 ,
[ V_33 | V_57 | V_37 ] = && V_59 ,
[ V_33 | V_60 | V_35 ] = && V_61 ,
[ V_33 | V_60 | V_37 ] = && V_62 ,
[ V_33 | V_63 | V_35 ] = && V_64 ,
[ V_33 | V_63 | V_37 ] = && V_65 ,
[ V_33 | V_66 | V_35 ] = && V_67 ,
[ V_33 | V_66 | V_37 ] = && V_68 ,
[ V_33 | V_69 ] = && V_70 ,
[ V_33 | V_71 | V_72 ] = && V_73 ,
[ V_33 | V_71 | V_74 ] = && V_75 ,
[ V_76 | V_34 | V_35 ] = && V_77 ,
[ V_76 | V_34 | V_37 ] = && V_78 ,
[ V_76 | V_39 | V_35 ] = && V_79 ,
[ V_76 | V_39 | V_37 ] = && V_80 ,
[ V_76 | V_42 | V_35 ] = && V_81 ,
[ V_76 | V_42 | V_37 ] = && V_82 ,
[ V_76 | V_45 | V_35 ] = && V_83 ,
[ V_76 | V_45 | V_37 ] = && V_84 ,
[ V_76 | V_48 | V_35 ] = && V_85 ,
[ V_76 | V_48 | V_37 ] = && V_86 ,
[ V_76 | V_51 | V_35 ] = && V_87 ,
[ V_76 | V_51 | V_37 ] = && V_88 ,
[ V_76 | V_54 | V_35 ] = && V_89 ,
[ V_76 | V_54 | V_37 ] = && V_90 ,
[ V_76 | V_57 | V_35 ] = && V_91 ,
[ V_76 | V_57 | V_37 ] = && V_92 ,
[ V_76 | V_60 | V_35 ] = && V_93 ,
[ V_76 | V_60 | V_37 ] = && V_94 ,
[ V_76 | V_95 | V_35 ] = && V_96 ,
[ V_76 | V_95 | V_37 ] = && V_97 ,
[ V_76 | V_63 | V_35 ] = && V_98 ,
[ V_76 | V_63 | V_37 ] = && V_99 ,
[ V_76 | V_66 | V_35 ] = && V_100 ,
[ V_76 | V_66 | V_37 ] = && V_101 ,
[ V_76 | V_69 ] = && V_102 ,
[ V_103 | V_104 ] = && V_105 ,
[ V_103 | V_106 ] = && V_107 ,
[ V_103 | V_108 | V_35 ] = && V_109 ,
[ V_103 | V_108 | V_37 ] = && V_110 ,
[ V_103 | V_111 | V_35 ] = && V_112 ,
[ V_103 | V_111 | V_37 ] = && V_113 ,
[ V_103 | V_114 | V_35 ] = && V_115 ,
[ V_103 | V_114 | V_37 ] = && V_116 ,
[ V_103 | V_117 | V_35 ] = && V_118 ,
[ V_103 | V_117 | V_37 ] = && V_119 ,
[ V_103 | V_120 | V_35 ] = && V_121 ,
[ V_103 | V_120 | V_37 ] = && V_122 ,
[ V_103 | V_123 | V_35 ] = && V_124 ,
[ V_103 | V_123 | V_37 ] = && V_125 ,
[ V_103 | V_126 | V_35 ] = && V_127 ,
[ V_103 | V_126 | V_37 ] = && V_128 ,
[ V_103 | V_129 ] = && V_130 ,
[ V_131 | V_132 | V_133 ] = && V_134 ,
[ V_131 | V_132 | V_135 ] = && V_136 ,
[ V_131 | V_132 | V_137 ] = && V_138 ,
[ V_131 | V_132 | V_139 ] = && V_140 ,
[ V_131 | V_141 | V_137 ] = && V_142 ,
[ V_131 | V_141 | V_139 ] = && V_143 ,
[ V_144 | V_132 | V_133 ] = && V_145 ,
[ V_144 | V_132 | V_135 ] = && V_146 ,
[ V_144 | V_132 | V_137 ] = && V_147 ,
[ V_144 | V_132 | V_139 ] = && V_148 ,
[ V_149 | V_132 | V_133 ] = && V_150 ,
[ V_149 | V_132 | V_135 ] = && V_151 ,
[ V_149 | V_132 | V_137 ] = && V_152 ,
[ V_149 | V_132 | V_139 ] = && V_153 ,
[ V_154 | V_155 | V_137 ] = && V_156 ,
[ V_154 | V_155 | V_135 ] = && V_157 ,
[ V_154 | V_155 | V_133 ] = && V_158 ,
[ V_154 | V_159 | V_137 ] = && V_160 ,
[ V_154 | V_159 | V_135 ] = && V_161 ,
[ V_154 | V_159 | V_133 ] = && V_162 ,
} ;
void * V_5 ;
int V_163 ;
#define F_18 ({ insn++; goto select_insn; })
#define F_19 ({ insn++; goto select_insn; })
V_164 = ( T_3 ) ( unsigned long ) & V_26 [ F_20 ( V_26 ) ] ;
V_165 = ( T_3 ) ( unsigned long ) V_23 ;
V_28 [ V_166 ] = 0 ;
V_28 [ V_167 ] = 0 ;
V_168:
goto * V_31 [ V_25 -> V_169 ] ;
#define F_21 ( T_4 , T_5 ) \
ALU64_##OPCODE##_X: \
DST = DST OP SRC; \
CONT; \
ALU_##OPCODE##_X: \
DST = (u32) DST OP (u32) SRC; \
CONT; \
ALU64_##OPCODE##_K: \
DST = DST OP IMM; \
CONT; \
ALU_##OPCODE##_K: \
DST = (u32) DST OP (u32) IMM; \
CONT;
F_21 (ADD, +)
F_21 (SUB, -)
F_21 (AND, &)
F_21 (OR, |)
F_21 (LSH, <<)
F_21 (RSH, >>)
F_21 (XOR, ^)
F_21 (MUL, *)
#undef F_21
V_70:
V_170 = ( V_171 ) - V_170 ;
F_18 ;
V_102:
V_170 = - V_170 ;
F_18 ;
V_61:
V_170 = ( V_171 ) V_172 ;
F_18 ;
V_62:
V_170 = ( V_171 ) V_173 ;
F_18 ;
V_93:
V_170 = V_172 ;
F_18 ;
V_94:
V_170 = V_173 ;
F_18 ;
V_96:
( * ( V_174 * ) & V_170 ) >>= V_172 ;
F_18 ;
V_97:
( * ( V_174 * ) & V_170 ) >>= V_173 ;
F_18 ;
V_100:
if ( F_22 ( V_172 == 0 ) )
return 0 ;
V_30 = V_170 ;
V_170 = F_23 ( V_30 , V_172 ) ;
F_18 ;
V_67:
if ( F_22 ( V_172 == 0 ) )
return 0 ;
V_30 = ( V_171 ) V_170 ;
V_170 = F_23 ( V_30 , ( V_171 ) V_172 ) ;
F_18 ;
V_101:
V_30 = V_170 ;
V_170 = F_23 ( V_30 , V_173 ) ;
F_18 ;
V_68:
V_30 = ( V_171 ) V_170 ;
V_170 = F_23 ( V_30 , ( V_171 ) V_173 ) ;
F_18 ;
V_98:
if ( F_22 ( V_172 == 0 ) )
return 0 ;
F_23 ( V_170 , V_172 ) ;
F_18 ;
V_64:
if ( F_22 ( V_172 == 0 ) )
return 0 ;
V_30 = ( V_171 ) V_170 ;
F_23 ( V_30 , ( V_171 ) V_172 ) ;
V_170 = ( V_171 ) V_30 ;
F_18 ;
V_99:
F_23 ( V_170 , V_173 ) ;
F_18 ;
V_65:
V_30 = ( V_171 ) V_170 ;
F_23 ( V_30 , ( V_171 ) V_173 ) ;
V_170 = ( V_171 ) V_30 ;
F_18 ;
V_73:
switch ( V_173 ) {
case 16 :
V_170 = ( V_175 V_176 ) F_24 ( V_170 ) ;
break;
case 32 :
V_170 = ( V_175 V_171 ) F_25 ( V_170 ) ;
break;
case 64 :
V_170 = ( V_175 T_3 ) F_26 ( V_170 ) ;
break;
}
F_18 ;
V_75:
switch ( V_173 ) {
case 16 :
V_170 = ( V_175 V_176 ) F_27 ( V_170 ) ;
break;
case 32 :
V_170 = ( V_175 V_171 ) F_28 ( V_170 ) ;
break;
case 64 :
V_170 = ( V_175 T_3 ) F_29 ( V_170 ) ;
break;
}
F_18 ;
V_105:
V_177 = ( F_16 + V_25 -> V_178 ) ( V_179 , V_180 , V_181 ,
V_182 , V_183 ) ;
F_18 ;
V_107:
V_25 += V_25 -> V_163 ;
F_18 ;
V_109:
if ( V_170 == V_172 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_110:
if ( V_170 == V_173 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_112:
if ( V_170 != V_172 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_113:
if ( V_170 != V_173 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_115:
if ( V_170 > V_172 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_116:
if ( V_170 > V_173 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_118:
if ( V_170 >= V_172 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_119:
if ( V_170 >= V_173 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_121:
if ( ( ( V_174 ) V_170 ) > ( ( V_174 ) V_172 ) ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_122:
if ( ( ( V_174 ) V_170 ) > ( ( V_174 ) V_173 ) ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_124:
if ( ( ( V_174 ) V_170 ) >= ( ( V_174 ) V_172 ) ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_125:
if ( ( ( V_174 ) V_170 ) >= ( ( V_174 ) V_173 ) ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_127:
if ( V_170 & V_172 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_128:
if ( V_170 & V_173 ) {
V_25 += V_25 -> V_163 ;
F_19 ;
}
F_18 ;
V_130:
return V_177 ;
#define F_30 ( T_6 , T_7 ) \
STX_MEM_##SIZEOP: \
*(SIZE *)(unsigned long) (DST + insn->off) = SRC; \
CONT; \
ST_MEM_##SIZEOP: \
*(SIZE *)(unsigned long) (DST + insn->off) = IMM; \
CONT; \
LDX_MEM_##SIZEOP: \
DST = *(SIZE *)(unsigned long) (SRC + insn->off); \
CONT;
F_30 (B, u8)
F_30 (H, u16)
F_30 (W, u32)
F_30 (DW, u64)
#undef F_30
V_142:
F_31 ( ( V_171 ) V_172 , ( V_184 * ) ( unsigned long )
( V_170 + V_25 -> V_163 ) ) ;
F_18 ;
V_143:
F_32 ( ( T_3 ) V_172 , ( V_185 * ) ( unsigned long )
( V_170 + V_25 -> V_163 ) ) ;
F_18 ;
V_156:
V_163 = V_173 ;
V_186:
V_5 = F_5 ( (struct V_1 * ) ( unsigned long ) V_187 , V_163 , 4 , & V_30 ) ;
if ( F_33 ( V_5 != NULL ) ) {
V_177 = F_34 ( V_5 ) ;
F_18 ;
}
return 0 ;
V_157:
V_163 = V_173 ;
V_188:
V_5 = F_5 ( (struct V_1 * ) ( unsigned long ) V_187 , V_163 , 2 , & V_30 ) ;
if ( F_33 ( V_5 != NULL ) ) {
V_177 = F_35 ( V_5 ) ;
F_18 ;
}
return 0 ;
V_158:
V_163 = V_173 ;
V_189:
V_5 = F_5 ( (struct V_1 * ) ( unsigned long ) V_187 , V_163 , 1 , & V_30 ) ;
if ( F_33 ( V_5 != NULL ) ) {
V_177 = * ( T_1 * ) V_5 ;
F_18 ;
}
return 0 ;
V_160:
V_163 = V_173 + V_172 ;
goto V_186;
V_161:
V_163 = V_173 + V_172 ;
goto V_188;
V_162:
V_163 = V_173 + V_172 ;
goto V_189;
V_32:
F_36 ( 1 , L_1 , V_25 -> V_169 ) ;
return 0 ;
}
static unsigned int F_37 ( void )
{
struct V_1 V_190 = { . V_191 = ~ 0 , } ;
T_1 * V_192 = ( T_1 * ) & V_190 ;
unsigned int V_163 ;
for ( V_163 = 0 ; V_163 < sizeof( struct V_1 ) ; V_163 ++ ) {
if ( V_192 [ V_163 ] == V_193 )
return V_163 ;
}
F_38 ( L_2 , V_194 ) ;
return - 1 ;
}
static T_3 F_39 ( T_3 V_23 , T_3 V_195 , T_3 V_196 , T_3 V_21 , T_3 V_22 )
{
return F_40 ( (struct V_1 * ) ( unsigned long ) V_23 ) ;
}
static T_3 F_41 ( T_3 V_23 , T_3 V_195 , T_3 V_196 , T_3 V_21 , T_3 V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) ( unsigned long ) V_23 ;
struct V_197 * V_198 ;
if ( F_42 ( V_2 ) )
return 0 ;
if ( V_2 -> V_199 < sizeof( struct V_197 ) )
return 0 ;
if ( V_195 > V_2 -> V_199 - sizeof( struct V_197 ) )
return 0 ;
V_198 = F_43 ( (struct V_197 * ) & V_2 -> V_200 [ V_195 ] , V_2 -> V_199 - V_195 , V_196 ) ;
if ( V_198 )
return ( void * ) V_198 - ( void * ) V_2 -> V_200 ;
return 0 ;
}
static T_3 F_44 ( T_3 V_23 , T_3 V_195 , T_3 V_196 , T_3 V_21 , T_3 V_22 )
{
struct V_1 * V_2 = (struct V_1 * ) ( unsigned long ) V_23 ;
struct V_197 * V_198 ;
if ( F_42 ( V_2 ) )
return 0 ;
if ( V_2 -> V_199 < sizeof( struct V_197 ) )
return 0 ;
if ( V_195 > V_2 -> V_199 - sizeof( struct V_197 ) )
return 0 ;
V_198 = (struct V_197 * ) & V_2 -> V_200 [ V_195 ] ;
if ( V_198 -> V_201 > V_2 -> V_199 - V_195 )
return 0 ;
V_198 = F_45 ( V_198 , V_196 ) ;
if ( V_198 )
return ( void * ) V_198 - ( void * ) V_2 -> V_200 ;
return 0 ;
}
static T_3 F_46 ( T_3 V_23 , T_3 V_195 , T_3 V_196 , T_3 V_21 , T_3 V_22 )
{
return F_47 () ;
}
static T_3 F_48 ( T_3 V_23 , T_3 V_195 , T_3 V_196 , T_3 V_21 , T_3 V_22 )
{
return F_49 () ;
}
static bool F_50 ( struct V_202 * V_203 ,
struct V_24 * * V_204 )
{
struct V_24 * V_25 = * V_204 ;
switch ( V_203 -> V_3 ) {
case V_205 + V_206 :
F_51 ( F_52 ( struct V_1 , V_207 ) != 2 ) ;
* V_25 ++ = F_53 ( V_135 , V_166 , V_208 ,
F_54 ( struct V_1 , V_207 ) ) ;
* V_25 = F_55 ( V_209 , V_166 , 16 ) ;
break;
case V_205 + V_210 :
* V_25 = F_53 ( V_133 , V_166 , V_208 ,
F_37 () ) ;
if ( V_25 -> V_163 < 0 )
return false ;
V_25 ++ ;
* V_25 = F_56 ( V_42 , V_166 , V_193 ) ;
#ifdef F_57
V_25 ++ ;
* V_25 = F_56 ( V_51 , V_166 , 5 ) ;
#endif
break;
case V_205 + V_211 :
case V_205 + V_212 :
F_51 ( F_52 ( struct V_213 , V_214 ) != 4 ) ;
F_51 ( F_52 ( struct V_213 , type ) != 2 ) ;
F_51 ( F_58 ( F_52 ( struct V_1 , V_215 ) ) < 0 ) ;
* V_25 ++ = F_53 ( F_58 ( F_52 ( struct V_1 , V_215 ) ) ,
V_216 , V_208 ,
F_54 ( struct V_1 , V_215 ) ) ;
* V_25 ++ = F_59 ( V_111 , V_216 , 0 , 1 ) ;
* V_25 ++ = F_60 () ;
if ( V_203 -> V_3 == V_205 + V_211 )
* V_25 = F_53 ( V_137 , V_166 , V_216 ,
F_54 ( struct V_213 , V_214 ) ) ;
else
* V_25 = F_53 ( V_135 , V_166 , V_216 ,
F_54 ( struct V_213 , type ) ) ;
break;
case V_205 + V_217 :
F_51 ( F_52 ( struct V_1 , V_218 ) != 4 ) ;
* V_25 = F_53 ( V_137 , V_166 , V_208 ,
F_54 ( struct V_1 , V_218 ) ) ;
break;
case V_205 + V_219 :
F_51 ( F_52 ( struct V_1 , V_220 ) != 4 ) ;
* V_25 = F_53 ( V_137 , V_166 , V_208 ,
F_54 ( struct V_1 , V_220 ) ) ;
break;
case V_205 + V_221 :
F_51 ( F_52 ( struct V_1 , V_222 ) != 2 ) ;
* V_25 = F_53 ( V_135 , V_166 , V_208 ,
F_54 ( struct V_1 , V_222 ) ) ;
break;
case V_205 + V_223 :
case V_205 + V_224 :
F_51 ( F_52 ( struct V_1 , V_225 ) != 2 ) ;
F_51 ( V_226 != 0x1000 ) ;
* V_25 ++ = F_53 ( V_135 , V_166 , V_208 ,
F_54 ( struct V_1 , V_225 ) ) ;
if ( V_203 -> V_3 == V_205 + V_223 ) {
* V_25 = F_56 ( V_42 , V_166 ,
~ V_226 ) ;
} else {
* V_25 ++ = F_56 ( V_51 , V_166 , 12 ) ;
* V_25 = F_56 ( V_42 , V_166 , 1 ) ;
}
break;
case V_205 + V_227 :
case V_205 + V_228 :
case V_205 + V_229 :
case V_205 + V_230 :
case V_205 + V_231 :
* V_25 ++ = F_61 ( V_232 , V_208 ) ;
* V_25 ++ = F_61 ( V_233 , V_166 ) ;
* V_25 ++ = F_61 ( V_234 , V_167 ) ;
switch ( V_203 -> V_3 ) {
case V_205 + V_227 :
* V_25 = F_62 ( F_39 ) ;
break;
case V_205 + V_228 :
* V_25 = F_62 ( F_41 ) ;
break;
case V_205 + V_229 :
* V_25 = F_62 ( F_44 ) ;
break;
case V_205 + V_230 :
* V_25 = F_62 ( F_46 ) ;
break;
case V_205 + V_231 :
* V_25 = F_62 ( F_48 ) ;
break;
}
break;
case V_205 + V_235 :
* V_25 = F_63 ( V_54 , V_166 , V_167 ) ;
break;
default:
F_64 ( F_16 ( 0 , 0 , 0 , 0 , 0 ) != 0 ) ;
return false ;
}
* V_204 = V_25 ;
return true ;
}
int F_65 ( struct V_202 * V_236 , int V_199 ,
struct V_24 * V_237 , int * V_238 )
{
int V_239 = 0 , V_240 = 0 , V_241 , V_242 ;
struct V_24 * V_243 ;
struct V_202 * V_203 ;
int * V_244 = NULL ;
T_1 V_245 ;
F_51 ( V_246 * sizeof( V_171 ) > V_27 ) ;
F_51 ( V_247 + 1 != V_29 ) ;
if ( V_199 <= 0 || V_199 > V_248 )
return - V_249 ;
if ( V_237 ) {
V_244 = F_66 ( V_199 , sizeof( * V_244 ) , V_250 ) ;
if ( ! V_244 )
return - V_15 ;
}
V_251:
V_243 = V_237 ;
V_203 = V_236 ;
if ( V_243 )
* V_243 = F_61 ( V_208 , V_232 ) ;
V_243 ++ ;
for ( V_242 = 0 ; V_242 < V_199 ; V_203 ++ , V_242 ++ ) {
struct V_24 V_252 [ 6 ] = { } ;
struct V_24 * V_25 = V_252 ;
if ( V_244 )
V_244 [ V_242 ] = V_243 - V_237 ;
switch ( V_203 -> V_169 ) {
case V_33 | V_34 | V_35 :
case V_33 | V_34 | V_37 :
case V_33 | V_39 | V_35 :
case V_33 | V_39 | V_37 :
case V_33 | V_42 | V_35 :
case V_33 | V_42 | V_37 :
case V_33 | V_45 | V_35 :
case V_33 | V_45 | V_37 :
case V_33 | V_48 | V_35 :
case V_33 | V_48 | V_37 :
case V_33 | V_51 | V_35 :
case V_33 | V_51 | V_37 :
case V_33 | V_54 | V_35 :
case V_33 | V_54 | V_37 :
case V_33 | V_57 | V_35 :
case V_33 | V_57 | V_37 :
case V_33 | V_63 | V_35 :
case V_33 | V_63 | V_37 :
case V_33 | V_66 | V_35 :
case V_33 | V_66 | V_37 :
case V_33 | V_69 :
case V_154 | V_155 | V_137 :
case V_154 | V_155 | V_135 :
case V_154 | V_155 | V_133 :
case V_154 | V_159 | V_137 :
case V_154 | V_159 | V_135 :
case V_154 | V_159 | V_133 :
if ( F_67 ( V_203 -> V_169 ) == V_154 &&
F_68 ( V_203 -> V_169 ) == V_155 &&
F_50 ( V_203 , & V_25 ) )
break;
* V_25 = F_69 ( V_203 -> V_169 , V_166 , V_167 , 0 , V_203 -> V_3 ) ;
break;
#define F_70 \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case V_103 | V_106 :
V_241 = V_242 + V_203 -> V_3 + 1 ;
V_25 -> V_169 = V_203 -> V_169 ;
F_70 ;
break;
case V_103 | V_108 | V_37 :
case V_103 | V_108 | V_35 :
case V_103 | V_126 | V_37 :
case V_103 | V_126 | V_35 :
case V_103 | V_114 | V_37 :
case V_103 | V_114 | V_35 :
case V_103 | V_117 | V_37 :
case V_103 | V_117 | V_35 :
if ( F_71 ( V_203 -> V_169 ) == V_37 && ( int ) V_203 -> V_3 < 0 ) {
* V_25 ++ = F_72 ( V_216 , V_203 -> V_3 ) ;
V_25 -> V_253 = V_166 ;
V_25 -> V_254 = V_216 ;
V_245 = V_35 ;
} else {
V_25 -> V_253 = V_166 ;
V_25 -> V_254 = V_167 ;
V_25 -> V_178 = V_203 -> V_3 ;
V_245 = F_71 ( V_203 -> V_169 ) ;
}
if ( V_203 -> V_255 == 0 ) {
V_25 -> V_169 = V_103 | F_73 ( V_203 -> V_169 ) | V_245 ;
V_241 = V_242 + V_203 -> V_256 + 1 ;
F_70 ;
break;
}
if ( V_203 -> V_256 == 0 && F_73 ( V_203 -> V_169 ) == V_108 ) {
V_25 -> V_169 = V_103 | V_111 | V_245 ;
V_241 = V_242 + V_203 -> V_255 + 1 ;
F_70 ;
break;
}
V_241 = V_242 + V_203 -> V_256 + 1 ;
V_25 -> V_169 = V_103 | F_73 ( V_203 -> V_169 ) | V_245 ;
F_70 ;
V_25 ++ ;
V_25 -> V_169 = V_103 | V_106 ;
V_241 = V_242 + V_203 -> V_255 + 1 ;
F_70 ;
break;
case V_149 | V_257 | V_133 :
* V_25 ++ = F_61 ( V_216 , V_166 ) ;
* V_25 ++ = F_74 ( V_133 , V_203 -> V_3 ) ;
* V_25 ++ = F_56 ( V_42 , V_166 , 0xf ) ;
* V_25 ++ = F_56 ( V_48 , V_166 , 2 ) ;
* V_25 ++ = F_61 ( V_167 , V_166 ) ;
* V_25 = F_61 ( V_166 , V_216 ) ;
break;
case V_258 | V_259 :
case V_258 | V_37 :
* V_25 ++ = F_75 ( F_76 ( V_203 -> V_169 ) == V_37 ?
V_37 : V_35 , V_260 ,
V_166 , V_203 -> V_3 ) ;
* V_25 = F_60 () ;
break;
case V_144 :
case V_131 :
* V_25 = F_77 ( V_137 , V_247 , F_67 ( V_203 -> V_169 ) ==
V_144 ? V_166 : V_167 ,
- ( V_246 - V_203 -> V_3 ) * 4 ) ;
break;
case V_154 | V_132 :
case V_149 | V_132 :
* V_25 = F_53 ( V_137 , F_67 ( V_203 -> V_169 ) == V_154 ?
V_166 : V_167 , V_247 ,
- ( V_246 - V_203 -> V_3 ) * 4 ) ;
break;
case V_154 | V_261 :
case V_149 | V_261 :
* V_25 = F_72 ( F_67 ( V_203 -> V_169 ) == V_154 ?
V_166 : V_167 , V_203 -> V_3 ) ;
break;
case V_262 | V_263 :
* V_25 = F_61 ( V_167 , V_166 ) ;
break;
case V_262 | V_264 :
* V_25 = F_61 ( V_166 , V_167 ) ;
break;
case V_154 | V_137 | V_265 :
case V_149 | V_137 | V_265 :
* V_25 = F_53 ( V_137 , F_67 ( V_203 -> V_169 ) == V_154 ?
V_166 : V_167 , V_208 ,
F_54 ( struct V_1 , V_199 ) ) ;
break;
case V_149 | V_155 | V_137 :
* V_25 = F_53 ( V_137 , V_166 , V_208 , V_203 -> V_3 ) ;
break;
default:
goto V_12;
}
V_25 ++ ;
if ( V_237 )
memcpy ( V_243 , V_252 ,
sizeof( * V_25 ) * ( V_25 - V_252 ) ) ;
V_243 += V_25 - V_252 ;
}
if ( ! V_237 ) {
* V_238 = V_243 - V_237 ;
return 0 ;
}
V_240 ++ ;
if ( V_239 != V_243 - V_237 ) {
V_239 = V_243 - V_237 ;
if ( V_240 > 2 )
goto V_12;
goto V_251;
}
F_78 ( V_244 ) ;
F_64 ( * V_238 != V_239 ) ;
return 0 ;
V_12:
F_78 ( V_244 ) ;
return - V_249 ;
}
static int F_79 ( struct V_202 * V_13 , int V_266 )
{
V_176 * V_267 , V_268 = 0 ;
int V_269 , V_270 = 0 ;
F_51 ( V_246 > 16 ) ;
V_267 = F_80 ( V_266 , sizeof( * V_267 ) , V_250 ) ;
if ( ! V_267 )
return - V_15 ;
memset ( V_267 , 0xff , V_266 * sizeof( * V_267 ) ) ;
for ( V_269 = 0 ; V_269 < V_266 ; V_269 ++ ) {
V_268 &= V_267 [ V_269 ] ;
switch ( V_13 [ V_269 ] . V_169 ) {
case V_144 :
case V_131 :
V_268 |= ( 1 << V_13 [ V_269 ] . V_3 ) ;
break;
case V_154 | V_132 :
case V_149 | V_132 :
if ( ! ( V_268 & ( 1 << V_13 [ V_269 ] . V_3 ) ) ) {
V_270 = - V_249 ;
goto error;
}
break;
case V_103 | V_106 :
V_267 [ V_269 + 1 + V_13 [ V_269 ] . V_3 ] &= V_268 ;
V_268 = ~ 0 ;
break;
case V_103 | V_108 | V_37 :
case V_103 | V_108 | V_35 :
case V_103 | V_117 | V_37 :
case V_103 | V_117 | V_35 :
case V_103 | V_114 | V_37 :
case V_103 | V_114 | V_35 :
case V_103 | V_126 | V_37 :
case V_103 | V_126 | V_35 :
V_267 [ V_269 + 1 + V_13 [ V_269 ] . V_256 ] &= V_268 ;
V_267 [ V_269 + 1 + V_13 [ V_269 ] . V_255 ] &= V_268 ;
V_268 = ~ 0 ;
break;
}
}
error:
F_78 ( V_267 ) ;
return V_270 ;
}
static bool F_81 ( V_176 V_271 )
{
static const bool V_272 [] = {
[ V_33 | V_34 | V_37 ] = true ,
[ V_33 | V_34 | V_35 ] = true ,
[ V_33 | V_39 | V_37 ] = true ,
[ V_33 | V_39 | V_35 ] = true ,
[ V_33 | V_57 | V_37 ] = true ,
[ V_33 | V_57 | V_35 ] = true ,
[ V_33 | V_63 | V_37 ] = true ,
[ V_33 | V_63 | V_35 ] = true ,
[ V_33 | V_66 | V_37 ] = true ,
[ V_33 | V_66 | V_35 ] = true ,
[ V_33 | V_42 | V_37 ] = true ,
[ V_33 | V_42 | V_35 ] = true ,
[ V_33 | V_45 | V_37 ] = true ,
[ V_33 | V_45 | V_35 ] = true ,
[ V_33 | V_54 | V_37 ] = true ,
[ V_33 | V_54 | V_35 ] = true ,
[ V_33 | V_48 | V_37 ] = true ,
[ V_33 | V_48 | V_35 ] = true ,
[ V_33 | V_51 | V_37 ] = true ,
[ V_33 | V_51 | V_35 ] = true ,
[ V_33 | V_69 ] = true ,
[ V_154 | V_137 | V_155 ] = true ,
[ V_154 | V_135 | V_155 ] = true ,
[ V_154 | V_133 | V_155 ] = true ,
[ V_154 | V_137 | V_265 ] = true ,
[ V_154 | V_137 | V_159 ] = true ,
[ V_154 | V_135 | V_159 ] = true ,
[ V_154 | V_133 | V_159 ] = true ,
[ V_154 | V_261 ] = true ,
[ V_154 | V_132 ] = true ,
[ V_149 | V_137 | V_265 ] = true ,
[ V_149 | V_133 | V_257 ] = true ,
[ V_149 | V_261 ] = true ,
[ V_149 | V_132 ] = true ,
[ V_144 ] = true ,
[ V_131 ] = true ,
[ V_262 | V_263 ] = true ,
[ V_262 | V_264 ] = true ,
[ V_258 | V_37 ] = true ,
[ V_258 | V_259 ] = true ,
[ V_103 | V_106 ] = true ,
[ V_103 | V_108 | V_37 ] = true ,
[ V_103 | V_108 | V_35 ] = true ,
[ V_103 | V_117 | V_37 ] = true ,
[ V_103 | V_117 | V_35 ] = true ,
[ V_103 | V_114 | V_37 ] = true ,
[ V_103 | V_114 | V_35 ] = true ,
[ V_103 | V_126 | V_37 ] = true ,
[ V_103 | V_126 | V_35 ] = true ,
} ;
if ( V_271 >= F_20 ( V_272 ) )
return false ;
return V_272 [ V_271 ] ;
}
int F_82 ( struct V_202 * V_13 , unsigned int V_266 )
{
bool V_273 ;
int V_269 ;
if ( V_266 == 0 || V_266 > V_248 )
return - V_249 ;
for ( V_269 = 0 ; V_269 < V_266 ; V_269 ++ ) {
struct V_202 * V_274 = & V_13 [ V_269 ] ;
if ( ! F_81 ( V_274 -> V_169 ) )
return - V_249 ;
switch ( V_274 -> V_169 ) {
case V_33 | V_63 | V_37 :
case V_33 | V_66 | V_37 :
if ( V_274 -> V_3 == 0 )
return - V_249 ;
break;
case V_154 | V_132 :
case V_149 | V_132 :
case V_144 :
case V_131 :
if ( V_274 -> V_3 >= V_246 )
return - V_249 ;
break;
case V_103 | V_106 :
if ( V_274 -> V_3 >= ( unsigned int ) ( V_266 - V_269 - 1 ) )
return - V_249 ;
break;
case V_103 | V_108 | V_37 :
case V_103 | V_108 | V_35 :
case V_103 | V_117 | V_37 :
case V_103 | V_117 | V_35 :
case V_103 | V_114 | V_37 :
case V_103 | V_114 | V_35 :
case V_103 | V_126 | V_37 :
case V_103 | V_126 | V_35 :
if ( V_269 + V_274 -> V_256 + 1 >= V_266 ||
V_269 + V_274 -> V_255 + 1 >= V_266 )
return - V_249 ;
break;
case V_154 | V_137 | V_155 :
case V_154 | V_135 | V_155 :
case V_154 | V_133 | V_155 :
V_273 = false ;
if ( F_83 ( V_274 ) & V_275 )
V_273 = true ;
if ( V_273 == false && V_274 -> V_3 >= V_205 )
return - V_249 ;
}
}
switch ( V_13 [ V_266 - 1 ] . V_169 ) {
case V_258 | V_37 :
case V_258 | V_259 :
return F_79 ( V_13 , V_266 ) ;
}
return - V_249 ;
}
static int F_84 ( struct F_7 * V_203 ,
const struct V_276 * V_277 )
{
unsigned int V_278 = F_85 ( V_277 ) ;
struct V_279 * V_280 ;
V_203 -> V_281 = F_86 ( sizeof( * V_280 ) , V_250 ) ;
if ( ! V_203 -> V_281 )
return - V_15 ;
V_280 = V_203 -> V_281 ;
V_280 -> V_199 = V_277 -> V_199 ;
V_280 -> V_13 = F_87 ( V_203 -> V_282 , V_278 , V_250 ) ;
if ( ! V_280 -> V_13 ) {
F_78 ( V_203 -> V_281 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_88 ( struct F_7 * V_203 )
{
struct V_279 * V_277 = V_203 -> V_281 ;
if ( V_277 ) {
F_78 ( V_277 -> V_13 ) ;
F_78 ( V_277 ) ;
}
}
static void F_89 ( struct V_283 * V_284 )
{
struct F_7 * V_203 = F_90 ( V_284 , struct F_7 , V_284 ) ;
F_88 ( V_203 ) ;
F_91 ( V_203 ) ;
}
static void F_92 ( struct F_7 * V_203 )
{
if ( F_93 ( & V_203 -> V_285 ) )
F_94 ( & V_203 -> V_284 , F_89 ) ;
}
void F_95 ( struct V_10 * V_11 , struct F_7 * V_203 )
{
F_96 ( F_97 ( V_203 -> V_199 ) , & V_11 -> V_286 ) ;
F_92 ( V_203 ) ;
}
void F_98 ( struct V_10 * V_11 , struct F_7 * V_203 )
{
F_99 ( & V_203 -> V_285 ) ;
F_31 ( F_97 ( V_203 -> V_199 ) , & V_11 -> V_286 ) ;
}
static struct F_7 * F_100 ( struct F_7 * V_203 ,
struct V_10 * V_11 ,
unsigned int V_199 )
{
struct F_7 * V_287 ;
if ( V_11 == NULL )
return F_101 ( V_203 , V_199 , V_250 ) ;
V_287 = F_102 ( V_11 , V_199 , V_250 ) ;
if ( V_287 ) {
* V_287 = * V_203 ;
V_203 -> V_281 = NULL ;
F_95 ( V_11 , V_203 ) ;
}
return V_287 ;
}
static struct F_7 * F_103 ( struct F_7 * V_203 ,
struct V_10 * V_11 )
{
struct V_202 * V_288 ;
struct F_7 * V_289 ;
int V_12 , V_238 , V_290 = V_203 -> V_199 ;
F_51 ( sizeof( struct V_202 ) !=
sizeof( struct V_24 ) ) ;
V_288 = F_87 ( V_203 -> V_282 , V_290 * sizeof( struct V_202 ) ,
V_250 ) ;
if ( ! V_288 ) {
V_12 = - V_15 ;
goto V_291;
}
V_12 = F_65 ( V_288 , V_290 , NULL , & V_238 ) ;
if ( V_12 )
goto V_292;
V_289 = V_203 ;
V_203 = F_100 ( V_289 , V_11 , F_97 ( V_238 ) ) ;
if ( ! V_203 ) {
V_203 = V_289 ;
V_12 = - V_15 ;
goto V_292;
}
V_203 -> V_199 = V_238 ;
V_12 = F_65 ( V_288 , V_290 , V_203 -> V_293 , & V_238 ) ;
if ( V_12 )
goto V_292;
F_104 ( V_203 ) ;
F_78 ( V_288 ) ;
return V_203 ;
V_292:
F_78 ( V_288 ) ;
V_291:
if ( V_11 != NULL )
F_95 ( V_11 , V_203 ) ;
else
F_78 ( V_203 ) ;
return F_105 ( V_12 ) ;
}
void __weak F_106 ( struct F_7 * V_236 )
{
}
void F_104 ( struct F_7 * V_203 )
{
V_203 -> V_294 = ( void * ) F_17 ;
F_106 ( V_203 ) ;
}
void F_91 ( struct F_7 * V_203 )
{
F_107 ( V_203 ) ;
}
static struct F_7 * F_108 ( struct F_7 * V_203 ,
struct V_10 * V_11 )
{
int V_12 ;
V_203 -> V_294 = NULL ;
V_203 -> V_295 = 0 ;
V_12 = F_82 ( V_203 -> V_282 , V_203 -> V_199 ) ;
if ( V_12 ) {
if ( V_11 != NULL )
F_95 ( V_11 , V_203 ) ;
else
F_78 ( V_203 ) ;
return F_105 ( V_12 ) ;
}
F_109 ( V_203 ) ;
if ( ! V_203 -> V_295 )
V_203 = F_103 ( V_203 , V_11 ) ;
return V_203 ;
}
int F_110 ( struct F_7 * * V_296 ,
struct V_279 * V_277 )
{
unsigned int V_278 = F_85 ( V_277 ) ;
struct F_7 * V_203 ;
if ( V_277 -> V_13 == NULL )
return - V_249 ;
V_203 = F_86 ( F_97 ( V_277 -> V_199 ) , V_250 ) ;
if ( ! V_203 )
return - V_15 ;
memcpy ( V_203 -> V_282 , V_277 -> V_13 , V_278 ) ;
F_111 ( & V_203 -> V_285 , 1 ) ;
V_203 -> V_199 = V_277 -> V_199 ;
V_203 -> V_281 = NULL ;
V_203 = F_108 ( V_203 , NULL ) ;
if ( F_112 ( V_203 ) )
return F_113 ( V_203 ) ;
* V_296 = V_203 ;
return 0 ;
}
void F_114 ( struct F_7 * V_203 )
{
F_92 ( V_203 ) ;
}
int F_115 ( struct V_276 * V_277 , struct V_10 * V_11 )
{
struct F_7 * V_203 , * V_289 ;
unsigned int V_278 = F_85 ( V_277 ) ;
unsigned int V_297 = F_97 ( V_277 -> V_199 ) ;
int V_12 ;
if ( F_9 ( V_11 , V_298 ) )
return - V_17 ;
if ( V_277 -> V_13 == NULL )
return - V_249 ;
V_203 = F_102 ( V_11 , V_297 , V_250 ) ;
if ( ! V_203 )
return - V_15 ;
if ( F_116 ( V_203 -> V_282 , V_277 -> V_13 , V_278 ) ) {
F_117 ( V_11 , V_203 , V_297 ) ;
return - V_299 ;
}
F_111 ( & V_203 -> V_285 , 1 ) ;
V_203 -> V_199 = V_277 -> V_199 ;
V_12 = F_84 ( V_203 , V_277 ) ;
if ( V_12 ) {
F_95 ( V_11 , V_203 ) ;
return - V_15 ;
}
V_203 = F_108 ( V_203 , V_11 ) ;
if ( F_112 ( V_203 ) )
return F_113 ( V_203 ) ;
V_289 = F_118 ( V_11 -> F_7 ,
F_119 ( V_11 ) ) ;
F_120 ( V_11 -> F_7 , V_203 ) ;
if ( V_289 )
F_95 ( V_11 , V_289 ) ;
return 0 ;
}
int F_121 ( struct V_10 * V_11 )
{
int V_270 = - V_300 ;
struct F_7 * V_13 ;
if ( F_9 ( V_11 , V_298 ) )
return - V_17 ;
V_13 = F_118 ( V_11 -> F_7 ,
F_119 ( V_11 ) ) ;
if ( V_13 ) {
F_122 ( V_11 -> F_7 , NULL ) ;
F_95 ( V_11 , V_13 ) ;
V_270 = 0 ;
}
return V_270 ;
}
int F_123 ( struct V_10 * V_11 , struct V_202 T_8 * V_301 ,
unsigned int V_199 )
{
struct V_279 * V_277 ;
struct F_7 * V_13 ;
int V_270 = 0 ;
F_124 ( V_11 ) ;
V_13 = F_118 ( V_11 -> F_7 ,
F_119 ( V_11 ) ) ;
if ( ! V_13 )
goto V_302;
V_277 = V_13 -> V_281 ;
V_270 = V_277 -> V_199 ;
if ( ! V_199 )
goto V_302;
V_270 = - V_249 ;
if ( V_199 < V_277 -> V_199 )
goto V_302;
V_270 = - V_299 ;
if ( F_125 ( V_301 , V_277 -> V_13 , F_85 ( V_277 ) ) )
goto V_302;
V_270 = V_277 -> V_199 ;
V_302:
F_126 ( V_11 ) ;
return V_270 ;
}
