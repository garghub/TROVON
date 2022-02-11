static T_1 F_1 ( const struct V_1 * V_2 )
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
( ! V_10 || ( V_16 &&
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
F_21 ( V_8 , V_29 -> V_55 ) ;
if ( V_14 -> V_19 . V_22 && V_29 -> V_63 != V_3 ) {
V_14 -> V_19 . V_20 = 0 ;
V_14 -> V_19 . V_22 = 0 ;
if ( F_22 ( ! V_14 -> V_64 ) )
V_14 -> V_17 = 0 ;
}
if ( V_65 . V_66 &&
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 )
F_23 ( V_8 , & V_36 -> V_67 ) ;
V_29 -> V_68 = V_27 -> V_50 ;
F_24 ( V_8 , V_3 ) ;
F_25 ( V_8 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_8 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_14 -> V_19 . V_71 = V_72 ;
F_26 ( V_8 , V_73 ) ;
V_37 = F_27 ( & V_65 , V_8 ) ;
if ( V_37 )
goto V_74;
F_28 ( V_8 ) ;
V_36 = F_29 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_68 , V_8 ) ;
if ( F_16 ( V_36 ) ) {
V_37 = F_17 ( V_36 ) ;
V_36 = NULL ;
goto V_74;
}
V_8 -> V_75 = V_76 ;
F_30 ( V_8 , & V_36 -> V_67 ) ;
if ( ! V_14 -> V_17 && F_22 ( ! V_14 -> V_64 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_63 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_77 = V_14 -> V_17 ^ V_78 ;
V_37 = F_31 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_74;
return 0 ;
V_74:
F_26 ( V_8 , V_79 ) ;
F_20 ( V_36 ) ;
V_8 -> V_80 = 0 ;
V_29 -> V_68 = 0 ;
return V_37 ;
}
void F_32 ( struct V_7 * V_8 )
{
struct V_81 * V_67 ;
struct V_28 * V_29 = F_11 ( V_8 ) ;
T_4 V_82 = F_7 ( V_8 ) -> V_83 ;
V_67 = F_33 ( V_8 , V_82 ) ;
if ( ! V_67 )
return;
if ( V_82 < F_34 ( V_67 ) && F_35 ( V_8 , V_67 ) )
V_8 -> V_84 = V_85 ;
V_82 = F_34 ( V_67 ) ;
if ( V_29 -> V_86 != V_87 &&
F_36 ( V_8 ) &&
F_25 ( V_8 ) -> V_88 > V_82 ) {
F_37 ( V_8 , V_82 ) ;
F_38 ( V_8 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_81 * V_67 = F_40 ( V_8 , 0 ) ;
if ( V_67 )
V_67 -> V_89 -> V_90 ( V_67 , V_8 , V_2 ) ;
}
void F_41 ( struct V_7 * V_8 , T_4 V_91 , bool abort )
{
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_94 * V_94 = F_19 ( V_8 ) ;
if ( V_91 != F_43 ( V_93 ) -> V_95 ) {
F_44 ( V_94 , V_96 ) ;
} else if ( abort ) {
F_45 ( V_93 -> V_97 , V_93 ) ;
F_46 ( V_93 -> V_97 ) ;
}
F_47 ( V_93 ) ;
}
void F_48 ( struct V_1 * V_98 , T_4 V_99 )
{
const struct V_100 * V_101 = ( const struct V_100 * ) V_98 -> V_102 ;
struct V_103 * V_104 = (struct V_103 * ) ( V_98 -> V_102 + ( V_101 -> V_105 << 2 ) ) ;
struct V_106 * V_107 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_49 ( V_98 ) -> type ;
const int V_108 = F_49 ( V_98 ) -> V_108 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_92 * V_109 ;
T_1 V_91 , V_110 ;
T_1 V_111 ;
int V_37 ;
struct V_94 * V_94 = F_50 ( V_98 -> V_112 ) ;
V_8 = F_51 ( V_94 , & V_113 , V_101 -> V_3 ,
V_104 -> V_5 , V_101 -> V_4 , F_52 ( V_104 -> V_6 ) ,
F_53 ( V_98 ) ) ;
if ( ! V_8 ) {
F_54 ( V_94 , V_114 ) ;
return;
}
if ( V_8 -> V_115 == V_116 ) {
F_55 ( F_56 ( V_8 ) ) ;
return;
}
V_91 = F_57 ( V_104 -> V_91 ) ;
if ( V_8 -> V_115 == V_117 )
return F_41 ( V_8 , V_91 ,
type == V_118 ||
type == V_119 ||
( type == V_120 &&
( V_108 == V_121 ||
V_108 == V_122 ) ) ) ;
F_58 ( V_8 ) ;
if ( F_59 ( V_8 ) ) {
if ( ! ( type == V_120 && V_108 == V_123 ) )
F_44 ( V_94 , V_124 ) ;
}
if ( V_8 -> V_115 == V_79 )
goto V_125;
if ( F_60 ( V_101 -> V_126 < F_11 ( V_8 ) -> V_127 ) ) {
F_44 ( V_94 , V_128 ) ;
goto V_125;
}
V_107 = F_25 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_109 = V_14 -> V_129 ;
V_110 = V_109 ? F_43 ( V_109 ) -> V_95 : V_14 -> V_110 ;
if ( V_8 -> V_115 != V_130 &&
! F_61 ( V_91 , V_110 , V_14 -> V_131 ) ) {
F_44 ( V_94 , V_96 ) ;
goto V_125;
}
switch ( type ) {
case V_132 :
F_39 ( V_98 , V_8 ) ;
goto V_125;
case V_133 :
goto V_125;
case V_118 :
V_37 = V_134 ;
break;
case V_120 :
if ( V_108 > V_135 )
goto V_125;
if ( V_108 == V_123 ) {
if ( V_8 -> V_115 == V_130 )
goto V_125;
V_14 -> V_83 = V_99 ;
if ( ! F_59 ( V_8 ) ) {
F_32 ( V_8 ) ;
} else {
if ( ! F_62 ( V_136 , & V_14 -> V_137 ) )
F_9 ( V_8 ) ;
}
goto V_125;
}
V_37 = V_138 [ V_108 ] . V_139 ;
if ( V_108 != V_121 && V_108 != V_122 )
break;
if ( V_91 != V_14 -> V_110 || ! V_107 -> V_140 ||
! V_107 -> V_141 || V_109 )
break;
if ( F_59 ( V_8 ) )
break;
V_107 -> V_141 -- ;
V_107 -> V_142 = V_14 -> V_143 ? F_63 ( V_14 ) :
V_144 ;
V_107 -> V_142 = F_64 ( V_107 , V_145 ) ;
V_2 = F_65 ( V_8 ) ;
F_66 ( ! V_2 ) ;
V_111 = V_107 -> V_142 -
F_67 ( V_107 -> V_142 ,
V_146 - F_68 ( V_2 ) ) ;
if ( V_111 ) {
F_69 ( V_8 , V_147 ,
V_111 , V_145 ) ;
} else {
F_70 ( V_8 ) ;
}
break;
case V_119 :
V_37 = V_148 ;
break;
default:
goto V_125;
}
switch ( V_8 -> V_115 ) {
case V_73 :
case V_149 :
if ( V_109 && ! V_109 -> V_8 )
break;
if ( ! F_59 ( V_8 ) ) {
V_8 -> V_150 = V_37 ;
V_8 -> V_151 ( V_8 ) ;
F_71 ( V_8 ) ;
} else {
V_8 -> V_84 = V_37 ;
}
goto V_125;
}
V_29 = F_11 ( V_8 ) ;
if ( ! F_59 ( V_8 ) && V_29 -> V_152 ) {
V_8 -> V_150 = V_37 ;
V_8 -> V_151 ( V_8 ) ;
} else {
V_8 -> V_84 = V_37 ;
}
V_125:
F_72 ( V_8 ) ;
F_73 ( V_8 ) ;
}
void F_74 ( struct V_1 * V_2 , T_3 V_4 , T_3 V_3 )
{
struct V_103 * V_104 = F_4 ( V_2 ) ;
if ( V_2 -> V_153 == V_154 ) {
V_104 -> V_155 = ~ F_75 ( V_2 -> V_156 , V_4 , V_3 , 0 ) ;
V_2 -> V_157 = F_76 ( V_2 ) - V_2 -> V_158 ;
V_2 -> V_159 = F_77 ( struct V_103 , V_155 ) ;
} else {
V_104 -> V_155 = F_75 ( V_2 -> V_156 , V_4 , V_3 ,
F_78 ( V_104 ,
V_104 -> V_160 << 2 ,
V_2 -> V_161 ) ) ;
}
}
void F_79 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_11 ( V_8 ) ;
F_74 ( V_2 , V_29 -> V_55 , V_29 -> V_63 ) ;
}
static void F_80 ( const struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_103 * V_104 = F_4 ( V_2 ) ;
struct {
struct V_103 V_104 ;
#ifdef F_81
T_3 V_46 [ ( V_162 >> 2 ) ] ;
#endif
} V_163 ;
struct V_164 V_165 ;
#ifdef F_81
struct V_166 * V_167 = NULL ;
const T_5 * V_168 = NULL ;
unsigned char V_169 [ 16 ] ;
int V_170 ;
struct V_7 * V_171 = NULL ;
#endif
struct V_94 * V_94 ;
if ( V_104 -> V_172 )
return;
if ( ! V_8 && F_82 ( V_2 ) -> V_173 != V_174 )
return;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_104 . V_5 = V_104 -> V_6 ;
V_163 . V_104 . V_6 = V_104 -> V_5 ;
V_163 . V_104 . V_160 = sizeof( struct V_103 ) / 4 ;
V_163 . V_104 . V_172 = 1 ;
if ( V_104 -> V_175 ) {
V_163 . V_104 . V_91 = V_104 -> V_176 ;
} else {
V_163 . V_104 . V_175 = 1 ;
V_163 . V_104 . V_176 = F_83 ( F_57 ( V_104 -> V_91 ) + V_104 -> V_177 + V_104 -> V_178 +
V_2 -> V_156 - ( V_104 -> V_160 << 2 ) ) ;
}
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_104 ) ;
V_94 = V_8 ? F_19 ( V_8 ) : F_50 ( F_84 ( V_2 ) -> V_112 ) ;
#ifdef F_81
F_85 () ;
V_168 = F_86 ( V_104 ) ;
if ( V_8 && F_87 ( V_8 ) ) {
V_167 = F_88 ( V_8 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
} else if ( V_168 ) {
V_171 = F_89 ( V_94 , & V_113 , NULL , 0 ,
F_3 ( V_2 ) -> V_4 ,
V_104 -> V_6 , F_3 ( V_2 ) -> V_3 ,
F_52 ( V_104 -> V_6 ) , F_53 ( V_2 ) ) ;
if ( ! V_171 )
goto V_125;
V_167 = F_88 ( V_171 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_167 )
goto V_125;
V_170 = F_90 ( V_169 , V_167 , NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 )
goto V_125;
}
if ( V_167 ) {
V_163 . V_46 [ 0 ] = F_83 ( ( V_183 << 24 ) |
( V_183 << 16 ) |
( V_184 << 8 ) |
V_185 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_91 ( ( T_5 * ) & V_163 . V_46 [ 1 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_104 ) ;
}
#endif
V_165 . V_161 = F_92 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_186 = F_77 ( struct V_103 , V_155 ) / 2 ;
V_165 . V_187 = ( V_8 && F_93 ( V_8 ) ) ? V_188 : 0 ;
if ( V_8 )
V_165 . V_189 = V_8 -> V_56 ;
F_94 ( F_77 ( struct V_7 , V_56 ) !=
F_77 ( struct V_190 , V_191 ) ) ;
V_165 . V_192 = F_3 ( V_2 ) -> V_192 ;
F_95 () ;
F_96 ( * F_97 ( V_94 -> V_193 . F_7 ) ,
V_2 , & F_98 ( V_2 ) -> V_194 . V_195 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_99 ( V_94 , V_196 ) ;
F_99 ( V_94 , V_197 ) ;
F_100 () ;
#ifdef F_81
V_125:
F_101 () ;
#endif
}
static void F_102 ( struct V_94 * V_94 ,
struct V_1 * V_2 , T_4 V_91 , T_4 V_175 ,
T_4 V_198 , T_4 V_199 , T_4 V_200 , int V_201 ,
struct V_166 * V_167 ,
int V_202 , T_6 V_192 )
{
const struct V_103 * V_104 = F_4 ( V_2 ) ;
struct {
struct V_103 V_104 ;
T_3 V_46 [ ( V_203 >> 2 )
#ifdef F_81
+ ( V_162 >> 2 )
#endif
] ;
} V_163 ;
struct V_164 V_165 ;
memset ( & V_163 . V_104 , 0 , sizeof( struct V_103 ) ) ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_104 ) ;
if ( V_200 ) {
V_163 . V_46 [ 0 ] = F_83 ( ( V_183 << 24 ) | ( V_183 << 16 ) |
( V_204 << 8 ) |
V_205 ) ;
V_163 . V_46 [ 1 ] = F_83 ( V_199 ) ;
V_163 . V_46 [ 2 ] = F_83 ( V_200 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_203 ;
}
V_163 . V_104 . V_5 = V_104 -> V_6 ;
V_163 . V_104 . V_6 = V_104 -> V_5 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
V_163 . V_104 . V_91 = F_83 ( V_91 ) ;
V_163 . V_104 . V_176 = F_83 ( V_175 ) ;
V_163 . V_104 . V_175 = 1 ;
V_163 . V_104 . V_206 = F_103 ( V_198 ) ;
#ifdef F_81
if ( V_167 ) {
int V_207 = ( V_200 ) ? 3 : 0 ;
V_163 . V_46 [ V_207 ++ ] = F_83 ( ( V_183 << 24 ) |
( V_183 << 16 ) |
( V_184 << 8 ) |
V_185 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_104 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_91 ( ( T_5 * ) & V_163 . V_46 [ V_207 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_104 ) ;
}
#endif
V_165 . V_187 = V_202 ;
V_165 . V_161 = F_92 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_186 = F_77 ( struct V_103 , V_155 ) / 2 ;
if ( V_201 )
V_165 . V_189 = V_201 ;
V_165 . V_192 = V_192 ;
F_95 () ;
F_96 ( * F_97 ( V_94 -> V_193 . F_7 ) ,
V_2 , & F_98 ( V_2 ) -> V_194 . V_195 . V_46 ,
F_3 ( V_2 ) -> V_4 , F_3 ( V_2 ) -> V_3 ,
& V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_99 ( V_94 , V_196 ) ;
F_100 () ;
}
static void F_104 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_190 * V_208 = F_56 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_102 ( F_19 ( V_8 ) , V_2 ,
V_12 -> V_18 , V_12 -> V_209 ,
V_12 -> V_210 >> V_208 -> V_211 ,
V_146 + V_12 -> V_212 ,
V_12 -> V_21 ,
V_208 -> V_191 ,
F_105 ( V_12 ) ,
V_208 -> V_213 ? V_188 : 0 ,
V_208 -> V_214
) ;
F_55 ( V_208 ) ;
}
static void F_106 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 )
{
T_4 V_91 = ( V_8 -> V_115 == V_130 ) ? F_43 ( V_93 ) -> V_95 + 1 :
F_7 ( V_8 ) -> V_131 ;
F_102 ( F_19 ( V_8 ) , V_2 , V_91 ,
F_43 ( V_93 ) -> V_215 , V_93 -> V_216 ,
V_146 ,
V_93 -> V_20 ,
0 ,
F_88 ( V_8 , (union V_182 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_107 ( V_93 ) -> V_217 ? V_188 : 0 ,
F_3 ( V_2 ) -> V_192 ) ;
}
static int F_108 ( const struct V_7 * V_8 , struct V_81 * V_67 ,
struct V_218 * V_52 ,
struct V_92 * V_93 ,
struct V_219 * V_220 ,
enum V_221 V_222 )
{
const struct V_223 * V_224 = F_107 ( V_93 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_67 && ( V_67 = F_109 ( V_8 , & V_34 , V_93 ) ) == NULL )
return - 1 ;
V_2 = F_110 ( V_8 , V_67 , V_93 , V_220 , V_222 ) ;
if ( V_2 ) {
F_74 ( V_2 , V_224 -> V_225 , V_224 -> V_226 ) ;
V_37 = F_111 ( V_2 , V_8 , V_224 -> V_225 ,
V_224 -> V_226 ,
V_224 -> V_46 ) ;
V_37 = F_112 ( V_37 ) ;
}
return V_37 ;
}
static void F_113 ( struct V_92 * V_93 )
{
F_114 ( F_107 ( V_93 ) -> V_46 ) ;
}
struct V_166 * F_88 ( const struct V_7 * V_8 ,
const union V_182 * V_227 ,
int V_228 )
{
const struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
unsigned int V_229 = sizeof( struct V_230 ) ;
const struct V_231 * V_232 ;
V_232 = F_115 ( V_14 -> V_233 ,
F_13 ( V_8 ) ) ;
if ( ! V_232 )
return NULL ;
#if F_116 ( V_234 )
if ( V_228 == V_235 )
V_229 = sizeof( struct V_236 ) ;
#endif
F_117 (key, &md5sig->head, node) {
if ( V_167 -> V_228 != V_228 )
continue;
if ( ! memcmp ( & V_167 -> V_227 , V_227 , V_229 ) )
return V_167 ;
}
return NULL ;
}
struct V_166 * F_118 ( const struct V_7 * V_8 ,
const struct V_7 * V_237 )
{
const union V_182 * V_227 ;
V_227 = ( const union V_182 * ) & V_237 -> V_238 ;
return F_88 ( V_8 , V_227 , V_42 ) ;
}
int F_119 ( struct V_7 * V_8 , const union V_182 * V_227 ,
int V_228 , const T_6 * V_239 , T_6 V_240 , T_7 V_241 )
{
struct V_166 * V_167 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_231 * V_232 ;
V_167 = F_88 ( V_8 , V_227 , V_228 ) ;
if ( V_167 ) {
memcpy ( V_167 -> V_167 , V_239 , V_240 ) ;
V_167 -> V_242 = V_240 ;
return 0 ;
}
V_232 = F_12 ( V_14 -> V_233 ,
F_13 ( V_8 ) ) ;
if ( ! V_232 ) {
V_232 = F_120 ( sizeof( * V_232 ) , V_241 ) ;
if ( ! V_232 )
return - V_243 ;
F_121 ( V_8 , V_244 ) ;
F_122 ( & V_232 -> V_158 ) ;
F_123 ( V_14 -> V_233 , V_232 ) ;
}
V_167 = F_124 ( V_8 , sizeof( * V_167 ) , V_241 ) ;
if ( ! V_167 )
return - V_243 ;
if ( ! F_125 () ) {
F_126 ( V_8 , V_167 , sizeof( * V_167 ) ) ;
return - V_243 ;
}
memcpy ( V_167 -> V_167 , V_239 , V_240 ) ;
V_167 -> V_242 = V_240 ;
V_167 -> V_228 = V_228 ;
memcpy ( & V_167 -> V_227 , V_227 ,
( V_228 == V_235 ) ? sizeof( struct V_236 ) :
sizeof( struct V_230 ) ) ;
F_127 ( & V_167 -> V_245 , & V_232 -> V_158 ) ;
return 0 ;
}
int F_128 ( struct V_7 * V_8 , const union V_182 * V_227 , int V_228 )
{
struct V_166 * V_167 ;
V_167 = F_88 ( V_8 , V_227 , V_228 ) ;
if ( ! V_167 )
return - V_246 ;
F_129 ( & V_167 -> V_245 ) ;
F_130 ( sizeof( * V_167 ) , & V_8 -> V_247 ) ;
F_131 ( V_167 , V_248 ) ;
return 0 ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_249 * V_250 ;
struct V_231 * V_232 ;
V_232 = F_12 ( V_14 -> V_233 , 1 ) ;
F_133 (key, n, &md5sig->head, node) {
F_129 ( & V_167 -> V_245 ) ;
F_130 ( sizeof( * V_167 ) , & V_8 -> V_247 ) ;
F_131 ( V_167 , V_248 ) ;
}
}
static int F_134 ( struct V_7 * V_8 , char T_8 * V_251 ,
int V_70 )
{
struct V_252 V_253 ;
struct V_26 * sin = (struct V_26 * ) & V_253 . V_254 ;
if ( V_70 < sizeof( V_253 ) )
return - V_40 ;
if ( F_135 ( & V_253 , V_251 , sizeof( V_253 ) ) )
return - V_255 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_253 . V_256 )
return F_128 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_253 . V_256 > V_257 )
return - V_40 ;
return F_119 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 , V_253 . V_258 , V_253 . V_256 ,
V_259 ) ;
}
static int F_136 ( struct V_260 * V_261 ,
T_3 V_3 , T_3 V_4 , int V_262 )
{
struct V_263 * V_264 ;
struct V_265 V_266 ;
V_264 = & V_261 -> V_267 . V_54 ;
V_264 -> V_4 = V_4 ;
V_264 -> V_3 = V_3 ;
V_264 -> V_268 = 0 ;
V_264 -> V_269 = V_57 ;
V_264 -> V_156 = F_137 ( V_262 ) ;
F_138 ( & V_266 , V_264 , sizeof( * V_264 ) ) ;
F_139 ( V_261 -> V_270 , & V_266 , NULL , sizeof( * V_264 ) ) ;
return F_140 ( V_261 -> V_270 ) ;
}
static int F_91 ( char * V_271 , const struct V_166 * V_167 ,
T_3 V_3 , T_3 V_4 , const struct V_103 * V_104 )
{
struct V_260 * V_261 ;
struct V_272 * V_93 ;
V_261 = F_141 () ;
if ( ! V_261 )
goto V_273;
V_93 = V_261 -> V_270 ;
if ( F_142 ( V_93 ) )
goto V_274;
if ( F_136 ( V_261 , V_3 , V_4 , V_104 -> V_160 << 2 ) )
goto V_274;
if ( F_143 ( V_261 , V_104 ) )
goto V_274;
if ( F_144 ( V_261 , V_167 ) )
goto V_274;
F_139 ( V_93 , NULL , V_271 , 0 ) ;
if ( F_145 ( V_93 ) )
goto V_274;
F_146 () ;
return 0 ;
V_274:
F_146 () ;
V_273:
memset ( V_271 , 0 , 16 ) ;
return 1 ;
}
int F_90 ( char * V_271 , const struct V_166 * V_167 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_260 * V_261 ;
struct V_272 * V_93 ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_275 ;
V_3 = V_8 -> V_238 ;
} else {
const struct V_100 * V_101 = F_3 ( V_2 ) ;
V_4 = V_101 -> V_4 ;
V_3 = V_101 -> V_3 ;
}
V_261 = F_141 () ;
if ( ! V_261 )
goto V_273;
V_93 = V_261 -> V_270 ;
if ( F_142 ( V_93 ) )
goto V_274;
if ( F_136 ( V_261 , V_3 , V_4 , V_2 -> V_156 ) )
goto V_274;
if ( F_143 ( V_261 , V_104 ) )
goto V_274;
if ( F_147 ( V_261 , V_2 , V_104 -> V_160 << 2 ) )
goto V_274;
if ( F_144 ( V_261 , V_167 ) )
goto V_274;
F_139 ( V_93 , NULL , V_271 , 0 ) ;
if ( F_145 ( V_93 ) )
goto V_274;
F_146 () ;
return 0 ;
V_274:
F_146 () ;
V_273:
memset ( V_271 , 0 , 16 ) ;
return 1 ;
}
static bool F_148 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_81
const T_5 * V_168 = NULL ;
struct V_166 * V_276 ;
const struct V_100 * V_101 = F_3 ( V_2 ) ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
int V_170 ;
unsigned char V_169 [ 16 ] ;
V_276 = F_88 ( V_8 , (union V_182 * ) & V_101 -> V_4 ,
V_42 ) ;
V_168 = F_86 ( V_104 ) ;
if ( ! V_276 && ! V_168 )
return false ;
if ( V_276 && ! V_168 ) {
F_149 ( F_19 ( V_8 ) , V_277 ) ;
return true ;
}
if ( ! V_276 && V_168 ) {
F_149 ( F_19 ( V_8 ) , V_278 ) ;
return true ;
}
V_170 = F_90 ( V_169 ,
V_276 ,
NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 ) {
F_150 ( L_1 ,
& V_101 -> V_4 , F_52 ( V_104 -> V_6 ) ,
& V_101 -> V_3 , F_52 ( V_104 -> V_5 ) ,
V_170 ? L_2
: L_3 ) ;
return true ;
}
return false ;
#endif
return false ;
}
static void F_151 ( struct V_92 * V_93 ,
const struct V_7 * V_279 ,
struct V_1 * V_2 )
{
struct V_223 * V_224 = F_107 ( V_93 ) ;
F_21 ( F_152 ( V_93 ) , F_3 ( V_2 ) -> V_3 ) ;
F_24 ( F_152 ( V_93 ) , F_3 ( V_2 ) -> V_4 ) ;
V_224 -> V_217 = F_11 ( V_279 ) -> V_280 ;
V_224 -> V_46 = F_153 ( V_2 ) ;
}
static struct V_81 * F_154 ( const struct V_7 * V_8 ,
struct V_218 * V_52 ,
const struct V_92 * V_93 ,
bool * V_281 )
{
struct V_81 * V_67 = F_109 ( V_8 , & V_52 -> V_53 . V_54 , V_93 ) ;
if ( V_281 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_107 ( V_93 ) -> V_226 )
* V_281 = true ;
else
* V_281 = false ;
}
return V_67 ;
}
int F_155 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_82 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_282;
return F_156 ( & V_283 ,
& V_284 , V_8 , V_2 ) ;
V_282:
F_46 ( V_8 ) ;
return 0 ;
}
struct V_7 * F_157 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_81 * V_67 ,
struct V_92 * V_285 ,
bool * V_286 )
{
struct V_223 * V_224 ;
struct V_28 * V_287 ;
struct V_13 * V_288 ;
struct V_7 * V_289 ;
#ifdef F_81
struct V_166 * V_167 ;
#endif
struct V_38 * V_39 ;
if ( F_158 ( V_8 ) )
goto V_290;
V_289 = F_159 ( V_8 , V_93 , V_2 ) ;
if ( ! V_289 )
goto V_291;
V_289 -> V_75 = V_76 ;
F_160 ( V_289 , V_2 ) ;
V_288 = F_7 ( V_289 ) ;
V_287 = F_11 ( V_289 ) ;
V_224 = F_107 ( V_93 ) ;
F_24 ( V_289 , V_224 -> V_226 ) ;
F_21 ( V_289 , V_224 -> V_225 ) ;
V_289 -> V_56 = V_224 -> V_292 ;
V_287 -> V_55 = V_224 -> V_225 ;
V_39 = V_224 -> V_46 ;
F_123 ( V_287 -> V_39 , V_39 ) ;
V_224 -> V_46 = NULL ;
V_287 -> V_293 = F_53 ( V_2 ) ;
V_287 -> V_294 = F_3 ( V_2 ) -> V_126 ;
V_287 -> V_295 = F_3 ( V_2 ) -> V_192 ;
F_25 ( V_289 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_289 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_287 -> V_77 = V_288 -> V_17 ^ V_78 ;
if ( ! V_67 ) {
V_67 = F_161 ( V_8 , V_289 , V_93 ) ;
if ( ! V_67 )
goto V_296;
} else {
}
F_30 ( V_289 , V_67 ) ;
F_162 ( V_289 , V_67 ) ;
F_37 ( V_289 , F_34 ( V_67 ) ) ;
V_288 -> V_297 = F_163 ( V_67 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_298 &&
F_7 ( V_8 ) -> V_19 . V_298 < V_288 -> V_297 )
V_288 -> V_297 = F_7 ( V_8 ) -> V_19 . V_298 ;
F_164 ( V_289 ) ;
#ifdef F_81
V_167 = F_88 ( V_8 , (union V_182 * ) & V_287 -> V_63 ,
V_42 ) ;
if ( V_167 ) {
F_119 ( V_289 , (union V_182 * ) & V_287 -> V_63 ,
V_42 , V_167 -> V_167 , V_167 -> V_242 , V_299 ) ;
F_121 ( V_289 , V_244 ) ;
}
#endif
if ( F_165 ( V_8 , V_289 ) < 0 )
goto V_296;
* V_286 = F_166 ( V_289 , F_152 ( V_285 ) ) ;
if ( * V_286 )
F_167 ( V_288 , V_93 ) ;
return V_289 ;
V_290:
F_149 ( F_19 ( V_8 ) , V_300 ) ;
V_291:
F_168 ( V_67 ) ;
exit:
F_46 ( V_8 ) ;
return NULL ;
V_296:
F_169 ( V_289 ) ;
F_71 ( V_289 ) ;
goto exit;
}
static struct V_7 * F_170 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
#ifdef F_171
const struct V_103 * V_104 = F_4 ( V_2 ) ;
if ( ! V_104 -> V_177 )
V_8 = F_172 ( V_8 , V_2 ) ;
#endif
return V_8 ;
}
int F_173 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_301 ;
if ( V_8 -> V_115 == V_302 ) {
struct V_81 * V_67 = V_8 -> V_303 ;
F_174 ( V_8 , V_2 ) ;
F_175 ( V_8 , V_2 ) ;
if ( V_67 ) {
if ( F_11 ( V_8 ) -> V_304 != V_2 -> V_305 ||
! V_67 -> V_89 -> V_155 ( V_67 , 0 ) ) {
F_168 ( V_67 ) ;
V_8 -> V_303 = NULL ;
}
}
F_176 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_156 ) ;
return 0 ;
}
if ( F_177 ( V_2 ) )
goto V_306;
if ( V_8 -> V_115 == V_130 ) {
struct V_7 * V_307 = F_170 ( V_8 , V_2 ) ;
if ( ! V_307 )
goto V_308;
if ( V_307 != V_8 ) {
F_174 ( V_307 , V_2 ) ;
F_175 ( V_307 , V_2 ) ;
if ( F_178 ( V_8 , V_307 , V_2 ) ) {
V_301 = V_307 ;
goto V_309;
}
return 0 ;
}
} else
F_174 ( V_8 , V_2 ) ;
if ( F_179 ( V_8 , V_2 ) ) {
V_301 = V_8 ;
goto V_309;
}
return 0 ;
V_309:
F_80 ( V_301 , V_2 ) ;
V_308:
F_180 ( V_2 ) ;
return 0 ;
V_306:
F_181 ( F_19 ( V_8 ) , V_310 ) ;
F_181 ( F_19 ( V_8 ) , V_311 ) ;
goto V_308;
}
void F_182 ( struct V_1 * V_2 )
{
const struct V_100 * V_101 ;
const struct V_103 * V_104 ;
struct V_7 * V_8 ;
if ( V_2 -> V_312 != V_313 )
return;
if ( ! F_183 ( V_2 , F_184 ( V_2 ) + sizeof( struct V_103 ) ) )
return;
V_101 = F_3 ( V_2 ) ;
V_104 = F_4 ( V_2 ) ;
if ( V_104 -> V_160 < sizeof( struct V_103 ) / 4 )
return;
V_8 = F_51 ( F_50 ( V_2 -> V_112 ) , & V_113 ,
V_101 -> V_4 , V_104 -> V_6 ,
V_101 -> V_3 , F_52 ( V_104 -> V_5 ) ,
V_2 -> V_305 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_314 = V_315 ;
if ( F_87 ( V_8 ) ) {
struct V_81 * V_67 = F_185 ( V_8 -> V_303 ) ;
if ( V_67 )
V_67 = F_186 ( V_67 , 0 ) ;
if ( V_67 &&
F_11 ( V_8 ) -> V_304 == V_2 -> V_305 )
F_187 ( V_2 , V_67 ) ;
}
}
}
bool F_188 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_316 || ! V_14 -> V_317 . V_318 )
return false ;
if ( V_2 -> V_156 <= F_189 ( V_2 ) &&
F_190 ( & V_14 -> V_317 . V_319 ) == 0 )
return false ;
if ( F_22 ( V_8 -> V_303 ) )
F_191 ( V_2 ) ;
else
F_192 ( V_2 ) ;
F_193 ( & V_14 -> V_317 . V_319 , V_2 ) ;
V_14 -> V_317 . V_320 += V_2 -> V_321 ;
if ( F_190 ( & V_14 -> V_317 . V_319 ) >= 32 ||
V_14 -> V_317 . V_320 + F_194 ( & V_8 -> V_322 ) > V_8 -> V_323 ) {
struct V_1 * V_324 ;
F_66 ( F_59 ( V_8 ) ) ;
F_195 ( F_19 ( V_8 ) , V_325 ,
F_190 ( & V_14 -> V_317 . V_319 ) ) ;
while ( ( V_324 = F_196 ( & V_14 -> V_317 . V_319 ) ) != NULL )
F_197 ( V_8 , V_324 ) ;
V_14 -> V_317 . V_320 = 0 ;
} else if ( F_190 ( & V_14 -> V_317 . V_319 ) == 1 ) {
F_198 ( F_199 ( V_8 ) ,
V_326 | V_327 | V_328 ) ;
if ( ! F_200 ( V_8 ) )
F_69 ( V_8 , V_329 ,
( 3 * F_201 ( V_8 ) ) / 4 ,
V_145 ) ;
}
return true ;
}
int F_202 ( struct V_1 * V_2 )
{
struct V_94 * V_94 = F_50 ( V_2 -> V_112 ) ;
const struct V_100 * V_101 ;
const struct V_103 * V_104 ;
bool V_330 ;
struct V_7 * V_8 ;
int V_331 ;
if ( V_2 -> V_312 != V_313 )
goto V_332;
F_99 ( V_94 , V_333 ) ;
if ( ! F_183 ( V_2 , sizeof( struct V_103 ) ) )
goto V_332;
V_104 = ( const struct V_103 * ) V_2 -> V_102 ;
if ( F_60 ( V_104 -> V_160 < sizeof( struct V_103 ) / 4 ) )
goto V_334;
if ( ! F_183 ( V_2 , V_104 -> V_160 * 4 ) )
goto V_332;
if ( F_203 ( V_2 , V_57 , V_335 ) )
goto V_336;
V_104 = ( const struct V_103 * ) V_2 -> V_102 ;
V_101 = F_3 ( V_2 ) ;
memmove ( & F_98 ( V_2 ) -> V_194 . V_195 , F_204 ( V_2 ) ,
sizeof( struct V_337 ) ) ;
F_205 () ;
F_98 ( V_2 ) -> V_91 = F_57 ( V_104 -> V_91 ) ;
F_98 ( V_2 ) -> V_338 = ( F_98 ( V_2 ) -> V_91 + V_104 -> V_177 + V_104 -> V_178 +
V_2 -> V_156 - V_104 -> V_160 * 4 ) ;
F_98 ( V_2 ) -> V_176 = F_57 ( V_104 -> V_176 ) ;
F_98 ( V_2 ) -> V_339 = F_206 ( V_104 ) ;
F_98 ( V_2 ) -> V_340 = 0 ;
F_98 ( V_2 ) -> V_341 = F_207 ( V_101 ) ;
F_98 ( V_2 ) -> V_342 = 0 ;
V_343:
V_8 = F_208 ( & V_113 , V_2 , F_209 ( V_104 ) , V_104 -> V_6 ,
V_104 -> V_5 , & V_330 ) ;
if ( ! V_8 )
goto V_344;
V_345:
if ( V_8 -> V_115 == V_116 )
goto V_346;
if ( V_8 -> V_115 == V_117 ) {
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_7 * V_307 ;
V_8 = V_93 -> V_97 ;
if ( F_60 ( F_148 ( V_8 , V_2 ) ) ) {
F_47 ( V_93 ) ;
goto V_332;
}
if ( F_60 ( V_8 -> V_115 != V_130 ) ) {
F_210 ( V_8 , V_93 ) ;
goto V_343;
}
F_9 ( V_8 ) ;
V_330 = true ;
V_307 = F_211 ( V_8 , V_2 , V_93 , false ) ;
if ( ! V_307 ) {
F_47 ( V_93 ) ;
goto V_347;
}
if ( V_307 == V_8 ) {
F_47 ( V_93 ) ;
} else if ( F_178 ( V_8 , V_307 , V_2 ) ) {
F_80 ( V_307 , V_2 ) ;
goto V_347;
} else {
F_73 ( V_8 ) ;
return 0 ;
}
}
if ( F_60 ( V_101 -> V_126 < F_11 ( V_8 ) -> V_127 ) ) {
F_44 ( V_94 , V_128 ) ;
goto V_347;
}
if ( ! F_212 ( V_8 , V_348 , V_2 ) )
goto V_347;
if ( F_148 ( V_8 , V_2 ) )
goto V_347;
F_213 ( V_2 ) ;
if ( F_214 ( V_8 , V_2 ) )
goto V_347;
V_2 -> V_112 = NULL ;
if ( V_8 -> V_115 == V_130 ) {
V_331 = F_173 ( V_8 , V_2 ) ;
goto V_349;
}
F_215 ( V_8 ) ;
F_216 ( V_8 ) ;
F_217 ( F_7 ( V_8 ) , V_2 ) ;
V_331 = 0 ;
if ( ! F_59 ( V_8 ) ) {
if ( ! F_188 ( V_8 , V_2 ) )
V_331 = F_173 ( V_8 , V_2 ) ;
} else if ( F_60 ( F_218 ( V_8 , V_2 ,
V_8 -> V_323 + V_8 -> V_350 ) ) ) {
F_72 ( V_8 ) ;
F_44 ( V_94 , V_351 ) ;
goto V_347;
}
F_72 ( V_8 ) ;
V_349:
if ( V_330 )
F_73 ( V_8 ) ;
return V_331 ;
V_344:
if ( ! F_212 ( NULL , V_348 , V_2 ) )
goto V_332;
if ( F_177 ( V_2 ) ) {
V_336:
F_99 ( V_94 , V_310 ) ;
V_334:
F_99 ( V_94 , V_311 ) ;
} else {
F_80 ( NULL , V_2 ) ;
}
V_332:
F_180 ( V_2 ) ;
return 0 ;
V_347:
F_219 ( V_8 , V_2 ) ;
if ( V_330 )
F_73 ( V_8 ) ;
goto V_332;
V_346:
if ( ! F_212 ( NULL , V_348 , V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_332;
}
if ( F_177 ( V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_336;
}
switch ( F_220 ( F_56 ( V_8 ) , V_2 , V_104 ) ) {
case V_352 : {
struct V_7 * V_353 = F_221 ( F_50 ( V_2 -> V_112 ) ,
& V_113 , V_2 ,
F_209 ( V_104 ) ,
V_101 -> V_4 , V_104 -> V_6 ,
V_101 -> V_3 , V_104 -> V_5 ,
F_53 ( V_2 ) ) ;
if ( V_353 ) {
F_222 ( F_56 ( V_8 ) ) ;
V_8 = V_353 ;
V_330 = false ;
goto V_345;
}
}
case V_354 :
F_104 ( V_8 , V_2 ) ;
break;
case V_355 :
F_80 ( V_8 , V_2 ) ;
F_222 ( F_56 ( V_8 ) ) ;
goto V_332;
case V_356 : ;
}
goto V_332;
}
void F_160 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_81 * V_67 = F_84 ( V_2 ) ;
if ( V_67 && F_223 ( V_67 ) ) {
V_8 -> V_303 = V_67 ;
F_11 ( V_8 ) -> V_304 = V_2 -> V_305 ;
}
}
static int F_224 ( struct V_7 * V_8 )
{
struct V_106 * V_107 = F_25 ( V_8 ) ;
F_225 ( V_8 ) ;
V_107 -> V_357 = & V_358 ;
#ifdef F_81
F_7 ( V_8 ) -> V_359 = & V_360 ;
#endif
return 0 ;
}
void F_226 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_227 ( V_8 ) ;
F_228 ( V_8 ) ;
F_229 ( V_8 ) ;
F_230 ( & V_14 -> V_361 ) ;
#ifdef F_81
if ( V_14 -> V_233 ) {
F_132 ( V_8 ) ;
F_131 ( V_14 -> V_233 , V_248 ) ;
V_14 -> V_233 = NULL ;
}
#endif
F_230 ( & V_14 -> V_317 . V_319 ) ;
if ( F_25 ( V_8 ) -> V_362 )
F_231 ( V_8 ) ;
F_66 ( V_14 -> V_129 ) ;
F_232 ( V_14 ) ;
F_233 ( V_14 ) ;
F_95 () ;
F_234 ( V_8 ) ;
F_100 () ;
if ( V_363 && V_8 -> V_364 )
F_235 ( V_8 ) ;
}
static void * F_236 ( struct V_365 * V_91 , void * V_366 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
struct V_94 * V_94 = F_237 ( V_91 ) ;
struct V_370 * V_371 ;
struct V_106 * V_107 ;
struct V_7 * V_8 = V_366 ;
if ( ! V_8 ) {
V_372:
V_371 = & V_113 . V_373 [ V_368 -> V_374 ] ;
F_238 ( & V_371 -> V_375 ) ;
V_8 = F_239 ( & V_371 -> V_158 ) ;
V_368 -> V_207 = 0 ;
goto V_376;
}
V_371 = & V_113 . V_373 [ V_368 -> V_374 ] ;
++ V_368 -> V_377 ;
++ V_368 -> V_207 ;
V_8 = F_240 ( V_8 ) ;
V_376:
F_241 (sk) {
if ( ! F_242 ( F_19 ( V_8 ) , V_94 ) )
continue;
if ( V_8 -> V_378 == V_368 -> V_228 )
return V_8 ;
V_107 = F_25 ( V_8 ) ;
}
F_243 ( & V_371 -> V_375 ) ;
V_368 -> V_207 = 0 ;
if ( ++ V_368 -> V_374 < V_379 )
goto V_372;
return NULL ;
}
static void * F_244 ( struct V_365 * V_91 , T_9 * V_380 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
void * V_381 ;
V_368 -> V_374 = 0 ;
V_368 -> V_207 = 0 ;
V_381 = F_236 ( V_91 , NULL ) ;
while ( V_381 && * V_380 ) {
V_381 = F_236 ( V_91 , V_381 ) ;
-- * V_380 ;
}
return V_381 ;
}
static inline bool F_245 ( const struct V_367 * V_368 )
{
return F_246 ( & V_113 . V_382 [ V_368 -> V_374 ] . V_383 ) ;
}
static void * F_247 ( struct V_365 * V_91 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
struct V_94 * V_94 = F_237 ( V_91 ) ;
void * V_381 = NULL ;
V_368 -> V_207 = 0 ;
for (; V_368 -> V_374 <= V_113 . V_384 ; ++ V_368 -> V_374 ) {
struct V_7 * V_8 ;
struct V_385 * V_245 ;
T_10 * V_375 = F_248 ( & V_113 , V_368 -> V_374 ) ;
if ( F_245 ( V_368 ) )
continue;
F_238 ( V_375 ) ;
F_249 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_378 != V_368 -> V_228 ||
! F_242 ( F_19 ( V_8 ) , V_94 ) ) {
continue;
}
V_381 = V_8 ;
goto V_125;
}
F_243 ( V_375 ) ;
}
V_125:
return V_381 ;
}
static void * F_250 ( struct V_365 * V_91 , void * V_366 )
{
struct V_7 * V_8 = V_366 ;
struct V_385 * V_245 ;
struct V_367 * V_368 = V_91 -> V_369 ;
struct V_94 * V_94 = F_237 ( V_91 ) ;
++ V_368 -> V_377 ;
++ V_368 -> V_207 ;
V_8 = F_251 ( V_8 ) ;
F_252 (sk, node) {
if ( V_8 -> V_378 == V_368 -> V_228 && F_242 ( F_19 ( V_8 ) , V_94 ) )
return V_8 ;
}
F_243 ( F_248 ( & V_113 , V_368 -> V_374 ) ) ;
++ V_368 -> V_374 ;
return F_247 ( V_91 ) ;
}
static void * F_253 ( struct V_365 * V_91 , T_9 V_380 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
void * V_381 ;
V_368 -> V_374 = 0 ;
V_381 = F_247 ( V_91 ) ;
while ( V_381 && V_380 ) {
V_381 = F_250 ( V_91 , V_381 ) ;
-- V_380 ;
}
return V_381 ;
}
static void * F_254 ( struct V_365 * V_91 , T_9 V_380 )
{
void * V_381 ;
struct V_367 * V_368 = V_91 -> V_369 ;
V_368 -> V_386 = V_387 ;
V_381 = F_244 ( V_91 , & V_380 ) ;
if ( ! V_381 ) {
V_368 -> V_386 = V_388 ;
V_381 = F_253 ( V_91 , V_380 ) ;
}
return V_381 ;
}
static void * F_255 ( struct V_365 * V_91 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
int V_207 = V_368 -> V_207 ;
int V_389 = V_368 -> V_377 ;
void * V_381 = NULL ;
switch ( V_368 -> V_386 ) {
case V_387 :
if ( V_368 -> V_374 >= V_379 )
break;
V_368 -> V_386 = V_387 ;
V_381 = F_236 ( V_91 , NULL ) ;
while ( V_207 -- && V_381 )
V_381 = F_236 ( V_91 , V_381 ) ;
if ( V_381 )
break;
V_368 -> V_374 = 0 ;
V_368 -> V_386 = V_388 ;
case V_388 :
if ( V_368 -> V_374 > V_113 . V_384 )
break;
V_381 = F_247 ( V_91 ) ;
while ( V_207 -- && V_381 )
V_381 = F_250 ( V_91 , V_381 ) ;
}
V_368 -> V_377 = V_389 ;
return V_381 ;
}
static void * F_256 ( struct V_365 * V_91 , T_9 * V_380 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
void * V_381 ;
if ( * V_380 && * V_380 == V_368 -> V_390 ) {
V_381 = F_255 ( V_91 ) ;
if ( V_381 )
goto V_125;
}
V_368 -> V_386 = V_387 ;
V_368 -> V_377 = 0 ;
V_368 -> V_374 = 0 ;
V_368 -> V_207 = 0 ;
V_381 = * V_380 ? F_254 ( V_91 , * V_380 - 1 ) : V_391 ;
V_125:
V_368 -> V_390 = * V_380 ;
return V_381 ;
}
static void * F_257 ( struct V_365 * V_91 , void * V_392 , T_9 * V_380 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
void * V_381 = NULL ;
if ( V_392 == V_391 ) {
V_381 = F_254 ( V_91 , 0 ) ;
goto V_125;
}
switch ( V_368 -> V_386 ) {
case V_387 :
V_381 = F_236 ( V_91 , V_392 ) ;
if ( ! V_381 ) {
V_368 -> V_386 = V_388 ;
V_368 -> V_374 = 0 ;
V_368 -> V_207 = 0 ;
V_381 = F_247 ( V_91 ) ;
}
break;
case V_388 :
V_381 = F_250 ( V_91 , V_392 ) ;
break;
}
V_125:
++ * V_380 ;
V_368 -> V_390 = * V_380 ;
return V_381 ;
}
static void F_258 ( struct V_365 * V_91 , void * V_392 )
{
struct V_367 * V_368 = V_91 -> V_369 ;
switch ( V_368 -> V_386 ) {
case V_387 :
if ( V_392 != V_391 )
F_243 ( & V_113 . V_373 [ V_368 -> V_374 ] . V_375 ) ;
break;
case V_388 :
if ( V_392 )
F_243 ( F_248 ( & V_113 , V_368 -> V_374 ) ) ;
break;
}
}
int F_259 ( struct V_393 * V_393 , struct V_394 * V_394 )
{
struct V_395 * V_396 = F_260 ( V_393 ) ;
struct V_367 * V_397 ;
int V_37 ;
V_37 = F_261 ( V_393 , V_394 , & V_396 -> V_398 ,
sizeof( struct V_367 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_397 = ( (struct V_365 * ) V_394 -> V_399 ) -> V_369 ;
V_397 -> V_228 = V_396 -> V_228 ;
V_397 -> V_390 = 0 ;
return 0 ;
}
int F_262 ( struct V_94 * V_94 , struct V_395 * V_396 )
{
int V_381 = 0 ;
struct V_400 * V_401 ;
V_396 -> V_398 . V_402 = F_256 ;
V_396 -> V_398 . V_403 = F_257 ;
V_396 -> V_398 . V_404 = F_258 ;
V_401 = F_263 ( V_396 -> V_405 , V_406 , V_94 -> V_407 ,
V_396 -> V_408 , V_396 ) ;
if ( ! V_401 )
V_381 = - V_243 ;
return V_381 ;
}
void F_264 ( struct V_94 * V_94 , struct V_395 * V_396 )
{
F_265 ( V_396 -> V_405 , V_94 -> V_407 ) ;
}
static void F_266 ( const struct V_92 * V_93 ,
struct V_365 * V_409 , int V_410 )
{
const struct V_223 * V_224 = F_107 ( V_93 ) ;
long V_411 = V_93 -> V_412 . V_413 - V_78 ;
F_267 ( V_409 , L_4
L_5 ,
V_410 ,
V_224 -> V_225 ,
V_224 -> V_414 ,
V_224 -> V_226 ,
F_52 ( V_224 -> V_415 ) ,
V_149 ,
0 , 0 ,
1 ,
F_268 ( V_411 ) ,
V_93 -> V_416 ,
F_269 ( F_270 ( V_409 ) ,
F_271 ( V_93 -> V_97 ) ) ,
0 ,
0 ,
0 ,
V_93 ) ;
}
static void F_272 ( struct V_7 * V_8 , struct V_365 * V_409 , int V_410 )
{
int V_417 ;
unsigned long V_418 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_106 * V_107 = F_25 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
const struct V_419 * V_420 = & V_107 -> V_421 . V_420 ;
T_3 V_5 = V_29 -> V_63 ;
T_3 V_422 = V_29 -> V_423 ;
T_11 V_424 = F_52 ( V_29 -> V_68 ) ;
T_11 V_425 = F_52 ( V_29 -> V_49 ) ;
int V_426 ;
int V_386 ;
if ( V_107 -> V_427 == V_147 ||
V_107 -> V_427 == V_428 ||
V_107 -> V_427 == V_429 ) {
V_417 = 1 ;
V_418 = V_107 -> V_430 ;
} else if ( V_107 -> V_427 == V_431 ) {
V_417 = 4 ;
V_418 = V_107 -> V_430 ;
} else if ( F_273 ( & V_8 -> V_432 ) ) {
V_417 = 2 ;
V_418 = V_8 -> V_432 . V_413 ;
} else {
V_417 = 0 ;
V_418 = V_78 ;
}
V_386 = F_274 ( V_8 ) ;
if ( V_386 == V_130 )
V_426 = V_8 -> V_433 ;
else
V_426 = F_275 ( int , V_14 -> V_215 - V_14 -> V_434 , 0 ) ;
F_267 ( V_409 , L_6
L_7 ,
V_410 , V_422 , V_425 , V_5 , V_424 , V_386 ,
V_14 -> V_17 - V_14 -> V_110 ,
V_426 ,
V_417 ,
F_268 ( V_418 - V_78 ) ,
V_107 -> V_140 ,
F_269 ( F_270 ( V_409 ) , F_271 ( V_8 ) ) ,
V_107 -> V_435 ,
F_276 ( V_8 ) ,
F_194 ( & V_8 -> V_436 ) , V_8 ,
F_277 ( V_107 -> V_142 ) ,
F_277 ( V_107 -> V_437 . V_438 ) ,
( V_107 -> V_437 . V_439 << 1 ) | V_107 -> V_437 . V_440 ,
V_14 -> V_441 ,
V_386 == V_130 ?
V_420 -> V_442 :
( F_278 ( V_14 ) ? - 1 : V_14 -> V_443 ) ) ;
}
static void F_279 ( const struct V_190 * V_208 ,
struct V_365 * V_409 , int V_410 )
{
long V_411 = V_208 -> V_444 . V_413 - V_78 ;
T_3 V_5 , V_422 ;
T_11 V_424 , V_425 ;
V_5 = V_208 -> V_445 ;
V_422 = V_208 -> V_446 ;
V_424 = F_52 ( V_208 -> V_447 ) ;
V_425 = F_52 ( V_208 -> V_448 ) ;
F_267 ( V_409 , L_4
L_8 ,
V_410 , V_422 , V_425 , V_5 , V_424 , V_208 -> V_449 , 0 , 0 ,
3 , F_268 ( V_411 ) , 0 , 0 , 0 , 0 ,
F_194 ( & V_208 -> V_450 ) , V_208 ) ;
}
static int F_280 ( struct V_365 * V_91 , void * V_392 )
{
struct V_367 * V_368 ;
struct V_7 * V_8 = V_392 ;
F_281 ( V_91 , V_451 - 1 ) ;
if ( V_392 == V_391 ) {
F_282 ( V_91 , L_9
L_10
L_11 ) ;
goto V_125;
}
V_368 = V_91 -> V_369 ;
if ( V_8 -> V_115 == V_116 )
F_279 ( V_392 , V_91 , V_368 -> V_377 ) ;
else if ( V_8 -> V_115 == V_117 )
F_266 ( V_392 , V_91 , V_368 -> V_377 ) ;
else
F_272 ( V_392 , V_91 , V_368 -> V_377 ) ;
V_125:
F_283 ( V_91 , '\n' ) ;
return 0 ;
}
static int T_12 F_284 ( struct V_94 * V_94 )
{
return F_262 ( V_94 , & V_452 ) ;
}
static void T_13 F_285 ( struct V_94 * V_94 )
{
F_264 ( V_94 , & V_452 ) ;
}
int T_14 F_286 ( void )
{
return F_287 ( & V_453 ) ;
}
void F_288 ( void )
{
F_289 ( & V_453 ) ;
}
static void T_13 F_290 ( struct V_94 * V_94 )
{
int V_454 ;
F_291 (cpu)
F_292 ( * F_293 ( V_94 -> V_193 . F_7 , V_454 ) ) ;
F_294 ( V_94 -> V_193 . F_7 ) ;
}
static int T_12 F_295 ( struct V_94 * V_94 )
{
int V_455 , V_454 ;
V_94 -> V_193 . F_7 = F_296 ( struct V_7 * ) ;
if ( ! V_94 -> V_193 . F_7 )
return - V_243 ;
F_291 (cpu) {
struct V_7 * V_8 ;
V_455 = F_297 ( & V_8 , V_456 , V_457 ,
V_57 , V_94 ) ;
if ( V_455 )
goto V_458;
F_298 ( V_8 , V_459 ) ;
* F_293 ( V_94 -> V_193 . F_7 , V_454 ) = V_8 ;
}
V_94 -> V_193 . V_460 = 2 ;
V_94 -> V_193 . V_461 = 1 ;
V_94 -> V_193 . V_462 = V_463 ;
V_94 -> V_193 . V_464 = V_465 ;
V_94 -> V_193 . V_466 = V_467 ;
V_94 -> V_193 . V_468 = V_469 ;
V_94 -> V_193 . V_470 = V_471 ;
V_94 -> V_193 . V_472 = V_473 ;
V_94 -> V_193 . V_474 = V_475 ;
V_94 -> V_193 . V_476 = V_477 ;
V_94 -> V_193 . V_478 = 1 ;
V_94 -> V_193 . V_479 = V_480 ;
V_94 -> V_193 . V_481 = V_482 ;
V_94 -> V_193 . V_483 = V_484 ;
V_94 -> V_193 . V_485 = 0 ;
V_94 -> V_193 . V_486 = V_487 ;
V_94 -> V_193 . V_488 = V_489 ;
return 0 ;
V_458:
F_290 ( V_94 ) ;
return V_455 ;
}
static void T_13 F_299 ( struct V_490 * V_491 )
{
F_300 ( & V_113 , & V_65 , V_42 ) ;
}
void T_14 F_301 ( void )
{
F_302 ( & V_113 ) ;
if ( F_287 ( & V_492 ) )
F_303 ( L_12 ) ;
}
