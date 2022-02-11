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
struct V_19 * V_20 = F_5 ( V_15 -> V_21 ) ;
F_6 ( V_20 , V_22 , 0x46 ) ;
switch ( V_18 ) {
case V_23 :
F_6 ( V_20 , V_8 , 0xFFFF ) ;
break;
case V_24 :
F_6 ( V_20 , V_8 , 0 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_25 * V_26 , int V_27 ,
int V_28 , unsigned int V_29 , unsigned int V_30 )
{
int V_31 ;
struct V_19 * V_20 = V_26 -> V_20 ;
int V_32 = 0 , V_33 = 0 ;
T_1 V_3 ;
if ( V_27 < V_34 || V_27 > V_35 )
return - V_36 ;
F_8 ( V_20 , V_37 ,
V_38 ,
0 ) ;
F_8 ( V_20 , V_37 ,
V_39 ,
0 ) ;
V_3 = F_9 ( V_20 , V_40 ) ;
if ( V_3 & V_41 )
return 0 ;
if ( ! V_29 || ! V_30 )
return 0 ;
switch ( V_27 ) {
case V_34 :
for ( V_31 = 0 ; V_31 < F_10 ( V_42 ) ; V_31 ++ ) {
if ( V_42 [ V_31 ] . V_43 == V_29
&& V_42 [ V_31 ] . V_44 == V_30 ) {
V_33 = V_42 [ V_31 ] . V_45 ;
break;
}
}
break;
case V_46 :
for ( V_31 = 0 ; V_31 < F_10 ( V_47 ) ; V_31 ++ ) {
if ( V_47 [ V_31 ] . V_43 == V_29
&& V_47 [ V_31 ] . V_44 == V_30 ) {
V_32 = V_46 ;
V_33 = V_47 [ V_31 ] . V_45 ;
break;
}
}
break;
case V_35 :
for ( V_31 = 0 ; V_31 < F_10 ( V_47 ) ; V_31 ++ ) {
if ( V_47 [ V_31 ] . V_43 == V_29
&& V_47 [ V_31 ] . V_44 == V_30 ) {
V_32 = V_35 ;
V_33 = V_47 [ V_31 ] . V_45 ;
break;
}
}
break;
default:
return - V_36 ;
}
if ( ! V_33 )
return - V_36 ;
F_6 ( V_20 , V_48 , V_32 ) ;
F_6 ( V_20 , V_49 , V_33 ) ;
F_8 ( V_20 , V_37 ,
V_38 ,
V_38 ) ;
F_8 ( V_20 , V_37 ,
V_39 ,
V_39 ) ;
F_8 ( V_20 , V_50 ,
V_51 ,
V_51 ) ;
return 0 ;
}
static int F_11 ( struct V_19 * V_20 , int V_52 )
{
struct V_53 * V_54 = F_12 ( V_20 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_10 ( V_55 ) ; V_31 ++ ) {
if ( V_55 [ V_31 ] . V_56 * V_52 == V_54 -> V_57 )
return V_31 ;
}
return - V_36 ;
}
static int F_13 ( struct V_25 * V_26 ,
int V_58 , unsigned int V_59 , int V_60 )
{
struct V_19 * V_20 = V_26 -> V_20 ;
struct V_53 * V_54 = F_12 ( V_20 ) ;
switch ( V_59 ) {
case 4096000 :
case 8192000 :
case 11289600 :
case 12288000 :
case 16384000 :
case 16934400 :
case 18432000 :
case 22579200 :
case 24576000 :
V_54 -> V_57 = V_59 ;
return 0 ;
}
return - V_36 ;
}
static int F_14 ( struct V_25 * V_26 ,
unsigned int V_61 )
{
struct V_19 * V_20 = V_26 -> V_20 ;
T_1 V_62 = 0 ;
switch ( V_61 & V_63 ) {
case V_64 :
V_62 = V_65 ;
break;
case V_66 :
V_62 = V_41 ;
break;
default:
return - V_36 ;
}
switch ( V_61 & V_67 ) {
case V_68 :
V_62 |= V_69 ;
break;
case V_70 :
V_62 |= V_71 ;
break;
case V_72 :
V_62 |= V_73 ;
break;
case V_74 :
V_62 |= V_75 ;
break;
default:
return - V_36 ;
}
switch ( V_61 & V_76 ) {
case V_77 :
break;
case V_78 :
V_62 |= V_79 ;
break;
case V_80 :
V_62 |= V_79 ;
break;
case V_81 :
break;
default:
return - V_36 ;
}
return F_6 ( V_20 , V_40 , V_62 ) ;
}
static int F_15 ( struct V_82 * V_83 ,
struct V_84 * V_85 , struct V_25 * V_86 )
{
struct V_19 * V_20 = V_86 -> V_20 ;
int V_87 , V_52 ;
T_1 V_62 ;
V_62 = F_9 ( V_20 , V_40 ) ;
V_62 &= ~ V_88 ;
switch ( F_16 ( V_85 ) ) {
case 16 :
V_62 |= V_89 ;
break;
case 20 :
V_62 |= V_90 ;
break;
case 24 :
V_62 |= V_91 ;
break;
default:
return - V_36 ;
}
F_6 ( V_20 , V_40 , V_62 ) ;
V_52 = F_17 ( V_85 ) ;
V_87 = F_11 ( V_20 , V_52 ) ;
if ( V_87 < 0 )
return - V_36 ;
V_87 = V_55 [ V_87 ] . V_45 ;
F_6 ( V_20 , V_92 , V_87 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_86 , int V_93 )
{
struct V_19 * V_20 = V_86 -> V_20 ;
T_1 V_94 = V_95
| V_96 ;
T_1 V_97 = F_9 ( V_20 , V_98 ) & ~ V_94 ;
if ( V_93 )
V_97 |= V_94 ;
return F_6 ( V_20 , V_98 , V_97 ) ;
}
static void F_19 ( struct V_19 * V_20 )
{
F_8 ( V_20 , V_99 ,
V_100 ,
V_100 ) ;
F_8 ( V_20 , V_101 ,
V_102 ,
V_102 ) ;
F_8 ( V_20 , V_98 ,
V_103 ,
V_103 ) ;
F_8 ( V_20 , V_5 ,
V_104 ,
0 ) ;
F_20 ( 500 ) ;
F_8 ( V_20 , V_37 ,
V_105 ,
V_105 ) ;
F_8 ( V_20 , V_99 ,
V_106 ,
V_106 ) ;
F_8 ( V_20 , V_98 ,
V_103 ,
0 ) ;
}
static int F_21 ( struct V_19 * V_20 ,
enum V_107 V_108 )
{
switch ( V_108 ) {
case V_109 :
F_19 ( V_20 ) ;
break;
case V_110 :
break;
case V_111 :
F_8 ( V_20 , V_99 ,
V_112 ,
V_113 ) ;
F_8 ( V_20 , V_37 ,
V_114 ,
V_115 ) ;
F_8 ( V_20 , V_5 ,
V_104 ,
0xffff ^ ( V_116
| V_117 ) ) ;
break;
case V_118 :
F_8 ( V_20 , V_37 ,
V_114 , 0 ) ;
F_8 ( V_20 , V_101 ,
V_119 , 0 ) ;
F_8 ( V_20 , V_99 ,
V_112 , 0 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_19 * V_20 )
{
struct V_53 * V_54 = F_12 ( V_20 ) ;
F_23 ( V_54 -> V_12 ) ;
return 0 ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_53 * V_54 = F_12 ( V_20 ) ;
switch ( V_54 -> V_120 ) {
case 0x5c :
F_25 ( V_20 , V_121 ,
F_10 ( V_121 ) ) ;
break;
default:
return - V_36 ;
}
return 0 ;
}
static int F_26 ( struct V_122 * V_123 ,
const struct V_124 * V_120 )
{
struct V_53 * V_54 ;
int V_125 , V_126 , V_127 ;
unsigned int V_128 , V_129 ;
V_54 = F_27 ( & V_123 -> V_2 ,
sizeof( struct V_53 ) , V_130 ) ;
if ( V_54 == NULL )
return - V_131 ;
F_28 ( V_123 , V_54 ) ;
V_54 -> V_12 = F_29 ( V_123 , & V_132 ) ;
if ( F_30 ( V_54 -> V_12 ) ) {
V_125 = F_31 ( V_54 -> V_12 ) ;
F_32 ( & V_123 -> V_2 , L_1 , V_125 ) ;
return V_125 ;
}
V_126 = F_33 ( V_54 -> V_12 , V_10 , & V_128 ) ;
V_127 = F_33 ( V_54 -> V_12 , V_11 , & V_129 ) ;
if ( V_126 != 0 || V_127 != 0 ) {
F_32 ( & V_123 -> V_2 ,
L_2 , V_126 , V_127 ) ;
return - V_133 ;
}
V_129 >>= 8 ;
if ( ( V_128 != 0x10EC ) || ( V_129 != V_120 -> V_134 ) ) {
F_32 ( & V_123 -> V_2 ,
L_3 , V_128 , V_129 ) ;
return - V_36 ;
}
V_125 = F_2 ( V_54 -> V_12 ) ;
if ( V_125 < 0 ) {
F_32 ( & V_123 -> V_2 , L_4 ) ;
return V_125 ;
}
V_54 -> V_120 = V_129 ;
switch ( V_54 -> V_120 ) {
case 0x5c :
V_135 . V_136 = L_5 ;
break;
default:
return - V_36 ;
}
V_125 = F_34 ( & V_123 -> V_2 ,
& V_137 , & V_135 , 1 ) ;
if ( V_125 < 0 ) {
F_32 ( & V_123 -> V_2 , L_6 , V_125 ) ;
return V_125 ;
}
return V_125 ;
}
static int F_35 ( struct V_122 * V_123 )
{
F_36 ( & V_123 -> V_2 ) ;
return 0 ;
}
