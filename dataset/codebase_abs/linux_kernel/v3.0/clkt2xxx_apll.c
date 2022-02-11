static int F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_3 , V_4 ;
V_4 = V_5 << V_1 -> V_6 ;
V_3 = F_2 ( V_7 , V_8 ) ;
if ( ( V_3 & V_4 ) == V_4 )
return 0 ;
V_3 &= ~ V_4 ;
V_3 |= V_4 ;
F_3 ( V_3 , V_7 , V_8 ) ;
F_4 ( V_9 , V_2 ,
V_10 , V_1 -> V_11 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_12 ) ;
}
static int F_6 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
F_8 () ;
}
static void F_9 ( struct V_1 * V_1 )
{
F_10 () ;
}
static void F_11 ( struct V_1 * V_1 )
{
F_12 () ;
}
static void F_13 ( struct V_1 * V_1 )
{
F_14 () ;
}
static void F_15 ( struct V_1 * V_1 )
{
T_1 V_3 ;
V_3 = F_2 ( V_7 , V_8 ) ;
V_3 &= ~ ( V_5 << V_1 -> V_6 ) ;
F_3 ( V_3 , V_7 , V_8 ) ;
}
T_1 F_16 ( void )
{
T_1 V_14 , V_15 = 0 ;
V_14 = F_2 ( V_7 , V_16 ) ;
V_14 &= V_17 ;
V_14 >>= V_18 ;
if ( V_14 == V_19 )
V_15 = 19200000 ;
else if ( V_14 == V_20 )
V_15 = 13000000 ;
else if ( V_14 == V_21 )
V_15 = 12000000 ;
return V_15 ;
}
