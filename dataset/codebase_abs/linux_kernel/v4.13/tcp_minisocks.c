static bool F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_1 == V_3 )
return true ;
if ( F_2 ( V_2 , V_3 ) && F_3 ( V_1 , V_4 ) )
return true ;
return V_1 == V_4 && V_1 == V_2 ;
}
static enum V_5
F_4 ( struct V_6 * V_7 ,
const struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = F_5 ( (struct V_13 * ) V_7 ) ;
if ( ! F_6 ( F_7 ( V_7 ) , V_9 , V_10 ,
& V_12 -> V_14 ) ) {
return V_15 ;
}
F_8 ( V_7 ) ;
return V_16 ;
}
enum V_5
F_9 ( struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_17 * V_18 )
{
struct V_19 V_20 ;
struct V_11 * V_12 = F_5 ( (struct V_13 * ) V_7 ) ;
bool V_21 = false ;
V_20 . V_22 = 0 ;
if ( V_18 -> V_23 > ( sizeof( * V_18 ) >> 2 ) && V_12 -> V_24 ) {
F_10 ( F_7 ( V_7 ) , V_9 , & V_20 , 0 , NULL ) ;
if ( V_20 . V_22 ) {
if ( V_20 . V_25 )
V_20 . V_25 -= V_12 -> V_26 ;
V_20 . V_27 = V_12 -> V_28 ;
V_20 . V_29 = V_12 -> V_24 ;
V_21 = F_11 ( & V_20 , V_18 -> V_30 ) ;
}
}
if ( V_7 -> V_31 == V_32 ) {
if ( V_21 ||
! F_1 ( F_12 ( V_9 ) -> V_1 , F_12 ( V_9 ) -> V_2 ,
V_12 -> V_33 ,
V_12 -> V_33 + V_12 -> V_34 ) )
return F_4 (
V_7 , V_9 , V_35 ) ;
if ( V_18 -> V_30 )
goto V_36;
if ( V_18 -> V_37 && ! F_3 ( F_12 ( V_9 ) -> V_1 , V_12 -> V_33 ) )
return V_38 ;
if ( ! V_18 -> V_39 ||
! F_2 ( F_12 ( V_9 ) -> V_2 , V_12 -> V_33 ) ||
F_12 ( V_9 ) -> V_2 == F_12 ( V_9 ) -> V_1 ) {
F_8 ( V_7 ) ;
return V_16 ;
}
if ( ! V_18 -> V_40 ||
F_12 ( V_9 ) -> V_2 != V_12 -> V_33 + 1 )
return V_38 ;
V_7 -> V_31 = V_41 ;
V_12 -> V_33 = F_12 ( V_9 ) -> V_2 ;
if ( V_20 . V_22 ) {
V_12 -> V_24 = F_13 () ;
V_12 -> V_28 = V_20 . V_42 ;
}
F_14 ( V_7 , V_43 ) ;
return V_15 ;
}
if ( ! V_21 &&
( F_12 ( V_9 ) -> V_1 == V_12 -> V_33 &&
( F_12 ( V_9 ) -> V_1 == F_12 ( V_9 ) -> V_2 || V_18 -> V_30 ) ) ) {
if ( V_18 -> V_30 ) {
if ( V_44 == 0 ) {
V_36:
F_15 ( V_7 ) ;
return V_16 ;
}
}
F_14 ( V_7 , V_43 ) ;
if ( V_20 . V_22 ) {
V_12 -> V_28 = V_20 . V_42 ;
V_12 -> V_24 = F_13 () ;
}
F_8 ( V_7 ) ;
return V_16 ;
}
if ( V_18 -> V_37 && ! V_18 -> V_30 && ! V_18 -> V_39 && ! V_21 &&
( F_2 ( F_12 ( V_9 ) -> V_1 , V_12 -> V_33 ) ||
( V_20 . V_22 &&
( V_45 ) ( V_12 -> V_28 - V_20 . V_42 ) < 0 ) ) ) {
T_1 V_46 = V_12 -> V_47 + 65535 + 2 ;
if ( V_46 == 0 )
V_46 ++ ;
F_12 ( V_9 ) -> V_48 = V_46 ;
return V_49 ;
}
if ( V_21 )
F_16 ( F_7 ( V_7 ) , V_50 ) ;
if ( ! V_18 -> V_30 ) {
if ( V_21 || V_18 -> V_39 )
F_14 ( V_7 , V_43 ) ;
return F_4 (
V_7 , V_9 , V_51 ) ;
}
F_8 ( V_7 ) ;
return V_16 ;
}
void F_17 ( struct V_13 * V_52 , int V_53 , int V_54 )
{
const struct V_55 * V_56 = F_18 ( V_52 ) ;
const struct V_57 * V_58 = F_19 ( V_52 ) ;
struct V_6 * V_7 ;
struct V_59 * V_60 = & F_20 ( V_52 ) -> V_61 . V_60 ;
V_7 = F_21 ( V_52 , V_60 , V_53 ) ;
if ( V_7 ) {
struct V_11 * V_12 = F_5 ( (struct V_13 * ) V_7 ) ;
const int V_62 = ( V_56 -> V_63 << 2 ) - ( V_56 -> V_63 >> 1 ) ;
struct V_64 * V_65 = F_22 ( V_52 ) ;
V_7 -> V_66 = V_65 -> V_67 ;
V_7 -> V_68 = V_58 -> V_69 . V_70 ;
V_12 -> V_33 = V_58 -> V_71 ;
V_12 -> V_47 = V_58 -> V_72 ;
V_12 -> V_34 = F_23 ( V_58 ) ;
V_12 -> V_28 = V_58 -> V_69 . V_27 ;
V_12 -> V_24 = V_58 -> V_69 . V_29 ;
V_12 -> V_26 = V_58 -> V_73 ;
V_12 -> V_14 = 0 ;
#if F_24 ( V_74 )
if ( V_7 -> V_75 == V_76 ) {
struct V_77 * V_78 = F_25 ( V_52 ) ;
V_7 -> V_79 = V_52 -> V_80 ;
V_7 -> V_81 = V_52 -> V_82 ;
V_7 -> V_83 = V_78 -> V_84 ;
V_7 -> V_85 = F_26 ( V_78 -> V_86 & V_87 ) ;
V_7 -> V_88 = V_52 -> V_89 ;
}
#endif
#ifdef F_27
do {
struct V_90 * V_91 ;
V_12 -> V_92 = NULL ;
V_91 = V_58 -> V_93 -> V_94 ( V_52 , V_52 ) ;
if ( V_91 ) {
V_12 -> V_92 = F_28 ( V_91 , sizeof( * V_91 ) , V_95 ) ;
if ( V_12 -> V_92 && ! F_29 () )
F_30 () ;
}
} while ( 0 );
#endif
if ( V_54 < V_62 )
V_54 = V_62 ;
V_7 -> V_96 = V_43 ;
if ( V_53 == V_41 )
V_54 = V_43 ;
F_31 ( V_7 , V_54 ) ;
F_32 ( V_7 , V_52 , & V_97 ) ;
F_8 ( V_7 ) ;
} else {
F_33 ( F_20 ( V_52 ) , V_98 ) ;
}
F_34 ( V_52 ) ;
F_35 ( V_52 ) ;
}
void F_36 ( struct V_13 * V_52 )
{
#ifdef F_27
struct V_11 * V_99 = F_5 ( V_52 ) ;
if ( V_99 -> V_92 )
F_37 ( V_99 -> V_92 , V_100 ) ;
#endif
}
void F_38 ( struct V_101 * V_102 ,
const struct V_13 * V_103 ,
const struct V_104 * V_105 )
{
struct V_106 * V_107 = F_39 ( V_102 ) ;
const struct V_57 * V_58 = F_19 ( V_103 ) ;
int V_108 = F_40 ( V_103 ) ;
T_1 V_109 ;
T_2 V_70 ;
T_1 V_110 ;
int V_111 ;
V_111 = F_41 ( V_58 , F_42 ( V_105 ) ) ;
V_109 = F_43 ( V_58 -> V_109 ) ;
V_102 -> V_112 = V_109 ? : F_44 ( V_105 , V_113 ) ;
if ( V_103 -> V_114 & V_115 &&
( V_102 -> V_112 > V_108 || V_102 -> V_112 == 0 ) )
V_102 -> V_112 = V_108 ;
V_110 = F_45 ( (struct V_13 * ) V_102 ) ;
if ( V_110 == 0 )
V_110 = F_44 ( V_105 , V_116 ) ;
else if ( V_108 < V_110 * V_111 )
V_108 = V_110 * V_111 ;
F_46 ( V_108 ,
V_111 - ( V_107 -> V_117 ? V_118 : 0 ) ,
& V_102 -> V_119 ,
& V_102 -> V_112 ,
V_107 -> V_120 ,
& V_70 ,
V_110 ) ;
V_107 -> V_70 = V_70 ;
}
static void F_47 ( struct V_57 * V_58 ,
const struct V_101 * V_102 )
{
V_58 -> V_121 = F_39 ( V_102 ) -> V_122 ? V_123 : 0 ;
}
void F_48 ( struct V_13 * V_52 , const struct V_104 * V_105 )
{
struct V_55 * V_56 = F_18 ( V_52 ) ;
T_1 V_124 = F_44 ( V_105 , V_125 ) ;
bool V_126 = false ;
if ( V_124 != V_127 ) {
const struct V_128 * V_129 ;
F_49 () ;
V_129 = F_50 ( V_124 ) ;
if ( F_51 ( V_129 && F_52 ( V_129 -> V_130 ) ) ) {
V_56 -> V_131 = F_53 ( V_105 ) ;
V_56 -> V_132 = V_129 ;
V_126 = true ;
}
F_54 () ;
}
if ( ! V_126 &&
( ! V_56 -> V_133 ||
! F_52 ( V_56 -> V_132 -> V_130 ) ) )
F_55 ( V_52 ) ;
F_56 ( V_52 , V_134 ) ;
}
struct V_13 * F_57 ( const struct V_13 * V_52 ,
struct V_101 * V_102 ,
struct V_8 * V_9 )
{
struct V_13 * V_135 = F_58 ( V_52 , V_102 , V_95 ) ;
if ( V_135 ) {
const struct V_106 * V_107 = F_39 ( V_102 ) ;
struct V_136 * V_137 = F_59 ( V_102 ) ;
struct V_55 * V_138 = F_18 ( V_135 ) ;
struct V_57 * V_139 = F_19 ( V_135 ) ;
V_139 -> V_140 = 0 ;
V_139 -> V_141 = V_139 -> V_142 =
V_139 -> V_71 = V_137 -> V_143 + 1 ;
V_139 -> V_144 = 1 ;
V_139 -> V_145 = V_139 -> V_146 =
V_139 -> V_72 = V_139 -> V_147 = V_137 -> V_148 + 1 ;
F_60 ( V_139 ) ;
F_61 ( & V_139 -> V_149 ) ;
F_62 ( V_139 , V_137 -> V_143 ) ;
V_139 -> V_150 = 0 ;
V_139 -> V_151 = F_63 ( V_152 ) ;
F_64 ( & V_139 -> V_153 , V_154 , ~ 0U ) ;
V_138 -> V_63 = V_152 ;
V_138 -> V_155 . V_156 = V_154 ;
V_139 -> V_157 = 0 ;
V_139 -> V_158 = 0 ;
V_139 -> V_159 = 0 ;
V_139 -> V_160 = 0 ;
V_139 -> V_161 = V_162 ;
V_139 -> V_163 = 0 ;
V_139 -> V_164 = V_154 ;
V_135 -> V_165 = V_137 -> V_166 ;
V_139 -> V_167 = 0 ;
V_139 -> V_168 = V_102 -> V_169 ;
V_139 -> V_170 = V_171 ;
V_139 -> V_172 = 0 ;
V_139 -> V_173 = ~ 0U ;
F_65 ( V_135 ) ;
V_139 -> V_174 = V_139 -> V_175 = V_137 -> V_148 + 1 ;
V_139 -> V_69 . V_22 = 0 ;
V_139 -> V_69 . V_176 = 0 ;
V_139 -> V_69 . V_177 = 0 ;
V_139 -> V_178 = 0 ;
if ( F_66 ( V_135 , V_179 ) )
F_67 ( V_135 ,
F_68 ( V_139 ) ) ;
V_139 -> V_69 . V_117 = V_107 -> V_117 ;
if ( ( V_139 -> V_69 . V_180 = V_107 -> V_180 ) != 0 ) {
if ( V_181 )
F_69 ( V_139 ) ;
}
V_139 -> V_109 = V_102 -> V_112 ;
V_139 -> V_182 = V_102 -> V_119 ;
V_139 -> V_110 = V_102 -> V_119 ;
V_139 -> V_69 . V_120 = V_107 -> V_120 ;
if ( V_139 -> V_69 . V_120 ) {
V_139 -> V_69 . V_183 = V_107 -> V_183 ;
V_139 -> V_69 . V_70 = V_107 -> V_70 ;
} else {
V_139 -> V_69 . V_183 = V_139 -> V_69 . V_70 = 0 ;
V_139 -> V_109 = F_70 ( V_139 -> V_109 , 65535U ) ;
}
V_139 -> V_184 = ( F_71 ( F_72 ( V_9 ) -> V_185 ) <<
V_139 -> V_69 . V_183 ) ;
V_139 -> V_186 = V_139 -> V_184 ;
if ( V_139 -> V_69 . V_117 ) {
V_139 -> V_69 . V_27 = V_102 -> V_27 ;
V_139 -> V_69 . V_29 = F_13 () ;
V_139 -> V_187 = sizeof( struct V_17 ) + V_118 ;
} else {
V_139 -> V_69 . V_29 = 0 ;
V_139 -> V_187 = sizeof( struct V_17 ) ;
}
V_139 -> V_73 = V_137 -> V_188 ;
#ifdef F_27
V_139 -> V_189 = NULL ;
if ( V_139 -> V_93 -> V_94 ( V_52 , V_135 ) )
V_139 -> V_187 += V_190 ;
#endif
if ( V_9 -> V_191 >= V_192 + V_139 -> V_187 )
V_138 -> V_155 . V_193 = V_9 -> V_191 - V_139 -> V_187 ;
V_139 -> V_69 . V_194 = V_102 -> V_111 ;
F_47 ( V_139 , V_102 ) ;
V_139 -> V_195 = NULL ;
V_139 -> V_196 = NULL ;
V_139 -> V_197 = 0 ;
V_139 -> V_198 . V_199 = 0 ;
V_139 -> V_198 . V_200 = 0 ;
F_73 ( F_20 ( V_52 ) , V_201 ) ;
}
return V_135 ;
}
struct V_13 * F_74 ( struct V_13 * V_52 , struct V_8 * V_9 ,
struct V_101 * V_102 ,
bool V_202 )
{
struct V_19 V_20 ;
struct V_13 * V_203 ;
const struct V_17 * V_18 = F_72 ( V_9 ) ;
T_3 V_204 = F_75 ( V_18 ) & ( V_205 | V_206 | V_207 ) ;
bool V_21 = false ;
bool V_208 ;
V_20 . V_22 = 0 ;
if ( V_18 -> V_23 > ( sizeof( struct V_17 ) >> 2 ) ) {
F_10 ( F_20 ( V_52 ) , V_9 , & V_20 , 0 , NULL ) ;
if ( V_20 . V_22 ) {
V_20 . V_27 = V_102 -> V_27 ;
if ( V_20 . V_25 )
V_20 . V_25 -= F_59 ( V_102 ) -> V_188 ;
V_20 . V_29 = F_13 () - ( ( V_152 / V_209 ) << V_102 -> V_210 ) ;
V_21 = F_11 ( & V_20 , V_18 -> V_30 ) ;
}
}
if ( F_12 ( V_9 ) -> V_1 == F_59 ( V_102 ) -> V_143 &&
V_204 == V_206 &&
! V_21 ) {
if ( ! F_6 ( F_20 ( V_52 ) , V_9 ,
V_211 ,
& F_59 ( V_102 ) -> V_167 ) &&
! F_76 ( V_52 , V_102 ) ) {
unsigned long V_212 = V_213 ;
V_212 += F_70 ( V_152 << V_102 -> V_210 ,
V_214 ) ;
if ( ! V_202 )
F_77 ( & V_102 -> V_215 , V_212 ) ;
else
V_102 -> V_215 . V_212 = V_212 ;
}
return NULL ;
}
if ( ( V_204 & V_207 ) && ! V_202 &&
( F_12 ( V_9 ) -> V_216 !=
F_59 ( V_102 ) -> V_148 + 1 ) )
return V_52 ;
if ( V_21 || ! F_1 ( F_12 ( V_9 ) -> V_1 , F_12 ( V_9 ) -> V_2 ,
F_59 ( V_102 ) -> V_71 , F_59 ( V_102 ) -> V_71 + V_102 -> V_119 ) ) {
if ( ! ( V_204 & V_205 ) &&
! F_6 ( F_20 ( V_52 ) , V_9 ,
V_211 ,
& F_59 ( V_102 ) -> V_167 ) )
V_102 -> V_217 -> V_218 ( V_52 , V_9 , V_102 ) ;
if ( V_21 )
F_16 ( F_20 ( V_52 ) , V_50 ) ;
return NULL ;
}
if ( V_20 . V_22 && ! F_2 ( F_12 ( V_9 ) -> V_1 , F_59 ( V_102 ) -> V_71 ) )
V_102 -> V_27 = V_20 . V_42 ;
if ( F_12 ( V_9 ) -> V_1 == F_59 ( V_102 ) -> V_143 ) {
V_204 &= ~ V_206 ;
}
if ( V_204 & ( V_205 | V_206 ) ) {
F_73 ( F_20 ( V_52 ) , V_219 ) ;
goto V_220;
}
if ( ! ( V_204 & V_207 ) )
return NULL ;
if ( V_202 )
return V_52 ;
if ( V_102 -> V_210 < F_18 ( V_52 ) -> V_221 . V_222 &&
F_12 ( V_9 ) -> V_2 == F_59 ( V_102 ) -> V_143 + 1 ) {
F_39 ( V_102 ) -> V_223 = 1 ;
F_16 ( F_20 ( V_52 ) , V_224 ) ;
return NULL ;
}
V_203 = F_18 ( V_52 ) -> V_225 -> V_226 ( V_52 , V_9 , V_102 , NULL ,
V_102 , & V_208 ) ;
if ( ! V_203 )
goto V_227;
F_78 ( V_203 , V_9 ) ;
F_79 ( V_203 , V_102 ) ;
return F_80 ( V_52 , V_203 , V_102 , V_208 ) ;
V_227:
if ( ! V_228 ) {
F_39 ( V_102 ) -> V_223 = 1 ;
return NULL ;
}
V_220:
if ( ! ( V_204 & V_205 ) ) {
V_102 -> V_217 -> V_229 ( V_52 , V_9 ) ;
} else if ( V_202 ) {
F_81 ( V_52 , V_102 , true ) ;
F_82 ( V_52 ) ;
}
if ( ! V_202 ) {
F_83 ( V_52 , V_102 ) ;
F_16 ( F_20 ( V_52 ) , V_230 ) ;
}
return NULL ;
}
int F_84 ( struct V_13 * V_231 , struct V_13 * V_203 ,
struct V_8 * V_9 )
{
int V_232 = 0 ;
int V_53 = V_203 -> V_233 ;
F_85 ( V_203 , V_9 ) ;
F_86 ( F_19 ( V_203 ) , V_9 ) ;
if ( ! F_87 ( V_203 ) ) {
V_232 = F_88 ( V_203 , V_9 ) ;
if ( V_53 == V_234 && V_203 -> V_233 != V_53 )
V_231 -> V_235 ( V_231 ) ;
} else {
F_89 ( V_203 , V_9 ) ;
}
F_90 ( V_203 ) ;
F_91 ( V_203 ) ;
return V_232 ;
}
