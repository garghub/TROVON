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
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_19 * V_20 = & V_18 -> V_20 ;
F_6 ( V_20 , L_1 ) ;
F_6 ( V_20 , L_2 ) ;
F_6 ( V_20 , L_3 ) ;
F_6 ( V_20 , L_4 ) ;
F_6 ( V_20 , L_5 ) ;
F_6 ( V_20 , L_6 ) ;
F_6 ( V_20 , L_7 ) ;
F_6 ( V_20 , L_8 ) ;
F_6 ( V_20 , L_9 ) ;
F_7 ( V_20 , V_21 ,
F_8 ( V_21 ) ) ;
F_9 ( V_20 , V_22 , F_8 ( V_22 ) ) ;
return 0 ;
}
static int T_1 F_10 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_27 ;
int V_28 ;
V_28 = F_11 ( V_29 ,
F_8 ( V_29 ) ) ;
if ( V_28 )
return V_28 ;
V_26 -> V_30 = & V_24 -> V_30 ;
V_28 = F_12 ( V_26 ) ;
if ( V_28 ) {
F_13 ( & V_24 -> V_30 , L_10 ,
V_28 ) ;
F_14 ( V_29 , F_8 ( V_29 ) ) ;
}
return V_28 ;
}
static int T_2 F_15 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_16 ( V_24 ) ;
F_14 ( V_29 , F_8 ( V_29 ) ) ;
F_17 ( V_26 ) ;
return 0 ;
}
