int F_1 ( struct V_1 * V_2 )
{
char V_3 [] = L_1 ;
char V_4 [] = L_2 ;
T_1 V_5 = F_2 () ;
T_2 V_6 = V_5 & 0xffffffff ;
T_2 V_7 = V_5 >> 32 ;
F_3 ( V_3 , sizeof( V_3 ) , V_2 -> V_8 , V_2 -> type , V_2 -> V_9 ) ;
F_3 ( V_4 , sizeof( V_4 ) , V_6 , V_7 ) ;
if ( V_2 -> V_8 == V_10 &&
V_2 -> type == V_11 &&
V_2 -> V_9 == V_12 )
return 0 ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 )
{
char V_3 [] = L_1 ;
F_3 ( V_3 , sizeof( V_3 ) , V_2 -> V_8 , V_2 -> type , V_2 -> V_9 ) ;
if ( V_2 -> V_8 == V_13 &&
V_2 -> type == V_11 &&
V_2 -> V_9 == V_14 )
return 0 ;
return 1 ;
}
