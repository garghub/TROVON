static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
unsigned int V_7 ;
V_6 = F_3 ( V_5 -> V_8 ,
V_5 -> V_9 + V_10 ,
V_5 -> V_11 , V_3 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_3 ( V_5 -> V_8 ,
V_5 -> V_9 + V_10 ,
V_12 ,
V_12 ) ;
if ( V_6 )
return V_6 ;
return F_4 ( V_5 -> V_8 ,
V_5 -> V_9 + V_13 ,
V_7 , ! ( V_7 & V_12 ) ,
0 , 1 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_14 = F_6 ( V_2 ) ;
int V_6 ;
unsigned int V_7 ;
V_6 = F_7 ( V_5 -> V_8 ,
V_5 -> V_9 + V_15 , & V_7 ) ;
if ( V_6 )
return V_6 ;
V_7 &= V_5 -> V_11 ;
return V_7 < V_14 ? V_7 : - V_16 ;
}
struct V_1 * F_8 ( struct V_17 * V_18 ,
struct V_8 * V_8 ,
const char * V_19 ,
const struct V_20 * V_21 )
{
struct V_4 * V_5 ;
struct V_22 V_23 ;
int V_6 ;
V_5 = F_9 ( V_18 , sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return F_10 ( - V_25 ) ;
V_23 . V_19 = V_19 ;
V_23 . V_26 = & V_27 ;
V_23 . V_28 = V_29 ;
V_23 . V_30 = V_21 -> V_30 ;
V_23 . V_14 = V_21 -> V_14 ,
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = V_21 -> V_9 ;
V_5 -> V_11 = V_21 -> V_11 ;
V_5 -> V_2 . V_23 = & V_23 ;
V_6 = F_11 ( V_18 , & V_5 -> V_2 ) ;
if ( V_6 )
return F_10 ( V_6 ) ;
return & V_5 -> V_2 ;
}
