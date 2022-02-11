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
}
if ( V_6 -> V_75 > V_102 )
F_33 ( V_99 , V_82 + V_128 ) ;
} else {
V_69 = V_98 -> V_124 . V_129 ;
}
F_33 ( V_69 , V_82 + V_130 ) ;
if ( V_58 ) {
if ( V_57 -> V_72 == V_116 ) {
V_69 = V_98 -> V_117 . V_131 ;
V_99 = V_98 -> V_117 . V_132 ;
} else {
V_69 = V_98 -> V_122 . V_133 [ 0 ] ;
V_99 = V_98 -> V_122 . V_133 [ 1 ] ;
}
F_33 ( V_69 , V_82 + V_134 ) ;
F_33 ( V_99 , V_82 + V_135 ) ;
}
V_69 = V_136 | V_137 | V_138 | V_139 | V_140 ;
if ( V_58 )
V_69 |= V_141 ;
#ifdef F_56
V_69 |= V_142 ;
#endif
F_33 ( V_69 , V_82 + V_143 ) ;
}
static int F_57 ( struct V_2 * V_4 ,
struct V_5 * V_6 )
{
int V_79 , V_44 , V_144 = 0 ;
unsigned long V_145 , V_146 ;
struct V_147 * V_148 ;
struct V_97 V_98 ;
enum V_149 V_72 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_56 * V_57 = & V_55 -> V_57 ;
F_58 ( & V_55 -> V_150 ) ;
if ( V_55 -> V_6 )
goto V_151;
if ( ! ( V_6 -> V_105 & V_152 ) )
V_55 -> V_153 = V_154 ;
if ( ! ( V_6 -> V_105 & V_155 ) )
V_55 -> V_153 = V_156 ;
if ( V_6 -> V_105 & V_157 )
V_57 -> V_72 = V_158 ;
if ( F_59 ( V_159 ) &&
! F_59 ( V_160 ) && ! F_59 ( V_161 ) &&
( V_6 -> V_105 & V_162 ) &&
( V_55 -> V_153 == V_156 ) )
V_57 -> V_72 = V_116 ;
if ( ( F_59 ( V_160 ) || V_57 -> V_72 == V_163 ) &&
( V_6 -> V_105 & ( V_164 |
V_165 |
V_166 ) ) )
V_57 -> V_72 = V_73 ;
if ( V_57 -> V_72 == V_163 ) {
V_144 = - V_167 ;
goto V_151;
}
switch ( V_55 -> V_153 ) {
case V_156 :
V_57 -> V_59 = V_168 ;
V_44 = V_6 -> V_169 ;
V_145 = V_6 -> V_170 ;
V_146 = V_6 -> V_171 ;
if ( V_57 -> V_72 == V_73 ) {
V_72 = V_172 ;
} else if ( V_57 -> V_72 == V_158 ) {
V_72 = V_173 ;
V_145 = F_60 ( V_145 , 32UL ) ;
V_146 = F_60 ( V_146 , 40UL ) ;
} else {
V_72 = V_174 ;
V_145 = F_60 ( V_145 , 32UL ) ;
V_146 = F_60 ( V_146 , 32UL ) ;
}
break;
case V_175 :
case V_154 :
V_57 -> V_59 = V_60 ;
V_44 = 0 ;
V_145 = V_6 -> V_171 ;
V_146 = V_6 -> V_176 ;
if ( V_57 -> V_72 == V_73 ) {
V_72 = V_177 ;
} else {
V_72 = V_178 ;
V_145 = F_60 ( V_145 , 40UL ) ;
V_146 = F_60 ( V_146 , 40UL ) ;
}
break;
default:
V_144 = - V_167 ;
goto V_151;
}
V_144 = F_26 ( V_6 -> V_179 , V_44 ,
V_6 -> V_180 ) ;
if ( V_144 < 0 )
goto V_151;
V_57 -> V_62 = V_144 ;
if ( V_6 -> V_75 < V_76 ) {
V_57 -> V_108 = F_61 ( & V_6 -> V_108 ) ;
V_57 -> V_108 %= V_6 -> V_181 ;
} else {
V_57 -> V_108 = V_57 -> V_62 ;
}
V_98 = (struct V_97 ) {
. V_182 = V_6 -> V_182 ,
. V_145 = V_145 ,
. V_146 = V_146 ,
. V_183 = & V_184 ,
. V_185 = V_6 -> V_8 ,
} ;
V_55 -> V_6 = V_6 ;
V_148 = F_62 ( V_72 , & V_98 , V_55 ) ;
if ( ! V_148 ) {
V_144 = - V_42 ;
goto V_186;
}
V_4 -> V_182 = V_98 . V_182 ;
V_4 -> V_187 . V_188 = ( 1UL << V_145 ) - 1 ;
V_4 -> V_187 . V_189 = true ;
F_52 ( V_55 , & V_98 ) ;
V_79 = V_6 -> V_190 [ V_6 -> V_191 + V_57 -> V_108 ] ;
V_144 = F_63 ( V_6 -> V_8 , V_79 , F_47 ,
V_192 , L_8 , V_4 ) ;
if ( V_144 < 0 ) {
F_64 ( V_6 -> V_8 , L_9 ,
V_57 -> V_108 , V_79 ) ;
V_57 -> V_108 = V_193 ;
}
F_65 ( & V_55 -> V_150 ) ;
V_55 -> V_148 = V_148 ;
return 0 ;
V_186:
V_55 -> V_6 = NULL ;
V_151:
F_65 ( & V_55 -> V_150 ) ;
return V_144 ;
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
F_33 ( 0 , V_82 + V_143 ) ;
if ( V_57 -> V_108 != V_193 ) {
V_79 = V_6 -> V_190 [ V_6 -> V_191 + V_57 -> V_108 ] ;
F_67 ( V_6 -> V_8 , V_79 , V_4 ) ;
}
F_68 ( V_55 -> V_148 ) ;
F_29 ( V_6 -> V_179 , V_57 -> V_62 ) ;
}
static struct V_2 * F_69 ( unsigned type )
{
struct V_1 * V_55 ;
if ( type != V_194 && type != V_195 )
return NULL ;
V_55 = F_70 ( sizeof( * V_55 ) , V_41 ) ;
if ( ! V_55 )
return NULL ;
if ( type == V_195 && ( V_196 ||
F_71 ( & V_55 -> V_4 ) ) ) {
F_25 ( V_55 ) ;
return NULL ;
}
F_72 ( & V_55 -> V_150 ) ;
F_73 ( & V_55 -> V_197 ) ;
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
struct V_198 * V_199 = V_6 -> V_200 + V_46 ;
T_2 V_69 = V_199 -> V_201 << V_202 | V_199 -> V_203 << V_204 ;
if ( V_199 -> V_205 )
V_69 |= V_206 ;
F_33 ( V_69 , F_32 ( V_6 ) + F_77 ( V_46 ) ) ;
}
static void F_78 ( struct V_5 * V_6 , int V_46 )
{
struct V_207 * V_208 = V_6 -> V_209 + V_46 ;
T_2 V_69 = ( V_208 -> type & V_210 ) << V_211 |
( V_208 -> V_62 & V_212 ) << V_213 |
( V_208 -> V_214 & V_215 ) << V_216 ;
F_33 ( V_69 , F_32 ( V_6 ) + F_79 ( V_46 ) ) ;
}
static void F_80 ( struct V_5 * V_6 , int V_46 )
{
F_78 ( V_6 , V_46 ) ;
if ( V_6 -> V_200 )
F_76 ( V_6 , V_46 ) ;
}
static int F_81 ( struct V_5 * V_6 , T_1 V_201 , T_1 V_203 )
{
struct V_198 * V_200 = V_6 -> V_200 ;
int V_7 , V_217 = - V_47 ;
if ( ! V_200 )
return V_201 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_218 ; ++ V_7 ) {
if ( ! V_200 [ V_7 ] . V_205 ) {
if ( V_217 < 0 )
V_217 = V_7 ;
continue;
}
if ( ( V_203 & V_200 [ V_7 ] . V_203 ) == V_203 &&
! ( ( V_201 ^ V_200 [ V_7 ] . V_201 ) & ~ V_200 [ V_7 ] . V_203 ) )
return V_7 ;
if ( ! ( ( V_201 ^ V_200 [ V_7 ] . V_201 ) & ~ ( V_200 [ V_7 ] . V_203 | V_203 ) ) )
return - V_167 ;
}
return V_217 ;
}
static bool F_82 ( struct V_5 * V_6 , int V_46 )
{
if ( -- V_6 -> V_209 [ V_46 ] . V_48 )
return false ;
V_6 -> V_209 [ V_46 ] = V_219 ;
if ( V_6 -> V_200 )
V_6 -> V_200 [ V_46 ] . V_205 = false ;
return true ;
}
static int F_83 ( struct V_15 * V_8 )
{
struct V_220 * V_221 = V_8 -> V_220 ;
struct V_222 * V_57 = V_221 -> V_223 ;
struct V_5 * V_6 = V_57 -> V_6 ;
struct V_198 * V_200 = V_6 -> V_200 ;
struct V_224 * V_225 ;
int V_7 , V_46 , V_144 ;
F_58 ( & V_6 -> V_226 ) ;
F_84 (fwspec, i, idx) {
T_1 V_227 = V_221 -> V_228 [ V_7 ] ;
T_1 V_203 = V_221 -> V_228 [ V_7 ] >> V_204 ;
if ( V_46 != V_229 ) {
V_144 = - V_230 ;
goto V_231;
}
V_144 = F_81 ( V_6 , V_227 , V_203 ) ;
if ( V_144 < 0 )
goto V_231;
V_46 = V_144 ;
if ( V_200 && V_6 -> V_209 [ V_46 ] . V_48 == 0 ) {
V_200 [ V_46 ] . V_201 = V_227 ;
V_200 [ V_46 ] . V_203 = V_203 ;
V_200 [ V_46 ] . V_205 = true ;
}
V_6 -> V_209 [ V_46 ] . V_48 ++ ;
V_57 -> V_232 [ V_7 ] = ( V_233 ) V_46 ;
}
V_225 = F_85 ( V_8 ) ;
if ( ! V_225 )
V_225 = F_86 ( - V_42 ) ;
if ( F_87 ( V_225 ) ) {
V_144 = F_88 ( V_225 ) ;
goto V_231;
}
F_89 ( V_225 ) ;
F_84 (fwspec, i, idx) {
F_80 ( V_6 , V_46 ) ;
V_6 -> V_209 [ V_46 ] . V_225 = V_225 ;
}
F_65 ( & V_6 -> V_226 ) ;
return 0 ;
V_231:
while ( V_7 -- ) {
F_82 ( V_6 , V_57 -> V_232 [ V_7 ] ) ;
V_57 -> V_232 [ V_7 ] = V_229 ;
}
F_65 ( & V_6 -> V_226 ) ;
return V_144 ;
}
static void F_90 ( struct V_220 * V_221 )
{
struct V_5 * V_6 = F_91 ( V_221 ) ;
struct V_222 * V_57 = V_221 -> V_223 ;
int V_7 , V_46 ;
F_58 ( & V_6 -> V_226 ) ;
F_84 (fwspec, i, idx) {
if ( F_82 ( V_6 , V_46 ) )
F_80 ( V_6 , V_46 ) ;
V_57 -> V_232 [ V_7 ] = V_229 ;
}
F_65 ( & V_6 -> V_226 ) ;
}
static int F_92 ( struct V_1 * V_55 ,
struct V_220 * V_221 )
{
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_207 * V_208 = V_6 -> V_209 ;
enum V_234 type = V_235 ;
T_6 V_62 = V_55 -> V_57 . V_62 ;
int V_7 , V_46 ;
F_84 (fwspec, i, idx) {
if ( type == V_208 [ V_46 ] . type && V_62 == V_208 [ V_46 ] . V_62 )
continue;
V_208 [ V_46 ] . type = type ;
V_208 [ V_46 ] . V_214 = V_236 ;
V_208 [ V_46 ] . V_62 = V_62 ;
F_78 ( V_6 , V_46 ) ;
}
return 0 ;
}
static int F_93 ( struct V_2 * V_4 , struct V_15 * V_8 )
{
int V_144 ;
struct V_220 * V_221 = V_8 -> V_220 ;
struct V_5 * V_6 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
if ( ! V_221 || V_221 -> V_237 != & V_40 ) {
F_64 ( V_8 , L_10 ) ;
return - V_238 ;
}
if ( ! V_221 -> V_223 )
return - V_34 ;
V_6 = F_91 ( V_221 ) ;
V_144 = F_57 ( V_4 , V_6 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_55 -> V_6 != V_6 ) {
F_64 ( V_8 ,
L_11 ,
F_94 ( V_55 -> V_6 -> V_8 ) , F_94 ( V_6 -> V_8 ) ) ;
return - V_167 ;
}
return F_92 ( V_55 , V_221 ) ;
}
static int F_95 ( struct V_2 * V_4 , unsigned long V_65 ,
T_7 V_239 , T_4 V_66 , int V_240 )
{
int V_144 ;
unsigned long V_241 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_147 * V_237 = V_55 -> V_148 ;
if ( ! V_237 )
return - V_34 ;
F_96 ( & V_55 -> V_197 , V_241 ) ;
V_144 = V_237 -> V_43 ( V_237 , V_65 , V_239 , V_66 , V_240 ) ;
F_97 ( & V_55 -> V_197 , V_241 ) ;
return V_144 ;
}
static T_4 F_98 ( struct V_2 * V_4 , unsigned long V_65 ,
T_4 V_66 )
{
T_4 V_144 ;
unsigned long V_241 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_147 * V_237 = V_55 -> V_148 ;
if ( ! V_237 )
return 0 ;
F_96 ( & V_55 -> V_197 , V_241 ) ;
V_144 = V_237 -> V_242 ( V_237 , V_65 , V_66 ) ;
F_97 ( & V_55 -> V_197 , V_241 ) ;
return V_144 ;
}
static T_7 F_99 ( struct V_2 * V_4 ,
T_8 V_65 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_5 * V_6 = V_55 -> V_6 ;
struct V_56 * V_57 = & V_55 -> V_57 ;
struct V_147 * V_237 = V_55 -> V_148 ;
struct V_15 * V_8 = V_6 -> V_8 ;
void T_3 * V_82 ;
T_2 V_243 ;
V_74 V_244 ;
unsigned long V_245 ;
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_57 -> V_62 ) ;
V_245 = V_65 & ~ 0xfffUL ;
if ( V_6 -> V_75 == V_76 )
F_46 ( V_245 , V_82 + V_246 ) ;
else
F_33 ( V_245 , V_82 + V_246 ) ;
if ( F_100 ( V_82 + V_247 , V_243 ,
! ( V_243 & V_248 ) , 5 , 50 ) ) {
F_64 ( V_8 ,
L_12 ,
& V_65 ) ;
return V_237 -> V_249 ( V_237 , V_65 ) ;
}
V_244 = F_48 ( V_82 + V_250 ) ;
if ( V_244 & V_251 ) {
F_64 ( V_8 , L_13 ) ;
F_64 ( V_8 , L_14 , V_244 ) ;
return 0 ;
}
return ( V_244 & F_101 ( 39 , 12 ) ) | ( V_65 & 0xfff ) ;
}
static T_7 F_102 ( struct V_2 * V_4 ,
T_8 V_65 )
{
T_7 V_144 ;
unsigned long V_241 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
struct V_147 * V_237 = V_55 -> V_148 ;
if ( ! V_237 )
return 0 ;
F_96 ( & V_55 -> V_197 , V_241 ) ;
if ( V_55 -> V_6 -> V_105 & V_252 &&
V_55 -> V_153 == V_156 ) {
V_144 = F_99 ( V_4 , V_65 ) ;
} else {
V_144 = V_237 -> V_249 ( V_237 , V_65 ) ;
}
F_97 ( & V_55 -> V_197 , V_241 ) ;
return V_144 ;
}
static bool F_103 ( enum V_253 V_254 )
{
switch ( V_254 ) {
case V_255 :
return true ;
case V_256 :
return true ;
case V_257 :
return true ;
default:
return false ;
}
}
static int F_104 ( struct V_15 * V_8 , void * V_23 )
{
return V_8 -> V_9 == V_23 ;
}
static struct V_5 * F_105 ( struct V_14 * V_27 )
{
struct V_15 * V_8 = F_106 ( & V_35 . V_36 , NULL ,
V_27 , F_104 ) ;
F_107 ( V_8 ) ;
return V_8 ? F_22 ( V_8 ) : NULL ;
}
static int F_108 ( struct V_15 * V_8 )
{
struct V_5 * V_6 ;
struct V_222 * V_57 ;
struct V_220 * V_221 = V_8 -> V_220 ;
int V_7 , V_144 ;
if ( V_196 ) {
V_144 = F_15 ( V_8 , & V_6 ) ;
V_221 = V_8 -> V_220 ;
if ( V_144 )
goto V_258;
} else if ( V_221 && V_221 -> V_237 == & V_40 ) {
V_6 = F_105 ( F_109 ( V_221 -> V_259 ) ) ;
} else {
return - V_34 ;
}
V_144 = - V_167 ;
for ( V_7 = 0 ; V_7 < V_221 -> V_260 ; V_7 ++ ) {
T_1 V_227 = V_221 -> V_228 [ V_7 ] ;
T_1 V_203 = V_221 -> V_228 [ V_7 ] >> V_204 ;
if ( V_227 & ~ V_6 -> V_261 ) {
F_64 ( V_8 , L_15 ,
V_227 , V_6 -> V_261 ) ;
goto V_258;
}
if ( V_203 & ~ V_6 -> V_262 ) {
F_64 ( V_8 , L_16 ,
V_227 , V_6 -> V_262 ) ;
goto V_258;
}
}
V_144 = - V_42 ;
V_57 = F_70 ( F_110 ( struct V_222 , V_232 [ V_7 ] ) ,
V_41 ) ;
if ( ! V_57 )
goto V_258;
V_57 -> V_6 = V_6 ;
V_221 -> V_223 = V_57 ;
while ( V_7 -- )
V_57 -> V_232 [ V_7 ] = V_229 ;
V_144 = F_83 ( V_8 ) ;
if ( V_144 )
goto V_258;
return 0 ;
V_258:
if ( V_221 )
F_25 ( V_221 -> V_223 ) ;
F_111 ( V_8 ) ;
return V_144 ;
}
static void F_112 ( struct V_15 * V_8 )
{
struct V_220 * V_221 = V_8 -> V_220 ;
if ( ! V_221 || V_221 -> V_237 != & V_40 )
return;
F_90 ( V_221 ) ;
F_113 ( V_8 ) ;
F_25 ( V_221 -> V_223 ) ;
F_111 ( V_8 ) ;
}
static struct V_224 * F_114 ( struct V_15 * V_8 )
{
struct V_220 * V_221 = V_8 -> V_220 ;
struct V_5 * V_6 = F_91 ( V_221 ) ;
struct V_224 * V_225 = NULL ;
int V_7 , V_46 ;
F_84 (fwspec, i, idx) {
if ( V_225 && V_6 -> V_209 [ V_46 ] . V_225 &&
V_225 != V_6 -> V_209 [ V_46 ] . V_225 )
return F_86 ( - V_167 ) ;
V_225 = V_6 -> V_209 [ V_46 ] . V_225 ;
}
if ( V_225 )
return V_225 ;
if ( F_7 ( V_8 ) )
V_225 = F_115 ( V_8 ) ;
else
V_225 = F_116 ( V_8 ) ;
return V_225 ;
}
static int F_117 ( struct V_2 * V_4 ,
enum V_263 V_264 , void * V_23 )
{
struct V_1 * V_55 = F_1 ( V_4 ) ;
switch ( V_264 ) {
case V_265 :
* ( int * ) V_23 = ( V_55 -> V_153 == V_175 ) ;
return 0 ;
default:
return - V_34 ;
}
}
static int F_118 ( struct V_2 * V_4 ,
enum V_263 V_264 , void * V_23 )
{
int V_144 = 0 ;
struct V_1 * V_55 = F_1 ( V_4 ) ;
F_58 ( & V_55 -> V_150 ) ;
switch ( V_264 ) {
case V_265 :
if ( V_55 -> V_6 ) {
V_144 = - V_266 ;
goto V_151;
}
if ( * ( int * ) V_23 )
V_55 -> V_153 = V_175 ;
else
V_55 -> V_153 = V_156 ;
break;
default:
V_144 = - V_34 ;
}
V_151:
F_65 ( & V_55 -> V_150 ) ;
return V_144 ;
}
static int F_119 ( struct V_15 * V_8 , struct V_267 * args )
{
T_2 V_268 = 0 ;
if ( args -> V_269 > 0 )
V_268 |= ( T_1 ) args -> args [ 0 ] ;
if ( args -> V_269 > 1 )
V_268 |= ( T_1 ) args -> args [ 1 ] << V_204 ;
return F_24 ( V_8 , & V_268 , 1 ) ;
}
static void F_120 ( struct V_5 * V_6 )
{
void T_3 * V_49 = F_32 ( V_6 ) ;
void T_3 * V_82 ;
int V_7 ;
T_2 V_69 , V_270 ;
V_69 = F_34 ( F_51 ( V_6 ) + V_93 ) ;
F_49 ( V_69 , F_51 ( V_6 ) + V_93 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_218 ; ++ V_7 )
F_80 ( V_6 , V_7 ) ;
V_69 = F_34 ( V_49 + V_271 ) ;
V_270 = ( V_69 >> V_272 ) & V_273 ;
if ( ( V_6 -> V_274 == V_275 ) && ( V_270 >= 2 ) ) {
V_69 = F_34 ( V_49 + V_276 ) ;
V_69 &= ~ V_277 ;
F_33 ( V_69 , V_49 + V_276 ) ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_180 ; ++ V_7 ) {
V_82 = F_40 ( V_6 ) + F_41 ( V_6 , V_7 ) ;
F_33 ( 0 , V_82 + V_143 ) ;
F_33 ( V_84 , V_82 + V_83 ) ;
if ( V_6 -> V_274 == V_275 ) {
V_69 = F_34 ( V_82 + V_278 ) ;
V_69 &= ~ V_279 ;
F_33 ( V_69 , V_82 + V_278 ) ;
}
}
F_33 ( 0 , V_49 + V_280 ) ;
F_33 ( 0 , V_49 + V_281 ) ;
V_69 = F_34 ( F_51 ( V_6 ) + V_282 ) ;
V_69 |= ( V_283 | V_284 | V_285 | V_286 ) ;
V_69 |= ( V_287 | V_288 ) ;
V_69 &= ~ V_289 ;
if ( V_290 )
V_69 |= V_291 ;
else
V_69 &= ~ V_291 ;
V_69 &= ~ V_292 ;
V_69 &= ~ ( V_293 << V_294 ) ;
if ( V_6 -> V_105 & V_106 )
V_69 |= V_295 ;
F_31 ( V_6 ) ;
F_49 ( V_69 , F_51 ( V_6 ) + V_282 ) ;
}
static int F_121 ( int V_66 )
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
static int F_122 ( struct V_5 * V_6 )
{
unsigned long V_66 ;
void T_3 * V_49 = F_32 ( V_6 ) ;
T_2 V_201 ;
bool V_296 , V_297 ;
int V_7 ;
F_5 ( V_6 -> V_8 , L_17 ) ;
F_5 ( V_6 -> V_8 , L_18 ,
V_6 -> V_75 == V_76 ? 2 : 1 ) ;
V_201 = F_34 ( V_49 + V_298 ) ;
if ( V_299 == 1 )
V_201 &= ~ ( V_300 | V_301 ) ;
else if ( V_299 == 2 )
V_201 &= ~ ( V_302 | V_301 ) ;
if ( V_201 & V_302 ) {
V_6 -> V_105 |= V_152 ;
F_5 ( V_6 -> V_8 , L_19 ) ;
}
if ( V_201 & V_300 ) {
V_6 -> V_105 |= V_155 ;
F_5 ( V_6 -> V_8 , L_20 ) ;
}
if ( V_201 & V_301 ) {
V_6 -> V_105 |= V_303 ;
F_5 ( V_6 -> V_8 , L_21 ) ;
}
if ( ! ( V_6 -> V_105 &
( V_152 | V_155 ) ) ) {
F_64 ( V_6 -> V_8 , L_22 ) ;
return - V_34 ;
}
if ( ( V_201 & V_302 ) &&
( ( V_6 -> V_75 < V_76 ) || ! ( V_201 & V_304 ) ) ) {
V_6 -> V_105 |= V_252 ;
F_5 ( V_6 -> V_8 , L_23 ) ;
}
V_296 = F_123 ( V_6 -> V_8 -> V_9 ) ;
V_297 = ! ! ( V_201 & V_305 ) ;
if ( V_296 )
V_6 -> V_105 |= V_306 ;
if ( V_296 || V_297 )
F_5 ( V_6 -> V_8 , L_24 ,
V_296 ? L_25 : L_26 ) ;
if ( V_296 != V_297 )
F_5 ( V_6 -> V_8 ,
L_27 ) ;
V_66 = 1 << ( ( V_201 >> V_307 ) & V_308 ) ;
V_6 -> V_261 = V_66 - 1 ;
if ( V_201 & V_309 ) {
T_2 V_199 ;
V_6 -> V_105 |= V_310 ;
V_66 = ( V_201 >> V_311 ) & V_312 ;
if ( V_66 == 0 ) {
F_64 ( V_6 -> V_8 ,
L_28 ) ;
return - V_34 ;
}
V_199 = V_6 -> V_261 << V_202 ;
F_33 ( V_199 , V_49 + F_77 ( 0 ) ) ;
V_199 = F_34 ( V_49 + F_77 ( 0 ) ) ;
V_6 -> V_261 = V_199 >> V_202 ;
V_199 = V_6 -> V_261 << V_204 ;
F_33 ( V_199 , V_49 + F_77 ( 0 ) ) ;
V_199 = F_34 ( V_49 + F_77 ( 0 ) ) ;
V_6 -> V_262 = V_199 >> V_204 ;
V_6 -> V_200 = F_124 ( V_6 -> V_8 , V_66 , sizeof( * V_6 -> V_200 ) ,
V_41 ) ;
if ( ! V_6 -> V_200 )
return - V_42 ;
F_5 ( V_6 -> V_8 ,
L_29 ,
V_66 , V_6 -> V_262 ) ;
}
V_6 -> V_209 = F_125 ( V_6 -> V_8 , V_66 , sizeof( * V_6 -> V_209 ) ,
V_41 ) ;
if ( ! V_6 -> V_209 )
return - V_42 ;
for ( V_7 = 0 ; V_7 < V_66 ; V_7 ++ )
V_6 -> V_209 [ V_7 ] = V_219 ;
V_6 -> V_218 = V_66 ;
F_72 ( & V_6 -> V_226 ) ;
if ( V_6 -> V_75 < V_76 || ! ( V_201 & V_313 ) ) {
V_6 -> V_105 |= V_157 ;
if ( ! ( V_201 & V_314 ) )
V_6 -> V_105 |= V_162 ;
}
V_201 = F_34 ( V_49 + V_315 ) ;
V_6 -> V_316 = ( V_201 & V_317 ) ? 16 : 12 ;
V_66 = 1 << ( ( ( V_201 >> V_318 ) & V_319 ) + 1 ) ;
V_66 *= 2 << V_6 -> V_316 ;
if ( V_6 -> V_66 != V_66 )
F_126 ( V_6 -> V_8 ,
L_30 ,
V_66 , V_6 -> V_66 ) ;
V_6 -> V_169 = ( V_201 >> V_320 ) & V_321 ;
V_6 -> V_180 = ( V_201 >> V_322 ) & V_323 ;
if ( V_6 -> V_169 > V_6 -> V_180 ) {
F_64 ( V_6 -> V_8 , L_31 ) ;
return - V_34 ;
}
F_5 ( V_6 -> V_8 , L_32 ,
V_6 -> V_180 , V_6 -> V_169 ) ;
if ( V_6 -> V_274 == V_324 ) {
V_6 -> V_325 =
F_127 ( V_6 -> V_180 ,
& V_326 ) ;
V_6 -> V_325 -= V_6 -> V_180 ;
}
V_201 = F_34 ( V_49 + V_327 ) ;
V_66 = F_121 ( ( V_201 >> V_328 ) & V_329 ) ;
V_6 -> V_171 = V_66 ;
V_66 = F_121 ( ( V_201 >> V_330 ) & V_331 ) ;
V_6 -> V_176 = V_66 ;
if ( V_201 & V_332 )
V_6 -> V_105 |= V_106 ;
if ( F_128 ( V_6 -> V_8 , F_129 ( V_66 ) ) )
F_126 ( V_6 -> V_8 ,
L_33 ) ;
if ( V_6 -> V_75 < V_76 ) {
V_6 -> V_170 = V_6 -> V_171 ;
if ( V_6 -> V_75 == V_333 )
V_6 -> V_105 |= V_164 ;
} else {
V_66 = ( V_201 >> V_334 ) & V_335 ;
V_6 -> V_170 = F_121 ( V_66 ) ;
if ( V_201 & V_336 )
V_6 -> V_105 |= V_166 ;
if ( V_201 & V_337 )
V_6 -> V_105 |= V_165 ;
if ( V_201 & V_338 )
V_6 -> V_105 |= V_164 ;
}
if ( V_6 -> V_105 & V_162 )
V_6 -> V_182 |= V_339 | V_340 | V_341 | V_342 ;
if ( V_6 -> V_105 &
( V_157 | V_166 ) )
V_6 -> V_182 |= V_339 | V_343 | V_344 ;
if ( V_6 -> V_105 & V_165 )
V_6 -> V_182 |= V_345 | V_346 ;
if ( V_6 -> V_105 & V_164 )
V_6 -> V_182 |= V_340 | V_347 ;
if ( V_40 . V_182 == - 1UL )
V_40 . V_182 = V_6 -> V_182 ;
else
V_40 . V_182 |= V_6 -> V_182 ;
F_5 ( V_6 -> V_8 , L_34 ,
V_6 -> V_182 ) ;
if ( V_6 -> V_105 & V_152 )
F_5 ( V_6 -> V_8 , L_35 ,
V_6 -> V_170 , V_6 -> V_171 ) ;
if ( V_6 -> V_105 & V_155 )
F_5 ( V_6 -> V_8 , L_36 ,
V_6 -> V_171 , V_6 -> V_176 ) ;
return 0 ;
}
static int F_130 ( struct V_348 * V_21 )
{
const struct V_349 * V_23 ;
struct V_350 * V_351 ;
struct V_5 * V_6 ;
struct V_15 * V_8 = & V_21 -> V_8 ;
int V_352 , V_7 , V_29 ;
bool V_353 ;
V_353 = F_16 ( V_8 -> V_9 , L_2 , NULL ) ;
if ( V_353 && ! V_354 ) {
if ( ! V_196 )
F_131 ( L_37 ) ;
V_196 = true ;
} else if ( ! V_353 && ! V_196 ) {
V_354 = true ;
} else {
F_64 ( V_8 , L_38 ) ;
return - V_34 ;
}
V_6 = F_132 ( V_8 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 ) {
F_64 ( V_8 , L_39 ) ;
return - V_42 ;
}
V_6 -> V_8 = V_8 ;
V_23 = F_133 ( V_8 ) ;
V_6 -> V_75 = V_23 -> V_75 ;
V_6 -> V_274 = V_23 -> V_274 ;
V_351 = F_134 ( V_21 , V_355 , 0 ) ;
V_6 -> V_61 = F_135 ( V_8 , V_351 ) ;
if ( F_87 ( V_6 -> V_61 ) )
return F_88 ( V_6 -> V_61 ) ;
V_6 -> V_66 = F_136 ( V_351 ) ;
if ( F_137 ( V_8 -> V_9 , L_40 ,
& V_6 -> V_191 ) ) {
F_64 ( V_8 , L_41 ) ;
return - V_34 ;
}
V_352 = 0 ;
while ( ( V_351 = F_134 ( V_21 , V_356 , V_352 ) ) ) {
V_352 ++ ;
if ( V_352 > V_6 -> V_191 )
V_6 -> V_181 ++ ;
}
if ( ! V_6 -> V_181 ) {
F_64 ( V_8 , L_42 ,
V_352 , V_6 -> V_191 + 1 ) ;
return - V_34 ;
}
V_6 -> V_190 = F_132 ( V_8 , sizeof( * V_6 -> V_190 ) * V_352 ,
V_41 ) ;
if ( ! V_6 -> V_190 ) {
F_64 ( V_8 , L_43 , V_352 ) ;
return - V_42 ;
}
for ( V_7 = 0 ; V_7 < V_352 ; ++ V_7 ) {
int V_79 = F_138 ( V_21 , V_7 ) ;
if ( V_79 < 0 ) {
F_64 ( V_8 , L_44 , V_7 ) ;
return - V_34 ;
}
V_6 -> V_190 [ V_7 ] = V_79 ;
}
V_29 = F_122 ( V_6 ) ;
if ( V_29 )
return V_29 ;
F_3 ( V_6 ) ;
if ( V_6 -> V_75 == V_76 &&
V_6 -> V_180 != V_6 -> V_181 ) {
F_64 ( V_8 ,
L_45 ,
V_6 -> V_181 , V_6 -> V_180 ) ;
return - V_34 ;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_191 ; ++ V_7 ) {
V_29 = F_63 ( V_6 -> V_8 , V_6 -> V_190 [ V_7 ] ,
F_50 ,
V_192 ,
L_46 ,
V_6 ) ;
if ( V_29 ) {
F_64 ( V_8 , L_47 ,
V_7 , V_6 -> V_190 [ V_7 ] ) ;
return V_29 ;
}
}
F_139 ( V_8 -> V_9 , & V_40 ) ;
F_140 ( V_21 , V_6 ) ;
F_120 ( V_6 ) ;
if ( ! F_141 ( & V_357 ) )
F_142 ( & V_357 , & V_40 ) ;
#ifdef F_143
if ( ! F_141 ( & V_358 ) )
F_142 ( & V_358 , & V_40 ) ;
#endif
#ifdef F_144
if ( ! F_141 ( & V_359 ) ) {
F_145 () ;
F_142 ( & V_359 , & V_40 ) ;
}
#endif
return 0 ;
}
static int F_146 ( struct V_348 * V_21 )
{
struct V_5 * V_6 = F_147 ( V_21 ) ;
if ( ! V_6 )
return - V_34 ;
if ( ! F_148 ( V_6 -> V_179 , V_360 ) )
F_64 ( & V_21 -> V_8 , L_48 ) ;
F_49 ( V_289 , F_51 ( V_6 ) + V_282 ) ;
return 0 ;
}
static int T_9 F_149 ( void )
{
static bool V_361 ;
int V_144 = 0 ;
if ( ! V_361 ) {
V_144 = F_150 ( & V_35 ) ;
V_361 = ! V_144 ;
}
return V_144 ;
}
static void T_10 F_151 ( void )
{
return F_152 ( & V_35 ) ;
}
static int T_9 F_153 ( struct V_14 * V_27 )
{
int V_144 = F_149 () ;
if ( V_144 )
return V_144 ;
if ( ! F_154 ( V_27 , NULL , V_357 . V_362 ) )
return - V_34 ;
return 0 ;
}
