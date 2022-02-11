struct V_1 * F_1 ( struct V_2 * V_3 ,
const char * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 V_10 ;
int V_11 ;
V_8 = F_2 ( V_3 , sizeof( * V_8 ) , V_12 ) ;
if ( ! V_8 )
return F_3 ( - V_13 ) ;
V_10 . V_4 = V_4 ;
V_10 . V_14 = & V_15 ;
V_10 . V_16 = NULL ;
V_10 . V_17 = 0 ;
V_8 -> V_18 = V_6 -> V_18 ;
V_8 -> V_19 . V_10 = & V_10 ;
V_11 = F_4 ( V_3 , & V_8 -> V_19 ) ;
if ( V_11 )
return F_3 ( V_11 ) ;
return & V_8 -> V_19 ;
}
