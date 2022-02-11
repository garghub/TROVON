static T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( L_1 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
F_2 ( L_2 ) ;
}
static bool F_4 ( struct V_1 * V_2 , int V_6 )
{
if ( F_5 ( V_7 + V_8 [ V_6 ] ) & V_9 )
return true ;
else
return false ;
}
static bool F_6 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_10 , V_11 ;
V_10 = F_5 ( V_12 + V_8 [ V_6 ] ) ;
V_11 = F_5 ( V_12 + V_8 [ V_6 ] ) ;
if ( V_10 != V_11 )
return true ;
else
return false ;
}
static void F_7 ( struct V_1 * V_2 , int V_6 )
{
unsigned V_13 = 100 ;
if ( V_6 >= V_2 -> V_14 . V_15 )
return;
if ( ! ( F_5 ( V_16 + V_8 [ V_6 ] ) & V_17 ) )
return;
while ( F_4 ( V_2 , V_6 ) ) {
if ( V_13 ++ == 100 ) {
V_13 = 0 ;
if ( ! F_6 ( V_2 , V_6 ) )
break;
}
}
while ( ! F_4 ( V_2 , V_6 ) ) {
if ( V_13 ++ == 100 ) {
V_13 = 0 ;
if ( ! F_6 ( V_2 , V_6 ) )
break;
}
}
}
static T_1 F_8 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 >= V_2 -> V_14 . V_15 )
return 0 ;
else
return F_5 ( V_18 + V_8 [ V_6 ] ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ )
F_10 ( V_2 , & V_2 -> V_19 , V_13 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ )
F_12 ( V_2 , & V_2 -> V_19 , V_13 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_20 , T_2 V_21 , bool V_22 )
{
struct V_23 * V_23 = V_2 -> V_14 . V_24 [ V_20 ] ;
F_14 ( V_25 + V_23 -> V_26 , V_22 ?
V_27 : 0 ) ;
F_14 ( V_28 + V_23 -> V_26 ,
F_15 ( V_21 ) ) ;
F_14 ( V_29 + V_23 -> V_26 ,
( T_1 ) V_21 ) ;
F_5 ( V_29 + V_23 -> V_26 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_6 ,
T_1 * V_30 , T_1 * V_31 )
{
if ( ( V_6 < 0 ) || ( V_6 >= V_2 -> V_14 . V_15 ) )
return - V_32 ;
* V_30 = F_5 ( V_33 + V_8 [ V_6 ] ) ;
* V_31 = F_5 ( V_12 + V_8 [ V_6 ] ) ;
return 0 ;
}
static bool F_17 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
bool V_36 = false ;
switch ( V_35 ) {
case V_37 :
if ( F_5 ( V_38 ) & V_39 )
V_36 = true ;
break;
case V_40 :
if ( F_5 ( V_41 ) & V_39 )
V_36 = true ;
break;
case V_42 :
if ( F_5 ( V_43 ) & V_39 )
V_36 = true ;
break;
case V_44 :
if ( F_5 ( V_45 ) & V_39 )
V_36 = true ;
break;
case V_46 :
if ( F_5 ( V_47 ) & V_39 )
V_36 = true ;
break;
case V_48 :
if ( F_5 ( V_49 ) & V_39 )
V_36 = true ;
break;
default:
break;
}
return V_36 ;
}
static void F_18 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
T_1 V_50 ;
bool V_36 = F_17 ( V_2 , V_35 ) ;
switch ( V_35 ) {
case V_37 :
V_50 = F_5 ( V_51 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_51 , V_50 ) ;
break;
case V_40 :
V_50 = F_5 ( V_53 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_53 , V_50 ) ;
break;
case V_42 :
V_50 = F_5 ( V_54 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_54 , V_50 ) ;
break;
case V_44 :
V_50 = F_5 ( V_55 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_55 , V_50 ) ;
break;
case V_46 :
V_50 = F_5 ( V_56 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_56 , V_50 ) ;
break;
case V_48 :
V_50 = F_5 ( V_57 ) ;
if ( V_36 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_14 ( V_57 , V_50 ) ;
break;
default:
break;
}
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = V_2 -> V_60 ;
struct V_61 * V_62 ;
T_1 V_50 = F_20 ( 0x9c4 ) |
F_21 ( 0xfa ) | V_63 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_64 * V_64 = F_23 ( V_62 ) ;
switch ( V_64 -> V_35 . V_35 ) {
case V_37 :
F_14 ( V_65 , V_50 ) ;
break;
case V_40 :
F_14 ( V_66 , V_50 ) ;
break;
case V_42 :
F_14 ( V_67 , V_50 ) ;
break;
case V_44 :
F_14 ( V_68 , V_50 ) ;
break;
case V_46 :
F_14 ( V_69 , V_50 ) ;
break;
case V_48 :
F_14 ( V_70 , V_50 ) ;
break;
default:
break;
}
if ( V_62 -> V_71 == V_72 ||
V_62 -> V_71 == V_73 ) {
T_1 V_74 , V_75 ;
switch ( V_64 -> V_35 . V_35 ) {
case V_37 :
V_74 = V_51 ;
break;
case V_40 :
V_74 = V_53 ;
break;
case V_42 :
V_74 = V_54 ;
break;
case V_44 :
V_74 = V_55 ;
break;
case V_46 :
V_74 = V_56 ;
break;
case V_48 :
V_74 = V_57 ;
break;
default:
continue;
}
V_75 = F_5 ( V_74 ) ;
V_75 &= ~ V_76 ;
F_14 ( V_74 , V_75 ) ;
continue;
}
F_18 ( V_2 , V_64 -> V_35 . V_35 ) ;
F_10 ( V_2 , & V_2 -> V_77 , V_64 -> V_35 . V_35 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = V_2 -> V_60 ;
struct V_61 * V_62 ;
F_22 (connector, &dev->mode_config.connector_list, head) {
struct V_64 * V_64 = F_23 ( V_62 ) ;
switch ( V_64 -> V_35 . V_35 ) {
case V_37 :
F_14 ( V_65 , 0 ) ;
break;
case V_40 :
F_14 ( V_66 , 0 ) ;
break;
case V_42 :
F_14 ( V_67 , 0 ) ;
break;
case V_44 :
F_14 ( V_68 , 0 ) ;
break;
case V_46 :
F_14 ( V_69 , 0 ) ;
break;
case V_48 :
F_14 ( V_70 , 0 ) ;
break;
default:
break;
}
F_12 ( V_2 , & V_2 -> V_77 , V_64 -> V_35 . V_35 ) ;
}
}
static T_1 F_25 ( struct V_1 * V_2 )
{
return V_78 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
F_2 ( L_3 ) ;
return true ;
}
static T_1 F_27 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 >= V_2 -> V_14 . V_15 )
return 0 ;
else
return F_5 ( V_18 + V_8 [ V_6 ] ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
T_1 V_81 , V_50 , V_82 ;
int V_13 , V_83 ;
V_80 -> V_84 = F_5 ( V_85 ) ;
V_80 -> V_86 = F_5 ( V_87 ) ;
F_14 ( V_85 , 0 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_81 = F_5 ( V_16 + V_8 [ V_13 ] ) & V_17 ;
if ( V_81 ) {
V_80 -> V_81 [ V_13 ] = true ;
V_50 = F_5 ( V_88 + V_8 [ V_13 ] ) ;
if ( ! ( V_50 & V_89 ) ) {
F_7 ( V_2 , V_13 ) ;
F_14 ( V_90 + V_8 [ V_13 ] , 1 ) ;
V_50 |= V_89 ;
F_14 ( V_88 + V_8 [ V_13 ] , V_50 ) ;
F_14 ( V_90 + V_8 [ V_13 ] , 0 ) ;
}
V_82 = F_27 ( V_2 , V_13 ) ;
for ( V_83 = 0 ; V_83 < V_2 -> V_91 ; V_83 ++ ) {
if ( F_27 ( V_2 , V_13 ) != V_82 )
break;
F_29 ( 1 ) ;
}
F_14 ( V_90 + V_8 [ V_13 ] , 1 ) ;
V_50 = F_5 ( V_16 + V_8 [ V_13 ] ) ;
V_50 &= ~ V_17 ;
F_14 ( V_16 + V_8 [ V_13 ] , V_50 ) ;
F_14 ( V_90 + V_8 [ V_13 ] , 0 ) ;
V_80 -> V_81 [ V_13 ] = false ;
} else {
V_80 -> V_81 [ V_13 ] = false ;
}
}
}
static void F_30 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
T_1 V_50 ;
int V_13 , V_83 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
F_14 ( V_28 + V_8 [ V_13 ] ,
F_15 ( V_2 -> V_92 . V_93 ) ) ;
F_14 ( V_94 + V_8 [ V_13 ] ,
F_15 ( V_2 -> V_92 . V_93 ) ) ;
F_14 ( V_29 + V_8 [ V_13 ] ,
( T_1 ) V_2 -> V_92 . V_93 ) ;
F_14 ( V_95 + V_8 [ V_13 ] ,
( T_1 ) V_2 -> V_92 . V_93 ) ;
}
F_14 ( V_96 , F_15 ( V_2 -> V_92 . V_93 ) ) ;
F_14 ( V_97 , ( T_1 ) V_2 -> V_92 . V_93 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_80 -> V_81 [ V_13 ] ) {
V_50 = F_5 ( V_98 + V_8 [ V_13 ] ) ;
if ( ( V_50 & 0x7 ) != 3 ) {
V_50 &= ~ 0x7 ;
V_50 |= 0x3 ;
F_14 ( V_98 + V_8 [ V_13 ] , V_50 ) ;
}
V_50 = F_5 ( V_99 + V_8 [ V_13 ] ) ;
if ( V_50 & V_100 ) {
V_50 &= ~ V_100 ;
F_14 ( V_99 + V_8 [ V_13 ] , V_50 ) ;
}
V_50 = F_5 ( V_101 + V_8 [ V_13 ] ) ;
if ( V_50 & 1 ) {
V_50 &= ~ 1 ;
F_14 ( V_101 + V_8 [ V_13 ] , V_50 ) ;
}
for ( V_83 = 0 ; V_83 < V_2 -> V_91 ; V_83 ++ ) {
V_50 = F_5 ( V_99 + V_8 [ V_13 ] ) ;
if ( ( V_50 & V_102 ) == 0 )
break;
F_29 ( 1 ) ;
}
}
}
F_14 ( V_87 , V_80 -> V_86 ) ;
F_31 ( 1 ) ;
F_14 ( V_85 , V_80 -> V_84 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
bool V_103 )
{
if ( ! V_103 )
F_14 ( V_104 ,
F_5 ( V_104 ) & V_105 ) ;
}
static void F_33 ( struct V_106 * V_107 )
{
struct V_58 * V_59 = V_107 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_109 * V_109 = F_34 ( V_107 ) ;
struct V_61 * V_62 = F_35 ( V_107 ) ;
struct V_23 * V_23 = F_36 ( V_107 -> V_6 ) ;
int V_110 = 0 ;
T_1 V_50 = 0 ;
enum V_111 V_112 = V_113 ;
if ( V_62 ) {
struct V_64 * V_64 = F_23 ( V_62 ) ;
V_110 = F_37 ( V_62 ) ;
V_112 = V_64 -> V_112 ;
}
if ( V_109 -> V_114 & V_115 )
return;
if ( V_110 == 0 )
return;
switch ( V_110 ) {
case 6 :
if ( V_112 == V_116 )
V_50 |= ( V_117 | V_118 |
V_119 ) ;
else
V_50 |= V_120 ;
break;
case 8 :
if ( V_112 == V_116 )
V_50 |= ( V_117 | V_118 |
V_121 |
V_119 | V_122 ) ;
else
V_50 |= ( V_120 | V_123 ) ;
break;
case 10 :
default:
break;
}
F_14 ( V_124 + V_23 -> V_26 , V_50 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
T_1 V_50 = F_5 ( V_125 ) ;
switch ( ( V_50 & V_126 ) >> V_127 ) {
case 0 :
default:
return 1 ;
case 1 :
return 2 ;
case 2 :
return 4 ;
case 3 :
return 8 ;
case 4 :
return 3 ;
case 5 :
return 6 ;
case 6 :
return 10 ;
case 7 :
return 12 ;
case 8 :
return 16 ;
}
}
static T_1 F_39 ( struct V_128 * V_129 )
{
T_3 V_130 ;
T_3 V_131 , V_132 , V_133 ;
T_3 V_134 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_131 . V_135 = F_40 ( V_129 -> V_131 ) ;
V_131 . V_135 = F_41 ( V_131 , V_134 ) ;
V_132 . V_135 = F_40 ( V_129 -> V_132 * 4 ) ;
V_134 . V_135 = F_40 ( 10 ) ;
V_130 . V_135 = F_40 ( 7 ) ;
V_130 . V_135 = F_41 ( V_130 , V_134 ) ;
V_133 . V_135 = F_42 ( V_132 , V_131 ) ;
V_133 . V_135 = F_42 ( V_133 , V_130 ) ;
return F_43 ( V_133 ) ;
}
static T_1 F_44 ( struct V_128 * V_129 )
{
T_3 V_136 ;
T_3 V_131 , V_132 , V_133 ;
T_3 V_134 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_131 . V_135 = F_40 ( V_129 -> V_131 ) ;
V_131 . V_135 = F_41 ( V_131 , V_134 ) ;
V_132 . V_135 = F_40 ( V_129 -> V_132 * 4 ) ;
V_134 . V_135 = F_40 ( 10 ) ;
V_136 . V_135 = F_40 ( 3 ) ;
V_136 . V_135 = F_41 ( V_136 , V_134 ) ;
V_133 . V_135 = F_42 ( V_132 , V_131 ) ;
V_133 . V_135 = F_42 ( V_133 , V_136 ) ;
return F_43 ( V_133 ) ;
}
static T_1 F_45 ( struct V_128 * V_129 )
{
T_3 V_137 ;
T_3 V_138 , V_133 ;
T_3 V_134 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_138 . V_135 = F_40 ( V_129 -> V_138 ) ;
V_138 . V_135 = F_41 ( V_138 , V_134 ) ;
V_134 . V_135 = F_40 ( 10 ) ;
V_137 . V_135 = F_40 ( 8 ) ;
V_137 . V_135 = F_41 ( V_137 , V_134 ) ;
V_134 . V_135 = F_40 ( 32 ) ;
V_133 . V_135 = F_42 ( V_134 , V_138 ) ;
V_133 . V_135 = F_42 ( V_133 , V_137 ) ;
return F_43 ( V_133 ) ;
}
static T_1 F_46 ( struct V_128 * V_129 )
{
T_3 V_139 ;
T_3 V_140 , V_133 ;
T_3 V_134 , V_141 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_140 . V_135 = F_40 ( V_129 -> V_140 ) ;
V_140 . V_135 = F_41 ( V_140 , V_134 ) ;
V_134 . V_135 = F_40 ( 32 ) ;
V_141 . V_135 = F_42 ( V_134 , V_140 ) ;
V_134 . V_135 = F_40 ( 10 ) ;
V_139 . V_135 = F_40 ( 8 ) ;
V_139 . V_135 = F_41 ( V_139 , V_134 ) ;
V_133 . V_135 = F_42 ( V_141 , V_139 ) ;
return F_43 ( V_133 ) ;
}
static T_1 F_47 ( struct V_128 * V_129 )
{
T_1 V_142 = F_39 ( V_129 ) ;
T_1 V_143 = F_45 ( V_129 ) ;
T_1 V_144 = F_46 ( V_129 ) ;
return F_48 ( V_142 , F_48 ( V_143 , V_144 ) ) ;
}
static T_1 F_49 ( struct V_128 * V_129 )
{
T_3 V_145 ;
T_3 V_146 ;
T_3 V_147 ;
T_3 V_133 ;
T_3 V_134 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_146 . V_135 = F_40 ( V_129 -> V_148 + V_129 -> V_149 ) ;
V_146 . V_135 = F_41 ( V_146 , V_134 ) ;
V_145 . V_135 = F_40 ( V_129 -> V_150 ) ;
V_147 . V_135 = F_40 ( V_129 -> V_147 ) ;
V_133 . V_135 = F_42 ( V_147 , V_145 ) ;
V_133 . V_135 = F_42 ( V_133 , V_129 -> V_151 ) ;
V_133 . V_135 = F_41 ( V_133 , V_146 ) ;
return F_43 ( V_133 ) ;
}
static T_1 F_50 ( struct V_128 * V_129 )
{
T_1 V_152 = 2000 ;
T_1 V_153 = F_47 ( V_129 ) ;
T_1 V_154 = ( 512 * 8 * 1000 ) / V_153 ;
T_1 V_155 = ( 128 * 4 * 1000 ) / V_153 ;
T_1 V_156 = 40000000 / V_129 -> V_140 ;
T_1 V_157 = ( ( V_129 -> V_158 + 1 ) * V_154 ) +
( V_129 -> V_158 * V_155 ) ;
T_1 V_159 = V_152 + V_157 + V_156 ;
T_1 V_160 , V_161 , V_162 ;
T_1 V_50 , V_163 = 12288 ;
T_3 V_134 , V_141 , V_164 ;
if ( V_129 -> V_158 == 0 )
return 0 ;
V_134 . V_135 = F_40 ( 2 ) ;
V_141 . V_135 = F_40 ( 1 ) ;
if ( ( V_129 -> V_151 . V_135 > V_134 . V_135 ) ||
( ( V_129 -> V_151 . V_135 > V_141 . V_135 ) && ( V_129 -> V_165 >= 3 ) ) ||
( V_129 -> V_165 >= 5 ) ||
( ( V_129 -> V_151 . V_135 >= V_134 . V_135 ) && V_129 -> V_166 ) )
V_160 = 4 ;
else
V_160 = 2 ;
V_134 . V_135 = F_40 ( V_153 ) ;
V_141 . V_135 = F_40 ( V_129 -> V_158 ) ;
V_134 . V_135 = F_41 ( V_134 , V_141 ) ;
V_141 . V_135 = F_40 ( V_152 + 512 ) ;
V_164 . V_135 = F_40 ( V_129 -> V_140 ) ;
V_141 . V_135 = F_41 ( V_141 , V_164 ) ;
V_164 . V_135 = F_40 ( V_163 ) ;
V_141 . V_135 = F_41 ( V_164 , V_141 ) ;
V_50 = F_48 ( F_43 ( V_134 ) , F_43 ( V_141 ) ) ;
V_141 . V_135 = F_40 ( 1000 ) ;
V_164 . V_135 = F_40 ( V_129 -> V_140 ) ;
V_141 . V_135 = F_41 ( V_164 , V_141 ) ;
V_164 . V_135 = F_40 ( V_129 -> V_150 ) ;
V_141 . V_135 = F_42 ( V_141 , V_164 ) ;
V_161 = F_48 ( V_50 , F_43 ( V_141 ) ) ;
V_134 . V_135 = F_40 ( V_160 * V_129 -> V_147 * V_129 -> V_150 ) ;
V_141 . V_135 = F_40 ( 1000 ) ;
V_164 . V_135 = F_40 ( V_161 ) ;
V_141 . V_135 = F_41 ( V_164 , V_141 ) ;
V_134 . V_135 = F_41 ( V_134 , V_141 ) ;
V_162 = F_43 ( V_134 ) ;
if ( V_162 < V_129 -> V_148 )
return V_159 ;
else
return V_159 + ( V_162 - V_129 -> V_148 ) ;
}
static bool F_51 ( struct V_128 * V_129 )
{
if ( F_49 ( V_129 ) <=
( F_44 ( V_129 ) / V_129 -> V_158 ) )
return true ;
else
return false ;
}
static bool F_52 ( struct V_128 * V_129 )
{
if ( F_49 ( V_129 ) <=
( F_47 ( V_129 ) / V_129 -> V_158 ) )
return true ;
else
return false ;
}
static bool F_53 ( struct V_128 * V_129 )
{
T_1 V_167 = V_129 -> V_168 / V_129 -> V_147 ;
T_1 V_146 = V_129 -> V_148 + V_129 -> V_149 ;
T_1 V_169 ;
T_1 V_170 ;
T_3 V_134 ;
V_134 . V_135 = F_40 ( 1 ) ;
if ( V_129 -> V_151 . V_135 > V_134 . V_135 )
V_169 = 1 ;
else {
if ( V_167 <= ( V_129 -> V_165 + 1 ) )
V_169 = 1 ;
else
V_169 = 2 ;
}
V_170 = ( V_169 * V_146 + V_129 -> V_149 ) ;
if ( F_50 ( V_129 ) <= V_170 )
return true ;
else
return false ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
T_1 V_168 , T_1 V_158 )
{
struct V_171 * V_172 = & V_23 -> V_173 . V_172 ;
struct V_128 V_174 , V_175 ;
T_1 V_132 ;
T_1 V_176 ;
T_1 V_146 = 0 ;
T_1 V_177 = 0 , V_178 = 0 ;
T_1 V_179 = 0 , V_180 = 0 ;
T_1 V_181 = V_182 ;
T_1 V_183 = V_182 ;
T_1 V_50 , V_184 ;
T_3 V_134 , V_141 , V_164 ;
if ( V_23 -> V_173 . V_185 && V_158 && V_172 ) {
V_176 = 1000000 / ( T_1 ) V_172 -> clock ;
V_146 = F_48 ( ( T_1 ) V_172 -> V_186 * V_176 , ( T_1 ) 65535 ) ;
V_181 = 0 ;
V_183 = 0 ;
V_132 = F_38 ( V_2 ) ;
if ( V_2 -> V_187 . V_188 ) {
V_175 . V_131 =
F_55 ( V_2 , false ) * 10 ;
V_175 . V_138 =
F_56 ( V_2 , false ) * 10 ;
} else {
V_175 . V_131 = V_2 -> V_187 . V_189 * 10 ;
V_175 . V_138 = V_2 -> V_187 . V_190 * 10 ;
}
V_175 . V_140 = V_172 -> clock ;
V_175 . V_147 = V_172 -> V_191 ;
V_175 . V_148 = V_172 -> V_191 * V_176 ;
V_175 . V_149 = V_146 - V_175 . V_148 ;
V_175 . V_166 = false ;
if ( V_172 -> V_192 & V_193 )
V_175 . V_166 = true ;
V_175 . V_151 = V_23 -> V_151 ;
V_175 . V_165 = 1 ;
if ( V_23 -> V_194 != V_195 )
V_175 . V_165 = 2 ;
V_175 . V_150 = 4 ;
V_175 . V_168 = V_168 ;
V_175 . V_132 = V_132 ;
V_175 . V_158 = V_158 ;
if ( V_2 -> V_187 . V_188 ) {
V_174 . V_131 =
F_55 ( V_2 , true ) * 10 ;
V_174 . V_138 =
F_56 ( V_2 , true ) * 10 ;
} else {
V_174 . V_131 = V_2 -> V_187 . V_189 * 10 ;
V_174 . V_138 = V_2 -> V_187 . V_190 * 10 ;
}
V_174 . V_140 = V_172 -> clock ;
V_174 . V_147 = V_172 -> V_191 ;
V_174 . V_148 = V_172 -> V_191 * V_176 ;
V_174 . V_149 = V_146 - V_174 . V_148 ;
V_174 . V_166 = false ;
if ( V_172 -> V_192 & V_193 )
V_174 . V_166 = true ;
V_174 . V_151 = V_23 -> V_151 ;
V_174 . V_165 = 1 ;
if ( V_23 -> V_194 != V_195 )
V_174 . V_165 = 2 ;
V_174 . V_150 = 4 ;
V_174 . V_168 = V_168 ;
V_174 . V_132 = V_132 ;
V_174 . V_158 = V_158 ;
V_177 = F_48 ( F_50 ( & V_175 ) , ( T_1 ) 65535 ) ;
V_178 = F_48 ( F_50 ( & V_174 ) , ( T_1 ) 65535 ) ;
if ( ! F_51 ( & V_175 ) ||
! F_52 ( & V_175 ) ||
! F_53 ( & V_175 ) ||
( V_2 -> V_14 . V_196 == 2 ) ) {
F_57 ( L_4 ) ;
V_181 |= V_197 ;
V_183 |= V_197 ;
}
if ( ! F_51 ( & V_174 ) ||
! F_52 ( & V_174 ) ||
! F_53 ( & V_174 ) ||
( V_2 -> V_14 . V_196 == 2 ) ) {
F_57 ( L_4 ) ;
V_181 |= V_197 ;
V_183 |= V_197 ;
}
V_134 . V_135 = F_40 ( 1000 ) ;
V_141 . V_135 = F_40 ( V_172 -> clock ) ;
V_141 . V_135 = F_41 ( V_141 , V_134 ) ;
V_164 . V_135 = F_40 ( V_177 ) ;
V_164 . V_135 = F_42 ( V_164 , V_141 ) ;
V_164 . V_135 = F_42 ( V_164 , V_23 -> V_198 ) ;
V_164 . V_135 = F_41 ( V_164 , V_134 ) ;
V_134 . V_135 = F_40 ( 16 ) ;
V_164 . V_135 = F_41 ( V_164 , V_134 ) ;
V_179 = F_43 ( V_164 ) ;
V_181 |= V_179 & V_199 ;
V_134 . V_135 = F_40 ( 1000 ) ;
V_141 . V_135 = F_40 ( V_172 -> clock ) ;
V_141 . V_135 = F_41 ( V_141 , V_134 ) ;
V_164 . V_135 = F_40 ( V_178 ) ;
V_164 . V_135 = F_42 ( V_164 , V_141 ) ;
V_164 . V_135 = F_42 ( V_164 , V_23 -> V_198 ) ;
V_164 . V_135 = F_41 ( V_164 , V_134 ) ;
V_134 . V_135 = F_40 ( 16 ) ;
V_164 . V_135 = F_41 ( V_164 , V_134 ) ;
V_180 = F_43 ( V_164 ) ;
V_183 |= V_180 & V_199 ;
}
V_184 = F_5 ( V_200 + V_23 -> V_26 ) ;
V_50 = V_184 ;
V_50 &= ~ F_58 ( 3 ) ;
V_50 |= F_58 ( 1 ) ;
F_14 ( V_200 + V_23 -> V_26 , V_50 ) ;
F_14 ( V_201 + V_23 -> V_26 ,
( F_59 ( V_177 ) |
F_60 ( V_146 ) ) ) ;
V_50 = F_5 ( V_200 + V_23 -> V_26 ) ;
V_50 &= ~ F_58 ( 3 ) ;
V_50 |= F_58 ( 2 ) ;
F_14 ( V_200 + V_23 -> V_26 , V_50 ) ;
F_14 ( V_201 + V_23 -> V_26 ,
( F_59 ( V_178 ) |
F_60 ( V_146 ) ) ) ;
F_14 ( V_200 + V_23 -> V_26 , V_184 ) ;
F_14 ( V_202 + V_23 -> V_26 , V_181 ) ;
F_14 ( V_203 + V_23 -> V_26 , V_183 ) ;
V_23 -> V_146 = V_146 ;
V_23 -> V_175 = V_177 ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
struct V_171 * V_172 ,
struct V_171 * V_204 )
{
T_1 V_50 , V_205 , V_13 ;
T_1 V_206 = V_23 -> V_20 * 0x8 ;
if ( V_23 -> V_173 . V_185 && V_172 ) {
if ( V_204 ) {
V_50 = 0 ;
V_205 = 1 ;
} else {
V_50 = 2 ;
V_205 = 2 ;
}
} else {
V_50 = 0 ;
V_205 = 0 ;
}
F_14 ( V_207 + V_23 -> V_26 ,
F_62 ( V_50 ) ) ;
F_14 ( V_208 + V_206 ,
F_63 ( V_205 ) ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_91 ; V_13 ++ ) {
if ( F_5 ( V_208 + V_206 ) &
V_209 )
break;
F_29 ( 1 ) ;
}
if ( V_23 -> V_173 . V_185 && V_172 ) {
switch ( V_50 ) {
case 0 :
default:
return 4096 * 2 ;
case 2 :
return 8192 * 2 ;
}
}
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_171 * V_210 = NULL ;
struct V_171 * V_211 = NULL ;
T_1 V_158 = 0 , V_168 ;
int V_13 ;
if ( ! V_2 -> V_14 . V_212 )
return;
F_65 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_2 -> V_14 . V_24 [ V_13 ] -> V_173 . V_185 )
V_158 ++ ;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 += 2 ) {
V_210 = & V_2 -> V_14 . V_24 [ V_13 ] -> V_173 . V_172 ;
V_211 = & V_2 -> V_14 . V_24 [ V_13 + 1 ] -> V_173 . V_172 ;
V_168 = F_61 ( V_2 , V_2 -> V_14 . V_24 [ V_13 ] , V_210 , V_211 ) ;
F_54 ( V_2 , V_2 -> V_14 . V_24 [ V_13 ] , V_168 , V_158 ) ;
V_168 = F_61 ( V_2 , V_2 -> V_14 . V_24 [ V_13 + 1 ] , V_211 , V_210 ) ;
F_54 ( V_2 , V_2 -> V_14 . V_24 [ V_13 + 1 ] , V_168 , V_158 ) ;
}
}
static void F_66 ( struct V_1 * V_2 ,
struct V_213 * V_214 ,
bool V_215 )
{
F_2 ( L_5 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
}
static void F_69 ( struct V_106 * V_107 ,
struct V_171 * V_172 )
{
F_2 ( L_6 ) ;
}
static void F_70 ( struct V_106 * V_107 , bool V_215 )
{
struct V_58 * V_59 = V_107 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_109 * V_109 = F_34 ( V_107 ) ;
struct V_216 * V_217 = V_109 -> V_218 ;
if ( ! V_217 || ! V_217 -> V_219 )
return;
if ( V_215 && V_217 -> V_219 -> V_185 )
return;
if ( ! V_215 && ! V_217 -> V_219 -> V_185 )
return;
if ( ! V_215 && V_217 -> V_219 -> V_214 ) {
F_66 ( V_2 , V_217 -> V_219 -> V_214 , false ) ;
V_217 -> V_219 -> V_214 = NULL ;
}
V_217 -> V_219 -> V_185 = V_215 ;
F_71 ( L_7 ,
V_215 ? L_8 : L_9 , V_217 -> V_219 -> V_220 , V_109 -> V_221 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_13 , V_83 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_222 ; V_13 ++ )
V_2 -> V_14 . V_219 [ V_13 ] = NULL ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_222 ; V_13 ++ ) {
V_2 -> V_14 . V_219 [ V_13 ] = F_73 ( sizeof( struct V_223 ) , V_224 ) ;
if ( V_2 -> V_14 . V_219 [ V_13 ] ) {
V_2 -> V_14 . V_219 [ V_13 ] -> V_220 = V_225 [ V_13 ] ;
V_2 -> V_14 . V_219 [ V_13 ] -> V_226 = V_13 ;
} else {
for ( V_83 = 0 ; V_83 < V_13 ; V_83 ++ ) {
F_74 ( V_2 -> V_14 . V_219 [ V_83 ] ) ;
V_2 -> V_14 . V_219 [ V_83 ] = NULL ;
}
F_75 ( L_10 ) ;
return - V_227 ;
}
}
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_222 ; V_13 ++ ) {
F_74 ( V_2 -> V_14 . V_219 [ V_13 ] ) ;
V_2 -> V_14 . V_219 [ V_13 ] = NULL ;
}
}
static void F_77 ( struct V_228 * V_6 , bool V_215 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
T_1 V_229 ;
V_229 = F_5 ( V_230 [ V_23 -> V_20 ] ) & ~ 1 ;
F_14 ( V_230 [ V_23 -> V_20 ] , V_229 | ( V_215 ? 1 : 0 ) ) ;
}
static void F_78 ( struct V_228 * V_6 , bool V_215 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
F_14 ( V_231 + V_23 -> V_26 , V_215 ? 1 : 0 ) ;
}
static int F_79 ( struct V_228 * V_6 ,
struct V_232 * V_233 ,
int V_234 , int V_235 , int V_236 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_237 * V_238 ;
struct V_232 * V_239 ;
struct V_240 * V_241 ;
struct V_242 * V_243 ;
T_4 V_244 , V_245 ;
T_5 V_246 , V_247 , V_248 ;
T_1 V_249 = F_80 ( V_250 ) ;
T_1 V_251 , V_252 ;
int V_253 ;
bool V_254 = false ;
if ( ! V_236 && ! V_6 -> V_255 -> V_233 ) {
F_57 ( L_11 ) ;
return 0 ;
}
if ( V_236 ) {
V_238 = F_81 ( V_233 ) ;
V_239 = V_233 ;
} else {
V_238 = F_81 ( V_6 -> V_255 -> V_233 ) ;
V_239 = V_6 -> V_255 -> V_233 ;
}
V_241 = V_238 -> V_241 ;
V_243 = F_82 ( V_241 ) ;
V_253 = F_83 ( V_243 , false ) ;
if ( F_84 ( V_253 != 0 ) )
return V_253 ;
if ( V_236 ) {
V_244 = F_85 ( V_243 ) ;
} else {
V_253 = F_86 ( V_243 , V_256 , & V_244 ) ;
if ( F_84 ( V_253 != 0 ) ) {
F_87 ( V_243 ) ;
return - V_32 ;
}
}
F_88 ( V_243 , & V_245 ) ;
F_87 ( V_243 ) ;
switch ( V_239 -> V_257 ) {
case V_258 :
V_246 = ( F_89 ( V_259 ) |
F_90 ( V_260 ) ) ;
break;
case V_261 :
case V_262 :
V_246 = ( F_89 ( V_263 ) |
F_90 ( V_264 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_265 ) ;
#endif
break;
case V_266 :
case V_267 :
V_246 = ( F_89 ( V_263 ) |
F_90 ( V_268 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_265 ) ;
#endif
break;
case V_269 :
case V_270 :
V_246 = ( F_89 ( V_263 ) |
F_90 ( V_271 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_265 ) ;
#endif
break;
case V_272 :
V_246 = ( F_89 ( V_263 ) |
F_90 ( V_273 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_265 ) ;
#endif
break;
case V_274 :
case V_275 :
V_246 = ( F_89 ( V_276 ) |
F_90 ( V_277 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_278 ) ;
#endif
break;
case V_279 :
case V_280 :
V_246 = ( F_89 ( V_276 ) |
F_90 ( V_281 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_278 ) ;
#endif
V_254 = true ;
break;
case V_282 :
case V_283 :
V_246 = ( F_89 ( V_276 ) |
F_90 ( V_284 ) ) ;
#ifdef F_91
V_249 = F_80 ( V_278 ) ;
#endif
V_254 = true ;
break;
default:
F_75 ( L_12 ,
F_92 ( V_239 -> V_257 ) ) ;
return - V_32 ;
}
if ( F_93 ( V_245 , V_285 ) == V_286 ) {
unsigned V_287 , V_288 , V_289 , V_290 , V_291 ;
V_287 = F_93 ( V_245 , V_292 ) ;
V_288 = F_93 ( V_245 , V_293 ) ;
V_289 = F_93 ( V_245 , V_294 ) ;
V_290 = F_93 ( V_245 , V_295 ) ;
V_291 = F_93 ( V_245 , V_296 ) ;
V_246 |= F_94 ( V_291 ) ;
V_246 |= F_95 ( V_297 ) ;
V_246 |= F_96 ( V_290 ) ;
V_246 |= F_97 ( V_287 ) ;
V_246 |= F_98 ( V_288 ) ;
V_246 |= F_99 ( V_289 ) ;
} else if ( F_93 ( V_245 , V_285 ) == V_298 ) {
V_246 |= F_95 ( V_299 ) ;
}
V_248 = F_93 ( V_245 , V_300 ) ;
V_246 |= F_100 ( V_248 ) ;
F_77 ( V_6 , false ) ;
F_14 ( V_25 + V_23 -> V_26 , 0 ) ;
F_14 ( V_28 + V_23 -> V_26 ,
F_15 ( V_244 ) ) ;
F_14 ( V_94 + V_23 -> V_26 ,
F_15 ( V_244 ) ) ;
F_14 ( V_29 + V_23 -> V_26 ,
( T_1 ) V_244 & V_301 ) ;
F_14 ( V_95 + V_23 -> V_26 ,
( T_1 ) V_244 & V_301 ) ;
F_14 ( V_302 + V_23 -> V_26 , V_246 ) ;
F_14 ( V_303 + V_23 -> V_26 , V_249 ) ;
F_101 ( V_304 + V_23 -> V_26 ,
( V_254 ? V_305 : 0 ) ,
~ V_305 ) ;
if ( V_254 )
F_57 ( L_13 ) ;
F_14 ( V_306 + V_23 -> V_26 , 0 ) ;
F_14 ( V_307 + V_23 -> V_26 , 0 ) ;
F_14 ( V_308 + V_23 -> V_26 , 0 ) ;
F_14 ( V_309 + V_23 -> V_26 , 0 ) ;
F_14 ( V_310 + V_23 -> V_26 , V_239 -> V_311 ) ;
F_14 ( V_312 + V_23 -> V_26 , V_239 -> V_313 ) ;
V_247 = V_239 -> V_314 [ 0 ] / ( V_239 -> V_315 / 8 ) ;
F_14 ( V_316 + V_23 -> V_26 , V_247 ) ;
F_78 ( V_6 , true ) ;
F_14 ( V_317 + V_23 -> V_26 ,
V_239 -> V_313 ) ;
V_234 &= ~ 3 ;
V_235 &= ~ 1 ;
F_14 ( V_318 + V_23 -> V_26 ,
( V_234 << 16 ) | V_235 ) ;
V_251 = V_6 -> V_172 . V_319 ;
V_252 = ( V_6 -> V_172 . V_320 + 1 ) & ~ 1 ;
F_14 ( V_321 + V_23 -> V_26 ,
( V_251 << 16 ) | V_252 ) ;
F_14 ( V_98 + V_23 -> V_26 , 0 ) ;
if ( ! V_236 && V_233 && V_233 != V_6 -> V_255 -> V_233 ) {
V_238 = F_81 ( V_233 ) ;
V_243 = F_82 ( V_238 -> V_241 ) ;
V_253 = F_83 ( V_243 , false ) ;
if ( F_84 ( V_253 != 0 ) )
return V_253 ;
F_102 ( V_243 ) ;
F_87 ( V_243 ) ;
}
F_64 ( V_2 ) ;
return 0 ;
}
static void F_103 ( struct V_228 * V_6 ,
struct V_171 * V_172 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( V_172 -> V_192 & V_193 )
F_14 ( V_322 + V_23 -> V_26 ,
V_323 ) ;
else
F_14 ( V_322 + V_23 -> V_26 , 0 ) ;
}
static void F_104 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
int V_13 ;
F_57 ( L_14 , V_23 -> V_20 ) ;
F_14 ( V_324 + V_23 -> V_26 ,
( F_105 ( V_325 ) |
F_106 ( V_325 ) ) ) ;
F_14 ( V_326 + V_23 -> V_26 ,
V_327 ) ;
F_14 ( V_328 + V_23 -> V_26 ,
V_329 ) ;
F_14 ( V_330 + V_23 -> V_26 ,
( F_107 ( V_331 ) |
F_108 ( V_331 ) ) ) ;
F_14 ( V_332 + V_23 -> V_26 , 0 ) ;
F_14 ( V_333 + V_23 -> V_26 , 0 ) ;
F_14 ( V_334 + V_23 -> V_26 , 0 ) ;
F_14 ( V_335 + V_23 -> V_26 , 0 ) ;
F_14 ( V_336 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_337 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_338 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_339 + V_23 -> V_26 , 0 ) ;
F_14 ( V_340 + V_23 -> V_26 , 0x00000007 ) ;
F_14 ( V_341 + V_23 -> V_26 , 0 ) ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ ) {
F_14 ( V_342 + V_23 -> V_26 ,
( V_23 -> V_343 [ V_13 ] << 20 ) |
( V_23 -> V_344 [ V_13 ] << 10 ) |
( V_23 -> V_345 [ V_13 ] << 0 ) ) ;
}
F_14 ( V_346 + V_23 -> V_26 ,
( F_109 ( V_347 ) |
F_110 ( V_347 ) |
F_111 ( V_347 ) |
F_112 ( V_347 ) ) ) ;
F_14 ( V_348 + V_23 -> V_26 ,
( F_113 ( V_349 ) |
F_114 ( V_349 ) ) ) ;
F_14 ( V_350 + V_23 -> V_26 ,
( F_115 ( V_351 ) |
F_116 ( V_351 ) ) ) ;
F_14 ( V_352 + V_23 -> V_26 ,
( F_117 ( 0 ) |
F_118 ( V_353 ) ) ) ;
F_14 ( 0x1a50 + V_23 -> V_26 , 0 ) ;
}
static int F_119 ( struct V_106 * V_107 )
{
struct V_109 * V_109 = F_34 ( V_107 ) ;
struct V_216 * V_217 = V_109 -> V_218 ;
switch ( V_109 -> V_221 ) {
case V_354 :
return V_217 -> V_355 ? 1 : 0 ;
case V_356 :
return V_217 -> V_355 ? 3 : 2 ;
case V_357 :
return V_217 -> V_355 ? 5 : 4 ;
case V_358 :
return 6 ;
default:
F_75 ( L_15 , V_109 -> V_221 ) ;
return 0 ;
}
}
static T_1 F_120 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
T_1 V_359 ;
int V_360 ;
if ( F_121 ( F_122 ( V_23 -> V_107 ) ) ) {
if ( V_2 -> clock . V_361 )
return V_362 ;
else
return V_363 ;
} else {
V_360 = F_123 ( V_6 ) ;
if ( V_360 != V_362 )
return V_360 ;
}
V_359 = F_124 ( V_6 ) ;
if ( ! ( V_359 & ( 1 << V_364 ) ) )
return V_364 ;
if ( ! ( V_359 & ( 1 << V_365 ) ) )
return V_365 ;
F_75 ( L_16 ) ;
return V_362 ;
}
static void F_125 ( struct V_228 * V_6 , bool V_366 )
{
struct V_1 * V_2 = V_6 -> V_59 -> V_108 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
T_5 V_367 ;
V_367 = F_5 ( V_368 + V_23 -> V_26 ) ;
if ( V_366 )
V_367 |= V_369 ;
else
V_367 &= ~ V_369 ;
F_14 ( V_368 + V_23 -> V_26 , V_367 ) ;
}
static void F_126 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_59 -> V_108 ;
F_127 ( V_370 + V_23 -> V_26 ,
F_128 ( V_371 ) |
F_129 ( V_372 ) ) ;
}
static void F_130 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_59 -> V_108 ;
F_14 ( V_373 + V_23 -> V_26 ,
F_15 ( V_23 -> V_374 ) ) ;
F_14 ( V_375 + V_23 -> V_26 ,
F_131 ( V_23 -> V_374 ) ) ;
F_127 ( V_370 + V_23 -> V_26 ,
V_376 |
F_128 ( V_371 ) |
F_129 ( V_372 ) ) ;
}
static int F_132 ( struct V_228 * V_6 ,
int V_234 , int V_235 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_59 -> V_108 ;
int V_377 = 0 , V_378 = 0 ;
int V_379 = V_23 -> V_380 ;
V_234 += V_6 -> V_234 ;
V_235 += V_6 -> V_235 ;
F_71 ( L_17 , V_234 , V_235 , V_6 -> V_234 , V_6 -> V_235 ) ;
if ( V_234 < 0 ) {
V_377 = F_48 ( - V_234 , V_23 -> V_381 - 1 ) ;
V_234 = 0 ;
}
if ( V_235 < 0 ) {
V_378 = F_48 ( - V_235 , V_23 -> V_382 - 1 ) ;
V_235 = 0 ;
}
F_14 ( V_383 + V_23 -> V_26 , ( V_234 << 16 ) | V_235 ) ;
F_14 ( V_384 + V_23 -> V_26 , ( V_377 << 16 ) | V_378 ) ;
F_14 ( V_385 + V_23 -> V_26 ,
( ( V_379 - 1 ) << 16 ) | ( V_23 -> V_386 - 1 ) ) ;
V_23 -> V_387 = V_234 ;
V_23 -> V_388 = V_235 ;
return 0 ;
}
static int F_133 ( struct V_228 * V_6 ,
int V_234 , int V_235 )
{
int V_389 ;
F_125 ( V_6 , true ) ;
V_389 = F_132 ( V_6 , V_234 , V_235 ) ;
F_125 ( V_6 , false ) ;
return V_389 ;
}
static int F_134 ( struct V_228 * V_6 ,
struct V_390 * V_391 ,
T_5 V_392 ,
T_5 V_311 ,
T_5 V_313 ,
T_6 V_393 ,
T_6 V_394 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_240 * V_241 ;
struct V_242 * V_395 ;
int V_389 ;
if ( ! V_392 ) {
F_126 ( V_6 ) ;
V_241 = NULL ;
goto V_396;
}
if ( ( V_311 > V_23 -> V_381 ) ||
( V_313 > V_23 -> V_382 ) ) {
F_75 ( L_18 , V_311 , V_313 ) ;
return - V_32 ;
}
V_241 = F_135 ( V_391 , V_392 ) ;
if ( ! V_241 ) {
F_75 ( L_19 , V_392 , V_23 -> V_20 ) ;
return - V_397 ;
}
V_395 = F_82 ( V_241 ) ;
V_389 = F_83 ( V_395 , false ) ;
if ( V_389 != 0 ) {
F_136 ( V_241 ) ;
return V_389 ;
}
V_389 = F_86 ( V_395 , V_256 , & V_23 -> V_374 ) ;
F_87 ( V_395 ) ;
if ( V_389 ) {
F_75 ( L_20 , V_389 ) ;
F_136 ( V_241 ) ;
return V_389 ;
}
V_23 -> V_380 = V_311 ;
V_23 -> V_386 = V_313 ;
F_125 ( V_6 , true ) ;
if ( V_393 != V_23 -> V_398 ||
V_394 != V_23 -> V_399 ) {
int V_234 , V_235 ;
V_234 = V_23 -> V_387 + V_23 -> V_398 - V_393 ;
V_235 = V_23 -> V_388 + V_23 -> V_399 - V_394 ;
F_132 ( V_6 , V_234 , V_235 ) ;
V_23 -> V_398 = V_393 ;
V_23 -> V_399 = V_394 ;
}
F_130 ( V_6 ) ;
F_125 ( V_6 , false ) ;
V_396:
if ( V_23 -> V_400 ) {
struct V_242 * V_395 = F_82 ( V_23 -> V_400 ) ;
V_389 = F_83 ( V_395 , false ) ;
if ( F_137 ( V_389 == 0 ) ) {
F_102 ( V_395 ) ;
F_87 ( V_395 ) ;
}
F_136 ( V_23 -> V_400 ) ;
}
V_23 -> V_400 = V_241 ;
return 0 ;
}
static void F_138 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( V_23 -> V_400 ) {
F_125 ( V_6 , true ) ;
F_132 ( V_6 , V_23 -> V_387 ,
V_23 -> V_388 ) ;
F_130 ( V_6 ) ;
F_125 ( V_6 , false ) ;
}
}
static int F_139 ( struct V_228 * V_6 , T_7 * V_401 , T_7 * V_402 ,
T_7 * V_403 , T_5 V_404 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_404 ; V_13 ++ ) {
V_23 -> V_343 [ V_13 ] = V_401 [ V_13 ] >> 6 ;
V_23 -> V_344 [ V_13 ] = V_402 [ V_13 ] >> 6 ;
V_23 -> V_345 [ V_13 ] = V_403 [ V_13 ] >> 6 ;
}
F_104 ( V_6 ) ;
return 0 ;
}
static void F_140 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
F_141 ( V_6 ) ;
F_74 ( V_23 ) ;
}
static void F_142 ( struct V_228 * V_6 , int V_172 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
unsigned type ;
switch ( V_172 ) {
case V_405 :
V_23 -> V_185 = true ;
F_143 ( V_6 , V_406 ) ;
F_144 ( V_6 , V_407 ) ;
type = F_145 ( V_2 , V_23 -> V_20 ) ;
F_146 ( V_2 , & V_2 -> V_408 , type ) ;
F_146 ( V_2 , & V_2 -> V_19 , type ) ;
F_147 ( V_59 , V_23 -> V_20 ) ;
F_104 ( V_6 ) ;
break;
case V_409 :
case V_410 :
case V_411 :
F_148 ( V_59 , V_23 -> V_20 ) ;
if ( V_23 -> V_185 )
F_144 ( V_6 , V_406 ) ;
F_143 ( V_6 , V_407 ) ;
V_23 -> V_185 = false ;
break;
}
F_149 ( V_2 ) ;
}
static void F_150 ( struct V_228 * V_6 )
{
F_151 ( V_6 , V_407 ) ;
F_152 ( V_6 , V_406 ) ;
F_142 ( V_6 , V_411 ) ;
}
static void F_153 ( struct V_228 * V_6 )
{
F_142 ( V_6 , V_405 ) ;
F_152 ( V_6 , V_407 ) ;
}
static void F_154 ( struct V_228 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
struct V_412 V_413 ;
int V_13 ;
F_142 ( V_6 , V_411 ) ;
if ( V_6 -> V_255 -> V_233 ) {
int V_253 ;
struct V_237 * V_238 ;
struct V_242 * V_243 ;
V_238 = F_81 ( V_6 -> V_255 -> V_233 ) ;
V_243 = F_82 ( V_238 -> V_241 ) ;
V_253 = F_83 ( V_243 , false ) ;
if ( F_84 ( V_253 ) )
F_75 ( L_21 ) ;
else {
F_102 ( V_243 ) ;
F_87 ( V_243 ) ;
}
}
F_78 ( V_6 , false ) ;
F_151 ( V_6 , V_406 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_2 -> V_14 . V_24 [ V_13 ] &&
V_2 -> V_14 . V_24 [ V_13 ] -> V_185 &&
V_13 != V_23 -> V_20 &&
V_23 -> V_414 == V_2 -> V_14 . V_24 [ V_13 ] -> V_414 ) {
goto V_415;
}
}
switch ( V_23 -> V_414 ) {
case V_365 :
case V_364 :
F_155 ( V_6 , V_23 -> V_20 , V_23 -> V_414 ,
0 , 0 , V_407 , 0 , 0 , 0 , 0 , 0 , false , & V_413 ) ;
break;
default:
break;
}
V_415:
V_23 -> V_414 = V_362 ;
V_23 -> V_416 = 0 ;
V_23 -> V_107 = NULL ;
V_23 -> V_62 = NULL ;
}
static int F_156 ( struct V_228 * V_6 ,
struct V_171 * V_172 ,
struct V_171 * V_417 ,
int V_234 , int V_235 , struct V_232 * V_418 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( ! V_23 -> V_416 )
return - V_32 ;
F_157 ( V_6 , V_417 ) ;
F_158 ( V_6 , V_417 ) ;
F_79 ( V_6 , V_418 , V_234 , V_235 , 0 ) ;
F_159 ( V_6 , V_172 , V_417 ) ;
F_160 ( V_6 ) ;
F_138 ( V_6 ) ;
V_23 -> V_419 = * V_417 ;
return 0 ;
}
static bool F_161 ( struct V_228 * V_6 ,
const struct V_171 * V_172 ,
struct V_171 * V_417 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_106 * V_107 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_107 -> V_6 == V_6 ) {
V_23 -> V_107 = V_107 ;
V_23 -> V_62 = F_35 ( V_107 ) ;
break;
}
}
if ( ( V_23 -> V_107 == NULL ) || ( V_23 -> V_62 == NULL ) ) {
V_23 -> V_107 = NULL ;
V_23 -> V_62 = NULL ;
return false ;
}
if ( ! F_162 ( V_6 , V_172 , V_417 ) )
return false ;
if ( F_163 ( V_6 , V_417 ) )
return false ;
V_23 -> V_414 = F_120 ( V_6 ) ;
if ( ( V_23 -> V_414 == V_362 ) &&
! F_121 ( F_122 ( V_23 -> V_107 ) ) )
return false ;
return true ;
}
static int F_164 ( struct V_228 * V_6 , int V_234 , int V_235 ,
struct V_232 * V_418 )
{
return F_79 ( V_6 , V_418 , V_234 , V_235 , 0 ) ;
}
static int F_165 ( struct V_228 * V_6 ,
struct V_232 * V_233 ,
int V_234 , int V_235 , enum V_420 V_421 )
{
return F_79 ( V_6 , V_233 , V_234 , V_235 , 1 ) ;
}
static int F_166 ( struct V_1 * V_2 , int V_422 )
{
struct V_23 * V_23 ;
int V_13 ;
V_23 = F_73 ( sizeof( struct V_23 ) +
( V_423 * sizeof( struct V_61 * ) ) , V_224 ) ;
if ( V_23 == NULL )
return - V_227 ;
F_167 ( V_2 -> V_60 , & V_23 -> V_173 , & V_424 ) ;
F_168 ( & V_23 -> V_173 , 256 ) ;
V_23 -> V_20 = V_422 ;
V_2 -> V_14 . V_24 [ V_422 ] = V_23 ;
V_23 -> V_381 = V_425 ;
V_23 -> V_382 = V_426 ;
V_2 -> V_60 -> V_427 . V_380 = V_23 -> V_381 ;
V_2 -> V_60 -> V_427 . V_386 = V_23 -> V_382 ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ ) {
V_23 -> V_343 [ V_13 ] = V_13 << 2 ;
V_23 -> V_344 [ V_13 ] = V_13 << 2 ;
V_23 -> V_345 [ V_13 ] = V_13 << 2 ;
}
V_23 -> V_26 = V_8 [ V_23 -> V_20 ] ;
V_23 -> V_414 = V_362 ;
V_23 -> V_416 = 0 ;
V_23 -> V_107 = NULL ;
V_23 -> V_62 = NULL ;
F_169 ( & V_23 -> V_173 , & V_428 ) ;
return 0 ;
}
static int F_170 ( void * V_392 )
{
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
V_2 -> V_429 = & F_1 ;
V_2 -> V_430 = & F_3 ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
switch ( V_2 -> V_431 ) {
case V_432 :
case V_433 :
case V_434 :
V_2 -> V_14 . V_15 = 6 ;
V_2 -> V_14 . V_435 = 6 ;
V_2 -> V_14 . V_222 = 6 ;
break;
case V_436 :
V_2 -> V_14 . V_15 = 2 ;
V_2 -> V_14 . V_435 = 2 ;
V_2 -> V_14 . V_222 = 2 ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_173 ( void * V_392 )
{
int V_253 , V_13 ;
bool V_389 ;
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_253 = F_174 ( V_2 , V_13 + 1 , & V_2 -> V_408 ) ;
if ( V_253 )
return V_253 ;
}
for ( V_13 = 8 ; V_13 < 20 ; V_13 += 2 ) {
V_253 = F_174 ( V_2 , V_13 , & V_2 -> V_19 ) ;
if ( V_253 )
return V_253 ;
}
V_253 = F_174 ( V_2 , 42 , & V_2 -> V_77 ) ;
if ( V_253 )
return V_253 ;
V_2 -> V_14 . V_212 = true ;
V_2 -> V_60 -> V_427 . V_437 = & V_438 ;
V_2 -> V_60 -> V_427 . V_439 = true ;
V_2 -> V_60 -> V_427 . V_440 = 16384 ;
V_2 -> V_60 -> V_427 . V_441 = 16384 ;
V_2 -> V_60 -> V_427 . V_442 = 24 ;
V_2 -> V_60 -> V_427 . V_443 = 1 ;
V_2 -> V_60 -> V_427 . V_444 = V_2 -> V_92 . V_445 ;
V_253 = F_175 ( V_2 ) ;
if ( V_253 )
return V_253 ;
V_2 -> V_60 -> V_427 . V_440 = 16384 ;
V_2 -> V_60 -> V_427 . V_441 = 16384 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_253 = F_166 ( V_2 , V_13 ) ;
if ( V_253 )
return V_253 ;
}
V_389 = F_176 ( V_2 ) ;
if ( V_389 )
F_177 ( V_2 -> V_60 ) ;
else
return - V_32 ;
V_253 = F_72 ( V_2 ) ;
if ( V_253 )
return V_253 ;
V_253 = F_67 ( V_2 ) ;
if ( V_253 )
return V_253 ;
F_178 ( V_2 -> V_60 ) ;
return V_253 ;
}
static int F_179 ( void * V_392 )
{
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
F_74 ( V_2 -> V_14 . V_446 ) ;
F_180 ( V_2 -> V_60 ) ;
F_68 ( V_2 ) ;
F_76 ( V_2 ) ;
F_181 ( V_2 -> V_60 ) ;
V_2 -> V_14 . V_212 = false ;
return 0 ;
}
static int F_182 ( void * V_392 )
{
int V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
F_183 ( V_2 ) ;
F_184 ( V_2 , V_2 -> clock . V_447 ) ;
F_19 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_448 . V_449 ; V_13 ++ ) {
F_66 ( V_2 , & V_2 -> V_14 . V_448 . V_214 [ V_13 ] , false ) ;
}
F_9 ( V_2 ) ;
return 0 ;
}
static int F_185 ( void * V_392 )
{
int V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
F_24 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_448 . V_449 ; V_13 ++ ) {
F_66 ( V_2 , & V_2 -> V_14 . V_448 . V_214 [ V_13 ] , false ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_186 ( void * V_392 )
{
return F_185 ( V_392 ) ;
}
static int F_187 ( void * V_392 )
{
struct V_1 * V_2 = (struct V_1 * ) V_392 ;
int V_389 ;
V_389 = F_182 ( V_392 ) ;
if ( V_2 -> V_14 . V_450 ) {
T_8 V_451 = F_188 ( V_2 ,
V_2 -> V_14 . V_450 ) ;
F_189 ( V_2 , V_2 -> V_14 . V_450 ,
V_451 ) ;
}
return V_389 ;
}
static bool F_190 ( void * V_392 )
{
return true ;
}
static int F_191 ( void * V_392 )
{
return 0 ;
}
static int F_192 ( void * V_392 )
{
F_2 ( L_22 ) ;
return 0 ;
}
static void F_193 ( struct V_1 * V_2 ,
int V_6 ,
enum V_452 V_421 )
{
T_1 V_453 , V_454 ;
if ( V_6 >= V_2 -> V_14 . V_15 ) {
F_71 ( L_23 , V_6 ) ;
return;
}
switch ( V_6 ) {
case 0 :
V_453 = V_455 ;
break;
case 1 :
V_453 = V_456 ;
break;
case 2 :
V_453 = V_457 ;
break;
case 3 :
V_453 = V_458 ;
break;
case 4 :
V_453 = V_459 ;
break;
case 5 :
V_453 = V_460 ;
break;
default:
F_71 ( L_23 , V_6 ) ;
return;
}
switch ( V_421 ) {
case V_461 :
V_454 = F_5 ( V_462 + V_453 ) ;
V_454 &= ~ V_463 ;
F_14 ( V_462 + V_453 , V_454 ) ;
break;
case V_464 :
V_454 = F_5 ( V_462 + V_453 ) ;
V_454 |= V_463 ;
F_14 ( V_462 + V_453 , V_454 ) ;
break;
default:
break;
}
}
static void F_194 ( struct V_1 * V_2 ,
int V_6 ,
enum V_452 V_421 )
{
}
static int F_195 ( struct V_1 * V_2 ,
struct V_465 * V_466 ,
unsigned type ,
enum V_452 V_421 )
{
T_1 V_74 , V_75 ;
switch ( type ) {
case V_37 :
V_74 = V_51 ;
break;
case V_40 :
V_74 = V_53 ;
break;
case V_42 :
V_74 = V_54 ;
break;
case V_44 :
V_74 = V_55 ;
break;
case V_46 :
V_74 = V_56 ;
break;
case V_48 :
V_74 = V_57 ;
break;
default:
F_71 ( L_24 , type ) ;
return 0 ;
}
switch ( V_421 ) {
case V_461 :
V_75 = F_5 ( V_74 ) ;
V_75 &= ~ ( V_76 | V_467 ) ;
F_14 ( V_74 , V_75 ) ;
break;
case V_464 :
V_75 = F_5 ( V_74 ) ;
V_75 |= ( V_76 | V_467 ) ;
F_14 ( V_74 , V_75 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_196 ( struct V_1 * V_2 ,
struct V_465 * V_466 ,
unsigned type ,
enum V_452 V_421 )
{
switch ( type ) {
case V_468 :
F_193 ( V_2 , 0 , V_421 ) ;
break;
case V_469 :
F_193 ( V_2 , 1 , V_421 ) ;
break;
case V_470 :
F_193 ( V_2 , 2 , V_421 ) ;
break;
case V_471 :
F_193 ( V_2 , 3 , V_421 ) ;
break;
case V_472 :
F_193 ( V_2 , 4 , V_421 ) ;
break;
case V_473 :
F_193 ( V_2 , 5 , V_421 ) ;
break;
case V_474 :
F_194 ( V_2 , 0 , V_421 ) ;
break;
case V_475 :
F_194 ( V_2 , 1 , V_421 ) ;
break;
case V_476 :
F_194 ( V_2 , 2 , V_421 ) ;
break;
case V_477 :
F_194 ( V_2 , 3 , V_421 ) ;
break;
case V_478 :
F_194 ( V_2 , 4 , V_421 ) ;
break;
case V_479 :
F_194 ( V_2 , 5 , V_421 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
struct V_465 * V_480 ,
struct V_481 * V_482 )
{
unsigned V_6 = V_482 -> V_483 - 1 ;
T_5 V_484 = F_5 ( V_485 [ V_6 ] . V_4 ) ;
unsigned V_486 = F_145 ( V_2 , V_6 ) ;
switch ( V_482 -> V_487 ) {
case 0 :
if ( V_484 & V_485 [ V_6 ] . V_488 )
F_14 ( V_489 + V_8 [ V_6 ] , V_490 ) ;
else
F_71 ( L_25 ) ;
if ( F_198 ( V_2 , V_480 , V_486 ) ) {
F_199 ( V_2 -> V_60 , V_6 ) ;
}
F_71 ( L_26 , V_6 + 1 ) ;
break;
case 1 :
if ( V_484 & V_485 [ V_6 ] . V_491 )
F_14 ( V_492 + V_8 [ V_6 ] , V_493 ) ;
else
F_71 ( L_25 ) ;
F_71 ( L_27 , V_6 + 1 ) ;
break;
default:
F_71 ( L_28 , V_482 -> V_483 , V_482 -> V_487 ) ;
break;
}
return 0 ;
}
static int F_200 ( struct V_1 * V_2 ,
struct V_465 * V_466 ,
unsigned type ,
enum V_452 V_421 )
{
T_1 V_4 ;
if ( type >= V_2 -> V_14 . V_15 ) {
F_75 ( L_29 , type ) ;
return - V_32 ;
}
V_4 = F_5 ( V_494 + V_8 [ type ] ) ;
if ( V_421 == V_461 )
F_14 ( V_494 + V_8 [ type ] ,
V_4 & ~ V_495 ) ;
else
F_14 ( V_494 + V_8 [ type ] ,
V_4 | V_495 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_465 * V_480 ,
struct V_481 * V_482 )
{
unsigned long V_192 ;
unsigned V_20 ;
struct V_23 * V_23 ;
struct V_496 * V_497 ;
V_20 = ( V_482 -> V_483 - 8 ) >> 1 ;
V_23 = V_2 -> V_14 . V_24 [ V_20 ] ;
if ( V_20 >= V_2 -> V_14 . V_15 ) {
F_75 ( L_29 , V_20 ) ;
return - V_32 ;
}
if ( F_5 ( V_498 + V_8 [ V_20 ] ) &
V_499 )
F_14 ( V_498 + V_8 [ V_20 ] ,
V_500 ) ;
if ( V_23 == NULL )
return 0 ;
F_202 ( & V_2 -> V_60 -> V_501 , V_192 ) ;
V_497 = V_23 -> V_502 ;
if ( V_23 -> V_503 != V_504 ) {
F_203 ( L_30
L_31 ,
V_23 -> V_503 ,
V_504 ) ;
F_204 ( & V_2 -> V_60 -> V_501 , V_192 ) ;
return 0 ;
}
V_23 -> V_503 = V_505 ;
V_23 -> V_502 = NULL ;
if ( V_497 -> V_506 )
F_205 ( & V_23 -> V_173 , V_497 -> V_506 ) ;
F_204 ( & V_2 -> V_60 -> V_501 , V_192 ) ;
F_206 ( & V_23 -> V_173 ) ;
F_207 ( & V_497 -> V_507 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_2 ,
struct V_465 * V_480 ,
struct V_481 * V_482 )
{
T_5 V_484 , V_508 , V_509 , V_50 ;
unsigned V_35 ;
if ( V_482 -> V_487 >= V_2 -> V_14 . V_435 ) {
F_71 ( L_28 , V_482 -> V_483 , V_482 -> V_487 ) ;
return 0 ;
}
V_35 = V_482 -> V_487 ;
V_484 = F_5 ( V_485 [ V_35 ] . V_4 ) ;
V_508 = V_485 [ V_35 ] . V_35 ;
V_509 = V_510 [ V_35 ] ;
if ( V_484 & V_508 ) {
V_50 = F_5 ( V_509 ) ;
V_50 |= V_511 ;
F_14 ( V_509 , V_50 ) ;
F_207 ( & V_2 -> V_512 ) ;
F_2 ( L_32 , V_35 + 1 ) ;
}
return 0 ;
}
static int F_209 ( void * V_392 ,
enum V_513 V_421 )
{
return 0 ;
}
static int F_210 ( void * V_392 ,
enum V_514 V_421 )
{
return 0 ;
}
static void
F_211 ( struct V_106 * V_107 ,
struct V_171 * V_172 ,
struct V_171 * V_417 )
{
struct V_109 * V_109 = F_34 ( V_107 ) ;
V_109 -> V_515 = V_417 -> clock ;
F_212 ( V_107 , V_411 ) ;
F_103 ( V_107 -> V_6 , V_172 ) ;
if ( F_122 ( V_107 ) == V_516 ) {
F_70 ( V_107 , true ) ;
F_69 ( V_107 , V_417 ) ;
}
}
static void F_213 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_59 -> V_108 ;
struct V_109 * V_109 = F_34 ( V_107 ) ;
struct V_61 * V_62 = F_35 ( V_107 ) ;
if ( ( V_109 -> V_517 &
( V_518 | V_115 ) ) ||
( F_214 ( V_107 ) !=
V_519 ) ) {
struct V_216 * V_217 = V_109 -> V_218 ;
if ( V_217 ) {
V_217 -> V_520 = F_119 ( V_107 ) ;
if ( V_109 -> V_517 & V_518 )
V_217 -> V_219 = V_2 -> V_14 . V_219 [ V_217 -> V_520 ] ;
}
}
F_215 ( V_2 , true ) ;
if ( V_62 ) {
struct V_64 * V_64 = F_23 ( V_62 ) ;
if ( V_64 -> V_521 . V_522 )
F_216 ( V_64 ) ;
if ( V_62 -> V_71 == V_72 )
F_217 ( V_62 ,
V_523 ) ;
}
F_218 ( V_107 ) ;
F_33 ( V_107 ) ;
}
static void F_219 ( struct V_106 * V_107 )
{
struct V_58 * V_59 = V_107 -> V_59 ;
struct V_1 * V_2 = V_59 -> V_108 ;
F_212 ( V_107 , V_405 ) ;
F_215 ( V_2 , false ) ;
}
static void F_220 ( struct V_106 * V_107 )
{
struct V_109 * V_109 = F_34 ( V_107 ) ;
struct V_216 * V_217 ;
F_212 ( V_107 , V_411 ) ;
if ( F_221 ( V_107 ) ) {
if ( F_122 ( V_107 ) == V_516 )
F_70 ( V_107 , false ) ;
V_217 = V_109 -> V_218 ;
V_217 -> V_520 = - 1 ;
}
V_109 -> V_517 = 0 ;
}
static void F_222 ( struct V_106 * V_107 )
{
}
static void F_223 ( struct V_106 * V_107 )
{
}
static void
F_224 ( struct V_106 * V_107 ,
struct V_171 * V_172 ,
struct V_171 * V_417 )
{
}
static void F_225 ( struct V_106 * V_107 )
{
}
static void
F_226 ( struct V_106 * V_107 , int V_172 )
{
}
static bool F_227 ( struct V_106 * V_107 ,
const struct V_171 * V_172 ,
struct V_171 * V_417 )
{
return true ;
}
static void F_228 ( struct V_106 * V_107 )
{
struct V_109 * V_109 = F_34 ( V_107 ) ;
if ( V_109 -> V_114 & ( V_115 ) )
F_229 ( V_109 ) ;
F_74 ( V_109 -> V_218 ) ;
F_230 ( V_107 ) ;
F_74 ( V_109 ) ;
}
static void F_231 ( struct V_1 * V_2 ,
T_5 V_524 ,
T_5 V_525 ,
T_7 V_526 )
{
struct V_58 * V_59 = V_2 -> V_60 ;
struct V_106 * V_107 ;
struct V_109 * V_109 ;
F_22 (encoder, &dev->mode_config.encoder_list, head) {
V_109 = F_34 ( V_107 ) ;
if ( V_109 -> V_524 == V_524 ) {
V_109 -> V_114 |= V_525 ;
return;
}
}
V_109 = F_73 ( sizeof( struct V_109 ) , V_224 ) ;
if ( ! V_109 )
return;
V_107 = & V_109 -> V_173 ;
switch ( V_2 -> V_14 . V_15 ) {
case 1 :
V_107 -> V_527 = 0x1 ;
break;
case 2 :
default:
V_107 -> V_527 = 0x3 ;
break;
case 4 :
V_107 -> V_527 = 0xf ;
break;
case 6 :
V_107 -> V_527 = 0x3f ;
break;
}
V_109 -> V_218 = NULL ;
V_109 -> V_524 = V_524 ;
V_109 -> V_221 = ( V_524 & V_528 ) >> V_529 ;
V_109 -> V_114 = V_525 ;
V_109 -> V_194 = V_195 ;
V_109 -> V_530 = V_531 ;
V_109 -> V_532 = false ;
V_109 -> V_526 = V_526 ;
switch ( V_109 -> V_221 ) {
case V_533 :
case V_534 :
F_232 ( V_59 , V_107 , & V_535 ,
V_536 , NULL ) ;
F_233 ( V_107 , & V_537 ) ;
break;
case V_538 :
case V_354 :
case V_356 :
case V_357 :
case V_358 :
if ( V_109 -> V_114 & ( V_115 ) ) {
V_109 -> V_194 = V_539 ;
F_232 ( V_59 , V_107 , & V_535 ,
V_540 , NULL ) ;
V_109 -> V_218 = F_234 ( V_109 ) ;
} else if ( V_109 -> V_114 & ( V_541 ) ) {
F_232 ( V_59 , V_107 , & V_535 ,
V_536 , NULL ) ;
V_109 -> V_218 = F_235 ( V_109 ) ;
} else {
F_232 ( V_59 , V_107 , & V_535 ,
V_542 , NULL ) ;
V_109 -> V_218 = F_235 ( V_109 ) ;
}
F_233 ( V_107 , & V_543 ) ;
break;
case V_544 :
case V_545 :
case V_546 :
case V_547 :
case V_548 :
case V_549 :
case V_550 :
case V_551 :
case V_552 :
V_109 -> V_532 = true ;
if ( V_109 -> V_114 & ( V_115 ) )
F_232 ( V_59 , V_107 , & V_535 ,
V_540 , NULL ) ;
else if ( V_109 -> V_114 & ( V_541 ) )
F_232 ( V_59 , V_107 , & V_535 ,
V_536 , NULL ) ;
else
F_232 ( V_59 , V_107 , & V_535 ,
V_542 , NULL ) ;
F_233 ( V_107 , & V_553 ) ;
break;
}
}
static void F_171 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_437 == NULL )
V_2 -> V_14 . V_437 = & V_554 ;
}
static void F_172 ( struct V_1 * V_2 )
{
V_2 -> V_408 . V_555 = V_556 ;
V_2 -> V_408 . V_437 = & V_557 ;
V_2 -> V_19 . V_555 = V_558 ;
V_2 -> V_19 . V_437 = & V_559 ;
V_2 -> V_77 . V_555 = V_560 ;
V_2 -> V_77 . V_437 = & V_561 ;
}
