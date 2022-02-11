static bool F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
break;
}
return false ;
}
static inline int F_2 ( struct V_12 * V_13 )
{
return F_3 ( V_13 , V_4 , 0x59B4 ) ;
}
static int F_4 ( struct V_14 * V_15 ,
struct V_16 * V_17 , int V_18 )
{
F_5 ( V_15 -> V_19 , V_20 , 0x46 ) ;
switch ( V_18 ) {
case V_21 :
F_5 ( V_15 -> V_19 , V_8 , 0xFFFF ) ;
break;
case V_22 :
F_5 ( V_15 -> V_19 , V_8 , 0 ) ;
break;
}
return 0 ;
}
static int F_6 ( struct V_23 * V_24 , int V_25 ,
int V_26 , unsigned int V_27 , unsigned int V_28 )
{
int V_29 ;
struct V_30 * V_19 = V_24 -> V_19 ;
int V_31 = 0 , V_32 = 0 ;
T_1 V_3 ;
if ( V_25 < V_33 || V_25 > V_34 )
return - V_35 ;
F_7 ( V_19 , V_36 ,
V_37 ,
0 ) ;
F_7 ( V_19 , V_36 ,
V_38 ,
0 ) ;
V_3 = F_8 ( V_19 , V_39 ) ;
if ( V_3 & V_40 )
return 0 ;
if ( ! V_27 || ! V_28 )
return 0 ;
switch ( V_25 ) {
case V_33 :
for ( V_29 = 0 ; V_29 < F_9 ( V_41 ) ; V_29 ++ ) {
if ( V_41 [ V_29 ] . V_42 == V_27
&& V_41 [ V_29 ] . V_43 == V_28 ) {
V_32 = V_41 [ V_29 ] . V_44 ;
break;
}
}
break;
case V_45 :
for ( V_29 = 0 ; V_29 < F_9 ( V_46 ) ; V_29 ++ ) {
if ( V_46 [ V_29 ] . V_42 == V_27
&& V_46 [ V_29 ] . V_43 == V_28 ) {
V_31 = V_45 ;
V_32 = V_46 [ V_29 ] . V_44 ;
break;
}
}
break;
case V_34 :
for ( V_29 = 0 ; V_29 < F_9 ( V_46 ) ; V_29 ++ ) {
if ( V_46 [ V_29 ] . V_42 == V_27
&& V_46 [ V_29 ] . V_43 == V_28 ) {
V_31 = V_34 ;
V_32 = V_46 [ V_29 ] . V_44 ;
break;
}
}
break;
default:
return - V_35 ;
}
if ( ! V_32 )
return - V_35 ;
F_5 ( V_19 , V_47 , V_31 ) ;
F_5 ( V_19 , V_48 , V_32 ) ;
F_7 ( V_19 , V_36 ,
V_37 ,
V_37 ) ;
F_7 ( V_19 , V_36 ,
V_38 ,
V_38 ) ;
F_7 ( V_19 , V_49 ,
V_50 ,
V_50 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_19 , int V_51 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < F_9 ( V_54 ) ; V_29 ++ ) {
if ( V_54 [ V_29 ] . V_55 * V_51 == V_53 -> V_56 )
return V_29 ;
}
return - V_35 ;
}
static int F_12 ( struct V_23 * V_24 ,
int V_57 , unsigned int V_58 , int V_59 )
{
struct V_30 * V_19 = V_24 -> V_19 ;
struct V_52 * V_53 = F_11 ( V_19 ) ;
switch ( V_58 ) {
case 8192000 :
case 11289600 :
case 12288000 :
case 16384000 :
case 16934400 :
case 18432000 :
case 22579200 :
case 24576000 :
V_53 -> V_56 = V_58 ;
return 0 ;
}
return - V_35 ;
}
static int F_13 ( struct V_23 * V_24 ,
unsigned int V_60 )
{
struct V_30 * V_19 = V_24 -> V_19 ;
T_1 V_61 = 0 ;
switch ( V_60 & V_62 ) {
case V_63 :
V_61 = V_64 ;
break;
case V_65 :
V_61 = V_40 ;
break;
default:
return - V_35 ;
}
switch ( V_60 & V_66 ) {
case V_67 :
V_61 |= V_68 ;
break;
case V_69 :
V_61 |= V_70 ;
break;
case V_71 :
V_61 |= V_72 ;
break;
case V_73 :
V_61 |= V_74 ;
break;
default:
return - V_35 ;
}
switch ( V_60 & V_75 ) {
case V_76 :
break;
case V_77 :
V_61 |= V_78 ;
break;
case V_79 :
V_61 |= V_78 ;
break;
case V_80 :
break;
default:
return - V_35 ;
}
return F_5 ( V_19 , V_39 , V_61 ) ;
}
static int F_14 ( struct V_81 * V_82 ,
struct V_83 * V_84 , struct V_23 * V_85 )
{
struct V_86 * V_87 = V_82 -> V_88 ;
struct V_30 * V_19 = V_87 -> V_19 ;
int V_89 , V_51 ;
T_1 V_61 ;
V_61 = F_8 ( V_19 , V_39 ) ;
V_61 &= ~ V_90 ;
switch ( F_15 ( V_84 ) ) {
case V_91 :
V_61 |= V_92 ;
break;
case V_93 :
V_61 |= V_94 ;
break;
case V_95 :
V_61 |= V_96 ;
break;
default:
return - V_35 ;
}
F_5 ( V_19 , V_39 , V_61 ) ;
V_51 = F_16 ( V_84 ) ;
V_89 = F_10 ( V_19 , V_51 ) ;
if ( V_89 < 0 )
return - V_35 ;
V_89 = V_54 [ V_89 ] . V_44 ;
F_5 ( V_19 , V_97 , V_89 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_85 , int V_98 )
{
struct V_30 * V_19 = V_85 -> V_19 ;
T_1 V_99 = V_100
| V_101 ;
T_1 V_102 = F_8 ( V_19 , V_103 ) & ~ V_99 ;
if ( V_98 )
V_102 |= V_99 ;
return F_5 ( V_19 , V_103 , V_102 ) ;
}
static void F_18 ( struct V_30 * V_19 )
{
F_7 ( V_19 , V_104 ,
V_105 ,
V_105 ) ;
F_7 ( V_19 , V_106 ,
V_107 ,
V_107 ) ;
F_7 ( V_19 , V_103 ,
V_108 ,
V_108 ) ;
F_7 ( V_19 , V_5 ,
V_109 ,
0 ) ;
F_19 ( 500 ) ;
F_7 ( V_19 , V_36 ,
V_110 ,
V_110 ) ;
F_7 ( V_19 , V_104 ,
V_111 ,
V_111 ) ;
F_7 ( V_19 , V_103 ,
V_108 ,
0 ) ;
}
static int F_20 ( struct V_30 * V_19 ,
enum V_112 V_113 )
{
switch ( V_113 ) {
case V_114 :
F_18 ( V_19 ) ;
break;
case V_115 :
break;
case V_116 :
F_7 ( V_19 , V_104 ,
V_117 ,
V_118 ) ;
F_7 ( V_19 , V_36 ,
V_119 ,
V_120 ) ;
F_7 ( V_19 , V_5 ,
V_109 ,
0xffff ^ ( V_121
| V_122 ) ) ;
break;
case V_123 :
F_7 ( V_19 , V_36 ,
V_119 , 0 ) ;
F_7 ( V_19 , V_106 ,
V_124 , 0 ) ;
F_7 ( V_19 , V_104 ,
V_117 , 0 ) ;
break;
}
V_19 -> V_125 . V_126 = V_113 ;
return 0 ;
}
static int F_21 ( struct V_30 * V_19 )
{
F_20 ( V_19 , V_123 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
F_23 ( V_53 -> V_12 ) ;
F_20 ( V_19 , V_116 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
int V_127 ;
V_19 -> V_128 = V_53 -> V_12 ;
V_127 = F_25 ( V_19 , 8 , 16 , V_129 ) ;
if ( V_127 != 0 ) {
F_26 ( V_19 -> V_2 , L_1 , V_127 ) ;
return V_127 ;
}
F_20 ( V_19 , V_116 ) ;
switch ( V_53 -> V_130 ) {
case 0x5c :
F_27 ( V_19 , V_131 ,
F_9 ( V_131 ) ) ;
break;
default:
return - V_35 ;
}
return V_127 ;
}
static int F_28 ( struct V_30 * V_19 )
{
F_20 ( V_19 , V_123 ) ;
return 0 ;
}
static T_2 int F_29 ( struct V_132 * V_133 ,
const struct V_134 * V_130 )
{
struct V_52 * V_53 ;
int V_127 , V_135 , V_136 ;
unsigned int V_137 , V_138 ;
V_53 = F_30 ( & V_133 -> V_2 ,
sizeof( struct V_52 ) , V_139 ) ;
if ( V_53 == NULL )
return - V_140 ;
F_31 ( V_133 , V_53 ) ;
V_53 -> V_12 = F_32 ( V_133 , & V_141 ) ;
if ( F_33 ( V_53 -> V_12 ) ) {
V_127 = F_34 ( V_53 -> V_12 ) ;
F_26 ( & V_133 -> V_2 , L_2 , V_127 ) ;
return V_127 ;
}
V_135 = F_35 ( V_53 -> V_12 , V_10 , & V_137 ) ;
V_136 = F_35 ( V_53 -> V_12 , V_11 , & V_138 ) ;
if ( V_135 != 0 || V_136 != 0 ) {
F_26 ( & V_133 -> V_2 ,
L_3 , V_135 , V_136 ) ;
F_36 ( V_53 -> V_12 ) ;
return - V_142 ;
}
V_138 >>= 8 ;
if ( ( V_137 != 0x10EC ) || ( V_138 != V_130 -> V_143 ) ) {
F_26 ( & V_133 -> V_2 ,
L_4 , V_137 , V_138 ) ;
F_36 ( V_53 -> V_12 ) ;
return - V_35 ;
}
V_127 = F_2 ( V_53 -> V_12 ) ;
if ( V_127 < 0 ) {
F_26 ( & V_133 -> V_2 , L_5 ) ;
F_36 ( V_53 -> V_12 ) ;
return V_127 ;
}
V_53 -> V_130 = V_138 ;
switch ( V_53 -> V_130 ) {
case 0x5c :
V_144 . V_145 = L_6 ;
break;
default:
return - V_35 ;
}
V_127 = F_37 ( & V_133 -> V_2 ,
& V_146 , & V_144 , 1 ) ;
if ( V_127 < 0 ) {
F_26 ( & V_133 -> V_2 , L_7 , V_127 ) ;
F_36 ( V_53 -> V_12 ) ;
return V_127 ;
}
return V_127 ;
}
static int F_38 ( struct V_132 * V_133 )
{
struct V_52 * V_53 = F_39 ( V_133 ) ;
F_40 ( & V_133 -> V_2 ) ;
F_36 ( V_53 -> V_12 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_127 ;
V_127 = F_42 ( & V_147 ) ;
if ( V_127 != 0 ) {
F_43 ( V_148 L_8 , V_149 ) ;
return V_127 ;
}
return V_127 ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_147 ) ;
}
