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
F_42 () ;
F_43 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_44 ( void )
{
return F_15 ( V_41 + V_142 ) ;
}
int F_45 ( void )
{
return F_15 ( V_143 ) ;
}
int F_46 ( T_2 V_129 )
{
if ( V_129 < V_144 || V_129 > V_145 )
return - V_48 ;
if ( F_47 () && ! F_48 () )
F_18 ( V_129 , V_143 ) ;
return 0 ;
}
static void F_49 ( bool V_146 )
{
void T_3 * V_147 [] = {
V_148 ,
V_149
} ;
unsigned long V_21 ;
unsigned int V_1 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
for ( V_1 = 0 ; V_1 < F_50 ( V_147 ) ; V_1 ++ ) {
T_1 V_36 ;
T_1 div ;
V_36 = F_3 ( V_147 [ V_1 ] ) ;
div = ( V_36 & V_150 ) ;
if ( V_146 ) {
if ( ( div <= 1 ) || ( div > 15 ) ) {
F_51 ( L_1 ,
div , V_151 ) ;
goto V_73;
}
div <<= 1 ;
} else {
if ( div <= 2 )
goto V_73;
div >>= 1 ;
}
V_36 = ( ( V_36 & ~ V_150 ) |
( div & V_150 ) ) ;
F_2 ( V_36 , V_147 [ V_1 ] ) ;
}
V_73:
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
int F_52 ( T_2 V_129 )
{
int V_57 = 0 ;
if ( V_129 == V_132 . V_152 )
return 0 ;
F_40 ( & V_132 . V_80 ) ;
if ( V_132 . V_152 == V_153 )
F_49 ( false ) ;
if ( ( V_129 != V_154 ) && ( V_132 . V_152 != V_154 ) )
goto V_155;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_133 , ( V_41 + V_134 ) ) ;
F_18 ( V_130 , ( V_41 + V_135 ) ) ;
F_18 ( ( ( V_129 == V_153 ) ? V_156 : V_129 ) ,
( V_41 + V_137 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_133 ) ||
( V_132 . V_139 . V_152 != V_129 ) )
V_57 = - V_141 ;
V_155:
if ( ( ! V_57 && ( V_129 == V_153 ) ) ||
( V_57 && ( V_132 . V_152 == V_153 ) ) )
F_49 ( true ) ;
if ( ! V_57 )
V_132 . V_152 = V_129 ;
F_43 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_53 ( void )
{
return F_15 ( V_41 + V_157 ) ;
}
int F_54 ( bool V_146 )
{
int V_57 = 0 ;
T_2 V_107 ;
static unsigned int V_56 ;
F_40 ( & V_132 . V_80 ) ;
if ( V_146 ) {
if ( 0 != V_56 ++ )
goto V_73;
V_107 = V_158 ;
} else {
if ( V_56 == 0 ) {
V_57 = - V_141 ;
goto V_73;
} else if ( 1 != V_56 -- ) {
goto V_73;
}
V_107 = V_159 ;
}
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_107 , ( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_107 ) ||
( ( V_132 . V_139 . V_160 & F_36 ( 0 ) ) != 0 ) )
V_57 = - V_141 ;
V_73:
F_43 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_55 ( void )
{
int V_57 = 0 ;
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_161 ,
( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( ( V_132 . V_139 . V_107 != V_161 ) ||
( ( V_132 . V_139 . V_160 & F_36 ( 0 ) ) != 0 ) )
V_57 = - V_141 ;
F_43 ( & V_132 . V_80 ) ;
return V_57 ;
}
static int F_56 ( T_2 clock , bool V_146 )
{
int V_57 = 0 ;
if ( clock == V_162 )
clock = ( V_146 ? V_163 : V_164 ) ;
else if ( clock == V_165 )
clock = ( V_146 ? V_166 : V_167 ) ;
else
return - V_48 ;
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_168 , ( V_41 + V_134 ) ) ;
F_18 ( clock , ( V_41 + V_169 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
if ( V_132 . V_139 . V_107 != V_168 )
V_57 = - V_141 ;
F_43 ( & V_132 . V_80 ) ;
return V_57 ;
}
int F_57 ( T_4 V_170 , T_2 V_171 )
{
int V_57 = 0 ;
bool V_172 = false ;
int V_1 ;
F_22 ( V_170 >= V_173 ) ;
switch ( V_170 ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
V_172 = true ;
break;
}
F_22 ( V_171 > V_178 ) ;
F_22 ( V_171 == V_179 && ! V_172 ) ;
F_40 ( & V_180 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 2 ) )
F_8 () ;
for ( V_1 = 0 ; V_1 < V_173 ; V_1 ++ )
F_18 ( V_181 , ( V_41 + V_182 + V_1 ) ) ;
F_18 ( V_171 , ( V_41 + V_182 + V_170 ) ) ;
F_18 ( V_183 , ( V_41 + V_184 ) ) ;
F_2 ( F_24 ( 2 ) , V_88 ) ;
if ( ! F_58 ( & V_180 . V_138 ,
F_59 ( 20000 ) ) ) {
F_51 ( L_2 ,
V_151 ) ;
V_57 = - V_141 ;
goto V_73;
}
if ( V_180 . V_139 . V_185 != V_186 )
V_57 = - V_141 ;
V_73:
F_43 ( & V_180 . V_80 ) ;
return V_57 ;
}
void F_60 ( struct V_187 * V_188 ,
struct V_187 * V_189 )
{
T_1 V_190 ;
T_1 V_191 ;
unsigned long V_21 ;
F_22 ( ( V_188 == NULL ) || ( V_189 == NULL ) ) ;
V_190 = ( V_188 -> V_192 & 0xF ) ;
V_190 = ( ( V_190 << 4 ) | ( V_188 -> V_193 & 0xF ) ) ;
V_190 = ( ( V_190 << 8 ) | ( V_188 -> V_194 & 0xFF ) ) ;
V_190 = ( ( V_190 << 8 ) | ( V_188 -> V_195 & 0xFF ) ) ;
V_190 = ( ( V_190 << 4 ) | ( V_188 -> V_196 & 0xF ) ) ;
V_190 = ( ( V_190 << 4 ) | ( V_188 -> V_197 & 0xF ) ) ;
V_191 = ( V_189 -> V_192 & 0xF ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_193 & 0xF ) ) ;
V_191 = ( ( V_191 << 8 ) | ( V_189 -> V_194 & 0xFF ) ) ;
V_191 = ( ( V_191 << 8 ) | ( V_189 -> V_195 & 0xFF ) ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_196 & 0xF ) ) ;
V_191 = ( ( V_191 << 4 ) | ( V_189 -> V_197 & 0xF ) ) ;
F_7 ( & V_180 . V_198 , V_21 ) ;
F_2 ( V_190 , ( V_41 + V_199 ) ) ;
F_2 ( V_191 , ( V_41 + V_200 ) ) ;
V_180 . V_201 =
( ( V_188 -> V_192 == V_202 ) ||
( V_188 -> V_193 == V_202 ) ||
( V_189 -> V_192 == V_202 ) ||
( V_189 -> V_193 == V_202 ) ) ;
F_9 ( & V_180 . V_198 , V_21 ) ;
}
bool F_61 ( void )
{
return V_180 . V_201 ;
}
static int F_62 ( bool V_146 )
{
int V_57 ;
unsigned long V_21 ;
V_57 = 0 ;
F_40 ( & V_203 . V_204 ) ;
F_7 ( & V_203 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 3 ) )
F_8 () ;
F_18 ( ( V_146 ? V_205 : V_206 ) , ( V_41 + V_207 ) ) ;
F_18 ( V_208 , ( V_41 + V_209 ) ) ;
F_2 ( F_24 ( 3 ) , V_88 ) ;
F_9 ( & V_203 . V_80 , V_21 ) ;
if ( V_146 && ! F_58 ( & V_203 . V_210 ,
F_59 ( 20000 ) ) ) {
F_51 ( L_2 ,
V_151 ) ;
V_57 = - V_141 ;
}
F_43 ( & V_203 . V_204 ) ;
return V_57 ;
}
static int F_63 ( bool V_146 )
{
T_1 V_36 = ( V_211 | V_212 ) ;
if ( ! V_146 )
V_36 |= V_213 ;
F_2 ( V_36 , V_214 ) ;
return 0 ;
}
static int F_64 ( T_2 clock , bool V_146 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_215 [ clock ] . V_31 ) ;
if ( V_146 ) {
V_36 |= ( V_216 | V_215 [ clock ] . V_217 ) ;
} else {
V_215 [ clock ] . V_217 = ( V_36 & V_218 ) ;
V_36 &= ~ ( V_216 | V_218 ) ;
}
F_2 ( V_36 , V_215 [ clock ] . V_31 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
static int F_65 ( T_2 clock , bool V_146 )
{
T_1 V_36 ;
int V_219 ;
if ( V_146 ) {
V_36 = F_3 ( V_220 ) ;
F_2 ( V_36 | V_221 , V_220 ) ;
}
V_219 = F_64 ( clock , V_146 ) ;
if ( ! V_219 && ! V_146 ) {
V_36 = F_3 ( V_220 ) ;
F_2 ( V_36 & ~ V_221 , V_220 ) ;
}
return V_219 ;
}
static inline bool F_66 ( void )
{
return ( F_3 ( V_16 ) &
( V_222 |
V_223 ) ) ==
( V_222 |
V_223 ) ;
}
static int F_67 ( bool V_146 )
{
int V_57 = 0 ;
T_1 V_36 ;
F_2 ( ( V_224 |
V_225 ) , ( V_146 ?
V_5 : V_226 ) ) ;
V_36 = F_3 ( V_13 ) ;
if ( V_146 )
V_36 |= V_227 ;
else
V_36 &= ~ V_227 ;
F_2 ( V_36 , V_13 ) ;
if ( V_146 ) {
unsigned int V_1 ;
bool V_228 = F_66 () ;
for ( V_1 = 10 ; ! V_228 && ( V_1 > 0 ) ; -- V_1 ) {
F_4 ( 100 ) ;
V_228 = F_66 () ;
}
if ( V_228 ) {
F_2 ( V_229 ,
V_18 ) ;
} else {
F_2 ( ( V_224 |
V_225 ) ,
V_226 ) ;
V_36 &= ~ V_227 ;
F_2 ( V_36 , V_13 ) ;
V_57 = - V_230 ;
}
} else {
F_2 ( V_229 , V_3 ) ;
}
return V_57 ;
}
static int F_68 ( T_2 V_231 , bool V_146 )
{
T_1 V_36 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_232 [ V_231 ] . V_233 ;
V_36 |= ( ( V_146 ? V_232 [ V_231 ] . V_234 : V_235 ) <<
V_232 [ V_231 ] . V_236 ) ;
F_2 ( V_36 , V_9 ) ;
return 0 ;
}
static int F_69 ( T_2 V_231 , bool V_146 )
{
T_1 V_36 ;
V_36 = F_3 ( V_11 ) ;
V_146 ? ( V_36 |= V_237 [ V_231 ] . V_238 ) : ( V_36 &= ~ V_237 [ V_231 ] . V_238 ) ;
F_2 ( V_36 , V_11 ) ;
return 0 ;
}
int F_70 ( T_2 clock , bool V_146 )
{
if ( clock == V_239 )
return F_65 ( clock , V_146 ) ;
else if ( clock < V_240 )
return F_64 ( clock , V_146 ) ;
else if ( clock == V_241 )
return F_63 ( V_146 ) ;
else if ( ( clock == V_242 ) || ( clock == V_243 ) )
return F_68 ( ( clock - V_242 ) , V_146 ) ;
else if ( ( V_244 <= clock ) && ( clock <= V_245 ) )
return F_69 ( ( clock - V_244 ) , V_146 ) ;
else if ( clock == V_246 )
return F_67 ( V_146 ) ;
else if ( clock == V_247 )
return F_62 ( V_146 ) ;
else if ( ( clock == V_162 ) || ( clock == V_165 ) )
return F_56 ( clock , V_146 ) ;
else
return - V_48 ;
}
static unsigned long F_71 ( void T_3 * V_31 , unsigned long V_248 ,
int V_249 )
{
T_5 V_250 ;
T_1 V_36 ;
T_1 V_251 ;
T_1 div = 1 ;
V_36 = F_3 ( V_31 ) ;
V_250 = V_248 ;
V_250 *= ( ( V_36 & V_252 ) >> V_253 ) ;
V_251 = ( ( V_36 & V_254 ) >> V_255 ) ;
if ( V_251 > 1 )
div *= V_251 ;
V_251 = ( ( V_36 & V_256 ) >> V_257 ) ;
if ( V_251 > 1 )
div *= V_251 ;
if ( V_36 & V_258 )
div *= 2 ;
if ( ( V_249 == V_259 ) || ( ( V_249 == V_260 ) &&
( V_36 & V_261 ) &&
( ( V_31 == V_262 ) ||
( V_31 == V_263 ) ||
( V_31 == V_264 ) ) ) )
div *= 2 ;
( void ) F_72 ( V_250 , div ) ;
return ( unsigned long ) V_250 ;
}
static unsigned long F_73 ( T_2 clock )
{
T_1 V_36 ;
T_1 V_217 ;
unsigned long V_250 = V_265 ;
V_36 = F_3 ( V_215 [ clock ] . V_31 ) ;
if ( V_36 & V_266 ) {
if ( V_215 [ clock ] . V_267 && ( V_36 & V_268 ) )
V_250 /= 2 ;
return V_250 ;
}
V_36 |= V_215 [ clock ] . V_217 ;
V_217 = ( V_36 & V_218 ) ;
if ( V_217 == V_269 )
V_250 = F_71 ( V_262 , V_250 , V_215 [ clock ] . V_249 ) ;
else if ( V_217 == V_270 )
V_250 = F_71 ( V_271 , V_250 , V_215 [ clock ] . V_249 ) ;
else if ( V_217 == V_272 )
V_250 = F_71 ( V_264 , V_250 , V_215 [ clock ] . V_249 ) ;
else
return 0 ;
if ( ( clock == V_239 ) &&
( V_36 & V_273 ) ) {
T_5 V_57 = ( V_250 * 10 ) ;
( void ) F_72 ( V_57 , 25 ) ;
return ( unsigned long ) V_57 ;
}
V_36 &= V_150 ;
if ( V_36 )
return V_250 / V_36 ;
else
return 0 ;
}
static unsigned long F_74 ( void )
{
return V_274 ;
}
static void F_42 ( void )
{
T_1 V_57 ;
unsigned long V_250 ;
V_57 = F_3 ( V_275 ) ;
if ( V_57 & V_276 ) {
V_250 = F_71 ( V_264 , V_265 , V_259 ) ;
if ( ! ( V_57 & V_277 ) )
V_250 /= 2 ;
V_57 = F_3 ( V_278 ) ;
V_57 &= V_150 ;
V_250 /= V_57 ;
} else {
V_250 = F_71 ( V_263 , V_265 , V_260 ) ;
}
V_274 = V_250 ;
}
static unsigned long F_75 ( T_2 V_231 )
{
T_1 V_234 ;
T_1 div = 1 ;
V_234 = F_3 ( V_9 ) ;
V_234 = ( ( V_234 & V_232 [ V_231 ] . V_233 ) >> V_232 [ V_231 ] . V_236 ) ;
if ( V_234 == V_235 )
V_234 = V_232 [ V_231 ] . V_234 ;
switch ( V_234 ) {
case V_279 :
div *= 2 ;
case V_280 :
div *= 2 ;
case V_281 :
return F_71 ( V_7 , F_73 ( V_282 ) ,
V_283 ) / div ;
default:
return 0 ;
}
}
static unsigned long F_76 ( T_2 V_231 )
{
T_1 div ;
div = F_3 ( V_11 ) ;
div = ( ( div & V_237 [ V_231 ] . V_59 ) >> ( V_237 [ V_231 ] . V_284 ) ) ;
return F_73 ( V_285 ) / F_77 ( ( T_1 ) 1 , div ) ;
}
unsigned long F_78 ( T_2 clock )
{
if ( clock < V_240 )
return F_73 ( clock ) ;
else if ( clock == V_241 )
return V_265 / 16 ;
else if ( clock == V_247 )
return V_265 ;
else if ( clock == V_162 )
return F_71 ( V_262 , V_265 , V_283 ) ;
else if ( clock == V_165 )
return F_71 ( V_271 , V_265 , V_283 ) ;
else if ( clock == V_286 )
return F_74 () ;
else if ( clock == V_287 )
return F_71 ( V_264 , V_265 , V_283 ) ;
else if ( clock == V_246 )
return F_71 ( V_7 , F_73 ( V_282 ) ,
V_283 ) ;
else if ( ( clock == V_242 ) || ( clock == V_243 ) )
return F_75 ( clock - V_242 ) ;
else if ( ( V_244 <= clock ) && ( clock <= V_245 ) )
return F_76 ( clock - V_244 ) ;
else
return 0 ;
}
static unsigned long F_79 ( T_1 V_288 , int V_249 )
{
if ( V_288 & V_266 )
return V_265 ;
V_288 &= V_218 ;
if ( V_288 == V_269 )
return F_71 ( V_262 , V_265 , V_249 ) ;
else if ( V_288 == V_270 )
return F_71 ( V_271 , V_265 , V_249 ) ;
else if ( V_288 == V_272 )
return F_71 ( V_264 , V_265 , V_249 ) ;
else
return 0 ;
}
static T_1 F_80 ( unsigned long V_248 , unsigned long V_250 )
{
T_1 div ;
div = ( V_248 / V_250 ) ;
if ( div == 0 )
return 1 ;
if ( V_250 < ( V_248 / div ) )
div ++ ;
return div ;
}
static long F_81 ( T_2 clock , unsigned long V_250 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_248 ;
long V_289 ;
V_36 = F_3 ( V_215 [ clock ] . V_31 ) ;
V_248 = F_79 ( ( V_36 | V_215 [ clock ] . V_217 ) ,
V_215 [ clock ] . V_249 ) ;
div = F_80 ( V_248 , V_250 ) ;
if ( V_36 & V_266 ) {
if ( V_215 [ clock ] . V_267 ) {
if ( div > 2 )
div = 2 ;
} else {
div = 1 ;
}
} else if ( ( clock == V_239 ) && ( div == 3 ) ) {
T_5 V_57 = ( V_248 * 10 ) ;
( void ) F_72 ( V_57 , 25 ) ;
if ( V_57 <= V_250 )
return ( unsigned long ) V_57 ;
}
V_289 = ( V_248 / F_82 ( div , ( T_1 ) 31 ) ) ;
return V_289 ;
}
static long F_83 ( unsigned long V_250 )
{
long V_289 = 0 ;
unsigned long V_248 ;
unsigned long V_290 ;
T_1 V_57 ;
V_248 = F_73 ( V_282 ) ;
V_290 = V_250 ;
for ( V_57 = 7 ; ( V_290 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_251 ;
V_251 = ( V_57 * V_250 ) ;
( void ) F_72 ( V_251 , V_248 ) ;
if ( V_251 < 6 )
V_251 = 6 ;
else if ( V_251 > 255 )
V_251 = 255 ;
V_251 *= V_248 ;
if ( ( ( 2 * V_251 ) < ( V_57 * V_291 ) ) ||
( ( V_57 * V_292 ) < ( 2 * V_251 ) ) )
continue;
( void ) F_72 ( V_251 , V_57 ) ;
if ( V_250 < V_251 ) {
if ( V_289 == 0 )
V_289 = ( long ) V_251 ;
break;
}
if ( ( V_250 - V_251 ) < V_290 ) {
V_290 = ( V_250 - V_251 ) ;
V_289 = ( long ) V_251 ;
}
}
return V_289 ;
}
static long F_84 ( unsigned long V_250 )
{
T_1 div ;
unsigned long V_248 ;
long V_289 ;
V_248 = F_71 ( V_7 , F_73 ( V_282 ) ,
V_283 ) ;
div = F_80 ( V_248 , V_250 ) ;
V_289 = ( V_248 / ( ( div > 2 ) ? 4 : div ) ) ;
return V_289 ;
}
static long F_85 ( unsigned long V_250 )
{
T_1 div ;
unsigned long V_248 ;
long V_289 ;
V_248 = F_73 ( V_285 ) ;
div = F_80 ( V_248 , V_250 ) ;
V_289 = ( V_248 / F_82 ( div , ( T_1 ) 255 ) ) ;
return V_289 ;
}
long F_86 ( T_2 clock , unsigned long V_250 )
{
if ( clock < V_240 )
return F_81 ( clock , V_250 ) ;
else if ( clock == V_246 )
return F_83 ( V_250 ) ;
else if ( ( clock == V_242 ) || ( clock == V_243 ) )
return F_84 ( V_250 ) ;
else if ( ( V_244 <= clock ) && ( clock <= V_245 ) )
return F_85 ( V_250 ) ;
else
return ( long ) F_78 ( clock ) ;
}
static void F_87 ( T_2 clock , unsigned long V_250 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_248 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_215 [ clock ] . V_31 ) ;
V_248 = F_79 ( ( V_36 | V_215 [ clock ] . V_217 ) ,
V_215 [ clock ] . V_249 ) ;
div = F_80 ( V_248 , V_250 ) ;
if ( V_36 & V_266 ) {
if ( V_215 [ clock ] . V_267 ) {
if ( div > 1 )
V_36 |= V_268 ;
else
V_36 &= ~ V_268 ;
}
} else if ( clock == V_239 ) {
V_36 &= ~ ( V_150 |
V_273 ) ;
if ( div == 3 ) {
T_5 V_57 = ( V_248 * 10 ) ;
( void ) F_72 ( V_57 , 25 ) ;
if ( V_57 <= V_250 ) {
V_36 |= V_273 ;
div = 0 ;
}
}
V_36 |= F_82 ( div , ( T_1 ) 31 ) ;
} else {
V_36 &= ~ V_150 ;
V_36 |= F_82 ( div , ( T_1 ) 31 ) ;
}
F_2 ( V_36 , V_215 [ clock ] . V_31 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
static int F_88 ( unsigned long V_250 )
{
unsigned long V_248 ;
unsigned long V_290 ;
T_1 V_293 = 0 ;
T_1 V_57 ;
V_248 = F_73 ( V_282 ) ;
V_290 = V_250 ;
for ( V_57 = 7 ; ( V_290 > 0 ) && ( V_57 > 0 ) ; V_57 -- ) {
T_5 V_251 ;
T_5 V_294 ;
V_251 = ( V_57 * V_250 ) ;
( void ) F_72 ( V_251 , V_248 ) ;
if ( V_251 < 6 )
V_251 = 6 ;
else if ( V_251 > 255 )
V_251 = 255 ;
V_294 = ( V_251 * V_248 ) ;
if ( ( ( 2 * V_294 ) < ( V_57 * V_291 ) ) ||
( ( V_57 * V_292 ) < ( 2 * V_294 ) ) )
continue;
( void ) F_72 ( V_294 , V_57 ) ;
if ( V_250 < V_294 ) {
if ( V_293 == 0 )
V_293 = ( ( ( T_1 ) V_251 << V_253 ) |
( V_57 << V_257 ) ) ;
break;
}
if ( ( V_250 - V_294 ) < V_290 ) {
V_290 = ( V_250 - V_294 ) ;
V_293 = ( ( ( T_1 ) V_251 << V_253 ) |
( V_57 << V_257 ) ) ;
}
}
if ( V_293 == 0 )
return - V_48 ;
V_293 |= ( 1 << V_255 ) ;
F_2 ( V_293 , V_7 ) ;
return 0 ;
}
static void F_89 ( T_2 V_231 , unsigned long V_250 )
{
T_1 V_36 ;
T_1 div ;
div = F_80 ( F_71 ( V_7 ,
F_73 ( V_282 ) , V_283 ) , V_250 ) ;
V_232 [ V_231 ] . V_234 = ( div == 1 ) ? V_281 :
( div == 2 ) ? V_280 :
V_279 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_232 [ V_231 ] . V_233 ;
V_36 |= ( V_232 [ V_231 ] . V_234 << V_232 [ V_231 ] . V_236 ) ;
F_2 ( V_36 , V_9 ) ;
}
static void F_90 ( T_2 V_231 , unsigned long V_250 )
{
T_1 V_36 ;
T_1 div ;
div = F_80 ( F_73 ( V_285 ) , V_250 ) ;
V_36 = F_3 ( V_11 ) ;
V_36 &= ~ V_237 [ V_231 ] . V_59 ;
V_36 |= ( F_82 ( div , ( T_1 ) 255 ) << V_237 [ V_231 ] . V_284 ) ;
F_2 ( V_36 , V_11 ) ;
}
int F_91 ( T_2 clock , unsigned long V_250 )
{
if ( clock < V_240 )
F_87 ( clock , V_250 ) ;
else if ( clock == V_246 )
return F_88 ( V_250 ) ;
else if ( ( clock == V_242 ) || ( clock == V_243 ) )
F_89 ( ( clock - V_242 ) , V_250 ) ;
else if ( ( V_244 <= clock ) && ( clock <= V_245 ) )
F_90 ( ( clock - V_244 ) , V_250 ) ;
return 0 ;
}
int F_92 ( T_2 V_74 )
{
if ( ( V_74 > V_295 ) ||
( V_74 < V_296 ) )
return - V_48 ;
F_40 ( & V_297 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_298 , ( V_41 + V_299 ) ) ;
F_18 ( ( ( V_300 << 4 ) | V_301 ) ,
( V_41 + V_302 ) ) ;
F_18 ( V_301 ,
( V_41 + V_303 ) ) ;
F_18 ( V_74 , ( V_41 + V_304 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_297 . V_138 ) ;
F_43 ( & V_297 . V_80 ) ;
return 0 ;
}
int F_93 ( T_2 V_305 )
{
F_40 ( & V_297 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_305 , ( V_41 + V_306 ) ) ;
F_18 ( V_307 , ( V_41 + V_299 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_297 . V_138 ) ;
F_43 ( & V_297 . V_80 ) ;
return 0 ;
}
int F_94 ( T_2 V_308 , T_2 V_309 )
{
F_40 ( & V_297 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_308 , ( V_41 + V_310 ) ) ;
F_18 ( V_309 , ( V_41 + V_311 ) ) ;
F_18 ( ( V_312 | V_313 ) ,
( V_41 + V_314 ) ) ;
F_18 ( V_315 , ( V_41 + V_299 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_297 . V_138 ) ;
F_43 ( & V_297 . V_80 ) ;
return 0 ;
}
static int F_95 ( T_4 V_36 )
{
F_40 ( & V_297 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_96 ( V_36 , ( V_41 + V_316 ) ) ;
F_18 ( V_317 , ( V_41 + V_299 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_297 . V_138 ) ;
F_43 ( & V_297 . V_80 ) ;
return 0 ;
}
int F_97 ( T_4 V_318 )
{
if ( V_318 == 0xFFFF )
return - V_48 ;
return F_95 ( V_318 ) ;
}
int F_98 ( void )
{
return F_95 ( 0xFFFF ) ;
}
static int F_99 ( T_2 V_319 , T_2 V_320 , T_2 V_321 , T_2 V_322 , T_2 V_323 )
{
F_40 ( & V_297 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 4 ) )
F_8 () ;
F_18 ( V_320 , ( V_41 + V_324 ) ) ;
F_18 ( V_321 , ( V_41 + V_325 ) ) ;
F_18 ( V_322 , ( V_41 + V_326 ) ) ;
F_18 ( V_323 , ( V_41 + V_327 ) ) ;
F_18 ( V_319 , ( V_41 + V_299 ) ) ;
F_2 ( F_24 ( 4 ) , V_88 ) ;
F_41 ( & V_297 . V_138 ) ;
F_43 ( & V_297 . V_80 ) ;
return 0 ;
}
int F_100 ( T_2 V_328 , bool V_329 )
{
F_22 ( V_328 == 0 || V_328 > 0xf ) ;
return F_99 ( V_330 , V_328 , 0 , 0 ,
V_329 ? V_331 :
V_332 ) ;
}
int F_101 ( T_2 V_333 )
{
return F_99 ( V_334 , V_333 , 0 , 0 , 0 ) ;
}
int F_102 ( T_2 V_333 )
{
return F_99 ( V_335 , V_333 , 0 , 0 , 0 ) ;
}
int F_103 ( T_2 V_333 )
{
return F_99 ( V_336 , V_333 , 0 , 0 , 0 ) ;
}
int F_104 ( T_2 V_333 , T_1 V_337 )
{
return F_99 ( V_338 ,
( V_333 & V_339 ) |
( T_2 ) ( ( V_337 << 4 ) & 0xf0 ) ,
( T_2 ) ( ( V_337 >> 4 ) & 0xff ) ,
( T_2 ) ( ( V_337 >> 12 ) & 0xff ) ,
( T_2 ) ( ( V_337 >> 20 ) & 0xff ) ) ;
}
int F_105 ( T_2 V_340 , T_2 V_31 , T_2 * V_33 , T_2 V_341 )
{
int V_57 ;
if ( V_341 != 1 )
return - V_48 ;
F_40 ( & V_342 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( 0 , ( V_41 + V_343 ) ) ;
F_18 ( F_106 ( V_340 ) , ( V_41 + V_344 ) ) ;
F_18 ( V_345 , ( V_41 + V_346 ) ) ;
F_18 ( V_31 , ( V_41 + V_347 ) ) ;
F_18 ( 0 , ( V_41 + V_348 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_58 ( & V_342 . V_138 ,
F_59 ( 20000 ) ) ) {
F_51 ( L_2 ,
V_151 ) ;
V_57 = - V_141 ;
} else {
V_57 = ( ( V_342 . V_139 . V_185 == V_349 ) ? 0 : - V_141 ) ;
}
if ( ! V_57 )
* V_33 = V_342 . V_139 . V_33 ;
F_43 ( & V_342 . V_80 ) ;
return V_57 ;
}
int F_107 ( T_2 V_340 , T_2 V_31 , T_2 * V_33 , T_2 * V_35 , T_2 V_341 )
{
int V_57 ;
if ( V_341 != 1 )
return - V_48 ;
F_40 ( & V_342 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 5 ) )
F_8 () ;
F_18 ( ~ * V_35 , ( V_41 + V_343 ) ) ;
F_18 ( F_108 ( V_340 ) , ( V_41 + V_344 ) ) ;
F_18 ( V_345 , ( V_41 + V_346 ) ) ;
F_18 ( V_31 , ( V_41 + V_347 ) ) ;
F_18 ( * V_33 , ( V_41 + V_348 ) ) ;
F_2 ( F_24 ( 5 ) , V_88 ) ;
if ( ! F_58 ( & V_342 . V_138 ,
F_59 ( 20000 ) ) ) {
F_51 ( L_2 ,
V_151 ) ;
V_57 = - V_141 ;
} else {
V_57 = ( ( V_342 . V_139 . V_185 == V_350 ) ? 0 : - V_141 ) ;
}
F_43 ( & V_342 . V_80 ) ;
return V_57 ;
}
int F_109 ( T_2 V_340 , T_2 V_31 , T_2 * V_33 , T_2 V_341 )
{
T_2 V_35 = ~ 0 ;
return F_107 ( V_340 , V_31 , V_33 , & V_35 , V_341 ) ;
}
int F_110 ( void )
{
T_1 V_36 ;
int V_219 = 0 ;
F_40 ( & V_79 . V_351 ) ;
V_36 = F_3 ( V_352 ) ;
if ( V_36 & V_353 )
goto V_73;
F_111 ( & V_354 , 1 ) ;
V_36 |= V_355 ;
F_2 ( V_36 , V_352 ) ;
F_4 ( 31 ) ;
V_36 |= V_353 ;
F_2 ( V_36 , V_352 ) ;
if ( ! F_58 ( & V_79 . V_356 ,
F_59 ( 5000 ) ) ) {
#if F_112 ( V_357 )
F_113 ( V_151 , true , true ) ;
#endif
F_114 ( L_3 ,
V_151 ) ;
V_219 = - V_358 ;
}
V_73:
F_43 ( & V_79 . V_351 ) ;
return V_219 ;
}
void F_115 ()
{
T_1 V_36 ;
F_40 ( & V_79 . V_351 ) ;
V_36 = F_3 ( V_352 ) ;
if ( ! ( V_36 & V_353 ) )
goto V_73;
F_2 ( ( V_36 & ~ V_353 ) ,
V_352 ) ;
if ( ! F_58 ( & V_79 . V_356 ,
F_59 ( 5000 ) ) ) {
F_114 ( L_3 ,
V_151 ) ;
}
F_111 ( & V_354 , 0 ) ;
V_73:
F_43 ( & V_79 . V_351 ) ;
}
bool F_116 ( void )
{
return ( F_117 ( & V_354 ) != 0 ) ;
}
void F_118 ( T_4 V_359 )
{
F_96 ( V_359 , ( V_41 + V_360 ) ) ;
F_2 ( 1 , V_361 ) ;
}
T_4 F_119 ( void )
{
return F_120 ( V_41 + V_360 ) ;
}
void F_121 ( void )
{
F_40 ( & V_132 . V_80 ) ;
while ( F_3 ( V_81 ) & F_24 ( 1 ) )
F_8 () ;
F_18 ( V_362 , ( V_41 + V_134 ) ) ;
F_2 ( F_24 ( 1 ) , V_88 ) ;
F_41 ( & V_132 . V_138 ) ;
F_43 ( & V_132 . V_80 ) ;
}
static void F_122 ( void )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
while ( F_3 ( V_81 ) & F_24 ( 0 ) )
F_8 () ;
F_18 ( V_363 , ( V_41 + V_83 ) ) ;
F_2 ( F_24 ( 0 ) , V_88 ) ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static inline void F_123 ( T_2 V_231 , T_2 V_107 )
{
F_124 ( L_4 ,
V_107 , V_231 ) ;
}
static bool F_125 ( void )
{
bool V_57 ;
T_1 V_364 ;
unsigned int V_231 ;
T_2 V_107 ;
V_107 = F_15 ( V_41 + V_365 ) ;
switch ( V_107 ) {
case V_366 :
case V_367 :
if ( F_15 ( V_41 + V_126 ) & 1 )
V_364 = F_3 ( V_41 + V_368 ) ;
else
V_364 = F_3 ( V_41 + V_369 ) ;
if ( V_364 & ( V_117 | V_118 ) )
F_126 ( & V_79 . V_356 ) ;
if ( V_364 & V_370 )
F_126 ( & V_203 . V_210 ) ;
V_364 &= V_79 . V_114 . V_115 ;
for ( V_231 = 0 ; V_231 < V_371 ; V_231 ++ ) {
if ( V_364 & V_372 [ V_231 ] )
F_127 ( V_373 + V_231 ) ;
}
V_57 = true ;
break;
default:
F_123 ( 0 , V_107 ) ;
V_57 = false ;
break;
}
F_2 ( F_24 ( 0 ) , V_374 ) ;
return V_57 ;
}
static bool F_128 ( void )
{
V_132 . V_139 . V_107 = F_15 ( V_41 + V_134 ) ;
V_132 . V_139 . V_140 = F_15 ( V_41 +
V_142 ) ;
V_132 . V_139 . V_152 = F_15 ( V_41 +
V_157 ) ;
V_132 . V_139 . V_160 = F_15 ( V_41 +
V_375 ) ;
F_2 ( F_24 ( 1 ) , V_374 ) ;
F_126 ( & V_132 . V_138 ) ;
return false ;
}
static bool F_129 ( void )
{
V_180 . V_139 . V_185 = F_15 ( V_41 + V_376 ) ;
F_2 ( F_24 ( 2 ) , V_374 ) ;
F_126 ( & V_180 . V_138 ) ;
return false ;
}
static bool F_130 ( void )
{
F_2 ( F_24 ( 3 ) , V_374 ) ;
return false ;
}
static bool F_131 ( void )
{
T_2 V_107 ;
bool V_377 = true ;
V_107 = F_15 ( V_41 + V_299 ) ;
switch ( V_107 ) {
case V_298 :
case V_307 :
case V_315 :
case V_317 :
case V_330 :
case V_334 :
case V_335 :
case V_338 :
case V_336 :
break;
default:
F_123 ( 4 , V_107 ) ;
V_377 = false ;
break;
}
F_2 ( F_24 ( 4 ) , V_374 ) ;
if ( V_377 )
F_126 ( & V_297 . V_138 ) ;
return false ;
}
static bool F_132 ( void )
{
V_342 . V_139 . V_185 = F_15 ( V_41 + V_378 ) ;
V_342 . V_139 . V_33 = F_15 ( V_41 + V_379 ) ;
F_2 ( F_24 ( 5 ) , V_374 ) ;
F_126 ( & V_342 . V_138 ) ;
return false ;
}
static bool F_133 ( void )
{
F_2 ( F_24 ( 6 ) , V_374 ) ;
return false ;
}
static bool F_134 ( void )
{
F_2 ( F_24 ( 7 ) , V_374 ) ;
return false ;
}
static T_6 F_135 ( int V_380 , void * V_381 )
{
T_1 V_58 ;
T_2 V_231 ;
T_6 V_57 ;
V_58 = ( F_3 ( V_382 ) & V_383 ) ;
if ( F_136 ( ! V_58 ) )
return V_384 ;
V_57 = V_385 ;
for ( V_231 = 0 ; V_58 ; V_231 ++ ) {
if ( V_58 & F_24 ( V_231 ) ) {
V_58 -= F_24 ( V_231 ) ;
if ( V_386 [ V_231 ] ( ) )
V_57 = V_387 ;
}
}
return V_57 ;
}
static T_6 F_137 ( int V_380 , void * V_381 )
{
F_122 () ;
return V_385 ;
}
static void F_138 ( struct V_388 * V_138 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_80 , V_21 ) ;
F_34 () ;
F_9 ( & V_79 . V_80 , V_21 ) ;
}
static void F_139 ( struct V_389 * V_251 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_390 , V_21 ) ;
V_79 . V_114 . V_115 &= ~ V_372 [ V_251 -> V_391 ] ;
F_9 ( & V_79 . V_390 , V_21 ) ;
if ( V_251 -> V_380 != V_392 )
F_140 ( & V_79 . V_393 ) ;
}
static void F_141 ( struct V_389 * V_251 )
{
unsigned long V_21 ;
F_7 ( & V_79 . V_390 , V_21 ) ;
V_79 . V_114 . V_115 |= V_372 [ V_251 -> V_391 ] ;
F_9 ( & V_79 . V_390 , V_21 ) ;
if ( V_251 -> V_380 != V_392 )
F_140 ( & V_79 . V_393 ) ;
}
static void F_142 ( struct V_389 * V_251 )
{
}
static char * F_143 ( T_2 V_394 )
{
switch ( V_394 ) {
case V_395 :
return L_5 ;
case V_396 :
return L_6 ;
case V_397 :
return L_7 ;
case V_398 :
return L_8 ;
case V_399 :
return L_9 ;
case V_400 :
return L_10 ;
default:
return L_11 ;
}
}
static int F_144 ( struct V_401 * V_251 , unsigned int V_402 ,
T_7 V_391 )
{
F_145 ( V_402 , & V_403 ,
V_404 ) ;
F_146 ( V_402 , V_405 ) ;
return 0 ;
}
static int F_147 ( struct V_406 * V_407 )
{
V_408 = F_148 (
V_407 , V_371 , V_373 ,
0 , & V_409 , NULL ) ;
if ( ! V_408 ) {
F_51 ( L_12 ) ;
return - V_410 ;
}
return 0 ;
}
void T_8 F_149 ( void )
{
if ( F_150 () ) {
void * V_411 = F_151 ( V_412 , V_413 ) ;
if ( V_411 != NULL ) {
T_1 V_40 ;
V_40 = F_3 ( V_411 + V_414 ) ;
V_38 . V_40 . V_394 = V_40 & 0xFF ;
V_38 . V_40 . V_415 = ( V_40 >> 8 ) & 0xFF ;
V_38 . V_40 . V_416 = ( V_40 >> 16 ) & 0xFF ;
V_38 . V_40 . V_417 = ( V_40 >> 24 ) & 0xFF ;
V_38 . V_39 = true ;
F_152 ( L_13 ,
F_143 ( V_38 . V_40 . V_394 ) ,
( V_40 >> 8 ) & 0xFF , ( V_40 >> 16 ) & 0xFF ,
( V_40 >> 24 ) & 0xFF ) ;
F_153 ( V_411 ) ;
}
V_41 = F_29 ( V_418 ) ;
} else {
F_51 ( L_14 ) ;
F_154 () ;
}
F_155 ( & V_79 . V_80 ) ;
F_155 ( & V_79 . V_390 ) ;
F_156 ( & V_79 . V_351 ) ;
F_157 ( & V_79 . V_356 ) ;
F_156 ( & V_132 . V_80 ) ;
F_157 ( & V_132 . V_138 ) ;
V_132 . V_152 = V_136 ;
F_156 ( & V_180 . V_80 ) ;
F_157 ( & V_180 . V_138 ) ;
F_155 ( & V_180 . V_198 ) ;
F_155 ( & V_203 . V_80 ) ;
F_156 ( & V_203 . V_204 ) ;
F_157 ( & V_203 . V_210 ) ;
F_156 ( & V_297 . V_80 ) ;
F_157 ( & V_297 . V_138 ) ;
F_156 ( & V_342 . V_80 ) ;
F_157 ( & V_342 . V_138 ) ;
F_158 ( & V_79 . V_393 , F_138 ) ;
F_42 () ;
}
static void T_8 F_159 ( void )
{
T_1 V_36 ;
V_36 = F_3 ( V_419 ) ;
V_36 &= ~ ( V_420 |
V_421 ) ;
F_2 ( V_36 , ( V_419 ) ) ;
}
static int T_9 F_160 ( struct V_422 * V_423 )
{
struct V_424 * V_425 = V_423 -> V_426 . V_427 ;
struct V_406 * V_407 = V_423 -> V_426 . V_428 ;
int V_380 = 0 , V_429 = 0 , V_1 ;
if ( F_161 () )
return - V_430 ;
F_159 () ;
F_2 ( V_383 , V_374 ) ;
if ( V_407 )
V_380 = F_162 ( V_423 , 0 ) ;
if ( ! V_407 || V_380 <= 0 )
V_380 = V_431 ;
V_429 = F_163 ( V_380 , F_135 ,
F_137 , V_432 , L_15 , NULL ) ;
if ( V_429 < 0 ) {
F_51 ( L_16 ) ;
V_429 = - V_72 ;
goto V_433;
}
F_147 ( V_407 ) ;
for ( V_1 = 0 ; V_1 < F_50 ( V_434 ) ; V_1 ++ ) {
if ( ! strcmp ( V_434 [ V_1 ] . V_435 , L_17 ) ) {
V_434 [ V_1 ] . V_427 = V_425 ;
V_434 [ V_1 ] . V_436 = sizeof( struct V_424 ) ;
}
}
if ( F_47 () )
F_164 ( V_295 ) ;
V_429 = F_165 ( & V_423 -> V_426 , 0 , V_434 ,
F_50 ( V_434 ) , NULL , 0 , NULL ) ;
if ( V_429 ) {
F_51 ( L_18 ) ;
return V_429 ;
}
F_152 ( L_19 ) ;
V_433:
return V_429 ;
}
static int T_8 F_166 ( void )
{
return F_167 ( & V_437 ) ;
}
