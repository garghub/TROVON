static T_1 F_1 ( const struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
F_4 ( V_2 ) -> V_5 ,
F_4 ( V_2 ) -> V_6 ) ;
}
static T_1 F_5 ( const struct V_7 * V_7 , const struct V_1 * V_2 )
{
return F_6 ( V_7 , F_3 ( V_2 ) -> V_3 , F_3 ( V_2 ) -> V_4 ) ;
}
int F_7 ( struct V_8 * V_9 , struct V_8 * V_10 , void * V_11 )
{
const struct V_12 * V_13 = F_8 ( V_10 ) ;
struct V_14 * V_15 = F_9 ( V_9 ) ;
if ( V_13 -> V_16 &&
( ! V_11 || ( F_10 ( V_9 ) -> V_17 . V_18 &&
F_11 () - V_13 -> V_16 > 1 ) ) ) {
V_15 -> V_19 = V_13 -> V_20 + 65535 + 2 ;
if ( V_15 -> V_19 == 0 )
V_15 -> V_19 = 1 ;
V_15 -> V_21 . V_22 = V_13 -> V_23 ;
V_15 -> V_21 . V_24 = V_13 -> V_16 ;
F_12 ( V_10 ) ;
return 1 ;
}
return 0 ;
}
int F_13 ( struct V_8 * V_9 , struct V_25 * V_26 , int V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_26 ;
struct V_30 * V_31 = F_14 ( V_9 ) ;
struct V_14 * V_15 = F_9 ( V_9 ) ;
T_2 V_32 , V_33 ;
T_3 V_3 , V_34 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 = & F_10 ( V_9 ) -> V_17 . V_43 ;
if ( V_27 < sizeof( struct V_28 ) )
return - V_44 ;
if ( V_29 -> V_45 != V_46 )
return - V_47 ;
V_34 = V_3 = V_29 -> V_48 . V_49 ;
V_41 = F_15 ( V_31 -> V_41 ,
F_16 ( V_9 ) ) ;
if ( V_41 && V_41 -> V_50 . V_51 ) {
if ( ! V_3 )
return - V_44 ;
V_34 = V_41 -> V_50 . V_52 ;
}
V_32 = V_31 -> V_53 ;
V_33 = V_29 -> V_54 ;
V_36 = & V_31 -> V_55 . V_56 . V_57 . V_58 ;
V_38 = F_17 ( V_36 , V_34 , V_31 -> V_59 ,
F_18 ( V_9 ) , V_9 -> V_60 ,
V_61 ,
V_32 , V_33 , V_9 ) ;
if ( F_19 ( V_38 ) ) {
V_39 = F_20 ( V_38 ) ;
if ( V_39 == - V_62 )
F_21 ( F_10 ( V_9 ) , V_63 ) ;
return V_39 ;
}
if ( V_38 -> V_64 & ( V_65 | V_66 ) ) {
F_22 ( V_38 ) ;
return - V_62 ;
}
if ( ! V_41 || ! V_41 -> V_50 . V_51 )
V_3 = V_36 -> V_3 ;
if ( ! V_31 -> V_59 )
V_31 -> V_59 = V_36 -> V_4 ;
F_23 ( V_9 , V_31 -> V_59 ) ;
if ( V_15 -> V_21 . V_24 && V_31 -> V_67 != V_3 ) {
V_15 -> V_21 . V_22 = 0 ;
V_15 -> V_21 . V_24 = 0 ;
if ( F_24 ( ! V_15 -> V_68 ) )
V_15 -> V_19 = 0 ;
}
V_31 -> V_69 = V_29 -> V_54 ;
F_25 ( V_9 , V_3 ) ;
F_26 ( V_9 ) -> V_70 = 0 ;
if ( V_41 )
F_26 ( V_9 ) -> V_70 = V_41 -> V_50 . V_71 ;
V_15 -> V_21 . V_72 = V_73 ;
F_27 ( V_9 , V_74 ) ;
V_39 = F_28 ( V_43 , V_9 ) ;
if ( V_39 )
goto V_75;
F_29 ( V_9 ) ;
V_38 = F_30 ( V_36 , V_38 , V_32 , V_33 ,
V_31 -> V_53 , V_31 -> V_69 , V_9 ) ;
if ( F_19 ( V_38 ) ) {
V_39 = F_20 ( V_38 ) ;
V_38 = NULL ;
goto V_75;
}
V_9 -> V_76 = V_77 ;
F_31 ( V_9 , & V_38 -> V_78 ) ;
V_38 = NULL ;
if ( F_24 ( ! V_15 -> V_68 ) ) {
if ( ! V_15 -> V_19 )
V_15 -> V_19 = F_2 ( V_31 -> V_59 ,
V_31 -> V_67 ,
V_31 -> V_53 ,
V_29 -> V_54 ) ;
V_15 -> V_79 = F_6 ( F_10 ( V_9 ) ,
V_31 -> V_59 ,
V_31 -> V_67 ) ;
}
V_31 -> V_80 = V_15 -> V_19 ^ V_81 ;
if ( F_32 ( V_9 , & V_39 ) )
return V_39 ;
if ( V_39 )
goto V_75;
V_39 = F_33 ( V_9 ) ;
if ( V_39 )
goto V_75;
return 0 ;
V_75:
F_27 ( V_9 , V_82 ) ;
F_22 ( V_38 ) ;
V_9 -> V_83 = 0 ;
V_31 -> V_69 = 0 ;
return V_39 ;
}
void F_34 ( struct V_8 * V_9 )
{
struct V_30 * V_31 = F_14 ( V_9 ) ;
struct V_84 * V_78 ;
T_1 V_85 ;
if ( ( 1 << V_9 -> V_86 ) & ( V_87 | V_88 ) )
return;
V_85 = F_9 ( V_9 ) -> V_89 ;
V_78 = F_35 ( V_9 , V_85 ) ;
if ( ! V_78 )
return;
if ( V_85 < F_36 ( V_78 ) && F_37 ( V_9 , V_78 ) )
V_9 -> V_90 = V_91 ;
V_85 = F_36 ( V_78 ) ;
if ( V_31 -> V_92 != V_93 &&
F_38 ( V_9 ) &&
F_26 ( V_9 ) -> V_94 > V_85 ) {
F_39 ( V_9 , V_85 ) ;
F_40 ( V_9 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_84 * V_78 = F_42 ( V_9 , 0 ) ;
if ( V_78 )
V_78 -> V_95 -> V_96 ( V_78 , V_9 , V_2 ) ;
}
void F_43 ( struct V_8 * V_9 , T_1 V_97 , bool abort )
{
struct V_98 * V_99 = F_44 ( V_9 ) ;
struct V_7 * V_7 = F_10 ( V_9 ) ;
if ( V_97 != F_45 ( V_99 ) -> V_100 ) {
F_46 ( V_7 , V_101 ) ;
} else if ( abort ) {
F_47 ( V_99 -> V_102 , V_99 ) ;
F_48 ( V_99 -> V_102 ) ;
}
F_49 ( V_99 ) ;
}
void F_50 ( struct V_1 * V_103 , T_1 V_104 )
{
const struct V_105 * V_106 = ( const struct V_105 * ) V_103 -> V_107 ;
struct V_108 * V_109 = (struct V_108 * ) ( V_103 -> V_107 + ( V_106 -> V_110 << 2 ) ) ;
struct V_111 * V_112 ;
struct V_14 * V_15 ;
struct V_30 * V_31 ;
const int type = F_51 ( V_103 ) -> type ;
const int V_113 = F_51 ( V_103 ) -> V_113 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_98 * V_114 ;
T_1 V_97 , V_115 ;
T_4 V_116 ;
T_1 V_117 ;
int V_39 ;
struct V_7 * V_7 = F_52 ( V_103 -> V_118 ) ;
V_9 = F_53 ( V_7 , & V_119 , V_106 -> V_3 ,
V_109 -> V_5 , V_106 -> V_4 , F_54 ( V_109 -> V_6 ) ,
F_55 ( V_103 ) ) ;
if ( ! V_9 ) {
F_56 ( V_7 , V_120 ) ;
return;
}
if ( V_9 -> V_86 == V_121 ) {
F_57 ( F_58 ( V_9 ) ) ;
return;
}
V_97 = F_59 ( V_109 -> V_97 ) ;
if ( V_9 -> V_86 == V_122 )
return F_43 ( V_9 , V_97 ,
type == V_123 ||
type == V_124 ||
( type == V_125 &&
( V_113 == V_126 ||
V_113 == V_127 ) ) ) ;
F_60 ( V_9 ) ;
if ( F_61 ( V_9 ) ) {
if ( ! ( type == V_125 && V_113 == V_128 ) )
F_46 ( V_7 , V_129 ) ;
}
if ( V_9 -> V_86 == V_82 )
goto V_130;
if ( F_62 ( V_106 -> V_131 < F_14 ( V_9 ) -> V_132 ) ) {
F_46 ( V_7 , V_133 ) ;
goto V_130;
}
V_112 = F_26 ( V_9 ) ;
V_15 = F_9 ( V_9 ) ;
V_114 = V_15 -> V_134 ;
V_115 = V_114 ? F_45 ( V_114 ) -> V_100 : V_15 -> V_115 ;
if ( V_9 -> V_86 != V_135 &&
! F_63 ( V_97 , V_115 , V_15 -> V_136 ) ) {
F_46 ( V_7 , V_101 ) ;
goto V_130;
}
switch ( type ) {
case V_137 :
if ( ! F_61 ( V_9 ) )
F_41 ( V_103 , V_9 ) ;
goto V_130;
case V_138 :
goto V_130;
case V_123 :
V_39 = V_139 ;
break;
case V_125 :
if ( V_113 > V_140 )
goto V_130;
if ( V_113 == V_128 ) {
if ( V_9 -> V_86 == V_135 )
goto V_130;
V_15 -> V_89 = V_104 ;
if ( ! F_61 ( V_9 ) ) {
F_34 ( V_9 ) ;
} else {
if ( ! F_64 ( V_141 , & V_9 -> V_142 ) )
F_12 ( V_9 ) ;
}
goto V_130;
}
V_39 = V_143 [ V_113 ] . V_144 ;
if ( V_113 != V_126 && V_113 != V_127 )
break;
if ( V_97 != V_15 -> V_115 || ! V_112 -> V_145 ||
! V_112 -> V_146 || V_114 )
break;
if ( F_61 ( V_9 ) )
break;
V_112 -> V_146 -- ;
V_112 -> V_147 = V_15 -> V_148 ? F_65 ( V_15 ) :
V_149 ;
V_112 -> V_147 = F_66 ( V_112 , V_150 ) ;
V_2 = F_67 ( V_9 ) ;
F_68 ( ! V_2 ) ;
F_69 ( V_15 ) ;
V_117 = ( T_1 ) ( V_15 -> V_151 - V_2 -> V_152 ) ;
V_116 = V_112 -> V_147 -
F_70 ( V_117 ) ;
if ( V_116 > 0 ) {
F_71 ( V_9 , V_153 ,
V_116 , V_150 ) ;
} else {
F_72 ( V_9 ) ;
}
break;
case V_124 :
V_39 = V_154 ;
break;
default:
goto V_130;
}
switch ( V_9 -> V_86 ) {
case V_74 :
case V_155 :
if ( V_114 && ! V_114 -> V_9 )
break;
if ( ! F_61 ( V_9 ) ) {
V_9 -> V_156 = V_39 ;
V_9 -> V_157 ( V_9 ) ;
F_73 ( V_9 ) ;
} else {
V_9 -> V_90 = V_39 ;
}
goto V_130;
}
V_31 = F_14 ( V_9 ) ;
if ( ! F_61 ( V_9 ) && V_31 -> V_158 ) {
V_9 -> V_156 = V_39 ;
V_9 -> V_157 ( V_9 ) ;
} else {
V_9 -> V_90 = V_39 ;
}
V_130:
F_74 ( V_9 ) ;
F_75 ( V_9 ) ;
}
void F_76 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_108 * V_109 = F_4 ( V_2 ) ;
if ( V_2 -> V_159 == V_160 ) {
V_109 -> V_161 = ~ F_77 ( V_2 -> V_162 , V_4 , V_3 , 0 ) ;
V_2 -> V_163 = F_78 ( V_2 ) - V_2 -> V_164 ;
V_2 -> V_165 = F_79 ( struct V_108 , V_161 ) ;
} else {
V_109 -> V_161 = F_77 ( V_2 -> V_162 , V_4 , V_3 ,
F_80 ( V_109 ,
V_109 -> V_166 << 2 ,
V_2 -> V_167 ) ) ;
}
}
void F_81 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_30 * V_31 = F_14 ( V_9 ) ;
F_76 ( V_2 , V_31 -> V_59 , V_31 -> V_67 ) ;
}
static void F_82 ( const struct V_8 * V_9 , struct V_1 * V_2 )
{
const struct V_108 * V_109 = F_4 ( V_2 ) ;
struct {
struct V_108 V_109 ;
#ifdef F_83
T_3 V_50 [ ( V_168 >> 2 ) ] ;
#endif
} V_169 ;
struct V_170 V_171 ;
#ifdef F_83
struct V_172 * V_173 = NULL ;
const T_5 * V_174 = NULL ;
unsigned char V_175 [ 16 ] ;
int V_176 ;
struct V_8 * V_177 = NULL ;
#endif
struct V_7 * V_7 ;
if ( V_109 -> V_178 )
return;
if ( ! V_9 && F_84 ( V_2 ) -> V_179 != V_180 )
return;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_109 . V_5 = V_109 -> V_6 ;
V_169 . V_109 . V_6 = V_109 -> V_5 ;
V_169 . V_109 . V_166 = sizeof( struct V_108 ) / 4 ;
V_169 . V_109 . V_178 = 1 ;
if ( V_109 -> V_181 ) {
V_169 . V_109 . V_97 = V_109 -> V_182 ;
} else {
V_169 . V_109 . V_181 = 1 ;
V_169 . V_109 . V_182 = F_85 ( F_59 ( V_109 -> V_97 ) + V_109 -> V_183 + V_109 -> V_184 +
V_2 -> V_162 - ( V_109 -> V_166 << 2 ) ) ;
}
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_185 [ 0 ] . V_186 = ( unsigned char * ) & V_169 ;
V_171 . V_185 [ 0 ] . V_187 = sizeof( V_169 . V_109 ) ;
V_7 = V_9 ? F_10 ( V_9 ) : F_52 ( F_86 ( V_2 ) -> V_118 ) ;
#ifdef F_83
F_87 () ;
V_174 = F_88 ( V_109 ) ;
if ( V_9 && F_89 ( V_9 ) ) {
V_173 = F_90 ( V_9 , (union V_188 * )
& F_3 ( V_2 ) -> V_4 , V_46 ) ;
} else if ( V_174 ) {
V_177 = F_91 ( V_7 , & V_119 , NULL , 0 ,
F_3 ( V_2 ) -> V_4 ,
V_109 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_54 ( V_109 -> V_6 ) , F_55 ( V_2 ) ) ;
if ( ! V_177 )
goto V_130;
V_173 = F_90 ( V_177 , (union V_188 * )
& F_3 ( V_2 ) -> V_4 , V_46 ) ;
if ( ! V_173 )
goto V_130;
V_176 = F_92 ( V_175 , V_173 , NULL , V_2 ) ;
if ( V_176 || memcmp ( V_174 , V_175 , 16 ) != 0 )
goto V_130;
}
if ( V_173 ) {
V_169 . V_50 [ 0 ] = F_85 ( ( V_189 << 24 ) |
( V_189 << 16 ) |
( V_190 << 8 ) |
V_191 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_168 ;
V_169 . V_109 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
F_93 ( ( T_5 * ) & V_169 . V_50 [ 1 ] ,
V_173 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_169 . V_109 ) ;
}
#endif
V_171 . V_167 = F_94 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_171 . V_185 [ 0 ] . V_187 , V_61 , 0 ) ;
V_171 . V_192 = F_79 ( struct V_108 , V_161 ) / 2 ;
V_171 . V_193 = ( V_9 && F_95 ( V_9 ) ) ? V_194 : 0 ;
if ( V_9 )
V_171 . V_195 = V_9 -> V_60 ;
F_96 ( F_79 ( struct V_8 , V_60 ) !=
F_79 ( struct V_196 , V_197 ) ) ;
V_171 . V_198 = F_3 ( V_2 ) -> V_198 ;
V_171 . V_199 = F_97 ( V_7 , V_9 && F_89 ( V_9 ) ? V_9 : NULL ) ;
F_98 () ;
F_99 ( * F_100 ( V_7 -> V_17 . F_9 ) ,
V_2 , & F_101 ( V_2 ) -> V_200 . V_201 . V_50 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_102 ( V_7 , V_202 ) ;
F_102 ( V_7 , V_203 ) ;
F_103 () ;
#ifdef F_83
V_130:
F_104 () ;
#endif
}
static void F_105 ( const struct V_8 * V_9 ,
struct V_1 * V_2 , T_1 V_97 , T_1 V_181 ,
T_1 V_204 , T_1 V_205 , T_1 V_206 , int V_207 ,
struct V_172 * V_173 ,
int V_208 , T_6 V_198 )
{
const struct V_108 * V_109 = F_4 ( V_2 ) ;
struct {
struct V_108 V_109 ;
T_3 V_50 [ ( V_209 >> 2 )
#ifdef F_83
+ ( V_168 >> 2 )
#endif
] ;
} V_169 ;
struct V_7 * V_7 = F_10 ( V_9 ) ;
struct V_170 V_171 ;
memset ( & V_169 . V_109 , 0 , sizeof( struct V_108 ) ) ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_185 [ 0 ] . V_186 = ( unsigned char * ) & V_169 ;
V_171 . V_185 [ 0 ] . V_187 = sizeof( V_169 . V_109 ) ;
if ( V_206 ) {
V_169 . V_50 [ 0 ] = F_85 ( ( V_189 << 24 ) | ( V_189 << 16 ) |
( V_210 << 8 ) |
V_211 ) ;
V_169 . V_50 [ 1 ] = F_85 ( V_205 ) ;
V_169 . V_50 [ 2 ] = F_85 ( V_206 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_209 ;
}
V_169 . V_109 . V_5 = V_109 -> V_6 ;
V_169 . V_109 . V_6 = V_109 -> V_5 ;
V_169 . V_109 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
V_169 . V_109 . V_97 = F_85 ( V_97 ) ;
V_169 . V_109 . V_182 = F_85 ( V_181 ) ;
V_169 . V_109 . V_181 = 1 ;
V_169 . V_109 . V_212 = F_106 ( V_204 ) ;
#ifdef F_83
if ( V_173 ) {
int V_213 = ( V_206 ) ? 3 : 0 ;
V_169 . V_50 [ V_213 ++ ] = F_85 ( ( V_189 << 24 ) |
( V_189 << 16 ) |
( V_190 << 8 ) |
V_191 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_168 ;
V_169 . V_109 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
F_93 ( ( T_5 * ) & V_169 . V_50 [ V_213 ] ,
V_173 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_169 . V_109 ) ;
}
#endif
V_171 . V_193 = V_208 ;
V_171 . V_167 = F_94 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_171 . V_185 [ 0 ] . V_187 , V_61 , 0 ) ;
V_171 . V_192 = F_79 ( struct V_108 , V_161 ) / 2 ;
if ( V_207 )
V_171 . V_195 = V_207 ;
V_171 . V_198 = V_198 ;
V_171 . V_199 = F_97 ( V_7 , F_89 ( V_9 ) ? V_9 : NULL ) ;
F_98 () ;
F_99 ( * F_100 ( V_7 -> V_17 . F_9 ) ,
V_2 , & F_101 ( V_2 ) -> V_200 . V_201 . V_50 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_102 ( V_7 , V_202 ) ;
F_103 () ;
}
static void F_107 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_196 * V_214 = F_58 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
F_105 ( V_9 , V_2 ,
V_13 -> V_20 , V_13 -> V_215 ,
V_13 -> V_216 >> V_214 -> V_217 ,
F_108 () + V_13 -> V_218 ,
V_13 -> V_23 ,
V_214 -> V_197 ,
F_109 ( V_13 ) ,
V_214 -> V_219 ? V_194 : 0 ,
V_214 -> V_220
) ;
F_57 ( V_214 ) ;
}
static void F_110 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_98 * V_99 )
{
T_1 V_97 = ( V_9 -> V_86 == V_135 ) ? F_45 ( V_99 ) -> V_100 + 1 :
F_9 ( V_9 ) -> V_136 ;
F_105 ( V_9 , V_2 , V_97 ,
F_45 ( V_99 ) -> V_221 ,
V_99 -> V_222 >> F_111 ( V_99 ) -> V_223 ,
F_108 () + F_45 ( V_99 ) -> V_224 ,
V_99 -> V_22 ,
0 ,
F_90 ( V_9 , (union V_188 * ) & F_3 ( V_2 ) -> V_3 ,
V_46 ) ,
F_111 ( V_99 ) -> V_225 ? V_194 : 0 ,
F_3 ( V_2 ) -> V_198 ) ;
}
static int F_112 ( const struct V_8 * V_9 , struct V_84 * V_78 ,
struct V_226 * V_56 ,
struct V_98 * V_99 ,
struct V_227 * V_228 ,
enum V_229 V_230 )
{
const struct V_231 * V_232 = F_111 ( V_99 ) ;
struct V_35 V_36 ;
int V_39 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_78 && ( V_78 = F_113 ( V_9 , & V_36 , V_99 ) ) == NULL )
return - 1 ;
V_2 = F_114 ( V_9 , V_78 , V_99 , V_228 , V_230 ) ;
if ( V_2 ) {
F_76 ( V_2 , V_232 -> V_233 , V_232 -> V_234 ) ;
V_39 = F_115 ( V_2 , V_9 , V_232 -> V_233 ,
V_232 -> V_234 ,
V_232 -> V_50 ) ;
V_39 = F_116 ( V_39 ) ;
}
return V_39 ;
}
static void F_117 ( struct V_98 * V_99 )
{
F_118 ( F_111 ( V_99 ) -> V_50 ) ;
}
struct V_172 * F_90 ( const struct V_8 * V_9 ,
const union V_188 * V_235 ,
int V_236 )
{
const struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
const struct V_237 * V_238 ;
T_3 V_239 ;
struct V_172 * V_240 = NULL ;
bool V_241 ;
V_238 = F_119 ( V_15 -> V_242 ,
F_16 ( V_9 ) ) ;
if ( ! V_238 )
return NULL ;
F_120 (key, &md5sig->head, node) {
if ( V_173 -> V_236 != V_236 )
continue;
if ( V_236 == V_46 ) {
V_239 = F_121 ( V_173 -> V_243 ) ;
V_241 = ( V_173 -> V_235 . V_244 . V_49 & V_239 ) ==
( V_235 -> V_244 . V_49 & V_239 ) ;
#if F_122 ( V_245 )
} else if ( V_236 == V_246 ) {
V_241 = F_123 ( & V_173 -> V_235 . V_247 , & V_235 -> V_247 ,
V_173 -> V_243 ) ;
#endif
} else {
V_241 = false ;
}
if ( V_241 && ( ! V_240 ||
V_173 -> V_243 > V_240 -> V_243 ) )
V_240 = V_173 ;
}
return V_240 ;
}
static struct V_172 * F_124 ( const struct V_8 * V_9 ,
const union V_188 * V_235 ,
int V_236 , T_6 V_243 )
{
const struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
unsigned int V_248 = sizeof( struct V_249 ) ;
const struct V_237 * V_238 ;
V_238 = F_119 ( V_15 -> V_242 ,
F_16 ( V_9 ) ) ;
if ( ! V_238 )
return NULL ;
#if F_122 ( V_245 )
if ( V_236 == V_246 )
V_248 = sizeof( struct V_250 ) ;
#endif
F_120 (key, &md5sig->head, node) {
if ( V_173 -> V_236 != V_236 )
continue;
if ( ! memcmp ( & V_173 -> V_235 , V_235 , V_248 ) &&
V_173 -> V_243 == V_243 )
return V_173 ;
}
return NULL ;
}
struct V_172 * F_125 ( const struct V_8 * V_9 ,
const struct V_8 * V_251 )
{
const union V_188 * V_235 ;
V_235 = ( const union V_188 * ) & V_251 -> V_252 ;
return F_90 ( V_9 , V_235 , V_46 ) ;
}
int F_126 ( struct V_8 * V_9 , const union V_188 * V_235 ,
int V_236 , T_6 V_243 , const T_6 * V_253 , T_6 V_254 ,
T_7 V_255 )
{
struct V_172 * V_173 ;
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_237 * V_238 ;
V_173 = F_124 ( V_9 , V_235 , V_236 , V_243 ) ;
if ( V_173 ) {
memcpy ( V_173 -> V_173 , V_253 , V_254 ) ;
V_173 -> V_256 = V_254 ;
return 0 ;
}
V_238 = F_15 ( V_15 -> V_242 ,
F_16 ( V_9 ) ) ;
if ( ! V_238 ) {
V_238 = F_127 ( sizeof( * V_238 ) , V_255 ) ;
if ( ! V_238 )
return - V_257 ;
F_128 ( V_9 , V_258 ) ;
F_129 ( & V_238 -> V_164 ) ;
F_130 ( V_15 -> V_242 , V_238 ) ;
}
V_173 = F_131 ( V_9 , sizeof( * V_173 ) , V_255 ) ;
if ( ! V_173 )
return - V_257 ;
if ( ! F_132 () ) {
F_133 ( V_9 , V_173 , sizeof( * V_173 ) ) ;
return - V_257 ;
}
memcpy ( V_173 -> V_173 , V_253 , V_254 ) ;
V_173 -> V_256 = V_254 ;
V_173 -> V_236 = V_236 ;
V_173 -> V_243 = V_243 ;
memcpy ( & V_173 -> V_235 , V_235 ,
( V_236 == V_246 ) ? sizeof( struct V_250 ) :
sizeof( struct V_249 ) ) ;
F_134 ( & V_173 -> V_259 , & V_238 -> V_164 ) ;
return 0 ;
}
int F_135 ( struct V_8 * V_9 , const union V_188 * V_235 , int V_236 ,
T_6 V_243 )
{
struct V_172 * V_173 ;
V_173 = F_124 ( V_9 , V_235 , V_236 , V_243 ) ;
if ( ! V_173 )
return - V_260 ;
F_136 ( & V_173 -> V_259 ) ;
F_137 ( sizeof( * V_173 ) , & V_9 -> V_261 ) ;
F_138 ( V_173 , V_262 ) ;
return 0 ;
}
static void F_139 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
struct V_263 * V_264 ;
struct V_237 * V_238 ;
V_238 = F_15 ( V_15 -> V_242 , 1 ) ;
F_140 (key, n, &md5sig->head, node) {
F_136 ( & V_173 -> V_259 ) ;
F_137 ( sizeof( * V_173 ) , & V_9 -> V_261 ) ;
F_138 ( V_173 , V_262 ) ;
}
}
static int F_141 ( struct V_8 * V_9 , int V_265 ,
char T_8 * V_266 , int V_71 )
{
struct V_267 V_268 ;
struct V_28 * sin = (struct V_28 * ) & V_268 . V_269 ;
T_6 V_243 = 32 ;
if ( V_71 < sizeof( V_268 ) )
return - V_44 ;
if ( F_142 ( & V_268 , V_266 , sizeof( V_268 ) ) )
return - V_270 ;
if ( sin -> V_45 != V_46 )
return - V_44 ;
if ( V_265 == V_271 &&
V_268 . V_272 & V_273 ) {
V_243 = V_268 . V_274 ;
if ( V_243 > 32 )
return - V_44 ;
}
if ( ! V_268 . V_275 )
return F_135 ( V_9 , (union V_188 * ) & sin -> V_48 . V_49 ,
V_46 , V_243 ) ;
if ( V_268 . V_275 > V_276 )
return - V_44 ;
return F_126 ( V_9 , (union V_188 * ) & sin -> V_48 . V_49 ,
V_46 , V_243 , V_268 . V_277 , V_268 . V_275 ,
V_278 ) ;
}
static int F_143 ( struct V_279 * V_280 ,
T_3 V_3 , T_3 V_4 ,
const struct V_108 * V_109 , int V_281 )
{
struct V_282 * V_283 ;
struct V_284 V_285 ;
struct V_108 * V_286 ;
V_283 = V_280 -> V_287 ;
V_283 -> V_4 = V_4 ;
V_283 -> V_3 = V_3 ;
V_283 -> V_288 = 0 ;
V_283 -> V_289 = V_61 ;
V_283 -> V_162 = F_144 ( V_281 ) ;
V_286 = (struct V_108 * ) ( V_283 + 1 ) ;
memcpy ( V_286 , V_109 , sizeof( * V_109 ) ) ;
V_286 -> V_161 = 0 ;
F_145 ( & V_285 , V_283 , sizeof( * V_283 ) + sizeof( * V_109 ) ) ;
F_146 ( V_280 -> V_290 , & V_285 , NULL ,
sizeof( * V_283 ) + sizeof( * V_109 ) ) ;
return F_147 ( V_280 -> V_290 ) ;
}
static int F_93 ( char * V_291 , const struct V_172 * V_173 ,
T_3 V_3 , T_3 V_4 , const struct V_108 * V_109 )
{
struct V_279 * V_280 ;
struct V_292 * V_99 ;
V_280 = F_148 () ;
if ( ! V_280 )
goto V_293;
V_99 = V_280 -> V_290 ;
if ( F_149 ( V_99 ) )
goto V_294;
if ( F_143 ( V_280 , V_3 , V_4 , V_109 , V_109 -> V_166 << 2 ) )
goto V_294;
if ( F_150 ( V_280 , V_173 ) )
goto V_294;
F_146 ( V_99 , NULL , V_291 , 0 ) ;
if ( F_151 ( V_99 ) )
goto V_294;
F_152 () ;
return 0 ;
V_294:
F_152 () ;
V_293:
memset ( V_291 , 0 , 16 ) ;
return 1 ;
}
int F_92 ( char * V_291 , const struct V_172 * V_173 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_279 * V_280 ;
struct V_292 * V_99 ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_9 ) {
V_4 = V_9 -> V_295 ;
V_3 = V_9 -> V_252 ;
} else {
const struct V_105 * V_106 = F_3 ( V_2 ) ;
V_4 = V_106 -> V_4 ;
V_3 = V_106 -> V_3 ;
}
V_280 = F_148 () ;
if ( ! V_280 )
goto V_293;
V_99 = V_280 -> V_290 ;
if ( F_149 ( V_99 ) )
goto V_294;
if ( F_143 ( V_280 , V_3 , V_4 , V_109 , V_2 -> V_162 ) )
goto V_294;
if ( F_153 ( V_280 , V_2 , V_109 -> V_166 << 2 ) )
goto V_294;
if ( F_150 ( V_280 , V_173 ) )
goto V_294;
F_146 ( V_99 , NULL , V_291 , 0 ) ;
if ( F_151 ( V_99 ) )
goto V_294;
F_152 () ;
return 0 ;
V_294:
F_152 () ;
V_293:
memset ( V_291 , 0 , 16 ) ;
return 1 ;
}
static bool F_154 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
#ifdef F_83
const T_5 * V_174 = NULL ;
struct V_172 * V_296 ;
const struct V_105 * V_106 = F_3 ( V_2 ) ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
int V_176 ;
unsigned char V_175 [ 16 ] ;
V_296 = F_90 ( V_9 , (union V_188 * ) & V_106 -> V_4 ,
V_46 ) ;
V_174 = F_88 ( V_109 ) ;
if ( ! V_296 && ! V_174 )
return false ;
if ( V_296 && ! V_174 ) {
F_155 ( F_10 ( V_9 ) , V_297 ) ;
return true ;
}
if ( ! V_296 && V_174 ) {
F_155 ( F_10 ( V_9 ) , V_298 ) ;
return true ;
}
V_176 = F_92 ( V_175 ,
V_296 ,
NULL , V_2 ) ;
if ( V_176 || memcmp ( V_174 , V_175 , 16 ) != 0 ) {
F_155 ( F_10 ( V_9 ) , V_299 ) ;
F_156 ( L_1 ,
& V_106 -> V_4 , F_54 ( V_109 -> V_6 ) ,
& V_106 -> V_3 , F_54 ( V_109 -> V_5 ) ,
V_176 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_157 ( struct V_98 * V_99 ,
const struct V_8 * V_300 ,
struct V_1 * V_2 )
{
struct V_231 * V_232 = F_111 ( V_99 ) ;
F_23 ( F_158 ( V_99 ) , F_3 ( V_2 ) -> V_3 ) ;
F_25 ( F_158 ( V_99 ) , F_3 ( V_2 ) -> V_4 ) ;
V_232 -> V_50 = F_159 ( V_2 ) ;
}
static struct V_84 * F_160 ( const struct V_8 * V_9 ,
struct V_226 * V_56 ,
const struct V_98 * V_99 )
{
return F_113 ( V_9 , & V_56 -> V_57 . V_58 , V_99 ) ;
}
int F_161 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_84 ( V_2 ) -> V_64 & ( V_66 | V_65 ) )
goto V_301;
return F_162 ( & V_302 ,
& V_303 , V_9 , V_2 ) ;
V_301:
F_48 ( V_9 ) ;
return 0 ;
}
struct V_8 * F_163 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_84 * V_78 ,
struct V_98 * V_304 ,
bool * V_305 )
{
struct V_231 * V_232 ;
struct V_30 * V_306 ;
struct V_14 * V_307 ;
struct V_8 * V_308 ;
#ifdef F_83
struct V_172 * V_173 ;
#endif
struct V_40 * V_41 ;
if ( F_164 ( V_9 ) )
goto V_309;
V_308 = F_165 ( V_9 , V_99 , V_2 ) ;
if ( ! V_308 )
goto V_310;
V_308 -> V_76 = V_77 ;
F_166 ( V_308 , V_2 ) ;
V_307 = F_9 ( V_308 ) ;
V_306 = F_14 ( V_308 ) ;
V_232 = F_111 ( V_99 ) ;
F_25 ( V_308 , V_232 -> V_234 ) ;
F_23 ( V_308 , V_232 -> V_233 ) ;
V_308 -> V_60 = V_232 -> V_311 ;
V_306 -> V_59 = V_232 -> V_233 ;
V_41 = V_232 -> V_50 ;
F_130 ( V_306 -> V_41 , V_41 ) ;
V_232 -> V_50 = NULL ;
V_306 -> V_312 = F_55 ( V_2 ) ;
V_306 -> V_313 = F_3 ( V_2 ) -> V_131 ;
V_306 -> V_314 = F_3 ( V_2 ) -> V_198 ;
F_26 ( V_308 ) -> V_70 = 0 ;
if ( V_41 )
F_26 ( V_308 ) -> V_70 = V_41 -> V_50 . V_71 ;
V_306 -> V_80 = V_307 -> V_19 ^ V_81 ;
if ( ! V_78 ) {
V_78 = F_167 ( V_9 , V_308 , V_99 ) ;
if ( ! V_78 )
goto V_315;
} else {
}
F_31 ( V_308 , V_78 ) ;
F_168 ( V_308 , V_78 ) ;
F_39 ( V_308 , F_36 ( V_78 ) ) ;
V_307 -> V_316 = F_169 ( F_9 ( V_9 ) , F_170 ( V_78 ) ) ;
F_171 ( V_308 ) ;
#ifdef F_83
V_173 = F_90 ( V_9 , (union V_188 * ) & V_306 -> V_67 ,
V_46 ) ;
if ( V_173 ) {
F_126 ( V_308 , (union V_188 * ) & V_306 -> V_67 ,
V_46 , 32 , V_173 -> V_173 , V_173 -> V_256 , V_317 ) ;
F_128 ( V_308 , V_258 ) ;
}
#endif
if ( F_172 ( V_9 , V_308 ) < 0 )
goto V_315;
* V_305 = F_173 ( V_308 , F_158 ( V_304 ) ) ;
if ( * V_305 )
F_174 ( V_307 , V_99 ) ;
return V_308 ;
V_309:
F_155 ( F_10 ( V_9 ) , V_318 ) ;
V_310:
F_175 ( V_78 ) ;
exit:
F_48 ( V_9 ) ;
return NULL ;
V_315:
F_176 ( V_308 ) ;
F_73 ( V_308 ) ;
goto exit;
}
static struct V_8 * F_177 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_178
const struct V_108 * V_109 = F_4 ( V_2 ) ;
if ( ! V_109 -> V_183 )
V_9 = F_179 ( V_9 , V_2 ) ;
#endif
return V_9 ;
}
int F_180 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_8 * V_319 ;
if ( V_9 -> V_86 == V_320 ) {
struct V_84 * V_78 = V_9 -> V_321 ;
F_181 ( V_9 , V_2 ) ;
F_182 ( V_9 , V_2 ) ;
if ( V_78 ) {
if ( F_14 ( V_9 ) -> V_322 != V_2 -> V_323 ||
! V_78 -> V_95 -> V_161 ( V_78 , 0 ) ) {
F_175 ( V_78 ) ;
V_9 -> V_321 = NULL ;
}
}
F_183 ( V_9 , V_2 , F_4 ( V_2 ) , V_2 -> V_162 ) ;
return 0 ;
}
if ( F_184 ( V_2 ) )
goto V_324;
if ( V_9 -> V_86 == V_135 ) {
struct V_8 * V_325 = F_177 ( V_9 , V_2 ) ;
if ( ! V_325 )
goto V_326;
if ( V_325 != V_9 ) {
if ( F_185 ( V_9 , V_325 , V_2 ) ) {
V_319 = V_325 ;
goto V_327;
}
return 0 ;
}
} else
F_181 ( V_9 , V_2 ) ;
if ( F_186 ( V_9 , V_2 ) ) {
V_319 = V_9 ;
goto V_327;
}
return 0 ;
V_327:
F_82 ( V_319 , V_2 ) ;
V_326:
F_187 ( V_2 ) ;
return 0 ;
V_324:
F_188 ( F_10 ( V_9 ) , V_328 ) ;
F_188 ( F_10 ( V_9 ) , V_329 ) ;
goto V_326;
}
void F_189 ( struct V_1 * V_2 )
{
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
struct V_8 * V_9 ;
if ( V_2 -> V_330 != V_331 )
return;
if ( ! F_190 ( V_2 , F_191 ( V_2 ) + sizeof( struct V_108 ) ) )
return;
V_106 = F_3 ( V_2 ) ;
V_109 = F_4 ( V_2 ) ;
if ( V_109 -> V_166 < sizeof( struct V_108 ) / 4 )
return;
V_9 = F_53 ( F_52 ( V_2 -> V_118 ) , & V_119 ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , F_54 ( V_109 -> V_5 ) ,
V_2 -> V_323 ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_332 = V_333 ;
if ( F_89 ( V_9 ) ) {
struct V_84 * V_78 = F_192 ( V_9 -> V_321 ) ;
if ( V_78 )
V_78 = F_193 ( V_78 , 0 ) ;
if ( V_78 &&
F_14 ( V_9 ) -> V_322 == V_2 -> V_323 )
F_194 ( V_2 , V_78 ) ;
}
}
}
bool F_195 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
if ( V_334 || ! V_15 -> V_335 . V_336 )
return false ;
if ( V_2 -> V_162 <= F_196 ( V_2 ) &&
F_197 ( & V_15 -> V_335 . V_337 ) == 0 )
return false ;
if ( F_24 ( V_9 -> V_321 ) )
F_198 ( V_2 ) ;
else
F_199 ( V_2 ) ;
F_200 ( & V_15 -> V_335 . V_337 , V_2 ) ;
V_15 -> V_335 . V_338 += V_2 -> V_339 ;
if ( F_197 ( & V_15 -> V_335 . V_337 ) >= 32 ||
V_15 -> V_335 . V_338 + F_201 ( & V_9 -> V_340 ) > V_9 -> V_341 ) {
struct V_1 * V_342 ;
F_68 ( F_61 ( V_9 ) ) ;
F_202 ( F_10 ( V_9 ) , V_343 ,
F_197 ( & V_15 -> V_335 . V_337 ) ) ;
while ( ( V_342 = F_203 ( & V_15 -> V_335 . V_337 ) ) != NULL )
F_204 ( V_9 , V_342 ) ;
V_15 -> V_335 . V_338 = 0 ;
} else if ( F_197 ( & V_15 -> V_335 . V_337 ) == 1 ) {
F_205 ( F_206 ( V_9 ) ,
V_344 | V_345 | V_346 ) ;
if ( ! F_207 ( V_9 ) )
F_71 ( V_9 , V_347 ,
( 3 * F_208 ( V_9 ) ) / 4 ,
V_150 ) ;
}
return true ;
}
bool F_209 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_348 = V_9 -> V_341 + V_9 -> V_349 ;
V_348 += 64 * 1024 ;
F_210 ( V_2 ) ;
if ( F_62 ( F_211 ( V_9 , V_2 , V_348 ) ) ) {
F_74 ( V_9 ) ;
F_46 ( F_10 ( V_9 ) , V_350 ) ;
return true ;
}
return false ;
}
int F_212 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_108 * V_109 = (struct V_108 * ) V_2 -> V_107 ;
unsigned int V_351 = V_2 -> V_162 ;
int V_39 ;
V_39 = F_213 ( V_9 , V_2 , V_109 -> V_166 * 4 ) ;
if ( ! V_39 ) {
V_351 -= V_2 -> V_162 ;
F_101 ( V_2 ) -> V_352 -= V_351 ;
}
return V_39 ;
}
int F_214 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_52 ( V_2 -> V_118 ) ;
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
bool V_353 ;
struct V_8 * V_9 ;
int V_354 ;
if ( V_2 -> V_330 != V_331 )
goto V_355;
F_102 ( V_7 , V_356 ) ;
if ( ! F_190 ( V_2 , sizeof( struct V_108 ) ) )
goto V_355;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
if ( F_62 ( V_109 -> V_166 < sizeof( struct V_108 ) / 4 ) )
goto V_357;
if ( ! F_190 ( V_2 , V_109 -> V_166 * 4 ) )
goto V_355;
if ( F_215 ( V_2 , V_61 , V_358 ) )
goto V_359;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
memmove ( & F_101 ( V_2 ) -> V_200 . V_201 , F_216 ( V_2 ) ,
sizeof( struct V_360 ) ) ;
F_217 () ;
F_101 ( V_2 ) -> V_97 = F_59 ( V_109 -> V_97 ) ;
F_101 ( V_2 ) -> V_352 = ( F_101 ( V_2 ) -> V_97 + V_109 -> V_183 + V_109 -> V_184 +
V_2 -> V_162 - V_109 -> V_166 * 4 ) ;
F_101 ( V_2 ) -> V_182 = F_59 ( V_109 -> V_182 ) ;
F_101 ( V_2 ) -> V_361 = F_218 ( V_109 ) ;
F_101 ( V_2 ) -> V_362 = 0 ;
F_101 ( V_2 ) -> V_363 = F_219 ( V_106 ) ;
F_101 ( V_2 ) -> V_364 = 0 ;
V_365:
V_9 = F_220 ( & V_119 , V_2 , F_221 ( V_109 ) , V_109 -> V_6 ,
V_109 -> V_5 , & V_353 ) ;
if ( ! V_9 )
goto V_366;
V_367:
if ( V_9 -> V_86 == V_121 )
goto V_368;
if ( V_9 -> V_86 == V_122 ) {
struct V_98 * V_99 = F_44 ( V_9 ) ;
struct V_8 * V_325 ;
V_9 = V_99 -> V_102 ;
if ( F_62 ( F_154 ( V_9 , V_2 ) ) ) {
F_222 ( V_9 , V_2 ) ;
F_49 ( V_99 ) ;
goto V_355;
}
if ( F_62 ( V_9 -> V_86 != V_135 ) ) {
F_223 ( V_9 , V_99 ) ;
goto V_365;
}
F_12 ( V_9 ) ;
V_353 = true ;
if ( F_212 ( V_9 , V_2 ) )
goto V_369;
V_325 = F_224 ( V_9 , V_2 , V_99 , false ) ;
if ( ! V_325 ) {
F_49 ( V_99 ) ;
goto V_369;
}
if ( V_325 == V_9 ) {
F_49 ( V_99 ) ;
} else if ( F_185 ( V_9 , V_325 , V_2 ) ) {
F_82 ( V_325 , V_2 ) ;
goto V_369;
} else {
F_75 ( V_9 ) ;
return 0 ;
}
}
if ( F_62 ( V_106 -> V_131 < F_14 ( V_9 ) -> V_132 ) ) {
F_46 ( V_7 , V_133 ) ;
goto V_369;
}
if ( ! F_225 ( V_9 , V_370 , V_2 ) )
goto V_369;
if ( F_154 ( V_9 , V_2 ) )
goto V_369;
F_226 ( V_2 ) ;
if ( F_212 ( V_9 , V_2 ) )
goto V_369;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
V_2 -> V_118 = NULL ;
if ( V_9 -> V_86 == V_135 ) {
V_354 = F_180 ( V_9 , V_2 ) ;
goto V_371;
}
F_227 ( V_9 ) ;
F_228 ( V_9 ) ;
F_229 ( F_9 ( V_9 ) , V_2 ) ;
V_354 = 0 ;
if ( ! F_61 ( V_9 ) ) {
if ( ! F_195 ( V_9 , V_2 ) )
V_354 = F_180 ( V_9 , V_2 ) ;
} else if ( F_209 ( V_9 , V_2 ) ) {
goto V_369;
}
F_74 ( V_9 ) ;
V_371:
if ( V_353 )
F_75 ( V_9 ) ;
return V_354 ;
V_366:
if ( ! F_225 ( NULL , V_370 , V_2 ) )
goto V_355;
if ( F_184 ( V_2 ) ) {
V_359:
F_102 ( V_7 , V_328 ) ;
V_357:
F_102 ( V_7 , V_329 ) ;
} else {
F_82 ( NULL , V_2 ) ;
}
V_355:
F_187 ( V_2 ) ;
return 0 ;
V_369:
F_222 ( V_9 , V_2 ) ;
if ( V_353 )
F_75 ( V_9 ) ;
goto V_355;
V_368:
if ( ! F_225 ( NULL , V_370 , V_2 ) ) {
F_57 ( F_58 ( V_9 ) ) ;
goto V_355;
}
if ( F_184 ( V_2 ) ) {
F_57 ( F_58 ( V_9 ) ) ;
goto V_359;
}
switch ( F_230 ( F_58 ( V_9 ) , V_2 , V_109 ) ) {
case V_372 : {
struct V_8 * V_373 = F_231 ( F_52 ( V_2 -> V_118 ) ,
& V_119 , V_2 ,
F_221 ( V_109 ) ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , V_109 -> V_5 ,
F_55 ( V_2 ) ) ;
if ( V_373 ) {
F_232 ( F_58 ( V_9 ) ) ;
V_9 = V_373 ;
V_353 = false ;
goto V_367;
}
}
case V_374 :
F_107 ( V_9 , V_2 ) ;
break;
case V_375 :
F_82 ( V_9 , V_2 ) ;
F_232 ( F_58 ( V_9 ) ) ;
goto V_355;
case V_376 : ;
}
goto V_355;
}
void F_166 ( struct V_8 * V_9 , const struct V_1 * V_2 )
{
struct V_84 * V_78 = F_86 ( V_2 ) ;
if ( V_78 && F_233 ( V_78 ) ) {
V_9 -> V_321 = V_78 ;
F_14 ( V_9 ) -> V_322 = V_2 -> V_323 ;
}
}
static int F_234 ( struct V_8 * V_9 )
{
struct V_111 * V_112 = F_26 ( V_9 ) ;
F_235 ( V_9 ) ;
V_112 -> V_377 = & V_378 ;
#ifdef F_83
F_9 ( V_9 ) -> V_379 = & V_380 ;
#endif
return 0 ;
}
void F_236 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
F_237 ( V_9 ) ;
F_238 ( V_9 ) ;
F_239 ( V_9 ) ;
F_240 ( V_9 ) ;
F_241 ( V_9 ) ;
F_242 ( & V_15 -> V_381 ) ;
#ifdef F_83
if ( V_15 -> V_242 ) {
F_139 ( V_9 ) ;
F_138 ( V_15 -> V_242 , V_262 ) ;
V_15 -> V_242 = NULL ;
}
#endif
F_243 ( & V_15 -> V_335 . V_337 ) ;
if ( F_26 ( V_9 ) -> V_382 )
F_244 ( V_9 ) ;
F_68 ( V_15 -> V_134 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_247 ( V_9 ) ;
}
static void * F_248 ( struct V_383 * V_97 , void * V_384 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
struct V_7 * V_7 = F_249 ( V_97 ) ;
struct V_388 * V_389 ;
struct V_8 * V_9 = V_384 ;
if ( ! V_9 ) {
V_390:
V_389 = & V_119 . V_391 [ V_386 -> V_392 ] ;
F_250 ( & V_389 -> V_393 ) ;
V_9 = F_251 ( & V_389 -> V_164 ) ;
V_386 -> V_213 = 0 ;
goto V_394;
}
V_389 = & V_119 . V_391 [ V_386 -> V_392 ] ;
++ V_386 -> V_395 ;
++ V_386 -> V_213 ;
V_9 = F_252 ( V_9 ) ;
V_394:
F_253 (sk) {
if ( ! F_254 ( F_10 ( V_9 ) , V_7 ) )
continue;
if ( V_9 -> V_396 == V_386 -> V_236 )
return V_9 ;
}
F_255 ( & V_389 -> V_393 ) ;
V_386 -> V_213 = 0 ;
if ( ++ V_386 -> V_392 < V_397 )
goto V_390;
return NULL ;
}
static void * F_256 ( struct V_383 * V_97 , T_9 * V_398 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
void * V_399 ;
V_386 -> V_392 = 0 ;
V_386 -> V_213 = 0 ;
V_399 = F_248 ( V_97 , NULL ) ;
while ( V_399 && * V_398 ) {
V_399 = F_248 ( V_97 , V_399 ) ;
-- * V_398 ;
}
return V_399 ;
}
static inline bool F_257 ( const struct V_385 * V_386 )
{
return F_258 ( & V_119 . V_400 [ V_386 -> V_392 ] . V_401 ) ;
}
static void * F_259 ( struct V_383 * V_97 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
struct V_7 * V_7 = F_249 ( V_97 ) ;
void * V_399 = NULL ;
V_386 -> V_213 = 0 ;
for (; V_386 -> V_392 <= V_119 . V_402 ; ++ V_386 -> V_392 ) {
struct V_8 * V_9 ;
struct V_403 * V_259 ;
T_10 * V_393 = F_260 ( & V_119 , V_386 -> V_392 ) ;
if ( F_257 ( V_386 ) )
continue;
F_261 ( V_393 ) ;
F_262 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_9 -> V_396 != V_386 -> V_236 ||
! F_254 ( F_10 ( V_9 ) , V_7 ) ) {
continue;
}
V_399 = V_9 ;
goto V_130;
}
F_263 ( V_393 ) ;
}
V_130:
return V_399 ;
}
static void * F_264 ( struct V_383 * V_97 , void * V_384 )
{
struct V_8 * V_9 = V_384 ;
struct V_403 * V_259 ;
struct V_385 * V_386 = V_97 -> V_387 ;
struct V_7 * V_7 = F_249 ( V_97 ) ;
++ V_386 -> V_395 ;
++ V_386 -> V_213 ;
V_9 = F_265 ( V_9 ) ;
F_266 (sk, node) {
if ( V_9 -> V_396 == V_386 -> V_236 && F_254 ( F_10 ( V_9 ) , V_7 ) )
return V_9 ;
}
F_263 ( F_260 ( & V_119 , V_386 -> V_392 ) ) ;
++ V_386 -> V_392 ;
return F_259 ( V_97 ) ;
}
static void * F_267 ( struct V_383 * V_97 , T_9 V_398 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
void * V_399 ;
V_386 -> V_392 = 0 ;
V_399 = F_259 ( V_97 ) ;
while ( V_399 && V_398 ) {
V_399 = F_264 ( V_97 , V_399 ) ;
-- V_398 ;
}
return V_399 ;
}
static void * F_268 ( struct V_383 * V_97 , T_9 V_398 )
{
void * V_399 ;
struct V_385 * V_386 = V_97 -> V_387 ;
V_386 -> V_404 = V_405 ;
V_399 = F_256 ( V_97 , & V_398 ) ;
if ( ! V_399 ) {
V_386 -> V_404 = V_406 ;
V_399 = F_267 ( V_97 , V_398 ) ;
}
return V_399 ;
}
static void * F_269 ( struct V_383 * V_97 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
int V_213 = V_386 -> V_213 ;
int V_407 = V_386 -> V_395 ;
void * V_399 = NULL ;
switch ( V_386 -> V_404 ) {
case V_405 :
if ( V_386 -> V_392 >= V_397 )
break;
V_386 -> V_404 = V_405 ;
V_399 = F_248 ( V_97 , NULL ) ;
while ( V_213 -- && V_399 )
V_399 = F_248 ( V_97 , V_399 ) ;
if ( V_399 )
break;
V_386 -> V_392 = 0 ;
V_386 -> V_404 = V_406 ;
case V_406 :
if ( V_386 -> V_392 > V_119 . V_402 )
break;
V_399 = F_259 ( V_97 ) ;
while ( V_213 -- && V_399 )
V_399 = F_264 ( V_97 , V_399 ) ;
}
V_386 -> V_395 = V_407 ;
return V_399 ;
}
static void * F_270 ( struct V_383 * V_97 , T_9 * V_398 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
void * V_399 ;
if ( * V_398 && * V_398 == V_386 -> V_408 ) {
V_399 = F_269 ( V_97 ) ;
if ( V_399 )
goto V_130;
}
V_386 -> V_404 = V_405 ;
V_386 -> V_395 = 0 ;
V_386 -> V_392 = 0 ;
V_386 -> V_213 = 0 ;
V_399 = * V_398 ? F_268 ( V_97 , * V_398 - 1 ) : V_409 ;
V_130:
V_386 -> V_408 = * V_398 ;
return V_399 ;
}
static void * F_271 ( struct V_383 * V_97 , void * V_410 , T_9 * V_398 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
void * V_399 = NULL ;
if ( V_410 == V_409 ) {
V_399 = F_268 ( V_97 , 0 ) ;
goto V_130;
}
switch ( V_386 -> V_404 ) {
case V_405 :
V_399 = F_248 ( V_97 , V_410 ) ;
if ( ! V_399 ) {
V_386 -> V_404 = V_406 ;
V_386 -> V_392 = 0 ;
V_386 -> V_213 = 0 ;
V_399 = F_259 ( V_97 ) ;
}
break;
case V_406 :
V_399 = F_264 ( V_97 , V_410 ) ;
break;
}
V_130:
++ * V_398 ;
V_386 -> V_408 = * V_398 ;
return V_399 ;
}
static void F_272 ( struct V_383 * V_97 , void * V_410 )
{
struct V_385 * V_386 = V_97 -> V_387 ;
switch ( V_386 -> V_404 ) {
case V_405 :
if ( V_410 != V_409 )
F_255 ( & V_119 . V_391 [ V_386 -> V_392 ] . V_393 ) ;
break;
case V_406 :
if ( V_410 )
F_263 ( F_260 ( & V_119 , V_386 -> V_392 ) ) ;
break;
}
}
int F_273 ( struct V_411 * V_411 , struct V_412 * V_412 )
{
struct V_413 * V_414 = F_274 ( V_411 ) ;
struct V_385 * V_415 ;
int V_39 ;
V_39 = F_275 ( V_411 , V_412 , & V_414 -> V_416 ,
sizeof( struct V_385 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_415 = ( (struct V_383 * ) V_412 -> V_417 ) -> V_387 ;
V_415 -> V_236 = V_414 -> V_236 ;
V_415 -> V_408 = 0 ;
return 0 ;
}
int F_276 ( struct V_7 * V_7 , struct V_413 * V_414 )
{
int V_399 = 0 ;
struct V_418 * V_419 ;
V_414 -> V_416 . V_420 = F_270 ;
V_414 -> V_416 . V_421 = F_271 ;
V_414 -> V_416 . V_422 = F_272 ;
V_419 = F_277 ( V_414 -> V_423 , V_424 , V_7 -> V_425 ,
V_414 -> V_426 , V_414 ) ;
if ( ! V_419 )
V_399 = - V_257 ;
return V_399 ;
}
void F_278 ( struct V_7 * V_7 , struct V_413 * V_414 )
{
F_279 ( V_414 -> V_423 , V_7 -> V_425 ) ;
}
static void F_280 ( const struct V_98 * V_99 ,
struct V_383 * V_427 , int V_428 )
{
const struct V_231 * V_232 = F_111 ( V_99 ) ;
long V_429 = V_99 -> V_430 . V_431 - V_81 ;
F_281 ( V_427 , L_4
L_5 ,
V_428 ,
V_232 -> V_233 ,
V_232 -> V_432 ,
V_232 -> V_234 ,
F_54 ( V_232 -> V_433 ) ,
V_155 ,
0 , 0 ,
1 ,
F_282 ( V_429 ) ,
V_99 -> V_434 ,
F_283 ( F_284 ( V_427 ) ,
F_285 ( V_99 -> V_102 ) ) ,
0 ,
0 ,
0 ,
V_99 ) ;
}
static void F_286 ( struct V_8 * V_9 , struct V_383 * V_427 , int V_428 )
{
int V_435 ;
unsigned long V_436 ;
const struct V_14 * V_15 = F_9 ( V_9 ) ;
const struct V_111 * V_112 = F_26 ( V_9 ) ;
const struct V_30 * V_31 = F_14 ( V_9 ) ;
const struct V_437 * V_438 = & V_112 -> V_439 . V_438 ;
T_3 V_5 = V_31 -> V_67 ;
T_3 V_440 = V_31 -> V_441 ;
T_11 V_442 = F_54 ( V_31 -> V_69 ) ;
T_11 V_443 = F_54 ( V_31 -> V_53 ) ;
int V_444 ;
int V_404 ;
if ( V_112 -> V_445 == V_153 ||
V_112 -> V_445 == V_446 ||
V_112 -> V_445 == V_447 ) {
V_435 = 1 ;
V_436 = V_112 -> V_448 ;
} else if ( V_112 -> V_445 == V_449 ) {
V_435 = 4 ;
V_436 = V_112 -> V_448 ;
} else if ( F_287 ( & V_9 -> V_450 ) ) {
V_435 = 2 ;
V_436 = V_9 -> V_450 . V_431 ;
} else {
V_435 = 0 ;
V_436 = V_81 ;
}
V_404 = F_288 ( V_9 ) ;
if ( V_404 == V_135 )
V_444 = V_9 -> V_451 ;
else
V_444 = F_289 ( int , V_15 -> V_221 - V_15 -> V_452 , 0 ) ;
F_281 ( V_427 , L_6
L_7 ,
V_428 , V_440 , V_443 , V_5 , V_442 , V_404 ,
V_15 -> V_19 - V_15 -> V_115 ,
V_444 ,
V_435 ,
F_282 ( V_436 - V_81 ) ,
V_112 -> V_145 ,
F_283 ( F_284 ( V_427 ) , F_285 ( V_9 ) ) ,
V_112 -> V_453 ,
F_290 ( V_9 ) ,
F_291 ( & V_9 -> V_454 ) , V_9 ,
F_292 ( V_112 -> V_147 ) ,
F_292 ( V_112 -> V_455 . V_456 ) ,
( V_112 -> V_455 . V_457 << 1 ) | V_112 -> V_455 . V_458 ,
V_15 -> V_459 ,
V_404 == V_135 ?
V_438 -> V_460 :
( F_293 ( V_15 ) ? - 1 : V_15 -> V_461 ) ) ;
}
static void F_294 ( const struct V_196 * V_214 ,
struct V_383 * V_427 , int V_428 )
{
long V_429 = V_214 -> V_462 . V_431 - V_81 ;
T_3 V_5 , V_440 ;
T_11 V_442 , V_443 ;
V_5 = V_214 -> V_463 ;
V_440 = V_214 -> V_464 ;
V_442 = F_54 ( V_214 -> V_465 ) ;
V_443 = F_54 ( V_214 -> V_466 ) ;
F_281 ( V_427 , L_4
L_8 ,
V_428 , V_440 , V_443 , V_5 , V_442 , V_214 -> V_467 , 0 , 0 ,
3 , F_282 ( V_429 ) , 0 , 0 , 0 , 0 ,
F_291 ( & V_214 -> V_468 ) , V_214 ) ;
}
static int F_295 ( struct V_383 * V_97 , void * V_410 )
{
struct V_385 * V_386 ;
struct V_8 * V_9 = V_410 ;
F_296 ( V_97 , V_469 - 1 ) ;
if ( V_410 == V_409 ) {
F_297 ( V_97 , L_9
L_10
L_11 ) ;
goto V_130;
}
V_386 = V_97 -> V_387 ;
if ( V_9 -> V_86 == V_121 )
F_294 ( V_410 , V_97 , V_386 -> V_395 ) ;
else if ( V_9 -> V_86 == V_122 )
F_280 ( V_410 , V_97 , V_386 -> V_395 ) ;
else
F_286 ( V_410 , V_97 , V_386 -> V_395 ) ;
V_130:
F_298 ( V_97 , '\n' ) ;
return 0 ;
}
static int T_12 F_299 ( struct V_7 * V_7 )
{
return F_276 ( V_7 , & V_470 ) ;
}
static void T_13 F_300 ( struct V_7 * V_7 )
{
F_278 ( V_7 , & V_470 ) ;
}
int T_14 F_301 ( void )
{
return F_302 ( & V_471 ) ;
}
void F_303 ( void )
{
F_304 ( & V_471 ) ;
}
static void T_13 F_305 ( struct V_7 * V_7 )
{
int V_472 ;
F_306 (cpu)
F_307 ( * F_308 ( V_7 -> V_17 . F_9 , V_472 ) ) ;
F_309 ( V_7 -> V_17 . F_9 ) ;
}
static int T_12 F_310 ( struct V_7 * V_7 )
{
int V_473 , V_472 , V_474 ;
V_7 -> V_17 . F_9 = F_311 ( struct V_8 * ) ;
if ( ! V_7 -> V_17 . F_9 )
return - V_257 ;
F_306 (cpu) {
struct V_8 * V_9 ;
V_473 = F_312 ( & V_9 , V_475 , V_476 ,
V_61 , V_7 ) ;
if ( V_473 )
goto V_477;
F_313 ( V_9 , V_478 ) ;
* F_308 ( V_7 -> V_17 . F_9 , V_472 ) = V_9 ;
}
V_7 -> V_17 . V_479 = 2 ;
V_7 -> V_17 . V_480 = 1 ;
V_7 -> V_17 . V_481 = V_482 ;
V_7 -> V_17 . V_483 = V_484 ;
V_7 -> V_17 . V_485 = V_486 ;
V_7 -> V_17 . V_487 = V_488 ;
V_7 -> V_17 . V_489 = V_490 ;
V_7 -> V_17 . V_491 = V_492 ;
V_7 -> V_17 . V_493 = V_494 ;
V_7 -> V_17 . V_495 = V_496 ;
V_7 -> V_17 . V_497 = 1 ;
V_7 -> V_17 . V_498 = V_499 ;
V_7 -> V_17 . V_500 = V_501 ;
V_7 -> V_17 . V_502 = V_503 ;
V_7 -> V_17 . V_504 = 0 ;
V_7 -> V_17 . V_505 = V_506 ;
V_7 -> V_17 . V_507 = V_508 ;
V_7 -> V_17 . V_18 = 0 ;
V_474 = V_119 . V_402 + 1 ;
V_7 -> V_17 . V_43 . V_509 = ( V_474 + 1 ) / 2 ;
V_7 -> V_17 . V_43 . V_510 = & V_119 ;
V_7 -> V_17 . V_511 = F_314 ( 128 , V_474 / 256 ) ;
V_7 -> V_17 . V_512 = 1 ;
V_7 -> V_17 . V_513 = 1 ;
V_7 -> V_17 . V_514 = 1 ;
return 0 ;
V_477:
F_305 ( V_7 ) ;
return V_473 ;
}
static void T_13 F_315 ( struct V_515 * V_516 )
{
F_316 ( & V_119 , V_46 ) ;
}
void T_14 F_317 ( void )
{
if ( F_302 ( & V_517 ) )
F_318 ( L_12 ) ;
}
