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
F_23 ( V_8 ) -> V_89 > V_83 ) {
F_33 ( V_8 , V_83 ) ;
F_34 ( V_8 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_82 * V_68 = F_36 ( V_8 , 0 ) ;
if ( V_68 )
V_68 -> V_90 -> V_91 ( V_68 , V_8 , V_2 ) ;
}
void F_37 ( struct V_1 * V_92 , T_4 V_93 )
{
const struct V_94 * V_95 = ( const struct V_94 * ) V_92 -> V_96 ;
struct V_97 * V_98 = (struct V_97 * ) ( V_92 -> V_96 + ( V_95 -> V_99 << 2 ) ) ;
struct V_100 * V_101 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_38 ( V_92 ) -> type ;
const int V_102 = F_38 ( V_92 ) -> V_102 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
T_1 V_105 ;
T_1 V_106 ;
int V_37 ;
struct V_107 * V_107 = F_39 ( V_92 -> V_108 ) ;
if ( V_92 -> V_109 < ( V_95 -> V_99 << 2 ) + 8 ) {
F_40 ( V_107 , V_110 ) ;
return;
}
V_8 = F_41 ( V_107 , & V_111 , V_95 -> V_3 , V_98 -> V_5 ,
V_95 -> V_4 , V_98 -> V_6 , F_42 ( V_92 ) ) ;
if ( ! V_8 ) {
F_40 ( V_107 , V_110 ) ;
return;
}
if ( V_8 -> V_112 == V_113 ) {
F_43 ( F_44 ( V_8 ) ) ;
return;
}
F_45 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_114 && V_102 == V_115 ) )
F_46 ( V_107 , V_116 ) ;
}
if ( V_8 -> V_112 == V_80 )
goto V_117;
if ( F_47 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_46 ( V_107 , V_120 ) ;
goto V_117;
}
V_101 = F_23 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_104 = V_14 -> V_121 ;
V_105 = F_48 ( V_98 -> V_105 ) ;
if ( V_8 -> V_112 != V_122 &&
! F_49 ( V_105 , V_14 -> V_123 , V_14 -> V_124 ) &&
( V_104 == NULL || V_105 != F_50 ( V_104 ) -> V_125 ) ) {
F_46 ( V_107 , V_126 ) ;
goto V_117;
}
switch ( type ) {
case V_127 :
F_35 ( V_92 , V_8 ) ;
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
if ( ! F_51 ( V_132 , & V_14 -> V_133 ) )
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
F_23 ( V_8 ) -> V_140 = ( V_14 -> V_141 ? F_52 ( V_14 ) :
V_142 ) << V_101 -> V_139 ;
F_53 ( V_8 ) ;
V_2 = F_54 ( V_8 ) ;
F_55 ( ! V_2 ) ;
V_106 = V_101 -> V_140 - F_56 ( V_101 -> V_140 ,
V_143 - F_57 ( V_2 ) -> V_144 ) ;
if ( V_106 ) {
F_58 ( V_8 , V_145 ,
V_106 , V_146 ) ;
} else {
F_59 ( V_8 ) ;
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
V_104 = F_60 ( V_8 , & V_149 , V_98 -> V_5 ,
V_95 -> V_3 , V_95 -> V_4 ) ;
if ( ! V_104 )
goto V_117;
F_61 ( V_104 -> V_8 ) ;
if ( V_105 != F_50 ( V_104 ) -> V_125 ) {
F_46 ( V_107 , V_126 ) ;
goto V_117;
}
F_62 ( V_8 , V_104 , V_149 ) ;
F_46 ( F_19 ( V_8 ) , V_150 ) ;
goto V_117;
case V_74 :
case V_151 :
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
F_63 ( V_8 ) ;
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
F_64 ( V_8 ) ;
F_65 ( V_8 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
if ( V_2 -> V_155 == V_156 ) {
V_98 -> V_157 = ~ F_67 ( V_2 -> V_109 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_68 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_69 ( struct V_97 , V_157 ) ;
} else {
V_98 -> V_157 = F_67 ( V_2 -> V_109 , V_4 , V_3 ,
F_70 ( V_98 ,
V_98 -> V_161 << 2 ,
V_2 -> V_162 ) ) ;
}
}
void F_71 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_66 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
struct V_97 * V_98 ;
if ( ! F_73 ( V_2 , sizeof( * V_98 ) ) )
return - V_40 ;
V_95 = F_3 ( V_2 ) ;
V_98 = F_4 ( V_2 ) ;
V_98 -> V_157 = 0 ;
V_2 -> V_155 = V_156 ;
F_66 ( V_2 , V_95 -> V_4 , V_95 -> V_3 ) ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
#ifdef F_75
T_3 V_46 [ ( V_163 >> 2 ) ] ;
#endif
} V_164 ;
struct V_165 V_166 ;
#ifdef F_75
struct V_167 * V_168 ;
const T_5 * V_169 = NULL ;
unsigned char V_170 [ 16 ] ;
int V_171 ;
struct V_7 * V_172 = NULL ;
#endif
struct V_107 * V_107 ;
if ( V_98 -> V_173 )
return;
if ( F_76 ( V_2 ) -> V_174 != V_175 )
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
V_164 . V_98 . V_177 = F_77 ( F_48 ( V_98 -> V_105 ) + V_98 -> V_178 + V_98 -> V_179 +
V_2 -> V_109 - ( V_98 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_98 ) ;
#ifdef F_75
V_169 = F_78 ( V_98 ) ;
if ( ! V_8 && V_169 ) {
V_172 = F_79 ( F_39 ( F_80 ( V_2 ) -> V_108 ) ,
& V_111 , F_3 ( V_2 ) -> V_4 ,
V_98 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_81 ( V_98 -> V_6 ) , F_42 ( V_2 ) ) ;
if ( ! V_172 )
return;
F_82 () ;
V_168 = F_83 ( V_172 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_168 )
goto V_184;
V_171 = F_84 ( V_170 , V_168 , NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 )
goto V_184;
} else {
V_168 = V_8 ? F_83 ( V_8 , (union V_183 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_168 ) {
V_164 . V_46 [ 0 ] = F_77 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_85 ( ( T_5 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_98 ) ;
}
#endif
V_166 . V_162 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_69 ( struct V_97 , V_157 ) / 2 ;
V_166 . V_189 = ( V_8 && F_11 ( V_8 ) -> V_190 ) ? V_191 : 0 ;
if ( V_8 )
V_166 . V_192 = V_8 -> V_56 ;
V_107 = F_39 ( F_80 ( V_2 ) -> V_108 ) ;
V_166 . V_193 = F_3 ( V_2 ) -> V_193 ;
F_87 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_88 ( V_107 , V_194 ) ;
F_88 ( V_107 , V_195 ) ;
#ifdef F_75
V_184:
if ( V_172 ) {
F_89 () ;
F_65 ( V_172 ) ;
}
#endif
}
static void F_90 ( struct V_1 * V_2 , T_4 V_105 , T_4 V_176 ,
T_4 V_196 , T_4 V_197 , T_4 V_198 , int V_199 ,
struct V_167 * V_168 ,
int V_200 , T_6 V_193 )
{
const struct V_97 * V_98 = F_4 ( V_2 ) ;
struct {
struct V_97 V_98 ;
T_3 V_46 [ ( V_201 >> 2 )
#ifdef F_75
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
struct V_107 * V_107 = F_39 ( F_80 ( V_2 ) -> V_108 ) ;
memset ( & V_164 . V_98 , 0 , sizeof( struct V_97 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_98 ) ;
if ( V_198 ) {
V_164 . V_46 [ 0 ] = F_77 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_202 << 8 ) |
V_203 ) ;
V_164 . V_46 [ 1 ] = F_77 ( V_197 ) ;
V_164 . V_46 [ 2 ] = F_77 ( V_198 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_201 ;
}
V_164 . V_98 . V_5 = V_98 -> V_6 ;
V_164 . V_98 . V_6 = V_98 -> V_5 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_98 . V_105 = F_77 ( V_105 ) ;
V_164 . V_98 . V_177 = F_77 ( V_176 ) ;
V_164 . V_98 . V_176 = 1 ;
V_164 . V_98 . V_204 = F_91 ( V_196 ) ;
#ifdef F_75
if ( V_168 ) {
int V_205 = ( V_198 ) ? 3 : 0 ;
V_164 . V_46 [ V_205 ++ ] = F_77 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_98 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_85 ( ( T_5 * ) & V_164 . V_46 [ V_205 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_98 ) ;
}
#endif
V_166 . V_189 = V_200 ;
V_166 . V_162 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_69 ( struct V_97 , V_157 ) / 2 ;
if ( V_199 )
V_166 . V_192 = V_199 ;
V_166 . V_193 = V_193 ;
F_87 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_88 ( V_107 , V_194 ) ;
}
static void F_92 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_206 * V_207 = F_44 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_90 ( V_2 , V_12 -> V_18 , V_12 -> V_208 ,
V_12 -> V_209 >> V_207 -> V_210 ,
V_143 + V_12 -> V_211 ,
V_12 -> V_21 ,
V_207 -> V_212 ,
F_93 ( V_12 ) ,
V_207 -> V_213 ? V_191 : 0 ,
V_207 -> V_214
) ;
F_43 ( V_207 ) ;
}
static void F_94 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 )
{
F_90 ( V_2 , ( V_8 -> V_112 == V_122 ) ?
F_50 ( V_104 ) -> V_125 + 1 : F_7 ( V_8 ) -> V_124 ,
F_50 ( V_104 ) -> V_215 , V_104 -> V_216 ,
V_143 ,
V_104 -> V_20 ,
0 ,
F_83 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_95 ( V_104 ) -> V_217 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_193 ) ;
}
static int F_96 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_103 * V_104 ,
struct V_218 * V_219 ,
T_7 V_220 ,
bool V_221 )
{
const struct V_222 * V_223 = F_95 ( V_104 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_97 ( V_8 , & V_34 , V_104 ) ) == NULL )
return - 1 ;
V_2 = F_98 ( V_8 , V_68 , V_104 , V_219 , NULL ) ;
if ( V_2 ) {
F_66 ( V_2 , V_223 -> V_224 , V_223 -> V_225 ) ;
F_99 ( V_2 , V_220 ) ;
V_37 = F_100 ( V_2 , V_8 , V_223 -> V_224 ,
V_223 -> V_225 ,
V_223 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( ! F_50 ( V_104 ) -> V_226 && ! V_37 )
F_50 ( V_104 ) -> V_226 = V_143 ;
}
return V_37 ;
}
static int F_102 ( struct V_7 * V_8 , struct V_103 * V_104 ,
struct V_218 * V_219 )
{
int V_227 = F_96 ( V_8 , NULL , V_104 , V_219 , 0 , false ) ;
if ( ! V_227 )
F_88 ( F_19 ( V_8 ) , V_228 ) ;
return V_227 ;
}
static void F_103 ( struct V_103 * V_104 )
{
F_104 ( F_95 ( V_104 ) -> V_46 ) ;
}
bool F_105 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_229 )
{
const char * V_230 = L_1 ;
bool V_231 = false ;
struct V_232 * V_233 ;
#ifdef F_106
if ( V_234 ) {
V_230 = L_2 ;
V_231 = true ;
F_46 ( F_19 ( V_8 ) , V_235 ) ;
} else
#endif
F_46 ( F_19 ( V_8 ) , V_236 ) ;
V_233 = F_23 ( V_8 ) -> V_237 . V_238 ;
if ( ! V_233 -> V_239 ) {
V_233 -> V_239 = 1 ;
F_107 ( L_3 ,
V_229 , F_81 ( F_4 ( V_2 ) -> V_5 ) , V_230 ) ;
}
return V_231 ;
}
static struct V_38 * F_108 ( struct V_1 * V_2 )
{
const struct V_240 * V_46 = & ( F_109 ( V_2 ) -> V_46 ) ;
struct V_38 * V_241 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_242 = sizeof( * V_241 ) + V_46 -> V_71 ;
V_241 = F_110 ( V_242 , V_243 ) ;
if ( V_241 ) {
if ( F_111 ( & V_241 -> V_46 , V_2 ) ) {
F_104 ( V_241 ) ;
V_241 = NULL ;
}
}
}
return V_241 ;
}
struct V_167 * F_83 ( struct V_7 * V_8 ,
const union V_183 * V_244 ,
int V_245 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
unsigned int V_246 = sizeof( struct V_247 ) ;
struct V_248 * V_249 ;
V_249 = F_112 ( V_14 -> V_250 ,
F_13 ( V_8 ) ||
F_113 ( & V_8 -> V_251 . V_252 ) ) ;
if ( ! V_249 )
return NULL ;
#if F_114 ( V_253 )
if ( V_245 == V_254 )
V_246 = sizeof( struct V_255 ) ;
#endif
F_115 (key, &md5sig->head, node) {
if ( V_168 -> V_245 != V_245 )
continue;
if ( ! memcmp ( & V_168 -> V_244 , V_244 , V_246 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_116 ( struct V_7 * V_8 ,
struct V_7 * V_256 )
{
union V_183 * V_244 ;
V_244 = (union V_183 * ) & F_11 ( V_256 ) -> V_64 ;
return F_83 ( V_8 , V_244 , V_42 ) ;
}
static struct V_167 * F_117 ( struct V_7 * V_8 ,
struct V_103 * V_104 )
{
union V_183 * V_244 ;
V_244 = (union V_183 * ) & F_95 ( V_104 ) -> V_225 ;
return F_83 ( V_8 , V_244 , V_42 ) ;
}
int F_118 ( struct V_7 * V_8 , const union V_183 * V_244 ,
int V_245 , const T_6 * V_257 , T_6 V_258 , T_8 V_259 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_248 * V_249 ;
V_168 = F_83 ( V_8 , (union V_183 * ) & V_244 , V_42 ) ;
if ( V_168 ) {
memcpy ( V_168 -> V_168 , V_257 , V_258 ) ;
V_168 -> V_260 = V_258 ;
return 0 ;
}
V_249 = F_12 ( V_14 -> V_250 ,
F_13 ( V_8 ) ) ;
if ( ! V_249 ) {
V_249 = F_110 ( sizeof( * V_249 ) , V_259 ) ;
if ( ! V_249 )
return - V_261 ;
F_119 ( V_8 , V_262 ) ;
F_120 ( & V_249 -> V_159 ) ;
F_121 ( V_14 -> V_250 , V_249 ) ;
}
V_168 = F_122 ( V_8 , sizeof( * V_168 ) , V_259 ) ;
if ( ! V_168 )
return - V_261 ;
if ( F_123 ( & V_249 -> V_159 ) && ! F_124 ( V_8 ) ) {
F_125 ( V_8 , V_168 , sizeof( * V_168 ) ) ;
return - V_261 ;
}
memcpy ( V_168 -> V_168 , V_257 , V_258 ) ;
V_168 -> V_260 = V_258 ;
V_168 -> V_245 = V_245 ;
memcpy ( & V_168 -> V_244 , V_244 ,
( V_245 == V_254 ) ? sizeof( struct V_255 ) :
sizeof( struct V_247 ) ) ;
F_126 ( & V_168 -> V_263 , & V_249 -> V_159 ) ;
return 0 ;
}
int F_127 ( struct V_7 * V_8 , const union V_183 * V_244 , int V_245 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_248 * V_249 ;
V_168 = F_83 ( V_8 , (union V_183 * ) & V_244 , V_42 ) ;
if ( ! V_168 )
return - V_264 ;
F_128 ( & V_168 -> V_263 ) ;
F_129 ( sizeof( * V_168 ) , & V_8 -> V_265 ) ;
F_130 ( V_168 , V_266 ) ;
V_249 = F_12 ( V_14 -> V_250 ,
F_13 ( V_8 ) ) ;
if ( F_123 ( & V_249 -> V_159 ) )
F_131 () ;
return 0 ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_267 * V_268 ;
struct V_248 * V_249 ;
V_249 = F_12 ( V_14 -> V_250 , 1 ) ;
if ( ! F_123 ( & V_249 -> V_159 ) )
F_131 () ;
F_133 (key, n, &md5sig->head, node) {
F_128 ( & V_168 -> V_263 ) ;
F_129 ( sizeof( * V_168 ) , & V_8 -> V_265 ) ;
F_130 ( V_168 , V_266 ) ;
}
}
static int F_134 ( struct V_7 * V_8 , char T_9 * V_269 ,
int V_71 )
{
struct V_270 V_271 ;
struct V_26 * sin = (struct V_26 * ) & V_271 . V_272 ;
if ( V_71 < sizeof( V_271 ) )
return - V_40 ;
if ( F_135 ( & V_271 , V_269 , sizeof( V_271 ) ) )
return - V_273 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_271 . V_274 || ! V_271 . V_275 )
return F_127 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_271 . V_275 > V_276 )
return - V_40 ;
return F_118 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_271 . V_274 , V_271 . V_275 ,
V_277 ) ;
}
static int F_136 ( struct V_278 * V_279 ,
T_3 V_3 , T_3 V_4 , int V_280 )
{
struct V_281 * V_282 ;
struct V_283 V_284 ;
V_282 = & V_279 -> V_285 . V_54 ;
V_282 -> V_4 = V_4 ;
V_282 -> V_3 = V_3 ;
V_282 -> V_286 = 0 ;
V_282 -> V_287 = V_57 ;
V_282 -> V_109 = F_137 ( V_280 ) ;
F_138 ( & V_284 , V_282 , sizeof( * V_282 ) ) ;
return F_139 ( & V_279 -> V_288 , & V_284 , sizeof( * V_282 ) ) ;
}
static int F_85 ( char * V_289 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_97 * V_98 )
{
struct V_278 * V_279 ;
struct V_290 * V_291 ;
V_279 = F_140 () ;
if ( ! V_279 )
goto V_292;
V_291 = & V_279 -> V_288 ;
if ( F_141 ( V_291 ) )
goto V_293;
if ( F_136 ( V_279 , V_3 , V_4 , V_98 -> V_161 << 2 ) )
goto V_293;
if ( F_142 ( V_279 , V_98 ) )
goto V_293;
if ( F_143 ( V_279 , V_168 ) )
goto V_293;
if ( F_144 ( V_291 , V_289 ) )
goto V_293;
F_145 () ;
return 0 ;
V_293:
F_145 () ;
V_292:
memset ( V_289 , 0 , 16 ) ;
return 1 ;
}
int F_84 ( char * V_289 , struct V_167 * V_168 ,
const struct V_7 * V_8 , const struct V_103 * V_104 ,
const struct V_1 * V_2 )
{
struct V_278 * V_279 ;
struct V_290 * V_291 ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_104 ) {
V_4 = F_95 ( V_104 ) -> V_224 ;
V_3 = F_95 ( V_104 ) -> V_225 ;
} else {
const struct V_94 * V_95 = F_3 ( V_2 ) ;
V_4 = V_95 -> V_4 ;
V_3 = V_95 -> V_3 ;
}
V_279 = F_140 () ;
if ( ! V_279 )
goto V_292;
V_291 = & V_279 -> V_288 ;
if ( F_141 ( V_291 ) )
goto V_293;
if ( F_136 ( V_279 , V_3 , V_4 , V_2 -> V_109 ) )
goto V_293;
if ( F_142 ( V_279 , V_98 ) )
goto V_293;
if ( F_146 ( V_279 , V_2 , V_98 -> V_161 << 2 ) )
goto V_293;
if ( F_143 ( V_279 , V_168 ) )
goto V_293;
if ( F_144 ( V_291 , V_289 ) )
goto V_293;
F_145 () ;
return 0 ;
V_293:
F_145 () ;
V_292:
memset ( V_289 , 0 , 16 ) ;
return 1 ;
}
static bool F_147 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_169 = NULL ;
struct V_167 * V_294 ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
const struct V_97 * V_98 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_294 = F_83 ( V_8 , (union V_183 * ) & V_95 -> V_4 ,
V_42 ) ;
V_169 = F_78 ( V_98 ) ;
if ( ! V_294 && ! V_169 )
return false ;
if ( V_294 && ! V_169 ) {
F_46 ( F_19 ( V_8 ) , V_295 ) ;
return true ;
}
if ( ! V_294 && V_169 ) {
F_46 ( F_19 ( V_8 ) , V_296 ) ;
return true ;
}
V_171 = F_84 ( V_170 ,
V_294 ,
NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_148 ( L_4 ,
& V_95 -> V_4 , F_81 ( V_98 -> V_6 ) ,
& V_95 -> V_3 , F_81 ( V_98 -> V_5 ) ,
V_171 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
static bool F_149 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_297 * V_298 ,
struct V_297 * V_299 )
{
bool V_300 = false ;
struct V_301 * V_302 ;
if ( F_21 ( ! F_150 ( V_298 ) ) ) {
if ( ( V_303 & V_304 ) ||
( ( V_303 & V_305 ) &&
( F_57 ( V_2 ) -> V_306 != F_57 ( V_2 ) -> V_105 + 1 ) ) )
V_300 = true ;
else
return false ;
}
V_302 = F_23 ( V_8 ) -> V_237 . V_302 ;
F_46 ( F_19 ( V_8 ) , V_307 ) ;
if ( ( V_303 & V_308 ) == 0 ||
V_302 == NULL || V_302 -> V_309 == 0 )
return false ;
if ( V_302 -> V_310 >= V_302 -> V_309 ) {
struct V_103 * V_311 ;
F_151 ( & V_302 -> V_312 ) ;
V_311 = V_302 -> V_313 ;
if ( ( V_311 == NULL ) || F_152 ( V_311 -> V_314 , V_79 ) ) {
F_153 ( & V_302 -> V_312 ) ;
F_46 ( F_19 ( V_8 ) ,
V_315 ) ;
V_298 -> V_109 = - 1 ;
return false ;
}
V_302 -> V_313 = V_311 -> V_316 ;
V_302 -> V_310 -- ;
F_153 ( & V_302 -> V_312 ) ;
F_154 ( V_311 ) ;
}
if ( V_300 ) {
F_50 ( V_104 ) -> V_215 = F_57 ( V_2 ) -> V_306 ;
return true ;
}
if ( V_298 -> V_109 == V_317 ) {
if ( ( V_303 & V_318 ) == 0 ) {
F_155 ( F_3 ( V_2 ) -> V_4 , V_299 ) ;
if ( ( V_299 -> V_109 != V_317 ) ||
memcmp ( & V_298 -> V_319 [ 0 ] , & V_299 -> V_319 [ 0 ] ,
V_317 ) != 0 )
return false ;
V_299 -> V_109 = - 1 ;
}
F_50 ( V_104 ) -> V_215 = F_57 ( V_2 ) -> V_306 ;
return true ;
} else if ( V_298 -> V_109 == 0 ) {
F_155 ( F_3 ( V_2 ) -> V_4 , V_299 ) ;
F_46 ( F_19 ( V_8 ) ,
V_320 ) ;
} else {
F_155 ( F_3 ( V_2 ) -> V_4 , V_299 ) ;
}
return false ;
}
static int F_156 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_1 * V_321 ,
struct V_103 * V_104 ,
struct V_218 * V_219 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_322 * V_323 = & F_23 ( V_8 ) -> V_237 ;
const struct V_222 * V_223 = F_95 ( V_104 ) ;
struct V_7 * V_324 ;
int V_37 ;
V_104 -> V_325 = 0 ;
V_104 -> V_326 = 0 ;
V_104 -> V_8 = NULL ;
V_324 = F_23 ( V_8 ) -> V_327 -> V_328 ( V_8 , V_2 , V_104 , NULL ) ;
if ( V_324 == NULL ) {
F_46 ( F_19 ( V_8 ) ,
V_329 ) ;
F_157 ( V_321 ) ;
return - 1 ;
}
V_37 = F_100 ( V_321 , V_8 , V_223 -> V_224 ,
V_223 -> V_225 , V_223 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( ! V_37 )
F_50 ( V_104 ) -> V_226 = V_143 ;
F_151 ( & V_323 -> V_302 -> V_312 ) ;
V_323 -> V_302 -> V_310 ++ ;
F_153 ( & V_323 -> V_302 -> V_312 ) ;
V_14 = F_7 ( V_324 ) ;
V_14 -> V_121 = V_104 ;
F_9 ( V_8 ) ;
F_50 ( V_104 ) -> V_330 = V_8 ;
V_14 -> V_331 = F_81 ( F_4 ( V_2 ) -> V_204 ) ;
F_58 ( V_324 , V_145 ,
V_142 , V_146 ) ;
F_158 ( V_8 , V_104 , V_324 ) ;
F_23 ( V_324 ) -> V_327 -> V_332 ( V_324 ) ;
F_159 ( V_324 ) ;
F_160 ( V_324 ) ;
F_161 ( V_324 ) ;
F_162 ( V_324 ) ;
if ( F_57 ( V_2 ) -> V_306 == F_57 ( V_2 ) -> V_105 + 1 ) {
V_14 -> V_215 = F_57 ( V_2 ) -> V_306 ;
} else {
V_2 = F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 , F_4 ( V_2 ) -> V_161 * 4 ) ;
F_166 ( V_2 , V_324 ) ;
F_167 ( & V_324 -> V_333 , V_2 ) ;
V_14 -> V_215 = F_57 ( V_2 ) -> V_306 ;
V_14 -> V_334 = 1 ;
}
V_8 -> V_335 ( V_8 , 0 ) ;
F_64 ( V_324 ) ;
F_65 ( V_324 ) ;
F_61 ( V_104 -> V_8 == NULL ) ;
return 0 ;
}
int F_168 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_336 V_337 ;
struct V_338 V_339 ;
const T_6 * V_169 ;
struct V_103 * V_104 ;
struct V_222 * V_223 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_340 = F_57 ( V_2 ) -> V_144 ;
bool V_231 = false ;
struct V_33 V_34 ;
struct V_297 V_298 = { . V_109 = - 1 } ;
struct V_297 V_299 = { . V_109 = - 1 } ;
struct V_1 * V_321 ;
int V_341 ;
if ( F_76 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_342;
if ( F_169 ( V_8 ) && ! V_340 ) {
V_231 = F_105 ( V_8 , V_2 , L_7 ) ;
if ( ! V_231 )
goto V_342;
}
if ( F_170 ( V_8 ) && F_171 ( V_8 ) > 1 ) {
F_46 ( F_19 ( V_8 ) , V_343 ) ;
goto V_342;
}
V_104 = F_172 ( & V_344 ) ;
if ( ! V_104 )
goto V_342;
#ifdef F_75
F_50 ( V_104 ) -> V_345 = & V_346 ;
#endif
F_173 ( & V_339 ) ;
V_339 . V_72 = V_73 ;
V_339 . V_347 = V_14 -> V_19 . V_347 ;
F_174 ( V_2 , & V_339 , & V_169 , 0 ,
V_231 ? NULL : & V_298 ) ;
if ( V_339 . V_348 > 0 &&
V_339 . V_349 &&
! V_14 -> V_19 . V_350 &&
( V_351 > 0 ||
( V_14 -> V_352 != NULL &&
V_14 -> V_352 -> V_353 > 0 ) ) ) {
T_6 * V_354 ;
T_4 * V_355 = & V_337 . V_356 [ V_357 ] ;
int V_358 = V_339 . V_348 - V_359 ;
if ( F_175 ( & V_337 . V_356 [ 0 ] ) != 0 )
goto V_360;
* V_355 ++ ^= ( V_361 T_4 ) V_3 ;
* V_355 ++ ^= ( V_361 T_4 ) V_4 ;
V_354 = ( T_6 * ) V_355 ;
while ( V_358 -- > 0 )
* V_354 ++ ^= * V_169 ++ ;
V_231 = false ;
V_337 . V_350 = 0 ;
V_337 . V_348 = V_339 . V_348 ;
} else if ( ! V_14 -> V_19 . V_362 ) {
V_337 . V_350 = 1 ;
V_337 . V_348 = 0 ;
} else {
goto V_360;
}
V_337 . V_362 = V_14 -> V_19 . V_362 ;
if ( V_231 && ! V_339 . V_349 )
F_173 ( & V_339 ) ;
V_339 . V_363 = V_339 . V_349 ;
F_176 ( V_104 , & V_339 , V_2 ) ;
V_223 = F_95 ( V_104 ) ;
V_223 -> V_224 = V_3 ;
V_223 -> V_225 = V_4 ;
V_223 -> V_217 = F_11 ( V_8 ) -> V_190 ;
V_223 -> V_46 = F_108 ( V_2 ) ;
if ( F_177 ( V_8 , V_2 , V_104 ) )
goto V_364;
if ( ! V_231 || V_339 . V_363 )
F_178 ( V_104 , V_2 , F_19 ( V_8 ) ) ;
if ( V_231 ) {
V_340 = F_179 ( V_8 , V_2 , & V_104 -> V_365 ) ;
V_104 -> V_366 = V_339 . V_363 ;
} else if ( ! V_340 ) {
if ( V_339 . V_349 &&
V_66 . V_67 &&
( V_68 = F_97 ( V_8 , & V_34 , V_104 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_180 ( V_104 , V_68 , true ) ) {
F_46 ( F_19 ( V_8 ) , V_367 ) ;
goto V_360;
}
}
else if ( ! V_234 &&
( V_368 - F_181 ( V_8 ) <
( V_368 >> 2 ) ) &&
! F_180 ( V_104 , V_68 , false ) ) {
F_182 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_360;
}
V_340 = F_1 ( V_2 ) ;
}
F_50 ( V_104 ) -> V_125 = V_340 ;
if ( V_68 == NULL ) {
V_68 = F_97 ( V_8 , & V_34 , V_104 ) ;
if ( V_68 == NULL )
goto V_364;
}
V_341 = F_149 ( V_8 , V_2 , V_104 , & V_298 , & V_299 ) ;
V_321 = F_98 ( V_8 , V_68 , V_104 ,
(struct V_218 * ) & V_337 ,
F_150 ( & V_299 ) ? & V_299 : NULL ) ;
if ( V_321 ) {
F_66 ( V_321 , V_223 -> V_224 , V_223 -> V_225 ) ;
F_99 ( V_321 , F_183 ( V_2 ) ) ;
} else
goto V_364;
if ( F_21 ( ! V_341 ) ) {
int V_37 ;
V_37 = F_100 ( V_321 , V_8 , V_223 -> V_224 ,
V_223 -> V_225 , V_223 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( V_37 || V_231 )
goto V_364;
F_50 ( V_104 ) -> V_226 = V_143 ;
F_50 ( V_104 ) -> V_330 = NULL ;
F_184 ( V_8 , V_104 , V_142 ) ;
if ( F_150 ( & V_298 ) && V_298 . V_109 != 0 )
F_46 ( F_19 ( V_8 ) ,
V_329 ) ;
} else if ( F_156 ( V_8 , V_2 , V_321 , V_104 ,
(struct V_218 * ) & V_337 ) )
goto V_364;
return 0 ;
V_360:
F_185 ( V_68 ) ;
V_364:
F_154 ( V_104 ) ;
V_342:
F_46 ( F_19 ( V_8 ) , V_150 ) ;
return 0 ;
}
struct V_7 * F_186 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_103 * V_104 ,
struct V_82 * V_68 )
{
struct V_222 * V_223 ;
struct V_28 * V_369 ;
struct V_13 * V_370 ;
struct V_7 * V_371 ;
#ifdef F_75
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_170 ( V_8 ) )
goto V_372;
V_371 = F_187 ( V_8 , V_104 , V_2 ) ;
if ( ! V_371 )
goto V_373;
V_371 -> V_76 = V_77 ;
F_188 ( V_371 , V_2 ) ;
V_370 = F_7 ( V_371 ) ;
V_369 = F_11 ( V_371 ) ;
V_223 = F_95 ( V_104 ) ;
V_369 -> V_64 = V_223 -> V_225 ;
V_369 -> V_63 = V_223 -> V_224 ;
V_369 -> V_55 = V_223 -> V_224 ;
V_39 = V_223 -> V_46 ;
F_121 ( V_369 -> V_39 , V_39 ) ;
V_223 -> V_46 = NULL ;
V_369 -> V_374 = F_42 ( V_2 ) ;
V_369 -> V_375 = F_3 ( V_2 ) -> V_118 ;
V_369 -> V_376 = F_3 ( V_2 ) -> V_193 ;
F_23 ( V_371 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_371 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_369 -> V_78 = V_370 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_189 ( V_8 , V_371 , V_104 ) ;
if ( ! V_68 )
goto V_377;
} else {
}
F_27 ( V_371 , V_68 ) ;
F_160 ( V_371 ) ;
F_33 ( V_371 , F_31 ( V_68 ) ) ;
V_370 -> V_378 = F_190 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_347 &&
F_7 ( V_8 ) -> V_19 . V_347 < V_370 -> V_378 )
V_370 -> V_378 = F_7 ( V_8 ) -> V_19 . V_347 ;
F_191 ( V_371 ) ;
F_192 ( V_371 , V_104 ) ;
V_370 -> V_379 = V_104 -> V_325 ;
#ifdef F_75
V_168 = F_83 ( V_8 , (union V_183 * ) & V_369 -> V_64 ,
V_42 ) ;
if ( V_168 != NULL ) {
F_118 ( V_371 , (union V_183 * ) & V_369 -> V_64 ,
V_42 , V_168 -> V_168 , V_168 -> V_260 , V_243 ) ;
F_119 ( V_371 , V_262 ) ;
}
#endif
if ( F_193 ( V_8 , V_371 ) < 0 )
goto V_377;
F_194 ( V_371 , NULL ) ;
return V_371 ;
V_372:
F_46 ( F_19 ( V_8 ) , V_343 ) ;
V_373:
F_185 ( V_68 ) ;
exit:
F_46 ( F_19 ( V_8 ) , V_150 ) ;
return NULL ;
V_377:
F_195 ( V_371 ) ;
F_63 ( V_371 ) ;
goto exit;
}
static struct V_7 * F_196 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_97 * V_98 = F_4 ( V_2 ) ;
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_7 * V_380 ;
struct V_103 * * V_149 ;
struct V_103 * V_104 = F_60 ( V_8 , & V_149 , V_98 -> V_6 ,
V_95 -> V_4 , V_95 -> V_3 ) ;
if ( V_104 )
return F_197 ( V_8 , V_2 , V_104 , V_149 , false ) ;
V_380 = F_198 ( F_19 ( V_8 ) , & V_111 , V_95 -> V_4 ,
V_98 -> V_6 , V_95 -> V_3 , V_98 -> V_5 , F_42 ( V_2 ) ) ;
if ( V_380 ) {
if ( V_380 -> V_112 != V_113 ) {
F_45 ( V_380 ) ;
return V_380 ;
}
F_43 ( F_44 ( V_380 ) ) ;
return NULL ;
}
#ifdef F_106
if ( ! V_98 -> V_178 )
V_8 = F_199 ( V_8 , V_2 , & ( F_109 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_10 F_200 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 = F_3 ( V_2 ) ;
if ( V_2 -> V_155 == V_381 ) {
if ( ! F_67 ( V_2 -> V_109 , V_95 -> V_4 ,
V_95 -> V_3 , V_2 -> V_162 ) ) {
V_2 -> V_155 = V_382 ;
return 0 ;
}
}
V_2 -> V_162 = F_86 ( V_95 -> V_4 , V_95 -> V_3 ,
V_2 -> V_109 , V_57 , 0 ) ;
if ( V_2 -> V_109 <= 76 ) {
return F_201 ( V_2 ) ;
}
return 0 ;
}
int F_202 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_383 ;
#ifdef F_75
if ( F_147 ( V_8 , V_2 ) )
goto V_384;
#endif
if ( V_8 -> V_112 == V_385 ) {
struct V_82 * V_68 = V_8 -> V_386 ;
F_203 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_387 != V_2 -> V_388 ||
V_68 -> V_90 -> V_157 ( V_68 , 0 ) == NULL ) {
F_185 ( V_68 ) ;
V_8 -> V_386 = NULL ;
}
}
if ( F_204 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_383 = V_8 ;
goto V_389;
}
return 0 ;
}
if ( V_2 -> V_109 < F_205 ( V_2 ) || F_206 ( V_2 ) )
goto V_390;
if ( V_8 -> V_112 == V_122 ) {
struct V_7 * V_380 = F_196 ( V_8 , V_2 ) ;
if ( ! V_380 )
goto V_384;
if ( V_380 != V_8 ) {
F_203 ( V_380 , V_2 ) ;
if ( F_207 ( V_8 , V_380 , V_2 ) ) {
V_383 = V_380 ;
goto V_389;
}
return 0 ;
}
} else
F_203 ( V_8 , V_2 ) ;
if ( F_208 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_383 = V_8 ;
goto V_389;
}
return 0 ;
V_389:
F_74 ( V_383 , V_2 ) ;
V_384:
F_157 ( V_2 ) ;
return 0 ;
V_390:
F_88 ( F_19 ( V_8 ) , V_391 ) ;
goto V_384;
}
void F_209 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
if ( V_2 -> V_392 != V_393 )
return;
if ( ! F_73 ( V_2 , F_210 ( V_2 ) + sizeof( struct V_97 ) ) )
return;
V_95 = F_3 ( V_2 ) ;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_161 < sizeof( struct V_97 ) / 4 )
return;
V_8 = F_211 ( F_39 ( V_2 -> V_108 ) , & V_111 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , F_81 ( V_98 -> V_5 ) ,
V_2 -> V_388 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_394 = V_395 ;
if ( V_8 -> V_112 != V_113 ) {
struct V_82 * V_68 = V_8 -> V_386 ;
if ( V_68 )
V_68 = F_212 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_387 == V_2 -> V_388 )
F_213 ( V_2 , V_68 ) ;
}
}
}
int F_214 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 ;
const struct V_97 * V_98 ;
struct V_7 * V_8 ;
int V_396 ;
struct V_107 * V_107 = F_39 ( V_2 -> V_108 ) ;
if ( V_2 -> V_392 != V_393 )
goto V_397;
F_88 ( V_107 , V_398 ) ;
if ( ! F_73 ( V_2 , sizeof( struct V_97 ) ) )
goto V_397;
V_98 = F_4 ( V_2 ) ;
if ( V_98 -> V_161 < sizeof( struct V_97 ) / 4 )
goto V_399;
if ( ! F_73 ( V_2 , V_98 -> V_161 * 4 ) )
goto V_397;
if ( ! F_215 ( V_2 ) && F_200 ( V_2 ) )
goto V_399;
V_98 = F_4 ( V_2 ) ;
V_95 = F_3 ( V_2 ) ;
F_57 ( V_2 ) -> V_105 = F_48 ( V_98 -> V_105 ) ;
F_57 ( V_2 ) -> V_306 = ( F_57 ( V_2 ) -> V_105 + V_98 -> V_178 + V_98 -> V_179 +
V_2 -> V_109 - V_98 -> V_161 * 4 ) ;
F_57 ( V_2 ) -> V_177 = F_48 ( V_98 -> V_177 ) ;
F_57 ( V_2 ) -> V_144 = 0 ;
F_57 ( V_2 ) -> V_400 = F_216 ( V_95 ) ;
F_57 ( V_2 ) -> V_401 = 0 ;
V_8 = F_217 ( & V_111 , V_2 , V_98 -> V_6 , V_98 -> V_5 ) ;
if ( ! V_8 )
goto V_402;
V_403:
if ( V_8 -> V_112 == V_113 )
goto V_404;
if ( F_47 ( V_95 -> V_118 < F_11 ( V_8 ) -> V_119 ) ) {
F_46 ( V_107 , V_120 ) ;
goto V_405;
}
if ( ! F_218 ( V_8 , V_406 , V_2 ) )
goto V_405;
F_219 ( V_2 ) ;
if ( F_220 ( V_8 , V_2 ) )
goto V_405;
V_2 -> V_108 = NULL ;
F_221 ( V_8 ) ;
V_396 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_222
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_407 . V_408 && V_14 -> V_407 . V_409 )
V_14 -> V_407 . V_408 = F_223 () ;
if ( V_14 -> V_407 . V_408 )
V_396 = F_202 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_224 ( V_8 , V_2 ) )
V_396 = F_202 ( V_8 , V_2 ) ;
}
} else if ( F_47 ( F_225 ( V_8 , V_2 ,
V_8 -> V_410 + V_8 -> V_411 ) ) ) {
F_64 ( V_8 ) ;
F_46 ( V_107 , V_412 ) ;
goto V_405;
}
F_64 ( V_8 ) ;
F_65 ( V_8 ) ;
return V_396 ;
V_402:
if ( ! F_218 ( NULL , V_406 , V_2 ) )
goto V_397;
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) || F_206 ( V_2 ) ) {
V_399:
F_88 ( V_107 , V_391 ) ;
} else {
F_74 ( NULL , V_2 ) ;
}
V_397:
F_157 ( V_2 ) ;
return 0 ;
V_405:
F_65 ( V_8 ) ;
goto V_397;
V_404:
if ( ! F_218 ( NULL , V_406 , V_2 ) ) {
F_43 ( F_44 ( V_8 ) ) ;
goto V_397;
}
if ( V_2 -> V_109 < ( V_98 -> V_161 << 2 ) || F_206 ( V_2 ) ) {
F_88 ( V_107 , V_391 ) ;
F_43 ( F_44 ( V_8 ) ) ;
goto V_397;
}
switch ( F_226 ( F_44 ( V_8 ) , V_2 , V_98 ) ) {
case V_413 : {
struct V_7 * V_414 = F_227 ( F_39 ( V_2 -> V_108 ) ,
& V_111 ,
V_95 -> V_4 , V_98 -> V_6 ,
V_95 -> V_3 , V_98 -> V_5 ,
F_42 ( V_2 ) ) ;
if ( V_414 ) {
F_228 ( F_44 ( V_8 ) , & V_66 ) ;
F_43 ( F_44 ( V_8 ) ) ;
V_8 = V_414 ;
goto V_403;
}
}
case V_415 :
F_92 ( V_8 , V_2 ) ;
break;
case V_416 :
goto V_402;
case V_417 : ;
}
goto V_397;
}
void F_188 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_80 ( V_2 ) ;
F_229 ( V_68 ) ;
V_8 -> V_386 = V_68 ;
F_11 ( V_8 ) -> V_387 = V_2 -> V_388 ;
}
static int F_230 ( struct V_7 * V_8 )
{
struct V_100 * V_101 = F_23 ( V_8 ) ;
F_231 ( V_8 ) ;
V_101 -> V_327 = & V_418 ;
#ifdef F_75
F_7 ( V_8 ) -> V_345 = & V_419 ;
#endif
return 0 ;
}
void F_232 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_233 ( V_8 ) ;
F_234 ( V_8 ) ;
F_235 ( V_8 ) ;
F_236 ( & V_14 -> V_420 ) ;
#ifdef F_75
if ( V_14 -> V_250 ) {
F_132 ( V_8 ) ;
F_130 ( V_14 -> V_250 , V_266 ) ;
V_14 -> V_250 = NULL ;
}
#endif
#ifdef F_222
F_236 ( & V_8 -> V_421 ) ;
#endif
F_236 ( & V_14 -> V_407 . V_422 ) ;
if ( F_23 ( V_8 ) -> V_423 )
F_237 ( V_8 ) ;
if ( V_14 -> V_352 != NULL ) {
F_238 ( & V_14 -> V_352 -> V_424 ,
V_425 ) ;
V_14 -> V_352 = NULL ;
}
F_55 ( V_14 -> V_121 != NULL ) ;
F_239 ( V_14 ) ;
F_240 ( V_8 ) ;
F_241 ( V_8 ) ;
}
static inline struct V_206 * F_242 ( struct V_426 * V_159 )
{
return F_243 ( V_159 ) ? NULL :
F_244 ( V_159 -> V_427 , struct V_206 , V_428 ) ;
}
static inline struct V_206 * F_245 ( struct V_206 * V_207 )
{
return ! F_246 ( V_207 -> V_428 . V_429 ) ?
F_247 ( V_207 -> V_428 . V_429 , F_248 ( * V_207 ) , V_428 ) : NULL ;
}
static void * F_249 ( struct V_430 * V_105 , void * V_431 )
{
struct V_100 * V_101 ;
struct V_432 * V_263 ;
struct V_7 * V_8 = V_431 ;
struct V_433 * V_434 ;
struct V_435 * V_436 = V_105 -> V_437 ;
struct V_107 * V_107 = F_250 ( V_105 ) ;
if ( ! V_8 ) {
V_434 = & V_111 . V_438 [ V_436 -> V_439 ] ;
F_251 ( & V_434 -> V_312 ) ;
V_8 = F_252 ( & V_434 -> V_159 ) ;
V_436 -> V_205 = 0 ;
goto V_440;
}
V_434 = & V_111 . V_438 [ V_436 -> V_439 ] ;
++ V_436 -> V_441 ;
++ V_436 -> V_205 ;
if ( V_436 -> V_442 == V_443 ) {
struct V_103 * V_104 = V_431 ;
V_101 = F_23 ( V_436 -> V_444 ) ;
V_104 = V_104 -> V_316 ;
while ( 1 ) {
while ( V_104 ) {
if ( V_104 -> V_445 -> V_245 == V_436 -> V_245 ) {
V_431 = V_104 ;
goto V_117;
}
V_104 = V_104 -> V_316 ;
}
if ( ++ V_436 -> V_446 >= V_101 -> V_237 . V_238 -> V_447 )
break;
V_448:
V_104 = V_101 -> V_237 . V_238 -> V_449 [ V_436 -> V_446 ] ;
}
V_8 = F_253 ( V_436 -> V_444 ) ;
V_436 -> V_442 = V_450 ;
F_254 ( & V_101 -> V_237 . V_451 ) ;
} else {
V_101 = F_23 ( V_8 ) ;
F_255 ( & V_101 -> V_237 . V_451 ) ;
if ( F_256 ( & V_101 -> V_237 ) )
goto V_452;
F_254 ( & V_101 -> V_237 . V_451 ) ;
V_8 = F_253 ( V_8 ) ;
}
V_440:
F_257 (sk, node) {
if ( ! F_258 ( F_19 ( V_8 ) , V_107 ) )
continue;
if ( V_8 -> V_453 == V_436 -> V_245 ) {
V_431 = V_8 ;
goto V_117;
}
V_101 = F_23 ( V_8 ) ;
F_255 ( & V_101 -> V_237 . V_451 ) ;
if ( F_256 ( & V_101 -> V_237 ) ) {
V_452:
V_436 -> V_454 = F_259 ( V_8 ) ;
V_436 -> V_444 = V_8 ;
V_436 -> V_442 = V_443 ;
V_436 -> V_446 = 0 ;
goto V_448;
}
F_254 ( & V_101 -> V_237 . V_451 ) ;
}
F_260 ( & V_434 -> V_312 ) ;
V_436 -> V_205 = 0 ;
if ( ++ V_436 -> V_439 < V_455 ) {
V_434 = & V_111 . V_438 [ V_436 -> V_439 ] ;
F_251 ( & V_434 -> V_312 ) ;
V_8 = F_252 ( & V_434 -> V_159 ) ;
goto V_440;
}
V_431 = NULL ;
V_117:
return V_431 ;
}
static void * F_261 ( struct V_430 * V_105 , T_11 * V_456 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
void * V_457 ;
V_436 -> V_439 = 0 ;
V_436 -> V_205 = 0 ;
V_457 = F_249 ( V_105 , NULL ) ;
while ( V_457 && * V_456 ) {
V_457 = F_249 ( V_105 , V_457 ) ;
-- * V_456 ;
}
return V_457 ;
}
static inline bool F_262 ( struct V_435 * V_436 )
{
return F_243 ( & V_111 . V_458 [ V_436 -> V_439 ] . V_459 ) &&
F_243 ( & V_111 . V_458 [ V_436 -> V_439 ] . V_460 ) ;
}
static void * F_263 ( struct V_430 * V_105 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
struct V_107 * V_107 = F_250 ( V_105 ) ;
void * V_457 = NULL ;
V_436 -> V_205 = 0 ;
for (; V_436 -> V_439 <= V_111 . V_461 ; ++ V_436 -> V_439 ) {
struct V_7 * V_8 ;
struct V_432 * V_263 ;
struct V_206 * V_207 ;
T_12 * V_312 = F_264 ( & V_111 , V_436 -> V_439 ) ;
if ( F_262 ( V_436 ) )
continue;
F_251 ( V_312 ) ;
F_265 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_453 != V_436 -> V_245 ||
! F_258 ( F_19 ( V_8 ) , V_107 ) ) {
continue;
}
V_457 = V_8 ;
goto V_117;
}
V_436 -> V_442 = V_462 ;
F_266 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_207 -> V_463 != V_436 -> V_245 ||
! F_258 ( F_267 ( V_207 ) , V_107 ) ) {
continue;
}
V_457 = V_207 ;
goto V_117;
}
F_260 ( V_312 ) ;
V_436 -> V_442 = V_464 ;
}
V_117:
return V_457 ;
}
static void * F_268 ( struct V_430 * V_105 , void * V_431 )
{
struct V_7 * V_8 = V_431 ;
struct V_206 * V_207 ;
struct V_432 * V_263 ;
struct V_435 * V_436 = V_105 -> V_437 ;
struct V_107 * V_107 = F_250 ( V_105 ) ;
++ V_436 -> V_441 ;
++ V_436 -> V_205 ;
if ( V_436 -> V_442 == V_462 ) {
V_207 = V_431 ;
V_207 = F_245 ( V_207 ) ;
V_465:
while ( V_207 && ( V_207 -> V_463 != V_436 -> V_245 || ! F_258 ( F_267 ( V_207 ) , V_107 ) ) ) {
V_207 = F_245 ( V_207 ) ;
}
if ( V_207 ) {
V_431 = V_207 ;
goto V_117;
}
F_260 ( F_264 ( & V_111 , V_436 -> V_439 ) ) ;
V_436 -> V_442 = V_464 ;
V_436 -> V_205 = 0 ;
while ( ++ V_436 -> V_439 <= V_111 . V_461 &&
F_262 ( V_436 ) )
;
if ( V_436 -> V_439 > V_111 . V_461 )
return NULL ;
F_251 ( F_264 ( & V_111 , V_436 -> V_439 ) ) ;
V_8 = F_252 ( & V_111 . V_458 [ V_436 -> V_439 ] . V_459 ) ;
} else
V_8 = F_253 ( V_8 ) ;
F_257 (sk, node) {
if ( V_8 -> V_453 == V_436 -> V_245 && F_258 ( F_19 ( V_8 ) , V_107 ) )
goto V_466;
}
V_436 -> V_442 = V_462 ;
V_207 = F_242 ( & V_111 . V_458 [ V_436 -> V_439 ] . V_460 ) ;
goto V_465;
V_466:
V_431 = V_8 ;
V_117:
return V_431 ;
}
static void * F_269 ( struct V_430 * V_105 , T_11 V_456 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
void * V_457 ;
V_436 -> V_439 = 0 ;
V_457 = F_263 ( V_105 ) ;
while ( V_457 && V_456 ) {
V_457 = F_268 ( V_105 , V_457 ) ;
-- V_456 ;
}
return V_457 ;
}
static void * F_270 ( struct V_430 * V_105 , T_11 V_456 )
{
void * V_457 ;
struct V_435 * V_436 = V_105 -> V_437 ;
V_436 -> V_442 = V_450 ;
V_457 = F_261 ( V_105 , & V_456 ) ;
if ( ! V_457 ) {
V_436 -> V_442 = V_464 ;
V_457 = F_269 ( V_105 , V_456 ) ;
}
return V_457 ;
}
static void * F_271 ( struct V_430 * V_105 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
int V_205 = V_436 -> V_205 ;
int V_467 = V_436 -> V_441 ;
void * V_457 = NULL ;
switch ( V_436 -> V_442 ) {
case V_443 :
case V_450 :
if ( V_436 -> V_439 >= V_455 )
break;
V_436 -> V_442 = V_450 ;
V_457 = F_249 ( V_105 , NULL ) ;
while ( V_205 -- && V_457 )
V_457 = F_249 ( V_105 , V_457 ) ;
if ( V_457 )
break;
V_436 -> V_439 = 0 ;
case V_464 :
case V_462 :
V_436 -> V_442 = V_464 ;
if ( V_436 -> V_439 > V_111 . V_461 )
break;
V_457 = F_263 ( V_105 ) ;
while ( V_205 -- && V_457 )
V_457 = F_268 ( V_105 , V_457 ) ;
}
V_436 -> V_441 = V_467 ;
return V_457 ;
}
static void * F_272 ( struct V_430 * V_105 , T_11 * V_456 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
void * V_457 ;
if ( * V_456 && * V_456 == V_436 -> V_468 ) {
V_457 = F_271 ( V_105 ) ;
if ( V_457 )
goto V_117;
}
V_436 -> V_442 = V_450 ;
V_436 -> V_441 = 0 ;
V_436 -> V_439 = 0 ;
V_436 -> V_205 = 0 ;
V_457 = * V_456 ? F_270 ( V_105 , * V_456 - 1 ) : V_469 ;
V_117:
V_436 -> V_468 = * V_456 ;
return V_457 ;
}
static void * F_273 ( struct V_430 * V_105 , void * V_470 , T_11 * V_456 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
void * V_457 = NULL ;
if ( V_470 == V_469 ) {
V_457 = F_270 ( V_105 , 0 ) ;
goto V_117;
}
switch ( V_436 -> V_442 ) {
case V_443 :
case V_450 :
V_457 = F_249 ( V_105 , V_470 ) ;
if ( ! V_457 ) {
V_436 -> V_442 = V_464 ;
V_436 -> V_439 = 0 ;
V_436 -> V_205 = 0 ;
V_457 = F_263 ( V_105 ) ;
}
break;
case V_464 :
case V_462 :
V_457 = F_268 ( V_105 , V_470 ) ;
break;
}
V_117:
++ * V_456 ;
V_436 -> V_468 = * V_456 ;
return V_457 ;
}
static void F_274 ( struct V_430 * V_105 , void * V_470 )
{
struct V_435 * V_436 = V_105 -> V_437 ;
switch ( V_436 -> V_442 ) {
case V_443 :
if ( V_470 ) {
struct V_100 * V_101 = F_23 ( V_436 -> V_444 ) ;
F_254 ( & V_101 -> V_237 . V_451 ) ;
}
case V_450 :
if ( V_470 != V_469 )
F_260 ( & V_111 . V_438 [ V_436 -> V_439 ] . V_312 ) ;
break;
case V_462 :
case V_464 :
if ( V_470 )
F_260 ( F_264 ( & V_111 , V_436 -> V_439 ) ) ;
break;
}
}
int F_275 ( struct V_471 * V_471 , struct V_472 * V_472 )
{
struct V_473 * V_474 = F_276 ( V_471 ) -> V_96 ;
struct V_435 * V_475 ;
int V_37 ;
V_37 = F_277 ( V_471 , V_472 , & V_474 -> V_476 ,
sizeof( struct V_435 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_475 = ( (struct V_430 * ) V_472 -> V_477 ) -> V_437 ;
V_475 -> V_245 = V_474 -> V_245 ;
V_475 -> V_468 = 0 ;
return 0 ;
}
int F_278 ( struct V_107 * V_107 , struct V_473 * V_474 )
{
int V_457 = 0 ;
struct V_478 * V_479 ;
V_474 -> V_476 . V_480 = F_272 ;
V_474 -> V_476 . V_429 = F_273 ;
V_474 -> V_476 . V_481 = F_274 ;
V_479 = F_279 ( V_474 -> V_482 , V_483 , V_107 -> V_484 ,
V_474 -> V_485 , V_474 ) ;
if ( ! V_479 )
V_457 = - V_261 ;
return V_457 ;
}
void F_280 ( struct V_107 * V_107 , struct V_473 * V_474 )
{
F_281 ( V_474 -> V_482 , V_107 -> V_484 ) ;
}
static void F_282 ( const struct V_7 * V_8 , const struct V_103 * V_104 ,
struct V_430 * V_486 , int V_487 , T_13 V_454 , int * V_109 )
{
const struct V_222 * V_223 = F_95 ( V_104 ) ;
long V_488 = V_104 -> V_314 - V_79 ;
F_283 ( V_486 , L_9
L_10 ,
V_487 ,
V_223 -> V_224 ,
F_81 ( F_11 ( V_8 ) -> V_49 ) ,
V_223 -> V_225 ,
F_81 ( V_223 -> V_489 ) ,
V_151 ,
0 , 0 ,
1 ,
F_284 ( V_488 ) ,
V_104 -> V_326 ,
F_285 ( F_286 ( V_486 ) , V_454 ) ,
0 ,
0 ,
F_287 ( & V_8 -> V_490 ) ,
V_104 ,
V_109 ) ;
}
static void F_288 ( struct V_7 * V_8 , struct V_430 * V_486 , int V_487 , int * V_109 )
{
int V_491 ;
unsigned long V_492 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_100 * V_101 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_301 * V_302 = V_101 -> V_237 . V_302 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_493 = V_29 -> V_63 ;
T_14 V_494 = F_81 ( V_29 -> V_69 ) ;
T_14 V_495 = F_81 ( V_29 -> V_49 ) ;
int V_496 ;
if ( V_101 -> V_497 == V_145 ) {
V_491 = 1 ;
V_492 = V_101 -> V_498 ;
} else if ( V_101 -> V_497 == V_499 ) {
V_491 = 4 ;
V_492 = V_101 -> V_498 ;
} else if ( F_289 ( & V_8 -> V_500 ) ) {
V_491 = 2 ;
V_492 = V_8 -> V_500 . V_314 ;
} else {
V_491 = 0 ;
V_492 = V_79 ;
}
if ( V_8 -> V_112 == V_122 )
V_496 = V_8 -> V_501 ;
else
V_496 = F_290 ( int , V_14 -> V_215 - V_14 -> V_502 , 0 ) ;
F_283 ( V_486 , L_11
L_12 ,
V_487 , V_493 , V_495 , V_5 , V_494 , V_8 -> V_112 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_496 ,
V_491 ,
F_284 ( V_492 - V_79 ) ,
V_101 -> V_138 ,
F_285 ( F_286 ( V_486 ) , F_259 ( V_8 ) ) ,
V_101 -> V_503 ,
F_291 ( V_8 ) ,
F_287 ( & V_8 -> V_490 ) , V_8 ,
F_292 ( V_101 -> V_140 ) ,
F_292 ( V_101 -> V_504 . V_505 ) ,
( V_101 -> V_504 . V_506 << 1 ) | V_101 -> V_504 . V_507 ,
V_14 -> V_508 ,
V_8 -> V_112 == V_122 ?
( V_302 ? V_302 -> V_309 : 0 ) :
( F_293 ( V_14 ) ? - 1 : V_14 -> V_509 ) ,
V_109 ) ;
}
static void F_294 ( const struct V_206 * V_207 ,
struct V_430 * V_486 , int V_487 , int * V_109 )
{
T_3 V_5 , V_493 ;
T_14 V_494 , V_495 ;
long V_488 = V_207 -> V_510 - V_79 ;
V_5 = V_207 -> V_511 ;
V_493 = V_207 -> V_512 ;
V_494 = F_81 ( V_207 -> V_513 ) ;
V_495 = F_81 ( V_207 -> V_514 ) ;
F_283 ( V_486 , L_9
L_13 ,
V_487 , V_493 , V_495 , V_5 , V_494 , V_207 -> V_515 , 0 , 0 ,
3 , F_284 ( V_488 ) , 0 , 0 , 0 , 0 ,
F_287 ( & V_207 -> V_516 ) , V_207 , V_109 ) ;
}
static int F_295 ( struct V_430 * V_105 , void * V_470 )
{
struct V_435 * V_436 ;
int V_109 ;
if ( V_470 == V_469 ) {
F_283 ( V_105 , L_14 , V_517 - 1 ,
L_15
L_16
L_17 ) ;
goto V_117;
}
V_436 = V_105 -> V_437 ;
switch ( V_436 -> V_442 ) {
case V_450 :
case V_464 :
F_288 ( V_470 , V_105 , V_436 -> V_441 , & V_109 ) ;
break;
case V_443 :
F_282 ( V_436 -> V_444 , V_470 , V_105 , V_436 -> V_441 , V_436 -> V_454 , & V_109 ) ;
break;
case V_462 :
F_294 ( V_470 , V_105 , V_436 -> V_441 , & V_109 ) ;
break;
}
F_283 ( V_105 , L_18 , V_517 - 1 - V_109 , L_6 ) ;
V_117:
return 0 ;
}
static int T_15 F_296 ( struct V_107 * V_107 )
{
return F_278 ( V_107 , & V_518 ) ;
}
static void T_16 F_297 ( struct V_107 * V_107 )
{
F_280 ( V_107 , & V_518 ) ;
}
int T_17 F_298 ( void )
{
return F_299 ( & V_519 ) ;
}
void F_300 ( void )
{
F_301 ( & V_519 ) ;
}
struct V_1 * * F_302 ( struct V_1 * * V_159 , struct V_1 * V_2 )
{
const struct V_94 * V_95 = F_303 ( V_2 ) ;
T_18 V_520 ;
T_10 V_521 ;
switch ( V_2 -> V_155 ) {
case V_381 :
if ( ! F_67 ( F_304 ( V_2 ) , V_95 -> V_4 , V_95 -> V_3 ,
V_2 -> V_162 ) ) {
V_2 -> V_155 = V_382 ;
break;
}
V_522:
F_305 ( V_2 ) -> V_522 = 1 ;
return NULL ;
case V_523 :
V_520 = F_86 ( V_95 -> V_4 , V_95 -> V_3 ,
F_304 ( V_2 ) , V_57 , 0 ) ;
V_521 = F_306 ( F_307 ( V_2 ,
F_308 ( V_2 ) ,
F_304 ( V_2 ) ,
V_520 ) ) ;
if ( V_521 )
goto V_522;
V_2 -> V_155 = V_382 ;
break;
}
return F_309 ( V_159 , V_2 ) ;
}
int F_310 ( struct V_1 * V_2 )
{
const struct V_94 * V_95 = F_3 ( V_2 ) ;
struct V_97 * V_98 = F_4 ( V_2 ) ;
V_98 -> V_157 = ~ F_67 ( V_2 -> V_109 - F_210 ( V_2 ) ,
V_95 -> V_4 , V_95 -> V_3 , 0 ) ;
F_311 ( V_2 ) -> V_524 = V_77 ;
return F_312 ( V_2 ) ;
}
static int T_15 F_313 ( struct V_107 * V_107 )
{
V_107 -> V_525 . V_526 = 2 ;
return 0 ;
}
static void T_16 F_314 ( struct V_107 * V_107 )
{
}
static void T_16 F_315 ( struct V_527 * V_528 )
{
F_316 ( & V_111 , & V_66 , V_42 ) ;
}
void T_17 F_317 ( void )
{
F_318 ( & V_111 ) ;
if ( F_299 ( & V_529 ) )
F_319 ( L_19 ) ;
}
