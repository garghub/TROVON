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
if ( ! V_19 )
goto V_20;
F_8 ( V_19 , V_41 ) ;
F_9 ( ( unsigned long ) V_19 -> V_42 ,
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
F_10 ( L_1 ) ;
return - V_47 ;
}
static int F_11 ( void )
{
int V_48 = V_49 ;
while ( ( F_12 () ) & V_50 ) {
F_13 ( 1 ) ;
if ( V_48 -- < 0 ) {
F_10 ( L_2 ) ;
return - V_51 ;
}
}
return 0 ;
}
static int F_14 ( struct V_52 * V_53 , int V_54 , int V_55 )
{
int V_56 ;
V_56 = F_11 () ;
if ( V_56 )
return V_56 ;
F_15 ( F_16 ( ( V_57 ) V_54 ) |
F_17 ( ( V_57 ) V_55 ) |
V_50 ) ;
V_56 = F_11 () ;
if ( V_56 )
return V_56 ;
return ( int ) F_18 () ;
}
static int F_19 ( struct V_52 * V_53 , int V_54 , int V_55 ,
V_57 V_58 )
{
int V_56 ;
V_56 = F_11 () ;
if ( V_56 )
return V_56 ;
F_20 ( ( V_59 ) V_58 ) ;
F_15 ( F_16 ( ( V_57 ) V_54 ) |
F_17 ( ( V_57 ) V_55 ) |
V_60 |
V_50 ) ;
return F_11 () ;
}
static int F_21 ( struct V_52 * V_53 )
{
return 0 ;
}
static void F_22 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
struct V_63 * V_64 = V_62 -> V_64 ;
unsigned long V_65 ;
int V_66 = 0 ;
F_24 ( & V_62 -> V_67 , V_65 ) ;
if ( V_64 -> V_68 ) {
if ( V_64 -> V_69 != V_62 -> V_70 ) {
V_59 V_71 = F_25 () ;
V_66 = 1 ;
if ( V_64 -> V_69 )
V_71 |= V_72 ;
else
V_71 &= ~ ( V_72 ) ;
F_26 ( V_71 ) ;
V_62 -> V_70 = V_64 -> V_69 ;
}
if ( V_64 -> V_73 != V_62 -> V_74 ) {
if ( V_64 -> V_75 == V_76 ) {
V_59 V_71 = F_25 () ;
switch ( V_64 -> V_73 ) {
case 10 :
V_71 |= V_77 ;
break;
case 100 :
V_71 &= ~ V_77 ;
break;
default:
F_27 ( V_17 ,
L_3 ,
V_64 -> V_73 ) ;
break;
}
F_26 ( V_71 ) ;
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
V_59 V_71 = F_25 () ;
F_28 ( V_64 ) ;
F_29 ( L_4 , V_71 ) ;
}
F_30 ( & V_62 -> V_67 , V_65 ) ;
}
static int F_31 ( struct V_16 * V_17 , int V_79 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
struct V_63 * V_64 = NULL ;
unsigned short V_80 ;
int V_5 ;
V_59 V_81 , V_82 ;
if ( ! ( F_32 () & V_83 ) )
F_33 ( F_32 () | V_83 ) ;
V_81 = F_34 () ;
V_82 = ( ( V_81 / V_84 ) / 2 ) - 1 ;
V_80 = F_35 () ;
V_80 = ( V_80 & ~ V_85 ) | F_36 ( V_82 ) ;
F_37 ( V_80 ) ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 ) {
struct V_63 * const V_87 = V_62 -> V_52 -> V_88 [ V_5 ] ;
if ( ! V_87 )
continue;
V_64 = V_87 ;
break;
}
if ( ! V_64 ) {
F_38 ( V_17 , L_5 ) ;
return - V_89 ;
}
if ( V_79 != V_76 &&
V_79 != V_90 ) {
F_38 ( V_17 , L_6 ) ;
return - V_91 ;
}
V_64 = F_39 ( V_17 , F_40 ( & V_64 -> V_17 ) ,
& F_22 , V_79 ) ;
if ( F_41 ( V_64 ) ) {
F_38 ( V_17 , L_7 ) ;
return F_42 ( V_64 ) ;
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
F_43 ( L_8
L_9 ,
V_64 -> V_103 -> V_104 , F_40 ( & V_64 -> V_17 ) , V_64 -> V_105 ,
V_84 , V_82 , V_81 / 1000000 ) ;
return 0 ;
}
static T_2 F_44 ( int V_105 , void * V_106 )
{
return V_107 ;
}
static int
F_45 ( struct V_16 * V_17 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
if ( V_62 -> V_64 )
return F_46 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static int
F_47 ( struct V_16 * V_17 , struct V_108 * V_109 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
if ( ! F_48 ( V_110 ) )
return - V_111 ;
if ( V_62 -> V_64 )
return F_49 ( V_62 -> V_64 , V_109 ) ;
return - V_91 ;
}
static void F_50 ( struct V_16 * V_17 ,
struct V_112 * V_113 )
{
F_51 ( V_113 -> V_114 , V_115 , sizeof( V_113 -> V_114 ) ) ;
F_51 ( V_113 -> V_116 , V_117 , sizeof( V_113 -> V_116 ) ) ;
F_51 ( V_113 -> V_118 , L_10 , sizeof( V_113 -> V_118 ) ) ;
F_51 ( V_113 -> V_119 , F_40 ( & V_17 -> V_17 ) , sizeof( V_113 -> V_119 ) ) ;
}
static void F_52 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
V_121 -> V_92 = V_122 ;
V_121 -> V_123 = V_62 -> V_124 ;
}
static int F_53 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
int V_125 ;
if ( V_121 -> V_123 & ( V_126 |
V_127 |
V_128 |
V_129 |
V_130 ) )
return - V_131 ;
V_62 -> V_124 = V_121 -> V_123 ;
if ( V_62 -> V_124 && ! V_62 -> V_132 ) {
V_125 = F_54 ( V_133 , F_44 ,
0 , L_11 , V_17 ) ;
if ( V_125 )
return V_125 ;
V_62 -> V_132 = true ;
}
if ( ! V_62 -> V_124 && V_62 -> V_132 ) {
F_55 ( V_133 , V_17 ) ;
V_62 -> V_132 = false ;
}
F_56 ( & V_17 -> V_17 , V_62 -> V_124 ) ;
return 0 ;
}
static int F_57 ( struct V_16 * V_17 ,
struct V_134 * V_113 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
V_113 -> V_135 =
V_136 |
V_137 |
V_138 ;
V_113 -> V_139 = V_62 -> V_139 ;
V_113 -> V_140 =
( 1 << V_141 ) |
( 1 << V_142 ) ;
V_113 -> V_143 =
( 1 << V_144 ) |
( 1 << V_145 ) |
( 1 << V_146 ) |
( 1 << V_147 ) ;
return 0 ;
}
static void F_58 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
int V_5 ;
unsigned short V_80 ;
V_80 = F_35 () ;
for ( V_5 = 0 ; V_5 < V_86 ; ++ V_5 )
if ( V_62 -> V_52 -> V_105 [ V_5 ] != V_148 )
break;
if ( V_5 < V_86 )
V_80 |= V_149 ;
V_80 |= V_150 ;
#if F_2 ( V_151 )
V_80 |= V_152 ;
#else
V_80 &= ~ V_152 ;
#endif
F_37 ( V_80 ) ;
F_59 ( V_153 | V_154 ) ;
F_60 ( V_62 -> V_155 ) ;
F_61 ( V_62 -> V_156 ) ;
F_62 ( 0 ) ;
F_63 ( 4 ) ;
F_64 ( 0 ) ;
F_65 ( 0 ) ;
F_66 ( 0 ) ;
F_67 ( 4 ) ;
F_68 ( 0 ) ;
F_69 ( 0 ) ;
}
static void F_70 ( T_3 * V_157 )
{
V_59 V_158 = F_71 ( * ( V_159 * ) & V_157 [ 0 ] ) ;
V_57 V_160 = F_72 ( * ( V_161 * ) & V_157 [ 4 ] ) ;
F_73 ( V_158 ) ;
F_74 ( V_160 ) ;
}
static int F_75 ( struct V_16 * V_17 , void * V_162 )
{
struct V_163 * V_164 = V_162 ;
if ( F_76 ( V_17 ) )
return - V_165 ;
memcpy ( V_17 -> V_166 , V_164 -> V_167 , V_17 -> V_168 ) ;
F_70 ( V_17 -> V_166 ) ;
return 0 ;
}
static V_59 F_77 ( V_59 V_169 , unsigned int * V_170 )
{
V_59 V_171 = 1000000000UL / V_169 ;
V_59 V_172 = 1 ;
unsigned int V_173 = 0 ;
while ( V_172 <= V_171 ) {
V_172 <<= 1 ;
V_173 ++ ;
}
* V_170 = V_173 ;
return 1000000000UL / V_172 ;
}
static int F_78 ( struct V_16 * V_174 ,
struct V_175 * V_176 , int V_109 )
{
struct V_177 V_27 ;
struct V_61 * V_62 = F_23 ( V_174 ) ;
V_57 V_178 ;
V_59 V_179 , V_180 , V_181 , V_182 ;
if ( F_79 ( & V_27 , V_176 -> V_183 , sizeof( V_27 ) ) )
return - V_184 ;
F_29 ( L_12 ,
V_185 , V_27 . V_65 , V_27 . V_186 , V_27 . V_187 ) ;
if ( V_27 . V_65 )
return - V_91 ;
if ( ( V_27 . V_186 != V_141 ) &&
( V_27 . V_186 != V_142 ) )
return - V_188 ;
V_178 = F_80 () ;
switch ( V_27 . V_187 ) {
case V_144 :
V_181 = 0xFFFFFFFF ;
F_81 ( V_181 ) ;
break;
case V_145 :
case V_189 :
case V_190 :
V_178 &= ~ 0x1F00 ;
F_82 ( V_178 ) ;
V_182 = 0x4A24170C ;
F_83 ( V_182 ) ;
V_179 = 0x11040800 ;
F_84 ( V_179 ) ;
V_180 = 0x0140013F ;
F_85 ( V_180 ) ;
V_181 = 0xFFFFFFFC ;
F_81 ( V_181 ) ;
V_27 . V_187 = V_145 ;
break;
case V_147 :
case V_191 :
case V_192 :
V_178 &= ~ 0x1F00 ;
F_82 ( V_178 ) ;
V_182 = 0x2A24170C ;
F_83 ( V_182 ) ;
V_179 = 0x11040800 ;
F_84 ( V_179 ) ;
V_180 = 0x0140013F ;
F_85 ( V_180 ) ;
V_181 = 0xFFFFFFF0 ;
F_81 ( V_181 ) ;
V_27 . V_187 = V_147 ;
break;
case V_146 :
case V_193 :
case V_194 :
V_178 &= ~ 0x1100 ;
F_82 ( V_178 ) ;
V_182 = 0x0E24170C ;
F_83 ( V_182 ) ;
V_179 = 0x110488F7 ;
F_84 ( V_179 ) ;
V_180 = 0x0140013F ;
F_85 ( V_180 ) ;
V_181 = 0xFFFFFFF0 ;
F_81 ( V_181 ) ;
V_27 . V_187 = V_146 ;
break;
default:
return - V_188 ;
}
if ( V_27 . V_186 == V_141 &&
F_86 ( V_27 . V_187 ) ) {
V_178 &= ~ V_195 ;
F_82 ( V_178 ) ;
F_87 () ;
} else {
V_178 |= V_195 ;
F_82 ( V_178 ) ;
F_88 () ;
F_89 () ;
F_90 () ;
F_91 () ;
F_87 () ;
}
V_62 -> V_196 = V_27 ;
return F_92 ( V_176 -> V_183 , & V_27 , sizeof( V_27 ) ) ?
- V_184 : 0 ;
}
static void F_93 ( struct V_16 * V_174 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_23 ( V_174 ) ;
if ( F_94 ( V_11 ) -> V_197 & V_198 ) {
int V_48 = V_49 ;
F_94 ( V_11 ) -> V_197 |= V_199 ;
while ( ( ! ( F_95 () & V_200 ) ) && ( -- V_48 ) )
F_13 ( 1 ) ;
if ( V_48 == 0 )
F_38 ( V_174 , L_13 ) ;
else {
struct V_201 V_202 ;
T_4 V_203 ;
T_4 V_204 ;
V_204 = F_90 () ;
V_204 |= ( T_4 ) F_91 () << 32 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_203 = V_204 << V_62 -> V_173 ;
V_202 . V_205 = F_96 ( V_203 ) ;
F_97 ( V_11 , & V_202 ) ;
}
}
}
static void F_98 ( struct V_16 * V_174 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_23 ( V_174 ) ;
V_59 V_206 ;
T_4 V_204 , V_203 ;
struct V_201 * V_202 ;
if ( F_86 ( V_62 -> V_196 . V_187 ) )
return;
V_206 = F_95 () & V_207 ;
if ( ! V_206 )
return;
V_202 = F_99 ( V_11 ) ;
V_204 = F_88 () ;
V_204 |= ( T_4 ) F_89 () << 32 ;
V_203 = V_204 << V_62 -> V_173 ;
memset ( V_202 , 0 , sizeof( * V_202 ) ) ;
V_202 -> V_205 = F_96 ( V_203 ) ;
}
static void F_100 ( struct V_16 * V_174 )
{
struct V_61 * V_62 = F_23 ( V_174 ) ;
T_4 V_208 , V_209 ;
V_59 V_169 , V_210 ;
V_169 = F_34 () ;
V_210 = F_77 ( V_169 , & V_62 -> V_173 ) ;
V_208 = V_210 * ( 1ULL << 32 ) ;
F_101 ( V_208 , V_169 ) ;
F_102 ( ( V_59 ) V_208 ) ;
V_62 -> V_208 = V_208 ;
V_209 = 1000000000ULL * V_169 ;
F_101 ( V_209 , V_210 ) ;
V_62 -> V_211 = V_209 - 1000000000ULL - 1ULL ;
V_62 -> V_196 . V_187 = V_144 ;
V_62 -> V_196 . V_186 = V_141 ;
}
static T_4 F_103 ( struct V_61 * V_62 )
{
T_4 V_203 ;
V_59 V_212 , V_213 ;
V_212 = F_104 () ;
V_213 = F_105 () ;
V_203 = ( ( T_4 ) V_213 ) << 32 ;
V_203 |= V_212 ;
V_203 <<= V_62 -> V_173 ;
return V_203 ;
}
static void F_106 ( struct V_61 * V_62 , T_4 V_203 )
{
V_59 V_213 , V_212 ;
V_203 >>= V_62 -> V_173 ;
V_213 = V_203 >> 32 ;
V_212 = V_203 & 0xffffffff ;
F_107 ( V_212 ) ;
F_108 ( V_213 ) ;
}
static int F_109 ( struct V_214 * V_215 , T_5 V_209 )
{
T_4 V_216 ;
V_59 V_217 , V_208 ;
int V_218 = 0 ;
struct V_61 * V_62 =
F_110 ( V_215 , struct V_61 , V_219 ) ;
if ( V_209 < 0 ) {
V_218 = 1 ;
V_209 = - V_209 ;
}
V_208 = V_62 -> V_208 ;
V_216 = V_208 ;
V_216 *= V_209 ;
V_217 = F_111 ( V_216 , 1000000000ULL ) ;
V_208 = V_218 ? V_208 - V_217 : V_208 + V_217 ;
F_102 ( V_208 ) ;
return 0 ;
}
static int F_112 ( struct V_214 * V_215 , T_6 V_220 )
{
T_6 V_221 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_215 , struct V_61 , V_219 ) ;
F_24 ( & V_62 -> V_222 , V_65 ) ;
V_221 = F_103 ( V_62 ) ;
V_221 += V_220 ;
F_106 ( V_62 , V_221 ) ;
F_30 ( & V_62 -> V_222 , V_65 ) ;
return 0 ;
}
static int F_113 ( struct V_214 * V_215 , struct V_223 * V_224 )
{
T_4 V_203 ;
V_59 V_225 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_215 , struct V_61 , V_219 ) ;
F_24 ( & V_62 -> V_222 , V_65 ) ;
V_203 = F_103 ( V_62 ) ;
F_30 ( & V_62 -> V_222 , V_65 ) ;
V_224 -> V_226 = F_114 ( V_203 , 1000000000 , & V_225 ) ;
V_224 -> V_227 = V_225 ;
return 0 ;
}
static int F_115 ( struct V_214 * V_215 ,
const struct V_223 * V_224 )
{
T_4 V_203 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_215 , struct V_61 , V_219 ) ;
V_203 = V_224 -> V_226 * 1000000000ULL ;
V_203 += V_224 -> V_227 ;
F_24 ( & V_62 -> V_222 , V_65 ) ;
F_106 ( V_62 , V_203 ) ;
F_30 ( & V_62 -> V_222 , V_65 ) ;
return 0 ;
}
static int F_116 ( struct V_214 * V_215 ,
struct V_228 * V_229 , int V_230 )
{
return - V_131 ;
}
static int F_117 ( struct V_16 * V_174 , struct V_231 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_174 ) ;
V_62 -> V_219 = V_232 ;
V_62 -> V_219 . V_233 = V_62 -> V_211 ;
V_62 -> clock = F_118 ( & V_62 -> V_219 , V_17 ) ;
if ( F_41 ( V_62 -> clock ) )
return F_42 ( V_62 -> clock ) ;
V_62 -> V_139 = F_119 ( V_62 -> clock ) ;
F_120 ( & V_62 -> V_222 ) ;
return 0 ;
}
static void F_121 ( struct V_61 * V_62 )
{
F_122 ( V_62 -> clock ) ;
}
static inline void F_123 ( void )
{
do {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_234 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
} while ( V_9 -> V_37 . V_234 != 0 );
}
static void F_124 ( struct V_61 * V_62 )
{
int V_48 = V_49 ;
if ( V_9 -> V_37 . V_234 != 0 )
F_123 () ;
if ( V_38 -> V_12 == V_9 ) {
while ( V_9 -> V_37 . V_234 == 0 ) {
F_13 ( 10 ) ;
if ( ! ( F_125 () & V_235 ) )
break;
if ( V_48 -- < 0 )
break;
}
if ( V_48 >= 0 )
F_123 () ;
else
F_126 ( V_62 -> V_236 ) ;
}
if ( V_38 -> V_12 != V_9 &&
F_127 ( V_62 -> V_236 ) )
F_128 ( V_62 -> V_236 ) ;
if ( V_9 != V_38 ) {
if ( F_127 ( V_62 -> V_236 ) )
V_62 -> V_237 . V_238 =
V_239 + ( V_240 >> 4 ) ;
else
V_62 -> V_237 . V_238 =
V_239 + V_240 ;
F_129 ( & V_62 -> V_237 ,
V_62 -> V_237 . V_238 ) ;
}
return;
}
static void F_130 ( unsigned long V_62 )
{
F_124 ( (struct V_61 * ) V_62 ) ;
}
static int F_131 ( struct V_18 * V_11 ,
struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
V_57 * V_44 ;
V_59 V_241 = ( unsigned long ) ( V_11 -> V_44 ) & 0x3 ;
V_38 -> V_11 = V_11 ;
if ( V_241 == 0x2 ) {
V_44 = ( V_57 * ) ( V_11 -> V_44 ) - 1 ;
* V_44 = ( V_57 ) ( V_11 -> V_242 ) ;
if ( F_94 ( V_11 ) -> V_197 & V_198 )
* V_44 |= 0x1000 ;
V_38 -> V_24 . V_31 = ( V_59 ) V_44 ;
F_132 ( ( V_59 ) V_44 ,
( V_59 ) ( ( T_3 * ) V_44 + V_11 -> V_242 + 4 ) ) ;
} else {
* ( ( V_57 * ) ( V_38 -> V_32 ) ) = ( V_57 ) ( V_11 -> V_242 ) ;
if ( F_94 ( V_11 ) -> V_197 & V_198 )
* ( ( V_57 * ) ( V_38 -> V_32 ) ) |= 0x1000 ;
memcpy ( ( T_3 * ) ( V_38 -> V_32 + 2 ) , V_11 -> V_44 ,
V_11 -> V_242 ) ;
V_38 -> V_24 . V_31 =
( V_59 ) V_38 -> V_32 ;
F_132 (
( V_59 ) V_38 -> V_32 ,
( V_59 ) ( V_38 -> V_32 + V_11 -> V_242 + 2 ) ) ;
}
F_87 () ;
V_38 -> V_37 . V_234 = 0 ;
V_38 -> V_24 . V_27 |= V_35 ;
if ( F_125 () & V_235 )
goto V_243;
F_133 ( & ( V_38 -> V_24 ) ) ;
F_134 ( V_38 -> V_24 . V_27 ) ;
F_26 ( F_25 () | V_244 ) ;
V_243:
F_93 ( V_17 , V_11 ) ;
V_38 = V_38 -> V_12 ;
V_17 -> V_245 . V_246 ++ ;
V_17 -> V_245 . V_247 += ( V_11 -> V_242 ) ;
F_124 ( V_62 ) ;
return V_248 ;
}
static void F_135 ( struct V_16 * V_17 )
{
struct V_18 * V_11 , * V_19 ;
unsigned short V_242 ;
struct V_61 * V_62 V_249 = F_23 ( V_17 ) ;
#if F_2 ( V_151 )
unsigned int V_5 ;
unsigned char V_250 [ V_251 + 1 ] ;
#endif
if ( V_46 -> V_37 . V_234 & V_252 ) {
F_136 ( V_17 , L_14 ) ;
V_17 -> V_245 . V_253 ++ ;
goto V_243;
}
V_11 = V_46 -> V_11 ;
V_19 = F_7 ( V_17 , V_40 + V_41 ) ;
if ( ! V_19 ) {
V_17 -> V_245 . V_253 ++ ;
goto V_243;
}
F_8 ( V_19 , V_41 ) ;
F_9 ( ( unsigned long ) V_19 -> V_42 ,
( unsigned long ) V_19 -> V_43 ) ;
V_46 -> V_11 = V_19 ;
V_46 -> V_24 . V_31 = ( unsigned long ) V_19 -> V_44 - 2 ;
V_242 = ( unsigned short ) ( ( V_46 -> V_37 . V_234 ) & V_254 ) ;
V_242 -= V_251 ;
F_137 ( V_11 , V_242 ) ;
V_11 -> V_255 = F_138 ( V_11 , V_17 ) ;
F_98 ( V_17 , V_11 ) ;
#if F_2 ( V_151 )
if ( V_11 -> V_44 [ V_256 ] == 0x45 ) {
V_11 -> V_257 = V_46 -> V_37 . V_258 ;
if ( V_11 -> V_242 % 2 ) {
V_250 [ 0 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_251 ; V_5 ++ )
V_250 [ V_5 + 1 ] = ~ V_11 -> V_44 [ V_11 -> V_242 + V_5 ] ;
V_11 -> V_257 = F_139 ( V_250 , V_251 + 1 , V_11 -> V_257 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_251 ; V_5 ++ )
V_250 [ V_5 ] = ~ V_11 -> V_44 [ V_11 -> V_242 + V_5 ] ;
V_11 -> V_257 = F_139 ( V_250 , V_251 , V_11 -> V_257 ) ;
}
V_11 -> V_259 = V_260 ;
}
#endif
F_140 ( V_11 ) ;
V_17 -> V_245 . V_261 ++ ;
V_17 -> V_245 . V_262 += V_242 ;
V_243:
V_46 -> V_37 . V_234 = 0x00000000 ;
V_46 = V_46 -> V_12 ;
}
static T_2 F_141 ( int V_105 , void * V_106 )
{
struct V_16 * V_17 = V_106 ;
int V_263 = 0 ;
V_264:
if ( V_46 -> V_37 . V_234 == 0 ) {
if ( V_263 == 0 ) {
if ( V_46 -> V_12 -> V_37 . V_234 != 0 ) {
V_46 = V_46 -> V_12 ;
goto V_265;
}
}
F_142 ( F_143 () |
V_266 | V_267 ) ;
return V_107 ;
}
V_265:
F_135 ( V_17 ) ;
V_263 ++ ;
goto V_264;
}
static void F_144 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
F_145 ( V_268 ) ;
F_141 ( V_268 , V_17 ) ;
F_124 ( V_62 ) ;
F_146 ( V_268 ) ;
}
static void F_147 ( void )
{
unsigned int V_71 ;
V_71 = F_25 () ;
V_71 &= ( ~ V_269 ) ;
V_71 &= ( ~ V_244 ) ;
F_26 ( V_71 ) ;
}
static int F_148 ( struct V_63 * V_64 )
{
int V_56 ;
V_59 V_71 ;
F_29 ( L_15 , V_185 ) ;
F_149 ( & ( V_14 -> V_24 ) ) ;
F_150 ( V_14 -> V_24 . V_27 ) ;
V_56 = F_11 () ;
if ( V_56 )
return V_56 ;
V_71 = F_25 () ;
if ( V_71 & V_72 )
V_71 |= V_270 ;
else
V_71 |= V_271 | V_272 | V_270 ;
V_71 |= V_269 ;
if ( V_64 -> V_75 == V_76 ) {
V_71 |= V_273 ;
#if F_2 ( V_274 ) || F_2 ( V_275 )
if ( V_276 < 3 ) {
V_71 |= V_244 ;
}
#endif
}
F_26 ( V_71 ) ;
return 0 ;
}
static void F_151 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
F_29 ( L_16 , V_17 -> V_104 , V_185 ) ;
F_147 () ;
F_152 ( & V_62 -> V_237 ) ;
while ( V_9 != V_38 ) {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_234 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
}
if ( F_127 ( V_62 -> V_236 ) )
F_128 ( V_62 -> V_236 ) ;
F_148 ( V_62 -> V_64 ) ;
V_17 -> V_277 = V_239 ;
F_128 ( V_17 ) ;
}
static void F_153 ( struct V_16 * V_17 )
{
V_59 V_278 , V_279 ;
struct V_280 * V_281 ;
V_59 V_282 ;
V_278 = V_279 = 0 ;
F_154 (ha, dev) {
V_282 = F_155 ( V_283 , V_281 -> V_164 ) ;
V_282 >>= 26 ;
if ( V_282 & 0x20 )
V_278 |= 1 << ( V_282 & 0x1f ) ;
else
V_279 |= 1 << ( V_282 & 0x1f ) ;
}
F_156 ( V_278 ) ;
F_157 ( V_279 ) ;
}
static void F_158 ( struct V_16 * V_17 )
{
V_59 V_80 ;
if ( V_17 -> V_65 & V_284 ) {
F_159 ( V_17 , L_17 ) ;
V_80 = F_25 () ;
V_80 |= V_285 ;
F_26 ( V_80 ) ;
} else if ( V_17 -> V_65 & V_286 ) {
V_80 = F_25 () ;
V_80 |= V_287 ;
F_26 ( V_80 ) ;
} else if ( ! F_160 ( V_17 ) ) {
V_80 = F_25 () ;
V_80 |= V_288 ;
F_26 ( V_80 ) ;
F_153 ( V_17 ) ;
} else {
V_80 = F_25 () ;
V_80 &= ~ ( V_289 | V_287 ) ;
F_26 ( V_80 ) ;
}
}
static int F_161 ( struct V_16 * V_174 , struct V_175 * V_176 , int V_109 )
{
struct V_61 * V_62 = F_23 ( V_174 ) ;
if ( ! F_76 ( V_174 ) )
return - V_91 ;
switch ( V_109 ) {
case V_290 :
return F_78 ( V_174 , V_176 , V_109 ) ;
default:
if ( V_62 -> V_64 )
return F_162 ( V_62 -> V_64 , V_176 , V_109 ) ;
else
return - V_131 ;
}
}
static void F_163 ( struct V_16 * V_17 )
{
F_26 ( 0x00000000 ) ;
F_150 ( 0x0000 ) ;
F_134 ( 0x0000 ) ;
}
static int F_164 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
int V_56 ;
F_29 ( L_16 , V_17 -> V_104 , V_185 ) ;
if ( ! F_165 ( V_17 -> V_166 ) ) {
F_27 ( V_17 , L_18 ) ;
return - V_91 ;
}
V_56 = F_5 ( V_17 ) ;
if ( V_56 )
return V_56 ;
F_166 ( V_62 -> V_64 ) ;
F_167 ( V_62 -> V_64 , V_291 , V_292 ) ;
F_58 ( V_17 ) ;
F_70 ( V_17 -> V_166 ) ;
F_147 () ;
V_56 = F_148 ( V_62 -> V_64 ) ;
if ( V_56 )
return V_56 ;
F_29 ( L_19 ) ;
F_168 ( V_17 ) ;
F_169 ( V_17 ) ;
return 0 ;
}
static int F_170 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_23 ( V_17 ) ;
F_29 ( L_16 , V_17 -> V_104 , V_185 ) ;
F_126 ( V_17 ) ;
F_171 ( V_17 ) ;
F_172 ( V_62 -> V_64 ) ;
F_167 ( V_62 -> V_64 , V_291 , V_293 ) ;
F_163 ( V_17 ) ;
F_1 () ;
return 0 ;
}
static int F_173 ( struct V_294 * V_295 )
{
struct V_16 * V_236 ;
struct V_61 * V_62 ;
struct V_294 * V_296 ;
struct V_297 * V_298 ;
int V_125 ;
V_236 = F_174 ( sizeof( struct V_61 ) ) ;
if ( ! V_236 )
return - V_47 ;
F_175 ( V_236 , & V_295 -> V_17 ) ;
F_176 ( V_295 , V_236 ) ;
V_62 = F_23 ( V_236 ) ;
V_62 -> V_236 = V_236 ;
* ( V_159 * ) ( & ( V_236 -> V_166 [ 0 ] ) ) = F_177 ( F_178 () ) ;
* ( V_161 * ) ( & ( V_236 -> V_166 [ 4 ] ) ) = F_179 ( ( V_57 ) F_180 () ) ;
F_73 ( 0x12345678 ) ;
if ( F_178 () != 0x12345678 ) {
F_181 ( & V_295 -> V_17 , L_20 ) ;
V_125 = - V_89 ;
goto V_299;
}
if ( ! F_165 ( V_236 -> V_166 ) ) {
if ( F_182 ( V_236 -> V_166 ) ||
! F_165 ( V_236 -> V_166 ) ) {
F_27 ( V_236 , L_21 ) ;
F_183 ( V_236 ) ;
}
}
F_70 ( V_236 -> V_166 ) ;
if ( ! F_184 ( & V_295 -> V_17 ) ) {
F_181 ( & V_295 -> V_17 , L_22 ) ;
V_125 = - V_89 ;
goto V_299;
}
V_296 = F_184 ( & V_295 -> V_17 ) ;
V_62 -> V_52 = F_185 ( V_296 ) ;
if ( ! V_62 -> V_52 ) {
F_181 ( & V_295 -> V_17 , L_23 ) ;
V_125 = - V_89 ;
goto V_299;
}
V_62 -> V_52 -> V_300 = V_236 ;
V_298 = F_184 ( & V_296 -> V_17 ) ;
V_125 = F_31 ( V_236 , V_298 -> V_79 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_24 ) ;
goto V_301;
}
V_62 -> V_155 = V_302 | V_298 -> V_155 ;
V_62 -> V_156 = V_302 | V_298 -> V_156 ;
F_186 ( V_236 ) ;
V_236 -> V_303 = & V_304 ;
V_236 -> V_305 = & V_306 ;
F_187 ( & V_62 -> V_237 ) ;
V_62 -> V_237 . V_44 = ( unsigned long ) V_62 ;
V_62 -> V_237 . V_307 = F_130 ;
F_120 ( & V_62 -> V_67 ) ;
V_125 = F_54 ( V_268 , F_141 ,
0 , L_25 , V_236 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_26 ) ;
V_125 = - V_165 ;
goto V_308;
}
V_125 = F_188 ( V_236 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_27 ) ;
goto V_309;
}
F_100 ( V_236 ) ;
V_125 = F_117 ( V_236 , & V_295 -> V_17 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_28 ) ;
goto V_310;
}
F_159 ( V_236 , L_29 , V_311 , V_117 ) ;
return 0 ;
V_310:
V_309:
F_55 ( V_268 , V_236 ) ;
V_308:
V_301:
F_189 ( V_62 -> V_52 ) ;
F_190 ( V_62 -> V_52 ) ;
V_299:
F_191 ( V_236 ) ;
return V_125 ;
}
static int F_192 ( struct V_294 * V_295 )
{
struct V_16 * V_236 = F_185 ( V_295 ) ;
struct V_61 * V_62 = F_23 ( V_236 ) ;
F_121 ( V_62 ) ;
V_62 -> V_52 -> V_300 = NULL ;
F_193 ( V_236 ) ;
F_55 ( V_268 , V_236 ) ;
F_191 ( V_236 ) ;
return 0 ;
}
static int F_194 ( struct V_294 * V_295 , T_7 V_312 )
{
struct V_16 * V_313 = F_185 ( V_295 ) ;
struct V_61 * V_62 = F_23 ( V_313 ) ;
if ( V_62 -> V_124 ) {
F_26 ( ( F_25 () & ~ V_244 ) | V_269 ) ;
F_195 ( V_314 ) ;
F_196 ( V_133 ) ;
} else {
if ( F_76 ( V_313 ) )
F_170 ( V_313 ) ;
}
return 0 ;
}
static int F_197 ( struct V_294 * V_295 )
{
struct V_16 * V_313 = F_185 ( V_295 ) ;
struct V_61 * V_62 = F_23 ( V_313 ) ;
if ( V_62 -> V_124 ) {
F_26 ( F_25 () | V_244 ) ;
F_195 ( 0 ) ;
F_198 ( V_133 ) ;
} else {
if ( F_76 ( V_313 ) )
F_164 ( V_313 ) ;
}
return 0 ;
}
static int F_199 ( struct V_294 * V_295 )
{
struct V_52 * V_315 ;
struct V_297 * V_316 ;
const unsigned short * V_317 ;
int V_125 , V_5 ;
V_316 = F_184 ( & V_295 -> V_17 ) ;
if ( ! V_316 ) {
F_181 ( & V_295 -> V_17 , L_30 ) ;
return - V_91 ;
}
V_317 = V_316 -> V_318 ;
V_125 = F_200 ( V_317 , V_115 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_31 ) ;
return V_125 ;
}
V_125 = - V_47 ;
V_315 = F_201 () ;
if ( V_315 == NULL )
goto V_319;
V_315 -> V_320 = F_14 ;
V_315 -> V_321 = F_19 ;
V_315 -> V_322 = F_21 ;
V_315 -> V_323 = & V_295 -> V_17 ;
V_315 -> V_104 = L_32 ;
V_315 -> V_324 = V_316 -> V_324 ;
snprintf ( V_315 -> V_325 , V_326 , L_33 ,
V_295 -> V_104 , V_295 -> V_325 ) ;
V_315 -> V_105 = F_202 ( sizeof( int ) * V_86 , V_327 ) ;
if ( ! V_315 -> V_105 )
goto V_328;
for ( V_5 = V_125 ; V_5 < V_86 ; ++ V_5 )
V_315 -> V_105 [ V_5 ] = V_148 ;
V_125 = F_203 ( V_316 -> V_329 , 0 , V_86 ) ;
if ( V_125 != V_316 -> V_329 )
F_181 ( & V_295 -> V_17 , L_34 ,
V_316 -> V_329 ) ;
for ( V_5 = 0 ; V_5 < V_125 ; ++ V_5 ) {
unsigned short V_330 = V_316 -> V_331 [ V_5 ] . V_164 ;
if ( V_330 < V_86 )
V_315 -> V_105 [ V_330 ] = V_316 -> V_331 [ V_5 ] . V_105 ;
else
F_181 ( & V_295 -> V_17 ,
L_35 ,
V_330 , V_5 ) ;
}
V_125 = F_204 ( V_315 ) ;
if ( V_125 ) {
F_181 ( & V_295 -> V_17 , L_36 ) ;
goto V_332;
}
F_176 ( V_295 , V_315 ) ;
return 0 ;
V_332:
F_205 ( V_315 -> V_105 ) ;
V_328:
F_190 ( V_315 ) ;
V_319:
F_206 ( V_317 ) ;
return V_125 ;
}
static int F_207 ( struct V_294 * V_295 )
{
struct V_52 * V_315 = F_185 ( V_295 ) ;
struct V_297 * V_316 =
F_184 ( & V_295 -> V_17 ) ;
F_189 ( V_315 ) ;
F_205 ( V_315 -> V_105 ) ;
F_190 ( V_315 ) ;
F_206 ( V_316 -> V_318 ) ;
return 0 ;
}
static int T_8 F_208 ( void )
{
int V_56 ;
V_56 = F_209 ( & V_333 ) ;
if ( ! V_56 )
return F_209 ( & V_334 ) ;
return - V_89 ;
}
static void T_9 F_210 ( void )
{
F_211 ( & V_334 ) ;
F_211 ( & V_333 ) ;
}
