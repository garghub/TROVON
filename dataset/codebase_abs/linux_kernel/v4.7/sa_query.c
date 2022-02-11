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
int F_42 ( struct V_6 * V_7 ,
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
int F_47 ( struct V_6 * V_7 ,
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
F_54 ( L_1 ) ;
return;
}
V_137 = F_55 ( sizeof *V_137 , V_142 ) ;
if ( ! V_137 ) {
return;
}
F_56 ( & V_137 -> V_133 ) ;
V_137 -> V_143 = ( 1 << V_139 . V_144 ) - 1 ;
V_137 -> V_145 = 0 ;
if ( F_57 ( V_21 -> V_22 -> V_23 , V_21 -> V_26 ,
V_146 , & V_137 -> V_145 ) )
F_58 ( L_2 ) ;
memset ( & V_141 , 0 , sizeof V_141 ) ;
V_141 . V_147 = V_139 . V_148 ;
V_141 . V_149 = V_139 . V_150 ;
V_141 . V_26 = V_21 -> V_26 ;
if ( V_139 . V_151 ) {
V_141 . V_152 = V_153 ;
V_141 . V_154 . V_38 . V_155 . V_156 = F_59 ( V_139 . V_156 ) ;
V_141 . V_154 . V_38 . V_155 . V_157 = F_59 ( V_158 ) ;
}
V_137 -> V_134 = F_60 ( V_21 -> V_22 -> V_159 -> V_160 , & V_141 ) ;
if ( F_61 ( V_137 -> V_134 ) ) {
F_54 ( L_3 ) ;
F_51 ( V_137 ) ;
return;
}
F_62 ( & V_21 -> V_161 ) ;
if ( V_21 -> V_132 )
F_63 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = V_137 ;
F_64 ( & V_21 -> V_161 ) ;
}
static void F_65 ( struct V_162 * V_163 , struct V_164 * V_165 )
{
if ( V_165 -> V_165 == V_166 ||
V_165 -> V_165 == V_167 ||
V_165 -> V_165 == V_168 ||
V_165 -> V_165 == V_169 ||
V_165 -> V_165 == V_170 ||
V_165 -> V_165 == V_171 ) {
unsigned long V_3 ;
struct V_172 * V_173 =
F_49 ( V_163 , F_66 ( * V_173 ) , V_174 ) ;
struct V_135 * V_21 =
& V_173 -> V_21 [ V_165 -> V_175 . V_26 - V_173 -> V_176 ] ;
if ( ! F_67 ( V_163 -> V_23 , V_21 -> V_26 ) )
return;
F_21 ( & V_21 -> V_161 , V_3 ) ;
if ( V_21 -> V_132 )
F_63 ( & V_21 -> V_132 -> V_133 , F_48 ) ;
V_21 -> V_132 = NULL ;
F_25 ( & V_21 -> V_161 , V_3 ) ;
F_68 ( V_177 , & V_173 -> V_21 [ V_165 -> V_175 . V_26 -
V_173 -> V_176 ] . V_136 ) ;
}
}
void F_69 ( struct V_178 * V_179 )
{
F_70 ( & V_179 -> V_180 , 1 ) ;
F_71 ( & V_179 -> V_181 ) ;
}
void F_72 ( struct V_178 * V_179 )
{
F_73 ( V_179 ) ;
F_74 ( & V_179 -> V_181 ) ;
}
void F_75 ( int V_182 , struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_183 * V_22 ;
struct V_126 * V_10 ;
F_21 ( & V_184 , V_3 ) ;
if ( F_76 ( & V_185 , V_182 ) != V_2 ) {
F_25 ( & V_184 , V_3 ) ;
return;
}
V_22 = V_2 -> V_21 -> V_22 ;
V_10 = V_2 -> V_10 ;
F_25 ( & V_184 , V_3 ) ;
if ( ! F_27 ( V_2 ) )
F_77 ( V_22 , V_10 ) ;
}
static V_53 F_78 ( struct V_186 * V_23 , V_53 V_26 )
{
struct V_172 * V_173 ;
struct V_135 * V_21 ;
unsigned long V_3 ;
V_53 V_143 ;
V_173 = F_79 ( V_23 , & V_187 ) ;
if ( ! V_173 )
return 0x7f ;
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
F_21 ( & V_21 -> V_161 , V_3 ) ;
V_143 = V_21 -> V_132 ? V_21 -> V_132 -> V_143 : 0x7f ;
F_25 ( & V_21 -> V_161 , V_3 ) ;
return V_143 ;
}
int F_80 ( struct V_186 * V_23 , V_53 V_26 ,
struct V_8 * V_87 , struct V_140 * V_141 )
{
int V_58 ;
T_2 V_188 ;
int V_189 ;
struct V_190 * V_191 = NULL ;
memset ( V_141 , 0 , sizeof *V_141 ) ;
V_141 -> V_147 = F_8 ( V_87 -> V_147 ) ;
V_141 -> V_149 = V_87 -> V_149 ;
V_141 -> V_192 = F_8 ( V_87 -> V_193 ) &
F_78 ( V_23 , V_26 ) ;
V_141 -> V_26 = V_26 ;
V_141 -> V_194 = V_87 -> V_195 ;
V_189 = F_81 ( V_23 , V_26 ) ;
if ( V_189 ) {
struct V_190 * V_196 ;
struct V_190 * V_197 ;
struct V_198 V_199 = { . V_200 = V_87 -> V_201 ,
. V_202 = V_87 -> V_202 ? V_87 -> V_202 :
& V_203 } ;
union {
struct V_204 V_205 ;
struct V_206 V_207 ;
struct V_208 V_209 ;
} V_210 , V_211 ;
if ( ! V_23 -> V_212 )
return - V_213 ;
F_82 ( & V_210 . V_205 , & V_87 -> V_41 ) ;
F_82 ( & V_211 . V_205 , & V_87 -> V_38 ) ;
V_58 = F_83 ( & V_210 . V_205 ,
& V_211 . V_205 , & V_199 ) ;
if ( V_58 )
return V_58 ;
if ( ( V_199 . V_214 == V_215 ||
V_199 . V_214 == V_216 ) &&
V_87 -> V_217 != V_218 )
return - V_219 ;
V_196 = V_23 -> V_212 ( V_23 , V_26 ) ;
if ( ! V_196 )
return - V_220 ;
V_197 = F_84 ( V_199 . V_202 ,
V_199 . V_200 ) ;
if ( V_197 -> V_3 & V_221 ) {
F_85 ( V_197 ) ;
V_197 = V_196 ;
F_86 ( V_197 ) ;
}
V_191 = F_87 ( V_87 ) ;
F_88 () ;
if ( ( V_191 && V_191 != V_197 ) ||
( V_197 != V_196 &&
! F_89 ( V_196 , V_197 ) ) )
V_58 = - V_222 ;
F_90 () ;
F_85 ( V_196 ) ;
F_85 ( V_197 ) ;
if ( V_58 ) {
if ( V_191 )
F_85 ( V_191 ) ;
return V_58 ;
}
}
if ( V_87 -> V_223 > 0 || V_189 ) {
V_141 -> V_152 = V_153 ;
V_141 -> V_154 . V_38 = V_87 -> V_38 ;
V_58 = F_91 ( V_23 , & V_87 -> V_41 ,
V_87 -> V_217 , V_26 , V_191 ,
& V_188 ) ;
if ( V_58 ) {
if ( V_191 )
F_85 ( V_191 ) ;
return V_58 ;
}
V_141 -> V_154 . V_224 = V_188 ;
V_141 -> V_154 . V_225 = F_92 ( V_87 -> V_225 ) ;
V_141 -> V_154 . V_223 = V_87 -> V_223 ;
V_141 -> V_154 . V_44 = V_87 -> V_44 ;
if ( V_191 )
F_85 ( V_191 ) ;
}
if ( V_189 )
memcpy ( V_141 -> V_226 , V_87 -> V_226 , V_227 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 , T_4 V_54 )
{
unsigned long V_3 ;
F_21 ( & V_2 -> V_21 -> V_161 , V_3 ) ;
if ( ! V_2 -> V_21 -> V_132 ) {
F_25 ( & V_2 -> V_21 -> V_161 , V_3 ) ;
return - V_228 ;
}
F_94 ( & V_2 -> V_21 -> V_132 -> V_133 ) ;
V_2 -> V_132 = V_2 -> V_21 -> V_132 ;
F_25 ( & V_2 -> V_21 -> V_161 , V_3 ) ;
V_2 -> V_10 = F_95 ( V_2 -> V_21 -> V_22 , 1 ,
V_2 -> V_132 -> V_145 ,
0 , V_229 , V_230 ,
V_54 ,
V_231 ) ;
if ( F_61 ( V_2 -> V_10 ) ) {
F_63 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
return - V_60 ;
}
V_2 -> V_10 -> V_134 = V_2 -> V_132 -> V_134 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_97 ( V_2 -> V_10 ) ;
F_63 ( & V_2 -> V_132 -> V_133 , F_48 ) ;
}
static void F_98 ( struct V_12 * V_13 , struct V_183 * V_22 )
{
unsigned long V_3 ;
memset ( V_13 , 0 , sizeof *V_13 ) ;
V_13 -> V_99 . V_232 = V_231 ;
V_13 -> V_99 . V_233 = V_234 ;
V_13 -> V_99 . V_235 = V_236 ;
F_21 ( & V_237 , V_3 ) ;
V_13 -> V_99 . V_238 =
F_59 ( ( ( T_3 ) V_22 -> V_239 ) << 32 | V_238 ++ ) ;
F_25 ( & V_237 , V_3 ) ;
}
static int F_99 ( struct V_1 * V_2 , int V_240 , T_4 V_54 )
{
bool V_241 = F_100 ( V_54 ) ;
unsigned long V_3 ;
int V_58 , V_182 ;
if ( V_241 )
F_101 ( V_54 ) ;
F_21 ( & V_184 , V_3 ) ;
V_182 = F_102 ( & V_185 , V_2 , 0 , 0 , V_242 ) ;
F_25 ( & V_184 , V_3 ) ;
if ( V_241 )
F_103 () ;
if ( V_182 < 0 )
return V_182 ;
V_2 -> V_10 -> V_240 = V_240 ;
V_2 -> V_10 -> V_11 [ 0 ] = V_2 ;
V_2 -> V_182 = V_182 ;
if ( V_2 -> V_3 & V_4 ) {
if ( ! F_104 ( V_65 ) ) {
if ( ! F_18 ( V_2 , V_54 ) )
return V_182 ;
}
F_1 ( V_2 ) ;
}
V_58 = F_41 ( V_2 -> V_10 , NULL ) ;
if ( V_58 ) {
F_21 ( & V_184 , V_3 ) ;
F_105 ( & V_185 , V_182 ) ;
F_25 ( & V_184 , V_3 ) ;
}
return V_58 ? V_58 : V_182 ;
}
void F_106 ( void * V_243 , struct V_8 * V_87 )
{
F_107 ( V_244 , F_108 ( V_244 ) , V_243 , V_87 ) ;
}
void F_109 ( struct V_8 * V_87 , void * V_243 )
{
F_110 ( V_244 , F_108 ( V_244 ) , V_87 , V_243 ) ;
}
static void F_111 ( struct V_1 * V_245 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_246 * V_2 =
F_49 ( V_245 , struct V_246 , V_245 ) ;
if ( V_13 ) {
struct V_8 V_87 ;
F_107 ( V_244 , F_108 ( V_244 ) ,
V_13 -> V_57 , & V_87 ) ;
V_87 . V_202 = NULL ;
V_87 . V_201 = 0 ;
V_87 . V_217 = V_247 ;
F_112 ( V_87 . V_226 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_113 ( struct V_1 * V_245 )
{
F_51 ( F_49 ( V_245 , struct V_246 , V_245 ) ) ;
}
int F_114 ( struct V_178 * V_179 ,
struct V_186 * V_23 , V_53 V_26 ,
struct V_8 * V_87 ,
T_1 V_14 ,
int V_240 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_8 * V_248 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_245 )
{
struct V_246 * V_2 ;
struct V_172 * V_173 = F_79 ( V_23 , & V_187 ) ;
struct V_135 * V_21 ;
struct V_183 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_173 )
return - V_220 ;
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_245 . V_21 = V_21 ;
V_58 = F_93 ( & V_2 -> V_245 , V_54 ) ;
if ( V_58 )
goto V_249;
F_116 ( V_179 ) ;
V_2 -> V_245 . V_179 = V_179 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_245 . V_10 -> V_13 ;
F_98 ( V_13 , V_22 ) ;
V_2 -> V_245 . V_91 = V_91 ? F_111 : NULL ;
V_2 -> V_245 . V_250 = F_113 ;
V_13 -> V_99 . V_100 = V_251 ;
V_13 -> V_99 . V_252 = F_117 ( V_253 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_244 , F_108 ( V_244 ) , V_87 , V_13 -> V_57 ) ;
* V_245 = & V_2 -> V_245 ;
V_2 -> V_245 . V_3 |= V_4 ;
V_2 -> V_245 . V_10 -> V_11 [ 1 ] = V_87 ;
V_58 = F_99 ( & V_2 -> V_245 , V_240 , V_54 ) ;
if ( V_58 < 0 )
goto V_254;
return V_58 ;
V_254:
* V_245 = NULL ;
F_73 ( V_2 -> V_245 . V_179 ) ;
F_96 ( & V_2 -> V_245 ) ;
V_249:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_118 ( struct V_1 * V_245 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_255 * V_2 =
F_49 ( V_245 , struct V_255 , V_245 ) ;
if ( V_13 ) {
struct V_256 V_87 ;
F_107 ( V_257 , F_108 ( V_257 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_119 ( struct V_1 * V_245 )
{
F_51 ( F_49 ( V_245 , struct V_255 , V_245 ) ) ;
}
int F_120 ( struct V_178 * V_179 ,
struct V_186 * V_23 , V_53 V_26 , V_53 V_100 ,
struct V_256 * V_87 ,
T_1 V_14 ,
int V_240 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_256 * V_248 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_245 )
{
struct V_255 * V_2 ;
struct V_172 * V_173 = F_79 ( V_23 , & V_187 ) ;
struct V_135 * V_21 ;
struct V_183 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_173 )
return - V_220 ;
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
V_22 = V_21 -> V_22 ;
if ( V_100 != V_251 &&
V_100 != V_258 &&
V_100 != V_259 )
return - V_219 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_245 . V_21 = V_21 ;
V_58 = F_93 ( & V_2 -> V_245 , V_54 ) ;
if ( V_58 )
goto V_249;
F_116 ( V_179 ) ;
V_2 -> V_245 . V_179 = V_179 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_245 . V_10 -> V_13 ;
F_98 ( V_13 , V_22 ) ;
V_2 -> V_245 . V_91 = V_91 ? F_118 : NULL ;
V_2 -> V_245 . V_250 = F_119 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_252 = F_117 ( V_260 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_257 , F_108 ( V_257 ) ,
V_87 , V_13 -> V_57 ) ;
* V_245 = & V_2 -> V_245 ;
V_58 = F_99 ( & V_2 -> V_245 , V_240 , V_54 ) ;
if ( V_58 < 0 )
goto V_254;
return V_58 ;
V_254:
* V_245 = NULL ;
F_73 ( V_2 -> V_245 . V_179 ) ;
F_96 ( & V_2 -> V_245 ) ;
V_249:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_121 ( struct V_1 * V_245 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_261 * V_2 =
F_49 ( V_245 , struct V_261 , V_245 ) ;
if ( V_13 ) {
struct V_262 V_87 ;
F_107 ( V_263 , F_108 ( V_263 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_122 ( struct V_1 * V_245 )
{
F_51 ( F_49 ( V_245 , struct V_261 , V_245 ) ) ;
}
int F_123 ( struct V_178 * V_179 ,
struct V_186 * V_23 , V_53 V_26 ,
V_53 V_100 ,
struct V_262 * V_87 ,
T_1 V_14 ,
int V_240 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_262 * V_248 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_245 )
{
struct V_261 * V_2 ;
struct V_172 * V_173 = F_79 ( V_23 , & V_187 ) ;
struct V_135 * V_21 ;
struct V_183 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_173 )
return - V_220 ;
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_245 . V_21 = V_21 ;
V_58 = F_93 ( & V_2 -> V_245 , V_54 ) ;
if ( V_58 )
goto V_249;
F_116 ( V_179 ) ;
V_2 -> V_245 . V_179 = V_179 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_245 . V_10 -> V_13 ;
F_98 ( V_13 , V_22 ) ;
V_2 -> V_245 . V_91 = V_91 ? F_121 : NULL ;
V_2 -> V_245 . V_250 = F_122 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_252 = F_117 ( V_264 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_263 , F_108 ( V_263 ) ,
V_87 , V_13 -> V_57 ) ;
* V_245 = & V_2 -> V_245 ;
V_58 = F_99 ( & V_2 -> V_245 , V_240 , V_54 ) ;
if ( V_58 < 0 )
goto V_254;
return V_58 ;
V_254:
* V_245 = NULL ;
F_73 ( V_2 -> V_245 . V_179 ) ;
F_96 ( & V_2 -> V_245 ) ;
V_249:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_124 ( struct V_1 * V_245 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_265 * V_2 =
F_49 ( V_245 , struct V_265 , V_245 ) ;
if ( V_13 ) {
struct V_266 V_87 ;
F_107 ( V_267 , F_108 ( V_267 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
static void F_125 ( struct V_1 * V_245 )
{
F_51 ( F_49 ( V_245 , struct V_265 , V_245 ) ) ;
}
int F_126 ( struct V_178 * V_179 ,
struct V_186 * V_23 , V_53 V_26 ,
struct V_266 * V_87 ,
T_1 V_14 , V_53 V_100 ,
int V_240 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_266 * V_248 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_245 )
{
struct V_265 * V_2 ;
struct V_172 * V_173 = F_79 ( V_23 , & V_187 ) ;
struct V_135 * V_21 ;
struct V_183 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_173 )
return - V_220 ;
if ( V_100 != V_251 &&
V_100 != V_258 &&
V_100 != V_259 ) {
return - V_219 ;
}
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_245 . V_21 = V_21 ;
V_58 = F_93 ( & V_2 -> V_245 , V_54 ) ;
if ( V_58 )
goto V_249;
F_116 ( V_179 ) ;
V_2 -> V_245 . V_179 = V_179 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_245 . V_10 -> V_13 ;
F_98 ( V_13 , V_22 ) ;
V_2 -> V_245 . V_91 = V_91 ? F_124 : NULL ;
V_2 -> V_245 . V_250 = F_125 ;
V_13 -> V_99 . V_100 = V_100 ;
V_13 -> V_99 . V_252 = F_117 ( V_268 ) ;
V_13 -> V_15 . V_14 = V_14 ;
F_110 ( V_267 , F_108 ( V_267 ) , V_87 ,
V_13 -> V_57 ) ;
* V_245 = & V_2 -> V_245 ;
V_58 = F_99 ( & V_2 -> V_245 , V_240 , V_54 ) ;
if ( V_58 < 0 )
goto V_254;
return V_58 ;
V_254:
* V_245 = NULL ;
F_73 ( V_2 -> V_245 . V_179 ) ;
F_96 ( & V_2 -> V_245 ) ;
V_249:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_127 ( struct V_1 * V_245 ,
int V_90 ,
struct V_12 * V_13 )
{
struct V_269 * V_2 =
F_49 ( V_245 , struct V_269 , V_245 ) ;
if ( V_13 ) {
struct V_270 V_87 ;
F_107 ( V_271 ,
F_108 ( V_271 ) ,
V_13 -> V_57 , & V_87 ) ;
V_2 -> V_91 ( V_90 , & V_87 , V_2 -> V_11 ) ;
} else {
V_2 -> V_91 ( V_90 , NULL , V_2 -> V_11 ) ;
}
}
static void F_128 ( struct V_1 * V_245 )
{
F_51 ( F_49 ( V_245 , struct V_269 ,
V_245 ) ) ;
}
int F_129 ( struct V_178 * V_179 ,
struct V_186 * V_23 , V_53 V_26 ,
int V_240 , T_4 V_54 ,
void (* V_91)( int V_90 ,
struct V_270 * V_248 ,
void * V_11 ) ,
void * V_11 ,
struct V_1 * * V_245 )
{
struct V_269 * V_2 ;
struct V_172 * V_173 = F_79 ( V_23 , & V_187 ) ;
struct V_135 * V_21 ;
struct V_183 * V_22 ;
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_173 )
return - V_220 ;
V_21 = & V_173 -> V_21 [ V_26 - V_173 -> V_176 ] ;
V_22 = V_21 -> V_22 ;
V_2 = F_115 ( sizeof( * V_2 ) , V_54 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_245 . V_21 = V_21 ;
V_58 = F_93 ( & V_2 -> V_245 , V_54 ) ;
if ( V_58 )
goto V_249;
F_116 ( V_179 ) ;
V_2 -> V_245 . V_179 = V_179 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_11 = V_11 ;
V_13 = V_2 -> V_245 . V_10 -> V_13 ;
F_98 ( V_13 , V_22 ) ;
V_2 -> V_245 . V_91 = V_91 ? F_127 : NULL ;
V_2 -> V_245 . V_250 = F_128 ;
V_13 -> V_99 . V_100 = V_251 ;
V_13 -> V_99 . V_252 = F_117 ( V_272 ) ;
V_13 -> V_15 . V_14 = 0 ;
* V_245 = & V_2 -> V_245 ;
V_58 = F_99 ( & V_2 -> V_245 , V_240 , V_54 ) ;
if ( V_58 < 0 )
goto V_254;
return V_58 ;
V_254:
* V_245 = NULL ;
F_73 ( V_2 -> V_245 . V_179 ) ;
F_96 ( & V_2 -> V_245 ) ;
V_249:
F_51 ( V_2 ) ;
return V_58 ;
}
static void F_36 ( struct V_183 * V_22 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_82 -> V_103 -> V_11 [ 0 ] ;
unsigned long V_3 ;
if ( V_2 -> V_91 )
switch ( V_82 -> V_90 ) {
case V_104 :
break;
case V_273 :
V_2 -> V_91 ( V_2 , - V_274 , NULL ) ;
break;
case V_108 :
V_2 -> V_91 ( V_2 , - V_275 , NULL ) ;
break;
default:
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
break;
}
F_21 ( & V_184 , V_3 ) ;
F_105 ( & V_185 , V_2 -> V_182 ) ;
F_25 ( & V_184 , V_3 ) ;
F_96 ( V_2 ) ;
F_73 ( V_2 -> V_179 ) ;
V_2 -> V_250 ( V_2 ) ;
}
static void F_130 ( struct V_183 * V_105 ,
struct V_126 * V_103 ,
struct V_276 * V_277 )
{
struct V_1 * V_2 ;
if ( ! V_103 )
return;
V_2 = V_103 -> V_11 [ 0 ] ;
if ( V_2 -> V_91 ) {
if ( V_277 -> V_278 -> V_90 == V_104 )
V_2 -> V_91 ( V_2 ,
V_277 -> V_279 . V_13 -> V_99 . V_90 ?
- V_219 : 0 ,
(struct V_12 * ) V_277 -> V_279 . V_13 ) ;
else
V_2 -> V_91 ( V_2 , - V_78 , NULL ) ;
}
F_131 ( V_277 ) ;
}
static void F_132 ( struct V_186 * V_23 )
{
struct V_172 * V_173 ;
int V_280 , V_281 , V_282 ;
int V_283 = 0 ;
V_280 = F_133 ( V_23 ) ;
V_281 = F_134 ( V_23 ) ;
V_173 = F_115 ( sizeof *V_173 +
( V_281 - V_280 + 1 ) * sizeof ( struct V_135 ) ,
V_142 ) ;
if ( ! V_173 )
return;
V_173 -> V_176 = V_280 ;
V_173 -> V_284 = V_281 ;
for ( V_282 = 0 ; V_282 <= V_281 - V_280 ; ++ V_282 ) {
F_135 ( & V_173 -> V_21 [ V_282 ] . V_161 ) ;
if ( ! F_67 ( V_23 , V_282 + 1 ) )
continue;
V_173 -> V_21 [ V_282 ] . V_132 = NULL ;
V_173 -> V_21 [ V_282 ] . V_26 = V_282 + V_280 ;
V_173 -> V_21 [ V_282 ] . V_22 =
F_136 ( V_23 , V_282 + V_280 , V_285 ,
NULL , 0 , F_36 ,
F_130 , V_173 , 0 ) ;
if ( F_61 ( V_173 -> V_21 [ V_282 ] . V_22 ) )
goto V_286;
F_137 ( & V_173 -> V_21 [ V_282 ] . V_136 , F_52 ) ;
V_283 ++ ;
}
if ( ! V_283 )
goto free;
F_138 ( V_23 , & V_187 , V_173 ) ;
F_139 ( & V_173 -> V_174 , V_23 , F_65 ) ;
if ( F_140 ( & V_173 -> V_174 ) )
goto V_286;
for ( V_282 = 0 ; V_282 <= V_281 - V_280 ; ++ V_282 ) {
if ( F_67 ( V_23 , V_282 + 1 ) )
F_52 ( & V_173 -> V_21 [ V_282 ] . V_136 ) ;
}
return;
V_286:
while ( -- V_282 >= 0 ) {
if ( F_67 ( V_23 , V_282 + 1 ) )
F_141 ( V_173 -> V_21 [ V_282 ] . V_22 ) ;
}
free:
F_51 ( V_173 ) ;
return;
}
static void F_142 ( struct V_186 * V_23 , void * V_287 )
{
struct V_172 * V_173 = V_287 ;
int V_282 ;
if ( ! V_173 )
return;
F_143 ( & V_173 -> V_174 ) ;
F_144 ( V_177 ) ;
for ( V_282 = 0 ; V_282 <= V_173 -> V_284 - V_173 -> V_176 ; ++ V_282 ) {
if ( F_67 ( V_23 , V_282 + 1 ) ) {
F_141 ( V_173 -> V_21 [ V_282 ] . V_22 ) ;
if ( V_173 -> V_21 [ V_282 ] . V_132 )
F_63 ( & V_173 -> V_21 [ V_282 ] . V_132 -> V_133 , F_48 ) ;
}
}
F_51 ( V_173 ) ;
}
int F_145 ( void )
{
int V_58 ;
F_146 ( & V_238 , sizeof V_238 ) ;
F_70 ( & V_69 , 0 ) ;
V_58 = F_147 ( & V_187 ) ;
if ( V_58 ) {
F_58 ( L_4 ) ;
goto V_249;
}
V_58 = F_148 () ;
if ( V_58 ) {
F_58 ( L_5 ) ;
goto V_254;
}
V_76 = F_149 ( L_6 ) ;
if ( ! V_76 ) {
V_58 = - V_60 ;
goto V_288;
}
F_150 ( & V_77 , F_37 ) ;
return 0 ;
V_288:
F_151 () ;
V_254:
F_152 ( & V_187 ) ;
V_249:
return V_58 ;
}
void F_153 ( void )
{
F_154 ( & V_77 ) ;
F_144 ( V_76 ) ;
F_155 ( V_76 ) ;
F_151 () ;
F_152 ( & V_187 ) ;
F_156 ( & V_185 ) ;
}
