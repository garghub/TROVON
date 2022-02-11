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
static void F_21 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
struct V_63 * V_64 = V_62 -> V_64 ;
unsigned long V_65 ;
int V_66 = 0 ;
F_23 ( & V_62 -> V_67 , V_65 ) ;
if ( V_64 -> V_68 ) {
if ( V_64 -> V_69 != V_62 -> V_70 ) {
V_59 V_71 = F_24 () ;
V_66 = 1 ;
if ( V_64 -> V_69 )
V_71 |= V_72 ;
else
V_71 &= ~ ( V_72 ) ;
F_25 ( V_71 ) ;
V_62 -> V_70 = V_64 -> V_69 ;
}
if ( V_64 -> V_73 != V_62 -> V_74 ) {
if ( V_64 -> V_75 == V_76 ) {
V_59 V_71 = F_24 () ;
switch ( V_64 -> V_73 ) {
case 10 :
V_71 |= V_77 ;
break;
case 100 :
V_71 &= ~ V_77 ;
break;
default:
F_26 ( V_17 ,
L_3 ,
V_64 -> V_73 ) ;
break;
}
F_25 ( V_71 ) ;
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
V_59 V_71 = F_24 () ;
F_27 ( V_64 ) ;
F_28 ( L_4 , V_71 ) ;
}
F_29 ( & V_62 -> V_67 , V_65 ) ;
}
static int F_30 ( struct V_16 * V_17 , int V_79 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
struct V_63 * V_64 ;
unsigned short V_80 ;
V_59 V_81 , V_82 ;
if ( ! ( F_31 () & V_83 ) )
F_32 ( F_31 () | V_83 ) ;
V_81 = F_33 () ;
V_82 = ( ( V_81 / V_84 ) / 2 ) - 1 ;
V_80 = F_34 () ;
V_80 = ( V_80 & ~ V_85 ) | F_35 ( V_82 ) ;
F_36 ( V_80 ) ;
V_64 = F_37 ( V_62 -> V_52 ) ;
if ( ! V_64 ) {
F_38 ( V_17 , L_5 ) ;
return - V_86 ;
}
if ( V_79 != V_76 &&
V_79 != V_87 ) {
F_38 ( V_17 , L_6 ) ;
return - V_88 ;
}
V_64 = F_39 ( V_17 , F_40 ( V_64 ) ,
& F_21 , V_79 ) ;
if ( F_41 ( V_64 ) ) {
F_38 ( V_17 , L_7 ) ;
return F_42 ( V_64 ) ;
}
V_64 -> V_89 &= ( V_90
| V_91
| V_92
| V_93
| V_94
| V_95 | V_96
| V_97
| V_98 ) ;
V_64 -> V_99 = V_64 -> V_89 ;
V_62 -> V_78 = 0 ;
V_62 -> V_74 = 0 ;
V_62 -> V_70 = - 1 ;
V_62 -> V_64 = V_64 ;
F_43 ( V_64 , L_8 ,
V_84 , V_82 , V_81 / 1000000 ) ;
return 0 ;
}
static T_2 F_44 ( int V_100 , void * V_101 )
{
return V_102 ;
}
static int
F_45 ( struct V_16 * V_17 , struct V_103 * V_104 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
if ( V_62 -> V_64 )
return F_46 ( V_62 -> V_64 , V_104 ) ;
return - V_88 ;
}
static int
F_47 ( struct V_16 * V_17 , struct V_103 * V_104 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
if ( ! F_48 ( V_105 ) )
return - V_106 ;
if ( V_62 -> V_64 )
return F_49 ( V_62 -> V_64 , V_104 ) ;
return - V_88 ;
}
static void F_50 ( struct V_16 * V_17 ,
struct V_107 * V_108 )
{
F_51 ( V_108 -> V_109 , V_110 , sizeof( V_108 -> V_109 ) ) ;
F_51 ( V_108 -> V_111 , V_112 , sizeof( V_108 -> V_111 ) ) ;
F_51 ( V_108 -> V_113 , L_9 , sizeof( V_108 -> V_113 ) ) ;
F_51 ( V_108 -> V_114 , F_52 ( & V_17 -> V_17 ) , sizeof( V_108 -> V_114 ) ) ;
}
static void F_53 ( struct V_16 * V_17 ,
struct V_115 * V_116 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
V_116 -> V_89 = V_117 ;
V_116 -> V_118 = V_62 -> V_119 ;
}
static int F_54 ( struct V_16 * V_17 ,
struct V_115 * V_116 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
int V_120 ;
if ( V_116 -> V_118 & ( V_121 |
V_122 |
V_123 |
V_124 |
V_125 ) )
return - V_126 ;
V_62 -> V_119 = V_116 -> V_118 ;
if ( V_62 -> V_119 && ! V_62 -> V_127 ) {
V_120 = F_55 ( V_128 , F_44 ,
0 , L_10 , V_17 ) ;
if ( V_120 )
return V_120 ;
V_62 -> V_127 = true ;
}
if ( ! V_62 -> V_119 && V_62 -> V_127 ) {
F_56 ( V_128 , V_17 ) ;
V_62 -> V_127 = false ;
}
F_57 ( & V_17 -> V_17 , V_62 -> V_119 ) ;
return 0 ;
}
static int F_58 ( struct V_16 * V_17 ,
struct V_129 * V_108 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
V_108 -> V_130 =
V_131 |
V_132 |
V_133 ;
V_108 -> V_134 = V_62 -> V_134 ;
V_108 -> V_135 =
( 1 << V_136 ) |
( 1 << V_137 ) ;
V_108 -> V_138 =
( 1 << V_139 ) |
( 1 << V_140 ) |
( 1 << V_141 ) |
( 1 << V_142 ) ;
return 0 ;
}
static void F_59 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
int V_5 ;
unsigned short V_80 ;
V_80 = F_34 () ;
for ( V_5 = 0 ; V_5 < V_143 ; ++ V_5 )
if ( V_62 -> V_52 -> V_100 [ V_5 ] != V_144 )
break;
if ( V_5 < V_143 )
V_80 |= V_145 ;
V_80 |= V_146 ;
#if F_2 ( V_147 )
V_80 |= V_148 ;
#else
V_80 &= ~ V_148 ;
#endif
F_36 ( V_80 ) ;
F_60 ( V_149 | V_150 ) ;
F_61 ( V_62 -> V_151 ) ;
F_62 ( V_62 -> V_152 ) ;
F_63 ( 0 ) ;
F_64 ( 4 ) ;
F_65 ( 0 ) ;
F_66 ( 0 ) ;
F_67 ( 0 ) ;
F_68 ( 4 ) ;
F_69 ( 0 ) ;
F_70 ( 0 ) ;
}
static void F_71 ( T_3 * V_153 )
{
V_59 V_154 = F_72 ( * ( V_155 * ) & V_153 [ 0 ] ) ;
V_57 V_156 = F_73 ( * ( V_157 * ) & V_153 [ 4 ] ) ;
F_74 ( V_154 ) ;
F_75 ( V_156 ) ;
}
static int F_76 ( struct V_16 * V_17 , void * V_158 )
{
struct V_159 * V_160 = V_158 ;
if ( F_77 ( V_17 ) )
return - V_161 ;
memcpy ( V_17 -> V_162 , V_160 -> V_163 , V_17 -> V_164 ) ;
F_71 ( V_17 -> V_162 ) ;
return 0 ;
}
static V_59 F_78 ( V_59 V_165 , unsigned int * V_166 )
{
V_59 V_167 = 1000000000UL / V_165 ;
V_59 V_168 = 1 ;
unsigned int V_169 = 0 ;
while ( V_168 <= V_167 ) {
V_168 <<= 1 ;
V_169 ++ ;
}
* V_166 = V_169 ;
return 1000000000UL / V_168 ;
}
static int F_79 ( struct V_16 * V_170 ,
struct V_171 * V_172 )
{
struct V_173 V_27 ;
struct V_61 * V_62 = F_22 ( V_170 ) ;
V_57 V_174 ;
V_59 V_175 , V_176 , V_177 , V_178 ;
if ( F_80 ( & V_27 , V_172 -> V_179 , sizeof( V_27 ) ) )
return - V_180 ;
F_28 ( L_11 ,
V_181 , V_27 . V_65 , V_27 . V_182 , V_27 . V_183 ) ;
if ( V_27 . V_65 )
return - V_88 ;
if ( ( V_27 . V_182 != V_136 ) &&
( V_27 . V_182 != V_137 ) )
return - V_184 ;
V_174 = F_81 () ;
switch ( V_27 . V_183 ) {
case V_139 :
V_177 = 0xFFFFFFFF ;
F_82 ( V_177 ) ;
break;
case V_140 :
case V_185 :
case V_186 :
V_174 &= ~ 0x1F00 ;
F_83 ( V_174 ) ;
V_178 = 0x4A24170C ;
F_84 ( V_178 ) ;
V_175 = 0x11040800 ;
F_85 ( V_175 ) ;
V_176 = 0x0140013F ;
F_86 ( V_176 ) ;
V_177 = 0xFFFFFFFC ;
F_82 ( V_177 ) ;
V_27 . V_183 = V_140 ;
break;
case V_142 :
case V_187 :
case V_188 :
V_174 &= ~ 0x1F00 ;
F_83 ( V_174 ) ;
V_178 = 0x2A24170C ;
F_84 ( V_178 ) ;
V_175 = 0x11040800 ;
F_85 ( V_175 ) ;
V_176 = 0x0140013F ;
F_86 ( V_176 ) ;
V_177 = 0xFFFFFFF0 ;
F_82 ( V_177 ) ;
V_27 . V_183 = V_142 ;
break;
case V_141 :
case V_189 :
case V_190 :
V_174 &= ~ 0x1100 ;
F_83 ( V_174 ) ;
V_178 = 0x0E24170C ;
F_84 ( V_178 ) ;
V_175 = 0x110488F7 ;
F_85 ( V_175 ) ;
V_176 = 0x0140013F ;
F_86 ( V_176 ) ;
V_177 = 0xFFFFFFF0 ;
F_82 ( V_177 ) ;
V_27 . V_183 = V_141 ;
break;
default:
return - V_184 ;
}
if ( V_27 . V_182 == V_136 &&
F_87 ( V_27 . V_183 ) ) {
V_174 &= ~ V_191 ;
F_83 ( V_174 ) ;
F_88 () ;
} else {
V_174 |= V_191 ;
F_83 ( V_174 ) ;
F_89 () ;
F_90 () ;
F_91 () ;
F_92 () ;
F_88 () ;
}
V_62 -> V_192 = V_27 ;
return F_93 ( V_172 -> V_179 , & V_27 , sizeof( V_27 ) ) ?
- V_180 : 0 ;
}
static int F_94 ( struct V_16 * V_170 ,
struct V_171 * V_172 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
return F_93 ( V_172 -> V_179 , & V_62 -> V_192 ,
sizeof( V_62 -> V_192 ) ) ?
- V_180 : 0 ;
}
static void F_95 ( struct V_16 * V_170 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
if ( F_96 ( V_11 ) -> V_193 & V_194 ) {
int V_48 = V_49 ;
F_96 ( V_11 ) -> V_193 |= V_195 ;
while ( ( ! ( F_97 () & V_196 ) ) && ( -- V_48 ) )
F_13 ( 1 ) ;
if ( V_48 == 0 )
F_38 ( V_170 , L_12 ) ;
else {
struct V_197 V_198 ;
T_4 V_199 ;
T_4 V_200 ;
V_200 = F_91 () ;
V_200 |= ( T_4 ) F_92 () << 32 ;
memset ( & V_198 , 0 , sizeof( V_198 ) ) ;
V_199 = V_200 << V_62 -> V_169 ;
V_198 . V_201 = F_98 ( V_199 ) ;
F_99 ( V_11 , & V_198 ) ;
}
}
}
static void F_100 ( struct V_16 * V_170 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
V_59 V_202 ;
T_4 V_200 , V_199 ;
struct V_197 * V_198 ;
if ( F_87 ( V_62 -> V_192 . V_183 ) )
return;
V_202 = F_97 () & V_203 ;
if ( ! V_202 )
return;
V_198 = F_101 ( V_11 ) ;
V_200 = F_89 () ;
V_200 |= ( T_4 ) F_90 () << 32 ;
V_199 = V_200 << V_62 -> V_169 ;
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
V_198 -> V_201 = F_98 ( V_199 ) ;
}
static void F_102 ( struct V_16 * V_170 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
T_4 V_204 , V_205 ;
V_59 V_165 , V_206 ;
V_165 = F_33 () ;
V_206 = F_78 ( V_165 , & V_62 -> V_169 ) ;
V_204 = V_206 * ( 1ULL << 32 ) ;
F_103 ( V_204 , V_165 ) ;
F_104 ( ( V_59 ) V_204 ) ;
V_62 -> V_204 = V_204 ;
V_205 = 1000000000ULL * V_165 ;
F_103 ( V_205 , V_206 ) ;
V_62 -> V_207 = V_205 - 1000000000ULL - 1ULL ;
V_62 -> V_192 . V_183 = V_139 ;
V_62 -> V_192 . V_182 = V_136 ;
}
static T_4 F_105 ( struct V_61 * V_62 )
{
T_4 V_199 ;
V_59 V_208 , V_209 ;
V_208 = F_106 () ;
V_209 = F_107 () ;
V_199 = ( ( T_4 ) V_209 ) << 32 ;
V_199 |= V_208 ;
V_199 <<= V_62 -> V_169 ;
return V_199 ;
}
static void F_108 ( struct V_61 * V_62 , T_4 V_199 )
{
V_59 V_209 , V_208 ;
V_199 >>= V_62 -> V_169 ;
V_209 = V_199 >> 32 ;
V_208 = V_199 & 0xffffffff ;
F_109 ( V_208 ) ;
F_110 ( V_209 ) ;
}
static int F_111 ( struct V_210 * V_211 , T_5 V_205 )
{
T_4 V_212 ;
V_59 V_213 , V_204 ;
int V_214 = 0 ;
struct V_61 * V_62 =
F_112 ( V_211 , struct V_61 , V_215 ) ;
if ( V_205 < 0 ) {
V_214 = 1 ;
V_205 = - V_205 ;
}
V_204 = V_62 -> V_204 ;
V_212 = V_204 ;
V_212 *= V_205 ;
V_213 = F_113 ( V_212 , 1000000000ULL ) ;
V_204 = V_214 ? V_204 - V_213 : V_204 + V_213 ;
F_104 ( V_204 ) ;
return 0 ;
}
static int F_114 ( struct V_210 * V_211 , T_6 V_216 )
{
T_6 V_217 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_112 ( V_211 , struct V_61 , V_215 ) ;
F_23 ( & V_62 -> V_218 , V_65 ) ;
V_217 = F_105 ( V_62 ) ;
V_217 += V_216 ;
F_108 ( V_62 , V_217 ) ;
F_29 ( & V_62 -> V_218 , V_65 ) ;
return 0 ;
}
static int F_115 ( struct V_210 * V_211 , struct V_219 * V_220 )
{
T_4 V_199 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_112 ( V_211 , struct V_61 , V_215 ) ;
F_23 ( & V_62 -> V_218 , V_65 ) ;
V_199 = F_105 ( V_62 ) ;
F_29 ( & V_62 -> V_218 , V_65 ) ;
* V_220 = F_116 ( V_199 ) ;
return 0 ;
}
static int F_117 ( struct V_210 * V_211 ,
const struct V_219 * V_220 )
{
T_4 V_199 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_112 ( V_211 , struct V_61 , V_215 ) ;
V_199 = F_118 ( V_220 ) ;
F_23 ( & V_62 -> V_218 , V_65 ) ;
F_108 ( V_62 , V_199 ) ;
F_29 ( & V_62 -> V_218 , V_65 ) ;
return 0 ;
}
static int F_119 ( struct V_210 * V_211 ,
struct V_221 * V_222 , int V_223 )
{
return - V_126 ;
}
static int F_120 ( struct V_16 * V_170 , struct V_224 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
V_62 -> V_215 = V_225 ;
V_62 -> V_215 . V_226 = V_62 -> V_207 ;
V_62 -> clock = F_121 ( & V_62 -> V_215 , V_17 ) ;
if ( F_41 ( V_62 -> clock ) )
return F_42 ( V_62 -> clock ) ;
V_62 -> V_134 = F_122 ( V_62 -> clock ) ;
F_123 ( & V_62 -> V_218 ) ;
return 0 ;
}
static void F_124 ( struct V_61 * V_62 )
{
F_125 ( V_62 -> clock ) ;
}
static inline void F_126 ( void )
{
do {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_227 = 0 ;
if ( V_9 -> V_11 ) {
F_127 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
} while ( V_9 -> V_37 . V_227 != 0 );
}
static void F_128 ( struct V_61 * V_62 )
{
int V_48 = V_49 ;
if ( V_9 -> V_37 . V_227 != 0 )
F_126 () ;
if ( V_38 -> V_12 == V_9 ) {
while ( V_9 -> V_37 . V_227 == 0 ) {
F_13 ( 10 ) ;
if ( ! ( F_129 () & V_228 ) )
break;
if ( V_48 -- < 0 )
break;
}
if ( V_48 >= 0 )
F_126 () ;
else
F_130 ( V_62 -> V_229 ) ;
}
if ( V_38 -> V_12 != V_9 &&
F_131 ( V_62 -> V_229 ) )
F_132 ( V_62 -> V_229 ) ;
if ( V_9 != V_38 ) {
if ( F_131 ( V_62 -> V_229 ) )
V_62 -> V_230 . V_231 =
V_232 + ( V_233 >> 4 ) ;
else
V_62 -> V_230 . V_231 =
V_232 + V_233 ;
F_133 ( & V_62 -> V_230 ,
V_62 -> V_230 . V_231 ) ;
}
return;
}
static void F_134 ( unsigned long V_62 )
{
F_128 ( (struct V_61 * ) V_62 ) ;
}
static int F_135 ( struct V_18 * V_11 ,
struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
V_57 * V_44 ;
V_59 V_234 = ( unsigned long ) ( V_11 -> V_44 ) & 0x3 ;
V_38 -> V_11 = V_11 ;
if ( V_234 == 0x2 ) {
V_44 = ( V_57 * ) ( V_11 -> V_44 ) - 1 ;
* V_44 = ( V_57 ) ( V_11 -> V_235 ) ;
if ( F_96 ( V_11 ) -> V_193 & V_194 )
* V_44 |= 0x1000 ;
V_38 -> V_24 . V_31 = ( V_59 ) V_44 ;
F_136 ( ( V_59 ) V_44 ,
( V_59 ) ( ( T_3 * ) V_44 + V_11 -> V_235 + 4 ) ) ;
} else {
* ( ( V_57 * ) ( V_38 -> V_32 ) ) = ( V_57 ) ( V_11 -> V_235 ) ;
if ( F_96 ( V_11 ) -> V_193 & V_194 )
* ( ( V_57 * ) ( V_38 -> V_32 ) ) |= 0x1000 ;
memcpy ( ( T_3 * ) ( V_38 -> V_32 + 2 ) , V_11 -> V_44 ,
V_11 -> V_235 ) ;
V_38 -> V_24 . V_31 =
( V_59 ) V_38 -> V_32 ;
F_136 (
( V_59 ) V_38 -> V_32 ,
( V_59 ) ( V_38 -> V_32 + V_11 -> V_235 + 2 ) ) ;
}
F_88 () ;
V_38 -> V_37 . V_227 = 0 ;
V_38 -> V_24 . V_27 |= V_35 ;
if ( F_129 () & V_228 )
goto V_236;
F_137 ( & ( V_38 -> V_24 ) ) ;
F_138 ( V_38 -> V_24 . V_27 ) ;
F_25 ( F_24 () | V_237 ) ;
V_236:
F_95 ( V_17 , V_11 ) ;
V_38 = V_38 -> V_12 ;
V_17 -> V_238 . V_239 ++ ;
V_17 -> V_238 . V_240 += ( V_11 -> V_235 ) ;
F_128 ( V_62 ) ;
return V_241 ;
}
static void F_139 ( struct V_61 * V_62 )
{
struct V_16 * V_17 = V_62 -> V_229 ;
struct V_18 * V_11 , * V_19 ;
unsigned short V_235 ;
#if F_2 ( V_147 )
unsigned int V_5 ;
unsigned char V_242 [ V_243 + 1 ] ;
#endif
if ( V_46 -> V_37 . V_227 & V_244 ) {
F_140 ( V_17 , L_13 ) ;
V_17 -> V_238 . V_245 ++ ;
goto V_236;
}
V_11 = V_46 -> V_11 ;
V_19 = F_7 ( V_17 , V_40 + V_41 ) ;
if ( ! V_19 ) {
V_17 -> V_238 . V_245 ++ ;
goto V_236;
}
F_8 ( V_19 , V_41 ) ;
F_9 ( ( unsigned long ) V_19 -> V_42 ,
( unsigned long ) V_19 -> V_43 ) ;
V_46 -> V_11 = V_19 ;
V_46 -> V_24 . V_31 = ( unsigned long ) V_19 -> V_44 - 2 ;
V_235 = ( unsigned short ) ( V_46 -> V_37 . V_227 & V_246 ) ;
V_235 -= V_243 ;
F_141 ( V_11 , V_235 ) ;
V_11 -> V_247 = F_142 ( V_11 , V_17 ) ;
F_100 ( V_17 , V_11 ) ;
#if F_2 ( V_147 )
if ( V_11 -> V_44 [ V_248 ] == 0x45 ) {
V_11 -> V_249 = V_46 -> V_37 . V_250 ;
if ( V_11 -> V_235 % 2 ) {
V_242 [ 0 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_243 ; V_5 ++ )
V_242 [ V_5 + 1 ] = ~ V_11 -> V_44 [ V_11 -> V_235 + V_5 ] ;
V_11 -> V_249 = F_143 ( V_242 , V_243 + 1 , V_11 -> V_249 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_243 ; V_5 ++ )
V_242 [ V_5 ] = ~ V_11 -> V_44 [ V_11 -> V_235 + V_5 ] ;
V_11 -> V_249 = F_143 ( V_242 , V_243 , V_11 -> V_249 ) ;
}
V_11 -> V_251 = V_252 ;
}
#endif
F_144 ( & V_62 -> V_253 , V_11 ) ;
V_17 -> V_238 . V_254 ++ ;
V_17 -> V_238 . V_255 += V_235 ;
V_236:
V_46 -> V_37 . V_227 = 0x00000000 ;
V_46 = V_46 -> V_12 ;
}
static int F_145 ( struct V_256 * V_253 , int V_257 )
{
int V_5 = 0 ;
struct V_61 * V_62 = F_112 ( V_253 ,
struct V_61 ,
V_253 ) ;
while ( V_46 -> V_37 . V_227 != 0 && V_5 < V_257 ) {
F_139 ( V_62 ) ;
V_5 ++ ;
}
if ( V_5 < V_257 ) {
F_146 ( V_253 ) ;
if ( F_147 ( V_258 , & V_62 -> V_65 ) )
F_148 ( V_259 ) ;
}
return V_5 ;
}
static T_2 F_149 ( int V_100 , void * V_101 )
{
struct V_61 * V_62 = F_22 ( V_101 ) ;
V_59 V_37 ;
V_37 = F_150 () ;
F_151 ( V_37 | V_260 | V_261 ) ;
if ( V_37 & V_260 ) {
F_152 ( V_259 ) ;
F_153 ( V_258 , & V_62 -> V_65 ) ;
F_154 ( & V_62 -> V_253 ) ;
}
return V_102 ;
}
static void F_155 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
F_149 ( V_259 , V_17 ) ;
F_128 ( V_62 ) ;
}
static void F_156 ( void )
{
unsigned int V_71 ;
V_71 = F_24 () ;
V_71 &= ( ~ V_262 ) ;
V_71 &= ( ~ V_237 ) ;
F_25 ( V_71 ) ;
}
static int F_157 ( struct V_63 * V_64 )
{
int V_56 ;
V_59 V_71 ;
F_28 ( L_14 , V_181 ) ;
F_158 ( & ( V_14 -> V_24 ) ) ;
F_159 ( V_14 -> V_24 . V_27 ) ;
V_56 = F_11 () ;
if ( V_56 )
return V_56 ;
V_71 = F_24 () ;
if ( V_71 & V_72 )
V_71 |= V_263 ;
else
V_71 |= V_264 | V_265 | V_263 ;
V_71 |= V_262 ;
if ( V_64 -> V_75 == V_76 ) {
V_71 |= V_266 ;
#if F_2 ( V_267 ) || F_2 ( V_268 )
if ( V_269 < 3 ) {
V_71 |= V_237 ;
}
#endif
}
F_25 ( V_71 ) ;
return 0 ;
}
static void F_160 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
F_28 ( L_15 , V_17 -> V_270 , V_181 ) ;
F_156 () ;
F_161 ( & V_62 -> V_230 ) ;
while ( V_9 != V_38 ) {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_227 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
}
if ( F_131 ( V_17 ) )
F_132 ( V_17 ) ;
F_157 ( V_62 -> V_64 ) ;
V_17 -> V_271 = V_232 ;
}
static void F_162 ( struct V_16 * V_17 )
{
V_59 V_272 , V_273 ;
struct V_274 * V_275 ;
V_59 V_276 ;
V_272 = V_273 = 0 ;
F_163 (ha, dev) {
V_276 = F_164 ( V_277 , V_275 -> V_160 ) ;
V_276 >>= 26 ;
if ( V_276 & 0x20 )
V_272 |= 1 << ( V_276 & 0x1f ) ;
else
V_273 |= 1 << ( V_276 & 0x1f ) ;
}
F_165 ( V_272 ) ;
F_166 ( V_273 ) ;
}
static void F_167 ( struct V_16 * V_17 )
{
V_59 V_80 ;
if ( V_17 -> V_65 & V_278 ) {
F_168 ( V_17 , L_16 ) ;
V_80 = F_24 () ;
V_80 |= V_279 ;
F_25 ( V_80 ) ;
} else if ( V_17 -> V_65 & V_280 ) {
V_80 = F_24 () ;
V_80 |= V_281 ;
F_25 ( V_80 ) ;
} else if ( ! F_169 ( V_17 ) ) {
V_80 = F_24 () ;
V_80 |= V_282 ;
F_25 ( V_80 ) ;
F_162 ( V_17 ) ;
} else {
V_80 = F_24 () ;
V_80 &= ~ ( V_283 | V_281 ) ;
F_25 ( V_80 ) ;
}
}
static int F_170 ( struct V_16 * V_170 , struct V_171 * V_172 , int V_104 )
{
struct V_61 * V_62 = F_22 ( V_170 ) ;
if ( ! F_77 ( V_170 ) )
return - V_88 ;
switch ( V_104 ) {
case V_284 :
return F_79 ( V_170 , V_172 ) ;
case V_285 :
return F_94 ( V_170 , V_172 ) ;
default:
if ( V_62 -> V_64 )
return F_171 ( V_62 -> V_64 , V_172 , V_104 ) ;
else
return - V_126 ;
}
}
static void F_172 ( struct V_16 * V_17 )
{
F_25 ( 0x00000000 ) ;
F_159 ( 0x0000 ) ;
F_138 ( 0x0000 ) ;
}
static int F_173 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
int V_56 ;
F_28 ( L_15 , V_17 -> V_270 , V_181 ) ;
if ( ! F_174 ( V_17 -> V_162 ) ) {
F_26 ( V_17 , L_17 ) ;
return - V_88 ;
}
V_56 = F_5 ( V_17 ) ;
if ( V_56 )
return V_56 ;
F_175 ( V_62 -> V_64 ) ;
F_59 ( V_17 ) ;
F_71 ( V_17 -> V_162 ) ;
F_156 () ;
V_56 = F_157 ( V_62 -> V_64 ) ;
if ( V_56 )
return V_56 ;
F_28 ( L_18 ) ;
F_176 ( & V_62 -> V_253 ) ;
F_177 ( V_17 ) ;
F_178 ( V_17 ) ;
return 0 ;
}
static int F_179 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_22 ( V_17 ) ;
F_28 ( L_15 , V_17 -> V_270 , V_181 ) ;
F_130 ( V_17 ) ;
F_180 ( & V_62 -> V_253 ) ;
F_181 ( V_17 ) ;
F_182 ( V_62 -> V_64 ) ;
F_183 ( V_62 -> V_64 , V_286 , V_287 ) ;
F_172 ( V_17 ) ;
F_1 () ;
return 0 ;
}
static int F_184 ( struct V_288 * V_289 )
{
struct V_16 * V_229 ;
struct V_61 * V_62 ;
struct V_288 * V_290 ;
struct V_291 * V_292 ;
int V_120 ;
V_229 = F_185 ( sizeof( struct V_61 ) ) ;
if ( ! V_229 )
return - V_47 ;
F_186 ( V_229 , & V_289 -> V_17 ) ;
F_187 ( V_289 , V_229 ) ;
V_62 = F_22 ( V_229 ) ;
V_62 -> V_229 = V_229 ;
* ( V_155 * ) ( & ( V_229 -> V_162 [ 0 ] ) ) = F_188 ( F_189 () ) ;
* ( V_157 * ) ( & ( V_229 -> V_162 [ 4 ] ) ) = F_190 ( ( V_57 ) F_191 () ) ;
F_74 ( 0x12345678 ) ;
if ( F_189 () != 0x12345678 ) {
F_192 ( & V_289 -> V_17 , L_19 ) ;
V_120 = - V_86 ;
goto V_293;
}
if ( ! F_174 ( V_229 -> V_162 ) ) {
if ( F_193 ( V_229 -> V_162 ) ||
! F_174 ( V_229 -> V_162 ) ) {
F_26 ( V_229 , L_20 ) ;
F_194 ( V_229 ) ;
}
}
F_71 ( V_229 -> V_162 ) ;
if ( ! F_195 ( & V_289 -> V_17 ) ) {
F_192 ( & V_289 -> V_17 , L_21 ) ;
V_120 = - V_86 ;
goto V_293;
}
V_290 = F_195 ( & V_289 -> V_17 ) ;
V_62 -> V_52 = F_196 ( V_290 ) ;
if ( ! V_62 -> V_52 ) {
F_192 ( & V_289 -> V_17 , L_22 ) ;
V_120 = - V_86 ;
goto V_293;
}
V_62 -> V_52 -> V_294 = V_229 ;
V_292 = F_195 ( & V_290 -> V_17 ) ;
V_120 = F_30 ( V_229 , V_292 -> V_79 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_23 ) ;
goto V_295;
}
V_62 -> V_151 = V_296 | V_292 -> V_151 ;
V_62 -> V_152 = V_296 | V_292 -> V_152 ;
V_229 -> V_297 = & V_298 ;
V_229 -> V_299 = & V_300 ;
F_197 ( & V_62 -> V_230 ) ;
V_62 -> V_230 . V_44 = ( unsigned long ) V_62 ;
V_62 -> V_230 . V_301 = F_134 ;
V_62 -> V_65 = 0 ;
F_198 ( V_229 , & V_62 -> V_253 , F_145 , V_15 ) ;
F_123 ( & V_62 -> V_67 ) ;
V_120 = F_55 ( V_259 , F_149 ,
0 , L_24 , V_229 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_25 ) ;
V_120 = - V_161 ;
goto V_302;
}
V_120 = F_199 ( V_229 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_26 ) ;
goto V_303;
}
F_102 ( V_229 ) ;
V_120 = F_120 ( V_229 , & V_289 -> V_17 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_27 ) ;
goto V_304;
}
F_168 ( V_229 , L_28 , V_305 , V_112 ) ;
return 0 ;
V_304:
V_303:
F_56 ( V_259 , V_229 ) ;
V_302:
F_200 ( & V_62 -> V_253 ) ;
V_295:
F_201 ( V_62 -> V_52 ) ;
F_202 ( V_62 -> V_52 ) ;
V_293:
F_203 ( V_229 ) ;
return V_120 ;
}
static int F_204 ( struct V_288 * V_289 )
{
struct V_16 * V_229 = F_196 ( V_289 ) ;
struct V_61 * V_62 = F_22 ( V_229 ) ;
F_124 ( V_62 ) ;
V_62 -> V_52 -> V_294 = NULL ;
F_205 ( V_229 ) ;
F_200 ( & V_62 -> V_253 ) ;
F_56 ( V_259 , V_229 ) ;
F_203 ( V_229 ) ;
return 0 ;
}
static int F_206 ( struct V_288 * V_289 , T_7 V_306 )
{
struct V_16 * V_307 = F_196 ( V_289 ) ;
struct V_61 * V_62 = F_22 ( V_307 ) ;
if ( V_62 -> V_119 ) {
F_25 ( ( F_24 () & ~ V_237 ) | V_262 ) ;
F_207 ( V_308 ) ;
F_208 ( V_128 ) ;
} else {
if ( F_77 ( V_307 ) )
F_179 ( V_307 ) ;
}
return 0 ;
}
static int F_209 ( struct V_288 * V_289 )
{
struct V_16 * V_307 = F_196 ( V_289 ) ;
struct V_61 * V_62 = F_22 ( V_307 ) ;
if ( V_62 -> V_119 ) {
F_25 ( F_24 () | V_237 ) ;
F_207 ( 0 ) ;
F_210 ( V_128 ) ;
} else {
if ( F_77 ( V_307 ) )
F_173 ( V_307 ) ;
}
return 0 ;
}
static int F_211 ( struct V_288 * V_289 )
{
struct V_52 * V_309 ;
struct V_291 * V_310 ;
const unsigned short * V_311 ;
int V_120 , V_5 ;
V_310 = F_195 ( & V_289 -> V_17 ) ;
if ( ! V_310 ) {
F_192 ( & V_289 -> V_17 , L_29 ) ;
return - V_88 ;
}
V_311 = V_310 -> V_312 ;
V_120 = F_212 ( V_311 , V_110 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_30 ) ;
return V_120 ;
}
V_120 = - V_47 ;
V_309 = F_213 () ;
if ( V_309 == NULL )
goto V_313;
V_309 -> V_314 = F_14 ;
V_309 -> V_315 = F_19 ;
V_309 -> V_316 = & V_289 -> V_17 ;
V_309 -> V_270 = L_31 ;
V_309 -> V_317 = V_310 -> V_317 ;
snprintf ( V_309 -> V_318 , V_319 , L_32 ,
V_289 -> V_270 , V_289 -> V_318 ) ;
V_120 = F_214 ( V_310 -> V_320 , 0 , V_143 ) ;
if ( V_120 != V_310 -> V_320 )
F_192 ( & V_289 -> V_17 , L_33 ,
V_310 -> V_320 ) ;
for ( V_5 = 0 ; V_5 < V_120 ; ++ V_5 ) {
unsigned short V_321 = V_310 -> V_322 [ V_5 ] . V_160 ;
if ( V_321 < V_143 )
V_309 -> V_100 [ V_321 ] = V_310 -> V_322 [ V_5 ] . V_100 ;
else
F_192 ( & V_289 -> V_17 ,
L_34 ,
V_321 , V_5 ) ;
}
V_120 = F_215 ( V_309 ) ;
if ( V_120 ) {
F_192 ( & V_289 -> V_17 , L_35 ) ;
goto V_323;
}
F_187 ( V_289 , V_309 ) ;
return 0 ;
V_323:
F_202 ( V_309 ) ;
V_313:
F_216 ( V_311 ) ;
return V_120 ;
}
static int F_217 ( struct V_288 * V_289 )
{
struct V_52 * V_309 = F_196 ( V_289 ) ;
struct V_291 * V_310 =
F_195 ( & V_289 -> V_17 ) ;
F_201 ( V_309 ) ;
F_202 ( V_309 ) ;
F_216 ( V_310 -> V_312 ) ;
return 0 ;
}
static int T_8 F_218 ( void )
{
return F_219 ( V_324 , F_220 ( V_324 ) ) ;
}
static void T_9 F_221 ( void )
{
F_222 ( V_324 , F_220 ( V_324 ) ) ;
}
