static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
V_7 = V_5 -> V_8 () ;
V_5 -> V_9 = F_3 ( V_5 -> V_10 , V_7 ) ;
return V_5 -> V_9 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
V_7 = F_5 ( V_5 -> V_10 , V_9 ) ;
return F_3 ( V_5 -> V_10 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_9 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 V_7 ;
V_7 = F_5 ( V_5 -> V_10 , V_9 ) ;
V_5 -> V_9 = F_3 ( V_5 -> V_10 , V_7 ) ;
V_5 -> V_12 ( V_7 ) ;
return 0 ;
}
struct V_13 * T_1 F_7 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_13 * V_13 ;
struct V_4 * V_5 ;
struct V_18 V_19 ;
V_5 = F_8 ( sizeof( struct V_4 ) , V_20 ) ;
if ( ! V_5 ) {
F_9 ( L_1 ) ;
return F_10 ( - V_21 ) ;
}
V_19 . V_22 = L_2 ;
V_19 . V_23 = & V_24 ;
V_19 . V_25 = V_26 ;
V_19 . V_27 = NULL ;
V_19 . V_28 = 0 ;
V_5 -> V_2 . V_19 = & V_19 ;
V_5 -> V_10 = V_17 -> V_10 ;
V_5 -> V_8 = V_17 -> V_8 ;
V_5 -> V_12 = V_17 -> V_12 ;
V_13 = F_11 ( V_15 , & V_5 -> V_2 ) ;
if ( F_12 ( V_13 ) )
F_13 ( V_5 ) ;
return V_13 ;
}
