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
static int F_9 ( struct V_1 * V_2 , bool V_24 ,
T_1 V_25 )
{
int V_14 ;
V_14 = F_2 ( V_2 , V_16 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= V_26 ;
V_14 |= ( ( V_25 - 1 ) << V_27 ) ;
if ( V_24 )
V_14 |= V_28 ;
return F_4 ( V_2 , V_16 , V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_30 ,
V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_32 != V_33 ) {
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_12 ( V_2 ) ;
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
return F_10 ( V_2 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_12 ( V_2 ) ;
V_6 = F_8 ( V_2 , V_2 -> V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_30 ,
V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_32 != V_33 ) {
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
const T_2 * V_34 ;
int V_35 , V_36 , V_37 , V_38 , V_39 ;
if ( ! V_2 -> V_40 . V_41 . V_42 )
return 0 ;
V_34 = F_16 ( V_2 -> V_40 . V_41 . V_42 ,
L_1 , & V_35 ) ;
if ( ! V_34 || V_35 < ( 4 * sizeof( * V_34 ) ) )
return 0 ;
V_37 = F_1 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
V_38 = V_37 ;
V_39 = 0 ;
V_35 /= sizeof( * V_34 ) ;
for ( V_36 = 0 ; V_36 < V_35 - 3 ; V_36 += 4 ) {
T_3 V_4 = F_17 ( V_34 + V_36 ) ;
T_3 V_14 = F_17 ( V_34 + V_36 + 1 ) ;
T_3 V_43 = F_17 ( V_34 + V_36 + 2 ) ;
T_3 V_44 = F_17 ( V_34 + V_36 + 3 ) ;
int V_15 ;
if ( V_4 != V_38 ) {
V_38 = V_4 ;
V_39 = F_3 ( V_2 , V_4 ) ;
if ( V_39 < 0 )
goto V_6;
}
V_15 = 0 ;
if ( V_43 ) {
V_15 = F_2 ( V_2 , V_14 ) ;
if ( V_15 < 0 ) {
V_39 = V_15 ;
goto V_6;
}
V_15 &= V_43 ;
}
V_15 |= V_44 ;
V_39 = F_4 ( V_2 , V_14 , V_15 ) ;
if ( V_39 < 0 )
goto V_6;
}
V_6:
if ( V_38 != V_37 ) {
V_36 = F_3 ( V_2 , V_37 ) ;
if ( V_39 == 0 )
V_39 = V_36 ;
}
return V_39 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_6 , V_5 , V_45 ;
V_5 = F_5 ( V_2 , V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
V_45 = F_2 ( V_2 , V_47 ) ;
if ( V_45 < 0 ) {
V_6 = V_45 ;
goto V_48;
}
V_45 &= V_49 ;
if ( V_2 -> V_50 == V_51 )
V_45 |= ( V_52 |
V_53 ) ;
else if ( V_2 -> V_50 == V_54 )
V_45 |= V_52 ;
else if ( V_2 -> V_50 == V_55 )
V_45 |= V_53 ;
V_6 = F_4 ( V_2 , V_47 , V_45 ) ;
V_48:
F_3 ( V_2 , V_5 ) ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_6 = 0 ;
if ( F_20 ( V_2 ) ) {
V_6 = F_18 ( V_2 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_11 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 , V_5 , V_45 ;
V_5 = F_5 ( V_2 , V_46 ) ;
if ( V_5 < 0 )
return V_5 ;
V_45 = F_2 ( V_2 , V_56 ) ;
V_45 |= V_57 ;
V_6 = F_4 ( V_2 , V_56 , V_45 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_19 ( V_2 ) ;
}
static inline T_4 F_22 ( T_4 V_58 )
{
T_4 V_59 = 0 ;
if ( V_58 & V_60 )
V_59 |= V_61 ;
if ( V_58 & V_62 )
V_59 |= V_63 ;
if ( ( V_58 & V_64 ) && ( V_58 & V_65 ) )
V_59 |= V_66 ;
else if ( V_58 & V_65 )
V_59 |= ( V_67
& ( ~ V_68 ) ) ;
return V_59 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_69 = 0 ;
int V_6 ;
int V_70 , V_71 ;
T_4 V_72 ;
if ( V_2 -> V_32 != V_33 )
return F_24 ( V_2 ) ;
V_2 -> V_73 &= V_2 -> V_74 ;
V_72 = V_2 -> V_73 ;
V_70 = F_2 ( V_2 , V_75 ) ;
if ( V_70 < 0 )
return V_70 ;
V_71 = V_70 ;
V_70 &= ~ ( V_61 | V_63
| V_76 ) ;
V_70 |= F_22 ( V_72 ) ;
if ( V_70 != V_71 ) {
V_6 = F_4 ( V_2 , V_75 , V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
V_69 = 1 ;
}
if ( V_69 == 0 ) {
int V_77 = F_2 ( V_2 , V_78 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( ! ( V_77 & V_79 ) || ( V_77 & V_80 ) )
V_69 = 1 ;
}
if ( V_69 > 0 )
V_69 = F_25 ( V_2 ) ;
return V_69 ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_21 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_82 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_23 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
return F_3 ( V_2 , V_81 ) ;
error:
F_3 ( V_2 , V_81 ) ;
return V_6 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return F_15 ( V_2 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
F_29 ( 500 ) ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( V_2 , true , 8 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_20 ( V_2 ) ) {
V_6 = F_18 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_27 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_2 ( V_2 , V_83 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 &= ~ V_84 ;
V_14 |= V_85 ;
V_14 = F_4 ( V_2 , V_83 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_27 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
T_3 V_86 ,
int V_87 )
{
int V_88 ;
V_88 = F_2 ( V_2 , V_89 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 &= ~ ( V_90 |
V_91 |
V_92 ) ;
V_88 |= V_86 ;
if ( V_87 )
V_88 |= V_91 ;
return F_4 ( V_2 , V_89 , V_88 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_88 ;
V_88 = F_2 ( V_2 , V_93 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( V_2 -> V_50 == V_51 ) {
V_88 |= ( V_94 | V_95 ) ;
} else if ( V_2 -> V_50 == V_54 ) {
V_88 &= ~ V_95 ;
V_88 |= V_94 ;
} else if ( V_2 -> V_50 == V_55 ) {
V_88 &= ~ V_94 ;
V_88 |= V_95 ;
}
return F_4 ( V_2 , V_93 , V_88 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_88 ;
int V_6 ;
V_6 = F_32 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_89 ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 &= ~ ( V_90 ) ;
if ( V_88 & V_92 )
V_88 |= V_96 ;
else
V_88 |= V_97 ;
return F_4 ( V_2 , V_89 , V_88 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_31 (
V_2 ,
V_98 ,
V_91 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_3 ( V_2 , V_81 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_32 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_31 (
V_2 ,
V_99 ,
V_91 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_31 (
V_2 ,
V_99 ,
V_91 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_6 ;
if ( F_20 ( V_2 ) ) {
V_6 = F_33 ( V_2 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_2 -> V_50 == V_100 ) {
V_6 = F_34 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_2 -> V_50 == V_101 ) {
V_6 = F_35 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_2 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_6 , V_5 ;
V_5 = F_5 ( V_2 , V_102 ) ;
if ( V_5 < 0 )
return V_5 ;
V_6 = F_4 ( V_2 , V_103 ,
V_104 ) ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( V_2 , V_5 ) ;
return F_27 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_6 ;
int V_88 ;
if ( V_2 -> V_50 == V_100 ) {
V_6 = F_3 ( V_2 , 18 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_105 ) ;
V_88 &= ~ V_106 ;
V_88 |= V_107 ;
V_6 = F_4 ( V_2 , V_105 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 |= V_108 ;
V_6 = F_4 ( V_2 , V_105 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
}
return F_37 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_12 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_8 ( V_2 , V_2 -> V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_11 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_46 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x15 , 0x1070 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_102 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_109 & V_110 )
V_6 = F_4 ( V_2 , 0x10 , 0x1100 ) ;
else
V_6 = F_4 ( V_2 , 0x10 , 0x021e ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_2 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 , V_46 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x15 , 0x1048 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_12 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_88 ;
int V_6 ;
V_6 = F_32 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_2 -> V_109 & V_111 ) {
V_6 = F_4 ( V_2 , 0x1d , 0x0012 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , 0x1e ) ;
if ( V_88 < 0 )
return V_88 ;
V_88 &= 0xf03f ;
V_88 |= 2 << 9 ;
V_88 |= 2 << 6 ;
V_6 = F_4 ( V_2 , 0x1e , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1d , 0x3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , 0x1e , 0x8000 ) ;
}
return V_6 ;
}
static int F_43 ( struct V_1 * V_2 )
{
return F_31 (
V_2 , V_98 ,
V_91 ) ;
}
static int F_44 ( struct V_1 * V_2 )
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
if ( V_2 -> V_50 == V_51 ) {
V_6 = F_42 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_2 -> V_50 == V_100 ) {
V_6 = F_43 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_15 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static T_4 F_45 ( T_4 V_112 )
{
T_4 V_59 = 0 ;
if ( V_112 & V_113 )
V_59 |= V_60 ;
if ( V_112 & V_114 )
V_59 |= V_62 ;
return V_59 ;
}
static int F_46 ( struct V_1 * V_2 , int V_115 )
{
int V_116 ;
if ( V_115 ) {
V_116 = F_2 ( V_2 , V_117 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( ( V_116 & V_118 ) == 0 )
V_2 -> V_119 = 0 ;
else
V_2 -> V_119 = 1 ;
} else {
return F_47 ( V_2 ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
int V_115 )
{
int V_116 ;
int V_112 ;
int V_120 ;
V_116 = F_2 ( V_2 , V_117 ) ;
if ( V_116 < 0 )
return V_116 ;
V_112 = F_2 ( V_2 , V_121 ) ;
if ( V_112 < 0 )
return V_112 ;
V_120 = F_2 ( V_2 , V_122 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( V_116 & V_123 )
V_2 -> V_124 = V_125 ;
else
V_2 -> V_124 = V_126 ;
V_116 = V_116 & V_127 ;
V_2 -> V_128 = 0 ;
V_2 -> V_129 = 0 ;
switch ( V_116 ) {
case V_130 :
V_2 -> V_131 = V_132 ;
break;
case V_133 :
V_2 -> V_131 = V_134 ;
break;
default:
V_2 -> V_131 = V_135 ;
break;
}
if ( ! V_115 ) {
V_2 -> V_136 =
F_49 ( V_120 ) |
F_50 ( V_112 ) ;
if ( V_2 -> V_124 == V_125 ) {
V_2 -> V_128 = V_112 & V_137 ? 1 : 0 ;
V_2 -> V_129 = V_112 & V_138 ? 1 : 0 ;
}
} else {
V_2 -> V_136 = F_45 ( V_112 ) ;
if ( V_2 -> V_124 == V_125 ) {
if ( ! ( V_112 & V_76 ) ) {
V_2 -> V_128 = 0 ;
V_2 -> V_129 = 0 ;
} else if ( ( V_112 & V_66 ) ) {
V_2 -> V_128 = 1 ;
V_2 -> V_129 = 1 ;
} else {
V_2 -> V_128 = 1 ;
V_2 -> V_129 = 0 ;
}
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_139 = F_2 ( V_2 , V_78 ) ;
if ( V_139 < 0 )
return V_139 ;
if ( V_139 & V_140 )
V_2 -> V_124 = V_125 ;
else
V_2 -> V_124 = V_126 ;
if ( V_139 & V_141 )
V_2 -> V_131 = V_132 ;
else if ( V_139 & V_142 )
V_2 -> V_131 = V_134 ;
else
V_2 -> V_131 = V_135 ;
V_2 -> V_128 = 0 ;
V_2 -> V_129 = 0 ;
V_2 -> V_136 = 0 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int V_4 )
{
int V_115 ;
int V_6 ;
if ( V_4 == V_82 )
V_115 = 1 ;
else
V_115 = 0 ;
V_6 = F_46 ( V_2 , V_115 ) ;
if ( V_6 )
return V_6 ;
if ( V_2 -> V_32 == V_33 )
V_6 = F_48 ( V_2 , V_115 ) ;
else
V_6 = F_51 ( V_2 ) ;
return V_6 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_6 ;
if ( V_2 -> V_74 & V_143 &&
V_2 -> V_50 != V_100 ) {
V_6 = F_3 ( V_2 , V_82 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_52 ( V_2 , V_82 ) ;
if ( V_6 < 0 )
goto error;
if ( V_2 -> V_119 )
return 0 ;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
goto error;
}
return F_52 ( V_2 , V_81 ) ;
error:
F_3 ( V_2 , V_81 ) ;
return V_6 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! ( V_2 -> V_74 & V_143 ) ) {
V_6 = F_3 ( V_2 , V_82 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_55 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
goto error;
}
return F_55 ( V_2 ) ;
error:
F_3 ( V_2 , V_81 ) ;
return V_6 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! ( V_2 -> V_74 & V_143 ) ) {
V_6 = F_3 ( V_2 , V_82 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_57 ( V_2 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
goto error;
}
return F_57 ( V_2 ) ;
error:
F_3 ( V_2 , V_81 ) ;
return V_6 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_144 = F_2 ( V_2 , V_117 ) ;
return ( V_144 < 0 ) ? V_144 : ( V_144 & V_145 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_146 ;
V_146 = F_2 ( V_2 , V_7 ) ;
if ( V_146 & V_11 )
return 1 ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
V_148 -> V_74 = V_149 ;
V_148 -> V_150 = 0 ;
if ( F_3 ( V_2 , V_151 ) < 0 )
return;
if ( F_2 ( V_2 , V_152 ) &
V_153 )
V_148 -> V_150 |= V_149 ;
if ( F_3 ( V_2 , V_81 ) < 0 )
return;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
int V_6 , V_5 , V_88 ;
V_5 = F_1 ( V_2 ) ;
if ( V_148 -> V_150 & V_149 ) {
V_6 = F_3 ( V_2 , V_81 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_154 ) ;
V_88 |= V_155 ;
V_6 = F_4 ( V_2 , V_154 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_102 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_156 ) ;
V_88 &= ~ V_157 ;
V_88 |= V_158 ;
V_88 |= V_159 ;
V_6 = F_4 ( V_2 , V_156 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_2 , V_151 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_160 ,
( ( V_2 -> V_161 -> V_162 [ 5 ] << 8 ) |
V_2 -> V_161 -> V_162 [ 4 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_163 ,
( ( V_2 -> V_161 -> V_162 [ 3 ] << 8 ) |
V_2 -> V_161 -> V_162 [ 2 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 , V_164 ,
( ( V_2 -> V_161 -> V_162 [ 1 ] << 8 ) |
V_2 -> V_161 -> V_162 [ 0 ] ) ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_152 ) ;
V_88 |= V_165 ;
V_88 |= V_153 ;
V_6 = F_4 ( V_2 , V_152 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
} else {
V_6 = F_3 ( V_2 , V_151 ) ;
if ( V_6 < 0 )
return V_6 ;
V_88 = F_2 ( V_2 , V_152 ) ;
V_88 |= V_165 ;
V_88 &= ~ V_153 ;
V_6 = F_4 ( V_2 , V_152 , V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
}
V_6 = F_3 ( V_2 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_74 & V_143 )
return F_63 ( V_166 ) ;
else
return F_63 ( V_166 ) - V_167 ;
}
static void F_64 ( struct V_1 * V_2 , T_1 * V_168 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_63 ( V_166 ) ; V_36 ++ ) {
memcpy ( V_168 + V_36 * V_169 ,
V_166 [ V_36 ] . string , V_169 ) ;
}
}
static T_5 F_65 ( struct V_1 * V_2 , int V_36 )
{
struct V_170 V_171 = V_166 [ V_36 ] ;
struct V_172 * V_173 = V_2 -> V_173 ;
int V_5 , V_15 ;
T_5 V_39 ;
V_5 = F_5 ( V_2 , V_171 . V_4 ) ;
if ( V_5 < 0 )
return V_174 ;
V_15 = F_2 ( V_2 , V_171 . V_14 ) ;
if ( V_15 < 0 ) {
V_39 = V_174 ;
} else {
V_15 = V_15 & ( ( 1 << V_171 . V_175 ) - 1 ) ;
V_173 -> V_176 [ V_36 ] += V_15 ;
V_39 = V_173 -> V_176 [ V_36 ] ;
}
F_3 ( V_2 , V_5 ) ;
return V_39 ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_177 * V_176 , T_5 * V_168 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_63 ( V_166 ) ; V_36 ++ )
V_168 [ V_36 ] = F_65 ( V_2 , V_36 ) ;
}
static int F_67 ( struct V_1 * V_2 , long * V_88 )
{
int V_5 ;
int V_39 ;
int V_15 ;
* V_88 = 0 ;
F_68 ( & V_2 -> V_178 ) ;
V_5 = F_5 ( V_2 , V_179 ) ;
if ( V_5 < 0 ) {
F_69 ( & V_2 -> V_178 ) ;
return V_5 ;
}
V_39 = F_2 ( V_2 , V_180 ) ;
if ( V_39 < 0 )
goto error;
V_39 = F_4 ( V_2 , V_180 ,
V_39 | V_181 ) ;
if ( V_39 < 0 )
goto error;
F_70 ( 10000 , 12000 ) ;
V_15 = F_2 ( V_2 , V_180 ) ;
if ( V_15 < 0 ) {
V_39 = V_15 ;
goto error;
}
V_39 = F_4 ( V_2 , V_180 ,
V_39 & ~ V_181 ) ;
if ( V_39 < 0 )
goto error;
* V_88 = ( ( V_15 & V_182 ) - 5 ) * 5000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_69 ( & V_2 -> V_178 ) ;
return V_39 ;
}
static int F_71 ( struct V_183 * V_41 ,
enum V_184 type ,
T_4 V_185 , int V_186 , long * V_88 )
{
struct V_1 * V_2 = F_72 ( V_41 ) ;
int V_6 ;
switch ( V_185 ) {
case V_187 :
V_6 = F_67 ( V_2 , V_88 ) ;
break;
default:
return - V_188 ;
}
return V_6 ;
}
static T_6 F_73 ( const void * V_168 ,
enum V_184 type ,
T_4 V_185 , int V_186 )
{
if ( type != V_189 )
return 0 ;
switch ( V_185 ) {
case V_187 :
return 0444 ;
default:
return 0 ;
}
}
static int F_74 ( struct V_1 * V_2 , long * V_88 )
{
int V_5 ;
int V_39 ;
* V_88 = 0 ;
F_68 ( & V_2 -> V_178 ) ;
V_5 = F_5 ( V_2 , V_179 ) ;
if ( V_5 < 0 ) {
F_69 ( & V_2 -> V_178 ) ;
return V_5 ;
}
V_39 = F_2 ( V_2 , V_190 ) ;
if ( V_39 < 0 )
goto error;
* V_88 = ( ( V_39 & V_191 ) - 25 ) * 1000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_69 ( & V_2 -> V_178 ) ;
return V_39 ;
}
static int F_75 ( struct V_1 * V_2 , long * V_88 )
{
int V_5 ;
int V_39 ;
* V_88 = 0 ;
F_68 ( & V_2 -> V_178 ) ;
V_5 = F_5 ( V_2 , V_179 ) ;
if ( V_5 < 0 ) {
F_69 ( & V_2 -> V_178 ) ;
return V_5 ;
}
V_39 = F_2 ( V_2 , V_180 ) ;
if ( V_39 < 0 )
goto error;
* V_88 = ( ( ( V_39 & V_192 ) >>
V_193 ) * 5 ) - 25 ;
* V_88 *= 1000 ;
error:
F_3 ( V_2 , V_5 ) ;
F_69 ( & V_2 -> V_178 ) ;
return V_39 ;
}
static int F_76 ( struct V_1 * V_2 , long V_88 )
{
int V_5 ;
int V_39 ;
F_68 ( & V_2 -> V_178 ) ;
V_5 = F_5 ( V_2 , V_179 ) ;
if ( V_5 < 0 ) {
F_69 ( & V_2 -> V_178 ) ;
return V_5 ;
}
V_39 = F_2 ( V_2 , V_180 ) ;
if ( V_39 < 0 )
goto error;
V_88 = V_88 / 1000 ;
V_88 = F_77 ( F_78 ( V_88 , 5 ) + 5 , 0 , 0x1f ) ;
V_39 = F_4 ( V_2 , V_180 ,
( V_39 & ~ V_192 ) |
( V_88 << V_193 ) ) ;
error:
F_3 ( V_2 , V_5 ) ;
F_69 ( & V_2 -> V_178 ) ;
return V_39 ;
}
static int F_79 ( struct V_1 * V_2 , long * V_194 )
{
int V_5 ;
int V_39 ;
* V_194 = false ;
F_68 ( & V_2 -> V_178 ) ;
V_5 = F_5 ( V_2 , V_179 ) ;
if ( V_5 < 0 ) {
F_69 ( & V_2 -> V_178 ) ;
return V_5 ;
}
V_39 = F_2 ( V_2 , V_180 ) ;
if ( V_39 < 0 )
goto error;
* V_194 = ! ! ( V_39 & V_195 ) ;
error:
F_3 ( V_2 , V_5 ) ;
F_69 ( & V_2 -> V_178 ) ;
return V_39 ;
}
static int F_80 ( struct V_183 * V_41 ,
enum V_184 type ,
T_4 V_185 , int V_186 , long * V_88 )
{
struct V_1 * V_2 = F_72 ( V_41 ) ;
int V_6 ;
switch ( V_185 ) {
case V_187 :
V_6 = F_74 ( V_2 , V_88 ) ;
break;
case V_196 :
V_6 = F_75 ( V_2 , V_88 ) ;
break;
case V_197 :
V_6 = F_79 ( V_2 , V_88 ) ;
break;
default:
return - V_188 ;
}
return V_6 ;
}
static int F_81 ( struct V_183 * V_41 ,
enum V_184 type ,
T_4 V_185 , int V_186 , long V_88 )
{
struct V_1 * V_2 = F_72 ( V_41 ) ;
int V_6 ;
switch ( V_185 ) {
case V_196 :
V_6 = F_76 ( V_2 , V_88 ) ;
break;
default:
return - V_188 ;
}
return V_6 ;
}
static T_6 F_82 ( const void * V_168 ,
enum V_184 type ,
T_4 V_185 , int V_186 )
{
if ( type != V_189 )
return 0 ;
switch ( V_185 ) {
case V_187 :
case V_197 :
return 0444 ;
case V_196 :
return 0644 ;
default:
return 0 ;
}
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_172 * V_173 = V_2 -> V_173 ;
struct V_183 * V_41 = & V_2 -> V_40 . V_41 ;
const char * V_198 = F_84 ( V_41 ) ;
T_7 V_35 = strlen ( V_198 ) ;
int V_36 , V_199 ;
V_173 -> V_200 = F_85 ( V_41 , V_35 , V_201 ) ;
if ( ! V_173 -> V_200 )
return - V_202 ;
for ( V_36 = V_199 = 0 ; V_36 < V_35 && V_198 [ V_36 ] ; V_36 ++ ) {
if ( isalnum ( V_198 [ V_36 ] ) )
V_173 -> V_200 [ V_199 ++ ] = V_198 [ V_36 ] ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_203 * V_204 )
{
struct V_172 * V_173 = V_2 -> V_173 ;
struct V_183 * V_41 = & V_2 -> V_40 . V_41 ;
int V_6 ;
V_6 = F_83 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_173 -> V_205 = F_87 (
V_41 , V_173 -> V_200 , V_2 , V_204 , NULL ) ;
return F_88 ( V_173 -> V_205 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
return F_86 ( V_2 , & V_206 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
return F_86 ( V_2 , & V_207 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_90 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
V_173 = F_85 ( & V_2 -> V_40 . V_41 , sizeof( * V_173 ) , V_201 ) ;
if ( ! V_173 )
return - V_202 ;
V_2 -> V_173 = V_173 ;
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_91 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_89 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_91 ( V_2 ) ;
if ( V_6 )
return V_6 ;
return F_90 ( V_2 ) ;
}
