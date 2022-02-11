static struct V_1 * F_1 ( struct V_2 * V_2 , char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_17 ;
V_17 = F_9 ( V_12 , type ) ;
if ( V_17 )
return V_17 ;
if ( type == V_18 &&
V_7 && V_7 -> V_19 == 0 )
F_10 ( V_12 -> V_15 . V_20 . V_21 , NULL ) ;
else if ( type == V_22 &&
V_7 && V_7 -> V_19 >= 0 )
V_12 -> V_15 . V_23 . V_19 = V_7 -> V_19 ;
if ( V_12 -> V_24 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_11 ( V_12 ) ) {
if ( ( * V_5 & V_25 ) !=
( V_12 -> V_15 . V_16 & V_25 ) )
return - V_26 ;
F_12 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_12 ( V_12 , 1 ) ;
F_13 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_14 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
V_12 -> V_27 = V_27 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 ,
struct V_31 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 = NULL ;
struct V_33 * V_34 ;
int V_13 ;
if ( ! F_11 ( V_12 ) )
return - V_35 ;
switch ( V_7 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
if ( F_16 ( V_12 -> V_9 -> V_40 ) )
return - V_41 ;
break;
default:
break;
}
V_34 = F_17 ( V_7 -> V_36 , V_28 , V_7 -> V_42 ,
V_7 -> V_34 , V_7 -> V_43 , V_7 -> V_44 ) ;
if ( F_16 ( V_34 ) )
return F_18 ( V_34 ) ;
if ( V_29 )
V_34 -> V_45 . V_5 |= V_46 ;
F_19 ( & V_12 -> V_9 -> V_47 ) ;
if ( V_30 ) {
if ( F_20 ( & V_12 -> V_24 ) )
V_21 = F_21 ( V_12 , V_30 ) ;
else
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 ) {
F_23 ( V_12 -> V_9 , V_34 ) ;
V_13 = - V_48 ;
goto V_49;
}
}
V_13 = F_24 ( V_34 , V_12 , V_21 ) ;
if ( V_13 )
F_23 ( V_12 -> V_9 , V_34 ) ;
V_49:
F_25 ( & V_12 -> V_9 -> V_47 ) ;
return V_13 ;
}
static int F_26 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_32 * V_21 ;
struct V_33 * V_34 = NULL ;
int V_17 ;
F_19 ( & V_9 -> V_47 ) ;
F_19 ( & V_9 -> V_50 ) ;
if ( V_30 ) {
V_17 = - V_48 ;
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 )
goto V_49;
if ( V_29 )
V_34 = F_27 ( V_9 , V_21 -> V_51 ) ;
else
V_34 = F_27 ( V_9 , V_21 -> V_52 [ V_28 ] ) ;
} else
V_34 = F_27 ( V_9 , V_12 -> V_53 [ V_28 ] ) ;
if ( ! V_34 ) {
V_17 = - V_48 ;
goto V_49;
}
F_28 ( V_34 ) ;
V_17 = 0 ;
V_49:
F_25 ( & V_9 -> V_50 ) ;
F_25 ( & V_9 -> V_47 ) ;
return V_17 ;
}
static int F_29 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 V_28 , bool V_29 , const T_3 * V_30 ,
void * V_54 ,
void (* F_30)( void * V_54 ,
struct V_31 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_32 * V_21 = NULL ;
T_3 V_44 [ 6 ] = { 0 } ;
struct V_31 V_7 ;
struct V_33 * V_34 = NULL ;
T_4 V_55 ;
T_1 V_56 ;
T_2 V_57 ;
int V_13 = - V_48 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
if ( V_30 ) {
V_21 = F_22 ( V_12 , V_30 ) ;
if ( ! V_21 )
goto V_58;
if ( V_29 )
V_34 = F_32 ( V_21 -> V_51 ) ;
else if ( V_28 < V_59 )
V_34 = F_32 ( V_21 -> V_52 [ V_28 ] ) ;
} else
V_34 = F_32 ( V_12 -> V_53 [ V_28 ] ) ;
if ( ! V_34 )
goto V_58;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_36 = V_34 -> V_45 . V_36 ;
switch ( V_34 -> V_45 . V_36 ) {
case V_38 :
V_56 = V_34 -> V_15 . V_60 . V_61 . V_56 ;
V_57 = V_34 -> V_15 . V_60 . V_61 . V_57 ;
if ( V_34 -> V_5 & V_62 )
F_33 ( V_12 -> V_9 ,
V_34 -> V_45 . V_63 ,
& V_56 , & V_57 ) ;
V_44 [ 0 ] = V_57 & 0xff ;
V_44 [ 1 ] = ( V_57 >> 8 ) & 0xff ;
V_44 [ 2 ] = V_56 & 0xff ;
V_44 [ 3 ] = ( V_56 >> 8 ) & 0xff ;
V_44 [ 4 ] = ( V_56 >> 16 ) & 0xff ;
V_44 [ 5 ] = ( V_56 >> 24 ) & 0xff ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
case V_64 :
V_55 = F_34 ( & V_34 -> V_15 . V_65 . V_66 ) ;
V_44 [ 0 ] = V_55 ;
V_44 [ 1 ] = V_55 >> 8 ;
V_44 [ 2 ] = V_55 >> 16 ;
V_44 [ 3 ] = V_55 >> 24 ;
V_44 [ 4 ] = V_55 >> 32 ;
V_44 [ 5 ] = V_55 >> 40 ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
case V_67 :
V_55 = F_34 ( & V_34 -> V_15 . V_68 . V_66 ) ;
V_44 [ 0 ] = V_55 ;
V_44 [ 1 ] = V_55 >> 8 ;
V_44 [ 2 ] = V_55 >> 16 ;
V_44 [ 3 ] = V_55 >> 24 ;
V_44 [ 4 ] = V_55 >> 32 ;
V_44 [ 5 ] = V_55 >> 40 ;
V_7 . V_44 = V_44 ;
V_7 . V_43 = 6 ;
break;
}
V_7 . V_34 = V_34 -> V_45 . V_34 ;
V_7 . V_42 = V_34 -> V_45 . V_69 ;
F_30 ( V_54 , & V_7 ) ;
V_13 = 0 ;
V_58:
F_35 () ;
return V_13 ;
}
static int F_36 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_28 , bool V_70 ,
bool V_71 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_37 ( V_12 , V_28 , V_70 , V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_28 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_39 ( V_12 , V_28 ) ;
return 0 ;
}
static void F_40 ( struct V_72 * V_73 , struct V_32 * V_21 , int V_74 )
{
if ( ! ( V_73 -> V_5 & V_75 ) ) {
struct V_76 * V_77 ;
V_77 = V_21 -> V_9 -> V_78 . V_2 -> V_79 [
V_21 -> V_9 -> V_78 . V_45 . V_80 -> V_81 ] ;
V_73 -> V_82 = V_77 -> V_83 [ V_74 ] . V_84 ;
} else
V_73 -> V_85 = V_74 ;
}
void F_41 ( struct V_32 * V_21 ,
const struct V_86 * V_73 ,
struct V_72 * V_87 )
{
V_87 -> V_5 = 0 ;
if ( V_73 -> V_5 & V_88 )
V_87 -> V_5 |= V_75 ;
if ( V_73 -> V_5 & V_89 )
V_87 -> V_5 |= V_90 ;
if ( V_73 -> V_5 & V_91 )
V_87 -> V_5 |= V_92 ;
F_40 ( V_87 , V_21 , V_73 -> V_74 ) ;
}
static void F_42 ( struct V_32 * V_21 , struct V_93 * V_94 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_95 V_96 ;
V_94 -> V_97 = V_12 -> V_9 -> V_98 ;
V_94 -> V_99 = V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 |
V_107 |
V_108 |
V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
F_43 ( & V_96 ) ;
V_94 -> V_114 = V_96 . V_115 - V_21 -> V_116 ;
V_94 -> V_117 = F_44 ( V_118 - V_21 -> V_119 ) ;
V_94 -> V_120 = V_21 -> V_120 ;
V_94 -> V_121 = V_21 -> V_121 ;
V_94 -> V_122 = V_21 -> V_122 ;
V_94 -> V_123 = V_21 -> V_123 ;
V_94 -> V_124 = V_21 -> V_125 ;
V_94 -> V_126 = V_21 -> V_127 ;
V_94 -> V_128 = V_21 -> V_129 ;
V_94 -> V_130 = V_21 -> V_130 ;
if ( ( V_21 -> V_9 -> V_78 . V_5 & V_131 ) ||
( V_21 -> V_9 -> V_78 . V_5 & V_132 ) ) {
V_94 -> V_99 |= V_133 | V_134 ;
V_94 -> signal = ( V_135 ) V_21 -> V_136 ;
V_94 -> V_137 = ( V_135 ) - F_45 ( & V_21 -> V_138 ) ;
}
F_41 ( V_21 , & V_21 -> V_139 , & V_94 -> V_140 ) ;
V_94 -> V_141 . V_5 = 0 ;
if ( V_21 -> V_142 & V_143 )
V_94 -> V_141 . V_5 |= V_75 ;
if ( V_21 -> V_142 & V_144 )
V_94 -> V_141 . V_5 |= V_90 ;
if ( V_21 -> V_142 & V_145 )
V_94 -> V_141 . V_5 |= V_92 ;
F_40 ( & V_94 -> V_141 , V_21 , V_21 -> V_146 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_46
V_94 -> V_99 |= V_147 |
V_148 |
V_149 ;
V_94 -> V_150 = F_47 ( V_21 -> V_150 ) ;
V_94 -> V_151 = F_47 ( V_21 -> V_151 ) ;
V_94 -> V_152 = V_21 -> V_152 ;
#endif
}
V_94 -> V_153 . V_5 = 0 ;
if ( V_12 -> V_24 . V_154 . V_155 )
V_94 -> V_153 . V_5 |= V_156 ;
if ( V_12 -> V_24 . V_154 . V_157 )
V_94 -> V_153 . V_5 |= V_158 ;
if ( V_12 -> V_24 . V_154 . V_159 )
V_94 -> V_153 . V_5 |= V_160 ;
V_94 -> V_153 . V_161 = V_12 -> V_9 -> V_78 . V_45 . V_162 ;
V_94 -> V_153 . V_163 = V_12 -> V_24 . V_154 . V_164 ;
V_94 -> V_165 . V_166 = 0 ;
V_94 -> V_165 . V_167 = F_48 ( V_168 ) |
F_48 ( V_169 ) |
F_48 ( V_170 ) |
F_48 ( V_171 ) |
F_48 ( V_172 ) |
F_48 ( V_173 ) ;
if ( F_49 ( V_21 , V_174 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_168 ) ;
if ( F_49 ( V_21 , V_175 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_169 ) ;
if ( F_49 ( V_21 , V_176 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_170 ) ;
if ( F_49 ( V_21 , V_177 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_171 ) ;
if ( F_49 ( V_21 , V_178 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_172 ) ;
if ( F_49 ( V_21 , V_179 ) )
V_94 -> V_165 . V_166 |= F_48 ( V_173 ) ;
}
static int F_50 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_180 , struct V_93 * V_94 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_51 ( V_12 , V_74 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_180 , V_21 -> V_21 . V_181 , V_182 ) ;
F_42 ( V_21 , V_94 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_52 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , struct V_183 * V_184 )
{
struct V_8 * V_9 = F_53 ( V_10 -> V_185 ) ;
return F_54 ( V_9 , V_74 , V_184 ) ;
}
static int F_55 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_180 , struct V_93 * V_94 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_22 ( V_12 , V_180 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_42 ( V_21 , V_94 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_56 ( struct V_11 * V_12 ,
const T_3 * V_186 , T_5 V_187 )
{
struct V_188 * V_189 , * V_190 ;
if ( ! V_186 || ! V_187 )
return 1 ;
V_190 = F_57 ( V_12 -> V_15 . V_191 . V_192 ) ;
V_189 = F_58 ( V_187 ) ;
if ( ! V_189 )
return - V_193 ;
memcpy ( F_59 ( V_189 , V_187 ) , V_186 , V_187 ) ;
F_60 ( V_12 -> V_15 . V_191 . V_192 , V_189 ) ;
if ( V_190 ) {
F_61 () ;
F_62 ( V_190 ) ;
}
return 0 ;
}
static int F_63 ( struct V_11 * V_12 ,
struct V_194 * V_7 )
{
struct V_195 * V_189 , * V_190 ;
int V_196 , V_197 ;
int V_198 , V_13 ;
T_1 V_199 = V_200 ;
V_190 = F_57 ( V_12 -> V_15 . V_191 . V_201 ) ;
if ( ! V_7 -> V_202 && ! V_190 )
return - V_41 ;
if ( V_7 -> V_202 )
V_196 = V_7 -> V_203 ;
else
V_196 = V_190 -> V_203 ;
if ( V_7 -> V_204 || ! V_190 )
V_197 = V_7 -> V_205 ;
else
V_197 = V_190 -> V_205 ;
V_198 = sizeof( * V_189 ) + V_196 + V_197 ;
V_189 = F_64 ( V_198 , V_206 ) ;
if ( ! V_189 )
return - V_193 ;
V_189 -> V_202 = ( ( T_3 * ) V_189 ) + sizeof( * V_189 ) ;
V_189 -> V_204 = V_189 -> V_202 + V_196 ;
V_189 -> V_203 = V_196 ;
V_189 -> V_205 = V_197 ;
if ( V_7 -> V_202 )
memcpy ( V_189 -> V_202 , V_7 -> V_202 , V_196 ) ;
else
memcpy ( V_189 -> V_202 , V_190 -> V_202 , V_196 ) ;
if ( V_7 -> V_204 )
memcpy ( V_189 -> V_204 , V_7 -> V_204 , V_197 ) ;
else
if ( V_190 )
memcpy ( V_189 -> V_204 , V_190 -> V_204 , V_197 ) ;
V_13 = F_56 ( V_12 , V_7 -> V_192 ,
V_7 -> V_207 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( V_13 == 0 )
V_199 |= V_208 ;
F_60 ( V_12 -> V_15 . V_191 . V_201 , V_189 ) ;
if ( V_190 )
F_65 ( V_190 , V_209 ) ;
return V_199 ;
}
static int F_66 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_210 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_195 * V_190 ;
struct V_11 * V_20 ;
T_1 V_199 = V_211 |
V_212 |
V_200 |
V_213 ;
int V_13 ;
V_190 = F_57 ( V_12 -> V_15 . V_191 . V_201 ) ;
if ( V_190 )
return - V_214 ;
V_12 -> V_215 = V_7 -> V_216 . V_217 ;
V_12 -> V_218 = V_7 -> V_216 . V_218 ;
F_67 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_20 -> V_215 =
V_7 -> V_216 . V_217 ;
V_20 -> V_218 =
V_7 -> V_216 . V_218 ;
}
V_12 -> V_24 . V_154 . V_164 = V_7 -> V_163 ;
V_12 -> V_24 . V_154 . V_161 = V_7 -> V_161 ;
V_12 -> V_24 . V_154 . V_219 = V_7 -> V_219 ;
if ( V_7 -> V_219 )
memcpy ( V_12 -> V_24 . V_154 . V_220 , V_7 -> V_220 ,
V_7 -> V_219 ) ;
V_12 -> V_24 . V_154 . V_221 =
( V_7 -> V_221 != V_222 ) ;
V_13 = F_63 ( V_12 , & V_7 -> V_201 ) ;
if ( V_13 < 0 )
return V_13 ;
V_199 |= V_13 ;
F_68 ( V_12 , V_199 ) ;
return 0 ;
}
static int F_69 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_194 * V_7 )
{
struct V_11 * V_12 ;
struct V_195 * V_190 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
V_190 = F_57 ( V_12 -> V_15 . V_191 . V_201 ) ;
if ( ! V_190 )
return - V_48 ;
V_13 = F_63 ( V_12 , V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
F_68 ( V_12 , V_13 ) ;
return 0 ;
}
static int F_70 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 ;
struct V_195 * V_190 ;
V_12 = F_5 ( V_10 ) ;
V_190 = F_57 ( V_12 -> V_15 . V_191 . V_201 ) ;
if ( ! V_190 )
return - V_48 ;
F_10 ( V_12 -> V_15 . V_191 . V_201 , NULL ) ;
F_65 ( V_190 , V_209 ) ;
F_68 ( V_12 , V_212 ) ;
return 0 ;
}
static void F_71 ( struct V_32 * V_21 )
{
struct V_223 * V_224 ;
struct V_188 * V_225 ;
V_225 = F_58 ( sizeof( * V_224 ) ) ;
if ( ! V_225 )
return;
V_224 = (struct V_223 * ) F_59 ( V_225 , sizeof( * V_224 ) ) ;
memset ( V_224 -> V_226 , 0xff , V_182 ) ;
memcpy ( V_224 -> V_227 , V_21 -> V_21 . V_181 , V_182 ) ;
V_224 -> V_228 = F_72 ( 6 ) ;
V_224 -> V_229 = 0 ;
V_224 -> V_230 = 0x01 ;
V_224 -> V_231 = 0xaf ;
V_224 -> V_232 [ 0 ] = 0x81 ;
V_224 -> V_232 [ 1 ] = 1 ;
V_224 -> V_232 [ 2 ] = 0 ;
V_225 -> V_10 = V_21 -> V_12 -> V_10 ;
V_225 -> V_233 = F_73 ( V_225 , V_21 -> V_12 -> V_10 ) ;
memset ( V_225 -> V_234 , 0 , sizeof( V_225 -> V_234 ) ) ;
F_74 ( V_225 ) ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_32 * V_21 ,
struct V_235 * V_7 )
{
int V_17 = 0 ;
T_1 V_236 ;
int V_237 , V_238 ;
struct V_76 * V_77 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_167 , V_166 ;
V_77 = V_9 -> V_78 . V_2 -> V_79 [ V_9 -> V_239 -> V_81 ] ;
V_167 = V_7 -> V_240 ;
V_166 = V_7 -> V_241 ;
if ( V_167 & F_48 ( V_172 ) ) {
if ( F_76 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( V_166 & F_48 ( V_172 ) &&
! F_49 ( V_21 , V_178 ) ) {
V_17 = F_77 ( V_21 , V_242 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_77 ( V_21 , V_243 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_167 & F_48 ( V_168 ) ) {
if ( V_166 & F_48 ( V_168 ) )
V_17 = F_77 ( V_21 , V_244 ) ;
else if ( F_49 ( V_21 , V_174 ) )
V_17 = F_77 ( V_21 , V_243 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_167 & F_48 ( V_172 ) ) {
if ( F_76 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( ! ( V_166 & F_48 ( V_172 ) ) &&
F_49 ( V_21 , V_178 ) ) {
V_17 = F_77 ( V_21 , V_242 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_77 ( V_21 , V_245 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_167 & F_48 ( V_169 ) ) {
if ( V_166 & F_48 ( V_169 ) )
F_78 ( V_21 , V_175 ) ;
else
F_79 ( V_21 , V_175 ) ;
}
if ( V_167 & F_48 ( V_170 ) ) {
if ( V_166 & F_48 ( V_170 ) ) {
F_78 ( V_21 , V_176 ) ;
V_21 -> V_21 . V_246 = true ;
} else {
F_79 ( V_21 , V_176 ) ;
V_21 -> V_21 . V_246 = false ;
}
}
if ( V_167 & F_48 ( V_171 ) ) {
if ( V_166 & F_48 ( V_171 ) )
F_78 ( V_21 , V_177 ) ;
else
F_79 ( V_21 , V_177 ) ;
}
if ( V_167 & F_48 ( V_173 ) ) {
if ( V_166 & F_48 ( V_173 ) )
F_78 ( V_21 , V_179 ) ;
else
F_79 ( V_21 , V_179 ) ;
}
if ( V_7 -> V_247 & V_248 ) {
V_21 -> V_21 . V_249 = V_7 -> V_249 ;
V_21 -> V_21 . V_250 = V_7 -> V_250 ;
}
if ( V_7 -> V_251 )
V_21 -> V_21 . V_251 = V_7 -> V_251 ;
if ( V_7 -> V_252 >= 0 )
V_21 -> V_252 = V_7 -> V_252 ;
if ( V_7 -> V_253 ) {
V_236 = 0 ;
for ( V_237 = 0 ; V_237 < V_7 -> V_254 ; V_237 ++ ) {
int V_73 = ( V_7 -> V_253 [ V_237 ] & 0x7f ) * 5 ;
for ( V_238 = 0 ; V_238 < V_77 -> V_255 ; V_238 ++ ) {
if ( V_77 -> V_83 [ V_238 ] . V_84 == V_73 )
V_236 |= F_48 ( V_238 ) ;
}
}
V_21 -> V_21 . V_256 [ V_9 -> V_239 -> V_81 ] = V_236 ;
}
if ( V_7 -> V_257 )
F_80 ( V_12 , V_77 ,
V_7 -> V_257 ,
& V_21 -> V_21 . V_258 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_46
if ( V_12 -> V_15 . V_259 . V_260 & V_261 )
switch ( V_7 -> V_152 ) {
case V_262 :
case V_263 :
case V_264 :
V_21 -> V_152 = V_7 -> V_152 ;
break;
default:
break;
}
else
switch ( V_7 -> V_265 ) {
case V_266 :
F_81 ( V_21 ) ;
break;
case V_267 :
F_82 ( V_21 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_180 , struct V_235 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_268 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_269 )
return - V_41 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_84 ( V_180 , V_12 -> V_24 . V_181 ) == 0 )
return - V_41 ;
if ( F_85 ( V_180 ) )
return - V_41 ;
V_21 = F_86 ( V_12 , V_180 , V_206 ) ;
if ( ! V_21 )
return - V_193 ;
F_87 ( V_21 , V_242 ) ;
F_87 ( V_21 , V_243 ) ;
V_13 = F_75 ( V_9 , V_21 , V_7 ) ;
if ( V_13 ) {
F_88 ( V_9 , V_21 ) ;
return V_13 ;
}
if ( ! F_49 ( V_21 , V_179 ) )
F_89 ( V_21 ) ;
V_268 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_269 ;
V_13 = F_90 ( V_21 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
if ( V_268 )
F_71 ( V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_180 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_180 )
return F_92 ( V_12 , V_180 ) ;
F_93 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_180 ,
struct V_235 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_270 ;
int V_13 ;
F_19 ( & V_9 -> V_47 ) ;
V_21 = F_22 ( V_12 , V_180 ) ;
if ( ! V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_48 ;
}
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_253 &&
! F_49 ( V_21 , V_179 ) ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
V_270 = F_5 ( V_7 -> V_20 ) ;
if ( V_270 -> V_24 . type != V_18 &&
V_270 -> V_24 . type != V_269 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 -> V_185 -> V_19 ) {
if ( V_270 -> V_15 . V_20 . V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_26 ;
}
F_60 ( V_270 -> V_15 . V_20 . V_21 , V_21 ) ;
}
V_21 -> V_12 = V_270 ;
F_71 ( V_21 ) ;
}
V_13 = F_75 ( V_9 , V_21 , V_7 ) ;
if ( V_13 ) {
F_25 ( & V_9 -> V_47 ) ;
return V_13 ;
}
if ( F_49 ( V_21 , V_179 ) && V_7 -> V_253 )
F_89 ( V_21 ) ;
F_25 ( & V_9 -> V_47 ) ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_240 & F_48 ( V_168 ) )
F_95 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_271 , T_3 * V_272 )
{
struct V_11 * V_12 ;
struct V_273 * V_274 ;
struct V_32 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_272 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_13 = F_97 ( V_271 , V_12 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
V_274 = F_98 ( V_271 , V_12 ) ;
if ( ! V_274 ) {
F_35 () ;
return - V_275 ;
}
F_99 ( V_274 , V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_271 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_271 )
return F_101 ( V_271 , V_12 ) ;
F_102 ( V_12 ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_271 , T_3 * V_272 )
{
struct V_11 * V_12 ;
struct V_273 * V_274 ;
struct V_32 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_272 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_274 = F_98 ( V_271 , V_12 ) ;
if ( ! V_274 ) {
F_35 () ;
return - V_48 ;
}
F_99 ( V_274 , V_21 ) ;
F_35 () ;
return 0 ;
}
static void F_104 ( struct V_273 * V_274 , T_3 * V_272 ,
struct V_276 * V_277 )
{
struct V_32 * V_278 = F_32 ( V_274 -> V_272 ) ;
if ( V_278 )
memcpy ( V_272 , V_278 -> V_21 . V_181 , V_182 ) ;
else
memset ( V_272 , 0 , V_182 ) ;
V_277 -> V_97 = V_279 ;
V_277 -> V_99 = V_280 |
V_281 |
V_282 |
V_283 |
V_284 |
V_285 |
V_286 ;
V_277 -> V_287 = V_274 -> V_288 . V_289 ;
V_277 -> V_290 = V_274 -> V_290 ;
V_277 -> V_291 = V_274 -> V_291 ;
if ( F_105 ( V_118 , V_274 -> V_292 ) )
V_277 -> V_293 = F_44 ( V_274 -> V_292 - V_118 ) ;
V_277 -> V_294 =
F_44 ( V_274 -> V_294 ) ;
V_277 -> V_295 = V_274 -> V_295 ;
V_277 -> V_5 = 0 ;
if ( V_274 -> V_5 & V_296 )
V_277 -> V_5 |= V_297 ;
if ( V_274 -> V_5 & V_298 )
V_277 -> V_5 |= V_299 ;
if ( V_274 -> V_5 & V_300 )
V_277 -> V_5 |= V_301 ;
if ( V_274 -> V_5 & V_302 )
V_277 -> V_5 |= V_303 ;
if ( V_274 -> V_5 & V_298 )
V_277 -> V_5 |= V_299 ;
V_277 -> V_5 = V_274 -> V_5 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_271 , T_3 * V_272 , struct V_276 * V_277 )
{
struct V_11 * V_12 ;
struct V_273 * V_274 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_274 = F_98 ( V_271 , V_12 ) ;
if ( ! V_274 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_271 , V_274 -> V_271 , V_182 ) ;
F_104 ( V_274 , V_272 , V_277 ) ;
F_35 () ;
return 0 ;
}
static int F_107 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_271 , T_3 * V_272 ,
struct V_276 * V_277 )
{
struct V_11 * V_12 ;
struct V_273 * V_274 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_274 = F_108 ( V_74 , V_12 ) ;
if ( ! V_274 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_271 , V_274 -> V_271 , V_182 ) ;
F_104 ( V_274 , V_272 , V_277 ) ;
F_35 () ;
return 0 ;
}
static int F_109 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_304 * V_45 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_45 , & ( V_12 -> V_15 . V_259 . V_305 ) , sizeof( struct V_304 ) ) ;
return 0 ;
}
static inline bool F_110 ( enum V_306 V_307 , T_1 V_167 )
{
return ( V_167 >> ( V_307 - 1 ) ) & 0x1 ;
}
static int F_111 ( struct V_308 * V_309 ,
const struct V_310 * V_311 )
{
T_3 * V_312 ;
const T_3 * V_313 ;
struct V_11 * V_12 = F_112 ( V_309 ,
struct V_11 , V_15 . V_259 ) ;
V_312 = NULL ;
V_313 = V_309 -> V_314 ;
if ( V_311 -> V_315 ) {
V_312 = F_113 ( V_311 -> V_314 , V_311 -> V_315 ,
V_206 ) ;
if ( ! V_312 )
return - V_193 ;
}
V_309 -> V_315 = V_311 -> V_315 ;
V_309 -> V_314 = V_312 ;
F_114 ( V_313 ) ;
V_309 -> V_316 = V_311 -> V_316 ;
memcpy ( V_309 -> V_317 , V_311 -> V_317 , V_309 -> V_316 ) ;
V_309 -> V_318 = V_311 -> V_319 ;
V_309 -> V_320 = V_311 -> V_321 ;
V_309 -> V_260 = V_322 ;
if ( V_311 -> V_323 )
V_309 -> V_260 |= V_324 ;
if ( V_311 -> V_325 )
V_309 -> V_260 |= V_261 ;
memcpy ( V_12 -> V_24 . V_154 . V_326 , V_311 -> V_326 ,
sizeof( V_311 -> V_326 ) ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_167 ,
const struct V_304 * V_327 )
{
struct V_304 * V_45 ;
struct V_11 * V_12 ;
struct V_308 * V_309 ;
V_12 = F_5 ( V_10 ) ;
V_309 = & V_12 -> V_15 . V_259 ;
V_45 = & ( V_12 -> V_15 . V_259 . V_305 ) ;
if ( F_110 ( V_328 , V_167 ) )
V_45 -> V_329 = V_327 -> V_329 ;
if ( F_110 ( V_330 , V_167 ) )
V_45 -> V_331 = V_327 -> V_331 ;
if ( F_110 ( V_332 , V_167 ) )
V_45 -> V_333 = V_327 -> V_333 ;
if ( F_110 ( V_334 , V_167 ) )
V_45 -> V_335 = V_327 -> V_335 ;
if ( F_110 ( V_336 , V_167 ) )
V_45 -> V_337 = V_327 -> V_337 ;
if ( F_110 ( V_338 , V_167 ) )
V_45 -> V_339 = V_327 -> V_339 ;
if ( F_110 ( V_340 , V_167 ) )
V_45 -> V_339 = V_327 -> V_341 ;
if ( F_110 ( V_342 , V_167 ) )
V_45 -> V_343 = V_327 -> V_343 ;
if ( F_110 ( V_344 , V_167 ) )
V_45 -> V_345 =
V_327 -> V_345 ;
if ( F_110 ( V_346 , V_167 ) )
V_45 -> V_347 = V_327 -> V_347 ;
if ( F_110 ( V_348 , V_167 ) )
V_45 -> V_349 = V_327 -> V_349 ;
if ( F_110 ( V_350 , V_167 ) )
V_45 -> V_351 =
V_327 -> V_351 ;
if ( F_110 ( V_352 , V_167 ) )
V_45 -> V_353 =
V_327 -> V_353 ;
if ( F_110 ( V_354 , V_167 ) )
V_45 -> V_355 =
V_327 -> V_355 ;
if ( F_110 ( V_356 ,
V_167 ) )
V_45 -> V_357 =
V_327 -> V_357 ;
if ( F_110 ( V_358 , V_167 ) ) {
V_45 -> V_359 = V_327 -> V_359 ;
F_116 ( V_309 ) ;
}
if ( F_110 ( V_360 , V_167 ) ) {
if ( V_327 -> V_361 &&
! V_45 -> V_359 ) {
V_45 -> V_359 = 1 ;
F_116 ( V_309 ) ;
}
V_45 -> V_361 =
V_327 -> V_361 ;
}
if ( F_110 ( V_362 , V_167 ) ) {
V_45 -> V_363 =
V_327 -> V_363 ;
}
if ( F_110 ( V_364 , V_167 ) )
V_45 -> V_365 = V_327 -> V_365 ;
if ( F_110 ( V_366 , V_167 ) ) {
if ( ! ( V_12 -> V_9 -> V_78 . V_5 & V_131 ) )
return - V_367 ;
V_45 -> V_368 = V_327 -> V_368 ;
}
return 0 ;
}
static int F_117 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_304 * V_45 ,
const struct V_310 * V_311 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_308 * V_309 = & V_12 -> V_15 . V_259 ;
int V_13 ;
memcpy ( & V_309 -> V_305 , V_45 , sizeof( struct V_304 ) ) ;
V_13 = F_111 ( V_309 , V_311 ) ;
if ( V_13 )
return V_13 ;
F_118 ( V_12 ) ;
return 0 ;
}
static int F_119 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_120 ( V_12 ) ;
return 0 ;
}
static int F_121 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_369 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_199 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_155 >= 0 ) {
V_12 -> V_24 . V_154 . V_155 = V_7 -> V_155 ;
V_199 |= V_370 ;
}
if ( V_7 -> V_157 >= 0 ) {
V_12 -> V_24 . V_154 . V_157 =
V_7 -> V_157 ;
V_199 |= V_371 ;
}
if ( ! V_12 -> V_24 . V_154 . V_159 &&
V_12 -> V_9 -> V_78 . V_45 . V_80 -> V_81 == V_372 ) {
V_12 -> V_24 . V_154 . V_159 = true ;
V_199 |= V_373 ;
}
if ( V_7 -> V_374 >= 0 ) {
V_12 -> V_24 . V_154 . V_159 =
V_7 -> V_374 ;
V_199 |= V_373 ;
}
if ( V_7 -> V_375 ) {
int V_237 , V_238 ;
T_1 V_236 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_76 * V_77 =
V_2 -> V_79 [ V_9 -> V_239 -> V_81 ] ;
for ( V_237 = 0 ; V_237 < V_7 -> V_376 ; V_237 ++ ) {
int V_73 = ( V_7 -> V_375 [ V_237 ] & 0x7f ) * 5 ;
for ( V_238 = 0 ; V_238 < V_77 -> V_255 ; V_238 ++ ) {
if ( V_77 -> V_83 [ V_238 ] . V_84 == V_73 )
V_236 |= F_48 ( V_238 ) ;
}
}
V_12 -> V_24 . V_154 . V_375 = V_236 ;
V_199 |= V_377 ;
}
if ( V_7 -> V_378 >= 0 ) {
if ( V_7 -> V_378 )
V_12 -> V_5 |= V_379 ;
else
V_12 -> V_5 &= ~ V_379 ;
}
if ( V_7 -> V_380 >= 0 ) {
V_12 -> V_24 . V_154 . V_381 =
( T_2 ) V_7 -> V_380 ;
V_199 |= V_382 ;
}
F_68 ( V_12 , V_199 ) ;
return 0 ;
}
static int F_122 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_383 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_384 V_385 ;
if ( ! V_9 -> V_386 -> V_387 )
return - V_388 ;
memset ( & V_385 , 0 , sizeof( V_385 ) ) ;
V_385 . V_389 = V_7 -> V_389 ;
V_385 . V_390 = V_7 -> V_391 ;
V_385 . V_392 = V_7 -> V_393 ;
V_385 . V_394 = V_7 -> V_394 ;
V_385 . V_395 = false ;
if ( V_7 -> V_396 >= V_9 -> V_78 . V_397 )
return - V_41 ;
V_12 -> V_398 [ V_7 -> V_396 ] = V_385 ;
if ( F_123 ( V_9 , V_12 , V_7 -> V_396 , & V_385 ) ) {
F_124 ( V_9 -> V_78 . V_2 ,
L_1 ,
V_7 -> V_396 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_125 ( struct V_2 * V_2 ,
struct V_1 * V_399 ,
struct V_400 * V_401 ,
enum V_402 V_403 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_400 * V_404 ;
enum V_402 V_405 ;
enum V_402 V_406 = V_407 ;
if ( V_399 )
V_12 = F_5 ( V_399 ) ;
switch ( F_126 ( V_9 , NULL ) ) {
case V_408 :
return - V_26 ;
case V_409 :
if ( V_9 -> V_239 != V_401 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_410 == V_403 )
return 0 ;
break;
case V_411 :
break;
}
if ( V_12 )
V_406 = V_12 -> V_24 . V_154 . V_403 ;
V_405 = V_9 -> V_410 ;
if ( ! F_127 ( V_9 , V_12 , V_403 ) )
return - V_26 ;
V_404 = V_9 -> V_239 ;
V_9 -> V_239 = V_401 ;
if ( ( V_404 != V_9 -> V_239 ) ||
( V_405 != V_9 -> V_410 ) )
F_128 ( V_9 , V_412 ) ;
if ( V_12 && V_12 -> V_24 . type != V_14 &&
V_406 != V_12 -> V_24 . V_154 . V_403 )
F_68 ( V_12 , V_382 ) ;
return 0 ;
}
static int F_129 ( struct V_2 * V_2 ,
struct V_413 * V_414 )
{
return F_130 ( F_2 ( V_2 ) , V_414 ) ;
}
static int F_131 ( struct V_2 * V_2 )
{
return F_132 ( F_2 ( V_2 ) ) ;
}
static int F_133 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_415 * V_416 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_134 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_417 :
case V_418 :
case V_419 :
break;
case V_420 :
if ( V_12 -> V_9 -> V_386 -> V_421 )
break;
case V_269 :
if ( V_12 -> V_15 . V_191 . V_201 )
return - V_388 ;
break;
default:
return - V_388 ;
}
return F_135 ( V_12 , V_416 ) ;
}
static int
F_136 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_422 * V_416 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_386 -> V_423 )
return - V_388 ;
return F_137 ( V_12 , V_416 ) ;
}
static int
F_138 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_386 -> V_424 )
return - V_388 ;
return F_139 ( V_12 ) ;
}
static int F_140 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_425 * V_416 )
{
return F_141 ( F_5 ( V_10 ) , V_416 ) ;
}
static int F_142 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_426 * V_416 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_126 ( V_9 , V_12 ) ) {
case V_408 :
return - V_26 ;
case V_409 :
if ( V_9 -> V_239 == V_416 -> V_427 -> V_80 )
break;
return - V_26 ;
case V_411 :
break;
}
return F_143 ( F_5 ( V_10 ) , V_416 ) ;
}
static int F_144 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_428 * V_416 )
{
return F_145 ( F_5 ( V_10 ) , V_416 ) ;
}
static int F_146 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_429 * V_416 )
{
return F_147 ( F_5 ( V_10 ) , V_416 ) ;
}
static int F_148 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_430 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_126 ( V_9 , V_12 ) ) {
case V_408 :
return - V_26 ;
case V_409 :
if ( ! V_7 -> V_431 )
return - V_26 ;
if ( V_9 -> V_239 == V_7 -> V_80 )
break;
return - V_26 ;
case V_411 :
break;
}
return F_149 ( V_12 , V_7 ) ;
}
static int F_150 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_151 ( V_12 ) ;
}
static int F_152 ( struct V_2 * V_2 , T_1 V_199 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_199 & V_432 ) {
V_13 = F_153 ( V_9 , V_2 -> V_433 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_199 & V_434 ) {
V_13 = F_154 ( V_9 , V_2 -> V_435 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_199 & V_436 ) {
V_13 = F_155 ( V_9 , V_2 -> V_437 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_199 & V_438 )
V_9 -> V_78 . V_45 . V_439 = V_2 -> V_440 ;
if ( V_199 & V_441 )
V_9 -> V_78 . V_45 . V_442 = V_2 -> V_443 ;
if ( V_199 &
( V_438 | V_441 ) )
F_128 ( V_9 , V_444 ) ;
return 0 ;
}
static int F_156 ( struct V_2 * V_2 ,
enum V_445 type , int V_446 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_400 * V_401 = V_9 -> V_78 . V_45 . V_80 ;
T_1 V_447 = 0 ;
switch ( type ) {
case V_448 :
V_9 -> V_449 = - 1 ;
break;
case V_450 :
if ( V_446 < 0 || ( V_446 % 100 ) )
return - V_388 ;
V_9 -> V_449 = F_157 ( V_446 ) ;
break;
case V_451 :
if ( V_446 < 0 || ( V_446 % 100 ) )
return - V_388 ;
if ( F_157 ( V_446 ) > V_401 -> V_452 )
return - V_41 ;
V_9 -> V_449 = F_157 ( V_446 ) ;
break;
}
F_128 ( V_9 , V_447 ) ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 , int * V_453 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_453 = V_9 -> V_78 . V_45 . V_454 ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_181 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_455 . V_456 , V_181 , V_182 ) ;
return 0 ;
}
static void F_160 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_161 ( V_9 ) ;
}
static int F_162 ( struct V_2 * V_2 , void * V_457 , int V_228 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_386 -> V_458 )
return - V_388 ;
return V_9 -> V_386 -> V_458 ( & V_9 -> V_78 , V_457 , V_228 ) ;
}
static int F_163 ( struct V_2 * V_2 ,
struct V_188 * V_225 ,
struct V_459 * V_234 ,
void * V_457 , int V_228 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_386 -> V_460 )
return - V_388 ;
return V_9 -> V_386 -> V_460 ( & V_9 -> V_78 , V_225 , V_234 , V_457 , V_228 ) ;
}
int F_164 ( struct V_11 * V_12 ,
enum V_461 V_462 )
{
const T_3 * V_191 ;
enum V_461 V_463 ;
int V_13 ;
F_165 ( & V_12 -> V_15 . V_23 . V_464 ) ;
V_463 = V_12 -> V_15 . V_23 . V_465 ;
V_12 -> V_15 . V_23 . V_465 = V_462 ;
if ( V_463 == V_462 &&
V_462 != V_466 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_467 ||
V_12 -> V_24 . V_154 . V_403 == V_407 ) {
F_19 ( & V_12 -> V_9 -> V_468 ) ;
F_166 ( V_12 -> V_9 ) ;
F_25 ( & V_12 -> V_9 -> V_468 ) ;
return 0 ;
}
V_191 = V_12 -> V_15 . V_23 . V_467 -> V_469 ;
if ( V_462 == V_466 ) {
if ( V_12 -> V_15 . V_23 . V_470 )
V_462 = V_471 ;
else
V_462 = V_472 ;
}
V_13 = F_167 ( V_12 , V_462 ,
V_191 , V_191 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_465 = V_463 ;
return V_13 ;
}
static int F_168 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_473 , int V_474 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_53 ( V_10 -> V_185 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_388 ;
if ( ! ( V_9 -> V_78 . V_5 & V_475 ) )
return - V_388 ;
if ( V_473 == V_12 -> V_15 . V_23 . V_470 &&
V_474 == V_9 -> V_476 )
return 0 ;
V_12 -> V_15 . V_23 . V_470 = V_473 ;
V_9 -> V_476 = V_474 ;
F_19 ( & V_12 -> V_15 . V_23 . V_464 ) ;
F_164 ( V_12 , V_12 -> V_15 . V_23 . V_465 ) ;
F_25 ( & V_12 -> V_15 . V_23 . V_464 ) ;
if ( V_9 -> V_78 . V_5 & V_477 )
F_128 ( V_9 , V_478 ) ;
F_95 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_6 V_479 , T_1 V_480 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_481 * V_24 = & V_12 -> V_24 ;
struct V_482 * V_154 = & V_24 -> V_154 ;
if ( V_479 == V_154 -> V_483 &&
V_480 == V_154 -> V_484 )
return 0 ;
V_154 -> V_483 = V_479 ;
V_154 -> V_484 = V_480 ;
if ( V_12 -> V_15 . V_23 . V_467 &&
V_12 -> V_24 . V_485 & V_486 )
F_68 ( V_12 , V_487 ) ;
return 0 ;
}
static int F_170 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_3 * V_181 ,
const struct V_488 * V_167 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_53 ( V_10 -> V_185 ) ;
int V_237 , V_17 ;
if ( V_9 -> V_78 . V_5 & V_489 ) {
V_17 = F_171 ( V_9 , V_12 , V_167 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_237 = 0 ; V_237 < V_490 ; V_237 ++ ) {
V_12 -> V_491 [ V_237 ] = V_167 -> V_231 [ V_237 ] . V_82 ;
memcpy ( V_12 -> V_492 [ V_237 ] , V_167 -> V_231 [ V_237 ] . V_85 ,
sizeof( V_167 -> V_231 [ V_237 ] . V_85 ) ) ;
}
return 0 ;
}
static int F_172 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_400 * V_401 ,
enum V_402 V_493 ,
unsigned int V_494 , T_4 * V_54 )
{
int V_17 ;
T_1 V_495 ;
F_165 ( & V_9 -> V_464 ) ;
if ( V_9 -> V_496 )
return - V_26 ;
V_495 = F_173 () | 1 ;
* V_54 = V_495 ;
V_9 -> V_497 = V_10 ;
V_9 -> V_496 = V_495 ;
V_9 -> V_498 = V_401 ;
V_9 -> V_499 = V_493 ;
V_9 -> V_500 = V_494 ;
V_17 = F_174 ( V_9 , V_401 , V_493 , V_494 ) ;
if ( V_17 ) {
V_9 -> V_498 = NULL ;
V_9 -> V_496 = 0 ;
}
return V_17 ;
}
static int F_175 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_400 * V_401 ,
enum V_402 V_403 ,
unsigned int V_494 ,
T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_386 -> V_501 ) {
int V_17 ;
F_19 ( & V_9 -> V_464 ) ;
V_17 = F_172 ( V_9 , V_10 ,
V_401 , V_403 ,
V_494 , V_54 ) ;
V_9 -> V_502 = false ;
F_25 ( & V_9 -> V_464 ) ;
return V_17 ;
}
return F_176 ( V_12 , V_401 , V_403 ,
V_494 , V_54 ) ;
}
static int F_177 ( struct V_8 * V_9 ,
T_4 V_54 )
{
int V_17 ;
F_165 ( & V_9 -> V_464 ) ;
if ( V_9 -> V_496 != V_54 )
return - V_48 ;
V_17 = F_178 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_496 = 0 ;
V_9 -> V_498 = NULL ;
F_179 ( V_9 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_386 -> V_503 ) {
int V_17 ;
F_19 ( & V_9 -> V_464 ) ;
V_17 = F_177 ( V_9 , V_54 ) ;
F_25 ( & V_9 -> V_464 ) ;
return V_17 ;
}
return F_181 ( V_12 , V_54 ) ;
}
static enum V_504
F_182 ( struct V_505 * V_506 , struct V_188 * V_225 )
{
if ( V_506 -> V_507 . V_508 && ! V_506 -> V_507 . V_509 )
F_183 ( V_506 -> V_12 -> V_10 ,
( unsigned long ) V_506 -> V_507 . V_510 ,
V_506 -> V_457 , V_506 -> V_511 , false , V_206 ) ;
return V_512 ;
}
static int F_184 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_400 * V_401 , bool V_513 ,
enum V_402 V_403 ,
bool V_514 , unsigned int V_508 ,
const T_3 * V_515 , T_5 V_228 , bool V_516 ,
bool V_517 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_188 * V_225 ;
struct V_32 * V_21 ;
struct V_505 * V_506 ;
const struct V_518 * V_519 = ( void * ) V_515 ;
T_1 V_5 ;
bool V_520 = false ;
if ( V_517 )
V_5 = V_521 ;
else
V_5 = V_522 |
V_523 ;
if ( V_401 != V_9 -> V_524 &&
V_401 != V_9 -> V_239 )
V_520 = true ;
if ( V_514 &&
( V_403 != V_9 -> V_525 &&
V_403 != V_9 -> V_410 ) )
V_520 = true ;
if ( V_401 == V_9 -> V_498 ) {
V_520 = false ;
V_5 |= V_526 ;
}
if ( V_516 )
V_5 |= V_527 ;
if ( V_520 && ! V_513 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_417 :
case V_269 :
case V_18 :
case V_420 :
case V_418 :
if ( ! F_185 ( V_519 -> V_528 ) ||
V_519 -> V_15 . V_529 . V_530 == V_531 )
break;
F_31 () ;
V_21 = F_21 ( V_12 , V_519 -> V_226 ) ;
F_35 () ;
if ( ! V_21 )
return - V_532 ;
break;
case V_22 :
case V_419 :
break;
default:
return - V_388 ;
}
V_225 = F_58 ( V_9 -> V_78 . V_533 + V_228 ) ;
if ( ! V_225 )
return - V_193 ;
F_186 ( V_225 , V_9 -> V_78 . V_533 ) ;
memcpy ( F_59 ( V_225 , V_228 ) , V_515 , V_228 ) ;
F_187 ( V_225 ) -> V_5 = V_5 ;
V_225 -> V_10 = V_12 -> V_10 ;
* V_54 = ( unsigned long ) V_225 ;
if ( V_520 && V_9 -> V_386 -> V_501 ) {
unsigned int V_494 ;
int V_17 ;
F_19 ( & V_9 -> V_464 ) ;
V_494 = 100 ;
if ( V_508 )
V_494 = V_508 ;
V_17 = F_172 ( V_9 , V_10 , V_401 ,
V_403 ,
V_494 , V_54 ) ;
if ( V_17 ) {
F_188 ( V_225 ) ;
F_25 ( & V_9 -> V_464 ) ;
return V_17 ;
}
V_9 -> V_502 = true ;
V_9 -> V_500 = V_508 ;
* V_54 ^= 2 ;
F_187 ( V_225 ) -> V_5 |= V_526 ;
V_9 -> V_534 = V_225 ;
V_9 -> V_535 = V_225 ;
F_25 ( & V_9 -> V_464 ) ;
return 0 ;
}
if ( ! V_520 && ! V_508 && ! V_12 -> V_24 . V_154 . V_536 ) {
F_189 ( V_12 , V_225 ) ;
return 0 ;
}
V_506 = F_64 ( sizeof( * V_506 ) + V_228 , V_206 ) ;
if ( ! V_506 ) {
F_188 ( V_225 ) ;
return - V_193 ;
}
V_506 -> type = V_537 ;
V_506 -> V_401 = V_401 ;
V_506 -> V_538 = V_403 ;
V_506 -> V_12 = V_12 ;
V_506 -> V_539 = F_182 ;
V_506 -> V_507 . V_510 = V_225 ;
V_506 -> V_507 . V_508 = V_508 ;
V_506 -> V_511 = V_228 ;
memcpy ( V_506 -> V_457 , V_515 , V_228 ) ;
F_190 ( V_506 ) ;
return 0 ;
}
static int F_191 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_505 * V_506 ;
int V_17 = - V_48 ;
F_19 ( & V_9 -> V_464 ) ;
if ( V_9 -> V_386 -> V_503 ) {
V_54 ^= 2 ;
V_17 = F_177 ( V_9 , V_54 ) ;
if ( V_17 == 0 ) {
F_188 ( V_9 -> V_534 ) ;
V_9 -> V_534 = NULL ;
V_9 -> V_535 = NULL ;
}
F_25 ( & V_9 -> V_464 ) ;
return V_17 ;
}
F_67 (wk, &local->work_list, list) {
if ( V_506 -> V_12 != V_12 )
continue;
if ( V_506 -> type != V_537 )
continue;
if ( V_54 != ( unsigned long ) V_506 -> V_507 . V_510 )
continue;
V_506 -> V_474 = V_118 ;
F_192 ( & V_9 -> V_78 , & V_9 -> V_540 ) ;
V_17 = 0 ;
break;
}
F_25 ( & V_9 -> V_464 ) ;
return V_17 ;
}
static void F_193 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_541 , bool V_542 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_541 != ( V_543 | V_544 ) )
return;
if ( V_542 )
V_9 -> V_545 ++ ;
else
V_9 -> V_545 -- ;
F_192 ( & V_9 -> V_78 , & V_9 -> V_546 ) ;
}
static int F_194 ( struct V_2 * V_2 , T_1 V_547 , T_1 V_548 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_549 )
return - V_388 ;
return F_195 ( V_9 , V_547 , V_548 ) ;
}
static int F_196 ( struct V_2 * V_2 , T_1 * V_547 , T_1 * V_548 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_197 ( V_9 , V_547 , V_548 ) ;
}
static int F_198 ( struct V_2 * V_2 , T_1 V_61 , T_1 V_550 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_199 ( V_9 , V_61 , V_550 ) ;
}
static void F_200 ( struct V_2 * V_2 ,
T_1 * V_61 , T_1 * V_551 , T_1 * V_550 , T_1 * V_552 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_201 ( V_9 , V_61 , V_551 , V_550 , V_552 ) ;
}
static int F_202 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_553 * V_457 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_386 -> V_554 )
return - V_388 ;
F_203 ( V_9 , V_12 , V_457 ) ;
return 0 ;
}
static void F_204 ( struct V_188 * V_225 )
{
T_3 * V_555 = ( void * ) F_59 ( V_225 , 7 ) ;
* V_555 ++ = V_556 ;
* V_555 ++ = 5 ;
* V_555 ++ = 0x0 ;
* V_555 ++ = 0x0 ;
* V_555 ++ = 0x0 ;
* V_555 ++ = 0x0 ;
* V_555 ++ = V_557 ;
}
static T_2 F_205 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_558 ;
V_558 = 0 ;
if ( V_9 -> V_239 -> V_81 != V_559 )
return V_558 ;
if ( ! ( V_9 -> V_78 . V_5 & V_560 ) )
V_558 |= V_561 ;
if ( ! ( V_9 -> V_78 . V_5 & V_562 ) )
V_558 |= V_563 ;
return V_558 ;
}
static void F_206 ( struct V_188 * V_225 , T_3 * V_564 ,
T_3 * V_565 , T_3 * V_469 )
{
struct V_566 * V_567 ;
V_567 = ( void * ) F_59 ( V_225 , sizeof( struct V_566 ) ) ;
V_567 -> V_568 = V_569 ;
V_567 -> V_315 = sizeof( struct V_566 ) - 2 ;
memcpy ( V_567 -> V_469 , V_469 , V_182 ) ;
memcpy ( V_567 -> V_570 , V_564 , V_182 ) ;
memcpy ( V_567 -> V_571 , V_565 , V_182 ) ;
}
static int
F_207 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_565 , T_3 V_572 , T_3 V_573 ,
T_2 V_574 , struct V_188 * V_225 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_575 * V_576 ;
V_576 = ( void * ) F_59 ( V_225 , F_208 ( struct V_575 , V_15 ) ) ;
memcpy ( V_576 -> V_226 , V_565 , V_182 ) ;
memcpy ( V_576 -> V_227 , V_12 -> V_24 . V_181 , V_182 ) ;
V_576 -> V_577 = F_209 ( V_578 ) ;
V_576 -> V_579 = V_580 ;
switch ( V_572 ) {
case V_581 :
V_576 -> V_530 = V_582 ;
V_576 -> V_572 = V_581 ;
F_59 ( V_225 , sizeof( V_576 -> V_15 . V_583 ) ) ;
V_576 -> V_15 . V_583 . V_573 = V_573 ;
V_576 -> V_15 . V_583 . V_584 =
F_210 ( F_205 ( V_12 ) ) ;
F_211 ( & V_12 -> V_24 , V_225 ) ;
F_212 ( & V_12 -> V_24 , V_225 ) ;
F_204 ( V_225 ) ;
break;
case V_585 :
V_576 -> V_530 = V_582 ;
V_576 -> V_572 = V_585 ;
F_59 ( V_225 , sizeof( V_576 -> V_15 . V_586 ) ) ;
V_576 -> V_15 . V_586 . V_574 = F_210 ( V_574 ) ;
V_576 -> V_15 . V_586 . V_573 = V_573 ;
V_576 -> V_15 . V_586 . V_584 =
F_210 ( F_205 ( V_12 ) ) ;
F_211 ( & V_12 -> V_24 , V_225 ) ;
F_212 ( & V_12 -> V_24 , V_225 ) ;
F_204 ( V_225 ) ;
break;
case V_587 :
V_576 -> V_530 = V_582 ;
V_576 -> V_572 = V_587 ;
F_59 ( V_225 , sizeof( V_576 -> V_15 . V_588 ) ) ;
V_576 -> V_15 . V_588 . V_574 = F_210 ( V_574 ) ;
V_576 -> V_15 . V_588 . V_573 = V_573 ;
break;
case V_589 :
V_576 -> V_530 = V_582 ;
V_576 -> V_572 = V_589 ;
F_59 ( V_225 , sizeof( V_576 -> V_15 . V_590 ) ) ;
V_576 -> V_15 . V_590 . V_591 = F_210 ( V_574 ) ;
break;
case V_592 :
V_576 -> V_530 = V_582 ;
V_576 -> V_572 = V_592 ;
F_59 ( V_225 , sizeof( V_576 -> V_15 . V_593 ) ) ;
V_576 -> V_15 . V_593 . V_573 = V_573 ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int
F_213 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_565 , T_3 V_572 , T_3 V_573 ,
T_2 V_574 , struct V_188 * V_225 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_518 * V_519 ;
V_519 = ( void * ) F_59 ( V_225 , 24 ) ;
memset ( V_519 , 0 , 24 ) ;
memcpy ( V_519 -> V_226 , V_565 , V_182 ) ;
memcpy ( V_519 -> V_227 , V_12 -> V_24 . V_181 , V_182 ) ;
memcpy ( V_519 -> V_469 , V_12 -> V_15 . V_23 . V_469 , V_182 ) ;
V_519 -> V_528 = F_210 ( V_543 |
V_594 ) ;
switch ( V_572 ) {
case V_595 :
F_59 ( V_225 , 1 + sizeof( V_519 -> V_15 . V_529 . V_15 . V_596 ) ) ;
V_519 -> V_15 . V_529 . V_530 = V_531 ;
V_519 -> V_15 . V_529 . V_15 . V_596 . V_572 =
V_595 ;
V_519 -> V_15 . V_529 . V_15 . V_596 . V_573 =
V_573 ;
V_519 -> V_15 . V_529 . V_15 . V_596 . V_584 =
F_210 ( F_205 ( V_12 ) ) ;
F_211 ( & V_12 -> V_24 , V_225 ) ;
F_212 ( & V_12 -> V_24 , V_225 ) ;
F_204 ( V_225 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_214 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_565 , T_3 V_572 , T_3 V_573 ,
T_2 V_574 , const T_3 * V_597 ,
T_5 V_598 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_599 * V_600 ;
struct V_188 * V_225 = NULL ;
bool V_601 ;
int V_17 ;
if ( ! ( V_2 -> V_5 & V_602 ) )
return - V_367 ;
if ( V_12 -> V_24 . type != V_22 ||
! V_12 -> V_15 . V_23 . V_467 )
return - V_41 ;
#ifdef F_215
F_216 ( V_603 L_2 , V_572 , V_565 ) ;
#endif
V_225 = F_58 ( V_9 -> V_78 . V_533 +
F_217 ( sizeof( struct V_518 ) ,
sizeof( struct V_575 ) ) +
50 +
7 +
V_598 +
sizeof( struct V_566 ) ) ;
if ( ! V_225 )
return - V_193 ;
V_600 = F_187 ( V_225 ) ;
F_186 ( V_225 , V_9 -> V_78 . V_533 ) ;
switch ( V_572 ) {
case V_581 :
case V_585 :
case V_587 :
case V_589 :
case V_592 :
V_17 = F_207 ( V_2 , V_10 , V_565 ,
V_572 , V_573 ,
V_574 , V_225 ) ;
V_601 = false ;
break;
case V_595 :
V_17 = F_213 ( V_2 , V_10 , V_565 , V_572 ,
V_573 , V_574 ,
V_225 ) ;
V_601 = true ;
break;
default:
V_17 = - V_367 ;
break;
}
if ( V_17 < 0 )
goto V_604;
if ( V_598 )
memcpy ( F_59 ( V_225 , V_598 ) , V_597 , V_598 ) ;
switch ( V_572 ) {
case V_581 :
case V_587 :
case V_589 :
case V_592 :
F_206 ( V_225 , V_12 -> V_24 . V_181 , V_565 ,
V_12 -> V_15 . V_23 . V_469 ) ;
break;
case V_585 :
case V_595 :
F_206 ( V_225 , V_565 , V_12 -> V_24 . V_181 ,
V_12 -> V_15 . V_23 . V_469 ) ;
break;
default:
V_17 = - V_367 ;
goto V_604;
}
if ( V_601 ) {
F_189 ( V_12 , V_225 ) ;
return 0 ;
}
switch ( V_572 ) {
case V_581 :
case V_585 :
F_218 ( V_225 , V_605 ) ;
V_225 -> V_606 = 2 ;
break;
default:
F_218 ( V_225 , V_607 ) ;
V_225 -> V_606 = 5 ;
break;
}
F_219 () ;
V_17 = F_220 ( V_225 , V_10 ) ;
F_221 () ;
return V_17 ;
V_604:
F_62 ( V_225 ) ;
return V_17 ;
}
static int F_222 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_565 , enum V_608 V_609 )
{
struct V_32 * V_21 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! ( V_2 -> V_5 & V_602 ) )
return - V_367 ;
if ( V_12 -> V_24 . type != V_22 )
return - V_41 ;
#ifdef F_215
F_216 ( V_603 L_3 , V_609 , V_565 ) ;
#endif
switch ( V_609 ) {
case V_610 :
F_31 () ;
V_21 = F_21 ( V_12 , V_565 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_532 ;
}
F_78 ( V_21 , V_611 ) ;
F_35 () ;
break;
case V_612 :
return F_223 ( V_12 , V_565 ) ;
case V_613 :
case V_614 :
case V_615 :
return - V_367 ;
default:
return - V_367 ;
}
return 0 ;
}
static int F_224 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_565 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_616 * V_617 ;
struct V_188 * V_225 ;
int V_198 = sizeof( * V_617 ) ;
T_7 V_618 ;
bool V_619 ;
struct V_599 * V_600 ;
struct V_32 * V_21 ;
F_31 () ;
V_21 = F_21 ( V_12 , V_565 ) ;
if ( V_21 ) {
V_619 = F_49 ( V_21 , V_176 ) ;
F_35 () ;
} else {
F_35 () ;
return - V_532 ;
}
if ( V_619 ) {
V_618 = F_210 ( V_620 |
V_621 |
V_622 ) ;
} else {
V_198 -= 2 ;
V_618 = F_210 ( V_620 |
V_623 |
V_622 ) ;
}
V_225 = F_58 ( V_9 -> V_78 . V_533 + V_198 ) ;
if ( ! V_225 )
return - V_193 ;
V_225 -> V_10 = V_10 ;
F_186 ( V_225 , V_9 -> V_78 . V_533 ) ;
V_617 = ( void * ) F_59 ( V_225 , V_198 ) ;
V_617 -> V_528 = V_618 ;
V_617 -> V_624 = 0 ;
memcpy ( V_617 -> V_625 , V_21 -> V_21 . V_181 , V_182 ) ;
memcpy ( V_617 -> V_626 , V_12 -> V_24 . V_181 , V_182 ) ;
memcpy ( V_617 -> V_627 , V_12 -> V_24 . V_181 , V_182 ) ;
V_617 -> V_628 = 0 ;
V_600 = F_187 ( V_225 ) ;
V_600 -> V_5 |= V_523 |
V_522 ;
F_218 ( V_225 , V_629 ) ;
V_225 -> V_606 = 7 ;
if ( V_619 )
V_617 -> V_630 = F_210 ( 7 ) ;
F_219 () ;
F_225 ( V_12 , V_225 ) ;
F_221 () ;
* V_54 = ( unsigned long ) V_225 ;
return 0 ;
}
static struct V_400 *
F_226 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return V_9 -> V_239 ;
}
