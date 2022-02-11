bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_1 * V_4 )
{
F_2 ( V_4 -> V_3 != V_3 ,
L_1 ,
V_3 , V_4 -> V_3 , V_4 ) ;
F_2 ( V_3 -> V_4 != V_4 ,
L_2 ,
V_4 , V_3 -> V_4 , V_3 ) ;
F_2 ( V_2 == V_3 || V_2 == V_4 ,
L_3 ,
V_2 , V_3 , V_4 ) ;
return true ;
}
bool F_3 ( struct V_1 * V_5 )
{
struct V_1 * V_3 , * V_4 ;
V_3 = V_5 -> V_3 ;
V_4 = V_5 -> V_4 ;
F_2 ( V_4 == V_6 ,
L_4 ,
V_5 , V_6 ) ;
F_2 ( V_3 == V_7 ,
L_5 ,
V_5 , V_7 ) ;
F_2 ( V_3 -> V_4 != V_5 ,
L_6 ,
V_5 , V_3 -> V_4 ) ;
F_2 ( V_4 -> V_3 != V_5 ,
L_7 ,
V_5 , V_4 -> V_3 ) ;
return true ;
}
