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
struct V_67 * V_62 = & V_61 -> V_62 ;
struct V_108 * V_109 = & V_61 -> V_6 -> V_110 [ V_62 -> V_63 ] ;
bool V_76 = V_62 -> V_77 != V_78 ;
V_109 -> V_62 = V_62 ;
if ( V_76 ) {
if ( V_62 -> V_82 == V_111 ) {
V_109 -> V_112 [ 0 ] = V_107 -> V_113 . V_112 ;
} else {
V_109 -> V_112 [ 0 ] = V_107 -> V_114 . V_112 ;
V_109 -> V_112 [ 1 ] = V_107 -> V_114 . V_112 >> 32 ;
V_109 -> V_112 [ 1 ] |= V_115 ;
if ( V_62 -> V_82 == V_83 )
V_109 -> V_112 [ 1 ] |= V_116 ;
}
} else {
V_109 -> V_112 [ 0 ] = V_107 -> V_117 . V_118 ;
}
if ( V_76 ) {
if ( V_62 -> V_82 == V_111 ) {
V_109 -> V_119 [ 0 ] = V_107 -> V_113 . V_119 [ 0 ] ;
V_109 -> V_119 [ 1 ] = V_107 -> V_113 . V_119 [ 1 ] ;
} else {
V_109 -> V_119 [ 0 ] = V_107 -> V_114 . V_119 [ 0 ] ;
V_109 -> V_119 [ 0 ] |= ( V_84 ) V_62 -> V_68 << V_120 ;
V_109 -> V_119 [ 1 ] = V_107 -> V_114 . V_119 [ 1 ] ;
V_109 -> V_119 [ 1 ] |= ( V_84 ) V_62 -> V_68 << V_120 ;
}
} else {
V_109 -> V_119 [ 0 ] = V_107 -> V_117 . V_121 ;
}
if ( V_76 ) {
if ( V_62 -> V_82 == V_111 ) {
V_109 -> V_122 [ 0 ] = V_107 -> V_113 . V_123 ;
V_109 -> V_122 [ 1 ] = V_107 -> V_113 . V_124 ;
} else {
V_109 -> V_122 [ 0 ] = V_107 -> V_114 . V_122 [ 0 ] ;
V_109 -> V_122 [ 1 ] = V_107 -> V_114 . V_122 [ 1 ] ;
}
}
}
static void F_56 ( struct V_5 * V_6 , int V_46 )
{
T_2 V_79 ;
bool V_76 ;
struct V_108 * V_109 = & V_6 -> V_110 [ V_46 ] ;
struct V_67 * V_62 = V_109 -> V_62 ;
void T_3 * V_90 , * V_125 ;
V_90 = F_42 ( V_6 , V_46 ) ;
if ( ! V_62 ) {
F_32 ( 0 , V_90 + V_126 ) ;
return;
}
V_125 = F_57 ( V_6 ) ;
V_76 = V_62 -> V_77 != V_78 ;
if ( V_6 -> V_127 > V_128 ) {
if ( V_62 -> V_82 == V_83 )
V_79 = V_129 ;
else
V_79 = V_130 ;
if ( V_6 -> V_131 & V_132 )
V_79 |= V_62 -> V_70 << V_133 ;
F_32 ( V_79 , V_125 + F_58 ( V_46 ) ) ;
}
V_79 = V_62 -> V_77 ;
if ( V_6 -> V_127 < V_134 )
V_79 |= V_62 -> V_135 << V_136 ;
if ( V_76 ) {
V_79 |= ( V_137 << V_138 ) |
( V_139 << V_140 ) ;
} else if ( ! ( V_6 -> V_131 & V_132 ) ) {
V_79 |= V_62 -> V_70 << V_141 ;
}
F_32 ( V_79 , V_125 + F_59 ( V_46 ) ) ;
if ( V_76 && V_6 -> V_127 > V_128 )
F_32 ( V_109 -> V_112 [ 1 ] , V_90 + V_142 ) ;
F_32 ( V_109 -> V_112 [ 0 ] , V_90 + V_143 ) ;
if ( V_62 -> V_82 == V_111 ) {
F_32 ( V_62 -> V_68 , V_90 + V_144 ) ;
F_32 ( V_109 -> V_119 [ 0 ] , V_90 + V_145 ) ;
F_32 ( V_109 -> V_119 [ 1 ] , V_90 + V_146 ) ;
} else {
F_47 ( V_109 -> V_119 [ 0 ] , V_90 + V_145 ) ;
if ( V_76 )
F_47 ( V_109 -> V_119 [ 1 ] , V_90 + V_146 ) ;
}
if ( V_76 ) {
F_32 ( V_109 -> V_122 [ 0 ] , V_90 + V_147 ) ;
F_32 ( V_109 -> V_122 [ 1 ] , V_90 + V_148 ) ;
}
V_79 = V_149 | V_150 | V_151 | V_152 | V_153 ;
if ( V_76 )
V_79 |= V_154 ;
if ( F_60 ( V_155 ) )
V_79 |= V_156 ;
F_32 ( V_79 , V_90 + V_126 ) ;
}
static int F_61 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_87 , V_44 , V_157 = 0 ;
unsigned long V_158 , V_159 ;
struct V_160 * V_161 ;
struct V_106 V_107 ;
enum V_162 V_82 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_67 * V_62 = & V_61 -> V_62 ;
const struct V_163 * V_164 ;
F_62 ( & V_61 -> V_165 ) ;
if ( V_61 -> V_6 )
goto V_166;
if ( V_4 -> type == V_167 ) {
V_61 -> V_168 = V_169 ;
V_61 -> V_6 = V_6 ;
goto V_166;
}
if ( ! ( V_6 -> V_131 & V_170 ) )
V_61 -> V_168 = V_171 ;
if ( ! ( V_6 -> V_131 & V_172 ) )
V_61 -> V_168 = V_173 ;
if ( V_6 -> V_131 & V_174 )
V_62 -> V_82 = V_175 ;
if ( F_60 ( V_176 ) &&
! F_60 ( V_177 ) && ! F_60 ( V_178 ) &&
( V_6 -> V_131 & V_179 ) &&
( V_61 -> V_168 == V_173 ) )
V_62 -> V_82 = V_111 ;
if ( ( F_60 ( V_177 ) || V_62 -> V_82 == V_180 ) &&
( V_6 -> V_131 & ( V_181 |
V_182 |
V_183 ) ) )
V_62 -> V_82 = V_83 ;
if ( V_62 -> V_82 == V_180 ) {
V_157 = - V_184 ;
goto V_166;
}
switch ( V_61 -> V_168 ) {
case V_173 :
V_62 -> V_77 = V_185 ;
V_44 = V_6 -> V_186 ;
V_158 = V_6 -> V_187 ;
V_159 = V_6 -> V_188 ;
if ( V_62 -> V_82 == V_83 ) {
V_82 = V_189 ;
} else if ( V_62 -> V_82 == V_175 ) {
V_82 = V_190 ;
V_158 = F_63 ( V_158 , 32UL ) ;
V_159 = F_63 ( V_159 , 40UL ) ;
} else {
V_82 = V_191 ;
V_158 = F_63 ( V_158 , 32UL ) ;
V_159 = F_63 ( V_159 , 32UL ) ;
}
V_164 = & V_192 ;
break;
case V_193 :
case V_171 :
V_62 -> V_77 = V_78 ;
V_44 = 0 ;
V_158 = V_6 -> V_188 ;
V_159 = V_6 -> V_194 ;
if ( V_62 -> V_82 == V_83 ) {
V_82 = V_195 ;
} else {
V_82 = V_196 ;
V_158 = F_63 ( V_158 , 40UL ) ;
V_159 = F_63 ( V_159 , 40UL ) ;
}
if ( V_6 -> V_127 == V_134 )
V_164 = & V_197 ;
else
V_164 = & V_198 ;
break;
default:
V_157 = - V_184 ;
goto V_166;
}
V_157 = F_26 ( V_6 -> V_199 , V_44 ,
V_6 -> V_200 ) ;
if ( V_157 < 0 )
goto V_166;
V_62 -> V_63 = V_157 ;
if ( V_6 -> V_127 < V_134 ) {
V_62 -> V_135 = F_64 ( & V_6 -> V_135 ) ;
V_62 -> V_135 %= V_6 -> V_201 ;
} else {
V_62 -> V_135 = V_62 -> V_63 ;
}
if ( V_61 -> V_168 == V_171 )
V_62 -> V_70 = V_62 -> V_63 + 1 + V_6 -> V_202 ;
else
V_62 -> V_68 = V_62 -> V_63 + V_6 -> V_202 ;
V_107 = (struct V_106 ) {
. V_203 = V_6 -> V_203 ,
. V_158 = V_158 ,
. V_159 = V_159 ,
. V_204 = V_164 ,
. V_205 = V_6 -> V_8 ,
} ;
if ( V_6 -> V_131 & V_206 )
V_107 . V_207 = V_208 ;
V_61 -> V_6 = V_6 ;
V_161 = F_65 ( V_82 , & V_107 , V_61 ) ;
if ( ! V_161 ) {
V_157 = - V_42 ;
goto V_209;
}
V_4 -> V_203 = V_107 . V_203 ;
V_4 -> V_210 . V_211 = ( 1UL << V_158 ) - 1 ;
V_4 -> V_210 . V_212 = true ;
F_55 ( V_61 , & V_107 ) ;
F_56 ( V_6 , V_62 -> V_63 ) ;
V_87 = V_6 -> V_213 [ V_6 -> V_214 + V_62 -> V_135 ] ;
V_157 = F_66 ( V_6 -> V_8 , V_87 , F_50 ,
V_215 , L_8 , V_4 ) ;
if ( V_157 < 0 ) {
F_67 ( V_6 -> V_8 , L_9 ,
V_62 -> V_135 , V_87 ) ;
V_62 -> V_135 = V_216 ;
}
F_68 ( & V_61 -> V_165 ) ;
V_61 -> V_161 = V_161 ;
return 0 ;
V_209:
V_61 -> V_6 = NULL ;
V_166:
F_68 ( & V_61 -> V_165 ) ;
return V_157 ;
}
static void F_69 ( struct V_2 * V_4 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
int V_87 ;
if ( ! V_6 || V_4 -> type == V_167 )
return;
V_6 -> V_110 [ V_62 -> V_63 ] . V_62 = NULL ;
F_56 ( V_6 , V_62 -> V_63 ) ;
if ( V_62 -> V_135 != V_216 ) {
V_87 = V_6 -> V_213 [ V_6 -> V_214 + V_62 -> V_135 ] ;
F_70 ( V_6 -> V_8 , V_87 , V_4 ) ;
}
F_71 ( V_61 -> V_161 ) ;
F_29 ( V_6 -> V_199 , V_62 -> V_63 ) ;
}
static struct V_2 * F_72 ( unsigned type )
{
struct V_1 * V_61 ;
if ( type != V_217 &&
type != V_218 &&
type != V_167 )
return NULL ;
V_61 = F_73 ( sizeof( * V_61 ) , V_41 ) ;
if ( ! V_61 )
return NULL ;
if ( type == V_218 && ( V_219 ||
F_74 ( & V_61 -> V_4 ) ) ) {
F_25 ( V_61 ) ;
return NULL ;
}
F_75 ( & V_61 -> V_165 ) ;
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
struct V_220 * V_221 = V_6 -> V_222 + V_46 ;
T_2 V_79 = V_221 -> V_223 << V_224 | V_221 -> V_225 << V_226 ;
if ( ! ( V_6 -> V_131 & V_227 ) && V_221 -> V_228 )
V_79 |= V_229 ;
F_32 ( V_79 , F_38 ( V_6 ) + F_80 ( V_46 ) ) ;
}
static void F_81 ( struct V_5 * V_6 , int V_46 )
{
struct V_230 * V_231 = V_6 -> V_232 + V_46 ;
T_2 V_79 = ( V_231 -> type & V_233 ) << V_234 |
( V_231 -> V_63 & V_235 ) << V_236 |
( V_231 -> V_237 & V_238 ) << V_239 ;
if ( V_6 -> V_131 & V_227 && V_6 -> V_222 &&
V_6 -> V_222 [ V_46 ] . V_228 )
V_79 |= V_240 ;
F_32 ( V_79 , F_38 ( V_6 ) + F_82 ( V_46 ) ) ;
}
static void F_83 ( struct V_5 * V_6 , int V_46 )
{
F_81 ( V_6 , V_46 ) ;
if ( V_6 -> V_222 )
F_79 ( V_6 , V_46 ) ;
}
static void F_84 ( struct V_5 * V_6 )
{
void T_3 * V_101 = F_38 ( V_6 ) ;
T_2 V_221 ;
if ( ! V_6 -> V_222 )
return;
V_221 = V_6 -> V_241 << V_224 ;
F_32 ( V_221 , V_101 + F_80 ( 0 ) ) ;
V_221 = F_33 ( V_101 + F_80 ( 0 ) ) ;
V_6 -> V_241 = V_221 >> V_224 ;
V_221 = V_6 -> V_241 << V_226 ;
F_32 ( V_221 , V_101 + F_80 ( 0 ) ) ;
V_221 = F_33 ( V_101 + F_80 ( 0 ) ) ;
V_6 -> V_242 = V_221 >> V_226 ;
}
static int F_85 ( struct V_5 * V_6 , T_1 V_223 , T_1 V_225 )
{
struct V_220 * V_222 = V_6 -> V_222 ;
int V_7 , V_243 = - V_47 ;
if ( ! V_222 )
return V_223 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_244 ; ++ V_7 ) {
if ( ! V_222 [ V_7 ] . V_228 ) {
if ( V_243 < 0 )
V_243 = V_7 ;
continue;
}
if ( ( V_225 & V_222 [ V_7 ] . V_225 ) == V_225 &&
! ( ( V_223 ^ V_222 [ V_7 ] . V_223 ) & ~ V_222 [ V_7 ] . V_225 ) )
return V_7 ;
if ( ! ( ( V_223 ^ V_222 [ V_7 ] . V_223 ) & ~ ( V_222 [ V_7 ] . V_225 | V_225 ) ) )
return - V_184 ;
}
return V_243 ;
}
static bool F_86 ( struct V_5 * V_6 , int V_46 )
{
if ( -- V_6 -> V_232 [ V_46 ] . V_245 )
return false ;
V_6 -> V_232 [ V_46 ] = V_246 ;
if ( V_6 -> V_222 )
V_6 -> V_222 [ V_46 ] . V_228 = false ;
return true ;
}
static int F_87 ( struct V_15 * V_8 )
{
struct V_247 * V_248 = V_8 -> V_247 ;
struct V_249 * V_62 = V_248 -> V_250 ;
struct V_5 * V_6 = V_62 -> V_6 ;
struct V_220 * V_222 = V_6 -> V_222 ;
struct V_251 * V_252 ;
int V_7 , V_46 , V_157 ;
F_62 ( & V_6 -> V_253 ) ;
F_88 (fwspec, i, idx) {
T_1 V_254 = V_248 -> V_255 [ V_7 ] ;
T_1 V_225 = V_248 -> V_255 [ V_7 ] >> V_226 ;
if ( V_46 != V_256 ) {
V_157 = - V_257 ;
goto V_258;
}
V_157 = F_85 ( V_6 , V_254 , V_225 ) ;
if ( V_157 < 0 )
goto V_258;
V_46 = V_157 ;
if ( V_222 && V_6 -> V_232 [ V_46 ] . V_245 == 0 ) {
V_222 [ V_46 ] . V_223 = V_254 ;
V_222 [ V_46 ] . V_225 = V_225 ;
V_222 [ V_46 ] . V_228 = true ;
}
V_6 -> V_232 [ V_46 ] . V_245 ++ ;
V_62 -> V_259 [ V_7 ] = ( V_260 ) V_46 ;
}
V_252 = F_89 ( V_8 ) ;
if ( ! V_252 )
V_252 = F_90 ( - V_42 ) ;
if ( F_91 ( V_252 ) ) {
V_157 = F_92 ( V_252 ) ;
goto V_258;
}
F_93 ( V_252 ) ;
F_88 (fwspec, i, idx) {
F_83 ( V_6 , V_46 ) ;
V_6 -> V_232 [ V_46 ] . V_252 = V_252 ;
}
F_68 ( & V_6 -> V_253 ) ;
return 0 ;
V_258:
while ( V_7 -- ) {
F_86 ( V_6 , V_62 -> V_259 [ V_7 ] ) ;
V_62 -> V_259 [ V_7 ] = V_256 ;
}
F_68 ( & V_6 -> V_253 ) ;
return V_157 ;
}
static void F_94 ( struct V_247 * V_248 )
{
struct V_5 * V_6 = F_95 ( V_248 ) ;
struct V_249 * V_62 = V_248 -> V_250 ;
int V_7 , V_46 ;
F_62 ( & V_6 -> V_253 ) ;
F_88 (fwspec, i, idx) {
if ( F_86 ( V_6 , V_46 ) )
F_83 ( V_6 , V_46 ) ;
V_62 -> V_259 [ V_7 ] = V_256 ;
}
F_68 ( & V_6 -> V_253 ) ;
}
static int F_96 ( struct V_1 * V_61 ,
struct V_247 * V_248 )
{
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_230 * V_231 = V_6 -> V_232 ;
T_6 V_63 = V_61 -> V_62 . V_63 ;
enum V_261 type ;
int V_7 , V_46 ;
if ( V_61 -> V_168 == V_169 )
type = V_262 ;
else
type = V_263 ;
F_88 (fwspec, i, idx) {
if ( type == V_231 [ V_46 ] . type && V_63 == V_231 [ V_46 ] . V_63 )
continue;
V_231 [ V_46 ] . type = type ;
V_231 [ V_46 ] . V_237 = V_264 ;
V_231 [ V_46 ] . V_63 = V_63 ;
F_81 ( V_6 , V_46 ) ;
}
return 0 ;
}
static int F_97 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_157 ;
struct V_247 * V_248 = V_8 -> V_247 ;
struct V_5 * V_6 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( ! V_248 || V_248 -> V_265 != & V_40 ) {
F_67 ( V_8 , L_10 ) ;
return - V_266 ;
}
if ( ! V_248 -> V_250 )
return - V_34 ;
V_6 = F_95 ( V_248 ) ;
V_157 = F_61 ( V_4 , V_6 ) ;
if ( V_157 < 0 )
return V_157 ;
if ( V_61 -> V_6 != V_6 ) {
F_67 ( V_8 ,
L_11 ,
F_98 ( V_61 -> V_6 -> V_8 ) , F_98 ( V_6 -> V_8 ) ) ;
return - V_184 ;
}
return F_96 ( V_61 , V_248 ) ;
}
static int F_99 ( struct V_2 * V_4 , unsigned long V_72 ,
T_7 V_267 , T_4 V_73 , int V_268 )
{
struct V_160 * V_265 = F_1 ( V_4 ) -> V_161 ;
if ( ! V_265 )
return - V_34 ;
return V_265 -> V_43 ( V_265 , V_72 , V_267 , V_73 , V_268 ) ;
}
static T_4 F_100 ( struct V_2 * V_4 , unsigned long V_72 ,
T_4 V_73 )
{
struct V_160 * V_265 = F_1 ( V_4 ) -> V_161 ;
if ( ! V_265 )
return 0 ;
return V_265 -> V_269 ( V_265 , V_72 , V_73 ) ;
}
static T_7 F_101 ( struct V_2 * V_4 ,
T_8 V_72 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_61 -> V_6 ;
struct V_67 * V_62 = & V_61 -> V_62 ;
struct V_160 * V_265 = V_61 -> V_161 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_3 * V_90 ;
T_2 V_270 ;
V_84 V_271 ;
unsigned long V_272 , V_56 ;
V_90 = F_42 ( V_6 , V_62 -> V_63 ) ;
F_39 ( & V_61 -> V_64 , V_56 ) ;
V_272 = V_72 & ~ 0xfffUL ;
if ( V_6 -> V_127 == V_134 )
F_48 ( V_272 , V_90 + V_273 ) ;
else
F_32 ( V_272 , V_90 + V_273 ) ;
if ( F_102 ( V_90 + V_274 , V_270 ,
! ( V_270 & V_275 ) , 5 , 50 ) ) {
F_40 ( & V_61 -> V_64 , V_56 ) ;
F_67 ( V_8 ,
L_12 ,
& V_72 ) ;
return V_265 -> V_276 ( V_265 , V_72 ) ;
}
V_271 = F_51 ( V_90 + V_277 ) ;
F_40 ( & V_61 -> V_64 , V_56 ) ;
if ( V_271 & V_278 ) {
F_67 ( V_8 , L_13 ) ;
F_67 ( V_8 , L_14 , V_271 ) ;
return 0 ;
}
return ( V_271 & F_103 ( 39 , 12 ) ) | ( V_72 & 0xfff ) ;
}
static T_7 F_104 ( struct V_2 * V_4 ,
T_8 V_72 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
struct V_160 * V_265 = V_61 -> V_161 ;
if ( V_4 -> type == V_167 )
return V_72 ;
if ( ! V_265 )
return 0 ;
if ( V_61 -> V_6 -> V_131 & V_279 &&
V_61 -> V_168 == V_173 )
return F_101 ( V_4 , V_72 ) ;
return V_265 -> V_276 ( V_265 , V_72 ) ;
}
static bool F_105 ( enum V_280 V_281 )
{
switch ( V_281 ) {
case V_282 :
return true ;
case V_283 :
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
struct V_5 * F_107 ( struct V_284 * V_39 )
{
struct V_15 * V_8 = F_108 ( & V_35 . V_36 , NULL ,
V_39 , F_106 ) ;
F_109 ( V_8 ) ;
return V_8 ? F_22 ( V_8 ) : NULL ;
}
static int F_110 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_249 * V_62 ;
struct V_247 * V_248 = V_8 -> V_247 ;
int V_7 , V_157 ;
if ( V_219 ) {
V_157 = F_15 ( V_8 , & V_6 ) ;
V_248 = V_8 -> V_247 ;
if ( V_157 )
goto V_285;
} else if ( V_248 && V_248 -> V_265 == & V_40 ) {
V_6 = F_107 ( V_248 -> V_286 ) ;
} else {
return - V_34 ;
}
V_157 = - V_184 ;
for ( V_7 = 0 ; V_7 < V_248 -> V_287 ; V_7 ++ ) {
T_1 V_254 = V_248 -> V_255 [ V_7 ] ;
T_1 V_225 = V_248 -> V_255 [ V_7 ] >> V_226 ;
if ( V_254 & ~ V_6 -> V_241 ) {
F_67 ( V_8 , L_15 ,
V_254 , V_6 -> V_241 ) ;
goto V_285;
}
if ( V_225 & ~ V_6 -> V_242 ) {
F_67 ( V_8 , L_16 ,
V_225 , V_6 -> V_242 ) ;
goto V_285;
}
}
V_157 = - V_42 ;
V_62 = F_73 ( F_111 ( struct V_249 , V_259 [ V_7 ] ) ,
V_41 ) ;
if ( ! V_62 )
goto V_285;
V_62 -> V_6 = V_6 ;
V_248 -> V_250 = V_62 ;
while ( V_7 -- )
V_62 -> V_259 [ V_7 ] = V_256 ;
V_157 = F_87 ( V_8 ) ;
if ( V_157 )
goto V_288;
F_112 ( & V_6 -> V_289 , V_8 ) ;
return 0 ;
V_288:
F_25 ( V_62 ) ;
V_285:
F_113 ( V_8 ) ;
return V_157 ;
}
static void F_114 ( struct V_15 * V_8 )
{
struct V_247 * V_248 = V_8 -> V_247 ;
struct V_249 * V_62 ;
struct V_5 * V_6 ;
if ( ! V_248 || V_248 -> V_265 != & V_40 )
return;
V_62 = V_248 -> V_250 ;
V_6 = V_62 -> V_6 ;
F_115 ( & V_6 -> V_289 , V_8 ) ;
F_94 ( V_248 ) ;
F_116 ( V_8 ) ;
F_25 ( V_248 -> V_250 ) ;
F_113 ( V_8 ) ;
}
static struct V_251 * F_117 ( struct V_15 * V_8 )
{
struct V_247 * V_248 = V_8 -> V_247 ;
struct V_5 * V_6 = F_95 ( V_248 ) ;
struct V_251 * V_252 = NULL ;
int V_7 , V_46 ;
F_88 (fwspec, i, idx) {
if ( V_252 && V_6 -> V_232 [ V_46 ] . V_252 &&
V_252 != V_6 -> V_232 [ V_46 ] . V_252 )
return F_90 ( - V_184 ) ;
V_252 = V_6 -> V_232 [ V_46 ] . V_252 ;
}
if ( V_252 )
return F_118 ( V_252 ) ;
if ( F_7 ( V_8 ) )
V_252 = F_119 ( V_8 ) ;
else
V_252 = F_120 ( V_8 ) ;
return V_252 ;
}
static int F_121 ( struct V_2 * V_4 ,
enum V_290 V_291 , void * V_23 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_217 )
return - V_184 ;
switch ( V_291 ) {
case V_292 :
* ( int * ) V_23 = ( V_61 -> V_168 == V_193 ) ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_122 ( struct V_2 * V_4 ,
enum V_290 V_291 , void * V_23 )
{
int V_157 = 0 ;
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_217 )
return - V_184 ;
F_62 ( & V_61 -> V_165 ) ;
switch ( V_291 ) {
case V_292 :
if ( V_61 -> V_6 ) {
V_157 = - V_293 ;
goto V_166;
}
if ( * ( int * ) V_23 )
V_61 -> V_168 = V_193 ;
else
V_61 -> V_168 = V_173 ;
break;
default:
V_157 = - V_34 ;
}
V_166:
F_68 ( & V_61 -> V_165 ) ;
return V_157 ;
}
static int F_123 ( struct V_15 * V_8 , struct V_294 * args )
{
T_2 V_225 , V_295 = 0 ;
if ( args -> V_296 > 0 )
V_295 |= ( T_1 ) args -> args [ 0 ] ;
if ( args -> V_296 > 1 )
V_295 |= ( T_1 ) args -> args [ 1 ] << V_226 ;
else if ( ! F_124 ( args -> V_27 , L_17 , & V_225 ) )
V_295 |= ( T_1 ) V_225 << V_226 ;
return F_24 ( V_8 , & V_295 , 1 ) ;
}
static void F_125 ( struct V_15 * V_8 ,
struct V_297 * V_298 )
{
struct V_299 * V_300 ;
int V_268 = V_301 | V_302 | V_303 ;
V_300 = F_126 ( V_304 , V_305 ,
V_268 , V_306 ) ;
if ( ! V_300 )
return;
F_127 ( & V_300 -> V_307 , V_298 ) ;
F_128 ( V_8 , V_298 ) ;
}
static void F_129 ( struct V_15 * V_8 ,
struct V_297 * V_298 )
{
struct V_299 * V_308 , * V_309 ;
F_130 (entry, next, head, list)
F_25 ( V_308 ) ;
}
static void F_131 ( struct V_5 * V_6 )
{
void T_3 * V_101 = F_38 ( V_6 ) ;
int V_7 ;
T_2 V_79 , V_310 ;
V_79 = F_33 ( F_54 ( V_6 ) + V_102 ) ;
F_52 ( V_79 , F_54 ( V_6 ) + V_102 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_244 ; ++ V_7 )
F_83 ( V_6 , V_7 ) ;
if ( V_6 -> V_311 == V_312 ) {
V_79 = F_33 ( V_101 + V_313 ) ;
V_310 = ( V_79 >> V_314 ) & V_315 ;
V_79 = F_33 ( V_101 + V_316 ) ;
if ( V_310 >= 2 )
V_79 &= ~ V_317 ;
V_79 |= V_318 ;
F_32 ( V_79 , V_101 + V_316 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_200 ; ++ V_7 ) {
void T_3 * V_90 = F_42 ( V_6 , V_7 ) ;
F_56 ( V_6 , V_7 ) ;
F_32 ( V_92 , V_90 + V_91 ) ;
if ( V_6 -> V_311 == V_312 ) {
V_79 = F_33 ( V_90 + V_319 ) ;
V_79 &= ~ V_320 ;
F_32 ( V_79 , V_90 + V_319 ) ;
}
}
F_32 ( 0 , V_101 + V_321 ) ;
F_32 ( 0 , V_101 + V_322 ) ;
V_79 = F_33 ( F_54 ( V_6 ) + V_323 ) ;
V_79 |= ( V_324 | V_325 | V_326 | V_327 ) ;
V_79 |= ( V_328 | V_329 ) ;
V_79 &= ~ V_330 ;
if ( V_331 )
V_79 |= V_332 ;
else
V_79 &= ~ V_332 ;
V_79 &= ~ V_333 ;
V_79 &= ~ ( V_334 << V_335 ) ;
if ( V_6 -> V_131 & V_132 )
V_79 |= V_336 ;
if ( V_6 -> V_131 & V_227 )
V_79 |= V_337 ;
F_37 ( V_6 ) ;
F_52 ( V_79 , F_54 ( V_6 ) + V_323 ) ;
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
T_2 V_223 ;
bool V_338 , V_339 = V_6 -> V_131 & V_206 ;
int V_7 ;
F_5 ( V_6 -> V_8 , L_18 ) ;
F_5 ( V_6 -> V_8 , L_19 ,
V_6 -> V_127 == V_134 ? 2 : 1 ) ;
V_223 = F_33 ( V_101 + V_340 ) ;
if ( V_341 == 1 )
V_223 &= ~ ( V_342 | V_343 ) ;
else if ( V_341 == 2 )
V_223 &= ~ ( V_344 | V_343 ) ;
if ( V_223 & V_344 ) {
V_6 -> V_131 |= V_170 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_223 & V_342 ) {
V_6 -> V_131 |= V_172 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_223 & V_343 ) {
V_6 -> V_131 |= V_345 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( ! ( V_6 -> V_131 &
( V_170 | V_172 ) ) ) {
F_67 ( V_6 -> V_8 , L_23 ) ;
return - V_34 ;
}
if ( ( V_223 & V_344 ) &&
( ( V_6 -> V_127 < V_134 ) || ! ( V_223 & V_346 ) ) ) {
V_6 -> V_131 |= V_279 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
V_338 = ! ! ( V_223 & V_347 ) ;
if ( V_339 || V_338 )
F_5 ( V_6 -> V_8 , L_25 ,
V_339 ? L_26 : L_27 ) ;
if ( V_339 != V_338 )
F_5 ( V_6 -> V_8 ,
L_28 ) ;
if ( V_6 -> V_127 == V_134 && V_223 & V_348 ) {
V_6 -> V_131 |= V_227 ;
V_73 = 1 << 16 ;
} else {
V_73 = 1 << ( ( V_223 >> V_349 ) & V_350 ) ;
}
V_6 -> V_241 = V_73 - 1 ;
if ( V_223 & V_351 ) {
V_6 -> V_131 |= V_352 ;
V_73 = ( V_223 >> V_353 ) & V_354 ;
if ( V_73 == 0 ) {
F_67 ( V_6 -> V_8 ,
L_29 ) ;
return - V_34 ;
}
V_6 -> V_222 = F_134 ( V_6 -> V_8 , V_73 , sizeof( * V_6 -> V_222 ) ,
V_41 ) ;
if ( ! V_6 -> V_222 )
return - V_42 ;
F_5 ( V_6 -> V_8 ,
L_30 , V_73 ) ;
}
V_6 -> V_232 = F_135 ( V_6 -> V_8 , V_73 , sizeof( * V_6 -> V_232 ) ,
V_41 ) ;
if ( ! V_6 -> V_232 )
return - V_42 ;
for ( V_7 = 0 ; V_7 < V_73 ; V_7 ++ )
V_6 -> V_232 [ V_7 ] = V_246 ;
V_6 -> V_244 = V_73 ;
F_75 ( & V_6 -> V_253 ) ;
F_76 ( & V_6 -> V_57 ) ;
if ( V_6 -> V_127 < V_134 || ! ( V_223 & V_355 ) ) {
V_6 -> V_131 |= V_174 ;
if ( ! ( V_223 & V_356 ) )
V_6 -> V_131 |= V_179 ;
}
V_223 = F_33 ( V_101 + V_357 ) ;
V_6 -> V_358 = ( V_223 & V_359 ) ? 16 : 12 ;
V_73 = 1 << ( ( ( V_223 >> V_360 ) & V_361 ) + 1 ) ;
V_73 <<= V_6 -> V_358 ;
if ( V_6 -> V_90 != V_101 + V_73 )
F_136 ( V_6 -> V_8 ,
L_31 ,
V_73 * 2 , ( V_6 -> V_90 - V_101 ) * 2 ) ;
V_6 -> V_186 = ( V_223 >> V_362 ) & V_363 ;
V_6 -> V_200 = ( V_223 >> V_364 ) & V_365 ;
if ( V_6 -> V_186 > V_6 -> V_200 ) {
F_67 ( V_6 -> V_8 , L_32 ) ;
return - V_34 ;
}
F_5 ( V_6 -> V_8 , L_33 ,
V_6 -> V_200 , V_6 -> V_186 ) ;
if ( V_6 -> V_311 == V_366 ) {
V_6 -> V_202 =
F_137 ( V_6 -> V_200 ,
& V_367 ) ;
V_6 -> V_202 -= V_6 -> V_200 ;
F_5 ( V_6 -> V_8 , L_34 ) ;
}
V_6 -> V_110 = F_134 ( V_6 -> V_8 , V_6 -> V_200 ,
sizeof( * V_6 -> V_110 ) , V_41 ) ;
if ( ! V_6 -> V_110 )
return - V_42 ;
V_223 = F_33 ( V_101 + V_368 ) ;
V_73 = F_132 ( ( V_223 >> V_369 ) & V_370 ) ;
V_6 -> V_188 = V_73 ;
V_73 = F_132 ( ( V_223 >> V_371 ) & V_372 ) ;
V_6 -> V_194 = V_73 ;
if ( V_223 & V_373 )
V_6 -> V_131 |= V_132 ;
if ( F_138 ( V_6 -> V_8 , F_139 ( V_73 ) ) )
F_136 ( V_6 -> V_8 ,
L_35 ) ;
if ( V_6 -> V_127 < V_134 ) {
V_6 -> V_187 = V_6 -> V_188 ;
if ( V_6 -> V_127 == V_374 )
V_6 -> V_131 |= V_181 ;
} else {
V_73 = ( V_223 >> V_375 ) & V_376 ;
V_6 -> V_187 = F_132 ( V_73 ) ;
if ( V_223 & V_377 )
V_6 -> V_131 |= V_183 ;
if ( V_223 & V_378 )
V_6 -> V_131 |= V_182 ;
if ( V_223 & V_379 )
V_6 -> V_131 |= V_181 ;
}
if ( V_6 -> V_131 & V_179 )
V_6 -> V_203 |= V_380 | V_381 | V_382 | V_383 ;
if ( V_6 -> V_131 &
( V_174 | V_183 ) )
V_6 -> V_203 |= V_380 | V_384 | V_385 ;
if ( V_6 -> V_131 & V_182 )
V_6 -> V_203 |= V_386 | V_387 ;
if ( V_6 -> V_131 & V_181 )
V_6 -> V_203 |= V_381 | V_388 ;
if ( V_40 . V_203 == - 1UL )
V_40 . V_203 = V_6 -> V_203 ;
else
V_40 . V_203 |= V_6 -> V_203 ;
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_203 ) ;
if ( V_6 -> V_131 & V_170 )
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_187 , V_6 -> V_188 ) ;
if ( V_6 -> V_131 & V_172 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_188 , V_6 -> V_194 ) ;
return 0 ;
}
static int F_140 ( T_2 V_311 , struct V_5 * V_6 )
{
int V_157 = 0 ;
switch ( V_311 ) {
case V_389 :
case V_390 :
V_6 -> V_127 = V_128 ;
V_6 -> V_311 = V_391 ;
break;
case V_392 :
V_6 -> V_127 = V_374 ;
V_6 -> V_311 = V_391 ;
break;
case V_393 :
V_6 -> V_127 = V_134 ;
V_6 -> V_311 = V_391 ;
break;
case V_394 :
V_6 -> V_127 = V_134 ;
V_6 -> V_311 = V_312 ;
break;
case V_395 :
V_6 -> V_127 = V_134 ;
V_6 -> V_311 = V_366 ;
break;
default:
V_157 = - V_34 ;
}
return V_157 ;
}
static int F_141 ( struct V_396 * V_21 ,
struct V_5 * V_6 )
{
struct V_15 * V_8 = V_6 -> V_8 ;
struct V_397 * V_28 =
* (struct V_397 * * ) F_142 ( V_8 ) ;
struct V_398 * V_399 ;
int V_157 ;
V_399 = (struct V_398 * ) V_28 -> V_400 ;
V_157 = F_140 ( V_399 -> V_311 , V_6 ) ;
if ( V_157 < 0 )
return V_157 ;
V_6 -> V_214 = 1 ;
if ( V_399 -> V_56 & V_401 )
V_6 -> V_131 |= V_206 ;
return 0 ;
}
static inline int F_141 ( struct V_396 * V_21 ,
struct V_5 * V_6 )
{
return - V_34 ;
}
static int F_143 ( struct V_396 * V_21 ,
struct V_5 * V_6 )
{
const struct V_402 * V_23 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
bool V_403 ;
if ( F_124 ( V_8 -> V_9 , L_39 ,
& V_6 -> V_214 ) ) {
F_67 ( V_8 , L_40 ) ;
return - V_34 ;
}
V_23 = F_144 ( V_8 ) ;
V_6 -> V_127 = V_23 -> V_127 ;
V_6 -> V_311 = V_23 -> V_311 ;
F_3 ( V_6 ) ;
V_403 = F_16 ( V_8 -> V_9 , L_2 , NULL ) ;
if ( V_403 && ! V_404 ) {
if ( ! V_219 )
F_145 ( L_41 ) ;
V_219 = true ;
} else if ( ! V_403 && ! V_219 ) {
V_404 = true ;
} else {
F_67 ( V_8 , L_42 ) ;
return - V_34 ;
}
if ( F_146 ( V_8 -> V_9 ) )
V_6 -> V_131 |= V_206 ;
return 0 ;
}
static void F_147 ( void )
{
if ( ! F_148 ( & V_405 ) )
F_149 ( & V_405 , & V_40 ) ;
#ifdef F_150
if ( ! F_148 ( & V_406 ) )
F_149 ( & V_406 , & V_40 ) ;
#endif
#ifdef F_151
if ( ! F_148 ( & V_407 ) ) {
F_152 () ;
F_149 ( & V_407 , & V_40 ) ;
}
#endif
}
static int F_153 ( struct V_396 * V_21 )
{
struct V_408 * V_409 ;
T_9 V_410 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
int V_411 , V_7 , V_29 ;
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
V_409 = F_155 ( V_21 , V_412 , 0 ) ;
V_410 = V_409 -> V_44 ;
V_6 -> V_55 = F_156 ( V_8 , V_409 ) ;
if ( F_91 ( V_6 -> V_55 ) )
return F_92 ( V_6 -> V_55 ) ;
V_6 -> V_90 = V_6 -> V_55 + F_157 ( V_409 ) / 2 ;
V_411 = 0 ;
while ( ( V_409 = F_155 ( V_21 , V_413 , V_411 ) ) ) {
V_411 ++ ;
if ( V_411 > V_6 -> V_214 )
V_6 -> V_201 ++ ;
}
if ( ! V_6 -> V_201 ) {
F_67 ( V_8 , L_44 ,
V_411 , V_6 -> V_214 + 1 ) ;
return - V_34 ;
}
V_6 -> V_213 = F_154 ( V_8 , sizeof( * V_6 -> V_213 ) * V_411 ,
V_41 ) ;
if ( ! V_6 -> V_213 ) {
F_67 ( V_8 , L_45 , V_411 ) ;
return - V_42 ;
}
for ( V_7 = 0 ; V_7 < V_411 ; ++ V_7 ) {
int V_87 = F_158 ( V_21 , V_7 ) ;
if ( V_87 < 0 ) {
F_67 ( V_8 , L_46 , V_7 ) ;
return - V_34 ;
}
V_6 -> V_213 [ V_7 ] = V_87 ;
}
V_29 = F_133 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_127 == V_134 &&
V_6 -> V_200 != V_6 -> V_201 ) {
F_67 ( V_8 ,
L_47 ,
V_6 -> V_201 , V_6 -> V_200 ) ;
return - V_34 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_214 ; ++ V_7 ) {
V_29 = F_66 ( V_6 -> V_8 , V_6 -> V_213 [ V_7 ] ,
F_53 ,
V_215 ,
L_48 ,
V_6 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_49 ,
V_7 , V_6 -> V_213 [ V_7 ] ) ;
return V_29 ;
}
}
V_29 = F_159 ( & V_6 -> V_289 , V_6 -> V_8 , NULL ,
L_50 , & V_410 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_51 ) ;
return V_29 ;
}
F_160 ( & V_6 -> V_289 , & V_40 ) ;
F_161 ( & V_6 -> V_289 , V_8 -> V_39 ) ;
V_29 = F_162 ( & V_6 -> V_289 ) ;
if ( V_29 ) {
F_67 ( V_8 , L_52 ) ;
return V_29 ;
}
F_163 ( V_21 , V_6 ) ;
F_131 ( V_6 ) ;
F_84 ( V_6 ) ;
if ( ! V_219 )
F_147 () ;
return 0 ;
}
static int F_164 ( void )
{
if ( V_219 )
F_147 () ;
return 0 ;
}
static int F_165 ( struct V_396 * V_21 )
{
struct V_5 * V_6 = F_166 ( V_21 ) ;
if ( ! V_6 )
return - V_34 ;
if ( ! F_167 ( V_6 -> V_199 , V_414 ) )
F_67 ( & V_21 -> V_8 , L_53 ) ;
F_52 ( V_330 , F_54 ( V_6 ) + V_323 ) ;
return 0 ;
}
static void F_168 ( struct V_396 * V_21 )
{
F_165 ( V_21 ) ;
}
static int T_10 F_169 ( struct V_15 * V_8 )
{
struct V_5 * V_6 = F_22 ( V_8 ) ;
F_131 ( V_6 ) ;
return 0 ;
}
