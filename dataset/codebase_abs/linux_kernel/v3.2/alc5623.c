static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 = V_2 -> V_8 ;
V_2 -> V_9 = 1 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 -> V_10 ; V_3 += V_4 )
V_7 [ V_3 ] = F_2 ( V_2 , V_3 ) ;
V_2 -> V_9 = 0 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_11 , 0 ) ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 , int V_16 )
{
F_4 ( V_13 -> V_2 , V_17 , 0x46 ) ;
switch ( V_16 ) {
case V_18 :
F_4 ( V_13 -> V_2 , V_19 , 0xFFFF ) ;
break;
case V_20 :
F_4 ( V_13 -> V_2 , V_19 , 0 ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_21 * V_22 , int V_23 ,
int V_24 , unsigned int V_25 , unsigned int V_26 )
{
int V_3 ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_27 = 0 , V_28 = 0 ;
T_1 V_29 ;
if ( V_23 < V_30 || V_23 > V_31 )
return - V_32 ;
F_7 ( V_2 , V_33 ,
V_34 ,
0 ) ;
V_29 = F_2 ( V_2 , V_35 ) ;
if ( V_29 & V_36 )
return 0 ;
if ( ! V_25 || ! V_26 )
return 0 ;
switch ( V_23 ) {
case V_30 :
for ( V_3 = 0 ; V_3 < F_8 ( V_37 ) ; V_3 ++ ) {
if ( V_37 [ V_3 ] . V_38 == V_25
&& V_37 [ V_3 ] . V_39 == V_26 ) {
V_28 = V_37 [ V_3 ] . V_40 ;
break;
}
}
break;
case V_31 :
for ( V_3 = 0 ; V_3 < F_8 ( V_41 ) ; V_3 ++ ) {
if ( V_41 [ V_3 ] . V_38 == V_25
&& V_41 [ V_3 ] . V_39 == V_26 ) {
V_27 = V_42 ;
V_28 = V_41 [ V_3 ] . V_40 ;
break;
}
}
break;
default:
return - V_43 ;
}
if ( ! V_28 )
return - V_43 ;
F_4 ( V_2 , V_44 , V_27 ) ;
F_4 ( V_2 , V_45 , V_28 ) ;
F_7 ( V_2 , V_33 ,
V_34 ,
V_34 ) ;
V_27 |= V_46 ;
F_4 ( V_2 , V_44 , V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_47 )
{
struct V_48 * V_49 = F_10 ( V_2 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < F_8 ( V_50 ) ; V_3 ++ ) {
if ( V_50 [ V_3 ] . V_51 * V_47 == V_49 -> V_52 )
return V_3 ;
}
return - V_43 ;
}
static int F_11 ( struct V_21 * V_22 ,
int V_53 , unsigned int V_54 , int V_55 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_48 * V_49 = F_10 ( V_2 ) ;
switch ( V_54 ) {
case 8192000 :
case 11289600 :
case 12288000 :
case 16384000 :
case 16934400 :
case 18432000 :
case 22579200 :
case 24576000 :
V_49 -> V_52 = V_54 ;
return 0 ;
}
return - V_43 ;
}
static int F_12 ( struct V_21 * V_22 ,
unsigned int V_56 )
{
struct V_1 * V_2 = V_22 -> V_2 ;
T_1 V_57 = 0 ;
switch ( V_56 & V_58 ) {
case V_59 :
V_57 = V_60 ;
break;
case V_61 :
V_57 = V_36 ;
break;
default:
return - V_43 ;
}
switch ( V_56 & V_62 ) {
case V_63 :
V_57 |= V_64 ;
break;
case V_65 :
V_57 |= V_66 ;
break;
case V_67 :
V_57 |= V_68 ;
break;
case V_69 :
V_57 |= V_70 ;
break;
case V_71 :
V_57 |= V_70 | V_72 ;
break;
default:
return - V_43 ;
}
switch ( V_56 & V_73 ) {
case V_74 :
break;
case V_75 :
V_57 |= V_76 ;
break;
case V_77 :
V_57 |= V_76 ;
break;
case V_78 :
break;
default:
return - V_43 ;
}
return F_4 ( V_2 , V_35 , V_57 ) ;
}
static int F_13 ( struct V_79 * V_80 ,
struct V_81 * V_82 , struct V_21 * V_83 )
{
struct V_84 * V_85 = V_80 -> V_86 ;
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_48 * V_49 = F_10 ( V_2 ) ;
int V_87 , V_47 ;
T_1 V_57 ;
V_57 = F_2 ( V_2 , V_35 ) ;
V_57 &= ~ V_88 ;
switch ( F_14 ( V_82 ) ) {
case V_89 :
V_57 |= V_90 ;
break;
case V_91 :
V_57 |= V_92 ;
break;
case V_93 :
V_57 |= V_94 ;
break;
case V_95 :
V_57 |= V_96 ;
break;
default:
return - V_43 ;
}
F_4 ( V_2 , V_35 , V_57 ) ;
V_47 = F_15 ( V_82 ) ;
V_87 = F_9 ( V_2 , V_47 ) ;
if ( V_87 < 0 )
return - V_43 ;
V_87 = V_50 [ V_87 ] . V_40 ;
F_16 ( V_2 -> V_97 , L_1 ,
V_98 , V_49 -> V_52 , V_47 , V_87 ) ;
F_4 ( V_2 , V_99 , V_87 ) ;
return 0 ;
}
static int F_17 ( struct V_21 * V_83 , int V_100 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_101 = V_102 | V_103 ;
T_1 V_104 = F_2 ( V_2 , V_105 ) & ~ V_101 ;
if ( V_100 )
V_104 |= V_101 ;
return F_4 ( V_2 , V_105 , V_104 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = F_10 ( V_2 ) ;
F_7 ( V_2 , V_106 ,
V_107 ,
V_107 ) ;
F_4 ( V_2 , V_108 , V_109 ) ;
F_7 ( V_2 , V_105 ,
V_110 ,
V_110 ) ;
F_19 ( 500 ) ;
F_4 ( V_2 , V_33 , V_111 ) ;
if ( V_49 -> V_112 == 0x22 )
F_4 ( V_2 , V_106 ,
V_113 ) ;
else
F_4 ( V_2 , V_106 ,
V_114 ) ;
F_7 ( V_2 , V_105 ,
V_110 ,
0 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_115 V_116 )
{
switch ( V_116 ) {
case V_117 :
F_18 ( V_2 ) ;
break;
case V_118 :
break;
case V_119 :
F_4 ( V_2 , V_33 ,
V_120 ) ;
F_4 ( V_2 , V_108 ,
V_121 ) ;
break;
case V_122 :
F_4 ( V_2 , V_33 , 0 ) ;
F_4 ( V_2 , V_108 , 0 ) ;
F_4 ( V_2 , V_106 , 0 ) ;
break;
}
V_2 -> V_123 . V_124 = V_116 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_125 )
{
F_20 ( V_2 , V_122 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 = V_2 -> V_8 ;
for ( V_3 = 2 ; V_3 < V_2 -> V_5 -> V_10 ; V_3 += V_4 )
F_4 ( V_2 , V_3 , V_7 [ V_3 ] ) ;
F_20 ( V_2 , V_119 ) ;
if ( V_2 -> V_123 . V_126 == V_117 ) {
F_20 ( V_2 , V_119 ) ;
V_2 -> V_123 . V_124 = V_117 ;
F_20 ( V_2 , V_2 -> V_123 . V_124 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = F_10 ( V_2 ) ;
struct V_127 * V_123 = & V_2 -> V_123 ;
int V_128 ;
V_128 = F_24 ( V_2 , 8 , 16 , V_49 -> V_129 ) ;
if ( V_128 < 0 ) {
F_25 ( V_2 -> V_97 , L_2 , V_128 ) ;
return V_128 ;
}
F_3 ( V_2 ) ;
F_1 ( V_2 ) ;
F_20 ( V_2 , V_119 ) ;
if ( V_49 -> V_130 ) {
F_4 ( V_2 , V_131 ,
V_49 -> V_130 ) ;
}
if ( V_49 -> V_132 ) {
F_4 ( V_2 , V_133 ,
V_49 -> V_132 ) ;
}
switch ( V_49 -> V_112 ) {
case 0x21 :
F_26 ( V_2 , V_134 ,
F_8 ( V_134 ) ) ;
break;
case 0x22 :
F_26 ( V_2 , V_135 ,
F_8 ( V_135 ) ) ;
break;
case 0x23 :
F_26 ( V_2 , V_136 ,
F_8 ( V_136 ) ) ;
break;
default:
return - V_43 ;
}
F_26 ( V_2 , V_137 ,
F_8 ( V_137 ) ) ;
F_27 ( V_123 , V_138 ,
F_8 ( V_138 ) ) ;
F_28 ( V_123 , V_139 , F_8 ( V_139 ) ) ;
switch ( V_49 -> V_112 ) {
case 0x21 :
case 0x22 :
F_27 ( V_123 , V_140 ,
F_8 ( V_140 ) ) ;
F_28 ( V_123 , V_141 ,
F_8 ( V_141 ) ) ;
break;
case 0x23 :
F_28 ( V_123 , V_142 ,
F_8 ( V_142 ) ) ;
break;
default:
return - V_43 ;
}
return V_128 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_122 ) ;
return 0 ;
}
static int F_30 ( struct V_143 * V_144 ,
const struct V_145 * V_112 )
{
struct V_146 * V_147 ;
struct V_48 * V_49 ;
int V_128 , V_148 , V_149 ;
V_148 = F_31 ( V_144 , V_150 ) ;
if ( V_148 < 0 ) {
F_25 ( & V_144 -> V_97 , L_3 ) ;
return - V_151 ;
}
V_148 = ( ( V_148 & 0xff ) << 8 ) | ( V_148 >> 8 ) ;
V_149 = F_32 ( V_144 , V_152 ) ;
if ( V_149 < 0 ) {
F_25 ( & V_144 -> V_97 , L_3 ) ;
return - V_151 ;
}
if ( ( V_148 != 0x10ec ) || ( V_149 != V_112 -> V_153 ) ) {
F_25 ( & V_144 -> V_97 , L_4 ) ;
F_25 ( & V_144 -> V_97 , L_5 ,
0x10ec , V_112 -> V_153 ,
V_148 , V_149 ) ;
return - V_32 ;
}
F_16 ( & V_144 -> V_97 , L_6 , V_149 ) ;
V_49 = F_33 ( sizeof( struct V_48 ) , V_154 ) ;
if ( V_49 == NULL )
return - V_155 ;
V_147 = V_144 -> V_97 . V_156 ;
if ( V_147 ) {
V_49 -> V_130 = V_147 -> V_130 ;
V_49 -> V_132 = V_147 -> V_132 ;
}
V_49 -> V_112 = V_149 ;
switch ( V_49 -> V_112 ) {
case 0x21 :
V_157 . V_158 = L_7 ;
break;
case 0x22 :
V_157 . V_158 = L_8 ;
break;
case 0x23 :
V_157 . V_158 = L_9 ;
break;
default:
F_34 ( V_49 ) ;
return - V_43 ;
}
F_35 ( V_144 , V_49 ) ;
V_49 -> V_129 = V_159 ;
V_128 = F_36 ( & V_144 -> V_97 ,
& V_160 , & V_157 , 1 ) ;
if ( V_128 != 0 ) {
F_25 ( & V_144 -> V_97 , L_10 , V_128 ) ;
F_34 ( V_49 ) ;
}
return V_128 ;
}
static int F_37 ( struct V_143 * V_144 )
{
struct V_48 * V_49 = F_38 ( V_144 ) ;
F_39 ( & V_144 -> V_97 ) ;
F_34 ( V_49 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_128 ;
V_128 = F_41 ( & V_161 ) ;
if ( V_128 != 0 ) {
F_42 ( V_162 L_11 , V_98 ) ;
return V_128 ;
}
return V_128 ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_161 ) ;
}
