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
V_23 ;
V_21 = F_9 ( V_17 ) ;
V_21 -> V_24 = F_10 ( V_19 ) ;
F_11 ( V_17 -> V_25 != NULL && V_19 -> V_26 != NULL ) ;
V_19 -> V_25 = V_17 -> V_25 ;
V_22 = V_19 -> V_26 -> V_27 -> V_28 (
V_15 , V_19 , V_19 -> V_26 -> V_29 , NULL ) ;
if ( V_22 == 0 ) {
F_12 ( V_19 ) ;
F_13 ( & V_19 -> V_30 , L_1 , & V_31 ) ;
}
RETURN ( V_22 ) ;
}
struct V_16 * F_14 ( const struct V_14 * V_15 ,
struct V_16 * V_17 )
{
return F_15 ( F_9 ( V_17 ) -> V_24 ) ;
}
struct V_16 * F_16 ( const struct V_14 * V_15 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
const struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_20 * V_21 ;
struct V_16 * V_40 ;
struct V_41 * V_42 ;
int V_22 ;
V_23 ;
F_17 ( V_21 ) ;
if ( V_21 == NULL )
RETURN ( F_3 ( - V_9 ) ) ;
V_40 = & V_21 -> V_43 . V_44 ;
F_18 ( & V_21 -> V_43 , V_33 ) ;
F_19 ( V_21 ) -> V_45 = V_37 ;
V_21 -> V_43 . V_46 = V_39 ;
F_17 ( V_42 ) ;
if ( V_42 != NULL ) {
V_22 = F_20 ( V_42 , & V_21 -> V_43 ) ;
if ( V_22 == 0 )
V_22 = F_21 ( & V_42 -> V_47 ) ;
else {
F_11 ( V_40 -> V_25 == NULL ) ;
F_22 ( L_2 , V_22 ) ;
F_23 ( V_42 ) ;
}
} else
V_22 = - V_9 ;
if ( V_22 != 0 ) {
F_24 ( V_15 , V_40 ) ;
V_40 = F_3 ( V_22 ) ;
}
RETURN ( V_40 ) ;
}
struct V_16 * F_24 ( const struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_20 * V_21 = F_9 ( V_17 ) ;
struct V_41 * V_42 = F_25 ( V_17 -> V_25 ) ;
struct V_16 * V_19 = F_15 ( V_21 -> V_24 ) ;
if ( V_17 -> V_25 != NULL ) {
F_26 ( V_42 ) ;
F_23 ( V_42 ) ;
}
F_27 ( F_10 ( V_17 ) ) ;
F_23 ( V_21 ) ;
return V_19 ;
}
int F_28 ( const struct V_14 * V_15 , struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_54 ;
F_2 ( V_53 , V_55 , V_8 ) ;
if ( V_53 != NULL ) {
F_29 ( V_51 , & V_53 -> V_56 , V_49 , & V_57 ) ;
V_54 = 0 ;
} else
V_54 = - V_9 ;
return V_54 ;
}
int F_30 ( struct V_32 * V_58 )
{
int V_54 ;
V_54 = F_31 ( V_59 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_32 ( V_58 ) ;
if ( V_54 )
goto V_60;
V_61 = F_33 ( & V_62 ,
V_63 | V_64 ) ;
if ( F_34 ( V_61 ) ) {
V_54 = F_35 ( V_61 ) ;
goto V_65;
}
V_61 -> V_66 . V_67 = 0x4 ;
return 0 ;
V_65:
F_36 ( V_58 ) ;
V_60:
F_37 ( V_59 ) ;
return V_54 ;
}
void F_38 ( struct V_32 * V_58 )
{
if ( V_61 != NULL ) {
F_39 ( V_61 , & V_62 ) ;
V_61 = NULL ;
}
F_36 ( V_58 ) ;
F_37 ( V_59 ) ;
}
struct V_68 * F_40 ( const struct V_14 * V_15 ,
const struct V_69 * V_70 ,
struct V_16 * V_49 ,
const struct V_71 * V_39 ,
const struct V_72 * V_37 )
{
struct V_73 * V_74 ;
struct V_68 * V_75 ;
F_2 ( V_74 , V_76 , V_8 ) ;
if ( V_74 != NULL ) {
struct V_77 * V_78 ;
V_75 = F_41 ( V_74 ) ;
V_78 = & V_74 -> V_79 ;
F_42 ( V_78 ) ;
F_43 ( V_75 , & V_78 -> V_80 , V_49 ) ;
F_44 ( & V_78 -> V_80 , V_75 ) ;
V_74 -> V_81 . V_82 = V_39 ;
V_75 -> V_83 = V_37 ;
} else
V_75 = NULL ;
return V_75 ;
}
int F_45 ( const struct V_14 * V_15 ,
struct V_73 * V_74 ,
const struct V_84 * V_85 )
{
V_74 -> V_86 = V_85 -> V_87 ;
V_74 -> V_88 = 0 ;
F_46 ( & V_74 -> V_81 , sizeof( struct V_89 ) ) ;
return 0 ;
}
int F_47 ( const struct V_14 * V_15 , struct V_68 * V_75 ,
const struct V_90 * V_85 )
{
struct V_20 * V_49 = F_9 ( V_75 -> V_91 ) ;
struct V_73 * V_74 = F_48 ( V_75 ) ;
struct V_68 * V_92 ;
struct V_16 * V_93 ;
int V_54 ;
V_93 = & V_49 -> V_24 -> V_44 ;
V_92 = V_93 -> V_45 -> V_94 ( V_15 , V_75 -> V_95 , V_93 ) ;
if ( V_92 != NULL ) {
const struct V_84 * V_96 ;
V_96 = F_49 ( V_85 ) ;
F_50 ( & V_74 -> V_97 ) ;
F_51 ( V_75 , V_92 ) ;
V_54 = F_45 ( V_15 , V_74 , V_96 ) ;
} else
V_54 = - V_9 ;
return V_54 ;
}
void F_52 ( const struct V_14 * V_15 , struct V_68 * V_75 )
{
struct V_73 * V_74 = F_48 ( V_75 ) ;
F_53 ( V_75 ) ;
F_54 ( V_75 -> V_95 ) ;
F_5 ( V_74 , V_76 ) ;
}
int F_55 ( const struct V_14 * V_15 ,
struct V_98 * V_75 , struct V_99 * V_100 ,
const struct V_101 * V_70 ,
const struct V_102 * V_103 )
{
struct V_104 * V_105 ;
int V_54 ;
F_56 ( V_15 , V_75 , F_57 ( V_75 ) ) ;
F_2 ( V_105 , V_106 , V_8 ) ;
if ( V_105 != NULL ) {
F_58 ( V_100 , & V_105 -> V_107 , V_75 , V_103 ) ;
V_54 = 0 ;
} else
V_54 = - V_9 ;
return V_54 ;
}
int F_59 ( const struct V_14 * V_15 , struct V_98 * V_75 ,
const struct V_108 * V_109 , unsigned V_110 )
{
return 0 ;
}
int F_60 ( const struct V_14 * V_15 ,
const struct V_98 * V_75 , struct V_111 * V_112 )
{
struct V_113 * V_113 = F_61 ( V_75 ) ;
V_23 ;
V_112 -> V_114 = F_62 ( V_113 ) ;
V_112 -> V_115 = F_63 ( V_113 ) ;
V_112 -> V_116 = F_64 ( V_113 ) ;
if ( V_112 -> V_117 > 0 && V_112 -> V_118 == 0 )
V_112 -> V_118 = F_65 ( V_113 ) ;
RETURN ( 0 ) ;
}
int F_66 ( const struct V_14 * V_15 , struct V_98 * V_75 ,
const struct V_84 * V_85 )
{
return 0 ;
}
static void F_67 ( struct V_98 * V_75 )
{
struct V_113 * V_113 = F_61 ( V_75 ) ;
F_68 ( V_113 ) ;
F_69 ( V_75 ) ;
}
static void F_70 ( struct V_98 * V_75 )
{
struct V_113 * V_113 = F_61 ( V_75 ) ;
F_71 ( V_75 ) ;
F_72 ( V_113 ) ;
}
struct V_119 * F_73 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 )
{
return F_74 ( V_121 ) ;
}
int F_75 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_122 )
{
struct V_123 * V_124 = F_76 ( V_15 ) ;
struct V_125 * V_126 = & F_77 ( V_15 ) -> V_127 ;
struct V_128 * V_119 = V_121 -> V_129 ;
int V_54 ;
V_23 ;
if ( V_122 -> V_130 == V_131 || V_122 -> V_130 == V_132 ||
V_122 -> V_130 == V_133 ) {
if ( V_124 -> V_134 -> V_135 & V_136 )
V_54 = - V_137 ;
else {
V_126 -> V_138 = V_119 -> V_139 ;
V_126 -> V_140 = V_119 -> V_139 ;
V_126 -> V_141 = V_119 -> V_142 ;
V_126 -> V_143 = V_144 ;
V_54 = F_78 ( & V_122 -> V_145 . V_146 ,
V_126 ) ? - V_137 : 0 ;
}
} else
V_54 = 0 ;
RETURN ( V_54 ) ;
}
int F_79 ( const struct V_14 * V_15 , const struct V_120 * V_121 )
{
F_80 () ;
return 0 ;
}
void F_81 ( const struct V_128 * V_119 )
{
}
int F_82 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 ,
int V_147 )
{
F_81 ( V_121 -> V_129 ) ;
return 0 ;
}
void F_83 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 )
{
F_81 ( V_121 -> V_129 ) ;
}
void F_84 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 )
{
F_81 ( V_121 -> V_129 ) ;
}
void F_85 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 )
{
F_81 ( V_121 -> V_129 ) ;
}
void F_86 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 )
{
struct V_128 * V_119 = V_121 -> V_129 ;
F_81 ( V_121 -> V_129 ) ;
F_87 ( V_15 , V_119 ) ;
}
int F_88 ( const struct V_14 * V_15 ,
const struct V_120 * V_121 ,
struct V_101 * V_70 )
{
V_23 ;
RETURN ( 0 ) ;
}
void F_89 ( const struct V_14 * V_15 ,
const struct V_148 * V_121 )
{
F_56 ( V_15 , V_121 -> V_149 , F_57 ( V_121 -> V_149 ) ) ;
}
void F_90 ( const struct V_14 * V_15 , struct V_148 * V_121 )
{
struct V_104 * V_105 = F_91 ( V_121 ) ;
F_5 ( V_105 , V_106 ) ;
}
int F_92 ( const struct V_14 * V_15 ,
const struct V_148 * V_121 ,
struct V_101 * V_70 , T_1 V_150 )
{
F_56 ( V_15 , V_121 -> V_149 , F_57 ( V_121 -> V_149 ) ) ;
return 0 ;
}
int F_93 ( const struct V_14 * V_15 , const struct V_148 * V_121 )
{
F_56 ( V_15 , V_121 -> V_149 , F_57 ( V_121 -> V_149 ) ) ;
return 0 ;
}
int F_94 ( const struct V_14 * V_15 , const struct V_148 * V_121 )
{
F_56 ( V_15 , V_121 -> V_149 , F_57 ( V_121 -> V_149 ) ) ;
return 0 ;
}
int F_95 ( const struct V_14 * V_15 ,
const struct V_148 * V_121 ,
const struct V_125 * V_151 ,
const struct V_101 * V_122 )
{
const struct V_99 * V_100 = V_121 -> V_152 ;
const struct V_125 * V_153 = & V_100 -> V_154 ;
const struct V_123 * V_124 = F_76 ( V_15 ) ;
int V_54 ;
V_23 ;
if ( V_124 -> V_155 )
V_54 = V_153 -> V_143 != V_156 ;
else if ( V_151 -> V_143 != V_153 -> V_143 )
V_54 = V_100 -> V_157 >= V_158 ;
else
V_54 = 1 ;
RETURN ( V_54 ) ;
}
void F_96 ( const struct V_14 * V_15 ,
const struct V_148 * V_121 ,
enum V_159 V_160 )
{
struct V_99 * V_100 = V_121 -> V_152 ;
V_23 ;
if ( V_160 == V_161 && V_100 -> V_157 < V_161 ) {
struct V_98 * V_75 ;
struct V_113 * V_113 ;
V_75 = V_121 -> V_149 ;
V_113 = F_61 ( V_75 ) ;
if ( V_100 -> V_154 . V_138 == 0 &&
V_100 -> V_154 . V_140 == V_162 )
F_97 ( V_15 , V_113 ) ;
}
EXIT ;
}
void F_98 ( const struct V_14 * V_15 , const struct V_163 * V_164 )
{
struct V_101 * V_122 = V_164 -> V_165 ;
F_56 ( V_15 , V_122 -> V_166 , F_57 ( V_122 -> V_166 ) ) ;
}
int F_99 ( const struct V_14 * V_15 , struct V_101 * V_122 ,
T_1 V_150 , enum V_167 V_168 ,
T_2 V_169 , T_2 V_170 )
{
struct V_123 * V_124 = F_76 ( V_15 ) ;
struct V_125 * V_153 = & V_124 -> V_171 . V_172 ;
struct V_98 * V_75 = V_122 -> V_166 ;
F_56 ( V_15 , V_75 , F_57 ( V_75 ) ) ;
V_23 ;
F_100 ( V_173 , L_3 , V_168 , V_169 , V_170 ) ;
memset ( & V_124 -> V_171 , 0 , sizeof V_124 -> V_171 ) ;
if ( V_124 -> V_134 && ( V_124 -> V_134 -> V_135 & V_136 ) ) {
V_153 -> V_143 = V_174 ;
V_153 -> V_175 = V_124 -> V_134 -> V_176 . V_177 ;
} else {
V_153 -> V_143 = V_168 ;
}
V_153 -> V_141 = V_75 ;
V_153 -> V_138 = V_169 ;
V_153 -> V_140 = V_170 ;
V_153 -> V_178 = V_150 ;
F_101 ( V_15 , V_122 , & V_124 -> V_171 ) ;
RETURN ( 0 ) ;
}
void F_102 ( const struct V_14 * V_15 ,
struct V_123 * V_124 , struct V_101 * V_122 )
{
int V_179 ;
T_3 V_180 = V_122 -> V_181 . V_182 . V_183 ;
V_124 -> V_184 = 0 ;
if ( ! F_103 ( V_15 , V_122 ) || V_124 -> V_185 == 0 )
return;
for ( V_179 = 0 ; V_179 < V_124 -> V_185 ; V_179 ++ ) {
struct V_186 * V_187 = & V_124 -> V_188 [ V_179 ] ;
if ( V_187 -> V_189 < V_180 )
V_180 -= V_187 -> V_189 ;
else {
if ( V_187 -> V_189 > V_180 ) {
V_124 -> V_184 = V_187 -> V_189 ;
V_187 -> V_189 = V_180 ;
}
break;
}
}
V_124 -> V_190 = V_179 + 1 ;
F_104 ( V_124 -> V_185 >= V_124 -> V_190 ,
L_4 ,
V_124 -> V_185 , V_124 -> V_190 ) ;
}
int F_105 ( const struct V_14 * V_15 , struct V_101 * V_122 ,
T_1 V_150 , enum V_167 V_168 ,
T_4 V_169 , T_4 V_170 )
{
struct V_98 * V_75 = V_122 -> V_166 ;
return F_99 ( V_15 , V_122 , V_150 , V_168 ,
F_106 ( V_75 , V_169 ) , F_106 ( V_75 , V_170 ) ) ;
}
void F_107 ( const struct V_14 * V_15 , const struct V_163 * V_164 )
{
F_56 ( V_15 , V_164 -> V_165 -> V_166 ,
F_57 ( V_164 -> V_165 -> V_166 ) ) ;
}
void F_108 ( const struct V_14 * V_15 ,
const struct V_163 * V_164 ,
T_3 V_191 )
{
struct V_123 * V_124 = F_109 ( V_15 , V_164 ) ;
struct V_101 * V_122 = V_164 -> V_165 ;
struct V_98 * V_75 = V_164 -> V_165 -> V_166 ;
F_56 ( V_15 , V_75 , F_57 ( V_75 ) ) ;
if ( ! F_103 ( V_15 , V_122 ) )
return;
F_11 ( V_124 -> V_185 >= V_124 -> V_190 ) ;
F_11 ( V_124 -> V_192 >= V_191 ) ;
V_124 -> V_188 += V_124 -> V_190 ;
V_124 -> V_185 -= V_124 -> V_190 ;
V_124 -> V_192 -= V_191 ;
if ( V_124 -> V_184 > 0 ) {
struct V_186 * V_187 ;
V_124 -> V_188 -- ;
V_124 -> V_185 ++ ;
V_187 = & V_124 -> V_188 [ 0 ] ;
if ( V_122 -> V_193 ) {
V_187 -> V_194 += V_187 -> V_189 ;
F_11 ( V_124 -> V_184 > V_187 -> V_189 ) ;
V_187 -> V_189 = V_124 -> V_184 - V_187 -> V_189 ;
} else {
V_187 -> V_189 = V_124 -> V_184 ;
}
V_124 -> V_184 = 0 ;
}
}
int F_110 ( const struct V_14 * V_15 , struct V_98 * V_75 ,
struct V_101 * V_122 , T_4 V_169 , T_3 V_195 , int * V_196 )
{
struct V_108 * V_109 = F_111 ( V_15 ) ;
struct V_113 * V_113 = F_61 ( V_75 ) ;
T_4 V_197 = V_169 + V_195 - 1 ;
T_4 V_198 ;
int V_54 ;
F_67 ( V_75 ) ;
V_54 = F_112 ( V_15 , V_75 , V_109 ) ;
if ( V_54 == 0 ) {
V_198 = V_109 -> V_199 ;
if ( V_197 > V_198 ) {
F_70 ( V_75 ) ;
V_54 = F_113 ( V_15 , V_122 , V_113 , V_75 , 0 ) ;
if ( V_54 == 0 && V_196 != NULL ) {
T_4 V_180 = F_114 ( V_113 ) ;
unsigned long V_200 = V_169 >> V_201 ;
if ( ( V_180 == 0 && V_200 != 0 ) ||
( ( ( V_180 - 1 ) >> V_201 ) < V_200 ) )
* V_196 = 1 ;
}
return V_54 ;
} else {
if ( F_114 ( V_113 ) < V_198 ) {
F_115 ( V_113 , V_198 ) ;
F_100 ( V_173 ,
V_202 L_5 V_203 L_6 ,
F_116 ( F_117 ( & V_75 -> V_204 ) ) ,
( V_205 ) F_114 ( V_113 ) ) ;
}
}
}
F_70 ( V_75 ) ;
return V_54 ;
}
void F_118 ( const struct V_14 * V_15 ,
const struct V_206 * V_121 , int V_207 )
{
struct V_52 * V_53 ;
if ( V_207 > 0 )
F_119 ( V_121 -> V_208 , V_121 -> V_209 -> V_210 , V_207 ) ;
V_53 = F_120 ( V_121 ) ;
F_5 ( V_53 , V_55 ) ;
}
void F_121 ( const struct V_14 * V_15 ,
const struct V_206 * V_121 ,
const struct V_98 * V_75 ,
struct V_211 * V_109 , T_5 V_212 )
{
struct V_113 * V_113 ;
struct V_213 * V_214 ;
T_6 V_215 ;
V_214 = V_109 -> V_216 ;
V_113 = F_61 ( V_75 ) ;
V_215 = V_217 ;
if ( ( V_212 & V_218 ) != 0 ) {
F_11 ( V_109 -> V_219 == NULL ) ;
V_109 -> V_219 = F_122 ( V_113 ,
V_121 -> V_209 -> V_210 ) ;
}
if ( V_121 -> V_209 -> V_210 == V_220 ) {
if ( V_212 & V_221 ) {
V_214 -> V_222 |= V_221 ;
V_214 -> V_223 = F_123 ( V_113 ) -> V_224 ;
V_215 |= V_225 | V_226 |
V_227 | V_228 ;
}
}
F_124 ( V_214 , V_113 , V_215 & V_212 ) ;
F_125 ( V_214 , & F_123 ( V_113 ) -> V_229 ) ;
memcpy ( V_109 -> V_230 , F_123 ( V_113 ) -> V_231 ,
V_232 ) ;
}
int F_126 ( struct V_113 * V_113 , const struct V_233 * V_109 ,
struct V_234 * V_235 )
{
struct V_14 * V_15 ;
struct V_101 * V_122 ;
int V_54 ;
int V_236 ;
V_23 ;
V_15 = F_127 ( & V_236 ) ;
if ( F_34 ( V_15 ) )
RETURN ( F_35 ( V_15 ) ) ;
V_122 = F_128 ( V_15 ) ;
V_122 -> V_166 = F_123 ( V_113 ) -> V_237 ;
V_122 -> V_181 . V_238 . V_239 . V_115 = F_129 ( V_109 -> V_240 ) ;
V_122 -> V_181 . V_238 . V_239 . V_114 = F_129 ( V_109 -> V_241 ) ;
V_122 -> V_181 . V_238 . V_239 . V_116 = F_129 ( V_109 -> V_242 ) ;
V_122 -> V_181 . V_238 . V_239 . V_117 = V_109 -> V_243 ;
V_122 -> V_181 . V_238 . V_244 = V_109 -> V_245 ;
V_122 -> V_181 . V_238 . V_246 = V_235 ;
V_247:
if ( F_130 ( V_15 , V_122 , V_248 , V_122 -> V_166 ) == 0 ) {
struct V_123 * V_124 = F_76 ( V_15 ) ;
if ( V_109 -> V_245 & V_249 )
V_124 -> V_134 = F_131 ( V_113 , V_109 ) ;
V_54 = F_132 ( V_15 , V_122 ) ;
} else {
V_54 = V_122 -> V_250 ;
}
F_133 ( V_15 , V_122 ) ;
if ( F_134 ( V_122 -> V_251 ) )
goto V_247;
F_39 ( V_15 , & V_236 ) ;
RETURN ( V_54 ) ;
}
struct V_16 * F_19 ( struct V_20 * V_21 )
{
return & V_21 -> V_43 . V_44 ;
}
struct V_20 * F_9 ( const struct V_16 * V_17 )
{
return F_135 ( V_17 , struct V_20 , V_43 . V_44 ) ;
}
struct V_20 * F_136 ( const struct V_48 * V_17 )
{
return F_135 ( V_17 , struct V_20 , V_43 ) ;
}
struct V_68 * F_41 ( struct V_73 * V_74 )
{
return & V_74 -> V_81 . V_204 ;
}
struct V_73 * F_48 ( const struct V_68 * V_75 )
{
return F_135 ( V_75 , struct V_73 , V_81 . V_204 ) ;
}
struct V_73 * F_137 ( const struct V_98 * V_75 )
{
return F_135 ( V_75 , struct V_73 , V_81 ) ;
}
struct V_104 * F_91 ( const struct V_148 * V_121 )
{
return F_138 ( V_121 , struct V_104 , V_107 ) ;
}
struct V_123 * F_109 ( const struct V_14 * V_15 ,
const struct V_163 * V_121 )
{
struct V_123 * V_124 ;
V_124 = F_138 ( V_121 , struct V_123 , V_252 ) ;
F_11 ( V_124 == F_76 ( V_15 ) ) ;
return V_124 ;
}
struct V_52 * F_120 ( const struct V_206 * V_121 )
{
return F_135 ( V_121 , struct V_52 , V_56 ) ;
}
struct V_119 * F_74 ( const struct V_120 * V_121 )
{
return F_139 ( V_121 ) -> V_253 ;
}
int F_57 ( const struct V_98 * V_75 )
{
struct V_113 * V_113 = F_61 ( V_75 ) ;
struct V_254 * V_255 = F_123 ( V_113 ) ;
return ( F_140 ( F_141 ( V_113 ) ) ||
F_141 ( V_113 ) == 0 ) && V_255 -> V_237 == V_75 ;
}
struct V_113 * F_61 ( const struct V_98 * V_75 )
{
return F_137 ( V_75 ) -> V_86 ;
}
struct V_128 * F_142 ( struct V_119 * V_256 )
{
F_143 ( F_144 ( V_256 ) ) ;
return (struct V_128 * ) V_256 -> V_257 ;
}
int F_145 ( struct V_113 * V_113 , struct V_258 * V_259 )
{
struct V_14 * V_15 ;
struct V_254 * V_255 ;
struct V_98 * V_260 ;
struct V_261 * V_42 ;
struct V_262 * V_263 ;
struct V_84 V_85 = {
. V_87 = V_113 ,
. V_181 = {
. V_264 = V_259
}
} ;
int V_54 = 0 ;
int V_236 ;
F_11 ( V_259 -> V_265 -> V_110 & V_266 ) ;
F_11 ( F_140 ( F_141 ( V_113 ) ) ) ;
V_15 = F_127 ( & V_236 ) ;
if ( F_34 ( V_15 ) )
return F_35 ( V_15 ) ;
V_42 = F_146 ( V_113 ) -> V_267 ;
V_255 = F_123 ( V_113 ) ;
V_263 = & V_255 -> V_229 ;
F_11 ( F_147 ( V_263 ) ) ;
if ( V_255 -> V_237 == NULL ) {
F_11 ( V_113 -> V_268 & V_269 ) ;
V_85 . V_270 . V_271 = V_272 ;
V_260 = F_148 ( V_15 , F_10 ( V_42 -> V_273 ) ,
V_263 , & V_85 ) ;
if ( ! F_34 ( V_260 ) ) {
V_255 -> V_237 = V_260 ;
V_255 -> V_274 = V_259 -> V_275 != NULL ;
F_149 ( & V_260 -> V_204 , L_7 , V_113 ) ;
} else
V_54 = F_35 ( V_260 ) ;
} else {
V_54 = F_150 ( V_15 , V_255 -> V_237 , & V_85 ) ;
}
F_39 ( V_15 , & V_236 ) ;
if ( V_54 != 0 )
F_22 ( L_8 V_202 L_9 ,
F_116 ( V_263 ) , V_54 ) ;
return V_54 ;
}
static void F_151 ( struct V_14 * V_15 , struct V_98 * V_75 )
{
struct V_69 * V_276 = V_75 -> V_204 . V_95 ;
T_7 V_277 ;
if ( F_134 ( F_152 ( & V_276 -> V_278 ) != 1 ) ) {
struct V_261 * V_42 = V_75 -> V_204 . V_91 -> V_25 ;
struct V_279 * V_280 ;
V_280 = F_153 ( V_42 , & V_276 -> V_281 ) ;
F_154 ( & V_277 ) ;
F_155 ( & V_280 -> V_282 , & V_277 ) ;
while ( 1 ) {
F_156 ( V_283 ) ;
if ( F_152 ( & V_276 -> V_278 ) == 1 )
break;
F_157 ( & V_277 , V_283 ) ;
}
F_156 ( V_284 ) ;
F_158 ( & V_280 -> V_282 , & V_277 ) ;
}
F_159 ( V_15 , V_75 ) ;
}
void F_160 ( struct V_113 * V_113 )
{
struct V_14 * V_15 ;
struct V_254 * V_255 = F_123 ( V_113 ) ;
struct V_98 * V_260 = V_255 -> V_237 ;
int V_236 ;
int V_285 ;
if ( V_260 != NULL ) {
void * V_286 ;
V_286 = F_161 () ;
V_15 = F_127 ( & V_236 ) ;
V_285 = F_34 ( V_15 ) ;
if ( V_285 ) {
F_162 ( & V_287 ) ;
F_11 ( V_61 != NULL ) ;
F_163 ( V_61 , & V_236 ) ;
V_15 = V_61 ;
}
F_164 ( V_15 , V_260 ) ;
F_165 ( & V_260 -> V_204 , L_7 , V_113 ) ;
F_151 ( V_15 , V_260 ) ;
V_255 -> V_237 = NULL ;
if ( V_285 ) {
F_166 ( V_61 , & V_236 ) ;
F_167 ( & V_287 ) ;
} else
F_39 ( V_15 , & V_236 ) ;
F_168 ( V_286 ) ;
}
}
T_8 F_169 ( struct V_288 * V_289 )
{
T_8 type = 0 ;
struct V_290 * V_291 ;
int V_292 = 0 ;
if ( F_170 ( V_289 -> V_293 ) & V_294 ) {
const unsigned V_295 = sizeof( struct V_290 ) - 1 ;
V_292 = F_171 ( V_289 -> V_296 ) ;
V_292 = ( V_292 + V_295 ) & ~ V_295 ;
V_291 = ( void * ) V_289 -> V_297 + V_292 ;
type = F_172 ( F_171 ( V_291 -> V_298 ) ) ;
}
return type ;
}
V_205 F_173 ( const struct V_262 * V_263 , int V_299 )
{
if ( V_300 == 32 || V_299 )
RETURN ( F_174 ( V_263 ) ) ;
else
RETURN ( F_175 ( V_263 ) ) ;
}
T_1 F_176 ( const struct V_262 * V_263 )
{
T_1 V_301 ;
V_23 ;
if ( F_177 ( V_263 ) ) {
V_301 = F_178 ( V_263 ) ;
RETURN ( V_301 ) ;
}
V_301 = ( F_175 ( V_263 ) >> 32 ) ;
RETURN ( V_301 ) ;
}
struct V_302 * F_179 ( struct V_113 * V_113 )
{
return F_180 ( F_123 ( V_113 ) -> V_237 ) ;
}
void inline F_181 ( struct V_113 * V_113 , struct V_302 * V_275 )
{
F_182 ( F_123 ( V_113 ) -> V_237 , V_275 ) ;
}
