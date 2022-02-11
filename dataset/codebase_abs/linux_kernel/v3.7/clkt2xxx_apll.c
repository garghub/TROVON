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
V_10 , F_5 ( V_1 ) ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_11 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
return F_1 ( V_1 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_1 )
{
F_9 () ;
}
static void F_10 ( struct V_1 * V_1 )
{
F_11 () ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_13 () ;
}
static void F_14 ( struct V_1 * V_1 )
{
F_15 () ;
}
static void F_16 ( struct V_1 * V_1 )
{
T_1 V_3 ;
V_3 = F_2 ( V_7 , V_8 ) ;
V_3 &= ~ ( V_5 << V_1 -> V_6 ) ;
F_3 ( V_3 , V_7 , V_8 ) ;
}
T_1 F_17 ( void )
{
T_1 V_13 , V_14 = 0 ;
V_13 = F_2 ( V_7 , V_15 ) ;
V_13 &= V_16 ;
V_13 >>= V_17 ;
if ( V_13 == V_18 )
V_14 = 19200000 ;
else if ( V_13 == V_19 )
V_14 = 13000000 ;
else if ( V_13 == V_20 )
V_14 = 12000000 ;
return V_14 ;
}
