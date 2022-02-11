static T_1 F_1 ( const struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
F_4 ( V_2 ) -> V_5 ,
F_4 ( V_2 ) -> V_6 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 )
{
return F_6 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ) ;
}
int F_7 ( struct V_7 * V_8 , struct V_7 * V_9 , void * V_10 )
{
const struct V_11 * V_12 = F_8 ( V_9 ) ;
struct V_13 * V_14 = F_9 ( V_8 ) ;
if ( V_12 -> V_15 &&
( ! V_10 || ( F_10 ( V_8 ) -> V_16 . V_17 &&
F_11 () - V_12 -> V_15 > 1 ) ) ) {
V_14 -> V_18 = V_12 -> V_19 + 65535 + 2 ;
if ( V_14 -> V_18 == 0 )
V_14 -> V_18 = 1 ;
V_14 -> V_20 . V_21 = V_12 -> V_22 ;
V_14 -> V_20 . V_23 = V_12 -> V_15 ;
F_12 ( V_9 ) ;
return 1 ;
}
return 0 ;
}
int F_13 ( struct V_7 * V_8 , struct V_24 * V_25 , int V_26 )
{
struct V_27 * V_28 = (struct V_27 * ) V_25 ;
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_13 * V_14 = F_9 ( V_8 ) ;
T_2 V_31 , V_32 ;
T_3 V_3 , V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = & F_10 ( V_8 ) -> V_16 . V_42 ;
if ( V_26 < sizeof( struct V_27 ) )
return - V_43 ;
if ( V_28 -> V_44 != V_45 )
return - V_46 ;
V_33 = V_3 = V_28 -> V_47 . V_48 ;
V_40 = F_15 ( V_30 -> V_40 ,
F_16 ( V_8 ) ) ;
if ( V_40 && V_40 -> V_49 . V_50 ) {
if ( ! V_3 )
return - V_43 ;
V_33 = V_40 -> V_49 . V_51 ;
}
V_31 = V_30 -> V_52 ;
V_32 = V_28 -> V_53 ;
V_35 = & V_30 -> V_54 . V_55 . V_56 . V_57 ;
V_37 = F_17 ( V_35 , V_33 , V_30 -> V_58 ,
F_18 ( V_8 ) , V_8 -> V_59 ,
V_60 ,
V_31 , V_32 , V_8 ) ;
if ( F_19 ( V_37 ) ) {
V_38 = F_20 ( V_37 ) ;
if ( V_38 == - V_61 )
F_21 ( F_10 ( V_8 ) , V_62 ) ;
return V_38 ;
}
if ( V_37 -> V_63 & ( V_64 | V_65 ) ) {
F_22 ( V_37 ) ;
return - V_61 ;
}
if ( ! V_40 || ! V_40 -> V_49 . V_50 )
V_3 = V_35 -> V_3 ;
if ( ! V_30 -> V_58 )
V_30 -> V_58 = V_35 -> V_4 ;
F_23 ( V_8 , V_30 -> V_58 ) ;
if ( V_14 -> V_20 . V_23 && V_30 -> V_66 != V_3 ) {
V_14 -> V_20 . V_21 = 0 ;
V_14 -> V_20 . V_23 = 0 ;
if ( F_24 ( ! V_14 -> V_67 ) )
V_14 -> V_18 = 0 ;
}
V_30 -> V_68 = V_28 -> V_53 ;
F_25 ( V_8 , V_3 ) ;
F_26 ( V_8 ) -> V_69 = 0 ;
if ( V_40 )
F_26 ( V_8 ) -> V_69 = V_40 -> V_49 . V_70 ;
V_14 -> V_20 . V_71 = V_72 ;
F_27 ( V_8 , V_73 ) ;
V_38 = F_28 ( V_42 , V_8 ) ;
if ( V_38 )
goto V_74;
F_29 ( V_8 ) ;
V_37 = F_30 ( V_35 , V_37 , V_31 , V_32 ,
V_30 -> V_52 , V_30 -> V_68 , V_8 ) ;
if ( F_19 ( V_37 ) ) {
V_38 = F_20 ( V_37 ) ;
V_37 = NULL ;
goto V_74;
}
V_8 -> V_75 = V_76 ;
F_31 ( V_8 , & V_37 -> V_77 ) ;
V_37 = NULL ;
if ( F_24 ( ! V_14 -> V_67 ) ) {
if ( ! V_14 -> V_18 )
V_14 -> V_18 = F_2 ( V_30 -> V_58 ,
V_30 -> V_66 ,
V_30 -> V_52 ,
V_28 -> V_53 ) ;
V_14 -> V_78 = F_6 ( V_30 -> V_58 ,
V_30 -> V_66 ) ;
}
V_30 -> V_79 = V_14 -> V_18 ^ V_80 ;
if ( F_32 ( V_8 , & V_38 ) )
return V_38 ;
if ( V_38 )
goto V_74;
V_38 = F_33 ( V_8 ) ;
if ( V_38 )
goto V_74;
return 0 ;
V_74:
F_27 ( V_8 , V_81 ) ;
F_22 ( V_37 ) ;
V_8 -> V_82 = 0 ;
V_30 -> V_68 = 0 ;
return V_38 ;
}
void F_34 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = F_14 ( V_8 ) ;
struct V_83 * V_77 ;
T_1 V_84 ;
if ( ( 1 << V_8 -> V_85 ) & ( V_86 | V_87 ) )
return;
V_84 = F_9 ( V_8 ) -> V_88 ;
V_77 = F_35 ( V_8 , V_84 ) ;
if ( ! V_77 )
return;
if ( V_84 < F_36 ( V_77 ) && F_37 ( V_8 , V_77 ) )
V_8 -> V_89 = V_90 ;
V_84 = F_36 ( V_77 ) ;
if ( V_30 -> V_91 != V_92 &&
F_38 ( V_8 ) &&
F_26 ( V_8 ) -> V_93 > V_84 ) {
F_39 ( V_8 , V_84 ) ;
F_40 ( V_8 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_83 * V_77 = F_42 ( V_8 , 0 ) ;
if ( V_77 )
V_77 -> V_94 -> V_95 ( V_77 , V_8 , V_2 ) ;
}
void F_43 ( struct V_7 * V_8 , T_1 V_96 , bool abort )
{
struct V_97 * V_98 = F_44 ( V_8 ) ;
struct V_99 * V_99 = F_10 ( V_8 ) ;
if ( V_96 != F_45 ( V_98 ) -> V_100 ) {
F_46 ( V_99 , V_101 ) ;
} else if ( abort ) {
F_47 ( V_98 -> V_102 , V_98 ) ;
F_48 ( V_98 -> V_102 ) ;
}
F_49 ( V_98 ) ;
}
void F_50 ( struct V_1 * V_103 , T_1 V_104 )
{
const struct V_105 * V_106 = ( const struct V_105 * ) V_103 -> V_107 ;
struct V_108 * V_109 = (struct V_108 * ) ( V_103 -> V_107 + ( V_106 -> V_110 << 2 ) ) ;
struct V_111 * V_112 ;
struct V_13 * V_14 ;
struct V_29 * V_30 ;
const int type = F_51 ( V_103 ) -> type ;
const int V_113 = F_51 ( V_103 ) -> V_113 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_97 * V_114 ;
T_4 V_96 , V_115 ;
T_4 V_116 ;
int V_38 ;
struct V_99 * V_99 = F_52 ( V_103 -> V_117 ) ;
V_8 = F_53 ( V_99 , & V_118 , V_106 -> V_3 ,
V_109 -> V_5 , V_106 -> V_4 , F_54 ( V_109 -> V_6 ) ,
F_55 ( V_103 ) ) ;
if ( ! V_8 ) {
F_56 ( V_99 , V_119 ) ;
return;
}
if ( V_8 -> V_85 == V_120 ) {
F_57 ( F_58 ( V_8 ) ) ;
return;
}
V_96 = F_59 ( V_109 -> V_96 ) ;
if ( V_8 -> V_85 == V_121 )
return F_43 ( V_8 , V_96 ,
type == V_122 ||
type == V_123 ||
( type == V_124 &&
( V_113 == V_125 ||
V_113 == V_126 ) ) ) ;
F_60 ( V_8 ) ;
if ( F_61 ( V_8 ) ) {
if ( ! ( type == V_124 && V_113 == V_127 ) )
F_46 ( V_99 , V_128 ) ;
}
if ( V_8 -> V_85 == V_81 )
goto V_129;
if ( F_62 ( V_106 -> V_130 < F_14 ( V_8 ) -> V_131 ) ) {
F_46 ( V_99 , V_132 ) ;
goto V_129;
}
V_112 = F_26 ( V_8 ) ;
V_14 = F_9 ( V_8 ) ;
V_114 = V_14 -> V_133 ;
V_115 = V_114 ? F_45 ( V_114 ) -> V_100 : V_14 -> V_115 ;
if ( V_8 -> V_85 != V_134 &&
! F_63 ( V_96 , V_115 , V_14 -> V_135 ) ) {
F_46 ( V_99 , V_101 ) ;
goto V_129;
}
switch ( type ) {
case V_136 :
if ( ! F_61 ( V_8 ) )
F_41 ( V_103 , V_8 ) ;
goto V_129;
case V_137 :
goto V_129;
case V_122 :
V_38 = V_138 ;
break;
case V_124 :
if ( V_113 > V_139 )
goto V_129;
if ( V_113 == V_127 ) {
if ( V_8 -> V_85 == V_134 )
goto V_129;
V_14 -> V_88 = V_104 ;
if ( ! F_61 ( V_8 ) ) {
F_34 ( V_8 ) ;
} else {
if ( ! F_64 ( V_140 , & V_8 -> V_141 ) )
F_12 ( V_8 ) ;
}
goto V_129;
}
V_38 = V_142 [ V_113 ] . V_143 ;
if ( V_113 != V_125 && V_113 != V_126 )
break;
if ( V_96 != V_14 -> V_115 || ! V_112 -> V_144 ||
! V_112 -> V_145 || V_114 )
break;
if ( F_61 ( V_8 ) )
break;
V_112 -> V_145 -- ;
V_112 -> V_146 = V_14 -> V_147 ? F_65 ( V_14 ) :
V_148 ;
V_112 -> V_146 = F_66 ( V_112 , V_149 ) ;
V_2 = F_67 ( V_8 ) ;
F_68 ( ! V_2 ) ;
V_116 = V_112 -> V_146 -
F_69 ( V_112 -> V_146 ,
V_150 - F_70 ( V_2 ) ) ;
if ( V_116 ) {
F_71 ( V_8 , V_151 ,
V_116 , V_149 ) ;
} else {
F_72 ( V_8 ) ;
}
break;
case V_123 :
V_38 = V_152 ;
break;
default:
goto V_129;
}
switch ( V_8 -> V_85 ) {
case V_73 :
case V_153 :
if ( V_114 && ! V_114 -> V_8 )
break;
if ( ! F_61 ( V_8 ) ) {
V_8 -> V_154 = V_38 ;
V_8 -> V_155 ( V_8 ) ;
F_73 ( V_8 ) ;
} else {
V_8 -> V_89 = V_38 ;
}
goto V_129;
}
V_30 = F_14 ( V_8 ) ;
if ( ! F_61 ( V_8 ) && V_30 -> V_156 ) {
V_8 -> V_154 = V_38 ;
V_8 -> V_155 ( V_8 ) ;
} else {
V_8 -> V_89 = V_38 ;
}
V_129:
F_74 ( V_8 ) ;
F_75 ( V_8 ) ;
}
void F_76 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_108 * V_109 = F_4 ( V_2 ) ;
if ( V_2 -> V_157 == V_158 ) {
V_109 -> V_159 = ~ F_77 ( V_2 -> V_160 , V_4 , V_3 , 0 ) ;
V_2 -> V_161 = F_78 ( V_2 ) - V_2 -> V_162 ;
V_2 -> V_163 = F_79 ( struct V_108 , V_159 ) ;
} else {
V_109 -> V_159 = F_77 ( V_2 -> V_160 , V_4 , V_3 ,
F_80 ( V_109 ,
V_109 -> V_164 << 2 ,
V_2 -> V_165 ) ) ;
}
}
void F_81 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_29 * V_30 = F_14 ( V_8 ) ;
F_76 ( V_2 , V_30 -> V_58 , V_30 -> V_66 ) ;
}
static void F_82 ( const struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_108 * V_109 = F_4 ( V_2 ) ;
struct {
struct V_108 V_109 ;
#ifdef F_83
T_3 V_49 [ ( V_166 >> 2 ) ] ;
#endif
} V_167 ;
struct V_168 V_169 ;
#ifdef F_83
struct V_170 * V_171 = NULL ;
const T_5 * V_172 = NULL ;
unsigned char V_173 [ 16 ] ;
int V_174 ;
struct V_7 * V_175 = NULL ;
#endif
struct V_99 * V_99 ;
if ( V_109 -> V_176 )
return;
if ( ! V_8 && F_84 ( V_2 ) -> V_177 != V_178 )
return;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_109 . V_5 = V_109 -> V_6 ;
V_167 . V_109 . V_6 = V_109 -> V_5 ;
V_167 . V_109 . V_164 = sizeof( struct V_108 ) / 4 ;
V_167 . V_109 . V_176 = 1 ;
if ( V_109 -> V_179 ) {
V_167 . V_109 . V_96 = V_109 -> V_180 ;
} else {
V_167 . V_109 . V_179 = 1 ;
V_167 . V_109 . V_180 = F_85 ( F_59 ( V_109 -> V_96 ) + V_109 -> V_181 + V_109 -> V_182 +
V_2 -> V_160 - ( V_109 -> V_164 << 2 ) ) ;
}
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_183 [ 0 ] . V_184 = ( unsigned char * ) & V_167 ;
V_169 . V_183 [ 0 ] . V_185 = sizeof( V_167 . V_109 ) ;
V_99 = V_8 ? F_10 ( V_8 ) : F_52 ( F_86 ( V_2 ) -> V_117 ) ;
#ifdef F_83
F_87 () ;
V_172 = F_88 ( V_109 ) ;
if ( V_8 && F_89 ( V_8 ) ) {
V_171 = F_90 ( V_8 , (union V_186 * )
& F_3 ( V_2 ) -> V_4 , V_45 ) ;
} else if ( V_172 ) {
V_175 = F_91 ( V_99 , & V_118 , NULL , 0 ,
F_3 ( V_2 ) -> V_4 ,
V_109 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_54 ( V_109 -> V_6 ) , F_55 ( V_2 ) ) ;
if ( ! V_175 )
goto V_129;
V_171 = F_90 ( V_175 , (union V_186 * )
& F_3 ( V_2 ) -> V_4 , V_45 ) ;
if ( ! V_171 )
goto V_129;
V_174 = F_92 ( V_173 , V_171 , NULL , V_2 ) ;
if ( V_174 || memcmp ( V_172 , V_173 , 16 ) != 0 )
goto V_129;
}
if ( V_171 ) {
V_167 . V_49 [ 0 ] = F_85 ( ( V_187 << 24 ) |
( V_187 << 16 ) |
( V_188 << 8 ) |
V_189 ) ;
V_169 . V_183 [ 0 ] . V_185 += V_166 ;
V_167 . V_109 . V_164 = V_169 . V_183 [ 0 ] . V_185 / 4 ;
F_93 ( ( T_5 * ) & V_167 . V_49 [ 1 ] ,
V_171 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 . V_109 ) ;
}
#endif
V_169 . V_165 = F_94 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_169 . V_183 [ 0 ] . V_185 , V_60 , 0 ) ;
V_169 . V_190 = F_79 ( struct V_108 , V_159 ) / 2 ;
V_169 . V_191 = ( V_8 && F_95 ( V_8 ) ) ? V_192 : 0 ;
if ( V_8 )
V_169 . V_193 = V_8 -> V_59 ;
F_96 ( F_79 ( struct V_7 , V_59 ) !=
F_79 ( struct V_194 , V_195 ) ) ;
V_169 . V_196 = F_3 ( V_2 ) -> V_196 ;
V_169 . V_197 = F_97 ( V_99 , V_8 && F_89 ( V_8 ) ? V_8 : NULL ) ;
F_98 () ;
F_99 ( * F_100 ( V_99 -> V_16 . F_9 ) ,
V_2 , & F_101 ( V_2 ) -> V_198 . V_199 . V_49 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_169 , V_169 . V_183 [ 0 ] . V_185 ) ;
F_102 ( V_99 , V_200 ) ;
F_102 ( V_99 , V_201 ) ;
F_103 () ;
#ifdef F_83
V_129:
F_104 () ;
#endif
}
static void F_105 ( const struct V_7 * V_8 ,
struct V_1 * V_2 , T_1 V_96 , T_1 V_179 ,
T_1 V_202 , T_1 V_203 , T_1 V_204 , int V_205 ,
struct V_170 * V_171 ,
int V_206 , T_6 V_196 )
{
const struct V_108 * V_109 = F_4 ( V_2 ) ;
struct {
struct V_108 V_109 ;
T_3 V_49 [ ( V_207 >> 2 )
#ifdef F_83
+ ( V_166 >> 2 )
#endif
] ;
} V_167 ;
struct V_99 * V_99 = F_10 ( V_8 ) ;
struct V_168 V_169 ;
memset ( & V_167 . V_109 , 0 , sizeof( struct V_108 ) ) ;
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
V_169 . V_183 [ 0 ] . V_184 = ( unsigned char * ) & V_167 ;
V_169 . V_183 [ 0 ] . V_185 = sizeof( V_167 . V_109 ) ;
if ( V_204 ) {
V_167 . V_49 [ 0 ] = F_85 ( ( V_187 << 24 ) | ( V_187 << 16 ) |
( V_208 << 8 ) |
V_209 ) ;
V_167 . V_49 [ 1 ] = F_85 ( V_203 ) ;
V_167 . V_49 [ 2 ] = F_85 ( V_204 ) ;
V_169 . V_183 [ 0 ] . V_185 += V_207 ;
}
V_167 . V_109 . V_5 = V_109 -> V_6 ;
V_167 . V_109 . V_6 = V_109 -> V_5 ;
V_167 . V_109 . V_164 = V_169 . V_183 [ 0 ] . V_185 / 4 ;
V_167 . V_109 . V_96 = F_85 ( V_96 ) ;
V_167 . V_109 . V_180 = F_85 ( V_179 ) ;
V_167 . V_109 . V_179 = 1 ;
V_167 . V_109 . V_210 = F_106 ( V_202 ) ;
#ifdef F_83
if ( V_171 ) {
int V_211 = ( V_204 ) ? 3 : 0 ;
V_167 . V_49 [ V_211 ++ ] = F_85 ( ( V_187 << 24 ) |
( V_187 << 16 ) |
( V_188 << 8 ) |
V_189 ) ;
V_169 . V_183 [ 0 ] . V_185 += V_166 ;
V_167 . V_109 . V_164 = V_169 . V_183 [ 0 ] . V_185 / 4 ;
F_93 ( ( T_5 * ) & V_167 . V_49 [ V_211 ] ,
V_171 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_167 . V_109 ) ;
}
#endif
V_169 . V_191 = V_206 ;
V_169 . V_165 = F_94 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_169 . V_183 [ 0 ] . V_185 , V_60 , 0 ) ;
V_169 . V_190 = F_79 ( struct V_108 , V_159 ) / 2 ;
if ( V_205 )
V_169 . V_193 = V_205 ;
V_169 . V_196 = V_196 ;
V_169 . V_197 = F_97 ( V_99 , F_89 ( V_8 ) ? V_8 : NULL ) ;
F_98 () ;
F_99 ( * F_100 ( V_99 -> V_16 . F_9 ) ,
V_2 , & F_101 ( V_2 ) -> V_198 . V_199 . V_49 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_169 , V_169 . V_183 [ 0 ] . V_185 ) ;
F_102 ( V_99 , V_200 ) ;
F_103 () ;
}
static void F_107 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_194 * V_212 = F_58 ( V_8 ) ;
struct V_11 * V_12 = F_8 ( V_8 ) ;
F_105 ( V_8 , V_2 ,
V_12 -> V_19 , V_12 -> V_213 ,
V_12 -> V_214 >> V_212 -> V_215 ,
V_150 + V_12 -> V_216 ,
V_12 -> V_22 ,
V_212 -> V_195 ,
F_108 ( V_12 ) ,
V_212 -> V_217 ? V_192 : 0 ,
V_212 -> V_218
) ;
F_57 ( V_212 ) ;
}
static void F_109 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_97 * V_98 )
{
T_1 V_96 = ( V_8 -> V_85 == V_134 ) ? F_45 ( V_98 ) -> V_100 + 1 :
F_9 ( V_8 ) -> V_135 ;
F_105 ( V_8 , V_2 , V_96 ,
F_45 ( V_98 ) -> V_219 ,
V_98 -> V_220 >> F_110 ( V_98 ) -> V_221 ,
V_150 + F_45 ( V_98 ) -> V_222 ,
V_98 -> V_21 ,
0 ,
F_90 ( V_8 , (union V_186 * ) & F_3 ( V_2 ) -> V_3 ,
V_45 ) ,
F_110 ( V_98 ) -> V_223 ? V_192 : 0 ,
F_3 ( V_2 ) -> V_196 ) ;
}
static int F_111 ( const struct V_7 * V_8 , struct V_83 * V_77 ,
struct V_224 * V_55 ,
struct V_97 * V_98 ,
struct V_225 * V_226 ,
enum V_227 V_228 )
{
const struct V_229 * V_230 = F_110 ( V_98 ) ;
struct V_34 V_35 ;
int V_38 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_77 && ( V_77 = F_112 ( V_8 , & V_35 , V_98 ) ) == NULL )
return - 1 ;
V_2 = F_113 ( V_8 , V_77 , V_98 , V_226 , V_228 ) ;
if ( V_2 ) {
F_76 ( V_2 , V_230 -> V_231 , V_230 -> V_232 ) ;
V_38 = F_114 ( V_2 , V_8 , V_230 -> V_231 ,
V_230 -> V_232 ,
V_230 -> V_49 ) ;
V_38 = F_115 ( V_38 ) ;
}
return V_38 ;
}
static void F_116 ( struct V_97 * V_98 )
{
F_117 ( F_110 ( V_98 ) -> V_49 ) ;
}
struct V_170 * F_90 ( const struct V_7 * V_8 ,
const union V_186 * V_233 ,
int V_234 )
{
const struct V_13 * V_14 = F_9 ( V_8 ) ;
struct V_170 * V_171 ;
unsigned int V_235 = sizeof( struct V_236 ) ;
const struct V_237 * V_238 ;
V_238 = F_118 ( V_14 -> V_239 ,
F_16 ( V_8 ) ) ;
if ( ! V_238 )
return NULL ;
#if F_119 ( V_240 )
if ( V_234 == V_241 )
V_235 = sizeof( struct V_242 ) ;
#endif
F_120 (key, &md5sig->head, node) {
if ( V_171 -> V_234 != V_234 )
continue;
if ( ! memcmp ( & V_171 -> V_233 , V_233 , V_235 ) )
return V_171 ;
}
return NULL ;
}
struct V_170 * F_121 ( const struct V_7 * V_8 ,
const struct V_7 * V_243 )
{
const union V_186 * V_233 ;
V_233 = ( const union V_186 * ) & V_243 -> V_244 ;
return F_90 ( V_8 , V_233 , V_45 ) ;
}
int F_122 ( struct V_7 * V_8 , const union V_186 * V_233 ,
int V_234 , const T_6 * V_245 , T_6 V_246 , T_7 V_247 )
{
struct V_170 * V_171 ;
struct V_13 * V_14 = F_9 ( V_8 ) ;
struct V_237 * V_238 ;
V_171 = F_90 ( V_8 , V_233 , V_234 ) ;
if ( V_171 ) {
memcpy ( V_171 -> V_171 , V_245 , V_246 ) ;
V_171 -> V_248 = V_246 ;
return 0 ;
}
V_238 = F_15 ( V_14 -> V_239 ,
F_16 ( V_8 ) ) ;
if ( ! V_238 ) {
V_238 = F_123 ( sizeof( * V_238 ) , V_247 ) ;
if ( ! V_238 )
return - V_249 ;
F_124 ( V_8 , V_250 ) ;
F_125 ( & V_238 -> V_162 ) ;
F_126 ( V_14 -> V_239 , V_238 ) ;
}
V_171 = F_127 ( V_8 , sizeof( * V_171 ) , V_247 ) ;
if ( ! V_171 )
return - V_249 ;
if ( ! F_128 () ) {
F_129 ( V_8 , V_171 , sizeof( * V_171 ) ) ;
return - V_249 ;
}
memcpy ( V_171 -> V_171 , V_245 , V_246 ) ;
V_171 -> V_248 = V_246 ;
V_171 -> V_234 = V_234 ;
memcpy ( & V_171 -> V_233 , V_233 ,
( V_234 == V_241 ) ? sizeof( struct V_242 ) :
sizeof( struct V_236 ) ) ;
F_130 ( & V_171 -> V_251 , & V_238 -> V_162 ) ;
return 0 ;
}
int F_131 ( struct V_7 * V_8 , const union V_186 * V_233 , int V_234 )
{
struct V_170 * V_171 ;
V_171 = F_90 ( V_8 , V_233 , V_234 ) ;
if ( ! V_171 )
return - V_252 ;
F_132 ( & V_171 -> V_251 ) ;
F_133 ( sizeof( * V_171 ) , & V_8 -> V_253 ) ;
F_134 ( V_171 , V_254 ) ;
return 0 ;
}
static void F_135 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_9 ( V_8 ) ;
struct V_170 * V_171 ;
struct V_255 * V_256 ;
struct V_237 * V_238 ;
V_238 = F_15 ( V_14 -> V_239 , 1 ) ;
F_136 (key, n, &md5sig->head, node) {
F_132 ( & V_171 -> V_251 ) ;
F_133 ( sizeof( * V_171 ) , & V_8 -> V_253 ) ;
F_134 ( V_171 , V_254 ) ;
}
}
static int F_137 ( struct V_7 * V_8 , char T_8 * V_257 ,
int V_70 )
{
struct V_258 V_259 ;
struct V_27 * sin = (struct V_27 * ) & V_259 . V_260 ;
if ( V_70 < sizeof( V_259 ) )
return - V_43 ;
if ( F_138 ( & V_259 , V_257 , sizeof( V_259 ) ) )
return - V_261 ;
if ( sin -> V_44 != V_45 )
return - V_43 ;
if ( ! V_259 . V_262 )
return F_131 ( V_8 , (union V_186 * ) & sin -> V_47 . V_48 ,
V_45 ) ;
if ( V_259 . V_262 > V_263 )
return - V_43 ;
return F_122 ( V_8 , (union V_186 * ) & sin -> V_47 . V_48 ,
V_45 , V_259 . V_264 , V_259 . V_262 ,
V_265 ) ;
}
static int F_139 ( struct V_266 * V_267 ,
T_3 V_3 , T_3 V_4 ,
const struct V_108 * V_109 , int V_268 )
{
struct V_269 * V_270 ;
struct V_271 V_272 ;
struct V_108 * V_273 ;
V_270 = V_267 -> V_274 ;
V_270 -> V_4 = V_4 ;
V_270 -> V_3 = V_3 ;
V_270 -> V_275 = 0 ;
V_270 -> V_276 = V_60 ;
V_270 -> V_160 = F_140 ( V_268 ) ;
V_273 = (struct V_108 * ) ( V_270 + 1 ) ;
memcpy ( V_273 , V_109 , sizeof( * V_109 ) ) ;
V_273 -> V_159 = 0 ;
F_141 ( & V_272 , V_270 , sizeof( * V_270 ) + sizeof( * V_109 ) ) ;
F_142 ( V_267 -> V_277 , & V_272 , NULL ,
sizeof( * V_270 ) + sizeof( * V_109 ) ) ;
return F_143 ( V_267 -> V_277 ) ;
}
static int F_93 ( char * V_278 , const struct V_170 * V_171 ,
T_3 V_3 , T_3 V_4 , const struct V_108 * V_109 )
{
struct V_266 * V_267 ;
struct V_279 * V_98 ;
V_267 = F_144 () ;
if ( ! V_267 )
goto V_280;
V_98 = V_267 -> V_277 ;
if ( F_145 ( V_98 ) )
goto V_281;
if ( F_139 ( V_267 , V_3 , V_4 , V_109 , V_109 -> V_164 << 2 ) )
goto V_281;
if ( F_146 ( V_267 , V_171 ) )
goto V_281;
F_142 ( V_98 , NULL , V_278 , 0 ) ;
if ( F_147 ( V_98 ) )
goto V_281;
F_148 () ;
return 0 ;
V_281:
F_148 () ;
V_280:
memset ( V_278 , 0 , 16 ) ;
return 1 ;
}
int F_92 ( char * V_278 , const struct V_170 * V_171 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_266 * V_267 ;
struct V_279 * V_98 ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_282 ;
V_3 = V_8 -> V_244 ;
} else {
const struct V_105 * V_106 = F_3 ( V_2 ) ;
V_4 = V_106 -> V_4 ;
V_3 = V_106 -> V_3 ;
}
V_267 = F_144 () ;
if ( ! V_267 )
goto V_280;
V_98 = V_267 -> V_277 ;
if ( F_145 ( V_98 ) )
goto V_281;
if ( F_139 ( V_267 , V_3 , V_4 , V_109 , V_2 -> V_160 ) )
goto V_281;
if ( F_149 ( V_267 , V_2 , V_109 -> V_164 << 2 ) )
goto V_281;
if ( F_146 ( V_267 , V_171 ) )
goto V_281;
F_142 ( V_98 , NULL , V_278 , 0 ) ;
if ( F_147 ( V_98 ) )
goto V_281;
F_148 () ;
return 0 ;
V_281:
F_148 () ;
V_280:
memset ( V_278 , 0 , 16 ) ;
return 1 ;
}
static bool F_150 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_83
const T_5 * V_172 = NULL ;
struct V_170 * V_283 ;
const struct V_105 * V_106 = F_3 ( V_2 ) ;
const struct V_108 * V_109 = F_4 ( V_2 ) ;
int V_174 ;
unsigned char V_173 [ 16 ] ;
V_283 = F_90 ( V_8 , (union V_186 * ) & V_106 -> V_4 ,
V_45 ) ;
V_172 = F_88 ( V_109 ) ;
if ( ! V_283 && ! V_172 )
return false ;
if ( V_283 && ! V_172 ) {
F_151 ( F_10 ( V_8 ) , V_284 ) ;
return true ;
}
if ( ! V_283 && V_172 ) {
F_151 ( F_10 ( V_8 ) , V_285 ) ;
return true ;
}
V_174 = F_92 ( V_173 ,
V_283 ,
NULL , V_2 ) ;
if ( V_174 || memcmp ( V_172 , V_173 , 16 ) != 0 ) {
F_151 ( F_10 ( V_8 ) , V_286 ) ;
F_152 ( L_1 ,
& V_106 -> V_4 , F_54 ( V_109 -> V_6 ) ,
& V_106 -> V_3 , F_54 ( V_109 -> V_5 ) ,
V_174 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_153 ( struct V_97 * V_98 ,
const struct V_7 * V_287 ,
struct V_1 * V_2 )
{
struct V_229 * V_230 = F_110 ( V_98 ) ;
F_23 ( F_154 ( V_98 ) , F_3 ( V_2 ) -> V_3 ) ;
F_25 ( F_154 ( V_98 ) , F_3 ( V_2 ) -> V_4 ) ;
V_230 -> V_49 = F_155 ( V_2 ) ;
}
static struct V_83 * F_156 ( const struct V_7 * V_8 ,
struct V_224 * V_55 ,
const struct V_97 * V_98 )
{
return F_112 ( V_8 , & V_55 -> V_56 . V_57 , V_98 ) ;
}
int F_157 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_84 ( V_2 ) -> V_63 & ( V_65 | V_64 ) )
goto V_288;
return F_158 ( & V_289 ,
& V_290 , V_8 , V_2 ) ;
V_288:
F_48 ( V_8 ) ;
return 0 ;
}
struct V_7 * F_159 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_83 * V_77 ,
struct V_97 * V_291 ,
bool * V_292 )
{
struct V_229 * V_230 ;
struct V_29 * V_293 ;
struct V_13 * V_294 ;
struct V_7 * V_295 ;
#ifdef F_83
struct V_170 * V_171 ;
#endif
struct V_39 * V_40 ;
if ( F_160 ( V_8 ) )
goto V_296;
V_295 = F_161 ( V_8 , V_98 , V_2 ) ;
if ( ! V_295 )
goto V_297;
V_295 -> V_75 = V_76 ;
F_162 ( V_295 , V_2 ) ;
V_294 = F_9 ( V_295 ) ;
V_293 = F_14 ( V_295 ) ;
V_230 = F_110 ( V_98 ) ;
F_25 ( V_295 , V_230 -> V_232 ) ;
F_23 ( V_295 , V_230 -> V_231 ) ;
V_295 -> V_59 = V_230 -> V_298 ;
V_293 -> V_58 = V_230 -> V_231 ;
V_40 = V_230 -> V_49 ;
F_126 ( V_293 -> V_40 , V_40 ) ;
V_230 -> V_49 = NULL ;
V_293 -> V_299 = F_55 ( V_2 ) ;
V_293 -> V_300 = F_3 ( V_2 ) -> V_130 ;
V_293 -> V_301 = F_3 ( V_2 ) -> V_196 ;
F_26 ( V_295 ) -> V_69 = 0 ;
if ( V_40 )
F_26 ( V_295 ) -> V_69 = V_40 -> V_49 . V_70 ;
V_293 -> V_79 = V_294 -> V_18 ^ V_80 ;
if ( ! V_77 ) {
V_77 = F_163 ( V_8 , V_295 , V_98 ) ;
if ( ! V_77 )
goto V_302;
} else {
}
F_31 ( V_295 , V_77 ) ;
F_164 ( V_295 , V_77 ) ;
F_39 ( V_295 , F_36 ( V_77 ) ) ;
V_294 -> V_303 = F_165 ( F_9 ( V_8 ) , F_166 ( V_77 ) ) ;
F_167 ( V_295 ) ;
#ifdef F_83
V_171 = F_90 ( V_8 , (union V_186 * ) & V_293 -> V_66 ,
V_45 ) ;
if ( V_171 ) {
F_122 ( V_295 , (union V_186 * ) & V_293 -> V_66 ,
V_45 , V_171 -> V_171 , V_171 -> V_248 , V_304 ) ;
F_124 ( V_295 , V_250 ) ;
}
#endif
if ( F_168 ( V_8 , V_295 ) < 0 )
goto V_302;
* V_292 = F_169 ( V_295 , F_154 ( V_291 ) ) ;
if ( * V_292 )
F_170 ( V_294 , V_98 ) ;
return V_295 ;
V_296:
F_151 ( F_10 ( V_8 ) , V_305 ) ;
V_297:
F_171 ( V_77 ) ;
exit:
F_48 ( V_8 ) ;
return NULL ;
V_302:
F_172 ( V_295 ) ;
F_73 ( V_295 ) ;
goto exit;
}
static struct V_7 * F_173 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
#ifdef F_174
const struct V_108 * V_109 = F_4 ( V_2 ) ;
if ( ! V_109 -> V_181 )
V_8 = F_175 ( V_8 , V_2 ) ;
#endif
return V_8 ;
}
int F_176 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_306 ;
if ( V_8 -> V_85 == V_307 ) {
struct V_83 * V_77 = V_8 -> V_308 ;
F_177 ( V_8 , V_2 ) ;
F_178 ( V_8 , V_2 ) ;
if ( V_77 ) {
if ( F_14 ( V_8 ) -> V_309 != V_2 -> V_310 ||
! V_77 -> V_94 -> V_159 ( V_77 , 0 ) ) {
F_171 ( V_77 ) ;
V_8 -> V_308 = NULL ;
}
}
F_179 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_160 ) ;
return 0 ;
}
if ( F_180 ( V_2 ) )
goto V_311;
if ( V_8 -> V_85 == V_134 ) {
struct V_7 * V_312 = F_173 ( V_8 , V_2 ) ;
if ( ! V_312 )
goto V_313;
if ( V_312 != V_8 ) {
if ( F_181 ( V_8 , V_312 , V_2 ) ) {
V_306 = V_312 ;
goto V_314;
}
return 0 ;
}
} else
F_177 ( V_8 , V_2 ) ;
if ( F_182 ( V_8 , V_2 ) ) {
V_306 = V_8 ;
goto V_314;
}
return 0 ;
V_314:
F_82 ( V_306 , V_2 ) ;
V_313:
F_183 ( V_2 ) ;
return 0 ;
V_311:
F_184 ( F_10 ( V_8 ) , V_315 ) ;
F_184 ( F_10 ( V_8 ) , V_316 ) ;
goto V_313;
}
void F_185 ( struct V_1 * V_2 )
{
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
struct V_7 * V_8 ;
if ( V_2 -> V_317 != V_318 )
return;
if ( ! F_186 ( V_2 , F_187 ( V_2 ) + sizeof( struct V_108 ) ) )
return;
V_106 = F_3 ( V_2 ) ;
V_109 = F_4 ( V_2 ) ;
if ( V_109 -> V_164 < sizeof( struct V_108 ) / 4 )
return;
V_8 = F_53 ( F_52 ( V_2 -> V_117 ) , & V_118 ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , F_54 ( V_109 -> V_5 ) ,
V_2 -> V_310 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_319 = V_320 ;
if ( F_89 ( V_8 ) ) {
struct V_83 * V_77 = F_188 ( V_8 -> V_308 ) ;
if ( V_77 )
V_77 = F_189 ( V_77 , 0 ) ;
if ( V_77 &&
F_14 ( V_8 ) -> V_309 == V_2 -> V_310 )
F_190 ( V_2 , V_77 ) ;
}
}
}
bool F_191 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_9 ( V_8 ) ;
if ( V_321 || ! V_14 -> V_322 . V_323 )
return false ;
if ( V_2 -> V_160 <= F_192 ( V_2 ) &&
F_193 ( & V_14 -> V_322 . V_324 ) == 0 )
return false ;
if ( F_24 ( V_8 -> V_308 ) )
F_194 ( V_2 ) ;
else
F_195 ( V_2 ) ;
F_196 ( & V_14 -> V_322 . V_324 , V_2 ) ;
V_14 -> V_322 . V_325 += V_2 -> V_326 ;
if ( F_193 ( & V_14 -> V_322 . V_324 ) >= 32 ||
V_14 -> V_322 . V_325 + F_197 ( & V_8 -> V_327 ) > V_8 -> V_328 ) {
struct V_1 * V_329 ;
F_68 ( F_61 ( V_8 ) ) ;
F_198 ( F_10 ( V_8 ) , V_330 ,
F_193 ( & V_14 -> V_322 . V_324 ) ) ;
while ( ( V_329 = F_199 ( & V_14 -> V_322 . V_324 ) ) != NULL )
F_200 ( V_8 , V_329 ) ;
V_14 -> V_322 . V_325 = 0 ;
} else if ( F_193 ( & V_14 -> V_322 . V_324 ) == 1 ) {
F_201 ( F_202 ( V_8 ) ,
V_331 | V_332 | V_333 ) ;
if ( ! F_203 ( V_8 ) )
F_71 ( V_8 , V_334 ,
( 3 * F_204 ( V_8 ) ) / 4 ,
V_149 ) ;
}
return true ;
}
bool F_205 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
T_1 V_335 = V_8 -> V_328 + V_8 -> V_336 ;
V_335 += 64 * 1024 ;
F_206 ( V_2 ) ;
if ( F_62 ( F_207 ( V_8 , V_2 , V_335 ) ) ) {
F_74 ( V_8 ) ;
F_46 ( F_10 ( V_8 ) , V_337 ) ;
return true ;
}
return false ;
}
int F_208 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_108 * V_109 = (struct V_108 * ) V_2 -> V_107 ;
unsigned int V_338 = V_2 -> V_160 ;
int V_38 ;
V_38 = F_209 ( V_8 , V_2 , V_109 -> V_164 * 4 ) ;
if ( ! V_38 ) {
V_338 -= V_2 -> V_160 ;
F_101 ( V_2 ) -> V_339 -= V_338 ;
}
return V_38 ;
}
int F_210 ( struct V_1 * V_2 )
{
struct V_99 * V_99 = F_52 ( V_2 -> V_117 ) ;
const struct V_105 * V_106 ;
const struct V_108 * V_109 ;
bool V_340 ;
struct V_7 * V_8 ;
int V_341 ;
if ( V_2 -> V_317 != V_318 )
goto V_342;
F_102 ( V_99 , V_343 ) ;
if ( ! F_186 ( V_2 , sizeof( struct V_108 ) ) )
goto V_342;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
if ( F_62 ( V_109 -> V_164 < sizeof( struct V_108 ) / 4 ) )
goto V_344;
if ( ! F_186 ( V_2 , V_109 -> V_164 * 4 ) )
goto V_342;
if ( F_211 ( V_2 , V_60 , V_345 ) )
goto V_346;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
memmove ( & F_101 ( V_2 ) -> V_198 . V_199 , F_212 ( V_2 ) ,
sizeof( struct V_347 ) ) ;
F_213 () ;
F_101 ( V_2 ) -> V_96 = F_59 ( V_109 -> V_96 ) ;
F_101 ( V_2 ) -> V_339 = ( F_101 ( V_2 ) -> V_96 + V_109 -> V_181 + V_109 -> V_182 +
V_2 -> V_160 - V_109 -> V_164 * 4 ) ;
F_101 ( V_2 ) -> V_180 = F_59 ( V_109 -> V_180 ) ;
F_101 ( V_2 ) -> V_348 = F_214 ( V_109 ) ;
F_101 ( V_2 ) -> V_349 = 0 ;
F_101 ( V_2 ) -> V_350 = F_215 ( V_106 ) ;
F_101 ( V_2 ) -> V_351 = 0 ;
V_352:
V_8 = F_216 ( & V_118 , V_2 , F_217 ( V_109 ) , V_109 -> V_6 ,
V_109 -> V_5 , & V_340 ) ;
if ( ! V_8 )
goto V_353;
V_354:
if ( V_8 -> V_85 == V_120 )
goto V_355;
if ( V_8 -> V_85 == V_121 ) {
struct V_97 * V_98 = F_44 ( V_8 ) ;
struct V_7 * V_312 ;
V_8 = V_98 -> V_102 ;
if ( F_62 ( F_150 ( V_8 , V_2 ) ) ) {
F_218 ( V_8 , V_2 ) ;
F_49 ( V_98 ) ;
goto V_342;
}
if ( F_62 ( V_8 -> V_85 != V_134 ) ) {
F_219 ( V_8 , V_98 ) ;
goto V_352;
}
F_12 ( V_8 ) ;
V_340 = true ;
V_312 = F_220 ( V_8 , V_2 , V_98 , false ) ;
if ( ! V_312 ) {
F_49 ( V_98 ) ;
goto V_356;
}
if ( V_312 == V_8 ) {
F_49 ( V_98 ) ;
} else if ( F_181 ( V_8 , V_312 , V_2 ) ) {
F_82 ( V_312 , V_2 ) ;
goto V_356;
} else {
F_75 ( V_8 ) ;
return 0 ;
}
}
if ( F_62 ( V_106 -> V_130 < F_14 ( V_8 ) -> V_131 ) ) {
F_46 ( V_99 , V_132 ) ;
goto V_356;
}
if ( ! F_221 ( V_8 , V_357 , V_2 ) )
goto V_356;
if ( F_150 ( V_8 , V_2 ) )
goto V_356;
F_222 ( V_2 ) ;
if ( F_208 ( V_8 , V_2 ) )
goto V_356;
V_109 = ( const struct V_108 * ) V_2 -> V_107 ;
V_106 = F_3 ( V_2 ) ;
V_2 -> V_117 = NULL ;
if ( V_8 -> V_85 == V_134 ) {
V_341 = F_176 ( V_8 , V_2 ) ;
goto V_358;
}
F_223 ( V_8 ) ;
F_224 ( V_8 ) ;
F_225 ( F_9 ( V_8 ) , V_2 ) ;
V_341 = 0 ;
if ( ! F_61 ( V_8 ) ) {
if ( ! F_191 ( V_8 , V_2 ) )
V_341 = F_176 ( V_8 , V_2 ) ;
} else if ( F_205 ( V_8 , V_2 ) ) {
goto V_356;
}
F_74 ( V_8 ) ;
V_358:
if ( V_340 )
F_75 ( V_8 ) ;
return V_341 ;
V_353:
if ( ! F_221 ( NULL , V_357 , V_2 ) )
goto V_342;
if ( F_180 ( V_2 ) ) {
V_346:
F_102 ( V_99 , V_315 ) ;
V_344:
F_102 ( V_99 , V_316 ) ;
} else {
F_82 ( NULL , V_2 ) ;
}
V_342:
F_183 ( V_2 ) ;
return 0 ;
V_356:
F_218 ( V_8 , V_2 ) ;
if ( V_340 )
F_75 ( V_8 ) ;
goto V_342;
V_355:
if ( ! F_221 ( NULL , V_357 , V_2 ) ) {
F_57 ( F_58 ( V_8 ) ) ;
goto V_342;
}
if ( F_180 ( V_2 ) ) {
F_57 ( F_58 ( V_8 ) ) ;
goto V_346;
}
switch ( F_226 ( F_58 ( V_8 ) , V_2 , V_109 ) ) {
case V_359 : {
struct V_7 * V_360 = F_227 ( F_52 ( V_2 -> V_117 ) ,
& V_118 , V_2 ,
F_217 ( V_109 ) ,
V_106 -> V_4 , V_109 -> V_6 ,
V_106 -> V_3 , V_109 -> V_5 ,
F_55 ( V_2 ) ) ;
if ( V_360 ) {
F_228 ( F_58 ( V_8 ) ) ;
V_8 = V_360 ;
V_340 = false ;
goto V_354;
}
}
case V_361 :
F_107 ( V_8 , V_2 ) ;
break;
case V_362 :
F_82 ( V_8 , V_2 ) ;
F_228 ( F_58 ( V_8 ) ) ;
goto V_342;
case V_363 : ;
}
goto V_342;
}
void F_162 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_83 * V_77 = F_86 ( V_2 ) ;
if ( V_77 && F_229 ( V_77 ) ) {
V_8 -> V_308 = V_77 ;
F_14 ( V_8 ) -> V_309 = V_2 -> V_310 ;
}
}
static int F_230 ( struct V_7 * V_8 )
{
struct V_111 * V_112 = F_26 ( V_8 ) ;
F_231 ( V_8 ) ;
V_112 -> V_364 = & V_365 ;
#ifdef F_83
F_9 ( V_8 ) -> V_366 = & V_367 ;
#endif
return 0 ;
}
void F_232 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_9 ( V_8 ) ;
F_233 ( V_8 ) ;
F_234 ( V_8 ) ;
F_235 ( V_8 ) ;
F_236 ( V_8 ) ;
F_237 ( & V_14 -> V_368 ) ;
#ifdef F_83
if ( V_14 -> V_239 ) {
F_135 ( V_8 ) ;
F_134 ( V_14 -> V_239 , V_254 ) ;
V_14 -> V_239 = NULL ;
}
#endif
F_238 ( & V_14 -> V_322 . V_324 ) ;
if ( F_26 ( V_8 ) -> V_369 )
F_239 ( V_8 ) ;
F_68 ( V_14 -> V_133 ) ;
F_240 ( V_14 ) ;
F_241 ( V_14 ) ;
F_242 ( V_8 ) ;
}
static void * F_243 ( struct V_370 * V_96 , void * V_371 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
struct V_99 * V_99 = F_244 ( V_96 ) ;
struct V_375 * V_376 ;
struct V_7 * V_8 = V_371 ;
if ( ! V_8 ) {
V_377:
V_376 = & V_118 . V_378 [ V_373 -> V_379 ] ;
F_245 ( & V_376 -> V_380 ) ;
V_8 = F_246 ( & V_376 -> V_162 ) ;
V_373 -> V_211 = 0 ;
goto V_381;
}
V_376 = & V_118 . V_378 [ V_373 -> V_379 ] ;
++ V_373 -> V_382 ;
++ V_373 -> V_211 ;
V_8 = F_247 ( V_8 ) ;
V_381:
F_248 (sk) {
if ( ! F_249 ( F_10 ( V_8 ) , V_99 ) )
continue;
if ( V_8 -> V_383 == V_373 -> V_234 )
return V_8 ;
}
F_250 ( & V_376 -> V_380 ) ;
V_373 -> V_211 = 0 ;
if ( ++ V_373 -> V_379 < V_384 )
goto V_377;
return NULL ;
}
static void * F_251 ( struct V_370 * V_96 , T_9 * V_385 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
void * V_386 ;
V_373 -> V_379 = 0 ;
V_373 -> V_211 = 0 ;
V_386 = F_243 ( V_96 , NULL ) ;
while ( V_386 && * V_385 ) {
V_386 = F_243 ( V_96 , V_386 ) ;
-- * V_385 ;
}
return V_386 ;
}
static inline bool F_252 ( const struct V_372 * V_373 )
{
return F_253 ( & V_118 . V_387 [ V_373 -> V_379 ] . V_388 ) ;
}
static void * F_254 ( struct V_370 * V_96 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
struct V_99 * V_99 = F_244 ( V_96 ) ;
void * V_386 = NULL ;
V_373 -> V_211 = 0 ;
for (; V_373 -> V_379 <= V_118 . V_389 ; ++ V_373 -> V_379 ) {
struct V_7 * V_8 ;
struct V_390 * V_251 ;
T_10 * V_380 = F_255 ( & V_118 , V_373 -> V_379 ) ;
if ( F_252 ( V_373 ) )
continue;
F_256 ( V_380 ) ;
F_257 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_383 != V_373 -> V_234 ||
! F_249 ( F_10 ( V_8 ) , V_99 ) ) {
continue;
}
V_386 = V_8 ;
goto V_129;
}
F_258 ( V_380 ) ;
}
V_129:
return V_386 ;
}
static void * F_259 ( struct V_370 * V_96 , void * V_371 )
{
struct V_7 * V_8 = V_371 ;
struct V_390 * V_251 ;
struct V_372 * V_373 = V_96 -> V_374 ;
struct V_99 * V_99 = F_244 ( V_96 ) ;
++ V_373 -> V_382 ;
++ V_373 -> V_211 ;
V_8 = F_260 ( V_8 ) ;
F_261 (sk, node) {
if ( V_8 -> V_383 == V_373 -> V_234 && F_249 ( F_10 ( V_8 ) , V_99 ) )
return V_8 ;
}
F_258 ( F_255 ( & V_118 , V_373 -> V_379 ) ) ;
++ V_373 -> V_379 ;
return F_254 ( V_96 ) ;
}
static void * F_262 ( struct V_370 * V_96 , T_9 V_385 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
void * V_386 ;
V_373 -> V_379 = 0 ;
V_386 = F_254 ( V_96 ) ;
while ( V_386 && V_385 ) {
V_386 = F_259 ( V_96 , V_386 ) ;
-- V_385 ;
}
return V_386 ;
}
static void * F_263 ( struct V_370 * V_96 , T_9 V_385 )
{
void * V_386 ;
struct V_372 * V_373 = V_96 -> V_374 ;
V_373 -> V_391 = V_392 ;
V_386 = F_251 ( V_96 , & V_385 ) ;
if ( ! V_386 ) {
V_373 -> V_391 = V_393 ;
V_386 = F_262 ( V_96 , V_385 ) ;
}
return V_386 ;
}
static void * F_264 ( struct V_370 * V_96 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
int V_211 = V_373 -> V_211 ;
int V_394 = V_373 -> V_382 ;
void * V_386 = NULL ;
switch ( V_373 -> V_391 ) {
case V_392 :
if ( V_373 -> V_379 >= V_384 )
break;
V_373 -> V_391 = V_392 ;
V_386 = F_243 ( V_96 , NULL ) ;
while ( V_211 -- && V_386 )
V_386 = F_243 ( V_96 , V_386 ) ;
if ( V_386 )
break;
V_373 -> V_379 = 0 ;
V_373 -> V_391 = V_393 ;
case V_393 :
if ( V_373 -> V_379 > V_118 . V_389 )
break;
V_386 = F_254 ( V_96 ) ;
while ( V_211 -- && V_386 )
V_386 = F_259 ( V_96 , V_386 ) ;
}
V_373 -> V_382 = V_394 ;
return V_386 ;
}
static void * F_265 ( struct V_370 * V_96 , T_9 * V_385 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
void * V_386 ;
if ( * V_385 && * V_385 == V_373 -> V_395 ) {
V_386 = F_264 ( V_96 ) ;
if ( V_386 )
goto V_129;
}
V_373 -> V_391 = V_392 ;
V_373 -> V_382 = 0 ;
V_373 -> V_379 = 0 ;
V_373 -> V_211 = 0 ;
V_386 = * V_385 ? F_263 ( V_96 , * V_385 - 1 ) : V_396 ;
V_129:
V_373 -> V_395 = * V_385 ;
return V_386 ;
}
static void * F_266 ( struct V_370 * V_96 , void * V_397 , T_9 * V_385 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
void * V_386 = NULL ;
if ( V_397 == V_396 ) {
V_386 = F_263 ( V_96 , 0 ) ;
goto V_129;
}
switch ( V_373 -> V_391 ) {
case V_392 :
V_386 = F_243 ( V_96 , V_397 ) ;
if ( ! V_386 ) {
V_373 -> V_391 = V_393 ;
V_373 -> V_379 = 0 ;
V_373 -> V_211 = 0 ;
V_386 = F_254 ( V_96 ) ;
}
break;
case V_393 :
V_386 = F_259 ( V_96 , V_397 ) ;
break;
}
V_129:
++ * V_385 ;
V_373 -> V_395 = * V_385 ;
return V_386 ;
}
static void F_267 ( struct V_370 * V_96 , void * V_397 )
{
struct V_372 * V_373 = V_96 -> V_374 ;
switch ( V_373 -> V_391 ) {
case V_392 :
if ( V_397 != V_396 )
F_250 ( & V_118 . V_378 [ V_373 -> V_379 ] . V_380 ) ;
break;
case V_393 :
if ( V_397 )
F_258 ( F_255 ( & V_118 , V_373 -> V_379 ) ) ;
break;
}
}
int F_268 ( struct V_398 * V_398 , struct V_399 * V_399 )
{
struct V_400 * V_401 = F_269 ( V_398 ) ;
struct V_372 * V_402 ;
int V_38 ;
V_38 = F_270 ( V_398 , V_399 , & V_401 -> V_403 ,
sizeof( struct V_372 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_402 = ( (struct V_370 * ) V_399 -> V_404 ) -> V_374 ;
V_402 -> V_234 = V_401 -> V_234 ;
V_402 -> V_395 = 0 ;
return 0 ;
}
int F_271 ( struct V_99 * V_99 , struct V_400 * V_401 )
{
int V_386 = 0 ;
struct V_405 * V_406 ;
V_401 -> V_403 . V_407 = F_265 ;
V_401 -> V_403 . V_408 = F_266 ;
V_401 -> V_403 . V_409 = F_267 ;
V_406 = F_272 ( V_401 -> V_410 , V_411 , V_99 -> V_412 ,
V_401 -> V_413 , V_401 ) ;
if ( ! V_406 )
V_386 = - V_249 ;
return V_386 ;
}
void F_273 ( struct V_99 * V_99 , struct V_400 * V_401 )
{
F_274 ( V_401 -> V_410 , V_99 -> V_412 ) ;
}
static void F_275 ( const struct V_97 * V_98 ,
struct V_370 * V_414 , int V_415 )
{
const struct V_229 * V_230 = F_110 ( V_98 ) ;
long V_416 = V_98 -> V_417 . V_418 - V_80 ;
F_276 ( V_414 , L_4
L_5 ,
V_415 ,
V_230 -> V_231 ,
V_230 -> V_419 ,
V_230 -> V_232 ,
F_54 ( V_230 -> V_420 ) ,
V_153 ,
0 , 0 ,
1 ,
F_277 ( V_416 ) ,
V_98 -> V_421 ,
F_278 ( F_279 ( V_414 ) ,
F_280 ( V_98 -> V_102 ) ) ,
0 ,
0 ,
0 ,
V_98 ) ;
}
static void F_281 ( struct V_7 * V_8 , struct V_370 * V_414 , int V_415 )
{
int V_422 ;
unsigned long V_423 ;
const struct V_13 * V_14 = F_9 ( V_8 ) ;
const struct V_111 * V_112 = F_26 ( V_8 ) ;
const struct V_29 * V_30 = F_14 ( V_8 ) ;
const struct V_424 * V_425 = & V_112 -> V_426 . V_425 ;
T_3 V_5 = V_30 -> V_66 ;
T_3 V_427 = V_30 -> V_428 ;
T_11 V_429 = F_54 ( V_30 -> V_68 ) ;
T_11 V_430 = F_54 ( V_30 -> V_52 ) ;
int V_431 ;
int V_391 ;
if ( V_112 -> V_432 == V_151 ||
V_112 -> V_432 == V_433 ||
V_112 -> V_432 == V_434 ) {
V_422 = 1 ;
V_423 = V_112 -> V_435 ;
} else if ( V_112 -> V_432 == V_436 ) {
V_422 = 4 ;
V_423 = V_112 -> V_435 ;
} else if ( F_282 ( & V_8 -> V_437 ) ) {
V_422 = 2 ;
V_423 = V_8 -> V_437 . V_418 ;
} else {
V_422 = 0 ;
V_423 = V_80 ;
}
V_391 = F_283 ( V_8 ) ;
if ( V_391 == V_134 )
V_431 = V_8 -> V_438 ;
else
V_431 = F_284 ( int , V_14 -> V_219 - V_14 -> V_439 , 0 ) ;
F_276 ( V_414 , L_6
L_7 ,
V_415 , V_427 , V_430 , V_5 , V_429 , V_391 ,
V_14 -> V_18 - V_14 -> V_115 ,
V_431 ,
V_422 ,
F_277 ( V_423 - V_80 ) ,
V_112 -> V_144 ,
F_278 ( F_279 ( V_414 ) , F_280 ( V_8 ) ) ,
V_112 -> V_440 ,
F_285 ( V_8 ) ,
F_197 ( & V_8 -> V_441 ) , V_8 ,
F_286 ( V_112 -> V_146 ) ,
F_286 ( V_112 -> V_442 . V_443 ) ,
( V_112 -> V_442 . V_444 << 1 ) | V_112 -> V_442 . V_445 ,
V_14 -> V_446 ,
V_391 == V_134 ?
V_425 -> V_447 :
( F_287 ( V_14 ) ? - 1 : V_14 -> V_448 ) ) ;
}
static void F_288 ( const struct V_194 * V_212 ,
struct V_370 * V_414 , int V_415 )
{
long V_416 = V_212 -> V_449 . V_418 - V_80 ;
T_3 V_5 , V_427 ;
T_11 V_429 , V_430 ;
V_5 = V_212 -> V_450 ;
V_427 = V_212 -> V_451 ;
V_429 = F_54 ( V_212 -> V_452 ) ;
V_430 = F_54 ( V_212 -> V_453 ) ;
F_276 ( V_414 , L_4
L_8 ,
V_415 , V_427 , V_430 , V_5 , V_429 , V_212 -> V_454 , 0 , 0 ,
3 , F_277 ( V_416 ) , 0 , 0 , 0 , 0 ,
F_197 ( & V_212 -> V_455 ) , V_212 ) ;
}
static int F_289 ( struct V_370 * V_96 , void * V_397 )
{
struct V_372 * V_373 ;
struct V_7 * V_8 = V_397 ;
F_290 ( V_96 , V_456 - 1 ) ;
if ( V_397 == V_396 ) {
F_291 ( V_96 , L_9
L_10
L_11 ) ;
goto V_129;
}
V_373 = V_96 -> V_374 ;
if ( V_8 -> V_85 == V_120 )
F_288 ( V_397 , V_96 , V_373 -> V_382 ) ;
else if ( V_8 -> V_85 == V_121 )
F_275 ( V_397 , V_96 , V_373 -> V_382 ) ;
else
F_281 ( V_397 , V_96 , V_373 -> V_382 ) ;
V_129:
F_292 ( V_96 , '\n' ) ;
return 0 ;
}
static int T_12 F_293 ( struct V_99 * V_99 )
{
return F_271 ( V_99 , & V_457 ) ;
}
static void T_13 F_294 ( struct V_99 * V_99 )
{
F_273 ( V_99 , & V_457 ) ;
}
int T_14 F_295 ( void )
{
return F_296 ( & V_458 ) ;
}
void F_297 ( void )
{
F_298 ( & V_458 ) ;
}
static void T_13 F_299 ( struct V_99 * V_99 )
{
int V_459 ;
F_300 (cpu)
F_301 ( * F_302 ( V_99 -> V_16 . F_9 , V_459 ) ) ;
F_303 ( V_99 -> V_16 . F_9 ) ;
}
static int T_12 F_304 ( struct V_99 * V_99 )
{
int V_460 , V_459 , V_461 ;
V_99 -> V_16 . F_9 = F_305 ( struct V_7 * ) ;
if ( ! V_99 -> V_16 . F_9 )
return - V_249 ;
F_300 (cpu) {
struct V_7 * V_8 ;
V_460 = F_306 ( & V_8 , V_462 , V_463 ,
V_60 , V_99 ) ;
if ( V_460 )
goto V_464;
F_307 ( V_8 , V_465 ) ;
* F_302 ( V_99 -> V_16 . F_9 , V_459 ) = V_8 ;
}
V_99 -> V_16 . V_466 = 2 ;
V_99 -> V_16 . V_467 = 1 ;
V_99 -> V_16 . V_468 = V_469 ;
V_99 -> V_16 . V_470 = V_471 ;
V_99 -> V_16 . V_472 = V_473 ;
V_99 -> V_16 . V_474 = V_475 ;
V_99 -> V_16 . V_476 = V_477 ;
V_99 -> V_16 . V_478 = V_479 ;
V_99 -> V_16 . V_480 = V_481 ;
V_99 -> V_16 . V_482 = V_483 ;
V_99 -> V_16 . V_484 = 1 ;
V_99 -> V_16 . V_485 = V_486 ;
V_99 -> V_16 . V_487 = V_488 ;
V_99 -> V_16 . V_489 = V_490 ;
V_99 -> V_16 . V_491 = 0 ;
V_99 -> V_16 . V_492 = V_493 ;
V_99 -> V_16 . V_494 = V_495 ;
V_99 -> V_16 . V_17 = 0 ;
V_461 = V_118 . V_389 + 1 ;
V_99 -> V_16 . V_42 . V_496 = ( V_461 + 1 ) / 2 ;
V_99 -> V_16 . V_42 . V_497 = & V_118 ;
V_99 -> V_16 . V_498 = F_308 ( 128 , V_461 / 256 ) ;
return 0 ;
V_464:
F_299 ( V_99 ) ;
return V_460 ;
}
static void T_13 F_309 ( struct V_499 * V_500 )
{
F_310 ( & V_118 , V_45 ) ;
}
void T_14 F_311 ( void )
{
if ( F_296 ( & V_501 ) )
F_312 ( L_12 ) ;
}
