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
int V_55 = 1 ;
int div = 1 ;
T_1 V_56 ;
V_2 -> V_57 -> V_58 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_12 < V_21 )
V_55 = 2 ;
if ( F_34 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_56 = F_30 ( V_2 , V_59 ) ;
V_56 &= ~ ( V_60 | V_61 | V_62
| V_63 ) ;
F_28 ( V_2 , V_56 , V_59 ) ;
while ( V_2 -> V_64 / V_55 / 16 > clock && V_55 < 256 )
V_55 *= 2 ;
while ( V_2 -> V_64 / V_55 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_57 ) , L_2 ,
clock , V_2 -> V_64 / V_55 / div ) ;
V_2 -> V_57 -> V_58 = V_2 -> V_64 / V_55 / div ;
V_55 >>= 1 ;
div -- ;
V_56 = F_30 ( V_2 , V_59 ) ;
V_56 |= ( V_60 | V_61 | V_62
| ( div << V_65 )
| ( V_55 << V_66 ) ) ;
F_28 ( V_2 , V_56 , V_59 ) ;
F_37 ( 1 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_67 )
{
T_1 V_68 ;
V_68 = F_30 ( V_2 , V_69 ) ;
V_68 &= ( ~ V_70 ) ;
switch ( V_67 ) {
case V_71 :
V_68 |= V_72 ;
break;
case V_73 :
V_68 |= V_74 ;
break;
default:
break;
}
F_28 ( V_2 , V_68 , V_69 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_75 )
{
F_40 ( V_2 , V_75 ) ;
F_28 ( V_2 , V_2 -> V_76 , V_28 ) ;
F_28 ( V_2 , V_2 -> V_76 , V_77 ) ;
}
static int F_41 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_42 ( V_79 ) ;
V_80 = F_30 ( V_2 , V_25 ) ;
return F_43 ( V_2 ) ;
}
static int F_44 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_42 ( V_79 ) ;
int V_9 = F_45 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_80 , V_25 ) ;
}
return V_9 ;
}
static void F_46 ( struct V_81 * V_82 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_83 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_83 = F_47 ( V_2 , V_19 ) ;
V_8 -> V_12 = ( V_83 & V_84 ) >>
V_22 ;
V_8 -> V_85 = V_83 & V_86 ;
if ( F_48 ( V_87 ) )
V_8 -> V_20 = true ;
else
V_8 -> V_20 = false ;
}
static int F_49 ( struct V_81 * V_82 )
{
struct V_1 * V_2 ;
struct V_88 * V_89 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_89 = V_82 -> V_79 . V_90 ;
if ( F_50 ( V_89 , L_3 ) )
V_2 = F_51 ( V_82 , & V_91 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_51 ( V_82 , & V_92 ,
sizeof( struct V_7 ) ) ;
if ( F_52 ( V_2 ) )
return F_53 ( V_2 ) ;
F_46 ( V_82 , V_2 ) ;
F_54 ( V_82 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_36 |= V_93 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_94 &= ~ V_95 ;
if ( F_55 ( V_89 , L_4 ) ||
F_55 ( V_89 , L_5 ) ||
F_55 ( V_89 , L_6 ) ||
F_55 ( V_89 , L_7 ) ||
F_55 ( V_89 , L_8 ) ||
F_55 ( V_89 , L_9 ) )
V_2 -> V_94 &= ~ V_96 ;
if ( F_55 ( V_89 , L_9 ) )
V_2 -> V_94 |= V_97 ;
if ( F_55 ( V_89 , L_10 ) ) {
V_2 -> V_36 |= V_37 ;
}
V_9 = F_56 ( V_2 -> V_57 ) ;
if ( V_9 )
goto V_98;
F_57 ( V_89 , & V_2 -> V_99 ) ;
V_9 = F_58 ( V_2 ) ;
if ( V_9 )
goto V_98;
return 0 ;
V_98:
F_59 ( V_82 ) ;
return V_9 ;
}
