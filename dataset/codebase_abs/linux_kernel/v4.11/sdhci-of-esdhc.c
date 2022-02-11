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
T_1 V_57 ;
V_2 -> V_58 -> V_59 = 0 ;
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
V_57 = F_30 ( V_2 , V_60 ) ;
V_57 &= ~ ( V_61 | V_62 | V_63 |
V_64 | V_65 ) ;
F_28 ( V_2 , V_57 , V_60 ) ;
while ( V_2 -> V_66 / V_55 / 16 > clock && V_55 < 256 )
V_55 *= 2 ;
while ( V_2 -> V_66 / V_55 / div > clock && div < 16 )
div ++ ;
F_35 ( F_36 ( V_2 -> V_58 ) , L_2 ,
clock , V_2 -> V_66 / V_55 / div ) ;
V_2 -> V_58 -> V_59 = V_2 -> V_66 / V_55 / div ;
V_55 >>= 1 ;
div -- ;
V_57 = F_30 ( V_2 , V_60 ) ;
V_57 |= ( V_62 | V_63 | V_64
| ( div << V_67 )
| ( V_55 << V_68 ) ) ;
F_28 ( V_2 , V_57 , V_60 ) ;
V_56 = 20 ;
while ( ! ( F_30 ( V_2 , V_69 ) & V_70 ) ) {
if ( V_56 == 0 ) {
F_37 ( L_3 ,
F_38 ( V_2 -> V_58 ) ) ;
return;
}
V_56 -- ;
F_39 ( 1 ) ;
}
V_57 |= V_61 ;
F_28 ( V_2 , V_57 , V_60 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_71 )
{
T_1 V_72 ;
V_72 = F_30 ( V_2 , V_73 ) ;
V_72 &= ( ~ V_74 ) ;
switch ( V_71 ) {
case V_75 :
V_72 |= V_76 ;
break;
case V_77 :
V_72 |= V_78 ;
break;
default:
break;
}
F_28 ( V_2 , V_72 , V_73 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_3 V_79 )
{
F_42 ( V_2 , V_79 ) ;
F_28 ( V_2 , V_2 -> V_80 , V_28 ) ;
F_28 ( V_2 , V_2 -> V_80 , V_81 ) ;
}
static int F_43 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_44 ( V_83 ) ;
V_84 = F_30 ( V_2 , V_25 ) ;
return F_45 ( V_2 ) ;
}
static int F_46 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_44 ( V_83 ) ;
int V_9 = F_47 ( V_2 ) ;
if ( V_9 == 0 ) {
F_29 ( V_2 ) ;
F_28 ( V_2 , V_84 , V_25 ) ;
}
return V_9 ;
}
static void F_48 ( struct V_85 * V_86 , struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_2 V_87 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_87 = F_49 ( V_2 , V_19 ) ;
V_8 -> V_12 = ( V_87 & V_88 ) >>
V_22 ;
V_8 -> V_89 = V_87 & V_90 ;
if ( F_50 ( V_91 ) )
V_8 -> V_20 = true ;
else
V_8 -> V_20 = false ;
}
static int F_51 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
struct V_92 * V_93 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_93 = V_86 -> V_83 . V_94 ;
if ( F_52 ( V_93 , L_4 ) )
V_2 = F_53 ( V_86 , & V_95 ,
sizeof( struct V_7 ) ) ;
else
V_2 = F_53 ( V_86 , & V_96 ,
sizeof( struct V_7 ) ) ;
if ( F_54 ( V_2 ) )
return F_55 ( V_2 ) ;
F_48 ( V_86 , V_2 ) ;
F_56 ( V_86 ) ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
if ( V_8 -> V_12 == V_13 )
V_2 -> V_36 |= V_97 ;
if ( V_8 -> V_12 > V_13 )
V_2 -> V_98 &= ~ V_99 ;
if ( F_57 ( V_93 , L_5 ) ||
F_57 ( V_93 , L_6 ) ||
F_57 ( V_93 , L_7 ) ||
F_57 ( V_93 , L_8 ) ||
F_57 ( V_93 , L_9 ) )
V_2 -> V_98 &= ~ V_100 ;
if ( F_57 ( V_93 , L_10 ) )
V_2 -> V_98 |= V_101 ;
if ( F_57 ( V_93 , L_11 ) ) {
V_2 -> V_36 |= V_37 ;
}
V_9 = F_58 ( V_2 -> V_58 ) ;
if ( V_9 )
goto V_102;
F_59 ( V_93 , & V_2 -> V_103 ) ;
V_9 = F_60 ( V_2 ) ;
if ( V_9 )
goto V_102;
return 0 ;
V_102:
F_61 ( V_86 ) ;
return V_9 ;
}
