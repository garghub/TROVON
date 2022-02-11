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
F_13 ( 20000 ) ;
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
F_17 ( L_10 ) ;
if ( ! V_3 -> V_48 ) {
F_18 ( L_11 ) ;
return 0 ;
}
if ( ! F_19 ( V_21 , true ) )
return 0 ;
V_65 = F_20 ( V_47 -> V_66 ) ;
if ( V_65 < 0 )
goto V_67;
V_50 = V_47 -> V_66 -> V_51 ;
V_51 = V_42 * V_3 -> V_48 -> V_68 + V_41 * ( V_3 -> V_48 -> V_69 / 8 ) ;
F_21 ( V_58 , V_3 -> V_48 -> V_68 ) ;
V_64 = F_11 ( V_61 ) ;
V_64 &= ~ V_70 ;
switch ( V_3 -> V_48 -> V_69 ) {
case 8 :
V_64 |= V_71 ;
break;
case 16 :
if ( V_3 -> V_48 -> V_72 == 15 )
V_64 |= V_73 ;
else
V_64 |= V_74 ;
break;
case 24 :
case 32 :
V_64 |= V_75 ;
break;
default:
F_22 ( L_12 ) ;
V_65 = - V_76 ;
F_23 ( V_47 -> V_66 ) ;
goto V_67;
}
F_21 ( V_61 , V_64 ) ;
F_18 ( L_13 , V_50 , V_51 , V_41 , V_42 ) ;
if ( 0 ) {
F_21 ( V_52 , V_51 ) ;
F_11 ( V_52 ) ;
F_21 ( V_55 , V_50 ) ;
F_11 ( V_55 ) ;
} else {
F_21 ( V_52 , V_50 + V_51 ) ;
F_11 ( V_52 ) ;
}
if ( V_44 )
F_23 ( F_16 ( V_44 ) -> V_66 ) ;
V_67:
F_24 ( V_21 ) ;
return V_65 ;
}
static void F_25 ( struct V_2 * V_3 , int V_77 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
int V_78 = ( V_49 == 0 ) ? V_79 : V_80 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
int V_81 = ( V_49 == 0 ) ? V_53 : V_54 ;
int V_82 = ( V_49 == 0 ) ? V_83 : V_84 ;
T_1 V_85 ;
bool V_86 ;
switch ( V_77 ) {
case V_87 :
case V_88 :
case V_89 :
V_85 = F_11 ( V_78 ) ;
if ( ( V_85 & V_90 ) == 0 ) {
F_21 ( V_78 , V_85 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
F_21 ( V_78 , V_85 | V_90 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
F_21 ( V_78 , V_85 | V_90 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
}
V_85 = F_11 ( V_82 ) ;
if ( ( V_85 & V_91 ) == 0 )
F_21 ( V_82 , V_85 | V_91 ) ;
V_85 = F_11 ( V_61 ) ;
if ( ( V_85 & V_92 ) == 0 ) {
F_21 ( V_61 ,
V_85 | V_92 ) ;
F_21 ( V_81 , F_11 ( V_81 ) ) ;
}
F_26 ( V_3 ) ;
break;
case V_93 :
F_21 ( V_94 , V_95 ) ;
V_85 = F_11 ( V_61 ) ;
if ( ( V_85 & V_92 ) != 0 ) {
F_21 ( V_61 ,
V_85 & ~ V_92 ) ;
F_21 ( V_81 , F_11 ( V_81 ) ) ;
F_11 ( V_81 ) ;
}
V_85 = F_11 ( V_82 ) ;
if ( ( V_85 & V_91 ) != 0 ) {
F_21 ( V_82 , V_85 & ~ V_91 ) ;
F_11 ( V_82 ) ;
}
F_12 ( V_21 ) ;
V_85 = F_11 ( V_78 ) ;
if ( ( V_85 & V_90 ) != 0 ) {
F_21 ( V_78 , V_85 & ~ V_90 ) ;
F_11 ( V_78 ) ;
}
F_13 ( 150 ) ;
break;
}
V_86 = V_3 -> V_86 && V_77 != V_93 ;
F_21 ( V_96 , 0x3F3E ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_97 * V_98 = V_3 -> V_99 ;
V_98 -> V_100 ( V_3 , V_93 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_97 * V_98 = V_3 -> V_99 ;
V_98 -> V_100 ( V_3 , V_87 ) ;
}
void F_29 ( struct V_101 * V_26 )
{
struct V_102 * V_103 =
V_26 -> V_99 ;
V_103 -> V_100 ( V_26 , V_93 ) ;
}
void F_30 ( struct V_101 * V_26 )
{
struct V_102 * V_103 =
V_26 -> V_99 ;
V_103 -> V_100 ( V_26 , V_87 ) ;
}
static bool F_31 ( struct V_2 * V_3 ,
struct V_104 * V_77 ,
struct V_104 * V_105 )
{
return true ;
}
static int F_32 ( struct V_20 * V_21 )
{
T_1 V_106 ;
V_106 = F_11 ( V_107 ) ;
if ( ( V_106 & V_108 ) == 0 )
return - 1 ;
return 1 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_104 * V_77 ,
struct V_104 * V_105 ,
int V_41 , int V_42 ,
struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
int V_109 = ( V_49 == 0 ) ? V_110 : V_111 ;
int V_78 = ( V_49 == 0 ) ? V_79 : V_80 ;
int V_61 = ( V_49 == 0 ) ? V_62 : V_63 ;
int V_82 = ( V_49 == 0 ) ? V_83 : V_84 ;
int V_112 = ( V_49 == 0 ) ? V_113 : V_114 ;
int V_115 = ( V_49 == 0 ) ? V_116 : V_117 ;
int V_118 = ( V_49 == 0 ) ? V_119 : V_120 ;
int V_121 = ( V_49 == 0 ) ? V_122 : V_123 ;
int V_124 = ( V_49 == 0 ) ? V_125 : V_126 ;
int V_127 = ( V_49 == 0 ) ? V_128 : V_129 ;
int V_130 = ( V_49 == 0 ) ? V_131 : V_132 ;
int V_133 = ( V_49 == 0 ) ? V_134 : V_135 ;
int V_136 = ( V_49 == 0 ) ? V_137 : V_138 ;
int V_9 ;
struct V_10 clock ;
T_1 V_139 = 0 , V_140 = 0 , V_64 , V_141 ;
bool V_142 , V_143 = false , V_144 = false ;
bool V_145 = false , V_146 = false , V_147 = false ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_148 ;
F_6 (connector, &mode_config->connector_list, head) {
struct V_27 * V_27 =
F_7 ( V_148 ) ;
if ( ! V_148 -> V_26
|| V_148 -> V_26 -> V_3 != V_3 )
continue;
switch ( V_27 -> type ) {
case V_5 :
V_146 = true ;
break;
case V_149 :
V_143 = true ;
break;
case V_150 :
V_144 = true ;
break;
case V_151 :
V_147 = true ;
break;
case V_152 :
V_145 = true ;
break;
}
}
V_9 = 96000 ;
V_142 = F_10 ( V_3 , V_105 -> clock , V_9 ,
& clock ) ;
if ( ! V_142 ) {
F_22 ( L_14 ) ;
return 0 ;
}
V_140 = clock . V_18 << 16 | clock . V_12 << 8 | clock . V_13 ;
V_139 = V_153 ;
if ( V_146 ) {
V_139 |= V_154 ;
V_139 |= V_155 ;
} else
V_139 |= V_156 ;
if ( V_143 ) {
int V_157 =
V_105 -> clock / V_77 -> clock ;
V_139 |= V_155 ;
V_139 |=
( V_157 - 1 ) << V_158 ;
}
V_139 |= ( 1 << ( clock . V_15 - 1 ) ) << 16 ;
switch ( clock . V_16 ) {
case 5 :
V_139 |= V_159 ;
break;
case 7 :
V_139 |= V_160 ;
break;
case 10 :
V_139 |= V_161 ;
break;
case 14 :
V_139 |= V_162 ;
break;
}
if ( V_147 ) {
V_139 |= 3 ;
}
V_139 |= V_163 ;
V_141 = F_11 ( V_82 ) ;
V_64 = V_164 ;
if ( V_49 == 0 )
V_64 |= V_165 ;
else
V_64 |= V_166 ;
V_64 |= V_92 ;
V_141 |= V_91 ;
V_139 |= V_90 ;
if ( F_32 ( V_21 ) == V_49 )
F_21 ( V_107 , 0 ) ;
F_18 ( L_15 , V_49 == 0 ? 'A' : 'B' ) ;
F_34 ( V_77 ) ;
if ( V_139 & V_90 ) {
F_21 ( V_109 , V_140 ) ;
F_21 ( V_78 , V_139 & ~ V_90 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
}
if ( V_146 ) {
T_1 V_167 = F_11 ( V_33 ) ;
V_167 |=
V_34 | V_168 |
V_169 ;
if ( clock . V_16 == 7 )
V_167 |= V_170 | V_36 ;
else
V_167 &= ~ ( V_170 | V_36 ) ;
F_21 ( V_33 , V_167 ) ;
F_11 ( V_33 ) ;
}
F_21 ( V_109 , V_140 ) ;
F_21 ( V_78 , V_139 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
F_21 ( V_78 , V_139 ) ;
F_11 ( V_78 ) ;
F_13 ( 150 ) ;
F_21 ( V_112 , ( V_105 -> V_171 - 1 ) |
( ( V_105 -> V_172 - 1 ) << 16 ) ) ;
F_21 ( V_115 , ( V_105 -> V_173 - 1 ) |
( ( V_105 -> V_174 - 1 ) << 16 ) ) ;
F_21 ( V_118 , ( V_105 -> V_175 - 1 ) |
( ( V_105 -> V_176 - 1 ) << 16 ) ) ;
F_21 ( V_121 , ( V_105 -> V_177 - 1 ) |
( ( V_105 -> V_178 - 1 ) << 16 ) ) ;
F_21 ( V_124 , ( V_105 -> V_179 - 1 ) |
( ( V_105 -> V_180 - 1 ) << 16 ) ) ;
F_21 ( V_127 , ( V_105 -> V_181 - 1 ) |
( ( V_105 -> V_182 - 1 ) << 16 ) ) ;
F_21 ( V_130 ,
( ( V_77 -> V_183 - 1 ) << 16 ) | ( V_77 -> V_184 - 1 ) ) ;
F_21 ( V_133 , 0 ) ;
F_21 ( V_136 ,
( ( V_77 -> V_184 - 1 ) << 16 ) | ( V_77 -> V_183 - 1 ) ) ;
F_21 ( V_82 , V_141 ) ;
F_11 ( V_82 ) ;
F_12 ( V_21 ) ;
F_21 ( V_61 , V_64 ) ;
{
struct V_97 * V_98 =
V_3 -> V_99 ;
V_98 -> V_185 ( V_3 , V_41 , V_42 , V_44 ) ;
}
F_12 ( V_21 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_186 * V_187 =
(struct V_186 * ) V_21 -> V_188 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_189 = V_190 ;
int V_191 ;
if ( ! V_3 -> V_86 )
return;
switch ( V_45 -> V_49 ) {
case 0 :
break;
case 1 :
V_189 = V_192 ;
break;
case 2 :
V_189 = V_193 ;
break;
default:
F_22 ( L_16 ) ;
return;
}
if ( F_19 ( V_21 , false ) ) {
for ( V_191 = 0 ; V_191 < 256 ; V_191 ++ ) {
F_21 ( V_189 + 4 * V_191 ,
( ( V_45 -> V_194 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) << 16 ) |
( ( V_45 -> V_196 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) << 8 ) |
( V_45 -> V_197 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) ) ;
}
F_24 ( V_21 ) ;
} else {
for ( V_191 = 0 ; V_191 < 256 ; V_191 ++ ) {
V_187 -> V_198 [ V_191 ] =
( ( V_45 -> V_194 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) << 16 ) |
( ( V_45 -> V_196 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) << 8 ) |
( V_45 -> V_197 [ V_191 ] +
V_45 -> V_195 [ V_191 ] ) ;
}
}
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_199 * V_200 = V_45 -> V_200 ;
int V_201 = ( V_45 -> V_49 == 0 ) ;
T_2 V_202 ;
int V_191 ;
F_18 ( L_10 ) ;
if ( ! V_200 ) {
F_18 ( L_17 ) ;
return;
}
V_200 -> V_203 = F_11 ( V_201 ? V_62 : V_63 ) ;
V_200 -> V_204 = F_11 ( V_201 ? V_83 : V_84 ) ;
V_200 -> V_205 = F_11 ( V_201 ? V_137 : V_138 ) ;
V_200 -> V_206 = F_11 ( V_201 ? V_110 : V_111 ) ;
V_200 -> V_207 = F_11 ( V_201 ? V_208 : V_209 ) ;
V_200 -> V_210 = F_11 ( V_201 ? V_79 : V_80 ) ;
V_200 -> V_211 = F_11 ( V_201 ? V_113 : V_114 ) ;
V_200 -> V_212 = F_11 ( V_201 ? V_116 : V_117 ) ;
V_200 -> V_213 = F_11 ( V_201 ? V_119 : V_120 ) ;
V_200 -> V_214 = F_11 ( V_201 ? V_122 : V_123 ) ;
V_200 -> V_215 = F_11 ( V_201 ? V_125 : V_126 ) ;
V_200 -> V_216 = F_11 ( V_201 ? V_128 : V_129 ) ;
V_200 -> V_217 = F_11 ( V_201 ? V_59 : V_60 ) ;
V_200 -> V_218 = F_11 ( V_201 ? V_131 : V_132 ) ;
V_200 -> V_219 = F_11 ( V_201 ? V_134 : V_135 ) ;
V_200 -> V_220 = F_11 ( V_201 ? V_53 : V_54 ) ;
F_18 ( L_18 ,
V_200 -> V_203 ,
V_200 -> V_204 ,
V_200 -> V_205 ,
V_200 -> V_206 ,
V_200 -> V_207 ,
V_200 -> V_210 ,
V_200 -> V_211 ,
V_200 -> V_212 ,
V_200 -> V_213 ,
V_200 -> V_214 ,
V_200 -> V_215 ,
V_200 -> V_216 ,
V_200 -> V_217 ,
V_200 -> V_218 ,
V_200 -> V_219 ,
V_200 -> V_220
) ;
V_202 = V_201 ? V_190 : V_192 ;
for ( V_191 = 0 ; V_191 < 256 ; ++ V_191 )
V_200 -> V_221 [ V_191 ] = F_11 ( V_202 + ( V_191 << 2 ) ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_199 * V_200 = V_45 -> V_200 ;
int V_201 = ( V_45 -> V_49 == 0 ) ;
T_2 V_202 ;
int V_191 ;
F_18 ( L_10 ) ;
if ( ! V_200 ) {
F_18 ( L_19 ) ;
return;
}
F_18 (
L_20 ,
F_11 ( V_201 ? V_62 : V_63 ) ,
F_11 ( V_201 ? V_83 : V_84 ) ,
F_11 ( V_201 ? V_137 : V_138 ) ,
F_11 ( V_201 ? V_110 : V_111 ) ,
F_11 ( V_201 ? V_208 : V_209 ) ,
F_11 ( V_201 ? V_79 : V_80 ) ,
F_11 ( V_201 ? V_113 : V_114 ) ,
F_11 ( V_201 ? V_116 : V_117 ) ,
F_11 ( V_201 ? V_119 : V_120 ) ,
F_11 ( V_201 ? V_122 : V_123 ) ,
F_11 ( V_201 ? V_125 : V_126 ) ,
F_11 ( V_201 ? V_128 : V_129 ) ,
F_11 ( V_201 ? V_59 : V_60 ) ,
F_11 ( V_201 ? V_131 : V_132 ) ,
F_11 ( V_201 ? V_134 : V_135 ) ,
F_11 ( V_201 ? V_53 : V_54 )
) ;
F_18 (
L_21 ,
V_200 -> V_203 ,
V_200 -> V_204 ,
V_200 -> V_205 ,
V_200 -> V_206 ,
V_200 -> V_207 ,
V_200 -> V_210 ,
V_200 -> V_211 ,
V_200 -> V_212 ,
V_200 -> V_213 ,
V_200 -> V_214 ,
V_200 -> V_215 ,
V_200 -> V_216 ,
V_200 -> V_217 ,
V_200 -> V_218 ,
V_200 -> V_219 ,
V_200 -> V_220
) ;
if ( V_200 -> V_210 & V_90 ) {
F_21 ( V_201 ? V_79 : V_80 ,
V_200 -> V_210 & ~ V_90 ) ;
F_11 ( V_201 ? V_79 : V_80 ) ;
F_18 ( L_22 ,
F_11 ( V_201 ? V_79 : V_80 ) ) ;
F_13 ( 150 ) ;
}
F_21 ( V_201 ? V_110 : V_111 , V_200 -> V_206 ) ;
F_11 ( V_201 ? V_110 : V_111 ) ;
F_21 ( V_201 ? V_208 : V_209 , V_200 -> V_207 ) ;
F_11 ( V_201 ? V_208 : V_209 ) ;
F_21 ( V_201 ? V_79 : V_80 , V_200 -> V_210 ) ;
F_11 ( V_201 ? V_79 : V_80 ) ;
F_13 ( 150 ) ;
F_21 ( V_201 ? V_113 : V_114 , V_200 -> V_211 ) ;
F_21 ( V_201 ? V_116 : V_117 , V_200 -> V_212 ) ;
F_21 ( V_201 ? V_119 : V_120 , V_200 -> V_213 ) ;
F_21 ( V_201 ? V_122 : V_123 , V_200 -> V_214 ) ;
F_21 ( V_201 ? V_125 : V_126 , V_200 -> V_215 ) ;
F_21 ( V_201 ? V_128 : V_129 , V_200 -> V_216 ) ;
F_21 ( V_201 ? V_59 : V_60 , V_200 -> V_217 ) ;
F_21 ( V_201 ? V_131 : V_132 , V_200 -> V_218 ) ;
F_21 ( V_201 ? V_134 : V_135 , V_200 -> V_219 ) ;
F_21 ( V_201 ? V_137 : V_138 , V_200 -> V_205 ) ;
F_21 ( V_201 ? V_53 : V_54 , V_200 -> V_220 ) ;
F_21 ( V_201 ? V_83 : V_84 , V_200 -> V_204 ) ;
F_12 ( V_21 ) ;
F_21 ( V_201 ? V_62 : V_63 , V_200 -> V_203 ) ;
F_21 ( V_201 ? V_53 : V_54 , V_200 -> V_220 ) ;
F_12 ( V_21 ) ;
V_202 = V_201 ? V_190 : V_192 ;
for ( V_191 = 0 ; V_191 < 256 ; ++ V_191 )
F_21 ( V_202 + ( V_191 << 2 ) , V_200 -> V_221 [ V_191 ] ) ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_222 * V_223 ,
T_2 V_224 ,
T_2 V_225 , T_2 V_226 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_227 = ( V_49 == 0 ) ? V_228 : V_229 ;
T_2 V_230 = ( V_49 == 0 ) ? V_231 : V_232 ;
T_2 V_85 ;
T_3 V_233 = 0 ;
struct V_234 * V_235 ;
struct V_236 * V_237 ;
int V_65 ;
F_18 ( L_10 ) ;
if ( ! V_224 ) {
F_18 ( L_23 ) ;
V_85 = V_238 ;
if ( F_19 ( V_21 , false ) ) {
F_21 ( V_227 , V_85 ) ;
F_21 ( V_230 , 0 ) ;
F_24 ( V_21 ) ;
}
if ( V_45 -> V_239 ) {
V_235 = F_38 ( V_45 -> V_239 ,
struct V_234 , V_240 ) ;
F_23 ( V_235 ) ;
F_39 ( V_45 -> V_239 ) ;
V_45 -> V_239 = NULL ;
}
return 0 ;
}
if ( V_225 != 64 || V_226 != 64 ) {
F_22 ( L_24 ) ;
return - V_76 ;
}
V_237 = F_40 ( V_21 , V_223 , V_224 ) ;
if ( ! V_237 )
return - V_241 ;
if ( V_237 -> V_242 < V_225 * V_226 * 4 ) {
F_22 ( L_25 ) ;
return - V_243 ;
}
V_235 = F_38 ( V_237 , struct V_234 , V_240 ) ;
V_65 = F_20 ( V_235 ) ;
if ( V_65 ) {
F_22 ( L_26 , V_224 ) ;
return V_65 ;
}
V_233 = V_235 -> V_51 ;
V_45 -> V_244 = V_233 ;
V_85 = 0 ;
V_85 |= ( V_49 << 28 ) ;
V_85 |= V_245 | V_246 ;
if ( F_19 ( V_21 , false ) ) {
F_21 ( V_227 , V_85 ) ;
F_21 ( V_230 , V_233 ) ;
F_24 ( V_21 ) ;
}
if ( V_45 -> V_239 && V_45 -> V_239 != V_237 ) {
V_235 = F_38 ( V_45 -> V_239 ,
struct V_234 , V_240 ) ;
F_23 ( V_235 ) ;
F_39 ( V_45 -> V_239 ) ;
V_45 -> V_239 = V_237 ;
}
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , int V_41 , int V_42 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_2 V_85 = 0 ;
T_2 V_233 ;
if ( V_41 < 0 ) {
V_85 |= ( V_247 << V_248 ) ;
V_41 = - V_41 ;
}
if ( V_42 < 0 ) {
V_85 |= ( V_247 << V_249 ) ;
V_42 = - V_42 ;
}
V_85 |= ( ( V_41 & V_250 ) << V_248 ) ;
V_85 |= ( ( V_42 & V_250 ) << V_249 ) ;
V_233 = V_45 -> V_244 ;
if ( F_19 ( V_21 , false ) ) {
F_21 ( ( V_49 == 0 ) ? V_251 : V_252 , V_85 ) ;
F_21 ( ( V_49 == 0 ) ? V_231 : V_232 , V_233 ) ;
F_24 ( V_21 ) ;
}
return 0 ;
}
static void F_42 ( struct V_2 * V_3 , T_4 * V_253 ,
T_4 * V_254 , T_4 * V_255 , T_2 type , T_2 V_242 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_191 ;
if ( V_242 != 256 )
return;
for ( V_191 = 0 ; V_191 < 256 ; V_191 ++ ) {
V_45 -> V_194 [ V_191 ] = V_253 [ V_191 ] >> 8 ;
V_45 -> V_196 [ V_191 ] = V_254 [ V_191 ] >> 8 ;
V_45 -> V_197 [ V_191 ] = V_255 [ V_191 ] >> 8 ;
}
F_26 ( V_3 ) ;
}
static int F_43 ( struct V_256 * V_257 )
{
int V_65 ;
struct V_20 * V_21 = V_257 -> V_3 -> V_21 ;
struct V_186 * V_187 = V_21 -> V_188 ;
if ( ! V_187 -> V_258 )
return F_44 ( V_257 ) ;
F_45 ( & V_21 -> V_259 -> V_21 ) ;
V_65 = F_44 ( V_257 ) ;
F_46 ( & V_21 -> V_259 -> V_21 ) ;
return V_65 ;
}
static int F_47 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
T_1 V_139 ;
T_1 V_140 ;
struct V_10 clock ;
bool V_146 ;
struct V_186 * V_187 = V_21 -> V_188 ;
if ( F_19 ( V_21 , false ) ) {
V_139 = F_11 ( ( V_49 == 0 ) ? V_79 : V_80 ) ;
if ( ( V_139 & V_260 ) == 0 )
V_140 = F_11 ( ( V_49 == 0 ) ? V_110 : V_111 ) ;
else
V_140 = F_11 ( ( V_49 == 0 ) ? V_208 : V_209 ) ;
V_146 = ( V_49 == 1 ) && ( F_11 ( V_33 ) & V_34 ) ;
F_24 ( V_21 ) ;
} else {
V_139 = ( V_49 == 0 ) ?
V_187 -> V_261 : V_187 -> V_262 ;
if ( ( V_139 & V_260 ) == 0 )
V_140 = ( V_49 == 0 ) ?
V_187 -> V_263 :
V_187 -> V_264 ;
else
V_140 = ( V_49 == 0 ) ?
V_187 -> V_265 :
V_187 -> V_266 ;
V_146 = ( V_49 == 1 ) && ( V_187 -> V_267 & V_34 ) ;
}
clock . V_12 = ( V_140 & V_268 ) >> V_269 ;
clock . V_13 = ( V_140 & V_270 ) >> V_271 ;
clock . V_18 = ( V_140 & V_272 ) >> V_273 ;
if ( V_146 ) {
clock . V_15 =
F_48 ( ( V_139 &
V_274 ) >>
V_275 ) ;
clock . V_16 = 14 ;
if ( ( V_139 & V_276 ) ==
V_277 ) {
F_3 ( 66000 , & clock ) ;
} else
F_3 ( 48000 , & clock ) ;
} else {
if ( V_139 & V_278 )
clock . V_15 = 2 ;
else {
clock . V_15 =
( ( V_139 &
V_279 ) >>
V_275 ) + 2 ;
}
if ( V_139 & V_280 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
F_3 ( 48000 , & clock ) ;
}
return clock . V_19 ;
}
struct V_104 * F_49 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
int V_49 = V_45 -> V_49 ;
struct V_104 * V_77 ;
int V_281 ;
int V_282 ;
int V_283 ;
int V_284 ;
struct V_186 * V_187 = V_21 -> V_188 ;
if ( F_19 ( V_21 , false ) ) {
V_281 = F_11 ( ( V_49 == 0 ) ? V_113 : V_114 ) ;
V_282 = F_11 ( ( V_49 == 0 ) ? V_119 : V_120 ) ;
V_283 = F_11 ( ( V_49 == 0 ) ? V_122 : V_123 ) ;
V_284 = F_11 ( ( V_49 == 0 ) ? V_128 : V_129 ) ;
F_24 ( V_21 ) ;
} else {
V_281 = ( V_49 == 0 ) ?
V_187 -> V_285 : V_187 -> V_286 ;
V_282 = ( V_49 == 0 ) ?
V_187 -> V_287 : V_187 -> V_288 ;
V_283 = ( V_49 == 0 ) ?
V_187 -> V_289 : V_187 -> V_290 ;
V_284 = ( V_49 == 0 ) ?
V_187 -> V_291 : V_187 -> V_292 ;
}
V_77 = F_50 ( sizeof( * V_77 ) , V_293 ) ;
if ( ! V_77 )
return NULL ;
V_77 -> clock = F_47 ( V_21 , V_3 ) ;
V_77 -> V_184 = ( V_281 & 0xffff ) + 1 ;
V_77 -> V_294 = ( ( V_281 & 0xffff0000 ) >> 16 ) + 1 ;
V_77 -> V_295 = ( V_282 & 0xffff ) + 1 ;
V_77 -> V_296 = ( ( V_282 & 0xffff0000 ) >> 16 ) + 1 ;
V_77 -> V_183 = ( V_283 & 0xffff ) + 1 ;
V_77 -> V_297 = ( ( V_283 & 0xffff0000 ) >> 16 ) + 1 ;
V_77 -> V_298 = ( V_284 & 0xffff ) + 1 ;
V_77 -> V_299 = ( ( V_284 & 0xffff0000 ) >> 16 ) + 1 ;
F_51 ( V_77 ) ;
F_52 ( V_77 , 0 ) ;
return V_77 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_45 * V_45 = F_15 ( V_3 ) ;
struct V_234 * V_235 ;
if ( V_45 -> V_239 ) {
V_235 = F_38 ( V_45 -> V_239 ,
struct V_234 , V_240 ) ;
F_23 ( V_235 ) ;
F_39 ( V_45 -> V_239 ) ;
V_45 -> V_239 = NULL ;
}
F_54 ( V_45 -> V_200 ) ;
F_55 ( V_3 ) ;
F_54 ( V_45 ) ;
}
void F_56 ( struct V_20 * V_21 , int V_49 ,
struct V_300 * V_301 )
{
struct V_186 * V_187 = V_21 -> V_188 ;
struct V_45 * V_45 ;
int V_191 ;
T_5 * V_302 , * V_303 , * V_304 ;
F_17 ( L_10 ) ;
V_45 =
F_50 ( sizeof( struct V_45 ) +
( V_305 * sizeof( struct V_24 * ) ) ,
V_293 ) ;
if ( V_45 == NULL )
return;
V_45 -> V_200 =
F_50 ( sizeof( struct V_199 ) , V_293 ) ;
if ( ! V_45 -> V_200 ) {
F_57 ( L_27 ) ;
F_54 ( V_45 ) ;
return;
}
F_58 ( V_21 , & V_45 -> V_230 , & V_306 ) ;
F_59 ( & V_45 -> V_230 , 256 ) ;
V_45 -> V_49 = V_49 ;
V_45 -> V_307 = V_49 ;
V_302 = V_45 -> V_230 . V_308 ;
V_303 = V_302 + 256 ;
V_304 = V_303 + 256 ;
for ( V_191 = 0 ; V_191 < 256 ; V_191 ++ ) {
V_45 -> V_194 [ V_191 ] = V_191 ;
V_45 -> V_196 [ V_191 ] = V_191 ;
V_45 -> V_197 [ V_191 ] = V_191 ;
V_302 [ V_191 ] = V_191 << 8 ;
V_303 [ V_191 ] = V_191 << 8 ;
V_304 [ V_191 ] = V_191 << 8 ;
V_45 -> V_195 [ V_191 ] = 0 ;
}
V_45 -> V_301 = V_301 ;
V_45 -> V_244 = 0 ;
if ( F_60 ( V_21 ) )
F_61 ( & V_45 -> V_230 ,
& V_309 ) ;
else
F_61 ( & V_45 -> V_230 ,
& V_310 ) ;
V_45 -> V_311 . V_3 = & V_45 -> V_230 ;
F_62 ( V_49 >= F_63 ( V_187 -> V_312 ) ||
V_187 -> V_312 [ V_45 -> V_307 ] != NULL ) ;
V_187 -> V_312 [ V_45 -> V_307 ] =
& V_45 -> V_230 ;
V_187 -> V_313 [ V_45 -> V_49 ] =
& V_45 -> V_230 ;
V_45 -> V_311 . V_314 =
(struct V_24 * * ) ( V_45 + 1 ) ;
V_45 -> V_311 . V_315 = 0 ;
}
int F_64 ( struct V_20 * V_21 , void * V_316 ,
struct V_222 * V_223 )
{
struct V_186 * V_187 = V_21 -> V_188 ;
struct V_317 * V_318 = V_316 ;
struct V_319 * V_320 ;
struct V_45 * V_3 ;
if ( ! V_187 ) {
F_22 ( L_28 ) ;
return - V_76 ;
}
V_320 = F_65 ( V_21 , V_318 -> V_321 ,
V_322 ) ;
if ( ! V_320 ) {
F_22 ( L_29 ) ;
return - V_76 ;
}
V_3 = F_15 ( F_66 ( V_320 ) ) ;
V_318 -> V_49 = V_3 -> V_49 ;
return 0 ;
}
struct V_2 * F_67 ( struct V_20 * V_21 , int V_49 )
{
struct V_2 * V_3 = NULL ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_45 * V_45 = F_15 ( V_3 ) ;
if ( V_45 -> V_49 == V_49 )
break;
}
return V_3 ;
}
int F_68 ( struct V_20 * V_21 , int V_323 )
{
int V_324 = 0 ;
struct V_24 * V_148 ;
int V_325 = 0 ;
F_6 (connector, &dev->mode_config.connector_list,
head) {
struct V_27 * V_27 =
F_7 ( V_148 ) ;
if ( V_323 & ( 1 << V_27 -> type ) )
V_324 |= ( 1 << V_325 ) ;
V_325 ++ ;
}
return V_324 ;
}
void F_69 ( struct V_20 * V_21 )
{
F_70 ( V_21 ) ;
}
struct V_101 * F_71 ( struct V_24 * V_148 )
{
struct V_27 * V_27 =
F_7 ( V_148 ) ;
return & V_27 -> V_326 ;
}
