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
int V_30 , V_31 , V_32 , V_33 , V_34 ;
if ( ! V_2 -> V_35 . V_36 . V_37 )
return 0 ;
V_29 = F_10 ( V_2 -> V_35 . V_36 . V_37 ,
L_1 , & V_30 ) ;
if ( ! V_29 || V_30 < ( 4 * sizeof( * V_29 ) ) )
return 0 ;
V_32 = F_2 ( V_2 , V_38 ) ;
if ( V_32 < 0 )
return V_32 ;
V_33 = V_32 ;
V_34 = 0 ;
V_30 /= sizeof( * V_29 ) ;
for ( V_31 = 0 ; V_31 < V_30 - 3 ; V_31 += 4 ) {
T_2 V_39 = F_11 ( V_29 + V_31 ) ;
T_2 V_11 = F_11 ( V_29 + V_31 + 1 ) ;
T_2 V_40 = F_11 ( V_29 + V_31 + 2 ) ;
T_2 V_41 = F_11 ( V_29 + V_31 + 3 ) ;
int V_12 ;
if ( V_39 != V_33 ) {
V_33 = V_39 ;
V_34 = F_4 ( V_2 , V_38 , V_39 ) ;
if ( V_34 < 0 )
goto V_3;
}
V_12 = 0 ;
if ( V_40 ) {
V_12 = F_2 ( V_2 , V_11 ) ;
if ( V_12 < 0 ) {
V_34 = V_12 ;
goto V_3;
}
V_12 &= V_40 ;
}
V_12 |= V_41 ;
V_34 = F_4 ( V_2 , V_11 , V_12 ) ;
if ( V_34 < 0 )
goto V_3;
}
V_3:
if ( V_33 != V_32 ) {
V_31 = F_4 ( V_2 , V_38 , V_32 ) ;
if ( V_34 == 0 )
V_34 = V_31 ;
}
return V_34 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_3 , V_42 , V_43 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 ,
V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_13 ( V_2 ) ) {
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
return F_7 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 , V_42 , V_43 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 ,
V_44 ) ;
if ( V_3 < 0 )
return V_3 ;
V_43 = F_2 ( V_2 , V_53 ) ;
V_43 |= V_54 ;
V_3 = F_4 ( V_2 , V_53 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_12 ( V_2 ) ;
}
static inline T_3 F_15 ( T_3 V_55 )
{
T_3 V_56 = 0 ;
if ( V_55 & V_57 )
V_56 |= V_58 ;
if ( V_55 & V_59 )
V_56 |= V_60 ;
if ( ( V_55 & V_61 ) && ( V_55 & V_62 ) )
V_56 |= V_63 ;
else if ( V_55 & V_62 )
V_56 |= ( V_64
& ( ~ V_65 ) ) ;
return V_56 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_66 = 0 ;
int V_3 ;
int V_67 , V_68 ;
T_3 V_69 ;
if ( V_2 -> V_26 != V_27 )
return F_17 ( V_2 ) ;
V_2 -> V_70 &= V_2 -> V_71 ;
V_69 = V_2 -> V_70 ;
V_67 = F_2 ( V_2 , V_72 ) ;
if ( V_67 < 0 )
return V_67 ;
V_68 = V_67 ;
V_67 &= ~ ( V_58 | V_60
| V_73 ) ;
V_67 |= F_15 ( V_69 ) ;
if ( V_67 != V_68 ) {
V_3 = F_4 ( V_2 , V_72 , V_67 ) ;
if ( V_3 < 0 )
return V_3 ;
V_66 = 1 ;
}
if ( V_66 == 0 ) {
int V_74 = F_2 ( V_2 , V_21 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( ! ( V_74 & V_75 ) || ( V_74 & V_76 ) )
V_66 = 1 ;
}
if ( V_66 > 0 )
V_66 = F_18 ( V_2 ) ;
return V_66 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_38 , V_77 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_14 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_38 , V_78 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_16 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
return F_4 ( V_2 , V_38 , V_77 ) ;
error:
F_4 ( V_2 , V_38 , V_77 ) ;
return V_3 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_79 ;
int V_3 ;
V_79 = F_2 ( V_2 , V_21 ) ;
V_79 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
F_22 ( 500 ) ;
V_3 = F_4 ( V_2 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_13 ) ;
V_79 |= ( 7 << 12 ) ;
V_79 |= ( 1 << 11 ) ;
V_79 |= V_14 ;
V_3 = F_4 ( V_2 , V_13 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_80 ) ;
V_79 |= ( 1 << 5 ) ;
V_79 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_80 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_21 ) ;
V_79 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
F_22 ( 500 ) ;
return F_20 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 , V_81 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= ~ V_82 ;
V_11 |= V_83 ;
V_11 = F_4 ( V_2 , V_81 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_20 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
int V_79 ;
if ( F_13 ( V_2 ) ) {
V_79 = F_2 ( V_2 , V_84 ) ;
if ( V_79 < 0 )
return V_79 ;
if ( V_2 -> V_47 == V_48 ) {
V_79 |= ( V_85 | V_86 ) ;
} else if ( V_2 -> V_47 == V_51 ) {
V_79 &= ~ V_86 ;
V_79 |= V_85 ;
} else if ( V_2 -> V_47 == V_52 ) {
V_79 &= ~ V_85 ;
V_79 |= V_86 ;
}
V_3 = F_4 ( V_2 , V_84 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 ) ;
if ( V_79 & V_89 )
V_79 |= V_90 ;
else
V_79 |= V_91 ;
V_3 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_47 == V_92 ) {
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 ) ;
V_79 |= V_93 ;
V_79 |= V_94 ;
V_3 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_95 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_95 ,
V_3 & ( ~ 0xff ) ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_47 == V_96 ) {
V_79 = F_2 ( V_2 , V_84 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 |= ( V_85 | V_86 ) ;
V_3 = F_4 ( V_2 , V_84 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 | V_89 ) ;
V_79 |= 0x7 | V_94 ;
V_3 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_79 = F_2 ( V_2 , V_21 ) ;
while ( V_79 & V_22 );
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 | V_89 ) ;
V_79 |= V_97 | V_94 ;
V_3 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_3 , V_42 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 , V_98 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_99 ,
V_100 ) ;
if ( V_3 < 0 )
return V_3 ;
F_4 ( V_2 , V_38 , V_42 ) ;
return F_20 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_3 ;
int V_79 ;
if ( V_2 -> V_47 == V_92 ) {
V_3 = F_4 ( V_2 , V_38 , 18 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_101 ) ;
V_79 &= ~ V_102 ;
V_79 |= V_103 ;
V_3 = F_4 ( V_2 , V_101 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 |= V_104 ;
V_3 = F_4 ( V_2 , V_101 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return F_25 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
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
static int F_28 ( struct V_1 * V_2 )
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
if ( V_2 -> V_105 & V_106 )
V_3 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_3 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 , 0x0 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_4 ( V_2 , V_21 , V_22 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_3 ;
int V_79 ;
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
int V_79 = F_2 ( V_2 , V_107 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 |= ( V_108 | V_109 ) ;
V_3 = F_4 ( V_2 , V_107 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_105 & V_110 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , 0x1e ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= 0xf03f ;
V_79 |= 2 << 9 ;
V_79 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_79 ) ;
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
if ( V_2 -> V_47 == V_92 ) {
V_79 = F_2 ( V_2 , V_111 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ V_112 ;
V_79 |= V_113 ;
V_79 |= V_114 ;
V_3 = F_4 ( V_2 , V_111 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static T_3 F_31 ( T_3 V_115 )
{
T_3 V_56 = 0 ;
if ( V_115 & V_116 )
V_56 |= V_57 ;
if ( V_115 & V_117 )
V_56 |= V_59 ;
return V_56 ;
}
static int F_32 ( struct V_1 * V_2 , int V_118 )
{
int V_119 ;
if ( V_118 ) {
V_119 = F_2 ( V_2 , V_120 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ( V_119 & V_121 ) == 0 )
V_2 -> V_122 = 0 ;
else
V_2 -> V_122 = 1 ;
} else {
return F_33 ( V_2 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_123 )
{
int V_67 ;
int V_3 ;
int V_115 ;
int V_124 ;
int V_119 = 0 ;
int V_118 ;
if ( V_123 == V_78 )
V_118 = 1 ;
else
V_118 = 0 ;
V_3 = F_32 ( V_2 , V_118 ) ;
if ( V_3 )
return V_3 ;
if ( V_27 == V_2 -> V_26 ) {
V_119 = F_2 ( V_2 , V_120 ) ;
if ( V_119 < 0 )
return V_119 ;
V_115 = F_2 ( V_2 , V_125 ) ;
if ( V_115 < 0 )
return V_115 ;
V_124 = F_2 ( V_2 , V_126 ) ;
if ( V_124 < 0 )
return V_124 ;
V_67 = F_2 ( V_2 , V_72 ) ;
if ( V_67 < 0 )
return V_67 ;
V_115 &= V_67 ;
if ( V_119 & V_127 )
V_2 -> V_128 = V_129 ;
else
V_2 -> V_128 = V_130 ;
V_119 = V_119 & V_131 ;
V_2 -> V_132 = V_2 -> V_133 = 0 ;
switch ( V_119 ) {
case V_134 :
V_2 -> V_135 = V_136 ;
break;
case V_137 :
V_2 -> V_135 = V_138 ;
break;
default:
V_2 -> V_135 = V_139 ;
break;
}
if ( ! V_118 ) {
V_2 -> V_140 = F_35 ( V_124 ) |
F_36 ( V_115 ) ;
if ( V_2 -> V_128 == V_129 ) {
V_2 -> V_132 = V_115 & V_141 ? 1 : 0 ;
V_2 -> V_133 = V_115 & V_142 ? 1 : 0 ;
}
} else {
V_2 -> V_140 = F_31 ( V_115 ) ;
if ( V_2 -> V_128 == V_129 ) {
if ( ! ( V_115 & V_73 ) ) {
V_2 -> V_132 = 0 ;
V_2 -> V_133 = 0 ;
} else if ( ( V_115 & V_63 ) ) {
V_2 -> V_132 = 1 ;
V_2 -> V_133 = 1 ;
} else {
V_2 -> V_132 = 1 ;
V_2 -> V_133 = 0 ;
}
}
}
} else {
int V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_143 )
V_2 -> V_128 = V_129 ;
else
V_2 -> V_128 = V_130 ;
if ( V_28 & V_144 )
V_2 -> V_135 = V_136 ;
else if ( V_28 & V_145 )
V_2 -> V_135 = V_138 ;
else
V_2 -> V_135 = V_139 ;
V_2 -> V_132 = V_2 -> V_133 = 0 ;
V_2 -> V_140 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_71 & V_146 &&
V_2 -> V_47 != V_92 ) {
V_3 = F_4 ( V_2 , V_38 , V_78 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_34 ( V_2 , V_78 ) ;
if ( V_3 < 0 )
goto error;
if ( V_2 -> V_122 )
return 0 ;
V_3 = F_4 ( V_2 , V_38 , V_77 ) ;
if ( V_3 < 0 )
goto error;
}
return F_34 ( V_2 , V_77 ) ;
error:
F_4 ( V_2 , V_38 , V_77 ) ;
return V_3 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_71 & V_146 ) ) {
V_3 = F_4 ( V_2 , V_38 , V_78 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_39 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_38 , V_77 ) ;
if ( V_3 < 0 )
goto error;
}
return F_39 ( V_2 ) ;
error:
F_4 ( V_2 , V_38 , V_77 ) ;
return V_3 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_71 & V_146 ) ) {
V_3 = F_4 ( V_2 , V_38 , V_78 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_41 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_38 , V_77 ) ;
if ( V_3 < 0 )
goto error;
}
return F_41 ( V_2 ) ;
error:
F_4 ( V_2 , V_38 , V_77 ) ;
return V_3 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_147 = F_2 ( V_2 , V_120 ) ;
return ( V_147 < 0 ) ? V_147 : ( V_147 & V_148 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_149 ;
V_149 = F_2 ( V_2 , V_4 ) ;
if ( V_149 & V_8 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
V_151 -> V_71 = V_152 ;
V_151 -> V_153 = 0 ;
if ( F_4 ( V_2 , V_38 ,
V_154 ) < 0 )
return;
if ( F_2 ( V_2 , V_155 ) &
V_156 )
V_151 -> V_153 |= V_152 ;
if ( F_4 ( V_2 , V_38 , 0x00 ) < 0 )
return;
}
static int F_45 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
int V_3 , V_42 , V_79 ;
V_42 = F_2 ( V_2 , V_38 ) ;
if ( V_151 -> V_153 & V_152 ) {
V_3 = F_4 ( V_2 , V_38 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_157 ) ;
V_79 |= V_158 ;
V_3 = F_4 ( V_2 , V_157 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 ,
V_159 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_160 ) ;
V_79 &= ~ V_161 ;
V_79 |= V_162 ;
V_79 |= V_163 ;
V_3 = F_4 ( V_2 , V_160 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_38 ,
V_154 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_164 ,
( ( V_2 -> V_165 -> V_166 [ 5 ] << 8 ) |
V_2 -> V_165 -> V_166 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_167 ,
( ( V_2 -> V_165 -> V_166 [ 3 ] << 8 ) |
V_2 -> V_165 -> V_166 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_168 ,
( ( V_2 -> V_165 -> V_166 [ 1 ] << 8 ) |
V_2 -> V_165 -> V_166 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_155 ) ;
V_79 |= V_169 ;
V_79 |= V_156 ;
V_3 = F_4 ( V_2 , V_155 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_38 ,
V_154 ) ;
if ( V_3 < 0 )
return V_3 ;
V_79 = F_2 ( V_2 , V_155 ) ;
V_79 |= V_169 ;
V_79 &= ~ V_156 ;
V_3 = F_4 ( V_2 , V_155 , V_79 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_38 , V_42 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 & V_146 )
return F_47 ( V_170 ) ;
else
return F_47 ( V_170 ) - V_171 ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_172 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_47 ( V_170 ) ; V_31 ++ ) {
memcpy ( V_172 + V_31 * V_173 ,
V_170 [ V_31 ] . string , V_173 ) ;
}
}
static T_5 F_49 ( struct V_1 * V_2 , int V_31 )
{
struct V_174 V_175 = V_170 [ V_31 ] ;
struct V_176 * V_177 = V_2 -> V_177 ;
int V_3 , V_42 , V_12 ;
T_5 V_34 ;
V_42 = F_2 ( V_2 , V_38 ) ;
V_3 = F_4 ( V_2 , V_38 ,
V_175 . V_123 ) ;
if ( V_3 < 0 )
return V_178 ;
V_12 = F_2 ( V_2 , V_175 . V_11 ) ;
if ( V_12 < 0 ) {
V_34 = V_178 ;
} else {
V_12 = V_12 & ( ( 1 << V_175 . V_179 ) - 1 ) ;
V_177 -> V_180 [ V_31 ] += V_12 ;
V_34 = V_177 -> V_180 [ V_31 ] ;
}
F_4 ( V_2 , V_38 , V_42 ) ;
return V_34 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_181 * V_180 , T_5 * V_172 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_47 ( V_170 ) ; V_31 ++ )
V_172 [ V_31 ] = F_49 ( V_2 , V_31 ) ;
}
static int F_51 ( struct V_1 * V_2 , long * V_79 )
{
int V_34 ;
int V_12 ;
* V_79 = 0 ;
F_52 ( & V_2 -> V_182 ) ;
V_34 = F_4 ( V_2 , V_95 , 0x6 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_2 ( V_2 , V_183 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_4 ( V_2 , V_183 ,
V_34 | V_184 ) ;
if ( V_34 < 0 )
goto error;
F_53 ( 10000 , 12000 ) ;
V_12 = F_2 ( V_2 , V_183 ) ;
if ( V_12 < 0 ) {
V_34 = V_12 ;
goto error;
}
V_34 = F_4 ( V_2 , V_183 ,
V_34 & ~ V_184 ) ;
if ( V_34 < 0 )
goto error;
* V_79 = ( ( V_12 & V_185 ) - 5 ) * 5000 ;
error:
F_4 ( V_2 , V_95 , 0x0 ) ;
F_54 ( & V_2 -> V_182 ) ;
return V_34 ;
}
static int F_55 ( struct V_186 * V_36 ,
enum V_187 type ,
T_3 V_188 , int V_189 , long * V_79 )
{
struct V_1 * V_2 = F_56 ( V_36 ) ;
int V_3 ;
switch ( V_188 ) {
case V_190 :
V_3 = F_51 ( V_2 , V_79 ) ;
break;
default:
return - V_191 ;
}
return V_3 ;
}
static T_6 F_57 ( const void * V_172 ,
enum V_187 type ,
T_3 V_188 , int V_189 )
{
if ( type != V_192 )
return 0 ;
switch ( V_188 ) {
case V_190 :
return 0444 ;
default:
return 0 ;
}
}
static int F_58 ( struct V_1 * V_2 , long * V_79 )
{
int V_34 ;
* V_79 = 0 ;
F_52 ( & V_2 -> V_182 ) ;
V_34 = F_4 ( V_2 , V_95 , 0x6 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_2 ( V_2 , V_193 ) ;
if ( V_34 < 0 )
goto error;
* V_79 = ( ( V_34 & V_194 ) - 25 ) * 1000 ;
error:
F_4 ( V_2 , V_95 , 0x0 ) ;
F_54 ( & V_2 -> V_182 ) ;
return V_34 ;
}
int F_59 ( struct V_1 * V_2 , long * V_79 )
{
int V_34 ;
* V_79 = 0 ;
F_52 ( & V_2 -> V_182 ) ;
V_34 = F_4 ( V_2 , V_95 , 0x6 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_2 ( V_2 , V_183 ) ;
if ( V_34 < 0 )
goto error;
* V_79 = ( ( ( V_34 & V_195 ) >>
V_196 ) * 5 ) - 25 ;
* V_79 *= 1000 ;
error:
F_4 ( V_2 , V_95 , 0x0 ) ;
F_54 ( & V_2 -> V_182 ) ;
return V_34 ;
}
int F_60 ( struct V_1 * V_2 , long V_79 )
{
int V_34 ;
F_52 ( & V_2 -> V_182 ) ;
V_34 = F_4 ( V_2 , V_95 , 0x6 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_2 ( V_2 , V_183 ) ;
if ( V_34 < 0 )
goto error;
V_79 = V_79 / 1000 ;
V_79 = F_61 ( F_62 ( V_79 , 5 ) + 5 , 0 , 0x1f ) ;
V_34 = F_4 ( V_2 , V_183 ,
( V_34 & ~ V_195 ) |
( V_79 << V_196 ) ) ;
error:
F_4 ( V_2 , V_95 , 0x0 ) ;
F_54 ( & V_2 -> V_182 ) ;
return V_34 ;
}
int F_63 ( struct V_1 * V_2 , long * V_197 )
{
int V_34 ;
* V_197 = false ;
F_52 ( & V_2 -> V_182 ) ;
V_34 = F_4 ( V_2 , V_95 , 0x6 ) ;
if ( V_34 < 0 )
goto error;
V_34 = F_2 ( V_2 , V_183 ) ;
if ( V_34 < 0 )
goto error;
* V_197 = ! ! ( V_34 & V_198 ) ;
error:
F_4 ( V_2 , V_95 , 0x0 ) ;
F_54 ( & V_2 -> V_182 ) ;
return V_34 ;
}
static int F_64 ( struct V_186 * V_36 ,
enum V_187 type ,
T_3 V_188 , int V_189 , long * V_79 )
{
struct V_1 * V_2 = F_56 ( V_36 ) ;
int V_3 ;
switch ( V_188 ) {
case V_190 :
V_3 = F_58 ( V_2 , V_79 ) ;
break;
case V_199 :
V_3 = F_59 ( V_2 , V_79 ) ;
break;
case V_200 :
V_3 = F_63 ( V_2 , V_79 ) ;
break;
default:
return - V_191 ;
}
return V_3 ;
}
static int F_65 ( struct V_186 * V_36 ,
enum V_187 type ,
T_3 V_188 , int V_189 , long V_79 )
{
struct V_1 * V_2 = F_56 ( V_36 ) ;
int V_3 ;
switch ( V_188 ) {
case V_199 :
V_3 = F_60 ( V_2 , V_79 ) ;
break;
default:
return - V_191 ;
}
return V_3 ;
}
static T_6 F_66 ( const void * V_172 ,
enum V_187 type ,
T_3 V_188 , int V_189 )
{
if ( type != V_192 )
return 0 ;
switch ( V_188 ) {
case V_190 :
case V_200 :
return 0444 ;
case V_199 :
return 0644 ;
default:
return 0 ;
}
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_176 * V_177 = V_2 -> V_177 ;
struct V_186 * V_36 = & V_2 -> V_35 . V_36 ;
const char * V_201 = F_68 ( V_36 ) ;
T_7 V_30 = strlen ( V_201 ) ;
int V_31 , V_202 ;
V_177 -> V_203 = F_69 ( V_36 , V_30 , V_204 ) ;
if ( ! V_177 -> V_203 )
return - V_205 ;
for ( V_31 = V_202 = 0 ; V_31 < V_30 && V_201 [ V_31 ] ; V_31 ++ ) {
if ( isalnum ( V_201 [ V_31 ] ) )
V_177 -> V_203 [ V_202 ++ ] = V_201 [ V_31 ] ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
const struct V_206 * V_207 )
{
struct V_176 * V_177 = V_2 -> V_177 ;
struct V_186 * V_36 = & V_2 -> V_35 . V_36 ;
int V_3 ;
V_3 = F_67 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_177 -> V_208 = F_71 (
V_36 , V_177 -> V_203 , V_2 , V_207 , NULL ) ;
return F_72 ( V_177 -> V_208 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , & V_209 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_70 ( V_2 , & V_210 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_176 * V_177 ;
V_177 = F_69 ( & V_2 -> V_35 . V_36 , sizeof( * V_177 ) , V_204 ) ;
if ( ! V_177 )
return - V_205 ;
V_2 -> V_177 = V_177 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_75 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_73 ( V_2 ) ;
}
static int F_77 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_75 ( V_2 ) ;
if ( V_3 )
return V_3 ;
return F_74 ( V_2 ) ;
}
