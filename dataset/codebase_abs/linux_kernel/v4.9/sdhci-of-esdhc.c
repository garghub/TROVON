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
T_2 V_9 ;
int V_18 = ( V_3 & 0x2 ) * 8 ;
if ( V_3 == V_19 )
V_9 = V_4 & 0xffff ;
else
V_9 = ( V_4 >> V_18 ) & 0xffff ;
return V_9 ;
}
static T_3 F_5 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_3 V_9 ;
T_3 V_20 ;
int V_18 = ( V_3 & 0x3 ) * 8 ;
V_9 = ( V_4 >> V_18 ) & 0xff ;
if ( V_3 == V_21 ) {
V_20 = ( V_4 >> 5 ) & V_22 ;
V_9 &= ~ V_22 ;
V_9 |= V_20 ;
}
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_23 )
{
T_1 V_9 ;
if ( V_3 == V_24 )
V_9 = V_4 | V_25 ;
else
V_9 = V_4 ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
int V_3 , T_2 V_4 , T_1 V_23 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 = ( V_3 & 0x2 ) * 8 ;
T_1 V_9 ;
switch ( V_3 ) {
case V_26 :
V_6 -> V_27 = V_4 ;
return V_23 ;
case V_28 :
V_9 = ( V_4 << 16 ) | V_6 -> V_27 ;
return V_9 ;
}
V_9 = V_23 & ( ~ ( 0xffff << V_18 ) ) ;
V_9 |= ( V_4 << V_18 ) ;
if ( V_3 == V_29 ) {
V_9 &= ( ~ F_8 ( 0x7 , 0 ) ) ;
}
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
int V_3 , T_3 V_4 , T_1 V_23 )
{
T_1 V_9 ;
T_1 V_20 ;
T_3 V_30 ;
int V_18 = ( V_3 & 0x3 ) * 8 ;
if ( V_3 == V_31 )
return V_23 ;
if ( V_3 == V_21 ) {
if ( V_2 -> V_32 & V_33 )
return V_23 ;
V_20 = ( V_4 & V_22 ) << 5 ;
V_9 = ( V_23 & ( ~ ( V_22 << 5 ) ) ) | V_20 ;
V_30 = ( V_4 & ( ~ V_22 ) ) |
( V_23 & V_22 ) ;
V_9 = ( V_9 & ( ~ 0xff ) ) | V_30 ;
V_9 &= ~ V_34 ;
return V_9 ;
}
V_9 = ( V_23 & ( ~ ( 0xff << V_18 ) ) ) | ( V_4 << V_18 ) ;
return V_9 ;
}
static T_1 F_10 ( struct V_1 * V_2 , int V_35 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_11 ( V_2 -> V_36 + V_35 ) ;
V_9 = F_1 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_35 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_13 ( V_2 -> V_36 + V_35 ) ;
V_9 = F_1 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static T_2 F_14 ( struct V_1 * V_2 , int V_35 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_37 = V_35 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_4 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static T_2 F_15 ( struct V_1 * V_2 , int V_35 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_37 = V_35 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_4 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_1 * V_2 , int V_35 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_37 = V_35 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_5 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static T_3 F_17 ( struct V_1 * V_2 , int V_35 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_37 = V_35 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_5 ( V_2 , V_35 , V_4 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_38 , int V_35 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_35 , V_38 , 0 ) ;
F_19 ( V_4 , V_2 -> V_36 + V_35 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_38 , int V_35 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_35 , V_38 , 0 ) ;
F_21 ( V_4 , V_2 -> V_36 + V_35 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_38 , int V_35 )
{
int V_37 = V_35 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_7 ( V_2 , V_35 , V_38 , V_4 ) ;
if ( V_35 != V_26 )
F_19 ( V_9 , V_2 -> V_36 + V_37 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_38 , int V_35 )
{
int V_37 = V_35 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_7 ( V_2 , V_35 , V_38 , V_4 ) ;
if ( V_35 != V_26 )
F_21 ( V_9 , V_2 -> V_36 + V_37 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_38 , int V_35 )
{
int V_37 = V_35 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_9 ( V_2 , V_35 , V_38 , V_4 ) ;
F_19 ( V_9 , V_2 -> V_36 + V_37 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_38 , int V_35 )
{
int V_37 = V_35 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_36 + V_37 ) ;
V_9 = F_9 ( V_2 , V_35 , V_38 , V_4 ) ;
F_21 ( V_9 , V_2 -> V_36 + V_37 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_40 ;
T_4 V_41 ;
T_4 V_42 ;
V_40 = ( V_39 & V_43 ) &&
( V_39 & V_25 ) &&
( V_8 -> V_12 == V_44 ) ;
if ( ! V_40 )
return;
V_2 -> V_45 -> error = 0 ;
V_41 = F_27 ( V_2 -> V_45 -> V_46 ) ;
V_42 = V_41 + V_2 -> V_45 -> V_47 ;
V_42 = ( V_42 & ~ ( V_48 - 1 ) ) +
V_48 ;
V_2 -> V_45 -> V_47 = V_42 - V_41 ;
F_28 ( V_2 , V_42 , V_49 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_30 ( V_2 , V_50 ) ;
V_4 |= V_51 ;
F_28 ( V_2 , V_4 , V_50 ) ;
return 0 ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> clock ;
}
static unsigned int F_32 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> clock / 256 / 16 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_52 = 1 ;
int div = 1 ;
T_1 V_53 ;
V_2 -> V_54 -> V_55 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_12 < V_44 )
V_52 = 2 ;
if ( F_34 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_53 = F_30 ( V_2 , V_56 ) ;
V_53 &= ~ ( V_57 | V_58 | V_59
| V_60 ) ;
F_28 ( V_2 , V_53 , V_56 ) ;
while ( V_2 -> V_61 / V_52 / 16 > clock && V_52 < 256 )
V_52 *= 2 ;
while ( V_2 -> V_61 / V_52 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_54 ) , L_2 ,
clock , V_2 -> V_61 / V_52 / div ) ;
V_2 -> V_54 -> V_55 = V_2 -> V_61 / V_52 / div ;
V_52 >>= 1 ;
div -- ;
V_53 = F_30 ( V_2 , V_56 ) ;
V_53 |= ( V_57 | V_58 | V_59
| ( div << V_62 )
| ( V_52 << V_63 ) ) ;
F_28 ( V_2 , V_53 , V_56 ) ;
F_37 ( 1 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_64 )
{
T_1 V_65 ;
V_65 = F_30 ( V_2 , V_66 ) ;
V_65 &= ( ~ V_67 ) ;
switch ( V_64 ) {
case V_68 :
V_65 |= V_69 ;
break;
case V_70 :
V_65 |= V_71 ;
break;
default:
break;
}
F_28 ( V_2 , V_65 , V_66 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_72 )
{
F_40 ( V_2 , V_72 ) ;
F_28 ( V_2 , V_2 -> V_73 , V_24 ) ;
F_28 ( V_2 , V_2 -> V_73 , V_74 ) ;
}
static int F_41 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_42 ( V_76 ) ;
V_77 = F_30 ( V_2 , V_21 ) ;
return F_43 ( V_2 ) ;
}
static int F_44 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_42 ( V_76 ) ;
int V_9 = F_45 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_77 , V_21 ) ;
}
return V_9 ;
}
static void F_46 ( struct V_78 * V_79 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_80 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_80 = F_47 ( V_2 , V_19 ) ;
V_8 -> V_12 = ( V_80 & V_81 ) >>
V_82 ;
V_8 -> V_83 = V_80 & V_84 ;
}
static int F_48 ( struct V_78 * V_79 )
{
struct V_1 * V_2 ;
struct V_85 * V_86 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_86 = V_79 -> V_76 . V_87 ;
if ( F_49 ( V_86 , L_3 ) )
V_2 = F_50 ( V_79 , & V_88 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_50 ( V_79 , & V_89 ,
sizeof( struct V_7 ) ) ;
if ( F_51 ( V_2 ) )
return F_52 ( V_2 ) ;
F_46 ( V_79 , V_2 ) ;
F_53 ( V_79 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_32 |= V_90 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_91 &= ~ V_92 ;
if ( F_54 ( V_86 , L_4 ) ||
F_54 ( V_86 , L_5 ) ||
F_54 ( V_86 , L_6 ) ||
F_54 ( V_86 , L_7 ) ||
F_54 ( V_86 , L_8 ) ||
F_54 ( V_86 , L_9 ) )
V_2 -> V_91 &= ~ V_93 ;
if ( F_54 ( V_86 , L_9 ) )
V_2 -> V_91 |= V_94 ;
if ( F_54 ( V_86 , L_10 ) ) {
V_2 -> V_32 |= V_33 ;
}
V_9 = F_55 ( V_2 -> V_54 ) ;
if ( V_9 )
goto V_95;
F_56 ( V_86 , & V_2 -> V_96 ) ;
V_9 = F_57 ( V_2 ) ;
if ( V_9 )
goto V_95;
return 0 ;
V_95:
F_58 ( V_79 ) ;
return V_9 ;
}
