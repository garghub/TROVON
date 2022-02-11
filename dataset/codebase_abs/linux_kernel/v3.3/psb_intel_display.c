static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 ;
if ( F_2 ( V_3 , V_5 ) )
V_4 = & V_6 [ V_7 ] ;
else
V_4 = & V_6 [ V_8 ] ;
return V_4 ;
}
static void F_3 ( int V_9 , struct V_10 * clock )
{
clock -> V_11 = 5 * ( clock -> V_12 + 2 ) + ( clock -> V_13 + 2 ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = V_9 * clock -> V_11 / ( clock -> V_18 + 2 ) ;
clock -> V_19 = clock -> V_17 / clock -> V_14 ;
}
static void F_4 ( int V_9 , struct V_10 * clock )
{
clock -> V_11 = 5 * ( clock -> V_12 + 2 ) + ( clock -> V_13 + 2 ) ;
clock -> V_14 = clock -> V_15 * clock -> V_16 ;
clock -> V_17 = V_9 * clock -> V_11 / ( clock -> V_18 + 2 ) ;
clock -> V_19 = clock -> V_17 / clock -> V_14 ;
}
static void F_5 ( struct V_20 * V_21 , int V_9 ,
struct V_10 * clock )
{
return F_4 ( V_9 , clock ) ;
}
bool F_2 ( struct V_2 * V_3 , int type )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_25 ;
F_6 (l_entry, &mode_config->connector_list, head) {
if ( V_25 -> V_26 && V_25 -> V_26 -> V_3 == V_3 ) {
struct V_27 * V_27 =
F_7 ( V_25 ) ;
if ( V_27 -> type == type )
return true ;
}
}
return false ;
}
static bool F_8 ( struct V_2 * V_3 ,
struct V_10 * clock )
{
const struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( clock -> V_15 < V_4 -> V_15 . V_28 || V_4 -> V_15 . V_29 < clock -> V_15 )
F_9 ( L_1 ) ;
if ( clock -> V_14 < V_4 -> V_14 . V_28 || V_4 -> V_14 . V_29 < clock -> V_14 )
F_9 ( L_2 ) ;
if ( clock -> V_13 < V_4 -> V_13 . V_28 || V_4 -> V_13 . V_29 < clock -> V_13 )
F_9 ( L_3 ) ;
if ( clock -> V_12 < V_4 -> V_12 . V_28 || V_4 -> V_12 . V_29 < clock -> V_12 )
F_9 ( L_4 ) ;
if ( clock -> V_12 <= clock -> V_13 )
F_9 ( L_5 ) ;
if ( clock -> V_11 < V_4 -> V_11 . V_28 || V_4 -> V_11 . V_29 < clock -> V_11 )
F_9 ( L_6 ) ;
if ( clock -> V_18 < V_4 -> V_18 . V_28 || V_4 -> V_18 . V_29 < clock -> V_18 )
F_9 ( L_7 ) ;
if ( clock -> V_17 < V_4 -> V_17 . V_28 || V_4 -> V_17 . V_29 < clock -> V_17 )
F_9 ( L_8 ) ;
if ( clock -> V_19 < V_4 -> V_19 . V_28 || V_4 -> V_19 . V_29 < clock -> V_19 )
F_9 ( L_9 ) ;
return true ;
}
static bool F_10 ( struct V_2 * V_3 , int V_30 ,
int V_9 ,
struct V_10 * V_31 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_10 clock ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_32 = V_30 ;
if ( F_2 ( V_3 , V_5 ) &&
( F_11 ( V_33 ) & V_34 ) != 0 ) {
if ( ( F_11 ( V_33 ) & V_35 ) ==
V_36 )
clock . V_16 = V_4 -> V_16 . V_37 ;
else
clock . V_16 = V_4 -> V_16 . V_38 ;
} else {
if ( V_30 < V_4 -> V_16 . V_39 )
clock . V_16 = V_4 -> V_16 . V_38 ;
else
clock . V_16 = V_4 -> V_16 . V_37 ;
}
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
for ( clock . V_12 = V_4 -> V_12 . V_28 ; clock . V_12 <= V_4 -> V_12 . V_29 ;
clock . V_12 ++ ) {
for ( clock . V_13 = V_4 -> V_13 . V_28 ;
clock . V_13 < clock . V_12 && clock . V_13 <= V_4 -> V_13 . V_29 ;
clock . V_13 ++ ) {
for ( clock . V_18 = V_4 -> V_18 . V_28 ;
clock . V_18 <= V_4 -> V_18 . V_29 ; clock . V_18 ++ ) {
for ( clock . V_15 = V_4 -> V_15 . V_28 ;
clock . V_15 <= V_4 -> V_15 . V_29 ;
clock . V_15 ++ ) {
int V_40 ;
F_5 ( V_21 , V_9 , & clock ) ;
if ( ! F_8
( V_3 , & clock ) )
continue;
V_40 = abs ( clock . V_19 - V_30 ) ;
if ( V_40 < V_32 ) {
* V_31 = clock ;
V_32 = V_40 ;
}
}
}
}
}
return V_32 != V_30 ;
}
void F_12 ( struct V_20 * V_21 )
{
F_13 ( 20 ) ;
}
int F_14 ( struct V_2 * V_3 ,
int V_41 , int V_42 , struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_46 * V_47 = F_16 ( V_3 -> V_48 ) ;
int V_49 = V_45 -> V_49 ;
unsigned long V_50 , V_51 ;
int V_52 = ( V_49 == 0 ? V_53 : V_54 ) ;
int V_55 = ( V_49 == 0 ? V_56 : V_57 ) ;
int V_58 = ( V_49 == 0 ) ? V_59 : V_60 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
T_1 V_64 ;
int V_65 = 0 ;
if ( ! F_17 ( V_21 , true ) )
return 0 ;
if ( ! V_3 -> V_48 ) {
F_18 ( V_21 -> V_21 , L_10 ) ;
goto V_66;
}
V_65 = F_19 ( V_47 -> V_67 ) ;
if ( V_65 < 0 )
goto V_68;
V_50 = V_47 -> V_67 -> V_51 ;
V_51 = V_42 * V_3 -> V_48 -> V_69 [ 0 ] + V_41 * ( V_3 -> V_48 -> V_70 / 8 ) ;
F_20 ( V_58 , V_3 -> V_48 -> V_69 [ 0 ] ) ;
V_64 = F_11 ( V_61 ) ;
V_64 &= ~ V_71 ;
switch ( V_3 -> V_48 -> V_70 ) {
case 8 :
V_64 |= V_72 ;
break;
case 16 :
if ( V_3 -> V_48 -> V_73 == 15 )
V_64 |= V_74 ;
else
V_64 |= V_75 ;
break;
case 24 :
case 32 :
V_64 |= V_76 ;
break;
default:
F_21 ( V_21 -> V_21 , L_11 ) ;
V_65 = - V_77 ;
F_22 ( V_47 -> V_67 ) ;
goto V_68;
}
F_20 ( V_61 , V_64 ) ;
if ( 0 ) {
F_20 ( V_52 , V_51 ) ;
F_11 ( V_52 ) ;
F_20 ( V_55 , V_50 ) ;
F_11 ( V_55 ) ;
} else {
F_20 ( V_52 , V_50 + V_51 ) ;
F_11 ( V_52 ) ;
}
V_66:
if ( V_44 )
F_22 ( F_16 ( V_44 ) -> V_67 ) ;
V_68:
F_23 ( V_21 ) ;
return V_65 ;
}
static void F_24 ( struct V_2 * V_3 , int V_78 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
int V_79 = ( V_49 == 0 ) ? V_80 : V_81 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
int V_82 = ( V_49 == 0 ) ? V_53 : V_54 ;
int V_83 = ( V_49 == 0 ) ? V_84 : V_85 ;
T_1 V_86 ;
bool V_87 ;
switch ( V_78 ) {
case V_88 :
case V_89 :
case V_90 :
V_86 = F_11 ( V_79 ) ;
if ( ( V_86 & V_91 ) == 0 ) {
F_20 ( V_79 , V_86 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_79 , V_86 | V_91 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_79 , V_86 | V_91 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
}
V_86 = F_11 ( V_83 ) ;
if ( ( V_86 & V_92 ) == 0 )
F_20 ( V_83 , V_86 | V_92 ) ;
V_86 = F_11 ( V_61 ) ;
if ( ( V_86 & V_93 ) == 0 ) {
F_20 ( V_61 ,
V_86 | V_93 ) ;
F_20 ( V_82 , F_11 ( V_82 ) ) ;
}
F_26 ( V_3 ) ;
break;
case V_94 :
F_20 ( V_95 , V_96 ) ;
V_86 = F_11 ( V_61 ) ;
if ( ( V_86 & V_93 ) != 0 ) {
F_20 ( V_61 ,
V_86 & ~ V_93 ) ;
F_20 ( V_82 , F_11 ( V_82 ) ) ;
F_11 ( V_82 ) ;
}
V_86 = F_11 ( V_83 ) ;
if ( ( V_86 & V_92 ) != 0 ) {
F_20 ( V_83 , V_86 & ~ V_92 ) ;
F_11 ( V_83 ) ;
}
F_12 ( V_21 ) ;
V_86 = F_11 ( V_79 ) ;
if ( ( V_86 & V_91 ) != 0 ) {
F_20 ( V_79 , V_86 & ~ V_91 ) ;
F_11 ( V_79 ) ;
}
F_25 ( 150 ) ;
break;
}
V_87 = V_3 -> V_87 && V_78 != V_94 ;
F_20 ( V_97 , 0x3F3E ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_98 * V_99 = V_3 -> V_100 ;
V_99 -> V_101 ( V_3 , V_94 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_98 * V_99 = V_3 -> V_100 ;
V_99 -> V_101 ( V_3 , V_88 ) ;
}
void F_29 ( struct V_102 * V_26 )
{
struct V_103 * V_104 =
V_26 -> V_100 ;
V_104 -> V_101 ( V_26 , V_94 ) ;
}
void F_30 ( struct V_102 * V_26 )
{
struct V_103 * V_104 =
V_26 -> V_100 ;
V_104 -> V_101 ( V_26 , V_88 ) ;
}
void F_31 ( struct V_102 * V_26 )
{
struct V_27 * V_105 = F_32 ( V_26 ) ;
F_33 ( V_26 ) ;
F_34 ( V_105 ) ;
}
static bool F_35 ( struct V_2 * V_3 ,
struct V_106 * V_78 ,
struct V_106 * V_107 )
{
return true ;
}
static int F_36 ( struct V_20 * V_21 )
{
T_1 V_108 ;
V_108 = F_11 ( V_109 ) ;
if ( ( V_108 & V_110 ) == 0 )
return - 1 ;
return 1 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_106 * V_78 ,
struct V_106 * V_107 ,
int V_41 , int V_42 ,
struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_98 * V_99 = V_3 -> V_100 ;
int V_49 = V_45 -> V_49 ;
int V_111 = ( V_49 == 0 ) ? V_112 : V_113 ;
int V_79 = ( V_49 == 0 ) ? V_80 : V_81 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
int V_83 = ( V_49 == 0 ) ? V_84 : V_85 ;
int V_114 = ( V_49 == 0 ) ? V_115 : V_116 ;
int V_117 = ( V_49 == 0 ) ? V_118 : V_119 ;
int V_120 = ( V_49 == 0 ) ? V_121 : V_122 ;
int V_123 = ( V_49 == 0 ) ? V_124 : V_125 ;
int V_126 = ( V_49 == 0 ) ? V_127 : V_128 ;
int V_129 = ( V_49 == 0 ) ? V_130 : V_131 ;
int V_132 = ( V_49 == 0 ) ? V_133 : V_134 ;
int V_135 = ( V_49 == 0 ) ? V_136 : V_137 ;
int V_138 = ( V_49 == 0 ) ? V_139 : V_140 ;
int V_9 ;
struct V_10 clock ;
T_1 V_141 = 0 , V_142 = 0 , V_64 , V_143 ;
bool V_144 , V_145 = false , V_146 = false ;
bool V_147 = false , V_148 = false , V_149 = false ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_150 ;
if ( V_3 -> V_48 == NULL ) {
V_99 -> V_151 ( V_3 , V_41 , V_42 , V_44 ) ;
return 0 ;
}
F_6 (connector, &mode_config->connector_list, head) {
struct V_27 * V_27 =
F_7 ( V_150 ) ;
if ( ! V_150 -> V_26
|| V_150 -> V_26 -> V_3 != V_3 )
continue;
switch ( V_27 -> type ) {
case V_5 :
V_148 = true ;
break;
case V_152 :
V_145 = true ;
break;
case V_153 :
V_146 = true ;
break;
case V_154 :
V_149 = true ;
break;
case V_155 :
V_147 = true ;
break;
}
}
V_9 = 96000 ;
V_144 = F_10 ( V_3 , V_107 -> clock , V_9 ,
& clock ) ;
if ( ! V_144 ) {
F_21 ( V_21 -> V_21 , L_12 ) ;
return 0 ;
}
V_142 = clock . V_18 << 16 | clock . V_12 << 8 | clock . V_13 ;
V_141 = V_156 ;
if ( V_148 ) {
V_141 |= V_157 ;
V_141 |= V_158 ;
} else
V_141 |= V_159 ;
if ( V_145 ) {
int V_160 =
V_107 -> clock / V_78 -> clock ;
V_141 |= V_158 ;
V_141 |=
( V_160 - 1 ) << V_161 ;
}
V_141 |= ( 1 << ( clock . V_15 - 1 ) ) << 16 ;
switch ( clock . V_16 ) {
case 5 :
V_141 |= V_162 ;
break;
case 7 :
V_141 |= V_163 ;
break;
case 10 :
V_141 |= V_164 ;
break;
case 14 :
V_141 |= V_165 ;
break;
}
if ( V_149 ) {
V_141 |= 3 ;
}
V_141 |= V_166 ;
V_143 = F_11 ( V_83 ) ;
V_64 = V_167 ;
if ( V_49 == 0 )
V_64 |= V_168 ;
else
V_64 |= V_169 ;
V_64 |= V_93 ;
V_143 |= V_92 ;
V_141 |= V_91 ;
if ( F_36 ( V_21 ) == V_49 )
F_20 ( V_109 , 0 ) ;
F_38 ( V_78 ) ;
if ( V_141 & V_91 ) {
F_20 ( V_111 , V_142 ) ;
F_20 ( V_79 , V_141 & ~ V_91 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
}
if ( V_148 ) {
T_1 V_170 = F_11 ( V_33 ) ;
V_170 &= ~ V_171 ;
if ( V_49 == 1 )
V_170 |= V_171 ;
V_170 |= V_34 | V_172 ;
V_170 &= ~ ( V_173 | V_36 ) ;
if ( clock . V_16 == 7 )
V_170 |= V_173 | V_36 ;
F_20 ( V_33 , V_170 ) ;
F_11 ( V_33 ) ;
}
F_20 ( V_111 , V_142 ) ;
F_20 ( V_79 , V_141 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_79 , V_141 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_114 , ( V_107 -> V_174 - 1 ) |
( ( V_107 -> V_175 - 1 ) << 16 ) ) ;
F_20 ( V_117 , ( V_107 -> V_176 - 1 ) |
( ( V_107 -> V_177 - 1 ) << 16 ) ) ;
F_20 ( V_120 , ( V_107 -> V_178 - 1 ) |
( ( V_107 -> V_179 - 1 ) << 16 ) ) ;
F_20 ( V_123 , ( V_107 -> V_180 - 1 ) |
( ( V_107 -> V_181 - 1 ) << 16 ) ) ;
F_20 ( V_126 , ( V_107 -> V_182 - 1 ) |
( ( V_107 -> V_183 - 1 ) << 16 ) ) ;
F_20 ( V_129 , ( V_107 -> V_184 - 1 ) |
( ( V_107 -> V_185 - 1 ) << 16 ) ) ;
F_20 ( V_132 ,
( ( V_78 -> V_186 - 1 ) << 16 ) | ( V_78 -> V_187 - 1 ) ) ;
F_20 ( V_135 , 0 ) ;
F_20 ( V_138 ,
( ( V_78 -> V_187 - 1 ) << 16 ) | ( V_78 -> V_186 - 1 ) ) ;
F_20 ( V_83 , V_143 ) ;
F_11 ( V_83 ) ;
F_12 ( V_21 ) ;
F_20 ( V_61 , V_64 ) ;
V_99 -> V_151 ( V_3 , V_41 , V_42 , V_44 ) ;
F_12 ( V_21 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_188 * V_189 =
(struct V_188 * ) V_21 -> V_190 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_191 = V_192 ;
int V_193 ;
if ( ! V_3 -> V_87 )
return;
switch ( V_45 -> V_49 ) {
case 0 :
break;
case 1 :
V_191 = V_194 ;
break;
case 2 :
V_191 = V_195 ;
break;
default:
F_21 ( V_21 -> V_21 , L_13 ) ;
return;
}
if ( F_17 ( V_21 , false ) ) {
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
F_20 ( V_191 + 4 * V_193 ,
( ( V_45 -> V_196 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) << 16 ) |
( ( V_45 -> V_198 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) << 8 ) |
( V_45 -> V_199 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) ) ;
}
F_23 ( V_21 ) ;
} else {
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
V_189 -> V_200 [ V_193 ] =
( ( V_45 -> V_196 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) << 16 ) |
( ( V_45 -> V_198 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) << 8 ) |
( V_45 -> V_199 [ V_193 ] +
V_45 -> V_197 [ V_193 ] ) ;
}
}
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_201 * V_202 = V_45 -> V_202 ;
int V_203 = ( V_45 -> V_49 == 0 ) ;
T_2 V_204 ;
int V_193 ;
if ( ! V_202 ) {
F_21 ( V_21 -> V_21 , L_14 ) ;
return;
}
V_202 -> V_205 = F_11 ( V_203 ? V_62 : V_63 ) ;
V_202 -> V_206 = F_11 ( V_203 ? V_84 : V_85 ) ;
V_202 -> V_207 = F_11 ( V_203 ? V_139 : V_140 ) ;
V_202 -> V_208 = F_11 ( V_203 ? V_112 : V_113 ) ;
V_202 -> V_209 = F_11 ( V_203 ? V_210 : V_211 ) ;
V_202 -> V_212 = F_11 ( V_203 ? V_80 : V_81 ) ;
V_202 -> V_213 = F_11 ( V_203 ? V_115 : V_116 ) ;
V_202 -> V_214 = F_11 ( V_203 ? V_118 : V_119 ) ;
V_202 -> V_215 = F_11 ( V_203 ? V_121 : V_122 ) ;
V_202 -> V_216 = F_11 ( V_203 ? V_124 : V_125 ) ;
V_202 -> V_217 = F_11 ( V_203 ? V_127 : V_128 ) ;
V_202 -> V_218 = F_11 ( V_203 ? V_130 : V_131 ) ;
V_202 -> V_219 = F_11 ( V_203 ? V_59 : V_60 ) ;
V_202 -> V_220 = F_11 ( V_203 ? V_133 : V_134 ) ;
V_202 -> V_221 = F_11 ( V_203 ? V_136 : V_137 ) ;
V_202 -> V_222 = F_11 ( V_203 ? V_53 : V_54 ) ;
V_204 = V_203 ? V_192 : V_194 ;
for ( V_193 = 0 ; V_193 < 256 ; ++ V_193 )
V_202 -> V_223 [ V_193 ] = F_11 ( V_204 + ( V_193 << 2 ) ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_201 * V_202 = V_45 -> V_202 ;
int V_203 = ( V_45 -> V_49 == 0 ) ;
T_2 V_204 ;
int V_193 ;
if ( ! V_202 ) {
F_21 ( V_21 -> V_21 , L_15 ) ;
return;
}
if ( V_202 -> V_212 & V_91 ) {
F_20 ( V_203 ? V_80 : V_81 ,
V_202 -> V_212 & ~ V_91 ) ;
F_11 ( V_203 ? V_80 : V_81 ) ;
F_25 ( 150 ) ;
}
F_20 ( V_203 ? V_112 : V_113 , V_202 -> V_208 ) ;
F_11 ( V_203 ? V_112 : V_113 ) ;
F_20 ( V_203 ? V_210 : V_211 , V_202 -> V_209 ) ;
F_11 ( V_203 ? V_210 : V_211 ) ;
F_20 ( V_203 ? V_80 : V_81 , V_202 -> V_212 ) ;
F_11 ( V_203 ? V_80 : V_81 ) ;
F_25 ( 150 ) ;
F_20 ( V_203 ? V_115 : V_116 , V_202 -> V_213 ) ;
F_20 ( V_203 ? V_118 : V_119 , V_202 -> V_214 ) ;
F_20 ( V_203 ? V_121 : V_122 , V_202 -> V_215 ) ;
F_20 ( V_203 ? V_124 : V_125 , V_202 -> V_216 ) ;
F_20 ( V_203 ? V_127 : V_128 , V_202 -> V_217 ) ;
F_20 ( V_203 ? V_130 : V_131 , V_202 -> V_218 ) ;
F_20 ( V_203 ? V_59 : V_60 , V_202 -> V_219 ) ;
F_20 ( V_203 ? V_133 : V_134 , V_202 -> V_220 ) ;
F_20 ( V_203 ? V_136 : V_137 , V_202 -> V_221 ) ;
F_20 ( V_203 ? V_139 : V_140 , V_202 -> V_207 ) ;
F_20 ( V_203 ? V_53 : V_54 , V_202 -> V_222 ) ;
F_20 ( V_203 ? V_84 : V_85 , V_202 -> V_206 ) ;
F_12 ( V_21 ) ;
F_20 ( V_203 ? V_62 : V_63 , V_202 -> V_205 ) ;
F_20 ( V_203 ? V_53 : V_54 , V_202 -> V_222 ) ;
F_12 ( V_21 ) ;
V_204 = V_203 ? V_192 : V_194 ;
for ( V_193 = 0 ; V_193 < 256 ; ++ V_193 )
F_20 ( V_204 + ( V_193 << 2 ) , V_202 -> V_223 [ V_193 ] ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_224 * V_225 ,
T_2 V_226 ,
T_2 V_227 , T_2 V_228 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_229 = ( V_49 == 0 ) ? V_230 : V_231 ;
T_2 V_232 = ( V_49 == 0 ) ? V_233 : V_234 ;
T_2 V_86 ;
T_3 V_235 = 0 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
int V_65 ;
if ( ! V_226 ) {
V_86 = V_240 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_229 , V_86 ) ;
F_20 ( V_232 , 0 ) ;
F_23 ( V_21 ) ;
}
if ( V_45 -> V_241 ) {
V_237 = F_42 ( V_45 -> V_241 ,
struct V_236 , V_242 ) ;
F_22 ( V_237 ) ;
F_43 ( V_45 -> V_241 ) ;
V_45 -> V_241 = NULL ;
}
return 0 ;
}
if ( V_227 != 64 || V_228 != 64 ) {
F_18 ( V_21 -> V_21 , L_16 ) ;
return - V_77 ;
}
V_239 = F_44 ( V_21 , V_225 , V_226 ) ;
if ( ! V_239 )
return - V_243 ;
if ( V_239 -> V_244 < V_227 * V_228 * 4 ) {
F_18 ( V_21 -> V_21 , L_17 ) ;
return - V_245 ;
}
V_237 = F_42 ( V_239 , struct V_236 , V_242 ) ;
V_65 = F_19 ( V_237 ) ;
if ( V_65 ) {
F_21 ( V_21 -> V_21 , L_18 , V_226 ) ;
return V_65 ;
}
V_235 = V_237 -> V_51 ;
V_45 -> V_246 = V_235 ;
V_86 = 0 ;
V_86 |= ( V_49 << 28 ) ;
V_86 |= V_247 | V_248 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_229 , V_86 ) ;
F_20 ( V_232 , V_235 ) ;
F_23 ( V_21 ) ;
}
if ( V_45 -> V_241 ) {
V_237 = F_42 ( V_45 -> V_241 ,
struct V_236 , V_242 ) ;
F_22 ( V_237 ) ;
F_43 ( V_45 -> V_241 ) ;
V_45 -> V_241 = V_239 ;
}
return 0 ;
}
static int F_45 ( struct V_2 * V_3 , int V_41 , int V_42 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_86 = 0 ;
T_2 V_235 ;
if ( V_41 < 0 ) {
V_86 |= ( V_249 << V_250 ) ;
V_41 = - V_41 ;
}
if ( V_42 < 0 ) {
V_86 |= ( V_249 << V_251 ) ;
V_42 = - V_42 ;
}
V_86 |= ( ( V_41 & V_252 ) << V_250 ) ;
V_86 |= ( ( V_42 & V_252 ) << V_251 ) ;
V_235 = V_45 -> V_246 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( ( V_49 == 0 ) ? V_253 : V_254 , V_86 ) ;
F_20 ( ( V_49 == 0 ) ? V_233 : V_234 , V_235 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
void F_46 ( struct V_2 * V_3 , T_4 * V_255 ,
T_4 * V_256 , T_4 * V_257 , T_2 type , T_2 V_244 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_193 ;
if ( V_244 != 256 )
return;
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
V_45 -> V_196 [ V_193 ] = V_255 [ V_193 ] >> 8 ;
V_45 -> V_198 [ V_193 ] = V_256 [ V_193 ] >> 8 ;
V_45 -> V_199 [ V_193 ] = V_257 [ V_193 ] >> 8 ;
}
F_26 ( V_3 ) ;
}
static int F_47 ( struct V_258 * V_259 )
{
int V_65 ;
struct V_20 * V_21 = V_259 -> V_3 -> V_21 ;
struct V_188 * V_189 = V_21 -> V_190 ;
if ( ! V_189 -> V_260 )
return F_48 ( V_259 ) ;
F_49 ( & V_21 -> V_261 -> V_21 ) ;
V_65 = F_48 ( V_259 ) ;
F_50 ( & V_21 -> V_261 -> V_21 ) ;
return V_65 ;
}
static int F_51 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_1 V_141 ;
T_1 V_142 ;
struct V_10 clock ;
bool V_148 ;
struct V_188 * V_189 = V_21 -> V_190 ;
if ( F_17 ( V_21 , false ) ) {
V_141 = F_11 ( ( V_49 == 0 ) ? V_80 : V_81 ) ;
if ( ( V_141 & V_262 ) == 0 )
V_142 = F_11 ( ( V_49 == 0 ) ? V_112 : V_113 ) ;
else
V_142 = F_11 ( ( V_49 == 0 ) ? V_210 : V_211 ) ;
V_148 = ( V_49 == 1 ) && ( F_11 ( V_33 ) & V_34 ) ;
F_23 ( V_21 ) ;
} else {
V_141 = ( V_49 == 0 ) ?
V_189 -> V_263 : V_189 -> V_264 ;
if ( ( V_141 & V_262 ) == 0 )
V_142 = ( V_49 == 0 ) ?
V_189 -> V_265 :
V_189 -> V_266 ;
else
V_142 = ( V_49 == 0 ) ?
V_189 -> V_267 :
V_189 -> V_268 ;
V_148 = ( V_49 == 1 ) && ( V_189 -> V_269 & V_34 ) ;
}
clock . V_12 = ( V_142 & V_270 ) >> V_271 ;
clock . V_13 = ( V_142 & V_272 ) >> V_273 ;
clock . V_18 = ( V_142 & V_274 ) >> V_275 ;
if ( V_148 ) {
clock . V_15 =
F_52 ( ( V_141 &
V_276 ) >>
V_277 ) ;
clock . V_16 = 14 ;
if ( ( V_141 & V_278 ) ==
V_279 ) {
F_3 ( 66000 , & clock ) ;
} else
F_3 ( 48000 , & clock ) ;
} else {
if ( V_141 & V_280 )
clock . V_15 = 2 ;
else {
clock . V_15 =
( ( V_141 &
V_281 ) >>
V_277 ) + 2 ;
}
if ( V_141 & V_282 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
F_3 ( 48000 , & clock ) ;
}
return clock . V_19 ;
}
struct V_106 * F_53 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
struct V_106 * V_78 ;
int V_283 ;
int V_284 ;
int V_285 ;
int V_286 ;
struct V_188 * V_189 = V_21 -> V_190 ;
if ( F_17 ( V_21 , false ) ) {
V_283 = F_11 ( ( V_49 == 0 ) ? V_115 : V_116 ) ;
V_284 = F_11 ( ( V_49 == 0 ) ? V_121 : V_122 ) ;
V_285 = F_11 ( ( V_49 == 0 ) ? V_124 : V_125 ) ;
V_286 = F_11 ( ( V_49 == 0 ) ? V_130 : V_131 ) ;
F_23 ( V_21 ) ;
} else {
V_283 = ( V_49 == 0 ) ?
V_189 -> V_287 : V_189 -> V_288 ;
V_284 = ( V_49 == 0 ) ?
V_189 -> V_289 : V_189 -> V_290 ;
V_285 = ( V_49 == 0 ) ?
V_189 -> V_291 : V_189 -> V_292 ;
V_286 = ( V_49 == 0 ) ?
V_189 -> V_293 : V_189 -> V_294 ;
}
V_78 = F_54 ( sizeof( * V_78 ) , V_295 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> clock = F_51 ( V_21 , V_3 ) ;
V_78 -> V_187 = ( V_283 & 0xffff ) + 1 ;
V_78 -> V_296 = ( ( V_283 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_297 = ( V_284 & 0xffff ) + 1 ;
V_78 -> V_298 = ( ( V_284 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_186 = ( V_285 & 0xffff ) + 1 ;
V_78 -> V_299 = ( ( V_285 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_300 = ( V_286 & 0xffff ) + 1 ;
V_78 -> V_301 = ( ( V_286 & 0xffff0000 ) >> 16 ) + 1 ;
F_55 ( V_78 ) ;
F_56 ( V_78 , 0 ) ;
return V_78 ;
}
void F_57 ( struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_236 * V_237 ;
if ( V_45 -> V_241 ) {
V_237 = F_42 ( V_45 -> V_241 ,
struct V_236 , V_242 ) ;
F_22 ( V_237 ) ;
F_43 ( V_45 -> V_241 ) ;
V_45 -> V_241 = NULL ;
}
F_34 ( V_45 -> V_202 ) ;
F_58 ( V_3 ) ;
F_34 ( V_45 ) ;
}
static void F_59 ( struct V_20 * V_21 , int V_49 )
{
T_1 V_229 [ 3 ] = { V_230 , V_231 , V_302 } ;
T_1 V_232 [ 3 ] = { V_233 , V_234 , V_303 } ;
F_20 ( V_229 [ V_49 ] , 0 ) ;
F_20 ( V_232 [ V_49 ] , 0 ) ;
}
void F_60 ( struct V_20 * V_21 , int V_49 ,
struct V_304 * V_305 )
{
struct V_188 * V_189 = V_21 -> V_190 ;
struct V_45 * V_45 ;
int V_193 ;
T_5 * V_306 , * V_307 , * V_308 ;
V_45 =
F_54 ( sizeof( struct V_45 ) +
( V_309 * sizeof( struct V_24 * ) ) ,
V_295 ) ;
if ( V_45 == NULL )
return;
V_45 -> V_202 =
F_54 ( sizeof( struct V_201 ) , V_295 ) ;
if ( ! V_45 -> V_202 ) {
F_21 ( V_21 -> V_21 , L_19 ) ;
F_34 ( V_45 ) ;
return;
}
F_61 ( V_21 , & V_45 -> V_232 , V_189 -> V_310 -> V_99 ) ;
F_62 ( & V_45 -> V_232 , 256 ) ;
V_45 -> V_49 = V_49 ;
V_45 -> V_311 = V_49 ;
V_306 = V_45 -> V_232 . V_312 ;
V_307 = V_306 + 256 ;
V_308 = V_307 + 256 ;
for ( V_193 = 0 ; V_193 < 256 ; V_193 ++ ) {
V_45 -> V_196 [ V_193 ] = V_193 ;
V_45 -> V_198 [ V_193 ] = V_193 ;
V_45 -> V_199 [ V_193 ] = V_193 ;
V_306 [ V_193 ] = V_193 << 8 ;
V_307 [ V_193 ] = V_193 << 8 ;
V_308 [ V_193 ] = V_193 << 8 ;
V_45 -> V_197 [ V_193 ] = 0 ;
}
V_45 -> V_305 = V_305 ;
V_45 -> V_246 = 0 ;
F_63 ( & V_45 -> V_232 ,
V_189 -> V_310 -> V_313 ) ;
V_45 -> V_314 . V_3 = & V_45 -> V_232 ;
F_64 ( V_49 >= F_65 ( V_189 -> V_315 ) ||
V_189 -> V_315 [ V_45 -> V_311 ] != NULL ) ;
V_189 -> V_315 [ V_45 -> V_311 ] =
& V_45 -> V_232 ;
V_189 -> V_316 [ V_45 -> V_49 ] =
& V_45 -> V_232 ;
V_45 -> V_314 . V_317 =
(struct V_24 * * ) ( V_45 + 1 ) ;
V_45 -> V_314 . V_318 = 0 ;
F_59 ( V_21 , V_49 ) ;
}
int F_66 ( struct V_20 * V_21 , void * V_319 ,
struct V_224 * V_225 )
{
struct V_188 * V_189 = V_21 -> V_190 ;
struct V_320 * V_321 = V_319 ;
struct V_322 * V_323 ;
struct V_45 * V_3 ;
if ( ! V_189 ) {
F_21 ( V_21 -> V_21 , L_20 ) ;
return - V_77 ;
}
V_323 = F_67 ( V_21 , V_321 -> V_324 ,
V_325 ) ;
if ( ! V_323 ) {
F_21 ( V_21 -> V_21 , L_21 ) ;
return - V_77 ;
}
V_3 = F_15 ( F_68 ( V_323 ) ) ;
V_321 -> V_49 = V_3 -> V_49 ;
return 0 ;
}
struct V_2 * F_69 ( struct V_20 * V_21 , int V_49 )
{
struct V_2 * V_3 = NULL ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_45 * V_45 = F_15 ( V_3 ) ;
if ( V_45 -> V_49 == V_49 )
break;
}
return V_3 ;
}
int F_70 ( struct V_20 * V_21 , int V_326 )
{
int V_327 = 0 ;
struct V_24 * V_150 ;
int V_328 = 0 ;
F_6 (connector, &dev->mode_config.connector_list,
head) {
struct V_27 * V_27 =
F_7 ( V_150 ) ;
if ( V_326 & ( 1 << V_27 -> type ) )
V_327 |= ( 1 << V_328 ) ;
V_328 ++ ;
}
return V_327 ;
}
void F_71 ( struct V_20 * V_21 )
{
F_72 ( V_21 ) ;
}
struct V_102 * F_73 ( struct V_24 * V_150 )
{
struct V_27 * V_27 =
F_7 ( V_150 ) ;
return & V_27 -> V_232 ;
}
void F_74 ( struct V_329 * V_150 ,
struct V_27 * V_26 )
{
V_150 -> V_26 = V_26 ;
F_75 ( & V_150 -> V_232 ,
& V_26 -> V_232 ) ;
}
