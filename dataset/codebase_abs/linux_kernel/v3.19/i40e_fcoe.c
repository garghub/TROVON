static inline bool F_1 ( T_1 V_1 )
{
return V_1 == V_2 ;
}
static inline bool F_2 ( T_1 V_1 )
{
return ( V_1 >= V_3 ) &&
( V_1 <= V_4 ) ;
}
static inline bool F_3 ( T_2 V_5 )
{
return ( V_5 == V_6 ) || ( V_5 == V_7 ) ;
}
static inline bool F_4 ( T_2 V_5 )
{
return ( V_5 == V_8 ) || ( V_5 == V_9 ) ;
}
static inline bool F_5 ( T_2 V_5 )
{
return F_3 ( V_5 ) ||
F_4 ( V_5 ) ;
}
static inline int F_6 ( struct V_10 * V_11 , T_2 * V_5 )
{
* V_5 = ( (struct V_12 * ) F_7 ( V_11 ) ) -> V_13 ;
if ( ! F_5 ( * V_5 ) )
return - V_14 ;
return 0 ;
}
static inline bool F_8 ( T_2 V_15 )
{
return ( V_15 == V_16 ) || ( V_15 == V_17 ) ||
( V_15 == V_18 ) || ( V_15 == V_19 ) ;
}
static inline int F_9 ( struct V_10 * V_11 , T_2 * V_15 )
{
F_10 ( V_11 , V_11 -> V_20 - 4 , V_15 , 1 ) ;
if ( ! F_8 ( * V_15 ) )
return - V_14 ;
return 0 ;
}
static inline T_3 F_11 ( T_2 V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_21 ;
case V_17 :
return V_22 ;
case V_18 :
return V_23 ;
case V_19 :
return V_24 ;
default:
F_12 ( L_1 , V_15 ) ;
return 0 ;
}
}
static inline bool F_13 ( T_1 V_25 )
{
return ( V_25 != V_26 ) && ( V_25 < V_27 ) ;
}
static inline void F_14 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
if ( F_15 ( V_32 , & V_31 -> V_33 ) )
return;
if ( V_31 -> V_34 ) {
F_16 ( & V_29 -> V_35 -> V_36 , V_31 -> V_34 , V_31 -> V_37 ,
V_38 ) ;
V_31 -> V_34 = NULL ;
V_31 -> V_37 = 0 ;
}
if ( V_31 -> V_39 ) {
F_17 ( V_31 -> V_39 , V_31 -> V_40 , V_31 -> V_41 ) ;
V_31 -> V_39 = NULL ;
}
}
static inline void F_18 ( struct V_30 * V_31 )
{
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_25 = V_26 ;
V_31 -> V_33 = V_42 ;
}
static inline bool F_19 ( T_2 V_43 )
{
return ( V_43 == V_44 ) ||
( V_43 == V_45 ) ;
}
static inline T_1 F_20 ( struct V_46 * V_47 )
{
T_3 V_48 = F_21 ( V_47 -> V_49 ) ;
return ( V_48 & V_50 ) ?
F_22 ( V_47 -> V_51 ) :
F_22 ( V_47 -> V_52 ) ;
}
static inline struct V_46 * F_23 (
struct V_10 * V_11 )
{
void * V_47 = V_11 -> V_53 + sizeof( struct V_12 ) ;
if ( F_24 ( V_11 ) -> V_54 == F_25 ( V_55 ) )
V_47 += sizeof( struct V_56 ) ;
return (struct V_46 * ) V_47 ;
}
static int F_26 ( struct V_57 * V_58 , T_1 V_25 )
{
struct V_59 * V_60 = F_27 ( V_58 ) ;
struct V_28 * V_29 = V_60 -> V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
int V_20 = 0 ;
struct V_30 * V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( ! V_64 || ! V_31 )
goto V_65;
if ( F_28 ( V_66 , & V_31 -> V_33 ) )
V_20 = V_31 -> V_20 ;
F_14 ( V_29 , V_31 ) ;
V_65:
return V_20 ;
}
int F_29 ( struct V_28 * V_29 )
{
struct V_67 * V_68 = & V_29 -> V_68 ;
T_3 V_69 ;
V_29 -> V_33 &= ~ V_70 ;
V_29 -> V_71 = 0 ;
V_29 -> V_72 = 0 ;
V_29 -> V_73 = 0 ;
if ( ! V_29 -> V_68 . V_74 . V_64 ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_2 ) ;
return 0 ;
}
if ( ! V_29 -> V_68 . V_74 . V_75 ) {
F_31 ( & V_29 -> V_35 -> V_36 ,
L_3 ) ;
return 0 ;
}
V_69 = F_32 ( V_68 , F_33 ( 1 ) ) ;
V_69 |= 1 << ( V_76 - 32 ) ;
V_69 |= 1 << ( V_77 - 32 ) ;
V_69 &= V_78 ;
F_34 ( V_68 , F_33 ( 1 ) , V_69 ) ;
V_29 -> V_33 |= V_70 ;
V_29 -> V_71 = V_79 ;
V_29 -> V_72 = ( 1 << V_80 ) *
V_81 ;
V_29 -> V_73 = V_29 -> V_72 +
( 1 << V_82 ) *
V_83 ;
V_29 -> V_84 . V_85 = V_82 ;
V_29 -> V_84 . V_86 = V_80 ;
V_69 = F_32 ( V_68 , V_87 ) ;
V_69 &= ~ V_88 ;
V_69 |= ( ( V_89 + V_90 + V_91 + V_92 )
<< V_93 ) ;
F_34 ( V_68 , V_87 , V_69 ) ;
F_30 ( & V_29 -> V_35 -> V_36 , L_4 ) ;
return 0 ;
}
T_2 F_35 ( struct V_28 * V_29 )
{
struct V_94 V_95 ;
struct V_67 * V_68 = & V_29 -> V_68 ;
T_2 V_96 = 0 ;
T_2 V_97 , V_98 ;
struct V_99 * V_100 = & V_68 -> V_101 ;
for ( V_98 = 0 ; V_98 < V_100 -> V_102 ; V_98 ++ ) {
V_95 = V_100 -> V_95 [ V_98 ] ;
if ( V_95 . V_103 == V_104 &&
V_95 . V_105 == V_106 ) {
V_97 = V_100 -> V_107 . V_108 [ V_95 . V_109 ] ;
V_96 |= ( 1 << V_97 ) ;
break;
}
}
V_96 = V_96 ? V_96 : 0x1 ;
return V_96 ;
}
int F_36 ( struct V_110 * V_61 , struct V_111 * V_112 )
{
struct V_113 * V_114 = & V_112 -> V_114 ;
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_67 * V_68 = & V_29 -> V_68 ;
T_2 V_96 = 0 ;
if ( ! ( V_29 -> V_33 & V_70 ) ) {
F_37 ( & V_29 -> V_35 -> V_36 ,
L_5 ) ;
return - V_115 ;
}
V_112 -> V_116 = V_68 -> V_117 ;
V_112 -> V_118 = 0 ;
V_112 -> V_119 = V_61 -> V_119 ;
V_112 -> V_120 = 0x1 ;
V_112 -> V_33 = V_121 ;
V_114 -> V_122 |= F_38 ( V_123 |
V_124 ) ;
V_114 -> V_122 &= F_38 ( ~ ( V_125 |
V_126 |
V_127 |
V_128 |
V_129 ) ) ;
V_96 = F_35 ( V_29 ) ;
F_39 ( V_61 , V_112 , V_96 , true ) ;
V_114 -> V_130 = V_131 ;
return 0 ;
}
int F_40 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_27 ( V_58 ) ;
struct V_110 * V_61 = V_60 -> V_61 ;
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
if ( ! ( V_29 -> V_33 & V_70 ) ) {
F_41 ( V_58 , L_6 ) ;
return - V_132 ;
}
if ( V_61 -> type != V_133 ) {
F_41 ( V_58 , L_7 ) ;
return - V_134 ;
}
F_42 ( & V_64 -> V_135 ) ;
return 0 ;
}
int F_43 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = F_27 ( V_58 ) ;
struct V_110 * V_61 = V_60 -> V_61 ;
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
if ( ! ( V_29 -> V_33 & V_70 ) ) {
F_41 ( V_58 , L_8 ) ;
return - V_132 ;
}
if ( V_61 -> type != V_133 )
return - V_134 ;
if ( ! F_44 ( & V_64 -> V_135 ) )
return - V_14 ;
F_45 ( V_58 , L_9 ) ;
return 0 ;
}
static void F_46 ( struct V_63 * V_64 ,
struct V_136 * V_36 ,
unsigned int V_137 )
{
struct V_138 * V_139 ;
V_139 = F_47 ( V_64 -> V_139 , V_137 ) ;
if ( ! V_139 -> V_39 ) {
F_31 ( V_36 , L_10 , V_137 ) ;
return;
}
F_48 ( V_139 -> V_39 ) ;
V_139 -> V_39 = NULL ;
}
static int F_49 ( struct V_63 * V_64 ,
struct V_136 * V_36 ,
unsigned int V_137 )
{
struct V_138 * V_139 ;
struct V_140 * V_39 ;
char V_141 [ 32 ] ;
V_139 = F_47 ( V_64 -> V_139 , V_137 ) ;
if ( V_139 && V_139 -> V_39 ) {
F_31 ( V_36 , L_11 , V_137 ) ;
return 0 ;
}
snprintf ( V_141 , sizeof( V_141 ) , L_12 , V_137 ) ;
V_39 = F_50 ( V_141 , V_36 , V_142 ,
V_143 , V_144 ) ;
if ( ! V_39 ) {
F_37 ( V_36 , L_13 , V_141 ) ;
return - V_145 ;
}
V_139 -> V_39 = V_39 ;
return 0 ;
}
void F_51 ( struct V_110 * V_61 )
{
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
int V_137 , V_98 ;
if ( V_61 -> type != V_133 )
return;
if ( ! V_64 -> V_139 )
return;
for ( V_98 = 0 ; V_98 < V_27 ; V_98 ++ )
F_26 ( V_61 -> V_58 , V_98 ) ;
F_52 (cpu)
F_46 ( V_64 , & V_29 -> V_35 -> V_36 , V_137 ) ;
F_53 ( V_64 -> V_139 ) ;
V_64 -> V_139 = NULL ;
F_45 ( V_61 -> V_58 , L_14 ,
V_61 -> V_43 , V_61 -> V_146 ) ;
}
int F_54 ( struct V_110 * V_61 )
{
struct V_28 * V_29 = V_61 -> V_62 ;
struct V_136 * V_36 = & V_29 -> V_35 -> V_36 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
unsigned int V_137 ;
int V_98 ;
if ( V_61 -> type != V_133 )
return - V_132 ;
if ( V_64 -> V_139 )
return - V_147 ;
V_64 -> V_139 = F_55 ( struct V_138 ) ;
if ( ! V_64 -> V_139 ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_15 ) ;
return - V_145 ;
}
F_52 (cpu) {
if ( ! F_49 ( V_64 , V_36 , V_137 ) )
continue;
F_37 ( V_36 , L_16 , V_137 ) ;
F_51 ( V_61 ) ;
return - V_145 ;
}
for ( V_98 = 0 ; V_98 < V_27 ; V_98 ++ )
F_18 ( & V_64 -> V_31 [ V_98 ] ) ;
F_45 ( V_61 -> V_58 , L_17 ,
V_61 -> V_43 , V_61 -> V_146 ) ;
return 0 ;
}
void F_56 ( struct V_148 * V_149 ,
union V_150 * V_151 , T_2 V_152 )
{
struct V_28 * V_29 = V_149 -> V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
struct V_30 * V_31 ;
T_3 error ;
T_1 V_25 ;
T_4 V_153 ;
if ( ! F_19 ( V_152 ) )
return;
V_25 = F_57 ( V_151 -> V_154 . V_155 . V_156 . V_157 ) &
( V_27 - 1 ) ;
if ( ! F_13 ( V_25 ) )
return;
V_31 = & V_64 -> V_31 [ V_25 ] ;
F_58 ( V_25 != V_31 -> V_25 ) ;
V_153 = F_59 ( V_151 -> V_154 . V_158 . V_159 ) ;
error = ( V_153 & V_160 ) >>
V_161 ;
if ( V_152 == V_44 ) {
if ( F_60 ( error ) ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_18 ,
V_25 , V_31 -> V_25 ) ;
V_31 -> V_162 |= V_163 ;
}
if ( F_61 ( error ) ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_19 ,
V_25 , V_31 -> V_25 ) ;
V_31 -> V_162 |= V_164 ;
}
}
if ( V_152 == V_45 ) {
if ( F_62 ( error ) ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_20 ,
V_25 , V_31 -> V_25 ) ;
V_31 -> V_162 |= V_165 ;
}
F_63 ( V_166 , & V_31 -> V_33 ) ;
}
F_14 ( V_29 , V_31 ) ;
F_18 ( V_31 ) ;
}
int F_64 ( struct V_148 * V_149 ,
union V_150 * V_151 ,
struct V_10 * V_11 )
{
struct V_28 * V_29 = V_149 -> V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
struct V_46 * V_47 = NULL ;
struct V_30 * V_31 = NULL ;
T_3 V_167 , V_168 ;
T_3 error , V_169 ;
int V_170 = - V_14 ;
T_1 V_1 ;
T_1 V_25 ;
T_4 V_153 ;
V_153 = F_59 ( V_151 -> V_154 . V_158 . V_159 ) ;
V_1 = ( V_153 & V_171 ) >> V_172 ;
if ( ! F_2 ( V_1 ) )
goto V_173;
error = ( V_153 & V_174 ) >> V_175 ;
V_169 = ( error >> V_176 ) &
V_177 ;
if ( F_65 ( V_169 == V_178 ) ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_21 ) ;
V_11 -> V_179 = V_180 ;
} else {
V_11 -> V_179 = V_181 ;
}
V_167 = ( V_153 & V_182 ) >> V_183 ;
V_168 = ( V_167 >> V_184 ) &
V_185 ;
V_47 = F_23 ( V_11 ) ;
V_25 = F_20 ( V_47 ) ;
if ( ! F_13 ( V_25 ) )
goto V_173;
if ( V_168 == V_186 )
goto V_173;
V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( ! V_31 -> V_34 )
goto V_173;
V_25 = F_66 ( V_151 -> V_154 . V_155 . V_187 . V_188 . V_189 ) ;
if ( V_31 -> V_25 != V_25 ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_22 ,
V_31 -> V_25 , V_25 ) ;
goto V_190;
}
if ( V_31 -> V_169 ) {
F_37 ( & V_29 -> V_35 -> V_36 , L_23 ,
V_25 , V_31 -> V_169 , V_169 ) ;
goto V_190;
}
V_31 -> V_20 = F_57 ( V_151 -> V_154 . V_155 . V_156 . V_157 ) ;
V_31 -> V_169 = V_169 ;
if ( V_168 == V_191 ) {
T_3 V_48 = F_21 ( V_47 -> V_49 ) ;
if ( ( V_48 & V_192 ) &&
( V_47 -> V_193 == V_194 ) ) {
struct V_195 * V_196 = NULL ;
V_196 = (struct V_195 * ) F_67 ( V_11 , sizeof( * V_196 ) ) ;
V_196 -> V_197 = V_17 ;
} else {
V_170 = 0 ;
goto V_173;
}
}
V_190:
F_14 ( V_29 , V_31 ) ;
if ( V_31 -> V_20 && ! V_31 -> V_169 ) {
int V_198 ;
V_170 = V_31 -> V_20 ;
F_18 ( V_31 ) ;
V_31 -> V_20 = V_170 ;
V_198 = F_68 ( V_170 , 2048 ) ;
V_149 -> V_199 . V_200 += V_170 ;
V_149 -> V_199 . V_201 += V_198 ;
V_149 -> V_202 -> V_203 . V_204 += V_170 ;
V_149 -> V_202 -> V_203 . V_205 += V_198 ;
F_69 ( V_66 , & V_31 -> V_33 ) ;
}
V_173:
return V_170 ;
}
static int F_70 ( struct V_57 * V_58 , T_1 V_25 ,
struct V_206 * V_34 , unsigned int V_37 ,
int V_207 )
{
static const unsigned int V_208 = V_209 ;
struct V_59 * V_60 = F_27 ( V_58 ) ;
struct V_138 * V_139 ;
struct V_28 * V_29 = V_60 -> V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
unsigned int V_98 , V_210 , V_211 ;
struct V_30 * V_31 ;
unsigned int V_212 = 0 ;
unsigned int V_213 = 0 ;
unsigned int V_214 = 0 ;
struct V_206 * V_215 ;
T_5 V_216 = 0 ;
unsigned int V_20 ;
if ( V_25 >= V_27 ) {
F_31 ( & V_29 -> V_35 -> V_36 , L_24 , V_25 ) ;
return 0 ;
}
if ( F_28 ( V_217 , & V_29 -> V_218 ) ||
F_28 ( V_219 , & V_29 -> V_218 ) ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_25 ,
V_25 ) ;
return 0 ;
}
V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( V_31 -> V_34 ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_26 ,
V_25 , V_31 -> V_34 , V_31 -> V_37 ) ;
return 0 ;
}
F_18 ( V_31 ) ;
if ( ! V_64 -> V_139 ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_27 , V_25 ) ;
return 0 ;
}
V_139 = F_47 ( V_64 -> V_139 , F_71 () ) ;
if ( ! V_139 -> V_39 ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_28 , V_25 ) ;
goto V_220;
}
V_211 = F_72 ( & V_29 -> V_35 -> V_36 , V_34 , V_37 , V_38 ) ;
if ( V_211 == 0 ) {
F_30 ( & V_29 -> V_35 -> V_36 , L_29 ,
V_34 , V_37 ) ;
goto V_221;
}
V_31 -> V_40 = F_73 ( V_139 -> V_39 , V_222 , & V_31 -> V_41 ) ;
if ( ! V_31 -> V_40 ) {
F_30 ( & V_29 -> V_35 -> V_36 ,
L_30 , V_25 ) ;
goto V_221;
}
V_210 = 0 ;
V_31 -> V_20 = 0 ;
F_74 (sgl, sg, dmacount, i) {
V_216 = F_75 ( V_215 ) ;
V_20 = F_76 ( V_215 ) ;
V_31 -> V_20 += V_20 ;
while ( V_20 ) {
if ( V_210 >= V_223 ) {
F_30 ( & V_29 -> V_35 -> V_36 ,
L_31 ,
V_25 , V_98 , V_210 , V_211 , ( T_4 ) V_216 ) ;
goto V_224;
}
V_213 = V_216 & ( ( T_5 ) V_208 - 1 ) ;
V_214 = F_77 (unsigned int, (bufflen - thisoff), len) ;
if ( ( V_210 != 0 ) && ( V_213 ) )
goto V_224;
if ( ( ( V_98 != ( V_211 - 1 ) ) || ( V_214 != V_20 ) ) &&
( ( V_214 + V_213 ) != V_208 ) )
goto V_224;
V_31 -> V_40 [ V_210 ] = ( T_4 ) ( V_216 - V_213 ) ;
if ( V_210 == 0 )
V_212 = V_213 ;
V_20 -= V_214 ;
V_216 += V_214 ;
V_210 ++ ;
}
}
V_31 -> V_225 = V_213 + V_214 ;
V_31 -> V_212 = V_212 ;
V_31 -> V_226 = V_210 ;
V_31 -> V_39 = V_139 -> V_39 ;
V_31 -> V_34 = V_34 ;
V_31 -> V_37 = V_37 ;
V_31 -> V_25 = V_25 ;
if ( V_207 )
F_69 ( V_227 , & V_31 -> V_33 ) ;
F_69 ( V_228 , & V_31 -> V_33 ) ;
F_78 () ;
return 1 ;
V_224:
F_17 ( V_31 -> V_39 , V_31 -> V_40 , V_31 -> V_41 ) ;
F_18 ( V_31 ) ;
V_221:
F_16 ( & V_29 -> V_35 -> V_36 , V_34 , V_37 , V_38 ) ;
V_220:
F_78 () ;
return 0 ;
}
static int F_79 ( struct V_57 * V_58 , T_1 V_25 ,
struct V_206 * V_34 , unsigned int V_37 )
{
return F_70 ( V_58 , V_25 , V_34 , V_37 , 0 ) ;
}
static int F_80 ( struct V_57 * V_58 , T_1 V_25 ,
struct V_206 * V_34 , unsigned int V_37 )
{
return F_70 ( V_58 , V_25 , V_34 , V_37 , 1 ) ;
}
static void F_81 ( struct V_148 * V_229 ,
struct V_10 * V_11 ,
struct V_30 * V_31 , T_2 V_5 )
{
struct V_230 * V_231 = NULL ;
struct V_232 * V_233 = NULL ;
struct V_234 * V_235 = NULL ;
struct V_28 * V_29 = V_229 -> V_61 -> V_62 ;
T_1 V_98 = V_229 -> V_236 ;
struct V_46 * V_47 ;
T_4 V_237 = 0 ;
bool V_207 ;
if ( F_28 ( V_166 , & V_31 -> V_33 ) ) {
F_31 ( & V_29 -> V_35 -> V_36 ,
L_32 ,
V_31 -> V_25 , V_31 -> V_33 ) ;
return;
}
if ( F_15 ( V_238 , & V_31 -> V_33 ) ) {
F_31 ( & V_29 -> V_35 -> V_36 ,
L_33 ,
V_31 -> V_25 , V_31 -> V_33 ) ;
return;
}
V_235 = F_82 ( V_229 , V_98 ) ;
V_98 ++ ;
if ( V_98 == V_229 -> V_239 )
V_98 = 0 ;
V_235 -> V_240 =
F_83 ( V_241 |
( ( T_4 ) V_242 <<
V_243 ) |
( ( T_4 ) V_31 -> V_212 <<
V_244 ) |
( ( T_4 ) V_31 -> V_225 <<
V_245 ) ) ;
V_235 -> V_246 = F_83 ( 0 ) ;
V_207 = F_28 ( V_227 , & V_31 -> V_33 ) ;
if ( V_207 )
V_235 -> V_240 |=
F_83 ( V_247 ) ;
V_233 = F_84 ( V_229 , V_98 ++ ) ;
if ( V_98 == V_229 -> V_239 )
V_98 = 0 ;
V_233 -> V_248 = F_83 ( V_31 -> V_25 | ( ( T_4 ) V_31 -> V_41 ) ) ;
V_233 -> V_249 = F_83 ( V_31 -> V_226 |
( ( T_4 ) ( V_250 |
V_251 ) <<
V_252 ) ) ;
V_231 = F_85 ( V_229 , V_98 ) ;
V_98 ++ ;
if ( V_98 == V_229 -> V_239 )
V_98 = 0 ;
V_47 = (struct V_46 * ) F_86 ( V_11 ) ;
V_231 -> V_253 = F_87 ( F_88 ( V_47 -> V_254 ) ) ;
V_231 -> V_255 = F_38 ( F_89 ( V_47 -> V_256 ) ) ;
V_231 -> V_257 = F_38 ( V_31 -> V_25 <<
V_258 ) ;
V_237 = V_259 ;
V_237 |= ( T_4 ) ( V_207 ?
V_260 :
V_261 ) ;
V_237 |= ( T_4 ) ( ( V_5 == V_6 || V_5 == V_7 ) ?
V_262 :
V_263 ) ;
V_237 |= ( ( T_4 ) V_11 -> V_264 <<
V_265 ) ;
V_231 -> V_237 = F_83 ( V_237 ) ;
V_229 -> V_236 = V_98 ;
}
static void F_90 ( struct V_148 * V_229 ,
struct V_10 * V_11 ,
struct V_30 * V_31 )
{
struct V_266 * V_267 ;
int V_98 ;
if ( F_15 ( V_166 , & V_31 -> V_33 ) )
return;
V_98 = V_229 -> V_236 ;
V_267 = F_91 ( V_229 , V_98 ) ;
V_98 ++ ;
if ( V_98 == V_229 -> V_239 )
V_98 = 0 ;
V_267 -> V_268 = F_87 ( 0 ) ;
V_267 -> V_269 = F_38 ( 0 ) ;
V_267 -> V_246 = F_38 ( 0 ) ;
V_267 -> V_270 = F_83 (
V_271 |
( V_272 <<
V_273 ) |
( V_274 <<
V_273 ) ) ;
V_229 -> V_236 = V_98 ;
}
static void F_92 ( struct V_148 * V_229 ,
struct V_10 * V_11 , T_2 V_5 )
{
struct V_28 * V_29 = V_229 -> V_61 -> V_62 ;
struct V_63 * V_64 = & V_29 -> V_64 ;
struct V_46 * V_47 ;
struct V_30 * V_31 ;
T_3 V_48 ;
T_2 V_275 ;
T_1 V_25 ;
V_47 = (struct V_46 * ) F_86 ( V_11 ) ;
V_48 = F_21 ( V_47 -> V_49 ) ;
V_275 = V_47 -> V_193 ;
V_31 = NULL ;
if ( ( V_275 == V_276 ) && ( V_48 & V_50 ) ) {
V_25 = F_89 ( V_47 -> V_52 ) ;
if ( F_13 ( V_25 ) ) {
V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( ( V_31 -> V_25 == V_25 ) &&
( F_28 ( V_227 , & V_31 -> V_33 ) ) )
F_81 ( V_229 , V_11 , V_31 , V_5 ) ;
}
} else if ( V_275 == V_277 ) {
V_25 = F_89 ( V_47 -> V_51 ) ;
if ( F_13 ( V_25 ) ) {
V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( ( V_31 -> V_25 == V_25 ) &&
( ! F_28 ( V_227 , & V_31 -> V_33 ) ) )
F_81 ( V_229 , V_11 , V_31 , V_5 ) ;
}
} else if ( V_275 == V_278 ) {
V_25 = F_89 ( V_47 -> V_51 ) ;
if ( F_13 ( V_25 ) ) {
V_31 = & V_64 -> V_31 [ V_25 ] ;
if ( ( V_31 -> V_25 == V_25 ) &&
( ! F_28 ( V_227 , & V_31 -> V_33 ) ) )
F_90 ( V_229 , V_11 , V_31 ) ;
}
}
}
static int F_93 ( struct V_148 * V_229 ,
struct V_10 * V_11 ,
T_3 V_279 , T_2 * V_280 , T_2 V_5 )
{
struct V_266 * V_267 ;
T_3 V_281 , V_282 , V_283 , V_284 ;
struct V_46 * V_47 ;
T_4 V_285 ;
if ( ! F_94 ( V_11 ) )
return 0 ;
if ( F_95 ( V_11 ) -> V_286 != V_287 ) {
F_41 ( V_11 -> V_36 ,
L_34 ,
F_95 ( V_11 ) -> V_286 ) ;
return - V_14 ;
}
* V_280 = F_96 ( V_11 ) + sizeof( struct V_46 ) +
sizeof( struct V_195 ) ;
if ( F_97 ( F_4 ( V_5 ) ) )
V_282 = V_288 ;
else
V_282 = V_289 ;
V_47 = (struct V_46 * ) F_86 ( V_11 ) ;
if ( V_47 -> V_49 [ 2 ] & V_290 )
V_282 |= V_291 ;
V_281 = V_271 ;
V_283 = V_11 -> V_20 - * V_280 ;
V_284 = F_95 ( V_11 ) -> V_292 ;
V_285 =
( ( T_4 ) V_281 << V_293 ) |
( ( T_4 ) V_282 << V_273 ) |
( ( T_4 ) V_283 << V_294 ) |
( ( T_4 ) V_284 << V_295 ) ;
V_267 = F_91 ( V_229 , V_229 -> V_236 ) ;
V_229 -> V_236 ++ ;
if ( V_229 -> V_236 == V_229 -> V_239 )
V_229 -> V_236 = 0 ;
V_267 -> V_268 = 0 ;
V_267 -> V_269 = F_38 ( ( V_279 & V_296 )
>> V_297 ) ;
V_267 -> V_270 = F_83 ( V_285 ) ;
return 1 ;
}
static void F_98 ( struct V_148 * V_229 ,
struct V_10 * V_11 ,
struct V_298 * V_299 ,
T_3 V_279 , T_2 V_280 , T_2 V_15 )
{
T_3 V_300 = 0 ;
T_3 V_301 = 0 ;
T_3 V_302 ;
V_301 = V_303 ;
V_302 = F_99 ( V_11 ) ;
if ( V_279 & V_304 )
V_302 += sizeof( struct V_56 ) ;
if ( V_11 -> V_305 == F_25 ( V_106 ) ) {
V_302 -= 2 ;
V_301 |= ( V_306 | F_11 ( V_15 ) ) ;
V_300 |= ( ( ( ( sizeof( struct V_12 ) + 2 ) >> 2 ) <<
V_307 ) |
( ( sizeof( struct V_46 ) >> 2 ) <<
V_308 ) ) ;
F_100 ( V_11 , V_11 -> V_20 - sizeof( struct V_195 ) ) ;
}
V_300 |= ( V_302 >> 1 ) << V_309 ;
return F_101 ( V_229 , V_11 , V_299 , V_279 , V_280 ,
V_301 , V_300 ) ;
}
static inline int F_102 ( struct V_10 * V_11 )
{
T_6 V_305 = V_11 -> V_305 ;
F_103 ( V_11 ) ;
V_11 -> V_310 = sizeof( struct V_311 ) ;
if ( V_305 == F_25 ( V_55 ) ) {
struct V_312 * V_313 = (struct V_312 * ) F_24 ( V_11 ) ;
V_305 = V_313 -> V_314 ;
V_11 -> V_310 += sizeof( struct V_56 ) ;
}
if ( ( V_305 != F_25 ( V_315 ) ) &&
( V_305 != F_25 ( V_106 ) ) )
return - V_14 ;
F_104 ( V_11 , V_11 -> V_310 ) ;
if ( V_305 == F_25 ( V_315 ) )
return 0 ;
F_105 ( V_11 , V_11 -> V_310 + sizeof( struct V_12 ) ) ;
return 0 ;
}
static T_7 F_106 ( struct V_10 * V_11 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = F_27 ( V_11 -> V_36 ) ;
struct V_110 * V_61 = V_60 -> V_61 ;
struct V_148 * V_229 = V_61 -> V_316 [ V_11 -> V_264 ] ;
struct V_298 * V_299 ;
T_3 V_279 = 0 ;
T_2 V_280 = 0 ;
T_2 V_5 = 0 ;
T_2 V_15 = 0 ;
int V_317 ;
if ( F_102 ( V_11 ) )
goto V_318;
if ( ! F_107 ( V_11 , V_229 ) )
return V_319 ;
if ( F_108 ( V_11 , V_229 , & V_279 ) )
goto V_318;
V_299 = & V_229 -> V_320 [ V_229 -> V_236 ] ;
if ( V_11 -> V_305 == F_25 ( V_315 ) )
goto V_321;
if ( F_6 ( V_11 , & V_5 ) || F_9 ( V_11 , & V_15 ) ) {
F_41 ( V_58 , L_35 , V_5 , V_15 ) ;
goto V_318;
}
V_279 |= V_322 ;
V_317 = F_93 ( V_229 , V_11 , V_279 , & V_280 , V_5 ) ;
if ( V_317 < 0 )
goto V_318;
else if ( V_317 )
V_279 |= V_323 ;
else
F_92 ( V_229 , V_11 , V_5 ) ;
V_321:
F_98 ( V_229 , V_11 , V_299 , V_279 , V_280 , V_15 ) ;
F_109 ( V_229 , V_324 ) ;
return V_325 ;
V_318:
F_110 ( V_11 ) ;
return V_325 ;
}
static int F_111 ( struct V_57 * V_58 , int V_326 )
{
F_112 ( V_58 , L_36 ) ;
return - V_115 ;
}
static int F_113 ( struct V_57 * V_58 ,
T_8 V_327 )
{
struct V_59 * V_60 = F_27 ( V_58 ) ;
struct V_110 * V_61 = V_60 -> V_61 ;
if ( V_327 & V_328 )
F_114 ( V_61 ) ;
else
F_115 ( V_61 ) ;
return 0 ;
}
void F_116 ( struct V_57 * V_58 , struct V_110 * V_61 )
{
struct V_67 * V_68 = & V_61 -> V_62 -> V_68 ;
struct V_28 * V_29 = V_61 -> V_62 ;
if ( V_61 -> type != V_133 )
return;
V_58 -> V_327 = ( V_329 |
V_328 |
V_330 ) ;
V_58 -> V_331 = V_58 -> V_327 ;
V_58 -> V_331 &= ~ ( V_329 |
V_328 |
V_330 ) ;
V_58 -> V_332 = V_27 - 1 ;
V_58 -> V_327 |= V_333 ;
V_58 -> V_331 |= V_333 ;
V_58 -> V_334 |= V_58 -> V_327 ;
V_58 -> V_335 |= V_336 ;
V_58 -> V_335 |= V_337 ;
F_117 ( V_58 -> V_338 , L_37 , V_339 - 1 ) ;
V_58 -> V_340 = V_89 ;
F_118 ( V_58 , & V_29 -> V_35 -> V_36 ) ;
F_119 ( V_61 , V_68 -> V_341 . V_342 , 0 , false , false ) ;
F_119 ( V_61 , ( T_2 [ 6 ] ) V_343 , 0 , false , false ) ;
F_119 ( V_61 , V_344 , 0 , false , false ) ;
F_119 ( V_61 , V_345 , 0 , false , false ) ;
F_119 ( V_61 , V_346 , 0 , false , false ) ;
F_119 ( V_61 , V_347 , 0 , false , false ) ;
F_120 ( V_58 -> V_348 , V_68 -> V_341 . V_342 ) ;
F_120 ( V_58 -> V_349 , V_68 -> V_341 . V_342 ) ;
V_58 -> V_350 = & V_351 ;
}
void F_121 ( struct V_28 * V_29 )
{
struct V_110 * V_61 ;
T_1 V_146 ;
int V_98 ;
if ( ! ( V_29 -> V_33 & V_70 ) )
return;
F_122 ( ! V_29 -> V_61 [ V_29 -> V_352 ] ) ;
for ( V_98 = 0 ; V_98 < V_29 -> V_353 ; V_98 ++ ) {
V_61 = V_29 -> V_61 [ V_98 ] ;
if ( V_61 && V_61 -> type == V_133 ) {
F_31 ( & V_29 -> V_35 -> V_36 ,
L_38 ) ;
return;
}
}
V_146 = V_29 -> V_61 [ V_29 -> V_352 ] -> V_146 ;
V_61 = F_123 ( V_29 , V_133 , V_146 , 0 ) ;
if ( V_61 ) {
F_124 ( & V_29 -> V_35 -> V_36 ,
L_39 ,
V_61 -> V_146 , V_61 -> V_43 , V_61 -> V_119 , V_146 ) ;
} else {
F_30 ( & V_29 -> V_35 -> V_36 , L_40 ) ;
}
}
