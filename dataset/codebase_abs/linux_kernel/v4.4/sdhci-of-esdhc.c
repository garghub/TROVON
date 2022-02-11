static T_1 F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_1 V_10 ;
if ( ( V_3 == V_11 ) && ( V_4 & V_12 ) ) {
if ( V_8 -> V_13 > V_14 ) {
V_10 = V_4 | V_15 ;
return V_10 ;
}
}
V_10 = V_4 ;
return V_10 ;
}
static T_2 F_3 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_2 V_10 ;
int V_16 = ( V_3 & 0x2 ) * 8 ;
if ( V_3 == V_17 )
V_10 = V_4 & 0xffff ;
else
V_10 = ( V_4 >> V_16 ) & 0xffff ;
return V_10 ;
}
static T_3 F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_3 V_10 ;
T_3 V_18 ;
int V_16 = ( V_3 & 0x3 ) * 8 ;
V_10 = ( V_4 >> V_16 ) & 0xff ;
if ( V_3 == V_19 ) {
V_18 = ( V_4 >> 5 ) & V_20 ;
V_10 &= ~ V_20 ;
V_10 |= V_18 ;
}
return V_10 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_21 )
{
T_1 V_10 ;
if ( V_3 == V_22 )
V_10 = V_4 | V_23 ;
else
V_10 = V_4 ;
return V_10 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
int V_3 , T_2 V_4 , T_1 V_21 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_16 = ( V_3 & 0x2 ) * 8 ;
T_1 V_10 ;
switch ( V_3 ) {
case V_24 :
V_6 -> V_25 = V_4 ;
return V_21 ;
case V_26 :
V_10 = ( V_4 << 16 ) | V_6 -> V_25 ;
return V_10 ;
}
V_10 = V_21 & ( ~ ( 0xffff << V_16 ) ) ;
V_10 |= ( V_4 << V_16 ) ;
if ( V_3 == V_27 ) {
V_10 &= ( ~ F_7 ( 0x7 , 0 ) ) ;
}
return V_10 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
int V_3 , T_3 V_4 , T_1 V_21 )
{
T_1 V_10 ;
T_1 V_18 ;
T_3 V_28 ;
int V_16 = ( V_3 & 0x3 ) * 8 ;
if ( V_3 == V_29 )
return V_21 ;
if ( V_3 == V_19 ) {
if ( V_2 -> V_30 & V_31 )
return V_21 ;
V_18 = ( V_4 & V_20 ) << 5 ;
V_10 = ( V_21 & ( ~ ( V_20 << 5 ) ) ) | V_18 ;
V_28 = ( V_4 & ( ~ V_20 ) ) |
( V_21 & V_20 ) ;
V_10 = ( V_10 & ( ~ 0xff ) ) | V_28 ;
V_10 &= ~ V_32 ;
return V_10 ;
}
V_10 = ( V_21 & ( ~ ( 0xff << V_16 ) ) ) | ( V_4 << V_16 ) ;
return V_10 ;
}
static T_1 F_9 ( struct V_1 * V_2 , int V_33 )
{
T_1 V_10 ;
T_1 V_4 ;
V_4 = F_10 ( V_2 -> V_34 + V_33 ) ;
V_10 = F_1 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static T_1 F_11 ( struct V_1 * V_2 , int V_33 )
{
T_1 V_10 ;
T_1 V_4 ;
V_4 = F_12 ( V_2 -> V_34 + V_33 ) ;
V_10 = F_1 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static T_2 F_13 ( struct V_1 * V_2 , int V_33 )
{
T_2 V_10 ;
T_1 V_4 ;
int V_35 = V_33 & ~ 0x3 ;
V_4 = F_10 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_3 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static T_2 F_14 ( struct V_1 * V_2 , int V_33 )
{
T_2 V_10 ;
T_1 V_4 ;
int V_35 = V_33 & ~ 0x3 ;
V_4 = F_12 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_3 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static T_3 F_15 ( struct V_1 * V_2 , int V_33 )
{
T_3 V_10 ;
T_1 V_4 ;
int V_35 = V_33 & ~ 0x3 ;
V_4 = F_10 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_4 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static T_3 F_16 ( struct V_1 * V_2 , int V_33 )
{
T_3 V_10 ;
T_1 V_4 ;
int V_35 = V_33 & ~ 0x3 ;
V_4 = F_12 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_4 ( V_2 , V_33 , V_4 ) ;
return V_10 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_36 , int V_33 )
{
T_1 V_4 ;
V_4 = F_5 ( V_2 , V_33 , V_36 , 0 ) ;
F_18 ( V_4 , V_2 -> V_34 + V_33 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_36 , int V_33 )
{
T_1 V_4 ;
V_4 = F_5 ( V_2 , V_33 , V_36 , 0 ) ;
F_20 ( V_4 , V_2 -> V_34 + V_33 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_2 V_36 , int V_33 )
{
int V_35 = V_33 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_10 ;
V_4 = F_10 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_6 ( V_2 , V_33 , V_36 , V_4 ) ;
if ( V_33 != V_24 )
F_18 ( V_10 , V_2 -> V_34 + V_35 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_36 , int V_33 )
{
int V_35 = V_33 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_10 ;
V_4 = F_12 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_6 ( V_2 , V_33 , V_36 , V_4 ) ;
if ( V_33 != V_24 )
F_20 ( V_10 , V_2 -> V_34 + V_35 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_3 V_36 , int V_33 )
{
int V_35 = V_33 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_10 ;
V_4 = F_10 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_8 ( V_2 , V_33 , V_36 , V_4 ) ;
F_18 ( V_10 , V_2 -> V_34 + V_35 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_36 , int V_33 )
{
int V_35 = V_33 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_10 ;
V_4 = F_12 ( V_2 -> V_34 + V_35 ) ;
V_10 = F_8 ( V_2 , V_33 , V_36 , V_4 ) ;
F_20 ( V_10 , V_2 -> V_34 + V_35 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_37 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
bool V_38 ;
T_4 V_39 ;
T_4 V_40 ;
V_38 = ( V_37 & V_41 ) &&
( V_37 & V_23 ) &&
( V_8 -> V_13 == V_42 ) ;
if ( ! V_38 )
return;
V_2 -> V_43 -> error = 0 ;
V_39 = F_26 ( V_2 -> V_43 -> V_44 ) ;
V_40 = V_39 + V_2 -> V_43 -> V_45 ;
V_40 = ( V_40 & ~ ( V_46 - 1 ) ) +
V_46 ;
V_2 -> V_43 -> V_45 = V_40 - V_39 ;
F_27 ( V_2 , V_40 , V_47 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_29 ( V_2 , V_48 ) ;
V_4 |= V_49 ;
F_27 ( V_2 , V_4 , V_48 ) ;
return 0 ;
}
static unsigned int F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> clock ;
}
static unsigned int F_31 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> clock / 256 / 16 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_50 = 1 ;
int div = 1 ;
T_1 V_51 ;
V_2 -> V_52 -> V_53 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_13 < V_42 )
V_50 = 2 ;
if ( F_33 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_51 = F_29 ( V_2 , V_54 ) ;
V_51 &= ~ ( V_55 | V_56 | V_57
| V_58 ) ;
F_27 ( V_2 , V_51 , V_54 ) ;
while ( V_2 -> V_59 / V_50 / 16 > clock && V_50 < 256 )
V_50 *= 2 ;
while ( V_2 -> V_59 / V_50 / div > clock && div < 16 )
div ++ ;
F_34 ( F_35 ( V_2 -> V_52 ) , L_2 ,
clock , V_2 -> V_59 / V_50 / div ) ;
V_2 -> V_52 -> V_53 = V_2 -> V_59 / V_50 / div ;
V_50 >>= 1 ;
div -- ;
V_51 = F_29 ( V_2 , V_54 ) ;
V_51 |= ( V_55 | V_56 | V_57
| ( div << V_60 )
| ( V_50 << V_61 ) ) ;
F_27 ( V_2 , V_51 , V_54 ) ;
F_36 ( 1 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_62 )
{
T_1 V_63 ;
V_63 = F_29 ( V_2 , V_64 ) ;
V_63 &= ( ~ V_65 ) ;
switch ( V_62 ) {
case V_66 :
V_63 |= V_67 ;
break;
case V_68 :
V_63 |= V_69 ;
break;
default:
break;
}
F_27 ( V_2 , V_63 , V_64 ) ;
}
static void F_38 ( struct V_1 * V_2 , T_3 V_70 )
{
F_39 ( V_2 , V_70 ) ;
F_27 ( V_2 , V_2 -> V_71 , V_22 ) ;
F_27 ( V_2 , V_2 -> V_71 , V_72 ) ;
}
static int F_40 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_41 ( V_74 ) ;
V_75 = F_29 ( V_2 , V_19 ) ;
return F_42 ( V_2 ) ;
}
static int F_43 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_41 ( V_74 ) ;
int V_10 = F_44 ( V_2 ) ;
if ( V_10 == 0 ) {
F_28 ( V_2 ) ;
F_27 ( V_2 , V_75 , V_19 ) ;
}
return V_10 ;
}
static void F_45 ( struct V_76 * V_77 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_78 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_46 ( & V_77 -> V_74 , sizeof( struct V_7 ) ,
V_79 ) ;
V_78 = F_47 ( V_2 , V_17 ) ;
V_8 -> V_13 = ( V_78 & V_80 ) >>
V_81 ;
V_8 -> V_82 = V_78 & V_83 ;
V_6 -> V_9 = V_8 ;
}
static int F_48 ( struct V_76 * V_77 )
{
struct V_1 * V_2 ;
struct V_84 * V_85 ;
int V_10 ;
V_85 = V_77 -> V_74 . V_86 ;
if ( F_49 ( V_85 , L_3 , NULL ) )
V_2 = F_50 ( V_77 , & V_87 , 0 ) ;
else
V_2 = F_50 ( V_77 , & V_88 , 0 ) ;
if ( F_51 ( V_2 ) )
return F_52 ( V_2 ) ;
F_45 ( V_77 , V_2 ) ;
F_53 ( V_77 ) ;
if ( F_54 ( V_85 , L_4 ) ||
F_54 ( V_85 , L_5 ) ||
F_54 ( V_85 , L_6 ) ||
F_54 ( V_85 , L_7 ) ||
F_54 ( V_85 , L_8 ) ||
F_54 ( V_85 , L_9 ) )
V_2 -> V_89 &= ~ V_90 ;
if ( F_54 ( V_85 , L_9 ) )
V_2 -> V_89 |= V_91 ;
if ( F_54 ( V_85 , L_10 ) ) {
V_2 -> V_30 |= V_31 ;
}
V_10 = F_55 ( V_2 -> V_52 ) ;
if ( V_10 )
goto V_92;
F_56 ( V_85 , & V_2 -> V_93 ) ;
V_10 = F_57 ( V_2 ) ;
if ( V_10 )
goto V_92;
return 0 ;
V_92:
F_58 ( V_77 ) ;
return V_10 ;
}
