static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 = ( void * ) V_8 -> V_11 ;
F_3 ( V_2 , L_1
L_2 ,
F_4 ( V_10 -> V_12 ) ,
V_10 -> V_13 ,
F_5 ( V_10 -> V_14 ) ,
F_4 ( V_10 -> V_15 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_16 * V_17 = ( void * ) V_8 -> V_11 ;
struct V_18 * V_19 = & V_2 -> V_20 [ V_21 ] ;
struct V_22 * V_23 = ( void * ) & V_19 -> V_24 ;
if ( ! F_7 ( V_25 , & V_2 -> V_26 ) )
return 0 ;
if ( ! F_4 ( V_17 -> V_26 ) && V_17 -> V_27 == V_2 -> V_28 ) {
V_23 -> V_27 = V_17 -> V_27 ;
V_19 -> V_29 . V_27 = V_17 -> V_27 ;
F_8 ( V_2 , L_3 ,
F_5 ( V_17 -> V_27 ) ) ;
F_9 ( V_2 , true ) ;
} else {
F_3 ( V_2 , L_4 ,
F_5 ( V_17 -> V_27 ) ) ;
F_9 ( V_2 , false ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_30 * V_31 = ( void * ) V_8 -> V_11 ;
if ( ! V_31 -> V_32 ) {
F_8 ( V_2 ,
L_5 ) ;
return 0 ;
}
memcpy ( & V_2 -> V_33 , V_31 , sizeof( * V_31 ) ) ;
V_2 -> V_34 |= V_35 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
#ifdef F_12
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_36 * V_37 = ( void * ) V_8 -> V_11 ;
F_13 ( V_2 , L_6 ,
V_37 -> V_38 , V_37 -> V_39 ) ;
#endif
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_1 T_2 V_40 =
F_4 ( V_8 -> V_41 ) & V_42 ;
F_15 ( V_2 , L_7
L_8 , V_40 ) ;
F_16 ( V_2 , V_43 , V_8 -> V_11 , V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_44 * V_45 = ( void * ) V_8 -> V_11 ;
#ifdef F_12
T_3 V_26 = F_5 ( V_45 -> V_46 . V_26 . V_26 ) ;
T_4 V_47 = F_18 ( V_45 -> V_46 . V_48 ) ;
F_13 ( V_2 , L_9
L_10 ,
V_26 & V_49 ,
V_45 -> V_46 . V_50 ,
F_4 ( V_45 -> V_51 ) ,
F_4 ( V_45 -> V_52 ) ,
F_4 ( V_45 -> V_53 ) , V_47 ) ;
#endif
V_2 -> V_54 = F_4 ( V_45 -> V_51 ) ;
return 0 ;
}
static bool F_19 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_57 * V_58 ,
unsigned int V_59 )
{
int V_60 ;
int V_61 = V_2 -> V_62 ;
if ( V_61 == V_63 ) {
F_15 ( V_2 , L_11 ) ;
return true ;
}
V_60 = F_4 ( V_56 -> V_64 ) -
F_4 ( V_2 -> V_65 . V_66 . V_64 ) +
F_4 ( V_58 -> V_64 ) -
F_4 ( V_2 -> V_65 . V_67 . V_64 ) ;
if ( V_60 <= 0 )
return true ;
if ( ( V_60 * 100 / V_59 ) > V_61 ) {
F_15 ( V_2 ,
L_12 ,
V_61 , V_60 , V_59 ) ;
return false ;
}
return true ;
}
int F_20 ( struct V_1 * V_2 , bool V_68 )
{
struct V_69 * V_70 ;
if ( F_7 ( V_71 , & V_2 -> V_26 ) )
return - V_72 ;
if ( ! F_21 ( V_2 ) ) {
F_22 ( V_2 , L_13 ) ;
return - V_73 ;
}
V_70 = & V_2 -> V_70 ;
V_70 -> V_74 ++ ;
if ( ! V_68 && V_70 -> V_75 &&
F_23 ( V_70 -> V_75 +
V_76 , V_77 ) ) {
F_24 ( V_2 , L_14 ) ;
V_70 -> V_78 ++ ;
return - V_72 ;
}
V_70 -> V_79 ++ ;
V_70 -> V_75 = V_77 ;
F_24 ( V_2 , L_15 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_57 * V_58 ,
struct V_80 * V_81 ,
unsigned long V_82 )
{
unsigned int V_59 ;
if ( F_7 ( V_71 , & V_2 -> V_26 ) )
return;
V_59 = F_27 ( V_82 - V_2 -> V_83 ) ;
if ( ! F_21 ( V_2 ) )
return;
if ( V_59 < 99 )
return;
if ( V_84 . V_85 &&
! F_19 ( V_2 , V_56 , V_58 , V_59 ) )
F_20 ( V_2 , false ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_86 * V_87 ;
int V_88 = 0 ;
int V_89 = 0 ;
int V_90 , V_91 , V_92 ;
int V_93 ;
V_87 = & V_2 -> V_65 . V_94 ;
V_90 =
F_4 ( V_87 -> V_95 ) & V_96 ;
V_91 =
F_4 ( V_87 -> V_97 ) & V_96 ;
V_92 =
F_4 ( V_87 -> V_98 ) & V_96 ;
if ( V_90 ) {
V_89 += V_90 ;
V_88 ++ ;
}
if ( V_91 ) {
V_89 += V_91 ;
V_88 ++ ;
}
if ( V_92 ) {
V_89 += V_92 ;
V_88 ++ ;
}
if ( V_88 )
V_93 = ( V_89 / V_88 ) - 107 ;
else
V_93 = V_99 ;
F_29 ( V_2 , L_16 ,
V_90 , V_91 , V_92 ,
V_93 ) ;
}
static void F_30 ( T_5 * V_100 , T_5 * V_101 , T_5 * V_60 ,
T_5 * V_102 , T_5 * V_103 , int V_104 )
{
int V_105 ;
for ( V_105 = 0 ;
V_105 < V_104 / sizeof( T_5 ) ;
V_105 ++ , V_100 ++ , V_101 ++ , V_60 ++ , V_102 ++ , V_103 ++ ) {
if ( F_4 ( * V_101 ) > F_4 ( * V_100 ) ) {
* V_60 = F_31 (
F_4 ( * V_101 ) - F_4 ( * V_100 ) ) ;
F_32 ( V_103 , F_4 ( * V_60 ) ) ;
if ( F_4 ( * V_60 ) > F_4 ( * V_102 ) )
* V_102 = * V_60 ;
}
}
}
static void
F_33 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_86 * V_94 ,
struct V_55 * V_66 ,
struct V_57 * V_67 ,
struct V_55 * V_108 ,
struct V_80 * V_81 ,
struct V_109 * V_110 )
{
#define F_34 ( T_6 ) \
accum_stats((__le32 *)&priv->statistics._name, \
(__le32 *)_name, \
(__le32 *)&priv->delta_stats._name, \
(__le32 *)&priv->max_delta_stats._name, \
(__le32 *)&priv->accum_stats._name, \
sizeof(*_name));
F_34 ( V_107 ) ;
F_34 ( V_94 ) ;
F_34 ( V_66 ) ;
F_34 ( V_67 ) ;
F_34 ( V_108 ) ;
F_34 ( V_81 ) ;
if ( V_110 )
F_34 ( V_110 ) ;
#undef F_34
}
static inline void
F_33 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
struct V_86 * V_94 ,
struct V_55 * V_66 ,
struct V_57 * V_67 ,
struct V_55 * V_108 ,
struct V_80 * V_81 ,
struct V_109 * V_110 )
{
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
unsigned long V_82 = V_77 ;
const int V_111 = 60 ;
int V_112 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_1 V_40 = F_4 ( V_8 -> V_41 ) & V_42 ;
T_5 * V_113 ;
struct V_106 * V_107 ;
struct V_86 * V_94 ;
struct V_55 * V_66 ;
struct V_57 * V_67 ;
struct V_55 * V_108 ;
struct V_80 * V_81 ;
struct V_109 * V_110 ;
V_40 -= sizeof( struct V_114 ) ;
F_13 ( V_2 , L_17 ,
V_40 ) ;
F_36 ( & V_2 -> V_65 . V_115 ) ;
if ( V_40 == sizeof( struct V_116 ) ) {
struct V_116 * V_117 ;
V_117 = ( void * ) & V_8 -> V_11 ;
V_113 = & V_117 -> V_113 ;
V_107 = & V_117 -> V_118 . V_107 ;
V_94 = & V_117 -> V_119 . V_118 . V_107 ;
V_66 = & V_117 -> V_119 . V_120 ;
V_67 = & V_117 -> V_119 . V_121 ;
V_108 = & V_117 -> V_119 . V_122 ;
V_81 = & V_117 -> V_81 ;
V_110 = & V_117 -> V_118 . V_123 ;
#ifdef F_37
V_2 -> V_65 . V_124 = V_117 -> V_119 . V_118 . V_124 ;
F_32 ( & V_2 -> V_65 . V_125 ,
F_4 ( V_117 -> V_119 . V_118 . V_124 ) ) ;
#endif
} else if ( V_40 == sizeof( struct V_126 ) ) {
struct V_126 * V_117 ;
V_117 = ( void * ) & V_8 -> V_11 ;
V_113 = & V_117 -> V_113 ;
V_107 = & V_117 -> V_118 . V_107 ;
V_94 = & V_117 -> V_119 . V_118 ;
V_66 = & V_117 -> V_119 . V_120 ;
V_67 = & V_117 -> V_119 . V_121 ;
V_108 = & V_117 -> V_119 . V_122 ;
V_81 = & V_117 -> V_81 ;
V_110 = NULL ;
} else {
F_38 ( 1 , L_18 ,
V_40 , sizeof( struct V_116 ) ,
sizeof( struct V_126 ) ) ;
F_39 ( & V_2 -> V_65 . V_115 ) ;
return 0 ;
}
V_112 = V_107 -> V_127 != V_2 -> V_65 . V_107 . V_127 ||
( * V_113 & V_128 ) !=
( V_2 -> V_65 . V_113 & V_128 ) ;
F_33 ( V_2 , V_107 , V_94 , V_66 ,
V_67 , V_108 , V_81 , V_110 ) ;
F_26 ( V_2 , V_66 , V_67 , V_81 , V_82 ) ;
V_2 -> V_65 . V_113 = * V_113 ;
memcpy ( & V_2 -> V_65 . V_107 , V_107 , sizeof( * V_107 ) ) ;
memcpy ( & V_2 -> V_65 . V_94 , V_94 , sizeof( * V_94 ) ) ;
memcpy ( & V_2 -> V_65 . V_66 , V_66 , sizeof( * V_66 ) ) ;
memcpy ( & V_2 -> V_65 . V_67 , V_67 , sizeof( * V_67 ) ) ;
memcpy ( & V_2 -> V_65 . V_108 , V_108 , sizeof( * V_108 ) ) ;
memcpy ( & V_2 -> V_65 . V_81 , V_81 , sizeof( * V_81 ) ) ;
#ifdef F_37
if ( V_110 )
memcpy ( & V_2 -> V_65 . V_110 , V_110 ,
sizeof( * V_110 ) ) ;
#endif
V_2 -> V_83 = V_82 ;
F_40 ( V_129 , & V_2 -> V_26 ) ;
F_41 ( & V_2 -> V_130 , V_77 +
F_42 ( V_111 * 1000 ) ) ;
if ( F_43 ( ! F_7 ( V_131 , & V_2 -> V_26 ) ) &&
( V_8 -> V_132 . V_6 == V_133 ) ) {
F_28 ( V_2 ) ;
F_44 ( V_2 -> V_134 , & V_2 -> V_135 ) ;
}
if ( V_2 -> V_136 -> V_127 && V_112 )
V_2 -> V_136 -> V_127 ( V_2 ) ;
F_39 ( & V_2 -> V_65 . V_115 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_126 * V_117 = ( void * ) V_8 -> V_11 ;
if ( F_4 ( V_117 -> V_113 ) & V_137 ) {
#ifdef F_37
memset ( & V_2 -> F_30 , 0 ,
sizeof( V_2 -> F_30 ) ) ;
memset ( & V_2 -> V_138 , 0 ,
sizeof( V_2 -> V_138 ) ) ;
memset ( & V_2 -> V_139 , 0 ,
sizeof( V_2 -> V_139 ) ) ;
#endif
F_13 ( V_2 , L_19 ) ;
}
F_35 ( V_2 , V_4 , V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_140 * V_141 = ( void * ) V_8 -> V_11 ;
T_1 V_142 = F_4 ( V_141 -> V_142 ) ;
unsigned long V_26 = V_2 -> V_26 ;
F_47 ( V_2 , L_20 ,
( V_142 & V_143 ) ? L_21 : L_22 ,
( V_142 & V_144 ) ? L_21 : L_22 ,
( V_142 & V_145 ) ?
L_23 : L_24 ) ;
if ( V_142 & ( V_144 | V_143 |
V_145 ) ) {
F_48 ( V_2 -> V_146 , V_147 ,
V_148 ) ;
F_49 ( V_2 -> V_146 , V_149 ,
V_150 ) ;
if ( ! ( V_142 & V_151 ) ) {
F_48 ( V_2 -> V_146 , V_152 ,
V_148 ) ;
F_49 ( V_2 -> V_146 , V_149 ,
V_150 ) ;
}
if ( V_142 & V_145 )
F_50 ( V_2 ) ;
}
if ( ! ( V_142 & V_145 ) )
F_51 ( V_2 ) ;
if ( V_142 & V_143 )
F_40 ( V_153 , & V_2 -> V_26 ) ;
else
F_52 ( V_153 , & V_2 -> V_26 ) ;
if ( ! ( V_142 & V_151 ) )
F_53 ( V_2 ) ;
if ( ( F_7 ( V_153 , & V_26 ) !=
F_7 ( V_153 , & V_2 -> V_26 ) ) )
F_54 ( V_2 -> V_154 -> V_155 ,
F_7 ( V_153 , & V_2 -> V_26 ) ) ;
else
F_55 ( & V_2 -> V_146 -> V_156 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_157 * V_158 = ( void * ) V_8 -> V_11 ;
if ( F_4 ( V_158 -> V_159 ) >
V_2 -> V_160 ) {
F_29 ( V_2 ,
L_25 ,
F_4 ( V_158 -> V_159 ) ,
F_4 ( V_158 -> V_161 ) ,
F_4 ( V_158 -> V_162 ) ,
F_4 ( V_158 -> V_163 ) ) ;
if ( ! F_7 ( V_131 , & V_2 -> V_26 ) )
F_57 ( V_2 ) ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
V_2 -> V_164 = true ;
memcpy ( & V_2 -> V_165 , V_8 -> V_11 ,
sizeof( struct V_166 ) ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_167 * V_132 ,
T_1 V_168 ,
struct V_169 * V_117 )
{
T_3 V_170 = F_5 ( V_132 -> V_171 ) ;
if ( V_2 -> V_20 [ V_21 ] . V_24 . V_172 &
V_173 )
return 0 ;
if ( ! ( V_170 & V_174 ) )
return 0 ;
F_13 ( V_2 , L_26 , V_168 ) ;
switch ( V_168 & V_175 ) {
case V_176 :
if ( ( V_168 & V_177 ) ==
V_178 )
break;
case V_179 :
if ( ( V_168 & V_177 ) ==
V_180 ) {
F_13 ( V_2 , L_27 ) ;
return - 1 ;
}
case V_181 :
if ( ( V_168 & V_177 ) ==
V_182 ) {
F_13 ( V_2 , L_28 ) ;
V_117 -> V_113 |= V_183 ;
}
break;
default:
break;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_167 * V_132 ,
T_3 V_40 ,
T_1 V_184 ,
struct V_3 * V_4 ,
struct V_169 * V_117 )
{
struct V_185 * V_186 ;
T_7 V_170 = V_132 -> V_171 ;
struct V_18 * V_19 ;
unsigned int V_187 , V_188 ;
if ( F_43 ( ! V_2 -> V_189 ) ) {
F_61 ( V_2 ,
L_29 ) ;
return;
}
if ( ! V_84 . V_190 &&
F_59 ( V_2 , V_132 , V_184 , V_117 ) )
return;
V_186 = F_62 ( 128 , V_191 ) ;
if ( ! V_186 ) {
F_3 ( V_2 , L_30 ) ;
return;
}
V_187 = ( V_40 <= F_63 ( V_186 ) ) ? V_40 : sizeof( * V_132 ) ;
memcpy ( F_64 ( V_186 , V_187 ) , V_132 , V_187 ) ;
V_188 = V_40 - V_187 ;
if ( V_188 ) {
int V_192 = ( void * ) V_132 + V_187 -
F_2 ( V_4 ) + F_65 ( V_4 ) ;
F_66 ( V_186 , 0 , F_67 ( V_4 ) , V_192 ,
V_188 , V_4 -> V_193 ) ;
}
if ( F_43 ( F_68 ( V_170 ) && V_2 -> V_194 ) ) {
F_69 (priv, ctx) {
if ( ! F_70 ( V_132 -> V_195 ,
V_19 -> V_24 . V_196 ) )
continue;
F_71 ( V_2 ) ;
}
}
memcpy ( F_72 ( V_186 ) , V_117 , sizeof( * V_117 ) ) ;
F_73 ( V_2 -> V_154 , V_186 ) ;
}
static T_1 F_74 ( struct V_1 * V_2 , T_1 V_197 )
{
T_1 V_198 = 0 ;
if ( ( V_197 & V_199 ) ==
V_199 )
V_198 |= ( V_199 |
V_200 ) ;
V_198 |= ( V_197 & V_175 ) ;
if ( ( V_197 & V_175 ) ==
V_201 )
return V_198 ;
if ( ( V_197 & V_175 ) ==
V_202 )
return V_198 ;
if ( ( V_197 & V_203 ) !=
V_203 )
return V_198 ;
switch ( V_197 & V_175 ) {
case V_181 :
if ( ! ( V_197 & V_204 ) )
V_198 |= V_180 ;
else
V_198 |= V_182 ;
break;
case V_176 :
if ( ! ( V_197 & V_205 ) ) {
V_198 |= V_178 ;
break;
}
default:
if ( ! ( V_197 & V_206 ) )
V_198 |= V_180 ;
else
V_198 |= V_182 ;
break;
}
F_13 ( V_2 , L_31 ,
V_197 , V_198 ) ;
return V_198 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_166 * V_207 )
{
struct V_208 * V_209 =
(struct V_208 * ) V_207 -> V_210 ;
T_1 V_211 , V_212 , V_213 , V_214 , V_215 ;
T_4 V_216 ;
V_211 = F_4 ( V_209 -> V_217 [ V_218 ] ) ;
V_216 = ( V_211 & V_219 ) >> V_220 ;
V_211 = F_4 ( V_209 -> V_217 [ V_221 ] ) ;
V_212 = ( V_211 & V_222 ) >>
V_223 ;
V_213 = ( V_211 & V_224 ) >>
V_225 ;
V_211 = F_4 ( V_209 -> V_217 [ V_226 ] ) ;
V_214 = ( V_211 & V_227 ) >>
V_228 ;
V_215 = F_76 ( T_1 , V_212 , V_213 ) ;
V_215 = F_76 ( T_1 , V_215 , V_214 ) ;
F_77 ( V_2 , L_32 ,
V_212 , V_213 , V_214 , V_215 , V_216 ) ;
return V_215 - V_216 - V_229 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_167 * V_230 ;
struct V_169 V_231 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_166 * V_232 ;
T_5 V_233 ;
struct V_234 * V_235 ;
T_1 V_40 ;
T_1 V_184 ;
T_1 V_48 ;
if ( V_8 -> V_132 . V_6 == V_236 ) {
V_232 = (struct V_166 * ) V_8 -> V_11 ;
V_230 = (struct V_167 * ) ( V_8 -> V_11 + sizeof( * V_232 )
+ V_232 -> V_237 ) ;
V_40 = F_5 ( V_232 -> V_238 ) ;
V_233 = * ( T_5 * ) ( V_8 -> V_11 + sizeof( * V_232 ) +
V_232 -> V_237 + V_40 ) ;
V_184 = F_4 ( V_233 ) ;
} else {
if ( ! V_2 -> V_164 ) {
F_3 ( V_2 , L_33 ) ;
return 0 ;
}
V_232 = & V_2 -> V_165 ;
V_235 = (struct V_234 * ) V_8 -> V_11 ;
V_230 = (struct V_167 * ) ( V_8 -> V_11 + sizeof( * V_235 ) ) ;
V_40 = F_5 ( V_235 -> V_238 ) ;
V_233 = * ( T_5 * ) ( V_8 -> V_11 + sizeof( * V_235 ) + V_40 ) ;
V_184 = F_74 ( V_2 ,
F_4 ( V_233 ) ) ;
}
if ( ( F_43 ( V_232 -> V_237 > 20 ) ) ) {
F_79 ( V_2 , L_34 ,
V_232 -> V_237 ) ;
return 0 ;
}
if ( ! ( V_233 & V_239 ) ||
! ( V_233 & V_240 ) ) {
F_13 ( V_2 , L_35 ,
F_4 ( V_233 ) ) ;
return 0 ;
}
V_48 = F_4 ( V_232 -> V_48 ) ;
V_231 . V_241 = F_80 ( V_232 -> V_242 ) ;
V_231 . V_243 = ( V_232 -> V_244 & V_245 ) ?
V_246 : V_247 ;
V_231 . V_248 =
F_81 ( F_5 ( V_232 -> V_27 ) ,
V_231 . V_243 ) ;
V_231 . V_249 =
F_82 ( V_48 , V_231 . V_243 ) ;
V_231 . V_113 = 0 ;
V_2 -> V_250 = F_4 ( V_232 -> V_251 ) ;
V_231 . signal = F_75 ( V_2 , V_232 ) ;
F_83 ( V_2 , L_36 ,
V_231 . signal , ( unsigned long long ) V_231 . V_241 ) ;
V_231 . V_252 =
( F_5 ( V_232 -> V_244 ) & V_253 )
>> V_254 ;
if ( V_232 -> V_244 & V_255 )
V_231 . V_113 |= V_256 ;
if ( V_48 & V_257 )
V_231 . V_113 |= V_258 ;
if ( V_48 & V_259 )
V_231 . V_113 |= V_260 ;
if ( V_48 & V_261 )
V_231 . V_113 |= V_262 ;
F_60 ( V_2 , V_230 , V_40 , V_184 ,
V_4 , & V_231 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_263 * V_264 , * V_265 ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_266 * V_267 = ( void * ) V_8 -> V_11 ;
V_265 = F_85 ( V_2 -> V_268 , true ) ;
if ( V_267 -> V_269 ) {
T_1 V_40 = F_5 ( V_267 -> V_270 . V_271 ) ;
T_1 V_272 = V_40 ;
V_40 += 1 + 1 + 3 + 1 ;
V_40 += 1 + 2 ;
V_272 += 1 + 2 ;
V_264 = F_86 ( sizeof( * V_264 ) + V_40 , V_191 ) ;
if ( V_264 ) {
V_264 -> V_271 = V_40 ;
V_264 -> V_11 [ 0 ] = V_273 ;
V_264 -> V_11 [ 1 ] = V_40 - 2 ;
V_264 -> V_11 [ 2 ] = ( V_274 >> 16 ) & 0xff ;
V_264 -> V_11 [ 3 ] = ( V_274 >> 8 ) & 0xff ;
V_264 -> V_11 [ 4 ] = ( V_274 >> 0 ) & 0xff ;
V_264 -> V_11 [ 5 ] = V_275 ;
memcpy ( & V_264 -> V_11 [ 6 ] , & V_267 -> V_270 ,
V_272 ) ;
}
} else
V_264 = NULL ;
F_87 ( V_2 -> V_268 , V_264 ) ;
if ( V_265 )
F_88 ( V_265 , V_276 ) ;
return 0 ;
}
void F_89 ( struct V_1 * V_2 )
{
int (* * F_90)( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 );
F_90 = V_2 -> V_277 ;
F_90 [ V_278 ] = F_1 ;
F_90 [ V_279 ] = F_6 ;
F_90 [ V_280 ] =
F_10 ;
F_90 [ V_281 ] = F_11 ;
F_90 [ V_282 ] =
F_14 ;
F_90 [ V_283 ] = F_17 ;
F_90 [ V_284 ] = V_285 ;
F_90 [ V_286 ] = F_84 ;
F_90 [ V_287 ] = F_45 ;
F_90 [ V_133 ] = F_35 ;
F_91 ( V_2 ) ;
F_90 [ V_288 ] = F_46 ;
F_90 [ V_289 ] =
F_56 ;
F_90 [ V_290 ] = F_58 ;
F_90 [ V_291 ] = F_78 ;
F_90 [ V_292 ] =
V_293 ;
V_2 -> V_277 [ V_294 ] = V_295 ;
F_92 ( & V_2 -> V_296 ) ;
if ( V_2 -> V_297 -> V_298 )
F_93 ( V_2 ) ;
}
int F_94 ( struct V_299 * V_300 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_95 ( V_300 ) ;
void (* F_96)( struct V_1 * ,
struct V_3 * );
int V_301 = 0 ;
F_97 ( & V_2 -> V_296 , V_8 ) ;
F_96 = F_98 ( V_2 -> F_96 ) ;
if ( F_96 )
F_96 ( V_2 , V_4 ) ;
if ( V_2 -> V_302 != V_303 ) {
if ( V_2 -> V_277 [ V_8 -> V_132 . V_6 ] ) {
V_2 -> V_304 [ V_8 -> V_132 . V_6 ] ++ ;
V_301 = V_2 -> V_277 [ V_8 -> V_132 . V_6 ] ( V_2 , V_4 , V_6 ) ;
} else {
F_13 ( V_2 , L_37 ,
F_99 ( V_8 -> V_132 . V_6 ) ,
V_8 -> V_132 . V_6 ) ;
}
}
return V_301 ;
}
