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
T_1 V_105 ;
T_1 V_106 ;
int V_37 ;
struct V_107 * V_107 = F_40 ( V_92 -> V_108 ) ;
if ( V_92 -> V_109 < ( V_95 -> V_99 << 2 ) + 8 ) {
F_41 ( V_107 , V_110 ) ;
return;
}
V_8 = F_42 ( V_107 , & V_111 , V_95 -> V_3 , V_98 -> V_5 ,
V_95 -> V_4 , V_98 -> V_6 , F_43 ( V_92 ) ) ;
if ( ! V_8 ) {
F_41 ( V_107 , V_110 ) ;
return;
}
if ( V_8 -> V_112 == V_113 ) {
F_44 ( F_45 ( V_8 ) ) ;
return;
}
F_46 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_114 && V_102 == V_115 ) )
F_47 ( V_107 , V_116 ) ;
}
if ( V_8 -> V_112 == V_80 )
goto V_117;
if ( F_48 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_47 ( V_107 , V_120 ) ;
goto V_117;
}
V_101 = F_23 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_104 = V_14 -> V_121 ;
V_105 = F_49 ( V_98 -> V_105 ) ;
if ( V_8 -> V_112 != V_122 &&
! F_50 ( V_105 , V_14 -> V_123 , V_14 -> V_124 ) &&
( V_104 == NULL || V_105 != F_51 ( V_104 ) -> V_125 ) ) {
F_47 ( V_107 , V_126 ) ;
goto V_117;
}
switch ( type ) {
case V_127 :
F_36 ( V_92 , V_8 ) ;
goto V_117;
case V_128 :
goto V_117;
case V_129 :
V_37 = V_130 ;
break;
case V_114 :
if ( V_102 > V_131 )
goto V_117;
if ( V_102 == V_115 ) {
if ( V_8 -> V_112 == V_122 )
goto V_117;
V_14 -> V_84 = V_93 ;
if ( ! F_13 ( V_8 ) ) {
F_29 ( V_8 ) ;
} else {
if ( ! F_52 ( V_132 , & V_14 -> V_133 ) )
F_9 ( V_8 ) ;
}
goto V_117;
}
V_37 = V_134 [ V_102 ] . V_135 ;
if ( V_102 != V_136 && V_102 != V_137 )
break;
if ( V_105 != V_14 -> V_123 || ! V_101 -> V_138 ||
! V_101 -> V_139 )
break;
if ( F_13 ( V_8 ) )
break;
V_101 -> V_139 -- ;
F_23 ( V_8 ) -> V_140 = ( V_14 -> V_141 ? F_53 ( V_14 ) :
V_142 ) << V_101 -> V_139 ;
F_54 ( V_8 ) ;
V_2 = F_55 ( V_8 ) ;
F_56 ( ! V_2 ) ;
V_106 = V_101 -> V_140 - F_57 ( V_101 -> V_140 ,
V_143 - F_58 ( V_2 ) -> V_144 ) ;
if ( V_106 ) {
F_59 ( V_8 , V_145 ,
V_106 , V_146 ) ;
} else {
F_60 ( V_8 ) ;
}
break;
case V_147 :
V_37 = V_148 ;
break;
default:
goto V_117;
}
if ( V_104 && V_104 -> V_8 == NULL )
goto V_117;
switch ( V_8 -> V_112 ) {
struct V_103 * V_104 , * * V_149 ;
case V_122 :
if ( F_13 ( V_8 ) )
goto V_117;
V_104 = F_61 ( V_8 , & V_149 , V_98 -> V_5 ,
V_95 -> V_3 , V_95 -> V_4 ) ;
if ( ! V_104 )
goto V_117;
F_62 ( V_104 -> V_8 ) ;
if ( V_105 != F_51 ( V_104 ) -> V_125 ) {
F_47 ( V_107 , V_126 ) ;
goto V_117;
}
F_63 ( V_8 , V_104 , V_149 ) ;
F_47 ( F_19 ( V_8 ) , V_150 ) ;
goto V_117;
case V_74 :
case V_151 :
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
F_64 ( V_8 ) ;
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
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
}
void F_67 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
if ( V_2 -> V_155 == V_156 ) {
V_98 -> V_157 = ~ F_68 ( V_2 -> V_109 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_69 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_70 ( struct V_97 , V_157 ) ;
} else {
V_98 -> V_157 = F_68 ( V_2 -> V_109 , V_4 , V_3 ,
F_71 ( V_98 ,
V_98 -> V_161 << 2 ,
V_2 -> V_162 ) ) ;
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
T_3 V_46 [ ( V_163 >> 2 ) ] ;
#endif
} V_164 ;
struct V_165 V_166 ;
#ifdef F_74
struct V_167 * V_168 ;
const T_5 * V_169 = NULL ;
unsigned char V_170 [ 16 ] ;
int V_171 ;
struct V_7 * V_172 = NULL ;
#endif
struct V_107 * V_107 ;
if ( V_98 -> V_173 )
return;
if ( F_75 ( V_2 ) -> V_174 != V_175 )
return;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_98 . V_5 = V_98 -> V_6 ;
V_164 . V_98 . V_6 = V_98 -> V_5 ;
V_164 . V_98 . V_161 = sizeof( struct V_97 ) / 4 ;
V_164 . V_98 . V_173 = 1 ;
if ( V_98 -> V_176 ) {
V_164 . V_98 . V_105 = V_98 -> V_177 ;
} else {
V_164 . V_98 . V_176 = 1 ;
V_164 . V_98 . V_177 = F_76 ( F_49 ( V_98 -> V_105 ) + V_98 -> V_178 + V_98 -> V_179 +
V_2 -> V_109 - ( V_98 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_98 ) ;
#ifdef F_74
V_169 = F_77 ( V_98 ) ;
if ( ! V_8 && V_169 ) {
V_172 = F_78 ( F_40 ( F_79 ( V_2 ) -> V_108 ) ,
& V_111 , F_3 ( V_2 ) -> V_4 ,
V_98 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_80 ( V_98 -> V_6 ) , F_43 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_81 () ;
V_168 = F_82 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_83 ( V_170 , V_168 , NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
} else {
V_168 = V_8 ? F_82 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_76 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_84 ( ( T_5 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_98 ) ;
}
#endif
V_166 . V_162 = F_85 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_70 ( struct V_97 , V_157 ) / 2 ;
V_166 . V_189 = ( V_8 && F_11 ( V_8 ) -> V_190 ) ? V_191 : 0 ;
if ( V_8 )
V_166 . V_192 = V_8 -> V_56 ;
V_107 = F_40 ( F_79 ( V_2 ) -> V_108 ) ;
V_166 . V_193 = F_3 ( V_2 ) -> V_193 ;
F_86 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_87 ( V_107 , V_194 ) ;
F_87 ( V_107 , V_195 ) ;
#ifdef F_74
V_184:
if ( V_172 ) {
F_88 () ;
F_66 ( V_172 ) ;
}
#endif
}
static void F_89 ( struct V_1 * V_2 , T_4 V_105 , T_4 V_176 ,
T_4 V_196 , T_4 V_197 , T_4 V_198 , int V_199 ,
struct V_167 * V_168 ,
int V_200 , T_6 V_193 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
T_3 V_46 [ ( V_201 >> 2 )
#ifdef F_74
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
struct V_107 * V_107 = F_40 ( F_79 ( V_2 ) -> V_108 ) ;
memset ( & V_164 . V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_98 ) ;
if ( V_198 ) {
V_164 . V_46 [ 0 ] = F_76 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_202 << 8 ) |
V_203 ) ;
V_164 . V_46 [ 1 ] = F_76 ( V_197 ) ;
V_164 . V_46 [ 2 ] = F_76 ( V_198 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_201 ;
}
V_164 . V_98 . V_5 = V_98 -> V_6 ;
V_164 . V_98 . V_6 = V_98 -> V_5 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_98 . V_105 = F_76 ( V_105 ) ;
V_164 . V_98 . V_177 = F_76 ( V_176 ) ;
V_164 . V_98 . V_176 = 1 ;
V_164 . V_98 . V_204 = F_90 ( V_196 ) ;
#ifdef F_74
if ( V_168 ) {
int V_205 = ( V_198 ) ? 3 : 0 ;
V_164 . V_46 [ V_205 ++ ] = F_76 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_84 ( ( T_5 * ) & V_164 . V_46 [ V_205 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_98 ) ;
}
#endif
V_166 . V_189 = V_200 ;
V_166 . V_162 = F_85 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_70 ( struct V_97 , V_157 ) / 2 ;
if ( V_199 )
V_166 . V_192 = V_199 ;
V_166 . V_193 = V_193 ;
F_86 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_87 ( V_107 , V_194 ) ;
}
static void F_91 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_206 * V_207 = F_45 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_89 ( V_2 , V_12 -> V_18 , V_12 -> V_208 ,
V_12 -> V_209 >> V_207 -> V_210 ,
V_143 + V_12 -> V_211 ,
V_12 -> V_21 ,
V_207 -> V_212 ,
F_92 ( V_12 ) ,
V_207 -> V_213 ? V_191 : 0 ,
V_207 -> V_214
) ;
F_44 ( V_207 ) ;
}
static void F_93 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 )
{
F_89 ( V_2 , ( V_8 -> V_112 == V_122 ) ?
F_51 ( V_104 ) -> V_125 + 1 : F_7 ( V_8 ) -> V_124 ,
F_51 ( V_104 ) -> V_215 , V_104 -> V_216 ,
V_143 ,
V_104 -> V_20 ,
0 ,
F_82 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_94 ( V_104 ) -> V_217 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_193 ) ;
}
static int F_95 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_103 * V_104 ,
T_7 V_218 )
{
const struct V_219 * V_220 = F_94 ( V_104 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_96 ( V_8 , & V_34 , V_104 ) ) == NULL )
return - 1 ;
V_2 = F_97 ( V_8 , V_68 , V_104 , NULL ) ;
if ( V_2 ) {
F_67 ( V_2 , V_220 -> V_221 , V_220 -> V_222 ) ;
F_98 ( V_2 , V_218 ) ;
V_37 = F_99 ( V_2 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 ,
V_220 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( ! F_51 ( V_104 ) -> V_223 && ! V_37 )
F_51 ( V_104 ) -> V_223 = V_143 ;
}
return V_37 ;
}
static int F_101 ( struct V_7 * V_8 , struct V_103 * V_104 )
{
int V_224 = F_95 ( V_8 , NULL , V_104 , 0 ) ;
if ( ! V_224 ) {
F_87 ( F_19 ( V_8 ) , V_225 ) ;
F_47 ( F_19 ( V_8 ) , V_226 ) ;
}
return V_224 ;
}
static void F_102 ( struct V_103 * V_104 )
{
F_103 ( F_94 ( V_104 ) -> V_46 ) ;
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
F_47 ( F_19 ( V_8 ) , V_233 ) ;
} else
#endif
F_47 ( F_19 ( V_8 ) , V_234 ) ;
V_231 = F_23 ( V_8 ) -> V_235 . V_236 ;
if ( ! V_231 -> V_237 && V_232 != 2 ) {
V_231 -> V_237 = 1 ;
F_106 ( L_3 ,
V_227 , F_80 ( F_4 ( V_2 ) -> V_5 ) , V_228 ) ;
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
struct V_167 * F_82 ( struct V_7 * V_8 ,
const union V_183 * V_242 ,
int V_243 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
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
if ( V_168 -> V_243 != V_243 )
continue;
if ( ! memcmp ( & V_168 -> V_242 , V_242 , V_244 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_115 ( struct V_7 * V_8 ,
struct V_7 * V_254 )
{
union V_183 * V_242 ;
V_242 = (union V_183 * ) & F_11 ( V_254 ) -> V_64 ;
return F_82 ( V_8 , V_242 , V_42 ) ;
}
static struct V_167 * F_116 ( struct V_7 * V_8 ,
struct V_103 * V_104 )
{
union V_183 * V_242 ;
V_242 = (union V_183 * ) & F_94 ( V_104 ) -> V_222 ;
return F_82 ( V_8 , V_242 , V_42 ) ;
}
int F_117 ( struct V_7 * V_8 , const union V_183 * V_242 ,
int V_243 , const T_6 * V_255 , T_6 V_256 , T_8 V_257 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_246 * V_247 ;
V_168 = F_82 ( V_8 , V_242 , V_243 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_255 , V_256 ) ;
V_168 -> V_258 = V_256 ;
return 0 ;
}
V_247 = F_12 ( V_14 -> V_248 ,
F_13 ( V_8 ) ) ;
if ( ! V_247 ) {
V_247 = F_109 ( sizeof( * V_247 ) , V_257 ) ;
if ( ! V_247 )
return - V_259 ;
F_118 ( V_8 , V_260 ) ;
F_119 ( & V_247 -> V_159 ) ;
F_120 ( V_14 -> V_248 , V_247 ) ;
}
V_168 = F_121 ( V_8 , sizeof( * V_168 ) , V_257 ) ;
if ( ! V_168 )
return - V_259 ;
if ( ! F_122 () ) {
F_123 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_259 ;
}
memcpy ( V_168 -> V_168 , V_255 , V_256 ) ;
V_168 -> V_258 = V_256 ;
V_168 -> V_243 = V_243 ;
memcpy ( & V_168 -> V_242 , V_242 ,
( V_243 == V_252 ) ? sizeof( struct V_253 ) :
sizeof( struct V_245 ) ) ;
F_124 ( & V_168 -> V_261 , & V_247 -> V_159 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_8 , const union V_183 * V_242 , int V_243 )
{
struct V_167 * V_168 ;
V_168 = F_82 ( V_8 , V_242 , V_243 ) ;
if ( ! V_168 )
return - V_262 ;
F_126 ( & V_168 -> V_261 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_263 ) ;
F_128 ( V_168 , V_264 ) ;
return 0 ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_265 * V_266 ;
struct V_246 * V_247 ;
V_247 = F_12 ( V_14 -> V_248 , 1 ) ;
F_130 (key, n, &md5sig->head, node) {
F_126 ( & V_168 -> V_261 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_263 ) ;
F_128 ( V_168 , V_264 ) ;
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
if ( ! V_269 . V_272 || ! V_269 . V_273 )
return F_125 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_269 . V_273 > V_274 )
return - V_40 ;
return F_117 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_269 . V_272 , V_269 . V_273 ,
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
V_280 -> V_109 = F_134 ( V_278 ) ;
F_135 ( & V_282 , V_280 , sizeof( * V_280 ) ) ;
return F_136 ( & V_277 -> V_286 , & V_282 , sizeof( * V_280 ) ) ;
}
static int F_84 ( char * V_287 , const struct V_167 * V_168 ,
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
if ( F_133 ( V_277 , V_3 , V_4 , V_98 -> V_161 << 2 ) )
goto V_291;
if ( F_139 ( V_277 , V_98 ) )
goto V_291;
if ( F_140 ( V_277 , V_168 ) )
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
int F_83 ( char * V_287 , struct V_167 * V_168 ,
const struct V_7 * V_8 , const struct V_103 * V_104 ,
const struct V_1 * V_2 )
{
struct V_276 * V_277 ;
struct V_288 * V_289 ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_104 ) {
V_4 = F_94 ( V_104 ) -> V_221 ;
V_3 = F_94 ( V_104 ) -> V_222 ;
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
if ( F_133 ( V_277 , V_3 , V_4 , V_2 -> V_109 ) )
goto V_291;
if ( F_139 ( V_277 , V_98 ) )
goto V_291;
if ( F_143 ( V_277 , V_2 , V_98 -> V_161 << 2 ) )
goto V_291;
if ( F_140 ( V_277 , V_168 ) )
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
static bool F_144 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_169 = NULL ;
struct V_167 * V_292 ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_292 = F_82 ( V_8 , (union V_183 * ) & V_95 -> V_4 ,
V_42 ) ;
V_169 = F_77 ( V_98 ) ;
if ( ! V_292 && ! V_169 )
return false ;
if ( V_292 && ! V_169 ) {
F_47 ( F_19 ( V_8 ) , V_293 ) ;
return true ;
}
if ( ! V_292 && V_169 ) {
F_47 ( F_19 ( V_8 ) , V_294 ) ;
return true ;
}
V_171 = F_83 ( V_170 ,
V_292 ,
NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_145 ( L_4 ,
& V_95 -> V_4 , F_80 ( V_98 -> V_6 ) ,
& V_95 -> V_3 , F_80 ( V_98 -> V_5 ) ,
V_171 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
static bool F_146 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_295 * V_296 ,
struct V_295 * V_297 )
{
bool V_298 = false ;
struct V_299 * V_300 ;
if ( F_21 ( ! F_147 ( V_296 ) ) ) {
if ( ( V_301 & V_302 ) ||
( ( V_301 & V_303 ) &&
( F_58 ( V_2 ) -> V_304 != F_58 ( V_2 ) -> V_105 + 1 ) ) )
V_298 = true ;
else
return false ;
}
V_300 = F_23 ( V_8 ) -> V_235 . V_300 ;
F_47 ( F_19 ( V_8 ) , V_305 ) ;
if ( ( V_301 & V_306 ) == 0 ||
V_300 == NULL || V_300 -> V_307 == 0 )
return false ;
if ( V_300 -> V_308 >= V_300 -> V_307 ) {
struct V_103 * V_309 ;
F_148 ( & V_300 -> V_310 ) ;
V_309 = V_300 -> V_311 ;
if ( ( V_309 == NULL ) || F_149 ( V_309 -> V_312 , V_79 ) ) {
F_150 ( & V_300 -> V_310 ) ;
F_47 ( F_19 ( V_8 ) ,
V_313 ) ;
V_296 -> V_109 = - 1 ;
return false ;
}
V_300 -> V_311 = V_309 -> V_314 ;
V_300 -> V_308 -- ;
F_150 ( & V_300 -> V_310 ) ;
F_151 ( V_309 ) ;
}
if ( V_298 ) {
F_51 ( V_104 ) -> V_215 = F_58 ( V_2 ) -> V_304 ;
return true ;
}
if ( V_296 -> V_109 == V_315 ) {
if ( ( V_301 & V_316 ) == 0 ) {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_297 ) ;
if ( ( V_297 -> V_109 != V_315 ) ||
memcmp ( & V_296 -> V_317 [ 0 ] , & V_297 -> V_317 [ 0 ] ,
V_315 ) != 0 )
return false ;
V_297 -> V_109 = - 1 ;
}
F_51 ( V_104 ) -> V_215 = F_58 ( V_2 ) -> V_304 ;
return true ;
} else if ( V_296 -> V_109 == 0 ) {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_297 ) ;
F_47 ( F_19 ( V_8 ) ,
V_318 ) ;
} else {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_297 ) ;
}
return false ;
}
static int F_153 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_1 * V_319 ,
struct V_103 * V_104 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_320 * V_321 = & F_23 ( V_8 ) -> V_235 ;
const struct V_219 * V_220 = F_94 ( V_104 ) ;
struct V_7 * V_322 ;
int V_37 ;
V_104 -> V_323 = 0 ;
V_104 -> V_324 = 0 ;
V_104 -> V_8 = NULL ;
V_322 = F_23 ( V_8 ) -> V_325 -> V_326 ( V_8 , V_2 , V_104 , NULL ) ;
if ( V_322 == NULL ) {
F_47 ( F_19 ( V_8 ) ,
V_327 ) ;
F_154 ( V_319 ) ;
return - 1 ;
}
V_37 = F_99 ( V_319 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( ! V_37 )
F_51 ( V_104 ) -> V_223 = V_143 ;
F_148 ( & V_321 -> V_300 -> V_310 ) ;
V_321 -> V_300 -> V_308 ++ ;
F_150 ( & V_321 -> V_300 -> V_310 ) ;
V_14 = F_7 ( V_322 ) ;
V_14 -> V_121 = V_104 ;
F_9 ( V_8 ) ;
F_51 ( V_104 ) -> V_328 = V_8 ;
V_14 -> V_329 = F_80 ( F_4 ( V_2 ) -> V_204 ) ;
F_59 ( V_322 , V_145 ,
V_142 , V_146 ) ;
F_155 ( V_8 , V_104 , V_322 ) ;
F_23 ( V_322 ) -> V_325 -> V_330 ( V_322 ) ;
F_156 ( V_322 ) ;
F_157 ( V_322 ) ;
F_158 ( V_322 ) ;
F_159 ( V_322 ) ;
if ( F_58 ( V_2 ) -> V_304 == F_58 ( V_2 ) -> V_105 + 1 ) {
V_14 -> V_215 = F_58 ( V_2 ) -> V_304 ;
} else {
V_2 = F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_162 ( V_2 , F_4 ( V_2 ) -> V_161 * 4 ) ;
F_163 ( V_2 , V_322 ) ;
F_164 ( & V_322 -> V_331 , V_2 ) ;
V_14 -> V_215 = F_58 ( V_2 ) -> V_304 ;
V_14 -> V_332 = 1 ;
}
V_8 -> V_333 ( V_8 ) ;
F_65 ( V_322 ) ;
F_66 ( V_322 ) ;
F_62 ( V_104 -> V_8 == NULL ) ;
return 0 ;
}
int F_165 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_334 V_335 ;
struct V_103 * V_104 ;
struct V_219 * V_220 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_336 = F_58 ( V_2 ) -> V_144 ;
bool V_229 = false ;
struct V_33 V_34 ;
struct V_295 V_296 = { . V_109 = - 1 } ;
struct V_295 V_297 = { . V_109 = - 1 } ;
struct V_1 * V_319 ;
int V_337 ;
if ( F_75 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_338;
if ( ( V_232 == 2 ||
F_166 ( V_8 ) ) && ! V_336 ) {
V_229 = F_104 ( V_8 , V_2 , L_7 ) ;
if ( ! V_229 )
goto V_338;
}
if ( F_167 ( V_8 ) && F_168 ( V_8 ) > 1 ) {
F_47 ( F_19 ( V_8 ) , V_339 ) ;
goto V_338;
}
V_104 = F_169 ( & V_340 ) ;
if ( ! V_104 )
goto V_338;
#ifdef F_74
F_51 ( V_104 ) -> V_341 = & V_342 ;
#endif
F_170 ( & V_335 ) ;
V_335 . V_72 = V_73 ;
V_335 . V_343 = V_14 -> V_19 . V_343 ;
F_171 ( V_2 , & V_335 , 0 , V_229 ? NULL : & V_296 ) ;
if ( V_229 && ! V_335 . V_344 )
F_170 ( & V_335 ) ;
V_335 . V_345 = V_335 . V_344 ;
F_172 ( V_104 , & V_335 , V_2 ) ;
V_220 = F_94 ( V_104 ) ;
V_220 -> V_221 = V_3 ;
V_220 -> V_222 = V_4 ;
V_220 -> V_217 = F_11 ( V_8 ) -> V_190 ;
V_220 -> V_46 = F_107 ( V_2 ) ;
if ( F_173 ( V_8 , V_2 , V_104 ) )
goto V_346;
if ( ! V_229 || V_335 . V_345 )
F_174 ( V_104 , V_2 , F_19 ( V_8 ) ) ;
if ( V_229 ) {
V_336 = F_175 ( V_8 , V_2 , & V_104 -> V_347 ) ;
V_104 -> V_348 = V_335 . V_345 ;
} else if ( ! V_336 ) {
if ( V_335 . V_344 &&
V_66 . V_67 &&
( V_68 = F_96 ( V_8 , & V_34 , V_104 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_176 ( V_104 , V_68 , true ) ) {
F_47 ( F_19 ( V_8 ) , V_349 ) ;
goto V_350;
}
}
else if ( ! V_232 &&
( V_351 - F_177 ( V_8 ) <
( V_351 >> 2 ) ) &&
! F_176 ( V_104 , V_68 , false ) ) {
F_178 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_350;
}
V_336 = F_1 ( V_2 ) ;
}
F_51 ( V_104 ) -> V_125 = V_336 ;
if ( V_68 == NULL ) {
V_68 = F_96 ( V_8 , & V_34 , V_104 ) ;
if ( V_68 == NULL )
goto V_346;
}
V_337 = F_146 ( V_8 , V_2 , V_104 , & V_296 , & V_297 ) ;
V_319 = F_97 ( V_8 , V_68 , V_104 ,
F_147 ( & V_297 ) ? & V_297 : NULL ) ;
if ( V_319 ) {
F_67 ( V_319 , V_220 -> V_221 , V_220 -> V_222 ) ;
F_98 ( V_319 , F_179 ( V_2 ) ) ;
} else
goto V_346;
if ( F_21 ( ! V_337 ) ) {
int V_37 ;
V_37 = F_99 ( V_319 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( V_37 || V_229 )
goto V_346;
F_51 ( V_104 ) -> V_223 = V_143 ;
F_51 ( V_104 ) -> V_328 = NULL ;
F_180 ( V_8 , V_104 , V_142 ) ;
if ( F_147 ( & V_296 ) && V_296 . V_109 != 0 )
F_47 ( F_19 ( V_8 ) ,
V_327 ) ;
} else if ( F_153 ( V_8 , V_2 , V_319 , V_104 ) )
goto V_346;
return 0 ;
V_350:
F_181 ( V_68 ) ;
V_346:
F_151 ( V_104 ) ;
V_338:
F_47 ( F_19 ( V_8 ) , V_150 ) ;
return 0 ;
}
struct V_7 * F_182 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_82 * V_68 )
{
struct V_219 * V_220 ;
struct V_28 * V_352 ;
struct V_13 * V_353 ;
struct V_7 * V_354 ;
#ifdef F_74
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_167 ( V_8 ) )
goto V_355;
V_354 = F_183 ( V_8 , V_104 , V_2 ) ;
if ( ! V_354 )
goto V_356;
V_354 -> V_76 = V_77 ;
F_184 ( V_354 , V_2 ) ;
V_353 = F_7 ( V_354 ) ;
V_352 = F_11 ( V_354 ) ;
V_220 = F_94 ( V_104 ) ;
V_352 -> V_64 = V_220 -> V_222 ;
V_352 -> V_63 = V_220 -> V_221 ;
V_352 -> V_55 = V_220 -> V_221 ;
V_39 = V_220 -> V_46 ;
F_120 ( V_352 -> V_39 , V_39 ) ;
V_220 -> V_46 = NULL ;
V_352 -> V_357 = F_43 ( V_2 ) ;
V_352 -> V_358 = F_3 ( V_2 ) -> V_118 ;
V_352 -> V_359 = F_3 ( V_2 ) -> V_193 ;
F_23 ( V_354 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_354 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_352 -> V_78 = V_353 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_185 ( V_8 , V_354 , V_104 ) ;
if ( ! V_68 )
goto V_360;
} else {
}
F_27 ( V_354 , V_68 ) ;
F_34 ( V_354 , F_31 ( V_68 ) ) ;
V_353 -> V_361 = F_186 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_343 &&
F_7 ( V_8 ) -> V_19 . V_343 < V_353 -> V_361 )
V_353 -> V_361 = F_7 ( V_8 ) -> V_19 . V_343 ;
F_187 ( V_354 ) ;
#ifdef F_74
V_168 = F_82 ( V_8 , (union V_183 * ) & V_352 -> V_64 ,
V_42 ) ;
if ( V_168 != NULL ) {
F_117 ( V_354 , (union V_183 * ) & V_352 -> V_64 ,
V_42 , V_168 -> V_168 , V_168 -> V_258 , V_241 ) ;
F_118 ( V_354 , V_260 ) ;
}
#endif
if ( F_188 ( V_8 , V_354 ) < 0 )
goto V_360;
F_189 ( V_354 , NULL ) ;
return V_354 ;
V_355:
F_47 ( F_19 ( V_8 ) , V_339 ) ;
V_356:
F_181 ( V_68 ) ;
exit:
F_47 ( F_19 ( V_8 ) , V_150 ) ;
return NULL ;
V_360:
F_190 ( V_354 ) ;
F_64 ( V_354 ) ;
goto exit;
}
static struct V_7 * F_191 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_7 * V_362 ;
struct V_103 * * V_149 ;
struct V_103 * V_104 = F_61 ( V_8 , & V_149 , V_98 -> V_6 ,
V_95 -> V_4 , V_95 -> V_3 ) ;
if ( V_104 )
return F_192 ( V_8 , V_2 , V_104 , V_149 , false ) ;
V_362 = F_193 ( F_19 ( V_8 ) , & V_111 , V_95 -> V_4 ,
V_98 -> V_6 , V_95 -> V_3 , V_98 -> V_5 , F_43 ( V_2 ) ) ;
if ( V_362 ) {
if ( V_362 -> V_112 != V_113 ) {
F_46 ( V_362 ) ;
return V_362 ;
}
F_44 ( F_45 ( V_362 ) ) ;
return NULL ;
}
#ifdef F_105
if ( ! V_98 -> V_178 )
V_8 = F_194 ( V_8 , V_2 , & ( F_108 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_10 F_195 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 = F_3 ( V_2 ) ;
if ( V_2 -> V_155 == V_363 ) {
if ( ! F_68 ( V_2 -> V_109 , V_95 -> V_4 ,
V_95 -> V_3 , V_2 -> V_162 ) ) {
V_2 -> V_155 = V_364 ;
return 0 ;
}
}
V_2 -> V_162 = F_85 ( V_95 -> V_4 , V_95 -> V_3 ,
V_2 -> V_109 , V_57 , 0 ) ;
if ( V_2 -> V_109 <= 76 ) {
return F_196 ( V_2 ) ;
}
return 0 ;
}
int F_197 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_365 ;
#ifdef F_74
if ( F_144 ( V_8 , V_2 ) )
goto V_366;
#endif
if ( V_8 -> V_112 == V_367 ) {
struct V_82 * V_68 = V_8 -> V_368 ;
F_198 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_369 != V_2 -> V_370 ||
V_68 -> V_90 -> V_157 ( V_68 , 0 ) == NULL ) {
F_181 ( V_68 ) ;
V_8 -> V_368 = NULL ;
}
}
F_199 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ;
return 0 ;
}
if ( V_2 -> V_109 < F_200 ( V_2 ) || F_201 ( V_2 ) )
goto V_371;
if ( V_8 -> V_112 == V_122 ) {
struct V_7 * V_362 = F_191 ( V_8 , V_2 ) ;
if ( ! V_362 )
goto V_366;
if ( V_362 != V_8 ) {
F_198 ( V_362 , V_2 ) ;
if ( F_202 ( V_8 , V_362 , V_2 ) ) {
V_365 = V_362 ;
goto V_372;
}
return 0 ;
}
} else
F_198 ( V_8 , V_2 ) ;
if ( F_203 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_365 = V_8 ;
goto V_372;
}
return 0 ;
V_372:
F_73 ( V_365 , V_2 ) ;
V_366:
F_154 ( V_2 ) ;
return 0 ;
V_371:
F_87 ( F_19 ( V_8 ) , V_373 ) ;
F_87 ( F_19 ( V_8 ) , V_374 ) ;
goto V_366;
}
void F_204 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
if ( V_2 -> V_375 != V_376 )
return;
if ( ! F_205 ( V_2 , F_206 ( V_2 ) + sizeof( struct V_97 ) ) )
return;
V_95 = F_3 ( V_2 ) ;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_161 < sizeof( struct V_97 ) / 4 )
return;
V_8 = F_207 ( F_40 ( V_2 -> V_108 ) , & V_111 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , F_80 ( V_98 -> V_5 ) ,
V_2 -> V_370 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_377 = V_378 ;
if ( V_8 -> V_112 != V_113 ) {
struct V_82 * V_68 = V_8 -> V_368 ;
if ( V_68 )
V_68 = F_208 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_369 == V_2 -> V_370 )
F_209 ( V_2 , V_68 ) ;
}
}
}
bool F_210 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_379 || ! V_14 -> V_380 . V_381 )
return false ;
if ( V_2 -> V_109 <= F_200 ( V_2 ) &&
F_211 ( & V_14 -> V_380 . V_382 ) == 0 )
return false ;
F_212 ( V_2 ) ;
F_164 ( & V_14 -> V_380 . V_382 , V_2 ) ;
V_14 -> V_380 . V_383 += V_2 -> V_384 ;
if ( V_14 -> V_380 . V_383 > V_8 -> V_385 ) {
struct V_1 * V_386 ;
F_56 ( F_13 ( V_8 ) ) ;
while ( ( V_386 = F_213 ( & V_14 -> V_380 . V_382 ) ) != NULL ) {
F_214 ( V_8 , V_386 ) ;
F_47 ( F_19 ( V_8 ) ,
V_387 ) ;
}
V_14 -> V_380 . V_383 = 0 ;
} else if ( F_211 ( & V_14 -> V_380 . V_382 ) == 1 ) {
F_215 ( F_216 ( V_8 ) ,
V_388 | V_389 | V_390 ) ;
if ( ! F_217 ( V_8 ) )
F_59 ( V_8 , V_391 ,
( 3 * F_218 ( V_8 ) ) / 4 ,
V_146 ) ;
}
return true ;
}
int F_219 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
int V_392 ;
struct V_107 * V_107 = F_40 ( V_2 -> V_108 ) ;
if ( V_2 -> V_375 != V_376 )
goto V_393;
F_87 ( V_107 , V_394 ) ;
if ( ! F_205 ( V_2 , sizeof( struct V_97 ) ) )
goto V_393;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_161 < sizeof( struct V_97 ) / 4 )
goto V_395;
if ( ! F_205 ( V_2 , V_98 -> V_161 * 4 ) )
goto V_393;
if ( ! F_220 ( V_2 ) && F_195 ( V_2 ) )
goto V_396;
V_98 = F_4 ( V_2 ) ;
V_95 = F_3 ( V_2 ) ;
F_58 ( V_2 ) -> V_105 = F_49 ( V_98 -> V_105 ) ;
F_58 ( V_2 ) -> V_304 = ( F_58 ( V_2 ) -> V_105 + V_98 -> V_178 + V_98 -> V_179 +
V_2 -> V_109 - V_98 -> V_161 * 4 ) ;
F_58 ( V_2 ) -> V_177 = F_49 ( V_98 -> V_177 ) ;
F_58 ( V_2 ) -> V_144 = 0 ;
F_58 ( V_2 ) -> V_397 = F_221 ( V_95 ) ;
F_58 ( V_2 ) -> V_398 = 0 ;
V_8 = F_222 ( & V_111 , V_2 , V_98 -> V_6 , V_98 -> V_5 ) ;
if ( ! V_8 )
goto V_399;
V_400:
if ( V_8 -> V_112 == V_113 )
goto V_401;
if ( F_48 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_47 ( V_107 , V_120 ) ;
goto V_402;
}
if ( ! F_223 ( V_8 , V_403 , V_2 ) )
goto V_402;
F_224 ( V_2 ) ;
if ( F_225 ( V_8 , V_2 ) )
goto V_402;
F_226 ( V_8 , V_2 ) ;
V_2 -> V_108 = NULL ;
F_227 ( V_8 ) ;
V_392 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_228
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_380 . V_404 && V_14 -> V_380 . V_405 )
V_14 -> V_380 . V_404 = F_229 () ;
if ( V_14 -> V_380 . V_404 )
V_392 = F_197 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_210 ( V_8 , V_2 ) )
V_392 = F_197 ( V_8 , V_2 ) ;
}
} else if ( F_48 ( F_230 ( V_8 , V_2 ,
V_8 -> V_385 + V_8 -> V_406 ) ) ) {
F_65 ( V_8 ) ;
F_47 ( V_107 , V_407 ) ;
goto V_402;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
return V_392 ;
V_399:
if ( ! F_223 ( NULL , V_403 , V_2 ) )
goto V_393;
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) || F_201 ( V_2 ) ) {
V_396:
F_87 ( V_107 , V_373 ) ;
V_395:
F_87 ( V_107 , V_374 ) ;
} else {
F_73 ( NULL , V_2 ) ;
}
V_393:
F_154 ( V_2 ) ;
return 0 ;
V_402:
F_66 ( V_8 ) ;
goto V_393;
V_401:
if ( ! F_223 ( NULL , V_403 , V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_393;
}
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_395;
}
if ( F_201 ( V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_396;
}
switch ( F_231 ( F_45 ( V_8 ) , V_2 , V_98 ) ) {
case V_408 : {
struct V_7 * V_409 = F_232 ( F_40 ( V_2 -> V_108 ) ,
& V_111 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , V_98 -> V_5 ,
F_43 ( V_2 ) ) ;
if ( V_409 ) {
F_233 ( F_45 ( V_8 ) , & V_66 ) ;
F_44 ( F_45 ( V_8 ) ) ;
V_8 = V_409 ;
goto V_400;
}
}
case V_410 :
F_91 ( V_8 , V_2 ) ;
break;
case V_411 :
goto V_399;
case V_412 : ;
}
goto V_393;
}
void F_184 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_79 ( V_2 ) ;
F_234 ( V_68 ) ;
V_8 -> V_368 = V_68 ;
F_11 ( V_8 ) -> V_369 = V_2 -> V_370 ;
}
static int F_235 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = F_23 ( V_8 ) ;
F_236 ( V_8 ) ;
V_101 -> V_325 = & V_413 ;
#ifdef F_74
F_7 ( V_8 ) -> V_341 = & V_414 ;
#endif
return 0 ;
}
void F_237 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_238 ( V_8 ) ;
F_239 ( V_8 ) ;
F_240 ( V_8 ) ;
F_241 ( & V_14 -> V_415 ) ;
#ifdef F_74
if ( V_14 -> V_248 ) {
F_129 ( V_8 ) ;
F_128 ( V_14 -> V_248 , V_264 ) ;
V_14 -> V_248 = NULL ;
}
#endif
#ifdef F_228
F_241 ( & V_8 -> V_416 ) ;
#endif
F_241 ( & V_14 -> V_380 . V_382 ) ;
if ( F_23 ( V_8 ) -> V_417 )
F_242 ( V_8 ) ;
F_56 ( V_14 -> V_121 != NULL ) ;
F_243 ( V_14 ) ;
F_244 ( V_8 ) ;
F_245 ( V_8 ) ;
}
static void * F_246 ( struct V_418 * V_105 , void * V_419 )
{
struct V_100 * V_101 ;
struct V_420 * V_261 ;
struct V_7 * V_8 = V_419 ;
struct V_421 * V_422 ;
struct V_423 * V_424 = V_105 -> V_425 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
if ( ! V_8 ) {
V_422 = & V_111 . V_426 [ V_424 -> V_427 ] ;
F_248 ( & V_422 -> V_310 ) ;
V_8 = F_249 ( & V_422 -> V_159 ) ;
V_424 -> V_205 = 0 ;
goto V_428;
}
V_422 = & V_111 . V_426 [ V_424 -> V_427 ] ;
++ V_424 -> V_429 ;
++ V_424 -> V_205 ;
if ( V_424 -> V_430 == V_431 ) {
struct V_103 * V_104 = V_419 ;
V_101 = F_23 ( V_424 -> V_432 ) ;
V_104 = V_104 -> V_314 ;
while ( 1 ) {
while ( V_104 ) {
if ( V_104 -> V_433 -> V_243 == V_424 -> V_243 ) {
V_419 = V_104 ;
goto V_117;
}
V_104 = V_104 -> V_314 ;
}
if ( ++ V_424 -> V_434 >= V_101 -> V_235 . V_236 -> V_435 )
break;
V_436:
V_104 = V_101 -> V_235 . V_236 -> V_437 [ V_424 -> V_434 ] ;
}
V_8 = F_250 ( V_424 -> V_432 ) ;
V_424 -> V_430 = V_438 ;
F_251 ( & V_101 -> V_235 . V_439 ) ;
} else {
V_101 = F_23 ( V_8 ) ;
F_252 ( & V_101 -> V_235 . V_439 ) ;
if ( F_253 ( & V_101 -> V_235 ) )
goto V_440;
F_251 ( & V_101 -> V_235 . V_439 ) ;
V_8 = F_250 ( V_8 ) ;
}
V_428:
F_254 (sk, node) {
if ( ! F_255 ( F_19 ( V_8 ) , V_107 ) )
continue;
if ( V_8 -> V_441 == V_424 -> V_243 ) {
V_419 = V_8 ;
goto V_117;
}
V_101 = F_23 ( V_8 ) ;
F_252 ( & V_101 -> V_235 . V_439 ) ;
if ( F_253 ( & V_101 -> V_235 ) ) {
V_440:
V_424 -> V_442 = F_256 ( V_8 ) ;
V_424 -> V_432 = V_8 ;
V_424 -> V_430 = V_431 ;
V_424 -> V_434 = 0 ;
goto V_436;
}
F_251 ( & V_101 -> V_235 . V_439 ) ;
}
F_257 ( & V_422 -> V_310 ) ;
V_424 -> V_205 = 0 ;
if ( ++ V_424 -> V_427 < V_443 ) {
V_422 = & V_111 . V_426 [ V_424 -> V_427 ] ;
F_248 ( & V_422 -> V_310 ) ;
V_8 = F_249 ( & V_422 -> V_159 ) ;
goto V_428;
}
V_419 = NULL ;
V_117:
return V_419 ;
}
static void * F_258 ( struct V_418 * V_105 , T_11 * V_444 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
void * V_445 ;
V_424 -> V_427 = 0 ;
V_424 -> V_205 = 0 ;
V_445 = F_246 ( V_105 , NULL ) ;
while ( V_445 && * V_444 ) {
V_445 = F_246 ( V_105 , V_445 ) ;
-- * V_444 ;
}
return V_445 ;
}
static inline bool F_259 ( const struct V_423 * V_424 )
{
return F_260 ( & V_111 . V_446 [ V_424 -> V_427 ] . V_447 ) ;
}
static void * F_261 ( struct V_418 * V_105 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
void * V_445 = NULL ;
V_424 -> V_205 = 0 ;
for (; V_424 -> V_427 <= V_111 . V_448 ; ++ V_424 -> V_427 ) {
struct V_7 * V_8 ;
struct V_420 * V_261 ;
T_12 * V_310 = F_262 ( & V_111 , V_424 -> V_427 ) ;
if ( F_259 ( V_424 ) )
continue;
F_248 ( V_310 ) ;
F_263 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_441 != V_424 -> V_243 ||
! F_255 ( F_19 ( V_8 ) , V_107 ) ) {
continue;
}
V_445 = V_8 ;
goto V_117;
}
F_257 ( V_310 ) ;
}
V_117:
return V_445 ;
}
static void * F_264 ( struct V_418 * V_105 , void * V_419 )
{
struct V_7 * V_8 = V_419 ;
struct V_420 * V_261 ;
struct V_423 * V_424 = V_105 -> V_425 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
++ V_424 -> V_429 ;
++ V_424 -> V_205 ;
V_8 = F_250 ( V_8 ) ;
F_254 (sk, node) {
if ( V_8 -> V_441 == V_424 -> V_243 && F_255 ( F_19 ( V_8 ) , V_107 ) )
return V_8 ;
}
F_257 ( F_262 ( & V_111 , V_424 -> V_427 ) ) ;
++ V_424 -> V_427 ;
return F_261 ( V_105 ) ;
}
static void * F_265 ( struct V_418 * V_105 , T_11 V_444 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
void * V_445 ;
V_424 -> V_427 = 0 ;
V_445 = F_261 ( V_105 ) ;
while ( V_445 && V_444 ) {
V_445 = F_264 ( V_105 , V_445 ) ;
-- V_444 ;
}
return V_445 ;
}
static void * F_266 ( struct V_418 * V_105 , T_11 V_444 )
{
void * V_445 ;
struct V_423 * V_424 = V_105 -> V_425 ;
V_424 -> V_430 = V_438 ;
V_445 = F_258 ( V_105 , & V_444 ) ;
if ( ! V_445 ) {
V_424 -> V_430 = V_449 ;
V_445 = F_265 ( V_105 , V_444 ) ;
}
return V_445 ;
}
static void * F_267 ( struct V_418 * V_105 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
int V_205 = V_424 -> V_205 ;
int V_450 = V_424 -> V_429 ;
void * V_445 = NULL ;
switch ( V_424 -> V_430 ) {
case V_431 :
case V_438 :
if ( V_424 -> V_427 >= V_443 )
break;
V_424 -> V_430 = V_438 ;
V_445 = F_246 ( V_105 , NULL ) ;
while ( V_205 -- && V_445 )
V_445 = F_246 ( V_105 , V_445 ) ;
if ( V_445 )
break;
V_424 -> V_427 = 0 ;
V_424 -> V_430 = V_449 ;
case V_449 :
if ( V_424 -> V_427 > V_111 . V_448 )
break;
V_445 = F_261 ( V_105 ) ;
while ( V_205 -- && V_445 )
V_445 = F_264 ( V_105 , V_445 ) ;
}
V_424 -> V_429 = V_450 ;
return V_445 ;
}
static void * F_268 ( struct V_418 * V_105 , T_11 * V_444 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
void * V_445 ;
if ( * V_444 && * V_444 == V_424 -> V_451 ) {
V_445 = F_267 ( V_105 ) ;
if ( V_445 )
goto V_117;
}
V_424 -> V_430 = V_438 ;
V_424 -> V_429 = 0 ;
V_424 -> V_427 = 0 ;
V_424 -> V_205 = 0 ;
V_445 = * V_444 ? F_266 ( V_105 , * V_444 - 1 ) : V_452 ;
V_117:
V_424 -> V_451 = * V_444 ;
return V_445 ;
}
static void * F_269 ( struct V_418 * V_105 , void * V_453 , T_11 * V_444 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
void * V_445 = NULL ;
if ( V_453 == V_452 ) {
V_445 = F_266 ( V_105 , 0 ) ;
goto V_117;
}
switch ( V_424 -> V_430 ) {
case V_431 :
case V_438 :
V_445 = F_246 ( V_105 , V_453 ) ;
if ( ! V_445 ) {
V_424 -> V_430 = V_449 ;
V_424 -> V_427 = 0 ;
V_424 -> V_205 = 0 ;
V_445 = F_261 ( V_105 ) ;
}
break;
case V_449 :
V_445 = F_264 ( V_105 , V_453 ) ;
break;
}
V_117:
++ * V_444 ;
V_424 -> V_451 = * V_444 ;
return V_445 ;
}
static void F_270 ( struct V_418 * V_105 , void * V_453 )
{
struct V_423 * V_424 = V_105 -> V_425 ;
switch ( V_424 -> V_430 ) {
case V_431 :
if ( V_453 ) {
struct V_100 * V_101 = F_23 ( V_424 -> V_432 ) ;
F_251 ( & V_101 -> V_235 . V_439 ) ;
}
case V_438 :
if ( V_453 != V_452 )
F_257 ( & V_111 . V_426 [ V_424 -> V_427 ] . V_310 ) ;
break;
case V_449 :
if ( V_453 )
F_257 ( F_262 ( & V_111 , V_424 -> V_427 ) ) ;
break;
}
}
int F_271 ( struct V_454 * V_454 , struct V_455 * V_455 )
{
struct V_456 * V_457 = F_272 ( V_454 ) ;
struct V_423 * V_458 ;
int V_37 ;
V_37 = F_273 ( V_454 , V_455 , & V_457 -> V_459 ,
sizeof( struct V_423 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_458 = ( (struct V_418 * ) V_455 -> V_460 ) -> V_425 ;
V_458 -> V_243 = V_457 -> V_243 ;
V_458 -> V_451 = 0 ;
return 0 ;
}
int F_274 ( struct V_107 * V_107 , struct V_456 * V_457 )
{
int V_445 = 0 ;
struct V_461 * V_462 ;
V_457 -> V_459 . V_463 = F_268 ;
V_457 -> V_459 . V_464 = F_269 ;
V_457 -> V_459 . V_465 = F_270 ;
V_462 = F_275 ( V_457 -> V_466 , V_467 , V_107 -> V_468 ,
V_457 -> V_469 , V_457 ) ;
if ( ! V_462 )
V_445 = - V_259 ;
return V_445 ;
}
void F_276 ( struct V_107 * V_107 , struct V_456 * V_457 )
{
F_277 ( V_457 -> V_466 , V_107 -> V_468 ) ;
}
static void F_278 ( const struct V_7 * V_8 , const struct V_103 * V_104 ,
struct V_418 * V_470 , int V_471 , T_13 V_442 )
{
const struct V_219 * V_220 = F_94 ( V_104 ) ;
long V_472 = V_104 -> V_312 - V_79 ;
F_279 ( V_470 , L_9
L_10 ,
V_471 ,
V_220 -> V_221 ,
F_80 ( F_11 ( V_8 ) -> V_49 ) ,
V_220 -> V_222 ,
F_80 ( V_220 -> V_473 ) ,
V_151 ,
0 , 0 ,
1 ,
F_280 ( V_472 ) ,
V_104 -> V_324 ,
F_281 ( F_282 ( V_470 ) , V_442 ) ,
0 ,
0 ,
F_283 ( & V_8 -> V_474 ) ,
V_104 ) ;
}
static void F_284 ( struct V_7 * V_8 , struct V_418 * V_470 , int V_471 )
{
int V_475 ;
unsigned long V_476 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_100 * V_101 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_299 * V_300 = V_101 -> V_235 . V_300 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_477 = V_29 -> V_63 ;
T_14 V_478 = F_80 ( V_29 -> V_69 ) ;
T_14 V_479 = F_80 ( V_29 -> V_49 ) ;
int V_480 ;
if ( V_101 -> V_481 == V_145 ||
V_101 -> V_481 == V_482 ||
V_101 -> V_481 == V_483 ) {
V_475 = 1 ;
V_476 = V_101 -> V_484 ;
} else if ( V_101 -> V_481 == V_485 ) {
V_475 = 4 ;
V_476 = V_101 -> V_484 ;
} else if ( F_285 ( & V_8 -> V_486 ) ) {
V_475 = 2 ;
V_476 = V_8 -> V_486 . V_312 ;
} else {
V_475 = 0 ;
V_476 = V_79 ;
}
if ( V_8 -> V_112 == V_122 )
V_480 = V_8 -> V_487 ;
else
V_480 = F_286 ( int , V_14 -> V_215 - V_14 -> V_488 , 0 ) ;
F_279 ( V_470 , L_11
L_12 ,
V_471 , V_477 , V_479 , V_5 , V_478 , V_8 -> V_112 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_480 ,
V_475 ,
F_280 ( V_476 - V_79 ) ,
V_101 -> V_138 ,
F_281 ( F_282 ( V_470 ) , F_256 ( V_8 ) ) ,
V_101 -> V_489 ,
F_287 ( V_8 ) ,
F_283 ( & V_8 -> V_474 ) , V_8 ,
F_288 ( V_101 -> V_140 ) ,
F_288 ( V_101 -> V_490 . V_491 ) ,
( V_101 -> V_490 . V_492 << 1 ) | V_101 -> V_490 . V_493 ,
V_14 -> V_494 ,
V_8 -> V_112 == V_122 ?
( V_300 ? V_300 -> V_307 : 0 ) :
( F_289 ( V_14 ) ? - 1 : V_14 -> V_495 ) ) ;
}
static void F_290 ( const struct V_206 * V_207 ,
struct V_418 * V_470 , int V_471 )
{
T_3 V_5 , V_477 ;
T_14 V_478 , V_479 ;
T_15 V_472 = V_207 -> V_496 - F_291 () ;
V_5 = V_207 -> V_497 ;
V_477 = V_207 -> V_498 ;
V_478 = F_80 ( V_207 -> V_499 ) ;
V_479 = F_80 ( V_207 -> V_500 ) ;
F_279 ( V_470 , L_9
L_13 ,
V_471 , V_477 , V_479 , V_5 , V_478 , V_207 -> V_501 , 0 , 0 ,
3 , F_280 ( V_472 ) , 0 , 0 , 0 , 0 ,
F_283 ( & V_207 -> V_502 ) , V_207 ) ;
}
static int F_292 ( struct V_418 * V_105 , void * V_453 )
{
struct V_423 * V_424 ;
struct V_7 * V_8 = V_453 ;
F_293 ( V_105 , V_503 - 1 ) ;
if ( V_453 == V_452 ) {
F_294 ( V_105 , L_14
L_15
L_16 ) ;
goto V_117;
}
V_424 = V_105 -> V_425 ;
switch ( V_424 -> V_430 ) {
case V_438 :
case V_449 :
if ( V_8 -> V_112 == V_113 )
F_290 ( V_453 , V_105 , V_424 -> V_429 ) ;
else
F_284 ( V_453 , V_105 , V_424 -> V_429 ) ;
break;
case V_431 :
F_278 ( V_424 -> V_432 , V_453 , V_105 , V_424 -> V_429 , V_424 -> V_442 ) ;
break;
}
V_117:
F_295 ( V_105 , '\n' ) ;
return 0 ;
}
static int T_16 F_296 ( struct V_107 * V_107 )
{
return F_274 ( V_107 , & V_504 ) ;
}
static void T_17 F_297 ( struct V_107 * V_107 )
{
F_276 ( V_107 , & V_504 ) ;
}
int T_18 F_298 ( void )
{
return F_299 ( & V_505 ) ;
}
void F_300 ( void )
{
F_301 ( & V_505 ) ;
}
static int T_16 F_302 ( struct V_107 * V_107 )
{
V_107 -> V_506 . V_507 = 2 ;
return 0 ;
}
static void T_17 F_303 ( struct V_107 * V_107 )
{
}
static void T_17 F_304 ( struct V_508 * V_509 )
{
F_305 ( & V_111 , & V_66 , V_42 ) ;
}
void T_18 F_306 ( void )
{
F_307 ( & V_111 ) ;
if ( F_299 ( & V_510 ) )
F_308 ( L_17 ) ;
}
