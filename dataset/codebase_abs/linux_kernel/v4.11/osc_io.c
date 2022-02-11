static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 = F_2 ( V_5 , struct V_1 , V_7 ) ;
F_3 ( V_6 == F_4 ( V_3 ) ) ;
return V_6 ;
}
static void F_5 ( const struct V_2 * V_3 , const struct V_4 * V_8 )
{
}
static void F_6 ( const struct V_2 * V_3 , void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_12 V_13 ;
F_7 ( V_11 , & V_13 ) ;
F_8 ( & V_13 , V_14 ) ;
F_9 ( V_11 ) ;
}
static int F_10 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
T_1 V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_10 * V_11 ;
int V_22 = - V_23 ;
V_11 = F_12 ( V_3 , V_20 , V_16 , 0 ) ;
if ( V_11 ) {
F_13 ( V_11 -> V_24 == V_20 ) ;
if ( V_11 -> V_25 != V_14 ) {
struct V_12 V_13 ;
F_7 ( V_11 , & V_13 ) ;
F_14 ( & V_13 , V_14 ) ;
F_8 ( & V_13 , V_11 -> V_25 ) ;
}
V_18 -> V_26 = F_15 ( V_20 ) -> V_27 ;
V_18 -> V_28 = F_16 ( F_17 ( V_20 ) ,
V_11 -> V_29 . V_30 . V_31 ) ;
V_18 -> V_32 = F_6 ;
V_18 -> V_33 = V_11 ;
V_22 = 0 ;
}
return V_22 ;
}
static int F_18 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
enum V_34 V_35 , struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_38 * V_40 ;
struct V_41 * V_42 = NULL ;
struct V_19 * V_20 = NULL ;
struct V_43 * V_44 ;
struct V_45 * V_8 ;
F_19 ( V_46 ) ;
struct V_47 * V_48 = & V_37 -> V_49 ;
struct V_47 * V_50 = & V_37 -> V_51 ;
unsigned int V_52 = 0 ;
int V_22 = 0 ;
int V_53 ;
int V_54 ;
unsigned int V_55 ;
F_13 ( V_48 -> V_56 > 0 ) ;
F_20 ( V_57 | V_58 , L_1 , V_48 -> V_56 , V_35 ) ;
V_20 = F_11 ( V_15 -> V_21 ) ;
V_42 = F_15 ( V_20 ) ;
V_55 = V_42 -> V_27 ;
V_53 = V_35 == V_59 ? V_60 : V_61 ;
V_54 = F_21 ( F_1 ( V_3 , V_15 ) ) ? V_62 : 0 ;
F_22 (page, tmp, qin) {
struct V_63 * V_64 ;
V_8 = V_39 -> V_65 ;
F_13 ( V_8 ) ;
V_44 = F_23 ( V_39 , V_20 ) ;
V_64 = & V_44 -> V_66 ;
F_13 ( V_20 == V_64 -> V_67 ) ;
if ( ! F_24 ( & V_64 -> V_68 ) ||
! F_24 ( & V_64 -> V_69 ) ) {
F_20 ( V_57 , L_2 ,
V_64 , V_44 ) ;
V_22 = - V_70 ;
break;
}
V_22 = F_25 ( V_3 , V_8 , V_39 , V_35 ) ;
if ( V_22 != 0 ) {
F_13 ( V_22 < 0 ) ;
if ( V_22 != - V_71 )
break;
V_22 = 0 ;
continue;
}
F_26 ( & V_64 -> V_72 ) ;
V_64 -> V_73 = V_74 | V_75 ;
V_64 -> V_73 |= V_76 ;
F_27 ( & V_64 -> V_72 ) ;
F_28 ( V_3 , V_44 , V_35 , V_54 ) ;
F_29 ( & V_64 -> V_68 , & V_46 ) ;
if ( V_39 -> V_77 )
F_30 ( V_50 , V_48 , V_39 ) ;
else
F_31 ( V_3 , V_48 , V_39 ) ;
if ( ++ V_52 == V_55 ) {
V_52 = 0 ;
V_22 = F_32 ( V_3 , V_20 , & V_46 , V_53 ,
V_54 ) ;
if ( V_22 < 0 )
break;
}
}
if ( V_52 > 0 )
V_22 = F_32 ( V_3 , V_20 , & V_46 , V_53 , V_54 ) ;
if ( V_50 -> V_56 > 0 && ! V_22 ) {
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
struct V_81 * V_82 = V_15 -> V_21 ;
F_34 ( V_82 ) ;
V_79 -> V_83 = F_35 ( V_84 ) ;
V_79 -> V_85 = V_79 -> V_83 ;
F_36 ( V_3 , V_82 , V_79 , V_86 | V_87 ) ;
F_37 ( V_82 ) ;
}
F_20 ( V_88 , L_3 , V_48 -> V_56 , V_50 -> V_56 , V_22 ) ;
return V_50 -> V_56 > 0 ? 0 : V_22 ;
}
static void F_38 ( const struct V_2 * V_3 ,
struct V_81 * V_82 , T_1 V_89 , T_2 V_90 )
{
struct V_91 * V_92 = F_11 ( V_82 ) -> V_93 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_94 ;
T_3 V_95 ;
V_95 = F_39 ( V_82 , V_89 ) + V_90 ;
F_34 ( V_82 ) ;
F_20 ( V_96 , L_4 ,
V_95 > V_92 -> V_97 ? L_5 : L_6 , V_92 -> V_97 , V_95 ,
V_92 -> V_98 . V_99 ) ;
V_79 -> V_85 = F_35 ( V_84 ) ;
V_79 -> V_83 = V_79 -> V_85 ;
V_94 = V_86 | V_87 ;
if ( V_95 > V_92 -> V_97 ) {
V_79 -> V_100 = V_95 ;
V_94 |= V_101 ;
}
if ( V_95 > V_92 -> V_98 . V_99 ) {
V_79 -> V_102 = V_95 ;
V_94 |= V_103 ;
}
F_36 ( V_3 , V_82 , V_79 , V_94 ) ;
F_37 ( V_82 ) ;
}
static int F_40 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
struct V_47 * V_48 , int V_104 , int V_90 ,
T_4 V_105 )
{
struct V_45 * V_8 = V_15 -> V_106 ;
struct V_1 * V_6 = F_1 ( V_3 , V_15 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_38 * V_39 ;
struct V_38 * V_107 ;
struct V_43 * V_44 ;
int V_22 = 0 ;
F_13 ( V_48 -> V_56 > 0 ) ;
V_107 = F_41 ( V_48 ) ;
if ( V_6 -> V_108 ) {
V_39 = F_42 ( V_48 ) ;
if ( V_39 == V_107 ) {
F_43 ( V_3 , V_39 , V_104 , V_90 ) ;
} else {
if ( V_104 != 0 )
F_43 ( V_3 , V_39 , V_104 , V_109 ) ;
if ( V_90 != V_109 )
F_43 ( V_3 , V_107 , 0 , V_90 ) ;
}
}
while ( V_48 -> V_56 > 0 ) {
struct V_63 * V_64 ;
V_39 = F_42 ( V_48 ) ;
V_44 = F_23 ( V_39 , V_20 ) ;
V_64 = & V_44 -> V_66 ;
if ( ! F_24 ( & V_64 -> V_69 ) ) {
F_20 ( V_57 , L_2 ,
V_64 , V_44 ) ;
V_22 = - V_70 ;
break;
}
if ( F_24 ( & V_64 -> V_68 ) ) {
V_22 = F_44 ( V_3 , & V_44 -> V_110 , V_8 ) ;
if ( V_22 != 0 )
break;
}
F_38 ( V_3 , F_17 ( V_20 ) , F_45 ( V_44 ) ,
V_39 == V_107 ? V_90 : V_109 ) ;
F_31 ( V_3 , V_48 , V_39 ) ;
(* V_105)( V_3 , V_8 , V_39 ) ;
}
if ( F_46 ( V_8 ) && V_6 -> V_111 ) {
F_47 ( V_3 , V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
}
F_20 ( V_88 , L_1 , V_48 -> V_56 , V_22 ) ;
return V_22 ;
}
static int F_48 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_112 * V_113 = F_15 ( V_20 ) -> V_114 ;
int V_115 = - V_116 ;
F_26 ( & V_113 -> V_117 ) ;
if ( F_49 ( ! V_113 -> V_118 ) ) {
F_50 ( & V_20 -> V_119 ) ;
V_115 = 0 ;
}
F_27 ( & V_113 -> V_117 ) ;
return V_115 ;
}
static int F_51 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_45 * V_8 = V_15 -> V_106 ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_41 * V_42 = F_15 ( V_20 ) ;
unsigned long V_120 ;
unsigned long V_121 ;
unsigned long V_55 ;
if ( F_52 ( V_8 ) )
return F_48 ( V_3 , V_15 ) ;
V_121 = V_8 -> V_122 . V_123 . V_124 >> V_125 ;
if ( V_8 -> V_122 . V_123 . V_126 & ~ V_127 )
++ V_121 ;
V_55 = V_42 -> V_27 * V_42 -> V_128 ;
if ( V_121 > V_55 )
V_121 = V_55 ;
V_120 = F_53 ( V_42 -> V_129 ) ;
if ( V_120 < V_121 && V_130 ( V_42, V_121 ) > 0 )
V_120 = F_53 ( V_42 -> V_129 ) ;
while ( V_120 >= V_121 ) {
if ( V_120 == F_54 ( V_42 -> V_129 , V_120 , V_120 - V_121 ) ) {
V_6 -> V_131 = V_121 ;
break;
}
V_120 = F_53 ( V_42 -> V_129 ) ;
}
if ( F_53 ( V_42 -> V_129 ) < V_55 ) {
F_20 ( V_57 , L_7 ,
F_55 ( V_42 ) , F_53 ( V_42 -> V_129 ) ,
V_55 ) ;
( void ) F_56 ( V_42 -> V_132 ) ;
}
return F_48 ( V_3 , V_15 ) ;
}
static void F_57 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
F_13 ( F_58 ( & V_20 -> V_119 ) > 0 ) ;
if ( F_59 ( & V_20 -> V_119 ) )
F_60 ( & V_20 -> V_133 ) ;
}
static void F_61 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_41 * V_42 = F_15 ( V_20 ) ;
if ( V_6 -> V_131 > 0 ) {
F_62 ( V_6 -> V_131 , V_42 -> V_129 ) ;
V_6 -> V_131 = 0 ;
}
V_6 -> V_134 = NULL ;
F_57 ( V_3 , V_15 ) ;
}
static int F_63 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_45 * V_8 ;
struct V_135 * V_136 ;
V_8 = V_15 -> V_106 ;
V_136 = & V_8 -> V_122 . V_137 ;
F_20 ( V_88 , L_8 ,
V_136 -> V_138 , V_136 -> V_139 , V_136 -> V_140 ) ;
if ( V_136 -> V_139 )
F_38 ( V_3 , V_15 -> V_21 ,
V_136 -> V_138 , V_136 -> V_140 ) ;
return 0 ;
}
static int F_64 ( void * V_141 , int V_115 )
{
struct V_142 * args = V_141 ;
args -> V_143 = V_115 ;
F_65 ( & args -> V_144 ) ;
return 0 ;
}
static int F_66 ( const struct V_2 * V_3 , struct V_45 * V_8 ,
struct V_43 * V_145 , void * V_9 )
{
struct V_38 * V_39 = V_145 -> V_110 . V_146 ;
struct V_63 * V_64 ;
T_3 V_16 = * ( T_3 * ) V_9 ;
V_64 = & V_145 -> V_66 ;
if ( V_64 -> V_147 & V_60 &&
! F_24 ( & V_64 -> V_68 ) )
F_67 ( V_148 , V_3 , V_39 , L_9 ,
V_16 , V_149 -> V_150 ) ;
if ( F_68 ( V_39 -> V_151 ) )
F_20 ( V_57 , L_10 ,
V_145 , F_45 ( V_145 ) , V_64 -> V_147 & V_152 ) ;
return V_153 ;
}
static void F_69 ( const struct V_2 * V_3 , struct V_45 * V_8 ,
struct V_1 * V_6 , T_3 V_154 )
{
struct V_81 * V_155 ;
int V_156 ;
T_1 V_16 ;
V_155 = V_6 -> V_7 . V_21 ;
V_16 = F_16 ( V_155 , V_154 ) ;
V_156 = F_39 ( V_155 , V_16 ) < V_154 ;
F_70 ( V_3 , V_8 , F_11 ( V_155 ) ,
V_16 + V_156 , V_157 ,
F_66 , ( void * ) & V_154 ) ;
}
static int F_71 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_106 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_91 * V_92 = F_11 ( V_82 ) -> V_93 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
struct V_158 * V_159 = & V_6 -> V_160 ;
struct V_142 * V_161 = & V_6 -> V_162 ;
T_3 V_154 = V_8 -> V_122 . V_163 . V_164 . V_99 ;
unsigned int V_165 = V_8 -> V_122 . V_163 . V_166 ;
int V_22 = 0 ;
if ( F_72 ( V_8 ) )
V_22 = F_73 ( V_3 , F_11 ( V_82 ) , V_154 ,
& V_6 -> V_167 ) ;
if ( V_22 == 0 && V_6 -> V_108 == 0 ) {
F_34 ( V_82 ) ;
V_22 = F_74 ( V_3 , V_82 , V_79 ) ;
if ( V_22 == 0 ) {
struct V_168 * V_169 = & V_8 -> V_122 . V_163 . V_164 ;
unsigned int V_170 = 0 ;
if ( V_165 & V_171 ) {
V_79 -> V_102 = V_154 ;
V_79 -> V_100 = V_154 ;
V_170 = V_103 | V_101 ;
}
if ( V_165 & V_172 ) {
V_79 -> V_83 = V_169 -> V_173 ;
V_170 |= V_86 ;
}
if ( V_165 & V_174 ) {
V_79 -> V_175 = V_169 -> V_176 ;
V_170 |= V_177 ;
}
if ( V_165 & V_178 ) {
V_79 -> V_85 = V_169 -> V_179 ;
V_170 |= V_87 ;
}
V_22 = F_36 ( V_3 , V_82 , V_79 ,
V_170 ) ;
}
F_37 ( V_82 ) ;
}
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
if ( V_22 == 0 ) {
V_159 -> V_180 = V_92 -> V_181 ;
F_75 ( V_159 , V_8 -> V_122 . V_163 . V_182 ) ;
V_159 -> V_183 = V_8 -> V_122 . V_163 . V_184 ;
V_159 -> V_185 |= V_186 | V_187 ;
if ( V_165 & V_188 ) {
V_159 -> V_185 |= V_189 ;
V_159 -> V_190 = V_79 -> V_85 ;
}
if ( V_165 & V_191 ) {
V_159 -> V_185 |= V_192 ;
V_159 -> V_193 = V_79 -> V_175 ;
}
if ( V_165 & V_194 ) {
V_159 -> V_185 |= V_195 ;
V_159 -> V_196 = V_79 -> V_83 ;
}
if ( V_165 & V_171 ) {
V_159 -> V_197 = V_154 ;
V_159 -> V_198 = V_199 ;
V_159 -> V_185 |= V_200 | V_201 ;
if ( V_6 -> V_108 ) {
V_159 -> V_202 = V_203 ;
V_159 -> V_185 |= V_204 ;
}
} else {
F_13 ( V_6 -> V_108 == 0 ) ;
}
if ( V_165 & V_205 ) {
V_159 -> V_202 = V_8 -> V_122 . V_163 . V_206 ;
V_159 -> V_185 |= V_204 ;
}
F_76 ( & V_161 -> V_144 ) ;
if ( V_165 & V_171 )
V_22 = F_77 ( F_78 ( F_11 ( V_82 ) ) ,
V_159 , F_64 ,
V_161 , V_207 ) ;
else
V_22 = F_79 ( F_78 ( F_11 ( V_82 ) ) ,
V_159 , F_64 ,
V_161 , V_207 ) ;
V_161 -> V_208 = V_22 == 0 ;
}
return V_22 ;
}
static void F_80 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_106 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_142 * V_161 = & V_6 -> V_162 ;
int V_22 = 0 ;
if ( V_161 -> V_208 ) {
F_81 ( & V_161 -> V_144 ) ;
V_22 = V_161 -> V_143 ;
V_8 -> V_209 = V_161 -> V_143 ;
}
if ( V_22 == 0 ) {
if ( V_6 -> V_108 ) {
struct V_210 * V_211 = F_82 ( V_82 -> V_212 . V_213 ) ;
F_13 ( F_72 ( V_8 ) ) ;
V_211 -> V_214 . V_215 ++ ;
}
}
if ( F_72 ( V_8 ) ) {
T_3 V_154 = V_8 -> V_122 . V_163 . V_164 . V_99 ;
F_69 ( V_3 , V_8 , V_6 , V_154 ) ;
F_83 ( V_3 , V_6 -> V_167 ) ;
V_6 -> V_167 = NULL ;
}
}
static int
F_84 ( const struct V_2 * V_3 , struct V_216 * V_217 ,
void * V_218 , int V_115 )
{
struct V_219 * V_220 = V_218 ;
struct V_1 * V_6 = V_220 -> V_221 ;
const struct V_222 * V_223 ;
if ( V_115 < 0 )
goto V_224;
V_223 = F_85 ( & V_217 -> V_225 , & V_226 ) ;
if ( ! V_223 ) {
V_115 = - V_227 ;
goto V_224;
}
F_86 ( & V_217 -> V_228 -> V_229 , & V_6 -> V_160 ,
& V_223 -> V_159 ) ;
V_224:
V_6 -> V_162 . V_143 = V_115 ;
F_65 ( & V_6 -> V_162 . V_144 ) ;
return 0 ;
}
static int F_87 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_230 * V_231 = & V_5 -> V_106 -> V_122 . V_232 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_142 * V_161 = & V_6 -> V_162 ;
struct V_19 * V_82 = F_11 ( V_5 -> V_21 ) ;
struct V_233 * exp = F_78 ( V_82 ) ;
struct V_91 * V_92 = V_82 -> V_93 ;
struct V_219 * V_220 ;
struct V_158 * V_159 = & V_6 -> V_160 ;
struct V_216 * V_217 ;
struct V_222 * V_223 ;
int V_115 ;
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
V_159 -> V_180 = V_92 -> V_181 ;
V_159 -> V_185 = V_186 | V_187 ;
if ( V_231 -> V_234 & ( V_235 | V_236 ) ) {
V_159 -> V_185 |= V_204 ;
V_159 -> V_202 |= V_203 ;
if ( V_231 -> V_234 & V_236 )
V_159 -> V_202 |= V_237 ;
}
F_76 ( & V_161 -> V_144 ) ;
V_217 = F_88 ( F_89 ( exp ) , & V_238 ) ;
if ( ! V_217 )
return - V_239 ;
V_115 = F_90 ( V_217 , V_240 , V_241 ) ;
if ( V_115 < 0 ) {
F_91 ( V_217 ) ;
return V_115 ;
}
V_223 = F_92 ( & V_217 -> V_225 , & V_226 ) ;
F_93 ( & V_217 -> V_228 -> V_229 , & V_223 -> V_159 , V_159 ) ;
F_94 ( V_217 ) ;
V_217 -> V_242 = F_84 ;
F_95 ( sizeof( * V_220 ) > sizeof( V_217 -> V_243 ) ) ;
V_220 = F_96 ( V_217 ) ;
V_220 -> V_221 = V_6 ;
F_97 ( V_217 ) ;
return 0 ;
}
static void F_98 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_230 * V_231 = & V_5 -> V_106 -> V_122 . V_232 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_142 * V_161 = & V_6 -> V_162 ;
F_81 ( & V_161 -> V_144 ) ;
if ( V_161 -> V_143 ) {
V_5 -> V_106 -> V_209 = V_161 -> V_143 ;
} else if ( ! ( V_6 -> V_160 . V_185 & V_244 ) ) {
V_5 -> V_106 -> V_209 = - V_245 ;
} else {
V_231 -> V_246 = V_6 -> V_160 . V_247 ;
V_5 -> V_106 -> V_209 = 0 ;
}
}
static int F_99 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_115 = 0 ;
if ( ! V_5 -> V_106 -> V_248 ) {
F_34 ( V_82 ) ;
V_79 -> V_175 = F_100 () ;
V_115 = F_36 ( V_3 , V_82 , V_79 , V_177 ) ;
F_37 ( V_82 ) ;
}
return V_115 ;
}
static int F_101 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_115 = 0 ;
F_102 ( V_249 , 1 ) ;
F_34 ( V_82 ) ;
V_79 -> V_85 = F_100 () ;
V_79 -> V_83 = V_79 -> V_85 ;
V_115 = F_36 ( V_3 , V_82 , V_79 , V_86 | V_87 ) ;
F_37 ( V_82 ) ;
return V_115 ;
}
static int F_103 ( const struct V_2 * V_3 , struct V_19 * V_82 ,
struct V_250 * V_136 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_158 * V_159 = & V_6 -> V_160 ;
struct V_91 * V_92 = V_82 -> V_93 ;
struct V_142 * V_161 = & V_6 -> V_162 ;
int V_115 = 0 ;
memset ( V_159 , 0 , sizeof( * V_159 ) ) ;
V_159 -> V_180 = V_92 -> V_181 ;
V_159 -> V_185 = V_186 | V_187 ;
V_159 -> V_197 = V_136 -> V_251 ;
V_159 -> V_198 = V_136 -> V_252 ;
V_159 -> V_185 |= V_200 | V_201 ;
F_75 ( V_159 , V_136 -> V_253 ) ;
F_76 ( & V_161 -> V_144 ) ;
V_115 = F_104 ( V_82 , V_159 , F_64 , V_161 , V_207 ) ;
return V_115 ;
}
static int F_105 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_106 ;
struct V_250 * V_136 = & V_8 -> V_122 . V_254 ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_19 * V_20 = F_11 ( V_82 ) ;
T_1 V_16 = F_16 ( V_82 , V_136 -> V_251 ) ;
T_1 V_31 = F_16 ( V_82 , V_136 -> V_252 ) ;
int V_22 = 0 ;
if ( V_136 -> V_252 == V_199 )
V_31 = V_157 ;
V_22 = F_106 ( V_3 , V_20 , V_16 , V_31 , 0 ,
V_136 -> V_255 == V_256 ) ;
if ( V_22 > 0 ) {
V_136 -> V_257 += V_22 ;
V_22 = 0 ;
}
if ( V_136 -> V_255 == V_258 ) {
int V_115 ;
V_115 = F_107 ( V_3 , V_20 , V_16 , V_31 ) ;
if ( V_22 == 0 )
V_22 = V_115 ;
V_115 = F_103 ( V_3 , V_20 , V_136 ) ;
if ( V_22 == 0 )
V_22 = V_115 ;
}
return V_22 ;
}
static void F_108 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_250 * V_136 = & V_5 -> V_106 -> V_122 . V_254 ;
struct V_81 * V_82 = V_5 -> V_21 ;
T_1 V_16 = F_16 ( V_82 , V_136 -> V_251 ) ;
T_1 V_31 = F_16 ( V_82 , V_136 -> V_252 ) ;
int V_22 = 0 ;
if ( V_136 -> V_255 == V_259 ) {
V_22 = F_107 ( V_3 , F_11 ( V_82 ) , V_16 , V_31 ) ;
} else if ( V_136 -> V_255 == V_258 ) {
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_142 * V_161 = & V_6 -> V_162 ;
F_81 ( & V_161 -> V_144 ) ;
if ( V_22 == 0 )
V_22 = V_161 -> V_143 ;
}
V_5 -> V_106 -> V_209 = V_22 ;
}
static void F_109 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
if ( V_6 -> V_111 ) {
F_47 ( V_3 , V_6 -> V_111 ) ;
V_6 -> V_111 = NULL ;
}
}
int F_110 ( const struct V_2 * V_3 ,
struct V_81 * V_82 , struct V_45 * V_8 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
F_111 ( V_6 , V_7 ) ;
F_112 ( V_8 , & V_6 -> V_7 , V_82 , & V_260 ) ;
return 0 ;
}
