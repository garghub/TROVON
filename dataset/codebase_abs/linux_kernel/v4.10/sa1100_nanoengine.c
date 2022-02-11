static int F_1 ( struct V_1 * V_2 )
{
unsigned V_3 = V_2 -> V_4 ;
int V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
V_5 = F_2 ( V_8 [ V_3 ] . V_9 , V_10 ,
V_3 ? L_1 : L_2 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_11 [ V_12 ] . V_13 = V_8 [ V_3 ] . V_14 ;
V_2 -> V_11 [ V_12 ] . V_15 = V_3 ? L_3 : L_4 ;
V_2 -> V_11 [ V_16 ] . V_13 = V_8 [ V_3 ] . V_17 ;
V_2 -> V_11 [ V_16 ] . V_15 = V_3 ? L_5 : L_6 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_8 [ V_2 -> V_4 ] . V_9 ) ;
}
static int F_5 (
struct V_1 * V_2 , const T_1 * V_18 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_6 ( V_8 [ V_2 -> V_4 ] . V_9 , ! ! ( V_18 -> V_19 & V_20 ) ) ;
return 0 ;
}
static void F_7 (
struct V_1 * V_2 , struct V_21 * V_18 )
{
unsigned V_3 = V_2 -> V_4 ;
if ( V_3 >= V_6 )
return;
V_18 -> V_22 = 1 ;
V_18 -> V_23 = 1 ;
V_18 -> V_24 = 1 ;
V_18 -> V_25 = 0 ;
}
int F_8 ( struct V_26 * V_27 )
{
int V_5 = - V_28 ;
if ( F_9 () )
V_5 = F_10 (
V_27 , & V_29 , 0 , 2 ) ;
return V_5 ;
}
