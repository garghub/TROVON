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
case 4096000 :
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
struct V_30 * V_19 = V_85 -> V_19 ;
int V_86 , V_51 ;
T_1 V_61 ;
V_61 = F_8 ( V_19 , V_39 ) ;
V_61 &= ~ V_87 ;
switch ( F_15 ( V_84 ) ) {
case 16 :
V_61 |= V_88 ;
break;
case 20 :
V_61 |= V_89 ;
break;
case 24 :
V_61 |= V_90 ;
break;
default:
return - V_35 ;
}
F_5 ( V_19 , V_39 , V_61 ) ;
V_51 = F_16 ( V_84 ) ;
V_86 = F_10 ( V_19 , V_51 ) ;
if ( V_86 < 0 )
return - V_35 ;
V_86 = V_54 [ V_86 ] . V_44 ;
F_5 ( V_19 , V_91 , V_86 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_85 , int V_92 )
{
struct V_30 * V_19 = V_85 -> V_19 ;
T_1 V_93 = V_94
| V_95 ;
T_1 V_96 = F_8 ( V_19 , V_97 ) & ~ V_93 ;
if ( V_92 )
V_96 |= V_93 ;
return F_5 ( V_19 , V_97 , V_96 ) ;
}
static void F_18 ( struct V_30 * V_19 )
{
F_7 ( V_19 , V_98 ,
V_99 ,
V_99 ) ;
F_7 ( V_19 , V_100 ,
V_101 ,
V_101 ) ;
F_7 ( V_19 , V_97 ,
V_102 ,
V_102 ) ;
F_7 ( V_19 , V_5 ,
V_103 ,
0 ) ;
F_19 ( 500 ) ;
F_7 ( V_19 , V_36 ,
V_104 ,
V_104 ) ;
F_7 ( V_19 , V_98 ,
V_105 ,
V_105 ) ;
F_7 ( V_19 , V_97 ,
V_102 ,
0 ) ;
}
static int F_20 ( struct V_30 * V_19 ,
enum V_106 V_107 )
{
switch ( V_107 ) {
case V_108 :
F_18 ( V_19 ) ;
break;
case V_109 :
break;
case V_110 :
F_7 ( V_19 , V_98 ,
V_111 ,
V_112 ) ;
F_7 ( V_19 , V_36 ,
V_113 ,
V_114 ) ;
F_7 ( V_19 , V_5 ,
V_103 ,
0xffff ^ ( V_115
| V_116 ) ) ;
break;
case V_117 :
F_7 ( V_19 , V_36 ,
V_113 , 0 ) ;
F_7 ( V_19 , V_100 ,
V_118 , 0 ) ;
F_7 ( V_19 , V_98 ,
V_111 , 0 ) ;
break;
}
V_19 -> V_119 . V_120 = V_107 ;
return 0 ;
}
static int F_21 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
F_22 ( V_53 -> V_12 ) ;
return 0 ;
}
static int F_23 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
switch ( V_53 -> V_121 ) {
case 0x5c :
F_24 ( V_19 , V_122 ,
F_9 ( V_122 ) ) ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_25 ( struct V_123 * V_124 ,
const struct V_125 * V_121 )
{
struct V_52 * V_53 ;
int V_126 , V_127 , V_128 ;
unsigned int V_129 , V_130 ;
V_53 = F_26 ( & V_124 -> V_2 ,
sizeof( struct V_52 ) , V_131 ) ;
if ( V_53 == NULL )
return - V_132 ;
F_27 ( V_124 , V_53 ) ;
V_53 -> V_12 = F_28 ( V_124 , & V_133 ) ;
if ( F_29 ( V_53 -> V_12 ) ) {
V_126 = F_30 ( V_53 -> V_12 ) ;
F_31 ( & V_124 -> V_2 , L_1 , V_126 ) ;
return V_126 ;
}
V_127 = F_32 ( V_53 -> V_12 , V_10 , & V_129 ) ;
V_128 = F_32 ( V_53 -> V_12 , V_11 , & V_130 ) ;
if ( V_127 != 0 || V_128 != 0 ) {
F_31 ( & V_124 -> V_2 ,
L_2 , V_127 , V_128 ) ;
return - V_134 ;
}
V_130 >>= 8 ;
if ( ( V_129 != 0x10EC ) || ( V_130 != V_121 -> V_135 ) ) {
F_31 ( & V_124 -> V_2 ,
L_3 , V_129 , V_130 ) ;
return - V_35 ;
}
V_126 = F_2 ( V_53 -> V_12 ) ;
if ( V_126 < 0 ) {
F_31 ( & V_124 -> V_2 , L_4 ) ;
return V_126 ;
}
V_53 -> V_121 = V_130 ;
switch ( V_53 -> V_121 ) {
case 0x5c :
V_136 . V_137 = L_5 ;
break;
default:
return - V_35 ;
}
V_126 = F_33 ( & V_124 -> V_2 ,
& V_138 , & V_136 , 1 ) ;
if ( V_126 < 0 ) {
F_31 ( & V_124 -> V_2 , L_6 , V_126 ) ;
return V_126 ;
}
return V_126 ;
}
static int F_34 ( struct V_123 * V_124 )
{
F_35 ( & V_124 -> V_2 ) ;
return 0 ;
}
