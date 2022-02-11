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
T_1 V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 = & F_8 ( V_9 ) -> V_17 . V_44 ;
if ( V_27 < sizeof( struct V_28 ) )
return - V_45 ;
if ( V_29 -> V_46 != V_47 )
return - V_48 ;
V_34 = V_4 = V_29 -> V_49 . V_50 ;
V_42 = F_13 ( V_31 -> V_42 ,
F_14 ( V_9 ) ) ;
if ( V_42 && V_42 -> V_51 . V_52 ) {
if ( ! V_4 )
return - V_45 ;
V_34 = V_42 -> V_51 . V_53 ;
}
V_32 = V_31 -> V_54 ;
V_33 = V_29 -> V_55 ;
V_36 = & V_31 -> V_56 . V_57 . V_58 . V_59 ;
V_38 = F_15 ( V_36 , V_34 , V_31 -> V_60 ,
F_16 ( V_9 ) , V_9 -> V_61 ,
V_62 ,
V_32 , V_33 , V_9 ) ;
if ( F_17 ( V_38 ) ) {
V_39 = F_18 ( V_38 ) ;
if ( V_39 == - V_63 )
F_19 ( F_8 ( V_9 ) , V_64 ) ;
return V_39 ;
}
if ( V_38 -> V_65 & ( V_66 | V_67 ) ) {
F_20 ( V_38 ) ;
return - V_63 ;
}
if ( ! V_42 || ! V_42 -> V_51 . V_52 )
V_4 = V_36 -> V_4 ;
if ( ! V_31 -> V_60 )
V_31 -> V_60 = V_36 -> V_5 ;
F_21 ( V_9 , V_31 -> V_60 ) ;
if ( V_15 -> V_21 . V_24 && V_31 -> V_68 != V_4 ) {
V_15 -> V_21 . V_22 = 0 ;
V_15 -> V_21 . V_24 = 0 ;
if ( F_22 ( ! V_15 -> V_69 ) )
V_15 -> V_19 = 0 ;
}
if ( V_44 -> V_70 &&
! V_15 -> V_21 . V_24 && V_36 -> V_4 == V_4 )
F_23 ( V_9 , & V_38 -> V_71 ) ;
V_31 -> V_72 = V_29 -> V_55 ;
F_24 ( V_9 , V_4 ) ;
F_25 ( V_9 ) -> V_73 = 0 ;
if ( V_42 )
F_25 ( V_9 ) -> V_73 = V_42 -> V_51 . V_74 ;
V_15 -> V_21 . V_75 = V_76 ;
F_26 ( V_9 , V_77 ) ;
V_39 = F_27 ( V_44 , V_9 ) ;
if ( V_39 )
goto V_78;
F_28 ( V_9 ) ;
V_38 = F_29 ( V_36 , V_38 , V_32 , V_33 ,
V_31 -> V_54 , V_31 -> V_72 , V_9 ) ;
if ( F_17 ( V_38 ) ) {
V_39 = F_18 ( V_38 ) ;
V_38 = NULL ;
goto V_78;
}
V_9 -> V_79 = V_80 ;
F_30 ( V_9 , & V_38 -> V_71 ) ;
V_38 = NULL ;
if ( F_22 ( ! V_15 -> V_69 ) ) {
V_40 = F_2 ( V_31 -> V_60 ,
V_31 -> V_68 ,
V_31 -> V_54 ,
V_29 -> V_55 ,
& V_15 -> V_81 ) ;
if ( ! V_15 -> V_19 )
V_15 -> V_19 = V_40 ;
}
V_31 -> V_82 = V_15 -> V_19 ^ V_83 ;
if ( F_31 ( V_9 , & V_39 ) )
return V_39 ;
if ( V_39 )
goto V_78;
V_39 = F_32 ( V_9 ) ;
if ( V_39 )
goto V_78;
return 0 ;
V_78:
F_26 ( V_9 , V_84 ) ;
F_20 ( V_38 ) ;
V_9 -> V_85 = 0 ;
V_31 -> V_72 = 0 ;
return V_39 ;
}
void F_33 ( struct V_8 * V_9 )
{
struct V_30 * V_31 = F_12 ( V_9 ) ;
struct V_86 * V_71 ;
T_1 V_87 ;
if ( ( 1 << V_9 -> V_88 ) & ( V_89 | V_90 ) )
return;
V_87 = F_7 ( V_9 ) -> V_91 ;
V_71 = F_34 ( V_9 , V_87 ) ;
if ( ! V_71 )
return;
if ( V_87 < F_35 ( V_71 ) && F_36 ( V_9 , V_71 ) )
V_9 -> V_92 = V_93 ;
V_87 = F_35 ( V_71 ) ;
if ( V_31 -> V_94 != V_95 &&
F_37 ( V_9 ) &&
F_25 ( V_9 ) -> V_96 > V_87 ) {
F_38 ( V_9 , V_87 ) ;
F_39 ( V_9 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_86 * V_71 = F_41 ( V_9 , 0 ) ;
if ( V_71 )
V_71 -> V_97 -> V_98 ( V_71 , V_9 , V_2 ) ;
}
void F_42 ( struct V_8 * V_9 , T_1 V_40 , bool abort )
{
struct V_99 * V_100 = F_43 ( V_9 ) ;
struct V_101 * V_101 = F_8 ( V_9 ) ;
if ( V_40 != F_44 ( V_100 ) -> V_102 ) {
F_45 ( V_101 , V_103 ) ;
} else if ( abort ) {
F_46 ( V_100 -> V_104 , V_100 ) ;
F_47 ( V_100 -> V_104 ) ;
}
F_48 ( V_100 ) ;
}
void F_49 ( struct V_1 * V_105 , T_1 V_106 )
{
const struct V_107 * V_108 = ( const struct V_107 * ) V_105 -> V_109 ;
struct V_110 * V_111 = (struct V_110 * ) ( V_105 -> V_109 + ( V_108 -> V_112 << 2 ) ) ;
struct V_113 * V_114 ;
struct V_14 * V_15 ;
struct V_30 * V_31 ;
const int type = F_50 ( V_105 ) -> type ;
const int V_115 = F_50 ( V_105 ) -> V_115 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_99 * V_116 ;
T_4 V_40 , V_117 ;
T_4 V_118 ;
int V_39 ;
struct V_101 * V_101 = F_51 ( V_105 -> V_119 ) ;
V_9 = F_52 ( V_101 , & V_120 , V_108 -> V_4 ,
V_111 -> V_6 , V_108 -> V_5 , F_53 ( V_111 -> V_7 ) ,
F_54 ( V_105 ) ) ;
if ( ! V_9 ) {
F_55 ( V_101 , V_121 ) ;
return;
}
if ( V_9 -> V_88 == V_122 ) {
F_56 ( F_57 ( V_9 ) ) ;
return;
}
V_40 = F_58 ( V_111 -> V_40 ) ;
if ( V_9 -> V_88 == V_123 )
return F_42 ( V_9 , V_40 ,
type == V_124 ||
type == V_125 ||
( type == V_126 &&
( V_115 == V_127 ||
V_115 == V_128 ) ) ) ;
F_59 ( V_9 ) ;
if ( F_60 ( V_9 ) ) {
if ( ! ( type == V_126 && V_115 == V_129 ) )
F_45 ( V_101 , V_130 ) ;
}
if ( V_9 -> V_88 == V_84 )
goto V_131;
if ( F_61 ( V_108 -> V_132 < F_12 ( V_9 ) -> V_133 ) ) {
F_45 ( V_101 , V_134 ) ;
goto V_131;
}
V_114 = F_25 ( V_9 ) ;
V_15 = F_7 ( V_9 ) ;
V_116 = V_15 -> V_135 ;
V_117 = V_116 ? F_44 ( V_116 ) -> V_102 : V_15 -> V_117 ;
if ( V_9 -> V_88 != V_136 &&
! F_62 ( V_40 , V_117 , V_15 -> V_137 ) ) {
F_45 ( V_101 , V_103 ) ;
goto V_131;
}
switch ( type ) {
case V_138 :
if ( ! F_60 ( V_9 ) )
F_40 ( V_105 , V_9 ) ;
goto V_131;
case V_139 :
goto V_131;
case V_124 :
V_39 = V_140 ;
break;
case V_126 :
if ( V_115 > V_141 )
goto V_131;
if ( V_115 == V_129 ) {
if ( V_9 -> V_88 == V_136 )
goto V_131;
V_15 -> V_91 = V_106 ;
if ( ! F_60 ( V_9 ) ) {
F_33 ( V_9 ) ;
} else {
if ( ! F_63 ( V_142 , & V_9 -> V_143 ) )
F_10 ( V_9 ) ;
}
goto V_131;
}
V_39 = V_144 [ V_115 ] . V_145 ;
if ( V_115 != V_127 && V_115 != V_128 )
break;
if ( V_40 != V_15 -> V_117 || ! V_114 -> V_146 ||
! V_114 -> V_147 || V_116 )
break;
if ( F_60 ( V_9 ) )
break;
V_114 -> V_147 -- ;
V_114 -> V_148 = V_15 -> V_149 ? F_64 ( V_15 ) :
V_150 ;
V_114 -> V_148 = F_65 ( V_114 , V_151 ) ;
V_2 = F_66 ( V_9 ) ;
F_67 ( ! V_2 ) ;
V_118 = V_114 -> V_148 -
F_68 ( V_114 -> V_148 ,
V_152 - F_69 ( V_2 ) ) ;
if ( V_118 ) {
F_70 ( V_9 , V_153 ,
V_118 , V_151 ) ;
} else {
F_71 ( V_9 ) ;
}
break;
case V_125 :
V_39 = V_154 ;
break;
default:
goto V_131;
}
switch ( V_9 -> V_88 ) {
case V_77 :
case V_155 :
if ( V_116 && ! V_116 -> V_9 )
break;
if ( ! F_60 ( V_9 ) ) {
V_9 -> V_156 = V_39 ;
V_9 -> V_157 ( V_9 ) ;
F_72 ( V_9 ) ;
} else {
V_9 -> V_92 = V_39 ;
}
goto V_131;
}
V_31 = F_12 ( V_9 ) ;
if ( ! F_60 ( V_9 ) && V_31 -> V_158 ) {
V_9 -> V_156 = V_39 ;
V_9 -> V_157 ( V_9 ) ;
} else {
V_9 -> V_92 = V_39 ;
}
V_131:
F_73 ( V_9 ) ;
F_74 ( V_9 ) ;
}
void F_75 ( struct V_1 * V_2 , T_3 V_5 , T_3 V_4 )
{
struct V_110 * V_111 = F_4 ( V_2 ) ;
if ( V_2 -> V_159 == V_160 ) {
V_111 -> V_161 = ~ F_76 ( V_2 -> V_162 , V_5 , V_4 , 0 ) ;
V_2 -> V_163 = F_77 ( V_2 ) - V_2 -> V_164 ;
V_2 -> V_165 = F_78 ( struct V_110 , V_161 ) ;
} else {
V_111 -> V_161 = F_76 ( V_2 -> V_162 , V_5 , V_4 ,
F_79 ( V_111 ,
V_111 -> V_166 << 2 ,
V_2 -> V_167 ) ) ;
}
}
void F_80 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_30 * V_31 = F_12 ( V_9 ) ;
F_75 ( V_2 , V_31 -> V_60 , V_31 -> V_68 ) ;
}
static void F_81 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_110 * V_111 = F_4 ( V_2 ) ;
struct {
struct V_110 V_111 ;
#ifdef F_82
T_3 V_51 [ ( V_168 >> 2 ) ] ;
#endif
} V_169 ;
struct V_170 V_171 ;
#ifdef F_82
struct V_172 * V_173 = NULL ;
const T_5 * V_174 = NULL ;
unsigned char V_175 [ 16 ] ;
int V_176 ;
struct V_8 * V_177 = NULL ;
#endif
struct V_101 * V_101 ;
if ( V_111 -> V_178 )
return;
if ( ! V_9 && F_83 ( V_2 ) -> V_179 != V_180 )
return;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_111 . V_6 = V_111 -> V_7 ;
V_169 . V_111 . V_7 = V_111 -> V_6 ;
V_169 . V_111 . V_166 = sizeof( struct V_110 ) / 4 ;
V_169 . V_111 . V_178 = 1 ;
if ( V_111 -> V_181 ) {
V_169 . V_111 . V_40 = V_111 -> V_182 ;
} else {
V_169 . V_111 . V_181 = 1 ;
V_169 . V_111 . V_182 = F_84 ( F_58 ( V_111 -> V_40 ) + V_111 -> V_183 + V_111 -> V_184 +
V_2 -> V_162 - ( V_111 -> V_166 << 2 ) ) ;
}
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_185 [ 0 ] . V_186 = ( unsigned char * ) & V_169 ;
V_171 . V_185 [ 0 ] . V_187 = sizeof( V_169 . V_111 ) ;
V_101 = V_9 ? F_8 ( V_9 ) : F_51 ( F_85 ( V_2 ) -> V_119 ) ;
#ifdef F_82
F_86 () ;
V_174 = F_87 ( V_111 ) ;
if ( V_9 && F_88 ( V_9 ) ) {
V_173 = F_89 ( V_9 , (union V_188 * )
& F_3 ( V_2 ) -> V_5 , V_47 ) ;
} else if ( V_174 ) {
V_177 = F_90 ( V_101 , & V_120 , NULL , 0 ,
F_3 ( V_2 ) -> V_5 ,
V_111 -> V_7 , F_3 ( V_2 ) -> V_4 ,
F_53 ( V_111 -> V_7 ) , F_54 ( V_2 ) ) ;
if ( ! V_177 )
goto V_131;
V_173 = F_89 ( V_177 , (union V_188 * )
& F_3 ( V_2 ) -> V_5 , V_47 ) ;
if ( ! V_173 )
goto V_131;
V_176 = F_91 ( V_175 , V_173 , NULL , V_2 ) ;
if ( V_176 || memcmp ( V_174 , V_175 , 16 ) != 0 )
goto V_131;
}
if ( V_173 ) {
V_169 . V_51 [ 0 ] = F_84 ( ( V_189 << 24 ) |
( V_189 << 16 ) |
( V_190 << 8 ) |
V_191 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_168 ;
V_169 . V_111 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
F_92 ( ( T_5 * ) & V_169 . V_51 [ 1 ] ,
V_173 , F_3 ( V_2 ) -> V_5 ,
F_3 ( V_2 ) -> V_4 , & V_169 . V_111 ) ;
}
#endif
V_171 . V_167 = F_93 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_5 ,
V_171 . V_185 [ 0 ] . V_187 , V_62 , 0 ) ;
V_171 . V_192 = F_78 ( struct V_110 , V_161 ) / 2 ;
V_171 . V_193 = ( V_9 && F_94 ( V_9 ) ) ? V_194 : 0 ;
if ( V_9 )
V_171 . V_195 = V_9 -> V_61 ;
F_95 ( F_78 ( struct V_8 , V_61 ) !=
F_78 ( struct V_196 , V_197 ) ) ;
V_171 . V_198 = F_3 ( V_2 ) -> V_198 ;
V_171 . V_199 = F_96 ( V_101 , V_9 && F_88 ( V_9 ) ? V_9 : NULL ) ;
F_97 () ;
F_98 ( * F_99 ( V_101 -> V_17 . F_7 ) ,
V_2 , & F_100 ( V_2 ) -> V_200 . V_201 . V_51 ,
F_3 ( V_2 ) -> V_5 , F_3 ( V_2 ) -> V_4 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_101 ( V_101 , V_202 ) ;
F_101 ( V_101 , V_203 ) ;
F_102 () ;
#ifdef F_82
V_131:
F_103 () ;
#endif
}
static void F_104 ( const struct V_8 * V_9 ,
struct V_1 * V_2 , T_1 V_40 , T_1 V_181 ,
T_1 V_204 , T_1 V_205 , T_1 V_206 , int V_207 ,
struct V_172 * V_173 ,
int V_208 , T_6 V_198 )
{
const struct V_110 * V_111 = F_4 ( V_2 ) ;
struct {
struct V_110 V_111 ;
T_3 V_51 [ ( V_209 >> 2 )
#ifdef F_82
+ ( V_168 >> 2 )
#endif
] ;
} V_169 ;
struct V_101 * V_101 = F_8 ( V_9 ) ;
struct V_170 V_171 ;
memset ( & V_169 . V_111 , 0 , sizeof( struct V_110 ) ) ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_185 [ 0 ] . V_186 = ( unsigned char * ) & V_169 ;
V_171 . V_185 [ 0 ] . V_187 = sizeof( V_169 . V_111 ) ;
if ( V_206 ) {
V_169 . V_51 [ 0 ] = F_84 ( ( V_189 << 24 ) | ( V_189 << 16 ) |
( V_210 << 8 ) |
V_211 ) ;
V_169 . V_51 [ 1 ] = F_84 ( V_205 ) ;
V_169 . V_51 [ 2 ] = F_84 ( V_206 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_209 ;
}
V_169 . V_111 . V_6 = V_111 -> V_7 ;
V_169 . V_111 . V_7 = V_111 -> V_6 ;
V_169 . V_111 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
V_169 . V_111 . V_40 = F_84 ( V_40 ) ;
V_169 . V_111 . V_182 = F_84 ( V_181 ) ;
V_169 . V_111 . V_181 = 1 ;
V_169 . V_111 . V_212 = F_105 ( V_204 ) ;
#ifdef F_82
if ( V_173 ) {
int V_213 = ( V_206 ) ? 3 : 0 ;
V_169 . V_51 [ V_213 ++ ] = F_84 ( ( V_189 << 24 ) |
( V_189 << 16 ) |
( V_190 << 8 ) |
V_191 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_168 ;
V_169 . V_111 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
F_92 ( ( T_5 * ) & V_169 . V_51 [ V_213 ] ,
V_173 , F_3 ( V_2 ) -> V_5 ,
F_3 ( V_2 ) -> V_4 , & V_169 . V_111 ) ;
}
#endif
V_171 . V_193 = V_208 ;
V_171 . V_167 = F_93 ( F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_5 ,
V_171 . V_185 [ 0 ] . V_187 , V_62 , 0 ) ;
V_171 . V_192 = F_78 ( struct V_110 , V_161 ) / 2 ;
if ( V_207 )
V_171 . V_195 = V_207 ;
V_171 . V_198 = V_198 ;
V_171 . V_199 = F_96 ( V_101 , F_88 ( V_9 ) ? V_9 : NULL ) ;
F_97 () ;
F_98 ( * F_99 ( V_101 -> V_17 . F_7 ) ,
V_2 , & F_100 ( V_2 ) -> V_200 . V_201 . V_51 ,
F_3 ( V_2 ) -> V_5 , F_3 ( V_2 ) -> V_4 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_101 ( V_101 , V_202 ) ;
F_102 () ;
}
static void F_106 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_196 * V_214 = F_57 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
F_104 ( V_9 , V_2 ,
V_13 -> V_20 , V_13 -> V_215 ,
V_13 -> V_216 >> V_214 -> V_217 ,
V_152 + V_13 -> V_218 ,
V_13 -> V_23 ,
V_214 -> V_197 ,
F_107 ( V_13 ) ,
V_214 -> V_219 ? V_194 : 0 ,
V_214 -> V_220
) ;
F_56 ( V_214 ) ;
}
static void F_108 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_99 * V_100 )
{
T_1 V_40 = ( V_9 -> V_88 == V_136 ) ? F_44 ( V_100 ) -> V_102 + 1 :
F_7 ( V_9 ) -> V_137 ;
F_104 ( V_9 , V_2 , V_40 ,
F_44 ( V_100 ) -> V_221 ,
V_100 -> V_222 >> F_109 ( V_100 ) -> V_223 ,
V_152 + F_44 ( V_100 ) -> V_224 ,
V_100 -> V_22 ,
0 ,
F_89 ( V_9 , (union V_188 * ) & F_3 ( V_2 ) -> V_4 ,
V_47 ) ,
F_109 ( V_100 ) -> V_225 ? V_194 : 0 ,
F_3 ( V_2 ) -> V_198 ) ;
}
static int F_110 ( const struct V_8 * V_9 , struct V_86 * V_71 ,
struct V_226 * V_57 ,
struct V_99 * V_100 ,
struct V_227 * V_228 ,
enum V_229 V_230 )
{
const struct V_231 * V_232 = F_109 ( V_100 ) ;
struct V_35 V_36 ;
int V_39 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_71 && ( V_71 = F_111 ( V_9 , & V_36 , V_100 ) ) == NULL )
return - 1 ;
V_2 = F_112 ( V_9 , V_71 , V_100 , V_228 , V_230 ) ;
if ( V_2 ) {
F_75 ( V_2 , V_232 -> V_233 , V_232 -> V_234 ) ;
V_39 = F_113 ( V_2 , V_9 , V_232 -> V_233 ,
V_232 -> V_234 ,
V_232 -> V_51 ) ;
V_39 = F_114 ( V_39 ) ;
}
return V_39 ;
}
static void F_115 ( struct V_99 * V_100 )
{
F_116 ( F_109 ( V_100 ) -> V_51 ) ;
}
struct V_172 * F_89 ( const struct V_8 * V_9 ,
const union V_188 * V_235 ,
int V_236 )
{
const struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_172 * V_173 ;
unsigned int V_237 = sizeof( struct V_238 ) ;
const struct V_239 * V_240 ;
V_240 = F_117 ( V_15 -> V_241 ,
F_14 ( V_9 ) ) ;
if ( ! V_240 )
return NULL ;
#if F_118 ( V_242 )
if ( V_236 == V_243 )
V_237 = sizeof( struct V_244 ) ;
#endif
F_119 (key, &md5sig->head, node) {
if ( V_173 -> V_236 != V_236 )
continue;
if ( ! memcmp ( & V_173 -> V_235 , V_235 , V_237 ) )
return V_173 ;
}
return NULL ;
}
struct V_172 * F_120 ( const struct V_8 * V_9 ,
const struct V_8 * V_245 )
{
const union V_188 * V_235 ;
V_235 = ( const union V_188 * ) & V_245 -> V_246 ;
return F_89 ( V_9 , V_235 , V_47 ) ;
}
int F_121 ( struct V_8 * V_9 , const union V_188 * V_235 ,
int V_236 , const T_6 * V_247 , T_6 V_248 , T_7 V_249 )
{
struct V_172 * V_173 ;
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_239 * V_240 ;
V_173 = F_89 ( V_9 , V_235 , V_236 ) ;
if ( V_173 ) {
memcpy ( V_173 -> V_173 , V_247 , V_248 ) ;
V_173 -> V_250 = V_248 ;
return 0 ;
}
V_240 = F_13 ( V_15 -> V_241 ,
F_14 ( V_9 ) ) ;
if ( ! V_240 ) {
V_240 = F_122 ( sizeof( * V_240 ) , V_249 ) ;
if ( ! V_240 )
return - V_251 ;
F_123 ( V_9 , V_252 ) ;
F_124 ( & V_240 -> V_164 ) ;
F_125 ( V_15 -> V_241 , V_240 ) ;
}
V_173 = F_126 ( V_9 , sizeof( * V_173 ) , V_249 ) ;
if ( ! V_173 )
return - V_251 ;
if ( ! F_127 () ) {
F_128 ( V_9 , V_173 , sizeof( * V_173 ) ) ;
return - V_251 ;
}
memcpy ( V_173 -> V_173 , V_247 , V_248 ) ;
V_173 -> V_250 = V_248 ;
V_173 -> V_236 = V_236 ;
memcpy ( & V_173 -> V_235 , V_235 ,
( V_236 == V_243 ) ? sizeof( struct V_244 ) :
sizeof( struct V_238 ) ) ;
F_129 ( & V_173 -> V_253 , & V_240 -> V_164 ) ;
return 0 ;
}
int F_130 ( struct V_8 * V_9 , const union V_188 * V_235 , int V_236 )
{
struct V_172 * V_173 ;
V_173 = F_89 ( V_9 , V_235 , V_236 ) ;
if ( ! V_173 )
return - V_254 ;
F_131 ( & V_173 -> V_253 ) ;
F_132 ( sizeof( * V_173 ) , & V_9 -> V_255 ) ;
F_133 ( V_173 , V_256 ) ;
return 0 ;
}
static void F_134 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_172 * V_173 ;
struct V_257 * V_258 ;
struct V_239 * V_240 ;
V_240 = F_13 ( V_15 -> V_241 , 1 ) ;
F_135 (key, n, &md5sig->head, node) {
F_131 ( & V_173 -> V_253 ) ;
F_132 ( sizeof( * V_173 ) , & V_9 -> V_255 ) ;
F_133 ( V_173 , V_256 ) ;
}
}
static int F_136 ( struct V_8 * V_9 , char T_8 * V_259 ,
int V_74 )
{
struct V_260 V_261 ;
struct V_28 * sin = (struct V_28 * ) & V_261 . V_262 ;
if ( V_74 < sizeof( V_261 ) )
return - V_45 ;
if ( F_137 ( & V_261 , V_259 , sizeof( V_261 ) ) )
return - V_263 ;
if ( sin -> V_46 != V_47 )
return - V_45 ;
if ( ! V_261 . V_264 )
return F_130 ( V_9 , (union V_188 * ) & sin -> V_49 . V_50 ,
V_47 ) ;
if ( V_261 . V_264 > V_265 )
return - V_45 ;
return F_121 ( V_9 , (union V_188 * ) & sin -> V_49 . V_50 ,
V_47 , V_261 . V_266 , V_261 . V_264 ,
V_267 ) ;
}
static int F_138 ( struct V_268 * V_269 ,
T_3 V_4 , T_3 V_5 ,
const struct V_110 * V_111 , int V_270 )
{
struct V_271 * V_272 ;
struct V_273 V_274 ;
struct V_110 * V_275 ;
V_272 = V_269 -> V_276 ;
V_272 -> V_5 = V_5 ;
V_272 -> V_4 = V_4 ;
V_272 -> V_277 = 0 ;
V_272 -> V_278 = V_62 ;
V_272 -> V_162 = F_139 ( V_270 ) ;
V_275 = (struct V_110 * ) ( V_272 + 1 ) ;
memcpy ( V_275 , V_111 , sizeof( * V_111 ) ) ;
V_275 -> V_161 = 0 ;
F_140 ( & V_274 , V_272 , sizeof( * V_272 ) + sizeof( * V_111 ) ) ;
F_141 ( V_269 -> V_279 , & V_274 , NULL ,
sizeof( * V_272 ) + sizeof( * V_111 ) ) ;
return F_142 ( V_269 -> V_279 ) ;
}
static int F_92 ( char * V_280 , const struct V_172 * V_173 ,
T_3 V_4 , T_3 V_5 , const struct V_110 * V_111 )
{
struct V_268 * V_269 ;
struct V_281 * V_100 ;
V_269 = F_143 () ;
if ( ! V_269 )
goto V_282;
V_100 = V_269 -> V_279 ;
if ( F_144 ( V_100 ) )
goto V_283;
if ( F_138 ( V_269 , V_4 , V_5 , V_111 , V_111 -> V_166 << 2 ) )
goto V_283;
if ( F_145 ( V_269 , V_173 ) )
goto V_283;
F_141 ( V_100 , NULL , V_280 , 0 ) ;
if ( F_146 ( V_100 ) )
goto V_283;
F_147 () ;
return 0 ;
V_283:
F_147 () ;
V_282:
memset ( V_280 , 0 , 16 ) ;
return 1 ;
}
int F_91 ( char * V_280 , const struct V_172 * V_173 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_268 * V_269 ;
struct V_281 * V_100 ;
const struct V_110 * V_111 = F_4 ( V_2 ) ;
T_3 V_5 , V_4 ;
if ( V_9 ) {
V_5 = V_9 -> V_284 ;
V_4 = V_9 -> V_246 ;
} else {
const struct V_107 * V_108 = F_3 ( V_2 ) ;
V_5 = V_108 -> V_5 ;
V_4 = V_108 -> V_4 ;
}
V_269 = F_143 () ;
if ( ! V_269 )
goto V_282;
V_100 = V_269 -> V_279 ;
if ( F_144 ( V_100 ) )
goto V_283;
if ( F_138 ( V_269 , V_4 , V_5 , V_111 , V_2 -> V_162 ) )
goto V_283;
if ( F_148 ( V_269 , V_2 , V_111 -> V_166 << 2 ) )
goto V_283;
if ( F_145 ( V_269 , V_173 ) )
goto V_283;
F_141 ( V_100 , NULL , V_280 , 0 ) ;
if ( F_146 ( V_100 ) )
goto V_283;
F_147 () ;
return 0 ;
V_283:
F_147 () ;
V_282:
memset ( V_280 , 0 , 16 ) ;
return 1 ;
}
static bool F_149 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
#ifdef F_82
const T_5 * V_174 = NULL ;
struct V_172 * V_285 ;
const struct V_107 * V_108 = F_3 ( V_2 ) ;
const struct V_110 * V_111 = F_4 ( V_2 ) ;
int V_176 ;
unsigned char V_175 [ 16 ] ;
V_285 = F_89 ( V_9 , (union V_188 * ) & V_108 -> V_5 ,
V_47 ) ;
V_174 = F_87 ( V_111 ) ;
if ( ! V_285 && ! V_174 )
return false ;
if ( V_285 && ! V_174 ) {
F_150 ( F_8 ( V_9 ) , V_286 ) ;
return true ;
}
if ( ! V_285 && V_174 ) {
F_150 ( F_8 ( V_9 ) , V_287 ) ;
return true ;
}
V_176 = F_91 ( V_175 ,
V_285 ,
NULL , V_2 ) ;
if ( V_176 || memcmp ( V_174 , V_175 , 16 ) != 0 ) {
F_150 ( F_8 ( V_9 ) , V_288 ) ;
F_151 ( L_1 ,
& V_108 -> V_5 , F_53 ( V_111 -> V_7 ) ,
& V_108 -> V_4 , F_53 ( V_111 -> V_6 ) ,
V_176 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_152 ( struct V_99 * V_100 ,
const struct V_8 * V_289 ,
struct V_1 * V_2 )
{
struct V_231 * V_232 = F_109 ( V_100 ) ;
F_21 ( F_153 ( V_100 ) , F_3 ( V_2 ) -> V_4 ) ;
F_24 ( F_153 ( V_100 ) , F_3 ( V_2 ) -> V_5 ) ;
V_232 -> V_51 = F_154 ( V_2 ) ;
}
static struct V_86 * F_155 ( const struct V_8 * V_9 ,
struct V_226 * V_57 ,
const struct V_99 * V_100 ,
bool * V_290 )
{
struct V_86 * V_71 = F_111 ( V_9 , & V_57 -> V_58 . V_59 , V_100 ) ;
if ( V_290 ) {
if ( V_57 -> V_58 . V_59 . V_4 == F_109 ( V_100 ) -> V_234 )
* V_290 = true ;
else
* V_290 = false ;
}
return V_71 ;
}
int F_156 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_83 ( V_2 ) -> V_65 & ( V_67 | V_66 ) )
goto V_291;
return F_157 ( & V_292 ,
& V_293 , V_9 , V_2 ) ;
V_291:
F_47 ( V_9 ) ;
return 0 ;
}
struct V_8 * F_158 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_99 * V_100 ,
struct V_86 * V_71 ,
struct V_99 * V_294 ,
bool * V_295 )
{
struct V_231 * V_232 ;
struct V_30 * V_296 ;
struct V_14 * V_297 ;
struct V_8 * V_298 ;
#ifdef F_82
struct V_172 * V_173 ;
#endif
struct V_41 * V_42 ;
if ( F_159 ( V_9 ) )
goto V_299;
V_298 = F_160 ( V_9 , V_100 , V_2 ) ;
if ( ! V_298 )
goto V_300;
V_298 -> V_79 = V_80 ;
F_161 ( V_298 , V_2 ) ;
V_297 = F_7 ( V_298 ) ;
V_296 = F_12 ( V_298 ) ;
V_232 = F_109 ( V_100 ) ;
F_24 ( V_298 , V_232 -> V_234 ) ;
F_21 ( V_298 , V_232 -> V_233 ) ;
V_298 -> V_61 = V_232 -> V_301 ;
V_296 -> V_60 = V_232 -> V_233 ;
V_42 = V_232 -> V_51 ;
F_125 ( V_296 -> V_42 , V_42 ) ;
V_232 -> V_51 = NULL ;
V_296 -> V_302 = F_54 ( V_2 ) ;
V_296 -> V_303 = F_3 ( V_2 ) -> V_132 ;
V_296 -> V_304 = F_3 ( V_2 ) -> V_198 ;
F_25 ( V_298 ) -> V_73 = 0 ;
if ( V_42 )
F_25 ( V_298 ) -> V_73 = V_42 -> V_51 . V_74 ;
V_296 -> V_82 = V_297 -> V_19 ^ V_83 ;
if ( ! V_71 ) {
V_71 = F_162 ( V_9 , V_298 , V_100 ) ;
if ( ! V_71 )
goto V_305;
} else {
}
F_30 ( V_298 , V_71 ) ;
F_163 ( V_298 , V_71 ) ;
F_38 ( V_298 , F_35 ( V_71 ) ) ;
V_297 -> V_306 = F_164 ( F_7 ( V_9 ) , F_165 ( V_71 ) ) ;
F_166 ( V_298 ) ;
#ifdef F_82
V_173 = F_89 ( V_9 , (union V_188 * ) & V_296 -> V_68 ,
V_47 ) ;
if ( V_173 ) {
F_121 ( V_298 , (union V_188 * ) & V_296 -> V_68 ,
V_47 , V_173 -> V_173 , V_173 -> V_250 , V_307 ) ;
F_123 ( V_298 , V_252 ) ;
}
#endif
if ( F_167 ( V_9 , V_298 ) < 0 )
goto V_305;
* V_295 = F_168 ( V_298 , F_153 ( V_294 ) ) ;
if ( * V_295 )
F_169 ( V_297 , V_100 ) ;
return V_298 ;
V_299:
F_150 ( F_8 ( V_9 ) , V_308 ) ;
V_300:
F_170 ( V_71 ) ;
exit:
F_47 ( V_9 ) ;
return NULL ;
V_305:
F_171 ( V_298 ) ;
F_72 ( V_298 ) ;
goto exit;
}
static struct V_8 * F_172 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_173
const struct V_110 * V_111 = F_4 ( V_2 ) ;
if ( ! V_111 -> V_183 )
V_9 = F_174 ( V_9 , V_2 ) ;
#endif
return V_9 ;
}
int F_175 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_8 * V_309 ;
if ( V_9 -> V_88 == V_310 ) {
struct V_86 * V_71 = V_9 -> V_311 ;
F_176 ( V_9 , V_2 ) ;
F_177 ( V_9 , V_2 ) ;
if ( V_71 ) {
if ( F_12 ( V_9 ) -> V_312 != V_2 -> V_313 ||
! V_71 -> V_97 -> V_161 ( V_71 , 0 ) ) {
F_170 ( V_71 ) ;
V_9 -> V_311 = NULL ;
}
}
F_178 ( V_9 , V_2 , F_4 ( V_2 ) , V_2 -> V_162 ) ;
return 0 ;
}
if ( F_179 ( V_2 ) )
goto V_314;
if ( V_9 -> V_88 == V_136 ) {
struct V_8 * V_315 = F_172 ( V_9 , V_2 ) ;
if ( ! V_315 )
goto V_316;
if ( V_315 != V_9 ) {
F_176 ( V_315 , V_2 ) ;
F_177 ( V_315 , V_2 ) ;
if ( F_180 ( V_9 , V_315 , V_2 ) ) {
V_309 = V_315 ;
goto V_317;
}
return 0 ;
}
} else
F_176 ( V_9 , V_2 ) ;
if ( F_181 ( V_9 , V_2 ) ) {
V_309 = V_9 ;
goto V_317;
}
return 0 ;
V_317:
F_81 ( V_309 , V_2 ) ;
V_316:
F_182 ( V_2 ) ;
return 0 ;
V_314:
F_183 ( F_8 ( V_9 ) , V_318 ) ;
F_183 ( F_8 ( V_9 ) , V_319 ) ;
goto V_316;
}
void F_184 ( struct V_1 * V_2 )
{
const struct V_107 * V_108 ;
const struct V_110 * V_111 ;
struct V_8 * V_9 ;
if ( V_2 -> V_320 != V_321 )
return;
if ( ! F_185 ( V_2 , F_186 ( V_2 ) + sizeof( struct V_110 ) ) )
return;
V_108 = F_3 ( V_2 ) ;
V_111 = F_4 ( V_2 ) ;
if ( V_111 -> V_166 < sizeof( struct V_110 ) / 4 )
return;
V_9 = F_52 ( F_51 ( V_2 -> V_119 ) , & V_120 ,
V_108 -> V_5 , V_111 -> V_7 ,
V_108 -> V_4 , F_53 ( V_111 -> V_6 ) ,
V_2 -> V_313 ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_322 = V_323 ;
if ( F_88 ( V_9 ) ) {
struct V_86 * V_71 = F_187 ( V_9 -> V_311 ) ;
if ( V_71 )
V_71 = F_188 ( V_71 , 0 ) ;
if ( V_71 &&
F_12 ( V_9 ) -> V_312 == V_2 -> V_313 )
F_189 ( V_2 , V_71 ) ;
}
}
}
bool F_190 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
if ( V_324 || ! V_15 -> V_325 . V_326 )
return false ;
if ( V_2 -> V_162 <= F_191 ( V_2 ) &&
F_192 ( & V_15 -> V_325 . V_327 ) == 0 )
return false ;
if ( F_22 ( V_9 -> V_311 ) )
F_193 ( V_2 ) ;
else
F_194 ( V_2 ) ;
F_195 ( & V_15 -> V_325 . V_327 , V_2 ) ;
V_15 -> V_325 . V_328 += V_2 -> V_329 ;
if ( F_192 ( & V_15 -> V_325 . V_327 ) >= 32 ||
V_15 -> V_325 . V_328 + F_196 ( & V_9 -> V_330 ) > V_9 -> V_331 ) {
struct V_1 * V_332 ;
F_67 ( F_60 ( V_9 ) ) ;
F_197 ( F_8 ( V_9 ) , V_333 ,
F_192 ( & V_15 -> V_325 . V_327 ) ) ;
while ( ( V_332 = F_198 ( & V_15 -> V_325 . V_327 ) ) != NULL )
F_199 ( V_9 , V_332 ) ;
V_15 -> V_325 . V_328 = 0 ;
} else if ( F_192 ( & V_15 -> V_325 . V_327 ) == 1 ) {
F_200 ( F_201 ( V_9 ) ,
V_334 | V_335 | V_336 ) ;
if ( ! F_202 ( V_9 ) )
F_70 ( V_9 , V_337 ,
( 3 * F_203 ( V_9 ) ) / 4 ,
V_151 ) ;
}
return true ;
}
bool F_204 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_338 = V_9 -> V_331 + V_9 -> V_339 ;
V_338 += 64 * 1024 ;
F_205 ( V_2 ) ;
if ( F_61 ( F_206 ( V_9 , V_2 , V_338 ) ) ) {
F_73 ( V_9 ) ;
F_45 ( F_8 ( V_9 ) , V_340 ) ;
return true ;
}
return false ;
}
int F_207 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_110 * V_111 = (struct V_110 * ) V_2 -> V_109 ;
unsigned int V_341 = V_2 -> V_162 ;
int V_39 ;
V_39 = F_208 ( V_9 , V_2 , V_111 -> V_166 * 4 ) ;
if ( ! V_39 ) {
V_341 -= V_2 -> V_162 ;
F_100 ( V_2 ) -> V_342 -= V_341 ;
}
return V_39 ;
}
int F_209 ( struct V_1 * V_2 )
{
struct V_101 * V_101 = F_51 ( V_2 -> V_119 ) ;
const struct V_107 * V_108 ;
const struct V_110 * V_111 ;
bool V_343 ;
struct V_8 * V_9 ;
int V_344 ;
if ( V_2 -> V_320 != V_321 )
goto V_345;
F_101 ( V_101 , V_346 ) ;
if ( ! F_185 ( V_2 , sizeof( struct V_110 ) ) )
goto V_345;
V_111 = ( const struct V_110 * ) V_2 -> V_109 ;
if ( F_61 ( V_111 -> V_166 < sizeof( struct V_110 ) / 4 ) )
goto V_347;
if ( ! F_185 ( V_2 , V_111 -> V_166 * 4 ) )
goto V_345;
if ( F_210 ( V_2 , V_62 , V_348 ) )
goto V_349;
V_111 = ( const struct V_110 * ) V_2 -> V_109 ;
V_108 = F_3 ( V_2 ) ;
memmove ( & F_100 ( V_2 ) -> V_200 . V_201 , F_211 ( V_2 ) ,
sizeof( struct V_350 ) ) ;
F_212 () ;
F_100 ( V_2 ) -> V_40 = F_58 ( V_111 -> V_40 ) ;
F_100 ( V_2 ) -> V_342 = ( F_100 ( V_2 ) -> V_40 + V_111 -> V_183 + V_111 -> V_184 +
V_2 -> V_162 - V_111 -> V_166 * 4 ) ;
F_100 ( V_2 ) -> V_182 = F_58 ( V_111 -> V_182 ) ;
F_100 ( V_2 ) -> V_351 = F_213 ( V_111 ) ;
F_100 ( V_2 ) -> V_352 = 0 ;
F_100 ( V_2 ) -> V_353 = F_214 ( V_108 ) ;
F_100 ( V_2 ) -> V_354 = 0 ;
V_355:
V_9 = F_215 ( & V_120 , V_2 , F_216 ( V_111 ) , V_111 -> V_7 ,
V_111 -> V_6 , & V_343 ) ;
if ( ! V_9 )
goto V_356;
V_357:
if ( V_9 -> V_88 == V_122 )
goto V_358;
if ( V_9 -> V_88 == V_123 ) {
struct V_99 * V_100 = F_43 ( V_9 ) ;
struct V_8 * V_315 ;
V_9 = V_100 -> V_104 ;
if ( F_61 ( F_149 ( V_9 , V_2 ) ) ) {
F_217 ( V_9 , V_2 ) ;
F_48 ( V_100 ) ;
goto V_345;
}
if ( F_61 ( V_9 -> V_88 != V_136 ) ) {
F_218 ( V_9 , V_100 ) ;
goto V_355;
}
F_10 ( V_9 ) ;
V_343 = true ;
V_315 = F_219 ( V_9 , V_2 , V_100 , false ) ;
if ( ! V_315 ) {
F_48 ( V_100 ) ;
goto V_359;
}
if ( V_315 == V_9 ) {
F_48 ( V_100 ) ;
} else if ( F_180 ( V_9 , V_315 , V_2 ) ) {
F_81 ( V_315 , V_2 ) ;
goto V_359;
} else {
F_74 ( V_9 ) ;
return 0 ;
}
}
if ( F_61 ( V_108 -> V_132 < F_12 ( V_9 ) -> V_133 ) ) {
F_45 ( V_101 , V_134 ) ;
goto V_359;
}
if ( ! F_220 ( V_9 , V_360 , V_2 ) )
goto V_359;
if ( F_149 ( V_9 , V_2 ) )
goto V_359;
F_221 ( V_2 ) ;
if ( F_207 ( V_9 , V_2 ) )
goto V_359;
V_111 = ( const struct V_110 * ) V_2 -> V_109 ;
V_108 = F_3 ( V_2 ) ;
V_2 -> V_119 = NULL ;
if ( V_9 -> V_88 == V_136 ) {
V_344 = F_175 ( V_9 , V_2 ) ;
goto V_361;
}
F_222 ( V_9 ) ;
F_223 ( V_9 ) ;
F_224 ( F_7 ( V_9 ) , V_2 ) ;
V_344 = 0 ;
if ( ! F_60 ( V_9 ) ) {
if ( ! F_190 ( V_9 , V_2 ) )
V_344 = F_175 ( V_9 , V_2 ) ;
} else if ( F_204 ( V_9 , V_2 ) ) {
goto V_359;
}
F_73 ( V_9 ) ;
V_361:
if ( V_343 )
F_74 ( V_9 ) ;
return V_344 ;
V_356:
if ( ! F_220 ( NULL , V_360 , V_2 ) )
goto V_345;
if ( F_179 ( V_2 ) ) {
V_349:
F_101 ( V_101 , V_318 ) ;
V_347:
F_101 ( V_101 , V_319 ) ;
} else {
F_81 ( NULL , V_2 ) ;
}
V_345:
F_182 ( V_2 ) ;
return 0 ;
V_359:
F_217 ( V_9 , V_2 ) ;
if ( V_343 )
F_74 ( V_9 ) ;
goto V_345;
V_358:
if ( ! F_220 ( NULL , V_360 , V_2 ) ) {
F_56 ( F_57 ( V_9 ) ) ;
goto V_345;
}
if ( F_179 ( V_2 ) ) {
F_56 ( F_57 ( V_9 ) ) ;
goto V_349;
}
switch ( F_225 ( F_57 ( V_9 ) , V_2 , V_111 ) ) {
case V_362 : {
struct V_8 * V_363 = F_226 ( F_51 ( V_2 -> V_119 ) ,
& V_120 , V_2 ,
F_216 ( V_111 ) ,
V_108 -> V_5 , V_111 -> V_7 ,
V_108 -> V_4 , V_111 -> V_6 ,
F_54 ( V_2 ) ) ;
if ( V_363 ) {
F_227 ( F_57 ( V_9 ) ) ;
V_9 = V_363 ;
V_343 = false ;
goto V_357;
}
}
case V_364 :
F_106 ( V_9 , V_2 ) ;
break;
case V_365 :
F_81 ( V_9 , V_2 ) ;
F_227 ( F_57 ( V_9 ) ) ;
goto V_345;
case V_366 : ;
}
goto V_345;
}
void F_161 ( struct V_8 * V_9 , const struct V_1 * V_2 )
{
struct V_86 * V_71 = F_85 ( V_2 ) ;
if ( V_71 && F_228 ( V_71 ) ) {
V_9 -> V_311 = V_71 ;
F_12 ( V_9 ) -> V_312 = V_2 -> V_313 ;
}
}
static int F_229 ( struct V_8 * V_9 )
{
struct V_113 * V_114 = F_25 ( V_9 ) ;
F_230 ( V_9 ) ;
V_114 -> V_367 = & V_368 ;
#ifdef F_82
F_7 ( V_9 ) -> V_369 = & V_370 ;
#endif
return 0 ;
}
void F_231 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
F_232 ( V_9 ) ;
F_233 ( V_9 ) ;
F_234 ( V_9 ) ;
F_235 ( & V_15 -> V_371 ) ;
#ifdef F_82
if ( V_15 -> V_241 ) {
F_134 ( V_9 ) ;
F_133 ( V_15 -> V_241 , V_256 ) ;
V_15 -> V_241 = NULL ;
}
#endif
F_236 ( & V_15 -> V_325 . V_327 ) ;
if ( F_25 ( V_9 ) -> V_372 )
F_237 ( V_9 ) ;
F_67 ( V_15 -> V_135 ) ;
F_238 ( V_15 ) ;
F_239 ( V_15 ) ;
F_240 ( V_9 ) ;
}
static void * F_241 ( struct V_373 * V_40 , void * V_374 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
struct V_101 * V_101 = F_242 ( V_40 ) ;
struct V_378 * V_379 ;
struct V_8 * V_9 = V_374 ;
if ( ! V_9 ) {
V_380:
V_379 = & V_120 . V_381 [ V_376 -> V_382 ] ;
F_243 ( & V_379 -> V_383 ) ;
V_9 = F_244 ( & V_379 -> V_164 ) ;
V_376 -> V_213 = 0 ;
goto V_384;
}
V_379 = & V_120 . V_381 [ V_376 -> V_382 ] ;
++ V_376 -> V_385 ;
++ V_376 -> V_213 ;
V_9 = F_245 ( V_9 ) ;
V_384:
F_246 (sk) {
if ( ! F_247 ( F_8 ( V_9 ) , V_101 ) )
continue;
if ( V_9 -> V_386 == V_376 -> V_236 )
return V_9 ;
}
F_248 ( & V_379 -> V_383 ) ;
V_376 -> V_213 = 0 ;
if ( ++ V_376 -> V_382 < V_387 )
goto V_380;
return NULL ;
}
static void * F_249 ( struct V_373 * V_40 , T_9 * V_388 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
void * V_389 ;
V_376 -> V_382 = 0 ;
V_376 -> V_213 = 0 ;
V_389 = F_241 ( V_40 , NULL ) ;
while ( V_389 && * V_388 ) {
V_389 = F_241 ( V_40 , V_389 ) ;
-- * V_388 ;
}
return V_389 ;
}
static inline bool F_250 ( const struct V_375 * V_376 )
{
return F_251 ( & V_120 . V_390 [ V_376 -> V_382 ] . V_391 ) ;
}
static void * F_252 ( struct V_373 * V_40 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
struct V_101 * V_101 = F_242 ( V_40 ) ;
void * V_389 = NULL ;
V_376 -> V_213 = 0 ;
for (; V_376 -> V_382 <= V_120 . V_392 ; ++ V_376 -> V_382 ) {
struct V_8 * V_9 ;
struct V_393 * V_253 ;
T_10 * V_383 = F_253 ( & V_120 , V_376 -> V_382 ) ;
if ( F_250 ( V_376 ) )
continue;
F_254 ( V_383 ) ;
F_255 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_9 -> V_386 != V_376 -> V_236 ||
! F_247 ( F_8 ( V_9 ) , V_101 ) ) {
continue;
}
V_389 = V_9 ;
goto V_131;
}
F_256 ( V_383 ) ;
}
V_131:
return V_389 ;
}
static void * F_257 ( struct V_373 * V_40 , void * V_374 )
{
struct V_8 * V_9 = V_374 ;
struct V_393 * V_253 ;
struct V_375 * V_376 = V_40 -> V_377 ;
struct V_101 * V_101 = F_242 ( V_40 ) ;
++ V_376 -> V_385 ;
++ V_376 -> V_213 ;
V_9 = F_258 ( V_9 ) ;
F_259 (sk, node) {
if ( V_9 -> V_386 == V_376 -> V_236 && F_247 ( F_8 ( V_9 ) , V_101 ) )
return V_9 ;
}
F_256 ( F_253 ( & V_120 , V_376 -> V_382 ) ) ;
++ V_376 -> V_382 ;
return F_252 ( V_40 ) ;
}
static void * F_260 ( struct V_373 * V_40 , T_9 V_388 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
void * V_389 ;
V_376 -> V_382 = 0 ;
V_389 = F_252 ( V_40 ) ;
while ( V_389 && V_388 ) {
V_389 = F_257 ( V_40 , V_389 ) ;
-- V_388 ;
}
return V_389 ;
}
static void * F_261 ( struct V_373 * V_40 , T_9 V_388 )
{
void * V_389 ;
struct V_375 * V_376 = V_40 -> V_377 ;
V_376 -> V_394 = V_395 ;
V_389 = F_249 ( V_40 , & V_388 ) ;
if ( ! V_389 ) {
V_376 -> V_394 = V_396 ;
V_389 = F_260 ( V_40 , V_388 ) ;
}
return V_389 ;
}
static void * F_262 ( struct V_373 * V_40 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
int V_213 = V_376 -> V_213 ;
int V_397 = V_376 -> V_385 ;
void * V_389 = NULL ;
switch ( V_376 -> V_394 ) {
case V_395 :
if ( V_376 -> V_382 >= V_387 )
break;
V_376 -> V_394 = V_395 ;
V_389 = F_241 ( V_40 , NULL ) ;
while ( V_213 -- && V_389 )
V_389 = F_241 ( V_40 , V_389 ) ;
if ( V_389 )
break;
V_376 -> V_382 = 0 ;
V_376 -> V_394 = V_396 ;
case V_396 :
if ( V_376 -> V_382 > V_120 . V_392 )
break;
V_389 = F_252 ( V_40 ) ;
while ( V_213 -- && V_389 )
V_389 = F_257 ( V_40 , V_389 ) ;
}
V_376 -> V_385 = V_397 ;
return V_389 ;
}
static void * F_263 ( struct V_373 * V_40 , T_9 * V_388 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
void * V_389 ;
if ( * V_388 && * V_388 == V_376 -> V_398 ) {
V_389 = F_262 ( V_40 ) ;
if ( V_389 )
goto V_131;
}
V_376 -> V_394 = V_395 ;
V_376 -> V_385 = 0 ;
V_376 -> V_382 = 0 ;
V_376 -> V_213 = 0 ;
V_389 = * V_388 ? F_261 ( V_40 , * V_388 - 1 ) : V_399 ;
V_131:
V_376 -> V_398 = * V_388 ;
return V_389 ;
}
static void * F_264 ( struct V_373 * V_40 , void * V_400 , T_9 * V_388 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
void * V_389 = NULL ;
if ( V_400 == V_399 ) {
V_389 = F_261 ( V_40 , 0 ) ;
goto V_131;
}
switch ( V_376 -> V_394 ) {
case V_395 :
V_389 = F_241 ( V_40 , V_400 ) ;
if ( ! V_389 ) {
V_376 -> V_394 = V_396 ;
V_376 -> V_382 = 0 ;
V_376 -> V_213 = 0 ;
V_389 = F_252 ( V_40 ) ;
}
break;
case V_396 :
V_389 = F_257 ( V_40 , V_400 ) ;
break;
}
V_131:
++ * V_388 ;
V_376 -> V_398 = * V_388 ;
return V_389 ;
}
static void F_265 ( struct V_373 * V_40 , void * V_400 )
{
struct V_375 * V_376 = V_40 -> V_377 ;
switch ( V_376 -> V_394 ) {
case V_395 :
if ( V_400 != V_399 )
F_248 ( & V_120 . V_381 [ V_376 -> V_382 ] . V_383 ) ;
break;
case V_396 :
if ( V_400 )
F_256 ( F_253 ( & V_120 , V_376 -> V_382 ) ) ;
break;
}
}
int F_266 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
struct V_403 * V_404 = F_267 ( V_401 ) ;
struct V_375 * V_405 ;
int V_39 ;
V_39 = F_268 ( V_401 , V_402 , & V_404 -> V_406 ,
sizeof( struct V_375 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_405 = ( (struct V_373 * ) V_402 -> V_407 ) -> V_377 ;
V_405 -> V_236 = V_404 -> V_236 ;
V_405 -> V_398 = 0 ;
return 0 ;
}
int F_269 ( struct V_101 * V_101 , struct V_403 * V_404 )
{
int V_389 = 0 ;
struct V_408 * V_409 ;
V_404 -> V_406 . V_410 = F_263 ;
V_404 -> V_406 . V_411 = F_264 ;
V_404 -> V_406 . V_412 = F_265 ;
V_409 = F_270 ( V_404 -> V_413 , V_414 , V_101 -> V_415 ,
V_404 -> V_416 , V_404 ) ;
if ( ! V_409 )
V_389 = - V_251 ;
return V_389 ;
}
void F_271 ( struct V_101 * V_101 , struct V_403 * V_404 )
{
F_272 ( V_404 -> V_413 , V_101 -> V_415 ) ;
}
static void F_273 ( const struct V_99 * V_100 ,
struct V_373 * V_417 , int V_418 )
{
const struct V_231 * V_232 = F_109 ( V_100 ) ;
long V_419 = V_100 -> V_420 . V_421 - V_83 ;
F_274 ( V_417 , L_4
L_5 ,
V_418 ,
V_232 -> V_233 ,
V_232 -> V_422 ,
V_232 -> V_234 ,
F_53 ( V_232 -> V_423 ) ,
V_155 ,
0 , 0 ,
1 ,
F_275 ( V_419 ) ,
V_100 -> V_424 ,
F_276 ( F_277 ( V_417 ) ,
F_278 ( V_100 -> V_104 ) ) ,
0 ,
0 ,
0 ,
V_100 ) ;
}
static void F_279 ( struct V_8 * V_9 , struct V_373 * V_417 , int V_418 )
{
int V_425 ;
unsigned long V_426 ;
const struct V_14 * V_15 = F_7 ( V_9 ) ;
const struct V_113 * V_114 = F_25 ( V_9 ) ;
const struct V_30 * V_31 = F_12 ( V_9 ) ;
const struct V_427 * V_428 = & V_114 -> V_429 . V_428 ;
T_3 V_6 = V_31 -> V_68 ;
T_3 V_430 = V_31 -> V_431 ;
T_11 V_432 = F_53 ( V_31 -> V_72 ) ;
T_11 V_433 = F_53 ( V_31 -> V_54 ) ;
int V_434 ;
int V_394 ;
if ( V_114 -> V_435 == V_153 ||
V_114 -> V_435 == V_436 ||
V_114 -> V_435 == V_437 ) {
V_425 = 1 ;
V_426 = V_114 -> V_438 ;
} else if ( V_114 -> V_435 == V_439 ) {
V_425 = 4 ;
V_426 = V_114 -> V_438 ;
} else if ( F_280 ( & V_9 -> V_440 ) ) {
V_425 = 2 ;
V_426 = V_9 -> V_440 . V_421 ;
} else {
V_425 = 0 ;
V_426 = V_83 ;
}
V_394 = F_281 ( V_9 ) ;
if ( V_394 == V_136 )
V_434 = V_9 -> V_441 ;
else
V_434 = F_282 ( int , V_15 -> V_221 - V_15 -> V_442 , 0 ) ;
F_274 ( V_417 , L_6
L_7 ,
V_418 , V_430 , V_433 , V_6 , V_432 , V_394 ,
V_15 -> V_19 - V_15 -> V_117 ,
V_434 ,
V_425 ,
F_275 ( V_426 - V_83 ) ,
V_114 -> V_146 ,
F_276 ( F_277 ( V_417 ) , F_278 ( V_9 ) ) ,
V_114 -> V_443 ,
F_283 ( V_9 ) ,
F_196 ( & V_9 -> V_444 ) , V_9 ,
F_284 ( V_114 -> V_148 ) ,
F_284 ( V_114 -> V_445 . V_446 ) ,
( V_114 -> V_445 . V_447 << 1 ) | V_114 -> V_445 . V_448 ,
V_15 -> V_449 ,
V_394 == V_136 ?
V_428 -> V_450 :
( F_285 ( V_15 ) ? - 1 : V_15 -> V_451 ) ) ;
}
static void F_286 ( const struct V_196 * V_214 ,
struct V_373 * V_417 , int V_418 )
{
long V_419 = V_214 -> V_452 . V_421 - V_83 ;
T_3 V_6 , V_430 ;
T_11 V_432 , V_433 ;
V_6 = V_214 -> V_453 ;
V_430 = V_214 -> V_454 ;
V_432 = F_53 ( V_214 -> V_455 ) ;
V_433 = F_53 ( V_214 -> V_456 ) ;
F_274 ( V_417 , L_4
L_8 ,
V_418 , V_430 , V_433 , V_6 , V_432 , V_214 -> V_457 , 0 , 0 ,
3 , F_275 ( V_419 ) , 0 , 0 , 0 , 0 ,
F_196 ( & V_214 -> V_458 ) , V_214 ) ;
}
static int F_287 ( struct V_373 * V_40 , void * V_400 )
{
struct V_375 * V_376 ;
struct V_8 * V_9 = V_400 ;
F_288 ( V_40 , V_459 - 1 ) ;
if ( V_400 == V_399 ) {
F_289 ( V_40 , L_9
L_10
L_11 ) ;
goto V_131;
}
V_376 = V_40 -> V_377 ;
if ( V_9 -> V_88 == V_122 )
F_286 ( V_400 , V_40 , V_376 -> V_385 ) ;
else if ( V_9 -> V_88 == V_123 )
F_273 ( V_400 , V_40 , V_376 -> V_385 ) ;
else
F_279 ( V_400 , V_40 , V_376 -> V_385 ) ;
V_131:
F_290 ( V_40 , '\n' ) ;
return 0 ;
}
static int T_12 F_291 ( struct V_101 * V_101 )
{
return F_269 ( V_101 , & V_460 ) ;
}
static void T_13 F_292 ( struct V_101 * V_101 )
{
F_271 ( V_101 , & V_460 ) ;
}
int T_14 F_293 ( void )
{
return F_294 ( & V_461 ) ;
}
void F_295 ( void )
{
F_296 ( & V_461 ) ;
}
static void T_13 F_297 ( struct V_101 * V_101 )
{
int V_462 ;
F_298 (cpu)
F_299 ( * F_300 ( V_101 -> V_17 . F_7 , V_462 ) ) ;
F_301 ( V_101 -> V_17 . F_7 ) ;
}
static int T_12 F_302 ( struct V_101 * V_101 )
{
int V_463 , V_462 , V_464 ;
V_101 -> V_17 . F_7 = F_303 ( struct V_8 * ) ;
if ( ! V_101 -> V_17 . F_7 )
return - V_251 ;
F_298 (cpu) {
struct V_8 * V_9 ;
V_463 = F_304 ( & V_9 , V_465 , V_466 ,
V_62 , V_101 ) ;
if ( V_463 )
goto V_467;
F_305 ( V_9 , V_468 ) ;
* F_300 ( V_101 -> V_17 . F_7 , V_462 ) = V_9 ;
}
V_101 -> V_17 . V_469 = 2 ;
V_101 -> V_17 . V_470 = 1 ;
V_101 -> V_17 . V_471 = V_472 ;
V_101 -> V_17 . V_473 = V_474 ;
V_101 -> V_17 . V_475 = V_476 ;
V_101 -> V_17 . V_477 = V_478 ;
V_101 -> V_17 . V_479 = V_480 ;
V_101 -> V_17 . V_481 = V_482 ;
V_101 -> V_17 . V_483 = V_484 ;
V_101 -> V_17 . V_485 = V_486 ;
V_101 -> V_17 . V_487 = 1 ;
V_101 -> V_17 . V_488 = V_489 ;
V_101 -> V_17 . V_490 = V_491 ;
V_101 -> V_17 . V_492 = V_493 ;
V_101 -> V_17 . V_494 = 0 ;
V_101 -> V_17 . V_495 = V_496 ;
V_101 -> V_17 . V_497 = V_498 ;
V_101 -> V_17 . V_18 = 0 ;
V_464 = V_120 . V_392 + 1 ;
V_101 -> V_17 . V_44 . V_70 = 0 ;
V_101 -> V_17 . V_44 . V_499 = ( V_464 + 1 ) / 2 ;
V_101 -> V_17 . V_44 . V_500 = & V_120 ;
V_101 -> V_17 . V_501 = F_306 ( 128 , V_464 / 256 ) ;
return 0 ;
V_467:
F_297 ( V_101 ) ;
return V_463 ;
}
static void T_13 F_307 ( struct V_502 * V_503 )
{
F_308 ( & V_120 , V_47 ) ;
}
void T_14 F_309 ( void )
{
if ( F_294 ( & V_504 ) )
F_310 ( L_12 ) ;
}
