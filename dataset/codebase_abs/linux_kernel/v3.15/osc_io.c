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
F_13 ( V_77 , L_4 V_78 L_5 V_78 L_6 V_78 L_7 ,
V_76 > V_70 -> V_79 ? L_8 : L_9 , V_70 -> V_79 , V_76 ,
V_70 -> V_80 . V_81 ) ;
V_75 = 0 ;
if ( V_76 > V_70 -> V_79 ) {
V_73 -> V_82 = V_76 ;
V_75 |= V_83 ;
}
if ( V_76 > V_70 -> V_80 . V_81 ) {
V_73 -> V_84 = V_76 ;
V_75 |= V_85 ;
}
F_28 ( V_11 , V_66 , V_73 , V_75 ) ;
F_29 ( V_66 ) ;
}
static void F_30 ( const struct V_10 * V_11 ,
struct V_15 * V_86 , unsigned V_68 )
{
struct V_16 * V_17 = V_86 -> V_87 . V_88 ;
struct V_65 * V_66 = V_86 -> V_87 . V_89 ;
F_24 ( V_11 , V_66 , V_17 -> V_90 , V_68 ) ;
}
static int F_31 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 ,
const struct V_18 * V_3 ,
unsigned V_91 , unsigned V_68 )
{
struct V_92 * V_93 = F_32 ( V_3 -> V_89 -> V_94 . V_95 ) ;
struct V_96 * V_97 = F_33 ( V_93 -> V_98 ) ;
struct V_9 * V_13 = F_4 ( V_11 , V_20 ) ;
int V_39 = 0 ;
if ( V_97 == NULL || V_97 -> V_99 )
V_39 = - V_100 ;
if ( V_39 == 0 && V_13 -> V_101 )
F_34 ( V_11 , V_3 -> V_88 , 1 ) ;
return V_39 ;
}
static int F_35 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 ,
const struct V_18 * V_3 ,
unsigned V_91 , unsigned V_68 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_20 ) ;
struct V_15 * V_30 = F_9 ( V_3 ) ;
struct V_28 * V_66 = F_14 ( V_30 -> V_87 . V_89 ) ;
struct V_51 * V_52 = & V_30 -> V_54 ;
F_8 ( V_68 > 0 ) ;
F_30 ( V_11 , F_9 ( V_3 ) , V_68 ) ;
if ( ! F_36 ( F_37 ( V_66 ) ) &&
F_38 ( V_102 ) )
V_52 -> V_103 |= V_104 ;
if ( V_13 -> V_101 )
F_39 ( V_11 , V_3 -> V_88 , V_91 , V_68 ) ;
return 0 ;
}
static int F_40 ( const struct V_10 * V_11 ,
const struct V_12 * V_20 )
{
struct V_31 * V_19 ;
struct V_105 * V_106 ;
V_19 = V_20 -> V_107 ;
V_106 = & V_19 -> V_108 . V_109 ;
F_13 ( V_64 , L_10 ,
V_106 -> V_110 , V_106 -> V_111 , V_106 -> V_112 ) ;
if ( V_106 -> V_111 )
F_24 ( V_11 , V_20 -> V_45 ,
V_106 -> V_110 , V_106 -> V_112 ) ;
return 0 ;
}
static int F_41 ( void * V_113 , int V_114 )
{
struct V_115 * args = V_113 ;
args -> V_116 = V_114 ;
F_42 ( & args -> V_117 ) ;
return 0 ;
}
static int F_43 ( const struct V_10 * V_11 , struct V_31 * V_19 ,
struct V_16 * V_17 , void * V_118 )
{
const struct V_18 * V_3 ;
struct V_15 * V_119 ;
struct V_51 * V_52 ;
T_2 V_120 = * ( T_2 * ) V_118 ;
V_3 = F_7 ( V_17 , & V_7 ) ;
F_8 ( V_3 != NULL ) ;
V_119 = F_9 ( V_3 ) ;
V_52 = & V_119 -> V_54 ;
if ( V_52 -> V_121 & V_48 &&
! F_18 ( & V_52 -> V_56 ) )
F_44 ( V_122 , V_11 , V_17 , L_11 V_78 L_12 ,
V_120 , V_123 -> V_124 ) ;
{
struct V_17 * V_125 = F_45 ( V_11 , V_17 ) ;
if ( F_46 ( V_125 ) )
F_13 ( V_44 , L_13 ,
V_119 , V_17 -> V_90 ,
( V_52 -> V_121 & V_126 ) ) ;
}
return V_127 ;
}
static void F_47 ( const struct V_10 * V_11 , struct V_31 * V_19 ,
struct V_9 * V_13 , T_2 V_128 )
{
struct V_65 * V_129 ;
int V_130 ;
T_1 V_120 ;
V_129 = V_13 -> V_14 . V_45 ;
V_120 = F_48 ( V_129 , V_128 ) ;
V_130 = F_26 ( V_129 , V_120 ) < V_128 ;
F_49 ( V_11 , V_129 , V_19 , V_120 + V_130 , V_131 ,
F_43 , ( void * ) & V_128 ) ;
}
static int F_50 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_107 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_69 * V_70 = F_14 ( V_66 ) -> V_71 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
struct V_132 * V_133 = & V_13 -> V_134 ;
struct V_115 * V_135 = & V_13 -> V_136 ;
T_2 V_128 = V_19 -> V_108 . V_137 . V_138 . V_81 ;
unsigned int V_139 = V_19 -> V_108 . V_137 . V_140 ;
int V_39 = 0 ;
struct V_141 V_142 = { { { 0 } } } ;
if ( F_51 ( V_19 ) )
V_39 = F_52 ( V_11 , V_13 , F_14 ( V_66 ) , V_128 ) ;
if ( V_39 == 0 && V_13 -> V_101 == 0 ) {
F_27 ( V_66 ) ;
V_39 = F_53 ( V_11 , V_66 , V_73 ) ;
if ( V_39 == 0 ) {
struct V_143 * V_144 = & V_19 -> V_108 . V_137 . V_138 ;
unsigned int V_145 = 0 ;
if ( V_139 & V_146 ) {
V_73 -> V_84 = V_73 -> V_82 = V_128 ;
V_145 = ( V_85 | V_83 ) ;
}
if ( V_139 & V_147 ) {
V_73 -> V_148 = V_144 -> V_149 ;
V_145 |= V_150 ;
}
if ( V_139 & V_151 ) {
V_73 -> V_152 = V_144 -> V_153 ;
V_145 |= V_154 ;
}
if ( V_139 & V_155 ) {
V_73 -> V_156 = V_144 -> V_157 ;
V_145 |= V_158 ;
}
V_39 = F_28 ( V_11 , V_66 , V_73 , V_145 ) ;
}
F_29 ( V_66 ) ;
}
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
if ( V_39 == 0 ) {
V_133 -> V_159 = V_70 -> V_160 ;
V_133 -> V_161 = V_73 -> V_148 ;
V_133 -> V_162 = V_73 -> V_152 ;
V_133 -> V_163 = V_73 -> V_156 ;
V_133 -> V_164 = V_165 | V_166 | V_167 |
V_168 | V_169 ;
if ( V_139 & V_146 ) {
V_133 -> V_170 = V_128 ;
V_133 -> V_171 = V_172 ;
V_133 -> V_164 |= V_173 | V_174 ;
if ( V_13 -> V_101 ) {
V_133 -> V_175 = V_176 ;
V_133 -> V_164 |= V_177 ;
}
} else {
F_8 ( V_13 -> V_101 == 0 ) ;
}
V_142 . V_134 = V_133 ;
V_142 . V_178 = V_19 -> V_108 . V_137 . V_179 ;
F_54 ( & V_135 -> V_117 ) ;
if ( V_139 & V_146 )
V_39 = F_55 ( F_37 ( F_14 ( V_66 ) ) ,
& V_142 , F_41 ,
V_135 , V_180 ) ;
else
V_39 = F_56 ( F_37 ( F_14 ( V_66 ) ) ,
& V_142 , NULL ,
F_41 ,
V_135 , V_180 ) ;
V_135 -> V_181 = V_39 == 0 ;
}
return V_39 ;
}
static void F_57 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_107 ;
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_115 * V_135 = & V_13 -> V_136 ;
int V_39 = 0 ;
if ( V_135 -> V_181 ) {
F_58 ( & V_135 -> V_117 ) ;
V_39 = V_19 -> V_182 = V_135 -> V_116 ;
}
if ( V_39 == 0 ) {
if ( V_13 -> V_101 ) {
struct V_92 * V_183 = F_32 ( V_66 -> V_94 . V_95 ) ;
F_8 ( F_51 ( V_19 ) ) ;
V_183 -> V_184 . V_185 ++ ;
}
}
if ( F_51 ( V_19 ) ) {
T_2 V_128 = V_19 -> V_108 . V_137 . V_138 . V_81 ;
F_47 ( V_11 , V_19 , V_13 , V_128 ) ;
if ( V_13 -> V_186 != NULL ) {
F_59 ( V_11 , V_13 , F_14 ( V_66 ) ) ;
V_13 -> V_186 = NULL ;
}
}
}
static int F_60 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
int V_114 = 0 ;
if ( V_13 -> V_101 == 0 && ! V_3 -> V_107 -> V_187 ) {
F_27 ( V_66 ) ;
V_73 -> V_152 = F_61 ( V_188 ) ;
V_114 = F_28 ( V_11 , V_66 , V_73 , V_154 ) ;
F_29 ( V_66 ) ;
}
return V_114 ;
}
static int F_62 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_72 * V_73 = & F_25 ( V_11 ) -> V_74 ;
int V_39 = 0 ;
if ( V_13 -> V_101 == 0 ) {
F_63 ( V_189 , 1 ) ;
F_27 ( V_66 ) ;
V_39 = F_53 ( V_11 , V_66 , V_73 ) ;
if ( V_39 == 0 ) {
V_73 -> V_148 = V_73 -> V_156 =
F_61 ( V_188 ) ;
V_39 = F_28 ( V_11 , V_66 , V_73 ,
V_150 | V_158 ) ;
}
F_29 ( V_66 ) ;
}
return V_39 ;
}
static int F_64 ( const struct V_10 * V_11 , struct V_28 * V_66 ,
struct V_190 * V_106 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
struct V_132 * V_133 = & V_13 -> V_134 ;
struct V_141 * V_142 = & V_13 -> V_191 ;
struct V_69 * V_70 = V_66 -> V_71 ;
struct V_115 * V_135 = & V_13 -> V_136 ;
int V_114 = 0 ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_159 = V_70 -> V_160 ;
V_133 -> V_164 = V_165 | V_166 ;
V_133 -> V_170 = V_106 -> V_192 ;
V_133 -> V_171 = V_106 -> V_193 ;
V_133 -> V_164 |= V_173 | V_174 ;
F_65 ( V_133 , V_106 -> V_194 ) ;
memset ( V_142 , 0 , sizeof( * V_142 ) ) ;
V_142 -> V_134 = V_133 ;
V_142 -> V_178 = V_106 -> V_195 ;
F_54 ( & V_135 -> V_117 ) ;
V_114 = F_66 ( F_37 ( V_66 ) , V_142 , F_41 , V_135 ,
V_180 ) ;
return V_114 ;
}
static int F_67 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_31 * V_19 = V_3 -> V_107 ;
struct V_190 * V_106 = & V_19 -> V_108 . V_196 ;
struct V_65 * V_66 = V_3 -> V_45 ;
struct V_28 * V_29 = F_14 ( V_66 ) ;
T_1 V_120 = F_48 ( V_66 , V_106 -> V_192 ) ;
T_1 V_197 = F_48 ( V_66 , V_106 -> V_193 ) ;
int V_39 = 0 ;
if ( V_106 -> V_193 == V_172 )
V_197 = V_131 ;
V_39 = F_68 ( V_11 , V_29 , V_120 , V_197 , 0 ,
V_106 -> V_198 == V_199 ) ;
if ( V_39 > 0 ) {
V_106 -> V_200 += V_39 ;
V_39 = 0 ;
}
if ( V_106 -> V_198 == V_201 ) {
int V_114 ;
V_114 = F_69 ( V_11 , V_29 , V_120 , V_197 ) ;
if ( V_39 == 0 )
V_39 = V_114 ;
V_114 = F_64 ( V_11 , V_29 , V_106 ) ;
if ( V_39 == 0 )
V_39 = V_114 ;
}
return V_39 ;
}
static void F_70 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_190 * V_106 = & V_3 -> V_107 -> V_108 . V_196 ;
struct V_65 * V_66 = V_3 -> V_45 ;
T_1 V_120 = F_48 ( V_66 , V_106 -> V_192 ) ;
T_1 V_197 = F_48 ( V_66 , V_106 -> V_193 ) ;
int V_39 = 0 ;
if ( V_106 -> V_198 == V_202 ) {
V_39 = F_69 ( V_11 , F_14 ( V_66 ) , V_120 , V_197 ) ;
} else if ( V_106 -> V_198 == V_201 ) {
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
struct V_115 * V_135 = & V_13 -> V_136 ;
F_58 ( & V_135 -> V_117 ) ;
if ( V_39 == 0 )
V_39 = V_135 -> V_116 ;
}
V_3 -> V_107 -> V_182 = V_39 ;
}
static void F_71 ( const struct V_10 * V_11 ,
const struct V_12 * V_3 )
{
struct V_9 * V_13 = F_4 ( V_11 , V_3 ) ;
if ( V_13 -> V_203 ) {
F_72 ( V_11 , V_13 -> V_203 ) ;
V_13 -> V_203 = NULL ;
}
}
static int F_73 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 )
{
return 0 ;
}
static void F_74 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 , int V_204 )
{
struct V_1 * V_205 ;
V_205 = F_1 ( V_3 ) ;
F_75 ( V_205 , V_206 ) ;
}
static void F_76 ( const struct V_10 * V_11 ,
const struct V_2 * V_3 ,
const struct V_65 * V_66 ,
struct V_207 * V_73 , T_3 V_208 )
{
struct V_69 * V_142 ;
struct V_209 * V_210 ;
struct V_16 * V_211 ;
struct V_212 * V_213 ;
struct V_214 * V_215 ;
struct V_15 * V_30 ;
struct V_132 * V_133 ;
struct V_143 * V_144 ;
V_142 = F_14 ( V_66 ) -> V_71 ;
V_144 = & V_142 -> V_80 ;
V_133 = V_73 -> V_216 ;
if ( ( V_208 & V_169 ) != 0 ) {
V_133 -> V_161 = V_144 -> V_149 ;
V_133 -> V_164 |= V_169 ;
}
if ( ( V_208 & V_167 ) != 0 ) {
V_133 -> V_162 = V_144 -> V_153 ;
V_133 -> V_164 |= V_167 ;
}
if ( ( V_208 & V_168 ) != 0 ) {
V_133 -> V_163 = V_144 -> V_157 ;
V_133 -> V_164 |= V_168 ;
}
if ( V_208 & V_166 ) {
F_77 ( & V_133 -> V_159 , F_78 ( & V_142 -> V_160 ) ) ;
V_133 -> V_164 |= V_166 ;
}
if ( V_208 & V_165 ) {
F_79 ( & V_133 -> V_159 , F_80 ( & V_142 -> V_160 ) ) ;
V_133 -> V_164 |= V_165 ;
}
if ( V_208 & V_217 ) {
V_210 = V_3 -> V_218 ;
F_8 ( ! F_18 ( & V_210 -> V_219 ) ) ;
V_211 = F_81 ( V_210 -> V_219 . V_220 ,
struct V_16 , V_221 ) ;
V_30 = F_6 ( V_211 ) ;
V_211 = V_30 -> V_87 . V_88 ;
V_213 = F_82 ( V_11 , V_211 -> V_222 , V_211 , NULL , 1 , 1 ) ;
if ( V_213 == NULL ) {
struct V_223 * V_224 ;
struct V_212 * V_225 ;
V_224 = V_223 ( V_211 -> V_222 ) ;
F_83 (scan, &head->coh_locks,
cll_linkage)
F_84 ( V_122 , V_11 , V_225 ,
L_14 ) ;
F_44 ( V_122 , V_11 , V_211 ,
L_15 ) ;
F_85 () ;
F_86 () ;
}
V_215 = F_87 ( V_213 ) ;
F_8 ( V_215 != NULL ) ;
F_8 ( F_88 ( V_30 -> V_226 , V_215 -> V_227 == NULL ) ) ;
if ( V_215 -> V_227 != NULL ) {
V_133 -> V_228 = V_215 -> V_227 -> V_229 ;
V_133 -> V_164 |= V_217 ;
}
F_89 ( V_11 , V_213 ) ;
}
}
int F_90 ( const struct V_10 * V_11 ,
struct V_65 * V_66 , struct V_31 * V_19 )
{
struct V_9 * V_13 = F_5 ( V_11 ) ;
F_91 ( V_13 , V_14 ) ;
F_92 ( V_19 , & V_13 -> V_14 , V_66 , & V_230 ) ;
return 0 ;
}
int F_93 ( const struct V_10 * V_11 , struct V_231 * V_93 ,
struct V_209 * V_232 )
{
struct V_1 * V_205 ;
int V_39 ;
F_94 ( V_205 , V_206 , V_233 ) ;
if ( V_205 != NULL ) {
F_95 ( V_232 , & V_205 -> V_8 , V_93 , & V_234 ) ;
V_39 = 0 ;
} else
V_39 = - V_235 ;
return V_39 ;
}
