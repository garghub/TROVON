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
static void F_41 ( struct V_32 * V_21 , struct V_86 * V_87 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_88 V_89 ;
V_87 -> V_90 = V_12 -> V_9 -> V_91 ;
V_87 -> V_92 = V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 |
V_105 |
V_106 ;
F_42 ( & V_89 ) ;
V_87 -> V_107 = V_89 . V_108 - V_21 -> V_109 ;
V_87 -> V_110 = F_43 ( V_111 - V_21 -> V_112 ) ;
V_87 -> V_113 = V_21 -> V_113 ;
V_87 -> V_114 = V_21 -> V_114 ;
V_87 -> V_115 = V_21 -> V_115 ;
V_87 -> V_116 = V_21 -> V_116 ;
V_87 -> V_117 = V_21 -> V_118 ;
V_87 -> V_119 = V_21 -> V_120 ;
V_87 -> V_121 = V_21 -> V_122 ;
V_87 -> V_123 = V_21 -> V_123 ;
if ( ( V_21 -> V_9 -> V_78 . V_5 & V_124 ) ||
( V_21 -> V_9 -> V_78 . V_5 & V_125 ) ) {
V_87 -> V_92 |= V_126 | V_127 ;
V_87 -> signal = ( V_128 ) V_21 -> V_129 ;
V_87 -> V_130 = ( V_128 ) - F_44 ( & V_21 -> V_131 ) ;
}
V_87 -> V_132 . V_5 = 0 ;
if ( V_21 -> V_133 . V_5 & V_134 )
V_87 -> V_132 . V_5 |= V_75 ;
if ( V_21 -> V_133 . V_5 & V_135 )
V_87 -> V_132 . V_5 |= V_136 ;
if ( V_21 -> V_133 . V_5 & V_137 )
V_87 -> V_132 . V_5 |= V_138 ;
F_40 ( & V_87 -> V_132 , V_21 , V_21 -> V_133 . V_74 ) ;
V_87 -> V_139 . V_5 = 0 ;
if ( V_21 -> V_140 & V_141 )
V_87 -> V_139 . V_5 |= V_75 ;
if ( V_21 -> V_140 & V_142 )
V_87 -> V_139 . V_5 |= V_136 ;
if ( V_21 -> V_140 & V_143 )
V_87 -> V_139 . V_5 |= V_138 ;
F_40 ( & V_87 -> V_139 , V_21 , V_21 -> V_144 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_45
V_87 -> V_92 |= V_145 |
V_146 |
V_147 ;
V_87 -> V_148 = F_46 ( V_21 -> V_148 ) ;
V_87 -> V_149 = F_46 ( V_21 -> V_149 ) ;
V_87 -> V_150 = V_21 -> V_150 ;
#endif
}
V_87 -> V_151 . V_5 = 0 ;
if ( V_12 -> V_24 . V_152 . V_153 )
V_87 -> V_151 . V_5 |= V_154 ;
if ( V_12 -> V_24 . V_152 . V_155 )
V_87 -> V_151 . V_5 |= V_156 ;
if ( V_12 -> V_24 . V_152 . V_157 )
V_87 -> V_151 . V_5 |= V_158 ;
V_87 -> V_151 . V_159 = V_12 -> V_9 -> V_78 . V_45 . V_160 ;
V_87 -> V_151 . V_161 = V_12 -> V_24 . V_152 . V_162 ;
V_87 -> V_163 . V_164 = 0 ;
V_87 -> V_163 . V_165 = F_47 ( V_166 ) |
F_47 ( V_167 ) |
F_47 ( V_168 ) |
F_47 ( V_169 ) |
F_47 ( V_170 ) |
F_47 ( V_171 ) ;
if ( F_48 ( V_21 , V_172 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_166 ) ;
if ( F_48 ( V_21 , V_173 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_167 ) ;
if ( F_48 ( V_21 , V_174 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_168 ) ;
if ( F_48 ( V_21 , V_175 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_169 ) ;
if ( F_48 ( V_21 , V_176 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_170 ) ;
if ( F_48 ( V_21 , V_177 ) )
V_87 -> V_163 . V_164 |= F_47 ( V_171 ) ;
}
static int F_49 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_178 , struct V_86 * V_87 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_50 ( V_12 , V_74 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_178 , V_21 -> V_21 . V_179 , V_180 ) ;
F_41 ( V_21 , V_87 ) ;
}
F_35 () ;
return V_17 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , struct V_181 * V_182 )
{
struct V_8 * V_9 = F_52 ( V_10 -> V_183 ) ;
return F_53 ( V_9 , V_74 , V_182 ) ;
}
static int F_54 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_178 , struct V_86 * V_87 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_32 * V_21 ;
int V_17 = - V_48 ;
F_31 () ;
V_21 = F_22 ( V_12 , V_178 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_41 ( V_21 , V_87 ) ;
}
F_35 () ;
return V_17 ;
}
static void F_55 ( struct V_11 * V_12 ,
struct V_184 * V_7 )
{
struct V_185 * V_152 = & V_12 -> V_24 . V_152 ;
V_152 -> V_186 = V_7 -> V_186 ;
if ( V_7 -> V_186 )
memcpy ( V_152 -> V_187 , V_7 -> V_187 , V_7 -> V_186 ) ;
V_152 -> V_188 =
( V_7 -> V_188 != V_189 ) ;
}
static int F_56 ( struct V_11 * V_12 ,
T_3 * V_190 , T_5 V_191 )
{
struct V_192 * V_193 , * V_194 ;
if ( ! V_190 || ! V_191 )
return - V_41 ;
V_194 = F_57 ( V_12 -> V_15 . V_195 . V_196 ) ;
V_193 = F_58 ( V_191 ) ;
if ( ! V_193 )
return - V_197 ;
memcpy ( F_59 ( V_193 , V_191 ) , V_190 , V_191 ) ;
F_60 ( V_12 -> V_15 . V_195 . V_196 , V_193 ) ;
F_61 () ;
if ( V_194 )
F_62 ( V_194 ) ;
return 0 ;
}
static int F_63 ( struct V_11 * V_12 ,
struct V_184 * V_7 )
{
struct V_198 * V_193 , * V_194 ;
int V_199 , V_200 ;
int V_201 ;
int V_13 = - V_41 ;
T_1 V_202 = 0 ;
V_194 = F_57 ( V_12 -> V_15 . V_195 . V_203 ) ;
if ( V_7 -> V_204 && ! V_7 -> V_205 )
return - V_41 ;
if ( V_7 -> V_206 &&
( V_12 -> V_24 . V_152 . V_162 != V_7 -> V_206 ) ) {
V_12 -> V_24 . V_152 . V_162 = V_7 -> V_206 ;
F_64 ( V_12 ,
V_207 ) ;
}
if ( ! V_7 -> V_204 && ! V_194 )
return V_13 ;
if ( ! V_7 -> V_159 && ! V_194 )
return V_13 ;
if ( V_7 -> V_204 )
V_199 = V_7 -> V_205 ;
else
V_199 = V_194 -> V_205 ;
if ( V_7 -> V_208 || ! V_194 )
V_200 = V_7 -> V_209 ;
else
V_200 = V_194 -> V_209 ;
V_201 = sizeof( * V_193 ) + V_199 + V_200 ;
V_193 = F_65 ( V_201 , V_210 ) ;
if ( ! V_193 )
return - V_197 ;
if ( V_7 -> V_159 )
V_193 -> V_159 = V_7 -> V_159 ;
else
V_193 -> V_159 = V_194 -> V_159 ;
V_193 -> V_204 = ( ( T_3 * ) V_193 ) + sizeof( * V_193 ) ;
V_193 -> V_208 = V_193 -> V_204 + V_199 ;
V_193 -> V_205 = V_199 ;
V_193 -> V_209 = V_200 ;
if ( V_7 -> V_204 )
memcpy ( V_193 -> V_204 , V_7 -> V_204 , V_199 ) ;
else
memcpy ( V_193 -> V_204 , V_194 -> V_204 , V_199 ) ;
if ( V_7 -> V_208 )
memcpy ( V_193 -> V_208 , V_7 -> V_208 , V_200 ) ;
else
if ( V_194 )
memcpy ( V_193 -> V_208 , V_194 -> V_208 , V_200 ) ;
V_12 -> V_24 . V_152 . V_159 = V_193 -> V_159 ;
F_60 ( V_12 -> V_15 . V_195 . V_203 , V_193 ) ;
F_61 () ;
F_66 ( V_194 ) ;
V_13 = F_56 ( V_12 , V_7 -> V_196 ,
V_7 -> V_211 ) ;
if ( ! V_13 )
V_202 |= V_212 ;
F_55 ( V_12 , V_7 ) ;
V_202 |= V_213 |
V_214 |
V_215 ;
F_64 ( V_12 , V_202 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_184 * V_7 )
{
struct V_11 * V_12 ;
struct V_198 * V_194 ;
struct V_11 * V_20 ;
int V_17 ;
V_12 = F_5 ( V_10 ) ;
V_194 = F_57 ( V_12 -> V_15 . V_195 . V_203 ) ;
if ( V_194 )
return - V_216 ;
V_17 = F_63 ( V_12 , V_7 ) ;
if ( V_17 )
return V_17 ;
V_12 -> V_217 = V_7 -> V_218 . V_219 ;
V_12 -> V_220 = V_7 -> V_218 . V_220 ;
F_68 (vlan, &sdata->u.ap.vlans, u.vlan.list) {
V_20 -> V_217 =
V_7 -> V_218 . V_219 ;
V_20 -> V_220 =
V_7 -> V_218 . V_220 ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_184 * V_7 )
{
struct V_11 * V_12 ;
struct V_198 * V_194 ;
V_12 = F_5 ( V_10 ) ;
V_194 = F_57 ( V_12 -> V_15 . V_195 . V_203 ) ;
if ( ! V_194 )
return - V_48 ;
return F_63 ( V_12 , V_7 ) ;
}
static int F_70 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 ;
struct V_198 * V_194 ;
V_12 = F_5 ( V_10 ) ;
V_194 = F_57 ( V_12 -> V_15 . V_195 . V_203 ) ;
if ( ! V_194 )
return - V_48 ;
F_10 ( V_12 -> V_15 . V_195 . V_203 , NULL ) ;
F_61 () ;
F_66 ( V_194 ) ;
F_64 ( V_12 , V_213 ) ;
return 0 ;
}
static void F_71 ( struct V_32 * V_21 )
{
struct V_221 * V_222 ;
struct V_192 * V_223 ;
V_223 = F_58 ( sizeof( * V_222 ) ) ;
if ( ! V_223 )
return;
V_222 = (struct V_221 * ) F_59 ( V_223 , sizeof( * V_222 ) ) ;
memset ( V_222 -> V_224 , 0xff , V_180 ) ;
memcpy ( V_222 -> V_225 , V_21 -> V_21 . V_179 , V_180 ) ;
V_222 -> V_226 = F_72 ( 6 ) ;
V_222 -> V_227 = 0 ;
V_222 -> V_228 = 0x01 ;
V_222 -> V_229 = 0xaf ;
V_222 -> V_230 [ 0 ] = 0x81 ;
V_222 -> V_230 [ 1 ] = 1 ;
V_222 -> V_230 [ 2 ] = 0 ;
V_223 -> V_10 = V_21 -> V_12 -> V_10 ;
V_223 -> V_231 = F_73 ( V_223 , V_21 -> V_12 -> V_10 ) ;
memset ( V_223 -> V_232 , 0 , sizeof( V_223 -> V_232 ) ) ;
F_74 ( V_223 ) ;
}
static int F_75 ( struct V_8 * V_9 ,
struct V_32 * V_21 ,
struct V_233 * V_7 )
{
int V_17 = 0 ;
T_1 V_234 ;
int V_235 , V_236 ;
struct V_76 * V_77 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_165 , V_164 ;
V_77 = V_9 -> V_78 . V_2 -> V_79 [ V_9 -> V_237 -> V_81 ] ;
V_165 = V_7 -> V_238 ;
V_164 = V_7 -> V_239 ;
if ( V_165 & F_47 ( V_170 ) ) {
if ( F_76 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( V_164 & F_47 ( V_170 ) &&
! F_48 ( V_21 , V_176 ) ) {
V_17 = F_77 ( V_21 ,
V_240 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_77 ( V_21 ,
V_241 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_165 & F_47 ( V_166 ) ) {
if ( V_164 & F_47 ( V_166 ) )
V_17 = F_77 ( V_21 ,
V_242 ) ;
else if ( F_48 ( V_21 , V_172 ) )
V_17 = F_77 ( V_21 ,
V_241 ) ;
if ( V_17 )
return V_17 ;
}
if ( V_165 & F_47 ( V_170 ) ) {
if ( F_76 ( ! F_20 ( & V_12 -> V_24 ) ) )
return - V_41 ;
if ( ! ( V_164 & F_47 ( V_170 ) ) &&
F_48 ( V_21 , V_176 ) ) {
V_17 = F_77 ( V_21 ,
V_240 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_77 ( V_21 ,
V_243 ) ;
if ( V_17 )
return V_17 ;
}
}
if ( V_165 & F_47 ( V_167 ) ) {
if ( V_164 & F_47 ( V_167 ) )
F_78 ( V_21 , V_173 ) ;
else
F_79 ( V_21 , V_173 ) ;
}
if ( V_165 & F_47 ( V_168 ) ) {
if ( V_164 & F_47 ( V_168 ) ) {
F_78 ( V_21 , V_174 ) ;
V_21 -> V_21 . V_244 = true ;
} else {
F_79 ( V_21 , V_174 ) ;
V_21 -> V_21 . V_244 = false ;
}
}
if ( V_165 & F_47 ( V_169 ) ) {
if ( V_164 & F_47 ( V_169 ) )
F_78 ( V_21 , V_175 ) ;
else
F_79 ( V_21 , V_175 ) ;
}
if ( V_165 & F_47 ( V_171 ) ) {
if ( V_164 & F_47 ( V_171 ) )
F_78 ( V_21 , V_177 ) ;
else
F_79 ( V_21 , V_177 ) ;
}
if ( V_7 -> V_245 & V_246 ) {
V_21 -> V_21 . V_247 = V_7 -> V_247 ;
V_21 -> V_21 . V_248 = V_7 -> V_248 ;
}
if ( V_7 -> V_249 )
V_21 -> V_21 . V_249 = V_7 -> V_249 ;
if ( V_7 -> V_250 >= 0 )
V_21 -> V_250 = V_7 -> V_250 ;
if ( V_7 -> V_251 ) {
V_234 = 0 ;
for ( V_235 = 0 ; V_235 < V_7 -> V_252 ; V_235 ++ ) {
int V_73 = ( V_7 -> V_251 [ V_235 ] & 0x7f ) * 5 ;
for ( V_236 = 0 ; V_236 < V_77 -> V_253 ; V_236 ++ ) {
if ( V_77 -> V_83 [ V_236 ] . V_84 == V_73 )
V_234 |= F_47 ( V_236 ) ;
}
}
V_21 -> V_21 . V_254 [ V_9 -> V_237 -> V_81 ] = V_234 ;
}
if ( V_7 -> V_255 )
F_80 ( V_12 , V_77 ,
V_7 -> V_255 ,
& V_21 -> V_21 . V_256 ) ;
if ( F_20 ( & V_12 -> V_24 ) ) {
#ifdef F_45
if ( V_12 -> V_15 . V_257 . V_258 & V_259 )
switch ( V_7 -> V_150 ) {
case V_260 :
case V_261 :
case V_262 :
V_21 -> V_150 = V_7 -> V_150 ;
break;
default:
break;
}
else
switch ( V_7 -> V_263 ) {
case V_264 :
F_81 ( V_21 ) ;
break;
case V_265 :
F_82 ( V_21 ) ;
break;
}
#endif
}
return 0 ;
}
static int F_83 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_178 , struct V_233 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_266 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_267 )
return - V_41 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_84 ( V_178 , V_12 -> V_24 . V_179 ) == 0 )
return - V_41 ;
if ( F_85 ( V_178 ) )
return - V_41 ;
V_21 = F_86 ( V_12 , V_178 , V_210 ) ;
if ( ! V_21 )
return - V_197 ;
F_87 ( V_21 , V_240 ) ;
F_87 ( V_21 , V_241 ) ;
V_13 = F_75 ( V_9 , V_21 , V_7 ) ;
if ( V_13 ) {
F_88 ( V_9 , V_21 ) ;
return V_13 ;
}
if ( ! F_48 ( V_21 , V_177 ) )
F_89 ( V_21 ) ;
V_266 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_267 ;
V_13 = F_90 ( V_21 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
if ( V_266 )
F_71 ( V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_178 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_178 )
return F_92 ( V_12 , V_178 ) ;
F_93 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_178 ,
struct V_233 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_32 * V_21 ;
struct V_11 * V_268 ;
F_19 ( & V_9 -> V_47 ) ;
V_21 = F_22 ( V_12 , V_178 ) ;
if ( ! V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_48 ;
}
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_251 &&
! F_48 ( V_21 , V_177 ) ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
V_268 = F_5 ( V_7 -> V_20 ) ;
if ( V_268 -> V_24 . type != V_18 &&
V_268 -> V_24 . type != V_267 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_41 ;
}
if ( V_7 -> V_20 -> V_183 -> V_19 ) {
if ( V_268 -> V_15 . V_20 . V_21 ) {
F_25 ( & V_9 -> V_47 ) ;
return - V_26 ;
}
F_60 ( V_268 -> V_15 . V_20 . V_21 , V_21 ) ;
}
V_21 -> V_12 = V_268 ;
F_71 ( V_21 ) ;
}
F_75 ( V_9 , V_21 , V_7 ) ;
if ( F_48 ( V_21 , V_177 ) && V_7 -> V_251 )
F_89 ( V_21 ) ;
F_25 ( & V_9 -> V_47 ) ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_238 & F_47 ( V_166 ) )
F_95 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_96 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_269 , T_3 * V_270 )
{
struct V_11 * V_12 ;
struct V_271 * V_272 ;
struct V_32 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_270 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_13 = F_97 ( V_269 , V_12 ) ;
if ( V_13 ) {
F_35 () ;
return V_13 ;
}
V_272 = F_98 ( V_269 , V_12 ) ;
if ( ! V_272 ) {
F_35 () ;
return - V_273 ;
}
F_99 ( V_272 , V_21 ) ;
F_35 () ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_269 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_269 )
return F_101 ( V_269 , V_12 ) ;
F_102 ( V_12 ) ;
return 0 ;
}
static int F_103 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 * V_269 , T_3 * V_270 )
{
struct V_11 * V_12 ;
struct V_271 * V_272 ;
struct V_32 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_21 = F_21 ( V_12 , V_270 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_48 ;
}
V_272 = F_98 ( V_269 , V_12 ) ;
if ( ! V_272 ) {
F_35 () ;
return - V_48 ;
}
F_99 ( V_272 , V_21 ) ;
F_35 () ;
return 0 ;
}
static void F_104 ( struct V_271 * V_272 , T_3 * V_270 ,
struct V_274 * V_275 )
{
struct V_32 * V_276 = F_32 ( V_272 -> V_270 ) ;
if ( V_276 )
memcpy ( V_270 , V_276 -> V_21 . V_179 , V_180 ) ;
else
memset ( V_270 , 0 , V_180 ) ;
V_275 -> V_90 = V_277 ;
V_275 -> V_92 = V_278 |
V_279 |
V_280 |
V_281 |
V_282 |
V_283 |
V_284 ;
V_275 -> V_285 = V_272 -> V_286 . V_287 ;
V_275 -> V_288 = V_272 -> V_288 ;
V_275 -> V_289 = V_272 -> V_289 ;
if ( F_105 ( V_111 , V_272 -> V_290 ) )
V_275 -> V_291 = F_43 ( V_272 -> V_290 - V_111 ) ;
V_275 -> V_292 =
F_43 ( V_272 -> V_292 ) ;
V_275 -> V_293 = V_272 -> V_293 ;
V_275 -> V_5 = 0 ;
if ( V_272 -> V_5 & V_294 )
V_275 -> V_5 |= V_295 ;
if ( V_272 -> V_5 & V_296 )
V_275 -> V_5 |= V_297 ;
if ( V_272 -> V_5 & V_298 )
V_275 -> V_5 |= V_299 ;
if ( V_272 -> V_5 & V_300 )
V_275 -> V_5 |= V_301 ;
if ( V_272 -> V_5 & V_296 )
V_275 -> V_5 |= V_297 ;
V_275 -> V_5 = V_272 -> V_5 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_269 , T_3 * V_270 , struct V_274 * V_275 )
{
struct V_11 * V_12 ;
struct V_271 * V_272 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_272 = F_98 ( V_269 , V_12 ) ;
if ( ! V_272 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_269 , V_272 -> V_269 , V_180 ) ;
F_104 ( V_272 , V_270 , V_275 ) ;
F_35 () ;
return 0 ;
}
static int F_107 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_74 , T_3 * V_269 , T_3 * V_270 ,
struct V_274 * V_275 )
{
struct V_11 * V_12 ;
struct V_271 * V_272 ;
V_12 = F_5 ( V_10 ) ;
F_31 () ;
V_272 = F_108 ( V_74 , V_12 ) ;
if ( ! V_272 ) {
F_35 () ;
return - V_48 ;
}
memcpy ( V_269 , V_272 -> V_269 , V_180 ) ;
F_104 ( V_272 , V_270 , V_275 ) ;
F_35 () ;
return 0 ;
}
static int F_109 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_302 * V_45 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_45 , & ( V_12 -> V_15 . V_257 . V_303 ) , sizeof( struct V_302 ) ) ;
return 0 ;
}
static inline bool F_110 ( enum V_304 V_305 , T_1 V_165 )
{
return ( V_165 >> ( V_305 - 1 ) ) & 0x1 ;
}
static int F_111 ( struct V_306 * V_307 ,
const struct V_308 * V_309 )
{
T_3 * V_310 ;
const T_3 * V_311 ;
struct V_11 * V_12 = F_112 ( V_307 ,
struct V_11 , V_15 . V_257 ) ;
V_310 = NULL ;
V_311 = V_307 -> V_312 ;
if ( V_309 -> V_313 ) {
V_310 = F_113 ( V_309 -> V_312 , V_309 -> V_313 ,
V_210 ) ;
if ( ! V_310 )
return - V_197 ;
}
V_307 -> V_313 = V_309 -> V_313 ;
V_307 -> V_312 = V_310 ;
F_66 ( V_311 ) ;
V_307 -> V_314 = V_309 -> V_314 ;
memcpy ( V_307 -> V_315 , V_309 -> V_315 , V_307 -> V_314 ) ;
V_307 -> V_316 = V_309 -> V_317 ;
V_307 -> V_318 = V_309 -> V_319 ;
V_307 -> V_258 = V_320 ;
if ( V_309 -> V_321 )
V_307 -> V_258 |= V_322 ;
if ( V_309 -> V_323 )
V_307 -> V_258 |= V_259 ;
memcpy ( V_12 -> V_24 . V_152 . V_324 , V_309 -> V_324 ,
sizeof( V_309 -> V_324 ) ) ;
return 0 ;
}
static int F_114 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_165 ,
const struct V_302 * V_325 )
{
struct V_302 * V_45 ;
struct V_11 * V_12 ;
struct V_306 * V_307 ;
V_12 = F_5 ( V_10 ) ;
V_307 = & V_12 -> V_15 . V_257 ;
V_45 = & ( V_12 -> V_15 . V_257 . V_303 ) ;
if ( F_110 ( V_326 , V_165 ) )
V_45 -> V_327 = V_325 -> V_327 ;
if ( F_110 ( V_328 , V_165 ) )
V_45 -> V_329 = V_325 -> V_329 ;
if ( F_110 ( V_330 , V_165 ) )
V_45 -> V_331 = V_325 -> V_331 ;
if ( F_110 ( V_332 , V_165 ) )
V_45 -> V_333 = V_325 -> V_333 ;
if ( F_110 ( V_334 , V_165 ) )
V_45 -> V_335 = V_325 -> V_335 ;
if ( F_110 ( V_336 , V_165 ) )
V_45 -> V_337 = V_325 -> V_337 ;
if ( F_110 ( V_338 , V_165 ) )
V_45 -> V_337 = V_325 -> V_339 ;
if ( F_110 ( V_340 , V_165 ) )
V_45 -> V_341 = V_325 -> V_341 ;
if ( F_110 ( V_342 , V_165 ) )
V_45 -> V_343 =
V_325 -> V_343 ;
if ( F_110 ( V_344 , V_165 ) )
V_45 -> V_345 = V_325 -> V_345 ;
if ( F_110 ( V_346 , V_165 ) )
V_45 -> V_347 = V_325 -> V_347 ;
if ( F_110 ( V_348 , V_165 ) )
V_45 -> V_349 =
V_325 -> V_349 ;
if ( F_110 ( V_350 , V_165 ) )
V_45 -> V_351 =
V_325 -> V_351 ;
if ( F_110 ( V_352 , V_165 ) )
V_45 -> V_353 =
V_325 -> V_353 ;
if ( F_110 ( V_354 ,
V_165 ) )
V_45 -> V_355 =
V_325 -> V_355 ;
if ( F_110 ( V_356 , V_165 ) ) {
V_45 -> V_357 = V_325 -> V_357 ;
F_115 ( V_307 ) ;
}
if ( F_110 ( V_358 , V_165 ) ) {
if ( V_325 -> V_359 &&
! V_45 -> V_357 ) {
V_45 -> V_357 = 1 ;
F_115 ( V_307 ) ;
}
V_45 -> V_359 =
V_325 -> V_359 ;
}
if ( F_110 ( V_360 , V_165 ) ) {
V_45 -> V_361 =
V_325 -> V_361 ;
}
return 0 ;
}
static int F_116 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_302 * V_45 ,
const struct V_308 * V_309 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_306 * V_307 = & V_12 -> V_15 . V_257 ;
int V_13 ;
memcpy ( & V_307 -> V_303 , V_45 , sizeof( struct V_302 ) ) ;
V_13 = F_111 ( V_307 , V_309 ) ;
if ( V_13 )
return V_13 ;
F_117 ( V_12 ) ;
return 0 ;
}
static int F_118 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_119 ( V_12 ) ;
return 0 ;
}
static int F_120 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_362 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_202 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_153 >= 0 ) {
V_12 -> V_24 . V_152 . V_153 = V_7 -> V_153 ;
V_202 |= V_363 ;
}
if ( V_7 -> V_155 >= 0 ) {
V_12 -> V_24 . V_152 . V_155 =
V_7 -> V_155 ;
V_202 |= V_364 ;
}
if ( ! V_12 -> V_24 . V_152 . V_157 &&
V_12 -> V_9 -> V_78 . V_45 . V_80 -> V_81 == V_365 ) {
V_12 -> V_24 . V_152 . V_157 = true ;
V_202 |= V_366 ;
}
if ( V_7 -> V_367 >= 0 ) {
V_12 -> V_24 . V_152 . V_157 =
V_7 -> V_367 ;
V_202 |= V_366 ;
}
if ( V_7 -> V_368 ) {
int V_235 , V_236 ;
T_1 V_234 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_76 * V_77 =
V_2 -> V_79 [ V_9 -> V_237 -> V_81 ] ;
for ( V_235 = 0 ; V_235 < V_7 -> V_369 ; V_235 ++ ) {
int V_73 = ( V_7 -> V_368 [ V_235 ] & 0x7f ) * 5 ;
for ( V_236 = 0 ; V_236 < V_77 -> V_253 ; V_236 ++ ) {
if ( V_77 -> V_83 [ V_236 ] . V_84 == V_73 )
V_234 |= F_47 ( V_236 ) ;
}
}
V_12 -> V_24 . V_152 . V_368 = V_234 ;
V_202 |= V_370 ;
}
if ( V_7 -> V_371 >= 0 ) {
if ( V_7 -> V_371 )
V_12 -> V_5 |= V_372 ;
else
V_12 -> V_5 &= ~ V_372 ;
}
if ( V_7 -> V_373 >= 0 ) {
V_12 -> V_24 . V_152 . V_374 =
( T_2 ) V_7 -> V_373 ;
V_202 |= V_375 ;
}
F_64 ( V_12 , V_202 ) ;
return 0 ;
}
static int F_121 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_376 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_377 V_378 ;
if ( ! V_9 -> V_379 -> V_380 )
return - V_381 ;
memset ( & V_378 , 0 , sizeof( V_378 ) ) ;
V_378 . V_382 = V_7 -> V_382 ;
V_378 . V_383 = V_7 -> V_384 ;
V_378 . V_385 = V_7 -> V_386 ;
V_378 . V_387 = V_7 -> V_387 ;
V_378 . V_388 = false ;
if ( V_7 -> V_389 >= V_9 -> V_78 . V_390 )
return - V_41 ;
V_12 -> V_391 [ V_7 -> V_389 ] = V_378 ;
if ( F_122 ( V_9 , V_12 , V_7 -> V_389 , & V_378 ) ) {
F_123 ( V_9 -> V_78 . V_2 ,
L_1 ,
V_7 -> V_389 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_124 ( struct V_2 * V_2 ,
struct V_1 * V_392 ,
struct V_393 * V_394 ,
enum V_395 V_396 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_393 * V_397 ;
enum V_395 V_398 ;
enum V_395 V_399 = V_400 ;
if ( V_392 )
V_12 = F_5 ( V_392 ) ;
switch ( F_125 ( V_9 , NULL ) ) {
case V_401 :
return - V_26 ;
case V_402 :
if ( V_9 -> V_237 != V_394 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_403 == V_396 )
return 0 ;
break;
case V_404 :
break;
}
if ( V_12 )
V_399 = V_12 -> V_24 . V_152 . V_396 ;
V_398 = V_9 -> V_403 ;
if ( ! F_126 ( V_9 , V_12 , V_396 ) )
return - V_26 ;
V_397 = V_9 -> V_237 ;
V_9 -> V_237 = V_394 ;
if ( ( V_397 != V_9 -> V_237 ) ||
( V_398 != V_9 -> V_403 ) )
F_127 ( V_9 , V_405 ) ;
if ( V_12 && V_12 -> V_24 . type != V_14 &&
V_399 != V_12 -> V_24 . V_152 . V_396 )
F_64 ( V_12 , V_375 ) ;
return 0 ;
}
static int F_128 ( struct V_2 * V_2 ,
struct V_406 * V_407 )
{
return F_129 ( F_2 ( V_2 ) , V_407 ) ;
}
static int F_130 ( struct V_2 * V_2 )
{
return F_131 ( F_2 ( V_2 ) ) ;
}
static int F_132 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_408 * V_409 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_133 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_410 :
case V_411 :
case V_412 :
break;
case V_413 :
if ( V_12 -> V_9 -> V_379 -> V_414 )
break;
case V_267 :
if ( V_12 -> V_15 . V_195 . V_203 )
return - V_381 ;
break;
default:
return - V_381 ;
}
return F_134 ( V_12 , V_409 ) ;
}
static int
F_135 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_415 * V_409 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_379 -> V_416 )
return - V_381 ;
return F_136 ( V_12 , V_409 ) ;
}
static int
F_137 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_379 -> V_417 )
return - V_381 ;
return F_138 ( V_12 ) ;
}
static int F_139 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_418 * V_409 )
{
return F_140 ( F_5 ( V_10 ) , V_409 ) ;
}
static int F_141 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_419 * V_409 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_125 ( V_9 , V_12 ) ) {
case V_401 :
return - V_26 ;
case V_402 :
if ( V_9 -> V_237 == V_409 -> V_420 -> V_80 )
break;
return - V_26 ;
case V_404 :
break;
}
return F_142 ( F_5 ( V_10 ) , V_409 ) ;
}
static int F_143 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_421 * V_409 ,
void * V_54 )
{
return F_144 ( F_5 ( V_10 ) ,
V_409 , V_54 ) ;
}
static int F_145 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_422 * V_409 ,
void * V_54 )
{
return F_146 ( F_5 ( V_10 ) ,
V_409 , V_54 ) ;
}
static int F_147 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_423 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_125 ( V_9 , V_12 ) ) {
case V_401 :
return - V_26 ;
case V_402 :
if ( ! V_7 -> V_424 )
return - V_26 ;
if ( V_9 -> V_237 == V_7 -> V_80 )
break;
return - V_26 ;
case V_404 :
break;
}
return F_148 ( V_12 , V_7 ) ;
}
static int F_149 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_150 ( V_12 ) ;
}
static int F_151 ( struct V_2 * V_2 , T_1 V_202 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_202 & V_425 ) {
V_13 = F_152 ( V_9 , V_2 -> V_426 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_202 & V_427 ) {
V_13 = F_153 ( V_9 , V_2 -> V_428 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_202 & V_429 ) {
V_13 = F_154 ( V_9 , V_2 -> V_430 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_202 & V_431 )
V_9 -> V_78 . V_45 . V_432 = V_2 -> V_433 ;
if ( V_202 & V_434 )
V_9 -> V_78 . V_45 . V_435 = V_2 -> V_436 ;
if ( V_202 &
( V_431 | V_434 ) )
F_127 ( V_9 , V_437 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 ,
enum V_438 type , int V_439 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_393 * V_394 = V_9 -> V_78 . V_45 . V_80 ;
T_1 V_440 = 0 ;
switch ( type ) {
case V_441 :
V_9 -> V_442 = - 1 ;
break;
case V_443 :
if ( V_439 < 0 || ( V_439 % 100 ) )
return - V_381 ;
V_9 -> V_442 = F_156 ( V_439 ) ;
break;
case V_444 :
if ( V_439 < 0 || ( V_439 % 100 ) )
return - V_381 ;
if ( F_156 ( V_439 ) > V_394 -> V_445 )
return - V_41 ;
V_9 -> V_442 = F_156 ( V_439 ) ;
break;
}
F_127 ( V_9 , V_440 ) ;
return 0 ;
}
static int F_157 ( struct V_2 * V_2 , int * V_446 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_446 = V_9 -> V_78 . V_45 . V_447 ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_179 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_448 . V_449 , V_179 , V_180 ) ;
return 0 ;
}
static void F_159 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_160 ( V_9 ) ;
}
static int F_161 ( struct V_2 * V_2 , void * V_450 , int V_226 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_379 -> V_451 )
return - V_381 ;
return V_9 -> V_379 -> V_451 ( & V_9 -> V_78 , V_450 , V_226 ) ;
}
static int F_162 ( struct V_2 * V_2 ,
struct V_192 * V_223 ,
struct V_452 * V_232 ,
void * V_450 , int V_226 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_379 -> V_453 )
return - V_381 ;
return V_9 -> V_379 -> V_453 ( & V_9 -> V_78 , V_223 , V_232 , V_450 , V_226 ) ;
}
int F_163 ( struct V_11 * V_12 ,
enum V_454 V_455 )
{
const T_3 * V_195 ;
enum V_454 V_456 ;
int V_13 ;
F_164 ( & V_12 -> V_15 . V_23 . V_457 ) ;
V_456 = V_12 -> V_15 . V_23 . V_458 ;
V_12 -> V_15 . V_23 . V_458 = V_455 ;
if ( V_456 == V_455 &&
V_455 != V_459 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_460 ||
V_12 -> V_24 . V_152 . V_396 == V_400 ) {
F_19 ( & V_12 -> V_9 -> V_461 ) ;
F_165 ( V_12 -> V_9 ) ;
F_25 ( & V_12 -> V_9 -> V_461 ) ;
return 0 ;
}
V_195 = V_12 -> V_15 . V_23 . V_460 -> V_462 ;
if ( V_455 == V_459 ) {
if ( V_12 -> V_15 . V_23 . V_463 )
V_455 = V_464 ;
else
V_455 = V_465 ;
}
V_13 = F_166 ( V_12 , V_455 ,
V_195 , V_195 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_458 = V_456 ;
return V_13 ;
}
static int F_167 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_466 , int V_467 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_52 ( V_10 -> V_183 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_381 ;
if ( ! ( V_9 -> V_78 . V_5 & V_468 ) )
return - V_381 ;
if ( V_466 == V_12 -> V_15 . V_23 . V_463 &&
V_467 == V_9 -> V_469 )
return 0 ;
V_12 -> V_15 . V_23 . V_463 = V_466 ;
V_9 -> V_469 = V_467 ;
F_19 ( & V_12 -> V_15 . V_23 . V_457 ) ;
F_163 ( V_12 , V_12 -> V_15 . V_23 . V_458 ) ;
F_25 ( & V_12 -> V_15 . V_23 . V_457 ) ;
if ( V_9 -> V_78 . V_5 & V_470 )
F_127 ( V_9 , V_471 ) ;
F_95 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_168 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_6 V_472 , T_1 V_473 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_52 ( V_10 -> V_183 ) ;
struct V_474 * V_24 = & V_12 -> V_24 ;
struct V_185 * V_152 = & V_24 -> V_152 ;
if ( V_472 == V_152 -> V_475 &&
V_473 == V_152 -> V_476 )
return 0 ;
V_152 -> V_475 = V_472 ;
V_152 -> V_476 = V_473 ;
if ( ! ( V_9 -> V_78 . V_5 & V_477 ) ) {
if ( V_12 -> V_24 . type != V_22 )
return - V_381 ;
return 0 ;
}
if ( V_12 -> V_15 . V_23 . V_460 )
F_64 ( V_12 , V_478 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_3 * V_179 ,
const struct V_479 * V_165 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_52 ( V_10 -> V_183 ) ;
int V_235 , V_17 ;
if ( V_9 -> V_78 . V_5 & V_480 ) {
V_17 = F_170 ( V_9 , V_12 , V_165 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_235 = 0 ; V_235 < V_481 ; V_235 ++ )
V_12 -> V_482 [ V_235 ] = V_165 -> V_229 [ V_235 ] . V_82 ;
return 0 ;
}
static int F_171 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_393 * V_394 ,
enum V_395 V_483 ,
unsigned int V_484 , T_4 * V_54 )
{
int V_17 ;
T_1 V_485 ;
F_164 ( & V_9 -> V_457 ) ;
if ( V_9 -> V_486 )
return - V_26 ;
V_485 = F_172 () | 1 ;
* V_54 = V_485 ;
V_9 -> V_487 = V_10 ;
V_9 -> V_486 = V_485 ;
V_9 -> V_488 = V_394 ;
V_9 -> V_489 = V_483 ;
V_9 -> V_490 = V_484 ;
V_17 = F_173 ( V_9 , V_394 , V_483 , V_484 ) ;
if ( V_17 ) {
V_9 -> V_488 = NULL ;
V_9 -> V_486 = 0 ;
}
return V_17 ;
}
static int F_174 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_393 * V_394 ,
enum V_395 V_396 ,
unsigned int V_484 ,
T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_379 -> V_491 ) {
int V_17 ;
F_19 ( & V_9 -> V_457 ) ;
V_17 = F_171 ( V_9 , V_10 ,
V_394 , V_396 ,
V_484 , V_54 ) ;
V_9 -> V_492 = false ;
F_25 ( & V_9 -> V_457 ) ;
return V_17 ;
}
return F_175 ( V_12 , V_394 , V_396 ,
V_484 , V_54 ) ;
}
static int F_176 ( struct V_8 * V_9 ,
T_4 V_54 )
{
int V_17 ;
F_164 ( & V_9 -> V_457 ) ;
if ( V_9 -> V_486 != V_54 )
return - V_48 ;
V_17 = F_177 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_486 = 0 ;
V_9 -> V_488 = NULL ;
F_178 ( V_9 ) ;
return 0 ;
}
static int F_179 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_379 -> V_493 ) {
int V_17 ;
F_19 ( & V_9 -> V_457 ) ;
V_17 = F_176 ( V_9 , V_54 ) ;
F_25 ( & V_9 -> V_457 ) ;
return V_17 ;
}
return F_180 ( V_12 , V_54 ) ;
}
static enum V_494
F_181 ( struct V_495 * V_496 , struct V_192 * V_223 )
{
if ( V_496 -> V_497 . V_498 && ! V_496 -> V_497 . V_499 )
F_182 ( V_496 -> V_12 -> V_10 ,
( unsigned long ) V_496 -> V_497 . V_500 ,
V_496 -> V_312 , V_496 -> V_313 , false , V_210 ) ;
return V_501 ;
}
static int F_183 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_393 * V_394 , bool V_502 ,
enum V_395 V_396 ,
bool V_503 , unsigned int V_498 ,
const T_3 * V_504 , T_5 V_226 , bool V_505 ,
bool V_506 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_192 * V_223 ;
struct V_32 * V_21 ;
struct V_495 * V_496 ;
const struct V_507 * V_508 = ( void * ) V_504 ;
T_1 V_5 ;
bool V_509 = false ;
if ( V_506 )
V_5 = V_510 ;
else
V_5 = V_511 |
V_512 ;
if ( V_394 != V_9 -> V_513 &&
V_394 != V_9 -> V_237 )
V_509 = true ;
if ( V_503 &&
( V_396 != V_9 -> V_514 &&
V_396 != V_9 -> V_403 ) )
V_509 = true ;
if ( V_394 == V_9 -> V_488 ) {
V_509 = false ;
V_5 |= V_515 ;
}
if ( V_505 )
V_5 |= V_516 ;
if ( V_509 && ! V_502 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_410 :
case V_267 :
case V_18 :
case V_413 :
case V_411 :
if ( ! F_184 ( V_508 -> V_517 ) ||
V_508 -> V_15 . V_518 . V_519 == V_520 )
break;
F_31 () ;
V_21 = F_21 ( V_12 , V_508 -> V_224 ) ;
F_35 () ;
if ( ! V_21 )
return - V_521 ;
break;
case V_22 :
case V_412 :
break;
default:
return - V_381 ;
}
V_223 = F_58 ( V_9 -> V_78 . V_522 + V_226 ) ;
if ( ! V_223 )
return - V_197 ;
F_185 ( V_223 , V_9 -> V_78 . V_522 ) ;
memcpy ( F_59 ( V_223 , V_226 ) , V_504 , V_226 ) ;
F_186 ( V_223 ) -> V_5 = V_5 ;
V_223 -> V_10 = V_12 -> V_10 ;
* V_54 = ( unsigned long ) V_223 ;
if ( V_509 && V_9 -> V_379 -> V_491 ) {
unsigned int V_484 ;
int V_17 ;
F_19 ( & V_9 -> V_457 ) ;
V_484 = 100 ;
if ( V_498 )
V_484 = V_498 ;
V_17 = F_171 ( V_9 , V_10 , V_394 ,
V_396 ,
V_484 , V_54 ) ;
if ( V_17 ) {
F_187 ( V_223 ) ;
F_25 ( & V_9 -> V_457 ) ;
return V_17 ;
}
V_9 -> V_492 = true ;
V_9 -> V_490 = V_498 ;
* V_54 ^= 2 ;
F_186 ( V_223 ) -> V_5 |= V_515 ;
V_9 -> V_523 = V_223 ;
V_9 -> V_524 = V_223 ;
F_25 ( & V_9 -> V_457 ) ;
return 0 ;
}
if ( ! V_509 && ! V_498 && ! V_12 -> V_24 . V_152 . V_525 ) {
F_188 ( V_12 , V_223 ) ;
return 0 ;
}
V_496 = F_65 ( sizeof( * V_496 ) + V_226 , V_210 ) ;
if ( ! V_496 ) {
F_187 ( V_223 ) ;
return - V_197 ;
}
V_496 -> type = V_526 ;
V_496 -> V_394 = V_394 ;
V_496 -> V_527 = V_396 ;
V_496 -> V_12 = V_12 ;
V_496 -> V_528 = F_181 ;
V_496 -> V_497 . V_500 = V_223 ;
V_496 -> V_497 . V_498 = V_498 ;
V_496 -> V_313 = V_226 ;
memcpy ( V_496 -> V_312 , V_504 , V_226 ) ;
F_189 ( V_496 ) ;
return 0 ;
}
static int F_190 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_495 * V_496 ;
int V_17 = - V_48 ;
F_19 ( & V_9 -> V_457 ) ;
if ( V_9 -> V_379 -> V_493 ) {
V_54 ^= 2 ;
V_17 = F_176 ( V_9 , V_54 ) ;
if ( V_17 == 0 ) {
F_187 ( V_9 -> V_523 ) ;
V_9 -> V_523 = NULL ;
V_9 -> V_524 = NULL ;
}
F_25 ( & V_9 -> V_457 ) ;
return V_17 ;
}
F_68 (wk, &local->work_list, list) {
if ( V_496 -> V_12 != V_12 )
continue;
if ( V_496 -> type != V_526 )
continue;
if ( V_54 != ( unsigned long ) V_496 -> V_497 . V_500 )
continue;
V_496 -> V_467 = V_111 ;
F_191 ( & V_9 -> V_78 , & V_9 -> V_529 ) ;
V_17 = 0 ;
break;
}
F_25 ( & V_9 -> V_457 ) ;
return V_17 ;
}
static void F_192 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_530 , bool V_531 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_530 != ( V_532 | V_533 ) )
return;
if ( V_531 )
V_9 -> V_534 ++ ;
else
V_9 -> V_534 -- ;
F_191 ( & V_9 -> V_78 , & V_9 -> V_535 ) ;
}
static int F_193 ( struct V_2 * V_2 , T_1 V_536 , T_1 V_537 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_538 )
return - V_381 ;
return F_194 ( V_9 , V_536 , V_537 ) ;
}
static int F_195 ( struct V_2 * V_2 , T_1 * V_536 , T_1 * V_537 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_196 ( V_9 , V_536 , V_537 ) ;
}
static int F_197 ( struct V_2 * V_2 , T_1 V_61 , T_1 V_539 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_198 ( V_9 , V_61 , V_539 ) ;
}
static void F_199 ( struct V_2 * V_2 ,
T_1 * V_61 , T_1 * V_540 , T_1 * V_539 , T_1 * V_541 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_200 ( V_9 , V_61 , V_540 , V_539 , V_541 ) ;
}
static int F_201 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_542 * V_450 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_379 -> V_543 )
return - V_381 ;
F_202 ( V_9 , V_12 , V_450 ) ;
return 0 ;
}
static void F_203 ( struct V_192 * V_223 )
{
T_3 * V_544 = ( void * ) F_59 ( V_223 , 7 ) ;
* V_544 ++ = V_545 ;
* V_544 ++ = 5 ;
* V_544 ++ = 0x0 ;
* V_544 ++ = 0x0 ;
* V_544 ++ = 0x0 ;
* V_544 ++ = 0x0 ;
* V_544 ++ = V_546 ;
}
static T_2 F_204 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_2 V_547 ;
V_547 = 0 ;
if ( V_9 -> V_237 -> V_81 != V_548 )
return V_547 ;
if ( ! ( V_9 -> V_78 . V_5 & V_549 ) )
V_547 |= V_550 ;
if ( ! ( V_9 -> V_78 . V_5 & V_551 ) )
V_547 |= V_552 ;
return V_547 ;
}
static void F_205 ( struct V_192 * V_223 , T_3 * V_553 ,
T_3 * V_554 , T_3 * V_462 )
{
struct V_555 * V_556 ;
V_556 = ( void * ) F_59 ( V_223 , sizeof( struct V_555 ) ) ;
V_556 -> V_557 = V_558 ;
V_556 -> V_313 = sizeof( struct V_555 ) - 2 ;
memcpy ( V_556 -> V_462 , V_462 , V_180 ) ;
memcpy ( V_556 -> V_559 , V_553 , V_180 ) ;
memcpy ( V_556 -> V_560 , V_554 , V_180 ) ;
}
static int
F_206 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_554 , T_3 V_561 , T_3 V_562 ,
T_2 V_563 , struct V_192 * V_223 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_564 * V_565 ;
V_565 = ( void * ) F_59 ( V_223 , F_207 ( struct V_564 , V_15 ) ) ;
memcpy ( V_565 -> V_224 , V_554 , V_180 ) ;
memcpy ( V_565 -> V_225 , V_12 -> V_24 . V_179 , V_180 ) ;
V_565 -> V_566 = F_208 ( V_567 ) ;
V_565 -> V_568 = V_569 ;
switch ( V_561 ) {
case V_570 :
V_565 -> V_519 = V_571 ;
V_565 -> V_561 = V_570 ;
F_59 ( V_223 , sizeof( V_565 -> V_15 . V_572 ) ) ;
V_565 -> V_15 . V_572 . V_562 = V_562 ;
V_565 -> V_15 . V_572 . V_573 =
F_209 ( F_204 ( V_12 ) ) ;
F_210 ( & V_12 -> V_24 , V_223 ) ;
F_211 ( & V_12 -> V_24 , V_223 ) ;
F_203 ( V_223 ) ;
break;
case V_574 :
V_565 -> V_519 = V_571 ;
V_565 -> V_561 = V_574 ;
F_59 ( V_223 , sizeof( V_565 -> V_15 . V_575 ) ) ;
V_565 -> V_15 . V_575 . V_563 = F_209 ( V_563 ) ;
V_565 -> V_15 . V_575 . V_562 = V_562 ;
V_565 -> V_15 . V_575 . V_573 =
F_209 ( F_204 ( V_12 ) ) ;
F_210 ( & V_12 -> V_24 , V_223 ) ;
F_211 ( & V_12 -> V_24 , V_223 ) ;
F_203 ( V_223 ) ;
break;
case V_576 :
V_565 -> V_519 = V_571 ;
V_565 -> V_561 = V_576 ;
F_59 ( V_223 , sizeof( V_565 -> V_15 . V_577 ) ) ;
V_565 -> V_15 . V_577 . V_563 = F_209 ( V_563 ) ;
V_565 -> V_15 . V_577 . V_562 = V_562 ;
break;
case V_578 :
V_565 -> V_519 = V_571 ;
V_565 -> V_561 = V_578 ;
F_59 ( V_223 , sizeof( V_565 -> V_15 . V_579 ) ) ;
V_565 -> V_15 . V_579 . V_580 = F_209 ( V_563 ) ;
break;
case V_581 :
V_565 -> V_519 = V_571 ;
V_565 -> V_561 = V_581 ;
F_59 ( V_223 , sizeof( V_565 -> V_15 . V_582 ) ) ;
V_565 -> V_15 . V_582 . V_562 = V_562 ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int
F_212 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_554 , T_3 V_561 , T_3 V_562 ,
T_2 V_563 , struct V_192 * V_223 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_507 * V_508 ;
V_508 = ( void * ) F_59 ( V_223 , 24 ) ;
memset ( V_508 , 0 , 24 ) ;
memcpy ( V_508 -> V_224 , V_554 , V_180 ) ;
memcpy ( V_508 -> V_225 , V_12 -> V_24 . V_179 , V_180 ) ;
memcpy ( V_508 -> V_462 , V_12 -> V_15 . V_23 . V_462 , V_180 ) ;
V_508 -> V_517 = F_209 ( V_532 |
V_583 ) ;
switch ( V_561 ) {
case V_584 :
F_59 ( V_223 , 1 + sizeof( V_508 -> V_15 . V_518 . V_15 . V_585 ) ) ;
V_508 -> V_15 . V_518 . V_519 = V_520 ;
V_508 -> V_15 . V_518 . V_15 . V_585 . V_561 =
V_584 ;
V_508 -> V_15 . V_518 . V_15 . V_585 . V_562 =
V_562 ;
V_508 -> V_15 . V_518 . V_15 . V_585 . V_573 =
F_209 ( F_204 ( V_12 ) ) ;
F_210 ( & V_12 -> V_24 , V_223 ) ;
F_211 ( & V_12 -> V_24 , V_223 ) ;
F_203 ( V_223 ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_213 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_554 , T_3 V_561 , T_3 V_562 ,
T_2 V_563 , const T_3 * V_586 ,
T_5 V_587 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_588 * V_589 ;
struct V_192 * V_223 = NULL ;
bool V_590 ;
int V_17 ;
if ( ! ( V_2 -> V_5 & V_591 ) )
return - V_592 ;
if ( V_12 -> V_24 . type != V_22 ||
! V_12 -> V_15 . V_23 . V_460 )
return - V_41 ;
#ifdef F_214
F_215 ( V_593 L_2 , V_561 , V_554 ) ;
#endif
V_223 = F_58 ( V_9 -> V_78 . V_522 +
F_216 ( sizeof( struct V_507 ) ,
sizeof( struct V_564 ) ) +
50 +
7 +
V_587 +
sizeof( struct V_555 ) ) ;
if ( ! V_223 )
return - V_197 ;
V_589 = F_186 ( V_223 ) ;
F_185 ( V_223 , V_9 -> V_78 . V_522 ) ;
switch ( V_561 ) {
case V_570 :
case V_574 :
case V_576 :
case V_578 :
case V_581 :
V_17 = F_206 ( V_2 , V_10 , V_554 ,
V_561 , V_562 ,
V_563 , V_223 ) ;
V_590 = false ;
break;
case V_584 :
V_17 = F_212 ( V_2 , V_10 , V_554 , V_561 ,
V_562 , V_563 ,
V_223 ) ;
V_590 = true ;
break;
default:
V_17 = - V_592 ;
break;
}
if ( V_17 < 0 )
goto V_594;
if ( V_587 )
memcpy ( F_59 ( V_223 , V_587 ) , V_586 , V_587 ) ;
switch ( V_561 ) {
case V_570 :
case V_576 :
case V_578 :
case V_581 :
F_205 ( V_223 , V_12 -> V_24 . V_179 , V_554 ,
V_12 -> V_15 . V_23 . V_462 ) ;
break;
case V_574 :
case V_584 :
F_205 ( V_223 , V_554 , V_12 -> V_24 . V_179 ,
V_12 -> V_15 . V_23 . V_462 ) ;
break;
default:
V_17 = - V_592 ;
goto V_594;
}
if ( V_590 ) {
F_188 ( V_12 , V_223 ) ;
return 0 ;
}
switch ( V_561 ) {
case V_570 :
case V_574 :
F_217 ( V_223 , V_595 ) ;
V_223 -> V_596 = 2 ;
break;
default:
F_217 ( V_223 , V_597 ) ;
V_223 -> V_596 = 5 ;
break;
}
F_218 () ;
V_17 = F_219 ( V_223 , V_10 ) ;
F_220 () ;
return V_17 ;
V_594:
F_62 ( V_223 ) ;
return V_17 ;
}
static int F_221 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_3 * V_554 , enum V_598 V_599 )
{
struct V_32 * V_21 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! ( V_2 -> V_5 & V_591 ) )
return - V_592 ;
if ( V_12 -> V_24 . type != V_22 )
return - V_41 ;
#ifdef F_214
F_215 ( V_593 L_3 , V_599 , V_554 ) ;
#endif
switch ( V_599 ) {
case V_600 :
F_31 () ;
V_21 = F_21 ( V_12 , V_554 ) ;
if ( ! V_21 ) {
F_35 () ;
return - V_521 ;
}
F_78 ( V_21 , V_601 ) ;
F_35 () ;
break;
case V_602 :
return F_222 ( V_12 , V_554 ) ;
case V_603 :
case V_604 :
case V_605 :
return - V_592 ;
default:
return - V_592 ;
}
return 0 ;
}
static int F_223 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_3 * V_554 , T_4 * V_54 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_606 * V_607 ;
struct V_192 * V_223 ;
int V_201 = sizeof( * V_607 ) ;
T_7 V_608 ;
bool V_609 ;
struct V_588 * V_589 ;
struct V_32 * V_21 ;
F_31 () ;
V_21 = F_21 ( V_12 , V_554 ) ;
if ( V_21 ) {
V_609 = F_48 ( V_21 , V_174 ) ;
F_35 () ;
} else {
F_35 () ;
return - V_521 ;
}
if ( V_609 ) {
V_608 = F_209 ( V_610 |
V_611 |
V_612 ) ;
} else {
V_201 -= 2 ;
V_608 = F_209 ( V_610 |
V_613 |
V_612 ) ;
}
V_223 = F_58 ( V_9 -> V_78 . V_522 + V_201 ) ;
if ( ! V_223 )
return - V_197 ;
V_223 -> V_10 = V_10 ;
F_185 ( V_223 , V_9 -> V_78 . V_522 ) ;
V_607 = ( void * ) F_59 ( V_223 , V_201 ) ;
V_607 -> V_517 = V_608 ;
V_607 -> V_614 = 0 ;
memcpy ( V_607 -> V_615 , V_21 -> V_21 . V_179 , V_180 ) ;
memcpy ( V_607 -> V_616 , V_12 -> V_24 . V_179 , V_180 ) ;
memcpy ( V_607 -> V_617 , V_12 -> V_24 . V_179 , V_180 ) ;
V_607 -> V_618 = 0 ;
V_589 = F_186 ( V_223 ) ;
V_589 -> V_5 |= V_512 |
V_511 ;
F_217 ( V_223 , V_619 ) ;
V_223 -> V_596 = 7 ;
if ( V_609 )
V_607 -> V_620 = F_209 ( 7 ) ;
F_218 () ;
F_224 ( V_12 , V_223 ) ;
F_220 () ;
* V_54 = ( unsigned long ) V_223 ;
return 0 ;
}
static struct V_393 *
F_225 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return V_9 -> V_237 ;
}
