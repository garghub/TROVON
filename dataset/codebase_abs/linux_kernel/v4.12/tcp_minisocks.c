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
F_10 ( V_9 , & V_20 , 0 , NULL ) ;
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
int V_110 ;
V_110 = F_41 ( V_58 , F_42 ( V_105 ) ) ;
V_109 = F_43 ( V_58 -> V_109 ) ;
V_102 -> V_111 = V_109 ? : F_44 ( V_105 , V_112 ) ;
if ( V_103 -> V_113 & V_114 &&
( V_102 -> V_111 > V_108 || V_102 -> V_111 == 0 ) )
V_102 -> V_111 = V_108 ;
F_45 ( V_108 ,
V_110 - ( V_107 -> V_115 ? V_116 : 0 ) ,
& V_102 -> V_117 ,
& V_102 -> V_111 ,
V_107 -> V_118 ,
& V_70 ,
F_44 ( V_105 , V_119 ) ) ;
V_107 -> V_70 = V_70 ;
}
static void F_46 ( struct V_57 * V_58 ,
const struct V_101 * V_102 )
{
V_58 -> V_120 = F_39 ( V_102 ) -> V_121 ? V_122 : 0 ;
}
void F_47 ( struct V_13 * V_52 , const struct V_104 * V_105 )
{
struct V_55 * V_56 = F_18 ( V_52 ) ;
T_1 V_123 = F_44 ( V_105 , V_124 ) ;
bool V_125 = false ;
if ( V_123 != V_126 ) {
const struct V_127 * V_128 ;
F_48 () ;
V_128 = F_49 ( V_123 ) ;
if ( F_50 ( V_128 && F_51 ( V_128 -> V_129 ) ) ) {
V_56 -> V_130 = F_52 ( V_105 ) ;
V_56 -> V_131 = V_128 ;
V_125 = true ;
}
F_53 () ;
}
if ( ! V_125 &&
( ! V_56 -> V_132 ||
! F_51 ( V_56 -> V_131 -> V_129 ) ) )
F_54 ( V_52 ) ;
F_55 ( V_52 , V_133 ) ;
}
struct V_13 * F_56 ( const struct V_13 * V_52 ,
struct V_101 * V_102 ,
struct V_8 * V_9 )
{
struct V_13 * V_134 = F_57 ( V_52 , V_102 , V_95 ) ;
if ( V_134 ) {
const struct V_106 * V_107 = F_39 ( V_102 ) ;
struct V_135 * V_136 = F_58 ( V_102 ) ;
struct V_55 * V_137 = F_18 ( V_134 ) ;
struct V_57 * V_138 = F_19 ( V_134 ) ;
V_138 -> V_139 = 0 ;
V_138 -> V_140 = V_138 -> V_141 =
V_138 -> V_71 = V_136 -> V_142 + 1 ;
V_138 -> V_143 = 1 ;
V_138 -> V_144 = V_138 -> V_145 =
V_138 -> V_72 = V_138 -> V_146 = V_136 -> V_147 + 1 ;
F_59 ( V_138 ) ;
F_60 ( & V_138 -> V_148 ) ;
F_61 ( V_138 , V_136 -> V_142 ) ;
V_138 -> V_149 = 0 ;
V_138 -> V_150 = F_62 ( V_151 ) ;
F_63 ( & V_138 -> V_152 , V_153 , ~ 0U ) ;
V_137 -> V_63 = V_151 ;
V_137 -> V_154 . V_155 = V_153 ;
V_138 -> V_156 = 0 ;
V_138 -> V_157 = 0 ;
V_138 -> V_158 = 0 ;
V_138 -> V_159 = 0 ;
V_138 -> V_160 = V_161 ;
V_138 -> V_162 = 0 ;
V_138 -> V_163 = V_136 -> V_164 . V_165 ;
V_134 -> V_166 = V_136 -> V_167 ;
V_138 -> V_168 = 0 ;
V_138 -> V_169 = V_102 -> V_170 ;
V_138 -> V_171 = V_172 ;
V_138 -> V_173 = 0 ;
V_138 -> V_174 = ~ 0U ;
F_64 ( V_134 ) ;
V_138 -> V_175 = V_138 -> V_176 = V_136 -> V_147 + 1 ;
V_138 -> V_69 . V_22 = 0 ;
V_138 -> V_69 . V_177 = 0 ;
V_138 -> V_69 . V_178 = 0 ;
V_138 -> V_179 = 0 ;
if ( F_65 ( V_134 , V_180 ) )
F_66 ( V_134 ,
F_67 ( V_138 ) ) ;
V_138 -> V_69 . V_115 = V_107 -> V_115 ;
if ( ( V_138 -> V_69 . V_181 = V_107 -> V_181 ) != 0 ) {
if ( V_182 )
F_68 ( V_138 ) ;
}
V_138 -> V_109 = V_102 -> V_111 ;
V_138 -> V_183 = V_102 -> V_117 ;
V_138 -> V_184 = V_102 -> V_117 ;
V_138 -> V_69 . V_118 = V_107 -> V_118 ;
if ( V_138 -> V_69 . V_118 ) {
V_138 -> V_69 . V_185 = V_107 -> V_185 ;
V_138 -> V_69 . V_70 = V_107 -> V_70 ;
} else {
V_138 -> V_69 . V_185 = V_138 -> V_69 . V_70 = 0 ;
V_138 -> V_109 = F_69 ( V_138 -> V_109 , 65535U ) ;
}
V_138 -> V_186 = ( F_70 ( F_71 ( V_9 ) -> V_187 ) <<
V_138 -> V_69 . V_185 ) ;
V_138 -> V_188 = V_138 -> V_186 ;
if ( V_138 -> V_69 . V_115 ) {
V_138 -> V_69 . V_27 = V_102 -> V_27 ;
V_138 -> V_69 . V_29 = F_13 () ;
V_138 -> V_189 = sizeof( struct V_17 ) + V_116 ;
} else {
V_138 -> V_69 . V_29 = 0 ;
V_138 -> V_189 = sizeof( struct V_17 ) ;
}
V_138 -> V_73 = V_136 -> V_190 ;
#ifdef F_27
V_138 -> V_191 = NULL ;
if ( V_138 -> V_93 -> V_94 ( V_52 , V_134 ) )
V_138 -> V_189 += V_192 ;
#endif
if ( V_9 -> V_193 >= V_194 + V_138 -> V_189 )
V_137 -> V_154 . V_195 = V_9 -> V_193 - V_138 -> V_189 ;
V_138 -> V_69 . V_196 = V_102 -> V_110 ;
F_46 ( V_138 , V_102 ) ;
V_138 -> V_197 = NULL ;
V_138 -> V_198 = NULL ;
V_138 -> V_199 = 0 ;
V_138 -> V_200 . V_201 . V_202 = 0 ;
V_138 -> V_200 . V_203 = 0 ;
F_72 ( F_20 ( V_52 ) , V_204 ) ;
}
return V_134 ;
}
struct V_13 * F_73 ( struct V_13 * V_52 , struct V_8 * V_9 ,
struct V_101 * V_102 ,
bool V_205 )
{
struct V_19 V_20 ;
struct V_13 * V_206 ;
const struct V_17 * V_18 = F_71 ( V_9 ) ;
T_3 V_207 = F_74 ( V_18 ) & ( V_208 | V_209 | V_210 ) ;
bool V_21 = false ;
bool V_211 ;
V_20 . V_22 = 0 ;
if ( V_18 -> V_23 > ( sizeof( struct V_17 ) >> 2 ) ) {
F_10 ( V_9 , & V_20 , 0 , NULL ) ;
if ( V_20 . V_22 ) {
V_20 . V_27 = V_102 -> V_27 ;
if ( V_20 . V_25 )
V_20 . V_25 -= F_58 ( V_102 ) -> V_190 ;
V_20 . V_29 = F_13 () - ( ( V_151 / V_212 ) << V_102 -> V_213 ) ;
V_21 = F_11 ( & V_20 , V_18 -> V_30 ) ;
}
}
if ( F_12 ( V_9 ) -> V_1 == F_58 ( V_102 ) -> V_142 &&
V_207 == V_209 &&
! V_21 ) {
if ( ! F_6 ( F_20 ( V_52 ) , V_9 ,
V_214 ,
& F_58 ( V_102 ) -> V_168 ) &&
! F_75 ( V_52 , V_102 ) ) {
unsigned long V_215 = V_216 ;
V_215 += F_69 ( V_151 << V_102 -> V_213 ,
V_217 ) ;
if ( ! V_205 )
F_76 ( & V_102 -> V_218 , V_215 ) ;
else
V_102 -> V_218 . V_215 = V_215 ;
}
return NULL ;
}
if ( ( V_207 & V_210 ) && ! V_205 &&
( F_12 ( V_9 ) -> V_219 !=
F_58 ( V_102 ) -> V_147 + 1 ) )
return V_52 ;
if ( V_21 || ! F_1 ( F_12 ( V_9 ) -> V_1 , F_12 ( V_9 ) -> V_2 ,
F_58 ( V_102 ) -> V_71 , F_58 ( V_102 ) -> V_71 + V_102 -> V_117 ) ) {
if ( ! ( V_207 & V_208 ) &&
! F_6 ( F_20 ( V_52 ) , V_9 ,
V_214 ,
& F_58 ( V_102 ) -> V_168 ) )
V_102 -> V_220 -> V_221 ( V_52 , V_9 , V_102 ) ;
if ( V_21 )
F_16 ( F_20 ( V_52 ) , V_50 ) ;
return NULL ;
}
if ( V_20 . V_22 && ! F_2 ( F_12 ( V_9 ) -> V_1 , F_58 ( V_102 ) -> V_71 ) )
V_102 -> V_27 = V_20 . V_42 ;
if ( F_12 ( V_9 ) -> V_1 == F_58 ( V_102 ) -> V_142 ) {
V_207 &= ~ V_209 ;
}
if ( V_207 & ( V_208 | V_209 ) ) {
F_72 ( F_20 ( V_52 ) , V_222 ) ;
goto V_223;
}
if ( ! ( V_207 & V_210 ) )
return NULL ;
if ( V_205 )
return V_52 ;
if ( V_102 -> V_213 < F_18 ( V_52 ) -> V_224 . V_225 &&
F_12 ( V_9 ) -> V_2 == F_58 ( V_102 ) -> V_142 + 1 ) {
F_39 ( V_102 ) -> V_226 = 1 ;
F_16 ( F_20 ( V_52 ) , V_227 ) ;
return NULL ;
}
V_206 = F_18 ( V_52 ) -> V_228 -> V_229 ( V_52 , V_9 , V_102 , NULL ,
V_102 , & V_211 ) ;
if ( ! V_206 )
goto V_230;
F_77 ( V_206 , V_9 ) ;
F_78 ( V_206 , V_102 ) ;
return F_79 ( V_52 , V_206 , V_102 , V_211 ) ;
V_230:
if ( ! V_231 ) {
F_39 ( V_102 ) -> V_226 = 1 ;
return NULL ;
}
V_223:
if ( ! ( V_207 & V_208 ) ) {
V_102 -> V_220 -> V_232 ( V_52 , V_9 ) ;
} else if ( V_205 ) {
F_80 ( V_52 , V_102 , true ) ;
F_81 ( V_52 ) ;
}
if ( ! V_205 ) {
F_82 ( V_52 , V_102 ) ;
F_16 ( F_20 ( V_52 ) , V_233 ) ;
}
return NULL ;
}
int F_83 ( struct V_13 * V_234 , struct V_13 * V_206 ,
struct V_8 * V_9 )
{
int V_235 = 0 ;
int V_53 = V_206 -> V_236 ;
F_84 ( V_206 , V_9 ) ;
F_85 ( F_19 ( V_206 ) , V_9 ) ;
if ( ! F_86 ( V_206 ) ) {
V_235 = F_87 ( V_206 , V_9 ) ;
if ( V_53 == V_237 && V_206 -> V_236 != V_53 )
V_234 -> V_238 ( V_234 ) ;
} else {
F_88 ( V_206 , V_9 ) ;
}
F_89 ( V_206 ) ;
F_90 ( V_206 ) ;
return V_235 ;
}
