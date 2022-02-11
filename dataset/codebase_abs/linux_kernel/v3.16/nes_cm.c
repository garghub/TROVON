int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_3 , V_2 ) ;
}
static struct V_4 * F_5 ( struct V_1 * V_2 ,
enum V_5 type )
{
struct V_4 * V_6 ;
if ( ! V_2 -> V_7 )
return NULL ;
V_6 = F_6 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> type = type ;
V_6 -> V_2 = V_2 ;
V_6 -> V_9 . V_10 = V_2 -> V_10 ;
V_6 -> V_9 . V_11 = V_2 -> V_11 ;
V_6 -> V_9 . V_12 = V_2 -> V_12 ;
V_6 -> V_9 . V_13 = V_2 -> V_13 ;
V_6 -> V_9 . V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_1
L_2 ,
V_2 , V_6 , type , V_6 -> V_9 . V_11 ,
V_6 -> V_9 . V_13 , V_6 -> V_9 . V_10 ,
V_6 -> V_9 . V_12 ) ;
F_8 ( V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
if ( ! V_16 ) {
F_7 ( V_14 , L_3 ) ;
return - 1 ;
}
F_10 ( V_2 , V_19 , & V_20 , NULL , V_21 ) ;
F_11 ( V_16 , V_2 , NULL , 0 , * V_19 , V_20 , V_22 ) ;
return F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = NULL ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_24 * V_25 ;
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_10 ( V_2 , V_19 , & V_20 , NULL , V_28 ) ;
V_25 = (struct V_24 * ) * V_19 ;
V_25 -> V_29 |= V_30 ;
F_11 ( V_16 , V_2 , NULL , 0 , * V_19 , V_20 , V_22 | V_31 ) ;
V_2 -> V_32 = V_33 ;
return F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_34 , T_3 * type ,
T_3 V_35 )
{
struct V_24 * V_25 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 ;
int V_41 ;
* type = V_42 ;
if ( V_35 < sizeof( struct V_24 ) ) {
F_7 ( V_14 , L_5 , V_35 ) ;
return - V_43 ;
}
V_25 = (struct V_24 * ) V_34 ;
V_40 = sizeof( struct V_24 ) ;
V_41 = F_16 ( V_25 -> V_41 ) ;
if ( V_41 > V_44 ) {
F_7 ( V_14 , L_6
L_7 ) ;
return - V_43 ;
}
if ( V_25 -> V_45 != V_46 && V_25 -> V_45 != V_47 ) {
F_7 ( V_14 , L_8
L_9 ) ;
return - V_43 ;
}
if ( V_25 -> V_45 > V_2 -> V_48 ) {
F_7 ( V_14 , L_8
L_10 ) ;
return - V_43 ;
} else {
V_2 -> V_48 = V_25 -> V_45 ;
}
if ( V_2 -> V_32 != V_49 ) {
if ( memcmp ( V_25 -> V_50 , V_51 , V_52 ) ) {
F_7 ( V_14 , L_11 ) ;
return - V_43 ;
}
} else {
if ( memcmp ( V_25 -> V_50 , V_53 , V_52 ) ) {
F_7 ( V_14 , L_11 ) ;
return - V_43 ;
}
}
if ( V_41 + V_40 != V_35 ) {
F_7 ( V_14 , L_12
L_13 ,
V_41 , V_40 , V_35 ) ;
return - V_43 ;
}
if ( V_35 > V_26 ) {
F_7 ( V_14 , L_14
L_15 ,
V_41 , V_40 , V_35 ) ;
return - V_43 ;
}
V_2 -> V_54 = V_41 ;
switch ( V_25 -> V_45 ) {
case V_47 : {
T_2 V_55 ;
T_2 V_56 ;
T_2 V_57 ;
T_2 V_58 ;
V_37 = (struct V_36 * ) V_34 ;
V_40 += V_59 ;
V_2 -> V_54 -= V_59 ;
V_39 = & V_37 -> V_39 ;
V_57 = F_16 ( V_39 -> V_60 ) ;
V_58 = F_16 ( V_39 -> V_61 ) ;
V_55 = V_57 & V_62 ;
V_56 = V_58 & V_62 ;
if ( ! ( V_57 & V_63 ) ) {
return - V_43 ;
}
if ( V_55 == V_62 || V_56 == V_62 )
V_2 -> V_64 = V_62 ;
if ( V_2 -> V_64 != V_62 ) {
if ( V_2 -> V_32 != V_49 ) {
if ( V_56 > V_65 ) {
V_2 -> V_55 = V_65 ;
} else {
V_2 -> V_55 = V_56 ;
if ( V_56 == 0 &&
( V_58 & V_66 ) ) {
V_2 -> V_55 = 1 ;
F_7 ( V_14 ,
L_16 ,
V_67 , V_56 ) ;
}
}
if ( V_55 > V_68 )
V_2 -> V_56 = V_68 ;
else
V_2 -> V_56 = V_55 ;
} else {
if ( V_56 > V_65 ) {
F_7 ( V_14 ,
L_17 ,
V_67 , V_56 ) ;
return - V_43 ;
}
V_2 -> V_55 = V_56 ;
if ( V_55 > V_68 ) {
V_2 -> V_56 = V_68 ;
} else {
if ( V_55 == 0 &&
( V_58 & V_66 ) ) {
F_7 ( V_14 ,
L_18 ,
V_67 , V_55 ) ;
return - V_43 ;
} else {
V_2 -> V_56 = V_55 ;
}
}
}
}
if ( V_58 & V_66 ) {
V_2 -> V_69 = V_70 ;
} else if ( V_58 & V_71 ) {
V_2 -> V_69 = V_72 ;
} else {
return - V_43 ;
}
break;
}
case V_46 :
default:
break;
}
memcpy ( V_2 -> V_73 , V_34 + V_40 , V_2 -> V_54 ) ;
if ( V_25 -> V_29 & V_30 )
* type = V_74 ;
return 0 ;
}
static void F_11 ( struct V_15 * V_16 ,
struct V_1 * V_2 , void * V_75 , T_3 V_76 ,
void * V_77 , T_3 V_78 , T_1 V_29 )
{
struct V_79 * V_80 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
T_1 * V_85 ;
T_2 V_86 = sizeof( * V_82 ) ;
V_86 += sizeof( * V_80 ) ;
V_86 += V_76 + V_78 ;
F_17 ( V_16 , 0 ) ;
memset ( V_16 -> V_77 , 0x00 , V_87 + sizeof( * V_82 ) + sizeof( * V_80 ) ) ;
V_85 = F_18 ( V_16 , V_86 + V_87 ) ;
V_84 = (struct V_83 * ) V_85 ;
V_85 += V_87 ;
V_82 = (struct V_81 * ) V_85 ;
V_85 += sizeof( * V_82 ) ;
V_80 = (struct V_79 * ) V_85 ;
F_19 ( V_16 ) ;
F_20 ( V_16 , V_87 ) ;
F_21 ( V_16 , V_87 + sizeof( * V_82 ) ) ;
V_85 += sizeof( * V_80 ) ;
V_16 -> V_88 = V_89 ;
if ( ! ( V_2 -> V_90 -> V_91 & V_92 ) )
V_16 -> V_88 = V_93 ;
V_16 -> V_94 = F_22 ( 0x800 ) ;
V_16 -> V_95 = 0 ;
V_16 -> V_96 = V_87 ;
memcpy ( V_84 -> V_97 , V_2 -> V_98 , V_99 ) ;
memcpy ( V_84 -> V_100 , V_2 -> V_101 , V_99 ) ;
V_84 -> V_102 = F_22 ( 0x0800 ) ;
V_82 -> V_103 = V_104 ;
V_82 -> V_105 = 5 ;
V_82 -> V_106 = 0 ;
V_82 -> V_107 = F_22 ( V_86 ) ;
V_82 -> V_108 = F_22 ( ++ V_2 -> V_109 . V_110 ) ;
V_82 -> V_111 = F_22 ( 0x4000 ) ;
V_82 -> V_112 = 0x40 ;
V_82 -> V_94 = 0x06 ;
V_82 -> V_113 = F_23 ( V_2 -> V_114 ) ;
V_82 -> V_115 = F_23 ( V_2 -> V_116 ) ;
V_80 -> V_117 = F_22 ( V_2 -> V_118 ) ;
V_80 -> V_119 = F_22 ( V_2 -> V_120 ) ;
V_80 -> V_121 = F_23 ( V_2 -> V_109 . V_122 ) ;
if ( V_29 & V_22 ) {
V_2 -> V_109 . V_123 = V_2 -> V_109 . V_124 ;
V_80 -> V_125 = F_23 ( V_2 -> V_109 . V_123 ) ;
V_80 -> V_126 = 1 ;
} else {
V_80 -> V_125 = 0 ;
}
if ( V_29 & V_127 ) {
V_2 -> V_109 . V_122 ++ ;
V_80 -> V_128 = 1 ;
} else {
V_2 -> V_109 . V_122 += V_78 ;
}
if ( V_29 & V_31 ) {
V_2 -> V_109 . V_122 ++ ;
V_80 -> V_129 = 1 ;
}
if ( V_29 & V_130 )
V_80 -> V_131 = 1 ;
V_80 -> V_132 = ( T_2 ) ( ( sizeof( * V_80 ) + V_76 + 3 ) >> 2 ) ;
V_80 -> V_133 = F_22 ( V_2 -> V_109 . V_134 ) ;
V_80 -> V_135 = 0 ;
if ( V_76 )
memcpy ( V_85 , V_75 , V_76 ) ;
V_85 += V_76 ;
if ( V_78 )
memcpy ( V_85 , V_77 , V_78 ) ;
F_24 ( V_16 ) -> V_136 = 0 ;
V_137 ++ ;
}
static void F_25 ( T_4 V_138 , T_5 V_139 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_141 ;
V_143 -> V_144 = V_145 ;
memcpy ( & V_143 -> V_146 . V_147 , & V_138 , sizeof( T_4 ) ) ;
V_143 -> V_148 = V_139 ;
}
static int F_26 ( struct V_149 * V_9 )
{
struct V_140 V_150 ;
struct V_140 V_151 ;
F_25 ( F_23 ( V_9 -> V_11 ) , F_22 ( V_9 -> V_13 ) ,
& V_150 ) ;
F_25 ( F_23 ( V_9 -> V_114 ) ,
F_22 ( V_9 -> V_118 ) , & V_151 ) ;
return F_27 ( & V_150 ,
& V_151 , V_152 ) ;
}
static int F_28 ( T_3 V_11 , T_2 V_13 ,
T_3 V_114 , T_2 V_118 )
{
struct V_140 V_150 ;
struct V_140 V_151 ;
F_25 ( F_23 ( V_11 ) , F_22 ( V_13 ) , & V_150 ) ;
F_25 ( F_23 ( V_114 ) , F_22 ( V_118 ) ,
& V_151 ) ;
F_29 ( & V_150 , & V_151 ) ;
return F_30 ( & V_150 , V_152 ) ;
}
static void F_31 ( struct V_149 * V_9 ,
struct V_153 * V_154 )
{
F_25 ( F_23 ( V_9 -> V_11 ) , F_22 ( V_9 -> V_13 ) ,
& V_154 -> V_11 ) ;
F_25 ( F_23 ( V_9 -> V_10 ) , F_22 ( V_9 -> V_12 ) ,
& V_154 -> V_10 ) ;
}
static void F_32 ( struct V_155 * V_156 ,
struct V_157 * V_154 )
{
memcpy ( V_154 -> V_158 , V_156 -> V_159 -> V_160 . V_161 ,
V_162 ) ;
memcpy ( V_154 -> V_163 , V_156 -> V_90 -> V_161 , V_164 ) ;
}
static void F_33 ( struct V_149 * V_9 ,
struct V_153 * V_154 )
{
struct V_142 * V_114 =
(struct V_142 * ) & V_154 -> V_114 ;
struct V_142 * V_116 =
(struct V_142 * ) & V_154 -> V_116 ;
if ( V_114 -> V_144 == V_145 ) {
V_9 -> V_114 =
F_34 ( V_114 -> V_146 . V_147 ) ;
V_9 -> V_118 = F_16 ( V_114 -> V_148 ) ;
}
if ( V_116 -> V_144 == V_145 ) {
V_9 -> V_116 =
F_34 ( V_116 -> V_146 . V_147 ) ;
V_9 -> V_120 = F_16 ( V_116 -> V_148 ) ;
}
}
static void F_35 ( struct V_165 * V_166 )
{
F_7 ( V_14 , L_19 ) ;
F_7 ( V_14 , L_20 , V_166 ) ;
if ( ! V_166 )
return;
F_7 ( V_14 , L_19 ) ;
F_7 ( V_14 , L_21 , V_166 -> V_32 ) ;
F_7 ( V_14 , L_22 , F_36 ( & V_166 -> V_167 ) ) ;
F_7 ( V_14 , L_23 , F_36 ( & V_166 -> V_168 ) ) ;
F_7 ( V_14 , L_24 , V_166 ) ;
F_7 ( V_14 , L_25 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
T_2 V_169 , T_2 V_170 )
{
if ( V_169 > V_65 )
V_169 = V_65 ;
if ( V_170 > V_68 )
V_170 = V_68 ;
V_2 -> V_55 = V_169 ;
V_2 -> V_56 = V_170 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * * V_19 ,
T_2 * V_20 , T_1 * V_171 , T_1 V_172 )
{
int V_173 = 0 ;
* V_19 = ( V_171 ) ? V_171 : & V_2 -> V_73 [ 0 ] ;
switch ( V_2 -> V_48 ) {
case V_46 :
* V_19 = ( T_1 * ) * V_19 + sizeof( struct V_38 ) ;
* V_20 = sizeof( struct V_24 ) + V_2 -> V_54 ;
F_38 ( V_2 , * V_19 , V_172 ) ;
break;
case V_47 :
* V_20 = sizeof( struct V_36 ) + V_2 -> V_54 ;
F_39 ( V_2 , * V_19 , V_172 ) ;
break;
default:
V_173 = - V_43 ;
}
return V_173 ;
}
static void F_39 ( struct V_1 * V_2 ,
void * V_17 , T_1 V_172 )
{
struct V_36 * V_25 = (struct V_36 * ) V_17 ;
struct V_38 * V_39 = & V_25 -> V_39 ;
T_2 V_60 ;
T_2 V_61 ;
F_38 ( V_2 , V_17 , V_172 ) ;
V_25 -> V_29 |= V_174 ;
V_25 -> V_41 += F_22 ( V_59 ) ;
if ( V_2 -> V_64 == V_62 ) {
V_60 = V_62 ;
V_61 = V_62 ;
} else {
V_60 = V_2 -> V_55 & V_62 ;
V_61 = V_2 -> V_56 & V_62 ;
}
V_60 |= V_63 ;
V_60 |= V_175 ;
switch ( V_172 ) {
case V_21 :
V_61 |= V_71 ;
V_61 |= V_66 ;
break;
case V_28 :
switch ( V_2 -> V_69 ) {
case V_72 :
V_61 |= V_71 ;
break;
case V_70 :
V_61 |= V_66 ;
break;
}
}
V_39 -> V_60 = F_22 ( V_60 ) ;
V_39 -> V_61 = F_22 ( V_61 ) ;
}
static void F_38 ( struct V_1 * V_2 , void * V_17 , T_1 V_172 )
{
struct V_24 * V_25 = (struct V_24 * ) V_17 ;
switch ( V_172 ) {
case V_21 :
memcpy ( V_25 -> V_50 , V_51 , V_52 ) ;
break;
case V_28 :
memcpy ( V_25 -> V_50 , V_53 , V_52 ) ;
break;
}
V_25 -> V_29 = V_176 ;
V_25 -> V_45 = V_2 -> V_48 ;
V_25 -> V_41 = F_22 ( V_2 -> V_54 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_177 * * V_178 )
{
T_6 V_179 ;
struct V_177 * V_180 = * V_178 ;
struct V_181 * V_182 = & V_180 -> V_183 . V_184 [ 0 ] ;
V_179 = ( unsigned long ) V_180 -> V_185 ;
V_179 |= V_186 >> 1 ;
F_41 ( V_182 -> V_187 , V_188 , V_179 ) ;
V_182 -> V_187 [ V_189 ] = 0 ;
V_182 -> V_187 [ V_190 ] = 0 ;
switch ( V_2 -> V_69 ) {
case V_72 :
F_7 ( V_14 , L_26 ) ;
V_182 -> V_187 [ V_191 ] =
F_42 ( V_192 ) ;
V_182 -> V_187 [ V_193 ] = 0 ;
V_182 -> V_187 [ V_194 ] = 0 ;
V_182 -> V_187 [ V_195 ] = 0 ;
break;
case V_70 :
default:
if ( V_2 -> V_69 != V_70 )
F_43 ( 1 , L_27 ,
V_2 -> V_69 ) ;
F_7 ( V_14 , L_28 ) ;
V_182 -> V_187 [ V_191 ] =
F_42 ( V_196 ) ;
V_182 -> V_187 [ V_197 ] = 1 ;
V_182 -> V_187 [ V_198 ] = 0 ;
V_182 -> V_187 [ V_199 ] = 0 ;
V_182 -> V_187 [ V_200 ] = 1 ;
V_182 -> V_187 [ V_195 ] = 1 ;
break;
}
if ( V_180 -> V_201 ) {
V_180 -> V_201 = 0 ;
F_44 ( V_180 -> V_202 ) ;
}
V_180 -> V_203 -> V_204 &= F_42 ( ~ ( V_205 |
V_206 |
V_207 ) ) ;
V_180 -> V_208 = 1 ;
V_180 -> V_183 . V_209 = 0 ;
}
int F_12 ( struct V_1 * V_2 , struct V_15 * V_16 ,
enum V_210 type , int V_211 ,
int V_212 )
{
unsigned long V_29 ;
struct V_165 * V_3 = V_2 -> V_3 ;
struct V_213 * V_214 ;
int V_173 = 0 ;
V_214 = F_6 ( sizeof( * V_214 ) , V_8 ) ;
if ( ! V_214 )
return - V_27 ;
V_214 -> V_215 = V_216 ;
V_214 -> V_217 = V_218 ;
V_214 -> V_16 = V_16 ;
V_214 -> V_219 = V_220 ;
V_214 -> type = type ;
V_214 -> V_90 = V_2 -> V_90 ;
V_214 -> V_211 = V_211 ;
V_214 -> V_212 = V_212 ;
if ( type == V_221 ) {
V_214 -> V_219 += ( V_222 / 10 ) ;
if ( V_2 -> V_223 ) {
F_45 ( V_214 ) ;
F_46 ( 1 ) ;
return - V_43 ;
}
V_2 -> V_223 = V_214 ;
}
if ( type == V_23 ) {
V_214 -> V_224 = F_34 ( F_47 ( V_16 ) -> V_121 ) ;
F_48 ( & V_214 -> V_16 -> V_225 ) ;
F_49 ( & V_2 -> V_226 , V_29 ) ;
V_2 -> V_227 = V_214 ;
F_2 ( V_2 ) ;
F_50 ( & V_2 -> V_226 , V_29 ) ;
V_214 -> V_219 = V_220 + V_228 ;
V_173 = F_51 ( V_214 -> V_16 , V_2 -> V_90 ) ;
if ( V_173 != V_229 ) {
F_7 ( V_14 , L_29
L_30 , V_214 , V_220 ) ;
V_214 -> V_219 = V_220 ;
V_173 = V_229 ;
} else {
V_230 ++ ;
if ( ! V_211 ) {
F_52 ( V_2 ) ;
if ( V_212 )
F_4 ( V_3 , V_2 ) ;
return V_173 ;
}
}
}
if ( ! F_53 ( & V_3 -> V_231 ) )
F_54 ( & V_3 -> V_231 , V_214 -> V_219 ) ;
return V_173 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_232 * V_7 = V_2 -> V_7 ;
enum V_233 V_32 = V_2 -> V_32 ;
V_2 -> V_32 = V_234 ;
switch ( V_32 ) {
case V_235 :
case V_236 :
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_237 :
case V_33 :
if ( V_2 -> V_7 )
V_7 -> V_238 ( V_7 ) ;
F_56 ( V_2 , NULL ) ;
break;
default:
F_2 ( V_2 ) ;
F_56 ( V_2 , NULL ) ;
F_5 ( V_2 , V_239 ) ;
}
}
static void F_57 ( struct V_1 * V_2 , T_3 V_240 )
{
struct V_213 * V_223 = V_2 -> V_223 ;
struct V_232 * V_7 = V_2 -> V_7 ;
struct V_177 * V_180 ;
unsigned long V_241 ;
if ( ! V_223 )
return;
V_180 = (struct V_177 * ) V_223 -> V_16 ;
if ( V_180 ) {
F_49 ( & V_180 -> V_242 , V_241 ) ;
if ( V_180 -> V_7 ) {
F_7 ( V_14 , L_31
L_32
L_33
L_34 , V_180 -> V_183 . V_243 , V_7 ,
F_36 ( & V_180 -> V_244 ) ) ;
V_180 -> V_245 = V_246 ;
V_180 -> V_247 = V_248 ;
V_180 -> V_249 = V_250 ;
F_50 ( & V_180 -> V_242 , V_241 ) ;
F_58 ( V_180 ) ;
} else {
F_50 ( & V_180 -> V_242 , V_241 ) ;
F_7 ( V_14 , L_31
L_32
L_35
L_34 , V_180 -> V_183 . V_243 , V_7 ,
F_36 ( & V_180 -> V_244 ) ) ;
}
} else if ( V_240 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_2 -> V_7 )
V_7 -> V_238 ( V_7 ) ;
F_45 ( V_223 ) ;
V_2 -> V_223 = NULL ;
}
static void F_59 ( unsigned long V_251 )
{
unsigned long V_29 ;
unsigned long V_252 = V_220 + V_253 ;
struct V_1 * V_2 ;
struct V_213 * V_227 , * V_223 ;
struct V_254 * V_255 ;
struct V_254 * V_256 ;
struct V_165 * V_3 = V_257 ;
T_3 V_258 = 0 ;
unsigned long V_219 ;
int V_173 = V_229 ;
struct V_254 V_259 ;
F_60 ( & V_259 ) ;
F_49 ( & V_3 -> V_260 , V_29 ) ;
F_61 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_2 = F_62 ( V_256 , struct V_1 , V_261 ) ;
if ( ( V_2 -> V_223 ) || ( V_2 -> V_227 ) ) {
F_2 ( V_2 ) ;
F_63 ( & V_2 -> V_262 , & V_259 ) ;
}
}
F_50 ( & V_3 -> V_260 , V_29 ) ;
F_61 (list_node, list_core_temp, &timer_list) {
V_2 = F_62 ( V_256 , struct V_1 ,
V_262 ) ;
V_223 = V_2 -> V_223 ;
if ( V_223 ) {
if ( F_64 ( V_223 -> V_219 , V_220 ) ) {
if ( V_252 > V_223 -> V_219 ||
! V_258 ) {
V_252 = V_223 -> V_219 ;
V_258 = 1 ;
}
} else {
F_57 ( V_2 , 1 ) ;
}
}
F_49 ( & V_2 -> V_226 , V_29 ) ;
do {
V_227 = V_2 -> V_227 ;
if ( ! V_227 )
break;
if ( F_64 ( V_227 -> V_219 , V_220 ) ) {
if ( V_2 -> V_32 != V_263 ) {
if ( ( V_252 >
V_227 -> V_219 ) ||
! V_258 ) {
V_252 =
V_227 -> V_219 ;
V_258 = 1 ;
}
} else {
F_65 ( V_2 ) ;
}
break;
}
if ( ( V_2 -> V_32 == V_263 ) ||
( V_2 -> V_32 == V_234 ) ) {
F_65 ( V_2 ) ;
break;
}
if ( ! V_227 -> V_217 ||
! V_227 -> V_215 ) {
V_264 ++ ;
F_65 ( V_2 ) ;
F_50 (
& V_2 -> V_226 , V_29 ) ;
F_55 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
F_49 ( & V_2 -> V_226 ,
V_29 ) ;
break;
}
F_48 ( & V_227 -> V_16 -> V_225 ) ;
V_265 ++ ;
F_7 ( V_14 , L_36
L_37
L_38
L_39
L_40 , V_227 , V_2 , V_220 ,
V_227 -> V_219 ,
V_227 -> V_217 ,
V_227 -> V_224 ,
V_2 -> V_109 . V_266 ) ;
F_50 ( & V_2 -> V_226 ,
V_29 ) ;
V_173 = F_51 ( V_227 -> V_16 , V_2 -> V_90 ) ;
F_49 ( & V_2 -> V_226 , V_29 ) ;
if ( V_173 != V_229 ) {
F_7 ( V_14 , L_41
L_42 , V_2 ) ;
V_267 ++ ;
V_227 -> V_215 -- ;
V_252 = V_220 + V_268 ;
V_258 = 1 ;
break;
} else {
V_230 ++ ;
}
F_7 ( V_14 , L_43
L_44 ,
V_227 -> V_217 ,
V_227 -> V_215 ) ;
if ( V_227 -> V_211 ) {
V_227 -> V_217 -- ;
V_219 = ( V_228 <<
( V_218 - V_227 -> V_217 ) ) ;
V_227 -> V_219 = V_220 +
F_66 ( V_219 , V_269 ) ;
if ( V_252 > V_227 -> V_219 ||
! V_258 ) {
V_252 = V_227 -> V_219 ;
V_258 = 1 ;
}
} else {
int V_212 ;
V_212 =
V_227 -> V_212 ;
F_7 ( V_14 , L_45 ,
V_2 , V_2 -> V_32 ) ;
F_65 ( V_2 ) ;
if ( V_212 )
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
} while ( 0 );
F_50 ( & V_2 -> V_226 , V_29 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
if ( V_258 ) {
if ( ! F_53 ( & V_3 -> V_231 ) )
F_54 ( & V_3 -> V_231 , V_252 ) ;
}
}
static int F_67 ( struct V_1 * V_2 , T_3 V_270 ,
struct V_15 * V_16 )
{
int V_173 ;
int V_29 = V_127 ;
char V_271 [ sizeof( struct V_272 ) +
sizeof( struct V_273 ) + sizeof( struct V_274 ) +
V_275 ] ;
int V_276 = 0 ;
union V_277 * V_75 ;
if ( ! V_2 )
return - V_43 ;
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_278 . V_279 = V_280 ;
V_75 -> V_278 . V_281 = sizeof( struct V_272 ) ;
V_75 -> V_278 . V_282 = F_22 ( V_2 -> V_109 . V_282 ) ;
V_276 += sizeof( struct V_272 ) ;
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_283 . V_279 = V_284 ;
V_75 -> V_283 . V_281 = sizeof( struct V_273 ) ;
V_75 -> V_283 . V_285 = V_2 -> V_109 . V_286 ;
V_276 += sizeof( struct V_273 ) ;
if ( V_270 && ! ( V_287 & V_288 ) ) {
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_289 . V_279 = V_290 ;
V_75 -> V_289 . V_281 = sizeof( struct V_274 ) ;
V_276 += sizeof( struct V_274 ) ;
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_291 = 1 ;
V_276 += 1 ;
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_291 = 1 ;
V_276 += 1 ;
}
V_75 = (union V_277 * ) & V_271 [ V_276 ] ;
V_75 -> V_291 = V_292 ;
V_276 += 1 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
if ( V_270 )
V_29 |= V_22 ;
F_11 ( V_16 , V_2 , V_271 , V_276 , NULL , 0 , V_29 ) ;
V_173 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_173 ;
}
static int F_56 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_173 ;
int V_29 = V_130 | V_22 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - V_27 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_29 ) ;
V_173 = F_12 ( V_2 , V_16 , V_23 , 0 , 1 ) ;
return V_173 ;
}
static int F_68 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_173 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 ) ;
V_173 = F_12 ( V_2 , V_16 , V_23 , 0 , 0 ) ;
return V_173 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_173 ;
if ( ! V_16 )
V_16 = F_14 ( V_26 ) ;
if ( ! V_16 ) {
F_7 ( V_14 , L_4 ) ;
return - 1 ;
}
F_11 ( V_16 , V_2 , NULL , 0 , NULL , 0 , V_22 | V_31 ) ;
V_173 = F_12 ( V_2 , V_16 , V_23 , 1 , 0 ) ;
return V_173 ;
}
static struct V_1 * F_70 ( struct V_165 * V_3 ,
T_2 V_12 , T_7 V_10 , T_2 V_13 , T_7 V_11 )
{
unsigned long V_29 ;
struct V_254 * V_293 ;
struct V_1 * V_2 ;
V_293 = & V_3 -> V_294 ;
F_49 ( & V_3 -> V_260 , V_29 ) ;
F_71 (cm_node, hte, list) {
F_7 ( V_14 , L_46 ,
V_2 -> V_11 , V_2 -> V_13 ,
V_11 , V_13 ,
V_2 -> V_10 , V_2 -> V_12 ,
V_10 , V_12 ) ;
if ( ( V_2 -> V_114 == V_11 ) &&
( V_2 -> V_118 == V_13 ) &&
( V_2 -> V_116 == V_10 ) &&
( V_2 -> V_120 == V_12 ) ) {
F_2 ( V_2 ) ;
F_50 ( & V_3 -> V_260 , V_29 ) ;
return V_2 ;
}
}
F_50 ( & V_3 -> V_260 , V_29 ) ;
return NULL ;
}
static struct V_295 * F_72 ( struct V_165 * V_3 ,
T_7 V_296 , T_2 V_297 ,
enum V_298 V_299 , int V_300 )
{
unsigned long V_29 ;
struct V_295 * V_301 ;
T_7 V_302 ;
T_2 V_303 ;
F_49 ( & V_3 -> V_304 , V_29 ) ;
F_71 (listen_node, &cm_core->listen_list.list, list) {
if ( V_300 ) {
V_302 = V_301 -> V_11 ;
V_303 = V_301 -> V_13 ;
} else {
V_302 = V_301 -> V_114 ;
V_303 = V_301 -> V_118 ;
}
if ( ( ( V_302 == V_296 ) ||
V_302 == 0x00000000 ) &&
( V_303 == V_297 ) &&
( V_299 & V_301 -> V_299 ) ) {
F_48 ( & V_301 -> V_305 ) ;
F_50 ( & V_3 -> V_304 , V_29 ) ;
return V_301 ;
}
}
F_50 ( & V_3 -> V_304 , V_29 ) ;
return NULL ;
}
static int F_73 ( struct V_165 * V_3 , struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_254 * V_293 ;
if ( ! V_2 || ! V_3 )
return - V_43 ;
F_7 ( V_14 , L_47 ,
V_2 ) ;
F_49 ( & V_3 -> V_260 , V_29 ) ;
V_293 = & V_3 -> V_294 ;
F_74 ( & V_2 -> V_261 , V_293 ) ;
F_48 ( & V_3 -> V_306 ) ;
F_50 ( & V_3 -> V_260 , V_29 ) ;
return 0 ;
}
static int F_75 ( struct V_165 * V_3 ,
struct V_295 * V_307 , int V_308 )
{
int V_173 = - V_43 ;
int V_309 = 0 ;
unsigned long V_29 ;
struct V_254 * V_310 = NULL ;
struct V_254 * V_311 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_254 V_312 ;
F_7 ( V_14 , L_48
L_49 , V_307 , V_308 ,
F_36 ( & V_307 -> V_305 ) ) ;
F_60 ( & V_312 ) ;
if ( V_308 ) {
F_49 ( & V_3 -> V_260 , V_29 ) ;
F_61 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_2 = F_62 ( V_310 , struct V_1 ,
V_261 ) ;
if ( ( V_2 -> V_307 == V_307 ) &&
( ! V_2 -> V_313 ) ) {
F_2 ( V_2 ) ;
F_63 ( & V_2 -> V_314 , & V_312 ) ;
}
}
F_50 ( & V_3 -> V_260 , V_29 ) ;
}
F_61 (list_pos, list_temp, &reset_list) {
V_2 = F_62 ( V_310 , struct V_1 ,
V_314 ) ;
{
struct V_1 * V_315 = V_2 -> V_316 ;
enum V_233 V_317 ;
if ( V_33 <= V_2 -> V_32 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
} else {
if ( ! V_315 ) {
F_52 ( V_2 ) ;
V_309 = F_56 ( V_2 , NULL ) ;
if ( V_309 ) {
V_2 -> V_32 =
V_234 ;
F_46 ( 1 ) ;
} else {
V_317 = V_2 -> V_32 ;
V_2 -> V_32 = V_318 ;
if ( V_317 != V_319 )
F_4 (
V_2 -> V_3 ,
V_2 ) ;
}
} else {
struct V_4 V_6 ;
V_6 . V_2 = V_315 ;
V_6 . V_9 . V_10 =
V_315 -> V_10 ;
V_6 . V_9 . V_11 =
V_315 -> V_11 ;
V_6 . V_9 . V_12 =
V_315 -> V_12 ;
V_6 . V_9 . V_13 =
V_315 -> V_13 ;
V_6 . V_9 . V_7 = V_315 -> V_7 ;
F_2 ( V_315 ) ;
V_315 -> V_32 = V_234 ;
F_76 ( & V_6 ) ;
V_2 -> V_32 = V_318 ;
F_4 ( V_2 -> V_3 ,
V_2 ) ;
}
}
}
}
F_49 ( & V_3 -> V_304 , V_29 ) ;
if ( ! F_77 ( & V_307 -> V_305 ) ) {
F_78 ( & V_307 -> V_261 ) ;
F_79 ( & V_3 -> V_167 ) ;
F_50 ( & V_3 -> V_304 , V_29 ) ;
if ( V_307 -> V_156 ) {
F_80 ( V_307 -> V_156 ,
V_307 -> V_118 ,
F_81 ( V_307 -> V_156 -> V_320 -> V_321 -> V_322 ) ,
V_323 ) ;
F_28 ( V_307 -> V_11 ,
V_307 -> V_13 ,
V_307 -> V_114 ,
V_307 -> V_118 ) ;
F_7 ( V_324 ,
L_50 ,
V_307 -> V_118 ) ;
}
F_7 ( V_14 , L_51 , V_307 ) ;
F_45 ( V_307 ) ;
V_307 = NULL ;
V_173 = 0 ;
F_48 ( & V_325 ) ;
} else {
F_50 ( & V_3 -> V_304 , V_29 ) ;
}
if ( V_307 ) {
if ( F_36 ( & V_307 -> V_326 ) > 0 )
F_7 ( V_14 , L_52
L_53 ,
V_307 , F_36 ( & V_307 -> V_326 ) ) ;
}
return V_173 ;
}
static int F_82 ( struct V_165 * V_3 ,
struct V_295 * V_307 )
{
V_307 -> V_299 = V_327 ;
V_307 -> V_7 = NULL ;
return F_75 ( V_3 , V_307 , 1 ) ;
}
static inline int F_83 ( struct V_165 * V_3 ,
struct V_1 * V_2 )
{
V_2 -> V_313 = 1 ;
if ( V_2 -> V_328 ) {
F_84 ( ! V_2 -> V_307 ) ;
F_79 ( & V_2 -> V_307 -> V_326 ) ;
V_2 -> V_328 = 0 ;
F_84 ( F_36 ( & V_2 -> V_307 -> V_326 ) < 0 ) ;
}
if ( ! F_53 ( & V_3 -> V_231 ) )
F_54 ( & V_3 -> V_231 , ( V_220 + V_268 ) ) ;
return 0 ;
}
static int F_85 ( struct V_155 * V_156 , T_3 V_329 , int V_330 )
{
struct V_331 * V_332 ;
struct V_333 * V_334 ;
int V_335 = V_330 ;
struct V_336 * V_90 ;
struct V_337 * V_338 = V_156 -> V_320 -> V_338 ;
V_332 = F_86 ( & V_339 , F_23 ( V_329 ) , 0 , 0 , 0 ) ;
if ( F_87 ( V_332 ) ) {
F_88 ( V_340 L_54 ,
V_67 , V_329 ) ;
return V_335 ;
}
if ( F_89 ( V_156 -> V_90 ) )
V_90 = F_90 ( V_156 -> V_90 ) ;
else
V_90 = V_156 -> V_90 ;
V_334 = F_91 ( & V_341 , & V_332 -> V_342 , V_90 ) ;
F_92 () ;
if ( V_334 ) {
if ( V_334 -> V_343 & V_344 ) {
F_7 ( V_14 , L_55
L_56 , V_329 ,
V_334 -> V_345 , F_34 ( V_332 -> V_342 ) ) ;
if ( V_330 >= 0 ) {
if ( F_93 ( V_338 -> V_346 [ V_330 ] . V_347 , V_334 -> V_345 ) ) {
goto V_348;
}
F_94 ( V_156 -> V_90 ,
V_338 -> V_346 [ V_330 ] . V_347 ,
V_329 , V_349 ) ;
}
F_94 ( V_156 -> V_90 , V_334 -> V_345 ,
V_329 , V_350 ) ;
V_335 = F_95 ( V_156 -> V_320 , V_329 , NULL ,
V_351 ) ;
} else {
F_96 ( V_334 , NULL ) ;
}
}
V_348:
F_97 () ;
if ( V_334 )
F_98 ( V_334 ) ;
F_99 ( V_332 ) ;
return V_335 ;
}
static struct V_1 * F_100 ( struct V_165 * V_3 ,
struct V_155 * V_156 , struct V_149 * V_9 ,
struct V_295 * V_307 )
{
struct V_1 * V_2 ;
struct V_352 V_353 ;
int V_354 = 0 ;
int V_330 = 0 ;
struct V_355 * V_320 ;
struct V_337 * V_338 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_11 = V_9 -> V_11 ;
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_12 = V_9 -> V_12 ;
V_2 -> V_114 = V_9 -> V_114 ;
V_2 -> V_116 = V_9 -> V_116 ;
V_2 -> V_118 = V_9 -> V_118 ;
V_2 -> V_120 = V_9 -> V_120 ;
V_2 -> V_48 = V_356 ;
V_2 -> V_69 = V_70 ;
V_2 -> V_64 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_56 = 0 ;
F_7 ( V_14 , L_57 ,
& V_2 -> V_11 , V_2 -> V_13 ,
& V_2 -> V_10 , V_2 -> V_12 ) ;
V_2 -> V_307 = V_307 ;
V_2 -> V_90 = V_156 -> V_90 ;
V_2 -> V_7 = V_9 -> V_7 ;
memcpy ( V_2 -> V_101 , V_156 -> V_90 -> V_357 , V_99 ) ;
F_7 ( V_14 , L_58 , V_2 -> V_307 ,
V_2 -> V_7 ) ;
F_101 ( & V_2 -> V_226 ) ;
V_2 -> V_316 = NULL ;
F_102 ( & V_2 -> V_305 , 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_109 . V_110 = V_358 ;
V_2 -> V_109 . V_286 = V_359 ;
V_2 -> V_109 . V_134 = V_360 >>
V_359 ;
V_353 = F_103 () ;
V_2 -> V_109 . V_122 = F_23 ( V_353 . V_361 ) ;
V_2 -> V_109 . V_282 = V_156 -> V_362 - sizeof( struct V_81 ) -
sizeof( struct V_79 ) - V_87 - V_363 ;
V_2 -> V_109 . V_124 = 0 ;
F_48 ( & V_3 -> V_168 ) ;
V_2 -> V_364 = V_9 -> V_364 ;
V_2 -> V_365 = 0 ;
V_2 -> V_328 = 0 ;
V_2 -> V_156 = V_156 ;
V_320 = V_156 -> V_320 ;
V_338 = V_320 -> V_338 ;
V_2 -> V_316 = NULL ;
V_354 = F_95 ( V_320 , V_2 -> V_116 ,
NULL , V_351 ) ;
V_330 = F_85 ( V_156 ,
V_2 -> V_116 , V_354 ) ;
if ( V_330 < 0 ) {
F_45 ( V_2 ) ;
return NULL ;
}
memcpy ( V_2 -> V_98 , V_338 -> V_346 [ V_330 ] . V_347 , V_99 ) ;
F_7 ( V_14 , L_59 ,
V_2 -> V_98 ) ;
F_73 ( V_3 , V_2 ) ;
F_48 ( & V_366 ) ;
return V_2 ;
}
static int F_2 ( struct V_1 * V_2 )
{
F_48 ( & V_2 -> V_305 ) ;
return 0 ;
}
static int F_4 ( struct V_165 * V_3 ,
struct V_1 * V_2 )
{
unsigned long V_29 ;
struct V_177 * V_180 ;
if ( ! V_2 )
return - V_43 ;
F_49 ( & V_2 -> V_3 -> V_260 , V_29 ) ;
if ( F_77 ( & V_2 -> V_305 ) ) {
F_50 ( & V_2 -> V_3 -> V_260 , V_29 ) ;
return 0 ;
}
F_78 ( & V_2 -> V_261 ) ;
F_79 ( & V_3 -> V_306 ) ;
F_50 ( & V_2 -> V_3 -> V_260 , V_29 ) ;
if ( ! V_2 -> V_313 && V_2 -> V_328 ) {
F_84 ( ! V_2 -> V_307 ) ;
F_79 ( & V_2 -> V_307 -> V_326 ) ;
F_84 ( F_36 ( & V_2 -> V_307 -> V_326 ) < 0 ) ;
}
F_46 ( V_2 -> V_227 ) ;
if ( V_2 -> V_223 )
F_57 ( V_2 , 0 ) ;
if ( V_2 -> V_307 ) {
F_75 ( V_3 , V_2 -> V_307 , 0 ) ;
} else {
if ( V_2 -> V_365 && V_2 -> V_156 ) {
F_80 ( V_2 -> V_156 , V_2 -> V_118 ,
F_81 ( V_2 -> V_156 -> V_320 -> V_321 -> V_322 ) ,
V_323 ) ;
}
F_7 ( V_324 , L_50 ,
V_2 -> V_118 ) ;
F_28 ( V_2 -> V_11 , V_2 -> V_13 ,
V_2 -> V_114 , V_2 -> V_118 ) ;
}
F_79 ( & V_3 -> V_168 ) ;
F_48 ( & V_367 ) ;
V_180 = V_2 -> V_180 ;
if ( V_180 ) {
V_180 -> V_2 = NULL ;
F_104 ( & V_180 -> V_368 ) ;
V_2 -> V_180 = NULL ;
}
F_45 ( V_2 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 , T_1 * V_369 ,
T_3 V_76 , T_3 V_370 )
{
T_3 V_371 ;
T_3 V_372 = 0 ;
union V_277 * V_373 ;
char V_374 = 0 ;
while ( V_372 < V_76 ) {
V_373 = (union V_277 * ) ( V_369 + V_372 ) ;
switch ( V_373 -> V_289 . V_279 ) {
case V_292 :
V_372 = V_76 ;
break;
case V_375 :
V_372 += 1 ;
continue;
case V_280 :
F_7 ( V_14 , L_60
L_61 , V_67 ,
V_373 -> V_278 . V_281 , V_372 , V_76 ) ;
V_374 = 1 ;
if ( V_373 -> V_278 . V_281 != 4 ) {
return 1 ;
} else {
V_371 = F_16 ( V_373 -> V_278 . V_282 ) ;
if ( V_371 > 0 && V_371 <
V_2 -> V_109 . V_282 )
V_2 -> V_109 . V_282 = V_371 ;
}
break;
case V_284 :
V_2 -> V_109 . V_376 =
V_373 -> V_283 . V_285 ;
break;
default:
F_7 ( V_14 , L_62 ,
V_373 -> V_289 . V_279 ) ;
break;
}
V_372 += V_373 -> V_289 . V_281 ;
}
if ( ( ! V_374 ) && ( V_370 ) )
V_2 -> V_109 . V_282 = V_377 ;
return 0 ;
}
static void F_106 ( struct V_15 * V_16 )
{
F_48 ( & V_378 ) ;
F_107 ( V_16 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
F_7 ( V_14 , L_63
L_49 , V_2 , V_2 -> V_32 ,
F_36 ( & V_2 -> V_305 ) ) ;
switch ( V_2 -> V_32 ) {
case V_235 :
case V_379 :
case V_380 :
case V_381 :
V_2 -> V_109 . V_124 ++ ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_237 ;
F_69 ( V_2 , NULL ) ;
break;
case V_49 :
F_5 ( V_2 , V_239 ) ;
V_2 -> V_109 . V_124 ++ ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
F_2 ( V_2 ) ;
F_56 ( V_2 , NULL ) ;
break;
case V_33 :
V_2 -> V_109 . V_124 ++ ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_236 ;
F_68 ( V_2 , NULL ) ;
break;
case V_382 :
V_2 -> V_109 . V_124 ++ ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_383 ;
F_68 ( V_2 , NULL ) ;
F_12 ( V_2 , NULL , V_221 , 1 , 0 ) ;
break;
case V_383 :
V_2 -> V_109 . V_124 ++ ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
break;
case V_263 :
default:
F_7 ( V_14 , L_64 ,
V_2 , V_2 -> V_32 ) ;
break;
}
}
static void F_109 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_384 = 0 ;
F_48 ( & V_385 ) ;
F_7 ( V_14 , L_65
L_66 , V_2 , V_2 -> V_32 ,
F_36 ( & V_2 -> V_305 ) ) ;
F_52 ( V_2 ) ;
switch ( V_2 -> V_32 ) {
case V_379 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_307 , V_2 -> V_32 ) ;
switch ( V_2 -> V_48 ) {
case V_47 :
V_2 -> V_48 = V_46 ;
V_2 -> V_32 = V_379 ;
if ( F_67 ( V_2 , 0 , NULL ) ) {
F_110 ( V_2 , V_16 , V_384 ) ;
}
break;
case V_46 :
default:
F_110 ( V_2 , V_16 , V_384 ) ;
break;
}
break;
case V_319 :
F_48 ( & V_2 -> V_386 ) ;
F_107 ( V_16 ) ;
break;
case V_380 :
case V_235 :
case V_387 :
F_7 ( V_14 , L_69 , V_67 , __LINE__ ) ;
F_111 ( V_2 , V_16 , V_384 ) ;
break;
case V_263 :
F_110 ( V_2 , V_16 , V_384 ) ;
break;
case V_234 :
F_106 ( V_16 ) ;
break;
case V_382 :
case V_33 :
case V_237 :
V_2 -> V_7 -> V_238 ( V_2 -> V_7 ) ;
case V_383 :
V_2 -> V_32 = V_234 ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_106 ( V_16 ) ;
break;
default:
F_106 ( V_16 ) ;
break;
}
}
static void F_112 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
int V_173 = 0 ;
int V_78 = V_16 -> V_35 ;
T_1 * V_388 = V_16 -> V_77 ;
enum V_5 type = V_389 ;
T_3 V_390 ;
V_173 = F_15 ( V_2 , V_388 , & V_390 , V_78 ) ;
if ( V_173 ) {
F_7 ( V_14 , L_70 ) ;
if ( V_2 -> V_32 == V_49 ) {
F_7 ( V_14 , L_71
L_72 , V_67 ,
__LINE__ , V_2 , V_2 -> V_307 ,
V_2 -> V_32 ) ;
F_110 ( V_2 , V_16 , 1 ) ;
} else {
F_111 ( V_2 , V_16 , 1 ) ;
}
return;
}
switch ( V_2 -> V_32 ) {
case V_380 :
if ( V_390 == V_74 )
F_46 ( 1 ) ;
V_2 -> V_32 = V_319 ;
type = V_391 ;
F_102 ( & V_2 -> V_386 ,
V_392 ) ;
break;
case V_49 :
F_52 ( V_2 ) ;
if ( V_390 == V_74 ) {
type = V_393 ;
V_2 -> V_32 = V_381 ;
} else {
type = V_394 ;
V_2 -> V_32 = V_263 ;
}
break;
default:
F_46 ( 1 ) ;
break;
}
F_107 ( V_16 ) ;
F_5 ( V_2 , type ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
switch ( V_2 -> V_32 ) {
case V_379 :
case V_49 :
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_307 , V_2 -> V_32 ) ;
F_110 ( V_2 , V_16 , 1 ) ;
break;
case V_380 :
case V_235 :
F_111 ( V_2 , V_16 , 1 ) ;
break;
case V_263 :
default:
F_106 ( V_16 ) ;
}
}
static int F_114 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_309 ;
V_309 = ( ( F_34 ( V_80 -> V_125 ) == V_2 -> V_109 . V_122 ) ) ? 0 : 1 ;
if ( V_309 )
F_110 ( V_2 , V_16 , 1 ) ;
return V_309 ;
}
static int F_115 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 )
{
int V_309 = 0 ;
T_3 V_121 ;
T_3 V_125 ;
T_3 V_122 = V_2 -> V_109 . V_122 ;
T_3 V_124 = V_2 -> V_109 . V_124 ;
T_3 V_134 ;
V_121 = F_34 ( V_80 -> V_121 ) ;
V_125 = F_34 ( V_80 -> V_125 ) ;
V_134 = V_2 -> V_109 . V_134 ;
if ( V_125 != V_122 )
V_309 = 1 ;
else if ( ! F_116 ( V_121 , V_124 , ( V_124 + V_134 ) ) )
V_309 = 1 ;
if ( V_309 ) {
F_7 ( V_14 , L_67
L_68 , V_67 , __LINE__ , V_2 ,
V_2 -> V_307 , V_2 -> V_32 ) ;
F_113 ( V_2 , V_16 ) ;
F_7 ( V_14 , L_73
L_74 , V_2 , V_121 , V_124 ,
V_134 ) ;
}
return V_309 ;
}
static void F_117 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_173 ;
T_3 V_395 ;
int V_76 ;
V_76 = ( V_80 -> V_132 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_395 = F_34 ( V_80 -> V_121 ) ;
switch ( V_2 -> V_32 ) {
case V_379 :
case V_49 :
F_110 ( V_2 , V_16 , 1 ) ;
break;
case V_387 :
if ( F_36 ( & V_2 -> V_307 -> V_326 ) >
V_2 -> V_307 -> V_396 ) {
F_7 ( V_14 , L_75
L_76 ) ;
V_397 ++ ;
F_111 ( V_2 , V_16 , 0 ) ;
break;
}
V_173 = F_118 ( V_2 , V_80 , V_16 , V_76 ,
1 ) ;
if ( V_173 ) {
F_111 ( V_2 , V_16 , 0 ) ;
break;
}
V_2 -> V_109 . V_124 = V_395 + 1 ;
F_84 ( V_2 -> V_227 ) ;
V_2 -> V_328 = 1 ;
F_48 ( & V_2 -> V_307 -> V_326 ) ;
V_2 -> V_32 = V_235 ;
F_67 ( V_2 , 1 , V_16 ) ;
break;
case V_234 :
F_52 ( V_2 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 , V_16 ) ;
break;
case V_263 :
case V_380 :
case V_33 :
case V_382 :
case V_319 :
case V_237 :
case V_236 :
case V_398 :
default:
F_106 ( V_16 ) ;
break;
}
}
static void F_119 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_173 ;
T_3 V_395 ;
int V_76 ;
V_76 = ( V_80 -> V_132 << 2 ) - sizeof( struct V_79 ) ;
F_17 ( V_16 , 0 ) ;
V_395 = F_34 ( V_80 -> V_121 ) ;
switch ( V_2 -> V_32 ) {
case V_379 :
F_52 ( V_2 ) ;
if ( F_114 ( V_2 , V_80 , V_16 ) )
return;
V_2 -> V_109 . V_266 = F_34 ( V_80 -> V_125 ) ;
V_173 = F_118 ( V_2 , V_80 , V_16 , V_76 , 0 ) ;
if ( V_173 ) {
F_7 ( V_14 , L_77 ,
V_2 ) ;
break;
}
F_52 ( V_2 ) ;
V_2 -> V_109 . V_124 = V_395 + 1 ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_32 = V_49 ;
break;
case V_319 :
F_111 ( V_2 , V_16 , 1 ) ;
break;
case V_387 :
V_2 -> V_109 . V_122 = F_34 ( V_80 -> V_125 ) ;
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
F_56 ( V_2 , V_16 ) ;
break;
case V_234 :
V_2 -> V_109 . V_122 = F_34 ( V_80 -> V_125 ) ;
F_52 ( V_2 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 , V_16 ) ;
break;
case V_380 :
case V_33 :
case V_382 :
case V_237 :
case V_263 :
case V_236 :
case V_398 :
case V_49 :
default:
F_106 ( V_16 ) ;
break;
}
}
static int F_120 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_79 * V_80 )
{
int V_78 = 0 ;
T_3 V_395 ;
int V_173 = 0 ;
int V_76 ;
V_76 = ( V_80 -> V_132 << 2 ) - sizeof( struct V_79 ) ;
if ( F_115 ( V_2 , V_80 , V_16 ) )
return - V_43 ;
F_121 ( V_16 , V_80 -> V_132 << 2 ) ;
V_395 = F_34 ( V_80 -> V_121 ) ;
V_78 = V_16 -> V_35 ;
switch ( V_2 -> V_32 ) {
case V_235 :
F_52 ( V_2 ) ;
V_173 = F_118 ( V_2 , V_80 , V_16 , V_76 , 1 ) ;
if ( V_173 )
break;
V_2 -> V_109 . V_266 = F_34 ( V_80 -> V_125 ) ;
V_2 -> V_32 = V_380 ;
if ( V_78 ) {
V_2 -> V_109 . V_124 = V_395 + V_78 ;
F_112 ( V_2 , V_16 ) ;
} else {
F_107 ( V_16 ) ;
}
break;
case V_380 :
F_52 ( V_2 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_124 = V_395 + V_78 ;
F_112 ( V_2 , V_16 ) ;
} else {
F_106 ( V_16 ) ;
}
break;
case V_49 :
V_2 -> V_109 . V_266 = F_34 ( V_80 -> V_125 ) ;
if ( V_78 ) {
V_2 -> V_109 . V_124 = V_395 + V_78 ;
F_112 ( V_2 , V_16 ) ;
} else {
F_107 ( V_16 ) ;
}
break;
case V_387 :
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
F_56 ( V_2 , V_16 ) ;
break;
case V_234 :
F_52 ( V_2 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 , V_16 ) ;
break;
case V_237 :
case V_236 :
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
V_2 -> V_7 -> V_238 ( V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
F_106 ( V_16 ) ;
break;
case V_33 :
F_52 ( V_2 ) ;
F_106 ( V_16 ) ;
V_2 -> V_32 = V_382 ;
break;
case V_379 :
case V_382 :
case V_263 :
case V_319 :
case V_398 :
default:
F_52 ( V_2 ) ;
F_106 ( V_16 ) ;
break;
}
return V_173 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_15 * V_16 , int V_76 , int V_399 )
{
T_1 * V_369 = ( T_1 * ) & V_80 [ 1 ] ;
if ( V_76 ) {
if ( F_105 ( V_2 , V_369 , V_76 ,
( T_3 ) V_80 -> V_128 ) ) {
F_7 ( V_14 , L_78 ,
V_67 , V_2 ) ;
if ( V_399 )
F_111 ( V_2 , V_16 , 1 ) ;
else
F_110 ( V_2 , V_16 , 1 ) ;
return 1 ;
}
}
V_2 -> V_109 . V_400 = F_16 ( V_80 -> V_133 ) <<
V_2 -> V_109 . V_376 ;
if ( V_2 -> V_109 . V_400 > V_2 -> V_109 . V_401 )
V_2 -> V_109 . V_401 = V_2 -> V_109 . V_400 ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_384 )
{
F_52 ( V_2 ) ;
if ( V_384 ) {
F_7 ( V_14 , L_79
L_80 , V_2 , V_2 -> V_32 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 , V_16 ) ;
} else {
F_107 ( V_16 ) ;
}
V_2 -> V_32 = V_234 ;
F_5 ( V_2 , V_239 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_384 )
{
F_52 ( V_2 ) ;
V_2 -> V_32 = V_234 ;
if ( V_384 ) {
F_7 ( V_14 , L_81
L_82 , V_2 , V_2 -> V_32 ) ;
F_56 ( V_2 , V_16 ) ;
} else {
F_107 ( V_16 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_213 * V_227 ;
V_227 = V_2 -> V_227 ;
if ( V_227 ) {
V_2 -> V_227 = NULL ;
F_107 ( V_227 -> V_16 ) ;
F_45 ( V_227 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
}
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned long V_29 ;
F_49 ( & V_2 -> V_226 , V_29 ) ;
F_65 ( V_2 ) ;
F_50 ( & V_2 -> V_226 , V_29 ) ;
}
static void F_122 ( struct V_1 * V_2 , struct V_15 * V_16 ,
struct V_165 * V_3 )
{
enum V_402 V_403 = V_404 ;
struct V_79 * V_80 = F_47 ( V_16 ) ;
T_3 V_405 = 0 ;
int V_173 = 0 ;
F_121 ( V_16 , F_123 ( V_16 ) -> V_105 << 2 ) ;
F_7 ( V_14 , L_83
L_84 , V_2 , V_2 -> V_32 , V_80 -> V_128 ,
V_80 -> V_126 , V_80 -> V_131 , V_80 -> V_129 ) ;
if ( V_80 -> V_131 ) {
V_403 = V_406 ;
} else if ( V_80 -> V_128 ) {
V_403 = V_407 ;
if ( V_80 -> V_126 )
V_403 = V_408 ;
} else if ( V_80 -> V_126 ) {
V_403 = V_409 ;
}
if ( V_80 -> V_129 )
V_405 = 1 ;
switch ( V_403 ) {
case V_407 :
F_117 ( V_2 , V_16 , V_80 ) ;
break;
case V_408 :
F_119 ( V_2 , V_16 , V_80 ) ;
break;
case V_409 :
V_173 = F_120 ( V_2 , V_16 , V_80 ) ;
if ( V_405 && ! V_173 )
F_108 ( V_2 ) ;
break;
case V_406 :
F_109 ( V_2 , V_16 , V_80 ) ;
break;
default:
if ( ( V_405 ) && ( ! F_115 ( V_2 , V_80 , V_16 ) ) )
F_108 ( V_2 ) ;
F_106 ( V_16 ) ;
break;
}
}
static struct V_295 * F_124 ( struct V_165 * V_3 ,
struct V_155 * V_156 , struct V_149 * V_9 )
{
struct V_295 * V_307 ;
struct V_157 V_410 ;
struct V_153 V_154 ;
unsigned long V_29 ;
int V_411 = 0 ;
F_7 ( V_14 , L_85 ,
V_9 -> V_11 , V_9 -> V_13 ) ;
V_307 = F_72 ( V_3 , V_9 -> V_11 , V_9 -> V_13 ,
V_412 , 1 ) ;
if ( V_307 && V_307 -> V_299 == V_413 ) {
F_79 ( & V_307 -> V_305 ) ;
F_7 ( V_14 , L_86 ) ;
return NULL ;
}
if ( ! V_307 ) {
F_32 ( V_156 , & V_410 ) ;
V_411 = F_125 ( & V_410 , V_152 ) ;
if ( V_411 ) {
F_7 ( V_324 ,
L_87 , V_411 ) ;
}
if ( F_126 () && ! V_411 ) {
F_31 ( V_9 , & V_154 ) ;
V_411 = F_127 ( & V_154 , V_152 ) ;
if ( V_411 )
F_7 ( V_324 ,
L_88 , V_411 ) ;
else
F_33 ( V_9 , & V_154 ) ;
}
V_307 = F_6 ( sizeof( * V_307 ) , V_8 ) ;
if ( ! V_307 ) {
F_7 ( V_14 , L_89 ) ;
return NULL ;
}
V_307 -> V_11 = V_9 -> V_11 ;
V_307 -> V_13 = V_9 -> V_13 ;
V_307 -> V_114 = V_9 -> V_114 ;
V_307 -> V_118 = V_9 -> V_118 ;
V_307 -> V_414 = 0 ;
F_102 ( & V_307 -> V_305 , 1 ) ;
}
else {
V_307 -> V_414 = 1 ;
}
V_307 -> V_7 = V_9 -> V_7 ;
F_102 ( & V_307 -> V_326 , 0 ) ;
V_307 -> V_3 = V_3 ;
V_307 -> V_156 = V_156 ;
F_48 ( & V_3 -> V_168 ) ;
V_307 -> V_364 = V_9 -> V_364 ;
V_307 -> V_396 = V_9 -> V_396 ;
V_307 -> V_299 = V_413 ;
if ( ! V_307 -> V_414 ) {
F_49 ( & V_3 -> V_304 , V_29 ) ;
F_63 ( & V_307 -> V_261 , & V_3 -> V_415 . V_261 ) ;
F_50 ( & V_3 -> V_304 , V_29 ) ;
F_48 ( & V_3 -> V_167 ) ;
}
F_7 ( V_14 , L_90
L_91 ,
V_9 -> V_11 , V_9 -> V_13 ,
V_307 , V_307 -> V_396 , V_307 -> V_7 ) ;
return V_307 ;
}
static struct V_1 * F_128 ( struct V_165 * V_3 ,
struct V_155 * V_156 , T_2 V_416 ,
void * V_417 , struct V_149 * V_9 )
{
int V_173 = 0 ;
struct V_1 * V_2 ;
struct V_295 * V_418 ;
struct V_1 * V_419 ;
struct V_149 V_420 ;
T_1 * V_19 ;
V_2 = F_100 ( V_3 , V_156 , V_9 , NULL ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_109 . V_421 = 1 ;
V_2 -> V_109 . V_286 = V_359 ;
if ( V_9 -> V_11 == V_9 -> V_10 ) {
V_418 = F_72 ( V_3 ,
V_2 -> V_114 , V_2 -> V_120 ,
V_413 , 0 ) ;
if ( V_418 == NULL ) {
F_5 ( V_2 , V_239 ) ;
} else {
V_420 = * V_9 ;
V_420 . V_13 = V_9 -> V_12 ;
V_420 . V_12 = V_9 -> V_13 ;
V_420 . V_118 =
V_9 -> V_120 ;
V_420 . V_120 =
V_9 -> V_118 ;
V_420 . V_7 = V_418 -> V_7 ;
V_419 = F_100 ( V_3 , V_156 ,
& V_420 , V_418 ) ;
if ( ! V_419 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return NULL ;
}
F_48 ( & V_422 ) ;
V_419 -> V_316 = V_2 ;
V_419 -> V_109 . V_286 =
V_359 ;
V_2 -> V_316 = V_419 ;
memcpy ( V_419 -> V_73 , V_417 ,
V_416 ) ;
V_419 -> V_54 = V_416 ;
V_2 -> V_32 = V_263 ;
V_2 -> V_109 . V_124 =
V_419 -> V_109 . V_122 ;
V_419 -> V_109 . V_124 =
V_2 -> V_109 . V_122 ;
V_2 -> V_109 . V_401 =
V_419 -> V_109 . V_134 ;
V_419 -> V_109 . V_401 =
V_2 -> V_109 . V_134 ;
V_2 -> V_109 . V_400 =
V_419 -> V_109 . V_134 ;
V_419 -> V_109 . V_400 =
V_2 -> V_109 . V_134 ;
V_2 -> V_109 . V_376 =
V_419 -> V_109 . V_286 ;
V_419 -> V_109 . V_376 =
V_2 -> V_109 . V_286 ;
V_419 -> V_32 = V_319 ;
F_5 ( V_419 , V_391 ) ;
}
return V_2 ;
}
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_416 ;
memcpy ( V_19 , V_417 , V_416 ) ;
V_2 -> V_32 = V_379 ;
V_173 = F_67 ( V_2 , 0 , NULL ) ;
if ( V_173 ) {
F_7 ( V_14 , L_92
L_93 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
V_2 = NULL ;
}
if ( V_2 ) {
F_7 ( V_14 , L_94
L_95 ,
V_2 -> V_10 , V_2 -> V_12 , V_2 ,
V_2 -> V_7 ) ;
}
return V_2 ;
}
static int F_129 ( struct V_165 * V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int F_130 ( struct V_165 * V_3 , struct V_1 * V_2 )
{
int V_173 = 0 ;
int V_309 = 0 ;
int V_386 ;
struct V_4 V_6 ;
struct V_232 * V_7 = V_2 -> V_7 ;
struct V_1 * V_315 = V_2 -> V_316 ;
F_7 ( V_14 , L_96 ,
V_67 , V_2 , V_2 -> V_109 . V_421 , V_2 -> V_32 ) ;
if ( V_2 -> V_109 . V_421 )
return V_173 ;
F_52 ( V_2 ) ;
if ( ! V_315 ) {
V_386 = F_131 ( 1 , & V_2 -> V_386 ) ;
if ( V_386 == V_423 ) {
V_2 -> V_32 = V_234 ;
F_4 ( V_3 , V_2 ) ;
} else {
if ( V_2 -> V_32 == V_318 ) {
F_4 ( V_3 , V_2 ) ;
} else {
V_173 = F_13 ( V_2 ) ;
if ( V_173 ) {
V_2 -> V_32 = V_234 ;
V_309 = F_56 ( V_2 , NULL ) ;
if ( V_309 )
F_46 ( 1 ) ;
} else {
V_7 -> V_424 ( V_7 ) ;
}
}
}
} else {
V_2 -> V_7 = NULL ;
if ( V_2 -> V_32 == V_318 ) {
F_4 ( V_3 , V_2 ) ;
F_4 ( V_3 , V_315 ) ;
} else {
V_6 . V_2 = V_315 ;
V_6 . V_9 . V_10 = V_315 -> V_10 ;
V_6 . V_9 . V_11 = V_315 -> V_11 ;
V_6 . V_9 . V_12 = V_315 -> V_12 ;
V_6 . V_9 . V_13 = V_315 -> V_13 ;
V_6 . V_9 . V_7 = V_315 -> V_7 ;
F_132 ( & V_6 ) ;
F_4 ( V_3 , V_2 ) ;
V_315 -> V_32 = V_236 ;
V_7 = V_315 -> V_7 ;
F_4 ( V_3 , V_315 ) ;
V_7 -> V_238 ( V_7 ) ;
}
}
return V_173 ;
}
static int F_133 ( struct V_165 * V_3 , struct V_1 * V_2 )
{
int V_173 = 0 ;
if ( ! V_3 || ! V_2 )
return - V_43 ;
switch ( V_2 -> V_32 ) {
case V_235 :
case V_379 :
case V_425 :
case V_380 :
case V_426 :
case V_49 :
case V_319 :
F_52 ( V_2 ) ;
F_56 ( V_2 , NULL ) ;
break;
case V_427 :
V_2 -> V_32 = V_237 ;
F_69 ( V_2 , NULL ) ;
break;
case V_33 :
case V_382 :
case V_237 :
case V_383 :
case V_236 :
V_173 = - 1 ;
break;
case V_387 :
F_52 ( V_2 ) ;
F_56 ( V_2 , NULL ) ;
break;
case V_381 :
case V_398 :
case V_428 :
case V_234 :
case V_318 :
V_173 = F_4 ( V_3 , V_2 ) ;
break;
case V_263 :
if ( V_2 -> V_227 )
F_88 ( V_340 L_97
L_98 , V_2 -> V_227 ) ;
V_173 = F_4 ( V_3 , V_2 ) ;
break;
}
return V_173 ;
}
static int F_134 ( struct V_165 * V_3 ,
struct V_155 * V_156 , struct V_15 * V_16 )
{
struct V_1 * V_2 = NULL ;
struct V_295 * V_307 = NULL ;
struct V_81 * V_82 ;
struct V_79 * V_80 ;
struct V_149 V_429 ;
int V_430 = 1 ;
T_4 V_431 , V_432 ;
if ( ! V_16 )
return 0 ;
if ( V_16 -> V_35 < sizeof( struct V_81 ) + sizeof( struct V_79 ) )
return 0 ;
V_82 = (struct V_81 * ) V_16 -> V_77 ;
V_80 = (struct V_79 * ) ( V_16 -> V_77 + sizeof( struct V_81 ) ) ;
V_429 . V_11 = F_34 ( V_82 -> V_115 ) ;
V_429 . V_13 = F_16 ( V_80 -> V_119 ) ;
V_429 . V_10 = F_34 ( V_82 -> V_113 ) ;
V_429 . V_12 = F_16 ( V_80 -> V_117 ) ;
V_429 . V_114 = F_34 ( V_82 -> V_115 ) ;
V_429 . V_118 = F_16 ( V_80 -> V_119 ) ;
V_429 . V_116 = F_34 ( V_82 -> V_113 ) ;
V_429 . V_120 = F_16 ( V_80 -> V_117 ) ;
V_431 = F_135 ( V_82 -> V_115 ) ;
V_432 = F_135 ( V_82 -> V_113 ) ;
F_7 ( V_14 , L_99 ,
& V_431 , V_80 -> V_119 , & V_432 , V_80 -> V_117 ) ;
do {
V_2 = F_70 ( V_3 ,
V_429 . V_120 , V_429 . V_116 ,
V_429 . V_118 , V_429 . V_114 ) ;
if ( ! V_2 ) {
if ( ( ! V_80 -> V_128 ) || ( V_80 -> V_126 ) ) {
V_430 = 0 ;
break;
}
V_307 = F_72 ( V_3 , V_429 . V_114 ,
V_429 . V_118 ,
V_413 , 0 ) ;
if ( ! V_307 ) {
V_429 . V_7 = NULL ;
V_429 . V_364 = 0 ;
F_7 ( V_14 , L_100 ) ;
V_430 = 0 ;
break;
}
V_429 . V_7 = V_307 -> V_7 ;
V_429 . V_364 = V_307 -> V_364 ;
V_2 = F_100 ( V_3 , V_156 , & V_429 ,
V_307 ) ;
if ( ! V_2 ) {
F_7 ( V_14 , L_101
L_102 ) ;
V_264 ++ ;
F_79 ( & V_307 -> V_305 ) ;
F_107 ( V_16 ) ;
break;
}
if ( ! V_80 -> V_131 && ! V_80 -> V_129 ) {
V_2 -> V_32 = V_387 ;
} else {
V_264 ++ ;
F_4 ( V_3 , V_2 ) ;
F_107 ( V_16 ) ;
break;
}
F_2 ( V_2 ) ;
} else if ( V_2 -> V_32 == V_263 ) {
if ( V_2 -> V_180 -> V_433 )
F_136 ( V_16 , V_156 , V_2 -> V_180 ) ;
else {
F_4 ( V_3 , V_2 ) ;
F_48 ( & V_378 ) ;
F_107 ( V_16 ) ;
}
break;
}
F_137 ( V_16 ) ;
F_21 ( V_16 , sizeof( * V_80 ) ) ;
V_16 -> V_35 = F_16 ( V_82 -> V_107 ) ;
F_122 ( V_2 , V_16 , V_3 ) ;
F_4 ( V_3 , V_2 ) ;
} while ( 0 );
return V_430 ;
}
static struct V_165 * F_138 ( void )
{
struct V_165 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_434 ) ;
if ( ! V_3 )
return NULL ;
F_60 ( & V_3 -> V_294 ) ;
F_139 ( & V_3 -> V_231 ) ;
V_3 -> V_231 . V_435 = F_59 ;
V_3 -> V_436 = V_437 ;
V_3 -> V_32 = V_428 ;
V_3 -> V_438 = V_439 ;
F_102 ( & V_3 -> V_440 , 0 ) ;
V_3 -> V_441 = & V_442 ;
F_101 ( & V_3 -> V_260 ) ;
F_101 ( & V_3 -> V_304 ) ;
F_60 ( & V_3 -> V_415 . V_261 ) ;
F_7 ( V_14 , L_103 , V_3 ) ;
F_7 ( V_14 , L_104 ) ;
V_3 -> V_443 = F_140 ( L_105 ) ;
V_3 -> V_444 = F_8 ;
F_7 ( V_14 , L_106 ) ;
V_3 -> V_445 = F_140 ( L_107 ) ;
F_35 ( V_3 ) ;
return V_3 ;
}
static int F_141 ( struct V_165 * V_3 )
{
F_7 ( V_14 , L_108 , V_3 ) ;
if ( ! V_3 )
return - V_43 ;
F_142 () ;
if ( F_53 ( & V_3 -> V_231 ) )
F_143 ( & V_3 -> V_231 ) ;
F_144 ( V_3 -> V_443 ) ;
F_144 ( V_3 -> V_445 ) ;
F_7 ( V_14 , L_109 ) ;
F_45 ( V_3 ) ;
return 0 ;
}
static int F_145 ( struct V_165 * V_3 )
{
return V_3 -> V_32 ;
}
static int F_146 ( struct V_165 * V_3 , T_3 type , T_3 V_446 )
{
int V_173 = 0 ;
switch ( type ) {
case V_447 :
V_3 -> V_436 = V_446 ;
break;
case V_448 :
V_3 -> V_438 = V_446 ;
break;
default:
V_173 = - V_43 ;
}
return V_173 ;
}
static int F_147 ( struct V_177 * V_180 , struct V_1 * V_2 )
{
int V_173 = 0 ;
if ( ! V_180 )
return - V_43 ;
V_180 -> V_203 -> V_449 |= F_42 ( V_450 |
V_451 | V_452 |
V_453 ) ;
if ( V_2 -> V_109 . V_376 || V_2 -> V_109 . V_286 )
V_180 -> V_203 -> V_449 |= F_42 ( V_454 ) ;
V_180 -> V_203 -> V_455 |= F_42 ( 64 << V_456 ) ;
V_180 -> V_203 -> V_282 |= F_42 ( ( ( T_3 ) V_2 -> V_109 . V_282 ) << 16 ) ;
V_180 -> V_203 -> V_457 |= F_42 (
( T_3 ) V_458 << V_459 ) ;
V_180 -> V_203 -> V_460 |= F_42 (
( V_2 -> V_109 . V_376 << V_461 ) &
V_462 ) ;
V_180 -> V_203 -> V_460 |= F_42 (
( V_2 -> V_109 . V_286 << V_463 ) &
V_464 ) ;
V_180 -> V_203 -> V_465 = F_42 ( 0x80 ) ;
V_180 -> V_203 -> V_466 = 0 ;
V_180 -> V_203 -> V_467 = 0 ;
V_180 -> V_203 -> V_468 = F_42 ( V_2 -> V_109 . V_122 ) ;
V_180 -> V_203 -> V_400 = F_42 ( V_2 -> V_109 . V_400 ) ;
V_180 -> V_203 -> V_124 = F_42 ( V_2 -> V_109 . V_124 ) ;
V_180 -> V_203 -> V_134 = F_42 ( V_2 -> V_109 . V_134 <<
V_2 -> V_109 . V_286 ) ;
V_180 -> V_203 -> V_469 = F_42 ( V_2 -> V_109 . V_122 ) ;
V_180 -> V_203 -> V_470 = F_42 ( V_2 -> V_109 . V_122 ) ;
V_180 -> V_203 -> V_471 = 0 ;
V_180 -> V_203 -> V_472 = F_42 ( 0x6 ) ;
V_180 -> V_203 -> V_473 = F_42 ( 0x3FFFC000 ) ;
V_180 -> V_203 -> V_474 = F_42 ( 2 * V_2 -> V_109 . V_282 ) ;
V_180 -> V_203 -> V_475 = F_42 ( V_2 -> V_109 . V_124 ) ;
V_180 -> V_203 -> V_476 = F_42 ( V_2 -> V_109 . V_122 ) ;
V_180 -> V_203 -> V_401 = F_42 ( V_2 -> V_109 . V_401 ) ;
F_7 ( V_14 , L_110
L_111 ,
V_180 -> V_183 . V_243 , F_148 ( V_180 -> V_203 -> V_124 ) ,
F_148 ( V_180 -> V_203 -> V_468 ) ,
V_2 -> V_109 . V_282 , F_148 ( V_180 -> V_203 -> V_460 ) ,
F_148 ( V_180 -> V_203 -> V_134 ) ,
F_148 ( V_180 -> V_203 -> V_449 ) ) ;
F_7 ( V_14 , L_112 , F_148 ( V_180 -> V_203 -> V_400 ) ) ;
F_7 ( V_14 , L_113 , F_148 ( V_180 -> V_203 -> V_474 ) ) ;
F_7 ( V_14 , L_114 , F_148 ( V_180 -> V_203 -> V_401 ) ) ;
F_7 ( V_14 , L_115 ) ;
V_2 -> V_32 = V_263 ;
return V_173 ;
}
int F_58 ( struct V_177 * V_180 )
{
struct V_477 * V_478 ;
V_478 = F_6 ( sizeof *V_478 , V_8 ) ;
if ( ! V_478 )
return - V_27 ;
F_149 ( & V_180 -> V_368 ) ;
V_478 -> V_180 = V_180 ;
F_150 ( & V_478 -> V_478 , V_479 ) ;
F_151 ( V_257 -> V_445 , & V_478 -> V_478 ) ;
return 0 ;
}
static void V_479 ( struct V_480 * V_478 )
{
struct V_477 * V_481 = F_62 ( V_478 , struct V_477 , V_478 ) ;
struct V_177 * V_180 = V_481 -> V_180 ;
F_45 ( V_481 ) ;
F_7 ( V_14 , L_116 ,
V_180 -> V_247 , V_180 -> V_183 . V_243 ) ;
F_152 ( V_180 ) ;
F_104 ( & V_180 -> V_368 ) ;
}
static int F_152 ( struct V_177 * V_180 )
{
unsigned long V_29 ;
int V_173 = 0 ;
struct V_232 * V_7 ;
struct V_482 V_483 ;
struct V_155 * V_156 ;
T_2 V_484 ;
T_1 V_485 ;
T_1 V_486 ;
int V_487 = 0 ;
int V_488 = 0 ;
int V_489 = 0 ;
int V_490 = 0 ;
T_3 V_491 = V_492 ;
struct V_493 V_494 ;
if ( ! V_180 ) {
F_7 ( V_14 , L_117 ) ;
return - 1 ;
}
F_49 ( & V_180 -> V_242 , V_29 ) ;
V_7 = V_180 -> V_7 ;
if ( ! V_7 ) {
F_7 ( V_14 , L_118 ,
V_180 -> V_183 . V_243 ) ;
F_50 ( & V_180 -> V_242 , V_29 ) ;
return - 1 ;
}
V_156 = F_153 ( V_180 -> V_368 . V_495 ) ;
F_7 ( V_14 , L_119 , V_180 -> V_183 . V_243 ) ;
V_485 = V_180 -> V_245 ;
V_486 = V_180 -> V_249 ;
V_484 = V_180 -> V_247 ;
if ( V_180 -> V_496 ) {
V_488 = 1 ;
V_489 = 1 ;
V_180 -> V_7 = NULL ;
F_143 ( & V_180 -> V_497 ) ;
if ( V_180 -> V_498 == 0 ) {
V_180 -> V_498 = 1 ;
V_490 = 1 ;
}
} else if ( ( V_485 == V_499 ) ||
( ( V_486 == V_500 ) &&
( V_484 == V_501 ) ) ) {
V_488 = 1 ;
if ( V_484 == V_501 )
V_487 = - V_502 ;
}
if ( ( ( V_485 == V_246 ) ||
( V_485 == V_503 ) ||
( V_484 == V_504 ) ||
( V_484 == V_501 ) ) ) {
V_489 = 1 ;
V_180 -> V_7 = NULL ;
if ( V_180 -> V_498 == 0 ) {
V_180 -> V_498 = 1 ;
V_490 = 1 ;
}
}
F_50 ( & V_180 -> V_242 , V_29 ) ;
if ( ( V_490 ) && ( V_180 -> V_505 == 0 ) ) {
if ( V_180 -> V_506 >= V_507 )
V_491 |= V_508 ;
F_154 ( V_156 -> V_320 , V_180 , V_491 , 1 ) ;
if ( V_180 -> V_496 ) {
V_494 . V_495 = V_180 -> V_368 . V_495 ;
V_494 . V_6 = V_180 -> V_509 ;
V_494 . V_510 . V_511 = & V_180 -> V_368 ;
if ( V_180 -> V_368 . V_512 )
V_180 -> V_368 . V_512 ( & V_494 , V_180 -> V_368 . V_513 ) ;
}
}
if ( ( V_7 ) && ( V_7 -> V_512 ) ) {
if ( V_488 ) {
F_48 ( & V_514 ) ;
V_483 . V_6 = V_515 ;
V_483 . V_516 = V_487 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
F_7 ( V_14 , L_120
L_121
L_122 ,
V_180 -> V_183 . V_243 , V_180 -> V_183 . V_519 ,
V_180 -> V_183 . V_209 , V_7 ,
F_36 ( & V_180 -> V_244 ) ) ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
if ( V_173 )
F_7 ( V_14 , L_123
L_124 , V_173 ) ;
}
if ( V_489 ) {
F_48 ( & V_520 ) ;
F_155 ( V_180 , 1 ) ;
V_7 -> V_521 = V_180 ;
V_483 . V_6 = V_522 ;
V_483 . V_516 = 0 ;
V_483 . V_521 = V_7 -> V_521 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
if ( V_173 )
F_7 ( V_14 , L_125 , V_173 ) ;
V_7 -> V_238 ( V_7 ) ;
}
}
return 0 ;
}
static int F_155 ( struct V_177 * V_180 , int V_523 )
{
int V_173 = 0 ;
struct V_155 * V_156 ;
struct V_355 * V_320 ;
struct V_524 * V_159 ;
V_156 = F_153 ( V_180 -> V_368 . V_495 ) ;
if ( ! V_156 )
return - V_43 ;
V_320 = V_156 -> V_320 ;
V_159 = V_156 -> V_159 ;
F_7 ( V_14 , L_126 ,
F_156 ( V_156 -> V_90 ) ) ;
if ( V_180 -> V_525 ) {
V_180 -> V_525 = 0 ;
} else {
if ( V_180 -> V_526 ) {
if ( V_180 -> V_527 )
V_159 -> V_160 . V_528 ( V_180 -> V_527 ) ;
F_157 ( V_320 -> V_321 ,
V_180 -> V_416 + V_180 -> V_529 ,
V_180 -> V_526 , V_180 -> V_530 ) ;
}
}
if ( V_180 -> V_2 ) {
F_7 ( V_14 , L_127 ) ;
V_257 -> V_441 -> V_531 ( V_257 , V_180 -> V_2 ) ;
}
return V_173 ;
}
int F_158 ( struct V_232 * V_7 , struct V_532 * V_533 )
{
T_6 V_179 ;
struct V_534 * V_368 ;
struct V_177 * V_180 ;
struct V_155 * V_156 ;
struct V_355 * V_320 ;
struct V_1 * V_2 ;
struct V_337 * V_535 ;
struct V_536 V_537 ;
struct V_482 V_483 ;
struct V_181 * V_182 ;
struct V_538 V_539 ;
T_3 V_540 ;
int V_173 ;
int V_386 ;
struct V_524 * V_159 ;
struct V_541 * V_542 = NULL ;
struct V_543 V_544 ;
struct V_545 * V_546 ;
T_6 V_547 ;
T_1 V_548 = 0 ;
struct V_36 * V_37 ;
T_1 V_17 = 0 ;
T_1 * V_18 = & V_17 ;
T_1 * * V_19 = & V_18 ;
T_2 V_20 = 0 ;
struct V_142 * V_549 = (struct V_142 * ) & V_7 -> V_517 ;
struct V_142 * V_550 = (struct V_142 * ) & V_7 -> V_518 ;
V_368 = F_159 ( V_7 -> V_495 , V_533 -> V_551 ) ;
if ( ! V_368 )
return - V_43 ;
V_180 = F_160 ( V_368 ) ;
V_156 = F_153 ( V_180 -> V_368 . V_495 ) ;
V_320 = V_156 -> V_320 ;
V_535 = V_320 -> V_338 ;
V_2 = (struct V_1 * ) V_7 -> V_521 ;
F_7 ( V_14 , L_128
L_129 , V_2 , V_156 , V_156 -> V_90 ,
V_156 -> V_90 -> V_161 ) ;
if ( V_318 == V_2 -> V_32 ) {
if ( V_2 -> V_316 )
F_4 ( V_2 -> V_3 , V_2 -> V_316 ) ;
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_43 ;
}
V_386 = F_131 ( 1 , & V_2 -> V_386 ) ;
if ( V_386 == V_423 ) {
F_4 ( V_2 -> V_3 , V_2 ) ;
return - V_502 ;
}
V_180 -> V_2 = ( void * ) V_2 ;
V_2 -> V_180 = V_180 ;
F_7 ( V_14 , L_130 ,
V_180 -> V_183 . V_243 , V_2 , V_220 , V_2 -> V_307 ) ;
F_48 ( & V_552 ) ;
F_7 ( V_14 , L_126 ,
F_156 ( V_156 -> V_90 ) ) ;
V_180 -> V_529 = sizeof( struct V_36 ) ;
V_180 -> V_526 = F_161 ( V_320 -> V_321 ,
V_180 -> V_529 + V_533 -> V_416 ,
& V_180 -> V_530 ) ;
if ( ! V_180 -> V_526 ) {
F_7 ( V_14 , L_131 ) ;
return - V_27 ;
}
V_37 = (struct V_36 * ) V_180 -> V_526 ;
if ( V_2 -> V_48 == V_46 )
V_548 = 4 ;
if ( V_2 -> V_48 == V_46 ||
V_2 -> V_64 == V_62 ) {
F_37 ( V_2 , ( T_2 ) V_533 -> V_553 , ( T_2 ) V_533 -> V_554 ) ;
}
memcpy ( V_37 -> V_555 , V_533 -> V_417 ,
V_533 -> V_416 ) ;
F_10 ( V_2 , V_19 , & V_20 , V_180 -> V_526 , V_28 ) ;
V_180 -> V_416 = V_533 -> V_416 ;
V_182 = & V_180 -> V_183 . V_184 [ 0 ] ;
if ( V_550 -> V_146 . V_147 != V_549 -> V_146 . V_147 ) {
V_179 = ( unsigned long ) V_180 ;
V_159 = V_156 -> V_159 ;
V_546 = V_180 -> V_546 ;
V_544 . V_141 = V_180 -> V_530 + V_548 ;
V_544 . V_556 = V_20 ;
V_547 = ( T_6 ) ( unsigned long ) * V_19 ;
V_542 = V_159 -> V_160 . V_557 ( (struct V_558 * ) V_546 ,
& V_544 , 1 ,
V_559 ,
& V_547 ) ;
if ( ! V_542 ) {
F_7 ( V_14 , L_132
L_133 ,
V_2 ) ;
F_157 ( V_320 -> V_321 ,
V_180 -> V_416 + V_180 -> V_529 ,
V_180 -> V_526 , V_180 -> V_530 ) ;
return - V_27 ;
}
V_542 -> V_560 = & V_546 -> V_561 ;
V_542 -> V_495 = V_546 -> V_561 . V_495 ;
V_180 -> V_527 = V_542 ;
V_179 |= V_186 >> 1 ;
F_41 ( V_182 -> V_187 ,
V_188 ,
V_179 ) ;
V_182 -> V_187 [ V_191 ] =
F_42 ( V_562 |
V_563 ) ;
V_182 -> V_187 [ V_193 ] =
F_42 ( V_20 ) ;
F_41 ( V_182 -> V_187 ,
V_189 ,
( T_6 ) ( unsigned long ) ( * V_19 ) ) ;
V_182 -> V_187 [ V_194 ] =
F_42 ( V_20 ) ;
V_182 -> V_187 [ V_195 ] = V_542 -> V_564 ;
if ( V_180 -> V_201 ) {
V_180 -> V_201 = 0 ;
F_44 ( V_180 -> V_202 ) ;
}
V_180 -> V_203 -> V_204 |=
F_42 ( V_205 |
V_206 ) ;
} else {
V_180 -> V_203 -> V_204 |=
F_42 ( V_206 ) ;
}
V_180 -> V_208 = 1 ;
V_180 -> V_7 = V_7 ;
V_2 -> V_7 = V_7 ;
V_7 -> V_521 = V_180 ;
V_180 -> V_525 = 0 ;
if ( V_2 -> V_32 == V_263 )
F_7 ( V_14 , L_134 ,
V_2 ) ;
F_147 ( V_180 , V_2 ) ;
V_180 -> V_203 -> V_565 [ 0 ] =
F_162 ( V_2 -> V_118 ) ;
V_180 -> V_203 -> V_565 [ 1 ] =
F_162 ( V_2 -> V_120 ) ;
V_180 -> V_203 -> V_566 = F_42 ( V_2 -> V_116 ) ;
V_180 -> V_203 -> V_455 |= F_42 (
( T_3 ) F_81 ( V_320 -> V_321 -> V_322 ) <<
V_567 ) ;
V_180 -> V_203 -> V_568 |=
F_42 ( F_95 ( V_320 ,
F_148 ( V_180 -> V_203 -> V_566 ) , NULL ,
V_351 ) << 16 ) ;
V_180 -> V_203 -> V_569 = F_42 (
V_220 - F_163 ( V_320 , V_570 ) ) ;
V_180 -> V_203 -> V_571 = F_42 ( V_180 -> V_183 . V_243 ) ;
V_180 -> V_203 -> V_204 |= F_42 (
( ( T_3 ) 1 << V_572 ) ) ;
V_180 -> V_203 -> V_204 |=
F_42 ( ( T_3 ) V_2 -> V_56 ) ;
memset ( & V_539 , 0 , sizeof( V_539 ) ) ;
V_539 . V_573 =
F_42 ( ( T_3 ) F_81 ( V_320 -> V_321 -> V_322 ) << 24 ) ;
V_539 . V_574 = F_23 ( V_2 -> V_116 ) ;
V_539 . V_575 [ 0 ] = F_22 ( V_2 -> V_120 ) ;
V_539 . V_575 [ 1 ] = F_22 ( V_2 -> V_118 ) ;
V_540 = F_164 ( & V_539 ) ;
V_180 -> V_576 = F_135 ( V_540 ^ 0xffffffff ) ;
F_7 ( V_14 , L_135 ,
V_180 -> V_576 , V_180 -> V_576 & V_535 -> V_577 ) ;
V_180 -> V_576 &= V_535 -> V_577 ;
V_180 -> V_203 -> V_576 = F_42 ( V_180 -> V_576 ) ;
V_2 -> V_3 -> V_441 -> V_313 ( V_2 -> V_3 , V_2 ) ;
F_7 ( V_14 , L_136
L_137
L_138 , V_180 -> V_183 . V_243 ,
F_34 ( V_550 -> V_146 . V_147 ) , F_16 ( V_550 -> V_148 ) ,
F_34 ( V_549 -> V_146 . V_147 ) , F_16 ( V_549 -> V_148 ) ,
F_148 ( V_180 -> V_203 -> V_124 ) ,
F_148 ( V_180 -> V_203 -> V_468 ) ,
V_20 ) ;
V_7 -> V_424 ( V_7 ) ;
F_149 ( & V_180 -> V_368 ) ;
V_483 . V_6 = V_578 ;
V_483 . V_516 = 0 ;
V_483 . V_521 = ( void * ) V_180 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
V_483 . V_553 = V_2 -> V_55 ;
V_483 . V_554 = V_2 -> V_56 ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
V_537 . V_579 = V_500 ;
F_165 ( & V_180 -> V_368 , & V_537 , V_580 , NULL ) ;
if ( V_2 -> V_316 ) {
V_2 -> V_316 -> V_54 =
V_180 -> V_416 ;
memcpy ( V_2 -> V_316 -> V_73 ,
V_533 -> V_417 , V_533 -> V_416 ) ;
F_5 ( V_2 -> V_316 , V_394 ) ;
}
if ( V_173 )
F_88 ( V_340 L_139
L_140 , V_67 , __LINE__ , V_173 ) ;
return 0 ;
}
int F_166 ( struct V_232 * V_7 , const void * V_581 , T_1 V_582 )
{
struct V_1 * V_2 ;
struct V_1 * V_315 ;
struct V_165 * V_3 ;
T_1 * V_19 ;
F_48 ( & V_583 ) ;
V_2 = (struct V_1 * ) V_7 -> V_521 ;
V_315 = V_2 -> V_316 ;
V_3 = V_2 -> V_3 ;
V_2 -> V_7 = V_7 ;
if ( V_582 + sizeof( struct V_36 ) > V_26 )
return - V_43 ;
if ( V_315 ) {
memcpy ( & V_315 -> V_25 . V_555 , V_581 , V_582 ) ;
V_315 -> V_25 . V_41 = V_582 ;
V_315 -> V_54 = V_582 ;
} else {
V_19 = & V_2 -> V_73 [ 0 ] + sizeof( struct V_36 ) ;
V_2 -> V_54 = V_582 ;
memcpy ( V_19 , V_581 , V_582 ) ;
}
return V_3 -> V_441 -> V_584 ( V_3 , V_2 ) ;
}
int F_167 ( struct V_232 * V_7 , struct V_532 * V_533 )
{
struct V_534 * V_368 ;
struct V_177 * V_180 ;
struct V_155 * V_156 ;
struct V_355 * V_320 ;
struct V_1 * V_2 ;
struct V_149 V_9 ;
int V_365 = 0 ;
struct V_142 * V_549 = (struct V_142 * ) & V_7 -> V_517 ;
struct V_142 * V_550 = (struct V_142 * ) & V_7 -> V_518 ;
struct V_157 V_410 ;
struct V_153 V_154 ;
int V_411 = 0 ;
if ( V_7 -> V_518 . V_585 != V_145 )
return - V_586 ;
V_368 = F_159 ( V_7 -> V_495 , V_533 -> V_551 ) ;
if ( ! V_368 )
return - V_43 ;
V_180 = F_160 ( V_368 ) ;
if ( ! V_180 )
return - V_43 ;
V_156 = F_153 ( V_180 -> V_368 . V_495 ) ;
if ( ! V_156 )
return - V_43 ;
V_320 = V_156 -> V_320 ;
if ( ! V_320 )
return - V_43 ;
if ( ! V_549 -> V_148 || ! V_550 -> V_148 )
return - V_43 ;
F_7 ( V_14 , L_141
L_142 , V_180 -> V_183 . V_243 ,
F_34 ( V_156 -> V_587 ) , F_34 ( V_550 -> V_146 . V_147 ) ,
F_16 ( V_550 -> V_148 ) , F_34 ( V_549 -> V_146 . V_147 ) ,
F_16 ( V_549 -> V_148 ) ) ;
F_48 ( & V_588 ) ;
V_180 -> V_525 = 1 ;
V_180 -> V_7 = V_7 ;
V_7 -> V_521 = V_180 ;
V_180 -> V_416 = V_533 -> V_416 ;
F_7 ( V_14 , L_143 , ( T_3 ) V_533 -> V_554 ) ;
F_7 ( V_14 , L_144 ,
V_533 -> V_416 ) ;
V_9 . V_11 = F_34 ( V_549 -> V_146 . V_147 ) ;
V_9 . V_13 = F_16 ( V_549 -> V_148 ) ;
V_9 . V_10 = F_34 ( V_550 -> V_146 . V_147 ) ;
V_9 . V_12 = F_16 ( V_550 -> V_148 ) ;
V_9 . V_7 = V_7 ;
V_9 . V_364 = V_589 ;
V_9 . V_114 = V_9 . V_11 ;
V_9 . V_118 = V_9 . V_13 ;
V_9 . V_116 = V_9 . V_10 ;
V_9 . V_120 = V_9 . V_12 ;
F_32 ( V_156 , & V_410 ) ;
V_411 = F_125 ( & V_410 , V_152 ) ;
if ( V_411 ) {
F_7 ( V_324 ,
L_87 , V_411 ) ;
}
if ( F_126 () && ! V_411 ) {
F_31 ( & V_9 , & V_154 ) ;
V_411 = F_168 ( & V_154 , V_152 ) ;
if ( V_411 )
F_7 ( V_324 ,
L_88 , V_411 ) ;
else
F_33 ( & V_9 , & V_154 ) ;
}
if ( V_549 -> V_146 . V_147 != V_550 -> V_146 . V_147 ) {
F_80 ( V_156 , V_9 . V_118 ,
F_81 ( V_320 -> V_321 -> V_322 ) , V_590 ) ;
V_365 = 1 ;
}
if ( F_26 ( & V_9 ) )
return - V_27 ;
V_7 -> V_424 ( V_7 ) ;
V_2 = V_257 -> V_441 -> V_591 ( V_257 , V_156 ,
V_533 -> V_416 , ( void * ) V_533 -> V_417 ,
& V_9 ) ;
if ( ! V_2 ) {
if ( V_365 )
F_80 ( V_156 , V_9 . V_118 ,
F_81 ( V_320 -> V_321 -> V_322 ) ,
V_323 ) ;
F_7 ( V_324 , L_145 ,
V_9 . V_118 ) ;
F_28 ( V_9 . V_11 , V_9 . V_13 ,
V_9 . V_114 , V_9 . V_118 ) ;
V_7 -> V_238 ( V_7 ) ;
return - V_27 ;
}
F_37 ( V_2 , ( T_2 ) V_533 -> V_553 , ( T_2 ) V_533 -> V_554 ) ;
if ( V_2 -> V_69 == V_70 &&
V_2 -> V_56 == 0 )
V_2 -> V_56 = 1 ;
V_2 -> V_365 = V_365 ;
V_180 -> V_2 = V_2 ;
V_2 -> V_180 = V_180 ;
F_149 ( & V_180 -> V_368 ) ;
return 0 ;
}
int F_169 ( struct V_232 * V_7 , int V_396 )
{
struct V_155 * V_156 ;
struct V_295 * V_2 ;
struct V_149 V_9 ;
int V_309 ;
struct V_142 * V_549 = (struct V_142 * ) & V_7 -> V_517 ;
F_7 ( V_14 , L_146 ,
V_7 , F_16 ( V_549 -> V_148 ) ) ;
if ( V_7 -> V_517 . V_585 != V_145 )
return - V_586 ;
V_156 = F_153 ( V_7 -> V_495 ) ;
if ( ! V_156 )
return - V_43 ;
F_7 ( V_14 , L_147 ,
V_156 , V_156 -> V_90 , V_156 -> V_90 -> V_161 ) ;
F_7 ( V_14 , L_148 ,
V_156 -> V_587 , V_549 -> V_146 . V_147 ) ;
V_9 . V_11 = F_34 ( V_156 -> V_587 ) ;
V_9 . V_13 = F_16 ( V_549 -> V_148 ) ;
V_9 . V_396 = V_396 ;
V_9 . V_7 = V_7 ;
V_9 . V_364 = V_589 ;
V_9 . V_114 = V_9 . V_11 ;
V_9 . V_118 = V_9 . V_13 ;
V_2 = V_257 -> V_441 -> V_592 ( V_257 , V_156 , & V_9 ) ;
if ( ! V_2 ) {
F_88 ( V_340 L_149 ,
V_67 , __LINE__ ) ;
return - V_27 ;
}
V_7 -> V_521 = V_2 ;
if ( ! V_2 -> V_414 ) {
if ( F_26 ( & V_9 ) )
return - V_27 ;
V_309 = F_80 ( V_156 , V_2 -> V_118 ,
F_81 ( V_156 -> V_320 -> V_321 -> V_322 ) ,
V_590 ) ;
if ( V_309 ) {
F_88 ( V_340 L_150 ,
V_309 ) ;
V_257 -> V_441 -> V_593 ( V_257 , ( void * ) V_2 ) ;
return V_309 ;
}
F_48 ( & V_594 ) ;
}
V_7 -> V_424 ( V_7 ) ;
V_7 -> V_521 = ( void * ) V_2 ;
return 0 ;
}
int F_170 ( struct V_232 * V_7 )
{
if ( V_7 -> V_521 )
V_257 -> V_441 -> V_593 ( V_257 , V_7 -> V_521 ) ;
else
F_7 ( V_14 , L_151 ) ;
V_7 -> V_238 ( V_7 ) ;
return 0 ;
}
int F_171 ( struct V_15 * V_16 , struct V_336 * V_595 )
{
int V_335 = 0 ;
V_596 ++ ;
if ( ( V_257 ) && ( V_257 -> V_441 ) )
V_335 = V_257 -> V_441 -> V_597 ( V_257 , F_172 ( V_595 ) , V_16 ) ;
else
F_7 ( V_14 , L_152
L_153 ) ;
return V_335 ;
}
int F_173 ( void )
{
F_7 ( V_14 , L_109 ) ;
V_257 = F_138 () ;
if ( V_257 )
return 0 ;
else
return - V_27 ;
}
int F_174 ( void )
{
V_257 -> V_441 -> V_598 ( V_257 ) ;
return 0 ;
}
static void F_175 ( struct V_4 * V_6 )
{
struct V_177 * V_180 ;
struct V_155 * V_156 ;
struct V_355 * V_320 ;
struct V_1 * V_2 ;
struct V_337 * V_338 ;
struct V_536 V_537 ;
struct V_232 * V_7 ;
struct V_482 V_483 ;
struct V_538 V_539 ;
T_3 V_540 ;
int V_173 ;
struct V_142 * V_549 ;
struct V_142 * V_550 ;
struct V_142 * V_599 ;
V_2 = V_6 -> V_2 ;
V_7 = V_2 -> V_7 ;
F_7 ( V_14 , L_154 , V_2 , V_7 ) ;
V_180 = (struct V_177 * ) V_7 -> V_521 ;
V_156 = F_153 ( V_180 -> V_368 . V_495 ) ;
V_320 = V_156 -> V_320 ;
V_338 = V_320 -> V_338 ;
V_549 = (struct V_142 * ) & V_7 -> V_517 ;
V_550 = (struct V_142 * ) & V_7 -> V_518 ;
V_599 = (struct V_142 * ) & V_483 . V_517 ;
if ( V_180 -> V_505 )
return;
F_48 ( & V_600 ) ;
F_7 ( V_14 , L_155
L_156 ,
V_180 -> V_183 . V_243 , F_34 ( V_550 -> V_146 . V_147 ) ,
F_16 ( V_550 -> V_148 ) , F_16 ( V_549 -> V_148 ) , V_220 ) ;
F_147 ( V_180 , V_2 ) ;
V_180 -> V_203 -> V_565 [ 0 ] =
F_162 ( V_2 -> V_118 ) ;
V_180 -> V_203 -> V_565 [ 1 ] =
F_162 ( V_2 -> V_120 ) ;
V_180 -> V_203 -> V_566 = F_42 ( V_2 -> V_116 ) ;
V_180 -> V_203 -> V_455 |= F_42 (
( T_3 ) F_81 ( V_320 -> V_321 -> V_322 ) <<
V_567 ) ;
V_180 -> V_203 -> V_568 |= F_42 (
F_95 ( V_320 ,
F_148 ( V_180 -> V_203 -> V_566 ) ,
NULL , V_351 ) << 16 ) ;
V_180 -> V_203 -> V_569 = F_42 (
V_220 - F_163 ( V_320 , V_570 ) ) ;
V_180 -> V_203 -> V_571 = F_42 ( V_180 -> V_183 . V_243 ) ;
V_180 -> V_203 -> V_204 |=
F_42 ( ( T_3 ) 1 <<
V_572 ) ;
V_180 -> V_203 -> V_204 |=
F_42 ( ( T_3 ) V_2 -> V_56 ) ;
F_40 ( V_2 , & V_180 ) ;
F_176 ( V_320 -> V_601 + V_602 ,
( 1 << 24 ) | 0x00800000 | V_180 -> V_183 . V_243 ) ;
memset ( & V_539 , 0 , sizeof( V_539 ) ) ;
V_539 . V_573 =
F_42 ( ( T_3 ) F_81 ( V_320 -> V_321 -> V_322 ) << 24 ) ;
V_539 . V_574 = F_23 ( V_2 -> V_116 ) ;
V_539 . V_575 [ 0 ] = F_22 ( V_2 -> V_120 ) ;
V_539 . V_575 [ 1 ] = F_22 ( V_2 -> V_118 ) ;
V_540 = F_164 ( & V_539 ) ;
V_180 -> V_576 = F_135 ( V_540 ^ 0xffffffff ) ;
F_7 ( V_14 , L_157 ,
V_180 -> V_576 , V_180 -> V_576 & V_338 -> V_577 ) ;
V_180 -> V_576 &= V_338 -> V_577 ;
V_180 -> V_203 -> V_576 = F_42 ( V_180 -> V_576 ) ;
V_180 -> V_526 = & V_2 -> V_25 ;
V_180 -> V_416 = ( T_1 ) V_2 -> V_54 ;
V_2 -> V_3 -> V_441 -> V_313 ( V_2 -> V_3 , V_2 ) ;
V_483 . V_6 = V_603 ;
V_483 . V_516 = 0 ;
V_483 . V_521 = V_7 -> V_521 ;
V_599 -> V_144 = V_145 ;
V_599 -> V_148 = V_549 -> V_148 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = ( void * ) V_6 -> V_2 -> V_73 ;
V_483 . V_416 = ( T_1 ) V_6 -> V_2 -> V_54 ;
V_483 . V_553 = V_2 -> V_55 ;
V_483 . V_554 = V_2 -> V_56 ;
V_599 -> V_146 . V_147 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
F_7 ( V_14 , L_125 , V_173 ) ;
if ( V_173 )
F_88 ( V_340 L_139
L_140 , V_67 , __LINE__ , V_173 ) ;
V_537 . V_579 = V_500 ;
F_165 ( & V_180 -> V_368 , & V_537 , V_580 , NULL ) ;
F_7 ( V_14 , L_158
L_159 , V_180 -> V_183 . V_243 , V_220 ) ;
return;
}
static void F_76 ( struct V_4 * V_6 )
{
struct V_177 * V_180 ;
struct V_232 * V_7 ;
struct V_482 V_483 ;
int V_173 ;
if ( ! V_6 -> V_2 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
if ( ! V_7 )
return;
F_7 ( V_14 , L_160 , V_6 -> V_2 , V_7 ) ;
V_180 = V_7 -> V_521 ;
if ( ! V_180 )
return;
V_180 -> V_7 = NULL ;
V_7 -> V_521 = NULL ;
V_483 . V_6 = V_603 ;
V_483 . V_516 = - V_502 ;
V_483 . V_521 = V_7 -> V_521 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
#ifdef F_177
{
struct V_142 * V_599 = (struct V_142 * )
& V_483 . V_517 ;
struct V_142 * V_604 = (struct V_142 * )
& V_483 . V_518 ;
F_7 ( V_14 , L_161 ,
V_599 -> V_146 . V_147 , V_604 -> V_146 . V_147 ) ;
}
#endif
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
F_7 ( V_14 , L_125 , V_173 ) ;
if ( V_173 )
F_88 ( V_340 L_139
L_140 , V_67 , __LINE__ , V_173 ) ;
V_7 -> V_238 ( V_7 ) ;
F_4 ( V_6 -> V_2 -> V_3 , V_6 -> V_2 ) ;
return;
}
static void F_178 ( struct V_4 * V_6 )
{
struct V_177 * V_180 ;
struct V_232 * V_7 ;
struct V_482 V_483 ;
int V_173 ;
if ( ! V_6 -> V_2 )
return;
if ( ! V_6 -> V_2 -> V_7 )
return;
V_7 = V_6 -> V_2 -> V_7 ;
F_7 ( V_14 , L_162 , V_6 -> V_2 , V_7 ) ;
V_180 = V_7 -> V_521 ;
if ( ! V_180 )
return;
V_180 -> V_7 = NULL ;
V_483 . V_6 = V_515 ;
V_483 . V_516 = - V_502 ;
V_483 . V_521 = V_7 -> V_521 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
V_7 -> V_424 ( V_7 ) ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
F_48 ( & V_520 ) ;
V_483 . V_6 = V_522 ;
V_483 . V_516 = 0 ;
V_483 . V_521 = V_7 -> V_521 ;
V_483 . V_517 = V_7 -> V_517 ;
V_483 . V_518 = V_7 -> V_518 ;
V_483 . V_417 = NULL ;
V_483 . V_416 = 0 ;
F_7 ( V_14 , L_163 , V_6 -> V_2 ) ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
F_7 ( V_14 , L_125 , V_173 ) ;
V_7 -> V_238 ( V_7 ) ;
return;
}
static void F_179 ( struct V_4 * V_6 )
{
struct V_232 * V_7 ;
struct V_482 V_483 ;
int V_173 ;
struct V_1 * V_2 ;
struct V_142 * V_599 = (struct V_142 * )
& V_483 . V_517 ;
struct V_142 * V_604 = (struct V_142 * )
& V_483 . V_518 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_48 ( & V_605 ) ;
F_7 ( V_14 , L_164 ,
V_2 , V_7 , V_220 ) ;
V_483 . V_6 = V_606 ;
V_483 . V_516 = 0 ;
V_483 . V_521 = ( void * ) V_2 ;
V_599 -> V_144 = V_145 ;
V_599 -> V_148 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_599 -> V_146 . V_147 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_604 -> V_144 = V_145 ;
V_604 -> V_148 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_604 -> V_146 . V_147 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_483 . V_417 = V_2 -> V_73 ;
V_483 . V_416 = ( T_1 ) V_2 -> V_54 ;
if ( V_2 -> V_48 == V_46 ) {
V_483 . V_553 = V_65 ;
V_483 . V_554 = V_68 ;
} else {
V_483 . V_553 = V_2 -> V_55 ;
V_483 . V_554 = V_2 -> V_56 ;
}
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
if ( V_173 )
F_88 ( V_340 L_165 ,
V_67 , __LINE__ , V_173 ) ;
return;
}
static void F_132 ( struct V_4 * V_6 )
{
struct V_232 * V_7 ;
struct V_482 V_483 ;
struct V_1 * V_2 ;
int V_173 ;
struct V_142 * V_599 = (struct V_142 * )
& V_483 . V_517 ;
struct V_142 * V_604 = (struct V_142 * )
& V_483 . V_518 ;
V_2 = V_6 -> V_2 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_7 ;
F_48 ( & V_605 ) ;
F_7 ( V_14 , L_164 ,
V_2 , V_7 , V_220 ) ;
V_483 . V_6 = V_603 ;
V_483 . V_516 = - V_607 ;
V_483 . V_521 = V_7 -> V_521 ;
V_599 -> V_144 = V_145 ;
V_599 -> V_148 = F_22 ( V_6 -> V_9 . V_13 ) ;
V_599 -> V_146 . V_147 = F_23 ( V_6 -> V_9 . V_11 ) ;
V_604 -> V_144 = V_145 ;
V_604 -> V_148 = F_22 ( V_6 -> V_9 . V_12 ) ;
V_604 -> V_146 . V_147 = F_23 ( V_6 -> V_9 . V_10 ) ;
V_483 . V_417 = V_2 -> V_73 ;
V_483 . V_416 = ( T_1 ) V_2 -> V_54 ;
F_7 ( V_14 , L_166
L_167 ,
V_599 -> V_146 . V_147 ,
V_604 -> V_146 . V_147 ) ;
V_173 = V_7 -> V_512 ( V_7 , & V_483 ) ;
if ( V_173 )
F_88 ( V_340 L_165 ,
V_67 , __LINE__ , V_173 ) ;
return;
}
static int F_8 ( struct V_4 * V_6 )
{
F_48 ( & V_6 -> V_2 -> V_3 -> V_440 ) ;
F_2 ( V_6 -> V_2 ) ;
V_6 -> V_9 . V_7 -> V_424 ( V_6 -> V_9 . V_7 ) ;
F_150 ( & V_6 -> V_608 , V_609 ) ;
F_7 ( V_14 , L_168 ,
V_6 -> V_2 , V_6 ) ;
F_151 ( V_6 -> V_2 -> V_3 -> V_443 , & V_6 -> V_608 ) ;
F_7 ( V_14 , L_169 ) ;
return 0 ;
}
static void V_609 ( struct V_480 * V_478 )
{
struct V_4 * V_6 = F_62 ( V_478 , struct V_4 ,
V_608 ) ;
struct V_165 * V_3 ;
if ( ( ! V_6 ) || ( ! V_6 -> V_2 ) || ( ! V_6 -> V_2 -> V_3 ) )
return;
V_3 = V_6 -> V_2 -> V_3 ;
F_7 ( V_14 , L_170 ,
V_6 , V_6 -> type , F_36 ( & V_3 -> V_440 ) ) ;
switch ( V_6 -> type ) {
case V_391 :
F_179 ( V_6 ) ;
F_7 ( V_14 , L_171 ,
V_6 -> V_2 ) ;
break;
case V_610 :
F_7 ( V_14 , L_172 ,
V_6 -> V_2 ) ;
F_178 ( V_6 ) ;
break;
case V_394 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 != V_263 ) )
break;
F_175 ( V_6 ) ;
F_7 ( V_14 , L_173 ) ;
break;
case V_393 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_263 ) )
break;
F_132 ( V_6 ) ;
F_7 ( V_14 , L_174 ) ;
break;
case V_239 :
if ( ( ! V_6 -> V_2 -> V_7 ) ||
( V_6 -> V_2 -> V_32 == V_263 ) )
break;
F_76 ( V_6 ) ;
F_7 ( V_14 , L_175 ) ;
break;
case V_611 :
F_7 ( V_14 , L_176 ) ;
break;
default:
F_7 ( V_14 , L_177 ) ;
break;
}
F_79 ( & V_3 -> V_440 ) ;
V_6 -> V_9 . V_7 -> V_238 ( V_6 -> V_9 . V_7 ) ;
F_4 ( V_3 , V_6 -> V_2 ) ;
F_45 ( V_6 ) ;
return;
}
