static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
if ( F_6 ( V_5 ) )
F_7 ( V_4 ) ;
}
static int F_8 ( struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_10 ;
V_4 -> V_1 = F_9 ( V_7 , 1 ) ;
if ( V_4 -> V_1 < 0 )
return V_4 -> V_1 ;
if ( F_6 ( V_5 ) ) {
V_4 -> V_11 = F_9 ( V_7 , 0 ) ;
if ( V_4 -> V_11 < 0 )
return V_4 -> V_11 ;
V_10 = F_10 ( V_9 , V_4 -> V_11 ,
F_1 ,
V_12 , L_1 , V_4 ) ;
if ( V_10 ) {
F_11 ( V_9 , L_2 ) ;
return V_10 ;
}
}
V_4 -> V_13 = - 1 ;
V_4 -> V_14 = & V_15 ;
V_10 = F_12 ( V_4 ) ;
if ( V_10 ) {
F_11 ( V_9 , L_3 ) ;
return V_10 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
struct V_16 * V_16 ;
struct V_3 * V_4 ;
struct V_17 * V_18 ;
int V_10 ;
V_16 = F_14 ( V_9 , sizeof( * V_16 ) , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_4 = & V_16 -> V_4 ;
V_4 -> V_9 = V_9 ;
V_18 = F_15 ( V_7 , V_21 , 0 ) ;
V_4 -> V_22 = F_16 ( V_9 , V_18 ) ;
if ( F_17 ( V_4 -> V_22 ) )
return F_18 ( V_4 -> V_22 ) ;
V_10 = F_8 ( V_4 , V_7 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
