static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 =
F_2 ( V_5 , & V_2 -> V_6 ) ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
struct V_10 * V_11 ;
void T_1 * V_12 ;
V_8 = F_3 ( & V_2 -> V_6 , sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return - V_14 ;
V_11 = F_4 ( V_2 , V_15 , 0 ) ;
V_12 = F_5 ( & V_2 -> V_6 , V_11 ) ;
if ( F_6 ( V_12 ) )
return F_7 ( V_12 ) ;
V_8 -> V_16 = 32 ,
V_8 -> V_17 = 32 ,
V_8 -> V_18 = 4 ,
V_8 -> V_19 = F_8 ( V_11 ) ;
V_9 = F_9 ( & V_2 -> V_6 , V_12 , V_8 ) ;
if ( F_6 ( V_9 ) )
return F_7 ( V_9 ) ;
return F_10 ( V_2 , V_4 -> V_20 ) ;
}
