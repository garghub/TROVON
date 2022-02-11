int F_1 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 [ F_2 ( V_7 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_9 ) ] = { 0 } ;
void * V_10 ;
F_3 ( V_9 , V_8 , V_11 , V_12 ) ;
F_3 ( V_9 , V_8 , V_5 , V_5 ) ;
V_10 = F_4 ( V_9 , V_8 , V_13 ) ;
memcpy ( V_10 , V_4 , sizeof( * V_4 ) ) ;
return F_5 ( V_2 , V_8 , sizeof( V_8 ) , V_6 , sizeof( V_6 ) ) ;
}
int F_6 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
T_1 V_6 [ F_2 ( V_14 ) ] = { 0 } ;
T_1 V_8 [ F_2 ( V_15 ) ] = { 0 } ;
void * V_10 ;
F_3 ( V_15 , V_8 , V_11 , V_16 ) ;
F_3 ( V_15 , V_8 , V_5 , V_5 ) ;
V_10 = F_4 ( V_15 , V_8 , V_13 ) ;
memcpy ( V_10 , V_4 , sizeof( * V_4 ) ) ;
return F_5 ( V_2 , V_8 , sizeof( V_8 ) , V_6 , sizeof( V_6 ) ) ;
}
