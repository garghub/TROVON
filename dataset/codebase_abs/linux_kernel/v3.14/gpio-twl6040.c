static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_7 = 0 ;
V_7 = F_3 ( V_4 , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
return ( V_7 >> V_3 ) & 1 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_9 )
{
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_9 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
int V_7 ;
T_1 V_10 ;
V_7 = F_3 ( V_4 , V_8 ) ;
if ( V_7 < 0 )
return;
if ( V_9 )
V_10 = V_7 | ( 1 << V_3 ) ;
else
V_10 = V_7 & ~ ( 1 << V_3 ) ;
F_6 ( V_4 , V_8 , V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_5 . V_6 ;
struct V_4 * V_4 = F_2 ( V_14 ) ;
int V_7 ;
V_15 . V_16 = - 1 ;
if ( F_8 ( V_4 ) < V_17 )
V_15 . V_18 = 3 ;
else
V_15 . V_18 = 1 ;
V_15 . V_5 = & V_12 -> V_5 ;
#ifdef F_9
V_15 . V_19 = V_14 -> V_19 ;
#endif
V_7 = F_10 ( & V_15 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_12 -> V_5 , L_1 , V_7 ) ;
V_15 . V_18 = 0 ;
}
return V_7 ;
}
static int F_12 ( struct V_11 * V_12 )
{
return F_13 ( & V_15 ) ;
}
