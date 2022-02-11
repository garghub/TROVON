static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_5 == V_6 )
V_3 = F_4 ( V_2 , V_7 , V_8 ) ;
else
V_3 = F_4 ( V_2 , V_7 , V_9 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 )
{
int V_11 ;
int V_3 ;
int V_12 ;
V_11 = F_2 ( V_2 , V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = V_11 ;
V_12 &= ~ V_14 ;
switch ( V_10 ) {
case V_15 :
V_12 |= V_16 ;
break;
case V_17 :
V_12 |= V_18 ;
break;
case V_19 :
case V_20 :
default:
V_12 |= V_14 ;
break;
}
if ( V_12 != V_11 ) {
V_3 = F_4 ( V_2 , V_13 , V_12 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x1f ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x200c ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x100 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_5 ( V_2 , V_2 -> V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_24 ,
V_25 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_26 != V_27 ) {
int V_28 ;
V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
V_3 = F_4 ( V_2 , V_21 , V_28 | V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
const T_1 * V_29 ;
int V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
if ( ! V_2 -> V_36 . V_37 )
return 0 ;
V_29 = F_9 ( V_2 -> V_36 . V_37 , L_1 , & V_30 ) ;
if ( ! V_29 || V_30 < ( 4 * sizeof( * V_29 ) ) )
return 0 ;
V_32 = F_2 ( V_2 , V_38 ) ;
if ( V_32 < 0 )
return V_32 ;
V_34 = 0 ;
V_33 = V_32 ;
V_35 = 0 ;
V_30 /= sizeof( * V_29 ) ;
for ( V_31 = 0 ; V_31 < V_30 - 3 ; V_31 += 4 ) {
T_2 V_39 = F_10 ( V_29 + V_31 ) ;
T_2 V_11 = F_10 ( V_29 + V_31 + 1 ) ;
T_2 V_40 = F_10 ( V_29 + V_31 + 2 ) ;
T_2 V_41 = F_10 ( V_29 + V_31 + 3 ) ;
int V_12 ;
if ( V_39 != V_33 ) {
V_33 = V_39 ;
V_34 = 1 ;
V_35 = F_4 ( V_2 , V_38 , V_39 ) ;
if ( V_35 < 0 )
goto V_3;
}
V_12 = 0 ;
if ( V_40 ) {
V_12 = F_2 ( V_2 , V_11 ) ;
if ( V_12 < 0 ) {
V_35 = V_12 ;
goto V_3;
}
V_12 &= V_40 ;
}
V_12 |= V_41 ;
V_35 = F_4 ( V_2 , V_11 , V_12 ) ;
if ( V_35 < 0 )
goto V_3;
}
V_3:
if ( V_34 ) {
V_31 = F_4 ( V_2 , V_38 , V_32 ) ;
if ( V_35 == 0 )
V_35 = V_31 ;
}
return V_35 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_42 , V_43 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 ,
V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_12 ( V_2 ) ) {
V_43 = F_2 ( V_2 , V_45 ) &
V_46 ;
if ( V_2 -> V_47 == V_48 )
V_43 |= ( V_49 |
V_50 ) ;
else if ( V_2 -> V_47 == V_51 )
V_43 |= V_49 ;
else if ( V_2 -> V_47 == V_52 )
V_43 |= V_50 ;
V_3 = F_4 ( V_2 , V_45 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_4 ( V_2 , V_38 , V_42 ) ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_13 ,
V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
V_42 = F_2 ( V_2 , V_38 ) ;
F_4 ( V_2 , V_38 , V_53 ) ;
F_4 ( V_2 , V_54 , V_55 ) ;
F_4 ( V_2 , V_38 , V_42 ) ;
V_3 = F_7 ( V_2 ) ;
return V_3 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 , V_42 , V_43 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 ,
V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_43 = F_2 ( V_2 , V_56 ) ;
V_43 |= V_57 ;
V_3 = F_4 ( V_2 , V_56 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_11 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_13 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_8 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_58 ;
int V_3 ;
V_58 = F_2 ( V_2 , V_21 ) ;
V_58 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
F_16 ( 500 ) ;
V_3 = F_4 ( V_2 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_13 ) ;
V_58 |= ( 7 << 12 ) ;
V_58 |= ( 1 << 11 ) ;
V_58 |= V_14 ;
V_3 = F_4 ( V_2 , V_13 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_59 ) ;
V_58 |= ( 1 << 5 ) ;
V_58 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_59 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_21 ) ;
V_58 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
F_16 ( 500 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 , V_60 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= ~ V_61 ;
V_11 |= V_62 ;
V_11 = F_4 ( V_2 , V_60 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
int V_58 ;
if ( F_12 ( V_2 ) ) {
V_58 = F_2 ( V_2 , V_63 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( V_2 -> V_47 == V_48 ) {
V_58 |= ( V_64 | V_65 ) ;
} else if ( V_2 -> V_47 == V_51 ) {
V_58 &= ~ V_65 ;
V_58 |= V_64 ;
} else if ( V_2 -> V_47 == V_52 ) {
V_58 &= ~ V_64 ;
V_58 |= V_65 ;
}
V_3 = F_4 ( V_2 , V_63 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ ( V_67 ) ;
if ( V_58 & V_68 )
V_58 |= V_69 ;
else
V_58 |= V_70 ;
V_3 = F_4 ( V_2 , V_66 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_47 == V_71 ) {
V_58 = F_2 ( V_2 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ ( V_67 ) ;
V_58 |= V_72 ;
V_58 |= V_73 ;
V_3 = F_4 ( V_2 , V_66 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_74 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_74 ,
V_3 & ( ~ 0xff ) ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_47 == V_75 ) {
V_58 = F_2 ( V_2 , V_63 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 |= ( V_64 | V_65 ) ;
V_3 = F_4 ( V_2 , V_63 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ ( V_67 | V_68 ) ;
V_58 |= 0x7 | V_73 ;
V_3 = F_4 ( V_2 , V_66 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_58 = F_2 ( V_2 , V_21 ) ;
while ( V_58 & V_22 );
V_58 = F_2 ( V_2 , V_66 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ ( V_67 | V_68 ) ;
V_58 |= V_76 | V_73 ;
V_3 = F_4 ( V_2 , V_66 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_13 ,
V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0003 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_77 & V_78 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 ;
int V_58 ;
V_3 = F_4 ( V_2 , 0x1d , 0x001b ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x418f ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x0016 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0xa2da ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_47 == V_48 ) {
int V_58 = F_2 ( V_2 , V_79 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 |= ( V_80 | V_81 ) ;
V_3 = F_4 ( V_2 , V_79 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_77 & V_82 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , 0x1e ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= 0xf03f ;
V_58 |= 2 << 9 ;
V_58 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1d , 0x3 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x1e , 0x8000 ) ;
if ( V_3 < 0 )
return V_3 ;
}
}
if ( V_2 -> V_47 == V_71 ) {
V_58 = F_2 ( V_2 , V_83 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 &= ~ V_84 ;
V_58 |= V_85 ;
V_58 |= V_86 ;
V_3 = F_4 ( V_2 , V_83 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_87 ;
int V_3 ;
int V_88 ;
int V_89 ;
int V_90 = 0 ;
V_3 = F_24 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_27 == V_2 -> V_26 ) {
V_90 = F_2 ( V_2 , V_91 ) ;
if ( V_90 < 0 )
return V_90 ;
V_88 = F_2 ( V_2 , V_92 ) ;
if ( V_88 < 0 )
return V_88 ;
V_89 = F_2 ( V_2 , V_93 ) ;
if ( V_89 < 0 )
return V_89 ;
V_87 = F_2 ( V_2 , V_94 ) ;
if ( V_87 < 0 )
return V_87 ;
V_2 -> V_95 = F_25 ( V_89 ) |
F_26 ( V_88 ) ;
V_88 &= V_87 ;
if ( V_90 & V_96 )
V_2 -> V_97 = V_98 ;
else
V_2 -> V_97 = V_99 ;
V_90 = V_90 & V_100 ;
V_2 -> V_101 = V_2 -> V_102 = 0 ;
switch ( V_90 ) {
case V_103 :
V_2 -> V_104 = V_105 ;
break;
case V_106 :
V_2 -> V_104 = V_107 ;
break;
default:
V_2 -> V_104 = V_108 ;
break;
}
if ( V_2 -> V_97 == V_98 ) {
V_2 -> V_101 = V_88 & V_109 ? 1 : 0 ;
V_2 -> V_102 = V_88 & V_110 ? 1 : 0 ;
}
} else {
int V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_111 )
V_2 -> V_97 = V_98 ;
else
V_2 -> V_97 = V_99 ;
if ( V_28 & V_112 )
V_2 -> V_104 = V_105 ;
else if ( V_28 & V_113 )
V_2 -> V_104 = V_107 ;
else
V_2 -> V_104 = V_108 ;
V_2 -> V_101 = V_2 -> V_102 = 0 ;
V_2 -> V_95 = 0 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_114 = F_2 ( V_2 , V_91 ) ;
return ( V_114 < 0 ) ? V_114 : ( V_114 & V_115 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_116 ;
V_116 = F_2 ( V_2 , V_4 ) ;
if ( V_116 & V_8 )
return 1 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
V_118 -> V_119 = V_120 ;
V_118 -> V_121 = 0 ;
if ( F_4 ( V_2 , V_38 ,
V_122 ) < 0 )
return;
if ( F_2 ( V_2 , V_123 ) &
V_124 )
V_118 -> V_121 |= V_120 ;
if ( F_4 ( V_2 , V_38 , 0x00 ) < 0 )
return;
}
static int F_30 ( struct V_1 * V_2 , struct V_117 * V_118 )
{
int V_3 , V_42 , V_58 ;
V_42 = F_2 ( V_2 , V_38 ) ;
if ( V_118 -> V_121 & V_120 ) {
V_3 = F_4 ( V_2 , V_38 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_125 ) ;
V_58 |= V_126 ;
V_3 = F_4 ( V_2 , V_125 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 ,
V_127 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_128 ) ;
V_58 &= ~ V_129 ;
V_58 |= V_130 ;
V_58 |= V_131 ;
V_3 = F_4 ( V_2 , V_128 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 ,
V_122 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_132 ,
( ( V_2 -> V_133 -> V_134 [ 5 ] << 8 ) |
V_2 -> V_133 -> V_134 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_135 ,
( ( V_2 -> V_133 -> V_134 [ 3 ] << 8 ) |
V_2 -> V_133 -> V_134 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_136 ,
( ( V_2 -> V_133 -> V_134 [ 1 ] << 8 ) |
V_2 -> V_133 -> V_134 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_123 ) ;
V_58 |= V_137 ;
V_58 |= V_124 ;
V_3 = F_4 ( V_2 , V_123 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_38 ,
V_122 ) ;
if ( V_3 < 0 )
return V_3 ;
V_58 = F_2 ( V_2 , V_123 ) ;
V_58 |= V_137 ;
V_58 &= ~ V_124 ;
V_3 = F_4 ( V_2 , V_123 , V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_38 , V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
