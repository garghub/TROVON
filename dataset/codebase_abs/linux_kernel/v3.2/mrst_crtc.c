static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( F_2 ( V_3 , V_10 )
|| F_2 ( V_3 , V_11 ) ) {
switch ( V_8 -> V_12 ) {
case 100 :
V_4 = & V_13 [ V_14 ] ;
break;
case 166 :
V_4 = & V_13 [ V_15 ] ;
break;
case 200 :
V_4 = & V_13 [ V_16 ] ;
break;
}
} else {
V_4 = NULL ;
F_3 ( V_6 -> V_6 , L_1 ) ;
}
return V_4 ;
}
static void F_4 ( int V_17 , struct V_18 * clock )
{
clock -> V_19 = ( V_17 * clock -> V_20 ) / ( 14 * clock -> V_21 ) ;
}
void F_5 ( char * V_22 , struct V_18 * clock )
{
F_6 ( L_2 ,
V_22 , clock -> V_19 , clock -> V_20 , clock -> V_21 ) ;
}
static bool
F_7 ( struct V_2 * V_3 , int V_23 , int V_17 ,
struct V_18 * V_24 )
{
struct V_18 clock ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_25 = V_23 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
for ( clock . V_20 = V_4 -> V_20 . V_26 ; clock . V_20 <= V_4 -> V_20 . V_27 ; clock . V_20 ++ ) {
for ( clock . V_21 = V_4 -> V_21 . V_26 ; clock . V_21 <= V_4 -> V_21 . V_27 ;
clock . V_21 ++ ) {
int V_28 ;
F_4 ( V_17 , & clock ) ;
V_28 = abs ( clock . V_19 - V_23 ) ;
if ( V_28 < V_25 ) {
* V_24 = clock ;
V_25 = V_28 ;
}
}
}
F_8 ( V_3 -> V_6 -> V_6 , L_3 , V_25 ) ;
return V_25 != V_23 ;
}
static void F_9 ( struct V_2 * V_3 , int V_29 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
int V_31 = V_30 -> V_31 ;
int V_32 = ( V_31 == 0 ) ? V_33 : V_34 ;
int V_35 = ( V_31 == 0 ) ? V_36 : V_37 ;
int V_38 = ( V_31 == 0 ) ? V_39 : V_40 ;
int V_41 = ( V_31 == 0 ) ? V_42 : V_43 ;
T_1 V_44 ;
bool V_45 ;
if ( ! F_11 ( V_6 , true ) )
return;
switch ( V_29 ) {
case V_46 :
case V_47 :
case V_48 :
V_44 = F_12 ( V_32 ) ;
if ( ( V_44 & V_49 ) == 0 ) {
F_13 ( V_32 , V_44 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_44 | V_49 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_44 | V_49 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
}
V_44 = F_12 ( V_41 ) ;
if ( ( V_44 & V_50 ) == 0 )
F_13 ( V_41 , V_44 | V_50 ) ;
V_44 = F_12 ( V_35 ) ;
if ( ( V_44 & V_51 ) == 0 ) {
F_13 ( V_35 ,
V_44 | V_51 ) ;
F_13 ( V_38 , F_12 ( V_38 ) ) ;
}
F_15 ( V_3 ) ;
break;
case V_52 :
F_13 ( V_53 , V_54 ) ;
V_44 = F_12 ( V_35 ) ;
if ( ( V_44 & V_51 ) != 0 ) {
F_13 ( V_35 ,
V_44 & ~ V_51 ) ;
F_13 ( V_38 , F_12 ( V_38 ) ) ;
F_12 ( V_38 ) ;
}
V_44 = F_12 ( V_41 ) ;
if ( ( V_44 & V_50 ) != 0 ) {
F_13 ( V_41 , V_44 & ~ V_50 ) ;
F_12 ( V_41 ) ;
}
F_16 ( V_6 ) ;
V_44 = F_12 ( V_32 ) ;
if ( ( V_44 & V_49 ) != 0 ) {
F_13 ( V_32 , V_44 & ~ V_49 ) ;
F_12 ( V_32 ) ;
}
F_14 ( 150 ) ;
break;
}
V_45 = V_3 -> V_45 && V_29 != V_52 ;
F_13 ( V_55 , 0x3FFF ) ;
F_13 ( V_56 , 0x3F88080A ) ;
F_13 ( V_57 , 0x0b060808 ) ;
F_13 ( V_58 , 0x0 ) ;
F_13 ( V_59 , 0x08030404 ) ;
F_13 ( V_60 , 0x04040404 ) ;
F_13 ( V_61 , 0x78 ) ;
F_13 ( 0x70400 , F_12 ( 0x70400 ) | 0x4000 ) ;
F_17 ( V_6 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
T_1 V_62 ;
V_62 = F_12 ( V_63 ) ;
if ( ( V_62 & V_64 ) == 0 )
return - 1 ;
return ( V_62 >> 29 ) & 3 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_65 * V_29 ,
struct V_65 * V_66 ,
int V_67 , int V_68 ,
struct V_69 * V_70 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_31 = V_30 -> V_31 ;
int V_71 = ( V_31 == 0 ) ? V_72 : V_73 ;
int V_32 = ( V_31 == 0 ) ? V_33 : V_34 ;
int V_35 = ( V_31 == 0 ) ? V_36 : V_37 ;
int V_41 = ( V_31 == 0 ) ? V_42 : V_43 ;
int V_74 = ( V_31 == 0 ) ? V_75 : V_76 ;
int V_77 = ( V_31 == 0 ) ? V_78 : V_79 ;
int V_80 = ( V_31 == 0 ) ? V_81 : V_82 ;
int V_83 = ( V_31 == 0 ) ? V_84 : V_85 ;
int V_86 = ( V_31 == 0 ) ? V_87 : V_88 ;
int V_89 = ( V_31 == 0 ) ? V_90 : V_91 ;
int V_92 = ( V_31 == 0 ) ? V_93 : V_94 ;
int V_17 = 0 ;
struct V_18 clock ;
T_1 V_95 = 0 , V_96 = 0 , V_97 , V_98 ;
bool V_99 , V_100 = false ;
bool V_101 = false , V_102 = false , V_103 = false ;
bool V_104 = false ;
struct V_105 * V_106 = & V_6 -> V_106 ;
struct V_107 * V_107 = NULL ;
T_2 V_108 = V_109 ;
struct V_110 * V_111 ;
if ( ! F_11 ( V_6 , true ) )
return 0 ;
memcpy ( & V_30 -> V_112 ,
V_29 ,
sizeof( struct V_65 ) ) ;
memcpy ( & V_30 -> V_113 ,
V_66 ,
sizeof( struct V_65 ) ) ;
F_20 (encoder, &mode_config->encoder_list, head) {
if ( V_111 -> V_3 != V_3 )
continue;
V_107 = F_21 ( V_111 ) ;
switch ( V_107 -> type ) {
case V_10 :
V_102 = true ;
break;
case V_114 :
V_100 = true ;
break;
case V_115 :
V_103 = true ;
break;
case V_116 :
V_101 = true ;
break;
case V_11 :
V_104 = true ;
break;
}
}
F_13 ( V_53 , V_54 ) ;
if ( F_18 ( V_6 ) == V_31 )
F_13 ( V_63 , 0 ) ;
F_13 ( V_92 ,
( ( V_29 -> V_117 - 1 ) << 16 ) |
( V_29 -> V_118 - 1 ) ) ;
if ( V_107 )
F_22 ( & V_107 -> V_119 ,
V_6 -> V_106 . V_120 , & V_108 ) ;
if ( V_108 == V_121 ) {
int V_122 = 0 , V_123 = 0 ;
V_122 = ( V_66 -> V_117 -
V_29 -> V_117 ) / 2 ;
V_123 = ( V_66 -> V_118 -
V_29 -> V_118 ) / 2 ;
F_13 ( V_74 , ( V_29 -> V_117 - 1 ) |
( ( V_66 -> V_124 - 1 ) << 16 ) ) ;
F_13 ( V_83 , ( V_29 -> V_118 - 1 ) |
( ( V_66 -> V_125 - 1 ) << 16 ) ) ;
F_13 ( V_77 ,
( V_66 -> V_126 - V_122 - 1 ) |
( ( V_66 -> V_127 - V_122 - 1 ) << 16 ) ) ;
F_13 ( V_80 ,
( V_66 -> V_128 - V_122 - 1 ) |
( ( V_66 -> V_129 - V_122 - 1 ) << 16 ) ) ;
F_13 ( V_86 ,
( V_66 -> V_130 - V_123 - 1 ) |
( ( V_66 -> V_131 - V_123 - 1 ) << 16 ) ) ;
F_13 ( V_89 ,
( V_66 -> V_132 - V_123 - 1 ) |
( ( V_66 -> V_133 - V_123 - 1 ) << 16 ) ) ;
} else {
F_13 ( V_74 , ( V_66 -> V_117 - 1 ) |
( ( V_66 -> V_124 - 1 ) << 16 ) ) ;
F_13 ( V_83 , ( V_66 -> V_118 - 1 ) |
( ( V_66 -> V_125 - 1 ) << 16 ) ) ;
F_13 ( V_77 , ( V_66 -> V_126 - 1 ) |
( ( V_66 -> V_127 - 1 ) << 16 ) ) ;
F_13 ( V_80 , ( V_66 -> V_128 - 1 ) |
( ( V_66 -> V_129 - 1 ) << 16 ) ) ;
F_13 ( V_86 , ( V_66 -> V_130 - 1 ) |
( ( V_66 -> V_131 - 1 ) << 16 ) ) ;
F_13 ( V_89 , ( V_66 -> V_132 - 1 ) |
( ( V_66 -> V_133 - 1 ) << 16 ) ) ;
}
{
struct V_134 * V_135 =
V_3 -> V_136 ;
V_135 -> V_137 ( V_3 , V_67 , V_68 , V_70 ) ;
}
V_98 = F_12 ( V_41 ) ;
V_97 = F_12 ( V_35 ) ;
V_97 |= V_138 ;
if ( V_31 == 0 )
V_97 |= V_139 ;
else
V_97 |= V_140 ;
V_8 -> V_97 = V_97 |= V_51 ;
V_8 -> V_98 = V_98 |= V_50 ;
if ( V_104 )
goto V_141;
V_17 = V_8 -> V_12 * 1000 ;
V_95 = 0 ;
V_99 = F_7 ( V_3 , V_66 -> clock , V_17 , & clock ) ;
if ( ! V_99 ) {
F_8 ( V_6 -> V_6 , L_4 ) ;
} else {
F_8 ( V_6 -> V_6 , L_5
L_6 , clock . V_19 , clock . V_20 ,
clock . V_21 ) ;
}
V_96 = V_142 [ ( clock . V_20 - V_143 ) ] << 8 ;
V_95 |= V_144 ;
V_95 |= V_49 ;
if ( V_102 )
V_95 |= V_145 ;
else
V_95 |= V_146 ;
if ( V_100 ) {
int V_147 =
V_66 -> clock / V_29 -> clock ;
V_95 |= V_148 ;
V_95 |=
( V_147 -
1 ) << V_149 ;
}
V_95 |= ( 1 << ( clock . V_21 - 2 ) ) << 17 ;
V_95 |= V_49 ;
F_5 ( L_7 , & clock ) ;
if ( V_95 & V_49 ) {
F_13 ( V_71 , V_96 ) ;
F_13 ( V_32 , V_95 & ~ V_49 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
}
F_13 ( V_71 , V_96 ) ;
F_13 ( V_32 , V_95 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_95 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_41 , V_98 ) ;
F_12 ( V_41 ) ;
F_16 ( V_6 ) ;
F_13 ( V_35 , V_97 ) ;
F_16 ( V_6 ) ;
V_141:
F_17 ( V_6 ) ;
return 0 ;
}
static bool F_23 ( struct V_2 * V_3 ,
struct V_65 * V_29 ,
struct V_65 * V_66 )
{
return true ;
}
int F_24 ( struct V_2 * V_3 ,
int V_67 , int V_68 , struct V_69 * V_70 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_150 * V_151 = F_25 ( V_3 -> V_152 ) ;
int V_31 = V_30 -> V_31 ;
unsigned long V_153 , V_154 ;
int V_155 = ( V_31 == 0 ? V_156 : V_40 ) ;
int V_157 = ( V_31 == 0 ? V_158 : V_159 ) ;
int V_160 = ( V_31 == 0 ) ? V_161 : V_162 ;
int V_35 = ( V_31 == 0 ) ? V_36 : V_37 ;
T_1 V_97 ;
int V_163 = 0 ;
if ( ! V_3 -> V_152 ) {
F_8 ( V_6 -> V_6 , L_8 ) ;
return 0 ;
}
if ( ! F_11 ( V_6 , true ) )
return 0 ;
V_153 = V_151 -> V_164 -> V_154 ;
V_154 = V_68 * V_3 -> V_152 -> V_165 + V_67 * ( V_3 -> V_152 -> V_166 / 8 ) ;
F_13 ( V_160 , V_3 -> V_152 -> V_165 ) ;
V_97 = F_12 ( V_35 ) ;
V_97 &= ~ V_167 ;
switch ( V_3 -> V_152 -> V_166 ) {
case 8 :
V_97 |= V_168 ;
break;
case 16 :
if ( V_3 -> V_152 -> V_169 == 15 )
V_97 |= V_170 ;
else
V_97 |= V_171 ;
break;
case 24 :
case 32 :
V_97 |= V_172 ;
break;
default:
F_3 ( V_6 -> V_6 , L_9 ) ;
V_163 = - V_173 ;
goto V_174;
}
F_13 ( V_35 , V_97 ) ;
F_13 ( V_155 , V_154 ) ;
F_12 ( V_155 ) ;
F_13 ( V_157 , V_153 ) ;
F_12 ( V_157 ) ;
V_174:
F_17 ( V_6 ) ;
return V_163 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_134 * V_135 = V_3 -> V_136 ;
V_135 -> V_175 ( V_3 , V_52 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_134 * V_135 = V_3 -> V_136 ;
V_135 -> V_175 ( V_3 , V_46 ) ;
}
