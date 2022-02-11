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
int V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
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
static int F_9 ( struct V_1 * V_2 )
{
const T_1 * V_29 ;
int V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
if ( ! V_2 -> V_36 . V_37 . V_38 )
return 0 ;
V_29 = F_10 ( V_2 -> V_36 . V_37 . V_38 ,
L_1 , & V_30 ) ;
if ( ! V_29 || V_30 < ( 4 * sizeof( * V_29 ) ) )
return 0 ;
V_32 = F_2 ( V_2 , V_39 ) ;
if ( V_32 < 0 )
return V_32 ;
V_34 = 0 ;
V_33 = V_32 ;
V_35 = 0 ;
V_30 /= sizeof( * V_29 ) ;
for ( V_31 = 0 ; V_31 < V_30 - 3 ; V_31 += 4 ) {
T_2 V_40 = F_11 ( V_29 + V_31 ) ;
T_2 V_11 = F_11 ( V_29 + V_31 + 1 ) ;
T_2 V_41 = F_11 ( V_29 + V_31 + 2 ) ;
T_2 V_42 = F_11 ( V_29 + V_31 + 3 ) ;
int V_12 ;
if ( V_40 != V_33 ) {
V_33 = V_40 ;
V_34 = 1 ;
V_35 = F_4 ( V_2 , V_39 , V_40 ) ;
if ( V_35 < 0 )
goto V_3;
}
V_12 = 0 ;
if ( V_41 ) {
V_12 = F_2 ( V_2 , V_11 ) ;
if ( V_12 < 0 ) {
V_35 = V_12 ;
goto V_3;
}
V_12 &= V_41 ;
}
V_12 |= V_42 ;
V_35 = F_4 ( V_2 , V_11 , V_12 ) ;
if ( V_35 < 0 )
goto V_3;
}
V_3:
if ( V_34 ) {
V_31 = F_4 ( V_2 , V_39 , V_32 ) ;
if ( V_35 == 0 )
V_35 = V_31 ;
}
return V_35 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 , V_43 , V_44 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_13 ( V_2 ) ) {
V_44 = F_2 ( V_2 , V_46 ) &
V_47 ;
if ( V_2 -> V_48 == V_49 )
V_44 |= ( V_50 |
V_51 ) ;
else if ( V_2 -> V_48 == V_52 )
V_44 |= V_50 ;
else if ( V_2 -> V_48 == V_53 )
V_44 |= V_51 ;
V_3 = F_4 ( V_2 , V_46 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_4 ( V_2 , V_39 , V_43 ) ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_13 ,
V_14 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_7 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 , V_43 , V_44 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
V_44 = F_2 ( V_2 , V_54 ) ;
V_44 |= V_55 ;
V_3 = F_4 ( V_2 , V_54 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_12 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_14 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_56 ;
int V_3 ;
V_56 = F_2 ( V_2 , V_21 ) ;
V_56 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
F_18 ( 500 ) ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_13 ) ;
V_56 |= ( 7 << 12 ) ;
V_56 |= ( 1 << 11 ) ;
V_56 |= V_14 ;
V_3 = F_4 ( V_2 , V_13 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_57 ) ;
V_56 |= ( 1 << 5 ) ;
V_56 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_57 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_21 ) ;
V_56 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
F_18 ( 500 ) ;
return F_16 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 , V_58 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= ~ V_59 ;
V_11 |= V_60 ;
V_11 = F_4 ( V_2 , V_58 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_16 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
int V_56 ;
if ( F_13 ( V_2 ) ) {
V_56 = F_2 ( V_2 , V_61 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_2 -> V_48 == V_49 ) {
V_56 |= ( V_62 | V_63 ) ;
} else if ( V_2 -> V_48 == V_52 ) {
V_56 &= ~ V_63 ;
V_56 |= V_62 ;
} else if ( V_2 -> V_48 == V_53 ) {
V_56 &= ~ V_62 ;
V_56 |= V_63 ;
}
V_3 = F_4 ( V_2 , V_61 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_64 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ ( V_65 ) ;
if ( V_56 & V_66 )
V_56 |= V_67 ;
else
V_56 |= V_68 ;
V_3 = F_4 ( V_2 , V_64 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_69 ) {
V_56 = F_2 ( V_2 , V_64 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ ( V_65 ) ;
V_56 |= V_70 ;
V_56 |= V_71 ;
V_3 = F_4 ( V_2 , V_64 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_72 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_72 ,
V_3 & ( ~ 0xff ) ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_73 ) {
V_56 = F_2 ( V_2 , V_61 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 |= ( V_62 | V_63 ) ;
V_3 = F_4 ( V_2 , V_61 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_64 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ ( V_65 | V_66 ) ;
V_56 |= 0x7 | V_71 ;
V_3 = F_4 ( V_2 , V_64 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_56 = F_2 ( V_2 , V_21 ) ;
while ( V_56 & V_22 );
V_56 = F_2 ( V_2 , V_64 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ ( V_65 | V_66 ) ;
V_56 |= V_74 | V_71 ;
V_3 = F_4 ( V_2 , V_64 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 , V_43 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 , V_75 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_76 ,
V_77 ) ;
if ( V_3 < 0 )
return V_3 ;
F_4 ( V_2 , V_39 , V_43 ) ;
return F_16 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 ;
int V_56 ;
if ( V_2 -> V_48 == V_69 ) {
V_3 = F_4 ( V_2 , V_39 , 18 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_78 ) ;
V_56 &= ~ V_79 ;
V_56 |= V_80 ;
V_3 = F_4 ( V_2 , V_78 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 |= V_81 ;
V_3 = F_4 ( V_2 , V_78 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return F_21 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
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
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0003 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_82 & V_83 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_3 ;
int V_56 ;
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
if ( V_2 -> V_48 == V_49 ) {
int V_56 = F_2 ( V_2 , V_84 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 |= ( V_85 | V_86 ) ;
V_3 = F_4 ( V_2 , V_84 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_82 & V_87 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , 0x1e ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= 0xf03f ;
V_56 |= 2 << 9 ;
V_56 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_56 ) ;
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
if ( V_2 -> V_48 == V_69 ) {
V_56 = F_2 ( V_2 , V_88 ) ;
if ( V_56 < 0 )
return V_56 ;
V_56 &= ~ V_89 ;
V_56 |= V_90 ;
V_56 |= V_91 ;
V_3 = F_4 ( V_2 , V_88 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_92 ;
int V_3 ;
int V_93 ;
int V_94 ;
int V_95 = 0 ;
V_3 = F_28 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_27 == V_2 -> V_26 ) {
V_95 = F_2 ( V_2 , V_96 ) ;
if ( V_95 < 0 )
return V_95 ;
V_93 = F_2 ( V_2 , V_97 ) ;
if ( V_93 < 0 )
return V_93 ;
V_94 = F_2 ( V_2 , V_98 ) ;
if ( V_94 < 0 )
return V_94 ;
V_92 = F_2 ( V_2 , V_99 ) ;
if ( V_92 < 0 )
return V_92 ;
V_2 -> V_100 = F_29 ( V_94 ) |
F_30 ( V_93 ) ;
V_93 &= V_92 ;
if ( V_95 & V_101 )
V_2 -> V_102 = V_103 ;
else
V_2 -> V_102 = V_104 ;
V_95 = V_95 & V_105 ;
V_2 -> V_106 = V_2 -> V_107 = 0 ;
switch ( V_95 ) {
case V_108 :
V_2 -> V_109 = V_110 ;
break;
case V_111 :
V_2 -> V_109 = V_112 ;
break;
default:
V_2 -> V_109 = V_113 ;
break;
}
if ( V_2 -> V_102 == V_103 ) {
V_2 -> V_106 = V_93 & V_114 ? 1 : 0 ;
V_2 -> V_107 = V_93 & V_115 ? 1 : 0 ;
}
} else {
int V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_116 )
V_2 -> V_102 = V_103 ;
else
V_2 -> V_102 = V_104 ;
if ( V_28 & V_117 )
V_2 -> V_109 = V_110 ;
else if ( V_28 & V_118 )
V_2 -> V_109 = V_112 ;
else
V_2 -> V_109 = V_113 ;
V_2 -> V_106 = V_2 -> V_107 = 0 ;
V_2 -> V_100 = 0 ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_119 = F_2 ( V_2 , V_96 ) ;
return ( V_119 < 0 ) ? V_119 : ( V_119 & V_120 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_121 ;
V_121 = F_2 ( V_2 , V_4 ) ;
if ( V_121 & V_8 )
return 1 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
V_123 -> V_124 = V_125 ;
V_123 -> V_126 = 0 ;
if ( F_4 ( V_2 , V_39 ,
V_127 ) < 0 )
return;
if ( F_2 ( V_2 , V_128 ) &
V_129 )
V_123 -> V_126 |= V_125 ;
if ( F_4 ( V_2 , V_39 , 0x00 ) < 0 )
return;
}
static int F_34 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
int V_3 , V_43 , V_56 ;
V_43 = F_2 ( V_2 , V_39 ) ;
if ( V_123 -> V_126 & V_125 ) {
V_3 = F_4 ( V_2 , V_39 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_130 ) ;
V_56 |= V_131 ;
V_3 = F_4 ( V_2 , V_130 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_132 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_133 ) ;
V_56 &= ~ V_134 ;
V_56 |= V_135 ;
V_56 |= V_136 ;
V_3 = F_4 ( V_2 , V_133 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_127 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_137 ,
( ( V_2 -> V_138 -> V_139 [ 5 ] << 8 ) |
V_2 -> V_138 -> V_139 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_140 ,
( ( V_2 -> V_138 -> V_139 [ 3 ] << 8 ) |
V_2 -> V_138 -> V_139 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_141 ,
( ( V_2 -> V_138 -> V_139 [ 1 ] << 8 ) |
V_2 -> V_138 -> V_139 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_128 ) ;
V_56 |= V_142 ;
V_56 |= V_129 ;
V_3 = F_4 ( V_2 , V_128 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_39 ,
V_127 ) ;
if ( V_3 < 0 )
return V_3 ;
V_56 = F_2 ( V_2 , V_128 ) ;
V_56 |= V_142 ;
V_56 &= ~ V_129 ;
V_3 = F_4 ( V_2 , V_128 , V_56 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_39 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_143 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_3 * V_144 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_36 ( V_143 ) ; V_31 ++ ) {
memcpy ( V_144 + V_31 * V_145 ,
V_143 [ V_31 ] . string , V_145 ) ;
}
}
static T_4 F_38 ( struct V_1 * V_2 , int V_31 )
{
struct V_146 V_147 = V_143 [ V_31 ] ;
struct V_148 * V_149 = V_2 -> V_149 ;
int V_3 , V_43 , V_12 ;
T_4 V_35 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_147 . V_150 ) ;
if ( V_3 < 0 )
return V_151 ;
V_12 = F_2 ( V_2 , V_147 . V_11 ) ;
if ( V_12 < 0 ) {
V_35 = V_151 ;
} else {
V_12 = V_12 & ( ( 1 << V_147 . V_152 ) - 1 ) ;
V_149 -> V_153 [ V_31 ] += V_12 ;
V_35 = V_149 -> V_153 [ V_31 ] ;
}
F_4 ( V_2 , V_39 , V_43 ) ;
return V_35 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_154 * V_153 , T_4 * V_144 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_36 ( V_143 ) ; V_31 ++ )
V_144 [ V_31 ] = F_38 ( V_2 , V_31 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_148 * V_149 ;
V_149 = F_41 ( & V_2 -> V_36 . V_37 , sizeof( * V_149 ) , V_155 ) ;
if ( ! V_149 )
return - V_156 ;
V_2 -> V_149 = V_149 ;
return 0 ;
}
