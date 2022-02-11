int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , void * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 , V_10 , V_11 = 0 ;
for (; ; ) {
V_9 = V_8 -> V_9 ;
F_3 () ;
V_10 = F_4 ( V_8 -> V_12 , V_3 ,
V_8 -> V_13 , V_9 ,
V_8 -> V_14 , V_4 ,
V_5 , V_6 ) ;
if ( V_10 == V_15 )
return 0 ;
if ( F_5 ( V_10 ) || ++ V_11 >= 3 ) {
F_6 ( & V_2 -> V_8 , L_1 ,
F_7 ( V_10 ) ) ;
return - V_16 ;
}
F_8 ( V_17 ) ;
}
}
