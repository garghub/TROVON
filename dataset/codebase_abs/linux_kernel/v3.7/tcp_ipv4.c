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
! V_14 -> V_19 . V_22 && V_34 -> V_3 == V_3 )
F_25 ( V_8 , & V_36 -> V_68 ) ;
V_29 -> V_69 = V_27 -> V_50 ;
V_29 -> V_64 = V_3 ;
F_26 ( V_8 ) -> V_70 = 0 ;
if ( V_39 )
F_26 ( V_8 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_14 -> V_19 . V_72 = V_73 ;
F_27 ( V_8 , V_74 ) ;
V_37 = F_28 ( & V_66 , V_8 ) ;
if ( V_37 )
goto V_75;
V_36 = F_29 ( V_34 , V_36 , V_30 , V_31 ,
V_29 -> V_49 , V_29 -> V_69 , V_8 ) ;
if ( F_19 ( V_36 ) ) {
V_37 = F_20 ( V_36 ) ;
V_36 = NULL ;
goto V_75;
}
V_8 -> V_76 = V_77 ;
F_30 ( V_8 , & V_36 -> V_68 ) ;
if ( ! V_14 -> V_17 && F_24 ( ! V_14 -> V_65 ) )
V_14 -> V_17 = F_2 ( V_29 -> V_55 ,
V_29 -> V_64 ,
V_29 -> V_49 ,
V_27 -> V_50 ) ;
V_29 -> V_78 = V_14 -> V_17 ^ V_79 ;
if ( F_24 ( ! V_14 -> V_65 ) )
V_37 = F_31 ( V_8 ) ;
else
V_37 = F_10 ( V_8 ) ;
V_36 = NULL ;
if ( V_37 )
goto V_75;
return 0 ;
V_75:
F_27 ( V_8 , V_80 ) ;
F_23 ( V_36 ) ;
V_8 -> V_81 = 0 ;
V_29 -> V_69 = 0 ;
return V_37 ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_82 * V_68 ;
struct V_28 * V_29 = F_14 ( V_8 ) ;
T_4 V_83 = F_7 ( V_8 ) -> V_84 ;
if ( V_8 -> V_85 == V_86 )
return;
V_68 = F_33 ( V_8 , V_83 ) ;
if ( ! V_68 )
return;
if ( V_83 < F_34 ( V_68 ) && F_35 ( V_8 , V_68 ) )
V_8 -> V_87 = V_88 ;
V_83 = F_34 ( V_68 ) ;
if ( V_29 -> V_89 != V_90 &&
F_26 ( V_8 ) -> V_91 > V_83 ) {
F_36 ( V_8 , V_83 ) ;
F_37 ( V_8 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_82 * V_68 = F_39 ( V_8 , 0 ) ;
if ( V_68 )
V_68 -> V_92 -> V_93 ( V_68 , V_8 , V_2 ) ;
}
void F_40 ( struct V_1 * V_94 , T_4 V_95 )
{
const struct V_96 * V_97 = ( const struct V_96 * ) V_94 -> V_98 ;
struct V_99 * V_100 = (struct V_99 * ) ( V_94 -> V_98 + ( V_97 -> V_101 << 2 ) ) ;
struct V_102 * V_103 ;
struct V_13 * V_14 ;
struct V_28 * V_29 ;
const int type = F_41 ( V_94 ) -> type ;
const int V_104 = F_41 ( V_94 ) -> V_104 ;
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_105 * V_106 ;
T_1 V_107 ;
T_1 V_108 ;
int V_37 ;
struct V_109 * V_109 = F_42 ( V_94 -> V_110 ) ;
if ( V_94 -> V_111 < ( V_97 -> V_101 << 2 ) + 8 ) {
F_43 ( V_109 , V_112 ) ;
return;
}
V_8 = F_44 ( V_109 , & V_113 , V_97 -> V_3 , V_100 -> V_5 ,
V_97 -> V_4 , V_100 -> V_6 , F_45 ( V_94 ) ) ;
if ( ! V_8 ) {
F_43 ( V_109 , V_112 ) ;
return;
}
if ( V_8 -> V_85 == V_114 ) {
F_46 ( F_47 ( V_8 ) ) ;
return;
}
F_48 ( V_8 ) ;
if ( F_16 ( V_8 ) &&
type != V_115 &&
V_104 != V_116 )
F_49 ( V_109 , V_117 ) ;
if ( V_8 -> V_85 == V_80 )
goto V_118;
if ( F_50 ( V_97 -> V_119 < F_14 ( V_8 ) -> V_120 ) ) {
F_49 ( V_109 , V_121 ) ;
goto V_118;
}
V_103 = F_26 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_106 = V_14 -> V_122 ;
V_107 = F_51 ( V_100 -> V_107 ) ;
if ( V_8 -> V_85 != V_86 &&
! F_52 ( V_107 , V_14 -> V_123 , V_14 -> V_124 ) &&
( V_106 == NULL || V_107 != F_53 ( V_106 ) -> V_125 ) ) {
F_49 ( V_109 , V_126 ) ;
goto V_118;
}
switch ( type ) {
case V_127 :
F_38 ( V_94 , V_8 ) ;
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
if ( ! F_16 ( V_8 ) ) {
F_32 ( V_8 ) ;
} else {
if ( ! F_54 ( V_132 , & V_14 -> V_133 ) )
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
if ( F_16 ( V_8 ) )
break;
V_103 -> V_139 -- ;
F_26 ( V_8 ) -> V_140 = ( V_14 -> V_141 ? F_55 ( V_14 ) :
V_142 ) << V_103 -> V_139 ;
F_56 ( V_8 ) ;
V_2 = F_57 ( V_8 ) ;
F_58 ( ! V_2 ) ;
V_108 = V_103 -> V_140 - F_59 ( V_103 -> V_140 ,
V_143 - F_60 ( V_2 ) -> V_144 ) ;
if ( V_108 ) {
F_61 ( V_8 , V_145 ,
V_108 , V_146 ) ;
} else {
F_62 ( V_8 ) ;
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
if ( F_16 ( V_8 ) )
goto V_118;
V_106 = F_63 ( V_8 , & V_149 , V_100 -> V_5 ,
V_97 -> V_3 , V_97 -> V_4 ) ;
if ( ! V_106 )
goto V_118;
F_64 ( V_106 -> V_8 ) ;
if ( V_107 != F_53 ( V_106 ) -> V_125 ) {
F_49 ( V_109 , V_126 ) ;
goto V_118;
}
F_65 ( V_8 , V_106 , V_149 ) ;
goto V_118;
case V_74 :
case V_150 :
if ( ! F_16 ( V_8 ) ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
F_66 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
goto V_118;
}
V_29 = F_14 ( V_8 ) ;
if ( ! F_16 ( V_8 ) && V_29 -> V_153 ) {
V_8 -> V_151 = V_37 ;
V_8 -> V_152 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
V_118:
F_67 ( V_8 ) ;
F_68 ( V_8 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
if ( V_2 -> V_154 == V_155 ) {
V_100 -> V_156 = ~ F_70 ( V_2 -> V_111 , V_4 , V_3 , 0 ) ;
V_2 -> V_157 = F_71 ( V_2 ) - V_2 -> V_158 ;
V_2 -> V_159 = F_72 ( struct V_99 , V_156 ) ;
} else {
V_100 -> V_156 = F_70 ( V_2 -> V_111 , V_4 , V_3 ,
F_73 ( V_100 ,
V_100 -> V_160 << 2 ,
V_2 -> V_161 ) ) ;
}
}
void F_74 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_28 * V_29 = F_14 ( V_8 ) ;
F_69 ( V_2 , V_29 -> V_55 , V_29 -> V_64 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 ;
struct V_99 * V_100 ;
if ( ! F_76 ( V_2 , sizeof( * V_100 ) ) )
return - V_40 ;
V_97 = F_3 ( V_2 ) ;
V_100 = F_4 ( V_2 ) ;
V_100 -> V_156 = 0 ;
V_2 -> V_154 = V_155 ;
F_69 ( V_2 , V_97 -> V_4 , V_97 -> V_3 ) ;
return 0 ;
}
static void F_77 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
#ifdef F_78
T_3 V_46 [ ( V_162 >> 2 ) ] ;
#endif
} V_163 ;
struct V_164 V_165 ;
#ifdef F_78
struct V_166 * V_167 ;
const T_5 * V_168 = NULL ;
unsigned char V_169 [ 16 ] ;
int V_170 ;
struct V_7 * V_171 = NULL ;
#endif
struct V_109 * V_109 ;
if ( V_100 -> V_172 )
return;
if ( F_79 ( V_2 ) -> V_173 != V_174 )
return;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_100 . V_5 = V_100 -> V_6 ;
V_163 . V_100 . V_6 = V_100 -> V_5 ;
V_163 . V_100 . V_160 = sizeof( struct V_99 ) / 4 ;
V_163 . V_100 . V_172 = 1 ;
if ( V_100 -> V_175 ) {
V_163 . V_100 . V_107 = V_100 -> V_176 ;
} else {
V_163 . V_100 . V_175 = 1 ;
V_163 . V_100 . V_176 = F_80 ( F_51 ( V_100 -> V_107 ) + V_100 -> V_177 + V_100 -> V_178 +
V_2 -> V_111 - ( V_100 -> V_160 << 2 ) ) ;
}
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_100 ) ;
#ifdef F_78
V_168 = F_81 ( V_100 ) ;
if ( ! V_8 && V_168 ) {
V_171 = F_82 ( F_42 ( F_83 ( V_2 ) -> V_110 ) ,
& V_113 , F_3 ( V_2 ) -> V_3 ,
F_84 ( V_100 -> V_6 ) , F_45 ( V_2 ) ) ;
if ( ! V_171 )
return;
F_85 () ;
V_167 = F_86 ( V_171 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_167 )
goto V_183;
V_170 = F_87 ( V_169 , V_167 , NULL , NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 )
goto V_183;
} else {
V_167 = V_8 ? F_86 ( V_8 , (union V_182 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_167 ) {
V_163 . V_46 [ 0 ] = F_80 ( ( V_184 << 24 ) |
( V_184 << 16 ) |
( V_185 << 8 ) |
V_186 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_100 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_88 ( ( T_5 * ) & V_163 . V_46 [ 1 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_100 ) ;
}
#endif
V_165 . V_161 = F_89 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_187 = F_72 ( struct V_99 , V_156 ) / 2 ;
V_165 . V_188 = ( V_8 && F_14 ( V_8 ) -> V_189 ) ? V_190 : 0 ;
if ( V_8 )
V_165 . V_191 = V_8 -> V_56 ;
V_109 = F_42 ( F_83 ( V_2 ) -> V_110 ) ;
V_165 . V_192 = F_3 ( V_2 ) -> V_192 ;
F_90 ( V_109 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_91 ( V_109 , V_193 ) ;
F_91 ( V_109 , V_194 ) ;
#ifdef F_78
V_183:
if ( V_171 ) {
F_92 () ;
F_68 ( V_171 ) ;
}
#endif
}
static void F_93 ( struct V_1 * V_2 , T_4 V_107 , T_4 V_175 ,
T_4 V_195 , T_4 V_196 , int V_197 ,
struct V_166 * V_167 ,
int V_198 , T_6 V_192 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
T_3 V_46 [ ( V_199 >> 2 )
#ifdef F_78
+ ( V_162 >> 2 )
#endif
] ;
} V_163 ;
struct V_164 V_165 ;
struct V_109 * V_109 = F_42 ( F_83 ( V_2 ) -> V_110 ) ;
memset ( & V_163 . V_100 , 0 , sizeof( struct V_99 ) ) ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_179 [ 0 ] . V_180 = ( unsigned char * ) & V_163 ;
V_165 . V_179 [ 0 ] . V_181 = sizeof( V_163 . V_100 ) ;
if ( V_196 ) {
V_163 . V_46 [ 0 ] = F_80 ( ( V_184 << 24 ) | ( V_184 << 16 ) |
( V_200 << 8 ) |
V_201 ) ;
V_163 . V_46 [ 1 ] = F_80 ( V_143 ) ;
V_163 . V_46 [ 2 ] = F_80 ( V_196 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_199 ;
}
V_163 . V_100 . V_5 = V_100 -> V_6 ;
V_163 . V_100 . V_6 = V_100 -> V_5 ;
V_163 . V_100 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
V_163 . V_100 . V_107 = F_80 ( V_107 ) ;
V_163 . V_100 . V_176 = F_80 ( V_175 ) ;
V_163 . V_100 . V_175 = 1 ;
V_163 . V_100 . V_202 = F_94 ( V_195 ) ;
#ifdef F_78
if ( V_167 ) {
int V_203 = ( V_196 ) ? 3 : 0 ;
V_163 . V_46 [ V_203 ++ ] = F_80 ( ( V_184 << 24 ) |
( V_184 << 16 ) |
( V_185 << 8 ) |
V_186 ) ;
V_165 . V_179 [ 0 ] . V_181 += V_162 ;
V_163 . V_100 . V_160 = V_165 . V_179 [ 0 ] . V_181 / 4 ;
F_88 ( ( T_5 * ) & V_163 . V_46 [ V_203 ] ,
V_167 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_163 . V_100 ) ;
}
#endif
V_165 . V_188 = V_198 ;
V_165 . V_161 = F_89 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_165 . V_179 [ 0 ] . V_181 , V_57 , 0 ) ;
V_165 . V_187 = F_72 ( struct V_99 , V_156 ) / 2 ;
if ( V_197 )
V_165 . V_191 = V_197 ;
V_165 . V_192 = V_192 ;
F_90 ( V_109 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_165 , V_165 . V_179 [ 0 ] . V_181 ) ;
F_91 ( V_109 , V_193 ) ;
}
static void F_95 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_204 * V_205 = F_47 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_93 ( V_2 , V_12 -> V_18 , V_12 -> V_206 ,
V_12 -> V_207 >> V_205 -> V_208 ,
V_12 -> V_21 ,
V_205 -> V_209 ,
F_96 ( V_12 ) ,
V_205 -> V_210 ? V_190 : 0 ,
V_205 -> V_211
) ;
F_46 ( V_205 ) ;
}
static void F_97 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 )
{
F_93 ( V_2 , ( V_8 -> V_85 == V_86 ) ?
F_53 ( V_106 ) -> V_125 + 1 : F_7 ( V_8 ) -> V_124 ,
F_53 ( V_106 ) -> V_212 , V_106 -> V_213 ,
V_106 -> V_20 ,
0 ,
F_86 ( V_8 , (union V_182 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_98 ( V_106 ) -> V_214 ? V_190 : 0 ,
F_3 ( V_2 ) -> V_192 ) ;
}
static int F_99 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_105 * V_106 ,
struct V_215 * V_216 ,
T_7 V_217 ,
bool V_218 )
{
const struct V_219 * V_220 = F_98 ( V_106 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_100 ( V_8 , & V_34 , V_106 ) ) == NULL )
return - 1 ;
V_2 = F_101 ( V_8 , V_68 , V_106 , V_216 , NULL ) ;
if ( V_2 ) {
F_69 ( V_2 , V_220 -> V_221 , V_220 -> V_222 ) ;
F_102 ( V_2 , V_217 ) ;
V_37 = F_103 ( V_2 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 ,
V_220 -> V_46 ) ;
V_37 = F_104 ( V_37 ) ;
if ( ! F_53 ( V_106 ) -> V_223 && ! V_37 )
F_53 ( V_106 ) -> V_223 = V_143 ;
}
return V_37 ;
}
static int F_105 ( struct V_7 * V_8 , struct V_105 * V_106 ,
struct V_215 * V_216 )
{
F_91 ( F_22 ( V_8 ) , V_224 ) ;
return F_99 ( V_8 , NULL , V_106 , V_216 , 0 , false ) ;
}
static void F_106 ( struct V_105 * V_106 )
{
F_107 ( F_98 ( V_106 ) -> V_46 ) ;
}
bool F_108 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_225 )
{
const char * V_226 = L_1 ;
bool V_227 = false ;
struct V_228 * V_229 ;
#ifdef F_109
if ( V_230 ) {
V_226 = L_2 ;
V_227 = true ;
F_49 ( F_22 ( V_8 ) , V_231 ) ;
} else
#endif
F_49 ( F_22 ( V_8 ) , V_232 ) ;
V_229 = F_26 ( V_8 ) -> V_233 . V_234 ;
if ( ! V_229 -> V_235 ) {
V_229 -> V_235 = 1 ;
F_110 ( L_3 ,
V_225 , F_84 ( F_4 ( V_2 ) -> V_5 ) , V_226 ) ;
}
return V_227 ;
}
static struct V_38 * F_111 ( struct V_1 * V_2 )
{
const struct V_236 * V_46 = & ( F_112 ( V_2 ) -> V_46 ) ;
struct V_38 * V_237 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_238 = sizeof( * V_237 ) + V_46 -> V_71 ;
V_237 = F_113 ( V_238 , V_239 ) ;
if ( V_237 ) {
if ( F_114 ( & V_237 -> V_46 , V_2 ) ) {
F_107 ( V_237 ) ;
V_237 = NULL ;
}
}
}
return V_237 ;
}
struct V_166 * F_86 ( struct V_7 * V_8 ,
const union V_182 * V_240 ,
int V_241 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_242 * V_243 ;
unsigned int V_244 = sizeof( struct V_245 ) ;
struct V_246 * V_247 ;
V_247 = F_115 ( V_14 -> V_248 ,
F_16 ( V_8 ) ||
F_116 ( & V_8 -> V_249 . V_250 ) ) ;
if ( ! V_247 )
return NULL ;
#if F_117 ( V_251 )
if ( V_241 == V_252 )
V_244 = sizeof( struct V_253 ) ;
#endif
F_118 (key, pos, &md5sig->head, node) {
if ( V_167 -> V_241 != V_241 )
continue;
if ( ! memcmp ( & V_167 -> V_240 , V_240 , V_244 ) )
return V_167 ;
}
return NULL ;
}
struct V_166 * F_119 ( struct V_7 * V_8 ,
struct V_7 * V_254 )
{
union V_182 * V_240 ;
V_240 = (union V_182 * ) & F_14 ( V_254 ) -> V_64 ;
return F_86 ( V_8 , V_240 , V_42 ) ;
}
static struct V_166 * F_120 ( struct V_7 * V_8 ,
struct V_105 * V_106 )
{
union V_182 * V_240 ;
V_240 = (union V_182 * ) & F_98 ( V_106 ) -> V_222 ;
return F_86 ( V_8 , V_240 , V_42 ) ;
}
int F_121 ( struct V_7 * V_8 , const union V_182 * V_240 ,
int V_241 , const T_6 * V_255 , T_6 V_256 , T_8 V_257 )
{
struct V_166 * V_167 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_246 * V_247 ;
V_167 = F_86 ( V_8 , (union V_182 * ) & V_240 , V_42 ) ;
if ( V_167 ) {
memcpy ( V_167 -> V_167 , V_255 , V_256 ) ;
V_167 -> V_258 = V_256 ;
return 0 ;
}
V_247 = F_15 ( V_14 -> V_248 ,
F_16 ( V_8 ) ) ;
if ( ! V_247 ) {
V_247 = F_113 ( sizeof( * V_247 ) , V_257 ) ;
if ( ! V_247 )
return - V_259 ;
F_122 ( V_8 , V_260 ) ;
F_123 ( & V_247 -> V_158 ) ;
F_124 ( V_14 -> V_248 , V_247 ) ;
}
V_167 = F_125 ( V_8 , sizeof( * V_167 ) , V_257 ) ;
if ( ! V_167 )
return - V_259 ;
if ( F_126 ( & V_247 -> V_158 ) && ! F_127 ( V_8 ) ) {
F_128 ( V_8 , V_167 , sizeof( * V_167 ) ) ;
return - V_259 ;
}
memcpy ( V_167 -> V_167 , V_255 , V_256 ) ;
V_167 -> V_258 = V_256 ;
V_167 -> V_241 = V_241 ;
memcpy ( & V_167 -> V_240 , V_240 ,
( V_241 == V_252 ) ? sizeof( struct V_253 ) :
sizeof( struct V_245 ) ) ;
F_129 ( & V_167 -> V_261 , & V_247 -> V_158 ) ;
return 0 ;
}
int F_130 ( struct V_7 * V_8 , const union V_182 * V_240 , int V_241 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_246 * V_247 ;
V_167 = F_86 ( V_8 , (union V_182 * ) & V_240 , V_42 ) ;
if ( ! V_167 )
return - V_262 ;
F_131 ( & V_167 -> V_261 ) ;
F_132 ( sizeof( * V_167 ) , & V_8 -> V_263 ) ;
F_133 ( V_167 , V_264 ) ;
V_247 = F_15 ( V_14 -> V_248 ,
F_16 ( V_8 ) ) ;
if ( F_126 ( & V_247 -> V_158 ) )
F_134 () ;
return 0 ;
}
void F_135 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_166 * V_167 ;
struct V_242 * V_243 , * V_265 ;
struct V_246 * V_247 ;
V_247 = F_15 ( V_14 -> V_248 , 1 ) ;
if ( ! F_126 ( & V_247 -> V_158 ) )
F_134 () ;
F_136 (key, pos, n, &md5sig->head, node) {
F_131 ( & V_167 -> V_261 ) ;
F_132 ( sizeof( * V_167 ) , & V_8 -> V_263 ) ;
F_133 ( V_167 , V_264 ) ;
}
}
static int F_137 ( struct V_7 * V_8 , char T_9 * V_266 ,
int V_71 )
{
struct V_267 V_268 ;
struct V_26 * sin = (struct V_26 * ) & V_268 . V_269 ;
if ( V_71 < sizeof( V_268 ) )
return - V_40 ;
if ( F_138 ( & V_268 , V_266 , sizeof( V_268 ) ) )
return - V_270 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_268 . V_271 || ! V_268 . V_272 )
return F_130 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_268 . V_272 > V_273 )
return - V_40 ;
return F_121 ( V_8 , (union V_182 * ) & sin -> V_44 . V_45 ,
V_42 , V_268 . V_271 , V_268 . V_272 ,
V_274 ) ;
}
static int F_139 ( struct V_275 * V_276 ,
T_3 V_3 , T_3 V_4 , int V_277 )
{
struct V_278 * V_279 ;
struct V_280 V_281 ;
V_279 = & V_276 -> V_282 . V_54 ;
V_279 -> V_4 = V_4 ;
V_279 -> V_3 = V_3 ;
V_279 -> V_283 = 0 ;
V_279 -> V_284 = V_57 ;
V_279 -> V_111 = F_140 ( V_277 ) ;
F_141 ( & V_281 , V_279 , sizeof( * V_279 ) ) ;
return F_142 ( & V_276 -> V_285 , & V_281 , sizeof( * V_279 ) ) ;
}
static int F_88 ( char * V_286 , const struct V_166 * V_167 ,
T_3 V_3 , T_3 V_4 , const struct V_99 * V_100 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
V_276 = F_143 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_144 ( V_288 ) )
goto V_290;
if ( F_139 ( V_276 , V_3 , V_4 , V_100 -> V_160 << 2 ) )
goto V_290;
if ( F_145 ( V_276 , V_100 ) )
goto V_290;
if ( F_146 ( V_276 , V_167 ) )
goto V_290;
if ( F_147 ( V_288 , V_286 ) )
goto V_290;
F_148 () ;
return 0 ;
V_290:
F_148 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
int F_87 ( char * V_286 , struct V_166 * V_167 ,
const struct V_7 * V_8 , const struct V_105 * V_106 ,
const struct V_1 * V_2 )
{
struct V_275 * V_276 ;
struct V_287 * V_288 ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_14 ( V_8 ) -> V_55 ;
V_3 = F_14 ( V_8 ) -> V_64 ;
} else if ( V_106 ) {
V_4 = F_98 ( V_106 ) -> V_221 ;
V_3 = F_98 ( V_106 ) -> V_222 ;
} else {
const struct V_96 * V_97 = F_3 ( V_2 ) ;
V_4 = V_97 -> V_4 ;
V_3 = V_97 -> V_3 ;
}
V_276 = F_143 () ;
if ( ! V_276 )
goto V_289;
V_288 = & V_276 -> V_285 ;
if ( F_144 ( V_288 ) )
goto V_290;
if ( F_139 ( V_276 , V_3 , V_4 , V_2 -> V_111 ) )
goto V_290;
if ( F_145 ( V_276 , V_100 ) )
goto V_290;
if ( F_149 ( V_276 , V_2 , V_100 -> V_160 << 2 ) )
goto V_290;
if ( F_146 ( V_276 , V_167 ) )
goto V_290;
if ( F_147 ( V_288 , V_286 ) )
goto V_290;
F_148 () ;
return 0 ;
V_290:
F_148 () ;
V_289:
memset ( V_286 , 0 , 16 ) ;
return 1 ;
}
static bool F_150 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_168 = NULL ;
struct V_166 * V_291 ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
int V_170 ;
unsigned char V_169 [ 16 ] ;
V_291 = F_86 ( V_8 , (union V_182 * ) & V_97 -> V_4 ,
V_42 ) ;
V_168 = F_81 ( V_100 ) ;
if ( ! V_291 && ! V_168 )
return false ;
if ( V_291 && ! V_168 ) {
F_49 ( F_22 ( V_8 ) , V_292 ) ;
return true ;
}
if ( ! V_291 && V_168 ) {
F_49 ( F_22 ( V_8 ) , V_293 ) ;
return true ;
}
V_170 = F_87 ( V_169 ,
V_291 ,
NULL , NULL , V_2 ) ;
if ( V_170 || memcmp ( V_168 , V_169 , 16 ) != 0 ) {
F_151 ( L_4 ,
& V_97 -> V_4 , F_84 ( V_100 -> V_6 ) ,
& V_97 -> V_3 , F_84 ( V_100 -> V_5 ) ,
V_170 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
static bool F_152 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_294 * V_295 ,
struct V_294 * V_296 )
{
bool V_297 = false ;
struct V_298 * V_299 ;
if ( F_24 ( ! F_153 ( V_295 ) ) ) {
if ( ( V_300 & V_301 ) ||
( ( V_300 & V_302 ) &&
( F_60 ( V_2 ) -> V_303 != F_60 ( V_2 ) -> V_107 + 1 ) ) )
V_297 = true ;
else
return false ;
}
V_299 = F_26 ( V_8 ) -> V_233 . V_299 ;
F_49 ( F_22 ( V_8 ) , V_304 ) ;
if ( ( V_300 & V_305 ) == 0 ||
V_299 == NULL || V_299 -> V_306 == 0 )
return false ;
if ( V_299 -> V_307 >= V_299 -> V_306 ) {
struct V_105 * V_308 ;
F_154 ( & V_299 -> V_309 ) ;
V_308 = V_299 -> V_310 ;
if ( ( V_308 == NULL ) || F_155 ( V_308 -> V_311 , V_79 ) ) {
F_156 ( & V_299 -> V_309 ) ;
F_49 ( F_22 ( V_8 ) ,
V_312 ) ;
V_295 -> V_111 = - 1 ;
return false ;
}
V_299 -> V_310 = V_308 -> V_313 ;
V_299 -> V_307 -- ;
F_156 ( & V_299 -> V_309 ) ;
F_157 ( V_308 ) ;
}
if ( V_297 ) {
F_53 ( V_106 ) -> V_212 = F_60 ( V_2 ) -> V_303 ;
return true ;
}
if ( V_295 -> V_111 == V_314 ) {
if ( ( V_300 & V_315 ) == 0 ) {
F_158 ( F_3 ( V_2 ) -> V_4 , V_296 ) ;
if ( ( V_296 -> V_111 != V_314 ) ||
memcmp ( & V_295 -> V_316 [ 0 ] , & V_296 -> V_316 [ 0 ] ,
V_314 ) != 0 )
return false ;
V_296 -> V_111 = - 1 ;
}
F_53 ( V_106 ) -> V_212 = F_60 ( V_2 ) -> V_303 ;
return true ;
} else if ( V_295 -> V_111 == 0 ) {
F_158 ( F_3 ( V_2 ) -> V_4 , V_296 ) ;
F_49 ( F_22 ( V_8 ) ,
V_317 ) ;
} else {
F_158 ( F_3 ( V_2 ) -> V_4 , V_296 ) ;
}
return false ;
}
static int F_159 ( struct V_7 * V_8 ,
struct V_1 * V_2 ,
struct V_1 * V_318 ,
struct V_105 * V_106 ,
struct V_215 * V_216 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_319 * V_320 = & F_26 ( V_8 ) -> V_233 ;
const struct V_219 * V_220 = F_98 ( V_106 ) ;
struct V_7 * V_321 ;
int V_37 ;
V_106 -> V_322 = 0 ;
V_106 -> V_8 = NULL ;
V_321 = F_26 ( V_8 ) -> V_323 -> V_324 ( V_8 , V_2 , V_106 , NULL ) ;
if ( V_321 == NULL ) {
F_49 ( F_22 ( V_8 ) ,
V_325 ) ;
F_160 ( V_318 ) ;
return - 1 ;
}
V_37 = F_103 ( V_318 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_104 ( V_37 ) ;
if ( ! V_37 )
F_53 ( V_106 ) -> V_223 = V_143 ;
F_154 ( & V_320 -> V_299 -> V_309 ) ;
V_320 -> V_299 -> V_307 ++ ;
F_156 ( & V_320 -> V_299 -> V_309 ) ;
V_14 = F_7 ( V_321 ) ;
V_14 -> V_122 = V_106 ;
F_9 ( V_8 ) ;
F_53 ( V_106 ) -> V_326 = V_8 ;
V_14 -> V_327 = F_84 ( F_4 ( V_2 ) -> V_202 ) ;
F_61 ( V_321 , V_145 ,
V_142 , V_146 ) ;
F_161 ( V_8 , V_106 , V_321 ) ;
F_26 ( V_321 ) -> V_323 -> V_328 ( V_321 ) ;
F_162 ( V_321 ) ;
F_163 ( V_321 ) ;
F_164 ( V_321 ) ;
F_165 ( V_321 ) ;
if ( F_60 ( V_2 ) -> V_303 == F_60 ( V_2 ) -> V_107 + 1 ) {
V_14 -> V_212 = F_60 ( V_2 ) -> V_303 ;
} else {
V_2 = F_166 ( V_2 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 , F_4 ( V_2 ) -> V_160 * 4 ) ;
F_169 ( V_2 , V_321 ) ;
F_170 ( & V_321 -> V_329 , V_2 ) ;
V_14 -> V_212 = F_60 ( V_2 ) -> V_303 ;
V_14 -> V_330 = 1 ;
}
V_8 -> V_331 ( V_8 , 0 ) ;
F_67 ( V_321 ) ;
F_68 ( V_321 ) ;
F_64 ( V_106 -> V_8 == NULL ) ;
return 0 ;
}
int F_171 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_332 V_333 ;
struct V_334 V_335 ;
const T_6 * V_168 ;
struct V_105 * V_106 ;
struct V_219 * V_220 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_336 = F_60 ( V_2 ) -> V_144 ;
bool V_227 = false ;
struct V_33 V_34 ;
struct V_294 V_295 = { . V_111 = - 1 } ;
struct V_294 V_296 = { . V_111 = - 1 } ;
struct V_1 * V_318 ;
int V_337 ;
if ( F_79 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_338;
if ( F_172 ( V_8 ) && ! V_336 ) {
V_227 = F_108 ( V_8 , V_2 , L_7 ) ;
if ( ! V_227 )
goto V_338;
}
if ( F_173 ( V_8 ) && F_174 ( V_8 ) > 1 )
goto V_338;
V_106 = F_175 ( & V_339 ) ;
if ( ! V_106 )
goto V_338;
#ifdef F_78
F_53 ( V_106 ) -> V_340 = & V_341 ;
#endif
F_176 ( & V_335 ) ;
V_335 . V_72 = V_73 ;
V_335 . V_342 = V_14 -> V_19 . V_342 ;
F_177 ( V_2 , & V_335 , & V_168 , 0 ,
V_227 ? NULL : & V_295 ) ;
if ( V_335 . V_343 > 0 &&
V_335 . V_344 &&
! V_14 -> V_19 . V_345 &&
( V_346 > 0 ||
( V_14 -> V_347 != NULL &&
V_14 -> V_347 -> V_348 > 0 ) ) ) {
T_6 * V_349 ;
T_4 * V_350 = & V_333 . V_351 [ V_352 ] ;
int V_353 = V_335 . V_343 - V_354 ;
if ( F_178 ( & V_333 . V_351 [ 0 ] ) != 0 )
goto V_355;
* V_350 ++ ^= ( V_356 T_4 ) V_3 ;
* V_350 ++ ^= ( V_356 T_4 ) V_4 ;
V_349 = ( T_6 * ) V_350 ;
while ( V_353 -- > 0 )
* V_349 ++ ^= * V_168 ++ ;
V_227 = false ;
V_333 . V_345 = 0 ;
V_333 . V_343 = V_335 . V_343 ;
} else if ( ! V_14 -> V_19 . V_357 ) {
V_333 . V_345 = 1 ;
V_333 . V_343 = 0 ;
} else {
goto V_355;
}
V_333 . V_357 = V_14 -> V_19 . V_357 ;
if ( V_227 && ! V_335 . V_344 )
F_176 ( & V_335 ) ;
V_335 . V_358 = V_335 . V_344 ;
F_179 ( V_106 , & V_335 , V_2 ) ;
V_220 = F_98 ( V_106 ) ;
V_220 -> V_221 = V_3 ;
V_220 -> V_222 = V_4 ;
V_220 -> V_214 = F_14 ( V_8 ) -> V_189 ;
V_220 -> V_46 = F_111 ( V_2 ) ;
if ( F_180 ( V_8 , V_2 , V_106 ) )
goto V_359;
if ( ! V_227 || V_335 . V_358 )
F_181 ( V_106 , V_2 ) ;
if ( V_227 ) {
V_336 = F_182 ( V_8 , V_2 , & V_106 -> V_360 ) ;
V_106 -> V_361 = V_335 . V_358 ;
} else if ( ! V_336 ) {
if ( V_335 . V_344 &&
V_66 . V_67 &&
( V_68 = F_100 ( V_8 , & V_34 , V_106 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_183 ( V_106 , V_68 , true ) ) {
F_49 ( F_22 ( V_8 ) , V_362 ) ;
goto V_355;
}
}
else if ( ! V_230 &&
( V_363 - F_184 ( V_8 ) <
( V_363 >> 2 ) ) &&
! F_183 ( V_106 , V_68 , false ) ) {
F_185 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_355;
}
V_336 = F_1 ( V_2 ) ;
}
F_53 ( V_106 ) -> V_125 = V_336 ;
if ( V_68 == NULL ) {
V_68 = F_100 ( V_8 , & V_34 , V_106 ) ;
if ( V_68 == NULL )
goto V_359;
}
V_337 = F_152 ( V_8 , V_2 , V_106 , & V_295 , & V_296 ) ;
V_318 = F_101 ( V_8 , V_68 , V_106 ,
(struct V_215 * ) & V_333 ,
F_153 ( & V_296 ) ? & V_296 : NULL ) ;
if ( V_318 ) {
F_69 ( V_318 , V_220 -> V_221 , V_220 -> V_222 ) ;
F_102 ( V_318 , F_186 ( V_2 ) ) ;
} else
goto V_359;
if ( F_24 ( ! V_337 ) ) {
int V_37 ;
V_37 = F_103 ( V_318 , V_8 , V_220 -> V_221 ,
V_220 -> V_222 , V_220 -> V_46 ) ;
V_37 = F_104 ( V_37 ) ;
if ( V_37 || V_227 )
goto V_359;
F_53 ( V_106 ) -> V_223 = V_143 ;
F_53 ( V_106 ) -> V_326 = NULL ;
F_187 ( V_8 , V_106 , V_142 ) ;
if ( F_153 ( & V_295 ) && V_295 . V_111 != 0 )
F_49 ( F_22 ( V_8 ) ,
V_325 ) ;
} else if ( F_159 ( V_8 , V_2 , V_318 , V_106 ,
(struct V_215 * ) & V_333 ) )
goto V_359;
return 0 ;
V_355:
F_188 ( V_68 ) ;
V_359:
F_157 ( V_106 ) ;
V_338:
return 0 ;
}
struct V_7 * F_189 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_105 * V_106 ,
struct V_82 * V_68 )
{
struct V_219 * V_220 ;
struct V_28 * V_364 ;
struct V_13 * V_365 ;
struct V_7 * V_366 ;
#ifdef F_78
struct V_166 * V_167 ;
#endif
struct V_38 * V_39 ;
if ( F_173 ( V_8 ) )
goto V_367;
V_366 = F_190 ( V_8 , V_106 , V_2 ) ;
if ( ! V_366 )
goto V_368;
V_366 -> V_76 = V_77 ;
F_191 ( V_366 , V_2 ) ;
V_365 = F_7 ( V_366 ) ;
V_364 = F_14 ( V_366 ) ;
V_220 = F_98 ( V_106 ) ;
V_364 -> V_64 = V_220 -> V_222 ;
V_364 -> V_63 = V_220 -> V_221 ;
V_364 -> V_55 = V_220 -> V_221 ;
V_39 = V_220 -> V_46 ;
F_124 ( V_364 -> V_39 , V_39 ) ;
V_220 -> V_46 = NULL ;
V_364 -> V_369 = F_45 ( V_2 ) ;
V_364 -> V_370 = F_3 ( V_2 ) -> V_119 ;
V_364 -> V_371 = F_3 ( V_2 ) -> V_192 ;
F_26 ( V_366 ) -> V_70 = 0 ;
if ( V_39 )
F_26 ( V_366 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_364 -> V_78 = V_365 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_192 ( V_8 , V_366 , V_106 ) ;
if ( ! V_68 )
goto V_372;
} else {
}
F_30 ( V_366 , V_68 ) ;
F_163 ( V_366 ) ;
F_36 ( V_366 , F_34 ( V_68 ) ) ;
V_365 -> V_373 = F_193 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_342 &&
F_7 ( V_8 ) -> V_19 . V_342 < V_365 -> V_373 )
V_365 -> V_373 = F_7 ( V_8 ) -> V_19 . V_342 ;
F_194 ( V_366 ) ;
F_195 ( V_366 , V_106 ) ;
V_365 -> V_374 = V_106 -> V_322 ;
#ifdef F_78
V_167 = F_86 ( V_8 , (union V_182 * ) & V_364 -> V_64 ,
V_42 ) ;
if ( V_167 != NULL ) {
F_121 ( V_366 , (union V_182 * ) & V_364 -> V_64 ,
V_42 , V_167 -> V_167 , V_167 -> V_258 , V_239 ) ;
F_122 ( V_366 , V_260 ) ;
}
#endif
if ( F_196 ( V_8 , V_366 ) < 0 )
goto V_372;
F_197 ( V_366 , NULL ) ;
return V_366 ;
V_367:
F_49 ( F_22 ( V_8 ) , V_375 ) ;
V_368:
F_188 ( V_68 ) ;
exit:
F_49 ( F_22 ( V_8 ) , V_376 ) ;
return NULL ;
V_372:
F_198 ( V_366 ) ;
F_199 ( V_366 ) ;
F_67 ( V_366 ) ;
F_68 ( V_366 ) ;
goto exit;
}
static struct V_7 * F_200 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_7 * V_377 ;
struct V_105 * * V_149 ;
struct V_105 * V_106 = F_63 ( V_8 , & V_149 , V_100 -> V_6 ,
V_97 -> V_4 , V_97 -> V_3 ) ;
if ( V_106 )
return F_201 ( V_8 , V_2 , V_106 , V_149 , false ) ;
V_377 = F_202 ( F_22 ( V_8 ) , & V_113 , V_97 -> V_4 ,
V_100 -> V_6 , V_97 -> V_3 , V_100 -> V_5 , F_45 ( V_2 ) ) ;
if ( V_377 ) {
if ( V_377 -> V_85 != V_114 ) {
F_48 ( V_377 ) ;
return V_377 ;
}
F_46 ( F_47 ( V_377 ) ) ;
return NULL ;
}
#ifdef F_109
if ( ! V_100 -> V_177 )
V_8 = F_203 ( V_8 , V_2 , & ( F_112 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_10 F_204 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
if ( V_2 -> V_154 == V_378 ) {
if ( ! F_70 ( V_2 -> V_111 , V_97 -> V_4 ,
V_97 -> V_3 , V_2 -> V_161 ) ) {
V_2 -> V_154 = V_379 ;
return 0 ;
}
}
V_2 -> V_161 = F_89 ( V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_111 , V_57 , 0 ) ;
if ( V_2 -> V_111 <= 76 ) {
return F_205 ( V_2 ) ;
}
return 0 ;
}
int F_206 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_380 ;
#ifdef F_78
if ( F_150 ( V_8 , V_2 ) )
goto V_381;
#endif
if ( V_8 -> V_85 == V_382 ) {
struct V_82 * V_68 = V_8 -> V_383 ;
F_207 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_14 ( V_8 ) -> V_384 != V_2 -> V_385 ||
V_68 -> V_92 -> V_156 ( V_68 , 0 ) == NULL ) {
F_188 ( V_68 ) ;
V_8 -> V_383 = NULL ;
}
}
if ( F_208 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_111 ) ) {
V_380 = V_8 ;
goto V_386;
}
return 0 ;
}
if ( V_2 -> V_111 < F_209 ( V_2 ) || F_210 ( V_2 ) )
goto V_387;
if ( V_8 -> V_85 == V_86 ) {
struct V_7 * V_377 = F_200 ( V_8 , V_2 ) ;
if ( ! V_377 )
goto V_381;
if ( V_377 != V_8 ) {
F_207 ( V_377 , V_2 ) ;
if ( F_211 ( V_8 , V_377 , V_2 ) ) {
V_380 = V_377 ;
goto V_386;
}
return 0 ;
}
} else
F_207 ( V_8 , V_2 ) ;
if ( F_212 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_111 ) ) {
V_380 = V_8 ;
goto V_386;
}
return 0 ;
V_386:
F_77 ( V_380 , V_2 ) ;
V_381:
F_160 ( V_2 ) ;
return 0 ;
V_387:
F_91 ( F_22 ( V_8 ) , V_388 ) ;
goto V_381;
}
void F_213 ( struct V_1 * V_2 )
{
struct V_109 * V_109 = F_42 ( V_2 -> V_110 ) ;
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
if ( V_2 -> V_389 != V_390 )
return;
if ( ! F_76 ( V_2 , F_214 ( V_2 ) + sizeof( struct V_99 ) ) )
return;
V_97 = F_3 ( V_2 ) ;
V_100 = (struct V_99 * ) ( ( char * ) V_97 + F_214 ( V_2 ) ) ;
if ( V_100 -> V_160 < sizeof( struct V_99 ) / 4 )
return;
V_8 = F_215 ( V_109 , & V_113 ,
V_97 -> V_4 , V_100 -> V_6 ,
V_97 -> V_3 , F_84 ( V_100 -> V_5 ) ,
V_2 -> V_385 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_391 = V_392 ;
if ( V_8 -> V_85 != V_114 ) {
struct V_82 * V_68 = V_8 -> V_383 ;
if ( V_68 )
V_68 = F_216 ( V_68 , 0 ) ;
if ( V_68 &&
F_14 ( V_8 ) -> V_384 == V_2 -> V_385 )
F_217 ( V_2 , V_68 ) ;
}
}
}
int F_218 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
int V_393 ;
struct V_109 * V_109 = F_42 ( V_2 -> V_110 ) ;
if ( V_2 -> V_389 != V_390 )
goto V_394;
F_91 ( V_109 , V_395 ) ;
if ( ! F_76 ( V_2 , sizeof( struct V_99 ) ) )
goto V_394;
V_100 = F_4 ( V_2 ) ;
if ( V_100 -> V_160 < sizeof( struct V_99 ) / 4 )
goto V_396;
if ( ! F_76 ( V_2 , V_100 -> V_160 * 4 ) )
goto V_394;
if ( ! F_219 ( V_2 ) && F_204 ( V_2 ) )
goto V_396;
V_100 = F_4 ( V_2 ) ;
V_97 = F_3 ( V_2 ) ;
F_60 ( V_2 ) -> V_107 = F_51 ( V_100 -> V_107 ) ;
F_60 ( V_2 ) -> V_303 = ( F_60 ( V_2 ) -> V_107 + V_100 -> V_177 + V_100 -> V_178 +
V_2 -> V_111 - V_100 -> V_160 * 4 ) ;
F_60 ( V_2 ) -> V_176 = F_51 ( V_100 -> V_176 ) ;
F_60 ( V_2 ) -> V_144 = 0 ;
F_60 ( V_2 ) -> V_397 = F_220 ( V_97 ) ;
F_60 ( V_2 ) -> V_398 = 0 ;
V_8 = F_221 ( & V_113 , V_2 , V_100 -> V_6 , V_100 -> V_5 ) ;
if ( ! V_8 )
goto V_399;
V_400:
if ( V_8 -> V_85 == V_114 )
goto V_401;
if ( F_50 ( V_97 -> V_119 < F_14 ( V_8 ) -> V_120 ) ) {
F_49 ( V_109 , V_121 ) ;
goto V_402;
}
if ( ! F_222 ( V_8 , V_403 , V_2 ) )
goto V_402;
F_223 ( V_2 ) ;
if ( F_224 ( V_8 , V_2 ) )
goto V_402;
V_2 -> V_110 = NULL ;
F_225 ( V_8 ) ;
V_393 = 0 ;
if ( ! F_16 ( V_8 ) ) {
#ifdef F_226
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_404 . V_405 && V_14 -> V_404 . V_406 )
V_14 -> V_404 . V_405 = F_227 () ;
if ( V_14 -> V_404 . V_405 )
V_393 = F_206 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_228 ( V_8 , V_2 ) )
V_393 = F_206 ( V_8 , V_2 ) ;
}
} else if ( F_50 ( F_229 ( V_8 , V_2 ,
V_8 -> V_407 + V_8 -> V_408 ) ) ) {
F_67 ( V_8 ) ;
F_49 ( V_109 , V_409 ) ;
goto V_402;
}
F_67 ( V_8 ) ;
F_68 ( V_8 ) ;
return V_393 ;
V_399:
if ( ! F_222 ( NULL , V_403 , V_2 ) )
goto V_394;
if ( V_2 -> V_111 < ( V_100 -> V_160 << 2 ) || F_210 ( V_2 ) ) {
V_396:
F_91 ( V_109 , V_388 ) ;
} else {
F_77 ( NULL , V_2 ) ;
}
V_394:
F_160 ( V_2 ) ;
return 0 ;
V_402:
F_68 ( V_8 ) ;
goto V_394;
V_401:
if ( ! F_222 ( NULL , V_403 , V_2 ) ) {
F_46 ( F_47 ( V_8 ) ) ;
goto V_394;
}
if ( V_2 -> V_111 < ( V_100 -> V_160 << 2 ) || F_210 ( V_2 ) ) {
F_91 ( V_109 , V_388 ) ;
F_46 ( F_47 ( V_8 ) ) ;
goto V_394;
}
switch ( F_230 ( F_47 ( V_8 ) , V_2 , V_100 ) ) {
case V_410 : {
struct V_7 * V_411 = F_231 ( F_42 ( V_2 -> V_110 ) ,
& V_113 ,
V_97 -> V_3 , V_100 -> V_5 ,
F_45 ( V_2 ) ) ;
if ( V_411 ) {
F_232 ( F_47 ( V_8 ) , & V_66 ) ;
F_46 ( F_47 ( V_8 ) ) ;
V_8 = V_411 ;
goto V_400;
}
}
case V_412 :
F_95 ( V_8 , V_2 ) ;
break;
case V_413 :
goto V_399;
case V_414 : ;
}
goto V_394;
}
void F_191 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_83 ( V_2 ) ;
F_233 ( V_68 ) ;
V_8 -> V_383 = V_68 ;
F_14 ( V_8 ) -> V_384 = V_2 -> V_385 ;
}
static int F_234 ( struct V_7 * V_8 )
{
struct V_102 * V_103 = F_26 ( V_8 ) ;
F_235 ( V_8 ) ;
V_103 -> V_323 = & V_415 ;
#ifdef F_78
F_7 ( V_8 ) -> V_340 = & V_416 ;
#endif
return 0 ;
}
void F_236 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_198 ( V_8 ) ;
F_199 ( V_8 ) ;
F_237 ( V_8 ) ;
F_238 ( & V_14 -> V_417 ) ;
#ifdef F_78
if ( V_14 -> V_248 ) {
F_135 ( V_8 ) ;
F_133 ( V_14 -> V_248 , V_264 ) ;
V_14 -> V_248 = NULL ;
}
#endif
#ifdef F_226
F_238 ( & V_8 -> V_418 ) ;
#endif
F_238 ( & V_14 -> V_404 . V_419 ) ;
if ( F_26 ( V_8 ) -> V_420 )
F_239 ( V_8 ) ;
if ( V_14 -> V_347 != NULL ) {
F_240 ( & V_14 -> V_347 -> V_421 ,
V_422 ) ;
V_14 -> V_347 = NULL ;
}
F_58 ( V_14 -> V_122 != NULL ) ;
F_241 ( V_14 ) ;
F_242 ( V_8 ) ;
F_243 ( V_8 ) ;
}
static inline struct V_204 * F_244 ( struct V_423 * V_158 )
{
return F_245 ( V_158 ) ? NULL :
F_246 ( V_158 -> V_424 , struct V_204 , V_425 ) ;
}
static inline struct V_204 * F_247 ( struct V_204 * V_205 )
{
return ! F_248 ( V_205 -> V_425 . V_426 ) ?
F_249 ( V_205 -> V_425 . V_426 , F_250 ( * V_205 ) , V_425 ) : NULL ;
}
static void * F_251 ( struct V_427 * V_107 , void * V_428 )
{
struct V_102 * V_103 ;
struct V_429 * V_261 ;
struct V_7 * V_8 = V_428 ;
struct V_430 * V_431 ;
struct V_432 * V_433 = V_107 -> V_434 ;
struct V_109 * V_109 = F_252 ( V_107 ) ;
if ( ! V_8 ) {
V_431 = & V_113 . V_435 [ V_433 -> V_436 ] ;
F_253 ( & V_431 -> V_309 ) ;
V_8 = F_254 ( & V_431 -> V_158 ) ;
V_433 -> V_203 = 0 ;
goto V_437;
}
V_431 = & V_113 . V_435 [ V_433 -> V_436 ] ;
++ V_433 -> V_438 ;
++ V_433 -> V_203 ;
if ( V_433 -> V_439 == V_440 ) {
struct V_105 * V_106 = V_428 ;
V_103 = F_26 ( V_433 -> V_441 ) ;
V_106 = V_106 -> V_313 ;
while ( 1 ) {
while ( V_106 ) {
if ( V_106 -> V_442 -> V_241 == V_433 -> V_241 ) {
V_428 = V_106 ;
goto V_118;
}
V_106 = V_106 -> V_313 ;
}
if ( ++ V_433 -> V_443 >= V_103 -> V_233 . V_234 -> V_444 )
break;
V_445:
V_106 = V_103 -> V_233 . V_234 -> V_446 [ V_433 -> V_443 ] ;
}
V_8 = F_255 ( V_433 -> V_441 ) ;
V_433 -> V_439 = V_447 ;
F_256 ( & V_103 -> V_233 . V_448 ) ;
} else {
V_103 = F_26 ( V_8 ) ;
F_257 ( & V_103 -> V_233 . V_448 ) ;
if ( F_258 ( & V_103 -> V_233 ) )
goto V_449;
F_256 ( & V_103 -> V_233 . V_448 ) ;
V_8 = F_255 ( V_8 ) ;
}
V_437:
F_259 (sk, node) {
if ( ! F_260 ( F_22 ( V_8 ) , V_109 ) )
continue;
if ( V_8 -> V_450 == V_433 -> V_241 ) {
V_428 = V_8 ;
goto V_118;
}
V_103 = F_26 ( V_8 ) ;
F_257 ( & V_103 -> V_233 . V_448 ) ;
if ( F_258 ( & V_103 -> V_233 ) ) {
V_449:
V_433 -> V_451 = F_261 ( V_8 ) ;
V_433 -> V_441 = V_8 ;
V_433 -> V_439 = V_440 ;
V_433 -> V_443 = 0 ;
goto V_445;
}
F_256 ( & V_103 -> V_233 . V_448 ) ;
}
F_262 ( & V_431 -> V_309 ) ;
V_433 -> V_203 = 0 ;
if ( ++ V_433 -> V_436 < V_452 ) {
V_431 = & V_113 . V_435 [ V_433 -> V_436 ] ;
F_253 ( & V_431 -> V_309 ) ;
V_8 = F_254 ( & V_431 -> V_158 ) ;
goto V_437;
}
V_428 = NULL ;
V_118:
return V_428 ;
}
static void * F_263 ( struct V_427 * V_107 , T_11 * V_243 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
void * V_453 ;
V_433 -> V_436 = 0 ;
V_433 -> V_203 = 0 ;
V_453 = F_251 ( V_107 , NULL ) ;
while ( V_453 && * V_243 ) {
V_453 = F_251 ( V_107 , V_453 ) ;
-- * V_243 ;
}
return V_453 ;
}
static inline bool F_264 ( struct V_432 * V_433 )
{
return F_245 ( & V_113 . V_454 [ V_433 -> V_436 ] . V_455 ) &&
F_245 ( & V_113 . V_454 [ V_433 -> V_436 ] . V_456 ) ;
}
static void * F_265 ( struct V_427 * V_107 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
struct V_109 * V_109 = F_252 ( V_107 ) ;
void * V_453 = NULL ;
V_433 -> V_203 = 0 ;
for (; V_433 -> V_436 <= V_113 . V_457 ; ++ V_433 -> V_436 ) {
struct V_7 * V_8 ;
struct V_429 * V_261 ;
struct V_204 * V_205 ;
T_12 * V_309 = F_266 ( & V_113 , V_433 -> V_436 ) ;
if ( F_264 ( V_433 ) )
continue;
F_253 ( V_309 ) ;
F_267 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_450 != V_433 -> V_241 ||
! F_260 ( F_22 ( V_8 ) , V_109 ) ) {
continue;
}
V_453 = V_8 ;
goto V_118;
}
V_433 -> V_439 = V_458 ;
F_268 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_205 -> V_459 != V_433 -> V_241 ||
! F_260 ( F_269 ( V_205 ) , V_109 ) ) {
continue;
}
V_453 = V_205 ;
goto V_118;
}
F_262 ( V_309 ) ;
V_433 -> V_439 = V_460 ;
}
V_118:
return V_453 ;
}
static void * F_270 ( struct V_427 * V_107 , void * V_428 )
{
struct V_7 * V_8 = V_428 ;
struct V_204 * V_205 ;
struct V_429 * V_261 ;
struct V_432 * V_433 = V_107 -> V_434 ;
struct V_109 * V_109 = F_252 ( V_107 ) ;
++ V_433 -> V_438 ;
++ V_433 -> V_203 ;
if ( V_433 -> V_439 == V_458 ) {
V_205 = V_428 ;
V_205 = F_247 ( V_205 ) ;
V_461:
while ( V_205 && ( V_205 -> V_459 != V_433 -> V_241 || ! F_260 ( F_269 ( V_205 ) , V_109 ) ) ) {
V_205 = F_247 ( V_205 ) ;
}
if ( V_205 ) {
V_428 = V_205 ;
goto V_118;
}
F_262 ( F_266 ( & V_113 , V_433 -> V_436 ) ) ;
V_433 -> V_439 = V_460 ;
V_433 -> V_203 = 0 ;
while ( ++ V_433 -> V_436 <= V_113 . V_457 &&
F_264 ( V_433 ) )
;
if ( V_433 -> V_436 > V_113 . V_457 )
return NULL ;
F_253 ( F_266 ( & V_113 , V_433 -> V_436 ) ) ;
V_8 = F_254 ( & V_113 . V_454 [ V_433 -> V_436 ] . V_455 ) ;
} else
V_8 = F_255 ( V_8 ) ;
F_259 (sk, node) {
if ( V_8 -> V_450 == V_433 -> V_241 && F_260 ( F_22 ( V_8 ) , V_109 ) )
goto V_462;
}
V_433 -> V_439 = V_458 ;
V_205 = F_244 ( & V_113 . V_454 [ V_433 -> V_436 ] . V_456 ) ;
goto V_461;
V_462:
V_428 = V_8 ;
V_118:
return V_428 ;
}
static void * F_271 ( struct V_427 * V_107 , T_11 V_243 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
void * V_453 ;
V_433 -> V_436 = 0 ;
V_453 = F_265 ( V_107 ) ;
while ( V_453 && V_243 ) {
V_453 = F_270 ( V_107 , V_453 ) ;
-- V_243 ;
}
return V_453 ;
}
static void * F_272 ( struct V_427 * V_107 , T_11 V_243 )
{
void * V_453 ;
struct V_432 * V_433 = V_107 -> V_434 ;
V_433 -> V_439 = V_447 ;
V_453 = F_263 ( V_107 , & V_243 ) ;
if ( ! V_453 ) {
V_433 -> V_439 = V_460 ;
V_453 = F_271 ( V_107 , V_243 ) ;
}
return V_453 ;
}
static void * F_273 ( struct V_427 * V_107 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
int V_203 = V_433 -> V_203 ;
int V_463 = V_433 -> V_438 ;
void * V_453 = NULL ;
switch ( V_433 -> V_439 ) {
case V_440 :
case V_447 :
if ( V_433 -> V_436 >= V_452 )
break;
V_433 -> V_439 = V_447 ;
V_453 = F_251 ( V_107 , NULL ) ;
while ( V_203 -- && V_453 )
V_453 = F_251 ( V_107 , V_453 ) ;
if ( V_453 )
break;
V_433 -> V_436 = 0 ;
case V_460 :
case V_458 :
V_433 -> V_439 = V_460 ;
if ( V_433 -> V_436 > V_113 . V_457 )
break;
V_453 = F_265 ( V_107 ) ;
while ( V_203 -- && V_453 )
V_453 = F_270 ( V_107 , V_453 ) ;
}
V_433 -> V_438 = V_463 ;
return V_453 ;
}
static void * F_274 ( struct V_427 * V_107 , T_11 * V_243 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
void * V_453 ;
if ( * V_243 && * V_243 == V_433 -> V_464 ) {
V_453 = F_273 ( V_107 ) ;
if ( V_453 )
goto V_118;
}
V_433 -> V_439 = V_447 ;
V_433 -> V_438 = 0 ;
V_433 -> V_436 = 0 ;
V_433 -> V_203 = 0 ;
V_453 = * V_243 ? F_272 ( V_107 , * V_243 - 1 ) : V_465 ;
V_118:
V_433 -> V_464 = * V_243 ;
return V_453 ;
}
static void * F_275 ( struct V_427 * V_107 , void * V_466 , T_11 * V_243 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
void * V_453 = NULL ;
if ( V_466 == V_465 ) {
V_453 = F_272 ( V_107 , 0 ) ;
goto V_118;
}
switch ( V_433 -> V_439 ) {
case V_440 :
case V_447 :
V_453 = F_251 ( V_107 , V_466 ) ;
if ( ! V_453 ) {
V_433 -> V_439 = V_460 ;
V_433 -> V_436 = 0 ;
V_433 -> V_203 = 0 ;
V_453 = F_265 ( V_107 ) ;
}
break;
case V_460 :
case V_458 :
V_453 = F_270 ( V_107 , V_466 ) ;
break;
}
V_118:
++ * V_243 ;
V_433 -> V_464 = * V_243 ;
return V_453 ;
}
static void F_276 ( struct V_427 * V_107 , void * V_466 )
{
struct V_432 * V_433 = V_107 -> V_434 ;
switch ( V_433 -> V_439 ) {
case V_440 :
if ( V_466 ) {
struct V_102 * V_103 = F_26 ( V_433 -> V_441 ) ;
F_256 ( & V_103 -> V_233 . V_448 ) ;
}
case V_447 :
if ( V_466 != V_465 )
F_262 ( & V_113 . V_435 [ V_433 -> V_436 ] . V_309 ) ;
break;
case V_458 :
case V_460 :
if ( V_466 )
F_262 ( F_266 ( & V_113 , V_433 -> V_436 ) ) ;
break;
}
}
int F_277 ( struct V_467 * V_467 , struct V_468 * V_468 )
{
struct V_469 * V_470 = F_278 ( V_467 ) -> V_98 ;
struct V_432 * V_471 ;
int V_37 ;
V_37 = F_279 ( V_467 , V_468 , & V_470 -> V_472 ,
sizeof( struct V_432 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_471 = ( (struct V_427 * ) V_468 -> V_473 ) -> V_434 ;
V_471 -> V_241 = V_470 -> V_241 ;
V_471 -> V_464 = 0 ;
return 0 ;
}
int F_280 ( struct V_109 * V_109 , struct V_469 * V_470 )
{
int V_453 = 0 ;
struct V_474 * V_475 ;
V_470 -> V_472 . V_476 = F_274 ;
V_470 -> V_472 . V_426 = F_275 ;
V_470 -> V_472 . V_477 = F_276 ;
V_475 = F_281 ( V_470 -> V_478 , V_479 , V_109 -> V_480 ,
V_470 -> V_481 , V_470 ) ;
if ( ! V_475 )
V_453 = - V_259 ;
return V_453 ;
}
void F_282 ( struct V_109 * V_109 , struct V_469 * V_470 )
{
F_283 ( V_109 , V_470 -> V_478 ) ;
}
static void F_284 ( const struct V_7 * V_8 , const struct V_105 * V_106 ,
struct V_427 * V_482 , int V_483 , T_13 V_451 , int * V_111 )
{
const struct V_219 * V_220 = F_98 ( V_106 ) ;
long V_484 = V_106 -> V_311 - V_79 ;
F_285 ( V_482 , L_9
L_10 ,
V_483 ,
V_220 -> V_221 ,
F_84 ( F_14 ( V_8 ) -> V_49 ) ,
V_220 -> V_222 ,
F_84 ( V_220 -> V_485 ) ,
V_150 ,
0 , 0 ,
1 ,
F_286 ( V_484 ) ,
V_106 -> V_322 ,
F_287 ( F_288 ( V_482 ) , V_451 ) ,
0 ,
0 ,
F_289 ( & V_8 -> V_486 ) ,
V_106 ,
V_111 ) ;
}
static void F_290 ( struct V_7 * V_8 , struct V_427 * V_482 , int V_483 , int * V_111 )
{
int V_487 ;
unsigned long V_488 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_102 * V_103 = F_26 ( V_8 ) ;
const struct V_28 * V_29 = F_14 ( V_8 ) ;
struct V_298 * V_299 = V_103 -> V_233 . V_299 ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_489 = V_29 -> V_63 ;
T_14 V_490 = F_84 ( V_29 -> V_69 ) ;
T_14 V_491 = F_84 ( V_29 -> V_49 ) ;
int V_492 ;
if ( V_103 -> V_493 == V_145 ) {
V_487 = 1 ;
V_488 = V_103 -> V_494 ;
} else if ( V_103 -> V_493 == V_495 ) {
V_487 = 4 ;
V_488 = V_103 -> V_494 ;
} else if ( F_291 ( & V_8 -> V_496 ) ) {
V_487 = 2 ;
V_488 = V_8 -> V_496 . V_311 ;
} else {
V_487 = 0 ;
V_488 = V_79 ;
}
if ( V_8 -> V_85 == V_86 )
V_492 = V_8 -> V_497 ;
else
V_492 = F_292 ( int , V_14 -> V_212 - V_14 -> V_498 , 0 ) ;
F_285 ( V_482 , L_11
L_12 ,
V_483 , V_489 , V_491 , V_5 , V_490 , V_8 -> V_85 ,
V_14 -> V_17 - V_14 -> V_123 ,
V_492 ,
V_487 ,
F_286 ( V_488 - V_79 ) ,
V_103 -> V_138 ,
F_287 ( F_288 ( V_482 ) , F_261 ( V_8 ) ) ,
V_103 -> V_499 ,
F_293 ( V_8 ) ,
F_289 ( & V_8 -> V_486 ) , V_8 ,
F_294 ( V_103 -> V_140 ) ,
F_294 ( V_103 -> V_500 . V_501 ) ,
( V_103 -> V_500 . V_502 << 1 ) | V_103 -> V_500 . V_503 ,
V_14 -> V_504 ,
V_8 -> V_85 == V_86 ?
( V_299 ? V_299 -> V_306 : 0 ) :
( F_295 ( V_14 ) ? - 1 : V_14 -> V_505 ) ,
V_111 ) ;
}
static void F_296 ( const struct V_204 * V_205 ,
struct V_427 * V_482 , int V_483 , int * V_111 )
{
T_3 V_5 , V_489 ;
T_14 V_490 , V_491 ;
long V_484 = V_205 -> V_506 - V_79 ;
V_5 = V_205 -> V_507 ;
V_489 = V_205 -> V_508 ;
V_490 = F_84 ( V_205 -> V_509 ) ;
V_491 = F_84 ( V_205 -> V_510 ) ;
F_285 ( V_482 , L_9
L_13 ,
V_483 , V_489 , V_491 , V_5 , V_490 , V_205 -> V_511 , 0 , 0 ,
3 , F_286 ( V_484 ) , 0 , 0 , 0 , 0 ,
F_289 ( & V_205 -> V_512 ) , V_205 , V_111 ) ;
}
static int F_297 ( struct V_427 * V_107 , void * V_466 )
{
struct V_432 * V_433 ;
int V_111 ;
if ( V_466 == V_465 ) {
F_285 ( V_107 , L_14 , V_513 - 1 ,
L_15
L_16
L_17 ) ;
goto V_118;
}
V_433 = V_107 -> V_434 ;
switch ( V_433 -> V_439 ) {
case V_447 :
case V_460 :
F_290 ( V_466 , V_107 , V_433 -> V_438 , & V_111 ) ;
break;
case V_440 :
F_284 ( V_433 -> V_441 , V_466 , V_107 , V_433 -> V_438 , V_433 -> V_451 , & V_111 ) ;
break;
case V_458 :
F_296 ( V_466 , V_107 , V_433 -> V_438 , & V_111 ) ;
break;
}
F_285 ( V_107 , L_18 , V_513 - 1 - V_111 , L_6 ) ;
V_118:
return 0 ;
}
static int T_15 F_298 ( struct V_109 * V_109 )
{
return F_280 ( V_109 , & V_514 ) ;
}
static void T_16 F_299 ( struct V_109 * V_109 )
{
F_282 ( V_109 , & V_514 ) ;
}
int T_17 F_300 ( void )
{
return F_301 ( & V_515 ) ;
}
void F_302 ( void )
{
F_303 ( & V_515 ) ;
}
struct V_1 * * F_304 ( struct V_1 * * V_158 , struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_305 ( V_2 ) ;
T_18 V_516 ;
T_10 V_517 ;
switch ( V_2 -> V_154 ) {
case V_378 :
if ( ! F_70 ( F_306 ( V_2 ) , V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_161 ) ) {
V_2 -> V_154 = V_379 ;
break;
}
V_518:
F_307 ( V_2 ) -> V_518 = 1 ;
return NULL ;
case V_519 :
V_516 = F_89 ( V_97 -> V_4 , V_97 -> V_3 ,
F_306 ( V_2 ) , V_57 , 0 ) ;
V_517 = F_308 ( F_309 ( V_2 ,
F_310 ( V_2 ) ,
F_306 ( V_2 ) ,
V_516 ) ) ;
if ( V_517 )
goto V_518;
V_2 -> V_154 = V_379 ;
break;
}
return F_311 ( V_158 , V_2 ) ;
}
int F_312 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_99 * V_100 = F_4 ( V_2 ) ;
V_100 -> V_156 = ~ F_70 ( V_2 -> V_111 - F_313 ( V_2 ) ,
V_97 -> V_4 , V_97 -> V_3 , 0 ) ;
F_314 ( V_2 ) -> V_520 = V_77 ;
return F_315 ( V_2 ) ;
}
static int T_15 F_316 ( struct V_109 * V_109 )
{
return 0 ;
}
static void T_16 F_317 ( struct V_109 * V_109 )
{
}
static void T_16 F_318 ( struct V_521 * V_522 )
{
F_319 ( & V_113 , & V_66 , V_42 ) ;
}
void T_17 F_320 ( void )
{
F_321 ( & V_113 ) ;
if ( F_301 ( & V_523 ) )
F_322 ( L_19 ) ;
}
