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
static int F_10 ( struct V_7 * V_8 )
{
F_11 ( V_8 ) ;
F_12 ( V_8 , NULL ) ;
return 0 ;
}
int F_13 ( struct V_7 * V_8 , struct V_23 * V_24 , int V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_24 ;
struct V_28 * V_29 = F_14 ( V_8 ) ;
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
V_39 = F_15 ( V_29 -> V_39 ,
F_16 ( V_8 ) ) ;
if ( V_39 && V_39 -> V_46 . V_47 ) {
if ( ! V_3 )
return - V_40 ;
V_32 = V_39 -> V_46 . V_48 ;
}
V_30 = V_29 -> V_49 ;
V_31 = V_27 -> V_50 ;
V_34 = & V_29 -> V_51 . V_52 . V_53 . V_54 ;
V_36 = F_17 ( V_34 , V_32 , V_29 -> V_55 ,
F_18 ( V_8 ) , V_8 -> V_56 ,
V_57 ,
V_30 , V_31 , V_8 , true ) ;
if ( F_19 ( V_36 ) ) {
V_37 = F_20 ( V_36 ) ;
if ( V_37 == - V_58 )
F_21 ( F_22 ( V_8 ) , V_59 ) ;
return V_37 ;
}
if ( V_36 -> V_60 & ( V_61 | V_62 ) ) {
F_23 ( V_36 ) ;
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
if ( F_24 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = 0 ;
}
if ( V_66 . V_67 &&
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 ) {
struct V_68 * V_69 = F_25 ( V_36 , V_34 -> V_3 ) ;
if ( V_69 ) {
F_26 ( V_69 ) ;
if ( ( V_70 ) F_8 () - V_69 -> V_71 <= V_72 ) {
V_14 -> V_19 . V_22 = V_69 -> V_71 ;
V_14 -> V_19 . V_20 = V_69 -> V_73 ;
}
}
}
V_29 -> V_74 = V_27 -> V_50 ;
V_29 -> V_64 = V_3 ;
F_27 ( V_8 ) -> V_75 = 0 ;
if ( V_39 )
F_27 ( V_8 ) -> V_75 = V_39 -> V_46 . V_76 ;
V_14 -> V_19 . V_77 = V_78 ;
F_28 ( V_8 , V_79 ) ;
V_37 = F_29 ( & V_66 , V_8 ) ;
if ( V_37 )
goto V_80;
V_36 = F_30 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_74 , V_8 ) ;
if ( F_19 ( V_36 ) ) {
V_37 = F_20 ( V_36 ) ;
V_36 = NULL ;
goto V_80;
}
V_8 -> V_81 = V_82 ;
F_31 ( V_8 , & V_36 -> V_83 ) ;
if ( ! V_14 -> V_17 && F_24 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_64 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_84 = V_14 -> V_17 ^ V_85 ;
if ( F_24 ( ! V_14 -> V_65 ) )
V_37 = F_32 ( V_8 ) ;
else
V_37 = F_10 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_80;
return 0 ;
V_80:
F_28 ( V_8 , V_86 ) ;
F_23 ( V_36 ) ;
V_8 -> V_87 = 0 ;
V_29 -> V_74 = 0 ;
return V_37 ;
}
static void F_33 ( struct V_7 * V_8 , const struct V_88 * V_89 , V_70 V_90 )
{
struct V_91 * V_83 ;
struct V_28 * V_29 = F_14 ( V_8 ) ;
if ( V_8 -> V_92 == V_93 )
return;
if ( ( V_83 = F_34 ( V_8 , 0 ) ) == NULL )
return;
V_83 -> V_94 -> V_95 ( V_83 , V_90 ) ;
if ( V_90 < F_35 ( V_83 ) && F_36 ( V_8 , V_83 ) )
V_8 -> V_96 = V_97 ;
V_90 = F_35 ( V_83 ) ;
if ( V_29 -> V_98 != V_99 &&
F_27 ( V_8 ) -> V_100 > V_90 ) {
F_37 ( V_8 , V_90 ) ;
F_38 ( V_8 ) ;
}
}
void F_39 ( struct V_1 * V_101 , V_70 V_102 )
{
const struct V_88 * V_89 = ( const struct V_88 * ) V_101 -> V_103 ;
struct V_104 * V_105 = (struct V_104 * ) ( V_101 -> V_103 + ( V_89 -> V_106 << 2 ) ) ;
struct V_107 * V_108 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_40 ( V_101 ) -> type ;
const int V_109 = F_40 ( V_101 ) -> V_109 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
T_1 V_110 ;
T_1 V_111 ;
int V_37 ;
struct V_112 * V_112 = F_41 ( V_101 -> V_113 ) ;
if ( V_101 -> V_114 < ( V_89 -> V_106 << 2 ) + 8 ) {
F_42 ( V_112 , V_115 ) ;
return;
}
V_8 = F_43 ( V_112 , & V_116 , V_89 -> V_3 , V_105 -> V_5 ,
V_89 -> V_4 , V_105 -> V_6 , F_44 ( V_101 ) ) ;
if ( ! V_8 ) {
F_42 ( V_112 , V_115 ) ;
return;
}
if ( V_8 -> V_92 == V_117 ) {
F_45 ( F_46 ( V_8 ) ) ;
return;
}
F_47 ( V_8 ) ;
if ( F_16 ( V_8 ) )
F_48 ( V_112 , V_118 ) ;
if ( V_8 -> V_92 == V_86 )
goto V_119;
if ( F_49 ( V_89 -> V_120 < F_14 ( V_8 ) -> V_121 ) ) {
F_48 ( V_112 , V_122 ) ;
goto V_119;
}
V_108 = F_27 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_110 = F_50 ( V_105 -> V_110 ) ;
if ( V_8 -> V_92 != V_93 &&
! F_51 ( V_110 , V_14 -> V_123 , V_14 -> V_124 ) ) {
F_48 ( V_112 , V_125 ) ;
goto V_119;
}
switch ( type ) {
case V_126 :
goto V_119;
case V_127 :
V_37 = V_128 ;
break;
case V_129 :
if ( V_109 > V_130 )
goto V_119;
if ( V_109 == V_131 ) {
if ( ! F_16 ( V_8 ) )
F_33 ( V_8 , V_89 , V_102 ) ;
goto V_119;
}
V_37 = V_132 [ V_109 ] . V_133 ;
if ( V_109 != V_134 && V_109 != V_135 )
break;
if ( V_110 != V_14 -> V_123 || ! V_108 -> V_136 ||
! V_108 -> V_137 )
break;
if ( F_16 ( V_8 ) )
break;
V_108 -> V_137 -- ;
F_27 ( V_8 ) -> V_138 = ( V_14 -> V_139 ? F_52 ( V_14 ) :
V_140 ) << V_108 -> V_137 ;
F_53 ( V_8 ) ;
V_2 = F_54 ( V_8 ) ;
F_55 ( ! V_2 ) ;
V_111 = V_108 -> V_138 - F_56 ( V_108 -> V_138 ,
V_141 - F_57 ( V_2 ) -> V_142 ) ;
if ( V_111 ) {
F_58 ( V_8 , V_143 ,
V_111 , V_144 ) ;
} else {
F_59 ( V_8 ) ;
}
break;
case V_145 :
V_37 = V_146 ;
break;
default:
goto V_119;
}
switch ( V_8 -> V_92 ) {
struct V_147 * V_148 , * * V_149 ;
case V_93 :
if ( F_16 ( V_8 ) )
goto V_119;
V_148 = F_60 ( V_8 , & V_149 , V_105 -> V_5 ,
V_89 -> V_3 , V_89 -> V_4 ) ;
if ( ! V_148 )
goto V_119;
F_61 ( V_148 -> V_8 ) ;
if ( V_110 != F_62 ( V_148 ) -> V_150 ) {
F_48 ( V_112 , V_125 ) ;
goto V_119;
}
F_63 ( V_8 , V_148 , V_149 ) ;
goto V_119;
case V_79 :
case V_151 :
if ( ! F_16 ( V_8 ) ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
F_64 ( V_8 ) ;
} else {
V_8 -> V_96 = V_37 ;
}
goto V_119;
}
V_29 = F_14 ( V_8 ) ;
if ( ! F_16 ( V_8 ) && V_29 -> V_154 ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
} else {
V_8 -> V_96 = V_37 ;
}
V_119:
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
}
static void F_67 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_104 * V_105 = F_4 ( V_2 ) ;
if ( V_2 -> V_155 == V_156 ) {
V_105 -> V_157 = ~ F_68 ( V_2 -> V_114 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_69 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_70 ( struct V_104 , V_157 ) ;
} else {
V_105 -> V_157 = F_68 ( V_2 -> V_114 , V_4 , V_3 ,
F_71 ( V_105 ,
V_105 -> V_161 << 2 ,
V_2 -> V_162 ) ) ;
}
}
void F_72 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_14 ( V_8 ) ;
F_67 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
const struct V_88 * V_89 ;
struct V_104 * V_105 ;
if ( ! F_74 ( V_2 , sizeof( * V_105 ) ) )
return - V_40 ;
V_89 = F_3 ( V_2 ) ;
V_105 = F_4 ( V_2 ) ;
V_105 -> V_157 = 0 ;
V_2 -> V_155 = V_156 ;
F_67 ( V_2 , V_89 -> V_4 , V_89 -> V_3 ) ;
return 0 ;
}
static void F_75 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
#ifdef F_76
T_3 V_46 [ ( V_163 >> 2 ) ] ;
#endif
} V_164 ;
struct V_165 V_166 ;
#ifdef F_76
struct V_167 * V_168 ;
const T_4 * V_169 = NULL ;
unsigned char V_170 [ 16 ] ;
int V_171 ;
struct V_7 * V_172 = NULL ;
#endif
struct V_112 * V_112 ;
if ( V_105 -> V_173 )
return;
if ( F_77 ( V_2 ) -> V_174 != V_175 )
return;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = sizeof( struct V_104 ) / 4 ;
V_164 . V_105 . V_173 = 1 ;
if ( V_105 -> V_176 ) {
V_164 . V_105 . V_110 = V_105 -> V_177 ;
} else {
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_177 = F_78 ( F_50 ( V_105 -> V_110 ) + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_114 - ( V_105 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
#ifdef F_76
V_169 = F_79 ( V_105 ) ;
if ( ! V_8 && V_169 ) {
V_172 = F_80 ( F_41 ( F_81 ( V_2 ) -> V_113 ) ,
& V_116 , F_3 ( V_2 ) -> V_3 ,
F_82 ( V_105 -> V_6 ) , F_44 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_83 () ;
V_168 = F_84 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_85 ( V_170 , V_168 , NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
} else {
V_168 = V_8 ? F_84 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_78 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_86 ( ( T_4 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_162 = F_87 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_70 ( struct V_104 , V_157 ) / 2 ;
V_166 . V_189 = ( V_8 && F_14 ( V_8 ) -> V_190 ) ? V_191 : 0 ;
V_166 . V_192 = V_8 ? V_8 -> V_56 : F_44 ( V_2 ) ;
V_112 = F_41 ( F_81 ( V_2 ) -> V_113 ) ;
V_166 . V_193 = F_3 ( V_2 ) -> V_193 ;
F_88 ( V_112 -> V_194 . V_13 , V_2 , F_3 ( V_2 ) -> V_4 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_89 ( V_112 , V_195 ) ;
F_89 ( V_112 , V_196 ) ;
#ifdef F_76
V_184:
if ( V_172 ) {
F_90 () ;
F_66 ( V_172 ) ;
}
#endif
}
static void F_91 ( struct V_1 * V_2 , V_70 V_110 , V_70 V_176 ,
V_70 V_197 , V_70 V_198 , int V_199 ,
struct V_167 * V_168 ,
int V_200 , T_5 V_193 )
{
const struct V_104 * V_105 = F_4 ( V_2 ) ;
struct {
struct V_104 V_105 ;
T_3 V_46 [ ( V_201 >> 2 )
#ifdef F_76
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
struct V_112 * V_112 = F_41 ( F_81 ( V_2 ) -> V_113 ) ;
memset ( & V_164 . V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_105 ) ;
if ( V_198 ) {
V_164 . V_46 [ 0 ] = F_78 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_202 << 8 ) |
V_203 ) ;
V_164 . V_46 [ 1 ] = F_78 ( V_141 ) ;
V_164 . V_46 [ 2 ] = F_78 ( V_198 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_201 ;
}
V_164 . V_105 . V_5 = V_105 -> V_6 ;
V_164 . V_105 . V_6 = V_105 -> V_5 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_105 . V_110 = F_78 ( V_110 ) ;
V_164 . V_105 . V_177 = F_78 ( V_176 ) ;
V_164 . V_105 . V_176 = 1 ;
V_164 . V_105 . V_204 = F_92 ( V_197 ) ;
#ifdef F_76
if ( V_168 ) {
int V_205 = ( V_198 ) ? 3 : 0 ;
V_164 . V_46 [ V_205 ++ ] = F_78 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_105 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_86 ( ( T_4 * ) & V_164 . V_46 [ V_205 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_105 ) ;
}
#endif
V_166 . V_189 = V_200 ;
V_166 . V_162 = F_87 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_70 ( struct V_104 , V_157 ) / 2 ;
if ( V_199 )
V_166 . V_192 = V_199 ;
V_166 . V_193 = V_193 ;
F_88 ( V_112 -> V_194 . V_13 , V_2 , F_3 ( V_2 ) -> V_4 ,
& V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_89 ( V_112 , V_195 ) ;
}
static void F_93 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_206 * V_207 = F_46 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_91 ( V_2 , V_12 -> V_18 , V_12 -> V_208 ,
V_12 -> V_209 >> V_207 -> V_210 ,
V_12 -> V_21 ,
V_207 -> V_211 ,
F_94 ( V_12 ) ,
V_207 -> V_212 ? V_191 : 0 ,
V_207 -> V_213
) ;
F_45 ( V_207 ) ;
}
static void F_95 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_147 * V_148 )
{
F_91 ( V_2 , F_62 ( V_148 ) -> V_150 + 1 ,
F_62 ( V_148 ) -> V_214 + 1 , V_148 -> V_215 ,
V_148 -> V_20 ,
0 ,
F_84 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_96 ( V_148 ) -> V_216 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_193 ) ;
}
static int F_97 ( struct V_7 * V_8 , struct V_91 * V_83 ,
struct V_147 * V_148 ,
struct V_217 * V_218 ,
T_6 V_219 )
{
const struct V_220 * V_221 = F_96 ( V_148 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_83 && ( V_83 = F_98 ( V_8 , & V_34 , V_148 ) ) == NULL )
return - 1 ;
V_2 = F_99 ( V_8 , V_83 , V_148 , V_218 ) ;
if ( V_2 ) {
F_67 ( V_2 , V_221 -> V_222 , V_221 -> V_223 ) ;
F_100 ( V_2 , V_219 ) ;
V_37 = F_101 ( V_2 , V_8 , V_221 -> V_222 ,
V_221 -> V_223 ,
V_221 -> V_46 ) ;
V_37 = F_102 ( V_37 ) ;
}
F_103 ( V_83 ) ;
return V_37 ;
}
static int F_104 ( struct V_7 * V_8 , struct V_147 * V_148 ,
struct V_217 * V_218 )
{
F_89 ( F_22 ( V_8 ) , V_224 ) ;
return F_97 ( V_8 , NULL , V_148 , V_218 , 0 ) ;
}
static void F_105 ( struct V_147 * V_148 )
{
F_106 ( F_96 ( V_148 ) -> V_46 ) ;
}
bool F_107 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_225 )
{
const char * V_226 = L_1 ;
bool V_227 = false ;
struct V_228 * V_229 ;
#ifdef F_108
if ( V_230 ) {
V_226 = L_2 ;
V_227 = true ;
F_48 ( F_22 ( V_8 ) , V_231 ) ;
} else
#endif
F_48 ( F_22 ( V_8 ) , V_232 ) ;
V_229 = F_27 ( V_8 ) -> V_233 . V_234 ;
if ( ! V_229 -> V_235 ) {
V_229 -> V_235 = 1 ;
F_109 ( L_3 ,
V_225 , F_82 ( F_4 ( V_2 ) -> V_5 ) , V_226 ) ;
}
return V_227 ;
}
static struct V_38 * F_110 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
const struct V_236 * V_46 = & ( F_111 ( V_2 ) -> V_46 ) ;
struct V_38 * V_237 = NULL ;
if ( V_46 && V_46 -> V_76 ) {
int V_238 = sizeof( * V_237 ) + V_46 -> V_76 ;
V_237 = F_112 ( V_238 , V_239 ) ;
if ( V_237 ) {
if ( F_113 ( & V_237 -> V_46 , V_2 ) ) {
F_106 ( V_237 ) ;
V_237 = NULL ;
}
}
}
return V_237 ;
}
struct V_167 * F_84 ( struct V_7 * V_8 ,
const union V_183 * V_240 ,
int V_241 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_242 * V_243 ;
unsigned int V_244 = sizeof( struct V_245 ) ;
struct V_246 * V_247 ;
V_247 = F_114 ( V_14 -> V_248 ,
F_16 ( V_8 ) ||
F_115 ( & V_8 -> V_249 . V_250 ) ) ;
if ( ! V_247 )
return NULL ;
#if F_116 ( V_251 )
if ( V_241 == V_252 )
V_244 = sizeof( struct V_253 ) ;
#endif
F_117 (key, pos, &md5sig->head, node) {
if ( V_168 -> V_241 != V_241 )
continue;
if ( ! memcmp ( & V_168 -> V_240 , V_240 , V_244 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_118 ( struct V_7 * V_8 ,
struct V_7 * V_254 )
{
union V_183 * V_240 ;
V_240 = (union V_183 * ) & F_14 ( V_254 ) -> V_64 ;
return F_84 ( V_8 , V_240 , V_42 ) ;
}
static struct V_167 * F_119 ( struct V_7 * V_8 ,
struct V_147 * V_148 )
{
union V_183 * V_240 ;
V_240 = (union V_183 * ) & F_96 ( V_148 ) -> V_223 ;
return F_84 ( V_8 , V_240 , V_42 ) ;
}
int F_120 ( struct V_7 * V_8 , const union V_183 * V_240 ,
int V_241 , const T_5 * V_255 , T_5 V_256 , T_7 V_257 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_246 * V_247 ;
V_168 = F_84 ( V_8 , (union V_183 * ) & V_240 , V_42 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_255 , V_256 ) ;
V_168 -> V_258 = V_256 ;
return 0 ;
}
V_247 = F_15 ( V_14 -> V_248 ,
F_16 ( V_8 ) ) ;
if ( ! V_247 ) {
V_247 = F_112 ( sizeof( * V_247 ) , V_257 ) ;
if ( ! V_247 )
return - V_259 ;
F_121 ( V_8 , V_260 ) ;
F_122 ( & V_247 -> V_159 ) ;
F_123 ( V_14 -> V_248 , V_247 ) ;
}
V_168 = F_124 ( V_8 , sizeof( * V_168 ) , V_257 ) ;
if ( ! V_168 )
return - V_259 ;
if ( F_125 ( & V_247 -> V_159 ) && ! F_126 ( V_8 ) ) {
F_127 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_259 ;
}
memcpy ( V_168 -> V_168 , V_255 , V_256 ) ;
V_168 -> V_258 = V_256 ;
V_168 -> V_241 = V_241 ;
memcpy ( & V_168 -> V_240 , V_240 ,
( V_241 == V_252 ) ? sizeof( struct V_253 ) :
sizeof( struct V_245 ) ) ;
F_128 ( & V_168 -> V_261 , & V_247 -> V_159 ) ;
return 0 ;
}
int F_129 ( struct V_7 * V_8 , const union V_183 * V_240 , int V_241 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_246 * V_247 ;
V_168 = F_84 ( V_8 , (union V_183 * ) & V_240 , V_42 ) ;
if ( ! V_168 )
return - V_262 ;
F_130 ( & V_168 -> V_261 ) ;
F_131 ( sizeof( * V_168 ) , & V_8 -> V_263 ) ;
F_132 ( V_168 , V_264 ) ;
V_247 = F_15 ( V_14 -> V_248 ,
F_16 ( V_8 ) ) ;
if ( F_125 ( & V_247 -> V_159 ) )
F_133 () ;
return 0 ;
}
void F_134 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_242 * V_243 , * V_265 ;
struct V_246 * V_247 ;
V_247 = F_15 ( V_14 -> V_248 , 1 ) ;
if ( ! F_125 ( & V_247 -> V_159 ) )
F_133 () ;
F_135 (key, pos, n, &md5sig->head, node) {
F_130 ( & V_168 -> V_261 ) ;
F_131 ( sizeof( * V_168 ) , & V_8 -> V_263 ) ;
F_132 ( V_168 , V_264 ) ;
}
}
static int F_136 ( struct V_7 * V_8 , char T_8 * V_266 ,
int V_76 )
{
struct V_267 V_268 ;
struct V_26 * sin = (struct V_26 * ) & V_268 . V_269 ;
if ( V_76 < sizeof( V_268 ) )
return - V_40 ;
if ( F_137 ( & V_268 , V_266 , sizeof( V_268 ) ) )
return - V_270 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_268 . V_271 || ! V_268 . V_272 )
return F_129 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_268 . V_272 > V_273 )
return - V_40 ;
return F_120 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_268 . V_271 , V_268 . V_272 ,
V_274 ) ;
}
static int F_138 ( struct V_275 * V_276 ,
T_3 V_3 , T_3 V_4 , int V_277 )
{
struct V_278 * V_279 ;
struct V_280 V_281 ;
V_279 = & V_276 -> V_282 . V_54 ;
V_279 -> V_4 = V_4 ;
V_279 -> V_3 = V_3 ;
V_279 -> V_283 = 0 ;
V_279 -> V_284 = V_57 ;
V_279 -> V_114 = F_139 ( V_277 ) ;
F_140 ( & V_281 , V_279 , sizeof( * V_279 ) ) ;
return F_141 ( & V_276 -> V_285 , & V_281 , sizeof( * V_279 ) ) ;
}
static int F_86 ( char * V_286 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_104 * V_105 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
V_276 = F_142 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_143 ( V_288 ) )
goto V_290;
if ( F_138 ( V_276 , V_3 , V_4 , V_105 -> V_161 << 2 ) )
goto V_290;
if ( F_144 ( V_276 , V_105 ) )
goto V_290;
if ( F_145 ( V_276 , V_168 ) )
goto V_290;
if ( F_146 ( V_288 , V_286 ) )
goto V_290;
F_147 () ;
return 0 ;
V_290:
F_147 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
int F_85 ( char * V_286 , struct V_167 * V_168 ,
const struct V_7 * V_8 , const struct V_147 * V_148 ,
const struct V_1 * V_2 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_14 ( V_8 ) -> V_55 ;
V_3 = F_14 ( V_8 ) -> V_64 ;
} else if ( V_148 ) {
V_4 = F_96 ( V_148 ) -> V_222 ;
V_3 = F_96 ( V_148 ) -> V_223 ;
} else {
const struct V_88 * V_89 = F_3 ( V_2 ) ;
V_4 = V_89 -> V_4 ;
V_3 = V_89 -> V_3 ;
}
V_276 = F_142 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_143 ( V_288 ) )
goto V_290;
if ( F_138 ( V_276 , V_3 , V_4 , V_2 -> V_114 ) )
goto V_290;
if ( F_144 ( V_276 , V_105 ) )
goto V_290;
if ( F_148 ( V_276 , V_2 , V_105 -> V_161 << 2 ) )
goto V_290;
if ( F_145 ( V_276 , V_168 ) )
goto V_290;
if ( F_146 ( V_288 , V_286 ) )
goto V_290;
F_147 () ;
return 0 ;
V_290:
F_147 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
static bool F_149 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_4 * V_169 = NULL ;
struct V_167 * V_291 ;
const struct V_88 * V_89 = F_3 ( V_2 ) ;
const struct V_104 * V_105 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_291 = F_84 ( V_8 , (union V_183 * ) & V_89 -> V_4 ,
V_42 ) ;
V_169 = F_79 ( V_105 ) ;
if ( ! V_291 && ! V_169 )
return false ;
if ( V_291 && ! V_169 ) {
F_48 ( F_22 ( V_8 ) , V_292 ) ;
return true ;
}
if ( ! V_291 && V_169 ) {
F_48 ( F_22 ( V_8 ) , V_293 ) ;
return true ;
}
V_171 = F_85 ( V_170 ,
V_291 ,
NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_150 ( L_4 ,
& V_89 -> V_4 , F_82 ( V_105 -> V_6 ) ,
& V_89 -> V_3 , F_82 ( V_105 -> V_5 ) ,
V_171 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
int F_151 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_294 V_295 ;
struct V_296 V_297 ;
const T_5 * V_169 ;
struct V_147 * V_148 ;
struct V_220 * V_221 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_91 * V_83 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_298 = F_57 ( V_2 ) -> V_142 ;
bool V_227 = false ;
if ( F_77 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_299;
if ( F_152 ( V_8 ) && ! V_298 ) {
V_227 = F_107 ( V_8 , V_2 , L_7 ) ;
if ( ! V_227 )
goto V_299;
}
if ( F_153 ( V_8 ) && F_154 ( V_8 ) > 1 )
goto V_299;
V_148 = F_155 ( & V_300 ) ;
if ( ! V_148 )
goto V_299;
#ifdef F_76
F_62 ( V_148 ) -> V_301 = & V_302 ;
#endif
F_156 ( & V_297 ) ;
V_297 . V_77 = V_78 ;
V_297 . V_303 = V_14 -> V_19 . V_303 ;
F_157 ( V_2 , & V_297 , & V_169 , 0 ) ;
if ( V_297 . V_304 > 0 &&
V_297 . V_305 &&
! V_14 -> V_19 . V_306 &&
( V_307 > 0 ||
( V_14 -> V_308 != NULL &&
V_14 -> V_308 -> V_309 > 0 ) ) ) {
T_5 * V_310 ;
V_70 * V_311 = & V_295 . V_312 [ V_313 ] ;
int V_314 = V_297 . V_304 - V_315 ;
if ( F_158 ( & V_295 . V_312 [ 0 ] ) != 0 )
goto V_316;
* V_311 ++ ^= ( V_317 V_70 ) V_3 ;
* V_311 ++ ^= ( V_317 V_70 ) V_4 ;
V_310 = ( T_5 * ) V_311 ;
while ( V_314 -- > 0 )
* V_310 ++ ^= * V_169 ++ ;
V_227 = false ;
V_295 . V_306 = 0 ;
V_295 . V_304 = V_297 . V_304 ;
} else if ( ! V_14 -> V_19 . V_318 ) {
V_295 . V_306 = 1 ;
V_295 . V_304 = 0 ;
} else {
goto V_316;
}
V_295 . V_318 = V_14 -> V_19 . V_318 ;
if ( V_227 && ! V_297 . V_305 )
F_156 ( & V_297 ) ;
V_297 . V_319 = V_297 . V_305 ;
F_159 ( V_148 , & V_297 , V_2 ) ;
V_221 = F_96 ( V_148 ) ;
V_221 -> V_222 = V_3 ;
V_221 -> V_223 = V_4 ;
V_221 -> V_216 = F_14 ( V_8 ) -> V_190 ;
V_221 -> V_46 = F_110 ( V_8 , V_2 ) ;
if ( F_160 ( V_8 , V_2 , V_148 ) )
goto V_320;
if ( ! V_227 || V_297 . V_319 )
F_161 ( V_148 , V_2 ) ;
if ( V_227 ) {
V_298 = F_162 ( V_8 , V_2 , & V_148 -> V_321 ) ;
V_148 -> V_322 = V_297 . V_319 ;
} else if ( ! V_298 ) {
struct V_68 * V_69 = NULL ;
struct V_33 V_34 ;
if ( V_297 . V_305 &&
V_66 . V_67 &&
( V_83 = F_98 ( V_8 , & V_34 , V_148 ) ) != NULL &&
V_34 . V_3 == V_4 &&
( V_69 = F_25 ( (struct V_35 * ) V_83 , V_34 . V_3 ) ) != NULL ) {
F_26 ( V_69 ) ;
if ( ( V_70 ) F_8 () - V_69 -> V_71 < V_72 &&
( V_323 ) ( V_69 -> V_73 - V_148 -> V_20 ) >
V_324 ) {
F_48 ( F_22 ( V_8 ) , V_325 ) ;
goto V_316;
}
}
else if ( ! V_230 &&
( V_326 - F_163 ( V_8 ) <
( V_326 >> 2 ) ) &&
( ! V_69 || ! V_69 -> V_71 ) &&
( ! V_83 || ! F_164 ( V_83 , V_327 ) ) ) {
F_165 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_316;
}
V_298 = F_1 ( V_2 ) ;
}
F_62 ( V_148 ) -> V_150 = V_298 ;
F_62 ( V_148 ) -> V_328 = V_141 ;
if ( F_97 ( V_8 , V_83 , V_148 ,
(struct V_217 * ) & V_295 ,
F_166 ( V_2 ) ) ||
V_227 )
goto V_320;
F_167 ( V_8 , V_148 , V_140 ) ;
return 0 ;
V_316:
F_103 ( V_83 ) ;
V_320:
F_168 ( V_148 ) ;
V_299:
return 0 ;
}
struct V_7 * F_169 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_147 * V_148 ,
struct V_91 * V_83 )
{
struct V_220 * V_221 ;
struct V_28 * V_329 ;
struct V_13 * V_330 ;
struct V_7 * V_331 ;
#ifdef F_76
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_153 ( V_8 ) )
goto V_332;
V_331 = F_170 ( V_8 , V_148 , V_2 ) ;
if ( ! V_331 )
goto V_333;
V_331 -> V_81 = V_82 ;
V_330 = F_7 ( V_331 ) ;
V_329 = F_14 ( V_331 ) ;
V_221 = F_96 ( V_148 ) ;
V_329 -> V_64 = V_221 -> V_223 ;
V_329 -> V_63 = V_221 -> V_222 ;
V_329 -> V_55 = V_221 -> V_222 ;
V_39 = V_221 -> V_46 ;
F_123 ( V_329 -> V_39 , V_39 ) ;
V_221 -> V_46 = NULL ;
V_329 -> V_334 = F_44 ( V_2 ) ;
V_329 -> V_335 = F_3 ( V_2 ) -> V_120 ;
V_329 -> V_336 = F_3 ( V_2 ) -> V_193 ;
F_27 ( V_331 ) -> V_75 = 0 ;
if ( V_39 )
F_27 ( V_331 ) -> V_75 = V_39 -> V_46 . V_76 ;
V_329 -> V_84 = V_330 -> V_17 ^ V_85 ;
if ( ! V_83 ) {
V_83 = F_171 ( V_8 , V_331 , V_148 ) ;
if ( ! V_83 )
goto V_337;
} else {
}
F_31 ( V_331 , V_83 ) ;
F_172 ( V_331 ) ;
F_37 ( V_331 , F_35 ( V_83 ) ) ;
V_330 -> V_338 = F_173 ( V_83 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_303 &&
F_7 ( V_8 ) -> V_19 . V_303 < V_330 -> V_338 )
V_330 -> V_338 = F_7 ( V_8 ) -> V_19 . V_303 ;
F_174 ( V_331 ) ;
if ( F_62 ( V_148 ) -> V_328 )
F_175 ( V_331 ,
V_141 - F_62 ( V_148 ) -> V_328 ) ;
V_330 -> V_339 = V_148 -> V_340 ;
#ifdef F_76
V_168 = F_84 ( V_8 , (union V_183 * ) & V_329 -> V_64 ,
V_42 ) ;
if ( V_168 != NULL ) {
F_120 ( V_331 , (union V_183 * ) & V_329 -> V_64 ,
V_42 , V_168 -> V_168 , V_168 -> V_258 , V_239 ) ;
F_121 ( V_331 , V_260 ) ;
}
#endif
if ( F_176 ( V_8 , V_331 ) < 0 )
goto V_337;
F_177 ( V_331 , NULL ) ;
return V_331 ;
V_332:
F_48 ( F_22 ( V_8 ) , V_341 ) ;
V_333:
F_103 ( V_83 ) ;
exit:
F_48 ( F_22 ( V_8 ) , V_342 ) ;
return NULL ;
V_337:
F_178 ( V_331 ) ;
F_179 ( V_331 ) ;
F_65 ( V_331 ) ;
F_66 ( V_331 ) ;
goto exit;
}
static struct V_7 * F_180 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_104 * V_105 = F_4 ( V_2 ) ;
const struct V_88 * V_89 = F_3 ( V_2 ) ;
struct V_7 * V_343 ;
struct V_147 * * V_149 ;
struct V_147 * V_148 = F_60 ( V_8 , & V_149 , V_105 -> V_6 ,
V_89 -> V_4 , V_89 -> V_3 ) ;
if ( V_148 )
return F_181 ( V_8 , V_2 , V_148 , V_149 ) ;
V_343 = F_182 ( F_22 ( V_8 ) , & V_116 , V_89 -> V_4 ,
V_105 -> V_6 , V_89 -> V_3 , V_105 -> V_5 , F_44 ( V_2 ) ) ;
if ( V_343 ) {
if ( V_343 -> V_92 != V_117 ) {
F_47 ( V_343 ) ;
return V_343 ;
}
F_45 ( F_46 ( V_343 ) ) ;
return NULL ;
}
#ifdef F_108
if ( ! V_105 -> V_178 )
V_8 = F_183 ( V_8 , V_2 , & ( F_111 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_9 F_184 ( struct V_1 * V_2 )
{
const struct V_88 * V_89 = F_3 ( V_2 ) ;
if ( V_2 -> V_155 == V_344 ) {
if ( ! F_68 ( V_2 -> V_114 , V_89 -> V_4 ,
V_89 -> V_3 , V_2 -> V_162 ) ) {
V_2 -> V_155 = V_345 ;
return 0 ;
}
}
V_2 -> V_162 = F_87 ( V_89 -> V_4 , V_89 -> V_3 ,
V_2 -> V_114 , V_57 , 0 ) ;
if ( V_2 -> V_114 <= 76 ) {
return F_185 ( V_2 ) ;
}
return 0 ;
}
int F_186 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_346 ;
#ifdef F_76
if ( F_149 ( V_8 , V_2 ) )
goto V_347;
#endif
if ( V_8 -> V_92 == V_348 ) {
F_187 ( V_8 , V_2 ) ;
if ( F_188 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_114 ) ) {
V_346 = V_8 ;
goto V_349;
}
return 0 ;
}
if ( V_2 -> V_114 < F_189 ( V_2 ) || F_190 ( V_2 ) )
goto V_350;
if ( V_8 -> V_92 == V_93 ) {
struct V_7 * V_343 = F_180 ( V_8 , V_2 ) ;
if ( ! V_343 )
goto V_347;
if ( V_343 != V_8 ) {
F_187 ( V_343 , V_2 ) ;
if ( F_191 ( V_8 , V_343 , V_2 ) ) {
V_346 = V_343 ;
goto V_349;
}
return 0 ;
}
} else
F_187 ( V_8 , V_2 ) ;
if ( F_192 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_114 ) ) {
V_346 = V_8 ;
goto V_349;
}
return 0 ;
V_349:
F_75 ( V_346 , V_2 ) ;
V_347:
F_193 ( V_2 ) ;
return 0 ;
V_350:
F_89 ( F_22 ( V_8 ) , V_351 ) ;
goto V_347;
}
int F_194 ( struct V_1 * V_2 )
{
const struct V_88 * V_89 ;
const struct V_104 * V_105 ;
struct V_7 * V_8 ;
int V_352 ;
struct V_112 * V_112 = F_41 ( V_2 -> V_113 ) ;
if ( V_2 -> V_353 != V_354 )
goto V_355;
F_89 ( V_112 , V_356 ) ;
if ( ! F_74 ( V_2 , sizeof( struct V_104 ) ) )
goto V_355;
V_105 = F_4 ( V_2 ) ;
if ( V_105 -> V_161 < sizeof( struct V_104 ) / 4 )
goto V_357;
if ( ! F_74 ( V_2 , V_105 -> V_161 * 4 ) )
goto V_355;
if ( ! F_195 ( V_2 ) && F_184 ( V_2 ) )
goto V_357;
V_105 = F_4 ( V_2 ) ;
V_89 = F_3 ( V_2 ) ;
F_57 ( V_2 ) -> V_110 = F_50 ( V_105 -> V_110 ) ;
F_57 ( V_2 ) -> V_358 = ( F_57 ( V_2 ) -> V_110 + V_105 -> V_178 + V_105 -> V_179 +
V_2 -> V_114 - V_105 -> V_161 * 4 ) ;
F_57 ( V_2 ) -> V_177 = F_50 ( V_105 -> V_177 ) ;
F_57 ( V_2 ) -> V_142 = 0 ;
F_57 ( V_2 ) -> V_359 = F_196 ( V_89 ) ;
F_57 ( V_2 ) -> V_360 = 0 ;
V_8 = F_197 ( & V_116 , V_2 , V_105 -> V_6 , V_105 -> V_5 ) ;
if ( ! V_8 )
goto V_361;
V_362:
if ( V_8 -> V_92 == V_117 )
goto V_363;
if ( F_49 ( V_89 -> V_120 < F_14 ( V_8 ) -> V_121 ) ) {
F_48 ( V_112 , V_122 ) ;
goto V_364;
}
if ( ! F_198 ( V_8 , V_365 , V_2 ) )
goto V_364;
F_199 ( V_2 ) ;
if ( F_200 ( V_8 , V_2 ) )
goto V_364;
V_2 -> V_113 = NULL ;
F_201 ( V_8 ) ;
V_352 = 0 ;
if ( ! F_16 ( V_8 ) ) {
#ifdef F_202
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_366 . V_367 && V_14 -> V_366 . V_368 )
V_14 -> V_366 . V_367 = F_203 () ;
if ( V_14 -> V_366 . V_367 )
V_352 = F_186 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_204 ( V_8 , V_2 ) )
V_352 = F_186 ( V_8 , V_2 ) ;
}
} else if ( F_49 ( F_205 ( V_8 , V_2 ,
V_8 -> V_369 + V_8 -> V_370 ) ) ) {
F_65 ( V_8 ) ;
F_48 ( V_112 , V_371 ) ;
goto V_364;
}
F_65 ( V_8 ) ;
F_66 ( V_8 ) ;
return V_352 ;
V_361:
if ( ! F_198 ( NULL , V_365 , V_2 ) )
goto V_355;
if ( V_2 -> V_114 < ( V_105 -> V_161 << 2 ) || F_190 ( V_2 ) ) {
V_357:
F_89 ( V_112 , V_351 ) ;
} else {
F_75 ( NULL , V_2 ) ;
}
V_355:
F_193 ( V_2 ) ;
return 0 ;
V_364:
F_66 ( V_8 ) ;
goto V_355;
V_363:
if ( ! F_198 ( NULL , V_365 , V_2 ) ) {
F_45 ( F_46 ( V_8 ) ) ;
goto V_355;
}
if ( V_2 -> V_114 < ( V_105 -> V_161 << 2 ) || F_190 ( V_2 ) ) {
F_89 ( V_112 , V_351 ) ;
F_45 ( F_46 ( V_8 ) ) ;
goto V_355;
}
switch ( F_206 ( F_46 ( V_8 ) , V_2 , V_105 ) ) {
case V_372 : {
struct V_7 * V_373 = F_207 ( F_41 ( V_2 -> V_113 ) ,
& V_116 ,
V_89 -> V_3 , V_105 -> V_5 ,
F_44 ( V_2 ) ) ;
if ( V_373 ) {
F_208 ( F_46 ( V_8 ) , & V_66 ) ;
F_45 ( F_46 ( V_8 ) ) ;
V_8 = V_373 ;
goto V_362;
}
}
case V_374 :
F_93 ( V_8 , V_2 ) ;
break;
case V_375 :
goto V_361;
case V_376 : ;
}
goto V_355;
}
struct V_68 * F_209 ( struct V_7 * V_8 , bool * V_377 )
{
struct V_35 * V_36 = (struct V_35 * ) F_210 ( V_8 ) ;
struct V_28 * V_29 = F_14 ( V_8 ) ;
struct V_68 * V_69 ;
if ( ! V_36 ||
V_29 -> V_51 . V_52 . V_53 . V_54 . V_3 != V_29 -> V_64 ) {
V_69 = F_211 ( V_29 -> V_64 , 1 ) ;
* V_377 = true ;
} else {
if ( ! V_36 -> V_69 )
F_212 ( V_36 , V_29 -> V_64 , 1 ) ;
V_69 = V_36 -> V_69 ;
* V_377 = false ;
}
return V_69 ;
}
void * F_213 ( struct V_7 * V_8 )
{
const struct V_206 * V_207 = F_46 ( V_8 ) ;
return F_211 ( V_207 -> V_378 , 1 ) ;
}
static int F_214 ( struct V_7 * V_8 )
{
struct V_107 * V_108 = F_27 ( V_8 ) ;
F_215 ( V_8 ) ;
V_108 -> V_379 = & V_380 ;
#ifdef F_76
F_7 ( V_8 ) -> V_301 = & V_381 ;
#endif
return 0 ;
}
void F_216 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_178 ( V_8 ) ;
F_179 ( V_8 ) ;
F_217 ( V_8 ) ;
F_218 ( & V_14 -> V_382 ) ;
#ifdef F_76
if ( V_14 -> V_248 ) {
F_134 ( V_8 ) ;
F_132 ( V_14 -> V_248 , V_264 ) ;
V_14 -> V_248 = NULL ;
}
#endif
#ifdef F_202
F_218 ( & V_8 -> V_383 ) ;
#endif
F_218 ( & V_14 -> V_366 . V_384 ) ;
if ( F_27 ( V_8 ) -> V_385 )
F_219 ( V_8 ) ;
if ( V_8 -> V_386 ) {
F_220 ( V_8 -> V_386 ) ;
V_8 -> V_386 = NULL ;
}
if ( V_14 -> V_308 != NULL ) {
F_221 ( & V_14 -> V_308 -> V_387 ,
V_388 ) ;
V_14 -> V_308 = NULL ;
}
F_222 ( V_8 ) ;
F_223 ( V_8 ) ;
}
static inline struct V_206 * F_224 ( struct V_389 * V_159 )
{
return F_225 ( V_159 ) ? NULL :
F_226 ( V_159 -> V_390 , struct V_206 , V_391 ) ;
}
static inline struct V_206 * F_227 ( struct V_206 * V_207 )
{
return ! F_228 ( V_207 -> V_391 . V_392 ) ?
F_229 ( V_207 -> V_391 . V_392 , F_230 ( * V_207 ) , V_391 ) : NULL ;
}
static void * F_231 ( struct V_393 * V_110 , void * V_394 )
{
struct V_107 * V_108 ;
struct V_395 * V_261 ;
struct V_7 * V_8 = V_394 ;
struct V_396 * V_397 ;
struct V_398 * V_399 = V_110 -> V_400 ;
struct V_112 * V_112 = F_232 ( V_110 ) ;
if ( ! V_8 ) {
V_397 = & V_116 . V_401 [ V_399 -> V_402 ] ;
F_233 ( & V_397 -> V_403 ) ;
V_8 = F_234 ( & V_397 -> V_159 ) ;
V_399 -> V_205 = 0 ;
goto V_404;
}
V_397 = & V_116 . V_401 [ V_399 -> V_402 ] ;
++ V_399 -> V_405 ;
++ V_399 -> V_205 ;
if ( V_399 -> V_406 == V_407 ) {
struct V_147 * V_148 = V_394 ;
V_108 = F_27 ( V_399 -> V_408 ) ;
V_148 = V_148 -> V_409 ;
while ( 1 ) {
while ( V_148 ) {
if ( V_148 -> V_410 -> V_241 == V_399 -> V_241 ) {
V_394 = V_148 ;
goto V_119;
}
V_148 = V_148 -> V_409 ;
}
if ( ++ V_399 -> V_411 >= V_108 -> V_233 . V_234 -> V_412 )
break;
V_413:
V_148 = V_108 -> V_233 . V_234 -> V_414 [ V_399 -> V_411 ] ;
}
V_8 = F_235 ( V_399 -> V_408 ) ;
V_399 -> V_406 = V_415 ;
F_236 ( & V_108 -> V_233 . V_416 ) ;
} else {
V_108 = F_27 ( V_8 ) ;
F_237 ( & V_108 -> V_233 . V_416 ) ;
if ( F_238 ( & V_108 -> V_233 ) )
goto V_417;
F_236 ( & V_108 -> V_233 . V_416 ) ;
V_8 = F_235 ( V_8 ) ;
}
V_404:
F_239 (sk, node) {
if ( ! F_240 ( F_22 ( V_8 ) , V_112 ) )
continue;
if ( V_8 -> V_418 == V_399 -> V_241 ) {
V_394 = V_8 ;
goto V_119;
}
V_108 = F_27 ( V_8 ) ;
F_237 ( & V_108 -> V_233 . V_416 ) ;
if ( F_238 ( & V_108 -> V_233 ) ) {
V_417:
V_399 -> V_419 = F_241 ( V_8 ) ;
V_399 -> V_408 = V_8 ;
V_399 -> V_406 = V_407 ;
V_399 -> V_411 = 0 ;
goto V_413;
}
F_236 ( & V_108 -> V_233 . V_416 ) ;
}
F_242 ( & V_397 -> V_403 ) ;
V_399 -> V_205 = 0 ;
if ( ++ V_399 -> V_402 < V_420 ) {
V_397 = & V_116 . V_401 [ V_399 -> V_402 ] ;
F_233 ( & V_397 -> V_403 ) ;
V_8 = F_234 ( & V_397 -> V_159 ) ;
goto V_404;
}
V_394 = NULL ;
V_119:
return V_394 ;
}
static void * F_243 ( struct V_393 * V_110 , T_10 * V_243 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
void * V_421 ;
V_399 -> V_402 = 0 ;
V_399 -> V_205 = 0 ;
V_421 = F_231 ( V_110 , NULL ) ;
while ( V_421 && * V_243 ) {
V_421 = F_231 ( V_110 , V_421 ) ;
-- * V_243 ;
}
return V_421 ;
}
static inline bool F_244 ( struct V_398 * V_399 )
{
return F_225 ( & V_116 . V_422 [ V_399 -> V_402 ] . V_423 ) &&
F_225 ( & V_116 . V_422 [ V_399 -> V_402 ] . V_424 ) ;
}
static void * F_245 ( struct V_393 * V_110 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
struct V_112 * V_112 = F_232 ( V_110 ) ;
void * V_421 = NULL ;
V_399 -> V_205 = 0 ;
for (; V_399 -> V_402 <= V_116 . V_425 ; ++ V_399 -> V_402 ) {
struct V_7 * V_8 ;
struct V_395 * V_261 ;
struct V_206 * V_207 ;
T_11 * V_403 = F_246 ( & V_116 , V_399 -> V_402 ) ;
if ( F_244 ( V_399 ) )
continue;
F_233 ( V_403 ) ;
F_247 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_418 != V_399 -> V_241 ||
! F_240 ( F_22 ( V_8 ) , V_112 ) ) {
continue;
}
V_421 = V_8 ;
goto V_119;
}
V_399 -> V_406 = V_426 ;
F_248 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_207 -> V_427 != V_399 -> V_241 ||
! F_240 ( F_249 ( V_207 ) , V_112 ) ) {
continue;
}
V_421 = V_207 ;
goto V_119;
}
F_242 ( V_403 ) ;
V_399 -> V_406 = V_428 ;
}
V_119:
return V_421 ;
}
static void * F_250 ( struct V_393 * V_110 , void * V_394 )
{
struct V_7 * V_8 = V_394 ;
struct V_206 * V_207 ;
struct V_395 * V_261 ;
struct V_398 * V_399 = V_110 -> V_400 ;
struct V_112 * V_112 = F_232 ( V_110 ) ;
++ V_399 -> V_405 ;
++ V_399 -> V_205 ;
if ( V_399 -> V_406 == V_426 ) {
V_207 = V_394 ;
V_207 = F_227 ( V_207 ) ;
V_429:
while ( V_207 && ( V_207 -> V_427 != V_399 -> V_241 || ! F_240 ( F_249 ( V_207 ) , V_112 ) ) ) {
V_207 = F_227 ( V_207 ) ;
}
if ( V_207 ) {
V_394 = V_207 ;
goto V_119;
}
F_242 ( F_246 ( & V_116 , V_399 -> V_402 ) ) ;
V_399 -> V_406 = V_428 ;
V_399 -> V_205 = 0 ;
while ( ++ V_399 -> V_402 <= V_116 . V_425 &&
F_244 ( V_399 ) )
;
if ( V_399 -> V_402 > V_116 . V_425 )
return NULL ;
F_233 ( F_246 ( & V_116 , V_399 -> V_402 ) ) ;
V_8 = F_234 ( & V_116 . V_422 [ V_399 -> V_402 ] . V_423 ) ;
} else
V_8 = F_235 ( V_8 ) ;
F_239 (sk, node) {
if ( V_8 -> V_418 == V_399 -> V_241 && F_240 ( F_22 ( V_8 ) , V_112 ) )
goto V_430;
}
V_399 -> V_406 = V_426 ;
V_207 = F_224 ( & V_116 . V_422 [ V_399 -> V_402 ] . V_424 ) ;
goto V_429;
V_430:
V_394 = V_8 ;
V_119:
return V_394 ;
}
static void * F_251 ( struct V_393 * V_110 , T_10 V_243 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
void * V_421 ;
V_399 -> V_402 = 0 ;
V_421 = F_245 ( V_110 ) ;
while ( V_421 && V_243 ) {
V_421 = F_250 ( V_110 , V_421 ) ;
-- V_243 ;
}
return V_421 ;
}
static void * F_252 ( struct V_393 * V_110 , T_10 V_243 )
{
void * V_421 ;
struct V_398 * V_399 = V_110 -> V_400 ;
V_399 -> V_406 = V_415 ;
V_421 = F_243 ( V_110 , & V_243 ) ;
if ( ! V_421 ) {
V_399 -> V_406 = V_428 ;
V_421 = F_251 ( V_110 , V_243 ) ;
}
return V_421 ;
}
static void * F_253 ( struct V_393 * V_110 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
int V_205 = V_399 -> V_205 ;
int V_431 = V_399 -> V_405 ;
void * V_421 = NULL ;
switch ( V_399 -> V_406 ) {
case V_407 :
case V_415 :
if ( V_399 -> V_402 >= V_420 )
break;
V_399 -> V_406 = V_415 ;
V_421 = F_231 ( V_110 , NULL ) ;
while ( V_205 -- && V_421 )
V_421 = F_231 ( V_110 , V_421 ) ;
if ( V_421 )
break;
V_399 -> V_402 = 0 ;
case V_428 :
case V_426 :
V_399 -> V_406 = V_428 ;
if ( V_399 -> V_402 > V_116 . V_425 )
break;
V_421 = F_245 ( V_110 ) ;
while ( V_205 -- && V_421 )
V_421 = F_250 ( V_110 , V_421 ) ;
}
V_399 -> V_405 = V_431 ;
return V_421 ;
}
static void * F_254 ( struct V_393 * V_110 , T_10 * V_243 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
void * V_421 ;
if ( * V_243 && * V_243 == V_399 -> V_432 ) {
V_421 = F_253 ( V_110 ) ;
if ( V_421 )
goto V_119;
}
V_399 -> V_406 = V_415 ;
V_399 -> V_405 = 0 ;
V_399 -> V_402 = 0 ;
V_399 -> V_205 = 0 ;
V_421 = * V_243 ? F_252 ( V_110 , * V_243 - 1 ) : V_433 ;
V_119:
V_399 -> V_432 = * V_243 ;
return V_421 ;
}
static void * F_255 ( struct V_393 * V_110 , void * V_434 , T_10 * V_243 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
void * V_421 = NULL ;
if ( V_434 == V_433 ) {
V_421 = F_252 ( V_110 , 0 ) ;
goto V_119;
}
switch ( V_399 -> V_406 ) {
case V_407 :
case V_415 :
V_421 = F_231 ( V_110 , V_434 ) ;
if ( ! V_421 ) {
V_399 -> V_406 = V_428 ;
V_399 -> V_402 = 0 ;
V_399 -> V_205 = 0 ;
V_421 = F_245 ( V_110 ) ;
}
break;
case V_428 :
case V_426 :
V_421 = F_250 ( V_110 , V_434 ) ;
break;
}
V_119:
++ * V_243 ;
V_399 -> V_432 = * V_243 ;
return V_421 ;
}
static void F_256 ( struct V_393 * V_110 , void * V_434 )
{
struct V_398 * V_399 = V_110 -> V_400 ;
switch ( V_399 -> V_406 ) {
case V_407 :
if ( V_434 ) {
struct V_107 * V_108 = F_27 ( V_399 -> V_408 ) ;
F_236 ( & V_108 -> V_233 . V_416 ) ;
}
case V_415 :
if ( V_434 != V_433 )
F_242 ( & V_116 . V_401 [ V_399 -> V_402 ] . V_403 ) ;
break;
case V_426 :
case V_428 :
if ( V_434 )
F_242 ( F_246 ( & V_116 , V_399 -> V_402 ) ) ;
break;
}
}
int F_257 ( struct V_435 * V_435 , struct V_436 * V_436 )
{
struct V_437 * V_438 = F_258 ( V_435 ) -> V_103 ;
struct V_398 * V_439 ;
int V_37 ;
V_37 = F_259 ( V_435 , V_436 , & V_438 -> V_440 ,
sizeof( struct V_398 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_439 = ( (struct V_393 * ) V_436 -> V_441 ) -> V_400 ;
V_439 -> V_241 = V_438 -> V_241 ;
V_439 -> V_432 = 0 ;
return 0 ;
}
int F_260 ( struct V_112 * V_112 , struct V_437 * V_438 )
{
int V_421 = 0 ;
struct V_442 * V_443 ;
V_438 -> V_440 . V_444 = F_254 ;
V_438 -> V_440 . V_392 = F_255 ;
V_438 -> V_440 . V_445 = F_256 ;
V_443 = F_261 ( V_438 -> V_446 , V_447 , V_112 -> V_448 ,
V_438 -> V_449 , V_438 ) ;
if ( ! V_443 )
V_421 = - V_259 ;
return V_421 ;
}
void F_262 ( struct V_112 * V_112 , struct V_437 * V_438 )
{
F_263 ( V_112 , V_438 -> V_446 ) ;
}
static void F_264 ( const struct V_7 * V_8 , const struct V_147 * V_148 ,
struct V_393 * V_450 , int V_451 , int V_419 , int * V_114 )
{
const struct V_220 * V_221 = F_96 ( V_148 ) ;
int V_452 = V_148 -> V_453 - V_85 ;
F_265 ( V_450 , L_9
L_10 ,
V_451 ,
V_221 -> V_222 ,
F_82 ( F_14 ( V_8 ) -> V_49 ) ,
V_221 -> V_223 ,
F_82 ( V_221 -> V_454 ) ,
V_151 ,
0 , 0 ,
1 ,
F_266 ( V_452 ) ,
V_148 -> V_340 ,
V_419 ,
0 ,
0 ,
F_267 ( & V_8 -> V_455 ) ,
V_148 ,
V_114 ) ;
}
static void F_268 ( struct V_7 * V_8 , struct V_393 * V_450 , int V_451 , int * V_114 )
{
int V_456 ;
unsigned long V_457 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_107 * V_108 = F_27 ( V_8 ) ;
const struct V_28 * V_29 = F_14 ( V_8 ) ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_458 = V_29 -> V_63 ;
T_12 V_459 = F_82 ( V_29 -> V_74 ) ;
T_12 V_460 = F_82 ( V_29 -> V_49 ) ;
int V_461 ;
if ( V_108 -> V_462 == V_143 ) {
V_456 = 1 ;
V_457 = V_108 -> V_463 ;
} else if ( V_108 -> V_462 == V_464 ) {
V_456 = 4 ;
V_457 = V_108 -> V_463 ;
} else if ( F_269 ( & V_8 -> V_465 ) ) {
V_456 = 2 ;
V_457 = V_8 -> V_465 . V_453 ;
} else {
V_456 = 0 ;
V_457 = V_85 ;
}
if ( V_8 -> V_92 == V_93 )
V_461 = V_8 -> V_466 ;
else
V_461 = F_270 ( int , V_14 -> V_467 - V_14 -> V_468 , 0 ) ;
F_265 ( V_450 , L_11
L_12 ,
V_451 , V_458 , V_460 , V_5 , V_459 , V_8 -> V_92 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_461 ,
V_456 ,
F_266 ( V_457 - V_85 ) ,
V_108 -> V_136 ,
F_241 ( V_8 ) ,
V_108 -> V_469 ,
F_271 ( V_8 ) ,
F_267 ( & V_8 -> V_455 ) , V_8 ,
F_266 ( V_108 -> V_138 ) ,
F_266 ( V_108 -> V_470 . V_471 ) ,
( V_108 -> V_470 . V_472 << 1 ) | V_108 -> V_470 . V_473 ,
V_14 -> V_474 ,
F_272 ( V_14 ) ? - 1 : V_14 -> V_475 ,
V_114 ) ;
}
static void F_273 ( const struct V_206 * V_207 ,
struct V_393 * V_450 , int V_451 , int * V_114 )
{
T_3 V_5 , V_458 ;
T_12 V_459 , V_460 ;
int V_452 = V_207 -> V_476 - V_85 ;
if ( V_452 < 0 )
V_452 = 0 ;
V_5 = V_207 -> V_378 ;
V_458 = V_207 -> V_477 ;
V_459 = F_82 ( V_207 -> V_478 ) ;
V_460 = F_82 ( V_207 -> V_479 ) ;
F_265 ( V_450 , L_9
L_13 ,
V_451 , V_458 , V_460 , V_5 , V_459 , V_207 -> V_480 , 0 , 0 ,
3 , F_266 ( V_452 ) , 0 , 0 , 0 , 0 ,
F_267 ( & V_207 -> V_481 ) , V_207 , V_114 ) ;
}
static int F_274 ( struct V_393 * V_110 , void * V_434 )
{
struct V_398 * V_399 ;
int V_114 ;
if ( V_434 == V_433 ) {
F_265 ( V_110 , L_14 , V_482 - 1 ,
L_15
L_16
L_17 ) ;
goto V_119;
}
V_399 = V_110 -> V_400 ;
switch ( V_399 -> V_406 ) {
case V_415 :
case V_428 :
F_268 ( V_434 , V_110 , V_399 -> V_405 , & V_114 ) ;
break;
case V_407 :
F_264 ( V_399 -> V_408 , V_434 , V_110 , V_399 -> V_405 , V_399 -> V_419 , & V_114 ) ;
break;
case V_426 :
F_273 ( V_434 , V_110 , V_399 -> V_405 , & V_114 ) ;
break;
}
F_265 ( V_110 , L_18 , V_482 - 1 - V_114 , L_6 ) ;
V_119:
return 0 ;
}
static int T_13 F_275 ( struct V_112 * V_112 )
{
return F_260 ( V_112 , & V_483 ) ;
}
static void T_14 F_276 ( struct V_112 * V_112 )
{
F_262 ( V_112 , & V_483 ) ;
}
int T_15 F_277 ( void )
{
return F_278 ( & V_484 ) ;
}
void F_279 ( void )
{
F_280 ( & V_484 ) ;
}
struct V_1 * * F_281 ( struct V_1 * * V_159 , struct V_1 * V_2 )
{
const struct V_88 * V_89 = F_282 ( V_2 ) ;
switch ( V_2 -> V_155 ) {
case V_344 :
if ( ! F_68 ( F_283 ( V_2 ) , V_89 -> V_4 , V_89 -> V_3 ,
V_2 -> V_162 ) ) {
V_2 -> V_155 = V_345 ;
break;
}
case V_485 :
F_284 ( V_2 ) -> V_486 = 1 ;
return NULL ;
}
return F_285 ( V_159 , V_2 ) ;
}
int F_286 ( struct V_1 * V_2 )
{
const struct V_88 * V_89 = F_3 ( V_2 ) ;
struct V_104 * V_105 = F_4 ( V_2 ) ;
V_105 -> V_157 = ~ F_68 ( V_2 -> V_114 - F_287 ( V_2 ) ,
V_89 -> V_4 , V_89 -> V_3 , 0 ) ;
F_288 ( V_2 ) -> V_487 = V_82 ;
return F_289 ( V_2 ) ;
}
static int T_13 F_290 ( struct V_112 * V_112 )
{
return F_291 ( & V_112 -> V_194 . V_13 ,
V_488 , V_489 , V_57 , V_112 ) ;
}
static void T_14 F_292 ( struct V_112 * V_112 )
{
F_293 ( V_112 -> V_194 . V_13 ) ;
}
static void T_14 F_294 ( struct V_490 * V_491 )
{
F_295 ( & V_116 , & V_66 , V_42 ) ;
}
void T_15 F_296 ( void )
{
F_297 ( & V_116 ) ;
if ( F_278 ( & V_492 ) )
F_298 ( L_19 ) ;
}
