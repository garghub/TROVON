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
V_9 = V_4 ;
return V_9 ;
}
static T_2 F_4 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_2 V_9 ;
int V_15 = ( V_3 & 0x2 ) * 8 ;
if ( V_3 == V_16 )
V_9 = V_4 & 0xffff ;
else
V_9 = ( V_4 >> V_15 ) & 0xffff ;
return V_9 ;
}
static T_3 F_5 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
T_3 V_9 ;
T_3 V_17 ;
int V_15 = ( V_3 & 0x3 ) * 8 ;
V_9 = ( V_4 >> V_15 ) & 0xff ;
if ( V_3 == V_18 ) {
V_17 = ( V_4 >> 5 ) & V_19 ;
V_9 &= ~ V_19 ;
V_9 |= V_17 ;
}
return V_9 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 , T_1 V_20 )
{
T_1 V_9 ;
if ( V_3 == V_21 )
V_9 = V_4 | V_22 ;
else
V_9 = V_4 ;
return V_9 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
int V_3 , T_2 V_4 , T_1 V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 = ( V_3 & 0x2 ) * 8 ;
T_1 V_9 ;
switch ( V_3 ) {
case V_23 :
V_6 -> V_24 = V_4 ;
return V_20 ;
case V_25 :
V_9 = ( V_4 << 16 ) | V_6 -> V_24 ;
return V_9 ;
}
V_9 = V_20 & ( ~ ( 0xffff << V_15 ) ) ;
V_9 |= ( V_4 << V_15 ) ;
if ( V_3 == V_26 ) {
V_9 &= ( ~ F_8 ( 0x7 , 0 ) ) ;
}
return V_9 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
int V_3 , T_3 V_4 , T_1 V_20 )
{
T_1 V_9 ;
T_1 V_17 ;
T_3 V_27 ;
int V_15 = ( V_3 & 0x3 ) * 8 ;
if ( V_3 == V_28 )
return V_20 ;
if ( V_3 == V_18 ) {
if ( V_2 -> V_29 & V_30 )
return V_20 ;
V_17 = ( V_4 & V_19 ) << 5 ;
V_9 = ( V_20 & ( ~ ( V_19 << 5 ) ) ) | V_17 ;
V_27 = ( V_4 & ( ~ V_19 ) ) |
( V_20 & V_19 ) ;
V_9 = ( V_9 & ( ~ 0xff ) ) | V_27 ;
V_9 &= ~ V_31 ;
return V_9 ;
}
V_9 = ( V_20 & ( ~ ( 0xff << V_15 ) ) ) | ( V_4 << V_15 ) ;
return V_9 ;
}
static T_1 F_10 ( struct V_1 * V_2 , int V_32 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_11 ( V_2 -> V_33 + V_32 ) ;
V_9 = F_1 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static T_1 F_12 ( struct V_1 * V_2 , int V_32 )
{
T_1 V_9 ;
T_1 V_4 ;
V_4 = F_13 ( V_2 -> V_33 + V_32 ) ;
V_9 = F_1 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static T_2 F_14 ( struct V_1 * V_2 , int V_32 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_34 = V_32 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_4 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static T_2 F_15 ( struct V_1 * V_2 , int V_32 )
{
T_2 V_9 ;
T_1 V_4 ;
int V_34 = V_32 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_4 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static T_3 F_16 ( struct V_1 * V_2 , int V_32 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_34 = V_32 & ~ 0x3 ;
V_4 = F_11 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_5 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static T_3 F_17 ( struct V_1 * V_2 , int V_32 )
{
T_3 V_9 ;
T_1 V_4 ;
int V_34 = V_32 & ~ 0x3 ;
V_4 = F_13 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_5 ( V_2 , V_32 , V_4 ) ;
return V_9 ;
}
static void F_18 ( struct V_1 * V_2 , T_1 V_35 , int V_32 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_32 , V_35 , 0 ) ;
F_19 ( V_4 , V_2 -> V_33 + V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 , T_1 V_35 , int V_32 )
{
T_1 V_4 ;
V_4 = F_6 ( V_2 , V_32 , V_35 , 0 ) ;
F_21 ( V_4 , V_2 -> V_33 + V_32 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_35 , int V_32 )
{
int V_34 = V_32 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_7 ( V_2 , V_32 , V_35 , V_4 ) ;
if ( V_32 != V_23 )
F_19 ( V_9 , V_2 -> V_33 + V_34 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_35 , int V_32 )
{
int V_34 = V_32 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_7 ( V_2 , V_32 , V_35 , V_4 ) ;
if ( V_32 != V_23 )
F_21 ( V_9 , V_2 -> V_33 + V_34 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_3 V_35 , int V_32 )
{
int V_34 = V_32 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_11 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_9 ( V_2 , V_32 , V_35 , V_4 ) ;
F_19 ( V_9 , V_2 -> V_33 + V_34 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_35 , int V_32 )
{
int V_34 = V_32 & ~ 0x3 ;
T_1 V_4 ;
T_1 V_9 ;
V_4 = F_13 ( V_2 -> V_33 + V_34 ) ;
V_9 = F_9 ( V_2 , V_32 , V_35 , V_4 ) ;
F_21 ( V_9 , V_2 -> V_33 + V_34 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_36 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
bool V_37 ;
T_4 V_38 ;
T_4 V_39 ;
V_37 = ( V_36 & V_40 ) &&
( V_36 & V_22 ) &&
( V_8 -> V_12 == V_41 ) ;
if ( ! V_37 )
return;
V_2 -> V_42 -> error = 0 ;
V_38 = F_27 ( V_2 -> V_42 -> V_43 ) ;
V_39 = V_38 + V_2 -> V_42 -> V_44 ;
V_39 = ( V_39 & ~ ( V_45 - 1 ) ) +
V_45 ;
V_2 -> V_42 -> V_44 = V_39 - V_38 ;
F_28 ( V_2 , V_39 , V_46 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = F_30 ( V_2 , V_47 ) ;
V_4 |= V_48 ;
F_28 ( V_2 , V_4 , V_47 ) ;
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
int V_49 = 1 ;
int div = 1 ;
T_1 V_50 ;
V_2 -> V_51 -> V_52 = 0 ;
if ( clock == 0 )
return;
if ( V_8 -> V_12 < V_41 )
V_49 = 2 ;
if ( F_34 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
V_50 = F_30 ( V_2 , V_53 ) ;
V_50 &= ~ ( V_54 | V_55 | V_56
| V_57 ) ;
F_28 ( V_2 , V_50 , V_53 ) ;
while ( V_2 -> V_58 / V_49 / 16 > clock && V_49 < 256 )
V_49 *= 2 ;
while ( V_2 -> V_58 / V_49 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_51 ) , L_2 ,
clock , V_2 -> V_58 / V_49 / div ) ;
V_2 -> V_51 -> V_52 = V_2 -> V_58 / V_49 / div ;
V_49 >>= 1 ;
div -- ;
V_50 = F_30 ( V_2 , V_53 ) ;
V_50 |= ( V_54 | V_55 | V_56
| ( div << V_59 )
| ( V_49 << V_60 ) ) ;
F_28 ( V_2 , V_50 , V_53 ) ;
F_37 ( 1 ) ;
}
static void F_38 ( struct V_1 * V_2 , int V_61 )
{
T_1 V_62 ;
V_62 = F_30 ( V_2 , V_63 ) ;
V_62 &= ( ~ V_64 ) ;
switch ( V_61 ) {
case V_65 :
V_62 |= V_66 ;
break;
case V_67 :
V_62 |= V_68 ;
break;
default:
break;
}
F_28 ( V_2 , V_62 , V_63 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_69 )
{
F_40 ( V_2 , V_69 ) ;
F_28 ( V_2 , V_2 -> V_70 , V_21 ) ;
F_28 ( V_2 , V_2 -> V_70 , V_71 ) ;
}
static int F_41 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_42 ( V_73 ) ;
V_74 = F_30 ( V_2 , V_18 ) ;
return F_43 ( V_2 ) ;
}
static int F_44 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_42 ( V_73 ) ;
int V_9 = F_45 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_74 , V_18 ) ;
}
return V_9 ;
}
static void F_46 ( struct V_75 * V_76 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_77 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_77 = F_47 ( V_2 , V_16 ) ;
V_8 -> V_12 = ( V_77 & V_78 ) >>
V_79 ;
V_8 -> V_80 = V_77 & V_81 ;
}
static int F_48 ( struct V_75 * V_76 )
{
struct V_1 * V_2 ;
struct V_82 * V_83 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_83 = V_76 -> V_73 . V_84 ;
if ( F_49 ( V_83 , L_3 , NULL ) )
V_2 = F_50 ( V_76 , & V_85 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_50 ( V_76 , & V_86 ,
sizeof( struct V_7 ) ) ;
if ( F_51 ( V_2 ) )
return F_52 ( V_2 ) ;
F_46 ( V_76 , V_2 ) ;
F_53 ( V_76 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_29 |= V_87 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_88 &= ~ V_89 ;
if ( F_54 ( V_83 , L_4 ) ||
F_54 ( V_83 , L_5 ) ||
F_54 ( V_83 , L_6 ) ||
F_54 ( V_83 , L_7 ) ||
F_54 ( V_83 , L_8 ) ||
F_54 ( V_83 , L_9 ) )
V_2 -> V_88 &= ~ V_90 ;
if ( F_54 ( V_83 , L_9 ) )
V_2 -> V_88 |= V_91 ;
if ( F_54 ( V_83 , L_10 ) ) {
V_2 -> V_29 |= V_30 ;
}
V_9 = F_55 ( V_2 -> V_51 ) ;
if ( V_9 )
goto V_92;
F_56 ( V_83 , & V_2 -> V_93 ) ;
V_9 = F_57 ( V_2 ) ;
if ( V_9 )
goto V_92;
return 0 ;
V_92:
F_58 ( V_76 ) ;
return V_9 ;
}
