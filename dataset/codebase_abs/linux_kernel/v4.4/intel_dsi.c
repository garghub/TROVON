static void F_1 ( struct V_1 * V_1 , enum V_2 V_2 )
{
struct V_3 * V_4 = & V_1 -> V_5 . V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 ;
V_11 = V_12 | V_13 |
V_14 | V_15 ;
if ( F_2 ( ( F_3 ( F_4 ( V_2 ) ) & V_11 ) == V_11 , 100 ) )
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_8 * V_9 , T_1 V_16 ,
const T_2 * V_17 , T_1 V_18 )
{
T_1 V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 += 4 ) {
T_1 V_21 = 0 ;
for ( V_20 = 0 ; V_20 < F_7 ( T_1 , V_18 - V_19 , 4 ) ; V_20 ++ )
V_21 |= * V_17 ++ << 8 * V_20 ;
F_8 ( V_16 , V_21 ) ;
}
}
static void F_9 ( struct V_8 * V_9 , T_1 V_16 ,
T_2 * V_17 , T_1 V_18 )
{
T_1 V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 += 4 ) {
T_1 V_21 = F_3 ( V_16 ) ;
for ( V_20 = 0 ; V_20 < F_7 ( T_1 , V_18 - V_19 , 4 ) ; V_20 ++ )
* V_17 ++ = V_21 >> 8 * V_20 ;
}
}
static T_3 F_10 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_26 * V_26 = F_11 ( V_23 ) ;
struct V_6 * V_7 = V_26 -> V_1 -> V_5 . V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
enum V_2 V_2 = V_26 -> V_2 ;
struct V_27 V_28 ;
T_3 V_29 ;
const T_2 * V_30 , * V_17 ;
T_1 V_31 , V_32 , V_33 , V_34 ;
V_29 = F_12 ( & V_28 , V_25 ) ;
if ( V_29 < 0 )
return V_29 ;
V_30 = V_28 . V_30 ;
V_17 = V_28 . V_35 ;
if ( V_25 -> V_36 & V_37 ) {
V_31 = F_13 ( V_2 ) ;
V_32 = V_38 ;
V_33 = F_14 ( V_2 ) ;
V_34 = V_39 ;
} else {
V_31 = F_15 ( V_2 ) ;
V_32 = V_40 ;
V_33 = F_16 ( V_2 ) ;
V_34 = V_41 ;
}
if ( V_28 . V_42 ) {
if ( F_2 ( ( F_3 ( F_4 ( V_2 ) ) & V_32 ) == 0 , 50 ) )
F_5 ( L_2 ) ;
F_6 ( V_9 , V_31 , V_28 . V_35 ,
V_28 . V_42 ) ;
}
if ( V_25 -> V_43 ) {
F_8 ( F_17 ( V_2 ) , V_44 ) ;
}
if ( F_2 ( ( F_3 ( F_4 ( V_2 ) ) & V_34 ) == 0 , 50 ) ) {
F_5 ( L_3 ) ;
}
F_8 ( V_33 , V_30 [ 2 ] << 16 | V_30 [ 1 ] << 8 | V_30 [ 0 ] ) ;
if ( V_25 -> V_43 ) {
V_32 = V_44 ;
if ( F_2 ( ( F_3 ( F_17 ( V_2 ) ) & V_32 ) == V_32 , 50 ) )
F_5 ( L_4 ) ;
F_9 ( V_9 , V_31 , V_25 -> V_45 , V_25 -> V_43 ) ;
}
return 4 + V_28 . V_42 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_46 * V_47 )
{
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_46 * V_47 )
{
return 0 ;
}
static struct V_26 * F_20 ( struct V_1 * V_1 ,
enum V_2 V_2 )
{
struct V_26 * V_23 ;
struct V_46 * V_48 ;
V_23 = F_21 ( sizeof( * V_23 ) , V_49 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_5 . V_50 = & V_51 ;
V_23 -> V_1 = V_1 ;
V_23 -> V_2 = V_2 ;
V_48 = F_21 ( sizeof( * V_48 ) , V_49 ) ;
if ( ! V_48 ) {
F_22 ( V_23 ) ;
return NULL ;
}
V_48 -> V_23 = & V_23 -> V_5 ;
V_23 -> V_48 = V_48 ;
return V_23 ;
}
static int F_23 ( struct V_1 * V_1 , T_1 V_52 , bool V_53 ,
enum V_2 V_2 )
{
struct V_3 * V_4 = & V_1 -> V_5 . V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
T_1 V_11 ;
if ( V_53 )
V_52 &= ~ V_54 ;
else
V_52 |= V_54 ;
F_8 ( F_17 ( V_2 ) , V_55 ) ;
if ( V_52 == F_3 ( F_24 ( V_2 ) ) )
F_5 ( L_5 , V_52 ) ;
F_8 ( F_24 ( V_2 ) , V_52 ) ;
V_11 = V_55 ;
if ( F_2 ( ( F_3 ( F_17 ( V_2 ) ) & V_11 ) == V_11 , 100 ) )
F_5 ( L_6 , V_52 ) ;
return 0 ;
}
static void F_25 ( struct V_8 * V_9 )
{
F_26 ( & V_9 -> V_56 ) ;
F_27 ( V_9 , 0x08 , 0x0001 ) ;
F_27 ( V_9 , 0x0F , 0x0005 ) ;
F_27 ( V_9 , 0x0F , 0x0025 ) ;
F_28 ( 150 ) ;
F_27 ( V_9 , 0x0F , 0x0000 ) ;
F_27 ( V_9 , 0x08 , 0x0000 ) ;
F_29 ( & V_9 -> V_56 ) ;
}
static inline bool F_30 ( struct V_1 * V_1 )
{
return V_1 -> V_57 == V_58 ;
}
static inline bool F_31 ( struct V_1 * V_1 )
{
return V_1 -> V_57 == V_59 ;
}
static bool F_32 ( struct V_60 * V_4 ,
struct V_61 * V_62 )
{
struct V_1 * V_1 = F_33 ( V_4 , struct V_1 ,
V_5 ) ;
struct V_63 * V_63 = V_1 -> V_64 ;
struct V_65 * V_66 = V_63 -> V_67 . V_66 ;
struct V_65 * V_68 = & V_62 -> V_5 . V_68 ;
F_34 ( L_7 ) ;
if ( V_66 )
F_35 ( V_66 , V_68 ) ;
V_68 -> V_36 = 0 ;
return true ;
}
static void F_36 ( struct V_60 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_21 ;
F_34 ( L_7 ) ;
F_38 (port, intel_dsi->ports) {
V_21 = F_3 ( F_39 ( V_2 ) ) ;
F_8 ( F_39 ( V_2 ) , V_21 | V_69 ) ;
F_40 ( 2000 , 2500 ) ;
V_21 = F_3 ( F_41 ( V_2 ) ) ;
V_21 &= ~ V_70 ;
V_21 |= ( V_71 | V_72 ) ;
F_8 ( F_41 ( V_2 ) , V_21 ) ;
F_40 ( 2 , 3 ) ;
V_21 = F_3 ( F_41 ( V_2 ) ) ;
V_21 &= ~ V_70 ;
V_21 |= ( V_73 | V_72 ) ;
F_8 ( F_41 ( V_2 ) , V_21 ) ;
F_40 ( 1000 , 1500 ) ;
V_21 = F_3 ( F_41 ( V_2 ) ) ;
V_21 &= ~ V_70 ;
V_21 |= V_72 ;
F_8 ( F_41 ( V_2 ) , V_21 ) ;
}
}
static void F_42 ( struct V_60 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_21 ;
F_34 ( L_7 ) ;
F_26 ( & V_9 -> V_56 ) ;
F_27 ( V_9 , 0x04 , 0x0004 ) ;
F_29 ( & V_9 -> V_56 ) ;
F_25 ( V_9 ) ;
F_38 (port, intel_dsi->ports) {
F_8 ( F_41 ( V_2 ) , V_71 ) ;
F_40 ( 2500 , 3000 ) ;
V_21 = F_3 ( F_43 ( V_74 ) ) ;
F_8 ( F_43 ( V_74 ) , V_21 | V_69 ) ;
F_40 ( 1000 , 1500 ) ;
F_8 ( F_41 ( V_2 ) , V_73 ) ;
F_40 ( 2500 , 3000 ) ;
F_8 ( F_41 ( V_2 ) , V_72 ) ;
F_40 ( 2500 , 3000 ) ;
}
}
static void F_44 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
if ( F_45 ( V_7 ) )
F_42 ( V_4 ) ;
else if ( F_46 ( V_7 ) )
F_36 ( V_4 ) ;
}
static void F_47 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_75 * V_75 = F_48 ( V_4 -> V_5 . V_76 ) ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_77 ;
T_1 V_78 ;
if ( V_1 -> V_79 == V_80 ) {
V_77 = F_3 ( V_81 ) ;
V_77 &= ~ V_82 |
V_1 -> V_83 <<
V_84 ;
F_8 ( V_81 , V_77 ) ;
}
F_38 (port, intel_dsi->ports) {
V_78 = F_46 ( V_7 ) ? F_39 ( V_2 ) :
F_43 ( V_2 ) ;
V_77 = F_3 ( V_78 ) ;
V_77 &= ~ V_85 ;
V_77 &= ~ V_86 ;
if ( V_1 -> V_87 == ( ( 1 << V_74 ) | ( 1 << V_88 ) ) ) {
V_77 |= ( V_1 -> V_79 - 1 )
<< V_89 ;
V_77 |= V_75 -> V_90 ?
V_91 :
V_92 ;
}
F_8 ( V_78 , V_77 | V_93 ) ;
F_49 ( V_78 ) ;
}
}
static void F_50 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_77 ;
T_1 V_78 ;
F_38 (port, intel_dsi->ports) {
V_78 = F_46 ( V_7 ) ? F_39 ( V_2 ) :
F_43 ( V_2 ) ;
V_77 = F_3 ( V_78 ) ;
F_8 ( V_78 , V_77 & ~ V_93 ) ;
F_49 ( V_78 ) ;
}
}
static void F_51 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
F_34 ( L_7 ) ;
if ( F_31 ( V_1 ) ) {
F_38 (port, intel_dsi->ports)
F_8 ( F_52 ( V_2 ) , 8 * 4 ) ;
} else {
F_53 ( 20 ) ;
F_38 (port, intel_dsi->ports)
F_23 ( V_1 , V_94 , false , V_2 ) ;
F_53 ( 100 ) ;
F_54 ( V_1 -> V_67 ) ;
F_38 (port, intel_dsi->ports)
F_1 ( V_1 , V_2 ) ;
F_47 ( V_4 ) ;
}
F_55 ( V_1 -> V_64 ) ;
}
static void F_56 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
struct V_75 * V_75 = F_48 ( V_4 -> V_5 . V_76 ) ;
enum V_90 V_90 = V_75 -> V_90 ;
enum V_2 V_2 ;
T_1 V_95 ;
F_34 ( L_7 ) ;
if ( V_1 -> V_96 )
F_57 ( V_1 -> V_96 , 1 ) ;
F_53 ( V_1 -> V_97 ) ;
if ( F_45 ( V_7 ) ) {
V_95 = F_3 ( F_58 ( V_90 ) ) ;
V_95 |= V_98 ;
F_8 ( F_58 ( V_90 ) , V_95 ) ;
V_75 -> V_62 -> V_99 . V_100 =
V_101 |
V_98 | V_102 ;
V_95 = F_3 ( V_103 ) ;
V_95 |= V_104 ;
F_8 ( V_103 , V_95 ) ;
}
F_44 ( V_4 ) ;
F_59 ( V_1 -> V_67 ) ;
F_38 (port, intel_dsi->ports)
F_1 ( V_1 , V_2 ) ;
F_51 ( V_4 ) ;
}
static void F_60 ( struct V_60 * V_4 )
{
F_34 ( L_7 ) ;
}
static void F_61 ( struct V_60 * V_4 )
{
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
F_34 ( L_7 ) ;
F_62 ( V_1 -> V_64 ) ;
if ( F_30 ( V_1 ) ) {
F_38 (port, intel_dsi->ports)
F_23 ( V_1 , V_105 , false , V_2 ) ;
F_53 ( 10 ) ;
}
}
static void F_63 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_77 ;
F_34 ( L_7 ) ;
if ( F_30 ( V_1 ) ) {
F_38 (port, intel_dsi->ports)
F_1 ( V_1 , V_2 ) ;
F_50 ( V_4 ) ;
F_53 ( 2 ) ;
}
F_38 (port, intel_dsi->ports) {
F_8 ( F_41 ( V_2 ) , 0x0 ) ;
F_64 ( V_4 , V_2 ) ;
F_8 ( F_65 ( V_2 ) , V_106 ) ;
V_77 = F_3 ( F_66 ( V_2 ) ) ;
V_77 &= ~ V_107 ;
F_8 ( F_66 ( V_2 ) , V_77 ) ;
F_8 ( F_41 ( V_2 ) , 0x1 ) ;
}
F_67 ( V_1 -> V_67 ) ;
F_38 (port, intel_dsi->ports)
F_1 ( V_1 , V_2 ) ;
}
static void F_68 ( struct V_60 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
struct V_8 * V_9 = V_4 -> V_5 . V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
enum V_2 V_2 ;
T_1 V_21 ;
T_1 V_78 = 0 ;
F_34 ( L_7 ) ;
F_38 (port, intel_dsi->ports) {
F_8 ( F_41 ( V_2 ) , V_72 |
V_71 ) ;
F_40 ( 2000 , 2500 ) ;
F_8 ( F_41 ( V_2 ) , V_72 |
V_73 ) ;
F_40 ( 2000 , 2500 ) ;
F_8 ( F_41 ( V_2 ) , V_72 |
V_71 ) ;
F_40 ( 2000 , 2500 ) ;
if ( F_46 ( V_7 ) )
V_78 = F_39 ( V_2 ) ;
else if ( F_45 ( V_7 ) )
V_78 = F_43 ( V_74 ) ;
if ( F_2 ( ( ( F_3 ( V_78 ) & V_108 )
== 0x00000 ) , 30 ) )
F_5 ( L_8 ) ;
V_21 = F_3 ( V_78 ) ;
F_8 ( V_78 , V_21 & ~ V_69 ) ;
F_40 ( 1000 , 1500 ) ;
F_8 ( F_41 ( V_2 ) , 0x00 ) ;
F_40 ( 2000 , 2500 ) ;
}
F_69 ( V_4 ) ;
}
static void F_70 ( struct V_60 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
T_1 V_21 ;
F_34 ( L_7 ) ;
F_63 ( V_4 ) ;
F_68 ( V_4 ) ;
V_21 = F_3 ( V_103 ) ;
V_21 &= ~ V_104 ;
F_8 ( V_103 , V_21 ) ;
F_71 ( V_1 -> V_67 ) ;
F_53 ( V_1 -> V_109 ) ;
F_53 ( V_1 -> V_110 ) ;
if ( V_1 -> V_96 )
F_57 ( V_1 -> V_96 , 0 ) ;
}
static bool F_72 ( struct V_60 * V_4 ,
enum V_90 * V_90 )
{
struct V_8 * V_9 = V_4 -> V_5 . V_7 -> V_10 ;
struct V_1 * V_1 = F_37 ( & V_4 -> V_5 ) ;
struct V_6 * V_7 = V_4 -> V_5 . V_7 ;
enum V_111 V_112 ;
T_1 V_113 , V_114 , V_33 ;
enum V_2 V_2 ;
F_34 ( L_7 ) ;
V_112 = F_73 ( V_4 ) ;
if ( ! F_74 ( V_9 , V_112 ) )
return false ;
F_38 (port, intel_dsi->ports) {
V_114 = F_3 ( F_66 ( V_2 ) ) ;
V_33 = F_46 ( V_7 ) ? F_39 ( V_2 ) :
F_43 ( V_2 ) ;
V_113 = F_3 ( V_33 ) & V_93 ;
if ( F_45 ( V_7 ) && ! F_75 ( V_7 ) &&
( V_2 == V_88 ) )
V_113 = F_3 ( F_76 ( V_115 ) ) &
V_116 ;
if ( V_113 || ( V_114 & V_117 ) ) {
if ( F_3 ( F_41 ( V_2 ) ) & V_72 ) {
* V_90 = V_2 == V_74 ? V_118 : V_115 ;
return true ;
}
}
}
return false ;
}
static void F_77 ( struct V_60 * V_4 ,
struct V_61 * V_119 )
{
T_1 V_120 = 0 ;
F_34 ( L_7 ) ;
V_119 -> V_99 . V_121 = 0 ;
if ( F_46 ( V_4 -> V_5 . V_7 ) )
V_120 = F_78 ( V_4 , V_119 -> V_122 ) ;
else if ( F_45 ( V_4 -> V_5 . V_7 ) )
V_120 = F_79 ( V_4 , V_119 -> V_122 ) ;
if ( ! V_120 )
return;
V_119 -> V_5 . V_68 . V_123 = V_120 ;
V_119 -> V_124 = V_120 ;
}
static enum V_125
F_80 ( struct V_126 * V_127 ,
struct V_65 * V_128 )
{
struct V_63 * V_63 = F_81 ( V_127 ) ;
struct V_65 * V_66 = V_63 -> V_67 . V_66 ;
int V_129 = F_82 ( V_127 -> V_7 ) -> V_130 ;
F_34 ( L_7 ) ;
if ( V_128 -> V_36 & V_131 ) {
F_34 ( L_9 ) ;
return V_132 ;
}
if ( V_66 ) {
if ( V_128 -> V_133 > V_66 -> V_133 )
return V_134 ;
if ( V_128 -> V_135 > V_66 -> V_135 )
return V_134 ;
if ( V_66 -> clock > V_129 )
return V_136 ;
}
return V_137 ;
}
static T_4 F_83 ( T_1 V_138 , unsigned int V_139 )
{
switch ( V_138 ) {
case V_140 :
default:
return 20 * V_139 ;
case V_141 :
return 10 * V_139 ;
case V_142 :
return 5 * V_139 ;
}
}
static T_4 F_84 ( T_4 V_143 , int V_144 , int V_145 ,
T_4 V_146 )
{
return F_85 ( F_85 ( V_143 * V_144 * V_146 ,
8 * 100 ) , V_145 ) ;
}
static void F_86 ( struct V_3 * V_4 ,
const struct V_65 * V_68 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_75 * V_75 = F_48 ( V_4 -> V_76 ) ;
struct V_1 * V_1 = F_37 ( V_4 ) ;
enum V_2 V_2 ;
unsigned int V_144 = V_75 -> V_62 -> V_122 ;
unsigned int V_145 = V_1 -> V_145 ;
T_4 V_147 , V_148 , V_149 , V_150 , V_151 , V_152 , V_153 ;
V_147 = V_68 -> V_154 ;
V_148 = V_68 -> V_155 - V_68 -> V_154 ;
V_149 = V_68 -> V_156 - V_68 -> V_155 ;
V_150 = V_68 -> V_157 - V_68 -> V_156 ;
if ( V_1 -> V_79 ) {
V_147 /= 2 ;
if ( V_1 -> V_79 == V_80 )
V_147 += V_1 -> V_83 ;
V_148 /= 2 ;
V_149 /= 2 ;
V_150 /= 2 ;
}
V_151 = V_68 -> V_158 - V_68 -> V_159 ;
V_152 = V_68 -> V_160 - V_68 -> V_158 ;
V_153 = V_68 -> V_161 - V_68 -> V_160 ;
V_147 = F_84 ( V_147 , V_144 , V_145 ,
V_1 -> V_146 ) ;
V_148 = F_84 ( V_148 , V_144 , V_145 , V_1 -> V_146 ) ;
V_149 = F_84 ( V_149 , V_144 , V_145 ,
V_1 -> V_146 ) ;
V_150 = F_84 ( V_150 , V_144 , V_145 , V_1 -> V_146 ) ;
F_38 (port, intel_dsi->ports) {
if ( F_46 ( V_7 ) ) {
F_8 ( F_87 ( V_2 ) ,
V_68 -> V_154 ) ;
F_8 ( F_88 ( V_2 ) ,
V_68 -> V_159 ) ;
F_8 ( F_89 ( V_2 ) ,
V_68 -> V_161 ) ;
}
F_8 ( F_90 ( V_2 ) , V_147 ) ;
F_8 ( F_91 ( V_2 ) , V_148 ) ;
F_8 ( F_92 ( V_2 ) , V_149 ) ;
F_8 ( F_93 ( V_2 ) , V_150 ) ;
F_8 ( F_94 ( V_2 ) , V_151 ) ;
F_8 ( F_95 ( V_2 ) , V_152 ) ;
F_8 ( F_96 ( V_2 ) , V_153 ) ;
}
}
static void F_97 ( struct V_60 * V_60 )
{
struct V_3 * V_4 = & V_60 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_75 * V_75 = F_48 ( V_4 -> V_76 ) ;
struct V_1 * V_1 = F_37 ( V_4 ) ;
const struct V_65 * V_68 = & V_75 -> V_62 -> V_5 . V_68 ;
enum V_2 V_2 ;
unsigned int V_144 = V_75 -> V_62 -> V_122 ;
T_1 V_21 , V_95 ;
T_4 V_162 ;
F_34 ( L_10 , F_98 ( V_75 -> V_90 ) ) ;
V_162 = V_68 -> V_154 ;
if ( V_1 -> V_79 ) {
V_162 /= 2 ;
if ( V_1 -> V_79 == V_80 )
V_162 += V_1 -> V_83 ;
}
F_38 (port, intel_dsi->ports) {
if ( F_45 ( V_7 ) ) {
V_95 = F_3 ( F_99 ( V_74 ) ) ;
V_95 &= ~ V_163 ;
F_8 ( F_99 ( V_74 ) , V_95 |
V_140 ) ;
V_95 = F_3 ( F_99 ( V_2 ) ) ;
V_95 &= ~ V_164 ;
F_8 ( F_99 ( V_2 ) , V_95 |
V_165 ) ;
} else if ( F_46 ( V_7 ) ) {
V_95 = F_3 ( F_99 ( V_2 ) ) ;
V_95 &= ~ V_166 ;
if ( V_2 == V_74 )
V_95 |= V_167 ;
else if ( V_2 == V_88 )
V_95 |= V_168 ;
F_8 ( F_99 ( V_2 ) , V_95 ) ;
}
F_8 ( F_17 ( V_2 ) , 0xffffffff ) ;
F_8 ( F_100 ( V_2 ) , 0xffffffff ) ;
F_8 ( F_101 ( V_2 ) , V_1 -> V_169 ) ;
F_8 ( F_102 ( V_2 ) ,
V_68 -> V_159 << V_170 |
V_162 << V_171 ) ;
}
F_86 ( V_4 , V_68 ) ;
V_21 = V_1 -> V_145 << V_172 ;
if ( F_31 ( V_1 ) ) {
V_21 |= V_1 -> V_173 << V_174 ;
V_21 |= V_175 ;
} else {
V_21 |= V_1 -> V_173 << V_176 ;
V_21 |= V_1 -> V_177 ;
}
V_95 = 0 ;
if ( V_1 -> V_178 == 0 )
V_95 |= V_179 ;
if ( V_1 -> V_180 )
V_95 |= V_106 ;
F_38 (port, intel_dsi->ports) {
F_8 ( F_66 ( V_2 ) , V_21 ) ;
if ( F_30 ( V_1 ) &&
V_1 -> V_181 == V_182 ) {
F_8 ( F_103 ( V_2 ) ,
F_84 ( V_68 -> V_157 , V_144 ,
V_1 -> V_145 ,
V_1 -> V_146 ) + 1 ) ;
} else {
F_8 ( F_103 ( V_2 ) ,
F_84 ( V_68 -> V_161 *
V_68 -> V_157 ,
V_144 , V_1 -> V_145 ,
V_1 -> V_146 ) + 1 ) ;
}
F_8 ( F_104 ( V_2 ) , V_1 -> V_183 ) ;
F_8 ( F_105 ( V_2 ) ,
V_1 -> V_184 ) ;
F_8 ( F_106 ( V_2 ) ,
V_1 -> V_185 ) ;
F_8 ( F_107 ( V_2 ) ,
F_83 ( V_1 -> V_186 , 100 ) ) ;
if ( F_46 ( V_7 ) && ( ! V_1 -> V_79 ) ) {
F_8 ( F_107 ( V_2 ==
V_74 ? V_88 : V_74 ) ,
V_1 -> V_187 ) ;
}
F_8 ( F_65 ( V_2 ) , V_95 ) ;
F_8 ( F_107 ( V_2 ) , V_1 -> V_187 ) ;
F_8 ( F_108 ( V_2 ) ,
V_1 -> V_188 ) ;
F_8 ( F_109 ( V_2 ) , V_1 -> V_189 ) ;
F_8 ( F_110 ( V_2 ) , V_1 -> V_190 ) ;
F_8 ( F_111 ( V_2 ) ,
V_1 -> V_191 << V_192 |
V_1 -> V_193 << V_194 ) ;
if ( F_30 ( V_1 ) )
F_8 ( F_112 ( V_2 ) ,
V_1 -> V_195 |
V_1 -> V_181 |
V_196 |
V_197 ) ;
}
}
static void F_113 ( struct V_60 * V_4 )
{
F_34 ( L_7 ) ;
F_97 ( V_4 ) ;
F_114 ( V_4 ) ;
}
static enum V_198
F_115 ( struct V_126 * V_127 , bool V_199 )
{
return V_200 ;
}
static int F_116 ( struct V_126 * V_127 )
{
struct V_63 * V_63 = F_81 ( V_127 ) ;
struct V_65 * V_128 ;
F_34 ( L_7 ) ;
if ( ! V_63 -> V_67 . V_66 ) {
F_34 ( L_11 ) ;
return 0 ;
}
V_128 = F_117 ( V_127 -> V_7 ,
V_63 -> V_67 . V_66 ) ;
if ( ! V_128 ) {
F_34 ( L_12 ) ;
return 0 ;
}
F_118 ( V_127 , V_128 ) ;
return 1 ;
}
static void F_119 ( struct V_126 * V_127 )
{
struct V_63 * V_63 = F_81 ( V_127 ) ;
F_34 ( L_7 ) ;
F_120 ( & V_63 -> V_67 ) ;
F_121 ( V_127 ) ;
F_22 ( V_127 ) ;
}
static void F_122 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_37 ( V_4 ) ;
if ( V_1 -> V_67 ) {
F_123 ( V_1 -> V_67 ) ;
F_124 ( V_1 -> V_67 ) ;
}
if ( V_1 -> V_96 )
F_125 ( V_1 -> V_96 ) ;
F_126 ( V_4 ) ;
}
void F_127 ( struct V_6 * V_7 )
{
struct V_1 * V_1 ;
struct V_60 * V_60 ;
struct V_3 * V_4 ;
struct V_63 * V_63 ;
struct V_126 * V_127 ;
struct V_65 * V_201 , * V_66 = NULL ;
struct V_8 * V_9 = V_7 -> V_10 ;
enum V_2 V_2 ;
unsigned int V_19 ;
F_34 ( L_7 ) ;
if ( ! V_9 -> V_202 . V_203 )
return;
if ( F_45 ( V_7 ) ) {
V_9 -> V_204 = V_205 ;
} else {
F_5 ( L_13 ) ;
return;
}
V_1 = F_21 ( sizeof( * V_1 ) , V_49 ) ;
if ( ! V_1 )
return;
V_63 = F_128 () ;
if ( ! V_63 ) {
F_22 ( V_1 ) ;
return;
}
V_60 = & V_1 -> V_5 ;
V_4 = & V_60 -> V_5 ;
V_1 -> V_64 = V_63 ;
V_127 = & V_63 -> V_5 ;
F_129 ( V_7 , V_4 , & V_206 , V_207 ) ;
V_60 -> V_208 = F_32 ;
V_60 -> V_209 = F_113 ;
V_60 -> V_210 = F_56 ;
V_60 -> V_211 = F_60 ;
V_60 -> V_212 = F_61 ;
V_60 -> V_213 = F_70 ;
V_60 -> V_214 = F_72 ;
V_60 -> V_215 = F_77 ;
V_63 -> V_214 = V_216 ;
V_63 -> V_217 = V_218 ;
if ( V_9 -> V_202 . V_47 . V_2 == V_219 ) {
V_60 -> V_220 = ( 1 << V_118 ) ;
V_1 -> V_87 = ( 1 << V_74 ) ;
} else if ( V_9 -> V_202 . V_47 . V_2 == V_221 ) {
V_60 -> V_220 = ( 1 << V_115 ) ;
V_1 -> V_87 = ( 1 << V_88 ) ;
}
if ( V_9 -> V_202 . V_47 . V_62 -> V_79 )
V_1 -> V_87 = ( ( 1 << V_74 ) | ( 1 << V_88 ) ) ;
F_38 (port, intel_dsi->ports) {
struct V_26 * V_23 ;
V_23 = F_20 ( V_1 , V_2 ) ;
if ( ! V_23 )
goto V_222;
V_1 -> V_223 [ V_2 ] = V_23 ;
}
for ( V_19 = 0 ; V_19 < F_130 ( V_224 ) ; V_19 ++ ) {
V_1 -> V_67 = V_224 [ V_19 ] . F_131 ( V_1 ,
V_224 [ V_19 ] . V_225 ) ;
if ( V_1 -> V_67 )
break;
}
if ( ! V_1 -> V_67 ) {
F_34 ( L_14 ) ;
goto V_222;
}
if ( V_9 -> V_202 . V_47 . V_62 -> V_226 == V_227 ) {
V_1 -> V_96 =
F_132 ( V_7 -> V_7 , L_15 , V_228 ) ;
if ( F_133 ( V_1 -> V_96 ) ) {
F_5 ( L_16 ) ;
V_1 -> V_96 = NULL ;
}
}
V_60 -> type = V_229 ;
V_60 -> V_230 = 0 ;
F_134 ( V_7 , V_127 , & V_231 ,
V_232 ) ;
F_135 ( V_127 , & V_233 ) ;
V_127 -> V_234 . V_235 = V_236 ;
V_127 -> V_237 = false ;
V_127 -> V_238 = false ;
F_136 ( V_63 , V_60 ) ;
F_137 ( V_127 ) ;
F_138 ( V_1 -> V_67 , V_127 ) ;
F_26 ( & V_7 -> V_239 . V_240 ) ;
F_139 ( V_1 -> V_67 ) ;
F_140 (scan, &connector->probed_modes, head) {
if ( ( V_201 -> type & V_241 ) ) {
V_66 = F_117 ( V_7 , V_201 ) ;
break;
}
}
F_29 ( & V_7 -> V_239 . V_240 ) ;
if ( ! V_66 ) {
F_34 ( L_11 ) ;
goto V_222;
}
F_141 ( & V_63 -> V_67 , V_66 , NULL ) ;
F_142 ( V_127 , V_242 ) ;
return;
V_222:
F_143 ( & V_60 -> V_5 ) ;
F_22 ( V_1 ) ;
F_22 ( V_63 ) ;
}
