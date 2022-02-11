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
int V_8 ;
V_4 -> V_1 = F_9 ( V_7 , 1 ) ;
if ( V_4 -> V_1 < 0 )
return V_4 -> V_1 ;
if ( F_6 ( V_5 ) ) {
V_4 -> V_9 = F_9 ( V_7 , 0 ) ;
if ( V_4 -> V_9 < 0 )
return V_4 -> V_9 ;
V_8 = F_10 ( & V_7 -> V_10 , V_4 -> V_9 ,
F_1 ,
V_11 , L_1 , V_4 ) ;
if ( V_8 ) {
F_11 ( & V_7 -> V_10 , L_2 ) ;
return V_8 ;
}
}
V_4 -> V_12 = - 1 ;
V_4 -> V_13 = & V_14 ;
V_8 = F_12 ( V_4 ) ;
if ( V_8 ) {
F_11 ( & V_7 -> V_10 , L_3 ) ;
return V_8 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_15 * V_15 ;
struct V_3 * V_4 ;
struct V_16 * V_17 ;
int V_8 ;
V_15 = F_14 ( & V_7 -> V_10 , sizeof( * V_15 ) ,
V_18 ) ;
if ( ! V_15 )
return - V_19 ;
V_4 = & V_15 -> V_4 ;
V_4 -> V_10 = & V_7 -> V_10 ;
V_17 = F_15 ( V_7 , V_20 , 0 ) ;
if ( ! V_17 )
return - V_21 ;
V_15 -> V_22 = F_16 ( & V_7 -> V_10 , V_17 ) ;
if ( F_17 ( V_15 -> V_22 ) )
return F_18 ( V_15 -> V_22 ) ;
V_4 -> V_23 = V_15 -> V_22 ;
V_8 = F_8 ( V_4 , V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
F_19 ( V_7 , V_15 ) ;
return 0 ;
}
