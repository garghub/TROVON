void F_1 ( struct V_1 V_2 )
{
int V_3 = 0 ;
T_1 V_4 [ 128 ] ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_1 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_2 , F_2 ( V_2 ) ?
L_3 : L_4 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_2 ,
F_3 ( V_2 ) ? L_5 : L_6 ) ;
if ( F_4 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_7 ) ;
else if ( F_5 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_8 ) ;
else if ( F_6 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_9 ) ;
else if ( F_7 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_10 ) ;
else if ( F_8 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_11 ) ;
else
V_3 += sprintf ( ( V_4 + V_3 ) , L_12 ,
V_2 . V_5 ) ;
if ( F_9 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_13 ) ;
else if ( F_10 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_14 ) ;
else if ( F_11 ( V_2 ) )
V_3 += sprintf ( ( V_4 + V_3 ) , L_15 ) ;
else
V_3 += sprintf ( ( V_4 + V_3 ) , L_16 ,
V_2 . V_6 ) ;
V_3 += sprintf ( ( V_4 + V_3 ) , L_17 , V_2 . V_7 ) ;
F_12 ( L_18 , V_4 ) ;
}
T_1 F_13 ( struct V_8 * V_9 , T_1 V_10 ,
T_1 V_11 , T_1 V_12 ,
bool V_13 )
{
T_1 V_14 ;
T_1 V_15 ;
V_14 = true ;
if ( ! V_13 ) {
if ( ! F_14 ( V_11 ) )
V_14 = false ;
if ( V_10 & V_16 )
V_14 = false ;
}
if ( V_14 == true )
V_15 = V_11 ;
else
V_15 = V_10 & ( ~ V_16 ) ;
if ( ! F_14 ( V_15 ) )
V_15 = V_12 ;
return V_15 ;
}
T_1 F_15 ( T_1 V_17 )
{
T_1 V_18 = V_19 ;
switch ( V_17 ) {
case V_20 :
V_18 = V_19 ;
break;
case V_21 :
V_18 = V_22 ;
break;
case V_23 :
V_18 = V_24 ;
break;
case V_25 :
V_18 = V_26 ;
break;
case V_27 :
V_18 = V_28 ;
break;
case V_29 :
V_18 = V_30 ;
break;
case V_31 :
V_18 = V_32 ;
break;
case V_33 :
V_18 = V_34 ;
break;
case V_35 :
V_18 = V_36 ;
break;
case V_37 :
V_18 = V_38 ;
break;
case V_39 :
V_18 = V_40 ;
break;
case V_41 :
V_18 = V_42 ;
break;
default:
break;
}
return V_18 ;
}
void F_16 ( struct V_8 * V_9 , T_1 * V_43 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
T_1 V_46 , V_47 , V_48 ;
T_2 V_49 = 0 ;
T_1 V_50 ;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
V_47 = V_43 [ V_46 ] & V_52 ;
V_48 = V_43 [ V_46 ] & 0x7f ;
if ( V_47 ) {
switch ( V_48 ) {
case V_20 :
V_49 |= V_53 ;
break;
case V_21 :
V_49 |= V_54 ;
break;
case V_23 :
V_49 |= V_55 ;
break;
case V_25 :
V_49 |= V_56 ;
break;
case V_27 :
V_49 |= V_57 ;
break;
case V_29 :
V_49 |= V_58 ;
break;
case V_31 :
V_49 |= V_59 ;
break;
case V_33 :
V_49 |= V_60 ;
break;
case V_35 :
V_49 |= V_61 ;
break;
case V_37 :
V_49 |= V_62 ;
break;
case V_39 :
V_49 |= V_63 ;
break;
case V_41 :
V_49 |= V_64 ;
break;
}
}
}
V_49 = ( V_49 | 0xd ) & 0x15d ;
V_45 -> V_65 = V_49 ;
V_49 |= 0x01 ;
F_12 ( L_19 , V_49 ) ;
F_18 ( V_9 , V_66 , V_49 & 0xff ) ;
F_18 ( V_9 , V_66 + 1 , ( V_49 >> 8 ) & 0xff ) ;
F_18 ( V_9 , V_66 + 2 ,
F_19 ( V_9 , V_66 + 2 ) & 0xf0 ) ;
V_50 = 0 ;
while ( V_49 > 0x1 ) {
V_49 = ( V_49 >> 1 ) ;
V_50 ++ ;
}
F_18 ( V_9 , V_67 , V_50 ) ;
return;
}
static void F_20 ( struct V_8 * V_68 )
{
struct V_69 * V_70 = F_21 ( V_68 ) ;
V_70 -> V_71 [ 0 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 1 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 2 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 3 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 4 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 5 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 6 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 7 ] = V_70 -> V_72 [ 0 ] ;
}
static void F_22 ( struct V_8 * V_68 , bool V_73 )
{
struct V_69 * V_70 = F_21 ( V_68 ) ;
if ( V_73 ) {
V_70 -> V_71 [ 0 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 1 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 2 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 3 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 4 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 5 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 6 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 7 ] = V_70 -> V_72 [ 0 ] ;
} else {
V_70 -> V_71 [ 0 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 1 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 2 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 3 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 4 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 5 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 6 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 7 ] = V_70 -> V_72 [ 0 ] ;
}
}
static void F_23 ( struct V_8 * V_68 , bool V_73 )
{
struct V_69 * V_70 = F_21 ( V_68 ) ;
if ( V_73 ) {
V_70 -> V_71 [ 0 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 1 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 2 ] = V_70 -> V_72 [ 2 ] ;
V_70 -> V_71 [ 3 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 4 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 5 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 6 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 7 ] = V_70 -> V_72 [ 0 ] ;
} else {
V_70 -> V_71 [ 0 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 1 ] = V_70 -> V_72 [ 1 ] ;
V_70 -> V_71 [ 2 ] = V_70 -> V_72 [ 2 ] ;
V_70 -> V_71 [ 3 ] = V_70 -> V_72 [ 2 ] ;
V_70 -> V_71 [ 4 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 5 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 6 ] = V_70 -> V_72 [ 0 ] ;
V_70 -> V_71 [ 7 ] = V_70 -> V_72 [ 0 ] ;
}
}
bool F_24 ( struct V_8 * V_68 , T_1 V_74 )
{
struct V_75 * V_76 = & V_68 -> V_77 ;
bool V_73 = ( V_76 -> V_78 ) ? true : false ;
bool V_79 = true ;
switch ( V_74 ) {
case 2 :
F_22 ( V_68 , V_73 ) ;
break;
case 3 :
F_23 ( V_68 , V_73 ) ;
break;
case 1 :
F_20 ( V_68 ) ;
break;
default:
V_79 = false ;
break;
}
return V_79 ;
}
void F_25 ( struct V_8 * V_80 )
{
F_26 ( V_80 , V_81 ,
V_80 -> V_82 . V_83 ) ;
}
void F_27 ( struct V_8 * V_80 )
{
F_18 ( V_80 , V_84 , V_85 ) ;
}
T_3 F_28 ( struct V_8 * V_80 , T_1 * V_4 )
{
T_3 V_18 = V_86 ;
struct V_87 * V_88 ;
int V_46 ;
T_1 V_89 ;
if ( V_4 == NULL )
goto exit;
V_89 = F_19 ( V_80 , V_84 ) ;
if ( V_89 == V_85 )
goto exit;
else if ( V_89 != V_90 )
goto V_91;
V_88 = (struct V_87 * ) V_4 ;
memset ( V_88 , 0 , 16 ) ;
* V_4 = F_19 ( V_80 , V_92 ) ;
* ( V_4 + 1 ) = F_19 ( V_80 , V_92 + 1 ) ;
F_29 ( V_93 , V_94 , L_20 ,
& V_88 , sizeof( V_88 ) ) ;
if ( 0 ) {
F_12 ( L_21 ,
V_95 , V_88 -> V_96 , V_88 -> V_97 , V_88 -> V_98 ,
V_89 ) ;
}
for ( V_46 = 0 ; V_46 < V_88 -> V_97 ; V_46 ++ )
V_88 -> V_99 [ V_46 ] = F_19 ( V_80 ,
V_92 +
sizeof( * V_88 ) + V_46 ) ;
F_29 ( V_93 , V_94 ,
L_22 , V_88 -> V_99 ,
V_88 -> V_97 ) ;
V_18 = V_100 ;
V_91:
F_27 ( V_80 ) ;
exit:
return V_18 ;
}
void
F_30 ( struct V_8 * V_9 , T_1 V_101 )
{
T_1 V_102 ;
if ( V_101 <= 7 ) {
switch ( V_9 -> V_103 . V_104 ) {
case V_105 :
case V_106 :
V_102 = 0 ;
break;
case V_107 :
case V_108 :
case V_109 :
case V_110 :
V_102 = 6 ;
break;
default:
V_102 = 7 ;
break;
}
if ( V_101 < V_102 )
V_101 = V_102 ;
V_101 |=
F_19 ( V_9 , V_111 ) & 0xf8 ;
F_18 ( V_9 , V_111 ,
V_101 ) ;
}
}
void F_31 ( struct V_8 * V_9 , T_1 V_112 )
{
T_1 V_113 [ 4 ] = { 0x41 , 0xa8 , 0x72 , 0xb9 } ;
T_1 V_114 ;
T_1 * V_115 ;
T_1 V_116 = 0 ;
V_115 = V_113 ;
#ifdef F_32
if ( ( F_33 ( V_9 ) == false ) &&
( F_34 ( V_9 ) == true ) ) {
V_114 = 0x8 ;
} else
#endif
{
V_114 = 0xF ;
}
if ( V_112 <= 3 ) {
V_112 = ( 1 << ( V_112 + 2 ) ) ;
if ( V_112 > V_114 )
V_112 = V_114 ;
for ( V_116 = 0 ; V_116 < 4 ; V_116 ++ ) {
if ( ( V_115 [ V_116 ] & 0xf0 ) > ( V_112 << 4 ) )
V_115 [ V_116 ] = ( V_115 [ V_116 ] & 0x0f ) |
( V_112 << 4 ) ;
if ( ( V_115 [ V_116 ] & 0x0f ) > V_112 )
V_115 [ V_116 ] = ( V_115 [ V_116 ] & 0xf0 ) |
V_112 ;
F_18 ( V_9 , V_117 + V_116 ,
V_115 [ V_116 ] ) ;
}
}
}
void F_35 ( struct V_8 * V_9 , T_1 V_118 )
{
T_1 V_119 = 0 ;
if ( V_118 != 0 ) {
V_119 |= V_120 ;
if ( V_118 & F_36 ( 1 ) )
V_119 |= V_121 ;
if ( V_118 & F_36 ( 2 ) )
V_119 |= V_122 ;
if ( V_118 & F_36 ( 3 ) )
V_119 |= V_123 ;
}
F_12 ( L_23 , V_119 ) ;
F_18 ( V_9 , V_124 , V_119 ) ;
}
void F_37 ( struct V_8 * V_9 , T_1 V_125 )
{
T_1 V_126 ;
V_126 = F_19 ( V_9 , V_127 ) & 0x0c ;
V_126 |= V_125 ;
F_18 ( V_9 , V_127 , V_126 ) ;
}
void F_38 ( struct V_8 * V_9 , T_1 V_125 )
{
T_1 V_126 ;
V_126 = F_19 ( V_9 , V_127 ) & 0x03 ;
V_126 |= V_125 << 2 ;
F_18 ( V_9 , V_127 , V_126 ) ;
}
void F_39 ( struct V_8 * V_9 , T_1 V_128 )
{
if ( V_128 )
F_40 ( V_9 , V_129 | V_130 , 0 ) ;
else
F_40 ( V_9 , 0 , V_129 | V_130 ) ;
}
void F_41 ( struct V_8 * V_9 , T_1 V_128 )
{
T_4 V_131 ;
V_131 = F_42 ( V_9 , V_132 ) ;
if ( V_128 )
V_131 |= V_133 | V_134 ;
else
V_131 &= ~ ( V_133 | V_134 ) ;
F_43 ( V_9 , V_132 , V_131 ) ;
}
void F_44 ( struct V_8 * V_9 , T_1 V_135 )
{
if ( V_135 ) {
T_4 V_136 ;
V_136 = F_42 ( V_9 , V_132 ) ;
V_136 &= ~ ( V_134 ) ;
F_43 ( V_9 , V_132 , V_136 ) ;
F_45 ( V_9 , V_137 , 0 ) ;
F_40 ( V_9 , V_138 , 0 ) ;
} else {
struct V_139 * V_140 = & V_9 -> V_141 ;
struct V_142 * V_143 ;
T_4 V_136 ;
V_143 = & V_140 -> V_144 ;
if ( ( F_46 ( V_9 ) == true ) ||
( ( V_143 -> V_145 & 0x03 ) == V_146 ) ||
( ( V_143 -> V_145 & 0x03 ) == V_147 ) ) {
F_45 ( V_9 , V_137 , 0xFFFF ) ;
F_40 ( V_9 , 0 , V_138 ) ;
}
V_136 = F_42 ( V_9 , V_132 ) ;
V_136 |= V_134 ;
F_43 ( V_9 , V_132 , V_136 ) ;
}
#ifdef F_32
F_47 ( V_9 , V_135 ? true : false ) ;
#endif
}
void F_48 ( struct V_8 * V_9 )
{
F_43 ( V_9 , V_132 , F_42 ( V_9 , V_132 ) | V_148 ) ;
F_12 ( L_24 , V_149 , __LINE__ ,
F_42 ( V_9 , V_132 ) ) ;
}
void F_49 ( struct V_8 * V_9 )
{
F_43 ( V_9 , V_132 ,
F_42 ( V_9 , V_132 ) & ( ~ V_148 ) ) ;
F_12 ( L_24 , V_149 , __LINE__ ,
F_42 ( V_9 , V_132 ) ) ;
}
void F_50 ( struct V_8 * V_9 , T_1 V_150 )
{
T_1 V_151 , V_152 ;
struct V_139 * V_140 = & V_9 -> V_141 ;
struct V_142 * V_143 = & V_140 -> V_144 ;
F_18 ( V_9 , V_153 , V_150 ) ;
if ( V_143 -> V_154 == 0 ) {
if ( V_140 -> V_155 == V_156 )
V_152 = 10 ;
else
V_152 = 16 ;
V_151 = V_152 + ( 2 * V_143 -> V_157 ) ;
F_18 ( V_9 , V_158 , V_151 ) ;
F_18 ( V_9 , V_159 , V_151 ) ;
F_18 ( V_9 , V_160 , V_151 ) ;
F_18 ( V_9 , V_161 , V_151 ) ;
}
}
void F_51 ( struct V_8 * V_9 , T_1 V_162 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
T_1 V_163 ;
V_163 = ( V_45 -> V_164 ) << 5 ;
if ( V_162 )
V_163 |= 0x80 ;
F_18 ( V_9 , V_66 + 2 , V_163 ) ;
}
void F_52 ( struct V_8 * V_9 , T_1 V_165 )
{
F_18 ( V_9 , V_166 , V_165 ) ;
}
void F_53 ( struct V_8 * V_9 , T_1 V_167 )
{
T_1 V_46 ;
T_4 V_168 = 0 ;
T_4 V_169 = 0 ;
T_4 V_170 = V_171 ;
for ( V_46 = 0 ; V_46 < V_172 ; V_46 ++ ) {
if ( V_46 == 0 ) {
V_169 |= ( V_167 & 0x03 ) |
( ( T_2 ) ( V_170 ) << 2 ) ;
} else {
V_169 = 0 ;
}
V_168 = V_172 * V_167 + V_46 ;
V_168 = V_168 | V_173 | V_174 ;
F_43 ( V_9 , V_175 , V_169 ) ;
F_43 ( V_9 , V_176 , V_168 ) ;
}
}
void F_54 ( struct V_8 * V_9 )
{
F_43 ( V_9 , V_176 , F_36 ( 31 ) | F_36 ( 30 ) ) ;
}
void F_55 ( struct V_8 * V_9 , T_4 V_177 , T_4 V_178 )
{
T_4 V_179 ;
F_43 ( V_9 , V_175 , V_177 ) ;
V_179 = V_173 | V_174 | V_178 ;
F_43 ( V_9 , V_176 , V_179 ) ;
}
void F_56 ( struct V_8 * V_9 )
{
#define F_57 BIT(18)
#define F_58 BIT(17)
struct V_180 * V_181 = & V_9 -> V_182 ;
T_1 V_183 = 100 ;
F_18 ( V_9 , V_184 , 0xff ) ;
V_9 -> V_185 . V_186 = F_59 ( V_9 , V_187 ) ;
if ( V_181 -> V_188 != true ) {
T_4 V_136 ;
V_136 = F_42 ( V_9 , V_189 ) ;
V_136 |= F_57 ;
F_43 ( V_9 , V_189 , V_136 ) ;
do {
V_136 = F_42 ( V_9 , V_189 ) & F_58 ;
if ( ! V_136 )
break;
} while ( V_183 -- );
if ( V_183 == 0 ) {
F_12 ( L_25 ) ;
}
F_45 ( V_9 , V_190 , 0 ) ;
F_43 ( V_9 , V_191 , 0x80000000 ) ;
F_60 ( 10 ) ;
}
}
void F_61 ( struct V_8 * V_9 , T_1 V_128 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
V_45 -> V_192 = V_128 ;
F_12 ( L_26 , V_95 , V_45 -> V_192 ) ;
}
void F_62 ( struct V_8 * V_9 )
{
F_18 ( V_9 , V_193 + 2 ,
F_19 ( V_9 , V_193 + 2 ) | V_194 ) ;
}
void F_63 ( struct V_8 * V_9 , T_1 V_195 )
{
F_18 ( V_9 , V_184 , V_195 ) ;
}
void F_64 ( struct V_8 * V_9 , T_2 V_196 )
{
F_45 ( V_9 , V_197 , V_196 ) ;
}
void F_65 ( struct V_8 * V_9 ,
T_1 V_198 , T_1 V_199 , T_1 V_200 , T_1 V_201 )
{
F_18 ( V_9 , V_202 , V_198 ) ;
F_18 ( V_9 , V_202 + 1 , V_199 ) ;
F_18 ( V_9 , V_203 , V_200 ) ;
F_18 ( V_9 , V_203 + 1 , V_201 ) ;
}
void F_66 ( struct V_8 * V_9 , T_4 V_204 )
{
F_43 ( V_9 , V_158 , V_204 ) ;
}
void F_67 ( struct V_8 * V_9 , T_4 V_205 )
{
F_43 ( V_9 , V_159 , V_205 ) ;
}
void F_68 ( struct V_8 * V_9 , T_4 V_206 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
V_45 -> V_207 = V_206 ;
F_43 ( V_9 , V_160 , V_206 ) ;
}
void F_69 ( struct V_8 * V_9 , T_4 V_208 )
{
F_43 ( V_9 , V_161 , V_208 ) ;
}
void F_70 ( struct V_8 * V_9 , T_1 V_128 )
{
F_18 ( V_9 , V_209 , V_128 ) ;
}
void F_71 ( struct V_8 * V_9 , T_4 V_210 )
{
if ( V_210 > V_211 * 0xFF ) {
F_72 ( V_93 , V_212 ,
( L_27
L_28 ,
V_210 , V_211 ) ) ;
return;
}
V_210 = ( V_210 + V_211 - 1 ) /
V_211 ;
F_18 ( V_9 , V_213 , ( T_1 ) V_210 ) ;
}
void F_73 ( struct V_8 * V_9 , T_4 V_214 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
struct V_215 * V_216 = & V_45 -> V_217 . V_218 ;
if ( V_214 == 0xff )
F_74 ( & V_45 -> V_217 , V_216 -> V_219 ) ;
else {
V_216 -> V_219 = V_216 -> V_220 ;
F_74 ( & V_45 -> V_217 , V_214 ) ;
}
}
void F_75 ( struct V_8 * V_9 , T_4 V_128 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
V_45 -> V_217 . V_221 = V_128 ;
}
void F_76 ( struct V_8 * V_9 , T_1 V_128 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
if ( V_128 )
V_45 -> V_217 . V_222 =
V_45 -> V_217 . V_221 ;
else
V_45 -> V_217 . V_221 =
V_45 -> V_217 . V_222 ;
}
void F_77 ( struct V_8 * V_9 , T_4 V_128 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
if ( V_128 == V_223 ) {
V_45 -> V_224 . V_225 = V_45 -> V_224 . V_226 ;
V_45 -> V_217 . V_221 = V_45 -> V_224 . V_227 ;
} else {
V_45 -> V_217 . V_221 |= V_128 ;
}
}
void F_78 ( struct V_8 * V_9 , T_4 V_128 )
{
struct V_44 * V_45 = F_17 ( V_9 ) ;
V_45 -> V_217 . V_221 &= V_128 ;
}
void F_79 ( struct V_8 * V_9 , T_1 V_128 )
{
F_18 ( V_9 , V_228 , V_128 ) ;
}
