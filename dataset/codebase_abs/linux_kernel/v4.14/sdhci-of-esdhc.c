static T_1 F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_9 ;
if ( ( V_3 == V_10 ) && ( V_4 & V_11 ) ) {
if ( V_8 -> V_12 > V_13 ) {
V_9 = V_4 | V_14 ;
return V_9 ;
}
}
if ( V_3 == V_15 ) {
V_9 = V_4 & 0x000fffff ;
V_9 |= ( V_4 >> 4 ) & V_16 ;
V_9 |= ( V_4 << 1 ) & V_17 ;
return V_9 ;
}
if ( V_3 == V_18 ) {
V_9 = V_4 & ~ ( V_19 | V_20 |
V_21 ) ;
return V_9 ;
}
V_9 = V_4 ;
return V_9 ;
}
static T_2 F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_2 V_9 ;
int V_22 = ( V_3 & 0x2 ) * 8 ;
if ( V_3 == V_23 )
V_9 = V_4 & 0xffff ;
else
V_9 = ( V_4 >> V_22 ) & 0xffff ;
if ( ( V_3 == V_23 ) &&
( V_8 -> V_24 ) )
V_9 = ( V_25 << V_26 ) | V_27 ;
return V_9 ;
}
static T_3 F_5 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_3 V_9 ;
T_3 V_28 ;
int V_22 = ( V_3 & 0x3 ) * 8 ;
V_9 = ( V_4 >> V_22 ) & 0xff ;
if ( V_3 == V_29 ) {
V_28 = ( V_4 >> 5 ) & V_30 ;
V_9 &= ~ V_30 ;
V_9 |= V_28 ;
}
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_31 )
{
T_1 V_9 ;
if ( V_3 == V_32 )
V_9 = V_4 | V_33 ;
else
V_9 = V_4 ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
int V_3 , T_2 V_4 , T_1 V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_22 = ( V_3 & 0x2 ) * 8 ;
T_1 V_9 ;
switch ( V_3 ) {
case V_34 :
V_6 -> V_35 = V_4 ;
return V_31 ;
case V_36 :
V_9 = ( V_4 << 16 ) | V_6 -> V_35 ;
return V_9 ;
}
V_9 = V_31 & ( ~ ( 0xffff << V_22 ) ) ;
V_9 |= ( V_4 << V_22 ) ;
if ( V_3 == V_37 ) {
V_9 &= ( ~ F_8 ( 0x7 , 0 ) ) ;
}
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
int V_3 , T_3 V_4 , T_1 V_31 )
{
T_1 V_9 ;
T_1 V_28 ;
T_3 V_38 ;
int V_22 = ( V_3 & 0x3 ) * 8 ;
if ( V_3 == V_39 )
return V_31 ;
if ( V_3 == V_29 ) {
if ( V_2 -> V_40 & V_41 )
return V_31 ;
V_28 = ( V_4 & V_30 ) << 5 ;
V_9 = ( V_31 & ( ~ ( V_30 << 5 ) ) ) | V_28 ;
V_38 = ( V_4 & ( ~ V_30 ) ) |
( V_31 & V_30 ) ;
V_9 = ( V_9 & ( ~ 0xff ) ) | V_38 ;
V_9 &= ~ V_42 ;
return V_9 ;
}
V_9 = ( V_31 & ( ~ ( 0xff << V_22 ) ) ) | ( V_4 << V_22 ) ;
return V_9 ;
}
static T_1 F_10 ( struct V_1 * V_2 , int V_43 )
{
T_1 V_9 ;
T_1 V_4 ;
if ( V_43 == V_18 )
V_4 = F_11 ( V_2 -> V_44 + V_45 ) ;
else
V_4 = F_11 ( V_2 -> V_44 + V_43 ) ;
V_9 = F_1 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_43 )
{
T_1 V_9 ;
T_1 V_4 ;
if ( V_43 == V_18 )
V_4 = F_13 ( V_2 -> V_44 + V_45 ) ;
else
V_4 = F_13 ( V_2 -> V_44 + V_43 ) ;
V_9 = F_1 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static T_2 F_14 ( struct V_1 * V_2 , int V_43 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_46 = V_43 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_4 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static T_2 F_15 ( struct V_1 * V_2 , int V_43 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_46 = V_43 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_4 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_1 * V_2 , int V_43 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_46 = V_43 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_5 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static T_3 F_17 ( struct V_1 * V_2 , int V_43 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_46 = V_43 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_5 ( V_2 , V_43 , V_4 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_47 , int V_43 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_43 , V_47 , 0 ) ;
F_19 ( V_4 , V_2 -> V_44 + V_43 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_47 , int V_43 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_43 , V_47 , 0 ) ;
F_21 ( V_4 , V_2 -> V_44 + V_43 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_47 , int V_43 )
{
int V_46 = V_43 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_7 ( V_2 , V_43 , V_47 , V_4 ) ;
if ( V_43 != V_34 )
F_19 ( V_9 , V_2 -> V_44 + V_46 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_47 , int V_43 )
{
int V_46 = V_43 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_7 ( V_2 , V_43 , V_47 , V_4 ) ;
if ( V_43 != V_34 )
F_21 ( V_9 , V_2 -> V_44 + V_46 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_47 , int V_43 )
{
int V_46 = V_43 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_9 ( V_2 , V_43 , V_47 , V_4 ) ;
F_19 ( V_9 , V_2 -> V_44 + V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_47 , int V_43 )
{
int V_46 = V_43 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_44 + V_46 ) ;
V_9 = F_9 ( V_2 , V_43 , V_47 , V_4 ) ;
F_21 ( V_9 , V_2 -> V_44 + V_46 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_49 ;
T_4 V_50 ;
T_4 V_51 ;
V_49 = ( V_48 & V_52 ) &&
( V_48 & V_33 ) &&
( V_8 -> V_12 == V_25 ) ;
if ( ! V_49 )
return;
V_2 -> V_53 -> error = 0 ;
V_50 = F_27 ( V_2 -> V_53 -> V_54 ) ;
V_51 = V_50 + V_2 -> V_53 -> V_55 ;
V_51 = ( V_51 & ~ ( V_56 - 1 ) ) +
V_56 ;
V_2 -> V_53 -> V_55 = V_51 - V_50 ;
F_28 ( V_2 , V_51 , V_57 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_30 ( V_2 , V_58 ) ;
V_4 |= V_59 ;
F_28 ( V_2 , V_4 , V_58 ) ;
return 0 ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_60 )
return V_8 -> V_60 ;
else
return V_6 -> clock ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int clock ;
if ( V_8 -> V_60 )
clock = V_8 -> V_60 ;
else
clock = V_6 -> clock ;
return clock / 256 / 16 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_61 = 1 ;
int div = 1 ;
T_5 V_62 ;
T_1 V_63 ;
V_2 -> V_64 -> V_65 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_12 < V_25 )
V_61 = 2 ;
if ( clock > 167000000 &&
F_34 ( NULL , NULL , L_1 ) )
clock = 167000000 ;
if ( clock > 125000000 &&
F_34 ( NULL , NULL , L_2 ) )
clock = 125000000 ;
if ( F_34 ( NULL , NULL , L_3 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_63 = F_30 ( V_2 , V_66 ) ;
V_63 &= ~ ( V_67 | V_68 | V_69 |
V_70 | V_71 ) ;
F_28 ( V_2 , V_63 , V_66 ) ;
while ( V_2 -> V_72 / V_61 / 16 > clock && V_61 < 256 )
V_61 *= 2 ;
while ( V_2 -> V_72 / V_61 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_64 ) , L_4 ,
clock , V_2 -> V_72 / V_61 / div ) ;
V_2 -> V_64 -> V_65 = V_2 -> V_72 / V_61 / div ;
V_61 >>= 1 ;
div -- ;
V_63 = F_30 ( V_2 , V_66 ) ;
V_63 |= ( V_68 | V_69 | V_70
| ( div << V_73 )
| ( V_61 << V_74 ) ) ;
F_28 ( V_2 , V_63 , V_66 ) ;
V_62 = F_37 ( F_38 () , 20 ) ;
while ( ! ( F_30 ( V_2 , V_75 ) & V_76 ) ) {
if ( F_39 ( F_38 () , V_62 ) ) {
F_40 ( L_5 ,
F_41 ( V_2 -> V_64 ) ) ;
return;
}
F_42 ( 10 ) ;
}
V_63 |= V_67 ;
F_28 ( V_2 , V_63 , V_66 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_77 )
{
T_1 V_78 ;
V_78 = F_30 ( V_2 , V_79 ) ;
V_78 &= ( ~ V_80 ) ;
switch ( V_77 ) {
case V_81 :
V_78 |= V_82 ;
break;
case V_83 :
V_78 |= V_84 ;
break;
default:
break;
}
F_28 ( V_2 , V_78 , V_79 ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_85 )
{
T_1 V_47 ;
T_5 V_62 ;
V_47 = F_30 ( V_2 , V_66 ) ;
if ( V_85 )
V_47 |= V_67 ;
else
V_47 &= ~ V_67 ;
F_28 ( V_2 , V_47 , V_66 ) ;
V_62 = F_37 ( F_38 () , 20 ) ;
V_47 = V_76 ;
while ( ! ( F_30 ( V_2 , V_75 ) & V_47 ) ) {
if ( F_39 ( F_38 () , V_62 ) ) {
F_40 ( L_5 ,
F_41 ( V_2 -> V_64 ) ) ;
break;
}
F_42 ( 10 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , T_3 V_86 )
{
F_46 ( V_2 , V_86 ) ;
F_28 ( V_2 , V_2 -> V_87 , V_32 ) ;
F_28 ( V_2 , V_2 -> V_87 , V_88 ) ;
}
static int F_47 ( struct V_89 * V_64 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 = F_48 ( V_64 ) ;
struct V_92 * V_93 ;
void T_6 * V_94 = NULL ;
T_1 V_95 ;
T_1 V_47 ;
if ( V_2 -> V_96 < V_97 )
return 0 ;
V_47 = F_30 ( V_2 , V_79 ) ;
switch ( V_91 -> V_98 ) {
case V_99 :
V_47 &= ~ V_100 ;
F_28 ( V_2 , V_47 , V_79 ) ;
return 0 ;
case V_101 :
V_93 = F_49 ( NULL , V_102 ) ;
if ( V_93 )
V_94 = F_50 ( V_93 , 0 ) ;
if ( V_94 ) {
V_95 = V_103 |
V_104 ;
F_19 ( V_95 ,
V_94 + V_105 ) ;
V_47 |= V_100 ;
F_28 ( V_2 , V_47 , V_79 ) ;
F_51 ( 5 ) ;
V_95 = V_103 |
V_106 ;
F_19 ( V_95 ,
V_94 + V_105 ) ;
F_52 ( V_94 ) ;
} else {
V_47 |= V_100 ;
F_28 ( V_2 , V_47 , V_79 ) ;
}
return 0 ;
default:
return 0 ;
}
}
static int F_53 ( struct V_89 * V_64 , T_1 V_107 )
{
struct V_1 * V_2 = F_48 ( V_64 ) ;
T_1 V_47 ;
F_44 ( V_2 , false ) ;
V_47 = F_30 ( V_2 , V_58 ) ;
V_47 |= V_108 ;
F_28 ( V_2 , V_47 , V_58 ) ;
V_47 = F_30 ( V_2 , V_109 ) ;
V_47 |= V_110 ;
F_28 ( V_2 , V_47 , V_109 ) ;
F_44 ( V_2 , true ) ;
return F_54 ( V_64 , V_107 ) ;
}
static int F_55 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_56 ( V_112 ) ;
V_113 = F_30 ( V_2 , V_29 ) ;
if ( V_2 -> V_114 != V_115 )
F_57 ( V_2 -> V_64 ) ;
return F_58 ( V_2 ) ;
}
static int F_59 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_56 ( V_112 ) ;
int V_9 = F_60 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_113 , V_29 ) ;
}
return V_9 ;
}
static void F_61 ( struct V_116 * V_117 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_92 * V_118 ;
struct V_119 * V_119 ;
T_1 V_47 ;
T_2 V_120 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_120 = F_62 ( V_2 , V_23 ) ;
V_8 -> V_12 = ( V_120 & V_121 ) >>
V_26 ;
V_8 -> V_122 = V_120 & V_123 ;
if ( F_63 ( V_124 ) )
V_8 -> V_24 = true ;
else
V_8 -> V_24 = false ;
V_118 = V_117 -> V_112 . V_125 ;
V_119 = F_64 ( V_118 , 0 ) ;
if ( ! F_65 ( V_119 ) ) {
if ( F_66 ( V_118 , L_1 ) )
V_8 -> V_60 = F_67 ( V_119 ) / 2 ;
else
V_8 -> V_60 = F_67 ( V_119 ) ;
F_68 ( V_119 ) ;
}
if ( V_8 -> V_60 ) {
F_44 ( V_2 , false ) ;
V_47 = F_30 ( V_2 , V_58 ) ;
V_47 |= V_126 ;
F_28 ( V_2 , V_47 , V_58 ) ;
F_44 ( V_2 , true ) ;
}
}
static int F_69 ( struct V_116 * V_117 )
{
struct V_1 * V_2 ;
struct V_92 * V_118 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_118 = V_117 -> V_112 . V_125 ;
if ( F_70 ( V_118 , L_6 ) )
V_2 = F_71 ( V_117 , & V_127 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_71 ( V_117 , & V_128 ,
sizeof( struct V_7 ) ) ;
if ( F_65 ( V_2 ) )
return F_72 ( V_2 ) ;
V_2 -> V_129 . V_130 =
F_47 ;
V_2 -> V_129 . V_131 = F_53 ;
V_2 -> V_132 = 1 ;
F_61 ( V_117 , V_2 ) ;
F_73 ( V_117 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_40 |= V_133 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_134 &= ~ V_135 ;
if ( F_66 ( V_118 , L_7 ) ||
F_66 ( V_118 , L_8 ) ||
F_66 ( V_118 , L_9 ) ||
F_66 ( V_118 , L_10 ) ||
F_66 ( V_118 , L_11 ) )
V_2 -> V_134 &= ~ V_136 ;
if ( F_66 ( V_118 , L_12 ) )
V_2 -> V_134 |= V_137 ;
if ( F_66 ( V_118 , L_13 ) ) {
V_2 -> V_40 |= V_41 ;
}
V_9 = F_74 ( V_2 -> V_64 ) ;
if ( V_9 )
goto V_138;
F_75 ( V_118 , & V_2 -> V_139 ) ;
V_9 = F_76 ( V_2 ) ;
if ( V_9 )
goto V_138;
return 0 ;
V_138:
F_77 ( V_117 ) ;
return V_9 ;
}
