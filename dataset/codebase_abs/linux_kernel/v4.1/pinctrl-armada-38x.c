static int F_1 ( unsigned V_1 , unsigned long * V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( unsigned V_1 , unsigned long V_2 )
{
return F_4 ( V_3 , V_1 , V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_8 ;
const struct V_9 * V_10 =
F_6 ( V_11 , & V_5 -> V_12 ) ;
struct V_13 * V_14 ;
if ( ! V_10 )
return - V_15 ;
V_14 = F_7 ( V_5 , V_16 , 0 ) ;
V_3 = F_8 ( & V_5 -> V_12 , V_14 ) ;
if ( F_9 ( V_3 ) )
return F_10 ( V_3 ) ;
V_7 -> V_17 = ( unsigned ) V_10 -> V_18 & 0xff ;
V_7 -> V_19 = V_20 ;
V_7 -> V_21 = F_11 ( V_20 ) ;
V_7 -> V_22 = V_23 ;
V_7 -> V_24 = F_11 ( V_23 ) ;
V_7 -> V_25 = V_26 ;
V_7 -> V_27 = V_20 [ 0 ] . V_28 ;
V_5 -> V_12 . V_29 = V_7 ;
return F_12 ( V_5 ) ;
}
static int F_13 ( struct V_4 * V_5 )
{
return F_14 ( V_5 ) ;
}
