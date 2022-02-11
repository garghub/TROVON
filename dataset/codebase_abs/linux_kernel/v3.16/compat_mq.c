static inline int F_1 ( struct V_1 * V_2 ,
const struct V_3 T_1 * V_4 )
{
if ( ! F_2 ( V_5 , V_4 , sizeof *V_4 ) )
return - V_6 ;
return F_3 ( V_2 -> V_7 , & V_4 -> V_7 )
| F_3 ( V_2 -> V_8 , & V_4 -> V_8 )
| F_3 ( V_2 -> V_9 , & V_4 -> V_9 )
| F_3 ( V_2 -> V_10 , & V_4 -> V_10 ) ;
}
static inline int F_4 ( const struct V_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
if ( F_5 ( V_4 , sizeof *V_4 ) )
return - V_6 ;
return F_6 ( V_2 -> V_7 , & V_4 -> V_7 )
| F_6 ( V_2 -> V_8 , & V_4 -> V_8 )
| F_6 ( V_2 -> V_9 , & V_4 -> V_9 )
| F_6 ( V_2 -> V_10 , & V_4 -> V_10 ) ;
}
