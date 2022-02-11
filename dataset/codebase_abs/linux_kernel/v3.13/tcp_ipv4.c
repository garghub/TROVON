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
if ( ! V_224 )
F_87 ( F_19 ( V_8 ) , V_225 ) ;
return V_224 ;
}
static void F_102 ( struct V_103 * V_104 )
{
F_103 ( F_94 ( V_104 ) -> V_46 ) ;
}
bool F_104 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_226 )
{
const char * V_227 = L_1 ;
bool V_228 = false ;
struct V_229 * V_230 ;
#ifdef F_105
if ( V_231 ) {
V_227 = L_2 ;
V_228 = true ;
F_47 ( F_19 ( V_8 ) , V_232 ) ;
} else
#endif
F_47 ( F_19 ( V_8 ) , V_233 ) ;
V_230 = F_23 ( V_8 ) -> V_234 . V_235 ;
if ( ! V_230 -> V_236 && V_231 != 2 ) {
V_230 -> V_236 = 1 ;
F_106 ( L_3 ,
V_226 , F_80 ( F_4 ( V_2 ) -> V_5 ) , V_227 ) ;
}
return V_228 ;
}
static struct V_38 * F_107 ( struct V_1 * V_2 )
{
const struct V_237 * V_46 = & ( F_108 ( V_2 ) -> V_46 ) ;
struct V_38 * V_238 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_239 = sizeof( * V_238 ) + V_46 -> V_71 ;
V_238 = F_109 ( V_239 , V_240 ) ;
if ( V_238 ) {
if ( F_110 ( & V_238 -> V_46 , V_2 ) ) {
F_103 ( V_238 ) ;
V_238 = NULL ;
}
}
}
return V_238 ;
}
struct V_167 * F_82 ( struct V_7 * V_8 ,
const union V_183 * V_241 ,
int V_242 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
unsigned int V_243 = sizeof( struct V_244 ) ;
struct V_245 * V_246 ;
V_246 = F_111 ( V_14 -> V_247 ,
F_13 ( V_8 ) ||
F_112 ( & V_8 -> V_248 . V_249 ) ) ;
if ( ! V_246 )
return NULL ;
#if F_113 ( V_250 )
if ( V_242 == V_251 )
V_243 = sizeof( struct V_252 ) ;
#endif
F_114 (key, &md5sig->head, node) {
if ( V_168 -> V_242 != V_242 )
continue;
if ( ! memcmp ( & V_168 -> V_241 , V_241 , V_243 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_115 ( struct V_7 * V_8 ,
struct V_7 * V_253 )
{
union V_183 * V_241 ;
V_241 = (union V_183 * ) & F_11 ( V_253 ) -> V_64 ;
return F_82 ( V_8 , V_241 , V_42 ) ;
}
static struct V_167 * F_116 ( struct V_7 * V_8 ,
struct V_103 * V_104 )
{
union V_183 * V_241 ;
V_241 = (union V_183 * ) & F_94 ( V_104 ) -> V_222 ;
return F_82 ( V_8 , V_241 , V_42 ) ;
}
int F_117 ( struct V_7 * V_8 , const union V_183 * V_241 ,
int V_242 , const T_6 * V_254 , T_6 V_255 , T_8 V_256 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_245 * V_246 ;
V_168 = F_82 ( V_8 , V_241 , V_242 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_254 , V_255 ) ;
V_168 -> V_257 = V_255 ;
return 0 ;
}
V_246 = F_12 ( V_14 -> V_247 ,
F_13 ( V_8 ) ) ;
if ( ! V_246 ) {
V_246 = F_109 ( sizeof( * V_246 ) , V_256 ) ;
if ( ! V_246 )
return - V_258 ;
F_118 ( V_8 , V_259 ) ;
F_119 ( & V_246 -> V_159 ) ;
F_120 ( V_14 -> V_247 , V_246 ) ;
}
V_168 = F_121 ( V_8 , sizeof( * V_168 ) , V_256 ) ;
if ( ! V_168 )
return - V_258 ;
if ( ! F_122 () ) {
F_123 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_258 ;
}
memcpy ( V_168 -> V_168 , V_254 , V_255 ) ;
V_168 -> V_257 = V_255 ;
V_168 -> V_242 = V_242 ;
memcpy ( & V_168 -> V_241 , V_241 ,
( V_242 == V_251 ) ? sizeof( struct V_252 ) :
sizeof( struct V_244 ) ) ;
F_124 ( & V_168 -> V_260 , & V_246 -> V_159 ) ;
return 0 ;
}
int F_125 ( struct V_7 * V_8 , const union V_183 * V_241 , int V_242 )
{
struct V_167 * V_168 ;
V_168 = F_82 ( V_8 , V_241 , V_242 ) ;
if ( ! V_168 )
return - V_261 ;
F_126 ( & V_168 -> V_260 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_262 ) ;
F_128 ( V_168 , V_263 ) ;
return 0 ;
}
static void F_129 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_264 * V_265 ;
struct V_245 * V_246 ;
V_246 = F_12 ( V_14 -> V_247 , 1 ) ;
F_130 (key, n, &md5sig->head, node) {
F_126 ( & V_168 -> V_260 ) ;
F_127 ( sizeof( * V_168 ) , & V_8 -> V_262 ) ;
F_128 ( V_168 , V_263 ) ;
}
}
static int F_131 ( struct V_7 * V_8 , char T_9 * V_266 ,
int V_71 )
{
struct V_267 V_268 ;
struct V_26 * sin = (struct V_26 * ) & V_268 . V_269 ;
if ( V_71 < sizeof( V_268 ) )
return - V_40 ;
if ( F_132 ( & V_268 , V_266 , sizeof( V_268 ) ) )
return - V_270 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_268 . V_271 || ! V_268 . V_272 )
return F_125 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_268 . V_272 > V_273 )
return - V_40 ;
return F_117 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_268 . V_271 , V_268 . V_272 ,
V_274 ) ;
}
static int F_133 ( struct V_275 * V_276 ,
T_3 V_3 , T_3 V_4 , int V_277 )
{
struct V_278 * V_279 ;
struct V_280 V_281 ;
V_279 = & V_276 -> V_282 . V_54 ;
V_279 -> V_4 = V_4 ;
V_279 -> V_3 = V_3 ;
V_279 -> V_283 = 0 ;
V_279 -> V_284 = V_57 ;
V_279 -> V_109 = F_134 ( V_277 ) ;
F_135 ( & V_281 , V_279 , sizeof( * V_279 ) ) ;
return F_136 ( & V_276 -> V_285 , & V_281 , sizeof( * V_279 ) ) ;
}
static int F_84 ( char * V_286 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_97 * V_98 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
V_276 = F_137 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_138 ( V_288 ) )
goto V_290;
if ( F_133 ( V_276 , V_3 , V_4 , V_98 -> V_161 << 2 ) )
goto V_290;
if ( F_139 ( V_276 , V_98 ) )
goto V_290;
if ( F_140 ( V_276 , V_168 ) )
goto V_290;
if ( F_141 ( V_288 , V_286 ) )
goto V_290;
F_142 () ;
return 0 ;
V_290:
F_142 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
int F_83 ( char * V_286 , struct V_167 * V_168 ,
const struct V_7 * V_8 , const struct V_103 * V_104 ,
const struct V_1 * V_2 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
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
V_276 = F_137 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_138 ( V_288 ) )
goto V_290;
if ( F_133 ( V_276 , V_3 , V_4 , V_2 -> V_109 ) )
goto V_290;
if ( F_139 ( V_276 , V_98 ) )
goto V_290;
if ( F_143 ( V_276 , V_2 , V_98 -> V_161 << 2 ) )
goto V_290;
if ( F_140 ( V_276 , V_168 ) )
goto V_290;
if ( F_141 ( V_288 , V_286 ) )
goto V_290;
F_142 () ;
return 0 ;
V_290:
F_142 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
static bool F_144 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_169 = NULL ;
struct V_167 * V_291 ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_291 = F_82 ( V_8 , (union V_183 * ) & V_95 -> V_4 ,
V_42 ) ;
V_169 = F_77 ( V_98 ) ;
if ( ! V_291 && ! V_169 )
return false ;
if ( V_291 && ! V_169 ) {
F_47 ( F_19 ( V_8 ) , V_292 ) ;
return true ;
}
if ( ! V_291 && V_169 ) {
F_47 ( F_19 ( V_8 ) , V_293 ) ;
return true ;
}
V_171 = F_83 ( V_170 ,
V_291 ,
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
struct V_294 * V_295 ,
struct V_294 * V_296 )
{
bool V_297 = false ;
struct V_298 * V_299 ;
if ( F_21 ( ! F_147 ( V_295 ) ) ) {
if ( ( V_300 & V_301 ) ||
( ( V_300 & V_302 ) &&
( F_58 ( V_2 ) -> V_303 != F_58 ( V_2 ) -> V_105 + 1 ) ) )
V_297 = true ;
else
return false ;
}
V_299 = F_23 ( V_8 ) -> V_234 . V_299 ;
F_47 ( F_19 ( V_8 ) , V_304 ) ;
if ( ( V_300 & V_305 ) == 0 ||
V_299 == NULL || V_299 -> V_306 == 0 )
return false ;
if ( V_299 -> V_307 >= V_299 -> V_306 ) {
struct V_103 * V_308 ;
F_148 ( & V_299 -> V_309 ) ;
V_308 = V_299 -> V_310 ;
if ( ( V_308 == NULL ) || F_149 ( V_308 -> V_311 , V_79 ) ) {
F_150 ( & V_299 -> V_309 ) ;
F_47 ( F_19 ( V_8 ) ,
V_312 ) ;
V_295 -> V_109 = - 1 ;
return false ;
}
V_299 -> V_310 = V_308 -> V_313 ;
V_299 -> V_307 -- ;
F_150 ( & V_299 -> V_309 ) ;
F_151 ( V_308 ) ;
}
if ( V_297 ) {
F_51 ( V_104 ) -> V_215 = F_58 ( V_2 ) -> V_303 ;
return true ;
}
if ( V_295 -> V_109 == V_314 ) {
if ( ( V_300 & V_315 ) == 0 ) {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_296 ) ;
if ( ( V_296 -> V_109 != V_314 ) ||
memcmp ( & V_295 -> V_316 [ 0 ] , & V_296 -> V_316 [ 0 ] ,
V_314 ) != 0 )
return false ;
V_296 -> V_109 = - 1 ;
}
F_51 ( V_104 ) -> V_215 = F_58 ( V_2 ) -> V_303 ;
return true ;
} else if ( V_295 -> V_109 == 0 ) {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_296 ) ;
F_47 ( F_19 ( V_8 ) ,
V_317 ) ;
} else {
F_152 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , V_296 ) ;
}
return false ;
}
static int F_153 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_1 * V_318 ,
struct V_103 * V_104 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_319 * V_320 = & F_23 ( V_8 ) -> V_234 ;
const struct V_219 * V_220 = F_94 ( V_104 ) ;
struct V_7 * V_321 ;
int V_37 ;
V_104 -> V_322 = 0 ;
V_104 -> V_323 = 0 ;
V_104 -> V_8 = NULL ;
V_321 = F_23 ( V_8 ) -> V_324 -> V_325 ( V_8 , V_2 , V_104 , NULL ) ;
if ( V_321 == NULL ) {
F_47 ( F_19 ( V_8 ) ,
V_326 ) ;
F_154 ( V_318 ) ;
return - 1 ;
}
V_37 = F_99 ( V_318 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( ! V_37 )
F_51 ( V_104 ) -> V_223 = V_143 ;
F_148 ( & V_320 -> V_299 -> V_309 ) ;
V_320 -> V_299 -> V_307 ++ ;
F_150 ( & V_320 -> V_299 -> V_309 ) ;
V_14 = F_7 ( V_321 ) ;
V_14 -> V_121 = V_104 ;
F_9 ( V_8 ) ;
F_51 ( V_104 ) -> V_327 = V_8 ;
V_14 -> V_328 = F_80 ( F_4 ( V_2 ) -> V_204 ) ;
F_59 ( V_321 , V_145 ,
V_142 , V_146 ) ;
F_155 ( V_8 , V_104 , V_321 ) ;
F_23 ( V_321 ) -> V_324 -> V_329 ( V_321 ) ;
F_156 ( V_321 ) ;
F_157 ( V_321 ) ;
F_158 ( V_321 ) ;
F_159 ( V_321 ) ;
if ( F_58 ( V_2 ) -> V_303 == F_58 ( V_2 ) -> V_105 + 1 ) {
V_14 -> V_215 = F_58 ( V_2 ) -> V_303 ;
} else {
V_2 = F_160 ( V_2 ) ;
F_161 ( V_2 ) ;
F_162 ( V_2 , F_4 ( V_2 ) -> V_161 * 4 ) ;
F_163 ( V_2 , V_321 ) ;
F_164 ( & V_321 -> V_330 , V_2 ) ;
V_14 -> V_215 = F_58 ( V_2 ) -> V_303 ;
V_14 -> V_331 = 1 ;
}
V_8 -> V_332 ( V_8 , 0 ) ;
F_65 ( V_321 ) ;
F_66 ( V_321 ) ;
F_62 ( V_104 -> V_8 == NULL ) ;
return 0 ;
}
int F_165 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_333 V_334 ;
struct V_103 * V_104 ;
struct V_219 * V_220 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_335 = F_58 ( V_2 ) -> V_144 ;
bool V_228 = false ;
struct V_33 V_34 ;
struct V_294 V_295 = { . V_109 = - 1 } ;
struct V_294 V_296 = { . V_109 = - 1 } ;
struct V_1 * V_318 ;
int V_336 ;
if ( F_75 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_337;
if ( ( V_231 == 2 ||
F_166 ( V_8 ) ) && ! V_335 ) {
V_228 = F_104 ( V_8 , V_2 , L_7 ) ;
if ( ! V_228 )
goto V_337;
}
if ( F_167 ( V_8 ) && F_168 ( V_8 ) > 1 ) {
F_47 ( F_19 ( V_8 ) , V_338 ) ;
goto V_337;
}
V_104 = F_169 ( & V_339 ) ;
if ( ! V_104 )
goto V_337;
#ifdef F_74
F_51 ( V_104 ) -> V_340 = & V_341 ;
#endif
F_170 ( & V_334 ) ;
V_334 . V_72 = V_73 ;
V_334 . V_342 = V_14 -> V_19 . V_342 ;
F_171 ( V_2 , & V_334 , 0 , V_228 ? NULL : & V_295 ) ;
if ( V_228 && ! V_334 . V_343 )
F_170 ( & V_334 ) ;
V_334 . V_344 = V_334 . V_343 ;
F_172 ( V_104 , & V_334 , V_2 ) ;
V_220 = F_94 ( V_104 ) ;
V_220 -> V_221 = V_3 ;
V_220 -> V_222 = V_4 ;
V_220 -> V_217 = F_11 ( V_8 ) -> V_190 ;
V_220 -> V_46 = F_107 ( V_2 ) ;
if ( F_173 ( V_8 , V_2 , V_104 ) )
goto V_345;
if ( ! V_228 || V_334 . V_344 )
F_174 ( V_104 , V_2 , F_19 ( V_8 ) ) ;
if ( V_228 ) {
V_335 = F_175 ( V_8 , V_2 , & V_104 -> V_346 ) ;
V_104 -> V_347 = V_334 . V_344 ;
} else if ( ! V_335 ) {
if ( V_334 . V_343 &&
V_66 . V_67 &&
( V_68 = F_96 ( V_8 , & V_34 , V_104 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_176 ( V_104 , V_68 , true ) ) {
F_47 ( F_19 ( V_8 ) , V_348 ) ;
goto V_349;
}
}
else if ( ! V_231 &&
( V_350 - F_177 ( V_8 ) <
( V_350 >> 2 ) ) &&
! F_176 ( V_104 , V_68 , false ) ) {
F_178 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_349;
}
V_335 = F_1 ( V_2 ) ;
}
F_51 ( V_104 ) -> V_125 = V_335 ;
if ( V_68 == NULL ) {
V_68 = F_96 ( V_8 , & V_34 , V_104 ) ;
if ( V_68 == NULL )
goto V_345;
}
V_336 = F_146 ( V_8 , V_2 , V_104 , & V_295 , & V_296 ) ;
V_318 = F_97 ( V_8 , V_68 , V_104 ,
F_147 ( & V_296 ) ? & V_296 : NULL ) ;
if ( V_318 ) {
F_67 ( V_318 , V_220 -> V_221 , V_220 -> V_222 ) ;
F_98 ( V_318 , F_179 ( V_2 ) ) ;
} else
goto V_345;
if ( F_21 ( ! V_336 ) ) {
int V_37 ;
V_37 = F_99 ( V_318 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_100 ( V_37 ) ;
if ( V_37 || V_228 )
goto V_345;
F_51 ( V_104 ) -> V_223 = V_143 ;
F_51 ( V_104 ) -> V_327 = NULL ;
F_180 ( V_8 , V_104 , V_142 ) ;
if ( F_147 ( & V_295 ) && V_295 . V_109 != 0 )
F_47 ( F_19 ( V_8 ) ,
V_326 ) ;
} else if ( F_153 ( V_8 , V_2 , V_318 , V_104 ) )
goto V_345;
return 0 ;
V_349:
F_181 ( V_68 ) ;
V_345:
F_151 ( V_104 ) ;
V_337:
F_47 ( F_19 ( V_8 ) , V_150 ) ;
return 0 ;
}
struct V_7 * F_182 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_82 * V_68 )
{
struct V_219 * V_220 ;
struct V_28 * V_351 ;
struct V_13 * V_352 ;
struct V_7 * V_353 ;
#ifdef F_74
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_167 ( V_8 ) )
goto V_354;
V_353 = F_183 ( V_8 , V_104 , V_2 ) ;
if ( ! V_353 )
goto V_355;
V_353 -> V_76 = V_77 ;
F_184 ( V_353 , V_2 ) ;
V_352 = F_7 ( V_353 ) ;
V_351 = F_11 ( V_353 ) ;
V_220 = F_94 ( V_104 ) ;
V_351 -> V_64 = V_220 -> V_222 ;
V_351 -> V_63 = V_220 -> V_221 ;
V_351 -> V_55 = V_220 -> V_221 ;
V_39 = V_220 -> V_46 ;
F_120 ( V_351 -> V_39 , V_39 ) ;
V_220 -> V_46 = NULL ;
V_351 -> V_356 = F_43 ( V_2 ) ;
V_351 -> V_357 = F_3 ( V_2 ) -> V_118 ;
V_351 -> V_358 = F_3 ( V_2 ) -> V_193 ;
F_23 ( V_353 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_353 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_351 -> V_78 = V_352 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_185 ( V_8 , V_353 , V_104 ) ;
if ( ! V_68 )
goto V_359;
} else {
}
F_27 ( V_353 , V_68 ) ;
F_157 ( V_353 ) ;
F_34 ( V_353 , F_31 ( V_68 ) ) ;
V_352 -> V_360 = F_186 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_342 &&
F_7 ( V_8 ) -> V_19 . V_342 < V_352 -> V_360 )
V_352 -> V_360 = F_7 ( V_8 ) -> V_19 . V_342 ;
F_187 ( V_353 ) ;
#ifdef F_74
V_168 = F_82 ( V_8 , (union V_183 * ) & V_351 -> V_64 ,
V_42 ) ;
if ( V_168 != NULL ) {
F_117 ( V_353 , (union V_183 * ) & V_351 -> V_64 ,
V_42 , V_168 -> V_168 , V_168 -> V_257 , V_240 ) ;
F_118 ( V_353 , V_259 ) ;
}
#endif
if ( F_188 ( V_8 , V_353 ) < 0 )
goto V_359;
F_189 ( V_353 , NULL ) ;
return V_353 ;
V_354:
F_47 ( F_19 ( V_8 ) , V_338 ) ;
V_355:
F_181 ( V_68 ) ;
exit:
F_47 ( F_19 ( V_8 ) , V_150 ) ;
return NULL ;
V_359:
F_190 ( V_353 ) ;
F_64 ( V_353 ) ;
goto exit;
}
static struct V_7 * F_191 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_7 * V_361 ;
struct V_103 * * V_149 ;
struct V_103 * V_104 = F_61 ( V_8 , & V_149 , V_98 -> V_6 ,
V_95 -> V_4 , V_95 -> V_3 ) ;
if ( V_104 )
return F_192 ( V_8 , V_2 , V_104 , V_149 , false ) ;
V_361 = F_193 ( F_19 ( V_8 ) , & V_111 , V_95 -> V_4 ,
V_98 -> V_6 , V_95 -> V_3 , V_98 -> V_5 , F_43 ( V_2 ) ) ;
if ( V_361 ) {
if ( V_361 -> V_112 != V_113 ) {
F_46 ( V_361 ) ;
return V_361 ;
}
F_44 ( F_45 ( V_361 ) ) ;
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
if ( V_2 -> V_155 == V_362 ) {
if ( ! F_68 ( V_2 -> V_109 , V_95 -> V_4 ,
V_95 -> V_3 , V_2 -> V_162 ) ) {
V_2 -> V_155 = V_363 ;
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
struct V_7 * V_364 ;
#ifdef F_74
if ( F_144 ( V_8 , V_2 ) )
goto V_365;
#endif
if ( V_8 -> V_112 == V_366 ) {
struct V_82 * V_68 = V_8 -> V_367 ;
F_198 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_368 != V_2 -> V_369 ||
V_68 -> V_90 -> V_157 ( V_68 , 0 ) == NULL ) {
F_181 ( V_68 ) ;
V_8 -> V_367 = NULL ;
}
}
F_199 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ;
return 0 ;
}
if ( V_2 -> V_109 < F_200 ( V_2 ) || F_201 ( V_2 ) )
goto V_370;
if ( V_8 -> V_112 == V_122 ) {
struct V_7 * V_361 = F_191 ( V_8 , V_2 ) ;
if ( ! V_361 )
goto V_365;
if ( V_361 != V_8 ) {
F_198 ( V_361 , V_2 ) ;
if ( F_202 ( V_8 , V_361 , V_2 ) ) {
V_364 = V_361 ;
goto V_371;
}
return 0 ;
}
} else
F_198 ( V_8 , V_2 ) ;
if ( F_203 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_364 = V_8 ;
goto V_371;
}
return 0 ;
V_371:
F_73 ( V_364 , V_2 ) ;
V_365:
F_154 ( V_2 ) ;
return 0 ;
V_370:
F_87 ( F_19 ( V_8 ) , V_372 ) ;
F_87 ( F_19 ( V_8 ) , V_373 ) ;
goto V_365;
}
void F_204 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
if ( V_2 -> V_374 != V_375 )
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
V_2 -> V_369 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_376 = V_377 ;
if ( V_8 -> V_112 != V_113 ) {
struct V_82 * V_68 = V_8 -> V_367 ;
if ( V_68 )
V_68 = F_208 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_368 == V_2 -> V_369 )
F_209 ( V_2 , V_68 ) ;
}
}
}
bool F_210 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_378 || ! V_14 -> V_379 . V_380 )
return false ;
if ( V_2 -> V_109 <= F_200 ( V_2 ) &&
F_211 ( & V_14 -> V_379 . V_381 ) == 0 )
return false ;
F_212 ( V_2 ) ;
F_164 ( & V_14 -> V_379 . V_381 , V_2 ) ;
V_14 -> V_379 . V_382 += V_2 -> V_383 ;
if ( V_14 -> V_379 . V_382 > V_8 -> V_384 ) {
struct V_1 * V_385 ;
F_56 ( F_13 ( V_8 ) ) ;
while ( ( V_385 = F_213 ( & V_14 -> V_379 . V_381 ) ) != NULL ) {
F_214 ( V_8 , V_385 ) ;
F_47 ( F_19 ( V_8 ) ,
V_386 ) ;
}
V_14 -> V_379 . V_382 = 0 ;
} else if ( F_211 ( & V_14 -> V_379 . V_381 ) == 1 ) {
F_215 ( F_216 ( V_8 ) ,
V_387 | V_388 | V_389 ) ;
if ( ! F_217 ( V_8 ) )
F_59 ( V_8 , V_390 ,
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
int V_391 ;
struct V_107 * V_107 = F_40 ( V_2 -> V_108 ) ;
if ( V_2 -> V_374 != V_375 )
goto V_392;
F_87 ( V_107 , V_393 ) ;
if ( ! F_205 ( V_2 , sizeof( struct V_97 ) ) )
goto V_392;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_161 < sizeof( struct V_97 ) / 4 )
goto V_394;
if ( ! F_205 ( V_2 , V_98 -> V_161 * 4 ) )
goto V_392;
if ( ! F_220 ( V_2 ) && F_195 ( V_2 ) )
goto V_395;
V_98 = F_4 ( V_2 ) ;
V_95 = F_3 ( V_2 ) ;
F_58 ( V_2 ) -> V_105 = F_49 ( V_98 -> V_105 ) ;
F_58 ( V_2 ) -> V_303 = ( F_58 ( V_2 ) -> V_105 + V_98 -> V_178 + V_98 -> V_179 +
V_2 -> V_109 - V_98 -> V_161 * 4 ) ;
F_58 ( V_2 ) -> V_177 = F_49 ( V_98 -> V_177 ) ;
F_58 ( V_2 ) -> V_144 = 0 ;
F_58 ( V_2 ) -> V_396 = F_221 ( V_95 ) ;
F_58 ( V_2 ) -> V_397 = 0 ;
V_8 = F_222 ( & V_111 , V_2 , V_98 -> V_6 , V_98 -> V_5 ) ;
if ( ! V_8 )
goto V_398;
V_399:
if ( V_8 -> V_112 == V_113 )
goto V_400;
if ( F_48 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_47 ( V_107 , V_120 ) ;
goto V_401;
}
if ( ! F_223 ( V_8 , V_402 , V_2 ) )
goto V_401;
F_224 ( V_2 ) ;
if ( F_225 ( V_8 , V_2 ) )
goto V_401;
F_226 ( V_8 , V_2 ) ;
V_2 -> V_108 = NULL ;
F_227 ( V_8 ) ;
V_391 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_228
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_379 . V_403 && V_14 -> V_379 . V_404 )
V_14 -> V_379 . V_403 = F_229 () ;
if ( V_14 -> V_379 . V_403 )
V_391 = F_197 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_210 ( V_8 , V_2 ) )
V_391 = F_197 ( V_8 , V_2 ) ;
}
} else if ( F_48 ( F_230 ( V_8 , V_2 ,
V_8 -> V_384 + V_8 -> V_405 ) ) ) {
F_65 ( V_8 ) ;
F_47 ( V_107 , V_406 ) ;
goto V_401;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
return V_391 ;
V_398:
if ( ! F_223 ( NULL , V_402 , V_2 ) )
goto V_392;
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) || F_201 ( V_2 ) ) {
V_395:
F_87 ( V_107 , V_372 ) ;
V_394:
F_87 ( V_107 , V_373 ) ;
} else {
F_73 ( NULL , V_2 ) ;
}
V_392:
F_154 ( V_2 ) ;
return 0 ;
V_401:
F_66 ( V_8 ) ;
goto V_392;
V_400:
if ( ! F_223 ( NULL , V_402 , V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_392;
}
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_394;
}
if ( F_201 ( V_2 ) ) {
F_44 ( F_45 ( V_8 ) ) ;
goto V_395;
}
switch ( F_231 ( F_45 ( V_8 ) , V_2 , V_98 ) ) {
case V_407 : {
struct V_7 * V_408 = F_232 ( F_40 ( V_2 -> V_108 ) ,
& V_111 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , V_98 -> V_5 ,
F_43 ( V_2 ) ) ;
if ( V_408 ) {
F_233 ( F_45 ( V_8 ) , & V_66 ) ;
F_44 ( F_45 ( V_8 ) ) ;
V_8 = V_408 ;
goto V_399;
}
}
case V_409 :
F_91 ( V_8 , V_2 ) ;
break;
case V_410 :
goto V_398;
case V_411 : ;
}
goto V_392;
}
void F_184 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_79 ( V_2 ) ;
F_234 ( V_68 ) ;
V_8 -> V_367 = V_68 ;
F_11 ( V_8 ) -> V_368 = V_2 -> V_369 ;
}
static int F_235 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = F_23 ( V_8 ) ;
F_236 ( V_8 ) ;
V_101 -> V_324 = & V_412 ;
#ifdef F_74
F_7 ( V_8 ) -> V_340 = & V_413 ;
#endif
return 0 ;
}
void F_237 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_238 ( V_8 ) ;
F_239 ( V_8 ) ;
F_240 ( V_8 ) ;
F_241 ( & V_14 -> V_414 ) ;
#ifdef F_74
if ( V_14 -> V_247 ) {
F_129 ( V_8 ) ;
F_128 ( V_14 -> V_247 , V_263 ) ;
V_14 -> V_247 = NULL ;
}
#endif
#ifdef F_228
F_241 ( & V_8 -> V_415 ) ;
#endif
F_241 ( & V_14 -> V_379 . V_381 ) ;
if ( F_23 ( V_8 ) -> V_416 )
F_242 ( V_8 ) ;
F_56 ( V_14 -> V_121 != NULL ) ;
F_243 ( V_14 ) ;
F_244 ( V_8 ) ;
F_245 ( V_8 ) ;
}
static void * F_246 ( struct V_417 * V_105 , void * V_418 )
{
struct V_100 * V_101 ;
struct V_419 * V_260 ;
struct V_7 * V_8 = V_418 ;
struct V_420 * V_421 ;
struct V_422 * V_423 = V_105 -> V_424 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
if ( ! V_8 ) {
V_421 = & V_111 . V_425 [ V_423 -> V_426 ] ;
F_248 ( & V_421 -> V_309 ) ;
V_8 = F_249 ( & V_421 -> V_159 ) ;
V_423 -> V_205 = 0 ;
goto V_427;
}
V_421 = & V_111 . V_425 [ V_423 -> V_426 ] ;
++ V_423 -> V_428 ;
++ V_423 -> V_205 ;
if ( V_423 -> V_429 == V_430 ) {
struct V_103 * V_104 = V_418 ;
V_101 = F_23 ( V_423 -> V_431 ) ;
V_104 = V_104 -> V_313 ;
while ( 1 ) {
while ( V_104 ) {
if ( V_104 -> V_432 -> V_242 == V_423 -> V_242 ) {
V_418 = V_104 ;
goto V_117;
}
V_104 = V_104 -> V_313 ;
}
if ( ++ V_423 -> V_433 >= V_101 -> V_234 . V_235 -> V_434 )
break;
V_435:
V_104 = V_101 -> V_234 . V_235 -> V_436 [ V_423 -> V_433 ] ;
}
V_8 = F_250 ( V_423 -> V_431 ) ;
V_423 -> V_429 = V_437 ;
F_251 ( & V_101 -> V_234 . V_438 ) ;
} else {
V_101 = F_23 ( V_8 ) ;
F_252 ( & V_101 -> V_234 . V_438 ) ;
if ( F_253 ( & V_101 -> V_234 ) )
goto V_439;
F_251 ( & V_101 -> V_234 . V_438 ) ;
V_8 = F_250 ( V_8 ) ;
}
V_427:
F_254 (sk, node) {
if ( ! F_255 ( F_19 ( V_8 ) , V_107 ) )
continue;
if ( V_8 -> V_440 == V_423 -> V_242 ) {
V_418 = V_8 ;
goto V_117;
}
V_101 = F_23 ( V_8 ) ;
F_252 ( & V_101 -> V_234 . V_438 ) ;
if ( F_253 ( & V_101 -> V_234 ) ) {
V_439:
V_423 -> V_441 = F_256 ( V_8 ) ;
V_423 -> V_431 = V_8 ;
V_423 -> V_429 = V_430 ;
V_423 -> V_433 = 0 ;
goto V_435;
}
F_251 ( & V_101 -> V_234 . V_438 ) ;
}
F_257 ( & V_421 -> V_309 ) ;
V_423 -> V_205 = 0 ;
if ( ++ V_423 -> V_426 < V_442 ) {
V_421 = & V_111 . V_425 [ V_423 -> V_426 ] ;
F_248 ( & V_421 -> V_309 ) ;
V_8 = F_249 ( & V_421 -> V_159 ) ;
goto V_427;
}
V_418 = NULL ;
V_117:
return V_418 ;
}
static void * F_258 ( struct V_417 * V_105 , T_11 * V_443 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
void * V_444 ;
V_423 -> V_426 = 0 ;
V_423 -> V_205 = 0 ;
V_444 = F_246 ( V_105 , NULL ) ;
while ( V_444 && * V_443 ) {
V_444 = F_246 ( V_105 , V_444 ) ;
-- * V_443 ;
}
return V_444 ;
}
static inline bool F_259 ( const struct V_422 * V_423 )
{
return F_260 ( & V_111 . V_445 [ V_423 -> V_426 ] . V_446 ) ;
}
static void * F_261 ( struct V_417 * V_105 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
void * V_444 = NULL ;
V_423 -> V_205 = 0 ;
for (; V_423 -> V_426 <= V_111 . V_447 ; ++ V_423 -> V_426 ) {
struct V_7 * V_8 ;
struct V_419 * V_260 ;
T_12 * V_309 = F_262 ( & V_111 , V_423 -> V_426 ) ;
if ( F_259 ( V_423 ) )
continue;
F_248 ( V_309 ) ;
F_263 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_440 != V_423 -> V_242 ||
! F_255 ( F_19 ( V_8 ) , V_107 ) ) {
continue;
}
V_444 = V_8 ;
goto V_117;
}
F_257 ( V_309 ) ;
}
V_117:
return V_444 ;
}
static void * F_264 ( struct V_417 * V_105 , void * V_418 )
{
struct V_7 * V_8 = V_418 ;
struct V_419 * V_260 ;
struct V_422 * V_423 = V_105 -> V_424 ;
struct V_107 * V_107 = F_247 ( V_105 ) ;
++ V_423 -> V_428 ;
++ V_423 -> V_205 ;
V_8 = F_250 ( V_8 ) ;
F_254 (sk, node) {
if ( V_8 -> V_440 == V_423 -> V_242 && F_255 ( F_19 ( V_8 ) , V_107 ) )
return V_8 ;
}
F_257 ( F_262 ( & V_111 , V_423 -> V_426 ) ) ;
++ V_423 -> V_426 ;
return F_261 ( V_105 ) ;
}
static void * F_265 ( struct V_417 * V_105 , T_11 V_443 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
void * V_444 ;
V_423 -> V_426 = 0 ;
V_444 = F_261 ( V_105 ) ;
while ( V_444 && V_443 ) {
V_444 = F_264 ( V_105 , V_444 ) ;
-- V_443 ;
}
return V_444 ;
}
static void * F_266 ( struct V_417 * V_105 , T_11 V_443 )
{
void * V_444 ;
struct V_422 * V_423 = V_105 -> V_424 ;
V_423 -> V_429 = V_437 ;
V_444 = F_258 ( V_105 , & V_443 ) ;
if ( ! V_444 ) {
V_423 -> V_429 = V_448 ;
V_444 = F_265 ( V_105 , V_443 ) ;
}
return V_444 ;
}
static void * F_267 ( struct V_417 * V_105 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
int V_205 = V_423 -> V_205 ;
int V_449 = V_423 -> V_428 ;
void * V_444 = NULL ;
switch ( V_423 -> V_429 ) {
case V_430 :
case V_437 :
if ( V_423 -> V_426 >= V_442 )
break;
V_423 -> V_429 = V_437 ;
V_444 = F_246 ( V_105 , NULL ) ;
while ( V_205 -- && V_444 )
V_444 = F_246 ( V_105 , V_444 ) ;
if ( V_444 )
break;
V_423 -> V_426 = 0 ;
V_423 -> V_429 = V_448 ;
case V_448 :
if ( V_423 -> V_426 > V_111 . V_447 )
break;
V_444 = F_261 ( V_105 ) ;
while ( V_205 -- && V_444 )
V_444 = F_264 ( V_105 , V_444 ) ;
}
V_423 -> V_428 = V_449 ;
return V_444 ;
}
static void * F_268 ( struct V_417 * V_105 , T_11 * V_443 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
void * V_444 ;
if ( * V_443 && * V_443 == V_423 -> V_450 ) {
V_444 = F_267 ( V_105 ) ;
if ( V_444 )
goto V_117;
}
V_423 -> V_429 = V_437 ;
V_423 -> V_428 = 0 ;
V_423 -> V_426 = 0 ;
V_423 -> V_205 = 0 ;
V_444 = * V_443 ? F_266 ( V_105 , * V_443 - 1 ) : V_451 ;
V_117:
V_423 -> V_450 = * V_443 ;
return V_444 ;
}
static void * F_269 ( struct V_417 * V_105 , void * V_452 , T_11 * V_443 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
void * V_444 = NULL ;
if ( V_452 == V_451 ) {
V_444 = F_266 ( V_105 , 0 ) ;
goto V_117;
}
switch ( V_423 -> V_429 ) {
case V_430 :
case V_437 :
V_444 = F_246 ( V_105 , V_452 ) ;
if ( ! V_444 ) {
V_423 -> V_429 = V_448 ;
V_423 -> V_426 = 0 ;
V_423 -> V_205 = 0 ;
V_444 = F_261 ( V_105 ) ;
}
break;
case V_448 :
V_444 = F_264 ( V_105 , V_452 ) ;
break;
}
V_117:
++ * V_443 ;
V_423 -> V_450 = * V_443 ;
return V_444 ;
}
static void F_270 ( struct V_417 * V_105 , void * V_452 )
{
struct V_422 * V_423 = V_105 -> V_424 ;
switch ( V_423 -> V_429 ) {
case V_430 :
if ( V_452 ) {
struct V_100 * V_101 = F_23 ( V_423 -> V_431 ) ;
F_251 ( & V_101 -> V_234 . V_438 ) ;
}
case V_437 :
if ( V_452 != V_451 )
F_257 ( & V_111 . V_425 [ V_423 -> V_426 ] . V_309 ) ;
break;
case V_448 :
if ( V_452 )
F_257 ( F_262 ( & V_111 , V_423 -> V_426 ) ) ;
break;
}
}
int F_271 ( struct V_453 * V_453 , struct V_454 * V_454 )
{
struct V_455 * V_456 = F_272 ( V_453 ) ;
struct V_422 * V_457 ;
int V_37 ;
V_37 = F_273 ( V_453 , V_454 , & V_456 -> V_458 ,
sizeof( struct V_422 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_457 = ( (struct V_417 * ) V_454 -> V_459 ) -> V_424 ;
V_457 -> V_242 = V_456 -> V_242 ;
V_457 -> V_450 = 0 ;
return 0 ;
}
int F_274 ( struct V_107 * V_107 , struct V_455 * V_456 )
{
int V_444 = 0 ;
struct V_460 * V_461 ;
V_456 -> V_458 . V_462 = F_268 ;
V_456 -> V_458 . V_463 = F_269 ;
V_456 -> V_458 . V_464 = F_270 ;
V_461 = F_275 ( V_456 -> V_465 , V_466 , V_107 -> V_467 ,
V_456 -> V_468 , V_456 ) ;
if ( ! V_461 )
V_444 = - V_258 ;
return V_444 ;
}
void F_276 ( struct V_107 * V_107 , struct V_455 * V_456 )
{
F_277 ( V_456 -> V_465 , V_107 -> V_467 ) ;
}
static void F_278 ( const struct V_7 * V_8 , const struct V_103 * V_104 ,
struct V_417 * V_469 , int V_470 , T_13 V_441 )
{
const struct V_219 * V_220 = F_94 ( V_104 ) ;
long V_471 = V_104 -> V_311 - V_79 ;
F_279 ( V_469 , L_9
L_10 ,
V_470 ,
V_220 -> V_221 ,
F_80 ( F_11 ( V_8 ) -> V_49 ) ,
V_220 -> V_222 ,
F_80 ( V_220 -> V_472 ) ,
V_151 ,
0 , 0 ,
1 ,
F_280 ( V_471 ) ,
V_104 -> V_323 ,
F_281 ( F_282 ( V_469 ) , V_441 ) ,
0 ,
0 ,
F_283 ( & V_8 -> V_473 ) ,
V_104 ) ;
}
static void F_284 ( struct V_7 * V_8 , struct V_417 * V_469 , int V_470 )
{
int V_474 ;
unsigned long V_475 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_100 * V_101 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_298 * V_299 = V_101 -> V_234 . V_299 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_476 = V_29 -> V_63 ;
T_14 V_477 = F_80 ( V_29 -> V_69 ) ;
T_14 V_478 = F_80 ( V_29 -> V_49 ) ;
int V_479 ;
if ( V_101 -> V_480 == V_145 ||
V_101 -> V_480 == V_481 ||
V_101 -> V_480 == V_482 ) {
V_474 = 1 ;
V_475 = V_101 -> V_483 ;
} else if ( V_101 -> V_480 == V_484 ) {
V_474 = 4 ;
V_475 = V_101 -> V_483 ;
} else if ( F_285 ( & V_8 -> V_485 ) ) {
V_474 = 2 ;
V_475 = V_8 -> V_485 . V_311 ;
} else {
V_474 = 0 ;
V_475 = V_79 ;
}
if ( V_8 -> V_112 == V_122 )
V_479 = V_8 -> V_486 ;
else
V_479 = F_286 ( int , V_14 -> V_215 - V_14 -> V_487 , 0 ) ;
F_279 ( V_469 , L_11
L_12 ,
V_470 , V_476 , V_478 , V_5 , V_477 , V_8 -> V_112 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_479 ,
V_474 ,
F_280 ( V_475 - V_79 ) ,
V_101 -> V_138 ,
F_281 ( F_282 ( V_469 ) , F_256 ( V_8 ) ) ,
V_101 -> V_488 ,
F_287 ( V_8 ) ,
F_283 ( & V_8 -> V_473 ) , V_8 ,
F_288 ( V_101 -> V_140 ) ,
F_288 ( V_101 -> V_489 . V_490 ) ,
( V_101 -> V_489 . V_491 << 1 ) | V_101 -> V_489 . V_492 ,
V_14 -> V_493 ,
V_8 -> V_112 == V_122 ?
( V_299 ? V_299 -> V_306 : 0 ) :
( F_289 ( V_14 ) ? - 1 : V_14 -> V_494 ) ) ;
}
static void F_290 ( const struct V_206 * V_207 ,
struct V_417 * V_469 , int V_470 )
{
T_3 V_5 , V_476 ;
T_14 V_477 , V_478 ;
long V_471 = V_207 -> V_495 - V_79 ;
V_5 = V_207 -> V_496 ;
V_476 = V_207 -> V_497 ;
V_477 = F_80 ( V_207 -> V_498 ) ;
V_478 = F_80 ( V_207 -> V_499 ) ;
F_279 ( V_469 , L_9
L_13 ,
V_470 , V_476 , V_478 , V_5 , V_477 , V_207 -> V_500 , 0 , 0 ,
3 , F_280 ( V_471 ) , 0 , 0 , 0 , 0 ,
F_283 ( & V_207 -> V_501 ) , V_207 ) ;
}
static int F_291 ( struct V_417 * V_105 , void * V_452 )
{
struct V_422 * V_423 ;
struct V_7 * V_8 = V_452 ;
F_292 ( V_105 , V_502 - 1 ) ;
if ( V_452 == V_451 ) {
F_293 ( V_105 , L_14
L_15
L_16 ) ;
goto V_117;
}
V_423 = V_105 -> V_424 ;
switch ( V_423 -> V_429 ) {
case V_437 :
case V_448 :
if ( V_8 -> V_112 == V_113 )
F_290 ( V_452 , V_105 , V_423 -> V_428 ) ;
else
F_284 ( V_452 , V_105 , V_423 -> V_428 ) ;
break;
case V_430 :
F_278 ( V_423 -> V_431 , V_452 , V_105 , V_423 -> V_428 , V_423 -> V_441 ) ;
break;
}
V_117:
F_294 ( V_105 , '\n' ) ;
return 0 ;
}
static int T_15 F_295 ( struct V_107 * V_107 )
{
return F_274 ( V_107 , & V_503 ) ;
}
static void T_16 F_296 ( struct V_107 * V_107 )
{
F_276 ( V_107 , & V_503 ) ;
}
int T_17 F_297 ( void )
{
return F_298 ( & V_504 ) ;
}
void F_299 ( void )
{
F_300 ( & V_504 ) ;
}
static int T_15 F_301 ( struct V_107 * V_107 )
{
V_107 -> V_505 . V_506 = 2 ;
return 0 ;
}
static void T_16 F_302 ( struct V_107 * V_107 )
{
}
static void T_16 F_303 ( struct V_507 * V_508 )
{
F_304 ( & V_111 , & V_66 , V_42 ) ;
}
void T_17 F_305 ( void )
{
F_306 ( & V_111 ) ;
if ( F_298 ( & V_509 ) )
F_307 ( L_17 ) ;
}
