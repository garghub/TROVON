int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , sizeof( struct V_5 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
V_6 -> V_12 = F_3 ( V_2 , 0 ) ;
if ( V_6 -> V_12 < 0 )
return V_6 -> V_12 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_9 = & V_2 -> V_9 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = V_2 -> V_9 . V_15 ;
V_8 = F_4 ( V_2 , V_16 , 0 ) ;
V_6 -> V_8 = F_5 ( & V_2 -> V_9 , V_8 ) ;
if ( F_6 ( V_6 -> V_8 ) )
return F_7 ( V_6 -> V_8 ) ;
V_6 -> V_17 = V_8 -> V_18 ;
F_8 ( V_2 , V_6 ) ;
return F_9 ( V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = NULL ;
const struct V_19 * V_20 ;
if ( V_2 -> V_9 . V_21 ) {
V_20 = F_11 ( V_22 , V_2 -> V_9 . V_21 ) ;
V_4 = V_20 -> V_23 ;
}
return F_1 ( V_2 , V_4 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
