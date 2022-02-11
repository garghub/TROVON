int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_1 ) ;
return V_5 ;
}
F_5 ( V_8 , V_3 ) ;
F_5 ( V_6 ,
F_6 ( V_9 , V_10 ) |
F_6 ( V_11 , V_12 ) |
F_6 ( 0xf , V_13 ) ) ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_2 ) ;
return V_5 ;
}
* V_4 = F_3 ( V_14 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
static bool V_15 = true ;
T_1 V_16 ;
if ( V_15 ) {
if ( F_1 ( V_2 , V_3 , & V_16 ) == 0 )
F_8 ( L_3 , V_3 , V_16 ) ;
F_8 ( L_4 , V_3 , V_4 ) ;
}
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_5 ) ;
return V_5 ;
}
F_5 ( V_8 , V_3 ) ;
F_5 ( V_14 , V_4 ) ;
F_5 ( V_6 ,
F_6 ( V_17 , V_10 ) |
F_6 ( V_11 , V_12 ) |
F_6 ( 0xf , V_13 ) ) ;
V_5 = F_2 ( ( F_3 ( V_6 ) & V_7 ) == 0 , 1000 ) ;
if ( V_5 ) {
F_4 ( L_6 ) ;
return V_5 ;
}
if ( V_15 ) {
if ( F_1 ( V_2 , V_3 , & V_16 ) == 0 )
F_8 ( L_7 , V_3 , V_16 ) ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_5 ( V_18 , 0 ) ;
F_3 ( V_18 ) ;
F_5 ( V_18 , V_19 | V_20 ) ;
}
static int
F_10 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_23 * clock , bool V_24 , T_1 V_25 )
{
struct V_26 * V_27 = F_11 ( V_22 ) ;
int V_28 = V_27 -> V_28 ;
T_1 V_29 , V_30 , V_31 ;
int V_5 = 0 ;
int V_32 = ( V_28 == 0 ) ? V_33 : V_34 ;
int V_35 = ( V_28 == 0 ) ? V_36 : V_37 ;
T_1 V_38 ;
T_1 V_39 , V_40 ;
F_9 ( V_2 ) ;
F_5 ( V_32 , V_41 | V_42 ) ;
F_12 ( 100 ) ;
V_38 = 0x68A701 ;
F_7 ( V_2 , F_13 ( V_28 ) , V_38 ) ;
V_5 = F_1 ( V_2 , V_35 , & V_38 ) ;
if ( V_5 )
return V_5 ;
V_38 &= ~ ( V_43 ) ;
if ( V_28 == 1 && ! V_24 && ! ( V_25 & V_44 ) ) {
F_8 ( L_8 ) ;
V_38 |= V_45 ;
} else {
F_8 ( L_9 ) ;
V_38 |= V_46 ;
}
V_5 = F_7 ( V_2 , V_35 , V_38 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_14 ( V_28 ) , & V_29 ) ;
if ( V_5 )
return V_5 ;
V_29 &= ~ V_47 ;
V_29 |= ( ( clock -> V_48 ) << V_49 ) ;
V_5 = F_7 ( V_2 , F_14 ( V_28 ) , V_29 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_15 ( V_28 ) , & V_30 ) ;
if ( V_5 )
return V_5 ;
V_30 &= 0xFFFF ;
V_30 |= 0x107 ;
V_30 &= ~ ( V_50 |
V_51 |
V_52 ) ;
V_30 |= ( ( clock -> V_53 ) << V_54 ) ;
if ( clock -> V_55 < 2250000 ) {
V_30 |= ( 2 << V_56 ) ;
V_30 |= ( 0 << V_57 ) ;
} else if ( clock -> V_55 < 2750000 ) {
V_30 |= ( 1 << V_56 ) ;
V_30 |= ( 1 << V_57 ) ;
} else if ( clock -> V_55 < 3300000 ) {
V_30 |= ( 0 << V_56 ) ;
V_30 |= ( 2 << V_57 ) ;
} else {
V_30 |= ( 0 << V_56 ) ;
V_30 |= ( 3 << V_57 ) ;
}
V_5 = F_7 ( V_2 , F_15 ( V_28 ) , V_30 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , F_16 ( V_28 ) , & V_31 ) ;
if ( V_5 )
return V_5 ;
V_31 &= ~ ( V_58 | V_59 ) ;
V_31 |= F_6 ( clock -> V_60 , V_61 ) ;
switch ( clock -> V_62 ) {
case 5 :
V_31 |= F_6 ( V_63 , V_64 ) ;
break;
case 10 :
V_31 |= F_6 ( V_65 , V_64 ) ;
break;
case 14 :
V_31 |= F_6 ( V_66 , V_64 ) ;
break;
case 7 :
V_31 |= F_6 ( V_67 , V_64 ) ;
break;
default:
F_4 ( L_10 , clock -> V_62 ) ;
return - V_68 ;
}
V_5 = F_7 ( V_2 , F_16 ( V_28 ) , V_31 ) ;
if ( V_5 )
return V_5 ;
if ( V_25 ) {
if ( ( V_25 & V_69 ) == V_70 ) {
V_39 = V_71 ;
F_1 ( V_2 , V_39 , & V_40 ) ;
V_40 &= ~ ( V_72 ) ;
V_40 |= V_73 | F_17 ( V_28 ) ;
F_7 ( V_2 , V_39 , V_40 ) ;
V_39 = V_74 ;
F_1 ( V_2 , V_39 , & V_40 ) ;
V_40 &= ~ ( V_72 ) ;
V_40 |= V_73 | F_17 ( V_28 ) ;
F_7 ( V_2 , V_39 , V_40 ) ;
} else {
V_39 = V_75 ;
F_1 ( V_2 , V_39 , & V_40 ) ;
V_40 &= ~ ( V_72 ) ;
V_40 |= V_73 | F_17 ( V_28 ) ;
F_7 ( V_2 , V_39 , V_40 ) ;
V_39 = V_76 ;
F_1 ( V_2 , V_39 , & V_40 ) ;
V_40 &= ~ ( V_72 ) ;
V_40 |= V_73 | F_17 ( V_28 ) ;
F_7 ( V_2 , V_39 , V_40 ) ;
}
}
return 0 ;
}
static bool F_18 ( struct V_21 * V_22 , int type )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_77 * V_78 = & V_2 -> V_78 ;
struct V_79 * V_80 ;
F_19 (l_entry, &mode_config->connector_list, head) {
if ( V_80 -> V_81 && V_80 -> V_81 -> V_22 == V_22 ) {
struct V_82 * V_82 =
F_20 ( V_80 ) ;
if ( V_82 -> type == type )
return true ;
}
}
return false ;
}
static const struct V_83 * F_21 ( struct V_21 * V_22 ,
int V_84 )
{
const struct V_83 * V_85 ;
if ( F_18 ( V_22 , V_86 ) ) {
if ( V_84 == 96000 )
V_85 = & V_87 [ V_88 ] ;
else
V_85 = & V_87 [ V_89 ] ;
} else if ( F_22 ( V_22 , V_90 ) ||
F_22 ( V_22 , V_91 ) ) {
if ( V_84 == 27000 )
V_85 = & V_87 [ V_92 ] ;
else
V_85 = & V_87 [ V_93 ] ;
} else {
if ( V_84 == 27000 )
V_85 = & V_87 [ V_94 ] ;
else
V_85 = & V_87 [ V_95 ] ;
}
return V_85 ;
}
static void F_23 ( struct V_1 * V_2 ,
int V_84 , struct V_23 * clock )
{
clock -> V_29 = clock -> V_48 + 2 ;
clock -> V_31 = clock -> V_60 * clock -> V_62 ;
clock -> V_55 = ( V_84 * clock -> V_29 ) / clock -> V_53 ;
clock -> V_96 = clock -> V_55 / clock -> V_31 ;
}
static bool F_24 ( struct V_21 * V_22 ,
const struct V_83 * V_85 ,
struct V_23 * clock )
{
if ( clock -> V_60 < V_85 -> V_60 . V_97 || V_85 -> V_60 . V_98 < clock -> V_60 )
F_25 ( L_11 ) ;
if ( clock -> V_31 < V_85 -> V_31 . V_97 || V_85 -> V_31 . V_98 < clock -> V_31 )
F_25 ( L_12 ) ;
if ( clock -> V_55 < V_85 -> V_55 . V_97 || V_85 -> V_55 . V_98 < clock -> V_55 )
F_25 ( L_13 ) ;
if ( clock -> V_96 < V_85 -> V_96 . V_97 || V_85 -> V_96 . V_98 < clock -> V_96 )
F_25 ( L_14 ) ;
return true ;
}
static bool F_26 ( const struct V_83 * V_85 ,
struct V_21 * V_22 , int V_99 , int V_84 ,
struct V_23 * V_100 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 clock ;
int V_101 = V_99 ;
if ( F_18 ( V_22 , V_86 ) &&
( F_3 ( V_102 ) & V_103 ) != 0 ) {
if ( ( F_3 ( V_102 ) & V_104 ) ==
V_105 )
clock . V_62 = V_85 -> V_62 . V_106 ;
else
clock . V_62 = V_85 -> V_62 . V_107 ;
} else {
if ( V_99 < V_85 -> V_62 . V_108 )
clock . V_62 = V_85 -> V_62 . V_107 ;
else
clock . V_62 = V_85 -> V_62 . V_106 ;
}
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
clock . V_109 = 0 ;
for ( clock . V_53 = V_85 -> V_53 . V_97 ; clock . V_53 <= V_85 -> V_53 . V_98 ; clock . V_53 ++ ) {
for ( clock . V_48 = V_85 -> V_48 . V_97 ; clock . V_48 <= V_85 -> V_48 . V_98 ;
clock . V_48 ++ ) {
for ( clock . V_60 = V_85 -> V_60 . V_97 ;
clock . V_60 <= V_85 -> V_60 . V_98 ;
clock . V_60 ++ ) {
int V_110 ;
F_23 ( V_2 , V_84 , & clock ) ;
if ( ! F_24 ( V_22 ,
V_85 , & clock ) )
continue;
V_110 = abs ( clock . V_96 - V_99 ) ;
if ( V_110 < V_101 ) {
* V_100 = clock ;
V_101 = V_110 ;
}
}
}
}
return V_101 != V_99 ;
}
static bool F_27 ( const struct V_83 * V_85 , struct V_21 * V_22 , int V_99 ,
int V_84 ,
struct V_23 * V_100 )
{
struct V_23 clock ;
if ( V_84 == 27000 ) {
if ( V_99 < 200000 ) {
clock . V_60 = 2 ;
clock . V_62 = 10 ;
clock . V_53 = 1 ;
clock . V_109 = 0 ;
clock . V_48 = 118 ;
} else {
clock . V_60 = 1 ;
clock . V_62 = 10 ;
clock . V_53 = 1 ;
clock . V_109 = 0 ;
clock . V_48 = 98 ;
}
} else if ( V_84 == 100000 ) {
if ( V_99 < 200000 ) {
clock . V_60 = 2 ;
clock . V_62 = 10 ;
clock . V_53 = 5 ;
clock . V_109 = 0 ;
clock . V_48 = 160 ;
} else {
clock . V_60 = 1 ;
clock . V_62 = 10 ;
clock . V_53 = 5 ;
clock . V_109 = 0 ;
clock . V_48 = 133 ;
}
} else
return false ;
clock . V_29 = clock . V_48 + 2 ;
clock . V_31 = clock . V_60 * clock . V_62 ;
clock . V_55 = ( V_84 * clock . V_29 ) / clock . V_53 ;
clock . V_96 = clock . V_55 / clock . V_31 ;
memcpy ( V_100 , & clock , sizeof( struct V_23 ) ) ;
return true ;
}
static int F_28 ( struct V_21 * V_22 ,
int V_111 , int V_112 , struct V_113 * V_114 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_118 * V_119 = F_29 ( V_22 -> V_120 ) ;
int V_28 = V_26 -> V_28 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_28 ] ;
unsigned long V_124 , V_125 ;
T_1 V_126 ;
int V_5 = 0 ;
if ( ! F_30 ( V_2 , true ) )
return 0 ;
if ( ! V_22 -> V_120 ) {
F_31 ( V_2 -> V_2 , L_15 ) ;
goto V_127;
}
V_5 = F_32 ( V_119 -> V_128 ) ;
if ( V_5 < 0 )
goto V_129;
V_124 = V_119 -> V_128 -> V_125 ;
V_125 = V_112 * V_22 -> V_120 -> V_130 [ 0 ] + V_111 * ( V_22 -> V_120 -> V_131 / 8 ) ;
F_5 ( V_122 -> V_132 , V_22 -> V_120 -> V_130 [ 0 ] ) ;
V_126 = F_3 ( V_122 -> V_133 ) ;
V_126 &= ~ V_134 ;
switch ( V_22 -> V_120 -> V_131 ) {
case 8 :
V_126 |= V_135 ;
break;
case 16 :
if ( V_22 -> V_120 -> V_136 == 15 )
V_126 |= V_137 ;
else
V_126 |= V_138 ;
break;
case 24 :
case 32 :
V_126 |= V_139 ;
break;
default:
F_31 ( V_2 -> V_2 , L_16 ) ;
V_5 = - V_68 ;
goto V_129;
}
F_5 ( V_122 -> V_133 , V_126 ) ;
F_33 ( V_2 -> V_2 ,
L_17 , V_124 , V_125 , V_111 , V_112 ) ;
F_5 ( V_122 -> V_140 , V_125 ) ;
F_3 ( V_122 -> V_140 ) ;
F_5 ( V_122 -> V_141 , V_124 ) ;
F_3 ( V_122 -> V_141 ) ;
V_127:
if ( V_114 )
F_34 ( F_29 ( V_114 ) -> V_128 ) ;
V_129:
F_35 ( V_2 ) ;
return V_5 ;
}
static bool F_36 ( struct V_1 * V_2 , int V_28 )
{
struct V_21 * V_22 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = NULL ;
V_22 = V_116 -> V_142 [ V_28 ] ;
V_26 = F_11 ( V_22 ) ;
if ( V_22 -> V_120 == NULL || ! V_26 -> V_143 )
return false ;
return true ;
}
static bool F_37 ( struct V_1 * V_2 )
{
T_2 V_144 = 0 ;
if ( F_36 ( V_2 , 0 ) )
V_144 |= V_145 ;
if ( F_36 ( V_2 , 1 ) )
V_144 |= V_146 ;
F_8 ( L_18 , V_144 ) ;
if ( V_144 == V_145 || V_144 == V_146 )
return true ;
else
return false ;
}
static bool F_38 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_77 * V_78 = & V_2 -> V_78 ;
struct V_79 * V_147 ;
if ( V_26 -> V_28 != 1 )
return false ;
F_19 (connector, &mode_config->connector_list, head) {
struct V_82 * V_82 =
F_20 ( V_147 ) ;
if ( ! V_147 -> V_81
|| V_147 -> V_81 -> V_22 != V_22 )
continue;
if ( V_82 -> type == V_86 )
return true ;
}
return false ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_3 ( V_148 ) & V_149 ) {
F_5 ( V_148 , ( F_3 ( V_148 ) & ~ V_149 ) ) ;
F_3 ( V_148 ) ;
F_40 ( V_2 ) ;
F_5 ( V_150 , 0 ) ;
F_3 ( V_150 ) ;
F_40 ( V_2 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( F_37 ( V_2 ) ) {
T_1 V_151 ;
V_151 = F_3 ( V_152 ) ;
V_151 &= ~ V_153 ;
V_151 |= ( 0x7e << V_154 ) ;
V_151 &= ~ V_155 ;
V_151 |= ( 0x4 << V_156 ) ;
F_5 ( V_152 , V_151 ) ;
V_151 = F_3 ( V_157 ) ;
V_151 &= ~ V_158 ;
V_151 |= ( 0x6 << V_159 ) ;
V_151 &= ~ V_160 ;
V_151 |= ( 0x8 << V_161 ) ;
F_5 ( V_157 , V_151 ) ;
F_5 ( V_162 , 0x36000000 ) ;
if ( F_38 ( V_2 , V_22 ) ) {
F_5 ( V_163 , 0x00040330 ) ;
} else {
V_151 = ( 3 << V_164 ) |
( 4 << V_165 ) |
( 3 << V_166 ) |
( 4 << V_167 ) ;
F_5 ( V_163 , V_151 ) ;
}
F_5 ( V_168 , 0x10 ) ;
F_40 ( V_2 ) ;
F_5 ( V_148 , V_149 ) ;
F_3 ( V_148 ) ;
F_40 ( V_2 ) ;
} else {
F_5 ( V_152 , 0x3f880808 ) ;
F_5 ( V_157 , 0x0b020202 ) ;
F_5 ( V_162 , 0x24000000 ) ;
F_5 ( V_169 , 0x08030202 ) ;
F_5 ( V_163 , 0x01010101 ) ;
F_5 ( V_168 , 0x1d0 ) ;
F_40 ( V_2 ) ;
F_39 ( V_2 ) ;
}
}
static void F_42 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_170 = V_171 ;
int V_172 ;
if ( ! V_22 -> V_173 )
return;
switch ( V_26 -> V_28 ) {
case 0 :
break;
case 1 :
V_170 = V_174 ;
break;
case 2 :
V_170 = V_175 ;
break;
default:
F_31 ( V_2 -> V_2 , L_19 ) ;
return;
}
if ( F_30 ( V_2 , false ) ) {
for ( V_172 = 0 ; V_172 < 256 ; V_172 ++ ) {
F_5 ( V_170 + 4 * V_172 ,
( ( V_26 -> V_176 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) << 16 ) |
( ( V_26 -> V_178 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) << 8 ) |
( V_26 -> V_179 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) ) ;
}
F_35 ( V_2 ) ;
} else {
for ( V_172 = 0 ; V_172 < 256 ; V_172 ++ ) {
V_116 -> V_180 . V_28 [ 0 ] . V_181 [ V_172 ] =
( ( V_26 -> V_176 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) << 16 ) |
( ( V_26 -> V_178 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) << 8 ) |
( V_26 -> V_179 [ V_172 ] +
V_26 -> V_177 [ V_172 ] ) ;
}
}
}
static void F_43 ( struct V_21 * V_22 , int V_182 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_28 ] ;
T_1 V_16 ;
F_39 ( V_2 ) ;
switch ( V_182 ) {
case V_183 :
case V_184 :
case V_185 :
if ( V_26 -> V_143 )
break;
V_26 -> V_143 = true ;
V_16 = F_3 ( V_122 -> V_186 ) ;
if ( ( V_16 & V_187 ) == 0 ) {
F_5 ( V_122 -> V_186 , V_16 ) ;
F_3 ( V_122 -> V_186 ) ;
F_12 ( 150 ) ;
F_5 ( V_122 -> V_186 , V_16 | V_187 ) ;
F_3 ( V_122 -> V_186 ) ;
F_12 ( 150 ) ;
F_5 ( V_122 -> V_186 , V_16 | V_187 ) ;
F_3 ( V_122 -> V_186 ) ;
F_12 ( 150 ) ;
}
V_16 = F_3 ( V_122 -> V_133 ) ;
if ( ( V_16 & V_188 ) == 0 ) {
F_5 ( V_122 -> V_133 ,
V_16 | V_188 ) ;
F_5 ( V_122 -> V_140 , F_3 ( V_122 -> V_140 ) ) ;
}
F_12 ( 150 ) ;
V_16 = F_3 ( V_122 -> V_189 ) ;
if ( ( V_16 & V_190 ) == 0 )
F_5 ( V_122 -> V_189 , V_16 | V_190 ) ;
V_16 = F_3 ( V_122 -> V_191 ) ;
V_16 &= ~ ( 0xFFFF ) ;
V_16 |= V_192 ;
F_5 ( V_122 -> V_191 , V_16 ) ;
F_3 ( V_122 -> V_191 ) ;
F_42 ( V_22 ) ;
break;
case V_193 :
if ( ! V_26 -> V_143 )
break;
V_26 -> V_143 = false ;
F_5 ( V_194 , V_195 ) ;
F_44 ( V_2 , V_28 ) ;
F_40 ( V_2 ) ;
V_16 = F_3 ( V_122 -> V_189 ) ;
if ( ( V_16 & V_190 ) != 0 ) {
F_5 ( V_122 -> V_189 , V_16 & ~ V_190 ) ;
F_3 ( V_122 -> V_189 ) ;
}
F_40 ( V_2 ) ;
F_12 ( 150 ) ;
V_16 = F_3 ( V_122 -> V_133 ) ;
if ( ( V_16 & V_188 ) != 0 ) {
F_5 ( V_122 -> V_133 ,
V_16 & ~ V_188 ) ;
F_5 ( V_122 -> V_140 , F_3 ( V_122 -> V_140 ) ) ;
F_3 ( V_122 -> V_140 ) ;
}
V_16 = F_3 ( V_122 -> V_186 ) ;
if ( ( V_16 & V_187 ) != 0 ) {
F_5 ( V_122 -> V_186 , V_16 & ~ V_187 ) ;
F_3 ( V_122 -> V_186 ) ;
}
F_12 ( 150 ) ;
break;
}
F_41 ( V_2 , V_22 ) ;
F_5 ( V_196 , 0x3F3E ) ;
}
static void F_45 ( struct V_21 * V_22 )
{
struct V_197 * V_198 = V_22 -> V_199 ;
V_198 -> V_200 ( V_22 , V_193 ) ;
}
static void F_46 ( struct V_21 * V_22 )
{
struct V_197 * V_198 = V_22 -> V_199 ;
V_198 -> V_200 ( V_22 , V_183 ) ;
}
static bool F_47 ( struct V_21 * V_22 ,
const struct V_201 * V_182 ,
struct V_201 * V_202 )
{
return true ;
}
static int F_48 ( struct V_1 * V_2 )
{
T_1 V_203 ;
V_203 = F_3 ( V_204 ) ;
if ( ( V_203 & V_205 ) == 0 )
return - 1 ;
return ( V_203 >> 29 ) & 0x3 ;
}
static int F_49 ( struct V_21 * V_22 ,
struct V_201 * V_182 ,
struct V_201 * V_202 ,
int V_111 , int V_112 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_28 ] ;
int V_84 ;
struct V_23 clock ;
T_1 V_186 = 0 , V_126 , V_206 ;
bool V_207 ;
bool V_208 = false , V_24 = false , V_209 = false ;
bool V_210 = false , V_211 = false ;
struct V_77 * V_78 = & V_2 -> V_78 ;
struct V_79 * V_147 ;
const struct V_83 * V_85 ;
T_1 V_25 = 0 ;
bool V_212 = false ;
F_19 (connector, &mode_config->connector_list, head) {
struct V_82 * V_82 =
F_20 ( V_147 ) ;
if ( ! V_147 -> V_81
|| V_147 -> V_81 -> V_22 != V_22 )
continue;
V_25 = V_82 -> V_25 ;
switch ( V_82 -> type ) {
case V_86 :
V_24 = true ;
break;
case V_213 :
V_209 = true ;
break;
case V_214 :
V_208 = true ;
break;
case V_215 :
V_210 = true ;
break;
case V_90 :
V_211 = true ;
break;
case V_91 :
V_212 = true ;
break;
default:
F_4 ( L_20 ) ;
return 0 ;
}
}
if ( V_116 -> V_216 )
V_84 = 96000 ;
else
V_84 = 27000 ;
if ( V_211 || V_212 ) {
if ( V_28 == 0 )
V_84 = 27000 ;
else
V_84 = 100000 ;
}
if ( V_24 && V_116 -> V_217 ) {
V_84 = V_116 -> V_218 * 1000 ;
F_8 ( L_21 , V_116 -> V_218 ) ;
}
F_50 ( V_202 ) ;
V_85 = F_21 ( V_22 , V_84 ) ;
V_207 = V_85 -> V_219 ( V_85 , V_22 , V_202 -> clock , V_84 ,
& clock ) ;
if ( ! V_207 ) {
F_31 ( V_2 -> V_2 , L_22 ) ;
return 0 ;
}
V_186 = V_42 ;
if ( V_209 ) {
V_186 |= 3 ;
}
if ( V_211 || V_212 ) {
F_51 ( V_22 , V_182 , V_202 ) ;
} else {
F_5 ( F_52 ( V_28 ) , 0 ) ;
F_5 ( F_53 ( V_28 ) , 0 ) ;
F_5 ( F_54 ( V_28 ) , 0 ) ;
F_5 ( F_55 ( V_28 ) , 0 ) ;
}
V_186 |= V_41 ;
V_206 = F_3 ( V_122 -> V_189 ) ;
V_206 &= ~ ( V_220 ) ;
if ( V_212 ) {
switch ( V_116 -> V_221 . V_222 ) {
case 24 :
V_206 |= V_223 ;
break;
case 18 :
V_206 |= V_224 ;
break;
case 30 :
V_206 |= V_225 ;
break;
default:
V_206 |= V_223 ;
break;
}
} else if ( V_24 ) {
if ( ( F_3 ( V_102 ) & V_226 ) == V_227 )
V_206 |= V_223 ;
else
V_206 |= V_224 ;
} else
V_206 |= V_223 ;
V_126 = V_228 ;
if ( V_28 == 0 )
V_126 |= V_229 ;
else
V_126 |= V_230 ;
V_126 |= V_188 ;
V_206 |= V_190 ;
F_5 ( V_122 -> V_186 , V_186 | V_42 | V_41 ) ;
F_3 ( V_122 -> V_186 ) ;
F_10 ( V_2 , V_22 , & clock , V_24 , V_25 ) ;
F_12 ( 150 ) ;
if ( V_24 ) {
T_1 V_231 = F_3 ( V_102 ) ;
V_231 |=
V_103 | V_232 |
V_233 ;
if ( clock . V_62 == 7 )
V_231 |= V_234 | V_105 ;
else
V_231 &= ~ ( V_234 | V_105 ) ;
F_5 ( V_102 , V_231 ) ;
F_3 ( V_102 ) ;
}
V_186 |= V_187 ;
if ( F_48 ( V_2 ) == V_28 )
F_5 ( V_204 , 0 ) ;
F_8 ( L_23 , V_28 == 0 ? 'A' : 'B' ) ;
F_50 ( V_182 ) ;
F_5 ( V_122 -> V_186 ,
( F_3 ( V_122 -> V_186 ) & ~ V_235 ) | V_187 ) ;
F_3 ( V_122 -> V_186 ) ;
F_12 ( 150 ) ;
if ( ! ( F_3 ( V_122 -> V_186 ) & V_235 ) ) {
F_31 ( V_2 -> V_2 , L_24 ) ;
return - V_236 ;
}
{
int V_237 = V_202 -> clock / V_182 -> clock ;
F_5 ( V_122 -> V_238 , ( 0 << V_239 ) | ( ( V_237 - 1 ) << V_240 ) ) ;
}
F_5 ( V_122 -> V_241 , ( V_202 -> V_242 - 1 ) |
( ( V_202 -> V_243 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_244 , ( V_202 -> V_245 - 1 ) |
( ( V_202 -> V_246 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_247 , ( V_202 -> V_248 - 1 ) |
( ( V_202 -> V_249 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_250 , ( V_202 -> V_251 - 1 ) |
( ( V_202 -> V_252 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_253 , ( V_202 -> V_254 - 1 ) |
( ( V_202 -> V_255 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_256 , ( V_202 -> V_257 - 1 ) |
( ( V_202 -> V_258 - 1 ) << 16 ) ) ;
F_5 ( V_122 -> V_259 ,
( ( V_182 -> V_260 - 1 ) << 16 ) | ( V_182 -> V_261 - 1 ) ) ;
F_5 ( V_122 -> V_262 , 0 ) ;
F_5 ( V_122 -> V_263 ,
( ( V_182 -> V_261 - 1 ) << 16 ) | ( V_182 -> V_260 - 1 ) ) ;
F_5 ( V_122 -> V_189 , V_206 ) ;
F_3 ( V_122 -> V_189 ) ;
F_40 ( V_2 ) ;
F_5 ( V_122 -> V_133 , V_126 ) ;
{
struct V_197 * V_198 =
V_22 -> V_199 ;
V_198 -> V_264 ( V_22 , V_111 , V_112 , V_114 ) ;
}
F_40 ( V_2 ) ;
return 0 ;
}
static void F_56 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_265 * V_266 = V_26 -> V_266 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_26 -> V_28 ] ;
T_2 V_267 ;
int V_172 ;
if ( ! V_266 ) {
F_33 ( V_2 -> V_2 , L_25 ) ;
return;
}
V_266 -> V_268 = F_3 ( V_122 -> V_133 ) ;
V_266 -> V_269 = F_3 ( V_122 -> V_189 ) ;
V_266 -> V_270 = F_3 ( V_122 -> V_263 ) ;
V_266 -> V_271 = F_3 ( V_122 -> V_272 ) ;
V_266 -> V_273 = F_3 ( V_122 -> V_274 ) ;
V_266 -> V_275 = F_3 ( V_122 -> V_186 ) ;
V_266 -> V_276 = F_3 ( V_122 -> V_241 ) ;
V_266 -> V_277 = F_3 ( V_122 -> V_244 ) ;
V_266 -> V_278 = F_3 ( V_122 -> V_247 ) ;
V_266 -> V_279 = F_3 ( V_122 -> V_250 ) ;
V_266 -> V_280 = F_3 ( V_122 -> V_253 ) ;
V_266 -> V_281 = F_3 ( V_122 -> V_256 ) ;
V_266 -> V_282 = F_3 ( V_122 -> V_132 ) ;
V_266 -> V_283 = F_3 ( V_122 -> V_259 ) ;
V_266 -> V_284 = F_3 ( V_122 -> V_262 ) ;
V_266 -> V_285 = F_3 ( V_122 -> V_140 ) ;
F_57 ( L_26 ,
V_266 -> V_268 ,
V_266 -> V_269 ,
V_266 -> V_270 ,
V_266 -> V_271 ,
V_266 -> V_273 ,
V_266 -> V_275 ,
V_266 -> V_276 ,
V_266 -> V_277 ,
V_266 -> V_278 ,
V_266 -> V_279 ,
V_266 -> V_280 ,
V_266 -> V_281 ,
V_266 -> V_282 ,
V_266 -> V_283 ,
V_266 -> V_284 ,
V_266 -> V_285
) ;
V_267 = V_122 -> V_181 ;
for ( V_172 = 0 ; V_172 < 256 ; ++ V_172 )
V_266 -> V_286 [ V_172 ] = F_3 ( V_267 + ( V_172 << 2 ) ) ;
}
static void F_58 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
struct V_265 * V_266 = V_26 -> V_266 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_26 -> V_28 ] ;
T_2 V_267 ;
int V_172 ;
if ( ! V_266 ) {
F_33 ( V_2 -> V_2 , L_27 ) ;
return;
}
F_57 (
L_28 ,
F_3 ( V_122 -> V_133 ) ,
F_3 ( V_122 -> V_189 ) ,
F_3 ( V_122 -> V_263 ) ,
F_3 ( V_122 -> V_272 ) ,
F_3 ( V_122 -> V_274 ) ,
F_3 ( V_122 -> V_186 ) ,
F_3 ( V_122 -> V_241 ) ,
F_3 ( V_122 -> V_244 ) ,
F_3 ( V_122 -> V_247 ) ,
F_3 ( V_122 -> V_250 ) ,
F_3 ( V_122 -> V_253 ) ,
F_3 ( V_122 -> V_256 ) ,
F_3 ( V_122 -> V_132 ) ,
F_3 ( V_122 -> V_259 ) ,
F_3 ( V_122 -> V_262 ) ,
F_3 ( V_122 -> V_140 )
) ;
F_57 (
L_29 ,
V_266 -> V_268 ,
V_266 -> V_269 ,
V_266 -> V_270 ,
V_266 -> V_271 ,
V_266 -> V_273 ,
V_266 -> V_275 ,
V_266 -> V_276 ,
V_266 -> V_277 ,
V_266 -> V_278 ,
V_266 -> V_279 ,
V_266 -> V_280 ,
V_266 -> V_281 ,
V_266 -> V_282 ,
V_266 -> V_283 ,
V_266 -> V_284 ,
V_266 -> V_285
) ;
if ( V_266 -> V_275 & V_187 ) {
F_5 ( V_122 -> V_186 ,
V_266 -> V_275 & ~ V_187 ) ;
F_3 ( V_122 -> V_186 ) ;
F_57 ( L_30 ,
F_3 ( V_122 -> V_186 ) ) ;
F_12 ( 150 ) ;
}
F_5 ( V_122 -> V_272 , V_266 -> V_271 ) ;
F_3 ( V_122 -> V_272 ) ;
F_5 ( V_122 -> V_274 , V_266 -> V_273 ) ;
F_3 ( V_122 -> V_274 ) ;
F_5 ( V_122 -> V_186 , V_266 -> V_275 ) ;
F_3 ( V_122 -> V_186 ) ;
F_12 ( 150 ) ;
F_5 ( V_122 -> V_241 , V_266 -> V_276 ) ;
F_5 ( V_122 -> V_244 , V_266 -> V_277 ) ;
F_5 ( V_122 -> V_247 , V_266 -> V_278 ) ;
F_5 ( V_122 -> V_250 , V_266 -> V_279 ) ;
F_5 ( V_122 -> V_253 , V_266 -> V_280 ) ;
F_5 ( V_122 -> V_256 , V_266 -> V_281 ) ;
F_5 ( V_122 -> V_132 , V_266 -> V_282 ) ;
F_5 ( V_122 -> V_259 , V_266 -> V_283 ) ;
F_5 ( V_122 -> V_262 , V_266 -> V_284 ) ;
F_5 ( V_122 -> V_263 , V_266 -> V_270 ) ;
F_5 ( V_122 -> V_140 , V_266 -> V_285 ) ;
F_5 ( V_122 -> V_189 , V_266 -> V_269 ) ;
F_40 ( V_2 ) ;
F_5 ( V_122 -> V_133 , V_266 -> V_268 ) ;
F_5 ( V_122 -> V_140 , V_266 -> V_285 ) ;
F_40 ( V_2 ) ;
V_267 = V_122 -> V_181 ;
for ( V_172 = 0 ; V_172 < 256 ; ++ V_172 )
F_5 ( V_267 + ( V_172 << 2 ) , V_266 -> V_286 [ V_172 ] ) ;
}
static int F_59 ( struct V_21 * V_22 ,
struct V_287 * V_288 ,
T_2 V_289 ,
T_2 V_290 , T_2 V_291 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
T_2 V_292 = ( V_28 == 0 ) ? V_293 : V_294 ;
T_2 V_140 = ( V_28 == 0 ) ? V_295 : V_296 ;
T_2 V_16 ;
T_3 V_297 = 0 ;
struct V_298 * V_299 ;
struct V_300 * V_301 ;
int V_5 ;
if ( ! V_289 ) {
V_16 = V_302 ;
if ( F_30 ( V_2 , false ) ) {
F_5 ( V_292 , V_16 ) ;
F_5 ( V_140 , 0 ) ;
F_35 ( V_2 ) ;
}
if ( V_26 -> V_303 ) {
V_299 = F_60 ( V_26 -> V_303 ,
struct V_298 , V_304 ) ;
F_34 ( V_299 ) ;
F_61 ( V_26 -> V_303 ) ;
V_26 -> V_303 = NULL ;
}
return 0 ;
}
if ( V_290 != 64 || V_291 != 64 ) {
F_33 ( V_2 -> V_2 , L_31 ) ;
return - V_68 ;
}
V_301 = F_62 ( V_2 , V_288 , V_289 ) ;
if ( ! V_301 )
return - V_305 ;
if ( V_301 -> V_259 < V_290 * V_291 * 4 ) {
F_33 ( V_2 -> V_2 , L_32 ) ;
return - V_306 ;
}
V_299 = F_60 ( V_301 , struct V_298 , V_304 ) ;
V_5 = F_32 ( V_299 ) ;
if ( V_5 ) {
F_31 ( V_2 -> V_2 , L_33 , V_289 ) ;
return V_5 ;
}
V_297 = V_299 -> V_125 ;
V_26 -> V_307 = V_297 ;
V_16 = 0 ;
V_16 |= ( V_28 << 28 ) ;
V_16 |= V_308 | V_309 ;
if ( F_30 ( V_2 , false ) ) {
F_5 ( V_292 , V_16 ) ;
F_5 ( V_140 , V_297 ) ;
F_35 ( V_2 ) ;
}
if ( V_26 -> V_303 ) {
V_299 = F_60 ( V_26 -> V_303 ,
struct V_298 , V_304 ) ;
F_34 ( V_299 ) ;
F_61 ( V_26 -> V_303 ) ;
V_26 -> V_303 = V_301 ;
}
return 0 ;
}
static int F_63 ( struct V_21 * V_22 , int V_111 , int V_112 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
T_2 V_16 = 0 ;
T_2 V_310 ;
if ( V_111 < 0 ) {
V_16 |= ( V_311 << V_312 ) ;
V_111 = - V_111 ;
}
if ( V_112 < 0 ) {
V_16 |= ( V_311 << V_313 ) ;
V_112 = - V_112 ;
}
V_16 |= ( ( V_111 & V_314 ) << V_312 ) ;
V_16 |= ( ( V_112 & V_314 ) << V_313 ) ;
V_310 = V_26 -> V_307 ;
if ( F_30 ( V_2 , false ) ) {
F_5 ( ( V_28 == 0 ) ? V_315 : V_316 , V_16 ) ;
F_5 ( ( V_28 == 0 ) ? V_295 : V_296 , V_310 ) ;
F_35 ( V_2 ) ;
}
return 0 ;
}
static void F_64 ( struct V_21 * V_22 , T_4 * V_317 ,
T_4 * V_318 , T_4 * V_319 , T_2 V_124 , T_2 V_259 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_172 ;
int V_320 = ( V_124 + V_259 > 256 ) ? 256 : V_124 + V_259 ;
for ( V_172 = V_124 ; V_172 < V_320 ; V_172 ++ ) {
V_26 -> V_176 [ V_172 ] = V_317 [ V_172 ] >> 8 ;
V_26 -> V_178 [ V_172 ] = V_318 [ V_172 ] >> 8 ;
V_26 -> V_179 [ V_172 ] = V_319 [ V_172 ] >> 8 ;
}
F_42 ( V_22 ) ;
}
static int F_65 ( struct V_321 * V_322 )
{
int V_5 = 0 ;
struct V_1 * V_2 = V_322 -> V_22 -> V_2 ;
struct V_115 * V_116 = V_2 -> V_117 ;
if ( ! V_116 -> V_323 )
return F_66 ( V_322 ) ;
F_67 ( & V_2 -> V_324 -> V_2 ) ;
V_5 = F_66 ( V_322 ) ;
F_68 ( & V_2 -> V_324 -> V_2 ) ;
return V_5 ;
}
static void F_69 ( int V_84 , struct V_23 * clock )
{
clock -> V_29 = 5 * ( clock -> V_109 + 2 ) + ( clock -> V_48 + 2 ) ;
clock -> V_31 = clock -> V_60 * clock -> V_62 ;
clock -> V_55 = V_84 * clock -> V_29 / ( clock -> V_53 + 2 ) ;
clock -> V_96 = clock -> V_55 / clock -> V_31 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_28 ] ;
T_1 V_186 ;
T_1 V_325 ;
struct V_23 clock ;
bool V_24 ;
struct V_326 * V_31 = & V_116 -> V_180 . V_28 [ V_28 ] ;
if ( F_30 ( V_2 , false ) ) {
V_186 = F_3 ( V_122 -> V_186 ) ;
if ( ( V_186 & V_327 ) == 0 )
V_325 = F_3 ( V_122 -> V_272 ) ;
else
V_325 = F_3 ( V_122 -> V_274 ) ;
V_24 = ( V_28 == 1 ) && ( F_3 ( V_102 ) & V_103 ) ;
F_35 ( V_2 ) ;
} else {
V_186 = V_31 -> V_186 ;
if ( ( V_186 & V_327 ) == 0 )
V_325 = V_31 -> V_272 ;
else
V_325 = V_31 -> V_274 ;
V_24 = ( V_28 == 1 ) &&
( V_116 -> V_180 . V_328 . V_329 & V_103 ) ;
}
clock . V_109 = ( V_325 & V_330 ) >> V_331 ;
clock . V_48 = ( V_325 & V_332 ) >> V_333 ;
clock . V_53 = ( V_325 & V_334 ) >> V_335 ;
if ( V_24 ) {
clock . V_60 =
F_71 ( ( V_186 &
V_336 ) >>
V_337 ) ;
if ( clock . V_60 == 0 ) {
clock . V_60 = 4 ;
F_31 ( V_2 -> V_2 , L_34 , V_186 ) ;
}
clock . V_62 = 14 ;
if ( ( V_186 & V_338 ) ==
V_339 ) {
F_69 ( 66000 , & clock ) ;
} else
F_69 ( 48000 , & clock ) ;
} else {
if ( V_186 & V_340 )
clock . V_60 = 2 ;
else {
clock . V_60 =
( ( V_186 &
V_341 ) >>
V_337 ) + 2 ;
}
if ( V_186 & V_342 )
clock . V_62 = 4 ;
else
clock . V_62 = 2 ;
F_69 ( 48000 , & clock ) ;
}
return clock . V_96 ;
}
struct V_201 * F_72 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
int V_28 = V_26 -> V_28 ;
struct V_115 * V_116 = V_2 -> V_117 ;
struct V_326 * V_31 = & V_116 -> V_180 . V_28 [ V_28 ] ;
const struct V_121 * V_122 = & V_116 -> V_123 [ V_28 ] ;
struct V_201 * V_182 ;
int V_343 ;
int V_247 ;
int V_344 ;
int V_256 ;
if ( F_30 ( V_2 , false ) ) {
V_343 = F_3 ( V_122 -> V_241 ) ;
V_247 = F_3 ( V_122 -> V_247 ) ;
V_344 = F_3 ( V_122 -> V_250 ) ;
V_256 = F_3 ( V_122 -> V_256 ) ;
F_35 ( V_2 ) ;
} else {
V_343 = V_31 -> V_241 ;
V_247 = V_31 -> V_247 ;
V_344 = V_31 -> V_250 ;
V_256 = V_31 -> V_256 ;
}
V_182 = F_73 ( sizeof( * V_182 ) , V_345 ) ;
if ( ! V_182 )
return NULL ;
V_182 -> clock = F_70 ( V_2 , V_22 ) ;
V_182 -> V_261 = ( V_343 & 0xffff ) + 1 ;
V_182 -> V_241 = ( ( V_343 & 0xffff0000 ) >> 16 ) + 1 ;
V_182 -> V_346 = ( V_247 & 0xffff ) + 1 ;
V_182 -> V_347 = ( ( V_247 & 0xffff0000 ) >> 16 ) + 1 ;
V_182 -> V_260 = ( V_344 & 0xffff ) + 1 ;
V_182 -> V_250 = ( ( V_344 & 0xffff0000 ) >> 16 ) + 1 ;
V_182 -> V_348 = ( V_256 & 0xffff ) + 1 ;
V_182 -> V_349 = ( ( V_256 & 0xffff0000 ) >> 16 ) + 1 ;
F_74 ( V_182 ) ;
F_75 ( V_182 , 0 ) ;
return V_182 ;
}
static void F_76 ( struct V_21 * V_22 )
{
struct V_26 * V_26 = F_11 ( V_22 ) ;
F_77 ( V_26 -> V_266 ) ;
F_78 ( V_22 ) ;
F_77 ( V_26 ) ;
}
