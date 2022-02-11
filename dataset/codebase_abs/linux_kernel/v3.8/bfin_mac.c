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
V_64 = F_40 ( V_17 , F_41 ( & V_64 -> V_17 ) , & F_23 ,
0 , V_79 ) ;
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
strcpy ( V_113 -> V_114 , V_115 ) ;
strcpy ( V_113 -> V_116 , V_117 ) ;
strcpy ( V_113 -> V_118 , L_11 ) ;
strcpy ( V_113 -> V_119 , F_41 ( & V_17 -> V_17 ) ) ;
}
static void F_52 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
V_121 -> V_92 = V_122 ;
V_121 -> V_123 = V_62 -> V_124 ;
}
static int F_53 ( struct V_16 * V_17 ,
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
V_125 = F_54 ( V_133 , F_45 ,
V_134 , L_12 , V_17 ) ;
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
static void F_58 ( struct V_16 * V_17 )
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
F_59 ( V_154 | V_155 ) ;
F_60 ( V_62 -> V_156 ) ;
F_61 ( V_62 -> V_157 ) ;
F_62 ( 0 ) ;
F_63 ( 4 ) ;
F_64 ( 0 ) ;
F_65 ( 0 ) ;
F_66 ( 0 ) ;
F_67 ( 4 ) ;
F_68 ( 0 ) ;
F_69 ( 0 ) ;
}
static void F_70 ( T_3 * V_158 )
{
V_59 V_159 = F_71 ( * ( V_160 * ) & V_158 [ 0 ] ) ;
V_57 V_161 = F_72 ( * ( V_162 * ) & V_158 [ 4 ] ) ;
F_73 ( V_159 ) ;
F_74 ( V_161 ) ;
}
static int F_75 ( struct V_16 * V_17 , void * V_163 )
{
struct V_164 * V_165 = V_163 ;
if ( F_76 ( V_17 ) )
return - V_166 ;
memcpy ( V_17 -> V_167 , V_165 -> V_168 , V_17 -> V_169 ) ;
V_17 -> V_170 &= ~ V_171 ;
F_70 ( V_17 -> V_167 ) ;
return 0 ;
}
static V_59 F_77 ( V_59 V_172 , unsigned int * V_173 )
{
V_59 V_174 = 1000000000UL / V_172 ;
V_59 V_175 = 1 ;
unsigned int V_176 = 0 ;
while ( V_175 <= V_174 ) {
V_175 <<= 1 ;
V_176 ++ ;
}
* V_173 = V_176 ;
return 1000000000UL / V_175 ;
}
static int F_78 ( struct V_16 * V_177 ,
struct V_178 * V_179 , int V_109 )
{
struct V_180 V_27 ;
struct V_61 * V_62 = F_24 ( V_177 ) ;
V_57 V_181 ;
V_59 V_182 , V_183 , V_184 , V_185 ;
if ( F_79 ( & V_27 , V_179 -> V_186 , sizeof( V_27 ) ) )
return - V_187 ;
F_30 ( L_13 ,
V_188 , V_27 . V_65 , V_27 . V_189 , V_27 . V_190 ) ;
if ( V_27 . V_65 )
return - V_91 ;
if ( ( V_27 . V_189 != V_142 ) &&
( V_27 . V_189 != V_143 ) )
return - V_191 ;
V_181 = F_80 () ;
switch ( V_27 . V_190 ) {
case V_145 :
V_184 = 0xFFFFFFFF ;
F_81 ( V_184 ) ;
break;
case V_146 :
case V_192 :
case V_193 :
V_181 &= ~ 0x1F00 ;
F_82 ( V_181 ) ;
V_185 = 0x4A24170C ;
F_83 ( V_185 ) ;
V_182 = 0x11040800 ;
F_84 ( V_182 ) ;
V_183 = 0x0140013F ;
F_85 ( V_183 ) ;
V_184 = 0xFFFFFFFC ;
F_81 ( V_184 ) ;
V_27 . V_190 = V_146 ;
break;
case V_148 :
case V_194 :
case V_195 :
V_181 &= ~ 0x1F00 ;
F_82 ( V_181 ) ;
V_185 = 0x2A24170C ;
F_83 ( V_185 ) ;
V_182 = 0x11040800 ;
F_84 ( V_182 ) ;
V_183 = 0x0140013F ;
F_85 ( V_183 ) ;
V_184 = 0xFFFFFFF0 ;
F_81 ( V_184 ) ;
V_27 . V_190 = V_148 ;
break;
case V_147 :
case V_196 :
case V_197 :
V_181 &= ~ 0x1100 ;
F_82 ( V_181 ) ;
V_185 = 0x0E24170C ;
F_83 ( V_185 ) ;
V_182 = 0x110488F7 ;
F_84 ( V_182 ) ;
V_183 = 0x0140013F ;
F_85 ( V_183 ) ;
V_184 = 0xFFFFFFF0 ;
F_81 ( V_184 ) ;
V_27 . V_190 = V_147 ;
break;
default:
return - V_191 ;
}
if ( V_27 . V_189 == V_142 &&
F_86 ( V_27 . V_190 ) ) {
V_181 &= ~ V_198 ;
F_82 ( V_181 ) ;
F_87 () ;
} else {
V_181 |= V_198 ;
F_82 ( V_181 ) ;
F_88 () ;
F_89 () ;
F_90 () ;
F_91 () ;
F_87 () ;
}
V_62 -> V_199 = V_27 ;
return F_92 ( V_179 -> V_186 , & V_27 , sizeof( V_27 ) ) ?
- V_187 : 0 ;
}
static void F_93 ( struct V_16 * V_177 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_177 ) ;
if ( F_94 ( V_11 ) -> V_200 & V_201 ) {
int V_48 = V_49 ;
F_94 ( V_11 ) -> V_200 |= V_202 ;
while ( ( ! ( F_95 () & V_203 ) ) && ( -- V_48 ) )
F_14 ( 1 ) ;
if ( V_48 == 0 )
F_39 ( V_177 , L_14 ) ;
else {
struct V_204 V_205 ;
T_4 V_206 ;
T_4 V_207 ;
V_207 = F_90 () ;
V_207 |= ( T_4 ) F_91 () << 32 ;
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_206 = V_207 << V_62 -> V_176 ;
V_205 . V_208 = F_96 ( V_206 ) ;
F_97 ( V_11 , & V_205 ) ;
}
}
}
static void F_98 ( struct V_16 * V_177 , struct V_18 * V_11 )
{
struct V_61 * V_62 = F_24 ( V_177 ) ;
V_59 V_209 ;
T_4 V_207 , V_206 ;
struct V_204 * V_205 ;
if ( F_86 ( V_62 -> V_199 . V_190 ) )
return;
V_209 = F_95 () & V_210 ;
if ( ! V_209 )
return;
V_205 = F_99 ( V_11 ) ;
V_207 = F_88 () ;
V_207 |= ( T_4 ) F_89 () << 32 ;
V_206 = V_207 << V_62 -> V_176 ;
memset ( V_205 , 0 , sizeof( * V_205 ) ) ;
V_205 -> V_208 = F_96 ( V_206 ) ;
}
static void F_100 ( struct V_16 * V_177 )
{
struct V_61 * V_62 = F_24 ( V_177 ) ;
T_4 V_211 , V_212 ;
V_59 V_172 , V_213 ;
V_172 = F_35 () ;
V_213 = F_77 ( V_172 , & V_62 -> V_176 ) ;
V_211 = V_213 * ( 1ULL << 32 ) ;
F_101 ( V_211 , V_172 ) ;
F_102 ( ( V_59 ) V_211 ) ;
V_62 -> V_211 = V_211 ;
V_212 = 1000000000ULL * V_172 ;
F_101 ( V_212 , V_213 ) ;
V_62 -> V_214 = V_212 - 1000000000ULL - 1ULL ;
V_62 -> V_199 . V_190 = V_145 ;
V_62 -> V_199 . V_189 = V_142 ;
}
static T_4 F_103 ( struct V_61 * V_62 )
{
T_4 V_206 ;
V_59 V_215 , V_216 ;
V_215 = F_104 () ;
V_216 = F_105 () ;
V_206 = ( ( T_4 ) V_216 ) << 32 ;
V_206 |= V_215 ;
V_206 <<= V_62 -> V_176 ;
return V_206 ;
}
static void F_106 ( struct V_61 * V_62 , T_4 V_206 )
{
V_59 V_216 , V_215 ;
V_206 >>= V_62 -> V_176 ;
V_216 = V_206 >> 32 ;
V_215 = V_206 & 0xffffffff ;
F_107 ( V_215 ) ;
F_108 ( V_216 ) ;
}
static int F_109 ( struct V_217 * V_218 , T_5 V_212 )
{
T_4 V_219 ;
V_59 V_220 , V_211 ;
int V_221 = 0 ;
struct V_61 * V_62 =
F_110 ( V_218 , struct V_61 , V_222 ) ;
if ( V_212 < 0 ) {
V_221 = 1 ;
V_212 = - V_212 ;
}
V_211 = V_62 -> V_211 ;
V_219 = V_211 ;
V_219 *= V_212 ;
V_220 = F_111 ( V_219 , 1000000000ULL ) ;
V_211 = V_221 ? V_211 - V_220 : V_211 + V_220 ;
F_102 ( V_211 ) ;
return 0 ;
}
static int F_112 ( struct V_217 * V_218 , T_6 V_223 )
{
T_6 V_224 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_218 , struct V_61 , V_222 ) ;
F_25 ( & V_62 -> V_225 , V_65 ) ;
V_224 = F_103 ( V_62 ) ;
V_224 += V_223 ;
F_106 ( V_62 , V_224 ) ;
F_31 ( & V_62 -> V_225 , V_65 ) ;
return 0 ;
}
static int F_113 ( struct V_217 * V_218 , struct V_226 * V_227 )
{
T_4 V_206 ;
V_59 V_228 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_218 , struct V_61 , V_222 ) ;
F_25 ( & V_62 -> V_225 , V_65 ) ;
V_206 = F_103 ( V_62 ) ;
F_31 ( & V_62 -> V_225 , V_65 ) ;
V_227 -> V_229 = F_114 ( V_206 , 1000000000 , & V_228 ) ;
V_227 -> V_230 = V_228 ;
return 0 ;
}
static int F_115 ( struct V_217 * V_218 ,
const struct V_226 * V_227 )
{
T_4 V_206 ;
unsigned long V_65 ;
struct V_61 * V_62 =
F_110 ( V_218 , struct V_61 , V_222 ) ;
V_206 = V_227 -> V_229 * 1000000000ULL ;
V_206 += V_227 -> V_230 ;
F_25 ( & V_62 -> V_225 , V_65 ) ;
F_106 ( V_62 , V_206 ) ;
F_31 ( & V_62 -> V_225 , V_65 ) ;
return 0 ;
}
static int F_116 ( struct V_217 * V_218 ,
struct V_231 * V_232 , int V_233 )
{
return - V_131 ;
}
static int F_117 ( struct V_16 * V_177 , struct V_234 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_177 ) ;
V_62 -> V_222 = V_235 ;
V_62 -> V_222 . V_236 = V_62 -> V_214 ;
V_62 -> clock = F_118 ( & V_62 -> V_222 , V_17 ) ;
if ( F_42 ( V_62 -> clock ) )
return F_43 ( V_62 -> clock ) ;
V_62 -> V_140 = F_119 ( V_62 -> clock ) ;
F_120 ( & V_62 -> V_225 ) ;
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
V_9 -> V_37 . V_237 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
} while ( V_9 -> V_37 . V_237 != 0 );
}
static void F_124 ( struct V_61 * V_62 )
{
int V_48 = V_49 ;
if ( V_9 -> V_37 . V_237 != 0 )
F_123 () ;
if ( V_38 -> V_12 == V_9 ) {
while ( V_9 -> V_37 . V_237 == 0 ) {
F_14 ( 10 ) ;
if ( ! ( F_125 () & V_238 ) )
break;
if ( V_48 -- < 0 )
break;
}
if ( V_48 >= 0 )
F_123 () ;
else
F_126 ( V_62 -> V_239 ) ;
}
if ( V_38 -> V_12 != V_9 &&
F_127 ( V_62 -> V_239 ) )
F_128 ( V_62 -> V_239 ) ;
if ( V_9 != V_38 ) {
if ( F_127 ( V_62 -> V_239 ) )
V_62 -> V_240 . V_241 =
V_242 + ( V_243 >> 4 ) ;
else
V_62 -> V_240 . V_241 =
V_242 + V_243 ;
F_129 ( & V_62 -> V_240 ,
V_62 -> V_240 . V_241 ) ;
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
struct V_61 * V_62 = F_24 ( V_17 ) ;
V_57 * V_44 ;
V_59 V_244 = ( unsigned long ) ( V_11 -> V_44 ) & 0x3 ;
V_38 -> V_11 = V_11 ;
if ( V_244 == 0x2 ) {
V_44 = ( V_57 * ) ( V_11 -> V_44 ) - 1 ;
* V_44 = ( V_57 ) ( V_11 -> V_245 ) ;
if ( F_94 ( V_11 ) -> V_200 & V_201 )
* V_44 |= 0x1000 ;
V_38 -> V_24 . V_31 = ( V_59 ) V_44 ;
F_132 ( ( V_59 ) V_44 ,
( V_59 ) ( ( T_3 * ) V_44 + V_11 -> V_245 + 4 ) ) ;
} else {
* ( ( V_57 * ) ( V_38 -> V_32 ) ) = ( V_57 ) ( V_11 -> V_245 ) ;
if ( F_94 ( V_11 ) -> V_200 & V_201 )
* ( ( V_57 * ) ( V_38 -> V_32 ) ) |= 0x1000 ;
memcpy ( ( T_3 * ) ( V_38 -> V_32 + 2 ) , V_11 -> V_44 ,
V_11 -> V_245 ) ;
V_38 -> V_24 . V_31 =
( V_59 ) V_38 -> V_32 ;
F_132 (
( V_59 ) V_38 -> V_32 ,
( V_59 ) ( V_38 -> V_32 + V_11 -> V_245 + 2 ) ) ;
}
F_87 () ;
V_38 -> V_37 . V_237 = 0 ;
V_38 -> V_24 . V_27 |= V_35 ;
if ( F_125 () & V_238 )
goto V_246;
F_133 ( & ( V_38 -> V_24 ) ) ;
F_134 ( V_38 -> V_24 . V_27 ) ;
F_27 ( F_26 () | V_247 ) ;
V_246:
F_93 ( V_17 , V_11 ) ;
V_38 = V_38 -> V_12 ;
V_17 -> V_248 . V_249 ++ ;
V_17 -> V_248 . V_250 += ( V_11 -> V_245 ) ;
F_124 ( V_62 ) ;
return V_251 ;
}
static void F_135 ( struct V_16 * V_17 )
{
struct V_18 * V_11 , * V_19 ;
unsigned short V_245 ;
struct V_61 * V_62 V_252 = F_24 ( V_17 ) ;
#if F_2 ( V_152 )
unsigned int V_5 ;
unsigned char V_253 [ V_254 + 1 ] ;
#endif
if ( V_46 -> V_37 . V_237 & V_255 ) {
F_136 ( V_17 , L_15 ) ;
V_17 -> V_248 . V_256 ++ ;
goto V_246;
}
V_11 = V_46 -> V_11 ;
V_19 = F_7 ( V_17 , V_40 + V_41 ) ;
if ( ! V_19 ) {
F_136 ( V_17 , L_16 ) ;
V_17 -> V_248 . V_256 ++ ;
goto V_246;
}
F_9 ( V_19 , V_41 ) ;
F_10 ( ( unsigned long ) V_19 -> V_42 ,
( unsigned long ) V_19 -> V_43 ) ;
V_46 -> V_11 = V_19 ;
V_46 -> V_24 . V_31 = ( unsigned long ) V_19 -> V_44 - 2 ;
V_245 = ( unsigned short ) ( ( V_46 -> V_37 . V_237 ) & V_257 ) ;
V_245 -= V_254 ;
F_137 ( V_11 , V_245 ) ;
V_11 -> V_258 = F_138 ( V_11 , V_17 ) ;
F_98 ( V_17 , V_11 ) ;
#if F_2 ( V_152 )
if ( V_11 -> V_44 [ V_259 ] == 0x45 ) {
V_11 -> V_260 = V_46 -> V_37 . V_261 ;
if ( V_11 -> V_245 % 2 ) {
V_253 [ 0 ] = 0 ;
for ( V_5 = 0 ; V_5 < V_254 ; V_5 ++ )
V_253 [ V_5 + 1 ] = ~ V_11 -> V_44 [ V_11 -> V_245 + V_5 ] ;
V_11 -> V_260 = F_139 ( V_253 , V_254 + 1 , V_11 -> V_260 ) ;
} else {
for ( V_5 = 0 ; V_5 < V_254 ; V_5 ++ )
V_253 [ V_5 ] = ~ V_11 -> V_44 [ V_11 -> V_245 + V_5 ] ;
V_11 -> V_260 = F_139 ( V_253 , V_254 , V_11 -> V_260 ) ;
}
V_11 -> V_262 = V_263 ;
}
#endif
F_140 ( V_11 ) ;
V_17 -> V_248 . V_264 ++ ;
V_17 -> V_248 . V_265 += V_245 ;
V_246:
V_46 -> V_37 . V_237 = 0x00000000 ;
V_46 = V_46 -> V_12 ;
}
static T_2 F_141 ( int V_105 , void * V_106 )
{
struct V_16 * V_17 = V_106 ;
int V_266 = 0 ;
V_267:
if ( V_46 -> V_37 . V_237 == 0 ) {
if ( V_266 == 0 ) {
if ( V_46 -> V_12 -> V_37 . V_237 != 0 ) {
V_46 = V_46 -> V_12 ;
goto V_268;
}
}
F_142 ( F_143 () |
V_269 | V_270 ) ;
return V_107 ;
}
V_268:
F_135 ( V_17 ) ;
V_266 ++ ;
goto V_267;
}
static void F_144 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_145 ( V_271 ) ;
F_141 ( V_271 , V_17 ) ;
F_124 ( V_62 ) ;
F_146 ( V_271 ) ;
}
static void F_147 ( void )
{
unsigned int V_71 ;
V_71 = F_26 () ;
V_71 &= ( ~ V_272 ) ;
V_71 &= ( ~ V_247 ) ;
F_27 ( V_71 ) ;
}
static int F_148 ( struct V_63 * V_64 )
{
int V_56 ;
V_59 V_71 ;
F_30 ( L_17 , V_188 ) ;
F_149 ( & ( V_14 -> V_24 ) ) ;
F_150 ( V_14 -> V_24 . V_27 ) ;
V_56 = F_12 () ;
if ( V_56 )
return V_56 ;
V_71 = F_26 () ;
if ( V_71 & V_72 )
V_71 |= V_273 ;
else
V_71 |= V_274 | V_275 | V_273 ;
V_71 |= V_272 ;
if ( V_64 -> V_75 == V_76 ) {
V_71 |= V_276 ;
#if F_2 ( V_277 ) || F_2 ( V_278 )
if ( V_279 < 3 ) {
V_71 |= V_247 ;
}
#endif
}
F_27 ( V_71 ) ;
return 0 ;
}
static void F_151 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_30 ( L_18 , V_17 -> V_104 , V_188 ) ;
F_147 () ;
F_152 ( & V_62 -> V_240 ) ;
while ( V_9 != V_38 ) {
V_9 -> V_24 . V_27 &= ~ V_35 ;
V_9 -> V_37 . V_237 = 0 ;
if ( V_9 -> V_11 ) {
F_3 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
V_9 = V_9 -> V_12 ;
}
if ( F_127 ( V_62 -> V_239 ) )
F_128 ( V_62 -> V_239 ) ;
F_148 ( V_62 -> V_64 ) ;
V_17 -> V_280 = V_242 ;
F_128 ( V_17 ) ;
}
static void F_153 ( struct V_16 * V_17 )
{
V_59 V_281 , V_282 ;
struct V_283 * V_284 ;
V_59 V_285 ;
V_281 = V_282 = 0 ;
F_154 (ha, dev) {
V_285 = F_155 ( V_286 , V_284 -> V_165 ) ;
V_285 >>= 26 ;
if ( V_285 & 0x20 )
V_281 |= 1 << ( V_285 & 0x1f ) ;
else
V_282 |= 1 << ( V_285 & 0x1f ) ;
}
F_156 ( V_281 ) ;
F_157 ( V_282 ) ;
}
static void F_158 ( struct V_16 * V_17 )
{
V_59 V_80 ;
if ( V_17 -> V_65 & V_287 ) {
F_159 ( V_17 , L_19 ) ;
V_80 = F_26 () ;
V_80 |= V_288 ;
F_27 ( V_80 ) ;
} else if ( V_17 -> V_65 & V_289 ) {
V_80 = F_26 () ;
V_80 |= V_290 ;
F_27 ( V_80 ) ;
} else if ( ! F_160 ( V_17 ) ) {
V_80 = F_26 () ;
V_80 |= V_291 ;
F_27 ( V_80 ) ;
F_153 ( V_17 ) ;
} else {
V_80 = F_26 () ;
V_80 &= ~ ( V_292 | V_290 ) ;
F_27 ( V_80 ) ;
}
}
static int F_161 ( struct V_16 * V_177 , struct V_178 * V_179 , int V_109 )
{
struct V_61 * V_62 = F_24 ( V_177 ) ;
if ( ! F_76 ( V_177 ) )
return - V_91 ;
switch ( V_109 ) {
case V_293 :
return F_78 ( V_177 , V_179 , V_109 ) ;
default:
if ( V_62 -> V_64 )
return F_162 ( V_62 -> V_64 , V_179 , V_109 ) ;
else
return - V_131 ;
}
}
static void F_163 ( struct V_16 * V_17 )
{
F_27 ( 0x00000000 ) ;
F_150 ( 0x0000 ) ;
F_134 ( 0x0000 ) ;
}
static int F_164 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
int V_56 ;
F_30 ( L_18 , V_17 -> V_104 , V_188 ) ;
if ( ! F_165 ( V_17 -> V_167 ) ) {
F_28 ( V_17 , L_20 ) ;
return - V_91 ;
}
V_56 = F_5 ( V_17 ) ;
if ( V_56 )
return V_56 ;
F_166 ( V_62 -> V_64 ) ;
F_167 ( V_62 -> V_64 , V_294 , V_295 ) ;
F_58 ( V_17 ) ;
F_70 ( V_17 -> V_167 ) ;
F_147 () ;
V_56 = F_148 ( V_62 -> V_64 ) ;
if ( V_56 )
return V_56 ;
F_30 ( L_21 ) ;
F_168 ( V_17 ) ;
F_169 ( V_17 ) ;
return 0 ;
}
static int F_170 ( struct V_16 * V_17 )
{
struct V_61 * V_62 = F_24 ( V_17 ) ;
F_30 ( L_18 , V_17 -> V_104 , V_188 ) ;
F_126 ( V_17 ) ;
F_171 ( V_17 ) ;
F_172 ( V_62 -> V_64 ) ;
F_167 ( V_62 -> V_64 , V_294 , V_296 ) ;
F_163 ( V_17 ) ;
F_1 () ;
return 0 ;
}
static int F_173 ( struct V_297 * V_298 )
{
struct V_16 * V_239 ;
struct V_61 * V_62 ;
struct V_297 * V_299 ;
struct V_300 * V_301 ;
int V_125 ;
V_239 = F_174 ( sizeof( struct V_61 ) ) ;
if ( ! V_239 )
return - V_47 ;
F_175 ( V_239 , & V_298 -> V_17 ) ;
F_176 ( V_298 , V_239 ) ;
V_62 = F_24 ( V_239 ) ;
V_62 -> V_239 = V_239 ;
* ( V_160 * ) ( & ( V_239 -> V_167 [ 0 ] ) ) = F_177 ( F_178 () ) ;
* ( V_162 * ) ( & ( V_239 -> V_167 [ 4 ] ) ) = F_179 ( ( V_57 ) F_180 () ) ;
F_73 ( 0x12345678 ) ;
if ( F_178 () != 0x12345678 ) {
F_181 ( & V_298 -> V_17 , L_22 ) ;
V_125 = - V_89 ;
goto V_302;
}
if ( ! F_165 ( V_239 -> V_167 ) ) {
if ( F_182 ( V_239 -> V_167 ) ||
! F_165 ( V_239 -> V_167 ) ) {
F_28 ( V_239 , L_23 ) ;
F_183 ( V_239 ) ;
}
}
F_70 ( V_239 -> V_167 ) ;
if ( ! V_298 -> V_17 . V_303 ) {
F_181 ( & V_298 -> V_17 , L_24 ) ;
V_125 = - V_89 ;
goto V_302;
}
V_299 = V_298 -> V_17 . V_303 ;
V_62 -> V_52 = F_184 ( V_299 ) ;
if ( ! V_62 -> V_52 ) {
F_181 ( & V_298 -> V_17 , L_25 ) ;
V_125 = - V_89 ;
goto V_302;
}
V_62 -> V_52 -> V_304 = V_239 ;
V_301 = V_299 -> V_17 . V_303 ;
V_125 = F_32 ( V_239 , V_301 -> V_79 ) ;
if ( V_125 ) {
F_181 ( & V_298 -> V_17 , L_26 ) ;
goto V_305;
}
V_62 -> V_156 = V_306 | V_301 -> V_156 ;
V_62 -> V_157 = V_306 | V_301 -> V_157 ;
F_185 ( V_239 ) ;
V_239 -> V_307 = & V_308 ;
V_239 -> V_309 = & V_310 ;
F_186 ( & V_62 -> V_240 ) ;
V_62 -> V_240 . V_44 = ( unsigned long ) V_62 ;
V_62 -> V_240 . V_311 = F_130 ;
F_120 ( & V_62 -> V_67 ) ;
V_125 = F_54 ( V_271 , F_141 ,
V_134 , L_27 , V_239 ) ;
if ( V_125 ) {
F_181 ( & V_298 -> V_17 , L_28 ) ;
V_125 = - V_166 ;
goto V_312;
}
V_125 = F_187 ( V_239 ) ;
if ( V_125 ) {
F_181 ( & V_298 -> V_17 , L_29 ) ;
goto V_313;
}
F_100 ( V_239 ) ;
if ( F_117 ( V_239 , & V_298 -> V_17 ) ) {
F_181 ( & V_298 -> V_17 , L_30 ) ;
goto V_314;
}
F_159 ( V_239 , L_31 , V_315 , V_117 ) ;
return 0 ;
V_314:
V_313:
F_55 ( V_271 , V_239 ) ;
V_312:
V_305:
F_188 ( V_62 -> V_52 ) ;
F_189 ( V_62 -> V_52 ) ;
V_302:
F_176 ( V_298 , NULL ) ;
F_190 ( V_239 ) ;
return V_125 ;
}
static int F_191 ( struct V_297 * V_298 )
{
struct V_16 * V_239 = F_184 ( V_298 ) ;
struct V_61 * V_62 = F_24 ( V_239 ) ;
F_121 ( V_62 ) ;
F_176 ( V_298 , NULL ) ;
V_62 -> V_52 -> V_304 = NULL ;
F_192 ( V_239 ) ;
F_55 ( V_271 , V_239 ) ;
F_190 ( V_239 ) ;
return 0 ;
}
static int F_193 ( struct V_297 * V_298 , T_7 V_316 )
{
struct V_16 * V_317 = F_184 ( V_298 ) ;
struct V_61 * V_62 = F_24 ( V_317 ) ;
if ( V_62 -> V_124 ) {
F_27 ( ( F_26 () & ~ V_247 ) | V_272 ) ;
F_194 ( V_318 ) ;
F_195 ( V_133 ) ;
} else {
if ( F_76 ( V_317 ) )
F_170 ( V_317 ) ;
}
return 0 ;
}
static int F_196 ( struct V_297 * V_298 )
{
struct V_16 * V_317 = F_184 ( V_298 ) ;
struct V_61 * V_62 = F_24 ( V_317 ) ;
if ( V_62 -> V_124 ) {
F_27 ( F_26 () | V_247 ) ;
F_194 ( 0 ) ;
F_197 ( V_133 ) ;
} else {
if ( F_76 ( V_317 ) )
F_164 ( V_317 ) ;
}
return 0 ;
}
static int F_198 ( struct V_297 * V_298 )
{
struct V_52 * V_319 ;
struct V_300 * V_320 ;
const unsigned short * V_321 ;
int V_125 , V_5 ;
V_320 = F_199 ( & V_298 -> V_17 ) ;
if ( ! V_320 ) {
F_181 ( & V_298 -> V_17 , L_32 ) ;
return - V_91 ;
}
V_321 = V_320 -> V_322 ;
V_125 = F_200 ( V_321 , V_115 ) ;
if ( V_125 ) {
F_181 ( & V_298 -> V_17 , L_33 ) ;
return V_125 ;
}
V_125 = - V_47 ;
V_319 = F_201 () ;
if ( V_319 == NULL )
goto V_323;
V_319 -> V_324 = F_15 ;
V_319 -> V_325 = F_20 ;
V_319 -> V_326 = F_22 ;
V_319 -> V_327 = & V_298 -> V_17 ;
V_319 -> V_104 = L_34 ;
V_319 -> V_328 = V_320 -> V_328 ;
snprintf ( V_319 -> V_329 , V_330 , L_35 ,
V_298 -> V_104 , V_298 -> V_329 ) ;
V_319 -> V_105 = F_202 ( sizeof( int ) * V_86 , V_331 ) ;
if ( ! V_319 -> V_105 )
goto V_332;
for ( V_5 = V_125 ; V_5 < V_86 ; ++ V_5 )
V_319 -> V_105 [ V_5 ] = V_149 ;
V_125 = F_203 ( V_320 -> V_333 , 0 , V_86 ) ;
if ( V_125 != V_320 -> V_333 )
F_181 ( & V_298 -> V_17 , L_36 ,
V_320 -> V_333 ) ;
for ( V_5 = 0 ; V_5 < V_125 ; ++ V_5 ) {
unsigned short V_334 = V_320 -> V_335 [ V_5 ] . V_165 ;
if ( V_334 < V_86 )
V_319 -> V_105 [ V_334 ] = V_320 -> V_335 [ V_5 ] . V_105 ;
else
F_181 ( & V_298 -> V_17 ,
L_37 ,
V_334 , V_5 ) ;
}
V_125 = F_204 ( V_319 ) ;
if ( V_125 ) {
F_181 ( & V_298 -> V_17 , L_38 ) ;
goto V_336;
}
F_176 ( V_298 , V_319 ) ;
return 0 ;
V_336:
F_205 ( V_319 -> V_105 ) ;
V_332:
F_189 ( V_319 ) ;
V_323:
F_206 ( V_321 ) ;
return V_125 ;
}
static int F_207 ( struct V_297 * V_298 )
{
struct V_52 * V_319 = F_184 ( V_298 ) ;
struct V_300 * V_320 =
F_199 ( & V_298 -> V_17 ) ;
F_176 ( V_298 , NULL ) ;
F_188 ( V_319 ) ;
F_205 ( V_319 -> V_105 ) ;
F_189 ( V_319 ) ;
F_206 ( V_320 -> V_322 ) ;
return 0 ;
}
static int T_8 F_208 ( void )
{
int V_56 ;
V_56 = F_209 ( & V_337 ) ;
if ( ! V_56 )
return F_209 ( & V_338 ) ;
return - V_89 ;
}
static void T_9 F_210 ( void )
{
F_211 ( & V_338 ) ;
F_211 ( & V_337 ) ;
}
