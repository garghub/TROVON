T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_3 ( & V_5 -> V_7 ) ;
V_6 = F_4 ( V_5 -> V_8 + V_9 ) ;
V_6 |= V_3 ;
F_5 ( V_6 , V_5 -> V_8 + V_9 ) ;
F_6 ( & V_5 -> V_7 ) ;
return F_4 ( V_5 -> V_8 + V_10 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
int V_13 ;
struct V_14 * V_15 ;
struct V_4 * V_5 ;
struct V_16 * V_17 = V_12 -> V_2 . V_18 ;
V_5 = F_8 ( & V_12 -> V_2 , sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_9 ( & V_12 -> V_2 , L_1 ) ;
return - V_20 ;
}
F_10 ( & V_5 -> V_7 ) ;
V_15 = F_11 ( V_12 , V_21 , 0 ) ;
if ( ! V_15 ) {
F_9 ( & V_12 -> V_2 , L_2 ) ;
return - V_22 ;
}
V_5 -> V_8 = F_12 ( & V_12 -> V_2 , V_15 ) ;
if ( F_13 ( V_5 -> V_8 ) )
return F_14 ( V_5 -> V_8 ) ;
F_15 ( & V_12 -> V_2 ) ;
F_16 ( & V_12 -> V_2 ) ;
F_17 ( V_12 , V_5 ) ;
V_13 = F_18 ( V_17 , NULL , NULL , & V_12 -> V_2 ) ;
if ( V_13 )
F_9 ( & V_12 -> V_2 , L_3 ) ;
return V_13 ;
}
static int F_19 ( struct V_11 * V_12 )
{
struct V_4 * V_5 = F_20 ( V_12 ) ;
F_21 ( & V_12 -> V_2 ) ;
F_22 ( & V_12 -> V_2 ) ;
F_23 ( & V_5 -> V_7 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_23 = F_4 ( V_5 -> V_8 + V_9 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_16 ( V_2 ) ;
F_5 ( V_5 -> V_23 , V_5 -> V_8 + V_9 ) ;
return 0 ;
}
