int F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_5 -> V_10 ,
V_2 , V_3 ) ;
int V_11 = V_9 -> error ;
if ( V_11 )
ERROR ( L_1 , V_2 ,
V_3 ) ;
else
F_3 ( V_1 , V_9 , V_9 -> V_12 , 0 ) ;
F_4 ( V_9 ) ;
return V_11 ;
}
