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
static int F_14 ( struct V_2 * V_3 ,
int V_41 , int V_42 , struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_49 * V_50 = F_16 ( V_3 -> V_51 ) ;
int V_52 = V_48 -> V_52 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_52 ] ;
unsigned long V_56 , V_57 ;
T_1 V_58 ;
int V_59 = 0 ;
if ( ! F_17 ( V_21 , true ) )
return 0 ;
if ( ! V_3 -> V_51 ) {
F_18 ( V_21 -> V_21 , L_10 ) ;
goto V_60;
}
V_59 = F_19 ( V_50 -> V_61 ) ;
if ( V_59 < 0 )
goto V_62;
V_56 = V_50 -> V_61 -> V_57 ;
V_57 = V_42 * V_3 -> V_51 -> V_63 [ 0 ] + V_41 * ( V_3 -> V_51 -> V_64 / 8 ) ;
F_20 ( V_54 -> V_65 , V_3 -> V_51 -> V_63 [ 0 ] ) ;
V_58 = F_11 ( V_54 -> V_66 ) ;
V_58 &= ~ V_67 ;
switch ( V_3 -> V_51 -> V_64 ) {
case 8 :
V_58 |= V_68 ;
break;
case 16 :
if ( V_3 -> V_51 -> V_69 == 15 )
V_58 |= V_70 ;
else
V_58 |= V_71 ;
break;
case 24 :
case 32 :
V_58 |= V_72 ;
break;
default:
F_21 ( V_21 -> V_21 , L_11 ) ;
V_59 = - V_73 ;
F_22 ( V_50 -> V_61 ) ;
goto V_62;
}
F_20 ( V_54 -> V_66 , V_58 ) ;
F_20 ( V_54 -> V_74 , V_56 + V_57 ) ;
F_11 ( V_54 -> V_74 ) ;
V_60:
if ( V_44 )
F_22 ( F_16 ( V_44 ) -> V_61 ) ;
V_62:
F_23 ( V_21 ) ;
return V_59 ;
}
static void F_24 ( struct V_2 * V_3 , int V_75 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
int V_52 = V_48 -> V_52 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_52 ] ;
T_1 V_76 ;
switch ( V_75 ) {
case V_77 :
case V_78 :
case V_79 :
V_76 = F_11 ( V_54 -> V_80 ) ;
if ( ( V_76 & V_81 ) == 0 ) {
F_20 ( V_54 -> V_80 , V_76 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
F_20 ( V_54 -> V_80 , V_76 | V_81 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
F_20 ( V_54 -> V_80 , V_76 | V_81 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
}
V_76 = F_11 ( V_54 -> V_82 ) ;
if ( ( V_76 & V_83 ) == 0 )
F_20 ( V_54 -> V_82 , V_76 | V_83 ) ;
V_76 = F_11 ( V_54 -> V_66 ) ;
if ( ( V_76 & V_84 ) == 0 ) {
F_20 ( V_54 -> V_66 ,
V_76 | V_84 ) ;
F_20 ( V_54 -> V_74 , F_11 ( V_54 -> V_74 ) ) ;
}
F_26 ( V_3 ) ;
break;
case V_85 :
F_20 ( V_86 , V_87 ) ;
V_76 = F_11 ( V_54 -> V_66 ) ;
if ( ( V_76 & V_84 ) != 0 ) {
F_20 ( V_54 -> V_66 ,
V_76 & ~ V_84 ) ;
F_20 ( V_54 -> V_74 , F_11 ( V_54 -> V_74 ) ) ;
F_11 ( V_54 -> V_74 ) ;
}
V_76 = F_11 ( V_54 -> V_82 ) ;
if ( ( V_76 & V_83 ) != 0 ) {
F_20 ( V_54 -> V_82 , V_76 & ~ V_83 ) ;
F_11 ( V_54 -> V_82 ) ;
}
F_12 ( V_21 ) ;
V_76 = F_11 ( V_54 -> V_80 ) ;
if ( ( V_76 & V_81 ) != 0 ) {
F_20 ( V_54 -> V_80 , V_76 & ~ V_81 ) ;
F_11 ( V_54 -> V_80 ) ;
}
F_25 ( 150 ) ;
break;
}
F_20 ( V_88 , 0x3F3E ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_89 * V_90 = V_3 -> V_91 ;
V_90 -> V_92 ( V_3 , V_85 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_89 * V_90 = V_3 -> V_91 ;
V_90 -> V_92 ( V_3 , V_77 ) ;
}
void F_29 ( struct V_93 * V_26 )
{
struct V_94 * V_95 =
V_26 -> V_91 ;
V_95 -> V_92 ( V_26 , V_85 ) ;
}
void F_30 ( struct V_93 * V_26 )
{
struct V_94 * V_95 =
V_26 -> V_91 ;
V_95 -> V_92 ( V_26 , V_77 ) ;
}
void F_31 ( struct V_93 * V_26 )
{
struct V_27 * V_96 = F_32 ( V_26 ) ;
F_33 ( V_26 ) ;
F_34 ( V_96 ) ;
}
static bool F_35 ( struct V_2 * V_3 ,
const struct V_97 * V_75 ,
struct V_97 * V_98 )
{
return true ;
}
static int F_36 ( struct V_20 * V_21 )
{
T_1 V_99 ;
V_99 = F_11 ( V_100 ) ;
if ( ( V_99 & V_101 ) == 0 )
return - 1 ;
return 1 ;
}
static int F_37 ( struct V_2 * V_3 ,
struct V_97 * V_75 ,
struct V_97 * V_98 ,
int V_41 , int V_42 ,
struct V_43 * V_44 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_89 * V_90 = V_3 -> V_91 ;
int V_52 = V_48 -> V_52 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_52 ] ;
int V_9 ;
struct V_10 clock ;
T_1 V_80 = 0 , V_102 = 0 , V_58 , V_103 ;
bool V_104 , V_105 = false ;
bool V_106 = false , V_107 = false ;
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_108 ;
if ( V_3 -> V_51 == NULL ) {
V_90 -> V_109 ( V_3 , V_41 , V_42 , V_44 ) ;
return 0 ;
}
F_6 (connector, &mode_config->connector_list, head) {
struct V_27 * V_27 =
F_7 ( V_108 ) ;
if ( ! V_108 -> V_26
|| V_108 -> V_26 -> V_3 != V_3 )
continue;
switch ( V_27 -> type ) {
case V_5 :
V_106 = true ;
break;
case V_110 :
V_105 = true ;
break;
case V_111 :
V_107 = true ;
break;
}
}
V_9 = 96000 ;
V_104 = F_10 ( V_3 , V_98 -> clock , V_9 ,
& clock ) ;
if ( ! V_104 ) {
F_21 ( V_21 -> V_21 , L_12 ) ;
return 0 ;
}
V_102 = clock . V_18 << 16 | clock . V_12 << 8 | clock . V_13 ;
V_80 = V_112 ;
if ( V_106 ) {
V_80 |= V_113 ;
V_80 |= V_114 ;
} else
V_80 |= V_115 ;
if ( V_105 ) {
int V_116 =
V_98 -> clock / V_75 -> clock ;
V_80 |= V_114 ;
V_80 |=
( V_116 - 1 ) << V_117 ;
}
V_80 |= ( 1 << ( clock . V_15 - 1 ) ) << 16 ;
switch ( clock . V_16 ) {
case 5 :
V_80 |= V_118 ;
break;
case 7 :
V_80 |= V_119 ;
break;
case 10 :
V_80 |= V_120 ;
break;
case 14 :
V_80 |= V_121 ;
break;
}
if ( V_107 ) {
V_80 |= 3 ;
}
V_80 |= V_122 ;
V_103 = F_11 ( V_54 -> V_82 ) ;
V_58 = V_123 ;
if ( V_52 == 0 )
V_58 |= V_124 ;
else
V_58 |= V_125 ;
V_58 |= V_84 ;
V_103 |= V_83 ;
V_80 |= V_81 ;
if ( F_36 ( V_21 ) == V_52 )
F_20 ( V_100 , 0 ) ;
F_38 ( V_75 ) ;
if ( V_80 & V_81 ) {
F_20 ( V_54 -> V_126 , V_102 ) ;
F_20 ( V_54 -> V_80 , V_80 & ~ V_81 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
}
if ( V_106 ) {
T_1 V_127 = F_11 ( V_33 ) ;
V_127 &= ~ V_128 ;
if ( V_52 == 1 )
V_127 |= V_128 ;
V_127 |= V_34 | V_129 ;
V_127 &= ~ ( V_130 | V_36 ) ;
if ( clock . V_16 == 7 )
V_127 |= V_130 | V_36 ;
F_20 ( V_33 , V_127 ) ;
F_11 ( V_33 ) ;
}
F_20 ( V_54 -> V_126 , V_102 ) ;
F_20 ( V_54 -> V_80 , V_80 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
F_20 ( V_54 -> V_80 , V_80 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
F_20 ( V_54 -> V_131 , ( V_98 -> V_132 - 1 ) |
( ( V_98 -> V_133 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_134 , ( V_98 -> V_135 - 1 ) |
( ( V_98 -> V_136 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_137 , ( V_98 -> V_138 - 1 ) |
( ( V_98 -> V_139 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_140 , ( V_98 -> V_141 - 1 ) |
( ( V_98 -> V_142 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_143 , ( V_98 -> V_144 - 1 ) |
( ( V_98 -> V_145 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_146 , ( V_98 -> V_147 - 1 ) |
( ( V_98 -> V_148 - 1 ) << 16 ) ) ;
F_20 ( V_54 -> V_149 ,
( ( V_75 -> V_150 - 1 ) << 16 ) | ( V_75 -> V_151 - 1 ) ) ;
F_20 ( V_54 -> V_152 , 0 ) ;
F_20 ( V_54 -> V_153 ,
( ( V_75 -> V_151 - 1 ) << 16 ) | ( V_75 -> V_150 - 1 ) ) ;
F_20 ( V_54 -> V_82 , V_103 ) ;
F_11 ( V_54 -> V_82 ) ;
F_12 ( V_21 ) ;
F_20 ( V_54 -> V_66 , V_58 ) ;
V_90 -> V_109 ( V_3 , V_41 , V_42 , V_44 ) ;
F_12 ( V_21 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_48 -> V_52 ] ;
int V_154 = V_54 -> V_155 ;
int V_156 ;
if ( ! V_3 -> V_157 )
return;
switch ( V_48 -> V_52 ) {
case 0 :
case 1 :
break;
default:
F_21 ( V_21 -> V_21 , L_13 ) ;
return;
}
if ( F_17 ( V_21 , false ) ) {
for ( V_156 = 0 ; V_156 < 256 ; V_156 ++ ) {
F_20 ( V_154 + 4 * V_156 ,
( ( V_48 -> V_158 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) << 16 ) |
( ( V_48 -> V_160 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) << 8 ) |
( V_48 -> V_161 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) ) ;
}
F_23 ( V_21 ) ;
} else {
for ( V_156 = 0 ; V_156 < 256 ; V_156 ++ ) {
V_46 -> V_162 . V_52 [ 0 ] . V_155 [ V_156 ] =
( ( V_48 -> V_158 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) << 16 ) |
( ( V_48 -> V_160 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) << 8 ) |
( V_48 -> V_161 [ V_156 ] +
V_48 -> V_159 [ V_156 ] ) ;
}
}
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_163 * V_164 = V_48 -> V_164 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_48 -> V_52 ] ;
T_2 V_165 ;
int V_156 ;
if ( ! V_164 ) {
F_21 ( V_21 -> V_21 , L_14 ) ;
return;
}
V_164 -> V_166 = F_11 ( V_54 -> V_66 ) ;
V_164 -> V_167 = F_11 ( V_54 -> V_82 ) ;
V_164 -> V_168 = F_11 ( V_54 -> V_153 ) ;
V_164 -> V_169 = F_11 ( V_54 -> V_126 ) ;
V_164 -> V_170 = F_11 ( V_54 -> V_171 ) ;
V_164 -> V_172 = F_11 ( V_54 -> V_80 ) ;
V_164 -> V_173 = F_11 ( V_54 -> V_131 ) ;
V_164 -> V_174 = F_11 ( V_54 -> V_134 ) ;
V_164 -> V_175 = F_11 ( V_54 -> V_137 ) ;
V_164 -> V_176 = F_11 ( V_54 -> V_140 ) ;
V_164 -> V_177 = F_11 ( V_54 -> V_143 ) ;
V_164 -> V_178 = F_11 ( V_54 -> V_146 ) ;
V_164 -> V_179 = F_11 ( V_54 -> V_65 ) ;
V_164 -> V_180 = F_11 ( V_54 -> V_149 ) ;
V_164 -> V_181 = F_11 ( V_54 -> V_152 ) ;
V_164 -> V_182 = F_11 ( V_54 -> V_74 ) ;
V_165 = V_54 -> V_155 ;
for ( V_156 = 0 ; V_156 < 256 ; ++ V_156 )
V_164 -> V_183 [ V_156 ] = F_11 ( V_165 + ( V_156 << 2 ) ) ;
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_163 * V_164 = V_48 -> V_164 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_48 -> V_52 ] ;
T_2 V_165 ;
int V_156 ;
if ( ! V_164 ) {
F_21 ( V_21 -> V_21 , L_15 ) ;
return;
}
if ( V_164 -> V_172 & V_81 ) {
F_20 ( V_54 -> V_80 ,
V_164 -> V_172 & ~ V_81 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
}
F_20 ( V_54 -> V_126 , V_164 -> V_169 ) ;
F_11 ( V_54 -> V_126 ) ;
F_20 ( V_54 -> V_171 , V_164 -> V_170 ) ;
F_11 ( V_54 -> V_171 ) ;
F_20 ( V_54 -> V_80 , V_164 -> V_172 ) ;
F_11 ( V_54 -> V_80 ) ;
F_25 ( 150 ) ;
F_20 ( V_54 -> V_131 , V_164 -> V_173 ) ;
F_20 ( V_54 -> V_134 , V_164 -> V_174 ) ;
F_20 ( V_54 -> V_137 , V_164 -> V_175 ) ;
F_20 ( V_54 -> V_140 , V_164 -> V_176 ) ;
F_20 ( V_54 -> V_143 , V_164 -> V_177 ) ;
F_20 ( V_54 -> V_146 , V_164 -> V_178 ) ;
F_20 ( V_54 -> V_65 , V_164 -> V_179 ) ;
F_20 ( V_54 -> V_149 , V_164 -> V_180 ) ;
F_20 ( V_54 -> V_152 , V_164 -> V_181 ) ;
F_20 ( V_54 -> V_153 , V_164 -> V_168 ) ;
F_20 ( V_54 -> V_74 , V_164 -> V_182 ) ;
F_20 ( V_54 -> V_82 , V_164 -> V_167 ) ;
F_12 ( V_21 ) ;
F_20 ( V_54 -> V_66 , V_164 -> V_166 ) ;
F_20 ( V_54 -> V_74 , V_164 -> V_182 ) ;
F_12 ( V_21 ) ;
V_165 = V_54 -> V_155 ;
for ( V_156 = 0 ; V_156 < 256 ; ++ V_156 )
F_20 ( V_165 + ( V_156 << 2 ) , V_164 -> V_183 [ V_156 ] ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_184 * V_185 ,
T_2 V_186 ,
T_2 V_187 , T_2 V_188 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
int V_52 = V_48 -> V_52 ;
T_2 V_189 = ( V_52 == 0 ) ? V_190 : V_191 ;
T_2 V_74 = ( V_52 == 0 ) ? V_192 : V_193 ;
T_2 V_76 ;
T_3 V_194 = 0 ;
struct V_195 * V_196 ;
struct V_195 * V_197 = V_48 -> V_197 ;
struct V_198 * V_199 ;
void * V_200 , * V_201 ;
int V_59 , V_156 , V_202 ;
if ( ! V_186 ) {
V_76 = V_203 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_189 , V_76 ) ;
F_20 ( V_74 , 0 ) ;
F_23 ( V_21 ) ;
}
if ( V_48 -> V_204 ) {
V_196 = F_42 ( V_48 -> V_204 ,
struct V_195 , V_205 ) ;
F_22 ( V_196 ) ;
F_43 ( V_48 -> V_204 ) ;
V_48 -> V_204 = NULL ;
}
return 0 ;
}
if ( V_187 != 64 || V_188 != 64 ) {
F_18 ( V_21 -> V_21 , L_16 ) ;
return - V_73 ;
}
V_199 = F_44 ( V_21 , V_185 , V_186 ) ;
if ( ! V_199 )
return - V_206 ;
if ( V_199 -> V_149 < V_187 * V_188 * 4 ) {
F_18 ( V_21 -> V_21 , L_17 ) ;
return - V_207 ;
}
V_196 = F_42 ( V_199 , struct V_195 , V_205 ) ;
V_59 = F_19 ( V_196 ) ;
if ( V_59 ) {
F_21 ( V_21 -> V_21 , L_18 , V_186 ) ;
return V_59 ;
}
if ( V_46 -> V_208 -> V_209 ) {
if ( V_197 == NULL ) {
F_21 ( V_21 -> V_21 , L_19 ) ;
return - V_207 ;
}
if ( V_196 -> V_210 > 4 )
V_202 = 4 ;
else
V_202 = V_196 -> V_210 ;
V_200 = V_46 -> V_211 + V_197 -> V_57 ;
for ( V_156 = 0 ; V_156 < V_202 ; V_156 ++ ) {
V_201 = F_45 ( V_196 -> V_212 [ V_156 ] ) ;
memcpy ( V_200 , V_201 , V_213 ) ;
F_46 ( V_196 -> V_212 [ V_156 ] ) ;
V_200 += V_213 ;
}
V_194 = V_48 -> V_214 ;
} else {
V_194 = V_196 -> V_57 ;
V_48 -> V_214 = V_194 ;
}
V_76 = 0 ;
V_76 |= ( V_52 << 28 ) ;
V_76 |= V_215 | V_216 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( V_189 , V_76 ) ;
F_20 ( V_74 , V_194 ) ;
F_23 ( V_21 ) ;
}
if ( V_48 -> V_204 ) {
V_196 = F_42 ( V_48 -> V_204 ,
struct V_195 , V_205 ) ;
F_22 ( V_196 ) ;
F_43 ( V_48 -> V_204 ) ;
V_48 -> V_204 = V_199 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , int V_41 , int V_42 )
{
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_48 * V_48 = F_15 ( V_3 ) ;
int V_52 = V_48 -> V_52 ;
T_2 V_76 = 0 ;
T_2 V_194 ;
if ( V_41 < 0 ) {
V_76 |= ( V_217 << V_218 ) ;
V_41 = - V_41 ;
}
if ( V_42 < 0 ) {
V_76 |= ( V_217 << V_219 ) ;
V_42 = - V_42 ;
}
V_76 |= ( ( V_41 & V_220 ) << V_218 ) ;
V_76 |= ( ( V_42 & V_220 ) << V_219 ) ;
V_194 = V_48 -> V_214 ;
if ( F_17 ( V_21 , false ) ) {
F_20 ( ( V_52 == 0 ) ? V_221 : V_222 , V_76 ) ;
F_20 ( ( V_52 == 0 ) ? V_192 : V_193 , V_194 ) ;
F_23 ( V_21 ) ;
}
return 0 ;
}
void F_48 ( struct V_2 * V_3 , T_4 * V_223 ,
T_4 * V_224 , T_4 * V_225 , T_2 type , T_2 V_149 )
{
struct V_48 * V_48 = F_15 ( V_3 ) ;
int V_156 ;
if ( V_149 != 256 )
return;
for ( V_156 = 0 ; V_156 < 256 ; V_156 ++ ) {
V_48 -> V_158 [ V_156 ] = V_223 [ V_156 ] >> 8 ;
V_48 -> V_160 [ V_156 ] = V_224 [ V_156 ] >> 8 ;
V_48 -> V_161 [ V_156 ] = V_225 [ V_156 ] >> 8 ;
}
F_26 ( V_3 ) ;
}
static int F_49 ( struct V_226 * V_227 )
{
int V_59 ;
struct V_20 * V_21 = V_227 -> V_3 -> V_21 ;
struct V_45 * V_46 = V_21 -> V_47 ;
if ( ! V_46 -> V_228 )
return F_50 ( V_227 ) ;
F_51 ( & V_21 -> V_229 -> V_21 ) ;
V_59 = F_50 ( V_227 ) ;
F_52 ( & V_21 -> V_229 -> V_21 ) ;
return V_59 ;
}
static int F_53 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_45 * V_46 = V_21 -> V_47 ;
int V_52 = V_48 -> V_52 ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_52 ] ;
T_1 V_80 ;
T_1 V_102 ;
struct V_10 clock ;
bool V_106 ;
struct V_230 * V_14 = & V_46 -> V_162 . V_52 [ V_52 ] ;
if ( F_17 ( V_21 , false ) ) {
V_80 = F_11 ( V_54 -> V_80 ) ;
if ( ( V_80 & V_231 ) == 0 )
V_102 = F_11 ( V_54 -> V_126 ) ;
else
V_102 = F_11 ( V_54 -> V_171 ) ;
V_106 = ( V_52 == 1 ) && ( F_11 ( V_33 ) & V_34 ) ;
F_23 ( V_21 ) ;
} else {
V_80 = V_14 -> V_80 ;
if ( ( V_80 & V_231 ) == 0 )
V_102 = V_14 -> V_126 ;
else
V_102 = V_14 -> V_171 ;
V_106 = ( V_52 == 1 ) && ( V_46 -> V_162 . V_232 . V_233 &
V_34 ) ;
}
clock . V_12 = ( V_102 & V_234 ) >> V_235 ;
clock . V_13 = ( V_102 & V_236 ) >> V_237 ;
clock . V_18 = ( V_102 & V_238 ) >> V_239 ;
if ( V_106 ) {
clock . V_15 =
F_54 ( ( V_80 &
V_240 ) >>
V_241 ) ;
clock . V_16 = 14 ;
if ( ( V_80 & V_242 ) ==
V_243 ) {
F_3 ( 66000 , & clock ) ;
} else
F_3 ( 48000 , & clock ) ;
} else {
if ( V_80 & V_244 )
clock . V_15 = 2 ;
else {
clock . V_15 =
( ( V_80 &
V_245 ) >>
V_241 ) + 2 ;
}
if ( V_80 & V_246 )
clock . V_16 = 4 ;
else
clock . V_16 = 2 ;
F_3 ( 48000 , & clock ) ;
}
return clock . V_19 ;
}
struct V_97 * F_55 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
struct V_48 * V_48 = F_15 ( V_3 ) ;
int V_52 = V_48 -> V_52 ;
struct V_97 * V_75 ;
int V_247 ;
int V_137 ;
int V_248 ;
int V_146 ;
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_230 * V_14 = & V_46 -> V_162 . V_52 [ V_52 ] ;
const struct V_53 * V_54 = & V_46 -> V_55 [ V_52 ] ;
if ( F_17 ( V_21 , false ) ) {
V_247 = F_11 ( V_54 -> V_131 ) ;
V_137 = F_11 ( V_54 -> V_137 ) ;
V_248 = F_11 ( V_54 -> V_140 ) ;
V_146 = F_11 ( V_54 -> V_146 ) ;
F_23 ( V_21 ) ;
} else {
V_247 = V_14 -> V_131 ;
V_137 = V_14 -> V_137 ;
V_248 = V_14 -> V_140 ;
V_146 = V_14 -> V_146 ;
}
V_75 = F_56 ( sizeof( * V_75 ) , V_249 ) ;
if ( ! V_75 )
return NULL ;
V_75 -> clock = F_53 ( V_21 , V_3 ) ;
V_75 -> V_151 = ( V_247 & 0xffff ) + 1 ;
V_75 -> V_131 = ( ( V_247 & 0xffff0000 ) >> 16 ) + 1 ;
V_75 -> V_250 = ( V_137 & 0xffff ) + 1 ;
V_75 -> V_251 = ( ( V_137 & 0xffff0000 ) >> 16 ) + 1 ;
V_75 -> V_150 = ( V_248 & 0xffff ) + 1 ;
V_75 -> V_140 = ( ( V_248 & 0xffff0000 ) >> 16 ) + 1 ;
V_75 -> V_252 = ( V_146 & 0xffff ) + 1 ;
V_75 -> V_253 = ( ( V_146 & 0xffff0000 ) >> 16 ) + 1 ;
F_57 ( V_75 ) ;
F_58 ( V_75 , 0 ) ;
return V_75 ;
}
void F_59 ( struct V_2 * V_3 )
{
struct V_48 * V_48 = F_15 ( V_3 ) ;
struct V_195 * V_196 ;
if ( V_48 -> V_204 ) {
V_196 = F_42 ( V_48 -> V_204 ,
struct V_195 , V_205 ) ;
F_22 ( V_196 ) ;
F_43 ( V_48 -> V_204 ) ;
V_48 -> V_204 = NULL ;
}
if ( V_48 -> V_197 != NULL )
F_60 ( V_3 -> V_21 , V_48 -> V_197 ) ;
F_34 ( V_48 -> V_164 ) ;
F_61 ( V_3 ) ;
F_34 ( V_48 ) ;
}
static void F_62 ( struct V_20 * V_21 ,
struct V_48 * V_48 )
{
struct V_45 * V_46 = V_21 -> V_47 ;
T_1 V_189 [ 3 ] = { V_190 , V_191 , V_254 } ;
T_1 V_74 [ 3 ] = { V_192 , V_193 , V_255 } ;
struct V_195 * V_197 ;
if ( V_46 -> V_208 -> V_209 ) {
V_197 = F_63 ( V_21 , 4 * V_213 , L_20 , 1 ) ;
if ( ! V_197 ) {
V_48 -> V_197 = NULL ;
goto V_256;
}
V_48 -> V_197 = V_197 ;
V_48 -> V_214 = V_46 -> V_257 +
V_197 -> V_57 ;
} else {
V_48 -> V_197 = NULL ;
}
V_256:
F_20 ( V_189 [ V_48 -> V_52 ] , 0 ) ;
F_20 ( V_74 [ V_48 -> V_52 ] , 0 ) ;
}
void F_64 ( struct V_20 * V_21 , int V_52 ,
struct V_258 * V_259 )
{
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_48 * V_48 ;
int V_156 ;
T_5 * V_260 , * V_261 , * V_262 ;
V_48 =
F_56 ( sizeof( struct V_48 ) +
( V_263 * sizeof( struct V_24 * ) ) ,
V_249 ) ;
if ( V_48 == NULL )
return;
V_48 -> V_164 =
F_56 ( sizeof( struct V_163 ) , V_249 ) ;
if ( ! V_48 -> V_164 ) {
F_21 ( V_21 -> V_21 , L_21 ) ;
F_34 ( V_48 ) ;
return;
}
F_65 ( V_21 , & V_48 -> V_74 , V_46 -> V_208 -> V_90 ) ;
F_66 ( & V_48 -> V_74 , 256 ) ;
V_48 -> V_52 = V_52 ;
V_48 -> V_264 = V_52 ;
V_260 = V_48 -> V_74 . V_265 ;
V_261 = V_260 + 256 ;
V_262 = V_261 + 256 ;
for ( V_156 = 0 ; V_156 < 256 ; V_156 ++ ) {
V_48 -> V_158 [ V_156 ] = V_156 ;
V_48 -> V_160 [ V_156 ] = V_156 ;
V_48 -> V_161 [ V_156 ] = V_156 ;
V_260 [ V_156 ] = V_156 << 8 ;
V_261 [ V_156 ] = V_156 << 8 ;
V_262 [ V_156 ] = V_156 << 8 ;
V_48 -> V_159 [ V_156 ] = 0 ;
}
V_48 -> V_259 = V_259 ;
V_48 -> V_214 = 0 ;
F_67 ( & V_48 -> V_74 ,
V_46 -> V_208 -> V_266 ) ;
V_48 -> V_267 . V_3 = & V_48 -> V_74 ;
F_68 ( V_52 >= F_69 ( V_46 -> V_268 ) ||
V_46 -> V_268 [ V_48 -> V_264 ] != NULL ) ;
V_46 -> V_268 [ V_48 -> V_264 ] =
& V_48 -> V_74 ;
V_46 -> V_269 [ V_48 -> V_52 ] =
& V_48 -> V_74 ;
V_48 -> V_267 . V_270 =
(struct V_24 * * ) ( V_48 + 1 ) ;
V_48 -> V_267 . V_271 = 0 ;
F_62 ( V_21 , V_48 ) ;
V_48 -> V_272 = true ;
}
int F_70 ( struct V_20 * V_21 , void * V_273 ,
struct V_184 * V_185 )
{
struct V_45 * V_46 = V_21 -> V_47 ;
struct V_274 * V_275 = V_273 ;
struct V_276 * V_277 ;
struct V_48 * V_3 ;
if ( ! V_46 ) {
F_21 ( V_21 -> V_21 , L_22 ) ;
return - V_73 ;
}
V_277 = F_71 ( V_21 , V_275 -> V_278 ,
V_279 ) ;
if ( ! V_277 ) {
F_21 ( V_21 -> V_21 , L_23 ) ;
return - V_73 ;
}
V_3 = F_15 ( F_72 ( V_277 ) ) ;
V_275 -> V_52 = V_3 -> V_52 ;
return 0 ;
}
struct V_2 * F_73 ( struct V_20 * V_21 , int V_52 )
{
struct V_2 * V_3 = NULL ;
F_6 (crtc, &dev->mode_config.crtc_list, head) {
struct V_48 * V_48 = F_15 ( V_3 ) ;
if ( V_48 -> V_52 == V_52 )
break;
}
return V_3 ;
}
int F_74 ( struct V_20 * V_21 , int V_280 )
{
int V_281 = 0 ;
struct V_24 * V_108 ;
int V_282 = 0 ;
F_6 (connector, &dev->mode_config.connector_list,
head) {
struct V_27 * V_27 =
F_7 ( V_108 ) ;
if ( V_280 & ( 1 << V_27 -> type ) )
V_281 |= ( 1 << V_282 ) ;
V_282 ++ ;
}
return V_281 ;
}
struct V_93 * F_75 ( struct V_24 * V_108 )
{
struct V_27 * V_27 =
F_7 ( V_108 ) ;
return & V_27 -> V_74 ;
}
void F_76 ( struct V_283 * V_108 ,
struct V_27 * V_26 )
{
V_108 -> V_26 = V_26 ;
F_77 ( & V_108 -> V_74 ,
& V_26 -> V_74 ) ;
}
