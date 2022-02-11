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
F_23 ( V_8 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_8 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_14 -> V_19 . V_72 = V_73 ;
F_24 ( V_8 , V_74 ) ;
V_37 = F_25 ( & V_66 , V_8 ) ;
if ( V_37 )
goto V_75;
V_36 = F_26 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_69 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
V_36 = NULL ;
goto V_75;
}
V_8 -> V_76 = V_77 ;
F_27 ( V_8 , & V_36 -> V_68 ) ;
if ( ! V_14 -> V_17 && F_21 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_64 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_78 = V_14 -> V_17 ^ V_79 ;
V_37 = F_28 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_75;
return 0 ;
V_75:
F_24 ( V_8 , V_80 ) ;
F_20 ( V_36 ) ;
V_8 -> V_81 = 0 ;
V_29 -> V_69 = 0 ;
return V_37 ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_82 * V_68 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
T_4 V_83 = F_7 ( V_8 ) -> V_84 ;
V_68 = F_30 ( V_8 , V_83 ) ;
if ( ! V_68 )
return;
if ( V_83 < F_31 ( V_68 ) && F_32 ( V_8 , V_68 ) )
V_8 -> V_85 = V_86 ;
V_83 = F_31 ( V_68 ) ;
if ( V_29 -> V_87 != V_88 &&
F_33 ( V_8 ) &&
F_23 ( V_8 ) -> V_89 > V_83 ) {
F_34 ( V_8 , V_83 ) ;
F_35 ( V_8 ) ;
}
}
static void F_36 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_82 * V_68 = F_37 ( V_8 , 0 ) ;
if ( V_68 )
V_68 -> V_90 -> V_91 ( V_68 , V_8 , V_2 ) ;
}
void F_38 ( struct V_1 * V_92 , T_4 V_93 )
{
const struct V_94 * V_95 = ( const struct V_94 * ) V_92 -> V_96 ;
struct V_97 * V_98 = (struct V_97 * ) ( V_92 -> V_96 + ( V_95 -> V_99 << 2 ) ) ;
struct V_100 * V_101 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_39 ( V_92 ) -> type ;
const int V_102 = F_39 ( V_92 ) -> V_102 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
T_1 V_105 , V_106 ;
T_1 V_107 ;
int V_37 ;
struct V_108 * V_108 = F_40 ( V_92 -> V_109 ) ;
if ( V_92 -> V_110 < ( V_95 -> V_99 << 2 ) + 8 ) {
F_41 ( V_108 , V_111 ) ;
return;
}
V_8 = F_42 ( V_108 , & V_112 , V_95 -> V_3 , V_98 -> V_5 ,
V_95 -> V_4 , V_98 -> V_6 , F_43 ( V_92 ) ) ;
if ( ! V_8 ) {
F_41 ( V_108 , V_111 ) ;
return;
}
if ( V_8 -> V_113 == V_114 ) {
F_44 ( F_45 ( V_8 ) ) ;
return;
}
F_46 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_115 && V_102 == V_116 ) )
F_47 ( V_108 , V_117 ) ;
}
if ( V_8 -> V_113 == V_80 )
goto V_118;
if ( F_48 ( V_95 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_47 ( V_108 , V_121 ) ;
goto V_118;
}
V_101 = F_23 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_105 = F_49 ( V_98 -> V_105 ) ;
V_104 = V_14 -> V_122 ;
V_106 = V_104 ? F_50 ( V_104 ) -> V_123 : V_14 -> V_106 ;
if ( V_8 -> V_113 != V_124 &&
! F_51 ( V_105 , V_106 , V_14 -> V_125 ) ) {
F_47 ( V_108 , V_126 ) ;
goto V_118;
}
switch ( type ) {
case V_127 :
F_36 ( V_92 , V_8 ) ;
goto V_118;
case V_128 :
goto V_118;
case V_129 :
V_37 = V_130 ;
break;
case V_115 :
if ( V_102 > V_131 )
goto V_118;
if ( V_102 == V_116 ) {
if ( V_8 -> V_113 == V_124 )
goto V_118;
V_14 -> V_84 = V_93 ;
if ( ! F_13 ( V_8 ) ) {
F_29 ( V_8 ) ;
} else {
if ( ! F_52 ( V_132 , & V_14 -> V_133 ) )
F_9 ( V_8 ) ;
}
goto V_118;
}
V_37 = V_134 [ V_102 ] . V_135 ;
if ( V_102 != V_136 && V_102 != V_137 )
break;
if ( V_105 != V_14 -> V_106 || ! V_101 -> V_138 ||
! V_101 -> V_139 || V_104 )
break;
if ( F_13 ( V_8 ) )
break;
V_101 -> V_139 -- ;
F_23 ( V_8 ) -> V_140 = ( V_14 -> V_141 ? F_53 ( V_14 ) :
V_142 ) << V_101 -> V_139 ;
F_54 ( V_8 ) ;
V_2 = F_55 ( V_8 ) ;
F_56 ( ! V_2 ) ;
V_107 = V_101 -> V_140 - F_57 ( V_101 -> V_140 ,
V_143 - F_58 ( V_2 ) -> V_144 ) ;
if ( V_107 ) {
F_59 ( V_8 , V_145 ,
V_107 , V_146 ) ;
} else {
F_60 ( V_8 ) ;
}
break;
case V_147 :
V_37 = V_148 ;
break;
default:
goto V_118;
}
switch ( V_8 -> V_113 ) {
struct V_103 * V_149 , * * V_150 ;
case V_124 :
if ( F_13 ( V_8 ) )
goto V_118;
V_149 = F_61 ( V_8 , & V_150 , V_98 -> V_5 ,
V_95 -> V_3 , V_95 -> V_4 ) ;
if ( ! V_149 )
goto V_118;
F_62 ( V_149 -> V_8 ) ;
if ( V_105 != F_50 ( V_149 ) -> V_123 ) {
F_47 ( V_108 , V_126 ) ;
goto V_118;
}
F_63 ( V_8 , V_149 , V_150 ) ;
F_47 ( F_19 ( V_8 ) , V_151 ) ;
goto V_118;
case V_74 :
case V_152 :
if ( V_104 && V_104 -> V_8 == NULL )
break;
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_153 = V_37 ;
V_8 -> V_154 ( V_8 ) ;
F_64 ( V_8 ) ;
} else {
V_8 -> V_85 = V_37 ;
}
goto V_118;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_155 ) {
V_8 -> V_153 = V_37 ;
V_8 -> V_154 ( V_8 ) ;
} else {
V_8 -> V_85 = V_37 ;
}
V_118:
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
}
void F_67 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
if ( V_2 -> V_156 == V_157 ) {
V_98 -> V_158 = ~ F_68 ( V_2 -> V_110 , V_4 , V_3 , 0 ) ;
V_2 -> V_159 = F_69 ( V_2 ) - V_2 -> V_160 ;
V_2 -> V_161 = F_70 ( struct V_97 , V_158 ) ;
} else {
V_98 -> V_158 = F_68 ( V_2 -> V_110 , V_4 , V_3 ,
F_71 ( V_98 ,
V_98 -> V_162 << 2 ,
V_2 -> V_163 ) ) ;
}
}
void F_72 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_67 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
static void F_73 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
#ifdef F_74
T_3 V_46 [ ( V_164 >> 2 ) ] ;
#endif
} V_165 ;
struct V_166 V_167 ;
#ifdef F_74
struct V_168 * V_169 ;
const T_5 * V_170 = NULL ;
unsigned char V_171 [ 16 ] ;
int V_172 ;
struct V_7 * V_173 = NULL ;
#endif
struct V_108 * V_108 ;
if ( V_98 -> V_174 )
return;
if ( F_75 ( V_2 ) -> V_175 != V_176 )
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
V_165 . V_98 . V_178 = F_76 ( F_49 ( V_98 -> V_105 ) + V_98 -> V_179 + V_98 -> V_180 +
V_2 -> V_110 - ( V_98 -> V_162 << 2 ) ) ;
}
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_181 [ 0 ] . V_182 = ( unsigned char * ) & V_165 ;
V_167 . V_181 [ 0 ] . V_183 = sizeof( V_165 . V_98 ) ;
#ifdef F_74
V_170 = F_77 ( V_98 ) ;
if ( ! V_8 && V_170 ) {
V_173 = F_78 ( F_40 ( F_79 ( V_2 ) -> V_109 ) ,
& V_112 , F_3 ( V_2 ) -> V_4 ,
V_98 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_80 ( V_98 -> V_6 ) , F_43 ( V_2 ) ) ;
if ( ! V_173 )
return;
F_81 () ;
V_169 = F_82 ( V_173 , (union V_184 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_169 )
goto V_185;
V_172 = F_83 ( V_171 , V_169 , NULL , NULL , V_2 ) ;
if ( V_172 || memcmp ( V_170 , V_171 , 16 ) != 0 )
goto V_185;
} else {
V_169 = V_8 ? F_82 ( V_8 , (union V_184 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_169 ) {
V_165 . V_46 [ 0 ] = F_76 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_164 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
F_84 ( ( T_5 * ) & V_165 . V_46 [ 1 ] ,
V_169 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 . V_98 ) ;
}
#endif
V_167 . V_163 = F_85 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_167 . V_181 [ 0 ] . V_183 , V_57 , 0 ) ;
V_167 . V_189 = F_70 ( struct V_97 , V_158 ) / 2 ;
V_167 . V_190 = ( V_8 && F_11 ( V_8 ) -> V_191 ) ? V_192 : 0 ;
if ( V_8 )
V_167 . V_193 = V_8 -> V_56 ;
V_108 = F_40 ( F_79 ( V_2 ) -> V_109 ) ;
V_167 . V_194 = F_3 ( V_2 ) -> V_194 ;
F_86 ( V_108 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 , V_167 . V_181 [ 0 ] . V_183 ) ;
F_87 ( V_108 , V_195 ) ;
F_87 ( V_108 , V_196 ) ;
#ifdef F_74
V_185:
if ( V_173 ) {
F_88 () ;
F_66 ( V_173 ) ;
}
#endif
}
static void F_89 ( struct V_1 * V_2 , T_4 V_105 , T_4 V_177 ,
T_4 V_197 , T_4 V_198 , T_4 V_199 , int V_200 ,
struct V_168 * V_169 ,
int V_201 , T_6 V_194 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
T_3 V_46 [ ( V_202 >> 2 )
#ifdef F_74
+ ( V_164 >> 2 )
#endif
] ;
} V_165 ;
struct V_166 V_167 ;
struct V_108 * V_108 = F_40 ( F_79 ( V_2 ) -> V_109 ) ;
memset ( & V_165 . V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_181 [ 0 ] . V_182 = ( unsigned char * ) & V_165 ;
V_167 . V_181 [ 0 ] . V_183 = sizeof( V_165 . V_98 ) ;
if ( V_199 ) {
V_165 . V_46 [ 0 ] = F_76 ( ( V_186 << 24 ) | ( V_186 << 16 ) |
( V_203 << 8 ) |
V_204 ) ;
V_165 . V_46 [ 1 ] = F_76 ( V_198 ) ;
V_165 . V_46 [ 2 ] = F_76 ( V_199 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_202 ;
}
V_165 . V_98 . V_5 = V_98 -> V_6 ;
V_165 . V_98 . V_6 = V_98 -> V_5 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
V_165 . V_98 . V_105 = F_76 ( V_105 ) ;
V_165 . V_98 . V_178 = F_76 ( V_177 ) ;
V_165 . V_98 . V_177 = 1 ;
V_165 . V_98 . V_205 = F_90 ( V_197 ) ;
#ifdef F_74
if ( V_169 ) {
int V_206 = ( V_199 ) ? 3 : 0 ;
V_165 . V_46 [ V_206 ++ ] = F_76 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_167 . V_181 [ 0 ] . V_183 += V_164 ;
V_165 . V_98 . V_162 = V_167 . V_181 [ 0 ] . V_183 / 4 ;
F_84 ( ( T_5 * ) & V_165 . V_46 [ V_206 ] ,
V_169 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 . V_98 ) ;
}
#endif
V_167 . V_190 = V_201 ;
V_167 . V_163 = F_85 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_167 . V_181 [ 0 ] . V_183 , V_57 , 0 ) ;
V_167 . V_189 = F_70 ( struct V_97 , V_158 ) / 2 ;
if ( V_200 )
V_167 . V_193 = V_200 ;
V_167 . V_194 = V_194 ;
F_86 ( V_108 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 , V_167 . V_181 [ 0 ] . V_183 ) ;
F_87 ( V_108 , V_195 ) ;
}
static void F_91 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_207 * V_208 = F_45 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_89 ( V_2 , V_12 -> V_18 , V_12 -> V_209 ,
V_12 -> V_210 >> V_208 -> V_211 ,
V_143 + V_12 -> V_212 ,
V_12 -> V_21 ,
V_208 -> V_213 ,
F_92 ( V_12 ) ,
V_208 -> V_214 ? V_192 : 0 ,
V_208 -> V_215
) ;
F_44 ( V_208 ) ;
}
static void F_93 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_149 )
{
F_89 ( V_2 , ( V_8 -> V_113 == V_124 ) ?
F_50 ( V_149 ) -> V_123 + 1 : F_7 ( V_8 ) -> V_125 ,
F_50 ( V_149 ) -> V_216 , V_149 -> V_217 ,
V_143 ,
V_149 -> V_20 ,
0 ,
F_82 ( V_8 , (union V_184 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_94 ( V_149 ) -> V_218 ? V_192 : 0 ,
F_3 ( V_2 ) -> V_194 ) ;
}
static int F_95 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_103 * V_149 ,
T_7 V_219 ,
struct V_220 * V_221 )
{
const struct V_222 * V_223 = F_94 ( V_149 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_96 ( V_8 , & V_34 , V_149 ) ) == NULL )
return - 1 ;
V_2 = F_97 ( V_8 , V_68 , V_149 , V_221 ) ;
if ( V_2 ) {
F_67 ( V_2 , V_223 -> V_224 , V_223 -> V_225 ) ;
F_98 ( V_2 , V_219 ) ;
V_37 = F_99 ( V_2 , V_8 , V_223 -> V_224 ,
V_223 -> V_225 ,
V_223 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( ! F_50 ( V_149 ) -> V_226 && ! V_37 )
F_50 ( V_149 ) -> V_226 = V_143 ;
}
return V_37 ;
}
static int F_101 ( struct V_7 * V_8 , struct V_103 * V_149 )
{
int V_227 = F_95 ( V_8 , NULL , V_149 , 0 , NULL ) ;
if ( ! V_227 ) {
F_87 ( F_19 ( V_8 ) , V_228 ) ;
F_47 ( F_19 ( V_8 ) , V_229 ) ;
}
return V_227 ;
}
static void F_102 ( struct V_103 * V_149 )
{
F_103 ( F_94 ( V_149 ) -> V_46 ) ;
}
bool F_104 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_230 )
{
const char * V_231 = L_1 ;
bool V_232 = false ;
struct V_233 * V_234 ;
#ifdef F_105
if ( V_235 ) {
V_231 = L_2 ;
V_232 = true ;
F_47 ( F_19 ( V_8 ) , V_236 ) ;
} else
#endif
F_47 ( F_19 ( V_8 ) , V_237 ) ;
V_234 = F_23 ( V_8 ) -> V_238 . V_239 ;
if ( ! V_234 -> V_240 && V_235 != 2 ) {
V_234 -> V_240 = 1 ;
F_106 ( L_3 ,
V_230 , F_80 ( F_4 ( V_2 ) -> V_5 ) , V_231 ) ;
}
return V_232 ;
}
static struct V_38 * F_107 ( struct V_1 * V_2 )
{
const struct V_241 * V_46 = & ( F_108 ( V_2 ) -> V_46 ) ;
struct V_38 * V_242 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_243 = sizeof( * V_242 ) + V_46 -> V_71 ;
V_242 = F_109 ( V_243 , V_244 ) ;
if ( V_242 ) {
if ( F_110 ( & V_242 -> V_46 , V_2 ) ) {
F_103 ( V_242 ) ;
V_242 = NULL ;
}
}
}
return V_242 ;
}
struct V_168 * F_82 ( struct V_7 * V_8 ,
const union V_184 * V_245 ,
int V_246 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_168 * V_169 ;
unsigned int V_247 = sizeof( struct V_248 ) ;
struct V_249 * V_250 ;
V_250 = F_111 ( V_14 -> V_251 ,
F_13 ( V_8 ) ||
F_112 ( & V_8 -> V_252 . V_253 ) ) ;
if ( ! V_250 )
return NULL ;
#if F_113 ( V_254 )
if ( V_246 == V_255 )
V_247 = sizeof( struct V_256 ) ;
#endif
F_114 (key, &md5sig->head, node) {
if ( V_169 -> V_246 != V_246 )
continue;
if ( ! memcmp ( & V_169 -> V_245 , V_245 , V_247 ) )
return V_169 ;
}
return NULL ;
}
struct V_168 * F_115 ( struct V_7 * V_8 ,
struct V_7 * V_257 )
{
union V_184 * V_245 ;
V_245 = (union V_184 * ) & F_11 ( V_257 ) -> V_64 ;
return F_82 ( V_8 , V_245 , V_42 ) ;
}
static struct V_168 * F_116 ( struct V_7 * V_8 ,
struct V_103 * V_149 )
{
union V_184 * V_245 ;
V_245 = (union V_184 * ) & F_94 ( V_149 ) -> V_225 ;
return F_82 ( V_8 , V_245 , V_42 ) ;
}
int F_117 ( struct V_7 * V_8 , const union V_184 * V_245 ,
int V_246 , const T_6 * V_258 , T_6 V_259 , T_8 V_260 )
{
struct V_168 * V_169 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_249 * V_250 ;
V_169 = F_82 ( V_8 , V_245 , V_246 ) ;
if ( V_169 ) {
memcpy ( V_169 -> V_169 , V_258 , V_259 ) ;
V_169 -> V_261 = V_259 ;
return 0 ;
}
V_250 = F_12 ( V_14 -> V_251 ,
F_13 ( V_8 ) ) ;
if ( ! V_250 ) {
V_250 = F_109 ( sizeof( * V_250 ) , V_260 ) ;
if ( ! V_250 )
return - V_262 ;
F_118 ( V_8 , V_263 ) ;
F_119 ( & V_250 -> V_160 ) ;
F_120 ( V_14 -> V_251 , V_250 ) ;
}
V_169 = F_121 ( V_8 , sizeof( * V_169 ) , V_260 ) ;
if ( ! V_169 )
return - V_262 ;
if ( ! F_122 () ) {
F_123 ( V_8 , V_169 , sizeof( * V_169 ) ) ;
return - V_262 ;
}
memcpy ( V_169 -> V_169 , V_258 , V_259 ) ;
V_169 -> V_261 = V_259 ;
V_169 -> V_246 = V_246 ;
memcpy ( & V_169 -> V_245 , V_245 ,
( V_246 == V_255 ) ? sizeof( struct V_256 ) :
sizeof( struct V_248 ) ) ;
F_124 ( & V_169 -> V_264 , & V_250 -> V_160 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_8 , const union V_184 * V_245 , int V_246 )
{
struct V_168 * V_169 ;
V_169 = F_82 ( V_8 , V_245 , V_246 ) ;
if ( ! V_169 )
return - V_265 ;
F_126 ( & V_169 -> V_264 ) ;
F_127 ( sizeof( * V_169 ) , & V_8 -> V_266 ) ;
F_128 ( V_169 , V_267 ) ;
return 0 ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_168 * V_169 ;
struct V_268 * V_269 ;
struct V_249 * V_250 ;
V_250 = F_12 ( V_14 -> V_251 , 1 ) ;
F_130 (key, n, &md5sig->head, node) {
F_126 ( & V_169 -> V_264 ) ;
F_127 ( sizeof( * V_169 ) , & V_8 -> V_266 ) ;
F_128 ( V_169 , V_267 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , char T_9 * V_270 ,
int V_71 )
{
struct V_271 V_272 ;
struct V_26 * sin = (struct V_26 * ) & V_272 . V_273 ;
if ( V_71 < sizeof( V_272 ) )
return - V_40 ;
if ( F_132 ( & V_272 , V_270 , sizeof( V_272 ) ) )
return - V_274 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_272 . V_275 || ! V_272 . V_276 )
return F_125 ( V_8 , (union V_184 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_272 . V_276 > V_277 )
return - V_40 ;
return F_117 ( V_8 , (union V_184 * ) & sin -> V_44 . V_45 ,
V_42 , V_272 . V_275 , V_272 . V_276 ,
V_278 ) ;
}
static int F_133 ( struct V_279 * V_280 ,
T_3 V_3 , T_3 V_4 , int V_281 )
{
struct V_282 * V_283 ;
struct V_284 V_285 ;
V_283 = & V_280 -> V_286 . V_54 ;
V_283 -> V_4 = V_4 ;
V_283 -> V_3 = V_3 ;
V_283 -> V_287 = 0 ;
V_283 -> V_288 = V_57 ;
V_283 -> V_110 = F_134 ( V_281 ) ;
F_135 ( & V_285 , V_283 , sizeof( * V_283 ) ) ;
return F_136 ( & V_280 -> V_289 , & V_285 , sizeof( * V_283 ) ) ;
}
static int F_84 ( char * V_290 , const struct V_168 * V_169 ,
T_3 V_3 , T_3 V_4 , const struct V_97 * V_98 )
{
struct V_279 * V_280 ;
struct V_291 * V_292 ;
V_280 = F_137 () ;
if ( ! V_280 )
goto V_293;
V_292 = & V_280 -> V_289 ;
if ( F_138 ( V_292 ) )
goto V_294;
if ( F_133 ( V_280 , V_3 , V_4 , V_98 -> V_162 << 2 ) )
goto V_294;
if ( F_139 ( V_280 , V_98 ) )
goto V_294;
if ( F_140 ( V_280 , V_169 ) )
goto V_294;
if ( F_141 ( V_292 , V_290 ) )
goto V_294;
F_142 () ;
return 0 ;
V_294:
F_142 () ;
V_293:
memset ( V_290 , 0 , 16 ) ;
return 1 ;
}
int F_83 ( char * V_290 , struct V_168 * V_169 ,
const struct V_7 * V_8 , const struct V_103 * V_149 ,
const struct V_1 * V_2 )
{
struct V_279 * V_280 ;
struct V_291 * V_292 ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_149 ) {
V_4 = F_94 ( V_149 ) -> V_224 ;
V_3 = F_94 ( V_149 ) -> V_225 ;
} else {
const struct V_94 * V_95 = F_3 ( V_2 ) ;
V_4 = V_95 -> V_4 ;
V_3 = V_95 -> V_3 ;
}
V_280 = F_137 () ;
if ( ! V_280 )
goto V_293;
V_292 = & V_280 -> V_289 ;
if ( F_138 ( V_292 ) )
goto V_294;
if ( F_133 ( V_280 , V_3 , V_4 , V_2 -> V_110 ) )
goto V_294;
if ( F_139 ( V_280 , V_98 ) )
goto V_294;
if ( F_143 ( V_280 , V_2 , V_98 -> V_162 << 2 ) )
goto V_294;
if ( F_140 ( V_280 , V_169 ) )
goto V_294;
if ( F_141 ( V_292 , V_290 ) )
goto V_294;
F_142 () ;
return 0 ;
V_294:
F_142 () ;
V_293:
memset ( V_290 , 0 , 16 ) ;
return 1 ;
}
static bool F_144 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_170 = NULL ;
struct V_168 * V_295 ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
int V_172 ;
unsigned char V_171 [ 16 ] ;
V_295 = F_82 ( V_8 , (union V_184 * ) & V_95 -> V_4 ,
V_42 ) ;
V_170 = F_77 ( V_98 ) ;
if ( ! V_295 && ! V_170 )
return false ;
if ( V_295 && ! V_170 ) {
F_47 ( F_19 ( V_8 ) , V_296 ) ;
return true ;
}
if ( ! V_295 && V_170 ) {
F_47 ( F_19 ( V_8 ) , V_297 ) ;
return true ;
}
V_172 = F_83 ( V_171 ,
V_295 ,
NULL , NULL , V_2 ) ;
if ( V_172 || memcmp ( V_170 , V_171 , 16 ) != 0 ) {
F_145 ( L_4 ,
& V_95 -> V_4 , F_80 ( V_98 -> V_6 ) ,
& V_95 -> V_3 , F_80 ( V_98 -> V_5 ) ,
V_172 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
int F_146 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_298 V_299 ;
struct V_103 * V_149 ;
struct V_222 * V_223 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_300 = F_58 ( V_2 ) -> V_144 ;
bool V_232 = false , V_104 ;
struct V_33 V_34 ;
struct V_220 V_221 = { . V_110 = - 1 } ;
int V_37 ;
if ( F_75 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_301;
if ( ( V_235 == 2 ||
F_147 ( V_8 ) ) && ! V_300 ) {
V_232 = F_104 ( V_8 , V_2 , L_7 ) ;
if ( ! V_232 )
goto V_301;
}
if ( F_148 ( V_8 ) && F_149 ( V_8 ) > 1 ) {
F_47 ( F_19 ( V_8 ) , V_302 ) ;
goto V_301;
}
V_149 = F_150 ( & V_303 ) ;
if ( ! V_149 )
goto V_301;
#ifdef F_74
F_50 ( V_149 ) -> V_304 = & V_305 ;
#endif
F_151 ( & V_299 ) ;
V_299 . V_72 = V_73 ;
V_299 . V_306 = V_14 -> V_19 . V_306 ;
F_152 ( V_2 , & V_299 , 0 , V_232 ? NULL : & V_221 ) ;
if ( V_232 && ! V_299 . V_307 )
F_151 ( & V_299 ) ;
V_299 . V_308 = V_299 . V_307 ;
F_153 ( V_149 , & V_299 , V_2 ) ;
V_223 = F_94 ( V_149 ) ;
V_223 -> V_224 = V_3 ;
V_223 -> V_225 = V_4 ;
V_223 -> V_218 = F_11 ( V_8 ) -> V_191 ;
V_223 -> V_46 = F_107 ( V_2 ) ;
V_223 -> V_309 = F_154 ( V_8 , V_2 ) ;
if ( F_155 ( V_8 , V_2 , V_149 ) )
goto V_310;
if ( ! V_232 || V_299 . V_308 )
F_156 ( V_149 , V_2 , F_19 ( V_8 ) ) ;
if ( V_232 ) {
V_300 = F_157 ( V_8 , V_2 , & V_149 -> V_311 ) ;
V_149 -> V_312 = V_299 . V_308 ;
} else if ( ! V_300 ) {
if ( V_299 . V_307 &&
V_66 . V_67 &&
( V_68 = F_96 ( V_8 , & V_34 , V_149 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_158 ( V_149 , V_68 , true ) ) {
F_47 ( F_19 ( V_8 ) , V_313 ) ;
goto V_314;
}
}
else if ( ! V_235 &&
( V_315 - F_159 ( V_8 ) <
( V_315 >> 2 ) ) &&
! F_158 ( V_149 , V_68 , false ) ) {
F_160 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_314;
}
V_300 = F_1 ( V_2 ) ;
}
if ( ! V_68 && ( V_68 = F_96 ( V_8 , & V_34 , V_149 ) ) == NULL )
goto V_310;
F_50 ( V_149 ) -> V_123 = V_300 ;
F_50 ( V_149 ) -> V_226 = V_143 ;
F_161 ( V_149 , V_8 , V_68 ) ;
V_104 = ! V_232 &&
F_162 ( V_8 , V_2 , V_149 , & V_221 , V_68 ) ;
V_37 = F_95 ( V_8 , V_68 , V_149 ,
F_163 ( V_2 ) , & V_221 ) ;
if ( ! V_104 ) {
if ( V_37 || V_232 )
goto V_310;
F_50 ( V_149 ) -> V_226 = V_143 ;
F_50 ( V_149 ) -> V_316 = NULL ;
F_164 ( V_8 , V_149 , V_142 ) ;
}
return 0 ;
V_314:
F_165 ( V_68 ) ;
V_310:
F_166 ( V_149 ) ;
V_301:
F_47 ( F_19 ( V_8 ) , V_151 ) ;
return 0 ;
}
struct V_7 * F_167 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_149 ,
struct V_82 * V_68 )
{
struct V_222 * V_223 ;
struct V_28 * V_317 ;
struct V_13 * V_318 ;
struct V_7 * V_319 ;
#ifdef F_74
struct V_168 * V_169 ;
#endif
struct V_38 * V_39 ;
if ( F_148 ( V_8 ) )
goto V_320;
V_319 = F_168 ( V_8 , V_149 , V_2 ) ;
if ( ! V_319 )
goto V_321;
V_319 -> V_76 = V_77 ;
F_169 ( V_319 , V_2 ) ;
V_318 = F_7 ( V_319 ) ;
V_317 = F_11 ( V_319 ) ;
V_223 = F_94 ( V_149 ) ;
V_317 -> V_64 = V_223 -> V_225 ;
V_317 -> V_63 = V_223 -> V_224 ;
V_317 -> V_55 = V_223 -> V_224 ;
V_39 = V_223 -> V_46 ;
F_120 ( V_317 -> V_39 , V_39 ) ;
V_223 -> V_46 = NULL ;
V_317 -> V_322 = F_43 ( V_2 ) ;
V_317 -> V_323 = F_3 ( V_2 ) -> V_119 ;
V_317 -> V_324 = F_3 ( V_2 ) -> V_194 ;
F_23 ( V_319 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_319 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_317 -> V_78 = V_318 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_170 ( V_8 , V_319 , V_149 ) ;
if ( ! V_68 )
goto V_325;
} else {
}
F_27 ( V_319 , V_68 ) ;
F_34 ( V_319 , F_31 ( V_68 ) ) ;
V_318 -> V_326 = F_171 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_306 &&
F_7 ( V_8 ) -> V_19 . V_306 < V_318 -> V_326 )
V_318 -> V_326 = F_7 ( V_8 ) -> V_19 . V_306 ;
F_172 ( V_319 ) ;
#ifdef F_74
V_169 = F_82 ( V_8 , (union V_184 * ) & V_317 -> V_64 ,
V_42 ) ;
if ( V_169 != NULL ) {
F_117 ( V_319 , (union V_184 * ) & V_317 -> V_64 ,
V_42 , V_169 -> V_169 , V_169 -> V_261 , V_244 ) ;
F_118 ( V_319 , V_263 ) ;
}
#endif
if ( F_173 ( V_8 , V_319 ) < 0 )
goto V_325;
F_174 ( V_319 , NULL ) ;
return V_319 ;
V_320:
F_47 ( F_19 ( V_8 ) , V_302 ) ;
V_321:
F_165 ( V_68 ) ;
exit:
F_47 ( F_19 ( V_8 ) , V_151 ) ;
return NULL ;
V_325:
F_175 ( V_319 ) ;
F_64 ( V_319 ) ;
goto exit;
}
static struct V_7 * F_176 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_7 * V_327 ;
struct V_103 * * V_150 ;
struct V_103 * V_149 = F_61 ( V_8 , & V_150 , V_98 -> V_6 ,
V_95 -> V_4 , V_95 -> V_3 ) ;
if ( V_149 )
return F_177 ( V_8 , V_2 , V_149 , V_150 , false ) ;
V_327 = F_178 ( F_19 ( V_8 ) , & V_112 , V_95 -> V_4 ,
V_98 -> V_6 , V_95 -> V_3 , V_98 -> V_5 , F_43 ( V_2 ) ) ;
if ( V_327 ) {
if ( V_327 -> V_113 != V_114 ) {
F_46 ( V_327 ) ;
return V_327 ;
}
F_44 ( F_45 ( V_327 ) ) ;
return NULL ;
}
#ifdef F_105
if ( ! V_98 -> V_179 )
V_8 = F_179 ( V_8 , V_2 , & ( F_108 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
int F_180 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_328 ;
#ifdef F_74
if ( F_144 ( V_8 , V_2 ) )
goto V_329;
#endif
if ( V_8 -> V_113 == V_330 ) {
struct V_82 * V_68 = V_8 -> V_331 ;
F_181 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_332 != V_2 -> V_333 ||
V_68 -> V_90 -> V_158 ( V_68 , 0 ) == NULL ) {
F_165 ( V_68 ) ;
V_8 -> V_331 = NULL ;
}
}
F_182 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_110 ) ;
return 0 ;
}
if ( V_2 -> V_110 < F_183 ( V_2 ) || F_184 ( V_2 ) )
goto V_334;
if ( V_8 -> V_113 == V_124 ) {
struct V_7 * V_327 = F_176 ( V_8 , V_2 ) ;
if ( ! V_327 )
goto V_329;
if ( V_327 != V_8 ) {
F_181 ( V_327 , V_2 ) ;
if ( F_185 ( V_8 , V_327 , V_2 ) ) {
V_328 = V_327 ;
goto V_335;
}
return 0 ;
}
} else
F_181 ( V_8 , V_2 ) ;
if ( F_186 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_110 ) ) {
V_328 = V_8 ;
goto V_335;
}
return 0 ;
V_335:
F_73 ( V_328 , V_2 ) ;
V_329:
F_187 ( V_2 ) ;
return 0 ;
V_334:
F_87 ( F_19 ( V_8 ) , V_336 ) ;
F_87 ( F_19 ( V_8 ) , V_337 ) ;
goto V_329;
}
void F_188 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
if ( V_2 -> V_338 != V_339 )
return;
if ( ! F_189 ( V_2 , F_190 ( V_2 ) + sizeof( struct V_97 ) ) )
return;
V_95 = F_3 ( V_2 ) ;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_162 < sizeof( struct V_97 ) / 4 )
return;
V_8 = F_191 ( F_40 ( V_2 -> V_109 ) , & V_112 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , F_80 ( V_98 -> V_5 ) ,
V_2 -> V_333 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_340 = V_341 ;
if ( V_8 -> V_113 != V_114 ) {
struct V_82 * V_68 = V_8 -> V_331 ;
if ( V_68 )
V_68 = F_192 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_332 == V_2 -> V_333 )
F_193 ( V_2 , V_68 ) ;
}
}
}
bool F_194 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_342 || ! V_14 -> V_343 . V_344 )
return false ;
if ( V_2 -> V_110 <= F_183 ( V_2 ) &&
F_195 ( & V_14 -> V_343 . V_345 ) == 0 )
return false ;
F_196 ( V_2 ) ;
F_197 ( & V_14 -> V_343 . V_345 , V_2 ) ;
V_14 -> V_343 . V_346 += V_2 -> V_347 ;
if ( V_14 -> V_343 . V_346 > V_8 -> V_348 ) {
struct V_1 * V_349 ;
F_56 ( F_13 ( V_8 ) ) ;
while ( ( V_349 = F_198 ( & V_14 -> V_343 . V_345 ) ) != NULL ) {
F_199 ( V_8 , V_349 ) ;
F_47 ( F_19 ( V_8 ) ,
V_350 ) ;
}
V_14 -> V_343 . V_346 = 0 ;
} else if ( F_195 ( & V_14 -> V_343 . V_345 ) == 1 ) {
F_200 ( F_201 ( V_8 ) ,
V_351 | V_352 | V_353 ) ;
if ( ! F_202 ( V_8 ) )
F_59 ( V_8 , V_354 ,
( 3 * F_203 ( V_8 ) ) / 4 ,
V_146 ) ;
}
return true ;
}
int F_204 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
int V_355 ;
struct V_108 * V_108 = F_40 ( V_2 -> V_109 ) ;
if ( V_2 -> V_338 != V_339 )
goto V_356;
F_87 ( V_108 , V_357 ) ;
if ( ! F_189 ( V_2 , sizeof( struct V_97 ) ) )
goto V_356;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_162 < sizeof( struct V_97 ) / 4 )
goto V_358;
if ( ! F_189 ( V_2 , V_98 -> V_162 * 4 ) )
goto V_356;
if ( F_205 ( V_2 , V_57 , V_359 ) )
goto V_360;
V_98 = F_4 ( V_2 ) ;
V_95 = F_3 ( V_2 ) ;
F_58 ( V_2 ) -> V_105 = F_49 ( V_98 -> V_105 ) ;
F_58 ( V_2 ) -> V_361 = ( F_58 ( V_2 ) -> V_105 + V_98 -> V_179 + V_98 -> V_180 +
V_2 -> V_110 - V_98 -> V_162 * 4 ) ;
F_58 ( V_2 ) -> V_178 = F_49 ( V_98 -> V_178 ) ;
F_58 ( V_2 ) -> V_144 = 0 ;
F_58 ( V_2 ) -> V_362 = F_206 ( V_95 ) ;
F_58 ( V_2 ) -> V_363 = 0 ;
V_8 = F_207 ( & V_112 , V_2 , V_98 -> V_6 , V_98 -> V_5 ) ;
if ( ! V_8 )
goto V_364;
V_365:
if ( V_8 -> V_113 == V_114 )
goto V_366;
if ( F_48 ( V_95 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_47 ( V_108 , V_121 ) ;
goto V_367;
}
if ( ! F_208 ( V_8 , V_368 , V_2 ) )
goto V_367;
F_209 ( V_2 ) ;
if ( F_210 ( V_8 , V_2 ) )
goto V_367;
F_211 ( V_8 , V_2 ) ;
V_2 -> V_109 = NULL ;
F_212 ( V_8 ) ;
V_355 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_213
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_343 . V_369 && V_14 -> V_343 . V_370 )
V_14 -> V_343 . V_369 = F_214 () ;
if ( V_14 -> V_343 . V_369 )
V_355 = F_180 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_194 ( V_8 , V_2 ) )
V_355 = F_180 ( V_8 , V_2 ) ;
}
} else if ( F_48 ( F_215 ( V_8 , V_2 ,
V_8 -> V_348 + V_8 -> V_371 ) ) ) {
F_65 ( V_8 ) ;
F_47 ( V_108 , V_372 ) ;
goto V_367;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
return V_355 ;
V_364:
if ( ! F_208 ( NULL , V_368 , V_2 ) )
goto V_356;
if ( V_2 -> V_110 < ( V_98 -> V_162 << 2 ) || F_184 ( V_2 ) ) {
V_360:
F_87 ( V_108 , V_336 ) ;
V_358:
F_87 ( V_108 , V_337 ) ;
} else {
F_73 ( NULL , V_2 ) ;
}
V_356:
F_187 ( V_2 ) ;
return 0 ;
V_367:
F_66 ( V_8 ) ;
goto V_356;
V_366:
if ( ! F_208 ( NULL , V_368 , V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_356;
}
if ( V_2 -> V_110 < ( V_98 -> V_162 << 2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_358;
}
if ( F_184 ( V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_360;
}
switch ( F_216 ( F_45 ( V_8 ) , V_2 , V_98 ) ) {
case V_373 : {
struct V_7 * V_374 = F_217 ( F_40 ( V_2 -> V_109 ) ,
& V_112 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , V_98 -> V_5 ,
F_43 ( V_2 ) ) ;
if ( V_374 ) {
F_218 ( F_45 ( V_8 ) , & V_66 ) ;
F_44 ( F_45 ( V_8 ) ) ;
V_8 = V_374 ;
goto V_365;
}
}
case V_375 :
F_91 ( V_8 , V_2 ) ;
break;
case V_376 :
goto V_364;
case V_377 : ;
}
goto V_356;
}
void F_169 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_79 ( V_2 ) ;
F_219 ( V_68 ) ;
V_8 -> V_331 = V_68 ;
F_11 ( V_8 ) -> V_332 = V_2 -> V_333 ;
}
static int F_220 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = F_23 ( V_8 ) ;
F_221 ( V_8 ) ;
V_101 -> V_378 = & V_379 ;
#ifdef F_74
F_7 ( V_8 ) -> V_304 = & V_380 ;
#endif
return 0 ;
}
void F_222 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_223 ( V_8 ) ;
F_224 ( V_8 ) ;
F_225 ( V_8 ) ;
F_226 ( & V_14 -> V_381 ) ;
#ifdef F_74
if ( V_14 -> V_251 ) {
F_129 ( V_8 ) ;
F_128 ( V_14 -> V_251 , V_267 ) ;
V_14 -> V_251 = NULL ;
}
#endif
#ifdef F_213
F_226 ( & V_8 -> V_382 ) ;
#endif
F_226 ( & V_14 -> V_343 . V_345 ) ;
if ( F_23 ( V_8 ) -> V_383 )
F_227 ( V_8 ) ;
F_56 ( V_14 -> V_122 != NULL ) ;
F_228 ( V_14 ) ;
F_229 ( V_8 ) ;
F_230 ( V_8 ) ;
}
static void * F_231 ( struct V_384 * V_105 , void * V_385 )
{
struct V_100 * V_101 ;
struct V_386 * V_264 ;
struct V_7 * V_8 = V_385 ;
struct V_387 * V_388 ;
struct V_389 * V_390 = V_105 -> V_391 ;
struct V_108 * V_108 = F_232 ( V_105 ) ;
if ( ! V_8 ) {
V_388 = & V_112 . V_392 [ V_390 -> V_393 ] ;
F_233 ( & V_388 -> V_394 ) ;
V_8 = F_234 ( & V_388 -> V_160 ) ;
V_390 -> V_206 = 0 ;
goto V_395;
}
V_388 = & V_112 . V_392 [ V_390 -> V_393 ] ;
++ V_390 -> V_396 ;
++ V_390 -> V_206 ;
if ( V_390 -> V_397 == V_398 ) {
struct V_103 * V_149 = V_385 ;
V_101 = F_23 ( V_390 -> V_399 ) ;
V_149 = V_149 -> V_400 ;
while ( 1 ) {
while ( V_149 ) {
if ( V_149 -> V_401 -> V_246 == V_390 -> V_246 ) {
V_385 = V_149 ;
goto V_118;
}
V_149 = V_149 -> V_400 ;
}
if ( ++ V_390 -> V_402 >= V_101 -> V_238 . V_239 -> V_403 )
break;
V_404:
V_149 = V_101 -> V_238 . V_239 -> V_405 [ V_390 -> V_402 ] ;
}
V_8 = F_235 ( V_390 -> V_399 ) ;
V_390 -> V_397 = V_406 ;
F_236 ( & V_101 -> V_238 . V_407 ) ;
} else {
V_101 = F_23 ( V_8 ) ;
F_237 ( & V_101 -> V_238 . V_407 ) ;
if ( F_238 ( & V_101 -> V_238 ) )
goto V_408;
F_236 ( & V_101 -> V_238 . V_407 ) ;
V_8 = F_235 ( V_8 ) ;
}
V_395:
F_239 (sk, node) {
if ( ! F_240 ( F_19 ( V_8 ) , V_108 ) )
continue;
if ( V_8 -> V_409 == V_390 -> V_246 ) {
V_385 = V_8 ;
goto V_118;
}
V_101 = F_23 ( V_8 ) ;
F_237 ( & V_101 -> V_238 . V_407 ) ;
if ( F_238 ( & V_101 -> V_238 ) ) {
V_408:
V_390 -> V_410 = F_241 ( V_8 ) ;
V_390 -> V_399 = V_8 ;
V_390 -> V_397 = V_398 ;
V_390 -> V_402 = 0 ;
goto V_404;
}
F_236 ( & V_101 -> V_238 . V_407 ) ;
}
F_242 ( & V_388 -> V_394 ) ;
V_390 -> V_206 = 0 ;
if ( ++ V_390 -> V_393 < V_411 ) {
V_388 = & V_112 . V_392 [ V_390 -> V_393 ] ;
F_233 ( & V_388 -> V_394 ) ;
V_8 = F_234 ( & V_388 -> V_160 ) ;
goto V_395;
}
V_385 = NULL ;
V_118:
return V_385 ;
}
static void * F_243 ( struct V_384 * V_105 , T_10 * V_412 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
void * V_413 ;
V_390 -> V_393 = 0 ;
V_390 -> V_206 = 0 ;
V_413 = F_231 ( V_105 , NULL ) ;
while ( V_413 && * V_412 ) {
V_413 = F_231 ( V_105 , V_413 ) ;
-- * V_412 ;
}
return V_413 ;
}
static inline bool F_244 ( const struct V_389 * V_390 )
{
return F_245 ( & V_112 . V_414 [ V_390 -> V_393 ] . V_415 ) ;
}
static void * F_246 ( struct V_384 * V_105 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
struct V_108 * V_108 = F_232 ( V_105 ) ;
void * V_413 = NULL ;
V_390 -> V_206 = 0 ;
for (; V_390 -> V_393 <= V_112 . V_416 ; ++ V_390 -> V_393 ) {
struct V_7 * V_8 ;
struct V_386 * V_264 ;
T_11 * V_394 = F_247 ( & V_112 , V_390 -> V_393 ) ;
if ( F_244 ( V_390 ) )
continue;
F_233 ( V_394 ) ;
F_248 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_409 != V_390 -> V_246 ||
! F_240 ( F_19 ( V_8 ) , V_108 ) ) {
continue;
}
V_413 = V_8 ;
goto V_118;
}
F_242 ( V_394 ) ;
}
V_118:
return V_413 ;
}
static void * F_249 ( struct V_384 * V_105 , void * V_385 )
{
struct V_7 * V_8 = V_385 ;
struct V_386 * V_264 ;
struct V_389 * V_390 = V_105 -> V_391 ;
struct V_108 * V_108 = F_232 ( V_105 ) ;
++ V_390 -> V_396 ;
++ V_390 -> V_206 ;
V_8 = F_235 ( V_8 ) ;
F_239 (sk, node) {
if ( V_8 -> V_409 == V_390 -> V_246 && F_240 ( F_19 ( V_8 ) , V_108 ) )
return V_8 ;
}
F_242 ( F_247 ( & V_112 , V_390 -> V_393 ) ) ;
++ V_390 -> V_393 ;
return F_246 ( V_105 ) ;
}
static void * F_250 ( struct V_384 * V_105 , T_10 V_412 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
void * V_413 ;
V_390 -> V_393 = 0 ;
V_413 = F_246 ( V_105 ) ;
while ( V_413 && V_412 ) {
V_413 = F_249 ( V_105 , V_413 ) ;
-- V_412 ;
}
return V_413 ;
}
static void * F_251 ( struct V_384 * V_105 , T_10 V_412 )
{
void * V_413 ;
struct V_389 * V_390 = V_105 -> V_391 ;
V_390 -> V_397 = V_406 ;
V_413 = F_243 ( V_105 , & V_412 ) ;
if ( ! V_413 ) {
V_390 -> V_397 = V_417 ;
V_413 = F_250 ( V_105 , V_412 ) ;
}
return V_413 ;
}
static void * F_252 ( struct V_384 * V_105 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
int V_206 = V_390 -> V_206 ;
int V_418 = V_390 -> V_396 ;
void * V_413 = NULL ;
switch ( V_390 -> V_397 ) {
case V_398 :
case V_406 :
if ( V_390 -> V_393 >= V_411 )
break;
V_390 -> V_397 = V_406 ;
V_413 = F_231 ( V_105 , NULL ) ;
while ( V_206 -- && V_413 )
V_413 = F_231 ( V_105 , V_413 ) ;
if ( V_413 )
break;
V_390 -> V_393 = 0 ;
V_390 -> V_397 = V_417 ;
case V_417 :
if ( V_390 -> V_393 > V_112 . V_416 )
break;
V_413 = F_246 ( V_105 ) ;
while ( V_206 -- && V_413 )
V_413 = F_249 ( V_105 , V_413 ) ;
}
V_390 -> V_396 = V_418 ;
return V_413 ;
}
static void * F_253 ( struct V_384 * V_105 , T_10 * V_412 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
void * V_413 ;
if ( * V_412 && * V_412 == V_390 -> V_419 ) {
V_413 = F_252 ( V_105 ) ;
if ( V_413 )
goto V_118;
}
V_390 -> V_397 = V_406 ;
V_390 -> V_396 = 0 ;
V_390 -> V_393 = 0 ;
V_390 -> V_206 = 0 ;
V_413 = * V_412 ? F_251 ( V_105 , * V_412 - 1 ) : V_420 ;
V_118:
V_390 -> V_419 = * V_412 ;
return V_413 ;
}
static void * F_254 ( struct V_384 * V_105 , void * V_421 , T_10 * V_412 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
void * V_413 = NULL ;
if ( V_421 == V_420 ) {
V_413 = F_251 ( V_105 , 0 ) ;
goto V_118;
}
switch ( V_390 -> V_397 ) {
case V_398 :
case V_406 :
V_413 = F_231 ( V_105 , V_421 ) ;
if ( ! V_413 ) {
V_390 -> V_397 = V_417 ;
V_390 -> V_393 = 0 ;
V_390 -> V_206 = 0 ;
V_413 = F_246 ( V_105 ) ;
}
break;
case V_417 :
V_413 = F_249 ( V_105 , V_421 ) ;
break;
}
V_118:
++ * V_412 ;
V_390 -> V_419 = * V_412 ;
return V_413 ;
}
static void F_255 ( struct V_384 * V_105 , void * V_421 )
{
struct V_389 * V_390 = V_105 -> V_391 ;
switch ( V_390 -> V_397 ) {
case V_398 :
if ( V_421 ) {
struct V_100 * V_101 = F_23 ( V_390 -> V_399 ) ;
F_236 ( & V_101 -> V_238 . V_407 ) ;
}
case V_406 :
if ( V_421 != V_420 )
F_242 ( & V_112 . V_392 [ V_390 -> V_393 ] . V_394 ) ;
break;
case V_417 :
if ( V_421 )
F_242 ( F_247 ( & V_112 , V_390 -> V_393 ) ) ;
break;
}
}
int F_256 ( struct V_422 * V_422 , struct V_423 * V_423 )
{
struct V_424 * V_425 = F_257 ( V_422 ) ;
struct V_389 * V_426 ;
int V_37 ;
V_37 = F_258 ( V_422 , V_423 , & V_425 -> V_427 ,
sizeof( struct V_389 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_426 = ( (struct V_384 * ) V_423 -> V_428 ) -> V_391 ;
V_426 -> V_246 = V_425 -> V_246 ;
V_426 -> V_419 = 0 ;
return 0 ;
}
int F_259 ( struct V_108 * V_108 , struct V_424 * V_425 )
{
int V_413 = 0 ;
struct V_429 * V_430 ;
V_425 -> V_427 . V_431 = F_253 ;
V_425 -> V_427 . V_432 = F_254 ;
V_425 -> V_427 . V_433 = F_255 ;
V_430 = F_260 ( V_425 -> V_434 , V_435 , V_108 -> V_436 ,
V_425 -> V_437 , V_425 ) ;
if ( ! V_430 )
V_413 = - V_262 ;
return V_413 ;
}
void F_261 ( struct V_108 * V_108 , struct V_424 * V_425 )
{
F_262 ( V_425 -> V_434 , V_108 -> V_436 ) ;
}
static void F_263 ( const struct V_7 * V_8 , const struct V_103 * V_149 ,
struct V_384 * V_438 , int V_439 , T_12 V_410 )
{
const struct V_222 * V_223 = F_94 ( V_149 ) ;
long V_440 = V_149 -> V_441 - V_79 ;
F_264 ( V_438 , L_9
L_10 ,
V_439 ,
V_223 -> V_224 ,
F_80 ( F_11 ( V_8 ) -> V_49 ) ,
V_223 -> V_225 ,
F_80 ( V_223 -> V_442 ) ,
V_152 ,
0 , 0 ,
1 ,
F_265 ( V_440 ) ,
V_149 -> V_443 ,
F_266 ( F_267 ( V_438 ) , V_410 ) ,
0 ,
0 ,
F_268 ( & V_8 -> V_444 ) ,
V_149 ) ;
}
static void F_269 ( struct V_7 * V_8 , struct V_384 * V_438 , int V_439 )
{
int V_445 ;
unsigned long V_446 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_100 * V_101 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_447 * V_448 = V_101 -> V_238 . V_448 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_449 = V_29 -> V_63 ;
T_13 V_450 = F_80 ( V_29 -> V_69 ) ;
T_13 V_451 = F_80 ( V_29 -> V_49 ) ;
int V_452 ;
if ( V_101 -> V_453 == V_145 ||
V_101 -> V_453 == V_454 ||
V_101 -> V_453 == V_455 ) {
V_445 = 1 ;
V_446 = V_101 -> V_456 ;
} else if ( V_101 -> V_453 == V_457 ) {
V_445 = 4 ;
V_446 = V_101 -> V_456 ;
} else if ( F_270 ( & V_8 -> V_458 ) ) {
V_445 = 2 ;
V_446 = V_8 -> V_458 . V_441 ;
} else {
V_445 = 0 ;
V_446 = V_79 ;
}
if ( V_8 -> V_113 == V_124 )
V_452 = V_8 -> V_459 ;
else
V_452 = F_271 ( int , V_14 -> V_216 - V_14 -> V_460 , 0 ) ;
F_264 ( V_438 , L_11
L_12 ,
V_439 , V_449 , V_451 , V_5 , V_450 , V_8 -> V_113 ,
V_14 -> V_17 - V_14 -> V_106 ,
V_452 ,
V_445 ,
F_265 ( V_446 - V_79 ) ,
V_101 -> V_138 ,
F_266 ( F_267 ( V_438 ) , F_241 ( V_8 ) ) ,
V_101 -> V_461 ,
F_272 ( V_8 ) ,
F_268 ( & V_8 -> V_444 ) , V_8 ,
F_273 ( V_101 -> V_140 ) ,
F_273 ( V_101 -> V_462 . V_463 ) ,
( V_101 -> V_462 . V_464 << 1 ) | V_101 -> V_462 . V_465 ,
V_14 -> V_466 ,
V_8 -> V_113 == V_124 ?
( V_448 ? V_448 -> V_467 : 0 ) :
( F_274 ( V_14 ) ? - 1 : V_14 -> V_468 ) ) ;
}
static void F_275 ( const struct V_207 * V_208 ,
struct V_384 * V_438 , int V_439 )
{
T_3 V_5 , V_449 ;
T_13 V_450 , V_451 ;
T_14 V_440 = V_208 -> V_469 - F_276 () ;
V_5 = V_208 -> V_470 ;
V_449 = V_208 -> V_471 ;
V_450 = F_80 ( V_208 -> V_472 ) ;
V_451 = F_80 ( V_208 -> V_473 ) ;
F_264 ( V_438 , L_9
L_13 ,
V_439 , V_449 , V_451 , V_5 , V_450 , V_208 -> V_474 , 0 , 0 ,
3 , F_265 ( V_440 ) , 0 , 0 , 0 , 0 ,
F_268 ( & V_208 -> V_475 ) , V_208 ) ;
}
static int F_277 ( struct V_384 * V_105 , void * V_421 )
{
struct V_389 * V_390 ;
struct V_7 * V_8 = V_421 ;
F_278 ( V_105 , V_476 - 1 ) ;
if ( V_421 == V_420 ) {
F_279 ( V_105 , L_14
L_15
L_16 ) ;
goto V_118;
}
V_390 = V_105 -> V_391 ;
switch ( V_390 -> V_397 ) {
case V_406 :
case V_417 :
if ( V_8 -> V_113 == V_114 )
F_275 ( V_421 , V_105 , V_390 -> V_396 ) ;
else
F_269 ( V_421 , V_105 , V_390 -> V_396 ) ;
break;
case V_398 :
F_263 ( V_390 -> V_399 , V_421 , V_105 , V_390 -> V_396 , V_390 -> V_410 ) ;
break;
}
V_118:
F_280 ( V_105 , '\n' ) ;
return 0 ;
}
static int T_15 F_281 ( struct V_108 * V_108 )
{
return F_259 ( V_108 , & V_477 ) ;
}
static void T_16 F_282 ( struct V_108 * V_108 )
{
F_261 ( V_108 , & V_477 ) ;
}
int T_17 F_283 ( void )
{
return F_284 ( & V_478 ) ;
}
void F_285 ( void )
{
F_286 ( & V_478 ) ;
}
static int T_15 F_287 ( struct V_108 * V_108 )
{
V_108 -> V_479 . V_480 = 2 ;
return 0 ;
}
static void T_16 F_288 ( struct V_108 * V_108 )
{
}
static void T_16 F_289 ( struct V_481 * V_482 )
{
F_290 ( & V_112 , & V_66 , V_42 ) ;
}
void T_17 F_291 ( void )
{
F_292 ( & V_112 ) ;
if ( F_284 ( & V_483 ) )
F_293 ( L_17 ) ;
}
