static const struct V_1 * F_1 ( struct V_2 * V_3 )
{
const struct V_1 * V_4 = NULL ;
struct V_5 * V_6 = V_3 -> V_6 ;
T_1 * V_7 = V_6 -> V_8 ;
if ( F_2 ( V_3 , V_9 )
|| F_2 ( V_3 , V_10 ) ) {
switch ( V_7 -> V_11 ) {
case 100 :
V_4 = & V_12 [ V_13 ] ;
break;
case 166 :
V_4 = & V_12 [ V_14 ] ;
break;
case 200 :
V_4 = & V_12 [ V_15 ] ;
break;
}
} else {
V_4 = NULL ;
F_3 ( L_1 ) ;
}
return V_4 ;
}
static void F_4 ( int V_16 , struct V_17 * clock )
{
clock -> V_18 = ( V_16 * clock -> V_19 ) / ( 14 * clock -> V_20 ) ;
}
void F_5 ( char * V_21 , struct V_17 * clock )
{
F_3 ( L_2 ,
V_21 , clock -> V_18 , clock -> V_19 , clock -> V_20 ) ;
}
static bool
F_6 ( struct V_2 * V_3 , int V_22 , int V_16 ,
struct V_17 * V_23 )
{
struct V_17 clock ;
const struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_24 = V_22 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
for ( clock . V_19 = V_4 -> V_19 . V_25 ; clock . V_19 <= V_4 -> V_19 . V_26 ; clock . V_19 ++ ) {
for ( clock . V_20 = V_4 -> V_20 . V_25 ; clock . V_20 <= V_4 -> V_20 . V_26 ;
clock . V_20 ++ ) {
int V_27 ;
F_4 ( V_16 , & clock ) ;
V_27 = abs ( clock . V_18 - V_22 ) ;
if ( V_27 < V_24 ) {
* V_23 = clock ;
V_24 = V_27 ;
}
}
}
F_7 ( L_3 , V_24 ) ;
return V_24 != V_22 ;
}
static void F_8 ( struct V_2 * V_3 , int V_28 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_29 * V_29 = F_9 ( V_3 ) ;
int V_30 = V_29 -> V_30 ;
int V_31 = ( V_30 == 0 ) ? V_32 : V_33 ;
int V_34 = ( V_30 == 0 ) ? V_35 : V_36 ;
int V_37 = ( V_30 == 0 ) ? V_38 : V_39 ;
int V_40 = ( V_30 == 0 ) ? V_41 : V_42 ;
T_2 V_43 ;
bool V_44 ;
F_3 ( L_4 , V_28 , V_30 ) ;
if ( ! F_10 ( V_6 , true ) )
return;
switch ( V_28 ) {
case V_45 :
case V_46 :
case V_47 :
V_43 = F_11 ( V_31 ) ;
if ( ( V_43 & V_48 ) == 0 ) {
F_12 ( V_31 , V_43 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
F_12 ( V_31 , V_43 | V_48 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
F_12 ( V_31 , V_43 | V_48 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
}
V_43 = F_11 ( V_40 ) ;
if ( ( V_43 & V_49 ) == 0 )
F_12 ( V_40 , V_43 | V_49 ) ;
V_43 = F_11 ( V_34 ) ;
if ( ( V_43 & V_50 ) == 0 ) {
F_12 ( V_34 ,
V_43 | V_50 ) ;
F_12 ( V_37 , F_11 ( V_37 ) ) ;
}
F_14 ( V_3 ) ;
break;
case V_51 :
F_12 ( V_52 , V_53 ) ;
V_43 = F_11 ( V_34 ) ;
if ( ( V_43 & V_50 ) != 0 ) {
F_12 ( V_34 ,
V_43 & ~ V_50 ) ;
F_12 ( V_37 , F_11 ( V_37 ) ) ;
F_11 ( V_37 ) ;
}
V_43 = F_11 ( V_40 ) ;
if ( ( V_43 & V_49 ) != 0 ) {
F_12 ( V_40 , V_43 & ~ V_49 ) ;
F_11 ( V_40 ) ;
}
F_15 ( V_6 ) ;
V_43 = F_11 ( V_31 ) ;
if ( ( V_43 & V_48 ) != 0 ) {
F_12 ( V_31 , V_43 & ~ V_48 ) ;
F_11 ( V_31 ) ;
}
F_13 ( 150 ) ;
break;
}
V_44 = V_3 -> V_44 && V_28 != V_51 ;
F_12 ( V_54 , 0x3FFF ) ;
F_12 ( V_55 , 0x3F88080A ) ;
F_12 ( V_56 , 0x0b060808 ) ;
F_12 ( V_57 , 0x0 ) ;
F_12 ( V_58 , 0x08030404 ) ;
F_12 ( V_59 , 0x04040404 ) ;
F_12 ( V_60 , 0x78 ) ;
F_12 ( 0x70400 , F_11 ( 0x70400 ) | 0x4000 ) ;
F_16 ( V_6 ) ;
}
static int F_17 ( struct V_5 * V_6 )
{
T_2 V_61 ;
V_61 = F_11 ( V_62 ) ;
if ( ( V_61 & V_63 ) == 0 )
return - 1 ;
return ( V_61 >> 29 ) & 3 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_64 * V_28 ,
struct V_64 * V_65 ,
int V_66 , int V_67 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_29 * V_29 = F_9 ( V_3 ) ;
T_1 * V_7 = V_6 -> V_8 ;
int V_30 = V_29 -> V_30 ;
int V_70 = ( V_30 == 0 ) ? V_71 : V_72 ;
int V_31 = ( V_30 == 0 ) ? V_32 : V_33 ;
int V_34 = ( V_30 == 0 ) ? V_35 : V_36 ;
int V_40 = ( V_30 == 0 ) ? V_41 : V_42 ;
int V_73 = ( V_30 == 0 ) ? V_74 : V_75 ;
int V_76 = ( V_30 == 0 ) ? V_77 : V_78 ;
int V_79 = ( V_30 == 0 ) ? V_80 : V_81 ;
int V_82 = ( V_30 == 0 ) ? V_83 : V_84 ;
int V_85 = ( V_30 == 0 ) ? V_86 : V_87 ;
int V_88 = ( V_30 == 0 ) ? V_89 : V_90 ;
int V_91 = ( V_30 == 0 ) ? V_92 : V_93 ;
int V_16 = 0 ;
struct V_17 clock ;
T_2 V_94 = 0 , V_95 = 0 , V_96 , V_97 ;
bool V_98 , V_99 = false ;
bool V_100 = false , V_101 = false , V_102 = false ;
bool V_103 = false ;
struct V_104 * V_105 = & V_6 -> V_105 ;
struct V_106 * V_106 = NULL ;
T_3 V_107 = V_108 ;
struct V_109 * V_110 ;
F_3 ( L_5 , V_30 ) ;
if ( ! F_10 ( V_6 , true ) )
return 0 ;
memcpy ( & V_29 -> V_111 ,
V_28 ,
sizeof( struct V_64 ) ) ;
memcpy ( & V_29 -> V_112 ,
V_65 ,
sizeof( struct V_64 ) ) ;
F_19 (encoder, &mode_config->encoder_list, head) {
if ( V_110 -> V_3 != V_3 )
continue;
V_106 = F_20 ( V_110 ) ;
switch ( V_106 -> type ) {
case V_9 :
V_101 = true ;
break;
case V_113 :
V_99 = true ;
break;
case V_114 :
V_102 = true ;
break;
case V_115 :
V_100 = true ;
break;
case V_10 :
V_103 = true ;
break;
}
}
F_12 ( V_52 , V_53 ) ;
if ( F_17 ( V_6 ) == V_30 )
F_12 ( V_62 , 0 ) ;
F_12 ( V_91 ,
( ( V_28 -> V_116 - 1 ) << 16 ) |
( V_28 -> V_117 - 1 ) ) ;
if ( V_106 )
F_21 ( & V_106 -> V_118 ,
V_6 -> V_105 . V_119 , & V_107 ) ;
if ( V_107 == V_120 ) {
int V_121 = 0 , V_122 = 0 ;
V_121 = ( V_65 -> V_116 -
V_28 -> V_116 ) / 2 ;
V_122 = ( V_65 -> V_117 -
V_28 -> V_117 ) / 2 ;
F_12 ( V_73 , ( V_28 -> V_116 - 1 ) |
( ( V_65 -> V_123 - 1 ) << 16 ) ) ;
F_12 ( V_82 , ( V_28 -> V_117 - 1 ) |
( ( V_65 -> V_124 - 1 ) << 16 ) ) ;
F_12 ( V_76 ,
( V_65 -> V_125 - V_121 - 1 ) |
( ( V_65 -> V_126 - V_121 - 1 ) << 16 ) ) ;
F_12 ( V_79 ,
( V_65 -> V_127 - V_121 - 1 ) |
( ( V_65 -> V_128 - V_121 - 1 ) << 16 ) ) ;
F_12 ( V_85 ,
( V_65 -> V_129 - V_122 - 1 ) |
( ( V_65 -> V_130 - V_122 - 1 ) << 16 ) ) ;
F_12 ( V_88 ,
( V_65 -> V_131 - V_122 - 1 ) |
( ( V_65 -> V_132 - V_122 - 1 ) << 16 ) ) ;
} else {
F_12 ( V_73 , ( V_65 -> V_116 - 1 ) |
( ( V_65 -> V_123 - 1 ) << 16 ) ) ;
F_12 ( V_82 , ( V_65 -> V_117 - 1 ) |
( ( V_65 -> V_124 - 1 ) << 16 ) ) ;
F_12 ( V_76 , ( V_65 -> V_125 - 1 ) |
( ( V_65 -> V_126 - 1 ) << 16 ) ) ;
F_12 ( V_79 , ( V_65 -> V_127 - 1 ) |
( ( V_65 -> V_128 - 1 ) << 16 ) ) ;
F_12 ( V_85 , ( V_65 -> V_129 - 1 ) |
( ( V_65 -> V_130 - 1 ) << 16 ) ) ;
F_12 ( V_88 , ( V_65 -> V_131 - 1 ) |
( ( V_65 -> V_132 - 1 ) << 16 ) ) ;
}
{
struct V_133 * V_134 =
V_3 -> V_135 ;
V_134 -> V_136 ( V_3 , V_66 , V_67 , V_69 ) ;
}
V_97 = F_11 ( V_40 ) ;
V_96 = F_11 ( V_34 ) ;
V_96 |= V_137 ;
if ( V_30 == 0 )
V_96 |= V_138 ;
else
V_96 |= V_139 ;
V_7 -> V_96 = V_96 |= V_50 ;
V_7 -> V_97 = V_97 |= V_49 ;
if ( V_103 )
goto V_140;
V_16 = V_7 -> V_11 * 1000 ;
V_94 = 0 ;
V_98 = F_6 ( V_3 , V_65 -> clock , V_16 , & clock ) ;
if ( ! V_98 ) {
F_3 (
L_6 ) ;
} else {
F_3 ( L_7
L_8 , clock . V_18 , clock . V_19 ,
clock . V_20 ) ;
}
V_95 = V_141 [ ( clock . V_19 - V_142 ) ] << 8 ;
V_94 |= V_143 ;
V_94 |= V_48 ;
if ( V_101 )
V_94 |= V_144 ;
else
V_94 |= V_145 ;
if ( V_99 ) {
int V_146 =
V_65 -> clock / V_28 -> clock ;
V_94 |= V_147 ;
V_94 |=
( V_146 -
1 ) << V_148 ;
}
V_94 |= ( 1 << ( clock . V_20 - 2 ) ) << 17 ;
V_94 |= V_48 ;
F_5 ( L_9 , & clock ) ;
if ( V_94 & V_48 ) {
F_12 ( V_70 , V_95 ) ;
F_12 ( V_31 , V_94 & ~ V_48 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
}
F_12 ( V_70 , V_95 ) ;
F_12 ( V_31 , V_94 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
F_12 ( V_31 , V_94 ) ;
F_11 ( V_31 ) ;
F_13 ( 150 ) ;
F_12 ( V_40 , V_97 ) ;
F_11 ( V_40 ) ;
F_15 ( V_6 ) ;
F_12 ( V_34 , V_96 ) ;
F_15 ( V_6 ) ;
V_140:
F_16 ( V_6 ) ;
return 0 ;
}
static bool F_22 ( struct V_2 * V_3 ,
struct V_64 * V_28 ,
struct V_64 * V_65 )
{
return true ;
}
int F_23 ( struct V_2 * V_3 ,
int V_66 , int V_67 , struct V_68 * V_69 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_29 * V_29 = F_9 ( V_3 ) ;
struct V_149 * V_150 = F_24 ( V_3 -> V_151 ) ;
int V_30 = V_29 -> V_30 ;
unsigned long V_152 , V_153 ;
int V_154 = ( V_30 == 0 ? V_155 : V_39 ) ;
int V_156 = ( V_30 == 0 ? V_157 : V_158 ) ;
int V_159 = ( V_30 == 0 ) ? V_160 : V_161 ;
int V_34 = ( V_30 == 0 ) ? V_35 : V_36 ;
T_2 V_96 ;
int V_162 = 0 ;
F_3 ( L_10 ) ;
if ( ! V_3 -> V_151 ) {
F_7 ( L_11 ) ;
return 0 ;
}
if ( ! F_10 ( V_6 , true ) )
return 0 ;
V_152 = V_150 -> V_163 -> V_153 ;
V_153 = V_67 * V_3 -> V_151 -> V_164 + V_66 * ( V_3 -> V_151 -> V_165 / 8 ) ;
F_12 ( V_159 , V_3 -> V_151 -> V_164 ) ;
V_96 = F_11 ( V_34 ) ;
V_96 &= ~ V_166 ;
switch ( V_3 -> V_151 -> V_165 ) {
case 8 :
V_96 |= V_167 ;
break;
case 16 :
if ( V_3 -> V_151 -> V_168 == 15 )
V_96 |= V_169 ;
else
V_96 |= V_170 ;
break;
case 24 :
case 32 :
V_96 |= V_171 ;
break;
default:
F_25 ( L_12 ) ;
V_162 = - V_172 ;
goto V_173;
}
F_12 ( V_34 , V_96 ) ;
F_7 ( L_13 , V_152 , V_153 , V_66 , V_67 ) ;
if ( 0 ) {
F_12 ( V_154 , V_153 ) ;
F_11 ( V_154 ) ;
F_12 ( V_156 , V_152 ) ;
F_11 ( V_156 ) ;
} else {
F_12 ( V_154 , V_152 + V_153 ) ;
F_11 ( V_154 ) ;
}
V_173:
F_16 ( V_6 ) ;
return V_162 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_133 * V_134 = V_3 -> V_135 ;
V_134 -> V_174 ( V_3 , V_51 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_133 * V_134 = V_3 -> V_135 ;
V_134 -> V_174 ( V_3 , V_45 ) ;
}
