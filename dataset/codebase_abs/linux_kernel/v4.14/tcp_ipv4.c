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
F_55 ( V_103 ) , 0 ) ;
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
F_54 ( V_109 -> V_6 ) , F_55 ( V_2 ) ,
F_92 ( V_2 ) ) ;
if ( ! V_177 )
goto V_130;
V_173 = F_90 ( V_177 , (union V_188 * )
& F_3 ( V_2 ) -> V_4 , V_46 ) ;
if ( ! V_173 )
goto V_130;
V_176 = F_93 ( V_175 , V_173 , NULL , V_2 ) ;
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
F_94 ( ( T_5 * ) & V_169 . V_50 [ 1 ] ,
V_173 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_169 . V_109 ) ;
}
#endif
V_171 . V_167 = F_95 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_171 . V_185 [ 0 ] . V_187 , V_61 , 0 ) ;
V_171 . V_192 = F_79 ( struct V_108 , V_161 ) / 2 ;
V_171 . V_193 = ( V_9 && F_96 ( V_9 ) ) ? V_194 : 0 ;
if ( V_9 )
V_171 . V_195 = V_9 -> V_60 ;
F_97 ( F_79 ( struct V_8 , V_60 ) !=
F_79 ( struct V_196 , V_197 ) ) ;
V_171 . V_198 = F_3 ( V_2 ) -> V_198 ;
V_171 . V_199 = F_98 ( V_7 , V_9 && F_89 ( V_9 ) ? V_9 : NULL ) ;
F_99 () ;
F_100 ( * F_101 ( V_7 -> V_17 . F_9 ) ,
V_2 , & F_102 ( V_2 ) -> V_200 . V_201 . V_50 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_103 ( V_7 , V_202 ) ;
F_103 ( V_7 , V_203 ) ;
F_104 () ;
#ifdef F_83
V_130:
F_105 () ;
#endif
}
static void F_106 ( const struct V_8 * V_9 ,
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
V_169 . V_109 . V_212 = F_107 ( V_204 ) ;
#ifdef F_83
if ( V_173 ) {
int V_213 = ( V_206 ) ? 3 : 0 ;
V_169 . V_50 [ V_213 ++ ] = F_85 ( ( V_189 << 24 ) |
( V_189 << 16 ) |
( V_190 << 8 ) |
V_191 ) ;
V_171 . V_185 [ 0 ] . V_187 += V_168 ;
V_169 . V_109 . V_166 = V_171 . V_185 [ 0 ] . V_187 / 4 ;
F_94 ( ( T_5 * ) & V_169 . V_50 [ V_213 ] ,
V_173 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_169 . V_109 ) ;
}
#endif
V_171 . V_193 = V_208 ;
V_171 . V_167 = F_95 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_171 . V_185 [ 0 ] . V_187 , V_61 , 0 ) ;
V_171 . V_192 = F_79 ( struct V_108 , V_161 ) / 2 ;
if ( V_207 )
V_171 . V_195 = V_207 ;
V_171 . V_198 = V_198 ;
V_171 . V_199 = F_98 ( V_7 , F_89 ( V_9 ) ? V_9 : NULL ) ;
F_99 () ;
F_100 ( * F_101 ( V_7 -> V_17 . F_9 ) ,
V_2 , & F_102 ( V_2 ) -> V_200 . V_201 . V_50 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_171 , V_171 . V_185 [ 0 ] . V_187 ) ;
F_103 ( V_7 , V_202 ) ;
F_104 () ;
}
static void F_108 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_196 * V_214 = F_58 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_9 ) ;
F_106 ( V_9 , V_2 ,
V_13 -> V_20 , V_13 -> V_215 ,
V_13 -> V_216 >> V_214 -> V_217 ,
F_109 () + V_13 -> V_218 ,
V_13 -> V_23 ,
V_214 -> V_197 ,
F_110 ( V_13 ) ,
V_214 -> V_219 ? V_194 : 0 ,
V_214 -> V_220
) ;
F_57 ( V_214 ) ;
}
static void F_111 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_98 * V_99 )
{
T_1 V_97 = ( V_9 -> V_86 == V_135 ) ? F_45 ( V_99 ) -> V_100 + 1 :
F_9 ( V_9 ) -> V_136 ;
F_106 ( V_9 , V_2 , V_97 ,
F_45 ( V_99 ) -> V_221 ,
V_99 -> V_222 >> F_112 ( V_99 ) -> V_223 ,
F_109 () + F_45 ( V_99 ) -> V_224 ,
V_99 -> V_22 ,
0 ,
F_90 ( V_9 , (union V_188 * ) & F_3 ( V_2 ) -> V_3 ,
V_46 ) ,
F_112 ( V_99 ) -> V_225 ? V_194 : 0 ,
F_3 ( V_2 ) -> V_198 ) ;
}
static int F_113 ( const struct V_8 * V_9 , struct V_84 * V_78 ,
struct V_226 * V_56 ,
struct V_98 * V_99 ,
struct V_227 * V_228 ,
enum V_229 V_230 )
{
const struct V_231 * V_232 = F_112 ( V_99 ) ;
struct V_35 V_36 ;
int V_39 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_78 && ( V_78 = F_114 ( V_9 , & V_36 , V_99 ) ) == NULL )
return - 1 ;
V_2 = F_115 ( V_9 , V_78 , V_99 , V_228 , V_230 ) ;
if ( V_2 ) {
F_76 ( V_2 , V_232 -> V_233 , V_232 -> V_234 ) ;
V_39 = F_116 ( V_2 , V_9 , V_232 -> V_233 ,
V_232 -> V_234 ,
F_117 ( V_232 ) ) ;
V_39 = F_118 ( V_39 ) ;
}
return V_39 ;
}
static void F_119 ( struct V_98 * V_99 )
{
F_120 ( F_15 ( F_112 ( V_99 ) -> V_235 , 1 ) ) ;
}
struct V_172 * F_90 ( const struct V_8 * V_9 ,
const union V_188 * V_236 ,
int V_237 )
{
const struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
const struct V_238 * V_239 ;
T_3 V_240 ;
struct V_172 * V_241 = NULL ;
bool V_242 ;
V_239 = F_121 ( V_15 -> V_243 ,
F_16 ( V_9 ) ) ;
if ( ! V_239 )
return NULL ;
F_122 (key, &md5sig->head, node) {
if ( V_173 -> V_237 != V_237 )
continue;
if ( V_237 == V_46 ) {
V_240 = F_123 ( V_173 -> V_244 ) ;
V_242 = ( V_173 -> V_236 . V_245 . V_49 & V_240 ) ==
( V_236 -> V_245 . V_49 & V_240 ) ;
#if F_124 ( V_246 )
} else if ( V_237 == V_247 ) {
V_242 = F_125 ( & V_173 -> V_236 . V_248 , & V_236 -> V_248 ,
V_173 -> V_244 ) ;
#endif
} else {
V_242 = false ;
}
if ( V_242 && ( ! V_241 ||
V_173 -> V_244 > V_241 -> V_244 ) )
V_241 = V_173 ;
}
return V_241 ;
}
static struct V_172 * F_126 ( const struct V_8 * V_9 ,
const union V_188 * V_236 ,
int V_237 , T_6 V_244 )
{
const struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
unsigned int V_249 = sizeof( struct V_250 ) ;
const struct V_238 * V_239 ;
V_239 = F_121 ( V_15 -> V_243 ,
F_16 ( V_9 ) ) ;
if ( ! V_239 )
return NULL ;
#if F_124 ( V_246 )
if ( V_237 == V_247 )
V_249 = sizeof( struct V_251 ) ;
#endif
F_122 (key, &md5sig->head, node) {
if ( V_173 -> V_237 != V_237 )
continue;
if ( ! memcmp ( & V_173 -> V_236 , V_236 , V_249 ) &&
V_173 -> V_244 == V_244 )
return V_173 ;
}
return NULL ;
}
struct V_172 * F_127 ( const struct V_8 * V_9 ,
const struct V_8 * V_252 )
{
const union V_188 * V_236 ;
V_236 = ( const union V_188 * ) & V_252 -> V_253 ;
return F_90 ( V_9 , V_236 , V_46 ) ;
}
int F_128 ( struct V_8 * V_9 , const union V_188 * V_236 ,
int V_237 , T_6 V_244 , const T_6 * V_254 , T_6 V_255 ,
T_7 V_256 )
{
struct V_172 * V_173 ;
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_238 * V_239 ;
V_173 = F_126 ( V_9 , V_236 , V_237 , V_244 ) ;
if ( V_173 ) {
memcpy ( V_173 -> V_173 , V_254 , V_255 ) ;
V_173 -> V_257 = V_255 ;
return 0 ;
}
V_239 = F_15 ( V_15 -> V_243 ,
F_16 ( V_9 ) ) ;
if ( ! V_239 ) {
V_239 = F_129 ( sizeof( * V_239 ) , V_256 ) ;
if ( ! V_239 )
return - V_258 ;
F_130 ( V_9 , V_259 ) ;
F_131 ( & V_239 -> V_164 ) ;
F_132 ( V_15 -> V_243 , V_239 ) ;
}
V_173 = F_133 ( V_9 , sizeof( * V_173 ) , V_256 ) ;
if ( ! V_173 )
return - V_258 ;
if ( ! F_134 () ) {
F_135 ( V_9 , V_173 , sizeof( * V_173 ) ) ;
return - V_258 ;
}
memcpy ( V_173 -> V_173 , V_254 , V_255 ) ;
V_173 -> V_257 = V_255 ;
V_173 -> V_237 = V_237 ;
V_173 -> V_244 = V_244 ;
memcpy ( & V_173 -> V_236 , V_236 ,
( V_237 == V_247 ) ? sizeof( struct V_251 ) :
sizeof( struct V_250 ) ) ;
F_136 ( & V_173 -> V_260 , & V_239 -> V_164 ) ;
return 0 ;
}
int F_137 ( struct V_8 * V_9 , const union V_188 * V_236 , int V_237 ,
T_6 V_244 )
{
struct V_172 * V_173 ;
V_173 = F_126 ( V_9 , V_236 , V_237 , V_244 ) ;
if ( ! V_173 )
return - V_261 ;
F_138 ( & V_173 -> V_260 ) ;
F_139 ( sizeof( * V_173 ) , & V_9 -> V_262 ) ;
F_140 ( V_173 , V_263 ) ;
return 0 ;
}
static void F_141 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_172 * V_173 ;
struct V_264 * V_265 ;
struct V_238 * V_239 ;
V_239 = F_15 ( V_15 -> V_243 , 1 ) ;
F_142 (key, n, &md5sig->head, node) {
F_138 ( & V_173 -> V_260 ) ;
F_139 ( sizeof( * V_173 ) , & V_9 -> V_262 ) ;
F_140 ( V_173 , V_263 ) ;
}
}
static int F_143 ( struct V_8 * V_9 , int V_266 ,
char T_8 * V_267 , int V_71 )
{
struct V_268 V_269 ;
struct V_28 * sin = (struct V_28 * ) & V_269 . V_270 ;
T_6 V_244 = 32 ;
if ( V_71 < sizeof( V_269 ) )
return - V_44 ;
if ( F_144 ( & V_269 , V_267 , sizeof( V_269 ) ) )
return - V_271 ;
if ( sin -> V_45 != V_46 )
return - V_44 ;
if ( V_266 == V_272 &&
V_269 . V_273 & V_274 ) {
V_244 = V_269 . V_275 ;
if ( V_244 > 32 )
return - V_44 ;
}
if ( ! V_269 . V_276 )
return F_137 ( V_9 , (union V_188 * ) & sin -> V_48 . V_49 ,
V_46 , V_244 ) ;
if ( V_269 . V_276 > V_277 )
return - V_44 ;
return F_128 ( V_9 , (union V_188 * ) & sin -> V_48 . V_49 ,
V_46 , V_244 , V_269 . V_278 , V_269 . V_276 ,
V_279 ) ;
}
static int F_145 ( struct V_280 * V_281 ,
T_3 V_3 , T_3 V_4 ,
const struct V_108 * V_109 , int V_282 )
{
struct V_283 * V_284 ;
struct V_285 V_286 ;
struct V_108 * V_287 ;
V_284 = V_281 -> V_288 ;
V_284 -> V_4 = V_4 ;
V_284 -> V_3 = V_3 ;
V_284 -> V_289 = 0 ;
V_284 -> V_290 = V_61 ;
V_284 -> V_162 = F_146 ( V_282 ) ;
V_287 = (struct V_108 * ) ( V_284 + 1 ) ;
memcpy ( V_287 , V_109 , sizeof( * V_109 ) ) ;
V_287 -> V_161 = 0 ;
F_147 ( & V_286 , V_284 , sizeof( * V_284 ) + sizeof( * V_109 ) ) ;
F_148 ( V_281 -> V_291 , & V_286 , NULL ,
sizeof( * V_284 ) + sizeof( * V_109 ) ) ;
return F_149 ( V_281 -> V_291 ) ;
}
static int F_94 ( char * V_292 , const struct V_172 * V_173 ,
T_3 V_3 , T_3 V_4 , const struct V_108 * V_109 )
{
struct V_280 * V_281 ;
struct V_293 * V_99 ;
V_281 = F_150 () ;
if ( ! V_281 )
goto V_294;
V_99 = V_281 -> V_291 ;
if ( F_151 ( V_99 ) )
goto V_295;
if ( F_145 ( V_281 , V_3 , V_4 , V_109 , V_109 -> V_166 << 2 ) )
goto V_295;
if ( F_152 ( V_281 , V_173 ) )
goto V_295;
F_148 ( V_99 , NULL , V_292 , 0 ) ;
if ( F_153 ( V_99 ) )
goto V_295;
F_154 () ;
return 0 ;
V_295:
F_154 () ;
V_294:
memset ( V_292 , 0 , 16 ) ;
return 1 ;
}
int F_93 ( char * V_292 , const struct V_172 * V_173 ,
const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_280 * V_281 ;
struct V_293 * V_99 ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_9 ) {
V_4 = V_9 -> V_296 ;
V_3 = V_9 -> V_253 ;
} else {
const struct V_105 * V_106 = F_3 ( V_2 ) ;
V_4 = V_106 -> V_4 ;
V_3 = V_106 -> V_3 ;
}
V_281 = F_150 () ;
if ( ! V_281 )
goto V_294;
V_99 = V_281 -> V_291 ;
if ( F_151 ( V_99 ) )
goto V_295;
if ( F_145 ( V_281 , V_3 , V_4 , V_109 , V_2 -> V_162 ) )
goto V_295;
if ( F_155 ( V_281 , V_2 , V_109 -> V_166 << 2 ) )
goto V_295;
if ( F_152 ( V_281 , V_173 ) )
goto V_295;
F_148 ( V_99 , NULL , V_292 , 0 ) ;
if ( F_153 ( V_99 ) )
goto V_295;
F_154 () ;
return 0 ;
V_295:
F_154 () ;
V_294:
memset ( V_292 , 0 , 16 ) ;
return 1 ;
}
static bool F_156 ( const struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
#ifdef F_83
const T_5 * V_174 = NULL ;
struct V_172 * V_297 ;
const struct V_105 * V_106 = F_3 ( V_2 ) ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
int V_176 ;
unsigned char V_175 [ 16 ] ;
V_297 = F_90 ( V_9 , (union V_188 * ) & V_106 -> V_4 ,
V_46 ) ;
V_174 = F_88 ( V_109 ) ;
if ( ! V_297 && ! V_174 )
return false ;
if ( V_297 && ! V_174 ) {
F_157 ( F_10 ( V_9 ) , V_298 ) ;
return true ;
}
if ( ! V_297 && V_174 ) {
F_157 ( F_10 ( V_9 ) , V_299 ) ;
return true ;
}
V_176 = F_93 ( V_175 ,
V_297 ,
NULL , V_2 ) ;
if ( V_176 || memcmp ( V_174 , V_175 , 16 ) != 0 ) {
F_157 ( F_10 ( V_9 ) , V_300 ) ;
F_158 ( L_1 ,
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
static void F_159 ( struct V_98 * V_99 ,
const struct V_8 * V_301 ,
struct V_1 * V_2 )
{
struct V_231 * V_232 = F_112 ( V_99 ) ;
struct V_7 * V_7 = F_10 ( V_301 ) ;
F_23 ( F_160 ( V_99 ) , F_3 ( V_2 ) -> V_3 ) ;
F_25 ( F_160 ( V_99 ) , F_3 ( V_2 ) -> V_4 ) ;
F_161 ( V_232 -> V_235 , F_162 ( V_7 , V_2 ) ) ;
}
static struct V_84 * F_163 ( const struct V_8 * V_9 ,
struct V_226 * V_56 ,
const struct V_98 * V_99 )
{
return F_114 ( V_9 , & V_56 -> V_57 . V_58 , V_99 ) ;
}
int F_164 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
if ( F_84 ( V_2 ) -> V_64 & ( V_66 | V_65 ) )
goto V_302;
return F_165 ( & V_303 ,
& V_304 , V_9 , V_2 ) ;
V_302:
F_48 ( V_9 ) ;
return 0 ;
}
struct V_8 * F_166 ( const struct V_8 * V_9 , struct V_1 * V_2 ,
struct V_98 * V_99 ,
struct V_84 * V_78 ,
struct V_98 * V_305 ,
bool * V_306 )
{
struct V_231 * V_232 ;
struct V_30 * V_307 ;
struct V_14 * V_308 ;
struct V_8 * V_309 ;
#ifdef F_83
struct V_172 * V_173 ;
#endif
struct V_40 * V_41 ;
if ( F_167 ( V_9 ) )
goto V_310;
V_309 = F_168 ( V_9 , V_99 , V_2 ) ;
if ( ! V_309 )
goto V_311;
V_309 -> V_76 = V_77 ;
F_169 ( V_309 , V_2 ) ;
V_308 = F_9 ( V_309 ) ;
V_307 = F_14 ( V_309 ) ;
V_232 = F_112 ( V_99 ) ;
F_25 ( V_309 , V_232 -> V_234 ) ;
F_23 ( V_309 , V_232 -> V_233 ) ;
V_309 -> V_60 = V_232 -> V_312 ;
V_307 -> V_59 = V_232 -> V_233 ;
V_41 = F_170 ( V_232 -> V_235 ) ;
F_161 ( V_307 -> V_41 , V_41 ) ;
V_307 -> V_313 = F_55 ( V_2 ) ;
V_307 -> V_314 = F_3 ( V_2 ) -> V_131 ;
V_307 -> V_315 = F_3 ( V_2 ) -> V_198 ;
F_26 ( V_309 ) -> V_70 = 0 ;
if ( V_41 )
F_26 ( V_309 ) -> V_70 = V_41 -> V_50 . V_71 ;
V_307 -> V_80 = V_308 -> V_19 ^ V_81 ;
if ( ! V_78 ) {
V_78 = F_171 ( V_9 , V_309 , V_99 ) ;
if ( ! V_78 )
goto V_316;
} else {
}
F_31 ( V_309 , V_78 ) ;
F_172 ( V_309 , V_78 ) ;
F_39 ( V_309 , F_36 ( V_78 ) ) ;
V_308 -> V_317 = F_173 ( F_9 ( V_9 ) , F_174 ( V_78 ) ) ;
F_175 ( V_309 ) ;
#ifdef F_83
V_173 = F_90 ( V_9 , (union V_188 * ) & V_307 -> V_67 ,
V_46 ) ;
if ( V_173 ) {
F_128 ( V_309 , (union V_188 * ) & V_307 -> V_67 ,
V_46 , 32 , V_173 -> V_173 , V_173 -> V_257 , V_318 ) ;
F_130 ( V_309 , V_259 ) ;
}
#endif
if ( F_176 ( V_9 , V_309 ) < 0 )
goto V_316;
* V_306 = F_177 ( V_309 , F_160 ( V_305 ) ) ;
if ( F_24 ( * V_306 ) ) {
F_178 ( V_308 , V_99 ) ;
V_232 -> V_235 = NULL ;
} else {
V_307 -> V_41 = NULL ;
}
return V_309 ;
V_310:
F_157 ( F_10 ( V_9 ) , V_319 ) ;
V_311:
F_179 ( V_78 ) ;
exit:
F_48 ( V_9 ) ;
return NULL ;
V_316:
V_307 -> V_41 = NULL ;
F_180 ( V_309 ) ;
F_73 ( V_309 ) ;
goto exit;
}
static struct V_8 * F_181 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
#ifdef F_182
const struct V_108 * V_109 = F_4 ( V_2 ) ;
if ( ! V_109 -> V_183 )
V_9 = F_183 ( V_9 , V_2 ) ;
#endif
return V_9 ;
}
int F_184 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_8 * V_320 ;
if ( V_9 -> V_86 == V_321 ) {
struct V_84 * V_78 = V_9 -> V_322 ;
F_185 ( V_9 , V_2 ) ;
F_186 ( V_9 , V_2 ) ;
if ( V_78 ) {
if ( F_14 ( V_9 ) -> V_323 != V_2 -> V_324 ||
! V_78 -> V_95 -> V_161 ( V_78 , 0 ) ) {
F_179 ( V_78 ) ;
V_9 -> V_322 = NULL ;
}
}
F_187 ( V_9 , V_2 , F_4 ( V_2 ) ) ;
return 0 ;
}
if ( F_188 ( V_2 ) )
goto V_325;
if ( V_9 -> V_86 == V_135 ) {
struct V_8 * V_326 = F_181 ( V_9 , V_2 ) ;
if ( ! V_326 )
goto V_327;
if ( V_326 != V_9 ) {
if ( F_189 ( V_9 , V_326 , V_2 ) ) {
V_320 = V_326 ;
goto V_328;
}
return 0 ;
}
} else
F_185 ( V_9 , V_2 ) ;
if ( F_190 ( V_9 , V_2 ) ) {
V_320 = V_9 ;
goto V_328;
}
return 0 ;
V_328:
F_82 ( V_320 , V_2 ) ;
V_327:
F_191 ( V_2 ) ;
return 0 ;
V_325:
F_192 ( F_10 ( V_9 ) , V_329 ) ;
F_192 ( F_10 ( V_9 ) , V_330 ) ;
goto V_327;
}
int F_193 ( struct V_1 * V_2 )
{
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
struct V_8 * V_9 ;
if ( V_2 -> V_331 != V_332 )
return 0 ;
if ( ! F_194 ( V_2 , F_195 ( V_2 ) + sizeof( struct V_108 ) ) )
return 0 ;
V_106 = F_3 ( V_2 ) ;
V_109 = F_4 ( V_2 ) ;
if ( V_109 -> V_166 < sizeof( struct V_108 ) / 4 )
return 0 ;
V_9 = F_53 ( F_52 ( V_2 -> V_118 ) , & V_119 ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , F_54 ( V_109 -> V_5 ) ,
V_2 -> V_324 , F_196 ( V_2 ) ) ;
if ( V_9 ) {
V_2 -> V_9 = V_9 ;
V_2 -> V_333 = V_334 ;
if ( F_89 ( V_9 ) ) {
struct V_84 * V_78 = F_197 ( V_9 -> V_322 ) ;
if ( V_78 )
V_78 = F_198 ( V_78 , 0 ) ;
if ( V_78 &&
F_14 ( V_9 ) -> V_323 == V_2 -> V_324 )
F_199 ( V_2 , V_78 ) ;
}
}
return 0 ;
}
bool F_200 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
T_1 V_335 = V_9 -> V_336 + V_9 -> V_337 ;
V_335 += 64 * 1024 ;
F_201 ( V_2 ) ;
if ( F_62 ( F_202 ( V_9 , V_2 , V_335 ) ) ) {
F_74 ( V_9 ) ;
F_46 ( F_10 ( V_9 ) , V_338 ) ;
return true ;
}
return false ;
}
int F_203 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_108 * V_109 = (struct V_108 * ) V_2 -> V_107 ;
unsigned int V_339 = V_2 -> V_162 ;
int V_39 ;
V_39 = F_204 ( V_9 , V_2 , V_109 -> V_166 * 4 ) ;
if ( ! V_39 ) {
V_339 -= V_2 -> V_162 ;
F_102 ( V_2 ) -> V_340 -= V_339 ;
}
return V_39 ;
}
int F_205 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_52 ( V_2 -> V_118 ) ;
int V_341 = F_196 ( V_2 ) ;
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
bool V_342 ;
struct V_8 * V_9 ;
int V_343 ;
if ( V_2 -> V_331 != V_332 )
goto V_344;
F_103 ( V_7 , V_345 ) ;
if ( ! F_194 ( V_2 , sizeof( struct V_108 ) ) )
goto V_344;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
if ( F_62 ( V_109 -> V_166 < sizeof( struct V_108 ) / 4 ) )
goto V_346;
if ( ! F_194 ( V_2 , V_109 -> V_166 * 4 ) )
goto V_344;
if ( F_206 ( V_2 , V_61 , V_347 ) )
goto V_348;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
memmove ( & F_102 ( V_2 ) -> V_200 . V_201 , F_207 ( V_2 ) ,
sizeof( struct V_349 ) ) ;
F_208 () ;
F_102 ( V_2 ) -> V_97 = F_59 ( V_109 -> V_97 ) ;
F_102 ( V_2 ) -> V_340 = ( F_102 ( V_2 ) -> V_97 + V_109 -> V_183 + V_109 -> V_184 +
V_2 -> V_162 - V_109 -> V_166 * 4 ) ;
F_102 ( V_2 ) -> V_182 = F_59 ( V_109 -> V_182 ) ;
F_102 ( V_2 ) -> V_350 = F_209 ( V_109 ) ;
F_102 ( V_2 ) -> V_351 = 0 ;
F_102 ( V_2 ) -> V_352 = F_210 ( V_106 ) ;
F_102 ( V_2 ) -> V_353 = 0 ;
F_102 ( V_2 ) -> V_354 =
V_2 -> V_355 || F_211 ( V_2 ) -> V_356 ;
V_357:
V_9 = F_212 ( & V_119 , V_2 , F_213 ( V_109 ) , V_109 -> V_6 ,
V_109 -> V_5 , V_341 , & V_342 ) ;
if ( ! V_9 )
goto V_358;
V_359:
if ( V_9 -> V_86 == V_121 )
goto V_360;
if ( V_9 -> V_86 == V_122 ) {
struct V_98 * V_99 = F_44 ( V_9 ) ;
struct V_8 * V_326 ;
V_9 = V_99 -> V_102 ;
if ( F_62 ( F_156 ( V_9 , V_2 ) ) ) {
F_214 ( V_9 , V_2 ) ;
F_49 ( V_99 ) ;
goto V_344;
}
if ( F_62 ( V_9 -> V_86 != V_135 ) ) {
F_215 ( V_9 , V_99 ) ;
goto V_357;
}
F_12 ( V_9 ) ;
V_342 = true ;
V_326 = NULL ;
if ( ! F_203 ( V_9 , V_2 ) )
V_326 = F_216 ( V_9 , V_2 , V_99 , false ) ;
if ( ! V_326 ) {
F_49 ( V_99 ) ;
goto V_361;
}
if ( V_326 == V_9 ) {
F_49 ( V_99 ) ;
} else if ( F_189 ( V_9 , V_326 , V_2 ) ) {
F_82 ( V_326 , V_2 ) ;
goto V_361;
} else {
F_75 ( V_9 ) ;
return 0 ;
}
}
if ( F_62 ( V_106 -> V_131 < F_14 ( V_9 ) -> V_132 ) ) {
F_46 ( V_7 , V_133 ) ;
goto V_361;
}
if ( ! F_217 ( V_9 , V_362 , V_2 ) )
goto V_361;
if ( F_156 ( V_9 , V_2 ) )
goto V_361;
F_218 ( V_2 ) ;
if ( F_203 ( V_9 , V_2 ) )
goto V_361;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
V_2 -> V_118 = NULL ;
if ( V_9 -> V_86 == V_135 ) {
V_343 = F_184 ( V_9 , V_2 ) ;
goto V_363;
}
F_219 ( V_9 ) ;
F_220 ( V_9 ) ;
F_221 ( F_9 ( V_9 ) , V_2 ) ;
V_343 = 0 ;
if ( ! F_61 ( V_9 ) ) {
V_343 = F_184 ( V_9 , V_2 ) ;
} else if ( F_200 ( V_9 , V_2 ) ) {
goto V_361;
}
F_74 ( V_9 ) ;
V_363:
if ( V_342 )
F_75 ( V_9 ) ;
return V_343 ;
V_358:
if ( ! F_217 ( NULL , V_362 , V_2 ) )
goto V_344;
if ( F_188 ( V_2 ) ) {
V_348:
F_103 ( V_7 , V_329 ) ;
V_346:
F_103 ( V_7 , V_330 ) ;
} else {
F_82 ( NULL , V_2 ) ;
}
V_344:
F_191 ( V_2 ) ;
return 0 ;
V_361:
F_214 ( V_9 , V_2 ) ;
if ( V_342 )
F_75 ( V_9 ) ;
goto V_344;
V_360:
if ( ! F_217 ( NULL , V_362 , V_2 ) ) {
F_57 ( F_58 ( V_9 ) ) ;
goto V_344;
}
if ( F_188 ( V_2 ) ) {
F_57 ( F_58 ( V_9 ) ) ;
goto V_348;
}
switch ( F_222 ( F_58 ( V_9 ) , V_2 , V_109 ) ) {
case V_364 : {
struct V_8 * V_365 = F_223 ( F_52 ( V_2 -> V_118 ) ,
& V_119 , V_2 ,
F_213 ( V_109 ) ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , V_109 -> V_5 ,
F_55 ( V_2 ) ,
V_341 ) ;
if ( V_365 ) {
F_224 ( F_58 ( V_9 ) ) ;
V_9 = V_365 ;
V_342 = false ;
goto V_359;
}
}
case V_366 :
F_108 ( V_9 , V_2 ) ;
break;
case V_367 :
F_82 ( V_9 , V_2 ) ;
F_224 ( F_58 ( V_9 ) ) ;
goto V_344;
case V_368 : ;
}
goto V_344;
}
void F_169 ( struct V_8 * V_9 , const struct V_1 * V_2 )
{
struct V_84 * V_78 = F_86 ( V_2 ) ;
if ( V_78 && F_225 ( V_78 ) ) {
V_9 -> V_322 = V_78 ;
F_14 ( V_9 ) -> V_323 = V_2 -> V_324 ;
}
}
static int F_226 ( struct V_8 * V_9 )
{
struct V_111 * V_112 = F_26 ( V_9 ) ;
F_227 ( V_9 ) ;
V_112 -> V_369 = & V_370 ;
#ifdef F_83
F_9 ( V_9 ) -> V_371 = & V_372 ;
#endif
return 0 ;
}
void F_228 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
F_229 ( V_9 ) ;
F_230 ( V_9 ) ;
F_231 ( V_9 ) ;
F_232 ( V_9 ) ;
F_233 ( V_9 ) ;
F_234 ( & V_15 -> V_373 ) ;
#ifdef F_83
if ( V_15 -> V_243 ) {
F_141 ( V_9 ) ;
F_140 ( V_15 -> V_243 , V_263 ) ;
V_15 -> V_243 = NULL ;
}
#endif
if ( F_26 ( V_9 ) -> V_374 )
F_235 ( V_9 ) ;
F_68 ( V_15 -> V_134 ) ;
F_236 ( V_15 ) ;
F_237 ( V_15 ) ;
F_238 ( V_9 ) ;
}
static void * F_239 ( struct V_375 * V_97 , void * V_376 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
struct V_7 * V_7 = F_240 ( V_97 ) ;
struct V_380 * V_381 ;
struct V_8 * V_9 = V_376 ;
if ( ! V_9 ) {
V_382:
V_381 = & V_119 . V_383 [ V_378 -> V_384 ] ;
F_241 ( & V_381 -> V_385 ) ;
V_9 = F_242 ( & V_381 -> V_164 ) ;
V_378 -> V_213 = 0 ;
goto V_386;
}
V_381 = & V_119 . V_383 [ V_378 -> V_384 ] ;
++ V_378 -> V_387 ;
++ V_378 -> V_213 ;
V_9 = F_243 ( V_9 ) ;
V_386:
F_244 (sk) {
if ( ! F_245 ( F_10 ( V_9 ) , V_7 ) )
continue;
if ( V_9 -> V_388 == V_378 -> V_237 )
return V_9 ;
}
F_246 ( & V_381 -> V_385 ) ;
V_378 -> V_213 = 0 ;
if ( ++ V_378 -> V_384 < V_389 )
goto V_382;
return NULL ;
}
static void * F_247 ( struct V_375 * V_97 , T_9 * V_390 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
void * V_391 ;
V_378 -> V_384 = 0 ;
V_378 -> V_213 = 0 ;
V_391 = F_239 ( V_97 , NULL ) ;
while ( V_391 && * V_390 ) {
V_391 = F_239 ( V_97 , V_391 ) ;
-- * V_390 ;
}
return V_391 ;
}
static inline bool F_248 ( const struct V_377 * V_378 )
{
return F_249 ( & V_119 . V_392 [ V_378 -> V_384 ] . V_393 ) ;
}
static void * F_250 ( struct V_375 * V_97 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
struct V_7 * V_7 = F_240 ( V_97 ) ;
void * V_391 = NULL ;
V_378 -> V_213 = 0 ;
for (; V_378 -> V_384 <= V_119 . V_394 ; ++ V_378 -> V_384 ) {
struct V_8 * V_9 ;
struct V_395 * V_260 ;
T_10 * V_385 = F_251 ( & V_119 , V_378 -> V_384 ) ;
if ( F_248 ( V_378 ) )
continue;
F_252 ( V_385 ) ;
F_253 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_9 -> V_388 != V_378 -> V_237 ||
! F_245 ( F_10 ( V_9 ) , V_7 ) ) {
continue;
}
V_391 = V_9 ;
goto V_130;
}
F_254 ( V_385 ) ;
}
V_130:
return V_391 ;
}
static void * F_255 ( struct V_375 * V_97 , void * V_376 )
{
struct V_8 * V_9 = V_376 ;
struct V_395 * V_260 ;
struct V_377 * V_378 = V_97 -> V_379 ;
struct V_7 * V_7 = F_240 ( V_97 ) ;
++ V_378 -> V_387 ;
++ V_378 -> V_213 ;
V_9 = F_256 ( V_9 ) ;
F_257 (sk, node) {
if ( V_9 -> V_388 == V_378 -> V_237 && F_245 ( F_10 ( V_9 ) , V_7 ) )
return V_9 ;
}
F_254 ( F_251 ( & V_119 , V_378 -> V_384 ) ) ;
++ V_378 -> V_384 ;
return F_250 ( V_97 ) ;
}
static void * F_258 ( struct V_375 * V_97 , T_9 V_390 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
void * V_391 ;
V_378 -> V_384 = 0 ;
V_391 = F_250 ( V_97 ) ;
while ( V_391 && V_390 ) {
V_391 = F_255 ( V_97 , V_391 ) ;
-- V_390 ;
}
return V_391 ;
}
static void * F_259 ( struct V_375 * V_97 , T_9 V_390 )
{
void * V_391 ;
struct V_377 * V_378 = V_97 -> V_379 ;
V_378 -> V_396 = V_397 ;
V_391 = F_247 ( V_97 , & V_390 ) ;
if ( ! V_391 ) {
V_378 -> V_396 = V_398 ;
V_391 = F_258 ( V_97 , V_390 ) ;
}
return V_391 ;
}
static void * F_260 ( struct V_375 * V_97 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
int V_213 = V_378 -> V_213 ;
int V_399 = V_378 -> V_387 ;
void * V_391 = NULL ;
switch ( V_378 -> V_396 ) {
case V_397 :
if ( V_378 -> V_384 >= V_389 )
break;
V_378 -> V_396 = V_397 ;
V_391 = F_239 ( V_97 , NULL ) ;
while ( V_213 -- && V_391 )
V_391 = F_239 ( V_97 , V_391 ) ;
if ( V_391 )
break;
V_378 -> V_384 = 0 ;
V_378 -> V_396 = V_398 ;
case V_398 :
if ( V_378 -> V_384 > V_119 . V_394 )
break;
V_391 = F_250 ( V_97 ) ;
while ( V_213 -- && V_391 )
V_391 = F_255 ( V_97 , V_391 ) ;
}
V_378 -> V_387 = V_399 ;
return V_391 ;
}
static void * F_261 ( struct V_375 * V_97 , T_9 * V_390 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
void * V_391 ;
if ( * V_390 && * V_390 == V_378 -> V_400 ) {
V_391 = F_260 ( V_97 ) ;
if ( V_391 )
goto V_130;
}
V_378 -> V_396 = V_397 ;
V_378 -> V_387 = 0 ;
V_378 -> V_384 = 0 ;
V_378 -> V_213 = 0 ;
V_391 = * V_390 ? F_259 ( V_97 , * V_390 - 1 ) : V_401 ;
V_130:
V_378 -> V_400 = * V_390 ;
return V_391 ;
}
static void * F_262 ( struct V_375 * V_97 , void * V_402 , T_9 * V_390 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
void * V_391 = NULL ;
if ( V_402 == V_401 ) {
V_391 = F_259 ( V_97 , 0 ) ;
goto V_130;
}
switch ( V_378 -> V_396 ) {
case V_397 :
V_391 = F_239 ( V_97 , V_402 ) ;
if ( ! V_391 ) {
V_378 -> V_396 = V_398 ;
V_378 -> V_384 = 0 ;
V_378 -> V_213 = 0 ;
V_391 = F_250 ( V_97 ) ;
}
break;
case V_398 :
V_391 = F_255 ( V_97 , V_402 ) ;
break;
}
V_130:
++ * V_390 ;
V_378 -> V_400 = * V_390 ;
return V_391 ;
}
static void F_263 ( struct V_375 * V_97 , void * V_402 )
{
struct V_377 * V_378 = V_97 -> V_379 ;
switch ( V_378 -> V_396 ) {
case V_397 :
if ( V_402 != V_401 )
F_246 ( & V_119 . V_383 [ V_378 -> V_384 ] . V_385 ) ;
break;
case V_398 :
if ( V_402 )
F_254 ( F_251 ( & V_119 , V_378 -> V_384 ) ) ;
break;
}
}
int F_264 ( struct V_403 * V_403 , struct V_404 * V_404 )
{
struct V_405 * V_406 = F_265 ( V_403 ) ;
struct V_377 * V_407 ;
int V_39 ;
V_39 = F_266 ( V_403 , V_404 , & V_406 -> V_408 ,
sizeof( struct V_377 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_407 = ( (struct V_375 * ) V_404 -> V_409 ) -> V_379 ;
V_407 -> V_237 = V_406 -> V_237 ;
V_407 -> V_400 = 0 ;
return 0 ;
}
int F_267 ( struct V_7 * V_7 , struct V_405 * V_406 )
{
int V_391 = 0 ;
struct V_410 * V_411 ;
V_406 -> V_408 . V_412 = F_261 ;
V_406 -> V_408 . V_413 = F_262 ;
V_406 -> V_408 . V_414 = F_263 ;
V_411 = F_268 ( V_406 -> V_415 , V_416 , V_7 -> V_417 ,
V_406 -> V_418 , V_406 ) ;
if ( ! V_411 )
V_391 = - V_258 ;
return V_391 ;
}
void F_269 ( struct V_7 * V_7 , struct V_405 * V_406 )
{
F_270 ( V_406 -> V_415 , V_7 -> V_417 ) ;
}
static void F_271 ( const struct V_98 * V_99 ,
struct V_375 * V_419 , int V_420 )
{
const struct V_231 * V_232 = F_112 ( V_99 ) ;
long V_421 = V_99 -> V_422 . V_423 - V_81 ;
F_272 ( V_419 , L_4
L_5 ,
V_420 ,
V_232 -> V_233 ,
V_232 -> V_424 ,
V_232 -> V_234 ,
F_54 ( V_232 -> V_425 ) ,
V_155 ,
0 , 0 ,
1 ,
F_273 ( V_421 ) ,
V_99 -> V_426 ,
F_274 ( F_275 ( V_419 ) ,
F_276 ( V_99 -> V_102 ) ) ,
0 ,
0 ,
0 ,
V_99 ) ;
}
static void F_277 ( struct V_8 * V_9 , struct V_375 * V_419 , int V_420 )
{
int V_427 ;
unsigned long V_428 ;
const struct V_14 * V_15 = F_9 ( V_9 ) ;
const struct V_111 * V_112 = F_26 ( V_9 ) ;
const struct V_30 * V_31 = F_14 ( V_9 ) ;
const struct V_429 * V_430 = & V_112 -> V_431 . V_430 ;
T_3 V_5 = V_31 -> V_67 ;
T_3 V_432 = V_31 -> V_433 ;
T_11 V_434 = F_54 ( V_31 -> V_69 ) ;
T_11 V_435 = F_54 ( V_31 -> V_53 ) ;
int V_436 ;
int V_396 ;
if ( V_112 -> V_437 == V_153 ||
V_112 -> V_437 == V_438 ||
V_112 -> V_437 == V_439 ) {
V_427 = 1 ;
V_428 = V_112 -> V_440 ;
} else if ( V_112 -> V_437 == V_441 ) {
V_427 = 4 ;
V_428 = V_112 -> V_440 ;
} else if ( F_278 ( & V_9 -> V_442 ) ) {
V_427 = 2 ;
V_428 = V_9 -> V_442 . V_423 ;
} else {
V_427 = 0 ;
V_428 = V_81 ;
}
V_396 = F_279 ( V_9 ) ;
if ( V_396 == V_135 )
V_436 = V_9 -> V_443 ;
else
V_436 = F_280 ( int , V_15 -> V_221 - V_15 -> V_444 , 0 ) ;
F_272 ( V_419 , L_6
L_7 ,
V_420 , V_432 , V_435 , V_5 , V_434 , V_396 ,
V_15 -> V_19 - V_15 -> V_115 ,
V_436 ,
V_427 ,
F_273 ( V_428 - V_81 ) ,
V_112 -> V_145 ,
F_274 ( F_275 ( V_419 ) , F_276 ( V_9 ) ) ,
V_112 -> V_445 ,
F_281 ( V_9 ) ,
F_282 ( & V_9 -> V_446 ) , V_9 ,
F_283 ( V_112 -> V_147 ) ,
F_283 ( V_112 -> V_447 . V_448 ) ,
( V_112 -> V_447 . V_449 << 1 ) | V_112 -> V_447 . V_450 ,
V_15 -> V_451 ,
V_396 == V_135 ?
V_430 -> V_452 :
( F_284 ( V_15 ) ? - 1 : V_15 -> V_453 ) ) ;
}
static void F_285 ( const struct V_196 * V_214 ,
struct V_375 * V_419 , int V_420 )
{
long V_421 = V_214 -> V_454 . V_423 - V_81 ;
T_3 V_5 , V_432 ;
T_11 V_434 , V_435 ;
V_5 = V_214 -> V_455 ;
V_432 = V_214 -> V_456 ;
V_434 = F_54 ( V_214 -> V_457 ) ;
V_435 = F_54 ( V_214 -> V_458 ) ;
F_272 ( V_419 , L_4
L_8 ,
V_420 , V_432 , V_435 , V_5 , V_434 , V_214 -> V_459 , 0 , 0 ,
3 , F_273 ( V_421 ) , 0 , 0 , 0 , 0 ,
F_282 ( & V_214 -> V_460 ) , V_214 ) ;
}
static int F_286 ( struct V_375 * V_97 , void * V_402 )
{
struct V_377 * V_378 ;
struct V_8 * V_9 = V_402 ;
F_287 ( V_97 , V_461 - 1 ) ;
if ( V_402 == V_401 ) {
F_288 ( V_97 , L_9
L_10
L_11 ) ;
goto V_130;
}
V_378 = V_97 -> V_379 ;
if ( V_9 -> V_86 == V_121 )
F_285 ( V_402 , V_97 , V_378 -> V_387 ) ;
else if ( V_9 -> V_86 == V_122 )
F_271 ( V_402 , V_97 , V_378 -> V_387 ) ;
else
F_277 ( V_402 , V_97 , V_378 -> V_387 ) ;
V_130:
F_289 ( V_97 , '\n' ) ;
return 0 ;
}
static int T_12 F_290 ( struct V_7 * V_7 )
{
return F_267 ( V_7 , & V_462 ) ;
}
static void T_13 F_291 ( struct V_7 * V_7 )
{
F_269 ( V_7 , & V_462 ) ;
}
int T_14 F_292 ( void )
{
return F_293 ( & V_463 ) ;
}
void F_294 ( void )
{
F_295 ( & V_463 ) ;
}
static void T_13 F_296 ( struct V_7 * V_7 )
{
int V_464 ;
F_297 (cpu)
F_298 ( * F_299 ( V_7 -> V_17 . F_9 , V_464 ) ) ;
F_300 ( V_7 -> V_17 . F_9 ) ;
}
static int T_12 F_301 ( struct V_7 * V_7 )
{
int V_465 , V_464 , V_466 ;
V_7 -> V_17 . F_9 = F_302 ( struct V_8 * ) ;
if ( ! V_7 -> V_17 . F_9 )
return - V_258 ;
F_297 (cpu) {
struct V_8 * V_9 ;
V_465 = F_303 ( & V_9 , V_467 , V_468 ,
V_61 , V_7 ) ;
if ( V_465 )
goto V_469;
F_304 ( V_9 , V_470 ) ;
* F_299 ( V_7 -> V_17 . F_9 , V_464 ) = V_9 ;
}
V_7 -> V_17 . V_471 = 2 ;
V_7 -> V_17 . V_472 = 1 ;
V_7 -> V_17 . V_473 = V_474 ;
V_7 -> V_17 . V_475 = V_476 ;
V_7 -> V_17 . V_477 = V_478 ;
V_7 -> V_17 . V_479 = V_480 ;
V_7 -> V_17 . V_481 = V_482 ;
V_7 -> V_17 . V_483 = V_484 ;
V_7 -> V_17 . V_485 = V_486 ;
V_7 -> V_17 . V_487 = V_488 ;
V_7 -> V_17 . V_489 = 1 ;
V_7 -> V_17 . V_490 = V_491 ;
V_7 -> V_17 . V_492 = V_493 ;
V_7 -> V_17 . V_494 = V_495 ;
V_7 -> V_17 . V_496 = 0 ;
V_7 -> V_17 . V_497 = V_498 ;
V_7 -> V_17 . V_499 = V_500 ;
V_7 -> V_17 . V_18 = 0 ;
V_466 = V_119 . V_394 + 1 ;
V_7 -> V_17 . V_43 . V_501 = ( V_466 + 1 ) / 2 ;
V_7 -> V_17 . V_43 . V_502 = & V_119 ;
V_7 -> V_17 . V_503 = F_305 ( 128 , V_466 / 256 ) ;
V_7 -> V_17 . V_504 = 1 ;
V_7 -> V_17 . V_505 = 1 ;
V_7 -> V_17 . V_506 = 1 ;
return 0 ;
V_469:
F_296 ( V_7 ) ;
return V_465 ;
}
static void T_13 F_306 ( struct V_507 * V_508 )
{
F_307 ( & V_119 , V_46 ) ;
}
void T_14 F_308 ( void )
{
if ( F_293 ( & V_509 ) )
F_309 ( L_12 ) ;
}
