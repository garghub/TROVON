static void F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_5 ;
#if ! F_2 ( V_6 )
T_1 V_7 = 0 ;
#endif
if ( V_8 ) {
V_4 = V_9 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
if ( V_4 ) {
if ( V_4 -> V_11 ) {
F_3 ( V_4 -> V_11 ) ;
V_4 -> V_11 = NULL ;
}
V_4 = V_4 -> V_12 ;
}
}
F_4 ( V_7 , V_8 , V_10 ) ;
}
if ( V_13 ) {
V_2 = V_14 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
if ( V_2 ) {
if ( V_2 -> V_11 ) {
F_3 ( V_2 -> V_11 ) ;
V_2 -> V_11 = NULL ;
}
V_2 = V_2 -> V_12 ;
}
}
F_4 ( V_7 , V_13 , V_15 ) ;
}
}
static int F_5 ( struct V_16 * V_17 )
{
int V_5 ;
struct V_18 * V_19 ;
#if ! F_2 ( V_6 )
T_1 V_7 ;
#endif
V_8 = F_6 ( & V_7 ,
sizeof( struct V_3 ) ,
V_10 ) ;
if ( V_8 == NULL )
goto V_20;
V_13 = F_6 ( & V_7 ,
sizeof( struct V_1 ) ,
V_15 ) ;
if ( V_13 == NULL )
goto V_20;
V_9 = V_21 = V_8 ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
struct V_3 * V_4 = V_8 + V_5 ;
struct V_22 * V_23 = & ( V_4 -> V_24 ) ;
struct V_22 * V_25 = & ( V_4 -> V_26 ) ;
V_23 -> V_27 = V_28 | V_29 | V_30 ;
V_23 -> V_31 = ( unsigned long ) V_4 -> V_32 ;
V_23 -> V_33 = 0 ;
V_23 -> V_34 = V_25 ;
V_25 -> V_27 = V_35 | V_36 | V_28 | V_29 | V_30 ;
V_25 -> V_31 = ( unsigned long ) ( & ( V_4 -> V_37 ) ) ;
V_25 -> V_33 = 0 ;
V_4 -> V_11 = NULL ;
V_21 -> V_26 . V_34 = V_23 ;
V_21 -> V_12 = V_4 ;
V_21 = V_4 ;
}
V_21 -> V_12 = V_9 ;
V_21 -> V_26 . V_34 = & ( V_9 -> V_24 ) ;
V_38 = V_9 ;
V_14 = V_39 = V_13 ;
for ( V_5 = 0 ; V_5 < V_15 ; V_5 ++ ) {
struct V_1 * V_2 = V_13 + V_5 ;
struct V_22 * V_23 = & ( V_2 -> V_24 ) ;
struct V_22 * V_25 = & ( V_2 -> V_26 ) ;
V_19 = F_7 ( V_17 , V_40 + V_41 ) ;
if ( ! V_19 ) {
F_8 ( L_1 ) ;
goto V_20;
}
F_9 ( V_19 , V_41 ) ;
F_10 ( ( unsigned long ) V_19 -> V_42 ,
( unsigned long ) V_19 -> V_43 ) ;
V_2 -> V_11 = V_19 ;
V_23 -> V_27 = V_35 | V_36 | V_28 | V_29 | V_30 ;
V_23 -> V_31 = ( unsigned long ) V_19 -> V_44 - 2 ;
V_23 -> V_33 = 0 ;
V_23 -> V_34 = V_25 ;
V_25 -> V_27 = V_35 | V_36 | V_28 | V_45 |
V_29 | V_30 ;
V_25 -> V_31 = ( unsigned long ) ( & ( V_2 -> V_37 ) ) ;
V_25 -> V_33 = 0 ;
V_39 -> V_26 . V_34 = V_23 ;
V_39 -> V_12 = V_2 ;
V_39 = V_2 ;
}
V_39 -> V_12 = V_14 ;
V_39 -> V_26 . V_34 = & ( V_14 -> V_24 ) ;
V_46 = V_14 ;
return 0 ;
V_20:
F_1 () ;
F_11 ( L_2 ) ;
return - V_47 ;
}
static int F_12 ( void )
{
int V_48 = V_49 ;
while ( ( F_13 () ) & V_50 ) {
F_14 ( 1 ) ;
if ( V_48 -- < 0 ) {
F_11 ( L_3 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_15 ( struct V_52 * V_53 , int V_54 , int V_55 )
{
int V_56 ;
V_56 = F_12 () ;
if ( V_56 )
return V_56 ;
F_16 ( F_17 ( ( V_57 ) V_54 ) |
F_18 ( ( V_57 ) V_55 ) |
V_50 ) ;
V_56 = F_12 () ;
if ( V_56 )
return V_56 ;
return ( int ) F_19 () ;
}
static int F_20 ( struct V_52 * V_53 , int V_54 , int V_55 ,
V_57 V_58 )
{
int V_56 ;
V_56 = F_12 () ;
if ( V_56 )
return V_56 ;
F_21 ( ( V_59 ) V_58 ) ;
F_16 ( F_17 ( ( V_57 ) V_54 ) |
F_18 ( ( V_57 ) V_55 ) |
V_60 |
V_50 ) ;
return F_12 () ;
}
static int F_22 ( struct V_52 * V_53 )
{
return 0 ;
}
static void F_23 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
struct V_63 * V_64 = V_62 -> V_64 ;
unsigned long V_65 ;
int V_66 = 0 ;
F_25 ( & V_62 -> V_67 , V_65 ) ;
if ( V_64 -> V_68 ) {
if ( V_64 -> V_69 != V_62 -> V_70 ) {
V_59 V_71 = F_26 () ;
V_66 = 1 ;
if ( V_64 -> V_69 )
V_71 |= V_72 ;
else
V_71 &= ~ ( V_72 ) ;
F_27 ( V_71 ) ;
V_62 -> V_70 = V_64 -> V_69 ;
}
if ( V_64 -> V_73 != V_62 -> V_74 ) {
if ( V_64 -> V_75 == V_76 ) {
V_59 V_71 = F_26 () ;
switch ( V_64 -> V_73 ) {
case 10 :
V_71 |= V_77 ;
break;
case 100 :
V_71 &= ~ V_77 ;
break;
default:
F_28 ( V_17 ,
L_4 ,
V_64 -> V_73 ) ;
break;
}
F_27 ( V_71 ) ;
}
V_66 = 1 ;
V_62 -> V_74 = V_64 -> V_73 ;
}
if ( ! V_62 -> V_78 ) {
V_66 = 1 ;
V_62 -> V_78 = 1 ;
}
} else if ( V_62 -> V_78 ) {
V_66 = 1 ;
V_62 -> V_78 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_70 = - 1 ;
}
if ( V_66 ) {
V_59 V_71 = F_26 () ;
F_29 ( V_64 ) ;
F_30 ( L_5 , V_71 ) ;
}
F_31 ( & V_62 -> V_67 , V_65 ) ;
}
static int F_32 ( struct V_16 * V_17 , int V_79 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
struct V_63 * V_64 = NULL ;
unsigned short V_80 ;
int V_5 ;
V_59 V_81 , V_82 ;
if ( ! ( F_33 () & V_83 ) )
F_34 ( F_33 () | V_83 ) ;
V_81 = F_35 () ;
V_82 = ( ( V_81 / V_84 ) / 2 ) - 1 ;
V_80 = F_36 () ;
V_80 = ( V_80 & ~ V_85 ) | F_37 ( V_82 ) ;
F_38 ( V_80 ) ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 ) {
struct V_63 * const V_87 = V_62 -> V_52 -> V_88 [ V_5 ] ;
if ( ! V_87 )
continue;
V_64 = V_87 ;
break;
}
if ( ! V_64 ) {
F_39 ( V_17 , L_6 ) ;
return - V_89 ;
}
if ( V_79 != V_76 &&
V_79 != V_90 ) {
F_39 ( V_17 , L_7 ) ;
return - V_91 ;
}
V_64 = F_40 ( V_17 , F_41 ( & V_64 -> V_17 ) ,
& F_23 , V_79 ) ;
if ( F_42 ( V_64 ) ) {
F_39 ( V_17 , L_8 ) ;
return F_43 ( V_64 ) ;
}
V_64 -> V_92 &= ( V_93
| V_94
| V_95
| V_96
| V_97
| V_98 | V_99
| V_100
| V_101 ) ;
V_64 -> V_102 = V_64 -> V_92 ;
V_62 -> V_78 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_70 = - 1 ;
V_62 -> V_64 = V_64 ;
F_44 ( L_9
L_10 ,
V_64 -> V_103 -> V_104 , F_41 ( & V_64 -> V_17 ) , V_64 -> V_105 ,
V_84 , V_82 , V_81 / 1000000 ) ;
return 0 ;
}
static T_2 F_45 ( int V_105 , void * V_106 )
{
return V_107 ;
}
static int
F_46 ( struct V_16 * V_17 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
if ( V_62 -> V_64 )
return F_47 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static int
F_48 ( struct V_16 * V_17 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
if ( ! F_49 ( V_110 ) )
return - V_111 ;
if ( V_62 -> V_64 )
return F_50 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static void F_51 ( struct V_16 * V_17 ,
struct V_112 * V_113 )
{
F_52 ( V_113 -> V_114 , V_115 , sizeof( V_113 -> V_114 ) ) ;
F_52 ( V_113 -> V_116 , V_117 , sizeof( V_113 -> V_116 ) ) ;
F_52 ( V_113 -> V_118 , L_11 , sizeof( V_113 -> V_118 ) ) ;
F_52 ( V_113 -> V_119 , F_41 ( & V_17 -> V_17 ) , sizeof( V_113 -> V_119 ) ) ;
}
static void F_53 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
V_121 -> V_92 = V_122 ;
V_121 -> V_123 = V_62 -> V_124 ;
}
static int F_54 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
int V_125 ;
if ( V_121 -> V_123 & ( V_126 |
V_127 |
V_128 |
V_129 |
V_130 ) )
return - V_131 ;
V_62 -> V_124 = V_121 -> V_123 ;
if ( V_62 -> V_124 && ! V_62 -> V_132 ) {
V_125 = F_55 ( V_133 , F_45 ,
V_134 , L_12 , V_17 ) ;
if ( V_125 )
return V_125 ;
V_62 -> V_132 = true ;
}
if ( ! V_62 -> V_124 && V_62 -> V_132 ) {
F_56 ( V_133 , V_17 ) ;
V_62 -> V_132 = false ;
}
F_57 ( & V_17 -> V_17 , V_62 -> V_124 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 ,
struct V_135 * V_113 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
V_113 -> V_136 =
V_137 |
V_138 |
V_139 ;
V_113 -> V_140 = V_62 -> V_140 ;
V_113 -> V_141 =
( 1 << V_142 ) |
( 1 << V_143 ) ;
V_113 -> V_144 =
( 1 << V_145 ) |
( 1 << V_146 ) |
( 1 << V_147 ) |
( 1 << V_148 ) ;
return 0 ;
}
static void F_59 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
int V_5 ;
unsigned short V_80 ;
V_80 = F_36 () ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 )
if ( V_62 -> V_52 -> V_105 [ V_5 ] != V_149 )
break;
if ( V_5 < V_86 )
V_80 |= V_150 ;
V_80 |= V_151 ;
#if F_2 ( V_152 )
V_80 |= V_153 ;
#else
V_80 &= ~ V_153 ;
#endif
F_38 ( V_80 ) ;
F_60 ( V_154 | V_155 ) ;
F_61 ( V_62 -> V_156 ) ;
F_62 ( V_62 -> V_157 ) ;
F_63 ( 0 ) ;
F_64 ( 4 ) ;
F_65 ( 0 ) ;
F_66 ( 0 ) ;
F_67 ( 0 ) ;
F_68 ( 4 ) ;
F_69 ( 0 ) ;
F_70 ( 0 ) ;
}
static void F_71 ( T_3 * V_158 )
{
V_59 V_159 = F_72 ( * ( V_160 * ) & V_158 [ 0 ] ) ;
V_57 V_161 = F_73 ( * ( V_162 * ) & V_158 [ 4 ] ) ;
F_74 ( V_159 ) ;
F_75 ( V_161 ) ;
}
static int F_76 ( struct V_16 * V_17 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
if ( F_77 ( V_17 ) )
return - V_166 ;
memcpy ( V_17 -> V_167 , V_165 -> V_168 , V_17 -> V_169 ) ;
F_71 ( V_17 -> V_167 ) ;
return 0 ;
}
static V_59 F_78 ( V_59 V_170 , unsigned int * V_171 )
{
V_59 V_172 = 1000000000UL / V_170 ;
V_59 V_173 = 1 ;
unsigned int V_174 = 0 ;
while ( V_173 <= V_172 ) {
V_173 <<= 1 ;
V_174 ++ ;
}
* V_171 = V_174 ;
return 1000000000UL / V_173 ;
}
static int F_79 ( struct V_16 * V_175 ,
struct V_176 * V_177 , int V_109 )
{
struct V_178 V_27 ;
struct V_61 * V_62 = F_24 ( V_175 ) ;
V_57 V_179 ;
V_59 V_180 , V_181 , V_182 , V_183 ;
if ( F_80 ( & V_27 , V_177 -> V_184 , sizeof( V_27 ) ) )
return - V_185 ;
F_30 ( L_13 ,
V_186 , V_27 . V_65 , V_27 . V_187 , V_27 . V_188 ) ;
if ( V_27 . V_65 )
return - V_91 ;
if ( ( V_27 . V_187 != V_142 ) &&
( V_27 . V_187 != V_143 ) )
return - V_189 ;
V_179 = F_81 () ;
switch ( V_27 . V_188 ) {
case V_145 :
V_182 = 0xFFFFFFFF ;
F_82 ( V_182 ) ;
break;
case V_146 :
case V_190 :
case V_191 :
V_179 &= ~ 0x1F00 ;
F_83 ( V_179 ) ;
V_183 = 0x4A24170C ;
F_84 ( V_183 ) ;
V_180 = 0x11040800 ;
F_85 ( V_180 ) ;
V_181 = 0x0140013F ;
F_86 ( V_181 ) ;
V_182 = 0xFFFFFFFC ;
F_82 ( V_182 ) ;
V_27 . V_188 = V_146 ;
break;
case V_148 :
case V_192 :
case V_193 :
V_179 &= ~ 0x1F00 ;
F_83 ( V_179 ) ;
V_183 = 0x2A24170C ;
F_84 ( V_183 ) ;
V_180 = 0x11040800 ;
F_85 ( V_180 ) ;
V_181 = 0x0140013F ;
F_86 ( V_181 ) ;
V_182 = 0xFFFFFFF0 ;
F_82 ( V_182 ) ;
V_27 . V_188 = V_148 ;
break;
case V_147 :
case V_194 :
case V_195 :
V_179 &= ~ 0x1100 ;
F_83 ( V_179 ) ;
V_183 = 0x0E24170C ;
F_84 ( V_183 ) ;
V_180 = 0x110488F7 ;
F_85 ( V_180 ) ;
V_181 = 0x0140013F ;
F_86 ( V_181 ) ;
V_182 = 0xFFFFFFF0 ;
F_82 ( V_182 ) ;
V_27 . V_188 = V_147 ;
break;
default:
return - V_189 ;
}
if ( V_27 . V_187 == V_142 &&
F_87 ( V_27 . V_188 ) ) {
V_179 &= ~ V_196 ;
F_83 ( V_179 ) ;
F_88 () ;
} else {
V_179 |= V_196 ;
F_83 ( V_179 ) ;
F_89 () ;
F_90 () ;
F_91 () ;
F_92 () ;
F_88 () ;
}
V_62 -> V_197 = V_27 ;
return F_93 ( V_177 -> V_184 , & V_27 , sizeof( V_27 ) ) ?
- V_185 : 0 ;
}
static void F_94 ( struct V_16 * V_175 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_175 ) ;
if ( F_95 ( V_11 ) -> V_198 & V_199 ) {
int V_48 = V_49 ;
F_95 ( V_11 ) -> V_198 |= V_200 ;
while ( ( ! ( F_96 () & V_201 ) ) && ( -- V_48 ) )
F_14 ( 1 ) ;
if ( V_48 == 0 )
F_39 ( V_175 , L_14 ) ;
else {
struct V_202 V_203 ;
T_4 V_204 ;
T_4 V_205 ;
V_205 = F_91 () ;
V_205 |= ( T_4 ) F_92 () << 32 ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_204 = V_205 << V_62 -> V_174 ;
V_203 . V_206 = F_97 ( V_204 ) ;
F_98 ( V_11 , & V_203 ) ;
}
}
}
static void F_99 ( struct V_16 * V_175 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_175 ) ;
V_59 V_207 ;
T_4 V_205 , V_204 ;
struct V_202 * V_203 ;
if ( F_87 ( V_62 -> V_197 . V_188 ) )
return;
V_207 = F_96 () & V_208 ;
if ( ! V_207 )
return;
V_203 = F_100 ( V_11 ) ;
V_205 = F_89 () ;
V_205 |= ( T_4 ) F_90 () << 32 ;
V_204 = V_205 << V_62 -> V_174 ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_203 -> V_206 = F_97 ( V_204 ) ;
}
static void F_101 ( struct V_16 * V_175 )
{
struct V_61 * V_62 = F_24 ( V_175 ) ;
T_4 V_209 , V_210 ;
V_59 V_170 , V_211 ;
V_170 = F_35 () ;
V_211 = F_78 ( V_170 , & V_62 -> V_174 ) ;
V_209 = V_211 * ( 1ULL << 32 ) ;
F_102 ( V_209 , V_170 ) ;
F_103 ( ( V_59 ) V_209 ) ;
V_62 -> V_209 = V_209 ;
V_210 = 1000000000ULL * V_170 ;
F_102 ( V_210 , V_211 ) ;
V_62 -> V_212 = V_210 - 1000000000ULL - 1ULL ;
V_62 -> V_197 . V_188 = V_145 ;
V_62 -> V_197 . V_187 = V_142 ;
}
static T_4 F_104 ( struct V_61 * V_62 )
{
T_4 V_204 ;
V_59 V_213 , V_214 ;
V_213 = F_105 () ;
V_214 = F_106 () ;
V_204 = ( ( T_4 ) V_214 ) << 32 ;
V_204 |= V_213 ;
V_204 <<= V_62 -> V_174 ;
return V_204 ;
}
static void F_107 ( struct V_61 * V_62 , T_4 V_204 )
{
V_59 V_214 , V_213 ;
V_204 >>= V_62 -> V_174 ;
V_214 = V_204 >> 32 ;
V_213 = V_204 & 0xffffffff ;
F_108 ( V_213 ) ;
F_109 ( V_214 ) ;
}
static int F_110 ( struct V_215 * V_216 , T_5 V_210 )
{
T_4 V_217 ;
V_59 V_218 , V_209 ;
int V_219 = 0 ;
struct V_61 * V_62 =
F_111 ( V_216 , struct V_61 , V_220 ) ;
if ( V_210 < 0 ) {
V_219 = 1 ;
V_210 = - V_210 ;
}
V_209 = V_62 -> V_209 ;
V_217 = V_209 ;
V_217 *= V_210 ;
V_218 = F_112 ( V_217 , 1000000000ULL ) ;
V_209 = V_219 ? V_209 - V_218 : V_209 + V_218 ;
F_103 ( V_209 ) ;
return 0 ;
}
static int F_113 ( struct V_215 * V_216 , T_6 V_221 )
{
T_6 V_222 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_111 ( V_216 , struct V_61 , V_220 ) ;
F_25 ( & V_62 -> V_223 , V_65 ) ;
V_222 = F_104 ( V_62 ) ;
V_222 += V_221 ;
F_107 ( V_62 , V_222 ) ;
F_31 ( & V_62 -> V_223 , V_65 ) ;
return 0 ;
}
static int F_114 ( struct V_215 * V_216 , struct V_224 * V_225 )
{
T_4 V_204 ;
V_59 V_226 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_111 ( V_216 , struct V_61 , V_220 ) ;
F_25 ( & V_62 -> V_223 , V_65 ) ;
V_204 = F_104 ( V_62 ) ;
F_31 ( & V_62 -> V_223 , V_65 ) ;
V_225 -> V_227 = F_115 ( V_204 , 1000000000 , & V_226 ) ;
V_225 -> V_228 = V_226 ;
return 0 ;
}
static int F_116 ( struct V_215 * V_216 ,
const struct V_224 * V_225 )
{
T_4 V_204 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_111 ( V_216 , struct V_61 , V_220 ) ;
V_204 = V_225 -> V_227 * 1000000000ULL ;
V_204 += V_225 -> V_228 ;
F_25 ( & V_62 -> V_223 , V_65 ) ;
F_107 ( V_62 , V_204 ) ;
F_31 ( & V_62 -> V_223 , V_65 ) ;
return 0 ;
}
static int F_117 ( struct V_215 * V_216 ,
struct V_229 * V_230 , int V_231 )
{
return - V_131 ;
}
static int F_118 ( struct V_16 * V_175 , struct V_232 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_175 ) ;
V_62 -> V_220 = V_233 ;
V_62 -> V_220 . V_234 = V_62 -> V_212 ;
V_62 -> clock = F_119 ( & V_62 -> V_220 , V_17 ) ;
if ( F_42 ( V_62 -> clock ) )
return F_43 ( V_62 -> clock ) ;
V_62 -> V_140 = F_120 ( V_62 -> clock ) ;
F_121 ( & V_62 -> V_223 ) ;
return 0 ;
}
static void F_122 ( struct V_61 * V_62 )
{
F_123 ( V_62 -> clock ) ;
}
static inline void F_124 ( void )
{
do {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_235 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
} while ( V_9 -> V_37 . V_235 != 0 );
}
static void F_125 ( struct V_61 * V_62 )
{
int V_48 = V_49 ;
if ( V_9 -> V_37 . V_235 != 0 )
F_124 () ;
if ( V_38 -> V_12 == V_9 ) {
while ( V_9 -> V_37 . V_235 == 0 ) {
F_14 ( 10 ) ;
if ( ! ( F_126 () & V_236 ) )
break;
if ( V_48 -- < 0 )
break;
}
if ( V_48 >= 0 )
F_124 () ;
else
F_127 ( V_62 -> V_237 ) ;
}
if ( V_38 -> V_12 != V_9 &&
F_128 ( V_62 -> V_237 ) )
F_129 ( V_62 -> V_237 ) ;
if ( V_9 != V_38 ) {
if ( F_128 ( V_62 -> V_237 ) )
V_62 -> V_238 . V_239 =
V_240 + ( V_241 >> 4 ) ;
else
V_62 -> V_238 . V_239 =
V_240 + V_241 ;
F_130 ( & V_62 -> V_238 ,
V_62 -> V_238 . V_239 ) ;
}
return;
}
static void F_131 ( unsigned long V_62 )
{
F_125 ( (struct V_61 * ) V_62 ) ;
}
static int F_132 ( struct V_18 * V_11 ,
struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
V_57 * V_44 ;
V_59 V_242 = ( unsigned long ) ( V_11 -> V_44 ) & 0x3 ;
V_38 -> V_11 = V_11 ;
if ( V_242 == 0x2 ) {
V_44 = ( V_57 * ) ( V_11 -> V_44 ) - 1 ;
* V_44 = ( V_57 ) ( V_11 -> V_243 ) ;
if ( F_95 ( V_11 ) -> V_198 & V_199 )
* V_44 |= 0x1000 ;
V_38 -> V_24 . V_31 = ( V_59 ) V_44 ;
F_133 ( ( V_59 ) V_44 ,
( V_59 ) ( ( T_3 * ) V_44 + V_11 -> V_243 + 4 ) ) ;
} else {
* ( ( V_57 * ) ( V_38 -> V_32 ) ) = ( V_57 ) ( V_11 -> V_243 ) ;
if ( F_95 ( V_11 ) -> V_198 & V_199 )
* ( ( V_57 * ) ( V_38 -> V_32 ) ) |= 0x1000 ;
memcpy ( ( T_3 * ) ( V_38 -> V_32 + 2 ) , V_11 -> V_44 ,
V_11 -> V_243 ) ;
V_38 -> V_24 . V_31 =
( V_59 ) V_38 -> V_32 ;
F_133 (
( V_59 ) V_38 -> V_32 ,
( V_59 ) ( V_38 -> V_32 + V_11 -> V_243 + 2 ) ) ;
}
F_88 () ;
V_38 -> V_37 . V_235 = 0 ;
V_38 -> V_24 . V_27 |= V_35 ;
if ( F_126 () & V_236 )
goto V_244;
F_134 ( & ( V_38 -> V_24 ) ) ;
F_135 ( V_38 -> V_24 . V_27 ) ;
F_27 ( F_26 () | V_245 ) ;
V_244:
F_94 ( V_17 , V_11 ) ;
V_38 = V_38 -> V_12 ;
V_17 -> V_246 . V_247 ++ ;
V_17 -> V_246 . V_248 += ( V_11 -> V_243 ) ;
F_125 ( V_62 ) ;
return V_249 ;
}
static void F_136 ( struct V_16 * V_17 )
{
struct V_18 * V_11 , * V_19 ;
unsigned short V_243 ;
struct V_61 * V_62 V_250 = F_24 ( V_17 ) ;
#if F_2 ( V_152 )
unsigned int V_5 ;
unsigned char V_251 [ V_252 + 1 ] ;
#endif
if ( V_46 -> V_37 . V_235 & V_253 ) {
F_137 ( V_17 , L_15 ) ;
V_17 -> V_246 . V_254 ++ ;
goto V_244;
}
V_11 = V_46 -> V_11 ;
V_19 = F_7 ( V_17 , V_40 + V_41 ) ;
if ( ! V_19 ) {
F_137 ( V_17 , L_16 ) ;
V_17 -> V_246 . V_254 ++ ;
goto V_244;
}
F_9 ( V_19 , V_41 ) ;
F_10 ( ( unsigned long ) V_19 -> V_42 ,
( unsigned long ) V_19 -> V_43 ) ;
V_46 -> V_11 = V_19 ;
V_46 -> V_24 . V_31 = ( unsigned long ) V_19 -> V_44 - 2 ;
V_243 = ( unsigned short ) ( ( V_46 -> V_37 . V_235 ) & V_255 ) ;
V_243 -= V_252 ;
F_138 ( V_11 , V_243 ) ;
V_11 -> V_256 = F_139 ( V_11 , V_17 ) ;
F_99 ( V_17 , V_11 ) ;
#if F_2 ( V_152 )
if ( V_11 -> V_44 [ V_257 ] == 0x45 ) {
V_11 -> V_258 = V_46 -> V_37 . V_259 ;
if ( V_11 -> V_243 % 2 ) {
V_251 [ 0 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_252 ; V_5 ++ )
V_251 [ V_5 + 1 ] = ~ V_11 -> V_44 [ V_11 -> V_243 + V_5 ] ;
V_11 -> V_258 = F_140 ( V_251 , V_252 + 1 , V_11 -> V_258 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_252 ; V_5 ++ )
V_251 [ V_5 ] = ~ V_11 -> V_44 [ V_11 -> V_243 + V_5 ] ;
V_11 -> V_258 = F_140 ( V_251 , V_252 , V_11 -> V_258 ) ;
}
V_11 -> V_260 = V_261 ;
}
#endif
F_141 ( V_11 ) ;
V_17 -> V_246 . V_262 ++ ;
V_17 -> V_246 . V_263 += V_243 ;
V_244:
V_46 -> V_37 . V_235 = 0x00000000 ;
V_46 = V_46 -> V_12 ;
}
static T_2 F_142 ( int V_105 , void * V_106 )
{
struct V_16 * V_17 = V_106 ;
int V_264 = 0 ;
V_265:
if ( V_46 -> V_37 . V_235 == 0 ) {
if ( V_264 == 0 ) {
if ( V_46 -> V_12 -> V_37 . V_235 != 0 ) {
V_46 = V_46 -> V_12 ;
goto V_266;
}
}
F_143 ( F_144 () |
V_267 | V_268 ) ;
return V_107 ;
}
V_266:
F_136 ( V_17 ) ;
V_264 ++ ;
goto V_265;
}
static void F_145 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_146 ( V_269 ) ;
F_142 ( V_269 , V_17 ) ;
F_125 ( V_62 ) ;
F_147 ( V_269 ) ;
}
static void F_148 ( void )
{
unsigned int V_71 ;
V_71 = F_26 () ;
V_71 &= ( ~ V_270 ) ;
V_71 &= ( ~ V_245 ) ;
F_27 ( V_71 ) ;
}
static int F_149 ( struct V_63 * V_64 )
{
int V_56 ;
V_59 V_71 ;
F_30 ( L_17 , V_186 ) ;
F_150 ( & ( V_14 -> V_24 ) ) ;
F_151 ( V_14 -> V_24 . V_27 ) ;
V_56 = F_12 () ;
if ( V_56 )
return V_56 ;
V_71 = F_26 () ;
if ( V_71 & V_72 )
V_71 |= V_271 ;
else
V_71 |= V_272 | V_273 | V_271 ;
V_71 |= V_270 ;
if ( V_64 -> V_75 == V_76 ) {
V_71 |= V_274 ;
#if F_2 ( V_275 ) || F_2 ( V_276 )
if ( V_277 < 3 ) {
V_71 |= V_245 ;
}
#endif
}
F_27 ( V_71 ) ;
return 0 ;
}
static void F_152 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_30 ( L_18 , V_17 -> V_104 , V_186 ) ;
F_148 () ;
F_153 ( & V_62 -> V_238 ) ;
while ( V_9 != V_38 ) {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_235 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
}
if ( F_128 ( V_62 -> V_237 ) )
F_129 ( V_62 -> V_237 ) ;
F_149 ( V_62 -> V_64 ) ;
V_17 -> V_278 = V_240 ;
F_129 ( V_17 ) ;
}
static void F_154 ( struct V_16 * V_17 )
{
V_59 V_279 , V_280 ;
struct V_281 * V_282 ;
V_59 V_283 ;
V_279 = V_280 = 0 ;
F_155 (ha, dev) {
V_283 = F_156 ( V_284 , V_282 -> V_165 ) ;
V_283 >>= 26 ;
if ( V_283 & 0x20 )
V_279 |= 1 << ( V_283 & 0x1f ) ;
else
V_280 |= 1 << ( V_283 & 0x1f ) ;
}
F_157 ( V_279 ) ;
F_158 ( V_280 ) ;
}
static void F_159 ( struct V_16 * V_17 )
{
V_59 V_80 ;
if ( V_17 -> V_65 & V_285 ) {
F_160 ( V_17 , L_19 ) ;
V_80 = F_26 () ;
V_80 |= V_286 ;
F_27 ( V_80 ) ;
} else if ( V_17 -> V_65 & V_287 ) {
V_80 = F_26 () ;
V_80 |= V_288 ;
F_27 ( V_80 ) ;
} else if ( ! F_161 ( V_17 ) ) {
V_80 = F_26 () ;
V_80 |= V_289 ;
F_27 ( V_80 ) ;
F_154 ( V_17 ) ;
} else {
V_80 = F_26 () ;
V_80 &= ~ ( V_290 | V_288 ) ;
F_27 ( V_80 ) ;
}
}
static int F_162 ( struct V_16 * V_175 , struct V_176 * V_177 , int V_109 )
{
struct V_61 * V_62 = F_24 ( V_175 ) ;
if ( ! F_77 ( V_175 ) )
return - V_91 ;
switch ( V_109 ) {
case V_291 :
return F_79 ( V_175 , V_177 , V_109 ) ;
default:
if ( V_62 -> V_64 )
return F_163 ( V_62 -> V_64 , V_177 , V_109 ) ;
else
return - V_131 ;
}
}
static void F_164 ( struct V_16 * V_17 )
{
F_27 ( 0x00000000 ) ;
F_151 ( 0x0000 ) ;
F_135 ( 0x0000 ) ;
}
static int F_165 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
int V_56 ;
F_30 ( L_18 , V_17 -> V_104 , V_186 ) ;
if ( ! F_166 ( V_17 -> V_167 ) ) {
F_28 ( V_17 , L_20 ) ;
return - V_91 ;
}
V_56 = F_5 ( V_17 ) ;
if ( V_56 )
return V_56 ;
F_167 ( V_62 -> V_64 ) ;
F_168 ( V_62 -> V_64 , V_292 , V_293 ) ;
F_59 ( V_17 ) ;
F_71 ( V_17 -> V_167 ) ;
F_148 () ;
V_56 = F_149 ( V_62 -> V_64 ) ;
if ( V_56 )
return V_56 ;
F_30 ( L_21 ) ;
F_169 ( V_17 ) ;
F_170 ( V_17 ) ;
return 0 ;
}
static int F_171 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_30 ( L_18 , V_17 -> V_104 , V_186 ) ;
F_127 ( V_17 ) ;
F_172 ( V_17 ) ;
F_173 ( V_62 -> V_64 ) ;
F_168 ( V_62 -> V_64 , V_292 , V_294 ) ;
F_164 ( V_17 ) ;
F_1 () ;
return 0 ;
}
static int F_174 ( struct V_295 * V_296 )
{
struct V_16 * V_237 ;
struct V_61 * V_62 ;
struct V_295 * V_297 ;
struct V_298 * V_299 ;
int V_125 ;
V_237 = F_175 ( sizeof( struct V_61 ) ) ;
if ( ! V_237 )
return - V_47 ;
F_176 ( V_237 , & V_296 -> V_17 ) ;
F_177 ( V_296 , V_237 ) ;
V_62 = F_24 ( V_237 ) ;
V_62 -> V_237 = V_237 ;
* ( V_160 * ) ( & ( V_237 -> V_167 [ 0 ] ) ) = F_178 ( F_179 () ) ;
* ( V_162 * ) ( & ( V_237 -> V_167 [ 4 ] ) ) = F_180 ( ( V_57 ) F_181 () ) ;
F_74 ( 0x12345678 ) ;
if ( F_179 () != 0x12345678 ) {
F_182 ( & V_296 -> V_17 , L_22 ) ;
V_125 = - V_89 ;
goto V_300;
}
if ( ! F_166 ( V_237 -> V_167 ) ) {
if ( F_183 ( V_237 -> V_167 ) ||
! F_166 ( V_237 -> V_167 ) ) {
F_28 ( V_237 , L_23 ) ;
F_184 ( V_237 ) ;
}
}
F_71 ( V_237 -> V_167 ) ;
if ( ! V_296 -> V_17 . V_301 ) {
F_182 ( & V_296 -> V_17 , L_24 ) ;
V_125 = - V_89 ;
goto V_300;
}
V_297 = V_296 -> V_17 . V_301 ;
V_62 -> V_52 = F_185 ( V_297 ) ;
if ( ! V_62 -> V_52 ) {
F_182 ( & V_296 -> V_17 , L_25 ) ;
V_125 = - V_89 ;
goto V_300;
}
V_62 -> V_52 -> V_302 = V_237 ;
V_299 = V_297 -> V_17 . V_301 ;
V_125 = F_32 ( V_237 , V_299 -> V_79 ) ;
if ( V_125 ) {
F_182 ( & V_296 -> V_17 , L_26 ) ;
goto V_303;
}
V_62 -> V_156 = V_304 | V_299 -> V_156 ;
V_62 -> V_157 = V_304 | V_299 -> V_157 ;
F_186 ( V_237 ) ;
V_237 -> V_305 = & V_306 ;
V_237 -> V_307 = & V_308 ;
F_187 ( & V_62 -> V_238 ) ;
V_62 -> V_238 . V_44 = ( unsigned long ) V_62 ;
V_62 -> V_238 . V_309 = F_131 ;
F_121 ( & V_62 -> V_67 ) ;
V_125 = F_55 ( V_269 , F_142 ,
V_134 , L_27 , V_237 ) ;
if ( V_125 ) {
F_182 ( & V_296 -> V_17 , L_28 ) ;
V_125 = - V_166 ;
goto V_310;
}
V_125 = F_188 ( V_237 ) ;
if ( V_125 ) {
F_182 ( & V_296 -> V_17 , L_29 ) ;
goto V_311;
}
F_101 ( V_237 ) ;
if ( F_118 ( V_237 , & V_296 -> V_17 ) ) {
F_182 ( & V_296 -> V_17 , L_30 ) ;
goto V_312;
}
F_160 ( V_237 , L_31 , V_313 , V_117 ) ;
return 0 ;
V_312:
V_311:
F_56 ( V_269 , V_237 ) ;
V_310:
V_303:
F_189 ( V_62 -> V_52 ) ;
F_190 ( V_62 -> V_52 ) ;
V_300:
F_177 ( V_296 , NULL ) ;
F_191 ( V_237 ) ;
return V_125 ;
}
static int F_192 ( struct V_295 * V_296 )
{
struct V_16 * V_237 = F_185 ( V_296 ) ;
struct V_61 * V_62 = F_24 ( V_237 ) ;
F_122 ( V_62 ) ;
F_177 ( V_296 , NULL ) ;
V_62 -> V_52 -> V_302 = NULL ;
F_193 ( V_237 ) ;
F_56 ( V_269 , V_237 ) ;
F_191 ( V_237 ) ;
return 0 ;
}
static int F_194 ( struct V_295 * V_296 , T_7 V_314 )
{
struct V_16 * V_315 = F_185 ( V_296 ) ;
struct V_61 * V_62 = F_24 ( V_315 ) ;
if ( V_62 -> V_124 ) {
F_27 ( ( F_26 () & ~ V_245 ) | V_270 ) ;
F_195 ( V_316 ) ;
F_196 ( V_133 ) ;
} else {
if ( F_77 ( V_315 ) )
F_171 ( V_315 ) ;
}
return 0 ;
}
static int F_197 ( struct V_295 * V_296 )
{
struct V_16 * V_315 = F_185 ( V_296 ) ;
struct V_61 * V_62 = F_24 ( V_315 ) ;
if ( V_62 -> V_124 ) {
F_27 ( F_26 () | V_245 ) ;
F_195 ( 0 ) ;
F_198 ( V_133 ) ;
} else {
if ( F_77 ( V_315 ) )
F_165 ( V_315 ) ;
}
return 0 ;
}
static int F_199 ( struct V_295 * V_296 )
{
struct V_52 * V_317 ;
struct V_298 * V_318 ;
const unsigned short * V_319 ;
int V_125 , V_5 ;
V_318 = F_200 ( & V_296 -> V_17 ) ;
if ( ! V_318 ) {
F_182 ( & V_296 -> V_17 , L_32 ) ;
return - V_91 ;
}
V_319 = V_318 -> V_320 ;
V_125 = F_201 ( V_319 , V_115 ) ;
if ( V_125 ) {
F_182 ( & V_296 -> V_17 , L_33 ) ;
return V_125 ;
}
V_125 = - V_47 ;
V_317 = F_202 () ;
if ( V_317 == NULL )
goto V_321;
V_317 -> V_322 = F_15 ;
V_317 -> V_323 = F_20 ;
V_317 -> V_324 = F_22 ;
V_317 -> V_325 = & V_296 -> V_17 ;
V_317 -> V_104 = L_34 ;
V_317 -> V_326 = V_318 -> V_326 ;
snprintf ( V_317 -> V_327 , V_328 , L_35 ,
V_296 -> V_104 , V_296 -> V_327 ) ;
V_317 -> V_105 = F_203 ( sizeof( int ) * V_86 , V_329 ) ;
if ( ! V_317 -> V_105 )
goto V_330;
for ( V_5 = V_125 ; V_5 < V_86 ; ++ V_5 )
V_317 -> V_105 [ V_5 ] = V_149 ;
V_125 = F_204 ( V_318 -> V_331 , 0 , V_86 ) ;
if ( V_125 != V_318 -> V_331 )
F_182 ( & V_296 -> V_17 , L_36 ,
V_318 -> V_331 ) ;
for ( V_5 = 0 ; V_5 < V_125 ; ++ V_5 ) {
unsigned short V_332 = V_318 -> V_333 [ V_5 ] . V_165 ;
if ( V_332 < V_86 )
V_317 -> V_105 [ V_332 ] = V_318 -> V_333 [ V_5 ] . V_105 ;
else
F_182 ( & V_296 -> V_17 ,
L_37 ,
V_332 , V_5 ) ;
}
V_125 = F_205 ( V_317 ) ;
if ( V_125 ) {
F_182 ( & V_296 -> V_17 , L_38 ) ;
goto V_334;
}
F_177 ( V_296 , V_317 ) ;
return 0 ;
V_334:
F_206 ( V_317 -> V_105 ) ;
V_330:
F_190 ( V_317 ) ;
V_321:
F_207 ( V_319 ) ;
return V_125 ;
}
static int F_208 ( struct V_295 * V_296 )
{
struct V_52 * V_317 = F_185 ( V_296 ) ;
struct V_298 * V_318 =
F_200 ( & V_296 -> V_17 ) ;
F_177 ( V_296 , NULL ) ;
F_189 ( V_317 ) ;
F_206 ( V_317 -> V_105 ) ;
F_190 ( V_317 ) ;
F_207 ( V_318 -> V_320 ) ;
return 0 ;
}
static int T_8 F_209 ( void )
{
int V_56 ;
V_56 = F_210 ( & V_335 ) ;
if ( ! V_56 )
return F_210 ( & V_336 ) ;
return - V_89 ;
}
static void T_9 F_211 ( void )
{
F_212 ( & V_336 ) ;
F_212 ( & V_335 ) ;
}
