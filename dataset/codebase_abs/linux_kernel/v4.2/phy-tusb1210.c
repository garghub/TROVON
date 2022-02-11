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
struct V_9 * V_10 ;
struct V_2 * V_3 ;
T_1 V_11 , V_12 ;
int V_13 ;
V_3 = F_7 ( & V_7 -> V_14 , sizeof( * V_3 ) , V_15 ) ;
if ( ! V_3 )
return - V_16 ;
V_10 = F_8 ( & V_7 -> V_14 , L_1 ) ;
if ( ! F_9 ( V_10 ) ) {
V_13 = F_10 ( V_10 , 0 ) ;
if ( V_13 )
return V_13 ;
F_3 ( V_10 , 1 ) ;
V_3 -> V_4 = V_10 ;
}
V_10 = F_8 ( & V_7 -> V_14 , L_2 ) ;
if ( ! F_9 ( V_10 ) ) {
V_13 = F_10 ( V_10 , 0 ) ;
if ( V_13 )
return V_13 ;
F_3 ( V_10 , 1 ) ;
V_3 -> V_5 = V_10 ;
}
F_11 ( & V_7 -> V_14 , L_3 , & V_11 ) ;
V_12 = V_11 << V_17 ;
F_11 ( & V_7 -> V_14 , L_4 , & V_11 ) ;
V_12 |= V_11 << V_18 ;
F_11 ( & V_7 -> V_14 , L_5 , & V_11 ) ;
V_12 |= V_11 << V_19 ;
if ( V_12 ) {
F_4 ( V_7 , V_8 , V_12 ) ;
V_3 -> V_6 = V_12 ;
}
V_3 -> V_1 = F_12 ( V_7 , & V_20 ) ;
if ( F_9 ( V_3 -> V_1 ) )
return F_13 ( V_3 -> V_1 ) ;
V_3 -> V_7 = V_7 ;
F_14 ( V_3 -> V_1 , V_3 ) ;
F_15 ( V_7 , V_3 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_7 )
{
struct V_2 * V_3 = F_17 ( V_7 ) ;
F_18 ( V_7 , V_3 -> V_1 ) ;
}
