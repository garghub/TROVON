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
int F_36 ( T_2 V_111 )
{
if ( V_111 < V_126 || V_111 > V_127 )
return - V_47 ;
if ( V_128 )
F_17 ( V_111 , V_125 ) ;
return 0 ;
}
static void F_37 ( bool V_129 )
{
T_1 V_130 [] = {
V_131 ,
V_132
} ;
unsigned long V_21 ;
unsigned int V_1 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
for ( V_1 = 0 ; V_1 < F_38 ( V_130 ) ; V_1 ++ ) {
T_1 V_36 ;
T_1 div ;
V_36 = F_3 ( V_26 + V_130 [ V_1 ] ) ;
div = ( V_36 & V_133 ) ;
if ( V_129 ) {
if ( ( div <= 1 ) || ( div > 15 ) ) {
F_39 ( L_1 ,
div , V_134 ) ;
goto V_72;
}
div <<= 1 ;
} else {
if ( div <= 2 )
goto V_72;
div >>= 1 ;
}
V_36 = ( ( V_36 & ~ V_133 ) |
( div & V_133 ) ) ;
F_2 ( V_36 , V_26 + V_130 [ V_1 ] ) ;
}
V_72:
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
int F_40 ( T_2 V_111 )
{
int V_56 = 0 ;
if ( V_111 == V_114 . V_135 )
return 0 ;
F_31 ( & V_114 . V_79 ) ;
if ( V_114 . V_135 == V_136 )
F_37 ( false ) ;
if ( ( V_111 != V_137 ) && ( V_114 . V_135 != V_137 ) )
goto V_138;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_115 , ( V_41 + V_116 ) ) ;
F_17 ( V_112 , ( V_41 + V_117 ) ) ;
F_17 ( ( ( V_111 == V_136 ) ? V_139 : V_111 ) ,
( V_41 + V_119 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_115 ) ||
( V_114 . V_121 . V_135 != V_111 ) )
V_56 = - V_123 ;
V_138:
if ( ( ! V_56 && ( V_111 == V_136 ) ) ||
( V_56 && ( V_114 . V_135 == V_136 ) ) )
F_37 ( true ) ;
if ( ! V_56 )
V_114 . V_135 = V_111 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_41 ( void )
{
return F_15 ( V_41 + V_140 ) ;
}
int F_42 ( bool V_129 )
{
int V_56 = 0 ;
T_2 V_89 ;
static unsigned int V_55 ;
F_31 ( & V_114 . V_79 ) ;
if ( V_129 ) {
if ( 0 != V_55 ++ )
goto V_72;
V_89 = V_141 ;
} else {
if ( V_55 == 0 ) {
V_56 = - V_123 ;
goto V_72;
} else if ( 1 != V_55 -- ) {
goto V_72;
}
V_89 = V_142 ;
}
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_89 , ( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_89 ) ||
( ( V_114 . V_121 . V_143 & F_27 ( 0 ) ) != 0 ) )
V_56 = - V_123 ;
V_72:
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_43 ( void )
{
int V_56 = 0 ;
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_144 ,
( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( ( V_114 . V_121 . V_89 != V_144 ) ||
( ( V_114 . V_121 . V_143 & F_27 ( 0 ) ) != 0 ) )
V_56 = - V_123 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
static int F_44 ( T_2 clock , bool V_129 )
{
int V_56 = 0 ;
if ( clock == V_145 )
clock = ( V_129 ? V_146 : V_147 ) ;
else if ( clock == V_148 )
clock = ( V_129 ? V_149 : V_150 ) ;
else
return - V_47 ;
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_151 , ( V_41 + V_116 ) ) ;
F_17 ( clock , ( V_41 + V_152 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
if ( V_114 . V_121 . V_89 != V_151 )
V_56 = - V_123 ;
F_33 ( & V_114 . V_79 ) ;
return V_56 ;
}
int F_45 ( T_4 V_153 , T_2 V_154 )
{
int V_56 = 0 ;
bool V_155 = false ;
int V_1 ;
F_21 ( V_153 >= V_156 ) ;
switch ( V_153 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
V_155 = true ;
break;
}
F_21 ( V_154 > V_161 ) ;
F_21 ( V_154 == V_162 && ! V_155 ) ;
F_31 ( & V_163 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 2 ) )
F_8 () ;
for ( V_1 = 0 ; V_1 < V_156 ; V_1 ++ )
F_17 ( V_164 , ( V_41 + V_165 + V_1 ) ) ;
F_17 ( V_154 , ( V_41 + V_165 + V_153 ) ) ;
F_17 ( V_166 , ( V_41 + V_167 ) ) ;
F_2 ( F_23 ( 2 ) , V_87 ) ;
if ( ! F_46 ( & V_163 . V_120 ,
F_47 ( 20000 ) ) ) {
F_39 ( L_2 ,
V_134 ) ;
V_56 = - V_123 ;
goto V_72;
}
if ( V_163 . V_121 . V_168 != V_169 )
V_56 = - V_123 ;
V_72:
F_33 ( & V_163 . V_79 ) ;
return V_56 ;
}
void F_48 ( struct V_170 * V_171 ,
struct V_170 * V_172 )
{
T_1 V_173 ;
T_1 V_174 ;
unsigned long V_21 ;
F_21 ( ( V_171 == NULL ) || ( V_172 == NULL ) ) ;
V_173 = ( V_171 -> V_175 & 0xF ) ;
V_173 = ( ( V_173 << 4 ) | ( V_171 -> V_176 & 0xF ) ) ;
V_173 = ( ( V_173 << 8 ) | ( V_171 -> V_177 & 0xFF ) ) ;
V_173 = ( ( V_173 << 8 ) | ( V_171 -> V_178 & 0xFF ) ) ;
V_173 = ( ( V_173 << 4 ) | ( V_171 -> V_179 & 0xF ) ) ;
V_173 = ( ( V_173 << 4 ) | ( V_171 -> V_180 & 0xF ) ) ;
V_174 = ( V_172 -> V_175 & 0xF ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_176 & 0xF ) ) ;
V_174 = ( ( V_174 << 8 ) | ( V_172 -> V_177 & 0xFF ) ) ;
V_174 = ( ( V_174 << 8 ) | ( V_172 -> V_178 & 0xFF ) ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_179 & 0xF ) ) ;
V_174 = ( ( V_174 << 4 ) | ( V_172 -> V_180 & 0xF ) ) ;
F_7 ( & V_163 . V_181 , V_21 ) ;
F_2 ( V_173 , ( V_41 + V_182 ) ) ;
F_2 ( V_174 , ( V_41 + V_183 ) ) ;
V_163 . V_184 =
( ( V_171 -> V_175 == V_185 ) ||
( V_171 -> V_176 == V_185 ) ||
( V_172 -> V_175 == V_185 ) ||
( V_172 -> V_176 == V_185 ) ) ;
F_9 ( & V_163 . V_181 , V_21 ) ;
}
bool F_49 ( void )
{
return V_163 . V_184 ;
}
static int F_50 ( bool V_129 )
{
int V_56 ;
unsigned long V_21 ;
V_56 = 0 ;
F_31 ( & V_186 . V_187 ) ;
F_7 ( & V_186 . V_79 , V_21 ) ;
while ( F_3 ( V_80 ) & F_23 ( 3 ) )
F_8 () ;
F_17 ( ( V_129 ? V_188 : V_189 ) , ( V_41 + V_190 ) ) ;
F_17 ( V_191 , ( V_41 + V_192 ) ) ;
F_2 ( F_23 ( 3 ) , V_87 ) ;
F_9 ( & V_186 . V_79 , V_21 ) ;
if ( V_129 && ! F_46 ( & V_186 . V_193 ,
F_47 ( 20000 ) ) ) {
F_39 ( L_2 ,
V_134 ) ;
V_56 = - V_123 ;
}
F_33 ( & V_186 . V_187 ) ;
return V_56 ;
}
static int F_51 ( bool V_129 )
{
T_1 V_36 = ( V_194 | V_195 ) ;
if ( ! V_129 )
V_36 |= V_196 ;
F_2 ( V_36 , V_197 ) ;
return 0 ;
}
static int F_52 ( T_2 clock , bool V_129 )
{
T_1 V_36 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_198 [ clock ] . V_199 ) ;
if ( V_129 ) {
V_36 |= ( V_200 | V_198 [ clock ] . V_201 ) ;
} else {
V_198 [ clock ] . V_201 = ( V_36 & V_202 ) ;
V_36 &= ~ ( V_200 | V_202 ) ;
}
F_2 ( V_36 , V_26 + V_198 [ clock ] . V_199 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
return 0 ;
}
static int F_53 ( T_2 clock , bool V_129 )
{
T_1 V_36 ;
int V_203 ;
if ( V_129 ) {
V_36 = F_3 ( V_204 ) ;
F_2 ( V_36 | V_205 , V_204 ) ;
}
V_203 = F_52 ( clock , V_129 ) ;
if ( ! V_203 && ! V_129 ) {
V_36 = F_3 ( V_204 ) ;
F_2 ( V_36 & ~ V_205 , V_204 ) ;
}
return V_203 ;
}
static inline bool F_54 ( void )
{
return ( F_3 ( V_16 ) &
( V_206 |
V_207 ) ) ==
( V_206 |
V_207 ) ;
}
static int F_55 ( bool V_129 )
{
int V_56 = 0 ;
T_1 V_36 ;
F_2 ( ( V_208 |
V_209 ) , ( V_129 ?
V_5 : V_210 ) ) ;
V_36 = F_3 ( V_13 ) ;
if ( V_129 )
V_36 |= V_211 ;
else
V_36 &= ~ V_211 ;
F_2 ( V_36 , V_13 ) ;
if ( V_129 ) {
unsigned int V_1 ;
bool V_212 = F_54 () ;
for ( V_1 = 10 ; ! V_212 && ( V_1 > 0 ) ; -- V_1 ) {
F_4 ( 100 ) ;
V_212 = F_54 () ;
}
if ( V_212 ) {
F_2 ( V_213 ,
V_18 ) ;
} else {
F_2 ( ( V_208 |
V_209 ) ,
V_210 ) ;
V_36 &= ~ V_211 ;
F_2 ( V_36 , V_13 ) ;
V_56 = - V_214 ;
}
} else {
F_2 ( V_213 , V_3 ) ;
}
return V_56 ;
}
static int F_56 ( T_2 V_215 , bool V_129 )
{
T_1 V_36 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_216 [ V_215 ] . V_217 ;
V_36 |= ( ( V_129 ? V_216 [ V_215 ] . V_218 : V_219 ) <<
V_216 [ V_215 ] . V_220 ) ;
F_2 ( V_36 , V_9 ) ;
return 0 ;
}
static int F_57 ( T_2 V_215 , bool V_129 )
{
T_1 V_36 ;
V_36 = F_3 ( V_11 ) ;
V_129 ? ( V_36 |= V_221 [ V_215 ] . V_222 ) : ( V_36 &= ~ V_221 [ V_215 ] . V_222 ) ;
F_2 ( V_36 , V_11 ) ;
return 0 ;
}
int F_58 ( T_2 clock , bool V_129 )
{
if ( clock == V_223 )
return F_53 ( clock , V_129 ) ;
else if ( clock < V_224 )
return F_52 ( clock , V_129 ) ;
else if ( clock == V_225 )
return F_51 ( V_129 ) ;
else if ( ( clock == V_226 ) || ( clock == V_227 ) )
return F_56 ( ( clock - V_226 ) , V_129 ) ;
else if ( ( V_228 <= clock ) && ( clock <= V_229 ) )
return F_57 ( ( clock - V_228 ) , V_129 ) ;
else if ( clock == V_230 )
return F_55 ( V_129 ) ;
else if ( clock == V_231 )
return F_50 ( V_129 ) ;
else if ( ( clock == V_145 ) || ( clock == V_148 ) )
return F_44 ( clock , V_129 ) ;
else
return - V_47 ;
}
static unsigned long F_59 ( void T_3 * V_32 , unsigned long V_232 ,
int V_233 )
{
T_5 V_234 ;
T_1 V_36 ;
T_1 V_235 ;
T_1 div = 1 ;
V_36 = F_3 ( V_32 ) ;
V_234 = V_232 ;
V_234 *= ( ( V_36 & V_236 ) >> V_237 ) ;
V_235 = ( ( V_36 & V_238 ) >> V_239 ) ;
if ( V_235 > 1 )
div *= V_235 ;
V_235 = ( ( V_36 & V_240 ) >> V_241 ) ;
if ( V_235 > 1 )
div *= V_235 ;
if ( V_36 & V_242 )
div *= 2 ;
if ( ( V_233 == V_243 ) || ( ( V_233 == V_244 ) &&
( V_36 & V_245 ) &&
( ( V_32 == V_246 ) ||
( V_32 == V_247 ) ||
( V_32 == V_248 ) ) ) )
div *= 2 ;
( void ) F_60 ( V_234 , div ) ;
return ( unsigned long ) V_234 ;
}
static unsigned long F_61 ( T_2 clock )
{
T_1 V_36 ;
T_1 V_201 ;
unsigned long V_234 = V_249 ;
V_36 = F_3 ( V_26 + V_198 [ clock ] . V_199 ) ;
if ( V_36 & V_250 ) {
if ( V_198 [ clock ] . V_251 && ( V_36 & V_252 ) )
V_234 /= 2 ;
return V_234 ;
}
V_36 |= V_198 [ clock ] . V_201 ;
V_201 = ( V_36 & V_202 ) ;
if ( V_201 == V_253 )
V_234 = F_59 ( V_246 , V_234 , V_198 [ clock ] . V_233 ) ;
else if ( V_201 == V_254 )
V_234 = F_59 ( V_255 , V_234 , V_198 [ clock ] . V_233 ) ;
else if ( V_201 == V_256 )
V_234 = F_59 ( V_248 , V_234 , V_198 [ clock ] . V_233 ) ;
else
return 0 ;
if ( ( clock == V_223 ) &&
( V_36 & V_257 ) ) {
T_5 V_56 = ( V_234 * 10 ) ;
( void ) F_60 ( V_56 , 25 ) ;
return ( unsigned long ) V_56 ;
}
V_36 &= V_133 ;
if ( V_36 )
return V_234 / V_36 ;
else
return 0 ;
}
static unsigned long F_62 ( void )
{
T_1 V_56 ;
unsigned long V_234 ;
V_56 = F_3 ( V_258 ) ;
if ( V_56 & V_259 ) {
V_234 = F_59 ( V_248 , V_249 , V_243 ) ;
if ( ! ( V_56 & V_260 ) )
V_234 /= 2 ;
V_56 = F_3 ( V_261 ) ;
V_56 &= V_133 ;
V_234 /= V_56 ;
} else {
V_234 = F_59 ( V_247 , V_249 , V_244 ) ;
}
return V_234 ;
}
static unsigned long F_63 ( T_2 V_215 )
{
T_1 V_218 ;
T_1 div = 1 ;
V_218 = F_3 ( V_9 ) ;
V_218 = ( ( V_218 & V_216 [ V_215 ] . V_217 ) >> V_216 [ V_215 ] . V_220 ) ;
if ( V_218 == V_219 )
V_218 = V_216 [ V_215 ] . V_218 ;
else
V_216 [ V_215 ] . V_218 = V_218 ;
switch ( V_218 ) {
case V_262 :
div *= 2 ;
case V_263 :
div *= 2 ;
case V_264 :
return F_59 ( V_7 , F_61 ( V_265 ) ,
V_266 ) / div ;
default:
return 0 ;
}
}
static unsigned long F_64 ( T_2 V_215 )
{
T_1 div ;
div = F_3 ( V_11 ) ;
div = ( ( div & V_221 [ V_215 ] . V_58 ) >> ( V_221 [ V_215 ] . V_267 ) ) ;
return F_61 ( V_268 ) / F_65 ( ( T_1 ) 1 , div ) ;
}
unsigned long F_66 ( T_2 clock )
{
if ( clock < V_224 )
return F_61 ( clock ) ;
else if ( clock == V_225 )
return V_249 / 16 ;
else if ( clock == V_231 )
return V_249 ;
else if ( clock == V_145 )
return F_59 ( V_246 , V_249 , V_266 ) ;
else if ( clock == V_148 )
return F_59 ( V_255 , V_249 , V_266 ) ;
else if ( clock == V_269 )
return F_62 () ;
else if ( clock == V_270 )
return F_59 ( V_248 , V_249 , V_266 ) ;
else if ( clock == V_230 )
return F_59 ( V_7 , F_61 ( V_265 ) ,
V_266 ) ;
else if ( ( clock == V_226 ) || ( clock == V_227 ) )
return F_63 ( clock - V_226 ) ;
else if ( ( V_228 <= clock ) && ( clock <= V_229 ) )
return F_64 ( clock - V_228 ) ;
else
return 0 ;
}
static unsigned long F_67 ( T_1 V_271 , int V_233 )
{
if ( V_271 & V_250 )
return V_249 ;
V_271 &= V_202 ;
if ( V_271 == V_253 )
return F_59 ( V_246 , V_249 , V_233 ) ;
else if ( V_271 == V_254 )
return F_59 ( V_255 , V_249 , V_233 ) ;
else if ( V_271 == V_256 )
return F_59 ( V_248 , V_249 , V_233 ) ;
else
return 0 ;
}
static T_1 F_68 ( unsigned long V_232 , unsigned long V_234 )
{
T_1 div ;
div = ( V_232 / V_234 ) ;
if ( div == 0 )
return 1 ;
if ( V_234 < ( V_232 / div ) )
div ++ ;
return div ;
}
static long F_69 ( T_2 clock , unsigned long V_234 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_232 ;
long V_272 ;
V_36 = F_3 ( V_26 + V_198 [ clock ] . V_199 ) ;
V_232 = F_67 ( ( V_36 | V_198 [ clock ] . V_201 ) ,
V_198 [ clock ] . V_233 ) ;
div = F_68 ( V_232 , V_234 ) ;
if ( V_36 & V_250 ) {
if ( V_198 [ clock ] . V_251 ) {
if ( div > 2 )
div = 2 ;
} else {
div = 1 ;
}
} else if ( ( clock == V_223 ) && ( div == 3 ) ) {
T_5 V_56 = ( V_232 * 10 ) ;
( void ) F_60 ( V_56 , 25 ) ;
if ( V_56 <= V_234 )
return ( unsigned long ) V_56 ;
}
V_272 = ( V_232 / F_70 ( div , ( T_1 ) 31 ) ) ;
return V_272 ;
}
static long F_71 ( unsigned long V_234 )
{
struct V_273 * V_274 ;
long V_275 = 0 ;
V_234 = V_234 / 1000 ;
F_72 (pos, db8500_cpufreq_table) {
V_275 = V_274 -> V_276 ;
if ( V_275 == V_234 )
break;
}
return V_275 * 1000 ;
}
static long F_73 ( unsigned long V_234 )
{
long V_272 = 0 ;
unsigned long V_232 ;
unsigned long V_277 ;
T_1 V_56 ;
V_232 = F_61 ( V_265 ) ;
V_277 = V_234 ;
for ( V_56 = 7 ; ( V_277 > 0 ) && ( V_56 > 0 ) ; V_56 -- ) {
T_5 V_235 ;
V_235 = ( V_56 * V_234 ) ;
( void ) F_60 ( V_235 , V_232 ) ;
if ( V_235 < 6 )
V_235 = 6 ;
else if ( V_235 > 255 )
V_235 = 255 ;
V_235 *= V_232 ;
if ( ( ( 2 * V_235 ) < ( V_56 * V_278 ) ) ||
( ( V_56 * V_279 ) < ( 2 * V_235 ) ) )
continue;
( void ) F_60 ( V_235 , V_56 ) ;
if ( V_234 < V_235 ) {
if ( V_272 == 0 )
V_272 = ( long ) V_235 ;
break;
}
if ( ( V_234 - V_235 ) < V_277 ) {
V_277 = ( V_234 - V_235 ) ;
V_272 = ( long ) V_235 ;
}
}
return V_272 ;
}
static long F_74 ( unsigned long V_234 )
{
T_1 div ;
unsigned long V_232 ;
long V_272 ;
V_232 = F_59 ( V_7 , F_61 ( V_265 ) ,
V_266 ) ;
div = F_68 ( V_232 , V_234 ) ;
V_272 = ( V_232 / ( ( div > 2 ) ? 4 : div ) ) ;
return V_272 ;
}
static long F_75 ( unsigned long V_234 )
{
T_1 div ;
unsigned long V_232 ;
long V_272 ;
V_232 = F_61 ( V_268 ) ;
div = F_68 ( V_232 , V_234 ) ;
V_272 = ( V_232 / F_70 ( div , ( T_1 ) 255 ) ) ;
return V_272 ;
}
long F_76 ( T_2 clock , unsigned long V_234 )
{
if ( clock < V_224 )
return F_69 ( clock , V_234 ) ;
else if ( clock == V_269 )
return F_71 ( V_234 ) ;
else if ( clock == V_230 )
return F_73 ( V_234 ) ;
else if ( ( clock == V_226 ) || ( clock == V_227 ) )
return F_74 ( V_234 ) ;
else if ( ( V_228 <= clock ) && ( clock <= V_229 ) )
return F_75 ( V_234 ) ;
else
return ( long ) F_66 ( clock ) ;
}
static void F_77 ( T_2 clock , unsigned long V_234 )
{
T_1 V_36 ;
T_1 div ;
unsigned long V_232 ;
unsigned long V_21 ;
F_7 ( & V_22 , V_21 ) ;
while ( ( F_3 ( V_23 ) & V_24 ) != 0 )
F_8 () ;
V_36 = F_3 ( V_26 + V_198 [ clock ] . V_199 ) ;
V_232 = F_67 ( ( V_36 | V_198 [ clock ] . V_201 ) ,
V_198 [ clock ] . V_233 ) ;
div = F_68 ( V_232 , V_234 ) ;
if ( V_36 & V_250 ) {
if ( V_198 [ clock ] . V_251 ) {
if ( div > 1 )
V_36 |= V_252 ;
else
V_36 &= ~ V_252 ;
}
} else if ( clock == V_223 ) {
V_36 &= ~ ( V_133 |
V_257 ) ;
if ( div == 3 ) {
T_5 V_56 = ( V_232 * 10 ) ;
( void ) F_60 ( V_56 , 25 ) ;
if ( V_56 <= V_234 ) {
V_36 |= V_257 ;
div = 0 ;
}
}
V_36 |= F_70 ( div , ( T_1 ) 31 ) ;
} else {
V_36 &= ~ V_133 ;
V_36 |= F_70 ( div , ( T_1 ) 31 ) ;
}
F_2 ( V_36 , V_26 + V_198 [ clock ] . V_199 ) ;
F_2 ( 0 , V_23 ) ;
F_9 ( & V_22 , V_21 ) ;
}
static int F_78 ( unsigned long V_234 )
{
struct V_273 * V_274 ;
V_234 = V_234 / 1000 ;
F_72 (pos, db8500_cpufreq_table)
if ( V_274 -> V_276 == V_234 )
break;
if ( V_274 -> V_276 != V_234 )
return - V_47 ;
return F_30 ( V_274 -> V_280 ) ;
}
static int F_79 ( unsigned long V_234 )
{
unsigned long V_232 ;
unsigned long V_277 ;
T_1 V_281 = 0 ;
T_1 V_56 ;
V_232 = F_61 ( V_265 ) ;
V_277 = V_234 ;
for ( V_56 = 7 ; ( V_277 > 0 ) && ( V_56 > 0 ) ; V_56 -- ) {
T_5 V_235 ;
T_5 V_282 ;
V_235 = ( V_56 * V_234 ) ;
( void ) F_60 ( V_235 , V_232 ) ;
if ( V_235 < 6 )
V_235 = 6 ;
else if ( V_235 > 255 )
V_235 = 255 ;
V_282 = ( V_235 * V_232 ) ;
if ( ( ( 2 * V_282 ) < ( V_56 * V_278 ) ) ||
( ( V_56 * V_279 ) < ( 2 * V_282 ) ) )
continue;
( void ) F_60 ( V_282 , V_56 ) ;
if ( V_234 < V_282 ) {
if ( V_281 == 0 )
V_281 = ( ( ( T_1 ) V_235 << V_237 ) |
( V_56 << V_241 ) ) ;
break;
}
if ( ( V_234 - V_282 ) < V_277 ) {
V_277 = ( V_234 - V_282 ) ;
V_281 = ( ( ( T_1 ) V_235 << V_237 ) |
( V_56 << V_241 ) ) ;
}
}
if ( V_281 == 0 )
return - V_47 ;
V_281 |= ( 1 << V_239 ) ;
F_2 ( V_281 , V_7 ) ;
return 0 ;
}
static void F_80 ( T_2 V_215 , unsigned long V_234 )
{
T_1 V_36 ;
T_1 div ;
div = F_68 ( F_59 ( V_7 ,
F_61 ( V_265 ) , V_266 ) , V_234 ) ;
V_216 [ V_215 ] . V_218 = ( div == 1 ) ? V_264 :
( div == 2 ) ? V_263 :
V_262 ;
V_36 = F_3 ( V_9 ) ;
V_36 &= ~ V_216 [ V_215 ] . V_217 ;
V_36 |= ( V_216 [ V_215 ] . V_218 << V_216 [ V_215 ] . V_220 ) ;
F_2 ( V_36 , V_9 ) ;
}
static void F_81 ( T_2 V_215 , unsigned long V_234 )
{
T_1 V_36 ;
T_1 div ;
div = F_68 ( F_61 ( V_268 ) , V_234 ) ;
V_36 = F_3 ( V_11 ) ;
V_36 &= ~ V_221 [ V_215 ] . V_58 ;
V_36 |= ( F_70 ( div , ( T_1 ) 255 ) << V_221 [ V_215 ] . V_267 ) ;
F_2 ( V_36 , V_11 ) ;
}
int F_82 ( T_2 clock , unsigned long V_234 )
{
if ( clock < V_224 )
F_77 ( clock , V_234 ) ;
else if ( clock == V_269 )
return F_78 ( V_234 ) ;
else if ( clock == V_230 )
return F_79 ( V_234 ) ;
else if ( ( clock == V_226 ) || ( clock == V_227 ) )
F_80 ( ( clock - V_226 ) , V_234 ) ;
else if ( ( V_228 <= clock ) && ( clock <= V_229 ) )
F_81 ( ( clock - V_228 ) , V_234 ) ;
return 0 ;
}
int F_83 ( T_2 V_73 )
{
if ( ( V_73 > V_283 ) ||
( V_73 < V_284 ) )
return - V_47 ;
F_31 ( & V_285 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_286 , ( V_41 + V_287 ) ) ;
F_17 ( ( ( V_288 << 4 ) | V_289 ) ,
( V_41 + V_290 ) ) ;
F_17 ( V_289 ,
( V_41 + V_291 ) ) ;
F_17 ( V_73 , ( V_41 + V_292 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_285 . V_120 ) ;
F_33 ( & V_285 . V_79 ) ;
return 0 ;
}
int F_84 ( T_2 V_293 )
{
F_31 ( & V_285 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_293 , ( V_41 + V_294 ) ) ;
F_17 ( V_295 , ( V_41 + V_287 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_285 . V_120 ) ;
F_33 ( & V_285 . V_79 ) ;
return 0 ;
}
int F_85 ( T_2 V_296 , T_2 V_297 )
{
F_31 ( & V_285 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_296 , ( V_41 + V_298 ) ) ;
F_17 ( V_297 , ( V_41 + V_299 ) ) ;
F_17 ( ( V_300 | V_301 ) ,
( V_41 + V_302 ) ) ;
F_17 ( V_303 , ( V_41 + V_287 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_285 . V_120 ) ;
F_33 ( & V_285 . V_79 ) ;
return 0 ;
}
static int F_86 ( T_4 V_36 )
{
F_31 ( & V_285 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_87 ( V_36 , ( V_41 + V_304 ) ) ;
F_17 ( V_305 , ( V_41 + V_287 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_285 . V_120 ) ;
F_33 ( & V_285 . V_79 ) ;
return 0 ;
}
int F_88 ( T_4 V_306 )
{
if ( V_306 == 0xFFFF )
return - V_47 ;
return F_86 ( V_306 ) ;
}
int F_89 ( void )
{
return F_86 ( 0xFFFF ) ;
}
static int F_90 ( T_2 V_307 , T_2 V_308 , T_2 V_309 , T_2 V_310 , T_2 V_311 )
{
F_31 ( & V_285 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 4 ) )
F_8 () ;
F_17 ( V_308 , ( V_41 + V_312 ) ) ;
F_17 ( V_309 , ( V_41 + V_313 ) ) ;
F_17 ( V_310 , ( V_41 + V_314 ) ) ;
F_17 ( V_311 , ( V_41 + V_315 ) ) ;
F_17 ( V_307 , ( V_41 + V_287 ) ) ;
F_2 ( F_23 ( 4 ) , V_87 ) ;
F_32 ( & V_285 . V_120 ) ;
F_33 ( & V_285 . V_79 ) ;
return 0 ;
}
int F_91 ( T_2 V_316 , bool V_317 )
{
F_21 ( V_316 == 0 || V_316 > 0xf ) ;
return F_90 ( V_318 , V_316 , 0 , 0 ,
V_317 ? V_319 :
V_320 ) ;
}
int F_92 ( T_2 V_321 )
{
return F_90 ( V_322 , V_321 , 0 , 0 , 0 ) ;
}
int F_93 ( T_2 V_321 )
{
return F_90 ( V_323 , V_321 , 0 , 0 , 0 ) ;
}
int F_94 ( T_2 V_321 )
{
return F_90 ( V_324 , V_321 , 0 , 0 , 0 ) ;
}
int F_95 ( T_2 V_321 , T_1 V_325 )
{
return F_90 ( V_326 ,
( V_321 & V_327 ) |
( T_2 ) ( ( V_325 << 4 ) & 0xf0 ) ,
( T_2 ) ( ( V_325 >> 4 ) & 0xff ) ,
( T_2 ) ( ( V_325 >> 12 ) & 0xff ) ,
( T_2 ) ( ( V_325 >> 20 ) & 0xff ) ) ;
}
int F_96 ( T_2 V_328 , T_2 V_32 , T_2 * V_33 , T_2 V_329 )
{
int V_56 ;
if ( V_329 != 1 )
return - V_47 ;
F_31 ( & V_330 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 5 ) )
F_8 () ;
F_17 ( 0 , ( V_41 + V_331 ) ) ;
F_17 ( F_97 ( V_328 ) , ( V_41 + V_332 ) ) ;
F_17 ( V_333 , ( V_41 + V_334 ) ) ;
F_17 ( V_32 , ( V_41 + V_335 ) ) ;
F_17 ( 0 , ( V_41 + V_336 ) ) ;
F_2 ( F_23 ( 5 ) , V_87 ) ;
if ( ! F_46 ( & V_330 . V_120 ,
F_47 ( 20000 ) ) ) {
F_39 ( L_2 ,
V_134 ) ;
V_56 = - V_123 ;
} else {
V_56 = ( ( V_330 . V_121 . V_168 == V_337 ) ? 0 : - V_123 ) ;
}
if ( ! V_56 )
* V_33 = V_330 . V_121 . V_33 ;
F_33 ( & V_330 . V_79 ) ;
return V_56 ;
}
int F_98 ( T_2 V_328 , T_2 V_32 , T_2 * V_33 , T_2 * V_35 , T_2 V_329 )
{
int V_56 ;
if ( V_329 != 1 )
return - V_47 ;
F_31 ( & V_330 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 5 ) )
F_8 () ;
F_17 ( ~ * V_35 , ( V_41 + V_331 ) ) ;
F_17 ( F_99 ( V_328 ) , ( V_41 + V_332 ) ) ;
F_17 ( V_333 , ( V_41 + V_334 ) ) ;
F_17 ( V_32 , ( V_41 + V_335 ) ) ;
F_17 ( * V_33 , ( V_41 + V_336 ) ) ;
F_2 ( F_23 ( 5 ) , V_87 ) ;
if ( ! F_46 ( & V_330 . V_120 ,
F_47 ( 20000 ) ) ) {
F_39 ( L_2 ,
V_134 ) ;
V_56 = - V_123 ;
} else {
V_56 = ( ( V_330 . V_121 . V_168 == V_338 ) ? 0 : - V_123 ) ;
}
F_33 ( & V_330 . V_79 ) ;
return V_56 ;
}
int F_100 ( T_2 V_328 , T_2 V_32 , T_2 * V_33 , T_2 V_329 )
{
T_2 V_35 = ~ 0 ;
return F_98 ( V_328 , V_32 , V_33 , & V_35 , V_329 ) ;
}
int F_101 ( void )
{
T_1 V_36 ;
int V_203 = 0 ;
F_31 ( & V_78 . V_339 ) ;
V_36 = F_3 ( V_340 ) ;
if ( V_36 & V_341 )
goto V_72;
F_102 ( & V_342 , 1 ) ;
V_36 |= V_343 ;
F_2 ( V_36 , V_340 ) ;
F_4 ( 31 ) ;
V_36 |= V_341 ;
F_2 ( V_36 , V_340 ) ;
if ( ! F_46 ( & V_78 . V_344 ,
F_47 ( 5000 ) ) ) {
F_103 ( L_3 ,
V_134 ) ;
V_203 = - V_345 ;
}
V_72:
F_33 ( & V_78 . V_339 ) ;
return V_203 ;
}
void F_104 ( void )
{
T_1 V_36 ;
F_31 ( & V_78 . V_339 ) ;
V_36 = F_3 ( V_340 ) ;
if ( ! ( V_36 & V_341 ) )
goto V_72;
F_2 ( ( V_36 & ~ V_341 ) ,
V_340 ) ;
if ( ! F_46 ( & V_78 . V_344 ,
F_47 ( 5000 ) ) ) {
F_103 ( L_3 ,
V_134 ) ;
}
F_102 ( & V_342 , 0 ) ;
V_72:
F_33 ( & V_78 . V_339 ) ;
}
bool F_105 ( void )
{
return ( F_106 ( & V_342 ) != 0 ) ;
}
void F_107 ( T_4 V_346 )
{
F_87 ( V_346 , ( V_41 + V_347 ) ) ;
F_2 ( 1 , V_348 ) ;
}
T_4 F_108 ( void )
{
return F_109 ( V_41 + V_347 ) ;
}
void F_110 ( void )
{
F_31 ( & V_114 . V_79 ) ;
while ( F_3 ( V_80 ) & F_23 ( 1 ) )
F_8 () ;
F_17 ( V_349 , ( V_41 + V_116 ) ) ;
F_2 ( F_23 ( 1 ) , V_87 ) ;
F_32 ( & V_114 . V_120 ) ;
F_33 ( & V_114 . V_79 ) ;
}
static void F_111 ( void )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_79 , V_21 ) ;
while ( F_3 ( V_80 ) & F_23 ( 0 ) )
F_8 () ;
F_17 ( V_350 , ( V_41 + V_82 ) ) ;
F_2 ( F_23 ( 0 ) , V_87 ) ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
static inline void F_112 ( T_2 V_215 , T_2 V_89 )
{
F_113 ( L_4 ,
V_89 , V_215 ) ;
}
static bool F_114 ( void )
{
bool V_56 ;
T_1 V_351 ;
unsigned int V_215 ;
T_2 V_89 ;
V_89 = F_15 ( V_41 + V_352 ) ;
switch ( V_89 ) {
case V_353 :
case V_354 :
if ( F_15 ( V_41 + V_108 ) & 1 )
V_351 = F_3 ( V_41 + V_355 ) ;
else
V_351 = F_3 ( V_41 + V_356 ) ;
if ( V_351 & ( V_99 | V_100 ) )
F_115 ( & V_78 . V_344 ) ;
if ( V_351 & V_357 )
F_115 ( & V_186 . V_193 ) ;
V_351 &= V_78 . V_96 . V_97 ;
for ( V_215 = 0 ; V_215 < V_358 ; V_215 ++ ) {
if ( V_351 & V_359 [ V_215 ] )
F_116 ( F_117 ( V_360 , V_215 ) ) ;
}
V_56 = true ;
break;
default:
F_112 ( 0 , V_89 ) ;
V_56 = false ;
break;
}
F_2 ( F_23 ( 0 ) , V_361 ) ;
return V_56 ;
}
static bool F_118 ( void )
{
V_114 . V_121 . V_89 = F_15 ( V_41 + V_116 ) ;
V_114 . V_121 . V_122 = F_15 ( V_41 +
V_124 ) ;
V_114 . V_121 . V_135 = F_15 ( V_41 +
V_140 ) ;
V_114 . V_121 . V_143 = F_15 ( V_41 +
V_362 ) ;
F_2 ( F_23 ( 1 ) , V_361 ) ;
F_115 ( & V_114 . V_120 ) ;
return false ;
}
static bool F_119 ( void )
{
V_163 . V_121 . V_168 = F_15 ( V_41 + V_363 ) ;
F_2 ( F_23 ( 2 ) , V_361 ) ;
F_115 ( & V_163 . V_120 ) ;
return false ;
}
static bool F_120 ( void )
{
F_2 ( F_23 ( 3 ) , V_361 ) ;
return false ;
}
static bool F_121 ( void )
{
T_2 V_89 ;
bool V_364 = true ;
V_89 = F_15 ( V_41 + V_287 ) ;
switch ( V_89 ) {
case V_286 :
case V_295 :
case V_303 :
case V_305 :
case V_318 :
case V_322 :
case V_323 :
case V_326 :
case V_324 :
break;
default:
F_112 ( 4 , V_89 ) ;
V_364 = false ;
break;
}
F_2 ( F_23 ( 4 ) , V_361 ) ;
if ( V_364 )
F_115 ( & V_285 . V_120 ) ;
return false ;
}
static bool F_122 ( void )
{
V_330 . V_121 . V_168 = F_15 ( V_41 + V_365 ) ;
V_330 . V_121 . V_33 = F_15 ( V_41 + V_366 ) ;
F_2 ( F_23 ( 5 ) , V_361 ) ;
F_115 ( & V_330 . V_120 ) ;
return false ;
}
static bool F_123 ( void )
{
F_2 ( F_23 ( 6 ) , V_361 ) ;
return false ;
}
static bool F_124 ( void )
{
F_2 ( F_23 ( 7 ) , V_361 ) ;
return false ;
}
static T_6 F_125 ( int V_367 , void * V_368 )
{
T_1 V_57 ;
T_2 V_215 ;
T_6 V_56 ;
V_57 = ( F_3 ( V_369 ) & V_370 ) ;
if ( F_126 ( ! V_57 ) )
return V_371 ;
V_56 = V_372 ;
for ( V_215 = 0 ; V_57 ; V_215 ++ ) {
if ( V_57 & F_23 ( V_215 ) ) {
V_57 -= F_23 ( V_215 ) ;
if ( V_373 [ V_215 ] ( ) )
V_56 = V_374 ;
}
}
return V_56 ;
}
static T_6 F_127 ( int V_367 , void * V_368 )
{
F_111 () ;
return V_372 ;
}
static void F_128 ( struct V_375 * V_120 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_79 , V_21 ) ;
F_25 () ;
F_9 ( & V_78 . V_79 , V_21 ) ;
}
static void F_129 ( struct V_376 * V_235 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_377 , V_21 ) ;
V_78 . V_96 . V_97 &= ~ V_359 [ V_235 -> V_378 ] ;
F_9 ( & V_78 . V_377 , V_21 ) ;
if ( V_235 -> V_367 != V_379 )
F_130 ( & V_78 . V_380 ) ;
}
static void F_131 ( struct V_376 * V_235 )
{
unsigned long V_21 ;
F_7 ( & V_78 . V_377 , V_21 ) ;
V_78 . V_96 . V_97 |= V_359 [ V_235 -> V_378 ] ;
F_9 ( & V_78 . V_377 , V_21 ) ;
if ( V_235 -> V_367 != V_379 )
F_130 ( & V_78 . V_380 ) ;
}
static void F_132 ( struct V_376 * V_235 )
{
}
static T_7 char * F_133 ( T_1 V_381 )
{
switch ( V_381 ) {
case V_382 :
return L_5 ;
case V_383 :
return L_6 ;
case V_384 :
return L_7 ;
case V_385 :
return L_8 ;
case V_386 :
return L_9 ;
case V_387 :
return L_10 ;
case V_388 :
return L_11 ;
case V_389 :
return L_12 ;
case V_390 :
return L_13 ;
case V_391 :
return L_14 ;
case V_392 :
return L_15 ;
case V_393 :
return L_16 ;
case V_394 :
return L_17 ;
case V_395 :
return L_18 ;
case V_396 :
return L_19 ;
case V_397 :
return L_20 ;
case V_398 :
return L_21 ;
default:
return L_22 ;
}
}
static int F_134 ( struct V_399 * V_235 , unsigned int V_400 ,
T_8 V_378 )
{
F_135 ( V_400 , & V_401 ,
V_402 ) ;
return 0 ;
}
static int F_136 ( struct V_403 * V_404 )
{
int V_1 ;
V_360 = F_137 (
V_404 , V_358 , 0 ,
& V_405 , NULL ) ;
if ( ! V_360 ) {
F_39 ( L_23 ) ;
return - V_406 ;
}
for ( V_1 = 0 ; V_1 < V_358 ; V_1 ++ )
F_138 ( V_360 , V_1 ) ;
return 0 ;
}
static void F_139 ( struct V_407 * V_408 ,
T_1 V_409 )
{
struct V_410 * V_411 ;
void T_3 * V_412 ;
T_1 V_40 ;
V_411 = F_140 ( V_408 , V_413 ,
L_24 ) ;
if ( ! V_411 ) {
F_141 ( & V_408 -> V_414 ,
L_25 ) ;
return;
}
V_412 = F_142 ( V_411 -> V_415 , F_143 ( V_411 ) ) ;
if ( ! V_412 ) {
F_141 ( & V_408 -> V_414 , L_26 ) ;
return;
}
V_40 = F_3 ( V_412 + V_409 ) ;
V_38 . V_40 . V_381 = ( V_40 & 0xFF ) ;
V_38 . V_40 . V_416 = ( V_40 >> 8 ) & 0xFF ;
V_38 . V_40 . V_417 = ( V_40 >> 16 ) & 0xFF ;
V_38 . V_40 . V_418 = ( V_40 >> 24 ) & 0xFF ;
strncpy ( V_38 . V_40 . V_419 ,
F_133 ( V_38 . V_40 . V_381 ) ,
V_420 ) ;
V_38 . V_39 = true ;
F_144 ( L_27 ,
V_38 . V_40 . V_419 ,
V_38 . V_40 . V_381 ,
V_38 . V_40 . V_416 ,
V_38 . V_40 . V_417 ,
V_38 . V_40 . V_418 ) ;
F_145 ( V_412 ) ;
}
void T_7 F_146 ( T_1 V_421 , T_1 V_329 )
{
V_26 = F_142 ( V_421 , V_329 ) ;
if ( ! V_26 )
F_39 ( L_28 , V_134 ) ;
F_147 ( & V_78 . V_79 ) ;
F_147 ( & V_78 . V_377 ) ;
F_148 ( & V_78 . V_339 ) ;
F_149 ( & V_78 . V_344 ) ;
F_148 ( & V_114 . V_79 ) ;
F_149 ( & V_114 . V_120 ) ;
V_114 . V_135 = V_118 ;
F_148 ( & V_163 . V_79 ) ;
F_149 ( & V_163 . V_120 ) ;
F_147 ( & V_163 . V_181 ) ;
F_147 ( & V_186 . V_79 ) ;
F_148 ( & V_186 . V_187 ) ;
F_149 ( & V_186 . V_193 ) ;
F_148 ( & V_285 . V_79 ) ;
F_149 ( & V_285 . V_120 ) ;
F_148 ( & V_330 . V_79 ) ;
F_149 ( & V_330 . V_120 ) ;
F_150 ( & V_78 . V_380 , F_128 ) ;
}
static void T_7 F_151 ( void )
{
T_1 V_36 ;
V_36 = F_3 ( V_422 ) ;
V_36 &= ~ ( V_423 |
V_424 ) ;
F_2 ( V_36 , ( V_422 ) ) ;
}
static void F_152 ( void )
{
if ( F_14 () ) {
V_425 [ 3 ] . V_276 = 1000000 ;
V_425 [ 3 ] . V_280 = V_426 ;
}
}
static int F_153 ( struct V_427 * V_428 )
{
struct V_403 * V_404 ;
struct V_410 V_429 ;
const struct V_430 V_431 = {
. V_432 = L_29 ,
. V_433 = L_30 ,
. V_321 = V_434 ,
. V_435 = & V_429 ,
. V_436 = 1 ,
} ;
if ( ! V_428 -> V_437 )
return - V_438 ;
F_154 (parent->of_node, np) {
if ( F_155 ( V_404 , V_431 . V_433 ) )
break;
}
if ( ! V_404 ) {
F_156 ( V_428 , L_31 ) ;
return - V_438 ;
}
F_157 ( V_404 , & V_429 , 1 ) ;
return F_158 ( V_428 , 0 , & V_431 , 1 , NULL , 0 , NULL ) ;
}
static int F_159 ( struct V_407 * V_408 )
{
struct V_403 * V_404 = V_408 -> V_414 . V_437 ;
int V_367 = 0 , V_439 = 0 ;
struct V_410 * V_411 ;
V_411 = F_140 ( V_408 , V_413 , L_32 ) ;
if ( ! V_411 ) {
F_141 ( & V_408 -> V_414 , L_33 ) ;
return - V_47 ;
}
V_26 = F_160 ( & V_408 -> V_414 , V_411 -> V_415 , F_143 ( V_411 ) ) ;
if ( ! V_26 ) {
F_141 ( & V_408 -> V_414 ,
L_34 ) ;
return - V_440 ;
}
F_151 () ;
F_139 ( V_408 , V_441 ) ;
V_411 = F_140 ( V_408 , V_413 , L_35 ) ;
if ( ! V_411 ) {
F_141 ( & V_408 -> V_414 , L_36 ) ;
return - V_47 ;
}
V_41 = F_160 ( & V_408 -> V_414 , V_411 -> V_415 ,
F_143 ( V_411 ) ) ;
if ( ! V_41 ) {
F_141 ( & V_408 -> V_414 ,
L_37 ) ;
return - V_440 ;
}
F_2 ( V_370 , V_361 ) ;
V_367 = F_161 ( V_408 , 0 ) ;
if ( V_367 <= 0 ) {
F_141 ( & V_408 -> V_414 , L_38 ) ;
return V_367 ;
}
V_439 = F_162 ( V_367 , F_125 ,
F_127 , V_442 , L_32 , NULL ) ;
if ( V_439 < 0 ) {
F_39 ( L_39 ) ;
return V_439 ;
}
F_136 ( V_404 ) ;
F_163 ( V_283 ) ;
F_152 () ;
V_439 = F_158 ( & V_408 -> V_414 , 0 , V_443 ,
F_38 ( V_443 ) , NULL , 0 , V_360 ) ;
if ( V_439 ) {
F_39 ( L_40 ) ;
return V_439 ;
}
if ( ! F_164 ( L_41 ) ) {
V_439 = F_158 ( & V_408 -> V_414 , 0 , V_444 ,
F_38 ( V_444 ) , NULL , 0 ,
V_360 ) ;
if ( V_439 ) {
F_165 ( & V_408 -> V_414 ) ;
F_39 ( L_40 ) ;
return V_439 ;
}
}
V_439 = F_153 ( & V_408 -> V_414 ) ;
if ( V_439 ) {
F_165 ( & V_408 -> V_414 ) ;
F_39 ( L_42 ) ;
return V_439 ;
}
F_144 ( L_43 ) ;
return V_439 ;
}
static int T_7 F_166 ( void )
{
return F_167 ( & V_445 ) ;
}
