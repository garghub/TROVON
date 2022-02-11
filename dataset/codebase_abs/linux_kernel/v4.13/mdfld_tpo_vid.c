static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_6 = 864 ;
V_4 -> V_7 = 480 ;
V_4 -> V_8 = 873 ;
V_4 -> V_9 = 876 ;
V_4 -> V_10 = 887 ;
V_4 -> V_11 = 487 ;
V_4 -> V_12 = 490 ;
V_4 -> V_13 = 499 ;
V_4 -> clock = 33264 ;
F_3 ( V_4 ) ;
F_4 ( V_4 , 0 ) ;
V_4 -> type |= V_14 ;
return V_4 ;
}
static int F_5 ( struct V_2 * V_3 ,
int V_15 ,
struct V_16 * V_17 )
{
if ( ! V_3 || ! V_17 )
return - V_18 ;
V_17 -> V_19 = V_20 ;
V_17 -> V_21 = V_22 ;
return 0 ;
}
