static inline bool F_1 ( T_1 V_1 )
{
return ( V_1 >= V_2 ) &&
( V_1 <= V_3 ) ;
}
static inline bool F_2 ( T_2 V_4 )
{
return ( V_4 == V_5 ) || ( V_4 == V_6 ) ;
}
static inline bool F_3 ( T_2 V_4 )
{
return ( V_4 == V_7 ) || ( V_4 == V_8 ) ;
}
static inline bool F_4 ( T_2 V_4 )
{
return F_2 ( V_4 ) ||
F_3 ( V_4 ) ;
}
static inline int F_5 ( struct V_9 * V_10 , T_2 * V_4 )
{
* V_4 = ( (struct V_11 * ) F_6 ( V_10 ) ) -> V_12 ;
if ( ! F_4 ( * V_4 ) )
return - V_13 ;
return 0 ;
}
static inline bool F_7 ( T_2 V_14 )
{
return ( V_14 == V_15 ) || ( V_14 == V_16 ) ||
( V_14 == V_17 ) || ( V_14 == V_18 ) ;
}
static inline int F_8 ( struct V_9 * V_10 , T_2 * V_14 )
{
F_9 ( V_10 , V_10 -> V_19 - 4 , V_14 , 1 ) ;
if ( ! F_7 ( * V_14 ) )
return - V_13 ;
return 0 ;
}
static inline T_3 F_10 ( T_2 V_14 )
{
switch ( V_14 ) {
case V_15 :
return V_20 ;
case V_16 :
return V_21 ;
case V_17 :
return V_22 ;
case V_18 :
return V_23 ;
default:
F_11 ( 1 ) ;
return - V_13 ;
}
}
static inline bool F_12 ( T_1 V_24 )
{
return ( V_24 != V_25 ) && ( V_24 < V_26 ) ;
}
static inline void F_13 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
if ( F_14 ( V_31 , & V_30 -> V_32 ) )
return;
if ( V_30 -> V_33 ) {
F_15 ( & V_28 -> V_34 -> V_35 , V_30 -> V_33 , V_30 -> V_36 ,
V_37 ) ;
V_30 -> V_33 = NULL ;
V_30 -> V_36 = 0 ;
}
if ( V_30 -> V_38 ) {
F_16 ( V_30 -> V_38 , V_30 -> V_39 , V_30 -> V_40 ) ;
V_30 -> V_38 = NULL ;
}
}
static inline void F_17 ( struct V_29 * V_30 )
{
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_24 = V_25 ;
V_30 -> V_32 = V_41 ;
}
static inline bool F_18 ( T_2 V_42 )
{
return ( V_42 == V_43 ) ||
( V_42 == V_44 ) ;
}
static inline T_1 F_19 ( struct V_45 * V_46 )
{
T_3 V_47 = F_20 ( V_46 -> V_48 ) ;
return ( V_47 & V_49 ) ?
F_21 ( V_46 -> V_50 ) :
F_21 ( V_46 -> V_51 ) ;
}
static inline struct V_45 * F_22 (
struct V_9 * V_10 )
{
void * V_46 = V_10 -> V_52 + sizeof( struct V_11 ) ;
if ( F_23 ( V_10 ) -> V_53 == F_24 ( V_54 ) )
V_46 += sizeof( struct V_55 ) ;
return (struct V_45 * ) V_46 ;
}
static int F_25 ( struct V_56 * V_57 , T_1 V_24 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_27 * V_28 = V_59 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
int V_19 = 0 ;
struct V_29 * V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ! V_63 || ! V_30 )
goto V_64;
if ( F_27 ( V_65 , & V_30 -> V_32 ) )
V_19 = V_30 -> V_19 ;
F_13 ( V_28 , V_30 ) ;
V_64:
return V_19 ;
}
int F_28 ( struct V_27 * V_28 )
{
struct V_66 * V_67 = & V_28 -> V_67 ;
T_3 V_68 ;
V_28 -> V_32 &= ~ V_69 ;
V_28 -> V_70 = 0 ;
V_28 -> V_71 = 0 ;
V_28 -> V_72 = 0 ;
if ( ! V_28 -> V_67 . V_73 . V_63 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_1 ) ;
return 0 ;
}
if ( ! V_28 -> V_67 . V_73 . V_74 ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_2 ) ;
return 0 ;
}
V_68 = F_31 ( V_67 , F_32 ( 1 ) ) ;
V_68 |= 1 << ( V_75 - 32 ) ;
V_68 |= 1 << ( V_76 - 32 ) ;
V_68 &= V_77 ;
F_33 ( V_67 , F_32 ( 1 ) , V_68 ) ;
V_28 -> V_32 |= V_69 ;
V_28 -> V_70 = V_78 ;
V_28 -> V_71 = ( 1 << V_79 ) *
V_80 ;
V_28 -> V_72 = V_28 -> V_71 +
( 1 << V_81 ) *
V_82 ;
V_28 -> V_83 . V_84 = V_81 ;
V_28 -> V_83 . V_85 = V_79 ;
V_68 = F_31 ( V_67 , V_86 ) ;
V_68 &= ~ V_87 ;
V_68 |= ( ( V_88 + V_89 + V_90 + V_91 )
<< V_92 ) ;
F_33 ( V_67 , V_86 , V_68 ) ;
F_29 ( & V_28 -> V_34 -> V_35 , L_3 ) ;
return 0 ;
}
T_2 F_34 ( struct V_27 * V_28 )
{
struct V_93 V_94 ;
struct V_66 * V_67 = & V_28 -> V_67 ;
T_2 V_95 = 0 ;
T_2 V_96 , V_97 ;
struct V_98 * V_99 = & V_67 -> V_100 ;
for ( V_97 = 0 ; V_97 < V_99 -> V_101 ; V_97 ++ ) {
V_94 = V_99 -> V_94 [ V_97 ] ;
if ( V_94 . V_102 == V_103 &&
V_94 . V_104 == V_105 ) {
V_96 = V_99 -> V_106 . V_107 [ V_94 . V_108 ] ;
V_95 |= ( 1 << V_96 ) ;
break;
}
}
V_95 = V_95 ? V_95 : 0x1 ;
return V_95 ;
}
int F_35 ( struct V_109 * V_60 , struct V_110 * V_111 )
{
struct V_112 * V_113 = & V_111 -> V_113 ;
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_66 * V_67 = & V_28 -> V_67 ;
T_2 V_95 = 0 ;
if ( ! ( V_28 -> V_32 & V_69 ) ) {
F_36 ( & V_28 -> V_34 -> V_35 ,
L_4 ) ;
return - V_114 ;
}
V_111 -> V_115 = V_67 -> V_116 ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = V_60 -> V_118 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_32 = V_121 ;
V_113 -> V_122 |= F_37 ( V_123 ) ;
V_113 -> V_122 &= F_37 ( ~ ( V_124 |
V_125 |
V_126 |
V_127 |
V_128 ) ) ;
if ( F_38 ( V_60 ) ) {
V_113 -> V_122 |=
F_37 ( V_129 ) ;
V_113 -> V_130 =
F_37 ( V_131 ) ;
}
V_95 = F_34 ( V_28 ) ;
F_39 ( V_60 , V_111 , V_95 , true ) ;
V_113 -> V_132 = V_133 ;
return 0 ;
}
int F_40 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
if ( ! ( V_28 -> V_32 & V_69 ) ) {
F_41 ( V_57 , L_5 ) ;
return - V_134 ;
}
if ( V_60 -> type != V_135 ) {
F_41 ( V_57 , L_6 ) ;
return - V_136 ;
}
F_42 ( & V_63 -> V_137 ) ;
return 0 ;
}
int F_43 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
if ( ! ( V_28 -> V_32 & V_69 ) ) {
F_41 ( V_57 , L_7 ) ;
return - V_134 ;
}
if ( V_60 -> type != V_135 )
return - V_136 ;
if ( ! F_44 ( & V_63 -> V_137 ) )
return - V_13 ;
F_45 ( V_57 , L_8 ) ;
return 0 ;
}
static void F_46 ( struct V_62 * V_63 ,
struct V_138 * V_35 ,
unsigned int V_139 )
{
struct V_140 * V_141 ;
V_141 = F_47 ( V_63 -> V_141 , V_139 ) ;
if ( ! V_141 -> V_38 ) {
F_30 ( V_35 , L_9 , V_139 ) ;
return;
}
F_48 ( V_141 -> V_38 ) ;
V_141 -> V_38 = NULL ;
}
static int F_49 ( struct V_62 * V_63 ,
struct V_138 * V_35 ,
unsigned int V_139 )
{
struct V_140 * V_141 ;
struct V_142 * V_38 ;
char V_143 [ 32 ] ;
V_141 = F_47 ( V_63 -> V_141 , V_139 ) ;
if ( V_141 && V_141 -> V_38 ) {
F_30 ( V_35 , L_10 , V_139 ) ;
return 0 ;
}
snprintf ( V_143 , sizeof( V_143 ) , L_11 , V_139 ) ;
V_38 = F_50 ( V_143 , V_35 , V_144 ,
V_145 , V_146 ) ;
if ( ! V_38 ) {
F_36 ( V_35 , L_12 , V_143 ) ;
return - V_147 ;
}
V_141 -> V_38 = V_38 ;
return 0 ;
}
void F_51 ( struct V_109 * V_60 )
{
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
int V_139 , V_97 ;
if ( V_60 -> type != V_135 )
return;
if ( ! V_63 -> V_141 )
return;
for ( V_97 = 0 ; V_97 < V_26 ; V_97 ++ )
F_25 ( V_60 -> V_57 , V_97 ) ;
F_52 (cpu)
F_46 ( V_63 , & V_28 -> V_34 -> V_35 , V_139 ) ;
F_53 ( V_63 -> V_141 ) ;
V_63 -> V_141 = NULL ;
F_45 ( V_60 -> V_57 , L_13 ,
V_60 -> V_42 , V_60 -> V_148 ) ;
}
int F_54 ( struct V_109 * V_60 )
{
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_138 * V_35 = & V_28 -> V_34 -> V_35 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
unsigned int V_139 ;
int V_97 ;
if ( V_60 -> type != V_135 )
return - V_134 ;
if ( V_63 -> V_141 )
return - V_149 ;
V_63 -> V_141 = F_55 ( struct V_140 ) ;
if ( ! V_63 -> V_141 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_14 ) ;
return - V_147 ;
}
F_52 (cpu) {
if ( ! F_49 ( V_63 , V_35 , V_139 ) )
continue;
F_36 ( V_35 , L_15 , V_139 ) ;
F_51 ( V_60 ) ;
return - V_147 ;
}
for ( V_97 = 0 ; V_97 < V_26 ; V_97 ++ )
F_17 ( & V_63 -> V_30 [ V_97 ] ) ;
F_45 ( V_60 -> V_57 , L_16 ,
V_60 -> V_42 , V_60 -> V_148 ) ;
return 0 ;
}
void F_56 ( struct V_150 * V_151 ,
union V_152 * V_153 , T_2 V_154 )
{
struct V_27 * V_28 = V_151 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_29 * V_30 ;
T_3 error ;
T_1 V_24 ;
T_4 V_155 ;
if ( ! F_18 ( V_154 ) )
return;
V_24 = F_57 ( V_153 -> V_156 . V_157 . V_158 . V_159 ) &
( V_26 - 1 ) ;
if ( ! F_12 ( V_24 ) )
return;
V_30 = & V_63 -> V_30 [ V_24 ] ;
F_11 ( V_24 != V_30 -> V_24 ) ;
V_155 = F_58 ( V_153 -> V_156 . V_160 . V_161 ) ;
error = ( V_155 & V_162 ) >>
V_163 ;
if ( V_154 == V_43 ) {
if ( F_59 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_17 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_164 |= V_165 ;
}
if ( F_60 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_18 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_164 |= V_166 ;
}
}
if ( V_154 == V_44 ) {
if ( F_61 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_19 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_164 |= V_167 ;
}
F_62 ( V_168 , & V_30 -> V_32 ) ;
}
F_13 ( V_28 , V_30 ) ;
F_17 ( V_30 ) ;
}
int F_63 ( struct V_150 * V_151 ,
union V_152 * V_153 ,
struct V_9 * V_10 )
{
struct V_27 * V_28 = V_151 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_45 * V_46 = NULL ;
struct V_29 * V_30 = NULL ;
T_3 V_169 , V_170 ;
T_3 error , V_171 ;
int V_172 = - V_13 ;
T_1 V_1 ;
T_1 V_24 ;
T_4 V_155 ;
V_155 = F_58 ( V_153 -> V_156 . V_160 . V_161 ) ;
V_1 = ( V_155 & V_173 ) >> V_174 ;
if ( ! F_1 ( V_1 ) )
goto V_175;
error = ( V_155 & V_176 ) >> V_177 ;
V_171 = ( error >> V_178 ) &
V_179 ;
if ( F_64 ( V_171 == V_180 ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_20 ) ;
V_10 -> V_181 = V_182 ;
} else {
V_10 -> V_181 = V_183 ;
}
V_169 = ( V_155 & V_184 ) >> V_185 ;
V_170 = ( V_169 >> V_186 ) &
V_187 ;
V_46 = F_22 ( V_10 ) ;
V_24 = F_19 ( V_46 ) ;
if ( ! F_12 ( V_24 ) )
goto V_175;
if ( V_170 == V_188 )
goto V_175;
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ! V_30 -> V_33 )
goto V_175;
V_24 = F_65 ( V_153 -> V_156 . V_157 . V_189 . V_190 . V_191 ) ;
if ( V_30 -> V_24 != V_24 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_21 ,
V_30 -> V_24 , V_24 ) ;
goto V_192;
}
if ( V_30 -> V_171 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_22 ,
V_24 , V_30 -> V_171 , V_171 ) ;
goto V_192;
}
V_30 -> V_19 = F_57 ( V_153 -> V_156 . V_157 . V_158 . V_159 ) ;
V_30 -> V_171 = V_171 ;
if ( V_170 == V_193 ) {
T_3 V_47 = F_20 ( V_46 -> V_48 ) ;
if ( ( V_47 & V_194 ) &&
( V_46 -> V_195 == V_196 ) ) {
struct V_197 * V_198 = NULL ;
V_198 = (struct V_197 * ) F_66 ( V_10 , sizeof( * V_198 ) ) ;
V_198 -> V_199 = V_16 ;
} else {
V_172 = 0 ;
goto V_175;
}
}
V_192:
F_13 ( V_28 , V_30 ) ;
if ( V_30 -> V_19 && ! V_30 -> V_171 ) {
int V_200 ;
V_172 = V_30 -> V_19 ;
F_17 ( V_30 ) ;
V_30 -> V_19 = V_172 ;
V_200 = F_67 ( V_172 , 2048 ) ;
V_151 -> V_201 . V_202 += V_172 ;
V_151 -> V_201 . V_203 += V_200 ;
V_151 -> V_204 -> V_205 . V_206 += V_172 ;
V_151 -> V_204 -> V_205 . V_207 += V_200 ;
F_68 ( V_65 , & V_30 -> V_32 ) ;
}
V_175:
return V_172 ;
}
static int F_69 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_208 * V_33 , unsigned int V_36 ,
int V_209 )
{
static const unsigned int V_210 = V_211 ;
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_140 * V_141 ;
struct V_27 * V_28 = V_59 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
unsigned int V_97 , V_212 , V_213 ;
struct V_29 * V_30 ;
unsigned int V_214 = 0 ;
unsigned int V_215 = 0 ;
unsigned int V_216 = 0 ;
struct V_208 * V_217 ;
T_5 V_218 = 0 ;
unsigned int V_19 ;
if ( V_24 >= V_26 ) {
F_30 ( & V_28 -> V_34 -> V_35 , L_23 , V_24 ) ;
return 0 ;
}
if ( F_27 ( V_219 , & V_28 -> V_220 ) ||
F_27 ( V_221 , & V_28 -> V_220 ) ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_24 ,
V_24 ) ;
return 0 ;
}
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( V_30 -> V_33 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_25 ,
V_24 , V_30 -> V_33 , V_30 -> V_36 ) ;
return 0 ;
}
F_17 ( V_30 ) ;
if ( ! V_63 -> V_141 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_26 , V_24 ) ;
return 0 ;
}
V_141 = F_47 ( V_63 -> V_141 , F_70 () ) ;
if ( ! V_141 -> V_38 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_27 , V_24 ) ;
goto V_222;
}
V_213 = F_71 ( & V_28 -> V_34 -> V_35 , V_33 , V_36 , V_37 ) ;
if ( V_213 == 0 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_28 ,
V_33 , V_36 ) ;
goto V_223;
}
V_30 -> V_39 = F_72 ( V_141 -> V_38 , V_224 , & V_30 -> V_40 ) ;
if ( ! V_30 -> V_39 ) {
F_29 ( & V_28 -> V_34 -> V_35 ,
L_29 , V_24 ) ;
goto V_223;
}
V_212 = 0 ;
V_30 -> V_19 = 0 ;
F_73 (sgl, sg, dmacount, i) {
V_218 = F_74 ( V_217 ) ;
V_19 = F_75 ( V_217 ) ;
V_30 -> V_19 += V_19 ;
while ( V_19 ) {
if ( V_212 >= V_225 ) {
F_29 ( & V_28 -> V_34 -> V_35 ,
L_30 ,
V_24 , V_97 , V_212 , V_213 , ( T_4 ) V_218 ) ;
goto V_226;
}
V_215 = V_218 & ( ( T_5 ) V_210 - 1 ) ;
V_216 = F_76 (unsigned int, (bufflen - thisoff), len) ;
if ( ( V_212 != 0 ) && ( V_215 ) )
goto V_226;
if ( ( ( V_97 != ( V_213 - 1 ) ) || ( V_216 != V_19 ) ) &&
( ( V_216 + V_215 ) != V_210 ) )
goto V_226;
V_30 -> V_39 [ V_212 ] = ( T_4 ) ( V_218 - V_215 ) ;
if ( V_212 == 0 )
V_214 = V_215 ;
V_19 -= V_216 ;
V_218 += V_216 ;
V_212 ++ ;
}
}
V_30 -> V_227 = V_215 + V_216 ;
V_30 -> V_214 = V_214 ;
V_30 -> V_228 = V_212 ;
V_30 -> V_38 = V_141 -> V_38 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_36 = V_36 ;
V_30 -> V_24 = V_24 ;
if ( V_209 )
F_68 ( V_229 , & V_30 -> V_32 ) ;
F_68 ( V_230 , & V_30 -> V_32 ) ;
F_77 () ;
return 1 ;
V_226:
F_16 ( V_30 -> V_38 , V_30 -> V_39 , V_30 -> V_40 ) ;
F_17 ( V_30 ) ;
V_223:
F_15 ( & V_28 -> V_34 -> V_35 , V_33 , V_36 , V_37 ) ;
V_222:
F_77 () ;
return 0 ;
}
static int F_78 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_208 * V_33 , unsigned int V_36 )
{
return F_69 ( V_57 , V_24 , V_33 , V_36 , 0 ) ;
}
static int F_79 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_208 * V_33 , unsigned int V_36 )
{
return F_69 ( V_57 , V_24 , V_33 , V_36 , 1 ) ;
}
static void F_80 ( struct V_150 * V_231 ,
struct V_9 * V_10 ,
struct V_29 * V_30 , T_2 V_4 )
{
struct V_232 * V_233 = NULL ;
struct V_234 * V_235 = NULL ;
struct V_236 * V_237 = NULL ;
struct V_27 * V_28 = V_231 -> V_60 -> V_61 ;
T_1 V_97 = V_231 -> V_238 ;
struct V_45 * V_46 ;
T_4 V_239 = 0 ;
bool V_209 ;
if ( F_27 ( V_168 , & V_30 -> V_32 ) ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_31 ,
V_30 -> V_24 , V_30 -> V_32 ) ;
return;
}
if ( F_14 ( V_240 , & V_30 -> V_32 ) ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_32 ,
V_30 -> V_24 , V_30 -> V_32 ) ;
return;
}
V_237 = F_81 ( V_231 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_231 -> V_241 )
V_97 = 0 ;
V_237 -> V_242 =
F_82 ( V_243 |
( ( T_4 ) V_244 <<
V_245 ) |
( ( T_4 ) V_30 -> V_214 <<
V_246 ) |
( ( T_4 ) V_30 -> V_227 <<
V_247 ) ) ;
V_237 -> V_248 = F_82 ( 0 ) ;
V_209 = F_27 ( V_229 , & V_30 -> V_32 ) ;
if ( V_209 )
V_237 -> V_242 |=
F_82 ( V_249 ) ;
V_235 = F_83 ( V_231 , V_97 ++ ) ;
if ( V_97 == V_231 -> V_241 )
V_97 = 0 ;
V_235 -> V_250 = F_82 ( V_30 -> V_24 | ( ( T_4 ) V_30 -> V_40 ) ) ;
V_235 -> V_251 = F_82 ( V_30 -> V_228 |
( ( T_4 ) ( V_252 |
V_253 ) <<
V_254 ) ) ;
V_233 = F_84 ( V_231 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_231 -> V_241 )
V_97 = 0 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
V_233 -> V_255 = F_86 ( F_87 ( V_46 -> V_256 ) ) ;
V_233 -> V_257 = F_37 ( F_88 ( V_46 -> V_258 ) ) ;
V_233 -> V_259 = F_37 ( V_30 -> V_24 <<
V_260 ) ;
V_239 = V_261 ;
V_239 |= ( T_4 ) ( V_209 ?
V_262 :
V_263 ) ;
V_239 |= ( T_4 ) ( ( V_4 == V_5 || V_4 == V_6 ) ?
V_264 :
V_265 ) ;
V_239 |= ( ( T_4 ) V_10 -> V_266 <<
V_267 ) ;
V_233 -> V_239 = F_82 ( V_239 ) ;
V_231 -> V_238 = V_97 ;
}
static void F_89 ( struct V_150 * V_231 ,
struct V_9 * V_10 ,
struct V_29 * V_30 )
{
struct V_268 * V_269 ;
int V_97 ;
if ( F_14 ( V_168 , & V_30 -> V_32 ) )
return;
V_97 = V_231 -> V_238 ;
V_269 = F_90 ( V_231 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_231 -> V_241 )
V_97 = 0 ;
V_269 -> V_270 = F_86 ( 0 ) ;
V_269 -> V_271 = F_37 ( 0 ) ;
V_269 -> V_248 = F_37 ( 0 ) ;
V_269 -> V_272 = F_82 (
V_273 |
( V_274 <<
V_275 ) |
( V_276 <<
V_275 ) ) ;
V_231 -> V_238 = V_97 ;
}
static void F_91 ( struct V_150 * V_231 ,
struct V_9 * V_10 , T_2 V_4 )
{
struct V_27 * V_28 = V_231 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_45 * V_46 ;
struct V_29 * V_30 ;
T_3 V_47 ;
T_2 V_277 ;
T_1 V_24 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
V_47 = F_20 ( V_46 -> V_48 ) ;
V_277 = V_46 -> V_195 ;
V_30 = NULL ;
if ( ( V_277 == V_278 ) && ( V_47 & V_49 ) ) {
V_24 = F_88 ( V_46 -> V_51 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( F_27 ( V_229 , & V_30 -> V_32 ) ) )
F_80 ( V_231 , V_10 , V_30 , V_4 ) ;
}
} else if ( V_277 == V_279 ) {
V_24 = F_88 ( V_46 -> V_50 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( ! F_27 ( V_229 , & V_30 -> V_32 ) ) )
F_80 ( V_231 , V_10 , V_30 , V_4 ) ;
}
} else if ( V_277 == V_280 ) {
V_24 = F_88 ( V_46 -> V_50 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( ! F_27 ( V_229 , & V_30 -> V_32 ) ) )
F_89 ( V_231 , V_10 , V_30 ) ;
}
}
}
static int F_92 ( struct V_150 * V_231 ,
struct V_9 * V_10 ,
T_3 V_281 , T_2 * V_282 , T_2 V_4 )
{
struct V_268 * V_269 ;
T_3 V_283 , V_284 , V_285 , V_286 ;
struct V_45 * V_46 ;
T_4 V_287 ;
if ( ! F_93 ( V_10 ) )
return 0 ;
if ( F_94 ( V_10 ) -> V_288 != V_289 ) {
F_41 ( V_10 -> V_35 ,
L_33 ,
F_94 ( V_10 ) -> V_288 ) ;
return - V_13 ;
}
* V_282 = F_95 ( V_10 ) + sizeof( struct V_45 ) +
sizeof( struct V_197 ) ;
if ( F_96 ( F_3 ( V_4 ) ) )
V_284 = V_290 ;
else
V_284 = V_291 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
if ( V_46 -> V_48 [ 2 ] & V_292 )
V_284 |= V_293 ;
V_283 = V_273 ;
V_285 = V_10 -> V_19 - * V_282 ;
V_286 = F_94 ( V_10 ) -> V_294 ;
V_287 =
( ( T_4 ) V_283 << V_295 ) |
( ( T_4 ) V_284 << V_275 ) |
( ( T_4 ) V_285 << V_296 ) |
( ( T_4 ) V_286 << V_297 ) ;
V_269 = F_90 ( V_231 , V_231 -> V_238 ) ;
V_231 -> V_238 ++ ;
if ( V_231 -> V_238 == V_231 -> V_241 )
V_231 -> V_238 = 0 ;
V_269 -> V_270 = 0 ;
V_269 -> V_271 = F_37 ( ( V_281 & V_298 )
>> V_299 ) ;
V_269 -> V_272 = F_82 ( V_287 ) ;
return 1 ;
}
static void F_97 ( struct V_150 * V_231 ,
struct V_9 * V_10 ,
struct V_300 * V_301 ,
T_3 V_281 , T_2 V_282 , T_2 V_14 )
{
T_3 V_302 = 0 ;
T_3 V_303 = 0 ;
T_3 V_304 ;
V_303 = V_305 ;
V_304 = F_98 ( V_10 ) ;
if ( V_281 & V_306 )
V_304 += sizeof( struct V_55 ) ;
if ( V_10 -> V_307 == F_24 ( V_105 ) ) {
V_304 -= 2 ;
V_303 |= ( V_308 | F_10 ( V_14 ) ) ;
V_302 |= ( ( ( ( sizeof( struct V_11 ) + 2 ) >> 2 ) <<
V_309 ) |
( ( sizeof( struct V_45 ) >> 2 ) <<
V_310 ) ) ;
F_99 ( V_10 , V_10 -> V_19 - sizeof( struct V_197 ) ) ;
}
V_302 |= ( V_304 >> 1 ) << V_311 ;
F_100 ( V_231 , V_10 , V_301 , V_281 , V_282 , V_303 , V_302 ) ;
}
static inline int F_101 ( struct V_9 * V_10 )
{
T_6 V_307 = V_10 -> V_307 ;
F_102 ( V_10 ) ;
V_10 -> V_312 = sizeof( struct V_313 ) ;
if ( V_307 == F_24 ( V_54 ) ) {
struct V_314 * V_315 = (struct V_314 * ) F_23 ( V_10 ) ;
V_307 = V_315 -> V_316 ;
V_10 -> V_312 += sizeof( struct V_55 ) ;
}
if ( ( V_307 != F_24 ( V_317 ) ) &&
( V_307 != F_24 ( V_105 ) ) )
return - V_13 ;
F_103 ( V_10 , V_10 -> V_312 ) ;
if ( V_307 == F_24 ( V_317 ) )
return 0 ;
F_104 ( V_10 , V_10 -> V_312 + sizeof( struct V_11 ) ) ;
return 0 ;
}
static T_7 F_105 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_10 -> V_35 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_150 * V_231 = V_60 -> V_318 [ V_10 -> V_266 ] ;
struct V_300 * V_301 ;
T_3 V_281 = 0 ;
T_2 V_282 = 0 ;
T_2 V_4 = 0 ;
T_2 V_14 = 0 ;
int V_319 ;
if ( F_101 ( V_10 ) )
goto V_320;
if ( ! F_106 ( V_10 , V_231 ) )
return V_321 ;
if ( F_107 ( V_10 , V_231 , & V_281 ) )
goto V_320;
V_301 = & V_231 -> V_322 [ V_231 -> V_238 ] ;
if ( V_10 -> V_307 == F_24 ( V_317 ) )
goto V_323;
if ( F_5 ( V_10 , & V_4 ) || F_8 ( V_10 , & V_14 ) ) {
F_41 ( V_57 , L_34 , V_4 , V_14 ) ;
goto V_320;
}
V_281 |= V_324 ;
V_319 = F_92 ( V_231 , V_10 , V_281 , & V_282 , V_4 ) ;
if ( V_319 < 0 )
goto V_320;
else if ( V_319 )
V_281 |= V_325 ;
else
F_91 ( V_231 , V_10 , V_4 ) ;
V_323:
F_97 ( V_231 , V_10 , V_301 , V_281 , V_282 , V_14 ) ;
F_108 ( V_231 , V_326 ) ;
return V_327 ;
V_320:
F_109 ( V_10 ) ;
return V_327 ;
}
static int F_110 ( struct V_56 * V_57 , int V_328 )
{
F_111 ( V_57 , L_35 ) ;
return - V_114 ;
}
static int F_112 ( struct V_56 * V_57 ,
T_8 V_329 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
if ( V_329 & V_330 )
F_113 ( V_60 ) ;
else
F_114 ( V_60 ) ;
return 0 ;
}
void F_115 ( struct V_56 * V_57 , struct V_109 * V_60 )
{
struct V_66 * V_67 = & V_60 -> V_61 -> V_67 ;
struct V_27 * V_28 = V_60 -> V_61 ;
if ( V_60 -> type != V_135 )
return;
V_57 -> V_329 = ( V_331 |
V_330 |
V_332 ) ;
V_57 -> V_333 = V_57 -> V_329 ;
V_57 -> V_333 &= ~ ( V_331 |
V_330 |
V_332 ) ;
V_57 -> V_334 = V_26 - 1 ;
V_57 -> V_329 |= V_335 ;
V_57 -> V_333 |= V_335 ;
V_57 -> V_336 |= V_57 -> V_329 ;
V_57 -> V_337 |= V_338 ;
V_57 -> V_337 |= V_339 ;
F_116 ( V_57 -> V_340 , L_36 , V_341 - 1 ) ;
V_57 -> V_342 = V_88 ;
F_117 ( V_57 , & V_28 -> V_34 -> V_35 ) ;
F_118 ( V_57 , & V_343 ) ;
V_57 -> V_344 = 1 ;
F_119 ( V_60 , V_67 -> V_345 . V_346 , 0 , false , false ) ;
F_119 ( V_60 , ( T_2 [ 6 ] ) V_347 , 0 , false , false ) ;
F_119 ( V_60 , V_348 , 0 , false , false ) ;
F_119 ( V_60 , V_349 , 0 , false , false ) ;
F_120 ( V_57 -> V_350 , V_67 -> V_345 . V_346 ) ;
F_120 ( V_57 -> V_351 , V_67 -> V_345 . V_346 ) ;
V_57 -> V_352 = & V_353 ;
}
void F_121 ( struct V_27 * V_28 )
{
struct V_109 * V_60 ;
T_1 V_148 ;
int V_97 ;
if ( ! ( V_28 -> V_32 & V_69 ) )
return;
F_122 ( ! V_28 -> V_60 [ V_28 -> V_354 ] ) ;
for ( V_97 = 0 ; V_97 < V_28 -> V_355 ; V_97 ++ ) {
V_60 = V_28 -> V_60 [ V_97 ] ;
if ( V_60 && V_60 -> type == V_135 ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_37 ) ;
return;
}
}
V_148 = V_28 -> V_60 [ V_28 -> V_354 ] -> V_148 ;
V_60 = F_123 ( V_28 , V_135 , V_148 , 0 ) ;
if ( V_60 ) {
F_124 ( & V_28 -> V_34 -> V_35 ,
L_38 ,
V_60 -> V_148 , V_60 -> V_42 , V_60 -> V_118 , V_148 ) ;
} else {
F_29 ( & V_28 -> V_34 -> V_35 , L_39 ) ;
}
}
