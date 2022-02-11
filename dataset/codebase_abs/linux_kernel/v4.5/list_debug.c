void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_1 * V_4 )
{
F_2 ( V_4 -> V_3 != V_3 ,
L_1
L_2 ,
V_3 , V_4 -> V_3 , V_4 ) ;
F_2 ( V_3 -> V_4 != V_4 ,
L_3
L_4 ,
V_4 , V_3 -> V_4 , V_3 ) ;
F_2 ( V_2 == V_3 || V_2 == V_4 ,
L_5 ,
V_2 , V_3 , V_4 ) ;
V_4 -> V_3 = V_2 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = V_3 ;
F_3 ( V_3 -> V_4 , V_2 ) ;
}
void F_4 ( struct V_1 * V_5 )
{
struct V_1 * V_3 , * V_4 ;
V_3 = V_5 -> V_3 ;
V_4 = V_5 -> V_4 ;
if ( F_2 ( V_4 == V_6 ,
L_6 ,
V_5 , V_6 ) ||
F_2 ( V_3 == V_7 ,
L_7 ,
V_5 , V_7 ) ||
F_2 ( V_3 -> V_4 != V_5 ,
L_8
L_9 , V_5 , V_3 -> V_4 ) ||
F_2 ( V_4 -> V_3 != V_5 ,
L_10
L_9 , V_5 , V_4 -> V_3 ) )
return;
F_5 ( V_3 , V_4 ) ;
}
void F_6 ( struct V_1 * V_5 )
{
F_4 ( V_5 ) ;
V_5 -> V_4 = V_6 ;
V_5 -> V_3 = V_7 ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_1 * V_3 , struct V_1 * V_4 )
{
F_2 ( V_4 -> V_3 != V_3 ,
L_11 ,
V_3 , V_4 -> V_3 , V_4 ) ;
F_2 ( V_3 -> V_4 != V_4 ,
L_12 ,
V_4 , V_3 -> V_4 , V_3 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_3 = V_3 ;
F_8 ( F_9 ( V_3 ) , V_2 ) ;
V_4 -> V_3 = V_2 ;
}
