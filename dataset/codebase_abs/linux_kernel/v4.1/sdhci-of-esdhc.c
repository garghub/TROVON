static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
if ( ( V_3 == V_6 ) && ( V_4 & V_7 ) ) {
T_1 V_8 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_8 = ( V_8 & V_10 ) >> V_11 ;
if ( V_8 > V_12 )
V_4 |= V_13 ;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
int V_14 = V_3 & ~ 0x3 ;
int V_15 = ( V_3 & 0x2 ) * 8 ;
if ( F_4 ( V_3 == V_16 ) )
V_4 = F_2 ( V_2 -> V_5 + V_14 ) & 0xffff ;
else
V_4 = ( F_2 ( V_2 -> V_5 + V_14 ) >> V_15 ) & 0xffff ;
return V_4 ;
}
static T_3 F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_14 = V_3 & ~ 0x3 ;
int V_15 = ( V_3 & 0x3 ) * 8 ;
T_3 V_4 = ( F_2 ( V_2 -> V_5 + V_14 ) >> V_15 ) & 0xff ;
if ( V_3 == V_17 ) {
T_1 V_18 ;
V_18 = F_2 ( V_2 -> V_5 + V_3 ) ;
V_18 = ( V_18 >> 5 ) & V_19 ;
V_4 &= ~ V_19 ;
V_4 |= V_18 ;
}
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_20 , int V_3 )
{
if ( V_3 == V_21 )
V_20 |= V_22 ;
F_7 ( V_2 , V_20 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_20 , int V_3 )
{
if ( V_3 == V_23 ) {
V_20 &= ~ F_9 ( 0x7 , 0 ) ;
}
F_10 ( V_2 , V_20 , V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_20 , int V_3 )
{
if ( V_3 == V_17 ) {
T_1 V_18 ;
if ( V_2 -> V_24 & V_25 )
return;
V_18 = ( V_20 & V_19 ) << 5 ;
F_12 ( V_2 -> V_5 + V_3 , V_19 << 5 ,
V_18 ) ;
V_20 &= ~ V_19 ;
V_20 |= F_2 ( V_2 -> V_5 + V_3 ) & V_19 ;
}
if ( V_3 == V_17 )
V_20 &= ~ V_26 ;
F_13 ( V_2 , V_20 , V_3 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_8 ;
bool V_28 ;
T_4 V_29 ;
T_4 V_30 ;
V_8 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_8 = ( V_8 & V_10 ) >> V_11 ;
V_28 = ( V_27 & V_31 ) &&
( V_27 & V_22 ) &&
( V_8 == V_32 ) ;
if ( ! V_28 )
return;
V_2 -> V_33 -> error = 0 ;
V_29 = F_15 ( V_2 -> V_33 -> V_34 ) ;
V_30 = V_29 + V_2 -> V_33 -> V_35 ;
V_30 = ( V_30 & ~ ( V_36 - 1 ) ) +
V_36 ;
V_2 -> V_33 -> V_35 = V_30 - V_29 ;
F_16 ( V_2 , V_30 , V_37 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_5 + V_38 , V_39 ) ;
return 0 ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
return V_41 -> clock ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
return V_41 -> clock / 256 / 16 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int clock )
{
int V_42 = 2 ;
int div = 1 ;
T_1 V_43 ;
V_2 -> V_44 -> V_45 = 0 ;
if ( clock == 0 )
return;
if ( F_23 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_43 = F_24 ( V_2 , V_46 ) ;
V_43 &= ~ ( V_47 | V_48 | V_49
| V_50 ) ;
F_16 ( V_2 , V_43 , V_46 ) ;
while ( V_2 -> V_51 / V_42 / 16 > clock && V_42 < 256 )
V_42 *= 2 ;
while ( V_2 -> V_51 / V_42 / div > clock && div < 16 )
div ++ ;
F_25 ( F_26 ( V_2 -> V_44 ) , L_2 ,
clock , V_2 -> V_51 / V_42 / div ) ;
V_42 >>= 1 ;
div -- ;
V_43 = F_24 ( V_2 , V_46 ) ;
V_43 |= ( V_47 | V_48 | V_49
| ( div << V_52 )
| ( V_42 << V_53 ) ) ;
F_16 ( V_2 , V_43 , V_46 ) ;
F_27 ( 1 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_54 ;
V_54 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_54 = ( V_54 & V_10 ) >> V_11 ;
if ( V_54 == V_12 )
V_2 -> V_24 |= V_55 ;
if ( V_54 > V_12 )
V_2 -> V_56 &= ~ V_57 ;
}
static void F_29 ( struct V_1 * V_2 , int V_58 )
{
T_1 V_59 ;
switch ( V_58 ) {
case V_60 :
V_59 = V_61 ;
break;
case V_62 :
V_59 = V_63 ;
break;
default:
V_59 = 0 ;
break;
}
F_12 ( V_2 -> V_5 + V_17 ,
V_64 , V_59 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_3 V_65 )
{
F_31 ( V_2 , V_65 ) ;
F_16 ( V_2 , V_2 -> V_66 , V_21 ) ;
F_16 ( V_2 , V_2 -> V_66 , V_67 ) ;
}
static int F_32 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_33 ( V_69 ) ;
V_70 = F_34 ( V_2 , V_17 ) ;
return F_35 ( V_2 ) ;
}
static int F_36 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = F_33 ( V_69 ) ;
int V_4 = F_37 ( V_2 ) ;
if ( V_4 == 0 ) {
F_17 ( V_2 ) ;
F_7 ( V_2 , V_70 , V_17 ) ;
}
return V_4 ;
}
static int F_38 ( struct V_71 * V_72 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
int V_4 ;
V_2 = F_39 ( V_72 , & V_75 , 0 ) ;
if ( F_40 ( V_2 ) )
return F_41 ( V_2 ) ;
F_42 ( V_72 ) ;
V_74 = V_72 -> V_69 . V_76 ;
if ( F_43 ( V_74 , L_3 ) ) {
V_2 -> V_24 |= V_25 ;
}
V_4 = F_44 ( V_2 -> V_44 ) ;
if ( V_4 )
goto V_77;
F_45 ( V_74 , & V_2 -> V_78 ) ;
V_4 = F_46 ( V_2 ) ;
if ( V_4 )
goto V_77;
return 0 ;
V_77:
F_47 ( V_72 ) ;
return V_4 ;
}
