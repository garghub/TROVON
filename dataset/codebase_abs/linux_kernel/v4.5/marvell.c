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
if ( ! V_2 -> V_36 . V_37 . V_38 )
return 0 ;
V_29 = F_9 ( V_2 -> V_36 . V_37 . V_38 ,
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
T_2 V_40 = F_10 ( V_29 + V_31 ) ;
T_2 V_11 = F_10 ( V_29 + V_31 + 1 ) ;
T_2 V_41 = F_10 ( V_29 + V_31 + 2 ) ;
T_2 V_42 = F_10 ( V_29 + V_31 + 3 ) ;
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
static int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_43 , V_44 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_12 ( V_2 ) ) {
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
V_43 = F_2 ( V_2 , V_39 ) ;
F_4 ( V_2 , V_39 , V_54 ) ;
F_4 ( V_2 , V_55 , V_56 ) ;
F_4 ( V_2 , V_39 , V_43 ) ;
V_3 = F_7 ( V_2 ) ;
return V_3 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_3 , V_43 , V_44 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_45 ) ;
if ( V_3 < 0 )
return V_3 ;
V_44 = F_2 ( V_2 , V_57 ) ;
V_44 |= V_58 ;
V_3 = F_4 ( V_2 , V_57 , V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , V_43 ) ;
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
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_59 ;
int V_3 ;
V_59 = F_2 ( V_2 , V_21 ) ;
V_59 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
F_17 ( 500 ) ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_13 ) ;
V_59 |= ( 7 << 12 ) ;
V_59 |= ( 1 << 11 ) ;
V_59 |= V_14 ;
V_3 = F_4 ( V_2 , V_13 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_60 ) ;
V_59 |= ( 1 << 5 ) ;
V_59 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_60 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_21 ) ;
V_59 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
F_17 ( 500 ) ;
return F_15 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 , V_61 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= ~ V_62 ;
V_11 |= V_63 ;
V_11 = F_4 ( V_2 , V_61 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_15 ( V_2 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
int V_59 ;
if ( F_12 ( V_2 ) ) {
V_59 = F_2 ( V_2 , V_64 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_2 -> V_48 == V_49 ) {
V_59 |= ( V_65 | V_66 ) ;
} else if ( V_2 -> V_48 == V_52 ) {
V_59 &= ~ V_66 ;
V_59 |= V_65 ;
} else if ( V_2 -> V_48 == V_53 ) {
V_59 &= ~ V_65 ;
V_59 |= V_66 ;
}
V_3 = F_4 ( V_2 , V_64 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_67 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= ~ ( V_68 ) ;
if ( V_59 & V_69 )
V_59 |= V_70 ;
else
V_59 |= V_71 ;
V_3 = F_4 ( V_2 , V_67 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_72 ) {
V_59 = F_2 ( V_2 , V_67 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= ~ ( V_68 ) ;
V_59 |= V_73 ;
V_59 |= V_74 ;
V_3 = F_4 ( V_2 , V_67 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_75 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_75 ,
V_3 & ( ~ 0xff ) ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_76 ) {
V_59 = F_2 ( V_2 , V_64 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 |= ( V_65 | V_66 ) ;
V_3 = F_4 ( V_2 , V_64 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_67 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= ~ ( V_68 | V_69 ) ;
V_59 |= 0x7 | V_74 ;
V_3 = F_4 ( V_2 , V_67 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_59 = F_2 ( V_2 , V_21 ) ;
while ( V_59 & V_22 );
V_59 = F_2 ( V_2 , V_67 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= ~ ( V_68 | V_69 ) ;
V_59 |= V_77 | V_74 ;
V_3 = F_4 ( V_2 , V_67 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_20 ( struct V_1 * V_2 )
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
static int F_21 ( struct V_1 * V_2 )
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
if ( V_2 -> V_78 & V_79 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_3 ;
int V_59 ;
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
int V_59 = F_2 ( V_2 , V_80 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 |= ( V_81 | V_82 ) ;
V_3 = F_4 ( V_2 , V_80 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_78 & V_83 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , 0x1e ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= 0xf03f ;
V_59 |= 2 << 9 ;
V_59 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_59 ) ;
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
if ( V_2 -> V_48 == V_72 ) {
V_59 = F_2 ( V_2 , V_84 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 &= ~ V_85 ;
V_59 |= V_86 ;
V_59 |= V_87 ;
V_3 = F_4 ( V_2 , V_84 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_8 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_88 ;
int V_3 ;
int V_89 ;
int V_90 ;
int V_91 = 0 ;
V_3 = F_25 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_27 == V_2 -> V_26 ) {
V_91 = F_2 ( V_2 , V_92 ) ;
if ( V_91 < 0 )
return V_91 ;
V_89 = F_2 ( V_2 , V_93 ) ;
if ( V_89 < 0 )
return V_89 ;
V_90 = F_2 ( V_2 , V_94 ) ;
if ( V_90 < 0 )
return V_90 ;
V_88 = F_2 ( V_2 , V_95 ) ;
if ( V_88 < 0 )
return V_88 ;
V_2 -> V_96 = F_26 ( V_90 ) |
F_27 ( V_89 ) ;
V_89 &= V_88 ;
if ( V_91 & V_97 )
V_2 -> V_98 = V_99 ;
else
V_2 -> V_98 = V_100 ;
V_91 = V_91 & V_101 ;
V_2 -> V_102 = V_2 -> V_103 = 0 ;
switch ( V_91 ) {
case V_104 :
V_2 -> V_105 = V_106 ;
break;
case V_107 :
V_2 -> V_105 = V_108 ;
break;
default:
V_2 -> V_105 = V_109 ;
break;
}
if ( V_2 -> V_98 == V_99 ) {
V_2 -> V_102 = V_89 & V_110 ? 1 : 0 ;
V_2 -> V_103 = V_89 & V_111 ? 1 : 0 ;
}
} else {
int V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_112 )
V_2 -> V_98 = V_99 ;
else
V_2 -> V_98 = V_100 ;
if ( V_28 & V_113 )
V_2 -> V_105 = V_106 ;
else if ( V_28 & V_114 )
V_2 -> V_105 = V_108 ;
else
V_2 -> V_105 = V_109 ;
V_2 -> V_102 = V_2 -> V_103 = 0 ;
V_2 -> V_96 = 0 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_115 = F_2 ( V_2 , V_92 ) ;
return ( V_115 < 0 ) ? V_115 : ( V_115 & V_116 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_117 ;
V_117 = F_2 ( V_2 , V_4 ) ;
if ( V_117 & V_8 )
return 1 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
V_119 -> V_120 = V_121 ;
V_119 -> V_122 = 0 ;
if ( F_4 ( V_2 , V_39 ,
V_123 ) < 0 )
return;
if ( F_2 ( V_2 , V_124 ) &
V_125 )
V_119 -> V_122 |= V_121 ;
if ( F_4 ( V_2 , V_39 , 0x00 ) < 0 )
return;
}
static int F_31 ( struct V_1 * V_2 , struct V_118 * V_119 )
{
int V_3 , V_43 , V_59 ;
V_43 = F_2 ( V_2 , V_39 ) ;
if ( V_119 -> V_122 & V_121 ) {
V_3 = F_4 ( V_2 , V_39 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_126 ) ;
V_59 |= V_127 ;
V_3 = F_4 ( V_2 , V_126 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_128 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_129 ) ;
V_59 &= ~ V_130 ;
V_59 |= V_131 ;
V_59 |= V_132 ;
V_3 = F_4 ( V_2 , V_129 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_123 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_133 ,
( ( V_2 -> V_134 -> V_135 [ 5 ] << 8 ) |
V_2 -> V_134 -> V_135 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_136 ,
( ( V_2 -> V_134 -> V_135 [ 3 ] << 8 ) |
V_2 -> V_134 -> V_135 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_137 ,
( ( V_2 -> V_134 -> V_135 [ 1 ] << 8 ) |
V_2 -> V_134 -> V_135 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_124 ) ;
V_59 |= V_138 ;
V_59 |= V_125 ;
V_3 = F_4 ( V_2 , V_124 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_39 ,
V_123 ) ;
if ( V_3 < 0 )
return V_3 ;
V_59 = F_2 ( V_2 , V_124 ) ;
V_59 |= V_138 ;
V_59 &= ~ V_125 ;
V_3 = F_4 ( V_2 , V_124 , V_59 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_39 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
return F_33 ( V_139 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_3 * V_140 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_33 ( V_139 ) ; V_31 ++ ) {
memcpy ( V_140 + V_31 * V_141 ,
V_139 [ V_31 ] . string , V_141 ) ;
}
}
static T_4 F_35 ( struct V_1 * V_2 , int V_31 )
{
struct V_142 V_143 = V_139 [ V_31 ] ;
struct V_144 * V_145 = V_2 -> V_145 ;
int V_3 , V_43 ;
T_4 V_12 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_143 . V_146 ) ;
if ( V_3 < 0 )
return V_147 ;
V_12 = F_2 ( V_2 , V_143 . V_11 ) ;
if ( V_12 < 0 ) {
V_12 = V_147 ;
} else {
V_12 = V_12 & ( ( 1 << V_143 . V_148 ) - 1 ) ;
V_145 -> V_149 [ V_31 ] += V_12 ;
V_12 = V_145 -> V_149 [ V_31 ] ;
}
F_4 ( V_2 , V_39 , V_43 ) ;
return V_12 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_150 * V_149 , T_4 * V_140 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_33 ( V_139 ) ; V_31 ++ )
V_140 [ V_31 ] = F_35 ( V_2 , V_31 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_144 * V_145 ;
V_145 = F_38 ( & V_2 -> V_36 . V_37 , sizeof( * V_145 ) , V_151 ) ;
if ( ! V_145 )
return - V_152 ;
V_2 -> V_145 = V_145 ;
return 0 ;
}
