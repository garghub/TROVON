static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 , 1 ) ;
F_3 ( V_3 -> V_5 , 1 ) ;
if ( V_3 -> V_6 )
F_4 ( V_3 -> V_7 , V_8 ,
V_3 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 , 0 ) ;
F_3 ( V_3 -> V_5 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_7 )
{
struct V_2 * V_3 ;
T_1 V_9 , V_10 ;
V_3 = F_7 ( & V_7 -> V_11 , sizeof( * V_3 ) , V_12 ) ;
if ( ! V_3 )
return - V_13 ;
V_3 -> V_4 = F_8 ( & V_7 -> V_11 , L_1 ,
V_14 ) ;
if ( F_9 ( V_3 -> V_4 ) )
return F_10 ( V_3 -> V_4 ) ;
F_3 ( V_3 -> V_4 , 1 ) ;
V_3 -> V_5 = F_8 ( & V_7 -> V_11 , L_2 ,
V_14 ) ;
if ( F_9 ( V_3 -> V_5 ) )
return F_10 ( V_3 -> V_5 ) ;
F_3 ( V_3 -> V_5 , 1 ) ;
F_11 ( & V_7 -> V_11 , L_3 , & V_9 ) ;
V_10 = V_9 << V_15 ;
F_11 ( & V_7 -> V_11 , L_4 , & V_9 ) ;
V_10 |= V_9 << V_16 ;
F_11 ( & V_7 -> V_11 , L_5 , & V_9 ) ;
V_10 |= V_9 << V_17 ;
if ( V_10 ) {
F_4 ( V_7 , V_8 , V_10 ) ;
V_3 -> V_6 = V_10 ;
}
V_3 -> V_1 = F_12 ( V_7 , & V_18 ) ;
if ( F_9 ( V_3 -> V_1 ) )
return F_10 ( V_3 -> V_1 ) ;
V_3 -> V_7 = V_7 ;
F_13 ( V_3 -> V_1 , V_3 ) ;
F_14 ( V_7 , V_3 ) ;
return 0 ;
}
static void F_15 ( struct V_7 * V_7 )
{
struct V_2 * V_3 = F_16 ( V_7 ) ;
F_17 ( V_7 , V_3 -> V_1 ) ;
}
