static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , unsigned int V_5 )
{
void T_1 * V_6 ;
T_2 V_7 , V_8 ;
V_6 = V_2 -> V_9 + F_2 ( V_4 / 2 ) ;
if ( F_3 ( V_4 ) )
V_8 = V_10 ;
else
V_8 = V_11 ;
F_4 ( & V_2 -> V_12 ) ;
V_7 = F_5 ( V_6 ) ;
if ( V_5 )
V_7 |= V_8 ;
else
V_7 &= ~ V_8 ;
F_6 ( V_7 , V_6 ) ;
if ( V_5 )
V_7 |= V_13 ;
else if ( ! ( V_7 & V_14 ) )
V_7 &= ~ V_13 ;
F_6 ( V_7 , V_6 ) ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_15 )
{
struct V_16 * V_17 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
return F_1 ( V_2 , V_17 -> V_18 , 1 ) ;
}
static int F_11 ( struct V_15 * V_15 )
{
struct V_16 * V_17 = F_9 ( V_15 ) ;
struct V_1 * V_2 = F_10 ( V_17 ) ;
return F_1 ( V_2 , V_17 -> V_18 , 0 ) ;
}
static struct V_15 * F_12 ( struct V_19 * V_20 ,
struct V_21 * args )
{
struct V_1 * V_2 = F_13 ( V_20 ) ;
if ( F_14 ( args -> args [ 0 ] >= V_22 ) )
return F_15 ( - V_23 ) ;
return V_2 -> V_24 [ args -> args [ 0 ] ] . V_15 ;
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_19 * V_20 = & V_26 -> V_20 ;
struct V_27 * V_28 ;
struct V_29 * V_29 ;
unsigned int V_30 ;
V_2 = F_17 ( V_20 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_28 = F_18 ( V_26 , V_33 , 0 ) ;
V_2 -> V_9 = F_19 ( V_20 , V_28 ) ;
if ( F_20 ( V_2 -> V_9 ) )
return F_21 ( V_2 -> V_9 ) ;
F_22 ( V_20 , V_2 ) ;
F_23 ( & V_2 -> V_12 ) ;
for ( V_30 = 0 ; V_30 < V_22 ; V_30 ++ ) {
struct V_15 * V_15 = F_24 ( V_20 , NULL ,
& V_34 ) ;
if ( F_20 ( V_15 ) ) {
F_25 ( V_20 , L_1 , V_30 ) ;
return F_21 ( V_15 ) ;
}
V_2 -> V_24 [ V_30 ] . V_15 = V_15 ;
V_2 -> V_24 [ V_30 ] . V_18 = V_30 ;
F_26 ( V_15 , & V_2 -> V_24 [ V_30 ] ) ;
}
V_29 = F_27 ( V_20 ,
F_12 ) ;
return F_28 ( V_29 ) ;
}
