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
F_43 ( V_93 ) -> V_215 ,
V_93 -> V_216 >> F_107 ( V_93 ) -> V_217 ,
V_146 ,
V_93 -> V_20 ,
0 ,
F_88 ( V_8 , (union V_182 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_107 ( V_93 ) -> V_218 ? V_188 : 0 ,
F_3 ( V_2 ) -> V_192 ) ;
}
static int F_108 ( const struct V_7 * V_8 , struct V_81 * V_67 ,
struct V_219 * V_52 ,
struct V_92 * V_93 ,
struct V_220 * V_221 ,
enum V_222 V_223 )
{
const struct V_224 * V_225 = F_107 ( V_93 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_67 && ( V_67 = F_109 ( V_8 , & V_34 , V_93 ) ) == NULL )
return - 1 ;
V_2 = F_110 ( V_8 , V_67 , V_93 , V_221 , V_223 ) ;
if ( V_2 ) {
F_74 ( V_2 , V_225 -> V_226 , V_225 -> V_227 ) ;
V_37 = F_111 ( V_2 , V_8 , V_225 -> V_226 ,
V_225 -> V_227 ,
V_225 -> V_46 ) ;
V_37 = F_112 ( V_37 ) ;
}
return V_37 ;
}
static void F_113 ( struct V_92 * V_93 )
{
F_114 ( F_107 ( V_93 ) -> V_46 ) ;
}
struct V_166 * F_88 ( const struct V_7 * V_8 ,
const union V_182 * V_228 ,
int V_229 )
{
const struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
unsigned int V_230 = sizeof( struct V_231 ) ;
const struct V_232 * V_233 ;
V_233 = F_115 ( V_14 -> V_234 ,
F_13 ( V_8 ) ) ;
if ( ! V_233 )
return NULL ;
#if F_116 ( V_235 )
if ( V_229 == V_236 )
V_230 = sizeof( struct V_237 ) ;
#endif
F_117 (key, &md5sig->head, node) {
if ( V_167 -> V_229 != V_229 )
continue;
if ( ! memcmp ( & V_167 -> V_228 , V_228 , V_230 ) )
return V_167 ;
}
return NULL ;
}
struct V_166 * F_118 ( const struct V_7 * V_8 ,
const struct V_7 * V_238 )
{
const union V_182 * V_228 ;
V_228 = ( const union V_182 * ) & V_238 -> V_239 ;
return F_88 ( V_8 , V_228 , V_42 ) ;
}
int F_119 ( struct V_7 * V_8 , const union V_182 * V_228 ,
int V_229 , const T_6 * V_240 , T_6 V_241 , T_7 V_242 )
{
struct V_166 * V_167 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_232 * V_233 ;
V_167 = F_88 ( V_8 , V_228 , V_229 ) ;
if ( V_167 ) {
memcpy ( V_167 -> V_167 , V_240 , V_241 ) ;
V_167 -> V_243 = V_241 ;
return 0 ;
}
V_233 = F_12 ( V_14 -> V_234 ,
F_13 ( V_8 ) ) ;
if ( ! V_233 ) {
V_233 = F_120 ( sizeof( * V_233 ) , V_242 ) ;
if ( ! V_233 )
return - V_244 ;
F_121 ( V_8 , V_245 ) ;
F_122 ( & V_233 -> V_158 ) ;
F_123 ( V_14 -> V_234 , V_233 ) ;
}
V_167 = F_124 ( V_8 , sizeof( * V_167 ) , V_242 ) ;
if ( ! V_167 )
return - V_244 ;
if ( ! F_125 () ) {
F_126 ( V_8 , V_167 , sizeof( * V_167 ) ) ;
return - V_244 ;
}
memcpy ( V_167 -> V_167 , V_240 , V_241 ) ;
V_167 -> V_243 = V_241 ;
V_167 -> V_229 = V_229 ;
memcpy ( & V_167 -> V_228 , V_228 ,
( V_229 == V_236 ) ? sizeof( struct V_237 ) :
sizeof( struct V_231 ) ) ;
F_127 ( & V_167 -> V_246 , & V_233 -> V_158 ) ;
return 0 ;
}
int F_128 ( struct V_7 * V_8 , const union V_182 * V_228 , int V_229 )
{
struct V_166 * V_167 ;
V_167 = F_88 ( V_8 , V_228 , V_229 ) ;
if ( ! V_167 )
return - V_247 ;
F_129 ( & V_167 -> V_246 ) ;
F_130 ( sizeof( * V_167 ) , & V_8 -> V_248 ) ;
F_131 ( V_167 , V_249 ) ;
return 0 ;
}
static void F_132 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_250 * V_251 ;
struct V_232 * V_233 ;
V_233 = F_12 ( V_14 -> V_234 , 1 ) ;
F_133 (key, n, &md5sig->head, node) {
F_129 ( & V_167 -> V_246 ) ;
F_130 ( sizeof( * V_167 ) , & V_8 -> V_248 ) ;
F_131 ( V_167 , V_249 ) ;
}
}
static int F_134 ( struct V_7 * V_8 , char T_8 * V_252 ,
int V_70 )
{
struct V_253 V_254 ;
struct V_26 * sin = (struct V_26 * ) & V_254 . V_255 ;
if ( V_70 < sizeof( V_254 ) )
return - V_40 ;
if ( F_135 ( & V_254 , V_252 , sizeof( V_254 ) ) )
return - V_256 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_254 . V_257 )
return F_128 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_254 . V_257 > V_258 )
return - V_40 ;
return F_119 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 , V_254 . V_259 , V_254 . V_257 ,
V_260 ) ;
}
static int F_136 ( struct V_261 * V_262 ,
T_3 V_3 , T_3 V_4 ,
const struct V_103 * V_104 , int V_263 )
{
struct V_264 * V_265 ;
struct V_266 V_267 ;
struct V_103 * V_268 ;
V_265 = V_262 -> V_269 ;
V_265 -> V_4 = V_4 ;
V_265 -> V_3 = V_3 ;
V_265 -> V_270 = 0 ;
V_265 -> V_271 = V_57 ;
V_265 -> V_156 = F_137 ( V_263 ) ;
V_268 = (struct V_103 * ) ( V_265 + 1 ) ;
memcpy ( V_268 , V_104 , sizeof( * V_104 ) ) ;
V_268 -> V_155 = 0 ;
F_138 ( & V_267 , V_265 , sizeof( * V_265 ) + sizeof( * V_104 ) ) ;
F_139 ( V_262 -> V_272 , & V_267 , NULL ,
sizeof( * V_265 ) + sizeof( * V_104 ) ) ;
return F_140 ( V_262 -> V_272 ) ;
}
static int F_91 ( char * V_273 , const struct V_166 * V_167 ,
T_3 V_3 , T_3 V_4 , const struct V_103 * V_104 )
{
struct V_261 * V_262 ;
struct V_274 * V_93 ;
V_262 = F_141 () ;
if ( ! V_262 )
goto V_275;
V_93 = V_262 -> V_272 ;
if ( F_142 ( V_93 ) )
goto V_276;
if ( F_136 ( V_262 , V_3 , V_4 , V_104 , V_104 -> V_160 << 2 ) )
goto V_276;
if ( F_143 ( V_262 , V_167 ) )
goto V_276;
F_139 ( V_93 , NULL , V_273 , 0 ) ;
if ( F_144 ( V_93 ) )
goto V_276;
F_145 () ;
return 0 ;
V_276:
F_145 () ;
V_275:
memset ( V_273 , 0 , 16 ) ;
return 1 ;
}
int F_90 ( char * V_273 , const struct V_166 * V_167 ,
const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
struct V_261 * V_262 ;
struct V_274 * V_93 ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = V_8 -> V_277 ;
V_3 = V_8 -> V_239 ;
} else {
const struct V_100 * V_101 = F_3 ( V_2 ) ;
V_4 = V_101 -> V_4 ;
V_3 = V_101 -> V_3 ;
}
V_262 = F_141 () ;
if ( ! V_262 )
goto V_275;
V_93 = V_262 -> V_272 ;
if ( F_142 ( V_93 ) )
goto V_276;
if ( F_136 ( V_262 , V_3 , V_4 , V_104 , V_2 -> V_156 ) )
goto V_276;
if ( F_146 ( V_262 , V_2 , V_104 -> V_160 << 2 ) )
goto V_276;
if ( F_143 ( V_262 , V_167 ) )
goto V_276;
F_139 ( V_93 , NULL , V_273 , 0 ) ;
if ( F_144 ( V_93 ) )
goto V_276;
F_145 () ;
return 0 ;
V_276:
F_145 () ;
V_275:
memset ( V_273 , 0 , 16 ) ;
return 1 ;
}
static bool F_147 ( const struct V_7 * V_8 ,
const struct V_1 * V_2 )
{
#ifdef F_81
const T_5 * V_168 = NULL ;
struct V_166 * V_278 ;
const struct V_100 * V_101 = F_3 ( V_2 ) ;
const struct V_103 * V_104 = F_4 ( V_2 ) ;
int V_170 ;
unsigned char V_169 [ 16 ] ;
V_278 = F_88 ( V_8 , (union V_182 * ) & V_101 -> V_4 ,
V_42 ) ;
V_168 = F_86 ( V_104 ) ;
if ( ! V_278 && ! V_168 )
return false ;
if ( V_278 && ! V_168 ) {
F_148 ( F_19 ( V_8 ) , V_279 ) ;
return true ;
}
if ( ! V_278 && V_168 ) {
F_148 ( F_19 ( V_8 ) , V_280 ) ;
return true ;
}
V_170 = F_90 ( V_169 ,
V_278 ,
NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 ) {
F_148 ( F_19 ( V_8 ) , V_281 ) ;
F_149 ( L_1 ,
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
static void F_150 ( struct V_92 * V_93 ,
const struct V_7 * V_282 ,
struct V_1 * V_2 )
{
struct V_224 * V_225 = F_107 ( V_93 ) ;
F_21 ( F_151 ( V_93 ) , F_3 ( V_2 ) -> V_3 ) ;
F_24 ( F_151 ( V_93 ) , F_3 ( V_2 ) -> V_4 ) ;
V_225 -> V_46 = F_152 ( V_2 ) ;
}
static struct V_81 * F_153 ( const struct V_7 * V_8 ,
struct V_219 * V_52 ,
const struct V_92 * V_93 ,
bool * V_283 )
{
struct V_81 * V_67 = F_109 ( V_8 , & V_52 -> V_53 . V_54 , V_93 ) ;
if ( V_283 ) {
if ( V_52 -> V_53 . V_54 . V_3 == F_107 ( V_93 ) -> V_227 )
* V_283 = true ;
else
* V_283 = false ;
}
return V_67 ;
}
int F_154 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
if ( F_82 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_284;
return F_155 ( & V_285 ,
& V_286 , V_8 , V_2 ) ;
V_284:
F_46 ( V_8 ) ;
return 0 ;
}
struct V_7 * F_156 ( const struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_92 * V_93 ,
struct V_81 * V_67 ,
struct V_92 * V_287 ,
bool * V_288 )
{
struct V_224 * V_225 ;
struct V_28 * V_289 ;
struct V_13 * V_290 ;
struct V_7 * V_291 ;
#ifdef F_81
struct V_166 * V_167 ;
#endif
struct V_38 * V_39 ;
if ( F_157 ( V_8 ) )
goto V_292;
V_291 = F_158 ( V_8 , V_93 , V_2 ) ;
if ( ! V_291 )
goto V_293;
V_291 -> V_75 = V_76 ;
F_159 ( V_291 , V_2 ) ;
V_290 = F_7 ( V_291 ) ;
V_289 = F_11 ( V_291 ) ;
V_225 = F_107 ( V_93 ) ;
F_24 ( V_291 , V_225 -> V_227 ) ;
F_21 ( V_291 , V_225 -> V_226 ) ;
V_291 -> V_56 = V_225 -> V_294 ;
V_289 -> V_55 = V_225 -> V_226 ;
V_39 = V_225 -> V_46 ;
F_123 ( V_289 -> V_39 , V_39 ) ;
V_225 -> V_46 = NULL ;
V_289 -> V_295 = F_53 ( V_2 ) ;
V_289 -> V_296 = F_3 ( V_2 ) -> V_126 ;
V_289 -> V_297 = F_3 ( V_2 ) -> V_192 ;
F_25 ( V_291 ) -> V_69 = 0 ;
if ( V_39 )
F_25 ( V_291 ) -> V_69 = V_39 -> V_46 . V_70 ;
V_289 -> V_77 = V_290 -> V_17 ^ V_78 ;
if ( ! V_67 ) {
V_67 = F_160 ( V_8 , V_291 , V_93 ) ;
if ( ! V_67 )
goto V_298;
} else {
}
F_30 ( V_291 , V_67 ) ;
F_161 ( V_291 , V_67 ) ;
F_37 ( V_291 , F_34 ( V_67 ) ) ;
V_290 -> V_299 = F_162 ( V_67 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_300 &&
F_7 ( V_8 ) -> V_19 . V_300 < V_290 -> V_299 )
V_290 -> V_299 = F_7 ( V_8 ) -> V_19 . V_300 ;
F_163 ( V_291 ) ;
#ifdef F_81
V_167 = F_88 ( V_8 , (union V_182 * ) & V_289 -> V_63 ,
V_42 ) ;
if ( V_167 ) {
F_119 ( V_291 , (union V_182 * ) & V_289 -> V_63 ,
V_42 , V_167 -> V_167 , V_167 -> V_243 , V_301 ) ;
F_121 ( V_291 , V_245 ) ;
}
#endif
if ( F_164 ( V_8 , V_291 ) < 0 )
goto V_298;
* V_288 = F_165 ( V_291 , F_151 ( V_287 ) ) ;
if ( * V_288 )
F_166 ( V_290 , V_93 ) ;
return V_291 ;
V_292:
F_148 ( F_19 ( V_8 ) , V_302 ) ;
V_293:
F_167 ( V_67 ) ;
exit:
F_46 ( V_8 ) ;
return NULL ;
V_298:
F_168 ( V_291 ) ;
F_71 ( V_291 ) ;
goto exit;
}
static struct V_7 * F_169 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
#ifdef F_170
const struct V_103 * V_104 = F_4 ( V_2 ) ;
if ( ! V_104 -> V_177 )
V_8 = F_171 ( V_8 , V_2 ) ;
#endif
return V_8 ;
}
int F_172 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_303 ;
if ( V_8 -> V_115 == V_304 ) {
struct V_81 * V_67 = V_8 -> V_305 ;
F_173 ( V_8 , V_2 ) ;
F_174 ( V_8 , V_2 ) ;
if ( V_67 ) {
if ( F_11 ( V_8 ) -> V_306 != V_2 -> V_307 ||
! V_67 -> V_89 -> V_155 ( V_67 , 0 ) ) {
F_167 ( V_67 ) ;
V_8 -> V_305 = NULL ;
}
}
F_175 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_156 ) ;
return 0 ;
}
if ( F_176 ( V_2 ) )
goto V_308;
if ( V_8 -> V_115 == V_130 ) {
struct V_7 * V_309 = F_169 ( V_8 , V_2 ) ;
if ( ! V_309 )
goto V_310;
if ( V_309 != V_8 ) {
F_173 ( V_309 , V_2 ) ;
F_174 ( V_309 , V_2 ) ;
if ( F_177 ( V_8 , V_309 , V_2 ) ) {
V_303 = V_309 ;
goto V_311;
}
return 0 ;
}
} else
F_173 ( V_8 , V_2 ) ;
if ( F_178 ( V_8 , V_2 ) ) {
V_303 = V_8 ;
goto V_311;
}
return 0 ;
V_311:
F_80 ( V_303 , V_2 ) ;
V_310:
F_179 ( V_2 ) ;
return 0 ;
V_308:
F_180 ( F_19 ( V_8 ) , V_312 ) ;
F_180 ( F_19 ( V_8 ) , V_313 ) ;
goto V_310;
}
void F_181 ( struct V_1 * V_2 )
{
const struct V_100 * V_101 ;
const struct V_103 * V_104 ;
struct V_7 * V_8 ;
if ( V_2 -> V_314 != V_315 )
return;
if ( ! F_182 ( V_2 , F_183 ( V_2 ) + sizeof( struct V_103 ) ) )
return;
V_101 = F_3 ( V_2 ) ;
V_104 = F_4 ( V_2 ) ;
if ( V_104 -> V_160 < sizeof( struct V_103 ) / 4 )
return;
V_8 = F_51 ( F_50 ( V_2 -> V_112 ) , & V_113 ,
V_101 -> V_4 , V_104 -> V_6 ,
V_101 -> V_3 , F_52 ( V_104 -> V_5 ) ,
V_2 -> V_307 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_316 = V_317 ;
if ( F_87 ( V_8 ) ) {
struct V_81 * V_67 = F_184 ( V_8 -> V_305 ) ;
if ( V_67 )
V_67 = F_185 ( V_67 , 0 ) ;
if ( V_67 &&
F_11 ( V_8 ) -> V_306 == V_2 -> V_307 )
F_186 ( V_2 , V_67 ) ;
}
}
}
bool F_187 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( V_318 || ! V_14 -> V_319 . V_320 )
return false ;
if ( V_2 -> V_156 <= F_188 ( V_2 ) &&
F_189 ( & V_14 -> V_319 . V_321 ) == 0 )
return false ;
if ( F_22 ( V_8 -> V_305 ) )
F_190 ( V_2 ) ;
else
F_191 ( V_2 ) ;
F_192 ( & V_14 -> V_319 . V_321 , V_2 ) ;
V_14 -> V_319 . V_322 += V_2 -> V_323 ;
if ( F_189 ( & V_14 -> V_319 . V_321 ) >= 32 ||
V_14 -> V_319 . V_322 + F_193 ( & V_8 -> V_324 ) > V_8 -> V_325 ) {
struct V_1 * V_326 ;
F_66 ( F_59 ( V_8 ) ) ;
F_194 ( F_19 ( V_8 ) , V_327 ,
F_189 ( & V_14 -> V_319 . V_321 ) ) ;
while ( ( V_326 = F_195 ( & V_14 -> V_319 . V_321 ) ) != NULL )
F_196 ( V_8 , V_326 ) ;
V_14 -> V_319 . V_322 = 0 ;
} else if ( F_189 ( & V_14 -> V_319 . V_321 ) == 1 ) {
F_197 ( F_198 ( V_8 ) ,
V_328 | V_329 | V_330 ) ;
if ( ! F_199 ( V_8 ) )
F_69 ( V_8 , V_331 ,
( 3 * F_200 ( V_8 ) ) / 4 ,
V_145 ) ;
}
return true ;
}
bool F_201 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
T_4 V_332 = V_8 -> V_325 + V_8 -> V_333 ;
V_332 += 64 * 1024 ;
if ( ! V_2 -> V_334 )
V_2 -> V_323 = F_202 ( F_203 ( V_2 ) ) ;
if ( F_60 ( F_204 ( V_8 , V_2 , V_332 ) ) ) {
F_72 ( V_8 ) ;
F_44 ( F_19 ( V_8 ) , V_335 ) ;
return true ;
}
return false ;
}
int F_205 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_103 * V_104 = (struct V_103 * ) V_2 -> V_102 ;
unsigned int V_336 = V_2 -> V_156 ;
int V_37 ;
V_37 = F_206 ( V_8 , V_2 , V_104 -> V_160 * 4 ) ;
if ( ! V_37 ) {
V_336 -= V_2 -> V_156 ;
F_98 ( V_2 ) -> V_337 -= V_336 ;
}
return V_37 ;
}
int F_207 ( struct V_1 * V_2 )
{
struct V_94 * V_94 = F_50 ( V_2 -> V_112 ) ;
const struct V_100 * V_101 ;
const struct V_103 * V_104 ;
bool V_338 ;
struct V_7 * V_8 ;
int V_339 ;
if ( V_2 -> V_314 != V_315 )
goto V_340;
F_99 ( V_94 , V_341 ) ;
if ( ! F_182 ( V_2 , sizeof( struct V_103 ) ) )
goto V_340;
V_104 = ( const struct V_103 * ) V_2 -> V_102 ;
if ( F_60 ( V_104 -> V_160 < sizeof( struct V_103 ) / 4 ) )
goto V_342;
if ( ! F_182 ( V_2 , V_104 -> V_160 * 4 ) )
goto V_340;
if ( F_208 ( V_2 , V_57 , V_343 ) )
goto V_344;
V_104 = ( const struct V_103 * ) V_2 -> V_102 ;
V_101 = F_3 ( V_2 ) ;
memmove ( & F_98 ( V_2 ) -> V_194 . V_195 , F_209 ( V_2 ) ,
sizeof( struct V_345 ) ) ;
F_210 () ;
F_98 ( V_2 ) -> V_91 = F_57 ( V_104 -> V_91 ) ;
F_98 ( V_2 ) -> V_337 = ( F_98 ( V_2 ) -> V_91 + V_104 -> V_177 + V_104 -> V_178 +
V_2 -> V_156 - V_104 -> V_160 * 4 ) ;
F_98 ( V_2 ) -> V_176 = F_57 ( V_104 -> V_176 ) ;
F_98 ( V_2 ) -> V_346 = F_211 ( V_104 ) ;
F_98 ( V_2 ) -> V_347 = 0 ;
F_98 ( V_2 ) -> V_348 = F_212 ( V_101 ) ;
F_98 ( V_2 ) -> V_349 = 0 ;
V_350:
V_8 = F_213 ( & V_113 , V_2 , F_214 ( V_104 ) , V_104 -> V_6 ,
V_104 -> V_5 , & V_338 ) ;
if ( ! V_8 )
goto V_351;
V_352:
if ( V_8 -> V_115 == V_116 )
goto V_353;
if ( V_8 -> V_115 == V_117 ) {
struct V_92 * V_93 = F_42 ( V_8 ) ;
struct V_7 * V_309 ;
V_8 = V_93 -> V_97 ;
if ( F_60 ( F_147 ( V_8 , V_2 ) ) ) {
F_215 ( V_8 , V_2 ) ;
F_47 ( V_93 ) ;
goto V_340;
}
if ( F_60 ( V_8 -> V_115 != V_130 ) ) {
F_216 ( V_8 , V_93 ) ;
goto V_350;
}
F_9 ( V_8 ) ;
V_338 = true ;
V_309 = F_217 ( V_8 , V_2 , V_93 , false ) ;
if ( ! V_309 ) {
F_47 ( V_93 ) ;
goto V_354;
}
if ( V_309 == V_8 ) {
F_47 ( V_93 ) ;
} else if ( F_177 ( V_8 , V_309 , V_2 ) ) {
F_80 ( V_309 , V_2 ) ;
goto V_354;
} else {
F_73 ( V_8 ) ;
return 0 ;
}
}
if ( F_60 ( V_101 -> V_126 < F_11 ( V_8 ) -> V_127 ) ) {
F_44 ( V_94 , V_128 ) ;
goto V_354;
}
if ( ! F_218 ( V_8 , V_355 , V_2 ) )
goto V_354;
if ( F_147 ( V_8 , V_2 ) )
goto V_354;
F_219 ( V_2 ) ;
if ( F_205 ( V_8 , V_2 ) )
goto V_354;
V_104 = ( const struct V_103 * ) V_2 -> V_102 ;
V_101 = F_3 ( V_2 ) ;
V_2 -> V_112 = NULL ;
if ( V_8 -> V_115 == V_130 ) {
V_339 = F_172 ( V_8 , V_2 ) ;
goto V_356;
}
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( F_7 ( V_8 ) , V_2 ) ;
V_339 = 0 ;
if ( ! F_59 ( V_8 ) ) {
if ( ! F_187 ( V_8 , V_2 ) )
V_339 = F_172 ( V_8 , V_2 ) ;
} else if ( F_201 ( V_8 , V_2 ) ) {
goto V_354;
}
F_72 ( V_8 ) ;
V_356:
if ( V_338 )
F_73 ( V_8 ) ;
return V_339 ;
V_351:
if ( ! F_218 ( NULL , V_355 , V_2 ) )
goto V_340;
if ( F_176 ( V_2 ) ) {
V_344:
F_99 ( V_94 , V_312 ) ;
V_342:
F_99 ( V_94 , V_313 ) ;
} else {
F_80 ( NULL , V_2 ) ;
}
V_340:
F_179 ( V_2 ) ;
return 0 ;
V_354:
F_215 ( V_8 , V_2 ) ;
if ( V_338 )
F_73 ( V_8 ) ;
goto V_340;
V_353:
if ( ! F_218 ( NULL , V_355 , V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_340;
}
if ( F_176 ( V_2 ) ) {
F_55 ( F_56 ( V_8 ) ) ;
goto V_344;
}
switch ( F_223 ( F_56 ( V_8 ) , V_2 , V_104 ) ) {
case V_357 : {
struct V_7 * V_358 = F_224 ( F_50 ( V_2 -> V_112 ) ,
& V_113 , V_2 ,
F_214 ( V_104 ) ,
V_101 -> V_4 , V_104 -> V_6 ,
V_101 -> V_3 , V_104 -> V_5 ,
F_53 ( V_2 ) ) ;
if ( V_358 ) {
F_225 ( F_56 ( V_8 ) ) ;
V_8 = V_358 ;
V_338 = false ;
goto V_352;
}
}
case V_359 :
F_104 ( V_8 , V_2 ) ;
break;
case V_360 :
F_80 ( V_8 , V_2 ) ;
F_225 ( F_56 ( V_8 ) ) ;
goto V_340;
case V_361 : ;
}
goto V_340;
}
void F_159 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_81 * V_67 = F_84 ( V_2 ) ;
if ( V_67 && F_226 ( V_67 ) ) {
V_8 -> V_305 = V_67 ;
F_11 ( V_8 ) -> V_306 = V_2 -> V_307 ;
}
}
static int F_227 ( struct V_7 * V_8 )
{
struct V_106 * V_107 = F_25 ( V_8 ) ;
F_228 ( V_8 ) ;
V_107 -> V_362 = & V_363 ;
#ifdef F_81
F_7 ( V_8 ) -> V_364 = & V_365 ;
#endif
return 0 ;
}
void F_229 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_230 ( V_8 ) ;
F_231 ( V_8 ) ;
F_232 ( V_8 ) ;
F_233 ( & V_14 -> V_366 ) ;
#ifdef F_81
if ( V_14 -> V_234 ) {
F_132 ( V_8 ) ;
F_131 ( V_14 -> V_234 , V_249 ) ;
V_14 -> V_234 = NULL ;
}
#endif
F_234 ( & V_14 -> V_319 . V_321 ) ;
if ( F_25 ( V_8 ) -> V_367 )
F_235 ( V_8 ) ;
F_66 ( V_14 -> V_129 ) ;
F_236 ( V_14 ) ;
F_237 ( V_14 ) ;
F_95 () ;
F_238 ( V_8 ) ;
F_100 () ;
}
static void * F_239 ( struct V_368 * V_91 , void * V_369 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
struct V_94 * V_94 = F_240 ( V_91 ) ;
struct V_373 * V_374 ;
struct V_7 * V_8 = V_369 ;
if ( ! V_8 ) {
V_375:
V_374 = & V_113 . V_376 [ V_371 -> V_377 ] ;
F_241 ( & V_374 -> V_378 ) ;
V_8 = F_242 ( & V_374 -> V_158 ) ;
V_371 -> V_207 = 0 ;
goto V_379;
}
V_374 = & V_113 . V_376 [ V_371 -> V_377 ] ;
++ V_371 -> V_380 ;
++ V_371 -> V_207 ;
V_8 = F_243 ( V_8 ) ;
V_379:
F_244 (sk) {
if ( ! F_245 ( F_19 ( V_8 ) , V_94 ) )
continue;
if ( V_8 -> V_381 == V_371 -> V_229 )
return V_8 ;
}
F_246 ( & V_374 -> V_378 ) ;
V_371 -> V_207 = 0 ;
if ( ++ V_371 -> V_377 < V_382 )
goto V_375;
return NULL ;
}
static void * F_247 ( struct V_368 * V_91 , T_9 * V_383 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
void * V_384 ;
V_371 -> V_377 = 0 ;
V_371 -> V_207 = 0 ;
V_384 = F_239 ( V_91 , NULL ) ;
while ( V_384 && * V_383 ) {
V_384 = F_239 ( V_91 , V_384 ) ;
-- * V_383 ;
}
return V_384 ;
}
static inline bool F_248 ( const struct V_370 * V_371 )
{
return F_249 ( & V_113 . V_385 [ V_371 -> V_377 ] . V_386 ) ;
}
static void * F_250 ( struct V_368 * V_91 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
struct V_94 * V_94 = F_240 ( V_91 ) ;
void * V_384 = NULL ;
V_371 -> V_207 = 0 ;
for (; V_371 -> V_377 <= V_113 . V_387 ; ++ V_371 -> V_377 ) {
struct V_7 * V_8 ;
struct V_388 * V_246 ;
T_10 * V_378 = F_251 ( & V_113 , V_371 -> V_377 ) ;
if ( F_248 ( V_371 ) )
continue;
F_241 ( V_378 ) ;
F_252 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_381 != V_371 -> V_229 ||
! F_245 ( F_19 ( V_8 ) , V_94 ) ) {
continue;
}
V_384 = V_8 ;
goto V_125;
}
F_246 ( V_378 ) ;
}
V_125:
return V_384 ;
}
static void * F_253 ( struct V_368 * V_91 , void * V_369 )
{
struct V_7 * V_8 = V_369 ;
struct V_388 * V_246 ;
struct V_370 * V_371 = V_91 -> V_372 ;
struct V_94 * V_94 = F_240 ( V_91 ) ;
++ V_371 -> V_380 ;
++ V_371 -> V_207 ;
V_8 = F_254 ( V_8 ) ;
F_255 (sk, node) {
if ( V_8 -> V_381 == V_371 -> V_229 && F_245 ( F_19 ( V_8 ) , V_94 ) )
return V_8 ;
}
F_246 ( F_251 ( & V_113 , V_371 -> V_377 ) ) ;
++ V_371 -> V_377 ;
return F_250 ( V_91 ) ;
}
static void * F_256 ( struct V_368 * V_91 , T_9 V_383 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
void * V_384 ;
V_371 -> V_377 = 0 ;
V_384 = F_250 ( V_91 ) ;
while ( V_384 && V_383 ) {
V_384 = F_253 ( V_91 , V_384 ) ;
-- V_383 ;
}
return V_384 ;
}
static void * F_257 ( struct V_368 * V_91 , T_9 V_383 )
{
void * V_384 ;
struct V_370 * V_371 = V_91 -> V_372 ;
V_371 -> V_389 = V_390 ;
V_384 = F_247 ( V_91 , & V_383 ) ;
if ( ! V_384 ) {
V_371 -> V_389 = V_391 ;
V_384 = F_256 ( V_91 , V_383 ) ;
}
return V_384 ;
}
static void * F_258 ( struct V_368 * V_91 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
int V_207 = V_371 -> V_207 ;
int V_392 = V_371 -> V_380 ;
void * V_384 = NULL ;
switch ( V_371 -> V_389 ) {
case V_390 :
if ( V_371 -> V_377 >= V_382 )
break;
V_371 -> V_389 = V_390 ;
V_384 = F_239 ( V_91 , NULL ) ;
while ( V_207 -- && V_384 )
V_384 = F_239 ( V_91 , V_384 ) ;
if ( V_384 )
break;
V_371 -> V_377 = 0 ;
V_371 -> V_389 = V_391 ;
case V_391 :
if ( V_371 -> V_377 > V_113 . V_387 )
break;
V_384 = F_250 ( V_91 ) ;
while ( V_207 -- && V_384 )
V_384 = F_253 ( V_91 , V_384 ) ;
}
V_371 -> V_380 = V_392 ;
return V_384 ;
}
static void * F_259 ( struct V_368 * V_91 , T_9 * V_383 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
void * V_384 ;
if ( * V_383 && * V_383 == V_371 -> V_393 ) {
V_384 = F_258 ( V_91 ) ;
if ( V_384 )
goto V_125;
}
V_371 -> V_389 = V_390 ;
V_371 -> V_380 = 0 ;
V_371 -> V_377 = 0 ;
V_371 -> V_207 = 0 ;
V_384 = * V_383 ? F_257 ( V_91 , * V_383 - 1 ) : V_394 ;
V_125:
V_371 -> V_393 = * V_383 ;
return V_384 ;
}
static void * F_260 ( struct V_368 * V_91 , void * V_395 , T_9 * V_383 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
void * V_384 = NULL ;
if ( V_395 == V_394 ) {
V_384 = F_257 ( V_91 , 0 ) ;
goto V_125;
}
switch ( V_371 -> V_389 ) {
case V_390 :
V_384 = F_239 ( V_91 , V_395 ) ;
if ( ! V_384 ) {
V_371 -> V_389 = V_391 ;
V_371 -> V_377 = 0 ;
V_371 -> V_207 = 0 ;
V_384 = F_250 ( V_91 ) ;
}
break;
case V_391 :
V_384 = F_253 ( V_91 , V_395 ) ;
break;
}
V_125:
++ * V_383 ;
V_371 -> V_393 = * V_383 ;
return V_384 ;
}
static void F_261 ( struct V_368 * V_91 , void * V_395 )
{
struct V_370 * V_371 = V_91 -> V_372 ;
switch ( V_371 -> V_389 ) {
case V_390 :
if ( V_395 != V_394 )
F_246 ( & V_113 . V_376 [ V_371 -> V_377 ] . V_378 ) ;
break;
case V_391 :
if ( V_395 )
F_246 ( F_251 ( & V_113 , V_371 -> V_377 ) ) ;
break;
}
}
int F_262 ( struct V_396 * V_396 , struct V_397 * V_397 )
{
struct V_398 * V_399 = F_263 ( V_396 ) ;
struct V_370 * V_400 ;
int V_37 ;
V_37 = F_264 ( V_396 , V_397 , & V_399 -> V_401 ,
sizeof( struct V_370 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_400 = ( (struct V_368 * ) V_397 -> V_402 ) -> V_372 ;
V_400 -> V_229 = V_399 -> V_229 ;
V_400 -> V_393 = 0 ;
return 0 ;
}
int F_265 ( struct V_94 * V_94 , struct V_398 * V_399 )
{
int V_384 = 0 ;
struct V_403 * V_404 ;
V_399 -> V_401 . V_405 = F_259 ;
V_399 -> V_401 . V_406 = F_260 ;
V_399 -> V_401 . V_407 = F_261 ;
V_404 = F_266 ( V_399 -> V_408 , V_409 , V_94 -> V_410 ,
V_399 -> V_411 , V_399 ) ;
if ( ! V_404 )
V_384 = - V_244 ;
return V_384 ;
}
void F_267 ( struct V_94 * V_94 , struct V_398 * V_399 )
{
F_268 ( V_399 -> V_408 , V_94 -> V_410 ) ;
}
static void F_269 ( const struct V_92 * V_93 ,
struct V_368 * V_412 , int V_413 )
{
const struct V_224 * V_225 = F_107 ( V_93 ) ;
long V_414 = V_93 -> V_415 . V_416 - V_78 ;
F_270 ( V_412 , L_4
L_5 ,
V_413 ,
V_225 -> V_226 ,
V_225 -> V_417 ,
V_225 -> V_227 ,
F_52 ( V_225 -> V_418 ) ,
V_149 ,
0 , 0 ,
1 ,
F_271 ( V_414 ) ,
V_93 -> V_419 ,
F_272 ( F_273 ( V_412 ) ,
F_274 ( V_93 -> V_97 ) ) ,
0 ,
0 ,
0 ,
V_93 ) ;
}
static void F_275 ( struct V_7 * V_8 , struct V_368 * V_412 , int V_413 )
{
int V_420 ;
unsigned long V_421 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_106 * V_107 = F_25 ( V_8 ) ;
const struct V_28 * V_29 = F_11 ( V_8 ) ;
const struct V_422 * V_423 = & V_107 -> V_424 . V_423 ;
T_3 V_5 = V_29 -> V_63 ;
T_3 V_425 = V_29 -> V_426 ;
T_11 V_427 = F_52 ( V_29 -> V_68 ) ;
T_11 V_428 = F_52 ( V_29 -> V_49 ) ;
int V_429 ;
int V_389 ;
if ( V_107 -> V_430 == V_147 ||
V_107 -> V_430 == V_431 ||
V_107 -> V_430 == V_432 ) {
V_420 = 1 ;
V_421 = V_107 -> V_433 ;
} else if ( V_107 -> V_430 == V_434 ) {
V_420 = 4 ;
V_421 = V_107 -> V_433 ;
} else if ( F_276 ( & V_8 -> V_435 ) ) {
V_420 = 2 ;
V_421 = V_8 -> V_435 . V_416 ;
} else {
V_420 = 0 ;
V_421 = V_78 ;
}
V_389 = F_277 ( V_8 ) ;
if ( V_389 == V_130 )
V_429 = V_8 -> V_436 ;
else
V_429 = F_278 ( int , V_14 -> V_215 - V_14 -> V_437 , 0 ) ;
F_270 ( V_412 , L_6
L_7 ,
V_413 , V_425 , V_428 , V_5 , V_427 , V_389 ,
V_14 -> V_17 - V_14 -> V_110 ,
V_429 ,
V_420 ,
F_271 ( V_421 - V_78 ) ,
V_107 -> V_140 ,
F_272 ( F_273 ( V_412 ) , F_274 ( V_8 ) ) ,
V_107 -> V_438 ,
F_279 ( V_8 ) ,
F_193 ( & V_8 -> V_439 ) , V_8 ,
F_280 ( V_107 -> V_142 ) ,
F_280 ( V_107 -> V_440 . V_441 ) ,
( V_107 -> V_440 . V_442 << 1 ) | V_107 -> V_440 . V_443 ,
V_14 -> V_444 ,
V_389 == V_130 ?
V_423 -> V_445 :
( F_281 ( V_14 ) ? - 1 : V_14 -> V_446 ) ) ;
}
static void F_282 ( const struct V_190 * V_208 ,
struct V_368 * V_412 , int V_413 )
{
long V_414 = V_208 -> V_447 . V_416 - V_78 ;
T_3 V_5 , V_425 ;
T_11 V_427 , V_428 ;
V_5 = V_208 -> V_448 ;
V_425 = V_208 -> V_449 ;
V_427 = F_52 ( V_208 -> V_450 ) ;
V_428 = F_52 ( V_208 -> V_451 ) ;
F_270 ( V_412 , L_4
L_8 ,
V_413 , V_425 , V_428 , V_5 , V_427 , V_208 -> V_452 , 0 , 0 ,
3 , F_271 ( V_414 ) , 0 , 0 , 0 , 0 ,
F_193 ( & V_208 -> V_453 ) , V_208 ) ;
}
static int F_283 ( struct V_368 * V_91 , void * V_395 )
{
struct V_370 * V_371 ;
struct V_7 * V_8 = V_395 ;
F_284 ( V_91 , V_454 - 1 ) ;
if ( V_395 == V_394 ) {
F_285 ( V_91 , L_9
L_10
L_11 ) ;
goto V_125;
}
V_371 = V_91 -> V_372 ;
if ( V_8 -> V_115 == V_116 )
F_282 ( V_395 , V_91 , V_371 -> V_380 ) ;
else if ( V_8 -> V_115 == V_117 )
F_269 ( V_395 , V_91 , V_371 -> V_380 ) ;
else
F_275 ( V_395 , V_91 , V_371 -> V_380 ) ;
V_125:
F_286 ( V_91 , '\n' ) ;
return 0 ;
}
static int T_12 F_287 ( struct V_94 * V_94 )
{
return F_265 ( V_94 , & V_455 ) ;
}
static void T_13 F_288 ( struct V_94 * V_94 )
{
F_267 ( V_94 , & V_455 ) ;
}
int T_14 F_289 ( void )
{
return F_290 ( & V_456 ) ;
}
void F_291 ( void )
{
F_292 ( & V_456 ) ;
}
static void T_13 F_293 ( struct V_94 * V_94 )
{
int V_457 ;
F_294 (cpu)
F_295 ( * F_296 ( V_94 -> V_193 . F_7 , V_457 ) ) ;
F_297 ( V_94 -> V_193 . F_7 ) ;
}
static int T_12 F_298 ( struct V_94 * V_94 )
{
int V_458 , V_457 ;
V_94 -> V_193 . F_7 = F_299 ( struct V_7 * ) ;
if ( ! V_94 -> V_193 . F_7 )
return - V_244 ;
F_294 (cpu) {
struct V_7 * V_8 ;
V_458 = F_300 ( & V_8 , V_459 , V_460 ,
V_57 , V_94 ) ;
if ( V_458 )
goto V_461;
F_301 ( V_8 , V_462 ) ;
* F_296 ( V_94 -> V_193 . F_7 , V_457 ) = V_8 ;
}
V_94 -> V_193 . V_463 = 2 ;
V_94 -> V_193 . V_464 = 1 ;
V_94 -> V_193 . V_465 = V_466 ;
V_94 -> V_193 . V_467 = V_468 ;
V_94 -> V_193 . V_469 = V_470 ;
V_94 -> V_193 . V_471 = V_472 ;
V_94 -> V_193 . V_473 = V_474 ;
V_94 -> V_193 . V_475 = V_476 ;
V_94 -> V_193 . V_477 = V_478 ;
V_94 -> V_193 . V_479 = V_480 ;
V_94 -> V_193 . V_481 = 1 ;
V_94 -> V_193 . V_482 = V_483 ;
V_94 -> V_193 . V_484 = V_485 ;
V_94 -> V_193 . V_486 = V_487 ;
V_94 -> V_193 . V_488 = 0 ;
V_94 -> V_193 . V_489 = V_490 ;
V_94 -> V_193 . V_491 = V_492 ;
return 0 ;
V_461:
F_293 ( V_94 ) ;
return V_458 ;
}
static void T_13 F_302 ( struct V_493 * V_494 )
{
F_303 ( & V_113 , & V_65 , V_42 ) ;
}
void T_14 F_304 ( void )
{
F_305 ( & V_113 ) ;
if ( F_290 ( & V_495 ) )
F_306 ( L_12 ) ;
}
