void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_4 ) , F_4 ( * V_6 ) , V_7 ) ;
int V_8 = F_5 ( V_9 - V_6 -> V_10 ) ;
char V_11 [ 80 ] ;
F_6 ( V_11 , sizeof( V_11 ) , V_6 -> V_12 , V_6 -> V_13 ) ;
F_7 ( V_2 , L_1 , V_11 ,
V_6 -> V_14 , V_8 / 1000 , V_8 % 1000 ) ;
}
