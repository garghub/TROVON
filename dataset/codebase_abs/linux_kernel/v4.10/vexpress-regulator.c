static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_6 = F_3 ( V_4 -> V_7 , 0 , & V_5 ) ;
return V_6 ? V_6 : V_5 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_8 , int V_9 , unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_5 ( V_4 -> V_7 , 0 , V_8 ) ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_15 V_16 = { } ;
V_4 = F_7 ( & V_12 -> V_17 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_4 -> V_7 = F_8 ( & V_12 -> V_17 ) ;
if ( F_9 ( V_4 -> V_7 ) )
return F_10 ( V_4 -> V_7 ) ;
V_4 -> V_20 . V_21 = F_11 ( & V_12 -> V_17 ) ;
V_4 -> V_20 . type = V_22 ;
V_4 -> V_20 . V_23 = V_24 ;
V_4 -> V_20 . V_25 = true ;
V_14 = F_12 ( & V_12 -> V_17 , V_12 -> V_17 . V_26 ,
& V_4 -> V_20 ) ;
if ( ! V_14 )
return - V_27 ;
V_14 -> V_28 . V_29 = 0 ;
if ( V_14 -> V_28 . V_8 && V_14 -> V_28 . V_9 )
V_4 -> V_20 . V_30 = & V_31 ;
else
V_4 -> V_20 . V_30 = & V_32 ;
V_16 . V_17 = & V_12 -> V_17 ;
V_16 . V_14 = V_14 ;
V_16 . V_33 = V_4 ;
V_16 . V_26 = V_12 -> V_17 . V_26 ;
V_4 -> V_2 = F_13 ( & V_12 -> V_17 , & V_4 -> V_20 , & V_16 ) ;
if ( F_9 ( V_4 -> V_2 ) )
return F_10 ( V_4 -> V_2 ) ;
F_14 ( V_12 , V_4 ) ;
return 0 ;
}
