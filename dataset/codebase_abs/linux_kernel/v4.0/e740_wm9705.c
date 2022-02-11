static void F_1 ( int V_1 )
{
F_2 ( V_2 , ! V_1 ) ;
F_2 ( V_3 , ( V_1 & V_4 ) ? 1 : 0 ) ;
F_2 ( V_5 , ( V_1 & V_6 ) ? 1 : 0 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
if ( V_11 & V_12 )
V_13 |= V_6 ;
else if ( V_11 & V_14 )
V_13 &= ~ V_6 ;
F_1 ( V_13 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
if ( V_11 & V_12 )
V_13 |= V_4 ;
else if ( V_11 & V_14 )
V_13 &= ~ V_4 ;
F_1 ( V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = & V_19 ;
int V_20 ;
V_20 = F_6 ( V_21 ,
F_7 ( V_21 ) ) ;
if ( V_20 )
return V_20 ;
V_18 -> V_22 = & V_16 -> V_22 ;
V_20 = F_8 ( V_18 ) ;
if ( V_20 ) {
F_9 ( & V_16 -> V_22 , L_1 ,
V_20 ) ;
F_10 ( V_21 , F_7 ( V_21 ) ) ;
}
return V_20 ;
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_12 ( V_16 ) ;
F_10 ( V_21 , F_7 ( V_21 ) ) ;
F_13 ( V_18 ) ;
return 0 ;
}
