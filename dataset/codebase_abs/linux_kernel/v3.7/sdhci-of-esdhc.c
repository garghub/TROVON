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
static void F_6 ( struct V_1 * V_2 , T_2 V_20 , int V_3 )
{
if ( V_3 == V_21 ) {
V_20 &= ~ F_7 ( 0x7 , 0 ) ;
}
F_8 ( V_2 , V_20 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_3 V_20 , int V_3 )
{
if ( V_3 == V_17 ) {
T_1 V_18 ;
V_18 = ( V_20 & V_19 ) << 5 ;
F_10 ( V_2 -> V_5 + V_3 , V_19 << 5 ,
V_18 ) ;
V_20 &= ~ V_19 ;
V_20 |= F_2 ( V_2 -> V_5 + V_3 ) & V_19 ;
}
if ( V_3 == V_17 )
V_20 &= ~ V_22 ;
F_11 ( V_2 , V_20 , V_3 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_5 + V_23 , V_24 ) ;
return 0 ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_15 ( V_2 ) ;
return V_26 -> clock ;
}
static unsigned int F_16 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_15 ( V_2 ) ;
return V_26 -> clock / 256 / 16 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int clock )
{
if ( F_18 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
F_19 ( V_2 , clock ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_27 = F_21 ( V_2 , V_17 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_23 ( V_2 , V_27 , V_17 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_28 ;
V_28 = F_2 ( V_2 -> V_5 + V_9 ) ;
V_28 = ( V_28 & V_10 ) >> V_11 ;
if ( V_28 == V_12 )
V_2 -> V_29 |= V_30 ;
}
static int T_4 F_25 ( struct V_31 * V_32 )
{
return F_26 ( V_32 , & V_33 ) ;
}
static int T_5 F_27 ( struct V_31 * V_32 )
{
return F_28 ( V_32 ) ;
}
