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
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , int V_3 )
{
if ( V_3 == V_10 ) {
V_9 &= ~ F_6 ( 0x7 , 0 ) ;
}
F_7 ( V_2 , V_9 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_9 , int V_3 )
{
if ( V_3 == V_11 )
V_9 &= ~ V_12 ;
F_9 ( V_2 , V_9 , V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_8 + V_13 , V_14 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_13 ( V_2 ) ;
return V_16 -> clock ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_13 ( V_2 ) ;
return V_16 -> clock / 256 / 16 ;
}
static int T_3 F_15 ( struct V_17 * V_18 )
{
return F_16 ( V_18 , & V_19 ) ;
}
static int T_4 F_17 ( struct V_17 * V_18 )
{
return F_18 ( V_18 ) ;
}
static int T_5 F_19 ( void )
{
return F_20 ( & V_20 ) ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_20 ) ;
}
