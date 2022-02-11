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
if ( V_91 != F_43 ( V_93 ) -> V_95 ) {
F_44 ( V_94 , V_96 ) ;
} else if ( abort ) {
F_45 ( V_93 -> V_97 , V_93 ) ;
F_44 ( V_94 , V_98 ) ;
}
F_46 ( V_93 ) ;
}
void F_47 ( struct V_1 * V_99 , T_4 V_100 )
{
const struct V_101 * V_102 = ( const struct V_101 * ) V_99 -> V_103 ;
struct V_104 * V_105 = (struct V_104 * ) ( V_99 -> V_103 + ( V_102 -> V_106 << 2 ) ) ;
struct V_107 * V_108 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_48 ( V_99 ) -> type ;
const int V_109 = F_48 ( V_99 ) -> V_109 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_92 * V_110 ;
T_1 V_91 , V_111 ;
T_1 V_112 ;
int V_37 ;
struct V_94 * V_94 = F_49 ( V_99 -> V_113 ) ;
V_8 = F_50 ( V_94 , & V_114 , V_102 -> V_3 ,
V_105 -> V_5 , V_102 -> V_4 , F_51 ( V_105 -> V_6 ) ,
F_52 ( V_99 ) ) ;
if ( ! V_8 ) {
F_53 ( V_94 , V_115 ) ;
return;
}
if ( V_8 -> V_116 == V_117 ) {
F_54 ( F_55 ( V_8 ) ) ;
return;
}
V_91 = F_56 ( V_105 -> V_91 ) ;
if ( V_8 -> V_116 == V_118 )
return F_41 ( V_8 , V_91 ,
type == V_119 ||
type == V_120 ||
( type == V_121 &&
( V_109 == V_122 ||
V_109 == V_123 ) ) ) ;
F_57 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_121 && V_109 == V_124 ) )
F_44 ( V_94 , V_125 ) ;
}
if ( V_8 -> V_116 == V_79 )
goto V_126;
if ( F_58 ( V_102 -> V_127 < F_11 ( V_8 ) -> V_128 ) ) {
F_44 ( V_94 , V_129 ) ;
goto V_126;
}
V_108 = F_25 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_110 = V_14 -> V_130 ;
V_111 = V_110 ? F_43 ( V_110 ) -> V_95 : V_14 -> V_111 ;
if ( V_8 -> V_116 != V_131 &&
! F_59 ( V_91 , V_111 , V_14 -> V_132 ) ) {
F_44 ( V_94 , V_96 ) ;
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
if ( ! F_60 ( V_137 , & V_14 -> V_138 ) )
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
V_108 -> V_143 = V_14 -> V_144 ? F_61 ( V_14 ) :
V_145 ;
V_108 -> V_143 = F_62 ( V_108 , V_146 ) ;
V_2 = F_63 ( V_8 ) ;
F_64 ( ! V_2 ) ;
V_112 = V_108 -> V_143 -
F_65 ( V_108 -> V_143 ,
V_147 - F_66 ( V_2 ) ) ;
if ( V_112 ) {
F_67 ( V_8 , V_148 ,
V_112 , V_146 ) ;
} else {
F_68 ( V_8 ) ;
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
F_69 ( V_8 ) ;
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
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
void F_72 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_104 * V_105 = F_4 ( V_2 ) ;
if ( V_2 -> V_154 == V_155 ) {
V_105 -> V_156 = ~ F_73 ( V_2 -> V_157 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_74 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_75 ( struct V_104 , V_156 ) ;
} else {
V_105 -> V_156 = F_73 ( V_2 -> V_157 , V_4 , V_3 ,
F_76 ( V_105 ,
V_105 -> V_161 << 2 ,
V_2 -> V_162 ) ) ;
}
}
void F_77 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_72 ( V_2 , V_29 -> V_55 , V_29 -> V_63 ) ;
}
static void F_78 ( const struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
#ifdef F_79
T_3 V_46 [ ( V_163 >> 2 ) ] ;
#endif
} V_164 ;
struct V_165 V_166 ;
#ifdef F_79
struct V_167 * V_168 = NULL ;
const T_5 * V_169 = NULL ;
unsigned char V_170 [ 16 ] ;
int V_171 ;
struct V_7 * V_172 = NULL ;
#endif
struct V_94 * V_94 ;
if ( V_105 -> V_173 )
return;
if ( ! V_8 && F_80 ( V_2 ) -> V_174 != V_175 )
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
V_164 . V_105 . V_177 = F_81 ( F_56 ( V_105 -> V_91 ) + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_157 - ( V_105 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
V_94 = V_8 ? F_19 ( V_8 ) : F_49 ( F_82 ( V_2 ) -> V_113 ) ;
#ifdef F_79
V_169 = F_83 ( V_105 ) ;
if ( V_8 && F_84 ( V_8 ) ) {
V_168 = F_85 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
} else if ( V_169 ) {
V_172 = F_86 ( V_94 , & V_114 , NULL , 0 ,
F_3 ( V_2 ) -> V_4 ,
V_105 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_51 ( V_105 -> V_6 ) , F_52 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_87 () ;
V_168 = F_85 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_88 ( V_170 , V_168 , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_81 ( ( V_185 << 24 ) |
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
V_166 . V_188 = F_75 ( struct V_104 , V_156 ) / 2 ;
V_166 . V_189 = ( V_8 && F_91 ( V_8 ) ) ? V_190 : 0 ;
if ( V_8 )
V_166 . V_191 = V_8 -> V_56 ;
F_92 ( F_75 ( struct V_7 , V_56 ) !=
F_75 ( struct V_192 , V_193 ) ) ;
V_166 . V_194 = F_3 ( V_2 ) -> V_194 ;
F_93 ( * F_94 ( V_94 -> V_195 . F_7 ) ,
V_2 , & F_95 ( V_2 ) -> V_196 . V_197 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_96 ( V_94 , V_198 ) ;
F_96 ( V_94 , V_199 ) ;
#ifdef F_79
V_184:
if ( V_172 ) {
F_97 () ;
F_71 ( V_172 ) ;
}
#endif
}
static void F_98 ( struct V_94 * V_94 ,
struct V_1 * V_2 , T_4 V_91 , T_4 V_176 ,
T_4 V_200 , T_4 V_201 , T_4 V_202 , int V_203 ,
struct V_167 * V_168 ,
int V_204 , T_6 V_194 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
T_3 V_46 [ ( V_205 >> 2 )
#ifdef F_79
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
V_164 . V_46 [ 0 ] = F_81 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_206 << 8 ) |
V_207 ) ;
V_164 . V_46 [ 1 ] = F_81 ( V_201 ) ;
V_164 . V_46 [ 2 ] = F_81 ( V_202 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_205 ;
}
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_105 . V_91 = F_81 ( V_91 ) ;
V_164 . V_105 . V_177 = F_81 ( V_176 ) ;
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_208 = F_99 ( V_200 ) ;
#ifdef F_79
if ( V_168 ) {
int V_209 = ( V_202 ) ? 3 : 0 ;
V_164 . V_46 [ V_209 ++ ] = F_81 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_89 ( ( T_5 * ) & V_164 . V_46 [ V_209 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_189 = V_204 ;
V_166 . V_162 = F_90 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_75 ( struct V_104 , V_156 ) / 2 ;
if ( V_203 )
V_166 . V_191 = V_203 ;
V_166 . V_194 = V_194 ;
F_93 ( * F_94 ( V_94 -> V_195 . F_7 ) ,
V_2 , & F_95 ( V_2 ) -> V_196 . V_197 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_96 ( V_94 , V_198 ) ;
}
static void F_100 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_192 * V_210 = F_55 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_98 ( F_19 ( V_8 ) , V_2 ,
V_12 -> V_18 , V_12 -> V_211 ,
V_12 -> V_212 >> V_210 -> V_213 ,
V_147 + V_12 -> V_214 ,
V_12 -> V_21 ,
V_210 -> V_193 ,
F_101 ( V_12 ) ,
V_210 -> V_215 ? V_190 : 0 ,
V_210 -> V_216
) ;
F_54 ( V_210 ) ;
}
static void F_102 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 )
{
T_4 V_91 = ( V_8 -> V_116 == V_131 ) ? F_43 ( V_93 ) -> V_95 + 1 :
F_7 ( V_8 ) -> V_132 ;
F_98 ( F_19 ( V_8 ) , V_2 , V_91 ,
F_43 ( V_93 ) -> V_217 , V_93 -> V_218 ,
V_147 ,
V_93 -> V_20 ,
0 ,
F_85 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_103 ( V_93 ) -> V_219 ? V_190 : 0 ,
F_3 ( V_2 ) -> V_194 ) ;
}
static int F_104 ( const struct V_7 * V_8 , struct V_81 * V_67 ,
struct V_220 * V_52 ,
struct V_92 * V_93 ,
struct V_221 * V_222 ,
bool V_223 )
{
const struct V_224 * V_225 = F_103 ( V_93 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_67 && ( V_67 = F_105 ( V_8 , & V_34 , V_93 ) ) == NULL )
return - 1 ;
V_2 = F_106 ( V_8 , V_67 , V_93 , V_222 , V_223 ) ;
if ( V_2 ) {
F_72 ( V_2 , V_225 -> V_226 , V_225 -> V_227 ) ;
V_37 = F_107 ( V_2 , V_8 , V_225 -> V_226 ,
V_225 -> V_227 ,
V_225 -> V_46 ) ;
V_37 = F_108 ( V_37 ) ;
}
return V_37 ;
}
static void F_109 ( struct V_92 * V_93 )
{
F_110 ( F_103 ( V_93 ) -> V_46 ) ;
}
struct V_167 * F_85 ( const struct V_7 * V_8 ,
const union V_183 * V_228 ,
int V_229 )
{
const struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
unsigned int V_230 = sizeof( struct V_231 ) ;
const struct V_232 * V_233 ;
V_233 = F_111 ( V_14 -> V_234 ,
F_13 ( V_8 ) ||
F_112 ( ( V_235 * ) & V_8 -> V_236 . V_237 ) ) ;
if ( ! V_233 )
return NULL ;
#if F_113 ( V_238 )
if ( V_229 == V_239 )
V_230 = sizeof( struct V_240 ) ;
#endif
F_114 (key, &md5sig->head, node) {
if ( V_168 -> V_229 != V_229 )
continue;
if ( ! memcmp ( & V_168 -> V_228 , V_228 , V_230 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_115 ( const struct V_7 * V_8 ,
const struct V_7 * V_241 )
{
const union V_183 * V_228 ;
V_228 = ( const union V_183 * ) & V_241 -> V_242 ;
return F_85 ( V_8 , V_228 , V_42 ) ;
}
int F_116 ( struct V_7 * V_8 , const union V_183 * V_228 ,
int V_229 , const T_6 * V_243 , T_6 V_244 , T_7 V_245 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_232 * V_233 ;
V_168 = F_85 ( V_8 , V_228 , V_229 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_243 , V_244 ) ;
V_168 -> V_246 = V_244 ;
return 0 ;
}
V_233 = F_12 ( V_14 -> V_234 ,
F_13 ( V_8 ) ||
F_112 ( & V_8 -> V_236 . V_237 ) ) ;
if ( ! V_233 ) {
V_233 = F_117 ( sizeof( * V_233 ) , V_245 ) ;
if ( ! V_233 )
return - V_247 ;
F_118 ( V_8 , V_248 ) ;
F_119 ( & V_233 -> V_159 ) ;
F_120 ( V_14 -> V_234 , V_233 ) ;
}
V_168 = F_121 ( V_8 , sizeof( * V_168 ) , V_245 ) ;
if ( ! V_168 )
return - V_247 ;
if ( ! F_122 () ) {
F_123 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_247 ;
}
memcpy ( V_168 -> V_168 , V_243 , V_244 ) ;
V_168 -> V_246 = V_244 ;
V_168 -> V_229 = V_229 ;
memcpy ( & V_168 -> V_228 , V_228 ,
( V_229 == V_239 ) ? sizeof( struct V_240 ) :
sizeof( struct V_231 ) ) ;
F_124 ( & V_168 -> V_249 , & V_233 -> V_159 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_8 , const union V_183 * V_228 , int V_229 )
{
struct V_167 * V_168 ;
V_168 = F_85 ( V_8 , V_228 , V_229 ) ;
if ( ! V_168 )
return - V_250 ;
F_126 ( & V_168 -> V_249 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_251 ) ;
F_128 ( V_168 , V_252 ) ;
return 0 ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_253 * V_254 ;
struct V_232 * V_233 ;
V_233 = F_12 ( V_14 -> V_234 , 1 ) ;
F_130 (key, n, &md5sig->head, node) {
F_126 ( & V_168 -> V_249 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_251 ) ;
F_128 ( V_168 , V_252 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , char T_8 * V_255 ,
int V_70 )
{
struct V_256 V_257 ;
struct V_26 * sin = (struct V_26 * ) & V_257 . V_258 ;
if ( V_70 < sizeof( V_257 ) )
return - V_40 ;
if ( F_132 ( & V_257 , V_255 , sizeof( V_257 ) ) )
return - V_259 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_257 . V_260 )
return F_125 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_257 . V_260 > V_261 )
return - V_40 ;
return F_116 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_257 . V_262 , V_257 . V_260 ,
V_263 ) ;
}
static int F_133 ( struct V_264 * V_265 ,
T_3 V_3 , T_3 V_4 , int V_266 )
{
struct V_267 * V_268 ;
struct V_269 V_270 ;
V_268 = & V_265 -> V_271 . V_54 ;
V_268 -> V_4 = V_4 ;
V_268 -> V_3 = V_3 ;
V_268 -> V_272 = 0 ;
V_268 -> V_273 = V_57 ;
V_268 -> V_157 = F_134 ( V_266 ) ;
F_135 ( & V_270 , V_268 , sizeof( * V_268 ) ) ;
F_136 ( V_265 -> V_274 , & V_270 , NULL , sizeof( * V_268 ) ) ;
return F_137 ( V_265 -> V_274 ) ;
}
static int F_89 ( char * V_275 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_104 * V_105 )
{
struct V_264 * V_265 ;
struct V_276 * V_93 ;
V_265 = F_138 () ;
if ( ! V_265 )
goto V_277;
V_93 = V_265 -> V_274 ;
if ( F_139 ( V_93 ) )
goto V_278;
if ( F_133 ( V_265 , V_3 , V_4 , V_105 -> V_161 << 2 ) )
goto V_278;
if ( F_140 ( V_265 , V_105 ) )
goto V_278;
if ( F_141 ( V_265 , V_168 ) )
goto V_278;
F_136 ( V_93 , NULL , V_275 , 0 ) ;
if ( F_142 ( V_93 ) )
goto V_278;
F_143 () ;
return 0 ;
V_278:
F_143 () ;
V_277:
memset ( V_275 , 0 , 16 ) ;
return 1 ;
}
int F_88 ( char * V_275 , const struct V_167 * V_168 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_264 * V_265 ;
struct V_276 * V_93 ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_279 ;
V_3 = V_8 -> V_242 ;
} else {
const struct V_101 * V_102 = F_3 ( V_2 ) ;
V_4 = V_102 -> V_4 ;
V_3 = V_102 -> V_3 ;
}
V_265 = F_138 () ;
if ( ! V_265 )
goto V_277;
V_93 = V_265 -> V_274 ;
if ( F_139 ( V_93 ) )
goto V_278;
if ( F_133 ( V_265 , V_3 , V_4 , V_2 -> V_157 ) )
goto V_278;
if ( F_140 ( V_265 , V_105 ) )
goto V_278;
if ( F_144 ( V_265 , V_2 , V_105 -> V_161 << 2 ) )
goto V_278;
if ( F_141 ( V_265 , V_168 ) )
goto V_278;
F_136 ( V_93 , NULL , V_275 , 0 ) ;
if ( F_142 ( V_93 ) )
goto V_278;
F_143 () ;
return 0 ;
V_278:
F_143 () ;
V_277:
memset ( V_275 , 0 , 16 ) ;
return 1 ;
}
static bool F_145 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_79
const T_5 * V_169 = NULL ;
struct V_167 * V_280 ;
const struct V_101 * V_102 = F_3 ( V_2 ) ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_280 = F_85 ( V_8 , (union V_183 * ) & V_102 -> V_4 ,
V_42 ) ;
V_169 = F_83 ( V_105 ) ;
if ( ! V_280 && ! V_169 )
return false ;
if ( V_280 && ! V_169 ) {
F_44 ( F_19 ( V_8 ) , V_281 ) ;
return true ;
}
if ( ! V_280 && V_169 ) {
F_44 ( F_19 ( V_8 ) , V_282 ) ;
return true ;
}
V_171 = F_88 ( V_170 ,
V_280 ,
NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_146 ( L_1 ,
& V_102 -> V_4 , F_51 ( V_105 -> V_6 ) ,
& V_102 -> V_3 , F_51 ( V_105 -> V_5 ) ,
V_171 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_147 ( struct V_92 * V_93 ,
const struct V_7 * V_283 ,
struct V_1 * V_2 )
{
struct V_224 * V_225 = F_103 ( V_93 ) ;
F_21 ( F_148 ( V_93 ) , F_3 ( V_2 ) -> V_3 ) ;
F_24 ( F_148 ( V_93 ) , F_3 ( V_2 ) -> V_4 ) ;
V_225 -> V_219 = F_11 ( V_283 ) -> V_284 ;
V_225 -> V_46 = F_149 ( V_2 ) ;
}
static struct V_81 * F_150 ( const struct V_7 * V_8 ,
struct V_220 * V_52 ,
const struct V_92 * V_93 ,
bool * V_285 )
{
struct V_81 * V_67 = F_105 ( V_8 , & V_52 -> V_53 . V_54 , V_93 ) ;
if ( V_285 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_103 ( V_93 ) -> V_227 )
* V_285 = true ;
else
* V_285 = false ;
}
return V_67 ;
}
int F_151 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_80 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_286;
return F_152 ( & V_287 ,
& V_288 , V_8 , V_2 ) ;
V_286:
F_44 ( F_19 ( V_8 ) , V_98 ) ;
return 0 ;
}
struct V_7 * F_153 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_81 * V_67 ,
struct V_92 * V_289 ,
bool * V_290 )
{
struct V_224 * V_225 ;
struct V_28 * V_291 ;
struct V_13 * V_292 ;
struct V_7 * V_293 ;
#ifdef F_79
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_154 ( V_8 ) )
goto V_294;
V_293 = F_155 ( V_8 , V_93 , V_2 ) ;
if ( ! V_293 )
goto V_295;
V_293 -> V_75 = V_76 ;
F_156 ( V_293 , V_2 ) ;
V_292 = F_7 ( V_293 ) ;
V_291 = F_11 ( V_293 ) ;
V_225 = F_103 ( V_93 ) ;
F_24 ( V_293 , V_225 -> V_227 ) ;
F_21 ( V_293 , V_225 -> V_226 ) ;
V_293 -> V_56 = V_225 -> V_296 ;
V_291 -> V_55 = V_225 -> V_226 ;
V_39 = V_225 -> V_46 ;
F_120 ( V_291 -> V_39 , V_39 ) ;
V_225 -> V_46 = NULL ;
V_291 -> V_297 = F_52 ( V_2 ) ;
V_291 -> V_298 = F_3 ( V_2 ) -> V_127 ;
V_291 -> V_299 = F_3 ( V_2 ) -> V_194 ;
F_25 ( V_293 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_293 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_291 -> V_77 = V_292 -> V_17 ^ V_78 ;
if ( ! V_67 ) {
V_67 = F_157 ( V_8 , V_293 , V_93 ) ;
if ( ! V_67 )
goto V_300;
} else {
}
F_30 ( V_293 , V_67 ) ;
F_158 ( V_293 , V_67 ) ;
F_37 ( V_293 , F_34 ( V_67 ) ) ;
V_292 -> V_301 = F_159 ( V_67 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_302 &&
F_7 ( V_8 ) -> V_19 . V_302 < V_292 -> V_301 )
V_292 -> V_301 = F_7 ( V_8 ) -> V_19 . V_302 ;
F_160 ( V_293 ) ;
#ifdef F_79
V_168 = F_85 ( V_8 , (union V_183 * ) & V_291 -> V_63 ,
V_42 ) ;
if ( V_168 ) {
F_116 ( V_293 , (union V_183 * ) & V_291 -> V_63 ,
V_42 , V_168 -> V_168 , V_168 -> V_246 , V_303 ) ;
F_118 ( V_293 , V_248 ) ;
}
#endif
if ( F_161 ( V_8 , V_293 ) < 0 )
goto V_300;
* V_290 = F_162 ( V_293 , F_148 ( V_289 ) ) ;
if ( * V_290 )
F_163 ( V_292 , V_93 ) ;
return V_293 ;
V_294:
F_44 ( F_19 ( V_8 ) , V_304 ) ;
V_295:
F_164 ( V_67 ) ;
exit:
F_44 ( F_19 ( V_8 ) , V_98 ) ;
return NULL ;
V_300:
F_165 ( V_293 ) ;
F_69 ( V_293 ) ;
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
struct V_7 * V_305 ;
if ( V_8 -> V_116 == V_306 ) {
struct V_81 * V_67 = V_8 -> V_307 ;
F_170 ( V_8 , V_2 ) ;
F_171 ( V_8 , V_2 ) ;
if ( V_67 ) {
if ( F_11 ( V_8 ) -> V_308 != V_2 -> V_309 ||
! V_67 -> V_89 -> V_156 ( V_67 , 0 ) ) {
F_164 ( V_67 ) ;
V_8 -> V_307 = NULL ;
}
}
F_172 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_157 ) ;
return 0 ;
}
if ( F_173 ( V_2 ) )
goto V_310;
if ( V_8 -> V_116 == V_131 ) {
struct V_7 * V_311 = F_166 ( V_8 , V_2 ) ;
if ( ! V_311 )
goto V_312;
if ( V_311 != V_8 ) {
F_170 ( V_311 , V_2 ) ;
F_171 ( V_311 , V_2 ) ;
if ( F_174 ( V_8 , V_311 , V_2 ) ) {
V_305 = V_311 ;
goto V_313;
}
return 0 ;
}
} else
F_170 ( V_8 , V_2 ) ;
if ( F_175 ( V_8 , V_2 ) ) {
V_305 = V_8 ;
goto V_313;
}
return 0 ;
V_313:
F_78 ( V_305 , V_2 ) ;
V_312:
F_176 ( V_2 ) ;
return 0 ;
V_310:
F_96 ( F_19 ( V_8 ) , V_314 ) ;
F_96 ( F_19 ( V_8 ) , V_315 ) ;
goto V_312;
}
void F_177 ( struct V_1 * V_2 )
{
const struct V_101 * V_102 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
if ( V_2 -> V_316 != V_317 )
return;
if ( ! F_178 ( V_2 , F_179 ( V_2 ) + sizeof( struct V_104 ) ) )
return;
V_102 = F_3 ( V_2 ) ;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
return;
V_8 = F_50 ( F_49 ( V_2 -> V_113 ) , & V_114 ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , F_51 ( V_105 -> V_5 ) ,
V_2 -> V_309 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_318 = V_319 ;
if ( F_84 ( V_8 ) ) {
struct V_81 * V_67 = F_180 ( V_8 -> V_307 ) ;
if ( V_67 )
V_67 = F_181 ( V_67 , 0 ) ;
if ( V_67 &&
F_11 ( V_8 ) -> V_308 == V_2 -> V_309 )
F_182 ( V_2 , V_67 ) ;
}
}
}
bool F_183 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_320 || ! V_14 -> V_321 . V_322 )
return false ;
if ( V_2 -> V_157 <= F_184 ( V_2 ) &&
F_185 ( & V_14 -> V_321 . V_323 ) == 0 )
return false ;
if ( F_22 ( V_8 -> V_307 ) )
F_186 ( V_2 ) ;
else
F_187 ( V_2 ) ;
F_188 ( & V_14 -> V_321 . V_323 , V_2 ) ;
V_14 -> V_321 . V_324 += V_2 -> V_325 ;
if ( V_14 -> V_321 . V_324 > V_8 -> V_326 ) {
struct V_1 * V_327 ;
F_64 ( F_13 ( V_8 ) ) ;
while ( ( V_327 = F_189 ( & V_14 -> V_321 . V_323 ) ) != NULL ) {
F_190 ( V_8 , V_327 ) ;
F_44 ( F_19 ( V_8 ) ,
V_328 ) ;
}
V_14 -> V_321 . V_324 = 0 ;
} else if ( F_185 ( & V_14 -> V_321 . V_323 ) == 1 ) {
F_191 ( F_192 ( V_8 ) ,
V_329 | V_330 | V_331 ) ;
if ( ! F_193 ( V_8 ) )
F_67 ( V_8 , V_332 ,
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
int V_333 ;
struct V_94 * V_94 = F_49 ( V_2 -> V_113 ) ;
if ( V_2 -> V_316 != V_317 )
goto V_334;
F_96 ( V_94 , V_335 ) ;
if ( ! F_178 ( V_2 , sizeof( struct V_104 ) ) )
goto V_334;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
goto V_336;
if ( ! F_178 ( V_2 , V_105 -> V_161 * 4 ) )
goto V_334;
if ( F_196 ( V_2 , V_57 , V_337 ) )
goto V_338;
V_105 = F_4 ( V_2 ) ;
V_102 = F_3 ( V_2 ) ;
memmove ( & F_95 ( V_2 ) -> V_196 . V_197 , F_197 ( V_2 ) ,
sizeof( struct V_339 ) ) ;
F_198 () ;
F_95 ( V_2 ) -> V_91 = F_56 ( V_105 -> V_91 ) ;
F_95 ( V_2 ) -> V_340 = ( F_95 ( V_2 ) -> V_91 + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_157 - V_105 -> V_161 * 4 ) ;
F_95 ( V_2 ) -> V_177 = F_56 ( V_105 -> V_177 ) ;
F_95 ( V_2 ) -> V_341 = F_199 ( V_105 ) ;
F_95 ( V_2 ) -> V_342 = 0 ;
F_95 ( V_2 ) -> V_343 = F_200 ( V_102 ) ;
F_95 ( V_2 ) -> V_344 = 0 ;
V_345:
V_8 = F_201 ( & V_114 , V_2 , F_202 ( V_105 ) , V_105 -> V_6 ,
V_105 -> V_5 ) ;
if ( ! V_8 )
goto V_346;
V_347:
if ( V_8 -> V_116 == V_117 )
goto V_348;
if ( V_8 -> V_116 == V_118 ) {
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_7 * V_311 ;
V_8 = V_93 -> V_97 ;
if ( F_58 ( F_145 ( V_8 , V_2 ) ) ) {
F_46 ( V_93 ) ;
goto V_334;
}
if ( F_58 ( V_8 -> V_116 != V_131 ) ) {
F_203 ( V_8 , V_93 ) ;
goto V_345;
}
F_9 ( V_8 ) ;
V_311 = F_204 ( V_8 , V_2 , V_93 , false ) ;
if ( ! V_311 ) {
F_46 ( V_93 ) ;
goto V_349;
}
if ( V_311 == V_8 ) {
F_46 ( V_93 ) ;
} else if ( F_174 ( V_8 , V_311 , V_2 ) ) {
F_78 ( V_311 , V_2 ) ;
goto V_349;
} else {
F_71 ( V_8 ) ;
return 0 ;
}
}
if ( F_58 ( V_102 -> V_127 < F_11 ( V_8 ) -> V_128 ) ) {
F_44 ( V_94 , V_129 ) ;
goto V_349;
}
if ( ! F_205 ( V_8 , V_350 , V_2 ) )
goto V_349;
if ( F_145 ( V_8 , V_2 ) )
goto V_349;
F_206 ( V_2 ) ;
if ( F_207 ( V_8 , V_2 ) )
goto V_349;
V_2 -> V_113 = NULL ;
if ( V_8 -> V_116 == V_131 ) {
V_333 = F_169 ( V_8 , V_2 ) ;
goto V_351;
}
F_208 ( V_8 ) ;
F_209 ( V_8 ) ;
F_210 ( F_7 ( V_8 ) , V_2 ) ;
V_333 = 0 ;
if ( ! F_13 ( V_8 ) ) {
if ( ! F_183 ( V_8 , V_2 ) )
V_333 = F_169 ( V_8 , V_2 ) ;
} else if ( F_58 ( F_211 ( V_8 , V_2 ,
V_8 -> V_326 + V_8 -> V_352 ) ) ) {
F_70 ( V_8 ) ;
F_44 ( V_94 , V_353 ) ;
goto V_349;
}
F_70 ( V_8 ) ;
V_351:
F_71 ( V_8 ) ;
return V_333 ;
V_346:
if ( ! F_205 ( NULL , V_350 , V_2 ) )
goto V_334;
if ( F_173 ( V_2 ) ) {
V_338:
F_96 ( V_94 , V_314 ) ;
V_336:
F_96 ( V_94 , V_315 ) ;
} else {
F_78 ( NULL , V_2 ) ;
}
V_334:
F_176 ( V_2 ) ;
return 0 ;
V_349:
F_71 ( V_8 ) ;
goto V_334;
V_348:
if ( ! F_205 ( NULL , V_350 , V_2 ) ) {
F_54 ( F_55 ( V_8 ) ) ;
goto V_334;
}
if ( F_173 ( V_2 ) ) {
F_54 ( F_55 ( V_8 ) ) ;
goto V_338;
}
switch ( F_212 ( F_55 ( V_8 ) , V_2 , V_105 ) ) {
case V_354 : {
struct V_7 * V_355 = F_213 ( F_49 ( V_2 -> V_113 ) ,
& V_114 , V_2 ,
F_202 ( V_105 ) ,
V_102 -> V_4 , V_105 -> V_6 ,
V_102 -> V_3 , V_105 -> V_5 ,
F_52 ( V_2 ) ) ;
if ( V_355 ) {
F_214 ( F_55 ( V_8 ) ) ;
V_8 = V_355 ;
goto V_347;
}
}
case V_356 :
F_100 ( V_8 , V_2 ) ;
break;
case V_357 :
F_78 ( V_8 , V_2 ) ;
F_214 ( F_55 ( V_8 ) ) ;
goto V_334;
case V_358 : ;
}
goto V_334;
}
void F_156 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_81 * V_67 = F_82 ( V_2 ) ;
if ( V_67 && F_215 ( V_67 ) ) {
V_8 -> V_307 = V_67 ;
F_11 ( V_8 ) -> V_308 = V_2 -> V_309 ;
}
}
static int F_216 ( struct V_7 * V_8 )
{
struct V_107 * V_108 = F_25 ( V_8 ) ;
F_217 ( V_8 ) ;
V_108 -> V_359 = & V_360 ;
#ifdef F_79
F_7 ( V_8 ) -> V_361 = & V_362 ;
#endif
return 0 ;
}
void F_218 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_219 ( V_8 ) ;
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( & V_14 -> V_363 ) ;
#ifdef F_79
if ( V_14 -> V_234 ) {
F_129 ( V_8 ) ;
F_128 ( V_14 -> V_234 , V_252 ) ;
V_14 -> V_234 = NULL ;
}
#endif
F_222 ( & V_14 -> V_321 . V_323 ) ;
if ( F_25 ( V_8 ) -> V_364 )
F_223 ( V_8 ) ;
F_64 ( V_14 -> V_130 ) ;
F_224 ( V_14 ) ;
F_225 ( V_14 ) ;
F_226 ( V_8 ) ;
if ( V_365 && V_8 -> V_366 )
F_227 ( V_8 ) ;
}
static void * F_228 ( struct V_367 * V_91 , void * V_368 )
{
struct V_107 * V_108 ;
struct V_369 * V_249 ;
struct V_7 * V_8 = V_368 ;
struct V_370 * V_371 ;
struct V_372 * V_373 = V_91 -> V_374 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
if ( ! V_8 ) {
V_371 = & V_114 . V_375 [ V_373 -> V_376 ] ;
F_230 ( & V_371 -> V_377 ) ;
V_8 = F_231 ( & V_371 -> V_159 ) ;
V_373 -> V_209 = 0 ;
goto V_378;
}
V_371 = & V_114 . V_375 [ V_373 -> V_376 ] ;
++ V_373 -> V_379 ;
++ V_373 -> V_209 ;
V_8 = F_232 ( V_8 ) ;
V_378:
F_233 (sk, node) {
if ( ! F_234 ( F_19 ( V_8 ) , V_94 ) )
continue;
if ( V_8 -> V_380 == V_373 -> V_229 ) {
V_368 = V_8 ;
goto V_126;
}
V_108 = F_25 ( V_8 ) ;
}
F_235 ( & V_371 -> V_377 ) ;
V_373 -> V_209 = 0 ;
if ( ++ V_373 -> V_376 < V_381 ) {
V_371 = & V_114 . V_375 [ V_373 -> V_376 ] ;
F_230 ( & V_371 -> V_377 ) ;
V_8 = F_231 ( & V_371 -> V_159 ) ;
goto V_378;
}
V_368 = NULL ;
V_126:
return V_368 ;
}
static void * F_236 ( struct V_367 * V_91 , T_9 * V_382 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
void * V_383 ;
V_373 -> V_376 = 0 ;
V_373 -> V_209 = 0 ;
V_383 = F_228 ( V_91 , NULL ) ;
while ( V_383 && * V_382 ) {
V_383 = F_228 ( V_91 , V_383 ) ;
-- * V_382 ;
}
return V_383 ;
}
static inline bool F_237 ( const struct V_372 * V_373 )
{
return F_238 ( & V_114 . V_384 [ V_373 -> V_376 ] . V_385 ) ;
}
static void * F_239 ( struct V_367 * V_91 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
void * V_383 = NULL ;
V_373 -> V_209 = 0 ;
for (; V_373 -> V_376 <= V_114 . V_386 ; ++ V_373 -> V_376 ) {
struct V_7 * V_8 ;
struct V_369 * V_249 ;
V_235 * V_377 = F_240 ( & V_114 , V_373 -> V_376 ) ;
if ( F_237 ( V_373 ) )
continue;
F_230 ( V_377 ) ;
F_241 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_380 != V_373 -> V_229 ||
! F_234 ( F_19 ( V_8 ) , V_94 ) ) {
continue;
}
V_383 = V_8 ;
goto V_126;
}
F_235 ( V_377 ) ;
}
V_126:
return V_383 ;
}
static void * F_242 ( struct V_367 * V_91 , void * V_368 )
{
struct V_7 * V_8 = V_368 ;
struct V_369 * V_249 ;
struct V_372 * V_373 = V_91 -> V_374 ;
struct V_94 * V_94 = F_229 ( V_91 ) ;
++ V_373 -> V_379 ;
++ V_373 -> V_209 ;
V_8 = F_232 ( V_8 ) ;
F_233 (sk, node) {
if ( V_8 -> V_380 == V_373 -> V_229 && F_234 ( F_19 ( V_8 ) , V_94 ) )
return V_8 ;
}
F_235 ( F_240 ( & V_114 , V_373 -> V_376 ) ) ;
++ V_373 -> V_376 ;
return F_239 ( V_91 ) ;
}
static void * F_243 ( struct V_367 * V_91 , T_9 V_382 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
void * V_383 ;
V_373 -> V_376 = 0 ;
V_383 = F_239 ( V_91 ) ;
while ( V_383 && V_382 ) {
V_383 = F_242 ( V_91 , V_383 ) ;
-- V_382 ;
}
return V_383 ;
}
static void * F_244 ( struct V_367 * V_91 , T_9 V_382 )
{
void * V_383 ;
struct V_372 * V_373 = V_91 -> V_374 ;
V_373 -> V_387 = V_388 ;
V_383 = F_236 ( V_91 , & V_382 ) ;
if ( ! V_383 ) {
V_373 -> V_387 = V_389 ;
V_383 = F_243 ( V_91 , V_382 ) ;
}
return V_383 ;
}
static void * F_245 ( struct V_367 * V_91 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
int V_209 = V_373 -> V_209 ;
int V_390 = V_373 -> V_379 ;
void * V_383 = NULL ;
switch ( V_373 -> V_387 ) {
case V_388 :
if ( V_373 -> V_376 >= V_381 )
break;
V_373 -> V_387 = V_388 ;
V_383 = F_228 ( V_91 , NULL ) ;
while ( V_209 -- && V_383 )
V_383 = F_228 ( V_91 , V_383 ) ;
if ( V_383 )
break;
V_373 -> V_376 = 0 ;
V_373 -> V_387 = V_389 ;
case V_389 :
if ( V_373 -> V_376 > V_114 . V_386 )
break;
V_383 = F_239 ( V_91 ) ;
while ( V_209 -- && V_383 )
V_383 = F_242 ( V_91 , V_383 ) ;
}
V_373 -> V_379 = V_390 ;
return V_383 ;
}
static void * F_246 ( struct V_367 * V_91 , T_9 * V_382 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
void * V_383 ;
if ( * V_382 && * V_382 == V_373 -> V_391 ) {
V_383 = F_245 ( V_91 ) ;
if ( V_383 )
goto V_126;
}
V_373 -> V_387 = V_388 ;
V_373 -> V_379 = 0 ;
V_373 -> V_376 = 0 ;
V_373 -> V_209 = 0 ;
V_383 = * V_382 ? F_244 ( V_91 , * V_382 - 1 ) : V_392 ;
V_126:
V_373 -> V_391 = * V_382 ;
return V_383 ;
}
static void * F_247 ( struct V_367 * V_91 , void * V_393 , T_9 * V_382 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
void * V_383 = NULL ;
if ( V_393 == V_392 ) {
V_383 = F_244 ( V_91 , 0 ) ;
goto V_126;
}
switch ( V_373 -> V_387 ) {
case V_388 :
V_383 = F_228 ( V_91 , V_393 ) ;
if ( ! V_383 ) {
V_373 -> V_387 = V_389 ;
V_373 -> V_376 = 0 ;
V_373 -> V_209 = 0 ;
V_383 = F_239 ( V_91 ) ;
}
break;
case V_389 :
V_383 = F_242 ( V_91 , V_393 ) ;
break;
}
V_126:
++ * V_382 ;
V_373 -> V_391 = * V_382 ;
return V_383 ;
}
static void F_248 ( struct V_367 * V_91 , void * V_393 )
{
struct V_372 * V_373 = V_91 -> V_374 ;
switch ( V_373 -> V_387 ) {
case V_388 :
if ( V_393 != V_392 )
F_235 ( & V_114 . V_375 [ V_373 -> V_376 ] . V_377 ) ;
break;
case V_389 :
if ( V_393 )
F_235 ( F_240 ( & V_114 , V_373 -> V_376 ) ) ;
break;
}
}
int F_249 ( struct V_394 * V_394 , struct V_395 * V_395 )
{
struct V_396 * V_397 = F_250 ( V_394 ) ;
struct V_372 * V_398 ;
int V_37 ;
V_37 = F_251 ( V_394 , V_395 , & V_397 -> V_399 ,
sizeof( struct V_372 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_398 = ( (struct V_367 * ) V_395 -> V_400 ) -> V_374 ;
V_398 -> V_229 = V_397 -> V_229 ;
V_398 -> V_391 = 0 ;
return 0 ;
}
int F_252 ( struct V_94 * V_94 , struct V_396 * V_397 )
{
int V_383 = 0 ;
struct V_401 * V_402 ;
V_397 -> V_399 . V_403 = F_246 ;
V_397 -> V_399 . V_404 = F_247 ;
V_397 -> V_399 . V_405 = F_248 ;
V_402 = F_253 ( V_397 -> V_406 , V_407 , V_94 -> V_408 ,
V_397 -> V_409 , V_397 ) ;
if ( ! V_402 )
V_383 = - V_247 ;
return V_383 ;
}
void F_254 ( struct V_94 * V_94 , struct V_396 * V_397 )
{
F_255 ( V_397 -> V_406 , V_94 -> V_408 ) ;
}
static void F_256 ( const struct V_92 * V_93 ,
struct V_367 * V_410 , int V_411 )
{
const struct V_224 * V_225 = F_103 ( V_93 ) ;
long V_412 = V_93 -> V_413 . V_414 - V_78 ;
F_257 ( V_410 , L_4
L_5 ,
V_411 ,
V_225 -> V_226 ,
V_225 -> V_415 ,
V_225 -> V_227 ,
F_51 ( V_225 -> V_416 ) ,
V_150 ,
0 , 0 ,
1 ,
F_258 ( V_412 ) ,
V_93 -> V_417 ,
F_259 ( F_260 ( V_410 ) ,
F_261 ( V_93 -> V_97 ) ) ,
0 ,
0 ,
0 ,
V_93 ) ;
}
static void F_262 ( struct V_7 * V_8 , struct V_367 * V_410 , int V_411 )
{
int V_418 ;
unsigned long V_419 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_107 * V_108 = F_25 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
const struct V_420 * V_421 = & V_108 -> V_422 . V_421 ;
T_3 V_5 = V_29 -> V_63 ;
T_3 V_423 = V_29 -> V_424 ;
T_10 V_425 = F_51 ( V_29 -> V_68 ) ;
T_10 V_426 = F_51 ( V_29 -> V_49 ) ;
int V_427 ;
int V_387 ;
if ( V_108 -> V_428 == V_148 ||
V_108 -> V_428 == V_429 ||
V_108 -> V_428 == V_430 ) {
V_418 = 1 ;
V_419 = V_108 -> V_431 ;
} else if ( V_108 -> V_428 == V_432 ) {
V_418 = 4 ;
V_419 = V_108 -> V_431 ;
} else if ( F_263 ( & V_8 -> V_433 ) ) {
V_418 = 2 ;
V_419 = V_8 -> V_433 . V_414 ;
} else {
V_418 = 0 ;
V_419 = V_78 ;
}
V_387 = F_264 ( V_8 ) ;
if ( V_387 == V_131 )
V_427 = V_8 -> V_434 ;
else
V_427 = F_265 ( int , V_14 -> V_217 - V_14 -> V_435 , 0 ) ;
F_257 ( V_410 , L_6
L_7 ,
V_411 , V_423 , V_426 , V_5 , V_425 , V_387 ,
V_14 -> V_17 - V_14 -> V_111 ,
V_427 ,
V_418 ,
F_258 ( V_419 - V_78 ) ,
V_108 -> V_141 ,
F_259 ( F_260 ( V_410 ) , F_261 ( V_8 ) ) ,
V_108 -> V_436 ,
F_266 ( V_8 ) ,
F_267 ( & V_8 -> V_437 ) , V_8 ,
F_268 ( V_108 -> V_143 ) ,
F_268 ( V_108 -> V_438 . V_439 ) ,
( V_108 -> V_438 . V_440 << 1 ) | V_108 -> V_438 . V_441 ,
V_14 -> V_442 ,
V_387 == V_131 ?
V_421 -> V_443 :
( F_269 ( V_14 ) ? - 1 : V_14 -> V_444 ) ) ;
}
static void F_270 ( const struct V_192 * V_210 ,
struct V_367 * V_410 , int V_411 )
{
long V_412 = V_210 -> V_445 . V_414 - V_78 ;
T_3 V_5 , V_423 ;
T_10 V_425 , V_426 ;
V_5 = V_210 -> V_446 ;
V_423 = V_210 -> V_447 ;
V_425 = F_51 ( V_210 -> V_448 ) ;
V_426 = F_51 ( V_210 -> V_449 ) ;
F_257 ( V_410 , L_4
L_8 ,
V_411 , V_423 , V_426 , V_5 , V_425 , V_210 -> V_450 , 0 , 0 ,
3 , F_258 ( V_412 ) , 0 , 0 , 0 , 0 ,
F_267 ( & V_210 -> V_451 ) , V_210 ) ;
}
static int F_271 ( struct V_367 * V_91 , void * V_393 )
{
struct V_372 * V_373 ;
struct V_7 * V_8 = V_393 ;
F_272 ( V_91 , V_452 - 1 ) ;
if ( V_393 == V_392 ) {
F_273 ( V_91 , L_9
L_10
L_11 ) ;
goto V_126;
}
V_373 = V_91 -> V_374 ;
if ( V_8 -> V_116 == V_117 )
F_270 ( V_393 , V_91 , V_373 -> V_379 ) ;
else if ( V_8 -> V_116 == V_118 )
F_256 ( V_393 , V_91 , V_373 -> V_379 ) ;
else
F_262 ( V_393 , V_91 , V_373 -> V_379 ) ;
V_126:
F_274 ( V_91 , '\n' ) ;
return 0 ;
}
static int T_11 F_275 ( struct V_94 * V_94 )
{
return F_252 ( V_94 , & V_453 ) ;
}
static void T_12 F_276 ( struct V_94 * V_94 )
{
F_254 ( V_94 , & V_453 ) ;
}
int T_13 F_277 ( void )
{
return F_278 ( & V_454 ) ;
}
void F_279 ( void )
{
F_280 ( & V_454 ) ;
}
static void T_12 F_281 ( struct V_94 * V_94 )
{
int V_455 ;
F_282 (cpu)
F_283 ( * F_284 ( V_94 -> V_195 . F_7 , V_455 ) ) ;
F_285 ( V_94 -> V_195 . F_7 ) ;
}
static int T_11 F_286 ( struct V_94 * V_94 )
{
int V_456 , V_455 ;
V_94 -> V_195 . F_7 = F_287 ( struct V_7 * ) ;
if ( ! V_94 -> V_195 . F_7 )
return - V_247 ;
F_282 (cpu) {
struct V_7 * V_8 ;
V_456 = F_288 ( & V_8 , V_457 , V_458 ,
V_57 , V_94 ) ;
if ( V_456 )
goto V_459;
* F_284 ( V_94 -> V_195 . F_7 , V_455 ) = V_8 ;
}
V_94 -> V_195 . V_460 = 2 ;
V_94 -> V_195 . V_461 = 1 ;
V_94 -> V_195 . V_462 = V_463 ;
V_94 -> V_195 . V_464 = V_465 ;
V_94 -> V_195 . V_466 = V_467 ;
V_94 -> V_195 . V_468 = V_469 ;
V_94 -> V_195 . V_470 = V_471 ;
V_94 -> V_195 . V_472 = V_473 ;
V_94 -> V_195 . V_474 = V_475 ;
V_94 -> V_195 . V_476 = V_477 ;
V_94 -> V_195 . V_478 = 1 ;
V_94 -> V_195 . V_479 = V_480 ;
V_94 -> V_195 . V_481 = V_482 ;
V_94 -> V_195 . V_483 = V_484 ;
V_94 -> V_195 . V_485 = 0 ;
V_94 -> V_195 . V_486 = V_487 ;
V_94 -> V_195 . V_488 = V_489 ;
return 0 ;
V_459:
F_281 ( V_94 ) ;
return V_456 ;
}
static void T_12 F_289 ( struct V_490 * V_491 )
{
F_290 ( & V_114 , & V_65 , V_42 ) ;
}
void T_13 F_291 ( void )
{
F_292 ( & V_114 ) ;
if ( F_278 ( & V_492 ) )
F_293 ( L_12 ) ;
}
