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
void F_41 ( struct V_7 * V_8 , T_4 V_91 , bool abort )
{
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_94 * V_94 = F_19 ( V_8 ) ;
F_43 ( V_93 -> V_8 ) ;
if ( V_91 != F_44 ( V_93 ) -> V_95 ) {
F_45 ( V_94 , V_96 ) ;
} else if ( abort ) {
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
return F_41 ( V_8 , V_91 ,
type == V_119 ||
type == V_120 ||
( type == V_121 &&
( V_109 == V_122 ||
V_109 == V_123 ) ) ) ;
F_58 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_121 && V_109 == V_124 ) )
F_45 ( V_94 , V_125 ) ;
}
if ( V_8 -> V_116 == V_79 )
goto V_126;
if ( F_59 ( V_102 -> V_127 < F_11 ( V_8 ) -> V_128 ) ) {
F_45 ( V_94 , V_129 ) ;
goto V_126;
}
V_108 = F_25 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_110 = V_14 -> V_130 ;
V_111 = V_110 ? F_44 ( V_110 ) -> V_95 : V_14 -> V_111 ;
if ( V_8 -> V_116 != V_131 &&
! F_60 ( V_91 , V_111 , V_14 -> V_132 ) ) {
F_45 ( V_94 , V_96 ) ;
goto V_126;
}
switch ( type ) {
case V_133 :
F_39 ( V_99 , V_8 ) ;
goto V_126;
case V_134 :
goto V_126;
case V_119 :
V_37 = V_135 ;
break;
case V_121 :
if ( V_109 > V_136 )
goto V_126;
if ( V_109 == V_124 ) {
if ( V_8 -> V_116 == V_131 )
goto V_126;
V_14 -> V_83 = V_100 ;
if ( ! F_13 ( V_8 ) ) {
F_32 ( V_8 ) ;
} else {
if ( ! F_61 ( V_137 , & V_14 -> V_138 ) )
F_9 ( V_8 ) ;
}
goto V_126;
}
V_37 = V_139 [ V_109 ] . V_140 ;
if ( V_109 != V_122 && V_109 != V_123 )
break;
if ( V_91 != V_14 -> V_111 || ! V_108 -> V_141 ||
! V_108 -> V_142 || V_110 )
break;
if ( F_13 ( V_8 ) )
break;
V_108 -> V_142 -- ;
V_108 -> V_143 = V_14 -> V_144 ? F_62 ( V_14 ) :
V_145 ;
V_108 -> V_143 = F_63 ( V_108 , V_146 ) ;
V_2 = F_64 ( V_8 ) ;
F_65 ( ! V_2 ) ;
V_112 = V_108 -> V_143 -
F_66 ( V_108 -> V_143 ,
V_147 - F_67 ( V_2 ) ) ;
if ( V_112 ) {
F_68 ( V_8 , V_148 ,
V_112 , V_146 ) ;
} else {
F_69 ( V_8 ) ;
}
break;
case V_120 :
V_37 = V_149 ;
break;
default:
goto V_126;
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
goto V_126;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_153 ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
} else {
V_8 -> V_84 = V_37 ;
}
V_126:
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
struct V_167 * V_168 = NULL ;
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
if ( V_8 && F_85 ( V_8 ) ) {
V_168 = F_86 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
} else if ( V_169 ) {
V_172 = F_87 ( V_94 ,
& V_114 , F_3 ( V_2 ) -> V_4 ,
V_105 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_52 ( V_105 -> V_6 ) , F_53 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_88 () ;
V_168 = F_86 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_89 ( V_170 , V_168 , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_82 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_90 ( ( T_5 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_162 = F_91 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_76 ( struct V_104 , V_156 ) / 2 ;
V_166 . V_189 = ( V_8 && F_92 ( V_8 ) ) ? V_190 : 0 ;
if ( V_8 )
V_166 . V_191 = V_8 -> V_56 ;
F_93 ( F_76 ( struct V_7 , V_56 ) !=
F_76 ( struct V_192 , V_193 ) ) ;
V_166 . V_194 = F_3 ( V_2 ) -> V_194 ;
F_94 ( * F_95 ( V_94 -> V_195 . F_7 ) ,
V_2 , & F_96 ( V_2 ) -> V_196 . V_197 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_97 ( V_94 , V_198 ) ;
F_97 ( V_94 , V_199 ) ;
#ifdef F_80
V_184:
if ( V_172 ) {
F_98 () ;
F_72 ( V_172 ) ;
}
#endif
}
static void F_99 ( struct V_94 * V_94 ,
struct V_1 * V_2 , T_4 V_91 , T_4 V_176 ,
T_4 V_200 , T_4 V_201 , T_4 V_202 , int V_203 ,
struct V_167 * V_168 ,
int V_204 , T_6 V_194 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
T_3 V_46 [ ( V_205 >> 2 )
#ifdef F_80
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
memset ( & V_164 . V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
if ( V_202 ) {
V_164 . V_46 [ 0 ] = F_82 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_206 << 8 ) |
V_207 ) ;
V_164 . V_46 [ 1 ] = F_82 ( V_201 ) ;
V_164 . V_46 [ 2 ] = F_82 ( V_202 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_205 ;
}
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_105 . V_91 = F_82 ( V_91 ) ;
V_164 . V_105 . V_177 = F_82 ( V_176 ) ;
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_208 = F_100 ( V_200 ) ;
#ifdef F_80
if ( V_168 ) {
int V_209 = ( V_202 ) ? 3 : 0 ;
V_164 . V_46 [ V_209 ++ ] = F_82 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_90 ( ( T_5 * ) & V_164 . V_46 [ V_209 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_189 = V_204 ;
V_166 . V_162 = F_91 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_76 ( struct V_104 , V_156 ) / 2 ;
if ( V_203 )
V_166 . V_191 = V_203 ;
V_166 . V_194 = V_194 ;
F_94 ( * F_95 ( V_94 -> V_195 . F_7 ) ,
V_2 , & F_96 ( V_2 ) -> V_196 . V_197 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_97 ( V_94 , V_198 ) ;
}
static void F_101 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_192 * V_210 = F_56 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_99 ( F_19 ( V_8 ) , V_2 ,
V_12 -> V_18 , V_12 -> V_211 ,
V_12 -> V_212 >> V_210 -> V_213 ,
V_147 + V_12 -> V_214 ,
V_12 -> V_21 ,
V_210 -> V_193 ,
F_102 ( V_12 ) ,
V_210 -> V_215 ? V_190 : 0 ,
V_210 -> V_216
) ;
F_55 ( V_210 ) ;
}
static void F_103 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 )
{
T_4 V_91 = ( V_8 -> V_116 == V_131 ) ? F_44 ( V_93 ) -> V_95 + 1 :
F_7 ( V_8 ) -> V_132 ;
F_99 ( F_19 ( V_8 ) , V_2 , V_91 ,
F_44 ( V_93 ) -> V_217 , V_93 -> V_218 ,
V_147 ,
V_93 -> V_20 ,
0 ,
F_86 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_104 ( V_93 ) -> V_219 ? V_190 : 0 ,
F_3 ( V_2 ) -> V_194 ) ;
}
static int F_105 ( const struct V_7 * V_8 , struct V_81 * V_67 ,
struct V_220 * V_52 ,
struct V_92 * V_93 ,
struct V_221 * V_222 ,
bool V_223 )
{
const struct V_224 * V_225 = F_104 ( V_93 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_67 && ( V_67 = F_106 ( V_8 , & V_34 , V_93 ) ) == NULL )
return - 1 ;
V_2 = F_107 ( V_8 , V_67 , V_93 , V_222 , V_223 ) ;
if ( V_2 ) {
F_73 ( V_2 , V_225 -> V_226 , V_225 -> V_227 ) ;
V_37 = F_108 ( V_2 , V_8 , V_225 -> V_226 ,
V_225 -> V_227 ,
V_225 -> V_46 ) ;
V_37 = F_109 ( V_37 ) ;
}
return V_37 ;
}
static void F_110 ( struct V_92 * V_93 )
{
F_111 ( F_104 ( V_93 ) -> V_46 ) ;
}
struct V_167 * F_86 ( const struct V_7 * V_8 ,
const union V_183 * V_228 ,
int V_229 )
{
const struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
unsigned int V_230 = sizeof( struct V_231 ) ;
const struct V_232 * V_233 ;
V_233 = F_112 ( V_14 -> V_234 ,
F_13 ( V_8 ) ||
F_113 ( ( V_235 * ) & V_8 -> V_236 . V_237 ) ) ;
if ( ! V_233 )
return NULL ;
#if F_114 ( V_238 )
if ( V_229 == V_239 )
V_230 = sizeof( struct V_240 ) ;
#endif
F_115 (key, &md5sig->head, node) {
if ( V_168 -> V_229 != V_229 )
continue;
if ( ! memcmp ( & V_168 -> V_228 , V_228 , V_230 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_116 ( const struct V_7 * V_8 ,
const struct V_7 * V_241 )
{
const union V_183 * V_228 ;
V_228 = ( const union V_183 * ) & V_241 -> V_242 ;
return F_86 ( V_8 , V_228 , V_42 ) ;
}
int F_117 ( struct V_7 * V_8 , const union V_183 * V_228 ,
int V_229 , const T_6 * V_243 , T_6 V_244 , T_7 V_245 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_232 * V_233 ;
V_168 = F_86 ( V_8 , V_228 , V_229 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_243 , V_244 ) ;
V_168 -> V_246 = V_244 ;
return 0 ;
}
V_233 = F_12 ( V_14 -> V_234 ,
F_13 ( V_8 ) ||
F_113 ( & V_8 -> V_236 . V_237 ) ) ;
if ( ! V_233 ) {
V_233 = F_118 ( sizeof( * V_233 ) , V_245 ) ;
if ( ! V_233 )
return - V_247 ;
F_119 ( V_8 , V_248 ) ;
F_120 ( & V_233 -> V_159 ) ;
F_121 ( V_14 -> V_234 , V_233 ) ;
}
V_168 = F_122 ( V_8 , sizeof( * V_168 ) , V_245 ) ;
if ( ! V_168 )
return - V_247 ;
if ( ! F_123 () ) {
F_124 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_247 ;
}
memcpy ( V_168 -> V_168 , V_243 , V_244 ) ;
V_168 -> V_246 = V_244 ;
V_168 -> V_229 = V_229 ;
memcpy ( & V_168 -> V_228 , V_228 ,
( V_229 == V_239 ) ? sizeof( struct V_240 ) :
sizeof( struct V_231 ) ) ;
F_125 ( & V_168 -> V_249 , & V_233 -> V_159 ) ;
return 0 ;
}
int F_126 ( struct V_7 * V_8 , const union V_183 * V_228 , int V_229 )
{
struct V_167 * V_168 ;
V_168 = F_86 ( V_8 , V_228 , V_229 ) ;
if ( ! V_168 )
return - V_250 ;
F_127 ( & V_168 -> V_249 ) ;
F_128 ( sizeof( * V_168 ) , & V_8 -> V_251 ) ;
F_129 ( V_168 , V_252 ) ;
return 0 ;
}
static void F_130 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_253 * V_254 ;
struct V_232 * V_233 ;
V_233 = F_12 ( V_14 -> V_234 , 1 ) ;
F_131 (key, n, &md5sig->head, node) {
F_127 ( & V_168 -> V_249 ) ;
F_128 ( sizeof( * V_168 ) , & V_8 -> V_251 ) ;
F_129 ( V_168 , V_252 ) ;
}
}
static int F_132 ( struct V_7 * V_8 , char T_8 * V_255 ,
int V_70 )
{
struct V_256 V_257 ;
struct V_26 * sin = (struct V_26 * ) & V_257 . V_258 ;
if ( V_70 < sizeof( V_257 ) )
return - V_40 ;
if ( F_133 ( & V_257 , V_255 , sizeof( V_257 ) ) )
return - V_259 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_257 . V_260 )
return F_126 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_257 . V_260 > V_261 )
return - V_40 ;
return F_117 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_257 . V_262 , V_257 . V_260 ,
V_263 ) ;
}
static int F_134 ( struct V_264 * V_265 ,
T_3 V_3 , T_3 V_4 , int V_266 )
{
struct V_267 * V_268 ;
struct V_269 V_270 ;
V_268 = & V_265 -> V_271 . V_54 ;
V_268 -> V_4 = V_4 ;
V_268 -> V_3 = V_3 ;
V_268 -> V_272 = 0 ;
V_268 -> V_273 = V_57 ;
V_268 -> V_157 = F_135 ( V_266 ) ;
F_136 ( & V_270 , V_268 , sizeof( * V_268 ) ) ;
return F_137 ( & V_265 -> V_274 , & V_270 , sizeof( * V_268 ) ) ;
}
static int F_90 ( char * V_275 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_104 * V_105 )
{
struct V_264 * V_265 ;
struct V_276 * V_277 ;
V_265 = F_138 () ;
if ( ! V_265 )
goto V_278;
V_277 = & V_265 -> V_274 ;
if ( F_139 ( V_277 ) )
goto V_279;
if ( F_134 ( V_265 , V_3 , V_4 , V_105 -> V_161 << 2 ) )
goto V_279;
if ( F_140 ( V_265 , V_105 ) )
goto V_279;
if ( F_141 ( V_265 , V_168 ) )
goto V_279;
if ( F_142 ( V_277 , V_275 ) )
goto V_279;
F_143 () ;
return 0 ;
V_279:
F_143 () ;
V_278:
memset ( V_275 , 0 , 16 ) ;
return 1 ;
}
int F_89 ( char * V_275 , const struct V_167 * V_168 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_264 * V_265 ;
struct V_276 * V_277 ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_280 ;
V_3 = V_8 -> V_242 ;
} else {
const struct V_101 * V_102 = F_3 ( V_2 ) ;
V_4 = V_102 -> V_4 ;
V_3 = V_102 -> V_3 ;
}
V_265 = F_138 () ;
if ( ! V_265 )
goto V_278;
V_277 = & V_265 -> V_274 ;
if ( F_139 ( V_277 ) )
goto V_279;
if ( F_134 ( V_265 , V_3 , V_4 , V_2 -> V_157 ) )
goto V_279;
if ( F_140 ( V_265 , V_105 ) )
goto V_279;
if ( F_144 ( V_265 , V_2 , V_105 -> V_161 << 2 ) )
goto V_279;
if ( F_141 ( V_265 , V_168 ) )
goto V_279;
if ( F_142 ( V_277 , V_275 ) )
goto V_279;
F_143 () ;
return 0 ;
V_279:
F_143 () ;
V_278:
memset ( V_275 , 0 , 16 ) ;
return 1 ;
}
static bool F_145 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_80
const T_5 * V_169 = NULL ;
struct V_167 * V_281 ;
const struct V_101 * V_102 = F_3 ( V_2 ) ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_281 = F_86 ( V_8 , (union V_183 * ) & V_102 -> V_4 ,
V_42 ) ;
V_169 = F_84 ( V_105 ) ;
if ( ! V_281 && ! V_169 )
return false ;
if ( V_281 && ! V_169 ) {
F_45 ( F_19 ( V_8 ) , V_282 ) ;
return true ;
}
if ( ! V_281 && V_169 ) {
F_45 ( F_19 ( V_8 ) , V_283 ) ;
return true ;
}
V_171 = F_89 ( V_170 ,
V_281 ,
NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_146 ( L_1 ,
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
static void F_147 ( struct V_92 * V_93 ,
const struct V_7 * V_284 ,
struct V_1 * V_2 )
{
struct V_224 * V_225 = F_104 ( V_93 ) ;
F_21 ( F_148 ( V_93 ) , F_3 ( V_2 ) -> V_3 ) ;
F_24 ( F_148 ( V_93 ) , F_3 ( V_2 ) -> V_4 ) ;
V_225 -> V_219 = F_11 ( V_284 ) -> V_285 ;
V_225 -> V_46 = F_149 ( V_2 ) ;
}
static struct V_81 * F_150 ( const struct V_7 * V_8 ,
struct V_220 * V_52 ,
const struct V_92 * V_93 ,
bool * V_286 )
{
struct V_81 * V_67 = F_106 ( V_8 , & V_52 -> V_53 . V_54 , V_93 ) ;
if ( V_286 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_104 ( V_93 ) -> V_227 )
* V_286 = true ;
else
* V_286 = false ;
}
return V_67 ;
}
int F_151 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_81 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_287;
return F_152 ( & V_288 ,
& V_289 , V_8 , V_2 ) ;
V_287:
F_45 ( F_19 ( V_8 ) , V_98 ) ;
return 0 ;
}
struct V_7 * F_153 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_81 * V_67 ,
struct V_92 * V_290 ,
bool * V_291 )
{
struct V_224 * V_225 ;
struct V_28 * V_292 ;
struct V_13 * V_293 ;
struct V_7 * V_294 ;
#ifdef F_80
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_154 ( V_8 ) )
goto V_295;
V_294 = F_155 ( V_8 , V_93 , V_2 ) ;
if ( ! V_294 )
goto V_296;
V_294 -> V_75 = V_76 ;
F_156 ( V_294 , V_2 ) ;
V_293 = F_7 ( V_294 ) ;
V_292 = F_11 ( V_294 ) ;
V_225 = F_104 ( V_93 ) ;
F_24 ( V_294 , V_225 -> V_227 ) ;
F_21 ( V_294 , V_225 -> V_226 ) ;
V_294 -> V_56 = V_225 -> V_297 ;
V_292 -> V_55 = V_225 -> V_226 ;
V_39 = V_225 -> V_46 ;
F_121 ( V_292 -> V_39 , V_39 ) ;
V_225 -> V_46 = NULL ;
V_292 -> V_298 = F_53 ( V_2 ) ;
V_292 -> V_299 = F_3 ( V_2 ) -> V_127 ;
V_292 -> V_300 = F_3 ( V_2 ) -> V_194 ;
F_25 ( V_294 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_294 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_292 -> V_77 = V_293 -> V_17 ^ V_78 ;
if ( ! V_67 ) {
V_67 = F_157 ( V_8 , V_294 , V_93 ) ;
if ( ! V_67 )
goto V_301;
} else {
}
F_30 ( V_294 , V_67 ) ;
F_158 ( V_294 , V_67 ) ;
F_37 ( V_294 , F_34 ( V_67 ) ) ;
V_293 -> V_302 = F_159 ( V_67 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_303 &&
F_7 ( V_8 ) -> V_19 . V_303 < V_293 -> V_302 )
V_293 -> V_302 = F_7 ( V_8 ) -> V_19 . V_303 ;
F_160 ( V_294 ) ;
#ifdef F_80
V_168 = F_86 ( V_8 , (union V_183 * ) & V_292 -> V_63 ,
V_42 ) ;
if ( V_168 ) {
F_117 ( V_294 , (union V_183 * ) & V_292 -> V_63 ,
V_42 , V_168 -> V_168 , V_168 -> V_246 , V_304 ) ;
F_119 ( V_294 , V_248 ) ;
}
#endif
if ( F_161 ( V_8 , V_294 ) < 0 )
goto V_301;
* V_291 = F_162 ( V_294 , F_148 ( V_290 ) ) ;
if ( * V_291 )
F_163 ( V_293 , V_93 ) ;
return V_294 ;
V_295:
F_45 ( F_19 ( V_8 ) , V_305 ) ;
V_296:
F_164 ( V_67 ) ;
exit:
F_45 ( F_19 ( V_8 ) , V_98 ) ;
return NULL ;
V_301:
F_165 ( V_294 ) ;
F_70 ( V_294 ) ;
goto exit;
}
static struct V_7 * F_166 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
#ifdef F_167
const struct V_104 * V_105 = F_4 ( V_2 ) ;
if ( ! V_105 -> V_178 )
V_8 = F_168 ( V_8 , V_2 ) ;
#endif
return V_8 ;
}
int F_169 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_306 ;
if ( V_8 -> V_116 == V_307 ) {
struct V_81 * V_67 = V_8 -> V_308 ;
F_170 ( V_8 , V_2 ) ;
F_171 ( V_8 , V_2 ) ;
if ( V_67 ) {
if ( F_11 ( V_8 ) -> V_309 != V_2 -> V_310 ||
! V_67 -> V_89 -> V_156 ( V_67 , 0 ) ) {
F_164 ( V_67 ) ;
V_8 -> V_308 = NULL ;
}
}
F_172 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_157 ) ;
return 0 ;
}
if ( F_173 ( V_2 ) )
goto V_311;
if ( V_8 -> V_116 == V_131 ) {
struct V_7 * V_312 = F_166 ( V_8 , V_2 ) ;
if ( ! V_312 )
goto V_313;
if ( V_312 != V_8 ) {
F_170 ( V_312 , V_2 ) ;
F_171 ( V_312 , V_2 ) ;
if ( F_174 ( V_8 , V_312 , V_2 ) ) {
V_306 = V_312 ;
goto V_314;
}
return 0 ;
}
} else
F_170 ( V_8 , V_2 ) ;
if ( F_175 ( V_8 , V_2 ) ) {
V_306 = V_8 ;
goto V_314;
}
return 0 ;
V_314:
F_79 ( V_306 , V_2 ) ;
V_313:
F_176 ( V_2 ) ;
return 0 ;
V_311:
F_97 ( F_19 ( V_8 ) , V_315 ) ;
F_97 ( F_19 ( V_8 ) , V_316 ) ;
goto V_313;
}
void F_177 ( struct V_1 * V_2 )
{
const struct V_101 * V_102 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
if ( V_2 -> V_317 != V_318 )
return;
if ( ! F_178 ( V_2 , F_179 ( V_2 ) + sizeof( struct V_104 ) ) )
return;
V_102 = F_3 ( V_2 ) ;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
return;
V_8 = F_51 ( F_50 ( V_2 -> V_113 ) , & V_114 ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , F_52 ( V_105 -> V_5 ) ,
V_2 -> V_310 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_319 = V_320 ;
if ( F_85 ( V_8 ) ) {
struct V_81 * V_67 = F_180 ( V_8 -> V_308 ) ;
if ( V_67 )
V_67 = F_181 ( V_67 , 0 ) ;
if ( V_67 &&
F_11 ( V_8 ) -> V_309 == V_2 -> V_310 )
F_182 ( V_2 , V_67 ) ;
}
}
}
bool F_183 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_321 || ! V_14 -> V_322 . V_323 )
return false ;
if ( V_2 -> V_157 <= F_184 ( V_2 ) &&
F_185 ( & V_14 -> V_322 . V_324 ) == 0 )
return false ;
if ( F_22 ( V_8 -> V_308 ) )
F_186 ( V_2 ) ;
else
F_187 ( V_2 ) ;
F_188 ( & V_14 -> V_322 . V_324 , V_2 ) ;
V_14 -> V_322 . V_325 += V_2 -> V_326 ;
if ( V_14 -> V_322 . V_325 > V_8 -> V_327 ) {
struct V_1 * V_328 ;
F_65 ( F_13 ( V_8 ) ) ;
while ( ( V_328 = F_189 ( & V_14 -> V_322 . V_324 ) ) != NULL ) {
F_190 ( V_8 , V_328 ) ;
F_45 ( F_19 ( V_8 ) ,
V_329 ) ;
}
V_14 -> V_322 . V_325 = 0 ;
} else if ( F_185 ( & V_14 -> V_322 . V_324 ) == 1 ) {
F_191 ( F_192 ( V_8 ) ,
V_330 | V_331 | V_332 ) ;
if ( ! F_193 ( V_8 ) )
F_68 ( V_8 , V_333 ,
( 3 * F_194 ( V_8 ) ) / 4 ,
V_146 ) ;
}
return true ;
}
int F_195 ( struct V_1 * V_2 )
{
const struct V_101 * V_102 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
int V_334 ;
struct V_94 * V_94 = F_50 ( V_2 -> V_113 ) ;
if ( V_2 -> V_317 != V_318 )
goto V_335;
F_97 ( V_94 , V_336 ) ;
if ( ! F_178 ( V_2 , sizeof( struct V_104 ) ) )
goto V_335;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
goto V_337;
if ( ! F_178 ( V_2 , V_105 -> V_161 * 4 ) )
goto V_335;
if ( F_196 ( V_2 , V_57 , V_338 ) )
goto V_339;
V_105 = F_4 ( V_2 ) ;
V_102 = F_3 ( V_2 ) ;
memmove ( & F_96 ( V_2 ) -> V_196 . V_197 , F_197 ( V_2 ) ,
sizeof( struct V_340 ) ) ;
F_198 () ;
F_96 ( V_2 ) -> V_91 = F_57 ( V_105 -> V_91 ) ;
F_96 ( V_2 ) -> V_341 = ( F_96 ( V_2 ) -> V_91 + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_157 - V_105 -> V_161 * 4 ) ;
F_96 ( V_2 ) -> V_177 = F_57 ( V_105 -> V_177 ) ;
F_96 ( V_2 ) -> V_342 = F_199 ( V_105 ) ;
F_96 ( V_2 ) -> V_343 = 0 ;
F_96 ( V_2 ) -> V_344 = F_200 ( V_102 ) ;
F_96 ( V_2 ) -> V_345 = 0 ;
V_346:
V_8 = F_201 ( & V_114 , V_2 , V_105 -> V_6 , V_105 -> V_5 ) ;
if ( ! V_8 )
goto V_347;
V_348:
if ( V_8 -> V_116 == V_117 )
goto V_349;
if ( V_8 -> V_116 == V_118 ) {
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_7 * V_312 ;
V_8 = V_93 -> V_97 ;
if ( F_59 ( F_145 ( V_8 , V_2 ) ) ) {
F_47 ( V_93 ) ;
goto V_335;
}
if ( F_59 ( V_8 -> V_116 != V_131 ) ) {
F_202 ( V_8 , V_93 ) ;
goto V_346;
}
F_9 ( V_8 ) ;
V_312 = F_203 ( V_8 , V_2 , V_93 , false ) ;
if ( ! V_312 ) {
F_47 ( V_93 ) ;
goto V_350;
}
if ( V_312 == V_8 ) {
F_47 ( V_93 ) ;
} else if ( F_174 ( V_8 , V_312 , V_2 ) ) {
F_79 ( V_312 , V_2 ) ;
goto V_350;
} else {
F_72 ( V_8 ) ;
return 0 ;
}
}
if ( F_59 ( V_102 -> V_127 < F_11 ( V_8 ) -> V_128 ) ) {
F_45 ( V_94 , V_129 ) ;
goto V_350;
}
if ( ! F_204 ( V_8 , V_351 , V_2 ) )
goto V_350;
if ( F_145 ( V_8 , V_2 ) )
goto V_350;
F_205 ( V_2 ) ;
if ( F_206 ( V_8 , V_2 ) )
goto V_350;
V_2 -> V_113 = NULL ;
if ( V_8 -> V_116 == V_131 ) {
V_334 = F_169 ( V_8 , V_2 ) ;
goto V_352;
}
F_207 ( V_8 ) ;
F_208 ( V_8 ) ;
F_7 ( V_8 ) -> V_353 += F_209 ( V_354 , 1 , F_210 ( V_2 ) -> V_355 ) ;
V_334 = 0 ;
if ( ! F_13 ( V_8 ) ) {
if ( ! F_183 ( V_8 , V_2 ) )
V_334 = F_169 ( V_8 , V_2 ) ;
} else if ( F_59 ( F_211 ( V_8 , V_2 ,
V_8 -> V_327 + V_8 -> V_356 ) ) ) {
F_71 ( V_8 ) ;
F_45 ( V_94 , V_357 ) ;
goto V_350;
}
F_71 ( V_8 ) ;
V_352:
F_72 ( V_8 ) ;
return V_334 ;
V_347:
if ( ! F_204 ( NULL , V_351 , V_2 ) )
goto V_335;
if ( F_173 ( V_2 ) ) {
V_339:
F_97 ( V_94 , V_315 ) ;
V_337:
F_97 ( V_94 , V_316 ) ;
} else {
F_79 ( NULL , V_2 ) ;
}
V_335:
F_176 ( V_2 ) ;
return 0 ;
V_350:
F_72 ( V_8 ) ;
goto V_335;
V_349:
if ( ! F_204 ( NULL , V_351 , V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_335;
}
if ( F_173 ( V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_339;
}
switch ( F_212 ( F_56 ( V_8 ) , V_2 , V_105 ) ) {
case V_358 : {
struct V_7 * V_359 = F_213 ( F_50 ( V_2 -> V_113 ) ,
& V_114 ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , V_105 -> V_5 ,
F_53 ( V_2 ) ) ;
if ( V_359 ) {
F_214 ( F_56 ( V_8 ) ) ;
V_8 = V_359 ;
goto V_348;
}
}
case V_360 :
F_101 ( V_8 , V_2 ) ;
break;
case V_361 :
F_79 ( V_8 , V_2 ) ;
F_214 ( F_56 ( V_8 ) ) ;
goto V_335;
case V_362 : ;
}
goto V_335;
}
void F_156 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_81 * V_67 = F_83 ( V_2 ) ;
if ( V_67 && F_215 ( V_67 ) ) {
V_8 -> V_308 = V_67 ;
F_11 ( V_8 ) -> V_309 = V_2 -> V_310 ;
}
}
static int F_216 ( struct V_7 * V_8 )
{
struct V_107 * V_108 = F_25 ( V_8 ) ;
F_217 ( V_8 ) ;
V_108 -> V_363 = & V_364 ;
#ifdef F_80
F_7 ( V_8 ) -> V_365 = & V_366 ;
#endif
return 0 ;
}
void F_218 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_219 ( V_8 ) ;
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( & V_14 -> V_367 ) ;
#ifdef F_80
if ( V_14 -> V_234 ) {
F_130 ( V_8 ) ;
F_129 ( V_14 -> V_234 , V_252 ) ;
V_14 -> V_234 = NULL ;
}
#endif
F_222 ( & V_14 -> V_322 . V_324 ) ;
if ( F_25 ( V_8 ) -> V_368 )
F_223 ( V_8 ) ;
F_65 ( V_14 -> V_130 ) ;
F_224 ( V_14 ) ;
F_225 ( V_14 ) ;
F_226 ( V_8 ) ;
if ( V_369 && V_8 -> V_370 )
F_227 ( V_8 ) ;
}
static void * F_228 ( struct V_371 * V_91 , void * V_372 )
{
struct V_107 * V_108 ;
struct V_373 * V_249 ;
struct V_7 * V_8 = V_372 ;
struct V_374 * V_375 ;
struct V_376 * V_377 = V_91 -> V_378 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
if ( ! V_8 ) {
V_375 = & V_114 . V_379 [ V_377 -> V_380 ] ;
F_230 ( & V_375 -> V_381 ) ;
V_8 = F_231 ( & V_375 -> V_159 ) ;
V_377 -> V_209 = 0 ;
goto V_382;
}
V_375 = & V_114 . V_379 [ V_377 -> V_380 ] ;
++ V_377 -> V_383 ;
++ V_377 -> V_209 ;
V_8 = F_232 ( V_8 ) ;
V_382:
F_233 (sk, node) {
if ( ! F_234 ( F_19 ( V_8 ) , V_94 ) )
continue;
if ( V_8 -> V_384 == V_377 -> V_229 ) {
V_372 = V_8 ;
goto V_126;
}
V_108 = F_25 ( V_8 ) ;
}
F_235 ( & V_375 -> V_381 ) ;
V_377 -> V_209 = 0 ;
if ( ++ V_377 -> V_380 < V_385 ) {
V_375 = & V_114 . V_379 [ V_377 -> V_380 ] ;
F_230 ( & V_375 -> V_381 ) ;
V_8 = F_231 ( & V_375 -> V_159 ) ;
goto V_382;
}
V_372 = NULL ;
V_126:
return V_372 ;
}
static void * F_236 ( struct V_371 * V_91 , T_9 * V_386 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
void * V_387 ;
V_377 -> V_380 = 0 ;
V_377 -> V_209 = 0 ;
V_387 = F_228 ( V_91 , NULL ) ;
while ( V_387 && * V_386 ) {
V_387 = F_228 ( V_91 , V_387 ) ;
-- * V_386 ;
}
return V_387 ;
}
static inline bool F_237 ( const struct V_376 * V_377 )
{
return F_238 ( & V_114 . V_388 [ V_377 -> V_380 ] . V_389 ) ;
}
static void * F_239 ( struct V_371 * V_91 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
void * V_387 = NULL ;
V_377 -> V_209 = 0 ;
for (; V_377 -> V_380 <= V_114 . V_390 ; ++ V_377 -> V_380 ) {
struct V_7 * V_8 ;
struct V_373 * V_249 ;
V_235 * V_381 = F_240 ( & V_114 , V_377 -> V_380 ) ;
if ( F_237 ( V_377 ) )
continue;
F_230 ( V_381 ) ;
F_241 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_384 != V_377 -> V_229 ||
! F_234 ( F_19 ( V_8 ) , V_94 ) ) {
continue;
}
V_387 = V_8 ;
goto V_126;
}
F_235 ( V_381 ) ;
}
V_126:
return V_387 ;
}
static void * F_242 ( struct V_371 * V_91 , void * V_372 )
{
struct V_7 * V_8 = V_372 ;
struct V_373 * V_249 ;
struct V_376 * V_377 = V_91 -> V_378 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
++ V_377 -> V_383 ;
++ V_377 -> V_209 ;
V_8 = F_232 ( V_8 ) ;
F_233 (sk, node) {
if ( V_8 -> V_384 == V_377 -> V_229 && F_234 ( F_19 ( V_8 ) , V_94 ) )
return V_8 ;
}
F_235 ( F_240 ( & V_114 , V_377 -> V_380 ) ) ;
++ V_377 -> V_380 ;
return F_239 ( V_91 ) ;
}
static void * F_243 ( struct V_371 * V_91 , T_9 V_386 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
void * V_387 ;
V_377 -> V_380 = 0 ;
V_387 = F_239 ( V_91 ) ;
while ( V_387 && V_386 ) {
V_387 = F_242 ( V_91 , V_387 ) ;
-- V_386 ;
}
return V_387 ;
}
static void * F_244 ( struct V_371 * V_91 , T_9 V_386 )
{
void * V_387 ;
struct V_376 * V_377 = V_91 -> V_378 ;
V_377 -> V_391 = V_392 ;
V_387 = F_236 ( V_91 , & V_386 ) ;
if ( ! V_387 ) {
V_377 -> V_391 = V_393 ;
V_387 = F_243 ( V_91 , V_386 ) ;
}
return V_387 ;
}
static void * F_245 ( struct V_371 * V_91 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
int V_209 = V_377 -> V_209 ;
int V_394 = V_377 -> V_383 ;
void * V_387 = NULL ;
switch ( V_377 -> V_391 ) {
case V_392 :
if ( V_377 -> V_380 >= V_385 )
break;
V_377 -> V_391 = V_392 ;
V_387 = F_228 ( V_91 , NULL ) ;
while ( V_209 -- && V_387 )
V_387 = F_228 ( V_91 , V_387 ) ;
if ( V_387 )
break;
V_377 -> V_380 = 0 ;
V_377 -> V_391 = V_393 ;
case V_393 :
if ( V_377 -> V_380 > V_114 . V_390 )
break;
V_387 = F_239 ( V_91 ) ;
while ( V_209 -- && V_387 )
V_387 = F_242 ( V_91 , V_387 ) ;
}
V_377 -> V_383 = V_394 ;
return V_387 ;
}
static void * F_246 ( struct V_371 * V_91 , T_9 * V_386 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
void * V_387 ;
if ( * V_386 && * V_386 == V_377 -> V_395 ) {
V_387 = F_245 ( V_91 ) ;
if ( V_387 )
goto V_126;
}
V_377 -> V_391 = V_392 ;
V_377 -> V_383 = 0 ;
V_377 -> V_380 = 0 ;
V_377 -> V_209 = 0 ;
V_387 = * V_386 ? F_244 ( V_91 , * V_386 - 1 ) : V_396 ;
V_126:
V_377 -> V_395 = * V_386 ;
return V_387 ;
}
static void * F_247 ( struct V_371 * V_91 , void * V_397 , T_9 * V_386 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
void * V_387 = NULL ;
if ( V_397 == V_396 ) {
V_387 = F_244 ( V_91 , 0 ) ;
goto V_126;
}
switch ( V_377 -> V_391 ) {
case V_392 :
V_387 = F_228 ( V_91 , V_397 ) ;
if ( ! V_387 ) {
V_377 -> V_391 = V_393 ;
V_377 -> V_380 = 0 ;
V_377 -> V_209 = 0 ;
V_387 = F_239 ( V_91 ) ;
}
break;
case V_393 :
V_387 = F_242 ( V_91 , V_397 ) ;
break;
}
V_126:
++ * V_386 ;
V_377 -> V_395 = * V_386 ;
return V_387 ;
}
static void F_248 ( struct V_371 * V_91 , void * V_397 )
{
struct V_376 * V_377 = V_91 -> V_378 ;
switch ( V_377 -> V_391 ) {
case V_392 :
if ( V_397 != V_396 )
F_235 ( & V_114 . V_379 [ V_377 -> V_380 ] . V_381 ) ;
break;
case V_393 :
if ( V_397 )
F_235 ( F_240 ( & V_114 , V_377 -> V_380 ) ) ;
break;
}
}
int F_249 ( struct V_398 * V_398 , struct V_399 * V_399 )
{
struct V_400 * V_401 = F_250 ( V_398 ) ;
struct V_376 * V_402 ;
int V_37 ;
V_37 = F_251 ( V_398 , V_399 , & V_401 -> V_403 ,
sizeof( struct V_376 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_402 = ( (struct V_371 * ) V_399 -> V_404 ) -> V_378 ;
V_402 -> V_229 = V_401 -> V_229 ;
V_402 -> V_395 = 0 ;
return 0 ;
}
int F_252 ( struct V_94 * V_94 , struct V_400 * V_401 )
{
int V_387 = 0 ;
struct V_405 * V_406 ;
V_401 -> V_403 . V_407 = F_246 ;
V_401 -> V_403 . V_408 = F_247 ;
V_401 -> V_403 . V_409 = F_248 ;
V_406 = F_253 ( V_401 -> V_410 , V_411 , V_94 -> V_412 ,
V_401 -> V_413 , V_401 ) ;
if ( ! V_406 )
V_387 = - V_247 ;
return V_387 ;
}
void F_254 ( struct V_94 * V_94 , struct V_400 * V_401 )
{
F_255 ( V_401 -> V_410 , V_94 -> V_412 ) ;
}
static void F_256 ( const struct V_92 * V_93 ,
struct V_371 * V_414 , int V_415 )
{
const struct V_224 * V_225 = F_104 ( V_93 ) ;
long V_416 = V_93 -> V_417 . V_418 - V_78 ;
F_257 ( V_414 , L_4
L_5 ,
V_415 ,
V_225 -> V_226 ,
V_225 -> V_419 ,
V_225 -> V_227 ,
F_52 ( V_225 -> V_420 ) ,
V_150 ,
0 , 0 ,
1 ,
F_258 ( V_416 ) ,
V_93 -> V_421 ,
F_259 ( F_260 ( V_414 ) ,
F_261 ( V_93 -> V_97 ) ) ,
0 ,
0 ,
0 ,
V_93 ) ;
}
static void F_262 ( struct V_7 * V_8 , struct V_371 * V_414 , int V_415 )
{
int V_422 ;
unsigned long V_423 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_107 * V_108 = F_25 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
const struct V_424 * V_425 = & V_108 -> V_426 . V_425 ;
T_3 V_5 = V_29 -> V_63 ;
T_3 V_427 = V_29 -> V_428 ;
T_10 V_429 = F_52 ( V_29 -> V_68 ) ;
T_10 V_430 = F_52 ( V_29 -> V_49 ) ;
int V_431 ;
int V_391 ;
if ( V_108 -> V_432 == V_148 ||
V_108 -> V_432 == V_433 ||
V_108 -> V_432 == V_434 ) {
V_422 = 1 ;
V_423 = V_108 -> V_435 ;
} else if ( V_108 -> V_432 == V_436 ) {
V_422 = 4 ;
V_423 = V_108 -> V_435 ;
} else if ( F_263 ( & V_8 -> V_437 ) ) {
V_422 = 2 ;
V_423 = V_8 -> V_437 . V_418 ;
} else {
V_422 = 0 ;
V_423 = V_78 ;
}
V_391 = F_264 ( V_8 ) ;
if ( V_391 == V_131 )
V_431 = V_8 -> V_438 ;
else
V_431 = F_209 ( int , V_14 -> V_217 - V_14 -> V_439 , 0 ) ;
F_257 ( V_414 , L_6
L_7 ,
V_415 , V_427 , V_430 , V_5 , V_429 , V_391 ,
V_14 -> V_17 - V_14 -> V_111 ,
V_431 ,
V_422 ,
F_258 ( V_423 - V_78 ) ,
V_108 -> V_141 ,
F_259 ( F_260 ( V_414 ) , F_261 ( V_8 ) ) ,
V_108 -> V_440 ,
F_265 ( V_8 ) ,
F_266 ( & V_8 -> V_441 ) , V_8 ,
F_267 ( V_108 -> V_143 ) ,
F_267 ( V_108 -> V_442 . V_443 ) ,
( V_108 -> V_442 . V_444 << 1 ) | V_108 -> V_442 . V_445 ,
V_14 -> V_446 ,
V_391 == V_131 ?
V_425 -> V_447 :
( F_268 ( V_14 ) ? - 1 : V_14 -> V_448 ) ) ;
}
static void F_269 ( const struct V_192 * V_210 ,
struct V_371 * V_414 , int V_415 )
{
long V_416 = V_210 -> V_449 . V_418 - V_78 ;
T_3 V_5 , V_427 ;
T_10 V_429 , V_430 ;
V_5 = V_210 -> V_450 ;
V_427 = V_210 -> V_451 ;
V_429 = F_52 ( V_210 -> V_452 ) ;
V_430 = F_52 ( V_210 -> V_453 ) ;
F_257 ( V_414 , L_4
L_8 ,
V_415 , V_427 , V_430 , V_5 , V_429 , V_210 -> V_454 , 0 , 0 ,
3 , F_258 ( V_416 ) , 0 , 0 , 0 , 0 ,
F_266 ( & V_210 -> V_455 ) , V_210 ) ;
}
static int F_270 ( struct V_371 * V_91 , void * V_397 )
{
struct V_376 * V_377 ;
struct V_7 * V_8 = V_397 ;
F_271 ( V_91 , V_456 - 1 ) ;
if ( V_397 == V_396 ) {
F_272 ( V_91 , L_9
L_10
L_11 ) ;
goto V_126;
}
V_377 = V_91 -> V_378 ;
if ( V_8 -> V_116 == V_117 )
F_269 ( V_397 , V_91 , V_377 -> V_383 ) ;
else if ( V_8 -> V_116 == V_118 )
F_256 ( V_397 , V_91 , V_377 -> V_383 ) ;
else
F_262 ( V_397 , V_91 , V_377 -> V_383 ) ;
V_126:
F_273 ( V_91 , '\n' ) ;
return 0 ;
}
static int T_11 F_274 ( struct V_94 * V_94 )
{
return F_252 ( V_94 , & V_457 ) ;
}
static void T_12 F_275 ( struct V_94 * V_94 )
{
F_254 ( V_94 , & V_457 ) ;
}
int T_13 F_276 ( void )
{
return F_277 ( & V_458 ) ;
}
void F_278 ( void )
{
F_279 ( & V_458 ) ;
}
static void T_12 F_280 ( struct V_94 * V_94 )
{
int V_459 ;
F_281 (cpu)
F_282 ( * F_283 ( V_94 -> V_195 . F_7 , V_459 ) ) ;
F_284 ( V_94 -> V_195 . F_7 ) ;
}
static int T_11 F_285 ( struct V_94 * V_94 )
{
int V_460 , V_459 ;
V_94 -> V_195 . F_7 = F_286 ( struct V_7 * ) ;
if ( ! V_94 -> V_195 . F_7 )
return - V_247 ;
F_281 (cpu) {
struct V_7 * V_8 ;
V_460 = F_287 ( & V_8 , V_461 , V_462 ,
V_57 , V_94 ) ;
if ( V_460 )
goto V_463;
* F_283 ( V_94 -> V_195 . F_7 , V_459 ) = V_8 ;
}
V_94 -> V_195 . V_464 = 2 ;
V_94 -> V_195 . V_465 = 1 ;
V_94 -> V_195 . V_466 = V_467 ;
V_94 -> V_195 . V_468 = V_469 ;
V_94 -> V_195 . V_470 = V_471 ;
V_94 -> V_195 . V_472 = V_473 ;
V_94 -> V_195 . V_474 = V_475 ;
V_94 -> V_195 . V_476 = V_477 ;
return 0 ;
V_463:
F_280 ( V_94 ) ;
return V_460 ;
}
static void T_12 F_288 ( struct V_478 * V_479 )
{
F_289 ( & V_114 , & V_65 , V_42 ) ;
}
void T_13 F_290 ( void )
{
F_291 ( & V_114 ) ;
if ( F_277 ( & V_480 ) )
F_292 ( L_12 ) ;
}
