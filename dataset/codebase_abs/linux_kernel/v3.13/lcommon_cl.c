void * F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( V_6 , V_7 , V_8 ) ;
if ( V_6 == NULL )
V_6 = F_3 ( - V_9 ) ;
return V_6 ;
}
void F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_5 * V_6 = V_10 ;
F_5 ( V_6 , V_7 ) ;
}
void * F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 ;
F_2 ( V_12 , V_13 , V_8 ) ;
if ( V_12 == NULL )
V_12 = F_3 ( - V_9 ) ;
return V_12 ;
}
void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
F_5 ( V_12 , V_13 ) ;
}
int F_8 ( const struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , struct V_16 * V_19 )
{
struct V_20 * V_21 ;
int V_22 ;
V_21 = F_9 ( V_17 ) ;
V_21 -> V_23 = F_10 ( V_19 ) ;
F_11 ( V_17 -> V_24 != NULL && V_19 -> V_25 != NULL ) ;
V_19 -> V_24 = V_17 -> V_24 ;
V_22 = V_19 -> V_25 -> V_26 -> V_27 (
V_15 , V_19 , V_19 -> V_25 -> V_28 , NULL ) ;
if ( V_22 == 0 ) {
F_12 ( V_19 ) ;
F_13 ( & V_19 -> V_29 , L_1 , & V_30 ) ;
}
return V_22 ;
}
struct V_16 * F_14 ( const struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_15 ( F_9 ( V_17 ) -> V_23 ) ;
}
struct V_16 * F_16 ( const struct V_14 * V_15 ,
struct V_31 * V_32 ,
struct V_33 * V_34 ,
const struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
struct V_20 * V_21 ;
struct V_16 * V_39 ;
struct V_40 * V_41 ;
int V_22 ;
F_17 ( V_21 ) ;
if ( V_21 == NULL )
return F_3 ( - V_9 ) ;
V_39 = & V_21 -> V_42 . V_43 ;
F_18 ( & V_21 -> V_42 , V_32 ) ;
F_19 ( V_21 ) -> V_44 = V_36 ;
V_21 -> V_42 . V_45 = V_38 ;
F_17 ( V_41 ) ;
if ( V_41 != NULL ) {
V_22 = F_20 ( V_41 , & V_21 -> V_42 ) ;
if ( V_22 == 0 )
V_22 = F_21 ( & V_41 -> V_46 ) ;
else {
F_11 ( V_39 -> V_24 == NULL ) ;
F_22 ( L_2 , V_22 ) ;
F_23 ( V_41 ) ;
}
} else
V_22 = - V_9 ;
if ( V_22 != 0 ) {
F_24 ( V_15 , V_39 ) ;
V_39 = F_3 ( V_22 ) ;
}
return V_39 ;
}
struct V_16 * F_24 ( const struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_20 * V_21 = F_9 ( V_17 ) ;
struct V_40 * V_41 = F_25 ( V_17 -> V_24 ) ;
struct V_16 * V_19 = F_15 ( V_21 -> V_23 ) ;
if ( V_17 -> V_24 != NULL ) {
F_26 ( V_41 ) ;
F_23 ( V_41 ) ;
}
F_27 ( F_10 ( V_17 ) ) ;
F_23 ( V_21 ) ;
return V_19 ;
}
int F_28 ( const struct V_14 * V_15 , struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 ;
int V_53 ;
F_2 ( V_52 , V_54 , V_8 ) ;
if ( V_52 != NULL ) {
F_29 ( V_50 , & V_52 -> V_55 , V_48 , & V_56 ) ;
V_53 = 0 ;
} else
V_53 = - V_9 ;
return V_53 ;
}
int F_30 ( struct V_31 * V_57 )
{
int V_53 ;
V_53 = F_31 ( V_58 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_32 ( V_57 ) ;
if ( V_53 )
goto V_59;
V_60 = F_33 ( & V_61 ,
V_62 | V_63 ) ;
if ( F_34 ( V_60 ) ) {
V_53 = F_35 ( V_60 ) ;
goto V_64;
}
V_60 -> V_65 . V_66 = 0x4 ;
return 0 ;
V_64:
F_36 ( V_57 ) ;
V_59:
F_37 ( V_58 ) ;
return V_53 ;
}
void F_38 ( struct V_31 * V_57 )
{
if ( V_60 != NULL ) {
F_39 ( V_60 , & V_61 ) ;
V_60 = NULL ;
}
F_36 ( V_57 ) ;
F_37 ( V_58 ) ;
}
struct V_67 * F_40 ( const struct V_14 * V_15 ,
const struct V_68 * V_69 ,
struct V_16 * V_48 ,
const struct V_70 * V_38 ,
const struct V_71 * V_36 )
{
struct V_72 * V_73 ;
struct V_67 * V_74 ;
F_2 ( V_73 , V_75 , V_8 ) ;
if ( V_73 != NULL ) {
struct V_76 * V_77 ;
V_74 = F_41 ( V_73 ) ;
V_77 = & V_73 -> V_78 ;
F_42 ( V_77 ) ;
F_43 ( V_74 , & V_77 -> V_79 , V_48 ) ;
F_44 ( & V_77 -> V_79 , V_74 ) ;
V_73 -> V_80 . V_81 = V_38 ;
V_74 -> V_82 = V_36 ;
} else
V_74 = NULL ;
return V_74 ;
}
int F_45 ( const struct V_14 * V_15 ,
struct V_72 * V_73 ,
const struct V_83 * V_84 )
{
V_73 -> V_85 = V_84 -> V_86 ;
V_73 -> V_87 = 0 ;
F_46 ( & V_73 -> V_80 , sizeof( struct V_88 ) ) ;
return 0 ;
}
int F_47 ( const struct V_14 * V_15 , struct V_67 * V_74 ,
const struct V_89 * V_84 )
{
struct V_20 * V_48 = F_9 ( V_74 -> V_90 ) ;
struct V_72 * V_73 = F_48 ( V_74 ) ;
struct V_67 * V_91 ;
struct V_16 * V_92 ;
int V_53 ;
V_92 = & V_48 -> V_23 -> V_43 ;
V_91 = V_92 -> V_44 -> V_93 ( V_15 , V_74 -> V_94 , V_92 ) ;
if ( V_91 != NULL ) {
const struct V_83 * V_95 ;
V_95 = F_49 ( V_84 ) ;
F_50 ( & V_73 -> V_96 ) ;
F_51 ( V_74 , V_91 ) ;
V_53 = F_45 ( V_15 , V_73 , V_95 ) ;
} else
V_53 = - V_9 ;
return V_53 ;
}
void F_52 ( const struct V_14 * V_15 , struct V_67 * V_74 )
{
struct V_72 * V_73 = F_48 ( V_74 ) ;
F_53 ( V_74 ) ;
F_54 ( V_74 -> V_94 ) ;
F_5 ( V_73 , V_75 ) ;
}
int F_55 ( const struct V_14 * V_15 ,
struct V_97 * V_74 , struct V_98 * V_99 ,
const struct V_100 * V_69 ,
const struct V_101 * V_102 )
{
struct V_103 * V_104 ;
int V_53 ;
F_56 ( V_15 , V_74 , F_57 ( V_74 ) ) ;
F_2 ( V_104 , V_105 , V_8 ) ;
if ( V_104 != NULL ) {
F_58 ( V_99 , & V_104 -> V_106 , V_74 , V_102 ) ;
V_53 = 0 ;
} else
V_53 = - V_9 ;
return V_53 ;
}
int F_59 ( const struct V_14 * V_15 , struct V_97 * V_74 ,
const struct V_107 * V_108 , unsigned V_109 )
{
return 0 ;
}
int F_60 ( const struct V_14 * V_15 ,
const struct V_97 * V_74 , struct V_110 * V_111 )
{
struct V_112 * V_112 = F_61 ( V_74 ) ;
V_111 -> V_113 = F_62 ( V_112 ) ;
V_111 -> V_114 = F_63 ( V_112 ) ;
V_111 -> V_115 = F_64 ( V_112 ) ;
if ( V_111 -> V_116 > 0 && V_111 -> V_117 == 0 )
V_111 -> V_117 = F_65 ( V_112 ) ;
return 0 ;
}
int F_66 ( const struct V_14 * V_15 , struct V_97 * V_74 ,
const struct V_83 * V_84 )
{
return 0 ;
}
static void F_67 ( struct V_97 * V_74 )
{
struct V_112 * V_112 = F_61 ( V_74 ) ;
F_68 ( V_112 ) ;
F_69 ( V_74 ) ;
}
static void F_70 ( struct V_97 * V_74 )
{
struct V_112 * V_112 = F_61 ( V_74 ) ;
F_71 ( V_74 ) ;
F_72 ( V_112 ) ;
}
struct V_118 * F_73 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 )
{
return F_74 ( V_120 ) ;
}
int F_75 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_121 )
{
struct V_122 * V_123 = F_76 ( V_15 ) ;
struct V_124 * V_125 = & F_77 ( V_15 ) -> V_126 ;
struct V_127 * V_118 = V_120 -> V_128 ;
int V_53 ;
if ( V_121 -> V_129 == V_130 || V_121 -> V_129 == V_131 ||
V_121 -> V_129 == V_132 ) {
if ( V_123 -> V_133 -> V_134 & V_135 )
V_53 = - V_136 ;
else {
V_125 -> V_137 = V_118 -> V_138 ;
V_125 -> V_139 = V_118 -> V_138 ;
V_125 -> V_140 = V_118 -> V_141 ;
V_125 -> V_142 = V_143 ;
V_53 = F_78 ( & V_121 -> V_144 . V_145 ,
V_125 ) ? - V_136 : 0 ;
}
} else
V_53 = 0 ;
return V_53 ;
}
int F_79 ( const struct V_14 * V_15 , const struct V_119 * V_120 )
{
F_80 () ;
return 0 ;
}
void F_81 ( const struct V_127 * V_118 )
{
}
int F_82 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 ,
int V_146 )
{
F_81 ( V_120 -> V_128 ) ;
return 0 ;
}
void F_83 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 )
{
F_81 ( V_120 -> V_128 ) ;
}
void F_84 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 )
{
F_81 ( V_120 -> V_128 ) ;
}
void F_85 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 )
{
F_81 ( V_120 -> V_128 ) ;
}
void F_86 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 )
{
struct V_127 * V_118 = V_120 -> V_128 ;
F_81 ( V_120 -> V_128 ) ;
F_87 ( V_15 , V_118 ) ;
}
int F_88 ( const struct V_14 * V_15 ,
const struct V_119 * V_120 ,
struct V_100 * V_69 )
{
return 0 ;
}
void F_89 ( const struct V_14 * V_15 ,
const struct V_147 * V_120 )
{
F_56 ( V_15 , V_120 -> V_148 , F_57 ( V_120 -> V_148 ) ) ;
}
void F_90 ( const struct V_14 * V_15 , struct V_147 * V_120 )
{
struct V_103 * V_104 = F_91 ( V_120 ) ;
F_5 ( V_104 , V_105 ) ;
}
int F_92 ( const struct V_14 * V_15 ,
const struct V_147 * V_120 ,
struct V_100 * V_69 , T_1 V_149 )
{
F_56 ( V_15 , V_120 -> V_148 , F_57 ( V_120 -> V_148 ) ) ;
return 0 ;
}
int F_93 ( const struct V_14 * V_15 , const struct V_147 * V_120 )
{
F_56 ( V_15 , V_120 -> V_148 , F_57 ( V_120 -> V_148 ) ) ;
return 0 ;
}
int F_94 ( const struct V_14 * V_15 , const struct V_147 * V_120 )
{
F_56 ( V_15 , V_120 -> V_148 , F_57 ( V_120 -> V_148 ) ) ;
return 0 ;
}
int F_95 ( const struct V_14 * V_15 ,
const struct V_147 * V_120 ,
const struct V_124 * V_150 ,
const struct V_100 * V_121 )
{
const struct V_98 * V_99 = V_120 -> V_151 ;
const struct V_124 * V_152 = & V_99 -> V_153 ;
const struct V_122 * V_123 = F_76 ( V_15 ) ;
int V_53 ;
if ( V_123 -> V_154 )
V_53 = V_152 -> V_142 != V_155 ;
else if ( V_150 -> V_142 != V_152 -> V_142 )
V_53 = V_99 -> V_156 >= V_157 ;
else
V_53 = 1 ;
return V_53 ;
}
void F_96 ( const struct V_14 * V_15 ,
const struct V_147 * V_120 ,
enum V_158 V_159 )
{
struct V_98 * V_99 = V_120 -> V_151 ;
if ( V_159 == V_160 && V_99 -> V_156 < V_160 ) {
struct V_97 * V_74 ;
struct V_112 * V_112 ;
V_74 = V_120 -> V_148 ;
V_112 = F_61 ( V_74 ) ;
if ( V_99 -> V_153 . V_137 == 0 &&
V_99 -> V_153 . V_139 == V_161 )
F_97 ( V_15 , V_112 ) ;
}
}
void F_98 ( const struct V_14 * V_15 , const struct V_162 * V_163 )
{
struct V_100 * V_121 = V_163 -> V_164 ;
F_56 ( V_15 , V_121 -> V_165 , F_57 ( V_121 -> V_165 ) ) ;
}
int F_99 ( const struct V_14 * V_15 , struct V_100 * V_121 ,
T_1 V_149 , enum V_166 V_167 ,
T_2 V_168 , T_2 V_169 )
{
struct V_122 * V_123 = F_76 ( V_15 ) ;
struct V_124 * V_152 = & V_123 -> V_170 . V_171 ;
struct V_97 * V_74 = V_121 -> V_165 ;
F_56 ( V_15 , V_74 , F_57 ( V_74 ) ) ;
F_100 ( V_172 , L_3 , V_167 , V_168 , V_169 ) ;
memset ( & V_123 -> V_170 , 0 , sizeof( V_123 -> V_170 ) ) ;
if ( V_123 -> V_133 && ( V_123 -> V_133 -> V_134 & V_135 ) ) {
V_152 -> V_142 = V_173 ;
V_152 -> V_174 = V_123 -> V_133 -> V_175 . V_176 ;
} else {
V_152 -> V_142 = V_167 ;
}
V_152 -> V_140 = V_74 ;
V_152 -> V_137 = V_168 ;
V_152 -> V_139 = V_169 ;
V_152 -> V_177 = V_149 ;
F_101 ( V_15 , V_121 , & V_123 -> V_170 ) ;
return 0 ;
}
void F_102 ( const struct V_14 * V_15 ,
struct V_122 * V_123 , struct V_100 * V_121 )
{
int V_178 ;
T_3 V_179 = V_121 -> V_180 . V_181 . V_182 ;
V_123 -> V_183 = 0 ;
if ( ! F_103 ( V_15 , V_121 ) || V_123 -> V_184 == 0 )
return;
for ( V_178 = 0 ; V_178 < V_123 -> V_184 ; V_178 ++ ) {
struct V_185 * V_186 = & V_123 -> V_187 [ V_178 ] ;
if ( V_186 -> V_188 < V_179 )
V_179 -= V_186 -> V_188 ;
else {
if ( V_186 -> V_188 > V_179 ) {
V_123 -> V_183 = V_186 -> V_188 ;
V_186 -> V_188 = V_179 ;
}
break;
}
}
V_123 -> V_189 = V_178 + 1 ;
F_104 ( V_123 -> V_184 >= V_123 -> V_189 ,
L_4 ,
V_123 -> V_184 , V_123 -> V_189 ) ;
}
int F_105 ( const struct V_14 * V_15 , struct V_100 * V_121 ,
T_1 V_149 , enum V_166 V_167 ,
T_4 V_168 , T_4 V_169 )
{
struct V_97 * V_74 = V_121 -> V_165 ;
return F_99 ( V_15 , V_121 , V_149 , V_167 ,
F_106 ( V_74 , V_168 ) , F_106 ( V_74 , V_169 ) ) ;
}
void F_107 ( const struct V_14 * V_15 , const struct V_162 * V_163 )
{
F_56 ( V_15 , V_163 -> V_164 -> V_165 ,
F_57 ( V_163 -> V_164 -> V_165 ) ) ;
}
void F_108 ( const struct V_14 * V_15 ,
const struct V_162 * V_163 ,
T_3 V_190 )
{
struct V_122 * V_123 = F_109 ( V_15 , V_163 ) ;
struct V_100 * V_121 = V_163 -> V_164 ;
struct V_97 * V_74 = V_163 -> V_164 -> V_165 ;
F_56 ( V_15 , V_74 , F_57 ( V_74 ) ) ;
if ( ! F_103 ( V_15 , V_121 ) )
return;
F_11 ( V_123 -> V_184 >= V_123 -> V_189 ) ;
F_11 ( V_123 -> V_191 >= V_190 ) ;
V_123 -> V_187 += V_123 -> V_189 ;
V_123 -> V_184 -= V_123 -> V_189 ;
V_123 -> V_191 -= V_190 ;
if ( V_123 -> V_183 > 0 ) {
struct V_185 * V_186 ;
V_123 -> V_187 -- ;
V_123 -> V_184 ++ ;
V_186 = & V_123 -> V_187 [ 0 ] ;
if ( V_121 -> V_192 ) {
V_186 -> V_193 += V_186 -> V_188 ;
F_11 ( V_123 -> V_183 > V_186 -> V_188 ) ;
V_186 -> V_188 = V_123 -> V_183 - V_186 -> V_188 ;
} else {
V_186 -> V_188 = V_123 -> V_183 ;
}
V_123 -> V_183 = 0 ;
}
}
int F_110 ( const struct V_14 * V_15 , struct V_97 * V_74 ,
struct V_100 * V_121 , T_4 V_168 , T_3 V_194 , int * V_195 )
{
struct V_107 * V_108 = F_111 ( V_15 ) ;
struct V_112 * V_112 = F_61 ( V_74 ) ;
T_4 V_196 = V_168 + V_194 - 1 ;
T_4 V_197 ;
int V_53 ;
F_67 ( V_74 ) ;
V_53 = F_112 ( V_15 , V_74 , V_108 ) ;
if ( V_53 == 0 ) {
V_197 = V_108 -> V_198 ;
if ( V_196 > V_197 ) {
F_70 ( V_74 ) ;
V_53 = F_113 ( V_15 , V_121 , V_112 , V_74 , 0 ) ;
if ( V_53 == 0 && V_195 != NULL ) {
T_4 V_179 = F_114 ( V_112 ) ;
unsigned long V_199 = V_168 >> V_200 ;
if ( ( V_179 == 0 && V_199 != 0 ) ||
( ( ( V_179 - 1 ) >> V_200 ) < V_199 ) )
* V_195 = 1 ;
}
return V_53 ;
} else {
if ( F_114 ( V_112 ) < V_197 ) {
F_115 ( V_112 , V_197 ) ;
F_100 ( V_172 ,
V_201 L_5 V_202 L_6 ,
F_116 ( F_117 ( & V_74 -> V_203 ) ) ,
( V_204 ) F_114 ( V_112 ) ) ;
}
}
}
F_70 ( V_74 ) ;
return V_53 ;
}
void F_118 ( const struct V_14 * V_15 ,
const struct V_205 * V_120 , int V_206 )
{
struct V_51 * V_52 ;
if ( V_206 > 0 )
F_119 ( V_120 -> V_207 , V_120 -> V_208 -> V_209 , V_206 ) ;
V_52 = F_120 ( V_120 ) ;
F_5 ( V_52 , V_54 ) ;
}
void F_121 ( const struct V_14 * V_15 ,
const struct V_205 * V_120 ,
const struct V_97 * V_74 ,
struct V_210 * V_108 , T_5 V_211 )
{
struct V_112 * V_112 ;
struct V_212 * V_213 ;
T_6 V_214 ;
V_213 = V_108 -> V_215 ;
V_112 = F_61 ( V_74 ) ;
V_214 = V_216 ;
if ( ( V_211 & V_217 ) != 0 ) {
F_11 ( V_108 -> V_218 == NULL ) ;
V_108 -> V_218 = F_122 ( V_112 ,
V_120 -> V_208 -> V_209 ) ;
}
if ( V_120 -> V_208 -> V_209 == V_219 ) {
if ( V_211 & V_220 ) {
V_213 -> V_221 |= V_220 ;
V_213 -> V_222 = F_123 ( V_112 ) -> V_223 ;
V_214 |= V_224 | V_225 |
V_226 | V_227 ;
}
}
F_124 ( V_213 , V_112 , V_214 & V_211 ) ;
F_125 ( V_213 , & F_123 ( V_112 ) -> V_228 ) ;
memcpy ( V_108 -> V_229 , F_123 ( V_112 ) -> V_230 ,
V_231 ) ;
}
int F_126 ( struct V_112 * V_112 , const struct V_232 * V_108 ,
struct V_233 * V_234 )
{
struct V_14 * V_15 ;
struct V_100 * V_121 ;
int V_53 ;
int V_235 ;
V_15 = F_127 ( & V_235 ) ;
if ( F_34 ( V_15 ) )
return F_35 ( V_15 ) ;
V_121 = F_128 ( V_15 ) ;
V_121 -> V_165 = F_123 ( V_112 ) -> V_236 ;
V_121 -> V_180 . V_237 . V_238 . V_114 = F_129 ( V_108 -> V_239 ) ;
V_121 -> V_180 . V_237 . V_238 . V_113 = F_129 ( V_108 -> V_240 ) ;
V_121 -> V_180 . V_237 . V_238 . V_115 = F_129 ( V_108 -> V_241 ) ;
V_121 -> V_180 . V_237 . V_238 . V_116 = V_108 -> V_242 ;
V_121 -> V_180 . V_237 . V_243 = V_108 -> V_244 ;
V_121 -> V_180 . V_237 . V_245 = V_234 ;
V_246:
if ( F_130 ( V_15 , V_121 , V_247 , V_121 -> V_165 ) == 0 ) {
struct V_122 * V_123 = F_76 ( V_15 ) ;
if ( V_108 -> V_244 & V_248 )
V_123 -> V_133 = F_131 ( V_112 , V_108 ) ;
V_53 = F_132 ( V_15 , V_121 ) ;
} else {
V_53 = V_121 -> V_249 ;
}
F_133 ( V_15 , V_121 ) ;
if ( F_134 ( V_121 -> V_250 ) )
goto V_246;
F_39 ( V_15 , & V_235 ) ;
return V_53 ;
}
struct V_16 * F_19 ( struct V_20 * V_21 )
{
return & V_21 -> V_42 . V_43 ;
}
struct V_20 * F_9 ( const struct V_16 * V_17 )
{
return F_135 ( V_17 , struct V_20 , V_42 . V_43 ) ;
}
struct V_20 * F_136 ( const struct V_47 * V_17 )
{
return F_135 ( V_17 , struct V_20 , V_42 ) ;
}
struct V_67 * F_41 ( struct V_72 * V_73 )
{
return & V_73 -> V_80 . V_203 ;
}
struct V_72 * F_48 ( const struct V_67 * V_74 )
{
return F_135 ( V_74 , struct V_72 , V_80 . V_203 ) ;
}
struct V_72 * F_137 ( const struct V_97 * V_74 )
{
return F_135 ( V_74 , struct V_72 , V_80 ) ;
}
struct V_103 * F_91 ( const struct V_147 * V_120 )
{
return F_138 ( V_120 , struct V_103 , V_106 ) ;
}
struct V_122 * F_109 ( const struct V_14 * V_15 ,
const struct V_162 * V_120 )
{
struct V_122 * V_123 ;
V_123 = F_138 ( V_120 , struct V_122 , V_251 ) ;
F_11 ( V_123 == F_76 ( V_15 ) ) ;
return V_123 ;
}
struct V_51 * F_120 ( const struct V_205 * V_120 )
{
return F_135 ( V_120 , struct V_51 , V_55 ) ;
}
struct V_118 * F_74 ( const struct V_119 * V_120 )
{
return F_139 ( V_120 ) -> V_252 ;
}
int F_57 ( const struct V_97 * V_74 )
{
struct V_112 * V_112 = F_61 ( V_74 ) ;
struct V_253 * V_254 = F_123 ( V_112 ) ;
return ( F_140 ( F_141 ( V_112 ) ) ||
F_141 ( V_112 ) == 0 ) && V_254 -> V_236 == V_74 ;
}
struct V_112 * F_61 ( const struct V_97 * V_74 )
{
return F_137 ( V_74 ) -> V_85 ;
}
struct V_127 * F_142 ( struct V_118 * V_255 )
{
F_143 ( F_144 ( V_255 ) ) ;
return (struct V_127 * ) V_255 -> V_256 ;
}
int F_145 ( struct V_112 * V_112 , struct V_257 * V_258 )
{
struct V_14 * V_15 ;
struct V_253 * V_254 ;
struct V_97 * V_259 ;
struct V_260 * V_41 ;
struct V_261 * V_262 ;
struct V_83 V_84 = {
. V_86 = V_112 ,
. V_180 = {
. V_263 = V_258
}
} ;
int V_53 = 0 ;
int V_235 ;
F_11 ( V_258 -> V_264 -> V_109 & V_265 ) ;
F_11 ( F_140 ( F_141 ( V_112 ) ) ) ;
V_15 = F_127 ( & V_235 ) ;
if ( F_34 ( V_15 ) )
return F_35 ( V_15 ) ;
V_41 = F_146 ( V_112 ) -> V_266 ;
V_254 = F_123 ( V_112 ) ;
V_262 = & V_254 -> V_228 ;
F_11 ( F_147 ( V_262 ) ) ;
if ( V_254 -> V_236 == NULL ) {
F_11 ( V_112 -> V_267 & V_268 ) ;
V_84 . V_269 . V_270 = V_271 ;
V_259 = F_148 ( V_15 , F_10 ( V_41 -> V_272 ) ,
V_262 , & V_84 ) ;
if ( ! F_34 ( V_259 ) ) {
V_254 -> V_236 = V_259 ;
V_254 -> V_273 = F_149 ( V_258 -> V_274 ) ;
F_150 ( & V_259 -> V_203 , L_7 , V_112 ) ;
} else
V_53 = F_35 ( V_259 ) ;
} else {
V_53 = F_151 ( V_15 , V_254 -> V_236 , & V_84 ) ;
}
F_39 ( V_15 , & V_235 ) ;
if ( V_53 != 0 )
F_22 ( L_8 V_201 L_9 ,
F_116 ( V_262 ) , V_53 ) ;
return V_53 ;
}
static void F_152 ( struct V_14 * V_15 , struct V_97 * V_74 )
{
struct V_68 * V_275 = V_74 -> V_203 . V_94 ;
T_7 V_276 ;
if ( F_134 ( F_153 ( & V_275 -> V_277 ) != 1 ) ) {
struct V_260 * V_41 = V_74 -> V_203 . V_90 -> V_24 ;
struct V_278 * V_279 ;
V_279 = F_154 ( V_41 , & V_275 -> V_280 ) ;
F_155 ( & V_276 ) ;
F_156 ( & V_279 -> V_281 , & V_276 ) ;
while ( 1 ) {
F_157 ( V_282 ) ;
if ( F_153 ( & V_275 -> V_277 ) == 1 )
break;
F_158 ( & V_276 , V_282 ) ;
}
F_157 ( V_283 ) ;
F_159 ( & V_279 -> V_281 , & V_276 ) ;
}
F_160 ( V_15 , V_74 ) ;
}
void F_161 ( struct V_112 * V_112 )
{
struct V_14 * V_15 ;
struct V_253 * V_254 = F_123 ( V_112 ) ;
struct V_97 * V_259 = V_254 -> V_236 ;
int V_235 ;
int V_284 ;
if ( V_259 != NULL ) {
void * V_285 ;
V_285 = F_162 () ;
V_15 = F_127 ( & V_235 ) ;
V_284 = F_34 ( V_15 ) ;
if ( V_284 ) {
F_163 ( & V_286 ) ;
F_11 ( V_60 != NULL ) ;
F_164 ( V_60 , & V_235 ) ;
V_15 = V_60 ;
}
F_165 ( V_15 , V_259 ) ;
F_166 ( & V_259 -> V_203 , L_7 , V_112 ) ;
F_152 ( V_15 , V_259 ) ;
V_254 -> V_236 = NULL ;
if ( V_284 ) {
F_167 ( V_60 , & V_235 ) ;
F_168 ( & V_286 ) ;
} else
F_39 ( V_15 , & V_235 ) ;
F_169 ( V_285 ) ;
}
}
T_8 F_170 ( struct V_287 * V_288 )
{
T_8 type = 0 ;
struct V_289 * V_290 ;
int V_291 = 0 ;
if ( F_171 ( V_288 -> V_292 ) & V_293 ) {
const unsigned V_294 = sizeof( struct V_289 ) - 1 ;
V_291 = F_172 ( V_288 -> V_295 ) ;
V_291 = ( V_291 + V_294 ) & ~ V_294 ;
V_290 = ( void * ) V_288 -> V_296 + V_291 ;
type = F_173 ( F_172 ( V_290 -> V_297 ) ) ;
}
return type ;
}
V_204 F_174 ( const struct V_261 * V_262 , int V_298 )
{
if ( V_299 == 32 || V_298 )
return F_175 ( V_262 ) ;
else
return F_176 ( V_262 ) ;
}
T_1 F_177 ( const struct V_261 * V_262 )
{
T_1 V_300 ;
if ( F_178 ( V_262 ) ) {
V_300 = F_179 ( V_262 ) ;
return V_300 ;
}
V_300 = ( F_176 ( V_262 ) >> 32 ) ;
return V_300 ;
}
struct V_301 * F_180 ( struct V_112 * V_112 )
{
return F_181 ( F_123 ( V_112 ) -> V_236 ) ;
}
void inline F_182 ( struct V_112 * V_112 , struct V_301 * V_274 )
{
F_183 ( F_123 ( V_112 ) -> V_236 , V_274 ) ;
}
