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
if ( V_35 >= V_2 -> V_14 . V_37 )
return V_36 ;
if ( F_5 ( V_38 + V_39 [ V_35 ] ) & V_40 )
V_36 = true ;
return V_36 ;
}
static void F_18 ( struct V_1 * V_2 ,
enum V_34 V_35 )
{
T_1 V_41 ;
bool V_36 = F_17 ( V_2 , V_35 ) ;
if ( V_35 >= V_2 -> V_14 . V_37 )
return;
V_41 = F_5 ( V_42 + V_39 [ V_35 ] ) ;
if ( V_36 )
V_41 &= ~ V_43 ;
else
V_41 |= V_43 ;
F_14 ( V_42 + V_39 [ V_35 ] , V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_47 * V_48 ;
T_1 V_41 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
struct V_49 * V_49 = F_21 ( V_48 ) ;
if ( V_49 -> V_35 . V_35 >= V_2 -> V_14 . V_37 )
continue;
V_41 = F_5 ( V_50 + V_39 [ V_49 -> V_35 . V_35 ] ) ;
V_41 |= V_51 ;
F_14 ( V_50 + V_39 [ V_49 -> V_35 . V_35 ] , V_41 ) ;
if ( V_48 -> V_52 == V_53 ||
V_48 -> V_52 == V_54 ) {
V_41 = F_5 ( V_42 + V_39 [ V_49 -> V_35 . V_35 ] ) ;
V_41 &= ~ V_55 ;
F_14 ( V_42 + V_39 [ V_49 -> V_35 . V_35 ] , V_41 ) ;
continue;
}
F_18 ( V_2 , V_49 -> V_35 . V_35 ) ;
F_10 ( V_2 , & V_2 -> V_56 , V_49 -> V_35 . V_35 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_47 * V_48 ;
T_1 V_41 ;
F_20 (connector, &dev->mode_config.connector_list, head) {
struct V_49 * V_49 = F_21 ( V_48 ) ;
if ( V_49 -> V_35 . V_35 >= V_2 -> V_14 . V_37 )
continue;
V_41 = F_5 ( V_50 + V_39 [ V_49 -> V_35 . V_35 ] ) ;
V_41 &= ~ V_51 ;
F_14 ( V_50 + V_39 [ V_49 -> V_35 . V_35 ] , 0 ) ;
F_12 ( V_2 , & V_2 -> V_56 , V_49 -> V_35 . V_35 ) ;
}
}
static T_1 F_23 ( struct V_1 * V_2 )
{
return V_57 ;
}
static T_1 F_24 ( struct V_1 * V_2 , int V_6 )
{
if ( V_6 >= V_2 -> V_14 . V_15 )
return 0 ;
else
return F_5 ( V_18 + V_8 [ V_6 ] ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
T_1 V_60 , V_41 , V_61 ;
int V_13 , V_62 ;
V_59 -> V_63 = F_5 ( V_64 ) ;
V_59 -> V_65 = F_5 ( V_66 ) ;
F_14 ( V_64 , 0 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_60 = F_5 ( V_16 + V_8 [ V_13 ] ) & V_17 ;
if ( V_60 ) {
V_59 -> V_60 [ V_13 ] = true ;
V_41 = F_5 ( V_67 + V_8 [ V_13 ] ) ;
if ( ! ( V_41 & V_68 ) ) {
F_7 ( V_2 , V_13 ) ;
F_14 ( V_69 + V_8 [ V_13 ] , 1 ) ;
V_41 |= V_68 ;
F_14 ( V_67 + V_8 [ V_13 ] , V_41 ) ;
F_14 ( V_69 + V_8 [ V_13 ] , 0 ) ;
}
V_61 = F_24 ( V_2 , V_13 ) ;
for ( V_62 = 0 ; V_62 < V_2 -> V_70 ; V_62 ++ ) {
if ( F_24 ( V_2 , V_13 ) != V_61 )
break;
F_26 ( 1 ) ;
}
F_14 ( V_69 + V_8 [ V_13 ] , 1 ) ;
V_41 = F_5 ( V_16 + V_8 [ V_13 ] ) ;
V_41 &= ~ V_17 ;
F_14 ( V_16 + V_8 [ V_13 ] , V_41 ) ;
F_14 ( V_69 + V_8 [ V_13 ] , 0 ) ;
V_59 -> V_60 [ V_13 ] = false ;
} else {
V_59 -> V_60 [ V_13 ] = false ;
}
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
T_1 V_41 ;
int V_13 , V_62 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
F_14 ( V_28 + V_8 [ V_13 ] ,
F_15 ( V_2 -> V_71 . V_72 ) ) ;
F_14 ( V_73 + V_8 [ V_13 ] ,
F_15 ( V_2 -> V_71 . V_72 ) ) ;
F_14 ( V_29 + V_8 [ V_13 ] ,
( T_1 ) V_2 -> V_71 . V_72 ) ;
F_14 ( V_74 + V_8 [ V_13 ] ,
( T_1 ) V_2 -> V_71 . V_72 ) ;
}
F_14 ( V_75 , F_15 ( V_2 -> V_71 . V_72 ) ) ;
F_14 ( V_76 , ( T_1 ) V_2 -> V_71 . V_72 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_59 -> V_60 [ V_13 ] ) {
V_41 = F_5 ( V_77 + V_8 [ V_13 ] ) ;
if ( ( V_41 & 0x7 ) != 0 ) {
V_41 &= ~ 0x7 ;
F_14 ( V_77 + V_8 [ V_13 ] , V_41 ) ;
}
V_41 = F_5 ( V_78 + V_8 [ V_13 ] ) ;
if ( V_41 & V_79 ) {
V_41 &= ~ V_79 ;
F_14 ( V_78 + V_8 [ V_13 ] , V_41 ) ;
}
V_41 = F_5 ( V_80 + V_8 [ V_13 ] ) ;
if ( V_41 & 1 ) {
V_41 &= ~ 1 ;
F_14 ( V_80 + V_8 [ V_13 ] , V_41 ) ;
}
for ( V_62 = 0 ; V_62 < V_2 -> V_70 ; V_62 ++ ) {
V_41 = F_5 ( V_78 + V_8 [ V_13 ] ) ;
if ( ( V_41 & V_81 ) == 0 )
break;
F_26 ( 1 ) ;
}
}
}
F_14 ( V_66 , V_59 -> V_65 ) ;
F_28 ( 1 ) ;
F_14 ( V_64 , V_59 -> V_63 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
bool V_82 )
{
if ( ! V_82 )
F_14 ( V_64 ,
F_5 ( V_64 ) & V_83 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_15 = 0 ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_86 :
case V_87 :
V_15 = 6 ;
break;
case V_88 :
V_15 = 2 ;
break;
default:
V_15 = 0 ;
}
return V_15 ;
}
void F_31 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 ) ) {
T_1 V_41 ;
int V_60 , V_13 ;
F_29 ( V_2 , false ) ;
for ( V_13 = 0 ; V_13 < F_30 ( V_2 ) ; V_13 ++ ) {
V_60 = F_5 ( V_16 + V_8 [ V_13 ] ) &
V_17 ;
if ( V_60 ) {
F_14 ( V_69 + V_8 [ V_13 ] , 1 ) ;
V_41 = F_5 ( V_16 + V_8 [ V_13 ] ) ;
V_41 &= ~ V_17 ;
F_14 ( V_16 + V_8 [ V_13 ] , V_41 ) ;
F_14 ( V_69 + V_8 [ V_13 ] , 0 ) ;
}
}
}
}
static void F_33 ( struct V_89 * V_90 )
{
struct V_44 * V_45 = V_90 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_92 * V_92 = F_34 ( V_90 ) ;
struct V_47 * V_48 = F_35 ( V_90 ) ;
struct V_23 * V_23 = F_36 ( V_90 -> V_6 ) ;
int V_93 = 0 ;
T_1 V_41 = 0 ;
enum V_94 V_95 = V_96 ;
if ( V_48 ) {
struct V_49 * V_49 = F_21 ( V_48 ) ;
V_93 = F_37 ( V_48 ) ;
V_95 = V_49 -> V_95 ;
}
if ( V_92 -> V_97 & V_98 )
return;
if ( V_93 == 0 )
return;
switch ( V_93 ) {
case 6 :
if ( V_95 == V_99 )
V_41 |= ( V_100 |
V_101 |
V_102 ) ;
else
V_41 |= V_103 ;
break;
case 8 :
if ( V_95 == V_99 )
V_41 |= ( V_100 |
V_101 |
V_104 |
V_102 |
V_105 ) ;
else
V_41 |= ( V_103 |
V_106 ) ;
break;
case 10 :
default:
break;
}
F_14 ( V_107 + V_23 -> V_26 , V_41 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
T_1 V_41 = F_5 ( V_108 ) ;
switch ( ( V_41 & V_109 ) >> V_110 ) {
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
static T_1 F_39 ( struct V_111 * V_112 )
{
T_3 V_113 ;
T_3 V_114 , V_115 , V_116 ;
T_3 V_117 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_114 . V_118 = F_40 ( V_112 -> V_114 ) ;
V_114 . V_118 = F_41 ( V_114 , V_117 ) ;
V_115 . V_118 = F_40 ( V_112 -> V_115 * 4 ) ;
V_117 . V_118 = F_40 ( 10 ) ;
V_113 . V_118 = F_40 ( 7 ) ;
V_113 . V_118 = F_41 ( V_113 , V_117 ) ;
V_116 . V_118 = F_42 ( V_115 , V_114 ) ;
V_116 . V_118 = F_42 ( V_116 , V_113 ) ;
return F_43 ( V_116 ) ;
}
static T_1 F_44 ( struct V_111 * V_112 )
{
T_3 V_119 ;
T_3 V_114 , V_115 , V_116 ;
T_3 V_117 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_114 . V_118 = F_40 ( V_112 -> V_114 ) ;
V_114 . V_118 = F_41 ( V_114 , V_117 ) ;
V_115 . V_118 = F_40 ( V_112 -> V_115 * 4 ) ;
V_117 . V_118 = F_40 ( 10 ) ;
V_119 . V_118 = F_40 ( 3 ) ;
V_119 . V_118 = F_41 ( V_119 , V_117 ) ;
V_116 . V_118 = F_42 ( V_115 , V_114 ) ;
V_116 . V_118 = F_42 ( V_116 , V_119 ) ;
return F_43 ( V_116 ) ;
}
static T_1 F_45 ( struct V_111 * V_112 )
{
T_3 V_120 ;
T_3 V_121 , V_116 ;
T_3 V_117 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_121 . V_118 = F_40 ( V_112 -> V_121 ) ;
V_121 . V_118 = F_41 ( V_121 , V_117 ) ;
V_117 . V_118 = F_40 ( 10 ) ;
V_120 . V_118 = F_40 ( 8 ) ;
V_120 . V_118 = F_41 ( V_120 , V_117 ) ;
V_117 . V_118 = F_40 ( 32 ) ;
V_116 . V_118 = F_42 ( V_117 , V_121 ) ;
V_116 . V_118 = F_42 ( V_116 , V_120 ) ;
return F_43 ( V_116 ) ;
}
static T_1 F_46 ( struct V_111 * V_112 )
{
T_3 V_122 ;
T_3 V_123 , V_116 ;
T_3 V_117 , V_124 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_123 . V_118 = F_40 ( V_112 -> V_123 ) ;
V_123 . V_118 = F_41 ( V_123 , V_117 ) ;
V_117 . V_118 = F_40 ( 32 ) ;
V_124 . V_118 = F_42 ( V_117 , V_123 ) ;
V_117 . V_118 = F_40 ( 10 ) ;
V_122 . V_118 = F_40 ( 8 ) ;
V_122 . V_118 = F_41 ( V_122 , V_117 ) ;
V_116 . V_118 = F_42 ( V_124 , V_122 ) ;
return F_43 ( V_116 ) ;
}
static T_1 F_47 ( struct V_111 * V_112 )
{
T_1 V_125 = F_39 ( V_112 ) ;
T_1 V_126 = F_45 ( V_112 ) ;
T_1 V_127 = F_46 ( V_112 ) ;
return F_48 ( V_125 , F_48 ( V_126 , V_127 ) ) ;
}
static T_1 F_49 ( struct V_111 * V_112 )
{
T_3 V_128 ;
T_3 V_129 ;
T_3 V_130 ;
T_3 V_116 ;
T_3 V_117 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_129 . V_118 = F_40 ( V_112 -> V_131 + V_112 -> V_132 ) ;
V_129 . V_118 = F_41 ( V_129 , V_117 ) ;
V_128 . V_118 = F_40 ( V_112 -> V_133 ) ;
V_130 . V_118 = F_40 ( V_112 -> V_130 ) ;
V_116 . V_118 = F_42 ( V_130 , V_128 ) ;
V_116 . V_118 = F_42 ( V_116 , V_112 -> V_134 ) ;
V_116 . V_118 = F_41 ( V_116 , V_129 ) ;
return F_43 ( V_116 ) ;
}
static T_1 F_50 ( struct V_111 * V_112 )
{
T_1 V_135 = 2000 ;
T_1 V_136 = F_47 ( V_112 ) ;
T_1 V_137 = ( 512 * 8 * 1000 ) / V_136 ;
T_1 V_138 = ( 128 * 4 * 1000 ) / V_136 ;
T_1 V_139 = 40000000 / V_112 -> V_123 ;
T_1 V_140 = ( ( V_112 -> V_141 + 1 ) * V_137 ) +
( V_112 -> V_141 * V_138 ) ;
T_1 V_142 = V_135 + V_140 + V_139 ;
T_1 V_143 , V_144 , V_145 ;
T_1 V_41 , V_146 = 12288 ;
T_3 V_117 , V_124 , V_147 ;
if ( V_112 -> V_141 == 0 )
return 0 ;
V_117 . V_118 = F_40 ( 2 ) ;
V_124 . V_118 = F_40 ( 1 ) ;
if ( ( V_112 -> V_134 . V_118 > V_117 . V_118 ) ||
( ( V_112 -> V_134 . V_118 > V_124 . V_118 ) && ( V_112 -> V_148 >= 3 ) ) ||
( V_112 -> V_148 >= 5 ) ||
( ( V_112 -> V_134 . V_118 >= V_117 . V_118 ) && V_112 -> V_149 ) )
V_143 = 4 ;
else
V_143 = 2 ;
V_117 . V_118 = F_40 ( V_136 ) ;
V_124 . V_118 = F_40 ( V_112 -> V_141 ) ;
V_117 . V_118 = F_41 ( V_117 , V_124 ) ;
V_41 = F_51 ( ( T_2 ) V_146 * ( T_2 ) V_112 -> V_123 , V_135 + 512 ) ;
V_41 = F_48 ( F_43 ( V_117 ) , V_41 ) ;
V_144 = F_48 ( V_41 , V_112 -> V_123 * V_112 -> V_133 / 1000 ) ;
V_117 . V_118 = F_40 ( V_143 * V_112 -> V_130 * V_112 -> V_133 ) ;
V_124 . V_118 = F_40 ( 1000 ) ;
V_147 . V_118 = F_40 ( V_144 ) ;
V_124 . V_118 = F_41 ( V_147 , V_124 ) ;
V_117 . V_118 = F_41 ( V_117 , V_124 ) ;
V_145 = F_43 ( V_117 ) ;
if ( V_145 < V_112 -> V_131 )
return V_142 ;
else
return V_142 + ( V_145 - V_112 -> V_131 ) ;
}
static bool F_52 ( struct V_111 * V_112 )
{
if ( F_49 ( V_112 ) <=
( F_44 ( V_112 ) / V_112 -> V_141 ) )
return true ;
else
return false ;
}
static bool F_53 ( struct V_111 * V_112 )
{
if ( F_49 ( V_112 ) <=
( F_47 ( V_112 ) / V_112 -> V_141 ) )
return true ;
else
return false ;
}
static bool F_54 ( struct V_111 * V_112 )
{
T_1 V_150 = V_112 -> V_151 / V_112 -> V_130 ;
T_1 V_129 = V_112 -> V_131 + V_112 -> V_132 ;
T_1 V_152 ;
T_1 V_153 ;
T_3 V_117 ;
V_117 . V_118 = F_40 ( 1 ) ;
if ( V_112 -> V_134 . V_118 > V_117 . V_118 )
V_152 = 1 ;
else {
if ( V_150 <= ( V_112 -> V_148 + 1 ) )
V_152 = 1 ;
else
V_152 = 2 ;
}
V_153 = ( V_152 * V_129 + V_112 -> V_132 ) ;
if ( F_50 ( V_112 ) <= V_153 )
return true ;
else
return false ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
T_1 V_151 , T_1 V_141 )
{
struct V_154 * V_155 = & V_23 -> V_156 . V_155 ;
struct V_111 V_157 , V_158 ;
T_1 V_115 ;
T_1 V_131 ;
T_1 V_129 = 0 ;
T_1 V_159 = 0 , V_160 = 0 ;
T_1 V_161 = 0 , V_162 = 0 ;
T_1 V_163 = V_164 ;
T_1 V_165 = V_164 ;
T_1 V_41 , V_166 , V_167 = 0 ;
T_3 V_117 , V_124 , V_147 ;
if ( V_23 -> V_156 . V_168 && V_141 && V_155 ) {
V_131 = ( T_1 ) F_51 ( ( T_2 ) V_155 -> V_169 * 1000000 ,
( T_1 ) V_155 -> clock ) ;
V_129 = ( T_1 ) F_51 ( ( T_2 ) V_155 -> V_170 * 1000000 ,
( T_1 ) V_155 -> clock ) ;
V_129 = F_48 ( V_129 , ( T_1 ) 65535 ) ;
V_163 = 0 ;
V_165 = 0 ;
V_115 = F_38 ( V_2 ) ;
if ( V_2 -> V_171 . V_172 ) {
V_158 . V_114 =
F_56 ( V_2 , false ) * 10 ;
V_158 . V_121 =
F_57 ( V_2 , false ) * 10 ;
} else {
V_158 . V_114 = V_2 -> V_171 . V_173 * 10 ;
V_158 . V_121 = V_2 -> V_171 . V_174 * 10 ;
}
V_158 . V_123 = V_155 -> clock ;
V_158 . V_130 = V_155 -> V_169 ;
V_158 . V_131 = V_131 ;
V_158 . V_132 = V_129 - V_158 . V_131 ;
V_158 . V_149 = false ;
if ( V_155 -> V_175 & V_176 )
V_158 . V_149 = true ;
V_158 . V_134 = V_23 -> V_134 ;
V_158 . V_148 = 1 ;
if ( V_23 -> V_177 != V_178 )
V_158 . V_148 = 2 ;
V_158 . V_133 = 4 ;
V_158 . V_151 = V_151 ;
V_158 . V_115 = V_115 ;
V_158 . V_141 = V_141 ;
if ( V_2 -> V_171 . V_172 ) {
V_157 . V_114 =
F_56 ( V_2 , true ) * 10 ;
V_157 . V_121 =
F_57 ( V_2 , true ) * 10 ;
} else {
V_157 . V_114 = V_2 -> V_171 . V_173 * 10 ;
V_157 . V_121 = V_2 -> V_171 . V_174 * 10 ;
}
V_157 . V_123 = V_155 -> clock ;
V_157 . V_130 = V_155 -> V_169 ;
V_157 . V_131 = V_131 ;
V_157 . V_132 = V_129 - V_157 . V_131 ;
V_157 . V_149 = false ;
if ( V_155 -> V_175 & V_176 )
V_157 . V_149 = true ;
V_157 . V_134 = V_23 -> V_134 ;
V_157 . V_148 = 1 ;
if ( V_23 -> V_177 != V_178 )
V_157 . V_148 = 2 ;
V_157 . V_133 = 4 ;
V_157 . V_151 = V_151 ;
V_157 . V_115 = V_115 ;
V_157 . V_141 = V_141 ;
V_159 = F_48 ( F_50 ( & V_158 ) , ( T_1 ) 65535 ) ;
V_160 = F_48 ( F_50 ( & V_157 ) , ( T_1 ) 65535 ) ;
if ( ! F_52 ( & V_158 ) ||
! F_53 ( & V_158 ) ||
! F_54 ( & V_158 ) ||
( V_2 -> V_14 . V_179 == 2 ) ) {
F_58 ( L_3 ) ;
V_163 |= V_180 ;
V_165 |= V_180 ;
}
if ( ! F_52 ( & V_157 ) ||
! F_53 ( & V_157 ) ||
! F_54 ( & V_157 ) ||
( V_2 -> V_14 . V_179 == 2 ) ) {
F_58 ( L_3 ) ;
V_163 |= V_180 ;
V_165 |= V_180 ;
}
V_117 . V_118 = F_40 ( 1000 ) ;
V_124 . V_118 = F_40 ( V_155 -> clock ) ;
V_124 . V_118 = F_41 ( V_124 , V_117 ) ;
V_147 . V_118 = F_40 ( V_159 ) ;
V_147 . V_118 = F_42 ( V_147 , V_124 ) ;
V_147 . V_118 = F_42 ( V_147 , V_23 -> V_181 ) ;
V_147 . V_118 = F_41 ( V_147 , V_117 ) ;
V_117 . V_118 = F_40 ( 16 ) ;
V_147 . V_118 = F_41 ( V_147 , V_117 ) ;
V_161 = F_43 ( V_147 ) ;
V_163 |= V_161 & V_182 ;
V_117 . V_118 = F_40 ( 1000 ) ;
V_124 . V_118 = F_40 ( V_155 -> clock ) ;
V_124 . V_118 = F_41 ( V_124 , V_117 ) ;
V_147 . V_118 = F_40 ( V_160 ) ;
V_147 . V_118 = F_42 ( V_147 , V_124 ) ;
V_147 . V_118 = F_42 ( V_147 , V_23 -> V_181 ) ;
V_147 . V_118 = F_41 ( V_147 , V_117 ) ;
V_117 . V_118 = F_40 ( 16 ) ;
V_147 . V_118 = F_41 ( V_147 , V_117 ) ;
V_162 = F_43 ( V_147 ) ;
V_165 |= V_162 & V_182 ;
V_167 = F_59 ( V_151 , V_155 -> V_169 ) ;
}
V_166 = F_5 ( V_183 + V_23 -> V_26 ) ;
V_41 = V_166 ;
V_41 &= ~ F_60 ( 3 ) ;
V_41 |= F_60 ( 1 ) ;
F_14 ( V_183 + V_23 -> V_26 , V_41 ) ;
F_14 ( V_184 + V_23 -> V_26 ,
( ( V_159 << V_185 ) |
( V_129 << V_186 ) ) ) ;
V_41 = F_5 ( V_183 + V_23 -> V_26 ) ;
V_41 &= ~ F_60 ( 3 ) ;
V_41 |= F_60 ( 2 ) ;
F_14 ( V_183 + V_23 -> V_26 , V_41 ) ;
F_14 ( V_184 + V_23 -> V_26 ,
( ( V_160 << V_185 ) |
( V_129 << V_186 ) ) ) ;
F_14 ( V_183 + V_23 -> V_26 , V_166 ) ;
F_14 ( V_187 + V_23 -> V_26 , V_163 ) ;
F_14 ( V_188 + V_23 -> V_26 , V_165 ) ;
V_23 -> V_129 = V_129 ;
V_23 -> V_158 = V_159 ;
V_23 -> V_167 = V_167 ;
}
static T_1 F_61 ( struct V_1 * V_2 ,
struct V_23 * V_23 ,
struct V_154 * V_155 ,
struct V_154 * V_189 )
{
T_1 V_41 , V_190 , V_13 ;
T_1 V_191 = V_23 -> V_20 * 0x8 ;
if ( V_23 -> V_156 . V_168 && V_155 ) {
if ( V_189 ) {
V_41 = 0 ;
V_190 = 1 ;
} else {
V_41 = 2 ;
V_190 = 2 ;
}
} else {
V_41 = 0 ;
V_190 = 0 ;
}
F_14 ( V_192 + V_23 -> V_26 ,
F_62 ( V_41 ) ) ;
F_14 ( V_193 + V_191 ,
( V_190 << V_194 ) ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_70 ; V_13 ++ ) {
if ( F_5 ( V_193 + V_191 ) &
V_195 )
break;
F_26 ( 1 ) ;
}
if ( V_23 -> V_156 . V_168 && V_155 ) {
switch ( V_41 ) {
case 0 :
default:
return 4096 * 2 ;
case 2 :
return 8192 * 2 ;
}
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_154 * V_196 = NULL ;
struct V_154 * V_197 = NULL ;
T_1 V_141 = 0 , V_151 ;
int V_13 ;
if ( ! V_2 -> V_14 . V_198 )
return;
F_64 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_2 -> V_14 . V_24 [ V_13 ] -> V_156 . V_168 )
V_141 ++ ;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 += 2 ) {
V_196 = & V_2 -> V_14 . V_24 [ V_13 ] -> V_156 . V_155 ;
V_197 = & V_2 -> V_14 . V_24 [ V_13 + 1 ] -> V_156 . V_155 ;
V_151 = F_61 ( V_2 , V_2 -> V_14 . V_24 [ V_13 ] , V_196 , V_197 ) ;
F_55 ( V_2 , V_2 -> V_14 . V_24 [ V_13 ] , V_151 , V_141 ) ;
V_151 = F_61 ( V_2 , V_2 -> V_14 . V_24 [ V_13 + 1 ] , V_197 , V_196 ) ;
F_55 ( V_2 , V_2 -> V_14 . V_24 [ V_13 + 1 ] , V_151 , V_141 ) ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_199 * V_200 ,
bool V_201 )
{
F_2 ( L_4 ) ;
}
static int F_66 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_67 ( struct V_1 * V_2 )
{
}
static void F_68 ( struct V_89 * V_90 ,
struct V_154 * V_155 )
{
F_2 ( L_5 ) ;
}
static void F_69 ( struct V_89 * V_90 , bool V_201 )
{
struct V_44 * V_45 = V_90 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_92 * V_92 = F_34 ( V_90 ) ;
struct V_202 * V_203 = V_92 -> V_204 ;
if ( ! V_203 || ! V_203 -> V_205 )
return;
if ( V_201 && V_203 -> V_205 -> V_168 )
return;
if ( ! V_201 && ! V_203 -> V_205 -> V_168 )
return;
if ( ! V_201 && V_203 -> V_205 -> V_200 ) {
F_65 ( V_2 , V_203 -> V_205 -> V_200 , false ) ;
V_203 -> V_205 -> V_200 = NULL ;
}
V_203 -> V_205 -> V_168 = V_201 ;
F_70 ( L_6 ,
V_201 ? L_7 : L_8 , V_203 -> V_205 -> V_206 , V_92 -> V_207 ) ;
}
static int F_71 ( struct V_1 * V_2 )
{
int V_13 , V_62 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_208 ; V_13 ++ )
V_2 -> V_14 . V_205 [ V_13 ] = NULL ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_208 ; V_13 ++ ) {
V_2 -> V_14 . V_205 [ V_13 ] = F_72 ( sizeof( struct V_209 ) , V_210 ) ;
if ( V_2 -> V_14 . V_205 [ V_13 ] ) {
V_2 -> V_14 . V_205 [ V_13 ] -> V_206 = V_211 [ V_13 ] ;
V_2 -> V_14 . V_205 [ V_13 ] -> V_212 = V_13 ;
} else {
for ( V_62 = 0 ; V_62 < V_13 ; V_62 ++ ) {
F_73 ( V_2 -> V_14 . V_205 [ V_62 ] ) ;
V_2 -> V_14 . V_205 [ V_62 ] = NULL ;
}
F_74 ( L_9 ) ;
return - V_213 ;
}
}
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_208 ; V_13 ++ ) {
F_73 ( V_2 -> V_14 . V_205 [ V_13 ] ) ;
V_2 -> V_14 . V_205 [ V_13 ] = NULL ;
}
}
static void F_76 ( struct V_214 * V_6 , bool V_201 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
T_1 V_215 ;
V_215 = F_5 ( V_216 [ V_23 -> V_20 ] ) & ~ 1 ;
F_14 ( V_216 [ V_23 -> V_20 ] , V_215 | ( V_201 ? 1 : 0 ) ) ;
}
static void F_77 ( struct V_214 * V_6 , bool V_201 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
F_14 ( V_217 + V_23 -> V_26 , V_201 ? 1 : 0 ) ;
}
static int F_78 ( struct V_214 * V_6 ,
struct V_218 * V_219 ,
int V_220 , int V_221 , int V_222 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_223 * V_224 ;
struct V_218 * V_225 ;
struct V_226 * V_227 ;
struct V_228 * V_229 ;
T_4 V_230 , V_231 ;
T_5 V_232 , V_233 , V_234 ;
T_1 V_235 = F_79 ( V_236 ) ;
T_1 V_237 , V_238 ;
int V_239 ;
bool V_240 = false ;
struct V_241 V_242 ;
if ( ! V_222 && ! V_6 -> V_243 -> V_219 ) {
F_58 ( L_10 ) ;
return 0 ;
}
if ( V_222 ) {
V_224 = F_80 ( V_219 ) ;
V_225 = V_219 ;
} else {
V_224 = F_80 ( V_6 -> V_243 -> V_219 ) ;
V_225 = V_6 -> V_243 -> V_219 ;
}
V_227 = V_224 -> V_227 ;
V_229 = F_81 ( V_227 ) ;
V_239 = F_82 ( V_229 , false ) ;
if ( F_83 ( V_239 != 0 ) )
return V_239 ;
if ( V_222 ) {
V_230 = F_84 ( V_229 ) ;
} else {
V_239 = F_85 ( V_229 , V_244 , & V_230 ) ;
if ( F_83 ( V_239 != 0 ) ) {
F_86 ( V_229 ) ;
return - V_32 ;
}
}
F_87 ( V_229 , & V_231 ) ;
F_86 ( V_229 ) ;
switch ( V_225 -> V_245 -> V_245 ) {
case V_246 :
V_232 = ( F_88 ( V_247 ) |
F_89 ( V_248 ) ) ;
break;
case V_249 :
case V_250 :
V_232 = ( F_88 ( V_251 ) |
F_89 ( V_252 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_253 ) ;
#endif
break;
case V_254 :
case V_255 :
V_232 = ( F_88 ( V_251 ) |
F_89 ( V_256 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_253 ) ;
#endif
break;
case V_257 :
case V_258 :
V_232 = ( F_88 ( V_251 ) |
F_89 ( V_259 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_253 ) ;
#endif
break;
case V_260 :
V_232 = ( F_88 ( V_251 ) |
F_89 ( V_261 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_253 ) ;
#endif
break;
case V_262 :
case V_263 :
V_232 = ( F_88 ( V_264 ) |
F_89 ( V_265 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_266 ) ;
#endif
break;
case V_267 :
case V_268 :
V_232 = ( F_88 ( V_264 ) |
F_89 ( V_269 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_266 ) ;
#endif
V_240 = true ;
break;
case V_270 :
case V_271 :
V_232 = ( F_88 ( V_264 ) |
F_89 ( V_272 ) ) ;
#ifdef F_90
V_235 = F_79 ( V_266 ) ;
#endif
V_240 = true ;
break;
default:
F_74 ( L_11 ,
F_91 ( V_225 -> V_245 -> V_245 , & V_242 ) ) ;
return - V_32 ;
}
if ( F_92 ( V_231 , V_273 ) == V_274 ) {
unsigned V_275 , V_276 , V_277 , V_278 , V_279 ;
V_275 = F_92 ( V_231 , V_280 ) ;
V_276 = F_92 ( V_231 , V_281 ) ;
V_277 = F_92 ( V_231 , V_282 ) ;
V_278 = F_92 ( V_231 , V_283 ) ;
V_279 = F_92 ( V_231 , V_284 ) ;
V_232 |= F_93 ( V_279 ) ;
V_232 |= F_94 ( V_285 ) ;
V_232 |= F_95 ( V_278 ) ;
V_232 |= F_96 ( V_275 ) ;
V_232 |= F_97 ( V_276 ) ;
V_232 |= F_98 ( V_277 ) ;
} else if ( F_92 ( V_231 , V_273 ) == V_286 ) {
V_232 |= F_94 ( V_287 ) ;
}
V_234 = F_92 ( V_231 , V_288 ) ;
V_232 |= F_99 ( V_234 ) ;
F_76 ( V_6 , false ) ;
F_14 ( V_25 + V_23 -> V_26 , 0 ) ;
F_14 ( V_28 + V_23 -> V_26 ,
F_15 ( V_230 ) ) ;
F_14 ( V_73 + V_23 -> V_26 ,
F_15 ( V_230 ) ) ;
F_14 ( V_29 + V_23 -> V_26 ,
( T_1 ) V_230 & V_289 ) ;
F_14 ( V_74 + V_23 -> V_26 ,
( T_1 ) V_230 & V_289 ) ;
F_14 ( V_290 + V_23 -> V_26 , V_232 ) ;
F_14 ( V_291 + V_23 -> V_26 , V_235 ) ;
F_100 ( V_292 + V_23 -> V_26 ,
( V_240 ? V_293 : 0 ) ,
~ V_293 ) ;
if ( V_240 )
F_58 ( L_12 ) ;
F_14 ( V_294 + V_23 -> V_26 , 0 ) ;
F_14 ( V_295 + V_23 -> V_26 , 0 ) ;
F_14 ( V_296 + V_23 -> V_26 , 0 ) ;
F_14 ( V_297 + V_23 -> V_26 , 0 ) ;
F_14 ( V_298 + V_23 -> V_26 , V_225 -> V_299 ) ;
F_14 ( V_300 + V_23 -> V_26 , V_225 -> V_301 ) ;
V_233 = V_225 -> V_302 [ 0 ] / V_225 -> V_245 -> V_303 [ 0 ] ;
F_14 ( V_304 + V_23 -> V_26 , V_233 ) ;
F_77 ( V_6 , true ) ;
F_14 ( V_305 + V_23 -> V_26 ,
V_225 -> V_301 ) ;
V_220 &= ~ 3 ;
V_221 &= ~ 1 ;
F_14 ( V_306 + V_23 -> V_26 ,
( V_220 << 16 ) | V_221 ) ;
V_237 = V_6 -> V_155 . V_307 ;
V_238 = ( V_6 -> V_155 . V_308 + 1 ) & ~ 1 ;
F_14 ( V_309 + V_23 -> V_26 ,
( V_237 << 16 ) | V_238 ) ;
F_14 ( V_77 + V_23 -> V_26 , 0 ) ;
if ( ! V_222 && V_219 && V_219 != V_6 -> V_243 -> V_219 ) {
V_224 = F_80 ( V_219 ) ;
V_229 = F_81 ( V_224 -> V_227 ) ;
V_239 = F_82 ( V_229 , true ) ;
if ( F_83 ( V_239 != 0 ) )
return V_239 ;
F_101 ( V_229 ) ;
F_86 ( V_229 ) ;
}
F_63 ( V_2 ) ;
return 0 ;
}
static void F_102 ( struct V_214 * V_6 ,
struct V_154 * V_155 )
{
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( V_155 -> V_175 & V_176 )
F_14 ( V_310 + V_23 -> V_26 ,
V_311 ) ;
else
F_14 ( V_310 + V_23 -> V_26 , 0 ) ;
}
static void F_103 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
int V_13 ;
F_58 ( L_13 , V_23 -> V_20 ) ;
F_14 ( V_312 + V_23 -> V_26 ,
( ( 0 << V_313 ) |
( 0 << V_314 ) ) ) ;
F_14 ( V_315 + V_23 -> V_26 ,
V_316 ) ;
F_14 ( V_317 + V_23 -> V_26 ,
V_318 ) ;
F_14 ( V_319 + V_23 -> V_26 ,
( ( 0 << V_320 ) |
( 0 << V_321 ) ) ) ;
F_14 ( V_322 + V_23 -> V_26 , 0 ) ;
F_14 ( V_323 + V_23 -> V_26 , 0 ) ;
F_14 ( V_324 + V_23 -> V_26 , 0 ) ;
F_14 ( V_325 + V_23 -> V_26 , 0 ) ;
F_14 ( V_326 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_327 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_328 + V_23 -> V_26 , 0xffff ) ;
F_14 ( V_329 + V_23 -> V_26 , 0 ) ;
F_14 ( V_330 + V_23 -> V_26 , 0x00000007 ) ;
F_14 ( V_331 + V_23 -> V_26 , 0 ) ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ ) {
F_14 ( V_332 + V_23 -> V_26 ,
( V_23 -> V_333 [ V_13 ] << 20 ) |
( V_23 -> V_334 [ V_13 ] << 10 ) |
( V_23 -> V_335 [ V_13 ] << 0 ) ) ;
}
F_14 ( V_336 + V_23 -> V_26 ,
( ( 0 << V_337 ) |
( 0 << V_338 ) |
F_104 ( 0 ) |
( 0 << V_339 ) ) ) ;
F_14 ( V_340 + V_23 -> V_26 ,
( ( 0 << V_341 ) |
( 0 << V_342 ) ) ) ;
F_14 ( V_343 + V_23 -> V_26 ,
( ( 0 << V_344 ) |
( 0 << V_345 ) ) ) ;
F_14 ( V_346 + V_23 -> V_26 ,
( ( 0 << V_347 ) |
( 0 << V_348 ) ) ) ;
F_14 ( 0x1a50 + V_23 -> V_26 , 0 ) ;
}
static int F_105 ( struct V_89 * V_90 )
{
struct V_92 * V_92 = F_34 ( V_90 ) ;
struct V_202 * V_203 = V_92 -> V_204 ;
switch ( V_92 -> V_207 ) {
case V_349 :
return V_203 -> V_350 ? 1 : 0 ;
case V_351 :
return V_203 -> V_350 ? 3 : 2 ;
case V_352 :
return V_203 -> V_350 ? 5 : 4 ;
case V_353 :
return 6 ;
default:
F_74 ( L_14 , V_92 -> V_207 ) ;
return 0 ;
}
}
static T_1 F_106 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
T_1 V_354 ;
int V_355 ;
if ( F_107 ( F_108 ( V_23 -> V_90 ) ) ) {
if ( V_2 -> clock . V_356 )
return V_357 ;
else
return V_358 ;
} else {
V_355 = F_109 ( V_6 ) ;
if ( V_355 != V_357 )
return V_355 ;
}
V_354 = F_110 ( V_6 ) ;
if ( ! ( V_354 & ( 1 << V_359 ) ) )
return V_359 ;
if ( ! ( V_354 & ( 1 << V_360 ) ) )
return V_360 ;
F_74 ( L_15 ) ;
return V_357 ;
}
static void F_111 ( struct V_214 * V_6 , bool V_361 )
{
struct V_1 * V_2 = V_6 -> V_45 -> V_91 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
T_5 V_362 ;
V_362 = F_5 ( V_363 + V_23 -> V_26 ) ;
if ( V_361 )
V_362 |= V_364 ;
else
V_362 &= ~ V_364 ;
F_14 ( V_363 + V_23 -> V_26 , V_362 ) ;
}
static void F_112 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_45 -> V_91 ;
F_113 ( V_365 + V_23 -> V_26 ,
( V_366 << V_367 ) |
( V_368 << V_369 ) ) ;
}
static void F_114 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_45 -> V_91 ;
F_14 ( V_370 + V_23 -> V_26 ,
F_15 ( V_23 -> V_371 ) ) ;
F_14 ( V_372 + V_23 -> V_26 ,
F_115 ( V_23 -> V_371 ) ) ;
F_113 ( V_365 + V_23 -> V_26 ,
V_373 |
( V_366 << V_367 ) |
( V_368 << V_369 ) ) ;
}
static int F_116 ( struct V_214 * V_6 ,
int V_220 , int V_221 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_1 * V_2 = V_6 -> V_45 -> V_91 ;
int V_374 = 0 , V_375 = 0 ;
int V_376 = V_23 -> V_377 ;
V_23 -> V_378 = V_220 ;
V_23 -> V_379 = V_221 ;
V_220 += V_6 -> V_220 ;
V_221 += V_6 -> V_221 ;
F_70 ( L_16 , V_220 , V_221 , V_6 -> V_220 , V_6 -> V_221 ) ;
if ( V_220 < 0 ) {
V_374 = F_48 ( - V_220 , V_23 -> V_380 - 1 ) ;
V_220 = 0 ;
}
if ( V_221 < 0 ) {
V_375 = F_48 ( - V_221 , V_23 -> V_381 - 1 ) ;
V_221 = 0 ;
}
F_14 ( V_382 + V_23 -> V_26 , ( V_220 << 16 ) | V_221 ) ;
F_14 ( V_383 + V_23 -> V_26 , ( V_374 << 16 ) | V_375 ) ;
F_14 ( V_384 + V_23 -> V_26 ,
( ( V_376 - 1 ) << 16 ) | ( V_23 -> V_385 - 1 ) ) ;
return 0 ;
}
static int F_117 ( struct V_214 * V_6 ,
int V_220 , int V_221 )
{
int V_386 ;
F_111 ( V_6 , true ) ;
V_386 = F_116 ( V_6 , V_220 , V_221 ) ;
F_111 ( V_6 , false ) ;
return V_386 ;
}
static int F_118 ( struct V_214 * V_6 ,
struct V_387 * V_388 ,
T_5 V_389 ,
T_5 V_299 ,
T_5 V_301 ,
T_6 V_390 ,
T_6 V_391 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_226 * V_227 ;
struct V_228 * V_392 ;
int V_386 ;
if ( ! V_389 ) {
F_112 ( V_6 ) ;
V_227 = NULL ;
goto V_393;
}
if ( ( V_299 > V_23 -> V_380 ) ||
( V_301 > V_23 -> V_381 ) ) {
F_74 ( L_17 , V_299 , V_301 ) ;
return - V_32 ;
}
V_227 = F_119 ( V_388 , V_389 ) ;
if ( ! V_227 ) {
F_74 ( L_18 , V_389 , V_23 -> V_20 ) ;
return - V_394 ;
}
V_392 = F_81 ( V_227 ) ;
V_386 = F_82 ( V_392 , false ) ;
if ( V_386 != 0 ) {
F_120 ( V_227 ) ;
return V_386 ;
}
V_386 = F_85 ( V_392 , V_244 , & V_23 -> V_371 ) ;
F_86 ( V_392 ) ;
if ( V_386 ) {
F_74 ( L_19 , V_386 ) ;
F_120 ( V_227 ) ;
return V_386 ;
}
F_111 ( V_6 , true ) ;
if ( V_299 != V_23 -> V_377 ||
V_301 != V_23 -> V_385 ||
V_390 != V_23 -> V_395 ||
V_391 != V_23 -> V_396 ) {
int V_220 , V_221 ;
V_220 = V_23 -> V_378 + V_23 -> V_395 - V_390 ;
V_221 = V_23 -> V_379 + V_23 -> V_396 - V_391 ;
F_116 ( V_6 , V_220 , V_221 ) ;
V_23 -> V_377 = V_299 ;
V_23 -> V_385 = V_301 ;
V_23 -> V_395 = V_390 ;
V_23 -> V_396 = V_391 ;
}
F_114 ( V_6 ) ;
F_111 ( V_6 , false ) ;
V_393:
if ( V_23 -> V_397 ) {
struct V_228 * V_392 = F_81 ( V_23 -> V_397 ) ;
V_386 = F_82 ( V_392 , true ) ;
if ( F_121 ( V_386 == 0 ) ) {
F_101 ( V_392 ) ;
F_86 ( V_392 ) ;
}
F_120 ( V_23 -> V_397 ) ;
}
V_23 -> V_397 = V_227 ;
return 0 ;
}
static void F_122 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( V_23 -> V_397 ) {
F_111 ( V_6 , true ) ;
F_116 ( V_6 , V_23 -> V_378 ,
V_23 -> V_379 ) ;
F_114 ( V_6 ) ;
F_111 ( V_6 , false ) ;
}
}
static int F_123 ( struct V_214 * V_6 , T_7 * V_398 , T_7 * V_399 ,
T_7 * V_400 , T_5 V_401 ,
struct V_402 * V_403 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_401 ; V_13 ++ ) {
V_23 -> V_333 [ V_13 ] = V_398 [ V_13 ] >> 6 ;
V_23 -> V_334 [ V_13 ] = V_399 [ V_13 ] >> 6 ;
V_23 -> V_335 [ V_13 ] = V_400 [ V_13 ] >> 6 ;
}
F_103 ( V_6 ) ;
return 0 ;
}
static void F_124 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
F_125 ( V_6 ) ;
F_73 ( V_23 ) ;
}
static void F_126 ( struct V_214 * V_6 , int V_155 )
{
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_23 * V_23 = F_36 ( V_6 ) ;
unsigned type ;
switch ( V_155 ) {
case V_404 :
V_23 -> V_168 = true ;
F_127 ( V_6 , V_405 ) ;
F_128 ( V_6 , V_406 ) ;
type = F_129 ( V_2 , V_23 -> V_20 ) ;
F_130 ( V_2 , & V_2 -> V_407 , type ) ;
F_130 ( V_2 , & V_2 -> V_19 , type ) ;
F_131 ( V_6 ) ;
F_103 ( V_6 ) ;
break;
case V_408 :
case V_409 :
case V_410 :
F_132 ( V_6 ) ;
if ( V_23 -> V_168 )
F_128 ( V_6 , V_405 ) ;
F_127 ( V_6 , V_406 ) ;
V_23 -> V_168 = false ;
break;
}
F_133 ( V_2 ) ;
}
static void F_134 ( struct V_214 * V_6 )
{
F_135 ( V_6 , V_406 ) ;
F_136 ( V_6 , V_405 ) ;
F_126 ( V_6 , V_410 ) ;
}
static void F_137 ( struct V_214 * V_6 )
{
F_126 ( V_6 , V_404 ) ;
F_136 ( V_6 , V_406 ) ;
}
static void F_138 ( struct V_214 * V_6 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
struct V_411 V_412 ;
int V_13 ;
F_126 ( V_6 , V_410 ) ;
if ( V_6 -> V_243 -> V_219 ) {
int V_239 ;
struct V_223 * V_224 ;
struct V_228 * V_229 ;
V_224 = F_80 ( V_6 -> V_243 -> V_219 ) ;
V_229 = F_81 ( V_224 -> V_227 ) ;
V_239 = F_82 ( V_229 , true ) ;
if ( F_83 ( V_239 ) )
F_74 ( L_20 ) ;
else {
F_101 ( V_229 ) ;
F_86 ( V_229 ) ;
}
}
F_77 ( V_6 , false ) ;
F_135 ( V_6 , V_405 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
if ( V_2 -> V_14 . V_24 [ V_13 ] &&
V_2 -> V_14 . V_24 [ V_13 ] -> V_168 &&
V_13 != V_23 -> V_20 &&
V_23 -> V_413 == V_2 -> V_14 . V_24 [ V_13 ] -> V_413 ) {
goto V_414;
}
}
switch ( V_23 -> V_413 ) {
case V_360 :
case V_359 :
F_139 ( V_6 , V_23 -> V_20 , V_23 -> V_413 ,
0 , 0 , V_406 , 0 , 0 , 0 , 0 , 0 , false , & V_412 ) ;
break;
default:
break;
}
V_414:
V_23 -> V_413 = V_357 ;
V_23 -> V_415 = 0 ;
V_23 -> V_90 = NULL ;
V_23 -> V_48 = NULL ;
}
static int F_140 ( struct V_214 * V_6 ,
struct V_154 * V_155 ,
struct V_154 * V_416 ,
int V_220 , int V_221 , struct V_218 * V_417 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
if ( ! V_23 -> V_415 )
return - V_32 ;
F_141 ( V_6 , V_416 ) ;
F_142 ( V_6 , V_416 ) ;
F_78 ( V_6 , V_417 , V_220 , V_221 , 0 ) ;
F_143 ( V_6 , V_155 , V_416 ) ;
F_144 ( V_6 ) ;
F_122 ( V_6 ) ;
V_23 -> V_418 = * V_416 ;
return 0 ;
}
static bool F_145 ( struct V_214 * V_6 ,
const struct V_154 * V_155 ,
struct V_154 * V_416 )
{
struct V_23 * V_23 = F_36 ( V_6 ) ;
struct V_44 * V_45 = V_6 -> V_45 ;
struct V_89 * V_90 ;
F_20 (encoder, &dev->mode_config.encoder_list, head) {
if ( V_90 -> V_6 == V_6 ) {
V_23 -> V_90 = V_90 ;
V_23 -> V_48 = F_35 ( V_90 ) ;
break;
}
}
if ( ( V_23 -> V_90 == NULL ) || ( V_23 -> V_48 == NULL ) ) {
V_23 -> V_90 = NULL ;
V_23 -> V_48 = NULL ;
return false ;
}
if ( ! F_146 ( V_6 , V_155 , V_416 ) )
return false ;
if ( F_147 ( V_6 , V_416 ) )
return false ;
V_23 -> V_413 = F_106 ( V_6 ) ;
if ( ( V_23 -> V_413 == V_357 ) &&
! F_107 ( F_108 ( V_23 -> V_90 ) ) )
return false ;
return true ;
}
static int F_148 ( struct V_214 * V_6 , int V_220 , int V_221 ,
struct V_218 * V_417 )
{
return F_78 ( V_6 , V_417 , V_220 , V_221 , 0 ) ;
}
static int F_149 ( struct V_214 * V_6 ,
struct V_218 * V_219 ,
int V_220 , int V_221 , enum V_419 V_420 )
{
return F_78 ( V_6 , V_219 , V_220 , V_221 , 1 ) ;
}
static int F_150 ( struct V_1 * V_2 , int V_421 )
{
struct V_23 * V_23 ;
int V_13 ;
V_23 = F_72 ( sizeof( struct V_23 ) +
( V_422 * sizeof( struct V_47 * ) ) , V_210 ) ;
if ( V_23 == NULL )
return - V_213 ;
F_151 ( V_2 -> V_46 , & V_23 -> V_156 , & V_423 ) ;
F_152 ( & V_23 -> V_156 , 256 ) ;
V_23 -> V_20 = V_421 ;
V_2 -> V_14 . V_24 [ V_421 ] = V_23 ;
V_23 -> V_380 = V_424 ;
V_23 -> V_381 = V_425 ;
V_2 -> V_46 -> V_426 . V_377 = V_23 -> V_380 ;
V_2 -> V_46 -> V_426 . V_385 = V_23 -> V_381 ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ ) {
V_23 -> V_333 [ V_13 ] = V_13 << 2 ;
V_23 -> V_334 [ V_13 ] = V_13 << 2 ;
V_23 -> V_335 [ V_13 ] = V_13 << 2 ;
}
V_23 -> V_26 = V_8 [ V_23 -> V_20 ] ;
V_23 -> V_413 = V_357 ;
V_23 -> V_415 = 0 ;
V_23 -> V_90 = NULL ;
V_23 -> V_48 = NULL ;
F_153 ( & V_23 -> V_156 , & V_427 ) ;
return 0 ;
}
static int F_154 ( void * V_389 )
{
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
V_2 -> V_428 = & F_1 ;
V_2 -> V_429 = & F_3 ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
V_2 -> V_14 . V_15 = F_30 ( V_2 ) ;
switch ( V_2 -> V_84 ) {
case V_85 :
case V_86 :
case V_87 :
V_2 -> V_14 . V_37 = 6 ;
V_2 -> V_14 . V_208 = 6 ;
break;
case V_88 :
V_2 -> V_14 . V_37 = 2 ;
V_2 -> V_14 . V_208 = 2 ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static int F_157 ( void * V_389 )
{
int V_239 , V_13 ;
bool V_386 ;
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_239 = F_158 ( V_2 , V_430 , V_13 + 1 , & V_2 -> V_407 ) ;
if ( V_239 )
return V_239 ;
}
for ( V_13 = 8 ; V_13 < 20 ; V_13 += 2 ) {
V_239 = F_158 ( V_2 , V_430 , V_13 , & V_2 -> V_19 ) ;
if ( V_239 )
return V_239 ;
}
V_239 = F_158 ( V_2 , V_430 , 42 , & V_2 -> V_56 ) ;
if ( V_239 )
return V_239 ;
V_2 -> V_14 . V_198 = true ;
V_2 -> V_46 -> V_426 . V_431 = & V_432 ;
V_2 -> V_46 -> V_426 . V_433 = true ;
V_2 -> V_46 -> V_426 . V_434 = 16384 ;
V_2 -> V_46 -> V_426 . V_435 = 16384 ;
V_2 -> V_46 -> V_426 . V_436 = 24 ;
V_2 -> V_46 -> V_426 . V_437 = 1 ;
V_2 -> V_46 -> V_426 . V_438 = V_2 -> V_71 . V_439 ;
V_239 = F_159 ( V_2 ) ;
if ( V_239 )
return V_239 ;
V_2 -> V_46 -> V_426 . V_434 = 16384 ;
V_2 -> V_46 -> V_426 . V_435 = 16384 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_15 ; V_13 ++ ) {
V_239 = F_150 ( V_2 , V_13 ) ;
if ( V_239 )
return V_239 ;
}
V_386 = F_160 ( V_2 ) ;
if ( V_386 )
F_161 ( V_2 -> V_46 ) ;
else
return - V_32 ;
V_239 = F_71 ( V_2 ) ;
if ( V_239 )
return V_239 ;
V_239 = F_66 ( V_2 ) ;
if ( V_239 )
return V_239 ;
F_162 ( V_2 -> V_46 ) ;
return V_239 ;
}
static int F_163 ( void * V_389 )
{
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
F_73 ( V_2 -> V_14 . V_440 ) ;
F_164 ( V_2 -> V_46 ) ;
F_67 ( V_2 ) ;
F_75 ( V_2 ) ;
F_165 ( V_2 -> V_46 ) ;
V_2 -> V_14 . V_198 = false ;
return 0 ;
}
static int F_166 ( void * V_389 )
{
int V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
F_167 ( V_2 ) ;
F_168 ( V_2 , V_2 -> clock . V_441 ) ;
F_19 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_442 . V_443 ; V_13 ++ ) {
F_65 ( V_2 , & V_2 -> V_14 . V_442 . V_200 [ V_13 ] , false ) ;
}
F_9 ( V_2 ) ;
return 0 ;
}
static int F_169 ( void * V_389 )
{
int V_13 ;
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
F_22 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 . V_442 . V_443 ; V_13 ++ ) {
F_65 ( V_2 , & V_2 -> V_14 . V_442 . V_200 [ V_13 ] , false ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int F_170 ( void * V_389 )
{
return F_169 ( V_389 ) ;
}
static int F_171 ( void * V_389 )
{
struct V_1 * V_2 = (struct V_1 * ) V_389 ;
int V_386 ;
V_386 = F_166 ( V_389 ) ;
if ( V_2 -> V_14 . V_444 ) {
T_8 V_445 = F_172 ( V_2 ,
V_2 -> V_14 . V_444 ) ;
F_173 ( V_2 , V_2 -> V_14 . V_444 ,
V_445 ) ;
}
return V_386 ;
}
static bool F_174 ( void * V_389 )
{
return true ;
}
static int F_175 ( void * V_389 )
{
return 0 ;
}
static int F_176 ( void * V_389 )
{
F_2 ( L_21 ) ;
return 0 ;
}
static void F_177 ( struct V_1 * V_2 ,
int V_6 ,
enum V_446 V_420 )
{
T_1 V_447 , V_448 ;
if ( V_6 >= V_2 -> V_14 . V_15 ) {
F_70 ( L_22 , V_6 ) ;
return;
}
switch ( V_6 ) {
case 0 :
V_447 = V_449 ;
break;
case 1 :
V_447 = V_450 ;
break;
case 2 :
V_447 = V_451 ;
break;
case 3 :
V_447 = V_452 ;
break;
case 4 :
V_447 = V_453 ;
break;
case 5 :
V_447 = V_454 ;
break;
default:
F_70 ( L_22 , V_6 ) ;
return;
}
switch ( V_420 ) {
case V_455 :
V_448 = F_5 ( V_456 + V_447 ) ;
V_448 &= ~ V_457 ;
F_14 ( V_456 + V_447 , V_448 ) ;
break;
case V_458 :
V_448 = F_5 ( V_456 + V_447 ) ;
V_448 |= V_457 ;
F_14 ( V_456 + V_447 , V_448 ) ;
break;
default:
break;
}
}
static void F_178 ( struct V_1 * V_2 ,
int V_6 ,
enum V_446 V_420 )
{
}
static int F_179 ( struct V_1 * V_2 ,
struct V_459 * V_460 ,
unsigned type ,
enum V_446 V_420 )
{
T_1 V_461 ;
if ( type >= V_2 -> V_14 . V_37 ) {
F_70 ( L_23 , type ) ;
return 0 ;
}
switch ( V_420 ) {
case V_455 :
V_461 = F_5 ( V_42 + V_39 [ type ] ) ;
V_461 &= ~ V_462 ;
F_14 ( V_42 + V_39 [ type ] , V_461 ) ;
break;
case V_458 :
V_461 = F_5 ( V_42 + V_39 [ type ] ) ;
V_461 |= V_462 ;
F_14 ( V_42 + V_39 [ type ] , V_461 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_459 * V_460 ,
unsigned type ,
enum V_446 V_420 )
{
switch ( type ) {
case V_463 :
F_177 ( V_2 , 0 , V_420 ) ;
break;
case V_464 :
F_177 ( V_2 , 1 , V_420 ) ;
break;
case V_465 :
F_177 ( V_2 , 2 , V_420 ) ;
break;
case V_466 :
F_177 ( V_2 , 3 , V_420 ) ;
break;
case V_467 :
F_177 ( V_2 , 4 , V_420 ) ;
break;
case V_468 :
F_177 ( V_2 , 5 , V_420 ) ;
break;
case V_469 :
F_178 ( V_2 , 0 , V_420 ) ;
break;
case V_470 :
F_178 ( V_2 , 1 , V_420 ) ;
break;
case V_471 :
F_178 ( V_2 , 2 , V_420 ) ;
break;
case V_472 :
F_178 ( V_2 , 3 , V_420 ) ;
break;
case V_473 :
F_178 ( V_2 , 4 , V_420 ) ;
break;
case V_474 :
F_178 ( V_2 , 5 , V_420 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_459 * V_475 ,
struct V_476 * V_477 )
{
unsigned V_6 = V_477 -> V_478 - 1 ;
T_5 V_479 = F_5 ( V_480 [ V_6 ] . V_4 ) ;
unsigned V_481 = F_129 ( V_2 , V_6 ) ;
switch ( V_477 -> V_482 [ 0 ] ) {
case 0 :
if ( V_479 & V_480 [ V_6 ] . V_483 )
F_14 ( V_484 + V_8 [ V_6 ] , V_485 ) ;
else
F_70 ( L_24 ) ;
if ( F_182 ( V_2 , V_475 , V_481 ) ) {
F_183 ( V_2 -> V_46 , V_6 ) ;
}
F_70 ( L_25 , V_6 + 1 ) ;
break;
case 1 :
if ( V_479 & V_480 [ V_6 ] . V_486 )
F_14 ( V_487 + V_8 [ V_6 ] , V_488 ) ;
else
F_70 ( L_24 ) ;
F_70 ( L_26 , V_6 + 1 ) ;
break;
default:
F_70 ( L_27 , V_477 -> V_478 , V_477 -> V_482 [ 0 ] ) ;
break;
}
return 0 ;
}
static int F_184 ( struct V_1 * V_2 ,
struct V_459 * V_460 ,
unsigned type ,
enum V_446 V_420 )
{
T_1 V_4 ;
if ( type >= V_2 -> V_14 . V_15 ) {
F_74 ( L_28 , type ) ;
return - V_32 ;
}
V_4 = F_5 ( V_489 + V_8 [ type ] ) ;
if ( V_420 == V_455 )
F_14 ( V_489 + V_8 [ type ] ,
V_4 & ~ V_490 ) ;
else
F_14 ( V_489 + V_8 [ type ] ,
V_4 | V_490 ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 ,
struct V_459 * V_475 ,
struct V_476 * V_477 )
{
unsigned long V_175 ;
unsigned V_20 ;
struct V_23 * V_23 ;
struct V_491 * V_492 ;
V_20 = ( V_477 -> V_478 - 8 ) >> 1 ;
V_23 = V_2 -> V_14 . V_24 [ V_20 ] ;
if ( V_20 >= V_2 -> V_14 . V_15 ) {
F_74 ( L_28 , V_20 ) ;
return - V_32 ;
}
if ( F_5 ( V_493 + V_8 [ V_20 ] ) &
V_494 )
F_14 ( V_493 + V_8 [ V_20 ] ,
V_495 ) ;
if ( V_23 == NULL )
return 0 ;
F_186 ( & V_2 -> V_46 -> V_496 , V_175 ) ;
V_492 = V_23 -> V_497 ;
if ( V_23 -> V_498 != V_499 ) {
F_187 ( L_29
L_30 ,
V_23 -> V_498 ,
V_499 ) ;
F_188 ( & V_2 -> V_46 -> V_496 , V_175 ) ;
return 0 ;
}
V_23 -> V_498 = V_500 ;
V_23 -> V_497 = NULL ;
if ( V_492 -> V_501 )
F_189 ( & V_23 -> V_156 , V_492 -> V_501 ) ;
F_188 ( & V_2 -> V_46 -> V_496 , V_175 ) ;
F_190 ( & V_23 -> V_156 ) ;
F_191 ( & V_492 -> V_502 ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_2 ,
struct V_459 * V_475 ,
struct V_476 * V_477 )
{
T_5 V_479 , V_503 , V_41 ;
unsigned V_35 ;
if ( V_477 -> V_482 [ 0 ] >= V_2 -> V_14 . V_37 ) {
F_70 ( L_27 , V_477 -> V_478 , V_477 -> V_482 [ 0 ] ) ;
return 0 ;
}
V_35 = V_477 -> V_482 [ 0 ] ;
V_479 = F_5 ( V_480 [ V_35 ] . V_4 ) ;
V_503 = V_480 [ V_35 ] . V_35 ;
if ( V_479 & V_503 ) {
V_41 = F_5 ( V_42 + V_39 [ V_35 ] ) ;
V_41 |= V_504 ;
F_14 ( V_42 + V_39 [ V_35 ] , V_41 ) ;
F_191 ( & V_2 -> V_505 ) ;
F_2 ( L_31 , V_35 + 1 ) ;
}
return 0 ;
}
static int F_193 ( void * V_389 ,
enum V_506 V_420 )
{
return 0 ;
}
static int F_194 ( void * V_389 ,
enum V_507 V_420 )
{
return 0 ;
}
static void
F_195 ( struct V_89 * V_90 ,
struct V_154 * V_155 ,
struct V_154 * V_416 )
{
struct V_92 * V_92 = F_34 ( V_90 ) ;
V_92 -> V_508 = V_416 -> clock ;
F_196 ( V_90 , V_410 ) ;
F_102 ( V_90 -> V_6 , V_155 ) ;
if ( F_108 ( V_90 ) == V_509 ) {
F_69 ( V_90 , true ) ;
F_68 ( V_90 , V_416 ) ;
}
}
static void F_197 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_45 -> V_91 ;
struct V_92 * V_92 = F_34 ( V_90 ) ;
struct V_47 * V_48 = F_35 ( V_90 ) ;
if ( ( V_92 -> V_510 &
( V_511 | V_98 ) ) ||
( F_198 ( V_90 ) !=
V_512 ) ) {
struct V_202 * V_203 = V_92 -> V_204 ;
if ( V_203 ) {
V_203 -> V_513 = F_105 ( V_90 ) ;
if ( V_92 -> V_510 & V_511 )
V_203 -> V_205 = V_2 -> V_14 . V_205 [ V_203 -> V_513 ] ;
}
}
F_199 ( V_2 , true ) ;
if ( V_48 ) {
struct V_49 * V_49 = F_21 ( V_48 ) ;
if ( V_49 -> V_514 . V_515 )
F_200 ( V_49 ) ;
if ( V_48 -> V_52 == V_53 )
F_201 ( V_48 ,
V_516 ) ;
}
F_202 ( V_90 ) ;
F_33 ( V_90 ) ;
}
static void F_203 ( struct V_89 * V_90 )
{
struct V_44 * V_45 = V_90 -> V_45 ;
struct V_1 * V_2 = V_45 -> V_91 ;
F_196 ( V_90 , V_404 ) ;
F_199 ( V_2 , false ) ;
}
static void F_204 ( struct V_89 * V_90 )
{
struct V_92 * V_92 = F_34 ( V_90 ) ;
struct V_202 * V_203 ;
F_196 ( V_90 , V_410 ) ;
if ( F_205 ( V_90 ) ) {
if ( F_108 ( V_90 ) == V_509 )
F_69 ( V_90 , false ) ;
V_203 = V_92 -> V_204 ;
V_203 -> V_513 = - 1 ;
}
V_92 -> V_510 = 0 ;
}
static void F_206 ( struct V_89 * V_90 )
{
}
static void F_207 ( struct V_89 * V_90 )
{
}
static void
F_208 ( struct V_89 * V_90 ,
struct V_154 * V_155 ,
struct V_154 * V_416 )
{
}
static void F_209 ( struct V_89 * V_90 )
{
}
static void
F_210 ( struct V_89 * V_90 , int V_155 )
{
}
static bool F_211 ( struct V_89 * V_90 ,
const struct V_154 * V_155 ,
struct V_154 * V_416 )
{
return true ;
}
static void F_212 ( struct V_89 * V_90 )
{
struct V_92 * V_92 = F_34 ( V_90 ) ;
if ( V_92 -> V_97 & ( V_98 ) )
F_213 ( V_92 ) ;
F_73 ( V_92 -> V_204 ) ;
F_214 ( V_90 ) ;
F_73 ( V_92 ) ;
}
static void F_215 ( struct V_1 * V_2 ,
T_5 V_517 ,
T_5 V_518 ,
T_7 V_519 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_89 * V_90 ;
struct V_92 * V_92 ;
F_20 (encoder, &dev->mode_config.encoder_list, head) {
V_92 = F_34 ( V_90 ) ;
if ( V_92 -> V_517 == V_517 ) {
V_92 -> V_97 |= V_518 ;
return;
}
}
V_92 = F_72 ( sizeof( struct V_92 ) , V_210 ) ;
if ( ! V_92 )
return;
V_90 = & V_92 -> V_156 ;
switch ( V_2 -> V_14 . V_15 ) {
case 1 :
V_90 -> V_520 = 0x1 ;
break;
case 2 :
default:
V_90 -> V_520 = 0x3 ;
break;
case 4 :
V_90 -> V_520 = 0xf ;
break;
case 6 :
V_90 -> V_520 = 0x3f ;
break;
}
V_92 -> V_204 = NULL ;
V_92 -> V_517 = V_517 ;
V_92 -> V_207 = ( V_517 & V_521 ) >> V_522 ;
V_92 -> V_97 = V_518 ;
V_92 -> V_177 = V_178 ;
V_92 -> V_523 = V_524 ;
V_92 -> V_525 = false ;
V_92 -> V_519 = V_519 ;
switch ( V_92 -> V_207 ) {
case V_526 :
case V_527 :
F_216 ( V_45 , V_90 , & V_528 ,
V_529 , NULL ) ;
F_217 ( V_90 , & V_530 ) ;
break;
case V_531 :
case V_349 :
case V_351 :
case V_352 :
case V_353 :
if ( V_92 -> V_97 & ( V_98 ) ) {
V_92 -> V_177 = V_532 ;
F_216 ( V_45 , V_90 , & V_528 ,
V_533 , NULL ) ;
V_92 -> V_204 = F_218 ( V_92 ) ;
} else if ( V_92 -> V_97 & ( V_534 ) ) {
F_216 ( V_45 , V_90 , & V_528 ,
V_529 , NULL ) ;
V_92 -> V_204 = F_219 ( V_92 ) ;
} else {
F_216 ( V_45 , V_90 , & V_528 ,
V_535 , NULL ) ;
V_92 -> V_204 = F_219 ( V_92 ) ;
}
F_217 ( V_90 , & V_536 ) ;
break;
case V_537 :
case V_538 :
case V_539 :
case V_540 :
case V_541 :
case V_542 :
case V_543 :
case V_544 :
case V_545 :
V_92 -> V_525 = true ;
if ( V_92 -> V_97 & ( V_98 ) )
F_216 ( V_45 , V_90 , & V_528 ,
V_533 , NULL ) ;
else if ( V_92 -> V_97 & ( V_534 ) )
F_216 ( V_45 , V_90 , & V_528 ,
V_529 , NULL ) ;
else
F_216 ( V_45 , V_90 , & V_528 ,
V_535 , NULL ) ;
F_217 ( V_90 , & V_546 ) ;
break;
}
}
static void F_155 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . V_431 == NULL )
V_2 -> V_14 . V_431 = & V_547 ;
}
static void F_156 ( struct V_1 * V_2 )
{
V_2 -> V_407 . V_548 = V_549 ;
V_2 -> V_407 . V_431 = & V_550 ;
V_2 -> V_19 . V_548 = V_551 ;
V_2 -> V_19 . V_431 = & V_552 ;
V_2 -> V_56 . V_548 = V_553 ;
V_2 -> V_56 . V_431 = & V_554 ;
}
