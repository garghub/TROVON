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
F_31 ( V_6 , V_55 + V_56 ,
V_55 + V_57 ) ;
}
static void F_39 ( void * V_58 )
{
struct V_1 * V_59 = V_58 ;
struct V_5 * V_6 = V_59 -> V_6 ;
void T_3 * V_55 = F_40 ( V_6 , V_59 -> V_60 . V_61 ) ;
F_31 ( V_6 , V_55 + V_62 ,
V_55 + V_63 ) ;
}
static void F_41 ( void * V_58 )
{
struct V_1 * V_59 = V_58 ;
F_37 ( V_59 -> V_6 ) ;
}
static void F_42 ( void * V_58 )
{
struct V_1 * V_59 = V_58 ;
struct V_64 * V_60 = & V_59 -> V_60 ;
void T_3 * V_55 = F_40 ( V_59 -> V_6 , V_60 -> V_61 ) ;
F_32 ( V_60 -> V_65 , V_55 + V_66 ) ;
F_39 ( V_58 ) ;
}
static void F_43 ( void * V_58 )
{
struct V_1 * V_59 = V_58 ;
struct V_5 * V_6 = V_59 -> V_6 ;
void T_3 * V_55 = F_38 ( V_6 ) ;
F_32 ( V_59 -> V_60 . V_67 , V_55 + V_68 ) ;
F_37 ( V_6 ) ;
}
static void F_44 ( unsigned long V_69 , T_4 V_70 ,
T_4 V_71 , bool V_72 , void * V_58 )
{
struct V_1 * V_59 = V_58 ;
struct V_64 * V_60 = & V_59 -> V_60 ;
bool V_73 = V_60 -> V_74 != V_75 ;
void T_3 * V_76 = F_40 ( V_59 -> V_6 , V_60 -> V_61 ) ;
if ( V_73 ) {
V_76 += V_72 ? V_77 : V_78 ;
if ( V_60 -> V_79 != V_80 ) {
V_69 &= ~ 12UL ;
V_69 |= V_60 -> V_65 ;
do {
F_32 ( V_69 , V_76 ) ;
V_69 += V_71 ;
} while ( V_70 -= V_71 );
} else {
V_69 >>= 12 ;
V_69 |= ( V_81 ) V_60 -> V_65 << 48 ;
do {
F_45 ( V_69 , V_76 ) ;
V_69 += V_71 >> 12 ;
} while ( V_70 -= V_71 );
}
} else {
V_76 += V_72 ? V_82 :
V_83 ;
V_69 >>= 12 ;
do {
F_46 ( V_69 , V_76 ) ;
V_69 += V_71 >> 12 ;
} while ( V_70 -= V_71 );
}
}
static void F_47 ( unsigned long V_69 , T_4 V_70 ,
T_4 V_71 , bool V_72 , void * V_58 )
{
struct V_1 * V_59 = V_58 ;
void T_3 * V_55 = F_38 ( V_59 -> V_6 ) ;
F_32 ( V_59 -> V_60 . V_67 , V_55 + V_68 ) ;
}
static T_5 F_48 ( int V_84 , void * V_8 )
{
T_2 V_85 , V_86 ;
unsigned long V_69 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_64 * V_60 = & V_59 -> V_60 ;
struct V_5 * V_6 = V_59 -> V_6 ;
void T_3 * V_87 ;
V_87 = F_40 ( V_6 , V_60 -> V_61 ) ;
V_85 = F_33 ( V_87 + V_88 ) ;
if ( ! ( V_85 & V_89 ) )
return V_90 ;
V_86 = F_33 ( V_87 + V_91 ) ;
V_69 = F_49 ( V_87 + V_92 ) ;
F_36 ( V_6 -> V_8 ,
L_5 ,
V_85 , V_69 , V_86 , V_60 -> V_61 ) ;
F_50 ( V_85 , V_87 + V_88 ) ;
return V_93 ;
}
static T_5 F_51 ( int V_84 , void * V_8 )
{
T_2 V_94 , V_95 , V_96 , V_97 ;
struct V_5 * V_6 = V_8 ;
void T_3 * V_98 = F_52 ( V_6 ) ;
V_94 = F_33 ( V_98 + V_99 ) ;
V_95 = F_33 ( V_98 + V_100 ) ;
V_96 = F_33 ( V_98 + V_101 ) ;
V_97 = F_33 ( V_98 + V_102 ) ;
if ( ! V_94 )
return V_90 ;
F_36 ( V_6 -> V_8 ,
L_6 ) ;
F_36 ( V_6 -> V_8 ,
L_7 ,
V_94 , V_95 , V_96 , V_97 ) ;
F_50 ( V_94 , V_98 + V_99 ) ;
return V_93 ;
}
static void F_53 ( struct V_1 * V_59 ,
struct V_103 * V_104 )
{
T_2 V_76 , V_105 ;
V_81 V_106 ;
bool V_73 ;
struct V_64 * V_60 = & V_59 -> V_60 ;
struct V_5 * V_6 = V_59 -> V_6 ;
void T_3 * V_87 , * V_107 ;
V_107 = F_54 ( V_6 ) ;
V_73 = V_60 -> V_74 != V_75 ;
V_87 = F_40 ( V_6 , V_60 -> V_61 ) ;
if ( V_6 -> V_108 > V_109 ) {
if ( V_60 -> V_79 == V_80 )
V_76 = V_110 ;
else
V_76 = V_111 ;
if ( V_6 -> V_112 & V_113 )
V_76 |= V_60 -> V_67 << V_114 ;
F_32 ( V_76 , V_107 + F_55 ( V_60 -> V_61 ) ) ;
}
V_76 = V_60 -> V_74 ;
if ( V_6 -> V_108 < V_115 )
V_76 |= V_60 -> V_116 << V_117 ;
if ( V_73 ) {
V_76 |= ( V_118 << V_119 ) |
( V_120 << V_121 ) ;
} else if ( ! ( V_6 -> V_112 & V_113 ) ) {
V_76 |= V_60 -> V_67 << V_122 ;
}
F_32 ( V_76 , V_107 + F_56 ( V_60 -> V_61 ) ) ;
if ( V_73 ) {
if ( V_60 -> V_79 == V_123 ) {
V_76 = V_104 -> V_124 . V_125 ;
V_105 = 0 ;
} else {
V_76 = V_104 -> V_126 . V_125 ;
V_105 = V_104 -> V_126 . V_125 >> 32 ;
V_105 |= V_127 ;
if ( V_60 -> V_79 == V_80 )
V_105 |= V_128 ;
}
if ( V_6 -> V_108 > V_109 )
F_32 ( V_105 , V_87 + V_129 ) ;
} else {
V_76 = V_104 -> V_130 . V_131 ;
}
F_32 ( V_76 , V_87 + V_132 ) ;
if ( V_73 ) {
if ( V_60 -> V_79 == V_123 ) {
V_76 = V_104 -> V_124 . V_133 [ 0 ] ;
F_32 ( V_76 , V_87 + V_134 ) ;
V_76 = V_104 -> V_124 . V_133 [ 1 ] ;
F_32 ( V_76 , V_87 + V_135 ) ;
F_32 ( V_60 -> V_65 , V_87 + V_136 ) ;
} else {
V_106 = V_104 -> V_126 . V_133 [ 0 ] ;
V_106 |= ( V_81 ) V_60 -> V_65 << V_137 ;
F_45 ( V_106 , V_87 + V_134 ) ;
V_106 = V_104 -> V_126 . V_133 [ 1 ] ;
V_106 |= ( V_81 ) V_60 -> V_65 << V_137 ;
F_45 ( V_106 , V_87 + V_135 ) ;
}
} else {
V_106 = V_104 -> V_130 . V_138 ;
F_45 ( V_106 , V_87 + V_134 ) ;
}
if ( V_73 ) {
if ( V_60 -> V_79 == V_123 ) {
V_76 = V_104 -> V_124 . V_139 ;
V_105 = V_104 -> V_124 . V_140 ;
} else {
V_76 = V_104 -> V_126 . V_141 [ 0 ] ;
V_105 = V_104 -> V_126 . V_141 [ 1 ] ;
}
F_32 ( V_76 , V_87 + V_142 ) ;
F_32 ( V_105 , V_87 + V_143 ) ;
}
V_76 = V_144 | V_145 | V_146 | V_147 | V_148 ;
if ( V_73 )
V_76 |= V_149 ;
#ifdef F_57
V_76 |= V_150 ;
#endif
F_32 ( V_76 , V_87 + V_151 ) ;
}
static int F_58 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_84 , V_44 , V_152 = 0 ;
unsigned long V_153 , V_154 ;
struct V_155 * V_156 ;
struct V_103 V_104 ;
enum V_157 V_79 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_64 * V_60 = & V_59 -> V_60 ;
const struct V_158 * V_159 ;
F_59 ( & V_59 -> V_160 ) ;
if ( V_59 -> V_6 )
goto V_161;
if ( V_4 -> type == V_162 ) {
V_59 -> V_163 = V_164 ;
V_59 -> V_6 = V_6 ;
goto V_161;
}
if ( ! ( V_6 -> V_112 & V_165 ) )
V_59 -> V_163 = V_166 ;
if ( ! ( V_6 -> V_112 & V_167 ) )
V_59 -> V_163 = V_168 ;
if ( V_6 -> V_112 & V_169 )
V_60 -> V_79 = V_170 ;
if ( F_60 ( V_171 ) &&
! F_60 ( V_172 ) && ! F_60 ( V_173 ) &&
( V_6 -> V_112 & V_174 ) &&
( V_59 -> V_163 == V_168 ) )
V_60 -> V_79 = V_123 ;
if ( ( F_60 ( V_172 ) || V_60 -> V_79 == V_175 ) &&
( V_6 -> V_112 & ( V_176 |
V_177 |
V_178 ) ) )
V_60 -> V_79 = V_80 ;
if ( V_60 -> V_79 == V_175 ) {
V_152 = - V_179 ;
goto V_161;
}
switch ( V_59 -> V_163 ) {
case V_168 :
V_60 -> V_74 = V_180 ;
V_44 = V_6 -> V_181 ;
V_153 = V_6 -> V_182 ;
V_154 = V_6 -> V_183 ;
if ( V_60 -> V_79 == V_80 ) {
V_79 = V_184 ;
} else if ( V_60 -> V_79 == V_170 ) {
V_79 = V_185 ;
V_153 = F_61 ( V_153 , 32UL ) ;
V_154 = F_61 ( V_154 , 40UL ) ;
} else {
V_79 = V_186 ;
V_153 = F_61 ( V_153 , 32UL ) ;
V_154 = F_61 ( V_154 , 32UL ) ;
}
V_159 = & V_187 ;
break;
case V_188 :
case V_166 :
V_60 -> V_74 = V_75 ;
V_44 = 0 ;
V_153 = V_6 -> V_183 ;
V_154 = V_6 -> V_189 ;
if ( V_60 -> V_79 == V_80 ) {
V_79 = V_190 ;
} else {
V_79 = V_191 ;
V_153 = F_61 ( V_153 , 40UL ) ;
V_154 = F_61 ( V_154 , 40UL ) ;
}
if ( V_6 -> V_108 == V_115 )
V_159 = & V_192 ;
else
V_159 = & V_193 ;
break;
default:
V_152 = - V_179 ;
goto V_161;
}
V_152 = F_26 ( V_6 -> V_194 , V_44 ,
V_6 -> V_195 ) ;
if ( V_152 < 0 )
goto V_161;
V_60 -> V_61 = V_152 ;
if ( V_6 -> V_108 < V_115 ) {
V_60 -> V_116 = F_62 ( & V_6 -> V_116 ) ;
V_60 -> V_116 %= V_6 -> V_196 ;
} else {
V_60 -> V_116 = V_60 -> V_61 ;
}
if ( V_59 -> V_163 == V_166 )
V_60 -> V_67 = V_60 -> V_61 + 1 + V_6 -> V_197 ;
else
V_60 -> V_65 = V_60 -> V_61 + V_6 -> V_197 ;
V_104 = (struct V_103 ) {
. V_198 = V_6 -> V_198 ,
. V_153 = V_153 ,
. V_154 = V_154 ,
. V_199 = V_159 ,
. V_200 = V_6 -> V_8 ,
} ;
V_59 -> V_6 = V_6 ;
V_156 = F_63 ( V_79 , & V_104 , V_59 ) ;
if ( ! V_156 ) {
V_152 = - V_42 ;
goto V_201;
}
V_4 -> V_198 = V_104 . V_198 ;
V_4 -> V_202 . V_203 = ( 1UL << V_153 ) - 1 ;
V_4 -> V_202 . V_204 = true ;
F_53 ( V_59 , & V_104 ) ;
V_84 = V_6 -> V_205 [ V_6 -> V_206 + V_60 -> V_116 ] ;
V_152 = F_64 ( V_6 -> V_8 , V_84 , F_48 ,
V_207 , L_8 , V_4 ) ;
if ( V_152 < 0 ) {
F_65 ( V_6 -> V_8 , L_9 ,
V_60 -> V_116 , V_84 ) ;
V_60 -> V_116 = V_208 ;
}
F_66 ( & V_59 -> V_160 ) ;
V_59 -> V_156 = V_156 ;
return 0 ;
V_201:
V_59 -> V_6 = NULL ;
V_161:
F_66 ( & V_59 -> V_160 ) ;
return V_152 ;
}
static void F_67 ( struct V_2 * V_4 )
{
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_59 -> V_6 ;
struct V_64 * V_60 = & V_59 -> V_60 ;
void T_3 * V_87 ;
int V_84 ;
if ( ! V_6 || V_4 -> type == V_162 )
return;
V_87 = F_40 ( V_6 , V_60 -> V_61 ) ;
F_32 ( 0 , V_87 + V_151 ) ;
if ( V_60 -> V_116 != V_208 ) {
V_84 = V_6 -> V_205 [ V_6 -> V_206 + V_60 -> V_116 ] ;
F_68 ( V_6 -> V_8 , V_84 , V_4 ) ;
}
F_69 ( V_59 -> V_156 ) ;
F_29 ( V_6 -> V_194 , V_60 -> V_61 ) ;
}
static struct V_2 * F_70 ( unsigned type )
{
struct V_1 * V_59 ;
if ( type != V_209 &&
type != V_210 &&
type != V_162 )
return NULL ;
V_59 = F_71 ( sizeof( * V_59 ) , V_41 ) ;
if ( ! V_59 )
return NULL ;
if ( type == V_210 && ( V_211 ||
F_72 ( & V_59 -> V_4 ) ) ) {
F_25 ( V_59 ) ;
return NULL ;
}
F_73 ( & V_59 -> V_160 ) ;
F_74 ( & V_59 -> V_212 ) ;
return & V_59 -> V_4 ;
}
static void F_75 ( struct V_2 * V_4 )
{
struct V_1 * V_59 = F_1 ( V_4 ) ;
F_76 ( V_4 ) ;
F_67 ( V_4 ) ;
F_25 ( V_59 ) ;
}
static void F_77 ( struct V_5 * V_6 , int V_46 )
{
struct V_213 * V_214 = V_6 -> V_215 + V_46 ;
T_2 V_76 = V_214 -> V_216 << V_217 | V_214 -> V_218 << V_219 ;
if ( ! ( V_6 -> V_112 & V_220 ) && V_214 -> V_221 )
V_76 |= V_222 ;
F_32 ( V_76 , F_38 ( V_6 ) + F_78 ( V_46 ) ) ;
}
static void F_79 ( struct V_5 * V_6 , int V_46 )
{
struct V_223 * V_224 = V_6 -> V_225 + V_46 ;
T_2 V_76 = ( V_224 -> type & V_226 ) << V_227 |
( V_224 -> V_61 & V_228 ) << V_229 |
( V_224 -> V_230 & V_231 ) << V_232 ;
if ( V_6 -> V_112 & V_220 && V_6 -> V_215 &&
V_6 -> V_215 [ V_46 ] . V_221 )
V_76 |= V_233 ;
F_32 ( V_76 , F_38 ( V_6 ) + F_80 ( V_46 ) ) ;
}
static void F_81 ( struct V_5 * V_6 , int V_46 )
{
F_79 ( V_6 , V_46 ) ;
if ( V_6 -> V_215 )
F_77 ( V_6 , V_46 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
void T_3 * V_98 = F_38 ( V_6 ) ;
T_2 V_214 ;
if ( ! V_6 -> V_215 )
return;
V_214 = V_6 -> V_234 << V_217 ;
F_32 ( V_214 , V_98 + F_78 ( 0 ) ) ;
V_214 = F_33 ( V_98 + F_78 ( 0 ) ) ;
V_6 -> V_234 = V_214 >> V_217 ;
V_214 = V_6 -> V_234 << V_219 ;
F_32 ( V_214 , V_98 + F_78 ( 0 ) ) ;
V_214 = F_33 ( V_98 + F_78 ( 0 ) ) ;
V_6 -> V_235 = V_214 >> V_219 ;
}
static int F_83 ( struct V_5 * V_6 , T_1 V_216 , T_1 V_218 )
{
struct V_213 * V_215 = V_6 -> V_215 ;
int V_7 , V_236 = - V_47 ;
if ( ! V_215 )
return V_216 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_237 ; ++ V_7 ) {
if ( ! V_215 [ V_7 ] . V_221 ) {
if ( V_236 < 0 )
V_236 = V_7 ;
continue;
}
if ( ( V_218 & V_215 [ V_7 ] . V_218 ) == V_218 &&
! ( ( V_216 ^ V_215 [ V_7 ] . V_216 ) & ~ V_215 [ V_7 ] . V_218 ) )
return V_7 ;
if ( ! ( ( V_216 ^ V_215 [ V_7 ] . V_216 ) & ~ ( V_215 [ V_7 ] . V_218 | V_218 ) ) )
return - V_179 ;
}
return V_236 ;
}
static bool F_84 ( struct V_5 * V_6 , int V_46 )
{
if ( -- V_6 -> V_225 [ V_46 ] . V_238 )
return false ;
V_6 -> V_225 [ V_46 ] = V_239 ;
if ( V_6 -> V_215 )
V_6 -> V_215 [ V_46 ] . V_221 = false ;
return true ;
}
static int F_85 ( struct V_15 * V_8 )
{
struct V_240 * V_241 = V_8 -> V_240 ;
struct V_242 * V_60 = V_241 -> V_243 ;
struct V_5 * V_6 = V_60 -> V_6 ;
struct V_213 * V_215 = V_6 -> V_215 ;
struct V_244 * V_245 ;
int V_7 , V_46 , V_152 ;
F_59 ( & V_6 -> V_246 ) ;
F_86 (fwspec, i, idx) {
T_1 V_247 = V_241 -> V_248 [ V_7 ] ;
T_1 V_218 = V_241 -> V_248 [ V_7 ] >> V_219 ;
if ( V_46 != V_249 ) {
V_152 = - V_250 ;
goto V_251;
}
V_152 = F_83 ( V_6 , V_247 , V_218 ) ;
if ( V_152 < 0 )
goto V_251;
V_46 = V_152 ;
if ( V_215 && V_6 -> V_225 [ V_46 ] . V_238 == 0 ) {
V_215 [ V_46 ] . V_216 = V_247 ;
V_215 [ V_46 ] . V_218 = V_218 ;
V_215 [ V_46 ] . V_221 = true ;
}
V_6 -> V_225 [ V_46 ] . V_238 ++ ;
V_60 -> V_252 [ V_7 ] = ( V_253 ) V_46 ;
}
V_245 = F_87 ( V_8 ) ;
if ( ! V_245 )
V_245 = F_88 ( - V_42 ) ;
if ( F_89 ( V_245 ) ) {
V_152 = F_90 ( V_245 ) ;
goto V_251;
}
F_91 ( V_245 ) ;
F_86 (fwspec, i, idx) {
F_81 ( V_6 , V_46 ) ;
V_6 -> V_225 [ V_46 ] . V_245 = V_245 ;
}
F_66 ( & V_6 -> V_246 ) ;
return 0 ;
V_251:
while ( V_7 -- ) {
F_84 ( V_6 , V_60 -> V_252 [ V_7 ] ) ;
V_60 -> V_252 [ V_7 ] = V_249 ;
}
F_66 ( & V_6 -> V_246 ) ;
return V_152 ;
}
static void F_92 ( struct V_240 * V_241 )
{
struct V_5 * V_6 = F_93 ( V_241 ) ;
struct V_242 * V_60 = V_241 -> V_243 ;
int V_7 , V_46 ;
F_59 ( & V_6 -> V_246 ) ;
F_86 (fwspec, i, idx) {
if ( F_84 ( V_6 , V_46 ) )
F_81 ( V_6 , V_46 ) ;
V_60 -> V_252 [ V_7 ] = V_249 ;
}
F_66 ( & V_6 -> V_246 ) ;
}
static int F_94 ( struct V_1 * V_59 ,
struct V_240 * V_241 )
{
struct V_5 * V_6 = V_59 -> V_6 ;
struct V_223 * V_224 = V_6 -> V_225 ;
T_6 V_61 = V_59 -> V_60 . V_61 ;
enum V_254 type ;
int V_7 , V_46 ;
if ( V_59 -> V_163 == V_164 )
type = V_255 ;
else
type = V_256 ;
F_86 (fwspec, i, idx) {
if ( type == V_224 [ V_46 ] . type && V_61 == V_224 [ V_46 ] . V_61 )
continue;
V_224 [ V_46 ] . type = type ;
V_224 [ V_46 ] . V_230 = V_257 ;
V_224 [ V_46 ] . V_61 = V_61 ;
F_79 ( V_6 , V_46 ) ;
}
return 0 ;
}
static int F_95 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_152 ;
struct V_240 * V_241 = V_8 -> V_240 ;
struct V_5 * V_6 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
if ( ! V_241 || V_241 -> V_258 != & V_40 ) {
F_65 ( V_8 , L_10 ) ;
return - V_259 ;
}
if ( ! V_241 -> V_243 )
return - V_34 ;
V_6 = F_93 ( V_241 ) ;
V_152 = F_58 ( V_4 , V_6 ) ;
if ( V_152 < 0 )
return V_152 ;
if ( V_59 -> V_6 != V_6 ) {
F_65 ( V_8 ,
L_11 ,
F_96 ( V_59 -> V_6 -> V_8 ) , F_96 ( V_6 -> V_8 ) ) ;
return - V_179 ;
}
return F_94 ( V_59 , V_241 ) ;
}
static int F_97 ( struct V_2 * V_4 , unsigned long V_69 ,
T_7 V_260 , T_4 V_70 , int V_261 )
{
int V_152 ;
unsigned long V_262 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_155 * V_258 = V_59 -> V_156 ;
if ( ! V_258 )
return - V_34 ;
F_98 ( & V_59 -> V_212 , V_262 ) ;
V_152 = V_258 -> V_43 ( V_258 , V_69 , V_260 , V_70 , V_261 ) ;
F_99 ( & V_59 -> V_212 , V_262 ) ;
return V_152 ;
}
static T_4 F_100 ( struct V_2 * V_4 , unsigned long V_69 ,
T_4 V_70 )
{
T_4 V_152 ;
unsigned long V_262 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_155 * V_258 = V_59 -> V_156 ;
if ( ! V_258 )
return 0 ;
F_98 ( & V_59 -> V_212 , V_262 ) ;
V_152 = V_258 -> V_263 ( V_258 , V_69 , V_70 ) ;
F_99 ( & V_59 -> V_212 , V_262 ) ;
return V_152 ;
}
static T_7 F_101 ( struct V_2 * V_4 ,
T_8 V_69 )
{
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_59 -> V_6 ;
struct V_64 * V_60 = & V_59 -> V_60 ;
struct V_155 * V_258 = V_59 -> V_156 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_3 * V_87 ;
T_2 V_264 ;
V_81 V_265 ;
unsigned long V_266 ;
V_87 = F_40 ( V_6 , V_60 -> V_61 ) ;
V_266 = V_69 & ~ 0xfffUL ;
if ( V_6 -> V_108 == V_115 )
F_46 ( V_266 , V_87 + V_267 ) ;
else
F_32 ( V_266 , V_87 + V_267 ) ;
if ( F_102 ( V_87 + V_268 , V_264 ,
! ( V_264 & V_269 ) , 5 , 50 ) ) {
F_65 ( V_8 ,
L_12 ,
& V_69 ) ;
return V_258 -> V_270 ( V_258 , V_69 ) ;
}
V_265 = F_49 ( V_87 + V_271 ) ;
if ( V_265 & V_272 ) {
F_65 ( V_8 , L_13 ) ;
F_65 ( V_8 , L_14 , V_265 ) ;
return 0 ;
}
return ( V_265 & F_103 ( 39 , 12 ) ) | ( V_69 & 0xfff ) ;
}
static T_7 F_104 ( struct V_2 * V_4 ,
T_8 V_69 )
{
T_7 V_152 ;
unsigned long V_262 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
struct V_155 * V_258 = V_59 -> V_156 ;
if ( V_4 -> type == V_162 )
return V_69 ;
if ( ! V_258 )
return 0 ;
F_98 ( & V_59 -> V_212 , V_262 ) ;
if ( V_59 -> V_6 -> V_112 & V_273 &&
V_59 -> V_163 == V_168 ) {
V_152 = F_101 ( V_4 , V_69 ) ;
} else {
V_152 = V_258 -> V_270 ( V_258 , V_69 ) ;
}
F_99 ( & V_59 -> V_212 , V_262 ) ;
return V_152 ;
}
static bool F_105 ( enum V_274 V_275 )
{
switch ( V_275 ) {
case V_276 :
return true ;
case V_277 :
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
struct V_5 * F_107 ( struct V_278 * V_39 )
{
struct V_15 * V_8 = F_108 ( & V_35 . V_36 , NULL ,
V_39 , F_106 ) ;
F_109 ( V_8 ) ;
return V_8 ? F_22 ( V_8 ) : NULL ;
}
static int F_110 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_242 * V_60 ;
struct V_240 * V_241 = V_8 -> V_240 ;
int V_7 , V_152 ;
if ( V_211 ) {
V_152 = F_15 ( V_8 , & V_6 ) ;
V_241 = V_8 -> V_240 ;
if ( V_152 )
goto V_279;
} else if ( V_241 && V_241 -> V_258 == & V_40 ) {
V_6 = F_107 ( V_241 -> V_280 ) ;
} else {
return - V_34 ;
}
V_152 = - V_179 ;
for ( V_7 = 0 ; V_7 < V_241 -> V_281 ; V_7 ++ ) {
T_1 V_247 = V_241 -> V_248 [ V_7 ] ;
T_1 V_218 = V_241 -> V_248 [ V_7 ] >> V_219 ;
if ( V_247 & ~ V_6 -> V_234 ) {
F_65 ( V_8 , L_15 ,
V_247 , V_6 -> V_234 ) ;
goto V_279;
}
if ( V_218 & ~ V_6 -> V_235 ) {
F_65 ( V_8 , L_16 ,
V_218 , V_6 -> V_235 ) ;
goto V_279;
}
}
V_152 = - V_42 ;
V_60 = F_71 ( F_111 ( struct V_242 , V_252 [ V_7 ] ) ,
V_41 ) ;
if ( ! V_60 )
goto V_279;
V_60 -> V_6 = V_6 ;
V_241 -> V_243 = V_60 ;
while ( V_7 -- )
V_60 -> V_252 [ V_7 ] = V_249 ;
V_152 = F_85 ( V_8 ) ;
if ( V_152 )
goto V_279;
F_112 ( & V_6 -> V_282 , V_8 ) ;
return 0 ;
V_279:
if ( V_241 )
F_25 ( V_241 -> V_243 ) ;
F_113 ( V_8 ) ;
return V_152 ;
}
static void F_114 ( struct V_15 * V_8 )
{
struct V_240 * V_241 = V_8 -> V_240 ;
struct V_242 * V_60 ;
struct V_5 * V_6 ;
if ( ! V_241 || V_241 -> V_258 != & V_40 )
return;
V_60 = V_241 -> V_243 ;
V_6 = V_60 -> V_6 ;
F_115 ( & V_6 -> V_282 , V_8 ) ;
F_92 ( V_241 ) ;
F_116 ( V_8 ) ;
F_25 ( V_241 -> V_243 ) ;
F_113 ( V_8 ) ;
}
static struct V_244 * F_117 ( struct V_15 * V_8 )
{
struct V_240 * V_241 = V_8 -> V_240 ;
struct V_5 * V_6 = F_93 ( V_241 ) ;
struct V_244 * V_245 = NULL ;
int V_7 , V_46 ;
F_86 (fwspec, i, idx) {
if ( V_245 && V_6 -> V_225 [ V_46 ] . V_245 &&
V_245 != V_6 -> V_225 [ V_46 ] . V_245 )
return F_88 ( - V_179 ) ;
V_245 = V_6 -> V_225 [ V_46 ] . V_245 ;
}
if ( V_245 )
return F_118 ( V_245 ) ;
if ( F_7 ( V_8 ) )
V_245 = F_119 ( V_8 ) ;
else
V_245 = F_120 ( V_8 ) ;
return V_245 ;
}
static int F_121 ( struct V_2 * V_4 ,
enum V_283 V_284 , void * V_23 )
{
struct V_1 * V_59 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_209 )
return - V_179 ;
switch ( V_284 ) {
case V_285 :
* ( int * ) V_23 = ( V_59 -> V_163 == V_188 ) ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_122 ( struct V_2 * V_4 ,
enum V_283 V_284 , void * V_23 )
{
int V_152 = 0 ;
struct V_1 * V_59 = F_1 ( V_4 ) ;
if ( V_4 -> type != V_209 )
return - V_179 ;
F_59 ( & V_59 -> V_160 ) ;
switch ( V_284 ) {
case V_285 :
if ( V_59 -> V_6 ) {
V_152 = - V_286 ;
goto V_161;
}
if ( * ( int * ) V_23 )
V_59 -> V_163 = V_188 ;
else
V_59 -> V_163 = V_168 ;
break;
default:
V_152 = - V_34 ;
}
V_161:
F_66 ( & V_59 -> V_160 ) ;
return V_152 ;
}
static int F_123 ( struct V_15 * V_8 , struct V_287 * args )
{
T_2 V_218 , V_288 = 0 ;
if ( args -> V_289 > 0 )
V_288 |= ( T_1 ) args -> args [ 0 ] ;
if ( args -> V_289 > 1 )
V_288 |= ( T_1 ) args -> args [ 1 ] << V_219 ;
else if ( ! F_124 ( args -> V_27 , L_17 , & V_218 ) )
V_288 |= ( T_1 ) V_218 << V_219 ;
return F_24 ( V_8 , & V_288 , 1 ) ;
}
static void F_125 ( struct V_15 * V_8 ,
struct V_290 * V_291 )
{
struct V_292 * V_293 ;
int V_261 = V_294 | V_295 | V_296 ;
V_293 = F_126 ( V_297 , V_298 ,
V_261 , V_299 ) ;
if ( ! V_293 )
return;
F_127 ( & V_293 -> V_300 , V_291 ) ;
F_128 ( V_8 , V_291 ) ;
}
static void F_129 ( struct V_15 * V_8 ,
struct V_290 * V_291 )
{
struct V_292 * V_301 , * V_302 ;
F_130 (entry, next, head, list)
F_25 ( V_301 ) ;
}
static void F_131 ( struct V_5 * V_6 )
{
void T_3 * V_98 = F_38 ( V_6 ) ;
void T_3 * V_87 ;
int V_7 ;
T_2 V_76 , V_303 ;
V_76 = F_33 ( F_52 ( V_6 ) + V_99 ) ;
F_50 ( V_76 , F_52 ( V_6 ) + V_99 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_237 ; ++ V_7 )
F_81 ( V_6 , V_7 ) ;
if ( V_6 -> V_304 == V_305 ) {
V_76 = F_33 ( V_98 + V_306 ) ;
V_303 = ( V_76 >> V_307 ) & V_308 ;
V_76 = F_33 ( V_98 + V_309 ) ;
if ( V_303 >= 2 )
V_76 &= ~ V_310 ;
V_76 |= V_311 ;
F_32 ( V_76 , V_98 + V_309 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_195 ; ++ V_7 ) {
V_87 = F_40 ( V_6 , V_7 ) ;
F_32 ( 0 , V_87 + V_151 ) ;
F_32 ( V_89 , V_87 + V_88 ) ;
if ( V_6 -> V_304 == V_305 ) {
V_76 = F_33 ( V_87 + V_312 ) ;
V_76 &= ~ V_313 ;
F_32 ( V_76 , V_87 + V_312 ) ;
}
}
F_32 ( 0 , V_98 + V_314 ) ;
F_32 ( 0 , V_98 + V_315 ) ;
V_76 = F_33 ( F_52 ( V_6 ) + V_316 ) ;
V_76 |= ( V_317 | V_318 | V_319 | V_320 ) ;
V_76 |= ( V_321 | V_322 ) ;
V_76 &= ~ V_323 ;
if ( V_324 )
V_76 |= V_325 ;
else
V_76 &= ~ V_325 ;
V_76 &= ~ V_326 ;
V_76 &= ~ ( V_327 << V_328 ) ;
if ( V_6 -> V_112 & V_113 )
V_76 |= V_329 ;
if ( V_6 -> V_112 & V_220 )
V_76 |= V_330 ;
F_37 ( V_6 ) ;
F_50 ( V_76 , F_52 ( V_6 ) + V_316 ) ;
}
static int F_132 ( int V_70 )
{
switch ( V_70 ) {
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
unsigned long V_70 ;
void T_3 * V_98 = F_38 ( V_6 ) ;
T_2 V_216 ;
bool V_331 , V_332 = V_6 -> V_112 & V_333 ;
int V_7 ;
F_5 ( V_6 -> V_8 , L_18 ) ;
F_5 ( V_6 -> V_8 , L_19 ,
V_6 -> V_108 == V_115 ? 2 : 1 ) ;
V_216 = F_33 ( V_98 + V_334 ) ;
if ( V_335 == 1 )
V_216 &= ~ ( V_336 | V_337 ) ;
else if ( V_335 == 2 )
V_216 &= ~ ( V_338 | V_337 ) ;
if ( V_216 & V_338 ) {
V_6 -> V_112 |= V_165 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_216 & V_336 ) {
V_6 -> V_112 |= V_167 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( V_216 & V_337 ) {
V_6 -> V_112 |= V_339 ;
F_5 ( V_6 -> V_8 , L_22 ) ;
}
if ( ! ( V_6 -> V_112 &
( V_165 | V_167 ) ) ) {
F_65 ( V_6 -> V_8 , L_23 ) ;
return - V_34 ;
}
if ( ( V_216 & V_338 ) &&
( ( V_6 -> V_108 < V_115 ) || ! ( V_216 & V_340 ) ) ) {
V_6 -> V_112 |= V_273 ;
F_5 ( V_6 -> V_8 , L_24 ) ;
}
V_331 = ! ! ( V_216 & V_341 ) ;
if ( V_332 || V_331 )
F_5 ( V_6 -> V_8 , L_25 ,
V_332 ? L_26 : L_27 ) ;
if ( V_332 != V_331 )
F_5 ( V_6 -> V_8 ,
L_28 ) ;
if ( V_6 -> V_108 == V_115 && V_216 & V_342 ) {
V_6 -> V_112 |= V_220 ;
V_70 = 1 << 16 ;
} else {
V_70 = 1 << ( ( V_216 >> V_343 ) & V_344 ) ;
}
V_6 -> V_234 = V_70 - 1 ;
if ( V_216 & V_345 ) {
V_6 -> V_112 |= V_346 ;
V_70 = ( V_216 >> V_347 ) & V_348 ;
if ( V_70 == 0 ) {
F_65 ( V_6 -> V_8 ,
L_29 ) ;
return - V_34 ;
}
V_6 -> V_215 = F_134 ( V_6 -> V_8 , V_70 , sizeof( * V_6 -> V_215 ) ,
V_41 ) ;
if ( ! V_6 -> V_215 )
return - V_42 ;
F_5 ( V_6 -> V_8 ,
L_30 , V_70 ) ;
}
V_6 -> V_225 = F_135 ( V_6 -> V_8 , V_70 , sizeof( * V_6 -> V_225 ) ,
V_41 ) ;
if ( ! V_6 -> V_225 )
return - V_42 ;
for ( V_7 = 0 ; V_7 < V_70 ; V_7 ++ )
V_6 -> V_225 [ V_7 ] = V_239 ;
V_6 -> V_237 = V_70 ;
F_73 ( & V_6 -> V_246 ) ;
if ( V_6 -> V_108 < V_115 || ! ( V_216 & V_349 ) ) {
V_6 -> V_112 |= V_169 ;
if ( ! ( V_216 & V_350 ) )
V_6 -> V_112 |= V_174 ;
}
V_216 = F_33 ( V_98 + V_351 ) ;
V_6 -> V_352 = ( V_216 & V_353 ) ? 16 : 12 ;
V_70 = 1 << ( ( ( V_216 >> V_354 ) & V_355 ) + 1 ) ;
V_70 <<= V_6 -> V_352 ;
if ( V_6 -> V_87 != V_98 + V_70 )
F_136 ( V_6 -> V_8 ,
L_31 ,
V_70 * 2 , ( V_6 -> V_87 - V_98 ) * 2 ) ;
V_6 -> V_181 = ( V_216 >> V_356 ) & V_357 ;
V_6 -> V_195 = ( V_216 >> V_358 ) & V_359 ;
if ( V_6 -> V_181 > V_6 -> V_195 ) {
F_65 ( V_6 -> V_8 , L_32 ) ;
return - V_34 ;
}
F_5 ( V_6 -> V_8 , L_33 ,
V_6 -> V_195 , V_6 -> V_181 ) ;
if ( V_6 -> V_304 == V_360 ) {
V_6 -> V_197 =
F_137 ( V_6 -> V_195 ,
& V_361 ) ;
V_6 -> V_197 -= V_6 -> V_195 ;
F_5 ( V_6 -> V_8 , L_34 ) ;
}
V_216 = F_33 ( V_98 + V_362 ) ;
V_70 = F_132 ( ( V_216 >> V_363 ) & V_364 ) ;
V_6 -> V_183 = V_70 ;
V_70 = F_132 ( ( V_216 >> V_365 ) & V_366 ) ;
V_6 -> V_189 = V_70 ;
if ( V_216 & V_367 )
V_6 -> V_112 |= V_113 ;
if ( F_138 ( V_6 -> V_8 , F_139 ( V_70 ) ) )
F_136 ( V_6 -> V_8 ,
L_35 ) ;
if ( V_6 -> V_108 < V_115 ) {
V_6 -> V_182 = V_6 -> V_183 ;
if ( V_6 -> V_108 == V_368 )
V_6 -> V_112 |= V_176 ;
} else {
V_70 = ( V_216 >> V_369 ) & V_370 ;
V_6 -> V_182 = F_132 ( V_70 ) ;
if ( V_216 & V_371 )
V_6 -> V_112 |= V_178 ;
if ( V_216 & V_372 )
V_6 -> V_112 |= V_177 ;
if ( V_216 & V_373 )
V_6 -> V_112 |= V_176 ;
}
if ( V_6 -> V_112 & V_174 )
V_6 -> V_198 |= V_374 | V_375 | V_376 | V_377 ;
if ( V_6 -> V_112 &
( V_169 | V_178 ) )
V_6 -> V_198 |= V_374 | V_378 | V_379 ;
if ( V_6 -> V_112 & V_177 )
V_6 -> V_198 |= V_380 | V_381 ;
if ( V_6 -> V_112 & V_176 )
V_6 -> V_198 |= V_375 | V_382 ;
if ( V_40 . V_198 == - 1UL )
V_40 . V_198 = V_6 -> V_198 ;
else
V_40 . V_198 |= V_6 -> V_198 ;
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_198 ) ;
if ( V_6 -> V_112 & V_165 )
F_5 ( V_6 -> V_8 , L_37 ,
V_6 -> V_182 , V_6 -> V_183 ) ;
if ( V_6 -> V_112 & V_167 )
F_5 ( V_6 -> V_8 , L_38 ,
V_6 -> V_183 , V_6 -> V_189 ) ;
return 0 ;
}
static int F_140 ( T_2 V_304 , struct V_5 * V_6 )
{
int V_152 = 0 ;
switch ( V_304 ) {
case V_383 :
case V_384 :
V_6 -> V_108 = V_109 ;
V_6 -> V_304 = V_385 ;
break;
case V_386 :
V_6 -> V_108 = V_115 ;
V_6 -> V_304 = V_385 ;
break;
case V_387 :
V_6 -> V_108 = V_115 ;
V_6 -> V_304 = V_305 ;
break;
default:
V_152 = - V_34 ;
}
return V_152 ;
}
static int F_141 ( struct V_388 * V_21 ,
struct V_5 * V_6 )
{
struct V_15 * V_8 = V_6 -> V_8 ;
struct V_389 * V_28 =
* (struct V_389 * * ) F_142 ( V_8 ) ;
struct V_390 * V_391 ;
int V_152 ;
V_391 = (struct V_390 * ) V_28 -> V_392 ;
V_152 = F_140 ( V_391 -> V_304 , V_6 ) ;
if ( V_152 < 0 )
return V_152 ;
V_6 -> V_206 = 1 ;
if ( V_391 -> V_262 & V_393 )
V_6 -> V_112 |= V_333 ;
return 0 ;
}
static inline int F_141 ( struct V_388 * V_21 ,
struct V_5 * V_6 )
{
return - V_34 ;
}
static int F_143 ( struct V_388 * V_21 ,
struct V_5 * V_6 )
{
const struct V_394 * V_23 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
bool V_395 ;
if ( F_124 ( V_8 -> V_9 , L_39 ,
& V_6 -> V_206 ) ) {
F_65 ( V_8 , L_40 ) ;
return - V_34 ;
}
V_23 = F_144 ( V_8 ) ;
V_6 -> V_108 = V_23 -> V_108 ;
V_6 -> V_304 = V_23 -> V_304 ;
F_3 ( V_6 ) ;
V_395 = F_16 ( V_8 -> V_9 , L_2 , NULL ) ;
if ( V_395 && ! V_396 ) {
if ( ! V_211 )
F_145 ( L_41 ) ;
V_211 = true ;
} else if ( ! V_395 && ! V_211 ) {
V_396 = true ;
} else {
F_65 ( V_8 , L_42 ) ;
return - V_34 ;
}
if ( F_146 ( V_8 -> V_9 ) )
V_6 -> V_112 |= V_333 ;
return 0 ;
}
static void F_147 ( void )
{
if ( ! F_148 ( & V_397 ) )
F_149 ( & V_397 , & V_40 ) ;
#ifdef F_150
if ( ! F_148 ( & V_398 ) )
F_149 ( & V_398 , & V_40 ) ;
#endif
#ifdef F_151
if ( ! F_148 ( & V_399 ) ) {
F_152 () ;
F_149 ( & V_399 , & V_40 ) ;
}
#endif
}
static int F_153 ( struct V_388 * V_21 )
{
struct V_400 * V_401 ;
T_9 V_402 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
int V_403 , V_7 , V_29 ;
V_6 = F_154 ( V_8 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 ) {
F_65 ( V_8 , L_43 ) ;
return - V_42 ;
}
V_6 -> V_8 = V_8 ;
if ( V_8 -> V_9 )
V_29 = F_143 ( V_21 , V_6 ) ;
else
V_29 = F_141 ( V_21 , V_6 ) ;
if ( V_29 )
return V_29 ;
V_401 = F_155 ( V_21 , V_404 , 0 ) ;
V_402 = V_401 -> V_44 ;
V_6 -> V_55 = F_156 ( V_8 , V_401 ) ;
if ( F_89 ( V_6 -> V_55 ) )
return F_90 ( V_6 -> V_55 ) ;
V_6 -> V_87 = V_6 -> V_55 + F_157 ( V_401 ) / 2 ;
V_403 = 0 ;
while ( ( V_401 = F_155 ( V_21 , V_405 , V_403 ) ) ) {
V_403 ++ ;
if ( V_403 > V_6 -> V_206 )
V_6 -> V_196 ++ ;
}
if ( ! V_6 -> V_196 ) {
F_65 ( V_8 , L_44 ,
V_403 , V_6 -> V_206 + 1 ) ;
return - V_34 ;
}
V_6 -> V_205 = F_154 ( V_8 , sizeof( * V_6 -> V_205 ) * V_403 ,
V_41 ) ;
if ( ! V_6 -> V_205 ) {
F_65 ( V_8 , L_45 , V_403 ) ;
return - V_42 ;
}
for ( V_7 = 0 ; V_7 < V_403 ; ++ V_7 ) {
int V_84 = F_158 ( V_21 , V_7 ) ;
if ( V_84 < 0 ) {
F_65 ( V_8 , L_46 , V_7 ) ;
return - V_34 ;
}
V_6 -> V_205 [ V_7 ] = V_84 ;
}
V_29 = F_133 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_108 == V_115 &&
V_6 -> V_195 != V_6 -> V_196 ) {
F_65 ( V_8 ,
L_47 ,
V_6 -> V_196 , V_6 -> V_195 ) ;
return - V_34 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_206 ; ++ V_7 ) {
V_29 = F_64 ( V_6 -> V_8 , V_6 -> V_205 [ V_7 ] ,
F_51 ,
V_207 ,
L_48 ,
V_6 ) ;
if ( V_29 ) {
F_65 ( V_8 , L_49 ,
V_7 , V_6 -> V_205 [ V_7 ] ) ;
return V_29 ;
}
}
V_29 = F_159 ( & V_6 -> V_282 , V_6 -> V_8 , NULL ,
L_50 , & V_402 ) ;
if ( V_29 ) {
F_65 ( V_8 , L_51 ) ;
return V_29 ;
}
F_160 ( & V_6 -> V_282 , & V_40 ) ;
F_161 ( & V_6 -> V_282 , V_8 -> V_39 ) ;
V_29 = F_162 ( & V_6 -> V_282 ) ;
if ( V_29 ) {
F_65 ( V_8 , L_52 ) ;
return V_29 ;
}
F_163 ( V_21 , V_6 ) ;
F_131 ( V_6 ) ;
F_82 ( V_6 ) ;
if ( ! V_211 )
F_147 () ;
return 0 ;
}
static int F_164 ( void )
{
if ( V_211 )
F_147 () ;
return 0 ;
}
static int F_165 ( struct V_388 * V_21 )
{
struct V_5 * V_6 = F_166 ( V_21 ) ;
if ( ! V_6 )
return - V_34 ;
if ( ! F_167 ( V_6 -> V_194 , V_406 ) )
F_65 ( & V_21 -> V_8 , L_53 ) ;
F_50 ( V_323 , F_52 ( V_6 ) + V_316 ) ;
return 0 ;
}
