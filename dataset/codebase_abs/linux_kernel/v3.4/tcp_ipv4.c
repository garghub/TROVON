static inline T_1 F_1 ( const struct V_1 * V_2 )
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
V_30 , V_31 , V_8 , true ) ;
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
V_14 -> V_17 = 0 ;
}
if ( V_65 . V_66 &&
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 ) {
struct V_67 * V_68 = F_21 ( V_36 , V_34 -> V_3 ) ;
if ( V_68 ) {
F_22 ( V_68 ) ;
if ( ( V_69 ) F_8 () - V_68 -> V_70 <= V_71 ) {
V_14 -> V_19 . V_22 = V_68 -> V_70 ;
V_14 -> V_19 . V_20 = V_68 -> V_72 ;
}
}
}
V_29 -> V_73 = V_27 -> V_50 ;
V_29 -> V_64 = V_3 ;
F_23 ( V_8 ) -> V_74 = 0 ;
if ( V_39 )
F_23 ( V_8 ) -> V_74 = V_39 -> V_46 . V_75 ;
V_14 -> V_19 . V_76 = V_77 ;
F_24 ( V_8 , V_78 ) ;
V_37 = F_25 ( & V_65 , V_8 ) ;
if ( V_37 )
goto V_79;
V_36 = F_26 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_73 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
V_36 = NULL ;
goto V_79;
}
V_8 -> V_80 = V_81 ;
F_27 ( V_8 , & V_36 -> V_82 ) ;
if ( ! V_14 -> V_17 )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_64 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_83 = V_14 -> V_17 ^ V_84 ;
V_37 = F_28 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_79;
return 0 ;
V_79:
F_24 ( V_8 , V_85 ) ;
F_20 ( V_36 ) ;
V_8 -> V_86 = 0 ;
V_29 -> V_73 = 0 ;
return V_37 ;
}
static void F_29 ( struct V_7 * V_8 , const struct V_87 * V_88 , V_69 V_89 )
{
struct V_90 * V_82 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
if ( V_8 -> V_91 == V_92 )
return;
if ( ( V_82 = F_30 ( V_8 , 0 ) ) == NULL )
return;
V_82 -> V_93 -> V_94 ( V_82 , V_89 ) ;
if ( V_89 < F_31 ( V_82 ) && F_32 ( V_8 , V_82 ) )
V_8 -> V_95 = V_96 ;
V_89 = F_31 ( V_82 ) ;
if ( V_29 -> V_97 != V_98 &&
F_23 ( V_8 ) -> V_99 > V_89 ) {
F_33 ( V_8 , V_89 ) ;
F_34 ( V_8 ) ;
}
}
void F_35 ( struct V_1 * V_100 , V_69 V_101 )
{
const struct V_87 * V_88 = ( const struct V_87 * ) V_100 -> V_102 ;
struct V_103 * V_104 = (struct V_103 * ) ( V_100 -> V_102 + ( V_88 -> V_105 << 2 ) ) ;
struct V_106 * V_107 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_36 ( V_100 ) -> type ;
const int V_108 = F_36 ( V_100 ) -> V_108 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
T_1 V_109 ;
T_1 V_110 ;
int V_37 ;
struct V_111 * V_111 = F_37 ( V_100 -> V_112 ) ;
if ( V_100 -> V_113 < ( V_88 -> V_105 << 2 ) + 8 ) {
F_38 ( V_111 , V_114 ) ;
return;
}
V_8 = F_39 ( V_111 , & V_115 , V_88 -> V_3 , V_104 -> V_5 ,
V_88 -> V_4 , V_104 -> V_6 , F_40 ( V_100 ) ) ;
if ( ! V_8 ) {
F_38 ( V_111 , V_114 ) ;
return;
}
if ( V_8 -> V_91 == V_116 ) {
F_41 ( F_42 ( V_8 ) ) ;
return;
}
F_43 ( V_8 ) ;
if ( F_13 ( V_8 ) )
F_44 ( V_111 , V_117 ) ;
if ( V_8 -> V_91 == V_85 )
goto V_118;
if ( F_45 ( V_88 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_44 ( V_111 , V_121 ) ;
goto V_118;
}
V_107 = F_23 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_109 = F_46 ( V_104 -> V_109 ) ;
if ( V_8 -> V_91 != V_92 &&
! F_47 ( V_109 , V_14 -> V_122 , V_14 -> V_123 ) ) {
F_44 ( V_111 , V_124 ) ;
goto V_118;
}
switch ( type ) {
case V_125 :
goto V_118;
case V_126 :
V_37 = V_127 ;
break;
case V_128 :
if ( V_108 > V_129 )
goto V_118;
if ( V_108 == V_130 ) {
if ( ! F_13 ( V_8 ) )
F_29 ( V_8 , V_88 , V_101 ) ;
goto V_118;
}
V_37 = V_131 [ V_108 ] . V_132 ;
if ( V_108 != V_133 && V_108 != V_134 )
break;
if ( V_109 != V_14 -> V_122 || ! V_107 -> V_135 ||
! V_107 -> V_136 )
break;
if ( F_13 ( V_8 ) )
break;
V_107 -> V_136 -- ;
F_23 ( V_8 ) -> V_137 = ( V_14 -> V_138 ? F_48 ( V_14 ) :
V_139 ) << V_107 -> V_136 ;
F_49 ( V_8 ) ;
V_2 = F_50 ( V_8 ) ;
F_51 ( ! V_2 ) ;
V_110 = V_107 -> V_137 - F_52 ( V_107 -> V_137 ,
V_140 - F_53 ( V_2 ) -> V_141 ) ;
if ( V_110 ) {
F_54 ( V_8 , V_142 ,
V_110 , V_143 ) ;
} else {
F_55 ( V_8 ) ;
}
break;
case V_144 :
V_37 = V_145 ;
break;
default:
goto V_118;
}
switch ( V_8 -> V_91 ) {
struct V_146 * V_147 , * * V_148 ;
case V_92 :
if ( F_13 ( V_8 ) )
goto V_118;
V_147 = F_56 ( V_8 , & V_148 , V_104 -> V_5 ,
V_88 -> V_3 , V_88 -> V_4 ) ;
if ( ! V_147 )
goto V_118;
F_57 ( V_147 -> V_8 ) ;
if ( V_109 != F_58 ( V_147 ) -> V_149 ) {
F_44 ( V_111 , V_124 ) ;
goto V_118;
}
F_59 ( V_8 , V_147 , V_148 ) ;
goto V_118;
case V_78 :
case V_150 :
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
F_60 ( V_8 ) ;
} else {
V_8 -> V_95 = V_37 ;
}
goto V_118;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_153 ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
} else {
V_8 -> V_95 = V_37 ;
}
V_118:
F_61 ( V_8 ) ;
F_62 ( V_8 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_103 * V_104 = F_4 ( V_2 ) ;
if ( V_2 -> V_154 == V_155 ) {
V_104 -> V_156 = ~ F_64 ( V_2 -> V_113 , V_4 , V_3 , 0 ) ;
V_2 -> V_157 = F_65 ( V_2 ) - V_2 -> V_158 ;
V_2 -> V_159 = F_66 ( struct V_103 , V_156 ) ;
} else {
V_104 -> V_156 = F_64 ( V_2 -> V_113 , V_4 , V_3 ,
F_67 ( V_104 ,
V_104 -> V_160 << 2 ,
V_2 -> V_161 ) ) ;
}
}
void F_68 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_63 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
int F_69 ( struct V_1 * V_2 )
{
const struct V_87 * V_88 ;
struct V_103 * V_104 ;
if ( ! F_70 ( V_2 , sizeof( * V_104 ) ) )
return - V_40 ;
V_88 = F_3 ( V_2 ) ;
V_104 = F_4 ( V_2 ) ;
V_104 -> V_156 = 0 ;
V_2 -> V_154 = V_155 ;
F_63 ( V_2 , V_88 -> V_4 , V_88 -> V_3 ) ;
return 0 ;
}
static void F_71 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_103 * V_104 = F_4 ( V_2 ) ;
struct {
struct V_103 V_104 ;
#ifdef F_72
T_3 V_46 [ ( V_162 >> 2 ) ] ;
#endif
} V_163 ;
struct V_164 V_165 ;
#ifdef F_72
struct V_166 * V_167 ;
const T_4 * V_168 = NULL ;
unsigned char V_169 [ 16 ] ;
int V_170 ;
struct V_7 * V_171 = NULL ;
#endif
struct V_111 * V_111 ;
if ( V_104 -> V_172 )
return;
if ( F_73 ( V_2 ) -> V_173 != V_174 )
return;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_104 . V_5 = V_104 -> V_6 ;
V_163 . V_104 . V_6 = V_104 -> V_5 ;
V_163 . V_104 . V_160 = sizeof( struct V_103 ) / 4 ;
V_163 . V_104 . V_172 = 1 ;
if ( V_104 -> V_175 ) {
V_163 . V_104 . V_109 = V_104 -> V_176 ;
} else {
V_163 . V_104 . V_175 = 1 ;
V_163 . V_104 . V_176 = F_74 ( F_46 ( V_104 -> V_109 ) + V_104 -> V_177 + V_104 -> V_178 +
V_2 -> V_113 - ( V_104 -> V_160 << 2 ) ) ;
}
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_104 ) ;
#ifdef F_72
V_168 = F_75 ( V_104 ) ;
if ( ! V_8 && V_168 ) {
V_171 = F_76 ( F_37 ( F_77 ( V_2 ) -> V_112 ) ,
& V_115 , F_3 ( V_2 ) -> V_3 ,
F_78 ( V_104 -> V_6 ) , F_40 ( V_2 ) ) ;
if ( ! V_171 )
return;
F_79 () ;
V_167 = F_80 ( V_171 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_167 )
goto V_183;
V_170 = F_81 ( V_169 , V_167 , NULL , NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 )
goto V_183;
} else {
V_167 = V_8 ? F_80 ( V_8 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_167 ) {
V_163 . V_46 [ 0 ] = F_74 ( ( V_184 << 24 ) |
( V_184 << 16 ) |
( V_185 << 8 ) |
V_186 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_82 ( ( T_4 * ) & V_163 . V_46 [ 1 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_104 ) ;
}
#endif
V_165 . V_161 = F_83 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_187 = F_66 ( struct V_103 , V_156 ) / 2 ;
V_165 . V_188 = ( V_8 && F_11 ( V_8 ) -> V_189 ) ? V_190 : 0 ;
V_165 . V_191 = V_8 ? V_8 -> V_56 : F_40 ( V_2 ) ;
V_111 = F_37 ( F_77 ( V_2 ) -> V_112 ) ;
V_165 . V_192 = F_3 ( V_2 ) -> V_192 ;
F_84 ( V_111 -> V_193 . V_13 , V_2 , F_3 ( V_2 ) -> V_4 ,
& V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_85 ( V_111 , V_194 ) ;
F_85 ( V_111 , V_195 ) ;
#ifdef F_72
V_183:
if ( V_171 ) {
F_86 () ;
F_62 ( V_171 ) ;
}
#endif
}
static void F_87 ( struct V_1 * V_2 , V_69 V_109 , V_69 V_175 ,
V_69 V_196 , V_69 V_197 , int V_198 ,
struct V_166 * V_167 ,
int V_199 , T_5 V_192 )
{
const struct V_103 * V_104 = F_4 ( V_2 ) ;
struct {
struct V_103 V_104 ;
T_3 V_46 [ ( V_200 >> 2 )
#ifdef F_72
+ ( V_162 >> 2 )
#endif
] ;
} V_163 ;
struct V_164 V_165 ;
struct V_111 * V_111 = F_37 ( F_77 ( V_2 ) -> V_112 ) ;
memset ( & V_163 . V_104 , 0 , sizeof( struct V_103 ) ) ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_104 ) ;
if ( V_197 ) {
V_163 . V_46 [ 0 ] = F_74 ( ( V_184 << 24 ) | ( V_184 << 16 ) |
( V_201 << 8 ) |
V_202 ) ;
V_163 . V_46 [ 1 ] = F_74 ( V_140 ) ;
V_163 . V_46 [ 2 ] = F_74 ( V_197 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_200 ;
}
V_163 . V_104 . V_5 = V_104 -> V_6 ;
V_163 . V_104 . V_6 = V_104 -> V_5 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
V_163 . V_104 . V_109 = F_74 ( V_109 ) ;
V_163 . V_104 . V_176 = F_74 ( V_175 ) ;
V_163 . V_104 . V_175 = 1 ;
V_163 . V_104 . V_203 = F_88 ( V_196 ) ;
#ifdef F_72
if ( V_167 ) {
int V_204 = ( V_197 ) ? 3 : 0 ;
V_163 . V_46 [ V_204 ++ ] = F_74 ( ( V_184 << 24 ) |
( V_184 << 16 ) |
( V_185 << 8 ) |
V_186 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_82 ( ( T_4 * ) & V_163 . V_46 [ V_204 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_104 ) ;
}
#endif
V_165 . V_188 = V_199 ;
V_165 . V_161 = F_83 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_187 = F_66 ( struct V_103 , V_156 ) / 2 ;
if ( V_198 )
V_165 . V_191 = V_198 ;
V_165 . V_192 = V_192 ;
F_84 ( V_111 -> V_193 . V_13 , V_2 , F_3 ( V_2 ) -> V_4 ,
& V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_85 ( V_111 , V_194 ) ;
}
static void F_89 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_205 * V_206 = F_42 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_87 ( V_2 , V_12 -> V_18 , V_12 -> V_207 ,
V_12 -> V_208 >> V_206 -> V_209 ,
V_12 -> V_21 ,
V_206 -> V_210 ,
F_90 ( V_12 ) ,
V_206 -> V_211 ? V_190 : 0 ,
V_206 -> V_212
) ;
F_41 ( V_206 ) ;
}
static void F_91 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_146 * V_147 )
{
F_87 ( V_2 , F_58 ( V_147 ) -> V_149 + 1 ,
F_58 ( V_147 ) -> V_213 + 1 , V_147 -> V_214 ,
V_147 -> V_20 ,
0 ,
F_80 ( V_8 , (union V_182 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_92 ( V_147 ) -> V_215 ? V_190 : 0 ,
F_3 ( V_2 ) -> V_192 ) ;
}
static int F_93 ( struct V_7 * V_8 , struct V_90 * V_82 ,
struct V_146 * V_147 ,
struct V_216 * V_217 )
{
const struct V_218 * V_219 = F_92 ( V_147 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_82 && ( V_82 = F_94 ( V_8 , & V_34 , V_147 ) ) == NULL )
return - 1 ;
V_2 = F_95 ( V_8 , V_82 , V_147 , V_217 ) ;
if ( V_2 ) {
F_63 ( V_2 , V_219 -> V_220 , V_219 -> V_221 ) ;
V_37 = F_96 ( V_2 , V_8 , V_219 -> V_220 ,
V_219 -> V_221 ,
V_219 -> V_46 ) ;
V_37 = F_97 ( V_37 ) ;
}
F_98 ( V_82 ) ;
return V_37 ;
}
static int F_99 ( struct V_7 * V_8 , struct V_146 * V_147 ,
struct V_216 * V_217 )
{
F_85 ( F_19 ( V_8 ) , V_222 ) ;
return F_93 ( V_8 , NULL , V_147 , V_217 ) ;
}
static void F_100 ( struct V_146 * V_147 )
{
F_101 ( F_92 ( V_147 ) -> V_46 ) ;
}
int F_102 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_223 )
{
const char * V_224 = L_1 ;
int V_225 = 0 ;
struct V_226 * V_227 ;
#ifdef F_103
if ( V_228 ) {
V_224 = L_2 ;
V_225 = 1 ;
F_44 ( F_19 ( V_8 ) , V_229 ) ;
} else
#endif
F_44 ( F_19 ( V_8 ) , V_230 ) ;
V_227 = F_23 ( V_8 ) -> V_231 . V_232 ;
if ( ! V_227 -> V_233 ) {
V_227 -> V_233 = 1 ;
F_104 ( L_3 ,
V_223 , F_78 ( F_4 ( V_2 ) -> V_5 ) , V_224 ) ;
}
return V_225 ;
}
static struct V_38 * F_105 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
const struct V_234 * V_46 = & ( F_106 ( V_2 ) -> V_46 ) ;
struct V_38 * V_235 = NULL ;
if ( V_46 && V_46 -> V_75 ) {
int V_236 = sizeof( * V_235 ) + V_46 -> V_75 ;
V_235 = F_107 ( V_236 , V_237 ) ;
if ( V_235 ) {
if ( F_108 ( & V_235 -> V_46 , V_2 ) ) {
F_101 ( V_235 ) ;
V_235 = NULL ;
}
}
}
return V_235 ;
}
struct V_166 * F_80 ( struct V_7 * V_8 ,
const union V_182 * V_238 ,
int V_239 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_240 * V_241 ;
unsigned int V_242 = sizeof( struct V_243 ) ;
struct V_244 * V_245 ;
V_245 = F_109 ( V_14 -> V_246 ,
F_13 ( V_8 ) ||
F_110 ( & V_8 -> V_247 . V_248 ) ) ;
if ( ! V_245 )
return NULL ;
#if F_111 ( V_249 )
if ( V_239 == V_250 )
V_242 = sizeof( struct V_251 ) ;
#endif
F_112 (key, pos, &md5sig->head, node) {
if ( V_167 -> V_239 != V_239 )
continue;
if ( ! memcmp ( & V_167 -> V_238 , V_238 , V_242 ) )
return V_167 ;
}
return NULL ;
}
struct V_166 * F_113 ( struct V_7 * V_8 ,
struct V_7 * V_252 )
{
union V_182 * V_238 ;
V_238 = (union V_182 * ) & F_11 ( V_252 ) -> V_64 ;
return F_80 ( V_8 , V_238 , V_42 ) ;
}
static struct V_166 * F_114 ( struct V_7 * V_8 ,
struct V_146 * V_147 )
{
union V_182 * V_238 ;
V_238 = (union V_182 * ) & F_92 ( V_147 ) -> V_221 ;
return F_80 ( V_8 , V_238 , V_42 ) ;
}
int F_115 ( struct V_7 * V_8 , const union V_182 * V_238 ,
int V_239 , const T_5 * V_253 , T_5 V_254 , T_6 V_255 )
{
struct V_166 * V_167 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_244 * V_245 ;
V_167 = F_80 ( V_8 , (union V_182 * ) & V_238 , V_42 ) ;
if ( V_167 ) {
memcpy ( V_167 -> V_167 , V_253 , V_254 ) ;
V_167 -> V_256 = V_254 ;
return 0 ;
}
V_245 = F_12 ( V_14 -> V_246 ,
F_13 ( V_8 ) ) ;
if ( ! V_245 ) {
V_245 = F_107 ( sizeof( * V_245 ) , V_255 ) ;
if ( ! V_245 )
return - V_257 ;
F_116 ( V_8 , V_258 ) ;
F_117 ( & V_245 -> V_158 ) ;
F_118 ( V_14 -> V_246 , V_245 ) ;
}
V_167 = F_119 ( V_8 , sizeof( * V_167 ) , V_255 ) ;
if ( ! V_167 )
return - V_257 ;
if ( F_120 ( & V_245 -> V_158 ) && ! F_121 ( V_8 ) ) {
F_122 ( V_8 , V_167 , sizeof( * V_167 ) ) ;
return - V_257 ;
}
memcpy ( V_167 -> V_167 , V_253 , V_254 ) ;
V_167 -> V_256 = V_254 ;
V_167 -> V_239 = V_239 ;
memcpy ( & V_167 -> V_238 , V_238 ,
( V_239 == V_250 ) ? sizeof( struct V_251 ) :
sizeof( struct V_243 ) ) ;
F_123 ( & V_167 -> V_259 , & V_245 -> V_158 ) ;
return 0 ;
}
int F_124 ( struct V_7 * V_8 , const union V_182 * V_238 , int V_239 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_244 * V_245 ;
V_167 = F_80 ( V_8 , (union V_182 * ) & V_238 , V_42 ) ;
if ( ! V_167 )
return - V_260 ;
F_125 ( & V_167 -> V_259 ) ;
F_126 ( sizeof( * V_167 ) , & V_8 -> V_261 ) ;
F_127 ( V_167 , V_262 ) ;
V_245 = F_12 ( V_14 -> V_246 ,
F_13 ( V_8 ) ) ;
if ( F_120 ( & V_245 -> V_158 ) )
F_128 () ;
return 0 ;
}
void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_240 * V_241 , * V_263 ;
struct V_244 * V_245 ;
V_245 = F_12 ( V_14 -> V_246 , 1 ) ;
if ( ! F_120 ( & V_245 -> V_158 ) )
F_128 () ;
F_130 (key, pos, n, &md5sig->head, node) {
F_125 ( & V_167 -> V_259 ) ;
F_126 ( sizeof( * V_167 ) , & V_8 -> V_261 ) ;
F_127 ( V_167 , V_262 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , char T_7 * V_264 ,
int V_75 )
{
struct V_265 V_266 ;
struct V_26 * sin = (struct V_26 * ) & V_266 . V_267 ;
if ( V_75 < sizeof( V_266 ) )
return - V_40 ;
if ( F_132 ( & V_266 , V_264 , sizeof( V_266 ) ) )
return - V_268 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_266 . V_269 || ! V_266 . V_270 )
return F_124 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_266 . V_270 > V_271 )
return - V_40 ;
return F_115 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 , V_266 . V_269 , V_266 . V_270 ,
V_272 ) ;
}
static int F_133 ( struct V_273 * V_274 ,
T_3 V_3 , T_3 V_4 , int V_275 )
{
struct V_276 * V_277 ;
struct V_278 V_279 ;
V_277 = & V_274 -> V_280 . V_54 ;
V_277 -> V_4 = V_4 ;
V_277 -> V_3 = V_3 ;
V_277 -> V_281 = 0 ;
V_277 -> V_282 = V_57 ;
V_277 -> V_113 = F_134 ( V_275 ) ;
F_135 ( & V_279 , V_277 , sizeof( * V_277 ) ) ;
return F_136 ( & V_274 -> V_283 , & V_279 , sizeof( * V_277 ) ) ;
}
static int F_82 ( char * V_284 , const struct V_166 * V_167 ,
T_3 V_3 , T_3 V_4 , const struct V_103 * V_104 )
{
struct V_273 * V_274 ;
struct V_285 * V_286 ;
V_274 = F_137 () ;
if ( ! V_274 )
goto V_287;
V_286 = & V_274 -> V_283 ;
if ( F_138 ( V_286 ) )
goto V_288;
if ( F_133 ( V_274 , V_3 , V_4 , V_104 -> V_160 << 2 ) )
goto V_288;
if ( F_139 ( V_274 , V_104 ) )
goto V_288;
if ( F_140 ( V_274 , V_167 ) )
goto V_288;
if ( F_141 ( V_286 , V_284 ) )
goto V_288;
F_142 () ;
return 0 ;
V_288:
F_142 () ;
V_287:
memset ( V_284 , 0 , 16 ) ;
return 1 ;
}
int F_81 ( char * V_284 , struct V_166 * V_167 ,
const struct V_7 * V_8 , const struct V_146 * V_147 ,
const struct V_1 * V_2 )
{
struct V_273 * V_274 ;
struct V_285 * V_286 ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_147 ) {
V_4 = F_92 ( V_147 ) -> V_220 ;
V_3 = F_92 ( V_147 ) -> V_221 ;
} else {
const struct V_87 * V_88 = F_3 ( V_2 ) ;
V_4 = V_88 -> V_4 ;
V_3 = V_88 -> V_3 ;
}
V_274 = F_137 () ;
if ( ! V_274 )
goto V_287;
V_286 = & V_274 -> V_283 ;
if ( F_138 ( V_286 ) )
goto V_288;
if ( F_133 ( V_274 , V_3 , V_4 , V_2 -> V_113 ) )
goto V_288;
if ( F_139 ( V_274 , V_104 ) )
goto V_288;
if ( F_143 ( V_274 , V_2 , V_104 -> V_160 << 2 ) )
goto V_288;
if ( F_140 ( V_274 , V_167 ) )
goto V_288;
if ( F_141 ( V_286 , V_284 ) )
goto V_288;
F_142 () ;
return 0 ;
V_288:
F_142 () ;
V_287:
memset ( V_284 , 0 , 16 ) ;
return 1 ;
}
static int F_144 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_4 * V_168 = NULL ;
struct V_166 * V_289 ;
const struct V_87 * V_88 = F_3 ( V_2 ) ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
int V_170 ;
unsigned char V_169 [ 16 ] ;
V_289 = F_80 ( V_8 , (union V_182 * ) & V_88 -> V_4 ,
V_42 ) ;
V_168 = F_75 ( V_104 ) ;
if ( ! V_289 && ! V_168 )
return 0 ;
if ( V_289 && ! V_168 ) {
F_44 ( F_19 ( V_8 ) , V_290 ) ;
return 1 ;
}
if ( ! V_289 && V_168 ) {
F_44 ( F_19 ( V_8 ) , V_291 ) ;
return 1 ;
}
V_170 = F_81 ( V_169 ,
V_289 ,
NULL , NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 ) {
if ( F_145 () ) {
F_104 ( L_4 ,
& V_88 -> V_4 , F_78 ( V_104 -> V_6 ) ,
& V_88 -> V_3 , F_78 ( V_104 -> V_5 ) ,
V_170 ? L_5 : L_6 ) ;
}
return 1 ;
}
return 0 ;
}
int F_146 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
const T_5 * V_168 ;
struct V_146 * V_147 ;
struct V_218 * V_219 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_90 * V_82 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_296 = F_53 ( V_2 ) -> V_141 ;
int V_225 = 0 ;
if ( F_73 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_297;
if ( F_147 ( V_8 ) && ! V_296 ) {
V_225 = F_102 ( V_8 , V_2 , L_7 ) ;
if ( ! V_225 )
goto V_297;
}
if ( F_148 ( V_8 ) && F_149 ( V_8 ) > 1 )
goto V_297;
V_147 = F_150 ( & V_298 ) ;
if ( ! V_147 )
goto V_297;
#ifdef F_72
F_58 ( V_147 ) -> V_299 = & V_300 ;
#endif
F_151 ( & V_295 ) ;
V_295 . V_76 = V_77 ;
V_295 . V_301 = V_14 -> V_19 . V_301 ;
F_152 ( V_2 , & V_295 , & V_168 , 0 ) ;
if ( V_295 . V_302 > 0 &&
V_295 . V_303 &&
! V_14 -> V_19 . V_304 &&
( V_305 > 0 ||
( V_14 -> V_306 != NULL &&
V_14 -> V_306 -> V_307 > 0 ) ) ) {
T_5 * V_308 ;
V_69 * V_309 = & V_293 . V_310 [ V_311 ] ;
int V_312 = V_295 . V_302 - V_313 ;
if ( F_153 ( & V_293 . V_310 [ 0 ] ) != 0 )
goto V_314;
* V_309 ++ ^= ( V_315 V_69 ) V_3 ;
* V_309 ++ ^= ( V_315 V_69 ) V_4 ;
V_308 = ( T_5 * ) V_309 ;
while ( V_312 -- > 0 )
* V_308 ++ ^= * V_168 ++ ;
V_225 = 0 ;
V_293 . V_304 = 0 ;
V_293 . V_302 = V_295 . V_302 ;
} else if ( ! V_14 -> V_19 . V_316 ) {
V_293 . V_304 = 1 ;
V_293 . V_302 = 0 ;
} else {
goto V_314;
}
V_293 . V_316 = V_14 -> V_19 . V_316 ;
if ( V_225 && ! V_295 . V_303 )
F_151 ( & V_295 ) ;
V_295 . V_317 = V_295 . V_303 ;
F_154 ( V_147 , & V_295 , V_2 ) ;
V_219 = F_92 ( V_147 ) ;
V_219 -> V_220 = V_3 ;
V_219 -> V_221 = V_4 ;
V_219 -> V_215 = F_11 ( V_8 ) -> V_189 ;
V_219 -> V_46 = F_105 ( V_8 , V_2 ) ;
if ( F_155 ( V_8 , V_2 , V_147 ) )
goto V_318;
if ( ! V_225 || V_295 . V_317 )
F_156 ( V_147 , F_4 ( V_2 ) ) ;
if ( V_225 ) {
V_296 = F_157 ( V_8 , V_2 , & V_147 -> V_319 ) ;
V_147 -> V_320 = V_295 . V_317 ;
} else if ( ! V_296 ) {
struct V_67 * V_68 = NULL ;
struct V_33 V_34 ;
if ( V_295 . V_303 &&
V_65 . V_66 &&
( V_82 = F_94 ( V_8 , & V_34 , V_147 ) ) != NULL &&
V_34 . V_3 == V_4 &&
( V_68 = F_21 ( (struct V_35 * ) V_82 , V_34 . V_3 ) ) != NULL ) {
F_22 ( V_68 ) ;
if ( ( V_69 ) F_8 () - V_68 -> V_70 < V_71 &&
( V_321 ) ( V_68 -> V_72 - V_147 -> V_20 ) >
V_322 ) {
F_44 ( F_19 ( V_8 ) , V_323 ) ;
goto V_314;
}
}
else if ( ! V_228 &&
( V_324 - F_158 ( V_8 ) <
( V_324 >> 2 ) ) &&
( ! V_68 || ! V_68 -> V_70 ) &&
( ! V_82 || ! F_159 ( V_82 , V_325 ) ) ) {
F_160 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_314;
}
V_296 = F_1 ( V_2 ) ;
}
F_58 ( V_147 ) -> V_149 = V_296 ;
F_58 ( V_147 ) -> V_326 = V_140 ;
if ( F_93 ( V_8 , V_82 , V_147 ,
(struct V_216 * ) & V_293 ) ||
V_225 )
goto V_318;
F_161 ( V_8 , V_147 , V_139 ) ;
return 0 ;
V_314:
F_98 ( V_82 ) ;
V_318:
F_162 ( V_147 ) ;
V_297:
return 0 ;
}
struct V_7 * F_163 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_146 * V_147 ,
struct V_90 * V_82 )
{
struct V_218 * V_219 ;
struct V_28 * V_327 ;
struct V_13 * V_328 ;
struct V_7 * V_329 ;
#ifdef F_72
struct V_166 * V_167 ;
#endif
struct V_38 * V_39 ;
if ( F_148 ( V_8 ) )
goto V_330;
V_329 = F_164 ( V_8 , V_147 , V_2 ) ;
if ( ! V_329 )
goto V_331;
V_329 -> V_80 = V_81 ;
V_328 = F_7 ( V_329 ) ;
V_327 = F_11 ( V_329 ) ;
V_219 = F_92 ( V_147 ) ;
V_327 -> V_64 = V_219 -> V_221 ;
V_327 -> V_63 = V_219 -> V_220 ;
V_327 -> V_55 = V_219 -> V_220 ;
V_39 = V_219 -> V_46 ;
F_118 ( V_327 -> V_39 , V_39 ) ;
V_219 -> V_46 = NULL ;
V_327 -> V_332 = F_40 ( V_2 ) ;
V_327 -> V_333 = F_3 ( V_2 ) -> V_119 ;
V_327 -> V_334 = F_3 ( V_2 ) -> V_192 ;
F_23 ( V_329 ) -> V_74 = 0 ;
if ( V_39 )
F_23 ( V_329 ) -> V_74 = V_39 -> V_46 . V_75 ;
V_327 -> V_83 = V_328 -> V_17 ^ V_84 ;
if ( ! V_82 ) {
V_82 = F_165 ( V_8 , V_329 , V_147 ) ;
if ( ! V_82 )
goto V_335;
} else {
}
F_27 ( V_329 , V_82 ) ;
F_166 ( V_329 ) ;
F_33 ( V_329 , F_31 ( V_82 ) ) ;
V_328 -> V_336 = F_167 ( V_82 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_301 &&
F_7 ( V_8 ) -> V_19 . V_301 < V_328 -> V_336 )
V_328 -> V_336 = F_7 ( V_8 ) -> V_19 . V_301 ;
F_168 ( V_329 ) ;
if ( F_58 ( V_147 ) -> V_326 )
F_169 ( V_329 ,
V_140 - F_58 ( V_147 ) -> V_326 ) ;
V_328 -> V_337 = V_147 -> V_338 ;
#ifdef F_72
V_167 = F_80 ( V_8 , (union V_182 * ) & V_327 -> V_64 ,
V_42 ) ;
if ( V_167 != NULL ) {
F_115 ( V_329 , (union V_182 * ) & V_327 -> V_64 ,
V_42 , V_167 -> V_167 , V_167 -> V_256 , V_237 ) ;
F_116 ( V_329 , V_258 ) ;
}
#endif
if ( F_170 ( V_8 , V_329 ) < 0 )
goto V_335;
F_171 ( V_329 , NULL ) ;
return V_329 ;
V_330:
F_44 ( F_19 ( V_8 ) , V_339 ) ;
V_331:
F_98 ( V_82 ) ;
exit:
F_44 ( F_19 ( V_8 ) , V_340 ) ;
return NULL ;
V_335:
F_172 ( V_329 ) ;
F_173 ( V_329 ) ;
F_61 ( V_329 ) ;
F_62 ( V_329 ) ;
goto exit;
}
static struct V_7 * F_174 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_103 * V_104 = F_4 ( V_2 ) ;
const struct V_87 * V_88 = F_3 ( V_2 ) ;
struct V_7 * V_341 ;
struct V_146 * * V_148 ;
struct V_146 * V_147 = F_56 ( V_8 , & V_148 , V_104 -> V_6 ,
V_88 -> V_4 , V_88 -> V_3 ) ;
if ( V_147 )
return F_175 ( V_8 , V_2 , V_147 , V_148 ) ;
V_341 = F_176 ( F_19 ( V_8 ) , & V_115 , V_88 -> V_4 ,
V_104 -> V_6 , V_88 -> V_3 , V_104 -> V_5 , F_40 ( V_2 ) ) ;
if ( V_341 ) {
if ( V_341 -> V_91 != V_116 ) {
F_43 ( V_341 ) ;
return V_341 ;
}
F_41 ( F_42 ( V_341 ) ) ;
return NULL ;
}
#ifdef F_103
if ( ! V_104 -> V_177 )
V_8 = F_177 ( V_8 , V_2 , & ( F_106 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_8 F_178 ( struct V_1 * V_2 )
{
const struct V_87 * V_88 = F_3 ( V_2 ) ;
if ( V_2 -> V_154 == V_342 ) {
if ( ! F_64 ( V_2 -> V_113 , V_88 -> V_4 ,
V_88 -> V_3 , V_2 -> V_161 ) ) {
V_2 -> V_154 = V_343 ;
return 0 ;
}
}
V_2 -> V_161 = F_83 ( V_88 -> V_4 , V_88 -> V_3 ,
V_2 -> V_113 , V_57 , 0 ) ;
if ( V_2 -> V_113 <= 76 ) {
return F_179 ( V_2 ) ;
}
return 0 ;
}
int F_180 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_344 ;
#ifdef F_72
if ( F_144 ( V_8 , V_2 ) )
goto V_345;
#endif
if ( V_8 -> V_91 == V_346 ) {
F_181 ( V_8 , V_2 ) ;
if ( F_182 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_113 ) ) {
V_344 = V_8 ;
goto V_347;
}
return 0 ;
}
if ( V_2 -> V_113 < F_183 ( V_2 ) || F_184 ( V_2 ) )
goto V_348;
if ( V_8 -> V_91 == V_92 ) {
struct V_7 * V_341 = F_174 ( V_8 , V_2 ) ;
if ( ! V_341 )
goto V_345;
if ( V_341 != V_8 ) {
F_181 ( V_341 , V_2 ) ;
if ( F_185 ( V_8 , V_341 , V_2 ) ) {
V_344 = V_341 ;
goto V_347;
}
return 0 ;
}
} else
F_181 ( V_8 , V_2 ) ;
if ( F_186 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_113 ) ) {
V_344 = V_8 ;
goto V_347;
}
return 0 ;
V_347:
F_71 ( V_344 , V_2 ) ;
V_345:
F_187 ( V_2 ) ;
return 0 ;
V_348:
F_85 ( F_19 ( V_8 ) , V_349 ) ;
goto V_345;
}
int F_188 ( struct V_1 * V_2 )
{
const struct V_87 * V_88 ;
const struct V_103 * V_104 ;
struct V_7 * V_8 ;
int V_350 ;
struct V_111 * V_111 = F_37 ( V_2 -> V_112 ) ;
if ( V_2 -> V_351 != V_352 )
goto V_353;
F_85 ( V_111 , V_354 ) ;
if ( ! F_70 ( V_2 , sizeof( struct V_103 ) ) )
goto V_353;
V_104 = F_4 ( V_2 ) ;
if ( V_104 -> V_160 < sizeof( struct V_103 ) / 4 )
goto V_355;
if ( ! F_70 ( V_2 , V_104 -> V_160 * 4 ) )
goto V_353;
if ( ! F_189 ( V_2 ) && F_178 ( V_2 ) )
goto V_355;
V_104 = F_4 ( V_2 ) ;
V_88 = F_3 ( V_2 ) ;
F_53 ( V_2 ) -> V_109 = F_46 ( V_104 -> V_109 ) ;
F_53 ( V_2 ) -> V_356 = ( F_53 ( V_2 ) -> V_109 + V_104 -> V_177 + V_104 -> V_178 +
V_2 -> V_113 - V_104 -> V_160 * 4 ) ;
F_53 ( V_2 ) -> V_176 = F_46 ( V_104 -> V_176 ) ;
F_53 ( V_2 ) -> V_141 = 0 ;
F_53 ( V_2 ) -> V_357 = F_190 ( V_88 ) ;
F_53 ( V_2 ) -> V_358 = 0 ;
V_8 = F_191 ( & V_115 , V_2 , V_104 -> V_6 , V_104 -> V_5 ) ;
if ( ! V_8 )
goto V_359;
V_360:
if ( V_8 -> V_91 == V_116 )
goto V_361;
if ( F_45 ( V_88 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_44 ( V_111 , V_121 ) ;
goto V_362;
}
if ( ! F_192 ( V_8 , V_363 , V_2 ) )
goto V_362;
F_193 ( V_2 ) ;
if ( F_194 ( V_8 , V_2 ) )
goto V_362;
V_2 -> V_112 = NULL ;
F_195 ( V_8 ) ;
V_350 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_196
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_364 . V_365 && V_14 -> V_364 . V_366 )
V_14 -> V_364 . V_365 = F_197 () ;
if ( V_14 -> V_364 . V_365 )
V_350 = F_180 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_198 ( V_8 , V_2 ) )
V_350 = F_180 ( V_8 , V_2 ) ;
}
} else if ( F_45 ( F_199 ( V_8 , V_2 ) ) ) {
F_61 ( V_8 ) ;
F_44 ( V_111 , V_367 ) ;
goto V_362;
}
F_61 ( V_8 ) ;
F_62 ( V_8 ) ;
return V_350 ;
V_359:
if ( ! F_192 ( NULL , V_363 , V_2 ) )
goto V_353;
if ( V_2 -> V_113 < ( V_104 -> V_160 << 2 ) || F_184 ( V_2 ) ) {
V_355:
F_85 ( V_111 , V_349 ) ;
} else {
F_71 ( NULL , V_2 ) ;
}
V_353:
F_187 ( V_2 ) ;
return 0 ;
V_362:
F_62 ( V_8 ) ;
goto V_353;
V_361:
if ( ! F_192 ( NULL , V_363 , V_2 ) ) {
F_41 ( F_42 ( V_8 ) ) ;
goto V_353;
}
if ( V_2 -> V_113 < ( V_104 -> V_160 << 2 ) || F_184 ( V_2 ) ) {
F_85 ( V_111 , V_349 ) ;
F_41 ( F_42 ( V_8 ) ) ;
goto V_353;
}
switch ( F_200 ( F_42 ( V_8 ) , V_2 , V_104 ) ) {
case V_368 : {
struct V_7 * V_369 = F_201 ( F_37 ( V_2 -> V_112 ) ,
& V_115 ,
V_88 -> V_3 , V_104 -> V_5 ,
F_40 ( V_2 ) ) ;
if ( V_369 ) {
F_202 ( F_42 ( V_8 ) , & V_65 ) ;
F_41 ( F_42 ( V_8 ) ) ;
V_8 = V_369 ;
goto V_360;
}
}
case V_370 :
F_89 ( V_8 , V_2 ) ;
break;
case V_371 :
goto V_359;
case V_372 : ;
}
goto V_353;
}
struct V_67 * F_203 ( struct V_7 * V_8 , bool * V_373 )
{
struct V_35 * V_36 = (struct V_35 * ) F_204 ( V_8 ) ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_67 * V_68 ;
if ( ! V_36 ||
V_29 -> V_51 . V_52 . V_53 . V_54 . V_3 != V_29 -> V_64 ) {
V_68 = F_205 ( V_29 -> V_64 , 1 ) ;
* V_373 = true ;
} else {
if ( ! V_36 -> V_68 )
F_206 ( V_36 , V_29 -> V_64 , 1 ) ;
V_68 = V_36 -> V_68 ;
* V_373 = false ;
}
return V_68 ;
}
void * F_207 ( struct V_7 * V_8 )
{
const struct V_205 * V_206 = F_42 ( V_8 ) ;
return F_205 ( V_206 -> V_374 , 1 ) ;
}
static int F_208 ( struct V_7 * V_8 )
{
struct V_106 * V_107 = F_23 ( V_8 ) ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_209 ( & V_14 -> V_375 ) ;
F_210 ( V_8 ) ;
F_211 ( V_14 ) ;
V_107 -> V_137 = V_139 ;
V_14 -> V_376 = V_139 ;
V_14 -> V_377 = V_378 ;
V_14 -> V_379 = V_380 ;
V_14 -> V_381 = ~ 0 ;
V_14 -> V_382 = V_77 ;
V_14 -> V_383 = V_384 ;
V_107 -> V_385 = & V_386 ;
V_8 -> V_91 = V_85 ;
V_8 -> V_387 = V_388 ;
F_212 ( V_8 , V_389 ) ;
V_107 -> V_390 = & V_391 ;
V_107 -> V_392 = F_33 ;
#ifdef F_72
V_14 -> V_299 = & V_393 ;
#endif
if ( V_305 > 0 ) {
V_14 -> V_306 =
F_213 ( sizeof( * V_14 -> V_306 ) ,
V_8 -> V_394 ) ;
if ( V_14 -> V_306 != NULL )
F_214 ( & V_14 -> V_306 -> V_395 ) ;
}
V_8 -> V_396 = V_397 [ 1 ] ;
V_8 -> V_398 = V_399 [ 1 ] ;
F_215 () ;
F_216 ( V_8 ) ;
F_217 ( V_8 ) ;
F_218 () ;
return 0 ;
}
void F_219 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_172 ( V_8 ) ;
F_173 ( V_8 ) ;
F_220 ( V_8 ) ;
F_221 ( & V_14 -> V_375 ) ;
#ifdef F_72
if ( V_14 -> V_246 ) {
F_129 ( V_8 ) ;
F_127 ( V_14 -> V_246 , V_262 ) ;
V_14 -> V_246 = NULL ;
}
#endif
#ifdef F_196
F_221 ( & V_8 -> V_400 ) ;
#endif
F_221 ( & V_14 -> V_364 . V_401 ) ;
if ( F_23 ( V_8 ) -> V_402 )
F_222 ( V_8 ) ;
if ( V_8 -> V_403 ) {
F_223 ( V_8 -> V_403 ) ;
V_8 -> V_403 = NULL ;
}
if ( V_14 -> V_306 != NULL ) {
F_224 ( & V_14 -> V_306 -> V_395 ,
V_404 ) ;
V_14 -> V_306 = NULL ;
}
F_225 ( V_8 ) ;
F_226 ( V_8 ) ;
}
static inline struct V_205 * F_227 ( struct V_405 * V_158 )
{
return F_228 ( V_158 ) ? NULL :
F_229 ( V_158 -> V_406 , struct V_205 , V_407 ) ;
}
static inline struct V_205 * F_230 ( struct V_205 * V_206 )
{
return ! F_231 ( V_206 -> V_407 . V_408 ) ?
F_232 ( V_206 -> V_407 . V_408 , F_233 ( * V_206 ) , V_407 ) : NULL ;
}
static void * F_234 ( struct V_409 * V_109 , void * V_410 )
{
struct V_106 * V_107 ;
struct V_411 * V_259 ;
struct V_7 * V_8 = V_410 ;
struct V_412 * V_413 ;
struct V_414 * V_415 = V_109 -> V_416 ;
struct V_111 * V_111 = F_235 ( V_109 ) ;
if ( ! V_8 ) {
V_413 = & V_115 . V_417 [ V_415 -> V_418 ] ;
F_236 ( & V_413 -> V_419 ) ;
V_8 = F_237 ( & V_413 -> V_158 ) ;
V_415 -> V_204 = 0 ;
goto V_420;
}
V_413 = & V_115 . V_417 [ V_415 -> V_418 ] ;
++ V_415 -> V_421 ;
++ V_415 -> V_204 ;
if ( V_415 -> V_422 == V_423 ) {
struct V_146 * V_147 = V_410 ;
V_107 = F_23 ( V_415 -> V_424 ) ;
V_147 = V_147 -> V_425 ;
while ( 1 ) {
while ( V_147 ) {
if ( V_147 -> V_426 -> V_239 == V_415 -> V_239 ) {
V_410 = V_147 ;
goto V_118;
}
V_147 = V_147 -> V_425 ;
}
if ( ++ V_415 -> V_427 >= V_107 -> V_231 . V_232 -> V_428 )
break;
V_429:
V_147 = V_107 -> V_231 . V_232 -> V_430 [ V_415 -> V_427 ] ;
}
V_8 = F_238 ( V_415 -> V_424 ) ;
V_415 -> V_422 = V_431 ;
F_239 ( & V_107 -> V_231 . V_432 ) ;
} else {
V_107 = F_23 ( V_8 ) ;
F_240 ( & V_107 -> V_231 . V_432 ) ;
if ( F_241 ( & V_107 -> V_231 ) )
goto V_433;
F_239 ( & V_107 -> V_231 . V_432 ) ;
V_8 = F_238 ( V_8 ) ;
}
V_420:
F_242 (sk, node) {
if ( ! F_243 ( F_19 ( V_8 ) , V_111 ) )
continue;
if ( V_8 -> V_434 == V_415 -> V_239 ) {
V_410 = V_8 ;
goto V_118;
}
V_107 = F_23 ( V_8 ) ;
F_240 ( & V_107 -> V_231 . V_432 ) ;
if ( F_241 ( & V_107 -> V_231 ) ) {
V_433:
V_415 -> V_435 = F_244 ( V_8 ) ;
V_415 -> V_424 = V_8 ;
V_415 -> V_422 = V_423 ;
V_415 -> V_427 = 0 ;
goto V_429;
}
F_239 ( & V_107 -> V_231 . V_432 ) ;
}
F_245 ( & V_413 -> V_419 ) ;
V_415 -> V_204 = 0 ;
if ( ++ V_415 -> V_418 < V_436 ) {
V_413 = & V_115 . V_417 [ V_415 -> V_418 ] ;
F_236 ( & V_413 -> V_419 ) ;
V_8 = F_237 ( & V_413 -> V_158 ) ;
goto V_420;
}
V_410 = NULL ;
V_118:
return V_410 ;
}
static void * F_246 ( struct V_409 * V_109 , T_9 * V_241 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
void * V_437 ;
V_415 -> V_418 = 0 ;
V_415 -> V_204 = 0 ;
V_437 = F_234 ( V_109 , NULL ) ;
while ( V_437 && * V_241 ) {
V_437 = F_234 ( V_109 , V_437 ) ;
-- * V_241 ;
}
return V_437 ;
}
static inline int F_247 ( struct V_414 * V_415 )
{
return F_228 ( & V_115 . V_438 [ V_415 -> V_418 ] . V_439 ) &&
F_228 ( & V_115 . V_438 [ V_415 -> V_418 ] . V_440 ) ;
}
static void * F_248 ( struct V_409 * V_109 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
struct V_111 * V_111 = F_235 ( V_109 ) ;
void * V_437 = NULL ;
V_415 -> V_204 = 0 ;
for (; V_415 -> V_418 <= V_115 . V_441 ; ++ V_415 -> V_418 ) {
struct V_7 * V_8 ;
struct V_411 * V_259 ;
struct V_205 * V_206 ;
T_10 * V_419 = F_249 ( & V_115 , V_415 -> V_418 ) ;
if ( F_247 ( V_415 ) )
continue;
F_236 ( V_419 ) ;
F_250 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_434 != V_415 -> V_239 ||
! F_243 ( F_19 ( V_8 ) , V_111 ) ) {
continue;
}
V_437 = V_8 ;
goto V_118;
}
V_415 -> V_422 = V_442 ;
F_251 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_206 -> V_443 != V_415 -> V_239 ||
! F_243 ( F_252 ( V_206 ) , V_111 ) ) {
continue;
}
V_437 = V_206 ;
goto V_118;
}
F_245 ( V_419 ) ;
V_415 -> V_422 = V_444 ;
}
V_118:
return V_437 ;
}
static void * F_253 ( struct V_409 * V_109 , void * V_410 )
{
struct V_7 * V_8 = V_410 ;
struct V_205 * V_206 ;
struct V_411 * V_259 ;
struct V_414 * V_415 = V_109 -> V_416 ;
struct V_111 * V_111 = F_235 ( V_109 ) ;
++ V_415 -> V_421 ;
++ V_415 -> V_204 ;
if ( V_415 -> V_422 == V_442 ) {
V_206 = V_410 ;
V_206 = F_230 ( V_206 ) ;
V_445:
while ( V_206 && ( V_206 -> V_443 != V_415 -> V_239 || ! F_243 ( F_252 ( V_206 ) , V_111 ) ) ) {
V_206 = F_230 ( V_206 ) ;
}
if ( V_206 ) {
V_410 = V_206 ;
goto V_118;
}
F_245 ( F_249 ( & V_115 , V_415 -> V_418 ) ) ;
V_415 -> V_422 = V_444 ;
V_415 -> V_204 = 0 ;
while ( ++ V_415 -> V_418 <= V_115 . V_441 &&
F_247 ( V_415 ) )
;
if ( V_415 -> V_418 > V_115 . V_441 )
return NULL ;
F_236 ( F_249 ( & V_115 , V_415 -> V_418 ) ) ;
V_8 = F_237 ( & V_115 . V_438 [ V_415 -> V_418 ] . V_439 ) ;
} else
V_8 = F_238 ( V_8 ) ;
F_242 (sk, node) {
if ( V_8 -> V_434 == V_415 -> V_239 && F_243 ( F_19 ( V_8 ) , V_111 ) )
goto V_446;
}
V_415 -> V_422 = V_442 ;
V_206 = F_227 ( & V_115 . V_438 [ V_415 -> V_418 ] . V_440 ) ;
goto V_445;
V_446:
V_410 = V_8 ;
V_118:
return V_410 ;
}
static void * F_254 ( struct V_409 * V_109 , T_9 V_241 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
void * V_437 ;
V_415 -> V_418 = 0 ;
V_437 = F_248 ( V_109 ) ;
while ( V_437 && V_241 ) {
V_437 = F_253 ( V_109 , V_437 ) ;
-- V_241 ;
}
return V_437 ;
}
static void * F_255 ( struct V_409 * V_109 , T_9 V_241 )
{
void * V_437 ;
struct V_414 * V_415 = V_109 -> V_416 ;
V_415 -> V_422 = V_431 ;
V_437 = F_246 ( V_109 , & V_241 ) ;
if ( ! V_437 ) {
V_415 -> V_422 = V_444 ;
V_437 = F_254 ( V_109 , V_241 ) ;
}
return V_437 ;
}
static void * F_256 ( struct V_409 * V_109 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
int V_204 = V_415 -> V_204 ;
int V_447 = V_415 -> V_421 ;
void * V_437 = NULL ;
switch ( V_415 -> V_422 ) {
case V_423 :
case V_431 :
if ( V_415 -> V_418 >= V_436 )
break;
V_415 -> V_422 = V_431 ;
V_437 = F_234 ( V_109 , NULL ) ;
while ( V_204 -- && V_437 )
V_437 = F_234 ( V_109 , V_437 ) ;
if ( V_437 )
break;
V_415 -> V_418 = 0 ;
case V_444 :
case V_442 :
V_415 -> V_422 = V_444 ;
if ( V_415 -> V_418 > V_115 . V_441 )
break;
V_437 = F_248 ( V_109 ) ;
while ( V_204 -- && V_437 )
V_437 = F_253 ( V_109 , V_437 ) ;
}
V_415 -> V_421 = V_447 ;
return V_437 ;
}
static void * F_257 ( struct V_409 * V_109 , T_9 * V_241 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
void * V_437 ;
if ( * V_241 && * V_241 == V_415 -> V_448 ) {
V_437 = F_256 ( V_109 ) ;
if ( V_437 )
goto V_118;
}
V_415 -> V_422 = V_431 ;
V_415 -> V_421 = 0 ;
V_415 -> V_418 = 0 ;
V_415 -> V_204 = 0 ;
V_437 = * V_241 ? F_255 ( V_109 , * V_241 - 1 ) : V_449 ;
V_118:
V_415 -> V_448 = * V_241 ;
return V_437 ;
}
static void * F_258 ( struct V_409 * V_109 , void * V_450 , T_9 * V_241 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
void * V_437 = NULL ;
if ( V_450 == V_449 ) {
V_437 = F_255 ( V_109 , 0 ) ;
goto V_118;
}
switch ( V_415 -> V_422 ) {
case V_423 :
case V_431 :
V_437 = F_234 ( V_109 , V_450 ) ;
if ( ! V_437 ) {
V_415 -> V_422 = V_444 ;
V_415 -> V_418 = 0 ;
V_415 -> V_204 = 0 ;
V_437 = F_248 ( V_109 ) ;
}
break;
case V_444 :
case V_442 :
V_437 = F_253 ( V_109 , V_450 ) ;
break;
}
V_118:
++ * V_241 ;
V_415 -> V_448 = * V_241 ;
return V_437 ;
}
static void F_259 ( struct V_409 * V_109 , void * V_450 )
{
struct V_414 * V_415 = V_109 -> V_416 ;
switch ( V_415 -> V_422 ) {
case V_423 :
if ( V_450 ) {
struct V_106 * V_107 = F_23 ( V_415 -> V_424 ) ;
F_239 ( & V_107 -> V_231 . V_432 ) ;
}
case V_431 :
if ( V_450 != V_449 )
F_245 ( & V_115 . V_417 [ V_415 -> V_418 ] . V_419 ) ;
break;
case V_442 :
case V_444 :
if ( V_450 )
F_245 ( F_249 ( & V_115 , V_415 -> V_418 ) ) ;
break;
}
}
int F_260 ( struct V_451 * V_451 , struct V_452 * V_452 )
{
struct V_453 * V_454 = F_261 ( V_451 ) -> V_102 ;
struct V_414 * V_455 ;
int V_37 ;
V_37 = F_262 ( V_451 , V_452 , & V_454 -> V_456 ,
sizeof( struct V_414 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_455 = ( (struct V_409 * ) V_452 -> V_457 ) -> V_416 ;
V_455 -> V_239 = V_454 -> V_239 ;
V_455 -> V_448 = 0 ;
return 0 ;
}
int F_263 ( struct V_111 * V_111 , struct V_453 * V_454 )
{
int V_437 = 0 ;
struct V_458 * V_459 ;
V_454 -> V_456 . V_460 = F_257 ;
V_454 -> V_456 . V_408 = F_258 ;
V_454 -> V_456 . V_461 = F_259 ;
V_459 = F_264 ( V_454 -> V_462 , V_463 , V_111 -> V_464 ,
V_454 -> V_465 , V_454 ) ;
if ( ! V_459 )
V_437 = - V_257 ;
return V_437 ;
}
void F_265 ( struct V_111 * V_111 , struct V_453 * V_454 )
{
F_266 ( V_111 , V_454 -> V_462 ) ;
}
static void F_267 ( const struct V_7 * V_8 , const struct V_146 * V_147 ,
struct V_409 * V_466 , int V_467 , int V_435 , int * V_113 )
{
const struct V_218 * V_219 = F_92 ( V_147 ) ;
int V_468 = V_147 -> V_469 - V_84 ;
F_268 ( V_466 , L_9
L_10 ,
V_467 ,
V_219 -> V_220 ,
F_78 ( F_11 ( V_8 ) -> V_49 ) ,
V_219 -> V_221 ,
F_78 ( V_219 -> V_470 ) ,
V_150 ,
0 , 0 ,
1 ,
F_269 ( V_468 ) ,
V_147 -> V_338 ,
V_435 ,
0 ,
0 ,
F_270 ( & V_8 -> V_471 ) ,
V_147 ,
V_113 ) ;
}
static void F_271 ( struct V_7 * V_8 , struct V_409 * V_466 , int V_467 , int * V_113 )
{
int V_472 ;
unsigned long V_473 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_106 * V_107 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_474 = V_29 -> V_63 ;
T_11 V_475 = F_78 ( V_29 -> V_73 ) ;
T_11 V_476 = F_78 ( V_29 -> V_49 ) ;
int V_477 ;
if ( V_107 -> V_478 == V_142 ) {
V_472 = 1 ;
V_473 = V_107 -> V_479 ;
} else if ( V_107 -> V_478 == V_480 ) {
V_472 = 4 ;
V_473 = V_107 -> V_479 ;
} else if ( F_272 ( & V_8 -> V_481 ) ) {
V_472 = 2 ;
V_473 = V_8 -> V_481 . V_469 ;
} else {
V_472 = 0 ;
V_473 = V_84 ;
}
if ( V_8 -> V_91 == V_92 )
V_477 = V_8 -> V_482 ;
else
V_477 = F_273 ( int , V_14 -> V_483 - V_14 -> V_484 , 0 ) ;
F_268 ( V_466 , L_11
L_12 ,
V_467 , V_474 , V_476 , V_5 , V_475 , V_8 -> V_91 ,
V_14 -> V_17 - V_14 -> V_122 ,
V_477 ,
V_472 ,
F_269 ( V_473 - V_84 ) ,
V_107 -> V_135 ,
F_244 ( V_8 ) ,
V_107 -> V_485 ,
F_274 ( V_8 ) ,
F_270 ( & V_8 -> V_471 ) , V_8 ,
F_269 ( V_107 -> V_137 ) ,
F_269 ( V_107 -> V_486 . V_487 ) ,
( V_107 -> V_486 . V_488 << 1 ) | V_107 -> V_486 . V_489 ,
V_14 -> V_377 ,
F_275 ( V_14 ) ? - 1 : V_14 -> V_379 ,
V_113 ) ;
}
static void F_276 ( const struct V_205 * V_206 ,
struct V_409 * V_466 , int V_467 , int * V_113 )
{
T_3 V_5 , V_474 ;
T_11 V_475 , V_476 ;
int V_468 = V_206 -> V_490 - V_84 ;
if ( V_468 < 0 )
V_468 = 0 ;
V_5 = V_206 -> V_374 ;
V_474 = V_206 -> V_491 ;
V_475 = F_78 ( V_206 -> V_492 ) ;
V_476 = F_78 ( V_206 -> V_493 ) ;
F_268 ( V_466 , L_9
L_13 ,
V_467 , V_474 , V_476 , V_5 , V_475 , V_206 -> V_494 , 0 , 0 ,
3 , F_269 ( V_468 ) , 0 , 0 , 0 , 0 ,
F_270 ( & V_206 -> V_495 ) , V_206 , V_113 ) ;
}
static int F_277 ( struct V_409 * V_109 , void * V_450 )
{
struct V_414 * V_415 ;
int V_113 ;
if ( V_450 == V_449 ) {
F_268 ( V_109 , L_14 , V_496 - 1 ,
L_15
L_16
L_17 ) ;
goto V_118;
}
V_415 = V_109 -> V_416 ;
switch ( V_415 -> V_422 ) {
case V_431 :
case V_444 :
F_271 ( V_450 , V_109 , V_415 -> V_421 , & V_113 ) ;
break;
case V_423 :
F_267 ( V_415 -> V_424 , V_450 , V_109 , V_415 -> V_421 , V_415 -> V_435 , & V_113 ) ;
break;
case V_442 :
F_276 ( V_450 , V_109 , V_415 -> V_421 , & V_113 ) ;
break;
}
F_268 ( V_109 , L_18 , V_496 - 1 - V_113 , L_6 ) ;
V_118:
return 0 ;
}
static int T_12 F_278 ( struct V_111 * V_111 )
{
return F_263 ( V_111 , & V_497 ) ;
}
static void T_13 F_279 ( struct V_111 * V_111 )
{
F_265 ( V_111 , & V_497 ) ;
}
int T_14 F_280 ( void )
{
return F_281 ( & V_498 ) ;
}
void F_282 ( void )
{
F_283 ( & V_498 ) ;
}
struct V_1 * * F_284 ( struct V_1 * * V_158 , struct V_1 * V_2 )
{
const struct V_87 * V_88 = F_285 ( V_2 ) ;
switch ( V_2 -> V_154 ) {
case V_342 :
if ( ! F_64 ( F_286 ( V_2 ) , V_88 -> V_4 , V_88 -> V_3 ,
V_2 -> V_161 ) ) {
V_2 -> V_154 = V_343 ;
break;
}
case V_499 :
F_287 ( V_2 ) -> V_500 = 1 ;
return NULL ;
}
return F_288 ( V_158 , V_2 ) ;
}
int F_289 ( struct V_1 * V_2 )
{
const struct V_87 * V_88 = F_3 ( V_2 ) ;
struct V_103 * V_104 = F_4 ( V_2 ) ;
V_104 -> V_156 = ~ F_64 ( V_2 -> V_113 - F_290 ( V_2 ) ,
V_88 -> V_4 , V_88 -> V_3 , 0 ) ;
F_291 ( V_2 ) -> V_501 = V_81 ;
return F_292 ( V_2 ) ;
}
static int T_12 F_293 ( struct V_111 * V_111 )
{
return F_294 ( & V_111 -> V_193 . V_13 ,
V_502 , V_503 , V_57 , V_111 ) ;
}
static void T_13 F_295 ( struct V_111 * V_111 )
{
F_296 ( V_111 -> V_193 . V_13 ) ;
}
static void T_13 F_297 ( struct V_504 * V_505 )
{
F_298 ( & V_115 , & V_65 , V_42 ) ;
}
void T_14 F_299 ( void )
{
F_300 ( & V_115 ) ;
if ( F_281 ( & V_506 ) )
F_301 ( L_19 ) ;
}
