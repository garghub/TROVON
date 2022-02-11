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
V_18 -> V_26 = F_15 ( F_16 ( V_20 ) ,
V_11 -> V_27 . V_28 . V_29 ) ;
V_18 -> V_30 = F_6 ;
V_18 -> V_31 = V_11 ;
V_22 = 0 ;
}
return V_22 ;
}
static int F_17 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
enum V_32 V_33 , struct V_34 * V_35 )
{
struct V_36 * V_37 ;
struct V_36 * V_38 ;
struct V_39 * V_40 = NULL ;
struct V_19 * V_20 = NULL ;
struct V_41 * V_42 ;
struct V_43 * V_8 ;
F_18 ( V_44 ) ;
struct V_45 * V_46 = & V_35 -> V_47 ;
struct V_45 * V_48 = & V_35 -> V_49 ;
unsigned int V_50 = 0 ;
int V_22 = 0 ;
int V_51 ;
int V_52 ;
unsigned int V_53 ;
F_13 ( V_46 -> V_54 > 0 ) ;
F_19 ( V_55 , L_1 , V_46 -> V_54 , V_33 ) ;
V_20 = F_11 ( V_15 -> V_21 ) ;
V_40 = F_20 ( V_20 ) ;
V_53 = V_40 -> V_56 ;
V_51 = V_33 == V_57 ? V_58 : V_59 ;
V_52 = F_21 ( F_1 ( V_3 , V_15 ) ) ? V_60 : 0 ;
F_22 (page, tmp, qin) {
struct V_61 * V_62 ;
V_8 = V_37 -> V_63 ;
F_13 ( V_8 ) ;
V_42 = F_23 ( V_37 , V_20 ) ;
V_62 = & V_42 -> V_64 ;
F_13 ( V_20 == V_62 -> V_65 ) ;
if ( ! F_24 ( & V_62 -> V_66 ) ||
! F_24 ( & V_62 -> V_67 ) ) {
F_19 ( V_55 , L_2 ,
V_62 , V_42 ) ;
V_22 = - V_68 ;
break;
}
V_22 = F_25 ( V_3 , V_8 , V_37 , V_33 ) ;
if ( V_22 != 0 ) {
F_13 ( V_22 < 0 ) ;
if ( V_22 != - V_69 )
break;
V_22 = 0 ;
continue;
}
F_26 ( & V_62 -> V_70 ) ;
V_62 -> V_71 = V_72 | V_73 ;
V_62 -> V_71 |= V_74 ;
F_27 ( & V_62 -> V_70 ) ;
F_28 ( V_3 , V_42 , V_33 , V_52 ) ;
F_29 ( & V_62 -> V_66 , & V_44 ) ;
if ( V_37 -> V_75 )
F_30 ( V_48 , V_46 , V_37 ) ;
else
F_31 ( V_3 , V_46 , V_37 ) ;
if ( ++ V_50 == V_53 ) {
V_50 = 0 ;
V_22 = F_32 ( V_3 , V_20 , & V_44 , V_51 ,
V_52 ) ;
if ( V_22 < 0 )
break;
}
}
if ( V_50 > 0 )
V_22 = F_32 ( V_3 , V_20 , & V_44 , V_51 , V_52 ) ;
F_19 ( V_76 , L_3 , V_46 -> V_54 , V_48 -> V_54 , V_22 ) ;
return V_48 -> V_54 > 0 ? 0 : V_22 ;
}
static void F_33 ( const struct V_2 * V_3 ,
struct V_77 * V_78 , T_1 V_79 , T_2 V_80 )
{
struct V_81 * V_82 = F_11 ( V_78 ) -> V_83 ;
struct V_84 * V_85 = & F_34 ( V_3 ) -> V_86 ;
int V_87 ;
T_3 V_88 ;
V_88 = F_35 ( V_78 , V_79 ) + V_80 ;
F_36 ( V_78 ) ;
F_19 ( V_89 , L_4 ,
V_88 > V_82 -> V_90 ? L_5 : L_6 , V_82 -> V_90 , V_88 ,
V_82 -> V_91 . V_92 ) ;
V_85 -> V_93 = F_37 ( V_94 ) ;
V_85 -> V_95 = V_85 -> V_93 ;
V_87 = V_96 | V_97 ;
if ( V_88 > V_82 -> V_90 ) {
V_85 -> V_98 = V_88 ;
V_87 |= V_99 ;
}
if ( V_88 > V_82 -> V_91 . V_92 ) {
V_85 -> V_100 = V_88 ;
V_87 |= V_101 ;
}
F_38 ( V_3 , V_78 , V_85 , V_87 ) ;
F_39 ( V_78 ) ;
}
static int F_40 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 ,
struct V_45 * V_46 , int V_102 , int V_80 ,
T_4 V_103 )
{
struct V_43 * V_8 = V_15 -> V_104 ;
struct V_1 * V_6 = F_1 ( V_3 , V_15 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_36 * V_37 ;
struct V_36 * V_105 ;
struct V_41 * V_42 ;
int V_22 = 0 ;
F_13 ( V_46 -> V_54 > 0 ) ;
V_105 = F_41 ( V_46 ) ;
if ( V_6 -> V_106 ) {
V_37 = F_42 ( V_46 ) ;
if ( V_37 == V_105 ) {
F_43 ( V_3 , V_37 , V_102 , V_80 ) ;
} else {
if ( V_102 != 0 )
F_43 ( V_3 , V_37 , V_102 , V_107 ) ;
if ( V_80 != V_107 )
F_43 ( V_3 , V_105 , 0 , V_80 ) ;
}
}
while ( V_46 -> V_54 > 0 ) {
struct V_61 * V_62 ;
V_37 = F_42 ( V_46 ) ;
V_42 = F_23 ( V_37 , V_20 ) ;
V_62 = & V_42 -> V_64 ;
if ( ! F_24 ( & V_62 -> V_67 ) ) {
F_19 ( V_55 , L_2 ,
V_62 , V_42 ) ;
V_22 = - V_68 ;
break;
}
if ( F_24 ( & V_62 -> V_66 ) ) {
V_22 = F_44 ( V_3 , & V_42 -> V_108 , V_8 ) ;
if ( V_22 != 0 )
break;
}
F_33 ( V_3 , F_16 ( V_20 ) , F_45 ( V_42 ) ,
V_37 == V_105 ? V_80 : V_107 ) ;
F_31 ( V_3 , V_46 , V_37 ) ;
(* V_103)( V_3 , V_8 , V_37 ) ;
}
if ( F_46 ( V_8 ) && V_6 -> V_109 ) {
F_47 ( V_3 , V_6 -> V_109 ) ;
V_6 -> V_109 = NULL ;
}
F_19 ( V_76 , L_1 , V_46 -> V_54 , V_22 ) ;
return V_22 ;
}
static int F_48 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_43 * V_8 = V_15 -> V_104 ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_39 * V_40 = F_20 ( V_20 ) ;
unsigned long V_110 ;
unsigned long V_111 ;
unsigned long V_53 ;
if ( F_49 ( V_8 ) )
return 0 ;
V_111 = V_8 -> V_112 . V_113 . V_114 >> V_115 ;
if ( V_8 -> V_112 . V_113 . V_116 & ~ V_117 )
++ V_111 ;
V_53 = V_40 -> V_56 * V_40 -> V_118 ;
if ( V_111 > V_53 )
V_111 = V_53 ;
V_110 = F_50 ( V_40 -> V_119 ) ;
if ( V_110 < V_111 && V_120 ( V_40, V_111 ) > 0 )
V_110 = F_50 ( V_40 -> V_119 ) ;
while ( V_110 >= V_111 ) {
if ( V_110 == F_51 ( V_40 -> V_119 , V_110 , V_110 - V_111 ) ) {
V_6 -> V_121 = V_111 ;
break;
}
V_110 = F_50 ( V_40 -> V_119 ) ;
}
if ( F_50 ( V_40 -> V_119 ) < V_53 ) {
F_19 ( V_55 , L_7 ,
F_52 ( V_40 ) , F_50 ( V_40 -> V_119 ) ,
V_53 ) ;
( void ) F_53 ( V_40 -> V_122 ) ;
}
return 0 ;
}
static void F_54 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_19 * V_20 = F_11 ( V_15 -> V_21 ) ;
struct V_39 * V_40 = F_20 ( V_20 ) ;
if ( V_6 -> V_121 > 0 ) {
F_55 ( V_6 -> V_121 , V_40 -> V_119 ) ;
V_6 -> V_121 = 0 ;
}
V_6 -> V_123 = NULL ;
}
static int F_56 ( const struct V_2 * V_3 ,
const struct V_4 * V_15 )
{
struct V_43 * V_8 ;
struct V_124 * V_125 ;
V_8 = V_15 -> V_104 ;
V_125 = & V_8 -> V_112 . V_126 ;
F_19 ( V_76 , L_8 ,
V_125 -> V_127 , V_125 -> V_128 , V_125 -> V_129 ) ;
if ( V_125 -> V_128 )
F_33 ( V_3 , V_15 -> V_21 ,
V_125 -> V_127 , V_125 -> V_129 ) ;
return 0 ;
}
static int F_57 ( void * V_130 , int V_131 )
{
struct V_132 * args = V_130 ;
args -> V_133 = V_131 ;
F_58 ( & args -> V_134 ) ;
return 0 ;
}
static int F_59 ( const struct V_2 * V_3 , struct V_43 * V_8 ,
struct V_41 * V_135 , void * V_9 )
{
struct V_36 * V_37 = V_135 -> V_108 . V_136 ;
struct V_61 * V_62 ;
T_3 V_16 = * ( T_3 * ) V_9 ;
V_62 = & V_135 -> V_64 ;
if ( V_62 -> V_137 & V_58 &&
! F_24 ( & V_62 -> V_66 ) )
F_60 ( V_138 , V_3 , V_37 , L_9 ,
V_16 , V_139 -> V_140 ) ;
if ( F_61 ( V_37 -> V_141 ) )
F_19 ( V_55 , L_10 ,
V_135 , F_45 ( V_135 ) , V_62 -> V_137 & V_142 ) ;
return V_143 ;
}
static void F_62 ( const struct V_2 * V_3 , struct V_43 * V_8 ,
struct V_1 * V_6 , T_3 V_144 )
{
struct V_77 * V_145 ;
int V_146 ;
T_1 V_16 ;
V_145 = V_6 -> V_7 . V_21 ;
V_16 = F_15 ( V_145 , V_144 ) ;
V_146 = F_35 ( V_145 , V_16 ) < V_144 ;
F_63 ( V_3 , V_8 , F_11 ( V_145 ) ,
V_16 + V_146 , V_147 ,
F_59 , ( void * ) & V_144 ) ;
}
static int F_64 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_43 * V_8 = V_5 -> V_104 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_77 * V_78 = V_5 -> V_21 ;
struct V_81 * V_82 = F_11 ( V_78 ) -> V_83 ;
struct V_84 * V_85 = & F_34 ( V_3 ) -> V_86 ;
struct V_148 * V_149 = & V_6 -> V_150 ;
struct V_132 * V_151 = & V_6 -> V_152 ;
T_3 V_144 = V_8 -> V_112 . V_153 . V_154 . V_92 ;
unsigned int V_155 = V_8 -> V_112 . V_153 . V_156 ;
int V_22 = 0 ;
if ( F_65 ( V_8 ) )
V_22 = F_66 ( V_3 , V_6 , F_11 ( V_78 ) , V_144 ) ;
if ( V_22 == 0 && V_6 -> V_106 == 0 ) {
F_36 ( V_78 ) ;
V_22 = F_67 ( V_3 , V_78 , V_85 ) ;
if ( V_22 == 0 ) {
struct V_157 * V_158 = & V_8 -> V_112 . V_153 . V_154 ;
unsigned int V_159 = 0 ;
if ( V_155 & V_160 ) {
V_85 -> V_100 = V_144 ;
V_85 -> V_98 = V_144 ;
V_159 = V_101 | V_99 ;
}
if ( V_155 & V_161 ) {
V_85 -> V_95 = V_158 -> V_162 ;
V_159 |= V_96 ;
}
if ( V_155 & V_163 ) {
V_85 -> V_164 = V_158 -> V_165 ;
V_159 |= V_166 ;
}
if ( V_155 & V_167 ) {
V_85 -> V_93 = V_158 -> V_168 ;
V_159 |= V_97 ;
}
V_22 = F_38 ( V_3 , V_78 , V_85 ,
V_159 ) ;
}
F_39 ( V_78 ) ;
}
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
if ( V_22 == 0 ) {
V_149 -> V_169 = V_82 -> V_170 ;
F_68 ( V_149 , V_8 -> V_112 . V_153 . V_171 ) ;
V_149 -> V_172 = V_8 -> V_112 . V_153 . V_173 ;
V_149 -> V_174 |= V_175 | V_176 ;
if ( V_155 & V_177 ) {
V_149 -> V_174 |= V_178 ;
V_149 -> V_179 = V_85 -> V_93 ;
}
if ( V_155 & V_180 ) {
V_149 -> V_174 |= V_181 ;
V_149 -> V_182 = V_85 -> V_164 ;
}
if ( V_155 & V_183 ) {
V_149 -> V_174 |= V_184 ;
V_149 -> V_185 = V_85 -> V_95 ;
}
if ( V_155 & V_160 ) {
V_149 -> V_186 = V_144 ;
V_149 -> V_187 = V_188 ;
V_149 -> V_174 |= V_189 | V_190 ;
if ( V_6 -> V_106 ) {
V_149 -> V_191 = V_192 ;
V_149 -> V_174 |= V_193 ;
}
} else {
F_13 ( V_6 -> V_106 == 0 ) ;
}
if ( V_155 & V_194 ) {
V_149 -> V_191 = V_8 -> V_112 . V_153 . V_195 ;
V_149 -> V_174 |= V_193 ;
}
F_69 ( & V_151 -> V_134 ) ;
if ( V_155 & V_160 )
V_22 = F_70 ( F_71 ( F_11 ( V_78 ) ) ,
V_149 , F_57 ,
V_151 , V_196 ) ;
else
V_22 = F_72 ( F_71 ( F_11 ( V_78 ) ) ,
V_149 , F_57 ,
V_151 , V_196 ) ;
V_151 -> V_197 = V_22 == 0 ;
}
return V_22 ;
}
static void F_73 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_43 * V_8 = V_5 -> V_104 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_77 * V_78 = V_5 -> V_21 ;
struct V_132 * V_151 = & V_6 -> V_152 ;
int V_22 = 0 ;
if ( V_151 -> V_197 ) {
F_74 ( & V_151 -> V_134 ) ;
V_22 = V_151 -> V_133 ;
V_8 -> V_198 = V_151 -> V_133 ;
}
if ( V_22 == 0 ) {
if ( V_6 -> V_106 ) {
struct V_199 * V_200 = F_75 ( V_78 -> V_201 . V_202 ) ;
F_13 ( F_65 ( V_8 ) ) ;
V_200 -> V_203 . V_204 ++ ;
}
}
if ( F_65 ( V_8 ) ) {
T_3 V_144 = V_8 -> V_112 . V_153 . V_154 . V_92 ;
F_62 ( V_3 , V_8 , V_6 , V_144 ) ;
if ( V_6 -> V_205 ) {
F_76 ( V_3 , V_6 , F_11 ( V_78 ) ) ;
V_6 -> V_205 = NULL ;
}
}
}
static int
F_77 ( const struct V_2 * V_3 , struct V_206 * V_207 ,
void * V_208 , int V_131 )
{
struct V_209 * V_210 = V_208 ;
struct V_1 * V_6 = V_210 -> V_211 ;
const struct V_212 * V_213 ;
if ( V_131 < 0 )
goto V_214;
V_213 = F_78 ( & V_207 -> V_215 , & V_216 ) ;
if ( ! V_213 ) {
V_131 = - V_217 ;
goto V_214;
}
F_79 ( & V_207 -> V_218 -> V_219 , & V_6 -> V_150 ,
& V_213 -> V_149 ) ;
V_214:
V_6 -> V_152 . V_133 = V_131 ;
F_58 ( & V_6 -> V_152 . V_134 ) ;
return 0 ;
}
static int F_80 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_220 * V_221 = & V_5 -> V_104 -> V_112 . V_222 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_132 * V_151 = & V_6 -> V_152 ;
struct V_19 * V_78 = F_11 ( V_5 -> V_21 ) ;
struct V_223 * exp = F_71 ( V_78 ) ;
struct V_81 * V_82 = V_78 -> V_83 ;
struct V_209 * V_210 ;
struct V_148 * V_149 = & V_6 -> V_150 ;
struct V_206 * V_207 ;
struct V_212 * V_213 ;
int V_131 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_169 = V_82 -> V_170 ;
V_149 -> V_174 = V_175 | V_176 ;
if ( V_221 -> V_224 & ( V_225 | V_226 ) ) {
V_149 -> V_174 |= V_193 ;
V_149 -> V_191 |= V_192 ;
if ( V_221 -> V_224 & V_226 )
V_149 -> V_191 |= V_227 ;
}
F_69 ( & V_151 -> V_134 ) ;
V_207 = F_81 ( F_82 ( exp ) , & V_228 ) ;
if ( ! V_207 )
return - V_229 ;
V_131 = F_83 ( V_207 , V_230 , V_231 ) ;
if ( V_131 < 0 ) {
F_84 ( V_207 ) ;
return V_131 ;
}
V_213 = F_85 ( & V_207 -> V_215 , & V_216 ) ;
F_86 ( & V_207 -> V_218 -> V_219 , & V_213 -> V_149 , V_149 ) ;
F_87 ( V_207 ) ;
V_207 -> V_232 = F_77 ;
F_88 ( sizeof( * V_210 ) <= sizeof( V_207 -> V_233 ) ) ;
V_210 = F_89 ( V_207 ) ;
V_210 -> V_211 = V_6 ;
F_90 ( V_207 ) ;
return 0 ;
}
static void F_91 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_220 * V_221 = & V_5 -> V_104 -> V_112 . V_222 ;
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_132 * V_151 = & V_6 -> V_152 ;
F_74 ( & V_151 -> V_134 ) ;
if ( V_151 -> V_133 ) {
V_5 -> V_104 -> V_198 = V_151 -> V_133 ;
} else if ( ! ( V_6 -> V_150 . V_174 & V_234 ) ) {
V_5 -> V_104 -> V_198 = - V_235 ;
} else {
V_221 -> V_236 = V_6 -> V_150 . V_237 ;
V_5 -> V_104 -> V_198 = 0 ;
}
}
static int F_92 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_77 * V_78 = V_5 -> V_21 ;
struct V_84 * V_85 = & F_34 ( V_3 ) -> V_86 ;
int V_131 = 0 ;
if ( ! V_5 -> V_104 -> V_238 ) {
F_36 ( V_78 ) ;
V_85 -> V_164 = F_93 () ;
V_131 = F_38 ( V_3 , V_78 , V_85 , V_166 ) ;
F_39 ( V_78 ) ;
}
return V_131 ;
}
static int F_94 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_77 * V_78 = V_5 -> V_21 ;
struct V_84 * V_85 = & F_34 ( V_3 ) -> V_86 ;
int V_131 = 0 ;
F_95 ( V_239 , 1 ) ;
F_36 ( V_78 ) ;
V_85 -> V_93 = F_93 () ;
V_85 -> V_95 = V_85 -> V_93 ;
V_131 = F_38 ( V_3 , V_78 , V_85 , V_96 | V_97 ) ;
F_39 ( V_78 ) ;
return V_131 ;
}
static int F_96 ( const struct V_2 * V_3 , struct V_19 * V_78 ,
struct V_240 * V_125 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_148 * V_149 = & V_6 -> V_150 ;
struct V_81 * V_82 = V_78 -> V_83 ;
struct V_132 * V_151 = & V_6 -> V_152 ;
int V_131 = 0 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_169 = V_82 -> V_170 ;
V_149 -> V_174 = V_175 | V_176 ;
V_149 -> V_186 = V_125 -> V_241 ;
V_149 -> V_187 = V_125 -> V_242 ;
V_149 -> V_174 |= V_189 | V_190 ;
F_68 ( V_149 , V_125 -> V_243 ) ;
F_69 ( & V_151 -> V_134 ) ;
V_131 = F_97 ( V_78 , V_149 , F_57 , V_151 , V_196 ) ;
return V_131 ;
}
static int F_98 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_43 * V_8 = V_5 -> V_104 ;
struct V_240 * V_125 = & V_8 -> V_112 . V_244 ;
struct V_77 * V_78 = V_5 -> V_21 ;
struct V_19 * V_20 = F_11 ( V_78 ) ;
T_1 V_16 = F_15 ( V_78 , V_125 -> V_241 ) ;
T_1 V_29 = F_15 ( V_78 , V_125 -> V_242 ) ;
int V_22 = 0 ;
if ( V_125 -> V_242 == V_188 )
V_29 = V_147 ;
V_22 = F_99 ( V_3 , V_20 , V_16 , V_29 , 0 ,
V_125 -> V_245 == V_246 ) ;
if ( V_22 > 0 ) {
V_125 -> V_247 += V_22 ;
V_22 = 0 ;
}
if ( V_125 -> V_245 == V_248 ) {
int V_131 ;
V_131 = F_100 ( V_3 , V_20 , V_16 , V_29 ) ;
if ( V_22 == 0 )
V_22 = V_131 ;
V_131 = F_96 ( V_3 , V_20 , V_125 ) ;
if ( V_22 == 0 )
V_22 = V_131 ;
}
return V_22 ;
}
static void F_101 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_240 * V_125 = & V_5 -> V_104 -> V_112 . V_244 ;
struct V_77 * V_78 = V_5 -> V_21 ;
T_1 V_16 = F_15 ( V_78 , V_125 -> V_241 ) ;
T_1 V_29 = F_15 ( V_78 , V_125 -> V_242 ) ;
int V_22 = 0 ;
if ( V_125 -> V_245 == V_249 ) {
V_22 = F_100 ( V_3 , F_11 ( V_78 ) , V_16 , V_29 ) ;
} else if ( V_125 -> V_245 == V_248 ) {
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
struct V_132 * V_151 = & V_6 -> V_152 ;
F_74 ( & V_151 -> V_134 ) ;
if ( V_22 == 0 )
V_22 = V_151 -> V_133 ;
}
V_5 -> V_104 -> V_198 = V_22 ;
}
static void F_102 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_5 ) ;
if ( V_6 -> V_109 ) {
F_47 ( V_3 , V_6 -> V_109 ) ;
V_6 -> V_109 = NULL ;
}
}
int F_103 ( const struct V_2 * V_3 ,
struct V_77 * V_78 , struct V_43 * V_8 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
F_104 ( V_6 , V_7 ) ;
F_105 ( V_8 , & V_6 -> V_7 , V_78 , & V_250 ) ;
return 0 ;
}
