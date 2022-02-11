static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_5 ) ;
F_6 ( V_2 ) ;
}
int F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_9 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_14 ;
V_4 = F_9 ( V_7 -> V_15 , sizeof( * V_4 ) , V_16 ) ;
if ( V_4 == NULL )
return - V_17 ;
V_2 = & V_4 -> V_2 ;
V_4 -> V_5 = F_10 ( V_11 ) ;
if ( ! V_4 -> V_5 )
return - V_18 ;
V_14 = F_11 ( V_7 -> V_19 , V_2 , & V_20 ,
V_21 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( V_2 , & V_22 ) ;
V_2 -> V_23 = V_24 ;
F_13 ( & V_2 -> V_25 ,
V_7 -> V_19 -> V_26 . V_27 , V_24 ) ;
V_14 = F_14 ( V_2 , V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_15 ( V_4 -> V_5 , V_2 ) ;
if ( V_14 < 0 )
return V_14 ;
V_4 -> V_13 = V_9 ;
return 0 ;
}
