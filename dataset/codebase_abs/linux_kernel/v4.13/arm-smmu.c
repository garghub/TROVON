static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
do {
if ( F_4 ( V_6 -> V_8 -> V_9 ,
V_10 [ V_7 ] . V_11 ) ) {
V_6 -> V_12 |= V_10 [ V_7 ] . V_13 ;
F_5 ( V_6 -> V_8 , L_1 ,
V_10 [ V_7 ] . V_11 ) ;
}
} while ( V_10 [ ++ V_7 ] . V_13 );
}
static struct V_14 * F_6 ( struct V_15 * V_8 )
{
if ( F_7 ( V_8 ) ) {
struct V_16 * V_17 = F_8 ( V_8 ) -> V_17 ;
while ( ! F_9 ( V_17 ) )
V_17 = V_17 -> V_18 ;
return F_10 ( V_17 -> V_19 -> V_18 -> V_9 ) ;
}
return F_10 ( V_8 -> V_9 ) ;
}
static int F_11 ( struct V_20 * V_21 , T_1 V_22 , void * V_23 )
{
* ( ( V_24 * ) V_23 ) = F_12 ( V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_8 , void * V_23 )
{
struct V_25 * V_26 = * ( void * * ) V_23 ;
struct V_14 * V_27 = V_26 -> V_28 ;
int V_29 ;
F_14 (it, err, dev->of_node, L_2 ,
L_3 , 0 )
if ( V_26 -> V_28 == V_27 ) {
* ( void * * ) V_23 = V_8 ;
return 1 ;
}
V_26 -> V_28 = V_27 ;
return V_29 == - V_30 ? 0 : V_29 ;
}
static int F_15 ( struct V_15 * V_8 ,
struct V_5 * * V_6 )
{
struct V_15 * V_31 ;
struct V_14 * V_27 ;
struct V_25 V_26 ;
void * V_23 = & V_26 ;
T_2 * V_32 ;
V_24 V_33 ;
int V_29 ;
V_27 = F_6 ( V_8 ) ;
if ( ! V_27 || ! F_16 ( V_27 , L_3 , NULL ) ) {
F_17 ( V_27 ) ;
return - V_34 ;
}
V_26 . V_28 = V_27 ;
V_29 = F_18 ( & V_35 . V_36 , NULL , & V_23 ,
F_13 ) ;
V_31 = V_23 ;
F_17 ( V_27 ) ;
if ( V_29 == 0 )
return - V_34 ;
if ( V_29 < 0 )
return V_29 ;
if ( F_7 ( V_8 ) ) {
F_19 ( F_8 ( V_8 ) , F_11 ,
& V_33 ) ;
V_26 . V_37 = & V_33 ;
V_26 . V_38 = 1 ;
}
V_29 = F_20 ( V_8 , & V_31 -> V_9 -> V_39 ,
& V_40 ) ;
if ( V_29 )
return V_29 ;
V_32 = F_21 ( V_26 . V_38 , sizeof( * V_32 ) , V_41 ) ;
if ( ! V_32 )
return - V_42 ;
* V_6 = F_22 ( V_31 ) ;
F_23 ( & V_26 , V_32 , V_26 . V_38 ) ;
V_29 = F_24 ( V_8 , V_32 , V_26 . V_38 ) ;
F_25 ( V_32 ) ;
return V_29 ;
}
static int F_26 ( unsigned long * V_43 , int V_44 , int V_45 )
{
int V_46 ;
do {
V_46 = F_27 ( V_43 , V_45 , V_44 ) ;
if ( V_46 == V_45 )
return - V_47 ;
} while ( F_28 ( V_46 , V_43 ) );
return V_46 ;
}
static void F_29 ( unsigned long * V_43 , int V_46 )
{
F_30 ( V_46 , V_43 ) ;
}
static void F_31 ( struct V_5 * V_6 ,
void T_3 * V_48 , void T_3 * V_49 )
{
unsigned int V_50 , V_51 ;
F_32 ( 0 , V_48 ) ;
for ( V_51 = 1 ; V_51 < V_52 ; V_51 *= 2 ) {
for ( V_50 = V_53 ; V_50 > 0 ; V_50 -- ) {
if ( ! ( F_33 ( V_49 ) & V_54 ) )
return;
F_34 () ;
}
F_35 ( V_51 ) ;
}
F_36 ( V_6 -> V_8 ,
L_4 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
void T_3 * V_55 = F_38 ( V_6 ) ;
unsigned long V_56 ;
F_39 ( & V_6 -> V_57 , V_56 ) ;
F_31 ( V_6 , V_55 + V_58 ,
V_55 + V_59 ) ;
F_40 ( & V_6 -> V_57 , V_56 ) ;
}
static void F_41 ( void * V_60 )
{
struct V_1 * V_61 = V_60 ;
struct V_5 * V_6 = V_61 -> V_6 ;
void T_3 * V_55 = F_42 ( V_6 , V_61 -> V_62 . V_63 ) ;
unsigned long V_56 ;
F_39 ( & V_61 -> V_64 , V_56 ) ;
F_31 ( V_6 , V_55 + V_65 ,
V_55 + V_66 ) ;
F_40 ( & V_61 -> V_64 , V_56 ) ;
}
static void F_43 ( void * V_60 )
{
struct V_1 * V_61 = V_60 ;
F_37 ( V_61 -> V_6 ) ;
}
static void F_44 ( void * V_60 )
{
struct V_1 * V_61 = V_60 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
void T_3 * V_55 = F_42 ( V_61 -> V_6 , V_62 -> V_63 ) ;
F_32 ( V_62 -> V_68 , V_55 + V_69 ) ;
F_41 ( V_60 ) ;
}
static void F_45 ( void * V_60 )
{
struct V_1 * V_61 = V_60 ;
struct V_5 * V_6 = V_61 -> V_6 ;
void T_3 * V_55 = F_38 ( V_6 ) ;
F_32 ( V_61 -> V_62 . V_70 , V_55 + V_71 ) ;
F_37 ( V_6 ) ;
}
static void F_46 ( unsigned long V_72 , T_4 V_73 ,
T_4 V_74 , bool V_75 , void * V_60 )
{
struct V_1 * V_61 = V_60 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
bool V_76 = V_62 -> V_77 != V_78 ;
void T_3 * V_79 = F_42 ( V_61 -> V_6 , V_62 -> V_63 ) ;
if ( V_76 ) {
V_79 += V_75 ? V_80 : V_81 ;
if ( V_62 -> V_82 != V_83 ) {
V_72 &= ~ 12UL ;
V_72 |= V_62 -> V_68 ;
do {
F_32 ( V_72 , V_79 ) ;
V_72 += V_74 ;
} while ( V_73 -= V_74 );
} else {
V_72 >>= 12 ;
V_72 |= ( V_84 ) V_62 -> V_68 << 48 ;
do {
F_47 ( V_72 , V_79 ) ;
V_72 += V_74 >> 12 ;
} while ( V_73 -= V_74 );
}
} else {
V_79 += V_75 ? V_85 :
V_86 ;
V_72 >>= 12 ;
do {
F_48 ( V_72 , V_79 ) ;
V_72 += V_74 >> 12 ;
} while ( V_73 -= V_74 );
}
}
static void F_49 ( unsigned long V_72 , T_4 V_73 ,
T_4 V_74 , bool V_75 , void * V_60 )
{
struct V_1 * V_61 = V_60 ;
void T_3 * V_55 = F_38 ( V_61 -> V_6 ) ;
F_32 ( V_61 -> V_62 . V_70 , V_55 + V_71 ) ;
}
static T_5 F_50 ( int V_87 , void * V_8 )
{
T_2 V_88 , V_89 ;
unsigned long V_72 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_67 * V_62 = & V_61 -> V_62 ;
struct V_5 * V_6 = V_61 -> V_6 ;
void T_3 * V_90 ;
V_90 = F_42 ( V_6 , V_62 -> V_63 ) ;
V_88 = F_33 ( V_90 + V_91 ) ;
if ( ! ( V_88 & V_92 ) )
return V_93 ;
V_89 = F_33 ( V_90 + V_94 ) ;
V_72 = F_51 ( V_90 + V_95 ) ;
F_36 ( V_6 -> V_8 ,
L_5 ,
V_88 , V_72 , V_89 , V_62 -> V_63 ) ;
F_52 ( V_88 , V_90 + V_91 ) ;
return V_96 ;
}
static T_5 F_53 ( int V_87 , void * V_8 )
{
T_2 V_97 , V_98 , V_99 , V_100 ;
struct V_5 * V_6 = V_8 ;
void T_3 * V_101 = F_54 ( V_6 ) ;
V_97 = F_33 ( V_101 + V_102 ) ;
V_98 = F_33 ( V_101 + V_103 ) ;
V_99 = F_33 ( V_101 + V_104 ) ;
V_100 = F_33 ( V_101 + V_105 ) ;
if ( ! V_97 )
return V_93 ;
F_36 ( V_6 -> V_8 ,
L_6 ) ;
F_36 ( V_6 -> V_8 ,
L_7 ,
V_97 , V_98 , V_99 , V_100 ) ;
F_52 ( V_97 , V_101 + V_102 ) ;
return V_96 ;
}
static void F_55 ( struct V_1 * V_61 ,
struct V_106 * V_107 )
{
T_2 V_79 , V_108 ;
V_84 V_109 ;
bool V_76 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
struct V_5 * V_6 = V_61 -> V_6 ;
void T_3 * V_90 , * V_110 ;
V_110 = F_56 ( V_6 ) ;
V_76 = V_62 -> V_77 != V_78 ;
V_90 = F_42 ( V_6 , V_62 -> V_63 ) ;
if ( V_6 -> V_111 > V_112 ) {
if ( V_62 -> V_82 == V_83 )
V_79 = V_113 ;
else
V_79 = V_114 ;
if ( V_6 -> V_115 & V_116 )
V_79 |= V_62 -> V_70 << V_117 ;
F_32 ( V_79 , V_110 + F_57 ( V_62 -> V_63 ) ) ;
}
V_79 = V_62 -> V_77 ;
if ( V_6 -> V_111 < V_118 )
V_79 |= V_62 -> V_119 << V_120 ;
if ( V_76 ) {
V_79 |= ( V_121 << V_122 ) |
( V_123 << V_124 ) ;
} else if ( ! ( V_6 -> V_115 & V_116 ) ) {
V_79 |= V_62 -> V_70 << V_125 ;
}
F_32 ( V_79 , V_110 + F_58 ( V_62 -> V_63 ) ) ;
if ( V_76 ) {
if ( V_62 -> V_82 == V_126 ) {
V_79 = V_107 -> V_127 . V_128 ;
V_108 = 0 ;
} else {
V_79 = V_107 -> V_129 . V_128 ;
V_108 = V_107 -> V_129 . V_128 >> 32 ;
V_108 |= V_130 ;
if ( V_62 -> V_82 == V_83 )
V_108 |= V_131 ;
}
if ( V_6 -> V_111 > V_112 )
F_32 ( V_108 , V_90 + V_132 ) ;
} else {
V_79 = V_107 -> V_133 . V_134 ;
}
F_32 ( V_79 , V_90 + V_135 ) ;
if ( V_76 ) {
if ( V_62 -> V_82 == V_126 ) {
V_79 = V_107 -> V_127 . V_136 [ 0 ] ;
F_32 ( V_79 , V_90 + V_137 ) ;
V_79 = V_107 -> V_127 . V_136 [ 1 ] ;
F_32 ( V_79 , V_90 + V_138 ) ;
F_32 ( V_62 -> V_68 , V_90 + V_139 ) ;
} else {
V_109 = V_107 -> V_129 . V_136 [ 0 ] ;
V_109 |= ( V_84 ) V_62 -> V_68 << V_140 ;
F_47 ( V_109 , V_90 + V_137 ) ;
V_109 = V_107 -> V_129 . V_136 [ 1 ] ;
V_109 |= ( V_84 ) V_62 -> V_68 << V_140 ;
F_47 ( V_109 , V_90 + V_138 ) ;
}
} else {
V_109 = V_107 -> V_133 . V_141 ;
F_47 ( V_109 , V_90 + V_137 ) ;
}
if ( V_76 ) {
if ( V_62 -> V_82 == V_126 ) {
V_79 = V_107 -> V_127 . V_142 ;
V_108 = V_107 -> V_127 . V_143 ;
} else {
V_79 = V_107 -> V_129 . V_144 [ 0 ] ;
V_108 = V_107 -> V_129 . V_144 [ 1 ] ;
}
F_32 ( V_79 , V_90 + V_145 ) ;
F_32 ( V_108 , V_90 + V_146 ) ;
}
V_79 = V_147 | V_148 | V_149 | V_150 | V_151 ;
if ( V_76 )
V_79 |= V_152 ;
#ifdef F_59
V_79 |= V_153 ;
#endif
F_32 ( V_79 , V_90 + V_154 ) ;
}
static int F_60 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_87 , V_44 , V_155 = 0 ;
unsigned long V_156 , V_157 ;
struct V_158 * V_159 ;
struct V_106 V_107 ;
enum V_160 V_82 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_67 * V_62 = & V_61 -> V_62 ;
const struct V_161 * V_162 ;
F_61 ( & V_61 -> V_163 ) ;
if ( V_61 -> V_6 )
goto V_164;
if ( V_4 -> type == V_165 ) {
V_61 -> V_166 = V_167 ;
V_61 -> V_6 = V_6 ;
goto V_164;
}
if ( ! ( V_6 -> V_115 & V_168 ) )
V_61 -> V_166 = V_169 ;
if ( ! ( V_6 -> V_115 & V_170 ) )
V_61 -> V_166 = V_171 ;
if ( V_6 -> V_115 & V_172 )
V_62 -> V_82 = V_173 ;
if ( F_62 ( V_174 ) &&
! F_62 ( V_175 ) && ! F_62 ( V_176 ) &&
( V_6 -> V_115 & V_177 ) &&
( V_61 -> V_166 == V_171 ) )
V_62 -> V_82 = V_126 ;
if ( ( F_62 ( V_175 ) || V_62 -> V_82 == V_178 ) &&
( V_6 -> V_115 & ( V_179 |
V_180 |
V_181 ) ) )
V_62 -> V_82 = V_83 ;
if ( V_62 -> V_82 == V_178 ) {
V_155 = - V_182 ;
goto V_164;
}
switch ( V_61 -> V_166 ) {
case V_171 :
V_62 -> V_77 = V_183 ;
V_44 = V_6 -> V_184 ;
V_156 = V_6 -> V_185 ;
V_157 = V_6 -> V_186 ;
if ( V_62 -> V_82 == V_83 ) {
V_82 = V_187 ;
} else if ( V_62 -> V_82 == V_173 ) {
V_82 = V_188 ;
V_156 = F_63 ( V_156 , 32UL ) ;
V_157 = F_63 ( V_157 , 40UL ) ;
} else {
V_82 = V_189 ;
V_156 = F_63 ( V_156 , 32UL ) ;
V_157 = F_63 ( V_157 , 32UL ) ;
}
V_162 = & V_190 ;
break;
case V_191 :
case V_169 :
V_62 -> V_77 = V_78 ;
V_44 = 0 ;
V_156 = V_6 -> V_186 ;
V_157 = V_6 -> V_192 ;
if ( V_62 -> V_82 == V_83 ) {
V_82 = V_193 ;
} else {
V_82 = V_194 ;
V_156 = F_63 ( V_156 , 40UL ) ;
V_157 = F_63 ( V_157 , 40UL ) ;
}
if ( V_6 -> V_111 == V_118 )
V_162 = & V_195 ;
else
V_162 = & V_196 ;
break;
default:
V_155 = - V_182 ;
goto V_164;
}
V_155 = F_26 ( V_6 -> V_197 , V_44 ,
V_6 -> V_198 ) ;
if ( V_155 < 0 )
goto V_164;
V_62 -> V_63 = V_155 ;
if ( V_6 -> V_111 < V_118 ) {
V_62 -> V_119 = F_64 ( & V_6 -> V_119 ) ;
V_62 -> V_119 %= V_6 -> V_199 ;
} else {
V_62 -> V_119 = V_62 -> V_63 ;
}
if ( V_61 -> V_166 == V_169 )
V_62 -> V_70 = V_62 -> V_63 + 1 + V_6 -> V_200 ;
else
V_62 -> V_68 = V_62 -> V_63 + V_6 -> V_200 ;
V_107 = (struct V_106 ) {
. V_201 = V_6 -> V_201 ,
. V_156 = V_156 ,
. V_157 = V_157 ,
. V_202 = V_162 ,
. V_203 = V_6 -> V_8 ,
} ;
if ( V_6 -> V_115 & V_204 )
V_107 . V_205 = V_206 ;
V_61 -> V_6 = V_6 ;
V_159 = F_65 ( V_82 , & V_107 , V_61 ) ;
if ( ! V_159 ) {
V_155 = - V_42 ;
goto V_207;
}
V_4 -> V_201 = V_107 . V_201 ;
V_4 -> V_208 . V_209 = ( 1UL << V_156 ) - 1 ;
V_4 -> V_208 . V_210 = true ;
F_55 ( V_61 , & V_107 ) ;
V_87 = V_6 -> V_211 [ V_6 -> V_212 + V_62 -> V_119 ] ;
V_155 = F_66 ( V_6 -> V_8 , V_87 , F_50 ,
V_213 , L_8 , V_4 ) ;
if ( V_155 < 0 ) {
F_67 ( V_6 -> V_8 , L_9 ,
V_62 -> V_119 , V_87 ) ;
V_62 -> V_119 = V_214 ;
}
F_68 ( & V_61 -> V_163 ) ;
V_61 -> V_159 = V_159 ;
return 0 ;
V_207:
V_61 -> V_6 = NULL ;
V_164:
F_68 ( & V_61 -> V_163 ) ;
return V_155 ;
}
static void F_69 ( struct V_2 * V_4 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
void T_3 * V_90 ;
int V_87 ;
if ( ! V_6 || V_4 -> type == V_165 )
return;
V_90 = F_42 ( V_6 , V_62 -> V_63 ) ;
F_32 ( 0 , V_90 + V_154 ) ;
if ( V_62 -> V_119 != V_214 ) {
V_87 = V_6 -> V_211 [ V_6 -> V_212 + V_62 -> V_119 ] ;
F_70 ( V_6 -> V_8 , V_87 , V_4 ) ;
}
F_71 ( V_61 -> V_159 ) ;
F_29 ( V_6 -> V_197 , V_62 -> V_63 ) ;
}
static struct V_2 * F_72 ( unsigned type )
{
struct V_1 * V_61 ;
if ( type != V_215 &&
type != V_216 &&
type != V_165 )
return NULL ;
V_61 = F_73 ( sizeof( * V_61 ) , V_41 ) ;
if ( ! V_61 )
return NULL ;
if ( type == V_216 && ( V_217 ||
F_74 ( & V_61 -> V_4 ) ) ) {
F_25 ( V_61 ) ;
return NULL ;
}
F_75 ( & V_61 -> V_163 ) ;
F_76 ( & V_61 -> V_64 ) ;
return & V_61 -> V_4 ;
}
static void F_77 ( struct V_2 * V_4 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
F_78 ( V_4 ) ;
F_69 ( V_4 ) ;
F_25 ( V_61 ) ;
}
static void F_79 ( struct V_5 * V_6 , int V_46 )
{
struct V_218 * V_219 = V_6 -> V_220 + V_46 ;
T_2 V_79 = V_219 -> V_221 << V_222 | V_219 -> V_223 << V_224 ;
if ( ! ( V_6 -> V_115 & V_225 ) && V_219 -> V_226 )
V_79 |= V_227 ;
F_32 ( V_79 , F_38 ( V_6 ) + F_80 ( V_46 ) ) ;
}
static void F_81 ( struct V_5 * V_6 , int V_46 )
{
struct V_228 * V_229 = V_6 -> V_230 + V_46 ;
T_2 V_79 = ( V_229 -> type & V_231 ) << V_232 |
( V_229 -> V_63 & V_233 ) << V_234 |
( V_229 -> V_235 & V_236 ) << V_237 ;
if ( V_6 -> V_115 & V_225 && V_6 -> V_220 &&
V_6 -> V_220 [ V_46 ] . V_226 )
V_79 |= V_238 ;
F_32 ( V_79 , F_38 ( V_6 ) + F_82 ( V_46 ) ) ;
}
static void F_83 ( struct V_5 * V_6 , int V_46 )
{
F_81 ( V_6 , V_46 ) ;
if ( V_6 -> V_220 )
F_79 ( V_6 , V_46 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
void T_3 * V_101 = F_38 ( V_6 ) ;
T_2 V_219 ;
if ( ! V_6 -> V_220 )
return;
V_219 = V_6 -> V_239 << V_222 ;
F_32 ( V_219 , V_101 + F_80 ( 0 ) ) ;
V_219 = F_33 ( V_101 + F_80 ( 0 ) ) ;
V_6 -> V_239 = V_219 >> V_222 ;
V_219 = V_6 -> V_239 << V_224 ;
F_32 ( V_219 , V_101 + F_80 ( 0 ) ) ;
V_219 = F_33 ( V_101 + F_80 ( 0 ) ) ;
V_6 -> V_240 = V_219 >> V_224 ;
}
static int F_85 ( struct V_5 * V_6 , T_1 V_221 , T_1 V_223 )
{
struct V_218 * V_220 = V_6 -> V_220 ;
int V_7 , V_241 = - V_47 ;
if ( ! V_220 )
return V_221 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_242 ; ++ V_7 ) {
if ( ! V_220 [ V_7 ] . V_226 ) {
if ( V_241 < 0 )
V_241 = V_7 ;
continue;
}
if ( ( V_223 & V_220 [ V_7 ] . V_223 ) == V_223 &&
! ( ( V_221 ^ V_220 [ V_7 ] . V_221 ) & ~ V_220 [ V_7 ] . V_223 ) )
return V_7 ;
if ( ! ( ( V_221 ^ V_220 [ V_7 ] . V_221 ) & ~ ( V_220 [ V_7 ] . V_223 | V_223 ) ) )
return - V_182 ;
}
return V_241 ;
}
static bool F_86 ( struct V_5 * V_6 , int V_46 )
{
if ( -- V_6 -> V_230 [ V_46 ] . V_243 )
return false ;
V_6 -> V_230 [ V_46 ] = V_244 ;
if ( V_6 -> V_220 )
V_6 -> V_220 [ V_46 ] . V_226 = false ;
return true ;
}
static int F_87 ( struct V_15 * V_8 )
{
struct V_245 * V_246 = V_8 -> V_245 ;
struct V_247 * V_62 = V_246 -> V_248 ;
struct V_5 * V_6 = V_62 -> V_6 ;
struct V_218 * V_220 = V_6 -> V_220 ;
struct V_249 * V_250 ;
int V_7 , V_46 , V_155 ;
F_61 ( & V_6 -> V_251 ) ;
F_88 (fwspec, i, idx) {
T_1 V_252 = V_246 -> V_253 [ V_7 ] ;
T_1 V_223 = V_246 -> V_253 [ V_7 ] >> V_224 ;
if ( V_46 != V_254 ) {
V_155 = - V_255 ;
goto V_256;
}
V_155 = F_85 ( V_6 , V_252 , V_223 ) ;
if ( V_155 < 0 )
goto V_256;
V_46 = V_155 ;
if ( V_220 && V_6 -> V_230 [ V_46 ] . V_243 == 0 ) {
V_220 [ V_46 ] . V_221 = V_252 ;
V_220 [ V_46 ] . V_223 = V_223 ;
V_220 [ V_46 ] . V_226 = true ;
}
V_6 -> V_230 [ V_46 ] . V_243 ++ ;
V_62 -> V_257 [ V_7 ] = ( V_258 ) V_46 ;
}
V_250 = F_89 ( V_8 ) ;
if ( ! V_250 )
V_250 = F_90 ( - V_42 ) ;
if ( F_91 ( V_250 ) ) {
V_155 = F_92 ( V_250 ) ;
goto V_256;
}
F_93 ( V_250 ) ;
F_88 (fwspec, i, idx) {
F_83 ( V_6 , V_46 ) ;
V_6 -> V_230 [ V_46 ] . V_250 = V_250 ;
}
F_68 ( & V_6 -> V_251 ) ;
return 0 ;
V_256:
while ( V_7 -- ) {
F_86 ( V_6 , V_62 -> V_257 [ V_7 ] ) ;
V_62 -> V_257 [ V_7 ] = V_254 ;
}
F_68 ( & V_6 -> V_251 ) ;
return V_155 ;
}
static void F_94 ( struct V_245 * V_246 )
{
struct V_5 * V_6 = F_95 ( V_246 ) ;
struct V_247 * V_62 = V_246 -> V_248 ;
int V_7 , V_46 ;
F_61 ( & V_6 -> V_251 ) ;
F_88 (fwspec, i, idx) {
if ( F_86 ( V_6 , V_46 ) )
F_83 ( V_6 , V_46 ) ;
V_62 -> V_257 [ V_7 ] = V_254 ;
}
F_68 ( & V_6 -> V_251 ) ;
}
static int F_96 ( struct V_1 * V_61 ,
struct V_245 * V_246 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_228 * V_229 = V_6 -> V_230 ;
T_6 V_63 = V_61 -> V_62 . V_63 ;
enum V_259 type ;
int V_7 , V_46 ;
if ( V_61 -> V_166 == V_167 )
type = V_260 ;
else
type = V_261 ;
F_88 (fwspec, i, idx) {
if ( type == V_229 [ V_46 ] . type && V_63 == V_229 [ V_46 ] . V_63 )
continue;
V_229 [ V_46 ] . type = type ;
V_229 [ V_46 ] . V_235 = V_262 ;
V_229 [ V_46 ] . V_63 = V_63 ;
F_81 ( V_6 , V_46 ) ;
}
return 0 ;
}
static int F_97 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_155 ;
struct V_245 * V_246 = V_8 -> V_245 ;
struct V_5 * V_6 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( ! V_246 || V_246 -> V_263 != & V_40 ) {
F_67 ( V_8 , L_10 ) ;
return - V_264 ;
}
if ( ! V_246 -> V_248 )
return - V_34 ;
V_6 = F_95 ( V_246 ) ;
V_155 = F_60 ( V_4 , V_6 ) ;
if ( V_155 < 0 )
return V_155 ;
if ( V_61 -> V_6 != V_6 ) {
F_67 ( V_8 ,
L_11 ,
F_98 ( V_61 -> V_6 -> V_8 ) , F_98 ( V_6 -> V_8 ) ) ;
return - V_182 ;
}
return F_96 ( V_61 , V_246 ) ;
}
static int F_99 ( struct V_2 * V_4 , unsigned long V_72 ,
T_7 V_265 , T_4 V_73 , int V_266 )
{
struct V_158 * V_263 = F_1 ( V_4 ) -> V_159 ;
if ( ! V_263 )
return - V_34 ;
return V_263 -> V_43 ( V_263 , V_72 , V_265 , V_73 , V_266 ) ;
}
static T_4 F_100 ( struct V_2 * V_4 , unsigned long V_72 ,
T_4 V_73 )
{
struct V_158 * V_263 = F_1 ( V_4 ) -> V_159 ;
if ( ! V_263 )
return 0 ;
return V_263 -> V_267 ( V_263 , V_72 , V_73 ) ;
}
static T_7 F_101 ( struct V_2 * V_4 ,
T_8 V_72 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
struct V_158 * V_263 = V_61 -> V_159 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_3 * V_90 ;
T_2 V_268 ;
V_84 V_269 ;
unsigned long V_270 , V_56 ;
V_90 = F_42 ( V_6 , V_62 -> V_63 ) ;
F_39 ( & V_61 -> V_64 , V_56 ) ;
V_270 = V_72 & ~ 0xfffUL ;
if ( V_6 -> V_111 == V_118 )
F_48 ( V_270 , V_90 + V_271 ) ;
else
F_32 ( V_270 , V_90 + V_271 ) ;
if ( F_102 ( V_90 + V_272 , V_268 ,
! ( V_268 & V_273 ) , 5 , 50 ) ) {
F_40 ( & V_61 -> V_64 , V_56 ) ;
F_67 ( V_8 ,
L_12 ,
& V_72 ) ;
return V_263 -> V_274 ( V_263 , V_72 ) ;
}
V_269 = F_51 ( V_90 + V_275 ) ;
F_40 ( & V_61 -> V_64 , V_56 ) ;
if ( V_269 & V_276 ) {
F_67 ( V_8 , L_13 ) ;
F_67 ( V_8 , L_14 , V_269 ) ;
return 0 ;
}
return ( V_269 & F_103 ( 39 , 12 ) ) | ( V_72 & 0xfff ) ;
}
static T_7 F_104 ( struct V_2 * V_4 ,
T_8 V_72 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_158 * V_263 = V_61 -> V_159 ;
if ( V_4 -> type == V_165 )
return V_72 ;
if ( ! V_263 )
return 0 ;
if ( V_61 -> V_6 -> V_115 & V_277 &&
V_61 -> V_166 == V_171 )
return F_101 ( V_4 , V_72 ) ;
return V_263 -> V_274 ( V_263 , V_72 ) ;
}
static bool F_105 ( enum V_278 V_279 )
{
switch ( V_279 ) {
case V_280 :
return true ;
case V_281 :
return true ;
default:
return false ;
}
}
static int F_106 ( struct V_15 * V_8 , void * V_23 )
{
return V_8 -> V_39 == V_23 ;
}
static
struct V_5 * F_107 ( struct V_282 * V_39 )
{
struct V_15 * V_8 = F_108 ( & V_35 . V_36 , NULL ,
V_39 , F_106 ) ;
F_109 ( V_8 ) ;
return V_8 ? F_22 ( V_8 ) : NULL ;
}
static int F_110 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_247 * V_62 ;
struct V_245 * V_246 = V_8 -> V_245 ;
int V_7 , V_155 ;
if ( V_217 ) {
V_155 = F_15 ( V_8 , & V_6 ) ;
V_246 = V_8 -> V_245 ;
if ( V_155 )
goto V_283;
} else if ( V_246 && V_246 -> V_263 == & V_40 ) {
V_6 = F_107 ( V_246 -> V_284 ) ;
} else {
return - V_34 ;
}
V_155 = - V_182 ;
for ( V_7 = 0 ; V_7 < V_246 -> V_285 ; V_7 ++ ) {
T_1 V_252 = V_246 -> V_253 [ V_7 ] ;
T_1 V_223 = V_246 -> V_253 [ V_7 ] >> V_224 ;
if ( V_252 & ~ V_6 -> V_239 ) {
F_67 ( V_8 , L_15 ,
V_252 , V_6 -> V_239 ) ;
goto V_283;
}
if ( V_223 & ~ V_6 -> V_240 ) {
F_67 ( V_8 , L_16 ,
V_223 , V_6 -> V_240 ) ;
goto V_283;
}
}
V_155 = - V_42 ;
V_62 = F_73 ( F_111 ( struct V_247 , V_257 [ V_7 ] ) ,
V_41 ) ;
if ( ! V_62 )
goto V_283;
V_62 -> V_6 = V_6 ;
V_246 -> V_248 = V_62 ;
while ( V_7 -- )
V_62 -> V_257 [ V_7 ] = V_254 ;
V_155 = F_87 ( V_8 ) ;
if ( V_155 )
goto V_286;
F_112 ( & V_6 -> V_287 , V_8 ) ;
return 0 ;
V_286:
F_25 ( V_62 ) ;
V_283:
F_113 ( V_8 ) ;
return V_155 ;
}
static void F_114 ( struct V_15 * V_8 )
{
struct V_245 * V_246 = V_8 -> V_245 ;
struct V_247 * V_62 ;
struct V_5 * V_6 ;
if ( ! V_246 || V_246 -> V_263 != & V_40 )
return;
V_62 = V_246 -> V_248 ;
V_6 = V_62 -> V_6 ;
F_115 ( & V_6 -> V_287 , V_8 ) ;
F_94 ( V_246 ) ;
F_116 ( V_8 ) ;
F_25 ( V_246 -> V_248 ) ;
F_113 ( V_8 ) ;
}
static struct V_249 * F_117 ( struct V_15 * V_8 )
{
struct V_245 * V_246 = V_8 -> V_245 ;
struct V_5 * V_6 = F_95 ( V_246 ) ;
struct V_249 * V_250 = NULL ;
int V_7 , V_46 ;
F_88 (fwspec, i, idx) {
if ( V_250 && V_6 -> V_230 [ V_46 ] . V_250 &&
V_250 != V_6 -> V_230 [ V_46 ] . V_250 )
return F_90 ( - V_182 ) ;
V_250 = V_6 -> V_230 [ V_46 ] . V_250 ;
}
if ( V_250 )
return F_118 ( V_250 ) ;
if ( F_7 ( V_8 ) )
V_250 = F_119 ( V_8 ) ;
else
V_250 = F_120 ( V_8 ) ;
return V_250 ;
}
static int F_121 ( struct V_2 * V_4 ,
enum V_288 V_289 , void * V_23 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_215 )
return - V_182 ;
switch ( V_289 ) {
case V_290 :
* ( int * ) V_23 = ( V_61 -> V_166 == V_191 ) ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_122 ( struct V_2 * V_4 ,
enum V_288 V_289 , void * V_23 )
{
int V_155 = 0 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_215 )
return - V_182 ;
F_61 ( & V_61 -> V_163 ) ;
switch ( V_289 ) {
case V_290 :
if ( V_61 -> V_6 ) {
V_155 = - V_291 ;
goto V_164;
}
if ( * ( int * ) V_23 )
V_61 -> V_166 = V_191 ;
else
V_61 -> V_166 = V_171 ;
break;
default:
V_155 = - V_34 ;
}
V_164:
F_68 ( & V_61 -> V_163 ) ;
return V_155 ;
}
static int F_123 ( struct V_15 * V_8 , struct V_292 * args )
{
T_2 V_223 , V_293 = 0 ;
if ( args -> V_294 > 0 )
V_293 |= ( T_1 ) args -> args [ 0 ] ;
if ( args -> V_294 > 1 )
V_293 |= ( T_1 ) args -> args [ 1 ] << V_224 ;
else if ( ! F_124 ( args -> V_27 , L_17 , & V_223 ) )
V_293 |= ( T_1 ) V_223 << V_224 ;
return F_24 ( V_8 , & V_293 , 1 ) ;
}
static void F_125 ( struct V_15 * V_8 ,
struct V_295 * V_296 )
{
struct V_297 * V_298 ;
int V_266 = V_299 | V_300 | V_301 ;
V_298 = F_126 ( V_302 , V_303 ,
V_266 , V_304 ) ;
if ( ! V_298 )
return;
F_127 ( & V_298 -> V_305 , V_296 ) ;
F_128 ( V_8 , V_296 ) ;
}
static void F_129 ( struct V_15 * V_8 ,
struct V_295 * V_296 )
{
struct V_297 * V_306 , * V_307 ;
F_130 (entry, next, head, list)
F_25 ( V_306 ) ;
}
static void F_131 ( struct V_5 * V_6 )
{
void T_3 * V_101 = F_38 ( V_6 ) ;
void T_3 * V_90 ;
int V_7 ;
T_2 V_79 , V_308 ;
V_79 = F_33 ( F_54 ( V_6 ) + V_102 ) ;
F_52 ( V_79 , F_54 ( V_6 ) + V_102 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_242 ; ++ V_7 )
F_83 ( V_6 , V_7 ) ;
if ( V_6 -> V_309 == V_310 ) {
V_79 = F_33 ( V_101 + V_311 ) ;
V_308 = ( V_79 >> V_312 ) & V_313 ;
V_79 = F_33 ( V_101 + V_314 ) ;
if ( V_308 >= 2 )
V_79 &= ~ V_315 ;
V_79 |= V_316 ;
F_32 ( V_79 , V_101 + V_314 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_198 ; ++ V_7 ) {
V_90 = F_42 ( V_6 , V_7 ) ;
F_32 ( 0 , V_90 + V_154 ) ;
F_32 ( V_92 , V_90 + V_91 ) ;
if ( V_6 -> V_309 == V_310 ) {
V_79 = F_33 ( V_90 + V_317 ) ;
V_79 &= ~ V_318 ;
F_32 ( V_79 , V_90 + V_317 ) ;
}
}
F_32 ( 0 , V_101 + V_319 ) ;
F_32 ( 0 , V_101 + V_320 ) ;
V_79 = F_33 ( F_54 ( V_6 ) + V_321 ) ;
V_79 |= ( V_322 | V_323 | V_324 | V_325 ) ;
V_79 |= ( V_326 | V_327 ) ;
V_79 &= ~ V_328 ;
if ( V_329 )
V_79 |= V_330 ;
else
V_79 &= ~ V_330 ;
V_79 &= ~ V_331 ;
V_79 &= ~ ( V_332 << V_333 ) ;
if ( V_6 -> V_115 & V_116 )
V_79 |= V_334 ;
if ( V_6 -> V_115 & V_225 )
V_79 |= V_335 ;
F_37 ( V_6 ) ;
F_52 ( V_79 , F_54 ( V_6 ) + V_321 ) ;
}
static int F_132 ( int V_73 )
{
switch ( V_73 ) {
case 0 :
return 32 ;
case 1 :
return 36 ;
case 2 :
return 40 ;
case 3 :
return 42 ;
case 4 :
return 44 ;
case 5 :
default:
return 48 ;
}
}
static int F_133 ( struct V_5 * V_6 )
{
unsigned long V_73 ;
void T_3 * V_101 = F_38 ( V_6 ) ;
T_2 V_221 ;
bool V_336 , V_337 = V_6 -> V_115 & V_204 ;
int V_7 ;
F_5 ( V_6 -> V_8 , L_18 ) ;
F_5 ( V_6 -> V_8 , L_19 ,
V_6 -> V_111 == V_118 ? 2 : 1 ) ;
V_221 = F_33 ( V_101 + V_338 ) ;
if ( V_339 == 1 )
V_221 &= ~ ( V_340 | V_341 ) ;
else if ( V_339 == 2 )
V_221 &= ~ ( V_342 | V_341 ) ;
if ( V_221 & V_342 ) {
V_6 -> V_115 |= V_168 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_221 & V_340 ) {
V_6 -> V_115 |= V_170 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_221 & V_341 ) {
V_6 -> V_115 |= V_343 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( ! ( V_6 -> V_115 &
( V_168 | V_170 ) ) ) {
F_67 ( V_6 -> V_8 , L_23 ) ;
return - V_34 ;
}
if ( ( V_221 & V_342 ) &&
( ( V_6 -> V_111 < V_118 ) || ! ( V_221 & V_344 ) ) ) {
V_6 -> V_115 |= V_277 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
V_336 = ! ! ( V_221 & V_345 ) ;
if ( V_337 || V_336 )
F_5 ( V_6 -> V_8 , L_25 ,
V_337 ? L_26 : L_27 ) ;
if ( V_337 != V_336 )
F_5 ( V_6 -> V_8 ,
L_28 ) ;
if ( V_6 -> V_111 == V_118 && V_221 & V_346 ) {
V_6 -> V_115 |= V_225 ;
V_73 = 1 << 16 ;
} else {
V_73 = 1 << ( ( V_221 >> V_347 ) & V_348 ) ;
}
V_6 -> V_239 = V_73 - 1 ;
if ( V_221 & V_349 ) {
V_6 -> V_115 |= V_350 ;
V_73 = ( V_221 >> V_351 ) & V_352 ;
if ( V_73 == 0 ) {
F_67 ( V_6 -> V_8 ,
L_29 ) ;
return - V_34 ;
}
V_6 -> V_220 = F_134 ( V_6 -> V_8 , V_73 , sizeof( * V_6 -> V_220 ) ,
V_41 ) ;
if ( ! V_6 -> V_220 )
return - V_42 ;
F_5 ( V_6 -> V_8 ,
L_30 , V_73 ) ;
}
V_6 -> V_230 = F_135 ( V_6 -> V_8 , V_73 , sizeof( * V_6 -> V_230 ) ,
V_41 ) ;
if ( ! V_6 -> V_230 )
return - V_42 ;
for ( V_7 = 0 ; V_7 < V_73 ; V_7 ++ )
V_6 -> V_230 [ V_7 ] = V_244 ;
V_6 -> V_242 = V_73 ;
F_75 ( & V_6 -> V_251 ) ;
F_76 ( & V_6 -> V_57 ) ;
if ( V_6 -> V_111 < V_118 || ! ( V_221 & V_353 ) ) {
V_6 -> V_115 |= V_172 ;
if ( ! ( V_221 & V_354 ) )
V_6 -> V_115 |= V_177 ;
}
V_221 = F_33 ( V_101 + V_355 ) ;
V_6 -> V_356 = ( V_221 & V_357 ) ? 16 : 12 ;
V_73 = 1 << ( ( ( V_221 >> V_358 ) & V_359 ) + 1 ) ;
V_73 <<= V_6 -> V_356 ;
if ( V_6 -> V_90 != V_101 + V_73 )
F_136 ( V_6 -> V_8 ,
L_31 ,
V_73 * 2 , ( V_6 -> V_90 - V_101 ) * 2 ) ;
V_6 -> V_184 = ( V_221 >> V_360 ) & V_361 ;
V_6 -> V_198 = ( V_221 >> V_362 ) & V_363 ;
if ( V_6 -> V_184 > V_6 -> V_198 ) {
F_67 ( V_6 -> V_8 , L_32 ) ;
return - V_34 ;
}
F_5 ( V_6 -> V_8 , L_33 ,
V_6 -> V_198 , V_6 -> V_184 ) ;
if ( V_6 -> V_309 == V_364 ) {
V_6 -> V_200 =
F_137 ( V_6 -> V_198 ,
& V_365 ) ;
V_6 -> V_200 -= V_6 -> V_198 ;
F_5 ( V_6 -> V_8 , L_34 ) ;
}
V_221 = F_33 ( V_101 + V_366 ) ;
V_73 = F_132 ( ( V_221 >> V_367 ) & V_368 ) ;
V_6 -> V_186 = V_73 ;
V_73 = F_132 ( ( V_221 >> V_369 ) & V_370 ) ;
V_6 -> V_192 = V_73 ;
if ( V_221 & V_371 )
V_6 -> V_115 |= V_116 ;
if ( F_138 ( V_6 -> V_8 , F_139 ( V_73 ) ) )
F_136 ( V_6 -> V_8 ,
L_35 ) ;
if ( V_6 -> V_111 < V_118 ) {
V_6 -> V_185 = V_6 -> V_186 ;
if ( V_6 -> V_111 == V_372 )
V_6 -> V_115 |= V_179 ;
} else {
V_73 = ( V_221 >> V_373 ) & V_374 ;
V_6 -> V_185 = F_132 ( V_73 ) ;
if ( V_221 & V_375 )
V_6 -> V_115 |= V_181 ;
if ( V_221 & V_376 )
V_6 -> V_115 |= V_180 ;
if ( V_221 & V_377 )
V_6 -> V_115 |= V_179 ;
}
if ( V_6 -> V_115 & V_177 )
V_6 -> V_201 |= V_378 | V_379 | V_380 | V_381 ;
if ( V_6 -> V_115 &
( V_172 | V_181 ) )
V_6 -> V_201 |= V_378 | V_382 | V_383 ;
if ( V_6 -> V_115 & V_180 )
V_6 -> V_201 |= V_384 | V_385 ;
if ( V_6 -> V_115 & V_179 )
V_6 -> V_201 |= V_379 | V_386 ;
if ( V_40 . V_201 == - 1UL )
V_40 . V_201 = V_6 -> V_201 ;
else
V_40 . V_201 |= V_6 -> V_201 ;
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_201 ) ;
if ( V_6 -> V_115 & V_168 )
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_185 , V_6 -> V_186 ) ;
if ( V_6 -> V_115 & V_170 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_186 , V_6 -> V_192 ) ;
return 0 ;
}
static int F_140 ( T_2 V_309 , struct V_5 * V_6 )
{
int V_155 = 0 ;
switch ( V_309 ) {
case V_387 :
case V_388 :
V_6 -> V_111 = V_112 ;
V_6 -> V_309 = V_389 ;
break;
case V_390 :
V_6 -> V_111 = V_372 ;
V_6 -> V_309 = V_389 ;
break;
case V_391 :
V_6 -> V_111 = V_118 ;
V_6 -> V_309 = V_389 ;
break;
case V_392 :
V_6 -> V_111 = V_118 ;
V_6 -> V_309 = V_310 ;
break;
case V_393 :
V_6 -> V_111 = V_118 ;
V_6 -> V_309 = V_364 ;
break;
default:
V_155 = - V_34 ;
}
return V_155 ;
}
static int F_141 ( struct V_394 * V_21 ,
struct V_5 * V_6 )
{
struct V_15 * V_8 = V_6 -> V_8 ;
struct V_395 * V_28 =
* (struct V_395 * * ) F_142 ( V_8 ) ;
struct V_396 * V_397 ;
int V_155 ;
V_397 = (struct V_396 * ) V_28 -> V_398 ;
V_155 = F_140 ( V_397 -> V_309 , V_6 ) ;
if ( V_155 < 0 )
return V_155 ;
V_6 -> V_212 = 1 ;
if ( V_397 -> V_56 & V_399 )
V_6 -> V_115 |= V_204 ;
return 0 ;
}
static inline int F_141 ( struct V_394 * V_21 ,
struct V_5 * V_6 )
{
return - V_34 ;
}
static int F_143 ( struct V_394 * V_21 ,
struct V_5 * V_6 )
{
const struct V_400 * V_23 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
bool V_401 ;
if ( F_124 ( V_8 -> V_9 , L_39 ,
& V_6 -> V_212 ) ) {
F_67 ( V_8 , L_40 ) ;
return - V_34 ;
}
V_23 = F_144 ( V_8 ) ;
V_6 -> V_111 = V_23 -> V_111 ;
V_6 -> V_309 = V_23 -> V_309 ;
F_3 ( V_6 ) ;
V_401 = F_16 ( V_8 -> V_9 , L_2 , NULL ) ;
if ( V_401 && ! V_402 ) {
if ( ! V_217 )
F_145 ( L_41 ) ;
V_217 = true ;
} else if ( ! V_401 && ! V_217 ) {
V_402 = true ;
} else {
F_67 ( V_8 , L_42 ) ;
return - V_34 ;
}
if ( F_146 ( V_8 -> V_9 ) )
V_6 -> V_115 |= V_204 ;
return 0 ;
}
static void F_147 ( void )
{
if ( ! F_148 ( & V_403 ) )
F_149 ( & V_403 , & V_40 ) ;
#ifdef F_150
if ( ! F_148 ( & V_404 ) )
F_149 ( & V_404 , & V_40 ) ;
#endif
#ifdef F_151
if ( ! F_148 ( & V_405 ) ) {
F_152 () ;
F_149 ( & V_405 , & V_40 ) ;
}
#endif
}
static int F_153 ( struct V_394 * V_21 )
{
struct V_406 * V_407 ;
T_9 V_408 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
int V_409 , V_7 , V_29 ;
V_6 = F_154 ( V_8 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 ) {
F_67 ( V_8 , L_43 ) ;
return - V_42 ;
}
V_6 -> V_8 = V_8 ;
if ( V_8 -> V_9 )
V_29 = F_143 ( V_21 , V_6 ) ;
else
V_29 = F_141 ( V_21 , V_6 ) ;
if ( V_29 )
return V_29 ;
V_407 = F_155 ( V_21 , V_410 , 0 ) ;
V_408 = V_407 -> V_44 ;
V_6 -> V_55 = F_156 ( V_8 , V_407 ) ;
if ( F_91 ( V_6 -> V_55 ) )
return F_92 ( V_6 -> V_55 ) ;
V_6 -> V_90 = V_6 -> V_55 + F_157 ( V_407 ) / 2 ;
V_409 = 0 ;
while ( ( V_407 = F_155 ( V_21 , V_411 , V_409 ) ) ) {
V_409 ++ ;
if ( V_409 > V_6 -> V_212 )
V_6 -> V_199 ++ ;
}
if ( ! V_6 -> V_199 ) {
F_67 ( V_8 , L_44 ,
V_409 , V_6 -> V_212 + 1 ) ;
return - V_34 ;
}
V_6 -> V_211 = F_154 ( V_8 , sizeof( * V_6 -> V_211 ) * V_409 ,
V_41 ) ;
if ( ! V_6 -> V_211 ) {
F_67 ( V_8 , L_45 , V_409 ) ;
return - V_42 ;
}
for ( V_7 = 0 ; V_7 < V_409 ; ++ V_7 ) {
int V_87 = F_158 ( V_21 , V_7 ) ;
if ( V_87 < 0 ) {
F_67 ( V_8 , L_46 , V_7 ) ;
return - V_34 ;
}
V_6 -> V_211 [ V_7 ] = V_87 ;
}
V_29 = F_133 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_111 == V_118 &&
V_6 -> V_198 != V_6 -> V_199 ) {
F_67 ( V_8 ,
L_47 ,
V_6 -> V_199 , V_6 -> V_198 ) ;
return - V_34 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_212 ; ++ V_7 ) {
V_29 = F_66 ( V_6 -> V_8 , V_6 -> V_211 [ V_7 ] ,
F_53 ,
V_213 ,
L_48 ,
V_6 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_49 ,
V_7 , V_6 -> V_211 [ V_7 ] ) ;
return V_29 ;
}
}
V_29 = F_159 ( & V_6 -> V_287 , V_6 -> V_8 , NULL ,
L_50 , & V_408 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_51 ) ;
return V_29 ;
}
F_160 ( & V_6 -> V_287 , & V_40 ) ;
F_161 ( & V_6 -> V_287 , V_8 -> V_39 ) ;
V_29 = F_162 ( & V_6 -> V_287 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_52 ) ;
return V_29 ;
}
F_163 ( V_21 , V_6 ) ;
F_131 ( V_6 ) ;
F_84 ( V_6 ) ;
if ( ! V_217 )
F_147 () ;
return 0 ;
}
static int F_164 ( void )
{
if ( V_217 )
F_147 () ;
return 0 ;
}
static int F_165 ( struct V_394 * V_21 )
{
struct V_5 * V_6 = F_166 ( V_21 ) ;
if ( ! V_6 )
return - V_34 ;
if ( ! F_167 ( V_6 -> V_197 , V_412 ) )
F_67 ( & V_21 -> V_8 , L_53 ) ;
F_52 ( V_328 , F_54 ( V_6 ) + V_321 ) ;
return 0 ;
}
