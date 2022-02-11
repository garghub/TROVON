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
if ( ( V_2 -> V_37 == V_38 ) ||
( V_2 -> V_37 == V_39 ) ||
( V_2 -> V_37 == V_40 ) ||
( V_2 -> V_37 == V_41 ) ) {
V_35 = F_2 ( V_2 , V_42 ) &
V_43 ;
if ( V_2 -> V_37 == V_39 )
V_35 |= ( V_44 |
V_45 ) ;
else if ( V_2 -> V_37 == V_40 )
V_35 |= V_44 ;
else if ( V_2 -> V_37 == V_41 )
V_35 |= V_45 ;
V_3 = F_4 ( V_2 , V_42 , V_35 ) ;
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
F_4 ( V_2 , V_28 , V_46 ) ;
F_4 ( V_2 , V_47 , V_48 ) ;
F_4 ( V_2 , V_28 , V_34 ) ;
V_3 = F_6 ( V_2 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_34 , V_35 ;
V_34 = F_2 ( V_2 , V_28 ) ;
V_3 = F_4 ( V_2 , V_28 ,
V_36 ) ;
if ( V_3 < 0 )
return V_3 ;
V_35 = F_2 ( V_2 , V_49 ) ;
V_35 |= V_50 ;
V_3 = F_4 ( V_2 , V_49 , V_35 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , V_34 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_10 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_11 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_7 ( V_2 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_51 ;
int V_3 ;
V_51 = F_2 ( V_2 , V_10 ) ;
V_51 |= V_11 ;
V_3 = F_4 ( V_2 , V_10 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( 500 ) ;
V_3 = F_4 ( V_2 , V_28 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_12 ) ;
V_51 |= ( 7 << 12 ) ;
V_51 |= ( 1 << 11 ) ;
V_51 |= V_13 ;
V_3 = F_4 ( V_2 , V_12 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_52 ) ;
V_51 |= ( 1 << 5 ) ;
V_51 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_52 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_10 ) ;
V_51 |= V_11 ;
V_3 = F_4 ( V_2 , V_10 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
F_14 ( 500 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_30 ;
V_30 = F_2 ( V_2 , V_53 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 &= ~ V_54 ;
V_30 |= V_55 ;
V_30 = F_4 ( V_2 , V_53 , V_30 ) ;
if ( V_30 < 0 )
return V_30 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_3 ;
int V_51 ;
if ( ( V_2 -> V_37 == V_38 ) ||
( V_2 -> V_37 == V_39 ) ||
( V_2 -> V_37 == V_40 ) ||
( V_2 -> V_37 == V_41 ) ) {
V_51 = F_2 ( V_2 , V_56 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_2 -> V_37 == V_39 ) {
V_51 |= ( V_57 | V_58 ) ;
} else if ( V_2 -> V_37 == V_40 ) {
V_51 &= ~ V_58 ;
V_51 |= V_57 ;
} else if ( V_2 -> V_37 == V_41 ) {
V_51 &= ~ V_57 ;
V_51 |= V_58 ;
}
V_3 = F_4 ( V_2 , V_56 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_59 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_60 ) ;
if ( V_51 & V_61 )
V_51 |= V_62 ;
else
V_51 |= V_63 ;
V_3 = F_4 ( V_2 , V_59 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_37 == V_64 ) {
V_51 = F_2 ( V_2 , V_59 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_60 ) ;
V_51 |= V_65 ;
V_51 |= V_66 ;
V_3 = F_4 ( V_2 , V_59 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_37 == V_67 ) {
V_51 = F_2 ( V_2 , V_56 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 |= ( V_57 | V_58 ) ;
V_3 = F_4 ( V_2 , V_56 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_59 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_60 | V_61 ) ;
V_51 |= 0x7 | V_66 ;
V_3 = F_4 ( V_2 , V_59 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_10 , V_11 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_51 = F_2 ( V_2 , V_10 ) ;
while ( V_51 & V_11 );
V_51 = F_2 ( V_2 , V_59 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ ( V_60 | V_61 ) ;
V_51 |= V_68 | V_66 ;
V_3 = F_4 ( V_2 , V_59 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_10 , V_11 ) ;
}
static int F_17 ( struct V_1 * V_2 )
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
static int F_18 ( struct V_1 * V_2 )
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
if ( V_2 -> V_69 & V_70 )
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
static int F_19 ( struct V_1 * V_2 )
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
static int F_20 ( struct V_1 * V_2 )
{
int V_3 ;
int V_51 ;
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
if ( V_2 -> V_37 == V_39 ) {
int V_51 = F_2 ( V_2 , V_71 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 |= ( V_72 | V_73 ) ;
V_3 = F_4 ( V_2 , V_71 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_69 & V_74 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , 0x1e ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= 0xf03f ;
V_51 |= 2 << 9 ;
V_51 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_51 ) ;
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
if ( V_2 -> V_37 == V_64 ) {
V_51 = F_2 ( V_2 , V_75 ) ;
if ( V_51 < 0 )
return V_51 ;
V_51 &= ~ V_76 ;
V_51 |= V_77 ;
V_51 |= V_78 ;
V_3 = F_4 ( V_2 , V_75 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_7 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_79 ;
int V_3 ;
int V_80 ;
int V_81 = 0 ;
V_3 = F_22 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_17 == V_2 -> V_16 ) {
V_81 = F_2 ( V_2 , V_82 ) ;
if ( V_81 < 0 )
return V_81 ;
V_80 = F_2 ( V_2 , V_83 ) ;
if ( V_80 < 0 )
return V_80 ;
V_79 = F_2 ( V_2 , V_84 ) ;
if ( V_79 < 0 )
return V_79 ;
V_80 &= V_79 ;
if ( V_81 & V_85 )
V_2 -> V_86 = V_87 ;
else
V_2 -> V_86 = V_88 ;
V_81 = V_81 & V_89 ;
V_2 -> V_90 = V_2 -> V_91 = 0 ;
switch ( V_81 ) {
case V_92 :
V_2 -> V_93 = V_94 ;
break;
case V_95 :
V_2 -> V_93 = V_96 ;
break;
default:
V_2 -> V_93 = V_97 ;
break;
}
if ( V_2 -> V_86 == V_87 ) {
V_2 -> V_90 = V_80 & V_98 ? 1 : 0 ;
V_2 -> V_91 = V_80 & V_99 ? 1 : 0 ;
}
} else {
int V_18 = F_2 ( V_2 , V_10 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_18 & V_100 )
V_2 -> V_86 = V_87 ;
else
V_2 -> V_86 = V_88 ;
if ( V_18 & V_101 )
V_2 -> V_93 = V_94 ;
else if ( V_18 & V_102 )
V_2 -> V_93 = V_96 ;
else
V_2 -> V_93 = V_97 ;
V_2 -> V_90 = V_2 -> V_91 = 0 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_103 = F_2 ( V_2 , V_82 ) ;
return ( V_103 < 0 ) ? V_103 : ( V_103 & V_104 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_105 ;
V_105 = F_2 ( V_2 , V_4 ) ;
if ( V_105 & V_8 )
return 1 ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
V_107 -> V_108 = V_109 ;
V_107 -> V_110 = 0 ;
if ( F_4 ( V_2 , V_28 ,
V_111 ) < 0 )
return;
if ( F_2 ( V_2 , V_112 ) &
V_113 )
V_107 -> V_110 |= V_109 ;
if ( F_4 ( V_2 , V_28 , 0x00 ) < 0 )
return;
}
static int F_26 ( struct V_1 * V_2 , struct V_106 * V_107 )
{
int V_3 , V_34 , V_51 ;
V_34 = F_2 ( V_2 , V_28 ) ;
if ( V_107 -> V_110 & V_109 ) {
V_3 = F_4 ( V_2 , V_28 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_114 ) ;
V_51 |= V_115 ;
V_3 = F_4 ( V_2 , V_114 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 ,
V_116 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_117 ) ;
V_51 &= ~ V_118 ;
V_51 |= V_119 ;
V_51 |= V_120 ;
V_3 = F_4 ( V_2 , V_117 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_28 ,
V_111 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_121 ,
( ( V_2 -> V_122 -> V_123 [ 5 ] << 8 ) |
V_2 -> V_122 -> V_123 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_124 ,
( ( V_2 -> V_122 -> V_123 [ 3 ] << 8 ) |
V_2 -> V_122 -> V_123 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_125 ,
( ( V_2 -> V_122 -> V_123 [ 1 ] << 8 ) |
V_2 -> V_122 -> V_123 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_112 ) ;
V_51 |= V_126 ;
V_51 |= V_113 ;
V_3 = F_4 ( V_2 , V_112 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_28 ,
V_111 ) ;
if ( V_3 < 0 )
return V_3 ;
V_51 = F_2 ( V_2 , V_112 ) ;
V_51 |= V_126 ;
V_51 &= ~ V_113 ;
V_3 = F_4 ( V_2 , V_112 , V_51 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_28 , V_34 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
