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
case V_88 :
V_61 |= V_89 ;
break;
case V_90 :
V_61 |= V_91 ;
break;
case V_92 :
V_61 |= V_93 ;
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
F_5 ( V_19 , V_94 , V_86 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_85 , int V_95 )
{
struct V_30 * V_19 = V_85 -> V_19 ;
T_1 V_96 = V_97
| V_98 ;
T_1 V_99 = F_8 ( V_19 , V_100 ) & ~ V_96 ;
if ( V_95 )
V_99 |= V_96 ;
return F_5 ( V_19 , V_100 , V_99 ) ;
}
static void F_18 ( struct V_30 * V_19 )
{
F_7 ( V_19 , V_101 ,
V_102 ,
V_102 ) ;
F_7 ( V_19 , V_103 ,
V_104 ,
V_104 ) ;
F_7 ( V_19 , V_100 ,
V_105 ,
V_105 ) ;
F_7 ( V_19 , V_5 ,
V_106 ,
0 ) ;
F_19 ( 500 ) ;
F_7 ( V_19 , V_36 ,
V_107 ,
V_107 ) ;
F_7 ( V_19 , V_101 ,
V_108 ,
V_108 ) ;
F_7 ( V_19 , V_100 ,
V_105 ,
0 ) ;
}
static int F_20 ( struct V_30 * V_19 ,
enum V_109 V_110 )
{
switch ( V_110 ) {
case V_111 :
F_18 ( V_19 ) ;
break;
case V_112 :
break;
case V_113 :
F_7 ( V_19 , V_101 ,
V_114 ,
V_115 ) ;
F_7 ( V_19 , V_36 ,
V_116 ,
V_117 ) ;
F_7 ( V_19 , V_5 ,
V_106 ,
0xffff ^ ( V_118
| V_119 ) ) ;
break;
case V_120 :
F_7 ( V_19 , V_36 ,
V_116 , 0 ) ;
F_7 ( V_19 , V_103 ,
V_121 , 0 ) ;
F_7 ( V_19 , V_101 ,
V_114 , 0 ) ;
break;
}
V_19 -> V_122 . V_123 = V_110 ;
return 0 ;
}
static int F_21 ( struct V_30 * V_19 )
{
F_20 ( V_19 , V_120 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
F_23 ( V_53 -> V_12 ) ;
F_20 ( V_19 , V_113 ) ;
return 0 ;
}
static int F_24 ( struct V_30 * V_19 )
{
struct V_52 * V_53 = F_11 ( V_19 ) ;
int V_124 ;
V_19 -> V_125 = V_53 -> V_12 ;
V_124 = F_25 ( V_19 , 8 , 16 , V_126 ) ;
if ( V_124 != 0 ) {
F_26 ( V_19 -> V_2 , L_1 , V_124 ) ;
return V_124 ;
}
F_20 ( V_19 , V_113 ) ;
switch ( V_53 -> V_127 ) {
case 0x5c :
F_27 ( V_19 , V_128 ,
F_9 ( V_128 ) ) ;
break;
default:
return - V_35 ;
}
return V_124 ;
}
static int F_28 ( struct V_30 * V_19 )
{
F_20 ( V_19 , V_120 ) ;
return 0 ;
}
static int F_29 ( struct V_129 * V_130 ,
const struct V_131 * V_127 )
{
struct V_52 * V_53 ;
int V_124 , V_132 , V_133 ;
unsigned int V_134 , V_135 ;
V_53 = F_30 ( & V_130 -> V_2 ,
sizeof( struct V_52 ) , V_136 ) ;
if ( V_53 == NULL )
return - V_137 ;
F_31 ( V_130 , V_53 ) ;
V_53 -> V_12 = F_32 ( V_130 , & V_138 ) ;
if ( F_33 ( V_53 -> V_12 ) ) {
V_124 = F_34 ( V_53 -> V_12 ) ;
F_26 ( & V_130 -> V_2 , L_2 , V_124 ) ;
return V_124 ;
}
V_132 = F_35 ( V_53 -> V_12 , V_10 , & V_134 ) ;
V_133 = F_35 ( V_53 -> V_12 , V_11 , & V_135 ) ;
if ( V_132 != 0 || V_133 != 0 ) {
F_26 ( & V_130 -> V_2 ,
L_3 , V_132 , V_133 ) ;
return - V_139 ;
}
V_135 >>= 8 ;
if ( ( V_134 != 0x10EC ) || ( V_135 != V_127 -> V_140 ) ) {
F_26 ( & V_130 -> V_2 ,
L_4 , V_134 , V_135 ) ;
return - V_35 ;
}
V_124 = F_2 ( V_53 -> V_12 ) ;
if ( V_124 < 0 ) {
F_26 ( & V_130 -> V_2 , L_5 ) ;
return V_124 ;
}
V_53 -> V_127 = V_135 ;
switch ( V_53 -> V_127 ) {
case 0x5c :
V_141 . V_142 = L_6 ;
break;
default:
return - V_35 ;
}
V_124 = F_36 ( & V_130 -> V_2 ,
& V_143 , & V_141 , 1 ) ;
if ( V_124 < 0 ) {
F_26 ( & V_130 -> V_2 , L_7 , V_124 ) ;
return V_124 ;
}
return V_124 ;
}
static int F_37 ( struct V_129 * V_130 )
{
F_38 ( & V_130 -> V_2 ) ;
return 0 ;
}
