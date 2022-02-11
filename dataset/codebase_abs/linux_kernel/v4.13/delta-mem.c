int F_1 ( struct V_1 * V_2 , T_1 V_3 , const char * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
T_2 V_10 ;
void * V_11 ;
unsigned long V_12 = V_13 ;
V_11 = F_2 ( V_8 -> V_9 , V_3 , & V_10 ,
V_14 | V_15 , V_12 ) ;
if ( ! V_11 ) {
F_3 ( V_8 -> V_9 ,
L_1 ,
V_2 -> V_4 , V_4 , V_3 ) ;
V_2 -> V_16 ++ ;
return - V_17 ;
}
V_6 -> V_3 = V_3 ;
V_6 -> V_18 = V_10 ;
V_6 -> V_19 = V_11 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_12 = V_12 ;
F_4 ( V_8 -> V_9 ,
L_2 ,
V_2 -> V_4 , V_3 , V_6 -> V_19 , & V_6 -> V_18 , V_6 -> V_4 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_4 ( V_8 -> V_9 ,
L_3 ,
V_2 -> V_4 , V_6 -> V_3 , V_6 -> V_19 , & V_6 -> V_18 , V_6 -> V_4 ) ;
F_6 ( V_8 -> V_9 , V_6 -> V_3 ,
V_6 -> V_19 , V_6 -> V_18 , V_6 -> V_12 ) ;
}
