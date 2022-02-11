int F_1 ( void )
{
int V_1 ;
F_2 ( V_2 , V_3 ) ;
F_2 ( V_4 , V_5 ) ;
F_2 ( V_6 , V_7 ) ;
F_2 ( V_8 , V_9 ) ;
F_2 ( V_10 , V_11 ) ;
F_2 ( V_12 , V_13 ) ;
F_2 ( V_14 , V_15 ) ;
for ( V_1 = 0 ; V_1 < 10 ; V_1 ++ ) {
if ( ( F_3 ( V_16 ) & V_17 )
== V_17 )
break;
F_4 ( 100 ) ;
}
F_2 ( V_2 , V_18 ) ;
return 0 ;
}
int F_5 ( void )
{
F_2 ( V_19 , V_13 ) ;
F_2 ( V_20 , V_11 ) ;
return 0 ;
}
int F_6 ( void )
{
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
F_2 ( V_25 , V_26 + V_27 ) ;
F_2 ( V_28 , V_26 + V_29 ) ;
F_2 ( V_30 , V_26 + V_31 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
T_1 F_10 ( unsigned int V_32 )
{
return F_3 ( V_26 + V_32 ) ;
}
void F_11 ( unsigned int V_32 , T_1 V_33 )
{
unsigned long V_21 ;
F_7 ( & V_34 , V_21 ) ;
F_2 ( V_33 , ( V_26 + V_32 ) ) ;
F_9 ( & V_34 , V_21 ) ;
}
void F_12 ( unsigned int V_32 , T_1 V_35 , T_1 V_33 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_34 , V_21 ) ;
V_36 = F_3 ( V_26 + V_32 ) ;
V_36 = ( ( V_36 & ~ V_35 ) | ( V_33 & V_35 ) ) ;
F_2 ( V_36 , ( V_26 + V_32 ) ) ;
F_9 ( & V_34 , V_21 ) ;
}
struct V_37 * F_13 ( void )
{
return V_38 . V_39 ? & V_38 . V_40 : NULL ;
}
bool F_14 ( void )
{
return ( F_15 ( V_41 + V_42 ) &
V_43 ) == V_43 ;
}
int F_16 ( enum V_44 V_36 )
{
if ( V_36 < V_45 || V_36 > V_46 )
return - V_47 ;
F_17 ( V_36 , ( V_41 + V_48 ) ) ;
return 0 ;
}
enum V_49 F_18 ( void )
{
return F_15 ( V_41 + V_50 ) ;
}
enum V_51 F_19 ( void )
{
return F_15 ( V_41 + V_52 ) ;
}
int F_20 ( T_2 V_53 , T_2 V_54 , T_2 div )
{
static int V_55 [ 2 ] ;
int V_56 = 0 ;
unsigned long V_21 ;
T_1 V_36 ;
T_1 V_57 ;
T_1 V_35 ;
T_1 V_58 ;
F_21 ( V_53 > 1 ) ;
F_21 ( div > 63 ) ;
F_21 ( ( V_53 == 0 ) && ( V_54 > V_59 ) ) ;
if ( ! div && ! V_55 [ V_53 ] )
return - V_47 ;
if ( V_53 == 0 ) {
V_58 = V_60 ;
V_35 = ( V_60 | V_61 ) ;
V_57 = ( ( V_54 << V_62 ) |
( div << V_63 ) ) ;
} else {
V_58 = V_64 ;
V_35 = ( V_64 | V_65 |
V_66 ) ;
V_57 = ( ( V_54 << V_67 ) |
( div << V_68 ) ) ;
}
V_57 &= V_35 ;
F_7 ( & V_69 , V_21 ) ;
V_36 = F_3 ( V_70 ) ;
if ( V_36 & V_58 ) {
if ( div ) {
if ( ( V_36 & V_35 ) != V_57 ) {
V_56 = - V_71 ;
goto V_72;
}
} else {
if ( ( V_36 & V_35 & ~ V_58 ) != V_57 ) {
V_56 = - V_47 ;
goto V_72;
}
}
}
F_2 ( ( V_57 | ( V_36 & ~ V_35 ) ) , V_70 ) ;
V_55 [ V_53 ] += ( div ? 1 : - 1 ) ;
V_72:
F_9 ( & V_69 , V_21 ) ;
return V_56 ;
}
int F_22 ( T_2 V_73 , bool V_74 , bool V_75 )
{
unsigned long V_21 ;
F_21 ( ( V_73 < V_76 ) || ( V_77 < V_73 ) ) ;
F_7 ( & V_78 . V_79 , V_21 ) ;
while ( F_3 ( V_80 ) & F_23 ( 0 ) )
F_8 () ;
F_17 ( V_81 , ( V_41 + V_82 ) ) ;
F_17 ( V_73 , ( V_41 + V_83 ) ) ;
F_17 ( ( V_75 ? 1 : 0 ) , ( V_41 + V_84 ) ) ;
F_17 ( ( V_74 ? 1 : 0 ) ,
( V_41 + V_85 ) ) ;
F_17 ( 0 , ( V_41 + V_86 ) ) ;
F_2 ( F_23 ( 0 ) , V_87 ) ;
F_9 ( & V_78 . V_79 , V_21 ) ;
return 0 ;
}
T_2 F_24 ( void )
{
return F_15 ( V_41 + V_88 ) ;
}
static void F_25 ( void )
{
const T_2 V_89 [ 2 ] = {
V_90 ,
V_91
} ;
static T_1 V_92 ;
static T_1 V_93 ;
T_1 V_94 ;
T_1 V_95 ;
unsigned int V_1 ;
V_94 = V_78 . V_96 . V_97 | V_78 . V_96 . V_98 ;
V_94 |= ( V_99 | V_100 ) ;
V_95 = V_78 . V_96 . V_95 ;
if ( ( V_94 == V_92 ) && ( V_95 == V_93 ) )
return;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
while ( F_3 ( V_80 ) & F_23 ( 0 ) )
F_8 () ;
F_2 ( V_94 , ( V_41 + V_101 ) ) ;
F_2 ( V_95 , ( V_41 + V_102 ) ) ;
F_17 ( V_89 [ V_1 ] , ( V_41 + V_82 ) ) ;
F_2 ( F_23 ( 0 ) , V_87 ) ;
}
V_92 = V_94 ;
V_93 = V_95 ;
}
void F_26 ( T_1 V_103 )
{
unsigned long V_21 ;
T_1 V_57 ;
int V_1 ;
F_21 ( V_103 != ( V_103 & V_104 ) ) ;
for ( V_1 = 0 , V_57 = 0 ; V_1 < V_105 ; V_1 ++ ) {
if ( V_103 & F_27 ( V_1 ) )
V_57 |= V_106 [ V_1 ] ;
}
F_7 ( & V_78 . V_79 , V_21 ) ;
V_78 . V_96 . V_98 = V_57 ;
F_25 () ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
void F_28 ( T_1 V_95 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_79 , V_21 ) ;
V_78 . V_96 . V_95 = V_95 ;
F_25 () ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
void F_29 ( void T_3 * * V_107 )
{
if ( F_15 ( V_41 + V_108 ) & 1 )
* V_107 = ( V_41 + V_109 ) ;
else
* V_107 = ( V_41 + V_110 ) ;
}
int F_30 ( T_2 V_111 )
{
int V_56 ;
if ( V_111 < V_112 || V_111 > V_113 )
return - V_47 ;
V_56 = 0 ;
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_115 , ( V_41 + V_116 ) ) ;
F_17 ( V_111 , ( V_41 + V_117 ) ) ;
F_17 ( V_118 , ( V_41 + V_119 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_115 ) ||
( V_114 . V_121 . V_122 != V_111 ) )
V_56 = - V_123 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_34 ( void )
{
return F_15 ( V_41 + V_124 ) ;
}
int F_35 ( void )
{
return F_15 ( V_125 ) ;
}
static void F_36 ( bool V_126 )
{
T_1 V_127 [] = {
V_128 ,
V_129
} ;
unsigned long V_21 ;
unsigned int V_1 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
for ( V_1 = 0 ; V_1 < F_37 ( V_127 ) ; V_1 ++ ) {
T_1 V_36 ;
T_1 div ;
V_36 = F_3 ( V_26 + V_127 [ V_1 ] ) ;
div = ( V_36 & V_130 ) ;
if ( V_126 ) {
if ( ( div <= 1 ) || ( div > 15 ) ) {
F_38 ( L_1 ,
div , V_131 ) ;
goto V_72;
}
div <<= 1 ;
} else {
if ( div <= 2 )
goto V_72;
div >>= 1 ;
}
V_36 = ( ( V_36 & ~ V_130 ) |
( div & V_130 ) ) ;
F_2 ( V_36 , V_26 + V_127 [ V_1 ] ) ;
}
V_72:
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
int F_39 ( T_2 V_111 )
{
int V_56 = 0 ;
if ( V_111 == V_114 . V_132 )
return 0 ;
F_31 ( & V_114 . V_79 ) ;
if ( V_114 . V_132 == V_133 )
F_36 ( false ) ;
if ( ( V_111 != V_134 ) && ( V_114 . V_132 != V_134 ) )
goto V_135;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_115 , ( V_41 + V_116 ) ) ;
F_17 ( V_112 , ( V_41 + V_117 ) ) ;
F_17 ( ( ( V_111 == V_133 ) ? V_136 : V_111 ) ,
( V_41 + V_119 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_115 ) ||
( V_114 . V_121 . V_132 != V_111 ) )
V_56 = - V_123 ;
V_135:
if ( ( ! V_56 && ( V_111 == V_133 ) ) ||
( V_56 && ( V_114 . V_132 == V_133 ) ) )
F_36 ( true ) ;
if ( ! V_56 )
V_114 . V_132 = V_111 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_40 ( void )
{
return F_15 ( V_41 + V_137 ) ;
}
int F_41 ( bool V_126 )
{
int V_56 = 0 ;
T_2 V_89 ;
static unsigned int V_55 ;
F_31 ( & V_114 . V_79 ) ;
if ( V_126 ) {
if ( 0 != V_55 ++ )
goto V_72;
V_89 = V_138 ;
} else {
if ( V_55 == 0 ) {
V_56 = - V_123 ;
goto V_72;
} else if ( 1 != V_55 -- ) {
goto V_72;
}
V_89 = V_139 ;
}
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_89 , ( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_89 ) ||
( ( V_114 . V_121 . V_140 & F_27 ( 0 ) ) != 0 ) )
V_56 = - V_123 ;
V_72:
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_42 ( void )
{
int V_56 = 0 ;
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_141 ,
( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_141 ) ||
( ( V_114 . V_121 . V_140 & F_27 ( 0 ) ) != 0 ) )
V_56 = - V_123 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
static int F_43 ( T_2 clock , bool V_126 )
{
int V_56 = 0 ;
if ( clock == V_142 )
clock = ( V_126 ? V_143 : V_144 ) ;
else if ( clock == V_145 )
clock = ( V_126 ? V_146 : V_147 ) ;
else
return - V_47 ;
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_148 , ( V_41 + V_116 ) ) ;
F_17 ( clock , ( V_41 + V_149 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( V_114 . V_121 . V_89 != V_148 )
V_56 = - V_123 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_44 ( T_4 V_150 , T_2 V_151 )
{
int V_56 = 0 ;
bool V_152 = false ;
int V_1 ;
F_21 ( V_150 >= V_153 ) ;
switch ( V_150 ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_152 = true ;
break;
}
F_21 ( V_151 > V_158 ) ;
F_21 ( V_151 == V_159 && ! V_152 ) ;
F_31 ( & V_160 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 2 ) )
F_8 () ;
for ( V_1 = 0 ; V_1 < V_153 ; V_1 ++ )
F_17 ( V_161 , ( V_41 + V_162 + V_1 ) ) ;
F_17 ( V_151 , ( V_41 + V_162 + V_150 ) ) ;
F_17 ( V_163 , ( V_41 + V_164 ) ) ;
F_2 ( F_23 ( 2 ) , V_87 ) ;
if ( ! F_45 ( & V_160 . V_120 ,
F_46 ( 20000 ) ) ) {
F_38 ( L_2 ,
V_131 ) ;
V_56 = - V_123 ;
goto V_72;
}
if ( V_160 . V_121 . V_165 != V_166 )
V_56 = - V_123 ;
V_72:
F_33 ( & V_160 . V_79 ) ;
return V_56 ;
}
void F_47 ( struct V_167 * V_168 ,
struct V_167 * V_169 )
{
T_1 V_170 ;
T_1 V_171 ;
unsigned long V_21 ;
F_21 ( ( V_168 == NULL ) || ( V_169 == NULL ) ) ;
V_170 = ( V_168 -> V_172 & 0xF ) ;
V_170 = ( ( V_170 << 4 ) | ( V_168 -> V_173 & 0xF ) ) ;
V_170 = ( ( V_170 << 8 ) | ( V_168 -> V_174 & 0xFF ) ) ;
V_170 = ( ( V_170 << 8 ) | ( V_168 -> V_175 & 0xFF ) ) ;
V_170 = ( ( V_170 << 4 ) | ( V_168 -> V_176 & 0xF ) ) ;
V_170 = ( ( V_170 << 4 ) | ( V_168 -> V_177 & 0xF ) ) ;
V_171 = ( V_169 -> V_172 & 0xF ) ;
V_171 = ( ( V_171 << 4 ) | ( V_169 -> V_173 & 0xF ) ) ;
V_171 = ( ( V_171 << 8 ) | ( V_169 -> V_174 & 0xFF ) ) ;
V_171 = ( ( V_171 << 8 ) | ( V_169 -> V_175 & 0xFF ) ) ;
V_171 = ( ( V_171 << 4 ) | ( V_169 -> V_176 & 0xF ) ) ;
V_171 = ( ( V_171 << 4 ) | ( V_169 -> V_177 & 0xF ) ) ;
F_7 ( & V_160 . V_178 , V_21 ) ;
F_2 ( V_170 , ( V_41 + V_179 ) ) ;
F_2 ( V_171 , ( V_41 + V_180 ) ) ;
V_160 . V_181 =
( ( V_168 -> V_172 == V_182 ) ||
( V_168 -> V_173 == V_182 ) ||
( V_169 -> V_172 == V_182 ) ||
( V_169 -> V_173 == V_182 ) ) ;
F_9 ( & V_160 . V_178 , V_21 ) ;
}
bool F_48 ( void )
{
return V_160 . V_181 ;
}
static int F_49 ( bool V_126 )
{
int V_56 ;
unsigned long V_21 ;
V_56 = 0 ;
F_31 ( & V_183 . V_184 ) ;
F_7 ( & V_183 . V_79 , V_21 ) ;
while ( F_3 ( V_80 ) & F_23 ( 3 ) )
F_8 () ;
F_17 ( ( V_126 ? V_185 : V_186 ) , ( V_41 + V_187 ) ) ;
F_17 ( V_188 , ( V_41 + V_189 ) ) ;
F_2 ( F_23 ( 3 ) , V_87 ) ;
F_9 ( & V_183 . V_79 , V_21 ) ;
if ( V_126 && ! F_45 ( & V_183 . V_190 ,
F_46 ( 20000 ) ) ) {
F_38 ( L_2 ,
V_131 ) ;
V_56 = - V_123 ;
}
F_33 ( & V_183 . V_184 ) ;
return V_56 ;
}
static int F_50 ( bool V_126 )
{
T_1 V_36 = ( V_191 | V_192 ) ;
if ( ! V_126 )
V_36 |= V_193 ;
F_2 ( V_36 , V_194 ) ;
return 0 ;
}
static int F_51 ( T_2 clock , bool V_126 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_195 [ clock ] . V_196 ) ;
if ( V_126 ) {
V_36 |= ( V_197 | V_195 [ clock ] . V_198 ) ;
} else {
V_195 [ clock ] . V_198 = ( V_36 & V_199 ) ;
V_36 &= ~ ( V_197 | V_199 ) ;
}
F_2 ( V_36 , V_26 + V_195 [ clock ] . V_196 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
static int F_52 ( T_2 clock , bool V_126 )
{
T_1 V_36 ;
int V_200 ;
if ( V_126 ) {
V_36 = F_3 ( V_201 ) ;
F_2 ( V_36 | V_202 , V_201 ) ;
}
V_200 = F_51 ( clock , V_126 ) ;
if ( ! V_200 && ! V_126 ) {
V_36 = F_3 ( V_201 ) ;
F_2 ( V_36 & ~ V_202 , V_201 ) ;
}
return V_200 ;
}
static inline bool F_53 ( void )
{
return ( F_3 ( V_16 ) &
( V_203 |
V_204 ) ) ==
( V_203 |
V_204 ) ;
}
static int F_54 ( bool V_126 )
{
int V_56 = 0 ;
T_1 V_36 ;
F_2 ( ( V_205 |
V_206 ) , ( V_126 ?
V_5 : V_207 ) ) ;
V_36 = F_3 ( V_13 ) ;
if ( V_126 )
V_36 |= V_208 ;
else
V_36 &= ~ V_208 ;
F_2 ( V_36 , V_13 ) ;
if ( V_126 ) {
unsigned int V_1 ;
bool V_209 = F_53 () ;
for ( V_1 = 10 ; ! V_209 && ( V_1 > 0 ) ; -- V_1 ) {
F_4 ( 100 ) ;
V_209 = F_53 () ;
}
if ( V_209 ) {
F_2 ( V_210 ,
V_18 ) ;
} else {
F_2 ( ( V_205 |
V_206 ) ,
V_207 ) ;
V_36 &= ~ V_208 ;
F_2 ( V_36 , V_13 ) ;
V_56 = - V_211 ;
}
} else {
F_2 ( V_210 , V_3 ) ;
}
return V_56 ;
}
static int F_55 ( T_2 V_212 , bool V_126 )
{
T_1 V_36 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_213 [ V_212 ] . V_214 ;
V_36 |= ( ( V_126 ? V_213 [ V_212 ] . V_215 : V_216 ) <<
V_213 [ V_212 ] . V_217 ) ;
F_2 ( V_36 , V_9 ) ;
return 0 ;
}
static int F_56 ( T_2 V_212 , bool V_126 )
{
T_1 V_36 ;
V_36 = F_3 ( V_11 ) ;
V_126 ? ( V_36 |= V_218 [ V_212 ] . V_219 ) : ( V_36 &= ~ V_218 [ V_212 ] . V_219 ) ;
F_2 ( V_36 , V_11 ) ;
return 0 ;
}
int F_57 ( T_2 clock , bool V_126 )
{
if ( clock == V_220 )
return F_52 ( clock , V_126 ) ;
else if ( clock < V_221 )
return F_51 ( clock , V_126 ) ;
else if ( clock == V_222 )
return F_50 ( V_126 ) ;
else if ( ( clock == V_223 ) || ( clock == V_224 ) )
return F_55 ( ( clock - V_223 ) , V_126 ) ;
else if ( ( V_225 <= clock ) && ( clock <= V_226 ) )
return F_56 ( ( clock - V_225 ) , V_126 ) ;
else if ( clock == V_227 )
return F_54 ( V_126 ) ;
else if ( clock == V_228 )
return F_49 ( V_126 ) ;
else if ( ( clock == V_142 ) || ( clock == V_145 ) )
return F_43 ( clock , V_126 ) ;
else
return - V_47 ;
}
static unsigned long F_58 ( void T_3 * V_32 , unsigned long V_229 ,
int V_230 )
{
T_5 V_231 ;
T_1 V_36 ;
T_1 V_232 ;
T_1 div = 1 ;
V_36 = F_3 ( V_32 ) ;
V_231 = V_229 ;
V_231 *= ( ( V_36 & V_233 ) >> V_234 ) ;
V_232 = ( ( V_36 & V_235 ) >> V_236 ) ;
if ( V_232 > 1 )
div *= V_232 ;
V_232 = ( ( V_36 & V_237 ) >> V_238 ) ;
if ( V_232 > 1 )
div *= V_232 ;
if ( V_36 & V_239 )
div *= 2 ;
if ( ( V_230 == V_240 ) || ( ( V_230 == V_241 ) &&
( V_36 & V_242 ) &&
( ( V_32 == V_243 ) ||
( V_32 == V_244 ) ||
( V_32 == V_245 ) ) ) )
div *= 2 ;
( void ) F_59 ( V_231 , div ) ;
return ( unsigned long ) V_231 ;
}
static unsigned long F_60 ( T_2 clock )
{
T_1 V_36 ;
T_1 V_198 ;
unsigned long V_231 = V_246 ;
V_36 = F_3 ( V_26 + V_195 [ clock ] . V_196 ) ;
if ( V_36 & V_247 ) {
if ( V_195 [ clock ] . V_248 && ( V_36 & V_249 ) )
V_231 /= 2 ;
return V_231 ;
}
V_36 |= V_195 [ clock ] . V_198 ;
V_198 = ( V_36 & V_199 ) ;
if ( V_198 == V_250 )
V_231 = F_58 ( V_243 , V_231 , V_195 [ clock ] . V_230 ) ;
else if ( V_198 == V_251 )
V_231 = F_58 ( V_252 , V_231 , V_195 [ clock ] . V_230 ) ;
else if ( V_198 == V_253 )
V_231 = F_58 ( V_245 , V_231 , V_195 [ clock ] . V_230 ) ;
else
return 0 ;
if ( ( clock == V_220 ) &&
( V_36 & V_254 ) ) {
T_5 V_56 = ( V_231 * 10 ) ;
( void ) F_59 ( V_56 , 25 ) ;
return ( unsigned long ) V_56 ;
}
V_36 &= V_130 ;
if ( V_36 )
return V_231 / V_36 ;
else
return 0 ;
}
static unsigned long F_61 ( void )
{
T_1 V_56 ;
unsigned long V_231 ;
V_56 = F_3 ( V_255 ) ;
if ( V_56 & V_256 ) {
V_231 = F_58 ( V_245 , V_246 , V_240 ) ;
if ( ! ( V_56 & V_257 ) )
V_231 /= 2 ;
V_56 = F_3 ( V_258 ) ;
V_56 &= V_130 ;
V_231 /= V_56 ;
} else {
V_231 = F_58 ( V_244 , V_246 , V_241 ) ;
}
return V_231 ;
}
static unsigned long F_62 ( T_2 V_212 )
{
T_1 V_215 ;
T_1 div = 1 ;
V_215 = F_3 ( V_9 ) ;
V_215 = ( ( V_215 & V_213 [ V_212 ] . V_214 ) >> V_213 [ V_212 ] . V_217 ) ;
if ( V_215 == V_216 )
V_215 = V_213 [ V_212 ] . V_215 ;
else
V_213 [ V_212 ] . V_215 = V_215 ;
switch ( V_215 ) {
case V_259 :
div *= 2 ;
case V_260 :
div *= 2 ;
case V_261 :
return F_58 ( V_7 , F_60 ( V_262 ) ,
V_263 ) / div ;
default:
return 0 ;
}
}
static unsigned long F_63 ( T_2 V_212 )
{
T_1 div ;
div = F_3 ( V_11 ) ;
div = ( ( div & V_218 [ V_212 ] . V_58 ) >> ( V_218 [ V_212 ] . V_264 ) ) ;
return F_60 ( V_265 ) / F_64 ( ( T_1 ) 1 , div ) ;
}
unsigned long F_65 ( T_2 clock )
{
if ( clock < V_221 )
return F_60 ( clock ) ;
else if ( clock == V_222 )
return V_246 / 16 ;
else if ( clock == V_228 )
return V_246 ;
else if ( clock == V_142 )
return F_58 ( V_243 , V_246 , V_263 ) ;
else if ( clock == V_145 )
return F_58 ( V_252 , V_246 , V_263 ) ;
else if ( clock == V_266 )
return F_61 () ;
else if ( clock == V_267 )
return F_58 ( V_245 , V_246 , V_263 ) ;
else if ( clock == V_227 )
return F_58 ( V_7 , F_60 ( V_262 ) ,
V_263 ) ;
else if ( ( clock == V_223 ) || ( clock == V_224 ) )
return F_62 ( clock - V_223 ) ;
else if ( ( V_225 <= clock ) && ( clock <= V_226 ) )
return F_63 ( clock - V_225 ) ;
else
return 0 ;
}
static unsigned long F_66 ( T_1 V_268 , int V_230 )
{
if ( V_268 & V_247 )
return V_246 ;
V_268 &= V_199 ;
if ( V_268 == V_250 )
return F_58 ( V_243 , V_246 , V_230 ) ;
else if ( V_268 == V_251 )
return F_58 ( V_252 , V_246 , V_230 ) ;
else if ( V_268 == V_253 )
return F_58 ( V_245 , V_246 , V_230 ) ;
else
return 0 ;
}
static T_1 F_67 ( unsigned long V_229 , unsigned long V_231 )
{
T_1 div ;
div = ( V_229 / V_231 ) ;
if ( div == 0 )
return 1 ;
if ( V_231 < ( V_229 / div ) )
div ++ ;
return div ;
}
static long F_68 ( T_2 clock , unsigned long V_231 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_229 ;
long V_269 ;
V_36 = F_3 ( V_26 + V_195 [ clock ] . V_196 ) ;
V_229 = F_66 ( ( V_36 | V_195 [ clock ] . V_198 ) ,
V_195 [ clock ] . V_230 ) ;
div = F_67 ( V_229 , V_231 ) ;
if ( V_36 & V_247 ) {
if ( V_195 [ clock ] . V_248 ) {
if ( div > 2 )
div = 2 ;
} else {
div = 1 ;
}
} else if ( ( clock == V_220 ) && ( div == 3 ) ) {
T_5 V_56 = ( V_229 * 10 ) ;
( void ) F_59 ( V_56 , 25 ) ;
if ( V_56 <= V_231 )
return ( unsigned long ) V_56 ;
}
V_269 = ( V_229 / F_69 ( div , ( T_1 ) 31 ) ) ;
return V_269 ;
}
static long F_70 ( unsigned long V_231 )
{
struct V_270 * V_271 ;
long V_272 = 0 ;
V_231 = V_231 / 1000 ;
F_71 (pos, db8500_cpufreq_table) {
V_272 = V_271 -> V_273 ;
if ( V_272 == V_231 )
break;
}
return V_272 * 1000 ;
}
static long F_72 ( unsigned long V_231 )
{
long V_269 = 0 ;
unsigned long V_229 ;
unsigned long V_274 ;
T_1 V_56 ;
V_229 = F_60 ( V_262 ) ;
V_274 = V_231 ;
for ( V_56 = 7 ; ( V_274 > 0 ) && ( V_56 > 0 ) ; V_56 -- ) {
T_5 V_232 ;
V_232 = ( V_56 * V_231 ) ;
( void ) F_59 ( V_232 , V_229 ) ;
if ( V_232 < 6 )
V_232 = 6 ;
else if ( V_232 > 255 )
V_232 = 255 ;
V_232 *= V_229 ;
if ( ( ( 2 * V_232 ) < ( V_56 * V_275 ) ) ||
( ( V_56 * V_276 ) < ( 2 * V_232 ) ) )
continue;
( void ) F_59 ( V_232 , V_56 ) ;
if ( V_231 < V_232 ) {
if ( V_269 == 0 )
V_269 = ( long ) V_232 ;
break;
}
if ( ( V_231 - V_232 ) < V_274 ) {
V_274 = ( V_231 - V_232 ) ;
V_269 = ( long ) V_232 ;
}
}
return V_269 ;
}
static long F_73 ( unsigned long V_231 )
{
T_1 div ;
unsigned long V_229 ;
long V_269 ;
V_229 = F_58 ( V_7 , F_60 ( V_262 ) ,
V_263 ) ;
div = F_67 ( V_229 , V_231 ) ;
V_269 = ( V_229 / ( ( div > 2 ) ? 4 : div ) ) ;
return V_269 ;
}
static long F_74 ( unsigned long V_231 )
{
T_1 div ;
unsigned long V_229 ;
long V_269 ;
V_229 = F_60 ( V_265 ) ;
div = F_67 ( V_229 , V_231 ) ;
V_269 = ( V_229 / F_69 ( div , ( T_1 ) 255 ) ) ;
return V_269 ;
}
long F_75 ( T_2 clock , unsigned long V_231 )
{
if ( clock < V_221 )
return F_68 ( clock , V_231 ) ;
else if ( clock == V_266 )
return F_70 ( V_231 ) ;
else if ( clock == V_227 )
return F_72 ( V_231 ) ;
else if ( ( clock == V_223 ) || ( clock == V_224 ) )
return F_73 ( V_231 ) ;
else if ( ( V_225 <= clock ) && ( clock <= V_226 ) )
return F_74 ( V_231 ) ;
else
return ( long ) F_65 ( clock ) ;
}
static void F_76 ( T_2 clock , unsigned long V_231 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_229 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_195 [ clock ] . V_196 ) ;
V_229 = F_66 ( ( V_36 | V_195 [ clock ] . V_198 ) ,
V_195 [ clock ] . V_230 ) ;
div = F_67 ( V_229 , V_231 ) ;
if ( V_36 & V_247 ) {
if ( V_195 [ clock ] . V_248 ) {
if ( div > 1 )
V_36 |= V_249 ;
else
V_36 &= ~ V_249 ;
}
} else if ( clock == V_220 ) {
V_36 &= ~ ( V_130 |
V_254 ) ;
if ( div == 3 ) {
T_5 V_56 = ( V_229 * 10 ) ;
( void ) F_59 ( V_56 , 25 ) ;
if ( V_56 <= V_231 ) {
V_36 |= V_254 ;
div = 0 ;
}
}
V_36 |= F_69 ( div , ( T_1 ) 31 ) ;
} else {
V_36 &= ~ V_130 ;
V_36 |= F_69 ( div , ( T_1 ) 31 ) ;
}
F_2 ( V_36 , V_26 + V_195 [ clock ] . V_196 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
static int F_77 ( unsigned long V_231 )
{
struct V_270 * V_271 ;
V_231 = V_231 / 1000 ;
F_71 (pos, db8500_cpufreq_table)
if ( V_271 -> V_273 == V_231 )
break;
if ( V_271 -> V_273 != V_231 )
return - V_47 ;
return F_30 ( V_271 -> V_277 ) ;
}
static int F_78 ( unsigned long V_231 )
{
unsigned long V_229 ;
unsigned long V_274 ;
T_1 V_278 = 0 ;
T_1 V_56 ;
V_229 = F_60 ( V_262 ) ;
V_274 = V_231 ;
for ( V_56 = 7 ; ( V_274 > 0 ) && ( V_56 > 0 ) ; V_56 -- ) {
T_5 V_232 ;
T_5 V_279 ;
V_232 = ( V_56 * V_231 ) ;
( void ) F_59 ( V_232 , V_229 ) ;
if ( V_232 < 6 )
V_232 = 6 ;
else if ( V_232 > 255 )
V_232 = 255 ;
V_279 = ( V_232 * V_229 ) ;
if ( ( ( 2 * V_279 ) < ( V_56 * V_275 ) ) ||
( ( V_56 * V_276 ) < ( 2 * V_279 ) ) )
continue;
( void ) F_59 ( V_279 , V_56 ) ;
if ( V_231 < V_279 ) {
if ( V_278 == 0 )
V_278 = ( ( ( T_1 ) V_232 << V_234 ) |
( V_56 << V_238 ) ) ;
break;
}
if ( ( V_231 - V_279 ) < V_274 ) {
V_274 = ( V_231 - V_279 ) ;
V_278 = ( ( ( T_1 ) V_232 << V_234 ) |
( V_56 << V_238 ) ) ;
}
}
if ( V_278 == 0 )
return - V_47 ;
V_278 |= ( 1 << V_236 ) ;
F_2 ( V_278 , V_7 ) ;
return 0 ;
}
static void F_79 ( T_2 V_212 , unsigned long V_231 )
{
T_1 V_36 ;
T_1 div ;
div = F_67 ( F_58 ( V_7 ,
F_60 ( V_262 ) , V_263 ) , V_231 ) ;
V_213 [ V_212 ] . V_215 = ( div == 1 ) ? V_261 :
( div == 2 ) ? V_260 :
V_259 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_213 [ V_212 ] . V_214 ;
V_36 |= ( V_213 [ V_212 ] . V_215 << V_213 [ V_212 ] . V_217 ) ;
F_2 ( V_36 , V_9 ) ;
}
static void F_80 ( T_2 V_212 , unsigned long V_231 )
{
T_1 V_36 ;
T_1 div ;
div = F_67 ( F_60 ( V_265 ) , V_231 ) ;
V_36 = F_3 ( V_11 ) ;
V_36 &= ~ V_218 [ V_212 ] . V_58 ;
V_36 |= ( F_69 ( div , ( T_1 ) 255 ) << V_218 [ V_212 ] . V_264 ) ;
F_2 ( V_36 , V_11 ) ;
}
int F_81 ( T_2 clock , unsigned long V_231 )
{
if ( clock < V_221 )
F_76 ( clock , V_231 ) ;
else if ( clock == V_266 )
return F_77 ( V_231 ) ;
else if ( clock == V_227 )
return F_78 ( V_231 ) ;
else if ( ( clock == V_223 ) || ( clock == V_224 ) )
F_79 ( ( clock - V_223 ) , V_231 ) ;
else if ( ( V_225 <= clock ) && ( clock <= V_226 ) )
F_80 ( ( clock - V_225 ) , V_231 ) ;
return 0 ;
}
int F_82 ( T_2 V_73 )
{
if ( ( V_73 > V_280 ) ||
( V_73 < V_281 ) )
return - V_47 ;
F_31 ( & V_282 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_283 , ( V_41 + V_284 ) ) ;
F_17 ( ( ( V_285 << 4 ) | V_286 ) ,
( V_41 + V_287 ) ) ;
F_17 ( V_286 ,
( V_41 + V_288 ) ) ;
F_17 ( V_73 , ( V_41 + V_289 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_282 . V_120 ) ;
F_33 ( & V_282 . V_79 ) ;
return 0 ;
}
int F_83 ( T_2 V_290 )
{
F_31 ( & V_282 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_290 , ( V_41 + V_291 ) ) ;
F_17 ( V_292 , ( V_41 + V_284 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_282 . V_120 ) ;
F_33 ( & V_282 . V_79 ) ;
return 0 ;
}
int F_84 ( T_2 V_293 , T_2 V_294 )
{
F_31 ( & V_282 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_293 , ( V_41 + V_295 ) ) ;
F_17 ( V_294 , ( V_41 + V_296 ) ) ;
F_17 ( ( V_297 | V_298 ) ,
( V_41 + V_299 ) ) ;
F_17 ( V_300 , ( V_41 + V_284 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_282 . V_120 ) ;
F_33 ( & V_282 . V_79 ) ;
return 0 ;
}
static int F_85 ( T_4 V_36 )
{
F_31 ( & V_282 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_86 ( V_36 , ( V_41 + V_301 ) ) ;
F_17 ( V_302 , ( V_41 + V_284 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_282 . V_120 ) ;
F_33 ( & V_282 . V_79 ) ;
return 0 ;
}
int F_87 ( T_4 V_303 )
{
if ( V_303 == 0xFFFF )
return - V_47 ;
return F_85 ( V_303 ) ;
}
int F_88 ( void )
{
return F_85 ( 0xFFFF ) ;
}
static int F_89 ( T_2 V_304 , T_2 V_305 , T_2 V_306 , T_2 V_307 , T_2 V_308 )
{
F_31 ( & V_282 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_305 , ( V_41 + V_309 ) ) ;
F_17 ( V_306 , ( V_41 + V_310 ) ) ;
F_17 ( V_307 , ( V_41 + V_311 ) ) ;
F_17 ( V_308 , ( V_41 + V_312 ) ) ;
F_17 ( V_304 , ( V_41 + V_284 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_282 . V_120 ) ;
F_33 ( & V_282 . V_79 ) ;
return 0 ;
}
int F_90 ( T_2 V_313 , bool V_314 )
{
F_21 ( V_313 == 0 || V_313 > 0xf ) ;
return F_89 ( V_315 , V_313 , 0 , 0 ,
V_314 ? V_316 :
V_317 ) ;
}
int F_91 ( T_2 V_318 )
{
return F_89 ( V_319 , V_318 , 0 , 0 , 0 ) ;
}
int F_92 ( T_2 V_318 )
{
return F_89 ( V_320 , V_318 , 0 , 0 , 0 ) ;
}
int F_93 ( T_2 V_318 )
{
return F_89 ( V_321 , V_318 , 0 , 0 , 0 ) ;
}
int F_94 ( T_2 V_318 , T_1 V_322 )
{
return F_89 ( V_323 ,
( V_318 & V_324 ) |
( T_2 ) ( ( V_322 << 4 ) & 0xf0 ) ,
( T_2 ) ( ( V_322 >> 4 ) & 0xff ) ,
( T_2 ) ( ( V_322 >> 12 ) & 0xff ) ,
( T_2 ) ( ( V_322 >> 20 ) & 0xff ) ) ;
}
int F_95 ( T_2 V_325 , T_2 V_32 , T_2 * V_33 , T_2 V_326 )
{
int V_56 ;
if ( V_326 != 1 )
return - V_47 ;
F_31 ( & V_327 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 5 ) )
F_8 () ;
F_17 ( 0 , ( V_41 + V_328 ) ) ;
F_17 ( F_96 ( V_325 ) , ( V_41 + V_329 ) ) ;
F_17 ( V_330 , ( V_41 + V_331 ) ) ;
F_17 ( V_32 , ( V_41 + V_332 ) ) ;
F_17 ( 0 , ( V_41 + V_333 ) ) ;
F_2 ( F_23 ( 5 ) , V_87 ) ;
if ( ! F_45 ( & V_327 . V_120 ,
F_46 ( 20000 ) ) ) {
F_38 ( L_2 ,
V_131 ) ;
V_56 = - V_123 ;
} else {
V_56 = ( ( V_327 . V_121 . V_165 == V_334 ) ? 0 : - V_123 ) ;
}
if ( ! V_56 )
* V_33 = V_327 . V_121 . V_33 ;
F_33 ( & V_327 . V_79 ) ;
return V_56 ;
}
int F_97 ( T_2 V_325 , T_2 V_32 , T_2 * V_33 , T_2 * V_35 , T_2 V_326 )
{
int V_56 ;
if ( V_326 != 1 )
return - V_47 ;
F_31 ( & V_327 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 5 ) )
F_8 () ;
F_17 ( ~ * V_35 , ( V_41 + V_328 ) ) ;
F_17 ( F_98 ( V_325 ) , ( V_41 + V_329 ) ) ;
F_17 ( V_330 , ( V_41 + V_331 ) ) ;
F_17 ( V_32 , ( V_41 + V_332 ) ) ;
F_17 ( * V_33 , ( V_41 + V_333 ) ) ;
F_2 ( F_23 ( 5 ) , V_87 ) ;
if ( ! F_45 ( & V_327 . V_120 ,
F_46 ( 20000 ) ) ) {
F_38 ( L_2 ,
V_131 ) ;
V_56 = - V_123 ;
} else {
V_56 = ( ( V_327 . V_121 . V_165 == V_335 ) ? 0 : - V_123 ) ;
}
F_33 ( & V_327 . V_79 ) ;
return V_56 ;
}
int F_99 ( T_2 V_325 , T_2 V_32 , T_2 * V_33 , T_2 V_326 )
{
T_2 V_35 = ~ 0 ;
return F_97 ( V_325 , V_32 , V_33 , & V_35 , V_326 ) ;
}
int F_100 ( void )
{
T_1 V_36 ;
int V_200 = 0 ;
F_31 ( & V_78 . V_336 ) ;
V_36 = F_3 ( V_337 ) ;
if ( V_36 & V_338 )
goto V_72;
F_101 ( & V_339 , 1 ) ;
V_36 |= V_340 ;
F_2 ( V_36 , V_337 ) ;
F_4 ( 31 ) ;
V_36 |= V_338 ;
F_2 ( V_36 , V_337 ) ;
if ( ! F_45 ( & V_78 . V_341 ,
F_46 ( 5000 ) ) ) {
F_102 ( L_3 ,
V_131 ) ;
V_200 = - V_342 ;
}
V_72:
F_33 ( & V_78 . V_336 ) ;
return V_200 ;
}
void F_103 ( void )
{
T_1 V_36 ;
F_31 ( & V_78 . V_336 ) ;
V_36 = F_3 ( V_337 ) ;
if ( ! ( V_36 & V_338 ) )
goto V_72;
F_2 ( ( V_36 & ~ V_338 ) ,
V_337 ) ;
if ( ! F_45 ( & V_78 . V_341 ,
F_46 ( 5000 ) ) ) {
F_102 ( L_3 ,
V_131 ) ;
}
F_101 ( & V_339 , 0 ) ;
V_72:
F_33 ( & V_78 . V_336 ) ;
}
bool F_104 ( void )
{
return ( F_105 ( & V_339 ) != 0 ) ;
}
void F_106 ( T_4 V_343 )
{
F_86 ( V_343 , ( V_41 + V_344 ) ) ;
F_2 ( 1 , V_345 ) ;
}
T_4 F_107 ( void )
{
return F_108 ( V_41 + V_344 ) ;
}
void F_109 ( void )
{
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_346 , ( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
F_33 ( & V_114 . V_79 ) ;
}
static void F_110 ( void )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_79 , V_21 ) ;
while ( F_3 ( V_80 ) & F_23 ( 0 ) )
F_8 () ;
F_17 ( V_347 , ( V_41 + V_82 ) ) ;
F_2 ( F_23 ( 0 ) , V_87 ) ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
static inline void F_111 ( T_2 V_212 , T_2 V_89 )
{
F_112 ( L_4 ,
V_89 , V_212 ) ;
}
static bool F_113 ( void )
{
bool V_56 ;
T_1 V_348 ;
unsigned int V_212 ;
T_2 V_89 ;
V_89 = F_15 ( V_41 + V_349 ) ;
switch ( V_89 ) {
case V_350 :
case V_351 :
if ( F_15 ( V_41 + V_108 ) & 1 )
V_348 = F_3 ( V_41 + V_352 ) ;
else
V_348 = F_3 ( V_41 + V_353 ) ;
if ( V_348 & ( V_99 | V_100 ) )
F_114 ( & V_78 . V_341 ) ;
if ( V_348 & V_354 )
F_114 ( & V_183 . V_190 ) ;
V_348 &= V_78 . V_96 . V_97 ;
for ( V_212 = 0 ; V_212 < V_355 ; V_212 ++ ) {
if ( V_348 & V_356 [ V_212 ] )
F_115 ( F_116 ( V_357 , V_212 ) ) ;
}
V_56 = true ;
break;
default:
F_111 ( 0 , V_89 ) ;
V_56 = false ;
break;
}
F_2 ( F_23 ( 0 ) , V_358 ) ;
return V_56 ;
}
static bool F_117 ( void )
{
V_114 . V_121 . V_89 = F_15 ( V_41 + V_116 ) ;
V_114 . V_121 . V_122 = F_15 ( V_41 +
V_124 ) ;
V_114 . V_121 . V_132 = F_15 ( V_41 +
V_137 ) ;
V_114 . V_121 . V_140 = F_15 ( V_41 +
V_359 ) ;
F_2 ( F_23 ( 1 ) , V_358 ) ;
F_114 ( & V_114 . V_120 ) ;
return false ;
}
static bool F_118 ( void )
{
V_160 . V_121 . V_165 = F_15 ( V_41 + V_360 ) ;
F_2 ( F_23 ( 2 ) , V_358 ) ;
F_114 ( & V_160 . V_120 ) ;
return false ;
}
static bool F_119 ( void )
{
F_2 ( F_23 ( 3 ) , V_358 ) ;
return false ;
}
static bool F_120 ( void )
{
T_2 V_89 ;
bool V_361 = true ;
V_89 = F_15 ( V_41 + V_284 ) ;
switch ( V_89 ) {
case V_283 :
case V_292 :
case V_300 :
case V_302 :
case V_315 :
case V_319 :
case V_320 :
case V_323 :
case V_321 :
break;
default:
F_111 ( 4 , V_89 ) ;
V_361 = false ;
break;
}
F_2 ( F_23 ( 4 ) , V_358 ) ;
if ( V_361 )
F_114 ( & V_282 . V_120 ) ;
return false ;
}
static bool F_121 ( void )
{
V_327 . V_121 . V_165 = F_15 ( V_41 + V_362 ) ;
V_327 . V_121 . V_33 = F_15 ( V_41 + V_363 ) ;
F_2 ( F_23 ( 5 ) , V_358 ) ;
F_114 ( & V_327 . V_120 ) ;
return false ;
}
static bool F_122 ( void )
{
F_2 ( F_23 ( 6 ) , V_358 ) ;
return false ;
}
static bool F_123 ( void )
{
F_2 ( F_23 ( 7 ) , V_358 ) ;
return false ;
}
static T_6 F_124 ( int V_364 , void * V_365 )
{
T_1 V_57 ;
T_2 V_212 ;
T_6 V_56 ;
V_57 = ( F_3 ( V_366 ) & V_367 ) ;
if ( F_125 ( ! V_57 ) )
return V_368 ;
V_56 = V_369 ;
for ( V_212 = 0 ; V_57 ; V_212 ++ ) {
if ( V_57 & F_23 ( V_212 ) ) {
V_57 -= F_23 ( V_212 ) ;
if ( V_370 [ V_212 ] ( ) )
V_56 = V_371 ;
}
}
return V_56 ;
}
static T_6 F_126 ( int V_364 , void * V_365 )
{
F_110 () ;
return V_369 ;
}
static void F_127 ( struct V_372 * V_120 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_79 , V_21 ) ;
F_25 () ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
static void F_128 ( struct V_373 * V_232 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_374 , V_21 ) ;
V_78 . V_96 . V_97 &= ~ V_356 [ V_232 -> V_375 ] ;
F_9 ( & V_78 . V_374 , V_21 ) ;
if ( V_232 -> V_364 != V_376 )
F_129 ( & V_78 . V_377 ) ;
}
static void F_130 ( struct V_373 * V_232 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_374 , V_21 ) ;
V_78 . V_96 . V_97 |= V_356 [ V_232 -> V_375 ] ;
F_9 ( & V_78 . V_374 , V_21 ) ;
if ( V_232 -> V_364 != V_376 )
F_129 ( & V_78 . V_377 ) ;
}
static void F_131 ( struct V_373 * V_232 )
{
}
static T_7 char * F_132 ( T_1 V_378 )
{
switch ( V_378 ) {
case V_379 :
return L_5 ;
case V_380 :
return L_6 ;
case V_381 :
return L_7 ;
case V_382 :
return L_8 ;
case V_383 :
return L_9 ;
case V_384 :
return L_10 ;
case V_385 :
return L_11 ;
case V_386 :
return L_12 ;
case V_387 :
return L_13 ;
case V_388 :
return L_14 ;
case V_389 :
return L_15 ;
case V_390 :
return L_16 ;
case V_391 :
return L_17 ;
case V_392 :
return L_18 ;
case V_393 :
return L_19 ;
case V_394 :
return L_20 ;
case V_395 :
return L_21 ;
default:
return L_22 ;
}
}
static int F_133 ( struct V_396 * V_232 , unsigned int V_397 ,
T_8 V_375 )
{
F_134 ( V_397 , & V_398 ,
V_399 ) ;
return 0 ;
}
static int F_135 ( struct V_400 * V_401 )
{
int V_1 ;
V_357 = F_136 (
V_401 , V_355 , 0 ,
& V_402 , NULL ) ;
if ( ! V_357 ) {
F_38 ( L_23 ) ;
return - V_403 ;
}
for ( V_1 = 0 ; V_1 < V_355 ; V_1 ++ )
F_137 ( V_357 , V_1 ) ;
return 0 ;
}
static void F_138 ( struct V_404 * V_405 ,
T_1 V_406 )
{
struct V_407 * V_408 ;
void T_3 * V_409 ;
T_1 V_40 ;
V_408 = F_139 ( V_405 , V_410 ,
L_24 ) ;
if ( ! V_408 ) {
F_140 ( & V_405 -> V_411 ,
L_25 ) ;
return;
}
V_409 = F_141 ( V_408 -> V_412 , F_142 ( V_408 ) ) ;
if ( ! V_409 ) {
F_140 ( & V_405 -> V_411 , L_26 ) ;
return;
}
V_40 = F_3 ( V_409 + V_406 ) ;
V_38 . V_40 . V_378 = ( V_40 & 0xFF ) ;
V_38 . V_40 . V_413 = ( V_40 >> 8 ) & 0xFF ;
V_38 . V_40 . V_414 = ( V_40 >> 16 ) & 0xFF ;
V_38 . V_40 . V_415 = ( V_40 >> 24 ) & 0xFF ;
strncpy ( V_38 . V_40 . V_416 ,
F_132 ( V_38 . V_40 . V_378 ) ,
V_417 ) ;
V_38 . V_39 = true ;
F_143 ( L_27 ,
V_38 . V_40 . V_416 ,
V_38 . V_40 . V_378 ,
V_38 . V_40 . V_413 ,
V_38 . V_40 . V_414 ,
V_38 . V_40 . V_415 ) ;
F_144 ( V_409 ) ;
}
void T_7 F_145 ( T_1 V_418 , T_1 V_326 )
{
V_26 = F_141 ( V_418 , V_326 ) ;
if ( ! V_26 )
F_38 ( L_28 , V_131 ) ;
F_146 ( & V_78 . V_79 ) ;
F_146 ( & V_78 . V_374 ) ;
F_147 ( & V_78 . V_336 ) ;
F_148 ( & V_78 . V_341 ) ;
F_147 ( & V_114 . V_79 ) ;
F_148 ( & V_114 . V_120 ) ;
V_114 . V_132 = V_118 ;
F_147 ( & V_160 . V_79 ) ;
F_148 ( & V_160 . V_120 ) ;
F_146 ( & V_160 . V_178 ) ;
F_146 ( & V_183 . V_79 ) ;
F_147 ( & V_183 . V_184 ) ;
F_148 ( & V_183 . V_190 ) ;
F_147 ( & V_282 . V_79 ) ;
F_148 ( & V_282 . V_120 ) ;
F_147 ( & V_327 . V_79 ) ;
F_148 ( & V_327 . V_120 ) ;
F_149 ( & V_78 . V_377 , F_127 ) ;
}
static void T_7 F_150 ( void )
{
T_1 V_36 ;
V_36 = F_3 ( V_419 ) ;
V_36 &= ~ ( V_420 |
V_421 ) ;
F_2 ( V_36 , ( V_419 ) ) ;
}
static void F_151 ( void )
{
if ( F_14 () ) {
V_422 [ 3 ] . V_273 = 1000000 ;
V_422 [ 3 ] . V_277 = V_423 ;
}
}
static int F_152 ( struct V_424 * V_425 )
{
struct V_400 * V_401 ;
struct V_407 V_426 ;
const struct V_427 V_428 = {
. V_429 = L_29 ,
. V_430 = L_30 ,
. V_318 = V_431 ,
. V_432 = & V_426 ,
. V_433 = 1 ,
} ;
if ( ! V_425 -> V_434 )
return - V_435 ;
F_153 (parent->of_node, np) {
if ( F_154 ( V_401 , V_428 . V_430 ) )
break;
}
if ( ! V_401 ) {
F_155 ( V_425 , L_31 ) ;
return - V_435 ;
}
F_156 ( V_401 , & V_426 , 1 ) ;
return F_157 ( V_425 , 0 , & V_428 , 1 , NULL , 0 , NULL ) ;
}
static int F_158 ( struct V_404 * V_405 )
{
struct V_400 * V_401 = V_405 -> V_411 . V_434 ;
int V_364 = 0 , V_436 = 0 ;
struct V_407 * V_408 ;
V_408 = F_139 ( V_405 , V_410 , L_32 ) ;
if ( ! V_408 ) {
F_140 ( & V_405 -> V_411 , L_33 ) ;
return - V_47 ;
}
V_26 = F_159 ( & V_405 -> V_411 , V_408 -> V_412 , F_142 ( V_408 ) ) ;
if ( ! V_26 ) {
F_140 ( & V_405 -> V_411 ,
L_34 ) ;
return - V_437 ;
}
F_150 () ;
F_138 ( V_405 , V_438 ) ;
V_408 = F_139 ( V_405 , V_410 , L_35 ) ;
if ( ! V_408 ) {
F_140 ( & V_405 -> V_411 , L_36 ) ;
return - V_47 ;
}
V_41 = F_159 ( & V_405 -> V_411 , V_408 -> V_412 ,
F_142 ( V_408 ) ) ;
if ( ! V_41 ) {
F_140 ( & V_405 -> V_411 ,
L_37 ) ;
return - V_437 ;
}
F_2 ( V_367 , V_358 ) ;
V_364 = F_160 ( V_405 , 0 ) ;
if ( V_364 <= 0 ) {
F_140 ( & V_405 -> V_411 , L_38 ) ;
return V_364 ;
}
V_436 = F_161 ( V_364 , F_124 ,
F_126 , V_439 , L_32 , NULL ) ;
if ( V_436 < 0 ) {
F_38 ( L_39 ) ;
return V_436 ;
}
F_135 ( V_401 ) ;
F_162 ( V_280 ) ;
F_151 () ;
V_436 = F_157 ( & V_405 -> V_411 , 0 , V_440 ,
F_37 ( V_440 ) , NULL , 0 , V_357 ) ;
if ( V_436 ) {
F_38 ( L_40 ) ;
return V_436 ;
}
if ( ! F_163 ( L_41 ) ) {
V_436 = F_157 ( & V_405 -> V_411 , 0 , V_441 ,
F_37 ( V_441 ) , NULL , 0 ,
V_357 ) ;
if ( V_436 ) {
F_164 ( & V_405 -> V_411 ) ;
F_38 ( L_40 ) ;
return V_436 ;
}
}
V_436 = F_152 ( & V_405 -> V_411 ) ;
if ( V_436 ) {
F_164 ( & V_405 -> V_411 ) ;
F_38 ( L_42 ) ;
return V_436 ;
}
F_143 ( L_43 ) ;
return V_436 ;
}
static int T_7 F_165 ( void )
{
return F_166 ( & V_442 ) ;
}
