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
F_11 ( L_1 , V_14 ) ;
return 0 ;
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
F_29 ( & V_28 -> V_34 -> V_35 , L_2 ) ;
return 0 ;
}
if ( ! V_28 -> V_67 . V_73 . V_74 ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_3 ) ;
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
F_29 ( & V_28 -> V_34 -> V_35 , L_4 ) ;
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
L_5 ) ;
return - V_114 ;
}
V_111 -> V_115 = V_67 -> V_116 ;
V_111 -> V_117 = 0 ;
V_111 -> V_118 = V_60 -> V_118 ;
V_111 -> V_119 = 0x1 ;
V_111 -> V_32 = V_120 ;
V_113 -> V_121 |= F_37 ( V_122 |
V_123 ) ;
V_113 -> V_121 &= F_37 ( ~ ( V_124 |
V_125 |
V_126 |
V_127 |
V_128 ) ) ;
V_113 -> V_129 = F_37 ( V_130 ) ;
V_95 = F_34 ( V_28 ) ;
F_38 ( V_60 , V_111 , V_95 , true ) ;
V_113 -> V_131 = V_132 ;
return 0 ;
}
int F_39 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
if ( ! ( V_28 -> V_32 & V_69 ) ) {
F_40 ( V_57 , L_6 ) ;
return - V_133 ;
}
if ( V_60 -> type != V_134 ) {
F_40 ( V_57 , L_7 ) ;
return - V_135 ;
}
F_41 ( & V_63 -> V_136 ) ;
return 0 ;
}
int F_42 ( struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
if ( ! ( V_28 -> V_32 & V_69 ) ) {
F_40 ( V_57 , L_8 ) ;
return - V_133 ;
}
if ( V_60 -> type != V_134 )
return - V_135 ;
if ( ! F_43 ( & V_63 -> V_136 ) )
return - V_13 ;
F_44 ( V_57 , L_9 ) ;
return 0 ;
}
static void F_45 ( struct V_62 * V_63 ,
struct V_137 * V_35 ,
unsigned int V_138 )
{
struct V_139 * V_140 ;
V_140 = F_46 ( V_63 -> V_140 , V_138 ) ;
if ( ! V_140 -> V_38 ) {
F_30 ( V_35 , L_10 , V_138 ) ;
return;
}
F_47 ( V_140 -> V_38 ) ;
V_140 -> V_38 = NULL ;
}
static int F_48 ( struct V_62 * V_63 ,
struct V_137 * V_35 ,
unsigned int V_138 )
{
struct V_139 * V_140 ;
struct V_141 * V_38 ;
char V_142 [ 32 ] ;
V_140 = F_46 ( V_63 -> V_140 , V_138 ) ;
if ( V_140 && V_140 -> V_38 ) {
F_30 ( V_35 , L_11 , V_138 ) ;
return 0 ;
}
snprintf ( V_142 , sizeof( V_142 ) , L_12 , V_138 ) ;
V_38 = F_49 ( V_142 , V_35 , V_143 ,
V_144 , V_145 ) ;
if ( ! V_38 ) {
F_36 ( V_35 , L_13 , V_142 ) ;
return - V_146 ;
}
V_140 -> V_38 = V_38 ;
return 0 ;
}
void F_50 ( struct V_109 * V_60 )
{
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
int V_138 , V_97 ;
if ( V_60 -> type != V_134 )
return;
if ( ! V_63 -> V_140 )
return;
for ( V_97 = 0 ; V_97 < V_26 ; V_97 ++ )
F_25 ( V_60 -> V_57 , V_97 ) ;
F_51 (cpu)
F_45 ( V_63 , & V_28 -> V_34 -> V_35 , V_138 ) ;
F_52 ( V_63 -> V_140 ) ;
V_63 -> V_140 = NULL ;
F_44 ( V_60 -> V_57 , L_14 ,
V_60 -> V_42 , V_60 -> V_147 ) ;
}
int F_53 ( struct V_109 * V_60 )
{
struct V_27 * V_28 = V_60 -> V_61 ;
struct V_137 * V_35 = & V_28 -> V_34 -> V_35 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
unsigned int V_138 ;
int V_97 ;
if ( V_60 -> type != V_134 )
return - V_133 ;
if ( V_63 -> V_140 )
return - V_148 ;
V_63 -> V_140 = F_54 ( struct V_139 ) ;
if ( ! V_63 -> V_140 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_15 ) ;
return - V_146 ;
}
F_51 (cpu) {
if ( ! F_48 ( V_63 , V_35 , V_138 ) )
continue;
F_36 ( V_35 , L_16 , V_138 ) ;
F_50 ( V_60 ) ;
return - V_146 ;
}
for ( V_97 = 0 ; V_97 < V_26 ; V_97 ++ )
F_17 ( & V_63 -> V_30 [ V_97 ] ) ;
F_44 ( V_60 -> V_57 , L_17 ,
V_60 -> V_42 , V_60 -> V_147 ) ;
return 0 ;
}
void F_55 ( struct V_149 * V_150 ,
union V_151 * V_152 , T_2 V_153 )
{
struct V_27 * V_28 = V_150 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_29 * V_30 ;
T_3 error ;
T_1 V_24 ;
T_4 V_154 ;
if ( ! F_18 ( V_153 ) )
return;
V_24 = F_56 ( V_152 -> V_155 . V_156 . V_157 . V_158 ) &
( V_26 - 1 ) ;
if ( ! F_12 ( V_24 ) )
return;
V_30 = & V_63 -> V_30 [ V_24 ] ;
F_57 ( V_24 != V_30 -> V_24 ) ;
V_154 = F_58 ( V_152 -> V_155 . V_159 . V_160 ) ;
error = ( V_154 & V_161 ) >>
V_162 ;
if ( V_153 == V_43 ) {
if ( F_59 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_18 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_163 |= V_164 ;
}
if ( F_60 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_19 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_163 |= V_165 ;
}
}
if ( V_153 == V_44 ) {
if ( F_61 ( error ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_20 ,
V_24 , V_30 -> V_24 ) ;
V_30 -> V_163 |= V_166 ;
}
F_62 ( V_167 , & V_30 -> V_32 ) ;
}
F_13 ( V_28 , V_30 ) ;
F_17 ( V_30 ) ;
}
int F_63 ( struct V_149 * V_150 ,
union V_151 * V_152 ,
struct V_9 * V_10 )
{
struct V_27 * V_28 = V_150 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_45 * V_46 = NULL ;
struct V_29 * V_30 = NULL ;
T_3 V_168 , V_169 ;
T_3 error , V_170 ;
int V_171 = - V_13 ;
T_1 V_1 ;
T_1 V_24 ;
T_4 V_154 ;
V_154 = F_58 ( V_152 -> V_155 . V_159 . V_160 ) ;
V_1 = ( V_154 & V_172 ) >> V_173 ;
if ( ! F_1 ( V_1 ) )
goto V_174;
error = ( V_154 & V_175 ) >> V_176 ;
V_170 = ( error >> V_177 ) &
V_178 ;
if ( F_64 ( V_170 == V_179 ) ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_21 ) ;
V_10 -> V_180 = V_181 ;
} else {
V_10 -> V_180 = V_182 ;
}
V_168 = ( V_154 & V_183 ) >> V_184 ;
V_169 = ( V_168 >> V_185 ) &
V_186 ;
V_46 = F_22 ( V_10 ) ;
V_24 = F_19 ( V_46 ) ;
if ( ! F_12 ( V_24 ) )
goto V_174;
if ( V_169 == V_187 )
goto V_174;
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ! V_30 -> V_33 )
goto V_174;
V_24 = F_65 ( V_152 -> V_155 . V_156 . V_188 . V_189 . V_190 ) ;
if ( V_30 -> V_24 != V_24 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_22 ,
V_30 -> V_24 , V_24 ) ;
goto V_191;
}
if ( V_30 -> V_170 ) {
F_36 ( & V_28 -> V_34 -> V_35 , L_23 ,
V_24 , V_30 -> V_170 , V_170 ) ;
goto V_191;
}
V_30 -> V_19 = F_56 ( V_152 -> V_155 . V_156 . V_157 . V_158 ) ;
V_30 -> V_170 = V_170 ;
if ( V_169 == V_192 ) {
T_3 V_47 = F_20 ( V_46 -> V_48 ) ;
if ( ( V_47 & V_193 ) &&
( V_46 -> V_194 == V_195 ) ) {
struct V_196 * V_197 = NULL ;
V_197 = (struct V_196 * ) F_66 ( V_10 , sizeof( * V_197 ) ) ;
V_197 -> V_198 = V_16 ;
} else {
V_171 = 0 ;
goto V_174;
}
}
V_191:
F_13 ( V_28 , V_30 ) ;
if ( V_30 -> V_19 && ! V_30 -> V_170 ) {
int V_199 ;
V_171 = V_30 -> V_19 ;
F_17 ( V_30 ) ;
V_30 -> V_19 = V_171 ;
V_199 = F_67 ( V_171 , 2048 ) ;
V_150 -> V_200 . V_201 += V_171 ;
V_150 -> V_200 . V_202 += V_199 ;
V_150 -> V_203 -> V_204 . V_205 += V_171 ;
V_150 -> V_203 -> V_204 . V_206 += V_199 ;
F_68 ( V_65 , & V_30 -> V_32 ) ;
}
V_174:
return V_171 ;
}
static int F_69 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_207 * V_33 , unsigned int V_36 ,
int V_208 )
{
static const unsigned int V_209 = V_210 ;
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_139 * V_140 ;
struct V_27 * V_28 = V_59 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
unsigned int V_97 , V_211 , V_212 ;
struct V_29 * V_30 ;
unsigned int V_213 = 0 ;
unsigned int V_214 = 0 ;
unsigned int V_215 = 0 ;
struct V_207 * V_216 ;
T_5 V_217 = 0 ;
unsigned int V_19 ;
if ( V_24 >= V_26 ) {
F_30 ( & V_28 -> V_34 -> V_35 , L_24 , V_24 ) ;
return 0 ;
}
if ( F_27 ( V_218 , & V_28 -> V_219 ) ||
F_27 ( V_220 , & V_28 -> V_219 ) ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_25 ,
V_24 ) ;
return 0 ;
}
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( V_30 -> V_33 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_26 ,
V_24 , V_30 -> V_33 , V_30 -> V_36 ) ;
return 0 ;
}
F_17 ( V_30 ) ;
if ( ! V_63 -> V_140 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_27 , V_24 ) ;
return 0 ;
}
V_140 = F_46 ( V_63 -> V_140 , F_70 () ) ;
if ( ! V_140 -> V_38 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_28 , V_24 ) ;
goto V_221;
}
V_212 = F_71 ( & V_28 -> V_34 -> V_35 , V_33 , V_36 , V_37 ) ;
if ( V_212 == 0 ) {
F_29 ( & V_28 -> V_34 -> V_35 , L_29 ,
V_33 , V_36 ) ;
goto V_222;
}
V_30 -> V_39 = F_72 ( V_140 -> V_38 , V_223 , & V_30 -> V_40 ) ;
if ( ! V_30 -> V_39 ) {
F_29 ( & V_28 -> V_34 -> V_35 ,
L_30 , V_24 ) ;
goto V_222;
}
V_211 = 0 ;
V_30 -> V_19 = 0 ;
F_73 (sgl, sg, dmacount, i) {
V_217 = F_74 ( V_216 ) ;
V_19 = F_75 ( V_216 ) ;
V_30 -> V_19 += V_19 ;
while ( V_19 ) {
if ( V_211 >= V_224 ) {
F_29 ( & V_28 -> V_34 -> V_35 ,
L_31 ,
V_24 , V_97 , V_211 , V_212 , ( T_4 ) V_217 ) ;
goto V_225;
}
V_214 = V_217 & ( ( T_5 ) V_209 - 1 ) ;
V_215 = F_76 (unsigned int, (bufflen - thisoff), len) ;
if ( ( V_211 != 0 ) && ( V_214 ) )
goto V_225;
if ( ( ( V_97 != ( V_212 - 1 ) ) || ( V_215 != V_19 ) ) &&
( ( V_215 + V_214 ) != V_209 ) )
goto V_225;
V_30 -> V_39 [ V_211 ] = ( T_4 ) ( V_217 - V_214 ) ;
if ( V_211 == 0 )
V_213 = V_214 ;
V_19 -= V_215 ;
V_217 += V_215 ;
V_211 ++ ;
}
}
V_30 -> V_226 = V_214 + V_215 ;
V_30 -> V_213 = V_213 ;
V_30 -> V_227 = V_211 ;
V_30 -> V_38 = V_140 -> V_38 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_36 = V_36 ;
V_30 -> V_24 = V_24 ;
if ( V_208 )
F_68 ( V_228 , & V_30 -> V_32 ) ;
F_68 ( V_229 , & V_30 -> V_32 ) ;
F_77 () ;
return 1 ;
V_225:
F_16 ( V_30 -> V_38 , V_30 -> V_39 , V_30 -> V_40 ) ;
F_17 ( V_30 ) ;
V_222:
F_15 ( & V_28 -> V_34 -> V_35 , V_33 , V_36 , V_37 ) ;
V_221:
F_77 () ;
return 0 ;
}
static int F_78 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_207 * V_33 , unsigned int V_36 )
{
return F_69 ( V_57 , V_24 , V_33 , V_36 , 0 ) ;
}
static int F_79 ( struct V_56 * V_57 , T_1 V_24 ,
struct V_207 * V_33 , unsigned int V_36 )
{
return F_69 ( V_57 , V_24 , V_33 , V_36 , 1 ) ;
}
static void F_80 ( struct V_149 * V_230 ,
struct V_9 * V_10 ,
struct V_29 * V_30 , T_2 V_4 )
{
struct V_231 * V_232 = NULL ;
struct V_233 * V_234 = NULL ;
struct V_235 * V_236 = NULL ;
struct V_27 * V_28 = V_230 -> V_60 -> V_61 ;
T_1 V_97 = V_230 -> V_237 ;
struct V_45 * V_46 ;
T_4 V_238 = 0 ;
bool V_208 ;
if ( F_27 ( V_167 , & V_30 -> V_32 ) ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_32 ,
V_30 -> V_24 , V_30 -> V_32 ) ;
return;
}
if ( F_14 ( V_239 , & V_30 -> V_32 ) ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_33 ,
V_30 -> V_24 , V_30 -> V_32 ) ;
return;
}
V_236 = F_81 ( V_230 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_230 -> V_240 )
V_97 = 0 ;
V_236 -> V_241 =
F_82 ( V_242 |
( ( T_4 ) V_243 <<
V_244 ) |
( ( T_4 ) V_30 -> V_213 <<
V_245 ) |
( ( T_4 ) V_30 -> V_226 <<
V_246 ) ) ;
V_236 -> V_247 = F_82 ( 0 ) ;
V_208 = F_27 ( V_228 , & V_30 -> V_32 ) ;
if ( V_208 )
V_236 -> V_241 |=
F_82 ( V_248 ) ;
V_234 = F_83 ( V_230 , V_97 ++ ) ;
if ( V_97 == V_230 -> V_240 )
V_97 = 0 ;
V_234 -> V_249 = F_82 ( V_30 -> V_24 | ( ( T_4 ) V_30 -> V_40 ) ) ;
V_234 -> V_250 = F_82 ( V_30 -> V_227 |
( ( T_4 ) ( V_251 |
V_252 ) <<
V_253 ) ) ;
V_232 = F_84 ( V_230 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_230 -> V_240 )
V_97 = 0 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
V_232 -> V_254 = F_86 ( F_87 ( V_46 -> V_255 ) ) ;
V_232 -> V_256 = F_37 ( F_88 ( V_46 -> V_257 ) ) ;
V_232 -> V_258 = F_37 ( V_30 -> V_24 <<
V_259 ) ;
V_238 = V_260 ;
V_238 |= ( T_4 ) ( V_208 ?
V_261 :
V_262 ) ;
V_238 |= ( T_4 ) ( ( V_4 == V_5 || V_4 == V_6 ) ?
V_263 :
V_264 ) ;
V_238 |= ( ( T_4 ) V_10 -> V_265 <<
V_266 ) ;
V_232 -> V_238 = F_82 ( V_238 ) ;
V_230 -> V_237 = V_97 ;
}
static void F_89 ( struct V_149 * V_230 ,
struct V_9 * V_10 ,
struct V_29 * V_30 )
{
struct V_267 * V_268 ;
int V_97 ;
if ( F_14 ( V_167 , & V_30 -> V_32 ) )
return;
V_97 = V_230 -> V_237 ;
V_268 = F_90 ( V_230 , V_97 ) ;
V_97 ++ ;
if ( V_97 == V_230 -> V_240 )
V_97 = 0 ;
V_268 -> V_269 = F_86 ( 0 ) ;
V_268 -> V_270 = F_37 ( 0 ) ;
V_268 -> V_247 = F_37 ( 0 ) ;
V_268 -> V_271 = F_82 (
V_272 |
( V_273 <<
V_274 ) |
( V_275 <<
V_274 ) ) ;
V_230 -> V_237 = V_97 ;
}
static void F_91 ( struct V_149 * V_230 ,
struct V_9 * V_10 , T_2 V_4 )
{
struct V_27 * V_28 = V_230 -> V_60 -> V_61 ;
struct V_62 * V_63 = & V_28 -> V_63 ;
struct V_45 * V_46 ;
struct V_29 * V_30 ;
T_3 V_47 ;
T_2 V_276 ;
T_1 V_24 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
V_47 = F_20 ( V_46 -> V_48 ) ;
V_276 = V_46 -> V_194 ;
V_30 = NULL ;
if ( ( V_276 == V_277 ) && ( V_47 & V_49 ) ) {
V_24 = F_88 ( V_46 -> V_51 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( F_27 ( V_228 , & V_30 -> V_32 ) ) )
F_80 ( V_230 , V_10 , V_30 , V_4 ) ;
}
} else if ( V_276 == V_278 ) {
V_24 = F_88 ( V_46 -> V_50 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( ! F_27 ( V_228 , & V_30 -> V_32 ) ) )
F_80 ( V_230 , V_10 , V_30 , V_4 ) ;
}
} else if ( V_276 == V_279 ) {
V_24 = F_88 ( V_46 -> V_50 ) ;
if ( F_12 ( V_24 ) ) {
V_30 = & V_63 -> V_30 [ V_24 ] ;
if ( ( V_30 -> V_24 == V_24 ) &&
( ! F_27 ( V_228 , & V_30 -> V_32 ) ) )
F_89 ( V_230 , V_10 , V_30 ) ;
}
}
}
static int F_92 ( struct V_149 * V_230 ,
struct V_9 * V_10 ,
T_3 V_280 , T_2 * V_281 , T_2 V_4 )
{
struct V_267 * V_268 ;
T_3 V_282 , V_283 , V_284 , V_285 ;
struct V_45 * V_46 ;
T_4 V_286 ;
if ( ! F_93 ( V_10 ) )
return 0 ;
if ( F_94 ( V_10 ) -> V_287 != V_288 ) {
F_40 ( V_10 -> V_35 ,
L_34 ,
F_94 ( V_10 ) -> V_287 ) ;
return - V_13 ;
}
* V_281 = F_95 ( V_10 ) + sizeof( struct V_45 ) +
sizeof( struct V_196 ) ;
if ( F_96 ( F_3 ( V_4 ) ) )
V_283 = V_289 ;
else
V_283 = V_290 ;
V_46 = (struct V_45 * ) F_85 ( V_10 ) ;
if ( V_46 -> V_48 [ 2 ] & V_291 )
V_283 |= V_292 ;
V_282 = V_272 ;
V_284 = V_10 -> V_19 - * V_281 ;
V_285 = F_94 ( V_10 ) -> V_293 ;
V_286 =
( ( T_4 ) V_282 << V_294 ) |
( ( T_4 ) V_283 << V_274 ) |
( ( T_4 ) V_284 << V_295 ) |
( ( T_4 ) V_285 << V_296 ) ;
V_268 = F_90 ( V_230 , V_230 -> V_237 ) ;
V_230 -> V_237 ++ ;
if ( V_230 -> V_237 == V_230 -> V_240 )
V_230 -> V_237 = 0 ;
V_268 -> V_269 = 0 ;
V_268 -> V_270 = F_37 ( ( V_280 & V_297 )
>> V_298 ) ;
V_268 -> V_271 = F_82 ( V_286 ) ;
return 1 ;
}
static void F_97 ( struct V_149 * V_230 ,
struct V_9 * V_10 ,
struct V_299 * V_300 ,
T_3 V_280 , T_2 V_281 , T_2 V_14 )
{
T_3 V_301 = 0 ;
T_3 V_302 = 0 ;
T_3 V_303 ;
V_302 = V_304 ;
V_303 = F_98 ( V_10 ) ;
if ( V_280 & V_305 )
V_303 += sizeof( struct V_55 ) ;
if ( V_10 -> V_306 == F_24 ( V_105 ) ) {
V_303 -= 2 ;
V_302 |= ( V_307 | F_10 ( V_14 ) ) ;
V_301 |= ( ( ( ( sizeof( struct V_11 ) + 2 ) >> 2 ) <<
V_308 ) |
( ( sizeof( struct V_45 ) >> 2 ) <<
V_309 ) ) ;
F_99 ( V_10 , V_10 -> V_19 - sizeof( struct V_196 ) ) ;
}
V_301 |= ( V_303 >> 1 ) << V_310 ;
return F_100 ( V_230 , V_10 , V_300 , V_280 , V_281 ,
V_302 , V_301 ) ;
}
static inline int F_101 ( struct V_9 * V_10 )
{
T_6 V_306 = V_10 -> V_306 ;
F_102 ( V_10 ) ;
V_10 -> V_311 = sizeof( struct V_312 ) ;
if ( V_306 == F_24 ( V_54 ) ) {
struct V_313 * V_314 = (struct V_313 * ) F_23 ( V_10 ) ;
V_306 = V_314 -> V_315 ;
V_10 -> V_311 += sizeof( struct V_55 ) ;
}
if ( ( V_306 != F_24 ( V_316 ) ) &&
( V_306 != F_24 ( V_105 ) ) )
return - V_13 ;
F_103 ( V_10 , V_10 -> V_311 ) ;
if ( V_306 == F_24 ( V_316 ) )
return 0 ;
F_104 ( V_10 , V_10 -> V_311 + sizeof( struct V_11 ) ) ;
return 0 ;
}
static T_7 F_105 ( struct V_9 * V_10 ,
struct V_56 * V_57 )
{
struct V_58 * V_59 = F_26 ( V_10 -> V_35 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
struct V_149 * V_230 = V_60 -> V_317 [ V_10 -> V_265 ] ;
struct V_299 * V_300 ;
T_3 V_280 = 0 ;
T_2 V_281 = 0 ;
T_2 V_4 = 0 ;
T_2 V_14 = 0 ;
int V_318 ;
if ( F_101 ( V_10 ) )
goto V_319;
if ( ! F_106 ( V_10 , V_230 ) )
return V_320 ;
if ( F_107 ( V_10 , V_230 , & V_280 ) )
goto V_319;
V_300 = & V_230 -> V_321 [ V_230 -> V_237 ] ;
if ( V_10 -> V_306 == F_24 ( V_316 ) )
goto V_322;
if ( F_5 ( V_10 , & V_4 ) || F_8 ( V_10 , & V_14 ) ) {
F_40 ( V_57 , L_35 , V_4 , V_14 ) ;
goto V_319;
}
V_280 |= V_323 ;
V_318 = F_92 ( V_230 , V_10 , V_280 , & V_281 , V_4 ) ;
if ( V_318 < 0 )
goto V_319;
else if ( V_318 )
V_280 |= V_324 ;
else
F_91 ( V_230 , V_10 , V_4 ) ;
V_322:
F_97 ( V_230 , V_10 , V_300 , V_280 , V_281 , V_14 ) ;
F_108 ( V_230 , V_325 ) ;
return V_326 ;
V_319:
F_109 ( V_10 ) ;
return V_326 ;
}
static int F_110 ( struct V_56 * V_57 , int V_327 )
{
F_111 ( V_57 , L_36 ) ;
return - V_114 ;
}
static int F_112 ( struct V_56 * V_57 ,
T_8 V_328 )
{
struct V_58 * V_59 = F_26 ( V_57 ) ;
struct V_109 * V_60 = V_59 -> V_60 ;
if ( V_328 & V_329 )
F_113 ( V_60 ) ;
else
F_114 ( V_60 ) ;
return 0 ;
}
void F_115 ( struct V_56 * V_57 , struct V_109 * V_60 )
{
struct V_66 * V_67 = & V_60 -> V_61 -> V_67 ;
struct V_27 * V_28 = V_60 -> V_61 ;
if ( V_60 -> type != V_134 )
return;
V_57 -> V_328 = ( V_330 |
V_329 |
V_331 ) ;
V_57 -> V_332 = V_57 -> V_328 ;
V_57 -> V_332 &= ~ ( V_330 |
V_329 |
V_331 ) ;
V_57 -> V_333 = V_26 - 1 ;
V_57 -> V_328 |= V_334 ;
V_57 -> V_332 |= V_334 ;
V_57 -> V_335 |= V_57 -> V_328 ;
V_57 -> V_336 |= V_337 ;
V_57 -> V_336 |= V_338 ;
F_116 ( V_57 -> V_339 , L_37 , V_340 - 1 ) ;
V_57 -> V_341 = V_88 ;
F_117 ( V_57 , & V_28 -> V_34 -> V_35 ) ;
V_57 -> V_342 = 1 ;
F_118 ( V_60 , V_67 -> V_343 . V_344 , 0 , false , false ) ;
F_118 ( V_60 , ( T_2 [ 6 ] ) V_345 , 0 , false , false ) ;
F_118 ( V_60 , V_346 , 0 , false , false ) ;
F_118 ( V_60 , V_347 , 0 , false , false ) ;
F_119 ( V_57 -> V_348 , V_67 -> V_343 . V_344 ) ;
F_119 ( V_57 -> V_349 , V_67 -> V_343 . V_344 ) ;
V_57 -> V_350 = & V_351 ;
}
void F_120 ( struct V_27 * V_28 )
{
struct V_109 * V_60 ;
T_1 V_147 ;
int V_97 ;
if ( ! ( V_28 -> V_32 & V_69 ) )
return;
F_121 ( ! V_28 -> V_60 [ V_28 -> V_352 ] ) ;
for ( V_97 = 0 ; V_97 < V_28 -> V_353 ; V_97 ++ ) {
V_60 = V_28 -> V_60 [ V_97 ] ;
if ( V_60 && V_60 -> type == V_134 ) {
F_30 ( & V_28 -> V_34 -> V_35 ,
L_38 ) ;
return;
}
}
V_147 = V_28 -> V_60 [ V_28 -> V_352 ] -> V_147 ;
V_60 = F_122 ( V_28 , V_134 , V_147 , 0 ) ;
if ( V_60 ) {
F_123 ( & V_28 -> V_34 -> V_35 ,
L_39 ,
V_60 -> V_147 , V_60 -> V_42 , V_60 -> V_118 , V_147 ) ;
} else {
F_29 ( & V_28 -> V_34 -> V_35 , L_40 ) ;
}
}
