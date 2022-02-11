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
int F_16 ( void )
{
return F_15 ( V_41 + V_44 ) ;
}
int F_17 ( enum V_45 V_36 )
{
if ( V_36 < V_46 || V_36 > V_47 )
return - V_48 ;
F_18 ( V_36 , ( V_41 + V_49 ) ) ;
return 0 ;
}
enum V_50 F_19 ( void )
{
return F_15 ( V_41 + V_51 ) ;
}
enum V_52 F_20 ( void )
{
return F_15 ( V_41 + V_53 ) ;
}
int F_21 ( T_2 V_54 , T_2 V_55 , T_2 div )
{
static int V_56 [ 2 ] ;
int V_57 = 0 ;
unsigned long V_21 ;
T_1 V_36 ;
T_1 V_58 ;
T_1 V_35 ;
T_1 V_59 ;
F_22 ( V_54 > 1 ) ;
F_22 ( div > 63 ) ;
F_22 ( ( V_54 == 0 ) && ( V_55 > V_60 ) ) ;
if ( ! div && ! V_56 [ V_54 ] )
return - V_48 ;
switch ( V_54 ) {
case 0 :
V_59 = V_61 ;
V_35 = ( V_61 | V_62 ) ;
V_58 = ( ( V_55 << V_63 ) |
( div << V_64 ) ) ;
break;
case 1 :
V_59 = V_65 ;
V_35 = ( V_65 | V_66 |
V_67 ) ;
V_58 = ( ( V_55 << V_68 ) |
( div << V_69 ) ) ;
break;
}
V_58 &= V_35 ;
F_7 ( & V_70 , V_21 ) ;
V_36 = F_3 ( V_71 ) ;
if ( V_36 & V_59 ) {
if ( div ) {
if ( ( V_36 & V_35 ) != V_58 ) {
V_57 = - V_72 ;
goto V_73;
}
} else {
if ( ( V_36 & V_35 & ~ V_59 ) != V_58 ) {
V_57 = - V_48 ;
goto V_73;
}
}
}
F_2 ( ( V_58 | ( V_36 & ~ V_35 ) ) , V_71 ) ;
V_56 [ V_54 ] += ( div ? 1 : - 1 ) ;
V_73:
F_9 ( & V_70 , V_21 ) ;
return V_57 ;
}
int F_23 ( T_2 V_74 , bool V_75 , bool V_76 )
{
unsigned long V_21 ;
F_22 ( ( V_74 < V_77 ) || ( V_78 < V_74 ) ) ;
F_7 ( & V_79 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_18 ( V_82 , ( V_41 + V_83 ) ) ;
F_18 ( V_74 , ( V_41 + V_84 ) ) ;
F_18 ( ( V_76 ? 1 : 0 ) , ( V_41 + V_85 ) ) ;
F_18 ( ( V_75 ? 1 : 0 ) ,
( V_41 + V_86 ) ) ;
F_18 ( 0 , ( V_41 + V_87 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
F_9 ( & V_79 . V_80 , V_21 ) ;
return 0 ;
}
T_2 F_25 ( void )
{
return F_15 ( V_41 + V_89 ) ;
}
static void F_26 ( void )
{
const T_2 V_90 [ 2 ] = {
V_91 ,
V_92
} ;
static T_1 V_93 ;
static T_1 V_94 ;
T_1 V_95 ;
T_1 V_96 ;
unsigned int V_1 ;
V_95 = V_79 . V_97 . V_98 | V_79 . V_97 . V_99 ;
V_95 |= ( V_100 | V_101 ) ;
V_96 = V_79 . V_97 . V_96 ;
if ( ( V_95 == V_93 ) && ( V_96 == V_94 ) )
return;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_2 ( V_95 , ( V_41 + V_102 ) ) ;
F_2 ( V_96 , ( V_41 + V_103 ) ) ;
F_18 ( V_90 [ V_1 ] , ( V_41 + V_83 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
}
V_93 = V_95 ;
V_94 = V_96 ;
}
void F_27 ( T_1 V_104 )
{
unsigned long V_21 ;
T_1 V_58 ;
int V_1 ;
F_22 ( V_104 != ( V_104 & V_105 ) ) ;
for ( V_1 = 0 , V_58 = 0 ; V_1 < V_106 ; V_1 ++ ) {
if ( V_104 & F_28 ( V_1 ) )
V_58 |= V_107 [ V_1 ] ;
}
F_7 ( & V_79 . V_80 , V_21 ) ;
V_79 . V_97 . V_99 = V_58 ;
F_26 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
void F_29 ( T_1 V_96 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
V_79 . V_97 . V_96 = V_96 ;
F_26 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
void F_30 ( void T_3 * * V_108 )
{
if ( F_15 ( V_41 + V_109 ) & 1 )
* V_108 = ( V_41 + V_110 ) ;
else
* V_108 = ( V_41 + V_111 ) ;
}
int F_31 ( T_2 V_112 )
{
int V_57 ;
if ( V_112 < V_113 || V_112 > V_114 )
return - V_48 ;
V_57 = 0 ;
F_32 ( & V_115 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_116 , ( V_41 + V_117 ) ) ;
F_18 ( V_112 , ( V_41 + V_118 ) ) ;
F_18 ( V_119 , ( V_41 + V_120 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
if ( ( V_115 . V_122 . V_90 != V_116 ) ||
( V_115 . V_122 . V_123 != V_112 ) )
V_57 = - V_124 ;
F_34 ( & V_115 . V_80 ) ;
return V_57 ;
}
int F_35 ( void )
{
return F_15 ( V_41 + V_125 ) ;
}
int F_36 ( void )
{
return F_15 ( V_126 ) ;
}
int F_37 ( T_2 V_112 )
{
if ( V_112 < V_127 || V_112 > V_128 )
return - V_48 ;
if ( V_129 )
F_18 ( V_112 , V_126 ) ;
return 0 ;
}
static void F_38 ( bool V_130 )
{
T_1 V_131 [] = {
V_132 ,
V_133
} ;
unsigned long V_21 ;
unsigned int V_1 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
for ( V_1 = 0 ; V_1 < F_39 ( V_131 ) ; V_1 ++ ) {
T_1 V_36 ;
T_1 div ;
V_36 = F_3 ( V_26 + V_131 [ V_1 ] ) ;
div = ( V_36 & V_134 ) ;
if ( V_130 ) {
if ( ( div <= 1 ) || ( div > 15 ) ) {
F_40 ( L_1 ,
div , V_135 ) ;
goto V_73;
}
div <<= 1 ;
} else {
if ( div <= 2 )
goto V_73;
div >>= 1 ;
}
V_36 = ( ( V_36 & ~ V_134 ) |
( div & V_134 ) ) ;
F_2 ( V_36 , V_26 + V_131 [ V_1 ] ) ;
}
V_73:
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
int F_41 ( T_2 V_112 )
{
int V_57 = 0 ;
if ( V_112 == V_115 . V_136 )
return 0 ;
F_32 ( & V_115 . V_80 ) ;
if ( V_115 . V_136 == V_137 )
F_38 ( false ) ;
if ( ( V_112 != V_138 ) && ( V_115 . V_136 != V_138 ) )
goto V_139;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_116 , ( V_41 + V_117 ) ) ;
F_18 ( V_113 , ( V_41 + V_118 ) ) ;
F_18 ( ( ( V_112 == V_137 ) ? V_140 : V_112 ) ,
( V_41 + V_120 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
if ( ( V_115 . V_122 . V_90 != V_116 ) ||
( V_115 . V_122 . V_136 != V_112 ) )
V_57 = - V_124 ;
V_139:
if ( ( ! V_57 && ( V_112 == V_137 ) ) ||
( V_57 && ( V_115 . V_136 == V_137 ) ) )
F_38 ( true ) ;
if ( ! V_57 )
V_115 . V_136 = V_112 ;
F_34 ( & V_115 . V_80 ) ;
return V_57 ;
}
int F_42 ( void )
{
return F_15 ( V_41 + V_141 ) ;
}
int F_43 ( bool V_130 )
{
int V_57 = 0 ;
T_2 V_90 ;
static unsigned int V_56 ;
F_32 ( & V_115 . V_80 ) ;
if ( V_130 ) {
if ( 0 != V_56 ++ )
goto V_73;
V_90 = V_142 ;
} else {
if ( V_56 == 0 ) {
V_57 = - V_124 ;
goto V_73;
} else if ( 1 != V_56 -- ) {
goto V_73;
}
V_90 = V_143 ;
}
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_90 , ( V_41 + V_117 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
if ( ( V_115 . V_122 . V_90 != V_90 ) ||
( ( V_115 . V_122 . V_144 & F_28 ( 0 ) ) != 0 ) )
V_57 = - V_124 ;
V_73:
F_34 ( & V_115 . V_80 ) ;
return V_57 ;
}
int F_44 ( void )
{
int V_57 = 0 ;
F_32 ( & V_115 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_145 ,
( V_41 + V_117 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
if ( ( V_115 . V_122 . V_90 != V_145 ) ||
( ( V_115 . V_122 . V_144 & F_28 ( 0 ) ) != 0 ) )
V_57 = - V_124 ;
F_34 ( & V_115 . V_80 ) ;
return V_57 ;
}
static int F_45 ( T_2 clock , bool V_130 )
{
int V_57 = 0 ;
if ( clock == V_146 )
clock = ( V_130 ? V_147 : V_148 ) ;
else if ( clock == V_149 )
clock = ( V_130 ? V_150 : V_151 ) ;
else
return - V_48 ;
F_32 ( & V_115 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_152 , ( V_41 + V_117 ) ) ;
F_18 ( clock , ( V_41 + V_153 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
if ( V_115 . V_122 . V_90 != V_152 )
V_57 = - V_124 ;
F_34 ( & V_115 . V_80 ) ;
return V_57 ;
}
int F_46 ( T_4 V_154 , T_2 V_155 )
{
int V_57 = 0 ;
bool V_156 = false ;
int V_1 ;
F_22 ( V_154 >= V_157 ) ;
switch ( V_154 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
V_156 = true ;
break;
}
F_22 ( V_155 > V_162 ) ;
F_22 ( V_155 == V_163 && ! V_156 ) ;
F_32 ( & V_164 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 2 ) )
F_8 () ;
for ( V_1 = 0 ; V_1 < V_157 ; V_1 ++ )
F_18 ( V_165 , ( V_41 + V_166 + V_1 ) ) ;
F_18 ( V_155 , ( V_41 + V_166 + V_154 ) ) ;
F_18 ( V_167 , ( V_41 + V_168 ) ) ;
F_2 ( F_24 ( 2 ) , V_88 ) ;
if ( ! F_47 ( & V_164 . V_121 ,
F_48 ( 20000 ) ) ) {
F_40 ( L_2 ,
V_135 ) ;
V_57 = - V_124 ;
goto V_73;
}
if ( V_164 . V_122 . V_169 != V_170 )
V_57 = - V_124 ;
V_73:
F_34 ( & V_164 . V_80 ) ;
return V_57 ;
}
void F_49 ( struct V_171 * V_172 ,
struct V_171 * V_173 )
{
T_1 V_174 ;
T_1 V_175 ;
unsigned long V_21 ;
F_22 ( ( V_172 == NULL ) || ( V_173 == NULL ) ) ;
V_174 = ( V_172 -> V_176 & 0xF ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_177 & 0xF ) ) ;
V_174 = ( ( V_174 << 8 ) | ( V_172 -> V_178 & 0xFF ) ) ;
V_174 = ( ( V_174 << 8 ) | ( V_172 -> V_179 & 0xFF ) ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_180 & 0xF ) ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_181 & 0xF ) ) ;
V_175 = ( V_173 -> V_176 & 0xF ) ;
V_175 = ( ( V_175 << 4 ) | ( V_173 -> V_177 & 0xF ) ) ;
V_175 = ( ( V_175 << 8 ) | ( V_173 -> V_178 & 0xFF ) ) ;
V_175 = ( ( V_175 << 8 ) | ( V_173 -> V_179 & 0xFF ) ) ;
V_175 = ( ( V_175 << 4 ) | ( V_173 -> V_180 & 0xF ) ) ;
V_175 = ( ( V_175 << 4 ) | ( V_173 -> V_181 & 0xF ) ) ;
F_7 ( & V_164 . V_182 , V_21 ) ;
F_2 ( V_174 , ( V_41 + V_183 ) ) ;
F_2 ( V_175 , ( V_41 + V_184 ) ) ;
V_164 . V_185 =
( ( V_172 -> V_176 == V_186 ) ||
( V_172 -> V_177 == V_186 ) ||
( V_173 -> V_176 == V_186 ) ||
( V_173 -> V_177 == V_186 ) ) ;
F_9 ( & V_164 . V_182 , V_21 ) ;
}
bool F_50 ( void )
{
return V_164 . V_185 ;
}
static int F_51 ( bool V_130 )
{
int V_57 ;
unsigned long V_21 ;
V_57 = 0 ;
F_32 ( & V_187 . V_188 ) ;
F_7 ( & V_187 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 3 ) )
F_8 () ;
F_18 ( ( V_130 ? V_189 : V_190 ) , ( V_41 + V_191 ) ) ;
F_18 ( V_192 , ( V_41 + V_193 ) ) ;
F_2 ( F_24 ( 3 ) , V_88 ) ;
F_9 ( & V_187 . V_80 , V_21 ) ;
if ( V_130 && ! F_47 ( & V_187 . V_194 ,
F_48 ( 20000 ) ) ) {
F_40 ( L_2 ,
V_135 ) ;
V_57 = - V_124 ;
}
F_34 ( & V_187 . V_188 ) ;
return V_57 ;
}
static int F_52 ( bool V_130 )
{
T_1 V_36 = ( V_195 | V_196 ) ;
if ( ! V_130 )
V_36 |= V_197 ;
F_2 ( V_36 , V_198 ) ;
return 0 ;
}
static int F_53 ( T_2 clock , bool V_130 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_199 [ clock ] . V_200 ) ;
if ( V_130 ) {
V_36 |= ( V_201 | V_199 [ clock ] . V_202 ) ;
} else {
V_199 [ clock ] . V_202 = ( V_36 & V_203 ) ;
V_36 &= ~ ( V_201 | V_203 ) ;
}
F_2 ( V_36 , V_26 + V_199 [ clock ] . V_200 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
static int F_54 ( T_2 clock , bool V_130 )
{
T_1 V_36 ;
int V_204 ;
if ( V_130 ) {
V_36 = F_3 ( V_205 ) ;
F_2 ( V_36 | V_206 , V_205 ) ;
}
V_204 = F_53 ( clock , V_130 ) ;
if ( ! V_204 && ! V_130 ) {
V_36 = F_3 ( V_205 ) ;
F_2 ( V_36 & ~ V_206 , V_205 ) ;
}
return V_204 ;
}
static inline bool F_55 ( void )
{
return ( F_3 ( V_16 ) &
( V_207 |
V_208 ) ) ==
( V_207 |
V_208 ) ;
}
static int F_56 ( bool V_130 )
{
int V_57 = 0 ;
T_1 V_36 ;
F_2 ( ( V_209 |
V_210 ) , ( V_130 ?
V_5 : V_211 ) ) ;
V_36 = F_3 ( V_13 ) ;
if ( V_130 )
V_36 |= V_212 ;
else
V_36 &= ~ V_212 ;
F_2 ( V_36 , V_13 ) ;
if ( V_130 ) {
unsigned int V_1 ;
bool V_213 = F_55 () ;
for ( V_1 = 10 ; ! V_213 && ( V_1 > 0 ) ; -- V_1 ) {
F_4 ( 100 ) ;
V_213 = F_55 () ;
}
if ( V_213 ) {
F_2 ( V_214 ,
V_18 ) ;
} else {
F_2 ( ( V_209 |
V_210 ) ,
V_211 ) ;
V_36 &= ~ V_212 ;
F_2 ( V_36 , V_13 ) ;
V_57 = - V_215 ;
}
} else {
F_2 ( V_214 , V_3 ) ;
}
return V_57 ;
}
static int F_57 ( T_2 V_216 , bool V_130 )
{
T_1 V_36 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_217 [ V_216 ] . V_218 ;
V_36 |= ( ( V_130 ? V_217 [ V_216 ] . V_219 : V_220 ) <<
V_217 [ V_216 ] . V_221 ) ;
F_2 ( V_36 , V_9 ) ;
return 0 ;
}
static int F_58 ( T_2 V_216 , bool V_130 )
{
T_1 V_36 ;
V_36 = F_3 ( V_11 ) ;
V_130 ? ( V_36 |= V_222 [ V_216 ] . V_223 ) : ( V_36 &= ~ V_222 [ V_216 ] . V_223 ) ;
F_2 ( V_36 , V_11 ) ;
return 0 ;
}
int F_59 ( T_2 clock , bool V_130 )
{
if ( clock == V_224 )
return F_54 ( clock , V_130 ) ;
else if ( clock < V_225 )
return F_53 ( clock , V_130 ) ;
else if ( clock == V_226 )
return F_52 ( V_130 ) ;
else if ( ( clock == V_227 ) || ( clock == V_228 ) )
return F_57 ( ( clock - V_227 ) , V_130 ) ;
else if ( ( V_229 <= clock ) && ( clock <= V_230 ) )
return F_58 ( ( clock - V_229 ) , V_130 ) ;
else if ( clock == V_231 )
return F_56 ( V_130 ) ;
else if ( clock == V_232 )
return F_51 ( V_130 ) ;
else if ( ( clock == V_146 ) || ( clock == V_149 ) )
return F_45 ( clock , V_130 ) ;
else
return - V_48 ;
}
static unsigned long F_60 ( void T_3 * V_32 , unsigned long V_233 ,
int V_234 )
{
T_5 V_235 ;
T_1 V_36 ;
T_1 V_236 ;
T_1 div = 1 ;
V_36 = F_3 ( V_32 ) ;
V_235 = V_233 ;
V_235 *= ( ( V_36 & V_237 ) >> V_238 ) ;
V_236 = ( ( V_36 & V_239 ) >> V_240 ) ;
if ( V_236 > 1 )
div *= V_236 ;
V_236 = ( ( V_36 & V_241 ) >> V_242 ) ;
if ( V_236 > 1 )
div *= V_236 ;
if ( V_36 & V_243 )
div *= 2 ;
if ( ( V_234 == V_244 ) || ( ( V_234 == V_245 ) &&
( V_36 & V_246 ) &&
( ( V_32 == V_247 ) ||
( V_32 == V_248 ) ||
( V_32 == V_249 ) ) ) )
div *= 2 ;
( void ) F_61 ( V_235 , div ) ;
return ( unsigned long ) V_235 ;
}
static unsigned long F_62 ( T_2 clock )
{
T_1 V_36 ;
T_1 V_202 ;
unsigned long V_235 = V_250 ;
V_36 = F_3 ( V_26 + V_199 [ clock ] . V_200 ) ;
if ( V_36 & V_251 ) {
if ( V_199 [ clock ] . V_252 && ( V_36 & V_253 ) )
V_235 /= 2 ;
return V_235 ;
}
V_36 |= V_199 [ clock ] . V_202 ;
V_202 = ( V_36 & V_203 ) ;
if ( V_202 == V_254 )
V_235 = F_60 ( V_247 , V_235 , V_199 [ clock ] . V_234 ) ;
else if ( V_202 == V_255 )
V_235 = F_60 ( V_256 , V_235 , V_199 [ clock ] . V_234 ) ;
else if ( V_202 == V_257 )
V_235 = F_60 ( V_249 , V_235 , V_199 [ clock ] . V_234 ) ;
else
return 0 ;
if ( ( clock == V_224 ) &&
( V_36 & V_258 ) ) {
T_5 V_57 = ( V_235 * 10 ) ;
( void ) F_61 ( V_57 , 25 ) ;
return ( unsigned long ) V_57 ;
}
V_36 &= V_134 ;
if ( V_36 )
return V_235 / V_36 ;
else
return 0 ;
}
static unsigned long F_63 ( void )
{
T_1 V_57 ;
unsigned long V_235 ;
V_57 = F_3 ( V_259 ) ;
if ( V_57 & V_260 ) {
V_235 = F_60 ( V_249 , V_250 , V_244 ) ;
if ( ! ( V_57 & V_261 ) )
V_235 /= 2 ;
V_57 = F_3 ( V_262 ) ;
V_57 &= V_134 ;
V_235 /= V_57 ;
} else {
V_235 = F_60 ( V_248 , V_250 , V_245 ) ;
}
return V_235 ;
}
static unsigned long F_64 ( T_2 V_216 )
{
T_1 V_219 ;
T_1 div = 1 ;
V_219 = F_3 ( V_9 ) ;
V_219 = ( ( V_219 & V_217 [ V_216 ] . V_218 ) >> V_217 [ V_216 ] . V_221 ) ;
if ( V_219 == V_220 )
V_219 = V_217 [ V_216 ] . V_219 ;
else
V_217 [ V_216 ] . V_219 = V_219 ;
switch ( V_219 ) {
case V_263 :
div *= 2 ;
case V_264 :
div *= 2 ;
case V_265 :
return F_60 ( V_7 , F_62 ( V_266 ) ,
V_267 ) / div ;
default:
return 0 ;
}
}
static unsigned long F_65 ( T_2 V_216 )
{
T_1 div ;
div = F_3 ( V_11 ) ;
div = ( ( div & V_222 [ V_216 ] . V_59 ) >> ( V_222 [ V_216 ] . V_268 ) ) ;
return F_62 ( V_269 ) / F_66 ( ( T_1 ) 1 , div ) ;
}
unsigned long F_67 ( T_2 clock )
{
if ( clock < V_225 )
return F_62 ( clock ) ;
else if ( clock == V_226 )
return V_250 / 16 ;
else if ( clock == V_232 )
return V_250 ;
else if ( clock == V_146 )
return F_60 ( V_247 , V_250 , V_267 ) ;
else if ( clock == V_149 )
return F_60 ( V_256 , V_250 , V_267 ) ;
else if ( clock == V_270 )
return F_63 () ;
else if ( clock == V_271 )
return F_60 ( V_249 , V_250 , V_267 ) ;
else if ( clock == V_231 )
return F_60 ( V_7 , F_62 ( V_266 ) ,
V_267 ) ;
else if ( ( clock == V_227 ) || ( clock == V_228 ) )
return F_64 ( clock - V_227 ) ;
else if ( ( V_229 <= clock ) && ( clock <= V_230 ) )
return F_65 ( clock - V_229 ) ;
else
return 0 ;
}
static unsigned long F_68 ( T_1 V_272 , int V_234 )
{
if ( V_272 & V_251 )
return V_250 ;
V_272 &= V_203 ;
if ( V_272 == V_254 )
return F_60 ( V_247 , V_250 , V_234 ) ;
else if ( V_272 == V_255 )
return F_60 ( V_256 , V_250 , V_234 ) ;
else if ( V_272 == V_257 )
return F_60 ( V_249 , V_250 , V_234 ) ;
else
return 0 ;
}
static T_1 F_69 ( unsigned long V_233 , unsigned long V_235 )
{
T_1 div ;
div = ( V_233 / V_235 ) ;
if ( div == 0 )
return 1 ;
if ( V_235 < ( V_233 / div ) )
div ++ ;
return div ;
}
static long F_70 ( T_2 clock , unsigned long V_235 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_233 ;
long V_273 ;
V_36 = F_3 ( V_26 + V_199 [ clock ] . V_200 ) ;
V_233 = F_68 ( ( V_36 | V_199 [ clock ] . V_202 ) ,
V_199 [ clock ] . V_234 ) ;
div = F_69 ( V_233 , V_235 ) ;
if ( V_36 & V_251 ) {
if ( V_199 [ clock ] . V_252 ) {
if ( div > 2 )
div = 2 ;
} else {
div = 1 ;
}
} else if ( ( clock == V_224 ) && ( div == 3 ) ) {
T_5 V_57 = ( V_233 * 10 ) ;
( void ) F_61 ( V_57 , 25 ) ;
if ( V_57 <= V_235 )
return ( unsigned long ) V_57 ;
}
V_273 = ( V_233 / F_71 ( div , ( T_1 ) 31 ) ) ;
return V_273 ;
}
static long F_72 ( unsigned long V_235 )
{
long V_274 = 0 ;
int V_1 = 0 ;
V_235 = V_235 / 1000 ;
while ( V_275 [ V_1 ] . V_276 != V_277 ) {
V_274 = V_275 [ V_1 ] . V_276 ;
if ( V_274 == V_235 )
break;
V_1 ++ ;
}
return V_274 * 1000 ;
}
static long F_73 ( unsigned long V_235 )
{
long V_273 = 0 ;
unsigned long V_233 ;
unsigned long V_278 ;
T_1 V_57 ;
V_233 = F_62 ( V_266 ) ;
V_278 = V_235 ;
for ( V_57 = 7 ; ( V_278 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_236 ;
V_236 = ( V_57 * V_235 ) ;
( void ) F_61 ( V_236 , V_233 ) ;
if ( V_236 < 6 )
V_236 = 6 ;
else if ( V_236 > 255 )
V_236 = 255 ;
V_236 *= V_233 ;
if ( ( ( 2 * V_236 ) < ( V_57 * V_279 ) ) ||
( ( V_57 * V_280 ) < ( 2 * V_236 ) ) )
continue;
( void ) F_61 ( V_236 , V_57 ) ;
if ( V_235 < V_236 ) {
if ( V_273 == 0 )
V_273 = ( long ) V_236 ;
break;
}
if ( ( V_235 - V_236 ) < V_278 ) {
V_278 = ( V_235 - V_236 ) ;
V_273 = ( long ) V_236 ;
}
}
return V_273 ;
}
static long F_74 ( unsigned long V_235 )
{
T_1 div ;
unsigned long V_233 ;
long V_273 ;
V_233 = F_60 ( V_7 , F_62 ( V_266 ) ,
V_267 ) ;
div = F_69 ( V_233 , V_235 ) ;
V_273 = ( V_233 / ( ( div > 2 ) ? 4 : div ) ) ;
return V_273 ;
}
static long F_75 ( unsigned long V_235 )
{
T_1 div ;
unsigned long V_233 ;
long V_273 ;
V_233 = F_62 ( V_269 ) ;
div = F_69 ( V_233 , V_235 ) ;
V_273 = ( V_233 / F_71 ( div , ( T_1 ) 255 ) ) ;
return V_273 ;
}
long F_76 ( T_2 clock , unsigned long V_235 )
{
if ( clock < V_225 )
return F_70 ( clock , V_235 ) ;
else if ( clock == V_270 )
return F_72 ( V_235 ) ;
else if ( clock == V_231 )
return F_73 ( V_235 ) ;
else if ( ( clock == V_227 ) || ( clock == V_228 ) )
return F_74 ( V_235 ) ;
else if ( ( V_229 <= clock ) && ( clock <= V_230 ) )
return F_75 ( V_235 ) ;
else
return ( long ) F_67 ( clock ) ;
}
static void F_77 ( T_2 clock , unsigned long V_235 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_233 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_199 [ clock ] . V_200 ) ;
V_233 = F_68 ( ( V_36 | V_199 [ clock ] . V_202 ) ,
V_199 [ clock ] . V_234 ) ;
div = F_69 ( V_233 , V_235 ) ;
if ( V_36 & V_251 ) {
if ( V_199 [ clock ] . V_252 ) {
if ( div > 1 )
V_36 |= V_253 ;
else
V_36 &= ~ V_253 ;
}
} else if ( clock == V_224 ) {
V_36 &= ~ ( V_134 |
V_258 ) ;
if ( div == 3 ) {
T_5 V_57 = ( V_233 * 10 ) ;
( void ) F_61 ( V_57 , 25 ) ;
if ( V_57 <= V_235 ) {
V_36 |= V_258 ;
div = 0 ;
}
}
V_36 |= F_71 ( div , ( T_1 ) 31 ) ;
} else {
V_36 &= ~ V_134 ;
V_36 |= F_71 ( div , ( T_1 ) 31 ) ;
}
F_2 ( V_36 , V_26 + V_199 [ clock ] . V_200 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
static int F_78 ( unsigned long V_235 )
{
int V_1 = 0 ;
V_235 = V_235 / 1000 ;
while ( V_275 [ V_1 ] . V_276 != V_277 ) {
if ( V_275 [ V_1 ] . V_276 == V_235 )
break;
V_1 ++ ;
}
if ( V_275 [ V_1 ] . V_276 != V_235 )
return - V_48 ;
return F_31 ( V_275 [ V_1 ] . V_281 ) ;
}
static int F_79 ( unsigned long V_235 )
{
unsigned long V_233 ;
unsigned long V_278 ;
T_1 V_282 = 0 ;
T_1 V_57 ;
V_233 = F_62 ( V_266 ) ;
V_278 = V_235 ;
for ( V_57 = 7 ; ( V_278 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_236 ;
T_5 V_283 ;
V_236 = ( V_57 * V_235 ) ;
( void ) F_61 ( V_236 , V_233 ) ;
if ( V_236 < 6 )
V_236 = 6 ;
else if ( V_236 > 255 )
V_236 = 255 ;
V_283 = ( V_236 * V_233 ) ;
if ( ( ( 2 * V_283 ) < ( V_57 * V_279 ) ) ||
( ( V_57 * V_280 ) < ( 2 * V_283 ) ) )
continue;
( void ) F_61 ( V_283 , V_57 ) ;
if ( V_235 < V_283 ) {
if ( V_282 == 0 )
V_282 = ( ( ( T_1 ) V_236 << V_238 ) |
( V_57 << V_242 ) ) ;
break;
}
if ( ( V_235 - V_283 ) < V_278 ) {
V_278 = ( V_235 - V_283 ) ;
V_282 = ( ( ( T_1 ) V_236 << V_238 ) |
( V_57 << V_242 ) ) ;
}
}
if ( V_282 == 0 )
return - V_48 ;
V_282 |= ( 1 << V_240 ) ;
F_2 ( V_282 , V_7 ) ;
return 0 ;
}
static void F_80 ( T_2 V_216 , unsigned long V_235 )
{
T_1 V_36 ;
T_1 div ;
div = F_69 ( F_60 ( V_7 ,
F_62 ( V_266 ) , V_267 ) , V_235 ) ;
V_217 [ V_216 ] . V_219 = ( div == 1 ) ? V_265 :
( div == 2 ) ? V_264 :
V_263 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_217 [ V_216 ] . V_218 ;
V_36 |= ( V_217 [ V_216 ] . V_219 << V_217 [ V_216 ] . V_221 ) ;
F_2 ( V_36 , V_9 ) ;
}
static void F_81 ( T_2 V_216 , unsigned long V_235 )
{
T_1 V_36 ;
T_1 div ;
div = F_69 ( F_62 ( V_269 ) , V_235 ) ;
V_36 = F_3 ( V_11 ) ;
V_36 &= ~ V_222 [ V_216 ] . V_59 ;
V_36 |= ( F_71 ( div , ( T_1 ) 255 ) << V_222 [ V_216 ] . V_268 ) ;
F_2 ( V_36 , V_11 ) ;
}
int F_82 ( T_2 clock , unsigned long V_235 )
{
if ( clock < V_225 )
F_77 ( clock , V_235 ) ;
else if ( clock == V_270 )
return F_78 ( V_235 ) ;
else if ( clock == V_231 )
return F_79 ( V_235 ) ;
else if ( ( clock == V_227 ) || ( clock == V_228 ) )
F_80 ( ( clock - V_227 ) , V_235 ) ;
else if ( ( V_229 <= clock ) && ( clock <= V_230 ) )
F_81 ( ( clock - V_229 ) , V_235 ) ;
return 0 ;
}
int F_83 ( T_2 V_74 )
{
if ( ( V_74 > V_284 ) ||
( V_74 < V_285 ) )
return - V_48 ;
F_32 ( & V_286 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_287 , ( V_41 + V_288 ) ) ;
F_18 ( ( ( V_289 << 4 ) | V_290 ) ,
( V_41 + V_291 ) ) ;
F_18 ( V_290 ,
( V_41 + V_292 ) ) ;
F_18 ( V_74 , ( V_41 + V_293 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_33 ( & V_286 . V_121 ) ;
F_34 ( & V_286 . V_80 ) ;
return 0 ;
}
int F_84 ( T_2 V_294 )
{
F_32 ( & V_286 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_294 , ( V_41 + V_295 ) ) ;
F_18 ( V_296 , ( V_41 + V_288 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_33 ( & V_286 . V_121 ) ;
F_34 ( & V_286 . V_80 ) ;
return 0 ;
}
int F_85 ( T_2 V_297 , T_2 V_298 )
{
F_32 ( & V_286 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_297 , ( V_41 + V_299 ) ) ;
F_18 ( V_298 , ( V_41 + V_300 ) ) ;
F_18 ( ( V_301 | V_302 ) ,
( V_41 + V_303 ) ) ;
F_18 ( V_304 , ( V_41 + V_288 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_33 ( & V_286 . V_121 ) ;
F_34 ( & V_286 . V_80 ) ;
return 0 ;
}
static int F_86 ( T_4 V_36 )
{
F_32 ( & V_286 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_87 ( V_36 , ( V_41 + V_305 ) ) ;
F_18 ( V_306 , ( V_41 + V_288 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_33 ( & V_286 . V_121 ) ;
F_34 ( & V_286 . V_80 ) ;
return 0 ;
}
int F_88 ( T_4 V_307 )
{
if ( V_307 == 0xFFFF )
return - V_48 ;
return F_86 ( V_307 ) ;
}
int F_89 ( void )
{
return F_86 ( 0xFFFF ) ;
}
static int F_90 ( T_2 V_308 , T_2 V_309 , T_2 V_310 , T_2 V_311 , T_2 V_312 )
{
F_32 ( & V_286 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_309 , ( V_41 + V_313 ) ) ;
F_18 ( V_310 , ( V_41 + V_314 ) ) ;
F_18 ( V_311 , ( V_41 + V_315 ) ) ;
F_18 ( V_312 , ( V_41 + V_316 ) ) ;
F_18 ( V_308 , ( V_41 + V_288 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_33 ( & V_286 . V_121 ) ;
F_34 ( & V_286 . V_80 ) ;
return 0 ;
}
int F_91 ( T_2 V_317 , bool V_318 )
{
F_22 ( V_317 == 0 || V_317 > 0xf ) ;
return F_90 ( V_319 , V_317 , 0 , 0 ,
V_318 ? V_320 :
V_321 ) ;
}
int F_92 ( T_2 V_322 )
{
return F_90 ( V_323 , V_322 , 0 , 0 , 0 ) ;
}
int F_93 ( T_2 V_322 )
{
return F_90 ( V_324 , V_322 , 0 , 0 , 0 ) ;
}
int F_94 ( T_2 V_322 )
{
return F_90 ( V_325 , V_322 , 0 , 0 , 0 ) ;
}
int F_95 ( T_2 V_322 , T_1 V_326 )
{
return F_90 ( V_327 ,
( V_322 & V_328 ) |
( T_2 ) ( ( V_326 << 4 ) & 0xf0 ) ,
( T_2 ) ( ( V_326 >> 4 ) & 0xff ) ,
( T_2 ) ( ( V_326 >> 12 ) & 0xff ) ,
( T_2 ) ( ( V_326 >> 20 ) & 0xff ) ) ;
}
int F_96 ( T_2 V_329 , T_2 V_32 , T_2 * V_33 , T_2 V_330 )
{
int V_57 ;
if ( V_330 != 1 )
return - V_48 ;
F_32 ( & V_331 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( 0 , ( V_41 + V_332 ) ) ;
F_18 ( F_97 ( V_329 ) , ( V_41 + V_333 ) ) ;
F_18 ( V_334 , ( V_41 + V_335 ) ) ;
F_18 ( V_32 , ( V_41 + V_336 ) ) ;
F_18 ( 0 , ( V_41 + V_337 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_47 ( & V_331 . V_121 ,
F_48 ( 20000 ) ) ) {
F_40 ( L_2 ,
V_135 ) ;
V_57 = - V_124 ;
} else {
V_57 = ( ( V_331 . V_122 . V_169 == V_338 ) ? 0 : - V_124 ) ;
}
if ( ! V_57 )
* V_33 = V_331 . V_122 . V_33 ;
F_34 ( & V_331 . V_80 ) ;
return V_57 ;
}
int F_98 ( T_2 V_329 , T_2 V_32 , T_2 * V_33 , T_2 * V_35 , T_2 V_330 )
{
int V_57 ;
if ( V_330 != 1 )
return - V_48 ;
F_32 ( & V_331 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( ~ * V_35 , ( V_41 + V_332 ) ) ;
F_18 ( F_99 ( V_329 ) , ( V_41 + V_333 ) ) ;
F_18 ( V_334 , ( V_41 + V_335 ) ) ;
F_18 ( V_32 , ( V_41 + V_336 ) ) ;
F_18 ( * V_33 , ( V_41 + V_337 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_47 ( & V_331 . V_121 ,
F_48 ( 20000 ) ) ) {
F_40 ( L_2 ,
V_135 ) ;
V_57 = - V_124 ;
} else {
V_57 = ( ( V_331 . V_122 . V_169 == V_339 ) ? 0 : - V_124 ) ;
}
F_34 ( & V_331 . V_80 ) ;
return V_57 ;
}
int F_100 ( T_2 V_329 , T_2 V_32 , T_2 * V_33 , T_2 V_330 )
{
T_2 V_35 = ~ 0 ;
return F_98 ( V_329 , V_32 , V_33 , & V_35 , V_330 ) ;
}
int F_101 ( void )
{
T_1 V_36 ;
int V_204 = 0 ;
F_32 ( & V_79 . V_340 ) ;
V_36 = F_3 ( V_341 ) ;
if ( V_36 & V_342 )
goto V_73;
F_102 ( & V_343 , 1 ) ;
V_36 |= V_344 ;
F_2 ( V_36 , V_341 ) ;
F_4 ( 31 ) ;
V_36 |= V_342 ;
F_2 ( V_36 , V_341 ) ;
if ( ! F_47 ( & V_79 . V_345 ,
F_48 ( 5000 ) ) ) {
#if F_103 ( V_346 )
F_104 ( V_135 , true , true ) ;
#endif
F_105 ( L_3 ,
V_135 ) ;
V_204 = - V_347 ;
}
V_73:
F_34 ( & V_79 . V_340 ) ;
return V_204 ;
}
void F_106 ( void )
{
T_1 V_36 ;
F_32 ( & V_79 . V_340 ) ;
V_36 = F_3 ( V_341 ) ;
if ( ! ( V_36 & V_342 ) )
goto V_73;
F_2 ( ( V_36 & ~ V_342 ) ,
V_341 ) ;
if ( ! F_47 ( & V_79 . V_345 ,
F_48 ( 5000 ) ) ) {
F_105 ( L_3 ,
V_135 ) ;
}
F_102 ( & V_343 , 0 ) ;
V_73:
F_34 ( & V_79 . V_340 ) ;
}
bool F_107 ( void )
{
return ( F_108 ( & V_343 ) != 0 ) ;
}
void F_109 ( T_4 V_348 )
{
F_87 ( V_348 , ( V_41 + V_349 ) ) ;
F_2 ( 1 , V_350 ) ;
}
T_4 F_110 ( void )
{
return F_111 ( V_41 + V_349 ) ;
}
void F_112 ( void )
{
F_32 ( & V_115 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_351 , ( V_41 + V_117 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_33 ( & V_115 . V_121 ) ;
F_34 ( & V_115 . V_80 ) ;
}
static void F_113 ( void )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_18 ( V_352 , ( V_41 + V_83 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static inline void F_114 ( T_2 V_216 , T_2 V_90 )
{
F_115 ( L_4 ,
V_90 , V_216 ) ;
}
static bool F_116 ( void )
{
bool V_57 ;
T_1 V_353 ;
unsigned int V_216 ;
T_2 V_90 ;
V_90 = F_15 ( V_41 + V_354 ) ;
switch ( V_90 ) {
case V_355 :
case V_356 :
if ( F_15 ( V_41 + V_109 ) & 1 )
V_353 = F_3 ( V_41 + V_357 ) ;
else
V_353 = F_3 ( V_41 + V_358 ) ;
if ( V_353 & ( V_100 | V_101 ) )
F_117 ( & V_79 . V_345 ) ;
if ( V_353 & V_359 )
F_117 ( & V_187 . V_194 ) ;
V_353 &= V_79 . V_97 . V_98 ;
for ( V_216 = 0 ; V_216 < V_360 ; V_216 ++ ) {
if ( V_353 & V_361 [ V_216 ] )
F_118 ( F_119 ( V_362 , V_216 ) ) ;
}
V_57 = true ;
break;
default:
F_114 ( 0 , V_90 ) ;
V_57 = false ;
break;
}
F_2 ( F_24 ( 0 ) , V_363 ) ;
return V_57 ;
}
static bool F_120 ( void )
{
V_115 . V_122 . V_90 = F_15 ( V_41 + V_117 ) ;
V_115 . V_122 . V_123 = F_15 ( V_41 +
V_125 ) ;
V_115 . V_122 . V_136 = F_15 ( V_41 +
V_141 ) ;
V_115 . V_122 . V_144 = F_15 ( V_41 +
V_364 ) ;
F_2 ( F_24 ( 1 ) , V_363 ) ;
F_117 ( & V_115 . V_121 ) ;
return false ;
}
static bool F_121 ( void )
{
V_164 . V_122 . V_169 = F_15 ( V_41 + V_365 ) ;
F_2 ( F_24 ( 2 ) , V_363 ) ;
F_117 ( & V_164 . V_121 ) ;
return false ;
}
static bool F_122 ( void )
{
F_2 ( F_24 ( 3 ) , V_363 ) ;
return false ;
}
static bool F_123 ( void )
{
T_2 V_90 ;
bool V_366 = true ;
V_90 = F_15 ( V_41 + V_288 ) ;
switch ( V_90 ) {
case V_287 :
case V_296 :
case V_304 :
case V_306 :
case V_319 :
case V_323 :
case V_324 :
case V_327 :
case V_325 :
break;
default:
F_114 ( 4 , V_90 ) ;
V_366 = false ;
break;
}
F_2 ( F_24 ( 4 ) , V_363 ) ;
if ( V_366 )
F_117 ( & V_286 . V_121 ) ;
return false ;
}
static bool F_124 ( void )
{
V_331 . V_122 . V_169 = F_15 ( V_41 + V_367 ) ;
V_331 . V_122 . V_33 = F_15 ( V_41 + V_368 ) ;
F_2 ( F_24 ( 5 ) , V_363 ) ;
F_117 ( & V_331 . V_121 ) ;
return false ;
}
static bool F_125 ( void )
{
F_2 ( F_24 ( 6 ) , V_363 ) ;
return false ;
}
static bool F_126 ( void )
{
F_2 ( F_24 ( 7 ) , V_363 ) ;
return false ;
}
static T_6 F_127 ( int V_369 , void * V_370 )
{
T_1 V_58 ;
T_2 V_216 ;
T_6 V_57 ;
V_58 = ( F_3 ( V_371 ) & V_372 ) ;
if ( F_128 ( ! V_58 ) )
return V_373 ;
V_57 = V_374 ;
for ( V_216 = 0 ; V_58 ; V_216 ++ ) {
if ( V_58 & F_24 ( V_216 ) ) {
V_58 -= F_24 ( V_216 ) ;
if ( V_375 [ V_216 ] ( ) )
V_57 = V_376 ;
}
}
return V_57 ;
}
static T_6 F_129 ( int V_369 , void * V_370 )
{
F_113 () ;
return V_374 ;
}
static void F_130 ( struct V_377 * V_121 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
F_26 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static void F_131 ( struct V_378 * V_236 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_379 , V_21 ) ;
V_79 . V_97 . V_98 &= ~ V_361 [ V_236 -> V_380 ] ;
F_9 ( & V_79 . V_379 , V_21 ) ;
if ( V_236 -> V_369 != V_381 )
F_132 ( & V_79 . V_382 ) ;
}
static void F_133 ( struct V_378 * V_236 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_379 , V_21 ) ;
V_79 . V_97 . V_98 |= V_361 [ V_236 -> V_380 ] ;
F_9 ( & V_79 . V_379 , V_21 ) ;
if ( V_236 -> V_369 != V_381 )
F_132 ( & V_79 . V_382 ) ;
}
static void F_134 ( struct V_378 * V_236 )
{
}
static T_7 char * F_135 ( T_1 V_383 )
{
switch ( V_383 ) {
case V_384 :
return L_5 ;
case V_385 :
return L_6 ;
case V_386 :
return L_7 ;
case V_387 :
return L_8 ;
case V_388 :
return L_9 ;
case V_389 :
return L_10 ;
case V_390 :
return L_11 ;
case V_391 :
return L_12 ;
case V_392 :
return L_13 ;
case V_393 :
return L_14 ;
case V_394 :
return L_15 ;
case V_395 :
return L_16 ;
case V_396 :
return L_17 ;
case V_397 :
return L_18 ;
case V_398 :
return L_19 ;
case V_399 :
return L_20 ;
case V_400 :
return L_21 ;
default:
return L_22 ;
}
}
static int F_136 ( struct V_401 * V_236 , unsigned int V_402 ,
T_8 V_380 )
{
F_137 ( V_402 , & V_403 ,
V_404 ) ;
F_138 ( V_402 , V_405 ) ;
return 0 ;
}
static int F_139 ( struct V_406 * V_407 )
{
int V_1 ;
V_362 = F_140 (
V_407 , V_360 , 0 ,
& V_408 , NULL ) ;
if ( ! V_362 ) {
F_40 ( L_23 ) ;
return - V_409 ;
}
for ( V_1 = 0 ; V_1 < V_360 ; V_1 ++ )
F_141 ( V_362 , V_1 ) ;
return 0 ;
}
static void F_142 ( struct V_410 * V_411 ,
T_1 V_412 )
{
struct V_413 * V_414 ;
void T_3 * V_415 ;
T_1 V_40 ;
V_414 = F_143 ( V_411 , V_416 ,
L_24 ) ;
if ( ! V_414 ) {
F_144 ( & V_411 -> V_417 ,
L_25 ) ;
return;
}
V_415 = F_145 ( V_414 -> V_418 , F_146 ( V_414 ) ) ;
if ( ! V_415 ) {
F_144 ( & V_411 -> V_417 , L_26 ) ;
return;
}
V_40 = F_3 ( V_415 + V_412 ) ;
V_38 . V_40 . V_383 = ( V_40 & 0xFF ) ;
V_38 . V_40 . V_419 = ( V_40 >> 8 ) & 0xFF ;
V_38 . V_40 . V_420 = ( V_40 >> 16 ) & 0xFF ;
V_38 . V_40 . V_421 = ( V_40 >> 24 ) & 0xFF ;
strncpy ( V_38 . V_40 . V_422 ,
F_135 ( V_38 . V_40 . V_383 ) ,
V_423 ) ;
V_38 . V_39 = true ;
F_147 ( L_27 ,
V_38 . V_40 . V_422 ,
V_38 . V_40 . V_383 ,
V_38 . V_40 . V_419 ,
V_38 . V_40 . V_420 ,
V_38 . V_40 . V_421 ) ;
F_148 ( V_415 ) ;
}
void T_7 F_149 ( T_1 V_424 , T_1 V_330 )
{
V_26 = F_145 ( V_424 , V_330 ) ;
if ( ! V_26 )
F_40 ( L_28 , V_135 ) ;
F_150 ( & V_79 . V_80 ) ;
F_150 ( & V_79 . V_379 ) ;
F_151 ( & V_79 . V_340 ) ;
F_152 ( & V_79 . V_345 ) ;
F_151 ( & V_115 . V_80 ) ;
F_152 ( & V_115 . V_121 ) ;
V_115 . V_136 = V_119 ;
F_151 ( & V_164 . V_80 ) ;
F_152 ( & V_164 . V_121 ) ;
F_150 ( & V_164 . V_182 ) ;
F_150 ( & V_187 . V_80 ) ;
F_151 ( & V_187 . V_188 ) ;
F_152 ( & V_187 . V_194 ) ;
F_151 ( & V_286 . V_80 ) ;
F_152 ( & V_286 . V_121 ) ;
F_151 ( & V_331 . V_80 ) ;
F_152 ( & V_331 . V_121 ) ;
F_153 ( & V_79 . V_382 , F_130 ) ;
}
static void T_7 F_154 ( void )
{
T_1 V_36 ;
V_36 = F_3 ( V_425 ) ;
V_36 &= ~ ( V_426 |
V_427 ) ;
F_2 ( V_36 , ( V_425 ) ) ;
}
static void F_155 ( void )
{
if ( F_14 () ) {
V_275 [ 3 ] . V_276 = 1000000 ;
V_275 [ 3 ] . V_281 = V_428 ;
}
}
static int F_156 ( struct V_429 * V_430 ,
struct V_431 * V_432 )
{
struct V_406 * V_407 ;
struct V_413 V_433 ;
struct V_434 V_435 = {
. V_436 = L_29 ,
. V_437 = L_30 ,
. V_322 = V_438 ,
. V_439 = V_432 ,
. V_440 = sizeof( struct V_431 ) ,
. V_441 = & V_433 ,
. V_442 = 1 ,
} ;
if ( ! V_430 -> V_443 )
return - V_444 ;
F_157 (parent->of_node, np) {
if ( F_158 ( V_407 , V_435 . V_437 ) )
break;
}
if ( ! V_407 ) {
F_159 ( V_430 , L_31 ) ;
return - V_444 ;
}
F_160 ( V_407 , & V_433 , 1 ) ;
return F_161 ( V_430 , 0 , & V_435 , 1 , NULL , 0 , NULL ) ;
}
static int F_162 ( struct V_410 * V_411 )
{
struct V_406 * V_407 = V_411 -> V_417 . V_443 ;
struct V_445 * V_432 = F_163 ( & V_411 -> V_417 ) ;
int V_369 = 0 , V_446 = 0 ;
struct V_413 * V_414 ;
V_414 = F_143 ( V_411 , V_416 , L_32 ) ;
if ( ! V_414 ) {
F_144 ( & V_411 -> V_417 , L_33 ) ;
return - V_447 ;
}
V_26 = F_164 ( & V_411 -> V_417 , V_414 -> V_418 , F_146 ( V_414 ) ) ;
if ( ! V_26 ) {
F_144 ( & V_411 -> V_417 ,
L_34 ) ;
return - V_447 ;
}
F_154 () ;
F_142 ( V_411 , V_432 -> V_412 ) ;
V_414 = F_143 ( V_411 , V_416 , L_35 ) ;
if ( ! V_414 ) {
F_144 ( & V_411 -> V_417 , L_36 ) ;
return - V_447 ;
}
V_41 = F_164 ( & V_411 -> V_417 , V_414 -> V_418 ,
F_146 ( V_414 ) ) ;
F_2 ( V_372 , V_363 ) ;
V_369 = F_165 ( V_411 , 0 ) ;
if ( V_369 <= 0 ) {
F_144 ( & V_411 -> V_417 , L_37 ) ;
return - V_447 ;
}
V_446 = F_166 ( V_369 , F_127 ,
F_129 , V_448 , L_32 , NULL ) ;
if ( V_446 < 0 ) {
F_40 ( L_38 ) ;
V_446 = - V_72 ;
goto V_449;
}
F_139 ( V_407 ) ;
F_167 ( V_284 ) ;
F_155 () ;
V_446 = F_161 ( & V_411 -> V_417 , 0 , V_450 ,
F_39 ( V_450 ) , NULL , 0 , V_362 ) ;
if ( V_446 ) {
F_40 ( L_39 ) ;
return V_446 ;
}
if ( ! F_168 ( L_40 ) ) {
V_446 = F_161 ( & V_411 -> V_417 , 0 , V_451 ,
F_39 ( V_451 ) , NULL , 0 ,
V_362 ) ;
if ( V_446 ) {
F_169 ( & V_411 -> V_417 ) ;
F_40 ( L_39 ) ;
goto V_449;
}
}
V_446 = F_156 ( & V_411 -> V_417 , V_432 -> V_452 ) ;
if ( V_446 ) {
F_169 ( & V_411 -> V_417 ) ;
F_40 ( L_41 ) ;
goto V_449;
}
F_147 ( L_42 ) ;
V_449:
return V_446 ;
}
static int T_7 F_170 ( void )
{
return F_171 ( & V_453 ) ;
}
