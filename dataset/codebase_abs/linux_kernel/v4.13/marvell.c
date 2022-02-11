static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_4 )
{
int V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_4 != V_5 )
return F_3 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_2 ( V_2 , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_8 == V_9 )
V_6 = F_4 ( V_2 , V_10 ,
V_11 ) ;
else
V_6 = F_4 ( V_2 , V_10 ,
V_12 ) ;
return V_6 ;
}
static int F_8 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
int V_6 ;
int V_15 ;
V_14 = F_2 ( V_2 , V_16 ) ;
if ( V_14 < 0 )
return V_14 ;
V_15 = V_14 ;
V_15 &= ~ V_17 ;
switch ( V_13 ) {
case V_18 :
V_15 |= V_19 ;
break;
case V_20 :
V_15 |= V_21 ;
break;
case V_22 :
case V_23 :
default:
V_15 |= V_17 ;
break;
}
if ( V_15 != V_14 ) {
V_6 = F_4 ( V_2 , V_16 , V_15 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_25 ,
V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_27 != V_28 ) {
int V_29 ;
V_29 = F_2 ( V_2 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_6 = F_4 ( V_2 , V_30 , V_29 | V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_30 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x1f ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0x200c ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0x100 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_9 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_30 , V_31 ) ;
V_6 = F_8 ( V_2 , V_2 -> V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_25 ,
V_26 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_10 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_27 != V_28 ) {
int V_29 ;
V_29 = F_2 ( V_2 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
V_6 = F_4 ( V_2 , V_30 , V_29 | V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
const T_1 * V_32 ;
int V_33 , V_34 , V_35 , V_36 , V_37 ;
if ( ! V_2 -> V_38 . V_39 . V_40 )
return 0 ;
V_32 = F_14 ( V_2 -> V_38 . V_39 . V_40 ,
L_1 , & V_33 ) ;
if ( ! V_32 || V_33 < ( 4 * sizeof( * V_32 ) ) )
return 0 ;
V_35 = F_1 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
V_36 = V_35 ;
V_37 = 0 ;
V_33 /= sizeof( * V_32 ) ;
for ( V_34 = 0 ; V_34 < V_33 - 3 ; V_34 += 4 ) {
T_2 V_4 = F_15 ( V_32 + V_34 ) ;
T_2 V_14 = F_15 ( V_32 + V_34 + 1 ) ;
T_2 V_41 = F_15 ( V_32 + V_34 + 2 ) ;
T_2 V_42 = F_15 ( V_32 + V_34 + 3 ) ;
int V_15 ;
if ( V_4 != V_36 ) {
V_36 = V_4 ;
V_37 = F_3 ( V_2 , V_4 ) ;
if ( V_37 < 0 )
goto V_6;
}
V_15 = 0 ;
if ( V_41 ) {
V_15 = F_2 ( V_2 , V_14 ) ;
if ( V_15 < 0 ) {
V_37 = V_15 ;
goto V_6;
}
V_15 &= V_41 ;
}
V_15 |= V_42 ;
V_37 = F_4 ( V_2 , V_14 , V_15 ) ;
if ( V_37 < 0 )
goto V_6;
}
V_6:
if ( V_36 != V_35 ) {
V_34 = F_3 ( V_2 , V_35 ) ;
if ( V_37 == 0 )
V_37 = V_34 ;
}
return V_37 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_6 , V_5 , V_43 ;
V_5 = F_5 ( V_2 , V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( F_17 ( V_2 ) ) {
V_43 = F_2 ( V_2 , V_45 ) &
V_46 ;
if ( V_2 -> V_47 == V_48 )
V_43 |= ( V_49 |
V_50 ) ;
else if ( V_2 -> V_47 == V_51 )
V_43 |= V_49 ;
else if ( V_2 -> V_47 == V_52 )
V_43 |= V_50 ;
V_6 = F_4 ( V_2 , V_45 , V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
}
F_3 ( V_2 , V_5 ) ;
V_6 = F_4 ( V_2 , V_30 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_16 ,
V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_10 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_6 , V_5 , V_43 ;
V_5 = F_5 ( V_2 , V_44 ) ;
if ( V_5 < 0 )
return V_5 ;
V_43 = F_2 ( V_2 , V_53 ) ;
V_43 |= V_54 ;
V_6 = F_4 ( V_2 , V_53 , V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_16 ( V_2 ) ;
}
static inline T_3 F_19 ( T_3 V_55 )
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
static int F_20 ( struct V_1 * V_2 )
{
int V_66 = 0 ;
int V_6 ;
int V_67 , V_68 ;
T_3 V_69 ;
if ( V_2 -> V_27 != V_28 )
return F_21 ( V_2 ) ;
V_2 -> V_70 &= V_2 -> V_71 ;
V_69 = V_2 -> V_70 ;
V_67 = F_2 ( V_2 , V_72 ) ;
if ( V_67 < 0 )
return V_67 ;
V_68 = V_67 ;
V_67 &= ~ ( V_58 | V_60
| V_73 ) ;
V_67 |= F_19 ( V_69 ) ;
if ( V_67 != V_68 ) {
V_6 = F_4 ( V_2 , V_72 , V_67 ) ;
if ( V_6 < 0 )
return V_6 ;
V_66 = 1 ;
}
if ( V_66 == 0 ) {
int V_74 = F_2 ( V_2 , V_30 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( ! ( V_74 & V_75 ) || ( V_74 & V_76 ) )
V_66 = 1 ;
}
if ( V_66 > 0 )
V_66 = F_22 ( V_2 ) ;
return V_66 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_18 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_20 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
return F_3 ( V_2 , V_77 ) ;
error:
F_3 ( V_2 , V_77 ) ;
return V_6 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_13 ( V_2 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_79 ;
int V_6 ;
V_79 = F_2 ( V_2 , V_30 ) ;
V_79 |= V_31 ;
V_6 = F_4 ( V_2 , V_30 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
F_26 ( 500 ) ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_16 ) ;
V_79 |= ( 7 << 12 ) ;
V_79 |= ( 1 << 11 ) ;
V_79 |= V_17 ;
V_6 = F_4 ( V_2 , V_16 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_80 ) ;
V_79 |= ( 1 << 5 ) ;
V_79 |= ( 1 << 4 ) ;
V_6 = F_4 ( V_2 , V_80 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_30 ) ;
V_79 |= V_31 ;
V_6 = F_4 ( V_2 , V_30 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
F_26 ( 500 ) ;
return F_24 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_2 ( V_2 , V_81 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_82 ;
V_14 |= V_83 ;
V_14 = F_4 ( V_2 , V_81 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_24 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_6 ;
int V_79 ;
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
V_6 = F_4 ( V_2 , V_84 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 ) ;
if ( V_79 & V_89 )
V_79 |= V_90 ;
else
V_79 |= V_91 ;
return F_4 ( V_2 , V_87 , V_79 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_6 ;
int V_79 ;
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 ) ;
V_79 |= V_92 ;
V_79 |= V_93 ;
V_6 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_2 , V_77 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_6 ;
int V_79 ;
V_79 = F_2 ( V_2 , V_84 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 |= ( V_85 | V_86 ) ;
V_6 = F_4 ( V_2 , V_84 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 |
V_89 ) ;
V_79 |= 0x7 | V_93 ;
V_6 = F_4 ( V_2 , V_87 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_30 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
do
V_79 = F_2 ( V_2 , V_30 ) ;
while ( V_79 & V_31 );
V_79 = F_2 ( V_2 , V_87 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ ( V_88 |
V_89 ) ;
V_79 |= V_94 |
V_93 ;
return F_4 ( V_2 , V_87 , V_79 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
int V_6 ;
if ( F_17 ( V_2 ) ) {
V_6 = F_28 ( V_2 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_2 -> V_47 == V_95 ) {
V_6 = F_29 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_2 -> V_47 == V_96 ) {
V_6 = F_30 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_13 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_2 , V_30 , V_31 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_6 , V_5 ;
V_5 = F_5 ( V_2 , V_97 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = F_4 ( V_2 , V_98 ,
V_99 ) ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( V_2 , V_5 ) ;
return F_24 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_6 ;
int V_79 ;
if ( V_2 -> V_47 == V_95 ) {
V_6 = F_3 ( V_2 , 18 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_100 ) ;
V_79 &= ~ V_101 ;
V_79 |= V_102 ;
V_6 = F_4 ( V_2 , V_100 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 |= V_103 ;
V_6 = F_4 ( V_2 , V_100 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return F_32 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_30 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_16 ,
V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_10 ( V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_97 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_104 & V_105 )
V_6 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_6 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_13 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_2 , V_30 , V_31 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_13 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_4 ( V_2 , V_30 , V_31 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_6 ;
int V_79 = F_2 ( V_2 , V_106 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 |= ( V_107 | V_108 ) ;
V_6 = F_4 ( V_2 , V_106 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_104 & V_109 ) {
V_6 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , 0x1e ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= 0xf03f ;
V_79 |= 2 << 9 ;
V_79 |= 2 << 6 ;
V_6 = F_4 ( V_2 , 0x1e , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0x8000 ) ;
}
return V_6 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_79 = F_2 ( V_2 , V_110 ) ;
if ( V_79 < 0 )
return V_79 ;
V_79 &= ~ V_111 ;
V_79 |= V_112 ;
V_79 |= V_113 ;
return F_4 ( V_2 , V_110 , V_79 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x001b ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0x418f ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x0016 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0xa2da ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_47 == V_48 ) {
V_6 = F_37 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_2 -> V_47 == V_95 ) {
V_6 = F_38 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_13 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static T_3 F_40 ( T_3 V_114 )
{
T_3 V_56 = 0 ;
if ( V_114 & V_115 )
V_56 |= V_57 ;
if ( V_114 & V_116 )
V_56 |= V_59 ;
return V_56 ;
}
static int F_41 ( struct V_1 * V_2 , int V_117 )
{
int V_118 ;
if ( V_117 ) {
V_118 = F_2 ( V_2 , V_119 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ( V_118 & V_120 ) == 0 )
V_2 -> V_121 = 0 ;
else
V_2 -> V_121 = 1 ;
} else {
return F_42 ( V_2 ) ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
int V_117 )
{
int V_118 ;
int V_114 ;
int V_122 ;
V_118 = F_2 ( V_2 , V_119 ) ;
if ( V_118 < 0 )
return V_118 ;
V_114 = F_2 ( V_2 , V_123 ) ;
if ( V_114 < 0 )
return V_114 ;
V_122 = F_2 ( V_2 , V_124 ) ;
if ( V_122 < 0 )
return V_122 ;
if ( V_118 & V_125 )
V_2 -> V_126 = V_127 ;
else
V_2 -> V_126 = V_128 ;
V_118 = V_118 & V_129 ;
V_2 -> V_130 = 0 ;
V_2 -> V_131 = 0 ;
switch ( V_118 ) {
case V_132 :
V_2 -> V_133 = V_134 ;
break;
case V_135 :
V_2 -> V_133 = V_136 ;
break;
default:
V_2 -> V_133 = V_137 ;
break;
}
if ( ! V_117 ) {
V_2 -> V_138 =
F_44 ( V_122 ) |
F_45 ( V_114 ) ;
if ( V_2 -> V_126 == V_127 ) {
V_2 -> V_130 = V_114 & V_139 ? 1 : 0 ;
V_2 -> V_131 = V_114 & V_140 ? 1 : 0 ;
}
} else {
V_2 -> V_138 = F_40 ( V_114 ) ;
if ( V_2 -> V_126 == V_127 ) {
if ( ! ( V_114 & V_73 ) ) {
V_2 -> V_130 = 0 ;
V_2 -> V_131 = 0 ;
} else if ( ( V_114 & V_63 ) ) {
V_2 -> V_130 = 1 ;
V_2 -> V_131 = 1 ;
} else {
V_2 -> V_130 = 1 ;
V_2 -> V_131 = 0 ;
}
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_29 = F_2 ( V_2 , V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_141 )
V_2 -> V_126 = V_127 ;
else
V_2 -> V_126 = V_128 ;
if ( V_29 & V_142 )
V_2 -> V_133 = V_134 ;
else if ( V_29 & V_143 )
V_2 -> V_133 = V_136 ;
else
V_2 -> V_133 = V_137 ;
V_2 -> V_130 = 0 ;
V_2 -> V_131 = 0 ;
V_2 -> V_138 = 0 ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_4 )
{
int V_117 ;
int V_6 ;
if ( V_4 == V_78 )
V_117 = 1 ;
else
V_117 = 0 ;
V_6 = F_41 ( V_2 , V_117 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_27 == V_28 )
V_6 = F_43 ( V_2 , V_117 ) ;
else
V_6 = F_46 ( V_2 ) ;
return V_6 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_71 & V_144 &&
V_2 -> V_47 != V_95 ) {
V_6 = F_3 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_47 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
goto error;
if ( V_2 -> V_121 )
return 0 ;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
goto error;
}
return F_47 ( V_2 , V_77 ) ;
error:
F_3 ( V_2 , V_77 ) ;
return V_6 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! ( V_2 -> V_71 & V_144 ) ) {
V_6 = F_3 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_50 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
goto error;
}
return F_50 ( V_2 ) ;
error:
F_3 ( V_2 , V_77 ) ;
return V_6 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! ( V_2 -> V_71 & V_144 ) ) {
V_6 = F_3 ( V_2 , V_78 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_52 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
goto error;
}
return F_52 ( V_2 ) ;
error:
F_3 ( V_2 , V_77 ) ;
return V_6 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_145 = F_2 ( V_2 , V_119 ) ;
return ( V_145 < 0 ) ? V_145 : ( V_145 & V_146 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_147 ;
V_147 = F_2 ( V_2 , V_7 ) ;
if ( V_147 & V_11 )
return 1 ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
V_149 -> V_71 = V_150 ;
V_149 -> V_151 = 0 ;
if ( F_3 ( V_2 , V_152 ) < 0 )
return;
if ( F_2 ( V_2 , V_153 ) &
V_154 )
V_149 -> V_151 |= V_150 ;
if ( F_3 ( V_2 , V_77 ) < 0 )
return;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
int V_6 , V_5 , V_79 ;
V_5 = F_1 ( V_2 ) ;
if ( V_149 -> V_151 & V_150 ) {
V_6 = F_3 ( V_2 , V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_155 ) ;
V_79 |= V_156 ;
V_6 = F_4 ( V_2 , V_155 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_97 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_157 ) ;
V_79 &= ~ V_158 ;
V_79 |= V_159 ;
V_79 |= V_160 ;
V_6 = F_4 ( V_2 , V_157 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_152 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_161 ,
( ( V_2 -> V_162 -> V_163 [ 5 ] << 8 ) |
V_2 -> V_162 -> V_163 [ 4 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_164 ,
( ( V_2 -> V_162 -> V_163 [ 3 ] << 8 ) |
V_2 -> V_162 -> V_163 [ 2 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_165 ,
( ( V_2 -> V_162 -> V_163 [ 1 ] << 8 ) |
V_2 -> V_162 -> V_163 [ 0 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_153 ) ;
V_79 |= V_166 ;
V_79 |= V_154 ;
V_6 = F_4 ( V_2 , V_153 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
V_6 = F_3 ( V_2 , V_152 ) ;
if ( V_6 < 0 )
return V_6 ;
V_79 = F_2 ( V_2 , V_153 ) ;
V_79 |= V_166 ;
V_79 &= ~ V_154 ;
V_6 = F_4 ( V_2 , V_153 , V_79 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_3 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 & V_144 )
return F_58 ( V_167 ) ;
else
return F_58 ( V_167 ) - V_168 ;
}
static void F_59 ( struct V_1 * V_2 , T_4 * V_169 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_58 ( V_167 ) ; V_34 ++ ) {
memcpy ( V_169 + V_34 * V_170 ,
V_167 [ V_34 ] . string , V_170 ) ;
}
}
static T_5 F_60 ( struct V_1 * V_2 , int V_34 )
{
struct V_171 V_172 = V_167 [ V_34 ] ;
struct V_173 * V_174 = V_2 -> V_174 ;
int V_5 , V_15 ;
T_5 V_37 ;
V_5 = F_5 ( V_2 , V_172 . V_4 ) ;
if ( V_5 < 0 )
return V_175 ;
V_15 = F_2 ( V_2 , V_172 . V_14 ) ;
if ( V_15 < 0 ) {
V_37 = V_175 ;
} else {
V_15 = V_15 & ( ( 1 << V_172 . V_176 ) - 1 ) ;
V_174 -> V_177 [ V_34 ] += V_15 ;
V_37 = V_174 -> V_177 [ V_34 ] ;
}
F_3 ( V_2 , V_5 ) ;
return V_37 ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_178 * V_177 , T_5 * V_169 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_58 ( V_167 ) ; V_34 ++ )
V_169 [ V_34 ] = F_60 ( V_2 , V_34 ) ;
}
static int F_62 ( struct V_1 * V_2 , long * V_79 )
{
int V_5 ;
int V_37 ;
int V_15 ;
* V_79 = 0 ;
F_63 ( & V_2 -> V_179 ) ;
V_5 = F_5 ( V_2 , V_180 ) ;
if ( V_5 < 0 ) {
F_64 ( & V_2 -> V_179 ) ;
return V_5 ;
}
V_37 = F_2 ( V_2 , V_181 ) ;
if ( V_37 < 0 )
goto error;
V_37 = F_4 ( V_2 , V_181 ,
V_37 | V_182 ) ;
if ( V_37 < 0 )
goto error;
F_65 ( 10000 , 12000 ) ;
V_15 = F_2 ( V_2 , V_181 ) ;
if ( V_15 < 0 ) {
V_37 = V_15 ;
goto error;
}
V_37 = F_4 ( V_2 , V_181 ,
V_37 & ~ V_182 ) ;
if ( V_37 < 0 )
goto error;
* V_79 = ( ( V_15 & V_183 ) - 5 ) * 5000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_64 ( & V_2 -> V_179 ) ;
return V_37 ;
}
static int F_66 ( struct V_184 * V_39 ,
enum V_185 type ,
T_3 V_186 , int V_187 , long * V_79 )
{
struct V_1 * V_2 = F_67 ( V_39 ) ;
int V_6 ;
switch ( V_186 ) {
case V_188 :
V_6 = F_62 ( V_2 , V_79 ) ;
break;
default:
return - V_189 ;
}
return V_6 ;
}
static T_6 F_68 ( const void * V_169 ,
enum V_185 type ,
T_3 V_186 , int V_187 )
{
if ( type != V_190 )
return 0 ;
switch ( V_186 ) {
case V_188 :
return 0444 ;
default:
return 0 ;
}
}
static int F_69 ( struct V_1 * V_2 , long * V_79 )
{
int V_5 ;
int V_37 ;
* V_79 = 0 ;
F_63 ( & V_2 -> V_179 ) ;
V_5 = F_5 ( V_2 , V_180 ) ;
if ( V_5 < 0 ) {
F_64 ( & V_2 -> V_179 ) ;
return V_5 ;
}
V_37 = F_2 ( V_2 , V_191 ) ;
if ( V_37 < 0 )
goto error;
* V_79 = ( ( V_37 & V_192 ) - 25 ) * 1000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_64 ( & V_2 -> V_179 ) ;
return V_37 ;
}
static int F_70 ( struct V_1 * V_2 , long * V_79 )
{
int V_5 ;
int V_37 ;
* V_79 = 0 ;
F_63 ( & V_2 -> V_179 ) ;
V_5 = F_5 ( V_2 , V_180 ) ;
if ( V_5 < 0 ) {
F_64 ( & V_2 -> V_179 ) ;
return V_5 ;
}
V_37 = F_2 ( V_2 , V_181 ) ;
if ( V_37 < 0 )
goto error;
* V_79 = ( ( ( V_37 & V_193 ) >>
V_194 ) * 5 ) - 25 ;
* V_79 *= 1000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_64 ( & V_2 -> V_179 ) ;
return V_37 ;
}
static int F_71 ( struct V_1 * V_2 , long V_79 )
{
int V_5 ;
int V_37 ;
F_63 ( & V_2 -> V_179 ) ;
V_5 = F_5 ( V_2 , V_180 ) ;
if ( V_5 < 0 ) {
F_64 ( & V_2 -> V_179 ) ;
return V_5 ;
}
V_37 = F_2 ( V_2 , V_181 ) ;
if ( V_37 < 0 )
goto error;
V_79 = V_79 / 1000 ;
V_79 = F_72 ( F_73 ( V_79 , 5 ) + 5 , 0 , 0x1f ) ;
V_37 = F_4 ( V_2 , V_181 ,
( V_37 & ~ V_193 ) |
( V_79 << V_194 ) ) ;
error:
F_3 ( V_2 , V_5 ) ;
F_64 ( & V_2 -> V_179 ) ;
return V_37 ;
}
static int F_74 ( struct V_1 * V_2 , long * V_195 )
{
int V_5 ;
int V_37 ;
* V_195 = false ;
F_63 ( & V_2 -> V_179 ) ;
V_5 = F_5 ( V_2 , V_180 ) ;
if ( V_5 < 0 ) {
F_64 ( & V_2 -> V_179 ) ;
return V_5 ;
}
V_37 = F_2 ( V_2 , V_181 ) ;
if ( V_37 < 0 )
goto error;
* V_195 = ! ! ( V_37 & V_196 ) ;
error:
F_3 ( V_2 , V_5 ) ;
F_64 ( & V_2 -> V_179 ) ;
return V_37 ;
}
static int F_75 ( struct V_184 * V_39 ,
enum V_185 type ,
T_3 V_186 , int V_187 , long * V_79 )
{
struct V_1 * V_2 = F_67 ( V_39 ) ;
int V_6 ;
switch ( V_186 ) {
case V_188 :
V_6 = F_69 ( V_2 , V_79 ) ;
break;
case V_197 :
V_6 = F_70 ( V_2 , V_79 ) ;
break;
case V_198 :
V_6 = F_74 ( V_2 , V_79 ) ;
break;
default:
return - V_189 ;
}
return V_6 ;
}
static int F_76 ( struct V_184 * V_39 ,
enum V_185 type ,
T_3 V_186 , int V_187 , long V_79 )
{
struct V_1 * V_2 = F_67 ( V_39 ) ;
int V_6 ;
switch ( V_186 ) {
case V_197 :
V_6 = F_71 ( V_2 , V_79 ) ;
break;
default:
return - V_189 ;
}
return V_6 ;
}
static T_6 F_77 ( const void * V_169 ,
enum V_185 type ,
T_3 V_186 , int V_187 )
{
if ( type != V_190 )
return 0 ;
switch ( V_186 ) {
case V_188 :
case V_198 :
return 0444 ;
case V_197 :
return 0644 ;
default:
return 0 ;
}
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = V_2 -> V_174 ;
struct V_184 * V_39 = & V_2 -> V_38 . V_39 ;
const char * V_199 = F_79 ( V_39 ) ;
T_7 V_33 = strlen ( V_199 ) ;
int V_34 , V_200 ;
V_174 -> V_201 = F_80 ( V_39 , V_33 , V_202 ) ;
if ( ! V_174 -> V_201 )
return - V_203 ;
for ( V_34 = V_200 = 0 ; V_34 < V_33 && V_199 [ V_34 ] ; V_34 ++ ) {
if ( isalnum ( V_199 [ V_34 ] ) )
V_174 -> V_201 [ V_200 ++ ] = V_199 [ V_34 ] ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
const struct V_204 * V_205 )
{
struct V_173 * V_174 = V_2 -> V_174 ;
struct V_184 * V_39 = & V_2 -> V_38 . V_39 ;
int V_6 ;
V_6 = F_78 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_174 -> V_206 = F_82 (
V_39 , V_174 -> V_201 , V_2 , V_205 , NULL ) ;
return F_83 ( V_174 -> V_206 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
return F_81 ( V_2 , & V_207 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_81 ( V_2 , & V_208 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_173 * V_174 ;
V_174 = F_80 ( & V_2 -> V_38 . V_39 , sizeof( * V_174 ) , V_202 ) ;
if ( ! V_174 )
return - V_203 ;
V_2 -> V_174 = V_174 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_86 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_84 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_86 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_85 ( V_2 ) ;
}
