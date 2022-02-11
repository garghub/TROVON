static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( F_2 ( V_3 == V_5 ) )
V_4 = F_3 ( V_2 -> V_6 + V_3 ) ;
else
V_4 = F_4 ( V_2 , V_3 ) ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_7 , int V_3 )
{
if ( V_3 == V_8 ) {
V_7 &= ~ F_6 ( 0x7 , 0 ) ;
}
F_7 ( V_2 , V_7 , V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_7 , int V_3 )
{
if ( V_3 == V_9 )
V_7 &= ~ V_10 ;
F_9 ( V_2 , V_7 , V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_6 + V_11 , V_12 ) ;
return 0 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_13 ( V_2 ) ;
return V_14 -> clock ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_13 ( V_2 ) ;
return V_14 -> clock / 256 / 16 ;
}
static int T_3 F_15 ( struct V_15 * V_16 )
{
return F_16 ( V_16 , & V_17 ) ;
}
static int T_4 F_17 ( struct V_15 * V_16 )
{
return F_18 ( V_16 ) ;
}
static int T_5 F_19 ( void )
{
return F_20 ( & V_18 ) ;
}
static void T_6 F_21 ( void )
{
F_22 ( & V_18 ) ;
}
