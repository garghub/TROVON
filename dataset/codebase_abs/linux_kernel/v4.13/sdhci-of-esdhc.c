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
V_9 = V_4 ;
return V_9 ;
}
static T_2 F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_2 V_9 ;
int V_18 = ( V_3 & 0x2 ) * 8 ;
if ( V_3 == V_19 )
V_9 = V_4 & 0xffff ;
else
V_9 = ( V_4 >> V_18 ) & 0xffff ;
if ( ( V_3 == V_19 ) &&
( V_8 -> V_20 ) )
V_9 = ( V_21 << V_22 ) | V_23 ;
return V_9 ;
}
static T_3 F_5 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_3 V_9 ;
T_3 V_24 ;
int V_18 = ( V_3 & 0x3 ) * 8 ;
V_9 = ( V_4 >> V_18 ) & 0xff ;
if ( V_3 == V_25 ) {
V_24 = ( V_4 >> 5 ) & V_26 ;
V_9 &= ~ V_26 ;
V_9 |= V_24 ;
}
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_27 )
{
T_1 V_9 ;
if ( V_3 == V_28 )
V_9 = V_4 | V_29 ;
else
V_9 = V_4 ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
int V_3 , T_2 V_4 , T_1 V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 = ( V_3 & 0x2 ) * 8 ;
T_1 V_9 ;
switch ( V_3 ) {
case V_30 :
V_6 -> V_31 = V_4 ;
return V_27 ;
case V_32 :
V_9 = ( V_4 << 16 ) | V_6 -> V_31 ;
return V_9 ;
}
V_9 = V_27 & ( ~ ( 0xffff << V_18 ) ) ;
V_9 |= ( V_4 << V_18 ) ;
if ( V_3 == V_33 ) {
V_9 &= ( ~ F_8 ( 0x7 , 0 ) ) ;
}
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
int V_3 , T_3 V_4 , T_1 V_27 )
{
T_1 V_9 ;
T_1 V_24 ;
T_3 V_34 ;
int V_18 = ( V_3 & 0x3 ) * 8 ;
if ( V_3 == V_35 )
return V_27 ;
if ( V_3 == V_25 ) {
if ( V_2 -> V_36 & V_37 )
return V_27 ;
V_24 = ( V_4 & V_26 ) << 5 ;
V_9 = ( V_27 & ( ~ ( V_26 << 5 ) ) ) | V_24 ;
V_34 = ( V_4 & ( ~ V_26 ) ) |
( V_27 & V_26 ) ;
V_9 = ( V_9 & ( ~ 0xff ) ) | V_34 ;
V_9 &= ~ V_38 ;
return V_9 ;
}
V_9 = ( V_27 & ( ~ ( 0xff << V_18 ) ) ) | ( V_4 << V_18 ) ;
return V_9 ;
}
static T_1 F_10 ( struct V_1 * V_2 , int V_39 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_11 ( V_2 -> V_40 + V_39 ) ;
V_9 = F_1 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_39 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_13 ( V_2 -> V_40 + V_39 ) ;
V_9 = F_1 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static T_2 F_14 ( struct V_1 * V_2 , int V_39 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_41 = V_39 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_4 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static T_2 F_15 ( struct V_1 * V_2 , int V_39 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_41 = V_39 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_4 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_1 * V_2 , int V_39 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_41 = V_39 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_5 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static T_3 F_17 ( struct V_1 * V_2 , int V_39 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_41 = V_39 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_5 ( V_2 , V_39 , V_4 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_42 , int V_39 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_39 , V_42 , 0 ) ;
F_19 ( V_4 , V_2 -> V_40 + V_39 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_42 , int V_39 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_39 , V_42 , 0 ) ;
F_21 ( V_4 , V_2 -> V_40 + V_39 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_42 , int V_39 )
{
int V_41 = V_39 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_7 ( V_2 , V_39 , V_42 , V_4 ) ;
if ( V_39 != V_30 )
F_19 ( V_9 , V_2 -> V_40 + V_41 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_42 , int V_39 )
{
int V_41 = V_39 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_7 ( V_2 , V_39 , V_42 , V_4 ) ;
if ( V_39 != V_30 )
F_21 ( V_9 , V_2 -> V_40 + V_41 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_42 , int V_39 )
{
int V_41 = V_39 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_9 ( V_2 , V_39 , V_42 , V_4 ) ;
F_19 ( V_9 , V_2 -> V_40 + V_41 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_42 , int V_39 )
{
int V_41 = V_39 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_40 + V_41 ) ;
V_9 = F_9 ( V_2 , V_39 , V_42 , V_4 ) ;
F_21 ( V_9 , V_2 -> V_40 + V_41 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_43 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_44 ;
T_4 V_45 ;
T_4 V_46 ;
V_44 = ( V_43 & V_47 ) &&
( V_43 & V_29 ) &&
( V_8 -> V_12 == V_21 ) ;
if ( ! V_44 )
return;
V_2 -> V_48 -> error = 0 ;
V_45 = F_27 ( V_2 -> V_48 -> V_49 ) ;
V_46 = V_45 + V_2 -> V_48 -> V_50 ;
V_46 = ( V_46 & ~ ( V_51 - 1 ) ) +
V_51 ;
V_2 -> V_48 -> V_50 = V_46 - V_45 ;
F_28 ( V_2 , V_46 , V_52 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_30 ( V_2 , V_53 ) ;
V_4 |= V_54 ;
F_28 ( V_2 , V_4 , V_53 ) ;
return 0 ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_55 )
return V_8 -> V_55 ;
else
return V_6 -> clock ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
unsigned int clock ;
if ( V_8 -> V_55 )
clock = V_8 -> V_55 ;
else
clock = V_6 -> clock ;
return clock / 256 / 16 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_56 = 1 ;
int div = 1 ;
T_5 V_57 ;
T_1 V_58 ;
V_2 -> V_59 -> V_60 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_12 < V_21 )
V_56 = 2 ;
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
V_58 = F_30 ( V_2 , V_61 ) ;
V_58 &= ~ ( V_62 | V_63 | V_64 |
V_65 | V_66 ) ;
F_28 ( V_2 , V_58 , V_61 ) ;
while ( V_2 -> V_67 / V_56 / 16 > clock && V_56 < 256 )
V_56 *= 2 ;
while ( V_2 -> V_67 / V_56 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_59 ) , L_4 ,
clock , V_2 -> V_67 / V_56 / div ) ;
V_2 -> V_59 -> V_60 = V_2 -> V_67 / V_56 / div ;
V_56 >>= 1 ;
div -- ;
V_58 = F_30 ( V_2 , V_61 ) ;
V_58 |= ( V_63 | V_64 | V_65
| ( div << V_68 )
| ( V_56 << V_69 ) ) ;
F_28 ( V_2 , V_58 , V_61 ) ;
V_57 = F_37 ( F_38 () , 20 ) ;
while ( ! ( F_30 ( V_2 , V_70 ) & V_71 ) ) {
if ( F_39 ( F_38 () , V_57 ) ) {
F_40 ( L_5 ,
F_41 ( V_2 -> V_59 ) ) ;
return;
}
F_42 ( 10 ) ;
}
V_58 |= V_62 ;
F_28 ( V_2 , V_58 , V_61 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_72 )
{
T_1 V_73 ;
V_73 = F_30 ( V_2 , V_74 ) ;
V_73 &= ( ~ V_75 ) ;
switch ( V_72 ) {
case V_76 :
V_73 |= V_77 ;
break;
case V_78 :
V_73 |= V_79 ;
break;
default:
break;
}
F_28 ( V_2 , V_73 , V_74 ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_80 )
{
T_1 V_42 ;
T_5 V_57 ;
V_42 = F_30 ( V_2 , V_61 ) ;
if ( V_80 )
V_42 |= V_62 ;
else
V_42 &= ~ V_62 ;
F_28 ( V_2 , V_42 , V_61 ) ;
V_57 = F_37 ( F_38 () , 20 ) ;
V_42 = V_71 ;
while ( ! ( F_30 ( V_2 , V_70 ) & V_42 ) ) {
if ( F_39 ( F_38 () , V_57 ) ) {
F_40 ( L_5 ,
F_41 ( V_2 -> V_59 ) ) ;
break;
}
F_42 ( 10 ) ;
}
}
static void F_45 ( struct V_1 * V_2 , T_3 V_81 )
{
F_46 ( V_2 , V_81 ) ;
F_28 ( V_2 , V_2 -> V_82 , V_28 ) ;
F_28 ( V_2 , V_2 -> V_82 , V_83 ) ;
}
static int F_47 ( struct V_84 * V_59 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_48 ( V_59 ) ;
struct V_87 * V_88 ;
void T_6 * V_89 = NULL ;
T_1 V_90 ;
T_1 V_42 ;
if ( V_2 -> V_91 < V_92 )
return 0 ;
V_42 = F_30 ( V_2 , V_74 ) ;
switch ( V_86 -> V_93 ) {
case V_94 :
V_42 &= ~ V_95 ;
F_28 ( V_2 , V_42 , V_74 ) ;
return 0 ;
case V_96 :
V_88 = F_49 ( NULL , V_97 ) ;
if ( V_88 )
V_89 = F_50 ( V_88 , 0 ) ;
if ( V_89 ) {
V_90 = V_98 |
V_99 ;
F_19 ( V_90 ,
V_89 + V_100 ) ;
V_42 |= V_95 ;
F_28 ( V_2 , V_42 , V_74 ) ;
F_51 ( 5 ) ;
V_90 = V_98 |
V_101 ;
F_19 ( V_90 ,
V_89 + V_100 ) ;
F_52 ( V_89 ) ;
} else {
V_42 |= V_95 ;
F_28 ( V_2 , V_42 , V_74 ) ;
}
return 0 ;
default:
return 0 ;
}
}
static int F_53 ( struct V_84 * V_59 , T_1 V_102 )
{
struct V_1 * V_2 = F_48 ( V_59 ) ;
T_1 V_42 ;
F_44 ( V_2 , false ) ;
V_42 = F_30 ( V_2 , V_53 ) ;
V_42 |= V_103 ;
F_28 ( V_2 , V_42 , V_53 ) ;
V_42 = F_30 ( V_2 , V_104 ) ;
V_42 |= V_105 ;
F_28 ( V_2 , V_42 , V_104 ) ;
F_44 ( V_2 , true ) ;
return F_54 ( V_59 , V_102 ) ;
}
static int F_55 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_56 ( V_107 ) ;
V_108 = F_30 ( V_2 , V_25 ) ;
if ( V_2 -> V_109 != V_110 )
F_57 ( V_2 -> V_59 ) ;
return F_58 ( V_2 ) ;
}
static int F_59 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = F_56 ( V_107 ) ;
int V_9 = F_60 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_108 , V_25 ) ;
}
return V_9 ;
}
static void F_61 ( struct V_111 * V_112 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_87 * V_113 ;
struct V_114 * V_114 ;
T_1 V_42 ;
T_2 V_115 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_115 = F_62 ( V_2 , V_19 ) ;
V_8 -> V_12 = ( V_115 & V_116 ) >>
V_22 ;
V_8 -> V_117 = V_115 & V_118 ;
if ( F_63 ( V_119 ) )
V_8 -> V_20 = true ;
else
V_8 -> V_20 = false ;
V_113 = V_112 -> V_107 . V_120 ;
V_114 = F_64 ( V_113 , 0 ) ;
if ( ! F_65 ( V_114 ) ) {
if ( F_66 ( V_113 , L_1 ) )
V_8 -> V_55 = F_67 ( V_114 ) / 2 ;
else
V_8 -> V_55 = F_67 ( V_114 ) ;
F_68 ( V_114 ) ;
}
if ( V_8 -> V_55 ) {
F_44 ( V_2 , false ) ;
V_42 = F_30 ( V_2 , V_53 ) ;
V_42 |= V_121 ;
F_28 ( V_2 , V_42 , V_53 ) ;
F_44 ( V_2 , true ) ;
}
}
static int F_69 ( struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_87 * V_113 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_113 = V_112 -> V_107 . V_120 ;
if ( F_70 ( V_113 , L_6 ) )
V_2 = F_71 ( V_112 , & V_122 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_71 ( V_112 , & V_123 ,
sizeof( struct V_7 ) ) ;
if ( F_65 ( V_2 ) )
return F_72 ( V_2 ) ;
V_2 -> V_124 . V_125 =
F_47 ;
V_2 -> V_124 . V_126 = F_53 ;
V_2 -> V_127 = 1 ;
F_61 ( V_112 , V_2 ) ;
F_73 ( V_112 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_36 |= V_128 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_129 &= ~ V_130 ;
if ( F_66 ( V_113 , L_7 ) ||
F_66 ( V_113 , L_8 ) ||
F_66 ( V_113 , L_9 ) ||
F_66 ( V_113 , L_10 ) ||
F_66 ( V_113 , L_11 ) )
V_2 -> V_129 &= ~ V_131 ;
if ( F_66 ( V_113 , L_12 ) )
V_2 -> V_129 |= V_132 ;
if ( F_66 ( V_113 , L_13 ) ) {
V_2 -> V_36 |= V_37 ;
}
V_9 = F_74 ( V_2 -> V_59 ) ;
if ( V_9 )
goto V_133;
F_75 ( V_113 , & V_2 -> V_134 ) ;
V_9 = F_76 ( V_2 ) ;
if ( V_9 )
goto V_133;
return 0 ;
V_133:
F_77 ( V_112 ) ;
return V_9 ;
}
