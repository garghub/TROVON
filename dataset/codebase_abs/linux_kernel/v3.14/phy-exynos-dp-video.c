static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_2 -> V_5 ) ;
if ( V_3 )
V_4 |= V_6 ;
else
V_4 &= ~ V_6 ;
F_3 ( V_4 , V_2 -> V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
return F_1 ( V_2 , 1 ) ;
}
static int F_6 ( struct V_7 * V_7 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
return F_1 ( V_2 , 0 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
struct V_7 * V_7 ;
V_2 = F_8 ( V_11 , sizeof( * V_2 ) , V_15 ) ;
if ( ! V_2 )
return - V_16 ;
V_13 = F_9 ( V_9 , V_17 , 0 ) ;
V_2 -> V_5 = F_10 ( V_11 , V_13 ) ;
if ( F_11 ( V_2 -> V_5 ) )
return F_12 ( V_2 -> V_5 ) ;
V_7 = F_13 ( V_11 , & V_18 , NULL ) ;
if ( F_11 ( V_7 ) ) {
F_14 ( V_11 , L_1 ) ;
return F_12 ( V_7 ) ;
}
F_15 ( V_7 , V_2 ) ;
V_14 = F_16 ( V_11 , V_19 ) ;
if ( F_11 ( V_14 ) )
return F_12 ( V_14 ) ;
return 0 ;
}
