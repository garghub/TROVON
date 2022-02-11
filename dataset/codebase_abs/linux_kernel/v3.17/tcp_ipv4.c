static T_1 F_1 ( const struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
F_4 ( V_2 ) -> V_5 ,
F_4 ( V_2 ) -> V_6 ) ;
}
int F_5 ( struct V_7 * V_8 , struct V_7 * V_9 , void * V_10 )
{
const struct V_11 * V_12 = F_6 ( V_9 ) ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_12 -> V_15 &&
( V_10 == NULL || ( V_16 &&
F_8 () - V_12 -> V_15 > 1 ) ) ) {
V_14 -> V_17 = V_12 -> V_18 + 65535 + 2 ;
if ( V_14 -> V_17 == 0 )
V_14 -> V_17 = 1 ;
V_14 -> V_19 . V_20 = V_12 -> V_21 ;
V_14 -> V_19 . V_22 = V_12 -> V_15 ;
F_9 ( V_9 ) ;
return 1 ;
}
return 0 ;
}
int F_10 ( struct V_7 * V_8 , struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
T_2 V_30 , V_31 ;
T_3 V_3 , V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
int V_37 ;
struct V_38 * V_39 ;
if ( V_25 < sizeof( struct V_26 ) )
return - V_40 ;
if ( V_27 -> V_41 != V_42 )
return - V_43 ;
V_32 = V_3 = V_27 -> V_44 . V_45 ;
V_39 = F_12 ( V_29 -> V_39 ,
F_13 ( V_8 ) ) ;
if ( V_39 && V_39 -> V_46 . V_47 ) {
if ( ! V_3 )
return - V_40 ;
V_32 = V_39 -> V_46 . V_48 ;
}
V_30 = V_29 -> V_49 ;
V_31 = V_27 -> V_50 ;
V_34 = & V_29 -> V_51 . V_52 . V_53 . V_54 ;
V_36 = F_14 ( V_34 , V_32 , V_29 -> V_55 ,
F_15 ( V_8 ) , V_8 -> V_56 ,
V_57 ,
V_30 , V_31 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
if ( V_37 == - V_58 )
F_18 ( F_19 ( V_8 ) , V_59 ) ;
return V_37 ;
}
if ( V_36 -> V_60 & ( V_61 | V_62 ) ) {
F_20 ( V_36 ) ;
return - V_58 ;
}
if ( ! V_39 || ! V_39 -> V_46 . V_47 )
V_3 = V_34 -> V_3 ;
if ( ! V_29 -> V_55 )
V_29 -> V_55 = V_34 -> V_4 ;
V_29 -> V_63 = V_29 -> V_55 ;
if ( V_14 -> V_19 . V_22 && V_29 -> V_64 != V_3 ) {
V_14 -> V_19 . V_20 = 0 ;
V_14 -> V_19 . V_22 = 0 ;
if ( F_21 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = 0 ;
}
if ( V_66 . V_67 &&
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 )
F_22 ( V_8 , & V_36 -> V_68 ) ;
V_29 -> V_69 = V_27 -> V_50 ;
V_29 -> V_64 = V_3 ;
F_23 ( V_8 ) ;
F_24 ( V_8 ) -> V_70 = 0 ;
if ( V_39 )
F_24 ( V_8 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_14 -> V_19 . V_72 = V_73 ;
F_25 ( V_8 , V_74 ) ;
V_37 = F_26 ( & V_66 , V_8 ) ;
if ( V_37 )
goto V_75;
V_36 = F_27 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_69 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
V_36 = NULL ;
goto V_75;
}
V_8 -> V_76 = V_77 ;
F_28 ( V_8 , & V_36 -> V_68 ) ;
if ( ! V_14 -> V_17 && F_21 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_64 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_78 = V_14 -> V_17 ^ V_79 ;
V_37 = F_29 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_75;
return 0 ;
V_75:
F_25 ( V_8 , V_80 ) ;
F_20 ( V_36 ) ;
V_8 -> V_81 = 0 ;
V_29 -> V_69 = 0 ;
return V_37 ;
}
void F_30 ( struct V_7 * V_8 )
{
struct V_82 * V_68 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
T_4 V_83 = F_7 ( V_8 ) -> V_84 ;
V_68 = F_31 ( V_8 , V_83 ) ;
if ( ! V_68 )
return;
if ( V_83 < F_32 ( V_68 ) && F_33 ( V_8 , V_68 ) )
V_8 -> V_85 = V_86 ;
V_83 = F_32 ( V_68 ) ;
if ( V_29 -> V_87 != V_88 &&
F_34 ( V_8 ) &&
F_24 ( V_8 ) -> V_89 > V_83 ) {
F_35 ( V_8 , V_83 ) ;
F_36 ( V_8 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_82 * V_68 = F_38 ( V_8 , 0 ) ;
if ( V_68 )
V_68 -> V_90 -> V_91 ( V_68 , V_8 , V_2 ) ;
}
void F_39 ( struct V_1 * V_92 , T_4 V_93 )
{
const struct V_94 * V_95 = ( const struct V_94 * ) V_92 -> V_96 ;
struct V_97 * V_98 = (struct V_97 * ) ( V_92 -> V_96 + ( V_95 -> V_99 << 2 ) ) ;
struct V_100 * V_101 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_40 ( V_92 ) -> type ;
const int V_102 = F_40 ( V_92 ) -> V_102 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
T_1 V_105 , V_106 ;
T_1 V_107 ;
int V_37 ;
struct V_108 * V_108 = F_41 ( V_92 -> V_109 ) ;
V_8 = F_42 ( V_108 , & V_110 , V_95 -> V_3 , V_98 -> V_5 ,
V_95 -> V_4 , V_98 -> V_6 , F_43 ( V_92 ) ) ;
if ( ! V_8 ) {
F_44 ( V_108 , V_111 ) ;
return;
}
if ( V_8 -> V_112 == V_113 ) {
F_45 ( F_46 ( V_8 ) ) ;
return;
}
F_47 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_114 && V_102 == V_115 ) )
F_48 ( V_108 , V_116 ) ;
}
if ( V_8 -> V_112 == V_80 )
goto V_117;
if ( F_49 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_48 ( V_108 , V_120 ) ;
goto V_117;
}
V_101 = F_24 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_105 = F_50 ( V_98 -> V_105 ) ;
V_104 = V_14 -> V_121 ;
V_106 = V_104 ? F_51 ( V_104 ) -> V_122 : V_14 -> V_106 ;
if ( V_8 -> V_112 != V_123 &&
! F_52 ( V_105 , V_106 , V_14 -> V_124 ) ) {
F_48 ( V_108 , V_125 ) ;
goto V_117;
}
switch ( type ) {
case V_126 :
F_37 ( V_92 , V_8 ) ;
goto V_117;
case V_127 :
goto V_117;
case V_128 :
V_37 = V_129 ;
break;
case V_114 :
if ( V_102 > V_130 )
goto V_117;
if ( V_102 == V_115 ) {
if ( V_8 -> V_112 == V_123 )
goto V_117;
V_14 -> V_84 = V_93 ;
if ( ! F_13 ( V_8 ) ) {
F_30 ( V_8 ) ;
} else {
if ( ! F_53 ( V_131 , & V_14 -> V_132 ) )
F_9 ( V_8 ) ;
}
goto V_117;
}
V_37 = V_133 [ V_102 ] . V_134 ;
if ( V_102 != V_135 && V_102 != V_136 )
break;
if ( V_105 != V_14 -> V_106 || ! V_101 -> V_137 ||
! V_101 -> V_138 || V_104 )
break;
if ( F_13 ( V_8 ) )
break;
V_101 -> V_138 -- ;
F_24 ( V_8 ) -> V_139 = ( V_14 -> V_140 ? F_54 ( V_14 ) :
V_141 ) << V_101 -> V_138 ;
F_55 ( V_8 ) ;
V_2 = F_56 ( V_8 ) ;
F_57 ( ! V_2 ) ;
V_107 = V_101 -> V_139 - F_58 ( V_101 -> V_139 ,
V_142 - F_59 ( V_2 ) -> V_143 ) ;
if ( V_107 ) {
F_60 ( V_8 , V_144 ,
V_107 , V_145 ) ;
} else {
F_61 ( V_8 ) ;
}
break;
case V_146 :
V_37 = V_147 ;
break;
default:
goto V_117;
}
switch ( V_8 -> V_112 ) {
struct V_103 * V_148 , * * V_149 ;
case V_123 :
if ( F_13 ( V_8 ) )
goto V_117;
V_148 = F_62 ( V_8 , & V_149 , V_98 -> V_5 ,
V_95 -> V_3 , V_95 -> V_4 ) ;
if ( ! V_148 )
goto V_117;
F_63 ( V_148 -> V_8 ) ;
if ( V_105 != F_51 ( V_148 ) -> V_122 ) {
F_48 ( V_108 , V_125 ) ;
goto V_117;
}
F_64 ( V_8 , V_148 , V_149 ) ;
F_48 ( F_19 ( V_8 ) , V_150 ) ;
goto V_117;
case V_74 :
case V_151 :
if ( V_104 && V_104 -> V_8 == NULL )
break;
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
F_65 ( V_8 ) ;
} else {
V_8 -> V_85 = V_37 ;
}
goto V_117;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_154 ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
} else {
V_8 -> V_85 = V_37 ;
}
V_117:
F_66 ( V_8 ) ;
F_67 ( V_8 ) ;
}
void F_68 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
if ( V_2 -> V_155 == V_156 ) {
V_98 -> V_157 = ~ F_69 ( V_2 -> V_158 , V_4 , V_3 , 0 ) ;
V_2 -> V_159 = F_70 ( V_2 ) - V_2 -> V_160 ;
V_2 -> V_161 = F_71 ( struct V_97 , V_157 ) ;
} else {
V_98 -> V_157 = F_69 ( V_2 -> V_158 , V_4 , V_3 ,
F_72 ( V_98 ,
V_98 -> V_162 << 2 ,
V_2 -> V_163 ) ) ;
}
}
void F_73 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_68 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
static void F_74 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
#ifdef F_75
T_3 V_46 [ ( V_164 >> 2 ) ] ;
#endif
} V_165 ;
struct V_166 V_167 ;
#ifdef F_75
struct V_168 * V_169 ;
const T_5 * V_170 = NULL ;
unsigned char V_171 [ 16 ] ;
int V_172 ;
struct V_7 * V_173 = NULL ;
#endif
struct V_108 * V_108 ;
if ( V_98 -> V_174 )
return;
if ( F_76 ( V_2 ) -> V_175 != V_176 )
return;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_98 . V_5 = V_98 -> V_6 ;
V_165 . V_98 . V_6 = V_98 -> V_5 ;
V_165 . V_98 . V_162 = sizeof( struct V_97 ) / 4 ;
V_165 . V_98 . V_174 = 1 ;
if ( V_98 -> V_177 ) {
V_165 . V_98 . V_105 = V_98 -> V_178 ;
} else {
V_165 . V_98 . V_177 = 1 ;
V_165 . V_98 . V_178 = F_77 ( F_50 ( V_98 -> V_105 ) + V_98 -> V_179 + V_98 -> V_180 +
V_2 -> V_158 - ( V_98 -> V_162 << 2 ) ) ;
}
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_181 [ 0 ] . V_182 = ( unsigned char * ) & V_165 ;
V_167 . V_181 [ 0 ] . V_183 = sizeof( V_165 . V_98 ) ;
#ifdef F_75
V_170 = F_78 ( V_98 ) ;
if ( ! V_8 && V_170 ) {
V_173 = F_79 ( F_41 ( F_80 ( V_2 ) -> V_109 ) ,
& V_110 , F_3 ( V_2 ) -> V_4 ,
V_98 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_81 ( V_98 -> V_6 ) , F_43 ( V_2 ) ) ;
if ( ! V_173 )
return;
F_82 () ;
V_169 = F_83 ( V_173 , (union V_184 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_169 )
goto V_185;
V_172 = F_84 ( V_171 , V_169 , NULL , NULL , V_2 ) ;
if ( V_172 || memcmp ( V_170 , V_171 , 16 ) != 0 )
goto V_185;
} else {
V_169 = V_8 ? F_83 ( V_8 , (union V_184 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_169 ) {
V_165 . V_46 [ 0 ] = F_77 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_164 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
F_85 ( ( T_5 * ) & V_165 . V_46 [ 1 ] ,
V_169 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 . V_98 ) ;
}
#endif
V_167 . V_163 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_167 . V_181 [ 0 ] . V_183 , V_57 , 0 ) ;
V_167 . V_189 = F_71 ( struct V_97 , V_157 ) / 2 ;
V_167 . V_190 = ( V_8 && F_11 ( V_8 ) -> V_191 ) ? V_192 : 0 ;
if ( V_8 )
V_167 . V_193 = V_8 -> V_56 ;
V_108 = F_41 ( F_80 ( V_2 ) -> V_109 ) ;
V_167 . V_194 = F_3 ( V_2 ) -> V_194 ;
F_87 ( V_108 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 , V_167 . V_181 [ 0 ] . V_183 ) ;
F_88 ( V_108 , V_195 ) ;
F_88 ( V_108 , V_196 ) ;
#ifdef F_75
V_185:
if ( V_173 ) {
F_89 () ;
F_67 ( V_173 ) ;
}
#endif
}
static void F_90 ( struct V_1 * V_2 , T_4 V_105 , T_4 V_177 ,
T_4 V_197 , T_4 V_198 , T_4 V_199 , int V_200 ,
struct V_168 * V_169 ,
int V_201 , T_6 V_194 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
T_3 V_46 [ ( V_202 >> 2 )
#ifdef F_75
+ ( V_164 >> 2 )
#endif
] ;
} V_165 ;
struct V_166 V_167 ;
struct V_108 * V_108 = F_41 ( F_80 ( V_2 ) -> V_109 ) ;
memset ( & V_165 . V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_181 [ 0 ] . V_182 = ( unsigned char * ) & V_165 ;
V_167 . V_181 [ 0 ] . V_183 = sizeof( V_165 . V_98 ) ;
if ( V_199 ) {
V_165 . V_46 [ 0 ] = F_77 ( ( V_186 << 24 ) | ( V_186 << 16 ) |
( V_203 << 8 ) |
V_204 ) ;
V_165 . V_46 [ 1 ] = F_77 ( V_198 ) ;
V_165 . V_46 [ 2 ] = F_77 ( V_199 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_202 ;
}
V_165 . V_98 . V_5 = V_98 -> V_6 ;
V_165 . V_98 . V_6 = V_98 -> V_5 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
V_165 . V_98 . V_105 = F_77 ( V_105 ) ;
V_165 . V_98 . V_178 = F_77 ( V_177 ) ;
V_165 . V_98 . V_177 = 1 ;
V_165 . V_98 . V_205 = F_91 ( V_197 ) ;
#ifdef F_75
if ( V_169 ) {
int V_206 = ( V_199 ) ? 3 : 0 ;
V_165 . V_46 [ V_206 ++ ] = F_77 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_164 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
F_85 ( ( T_5 * ) & V_165 . V_46 [ V_206 ] ,
V_169 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 . V_98 ) ;
}
#endif
V_167 . V_190 = V_201 ;
V_167 . V_163 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_167 . V_181 [ 0 ] . V_183 , V_57 , 0 ) ;
V_167 . V_189 = F_71 ( struct V_97 , V_157 ) / 2 ;
if ( V_200 )
V_167 . V_193 = V_200 ;
V_167 . V_194 = V_194 ;
F_87 ( V_108 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 , V_167 . V_181 [ 0 ] . V_183 ) ;
F_88 ( V_108 , V_195 ) ;
}
static void F_92 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_207 * V_208 = F_46 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_90 ( V_2 , V_12 -> V_18 , V_12 -> V_209 ,
V_12 -> V_210 >> V_208 -> V_211 ,
V_142 + V_12 -> V_212 ,
V_12 -> V_21 ,
V_208 -> V_213 ,
F_93 ( V_12 ) ,
V_208 -> V_214 ? V_192 : 0 ,
V_208 -> V_215
) ;
F_45 ( V_208 ) ;
}
static void F_94 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_148 )
{
F_90 ( V_2 , ( V_8 -> V_112 == V_123 ) ?
F_51 ( V_148 ) -> V_122 + 1 : F_7 ( V_8 ) -> V_124 ,
F_51 ( V_148 ) -> V_216 , V_148 -> V_217 ,
V_142 ,
V_148 -> V_20 ,
0 ,
F_83 ( V_8 , (union V_184 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_95 ( V_148 ) -> V_218 ? V_192 : 0 ,
F_3 ( V_2 ) -> V_194 ) ;
}
static int F_96 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_219 * V_52 ,
struct V_103 * V_148 ,
T_7 V_220 ,
struct V_221 * V_222 )
{
const struct V_223 * V_224 = F_95 ( V_148 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_97 ( V_8 , & V_34 , V_148 ) ) == NULL )
return - 1 ;
V_2 = F_98 ( V_8 , V_68 , V_148 , V_222 ) ;
if ( V_2 ) {
F_68 ( V_2 , V_224 -> V_225 , V_224 -> V_226 ) ;
F_99 ( V_2 , V_220 ) ;
V_37 = F_100 ( V_2 , V_8 , V_224 -> V_225 ,
V_224 -> V_226 ,
V_224 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
}
return V_37 ;
}
static void F_102 ( struct V_103 * V_148 )
{
F_103 ( F_95 ( V_148 ) -> V_46 ) ;
}
bool F_104 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_227 )
{
const char * V_228 = L_1 ;
bool V_229 = false ;
struct V_230 * V_231 ;
#ifdef F_105
if ( V_232 ) {
V_228 = L_2 ;
V_229 = true ;
F_48 ( F_19 ( V_8 ) , V_233 ) ;
} else
#endif
F_48 ( F_19 ( V_8 ) , V_234 ) ;
V_231 = F_24 ( V_8 ) -> V_235 . V_236 ;
if ( ! V_231 -> V_237 && V_232 != 2 ) {
V_231 -> V_237 = 1 ;
F_106 ( L_3 ,
V_227 , F_81 ( F_4 ( V_2 ) -> V_5 ) , V_228 ) ;
}
return V_229 ;
}
static struct V_38 * F_107 ( struct V_1 * V_2 )
{
const struct V_238 * V_46 = & ( F_108 ( V_2 ) -> V_46 ) ;
struct V_38 * V_239 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_240 = sizeof( * V_239 ) + V_46 -> V_71 ;
V_239 = F_109 ( V_240 , V_241 ) ;
if ( V_239 ) {
if ( F_110 ( & V_239 -> V_46 , V_2 ) ) {
F_103 ( V_239 ) ;
V_239 = NULL ;
}
}
}
return V_239 ;
}
struct V_168 * F_83 ( struct V_7 * V_8 ,
const union V_184 * V_242 ,
int V_243 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_168 * V_169 ;
unsigned int V_244 = sizeof( struct V_245 ) ;
struct V_246 * V_247 ;
V_247 = F_111 ( V_14 -> V_248 ,
F_13 ( V_8 ) ||
F_112 ( & V_8 -> V_249 . V_250 ) ) ;
if ( ! V_247 )
return NULL ;
#if F_113 ( V_251 )
if ( V_243 == V_252 )
V_244 = sizeof( struct V_253 ) ;
#endif
F_114 (key, &md5sig->head, node) {
if ( V_169 -> V_243 != V_243 )
continue;
if ( ! memcmp ( & V_169 -> V_242 , V_242 , V_244 ) )
return V_169 ;
}
return NULL ;
}
struct V_168 * F_115 ( struct V_7 * V_8 ,
struct V_7 * V_254 )
{
union V_184 * V_242 ;
V_242 = (union V_184 * ) & F_11 ( V_254 ) -> V_64 ;
return F_83 ( V_8 , V_242 , V_42 ) ;
}
static struct V_168 * F_116 ( struct V_7 * V_8 ,
struct V_103 * V_148 )
{
union V_184 * V_242 ;
V_242 = (union V_184 * ) & F_95 ( V_148 ) -> V_226 ;
return F_83 ( V_8 , V_242 , V_42 ) ;
}
int F_117 ( struct V_7 * V_8 , const union V_184 * V_242 ,
int V_243 , const T_6 * V_255 , T_6 V_256 , T_8 V_257 )
{
struct V_168 * V_169 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_246 * V_247 ;
V_169 = F_83 ( V_8 , V_242 , V_243 ) ;
if ( V_169 ) {
memcpy ( V_169 -> V_169 , V_255 , V_256 ) ;
V_169 -> V_258 = V_256 ;
return 0 ;
}
V_247 = F_12 ( V_14 -> V_248 ,
F_13 ( V_8 ) ) ;
if ( ! V_247 ) {
V_247 = F_109 ( sizeof( * V_247 ) , V_257 ) ;
if ( ! V_247 )
return - V_259 ;
F_118 ( V_8 , V_260 ) ;
F_119 ( & V_247 -> V_160 ) ;
F_120 ( V_14 -> V_248 , V_247 ) ;
}
V_169 = F_121 ( V_8 , sizeof( * V_169 ) , V_257 ) ;
if ( ! V_169 )
return - V_259 ;
if ( ! F_122 () ) {
F_123 ( V_8 , V_169 , sizeof( * V_169 ) ) ;
return - V_259 ;
}
memcpy ( V_169 -> V_169 , V_255 , V_256 ) ;
V_169 -> V_258 = V_256 ;
V_169 -> V_243 = V_243 ;
memcpy ( & V_169 -> V_242 , V_242 ,
( V_243 == V_252 ) ? sizeof( struct V_253 ) :
sizeof( struct V_245 ) ) ;
F_124 ( & V_169 -> V_261 , & V_247 -> V_160 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_8 , const union V_184 * V_242 , int V_243 )
{
struct V_168 * V_169 ;
V_169 = F_83 ( V_8 , V_242 , V_243 ) ;
if ( ! V_169 )
return - V_262 ;
F_126 ( & V_169 -> V_261 ) ;
F_127 ( sizeof( * V_169 ) , & V_8 -> V_263 ) ;
F_128 ( V_169 , V_264 ) ;
return 0 ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_168 * V_169 ;
struct V_265 * V_266 ;
struct V_246 * V_247 ;
V_247 = F_12 ( V_14 -> V_248 , 1 ) ;
F_130 (key, n, &md5sig->head, node) {
F_126 ( & V_169 -> V_261 ) ;
F_127 ( sizeof( * V_169 ) , & V_8 -> V_263 ) ;
F_128 ( V_169 , V_264 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , char T_9 * V_267 ,
int V_71 )
{
struct V_268 V_269 ;
struct V_26 * sin = (struct V_26 * ) & V_269 . V_270 ;
if ( V_71 < sizeof( V_269 ) )
return - V_40 ;
if ( F_132 ( & V_269 , V_267 , sizeof( V_269 ) ) )
return - V_271 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_269 . V_272 )
return F_125 ( V_8 , (union V_184 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_269 . V_272 > V_273 )
return - V_40 ;
return F_117 ( V_8 , (union V_184 * ) & sin -> V_44 . V_45 ,
V_42 , V_269 . V_274 , V_269 . V_272 ,
V_275 ) ;
}
static int F_133 ( struct V_276 * V_277 ,
T_3 V_3 , T_3 V_4 , int V_278 )
{
struct V_279 * V_280 ;
struct V_281 V_282 ;
V_280 = & V_277 -> V_283 . V_54 ;
V_280 -> V_4 = V_4 ;
V_280 -> V_3 = V_3 ;
V_280 -> V_284 = 0 ;
V_280 -> V_285 = V_57 ;
V_280 -> V_158 = F_134 ( V_278 ) ;
F_135 ( & V_282 , V_280 , sizeof( * V_280 ) ) ;
return F_136 ( & V_277 -> V_286 , & V_282 , sizeof( * V_280 ) ) ;
}
static int F_85 ( char * V_287 , const struct V_168 * V_169 ,
T_3 V_3 , T_3 V_4 , const struct V_97 * V_98 )
{
struct V_276 * V_277 ;
struct V_288 * V_289 ;
V_277 = F_137 () ;
if ( ! V_277 )
goto V_290;
V_289 = & V_277 -> V_286 ;
if ( F_138 ( V_289 ) )
goto V_291;
if ( F_133 ( V_277 , V_3 , V_4 , V_98 -> V_162 << 2 ) )
goto V_291;
if ( F_139 ( V_277 , V_98 ) )
goto V_291;
if ( F_140 ( V_277 , V_169 ) )
goto V_291;
if ( F_141 ( V_289 , V_287 ) )
goto V_291;
F_142 () ;
return 0 ;
V_291:
F_142 () ;
V_290:
memset ( V_287 , 0 , 16 ) ;
return 1 ;
}
int F_84 ( char * V_287 , struct V_168 * V_169 ,
const struct V_7 * V_8 , const struct V_103 * V_148 ,
const struct V_1 * V_2 )
{
struct V_276 * V_277 ;
struct V_288 * V_289 ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_148 ) {
V_4 = F_95 ( V_148 ) -> V_225 ;
V_3 = F_95 ( V_148 ) -> V_226 ;
} else {
const struct V_94 * V_95 = F_3 ( V_2 ) ;
V_4 = V_95 -> V_4 ;
V_3 = V_95 -> V_3 ;
}
V_277 = F_137 () ;
if ( ! V_277 )
goto V_290;
V_289 = & V_277 -> V_286 ;
if ( F_138 ( V_289 ) )
goto V_291;
if ( F_133 ( V_277 , V_3 , V_4 , V_2 -> V_158 ) )
goto V_291;
if ( F_139 ( V_277 , V_98 ) )
goto V_291;
if ( F_143 ( V_277 , V_2 , V_98 -> V_162 << 2 ) )
goto V_291;
if ( F_140 ( V_277 , V_169 ) )
goto V_291;
if ( F_141 ( V_289 , V_287 ) )
goto V_291;
F_142 () ;
return 0 ;
V_291:
F_142 () ;
V_290:
memset ( V_287 , 0 , 16 ) ;
return 1 ;
}
static bool F_144 ( struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
const T_5 * V_170 = NULL ;
struct V_168 * V_292 ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
int V_172 ;
unsigned char V_171 [ 16 ] ;
V_292 = F_83 ( V_8 , (union V_184 * ) & V_95 -> V_4 ,
V_42 ) ;
V_170 = F_78 ( V_98 ) ;
if ( ! V_292 && ! V_170 )
return false ;
if ( V_292 && ! V_170 ) {
F_48 ( F_19 ( V_8 ) , V_293 ) ;
return true ;
}
if ( ! V_292 && V_170 ) {
F_48 ( F_19 ( V_8 ) , V_294 ) ;
return true ;
}
V_172 = F_84 ( V_171 ,
V_292 ,
NULL , NULL , V_2 ) ;
if ( V_172 || memcmp ( V_170 , V_171 , 16 ) != 0 ) {
F_145 ( L_4 ,
& V_95 -> V_4 , F_81 ( V_98 -> V_6 ) ,
& V_95 -> V_3 , F_81 ( V_98 -> V_5 ) ,
V_172 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
static bool F_146 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
bool V_295 ;
F_82 () ;
V_295 = F_144 ( V_8 , V_2 ) ;
F_89 () ;
return V_295 ;
}
static void F_147 ( struct V_103 * V_148 , struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_223 * V_224 = F_95 ( V_148 ) ;
V_224 -> V_225 = F_3 ( V_2 ) -> V_3 ;
V_224 -> V_226 = F_3 ( V_2 ) -> V_4 ;
V_224 -> V_218 = F_11 ( V_8 ) -> V_191 ;
V_224 -> V_46 = F_107 ( V_2 ) ;
}
static struct V_82 * F_148 ( struct V_7 * V_8 , struct V_219 * V_52 ,
const struct V_103 * V_148 ,
bool * V_296 )
{
struct V_82 * V_68 = F_97 ( V_8 , & V_52 -> V_53 . V_54 , V_148 ) ;
if ( V_296 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_95 ( V_148 ) -> V_226 )
* V_296 = true ;
else
* V_296 = false ;
}
return V_68 ;
}
int F_149 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_76 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_297;
return F_150 ( & V_298 ,
& V_299 , V_8 , V_2 ) ;
V_297:
F_48 ( F_19 ( V_8 ) , V_150 ) ;
return 0 ;
}
struct V_7 * F_151 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_148 ,
struct V_82 * V_68 )
{
struct V_223 * V_224 ;
struct V_28 * V_300 ;
struct V_13 * V_301 ;
struct V_7 * V_302 ;
#ifdef F_75
struct V_168 * V_169 ;
#endif
struct V_38 * V_39 ;
if ( F_152 ( V_8 ) )
goto V_303;
V_302 = F_153 ( V_8 , V_148 , V_2 ) ;
if ( ! V_302 )
goto V_304;
V_302 -> V_76 = V_77 ;
F_154 ( V_302 , V_2 ) ;
V_301 = F_7 ( V_302 ) ;
V_300 = F_11 ( V_302 ) ;
V_224 = F_95 ( V_148 ) ;
V_300 -> V_64 = V_224 -> V_226 ;
V_300 -> V_63 = V_224 -> V_225 ;
V_300 -> V_55 = V_224 -> V_225 ;
V_39 = V_224 -> V_46 ;
F_120 ( V_300 -> V_39 , V_39 ) ;
V_224 -> V_46 = NULL ;
V_300 -> V_305 = F_43 ( V_2 ) ;
V_300 -> V_306 = F_3 ( V_2 ) -> V_118 ;
V_300 -> V_307 = F_3 ( V_2 ) -> V_194 ;
F_24 ( V_302 ) -> V_70 = 0 ;
F_23 ( V_302 ) ;
if ( V_39 )
F_24 ( V_302 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_300 -> V_78 = V_301 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_155 ( V_8 , V_302 , V_148 ) ;
if ( ! V_68 )
goto V_308;
} else {
}
F_28 ( V_302 , V_68 ) ;
F_35 ( V_302 , F_32 ( V_68 ) ) ;
V_301 -> V_309 = F_156 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_310 &&
F_7 ( V_8 ) -> V_19 . V_310 < V_301 -> V_309 )
V_301 -> V_309 = F_7 ( V_8 ) -> V_19 . V_310 ;
F_157 ( V_302 ) ;
#ifdef F_75
V_169 = F_83 ( V_8 , (union V_184 * ) & V_300 -> V_64 ,
V_42 ) ;
if ( V_169 != NULL ) {
F_117 ( V_302 , (union V_184 * ) & V_300 -> V_64 ,
V_42 , V_169 -> V_169 , V_169 -> V_258 , V_241 ) ;
F_118 ( V_302 , V_260 ) ;
}
#endif
if ( F_158 ( V_8 , V_302 ) < 0 )
goto V_308;
F_159 ( V_302 , NULL ) ;
return V_302 ;
V_303:
F_48 ( F_19 ( V_8 ) , V_311 ) ;
V_304:
F_160 ( V_68 ) ;
exit:
F_48 ( F_19 ( V_8 ) , V_150 ) ;
return NULL ;
V_308:
F_161 ( V_302 ) ;
F_65 ( V_302 ) ;
goto exit;
}
static struct V_7 * F_162 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_7 * V_312 ;
struct V_103 * * V_149 ;
struct V_103 * V_148 = F_62 ( V_8 , & V_149 , V_98 -> V_6 ,
V_95 -> V_4 , V_95 -> V_3 ) ;
if ( V_148 )
return F_163 ( V_8 , V_2 , V_148 , V_149 , false ) ;
V_312 = F_164 ( F_19 ( V_8 ) , & V_110 , V_95 -> V_4 ,
V_98 -> V_6 , V_95 -> V_3 , V_98 -> V_5 , F_43 ( V_2 ) ) ;
if ( V_312 ) {
if ( V_312 -> V_112 != V_113 ) {
F_47 ( V_312 ) ;
return V_312 ;
}
F_45 ( F_46 ( V_312 ) ) ;
return NULL ;
}
#ifdef F_105
if ( ! V_98 -> V_179 )
V_8 = F_165 ( V_8 , V_2 , & ( F_108 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
int F_166 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_313 ;
if ( V_8 -> V_112 == V_314 ) {
struct V_82 * V_68 = V_8 -> V_315 ;
F_167 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_316 != V_2 -> V_317 ||
V_68 -> V_90 -> V_157 ( V_68 , 0 ) == NULL ) {
F_160 ( V_68 ) ;
V_8 -> V_315 = NULL ;
}
}
F_168 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_158 ) ;
return 0 ;
}
if ( V_2 -> V_158 < F_169 ( V_2 ) || F_170 ( V_2 ) )
goto V_318;
if ( V_8 -> V_112 == V_123 ) {
struct V_7 * V_312 = F_162 ( V_8 , V_2 ) ;
if ( ! V_312 )
goto V_319;
if ( V_312 != V_8 ) {
F_167 ( V_312 , V_2 ) ;
if ( F_171 ( V_8 , V_312 , V_2 ) ) {
V_313 = V_312 ;
goto V_320;
}
return 0 ;
}
} else
F_167 ( V_8 , V_2 ) ;
if ( F_172 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_158 ) ) {
V_313 = V_8 ;
goto V_320;
}
return 0 ;
V_320:
F_74 ( V_313 , V_2 ) ;
V_319:
F_173 ( V_2 ) ;
return 0 ;
V_318:
F_88 ( F_19 ( V_8 ) , V_321 ) ;
F_88 ( F_19 ( V_8 ) , V_322 ) ;
goto V_319;
}
void F_174 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
if ( V_2 -> V_323 != V_324 )
return;
if ( ! F_175 ( V_2 , F_176 ( V_2 ) + sizeof( struct V_97 ) ) )
return;
V_95 = F_3 ( V_2 ) ;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_162 < sizeof( struct V_97 ) / 4 )
return;
V_8 = F_177 ( F_41 ( V_2 -> V_109 ) , & V_110 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , F_81 ( V_98 -> V_5 ) ,
V_2 -> V_317 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_325 = V_326 ;
if ( V_8 -> V_112 != V_113 ) {
struct V_82 * V_68 = V_8 -> V_315 ;
if ( V_68 )
V_68 = F_178 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_316 == V_2 -> V_317 )
F_179 ( V_2 , V_68 ) ;
}
}
}
bool F_180 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_327 || ! V_14 -> V_328 . V_329 )
return false ;
if ( V_2 -> V_158 <= F_169 ( V_2 ) &&
F_181 ( & V_14 -> V_328 . V_330 ) == 0 )
return false ;
F_182 ( V_2 ) ;
F_183 ( & V_14 -> V_328 . V_330 , V_2 ) ;
V_14 -> V_328 . V_331 += V_2 -> V_332 ;
if ( V_14 -> V_328 . V_331 > V_8 -> V_333 ) {
struct V_1 * V_334 ;
F_57 ( F_13 ( V_8 ) ) ;
while ( ( V_334 = F_184 ( & V_14 -> V_328 . V_330 ) ) != NULL ) {
F_185 ( V_8 , V_334 ) ;
F_48 ( F_19 ( V_8 ) ,
V_335 ) ;
}
V_14 -> V_328 . V_331 = 0 ;
} else if ( F_181 ( & V_14 -> V_328 . V_330 ) == 1 ) {
F_186 ( F_187 ( V_8 ) ,
V_336 | V_337 | V_338 ) ;
if ( ! F_188 ( V_8 ) )
F_60 ( V_8 , V_339 ,
( 3 * F_189 ( V_8 ) ) / 4 ,
V_145 ) ;
}
return true ;
}
int F_190 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
int V_295 ;
struct V_108 * V_108 = F_41 ( V_2 -> V_109 ) ;
if ( V_2 -> V_323 != V_324 )
goto V_340;
F_88 ( V_108 , V_341 ) ;
if ( ! F_175 ( V_2 , sizeof( struct V_97 ) ) )
goto V_340;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_162 < sizeof( struct V_97 ) / 4 )
goto V_342;
if ( ! F_175 ( V_2 , V_98 -> V_162 * 4 ) )
goto V_340;
if ( F_191 ( V_2 , V_57 , V_343 ) )
goto V_344;
V_98 = F_4 ( V_2 ) ;
V_95 = F_3 ( V_2 ) ;
F_59 ( V_2 ) -> V_105 = F_50 ( V_98 -> V_105 ) ;
F_59 ( V_2 ) -> V_345 = ( F_59 ( V_2 ) -> V_105 + V_98 -> V_179 + V_98 -> V_180 +
V_2 -> V_158 - V_98 -> V_162 * 4 ) ;
F_59 ( V_2 ) -> V_178 = F_50 ( V_98 -> V_178 ) ;
F_59 ( V_2 ) -> V_143 = 0 ;
F_59 ( V_2 ) -> V_346 = F_192 ( V_95 ) ;
F_59 ( V_2 ) -> V_347 = 0 ;
V_8 = F_193 ( & V_110 , V_2 , V_98 -> V_6 , V_98 -> V_5 ) ;
if ( ! V_8 )
goto V_348;
V_349:
if ( V_8 -> V_112 == V_113 )
goto V_350;
if ( F_49 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_48 ( V_108 , V_120 ) ;
goto V_351;
}
if ( ! F_194 ( V_8 , V_352 , V_2 ) )
goto V_351;
#ifdef F_75
if ( F_146 ( V_8 , V_2 ) )
goto V_351;
#endif
F_195 ( V_2 ) ;
if ( F_196 ( V_8 , V_2 ) )
goto V_351;
F_197 ( V_8 , V_2 ) ;
V_2 -> V_109 = NULL ;
F_198 ( V_8 ) ;
V_295 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_199
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_328 . V_353 && V_14 -> V_328 . V_354 )
V_14 -> V_328 . V_353 = F_200 () ;
if ( V_14 -> V_328 . V_353 )
V_295 = F_166 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_180 ( V_8 , V_2 ) )
V_295 = F_166 ( V_8 , V_2 ) ;
}
} else if ( F_49 ( F_201 ( V_8 , V_2 ,
V_8 -> V_333 + V_8 -> V_355 ) ) ) {
F_66 ( V_8 ) ;
F_48 ( V_108 , V_356 ) ;
goto V_351;
}
F_66 ( V_8 ) ;
F_67 ( V_8 ) ;
return V_295 ;
V_348:
if ( ! F_194 ( NULL , V_352 , V_2 ) )
goto V_340;
if ( V_2 -> V_158 < ( V_98 -> V_162 << 2 ) || F_170 ( V_2 ) ) {
V_344:
F_88 ( V_108 , V_321 ) ;
V_342:
F_88 ( V_108 , V_322 ) ;
} else {
F_74 ( NULL , V_2 ) ;
}
V_340:
F_173 ( V_2 ) ;
return 0 ;
V_351:
F_67 ( V_8 ) ;
goto V_340;
V_350:
if ( ! F_194 ( NULL , V_352 , V_2 ) ) {
F_45 ( F_46 ( V_8 ) ) ;
goto V_340;
}
if ( V_2 -> V_158 < ( V_98 -> V_162 << 2 ) ) {
F_45 ( F_46 ( V_8 ) ) ;
goto V_342;
}
if ( F_170 ( V_2 ) ) {
F_45 ( F_46 ( V_8 ) ) ;
goto V_344;
}
switch ( F_202 ( F_46 ( V_8 ) , V_2 , V_98 ) ) {
case V_357 : {
struct V_7 * V_358 = F_203 ( F_41 ( V_2 -> V_109 ) ,
& V_110 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , V_98 -> V_5 ,
F_43 ( V_2 ) ) ;
if ( V_358 ) {
F_204 ( F_46 ( V_8 ) , & V_66 ) ;
F_45 ( F_46 ( V_8 ) ) ;
V_8 = V_358 ;
goto V_349;
}
}
case V_359 :
F_92 ( V_8 , V_2 ) ;
break;
case V_360 :
goto V_348;
case V_361 : ;
}
goto V_340;
}
void F_154 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_80 ( V_2 ) ;
F_205 ( V_68 ) ;
V_8 -> V_315 = V_68 ;
F_11 ( V_8 ) -> V_316 = V_2 -> V_317 ;
}
static int F_206 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = F_24 ( V_8 ) ;
F_207 ( V_8 ) ;
V_101 -> V_362 = & V_363 ;
#ifdef F_75
F_7 ( V_8 ) -> V_364 = & V_365 ;
#endif
return 0 ;
}
void F_208 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_209 ( V_8 ) ;
F_210 ( V_8 ) ;
F_211 ( V_8 ) ;
F_212 ( & V_14 -> V_366 ) ;
#ifdef F_75
if ( V_14 -> V_248 ) {
F_129 ( V_8 ) ;
F_128 ( V_14 -> V_248 , V_264 ) ;
V_14 -> V_248 = NULL ;
}
#endif
#ifdef F_199
F_212 ( & V_8 -> V_367 ) ;
#endif
F_212 ( & V_14 -> V_328 . V_330 ) ;
if ( F_24 ( V_8 ) -> V_368 )
F_213 ( V_8 ) ;
F_57 ( V_14 -> V_121 != NULL ) ;
F_214 ( V_14 ) ;
F_215 ( V_8 ) ;
F_216 ( V_8 ) ;
}
static void * F_217 ( struct V_369 * V_105 , void * V_370 )
{
struct V_100 * V_101 ;
struct V_371 * V_261 ;
struct V_7 * V_8 = V_370 ;
struct V_372 * V_373 ;
struct V_374 * V_375 = V_105 -> V_376 ;
struct V_108 * V_108 = F_218 ( V_105 ) ;
if ( ! V_8 ) {
V_373 = & V_110 . V_377 [ V_375 -> V_378 ] ;
F_219 ( & V_373 -> V_379 ) ;
V_8 = F_220 ( & V_373 -> V_160 ) ;
V_375 -> V_206 = 0 ;
goto V_380;
}
V_373 = & V_110 . V_377 [ V_375 -> V_378 ] ;
++ V_375 -> V_381 ;
++ V_375 -> V_206 ;
if ( V_375 -> V_382 == V_383 ) {
struct V_103 * V_148 = V_370 ;
V_101 = F_24 ( V_375 -> V_384 ) ;
V_148 = V_148 -> V_385 ;
while ( 1 ) {
while ( V_148 ) {
if ( V_148 -> V_386 -> V_243 == V_375 -> V_243 ) {
V_370 = V_148 ;
goto V_117;
}
V_148 = V_148 -> V_385 ;
}
if ( ++ V_375 -> V_387 >= V_101 -> V_235 . V_236 -> V_388 )
break;
V_389:
V_148 = V_101 -> V_235 . V_236 -> V_390 [ V_375 -> V_387 ] ;
}
V_8 = F_221 ( V_375 -> V_384 ) ;
V_375 -> V_382 = V_391 ;
F_222 ( & V_101 -> V_235 . V_392 ) ;
} else {
V_101 = F_24 ( V_8 ) ;
F_223 ( & V_101 -> V_235 . V_392 ) ;
if ( F_224 ( & V_101 -> V_235 ) )
goto V_393;
F_222 ( & V_101 -> V_235 . V_392 ) ;
V_8 = F_221 ( V_8 ) ;
}
V_380:
F_225 (sk, node) {
if ( ! F_226 ( F_19 ( V_8 ) , V_108 ) )
continue;
if ( V_8 -> V_394 == V_375 -> V_243 ) {
V_370 = V_8 ;
goto V_117;
}
V_101 = F_24 ( V_8 ) ;
F_223 ( & V_101 -> V_235 . V_392 ) ;
if ( F_224 ( & V_101 -> V_235 ) ) {
V_393:
V_375 -> V_395 = F_227 ( V_8 ) ;
V_375 -> V_384 = V_8 ;
V_375 -> V_382 = V_383 ;
V_375 -> V_387 = 0 ;
goto V_389;
}
F_222 ( & V_101 -> V_235 . V_392 ) ;
}
F_228 ( & V_373 -> V_379 ) ;
V_375 -> V_206 = 0 ;
if ( ++ V_375 -> V_378 < V_396 ) {
V_373 = & V_110 . V_377 [ V_375 -> V_378 ] ;
F_219 ( & V_373 -> V_379 ) ;
V_8 = F_220 ( & V_373 -> V_160 ) ;
goto V_380;
}
V_370 = NULL ;
V_117:
return V_370 ;
}
static void * F_229 ( struct V_369 * V_105 , T_10 * V_397 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
void * V_398 ;
V_375 -> V_378 = 0 ;
V_375 -> V_206 = 0 ;
V_398 = F_217 ( V_105 , NULL ) ;
while ( V_398 && * V_397 ) {
V_398 = F_217 ( V_105 , V_398 ) ;
-- * V_397 ;
}
return V_398 ;
}
static inline bool F_230 ( const struct V_374 * V_375 )
{
return F_231 ( & V_110 . V_399 [ V_375 -> V_378 ] . V_400 ) ;
}
static void * F_232 ( struct V_369 * V_105 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
struct V_108 * V_108 = F_218 ( V_105 ) ;
void * V_398 = NULL ;
V_375 -> V_206 = 0 ;
for (; V_375 -> V_378 <= V_110 . V_401 ; ++ V_375 -> V_378 ) {
struct V_7 * V_8 ;
struct V_371 * V_261 ;
T_11 * V_379 = F_233 ( & V_110 , V_375 -> V_378 ) ;
if ( F_230 ( V_375 ) )
continue;
F_219 ( V_379 ) ;
F_234 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_394 != V_375 -> V_243 ||
! F_226 ( F_19 ( V_8 ) , V_108 ) ) {
continue;
}
V_398 = V_8 ;
goto V_117;
}
F_228 ( V_379 ) ;
}
V_117:
return V_398 ;
}
static void * F_235 ( struct V_369 * V_105 , void * V_370 )
{
struct V_7 * V_8 = V_370 ;
struct V_371 * V_261 ;
struct V_374 * V_375 = V_105 -> V_376 ;
struct V_108 * V_108 = F_218 ( V_105 ) ;
++ V_375 -> V_381 ;
++ V_375 -> V_206 ;
V_8 = F_221 ( V_8 ) ;
F_225 (sk, node) {
if ( V_8 -> V_394 == V_375 -> V_243 && F_226 ( F_19 ( V_8 ) , V_108 ) )
return V_8 ;
}
F_228 ( F_233 ( & V_110 , V_375 -> V_378 ) ) ;
++ V_375 -> V_378 ;
return F_232 ( V_105 ) ;
}
static void * F_236 ( struct V_369 * V_105 , T_10 V_397 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
void * V_398 ;
V_375 -> V_378 = 0 ;
V_398 = F_232 ( V_105 ) ;
while ( V_398 && V_397 ) {
V_398 = F_235 ( V_105 , V_398 ) ;
-- V_397 ;
}
return V_398 ;
}
static void * F_237 ( struct V_369 * V_105 , T_10 V_397 )
{
void * V_398 ;
struct V_374 * V_375 = V_105 -> V_376 ;
V_375 -> V_382 = V_391 ;
V_398 = F_229 ( V_105 , & V_397 ) ;
if ( ! V_398 ) {
V_375 -> V_382 = V_402 ;
V_398 = F_236 ( V_105 , V_397 ) ;
}
return V_398 ;
}
static void * F_238 ( struct V_369 * V_105 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
int V_206 = V_375 -> V_206 ;
int V_403 = V_375 -> V_381 ;
void * V_398 = NULL ;
switch ( V_375 -> V_382 ) {
case V_383 :
case V_391 :
if ( V_375 -> V_378 >= V_396 )
break;
V_375 -> V_382 = V_391 ;
V_398 = F_217 ( V_105 , NULL ) ;
while ( V_206 -- && V_398 )
V_398 = F_217 ( V_105 , V_398 ) ;
if ( V_398 )
break;
V_375 -> V_378 = 0 ;
V_375 -> V_382 = V_402 ;
case V_402 :
if ( V_375 -> V_378 > V_110 . V_401 )
break;
V_398 = F_232 ( V_105 ) ;
while ( V_206 -- && V_398 )
V_398 = F_235 ( V_105 , V_398 ) ;
}
V_375 -> V_381 = V_403 ;
return V_398 ;
}
static void * F_239 ( struct V_369 * V_105 , T_10 * V_397 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
void * V_398 ;
if ( * V_397 && * V_397 == V_375 -> V_404 ) {
V_398 = F_238 ( V_105 ) ;
if ( V_398 )
goto V_117;
}
V_375 -> V_382 = V_391 ;
V_375 -> V_381 = 0 ;
V_375 -> V_378 = 0 ;
V_375 -> V_206 = 0 ;
V_398 = * V_397 ? F_237 ( V_105 , * V_397 - 1 ) : V_405 ;
V_117:
V_375 -> V_404 = * V_397 ;
return V_398 ;
}
static void * F_240 ( struct V_369 * V_105 , void * V_406 , T_10 * V_397 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
void * V_398 = NULL ;
if ( V_406 == V_405 ) {
V_398 = F_237 ( V_105 , 0 ) ;
goto V_117;
}
switch ( V_375 -> V_382 ) {
case V_383 :
case V_391 :
V_398 = F_217 ( V_105 , V_406 ) ;
if ( ! V_398 ) {
V_375 -> V_382 = V_402 ;
V_375 -> V_378 = 0 ;
V_375 -> V_206 = 0 ;
V_398 = F_232 ( V_105 ) ;
}
break;
case V_402 :
V_398 = F_235 ( V_105 , V_406 ) ;
break;
}
V_117:
++ * V_397 ;
V_375 -> V_404 = * V_397 ;
return V_398 ;
}
static void F_241 ( struct V_369 * V_105 , void * V_406 )
{
struct V_374 * V_375 = V_105 -> V_376 ;
switch ( V_375 -> V_382 ) {
case V_383 :
if ( V_406 ) {
struct V_100 * V_101 = F_24 ( V_375 -> V_384 ) ;
F_222 ( & V_101 -> V_235 . V_392 ) ;
}
case V_391 :
if ( V_406 != V_405 )
F_228 ( & V_110 . V_377 [ V_375 -> V_378 ] . V_379 ) ;
break;
case V_402 :
if ( V_406 )
F_228 ( F_233 ( & V_110 , V_375 -> V_378 ) ) ;
break;
}
}
int F_242 ( struct V_407 * V_407 , struct V_408 * V_408 )
{
struct V_409 * V_410 = F_243 ( V_407 ) ;
struct V_374 * V_411 ;
int V_37 ;
V_37 = F_244 ( V_407 , V_408 , & V_410 -> V_412 ,
sizeof( struct V_374 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_411 = ( (struct V_369 * ) V_408 -> V_413 ) -> V_376 ;
V_411 -> V_243 = V_410 -> V_243 ;
V_411 -> V_404 = 0 ;
return 0 ;
}
int F_245 ( struct V_108 * V_108 , struct V_409 * V_410 )
{
int V_398 = 0 ;
struct V_414 * V_415 ;
V_410 -> V_412 . V_416 = F_239 ;
V_410 -> V_412 . V_417 = F_240 ;
V_410 -> V_412 . V_418 = F_241 ;
V_415 = F_246 ( V_410 -> V_419 , V_420 , V_108 -> V_421 ,
V_410 -> V_422 , V_410 ) ;
if ( ! V_415 )
V_398 = - V_259 ;
return V_398 ;
}
void F_247 ( struct V_108 * V_108 , struct V_409 * V_410 )
{
F_248 ( V_410 -> V_419 , V_108 -> V_421 ) ;
}
static void F_249 ( const struct V_7 * V_8 , const struct V_103 * V_148 ,
struct V_369 * V_423 , int V_424 , T_12 V_395 )
{
const struct V_223 * V_224 = F_95 ( V_148 ) ;
long V_425 = V_148 -> V_426 - V_79 ;
F_250 ( V_423 , L_7
L_8 ,
V_424 ,
V_224 -> V_225 ,
F_81 ( F_11 ( V_8 ) -> V_49 ) ,
V_224 -> V_226 ,
F_81 ( V_224 -> V_427 ) ,
V_151 ,
0 , 0 ,
1 ,
F_251 ( V_425 ) ,
V_148 -> V_428 ,
F_252 ( F_253 ( V_423 ) , V_395 ) ,
0 ,
0 ,
F_254 ( & V_8 -> V_429 ) ,
V_148 ) ;
}
static void F_255 ( struct V_7 * V_8 , struct V_369 * V_423 , int V_424 )
{
int V_430 ;
unsigned long V_431 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_100 * V_101 = F_24 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_432 * V_433 = V_101 -> V_235 . V_433 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_434 = V_29 -> V_63 ;
T_13 V_435 = F_81 ( V_29 -> V_69 ) ;
T_13 V_436 = F_81 ( V_29 -> V_49 ) ;
int V_437 ;
if ( V_101 -> V_438 == V_144 ||
V_101 -> V_438 == V_439 ||
V_101 -> V_438 == V_440 ) {
V_430 = 1 ;
V_431 = V_101 -> V_441 ;
} else if ( V_101 -> V_438 == V_442 ) {
V_430 = 4 ;
V_431 = V_101 -> V_441 ;
} else if ( F_256 ( & V_8 -> V_443 ) ) {
V_430 = 2 ;
V_431 = V_8 -> V_443 . V_426 ;
} else {
V_430 = 0 ;
V_431 = V_79 ;
}
if ( V_8 -> V_112 == V_123 )
V_437 = V_8 -> V_444 ;
else
V_437 = F_257 ( int , V_14 -> V_216 - V_14 -> V_445 , 0 ) ;
F_250 ( V_423 , L_9
L_10 ,
V_424 , V_434 , V_436 , V_5 , V_435 , V_8 -> V_112 ,
V_14 -> V_17 - V_14 -> V_106 ,
V_437 ,
V_430 ,
F_251 ( V_431 - V_79 ) ,
V_101 -> V_137 ,
F_252 ( F_253 ( V_423 ) , F_227 ( V_8 ) ) ,
V_101 -> V_446 ,
F_258 ( V_8 ) ,
F_254 ( & V_8 -> V_429 ) , V_8 ,
F_259 ( V_101 -> V_139 ) ,
F_259 ( V_101 -> V_447 . V_448 ) ,
( V_101 -> V_447 . V_449 << 1 ) | V_101 -> V_447 . V_450 ,
V_14 -> V_451 ,
V_8 -> V_112 == V_123 ?
( V_433 ? V_433 -> V_452 : 0 ) :
( F_260 ( V_14 ) ? - 1 : V_14 -> V_453 ) ) ;
}
static void F_261 ( const struct V_207 * V_208 ,
struct V_369 * V_423 , int V_424 )
{
T_3 V_5 , V_434 ;
T_13 V_435 , V_436 ;
T_14 V_425 = V_208 -> V_454 - F_262 () ;
V_5 = V_208 -> V_455 ;
V_434 = V_208 -> V_456 ;
V_435 = F_81 ( V_208 -> V_457 ) ;
V_436 = F_81 ( V_208 -> V_458 ) ;
F_250 ( V_423 , L_7
L_11 ,
V_424 , V_434 , V_436 , V_5 , V_435 , V_208 -> V_459 , 0 , 0 ,
3 , F_251 ( V_425 ) , 0 , 0 , 0 , 0 ,
F_254 ( & V_208 -> V_460 ) , V_208 ) ;
}
static int F_263 ( struct V_369 * V_105 , void * V_406 )
{
struct V_374 * V_375 ;
struct V_7 * V_8 = V_406 ;
F_264 ( V_105 , V_461 - 1 ) ;
if ( V_406 == V_405 ) {
F_265 ( V_105 , L_12
L_13
L_14 ) ;
goto V_117;
}
V_375 = V_105 -> V_376 ;
switch ( V_375 -> V_382 ) {
case V_391 :
case V_402 :
if ( V_8 -> V_112 == V_113 )
F_261 ( V_406 , V_105 , V_375 -> V_381 ) ;
else
F_255 ( V_406 , V_105 , V_375 -> V_381 ) ;
break;
case V_383 :
F_249 ( V_375 -> V_384 , V_406 , V_105 , V_375 -> V_381 , V_375 -> V_395 ) ;
break;
}
V_117:
F_266 ( V_105 , '\n' ) ;
return 0 ;
}
static int T_15 F_267 ( struct V_108 * V_108 )
{
return F_245 ( V_108 , & V_462 ) ;
}
static void T_16 F_268 ( struct V_108 * V_108 )
{
F_247 ( V_108 , & V_462 ) ;
}
int T_17 F_269 ( void )
{
return F_270 ( & V_463 ) ;
}
void F_271 ( void )
{
F_272 ( & V_463 ) ;
}
static int T_15 F_273 ( struct V_108 * V_108 )
{
V_108 -> V_464 . V_465 = 2 ;
return 0 ;
}
static void T_16 F_274 ( struct V_108 * V_108 )
{
}
static void T_16 F_275 ( struct V_466 * V_467 )
{
F_276 ( & V_110 , & V_66 , V_42 ) ;
}
void T_17 F_277 ( void )
{
F_278 ( & V_110 ) ;
if ( F_270 ( & V_468 ) )
F_279 ( L_15 ) ;
}
