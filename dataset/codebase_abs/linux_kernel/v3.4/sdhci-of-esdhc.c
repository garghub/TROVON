static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
int V_5 = V_3 & ~ 0x3 ;
int V_6 = ( V_3 & 0x2 ) * 8 ;
if ( F_2 ( V_3 == V_7 ) )
V_4 = F_3 ( V_2 -> V_8 + V_5 ) & 0xffff ;
else
V_4 = ( F_3 ( V_2 -> V_8 + V_5 ) >> V_6 ) & 0xffff ;
return V_4 ;
}
static T_2 F_4 ( struct V_1 * V_2 , int V_3 )
{
int V_5 = V_3 & ~ 0x3 ;
int V_6 = ( V_3 & 0x3 ) * 8 ;
T_2 V_4 = ( F_3 ( V_2 -> V_8 + V_5 ) >> V_6 ) & 0xff ;
if ( V_3 == V_9 ) {
T_3 V_10 ;
V_10 = F_3 ( V_2 -> V_8 + V_3 ) ;
V_10 = ( V_10 >> 5 ) & V_11 ;
V_4 &= ~ V_11 ;
V_4 |= V_10 ;
}
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_12 , int V_3 )
{
if ( V_3 == V_13 ) {
V_12 &= ~ F_6 ( 0x7 , 0 ) ;
}
F_7 ( V_2 , V_12 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_12 , int V_3 )
{
if ( V_3 == V_9 ) {
T_3 V_10 ;
V_10 = ( V_12 & V_11 ) << 5 ;
F_9 ( V_2 -> V_8 + V_3 , V_11 << 5 ,
V_10 ) ;
V_12 &= ~ V_11 ;
V_12 |= F_3 ( V_2 -> V_8 + V_3 ) & V_11 ;
}
if ( V_3 == V_9 )
V_12 &= ~ V_14 ;
F_10 ( V_2 , V_12 , V_3 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_8 + V_15 , V_16 ) ;
return 0 ;
}
static unsigned int F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_14 ( V_2 ) ;
return V_18 -> clock ;
}
static unsigned int F_15 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_14 ( V_2 ) ;
return V_18 -> clock / 256 / 16 ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int clock )
{
if ( F_17 ( NULL , NULL , L_1 ) ) {
if ( clock > 20000000 )
clock -= 5000000 ;
if ( clock > 40000000 )
clock -= 5000000 ;
}
F_18 ( V_2 , clock ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
V_19 = F_20 ( V_2 , V_9 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_22 ( V_2 , V_19 , V_9 ) ;
}
static int T_4 F_23 ( struct V_20 * V_21 )
{
return F_24 ( V_21 , & V_22 ) ;
}
static int T_5 F_25 ( struct V_20 * V_21 )
{
return F_26 ( V_21 ) ;
}
