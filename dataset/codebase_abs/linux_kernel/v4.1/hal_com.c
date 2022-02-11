T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 ,
bool V_6 )
{
T_1 V_7 ;
T_1 V_8 ;
V_7 = true ;
if ( ! V_6 ) {
if ( ! F_2 ( V_4 ) )
V_7 = false ;
if ( V_3 & V_9 )
V_7 = false ;
}
if ( V_7 == true )
V_8 = V_4 ;
else
V_8 = V_3 & ( ~ V_9 ) ;
if ( ! F_2 ( V_8 ) )
V_8 = V_5 ;
return V_8 ;
}
T_1 F_3 ( T_1 V_10 )
{
T_1 V_11 = V_12 ;
switch ( V_10 ) {
case V_13 :
V_11 = V_12 ;
break;
case V_14 :
V_11 = V_15 ;
break;
case V_16 :
V_11 = V_17 ;
break;
case V_18 :
V_11 = V_19 ;
break;
case V_20 :
V_11 = V_21 ;
break;
case V_22 :
V_11 = V_23 ;
break;
case V_24 :
V_11 = V_25 ;
break;
case V_26 :
V_11 = V_27 ;
break;
case V_28 :
V_11 = V_29 ;
break;
case V_30 :
V_11 = V_31 ;
break;
case V_32 :
V_11 = V_33 ;
break;
case V_34 :
V_11 = V_35 ;
break;
default:
break;
}
return V_11 ;
}
void F_4 ( struct V_1 * V_2 , T_1 * V_36 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
T_1 V_39 , V_40 , V_41 ;
T_2 V_42 = 0 ;
T_1 V_43 ;
for ( V_39 = 0 ; V_39 < V_44 ; V_39 ++ ) {
V_40 = V_36 [ V_39 ] & V_45 ;
V_41 = V_36 [ V_39 ] & 0x7f ;
if ( V_40 ) {
switch ( V_41 ) {
case V_13 :
V_42 |= V_46 ;
break;
case V_14 :
V_42 |= V_47 ;
break;
case V_16 :
V_42 |= V_48 ;
break;
case V_18 :
V_42 |= V_49 ;
break;
case V_20 :
V_42 |= V_50 ;
break;
case V_22 :
V_42 |= V_51 ;
break;
case V_24 :
V_42 |= V_52 ;
break;
case V_26 :
V_42 |= V_53 ;
break;
case V_28 :
V_42 |= V_54 ;
break;
case V_30 :
V_42 |= V_55 ;
break;
case V_32 :
V_42 |= V_56 ;
break;
case V_34 :
V_42 |= V_57 ;
break;
}
}
}
V_42 = ( V_42 | 0xd ) & 0x15d ;
V_38 -> V_58 = V_42 ;
V_42 |= 0x01 ;
F_6 ( L_1 , V_42 ) ;
F_7 ( V_2 , V_59 , V_42 & 0xff ) ;
F_7 ( V_2 , V_59 + 1 , ( V_42 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_59 + 2 ,
F_8 ( V_2 , V_59 + 2 ) & 0xf0 ) ;
V_43 = 0 ;
while ( V_42 > 0x1 ) {
V_42 >>= 1 ;
V_43 ++ ;
}
F_7 ( V_2 , V_60 , V_43 ) ;
}
static void F_9 ( struct V_1 * V_61 )
{
struct V_62 * V_63 = F_10 ( V_61 ) ;
V_63 -> V_64 [ 0 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 1 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 2 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 3 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 4 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 5 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 6 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 7 ] = V_63 -> V_65 [ 0 ] ;
}
static void F_11 ( struct V_1 * V_61 , bool V_66 )
{
struct V_62 * V_63 = F_10 ( V_61 ) ;
if ( V_66 ) {
V_63 -> V_64 [ 0 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 1 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 2 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 3 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 4 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 5 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 6 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 7 ] = V_63 -> V_65 [ 0 ] ;
} else {
V_63 -> V_64 [ 0 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 1 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 2 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 3 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 4 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 5 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 6 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 7 ] = V_63 -> V_65 [ 0 ] ;
}
}
static void F_12 ( struct V_1 * V_61 , bool V_66 )
{
struct V_62 * V_63 = F_10 ( V_61 ) ;
if ( V_66 ) {
V_63 -> V_64 [ 0 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 1 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 2 ] = V_63 -> V_65 [ 2 ] ;
V_63 -> V_64 [ 3 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 4 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 5 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 6 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 7 ] = V_63 -> V_65 [ 0 ] ;
} else {
V_63 -> V_64 [ 0 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 1 ] = V_63 -> V_65 [ 1 ] ;
V_63 -> V_64 [ 2 ] = V_63 -> V_65 [ 2 ] ;
V_63 -> V_64 [ 3 ] = V_63 -> V_65 [ 2 ] ;
V_63 -> V_64 [ 4 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 5 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 6 ] = V_63 -> V_65 [ 0 ] ;
V_63 -> V_64 [ 7 ] = V_63 -> V_65 [ 0 ] ;
}
}
bool F_13 ( struct V_1 * V_61 , T_1 V_67 )
{
struct V_68 * V_69 = & V_61 -> V_70 ;
bool V_66 = ( V_69 -> V_71 ) ? true : false ;
bool V_72 = true ;
switch ( V_67 ) {
case 2 :
F_11 ( V_61 , V_66 ) ;
break;
case 3 :
F_12 ( V_61 , V_66 ) ;
break;
case 1 :
F_9 ( V_61 ) ;
break;
default:
V_72 = false ;
break;
}
return V_72 ;
}
void F_14 ( struct V_1 * V_73 )
{
F_7 ( V_73 , V_74 , V_75 ) ;
}
int F_15 ( struct V_1 * V_73 , T_1 * V_76 )
{
int V_11 = V_77 ;
struct V_78 * V_79 ;
int V_39 ;
T_1 V_80 ;
if ( V_76 == NULL )
goto exit;
V_80 = F_8 ( V_73 , V_74 ) ;
if ( V_80 == V_75 )
goto exit;
else if ( V_80 != V_81 )
goto V_82;
V_79 = (struct V_78 * ) V_76 ;
memset ( V_79 , 0 , 16 ) ;
* V_76 = F_8 ( V_73 , V_83 ) ;
* ( V_76 + 1 ) = F_8 ( V_73 , V_83 + 1 ) ;
F_16 ( V_84 , V_85 , L_2 ,
& V_79 , sizeof( V_79 ) ) ;
if ( 0 ) {
F_6 ( L_3 ,
V_86 , V_79 -> V_87 , V_79 -> V_88 , V_79 -> V_89 ,
V_80 ) ;
}
for ( V_39 = 0 ; V_39 < V_79 -> V_88 ; V_39 ++ )
V_79 -> V_90 [ V_39 ] = F_8 ( V_73 ,
V_83 +
sizeof( * V_79 ) + V_39 ) ;
F_16 ( V_84 , V_85 ,
L_4 , V_79 -> V_90 ,
V_79 -> V_88 ) ;
V_11 = V_91 ;
V_82:
F_14 ( V_73 ) ;
exit:
return V_11 ;
}
void
F_17 ( struct V_1 * V_2 , T_1 V_92 )
{
T_1 V_93 ;
if ( V_92 <= 7 ) {
switch ( V_2 -> V_94 . V_95 ) {
case 0 :
case V_96 :
V_93 = 0 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_93 = 6 ;
break;
default:
V_93 = 7 ;
break;
}
if ( V_92 < V_93 )
V_92 = V_93 ;
V_92 |=
F_8 ( V_2 , V_100 ) & 0xf8 ;
F_7 ( V_2 , V_100 ,
V_92 ) ;
}
}
void F_18 ( struct V_1 * V_2 , T_1 V_101 )
{
T_1 V_102 [ 4 ] = { 0x41 , 0xa8 , 0x72 , 0xb9 } ;
T_1 V_103 ;
T_1 * V_104 ;
T_1 V_105 = 0 ;
V_104 = V_102 ;
if ( F_19 ( V_2 ) &&
F_20 ( V_2 ) )
V_103 = 0x8 ;
else
V_103 = 0xF ;
if ( V_101 <= 3 ) {
V_101 = 1 << ( V_101 + 2 ) ;
if ( V_101 > V_103 )
V_101 = V_103 ;
for ( V_105 = 0 ; V_105 < 4 ; V_105 ++ ) {
if ( ( V_104 [ V_105 ] & 0xf0 ) > ( V_101 << 4 ) )
V_104 [ V_105 ] = ( V_104 [ V_105 ] & 0x0f ) |
( V_101 << 4 ) ;
if ( ( V_104 [ V_105 ] & 0x0f ) > V_101 )
V_104 [ V_105 ] = ( V_104 [ V_105 ] & 0xf0 ) |
V_101 ;
F_7 ( V_2 , V_106 + V_105 ,
V_104 [ V_105 ] ) ;
}
}
}
void F_21 ( struct V_1 * V_2 , T_1 V_107 )
{
T_1 V_108 = 0 ;
if ( V_107 != 0 ) {
V_108 |= V_109 ;
if ( V_107 & F_22 ( 1 ) )
V_108 |= V_110 ;
if ( V_107 & F_22 ( 2 ) )
V_108 |= V_111 ;
if ( V_107 & F_22 ( 3 ) )
V_108 |= V_112 ;
}
F_6 ( L_5 , V_108 ) ;
F_7 ( V_2 , V_113 , V_108 ) ;
}
void F_23 ( struct V_1 * V_2 , T_1 V_114 )
{
T_1 V_115 ;
V_115 = F_8 ( V_2 , V_116 ) & 0x0c ;
V_115 |= V_114 ;
F_7 ( V_2 , V_116 , V_115 ) ;
}
void F_24 ( struct V_1 * V_2 , T_1 V_114 )
{
T_1 V_115 ;
V_115 = F_8 ( V_2 , V_116 ) & 0x03 ;
V_115 |= V_114 << 2 ;
F_7 ( V_2 , V_116 , V_115 ) ;
}
void F_25 ( struct V_1 * V_2 , T_1 V_117 )
{
if ( V_117 )
F_26 ( V_2 , V_118 | V_119 , 0 ) ;
else
F_26 ( V_2 , 0 , V_118 | V_119 ) ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_117 )
{
T_3 V_120 ;
V_120 = F_28 ( V_2 , V_121 ) ;
if ( V_117 )
V_120 |= V_122 | V_123 ;
else
V_120 &= ~ ( V_122 | V_123 ) ;
F_29 ( V_2 , V_121 , V_120 ) ;
}
void F_30 ( struct V_1 * V_2 , T_1 V_124 )
{
if ( V_124 ) {
T_3 V_125 ;
V_125 = F_28 ( V_2 , V_121 ) ;
V_125 &= ~ ( V_123 ) ;
F_29 ( V_2 , V_121 , V_125 ) ;
F_31 ( V_2 , V_126 , 0 ) ;
F_26 ( V_2 , V_127 , 0 ) ;
} else {
struct V_128 * V_129 = & V_2 -> V_130 ;
struct V_131 * V_132 ;
T_3 V_125 ;
V_132 = & V_129 -> V_133 ;
if ( ( F_32 ( V_2 ) == true ) ||
( ( V_132 -> V_134 & 0x03 ) == V_135 ) ||
( ( V_132 -> V_134 & 0x03 ) == V_136 ) ) {
F_31 ( V_2 , V_126 , 0xFFFF ) ;
F_26 ( V_2 , 0 , V_127 ) ;
}
V_125 = F_28 ( V_2 , V_121 ) ;
V_125 |= V_123 ;
F_29 ( V_2 , V_121 , V_125 ) ;
}
F_33 ( V_2 , V_124 ? true : false ) ;
}
void F_34 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_121 ,
F_28 ( V_2 , V_121 ) | V_137 ) ;
F_6 ( L_6 , V_86 , __LINE__ ,
F_28 ( V_2 , V_121 ) ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_121 ,
F_28 ( V_2 , V_121 ) & ( ~ V_137 ) ) ;
F_6 ( L_6 , V_86 , __LINE__ ,
F_28 ( V_2 , V_121 ) ) ;
}
void F_36 ( struct V_1 * V_2 , T_1 V_138 )
{
T_1 V_139 , V_140 ;
struct V_128 * V_129 = & V_2 -> V_130 ;
struct V_131 * V_132 = & V_129 -> V_133 ;
F_7 ( V_2 , V_141 , V_138 ) ;
if ( V_132 -> V_142 == 0 ) {
if ( V_129 -> V_143 == V_144 )
V_140 = 10 ;
else
V_140 = 16 ;
V_139 = V_140 + ( 2 * V_132 -> V_145 ) ;
F_7 ( V_2 , V_146 , V_139 ) ;
F_7 ( V_2 , V_147 , V_139 ) ;
F_7 ( V_2 , V_148 , V_139 ) ;
F_7 ( V_2 , V_149 , V_139 ) ;
}
}
void F_37 ( struct V_1 * V_2 , T_1 V_150 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
T_1 V_151 ;
V_151 = ( V_38 -> V_152 ) << 5 ;
if ( V_150 )
V_151 |= 0x80 ;
F_7 ( V_2 , V_59 + 2 , V_151 ) ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_153 )
{
F_7 ( V_2 , V_154 , V_153 ) ;
}
void F_39 ( struct V_1 * V_2 , T_1 V_155 )
{
T_1 V_39 ;
T_3 V_156 = 0 ;
T_3 V_157 = 0 ;
T_3 V_158 = V_159 ;
for ( V_39 = 0 ; V_39 < V_160 ; V_39 ++ ) {
if ( V_39 == 0 ) {
V_157 |= ( V_155 & 0x03 ) |
( ( T_2 ) ( V_158 ) << 2 ) ;
} else {
V_157 = 0 ;
}
V_156 = V_160 * V_155 + V_39 ;
V_156 = V_156 | V_161 | V_162 ;
F_29 ( V_2 , V_163 , V_157 ) ;
F_29 ( V_2 , V_164 , V_156 ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
F_29 ( V_2 , V_164 , V_161 | F_22 ( 30 ) ) ;
}
void F_41 ( struct V_1 * V_2 ,
T_1 V_165 , T_2 V_107 , const T_1 * V_166 , const T_1 * V_167 )
{
T_3 V_168 ;
unsigned int V_39 , V_117 , V_169 ;
int V_170 ;
V_169 = V_165 << 3 ;
for ( V_170 = 5 ; V_170 >= 0 ; V_170 -- ) {
switch ( V_170 ) {
case 0 :
V_117 = V_107 | ( V_166 [ 0 ] << 16 ) | ( V_166 [ 1 ] << 24 ) ;
break;
case 1 :
V_117 = V_166 [ 2 ] | ( V_166 [ 3 ] << 8 ) |
( V_166 [ 4 ] << 16 ) | ( V_166 [ 5 ] << 24 ) ;
break;
default:
V_39 = ( V_170 - 2 ) << 2 ;
V_117 = V_167 [ V_39 ] | ( V_167 [ V_39 + 1 ] << 8 ) |
( V_167 [ V_39 + 2 ] << 16 ) | ( V_167 [ V_39 + 3 ] << 24 ) ;
break;
}
F_29 ( V_2 , V_163 , V_117 ) ;
V_168 = V_161 | V_162 | ( V_169 + V_170 ) ;
F_29 ( V_2 , V_164 , V_168 ) ;
}
}
void F_42 ( struct V_1 * V_2 )
{
#define F_43 BIT(18)
#define F_44 BIT(17)
struct V_171 * V_172 = & V_2 -> V_173 ;
T_1 V_174 = 100 ;
F_7 ( V_2 , V_175 , 0xff ) ;
V_2 -> V_176 . V_177 = F_8 ( V_2 , V_178 ) ;
if ( V_172 -> V_179 != true ) {
T_3 V_125 ;
V_125 = F_28 ( V_2 , V_180 ) ;
V_125 |= F_43 ;
F_29 ( V_2 , V_180 , V_125 ) ;
do {
V_125 = F_28 ( V_2 ,
V_180 ) & F_44 ;
if ( ! V_125 )
break;
} while ( V_174 -- );
if ( V_174 == 0 )
F_6 ( L_7 ) ;
F_31 ( V_2 , V_181 , 0 ) ;
F_29 ( V_2 , V_182 , 0x80000000 ) ;
F_45 ( 10 ) ;
}
}
void F_46 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_183 + 2 ,
F_8 ( V_2 , V_183 + 2 ) | F_22 ( 0 ) ) ;
}
bool F_47 ( struct V_1 * V_2 )
{
bool V_184 ;
V_184 = ( F_8 ( V_2 , V_183 + 2 ) & F_22 ( 0 ) ) ? true : false ;
return V_184 ;
}
void F_48 ( struct V_1 * V_2 , T_2 V_185 )
{
F_31 ( V_2 , V_186 , V_185 ) ;
}
void F_49 ( struct V_1 * V_2 ,
T_1 V_187 , T_1 V_188 , T_1 V_189 , T_1 V_190 )
{
F_7 ( V_2 , V_191 , V_187 ) ;
F_7 ( V_2 , V_191 + 1 , V_188 ) ;
F_7 ( V_2 , V_192 , V_189 ) ;
F_7 ( V_2 , V_192 + 1 , V_190 ) ;
}
void F_50 ( struct V_1 * V_2 , T_3 V_193 )
{
F_29 ( V_2 , V_146 , V_193 ) ;
}
void F_51 ( struct V_1 * V_2 , T_3 V_194 )
{
F_29 ( V_2 , V_147 , V_194 ) ;
}
void F_52 ( struct V_1 * V_2 , T_3 V_195 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
V_38 -> V_196 = V_195 ;
F_29 ( V_2 , V_148 , V_195 ) ;
}
void F_53 ( struct V_1 * V_2 , T_3 V_197 )
{
F_29 ( V_2 , V_149 , V_197 ) ;
}
void F_54 ( struct V_1 * V_2 , T_1 V_117 )
{
F_7 ( V_2 , V_198 , V_117 ) ;
}
void F_55 ( struct V_1 * V_2 , T_3 V_199 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
struct V_200 * V_201 = & V_38 -> V_202 . V_203 ;
if ( V_199 == 0xff )
F_56 ( & V_38 -> V_202 , V_201 -> V_204 ) ;
else {
V_201 -> V_204 = V_201 -> V_205 ;
F_56 ( & V_38 -> V_202 , V_199 ) ;
}
}
void F_57 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
V_38 -> V_202 . V_206 = V_38 -> V_202 . V_207 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
V_38 -> V_202 . V_207 = V_38 -> V_202 . V_206 ;
}
void F_59 ( struct V_1 * V_2 , T_3 V_117 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
if ( V_117 == V_208 )
V_38 -> V_202 . V_206 = V_38 -> V_209 . V_210 ;
else
V_38 -> V_202 . V_206 |= V_117 ;
}
void F_60 ( struct V_1 * V_2 , T_3 V_117 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
V_38 -> V_202 . V_206 &= V_117 ;
}
void F_61 ( struct V_1 * V_2 , T_1 V_117 )
{
F_7 ( V_2 , V_211 , V_117 ) ;
}
T_1 F_62 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_5 ( V_2 ) ;
return V_38 -> V_212 ;
}
bool F_63 ( struct V_1 * V_2 )
{
bool V_184 ;
T_3 V_213 ;
if ( ( V_2 -> V_214 == true ) ||
( V_2 -> V_173 . V_215 == V_216 ) ) {
V_184 = true ;
} else {
V_213 = F_28 ( V_2 , V_121 ) ;
if ( V_213 & 0x00070000 )
V_184 = false ;
else
V_184 = true ;
}
return V_184 ;
}
bool F_64 ( struct V_1 * V_2 )
{
T_3 V_217 ;
V_217 = F_28 ( V_2 , V_218 ) ;
return ( ( V_217 & 0x0000ff00 ) == 0 ) ? true : false ;
}
