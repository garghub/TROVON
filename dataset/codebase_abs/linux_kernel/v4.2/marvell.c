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
static int F_5 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
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
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_14 ,
V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_16 != V_17 ) {
int V_18 ;
V_18 = F_2 ( V_2 , V_10 ) ;
if ( V_18 < 0 )
return V_18 ;
V_3 = F_4 ( V_2 , V_10 , V_18 | V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
const T_1 * V_19 ;
int V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ;
if ( ! V_2 -> V_26 . V_27 )
return 0 ;
V_19 = F_8 ( V_2 -> V_26 . V_27 , L_1 , & V_20 ) ;
if ( ! V_19 || V_20 < ( 4 * sizeof( * V_19 ) ) )
return 0 ;
V_22 = F_2 ( V_2 , V_28 ) ;
if ( V_22 < 0 )
return V_22 ;
V_24 = 0 ;
V_23 = V_22 ;
V_25 = 0 ;
V_20 /= sizeof( * V_19 ) ;
for ( V_21 = 0 ; V_21 < V_20 - 3 ; V_21 += 4 ) {
T_2 V_29 = F_9 ( V_19 + V_21 ) ;
T_2 V_30 = F_9 ( V_19 + V_21 + 1 ) ;
T_2 V_31 = F_9 ( V_19 + V_21 + 2 ) ;
T_2 V_32 = F_9 ( V_19 + V_21 + 3 ) ;
int V_33 ;
if ( V_29 != V_23 ) {
V_23 = V_29 ;
V_24 = 1 ;
V_25 = F_4 ( V_2 , V_28 , V_29 ) ;
if ( V_25 < 0 )
goto V_3;
}
V_33 = 0 ;
if ( V_31 ) {
V_33 = F_2 ( V_2 , V_30 ) ;
if ( V_33 < 0 ) {
V_25 = V_33 ;
goto V_3;
}
V_33 &= V_31 ;
}
V_33 |= V_32 ;
V_25 = F_4 ( V_2 , V_30 , V_33 ) ;
if ( V_25 < 0 )
goto V_3;
}
V_3:
if ( V_24 ) {
V_21 = F_4 ( V_2 , V_28 , V_22 ) ;
if ( V_25 == 0 )
V_25 = V_21 ;
}
return V_25 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 , V_34 , V_35 ;
V_34 = F_2 ( V_2 , V_28 ) ;
V_3 = F_4 ( V_2 , V_28 ,
V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_11 ( V_2 ) ) {
V_35 = F_2 ( V_2 , V_37 ) &
V_38 ;
if ( V_2 -> V_39 == V_40 )
V_35 |= ( V_41 |
V_42 ) ;
else if ( V_2 -> V_39 == V_43 )
V_35 |= V_41 ;
else if ( V_2 -> V_39 == V_44 )
V_35 |= V_42 ;
V_3 = F_4 ( V_2 , V_37 , V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
}
F_4 ( V_2 , V_28 , V_34 ) ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_34 = F_2 ( V_2 , V_28 ) ;
F_4 ( V_2 , V_28 , V_45 ) ;
F_4 ( V_2 , V_46 , V_47 ) ;
F_4 ( V_2 , V_28 , V_34 ) ;
V_3 = F_6 ( V_2 ) ;
return V_3 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 , V_34 , V_35 ;
V_34 = F_2 ( V_2 , V_28 ) ;
V_3 = F_4 ( V_2 , V_28 ,
V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
V_35 = F_2 ( V_2 , V_48 ) ;
V_35 |= V_49 ;
V_3 = F_4 ( V_2 , V_48 , V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , V_34 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_10 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_12 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_7 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_50 ;
int V_3 ;
V_50 = F_2 ( V_2 , V_10 ) ;
V_50 |= V_11 ;
V_3 = F_4 ( V_2 , V_10 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
F_15 ( 500 ) ;
V_3 = F_4 ( V_2 , V_28 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_12 ) ;
V_50 |= ( 7 << 12 ) ;
V_50 |= ( 1 << 11 ) ;
V_50 |= V_13 ;
V_3 = F_4 ( V_2 , V_12 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_51 ) ;
V_50 |= ( 1 << 5 ) ;
V_50 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_51 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_10 ) ;
V_50 |= V_11 ;
V_3 = F_4 ( V_2 , V_10 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
F_15 ( 500 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_2 ( V_2 , V_52 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 &= ~ V_53 ;
V_30 |= V_54 ;
V_30 = F_4 ( V_2 , V_52 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 ;
int V_50 ;
if ( F_11 ( V_2 ) ) {
V_50 = F_2 ( V_2 , V_55 ) ;
if ( V_50 < 0 )
return V_50 ;
if ( V_2 -> V_39 == V_40 ) {
V_50 |= ( V_56 | V_57 ) ;
} else if ( V_2 -> V_39 == V_43 ) {
V_50 &= ~ V_57 ;
V_50 |= V_56 ;
} else if ( V_2 -> V_39 == V_44 ) {
V_50 &= ~ V_56 ;
V_50 |= V_57 ;
}
V_3 = F_4 ( V_2 , V_55 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ ( V_59 ) ;
if ( V_50 & V_60 )
V_50 |= V_61 ;
else
V_50 |= V_62 ;
V_3 = F_4 ( V_2 , V_58 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_39 == V_63 ) {
V_50 = F_2 ( V_2 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ ( V_59 ) ;
V_50 |= V_64 ;
V_50 |= V_65 ;
V_3 = F_4 ( V_2 , V_58 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_39 == V_66 ) {
V_50 = F_2 ( V_2 , V_55 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 |= ( V_56 | V_57 ) ;
V_3 = F_4 ( V_2 , V_55 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ ( V_59 | V_60 ) ;
V_50 |= 0x7 | V_65 ;
V_3 = F_4 ( V_2 , V_58 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_50 = F_2 ( V_2 , V_10 ) ;
while ( V_50 & V_11 );
V_50 = F_2 ( V_2 , V_58 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ ( V_59 | V_60 ) ;
V_50 |= V_67 | V_65 ;
V_3 = F_4 ( V_2 , V_58 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_12 ,
V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_6 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0003 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_68 & V_69 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 ;
int V_50 ;
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
if ( V_2 -> V_39 == V_40 ) {
int V_50 = F_2 ( V_2 , V_70 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 |= ( V_71 | V_72 ) ;
V_3 = F_4 ( V_2 , V_70 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_68 & V_73 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , 0x1e ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= 0xf03f ;
V_50 |= 2 << 9 ;
V_50 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_50 ) ;
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
if ( V_2 -> V_39 == V_63 ) {
V_50 = F_2 ( V_2 , V_74 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 &= ~ V_75 ;
V_50 |= V_76 ;
V_50 |= V_77 ;
V_3 = F_4 ( V_2 , V_74 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_78 ;
int V_3 ;
int V_79 ;
int V_80 = 0 ;
V_3 = F_23 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_17 == V_2 -> V_16 ) {
V_80 = F_2 ( V_2 , V_81 ) ;
if ( V_80 < 0 )
return V_80 ;
V_79 = F_2 ( V_2 , V_82 ) ;
if ( V_79 < 0 )
return V_79 ;
V_78 = F_2 ( V_2 , V_83 ) ;
if ( V_78 < 0 )
return V_78 ;
V_79 &= V_78 ;
if ( V_80 & V_84 )
V_2 -> V_85 = V_86 ;
else
V_2 -> V_85 = V_87 ;
V_80 = V_80 & V_88 ;
V_2 -> V_89 = V_2 -> V_90 = 0 ;
switch ( V_80 ) {
case V_91 :
V_2 -> V_92 = V_93 ;
break;
case V_94 :
V_2 -> V_92 = V_95 ;
break;
default:
V_2 -> V_92 = V_96 ;
break;
}
if ( V_2 -> V_85 == V_86 ) {
V_2 -> V_89 = V_79 & V_97 ? 1 : 0 ;
V_2 -> V_90 = V_79 & V_98 ? 1 : 0 ;
}
} else {
int V_18 = F_2 ( V_2 , V_10 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_99 )
V_2 -> V_85 = V_86 ;
else
V_2 -> V_85 = V_87 ;
if ( V_18 & V_100 )
V_2 -> V_92 = V_93 ;
else if ( V_18 & V_101 )
V_2 -> V_92 = V_95 ;
else
V_2 -> V_92 = V_96 ;
V_2 -> V_89 = V_2 -> V_90 = 0 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_102 = F_2 ( V_2 , V_81 ) ;
return ( V_102 < 0 ) ? V_102 : ( V_102 & V_103 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_104 ;
V_104 = F_2 ( V_2 , V_4 ) ;
if ( V_104 & V_8 )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
V_106 -> V_107 = V_108 ;
V_106 -> V_109 = 0 ;
if ( F_4 ( V_2 , V_28 ,
V_110 ) < 0 )
return;
if ( F_2 ( V_2 , V_111 ) &
V_112 )
V_106 -> V_109 |= V_108 ;
if ( F_4 ( V_2 , V_28 , 0x00 ) < 0 )
return;
}
static int F_27 ( struct V_1 * V_2 , struct V_105 * V_106 )
{
int V_3 , V_34 , V_50 ;
V_34 = F_2 ( V_2 , V_28 ) ;
if ( V_106 -> V_109 & V_108 ) {
V_3 = F_4 ( V_2 , V_28 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_113 ) ;
V_50 |= V_114 ;
V_3 = F_4 ( V_2 , V_113 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 ,
V_115 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_116 ) ;
V_50 &= ~ V_117 ;
V_50 |= V_118 ;
V_50 |= V_119 ;
V_3 = F_4 ( V_2 , V_116 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 ,
V_110 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_120 ,
( ( V_2 -> V_121 -> V_122 [ 5 ] << 8 ) |
V_2 -> V_121 -> V_122 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_123 ,
( ( V_2 -> V_121 -> V_122 [ 3 ] << 8 ) |
V_2 -> V_121 -> V_122 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_124 ,
( ( V_2 -> V_121 -> V_122 [ 1 ] << 8 ) |
V_2 -> V_121 -> V_122 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_111 ) ;
V_50 |= V_125 ;
V_50 |= V_112 ;
V_3 = F_4 ( V_2 , V_111 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_28 ,
V_110 ) ;
if ( V_3 < 0 )
return V_3 ;
V_50 = F_2 ( V_2 , V_111 ) ;
V_50 |= V_125 ;
V_50 &= ~ V_112 ;
V_3 = F_4 ( V_2 , V_111 , V_50 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_28 , V_34 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
