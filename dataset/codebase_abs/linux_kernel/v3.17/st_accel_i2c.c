static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = F_2 ( & V_2 -> V_10 , sizeof( * V_8 ) ) ;
if ( ! V_6 )
return - V_11 ;
V_8 = F_3 ( V_6 ) ;
V_8 -> V_10 = & V_2 -> V_10 ;
F_4 ( V_2 , V_12 ) ;
F_5 ( V_6 , V_2 , V_8 ) ;
V_9 = F_6 ( V_6 , V_2 -> V_10 . V_13 ) ;
if ( V_9 < 0 )
return V_9 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( F_9 ( V_2 ) ) ;
return 0 ;
}
