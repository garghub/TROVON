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
static void F_5 ( char * V_22 , struct V_18 * clock )
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
if ( ! F_11 ( V_6 , true ) )
return;
switch ( V_29 ) {
case V_45 :
case V_46 :
case V_47 :
V_44 = F_12 ( V_32 ) ;
if ( ( V_44 & V_48 ) == 0 ) {
F_13 ( V_32 , V_44 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_44 | V_48 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_44 | V_48 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
}
V_44 = F_12 ( V_41 ) ;
if ( ( V_44 & V_49 ) == 0 )
F_13 ( V_41 , V_44 | V_49 ) ;
V_44 = F_12 ( V_35 ) ;
if ( ( V_44 & V_50 ) == 0 ) {
F_13 ( V_35 ,
V_44 | V_50 ) ;
F_13 ( V_38 , F_12 ( V_38 ) ) ;
}
F_15 ( V_3 ) ;
break;
case V_51 :
F_13 ( V_52 , V_53 ) ;
V_44 = F_12 ( V_35 ) ;
if ( ( V_44 & V_50 ) != 0 ) {
F_13 ( V_35 ,
V_44 & ~ V_50 ) ;
F_13 ( V_38 , F_12 ( V_38 ) ) ;
F_12 ( V_38 ) ;
}
V_44 = F_12 ( V_41 ) ;
if ( ( V_44 & V_49 ) != 0 ) {
F_13 ( V_41 , V_44 & ~ V_49 ) ;
F_12 ( V_41 ) ;
}
F_16 ( V_6 ) ;
V_44 = F_12 ( V_32 ) ;
if ( ( V_44 & V_48 ) != 0 ) {
F_13 ( V_32 , V_44 & ~ V_48 ) ;
F_12 ( V_32 ) ;
}
F_14 ( 150 ) ;
break;
}
F_13 ( V_54 , 0x3FFF ) ;
F_13 ( V_55 , 0x3F88080A ) ;
F_13 ( V_56 , 0x0b060808 ) ;
F_13 ( V_57 , 0x0 ) ;
F_13 ( V_58 , 0x08030404 ) ;
F_13 ( V_59 , 0x04040404 ) ;
F_13 ( V_60 , 0x78 ) ;
F_13 ( 0x70400 , F_12 ( 0x70400 ) | 0x4000 ) ;
F_17 ( V_6 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
T_1 V_61 ;
V_61 = F_12 ( V_62 ) ;
if ( ( V_61 & V_63 ) == 0 )
return - 1 ;
return ( V_61 >> 29 ) & 3 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_64 * V_29 ,
struct V_64 * V_65 ,
int V_66 , int V_67 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_31 = V_30 -> V_31 ;
int V_70 = ( V_31 == 0 ) ? V_71 : V_72 ;
int V_32 = ( V_31 == 0 ) ? V_33 : V_34 ;
int V_35 = ( V_31 == 0 ) ? V_36 : V_37 ;
int V_41 = ( V_31 == 0 ) ? V_42 : V_43 ;
int V_73 = ( V_31 == 0 ) ? V_74 : V_75 ;
int V_76 = ( V_31 == 0 ) ? V_77 : V_78 ;
int V_79 = ( V_31 == 0 ) ? V_80 : V_81 ;
int V_82 = ( V_31 == 0 ) ? V_83 : V_84 ;
int V_85 = ( V_31 == 0 ) ? V_86 : V_87 ;
int V_88 = ( V_31 == 0 ) ? V_89 : V_90 ;
int V_91 = ( V_31 == 0 ) ? V_92 : V_93 ;
int V_17 = 0 ;
struct V_18 clock ;
T_1 V_94 = 0 , V_95 = 0 , V_96 , V_97 ;
bool V_98 , V_99 = false ;
bool V_100 = false ;
bool V_101 = false ;
struct V_102 * V_103 = & V_6 -> V_103 ;
struct V_104 * V_104 = NULL ;
T_2 V_105 = V_106 ;
struct V_107 * V_108 ;
if ( ! F_11 ( V_6 , true ) )
return 0 ;
memcpy ( & V_30 -> V_109 ,
V_29 ,
sizeof( struct V_64 ) ) ;
memcpy ( & V_30 -> V_110 ,
V_65 ,
sizeof( struct V_64 ) ) ;
F_20 (connector, &mode_config->connector_list, head) {
if ( ! V_108 -> V_111 || V_108 -> V_111 -> V_3 != V_3 )
continue;
V_104 = F_21 ( V_108 ) ;
switch ( V_104 -> type ) {
case V_10 :
V_100 = true ;
break;
case V_112 :
V_99 = true ;
break;
case V_11 :
V_101 = true ;
break;
}
}
F_13 ( V_52 , V_53 ) ;
if ( F_18 ( V_6 ) == V_31 )
F_13 ( V_62 , 0 ) ;
F_13 ( V_91 ,
( ( V_29 -> V_113 - 1 ) << 16 ) |
( V_29 -> V_114 - 1 ) ) ;
if ( V_104 )
F_22 ( V_108 ,
V_6 -> V_103 . V_115 , & V_105 ) ;
if ( V_105 == V_116 ) {
int V_117 = 0 , V_118 = 0 ;
V_117 = ( V_65 -> V_113 -
V_29 -> V_113 ) / 2 ;
V_118 = ( V_65 -> V_114 -
V_29 -> V_114 ) / 2 ;
F_13 ( V_73 , ( V_29 -> V_113 - 1 ) |
( ( V_65 -> V_119 - 1 ) << 16 ) ) ;
F_13 ( V_82 , ( V_29 -> V_114 - 1 ) |
( ( V_65 -> V_120 - 1 ) << 16 ) ) ;
F_13 ( V_76 ,
( V_65 -> V_121 - V_117 - 1 ) |
( ( V_65 -> V_122 - V_117 - 1 ) << 16 ) ) ;
F_13 ( V_79 ,
( V_65 -> V_123 - V_117 - 1 ) |
( ( V_65 -> V_124 - V_117 - 1 ) << 16 ) ) ;
F_13 ( V_85 ,
( V_65 -> V_125 - V_118 - 1 ) |
( ( V_65 -> V_126 - V_118 - 1 ) << 16 ) ) ;
F_13 ( V_88 ,
( V_65 -> V_127 - V_118 - 1 ) |
( ( V_65 -> V_128 - V_118 - 1 ) << 16 ) ) ;
} else {
F_13 ( V_73 , ( V_65 -> V_113 - 1 ) |
( ( V_65 -> V_119 - 1 ) << 16 ) ) ;
F_13 ( V_82 , ( V_65 -> V_114 - 1 ) |
( ( V_65 -> V_120 - 1 ) << 16 ) ) ;
F_13 ( V_76 , ( V_65 -> V_121 - 1 ) |
( ( V_65 -> V_122 - 1 ) << 16 ) ) ;
F_13 ( V_79 , ( V_65 -> V_123 - 1 ) |
( ( V_65 -> V_124 - 1 ) << 16 ) ) ;
F_13 ( V_85 , ( V_65 -> V_125 - 1 ) |
( ( V_65 -> V_126 - 1 ) << 16 ) ) ;
F_13 ( V_88 , ( V_65 -> V_127 - 1 ) |
( ( V_65 -> V_128 - 1 ) << 16 ) ) ;
}
{
struct V_129 * V_130 =
V_3 -> V_131 ;
V_130 -> V_132 ( V_3 , V_66 , V_67 , V_69 ) ;
}
V_97 = F_12 ( V_41 ) ;
V_96 = F_12 ( V_35 ) ;
V_96 |= V_133 ;
if ( V_31 == 0 )
V_96 |= V_134 ;
else
V_96 |= V_135 ;
if ( V_101 )
goto V_136;
V_17 = V_8 -> V_12 * 1000 ;
V_94 = 0 ;
V_98 = F_7 ( V_3 , V_65 -> clock , V_17 , & clock ) ;
if ( ! V_98 ) {
F_8 ( V_6 -> V_6 , L_4 ) ;
} else {
F_8 ( V_6 -> V_6 , L_5
L_6 , clock . V_19 , clock . V_20 ,
clock . V_21 ) ;
}
V_95 = V_137 [ ( clock . V_20 - V_138 ) ] << 8 ;
V_94 |= V_139 ;
V_94 |= V_48 ;
if ( V_100 )
V_94 |= V_140 ;
else
V_94 |= V_141 ;
if ( V_99 ) {
int V_142 =
V_65 -> clock / V_29 -> clock ;
V_94 |= V_143 ;
V_94 |=
( V_142 -
1 ) << V_144 ;
}
V_94 |= ( 1 << ( clock . V_21 - 2 ) ) << 17 ;
V_94 |= V_48 ;
F_5 ( L_7 , & clock ) ;
if ( V_94 & V_48 ) {
F_13 ( V_70 , V_95 ) ;
F_13 ( V_32 , V_94 & ~ V_48 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
}
F_13 ( V_70 , V_95 ) ;
F_13 ( V_32 , V_94 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_32 , V_94 ) ;
F_12 ( V_32 ) ;
F_14 ( 150 ) ;
F_13 ( V_41 , V_97 ) ;
F_12 ( V_41 ) ;
F_16 ( V_6 ) ;
F_13 ( V_35 , V_96 ) ;
F_16 ( V_6 ) ;
V_136:
F_17 ( V_6 ) ;
return 0 ;
}
static bool F_23 ( struct V_2 * V_3 ,
struct V_64 * V_29 ,
struct V_64 * V_65 )
{
return true ;
}
static int F_24 ( struct V_2 * V_3 ,
int V_66 , int V_67 , struct V_68 * V_69 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_30 * V_30 = F_10 ( V_3 ) ;
struct V_145 * V_146 = F_25 ( V_3 -> V_147 ) ;
int V_31 = V_30 -> V_31 ;
unsigned long V_148 , V_149 ;
int V_150 = ( V_31 == 0 ? V_151 : V_40 ) ;
int V_152 = ( V_31 == 0 ? V_153 : V_154 ) ;
int V_155 = ( V_31 == 0 ) ? V_156 : V_157 ;
int V_35 = ( V_31 == 0 ) ? V_36 : V_37 ;
T_1 V_96 ;
int V_158 = 0 ;
if ( ! V_3 -> V_147 ) {
F_8 ( V_6 -> V_6 , L_8 ) ;
return 0 ;
}
if ( ! F_11 ( V_6 , true ) )
return 0 ;
V_148 = V_146 -> V_159 -> V_149 ;
V_149 = V_67 * V_3 -> V_147 -> V_160 [ 0 ] + V_66 * ( V_3 -> V_147 -> V_161 / 8 ) ;
F_13 ( V_155 , V_3 -> V_147 -> V_160 [ 0 ] ) ;
V_96 = F_12 ( V_35 ) ;
V_96 &= ~ V_162 ;
switch ( V_3 -> V_147 -> V_161 ) {
case 8 :
V_96 |= V_163 ;
break;
case 16 :
if ( V_3 -> V_147 -> V_164 == 15 )
V_96 |= V_165 ;
else
V_96 |= V_166 ;
break;
case 24 :
case 32 :
V_96 |= V_167 ;
break;
default:
F_3 ( V_6 -> V_6 , L_9 ) ;
V_158 = - V_168 ;
goto V_169;
}
F_13 ( V_35 , V_96 ) ;
F_13 ( V_150 , V_149 ) ;
F_12 ( V_150 ) ;
F_13 ( V_152 , V_148 ) ;
F_12 ( V_152 ) ;
V_169:
F_17 ( V_6 ) ;
return V_158 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_129 * V_130 = V_3 -> V_131 ;
V_130 -> V_170 ( V_3 , V_51 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_129 * V_130 = V_3 -> V_131 ;
V_130 -> V_170 ( V_3 , V_45 ) ;
}
