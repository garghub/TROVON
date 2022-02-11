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
V_79 -> V_83 = F_35 () ;
V_79 -> V_84 = V_79 -> V_83 ;
F_36 ( V_3 , V_82 , V_79 , V_85 | V_86 ) ;
F_37 ( V_82 ) ;
}
F_20 ( V_87 , L_3 , V_48 -> V_56 , V_50 -> V_56 , V_22 ) ;
return V_50 -> V_56 > 0 ? 0 : V_22 ;
}
static void F_38 ( const struct V_2 * V_3 ,
struct V_81 * V_82 , T_1 V_88 , T_2 V_89 )
{
struct V_90 * V_91 = F_11 ( V_82 ) -> V_92 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_93 ;
T_3 V_94 ;
V_94 = F_39 ( V_82 , V_88 ) + V_89 ;
F_34 ( V_82 ) ;
F_20 ( V_95 , L_4 ,
V_94 > V_91 -> V_96 ? L_5 : L_6 , V_91 -> V_96 , V_94 ,
V_91 -> V_97 . V_98 ) ;
V_79 -> V_84 = F_35 () ;
V_79 -> V_83 = V_79 -> V_84 ;
V_93 = V_85 | V_86 ;
if ( V_94 > V_91 -> V_96 ) {
V_79 -> V_99 = V_94 ;
V_93 |= V_100 ;
}
if ( V_94 > V_91 -> V_97 . V_98 ) {
V_79 -> V_101 = V_94 ;
V_93 |= V_102 ;
}
F_36 ( V_3 , V_82 , V_79 , V_93 ) ;
F_37 ( V_82 ) ;
}
static int F_40 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
struct V_47 * V_48 , int V_103 , int V_89 ,
T_4 V_104 )
{
struct V_45 * V_8 = V_15 -> V_105 ;
struct V_1 * V_6 = F_1 ( V_3 , V_15 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_38 * V_39 ;
struct V_38 * V_106 ;
struct V_43 * V_44 ;
int V_22 = 0 ;
F_13 ( V_48 -> V_56 > 0 ) ;
V_106 = F_41 ( V_48 ) ;
if ( V_6 -> V_107 ) {
V_39 = F_42 ( V_48 ) ;
if ( V_39 == V_106 ) {
F_43 ( V_3 , V_39 , V_103 , V_89 ) ;
} else {
if ( V_103 != 0 )
F_43 ( V_3 , V_39 , V_103 , V_108 ) ;
if ( V_89 != V_108 )
F_43 ( V_3 , V_106 , 0 , V_89 ) ;
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
V_22 = F_44 ( V_3 , & V_44 -> V_109 , V_8 ) ;
if ( V_22 != 0 )
break;
}
F_38 ( V_3 , F_17 ( V_20 ) , F_45 ( V_44 ) ,
V_39 == V_106 ? V_89 : V_108 ) ;
F_31 ( V_3 , V_48 , V_39 ) ;
(* V_104)( V_3 , V_8 , V_39 ) ;
}
if ( F_46 ( V_8 ) && V_6 -> V_110 ) {
F_47 ( V_3 , V_6 -> V_110 ) ;
V_6 -> V_110 = NULL ;
}
F_20 ( V_87 , L_1 , V_48 -> V_56 , V_22 ) ;
return V_22 ;
}
static int F_48 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_111 * V_112 = F_15 ( V_20 ) -> V_113 ;
int V_114 = - V_115 ;
F_26 ( & V_112 -> V_116 ) ;
if ( F_49 ( ! V_112 -> V_117 ) ) {
struct V_1 * V_6 = F_4 ( V_3 ) ;
F_50 ( & V_20 -> V_118 ) ;
V_6 -> V_119 = 1 ;
V_114 = 0 ;
}
F_27 ( & V_112 -> V_116 ) ;
return V_114 ;
}
static int F_51 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_45 * V_8 = V_15 -> V_105 ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
unsigned long V_120 ;
if ( F_52 ( V_8 ) )
return F_48 ( V_3 , V_15 ) ;
V_120 = V_8 -> V_121 . V_122 . V_123 >> V_124 ;
if ( V_8 -> V_121 . V_122 . V_125 & ~ V_126 )
++ V_120 ;
V_6 -> V_127 = F_53 ( F_15 ( V_20 ) , V_120 ) ;
return F_48 ( V_3 , V_15 ) ;
}
static void F_54 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
if ( V_6 -> V_119 ) {
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
V_6 -> V_119 = 0 ;
F_13 ( F_55 ( & V_20 -> V_118 ) > 0 ) ;
if ( F_56 ( & V_20 -> V_118 ) )
F_57 ( & V_20 -> V_128 ) ;
}
}
static void F_58 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
if ( V_6 -> V_127 > 0 ) {
F_59 ( F_15 ( V_20 ) , V_6 -> V_127 ) ;
V_6 -> V_127 = 0 ;
}
V_6 -> V_129 = NULL ;
F_54 ( V_3 , V_15 ) ;
}
static int F_60 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_45 * V_8 ;
struct V_130 * V_131 ;
V_8 = V_15 -> V_105 ;
V_131 = & V_8 -> V_121 . V_132 ;
F_20 ( V_87 , L_7 ,
V_131 -> V_133 , V_131 -> V_134 , V_131 -> V_135 ) ;
if ( V_131 -> V_134 )
F_38 ( V_3 , V_15 -> V_21 ,
V_131 -> V_133 , V_131 -> V_135 ) ;
return 0 ;
}
static int F_61 ( void * V_136 , int V_114 )
{
struct V_137 * args = V_136 ;
args -> V_138 = V_114 ;
F_62 ( & args -> V_139 ) ;
return 0 ;
}
static int F_63 ( const struct V_2 * V_3 , struct V_45 * V_8 ,
struct V_43 * V_140 , void * V_9 )
{
struct V_38 * V_39 = V_140 -> V_109 . V_141 ;
struct V_63 * V_64 ;
T_3 V_16 = * ( T_3 * ) V_9 ;
V_64 = & V_140 -> V_66 ;
if ( V_64 -> V_142 & V_60 &&
! F_24 ( & V_64 -> V_68 ) )
F_64 ( V_143 , V_3 , V_39 , L_8 ,
V_16 , V_144 -> V_145 ) ;
if ( F_65 ( V_39 -> V_146 ) )
F_20 ( V_57 , L_9 ,
V_140 , F_45 ( V_140 ) , V_64 -> V_142 & V_147 ) ;
return V_148 ;
}
static void F_66 ( const struct V_2 * V_3 , struct V_45 * V_8 ,
struct V_1 * V_6 , T_3 V_149 )
{
struct V_81 * V_150 ;
int V_151 ;
T_1 V_16 ;
V_150 = V_6 -> V_7 . V_21 ;
V_16 = F_16 ( V_150 , V_149 ) ;
V_151 = F_39 ( V_150 , V_16 ) < V_149 ;
F_67 ( V_3 , V_8 , F_11 ( V_150 ) ,
V_16 + V_151 , V_152 ,
F_63 , ( void * ) & V_149 ) ;
}
static int F_68 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_105 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_90 * V_91 = F_11 ( V_82 ) -> V_92 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
struct V_153 * V_154 = & V_6 -> V_155 ;
struct V_137 * V_156 = & V_6 -> V_157 ;
T_3 V_149 = V_8 -> V_121 . V_158 . V_159 . V_98 ;
unsigned int V_160 = V_8 -> V_121 . V_158 . V_161 ;
int V_22 = 0 ;
if ( F_69 ( V_8 ) )
V_22 = F_70 ( V_3 , F_11 ( V_82 ) , V_149 ,
& V_6 -> V_162 ) ;
if ( V_22 == 0 && V_6 -> V_107 == 0 ) {
F_34 ( V_82 ) ;
V_22 = F_71 ( V_3 , V_82 , V_79 ) ;
if ( V_22 == 0 ) {
struct V_163 * V_164 = & V_8 -> V_121 . V_158 . V_159 ;
unsigned int V_165 = 0 ;
if ( V_160 & V_166 ) {
V_79 -> V_101 = V_149 ;
V_79 -> V_99 = V_149 ;
V_165 = V_102 | V_100 ;
}
if ( V_160 & V_167 ) {
V_79 -> V_83 = V_164 -> V_168 ;
V_165 |= V_85 ;
}
if ( V_160 & V_169 ) {
V_79 -> V_170 = V_164 -> V_171 ;
V_165 |= V_172 ;
}
if ( V_160 & V_173 ) {
V_79 -> V_84 = V_164 -> V_174 ;
V_165 |= V_86 ;
}
V_22 = F_36 ( V_3 , V_82 , V_79 ,
V_165 ) ;
}
F_37 ( V_82 ) ;
}
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
if ( V_22 == 0 ) {
V_154 -> V_175 = V_91 -> V_176 ;
F_72 ( V_154 , V_8 -> V_121 . V_158 . V_177 ) ;
V_154 -> V_178 = V_8 -> V_121 . V_158 . V_179 ;
V_154 -> V_180 |= V_181 | V_182 ;
if ( V_160 & V_183 ) {
V_154 -> V_180 |= V_184 ;
V_154 -> V_185 = V_79 -> V_84 ;
}
if ( V_160 & V_186 ) {
V_154 -> V_180 |= V_187 ;
V_154 -> V_188 = V_79 -> V_170 ;
}
if ( V_160 & V_189 ) {
V_154 -> V_180 |= V_190 ;
V_154 -> V_191 = V_79 -> V_83 ;
}
if ( V_160 & V_166 ) {
V_154 -> V_192 = V_149 ;
V_154 -> V_193 = V_194 ;
V_154 -> V_180 |= V_195 | V_196 ;
if ( V_6 -> V_107 ) {
V_154 -> V_197 = V_198 ;
V_154 -> V_180 |= V_199 ;
}
} else {
F_13 ( V_6 -> V_107 == 0 ) ;
}
if ( V_160 & V_200 ) {
V_154 -> V_197 = V_8 -> V_121 . V_158 . V_201 ;
V_154 -> V_180 |= V_199 ;
}
F_73 ( & V_156 -> V_139 ) ;
if ( V_160 & V_166 )
V_22 = F_74 ( F_75 ( F_11 ( V_82 ) ) ,
V_154 , F_61 ,
V_156 , V_202 ) ;
else
V_22 = F_76 ( F_75 ( F_11 ( V_82 ) ) ,
V_154 , F_61 ,
V_156 , V_202 ) ;
V_156 -> V_203 = V_22 == 0 ;
}
return V_22 ;
}
static void F_77 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_105 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_137 * V_156 = & V_6 -> V_157 ;
int V_22 = 0 ;
if ( V_156 -> V_203 ) {
F_78 ( & V_156 -> V_139 ) ;
V_22 = V_156 -> V_138 ;
V_8 -> V_204 = V_156 -> V_138 ;
}
if ( V_22 == 0 ) {
if ( V_6 -> V_107 ) {
struct V_205 * V_206 = F_79 ( V_82 -> V_207 . V_208 ) ;
F_13 ( F_69 ( V_8 ) ) ;
V_206 -> V_209 . V_210 ++ ;
}
}
if ( F_69 ( V_8 ) ) {
T_3 V_149 = V_8 -> V_121 . V_158 . V_159 . V_98 ;
F_66 ( V_3 , V_8 , V_6 , V_149 ) ;
F_80 ( V_3 , V_6 -> V_162 ) ;
V_6 -> V_162 = NULL ;
}
}
static int
F_81 ( const struct V_2 * V_3 , struct V_211 * V_212 ,
void * V_213 , int V_114 )
{
struct V_214 * V_215 = V_213 ;
struct V_1 * V_6 = V_215 -> V_216 ;
const struct V_217 * V_218 ;
if ( V_114 < 0 )
goto V_219;
V_218 = F_82 ( & V_212 -> V_220 , & V_221 ) ;
if ( ! V_218 ) {
V_114 = - V_222 ;
goto V_219;
}
F_83 ( & V_212 -> V_223 -> V_224 , & V_6 -> V_155 ,
& V_218 -> V_154 ) ;
V_219:
V_6 -> V_157 . V_138 = V_114 ;
F_62 ( & V_6 -> V_157 . V_139 ) ;
return 0 ;
}
static int F_84 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_225 * V_226 = & V_5 -> V_105 -> V_121 . V_227 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_137 * V_156 = & V_6 -> V_157 ;
struct V_19 * V_82 = F_11 ( V_5 -> V_21 ) ;
struct V_228 * exp = F_75 ( V_82 ) ;
struct V_90 * V_91 = V_82 -> V_92 ;
struct V_214 * V_215 ;
struct V_153 * V_154 = & V_6 -> V_155 ;
struct V_211 * V_212 ;
struct V_217 * V_218 ;
int V_114 ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_154 -> V_175 = V_91 -> V_176 ;
V_154 -> V_180 = V_181 | V_182 ;
if ( V_226 -> V_229 & ( V_230 | V_231 ) ) {
V_154 -> V_180 |= V_199 ;
V_154 -> V_197 |= V_198 ;
if ( V_226 -> V_229 & V_231 )
V_154 -> V_197 |= V_232 ;
}
F_73 ( & V_156 -> V_139 ) ;
V_212 = F_85 ( F_86 ( exp ) , & V_233 ) ;
if ( ! V_212 )
return - V_234 ;
V_114 = F_87 ( V_212 , V_235 , V_236 ) ;
if ( V_114 < 0 ) {
F_88 ( V_212 ) ;
return V_114 ;
}
V_218 = F_89 ( & V_212 -> V_220 , & V_221 ) ;
F_90 ( & V_212 -> V_223 -> V_224 , & V_218 -> V_154 , V_154 ) ;
F_91 ( V_212 ) ;
V_212 -> V_237 = F_81 ;
F_92 ( sizeof( * V_215 ) > sizeof( V_212 -> V_238 ) ) ;
V_215 = F_93 ( V_212 ) ;
V_215 -> V_216 = V_6 ;
F_94 ( V_212 ) ;
return 0 ;
}
static void F_95 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_225 * V_226 = & V_5 -> V_105 -> V_121 . V_227 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_137 * V_156 = & V_6 -> V_157 ;
F_78 ( & V_156 -> V_139 ) ;
if ( V_156 -> V_138 ) {
V_5 -> V_105 -> V_204 = V_156 -> V_138 ;
} else if ( ! ( V_6 -> V_155 . V_180 & V_239 ) ) {
V_5 -> V_105 -> V_204 = - V_240 ;
} else {
V_226 -> V_241 = V_6 -> V_155 . V_242 ;
V_5 -> V_105 -> V_204 = 0 ;
}
}
static int F_96 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_114 = 0 ;
if ( ! V_5 -> V_105 -> V_243 ) {
F_34 ( V_82 ) ;
V_79 -> V_170 = F_35 () ;
V_114 = F_36 ( V_3 , V_82 , V_79 , V_172 ) ;
F_37 ( V_82 ) ;
}
return V_114 ;
}
static int F_97 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_78 * V_79 = & F_33 ( V_3 ) -> V_80 ;
int V_114 = 0 ;
F_98 ( V_244 , 1 ) ;
F_34 ( V_82 ) ;
V_79 -> V_84 = F_35 () ;
V_79 -> V_83 = V_79 -> V_84 ;
V_114 = F_36 ( V_3 , V_82 , V_79 , V_85 | V_86 ) ;
F_37 ( V_82 ) ;
return V_114 ;
}
static int F_99 ( const struct V_2 * V_3 , struct V_19 * V_82 ,
struct V_245 * V_131 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_153 * V_154 = & V_6 -> V_155 ;
struct V_90 * V_91 = V_82 -> V_92 ;
struct V_137 * V_156 = & V_6 -> V_157 ;
int V_114 = 0 ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_154 -> V_175 = V_91 -> V_176 ;
V_154 -> V_180 = V_181 | V_182 ;
V_154 -> V_192 = V_131 -> V_246 ;
V_154 -> V_193 = V_131 -> V_247 ;
V_154 -> V_180 |= V_195 | V_196 ;
F_72 ( V_154 , V_131 -> V_248 ) ;
F_73 ( & V_156 -> V_139 ) ;
V_114 = F_100 ( V_82 , V_154 , F_61 , V_156 , V_202 ) ;
return V_114 ;
}
static int F_101 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_45 * V_8 = V_5 -> V_105 ;
struct V_245 * V_131 = & V_8 -> V_121 . V_249 ;
struct V_81 * V_82 = V_5 -> V_21 ;
struct V_19 * V_20 = F_11 ( V_82 ) ;
T_1 V_16 = F_16 ( V_82 , V_131 -> V_246 ) ;
T_1 V_31 = F_16 ( V_82 , V_131 -> V_247 ) ;
int V_22 = 0 ;
if ( V_131 -> V_247 == V_194 )
V_31 = V_152 ;
V_22 = F_102 ( V_3 , V_20 , V_16 , V_31 , 0 ,
V_131 -> V_250 == V_251 ) ;
if ( V_22 > 0 ) {
V_131 -> V_252 += V_22 ;
V_22 = 0 ;
}
if ( V_131 -> V_250 == V_253 ) {
int V_114 ;
V_114 = F_103 ( V_3 , V_20 , V_16 , V_31 ) ;
if ( V_22 == 0 )
V_22 = V_114 ;
V_114 = F_99 ( V_3 , V_20 , V_131 ) ;
if ( V_22 == 0 )
V_22 = V_114 ;
}
return V_22 ;
}
static void F_104 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_245 * V_131 = & V_5 -> V_105 -> V_121 . V_249 ;
struct V_81 * V_82 = V_5 -> V_21 ;
T_1 V_16 = F_16 ( V_82 , V_131 -> V_246 ) ;
T_1 V_31 = F_16 ( V_82 , V_131 -> V_247 ) ;
int V_22 = 0 ;
if ( V_131 -> V_250 == V_254 ) {
V_22 = F_103 ( V_3 , F_11 ( V_82 ) , V_16 , V_31 ) ;
} else if ( V_131 -> V_250 == V_253 ) {
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_137 * V_156 = & V_6 -> V_157 ;
F_78 ( & V_156 -> V_139 ) ;
if ( V_22 == 0 )
V_22 = V_156 -> V_138 ;
}
V_5 -> V_105 -> V_204 = V_22 ;
}
static void F_105 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
if ( V_6 -> V_110 ) {
F_47 ( V_3 , V_6 -> V_110 ) ;
V_6 -> V_110 = NULL ;
}
}
int F_106 ( const struct V_2 * V_3 ,
struct V_81 * V_82 , struct V_45 * V_8 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
F_107 ( V_6 , V_7 ) ;
F_108 ( V_8 , & V_6 -> V_7 , V_82 , & V_255 ) ;
return 0 ;
}
