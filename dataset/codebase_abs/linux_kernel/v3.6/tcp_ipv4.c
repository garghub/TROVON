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
T_1 V_105 ;
T_1 V_106 ;
int V_37 ;
struct V_107 * V_107 = F_42 ( V_94 -> V_108 ) ;
if ( V_94 -> V_109 < ( V_97 -> V_101 << 2 ) + 8 ) {
F_43 ( V_107 , V_110 ) ;
return;
}
V_8 = F_44 ( V_107 , & V_111 , V_97 -> V_3 , V_100 -> V_5 ,
V_97 -> V_4 , V_100 -> V_6 , F_45 ( V_94 ) ) ;
if ( ! V_8 ) {
F_43 ( V_107 , V_110 ) ;
return;
}
if ( V_8 -> V_85 == V_112 ) {
F_46 ( F_47 ( V_8 ) ) ;
return;
}
F_48 ( V_8 ) ;
if ( F_16 ( V_8 ) &&
type != V_113 &&
V_104 != V_114 )
F_49 ( V_107 , V_115 ) ;
if ( V_8 -> V_85 == V_80 )
goto V_116;
if ( F_50 ( V_97 -> V_117 < F_14 ( V_8 ) -> V_118 ) ) {
F_49 ( V_107 , V_119 ) ;
goto V_116;
}
V_103 = F_26 ( V_8 ) ;
V_14 = F_7 ( V_8 ) ;
V_105 = F_51 ( V_100 -> V_105 ) ;
if ( V_8 -> V_85 != V_86 &&
! F_52 ( V_105 , V_14 -> V_120 , V_14 -> V_121 ) ) {
F_49 ( V_107 , V_122 ) ;
goto V_116;
}
switch ( type ) {
case V_123 :
F_38 ( V_94 , V_8 ) ;
goto V_116;
case V_124 :
goto V_116;
case V_125 :
V_37 = V_126 ;
break;
case V_113 :
if ( V_104 > V_127 )
goto V_116;
if ( V_104 == V_114 ) {
V_14 -> V_84 = V_95 ;
if ( ! F_16 ( V_8 ) ) {
F_32 ( V_8 ) ;
} else {
if ( ! F_53 ( V_128 , & V_14 -> V_129 ) )
F_9 ( V_8 ) ;
}
goto V_116;
}
V_37 = V_130 [ V_104 ] . V_131 ;
if ( V_104 != V_132 && V_104 != V_133 )
break;
if ( V_105 != V_14 -> V_120 || ! V_103 -> V_134 ||
! V_103 -> V_135 )
break;
if ( F_16 ( V_8 ) )
break;
V_103 -> V_135 -- ;
F_26 ( V_8 ) -> V_136 = ( V_14 -> V_137 ? F_54 ( V_14 ) :
V_138 ) << V_103 -> V_135 ;
F_55 ( V_8 ) ;
V_2 = F_56 ( V_8 ) ;
F_57 ( ! V_2 ) ;
V_106 = V_103 -> V_136 - F_58 ( V_103 -> V_136 ,
V_139 - F_59 ( V_2 ) -> V_140 ) ;
if ( V_106 ) {
F_60 ( V_8 , V_141 ,
V_106 , V_142 ) ;
} else {
F_61 ( V_8 ) ;
}
break;
case V_143 :
V_37 = V_144 ;
break;
default:
goto V_116;
}
switch ( V_8 -> V_85 ) {
struct V_145 * V_146 , * * V_147 ;
case V_86 :
if ( F_16 ( V_8 ) )
goto V_116;
V_146 = F_62 ( V_8 , & V_147 , V_100 -> V_5 ,
V_97 -> V_3 , V_97 -> V_4 ) ;
if ( ! V_146 )
goto V_116;
F_63 ( V_146 -> V_8 ) ;
if ( V_105 != F_64 ( V_146 ) -> V_148 ) {
F_49 ( V_107 , V_122 ) ;
goto V_116;
}
F_65 ( V_8 , V_146 , V_147 ) ;
goto V_116;
case V_74 :
case V_149 :
if ( ! F_16 ( V_8 ) ) {
V_8 -> V_150 = V_37 ;
V_8 -> V_151 ( V_8 ) ;
F_66 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
goto V_116;
}
V_29 = F_14 ( V_8 ) ;
if ( ! F_16 ( V_8 ) && V_29 -> V_152 ) {
V_8 -> V_150 = V_37 ;
V_8 -> V_151 ( V_8 ) ;
} else {
V_8 -> V_87 = V_37 ;
}
V_116:
F_67 ( V_8 ) ;
F_68 ( V_8 ) ;
}
static void F_69 ( struct V_1 * V_2 ,
T_3 V_4 , T_3 V_3 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
if ( V_2 -> V_153 == V_154 ) {
V_100 -> V_155 = ~ F_70 ( V_2 -> V_109 , V_4 , V_3 , 0 ) ;
V_2 -> V_156 = F_71 ( V_2 ) - V_2 -> V_157 ;
V_2 -> V_158 = F_72 ( struct V_99 , V_155 ) ;
} else {
V_100 -> V_155 = F_70 ( V_2 -> V_109 , V_4 , V_3 ,
F_73 ( V_100 ,
V_100 -> V_159 << 2 ,
V_2 -> V_160 ) ) ;
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
V_100 -> V_155 = 0 ;
V_2 -> V_153 = V_154 ;
F_69 ( V_2 , V_97 -> V_4 , V_97 -> V_3 ) ;
return 0 ;
}
static void F_77 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
#ifdef F_78
T_3 V_46 [ ( V_161 >> 2 ) ] ;
#endif
} V_162 ;
struct V_163 V_164 ;
#ifdef F_78
struct V_165 * V_166 ;
const T_5 * V_167 = NULL ;
unsigned char V_168 [ 16 ] ;
int V_169 ;
struct V_7 * V_170 = NULL ;
#endif
struct V_107 * V_107 ;
if ( V_100 -> V_171 )
return;
if ( F_79 ( V_2 ) -> V_172 != V_173 )
return;
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_100 . V_5 = V_100 -> V_6 ;
V_162 . V_100 . V_6 = V_100 -> V_5 ;
V_162 . V_100 . V_159 = sizeof( struct V_99 ) / 4 ;
V_162 . V_100 . V_171 = 1 ;
if ( V_100 -> V_174 ) {
V_162 . V_100 . V_105 = V_100 -> V_175 ;
} else {
V_162 . V_100 . V_174 = 1 ;
V_162 . V_100 . V_175 = F_80 ( F_51 ( V_100 -> V_105 ) + V_100 -> V_176 + V_100 -> V_177 +
V_2 -> V_109 - ( V_100 -> V_159 << 2 ) ) ;
}
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_178 [ 0 ] . V_179 = ( unsigned char * ) & V_162 ;
V_164 . V_178 [ 0 ] . V_180 = sizeof( V_162 . V_100 ) ;
#ifdef F_78
V_167 = F_81 ( V_100 ) ;
if ( ! V_8 && V_167 ) {
V_170 = F_82 ( F_42 ( F_83 ( V_2 ) -> V_108 ) ,
& V_111 , F_3 ( V_2 ) -> V_3 ,
F_84 ( V_100 -> V_6 ) , F_45 ( V_2 ) ) ;
if ( ! V_170 )
return;
F_85 () ;
V_166 = F_86 ( V_170 , (union V_181 * )
& F_3 ( V_2 ) -> V_4 , V_42 ) ;
if ( ! V_166 )
goto V_182;
V_169 = F_87 ( V_168 , V_166 , NULL , NULL , V_2 ) ;
if ( V_169 || memcmp ( V_167 , V_168 , 16 ) != 0 )
goto V_182;
} else {
V_166 = V_8 ? F_86 ( V_8 , (union V_181 * )
& F_3 ( V_2 ) -> V_4 ,
V_42 ) : NULL ;
}
if ( V_166 ) {
V_162 . V_46 [ 0 ] = F_80 ( ( V_183 << 24 ) |
( V_183 << 16 ) |
( V_184 << 8 ) |
V_185 ) ;
V_164 . V_178 [ 0 ] . V_180 += V_161 ;
V_162 . V_100 . V_159 = V_164 . V_178 [ 0 ] . V_180 / 4 ;
F_88 ( ( T_5 * ) & V_162 . V_46 [ 1 ] ,
V_166 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_162 . V_100 ) ;
}
#endif
V_164 . V_160 = F_89 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_164 . V_178 [ 0 ] . V_180 , V_57 , 0 ) ;
V_164 . V_186 = F_72 ( struct V_99 , V_155 ) / 2 ;
V_164 . V_187 = ( V_8 && F_14 ( V_8 ) -> V_188 ) ? V_189 : 0 ;
V_164 . V_190 = V_8 ? V_8 -> V_56 : F_45 ( V_2 ) ;
V_107 = F_42 ( F_83 ( V_2 ) -> V_108 ) ;
V_164 . V_191 = F_3 ( V_2 ) -> V_191 ;
F_90 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 , V_164 . V_178 [ 0 ] . V_180 ) ;
F_91 ( V_107 , V_192 ) ;
F_91 ( V_107 , V_193 ) ;
#ifdef F_78
V_182:
if ( V_170 ) {
F_92 () ;
F_68 ( V_170 ) ;
}
#endif
}
static void F_93 ( struct V_1 * V_2 , T_4 V_105 , T_4 V_174 ,
T_4 V_194 , T_4 V_195 , int V_196 ,
struct V_165 * V_166 ,
int V_197 , T_6 V_191 )
{
const struct V_99 * V_100 = F_4 ( V_2 ) ;
struct {
struct V_99 V_100 ;
T_3 V_46 [ ( V_198 >> 2 )
#ifdef F_78
+ ( V_161 >> 2 )
#endif
] ;
} V_162 ;
struct V_163 V_164 ;
struct V_107 * V_107 = F_42 ( F_83 ( V_2 ) -> V_108 ) ;
memset ( & V_162 . V_100 , 0 , sizeof( struct V_99 ) ) ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_164 . V_178 [ 0 ] . V_179 = ( unsigned char * ) & V_162 ;
V_164 . V_178 [ 0 ] . V_180 = sizeof( V_162 . V_100 ) ;
if ( V_195 ) {
V_162 . V_46 [ 0 ] = F_80 ( ( V_183 << 24 ) | ( V_183 << 16 ) |
( V_199 << 8 ) |
V_200 ) ;
V_162 . V_46 [ 1 ] = F_80 ( V_139 ) ;
V_162 . V_46 [ 2 ] = F_80 ( V_195 ) ;
V_164 . V_178 [ 0 ] . V_180 += V_198 ;
}
V_162 . V_100 . V_5 = V_100 -> V_6 ;
V_162 . V_100 . V_6 = V_100 -> V_5 ;
V_162 . V_100 . V_159 = V_164 . V_178 [ 0 ] . V_180 / 4 ;
V_162 . V_100 . V_105 = F_80 ( V_105 ) ;
V_162 . V_100 . V_175 = F_80 ( V_174 ) ;
V_162 . V_100 . V_174 = 1 ;
V_162 . V_100 . V_201 = F_94 ( V_194 ) ;
#ifdef F_78
if ( V_166 ) {
int V_202 = ( V_195 ) ? 3 : 0 ;
V_162 . V_46 [ V_202 ++ ] = F_80 ( ( V_183 << 24 ) |
( V_183 << 16 ) |
( V_184 << 8 ) |
V_185 ) ;
V_164 . V_178 [ 0 ] . V_180 += V_161 ;
V_162 . V_100 . V_159 = V_164 . V_178 [ 0 ] . V_180 / 4 ;
F_88 ( ( T_5 * ) & V_162 . V_46 [ V_202 ] ,
V_166 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_162 . V_100 ) ;
}
#endif
V_164 . V_187 = V_197 ;
V_164 . V_160 = F_89 ( F_3 ( V_2 ) -> V_3 ,
F_3 ( V_2 ) -> V_4 ,
V_164 . V_178 [ 0 ] . V_180 , V_57 , 0 ) ;
V_164 . V_186 = F_72 ( struct V_99 , V_155 ) / 2 ;
if ( V_196 )
V_164 . V_190 = V_196 ;
V_164 . V_191 = V_191 ;
F_90 ( V_107 , V_2 , F_3 ( V_2 ) -> V_4 ,
F_3 ( V_2 ) -> V_3 , & V_164 , V_164 . V_178 [ 0 ] . V_180 ) ;
F_91 ( V_107 , V_192 ) ;
}
static void F_95 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_203 * V_204 = F_47 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_8 ) ;
F_93 ( V_2 , V_12 -> V_18 , V_12 -> V_205 ,
V_12 -> V_206 >> V_204 -> V_207 ,
V_12 -> V_21 ,
V_204 -> V_208 ,
F_96 ( V_12 ) ,
V_204 -> V_209 ? V_189 : 0 ,
V_204 -> V_210
) ;
F_46 ( V_204 ) ;
}
static void F_97 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_145 * V_146 )
{
F_93 ( V_2 , F_64 ( V_146 ) -> V_148 + 1 ,
F_64 ( V_146 ) -> V_211 + 1 , V_146 -> V_212 ,
V_146 -> V_20 ,
0 ,
F_86 ( V_8 , (union V_181 * ) & F_3 ( V_2 ) -> V_3 ,
V_42 ) ,
F_98 ( V_146 ) -> V_213 ? V_189 : 0 ,
F_3 ( V_2 ) -> V_191 ) ;
}
static int F_99 ( struct V_7 * V_8 , struct V_82 * V_68 ,
struct V_145 * V_146 ,
struct V_214 * V_215 ,
T_7 V_216 ,
bool V_217 )
{
const struct V_218 * V_219 = F_98 ( V_146 ) ;
struct V_33 V_34 ;
int V_37 = - 1 ;
struct V_1 * V_2 ;
if ( ! V_68 && ( V_68 = F_100 ( V_8 , & V_34 , V_146 ) ) == NULL )
return - 1 ;
V_2 = F_101 ( V_8 , V_68 , V_146 , V_215 ) ;
if ( V_2 ) {
F_69 ( V_2 , V_219 -> V_220 , V_219 -> V_221 ) ;
F_102 ( V_2 , V_216 ) ;
V_37 = F_103 ( V_2 , V_8 , V_219 -> V_220 ,
V_219 -> V_221 ,
V_219 -> V_46 ) ;
V_37 = F_104 ( V_37 ) ;
}
return V_37 ;
}
static int F_105 ( struct V_7 * V_8 , struct V_145 * V_146 ,
struct V_214 * V_215 )
{
F_91 ( F_22 ( V_8 ) , V_222 ) ;
return F_99 ( V_8 , NULL , V_146 , V_215 , 0 , false ) ;
}
static void F_106 ( struct V_145 * V_146 )
{
F_107 ( F_98 ( V_146 ) -> V_46 ) ;
}
bool F_108 ( struct V_7 * V_8 ,
const struct V_1 * V_2 ,
const char * V_223 )
{
const char * V_224 = L_1 ;
bool V_225 = false ;
struct V_226 * V_227 ;
#ifdef F_109
if ( V_228 ) {
V_224 = L_2 ;
V_225 = true ;
F_49 ( F_22 ( V_8 ) , V_229 ) ;
} else
#endif
F_49 ( F_22 ( V_8 ) , V_230 ) ;
V_227 = F_26 ( V_8 ) -> V_231 . V_232 ;
if ( ! V_227 -> V_233 ) {
V_227 -> V_233 = 1 ;
F_110 ( L_3 ,
V_223 , F_84 ( F_4 ( V_2 ) -> V_5 ) , V_224 ) ;
}
return V_225 ;
}
static struct V_38 * F_111 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
const struct V_234 * V_46 = & ( F_112 ( V_2 ) -> V_46 ) ;
struct V_38 * V_235 = NULL ;
if ( V_46 && V_46 -> V_71 ) {
int V_236 = sizeof( * V_235 ) + V_46 -> V_71 ;
V_235 = F_113 ( V_236 , V_237 ) ;
if ( V_235 ) {
if ( F_114 ( & V_235 -> V_46 , V_2 ) ) {
F_107 ( V_235 ) ;
V_235 = NULL ;
}
}
}
return V_235 ;
}
struct V_165 * F_86 ( struct V_7 * V_8 ,
const union V_181 * V_238 ,
int V_239 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_165 * V_166 ;
struct V_240 * V_241 ;
unsigned int V_242 = sizeof( struct V_243 ) ;
struct V_244 * V_245 ;
V_245 = F_115 ( V_14 -> V_246 ,
F_16 ( V_8 ) ||
F_116 ( & V_8 -> V_247 . V_248 ) ) ;
if ( ! V_245 )
return NULL ;
#if F_117 ( V_249 )
if ( V_239 == V_250 )
V_242 = sizeof( struct V_251 ) ;
#endif
F_118 (key, pos, &md5sig->head, node) {
if ( V_166 -> V_239 != V_239 )
continue;
if ( ! memcmp ( & V_166 -> V_238 , V_238 , V_242 ) )
return V_166 ;
}
return NULL ;
}
struct V_165 * F_119 ( struct V_7 * V_8 ,
struct V_7 * V_252 )
{
union V_181 * V_238 ;
V_238 = (union V_181 * ) & F_14 ( V_252 ) -> V_64 ;
return F_86 ( V_8 , V_238 , V_42 ) ;
}
static struct V_165 * F_120 ( struct V_7 * V_8 ,
struct V_145 * V_146 )
{
union V_181 * V_238 ;
V_238 = (union V_181 * ) & F_98 ( V_146 ) -> V_221 ;
return F_86 ( V_8 , V_238 , V_42 ) ;
}
int F_121 ( struct V_7 * V_8 , const union V_181 * V_238 ,
int V_239 , const T_6 * V_253 , T_6 V_254 , T_8 V_255 )
{
struct V_165 * V_166 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_244 * V_245 ;
V_166 = F_86 ( V_8 , (union V_181 * ) & V_238 , V_42 ) ;
if ( V_166 ) {
memcpy ( V_166 -> V_166 , V_253 , V_254 ) ;
V_166 -> V_256 = V_254 ;
return 0 ;
}
V_245 = F_15 ( V_14 -> V_246 ,
F_16 ( V_8 ) ) ;
if ( ! V_245 ) {
V_245 = F_113 ( sizeof( * V_245 ) , V_255 ) ;
if ( ! V_245 )
return - V_257 ;
F_122 ( V_8 , V_258 ) ;
F_123 ( & V_245 -> V_157 ) ;
F_124 ( V_14 -> V_246 , V_245 ) ;
}
V_166 = F_125 ( V_8 , sizeof( * V_166 ) , V_255 ) ;
if ( ! V_166 )
return - V_257 ;
if ( F_126 ( & V_245 -> V_157 ) && ! F_127 ( V_8 ) ) {
F_128 ( V_8 , V_166 , sizeof( * V_166 ) ) ;
return - V_257 ;
}
memcpy ( V_166 -> V_166 , V_253 , V_254 ) ;
V_166 -> V_256 = V_254 ;
V_166 -> V_239 = V_239 ;
memcpy ( & V_166 -> V_238 , V_238 ,
( V_239 == V_250 ) ? sizeof( struct V_251 ) :
sizeof( struct V_243 ) ) ;
F_129 ( & V_166 -> V_259 , & V_245 -> V_157 ) ;
return 0 ;
}
int F_130 ( struct V_7 * V_8 , const union V_181 * V_238 , int V_239 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_165 * V_166 ;
struct V_244 * V_245 ;
V_166 = F_86 ( V_8 , (union V_181 * ) & V_238 , V_42 ) ;
if ( ! V_166 )
return - V_260 ;
F_131 ( & V_166 -> V_259 ) ;
F_132 ( sizeof( * V_166 ) , & V_8 -> V_261 ) ;
F_133 ( V_166 , V_262 ) ;
V_245 = F_15 ( V_14 -> V_246 ,
F_16 ( V_8 ) ) ;
if ( F_126 ( & V_245 -> V_157 ) )
F_134 () ;
return 0 ;
}
void F_135 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_165 * V_166 ;
struct V_240 * V_241 , * V_263 ;
struct V_244 * V_245 ;
V_245 = F_15 ( V_14 -> V_246 , 1 ) ;
if ( ! F_126 ( & V_245 -> V_157 ) )
F_134 () ;
F_136 (key, pos, n, &md5sig->head, node) {
F_131 ( & V_166 -> V_259 ) ;
F_132 ( sizeof( * V_166 ) , & V_8 -> V_261 ) ;
F_133 ( V_166 , V_262 ) ;
}
}
static int F_137 ( struct V_7 * V_8 , char T_9 * V_264 ,
int V_71 )
{
struct V_265 V_266 ;
struct V_26 * sin = (struct V_26 * ) & V_266 . V_267 ;
if ( V_71 < sizeof( V_266 ) )
return - V_40 ;
if ( F_138 ( & V_266 , V_264 , sizeof( V_266 ) ) )
return - V_268 ;
if ( sin -> V_41 != V_42 )
return - V_40 ;
if ( ! V_266 . V_269 || ! V_266 . V_270 )
return F_130 ( V_8 , (union V_181 * ) & sin -> V_44 . V_45 ,
V_42 ) ;
if ( V_266 . V_270 > V_271 )
return - V_40 ;
return F_121 ( V_8 , (union V_181 * ) & sin -> V_44 . V_45 ,
V_42 , V_266 . V_269 , V_266 . V_270 ,
V_272 ) ;
}
static int F_139 ( struct V_273 * V_274 ,
T_3 V_3 , T_3 V_4 , int V_275 )
{
struct V_276 * V_277 ;
struct V_278 V_279 ;
V_277 = & V_274 -> V_280 . V_54 ;
V_277 -> V_4 = V_4 ;
V_277 -> V_3 = V_3 ;
V_277 -> V_281 = 0 ;
V_277 -> V_282 = V_57 ;
V_277 -> V_109 = F_140 ( V_275 ) ;
F_141 ( & V_279 , V_277 , sizeof( * V_277 ) ) ;
return F_142 ( & V_274 -> V_283 , & V_279 , sizeof( * V_277 ) ) ;
}
static int F_88 ( char * V_284 , const struct V_165 * V_166 ,
T_3 V_3 , T_3 V_4 , const struct V_99 * V_100 )
{
struct V_273 * V_274 ;
struct V_285 * V_286 ;
V_274 = F_143 () ;
if ( ! V_274 )
goto V_287;
V_286 = & V_274 -> V_283 ;
if ( F_144 ( V_286 ) )
goto V_288;
if ( F_139 ( V_274 , V_3 , V_4 , V_100 -> V_159 << 2 ) )
goto V_288;
if ( F_145 ( V_274 , V_100 ) )
goto V_288;
if ( F_146 ( V_274 , V_166 ) )
goto V_288;
if ( F_147 ( V_286 , V_284 ) )
goto V_288;
F_148 () ;
return 0 ;
V_288:
F_148 () ;
V_287:
memset ( V_284 , 0 , 16 ) ;
return 1 ;
}
int F_87 ( char * V_284 , struct V_165 * V_166 ,
const struct V_7 * V_8 , const struct V_145 * V_146 ,
const struct V_1 * V_2 )
{
struct V_273 * V_274 ;
struct V_285 * V_286 ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
T_3 V_4 , V_3 ;
if ( V_8 ) {
V_4 = F_14 ( V_8 ) -> V_55 ;
V_3 = F_14 ( V_8 ) -> V_64 ;
} else if ( V_146 ) {
V_4 = F_98 ( V_146 ) -> V_220 ;
V_3 = F_98 ( V_146 ) -> V_221 ;
} else {
const struct V_96 * V_97 = F_3 ( V_2 ) ;
V_4 = V_97 -> V_4 ;
V_3 = V_97 -> V_3 ;
}
V_274 = F_143 () ;
if ( ! V_274 )
goto V_287;
V_286 = & V_274 -> V_283 ;
if ( F_144 ( V_286 ) )
goto V_288;
if ( F_139 ( V_274 , V_3 , V_4 , V_2 -> V_109 ) )
goto V_288;
if ( F_145 ( V_274 , V_100 ) )
goto V_288;
if ( F_149 ( V_274 , V_2 , V_100 -> V_159 << 2 ) )
goto V_288;
if ( F_146 ( V_274 , V_166 ) )
goto V_288;
if ( F_147 ( V_286 , V_284 ) )
goto V_288;
F_148 () ;
return 0 ;
V_288:
F_148 () ;
V_287:
memset ( V_284 , 0 , 16 ) ;
return 1 ;
}
static bool F_150 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
const T_5 * V_167 = NULL ;
struct V_165 * V_289 ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
const struct V_99 * V_100 = F_4 ( V_2 ) ;
int V_169 ;
unsigned char V_168 [ 16 ] ;
V_289 = F_86 ( V_8 , (union V_181 * ) & V_97 -> V_4 ,
V_42 ) ;
V_167 = F_81 ( V_100 ) ;
if ( ! V_289 && ! V_167 )
return false ;
if ( V_289 && ! V_167 ) {
F_49 ( F_22 ( V_8 ) , V_290 ) ;
return true ;
}
if ( ! V_289 && V_167 ) {
F_49 ( F_22 ( V_8 ) , V_291 ) ;
return true ;
}
V_169 = F_87 ( V_168 ,
V_289 ,
NULL , NULL , V_2 ) ;
if ( V_169 || memcmp ( V_167 , V_168 , 16 ) != 0 ) {
F_151 ( L_4 ,
& V_97 -> V_4 , F_84 ( V_100 -> V_6 ) ,
& V_97 -> V_3 , F_84 ( V_100 -> V_5 ) ,
V_169 ? L_5
: L_6 ) ;
return true ;
}
return false ;
}
int F_152 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_292 V_293 ;
struct V_294 V_295 ;
const T_6 * V_167 ;
struct V_145 * V_146 ;
struct V_218 * V_219 ;
struct V_13 * V_14 = F_7 ( V_8 ) ;
struct V_82 * V_68 = NULL ;
T_3 V_4 = F_3 ( V_2 ) -> V_4 ;
T_3 V_3 = F_3 ( V_2 ) -> V_3 ;
T_1 V_296 = F_59 ( V_2 ) -> V_140 ;
bool V_225 = false ;
if ( F_79 ( V_2 ) -> V_60 & ( V_62 | V_61 ) )
goto V_297;
if ( F_153 ( V_8 ) && ! V_296 ) {
V_225 = F_108 ( V_8 , V_2 , L_7 ) ;
if ( ! V_225 )
goto V_297;
}
if ( F_154 ( V_8 ) && F_155 ( V_8 ) > 1 )
goto V_297;
V_146 = F_156 ( & V_298 ) ;
if ( ! V_146 )
goto V_297;
#ifdef F_78
F_64 ( V_146 ) -> V_299 = & V_300 ;
#endif
F_157 ( & V_295 ) ;
V_295 . V_72 = V_73 ;
V_295 . V_301 = V_14 -> V_19 . V_301 ;
F_158 ( V_2 , & V_295 , & V_167 , 0 , NULL ) ;
if ( V_295 . V_302 > 0 &&
V_295 . V_303 &&
! V_14 -> V_19 . V_304 &&
( V_305 > 0 ||
( V_14 -> V_306 != NULL &&
V_14 -> V_306 -> V_307 > 0 ) ) ) {
T_6 * V_308 ;
T_4 * V_309 = & V_293 . V_310 [ V_311 ] ;
int V_312 = V_295 . V_302 - V_313 ;
if ( F_159 ( & V_293 . V_310 [ 0 ] ) != 0 )
goto V_314;
* V_309 ++ ^= ( V_315 T_4 ) V_3 ;
* V_309 ++ ^= ( V_315 T_4 ) V_4 ;
V_308 = ( T_6 * ) V_309 ;
while ( V_312 -- > 0 )
* V_308 ++ ^= * V_167 ++ ;
V_225 = false ;
V_293 . V_304 = 0 ;
V_293 . V_302 = V_295 . V_302 ;
} else if ( ! V_14 -> V_19 . V_316 ) {
V_293 . V_304 = 1 ;
V_293 . V_302 = 0 ;
} else {
goto V_314;
}
V_293 . V_316 = V_14 -> V_19 . V_316 ;
if ( V_225 && ! V_295 . V_303 )
F_157 ( & V_295 ) ;
V_295 . V_317 = V_295 . V_303 ;
F_160 ( V_146 , & V_295 , V_2 ) ;
V_219 = F_98 ( V_146 ) ;
V_219 -> V_220 = V_3 ;
V_219 -> V_221 = V_4 ;
V_219 -> V_213 = F_14 ( V_8 ) -> V_188 ;
V_219 -> V_46 = F_111 ( V_8 , V_2 ) ;
if ( F_161 ( V_8 , V_2 , V_146 ) )
goto V_318;
if ( ! V_225 || V_295 . V_317 )
F_162 ( V_146 , V_2 ) ;
if ( V_225 ) {
V_296 = F_163 ( V_8 , V_2 , & V_146 -> V_319 ) ;
V_146 -> V_320 = V_295 . V_317 ;
} else if ( ! V_296 ) {
struct V_33 V_34 ;
if ( V_295 . V_303 &&
V_66 . V_67 &&
( V_68 = F_100 ( V_8 , & V_34 , V_146 ) ) != NULL &&
V_34 . V_3 == V_4 ) {
if ( ! F_164 ( V_146 , V_68 , true ) ) {
F_49 ( F_22 ( V_8 ) , V_321 ) ;
goto V_314;
}
}
else if ( ! V_228 &&
( V_322 - F_165 ( V_8 ) <
( V_322 >> 2 ) ) &&
! F_164 ( V_146 , V_68 , false ) ) {
F_166 (KERN_DEBUG pr_fmt(L_8),
&saddr, ntohs(tcp_hdr(skb)->source)) ;
goto V_314;
}
V_296 = F_1 ( V_2 ) ;
}
F_64 ( V_146 ) -> V_148 = V_296 ;
F_64 ( V_146 ) -> V_323 = V_139 ;
if ( F_99 ( V_8 , V_68 , V_146 ,
(struct V_214 * ) & V_293 ,
F_167 ( V_2 ) ,
V_225 ) ||
V_225 )
goto V_318;
F_168 ( V_8 , V_146 , V_138 ) ;
return 0 ;
V_314:
F_169 ( V_68 ) ;
V_318:
F_170 ( V_146 ) ;
V_297:
return 0 ;
}
struct V_7 * F_171 ( struct V_7 * V_8 , struct V_1 * V_2 ,
struct V_145 * V_146 ,
struct V_82 * V_68 )
{
struct V_218 * V_219 ;
struct V_28 * V_324 ;
struct V_13 * V_325 ;
struct V_7 * V_326 ;
#ifdef F_78
struct V_165 * V_166 ;
#endif
struct V_38 * V_39 ;
if ( F_154 ( V_8 ) )
goto V_327;
V_326 = F_172 ( V_8 , V_146 , V_2 ) ;
if ( ! V_326 )
goto V_328;
V_326 -> V_76 = V_77 ;
F_173 ( V_326 , V_2 ) ;
V_325 = F_7 ( V_326 ) ;
V_324 = F_14 ( V_326 ) ;
V_219 = F_98 ( V_146 ) ;
V_324 -> V_64 = V_219 -> V_221 ;
V_324 -> V_63 = V_219 -> V_220 ;
V_324 -> V_55 = V_219 -> V_220 ;
V_39 = V_219 -> V_46 ;
F_124 ( V_324 -> V_39 , V_39 ) ;
V_219 -> V_46 = NULL ;
V_324 -> V_329 = F_45 ( V_2 ) ;
V_324 -> V_330 = F_3 ( V_2 ) -> V_117 ;
V_324 -> V_331 = F_3 ( V_2 ) -> V_191 ;
F_26 ( V_326 ) -> V_70 = 0 ;
if ( V_39 )
F_26 ( V_326 ) -> V_70 = V_39 -> V_46 . V_71 ;
V_324 -> V_78 = V_325 -> V_17 ^ V_79 ;
if ( ! V_68 ) {
V_68 = F_174 ( V_8 , V_326 , V_146 ) ;
if ( ! V_68 )
goto V_332;
} else {
}
F_30 ( V_326 , V_68 ) ;
F_175 ( V_326 ) ;
F_36 ( V_326 , F_34 ( V_68 ) ) ;
V_325 -> V_333 = F_176 ( V_68 ) ;
if ( F_7 ( V_8 ) -> V_19 . V_301 &&
F_7 ( V_8 ) -> V_19 . V_301 < V_325 -> V_333 )
V_325 -> V_333 = F_7 ( V_8 ) -> V_19 . V_301 ;
F_177 ( V_326 ) ;
if ( F_64 ( V_146 ) -> V_323 )
F_178 ( V_326 ,
V_139 - F_64 ( V_146 ) -> V_323 ) ;
V_325 -> V_334 = V_146 -> V_335 ;
#ifdef F_78
V_166 = F_86 ( V_8 , (union V_181 * ) & V_324 -> V_64 ,
V_42 ) ;
if ( V_166 != NULL ) {
F_121 ( V_326 , (union V_181 * ) & V_324 -> V_64 ,
V_42 , V_166 -> V_166 , V_166 -> V_256 , V_237 ) ;
F_122 ( V_326 , V_258 ) ;
}
#endif
if ( F_179 ( V_8 , V_326 ) < 0 )
goto V_332;
F_180 ( V_326 , NULL ) ;
return V_326 ;
V_327:
F_49 ( F_22 ( V_8 ) , V_336 ) ;
V_328:
F_169 ( V_68 ) ;
exit:
F_49 ( F_22 ( V_8 ) , V_337 ) ;
return NULL ;
V_332:
F_181 ( V_326 ) ;
F_182 ( V_326 ) ;
F_67 ( V_326 ) ;
F_68 ( V_326 ) ;
goto exit;
}
static struct V_7 * F_183 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_99 * V_100 = F_4 ( V_2 ) ;
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_7 * V_338 ;
struct V_145 * * V_147 ;
struct V_145 * V_146 = F_62 ( V_8 , & V_147 , V_100 -> V_6 ,
V_97 -> V_4 , V_97 -> V_3 ) ;
if ( V_146 )
return F_184 ( V_8 , V_2 , V_146 , V_147 ) ;
V_338 = F_185 ( F_22 ( V_8 ) , & V_111 , V_97 -> V_4 ,
V_100 -> V_6 , V_97 -> V_3 , V_100 -> V_5 , F_45 ( V_2 ) ) ;
if ( V_338 ) {
if ( V_338 -> V_85 != V_112 ) {
F_48 ( V_338 ) ;
return V_338 ;
}
F_46 ( F_47 ( V_338 ) ) ;
return NULL ;
}
#ifdef F_109
if ( ! V_100 -> V_176 )
V_8 = F_186 ( V_8 , V_2 , & ( F_112 ( V_2 ) -> V_46 ) ) ;
#endif
return V_8 ;
}
static T_10 F_187 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
if ( V_2 -> V_153 == V_339 ) {
if ( ! F_70 ( V_2 -> V_109 , V_97 -> V_4 ,
V_97 -> V_3 , V_2 -> V_160 ) ) {
V_2 -> V_153 = V_340 ;
return 0 ;
}
}
V_2 -> V_160 = F_89 ( V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_109 , V_57 , 0 ) ;
if ( V_2 -> V_109 <= 76 ) {
return F_188 ( V_2 ) ;
}
return 0 ;
}
int F_189 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_7 * V_341 ;
#ifdef F_78
if ( F_150 ( V_8 , V_2 ) )
goto V_342;
#endif
if ( V_8 -> V_85 == V_343 ) {
struct V_82 * V_68 = V_8 -> V_344 ;
F_190 ( V_8 , V_2 ) ;
if ( V_68 ) {
if ( F_14 ( V_8 ) -> V_345 != V_2 -> V_346 ||
V_68 -> V_92 -> V_155 ( V_68 , 0 ) == NULL ) {
F_169 ( V_68 ) ;
V_8 -> V_344 = NULL ;
}
}
if ( F_191 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_341 = V_8 ;
goto V_347;
}
return 0 ;
}
if ( V_2 -> V_109 < F_192 ( V_2 ) || F_193 ( V_2 ) )
goto V_348;
if ( V_8 -> V_85 == V_86 ) {
struct V_7 * V_338 = F_183 ( V_8 , V_2 ) ;
if ( ! V_338 )
goto V_342;
if ( V_338 != V_8 ) {
F_190 ( V_338 , V_2 ) ;
if ( F_194 ( V_8 , V_338 , V_2 ) ) {
V_341 = V_338 ;
goto V_347;
}
return 0 ;
}
} else
F_190 ( V_8 , V_2 ) ;
if ( F_195 ( V_8 , V_2 , F_4 ( V_2 ) , V_2 -> V_109 ) ) {
V_341 = V_8 ;
goto V_347;
}
return 0 ;
V_347:
F_77 ( V_341 , V_2 ) ;
V_342:
F_196 ( V_2 ) ;
return 0 ;
V_348:
F_91 ( F_22 ( V_8 ) , V_349 ) ;
goto V_342;
}
void F_197 ( struct V_1 * V_2 )
{
struct V_107 * V_107 = F_42 ( V_2 -> V_108 ) ;
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
if ( V_2 -> V_350 != V_351 )
return;
if ( ! F_76 ( V_2 , F_198 ( V_2 ) + sizeof( struct V_99 ) ) )
return;
V_97 = F_3 ( V_2 ) ;
V_100 = (struct V_99 * ) ( ( char * ) V_97 + F_198 ( V_2 ) ) ;
if ( V_100 -> V_159 < sizeof( struct V_99 ) / 4 )
return;
V_8 = F_199 ( V_107 , & V_111 ,
V_97 -> V_4 , V_100 -> V_6 ,
V_97 -> V_3 , F_84 ( V_100 -> V_5 ) ,
V_2 -> V_346 ) ;
if ( V_8 ) {
V_2 -> V_8 = V_8 ;
V_2 -> V_352 = V_353 ;
if ( V_8 -> V_85 != V_112 ) {
struct V_82 * V_68 = V_8 -> V_344 ;
if ( V_68 )
V_68 = F_200 ( V_68 , 0 ) ;
if ( V_68 &&
F_14 ( V_8 ) -> V_345 == V_2 -> V_346 )
F_201 ( V_2 , V_68 ) ;
}
}
}
int F_202 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 ;
const struct V_99 * V_100 ;
struct V_7 * V_8 ;
int V_354 ;
struct V_107 * V_107 = F_42 ( V_2 -> V_108 ) ;
if ( V_2 -> V_350 != V_351 )
goto V_355;
F_91 ( V_107 , V_356 ) ;
if ( ! F_76 ( V_2 , sizeof( struct V_99 ) ) )
goto V_355;
V_100 = F_4 ( V_2 ) ;
if ( V_100 -> V_159 < sizeof( struct V_99 ) / 4 )
goto V_357;
if ( ! F_76 ( V_2 , V_100 -> V_159 * 4 ) )
goto V_355;
if ( ! F_203 ( V_2 ) && F_187 ( V_2 ) )
goto V_357;
V_100 = F_4 ( V_2 ) ;
V_97 = F_3 ( V_2 ) ;
F_59 ( V_2 ) -> V_105 = F_51 ( V_100 -> V_105 ) ;
F_59 ( V_2 ) -> V_358 = ( F_59 ( V_2 ) -> V_105 + V_100 -> V_176 + V_100 -> V_177 +
V_2 -> V_109 - V_100 -> V_159 * 4 ) ;
F_59 ( V_2 ) -> V_175 = F_51 ( V_100 -> V_175 ) ;
F_59 ( V_2 ) -> V_140 = 0 ;
F_59 ( V_2 ) -> V_359 = F_204 ( V_97 ) ;
F_59 ( V_2 ) -> V_360 = 0 ;
V_8 = F_205 ( & V_111 , V_2 , V_100 -> V_6 , V_100 -> V_5 ) ;
if ( ! V_8 )
goto V_361;
V_362:
if ( V_8 -> V_85 == V_112 )
goto V_363;
if ( F_50 ( V_97 -> V_117 < F_14 ( V_8 ) -> V_118 ) ) {
F_49 ( V_107 , V_119 ) ;
goto V_364;
}
if ( ! F_206 ( V_8 , V_365 , V_2 ) )
goto V_364;
F_207 ( V_2 ) ;
if ( F_208 ( V_8 , V_2 ) )
goto V_364;
V_2 -> V_108 = NULL ;
F_209 ( V_8 ) ;
V_354 = 0 ;
if ( ! F_16 ( V_8 ) ) {
#ifdef F_210
struct V_13 * V_14 = F_7 ( V_8 ) ;
if ( ! V_14 -> V_366 . V_367 && V_14 -> V_366 . V_368 )
V_14 -> V_366 . V_367 = F_211 () ;
if ( V_14 -> V_366 . V_367 )
V_354 = F_189 ( V_8 , V_2 ) ;
else
#endif
{
if ( ! F_212 ( V_8 , V_2 ) )
V_354 = F_189 ( V_8 , V_2 ) ;
}
} else if ( F_50 ( F_213 ( V_8 , V_2 ,
V_8 -> V_369 + V_8 -> V_370 ) ) ) {
F_67 ( V_8 ) ;
F_49 ( V_107 , V_371 ) ;
goto V_364;
}
F_67 ( V_8 ) ;
F_68 ( V_8 ) ;
return V_354 ;
V_361:
if ( ! F_206 ( NULL , V_365 , V_2 ) )
goto V_355;
if ( V_2 -> V_109 < ( V_100 -> V_159 << 2 ) || F_193 ( V_2 ) ) {
V_357:
F_91 ( V_107 , V_349 ) ;
} else {
F_77 ( NULL , V_2 ) ;
}
V_355:
F_196 ( V_2 ) ;
return 0 ;
V_364:
F_68 ( V_8 ) ;
goto V_355;
V_363:
if ( ! F_206 ( NULL , V_365 , V_2 ) ) {
F_46 ( F_47 ( V_8 ) ) ;
goto V_355;
}
if ( V_2 -> V_109 < ( V_100 -> V_159 << 2 ) || F_193 ( V_2 ) ) {
F_91 ( V_107 , V_349 ) ;
F_46 ( F_47 ( V_8 ) ) ;
goto V_355;
}
switch ( F_214 ( F_47 ( V_8 ) , V_2 , V_100 ) ) {
case V_372 : {
struct V_7 * V_373 = F_215 ( F_42 ( V_2 -> V_108 ) ,
& V_111 ,
V_97 -> V_3 , V_100 -> V_5 ,
F_45 ( V_2 ) ) ;
if ( V_373 ) {
F_216 ( F_47 ( V_8 ) , & V_66 ) ;
F_46 ( F_47 ( V_8 ) ) ;
V_8 = V_373 ;
goto V_362;
}
}
case V_374 :
F_95 ( V_8 , V_2 ) ;
break;
case V_375 :
goto V_361;
case V_376 : ;
}
goto V_355;
}
void F_173 ( struct V_7 * V_8 , const struct V_1 * V_2 )
{
struct V_82 * V_68 = F_83 ( V_2 ) ;
F_217 ( V_68 ) ;
V_8 -> V_344 = V_68 ;
F_14 ( V_8 ) -> V_345 = V_2 -> V_346 ;
}
static int F_218 ( struct V_7 * V_8 )
{
struct V_102 * V_103 = F_26 ( V_8 ) ;
F_219 ( V_8 ) ;
V_103 -> V_377 = & V_378 ;
#ifdef F_78
F_7 ( V_8 ) -> V_299 = & V_379 ;
#endif
return 0 ;
}
void F_220 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_7 ( V_8 ) ;
F_181 ( V_8 ) ;
F_182 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( & V_14 -> V_380 ) ;
#ifdef F_78
if ( V_14 -> V_246 ) {
F_135 ( V_8 ) ;
F_133 ( V_14 -> V_246 , V_262 ) ;
V_14 -> V_246 = NULL ;
}
#endif
#ifdef F_210
F_222 ( & V_8 -> V_381 ) ;
#endif
F_222 ( & V_14 -> V_366 . V_382 ) ;
if ( F_26 ( V_8 ) -> V_383 )
F_223 ( V_8 ) ;
if ( V_8 -> V_384 ) {
F_224 ( V_8 -> V_384 ) ;
V_8 -> V_384 = NULL ;
}
if ( V_14 -> V_306 != NULL ) {
F_225 ( & V_14 -> V_306 -> V_385 ,
V_386 ) ;
V_14 -> V_306 = NULL ;
}
F_226 ( V_14 ) ;
F_227 ( V_8 ) ;
F_228 ( V_8 ) ;
}
static inline struct V_203 * F_229 ( struct V_387 * V_157 )
{
return F_230 ( V_157 ) ? NULL :
F_231 ( V_157 -> V_388 , struct V_203 , V_389 ) ;
}
static inline struct V_203 * F_232 ( struct V_203 * V_204 )
{
return ! F_233 ( V_204 -> V_389 . V_390 ) ?
F_234 ( V_204 -> V_389 . V_390 , F_235 ( * V_204 ) , V_389 ) : NULL ;
}
static void * F_236 ( struct V_391 * V_105 , void * V_392 )
{
struct V_102 * V_103 ;
struct V_393 * V_259 ;
struct V_7 * V_8 = V_392 ;
struct V_394 * V_395 ;
struct V_396 * V_397 = V_105 -> V_398 ;
struct V_107 * V_107 = F_237 ( V_105 ) ;
if ( ! V_8 ) {
V_395 = & V_111 . V_399 [ V_397 -> V_400 ] ;
F_238 ( & V_395 -> V_401 ) ;
V_8 = F_239 ( & V_395 -> V_157 ) ;
V_397 -> V_202 = 0 ;
goto V_402;
}
V_395 = & V_111 . V_399 [ V_397 -> V_400 ] ;
++ V_397 -> V_403 ;
++ V_397 -> V_202 ;
if ( V_397 -> V_404 == V_405 ) {
struct V_145 * V_146 = V_392 ;
V_103 = F_26 ( V_397 -> V_406 ) ;
V_146 = V_146 -> V_407 ;
while ( 1 ) {
while ( V_146 ) {
if ( V_146 -> V_408 -> V_239 == V_397 -> V_239 ) {
V_392 = V_146 ;
goto V_116;
}
V_146 = V_146 -> V_407 ;
}
if ( ++ V_397 -> V_409 >= V_103 -> V_231 . V_232 -> V_410 )
break;
V_411:
V_146 = V_103 -> V_231 . V_232 -> V_412 [ V_397 -> V_409 ] ;
}
V_8 = F_240 ( V_397 -> V_406 ) ;
V_397 -> V_404 = V_413 ;
F_241 ( & V_103 -> V_231 . V_414 ) ;
} else {
V_103 = F_26 ( V_8 ) ;
F_242 ( & V_103 -> V_231 . V_414 ) ;
if ( F_243 ( & V_103 -> V_231 ) )
goto V_415;
F_241 ( & V_103 -> V_231 . V_414 ) ;
V_8 = F_240 ( V_8 ) ;
}
V_402:
F_244 (sk, node) {
if ( ! F_245 ( F_22 ( V_8 ) , V_107 ) )
continue;
if ( V_8 -> V_416 == V_397 -> V_239 ) {
V_392 = V_8 ;
goto V_116;
}
V_103 = F_26 ( V_8 ) ;
F_242 ( & V_103 -> V_231 . V_414 ) ;
if ( F_243 ( & V_103 -> V_231 ) ) {
V_415:
V_397 -> V_417 = F_246 ( V_8 ) ;
V_397 -> V_406 = V_8 ;
V_397 -> V_404 = V_405 ;
V_397 -> V_409 = 0 ;
goto V_411;
}
F_241 ( & V_103 -> V_231 . V_414 ) ;
}
F_247 ( & V_395 -> V_401 ) ;
V_397 -> V_202 = 0 ;
if ( ++ V_397 -> V_400 < V_418 ) {
V_395 = & V_111 . V_399 [ V_397 -> V_400 ] ;
F_238 ( & V_395 -> V_401 ) ;
V_8 = F_239 ( & V_395 -> V_157 ) ;
goto V_402;
}
V_392 = NULL ;
V_116:
return V_392 ;
}
static void * F_248 ( struct V_391 * V_105 , T_11 * V_241 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
void * V_419 ;
V_397 -> V_400 = 0 ;
V_397 -> V_202 = 0 ;
V_419 = F_236 ( V_105 , NULL ) ;
while ( V_419 && * V_241 ) {
V_419 = F_236 ( V_105 , V_419 ) ;
-- * V_241 ;
}
return V_419 ;
}
static inline bool F_249 ( struct V_396 * V_397 )
{
return F_230 ( & V_111 . V_420 [ V_397 -> V_400 ] . V_421 ) &&
F_230 ( & V_111 . V_420 [ V_397 -> V_400 ] . V_422 ) ;
}
static void * F_250 ( struct V_391 * V_105 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
struct V_107 * V_107 = F_237 ( V_105 ) ;
void * V_419 = NULL ;
V_397 -> V_202 = 0 ;
for (; V_397 -> V_400 <= V_111 . V_423 ; ++ V_397 -> V_400 ) {
struct V_7 * V_8 ;
struct V_393 * V_259 ;
struct V_203 * V_204 ;
T_12 * V_401 = F_251 ( & V_111 , V_397 -> V_400 ) ;
if ( F_249 ( V_397 ) )
continue;
F_238 ( V_401 ) ;
F_252 (sk, node, &tcp_hashinfo.ehash[st->bucket].chain) {
if ( V_8 -> V_416 != V_397 -> V_239 ||
! F_245 ( F_22 ( V_8 ) , V_107 ) ) {
continue;
}
V_419 = V_8 ;
goto V_116;
}
V_397 -> V_404 = V_424 ;
F_253 (tw, node,
&tcp_hashinfo.ehash[st->bucket].twchain) {
if ( V_204 -> V_425 != V_397 -> V_239 ||
! F_245 ( F_254 ( V_204 ) , V_107 ) ) {
continue;
}
V_419 = V_204 ;
goto V_116;
}
F_247 ( V_401 ) ;
V_397 -> V_404 = V_426 ;
}
V_116:
return V_419 ;
}
static void * F_255 ( struct V_391 * V_105 , void * V_392 )
{
struct V_7 * V_8 = V_392 ;
struct V_203 * V_204 ;
struct V_393 * V_259 ;
struct V_396 * V_397 = V_105 -> V_398 ;
struct V_107 * V_107 = F_237 ( V_105 ) ;
++ V_397 -> V_403 ;
++ V_397 -> V_202 ;
if ( V_397 -> V_404 == V_424 ) {
V_204 = V_392 ;
V_204 = F_232 ( V_204 ) ;
V_427:
while ( V_204 && ( V_204 -> V_425 != V_397 -> V_239 || ! F_245 ( F_254 ( V_204 ) , V_107 ) ) ) {
V_204 = F_232 ( V_204 ) ;
}
if ( V_204 ) {
V_392 = V_204 ;
goto V_116;
}
F_247 ( F_251 ( & V_111 , V_397 -> V_400 ) ) ;
V_397 -> V_404 = V_426 ;
V_397 -> V_202 = 0 ;
while ( ++ V_397 -> V_400 <= V_111 . V_423 &&
F_249 ( V_397 ) )
;
if ( V_397 -> V_400 > V_111 . V_423 )
return NULL ;
F_238 ( F_251 ( & V_111 , V_397 -> V_400 ) ) ;
V_8 = F_239 ( & V_111 . V_420 [ V_397 -> V_400 ] . V_421 ) ;
} else
V_8 = F_240 ( V_8 ) ;
F_244 (sk, node) {
if ( V_8 -> V_416 == V_397 -> V_239 && F_245 ( F_22 ( V_8 ) , V_107 ) )
goto V_428;
}
V_397 -> V_404 = V_424 ;
V_204 = F_229 ( & V_111 . V_420 [ V_397 -> V_400 ] . V_422 ) ;
goto V_427;
V_428:
V_392 = V_8 ;
V_116:
return V_392 ;
}
static void * F_256 ( struct V_391 * V_105 , T_11 V_241 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
void * V_419 ;
V_397 -> V_400 = 0 ;
V_419 = F_250 ( V_105 ) ;
while ( V_419 && V_241 ) {
V_419 = F_255 ( V_105 , V_419 ) ;
-- V_241 ;
}
return V_419 ;
}
static void * F_257 ( struct V_391 * V_105 , T_11 V_241 )
{
void * V_419 ;
struct V_396 * V_397 = V_105 -> V_398 ;
V_397 -> V_404 = V_413 ;
V_419 = F_248 ( V_105 , & V_241 ) ;
if ( ! V_419 ) {
V_397 -> V_404 = V_426 ;
V_419 = F_256 ( V_105 , V_241 ) ;
}
return V_419 ;
}
static void * F_258 ( struct V_391 * V_105 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
int V_202 = V_397 -> V_202 ;
int V_429 = V_397 -> V_403 ;
void * V_419 = NULL ;
switch ( V_397 -> V_404 ) {
case V_405 :
case V_413 :
if ( V_397 -> V_400 >= V_418 )
break;
V_397 -> V_404 = V_413 ;
V_419 = F_236 ( V_105 , NULL ) ;
while ( V_202 -- && V_419 )
V_419 = F_236 ( V_105 , V_419 ) ;
if ( V_419 )
break;
V_397 -> V_400 = 0 ;
case V_426 :
case V_424 :
V_397 -> V_404 = V_426 ;
if ( V_397 -> V_400 > V_111 . V_423 )
break;
V_419 = F_250 ( V_105 ) ;
while ( V_202 -- && V_419 )
V_419 = F_255 ( V_105 , V_419 ) ;
}
V_397 -> V_403 = V_429 ;
return V_419 ;
}
static void * F_259 ( struct V_391 * V_105 , T_11 * V_241 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
void * V_419 ;
if ( * V_241 && * V_241 == V_397 -> V_430 ) {
V_419 = F_258 ( V_105 ) ;
if ( V_419 )
goto V_116;
}
V_397 -> V_404 = V_413 ;
V_397 -> V_403 = 0 ;
V_397 -> V_400 = 0 ;
V_397 -> V_202 = 0 ;
V_419 = * V_241 ? F_257 ( V_105 , * V_241 - 1 ) : V_431 ;
V_116:
V_397 -> V_430 = * V_241 ;
return V_419 ;
}
static void * F_260 ( struct V_391 * V_105 , void * V_432 , T_11 * V_241 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
void * V_419 = NULL ;
if ( V_432 == V_431 ) {
V_419 = F_257 ( V_105 , 0 ) ;
goto V_116;
}
switch ( V_397 -> V_404 ) {
case V_405 :
case V_413 :
V_419 = F_236 ( V_105 , V_432 ) ;
if ( ! V_419 ) {
V_397 -> V_404 = V_426 ;
V_397 -> V_400 = 0 ;
V_397 -> V_202 = 0 ;
V_419 = F_250 ( V_105 ) ;
}
break;
case V_426 :
case V_424 :
V_419 = F_255 ( V_105 , V_432 ) ;
break;
}
V_116:
++ * V_241 ;
V_397 -> V_430 = * V_241 ;
return V_419 ;
}
static void F_261 ( struct V_391 * V_105 , void * V_432 )
{
struct V_396 * V_397 = V_105 -> V_398 ;
switch ( V_397 -> V_404 ) {
case V_405 :
if ( V_432 ) {
struct V_102 * V_103 = F_26 ( V_397 -> V_406 ) ;
F_241 ( & V_103 -> V_231 . V_414 ) ;
}
case V_413 :
if ( V_432 != V_431 )
F_247 ( & V_111 . V_399 [ V_397 -> V_400 ] . V_401 ) ;
break;
case V_424 :
case V_426 :
if ( V_432 )
F_247 ( F_251 ( & V_111 , V_397 -> V_400 ) ) ;
break;
}
}
int F_262 ( struct V_433 * V_433 , struct V_434 * V_434 )
{
struct V_435 * V_436 = F_263 ( V_433 ) -> V_98 ;
struct V_396 * V_437 ;
int V_37 ;
V_37 = F_264 ( V_433 , V_434 , & V_436 -> V_438 ,
sizeof( struct V_396 ) ) ;
if ( V_37 < 0 )
return V_37 ;
V_437 = ( (struct V_391 * ) V_434 -> V_439 ) -> V_398 ;
V_437 -> V_239 = V_436 -> V_239 ;
V_437 -> V_430 = 0 ;
return 0 ;
}
int F_265 ( struct V_107 * V_107 , struct V_435 * V_436 )
{
int V_419 = 0 ;
struct V_440 * V_441 ;
V_436 -> V_438 . V_442 = F_259 ;
V_436 -> V_438 . V_390 = F_260 ;
V_436 -> V_438 . V_443 = F_261 ;
V_441 = F_266 ( V_436 -> V_444 , V_445 , V_107 -> V_446 ,
V_436 -> V_447 , V_436 ) ;
if ( ! V_441 )
V_419 = - V_257 ;
return V_419 ;
}
void F_267 ( struct V_107 * V_107 , struct V_435 * V_436 )
{
F_268 ( V_107 , V_436 -> V_444 ) ;
}
static void F_269 ( const struct V_7 * V_8 , const struct V_145 * V_146 ,
struct V_391 * V_448 , int V_449 , int V_417 , int * V_109 )
{
const struct V_218 * V_219 = F_98 ( V_146 ) ;
int V_450 = V_146 -> V_451 - V_79 ;
F_270 ( V_448 , L_9
L_10 ,
V_449 ,
V_219 -> V_220 ,
F_84 ( F_14 ( V_8 ) -> V_49 ) ,
V_219 -> V_221 ,
F_84 ( V_219 -> V_452 ) ,
V_149 ,
0 , 0 ,
1 ,
F_271 ( V_450 ) ,
V_146 -> V_335 ,
V_417 ,
0 ,
0 ,
F_272 ( & V_8 -> V_453 ) ,
V_146 ,
V_109 ) ;
}
static void F_273 ( struct V_7 * V_8 , struct V_391 * V_448 , int V_449 , int * V_109 )
{
int V_454 ;
unsigned long V_455 ;
const struct V_13 * V_14 = F_7 ( V_8 ) ;
const struct V_102 * V_103 = F_26 ( V_8 ) ;
const struct V_28 * V_29 = F_14 ( V_8 ) ;
T_3 V_5 = V_29 -> V_64 ;
T_3 V_456 = V_29 -> V_63 ;
T_13 V_457 = F_84 ( V_29 -> V_69 ) ;
T_13 V_458 = F_84 ( V_29 -> V_49 ) ;
int V_459 ;
if ( V_103 -> V_460 == V_141 ) {
V_454 = 1 ;
V_455 = V_103 -> V_461 ;
} else if ( V_103 -> V_460 == V_462 ) {
V_454 = 4 ;
V_455 = V_103 -> V_461 ;
} else if ( F_274 ( & V_8 -> V_463 ) ) {
V_454 = 2 ;
V_455 = V_8 -> V_463 . V_451 ;
} else {
V_454 = 0 ;
V_455 = V_79 ;
}
if ( V_8 -> V_85 == V_86 )
V_459 = V_8 -> V_464 ;
else
V_459 = F_275 ( int , V_14 -> V_465 - V_14 -> V_466 , 0 ) ;
F_270 ( V_448 , L_11
L_12 ,
V_449 , V_456 , V_458 , V_5 , V_457 , V_8 -> V_85 ,
V_14 -> V_17 - V_14 -> V_120 ,
V_459 ,
V_454 ,
F_271 ( V_455 - V_79 ) ,
V_103 -> V_134 ,
F_246 ( V_8 ) ,
V_103 -> V_467 ,
F_276 ( V_8 ) ,
F_272 ( & V_8 -> V_453 ) , V_8 ,
F_271 ( V_103 -> V_136 ) ,
F_271 ( V_103 -> V_468 . V_469 ) ,
( V_103 -> V_468 . V_470 << 1 ) | V_103 -> V_468 . V_471 ,
V_14 -> V_472 ,
F_277 ( V_14 ) ? - 1 : V_14 -> V_473 ,
V_109 ) ;
}
static void F_278 ( const struct V_203 * V_204 ,
struct V_391 * V_448 , int V_449 , int * V_109 )
{
T_3 V_5 , V_456 ;
T_13 V_457 , V_458 ;
int V_450 = V_204 -> V_474 - V_79 ;
if ( V_450 < 0 )
V_450 = 0 ;
V_5 = V_204 -> V_475 ;
V_456 = V_204 -> V_476 ;
V_457 = F_84 ( V_204 -> V_477 ) ;
V_458 = F_84 ( V_204 -> V_478 ) ;
F_270 ( V_448 , L_9
L_13 ,
V_449 , V_456 , V_458 , V_5 , V_457 , V_204 -> V_479 , 0 , 0 ,
3 , F_271 ( V_450 ) , 0 , 0 , 0 , 0 ,
F_272 ( & V_204 -> V_480 ) , V_204 , V_109 ) ;
}
static int F_279 ( struct V_391 * V_105 , void * V_432 )
{
struct V_396 * V_397 ;
int V_109 ;
if ( V_432 == V_431 ) {
F_270 ( V_105 , L_14 , V_481 - 1 ,
L_15
L_16
L_17 ) ;
goto V_116;
}
V_397 = V_105 -> V_398 ;
switch ( V_397 -> V_404 ) {
case V_413 :
case V_426 :
F_273 ( V_432 , V_105 , V_397 -> V_403 , & V_109 ) ;
break;
case V_405 :
F_269 ( V_397 -> V_406 , V_432 , V_105 , V_397 -> V_403 , V_397 -> V_417 , & V_109 ) ;
break;
case V_424 :
F_278 ( V_432 , V_105 , V_397 -> V_403 , & V_109 ) ;
break;
}
F_270 ( V_105 , L_18 , V_481 - 1 - V_109 , L_6 ) ;
V_116:
return 0 ;
}
static int T_14 F_280 ( struct V_107 * V_107 )
{
return F_265 ( V_107 , & V_482 ) ;
}
static void T_15 F_281 ( struct V_107 * V_107 )
{
F_267 ( V_107 , & V_482 ) ;
}
int T_16 F_282 ( void )
{
return F_283 ( & V_483 ) ;
}
void F_284 ( void )
{
F_285 ( & V_483 ) ;
}
struct V_1 * * F_286 ( struct V_1 * * V_157 , struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_287 ( V_2 ) ;
switch ( V_2 -> V_153 ) {
case V_339 :
if ( ! F_70 ( F_288 ( V_2 ) , V_97 -> V_4 , V_97 -> V_3 ,
V_2 -> V_160 ) ) {
V_2 -> V_153 = V_340 ;
break;
}
case V_484 :
F_289 ( V_2 ) -> V_485 = 1 ;
return NULL ;
}
return F_290 ( V_157 , V_2 ) ;
}
int F_291 ( struct V_1 * V_2 )
{
const struct V_96 * V_97 = F_3 ( V_2 ) ;
struct V_99 * V_100 = F_4 ( V_2 ) ;
V_100 -> V_155 = ~ F_70 ( V_2 -> V_109 - F_292 ( V_2 ) ,
V_97 -> V_4 , V_97 -> V_3 , 0 ) ;
F_293 ( V_2 ) -> V_486 = V_77 ;
return F_294 ( V_2 ) ;
}
static int T_14 F_295 ( struct V_107 * V_107 )
{
return 0 ;
}
static void T_15 F_296 ( struct V_107 * V_107 )
{
}
static void T_15 F_297 ( struct V_487 * V_488 )
{
F_298 ( & V_111 , & V_66 , V_42 ) ;
}
void T_16 F_299 ( void )
{
F_300 ( & V_111 ) ;
if ( F_283 ( & V_489 ) )
F_301 ( L_19 ) ;
}
