static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , bool V_5 )
{
T_2 V_6 ;
F_2 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
V_6 |= V_4 ;
else
V_6 &= ~ V_4 ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , bool V_5 )
{
T_1 V_6 ;
F_5 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
V_6 |= V_4 ;
else
V_6 &= ~ V_4 ;
F_6 ( V_2 , V_3 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_7 , int V_8 , T_2 V_4 ,
bool V_5 )
{
T_1 V_3 ;
T_2 V_6 ;
V_3 = F_8 ( V_7 , V_8 ) ;
F_2 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
V_6 |= V_4 ;
else
V_6 &= ~ V_4 ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_7 , int V_8 ,
T_1 V_4 , bool V_5 )
{
T_1 V_3 ;
T_1 V_6 ;
V_3 = F_8 ( V_7 , V_8 ) ;
F_5 ( V_2 , V_3 , & V_6 ) ;
if ( V_5 )
V_6 |= V_4 ;
else
V_6 &= ~ V_4 ;
F_6 ( V_2 , V_3 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_9 , int V_10 )
{
T_2 V_6 ;
do {
F_2 ( V_2 , V_11 , & V_6 ) ;
if ( ! ( V_6 & V_9 ) )
break;
F_11 ( 1 , 10 ) ;
} while ( V_10 -- > 0 );
if ( V_10 <= 0 )
return - V_12 ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , T_3 V_15 , T_1 * V_16 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_18 ;
F_13 ( & V_2 -> V_19 ) ;
F_14 ( V_2 , V_20 , V_15 & V_21 ) ;
F_3 ( V_2 , V_11 , V_22 | V_23 ) ;
V_18 = F_10 ( V_2 , V_23 , 1000 ) ;
if ( V_18 < 0 ) {
F_15 ( V_2 -> V_2 , L_1 ) ;
goto exit;
}
F_5 ( V_2 , V_24 , & V_16 [ 0 ] ) ;
F_5 ( V_2 , V_25 , & V_16 [ 1 ] ) ;
F_5 ( V_2 , V_26 , & V_16 [ 2 ] ) ;
F_3 ( V_2 , V_11 , 0 ) ;
exit:
F_16 ( & V_2 -> V_19 ) ;
return V_18 ;
}
static int F_17 ( struct V_13 * V_14 , T_3 V_15 , T_1 * V_16 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_18 ;
F_13 ( & V_2 -> V_19 ) ;
F_6 ( V_2 , V_24 , V_16 [ 0 ] ) ;
F_6 ( V_2 , V_25 , V_16 [ 1 ] ) ;
F_6 ( V_2 , V_26 , V_16 [ 2 ] ) ;
F_14 ( V_2 , V_20 , V_15 & V_21 ) ;
F_3 ( V_2 , V_11 , V_23 | V_27 ) ;
V_18 = F_10 ( V_2 , V_23 , 1000 ) ;
if ( V_18 < 0 ) {
F_15 ( V_2 -> V_2 , L_2 ) ;
goto exit;
}
F_3 ( V_2 , V_11 , 0 ) ;
V_2 -> V_28 [ V_15 ] . V_29 [ 0 ] = V_16 [ 0 ] ;
V_2 -> V_28 [ V_15 ] . V_29 [ 1 ] = V_16 [ 1 ] ;
V_2 -> V_28 [ V_15 ] . V_29 [ 2 ] = V_16 [ 2 ] ;
exit:
F_16 ( & V_2 -> V_19 ) ;
return V_18 ;
}
static void F_18 ( struct V_13 * V_14 , T_1 * V_29 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
F_5 ( V_2 , V_30 , & V_29 [ 0 ] ) ;
F_5 ( V_2 , V_31 , & V_29 [ 1 ] ) ;
F_5 ( V_2 , V_32 , & V_29 [ 2 ] ) ;
F_5 ( V_2 , V_33 , & V_29 [ 3 ] ) ;
}
static void F_19 ( struct V_13 * V_14 , T_1 * V_29 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
F_6 ( V_2 , V_30 , V_29 [ 0 ] ) ;
F_6 ( V_2 , V_31 , V_29 [ 1 ] ) ;
F_6 ( V_2 , V_32 , V_29 [ 2 ] ) ;
F_6 ( V_2 , V_33 , V_29 [ 3 ] ) ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_9 , int V_10 )
{
T_1 V_6 ;
do {
F_5 ( V_2 , V_34 , & V_6 ) ;
if ( ! ( V_6 & V_9 ) )
break;
F_11 ( 1 , 10 ) ;
} while ( V_10 -- > 0 );
if ( V_10 <= 0 )
return - V_12 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_9 , int V_10 )
{
T_1 V_6 ;
do {
F_5 ( V_2 , V_35 , & V_6 ) ;
if ( ! ( V_6 & V_9 ) )
break;
F_11 ( 1 , 10 ) ;
} while ( V_10 -- > 0 );
if ( V_10 <= 0 )
return - V_12 ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_2 V_36 ;
T_3 V_37 ;
T_1 V_38 ;
F_1 ( V_2 , V_39 , V_40 , true ) ;
F_2 ( V_2 , V_41 , & V_36 ) ;
V_36 &= ~ V_42 ;
F_3 ( V_2 , V_41 , V_36 ) ;
F_2 ( V_2 , V_43 , & V_36 ) ;
V_36 = V_44 | V_45 |
V_46 | V_47 | V_48 ;
F_3 ( V_2 , V_43 , V_36 ) ;
F_6 ( V_2 , V_49 , V_50 ) ;
F_6 ( V_2 , V_51 , 0x7F ) ;
F_5 ( V_2 , V_52 , & V_38 ) ;
F_23 ( V_2 , V_53 , & V_37 ) ;
V_37 &= ~ V_54 ;
V_37 |= ( V_55 * V_56 ) / 100 ;
F_14 ( V_2 , V_53 , V_37 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , int V_7 , bool V_57 )
{
T_2 V_36 ;
T_3 V_37 ;
if ( V_57 )
F_7 ( V_2 , V_7 , V_58 , V_59 ,
true ) ;
F_7 ( V_2 , V_7 , V_58 , V_60 , false ) ;
F_7 ( V_2 , V_7 , V_61 , V_62 , true ) ;
F_7 ( V_2 , V_7 , V_58 ,
V_63 | V_64 , true ) ;
F_7 ( V_2 , V_7 , V_65 , V_66 , true ) ;
F_7 ( V_2 , V_7 , V_67 , V_68 , false ) ;
F_7 ( V_2 , V_7 , V_69 , V_70 ,
false ) ;
F_9 ( V_2 , V_7 , V_71 ,
V_72 , false ) ;
F_7 ( V_2 , V_7 , V_67 , V_73 , true ) ;
F_25 ( V_2 , V_7 , V_74 , & V_36 ) ;
V_36 |= V_75 ;
V_36 &= ~ V_76 ;
V_36 &= ~ V_77 ;
V_36 |= V_78 ;
F_26 ( V_2 , V_7 , V_74 , V_36 ) ;
F_27 ( V_2 , V_7 , V_79 , & V_37 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_80 ;
V_14 -> V_81 = V_2 -> V_82 ;
for ( V_80 = 0 ; V_80 < V_14 -> V_81 ; V_80 ++ ) {
if ( F_29 ( V_14 , V_80 ) && ( V_2 -> V_83 & ( 1 << V_80 ) ) ) {
V_2 -> V_57 = V_80 ;
F_24 ( V_2 , V_80 , true ) ;
}
}
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_18 = 0 ;
V_2 -> V_28 = F_31 ( V_2 -> V_2 , sizeof( struct V_16 ) ,
V_2 -> V_84 , V_85 ) ;
if ( ! V_2 -> V_28 )
return - V_86 ;
V_18 = F_22 ( V_14 ) ;
if ( V_18 ) {
F_32 ( V_14 -> V_2 , L_3 ) ;
return V_18 ;
}
F_1 ( V_2 , V_87 , V_88 , true ) ;
F_28 ( V_14 ) ;
F_1 ( V_2 , V_87 , V_89 , true ) ;
F_1 ( V_2 , V_90 , V_91 , true ) ;
F_1 ( V_2 , V_39 , V_92 , true ) ;
return 0 ;
}
static enum V_93 F_33 ( struct V_13 * V_14 )
{
return V_94 ;
}
static int F_34 ( struct V_13 * V_14 , int V_3 , int V_95 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_3 V_96 = 0 ;
F_27 ( V_2 , V_3 , 0x100 + ( V_95 << 1 ) , & V_96 ) ;
return V_96 ;
}
static int F_35 ( struct V_13 * V_14 , int V_3 , int V_95 , T_3 V_96 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
F_36 ( V_2 , V_3 , 0x100 + ( V_95 << 1 ) , V_96 ) ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 , int V_7 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
F_24 ( V_2 , V_7 , false ) ;
return 0 ;
}
static void F_38 ( struct V_13 * V_14 , int V_7 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
F_7 ( V_2 , V_7 , V_58 , V_60 , true ) ;
}
static int F_39 ( struct V_13 * V_14 )
{
return V_99 ;
}
static void F_40 ( struct V_13 * V_14 , int V_7 , T_4 * V_100 )
{
int V_80 ;
for ( V_80 = 0 ; V_80 < V_99 ; V_80 ++ ) {
memcpy ( V_100 + V_80 * V_101 , V_102 [ V_80 ] . string ,
V_101 ) ;
}
}
static void F_41 ( struct V_13 * V_14 , int V_7 ,
T_5 * V_100 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_80 ;
T_1 V_6 ;
int V_10 ;
F_13 ( & V_2 -> V_103 ) ;
for ( V_80 = 0 ; V_80 < V_99 ; V_80 ++ ) {
V_6 = V_104 ;
V_6 |= ( ( V_102 [ V_80 ] . V_105 & 0xFF ) << V_106 ) ;
F_42 ( V_2 , V_7 , V_107 , V_6 ) ;
V_10 = 1000 ;
do {
F_43 ( V_2 , V_7 , V_107 ,
& V_6 ) ;
F_11 ( 1 , 10 ) ;
if ( ! ( V_6 & V_104 ) )
break;
} while ( V_10 -- > 0 );
if ( ! V_10 ) {
F_15 ( V_2 -> V_2 , L_4 ) ;
break;
}
F_43 ( V_2 , V_7 , V_108 , & V_6 ) ;
V_2 -> V_109 [ V_80 ] += ( T_5 ) V_6 ;
V_100 [ V_80 ] = V_2 -> V_109 [ V_80 ] ;
}
F_16 ( & V_2 -> V_103 ) ;
}
static void F_44 ( struct V_13 * V_14 , int V_7 , T_2 V_110 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_2 V_6 ;
F_25 ( V_2 , V_7 , V_111 , & V_6 ) ;
V_6 &= ~ ( V_112 | V_113 | V_114 ) ;
switch ( V_110 ) {
case V_115 :
V_6 |= V_114 ;
break;
case V_116 :
V_6 |= ( V_113 | V_114 ) ;
break;
case V_117 :
V_6 |= V_113 ;
break;
case V_118 :
V_6 |= ( V_112 | V_113 ) ;
break;
case V_119 :
V_6 |= V_114 ;
break;
default:
F_32 ( V_14 -> V_2 , L_5 , V_110 ) ;
return;
}
F_26 ( V_2 , V_7 , V_111 , V_6 ) ;
}
static void F_45 ( struct V_13 * V_14 , int V_7 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_2 V_36 ;
F_2 ( V_2 , V_43 , & V_36 ) ;
V_36 |= V_120 ;
F_3 ( V_2 , V_43 , V_36 ) ;
V_36 &= ~ V_120 ;
F_3 ( V_2 , V_43 , V_36 ) ;
}
static int F_46 ( struct V_13 * V_14 , int V_7 , bool V_121 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
if ( V_121 ) {
F_7 ( V_2 , V_7 , V_122 ,
V_123 , true ) ;
F_4 ( V_2 , V_124 , V_125 , true ) ;
F_1 ( V_2 , V_126 , V_127 , true ) ;
} else {
F_1 ( V_2 , V_126 , V_127 , false ) ;
F_4 ( V_2 , V_124 , V_125 , false ) ;
F_7 ( V_2 , V_7 , V_122 ,
V_123 , false ) ;
}
return 0 ;
}
static int F_47 ( struct V_13 * V_14 , int V_7 ,
const struct V_128 * V_129 ,
struct V_130 * V_131 )
{
return 0 ;
}
static void F_48 ( struct V_13 * V_14 , int V_7 ,
const struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_1 V_16 [ 3 ] ;
T_3 V_15 ;
bool V_132 = V_129 -> V_133 & V_134 ;
for ( V_15 = V_129 -> V_135 ; V_15 <= V_129 -> V_136 ; V_15 ++ ) {
if ( F_12 ( V_14 , V_15 , V_16 ) ) {
F_15 ( V_2 -> V_2 , L_6 ) ;
return;
}
V_16 [ 0 ] = V_137 | ( V_15 & V_138 ) ;
if ( V_132 )
V_16 [ 1 ] |= F_49 ( V_7 ) ;
else
V_16 [ 1 ] &= ~ F_49 ( V_7 ) ;
V_16 [ 1 ] &= ~ ( F_49 ( V_2 -> V_57 ) ) ;
V_16 [ 2 ] |= F_49 ( V_7 ) | F_49 ( V_2 -> V_57 ) ;
if ( F_17 ( V_14 , V_15 , V_16 ) ) {
F_15 ( V_2 -> V_2 , L_7 ) ;
return;
}
if ( V_129 -> V_133 & V_139 )
F_36 ( V_2 , V_7 , V_140 , V_15 ) ;
}
}
static int F_50 ( struct V_13 * V_14 , int V_7 ,
const struct V_128 * V_129 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
bool V_132 = V_129 -> V_133 & V_134 ;
T_1 V_16 [ 3 ] ;
T_3 V_15 ;
T_3 V_141 ;
F_27 ( V_2 , V_7 , V_140 , & V_141 ) ;
V_141 = V_141 & 0xFFF ;
for ( V_15 = V_129 -> V_135 ; V_15 <= V_129 -> V_136 ; V_15 ++ ) {
if ( F_12 ( V_14 , V_15 , V_16 ) ) {
F_15 ( V_2 -> V_2 , L_6 ) ;
return - V_12 ;
}
V_16 [ 2 ] &= ~ F_49 ( V_7 ) ;
if ( V_141 == V_15 )
V_141 = 1 ;
if ( V_132 )
V_16 [ 1 ] &= ~ F_49 ( V_7 ) ;
if ( F_17 ( V_14 , V_15 , V_16 ) ) {
F_15 ( V_2 -> V_2 , L_7 ) ;
return - V_12 ;
}
}
F_36 ( V_2 , V_7 , V_140 , V_141 ) ;
return 0 ;
}
static int F_51 ( struct V_13 * V_14 , int V_7 ,
const unsigned char * V_3 , T_3 V_15 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_1 V_142 [ 4 ] ;
T_1 V_6 ;
int V_18 = 0 ;
F_13 ( & V_2 -> V_143 ) ;
V_6 = V_15 << V_144 ;
V_6 |= ( ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_6 ( V_2 , V_145 , V_6 ) ;
V_6 = ( ( V_3 [ 2 ] << 24 ) | ( V_3 [ 3 ] << 16 ) ) ;
V_6 |= ( ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
F_6 ( V_2 , V_146 , V_6 ) ;
F_6 ( V_2 , V_34 , V_147 | V_148 ) ;
V_18 = F_20 ( V_2 , V_148 , 1000 ) ;
if ( V_18 < 0 ) {
F_15 ( V_2 -> V_2 , L_8 ) ;
goto exit;
}
F_18 ( V_14 , V_142 ) ;
V_142 [ 0 ] = V_149 ;
V_142 [ 1 ] |= F_49 ( V_7 ) ;
if ( V_15 )
V_142 [ 1 ] |= V_150 ;
V_142 [ 2 ] = ( V_15 << V_151 ) ;
V_142 [ 2 ] |= ( ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
V_142 [ 3 ] = ( ( V_3 [ 2 ] << 24 ) | ( V_3 [ 3 ] << 16 ) ) ;
V_142 [ 3 ] |= ( ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
F_19 ( V_14 , V_142 ) ;
F_6 ( V_2 , V_34 , V_152 | V_148 ) ;
V_18 = F_20 ( V_2 , V_148 , 1000 ) ;
if ( V_18 < 0 )
F_15 ( V_2 -> V_2 , L_9 ) ;
exit:
F_16 ( & V_2 -> V_143 ) ;
return V_18 ;
}
static int F_52 ( struct V_13 * V_14 , int V_7 ,
const unsigned char * V_3 , T_3 V_15 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_1 V_142 [ 4 ] ;
T_1 V_6 ;
int V_18 = 0 ;
F_13 ( & V_2 -> V_143 ) ;
V_6 = V_15 << V_144 ;
V_6 |= ( ( V_3 [ 0 ] << 8 ) | V_3 [ 1 ] ) ;
F_6 ( V_2 , V_145 , V_6 ) ;
V_6 = ( ( V_3 [ 2 ] << 24 ) | ( V_3 [ 3 ] << 16 ) ) ;
V_6 |= ( ( V_3 [ 4 ] << 8 ) | V_3 [ 5 ] ) ;
F_6 ( V_2 , V_146 , V_6 ) ;
F_6 ( V_2 , V_34 , V_147 | V_148 ) ;
V_18 = F_20 ( V_2 , V_148 , 1000 ) ;
if ( V_18 < 0 ) {
F_15 ( V_2 -> V_2 , L_8 ) ;
goto exit;
}
F_5 ( V_2 , V_30 , & V_142 [ 0 ] ) ;
if ( V_142 [ 0 ] & V_149 ) {
F_5 ( V_2 , V_31 , & V_142 [ 1 ] ) ;
F_5 ( V_2 , V_32 , & V_142 [ 2 ] ) ;
F_5 ( V_2 , V_33 , & V_142 [ 3 ] ) ;
V_142 [ 2 ] &= ~ F_49 ( V_7 ) ;
if ( ( V_142 [ 2 ] & V_153 ) == 0 ) {
V_142 [ 0 ] = 0 ;
V_142 [ 1 ] = 0 ;
V_142 [ 2 ] = 0 ;
V_142 [ 3 ] = 0 ;
}
} else {
V_142 [ 0 ] = 0 ;
V_142 [ 1 ] = 0 ;
V_142 [ 2 ] = 0 ;
V_142 [ 3 ] = 0 ;
}
F_19 ( V_14 , V_142 ) ;
F_6 ( V_2 , V_34 , V_152 | V_148 ) ;
V_18 = F_20 ( V_2 , V_148 , 1000 ) ;
if ( V_18 < 0 )
F_15 ( V_2 -> V_2 , L_9 ) ;
exit:
F_16 ( & V_2 -> V_143 ) ;
return V_18 ;
}
static void F_53 ( struct V_154 * V_155 , T_1 * V_142 )
{
V_155 -> V_156 = ! ! ( V_142 [ 0 ] & V_149 ) ;
V_155 -> V_157 = ! ! ( V_142 [ 0 ] & V_158 ) ;
V_155 -> V_159 = ! ! ( V_142 [ 0 ] & V_160 ) ;
V_155 -> V_161 = ( V_142 [ 0 ] >> V_162 ) &
V_163 ;
V_155 -> V_164 = V_142 [ 0 ] & V_165 ;
V_155 -> V_166 = ! ! ( V_142 [ 1 ] & V_167 ) ;
V_155 -> V_168 = ! ! ( V_142 [ 1 ] & V_150 ) ;
V_155 -> V_169 = V_142 [ 1 ] & V_153 ;
V_155 -> V_170 = ( V_142 [ 2 ] >> V_151 ) & V_171 ;
V_155 -> V_172 [ 0 ] = ( V_142 [ 2 ] >> 8 ) & 0xFF ;
V_155 -> V_172 [ 1 ] = V_142 [ 2 ] & 0xFF ;
V_155 -> V_172 [ 2 ] = ( V_142 [ 3 ] >> 24 ) & 0xFF ;
V_155 -> V_172 [ 3 ] = ( V_142 [ 3 ] >> 16 ) & 0xFF ;
V_155 -> V_172 [ 4 ] = ( V_142 [ 3 ] >> 8 ) & 0xFF ;
V_155 -> V_172 [ 5 ] = V_142 [ 3 ] & 0xFF ;
}
static int F_54 ( struct V_13 * V_14 , int V_7 ,
T_6 * V_173 , void * V_6 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_18 = 0 ;
T_1 V_174 ;
T_1 V_142 [ 4 ] ;
struct V_154 V_155 ;
int V_10 ;
F_13 ( & V_2 -> V_143 ) ;
F_6 ( V_2 , V_34 , V_148 | V_175 ) ;
do {
V_10 = 1000 ;
do {
F_5 ( V_2 , V_34 , & V_174 ) ;
if ( ( V_174 & V_176 ) || ! ( V_174 & V_148 ) )
break;
F_11 ( 1 , 10 ) ;
} while ( V_10 -- > 0 );
if ( ! V_10 ) {
F_15 ( V_2 -> V_2 , L_10 ) ;
V_18 = - V_12 ;
goto exit;
}
F_18 ( V_14 , V_142 ) ;
F_53 ( & V_155 , V_142 ) ;
if ( V_155 . V_169 & F_49 ( V_7 ) ) {
V_18 = V_173 ( V_155 . V_172 , V_155 . V_170 , V_155 . V_156 , V_6 ) ;
if ( V_18 )
goto exit;
}
} while ( V_174 & V_148 );
exit:
F_6 ( V_2 , V_34 , 0 ) ;
F_16 ( & V_2 -> V_143 ) ;
return V_18 ;
}
static int F_55 ( struct V_13 * V_14 , int V_7 ,
const struct V_177 * V_178 ,
struct V_130 * V_131 )
{
return 0 ;
}
static void F_56 ( struct V_13 * V_14 , int V_7 ,
const struct V_177 * V_178 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_1 V_179 [ 4 ] ;
T_1 V_6 ;
int V_105 ;
T_1 V_180 , V_181 ;
V_180 = ( ( V_178 -> V_3 [ 0 ] << 8 ) | V_178 -> V_3 [ 1 ] ) ;
V_181 = ( ( V_178 -> V_3 [ 2 ] << 24 ) | ( V_178 -> V_3 [ 3 ] << 16 ) ) ;
V_181 |= ( ( V_178 -> V_3 [ 4 ] << 8 ) | V_178 -> V_3 [ 5 ] ) ;
F_13 ( & V_2 -> V_143 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_182 ; V_105 ++ ) {
V_6 = ( V_105 << V_183 ) |
V_184 | V_185 ;
F_6 ( V_2 , V_35 , V_6 ) ;
if ( F_21 ( V_2 , V_185 , 1000 ) < 0 ) {
F_15 ( V_2 -> V_2 , L_11 ) ;
goto exit;
}
F_18 ( V_14 , V_179 ) ;
if ( V_179 [ 0 ] & V_149 ) {
if ( ( ( V_179 [ 2 ] >> V_151 ) == ( V_178 -> V_15 ) ) &&
( ( V_179 [ 2 ] & V_186 ) == V_180 ) &&
( V_179 [ 3 ] == V_181 ) ) {
break;
}
} else {
break;
}
}
if ( V_105 == V_2 -> V_182 )
goto exit;
V_179 [ 0 ] = V_149 ;
V_179 [ 1 ] |= F_49 ( V_7 ) ;
if ( V_178 -> V_15 )
V_179 [ 1 ] |= V_150 ;
V_179 [ 2 ] = ( V_178 -> V_15 << V_151 ) ;
V_179 [ 2 ] |= V_180 ;
V_179 [ 3 ] = V_181 ;
F_19 ( V_14 , V_179 ) ;
V_6 = ( V_105 << V_183 ) | V_185 ;
F_6 ( V_2 , V_35 , V_6 ) ;
if ( F_21 ( V_2 , V_185 , 1000 ) < 0 )
F_15 ( V_2 -> V_2 , L_11 ) ;
exit:
F_16 ( & V_2 -> V_143 ) ;
}
static int F_57 ( struct V_13 * V_14 , int V_7 ,
const struct V_177 * V_178 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_1 V_179 [ 4 ] ;
T_1 V_6 ;
int V_105 ;
int V_18 = 0 ;
T_1 V_180 , V_181 ;
V_180 = ( ( V_178 -> V_3 [ 0 ] << 8 ) | V_178 -> V_3 [ 1 ] ) ;
V_181 = ( ( V_178 -> V_3 [ 2 ] << 24 ) | ( V_178 -> V_3 [ 3 ] << 16 ) ) ;
V_181 |= ( ( V_178 -> V_3 [ 4 ] << 8 ) | V_178 -> V_3 [ 5 ] ) ;
F_13 ( & V_2 -> V_143 ) ;
for ( V_105 = 0 ; V_105 < V_2 -> V_182 ; V_105 ++ ) {
V_6 = ( V_105 << V_183 ) |
V_184 | V_185 ;
F_6 ( V_2 , V_35 , V_6 ) ;
V_18 = F_21 ( V_2 , V_185 , 1000 ) ;
if ( V_18 < 0 ) {
F_15 ( V_2 -> V_2 , L_11 ) ;
goto exit;
}
F_18 ( V_14 , V_179 ) ;
if ( V_179 [ 0 ] & V_149 ) {
if ( ( ( V_179 [ 2 ] >> V_151 ) == ( V_178 -> V_15 ) ) &&
( ( V_179 [ 2 ] & V_186 ) == V_180 ) &&
( V_179 [ 3 ] == V_181 ) ) {
break;
}
}
}
if ( V_105 == V_2 -> V_182 ) {
V_18 = - V_187 ;
goto exit;
}
V_179 [ 1 ] &= ~ F_49 ( V_7 ) ;
if ( ( V_179 [ 1 ] & V_153 ) == 0 ) {
V_179 [ 0 ] = 0 ;
V_179 [ 1 ] = 0 ;
V_179 [ 2 ] = 0 ;
V_179 [ 3 ] = 0 ;
}
F_19 ( V_14 , V_179 ) ;
V_6 = ( V_105 << V_183 ) | V_185 ;
F_6 ( V_2 , V_35 , V_6 ) ;
V_18 = F_21 ( V_2 , V_185 , 1000 ) ;
if ( V_18 < 0 )
F_15 ( V_2 -> V_2 , L_11 ) ;
exit:
F_16 ( & V_2 -> V_143 ) ;
return V_18 ;
}
static int F_58 ( struct V_13 * V_14 , int V_7 ,
struct V_188 * V_189 ,
bool V_190 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
if ( V_190 )
F_7 ( V_2 , V_7 , V_191 , V_192 , true ) ;
else
F_7 ( V_2 , V_7 , V_191 , V_193 , true ) ;
F_7 ( V_2 , V_7 , V_191 , V_194 , false ) ;
F_7 ( V_2 , V_189 -> V_195 , V_191 ,
V_194 , true ) ;
F_1 ( V_2 , V_196 , V_197 , false ) ;
return 0 ;
}
static void F_59 ( struct V_13 * V_14 , int V_7 ,
struct V_188 * V_189 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
T_2 V_6 ;
if ( V_189 -> V_190 )
F_7 ( V_2 , V_7 , V_191 , V_192 , false ) ;
else
F_7 ( V_2 , V_7 , V_191 , V_193 , false ) ;
F_25 ( V_2 , V_7 , V_191 , & V_6 ) ;
if ( ! ( V_6 & ( V_192 | V_193 ) ) )
F_7 ( V_2 , V_189 -> V_195 , V_191 ,
V_194 , false ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_80 ;
F_61 ( & V_2 -> V_198 ) ;
F_61 ( & V_2 -> V_103 ) ;
F_61 ( & V_2 -> V_143 ) ;
F_61 ( & V_2 -> V_19 ) ;
V_2 -> V_14 -> V_199 = & V_200 ;
for ( V_80 = 0 ; V_80 < F_62 ( V_201 ) ; V_80 ++ ) {
const struct V_202 * V_203 = & V_201 [ V_80 ] ;
if ( V_2 -> V_204 == V_203 -> V_204 ) {
V_2 -> V_205 = V_203 -> V_206 ;
V_2 -> V_84 = V_203 -> V_84 ;
V_2 -> V_207 = V_203 -> V_207 ;
V_2 -> V_182 = V_203 -> V_182 ;
V_2 -> V_82 = V_203 -> V_82 ;
V_2 -> V_83 = V_203 -> V_83 ;
break;
}
}
if ( ! V_2 -> V_82 )
return - V_208 ;
return 0 ;
}
struct V_1 * F_63 ( struct V_209 * V_210 ,
const struct V_211 * V_199 ,
void * V_17 )
{
struct V_13 * V_14 ;
struct V_1 * V_212 ;
V_14 = F_64 ( V_210 , V_213 ) ;
if ( ! V_14 )
return NULL ;
V_212 = F_65 ( V_210 , sizeof( * V_212 ) , V_85 ) ;
if ( ! V_212 )
return NULL ;
V_14 -> V_17 = V_212 ;
V_212 -> V_2 = V_210 ;
V_212 -> V_14 = V_14 ;
V_212 -> V_17 = V_17 ;
V_212 -> V_199 = V_199 ;
return V_212 ;
}
int F_66 ( struct V_1 * V_2 )
{
T_2 V_36 ;
T_1 V_214 ;
int V_18 ;
V_18 = F_2 ( V_2 , V_41 , & V_36 ) ;
if ( V_18 )
return V_18 ;
V_36 &= ~ V_42 ;
V_18 = F_3 ( V_2 , V_41 , V_36 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_5 ( V_2 , V_215 , & V_214 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_204 = V_214 ;
return 0 ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_216 )
V_2 -> V_204 = V_2 -> V_216 -> V_204 ;
if ( F_66 ( V_2 ) )
return - V_187 ;
V_18 = F_60 ( V_2 ) ;
if ( V_18 )
return V_18 ;
return F_68 ( V_2 -> V_14 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_70 ( V_2 -> V_14 ) ;
}
