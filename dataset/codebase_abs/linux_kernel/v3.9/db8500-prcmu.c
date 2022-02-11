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
F_2 ( V_25 , V_26 ) ;
F_2 ( V_27 , V_28 ) ;
F_2 ( V_29 , V_30 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
T_1 F_10 ( unsigned int V_31 )
{
return F_3 ( V_32 + V_31 ) ;
}
void F_11 ( unsigned int V_31 , T_1 V_33 )
{
unsigned long V_21 ;
F_7 ( & V_34 , V_21 ) ;
F_2 ( V_33 , ( V_32 + V_31 ) ) ;
F_9 ( & V_34 , V_21 ) ;
}
void F_12 ( unsigned int V_31 , T_1 V_35 , T_1 V_33 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_34 , V_21 ) ;
V_36 = F_3 ( V_32 + V_31 ) ;
V_36 = ( ( V_36 & ~ V_35 ) | ( V_33 & V_35 ) ) ;
F_2 ( V_36 , ( V_32 + V_31 ) ) ;
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
int F_26 ( void )
{
T_1 V_36 = F_3 ( V_90 ) ;
F_2 ( V_36 | V_91 ,
V_90 ) ;
F_3 ( V_90 ) ;
F_4 ( 1 ) ;
return 0 ;
}
int F_27 ( void )
{
T_1 V_36 = F_3 ( V_90 ) ;
F_2 ( V_36 & ~ V_91 , V_90 ) ;
return 0 ;
}
bool F_28 ( void )
{
T_1 V_92 ;
T_1 V_93 ;
void T_3 * V_94 = F_29 ( V_95 ) ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_96 ; V_1 ++ ) {
V_92 = F_30 ( V_94 + V_97 + V_1 * 4 ) ;
V_93 = F_30 ( V_94 + V_98 + V_1 * 4 ) ;
if ( V_92 & V_93 )
return true ;
}
return false ;
}
bool F_31 ( void )
{
T_1 V_99 , V_100 ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_96 - 1 ; V_1 ++ ) {
V_99 = F_3 ( V_101 + V_1 * 4 ) ;
V_100 = F_3 ( V_102 + V_1 * 4 ) ;
if ( V_99 & V_100 )
return true ;
}
return false ;
}
bool F_32 ( int V_103 )
{
return F_3 ( V_104 ) & V_103 ? V_105 :
V_106 ;
}
int F_33 ( void )
{
T_1 V_93 ;
void T_3 * V_94 = F_29 ( V_95 ) ;
int V_1 ;
for ( V_1 = 0 ; V_1 < V_96 - 1 ; V_1 ++ ) {
V_93 = F_30 ( V_94 +
V_98 + ( V_1 + 1 ) * 4 ) ;
F_2 ( V_93 , V_102 + V_1 * 4 ) ;
}
return 0 ;
}
static void F_34 ( void )
{
const T_2 V_107 [ 2 ] = {
V_108 ,
V_109
} ;
static T_1 V_110 ;
static T_1 V_111 ;
T_1 V_112 ;
T_1 V_113 ;
unsigned int V_1 ;
V_112 = V_79 . V_114 . V_115 | V_79 . V_114 . V_116 ;
V_112 |= ( V_117 | V_118 ) ;
V_113 = V_79 . V_114 . V_113 ;
if ( ( V_112 == V_110 ) && ( V_113 == V_111 ) )
return;
for ( V_1 = 0 ; V_1 < 2 ; V_1 ++ ) {
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_2 ( V_112 , ( V_41 + V_119 ) ) ;
F_2 ( V_113 , ( V_41 + V_120 ) ) ;
F_18 ( V_107 [ V_1 ] , ( V_41 + V_83 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
}
V_110 = V_112 ;
V_111 = V_113 ;
}
void F_35 ( T_1 V_121 )
{
unsigned long V_21 ;
T_1 V_58 ;
int V_1 ;
F_22 ( V_121 != ( V_121 & V_122 ) ) ;
for ( V_1 = 0 , V_58 = 0 ; V_1 < V_123 ; V_1 ++ ) {
if ( V_121 & F_36 ( V_1 ) )
V_58 |= V_124 [ V_1 ] ;
}
F_7 ( & V_79 . V_80 , V_21 ) ;
V_79 . V_114 . V_116 = V_58 ;
F_34 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
void F_37 ( T_1 V_113 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
V_79 . V_114 . V_113 = V_113 ;
F_34 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
void F_38 ( void T_3 * * V_125 )
{
if ( F_15 ( V_41 + V_126 ) & 1 )
* V_125 = ( V_41 + V_127 ) ;
else
* V_125 = ( V_41 + V_128 ) ;
}
int F_39 ( T_2 V_129 )
{
int V_57 ;
if ( V_129 < V_130 || V_129 > V_131 )
return - V_48 ;
V_57 = 0 ;
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_133 , ( V_41 + V_134 ) ) ;
F_18 ( V_129 , ( V_41 + V_135 ) ) ;
F_18 ( V_136 , ( V_41 + V_137 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_133 ) ||
( V_132 . V_139 . V_140 != V_129 ) )
V_57 = - V_141 ;
F_42 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_43 ( void )
{
return F_15 ( V_41 + V_142 ) ;
}
int F_44 ( void )
{
return F_15 ( V_143 ) ;
}
int F_45 ( T_2 V_129 )
{
if ( V_129 < V_144 || V_129 > V_145 )
return - V_48 ;
if ( V_146 )
F_18 ( V_129 , V_143 ) ;
return 0 ;
}
static void F_46 ( bool V_147 )
{
void T_3 * V_148 [] = {
V_149 ,
V_150
} ;
unsigned long V_21 ;
unsigned int V_1 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
for ( V_1 = 0 ; V_1 < F_47 ( V_148 ) ; V_1 ++ ) {
T_1 V_36 ;
T_1 div ;
V_36 = F_3 ( V_148 [ V_1 ] ) ;
div = ( V_36 & V_151 ) ;
if ( V_147 ) {
if ( ( div <= 1 ) || ( div > 15 ) ) {
F_48 ( L_1 ,
div , V_152 ) ;
goto V_73;
}
div <<= 1 ;
} else {
if ( div <= 2 )
goto V_73;
div >>= 1 ;
}
V_36 = ( ( V_36 & ~ V_151 ) |
( div & V_151 ) ) ;
F_2 ( V_36 , V_148 [ V_1 ] ) ;
}
V_73:
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
int F_49 ( T_2 V_129 )
{
int V_57 = 0 ;
if ( V_129 == V_132 . V_153 )
return 0 ;
F_40 ( & V_132 . V_80 ) ;
if ( V_132 . V_153 == V_154 )
F_46 ( false ) ;
if ( ( V_129 != V_155 ) && ( V_132 . V_153 != V_155 ) )
goto V_156;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_133 , ( V_41 + V_134 ) ) ;
F_18 ( V_130 , ( V_41 + V_135 ) ) ;
F_18 ( ( ( V_129 == V_154 ) ? V_157 : V_129 ) ,
( V_41 + V_137 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_133 ) ||
( V_132 . V_139 . V_153 != V_129 ) )
V_57 = - V_141 ;
V_156:
if ( ( ! V_57 && ( V_129 == V_154 ) ) ||
( V_57 && ( V_132 . V_153 == V_154 ) ) )
F_46 ( true ) ;
if ( ! V_57 )
V_132 . V_153 = V_129 ;
F_42 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_50 ( void )
{
return F_15 ( V_41 + V_158 ) ;
}
int F_51 ( bool V_147 )
{
int V_57 = 0 ;
T_2 V_107 ;
static unsigned int V_56 ;
F_40 ( & V_132 . V_80 ) ;
if ( V_147 ) {
if ( 0 != V_56 ++ )
goto V_73;
V_107 = V_159 ;
} else {
if ( V_56 == 0 ) {
V_57 = - V_141 ;
goto V_73;
} else if ( 1 != V_56 -- ) {
goto V_73;
}
V_107 = V_160 ;
}
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_107 , ( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_107 ) ||
( ( V_132 . V_139 . V_161 & F_36 ( 0 ) ) != 0 ) )
V_57 = - V_141 ;
V_73:
F_42 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_52 ( void )
{
int V_57 = 0 ;
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_162 ,
( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_162 ) ||
( ( V_132 . V_139 . V_161 & F_36 ( 0 ) ) != 0 ) )
V_57 = - V_141 ;
F_42 ( & V_132 . V_80 ) ;
return V_57 ;
}
static int F_53 ( T_2 clock , bool V_147 )
{
int V_57 = 0 ;
if ( clock == V_163 )
clock = ( V_147 ? V_164 : V_165 ) ;
else if ( clock == V_166 )
clock = ( V_147 ? V_167 : V_168 ) ;
else
return - V_48 ;
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_169 , ( V_41 + V_134 ) ) ;
F_18 ( clock , ( V_41 + V_170 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( V_132 . V_139 . V_107 != V_169 )
V_57 = - V_141 ;
F_42 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_54 ( T_4 V_171 , T_2 V_172 )
{
int V_57 = 0 ;
bool V_173 = false ;
int V_1 ;
F_22 ( V_171 >= V_174 ) ;
switch ( V_171 ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_173 = true ;
break;
}
F_22 ( V_172 > V_179 ) ;
F_22 ( V_172 == V_180 && ! V_173 ) ;
F_40 ( & V_181 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 2 ) )
F_8 () ;
for ( V_1 = 0 ; V_1 < V_174 ; V_1 ++ )
F_18 ( V_182 , ( V_41 + V_183 + V_1 ) ) ;
F_18 ( V_172 , ( V_41 + V_183 + V_171 ) ) ;
F_18 ( V_184 , ( V_41 + V_185 ) ) ;
F_2 ( F_24 ( 2 ) , V_88 ) ;
if ( ! F_55 ( & V_181 . V_138 ,
F_56 ( 20000 ) ) ) {
F_48 ( L_2 ,
V_152 ) ;
V_57 = - V_141 ;
goto V_73;
}
if ( V_181 . V_139 . V_186 != V_187 )
V_57 = - V_141 ;
V_73:
F_42 ( & V_181 . V_80 ) ;
return V_57 ;
}
void F_57 ( struct V_188 * V_189 ,
struct V_188 * V_190 )
{
T_1 V_191 ;
T_1 V_192 ;
unsigned long V_21 ;
F_22 ( ( V_189 == NULL ) || ( V_190 == NULL ) ) ;
V_191 = ( V_189 -> V_193 & 0xF ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_194 & 0xF ) ) ;
V_191 = ( ( V_191 << 8 ) | ( V_189 -> V_195 & 0xFF ) ) ;
V_191 = ( ( V_191 << 8 ) | ( V_189 -> V_196 & 0xFF ) ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_197 & 0xF ) ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_198 & 0xF ) ) ;
V_192 = ( V_190 -> V_193 & 0xF ) ;
V_192 = ( ( V_192 << 4 ) | ( V_190 -> V_194 & 0xF ) ) ;
V_192 = ( ( V_192 << 8 ) | ( V_190 -> V_195 & 0xFF ) ) ;
V_192 = ( ( V_192 << 8 ) | ( V_190 -> V_196 & 0xFF ) ) ;
V_192 = ( ( V_192 << 4 ) | ( V_190 -> V_197 & 0xF ) ) ;
V_192 = ( ( V_192 << 4 ) | ( V_190 -> V_198 & 0xF ) ) ;
F_7 ( & V_181 . V_199 , V_21 ) ;
F_2 ( V_191 , ( V_41 + V_200 ) ) ;
F_2 ( V_192 , ( V_41 + V_201 ) ) ;
V_181 . V_202 =
( ( V_189 -> V_193 == V_203 ) ||
( V_189 -> V_194 == V_203 ) ||
( V_190 -> V_193 == V_203 ) ||
( V_190 -> V_194 == V_203 ) ) ;
F_9 ( & V_181 . V_199 , V_21 ) ;
}
bool F_58 ( void )
{
return V_181 . V_202 ;
}
static int F_59 ( bool V_147 )
{
int V_57 ;
unsigned long V_21 ;
V_57 = 0 ;
F_40 ( & V_204 . V_205 ) ;
F_7 ( & V_204 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 3 ) )
F_8 () ;
F_18 ( ( V_147 ? V_206 : V_207 ) , ( V_41 + V_208 ) ) ;
F_18 ( V_209 , ( V_41 + V_210 ) ) ;
F_2 ( F_24 ( 3 ) , V_88 ) ;
F_9 ( & V_204 . V_80 , V_21 ) ;
if ( V_147 && ! F_55 ( & V_204 . V_211 ,
F_56 ( 20000 ) ) ) {
F_48 ( L_2 ,
V_152 ) ;
V_57 = - V_141 ;
}
F_42 ( & V_204 . V_205 ) ;
return V_57 ;
}
static int F_60 ( bool V_147 )
{
T_1 V_36 = ( V_212 | V_213 ) ;
if ( ! V_147 )
V_36 |= V_214 ;
F_2 ( V_36 , V_215 ) ;
return 0 ;
}
static int F_61 ( T_2 clock , bool V_147 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_216 [ clock ] . V_31 ) ;
if ( V_147 ) {
V_36 |= ( V_217 | V_216 [ clock ] . V_218 ) ;
} else {
V_216 [ clock ] . V_218 = ( V_36 & V_219 ) ;
V_36 &= ~ ( V_217 | V_219 ) ;
}
F_2 ( V_36 , V_216 [ clock ] . V_31 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
static int F_62 ( T_2 clock , bool V_147 )
{
T_1 V_36 ;
int V_220 ;
if ( V_147 ) {
V_36 = F_3 ( V_221 ) ;
F_2 ( V_36 | V_222 , V_221 ) ;
}
V_220 = F_61 ( clock , V_147 ) ;
if ( ! V_220 && ! V_147 ) {
V_36 = F_3 ( V_221 ) ;
F_2 ( V_36 & ~ V_222 , V_221 ) ;
}
return V_220 ;
}
static inline bool F_63 ( void )
{
return ( F_3 ( V_16 ) &
( V_223 |
V_224 ) ) ==
( V_223 |
V_224 ) ;
}
static int F_64 ( bool V_147 )
{
int V_57 = 0 ;
T_1 V_36 ;
F_2 ( ( V_225 |
V_226 ) , ( V_147 ?
V_5 : V_227 ) ) ;
V_36 = F_3 ( V_13 ) ;
if ( V_147 )
V_36 |= V_228 ;
else
V_36 &= ~ V_228 ;
F_2 ( V_36 , V_13 ) ;
if ( V_147 ) {
unsigned int V_1 ;
bool V_229 = F_63 () ;
for ( V_1 = 10 ; ! V_229 && ( V_1 > 0 ) ; -- V_1 ) {
F_4 ( 100 ) ;
V_229 = F_63 () ;
}
if ( V_229 ) {
F_2 ( V_230 ,
V_18 ) ;
} else {
F_2 ( ( V_225 |
V_226 ) ,
V_227 ) ;
V_36 &= ~ V_228 ;
F_2 ( V_36 , V_13 ) ;
V_57 = - V_231 ;
}
} else {
F_2 ( V_230 , V_3 ) ;
}
return V_57 ;
}
static int F_65 ( T_2 V_232 , bool V_147 )
{
T_1 V_36 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_233 [ V_232 ] . V_234 ;
V_36 |= ( ( V_147 ? V_233 [ V_232 ] . V_235 : V_236 ) <<
V_233 [ V_232 ] . V_237 ) ;
F_2 ( V_36 , V_9 ) ;
return 0 ;
}
static int F_66 ( T_2 V_232 , bool V_147 )
{
T_1 V_36 ;
V_36 = F_3 ( V_11 ) ;
V_147 ? ( V_36 |= V_238 [ V_232 ] . V_239 ) : ( V_36 &= ~ V_238 [ V_232 ] . V_239 ) ;
F_2 ( V_36 , V_11 ) ;
return 0 ;
}
int F_67 ( T_2 clock , bool V_147 )
{
if ( clock == V_240 )
return F_62 ( clock , V_147 ) ;
else if ( clock < V_241 )
return F_61 ( clock , V_147 ) ;
else if ( clock == V_242 )
return F_60 ( V_147 ) ;
else if ( ( clock == V_243 ) || ( clock == V_244 ) )
return F_65 ( ( clock - V_243 ) , V_147 ) ;
else if ( ( V_245 <= clock ) && ( clock <= V_246 ) )
return F_66 ( ( clock - V_245 ) , V_147 ) ;
else if ( clock == V_247 )
return F_64 ( V_147 ) ;
else if ( clock == V_248 )
return F_59 ( V_147 ) ;
else if ( ( clock == V_163 ) || ( clock == V_166 ) )
return F_53 ( clock , V_147 ) ;
else
return - V_48 ;
}
static unsigned long F_68 ( void T_3 * V_31 , unsigned long V_249 ,
int V_250 )
{
T_5 V_251 ;
T_1 V_36 ;
T_1 V_252 ;
T_1 div = 1 ;
V_36 = F_3 ( V_31 ) ;
V_251 = V_249 ;
V_251 *= ( ( V_36 & V_253 ) >> V_254 ) ;
V_252 = ( ( V_36 & V_255 ) >> V_256 ) ;
if ( V_252 > 1 )
div *= V_252 ;
V_252 = ( ( V_36 & V_257 ) >> V_258 ) ;
if ( V_252 > 1 )
div *= V_252 ;
if ( V_36 & V_259 )
div *= 2 ;
if ( ( V_250 == V_260 ) || ( ( V_250 == V_261 ) &&
( V_36 & V_262 ) &&
( ( V_31 == V_263 ) ||
( V_31 == V_264 ) ||
( V_31 == V_265 ) ) ) )
div *= 2 ;
( void ) F_69 ( V_251 , div ) ;
return ( unsigned long ) V_251 ;
}
static unsigned long F_70 ( T_2 clock )
{
T_1 V_36 ;
T_1 V_218 ;
unsigned long V_251 = V_266 ;
V_36 = F_3 ( V_216 [ clock ] . V_31 ) ;
if ( V_36 & V_267 ) {
if ( V_216 [ clock ] . V_268 && ( V_36 & V_269 ) )
V_251 /= 2 ;
return V_251 ;
}
V_36 |= V_216 [ clock ] . V_218 ;
V_218 = ( V_36 & V_219 ) ;
if ( V_218 == V_270 )
V_251 = F_68 ( V_263 , V_251 , V_216 [ clock ] . V_250 ) ;
else if ( V_218 == V_271 )
V_251 = F_68 ( V_272 , V_251 , V_216 [ clock ] . V_250 ) ;
else if ( V_218 == V_273 )
V_251 = F_68 ( V_265 , V_251 , V_216 [ clock ] . V_250 ) ;
else
return 0 ;
if ( ( clock == V_240 ) &&
( V_36 & V_274 ) ) {
T_5 V_57 = ( V_251 * 10 ) ;
( void ) F_69 ( V_57 , 25 ) ;
return ( unsigned long ) V_57 ;
}
V_36 &= V_151 ;
if ( V_36 )
return V_251 / V_36 ;
else
return 0 ;
}
static unsigned long F_71 ( void )
{
T_1 V_57 ;
unsigned long V_251 ;
V_57 = F_3 ( V_275 ) ;
if ( V_57 & V_276 ) {
V_251 = F_68 ( V_265 , V_266 , V_260 ) ;
if ( ! ( V_57 & V_277 ) )
V_251 /= 2 ;
V_57 = F_3 ( V_278 ) ;
V_57 &= V_151 ;
V_251 /= V_57 ;
} else {
V_251 = F_68 ( V_264 , V_266 , V_261 ) ;
}
return V_251 ;
}
static unsigned long F_72 ( T_2 V_232 )
{
T_1 V_235 ;
T_1 div = 1 ;
V_235 = F_3 ( V_9 ) ;
V_235 = ( ( V_235 & V_233 [ V_232 ] . V_234 ) >> V_233 [ V_232 ] . V_237 ) ;
if ( V_235 == V_236 )
V_235 = V_233 [ V_232 ] . V_235 ;
switch ( V_235 ) {
case V_279 :
div *= 2 ;
case V_280 :
div *= 2 ;
case V_281 :
return F_68 ( V_7 , F_70 ( V_282 ) ,
V_283 ) / div ;
default:
return 0 ;
}
}
static unsigned long F_73 ( T_2 V_232 )
{
T_1 div ;
div = F_3 ( V_11 ) ;
div = ( ( div & V_238 [ V_232 ] . V_59 ) >> ( V_238 [ V_232 ] . V_284 ) ) ;
return F_70 ( V_285 ) / F_74 ( ( T_1 ) 1 , div ) ;
}
unsigned long F_75 ( T_2 clock )
{
if ( clock < V_241 )
return F_70 ( clock ) ;
else if ( clock == V_242 )
return V_266 / 16 ;
else if ( clock == V_248 )
return V_266 ;
else if ( clock == V_163 )
return F_68 ( V_263 , V_266 , V_283 ) ;
else if ( clock == V_166 )
return F_68 ( V_272 , V_266 , V_283 ) ;
else if ( clock == V_286 )
return F_71 () ;
else if ( clock == V_287 )
return F_68 ( V_265 , V_266 , V_283 ) ;
else if ( clock == V_247 )
return F_68 ( V_7 , F_70 ( V_282 ) ,
V_283 ) ;
else if ( ( clock == V_243 ) || ( clock == V_244 ) )
return F_72 ( clock - V_243 ) ;
else if ( ( V_245 <= clock ) && ( clock <= V_246 ) )
return F_73 ( clock - V_245 ) ;
else
return 0 ;
}
static unsigned long F_76 ( T_1 V_288 , int V_250 )
{
if ( V_288 & V_267 )
return V_266 ;
V_288 &= V_219 ;
if ( V_288 == V_270 )
return F_68 ( V_263 , V_266 , V_250 ) ;
else if ( V_288 == V_271 )
return F_68 ( V_272 , V_266 , V_250 ) ;
else if ( V_288 == V_273 )
return F_68 ( V_265 , V_266 , V_250 ) ;
else
return 0 ;
}
static T_1 F_77 ( unsigned long V_249 , unsigned long V_251 )
{
T_1 div ;
div = ( V_249 / V_251 ) ;
if ( div == 0 )
return 1 ;
if ( V_251 < ( V_249 / div ) )
div ++ ;
return div ;
}
static long F_78 ( T_2 clock , unsigned long V_251 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_249 ;
long V_289 ;
V_36 = F_3 ( V_216 [ clock ] . V_31 ) ;
V_249 = F_76 ( ( V_36 | V_216 [ clock ] . V_218 ) ,
V_216 [ clock ] . V_250 ) ;
div = F_77 ( V_249 , V_251 ) ;
if ( V_36 & V_267 ) {
if ( V_216 [ clock ] . V_268 ) {
if ( div > 2 )
div = 2 ;
} else {
div = 1 ;
}
} else if ( ( clock == V_240 ) && ( div == 3 ) ) {
T_5 V_57 = ( V_249 * 10 ) ;
( void ) F_69 ( V_57 , 25 ) ;
if ( V_57 <= V_251 )
return ( unsigned long ) V_57 ;
}
V_289 = ( V_249 / F_79 ( div , ( T_1 ) 31 ) ) ;
return V_289 ;
}
static long F_80 ( unsigned long V_251 )
{
long V_290 = 0 ;
int V_1 = 0 ;
V_251 = V_251 / 1000 ;
while ( V_291 [ V_1 ] . V_292 != V_293 ) {
V_290 = V_291 [ V_1 ] . V_292 ;
if ( V_290 == V_251 )
break;
V_1 ++ ;
}
return V_290 * 1000 ;
}
static long F_81 ( unsigned long V_251 )
{
long V_289 = 0 ;
unsigned long V_249 ;
unsigned long V_294 ;
T_1 V_57 ;
V_249 = F_70 ( V_282 ) ;
V_294 = V_251 ;
for ( V_57 = 7 ; ( V_294 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_252 ;
V_252 = ( V_57 * V_251 ) ;
( void ) F_69 ( V_252 , V_249 ) ;
if ( V_252 < 6 )
V_252 = 6 ;
else if ( V_252 > 255 )
V_252 = 255 ;
V_252 *= V_249 ;
if ( ( ( 2 * V_252 ) < ( V_57 * V_295 ) ) ||
( ( V_57 * V_296 ) < ( 2 * V_252 ) ) )
continue;
( void ) F_69 ( V_252 , V_57 ) ;
if ( V_251 < V_252 ) {
if ( V_289 == 0 )
V_289 = ( long ) V_252 ;
break;
}
if ( ( V_251 - V_252 ) < V_294 ) {
V_294 = ( V_251 - V_252 ) ;
V_289 = ( long ) V_252 ;
}
}
return V_289 ;
}
static long F_82 ( unsigned long V_251 )
{
T_1 div ;
unsigned long V_249 ;
long V_289 ;
V_249 = F_68 ( V_7 , F_70 ( V_282 ) ,
V_283 ) ;
div = F_77 ( V_249 , V_251 ) ;
V_289 = ( V_249 / ( ( div > 2 ) ? 4 : div ) ) ;
return V_289 ;
}
static long F_83 ( unsigned long V_251 )
{
T_1 div ;
unsigned long V_249 ;
long V_289 ;
V_249 = F_70 ( V_285 ) ;
div = F_77 ( V_249 , V_251 ) ;
V_289 = ( V_249 / F_79 ( div , ( T_1 ) 255 ) ) ;
return V_289 ;
}
long F_84 ( T_2 clock , unsigned long V_251 )
{
if ( clock < V_241 )
return F_78 ( clock , V_251 ) ;
else if ( clock == V_286 )
return F_80 ( V_251 ) ;
else if ( clock == V_247 )
return F_81 ( V_251 ) ;
else if ( ( clock == V_243 ) || ( clock == V_244 ) )
return F_82 ( V_251 ) ;
else if ( ( V_245 <= clock ) && ( clock <= V_246 ) )
return F_83 ( V_251 ) ;
else
return ( long ) F_75 ( clock ) ;
}
static void F_85 ( T_2 clock , unsigned long V_251 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_249 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_216 [ clock ] . V_31 ) ;
V_249 = F_76 ( ( V_36 | V_216 [ clock ] . V_218 ) ,
V_216 [ clock ] . V_250 ) ;
div = F_77 ( V_249 , V_251 ) ;
if ( V_36 & V_267 ) {
if ( V_216 [ clock ] . V_268 ) {
if ( div > 1 )
V_36 |= V_269 ;
else
V_36 &= ~ V_269 ;
}
} else if ( clock == V_240 ) {
V_36 &= ~ ( V_151 |
V_274 ) ;
if ( div == 3 ) {
T_5 V_57 = ( V_249 * 10 ) ;
( void ) F_69 ( V_57 , 25 ) ;
if ( V_57 <= V_251 ) {
V_36 |= V_274 ;
div = 0 ;
}
}
V_36 |= F_79 ( div , ( T_1 ) 31 ) ;
} else {
V_36 &= ~ V_151 ;
V_36 |= F_79 ( div , ( T_1 ) 31 ) ;
}
F_2 ( V_36 , V_216 [ clock ] . V_31 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
static int F_86 ( unsigned long V_251 )
{
int V_1 = 0 ;
V_251 = V_251 / 1000 ;
while ( V_291 [ V_1 ] . V_292 != V_293 ) {
if ( V_291 [ V_1 ] . V_292 == V_251 )
break;
V_1 ++ ;
}
if ( V_291 [ V_1 ] . V_292 != V_251 )
return - V_48 ;
return F_39 ( V_291 [ V_1 ] . V_297 ) ;
}
static int F_87 ( unsigned long V_251 )
{
unsigned long V_249 ;
unsigned long V_294 ;
T_1 V_298 = 0 ;
T_1 V_57 ;
V_249 = F_70 ( V_282 ) ;
V_294 = V_251 ;
for ( V_57 = 7 ; ( V_294 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_252 ;
T_5 V_299 ;
V_252 = ( V_57 * V_251 ) ;
( void ) F_69 ( V_252 , V_249 ) ;
if ( V_252 < 6 )
V_252 = 6 ;
else if ( V_252 > 255 )
V_252 = 255 ;
V_299 = ( V_252 * V_249 ) ;
if ( ( ( 2 * V_299 ) < ( V_57 * V_295 ) ) ||
( ( V_57 * V_296 ) < ( 2 * V_299 ) ) )
continue;
( void ) F_69 ( V_299 , V_57 ) ;
if ( V_251 < V_299 ) {
if ( V_298 == 0 )
V_298 = ( ( ( T_1 ) V_252 << V_254 ) |
( V_57 << V_258 ) ) ;
break;
}
if ( ( V_251 - V_299 ) < V_294 ) {
V_294 = ( V_251 - V_299 ) ;
V_298 = ( ( ( T_1 ) V_252 << V_254 ) |
( V_57 << V_258 ) ) ;
}
}
if ( V_298 == 0 )
return - V_48 ;
V_298 |= ( 1 << V_256 ) ;
F_2 ( V_298 , V_7 ) ;
return 0 ;
}
static void F_88 ( T_2 V_232 , unsigned long V_251 )
{
T_1 V_36 ;
T_1 div ;
div = F_77 ( F_68 ( V_7 ,
F_70 ( V_282 ) , V_283 ) , V_251 ) ;
V_233 [ V_232 ] . V_235 = ( div == 1 ) ? V_281 :
( div == 2 ) ? V_280 :
V_279 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_233 [ V_232 ] . V_234 ;
V_36 |= ( V_233 [ V_232 ] . V_235 << V_233 [ V_232 ] . V_237 ) ;
F_2 ( V_36 , V_9 ) ;
}
static void F_89 ( T_2 V_232 , unsigned long V_251 )
{
T_1 V_36 ;
T_1 div ;
div = F_77 ( F_70 ( V_285 ) , V_251 ) ;
V_36 = F_3 ( V_11 ) ;
V_36 &= ~ V_238 [ V_232 ] . V_59 ;
V_36 |= ( F_79 ( div , ( T_1 ) 255 ) << V_238 [ V_232 ] . V_284 ) ;
F_2 ( V_36 , V_11 ) ;
}
int F_90 ( T_2 clock , unsigned long V_251 )
{
if ( clock < V_241 )
F_85 ( clock , V_251 ) ;
else if ( clock == V_286 )
return F_86 ( V_251 ) ;
else if ( clock == V_247 )
return F_87 ( V_251 ) ;
else if ( ( clock == V_243 ) || ( clock == V_244 ) )
F_88 ( ( clock - V_243 ) , V_251 ) ;
else if ( ( V_245 <= clock ) && ( clock <= V_246 ) )
F_89 ( ( clock - V_245 ) , V_251 ) ;
return 0 ;
}
int F_91 ( T_2 V_74 )
{
if ( ( V_74 > V_300 ) ||
( V_74 < V_301 ) )
return - V_48 ;
F_40 ( & V_302 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_303 , ( V_41 + V_304 ) ) ;
F_18 ( ( ( V_305 << 4 ) | V_306 ) ,
( V_41 + V_307 ) ) ;
F_18 ( V_306 ,
( V_41 + V_308 ) ) ;
F_18 ( V_74 , ( V_41 + V_309 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_302 . V_138 ) ;
F_42 ( & V_302 . V_80 ) ;
return 0 ;
}
int F_92 ( T_2 V_310 )
{
F_40 ( & V_302 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_310 , ( V_41 + V_311 ) ) ;
F_18 ( V_312 , ( V_41 + V_304 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_302 . V_138 ) ;
F_42 ( & V_302 . V_80 ) ;
return 0 ;
}
int F_93 ( T_2 V_313 , T_2 V_314 )
{
F_40 ( & V_302 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_313 , ( V_41 + V_315 ) ) ;
F_18 ( V_314 , ( V_41 + V_316 ) ) ;
F_18 ( ( V_317 | V_318 ) ,
( V_41 + V_319 ) ) ;
F_18 ( V_320 , ( V_41 + V_304 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_302 . V_138 ) ;
F_42 ( & V_302 . V_80 ) ;
return 0 ;
}
static int F_94 ( T_4 V_36 )
{
F_40 ( & V_302 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_95 ( V_36 , ( V_41 + V_321 ) ) ;
F_18 ( V_322 , ( V_41 + V_304 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_302 . V_138 ) ;
F_42 ( & V_302 . V_80 ) ;
return 0 ;
}
int F_96 ( T_4 V_323 )
{
if ( V_323 == 0xFFFF )
return - V_48 ;
return F_94 ( V_323 ) ;
}
int F_97 ( void )
{
return F_94 ( 0xFFFF ) ;
}
static int F_98 ( T_2 V_324 , T_2 V_325 , T_2 V_326 , T_2 V_327 , T_2 V_328 )
{
F_40 ( & V_302 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_325 , ( V_41 + V_329 ) ) ;
F_18 ( V_326 , ( V_41 + V_330 ) ) ;
F_18 ( V_327 , ( V_41 + V_331 ) ) ;
F_18 ( V_328 , ( V_41 + V_332 ) ) ;
F_18 ( V_324 , ( V_41 + V_304 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_302 . V_138 ) ;
F_42 ( & V_302 . V_80 ) ;
return 0 ;
}
int F_99 ( T_2 V_333 , bool V_334 )
{
F_22 ( V_333 == 0 || V_333 > 0xf ) ;
return F_98 ( V_335 , V_333 , 0 , 0 ,
V_334 ? V_336 :
V_337 ) ;
}
int F_100 ( T_2 V_338 )
{
return F_98 ( V_339 , V_338 , 0 , 0 , 0 ) ;
}
int F_101 ( T_2 V_338 )
{
return F_98 ( V_340 , V_338 , 0 , 0 , 0 ) ;
}
int F_102 ( T_2 V_338 )
{
return F_98 ( V_341 , V_338 , 0 , 0 , 0 ) ;
}
int F_103 ( T_2 V_338 , T_1 V_342 )
{
return F_98 ( V_343 ,
( V_338 & V_344 ) |
( T_2 ) ( ( V_342 << 4 ) & 0xf0 ) ,
( T_2 ) ( ( V_342 >> 4 ) & 0xff ) ,
( T_2 ) ( ( V_342 >> 12 ) & 0xff ) ,
( T_2 ) ( ( V_342 >> 20 ) & 0xff ) ) ;
}
int F_104 ( T_2 V_345 , T_2 V_31 , T_2 * V_33 , T_2 V_346 )
{
int V_57 ;
if ( V_346 != 1 )
return - V_48 ;
F_40 ( & V_347 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( 0 , ( V_41 + V_348 ) ) ;
F_18 ( F_105 ( V_345 ) , ( V_41 + V_349 ) ) ;
F_18 ( V_350 , ( V_41 + V_351 ) ) ;
F_18 ( V_31 , ( V_41 + V_352 ) ) ;
F_18 ( 0 , ( V_41 + V_353 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_55 ( & V_347 . V_138 ,
F_56 ( 20000 ) ) ) {
F_48 ( L_2 ,
V_152 ) ;
V_57 = - V_141 ;
} else {
V_57 = ( ( V_347 . V_139 . V_186 == V_354 ) ? 0 : - V_141 ) ;
}
if ( ! V_57 )
* V_33 = V_347 . V_139 . V_33 ;
F_42 ( & V_347 . V_80 ) ;
return V_57 ;
}
int F_106 ( T_2 V_345 , T_2 V_31 , T_2 * V_33 , T_2 * V_35 , T_2 V_346 )
{
int V_57 ;
if ( V_346 != 1 )
return - V_48 ;
F_40 ( & V_347 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( ~ * V_35 , ( V_41 + V_348 ) ) ;
F_18 ( F_107 ( V_345 ) , ( V_41 + V_349 ) ) ;
F_18 ( V_350 , ( V_41 + V_351 ) ) ;
F_18 ( V_31 , ( V_41 + V_352 ) ) ;
F_18 ( * V_33 , ( V_41 + V_353 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_55 ( & V_347 . V_138 ,
F_56 ( 20000 ) ) ) {
F_48 ( L_2 ,
V_152 ) ;
V_57 = - V_141 ;
} else {
V_57 = ( ( V_347 . V_139 . V_186 == V_355 ) ? 0 : - V_141 ) ;
}
F_42 ( & V_347 . V_80 ) ;
return V_57 ;
}
int F_108 ( T_2 V_345 , T_2 V_31 , T_2 * V_33 , T_2 V_346 )
{
T_2 V_35 = ~ 0 ;
return F_106 ( V_345 , V_31 , V_33 , & V_35 , V_346 ) ;
}
int F_109 ( void )
{
T_1 V_36 ;
int V_220 = 0 ;
F_40 ( & V_79 . V_356 ) ;
V_36 = F_3 ( V_357 ) ;
if ( V_36 & V_358 )
goto V_73;
F_110 ( & V_359 , 1 ) ;
V_36 |= V_360 ;
F_2 ( V_36 , V_357 ) ;
F_4 ( 31 ) ;
V_36 |= V_358 ;
F_2 ( V_36 , V_357 ) ;
if ( ! F_55 ( & V_79 . V_361 ,
F_56 ( 5000 ) ) ) {
#if F_111 ( V_362 )
F_112 ( V_152 , true , true ) ;
#endif
F_113 ( L_3 ,
V_152 ) ;
V_220 = - V_363 ;
}
V_73:
F_42 ( & V_79 . V_356 ) ;
return V_220 ;
}
void F_114 ()
{
T_1 V_36 ;
F_40 ( & V_79 . V_356 ) ;
V_36 = F_3 ( V_357 ) ;
if ( ! ( V_36 & V_358 ) )
goto V_73;
F_2 ( ( V_36 & ~ V_358 ) ,
V_357 ) ;
if ( ! F_55 ( & V_79 . V_361 ,
F_56 ( 5000 ) ) ) {
F_113 ( L_3 ,
V_152 ) ;
}
F_110 ( & V_359 , 0 ) ;
V_73:
F_42 ( & V_79 . V_356 ) ;
}
bool F_115 ( void )
{
return ( F_116 ( & V_359 ) != 0 ) ;
}
void F_117 ( T_4 V_364 )
{
F_95 ( V_364 , ( V_41 + V_365 ) ) ;
F_2 ( 1 , V_366 ) ;
}
T_4 F_118 ( void )
{
return F_119 ( V_41 + V_365 ) ;
}
void F_120 ( void )
{
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_367 , ( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
F_42 ( & V_132 . V_80 ) ;
}
static void F_121 ( void )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_18 ( V_368 , ( V_41 + V_83 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static inline void F_122 ( T_2 V_232 , T_2 V_107 )
{
F_123 ( L_4 ,
V_107 , V_232 ) ;
}
static bool F_124 ( void )
{
bool V_57 ;
T_1 V_369 ;
unsigned int V_232 ;
T_2 V_107 ;
V_107 = F_15 ( V_41 + V_370 ) ;
switch ( V_107 ) {
case V_371 :
case V_372 :
if ( F_15 ( V_41 + V_126 ) & 1 )
V_369 = F_3 ( V_41 + V_373 ) ;
else
V_369 = F_3 ( V_41 + V_374 ) ;
if ( V_369 & ( V_117 | V_118 ) )
F_125 ( & V_79 . V_361 ) ;
if ( V_369 & V_375 )
F_125 ( & V_204 . V_211 ) ;
V_369 &= V_79 . V_114 . V_115 ;
for ( V_232 = 0 ; V_232 < V_376 ; V_232 ++ ) {
if ( V_369 & V_377 [ V_232 ] )
F_126 ( F_127 ( V_378 , V_232 ) ) ;
}
V_57 = true ;
break;
default:
F_122 ( 0 , V_107 ) ;
V_57 = false ;
break;
}
F_2 ( F_24 ( 0 ) , V_379 ) ;
return V_57 ;
}
static bool F_128 ( void )
{
V_132 . V_139 . V_107 = F_15 ( V_41 + V_134 ) ;
V_132 . V_139 . V_140 = F_15 ( V_41 +
V_142 ) ;
V_132 . V_139 . V_153 = F_15 ( V_41 +
V_158 ) ;
V_132 . V_139 . V_161 = F_15 ( V_41 +
V_380 ) ;
F_2 ( F_24 ( 1 ) , V_379 ) ;
F_125 ( & V_132 . V_138 ) ;
return false ;
}
static bool F_129 ( void )
{
V_181 . V_139 . V_186 = F_15 ( V_41 + V_381 ) ;
F_2 ( F_24 ( 2 ) , V_379 ) ;
F_125 ( & V_181 . V_138 ) ;
return false ;
}
static bool F_130 ( void )
{
F_2 ( F_24 ( 3 ) , V_379 ) ;
return false ;
}
static bool F_131 ( void )
{
T_2 V_107 ;
bool V_382 = true ;
V_107 = F_15 ( V_41 + V_304 ) ;
switch ( V_107 ) {
case V_303 :
case V_312 :
case V_320 :
case V_322 :
case V_335 :
case V_339 :
case V_340 :
case V_343 :
case V_341 :
break;
default:
F_122 ( 4 , V_107 ) ;
V_382 = false ;
break;
}
F_2 ( F_24 ( 4 ) , V_379 ) ;
if ( V_382 )
F_125 ( & V_302 . V_138 ) ;
return false ;
}
static bool F_132 ( void )
{
V_347 . V_139 . V_186 = F_15 ( V_41 + V_383 ) ;
V_347 . V_139 . V_33 = F_15 ( V_41 + V_384 ) ;
F_2 ( F_24 ( 5 ) , V_379 ) ;
F_125 ( & V_347 . V_138 ) ;
return false ;
}
static bool F_133 ( void )
{
F_2 ( F_24 ( 6 ) , V_379 ) ;
return false ;
}
static bool F_134 ( void )
{
F_2 ( F_24 ( 7 ) , V_379 ) ;
return false ;
}
static T_6 F_135 ( int V_385 , void * V_386 )
{
T_1 V_58 ;
T_2 V_232 ;
T_6 V_57 ;
V_58 = ( F_3 ( V_387 ) & V_388 ) ;
if ( F_136 ( ! V_58 ) )
return V_389 ;
V_57 = V_390 ;
for ( V_232 = 0 ; V_58 ; V_232 ++ ) {
if ( V_58 & F_24 ( V_232 ) ) {
V_58 -= F_24 ( V_232 ) ;
if ( V_391 [ V_232 ] ( ) )
V_57 = V_392 ;
}
}
return V_57 ;
}
static T_6 F_137 ( int V_385 , void * V_386 )
{
F_121 () ;
return V_390 ;
}
static void F_138 ( struct V_393 * V_138 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
F_34 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static void F_139 ( struct V_394 * V_252 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_395 , V_21 ) ;
V_79 . V_114 . V_115 &= ~ V_377 [ V_252 -> V_396 ] ;
F_9 ( & V_79 . V_395 , V_21 ) ;
if ( V_252 -> V_385 != V_397 )
F_140 ( & V_79 . V_398 ) ;
}
static void F_141 ( struct V_394 * V_252 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_395 , V_21 ) ;
V_79 . V_114 . V_115 |= V_377 [ V_252 -> V_396 ] ;
F_9 ( & V_79 . V_395 , V_21 ) ;
if ( V_252 -> V_385 != V_397 )
F_140 ( & V_79 . V_398 ) ;
}
static void F_142 ( struct V_394 * V_252 )
{
}
static T_7 char * F_143 ( T_1 V_399 )
{
switch ( V_399 ) {
case V_400 :
return L_5 ;
case V_401 :
return L_6 ;
case V_402 :
return L_7 ;
case V_403 :
return L_8 ;
case V_404 :
return L_9 ;
case V_405 :
return L_10 ;
case V_406 :
return L_11 ;
case V_407 :
return L_12 ;
case V_408 :
return L_13 ;
case V_409 :
return L_14 ;
case V_410 :
return L_15 ;
case V_411 :
return L_16 ;
case V_412 :
return L_17 ;
case V_413 :
return L_18 ;
case V_414 :
return L_19 ;
case V_415 :
return L_20 ;
case V_416 :
return L_21 ;
default:
return L_22 ;
}
}
static int F_144 ( struct V_417 * V_252 , unsigned int V_418 ,
T_8 V_396 )
{
F_145 ( V_418 , & V_419 ,
V_420 ) ;
F_146 ( V_418 , V_421 ) ;
return 0 ;
}
static int F_147 ( struct V_422 * V_423 )
{
int V_424 = 0 ;
int V_1 ;
if ( ! V_423 )
V_424 = V_425 ;
V_378 = F_148 (
V_423 , V_376 , V_424 ,
& V_426 , NULL ) ;
if ( ! V_378 ) {
F_48 ( L_23 ) ;
return - V_427 ;
}
for ( V_1 = 0 ; V_1 < V_376 ; V_1 ++ )
F_149 ( V_378 , V_1 ) ;
return 0 ;
}
static void F_150 ( struct V_428 * V_429 ,
T_1 V_430 )
{
struct V_431 * V_432 ;
void T_3 * V_433 ;
V_432 = F_151 ( V_429 , V_434 ,
L_24 ) ;
if ( ! V_432 ) {
F_152 ( & V_429 -> V_435 ,
L_25 ) ;
return;
}
V_433 = F_153 ( V_432 -> V_436 , F_154 ( V_432 ) ) ;
if ( V_433 != NULL ) {
T_1 V_40 ;
V_40 = F_3 ( V_433 + V_430 ) ;
V_38 . V_40 . V_399 = ( V_40 & 0xFF ) ;
V_38 . V_40 . V_437 = ( V_40 >> 8 ) & 0xFF ;
V_38 . V_40 . V_438 = ( V_40 >> 16 ) & 0xFF ;
V_38 . V_40 . V_439 = ( V_40 >> 24 ) & 0xFF ;
strncpy ( V_38 . V_40 . V_440 ,
F_143 ( V_38 . V_40 . V_399 ) ,
V_441 ) ;
V_38 . V_39 = true ;
F_155 ( L_26 ,
V_38 . V_40 . V_440 ,
V_38 . V_40 . V_399 ,
V_38 . V_40 . V_437 ,
V_38 . V_40 . V_438 ,
V_38 . V_40 . V_439 ) ;
F_156 ( V_433 ) ;
}
}
void T_7 F_157 ( void )
{
F_158 ( & V_79 . V_80 ) ;
F_158 ( & V_79 . V_395 ) ;
F_159 ( & V_79 . V_356 ) ;
F_160 ( & V_79 . V_361 ) ;
F_159 ( & V_132 . V_80 ) ;
F_160 ( & V_132 . V_138 ) ;
V_132 . V_153 = V_136 ;
F_159 ( & V_181 . V_80 ) ;
F_160 ( & V_181 . V_138 ) ;
F_158 ( & V_181 . V_199 ) ;
F_158 ( & V_204 . V_80 ) ;
F_159 ( & V_204 . V_205 ) ;
F_160 ( & V_204 . V_211 ) ;
F_159 ( & V_302 . V_80 ) ;
F_160 ( & V_302 . V_138 ) ;
F_159 ( & V_347 . V_80 ) ;
F_160 ( & V_347 . V_138 ) ;
F_161 ( & V_79 . V_398 , F_138 ) ;
}
static void T_7 F_162 ( void )
{
T_1 V_36 ;
V_36 = F_3 ( V_442 ) ;
V_36 &= ~ ( V_443 |
V_444 ) ;
F_2 ( V_36 , ( V_442 ) ) ;
}
static void F_163 ( void )
{
if ( F_14 () ) {
V_291 [ 3 ] . V_292 = 1000000 ;
V_291 [ 3 ] . V_297 = V_445 ;
}
}
static int F_164 ( struct V_428 * V_429 )
{
struct V_422 * V_423 = V_429 -> V_435 . V_446 ;
struct V_447 * V_448 = F_165 ( & V_429 -> V_435 ) ;
int V_385 = 0 , V_449 = 0 , V_1 ;
struct V_431 * V_432 ;
F_162 () ;
F_150 ( V_429 , V_448 -> V_430 ) ;
V_432 = F_151 ( V_429 , V_434 , L_27 ) ;
if ( ! V_432 ) {
F_152 ( & V_429 -> V_435 , L_28 ) ;
return - V_450 ;
}
V_41 = F_166 ( & V_429 -> V_435 , V_432 -> V_436 ,
F_154 ( V_432 ) ) ;
F_2 ( V_388 , V_379 ) ;
V_385 = F_167 ( V_429 , 0 ) ;
if ( V_385 <= 0 ) {
F_152 ( & V_429 -> V_435 , L_29 ) ;
return - V_450 ;
}
V_449 = F_168 ( V_385 , F_135 ,
F_137 , V_451 , L_30 , NULL ) ;
if ( V_449 < 0 ) {
F_48 ( L_31 ) ;
V_449 = - V_72 ;
goto V_452;
}
F_147 ( V_423 ) ;
for ( V_1 = 0 ; V_1 < F_47 ( V_453 ) ; V_1 ++ ) {
if ( ! strcmp ( V_453 [ V_1 ] . V_454 , L_32 ) ) {
V_453 [ V_1 ] . V_455 = V_448 -> V_456 ;
V_453 [ V_1 ] . V_457 = sizeof( struct V_458 ) ;
}
}
F_169 ( V_300 ) ;
F_163 () ;
V_449 = F_170 ( & V_429 -> V_435 , 0 , V_453 ,
F_47 ( V_453 ) , NULL , 0 , NULL ) ;
if ( V_449 ) {
F_48 ( L_33 ) ;
return V_449 ;
}
F_155 ( L_34 ) ;
V_452:
return V_449 ;
}
static int T_7 F_171 ( void )
{
return F_172 ( & V_459 ) ;
}
