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
( ! V_10 || ( V_16 &&
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
F_21 ( V_8 , V_29 -> V_55 ) ;
if ( V_14 -> V_19 . V_22 && V_29 -> V_63 != V_3 ) {
V_14 -> V_19 . V_20 = 0 ;
V_14 -> V_19 . V_22 = 0 ;
if ( F_22 ( ! V_14 -> V_64 ) )
V_14 -> V_17 = 0 ;
}
if ( V_65 . V_66 &&
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 )
F_23 ( V_8 , & V_36 -> V_67 ) ;
V_29 -> V_68 = V_27 -> V_50 ;
F_24 ( V_8 , V_3 ) ;
F_25 ( V_8 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_8 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_14 -> V_19 . V_71 = V_72 ;
F_26 ( V_8 , V_73 ) ;
V_37 = F_27 ( & V_65 , V_8 ) ;
if ( V_37 )
goto V_74;
F_28 ( V_8 ) ;
V_36 = F_29 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_68 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
V_36 = NULL ;
goto V_74;
}
V_8 -> V_75 = V_76 ;
F_30 ( V_8 , & V_36 -> V_67 ) ;
if ( ! V_14 -> V_17 && F_22 ( ! V_14 -> V_64 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_63 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_77 = V_14 -> V_17 ^ V_78 ;
V_37 = F_31 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_74;
return 0 ;
V_74:
F_26 ( V_8 , V_79 ) ;
F_20 ( V_36 ) ;
V_8 -> V_80 = 0 ;
V_29 -> V_68 = 0 ;
return V_37 ;
}
void F_32 ( struct V_7 * V_8 )
{
struct V_81 * V_67 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
T_4 V_82 = F_7 ( V_8 ) -> V_83 ;
V_67 = F_33 ( V_8 , V_82 ) ;
if ( ! V_67 )
return;
if ( V_82 < F_34 ( V_67 ) && F_35 ( V_8 , V_67 ) )
V_8 -> V_84 = V_85 ;
V_82 = F_34 ( V_67 ) ;
if ( V_29 -> V_86 != V_87 &&
F_36 ( V_8 ) &&
F_25 ( V_8 ) -> V_88 > V_82 ) {
F_37 ( V_8 , V_82 ) ;
F_38 ( V_8 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_81 * V_67 = F_40 ( V_8 , 0 ) ;
if ( V_67 )
V_67 -> V_89 -> V_90 ( V_67 , V_8 , V_2 ) ;
}
void F_41 ( struct V_7 * V_8 , T_4 V_91 )
{
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_94 * V_94 = F_19 ( V_8 ) ;
F_43 ( V_93 -> V_8 ) ;
if ( V_91 != F_44 ( V_93 ) -> V_95 ) {
F_45 ( V_94 , V_96 ) ;
} else {
F_46 ( V_93 -> V_97 , V_93 ) ;
F_45 ( V_94 , V_98 ) ;
}
F_47 ( V_93 ) ;
}
void F_48 ( struct V_1 * V_99 , T_4 V_100 )
{
const struct V_101 * V_102 = ( const struct V_101 * ) V_99 -> V_103 ;
struct V_104 * V_105 = (struct V_104 * ) ( V_99 -> V_103 + ( V_102 -> V_106 << 2 ) ) ;
struct V_107 * V_108 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_49 ( V_99 ) -> type ;
const int V_109 = F_49 ( V_99 ) -> V_109 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_92 * V_110 ;
T_1 V_91 , V_111 ;
T_1 V_112 ;
int V_37 ;
struct V_94 * V_94 = F_50 ( V_99 -> V_113 ) ;
V_8 = F_51 ( V_94 , & V_114 , V_102 -> V_3 ,
V_105 -> V_5 , V_102 -> V_4 , F_52 ( V_105 -> V_6 ) ,
F_53 ( V_99 ) ) ;
if ( ! V_8 ) {
F_54 ( V_94 , V_115 ) ;
return;
}
if ( V_8 -> V_116 == V_117 ) {
F_55 ( F_56 ( V_8 ) ) ;
return;
}
V_91 = F_57 ( V_105 -> V_91 ) ;
if ( V_8 -> V_116 == V_118 )
return F_41 ( V_8 , V_91 ) ;
F_58 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_119 && V_109 == V_120 ) )
F_45 ( V_94 , V_121 ) ;
}
if ( V_8 -> V_116 == V_79 )
goto V_122;
if ( F_59 ( V_102 -> V_123 < F_11 ( V_8 ) -> V_124 ) ) {
F_45 ( V_94 , V_125 ) ;
goto V_122;
}
V_108 = F_25 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_110 = V_14 -> V_126 ;
V_111 = V_110 ? F_44 ( V_110 ) -> V_95 : V_14 -> V_111 ;
if ( V_8 -> V_116 != V_127 &&
! F_60 ( V_91 , V_111 , V_14 -> V_128 ) ) {
F_45 ( V_94 , V_96 ) ;
goto V_122;
}
switch ( type ) {
case V_129 :
F_39 ( V_99 , V_8 ) ;
goto V_122;
case V_130 :
goto V_122;
case V_131 :
V_37 = V_132 ;
break;
case V_119 :
if ( V_109 > V_133 )
goto V_122;
if ( V_109 == V_120 ) {
if ( V_8 -> V_116 == V_127 )
goto V_122;
V_14 -> V_83 = V_100 ;
if ( ! F_13 ( V_8 ) ) {
F_32 ( V_8 ) ;
} else {
if ( ! F_61 ( V_134 , & V_14 -> V_135 ) )
F_9 ( V_8 ) ;
}
goto V_122;
}
V_37 = V_136 [ V_109 ] . V_137 ;
if ( V_109 != V_138 && V_109 != V_139 )
break;
if ( V_91 != V_14 -> V_111 || ! V_108 -> V_140 ||
! V_108 -> V_141 || V_110 )
break;
if ( F_13 ( V_8 ) )
break;
V_108 -> V_141 -- ;
V_108 -> V_142 = V_14 -> V_143 ? F_62 ( V_14 ) :
V_144 ;
V_108 -> V_142 = F_63 ( V_108 , V_145 ) ;
V_2 = F_64 ( V_8 ) ;
F_65 ( ! V_2 ) ;
V_112 = V_108 -> V_142 -
F_66 ( V_108 -> V_142 ,
V_146 - F_67 ( V_2 ) ) ;
if ( V_112 ) {
F_68 ( V_8 , V_147 ,
V_112 , V_145 ) ;
} else {
F_69 ( V_8 ) ;
}
break;
case V_148 :
V_37 = V_149 ;
break;
default:
goto V_122;
}
switch ( V_8 -> V_116 ) {
case V_73 :
case V_150 :
if ( V_110 && ! V_110 -> V_8 )
break;
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
F_70 ( V_8 ) ;
} else {
V_8 -> V_84 = V_37 ;
}
goto V_122;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_153 ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
} else {
V_8 -> V_84 = V_37 ;
}
V_122:
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
}
void F_73 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_104 * V_105 = F_4 ( V_2 ) ;
if ( V_2 -> V_154 == V_155 ) {
V_105 -> V_156 = ~ F_74 ( V_2 -> V_157 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_75 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_76 ( struct V_104 , V_156 ) ;
} else {
V_105 -> V_156 = F_74 ( V_2 -> V_157 , V_4 , V_3 ,
F_77 ( V_105 ,
V_105 -> V_161 << 2 ,
V_2 -> V_162 ) ) ;
}
}
void F_78 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_73 ( V_2 , V_29 -> V_55 , V_29 -> V_63 ) ;
}
static void F_79 ( const struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
#ifdef F_80
T_3 V_46 [ ( V_163 >> 2 ) ] ;
#endif
} V_164 ;
struct V_165 V_166 ;
#ifdef F_80
struct V_167 * V_168 ;
const T_5 * V_169 = NULL ;
unsigned char V_170 [ 16 ] ;
int V_171 ;
struct V_7 * V_172 = NULL ;
#endif
struct V_94 * V_94 ;
if ( V_105 -> V_173 )
return;
if ( ! V_8 && F_81 ( V_2 ) -> V_174 != V_175 )
return;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = sizeof( struct V_104 ) / 4 ;
V_164 . V_105 . V_173 = 1 ;
if ( V_105 -> V_176 ) {
V_164 . V_105 . V_91 = V_105 -> V_177 ;
} else {
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_177 = F_82 ( F_57 ( V_105 -> V_91 ) + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_157 - ( V_105 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
V_94 = V_8 ? F_19 ( V_8 ) : F_50 ( F_83 ( V_2 ) -> V_113 ) ;
#ifdef F_80
V_169 = F_84 ( V_105 ) ;
if ( ! V_8 && V_169 ) {
V_172 = F_85 ( V_94 ,
& V_114 , F_3 ( V_2 ) -> V_4 ,
V_105 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_52 ( V_105 -> V_6 ) , F_53 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_86 () ;
V_168 = F_87 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_88 ( V_170 , V_168 , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
} else {
V_168 = V_8 ? F_87 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_82 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_89 ( ( T_5 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_162 = F_90 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_76 ( struct V_104 , V_156 ) / 2 ;
V_166 . V_189 = ( V_8 && F_11 ( V_8 ) -> V_190 ) ? V_191 : 0 ;
if ( V_8 )
V_166 . V_192 = V_8 -> V_56 ;
V_166 . V_193 = F_3 ( V_2 ) -> V_193 ;
F_91 ( * F_92 ( V_94 -> V_194 . F_7 ) ,
V_2 , & F_93 ( V_2 ) -> V_195 . V_196 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_94 ( V_94 , V_197 ) ;
F_94 ( V_94 , V_198 ) ;
#ifdef F_80
V_184:
if ( V_172 ) {
F_95 () ;
F_72 ( V_172 ) ;
}
#endif
}
static void F_96 ( struct V_1 * V_2 , T_4 V_91 , T_4 V_176 ,
T_4 V_199 , T_4 V_200 , T_4 V_201 , int V_202 ,
struct V_167 * V_168 ,
int V_203 , T_6 V_193 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
T_3 V_46 [ ( V_204 >> 2 )
#ifdef F_80
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
struct V_94 * V_94 = F_50 ( F_83 ( V_2 ) -> V_113 ) ;
memset ( & V_164 . V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
if ( V_201 ) {
V_164 . V_46 [ 0 ] = F_82 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_205 << 8 ) |
V_206 ) ;
V_164 . V_46 [ 1 ] = F_82 ( V_200 ) ;
V_164 . V_46 [ 2 ] = F_82 ( V_201 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_204 ;
}
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_105 . V_91 = F_82 ( V_91 ) ;
V_164 . V_105 . V_177 = F_82 ( V_176 ) ;
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_207 = F_97 ( V_199 ) ;
#ifdef F_80
if ( V_168 ) {
int V_208 = ( V_201 ) ? 3 : 0 ;
V_164 . V_46 [ V_208 ++ ] = F_82 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_89 ( ( T_5 * ) & V_164 . V_46 [ V_208 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_189 = V_203 ;
V_166 . V_162 = F_90 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_76 ( struct V_104 , V_156 ) / 2 ;
if ( V_202 )
V_166 . V_192 = V_202 ;
V_166 . V_193 = V_193 ;
F_91 ( * F_92 ( V_94 -> V_194 . F_7 ) ,
V_2 , & F_93 ( V_2 ) -> V_195 . V_196 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_94 ( V_94 , V_197 ) ;
}
static void F_98 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_209 * V_210 = F_56 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_96 ( V_2 , V_12 -> V_18 , V_12 -> V_211 ,
V_12 -> V_212 >> V_210 -> V_213 ,
V_146 + V_12 -> V_214 ,
V_12 -> V_21 ,
V_210 -> V_215 ,
F_99 ( V_12 ) ,
V_210 -> V_216 ? V_191 : 0 ,
V_210 -> V_217
) ;
F_55 ( V_210 ) ;
}
static void F_100 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 )
{
F_96 ( V_2 , ( V_8 -> V_116 == V_127 ) ?
F_44 ( V_93 ) -> V_95 + 1 : F_7 ( V_8 ) -> V_128 ,
F_44 ( V_93 ) -> V_218 , V_93 -> V_219 ,
V_146 ,
V_93 -> V_20 ,
0 ,
F_87 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_101 ( V_93 ) -> V_220 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_193 ) ;
}
static int F_102 ( const struct V_7 * V_8 , struct V_81 * V_67 ,
struct V_221 * V_52 ,
struct V_92 * V_93 ,
struct V_222 * V_223 ,
bool V_224 )
{
const struct V_225 * V_226 = F_101 ( V_93 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_67 && ( V_67 = F_103 ( V_8 , & V_34 , V_93 ) ) == NULL )
return - 1 ;
V_2 = F_104 ( V_8 , V_67 , V_93 , V_223 , V_224 ) ;
if ( V_2 ) {
F_73 ( V_2 , V_226 -> V_227 , V_226 -> V_228 ) ;
V_37 = F_105 ( V_2 , V_8 , V_226 -> V_227 ,
V_226 -> V_228 ,
V_226 -> V_46 ) ;
V_37 = F_106 ( V_37 ) ;
}
return V_37 ;
}
static void F_107 ( struct V_92 * V_93 )
{
F_108 ( F_101 ( V_93 ) -> V_46 ) ;
}
struct V_167 * F_87 ( const struct V_7 * V_8 ,
const union V_183 * V_229 ,
int V_230 )
{
const struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
unsigned int V_231 = sizeof( struct V_232 ) ;
const struct V_233 * V_234 ;
V_234 = F_109 ( V_14 -> V_235 ,
F_13 ( V_8 ) ||
F_110 ( ( V_236 * ) & V_8 -> V_237 . V_238 ) ) ;
if ( ! V_234 )
return NULL ;
#if F_111 ( V_239 )
if ( V_230 == V_240 )
V_231 = sizeof( struct V_241 ) ;
#endif
F_112 (key, &md5sig->head, node) {
if ( V_168 -> V_230 != V_230 )
continue;
if ( ! memcmp ( & V_168 -> V_229 , V_229 , V_231 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_113 ( const struct V_7 * V_8 ,
const struct V_7 * V_242 )
{
const union V_183 * V_229 ;
V_229 = ( const union V_183 * ) & V_242 -> V_243 ;
return F_87 ( V_8 , V_229 , V_42 ) ;
}
int F_114 ( struct V_7 * V_8 , const union V_183 * V_229 ,
int V_230 , const T_6 * V_244 , T_6 V_245 , T_7 V_246 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_233 * V_234 ;
V_168 = F_87 ( V_8 , V_229 , V_230 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_244 , V_245 ) ;
V_168 -> V_247 = V_245 ;
return 0 ;
}
V_234 = F_12 ( V_14 -> V_235 ,
F_13 ( V_8 ) ||
F_110 ( & V_8 -> V_237 . V_238 ) ) ;
if ( ! V_234 ) {
V_234 = F_115 ( sizeof( * V_234 ) , V_246 ) ;
if ( ! V_234 )
return - V_248 ;
F_116 ( V_8 , V_249 ) ;
F_117 ( & V_234 -> V_159 ) ;
F_118 ( V_14 -> V_235 , V_234 ) ;
}
V_168 = F_119 ( V_8 , sizeof( * V_168 ) , V_246 ) ;
if ( ! V_168 )
return - V_248 ;
if ( ! F_120 () ) {
F_121 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_248 ;
}
memcpy ( V_168 -> V_168 , V_244 , V_245 ) ;
V_168 -> V_247 = V_245 ;
V_168 -> V_230 = V_230 ;
memcpy ( & V_168 -> V_229 , V_229 ,
( V_230 == V_240 ) ? sizeof( struct V_241 ) :
sizeof( struct V_232 ) ) ;
F_122 ( & V_168 -> V_250 , & V_234 -> V_159 ) ;
return 0 ;
}
int F_123 ( struct V_7 * V_8 , const union V_183 * V_229 , int V_230 )
{
struct V_167 * V_168 ;
V_168 = F_87 ( V_8 , V_229 , V_230 ) ;
if ( ! V_168 )
return - V_251 ;
F_124 ( & V_168 -> V_250 ) ;
F_125 ( sizeof( * V_168 ) , & V_8 -> V_252 ) ;
F_126 ( V_168 , V_253 ) ;
return 0 ;
}
static void F_127 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_254 * V_255 ;
struct V_233 * V_234 ;
V_234 = F_12 ( V_14 -> V_235 , 1 ) ;
F_128 (key, n, &md5sig->head, node) {
F_124 ( & V_168 -> V_250 ) ;
F_125 ( sizeof( * V_168 ) , & V_8 -> V_252 ) ;
F_126 ( V_168 , V_253 ) ;
}
}
static int F_129 ( struct V_7 * V_8 , char T_8 * V_256 ,
int V_70 )
{
struct V_257 V_258 ;
struct V_26 * sin = (struct V_26 * ) & V_258 . V_259 ;
if ( V_70 < sizeof( V_258 ) )
return - V_40 ;
if ( F_130 ( & V_258 , V_256 , sizeof( V_258 ) ) )
return - V_260 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_258 . V_261 )
return F_123 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_258 . V_261 > V_262 )
return - V_40 ;
return F_114 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_258 . V_263 , V_258 . V_261 ,
V_264 ) ;
}
static int F_131 ( struct V_265 * V_266 ,
T_3 V_3 , T_3 V_4 , int V_267 )
{
struct V_268 * V_269 ;
struct V_270 V_271 ;
V_269 = & V_266 -> V_272 . V_54 ;
V_269 -> V_4 = V_4 ;
V_269 -> V_3 = V_3 ;
V_269 -> V_273 = 0 ;
V_269 -> V_274 = V_57 ;
V_269 -> V_157 = F_132 ( V_267 ) ;
F_133 ( & V_271 , V_269 , sizeof( * V_269 ) ) ;
return F_134 ( & V_266 -> V_275 , & V_271 , sizeof( * V_269 ) ) ;
}
static int F_89 ( char * V_276 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_104 * V_105 )
{
struct V_265 * V_266 ;
struct V_277 * V_278 ;
V_266 = F_135 () ;
if ( ! V_266 )
goto V_279;
V_278 = & V_266 -> V_275 ;
if ( F_136 ( V_278 ) )
goto V_280;
if ( F_131 ( V_266 , V_3 , V_4 , V_105 -> V_161 << 2 ) )
goto V_280;
if ( F_137 ( V_266 , V_105 ) )
goto V_280;
if ( F_138 ( V_266 , V_168 ) )
goto V_280;
if ( F_139 ( V_278 , V_276 ) )
goto V_280;
F_140 () ;
return 0 ;
V_280:
F_140 () ;
V_279:
memset ( V_276 , 0 , 16 ) ;
return 1 ;
}
int F_88 ( char * V_276 , const struct V_167 * V_168 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_265 * V_266 ;
struct V_277 * V_278 ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_281 ;
V_3 = V_8 -> V_243 ;
} else {
const struct V_101 * V_102 = F_3 ( V_2 ) ;
V_4 = V_102 -> V_4 ;
V_3 = V_102 -> V_3 ;
}
V_266 = F_135 () ;
if ( ! V_266 )
goto V_279;
V_278 = & V_266 -> V_275 ;
if ( F_136 ( V_278 ) )
goto V_280;
if ( F_131 ( V_266 , V_3 , V_4 , V_2 -> V_157 ) )
goto V_280;
if ( F_137 ( V_266 , V_105 ) )
goto V_280;
if ( F_141 ( V_266 , V_2 , V_105 -> V_161 << 2 ) )
goto V_280;
if ( F_138 ( V_266 , V_168 ) )
goto V_280;
if ( F_139 ( V_278 , V_276 ) )
goto V_280;
F_140 () ;
return 0 ;
V_280:
F_140 () ;
V_279:
memset ( V_276 , 0 , 16 ) ;
return 1 ;
}
static bool F_142 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_80
const T_5 * V_169 = NULL ;
struct V_167 * V_282 ;
const struct V_101 * V_102 = F_3 ( V_2 ) ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_282 = F_87 ( V_8 , (union V_183 * ) & V_102 -> V_4 ,
V_42 ) ;
V_169 = F_84 ( V_105 ) ;
if ( ! V_282 && ! V_169 )
return false ;
if ( V_282 && ! V_169 ) {
F_45 ( F_19 ( V_8 ) , V_283 ) ;
return true ;
}
if ( ! V_282 && V_169 ) {
F_45 ( F_19 ( V_8 ) , V_284 ) ;
return true ;
}
V_171 = F_88 ( V_170 ,
V_282 ,
NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_143 ( L_1 ,
& V_102 -> V_4 , F_52 ( V_105 -> V_6 ) ,
& V_102 -> V_3 , F_52 ( V_105 -> V_5 ) ,
V_171 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_144 ( struct V_92 * V_93 ,
const struct V_7 * V_285 ,
struct V_1 * V_2 )
{
struct V_225 * V_226 = F_101 ( V_93 ) ;
F_21 ( F_145 ( V_93 ) , F_3 ( V_2 ) -> V_3 ) ;
F_24 ( F_145 ( V_93 ) , F_3 ( V_2 ) -> V_4 ) ;
V_226 -> V_220 = F_11 ( V_285 ) -> V_190 ;
V_226 -> V_46 = F_146 ( V_2 ) ;
}
static struct V_81 * F_147 ( const struct V_7 * V_8 ,
struct V_221 * V_52 ,
const struct V_92 * V_93 ,
bool * V_286 )
{
struct V_81 * V_67 = F_103 ( V_8 , & V_52 -> V_53 . V_54 , V_93 ) ;
if ( V_286 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_101 ( V_93 ) -> V_228 )
* V_286 = true ;
else
* V_286 = false ;
}
return V_67 ;
}
int F_148 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_81 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_287;
return F_149 ( & V_288 ,
& V_289 , V_8 , V_2 ) ;
V_287:
F_45 ( F_19 ( V_8 ) , V_98 ) ;
return 0 ;
}
struct V_7 * F_150 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_81 * V_67 ,
struct V_92 * V_290 ,
bool * V_291 )
{
struct V_225 * V_226 ;
struct V_28 * V_292 ;
struct V_13 * V_293 ;
struct V_7 * V_294 ;
#ifdef F_80
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_151 ( V_8 ) )
goto V_295;
V_294 = F_152 ( V_8 , V_93 , V_2 ) ;
if ( ! V_294 )
goto V_296;
V_294 -> V_75 = V_76 ;
F_153 ( V_294 , V_2 ) ;
V_293 = F_7 ( V_294 ) ;
V_292 = F_11 ( V_294 ) ;
V_226 = F_101 ( V_93 ) ;
F_24 ( V_294 , V_226 -> V_228 ) ;
F_21 ( V_294 , V_226 -> V_227 ) ;
V_292 -> V_55 = V_226 -> V_227 ;
V_39 = V_226 -> V_46 ;
F_118 ( V_292 -> V_39 , V_39 ) ;
V_226 -> V_46 = NULL ;
V_292 -> V_297 = F_53 ( V_2 ) ;
V_292 -> V_298 = F_3 ( V_2 ) -> V_123 ;
V_292 -> V_299 = F_3 ( V_2 ) -> V_193 ;
F_25 ( V_294 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_294 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_292 -> V_77 = V_293 -> V_17 ^ V_78 ;
if ( ! V_67 ) {
V_67 = F_154 ( V_8 , V_294 , V_93 ) ;
if ( ! V_67 )
goto V_300;
} else {
}
F_30 ( V_294 , V_67 ) ;
F_155 ( V_294 , V_67 ) ;
F_37 ( V_294 , F_34 ( V_67 ) ) ;
V_293 -> V_301 = F_156 ( V_67 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_302 &&
F_7 ( V_8 ) -> V_19 . V_302 < V_293 -> V_301 )
V_293 -> V_301 = F_7 ( V_8 ) -> V_19 . V_302 ;
F_157 ( V_294 ) ;
#ifdef F_80
V_168 = F_87 ( V_8 , (union V_183 * ) & V_292 -> V_63 ,
V_42 ) ;
if ( V_168 ) {
F_114 ( V_294 , (union V_183 * ) & V_292 -> V_63 ,
V_42 , V_168 -> V_168 , V_168 -> V_247 , V_303 ) ;
F_116 ( V_294 , V_249 ) ;
}
#endif
if ( F_158 ( V_8 , V_294 ) < 0 )
goto V_300;
* V_291 = F_159 ( V_294 , F_145 ( V_290 ) ) ;
if ( * V_291 )
F_160 ( V_293 , V_93 ) ;
return V_294 ;
V_295:
F_45 ( F_19 ( V_8 ) , V_304 ) ;
V_296:
F_161 ( V_67 ) ;
exit:
F_45 ( F_19 ( V_8 ) , V_98 ) ;
return NULL ;
V_300:
F_162 ( V_294 ) ;
F_70 ( V_294 ) ;
goto exit;
}
static struct V_7 * F_163 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
#ifdef F_164
const struct V_104 * V_105 = F_4 ( V_2 ) ;
if ( ! V_105 -> V_178 )
V_8 = F_165 ( V_8 , V_2 ) ;
#endif
return V_8 ;
}
int F_166 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_305 ;
if ( V_8 -> V_116 == V_306 ) {
struct V_81 * V_67 = V_8 -> V_307 ;
F_167 ( V_8 , V_2 ) ;
F_168 ( V_8 , V_2 ) ;
if ( V_67 ) {
if ( F_11 ( V_8 ) -> V_308 != V_2 -> V_309 ||
! V_67 -> V_89 -> V_156 ( V_67 , 0 ) ) {
F_161 ( V_67 ) ;
V_8 -> V_307 = NULL ;
}
}
F_169 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_157 ) ;
return 0 ;
}
if ( F_170 ( V_2 ) )
goto V_310;
if ( V_8 -> V_116 == V_127 ) {
struct V_7 * V_311 = F_163 ( V_8 , V_2 ) ;
if ( ! V_311 )
goto V_312;
if ( V_311 != V_8 ) {
F_167 ( V_311 , V_2 ) ;
F_168 ( V_311 , V_2 ) ;
if ( F_171 ( V_8 , V_311 , V_2 ) ) {
V_305 = V_311 ;
goto V_313;
}
return 0 ;
}
} else
F_167 ( V_8 , V_2 ) ;
if ( F_172 ( V_8 , V_2 ) ) {
V_305 = V_8 ;
goto V_313;
}
return 0 ;
V_313:
F_79 ( V_305 , V_2 ) ;
V_312:
F_173 ( V_2 ) ;
return 0 ;
V_310:
F_94 ( F_19 ( V_8 ) , V_314 ) ;
F_94 ( F_19 ( V_8 ) , V_315 ) ;
goto V_312;
}
void F_174 ( struct V_1 * V_2 )
{
const struct V_101 * V_102 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
if ( V_2 -> V_316 != V_317 )
return;
if ( ! F_175 ( V_2 , F_176 ( V_2 ) + sizeof( struct V_104 ) ) )
return;
V_102 = F_3 ( V_2 ) ;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
return;
V_8 = F_51 ( F_50 ( V_2 -> V_113 ) , & V_114 ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , F_52 ( V_105 -> V_5 ) ,
V_2 -> V_309 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_318 = V_319 ;
if ( F_177 ( V_8 ) ) {
struct V_81 * V_67 = F_178 ( V_8 -> V_307 ) ;
if ( V_67 )
V_67 = F_179 ( V_67 , 0 ) ;
if ( V_67 &&
F_11 ( V_8 ) -> V_308 == V_2 -> V_309 )
F_180 ( V_2 , V_67 ) ;
}
}
}
bool F_181 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_320 || ! V_14 -> V_321 . V_322 )
return false ;
if ( V_2 -> V_157 <= F_182 ( V_2 ) &&
F_183 ( & V_14 -> V_321 . V_323 ) == 0 )
return false ;
if ( F_22 ( V_8 -> V_307 ) )
F_184 ( V_2 ) ;
else
F_185 ( V_2 ) ;
F_186 ( & V_14 -> V_321 . V_323 , V_2 ) ;
V_14 -> V_321 . V_324 += V_2 -> V_325 ;
if ( V_14 -> V_321 . V_324 > V_8 -> V_326 ) {
struct V_1 * V_327 ;
F_65 ( F_13 ( V_8 ) ) ;
while ( ( V_327 = F_187 ( & V_14 -> V_321 . V_323 ) ) != NULL ) {
F_188 ( V_8 , V_327 ) ;
F_45 ( F_19 ( V_8 ) ,
V_328 ) ;
}
V_14 -> V_321 . V_324 = 0 ;
} else if ( F_183 ( & V_14 -> V_321 . V_323 ) == 1 ) {
F_189 ( F_190 ( V_8 ) ,
V_329 | V_330 | V_331 ) ;
if ( ! F_191 ( V_8 ) )
F_68 ( V_8 , V_332 ,
( 3 * F_192 ( V_8 ) ) / 4 ,
V_145 ) ;
}
return true ;
}
int F_193 ( struct V_1 * V_2 )
{
const struct V_101 * V_102 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
int V_333 ;
struct V_94 * V_94 = F_50 ( V_2 -> V_113 ) ;
if ( V_2 -> V_316 != V_317 )
goto V_334;
F_94 ( V_94 , V_335 ) ;
if ( ! F_175 ( V_2 , sizeof( struct V_104 ) ) )
goto V_334;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
goto V_336;
if ( ! F_175 ( V_2 , V_105 -> V_161 * 4 ) )
goto V_334;
if ( F_194 ( V_2 , V_57 , V_337 ) )
goto V_338;
V_105 = F_4 ( V_2 ) ;
V_102 = F_3 ( V_2 ) ;
memmove ( & F_93 ( V_2 ) -> V_195 . V_196 , F_195 ( V_2 ) ,
sizeof( struct V_339 ) ) ;
F_196 () ;
F_93 ( V_2 ) -> V_91 = F_57 ( V_105 -> V_91 ) ;
F_93 ( V_2 ) -> V_340 = ( F_93 ( V_2 ) -> V_91 + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_157 - V_105 -> V_161 * 4 ) ;
F_93 ( V_2 ) -> V_177 = F_57 ( V_105 -> V_177 ) ;
F_93 ( V_2 ) -> V_341 = F_197 ( V_105 ) ;
F_93 ( V_2 ) -> V_342 = 0 ;
F_93 ( V_2 ) -> V_343 = F_198 ( V_102 ) ;
F_93 ( V_2 ) -> V_344 = 0 ;
V_345:
V_8 = F_199 ( & V_114 , V_2 , V_105 -> V_6 , V_105 -> V_5 ) ;
if ( ! V_8 )
goto V_346;
V_347:
if ( V_8 -> V_116 == V_117 )
goto V_348;
if ( V_8 -> V_116 == V_118 ) {
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_7 * V_311 = NULL ;
V_8 = V_93 -> V_97 ;
if ( F_142 ( V_8 , V_2 ) )
goto V_349;
if ( F_22 ( V_8 -> V_116 == V_127 ) ) {
V_311 = F_200 ( V_8 , V_2 , V_93 , false ) ;
} else {
F_201 ( V_8 , V_93 ) ;
goto V_345;
}
if ( ! V_311 ) {
F_47 ( V_93 ) ;
goto V_334;
}
if ( V_311 == V_8 ) {
F_9 ( V_8 ) ;
F_47 ( V_93 ) ;
} else if ( F_171 ( V_8 , V_311 , V_2 ) ) {
F_79 ( V_311 , V_2 ) ;
goto V_334;
} else {
return 0 ;
}
}
if ( F_59 ( V_102 -> V_123 < F_11 ( V_8 ) -> V_124 ) ) {
F_45 ( V_94 , V_125 ) ;
goto V_349;
}
if ( ! F_202 ( V_8 , V_350 , V_2 ) )
goto V_349;
if ( F_142 ( V_8 , V_2 ) )
goto V_349;
F_203 ( V_2 ) ;
if ( F_204 ( V_8 , V_2 ) )
goto V_349;
V_2 -> V_113 = NULL ;
if ( V_8 -> V_116 == V_127 ) {
V_333 = F_166 ( V_8 , V_2 ) ;
goto V_351;
}
F_205 ( V_8 ) ;
F_206 ( V_8 ) ;
F_7 ( V_8 ) -> V_352 += F_207 ( V_353 , 1 , F_208 ( V_2 ) -> V_354 ) ;
V_333 = 0 ;
if ( ! F_13 ( V_8 ) ) {
if ( ! F_181 ( V_8 , V_2 ) )
V_333 = F_166 ( V_8 , V_2 ) ;
} else if ( F_59 ( F_209 ( V_8 , V_2 ,
V_8 -> V_326 + V_8 -> V_355 ) ) ) {
F_71 ( V_8 ) ;
F_45 ( V_94 , V_356 ) ;
goto V_349;
}
F_71 ( V_8 ) ;
V_351:
F_72 ( V_8 ) ;
return V_333 ;
V_346:
if ( ! F_202 ( NULL , V_350 , V_2 ) )
goto V_334;
if ( F_170 ( V_2 ) ) {
V_338:
F_94 ( V_94 , V_314 ) ;
V_336:
F_94 ( V_94 , V_315 ) ;
} else {
F_79 ( NULL , V_2 ) ;
}
V_334:
F_173 ( V_2 ) ;
return 0 ;
V_349:
F_72 ( V_8 ) ;
goto V_334;
V_348:
if ( ! F_202 ( NULL , V_350 , V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_334;
}
if ( F_170 ( V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_338;
}
switch ( F_210 ( F_56 ( V_8 ) , V_2 , V_105 ) ) {
case V_357 : {
struct V_7 * V_358 = F_211 ( F_50 ( V_2 -> V_113 ) ,
& V_114 ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , V_105 -> V_5 ,
F_53 ( V_2 ) ) ;
if ( V_358 ) {
F_212 ( F_56 ( V_8 ) ) ;
V_8 = V_358 ;
goto V_347;
}
}
case V_359 :
F_98 ( V_8 , V_2 ) ;
break;
case V_360 :
goto V_346;
case V_361 : ;
}
goto V_334;
}
void F_153 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_81 * V_67 = F_83 ( V_2 ) ;
if ( V_67 && F_213 ( V_67 ) ) {
V_8 -> V_307 = V_67 ;
F_11 ( V_8 ) -> V_308 = V_2 -> V_309 ;
}
}
static int F_214 ( struct V_7 * V_8 )
{
struct V_107 * V_108 = F_25 ( V_8 ) ;
F_215 ( V_8 ) ;
V_108 -> V_362 = & V_363 ;
#ifdef F_80
F_7 ( V_8 ) -> V_364 = & V_365 ;
#endif
return 0 ;
}
void F_216 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_217 ( V_8 ) ;
F_218 ( V_8 ) ;
F_219 ( V_8 ) ;
F_220 ( & V_14 -> V_366 ) ;
#ifdef F_80
if ( V_14 -> V_235 ) {
F_127 ( V_8 ) ;
F_126 ( V_14 -> V_235 , V_253 ) ;
V_14 -> V_235 = NULL ;
}
#endif
F_220 ( & V_14 -> V_321 . V_323 ) ;
if ( F_25 ( V_8 ) -> V_367 )
F_221 ( V_8 ) ;
F_65 ( V_14 -> V_126 ) ;
F_222 ( V_14 ) ;
F_223 ( V_14 ) ;
F_224 ( V_8 ) ;
F_225 ( V_8 ) ;
}
static void * F_226 ( struct V_368 * V_91 , void * V_369 )
{
struct V_107 * V_108 ;
struct V_370 * V_250 ;
struct V_7 * V_8 = V_369 ;
struct V_371 * V_372 ;
struct V_373 * V_374 = V_91 -> V_375 ;
struct V_94 * V_94 = F_227 ( V_91 ) ;
if ( ! V_8 ) {
V_372 = & V_114 . V_376 [ V_374 -> V_377 ] ;
F_228 ( & V_372 -> V_378 ) ;
V_8 = F_229 ( & V_372 -> V_159 ) ;
V_374 -> V_208 = 0 ;
goto V_379;
}
V_372 = & V_114 . V_376 [ V_374 -> V_377 ] ;
++ V_374 -> V_380 ;
++ V_374 -> V_208 ;
V_8 = F_230 ( V_8 ) ;
V_379:
F_231 (sk, node) {
if ( ! F_232 ( F_19 ( V_8 ) , V_94 ) )
continue;
if ( V_8 -> V_381 == V_374 -> V_230 ) {
V_369 = V_8 ;
goto V_122;
}
V_108 = F_25 ( V_8 ) ;
}
F_233 ( & V_372 -> V_378 ) ;
V_374 -> V_208 = 0 ;
if ( ++ V_374 -> V_377 < V_382 ) {
V_372 = & V_114 . V_376 [ V_374 -> V_377 ] ;
F_228 ( & V_372 -> V_378 ) ;
V_8 = F_229 ( & V_372 -> V_159 ) ;
goto V_379;
}
V_369 = NULL ;
V_122:
return V_369 ;
}
static void * F_234 ( struct V_368 * V_91 , T_9 * V_383 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
void * V_384 ;
V_374 -> V_377 = 0 ;
V_374 -> V_208 = 0 ;
V_384 = F_226 ( V_91 , NULL ) ;
while ( V_384 && * V_383 ) {
V_384 = F_226 ( V_91 , V_384 ) ;
-- * V_383 ;
}
return V_384 ;
}
static inline bool F_235 ( const struct V_373 * V_374 )
{
return F_236 ( & V_114 . V_385 [ V_374 -> V_377 ] . V_386 ) ;
}
static void * F_237 ( struct V_368 * V_91 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
struct V_94 * V_94 = F_227 ( V_91 ) ;
void * V_384 = NULL ;
V_374 -> V_208 = 0 ;
for (; V_374 -> V_377 <= V_114 . V_387 ; ++ V_374 -> V_377 ) {
struct V_7 * V_8 ;
struct V_370 * V_250 ;
V_236 * V_378 = F_238 ( & V_114 , V_374 -> V_377 ) ;
if ( F_235 ( V_374 ) )
continue;
F_228 ( V_378 ) ;
F_239 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_381 != V_374 -> V_230 ||
! F_232 ( F_19 ( V_8 ) , V_94 ) ) {
continue;
}
V_384 = V_8 ;
goto V_122;
}
F_233 ( V_378 ) ;
}
V_122:
return V_384 ;
}
static void * F_240 ( struct V_368 * V_91 , void * V_369 )
{
struct V_7 * V_8 = V_369 ;
struct V_370 * V_250 ;
struct V_373 * V_374 = V_91 -> V_375 ;
struct V_94 * V_94 = F_227 ( V_91 ) ;
++ V_374 -> V_380 ;
++ V_374 -> V_208 ;
V_8 = F_230 ( V_8 ) ;
F_231 (sk, node) {
if ( V_8 -> V_381 == V_374 -> V_230 && F_232 ( F_19 ( V_8 ) , V_94 ) )
return V_8 ;
}
F_233 ( F_238 ( & V_114 , V_374 -> V_377 ) ) ;
++ V_374 -> V_377 ;
return F_237 ( V_91 ) ;
}
static void * F_241 ( struct V_368 * V_91 , T_9 V_383 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
void * V_384 ;
V_374 -> V_377 = 0 ;
V_384 = F_237 ( V_91 ) ;
while ( V_384 && V_383 ) {
V_384 = F_240 ( V_91 , V_384 ) ;
-- V_383 ;
}
return V_384 ;
}
static void * F_242 ( struct V_368 * V_91 , T_9 V_383 )
{
void * V_384 ;
struct V_373 * V_374 = V_91 -> V_375 ;
V_374 -> V_388 = V_389 ;
V_384 = F_234 ( V_91 , & V_383 ) ;
if ( ! V_384 ) {
V_374 -> V_388 = V_390 ;
V_384 = F_241 ( V_91 , V_383 ) ;
}
return V_384 ;
}
static void * F_243 ( struct V_368 * V_91 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
int V_208 = V_374 -> V_208 ;
int V_391 = V_374 -> V_380 ;
void * V_384 = NULL ;
switch ( V_374 -> V_388 ) {
case V_389 :
if ( V_374 -> V_377 >= V_382 )
break;
V_374 -> V_388 = V_389 ;
V_384 = F_226 ( V_91 , NULL ) ;
while ( V_208 -- && V_384 )
V_384 = F_226 ( V_91 , V_384 ) ;
if ( V_384 )
break;
V_374 -> V_377 = 0 ;
V_374 -> V_388 = V_390 ;
case V_390 :
if ( V_374 -> V_377 > V_114 . V_387 )
break;
V_384 = F_237 ( V_91 ) ;
while ( V_208 -- && V_384 )
V_384 = F_240 ( V_91 , V_384 ) ;
}
V_374 -> V_380 = V_391 ;
return V_384 ;
}
static void * F_244 ( struct V_368 * V_91 , T_9 * V_383 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
void * V_384 ;
if ( * V_383 && * V_383 == V_374 -> V_392 ) {
V_384 = F_243 ( V_91 ) ;
if ( V_384 )
goto V_122;
}
V_374 -> V_388 = V_389 ;
V_374 -> V_380 = 0 ;
V_374 -> V_377 = 0 ;
V_374 -> V_208 = 0 ;
V_384 = * V_383 ? F_242 ( V_91 , * V_383 - 1 ) : V_393 ;
V_122:
V_374 -> V_392 = * V_383 ;
return V_384 ;
}
static void * F_245 ( struct V_368 * V_91 , void * V_394 , T_9 * V_383 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
void * V_384 = NULL ;
if ( V_394 == V_393 ) {
V_384 = F_242 ( V_91 , 0 ) ;
goto V_122;
}
switch ( V_374 -> V_388 ) {
case V_389 :
V_384 = F_226 ( V_91 , V_394 ) ;
if ( ! V_384 ) {
V_374 -> V_388 = V_390 ;
V_374 -> V_377 = 0 ;
V_374 -> V_208 = 0 ;
V_384 = F_237 ( V_91 ) ;
}
break;
case V_390 :
V_384 = F_240 ( V_91 , V_394 ) ;
break;
}
V_122:
++ * V_383 ;
V_374 -> V_392 = * V_383 ;
return V_384 ;
}
static void F_246 ( struct V_368 * V_91 , void * V_394 )
{
struct V_373 * V_374 = V_91 -> V_375 ;
switch ( V_374 -> V_388 ) {
case V_389 :
if ( V_394 != V_393 )
F_233 ( & V_114 . V_376 [ V_374 -> V_377 ] . V_378 ) ;
break;
case V_390 :
if ( V_394 )
F_233 ( F_238 ( & V_114 , V_374 -> V_377 ) ) ;
break;
}
}
int F_247 ( struct V_395 * V_395 , struct V_396 * V_396 )
{
struct V_397 * V_398 = F_248 ( V_395 ) ;
struct V_373 * V_399 ;
int V_37 ;
V_37 = F_249 ( V_395 , V_396 , & V_398 -> V_400 ,
sizeof( struct V_373 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_399 = ( (struct V_368 * ) V_396 -> V_401 ) -> V_375 ;
V_399 -> V_230 = V_398 -> V_230 ;
V_399 -> V_392 = 0 ;
return 0 ;
}
int F_250 ( struct V_94 * V_94 , struct V_397 * V_398 )
{
int V_384 = 0 ;
struct V_402 * V_403 ;
V_398 -> V_400 . V_404 = F_244 ;
V_398 -> V_400 . V_405 = F_245 ;
V_398 -> V_400 . V_406 = F_246 ;
V_403 = F_251 ( V_398 -> V_407 , V_408 , V_94 -> V_409 ,
V_398 -> V_410 , V_398 ) ;
if ( ! V_403 )
V_384 = - V_248 ;
return V_384 ;
}
void F_252 ( struct V_94 * V_94 , struct V_397 * V_398 )
{
F_253 ( V_398 -> V_407 , V_94 -> V_409 ) ;
}
static void F_254 ( const struct V_92 * V_93 ,
struct V_368 * V_411 , int V_412 )
{
const struct V_225 * V_226 = F_101 ( V_93 ) ;
long V_413 = V_93 -> V_414 . V_415 - V_78 ;
F_255 ( V_411 , L_4
L_5 ,
V_412 ,
V_226 -> V_227 ,
V_226 -> V_416 ,
V_226 -> V_228 ,
F_52 ( V_226 -> V_417 ) ,
V_150 ,
0 , 0 ,
1 ,
F_256 ( V_413 ) ,
V_93 -> V_418 ,
F_257 ( F_258 ( V_411 ) ,
F_259 ( V_93 -> V_97 ) ) ,
0 ,
0 ,
0 ,
V_93 ) ;
}
static void F_260 ( struct V_7 * V_8 , struct V_368 * V_411 , int V_412 )
{
int V_419 ;
unsigned long V_420 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_107 * V_108 = F_25 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
const struct V_421 * V_422 = & V_108 -> V_423 . V_422 ;
T_3 V_5 = V_29 -> V_63 ;
T_3 V_424 = V_29 -> V_425 ;
T_10 V_426 = F_52 ( V_29 -> V_68 ) ;
T_10 V_427 = F_52 ( V_29 -> V_49 ) ;
int V_428 ;
int V_388 ;
if ( V_108 -> V_429 == V_147 ||
V_108 -> V_429 == V_430 ||
V_108 -> V_429 == V_431 ) {
V_419 = 1 ;
V_420 = V_108 -> V_432 ;
} else if ( V_108 -> V_429 == V_433 ) {
V_419 = 4 ;
V_420 = V_108 -> V_432 ;
} else if ( F_261 ( & V_8 -> V_434 ) ) {
V_419 = 2 ;
V_420 = V_8 -> V_434 . V_415 ;
} else {
V_419 = 0 ;
V_420 = V_78 ;
}
V_388 = F_262 ( V_8 ) ;
if ( V_388 == V_127 )
V_428 = V_8 -> V_435 ;
else
V_428 = F_207 ( int , V_14 -> V_218 - V_14 -> V_436 , 0 ) ;
F_255 ( V_411 , L_6
L_7 ,
V_412 , V_424 , V_427 , V_5 , V_426 , V_388 ,
V_14 -> V_17 - V_14 -> V_111 ,
V_428 ,
V_419 ,
F_256 ( V_420 - V_78 ) ,
V_108 -> V_140 ,
F_257 ( F_258 ( V_411 ) , F_259 ( V_8 ) ) ,
V_108 -> V_437 ,
F_263 ( V_8 ) ,
F_264 ( & V_8 -> V_438 ) , V_8 ,
F_265 ( V_108 -> V_142 ) ,
F_265 ( V_108 -> V_439 . V_440 ) ,
( V_108 -> V_439 . V_441 << 1 ) | V_108 -> V_439 . V_442 ,
V_14 -> V_443 ,
V_388 == V_127 ?
V_422 -> V_444 :
( F_266 ( V_14 ) ? - 1 : V_14 -> V_445 ) ) ;
}
static void F_267 ( const struct V_209 * V_210 ,
struct V_368 * V_411 , int V_412 )
{
long V_413 = V_210 -> V_446 . V_415 - V_78 ;
T_3 V_5 , V_424 ;
T_10 V_426 , V_427 ;
V_5 = V_210 -> V_447 ;
V_424 = V_210 -> V_448 ;
V_426 = F_52 ( V_210 -> V_449 ) ;
V_427 = F_52 ( V_210 -> V_450 ) ;
F_255 ( V_411 , L_4
L_8 ,
V_412 , V_424 , V_427 , V_5 , V_426 , V_210 -> V_451 , 0 , 0 ,
3 , F_256 ( V_413 ) , 0 , 0 , 0 , 0 ,
F_264 ( & V_210 -> V_452 ) , V_210 ) ;
}
static int F_268 ( struct V_368 * V_91 , void * V_394 )
{
struct V_373 * V_374 ;
struct V_7 * V_8 = V_394 ;
F_269 ( V_91 , V_453 - 1 ) ;
if ( V_394 == V_393 ) {
F_270 ( V_91 , L_9
L_10
L_11 ) ;
goto V_122;
}
V_374 = V_91 -> V_375 ;
if ( V_8 -> V_116 == V_117 )
F_267 ( V_394 , V_91 , V_374 -> V_380 ) ;
else if ( V_8 -> V_116 == V_118 )
F_254 ( V_394 , V_91 , V_374 -> V_380 ) ;
else
F_260 ( V_394 , V_91 , V_374 -> V_380 ) ;
V_122:
F_271 ( V_91 , '\n' ) ;
return 0 ;
}
static int T_11 F_272 ( struct V_94 * V_94 )
{
return F_250 ( V_94 , & V_454 ) ;
}
static void T_12 F_273 ( struct V_94 * V_94 )
{
F_252 ( V_94 , & V_454 ) ;
}
int T_13 F_274 ( void )
{
return F_275 ( & V_455 ) ;
}
void F_276 ( void )
{
F_277 ( & V_455 ) ;
}
static void T_12 F_278 ( struct V_94 * V_94 )
{
int V_456 ;
F_279 (cpu)
F_280 ( * F_281 ( V_94 -> V_194 . F_7 , V_456 ) ) ;
F_282 ( V_94 -> V_194 . F_7 ) ;
}
static int T_11 F_283 ( struct V_94 * V_94 )
{
int V_457 , V_456 ;
V_94 -> V_194 . F_7 = F_284 ( struct V_7 * ) ;
if ( ! V_94 -> V_194 . F_7 )
return - V_248 ;
F_279 (cpu) {
struct V_7 * V_8 ;
V_457 = F_285 ( & V_8 , V_458 , V_459 ,
V_57 , V_94 ) ;
if ( V_457 )
goto V_460;
* F_281 ( V_94 -> V_194 . F_7 , V_456 ) = V_8 ;
}
V_94 -> V_194 . V_461 = 2 ;
V_94 -> V_194 . V_462 = 1 ;
V_94 -> V_194 . V_463 = V_464 ;
V_94 -> V_194 . V_465 = V_466 ;
V_94 -> V_194 . V_467 = V_468 ;
return 0 ;
V_460:
F_278 ( V_94 ) ;
return V_457 ;
}
static void T_12 F_286 ( struct V_469 * V_470 )
{
F_287 ( & V_114 , & V_65 , V_42 ) ;
}
void T_13 F_288 ( void )
{
F_289 ( & V_114 ) ;
if ( F_275 ( & V_471 ) )
F_290 ( L_12 ) ;
}
