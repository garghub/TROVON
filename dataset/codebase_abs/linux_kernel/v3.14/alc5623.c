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
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_48 * V_49 = F_10 ( V_2 ) ;
int V_84 , V_47 ;
T_1 V_57 ;
V_57 = F_2 ( V_2 , V_35 ) ;
V_57 &= ~ V_85 ;
switch ( F_14 ( V_82 ) ) {
case 16 :
V_57 |= V_86 ;
break;
case 20 :
V_57 |= V_87 ;
break;
case 24 :
V_57 |= V_88 ;
break;
case 32 :
V_57 |= V_89 ;
break;
default:
return - V_43 ;
}
F_4 ( V_2 , V_35 , V_57 ) ;
V_47 = F_15 ( V_82 ) ;
V_84 = F_9 ( V_2 , V_47 ) ;
if ( V_84 < 0 )
return - V_43 ;
V_84 = V_50 [ V_84 ] . V_40 ;
F_16 ( V_2 -> V_90 , L_1 ,
V_91 , V_49 -> V_52 , V_47 , V_84 ) ;
F_4 ( V_2 , V_92 , V_84 ) ;
return 0 ;
}
static int F_17 ( struct V_21 * V_83 , int V_93 )
{
struct V_1 * V_2 = V_83 -> V_2 ;
T_1 V_94 = V_95 | V_96 ;
T_1 V_97 = F_2 ( V_2 , V_98 ) & ~ V_94 ;
if ( V_93 )
V_97 |= V_94 ;
return F_4 ( V_2 , V_98 , V_97 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = F_10 ( V_2 ) ;
F_7 ( V_2 , V_99 ,
V_100 ,
V_100 ) ;
F_4 ( V_2 , V_101 , V_102 ) ;
F_7 ( V_2 , V_98 ,
V_103 ,
V_103 ) ;
F_19 ( 500 ) ;
F_4 ( V_2 , V_33 , V_104 ) ;
if ( V_49 -> V_105 == 0x22 )
F_4 ( V_2 , V_99 ,
V_106 ) ;
else
F_4 ( V_2 , V_99 ,
V_107 ) ;
F_7 ( V_2 , V_98 ,
V_103 ,
0 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_108 V_109 )
{
switch ( V_109 ) {
case V_110 :
F_18 ( V_2 ) ;
break;
case V_111 :
break;
case V_112 :
F_4 ( V_2 , V_33 ,
V_113 ) ;
F_4 ( V_2 , V_101 ,
V_114 ) ;
break;
case V_115 :
F_4 ( V_2 , V_33 , 0 ) ;
F_4 ( V_2 , V_101 , 0 ) ;
F_4 ( V_2 , V_99 , 0 ) ;
break;
}
V_2 -> V_116 . V_117 = V_109 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_115 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 , V_4 = V_2 -> V_5 -> V_6 ;
T_1 * V_7 = V_2 -> V_8 ;
for ( V_3 = 2 ; V_3 < V_2 -> V_5 -> V_10 ; V_3 += V_4 )
F_4 ( V_2 , V_3 , V_7 [ V_3 ] ) ;
F_20 ( V_2 , V_112 ) ;
if ( V_2 -> V_116 . V_118 == V_110 ) {
F_20 ( V_2 , V_112 ) ;
V_2 -> V_116 . V_117 = V_110 ;
F_20 ( V_2 , V_2 -> V_116 . V_117 ) ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = F_10 ( V_2 ) ;
struct V_119 * V_116 = & V_2 -> V_116 ;
int V_120 ;
V_120 = F_24 ( V_2 , 8 , 16 , V_49 -> V_121 ) ;
if ( V_120 < 0 ) {
F_25 ( V_2 -> V_90 , L_2 , V_120 ) ;
return V_120 ;
}
F_3 ( V_2 ) ;
F_1 ( V_2 ) ;
F_20 ( V_2 , V_112 ) ;
if ( V_49 -> V_122 ) {
F_4 ( V_2 , V_123 ,
V_49 -> V_122 ) ;
}
if ( V_49 -> V_124 ) {
F_4 ( V_2 , V_125 ,
V_49 -> V_124 ) ;
}
switch ( V_49 -> V_105 ) {
case 0x21 :
F_26 ( V_2 , V_126 ,
F_8 ( V_126 ) ) ;
break;
case 0x22 :
F_26 ( V_2 , V_127 ,
F_8 ( V_127 ) ) ;
break;
case 0x23 :
F_26 ( V_2 , V_128 ,
F_8 ( V_128 ) ) ;
break;
default:
return - V_43 ;
}
F_26 ( V_2 , V_129 ,
F_8 ( V_129 ) ) ;
F_27 ( V_116 , V_130 ,
F_8 ( V_130 ) ) ;
F_28 ( V_116 , V_131 , F_8 ( V_131 ) ) ;
switch ( V_49 -> V_105 ) {
case 0x21 :
case 0x22 :
F_27 ( V_116 , V_132 ,
F_8 ( V_132 ) ) ;
F_28 ( V_116 , V_133 ,
F_8 ( V_133 ) ) ;
break;
case 0x23 :
F_28 ( V_116 , V_134 ,
F_8 ( V_134 ) ) ;
break;
default:
return - V_43 ;
}
return V_120 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_115 ) ;
return 0 ;
}
static int F_30 ( struct V_135 * V_136 ,
const struct V_137 * V_105 )
{
struct V_138 * V_139 ;
struct V_48 * V_49 ;
int V_120 , V_140 , V_141 ;
V_140 = F_31 ( V_136 , V_142 ) ;
if ( V_140 < 0 ) {
F_25 ( & V_136 -> V_90 , L_3 ) ;
return - V_143 ;
}
V_140 = ( ( V_140 & 0xff ) << 8 ) | ( V_140 >> 8 ) ;
V_141 = F_32 ( V_136 , V_144 ) ;
if ( V_141 < 0 ) {
F_25 ( & V_136 -> V_90 , L_3 ) ;
return - V_143 ;
}
if ( ( V_140 != 0x10ec ) || ( V_141 != V_105 -> V_145 ) ) {
F_25 ( & V_136 -> V_90 , L_4 ) ;
F_25 ( & V_136 -> V_90 , L_5 ,
0x10ec , V_105 -> V_145 ,
V_140 , V_141 ) ;
return - V_32 ;
}
F_16 ( & V_136 -> V_90 , L_6 , V_141 ) ;
V_49 = F_33 ( & V_136 -> V_90 , sizeof( struct V_48 ) ,
V_146 ) ;
if ( V_49 == NULL )
return - V_147 ;
V_139 = V_136 -> V_90 . V_148 ;
if ( V_139 ) {
V_49 -> V_122 = V_139 -> V_122 ;
V_49 -> V_124 = V_139 -> V_124 ;
}
V_49 -> V_105 = V_141 ;
switch ( V_49 -> V_105 ) {
case 0x21 :
V_149 . V_150 = L_7 ;
break;
case 0x22 :
V_149 . V_150 = L_8 ;
break;
case 0x23 :
V_149 . V_150 = L_9 ;
break;
default:
return - V_43 ;
}
F_34 ( V_136 , V_49 ) ;
V_49 -> V_121 = V_151 ;
V_120 = F_35 ( & V_136 -> V_90 ,
& V_152 , & V_149 , 1 ) ;
if ( V_120 != 0 )
F_25 ( & V_136 -> V_90 , L_10 , V_120 ) ;
return V_120 ;
}
static int F_36 ( struct V_135 * V_136 )
{
F_37 ( & V_136 -> V_90 ) ;
return 0 ;
}
