int F_1 ( struct V_1 * V_2 , T_1 V_3 , const char * V_4 ,
struct V_5 * * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_5 * V_9 ;
T_2 V_10 ;
void * V_11 ;
V_9 = F_3 ( V_8 , sizeof( * V_9 ) , V_12 ) ;
if ( ! V_9 ) {
V_2 -> V_13 ++ ;
return - V_14 ;
}
V_11 = F_4 ( V_8 , V_3 , & V_10 , V_12 | V_15 ,
V_16 ) ;
if ( ! V_11 ) {
F_5 ( V_8 , L_1 ,
V_2 -> V_4 , V_17 , V_4 , V_3 ) ;
V_2 -> V_13 ++ ;
F_6 ( V_8 , V_9 ) ;
return - V_14 ;
}
V_9 -> V_3 = V_3 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_18 = V_11 ;
V_9 -> V_4 = V_4 ;
F_7 ( V_8 ,
L_2 ,
V_2 -> V_4 , V_3 , V_9 -> V_18 , & V_9 -> V_10 , V_9 -> V_4 ) ;
* V_6 = V_9 ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_7 ( V_8 ,
L_3 ,
V_2 -> V_4 , V_6 -> V_3 , V_6 -> V_18 , & V_6 -> V_10 , V_6 -> V_4 ) ;
F_9 ( V_8 , V_6 -> V_3 , V_6 -> V_18 , V_6 -> V_10 ,
V_16 ) ;
F_6 ( V_8 , V_6 ) ;
}
