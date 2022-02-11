static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_2 -> V_9 ;
V_5 = F_2 ( V_10 , V_9 -> V_11 ) ;
V_7 = (struct V_6 * ) V_5 -> V_12 ;
V_3 = F_3 ( V_2 , V_7 ) ;
if ( V_3 )
F_4 ( V_9 , L_1 , V_3 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_6 ( V_2 ) ;
F_7 ( & ( V_2 ) -> V_9 ) ;
F_8 ( V_14 ) ;
return 0 ;
}
