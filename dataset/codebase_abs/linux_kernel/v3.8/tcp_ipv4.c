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
if ( V_8 -> V_85 == V_86 )
return;
V_68 = F_30 ( V_8 , V_83 ) ;
if ( ! V_68 )
return;
if ( V_83 < F_31 ( V_68 ) && F_32 ( V_8 , V_68 ) )
V_8 -> V_87 = V_88 ;
V_83 = F_31 ( V_68 ) ;
if ( V_29 -> V_89 != V_90 &&
F_23 ( V_8 ) -> V_91 > V_83 ) {
F_33 ( V_8 , V_83 ) ;
F_34 ( V_8 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_82 * V_68 = F_36 ( V_8 , 0 ) ;
if ( V_68 )
V_68 -> V_92 -> V_93 ( V_68 , V_8 , V_2 ) ;
}
void F_37 ( struct V_1 * V_94 , T_4 V_95 )
{
const struct V_96 * V_97 = ( const struct V_96 * ) V_94 -> V_98 ;
struct V_99 * V_100 = (struct V_99 * ) ( V_94 -> V_98 + ( V_97 -> V_101 << 2 ) ) ;
struct V_102 * V_103 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_38 ( V_94 ) -> type ;
const int V_104 = F_38 ( V_94 ) -> V_104 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
T_1 V_107 ;
T_1 V_108 ;
int V_37 ;
struct V_109 * V_109 = F_39 ( V_94 -> V_110 ) ;
if ( V_94 -> V_111 < ( V_97 -> V_101 << 2 ) + 8 ) {
F_40 ( V_109 , V_112 ) ;
return;
}
V_8 = F_41 ( V_109 , & V_113 , V_97 -> V_3 , V_100 -> V_5 ,
V_97 -> V_4 , V_100 -> V_6 , F_42 ( V_94 ) ) ;
if ( ! V_8 ) {
F_40 ( V_109 , V_112 ) ;
return;
}
if ( V_8 -> V_85 == V_114 ) {
F_43 ( F_44 ( V_8 ) ) ;
return;
}
F_45 ( V_8 ) ;
if ( F_13 ( V_8 ) ) {
if ( ! ( type == V_115 && V_104 == V_116 ) )
F_46 ( V_109 , V_117 ) ;
}
if ( V_8 -> V_85 == V_80 )
goto V_118;
if ( F_47 ( V_97 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_46 ( V_109 , V_121 ) ;
goto V_118;
}
V_103 = F_23 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_106 = V_14 -> V_122 ;
V_107 = F_48 ( V_100 -> V_107 ) ;
if ( V_8 -> V_85 != V_86 &&
! F_49 ( V_107 , V_14 -> V_123 , V_14 -> V_124 ) &&
( V_106 == NULL || V_107 != F_50 ( V_106 ) -> V_125 ) ) {
F_46 ( V_109 , V_126 ) ;
goto V_118;
}
switch ( type ) {
case V_127 :
F_35 ( V_94 , V_8 ) ;
goto V_118;
case V_128 :
goto V_118;
case V_129 :
V_37 = V_130 ;
break;
case V_115 :
if ( V_104 > V_131 )
goto V_118;
if ( V_104 == V_116 ) {
V_14 -> V_84 = V_95 ;
if ( ! F_13 ( V_8 ) ) {
F_29 ( V_8 ) ;
} else {
if ( ! F_51 ( V_132 , & V_14 -> V_133 ) )
F_9 ( V_8 ) ;
}
goto V_118;
}
V_37 = V_134 [ V_104 ] . V_135 ;
if ( V_104 != V_136 && V_104 != V_137 )
break;
if ( V_107 != V_14 -> V_123 || ! V_103 -> V_138 ||
! V_103 -> V_139 )
break;
if ( F_13 ( V_8 ) )
break;
V_103 -> V_139 -- ;
F_23 ( V_8 ) -> V_140 = ( V_14 -> V_141 ? F_52 ( V_14 ) :
V_142 ) << V_103 -> V_139 ;
F_53 ( V_8 ) ;
V_2 = F_54 ( V_8 ) ;
F_55 ( ! V_2 ) ;
V_108 = V_103 -> V_140 - F_56 ( V_103 -> V_140 ,
V_143 - F_57 ( V_2 ) -> V_144 ) ;
if ( V_108 ) {
F_58 ( V_8 , V_145 ,
V_108 , V_146 ) ;
} else {
F_59 ( V_8 ) ;
}
break;
case V_147 :
V_37 = V_148 ;
break;
default:
goto V_118;
}
if ( V_106 && V_106 -> V_8 == NULL )
goto V_118;
switch ( V_8 -> V_85 ) {
struct V_105 * V_106 , * * V_149 ;
case V_86 :
if ( F_13 ( V_8 ) )
goto V_118;
V_106 = F_60 ( V_8 , & V_149 , V_100 -> V_5 ,
V_97 -> V_3 , V_97 -> V_4 ) ;
if ( ! V_106 )
goto V_118;
F_61 ( V_106 -> V_8 ) ;
if ( V_107 != F_50 ( V_106 ) -> V_125 ) {
F_46 ( V_109 , V_126 ) ;
goto V_118;
}
F_62 ( V_8 , V_106 , V_149 ) ;
F_46 ( F_19 ( V_8 ) , V_150 ) ;
goto V_118;
case V_74 :
case V_151 :
if ( ! F_13 ( V_8 ) ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
F_63 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
goto V_118;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_13 ( V_8 ) && V_29 -> V_154 ) {
V_8 -> V_152 = V_37 ;
V_8 -> V_153 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
V_118:
F_64 ( V_8 ) ;
F_65 ( V_8 ) ;
}
static void F_66 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
if ( V_2 -> V_155 == V_156 ) {
V_100 -> V_157 = ~ F_67 ( V_2 -> V_111 , V_4 , V_3 , 0 ) ;
V_2 -> V_158 = F_68 ( V_2 ) - V_2 -> V_159 ;
V_2 -> V_160 = F_69 ( struct V_99 , V_157 ) ;
} else {
V_100 -> V_157 = F_67 ( V_2 -> V_111 , V_4 , V_3 ,
F_70 ( V_100 ,
V_100 -> V_161 << 2 ,
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
const struct V_96 * V_97 ;
struct V_99 * V_100 ;
if ( ! F_73 ( V_2 , sizeof( * V_100 ) ) )
return - V_40 ;
V_97 = F_3 ( V_2 ) ;
V_100 = F_4 ( V_2 ) ;
V_100 -> V_157 = 0 ;
V_2 -> V_155 = V_156 ;
F_66 ( V_2 , V_97 -> V_4 , V_97 -> V_3 ) ;
return 0 ;
}
static void F_74 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
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
struct V_109 * V_109 ;
if ( V_100 -> V_173 )
return;
if ( F_76 ( V_2 ) -> V_174 != V_175 )
return;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_100 . V_5 = V_100 -> V_6 ;
V_164 . V_100 . V_6 = V_100 -> V_5 ;
V_164 . V_100 . V_161 = sizeof( struct V_99 ) / 4 ;
V_164 . V_100 . V_173 = 1 ;
if ( V_100 -> V_176 ) {
V_164 . V_100 . V_107 = V_100 -> V_177 ;
} else {
V_164 . V_100 . V_176 = 1 ;
V_164 . V_100 . V_177 = F_77 ( F_48 ( V_100 -> V_107 ) + V_100 -> V_178 + V_100 -> V_179 +
V_2 -> V_111 - ( V_100 -> V_161 << 2 ) ) ;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_100 ) ;
#ifdef F_75
V_169 = F_78 ( V_100 ) ;
if ( ! V_8 && V_169 ) {
V_172 = F_79 ( F_39 ( F_80 ( V_2 ) -> V_110 ) ,
& V_113 , F_3 ( V_2 ) -> V_3 ,
F_81 ( V_100 -> V_6 ) , F_42 ( V_2 ) ) ;
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
V_164 . V_100 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_85 ( ( T_5 * ) & V_164 . V_46 [ 1 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_100 ) ;
}
#endif
V_166 . V_162 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_69 ( struct V_99 , V_157 ) / 2 ;
V_166 . V_189 = ( V_8 && F_11 ( V_8 ) -> V_190 ) ? V_191 : 0 ;
if ( V_8 )
V_166 . V_192 = V_8 -> V_56 ;
V_109 = F_39 ( F_80 ( V_2 ) -> V_110 ) ;
V_166 . V_193 = F_3 ( V_2 ) -> V_193 ;
F_87 ( V_109 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_88 ( V_109 , V_194 ) ;
F_88 ( V_109 , V_195 ) ;
#ifdef F_75
V_184:
if ( V_172 ) {
F_89 () ;
F_65 ( V_172 ) ;
}
#endif
}
static void F_90 ( struct V_1 * V_2 , T_4 V_107 , T_4 V_176 ,
T_4 V_196 , T_4 V_197 , int V_198 ,
struct V_167 * V_168 ,
int V_199 , T_6 V_193 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
T_3 V_46 [ ( V_200 >> 2 )
#ifdef F_75
+ ( V_163 >> 2 )
#endif
] ;
} V_164 ;
struct V_165 V_166 ;
struct V_109 * V_109 = F_39 ( F_80 ( V_2 ) -> V_110 ) ;
memset ( & V_164 . V_100 , 0 , sizeof( struct V_99 ) ) ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_180 [ 0 ] . V_181 = ( unsigned char * ) & V_164 ;
V_166 . V_180 [ 0 ] . V_182 = sizeof( V_164 . V_100 ) ;
if ( V_197 ) {
V_164 . V_46 [ 0 ] = F_77 ( ( V_185 << 24 ) | ( V_185 << 16 ) |
( V_201 << 8 ) |
V_202 ) ;
V_164 . V_46 [ 1 ] = F_77 ( V_143 ) ;
V_164 . V_46 [ 2 ] = F_77 ( V_197 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_200 ;
}
V_164 . V_100 . V_5 = V_100 -> V_6 ;
V_164 . V_100 . V_6 = V_100 -> V_5 ;
V_164 . V_100 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
V_164 . V_100 . V_107 = F_77 ( V_107 ) ;
V_164 . V_100 . V_177 = F_77 ( V_176 ) ;
V_164 . V_100 . V_176 = 1 ;
V_164 . V_100 . V_203 = F_91 ( V_196 ) ;
#ifdef F_75
if ( V_168 ) {
int V_204 = ( V_197 ) ? 3 : 0 ;
V_164 . V_46 [ V_204 ++ ] = F_77 ( ( V_185 << 24 ) |
( V_185 << 16 ) |
( V_186 << 8 ) |
V_187 ) ;
V_166 . V_180 [ 0 ] . V_182 += V_163 ;
V_164 . V_100 . V_161 = V_166 . V_180 [ 0 ] . V_182 / 4 ;
F_85 ( ( T_5 * ) & V_164 . V_46 [ V_204 ] ,
V_168 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 . V_100 ) ;
}
#endif
V_166 . V_189 = V_199 ;
V_166 . V_162 = F_86 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_166 . V_180 [ 0 ] . V_182 , V_57 , 0 ) ;
V_166 . V_188 = F_69 ( struct V_99 , V_157 ) / 2 ;
if ( V_198 )
V_166 . V_192 = V_198 ;
V_166 . V_193 = V_193 ;
F_87 ( V_109 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_166 , V_166 . V_180 [ 0 ] . V_182 ) ;
F_88 ( V_109 , V_194 ) ;
}
static void F_92 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_205 * V_206 = F_44 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_90 ( V_2 , V_12 -> V_18 , V_12 -> V_207 ,
V_12 -> V_208 >> V_206 -> V_209 ,
V_12 -> V_21 ,
V_206 -> V_210 ,
F_93 ( V_12 ) ,
V_206 -> V_211 ? V_191 : 0 ,
V_206 -> V_212
) ;
F_43 ( V_206 ) ;
}
static void F_94 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 )
{
F_90 ( V_2 , ( V_8 -> V_85 == V_86 ) ?
F_50 ( V_106 ) -> V_125 + 1 : F_7 ( V_8 ) -> V_124 ,
F_50 ( V_106 ) -> V_213 , V_106 -> V_214 ,
V_106 -> V_20 ,
0 ,
F_83 ( V_8 , (union V_183 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_95 ( V_106 ) -> V_215 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_193 ) ;
}
static int F_96 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_105 * V_106 ,
struct V_216 * V_217 ,
T_7 V_218 ,
bool V_219 )
{
const struct V_220 * V_221 = F_95 ( V_106 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_97 ( V_8 , & V_34 , V_106 ) ) == NULL )
return - 1 ;
V_2 = F_98 ( V_8 , V_68 , V_106 , V_217 , NULL ) ;
if ( V_2 ) {
F_66 ( V_2 , V_221 -> V_222 , V_221 -> V_223 ) ;
F_99 ( V_2 , V_218 ) ;
V_37 = F_100 ( V_2 , V_8 , V_221 -> V_222 ,
V_221 -> V_223 ,
V_221 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( ! F_50 ( V_106 ) -> V_224 && ! V_37 )
F_50 ( V_106 ) -> V_224 = V_143 ;
}
return V_37 ;
}
static int F_102 ( struct V_7 * V_8 , struct V_105 * V_106 ,
struct V_216 * V_217 )
{
int V_225 = F_96 ( V_8 , NULL , V_106 , V_217 , 0 , false ) ;
if ( ! V_225 )
F_88 ( F_19 ( V_8 ) , V_226 ) ;
return V_225 ;
}
static void F_103 ( struct V_105 * V_106 )
{
F_104 ( F_95 ( V_106 ) -> V_46 ) ;
}
bool F_105 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_227 )
{
const char * V_228 = L_1 ;
bool V_229 = false ;
struct V_230 * V_231 ;
#ifdef F_106
if ( V_232 ) {
V_228 = L_2 ;
V_229 = true ;
F_46 ( F_19 ( V_8 ) , V_233 ) ;
} else
#endif
F_46 ( F_19 ( V_8 ) , V_234 ) ;
V_231 = F_23 ( V_8 ) -> V_235 . V_236 ;
if ( ! V_231 -> V_237 ) {
V_231 -> V_237 = 1 ;
F_107 ( L_3 ,
V_227 , F_81 ( F_4 ( V_2 ) -> V_5 ) , V_228 ) ;
}
return V_229 ;
}
static struct V_38 * F_108 ( struct V_1 * V_2 )
{
const struct V_238 * V_46 = & ( F_109 ( V_2 ) -> V_46 ) ;
struct V_38 * V_239 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_240 = sizeof( * V_239 ) + V_46 -> V_71 ;
V_239 = F_110 ( V_240 , V_241 ) ;
if ( V_239 ) {
if ( F_111 ( & V_239 -> V_46 , V_2 ) ) {
F_104 ( V_239 ) ;
V_239 = NULL ;
}
}
}
return V_239 ;
}
struct V_167 * F_83 ( struct V_7 * V_8 ,
const union V_183 * V_242 ,
int V_243 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_244 * V_245 ;
unsigned int V_246 = sizeof( struct V_247 ) ;
struct V_248 * V_249 ;
V_249 = F_112 ( V_14 -> V_250 ,
F_13 ( V_8 ) ||
F_113 ( & V_8 -> V_251 . V_252 ) ) ;
if ( ! V_249 )
return NULL ;
#if F_114 ( V_253 )
if ( V_243 == V_254 )
V_246 = sizeof( struct V_255 ) ;
#endif
F_115 (key, pos, &md5sig->head, node) {
if ( V_168 -> V_243 != V_243 )
continue;
if ( ! memcmp ( & V_168 -> V_242 , V_242 , V_246 ) )
return V_168 ;
}
return NULL ;
}
struct V_167 * F_116 ( struct V_7 * V_8 ,
struct V_7 * V_256 )
{
union V_183 * V_242 ;
V_242 = (union V_183 * ) & F_11 ( V_256 ) -> V_64 ;
return F_83 ( V_8 , V_242 , V_42 ) ;
}
static struct V_167 * F_117 ( struct V_7 * V_8 ,
struct V_105 * V_106 )
{
union V_183 * V_242 ;
V_242 = (union V_183 * ) & F_95 ( V_106 ) -> V_223 ;
return F_83 ( V_8 , V_242 , V_42 ) ;
}
int F_118 ( struct V_7 * V_8 , const union V_183 * V_242 ,
int V_243 , const T_6 * V_257 , T_6 V_258 , T_8 V_259 )
{
struct V_167 * V_168 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_248 * V_249 ;
V_168 = F_83 ( V_8 , (union V_183 * ) & V_242 , V_42 ) ;
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
V_168 -> V_243 = V_243 ;
memcpy ( & V_168 -> V_242 , V_242 ,
( V_243 == V_254 ) ? sizeof( struct V_255 ) :
sizeof( struct V_247 ) ) ;
F_126 ( & V_168 -> V_263 , & V_249 -> V_159 ) ;
return 0 ;
}
int F_127 ( struct V_7 * V_8 , const union V_183 * V_242 , int V_243 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_167 * V_168 ;
struct V_248 * V_249 ;
V_168 = F_83 ( V_8 , (union V_183 * ) & V_242 , V_42 ) ;
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
struct V_244 * V_245 , * V_267 ;
struct V_248 * V_249 ;
V_249 = F_12 ( V_14 -> V_250 , 1 ) ;
if ( ! F_123 ( & V_249 -> V_159 ) )
F_131 () ;
F_133 (key, pos, n, &md5sig->head, node) {
F_128 ( & V_168 -> V_263 ) ;
F_129 ( sizeof( * V_168 ) , & V_8 -> V_265 ) ;
F_130 ( V_168 , V_266 ) ;
}
}
static int F_134 ( struct V_7 * V_8 , char T_9 * V_268 ,
int V_71 )
{
struct V_269 V_270 ;
struct V_26 * sin = (struct V_26 * ) & V_270 . V_271 ;
if ( V_71 < sizeof( V_270 ) )
return - V_40 ;
if ( F_135 ( & V_270 , V_268 , sizeof( V_270 ) ) )
return - V_272 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_270 . V_273 || ! V_270 . V_274 )
return F_127 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_270 . V_274 > V_275 )
return - V_40 ;
return F_118 ( V_8 , (union V_183 * ) & sin -> V_44 . V_45 ,
V_42 , V_270 . V_273 , V_270 . V_274 ,
V_276 ) ;
}
static int F_136 ( struct V_277 * V_278 ,
T_3 V_3 , T_3 V_4 , int V_279 )
{
struct V_280 * V_281 ;
struct V_282 V_283 ;
V_281 = & V_278 -> V_284 . V_54 ;
V_281 -> V_4 = V_4 ;
V_281 -> V_3 = V_3 ;
V_281 -> V_285 = 0 ;
V_281 -> V_286 = V_57 ;
V_281 -> V_111 = F_137 ( V_279 ) ;
F_138 ( & V_283 , V_281 , sizeof( * V_281 ) ) ;
return F_139 ( & V_278 -> V_287 , & V_283 , sizeof( * V_281 ) ) ;
}
static int F_85 ( char * V_288 , const struct V_167 * V_168 ,
T_3 V_3 , T_3 V_4 , const struct V_99 * V_100 )
{
struct V_277 * V_278 ;
struct V_289 * V_290 ;
V_278 = F_140 () ;
if ( ! V_278 )
goto V_291;
V_290 = & V_278 -> V_287 ;
if ( F_141 ( V_290 ) )
goto V_292;
if ( F_136 ( V_278 , V_3 , V_4 , V_100 -> V_161 << 2 ) )
goto V_292;
if ( F_142 ( V_278 , V_100 ) )
goto V_292;
if ( F_143 ( V_278 , V_168 ) )
goto V_292;
if ( F_144 ( V_290 , V_288 ) )
goto V_292;
F_145 () ;
return 0 ;
V_292:
F_145 () ;
V_291:
memset ( V_288 , 0 , 16 ) ;
return 1 ;
}
int F_84 ( char * V_288 , struct V_167 * V_168 ,
const struct V_7 * V_8 , const struct V_105 * V_106 ,
const struct V_1 * V_2 )
{
struct V_277 * V_278 ;
struct V_289 * V_290 ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_11 ( V_8 ) -> V_55 ;
V_3 = F_11 ( V_8 ) -> V_64 ;
} else if ( V_106 ) {
V_4 = F_95 ( V_106 ) -> V_222 ;
V_3 = F_95 ( V_106 ) -> V_223 ;
} else {
const struct V_96 * V_97 = F_3 ( V_2 ) ;
V_4 = V_97 -> V_4 ;
V_3 = V_97 -> V_3 ;
}
V_278 = F_140 () ;
if ( ! V_278 )
goto V_291;
V_290 = & V_278 -> V_287 ;
if ( F_141 ( V_290 ) )
goto V_292;
if ( F_136 ( V_278 , V_3 , V_4 , V_2 -> V_111 ) )
goto V_292;
if ( F_142 ( V_278 , V_100 ) )
goto V_292;
if ( F_146 ( V_278 , V_2 , V_100 -> V_161 << 2 ) )
goto V_292;
if ( F_143 ( V_278 , V_168 ) )
goto V_292;
if ( F_144 ( V_290 , V_288 ) )
goto V_292;
F_145 () ;
return 0 ;
V_292:
F_145 () ;
V_291:
memset ( V_288 , 0 , 16 ) ;
return 1 ;
}
static bool F_147 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_169 = NULL ;
struct V_167 * V_293 ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
int V_171 ;
unsigned char V_170 [ 16 ] ;
V_293 = F_83 ( V_8 , (union V_183 * ) & V_97 -> V_4 ,
V_42 ) ;
V_169 = F_78 ( V_100 ) ;
if ( ! V_293 && ! V_169 )
return false ;
if ( V_293 && ! V_169 ) {
F_46 ( F_19 ( V_8 ) , V_294 ) ;
return true ;
}
if ( ! V_293 && V_169 ) {
F_46 ( F_19 ( V_8 ) , V_295 ) ;
return true ;
}
V_171 = F_84 ( V_170 ,
V_293 ,
NULL , NULL , V_2 ) ;
if ( V_171 || memcmp ( V_169 , V_170 , 16 ) != 0 ) {
F_148 ( L_4 ,
& V_97 -> V_4 , F_81 ( V_100 -> V_6 ) ,
& V_97 -> V_3 , F_81 ( V_100 -> V_5 ) ,
V_171 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
static bool F_149 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_296 * V_297 ,
struct V_296 * V_298 )
{
bool V_299 = false ;
struct V_300 * V_301 ;
if ( F_21 ( ! F_150 ( V_297 ) ) ) {
if ( ( V_302 & V_303 ) ||
( ( V_302 & V_304 ) &&
( F_57 ( V_2 ) -> V_305 != F_57 ( V_2 ) -> V_107 + 1 ) ) )
V_299 = true ;
else
return false ;
}
V_301 = F_23 ( V_8 ) -> V_235 . V_301 ;
F_46 ( F_19 ( V_8 ) , V_306 ) ;
if ( ( V_302 & V_307 ) == 0 ||
V_301 == NULL || V_301 -> V_308 == 0 )
return false ;
if ( V_301 -> V_309 >= V_301 -> V_308 ) {
struct V_105 * V_310 ;
F_151 ( & V_301 -> V_311 ) ;
V_310 = V_301 -> V_312 ;
if ( ( V_310 == NULL ) || F_152 ( V_310 -> V_313 , V_79 ) ) {
F_153 ( & V_301 -> V_311 ) ;
F_46 ( F_19 ( V_8 ) ,
V_314 ) ;
V_297 -> V_111 = - 1 ;
return false ;
}
V_301 -> V_312 = V_310 -> V_315 ;
V_301 -> V_309 -- ;
F_153 ( & V_301 -> V_311 ) ;
F_154 ( V_310 ) ;
}
if ( V_299 ) {
F_50 ( V_106 ) -> V_213 = F_57 ( V_2 ) -> V_305 ;
return true ;
}
if ( V_297 -> V_111 == V_316 ) {
if ( ( V_302 & V_317 ) == 0 ) {
F_155 ( F_3 ( V_2 ) -> V_4 , V_298 ) ;
if ( ( V_298 -> V_111 != V_316 ) ||
memcmp ( & V_297 -> V_318 [ 0 ] , & V_298 -> V_318 [ 0 ] ,
V_316 ) != 0 )
return false ;
V_298 -> V_111 = - 1 ;
}
F_50 ( V_106 ) -> V_213 = F_57 ( V_2 ) -> V_305 ;
return true ;
} else if ( V_297 -> V_111 == 0 ) {
F_155 ( F_3 ( V_2 ) -> V_4 , V_298 ) ;
F_46 ( F_19 ( V_8 ) ,
V_319 ) ;
} else {
F_155 ( F_3 ( V_2 ) -> V_4 , V_298 ) ;
}
return false ;
}
static int F_156 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_1 * V_320 ,
struct V_105 * V_106 ,
struct V_216 * V_217 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_321 * V_322 = & F_23 ( V_8 ) -> V_235 ;
const struct V_220 * V_221 = F_95 ( V_106 ) ;
struct V_7 * V_323 ;
int V_37 ;
V_106 -> V_324 = 0 ;
V_106 -> V_325 = 0 ;
V_106 -> V_8 = NULL ;
V_323 = F_23 ( V_8 ) -> V_326 -> V_327 ( V_8 , V_2 , V_106 , NULL ) ;
if ( V_323 == NULL ) {
F_46 ( F_19 ( V_8 ) ,
V_328 ) ;
F_157 ( V_320 ) ;
return - 1 ;
}
V_37 = F_100 ( V_320 , V_8 , V_221 -> V_222 ,
V_221 -> V_223 , V_221 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( ! V_37 )
F_50 ( V_106 ) -> V_224 = V_143 ;
F_151 ( & V_322 -> V_301 -> V_311 ) ;
V_322 -> V_301 -> V_309 ++ ;
F_153 ( & V_322 -> V_301 -> V_311 ) ;
V_14 = F_7 ( V_323 ) ;
V_14 -> V_122 = V_106 ;
F_9 ( V_8 ) ;
F_50 ( V_106 ) -> V_329 = V_8 ;
V_14 -> V_330 = F_81 ( F_4 ( V_2 ) -> V_203 ) ;
F_58 ( V_323 , V_145 ,
V_142 , V_146 ) ;
F_158 ( V_8 , V_106 , V_323 ) ;
F_23 ( V_323 ) -> V_326 -> V_331 ( V_323 ) ;
F_159 ( V_323 ) ;
F_160 ( V_323 ) ;
F_161 ( V_323 ) ;
F_162 ( V_323 ) ;
if ( F_57 ( V_2 ) -> V_305 == F_57 ( V_2 ) -> V_107 + 1 ) {
V_14 -> V_213 = F_57 ( V_2 ) -> V_305 ;
} else {
V_2 = F_163 ( V_2 ) ;
F_164 ( V_2 ) ;
F_165 ( V_2 , F_4 ( V_2 ) -> V_161 * 4 ) ;
F_166 ( V_2 , V_323 ) ;
F_167 ( & V_323 -> V_332 , V_2 ) ;
V_14 -> V_213 = F_57 ( V_2 ) -> V_305 ;
V_14 -> V_333 = 1 ;
}
V_8 -> V_334 ( V_8 , 0 ) ;
F_64 ( V_323 ) ;
F_65 ( V_323 ) ;
F_61 ( V_106 -> V_8 == NULL ) ;
return 0 ;
}
int F_168 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_335 V_336 ;
struct V_337 V_338 ;
const T_6 * V_169 ;
struct V_105 * V_106 ;
struct V_220 * V_221 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_339 = F_57 ( V_2 ) -> V_144 ;
bool V_229 = false ;
struct V_33 V_34 ;
struct V_296 V_297 = { . V_111 = - 1 } ;
struct V_296 V_298 = { . V_111 = - 1 } ;
struct V_1 * V_320 ;
int V_340 ;
if ( F_76 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_341;
if ( F_169 ( V_8 ) && ! V_339 ) {
V_229 = F_105 ( V_8 , V_2 , L_7 ) ;
if ( ! V_229 )
goto V_341;
}
if ( F_170 ( V_8 ) && F_171 ( V_8 ) > 1 ) {
F_46 ( F_19 ( V_8 ) , V_342 ) ;
goto V_341;
}
V_106 = F_172 ( & V_343 ) ;
if ( ! V_106 )
goto V_341;
#ifdef F_75
F_50 ( V_106 ) -> V_344 = & V_345 ;
#endif
F_173 ( & V_338 ) ;
V_338 . V_72 = V_73 ;
V_338 . V_346 = V_14 -> V_19 . V_346 ;
F_174 ( V_2 , & V_338 , & V_169 , 0 ,
V_229 ? NULL : & V_297 ) ;
if ( V_338 . V_347 > 0 &&
V_338 . V_348 &&
! V_14 -> V_19 . V_349 &&
( V_350 > 0 ||
( V_14 -> V_351 != NULL &&
V_14 -> V_351 -> V_352 > 0 ) ) ) {
T_6 * V_353 ;
T_4 * V_354 = & V_336 . V_355 [ V_356 ] ;
int V_357 = V_338 . V_347 - V_358 ;
if ( F_175 ( & V_336 . V_355 [ 0 ] ) != 0 )
goto V_359;
* V_354 ++ ^= ( V_360 T_4 ) V_3 ;
* V_354 ++ ^= ( V_360 T_4 ) V_4 ;
V_353 = ( T_6 * ) V_354 ;
while ( V_357 -- > 0 )
* V_353 ++ ^= * V_169 ++ ;
V_229 = false ;
V_336 . V_349 = 0 ;
V_336 . V_347 = V_338 . V_347 ;
} else if ( ! V_14 -> V_19 . V_361 ) {
V_336 . V_349 = 1 ;
V_336 . V_347 = 0 ;
} else {
goto V_359;
}
V_336 . V_361 = V_14 -> V_19 . V_361 ;
if ( V_229 && ! V_338 . V_348 )
F_173 ( & V_338 ) ;
V_338 . V_362 = V_338 . V_348 ;
F_176 ( V_106 , & V_338 , V_2 ) ;
V_221 = F_95 ( V_106 ) ;
V_221 -> V_222 = V_3 ;
V_221 -> V_223 = V_4 ;
V_221 -> V_215 = F_11 ( V_8 ) -> V_190 ;
V_221 -> V_46 = F_108 ( V_2 ) ;
if ( F_177 ( V_8 , V_2 , V_106 ) )
goto V_363;
if ( ! V_229 || V_338 . V_362 )
F_178 ( V_106 , V_2 ) ;
if ( V_229 ) {
V_339 = F_179 ( V_8 , V_2 , & V_106 -> V_364 ) ;
V_106 -> V_365 = V_338 . V_362 ;
} else if ( ! V_339 ) {
if ( V_338 . V_348 &&
V_66 . V_67 &&
( V_68 = F_97 ( V_8 , & V_34 , V_106 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_180 ( V_106 , V_68 , true ) ) {
F_46 ( F_19 ( V_8 ) , V_366 ) ;
goto V_359;
}
}
else if ( ! V_232 &&
( V_367 - F_181 ( V_8 ) <
( V_367 >> 2 ) ) &&
! F_180 ( V_106 , V_68 , false ) ) {
F_182 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_359;
}
V_339 = F_1 ( V_2 ) ;
}
F_50 ( V_106 ) -> V_125 = V_339 ;
if ( V_68 == NULL ) {
V_68 = F_97 ( V_8 , & V_34 , V_106 ) ;
if ( V_68 == NULL )
goto V_363;
}
V_340 = F_149 ( V_8 , V_2 , V_106 , & V_297 , & V_298 ) ;
V_320 = F_98 ( V_8 , V_68 , V_106 ,
(struct V_216 * ) & V_336 ,
F_150 ( & V_298 ) ? & V_298 : NULL ) ;
if ( V_320 ) {
F_66 ( V_320 , V_221 -> V_222 , V_221 -> V_223 ) ;
F_99 ( V_320 , F_183 ( V_2 ) ) ;
} else
goto V_363;
if ( F_21 ( ! V_340 ) ) {
int V_37 ;
V_37 = F_100 ( V_320 , V_8 , V_221 -> V_222 ,
V_221 -> V_223 , V_221 -> V_46 ) ;
V_37 = F_101 ( V_37 ) ;
if ( V_37 || V_229 )
goto V_363;
F_50 ( V_106 ) -> V_224 = V_143 ;
F_50 ( V_106 ) -> V_329 = NULL ;
F_184 ( V_8 , V_106 , V_142 ) ;
if ( F_150 ( & V_297 ) && V_297 . V_111 != 0 )
F_46 ( F_19 ( V_8 ) ,
V_328 ) ;
} else if ( F_156 ( V_8 , V_2 , V_320 , V_106 ,
(struct V_216 * ) & V_336 ) )
goto V_363;
return 0 ;
V_359:
F_185 ( V_68 ) ;
V_363:
F_154 ( V_106 ) ;
V_341:
F_46 ( F_19 ( V_8 ) , V_150 ) ;
return 0 ;
}
struct V_7 * F_186 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_82 * V_68 )
{
struct V_220 * V_221 ;
struct V_28 * V_368 ;
struct V_13 * V_369 ;
struct V_7 * V_370 ;
#ifdef F_75
struct V_167 * V_168 ;
#endif
struct V_38 * V_39 ;
if ( F_170 ( V_8 ) )
goto V_371;
V_370 = F_187 ( V_8 , V_106 , V_2 ) ;
if ( ! V_370 )
goto V_372;
V_370 -> V_76 = V_77 ;
F_188 ( V_370 , V_2 ) ;
V_369 = F_7 ( V_370 ) ;
V_368 = F_11 ( V_370 ) ;
V_221 = F_95 ( V_106 ) ;
V_368 -> V_64 = V_221 -> V_223 ;
V_368 -> V_63 = V_221 -> V_222 ;
V_368 -> V_55 = V_221 -> V_222 ;
V_39 = V_221 -> V_46 ;
F_121 ( V_368 -> V_39 , V_39 ) ;
V_221 -> V_46 = NULL ;
V_368 -> V_373 = F_42 ( V_2 ) ;
V_368 -> V_374 = F_3 ( V_2 ) -> V_119 ;
V_368 -> V_375 = F_3 ( V_2 ) -> V_193 ;
F_23 ( V_370 ) -> V_70 = 0 ;
if ( V_39 )
F_23 ( V_370 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_368 -> V_78 = V_369 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_189 ( V_8 , V_370 , V_106 ) ;
if ( ! V_68 )
goto V_376;
} else {
}
F_27 ( V_370 , V_68 ) ;
F_160 ( V_370 ) ;
F_33 ( V_370 , F_31 ( V_68 ) ) ;
V_369 -> V_377 = F_190 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_346 &&
F_7 ( V_8 ) -> V_19 . V_346 < V_369 -> V_377 )
V_369 -> V_377 = F_7 ( V_8 ) -> V_19 . V_346 ;
F_191 ( V_370 ) ;
F_192 ( V_370 , V_106 ) ;
V_369 -> V_378 = V_106 -> V_324 ;
#ifdef F_75
V_168 = F_83 ( V_8 , (union V_183 * ) & V_368 -> V_64 ,
V_42 ) ;
if ( V_168 != NULL ) {
F_118 ( V_370 , (union V_183 * ) & V_368 -> V_64 ,
V_42 , V_168 -> V_168 , V_168 -> V_260 , V_241 ) ;
F_119 ( V_370 , V_262 ) ;
}
#endif
if ( F_193 ( V_8 , V_370 ) < 0 )
goto V_376;
F_194 ( V_370 , NULL ) ;
return V_370 ;
V_371:
F_46 ( F_19 ( V_8 ) , V_342 ) ;
V_372:
F_185 ( V_68 ) ;
exit:
F_46 ( F_19 ( V_8 ) , V_150 ) ;
return NULL ;
V_376:
F_195 ( V_370 ) ;
F_63 ( V_370 ) ;
goto exit;
}
static struct V_7 * F_196 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_7 * V_379 ;
struct V_105 * * V_149 ;
struct V_105 * V_106 = F_60 ( V_8 , & V_149 , V_100 -> V_6 ,
V_97 -> V_4 , V_97 -> V_3 ) ;
if ( V_106 )
return F_197 ( V_8 , V_2 , V_106 , V_149 , false ) ;
V_379 = F_198 ( F_19 ( V_8 ) , & V_113 , V_97 -> V_4 ,
V_100 -> V_6 , V_97 -> V_3 , V_100 -> V_5 , F_42 ( V_2 ) ) ;
if ( V_379 ) {
if ( V_379 -> V_85 != V_114 ) {
F_45 ( V_379 ) ;
return V_379 ;
}
F_43 ( F_44 ( V_379 ) ) ;
return NULL ;
}
#ifdef F_106
if ( ! V_100 -> V_178 )
V_8 = F_199 ( V_8 , V_2 , & ( F_109 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_10 F_200 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
if ( V_2 -> V_155 == V_380 ) {
if ( ! F_67 ( V_2 -> V_111 , V_97 -> V_4 ,
V_97 -> V_3 , V_2 -> V_162 ) ) {
V_2 -> V_155 = V_381 ;
return 0 ;
}
}
V_2 -> V_162 = F_86 ( V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_111 , V_57 , 0 ) ;
if ( V_2 -> V_111 <= 76 ) {
return F_201 ( V_2 ) ;
}
return 0 ;
}
int F_202 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_382 ;
#ifdef F_75
if ( F_147 ( V_8 , V_2 ) )
goto V_383;
#endif
if ( V_8 -> V_85 == V_384 ) {
struct V_82 * V_68 = V_8 -> V_385 ;
F_203 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_11 ( V_8 ) -> V_386 != V_2 -> V_387 ||
V_68 -> V_92 -> V_157 ( V_68 , 0 ) == NULL ) {
F_185 ( V_68 ) ;
V_8 -> V_385 = NULL ;
}
}
if ( F_204 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_111 ) ) {
V_382 = V_8 ;
goto V_388;
}
return 0 ;
}
if ( V_2 -> V_111 < F_205 ( V_2 ) || F_206 ( V_2 ) )
goto V_389;
if ( V_8 -> V_85 == V_86 ) {
struct V_7 * V_379 = F_196 ( V_8 , V_2 ) ;
if ( ! V_379 )
goto V_383;
if ( V_379 != V_8 ) {
F_203 ( V_379 , V_2 ) ;
if ( F_207 ( V_8 , V_379 , V_2 ) ) {
V_382 = V_379 ;
goto V_388;
}
return 0 ;
}
} else
F_203 ( V_8 , V_2 ) ;
if ( F_208 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_111 ) ) {
V_382 = V_8 ;
goto V_388;
}
return 0 ;
V_388:
F_74 ( V_382 , V_2 ) ;
V_383:
F_157 ( V_2 ) ;
return 0 ;
V_389:
F_88 ( F_19 ( V_8 ) , V_390 ) ;
goto V_383;
}
void F_209 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
if ( V_2 -> V_391 != V_392 )
return;
if ( ! F_73 ( V_2 , F_210 ( V_2 ) + sizeof( struct V_99 ) ) )
return;
V_97 = F_3 ( V_2 ) ;
V_100 = F_4 ( V_2 ) ;
if ( V_100 -> V_161 < sizeof( struct V_99 ) / 4 )
return;
V_8 = F_211 ( F_39 ( V_2 -> V_110 ) , & V_113 ,
V_97 -> V_4 , V_100 -> V_6 ,
V_97 -> V_3 , F_81 ( V_100 -> V_5 ) ,
V_2 -> V_387 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_393 = V_394 ;
if ( V_8 -> V_85 != V_114 ) {
struct V_82 * V_68 = V_8 -> V_385 ;
if ( V_68 )
V_68 = F_212 ( V_68 , 0 ) ;
if ( V_68 &&
F_11 ( V_8 ) -> V_386 == V_2 -> V_387 )
F_213 ( V_2 , V_68 ) ;
}
}
}
int F_214 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
int V_395 ;
struct V_109 * V_109 = F_39 ( V_2 -> V_110 ) ;
if ( V_2 -> V_391 != V_392 )
goto V_396;
F_88 ( V_109 , V_397 ) ;
if ( ! F_73 ( V_2 , sizeof( struct V_99 ) ) )
goto V_396;
V_100 = F_4 ( V_2 ) ;
if ( V_100 -> V_161 < sizeof( struct V_99 ) / 4 )
goto V_398;
if ( ! F_73 ( V_2 , V_100 -> V_161 * 4 ) )
goto V_396;
if ( ! F_215 ( V_2 ) && F_200 ( V_2 ) )
goto V_398;
V_100 = F_4 ( V_2 ) ;
V_97 = F_3 ( V_2 ) ;
F_57 ( V_2 ) -> V_107 = F_48 ( V_100 -> V_107 ) ;
F_57 ( V_2 ) -> V_305 = ( F_57 ( V_2 ) -> V_107 + V_100 -> V_178 + V_100 -> V_179 +
V_2 -> V_111 - V_100 -> V_161 * 4 ) ;
F_57 ( V_2 ) -> V_177 = F_48 ( V_100 -> V_177 ) ;
F_57 ( V_2 ) -> V_144 = 0 ;
F_57 ( V_2 ) -> V_399 = F_216 ( V_97 ) ;
F_57 ( V_2 ) -> V_400 = 0 ;
V_8 = F_217 ( & V_113 , V_2 , V_100 -> V_6 , V_100 -> V_5 ) ;
if ( ! V_8 )
goto V_401;
V_402:
if ( V_8 -> V_85 == V_114 )
goto V_403;
if ( F_47 ( V_97 -> V_119 < F_11 ( V_8 ) -> V_120 ) ) {
F_46 ( V_109 , V_121 ) ;
goto V_404;
}
if ( ! F_218 ( V_8 , V_405 , V_2 ) )
goto V_404;
F_219 ( V_2 ) ;
if ( F_220 ( V_8 , V_2 ) )
goto V_404;
V_2 -> V_110 = NULL ;
F_221 ( V_8 ) ;
V_395 = 0 ;
if ( ! F_13 ( V_8 ) ) {
#ifdef F_222
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_406 . V_407 && V_14 -> V_406 . V_408 )
V_14 -> V_406 . V_407 = F_223 () ;
if ( V_14 -> V_406 . V_407 )
V_395 = F_202 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_224 ( V_8 , V_2 ) )
V_395 = F_202 ( V_8 , V_2 ) ;
}
} else if ( F_47 ( F_225 ( V_8 , V_2 ,
V_8 -> V_409 + V_8 -> V_410 ) ) ) {
F_64 ( V_8 ) ;
F_46 ( V_109 , V_411 ) ;
goto V_404;
}
F_64 ( V_8 ) ;
F_65 ( V_8 ) ;
return V_395 ;
V_401:
if ( ! F_218 ( NULL , V_405 , V_2 ) )
goto V_396;
if ( V_2 -> V_111 < ( V_100 -> V_161 << 2 ) || F_206 ( V_2 ) ) {
V_398:
F_88 ( V_109 , V_390 ) ;
} else {
F_74 ( NULL , V_2 ) ;
}
V_396:
F_157 ( V_2 ) ;
return 0 ;
V_404:
F_65 ( V_8 ) ;
goto V_396;
V_403:
if ( ! F_218 ( NULL , V_405 , V_2 ) ) {
F_43 ( F_44 ( V_8 ) ) ;
goto V_396;
}
if ( V_2 -> V_111 < ( V_100 -> V_161 << 2 ) || F_206 ( V_2 ) ) {
F_88 ( V_109 , V_390 ) ;
F_43 ( F_44 ( V_8 ) ) ;
goto V_396;
}
switch ( F_226 ( F_44 ( V_8 ) , V_2 , V_100 ) ) {
case V_412 : {
struct V_7 * V_413 = F_227 ( F_39 ( V_2 -> V_110 ) ,
& V_113 ,
V_97 -> V_3 , V_100 -> V_5 ,
F_42 ( V_2 ) ) ;
if ( V_413 ) {
F_228 ( F_44 ( V_8 ) , & V_66 ) ;
F_43 ( F_44 ( V_8 ) ) ;
V_8 = V_413 ;
goto V_402;
}
}
case V_414 :
F_92 ( V_8 , V_2 ) ;
break;
case V_415 :
goto V_401;
case V_416 : ;
}
goto V_396;
}
void F_188 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_80 ( V_2 ) ;
F_229 ( V_68 ) ;
V_8 -> V_385 = V_68 ;
F_11 ( V_8 ) -> V_386 = V_2 -> V_387 ;
}
static int F_230 ( struct V_7 * V_8 )
{
struct V_102 * V_103 = F_23 ( V_8 ) ;
F_231 ( V_8 ) ;
V_103 -> V_326 = & V_417 ;
#ifdef F_75
F_7 ( V_8 ) -> V_344 = & V_418 ;
#endif
return 0 ;
}
void F_232 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_233 ( V_8 ) ;
F_234 ( V_8 ) ;
F_235 ( V_8 ) ;
F_236 ( & V_14 -> V_419 ) ;
#ifdef F_75
if ( V_14 -> V_250 ) {
F_132 ( V_8 ) ;
F_130 ( V_14 -> V_250 , V_266 ) ;
V_14 -> V_250 = NULL ;
}
#endif
#ifdef F_222
F_236 ( & V_8 -> V_420 ) ;
#endif
F_236 ( & V_14 -> V_406 . V_421 ) ;
if ( F_23 ( V_8 ) -> V_422 )
F_237 ( V_8 ) ;
if ( V_14 -> V_351 != NULL ) {
F_238 ( & V_14 -> V_351 -> V_423 ,
V_424 ) ;
V_14 -> V_351 = NULL ;
}
F_55 ( V_14 -> V_122 != NULL ) ;
F_239 ( V_14 ) ;
F_240 ( V_8 ) ;
F_241 ( V_8 ) ;
}
static inline struct V_205 * F_242 ( struct V_425 * V_159 )
{
return F_243 ( V_159 ) ? NULL :
F_244 ( V_159 -> V_426 , struct V_205 , V_427 ) ;
}
static inline struct V_205 * F_245 ( struct V_205 * V_206 )
{
return ! F_246 ( V_206 -> V_427 . V_428 ) ?
F_247 ( V_206 -> V_427 . V_428 , F_248 ( * V_206 ) , V_427 ) : NULL ;
}
static void * F_249 ( struct V_429 * V_107 , void * V_430 )
{
struct V_102 * V_103 ;
struct V_431 * V_263 ;
struct V_7 * V_8 = V_430 ;
struct V_432 * V_433 ;
struct V_434 * V_435 = V_107 -> V_436 ;
struct V_109 * V_109 = F_250 ( V_107 ) ;
if ( ! V_8 ) {
V_433 = & V_113 . V_437 [ V_435 -> V_438 ] ;
F_251 ( & V_433 -> V_311 ) ;
V_8 = F_252 ( & V_433 -> V_159 ) ;
V_435 -> V_204 = 0 ;
goto V_439;
}
V_433 = & V_113 . V_437 [ V_435 -> V_438 ] ;
++ V_435 -> V_440 ;
++ V_435 -> V_204 ;
if ( V_435 -> V_441 == V_442 ) {
struct V_105 * V_106 = V_430 ;
V_103 = F_23 ( V_435 -> V_443 ) ;
V_106 = V_106 -> V_315 ;
while ( 1 ) {
while ( V_106 ) {
if ( V_106 -> V_444 -> V_243 == V_435 -> V_243 ) {
V_430 = V_106 ;
goto V_118;
}
V_106 = V_106 -> V_315 ;
}
if ( ++ V_435 -> V_445 >= V_103 -> V_235 . V_236 -> V_446 )
break;
V_447:
V_106 = V_103 -> V_235 . V_236 -> V_448 [ V_435 -> V_445 ] ;
}
V_8 = F_253 ( V_435 -> V_443 ) ;
V_435 -> V_441 = V_449 ;
F_254 ( & V_103 -> V_235 . V_450 ) ;
} else {
V_103 = F_23 ( V_8 ) ;
F_255 ( & V_103 -> V_235 . V_450 ) ;
if ( F_256 ( & V_103 -> V_235 ) )
goto V_451;
F_254 ( & V_103 -> V_235 . V_450 ) ;
V_8 = F_253 ( V_8 ) ;
}
V_439:
F_257 (sk, node) {
if ( ! F_258 ( F_19 ( V_8 ) , V_109 ) )
continue;
if ( V_8 -> V_452 == V_435 -> V_243 ) {
V_430 = V_8 ;
goto V_118;
}
V_103 = F_23 ( V_8 ) ;
F_255 ( & V_103 -> V_235 . V_450 ) ;
if ( F_256 ( & V_103 -> V_235 ) ) {
V_451:
V_435 -> V_453 = F_259 ( V_8 ) ;
V_435 -> V_443 = V_8 ;
V_435 -> V_441 = V_442 ;
V_435 -> V_445 = 0 ;
goto V_447;
}
F_254 ( & V_103 -> V_235 . V_450 ) ;
}
F_260 ( & V_433 -> V_311 ) ;
V_435 -> V_204 = 0 ;
if ( ++ V_435 -> V_438 < V_454 ) {
V_433 = & V_113 . V_437 [ V_435 -> V_438 ] ;
F_251 ( & V_433 -> V_311 ) ;
V_8 = F_252 ( & V_433 -> V_159 ) ;
goto V_439;
}
V_430 = NULL ;
V_118:
return V_430 ;
}
static void * F_261 ( struct V_429 * V_107 , T_11 * V_245 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
void * V_455 ;
V_435 -> V_438 = 0 ;
V_435 -> V_204 = 0 ;
V_455 = F_249 ( V_107 , NULL ) ;
while ( V_455 && * V_245 ) {
V_455 = F_249 ( V_107 , V_455 ) ;
-- * V_245 ;
}
return V_455 ;
}
static inline bool F_262 ( struct V_434 * V_435 )
{
return F_243 ( & V_113 . V_456 [ V_435 -> V_438 ] . V_457 ) &&
F_243 ( & V_113 . V_456 [ V_435 -> V_438 ] . V_458 ) ;
}
static void * F_263 ( struct V_429 * V_107 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
struct V_109 * V_109 = F_250 ( V_107 ) ;
void * V_455 = NULL ;
V_435 -> V_204 = 0 ;
for (; V_435 -> V_438 <= V_113 . V_459 ; ++ V_435 -> V_438 ) {
struct V_7 * V_8 ;
struct V_431 * V_263 ;
struct V_205 * V_206 ;
T_12 * V_311 = F_264 ( & V_113 , V_435 -> V_438 ) ;
if ( F_262 ( V_435 ) )
continue;
F_251 ( V_311 ) ;
F_265 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_452 != V_435 -> V_243 ||
! F_258 ( F_19 ( V_8 ) , V_109 ) ) {
continue;
}
V_455 = V_8 ;
goto V_118;
}
V_435 -> V_441 = V_460 ;
F_266 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_206 -> V_461 != V_435 -> V_243 ||
! F_258 ( F_267 ( V_206 ) , V_109 ) ) {
continue;
}
V_455 = V_206 ;
goto V_118;
}
F_260 ( V_311 ) ;
V_435 -> V_441 = V_462 ;
}
V_118:
return V_455 ;
}
static void * F_268 ( struct V_429 * V_107 , void * V_430 )
{
struct V_7 * V_8 = V_430 ;
struct V_205 * V_206 ;
struct V_431 * V_263 ;
struct V_434 * V_435 = V_107 -> V_436 ;
struct V_109 * V_109 = F_250 ( V_107 ) ;
++ V_435 -> V_440 ;
++ V_435 -> V_204 ;
if ( V_435 -> V_441 == V_460 ) {
V_206 = V_430 ;
V_206 = F_245 ( V_206 ) ;
V_463:
while ( V_206 && ( V_206 -> V_461 != V_435 -> V_243 || ! F_258 ( F_267 ( V_206 ) , V_109 ) ) ) {
V_206 = F_245 ( V_206 ) ;
}
if ( V_206 ) {
V_430 = V_206 ;
goto V_118;
}
F_260 ( F_264 ( & V_113 , V_435 -> V_438 ) ) ;
V_435 -> V_441 = V_462 ;
V_435 -> V_204 = 0 ;
while ( ++ V_435 -> V_438 <= V_113 . V_459 &&
F_262 ( V_435 ) )
;
if ( V_435 -> V_438 > V_113 . V_459 )
return NULL ;
F_251 ( F_264 ( & V_113 , V_435 -> V_438 ) ) ;
V_8 = F_252 ( & V_113 . V_456 [ V_435 -> V_438 ] . V_457 ) ;
} else
V_8 = F_253 ( V_8 ) ;
F_257 (sk, node) {
if ( V_8 -> V_452 == V_435 -> V_243 && F_258 ( F_19 ( V_8 ) , V_109 ) )
goto V_464;
}
V_435 -> V_441 = V_460 ;
V_206 = F_242 ( & V_113 . V_456 [ V_435 -> V_438 ] . V_458 ) ;
goto V_463;
V_464:
V_430 = V_8 ;
V_118:
return V_430 ;
}
static void * F_269 ( struct V_429 * V_107 , T_11 V_245 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
void * V_455 ;
V_435 -> V_438 = 0 ;
V_455 = F_263 ( V_107 ) ;
while ( V_455 && V_245 ) {
V_455 = F_268 ( V_107 , V_455 ) ;
-- V_245 ;
}
return V_455 ;
}
static void * F_270 ( struct V_429 * V_107 , T_11 V_245 )
{
void * V_455 ;
struct V_434 * V_435 = V_107 -> V_436 ;
V_435 -> V_441 = V_449 ;
V_455 = F_261 ( V_107 , & V_245 ) ;
if ( ! V_455 ) {
V_435 -> V_441 = V_462 ;
V_455 = F_269 ( V_107 , V_245 ) ;
}
return V_455 ;
}
static void * F_271 ( struct V_429 * V_107 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
int V_204 = V_435 -> V_204 ;
int V_465 = V_435 -> V_440 ;
void * V_455 = NULL ;
switch ( V_435 -> V_441 ) {
case V_442 :
case V_449 :
if ( V_435 -> V_438 >= V_454 )
break;
V_435 -> V_441 = V_449 ;
V_455 = F_249 ( V_107 , NULL ) ;
while ( V_204 -- && V_455 )
V_455 = F_249 ( V_107 , V_455 ) ;
if ( V_455 )
break;
V_435 -> V_438 = 0 ;
case V_462 :
case V_460 :
V_435 -> V_441 = V_462 ;
if ( V_435 -> V_438 > V_113 . V_459 )
break;
V_455 = F_263 ( V_107 ) ;
while ( V_204 -- && V_455 )
V_455 = F_268 ( V_107 , V_455 ) ;
}
V_435 -> V_440 = V_465 ;
return V_455 ;
}
static void * F_272 ( struct V_429 * V_107 , T_11 * V_245 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
void * V_455 ;
if ( * V_245 && * V_245 == V_435 -> V_466 ) {
V_455 = F_271 ( V_107 ) ;
if ( V_455 )
goto V_118;
}
V_435 -> V_441 = V_449 ;
V_435 -> V_440 = 0 ;
V_435 -> V_438 = 0 ;
V_435 -> V_204 = 0 ;
V_455 = * V_245 ? F_270 ( V_107 , * V_245 - 1 ) : V_467 ;
V_118:
V_435 -> V_466 = * V_245 ;
return V_455 ;
}
static void * F_273 ( struct V_429 * V_107 , void * V_468 , T_11 * V_245 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
void * V_455 = NULL ;
if ( V_468 == V_467 ) {
V_455 = F_270 ( V_107 , 0 ) ;
goto V_118;
}
switch ( V_435 -> V_441 ) {
case V_442 :
case V_449 :
V_455 = F_249 ( V_107 , V_468 ) ;
if ( ! V_455 ) {
V_435 -> V_441 = V_462 ;
V_435 -> V_438 = 0 ;
V_435 -> V_204 = 0 ;
V_455 = F_263 ( V_107 ) ;
}
break;
case V_462 :
case V_460 :
V_455 = F_268 ( V_107 , V_468 ) ;
break;
}
V_118:
++ * V_245 ;
V_435 -> V_466 = * V_245 ;
return V_455 ;
}
static void F_274 ( struct V_429 * V_107 , void * V_468 )
{
struct V_434 * V_435 = V_107 -> V_436 ;
switch ( V_435 -> V_441 ) {
case V_442 :
if ( V_468 ) {
struct V_102 * V_103 = F_23 ( V_435 -> V_443 ) ;
F_254 ( & V_103 -> V_235 . V_450 ) ;
}
case V_449 :
if ( V_468 != V_467 )
F_260 ( & V_113 . V_437 [ V_435 -> V_438 ] . V_311 ) ;
break;
case V_460 :
case V_462 :
if ( V_468 )
F_260 ( F_264 ( & V_113 , V_435 -> V_438 ) ) ;
break;
}
}
int F_275 ( struct V_469 * V_469 , struct V_470 * V_470 )
{
struct V_471 * V_472 = F_276 ( V_469 ) -> V_98 ;
struct V_434 * V_473 ;
int V_37 ;
V_37 = F_277 ( V_469 , V_470 , & V_472 -> V_474 ,
sizeof( struct V_434 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_473 = ( (struct V_429 * ) V_470 -> V_475 ) -> V_436 ;
V_473 -> V_243 = V_472 -> V_243 ;
V_473 -> V_466 = 0 ;
return 0 ;
}
int F_278 ( struct V_109 * V_109 , struct V_471 * V_472 )
{
int V_455 = 0 ;
struct V_476 * V_477 ;
V_472 -> V_474 . V_478 = F_272 ;
V_472 -> V_474 . V_428 = F_273 ;
V_472 -> V_474 . V_479 = F_274 ;
V_477 = F_279 ( V_472 -> V_480 , V_481 , V_109 -> V_482 ,
V_472 -> V_483 , V_472 ) ;
if ( ! V_477 )
V_455 = - V_261 ;
return V_455 ;
}
void F_280 ( struct V_109 * V_109 , struct V_471 * V_472 )
{
F_281 ( V_109 , V_472 -> V_480 ) ;
}
static void F_282 ( const struct V_7 * V_8 , const struct V_105 * V_106 ,
struct V_429 * V_484 , int V_485 , T_13 V_453 , int * V_111 )
{
const struct V_220 * V_221 = F_95 ( V_106 ) ;
long V_486 = V_106 -> V_313 - V_79 ;
F_283 ( V_484 , L_9
L_10 ,
V_485 ,
V_221 -> V_222 ,
F_81 ( F_11 ( V_8 ) -> V_49 ) ,
V_221 -> V_223 ,
F_81 ( V_221 -> V_487 ) ,
V_151 ,
0 , 0 ,
1 ,
F_284 ( V_486 ) ,
V_106 -> V_325 ,
F_285 ( F_286 ( V_484 ) , V_453 ) ,
0 ,
0 ,
F_287 ( & V_8 -> V_488 ) ,
V_106 ,
V_111 ) ;
}
static void F_288 ( struct V_7 * V_8 , struct V_429 * V_484 , int V_485 , int * V_111 )
{
int V_489 ;
unsigned long V_490 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_102 * V_103 = F_23 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
struct V_300 * V_301 = V_103 -> V_235 . V_301 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_491 = V_29 -> V_63 ;
T_14 V_492 = F_81 ( V_29 -> V_69 ) ;
T_14 V_493 = F_81 ( V_29 -> V_49 ) ;
int V_494 ;
if ( V_103 -> V_495 == V_145 ) {
V_489 = 1 ;
V_490 = V_103 -> V_496 ;
} else if ( V_103 -> V_495 == V_497 ) {
V_489 = 4 ;
V_490 = V_103 -> V_496 ;
} else if ( F_289 ( & V_8 -> V_498 ) ) {
V_489 = 2 ;
V_490 = V_8 -> V_498 . V_313 ;
} else {
V_489 = 0 ;
V_490 = V_79 ;
}
if ( V_8 -> V_85 == V_86 )
V_494 = V_8 -> V_499 ;
else
V_494 = F_290 ( int , V_14 -> V_213 - V_14 -> V_500 , 0 ) ;
F_283 ( V_484 , L_11
L_12 ,
V_485 , V_491 , V_493 , V_5 , V_492 , V_8 -> V_85 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_494 ,
V_489 ,
F_284 ( V_490 - V_79 ) ,
V_103 -> V_138 ,
F_285 ( F_286 ( V_484 ) , F_259 ( V_8 ) ) ,
V_103 -> V_501 ,
F_291 ( V_8 ) ,
F_287 ( & V_8 -> V_488 ) , V_8 ,
F_292 ( V_103 -> V_140 ) ,
F_292 ( V_103 -> V_502 . V_503 ) ,
( V_103 -> V_502 . V_504 << 1 ) | V_103 -> V_502 . V_505 ,
V_14 -> V_506 ,
V_8 -> V_85 == V_86 ?
( V_301 ? V_301 -> V_308 : 0 ) :
( F_293 ( V_14 ) ? - 1 : V_14 -> V_507 ) ,
V_111 ) ;
}
static void F_294 ( const struct V_205 * V_206 ,
struct V_429 * V_484 , int V_485 , int * V_111 )
{
T_3 V_5 , V_491 ;
T_14 V_492 , V_493 ;
long V_486 = V_206 -> V_508 - V_79 ;
V_5 = V_206 -> V_509 ;
V_491 = V_206 -> V_510 ;
V_492 = F_81 ( V_206 -> V_511 ) ;
V_493 = F_81 ( V_206 -> V_512 ) ;
F_283 ( V_484 , L_9
L_13 ,
V_485 , V_491 , V_493 , V_5 , V_492 , V_206 -> V_513 , 0 , 0 ,
3 , F_284 ( V_486 ) , 0 , 0 , 0 , 0 ,
F_287 ( & V_206 -> V_514 ) , V_206 , V_111 ) ;
}
static int F_295 ( struct V_429 * V_107 , void * V_468 )
{
struct V_434 * V_435 ;
int V_111 ;
if ( V_468 == V_467 ) {
F_283 ( V_107 , L_14 , V_515 - 1 ,
L_15
L_16
L_17 ) ;
goto V_118;
}
V_435 = V_107 -> V_436 ;
switch ( V_435 -> V_441 ) {
case V_449 :
case V_462 :
F_288 ( V_468 , V_107 , V_435 -> V_440 , & V_111 ) ;
break;
case V_442 :
F_282 ( V_435 -> V_443 , V_468 , V_107 , V_435 -> V_440 , V_435 -> V_453 , & V_111 ) ;
break;
case V_460 :
F_294 ( V_468 , V_107 , V_435 -> V_440 , & V_111 ) ;
break;
}
F_283 ( V_107 , L_18 , V_515 - 1 - V_111 , L_6 ) ;
V_118:
return 0 ;
}
static int T_15 F_296 ( struct V_109 * V_109 )
{
return F_278 ( V_109 , & V_516 ) ;
}
static void T_16 F_297 ( struct V_109 * V_109 )
{
F_280 ( V_109 , & V_516 ) ;
}
int T_17 F_298 ( void )
{
return F_299 ( & V_517 ) ;
}
void F_300 ( void )
{
F_301 ( & V_517 ) ;
}
struct V_1 * * F_302 ( struct V_1 * * V_159 , struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_303 ( V_2 ) ;
T_18 V_518 ;
T_10 V_519 ;
switch ( V_2 -> V_155 ) {
case V_380 :
if ( ! F_67 ( F_304 ( V_2 ) , V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_162 ) ) {
V_2 -> V_155 = V_381 ;
break;
}
V_520:
F_305 ( V_2 ) -> V_520 = 1 ;
return NULL ;
case V_521 :
V_518 = F_86 ( V_97 -> V_4 , V_97 -> V_3 ,
F_304 ( V_2 ) , V_57 , 0 ) ;
V_519 = F_306 ( F_307 ( V_2 ,
F_308 ( V_2 ) ,
F_304 ( V_2 ) ,
V_518 ) ) ;
if ( V_519 )
goto V_520;
V_2 -> V_155 = V_381 ;
break;
}
return F_309 ( V_159 , V_2 ) ;
}
int F_310 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_99 * V_100 = F_4 ( V_2 ) ;
V_100 -> V_157 = ~ F_67 ( V_2 -> V_111 - F_210 ( V_2 ) ,
V_97 -> V_4 , V_97 -> V_3 , 0 ) ;
F_311 ( V_2 ) -> V_522 = V_77 ;
return F_312 ( V_2 ) ;
}
static int T_15 F_313 ( struct V_109 * V_109 )
{
return 0 ;
}
static void T_16 F_314 ( struct V_109 * V_109 )
{
}
static void T_16 F_315 ( struct V_523 * V_524 )
{
F_316 ( & V_113 , & V_66 , V_42 ) ;
}
void T_17 F_317 ( void )
{
F_318 ( & V_113 ) ;
if ( F_299 ( & V_525 ) )
F_319 ( L_19 ) ;
}
