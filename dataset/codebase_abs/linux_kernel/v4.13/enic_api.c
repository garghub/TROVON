int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 V_5 , T_1 * V_6 , T_1 * V_7 , int V_8 )
{
int V_9 ;
struct V_10 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_3 ( & V_10 -> V_13 ) ;
F_4 ( & V_10 -> V_14 ) ;
F_5 ( V_12 , V_3 ) ;
V_9 = F_6 ( V_12 , V_5 , V_6 , V_7 , V_8 ) ;
F_7 ( V_12 ) ;
F_8 ( & V_10 -> V_14 ) ;
F_9 ( & V_10 -> V_13 ) ;
return V_9 ;
}
