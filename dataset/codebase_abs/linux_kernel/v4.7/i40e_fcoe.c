static inline bool F_1 ( T_1 V_1 )
{
return ( V_1 == V_2 ) || ( V_1 == V_3 ) ;
}
static inline bool F_2 ( T_1 V_1 )
{
return ( V_1 == V_4 ) || ( V_1 == V_5 ) ;
}
static inline bool F_3 ( T_1 V_1 )
{
return F_1 ( V_1 ) ||
F_2 ( V_1 ) ;
}
static inline int F_4 ( struct V_6 * V_7 , T_1 * V_1 )
{
* V_1 = ( (struct V_8 * ) F_5 ( V_7 ) ) -> V_9 ;
if ( ! F_3 ( * V_1 ) )
return - V_10 ;
return 0 ;
}
static inline bool F_6 ( T_1 V_11 )
{
return ( V_11 == V_12 ) || ( V_11 == V_13 ) ||
( V_11 == V_14 ) || ( V_11 == V_15 ) ;
}
static inline int F_7 ( struct V_6 * V_7 , T_1 * V_11 )
{
F_8 ( V_7 , V_7 -> V_16 - 4 , V_11 , 1 ) ;
if ( ! F_6 ( * V_11 ) )
return - V_10 ;
return 0 ;
}
static inline T_2 F_9 ( T_1 V_11 )
{
switch ( V_11 ) {
case V_12 :
return V_17 ;
case V_13 :
return V_18 ;
case V_14 :
return V_19 ;
case V_15 :
return V_20 ;
default:
F_10 ( 1 ) ;
return - V_10 ;
}
}
static inline bool F_11 ( T_3 V_21 )
{
return ( V_21 != V_22 ) && ( V_21 < V_23 ) ;
}
static inline void F_12 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
if ( F_13 ( V_28 , & V_27 -> V_29 ) )
return;
if ( V_27 -> V_30 ) {
F_14 ( & V_25 -> V_31 -> V_32 , V_27 -> V_30 , V_27 -> V_33 ,
V_34 ) ;
V_27 -> V_30 = NULL ;
V_27 -> V_33 = 0 ;
}
if ( V_27 -> V_35 ) {
F_15 ( V_27 -> V_35 , V_27 -> V_36 , V_27 -> V_37 ) ;
V_27 -> V_35 = NULL ;
}
}
static inline void F_16 ( struct V_26 * V_27 )
{
memset ( V_27 , 0 , sizeof( struct V_26 ) ) ;
V_27 -> V_21 = V_22 ;
V_27 -> V_29 = V_38 ;
}
static inline bool F_17 ( T_1 V_39 )
{
return ( V_39 == V_40 ) ||
( V_39 == V_41 ) ;
}
static inline T_3 F_18 ( struct V_42 * V_43 )
{
T_2 V_44 = F_19 ( V_43 -> V_45 ) ;
return ( V_44 & V_46 ) ?
F_20 ( V_43 -> V_47 ) :
F_20 ( V_43 -> V_48 ) ;
}
static inline struct V_42 * F_21 (
struct V_6 * V_7 )
{
void * V_43 = V_7 -> V_49 + sizeof( struct V_8 ) ;
if ( F_22 ( V_7 ) -> V_50 == F_23 ( V_51 ) )
V_43 += sizeof( struct V_52 ) ;
return (struct V_42 * ) V_43 ;
}
static int F_24 ( struct V_53 * V_54 , T_3 V_21 )
{
struct V_55 * V_56 = F_25 ( V_54 ) ;
struct V_24 * V_25 = V_56 -> V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
int V_16 = 0 ;
struct V_26 * V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( ! V_60 || ! V_27 )
goto V_61;
if ( F_26 ( V_62 , & V_27 -> V_29 ) )
V_16 = V_27 -> V_16 ;
F_12 ( V_25 , V_27 ) ;
V_61:
return V_16 ;
}
void F_27 ( struct V_24 * V_25 )
{
struct V_63 * V_64 = & V_25 -> V_64 ;
T_2 V_65 ;
V_25 -> V_29 &= ~ V_66 ;
V_25 -> V_67 = 0 ;
V_25 -> V_68 = 0 ;
V_25 -> V_69 = 0 ;
if ( ! V_25 -> V_64 . V_70 . V_60 ) {
F_28 ( & V_25 -> V_31 -> V_32 , L_1 ) ;
return;
}
if ( ! V_25 -> V_64 . V_70 . V_71 ) {
F_29 ( & V_25 -> V_31 -> V_32 ,
L_2 ) ;
return;
}
V_65 = F_30 ( V_64 , F_31 ( 1 ) ) ;
V_65 |= F_32 ( V_72 - 32 ) ;
V_65 |= F_32 ( V_73 - 32 ) ;
V_65 &= V_74 ;
F_33 ( V_64 , F_31 ( 1 ) , V_65 ) ;
V_25 -> V_29 |= V_66 ;
V_25 -> V_67 = V_75 ;
V_25 -> V_68 = F_32 ( V_76 ) *
V_77 ;
V_25 -> V_69 = V_25 -> V_68 +
F_32 ( V_78 ) *
V_79 ;
V_25 -> V_80 . V_81 = V_78 ;
V_25 -> V_80 . V_82 = V_76 ;
V_65 = F_30 ( V_64 , V_83 ) ;
V_65 &= ~ V_84 ;
V_65 |= ( ( V_85 + V_86 + V_87 + V_88 )
<< V_89 ) ;
F_33 ( V_64 , V_83 , V_65 ) ;
F_34 ( & V_25 -> V_31 -> V_32 , L_3 ) ;
}
T_1 F_35 ( struct V_24 * V_25 )
{
struct V_90 V_91 ;
struct V_63 * V_64 = & V_25 -> V_64 ;
T_1 V_92 = 0 ;
T_1 V_93 , V_94 ;
struct V_95 * V_96 = & V_64 -> V_97 ;
for ( V_94 = 0 ; V_94 < V_96 -> V_98 ; V_94 ++ ) {
V_91 = V_96 -> V_91 [ V_94 ] ;
if ( V_91 . V_99 == V_100 &&
V_91 . V_101 == V_102 ) {
V_93 = V_96 -> V_103 . V_104 [ V_91 . V_105 ] ;
V_92 |= F_32 ( V_93 ) ;
break;
}
}
V_92 = V_92 ? V_92 : 0x1 ;
return V_92 ;
}
int F_36 ( struct V_106 * V_57 , struct V_107 * V_108 )
{
struct V_109 * V_110 = & V_108 -> V_110 ;
struct V_24 * V_25 = V_57 -> V_58 ;
struct V_63 * V_64 = & V_25 -> V_64 ;
T_1 V_92 = 0 ;
if ( ! ( V_25 -> V_29 & V_66 ) ) {
F_37 ( & V_25 -> V_31 -> V_32 ,
L_4 ) ;
return - V_111 ;
}
V_108 -> V_112 = V_64 -> V_113 ;
V_108 -> V_114 = 0 ;
V_108 -> V_115 = V_57 -> V_115 ;
V_108 -> V_116 = V_117 ;
V_108 -> V_29 = V_118 ;
V_110 -> V_119 |= F_38 ( V_120 ) ;
V_110 -> V_119 &= F_38 ( ~ ( V_121 |
V_122 |
V_123 |
V_124 |
V_125 ) ) ;
if ( F_39 ( V_57 ) ) {
V_110 -> V_119 |=
F_38 ( V_126 ) ;
V_110 -> V_127 =
F_38 ( V_128 ) ;
}
V_92 = F_35 ( V_25 ) ;
F_40 ( V_57 , V_108 , V_92 , true ) ;
V_110 -> V_129 = V_130 ;
return 0 ;
}
int F_41 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_25 ( V_54 ) ;
struct V_106 * V_57 = V_56 -> V_57 ;
struct V_24 * V_25 = V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
if ( ! ( V_25 -> V_29 & V_66 ) ) {
F_42 ( V_54 , L_5 ) ;
return - V_131 ;
}
if ( V_57 -> type != V_132 ) {
F_42 ( V_54 , L_6 ) ;
return - V_133 ;
}
F_43 ( & V_60 -> V_134 ) ;
return 0 ;
}
int F_44 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_25 ( V_54 ) ;
struct V_106 * V_57 = V_56 -> V_57 ;
struct V_24 * V_25 = V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
if ( ! ( V_25 -> V_29 & V_66 ) ) {
F_42 ( V_54 , L_7 ) ;
return - V_131 ;
}
if ( V_57 -> type != V_132 )
return - V_133 ;
if ( ! F_45 ( & V_60 -> V_134 ) )
return - V_10 ;
F_46 ( V_54 , L_8 ) ;
return 0 ;
}
static void F_47 ( struct V_59 * V_60 ,
struct V_135 * V_32 ,
unsigned int V_136 )
{
struct V_137 * V_138 ;
V_138 = F_48 ( V_60 -> V_138 , V_136 ) ;
if ( ! V_138 -> V_35 ) {
F_29 ( V_32 , L_9 , V_136 ) ;
return;
}
F_49 ( V_138 -> V_35 ) ;
V_138 -> V_35 = NULL ;
}
static int F_50 ( struct V_59 * V_60 ,
struct V_135 * V_32 ,
unsigned int V_136 )
{
struct V_137 * V_138 ;
struct V_139 * V_35 ;
char V_140 [ 32 ] ;
V_138 = F_48 ( V_60 -> V_138 , V_136 ) ;
if ( V_138 && V_138 -> V_35 ) {
F_29 ( V_32 , L_10 , V_136 ) ;
return 0 ;
}
snprintf ( V_140 , sizeof( V_140 ) , L_11 , V_136 ) ;
V_35 = F_51 ( V_140 , V_32 , V_141 ,
V_142 , V_143 ) ;
if ( ! V_35 ) {
F_37 ( V_32 , L_12 , V_140 ) ;
return - V_144 ;
}
V_138 -> V_35 = V_35 ;
return 0 ;
}
void F_52 ( struct V_106 * V_57 )
{
struct V_24 * V_25 = V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
int V_136 , V_94 ;
if ( V_57 -> type != V_132 )
return;
if ( ! V_60 -> V_138 )
return;
for ( V_94 = 0 ; V_94 < V_23 ; V_94 ++ )
F_24 ( V_57 -> V_54 , V_94 ) ;
F_53 (cpu)
F_47 ( V_60 , & V_25 -> V_31 -> V_32 , V_136 ) ;
F_54 ( V_60 -> V_138 ) ;
V_60 -> V_138 = NULL ;
F_46 ( V_57 -> V_54 , L_13 ,
V_57 -> V_39 , V_57 -> V_145 ) ;
}
int F_55 ( struct V_106 * V_57 )
{
struct V_24 * V_25 = V_57 -> V_58 ;
struct V_135 * V_32 = & V_25 -> V_31 -> V_32 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
unsigned int V_136 ;
int V_94 ;
if ( V_57 -> type != V_132 )
return - V_131 ;
if ( V_60 -> V_138 )
return - V_146 ;
V_60 -> V_138 = F_56 ( struct V_137 ) ;
if ( ! V_60 -> V_138 ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_14 ) ;
return - V_144 ;
}
F_53 (cpu) {
if ( ! F_50 ( V_60 , V_32 , V_136 ) )
continue;
F_37 ( V_32 , L_15 , V_136 ) ;
F_52 ( V_57 ) ;
return - V_144 ;
}
for ( V_94 = 0 ; V_94 < V_23 ; V_94 ++ )
F_16 ( & V_60 -> V_27 [ V_94 ] ) ;
F_46 ( V_57 -> V_54 , L_16 ,
V_57 -> V_39 , V_57 -> V_145 ) ;
return 0 ;
}
void F_57 ( struct V_147 * V_148 ,
union V_149 * V_150 , T_1 V_151 )
{
struct V_24 * V_25 = V_148 -> V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
struct V_26 * V_27 ;
T_2 error ;
T_3 V_21 ;
T_4 V_152 ;
if ( ! F_17 ( V_151 ) )
return;
V_21 = F_58 ( V_150 -> V_153 . V_154 . V_155 . V_156 ) &
( V_23 - 1 ) ;
if ( ! F_11 ( V_21 ) )
return;
V_27 = & V_60 -> V_27 [ V_21 ] ;
F_10 ( V_21 != V_27 -> V_21 ) ;
V_152 = F_59 ( V_150 -> V_153 . V_157 . V_158 ) ;
error = ( V_152 & V_159 ) >>
V_160 ;
if ( V_151 == V_40 ) {
if ( F_60 ( error ) ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_17 ,
V_21 , V_27 -> V_21 ) ;
V_27 -> V_161 |= V_162 ;
}
if ( F_61 ( error ) ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_18 ,
V_21 , V_27 -> V_21 ) ;
V_27 -> V_161 |= V_163 ;
}
}
if ( V_151 == V_41 ) {
if ( F_62 ( error ) ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_19 ,
V_21 , V_27 -> V_21 ) ;
V_27 -> V_161 |= V_164 ;
}
F_63 ( V_165 , & V_27 -> V_29 ) ;
}
F_12 ( V_25 , V_27 ) ;
F_16 ( V_27 ) ;
}
int F_64 ( struct V_147 * V_148 ,
union V_149 * V_150 ,
struct V_6 * V_7 )
{
struct V_24 * V_25 = V_148 -> V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
struct V_42 * V_43 = NULL ;
struct V_26 * V_27 = NULL ;
T_2 V_166 , V_167 ;
T_2 error , V_168 ;
int V_169 = - V_10 ;
T_3 V_170 ;
T_3 V_21 ;
T_4 V_152 ;
V_152 = F_59 ( V_150 -> V_153 . V_157 . V_158 ) ;
V_170 = ( V_152 & V_171 ) >> V_172 ;
if ( ! F_65 ( V_170 ) )
goto V_173;
error = ( V_152 & V_174 ) >> V_175 ;
V_168 = ( error >> V_176 ) &
V_177 ;
if ( F_66 ( V_168 == V_178 ) ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_20 ) ;
V_7 -> V_179 = V_180 ;
} else {
V_7 -> V_179 = V_181 ;
}
V_166 = ( V_152 & V_182 ) >> V_183 ;
V_167 = ( V_166 >> V_184 ) &
V_185 ;
V_43 = F_21 ( V_7 ) ;
V_21 = F_18 ( V_43 ) ;
if ( ! F_11 ( V_21 ) )
goto V_173;
if ( V_167 == V_186 )
goto V_173;
V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( ! V_27 -> V_30 )
goto V_173;
V_21 = F_67 ( V_150 -> V_153 . V_154 . V_187 . V_188 . V_189 ) ;
if ( V_27 -> V_21 != V_21 ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_21 ,
V_27 -> V_21 , V_21 ) ;
goto V_190;
}
if ( V_27 -> V_168 ) {
F_37 ( & V_25 -> V_31 -> V_32 , L_22 ,
V_21 , V_27 -> V_168 , V_168 ) ;
goto V_190;
}
V_27 -> V_16 = F_58 ( V_150 -> V_153 . V_154 . V_155 . V_156 ) ;
V_27 -> V_168 = V_168 ;
if ( V_167 == V_191 ) {
T_2 V_44 = F_19 ( V_43 -> V_45 ) ;
if ( ( V_44 & V_192 ) &&
( V_43 -> V_193 == V_194 ) ) {
struct V_195 * V_196 = NULL ;
V_196 = (struct V_195 * ) F_68 ( V_7 , sizeof( * V_196 ) ) ;
V_196 -> V_197 = V_13 ;
} else {
V_169 = 0 ;
goto V_173;
}
}
V_190:
F_12 ( V_25 , V_27 ) ;
if ( V_27 -> V_16 && ! V_27 -> V_168 ) {
int V_198 ;
V_169 = V_27 -> V_16 ;
F_16 ( V_27 ) ;
V_27 -> V_16 = V_169 ;
V_198 = F_69 ( V_169 , 2048 ) ;
V_148 -> V_199 . V_200 += V_169 ;
V_148 -> V_199 . V_201 += V_198 ;
V_148 -> V_202 -> V_203 . V_204 += V_169 ;
V_148 -> V_202 -> V_203 . V_205 += V_198 ;
F_70 ( V_62 , & V_27 -> V_29 ) ;
}
V_173:
return V_169 ;
}
static int F_71 ( struct V_53 * V_54 , T_3 V_21 ,
struct V_206 * V_30 , unsigned int V_33 ,
int V_207 )
{
static const unsigned int V_208 = V_209 ;
struct V_55 * V_56 = F_25 ( V_54 ) ;
struct V_137 * V_138 ;
struct V_24 * V_25 = V_56 -> V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
unsigned int V_94 , V_210 , V_211 ;
struct V_26 * V_27 ;
unsigned int V_212 = 0 ;
unsigned int V_213 = 0 ;
unsigned int V_214 = 0 ;
struct V_206 * V_215 ;
T_5 V_216 = 0 ;
unsigned int V_16 ;
if ( V_21 >= V_23 ) {
F_29 ( & V_25 -> V_31 -> V_32 , L_23 , V_21 ) ;
return 0 ;
}
if ( F_26 ( V_217 , & V_25 -> V_218 ) ||
F_26 ( V_219 , & V_25 -> V_218 ) ) {
F_34 ( & V_25 -> V_31 -> V_32 , L_24 ,
V_21 ) ;
return 0 ;
}
V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( V_27 -> V_30 ) {
F_34 ( & V_25 -> V_31 -> V_32 , L_25 ,
V_21 , V_27 -> V_30 , V_27 -> V_33 ) ;
return 0 ;
}
F_16 ( V_27 ) ;
if ( ! V_60 -> V_138 ) {
F_34 ( & V_25 -> V_31 -> V_32 , L_26 , V_21 ) ;
return 0 ;
}
V_138 = F_48 ( V_60 -> V_138 , F_72 () ) ;
if ( ! V_138 -> V_35 ) {
F_34 ( & V_25 -> V_31 -> V_32 , L_27 , V_21 ) ;
goto V_220;
}
V_211 = F_73 ( & V_25 -> V_31 -> V_32 , V_30 , V_33 , V_34 ) ;
if ( V_211 == 0 ) {
F_34 ( & V_25 -> V_31 -> V_32 , L_28 ,
V_30 , V_33 ) ;
goto V_221;
}
V_27 -> V_36 = F_74 ( V_138 -> V_35 , V_222 , & V_27 -> V_37 ) ;
if ( ! V_27 -> V_36 ) {
F_34 ( & V_25 -> V_31 -> V_32 ,
L_29 , V_21 ) ;
goto V_221;
}
V_210 = 0 ;
V_27 -> V_16 = 0 ;
F_75 (sgl, sg, dmacount, i) {
V_216 = F_76 ( V_215 ) ;
V_16 = F_77 ( V_215 ) ;
V_27 -> V_16 += V_16 ;
while ( V_16 ) {
if ( V_210 >= V_223 ) {
F_34 ( & V_25 -> V_31 -> V_32 ,
L_30 ,
V_21 , V_94 , V_210 , V_211 , ( T_4 ) V_216 ) ;
goto V_224;
}
V_213 = V_216 & ( ( T_5 ) V_208 - 1 ) ;
V_214 = F_78 (unsigned int, (bufflen - thisoff), len) ;
if ( ( V_210 != 0 ) && ( V_213 ) )
goto V_224;
if ( ( ( V_94 != ( V_211 - 1 ) ) || ( V_214 != V_16 ) ) &&
( ( V_214 + V_213 ) != V_208 ) )
goto V_224;
V_27 -> V_36 [ V_210 ] = ( T_4 ) ( V_216 - V_213 ) ;
if ( V_210 == 0 )
V_212 = V_213 ;
V_16 -= V_214 ;
V_216 += V_214 ;
V_210 ++ ;
}
}
V_27 -> V_225 = V_213 + V_214 ;
V_27 -> V_212 = V_212 ;
V_27 -> V_226 = V_210 ;
V_27 -> V_35 = V_138 -> V_35 ;
V_27 -> V_30 = V_30 ;
V_27 -> V_33 = V_33 ;
V_27 -> V_21 = V_21 ;
if ( V_207 )
F_70 ( V_227 , & V_27 -> V_29 ) ;
F_70 ( V_228 , & V_27 -> V_29 ) ;
F_79 () ;
return 1 ;
V_224:
F_15 ( V_27 -> V_35 , V_27 -> V_36 , V_27 -> V_37 ) ;
F_16 ( V_27 ) ;
V_221:
F_14 ( & V_25 -> V_31 -> V_32 , V_30 , V_33 , V_34 ) ;
V_220:
F_79 () ;
return 0 ;
}
static int F_80 ( struct V_53 * V_54 , T_3 V_21 ,
struct V_206 * V_30 , unsigned int V_33 )
{
return F_71 ( V_54 , V_21 , V_30 , V_33 , 0 ) ;
}
static int F_81 ( struct V_53 * V_54 , T_3 V_21 ,
struct V_206 * V_30 , unsigned int V_33 )
{
return F_71 ( V_54 , V_21 , V_30 , V_33 , 1 ) ;
}
static void F_82 ( struct V_147 * V_229 ,
struct V_6 * V_7 ,
struct V_26 * V_27 , T_1 V_1 )
{
struct V_230 * V_231 = NULL ;
struct V_232 * V_233 = NULL ;
struct V_234 * V_235 = NULL ;
struct V_24 * V_25 = V_229 -> V_57 -> V_58 ;
T_3 V_94 = V_229 -> V_236 ;
struct V_42 * V_43 ;
T_4 V_237 = 0 ;
bool V_207 ;
if ( F_26 ( V_165 , & V_27 -> V_29 ) ) {
F_29 ( & V_25 -> V_31 -> V_32 ,
L_31 ,
V_27 -> V_21 , V_27 -> V_29 ) ;
return;
}
if ( F_13 ( V_238 , & V_27 -> V_29 ) ) {
F_29 ( & V_25 -> V_31 -> V_32 ,
L_32 ,
V_27 -> V_21 , V_27 -> V_29 ) ;
return;
}
V_235 = F_83 ( V_229 , V_94 ) ;
V_94 ++ ;
if ( V_94 == V_229 -> V_239 )
V_94 = 0 ;
V_235 -> V_240 =
F_84 ( V_241 |
( ( T_4 ) V_242 <<
V_243 ) |
( ( T_4 ) V_27 -> V_212 <<
V_244 ) |
( ( T_4 ) V_27 -> V_225 <<
V_245 ) ) ;
V_235 -> V_246 = F_84 ( 0 ) ;
V_207 = F_26 ( V_227 , & V_27 -> V_29 ) ;
if ( V_207 )
V_235 -> V_240 |=
F_84 ( V_247 ) ;
V_233 = F_85 ( V_229 , V_94 ++ ) ;
if ( V_94 == V_229 -> V_239 )
V_94 = 0 ;
V_233 -> V_248 = F_84 ( V_27 -> V_21 | ( ( T_4 ) V_27 -> V_37 ) ) ;
V_233 -> V_249 = F_84 ( V_27 -> V_226 |
( ( T_4 ) ( V_250 |
V_251 ) <<
V_252 ) ) ;
V_231 = F_86 ( V_229 , V_94 ) ;
V_94 ++ ;
if ( V_94 == V_229 -> V_239 )
V_94 = 0 ;
V_43 = (struct V_42 * ) F_87 ( V_7 ) ;
V_231 -> V_253 = F_88 ( F_89 ( V_43 -> V_254 ) ) ;
V_231 -> V_255 = F_38 ( F_90 ( V_43 -> V_256 ) ) ;
V_231 -> V_257 = F_38 ( V_27 -> V_21 <<
V_258 ) ;
V_237 = V_259 ;
V_237 |= ( T_4 ) ( V_207 ?
V_260 :
V_261 ) ;
V_237 |= ( T_4 ) ( ( V_1 == V_2 || V_1 == V_3 ) ?
V_262 :
V_263 ) ;
V_237 |= ( ( T_4 ) V_7 -> V_264 <<
V_265 ) ;
V_231 -> V_237 = F_84 ( V_237 ) ;
V_229 -> V_236 = V_94 ;
}
static void F_91 ( struct V_147 * V_229 ,
struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_266 * V_267 ;
int V_94 ;
if ( F_13 ( V_165 , & V_27 -> V_29 ) )
return;
V_94 = V_229 -> V_236 ;
V_267 = F_92 ( V_229 , V_94 ) ;
V_94 ++ ;
if ( V_94 == V_229 -> V_239 )
V_94 = 0 ;
V_267 -> V_268 = F_88 ( 0 ) ;
V_267 -> V_269 = F_38 ( 0 ) ;
V_267 -> V_246 = F_38 ( 0 ) ;
V_267 -> V_270 = F_84 (
V_271 |
( V_272 <<
V_273 ) |
( V_274 <<
V_273 ) ) ;
V_229 -> V_236 = V_94 ;
}
static void F_93 ( struct V_147 * V_229 ,
struct V_6 * V_7 , T_1 V_1 )
{
struct V_24 * V_25 = V_229 -> V_57 -> V_58 ;
struct V_59 * V_60 = & V_25 -> V_60 ;
struct V_42 * V_43 ;
struct V_26 * V_27 ;
T_2 V_44 ;
T_1 V_275 ;
T_3 V_21 ;
V_43 = (struct V_42 * ) F_87 ( V_7 ) ;
V_44 = F_19 ( V_43 -> V_45 ) ;
V_275 = V_43 -> V_193 ;
V_27 = NULL ;
if ( ( V_275 == V_276 ) && ( V_44 & V_46 ) ) {
V_21 = F_90 ( V_43 -> V_48 ) ;
if ( F_11 ( V_21 ) ) {
V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( ( V_27 -> V_21 == V_21 ) &&
( F_26 ( V_227 , & V_27 -> V_29 ) ) )
F_82 ( V_229 , V_7 , V_27 , V_1 ) ;
}
} else if ( V_275 == V_277 ) {
V_21 = F_90 ( V_43 -> V_47 ) ;
if ( F_11 ( V_21 ) ) {
V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( ( V_27 -> V_21 == V_21 ) &&
( ! F_26 ( V_227 , & V_27 -> V_29 ) ) )
F_82 ( V_229 , V_7 , V_27 , V_1 ) ;
}
} else if ( V_275 == V_278 ) {
V_21 = F_90 ( V_43 -> V_47 ) ;
if ( F_11 ( V_21 ) ) {
V_27 = & V_60 -> V_27 [ V_21 ] ;
if ( ( V_27 -> V_21 == V_21 ) &&
( ! F_26 ( V_227 , & V_27 -> V_29 ) ) )
F_91 ( V_229 , V_7 , V_27 ) ;
}
}
}
static int F_94 ( struct V_147 * V_229 ,
struct V_6 * V_7 ,
T_2 V_279 , T_1 * V_280 , T_1 V_1 )
{
struct V_266 * V_267 ;
T_2 V_281 , V_282 , V_283 , V_284 ;
struct V_42 * V_43 ;
T_4 V_285 ;
if ( ! F_95 ( V_7 ) )
return 0 ;
if ( F_96 ( V_7 ) -> V_286 != V_287 ) {
F_42 ( V_7 -> V_32 ,
L_33 ,
F_96 ( V_7 ) -> V_286 ) ;
return - V_10 ;
}
* V_280 = F_97 ( V_7 ) + sizeof( struct V_42 ) +
sizeof( struct V_195 ) ;
if ( F_98 ( F_2 ( V_1 ) ) )
V_282 = V_288 ;
else
V_282 = V_289 ;
V_43 = (struct V_42 * ) F_87 ( V_7 ) ;
if ( V_43 -> V_45 [ 2 ] & V_290 )
V_282 |= V_291 ;
V_281 = V_271 ;
V_283 = V_7 -> V_16 - * V_280 ;
V_284 = F_96 ( V_7 ) -> V_292 ;
V_285 =
( ( T_4 ) V_281 << V_293 ) |
( ( T_4 ) V_282 << V_273 ) |
( ( T_4 ) V_283 << V_294 ) |
( ( T_4 ) V_284 << V_295 ) ;
V_267 = F_92 ( V_229 , V_229 -> V_236 ) ;
V_229 -> V_236 ++ ;
if ( V_229 -> V_236 == V_229 -> V_239 )
V_229 -> V_236 = 0 ;
V_267 -> V_268 = 0 ;
V_267 -> V_269 = F_38 ( ( V_279 & V_296 )
>> V_297 ) ;
V_267 -> V_270 = F_84 ( V_285 ) ;
return 1 ;
}
static void F_99 ( struct V_147 * V_229 ,
struct V_6 * V_7 ,
struct V_298 * V_299 ,
T_2 V_279 , T_1 V_280 , T_1 V_11 )
{
T_2 V_300 = 0 ;
T_2 V_301 = 0 ;
T_2 V_302 ;
V_301 = V_303 ;
V_302 = F_100 ( V_7 ) ;
if ( V_279 & V_304 )
V_302 += sizeof( struct V_52 ) ;
if ( V_7 -> V_305 == F_23 ( V_102 ) ) {
V_302 -= 2 ;
V_301 |= ( V_306 | F_9 ( V_11 ) ) ;
V_300 |= ( ( ( ( sizeof( struct V_8 ) + 2 ) >> 2 ) <<
V_307 ) |
( ( sizeof( struct V_42 ) >> 2 ) <<
V_308 ) ) ;
F_101 ( V_7 , V_7 -> V_16 - sizeof( struct V_195 ) ) ;
}
V_300 |= ( V_302 >> 1 ) << V_309 ;
F_102 ( V_229 , V_7 , V_299 , V_279 , V_280 , V_301 , V_300 ) ;
}
static inline int F_103 ( struct V_6 * V_7 )
{
T_6 V_305 = V_7 -> V_305 ;
F_104 ( V_7 ) ;
V_7 -> V_310 = sizeof( struct V_311 ) ;
if ( V_305 == F_23 ( V_51 ) ) {
struct V_312 * V_313 = (struct V_312 * ) F_22 ( V_7 ) ;
V_305 = V_313 -> V_314 ;
V_7 -> V_310 += sizeof( struct V_52 ) ;
}
if ( ( V_305 != F_23 ( V_315 ) ) &&
( V_305 != F_23 ( V_102 ) ) )
return - V_10 ;
F_105 ( V_7 , V_7 -> V_310 ) ;
if ( V_305 == F_23 ( V_315 ) )
return 0 ;
F_106 ( V_7 , V_7 -> V_310 + sizeof( struct V_8 ) ) ;
return 0 ;
}
static T_7 F_107 ( struct V_6 * V_7 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = F_25 ( V_7 -> V_32 ) ;
struct V_106 * V_57 = V_56 -> V_57 ;
struct V_147 * V_229 = V_57 -> V_316 [ V_7 -> V_264 ] ;
struct V_298 * V_299 ;
T_2 V_279 = 0 ;
int V_317 , V_239 ;
T_1 V_280 = 0 ;
T_1 V_1 = 0 ;
T_1 V_11 = 0 ;
if ( F_103 ( V_7 ) )
goto V_318;
V_239 = F_108 ( V_7 ) ;
if ( F_109 ( V_7 , V_239 ) ) {
if ( F_110 ( V_7 ) )
goto V_318;
V_239 = F_111 ( V_7 -> V_16 ) ;
V_229 -> V_319 . V_320 ++ ;
}
if ( F_112 ( V_229 , V_239 + 4 + 1 ) ) {
V_229 -> V_319 . V_321 ++ ;
return V_322 ;
}
if ( F_113 ( V_7 , V_229 , & V_279 ) )
goto V_318;
V_299 = & V_229 -> V_323 [ V_229 -> V_236 ] ;
if ( V_7 -> V_305 == F_23 ( V_315 ) )
goto V_324;
if ( F_4 ( V_7 , & V_1 ) || F_7 ( V_7 , & V_11 ) ) {
F_42 ( V_54 , L_34 , V_1 , V_11 ) ;
goto V_318;
}
V_279 |= V_325 ;
V_317 = F_94 ( V_229 , V_7 , V_279 , & V_280 , V_1 ) ;
if ( V_317 < 0 )
goto V_318;
else if ( V_317 )
V_279 |= V_326 ;
else
F_93 ( V_229 , V_7 , V_1 ) ;
V_324:
F_99 ( V_229 , V_7 , V_299 , V_279 , V_280 , V_11 ) ;
F_112 ( V_229 , V_327 ) ;
return V_328 ;
V_318:
F_114 ( V_7 ) ;
return V_328 ;
}
static int F_115 ( struct V_53 * V_54 , int V_329 )
{
F_116 ( V_54 , L_35 ) ;
return - V_111 ;
}
static int F_117 ( struct V_53 * V_54 ,
T_8 V_330 )
{
struct V_55 * V_56 = F_25 ( V_54 ) ;
struct V_106 * V_57 = V_56 -> V_57 ;
if ( V_330 & V_331 )
F_118 ( V_57 ) ;
else
F_119 ( V_57 ) ;
return 0 ;
}
void F_120 ( struct V_53 * V_54 , struct V_106 * V_57 )
{
struct V_63 * V_64 = & V_57 -> V_58 -> V_64 ;
struct V_24 * V_25 = V_57 -> V_58 ;
if ( V_57 -> type != V_132 )
return;
V_54 -> V_330 = ( V_332 |
V_331 |
V_333 ) ;
V_54 -> V_334 = V_54 -> V_330 ;
V_54 -> V_334 &= ~ ( V_332 |
V_331 |
V_333 ) ;
V_54 -> V_335 = V_23 - 1 ;
V_54 -> V_330 |= V_336 ;
V_54 -> V_334 |= V_336 ;
V_54 -> V_337 |= V_54 -> V_330 ;
V_54 -> V_338 |= V_339 ;
V_54 -> V_338 |= V_340 ;
F_121 ( V_54 -> V_341 , L_36 , V_342 - 1 ) ;
V_54 -> V_343 = V_85 ;
F_122 ( V_54 , & V_25 -> V_31 -> V_32 ) ;
F_123 ( V_54 , & V_344 ) ;
V_54 -> V_345 = 1 ;
F_124 ( & V_57 -> V_346 ) ;
F_125 ( V_57 , V_64 -> V_347 . V_348 , 0 , false , false ) ;
F_125 ( V_57 , ( T_1 [ 6 ] ) V_349 , 0 , false , false ) ;
F_125 ( V_57 , V_350 , 0 , false , false ) ;
F_125 ( V_57 , V_351 , 0 , false , false ) ;
F_126 ( & V_57 -> V_346 ) ;
F_127 ( V_54 -> V_352 , V_64 -> V_347 . V_348 ) ;
F_127 ( V_54 -> V_353 , V_64 -> V_347 . V_348 ) ;
V_54 -> V_354 = & V_355 ;
}
void F_128 ( struct V_24 * V_25 )
{
struct V_106 * V_57 ;
T_3 V_145 ;
int V_94 ;
if ( ! ( V_25 -> V_29 & V_66 ) )
return;
for ( V_94 = 0 ; V_94 < V_25 -> V_356 ; V_94 ++ ) {
V_57 = V_25 -> V_57 [ V_94 ] ;
if ( V_57 && V_57 -> type == V_132 ) {
F_29 ( & V_25 -> V_31 -> V_32 ,
L_37 ) ;
return;
}
}
V_145 = V_25 -> V_57 [ V_25 -> V_357 ] -> V_145 ;
V_57 = F_129 ( V_25 , V_132 , V_145 , 0 ) ;
if ( V_57 ) {
F_28 ( & V_25 -> V_31 -> V_32 ,
L_38 ,
V_57 -> V_145 , V_57 -> V_39 , V_57 -> V_115 , V_145 ) ;
} else {
F_34 ( & V_25 -> V_31 -> V_32 , L_39 ) ;
}
}
