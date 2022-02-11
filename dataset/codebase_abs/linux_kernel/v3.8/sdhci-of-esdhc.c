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
V_18 = ( V_20 & V_19 ) << 5 ;
F_12 ( V_2 -> V_5 + V_3 , V_19 << 5 ,
V_18 ) ;
V_20 &= ~ V_19 ;
V_20 |= F_2 ( V_2 -> V_5 + V_3 ) & V_19 ;
}
if ( V_3 == V_17 )
V_20 &= ~ V_24 ;
F_13 ( V_2 , V_20 , V_3 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_25 )
{
T_1 V_8 ;
bool V_26 ;
T_4 V_27 ;
T_4 V_28 ;
V_8 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_8 = ( V_8 & V_10 ) >> V_11 ;
V_26 = ( V_25 & V_29 ) &&
( V_25 & V_22 ) &&
( V_8 == V_30 ) ;
if ( ! V_26 )
return;
V_2 -> V_31 -> error = 0 ;
V_27 = F_15 ( V_2 -> V_31 -> V_32 ) ;
V_28 = V_27 + V_2 -> V_31 -> V_33 ;
V_28 = ( V_28 & ~ ( V_34 - 1 ) ) +
V_34 ;
V_2 -> V_31 -> V_33 = V_28 - V_27 ;
F_16 ( V_2 , V_28 , V_35 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_5 + V_36 , V_37 ) ;
return 0 ;
}
static unsigned int F_19 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_20 ( V_2 ) ;
return V_39 -> clock ;
}
static unsigned int F_21 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_20 ( V_2 ) ;
return V_39 -> clock / 256 / 16 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned int clock )
{
if ( F_23 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
F_24 ( V_2 , clock ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
V_40 = F_26 ( V_2 , V_17 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_7 ( V_2 , V_40 , V_17 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_41 ;
V_41 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_41 = ( V_41 & V_10 ) >> V_11 ;
if ( V_41 == V_12 )
V_2 -> V_42 |= V_43 ;
if ( V_41 > V_12 )
V_2 -> V_44 &= ~ V_45 ;
}
static int F_29 ( struct V_46 * V_47 )
{
return F_30 ( V_47 , & V_48 ) ;
}
static int F_31 ( struct V_46 * V_47 )
{
return F_32 ( V_47 ) ;
}
