static enum V_1 F_1 ( struct V_2 * V_3 )
{
return V_4 ;
}
static int F_2 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_1 V_8 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
F_3 ( 0 , V_10 -> V_11 + V_12 ) ;
F_4 ( V_13 ) ;
F_3 ( V_14 , V_10 -> V_11 + V_12 ) ;
F_4 ( V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_2 * V_3 , const char * V_7 ,
T_1 V_8 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
T_1 V_16 = 0 ;
int V_17 ;
T_2 V_18 ;
while ( V_8 -- ) {
V_17 = F_6 ( V_10 -> V_11 + V_12 ,
V_18 , ! ( V_18 & V_19 ) ,
1 , V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
F_3 ( V_7 [ V_16 ] , V_10 -> V_11 + V_21 ) ;
V_16 ++ ;
}
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
T_2 V_18 ;
F_8 ( 1000 , 2000 ) ;
V_18 = F_9 ( V_10 -> V_11 + V_12 ) ;
V_18 |= V_22 ;
F_3 ( V_18 , V_10 -> V_11 + V_12 ) ;
F_8 ( 1000 , 2000 ) ;
V_18 = F_9 ( V_10 -> V_11 + V_12 ) ;
V_18 &= ~ V_22 ;
F_3 ( V_18 , V_10 -> V_11 + V_12 ) ;
V_18 = F_9 ( V_10 -> V_11 + V_12 ) ;
if ( ( V_18 & V_23 ) != V_23 )
return - V_24 ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_29 ;
struct V_9 * V_10 ;
struct V_30 * V_31 ;
V_10 = F_11 ( V_28 , sizeof( * V_10 ) , V_32 ) ;
if ( ! V_10 )
return - V_33 ;
V_10 -> V_29 = V_28 ;
V_31 = F_12 ( V_26 , V_34 , 0 ) ;
V_10 -> V_11 = F_13 ( V_28 , V_31 ) ;
if ( F_14 ( V_10 -> V_11 ) ) {
F_15 ( V_28 , L_1 ) ;
return F_16 ( V_10 -> V_11 ) ;
}
return F_17 ( V_28 , L_2 ,
& V_35 , V_10 ) ;
}
static int F_18 ( struct V_25 * V_26 )
{
F_19 ( & V_26 -> V_29 ) ;
return 0 ;
}
