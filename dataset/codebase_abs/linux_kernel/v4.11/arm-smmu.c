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
static void F_31 ( struct V_5 * V_6 )
{
int V_48 = 0 ;
void T_3 * V_49 = F_32 ( V_6 ) ;
F_33 ( 0 , V_49 + V_50 ) ;
while ( F_34 ( V_49 + V_51 )
& V_52 ) {
F_35 () ;
if ( ++ V_48 == V_53 ) {
F_36 ( V_6 -> V_8 ,
L_4 ) ;
return;
}
F_37 ( 1 ) ;
}
}
static void F_38 ( void * V_54 )
{
struct V_1 * V_55 = V_54 ;
F_31 ( V_55 -> V_6 ) ;
}
static void F_39 ( void * V_54 )
{
struct V_1 * V_55 = V_54 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_5 * V_6 = V_55 -> V_6 ;
bool V_58 = V_57 -> V_59 != V_60 ;
void T_3 * V_61 ;
if ( V_58 ) {
V_61 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
F_33 ( F_42 ( V_6 , V_57 ) ,
V_61 + V_63 ) ;
} else {
V_61 = F_32 ( V_6 ) ;
F_33 ( F_43 ( V_6 , V_57 ) ,
V_61 + V_64 ) ;
}
F_31 ( V_6 ) ;
}
static void F_44 ( unsigned long V_65 , T_4 V_66 ,
T_4 V_67 , bool V_68 , void * V_54 )
{
struct V_1 * V_55 = V_54 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_5 * V_6 = V_55 -> V_6 ;
bool V_58 = V_57 -> V_59 != V_60 ;
void T_3 * V_69 ;
if ( V_58 ) {
V_69 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
V_69 += V_68 ? V_70 : V_71 ;
if ( V_57 -> V_72 != V_73 ) {
V_65 &= ~ 12UL ;
V_65 |= F_42 ( V_6 , V_57 ) ;
do {
F_33 ( V_65 , V_69 ) ;
V_65 += V_67 ;
} while ( V_66 -= V_67 );
} else {
V_65 >>= 12 ;
V_65 |= ( V_74 ) F_42 ( V_6 , V_57 ) << 48 ;
do {
F_45 ( V_65 , V_69 ) ;
V_65 += V_67 >> 12 ;
} while ( V_66 -= V_67 );
}
} else if ( V_6 -> V_75 == V_76 ) {
V_69 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
V_69 += V_68 ? V_77 :
V_78 ;
V_65 >>= 12 ;
do {
F_46 ( V_65 , V_69 ) ;
V_65 += V_67 >> 12 ;
} while ( V_66 -= V_67 );
} else {
V_69 = F_32 ( V_6 ) + V_64 ;
F_33 ( F_43 ( V_6 , V_57 ) , V_69 ) ;
}
}
static T_5 F_47 ( int V_79 , void * V_8 )
{
T_2 V_80 , V_81 ;
unsigned long V_65 ;
struct V_2 * V_4 = V_8 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_5 * V_6 = V_55 -> V_6 ;
void T_3 * V_82 ;
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
V_80 = F_34 ( V_82 + V_83 ) ;
if ( ! ( V_80 & V_84 ) )
return V_85 ;
V_81 = F_34 ( V_82 + V_86 ) ;
V_65 = F_48 ( V_82 + V_87 ) ;
F_36 ( V_6 -> V_8 ,
L_5 ,
V_80 , V_65 , V_81 , V_57 -> V_62 ) ;
F_49 ( V_80 , V_82 + V_83 ) ;
return V_88 ;
}
static T_5 F_50 ( int V_79 , void * V_8 )
{
T_2 V_89 , V_90 , V_91 , V_92 ;
struct V_5 * V_6 = V_8 ;
void T_3 * V_49 = F_51 ( V_6 ) ;
V_89 = F_34 ( V_49 + V_93 ) ;
V_90 = F_34 ( V_49 + V_94 ) ;
V_91 = F_34 ( V_49 + V_95 ) ;
V_92 = F_34 ( V_49 + V_96 ) ;
if ( ! V_89 )
return V_85 ;
F_36 ( V_6 -> V_8 ,
L_6 ) ;
F_36 ( V_6 -> V_8 ,
L_7 ,
V_89 , V_90 , V_91 , V_92 ) ;
F_49 ( V_89 , V_49 + V_93 ) ;
return V_88 ;
}
static void F_52 ( struct V_1 * V_55 ,
struct V_97 * V_98 )
{
T_2 V_69 , V_99 ;
V_74 V_100 ;
bool V_58 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_5 * V_6 = V_55 -> V_6 ;
void T_3 * V_82 , * V_101 ;
V_101 = F_53 ( V_6 ) ;
V_58 = V_57 -> V_59 != V_60 ;
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
if ( V_6 -> V_75 > V_102 ) {
if ( V_57 -> V_72 == V_73 )
V_69 = V_103 ;
else
V_69 = V_104 ;
if ( V_6 -> V_105 & V_106 )
V_69 |= F_43 ( V_6 , V_57 ) << V_107 ;
F_33 ( V_69 , V_101 + F_54 ( V_57 -> V_62 ) ) ;
}
V_69 = V_57 -> V_59 ;
if ( V_6 -> V_75 < V_76 )
V_69 |= V_57 -> V_108 << V_109 ;
if ( V_58 ) {
V_69 |= ( V_110 << V_111 ) |
( V_112 << V_113 ) ;
} else if ( ! ( V_6 -> V_105 & V_106 ) ) {
V_69 |= F_43 ( V_6 , V_57 ) << V_114 ;
}
F_33 ( V_69 , V_101 + F_55 ( V_57 -> V_62 ) ) ;
if ( V_58 ) {
T_1 V_115 = F_42 ( V_6 , V_57 ) ;
if ( V_57 -> V_72 == V_116 ) {
V_69 = V_98 -> V_117 . V_118 [ 0 ] ;
F_33 ( V_69 , V_82 + V_119 ) ;
V_69 = V_98 -> V_117 . V_118 [ 1 ] ;
F_33 ( V_69 , V_82 + V_120 ) ;
F_33 ( V_115 , V_82 + V_121 ) ;
} else {
V_100 = V_98 -> V_122 . V_118 [ 0 ] ;
V_100 |= ( V_74 ) V_115 << V_123 ;
F_45 ( V_100 , V_82 + V_119 ) ;
V_100 = V_98 -> V_122 . V_118 [ 1 ] ;
V_100 |= ( V_74 ) V_115 << V_123 ;
F_45 ( V_100 , V_82 + V_120 ) ;
}
} else {
V_100 = V_98 -> V_124 . V_125 ;
F_45 ( V_100 , V_82 + V_119 ) ;
}
if ( V_58 ) {
if ( V_57 -> V_72 == V_116 ) {
V_69 = V_98 -> V_117 . V_126 ;
V_99 = 0 ;
} else {
V_69 = V_98 -> V_122 . V_126 ;
V_99 = V_98 -> V_122 . V_126 >> 32 ;
V_99 |= V_127 ;
if ( V_57 -> V_72 == V_73 )
V_99 |= V_128 ;
}
if ( V_6 -> V_75 > V_102 )
F_33 ( V_99 , V_82 + V_129 ) ;
} else {
V_69 = V_98 -> V_124 . V_130 ;
}
F_33 ( V_69 , V_82 + V_131 ) ;
if ( V_58 ) {
if ( V_57 -> V_72 == V_116 ) {
V_69 = V_98 -> V_117 . V_132 ;
V_99 = V_98 -> V_117 . V_133 ;
} else {
V_69 = V_98 -> V_122 . V_134 [ 0 ] ;
V_99 = V_98 -> V_122 . V_134 [ 1 ] ;
}
F_33 ( V_69 , V_82 + V_135 ) ;
F_33 ( V_99 , V_82 + V_136 ) ;
}
V_69 = V_137 | V_138 | V_139 | V_140 | V_141 ;
if ( V_58 )
V_69 |= V_142 ;
#ifdef F_56
V_69 |= V_143 ;
#endif
F_33 ( V_69 , V_82 + V_144 ) ;
}
static int F_57 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_79 , V_44 , V_145 = 0 ;
unsigned long V_146 , V_147 ;
struct V_148 * V_149 ;
struct V_97 V_98 ;
enum V_150 V_72 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_56 * V_57 = & V_55 -> V_57 ;
F_58 ( & V_55 -> V_151 ) ;
if ( V_55 -> V_6 )
goto V_152;
if ( ! ( V_6 -> V_105 & V_153 ) )
V_55 -> V_154 = V_155 ;
if ( ! ( V_6 -> V_105 & V_156 ) )
V_55 -> V_154 = V_157 ;
if ( V_6 -> V_105 & V_158 )
V_57 -> V_72 = V_159 ;
if ( F_59 ( V_160 ) &&
! F_59 ( V_161 ) && ! F_59 ( V_162 ) &&
( V_6 -> V_105 & V_163 ) &&
( V_55 -> V_154 == V_157 ) )
V_57 -> V_72 = V_116 ;
if ( ( F_59 ( V_161 ) || V_57 -> V_72 == V_164 ) &&
( V_6 -> V_105 & ( V_165 |
V_166 |
V_167 ) ) )
V_57 -> V_72 = V_73 ;
if ( V_57 -> V_72 == V_164 ) {
V_145 = - V_168 ;
goto V_152;
}
switch ( V_55 -> V_154 ) {
case V_157 :
V_57 -> V_59 = V_169 ;
V_44 = V_6 -> V_170 ;
V_146 = V_6 -> V_171 ;
V_147 = V_6 -> V_172 ;
if ( V_57 -> V_72 == V_73 ) {
V_72 = V_173 ;
} else if ( V_57 -> V_72 == V_159 ) {
V_72 = V_174 ;
V_146 = F_60 ( V_146 , 32UL ) ;
V_147 = F_60 ( V_147 , 40UL ) ;
} else {
V_72 = V_175 ;
V_146 = F_60 ( V_146 , 32UL ) ;
V_147 = F_60 ( V_147 , 32UL ) ;
}
break;
case V_176 :
case V_155 :
V_57 -> V_59 = V_60 ;
V_44 = 0 ;
V_146 = V_6 -> V_172 ;
V_147 = V_6 -> V_177 ;
if ( V_57 -> V_72 == V_73 ) {
V_72 = V_178 ;
} else {
V_72 = V_179 ;
V_146 = F_60 ( V_146 , 40UL ) ;
V_147 = F_60 ( V_147 , 40UL ) ;
}
break;
default:
V_145 = - V_168 ;
goto V_152;
}
V_145 = F_26 ( V_6 -> V_180 , V_44 ,
V_6 -> V_181 ) ;
if ( V_145 < 0 )
goto V_152;
V_57 -> V_62 = V_145 ;
if ( V_6 -> V_75 < V_76 ) {
V_57 -> V_108 = F_61 ( & V_6 -> V_108 ) ;
V_57 -> V_108 %= V_6 -> V_182 ;
} else {
V_57 -> V_108 = V_57 -> V_62 ;
}
V_98 = (struct V_97 ) {
. V_183 = V_6 -> V_183 ,
. V_146 = V_146 ,
. V_147 = V_147 ,
. V_184 = & V_185 ,
. V_186 = V_6 -> V_8 ,
} ;
V_55 -> V_6 = V_6 ;
V_149 = F_62 ( V_72 , & V_98 , V_55 ) ;
if ( ! V_149 ) {
V_145 = - V_42 ;
goto V_187;
}
V_4 -> V_183 = V_98 . V_183 ;
V_4 -> V_188 . V_189 = ( 1UL << V_146 ) - 1 ;
V_4 -> V_188 . V_190 = true ;
F_52 ( V_55 , & V_98 ) ;
V_79 = V_6 -> V_191 [ V_6 -> V_192 + V_57 -> V_108 ] ;
V_145 = F_63 ( V_6 -> V_8 , V_79 , F_47 ,
V_193 , L_8 , V_4 ) ;
if ( V_145 < 0 ) {
F_64 ( V_6 -> V_8 , L_9 ,
V_57 -> V_108 , V_79 ) ;
V_57 -> V_108 = V_194 ;
}
F_65 ( & V_55 -> V_151 ) ;
V_55 -> V_149 = V_149 ;
return 0 ;
V_187:
V_55 -> V_6 = NULL ;
V_152:
F_65 ( & V_55 -> V_151 ) ;
return V_145 ;
}
static void F_66 ( struct V_2 * V_4 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
void T_3 * V_82 ;
int V_79 ;
if ( ! V_6 )
return;
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
F_33 ( 0 , V_82 + V_144 ) ;
if ( V_57 -> V_108 != V_194 ) {
V_79 = V_6 -> V_191 [ V_6 -> V_192 + V_57 -> V_108 ] ;
F_67 ( V_6 -> V_8 , V_79 , V_4 ) ;
}
F_68 ( V_55 -> V_149 ) ;
F_29 ( V_6 -> V_180 , V_57 -> V_62 ) ;
}
static struct V_2 * F_69 ( unsigned type )
{
struct V_1 * V_55 ;
if ( type != V_195 && type != V_196 )
return NULL ;
V_55 = F_70 ( sizeof( * V_55 ) , V_41 ) ;
if ( ! V_55 )
return NULL ;
if ( type == V_196 && ( V_197 ||
F_71 ( & V_55 -> V_4 ) ) ) {
F_25 ( V_55 ) ;
return NULL ;
}
F_72 ( & V_55 -> V_151 ) ;
F_73 ( & V_55 -> V_198 ) ;
return & V_55 -> V_4 ;
}
static void F_74 ( struct V_2 * V_4 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
F_75 ( V_4 ) ;
F_66 ( V_4 ) ;
F_25 ( V_55 ) ;
}
static void F_76 ( struct V_5 * V_6 , int V_46 )
{
struct V_199 * V_200 = V_6 -> V_201 + V_46 ;
T_2 V_69 = V_200 -> V_202 << V_203 | V_200 -> V_204 << V_205 ;
if ( ! ( V_6 -> V_105 & V_206 ) && V_200 -> V_207 )
V_69 |= V_208 ;
F_33 ( V_69 , F_32 ( V_6 ) + F_77 ( V_46 ) ) ;
}
static void F_78 ( struct V_5 * V_6 , int V_46 )
{
struct V_209 * V_210 = V_6 -> V_211 + V_46 ;
T_2 V_69 = ( V_210 -> type & V_212 ) << V_213 |
( V_210 -> V_62 & V_214 ) << V_215 |
( V_210 -> V_216 & V_217 ) << V_218 ;
if ( V_6 -> V_105 & V_206 && V_6 -> V_201 &&
V_6 -> V_201 [ V_46 ] . V_207 )
V_69 |= V_219 ;
F_33 ( V_69 , F_32 ( V_6 ) + F_79 ( V_46 ) ) ;
}
static void F_80 ( struct V_5 * V_6 , int V_46 )
{
F_78 ( V_6 , V_46 ) ;
if ( V_6 -> V_201 )
F_76 ( V_6 , V_46 ) ;
}
static void F_81 ( struct V_5 * V_6 )
{
void T_3 * V_49 = F_32 ( V_6 ) ;
T_2 V_200 ;
if ( ! V_6 -> V_201 )
return;
V_200 = V_6 -> V_220 << V_203 ;
F_33 ( V_200 , V_49 + F_77 ( 0 ) ) ;
V_200 = F_34 ( V_49 + F_77 ( 0 ) ) ;
V_6 -> V_220 = V_200 >> V_203 ;
V_200 = V_6 -> V_220 << V_205 ;
F_33 ( V_200 , V_49 + F_77 ( 0 ) ) ;
V_200 = F_34 ( V_49 + F_77 ( 0 ) ) ;
V_6 -> V_221 = V_200 >> V_205 ;
}
static int F_82 ( struct V_5 * V_6 , T_1 V_202 , T_1 V_204 )
{
struct V_199 * V_201 = V_6 -> V_201 ;
int V_7 , V_222 = - V_47 ;
if ( ! V_201 )
return V_202 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_223 ; ++ V_7 ) {
if ( ! V_201 [ V_7 ] . V_207 ) {
if ( V_222 < 0 )
V_222 = V_7 ;
continue;
}
if ( ( V_204 & V_201 [ V_7 ] . V_204 ) == V_204 &&
! ( ( V_202 ^ V_201 [ V_7 ] . V_202 ) & ~ V_201 [ V_7 ] . V_204 ) )
return V_7 ;
if ( ! ( ( V_202 ^ V_201 [ V_7 ] . V_202 ) & ~ ( V_201 [ V_7 ] . V_204 | V_204 ) ) )
return - V_168 ;
}
return V_222 ;
}
static bool F_83 ( struct V_5 * V_6 , int V_46 )
{
if ( -- V_6 -> V_211 [ V_46 ] . V_48 )
return false ;
V_6 -> V_211 [ V_46 ] = V_224 ;
if ( V_6 -> V_201 )
V_6 -> V_201 [ V_46 ] . V_207 = false ;
return true ;
}
static int F_84 ( struct V_15 * V_8 )
{
struct V_225 * V_226 = V_8 -> V_225 ;
struct V_227 * V_57 = V_226 -> V_228 ;
struct V_5 * V_6 = V_57 -> V_6 ;
struct V_199 * V_201 = V_6 -> V_201 ;
struct V_229 * V_230 ;
int V_7 , V_46 , V_145 ;
F_58 ( & V_6 -> V_231 ) ;
F_85 (fwspec, i, idx) {
T_1 V_232 = V_226 -> V_233 [ V_7 ] ;
T_1 V_204 = V_226 -> V_233 [ V_7 ] >> V_205 ;
if ( V_46 != V_234 ) {
V_145 = - V_235 ;
goto V_236;
}
V_145 = F_82 ( V_6 , V_232 , V_204 ) ;
if ( V_145 < 0 )
goto V_236;
V_46 = V_145 ;
if ( V_201 && V_6 -> V_211 [ V_46 ] . V_48 == 0 ) {
V_201 [ V_46 ] . V_202 = V_232 ;
V_201 [ V_46 ] . V_204 = V_204 ;
V_201 [ V_46 ] . V_207 = true ;
}
V_6 -> V_211 [ V_46 ] . V_48 ++ ;
V_57 -> V_237 [ V_7 ] = ( V_238 ) V_46 ;
}
V_230 = F_86 ( V_8 ) ;
if ( ! V_230 )
V_230 = F_87 ( - V_42 ) ;
if ( F_88 ( V_230 ) ) {
V_145 = F_89 ( V_230 ) ;
goto V_236;
}
F_90 ( V_230 ) ;
F_85 (fwspec, i, idx) {
F_80 ( V_6 , V_46 ) ;
V_6 -> V_211 [ V_46 ] . V_230 = V_230 ;
}
F_65 ( & V_6 -> V_231 ) ;
return 0 ;
V_236:
while ( V_7 -- ) {
F_83 ( V_6 , V_57 -> V_237 [ V_7 ] ) ;
V_57 -> V_237 [ V_7 ] = V_234 ;
}
F_65 ( & V_6 -> V_231 ) ;
return V_145 ;
}
static void F_91 ( struct V_225 * V_226 )
{
struct V_5 * V_6 = F_92 ( V_226 ) ;
struct V_227 * V_57 = V_226 -> V_228 ;
int V_7 , V_46 ;
F_58 ( & V_6 -> V_231 ) ;
F_85 (fwspec, i, idx) {
if ( F_83 ( V_6 , V_46 ) )
F_80 ( V_6 , V_46 ) ;
V_57 -> V_237 [ V_7 ] = V_234 ;
}
F_65 ( & V_6 -> V_231 ) ;
}
static int F_93 ( struct V_1 * V_55 ,
struct V_225 * V_226 )
{
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_209 * V_210 = V_6 -> V_211 ;
enum V_239 type = V_240 ;
T_6 V_62 = V_55 -> V_57 . V_62 ;
int V_7 , V_46 ;
F_85 (fwspec, i, idx) {
if ( type == V_210 [ V_46 ] . type && V_62 == V_210 [ V_46 ] . V_62 )
continue;
V_210 [ V_46 ] . type = type ;
V_210 [ V_46 ] . V_216 = V_241 ;
V_210 [ V_46 ] . V_62 = V_62 ;
F_78 ( V_6 , V_46 ) ;
}
return 0 ;
}
static int F_94 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_145 ;
struct V_225 * V_226 = V_8 -> V_225 ;
struct V_5 * V_6 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
if ( ! V_226 || V_226 -> V_242 != & V_40 ) {
F_64 ( V_8 , L_10 ) ;
return - V_243 ;
}
if ( ! V_226 -> V_228 )
return - V_34 ;
V_6 = F_92 ( V_226 ) ;
V_145 = F_57 ( V_4 , V_6 ) ;
if ( V_145 < 0 )
return V_145 ;
if ( V_55 -> V_6 != V_6 ) {
F_64 ( V_8 ,
L_11 ,
F_95 ( V_55 -> V_6 -> V_8 ) , F_95 ( V_6 -> V_8 ) ) ;
return - V_168 ;
}
return F_93 ( V_55 , V_226 ) ;
}
static int F_96 ( struct V_2 * V_4 , unsigned long V_65 ,
T_7 V_244 , T_4 V_66 , int V_245 )
{
int V_145 ;
unsigned long V_246 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_148 * V_242 = V_55 -> V_149 ;
if ( ! V_242 )
return - V_34 ;
F_97 ( & V_55 -> V_198 , V_246 ) ;
V_145 = V_242 -> V_43 ( V_242 , V_65 , V_244 , V_66 , V_245 ) ;
F_98 ( & V_55 -> V_198 , V_246 ) ;
return V_145 ;
}
static T_4 F_99 ( struct V_2 * V_4 , unsigned long V_65 ,
T_4 V_66 )
{
T_4 V_145 ;
unsigned long V_246 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_148 * V_242 = V_55 -> V_149 ;
if ( ! V_242 )
return 0 ;
F_97 ( & V_55 -> V_198 , V_246 ) ;
V_145 = V_242 -> V_247 ( V_242 , V_65 , V_66 ) ;
F_98 ( & V_55 -> V_198 , V_246 ) ;
return V_145 ;
}
static T_7 F_100 ( struct V_2 * V_4 ,
T_8 V_65 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_148 * V_242 = V_55 -> V_149 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_3 * V_82 ;
T_2 V_248 ;
V_74 V_249 ;
unsigned long V_250 ;
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
V_250 = V_65 & ~ 0xfffUL ;
if ( V_6 -> V_75 == V_76 )
F_46 ( V_250 , V_82 + V_251 ) ;
else
F_33 ( V_250 , V_82 + V_251 ) ;
if ( F_101 ( V_82 + V_252 , V_248 ,
! ( V_248 & V_253 ) , 5 , 50 ) ) {
F_64 ( V_8 ,
L_12 ,
& V_65 ) ;
return V_242 -> V_254 ( V_242 , V_65 ) ;
}
V_249 = F_48 ( V_82 + V_255 ) ;
if ( V_249 & V_256 ) {
F_64 ( V_8 , L_13 ) ;
F_64 ( V_8 , L_14 , V_249 ) ;
return 0 ;
}
return ( V_249 & F_102 ( 39 , 12 ) ) | ( V_65 & 0xfff ) ;
}
static T_7 F_103 ( struct V_2 * V_4 ,
T_8 V_65 )
{
T_7 V_145 ;
unsigned long V_246 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_148 * V_242 = V_55 -> V_149 ;
if ( ! V_242 )
return 0 ;
F_97 ( & V_55 -> V_198 , V_246 ) ;
if ( V_55 -> V_6 -> V_105 & V_257 &&
V_55 -> V_154 == V_157 ) {
V_145 = F_100 ( V_4 , V_65 ) ;
} else {
V_145 = V_242 -> V_254 ( V_242 , V_65 ) ;
}
F_98 ( & V_55 -> V_198 , V_246 ) ;
return V_145 ;
}
static bool F_104 ( enum V_258 V_259 )
{
switch ( V_259 ) {
case V_260 :
return true ;
case V_261 :
return true ;
default:
return false ;
}
}
static int F_105 ( struct V_15 * V_8 , void * V_23 )
{
return V_8 -> V_39 == V_23 ;
}
static
struct V_5 * F_106 ( struct V_262 * V_39 )
{
struct V_15 * V_8 = F_107 ( & V_35 . V_36 , NULL ,
V_39 , F_105 ) ;
F_108 ( V_8 ) ;
return V_8 ? F_22 ( V_8 ) : NULL ;
}
static int F_109 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_227 * V_57 ;
struct V_225 * V_226 = V_8 -> V_225 ;
int V_7 , V_145 ;
if ( V_197 ) {
V_145 = F_15 ( V_8 , & V_6 ) ;
V_226 = V_8 -> V_225 ;
if ( V_145 )
goto V_263;
} else if ( V_226 && V_226 -> V_242 == & V_40 ) {
V_6 = F_106 ( V_226 -> V_264 ) ;
} else {
return - V_34 ;
}
V_145 = - V_168 ;
for ( V_7 = 0 ; V_7 < V_226 -> V_265 ; V_7 ++ ) {
T_1 V_232 = V_226 -> V_233 [ V_7 ] ;
T_1 V_204 = V_226 -> V_233 [ V_7 ] >> V_205 ;
if ( V_232 & ~ V_6 -> V_220 ) {
F_64 ( V_8 , L_15 ,
V_232 , V_6 -> V_220 ) ;
goto V_263;
}
if ( V_204 & ~ V_6 -> V_221 ) {
F_64 ( V_8 , L_16 ,
V_232 , V_6 -> V_221 ) ;
goto V_263;
}
}
V_145 = - V_42 ;
V_57 = F_70 ( F_110 ( struct V_227 , V_237 [ V_7 ] ) ,
V_41 ) ;
if ( ! V_57 )
goto V_263;
V_57 -> V_6 = V_6 ;
V_226 -> V_228 = V_57 ;
while ( V_7 -- )
V_57 -> V_237 [ V_7 ] = V_234 ;
V_145 = F_84 ( V_8 ) ;
if ( V_145 )
goto V_263;
F_111 ( & V_6 -> V_266 , V_8 ) ;
return 0 ;
V_263:
if ( V_226 )
F_25 ( V_226 -> V_228 ) ;
F_112 ( V_8 ) ;
return V_145 ;
}
static void F_113 ( struct V_15 * V_8 )
{
struct V_225 * V_226 = V_8 -> V_225 ;
struct V_227 * V_57 ;
struct V_5 * V_6 ;
if ( ! V_226 || V_226 -> V_242 != & V_40 )
return;
V_57 = V_226 -> V_228 ;
V_6 = V_57 -> V_6 ;
F_114 ( & V_6 -> V_266 , V_8 ) ;
F_91 ( V_226 ) ;
F_115 ( V_8 ) ;
F_25 ( V_226 -> V_228 ) ;
F_112 ( V_8 ) ;
}
static struct V_229 * F_116 ( struct V_15 * V_8 )
{
struct V_225 * V_226 = V_8 -> V_225 ;
struct V_5 * V_6 = F_92 ( V_226 ) ;
struct V_229 * V_230 = NULL ;
int V_7 , V_46 ;
F_85 (fwspec, i, idx) {
if ( V_230 && V_6 -> V_211 [ V_46 ] . V_230 &&
V_230 != V_6 -> V_211 [ V_46 ] . V_230 )
return F_87 ( - V_168 ) ;
V_230 = V_6 -> V_211 [ V_46 ] . V_230 ;
}
if ( V_230 )
return F_117 ( V_230 ) ;
if ( F_7 ( V_8 ) )
V_230 = F_118 ( V_8 ) ;
else
V_230 = F_119 ( V_8 ) ;
return V_230 ;
}
static int F_120 ( struct V_2 * V_4 ,
enum V_267 V_268 , void * V_23 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
switch ( V_268 ) {
case V_269 :
* ( int * ) V_23 = ( V_55 -> V_154 == V_176 ) ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_121 ( struct V_2 * V_4 ,
enum V_267 V_268 , void * V_23 )
{
int V_145 = 0 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
F_58 ( & V_55 -> V_151 ) ;
switch ( V_268 ) {
case V_269 :
if ( V_55 -> V_6 ) {
V_145 = - V_270 ;
goto V_152;
}
if ( * ( int * ) V_23 )
V_55 -> V_154 = V_176 ;
else
V_55 -> V_154 = V_157 ;
break;
default:
V_145 = - V_34 ;
}
V_152:
F_65 ( & V_55 -> V_151 ) ;
return V_145 ;
}
static int F_122 ( struct V_15 * V_8 , struct V_271 * args )
{
T_2 V_272 = 0 ;
if ( args -> V_273 > 0 )
V_272 |= ( T_1 ) args -> args [ 0 ] ;
if ( args -> V_273 > 1 )
V_272 |= ( T_1 ) args -> args [ 1 ] << V_205 ;
return F_24 ( V_8 , & V_272 , 1 ) ;
}
static void F_123 ( struct V_15 * V_8 ,
struct V_274 * V_275 )
{
struct V_276 * V_277 ;
int V_245 = V_278 | V_279 | V_280 ;
V_277 = F_124 ( V_281 , V_282 ,
V_245 , V_283 ) ;
if ( ! V_277 )
return;
F_125 ( & V_277 -> V_284 , V_275 ) ;
}
static void F_126 ( struct V_15 * V_8 ,
struct V_274 * V_275 )
{
struct V_276 * V_285 , * V_286 ;
F_127 (entry, next, head, list)
F_25 ( V_285 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
void T_3 * V_49 = F_32 ( V_6 ) ;
void T_3 * V_82 ;
int V_7 ;
T_2 V_69 , V_287 ;
V_69 = F_34 ( F_51 ( V_6 ) + V_93 ) ;
F_49 ( V_69 , F_51 ( V_6 ) + V_93 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_223 ; ++ V_7 )
F_80 ( V_6 , V_7 ) ;
if ( V_6 -> V_288 == V_289 ) {
V_69 = F_34 ( V_49 + V_290 ) ;
V_287 = ( V_69 >> V_291 ) & V_292 ;
V_69 = F_34 ( V_49 + V_293 ) ;
if ( V_287 >= 2 )
V_69 &= ~ V_294 ;
V_69 |= V_295 ;
F_33 ( V_69 , V_49 + V_293 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_181 ; ++ V_7 ) {
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_7 ) ;
F_33 ( 0 , V_82 + V_144 ) ;
F_33 ( V_84 , V_82 + V_83 ) ;
if ( V_6 -> V_288 == V_289 ) {
V_69 = F_34 ( V_82 + V_296 ) ;
V_69 &= ~ V_297 ;
F_33 ( V_69 , V_82 + V_296 ) ;
}
}
F_33 ( 0 , V_49 + V_298 ) ;
F_33 ( 0 , V_49 + V_299 ) ;
V_69 = F_34 ( F_51 ( V_6 ) + V_300 ) ;
V_69 |= ( V_301 | V_302 | V_303 | V_304 ) ;
V_69 |= ( V_305 | V_306 ) ;
V_69 &= ~ V_307 ;
if ( V_308 )
V_69 |= V_309 ;
else
V_69 &= ~ V_309 ;
V_69 &= ~ V_310 ;
V_69 &= ~ ( V_311 << V_312 ) ;
if ( V_6 -> V_105 & V_106 )
V_69 |= V_313 ;
if ( V_6 -> V_105 & V_206 )
V_69 |= V_314 ;
F_31 ( V_6 ) ;
F_49 ( V_69 , F_51 ( V_6 ) + V_300 ) ;
}
static int F_129 ( int V_66 )
{
switch ( V_66 ) {
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
static int F_130 ( struct V_5 * V_6 )
{
unsigned long V_66 ;
void T_3 * V_49 = F_32 ( V_6 ) ;
T_2 V_202 ;
bool V_315 , V_316 = V_6 -> V_105 & V_317 ;
int V_7 ;
F_5 ( V_6 -> V_8 , L_17 ) ;
F_5 ( V_6 -> V_8 , L_18 ,
V_6 -> V_75 == V_76 ? 2 : 1 ) ;
V_202 = F_34 ( V_49 + V_318 ) ;
if ( V_319 == 1 )
V_202 &= ~ ( V_320 | V_321 ) ;
else if ( V_319 == 2 )
V_202 &= ~ ( V_322 | V_321 ) ;
if ( V_202 & V_322 ) {
V_6 -> V_105 |= V_153 ;
F_5 ( V_6 -> V_8 , L_19 ) ;
}
if ( V_202 & V_320 ) {
V_6 -> V_105 |= V_156 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_202 & V_321 ) {
V_6 -> V_105 |= V_323 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( ! ( V_6 -> V_105 &
( V_153 | V_156 ) ) ) {
F_64 ( V_6 -> V_8 , L_22 ) ;
return - V_34 ;
}
if ( ( V_202 & V_322 ) &&
( ( V_6 -> V_75 < V_76 ) || ! ( V_202 & V_324 ) ) ) {
V_6 -> V_105 |= V_257 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
V_315 = ! ! ( V_202 & V_325 ) ;
if ( V_316 || V_315 )
F_5 ( V_6 -> V_8 , L_24 ,
V_316 ? L_25 : L_26 ) ;
if ( V_316 != V_315 )
F_5 ( V_6 -> V_8 ,
L_27 ) ;
if ( V_6 -> V_75 == V_76 && V_202 & V_326 ) {
V_6 -> V_105 |= V_206 ;
V_66 = 1 << 16 ;
} else {
V_66 = 1 << ( ( V_202 >> V_327 ) & V_328 ) ;
}
V_6 -> V_220 = V_66 - 1 ;
if ( V_202 & V_329 ) {
V_6 -> V_105 |= V_330 ;
V_66 = ( V_202 >> V_331 ) & V_332 ;
if ( V_66 == 0 ) {
F_64 ( V_6 -> V_8 ,
L_28 ) ;
return - V_34 ;
}
V_6 -> V_201 = F_131 ( V_6 -> V_8 , V_66 , sizeof( * V_6 -> V_201 ) ,
V_41 ) ;
if ( ! V_6 -> V_201 )
return - V_42 ;
F_5 ( V_6 -> V_8 ,
L_29 , V_66 ) ;
}
V_6 -> V_211 = F_132 ( V_6 -> V_8 , V_66 , sizeof( * V_6 -> V_211 ) ,
V_41 ) ;
if ( ! V_6 -> V_211 )
return - V_42 ;
for ( V_7 = 0 ; V_7 < V_66 ; V_7 ++ )
V_6 -> V_211 [ V_7 ] = V_224 ;
V_6 -> V_223 = V_66 ;
F_72 ( & V_6 -> V_231 ) ;
if ( V_6 -> V_75 < V_76 || ! ( V_202 & V_333 ) ) {
V_6 -> V_105 |= V_158 ;
if ( ! ( V_202 & V_334 ) )
V_6 -> V_105 |= V_163 ;
}
V_202 = F_34 ( V_49 + V_335 ) ;
V_6 -> V_336 = ( V_202 & V_337 ) ? 16 : 12 ;
V_66 = 1 << ( ( ( V_202 >> V_338 ) & V_339 ) + 1 ) ;
V_66 *= 2 << V_6 -> V_336 ;
if ( V_6 -> V_66 != V_66 )
F_133 ( V_6 -> V_8 ,
L_30 ,
V_66 , V_6 -> V_66 ) ;
V_6 -> V_170 = ( V_202 >> V_340 ) & V_341 ;
V_6 -> V_181 = ( V_202 >> V_342 ) & V_343 ;
if ( V_6 -> V_170 > V_6 -> V_181 ) {
F_64 ( V_6 -> V_8 , L_31 ) ;
return - V_34 ;
}
F_5 ( V_6 -> V_8 , L_32 ,
V_6 -> V_181 , V_6 -> V_170 ) ;
if ( V_6 -> V_288 == V_344 ) {
V_6 -> V_345 =
F_134 ( V_6 -> V_181 ,
& V_346 ) ;
V_6 -> V_345 -= V_6 -> V_181 ;
}
V_202 = F_34 ( V_49 + V_347 ) ;
V_66 = F_129 ( ( V_202 >> V_348 ) & V_349 ) ;
V_6 -> V_172 = V_66 ;
V_66 = F_129 ( ( V_202 >> V_350 ) & V_351 ) ;
V_6 -> V_177 = V_66 ;
if ( V_202 & V_352 )
V_6 -> V_105 |= V_106 ;
if ( F_135 ( V_6 -> V_8 , F_136 ( V_66 ) ) )
F_133 ( V_6 -> V_8 ,
L_33 ) ;
if ( V_6 -> V_75 < V_76 ) {
V_6 -> V_171 = V_6 -> V_172 ;
if ( V_6 -> V_75 == V_353 )
V_6 -> V_105 |= V_165 ;
} else {
V_66 = ( V_202 >> V_354 ) & V_355 ;
V_6 -> V_171 = F_129 ( V_66 ) ;
if ( V_202 & V_356 )
V_6 -> V_105 |= V_167 ;
if ( V_202 & V_357 )
V_6 -> V_105 |= V_166 ;
if ( V_202 & V_358 )
V_6 -> V_105 |= V_165 ;
}
if ( V_6 -> V_105 & V_163 )
V_6 -> V_183 |= V_359 | V_360 | V_361 | V_362 ;
if ( V_6 -> V_105 &
( V_158 | V_167 ) )
V_6 -> V_183 |= V_359 | V_363 | V_364 ;
if ( V_6 -> V_105 & V_166 )
V_6 -> V_183 |= V_365 | V_366 ;
if ( V_6 -> V_105 & V_165 )
V_6 -> V_183 |= V_360 | V_367 ;
if ( V_40 . V_183 == - 1UL )
V_40 . V_183 = V_6 -> V_183 ;
else
V_40 . V_183 |= V_6 -> V_183 ;
F_5 ( V_6 -> V_8 , L_34 ,
V_6 -> V_183 ) ;
if ( V_6 -> V_105 & V_153 )
F_5 ( V_6 -> V_8 , L_35 ,
V_6 -> V_171 , V_6 -> V_172 ) ;
if ( V_6 -> V_105 & V_156 )
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_172 , V_6 -> V_177 ) ;
return 0 ;
}
static int F_137 ( T_2 V_288 , struct V_5 * V_6 )
{
int V_145 = 0 ;
switch ( V_288 ) {
case V_368 :
case V_369 :
V_6 -> V_75 = V_102 ;
V_6 -> V_288 = V_370 ;
break;
case V_371 :
V_6 -> V_75 = V_76 ;
V_6 -> V_288 = V_370 ;
break;
case V_372 :
V_6 -> V_75 = V_76 ;
V_6 -> V_288 = V_289 ;
break;
default:
V_145 = - V_34 ;
}
return V_145 ;
}
static int F_138 ( struct V_373 * V_21 ,
struct V_5 * V_6 )
{
struct V_15 * V_8 = V_6 -> V_8 ;
struct V_374 * V_28 =
* (struct V_374 * * ) F_139 ( V_8 ) ;
struct V_375 * V_376 ;
int V_145 ;
V_376 = (struct V_375 * ) V_28 -> V_377 ;
V_145 = F_137 ( V_376 -> V_288 , V_6 ) ;
if ( V_145 < 0 )
return V_145 ;
V_6 -> V_192 = 1 ;
if ( V_376 -> V_246 & V_378 )
V_6 -> V_105 |= V_317 ;
return 0 ;
}
static inline int F_138 ( struct V_373 * V_21 ,
struct V_5 * V_6 )
{
return - V_34 ;
}
static int F_140 ( struct V_373 * V_21 ,
struct V_5 * V_6 )
{
const struct V_379 * V_23 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
bool V_380 ;
if ( F_141 ( V_8 -> V_9 , L_37 ,
& V_6 -> V_192 ) ) {
F_64 ( V_8 , L_38 ) ;
return - V_34 ;
}
V_23 = F_142 ( V_8 ) ;
V_6 -> V_75 = V_23 -> V_75 ;
V_6 -> V_288 = V_23 -> V_288 ;
F_3 ( V_6 ) ;
V_380 = F_16 ( V_8 -> V_9 , L_2 , NULL ) ;
if ( V_380 && ! V_381 ) {
if ( ! V_197 )
F_143 ( L_39 ) ;
V_197 = true ;
} else if ( ! V_380 && ! V_197 ) {
V_381 = true ;
} else {
F_64 ( V_8 , L_40 ) ;
return - V_34 ;
}
if ( F_144 ( V_8 -> V_9 ) )
V_6 -> V_105 |= V_317 ;
return 0 ;
}
static int F_145 ( struct V_373 * V_21 )
{
struct V_382 * V_383 ;
T_9 V_384 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
int V_385 , V_7 , V_29 ;
V_6 = F_146 ( V_8 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 ) {
F_64 ( V_8 , L_41 ) ;
return - V_42 ;
}
V_6 -> V_8 = V_8 ;
if ( V_8 -> V_9 )
V_29 = F_140 ( V_21 , V_6 ) ;
else
V_29 = F_138 ( V_21 , V_6 ) ;
if ( V_29 )
return V_29 ;
V_383 = F_147 ( V_21 , V_386 , 0 ) ;
V_384 = V_383 -> V_44 ;
V_6 -> V_61 = F_148 ( V_8 , V_383 ) ;
if ( F_88 ( V_6 -> V_61 ) )
return F_89 ( V_6 -> V_61 ) ;
V_6 -> V_66 = F_149 ( V_383 ) ;
V_385 = 0 ;
while ( ( V_383 = F_147 ( V_21 , V_387 , V_385 ) ) ) {
V_385 ++ ;
if ( V_385 > V_6 -> V_192 )
V_6 -> V_182 ++ ;
}
if ( ! V_6 -> V_182 ) {
F_64 ( V_8 , L_42 ,
V_385 , V_6 -> V_192 + 1 ) ;
return - V_34 ;
}
V_6 -> V_191 = F_146 ( V_8 , sizeof( * V_6 -> V_191 ) * V_385 ,
V_41 ) ;
if ( ! V_6 -> V_191 ) {
F_64 ( V_8 , L_43 , V_385 ) ;
return - V_42 ;
}
for ( V_7 = 0 ; V_7 < V_385 ; ++ V_7 ) {
int V_79 = F_150 ( V_21 , V_7 ) ;
if ( V_79 < 0 ) {
F_64 ( V_8 , L_44 , V_7 ) ;
return - V_34 ;
}
V_6 -> V_191 [ V_7 ] = V_79 ;
}
V_29 = F_130 ( V_6 ) ;
if ( V_29 )
return V_29 ;
if ( V_6 -> V_75 == V_76 &&
V_6 -> V_181 != V_6 -> V_182 ) {
F_64 ( V_8 ,
L_45 ,
V_6 -> V_182 , V_6 -> V_181 ) ;
return - V_34 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_192 ; ++ V_7 ) {
V_29 = F_63 ( V_6 -> V_8 , V_6 -> V_191 [ V_7 ] ,
F_50 ,
V_193 ,
L_46 ,
V_6 ) ;
if ( V_29 ) {
F_64 ( V_8 , L_47 ,
V_7 , V_6 -> V_191 [ V_7 ] ) ;
return V_29 ;
}
}
V_29 = F_151 ( & V_6 -> V_266 , V_6 -> V_8 , NULL ,
L_48 , & V_384 ) ;
if ( V_29 ) {
F_64 ( V_8 , L_49 ) ;
return V_29 ;
}
F_152 ( & V_6 -> V_266 , & V_40 ) ;
F_153 ( & V_6 -> V_266 , V_8 -> V_39 ) ;
V_29 = F_154 ( & V_6 -> V_266 ) ;
if ( V_29 ) {
F_64 ( V_8 , L_50 ) ;
return V_29 ;
}
F_155 ( V_21 , V_6 ) ;
F_128 ( V_6 ) ;
F_81 ( V_6 ) ;
if ( ! F_156 ( & V_388 ) )
F_157 ( & V_388 , & V_40 ) ;
#ifdef F_158
if ( ! F_156 ( & V_389 ) )
F_157 ( & V_389 , & V_40 ) ;
#endif
#ifdef F_159
if ( ! F_156 ( & V_390 ) ) {
F_160 () ;
F_157 ( & V_390 , & V_40 ) ;
}
#endif
return 0 ;
}
static int F_161 ( struct V_373 * V_21 )
{
struct V_5 * V_6 = F_162 ( V_21 ) ;
if ( ! V_6 )
return - V_34 ;
if ( ! F_163 ( V_6 -> V_180 , V_391 ) )
F_64 ( & V_21 -> V_8 , L_51 ) ;
F_49 ( V_307 , F_51 ( V_6 ) + V_300 ) ;
return 0 ;
}
static int T_10 F_164 ( void )
{
static bool V_392 ;
int V_145 = 0 ;
if ( ! V_392 ) {
V_145 = F_165 ( & V_35 ) ;
V_392 = ! V_145 ;
}
return V_145 ;
}
static void T_11 F_166 ( void )
{
return F_167 ( & V_35 ) ;
}
static int T_10 F_168 ( struct V_14 * V_27 )
{
int V_145 = F_164 () ;
if ( V_145 )
return V_145 ;
if ( ! F_169 ( V_27 , NULL , V_388 . V_393 ) )
return - V_34 ;
return 0 ;
}
static int T_10 F_170 ( struct V_394 * V_395 )
{
if ( F_171 ( V_396 ) )
return F_164 () ;
return 0 ;
}
