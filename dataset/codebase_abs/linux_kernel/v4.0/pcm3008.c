static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = V_7 -> V_11 -> V_12 ;
F_3 ( V_10 -> V_13 ,
F_4 ( V_5 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_10 = V_7 -> V_11 -> V_12 ;
F_3 ( V_10 -> V_14 ,
F_4 ( V_5 ) ) ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_9 * V_10 = V_16 -> V_11 . V_12 ;
int V_17 ;
if ( ! V_10 )
return - V_18 ;
V_17 = F_7 ( & V_16 -> V_11 , V_10 -> V_19 ,
V_20 , L_1 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_7 ( & V_16 -> V_11 , V_10 -> V_21 ,
V_22 , L_2 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_7 ( & V_16 -> V_11 , V_10 -> V_14 ,
V_22 , L_3 ) ;
if ( V_17 != 0 )
return V_17 ;
V_17 = F_7 ( & V_16 -> V_11 , V_10 -> V_13 ,
V_22 , L_4 ) ;
if ( V_17 != 0 )
return V_17 ;
return F_8 ( & V_16 -> V_11 ,
& V_23 , & V_24 , 1 ) ;
}
static int F_9 ( struct V_15 * V_16 )
{
F_10 ( & V_16 -> V_11 ) ;
return 0 ;
}
