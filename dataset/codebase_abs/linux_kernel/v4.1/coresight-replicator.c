static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_7 , L_1 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
F_3 ( V_6 -> V_7 , L_2 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_7 = & V_10 -> V_7 ;
struct V_12 * V_13 = NULL ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_10 -> V_7 . V_18 ;
if ( V_17 ) {
V_13 = F_6 ( V_7 , V_17 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
V_10 -> V_7 . V_19 = V_13 ;
}
V_6 = F_9 ( V_7 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_7 = & V_10 -> V_7 ;
F_10 ( V_10 , V_6 ) ;
V_15 = F_9 ( V_7 , sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 )
return - V_21 ;
V_15 -> type = V_22 ;
V_15 -> V_23 . V_24 = V_25 ;
V_15 -> V_26 = & V_27 ;
V_15 -> V_13 = V_10 -> V_7 . V_19 ;
V_15 -> V_7 = & V_10 -> V_7 ;
V_6 -> V_2 = F_11 ( V_15 ) ;
if ( F_7 ( V_6 -> V_2 ) )
return F_8 ( V_6 -> V_2 ) ;
F_3 ( V_7 , L_3 ) ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_5 * V_6 = F_13 ( V_10 ) ;
F_14 ( V_6 -> V_2 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_28 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_28 ) ;
}
