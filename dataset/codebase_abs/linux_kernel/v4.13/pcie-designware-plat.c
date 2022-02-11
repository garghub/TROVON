static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_6 ) ;
if ( F_7 ( V_7 ) )
F_8 ( V_4 ) ;
}
static int F_9 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
int V_12 ;
V_4 -> V_1 = F_10 ( V_9 , 1 ) ;
if ( V_4 -> V_1 < 0 )
return V_4 -> V_1 ;
if ( F_7 ( V_7 ) ) {
V_4 -> V_13 = F_10 ( V_9 , 0 ) ;
if ( V_4 -> V_13 < 0 )
return V_4 -> V_13 ;
V_12 = F_11 ( V_11 , V_4 -> V_13 ,
F_1 ,
V_14 | V_15 ,
L_1 , V_4 ) ;
if ( V_12 ) {
F_12 ( V_11 , L_2 ) ;
return V_12 ;
}
}
V_4 -> V_16 = - 1 ;
V_4 -> V_17 = & V_18 ;
V_12 = F_13 ( V_4 ) ;
if ( V_12 ) {
F_12 ( V_11 , L_3 ) ;
return V_12 ;
}
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_19 * V_19 ;
struct V_5 * V_6 ;
struct V_20 * V_21 ;
int V_12 ;
V_19 = F_15 ( V_11 , sizeof( * V_19 ) , V_22 ) ;
if ( ! V_19 )
return - V_23 ;
V_6 = F_15 ( V_11 , sizeof( * V_6 ) , V_22 ) ;
if ( ! V_6 )
return - V_23 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_17 = & V_24 ;
V_19 -> V_6 = V_6 ;
V_21 = F_16 ( V_9 , V_25 , 0 ) ;
V_6 -> V_26 = F_17 ( V_11 , V_21 ) ;
if ( F_18 ( V_6 -> V_26 ) )
return F_19 ( V_6 -> V_26 ) ;
F_20 ( V_9 , V_19 ) ;
V_12 = F_9 ( & V_6 -> V_4 , V_9 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
