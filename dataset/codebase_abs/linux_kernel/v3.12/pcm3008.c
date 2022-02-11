static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_2 ( V_9 -> V_12 ,
F_3 ( V_5 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 -> V_11 ;
F_2 ( V_9 -> V_13 ,
F_3 ( V_5 ) ) ;
return 0 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = V_15 -> V_10 . V_11 ;
int V_16 ;
if ( ! V_9 )
return - V_17 ;
V_16 = F_6 ( & V_15 -> V_10 , V_9 -> V_18 ,
V_19 , L_1 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_6 ( & V_15 -> V_10 , V_9 -> V_20 ,
V_21 , L_2 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_6 ( & V_15 -> V_10 , V_9 -> V_13 ,
V_21 , L_3 ) ;
if ( V_16 != 0 )
return V_16 ;
V_16 = F_6 ( & V_15 -> V_10 , V_9 -> V_12 ,
V_21 , L_4 ) ;
if ( V_16 != 0 )
return V_16 ;
return F_7 ( & V_15 -> V_10 ,
& V_22 , & V_23 , 1 ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
F_9 ( & V_15 -> V_10 ) ;
return 0 ;
}
