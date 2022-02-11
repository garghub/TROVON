static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
F_2 ( V_3 -> V_4 -> V_5 . V_6 == & V_7 ) ;
return F_3 ( V_3 , struct V_1 , V_8 ) ;
}
static struct V_9 * F_4 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_3 ( V_3 , struct V_9 , V_14 ) ;
F_2 ( V_13 == F_5 ( V_11 ) ) ;
return V_13 ;
}
static struct V_15 * F_6 ( struct V_16 * V_17 )
{
const struct V_18 * V_3 ;
V_3 = F_7 ( V_17 , & V_7 ) ;
F_8 ( V_3 != NULL ) ;
return F_9 ( V_3 ) ;
}
static void F_10 ( const struct V_10 * V_11 , const struct V_12 * V_19 )
{
}
static int F_11 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 ,
enum V_21 V_22 , struct V_23 * V_24 )
{
struct V_16 * V_17 ;
struct V_16 * V_25 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_29 = NULL ;
struct V_15 * V_30 ;
struct V_31 * V_19 ;
F_12 ( V_32 ) ;
struct V_33 * V_34 = & V_24 -> V_35 ;
struct V_33 * V_36 = & V_24 -> V_37 ;
int V_38 = 0 ;
int V_39 = 0 ;
int V_40 ;
int V_41 ;
int V_42 ;
F_8 ( V_34 -> V_43 > 0 ) ;
F_13 ( V_44 , L_1 , V_34 -> V_43 , V_22 ) ;
V_29 = F_14 ( V_20 -> V_45 ) ;
V_27 = F_15 ( V_29 ) ;
V_42 = V_27 -> V_46 ;
V_40 = V_22 == V_47 ? V_48 : V_49 ;
V_41 = F_16 ( F_4 ( V_11 , V_20 ) ) ? V_50 : 0 ;
F_17 (page, tmp, qin) {
struct V_51 * V_52 ;
V_19 = V_17 -> V_53 ;
F_8 ( V_19 != NULL ) ;
V_30 = F_6 ( V_17 ) ;
V_52 = & V_30 -> V_54 ;
F_8 ( V_29 == V_52 -> V_55 ) ;
if ( ! F_18 ( & V_52 -> V_56 ) ||
! F_18 ( & V_52 -> V_57 ) ) {
F_13 ( V_44 , L_2 ,
V_52 , V_30 ) ;
V_39 = - V_58 ;
break;
}
V_39 = F_19 ( V_11 , V_19 , V_17 , V_22 ) ;
if ( V_39 != 0 ) {
F_8 ( V_39 < 0 ) ;
if ( V_39 != - V_59 )
break;
V_39 = 0 ;
continue;
}
F_20 ( V_36 , V_34 , V_17 ) ;
V_52 -> V_60 = V_61 | V_62 ;
V_52 -> V_60 |= V_63 ;
F_21 ( V_11 , V_30 , V_22 , V_41 ) ;
F_22 ( & V_52 -> V_56 , & V_32 ) ;
if ( ++ V_38 == V_42 ) {
V_38 = 0 ;
V_39 = F_23 ( V_11 , V_29 , & V_32 , V_40 ,
V_41 ) ;
if ( V_39 < 0 )
break;
}
}
if ( V_38 > 0 )
V_39 = F_23 ( V_11 , V_29 , & V_32 , V_40 , V_41 ) ;
F_13 ( V_64 , L_3 , V_34 -> V_43 , V_36 -> V_43 , V_39 ) ;
return V_36 -> V_43 > 0 ? 0 : V_39 ;
}
static void F_24 ( const struct V_10 * V_11 ,
struct V_65 * V_66 , T_1 V_67 , unsigned V_68 )
{
struct V_69 * V_70 = F_14 ( V_66 ) -> V_71 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
int V_75 ;
T_2 V_76 ;
V_76 = F_26 ( V_66 , V_67 ) + V_68 ;
F_27 ( V_66 ) ;
F_13 ( V_77 , L_4 ,
V_76 > V_70 -> V_78 ? L_5 : L_6 , V_70 -> V_78 , V_76 ,
V_70 -> V_79 . V_80 ) ;
V_75 = 0 ;
if ( V_76 > V_70 -> V_78 ) {
V_73 -> V_81 = V_76 ;
V_75 |= V_82 ;
}
if ( V_76 > V_70 -> V_79 . V_80 ) {
V_73 -> V_83 = V_76 ;
V_75 |= V_84 ;
}
F_28 ( V_11 , V_66 , V_73 , V_75 ) ;
F_29 ( V_66 ) ;
}
static void F_30 ( const struct V_10 * V_11 ,
struct V_15 * V_85 , unsigned V_68 )
{
struct V_16 * V_17 = V_85 -> V_86 . V_87 ;
struct V_65 * V_66 = V_85 -> V_86 . V_88 ;
F_24 ( V_11 , V_66 , V_17 -> V_89 , V_68 ) ;
}
static int F_31 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 ,
const struct V_18 * V_3 ,
unsigned V_90 , unsigned V_68 )
{
struct V_91 * V_92 = F_32 ( V_3 -> V_88 -> V_93 . V_94 ) ;
struct V_95 * V_96 = F_33 ( V_92 -> V_97 ) ;
struct V_9 * V_13 = F_4 ( V_11 , V_20 ) ;
int V_39 = 0 ;
if ( V_96 == NULL || V_96 -> V_98 )
V_39 = - V_99 ;
if ( V_39 == 0 && V_13 -> V_100 )
F_34 ( V_11 , V_3 -> V_87 , 1 ) ;
return V_39 ;
}
static int F_35 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 ,
const struct V_18 * V_3 ,
unsigned V_90 , unsigned V_68 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_20 ) ;
struct V_15 * V_30 = F_9 ( V_3 ) ;
struct V_28 * V_66 = F_14 ( V_30 -> V_86 . V_88 ) ;
struct V_51 * V_52 = & V_30 -> V_54 ;
F_8 ( V_68 > 0 ) ;
F_30 ( V_11 , F_9 ( V_3 ) , V_68 ) ;
if ( ! F_36 ( F_37 ( V_66 ) ) &&
F_38 ( V_101 ) )
V_52 -> V_102 |= V_103 ;
if ( V_13 -> V_100 )
F_39 ( V_11 , V_3 -> V_87 , V_90 , V_68 ) ;
return 0 ;
}
static int F_40 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 )
{
struct V_31 * V_19 ;
struct V_104 * V_105 ;
V_19 = V_20 -> V_106 ;
V_105 = & V_19 -> V_107 . V_108 ;
F_13 ( V_64 , L_7 ,
V_105 -> V_109 , V_105 -> V_110 , V_105 -> V_111 ) ;
if ( V_105 -> V_110 )
F_24 ( V_11 , V_20 -> V_45 ,
V_105 -> V_109 , V_105 -> V_111 ) ;
return 0 ;
}
static int F_41 ( void * V_112 , int V_113 )
{
struct V_114 * args = V_112 ;
args -> V_115 = V_113 ;
F_42 ( & args -> V_116 ) ;
return 0 ;
}
static int F_43 ( const struct V_10 * V_11 , struct V_31 * V_19 ,
struct V_16 * V_17 , void * V_117 )
{
const struct V_18 * V_3 ;
struct V_15 * V_118 ;
struct V_51 * V_52 ;
T_2 V_119 = * ( T_2 * ) V_117 ;
V_3 = F_7 ( V_17 , & V_7 ) ;
F_8 ( V_3 != NULL ) ;
V_118 = F_9 ( V_3 ) ;
V_52 = & V_118 -> V_54 ;
if ( V_52 -> V_120 & V_48 &&
! F_18 ( & V_52 -> V_56 ) )
F_44 ( V_121 , V_11 , V_17 , L_8 ,
V_119 , V_122 -> V_123 ) ;
{
struct V_17 * V_124 = F_45 ( V_11 , V_17 ) ;
if ( F_46 ( V_124 ) )
F_13 ( V_44 , L_9 ,
V_118 , V_17 -> V_89 ,
( V_52 -> V_120 & V_125 ) ) ;
}
return V_126 ;
}
static void F_47 ( const struct V_10 * V_11 , struct V_31 * V_19 ,
struct V_9 * V_13 , T_2 V_127 )
{
struct V_65 * V_128 ;
int V_129 ;
T_1 V_119 ;
V_128 = V_13 -> V_14 . V_45 ;
V_119 = F_48 ( V_128 , V_127 ) ;
V_129 = F_26 ( V_128 , V_119 ) < V_127 ;
F_49 ( V_11 , V_128 , V_19 , V_119 + V_129 , V_130 ,
F_43 , ( void * ) & V_127 ) ;
}
static int F_50 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_106 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_69 * V_70 = F_14 ( V_66 ) -> V_71 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
struct V_131 * V_132 = & V_13 -> V_133 ;
struct V_114 * V_134 = & V_13 -> V_135 ;
T_2 V_127 = V_19 -> V_107 . V_136 . V_137 . V_80 ;
unsigned int V_138 = V_19 -> V_107 . V_136 . V_139 ;
int V_39 = 0 ;
struct V_140 V_141 = { } ;
if ( F_51 ( V_19 ) )
V_39 = F_52 ( V_11 , V_13 , F_14 ( V_66 ) , V_127 ) ;
if ( V_39 == 0 && V_13 -> V_100 == 0 ) {
F_27 ( V_66 ) ;
V_39 = F_53 ( V_11 , V_66 , V_73 ) ;
if ( V_39 == 0 ) {
struct V_142 * V_143 = & V_19 -> V_107 . V_136 . V_137 ;
unsigned int V_144 = 0 ;
if ( V_138 & V_145 ) {
V_73 -> V_83 = V_73 -> V_81 = V_127 ;
V_144 = V_84 | V_82 ;
}
if ( V_138 & V_146 ) {
V_73 -> V_147 = V_143 -> V_148 ;
V_144 |= V_149 ;
}
if ( V_138 & V_150 ) {
V_73 -> V_151 = V_143 -> V_152 ;
V_144 |= V_153 ;
}
if ( V_138 & V_154 ) {
V_73 -> V_155 = V_143 -> V_156 ;
V_144 |= V_157 ;
}
V_39 = F_28 ( V_11 , V_66 , V_73 , V_144 ) ;
}
F_29 ( V_66 ) ;
}
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
if ( V_39 == 0 ) {
V_132 -> V_158 = V_70 -> V_159 ;
V_132 -> V_160 = V_73 -> V_147 ;
V_132 -> V_161 = V_73 -> V_151 ;
V_132 -> V_162 = V_73 -> V_155 ;
V_132 -> V_163 = V_164 | V_165 | V_166 |
V_167 | V_168 ;
if ( V_138 & V_145 ) {
V_132 -> V_169 = V_127 ;
V_132 -> V_170 = V_171 ;
V_132 -> V_163 |= V_172 | V_173 ;
if ( V_13 -> V_100 ) {
V_132 -> V_174 = V_175 ;
V_132 -> V_163 |= V_176 ;
}
} else {
F_8 ( V_13 -> V_100 == 0 ) ;
}
V_141 . V_133 = V_132 ;
F_54 ( & V_134 -> V_116 ) ;
if ( V_138 & V_145 )
V_39 = F_55 ( F_37 ( F_14 ( V_66 ) ) ,
& V_141 , F_41 ,
V_134 , V_177 ) ;
else
V_39 = F_56 ( F_37 ( F_14 ( V_66 ) ) ,
& V_141 , NULL ,
F_41 ,
V_134 , V_177 ) ;
V_134 -> V_178 = V_39 == 0 ;
}
return V_39 ;
}
static void F_57 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_106 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_114 * V_134 = & V_13 -> V_135 ;
int V_39 = 0 ;
if ( V_134 -> V_178 ) {
F_58 ( & V_134 -> V_116 ) ;
V_39 = V_19 -> V_179 = V_134 -> V_115 ;
}
if ( V_39 == 0 ) {
if ( V_13 -> V_100 ) {
struct V_91 * V_180 = F_32 ( V_66 -> V_93 . V_94 ) ;
F_8 ( F_51 ( V_19 ) ) ;
V_180 -> V_181 . V_182 ++ ;
}
}
if ( F_51 ( V_19 ) ) {
T_2 V_127 = V_19 -> V_107 . V_136 . V_137 . V_80 ;
F_47 ( V_11 , V_19 , V_13 , V_127 ) ;
if ( V_13 -> V_183 != NULL ) {
F_59 ( V_11 , V_13 , F_14 ( V_66 ) ) ;
V_13 -> V_183 = NULL ;
}
}
}
static int F_60 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
int V_113 = 0 ;
if ( ! V_3 -> V_106 -> V_184 ) {
F_27 ( V_66 ) ;
V_73 -> V_151 = F_61 () ;
V_113 = F_28 ( V_11 , V_66 , V_73 , V_153 ) ;
F_29 ( V_66 ) ;
}
return V_113 ;
}
static int F_62 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
int V_113 = 0 ;
F_63 ( V_185 , 1 ) ;
F_27 ( V_66 ) ;
V_73 -> V_147 = V_73 -> V_155 = F_61 () ;
V_113 = F_28 ( V_11 , V_66 , V_73 , V_149 | V_157 ) ;
F_29 ( V_66 ) ;
return V_113 ;
}
static int F_64 ( const struct V_10 * V_11 , struct V_28 * V_66 ,
struct V_186 * V_105 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_131 * V_132 = & V_13 -> V_133 ;
struct V_140 * V_141 = & V_13 -> V_187 ;
struct V_69 * V_70 = V_66 -> V_71 ;
struct V_114 * V_134 = & V_13 -> V_135 ;
int V_113 = 0 ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
V_132 -> V_158 = V_70 -> V_159 ;
V_132 -> V_163 = V_164 | V_165 ;
V_132 -> V_169 = V_105 -> V_188 ;
V_132 -> V_170 = V_105 -> V_189 ;
V_132 -> V_163 |= V_172 | V_173 ;
F_65 ( V_132 , V_105 -> V_190 ) ;
memset ( V_141 , 0 , sizeof( * V_141 ) ) ;
V_141 -> V_133 = V_132 ;
F_54 ( & V_134 -> V_116 ) ;
V_113 = F_66 ( F_37 ( V_66 ) , V_141 , F_41 , V_134 ,
V_177 ) ;
return V_113 ;
}
static int F_67 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_106 ;
struct V_186 * V_105 = & V_19 -> V_107 . V_191 ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_28 * V_29 = F_14 ( V_66 ) ;
T_1 V_119 = F_48 ( V_66 , V_105 -> V_188 ) ;
T_1 V_192 = F_48 ( V_66 , V_105 -> V_189 ) ;
int V_39 = 0 ;
if ( V_105 -> V_189 == V_171 )
V_192 = V_130 ;
V_39 = F_68 ( V_11 , V_29 , V_119 , V_192 , 0 ,
V_105 -> V_193 == V_194 ) ;
if ( V_39 > 0 ) {
V_105 -> V_195 += V_39 ;
V_39 = 0 ;
}
if ( V_105 -> V_193 == V_196 ) {
int V_113 ;
V_113 = F_69 ( V_11 , V_29 , V_119 , V_192 ) ;
if ( V_39 == 0 )
V_39 = V_113 ;
V_113 = F_64 ( V_11 , V_29 , V_105 ) ;
if ( V_39 == 0 )
V_39 = V_113 ;
}
return V_39 ;
}
static void F_70 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_186 * V_105 = & V_3 -> V_106 -> V_107 . V_191 ;
struct V_65 * V_66 = V_3 -> V_45 ;
T_1 V_119 = F_48 ( V_66 , V_105 -> V_188 ) ;
T_1 V_192 = F_48 ( V_66 , V_105 -> V_189 ) ;
int V_39 = 0 ;
if ( V_105 -> V_193 == V_197 ) {
V_39 = F_69 ( V_11 , F_14 ( V_66 ) , V_119 , V_192 ) ;
} else if ( V_105 -> V_193 == V_196 ) {
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_114 * V_134 = & V_13 -> V_135 ;
F_58 ( & V_134 -> V_116 ) ;
if ( V_39 == 0 )
V_39 = V_134 -> V_115 ;
}
V_3 -> V_106 -> V_179 = V_39 ;
}
static void F_71 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
if ( V_13 -> V_198 ) {
F_72 ( V_11 , V_13 -> V_198 ) ;
V_13 -> V_198 = NULL ;
}
}
static int F_73 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static void F_74 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 , int V_199 )
{
struct V_1 * V_200 ;
V_200 = F_1 ( V_3 ) ;
F_75 ( V_201 , V_200 ) ;
}
static void F_76 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 ,
const struct V_65 * V_66 ,
struct V_202 * V_73 , T_3 V_203 )
{
struct V_69 * V_141 ;
struct V_204 * V_205 ;
struct V_16 * V_206 ;
struct V_207 * V_208 ;
struct V_209 * V_210 ;
struct V_15 * V_30 ;
struct V_131 * V_132 ;
struct V_142 * V_143 ;
V_141 = F_14 ( V_66 ) -> V_71 ;
V_143 = & V_141 -> V_79 ;
V_132 = V_73 -> V_211 ;
if ( ( V_203 & V_168 ) != 0 ) {
V_132 -> V_160 = V_143 -> V_148 ;
V_132 -> V_163 |= V_168 ;
}
if ( ( V_203 & V_166 ) != 0 ) {
V_132 -> V_161 = V_143 -> V_152 ;
V_132 -> V_163 |= V_166 ;
}
if ( ( V_203 & V_167 ) != 0 ) {
V_132 -> V_162 = V_143 -> V_156 ;
V_132 -> V_163 |= V_167 ;
}
if ( V_203 & V_165 ) {
F_77 ( & V_132 -> V_158 , F_78 ( & V_141 -> V_159 ) ) ;
V_132 -> V_163 |= V_165 ;
}
if ( V_203 & V_164 ) {
F_79 ( & V_132 -> V_158 , F_80 ( & V_141 -> V_159 ) ) ;
V_132 -> V_163 |= V_164 ;
}
if ( V_203 & V_212 ) {
V_205 = V_3 -> V_213 ;
F_8 ( ! F_18 ( & V_205 -> V_214 ) ) ;
V_206 = F_81 ( V_205 -> V_214 . V_215 ,
struct V_16 , V_216 ) ;
V_30 = F_6 ( V_206 ) ;
V_206 = V_30 -> V_86 . V_87 ;
V_208 = F_82 ( V_11 , V_206 -> V_217 , V_206 , NULL , 1 , 1 ) ;
if ( V_208 == NULL ) {
struct V_218 * V_219 ;
struct V_207 * V_220 ;
V_219 = V_218 ( V_206 -> V_217 ) ;
F_83 (scan, &head->coh_locks,
cll_linkage)
F_84 ( V_121 , V_11 , V_220 ,
L_10 ) ;
F_44 ( V_121 , V_11 , V_206 ,
L_11 ) ;
F_85 () ;
F_86 () ;
}
V_210 = F_87 ( V_208 ) ;
F_8 ( V_210 != NULL ) ;
F_8 ( F_88 ( V_30 -> V_221 , V_210 -> V_222 == NULL ) ) ;
if ( V_210 -> V_222 != NULL ) {
V_132 -> V_223 = V_210 -> V_222 -> V_224 ;
V_132 -> V_163 |= V_212 ;
}
F_89 ( V_11 , V_208 ) ;
}
}
int F_90 ( const struct V_10 * V_11 ,
struct V_65 * V_66 , struct V_31 * V_19 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
F_91 ( V_13 , V_14 ) ;
F_92 ( V_19 , & V_13 -> V_14 , V_66 , & V_225 ) ;
return 0 ;
}
int F_93 ( const struct V_10 * V_11 , struct V_226 * V_92 ,
struct V_204 * V_227 )
{
struct V_1 * V_200 ;
int V_39 ;
V_200 = F_94 ( V_201 , V_228 | V_229 ) ;
if ( V_200 != NULL ) {
F_95 ( V_227 , & V_200 -> V_8 , V_92 , & V_230 ) ;
V_39 = 0 ;
} else
V_39 = - V_231 ;
return V_39 ;
}
