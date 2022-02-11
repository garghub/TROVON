static T_1 F_1 ( const struct V_1 * V_2 , T_1 * V_3 )
{
return F_2 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_5 ,
F_4 ( V_2 ) -> V_6 ,
F_4 ( V_2 ) -> V_7 , V_3 ) ;
}
int F_5 ( struct V_8 * V_9 , struct V_8 * V_10 , void * V_11 )
{
const struct V_12 * V_13 = F_6 ( V_10 ) ;
struct V_14 * V_15 = F_7 ( V_9 ) ;
if ( V_13 -> V_16 &&
( ! V_11 || ( F_8 ( V_9 ) -> V_17 . V_18 &&
F_9 () - V_13 -> V_16 > 1 ) ) ) {
V_15 -> V_19 = V_13 -> V_20 + 65535 + 2 ;
if ( V_15 -> V_19 == 0 )
V_15 -> V_19 = 1 ;
V_15 -> V_21 . V_22 = V_13 -> V_23 ;
V_15 -> V_21 . V_24 = V_13 -> V_16 ;
F_10 ( V_10 ) ;
return 1 ;
}
return 0 ;
}
int F_11 ( struct V_8 * V_9 , struct V_25 * V_26 , int V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
struct V_30 * V_31 = F_12 ( V_9 ) ;
struct V_14 * V_15 = F_7 ( V_9 ) ;
T_2 V_32 , V_33 ;
T_3 V_4 , V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_39 ;
struct V_40 * V_41 ;
if ( V_27 < sizeof( struct V_28 ) )
return - V_42 ;
if ( V_29 -> V_43 != V_44 )
return - V_45 ;
V_34 = V_4 = V_29 -> V_46 . V_47 ;
V_41 = F_13 ( V_31 -> V_41 ,
F_14 ( V_9 ) ) ;
if ( V_41 && V_41 -> V_48 . V_49 ) {
if ( ! V_4 )
return - V_42 ;
V_34 = V_41 -> V_48 . V_50 ;
}
V_32 = V_31 -> V_51 ;
V_33 = V_29 -> V_52 ;
V_36 = & V_31 -> V_53 . V_54 . V_55 . V_56 ;
V_38 = F_15 ( V_36 , V_34 , V_31 -> V_57 ,
F_16 ( V_9 ) , V_9 -> V_58 ,
V_59 ,
V_32 , V_33 , V_9 ) ;
if ( F_17 ( V_38 ) ) {
V_39 = F_18 ( V_38 ) ;
if ( V_39 == - V_60 )
F_19 ( F_8 ( V_9 ) , V_61 ) ;
return V_39 ;
}
if ( V_38 -> V_62 & ( V_63 | V_64 ) ) {
F_20 ( V_38 ) ;
return - V_60 ;
}
if ( ! V_41 || ! V_41 -> V_48 . V_49 )
V_4 = V_36 -> V_4 ;
if ( ! V_31 -> V_57 )
V_31 -> V_57 = V_36 -> V_5 ;
F_21 ( V_9 , V_31 -> V_57 ) ;
if ( V_15 -> V_21 . V_24 && V_31 -> V_65 != V_4 ) {
V_15 -> V_21 . V_22 = 0 ;
V_15 -> V_21 . V_24 = 0 ;
if ( F_22 ( ! V_15 -> V_66 ) )
V_15 -> V_19 = 0 ;
}
if ( V_67 . V_68 &&
! V_15 -> V_21 . V_24 && V_36 -> V_4 == V_4 )
F_23 ( V_9 , & V_38 -> V_69 ) ;
V_31 -> V_70 = V_29 -> V_52 ;
F_24 ( V_9 , V_4 ) ;
F_25 ( V_9 ) -> V_71 = 0 ;
if ( V_41 )
F_25 ( V_9 ) -> V_71 = V_41 -> V_48 . V_72 ;
V_15 -> V_21 . V_73 = V_74 ;
F_26 ( V_9 , V_75 ) ;
V_39 = F_27 ( & V_67 , V_9 ) ;
if ( V_39 )
goto V_76;
F_28 ( V_9 ) ;
V_38 = F_29 ( V_36 , V_38 , V_32 , V_33 ,
V_31 -> V_51 , V_31 -> V_70 , V_9 ) ;
if ( F_17 ( V_38 ) ) {
V_39 = F_18 ( V_38 ) ;
V_38 = NULL ;
goto V_76;
}
V_9 -> V_77 = V_78 ;
F_30 ( V_9 , & V_38 -> V_69 ) ;
if ( ! V_15 -> V_19 && F_22 ( ! V_15 -> V_66 ) )
V_15 -> V_19 = F_2 ( V_31 -> V_57 ,
V_31 -> V_65 ,
V_31 -> V_51 ,
V_29 -> V_52 ,
& V_15 -> V_79 ) ;
V_31 -> V_80 = V_15 -> V_19 ^ V_81 ;
V_39 = F_31 ( V_9 ) ;
V_38 = NULL ;
if ( V_39 )
goto V_76;
return 0 ;
V_76:
F_26 ( V_9 , V_82 ) ;
F_20 ( V_38 ) ;
V_9 -> V_83 = 0 ;
V_31 -> V_70 = 0 ;
return V_39 ;
}
void F_32 ( struct V_8 * V_9 )
{
struct V_84 * V_69 ;
struct V_30 * V_31 = F_12 ( V_9 ) ;
T_1 V_85 = F_7 ( V_9 ) -> V_86 ;
V_69 = F_33 ( V_9 , V_85 ) ;
if ( ! V_69 )
return;
if ( V_85 < F_34 ( V_69 ) && F_35 ( V_9 , V_69 ) )
V_9 -> V_87 = V_88 ;
V_85 = F_34 ( V_69 ) ;
if ( V_31 -> V_89 != V_90 &&
F_36 ( V_9 ) &&
F_25 ( V_9 ) -> V_91 > V_85 ) {
F_37 ( V_9 , V_85 ) ;
F_38 ( V_9 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_84 * V_69 = F_40 ( V_9 , 0 ) ;
if ( V_69 )
V_69 -> V_92 -> V_93 ( V_69 , V_9 , V_2 ) ;
}
void F_41 ( struct V_8 * V_9 , T_1 V_94 , bool abort )
{
struct V_95 * V_96 = F_42 ( V_9 ) ;
struct V_97 * V_97 = F_8 ( V_9 ) ;
if ( V_94 != F_43 ( V_96 ) -> V_98 ) {
F_44 ( V_97 , V_99 ) ;
} else if ( abort ) {
F_45 ( V_96 -> V_100 , V_96 ) ;
F_46 ( V_96 -> V_100 ) ;
}
F_47 ( V_96 ) ;
}
void F_48 ( struct V_1 * V_101 , T_1 V_102 )
{
const struct V_103 * V_104 = ( const struct V_103 * ) V_101 -> V_105 ;
struct V_106 * V_107 = (struct V_106 * ) ( V_101 -> V_105 + ( V_104 -> V_108 << 2 ) ) ;
struct V_109 * V_110 ;
struct V_14 * V_15 ;
struct V_30 * V_31 ;
const int type = F_49 ( V_101 ) -> type ;
const int V_111 = F_49 ( V_101 ) -> V_111 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_95 * V_112 ;
T_4 V_94 , V_113 ;
T_4 V_114 ;
int V_39 ;
struct V_97 * V_97 = F_50 ( V_101 -> V_115 ) ;
V_9 = F_51 ( V_97 , & V_116 , V_104 -> V_4 ,
V_107 -> V_6 , V_104 -> V_5 , F_52 ( V_107 -> V_7 ) ,
F_53 ( V_101 ) ) ;
if ( ! V_9 ) {
F_54 ( V_97 , V_117 ) ;
return;
}
if ( V_9 -> V_118 == V_119 ) {
F_55 ( F_56 ( V_9 ) ) ;
return;
}
V_94 = F_57 ( V_107 -> V_94 ) ;
if ( V_9 -> V_118 == V_120 )
return F_41 ( V_9 , V_94 ,
type == V_121 ||
type == V_122 ||
( type == V_123 &&
( V_111 == V_124 ||
V_111 == V_125 ) ) ) ;
F_58 ( V_9 ) ;
if ( F_59 ( V_9 ) ) {
if ( ! ( type == V_123 && V_111 == V_126 ) )
F_44 ( V_97 , V_127 ) ;
}
if ( V_9 -> V_118 == V_82 )
goto V_128;
if ( F_60 ( V_104 -> V_129 < F_12 ( V_9 ) -> V_130 ) ) {
F_44 ( V_97 , V_131 ) ;
goto V_128;
}
V_110 = F_25 ( V_9 ) ;
V_15 = F_7 ( V_9 ) ;
V_112 = V_15 -> V_132 ;
V_113 = V_112 ? F_43 ( V_112 ) -> V_98 : V_15 -> V_113 ;
if ( V_9 -> V_118 != V_133 &&
! F_61 ( V_94 , V_113 , V_15 -> V_134 ) ) {
F_44 ( V_97 , V_99 ) ;
goto V_128;
}
switch ( type ) {
case V_135 :
F_39 ( V_101 , V_9 ) ;
goto V_128;
case V_136 :
goto V_128;
case V_121 :
V_39 = V_137 ;
break;
case V_123 :
if ( V_111 > V_138 )
goto V_128;
if ( V_111 == V_126 ) {
if ( V_9 -> V_118 == V_133 )
goto V_128;
V_15 -> V_86 = V_102 ;
if ( ! F_59 ( V_9 ) ) {
F_32 ( V_9 ) ;
} else {
if ( ! F_62 ( V_139 , & V_9 -> V_140 ) )
F_10 ( V_9 ) ;
}
goto V_128;
}
V_39 = V_141 [ V_111 ] . V_142 ;
if ( V_111 != V_124 && V_111 != V_125 )
break;
if ( V_94 != V_15 -> V_113 || ! V_110 -> V_143 ||
! V_110 -> V_144 || V_112 )
break;
if ( F_59 ( V_9 ) )
break;
V_110 -> V_144 -- ;
V_110 -> V_145 = V_15 -> V_146 ? F_63 ( V_15 ) :
V_147 ;
V_110 -> V_145 = F_64 ( V_110 , V_148 ) ;
V_2 = F_65 ( V_9 ) ;
F_66 ( ! V_2 ) ;
V_114 = V_110 -> V_145 -
F_67 ( V_110 -> V_145 ,
V_149 - F_68 ( V_2 ) ) ;
if ( V_114 ) {
F_69 ( V_9 , V_150 ,
V_114 , V_148 ) ;
} else {
F_70 ( V_9 ) ;
}
break;
case V_122 :
V_39 = V_151 ;
break;
default:
goto V_128;
}
switch ( V_9 -> V_118 ) {
case V_75 :
case V_152 :
if ( V_112 && ! V_112 -> V_9 )
break;
if ( ! F_59 ( V_9 ) ) {
V_9 -> V_153 = V_39 ;
V_9 -> V_154 ( V_9 ) ;
F_71 ( V_9 ) ;
} else {
V_9 -> V_87 = V_39 ;
}
goto V_128;
}
V_31 = F_12 ( V_9 ) ;
if ( ! F_59 ( V_9 ) && V_31 -> V_155 ) {
V_9 -> V_153 = V_39 ;
V_9 -> V_154 ( V_9 ) ;
} else {
V_9 -> V_87 = V_39 ;
}
V_128:
F_72 ( V_9 ) ;
F_73 ( V_9 ) ;
}
void F_74 ( struct V_1 * V_2 , T_3 V_5 , T_3 V_4 )
{
struct V_106 * V_107 = F_4 ( V_2 ) ;
if ( V_2 -> V_156 == V_157 ) {
V_107 -> V_158 = ~ F_75 ( V_2 -> V_159 , V_5 , V_4 , 0 ) ;
V_2 -> V_160 = F_76 ( V_2 ) - V_2 -> V_161 ;
V_2 -> V_162 = F_77 ( struct V_106 , V_158 ) ;
} else {
V_107 -> V_158 = F_75 ( V_2 -> V_159 , V_5 , V_4 ,
F_78 ( V_107 ,
V_107 -> V_163 << 2 ,
V_2 -> V_164 ) ) ;
}
}
void F_79 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_30 * V_31 = F_12 ( V_9 ) ;
F_74 ( V_2 , V_31 -> V_57 , V_31 -> V_65 ) ;
}
static void F_80 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_106 * V_107 = F_4 ( V_2 ) ;
struct {
struct V_106 V_107 ;
#ifdef F_81
T_3 V_48 [ ( V_165 >> 2 ) ] ;
#endif
} V_166 ;
struct V_167 V_168 ;
#ifdef F_81
struct V_169 * V_170 = NULL ;
const T_5 * V_171 = NULL ;
unsigned char V_172 [ 16 ] ;
int V_173 ;
struct V_8 * V_174 = NULL ;
#endif
struct V_97 * V_97 ;
if ( V_107 -> V_175 )
return;
if ( ! V_9 && F_82 ( V_2 ) -> V_176 != V_177 )
return;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_107 . V_6 = V_107 -> V_7 ;
V_166 . V_107 . V_7 = V_107 -> V_6 ;
V_166 . V_107 . V_163 = sizeof( struct V_106 ) / 4 ;
V_166 . V_107 . V_175 = 1 ;
if ( V_107 -> V_178 ) {
V_166 . V_107 . V_94 = V_107 -> V_179 ;
} else {
V_166 . V_107 . V_178 = 1 ;
V_166 . V_107 . V_179 = F_83 ( F_57 ( V_107 -> V_94 ) + V_107 -> V_180 + V_107 -> V_181 +
V_2 -> V_159 - ( V_107 -> V_163 << 2 ) ) ;
}
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_182 [ 0 ] . V_183 = ( unsigned char * ) & V_166 ;
V_168 . V_182 [ 0 ] . V_184 = sizeof( V_166 . V_107 ) ;
V_97 = V_9 ? F_8 ( V_9 ) : F_50 ( F_84 ( V_2 ) -> V_115 ) ;
#ifdef F_81
F_85 () ;
V_171 = F_86 ( V_107 ) ;
if ( V_9 && F_87 ( V_9 ) ) {
V_170 = F_88 ( V_9 , (union V_185 * )
& F_3 ( V_2 ) -> V_5 , V_44 ) ;
} else if ( V_171 ) {
V_174 = F_89 ( V_97 , & V_116 , NULL , 0 ,
F_3 ( V_2 ) -> V_5 ,
V_107 -> V_7 , F_3 ( V_2 ) -> V_4 ,
F_52 ( V_107 -> V_7 ) , F_53 ( V_2 ) ) ;
if ( ! V_174 )
goto V_128;
V_170 = F_88 ( V_174 , (union V_185 * )
& F_3 ( V_2 ) -> V_5 , V_44 ) ;
if ( ! V_170 )
goto V_128;
V_173 = F_90 ( V_172 , V_170 , NULL , V_2 ) ;
if ( V_173 || memcmp ( V_171 , V_172 , 16 ) != 0 )
goto V_128;
}
if ( V_170 ) {
V_166 . V_48 [ 0 ] = F_83 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_168 . V_182 [ 0 ] . V_184 += V_165 ;
V_166 . V_107 . V_163 = V_168 . V_182 [ 0 ] . V_184 / 4 ;
F_91 ( ( T_5 * ) & V_166 . V_48 [ 1 ] ,
V_170 , F_3 ( V_2 ) -> V_5 ,
F_3 ( V_2 ) -> V_4 , & V_166 . V_107 ) ;
}
#endif
V_168 . V_164 = F_92 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_5 ,
V_168 . V_182 [ 0 ] . V_184 , V_59 , 0 ) ;
V_168 . V_189 = F_77 ( struct V_106 , V_158 ) / 2 ;
V_168 . V_190 = ( V_9 && F_93 ( V_9 ) ) ? V_191 : 0 ;
if ( V_9 )
V_168 . V_192 = V_9 -> V_58 ;
F_94 ( F_77 ( struct V_8 , V_58 ) !=
F_77 ( struct V_193 , V_194 ) ) ;
V_168 . V_195 = F_3 ( V_2 ) -> V_195 ;
V_168 . V_196 = F_95 ( V_97 , V_9 && F_87 ( V_9 ) ? V_9 : NULL ) ;
F_96 () ;
F_97 ( * F_98 ( V_97 -> V_17 . F_7 ) ,
V_2 , & F_99 ( V_2 ) -> V_197 . V_198 . V_48 ,
F_3 ( V_2 ) -> V_5 , F_3 ( V_2 ) -> V_4 ,
& V_168 , V_168 . V_182 [ 0 ] . V_184 ) ;
F_100 ( V_97 , V_199 ) ;
F_100 ( V_97 , V_200 ) ;
F_101 () ;
#ifdef F_81
V_128:
F_102 () ;
#endif
}
static void F_103 ( const struct V_8 * V_9 ,
struct V_1 * V_2 , T_1 V_94 , T_1 V_178 ,
T_1 V_201 , T_1 V_202 , T_1 V_203 , int V_204 ,
struct V_169 * V_170 ,
int V_205 , T_6 V_195 )
{
const struct V_106 * V_107 = F_4 ( V_2 ) ;
struct {
struct V_106 V_107 ;
T_3 V_48 [ ( V_206 >> 2 )
#ifdef F_81
+ ( V_165 >> 2 )
#endif
] ;
} V_166 ;
struct V_97 * V_97 = F_8 ( V_9 ) ;
struct V_167 V_168 ;
memset ( & V_166 . V_107 , 0 , sizeof( struct V_106 ) ) ;
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
V_168 . V_182 [ 0 ] . V_183 = ( unsigned char * ) & V_166 ;
V_168 . V_182 [ 0 ] . V_184 = sizeof( V_166 . V_107 ) ;
if ( V_203 ) {
V_166 . V_48 [ 0 ] = F_83 ( ( V_186 << 24 ) | ( V_186 << 16 ) |
( V_207 << 8 ) |
V_208 ) ;
V_166 . V_48 [ 1 ] = F_83 ( V_202 ) ;
V_166 . V_48 [ 2 ] = F_83 ( V_203 ) ;
V_168 . V_182 [ 0 ] . V_184 += V_206 ;
}
V_166 . V_107 . V_6 = V_107 -> V_7 ;
V_166 . V_107 . V_7 = V_107 -> V_6 ;
V_166 . V_107 . V_163 = V_168 . V_182 [ 0 ] . V_184 / 4 ;
V_166 . V_107 . V_94 = F_83 ( V_94 ) ;
V_166 . V_107 . V_179 = F_83 ( V_178 ) ;
V_166 . V_107 . V_178 = 1 ;
V_166 . V_107 . V_209 = F_104 ( V_201 ) ;
#ifdef F_81
if ( V_170 ) {
int V_210 = ( V_203 ) ? 3 : 0 ;
V_166 . V_48 [ V_210 ++ ] = F_83 ( ( V_186 << 24 ) |
( V_186 << 16 ) |
( V_187 << 8 ) |
V_188 ) ;
V_168 . V_182 [ 0 ] . V_184 += V_165 ;
V_166 . V_107 . V_163 = V_168 . V_182 [ 0 ] . V_184 / 4 ;
F_91 ( ( T_5 * ) & V_166 . V_48 [ V_210 ] ,
V_170 , F_3 ( V_2 ) -> V_5 ,
F_3 ( V_2 ) -> V_4 , & V_166 . V_107 ) ;
}
#endif
V_168 . V_190 = V_205 ;
V_168 . V_164 = F_92 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_5 ,
V_168 . V_182 [ 0 ] . V_184 , V_59 , 0 ) ;
V_168 . V_189 = F_77 ( struct V_106 , V_158 ) / 2 ;
if ( V_204 )
V_168 . V_192 = V_204 ;
V_168 . V_195 = V_195 ;
V_168 . V_196 = F_95 ( V_97 , F_87 ( V_9 ) ? V_9 : NULL ) ;
F_96 () ;
F_97 ( * F_98 ( V_97 -> V_17 . F_7 ) ,
V_2 , & F_99 ( V_2 ) -> V_197 . V_198 . V_48 ,
F_3 ( V_2 ) -> V_5 , F_3 ( V_2 ) -> V_4 ,
& V_168 , V_168 . V_182 [ 0 ] . V_184 ) ;
F_100 ( V_97 , V_199 ) ;
F_101 () ;
}
static void F_105 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_193 * V_211 = F_56 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
F_103 ( V_9 , V_2 ,
V_13 -> V_20 , V_13 -> V_212 ,
V_13 -> V_213 >> V_211 -> V_214 ,
V_149 + V_13 -> V_215 ,
V_13 -> V_23 ,
V_211 -> V_194 ,
F_106 ( V_13 ) ,
V_211 -> V_216 ? V_191 : 0 ,
V_211 -> V_217
) ;
F_55 ( V_211 ) ;
}
static void F_107 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_95 * V_96 )
{
T_1 V_94 = ( V_9 -> V_118 == V_133 ) ? F_43 ( V_96 ) -> V_98 + 1 :
F_7 ( V_9 ) -> V_134 ;
F_103 ( V_9 , V_2 , V_94 ,
F_43 ( V_96 ) -> V_218 ,
V_96 -> V_219 >> F_108 ( V_96 ) -> V_220 ,
V_149 + F_43 ( V_96 ) -> V_221 ,
V_96 -> V_22 ,
0 ,
F_88 ( V_9 , (union V_185 * ) & F_3 ( V_2 ) -> V_4 ,
V_44 ) ,
F_108 ( V_96 ) -> V_222 ? V_191 : 0 ,
F_3 ( V_2 ) -> V_195 ) ;
}
static int F_109 ( const struct V_8 * V_9 , struct V_84 * V_69 ,
struct V_223 * V_54 ,
struct V_95 * V_96 ,
struct V_224 * V_225 ,
enum V_226 V_227 )
{
const struct V_228 * V_229 = F_108 ( V_96 ) ;
struct V_35 V_36 ;
int V_39 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_69 && ( V_69 = F_110 ( V_9 , & V_36 , V_96 ) ) == NULL )
return - 1 ;
V_2 = F_111 ( V_9 , V_69 , V_96 , V_225 , V_227 ) ;
if ( V_2 ) {
F_74 ( V_2 , V_229 -> V_230 , V_229 -> V_231 ) ;
V_39 = F_112 ( V_2 , V_9 , V_229 -> V_230 ,
V_229 -> V_231 ,
V_229 -> V_48 ) ;
V_39 = F_113 ( V_39 ) ;
}
return V_39 ;
}
static void F_114 ( struct V_95 * V_96 )
{
F_115 ( F_108 ( V_96 ) -> V_48 ) ;
}
struct V_169 * F_88 ( const struct V_8 * V_9 ,
const union V_185 * V_232 ,
int V_233 )
{
const struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_169 * V_170 ;
unsigned int V_234 = sizeof( struct V_235 ) ;
const struct V_236 * V_237 ;
V_237 = F_116 ( V_15 -> V_238 ,
F_14 ( V_9 ) ) ;
if ( ! V_237 )
return NULL ;
#if F_117 ( V_239 )
if ( V_233 == V_240 )
V_234 = sizeof( struct V_241 ) ;
#endif
F_118 (key, &md5sig->head, node) {
if ( V_170 -> V_233 != V_233 )
continue;
if ( ! memcmp ( & V_170 -> V_232 , V_232 , V_234 ) )
return V_170 ;
}
return NULL ;
}
struct V_169 * F_119 ( const struct V_8 * V_9 ,
const struct V_8 * V_242 )
{
const union V_185 * V_232 ;
V_232 = ( const union V_185 * ) & V_242 -> V_243 ;
return F_88 ( V_9 , V_232 , V_44 ) ;
}
int F_120 ( struct V_8 * V_9 , const union V_185 * V_232 ,
int V_233 , const T_6 * V_244 , T_6 V_245 , T_7 V_246 )
{
struct V_169 * V_170 ;
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_236 * V_237 ;
V_170 = F_88 ( V_9 , V_232 , V_233 ) ;
if ( V_170 ) {
memcpy ( V_170 -> V_170 , V_244 , V_245 ) ;
V_170 -> V_247 = V_245 ;
return 0 ;
}
V_237 = F_13 ( V_15 -> V_238 ,
F_14 ( V_9 ) ) ;
if ( ! V_237 ) {
V_237 = F_121 ( sizeof( * V_237 ) , V_246 ) ;
if ( ! V_237 )
return - V_248 ;
F_122 ( V_9 , V_249 ) ;
F_123 ( & V_237 -> V_161 ) ;
F_124 ( V_15 -> V_238 , V_237 ) ;
}
V_170 = F_125 ( V_9 , sizeof( * V_170 ) , V_246 ) ;
if ( ! V_170 )
return - V_248 ;
if ( ! F_126 () ) {
F_127 ( V_9 , V_170 , sizeof( * V_170 ) ) ;
return - V_248 ;
}
memcpy ( V_170 -> V_170 , V_244 , V_245 ) ;
V_170 -> V_247 = V_245 ;
V_170 -> V_233 = V_233 ;
memcpy ( & V_170 -> V_232 , V_232 ,
( V_233 == V_240 ) ? sizeof( struct V_241 ) :
sizeof( struct V_235 ) ) ;
F_128 ( & V_170 -> V_250 , & V_237 -> V_161 ) ;
return 0 ;
}
int F_129 ( struct V_8 * V_9 , const union V_185 * V_232 , int V_233 )
{
struct V_169 * V_170 ;
V_170 = F_88 ( V_9 , V_232 , V_233 ) ;
if ( ! V_170 )
return - V_251 ;
F_130 ( & V_170 -> V_250 ) ;
F_131 ( sizeof( * V_170 ) , & V_9 -> V_252 ) ;
F_132 ( V_170 , V_253 ) ;
return 0 ;
}
static void F_133 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_169 * V_170 ;
struct V_254 * V_255 ;
struct V_236 * V_237 ;
V_237 = F_13 ( V_15 -> V_238 , 1 ) ;
F_134 (key, n, &md5sig->head, node) {
F_130 ( & V_170 -> V_250 ) ;
F_131 ( sizeof( * V_170 ) , & V_9 -> V_252 ) ;
F_132 ( V_170 , V_253 ) ;
}
}
static int F_135 ( struct V_8 * V_9 , char T_8 * V_256 ,
int V_72 )
{
struct V_257 V_258 ;
struct V_28 * sin = (struct V_28 * ) & V_258 . V_259 ;
if ( V_72 < sizeof( V_258 ) )
return - V_42 ;
if ( F_136 ( & V_258 , V_256 , sizeof( V_258 ) ) )
return - V_260 ;
if ( sin -> V_43 != V_44 )
return - V_42 ;
if ( ! V_258 . V_261 )
return F_129 ( V_9 , (union V_185 * ) & sin -> V_46 . V_47 ,
V_44 ) ;
if ( V_258 . V_261 > V_262 )
return - V_42 ;
return F_120 ( V_9 , (union V_185 * ) & sin -> V_46 . V_47 ,
V_44 , V_258 . V_263 , V_258 . V_261 ,
V_264 ) ;
}
static int F_137 ( struct V_265 * V_266 ,
T_3 V_4 , T_3 V_5 ,
const struct V_106 * V_107 , int V_267 )
{
struct V_268 * V_269 ;
struct V_270 V_271 ;
struct V_106 * V_272 ;
V_269 = V_266 -> V_273 ;
V_269 -> V_5 = V_5 ;
V_269 -> V_4 = V_4 ;
V_269 -> V_274 = 0 ;
V_269 -> V_275 = V_59 ;
V_269 -> V_159 = F_138 ( V_267 ) ;
V_272 = (struct V_106 * ) ( V_269 + 1 ) ;
memcpy ( V_272 , V_107 , sizeof( * V_107 ) ) ;
V_272 -> V_158 = 0 ;
F_139 ( & V_271 , V_269 , sizeof( * V_269 ) + sizeof( * V_107 ) ) ;
F_140 ( V_266 -> V_276 , & V_271 , NULL ,
sizeof( * V_269 ) + sizeof( * V_107 ) ) ;
return F_141 ( V_266 -> V_276 ) ;
}
static int F_91 ( char * V_277 , const struct V_169 * V_170 ,
T_3 V_4 , T_3 V_5 , const struct V_106 * V_107 )
{
struct V_265 * V_266 ;
struct V_278 * V_96 ;
V_266 = F_142 () ;
if ( ! V_266 )
goto V_279;
V_96 = V_266 -> V_276 ;
if ( F_143 ( V_96 ) )
goto V_280;
if ( F_137 ( V_266 , V_4 , V_5 , V_107 , V_107 -> V_163 << 2 ) )
goto V_280;
if ( F_144 ( V_266 , V_170 ) )
goto V_280;
F_140 ( V_96 , NULL , V_277 , 0 ) ;
if ( F_145 ( V_96 ) )
goto V_280;
F_146 () ;
return 0 ;
V_280:
F_146 () ;
V_279:
memset ( V_277 , 0 , 16 ) ;
return 1 ;
}
int F_90 ( char * V_277 , const struct V_169 * V_170 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_265 * V_266 ;
struct V_278 * V_96 ;
const struct V_106 * V_107 = F_4 ( V_2 ) ;
T_3 V_5 , V_4 ;
if ( V_9 ) {
V_5 = V_9 -> V_281 ;
V_4 = V_9 -> V_243 ;
} else {
const struct V_103 * V_104 = F_3 ( V_2 ) ;
V_5 = V_104 -> V_5 ;
V_4 = V_104 -> V_4 ;
}
V_266 = F_142 () ;
if ( ! V_266 )
goto V_279;
V_96 = V_266 -> V_276 ;
if ( F_143 ( V_96 ) )
goto V_280;
if ( F_137 ( V_266 , V_4 , V_5 , V_107 , V_2 -> V_159 ) )
goto V_280;
if ( F_147 ( V_266 , V_2 , V_107 -> V_163 << 2 ) )
goto V_280;
if ( F_144 ( V_266 , V_170 ) )
goto V_280;
F_140 ( V_96 , NULL , V_277 , 0 ) ;
if ( F_145 ( V_96 ) )
goto V_280;
F_146 () ;
return 0 ;
V_280:
F_146 () ;
V_279:
memset ( V_277 , 0 , 16 ) ;
return 1 ;
}
static bool F_148 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
#ifdef F_81
const T_5 * V_171 = NULL ;
struct V_169 * V_282 ;
const struct V_103 * V_104 = F_3 ( V_2 ) ;
const struct V_106 * V_107 = F_4 ( V_2 ) ;
int V_173 ;
unsigned char V_172 [ 16 ] ;
V_282 = F_88 ( V_9 , (union V_185 * ) & V_104 -> V_5 ,
V_44 ) ;
V_171 = F_86 ( V_107 ) ;
if ( ! V_282 && ! V_171 )
return false ;
if ( V_282 && ! V_171 ) {
F_149 ( F_8 ( V_9 ) , V_283 ) ;
return true ;
}
if ( ! V_282 && V_171 ) {
F_149 ( F_8 ( V_9 ) , V_284 ) ;
return true ;
}
V_173 = F_90 ( V_172 ,
V_282 ,
NULL , V_2 ) ;
if ( V_173 || memcmp ( V_171 , V_172 , 16 ) != 0 ) {
F_149 ( F_8 ( V_9 ) , V_285 ) ;
F_150 ( L_1 ,
& V_104 -> V_5 , F_52 ( V_107 -> V_7 ) ,
& V_104 -> V_4 , F_52 ( V_107 -> V_6 ) ,
V_173 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_151 ( struct V_95 * V_96 ,
const struct V_8 * V_286 ,
struct V_1 * V_2 )
{
struct V_228 * V_229 = F_108 ( V_96 ) ;
F_21 ( F_152 ( V_96 ) , F_3 ( V_2 ) -> V_4 ) ;
F_24 ( F_152 ( V_96 ) , F_3 ( V_2 ) -> V_5 ) ;
V_229 -> V_48 = F_153 ( V_2 ) ;
}
static struct V_84 * F_154 ( const struct V_8 * V_9 ,
struct V_223 * V_54 ,
const struct V_95 * V_96 ,
bool * V_287 )
{
struct V_84 * V_69 = F_110 ( V_9 , & V_54 -> V_55 . V_56 , V_96 ) ;
if ( V_287 ) {
if ( V_54 -> V_55 . V_56 . V_4 == F_108 ( V_96 ) -> V_231 )
* V_287 = true ;
else
* V_287 = false ;
}
return V_69 ;
}
int F_155 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_82 ( V_2 ) -> V_62 & ( V_64 | V_63 ) )
goto V_288;
return F_156 ( & V_289 ,
& V_290 , V_9 , V_2 ) ;
V_288:
F_46 ( V_9 ) ;
return 0 ;
}
struct V_8 * F_157 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_95 * V_96 ,
struct V_84 * V_69 ,
struct V_95 * V_291 ,
bool * V_292 )
{
struct V_228 * V_229 ;
struct V_30 * V_293 ;
struct V_14 * V_294 ;
struct V_8 * V_295 ;
#ifdef F_81
struct V_169 * V_170 ;
#endif
struct V_40 * V_41 ;
if ( F_158 ( V_9 ) )
goto V_296;
V_295 = F_159 ( V_9 , V_96 , V_2 ) ;
if ( ! V_295 )
goto V_297;
V_295 -> V_77 = V_78 ;
F_160 ( V_295 , V_2 ) ;
V_294 = F_7 ( V_295 ) ;
V_293 = F_12 ( V_295 ) ;
V_229 = F_108 ( V_96 ) ;
F_24 ( V_295 , V_229 -> V_231 ) ;
F_21 ( V_295 , V_229 -> V_230 ) ;
V_295 -> V_58 = V_229 -> V_298 ;
V_293 -> V_57 = V_229 -> V_230 ;
V_41 = V_229 -> V_48 ;
F_124 ( V_293 -> V_41 , V_41 ) ;
V_229 -> V_48 = NULL ;
V_293 -> V_299 = F_53 ( V_2 ) ;
V_293 -> V_300 = F_3 ( V_2 ) -> V_129 ;
V_293 -> V_301 = F_3 ( V_2 ) -> V_195 ;
F_25 ( V_295 ) -> V_71 = 0 ;
if ( V_41 )
F_25 ( V_295 ) -> V_71 = V_41 -> V_48 . V_72 ;
V_293 -> V_80 = V_294 -> V_19 ^ V_81 ;
if ( ! V_69 ) {
V_69 = F_161 ( V_9 , V_295 , V_96 ) ;
if ( ! V_69 )
goto V_302;
} else {
}
F_30 ( V_295 , V_69 ) ;
F_162 ( V_295 , V_69 ) ;
F_37 ( V_295 , F_34 ( V_69 ) ) ;
V_294 -> V_303 = F_163 ( V_69 ) ;
if ( F_7 ( V_9 ) -> V_21 . V_304 &&
F_7 ( V_9 ) -> V_21 . V_304 < V_294 -> V_303 )
V_294 -> V_303 = F_7 ( V_9 ) -> V_21 . V_304 ;
F_164 ( V_295 ) ;
#ifdef F_81
V_170 = F_88 ( V_9 , (union V_185 * ) & V_293 -> V_65 ,
V_44 ) ;
if ( V_170 ) {
F_120 ( V_295 , (union V_185 * ) & V_293 -> V_65 ,
V_44 , V_170 -> V_170 , V_170 -> V_247 , V_305 ) ;
F_122 ( V_295 , V_249 ) ;
}
#endif
if ( F_165 ( V_9 , V_295 ) < 0 )
goto V_302;
* V_292 = F_166 ( V_295 , F_152 ( V_291 ) ) ;
if ( * V_292 )
F_167 ( V_294 , V_96 ) ;
return V_295 ;
V_296:
F_149 ( F_8 ( V_9 ) , V_306 ) ;
V_297:
F_168 ( V_69 ) ;
exit:
F_46 ( V_9 ) ;
return NULL ;
V_302:
F_169 ( V_295 ) ;
F_71 ( V_295 ) ;
goto exit;
}
static struct V_8 * F_170 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_171
const struct V_106 * V_107 = F_4 ( V_2 ) ;
if ( ! V_107 -> V_180 )
V_9 = F_172 ( V_9 , V_2 ) ;
#endif
return V_9 ;
}
int F_173 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_8 * V_307 ;
if ( V_9 -> V_118 == V_308 ) {
struct V_84 * V_69 = V_9 -> V_309 ;
F_174 ( V_9 , V_2 ) ;
F_175 ( V_9 , V_2 ) ;
if ( V_69 ) {
if ( F_12 ( V_9 ) -> V_310 != V_2 -> V_311 ||
! V_69 -> V_92 -> V_158 ( V_69 , 0 ) ) {
F_168 ( V_69 ) ;
V_9 -> V_309 = NULL ;
}
}
F_176 ( V_9 , V_2 , F_4 ( V_2 ) , V_2 -> V_159 ) ;
return 0 ;
}
if ( F_177 ( V_2 ) )
goto V_312;
if ( V_9 -> V_118 == V_133 ) {
struct V_8 * V_313 = F_170 ( V_9 , V_2 ) ;
if ( ! V_313 )
goto V_314;
if ( V_313 != V_9 ) {
F_174 ( V_313 , V_2 ) ;
F_175 ( V_313 , V_2 ) ;
if ( F_178 ( V_9 , V_313 , V_2 ) ) {
V_307 = V_313 ;
goto V_315;
}
return 0 ;
}
} else
F_174 ( V_9 , V_2 ) ;
if ( F_179 ( V_9 , V_2 ) ) {
V_307 = V_9 ;
goto V_315;
}
return 0 ;
V_315:
F_80 ( V_307 , V_2 ) ;
V_314:
F_180 ( V_2 ) ;
return 0 ;
V_312:
F_181 ( F_8 ( V_9 ) , V_316 ) ;
F_181 ( F_8 ( V_9 ) , V_317 ) ;
goto V_314;
}
void F_182 ( struct V_1 * V_2 )
{
const struct V_103 * V_104 ;
const struct V_106 * V_107 ;
struct V_8 * V_9 ;
if ( V_2 -> V_318 != V_319 )
return;
if ( ! F_183 ( V_2 , F_184 ( V_2 ) + sizeof( struct V_106 ) ) )
return;
V_104 = F_3 ( V_2 ) ;
V_107 = F_4 ( V_2 ) ;
if ( V_107 -> V_163 < sizeof( struct V_106 ) / 4 )
return;
V_9 = F_51 ( F_50 ( V_2 -> V_115 ) , & V_116 ,
V_104 -> V_5 , V_107 -> V_7 ,
V_104 -> V_4 , F_52 ( V_107 -> V_6 ) ,
V_2 -> V_311 ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_320 = V_321 ;
if ( F_87 ( V_9 ) ) {
struct V_84 * V_69 = F_185 ( V_9 -> V_309 ) ;
if ( V_69 )
V_69 = F_186 ( V_69 , 0 ) ;
if ( V_69 &&
F_12 ( V_9 ) -> V_310 == V_2 -> V_311 )
F_187 ( V_2 , V_69 ) ;
}
}
}
bool F_188 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
if ( V_322 || ! V_15 -> V_323 . V_324 )
return false ;
if ( V_2 -> V_159 <= F_189 ( V_2 ) &&
F_190 ( & V_15 -> V_323 . V_325 ) == 0 )
return false ;
if ( F_22 ( V_9 -> V_309 ) )
F_191 ( V_2 ) ;
else
F_192 ( V_2 ) ;
F_193 ( & V_15 -> V_323 . V_325 , V_2 ) ;
V_15 -> V_323 . V_326 += V_2 -> V_327 ;
if ( F_190 ( & V_15 -> V_323 . V_325 ) >= 32 ||
V_15 -> V_323 . V_326 + F_194 ( & V_9 -> V_328 ) > V_9 -> V_329 ) {
struct V_1 * V_330 ;
F_66 ( F_59 ( V_9 ) ) ;
F_195 ( F_8 ( V_9 ) , V_331 ,
F_190 ( & V_15 -> V_323 . V_325 ) ) ;
while ( ( V_330 = F_196 ( & V_15 -> V_323 . V_325 ) ) != NULL )
F_197 ( V_9 , V_330 ) ;
V_15 -> V_323 . V_326 = 0 ;
} else if ( F_190 ( & V_15 -> V_323 . V_325 ) == 1 ) {
F_198 ( F_199 ( V_9 ) ,
V_332 | V_333 | V_334 ) ;
if ( ! F_200 ( V_9 ) )
F_69 ( V_9 , V_335 ,
( 3 * F_201 ( V_9 ) ) / 4 ,
V_148 ) ;
}
return true ;
}
bool F_202 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_336 = V_9 -> V_329 + V_9 -> V_337 ;
V_336 += 64 * 1024 ;
if ( ! V_2 -> V_338 )
V_2 -> V_327 = F_203 ( F_204 ( V_2 ) ) ;
if ( F_60 ( F_205 ( V_9 , V_2 , V_336 ) ) ) {
F_72 ( V_9 ) ;
F_44 ( F_8 ( V_9 ) , V_339 ) ;
return true ;
}
return false ;
}
int F_206 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_106 * V_107 = (struct V_106 * ) V_2 -> V_105 ;
unsigned int V_340 = V_2 -> V_159 ;
int V_39 ;
V_39 = F_207 ( V_9 , V_2 , V_107 -> V_163 * 4 ) ;
if ( ! V_39 ) {
V_340 -= V_2 -> V_159 ;
F_99 ( V_2 ) -> V_341 -= V_340 ;
}
return V_39 ;
}
int F_208 ( struct V_1 * V_2 )
{
struct V_97 * V_97 = F_50 ( V_2 -> V_115 ) ;
const struct V_103 * V_104 ;
const struct V_106 * V_107 ;
bool V_342 ;
struct V_8 * V_9 ;
int V_343 ;
if ( V_2 -> V_318 != V_319 )
goto V_344;
F_100 ( V_97 , V_345 ) ;
if ( ! F_183 ( V_2 , sizeof( struct V_106 ) ) )
goto V_344;
V_107 = ( const struct V_106 * ) V_2 -> V_105 ;
if ( F_60 ( V_107 -> V_163 < sizeof( struct V_106 ) / 4 ) )
goto V_346;
if ( ! F_183 ( V_2 , V_107 -> V_163 * 4 ) )
goto V_344;
if ( F_209 ( V_2 , V_59 , V_347 ) )
goto V_348;
V_107 = ( const struct V_106 * ) V_2 -> V_105 ;
V_104 = F_3 ( V_2 ) ;
memmove ( & F_99 ( V_2 ) -> V_197 . V_198 , F_210 ( V_2 ) ,
sizeof( struct V_349 ) ) ;
F_211 () ;
F_99 ( V_2 ) -> V_94 = F_57 ( V_107 -> V_94 ) ;
F_99 ( V_2 ) -> V_341 = ( F_99 ( V_2 ) -> V_94 + V_107 -> V_180 + V_107 -> V_181 +
V_2 -> V_159 - V_107 -> V_163 * 4 ) ;
F_99 ( V_2 ) -> V_179 = F_57 ( V_107 -> V_179 ) ;
F_99 ( V_2 ) -> V_350 = F_212 ( V_107 ) ;
F_99 ( V_2 ) -> V_351 = 0 ;
F_99 ( V_2 ) -> V_352 = F_213 ( V_104 ) ;
F_99 ( V_2 ) -> V_353 = 0 ;
V_354:
V_9 = F_214 ( & V_116 , V_2 , F_215 ( V_107 ) , V_107 -> V_7 ,
V_107 -> V_6 , & V_342 ) ;
if ( ! V_9 )
goto V_355;
V_356:
if ( V_9 -> V_118 == V_119 )
goto V_357;
if ( V_9 -> V_118 == V_120 ) {
struct V_95 * V_96 = F_42 ( V_9 ) ;
struct V_8 * V_313 ;
V_9 = V_96 -> V_100 ;
if ( F_60 ( F_148 ( V_9 , V_2 ) ) ) {
F_216 ( V_9 , V_2 ) ;
F_47 ( V_96 ) ;
goto V_344;
}
if ( F_60 ( V_9 -> V_118 != V_133 ) ) {
F_217 ( V_9 , V_96 ) ;
goto V_354;
}
F_10 ( V_9 ) ;
V_342 = true ;
V_313 = F_218 ( V_9 , V_2 , V_96 , false ) ;
if ( ! V_313 ) {
F_47 ( V_96 ) ;
goto V_358;
}
if ( V_313 == V_9 ) {
F_47 ( V_96 ) ;
} else if ( F_178 ( V_9 , V_313 , V_2 ) ) {
F_80 ( V_313 , V_2 ) ;
goto V_358;
} else {
F_73 ( V_9 ) ;
return 0 ;
}
}
if ( F_60 ( V_104 -> V_129 < F_12 ( V_9 ) -> V_130 ) ) {
F_44 ( V_97 , V_131 ) ;
goto V_358;
}
if ( ! F_219 ( V_9 , V_359 , V_2 ) )
goto V_358;
if ( F_148 ( V_9 , V_2 ) )
goto V_358;
F_220 ( V_2 ) ;
if ( F_206 ( V_9 , V_2 ) )
goto V_358;
V_107 = ( const struct V_106 * ) V_2 -> V_105 ;
V_104 = F_3 ( V_2 ) ;
V_2 -> V_115 = NULL ;
if ( V_9 -> V_118 == V_133 ) {
V_343 = F_173 ( V_9 , V_2 ) ;
goto V_360;
}
F_221 ( V_9 ) ;
F_222 ( V_9 ) ;
F_223 ( F_7 ( V_9 ) , V_2 ) ;
V_343 = 0 ;
if ( ! F_59 ( V_9 ) ) {
if ( ! F_188 ( V_9 , V_2 ) )
V_343 = F_173 ( V_9 , V_2 ) ;
} else if ( F_202 ( V_9 , V_2 ) ) {
goto V_358;
}
F_72 ( V_9 ) ;
V_360:
if ( V_342 )
F_73 ( V_9 ) ;
return V_343 ;
V_355:
if ( ! F_219 ( NULL , V_359 , V_2 ) )
goto V_344;
if ( F_177 ( V_2 ) ) {
V_348:
F_100 ( V_97 , V_316 ) ;
V_346:
F_100 ( V_97 , V_317 ) ;
} else {
F_80 ( NULL , V_2 ) ;
}
V_344:
F_180 ( V_2 ) ;
return 0 ;
V_358:
F_216 ( V_9 , V_2 ) ;
if ( V_342 )
F_73 ( V_9 ) ;
goto V_344;
V_357:
if ( ! F_219 ( NULL , V_359 , V_2 ) ) {
F_55 ( F_56 ( V_9 ) ) ;
goto V_344;
}
if ( F_177 ( V_2 ) ) {
F_55 ( F_56 ( V_9 ) ) ;
goto V_348;
}
switch ( F_224 ( F_56 ( V_9 ) , V_2 , V_107 ) ) {
case V_361 : {
struct V_8 * V_362 = F_225 ( F_50 ( V_2 -> V_115 ) ,
& V_116 , V_2 ,
F_215 ( V_107 ) ,
V_104 -> V_5 , V_107 -> V_7 ,
V_104 -> V_4 , V_107 -> V_6 ,
F_53 ( V_2 ) ) ;
if ( V_362 ) {
F_226 ( F_56 ( V_9 ) ) ;
V_9 = V_362 ;
V_342 = false ;
goto V_356;
}
}
case V_363 :
F_105 ( V_9 , V_2 ) ;
break;
case V_364 :
F_80 ( V_9 , V_2 ) ;
F_226 ( F_56 ( V_9 ) ) ;
goto V_344;
case V_365 : ;
}
goto V_344;
}
void F_160 ( struct V_8 * V_9 , const struct V_1 * V_2 )
{
struct V_84 * V_69 = F_84 ( V_2 ) ;
if ( V_69 && F_227 ( V_69 ) ) {
V_9 -> V_309 = V_69 ;
F_12 ( V_9 ) -> V_310 = V_2 -> V_311 ;
}
}
static int F_228 ( struct V_8 * V_9 )
{
struct V_109 * V_110 = F_25 ( V_9 ) ;
F_229 ( V_9 ) ;
V_110 -> V_366 = & V_367 ;
#ifdef F_81
F_7 ( V_9 ) -> V_368 = & V_369 ;
#endif
return 0 ;
}
void F_230 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
F_231 ( V_9 ) ;
F_232 ( V_9 ) ;
F_233 ( V_9 ) ;
F_234 ( & V_15 -> V_370 ) ;
#ifdef F_81
if ( V_15 -> V_238 ) {
F_133 ( V_9 ) ;
F_132 ( V_15 -> V_238 , V_253 ) ;
V_15 -> V_238 = NULL ;
}
#endif
F_235 ( & V_15 -> V_323 . V_325 ) ;
if ( F_25 ( V_9 ) -> V_371 )
F_236 ( V_9 ) ;
F_66 ( V_15 -> V_132 ) ;
F_237 ( V_15 ) ;
F_238 ( V_15 ) ;
F_96 () ;
F_239 ( V_9 ) ;
F_101 () ;
}
static void * F_240 ( struct V_372 * V_94 , void * V_373 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
struct V_97 * V_97 = F_241 ( V_94 ) ;
struct V_377 * V_378 ;
struct V_8 * V_9 = V_373 ;
if ( ! V_9 ) {
V_379:
V_378 = & V_116 . V_380 [ V_375 -> V_381 ] ;
F_242 ( & V_378 -> V_382 ) ;
V_9 = F_243 ( & V_378 -> V_161 ) ;
V_375 -> V_210 = 0 ;
goto V_383;
}
V_378 = & V_116 . V_380 [ V_375 -> V_381 ] ;
++ V_375 -> V_384 ;
++ V_375 -> V_210 ;
V_9 = F_244 ( V_9 ) ;
V_383:
F_245 (sk) {
if ( ! F_246 ( F_8 ( V_9 ) , V_97 ) )
continue;
if ( V_9 -> V_385 == V_375 -> V_233 )
return V_9 ;
}
F_247 ( & V_378 -> V_382 ) ;
V_375 -> V_210 = 0 ;
if ( ++ V_375 -> V_381 < V_386 )
goto V_379;
return NULL ;
}
static void * F_248 ( struct V_372 * V_94 , T_9 * V_387 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
void * V_388 ;
V_375 -> V_381 = 0 ;
V_375 -> V_210 = 0 ;
V_388 = F_240 ( V_94 , NULL ) ;
while ( V_388 && * V_387 ) {
V_388 = F_240 ( V_94 , V_388 ) ;
-- * V_387 ;
}
return V_388 ;
}
static inline bool F_249 ( const struct V_374 * V_375 )
{
return F_250 ( & V_116 . V_389 [ V_375 -> V_381 ] . V_390 ) ;
}
static void * F_251 ( struct V_372 * V_94 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
struct V_97 * V_97 = F_241 ( V_94 ) ;
void * V_388 = NULL ;
V_375 -> V_210 = 0 ;
for (; V_375 -> V_381 <= V_116 . V_391 ; ++ V_375 -> V_381 ) {
struct V_8 * V_9 ;
struct V_392 * V_250 ;
T_10 * V_382 = F_252 ( & V_116 , V_375 -> V_381 ) ;
if ( F_249 ( V_375 ) )
continue;
F_253 ( V_382 ) ;
F_254 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_9 -> V_385 != V_375 -> V_233 ||
! F_246 ( F_8 ( V_9 ) , V_97 ) ) {
continue;
}
V_388 = V_9 ;
goto V_128;
}
F_255 ( V_382 ) ;
}
V_128:
return V_388 ;
}
static void * F_256 ( struct V_372 * V_94 , void * V_373 )
{
struct V_8 * V_9 = V_373 ;
struct V_392 * V_250 ;
struct V_374 * V_375 = V_94 -> V_376 ;
struct V_97 * V_97 = F_241 ( V_94 ) ;
++ V_375 -> V_384 ;
++ V_375 -> V_210 ;
V_9 = F_257 ( V_9 ) ;
F_258 (sk, node) {
if ( V_9 -> V_385 == V_375 -> V_233 && F_246 ( F_8 ( V_9 ) , V_97 ) )
return V_9 ;
}
F_255 ( F_252 ( & V_116 , V_375 -> V_381 ) ) ;
++ V_375 -> V_381 ;
return F_251 ( V_94 ) ;
}
static void * F_259 ( struct V_372 * V_94 , T_9 V_387 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
void * V_388 ;
V_375 -> V_381 = 0 ;
V_388 = F_251 ( V_94 ) ;
while ( V_388 && V_387 ) {
V_388 = F_256 ( V_94 , V_388 ) ;
-- V_387 ;
}
return V_388 ;
}
static void * F_260 ( struct V_372 * V_94 , T_9 V_387 )
{
void * V_388 ;
struct V_374 * V_375 = V_94 -> V_376 ;
V_375 -> V_393 = V_394 ;
V_388 = F_248 ( V_94 , & V_387 ) ;
if ( ! V_388 ) {
V_375 -> V_393 = V_395 ;
V_388 = F_259 ( V_94 , V_387 ) ;
}
return V_388 ;
}
static void * F_261 ( struct V_372 * V_94 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
int V_210 = V_375 -> V_210 ;
int V_396 = V_375 -> V_384 ;
void * V_388 = NULL ;
switch ( V_375 -> V_393 ) {
case V_394 :
if ( V_375 -> V_381 >= V_386 )
break;
V_375 -> V_393 = V_394 ;
V_388 = F_240 ( V_94 , NULL ) ;
while ( V_210 -- && V_388 )
V_388 = F_240 ( V_94 , V_388 ) ;
if ( V_388 )
break;
V_375 -> V_381 = 0 ;
V_375 -> V_393 = V_395 ;
case V_395 :
if ( V_375 -> V_381 > V_116 . V_391 )
break;
V_388 = F_251 ( V_94 ) ;
while ( V_210 -- && V_388 )
V_388 = F_256 ( V_94 , V_388 ) ;
}
V_375 -> V_384 = V_396 ;
return V_388 ;
}
static void * F_262 ( struct V_372 * V_94 , T_9 * V_387 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
void * V_388 ;
if ( * V_387 && * V_387 == V_375 -> V_397 ) {
V_388 = F_261 ( V_94 ) ;
if ( V_388 )
goto V_128;
}
V_375 -> V_393 = V_394 ;
V_375 -> V_384 = 0 ;
V_375 -> V_381 = 0 ;
V_375 -> V_210 = 0 ;
V_388 = * V_387 ? F_260 ( V_94 , * V_387 - 1 ) : V_398 ;
V_128:
V_375 -> V_397 = * V_387 ;
return V_388 ;
}
static void * F_263 ( struct V_372 * V_94 , void * V_399 , T_9 * V_387 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
void * V_388 = NULL ;
if ( V_399 == V_398 ) {
V_388 = F_260 ( V_94 , 0 ) ;
goto V_128;
}
switch ( V_375 -> V_393 ) {
case V_394 :
V_388 = F_240 ( V_94 , V_399 ) ;
if ( ! V_388 ) {
V_375 -> V_393 = V_395 ;
V_375 -> V_381 = 0 ;
V_375 -> V_210 = 0 ;
V_388 = F_251 ( V_94 ) ;
}
break;
case V_395 :
V_388 = F_256 ( V_94 , V_399 ) ;
break;
}
V_128:
++ * V_387 ;
V_375 -> V_397 = * V_387 ;
return V_388 ;
}
static void F_264 ( struct V_372 * V_94 , void * V_399 )
{
struct V_374 * V_375 = V_94 -> V_376 ;
switch ( V_375 -> V_393 ) {
case V_394 :
if ( V_399 != V_398 )
F_247 ( & V_116 . V_380 [ V_375 -> V_381 ] . V_382 ) ;
break;
case V_395 :
if ( V_399 )
F_255 ( F_252 ( & V_116 , V_375 -> V_381 ) ) ;
break;
}
}
int F_265 ( struct V_400 * V_400 , struct V_401 * V_401 )
{
struct V_402 * V_403 = F_266 ( V_400 ) ;
struct V_374 * V_404 ;
int V_39 ;
V_39 = F_267 ( V_400 , V_401 , & V_403 -> V_405 ,
sizeof( struct V_374 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_404 = ( (struct V_372 * ) V_401 -> V_406 ) -> V_376 ;
V_404 -> V_233 = V_403 -> V_233 ;
V_404 -> V_397 = 0 ;
return 0 ;
}
int F_268 ( struct V_97 * V_97 , struct V_402 * V_403 )
{
int V_388 = 0 ;
struct V_407 * V_408 ;
V_403 -> V_405 . V_409 = F_262 ;
V_403 -> V_405 . V_410 = F_263 ;
V_403 -> V_405 . V_411 = F_264 ;
V_408 = F_269 ( V_403 -> V_412 , V_413 , V_97 -> V_414 ,
V_403 -> V_415 , V_403 ) ;
if ( ! V_408 )
V_388 = - V_248 ;
return V_388 ;
}
void F_270 ( struct V_97 * V_97 , struct V_402 * V_403 )
{
F_271 ( V_403 -> V_412 , V_97 -> V_414 ) ;
}
static void F_272 ( const struct V_95 * V_96 ,
struct V_372 * V_416 , int V_417 )
{
const struct V_228 * V_229 = F_108 ( V_96 ) ;
long V_418 = V_96 -> V_419 . V_420 - V_81 ;
F_273 ( V_416 , L_4
L_5 ,
V_417 ,
V_229 -> V_230 ,
V_229 -> V_421 ,
V_229 -> V_231 ,
F_52 ( V_229 -> V_422 ) ,
V_152 ,
0 , 0 ,
1 ,
F_274 ( V_418 ) ,
V_96 -> V_423 ,
F_275 ( F_276 ( V_416 ) ,
F_277 ( V_96 -> V_100 ) ) ,
0 ,
0 ,
0 ,
V_96 ) ;
}
static void F_278 ( struct V_8 * V_9 , struct V_372 * V_416 , int V_417 )
{
int V_424 ;
unsigned long V_425 ;
const struct V_14 * V_15 = F_7 ( V_9 ) ;
const struct V_109 * V_110 = F_25 ( V_9 ) ;
const struct V_30 * V_31 = F_12 ( V_9 ) ;
const struct V_426 * V_427 = & V_110 -> V_428 . V_427 ;
T_3 V_6 = V_31 -> V_65 ;
T_3 V_429 = V_31 -> V_430 ;
T_11 V_431 = F_52 ( V_31 -> V_70 ) ;
T_11 V_432 = F_52 ( V_31 -> V_51 ) ;
int V_433 ;
int V_393 ;
if ( V_110 -> V_434 == V_150 ||
V_110 -> V_434 == V_435 ||
V_110 -> V_434 == V_436 ) {
V_424 = 1 ;
V_425 = V_110 -> V_437 ;
} else if ( V_110 -> V_434 == V_438 ) {
V_424 = 4 ;
V_425 = V_110 -> V_437 ;
} else if ( F_279 ( & V_9 -> V_439 ) ) {
V_424 = 2 ;
V_425 = V_9 -> V_439 . V_420 ;
} else {
V_424 = 0 ;
V_425 = V_81 ;
}
V_393 = F_280 ( V_9 ) ;
if ( V_393 == V_133 )
V_433 = V_9 -> V_440 ;
else
V_433 = F_281 ( int , V_15 -> V_218 - V_15 -> V_441 , 0 ) ;
F_273 ( V_416 , L_6
L_7 ,
V_417 , V_429 , V_432 , V_6 , V_431 , V_393 ,
V_15 -> V_19 - V_15 -> V_113 ,
V_433 ,
V_424 ,
F_274 ( V_425 - V_81 ) ,
V_110 -> V_143 ,
F_275 ( F_276 ( V_416 ) , F_277 ( V_9 ) ) ,
V_110 -> V_442 ,
F_282 ( V_9 ) ,
F_194 ( & V_9 -> V_443 ) , V_9 ,
F_283 ( V_110 -> V_145 ) ,
F_283 ( V_110 -> V_444 . V_445 ) ,
( V_110 -> V_444 . V_446 << 1 ) | V_110 -> V_444 . V_447 ,
V_15 -> V_448 ,
V_393 == V_133 ?
V_427 -> V_449 :
( F_284 ( V_15 ) ? - 1 : V_15 -> V_450 ) ) ;
}
static void F_285 ( const struct V_193 * V_211 ,
struct V_372 * V_416 , int V_417 )
{
long V_418 = V_211 -> V_451 . V_420 - V_81 ;
T_3 V_6 , V_429 ;
T_11 V_431 , V_432 ;
V_6 = V_211 -> V_452 ;
V_429 = V_211 -> V_453 ;
V_431 = F_52 ( V_211 -> V_454 ) ;
V_432 = F_52 ( V_211 -> V_455 ) ;
F_273 ( V_416 , L_4
L_8 ,
V_417 , V_429 , V_432 , V_6 , V_431 , V_211 -> V_456 , 0 , 0 ,
3 , F_274 ( V_418 ) , 0 , 0 , 0 , 0 ,
F_194 ( & V_211 -> V_457 ) , V_211 ) ;
}
static int F_286 ( struct V_372 * V_94 , void * V_399 )
{
struct V_374 * V_375 ;
struct V_8 * V_9 = V_399 ;
F_287 ( V_94 , V_458 - 1 ) ;
if ( V_399 == V_398 ) {
F_288 ( V_94 , L_9
L_10
L_11 ) ;
goto V_128;
}
V_375 = V_94 -> V_376 ;
if ( V_9 -> V_118 == V_119 )
F_285 ( V_399 , V_94 , V_375 -> V_384 ) ;
else if ( V_9 -> V_118 == V_120 )
F_272 ( V_399 , V_94 , V_375 -> V_384 ) ;
else
F_278 ( V_399 , V_94 , V_375 -> V_384 ) ;
V_128:
F_289 ( V_94 , '\n' ) ;
return 0 ;
}
static int T_12 F_290 ( struct V_97 * V_97 )
{
return F_268 ( V_97 , & V_459 ) ;
}
static void T_13 F_291 ( struct V_97 * V_97 )
{
F_270 ( V_97 , & V_459 ) ;
}
int T_14 F_292 ( void )
{
return F_293 ( & V_460 ) ;
}
void F_294 ( void )
{
F_295 ( & V_460 ) ;
}
static void T_13 F_296 ( struct V_97 * V_97 )
{
int V_461 ;
F_297 (cpu)
F_298 ( * F_299 ( V_97 -> V_17 . F_7 , V_461 ) ) ;
F_300 ( V_97 -> V_17 . F_7 ) ;
}
static int T_12 F_301 ( struct V_97 * V_97 )
{
int V_462 , V_461 ;
V_97 -> V_17 . F_7 = F_302 ( struct V_8 * ) ;
if ( ! V_97 -> V_17 . F_7 )
return - V_248 ;
F_297 (cpu) {
struct V_8 * V_9 ;
V_462 = F_303 ( & V_9 , V_463 , V_464 ,
V_59 , V_97 ) ;
if ( V_462 )
goto V_465;
F_304 ( V_9 , V_466 ) ;
* F_299 ( V_97 -> V_17 . F_7 , V_461 ) = V_9 ;
}
V_97 -> V_17 . V_467 = 2 ;
V_97 -> V_17 . V_468 = 1 ;
V_97 -> V_17 . V_469 = V_470 ;
V_97 -> V_17 . V_471 = V_472 ;
V_97 -> V_17 . V_473 = V_474 ;
V_97 -> V_17 . V_475 = V_476 ;
V_97 -> V_17 . V_477 = V_478 ;
V_97 -> V_17 . V_479 = V_480 ;
V_97 -> V_17 . V_481 = V_482 ;
V_97 -> V_17 . V_483 = V_484 ;
V_97 -> V_17 . V_485 = 1 ;
V_97 -> V_17 . V_486 = V_487 ;
V_97 -> V_17 . V_488 = V_489 ;
V_97 -> V_17 . V_490 = V_491 ;
V_97 -> V_17 . V_492 = 0 ;
V_97 -> V_17 . V_493 = V_494 ;
V_97 -> V_17 . V_495 = V_496 ;
V_97 -> V_17 . V_18 = 0 ;
return 0 ;
V_465:
F_296 ( V_97 ) ;
return V_462 ;
}
static void T_13 F_305 ( struct V_497 * V_498 )
{
F_306 ( & V_116 , & V_67 , V_44 ) ;
}
void T_14 F_307 ( void )
{
F_308 ( & V_116 ) ;
if ( F_293 ( & V_499 ) )
F_309 ( L_12 ) ;
}
