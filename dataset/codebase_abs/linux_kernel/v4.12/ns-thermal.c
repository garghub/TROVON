static int F_1 ( void * V_1 , int * V_2 )
{
struct V_3 * V_3 = V_1 ;
int V_4 = F_2 ( V_3 -> V_5 ) ;
int V_6 = F_3 ( V_3 -> V_5 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_3 -> V_8 + V_9 ) ;
if ( ( V_7 & V_10 ) != V_11 ) {
V_7 &= ~ V_10 ;
V_7 |= V_11 ;
F_5 ( V_7 , V_3 -> V_8 + V_9 ) ;
}
V_7 = F_4 ( V_3 -> V_8 + V_12 ) ;
* V_2 = V_6 * V_7 + V_4 ;
return 0 ;
}
static int F_6 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
struct V_3 * V_3 ;
V_3 = F_7 ( V_16 , sizeof( * V_3 ) , V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_3 -> V_8 = F_8 ( F_9 ( V_16 ) , 0 ) ;
if ( F_10 ( ! V_3 -> V_8 ) )
return - V_19 ;
V_3 -> V_5 = F_11 ( V_16 , 0 ,
V_3 ,
& V_20 ) ;
if ( F_12 ( V_3 -> V_5 ) ) {
F_13 ( V_3 -> V_8 ) ;
return F_14 ( V_3 -> V_5 ) ;
}
F_15 ( V_14 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_3 * V_3 = F_17 ( V_14 ) ;
F_13 ( V_3 -> V_8 ) ;
return 0 ;
}
