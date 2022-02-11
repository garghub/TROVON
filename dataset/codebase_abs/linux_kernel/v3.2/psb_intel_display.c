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
V_51 = V_42 * V_3 -> V_48 -> V_69 + V_41 * ( V_3 -> V_48 -> V_70 / 8 ) ;
F_20 ( V_58 , V_3 -> V_48 -> V_69 ) ;
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
static bool F_31 ( struct V_2 * V_3 ,
struct V_105 * V_78 ,
struct V_105 * V_106 )
{
return true ;
}
static int F_32 ( struct V_20 * V_21 )
{
T_1 V_107 ;
V_107 = F_11 ( V_108 ) ;
if ( ( V_107 & V_109 ) == 0 )
return - 1 ;
return 1 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_105 * V_78 ,
struct V_105 * V_106 ,
int V_41 , int V_42 ,
struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_98 * V_99 = V_3 -> V_100 ;
int V_49 = V_45 -> V_49 ;
int V_110 = ( V_49 == 0 ) ? V_111 : V_112 ;
int V_79 = ( V_49 == 0 ) ? V_80 : V_81 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
int V_83 = ( V_49 == 0 ) ? V_84 : V_85 ;
int V_113 = ( V_49 == 0 ) ? V_114 : V_115 ;
int V_116 = ( V_49 == 0 ) ? V_117 : V_118 ;
int V_119 = ( V_49 == 0 ) ? V_120 : V_121 ;
int V_122 = ( V_49 == 0 ) ? V_123 : V_124 ;
int V_125 = ( V_49 == 0 ) ? V_126 : V_127 ;
int V_128 = ( V_49 == 0 ) ? V_129 : V_130 ;
int V_131 = ( V_49 == 0 ) ? V_132 : V_133 ;
int V_134 = ( V_49 == 0 ) ? V_135 : V_136 ;
int V_137 = ( V_49 == 0 ) ? V_138 : V_139 ;
int V_9 ;
struct V_10 clock ;
T_1 V_140 = 0 , V_141 = 0 , V_64 , V_142 ;
bool V_143 , V_144 = false , V_145 = false ;
bool V_146 = false , V_147 = false , V_148 = false ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_149 ;
if ( V_3 -> V_48 == NULL ) {
V_99 -> V_150 ( V_3 , V_41 , V_42 , V_44 ) ;
return 0 ;
}
F_6 (connector, &mode_config->connector_list, head) {
struct V_27 * V_27 =
F_7 ( V_149 ) ;
if ( ! V_149 -> V_26
|| V_149 -> V_26 -> V_3 != V_3 )
continue;
switch ( V_27 -> type ) {
case V_5 :
V_147 = true ;
break;
case V_151 :
V_144 = true ;
break;
case V_152 :
V_145 = true ;
break;
case V_153 :
V_148 = true ;
break;
case V_154 :
V_146 = true ;
break;
}
}
V_9 = 96000 ;
V_143 = F_10 ( V_3 , V_106 -> clock , V_9 ,
& clock ) ;
if ( ! V_143 ) {
F_21 ( V_21 -> V_21 , L_12 ) ;
return 0 ;
}
V_141 = clock . V_18 << 16 | clock . V_12 << 8 | clock . V_13 ;
V_140 = V_155 ;
if ( V_147 ) {
V_140 |= V_156 ;
V_140 |= V_157 ;
} else
V_140 |= V_158 ;
if ( V_144 ) {
int V_159 =
V_106 -> clock / V_78 -> clock ;
V_140 |= V_157 ;
V_140 |=
( V_159 - 1 ) << V_160 ;
}
V_140 |= ( 1 << ( clock . V_15 - 1 ) ) << 16 ;
switch ( clock . V_16 ) {
case 5 :
V_140 |= V_161 ;
break;
case 7 :
V_140 |= V_162 ;
break;
case 10 :
V_140 |= V_163 ;
break;
case 14 :
V_140 |= V_164 ;
break;
}
if ( V_148 ) {
V_140 |= 3 ;
}
V_140 |= V_165 ;
V_142 = F_11 ( V_83 ) ;
V_64 = V_166 ;
if ( V_49 == 0 )
V_64 |= V_167 ;
else
V_64 |= V_168 ;
V_64 |= V_93 ;
V_142 |= V_92 ;
V_140 |= V_91 ;
if ( F_32 ( V_21 ) == V_49 )
F_20 ( V_108 , 0 ) ;
F_34 ( V_78 ) ;
if ( V_140 & V_91 ) {
F_20 ( V_110 , V_141 ) ;
F_20 ( V_79 , V_140 & ~ V_91 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
}
if ( V_147 ) {
T_1 V_169 = F_11 ( V_33 ) ;
V_169 &= ~ V_170 ;
if ( V_49 == 1 )
V_169 |= V_170 ;
V_169 |= V_34 | V_171 ;
V_169 &= ~ ( V_172 | V_36 ) ;
if ( clock . V_16 == 7 )
V_169 |= V_172 | V_36 ;
F_20 ( V_33 , V_169 ) ;
F_11 ( V_33 ) ;
}
F_20 ( V_110 , V_141 ) ;
F_20 ( V_79 , V_140 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_79 , V_140 ) ;
F_11 ( V_79 ) ;
F_25 ( 150 ) ;
F_20 ( V_113 , ( V_106 -> V_173 - 1 ) |
( ( V_106 -> V_174 - 1 ) << 16 ) ) ;
F_20 ( V_116 , ( V_106 -> V_175 - 1 ) |
( ( V_106 -> V_176 - 1 ) << 16 ) ) ;
F_20 ( V_119 , ( V_106 -> V_177 - 1 ) |
( ( V_106 -> V_178 - 1 ) << 16 ) ) ;
F_20 ( V_122 , ( V_106 -> V_179 - 1 ) |
( ( V_106 -> V_180 - 1 ) << 16 ) ) ;
F_20 ( V_125 , ( V_106 -> V_181 - 1 ) |
( ( V_106 -> V_182 - 1 ) << 16 ) ) ;
F_20 ( V_128 , ( V_106 -> V_183 - 1 ) |
( ( V_106 -> V_184 - 1 ) << 16 ) ) ;
F_20 ( V_131 ,
( ( V_78 -> V_185 - 1 ) << 16 ) | ( V_78 -> V_186 - 1 ) ) ;
F_20 ( V_134 , 0 ) ;
F_20 ( V_137 ,
( ( V_78 -> V_186 - 1 ) << 16 ) | ( V_78 -> V_185 - 1 ) ) ;
F_20 ( V_83 , V_142 ) ;
F_11 ( V_83 ) ;
F_12 ( V_21 ) ;
F_20 ( V_61 , V_64 ) ;
V_99 -> V_150 ( V_3 , V_41 , V_42 , V_44 ) ;
F_12 ( V_21 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_187 * V_188 =
(struct V_187 * ) V_21 -> V_189 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_190 = V_191 ;
int V_192 ;
if ( ! V_3 -> V_87 )
return;
switch ( V_45 -> V_49 ) {
case 0 :
break;
case 1 :
V_190 = V_193 ;
break;
case 2 :
V_190 = V_194 ;
break;
default:
F_21 ( V_21 -> V_21 , L_13 ) ;
return;
}
if ( F_17 ( V_21 , false ) ) {
for ( V_192 = 0 ; V_192 < 256 ; V_192 ++ ) {
F_20 ( V_190 + 4 * V_192 ,
( ( V_45 -> V_195 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) << 16 ) |
( ( V_45 -> V_197 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) << 8 ) |
( V_45 -> V_198 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) ) ;
}
F_23 ( V_21 ) ;
} else {
for ( V_192 = 0 ; V_192 < 256 ; V_192 ++ ) {
V_188 -> V_199 [ V_192 ] =
( ( V_45 -> V_195 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) << 16 ) |
( ( V_45 -> V_197 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) << 8 ) |
( V_45 -> V_198 [ V_192 ] +
V_45 -> V_196 [ V_192 ] ) ;
}
}
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_200 * V_201 = V_45 -> V_201 ;
int V_202 = ( V_45 -> V_49 == 0 ) ;
T_2 V_203 ;
int V_192 ;
if ( ! V_201 ) {
F_21 ( V_21 -> V_21 , L_14 ) ;
return;
}
V_201 -> V_204 = F_11 ( V_202 ? V_62 : V_63 ) ;
V_201 -> V_205 = F_11 ( V_202 ? V_84 : V_85 ) ;
V_201 -> V_206 = F_11 ( V_202 ? V_138 : V_139 ) ;
V_201 -> V_207 = F_11 ( V_202 ? V_111 : V_112 ) ;
V_201 -> V_208 = F_11 ( V_202 ? V_209 : V_210 ) ;
V_201 -> V_211 = F_11 ( V_202 ? V_80 : V_81 ) ;
V_201 -> V_212 = F_11 ( V_202 ? V_114 : V_115 ) ;
V_201 -> V_213 = F_11 ( V_202 ? V_117 : V_118 ) ;
V_201 -> V_214 = F_11 ( V_202 ? V_120 : V_121 ) ;
V_201 -> V_215 = F_11 ( V_202 ? V_123 : V_124 ) ;
V_201 -> V_216 = F_11 ( V_202 ? V_126 : V_127 ) ;
V_201 -> V_217 = F_11 ( V_202 ? V_129 : V_130 ) ;
V_201 -> V_218 = F_11 ( V_202 ? V_59 : V_60 ) ;
V_201 -> V_219 = F_11 ( V_202 ? V_132 : V_133 ) ;
V_201 -> V_220 = F_11 ( V_202 ? V_135 : V_136 ) ;
V_201 -> V_221 = F_11 ( V_202 ? V_53 : V_54 ) ;
V_203 = V_202 ? V_191 : V_193 ;
for ( V_192 = 0 ; V_192 < 256 ; ++ V_192 )
V_201 -> V_222 [ V_192 ] = F_11 ( V_203 + ( V_192 << 2 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_200 * V_201 = V_45 -> V_201 ;
int V_202 = ( V_45 -> V_49 == 0 ) ;
T_2 V_203 ;
int V_192 ;
if ( ! V_201 ) {
F_21 ( V_21 -> V_21 , L_15 ) ;
return;
}
if ( V_201 -> V_211 & V_91 ) {
F_20 ( V_202 ? V_80 : V_81 ,
V_201 -> V_211 & ~ V_91 ) ;
F_11 ( V_202 ? V_80 : V_81 ) ;
F_25 ( 150 ) ;
}
F_20 ( V_202 ? V_111 : V_112 , V_201 -> V_207 ) ;
F_11 ( V_202 ? V_111 : V_112 ) ;
F_20 ( V_202 ? V_209 : V_210 , V_201 -> V_208 ) ;
F_11 ( V_202 ? V_209 : V_210 ) ;
F_20 ( V_202 ? V_80 : V_81 , V_201 -> V_211 ) ;
F_11 ( V_202 ? V_80 : V_81 ) ;
F_25 ( 150 ) ;
F_20 ( V_202 ? V_114 : V_115 , V_201 -> V_212 ) ;
F_20 ( V_202 ? V_117 : V_118 , V_201 -> V_213 ) ;
F_20 ( V_202 ? V_120 : V_121 , V_201 -> V_214 ) ;
F_20 ( V_202 ? V_123 : V_124 , V_201 -> V_215 ) ;
F_20 ( V_202 ? V_126 : V_127 , V_201 -> V_216 ) ;
F_20 ( V_202 ? V_129 : V_130 , V_201 -> V_217 ) ;
F_20 ( V_202 ? V_59 : V_60 , V_201 -> V_218 ) ;
F_20 ( V_202 ? V_132 : V_133 , V_201 -> V_219 ) ;
F_20 ( V_202 ? V_135 : V_136 , V_201 -> V_220 ) ;
F_20 ( V_202 ? V_138 : V_139 , V_201 -> V_206 ) ;
F_20 ( V_202 ? V_53 : V_54 , V_201 -> V_221 ) ;
F_20 ( V_202 ? V_84 : V_85 , V_201 -> V_205 ) ;
F_12 ( V_21 ) ;
F_20 ( V_202 ? V_62 : V_63 , V_201 -> V_204 ) ;
F_20 ( V_202 ? V_53 : V_54 , V_201 -> V_221 ) ;
F_12 ( V_21 ) ;
V_203 = V_202 ? V_191 : V_193 ;
for ( V_192 = 0 ; V_192 < 256 ; ++ V_192 )
F_20 ( V_203 + ( V_192 << 2 ) , V_201 -> V_222 [ V_192 ] ) ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_223 * V_224 ,
T_2 V_225 ,
T_2 V_226 , T_2 V_227 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_228 = ( V_49 == 0 ) ? V_229 : V_230 ;
T_2 V_231 = ( V_49 == 0 ) ? V_232 : V_233 ;
T_2 V_86 ;
T_3 V_234 = 0 ;
struct V_235 * V_236 ;
struct V_237 * V_238 ;
int V_65 ;
if ( ! V_225 ) {
V_86 = V_239 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_228 , V_86 ) ;
F_20 ( V_231 , 0 ) ;
F_23 ( V_21 ) ;
}
if ( V_45 -> V_240 ) {
V_236 = F_38 ( V_45 -> V_240 ,
struct V_235 , V_241 ) ;
F_22 ( V_236 ) ;
F_39 ( V_45 -> V_240 ) ;
V_45 -> V_240 = NULL ;
}
return 0 ;
}
if ( V_226 != 64 || V_227 != 64 ) {
F_18 ( V_21 -> V_21 , L_16 ) ;
return - V_77 ;
}
V_238 = F_40 ( V_21 , V_224 , V_225 ) ;
if ( ! V_238 )
return - V_242 ;
if ( V_238 -> V_243 < V_226 * V_227 * 4 ) {
F_18 ( V_21 -> V_21 , L_17 ) ;
return - V_244 ;
}
V_236 = F_38 ( V_238 , struct V_235 , V_241 ) ;
V_65 = F_19 ( V_236 ) ;
if ( V_65 ) {
F_21 ( V_21 -> V_21 , L_18 , V_225 ) ;
return V_65 ;
}
V_234 = V_236 -> V_51 ;
V_45 -> V_245 = V_234 ;
V_86 = 0 ;
V_86 |= ( V_49 << 28 ) ;
V_86 |= V_246 | V_247 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_228 , V_86 ) ;
F_20 ( V_231 , V_234 ) ;
F_23 ( V_21 ) ;
}
if ( V_45 -> V_240 ) {
V_236 = F_38 ( V_45 -> V_240 ,
struct V_235 , V_241 ) ;
F_22 ( V_236 ) ;
F_39 ( V_45 -> V_240 ) ;
V_45 -> V_240 = V_238 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , int V_41 , int V_42 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_86 = 0 ;
T_2 V_234 ;
if ( V_41 < 0 ) {
V_86 |= ( V_248 << V_249 ) ;
V_41 = - V_41 ;
}
if ( V_42 < 0 ) {
V_86 |= ( V_248 << V_250 ) ;
V_42 = - V_42 ;
}
V_86 |= ( ( V_41 & V_251 ) << V_249 ) ;
V_86 |= ( ( V_42 & V_251 ) << V_250 ) ;
V_234 = V_45 -> V_245 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( ( V_49 == 0 ) ? V_252 : V_253 , V_86 ) ;
F_20 ( ( V_49 == 0 ) ? V_232 : V_233 , V_234 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
void F_42 ( struct V_2 * V_3 , T_4 * V_254 ,
T_4 * V_255 , T_4 * V_256 , T_2 type , T_2 V_243 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_192 ;
if ( V_243 != 256 )
return;
for ( V_192 = 0 ; V_192 < 256 ; V_192 ++ ) {
V_45 -> V_195 [ V_192 ] = V_254 [ V_192 ] >> 8 ;
V_45 -> V_197 [ V_192 ] = V_255 [ V_192 ] >> 8 ;
V_45 -> V_198 [ V_192 ] = V_256 [ V_192 ] >> 8 ;
}
F_26 ( V_3 ) ;
}
static int F_43 ( struct V_257 * V_258 )
{
int V_65 ;
struct V_20 * V_21 = V_258 -> V_3 -> V_21 ;
F_44 ( & V_21 -> V_259 -> V_21 ) ;
V_65 = F_45 ( V_258 ) ;
F_46 ( & V_21 -> V_259 -> V_21 ) ;
return V_65 ;
}
static int F_47 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_1 V_140 ;
T_1 V_141 ;
struct V_10 clock ;
bool V_147 ;
struct V_187 * V_188 = V_21 -> V_189 ;
if ( F_17 ( V_21 , false ) ) {
V_140 = F_11 ( ( V_49 == 0 ) ? V_80 : V_81 ) ;
if ( ( V_140 & V_260 ) == 0 )
V_141 = F_11 ( ( V_49 == 0 ) ? V_111 : V_112 ) ;
else
V_141 = F_11 ( ( V_49 == 0 ) ? V_209 : V_210 ) ;
V_147 = ( V_49 == 1 ) && ( F_11 ( V_33 ) & V_34 ) ;
F_23 ( V_21 ) ;
} else {
V_140 = ( V_49 == 0 ) ?
V_188 -> V_261 : V_188 -> V_262 ;
if ( ( V_140 & V_260 ) == 0 )
V_141 = ( V_49 == 0 ) ?
V_188 -> V_263 :
V_188 -> V_264 ;
else
V_141 = ( V_49 == 0 ) ?
V_188 -> V_265 :
V_188 -> V_266 ;
V_147 = ( V_49 == 1 ) && ( V_188 -> V_267 & V_34 ) ;
}
clock . V_12 = ( V_141 & V_268 ) >> V_269 ;
clock . V_13 = ( V_141 & V_270 ) >> V_271 ;
clock . V_18 = ( V_141 & V_272 ) >> V_273 ;
if ( V_147 ) {
clock . V_15 =
F_48 ( ( V_140 &
V_274 ) >>
V_275 ) ;
clock . V_16 = 14 ;
if ( ( V_140 & V_276 ) ==
V_277 ) {
F_3 ( 66000 , & clock ) ;
} else
F_3 ( 48000 , & clock ) ;
} else {
if ( V_140 & V_278 )
clock . V_15 = 2 ;
else {
clock . V_15 =
( ( V_140 &
V_279 ) >>
V_275 ) + 2 ;
}
if ( V_140 & V_280 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
F_3 ( 48000 , & clock ) ;
}
return clock . V_19 ;
}
struct V_105 * F_49 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
struct V_105 * V_78 ;
int V_281 ;
int V_282 ;
int V_283 ;
int V_284 ;
struct V_187 * V_188 = V_21 -> V_189 ;
if ( F_17 ( V_21 , false ) ) {
V_281 = F_11 ( ( V_49 == 0 ) ? V_114 : V_115 ) ;
V_282 = F_11 ( ( V_49 == 0 ) ? V_120 : V_121 ) ;
V_283 = F_11 ( ( V_49 == 0 ) ? V_123 : V_124 ) ;
V_284 = F_11 ( ( V_49 == 0 ) ? V_129 : V_130 ) ;
F_23 ( V_21 ) ;
} else {
V_281 = ( V_49 == 0 ) ?
V_188 -> V_285 : V_188 -> V_286 ;
V_282 = ( V_49 == 0 ) ?
V_188 -> V_287 : V_188 -> V_288 ;
V_283 = ( V_49 == 0 ) ?
V_188 -> V_289 : V_188 -> V_290 ;
V_284 = ( V_49 == 0 ) ?
V_188 -> V_291 : V_188 -> V_292 ;
}
V_78 = F_50 ( sizeof( * V_78 ) , V_293 ) ;
if ( ! V_78 )
return NULL ;
V_78 -> clock = F_47 ( V_21 , V_3 ) ;
V_78 -> V_186 = ( V_281 & 0xffff ) + 1 ;
V_78 -> V_294 = ( ( V_281 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_295 = ( V_282 & 0xffff ) + 1 ;
V_78 -> V_296 = ( ( V_282 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_185 = ( V_283 & 0xffff ) + 1 ;
V_78 -> V_297 = ( ( V_283 & 0xffff0000 ) >> 16 ) + 1 ;
V_78 -> V_298 = ( V_284 & 0xffff ) + 1 ;
V_78 -> V_299 = ( ( V_284 & 0xffff0000 ) >> 16 ) + 1 ;
F_51 ( V_78 ) ;
F_52 ( V_78 , 0 ) ;
return V_78 ;
}
void F_53 ( struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_235 * V_236 ;
if ( V_45 -> V_240 ) {
V_236 = F_38 ( V_45 -> V_240 ,
struct V_235 , V_241 ) ;
F_22 ( V_236 ) ;
F_39 ( V_45 -> V_240 ) ;
V_45 -> V_240 = NULL ;
}
F_54 ( V_45 -> V_201 ) ;
F_55 ( V_3 ) ;
F_54 ( V_45 ) ;
}
static void F_56 ( struct V_20 * V_21 , int V_49 )
{
T_1 V_228 [ 3 ] = { V_229 , V_230 , V_300 } ;
T_1 V_231 [ 3 ] = { V_232 , V_233 , V_301 } ;
F_20 ( V_228 [ V_49 ] , 0 ) ;
F_20 ( V_231 [ V_49 ] , 0 ) ;
}
void F_57 ( struct V_20 * V_21 , int V_49 ,
struct V_302 * V_303 )
{
struct V_187 * V_188 = V_21 -> V_189 ;
struct V_45 * V_45 ;
int V_192 ;
T_5 * V_304 , * V_305 , * V_306 ;
V_45 =
F_50 ( sizeof( struct V_45 ) +
( V_307 * sizeof( struct V_24 * ) ) ,
V_293 ) ;
if ( V_45 == NULL )
return;
V_45 -> V_201 =
F_50 ( sizeof( struct V_200 ) , V_293 ) ;
if ( ! V_45 -> V_201 ) {
F_21 ( V_21 -> V_21 , L_19 ) ;
F_54 ( V_45 ) ;
return;
}
F_58 ( V_21 , & V_45 -> V_231 , V_188 -> V_308 -> V_99 ) ;
F_59 ( & V_45 -> V_231 , 256 ) ;
V_45 -> V_49 = V_49 ;
V_45 -> V_309 = V_49 ;
V_304 = V_45 -> V_231 . V_310 ;
V_305 = V_304 + 256 ;
V_306 = V_305 + 256 ;
for ( V_192 = 0 ; V_192 < 256 ; V_192 ++ ) {
V_45 -> V_195 [ V_192 ] = V_192 ;
V_45 -> V_197 [ V_192 ] = V_192 ;
V_45 -> V_198 [ V_192 ] = V_192 ;
V_304 [ V_192 ] = V_192 << 8 ;
V_305 [ V_192 ] = V_192 << 8 ;
V_306 [ V_192 ] = V_192 << 8 ;
V_45 -> V_196 [ V_192 ] = 0 ;
}
V_45 -> V_303 = V_303 ;
V_45 -> V_245 = 0 ;
F_60 ( & V_45 -> V_231 ,
V_188 -> V_308 -> V_311 ) ;
V_45 -> V_312 . V_3 = & V_45 -> V_231 ;
F_61 ( V_49 >= F_62 ( V_188 -> V_313 ) ||
V_188 -> V_313 [ V_45 -> V_309 ] != NULL ) ;
V_188 -> V_313 [ V_45 -> V_309 ] =
& V_45 -> V_231 ;
V_188 -> V_314 [ V_45 -> V_49 ] =
& V_45 -> V_231 ;
V_45 -> V_312 . V_315 =
(struct V_24 * * ) ( V_45 + 1 ) ;
V_45 -> V_312 . V_316 = 0 ;
F_56 ( V_21 , V_49 ) ;
}
int F_63 ( struct V_20 * V_21 , void * V_317 ,
struct V_223 * V_224 )
{
struct V_187 * V_188 = V_21 -> V_189 ;
struct V_318 * V_319 = V_317 ;
struct V_320 * V_321 ;
struct V_45 * V_3 ;
if ( ! V_188 ) {
F_21 ( V_21 -> V_21 , L_20 ) ;
return - V_77 ;
}
V_321 = F_64 ( V_21 , V_319 -> V_322 ,
V_323 ) ;
if ( ! V_321 ) {
F_21 ( V_21 -> V_21 , L_21 ) ;
return - V_77 ;
}
V_3 = F_15 ( F_65 ( V_321 ) ) ;
V_319 -> V_49 = V_3 -> V_49 ;
return 0 ;
}
struct V_2 * F_66 ( struct V_20 * V_21 , int V_49 )
{
struct V_2 * V_3 = NULL ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_45 * V_45 = F_15 ( V_3 ) ;
if ( V_45 -> V_49 == V_49 )
break;
}
return V_3 ;
}
int F_67 ( struct V_20 * V_21 , int V_324 )
{
int V_325 = 0 ;
struct V_24 * V_149 ;
int V_326 = 0 ;
F_6 (connector, &dev->mode_config.connector_list,
head) {
struct V_27 * V_27 =
F_7 ( V_149 ) ;
if ( V_324 & ( 1 << V_27 -> type ) )
V_325 |= ( 1 << V_326 ) ;
V_326 ++ ;
}
return V_325 ;
}
void F_68 ( struct V_20 * V_21 )
{
F_69 ( V_21 ) ;
}
struct V_102 * F_70 ( struct V_24 * V_149 )
{
struct V_27 * V_27 =
F_7 ( V_149 ) ;
return & V_27 -> V_327 ;
}
