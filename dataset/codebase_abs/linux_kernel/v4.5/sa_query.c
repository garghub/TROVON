static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 & V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 -> V_11 [ 1 ] ;
struct V_12 * V_13 = V_2 -> V_10 -> V_13 ;
T_1 V_14 = V_13 -> V_15 . V_14 ;
T_2 V_16 ;
T_3 V_17 ;
struct V_18 * V_19 ;
V_2 -> V_10 -> V_11 [ 1 ] = NULL ;
V_19 = (struct V_18 * )
F_4 ( V_7 , F_5 ( sizeof( * V_19 ) ) ) ;
memcpy ( V_19 -> V_20 , V_2 -> V_21 -> V_22 -> V_23 -> V_24 ,
V_25 ) ;
V_19 -> V_26 = V_2 -> V_21 -> V_26 ;
if ( ( V_14 & V_27 ) &&
V_9 -> V_28 != 0 )
V_2 -> V_29 = V_30 ;
else
V_2 -> V_29 = V_31 ;
V_19 -> V_29 = V_2 -> V_29 ;
if ( V_14 & V_32 ) {
V_17 = F_6 ( V_9 -> V_33 ) ;
F_7 ( V_7 , V_34 | V_35 ,
sizeof( V_17 ) , & V_17 ) ;
}
if ( V_14 & V_36 )
F_7 ( V_7 , V_34 | V_37 ,
sizeof( V_9 -> V_38 ) , & V_9 -> V_38 ) ;
if ( V_14 & V_39 )
F_7 ( V_7 , V_34 | V_40 ,
sizeof( V_9 -> V_41 ) , & V_9 -> V_41 ) ;
if ( V_14 & V_42 )
F_7 ( V_7 , V_34 | V_43 ,
sizeof( V_9 -> V_44 ) , & V_9 -> V_44 ) ;
if ( V_14 & V_45 ) {
V_16 = F_8 ( V_9 -> V_46 ) ;
F_7 ( V_7 , V_34 | V_47 ,
sizeof( V_16 ) , & V_16 ) ;
}
if ( V_14 & V_48 ) {
V_16 = F_8 ( V_9 -> V_49 ) ;
F_7 ( V_7 , V_34 | V_50 ,
sizeof( V_16 ) , & V_16 ) ;
}
}
static int F_9 ( T_1 V_14 )
{
int V_51 = 0 ;
if ( V_14 & V_32 )
V_51 += F_10 ( sizeof( T_3 ) ) ;
if ( V_14 & V_36 )
V_51 += F_10 ( sizeof( struct V_52 ) ) ;
if ( V_14 & V_39 )
V_51 += F_10 ( sizeof( struct V_52 ) ) ;
if ( V_14 & V_42 )
V_51 += F_10 ( sizeof( V_53 ) ) ;
if ( V_14 & V_45 )
V_51 += F_10 ( sizeof( T_2 ) ) ;
if ( V_14 & V_48 )
V_51 += F_10 ( sizeof( T_2 ) ) ;
if ( F_11 ( V_51 == 0 ) )
return V_51 ;
V_51 += F_5 ( sizeof( struct V_18 ) ) ;
return V_51 ;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_54 )
{
struct V_6 * V_7 = NULL ;
struct V_55 * V_56 ;
void * V_57 ;
int V_58 = 0 ;
struct V_12 * V_13 ;
int V_51 ;
V_13 = V_2 -> V_10 -> V_13 ;
V_51 = F_9 ( V_13 -> V_15 . V_14 ) ;
if ( V_51 <= 0 )
return - V_59 ;
V_7 = F_13 ( V_51 , V_54 ) ;
if ( ! V_7 )
return - V_60 ;
V_57 = F_14 ( V_7 , & V_56 , V_2 -> V_61 , 0 , V_62 ,
V_63 , V_64 ) ;
if ( ! V_57 ) {
F_15 ( V_7 ) ;
return - V_59 ;
}
F_3 ( V_7 , V_2 ) ;
F_16 ( V_7 , V_56 ) ;
V_58 = F_17 ( V_7 , V_56 , V_65 , V_54 ) ;
if ( ! V_58 )
V_58 = V_51 ;
else
V_58 = 0 ;
return V_58 ;
}
static int F_18 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
unsigned long V_66 ;
int V_58 ;
F_19 ( & V_2 -> V_67 ) ;
V_2 -> V_61 = ( V_68 ) F_20 ( & V_69 ) ;
F_21 ( & V_70 , V_3 ) ;
V_66 = F_22 ( V_71 ) ;
V_2 -> V_72 = V_66 + V_73 ;
F_23 ( & V_2 -> V_67 , & V_74 ) ;
if ( V_74 . V_75 == & V_2 -> V_67 )
F_24 ( V_76 , & V_77 , V_66 ) ;
F_25 ( & V_70 , V_3 ) ;
V_58 = F_12 ( V_2 , V_54 ) ;
if ( V_58 <= 0 ) {
V_58 = - V_78 ;
F_21 ( & V_70 , V_3 ) ;
F_26 ( & V_2 -> V_67 ) ;
F_25 ( & V_70 , V_3 ) ;
} else {
V_58 = 0 ;
}
return V_58 ;
}
static int F_27 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_1 * V_79 ;
int V_80 = 0 ;
F_21 ( & V_70 , V_3 ) ;
F_28 (wait_query, &ib_nl_request_list, list) {
if ( V_2 == V_79 ) {
V_2 -> V_3 |= V_5 ;
V_2 -> V_72 = V_73 ;
F_29 ( & V_2 -> V_67 , & V_74 ) ;
V_80 = 1 ;
F_30 ( V_76 , & V_77 , 1 ) ;
break;
}
}
F_25 ( & V_70 , V_3 ) ;
return V_80 ;
}
static void F_31 ( struct V_1 * V_2 ,
const struct V_55 * V_56 )
{
struct V_81 V_82 ;
struct V_12 * V_13 = NULL ;
const struct V_83 * V_84 , * V_85 ;
struct V_86 * V_87 ;
int V_51 , V_88 ;
V_68 V_89 = 0 ;
int V_90 = - V_78 ;
if ( V_2 -> V_91 ) {
V_84 = ( const struct V_83 * ) F_32 ( V_56 ) ;
V_51 = F_33 ( V_56 ) ;
switch ( V_2 -> V_29 ) {
case V_31 :
V_89 = V_92 | V_93 ;
break;
case V_94 :
case V_30 :
default:
V_89 = V_92 | V_95 |
V_96 ;
break;
}
F_34 (curr, head, len, rem) {
if ( V_85 -> V_97 == V_98 ) {
V_87 = F_35 ( V_85 ) ;
if ( ( V_87 -> V_3 & V_89 ) == V_89 ) {
V_13 = V_2 -> V_10 -> V_13 ;
V_13 -> V_99 . V_100 |=
V_101 ;
memcpy ( V_13 -> V_57 , V_87 -> V_102 ,
sizeof( V_87 -> V_102 ) ) ;
V_90 = 0 ;
break;
}
}
}
V_2 -> V_91 ( V_2 , V_90 , V_13 ) ;
}
V_82 . V_103 = V_2 -> V_10 ;
V_82 . V_90 = V_104 ;
F_36 ( V_2 -> V_10 -> V_105 , & V_82 ) ;
}
static void F_37 ( struct V_106 * V_107 )
{
unsigned long V_3 ;
struct V_1 * V_2 ;
unsigned long V_66 ;
struct V_81 V_82 ;
int V_58 ;
F_21 ( & V_70 , V_3 ) ;
while ( ! F_38 ( & V_74 ) ) {
V_2 = F_39 ( V_74 . V_75 ,
struct V_1 , V_67 ) ;
if ( F_40 ( V_2 -> V_72 , V_73 ) ) {
V_66 = V_2 -> V_72 - V_73 ;
if ( ( long ) V_66 <= 0 )
V_66 = 1 ;
F_24 ( V_76 , & V_77 , V_66 ) ;
break;
}
F_26 ( & V_2 -> V_67 ) ;
F_1 ( V_2 ) ;
if ( F_2 ( V_2 ) )
V_58 = - 1 ;
else
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
V_82 . V_103 = V_2 -> V_10 ;
V_82 . V_90 = V_108 ;
F_25 ( & V_70 , V_3 ) ;
F_36 ( V_2 -> V_21 -> V_22 , & V_82 ) ;
F_21 ( & V_70 , V_3 ) ;
}
}
F_25 ( & V_70 , V_3 ) ;
}
static int F_42 ( struct V_6 * V_7 ,
struct V_109 * V_110 )
{
const struct V_55 * V_56 = (struct V_55 * ) V_110 -> V_56 ;
int V_72 , V_111 , V_112 ;
const struct V_83 * V_113 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
long V_66 = 0 ;
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( ! ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) ||
! F_44 ( V_7 , V_118 ) )
return - V_119 ;
V_58 = F_45 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_120 ) ;
V_113 = ( const struct V_83 * ) V_114 [ V_121 ] ;
if ( V_58 || ! V_113 )
goto V_122;
V_72 = * ( int * ) F_35 ( V_113 ) ;
if ( V_72 < V_123 )
V_72 = V_123 ;
if ( V_72 > V_124 )
V_72 = V_124 ;
V_111 = V_72 - V_71 ;
if ( V_111 < 0 )
V_112 = - V_111 ;
else
V_112 = V_111 ;
if ( V_111 != 0 ) {
F_21 ( & V_70 , V_3 ) ;
V_71 = V_72 ;
F_28 (query, &ib_nl_request_list, list) {
if ( V_111 < 0 && V_112 > V_2 -> V_72 )
V_2 -> V_72 = 0 ;
else
V_2 -> V_72 += V_111 ;
if ( ! V_66 ) {
V_66 = V_2 -> V_72 - V_73 ;
if ( V_66 <= 0 )
V_66 = 1 ;
}
}
if ( V_66 )
F_30 ( V_76 , & V_77 ,
( unsigned long ) V_66 ) ;
F_25 ( & V_70 , V_3 ) ;
}
V_122:
return V_7 -> V_51 ;
}
static inline int F_46 ( const struct V_55 * V_56 )
{
struct V_83 * V_114 [ V_115 ] ;
int V_58 ;
if ( V_56 -> V_116 & V_125 )
return 0 ;
V_58 = F_45 ( V_114 , V_115 - 1 , F_32 ( V_56 ) ,
F_33 ( V_56 ) , V_120 ) ;
if ( V_58 )
return 0 ;
return 1 ;
}
static int F_47 ( struct V_6 * V_7 ,
struct V_109 * V_110 )
{
const struct V_55 * V_56 = (struct V_55 * ) V_110 -> V_56 ;
unsigned long V_3 ;
struct V_1 * V_2 ;
struct V_126 * V_103 ;
struct V_81 V_82 ;
int V_80 = 0 ;
int V_58 ;
if ( ( V_56 -> V_116 & V_64 ) ||
! ( F_43 ( V_7 ) . V_117 ) ||
! F_44 ( V_7 , V_118 ) )
return - V_119 ;
F_21 ( & V_70 , V_3 ) ;
F_28 (query, &ib_nl_request_list, list) {
if ( V_56 -> V_127 == V_2 -> V_61 ) {
V_80 = ! F_2 ( V_2 ) ;
if ( V_80 )
F_26 ( & V_2 -> V_67 ) ;
break;
}
}
if ( ! V_80 ) {
F_25 ( & V_70 , V_3 ) ;
goto V_128;
}
V_103 = V_2 -> V_10 ;
if ( ! F_46 ( V_56 ) ) {
F_1 ( V_2 ) ;
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
F_25 ( & V_70 , V_3 ) ;
if ( V_58 ) {
V_82 . V_103 = V_103 ;
V_82 . V_90 = V_129 ;
F_36 ( V_2 -> V_21 -> V_22 , & V_82 ) ;
}
} else {
F_25 ( & V_70 , V_3 ) ;
F_31 ( V_2 , V_56 ) ;
}
V_128:
return V_7 -> V_51 ;
}
static void F_48 ( struct V_130 * V_130 )
{
struct V_131 * V_132 = F_49 ( V_130 , struct V_131 , V_133 ) ;
F_50 ( V_132 -> V_134 ) ;
F_51 ( V_132 ) ;
}
static void F_52 ( struct V_106 * V_107 )
{
struct V_135 * V_21 =
F_49 ( V_107 , struct V_135 , V_136 ) ;
struct V_131 * V_137 ;
struct V_138 V_139 ;
struct V_140 V_141 ;
if ( F_53 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 , & V_139 ) ) {
F_54 ( V_142 L_1 ) ;
return;
}
V_137 = F_55 ( sizeof *V_137 , V_143 ) ;
if ( ! V_137 ) {
F_54 ( V_142 L_2 ) ;
return;
}
F_56 ( & V_137 -> V_133 ) ;
V_137 -> V_144 = ( 1 << V_139 . V_145 ) - 1 ;
V_137 -> V_146 = 0 ;
if ( F_57 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_147 , & V_137 -> V_146 ) )
F_54 ( V_148 L_3 ) ;
memset ( & V_141 , 0 , sizeof V_141 ) ;
V_141 . V_149 = V_139 . V_150 ;
V_141 . V_151 = V_139 . V_152 ;
V_141 . V_26 = V_21 -> V_26 ;
V_137 -> V_134 = F_58 ( V_21 -> V_22 -> V_153 -> V_154 , & V_141 ) ;
if ( F_59 ( V_137 -> V_134 ) ) {
F_54 ( V_142 L_4 ) ;
F_51 ( V_137 ) ;
return;
}
F_60 ( & V_21 -> V_155 ) ;
if ( V_21 -> V_132 )
F_61 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = V_137 ;
F_62 ( & V_21 -> V_155 ) ;
}
static void F_63 ( struct V_156 * V_157 , struct V_158 * V_159 )
{
if ( V_159 -> V_159 == V_160 ||
V_159 -> V_159 == V_161 ||
V_159 -> V_159 == V_162 ||
V_159 -> V_159 == V_163 ||
V_159 -> V_159 == V_164 ||
V_159 -> V_159 == V_165 ) {
unsigned long V_3 ;
struct V_166 * V_167 =
F_49 ( V_157 , F_64 ( * V_167 ) , V_168 ) ;
struct V_135 * V_21 =
& V_167 -> V_21 [ V_159 -> V_169 . V_26 - V_167 -> V_170 ] ;
if ( ! F_65 ( V_157 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_155 , V_3 ) ;
if ( V_21 -> V_132 )
F_61 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = NULL ;
F_25 ( & V_21 -> V_155 , V_3 ) ;
F_66 ( V_171 , & V_167 -> V_21 [ V_159 -> V_169 . V_26 -
V_167 -> V_170 ] . V_136 ) ;
}
}
void F_67 ( struct V_172 * V_173 )
{
F_68 ( & V_173 -> V_174 , 1 ) ;
F_69 ( & V_173 -> V_175 ) ;
}
void F_70 ( struct V_172 * V_173 )
{
F_71 ( V_173 ) ;
F_72 ( & V_173 -> V_175 ) ;
}
void F_73 ( int V_176 , struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_177 * V_22 ;
struct V_126 * V_10 ;
F_21 ( & V_178 , V_3 ) ;
if ( F_74 ( & V_179 , V_176 ) != V_2 ) {
F_25 ( & V_178 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_178 , V_3 ) ;
if ( ! F_27 ( V_2 ) )
F_75 ( V_22 , V_10 ) ;
}
static V_53 F_76 ( struct V_180 * V_23 , V_53 V_26 )
{
struct V_166 * V_167 ;
struct V_135 * V_21 ;
unsigned long V_3 ;
V_53 V_144 ;
V_167 = F_77 ( V_23 , & V_181 ) ;
if ( ! V_167 )
return 0x7f ;
V_21 = & V_167 -> V_21 [ V_26 - V_167 -> V_170 ] ;
F_21 ( & V_21 -> V_155 , V_3 ) ;
V_144 = V_21 -> V_132 ? V_21 -> V_132 -> V_144 : 0x7f ;
F_25 ( & V_21 -> V_155 , V_3 ) ;
return V_144 ;
}
int F_78 ( struct V_180 * V_23 , V_53 V_26 ,
struct V_8 * V_87 , struct V_140 * V_141 )
{
int V_58 ;
T_2 V_182 ;
int V_183 ;
struct V_184 * V_185 = NULL ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
V_141 -> V_149 = F_8 ( V_87 -> V_149 ) ;
V_141 -> V_151 = V_87 -> V_151 ;
V_141 -> V_186 = F_8 ( V_87 -> V_187 ) &
F_76 ( V_23 , V_26 ) ;
V_141 -> V_26 = V_26 ;
V_141 -> V_188 = V_87 -> V_189 ;
V_183 = F_79 ( V_23 , V_26 ) ;
if ( V_183 ) {
struct V_184 * V_190 ;
struct V_184 * V_191 ;
struct V_192 V_193 = { . V_194 = V_87 -> V_195 ,
. V_196 = V_87 -> V_196 ? V_87 -> V_196 :
& V_197 } ;
union {
struct V_198 V_199 ;
struct V_200 V_201 ;
struct V_202 V_203 ;
} V_204 , V_205 ;
if ( ! V_23 -> V_206 )
return - V_207 ;
F_80 ( & V_204 . V_199 , & V_87 -> V_41 ) ;
F_80 ( & V_205 . V_199 , & V_87 -> V_38 ) ;
V_58 = F_81 ( & V_204 . V_199 ,
& V_205 . V_199 , & V_193 ) ;
if ( V_58 )
return V_58 ;
if ( ( V_193 . V_208 == V_209 ||
V_193 . V_208 == V_210 ) &&
V_87 -> V_211 != V_212 )
return - V_213 ;
V_190 = V_23 -> V_206 ( V_23 , V_26 ) ;
if ( ! V_190 )
return - V_214 ;
V_191 = F_82 ( V_193 . V_196 ,
V_193 . V_194 ) ;
if ( V_191 -> V_3 & V_215 ) {
F_83 ( V_191 ) ;
V_191 = V_190 ;
F_84 ( V_191 ) ;
}
V_185 = F_85 ( V_87 ) ;
F_86 () ;
if ( ( V_185 && V_185 != V_191 ) ||
( V_191 != V_190 &&
! F_87 ( V_190 , V_191 ) ) )
V_58 = - V_216 ;
F_88 () ;
F_83 ( V_190 ) ;
F_83 ( V_191 ) ;
if ( V_58 ) {
if ( V_185 )
F_83 ( V_185 ) ;
return V_58 ;
}
}
if ( V_87 -> V_217 > 0 || V_183 ) {
V_141 -> V_218 = V_219 ;
V_141 -> V_220 . V_38 = V_87 -> V_38 ;
V_58 = F_89 ( V_23 , & V_87 -> V_41 ,
V_87 -> V_211 , V_26 , V_185 ,
& V_182 ) ;
if ( V_58 ) {
if ( V_185 )
F_83 ( V_185 ) ;
return V_58 ;
}
V_141 -> V_220 . V_221 = V_182 ;
V_141 -> V_220 . V_222 = F_90 ( V_87 -> V_222 ) ;
V_141 -> V_220 . V_217 = V_87 -> V_217 ;
V_141 -> V_220 . V_44 = V_87 -> V_44 ;
if ( V_185 )
F_83 ( V_185 ) ;
}
if ( V_183 )
memcpy ( V_141 -> V_223 , V_87 -> V_223 , V_224 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_155 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_132 ) {
F_25 ( & V_2 -> V_21 -> V_155 , V_3 ) ;
return - V_225 ;
}
F_92 ( & V_2 -> V_21 -> V_132 -> V_133 ) ;
V_2 -> V_132 = V_2 -> V_21 -> V_132 ;
F_25 ( & V_2 -> V_21 -> V_155 , V_3 ) ;
V_2 -> V_10 = F_93 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_132 -> V_146 ,
0 , V_226 , V_227 ,
V_54 ,
V_228 ) ;
if ( F_59 ( V_2 -> V_10 ) ) {
F_61 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_134 = V_2 -> V_132 -> V_134 ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_95 ( V_2 -> V_10 ) ;
F_61 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
}
static void F_96 ( struct V_12 * V_13 , struct V_177 * V_22 )
{
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
V_13 -> V_99 . V_229 = V_228 ;
V_13 -> V_99 . V_230 = V_231 ;
V_13 -> V_99 . V_232 = V_233 ;
F_21 ( & V_234 , V_3 ) ;
V_13 -> V_99 . V_235 =
F_97 ( ( ( T_3 ) V_22 -> V_236 ) << 32 | V_235 ++ ) ;
F_25 ( & V_234 , V_3 ) ;
}
static int F_98 ( struct V_1 * V_2 , int V_237 , T_4 V_54 )
{
bool V_238 = F_99 ( V_54 ) ;
unsigned long V_3 ;
int V_58 , V_176 ;
if ( V_238 )
F_100 ( V_54 ) ;
F_21 ( & V_178 , V_3 ) ;
V_176 = F_101 ( & V_179 , V_2 , 0 , 0 , V_239 ) ;
F_25 ( & V_178 , V_3 ) ;
if ( V_238 )
F_102 () ;
if ( V_176 < 0 )
return V_176 ;
V_2 -> V_10 -> V_237 = V_237 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_176 = V_176 ;
if ( V_2 -> V_3 & V_4 ) {
if ( ! F_103 ( V_65 ) ) {
if ( ! F_18 ( V_2 , V_54 ) )
return V_176 ;
}
F_1 ( V_2 ) ;
}
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
F_21 ( & V_178 , V_3 ) ;
F_104 ( & V_179 , V_176 ) ;
F_25 ( & V_178 , V_3 ) ;
}
return V_58 ? V_58 : V_176 ;
}
void F_105 ( void * V_240 , struct V_8 * V_87 )
{
F_106 ( V_241 , F_107 ( V_241 ) , V_240 , V_87 ) ;
}
void F_108 ( struct V_8 * V_87 , void * V_240 )
{
F_109 ( V_241 , F_107 ( V_241 ) , V_87 , V_240 ) ;
}
static void F_110 ( struct V_1 * V_242 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_243 * V_2 =
F_49 ( V_242 , struct V_243 , V_242 ) ;
if ( V_13 ) {
struct V_8 V_87 ;
F_106 ( V_241 , F_107 ( V_241 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_196 = NULL ;
V_87 . V_195 = 0 ;
V_87 . V_211 = V_244 ;
memset ( V_87 . V_223 , 0 , V_224 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_111 ( struct V_1 * V_242 )
{
F_51 ( F_49 ( V_242 , struct V_243 , V_242 ) ) ;
}
int F_112 ( struct V_172 * V_173 ,
struct V_180 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
T_1 V_14 ,
int V_237 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_8 * V_245 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_242 )
{
struct V_243 * V_2 ;
struct V_166 * V_167 = F_77 ( V_23 , & V_181 ) ;
struct V_135 * V_21 ;
struct V_177 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_167 )
return - V_214 ;
V_21 = & V_167 -> V_21 [ V_26 - V_167 -> V_170 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_242 . V_21 = V_21 ;
V_58 = F_91 ( & V_2 -> V_242 , V_54 ) ;
if ( V_58 )
goto V_246;
F_114 ( V_173 ) ;
V_2 -> V_242 . V_173 = V_173 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_242 . V_10 -> V_13 ;
F_96 ( V_13 , V_22 ) ;
V_2 -> V_242 . V_91 = V_91 ? F_110 : NULL ;
V_2 -> V_242 . V_247 = F_111 ;
V_13 -> V_99 . V_100 = V_248 ;
V_13 -> V_99 . V_249 = F_115 ( V_250 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_241 , F_107 ( V_241 ) , V_87 , V_13 -> V_57 ) ;
* V_242 = & V_2 -> V_242 ;
V_2 -> V_242 . V_3 |= V_4 ;
V_2 -> V_242 . V_10 -> V_11 [ 1 ] = V_87 ;
V_58 = F_98 ( & V_2 -> V_242 , V_237 , V_54 ) ;
if ( V_58 < 0 )
goto V_251;
return V_58 ;
V_251:
* V_242 = NULL ;
F_71 ( V_2 -> V_242 . V_173 ) ;
F_94 ( & V_2 -> V_242 ) ;
V_246:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_116 ( struct V_1 * V_242 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_252 * V_2 =
F_49 ( V_242 , struct V_252 , V_242 ) ;
if ( V_13 ) {
struct V_253 V_87 ;
F_106 ( V_254 , F_107 ( V_254 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_117 ( struct V_1 * V_242 )
{
F_51 ( F_49 ( V_242 , struct V_252 , V_242 ) ) ;
}
int F_118 ( struct V_172 * V_173 ,
struct V_180 * V_23 , V_53 V_26 , V_53 V_100 ,
struct V_253 * V_87 ,
T_1 V_14 ,
int V_237 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_253 * V_245 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_242 )
{
struct V_252 * V_2 ;
struct V_166 * V_167 = F_77 ( V_23 , & V_181 ) ;
struct V_135 * V_21 ;
struct V_177 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_167 )
return - V_214 ;
V_21 = & V_167 -> V_21 [ V_26 - V_167 -> V_170 ] ;
V_22 = V_21 -> V_22 ;
if ( V_100 != V_248 &&
V_100 != V_255 &&
V_100 != V_256 )
return - V_213 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_242 . V_21 = V_21 ;
V_58 = F_91 ( & V_2 -> V_242 , V_54 ) ;
if ( V_58 )
goto V_246;
F_114 ( V_173 ) ;
V_2 -> V_242 . V_173 = V_173 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_242 . V_10 -> V_13 ;
F_96 ( V_13 , V_22 ) ;
V_2 -> V_242 . V_91 = V_91 ? F_116 : NULL ;
V_2 -> V_242 . V_247 = F_117 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_249 = F_115 ( V_257 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_254 , F_107 ( V_254 ) ,
V_87 , V_13 -> V_57 ) ;
* V_242 = & V_2 -> V_242 ;
V_58 = F_98 ( & V_2 -> V_242 , V_237 , V_54 ) ;
if ( V_58 < 0 )
goto V_251;
return V_58 ;
V_251:
* V_242 = NULL ;
F_71 ( V_2 -> V_242 . V_173 ) ;
F_94 ( & V_2 -> V_242 ) ;
V_246:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_119 ( struct V_1 * V_242 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_258 * V_2 =
F_49 ( V_242 , struct V_258 , V_242 ) ;
if ( V_13 ) {
struct V_259 V_87 ;
F_106 ( V_260 , F_107 ( V_260 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_120 ( struct V_1 * V_242 )
{
F_51 ( F_49 ( V_242 , struct V_258 , V_242 ) ) ;
}
int F_121 ( struct V_172 * V_173 ,
struct V_180 * V_23 , V_53 V_26 ,
V_53 V_100 ,
struct V_259 * V_87 ,
T_1 V_14 ,
int V_237 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_259 * V_245 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_242 )
{
struct V_258 * V_2 ;
struct V_166 * V_167 = F_77 ( V_23 , & V_181 ) ;
struct V_135 * V_21 ;
struct V_177 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_167 )
return - V_214 ;
V_21 = & V_167 -> V_21 [ V_26 - V_167 -> V_170 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_242 . V_21 = V_21 ;
V_58 = F_91 ( & V_2 -> V_242 , V_54 ) ;
if ( V_58 )
goto V_246;
F_114 ( V_173 ) ;
V_2 -> V_242 . V_173 = V_173 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_242 . V_10 -> V_13 ;
F_96 ( V_13 , V_22 ) ;
V_2 -> V_242 . V_91 = V_91 ? F_119 : NULL ;
V_2 -> V_242 . V_247 = F_120 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_249 = F_115 ( V_261 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_260 , F_107 ( V_260 ) ,
V_87 , V_13 -> V_57 ) ;
* V_242 = & V_2 -> V_242 ;
V_58 = F_98 ( & V_2 -> V_242 , V_237 , V_54 ) ;
if ( V_58 < 0 )
goto V_251;
return V_58 ;
V_251:
* V_242 = NULL ;
F_71 ( V_2 -> V_242 . V_173 ) ;
F_94 ( & V_2 -> V_242 ) ;
V_246:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_122 ( struct V_1 * V_242 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_262 * V_2 =
F_49 ( V_242 , struct V_262 , V_242 ) ;
if ( V_13 ) {
struct V_263 V_87 ;
F_106 ( V_264 , F_107 ( V_264 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_123 ( struct V_1 * V_242 )
{
F_51 ( F_49 ( V_242 , struct V_262 , V_242 ) ) ;
}
int F_124 ( struct V_172 * V_173 ,
struct V_180 * V_23 , V_53 V_26 ,
struct V_263 * V_87 ,
T_1 V_14 , V_53 V_100 ,
int V_237 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_263 * V_245 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_242 )
{
struct V_262 * V_2 ;
struct V_166 * V_167 = F_77 ( V_23 , & V_181 ) ;
struct V_135 * V_21 ;
struct V_177 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_167 )
return - V_214 ;
if ( V_100 != V_248 &&
V_100 != V_255 &&
V_100 != V_256 ) {
return - V_213 ;
}
V_21 = & V_167 -> V_21 [ V_26 - V_167 -> V_170 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_113 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_242 . V_21 = V_21 ;
V_58 = F_91 ( & V_2 -> V_242 , V_54 ) ;
if ( V_58 )
goto V_246;
F_114 ( V_173 ) ;
V_2 -> V_242 . V_173 = V_173 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_242 . V_10 -> V_13 ;
F_96 ( V_13 , V_22 ) ;
V_2 -> V_242 . V_91 = V_91 ? F_122 : NULL ;
V_2 -> V_242 . V_247 = F_123 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_249 = F_115 ( V_265 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_109 ( V_264 , F_107 ( V_264 ) , V_87 ,
V_13 -> V_57 ) ;
* V_242 = & V_2 -> V_242 ;
V_58 = F_98 ( & V_2 -> V_242 , V_237 , V_54 ) ;
if ( V_58 < 0 )
goto V_251;
return V_58 ;
V_251:
* V_242 = NULL ;
F_71 ( V_2 -> V_242 . V_173 ) ;
F_94 ( & V_2 -> V_242 ) ;
V_246:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_36 ( struct V_177 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_103 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_91 )
switch ( V_82 -> V_90 ) {
case V_104 :
break;
case V_266 :
V_2 -> V_91 ( V_2 , - V_267 , NULL ) ;
break;
case V_108 :
V_2 -> V_91 ( V_2 , - V_268 , NULL ) ;
break;
default:
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
break;
}
F_21 ( & V_178 , V_3 ) ;
F_104 ( & V_179 , V_2 -> V_176 ) ;
F_25 ( & V_178 , V_3 ) ;
F_94 ( V_2 ) ;
F_71 ( V_2 -> V_173 ) ;
V_2 -> V_247 ( V_2 ) ;
}
static void F_125 ( struct V_177 * V_105 ,
struct V_126 * V_103 ,
struct V_269 * V_270 )
{
struct V_1 * V_2 ;
if ( ! V_103 )
return;
V_2 = V_103 -> V_11 [ 0 ] ;
if ( V_2 -> V_91 ) {
if ( V_270 -> V_271 -> V_90 == V_104 )
V_2 -> V_91 ( V_2 ,
V_270 -> V_272 . V_13 -> V_99 . V_90 ?
- V_213 : 0 ,
(struct V_12 * ) V_270 -> V_272 . V_13 ) ;
else
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
}
F_126 ( V_270 ) ;
}
static void F_127 ( struct V_180 * V_23 )
{
struct V_166 * V_167 ;
int V_273 , V_274 , V_275 ;
int V_276 = 0 ;
V_273 = F_128 ( V_23 ) ;
V_274 = F_129 ( V_23 ) ;
V_167 = F_113 ( sizeof *V_167 +
( V_274 - V_273 + 1 ) * sizeof ( struct V_135 ) ,
V_143 ) ;
if ( ! V_167 )
return;
V_167 -> V_170 = V_273 ;
V_167 -> V_277 = V_274 ;
for ( V_275 = 0 ; V_275 <= V_274 - V_273 ; ++ V_275 ) {
F_130 ( & V_167 -> V_21 [ V_275 ] . V_155 ) ;
if ( ! F_65 ( V_23 , V_275 + 1 ) )
continue;
V_167 -> V_21 [ V_275 ] . V_132 = NULL ;
V_167 -> V_21 [ V_275 ] . V_26 = V_275 + V_273 ;
V_167 -> V_21 [ V_275 ] . V_22 =
F_131 ( V_23 , V_275 + V_273 , V_278 ,
NULL , 0 , F_36 ,
F_125 , V_167 , 0 ) ;
if ( F_59 ( V_167 -> V_21 [ V_275 ] . V_22 ) )
goto V_279;
F_132 ( & V_167 -> V_21 [ V_275 ] . V_136 , F_52 ) ;
V_276 ++ ;
}
if ( ! V_276 )
goto free;
F_133 ( V_23 , & V_181 , V_167 ) ;
F_134 ( & V_167 -> V_168 , V_23 , F_63 ) ;
if ( F_135 ( & V_167 -> V_168 ) )
goto V_279;
for ( V_275 = 0 ; V_275 <= V_274 - V_273 ; ++ V_275 ) {
if ( F_65 ( V_23 , V_275 + 1 ) )
F_52 ( & V_167 -> V_21 [ V_275 ] . V_136 ) ;
}
return;
V_279:
while ( -- V_275 >= 0 ) {
if ( F_65 ( V_23 , V_275 + 1 ) )
F_136 ( V_167 -> V_21 [ V_275 ] . V_22 ) ;
}
free:
F_51 ( V_167 ) ;
return;
}
static void F_137 ( struct V_180 * V_23 , void * V_280 )
{
struct V_166 * V_167 = V_280 ;
int V_275 ;
if ( ! V_167 )
return;
F_138 ( & V_167 -> V_168 ) ;
F_139 ( V_171 ) ;
for ( V_275 = 0 ; V_275 <= V_167 -> V_277 - V_167 -> V_170 ; ++ V_275 ) {
if ( F_65 ( V_23 , V_275 + 1 ) ) {
F_136 ( V_167 -> V_21 [ V_275 ] . V_22 ) ;
if ( V_167 -> V_21 [ V_275 ] . V_132 )
F_61 ( & V_167 -> V_21 [ V_275 ] . V_132 -> V_133 , F_48 ) ;
}
}
F_51 ( V_167 ) ;
}
static int T_5 F_140 ( void )
{
int V_58 ;
F_141 ( & V_235 , sizeof V_235 ) ;
F_68 ( & V_69 , 0 ) ;
V_58 = F_142 ( & V_181 ) ;
if ( V_58 ) {
F_54 ( V_148 L_5 ) ;
goto V_246;
}
V_58 = F_143 () ;
if ( V_58 ) {
F_54 ( V_148 L_6 ) ;
goto V_251;
}
V_76 = F_144 ( L_7 ) ;
if ( ! V_76 ) {
V_58 = - V_60 ;
goto V_281;
}
if ( F_145 ( V_62 , V_282 ,
V_283 ) ) {
F_146 ( L_8 ) ;
V_58 = - V_213 ;
goto V_284;
}
F_147 ( & V_77 , F_37 ) ;
return 0 ;
V_284:
F_148 ( V_76 ) ;
V_281:
F_149 () ;
V_251:
F_150 ( & V_181 ) ;
V_246:
return V_58 ;
}
static void T_6 F_151 ( void )
{
F_152 ( V_62 ) ;
F_153 ( & V_77 ) ;
F_139 ( V_76 ) ;
F_148 ( V_76 ) ;
F_149 () ;
F_150 ( & V_181 ) ;
F_154 ( & V_179 ) ;
}
