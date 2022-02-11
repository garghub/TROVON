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
static inline T_3 F_15 ( T_3 V_56 )
{
T_3 V_57 = 0 ;
if ( V_56 & V_58 )
V_57 |= V_59 ;
if ( V_56 & V_60 )
V_57 |= V_61 ;
if ( ( V_56 & V_62 ) && ( V_56 & V_63 ) )
V_57 |= V_64 ;
else if ( V_56 & V_63 )
V_57 |= ( V_65
& ( ~ V_66 ) ) ;
return V_57 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_67 = 0 ;
int V_3 ;
int V_68 , V_69 ;
T_3 V_70 ;
if ( V_2 -> V_26 != V_27 )
return F_17 ( V_2 ) ;
V_2 -> V_71 &= V_2 -> V_72 ;
V_70 = V_2 -> V_71 ;
V_68 = F_2 ( V_2 , V_73 ) ;
if ( V_68 < 0 )
return V_68 ;
V_69 = V_68 ;
V_68 &= ~ ( V_59 | V_61
| V_74 ) ;
V_68 |= F_15 ( V_70 ) ;
if ( V_68 != V_69 ) {
V_3 = F_4 ( V_2 , V_73 , V_68 ) ;
if ( V_3 < 0 )
return V_3 ;
V_67 = 1 ;
}
if ( V_67 == 0 ) {
int V_75 = F_2 ( V_2 , V_21 ) ;
if ( V_75 < 0 )
return V_75 ;
if ( ! ( V_75 & V_76 ) || ( V_75 & V_77 ) )
V_67 = 1 ;
}
if ( V_67 > 0 )
V_67 = F_18 ( V_2 ) ;
return V_67 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_4 ( V_2 , V_39 , V_78 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_14 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_39 , V_79 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_16 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
return F_4 ( V_2 , V_39 , V_78 ) ;
error:
F_4 ( V_2 , V_39 , V_78 ) ;
return V_3 ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_80 ;
int V_3 ;
V_80 = F_2 ( V_2 , V_21 ) ;
V_80 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
F_22 ( 500 ) ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_13 ) ;
V_80 |= ( 7 << 12 ) ;
V_80 |= ( 1 << 11 ) ;
V_80 |= V_14 ;
V_3 = F_4 ( V_2 , V_13 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_81 ) ;
V_80 |= ( 1 << 5 ) ;
V_80 |= ( 1 << 4 ) ;
V_3 = F_4 ( V_2 , V_81 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_21 ) ;
V_80 |= V_22 ;
V_3 = F_4 ( V_2 , V_21 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
F_22 ( 500 ) ;
return F_20 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_2 ( V_2 , V_82 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 &= ~ V_83 ;
V_11 |= V_84 ;
V_11 = F_4 ( V_2 , V_82 , V_11 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_20 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_3 ;
int V_80 ;
if ( F_13 ( V_2 ) ) {
V_80 = F_2 ( V_2 , V_85 ) ;
if ( V_80 < 0 )
return V_80 ;
if ( V_2 -> V_48 == V_49 ) {
V_80 |= ( V_86 | V_87 ) ;
} else if ( V_2 -> V_48 == V_52 ) {
V_80 &= ~ V_87 ;
V_80 |= V_86 ;
} else if ( V_2 -> V_48 == V_53 ) {
V_80 &= ~ V_86 ;
V_80 |= V_87 ;
}
V_3 = F_4 ( V_2 , V_85 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_88 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_89 ) ;
if ( V_80 & V_90 )
V_80 |= V_91 ;
else
V_80 |= V_92 ;
V_3 = F_4 ( V_2 , V_88 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_93 ) {
V_80 = F_2 ( V_2 , V_88 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_89 ) ;
V_80 |= V_94 ;
V_80 |= V_95 ;
V_3 = F_4 ( V_2 , V_88 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_2 , V_96 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_96 ,
V_3 & ( ~ 0xff ) ) ;
if ( V_3 < 0 )
return V_3 ;
}
if ( V_2 -> V_48 == V_97 ) {
V_80 = F_2 ( V_2 , V_85 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 |= ( V_86 | V_87 ) ;
V_3 = F_4 ( V_2 , V_85 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_88 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_89 | V_90 ) ;
V_80 |= 0x7 | V_95 ;
V_3 = F_4 ( V_2 , V_88 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_21 , V_22 ) ;
if ( V_3 < 0 )
return V_3 ;
do
V_80 = F_2 ( V_2 , V_21 ) ;
while ( V_80 & V_22 );
V_80 = F_2 ( V_2 , V_88 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ ( V_89 | V_90 ) ;
V_80 |= V_98 | V_95 ;
V_3 = F_4 ( V_2 , V_88 , V_80 ) ;
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
int V_3 , V_43 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 , V_99 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_100 ,
V_101 ) ;
if ( V_3 < 0 )
return V_3 ;
F_4 ( V_2 , V_39 , V_43 ) ;
return F_20 ( V_2 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_3 ;
int V_80 ;
if ( V_2 -> V_48 == V_93 ) {
V_3 = F_4 ( V_2 , V_39 , 18 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_102 ) ;
V_80 &= ~ V_103 ;
V_80 |= V_104 ;
V_3 = F_4 ( V_2 , V_102 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 |= V_105 ;
V_3 = F_4 ( V_2 , V_102 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0 ) ;
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
V_3 = F_4 ( V_2 , V_39 , 0x0002 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 , 0x0003 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_106 & V_107 )
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
static int F_29 ( struct V_1 * V_2 )
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
static int F_30 ( struct V_1 * V_2 )
{
int V_3 ;
int V_80 ;
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
int V_80 = F_2 ( V_2 , V_108 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 |= ( V_109 | V_110 ) ;
V_3 = F_4 ( V_2 , V_108 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 -> V_106 & V_111 ) {
V_3 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , 0x1e ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= 0xf03f ;
V_80 |= 2 << 9 ;
V_80 |= 2 << 6 ;
V_3 = F_4 ( V_2 , 0x1e , V_80 ) ;
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
if ( V_2 -> V_48 == V_93 ) {
V_80 = F_2 ( V_2 , V_112 ) ;
if ( V_80 < 0 )
return V_80 ;
V_80 &= ~ V_113 ;
V_80 |= V_114 ;
V_80 |= V_115 ;
V_3 = F_4 ( V_2 , V_112 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_9 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static T_3 F_31 ( T_3 V_116 )
{
T_3 V_57 = 0 ;
if ( V_116 & V_117 )
V_57 |= V_58 ;
if ( V_116 & V_118 )
V_57 |= V_60 ;
return V_57 ;
}
static int F_32 ( struct V_1 * V_2 , int V_119 )
{
int V_120 ;
if ( V_119 ) {
V_120 = F_2 ( V_2 , V_121 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( ( V_120 & V_122 ) == 0 )
V_2 -> V_123 = 0 ;
else
V_2 -> V_123 = 1 ;
} else {
return F_33 ( V_2 ) ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , int V_124 )
{
int V_68 ;
int V_3 ;
int V_116 ;
int V_125 ;
int V_120 = 0 ;
int V_119 ;
if ( V_124 == V_79 )
V_119 = 1 ;
else
V_119 = 0 ;
V_3 = F_32 ( V_2 , V_119 ) ;
if ( V_3 )
return V_3 ;
if ( V_27 == V_2 -> V_26 ) {
V_120 = F_2 ( V_2 , V_121 ) ;
if ( V_120 < 0 )
return V_120 ;
V_116 = F_2 ( V_2 , V_126 ) ;
if ( V_116 < 0 )
return V_116 ;
V_125 = F_2 ( V_2 , V_127 ) ;
if ( V_125 < 0 )
return V_125 ;
V_68 = F_2 ( V_2 , V_73 ) ;
if ( V_68 < 0 )
return V_68 ;
V_116 &= V_68 ;
if ( V_120 & V_128 )
V_2 -> V_129 = V_130 ;
else
V_2 -> V_129 = V_131 ;
V_120 = V_120 & V_132 ;
V_2 -> V_133 = V_2 -> V_134 = 0 ;
switch ( V_120 ) {
case V_135 :
V_2 -> V_136 = V_137 ;
break;
case V_138 :
V_2 -> V_136 = V_139 ;
break;
default:
V_2 -> V_136 = V_140 ;
break;
}
if ( ! V_119 ) {
V_2 -> V_141 = F_35 ( V_125 ) |
F_36 ( V_116 ) ;
if ( V_2 -> V_129 == V_130 ) {
V_2 -> V_133 = V_116 & V_142 ? 1 : 0 ;
V_2 -> V_134 = V_116 & V_143 ? 1 : 0 ;
}
} else {
V_2 -> V_141 = F_31 ( V_116 ) ;
if ( V_2 -> V_129 == V_130 ) {
if ( ! ( V_116 & V_74 ) ) {
V_2 -> V_133 = 0 ;
V_2 -> V_134 = 0 ;
} else if ( ( V_116 & V_64 ) ) {
V_2 -> V_133 = 1 ;
V_2 -> V_134 = 1 ;
} else {
V_2 -> V_133 = 1 ;
V_2 -> V_134 = 0 ;
}
}
}
} else {
int V_28 = F_2 ( V_2 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_144 )
V_2 -> V_129 = V_130 ;
else
V_2 -> V_129 = V_131 ;
if ( V_28 & V_145 )
V_2 -> V_136 = V_137 ;
else if ( V_28 & V_146 )
V_2 -> V_136 = V_139 ;
else
V_2 -> V_136 = V_140 ;
V_2 -> V_133 = V_2 -> V_134 = 0 ;
V_2 -> V_141 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_72 & V_147 ) {
V_3 = F_4 ( V_2 , V_39 , V_79 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_34 ( V_2 , V_79 ) ;
if ( V_3 < 0 )
goto error;
if ( V_2 -> V_123 )
return 0 ;
V_3 = F_4 ( V_2 , V_39 , V_78 ) ;
if ( V_3 < 0 )
goto error;
}
return F_34 ( V_2 , V_78 ) ;
error:
F_4 ( V_2 , V_39 , V_78 ) ;
return V_3 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_72 & V_147 ) ) {
V_3 = F_4 ( V_2 , V_39 , V_79 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_39 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_39 , V_78 ) ;
if ( V_3 < 0 )
goto error;
}
return F_39 ( V_2 ) ;
error:
F_4 ( V_2 , V_39 , V_78 ) ;
return V_3 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_3 ;
if ( ! ( V_2 -> V_72 & V_147 ) ) {
V_3 = F_4 ( V_2 , V_39 , V_79 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_41 ( V_2 ) ;
if ( V_3 < 0 )
goto error;
V_3 = F_4 ( V_2 , V_39 , V_78 ) ;
if ( V_3 < 0 )
goto error;
}
return F_41 ( V_2 ) ;
error:
F_4 ( V_2 , V_39 , V_78 ) ;
return V_3 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_148 = F_2 ( V_2 , V_121 ) ;
return ( V_148 < 0 ) ? V_148 : ( V_148 & V_149 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_150 ;
V_150 = F_2 ( V_2 , V_4 ) ;
if ( V_150 & V_8 )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
V_152 -> V_72 = V_153 ;
V_152 -> V_154 = 0 ;
if ( F_4 ( V_2 , V_39 ,
V_155 ) < 0 )
return;
if ( F_2 ( V_2 , V_156 ) &
V_157 )
V_152 -> V_154 |= V_153 ;
if ( F_4 ( V_2 , V_39 , 0x00 ) < 0 )
return;
}
static int F_45 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
int V_3 , V_43 , V_80 ;
V_43 = F_2 ( V_2 , V_39 ) ;
if ( V_152 -> V_154 & V_153 ) {
V_3 = F_4 ( V_2 , V_39 , 0x00 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_158 ) ;
V_80 |= V_159 ;
V_3 = F_4 ( V_2 , V_158 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_160 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_161 ) ;
V_80 &= ~ V_162 ;
V_80 |= V_163 ;
V_80 |= V_164 ;
V_3 = F_4 ( V_2 , V_161 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_39 ,
V_155 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_165 ,
( ( V_2 -> V_166 -> V_167 [ 5 ] << 8 ) |
V_2 -> V_166 -> V_167 [ 4 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_168 ,
( ( V_2 -> V_166 -> V_167 [ 3 ] << 8 ) |
V_2 -> V_166 -> V_167 [ 2 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_4 ( V_2 , V_169 ,
( ( V_2 -> V_166 -> V_167 [ 1 ] << 8 ) |
V_2 -> V_166 -> V_167 [ 0 ] ) ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_156 ) ;
V_80 |= V_170 ;
V_80 |= V_157 ;
V_3 = F_4 ( V_2 , V_156 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
} else {
V_3 = F_4 ( V_2 , V_39 ,
V_155 ) ;
if ( V_3 < 0 )
return V_3 ;
V_80 = F_2 ( V_2 , V_156 ) ;
V_80 |= V_170 ;
V_80 &= ~ V_157 ;
V_3 = F_4 ( V_2 , V_156 , V_80 ) ;
if ( V_3 < 0 )
return V_3 ;
}
V_3 = F_4 ( V_2 , V_39 , V_43 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_72 & V_147 )
return F_47 ( V_171 ) ;
else
return F_47 ( V_171 ) - V_172 ;
}
static void F_48 ( struct V_1 * V_2 , T_4 * V_173 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_47 ( V_171 ) ; V_31 ++ ) {
memcpy ( V_173 + V_31 * V_174 ,
V_171 [ V_31 ] . string , V_174 ) ;
}
}
static T_5 F_49 ( struct V_1 * V_2 , int V_31 )
{
struct V_175 V_176 = V_171 [ V_31 ] ;
struct V_177 * V_178 = V_2 -> V_178 ;
int V_3 , V_43 , V_12 ;
T_5 V_35 ;
V_43 = F_2 ( V_2 , V_39 ) ;
V_3 = F_4 ( V_2 , V_39 ,
V_176 . V_124 ) ;
if ( V_3 < 0 )
return V_179 ;
V_12 = F_2 ( V_2 , V_176 . V_11 ) ;
if ( V_12 < 0 ) {
V_35 = V_179 ;
} else {
V_12 = V_12 & ( ( 1 << V_176 . V_180 ) - 1 ) ;
V_178 -> V_181 [ V_31 ] += V_12 ;
V_35 = V_178 -> V_181 [ V_31 ] ;
}
F_4 ( V_2 , V_39 , V_43 ) ;
return V_35 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_182 * V_181 , T_5 * V_173 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < F_47 ( V_171 ) ; V_31 ++ )
V_173 [ V_31 ] = F_49 ( V_2 , V_31 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_177 * V_178 ;
V_178 = F_52 ( & V_2 -> V_36 . V_37 , sizeof( * V_178 ) , V_183 ) ;
if ( ! V_178 )
return - V_184 ;
V_2 -> V_178 = V_178 ;
return 0 ;
}
