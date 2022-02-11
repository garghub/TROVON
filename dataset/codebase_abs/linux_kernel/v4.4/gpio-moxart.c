static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
void T_1 * V_9 ;
int V_10 ;
V_8 = F_2 ( V_4 , sizeof( * V_8 ) , V_11 ) ;
if ( ! V_8 )
return - V_12 ;
V_6 = F_3 ( V_2 , V_13 , 0 ) ;
V_9 = F_4 ( V_4 , V_6 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
V_10 = F_7 ( V_8 , V_4 , 4 , V_9 + V_14 ,
V_9 + V_15 , NULL ,
V_9 + V_16 , NULL ,
V_17 ) ;
if ( V_10 ) {
F_8 ( & V_2 -> V_4 , L_1 ) ;
return V_10 ;
}
V_8 -> V_18 . V_19 = L_2 ;
V_8 -> V_18 . V_20 = V_21 ;
V_8 -> V_18 . free = V_22 ;
V_8 -> V_23 = V_8 -> V_24 ( V_8 -> V_25 ) ;
V_8 -> V_18 . V_9 = 0 ;
V_8 -> V_18 . V_26 = 32 ;
V_8 -> V_18 . V_4 = V_4 ;
V_8 -> V_18 . V_27 = V_28 ;
V_10 = F_9 ( & V_8 -> V_18 ) ;
if ( V_10 ) {
F_8 ( V_4 , L_3 ,
V_4 -> V_29 -> V_30 ) ;
return V_10 ;
}
return V_10 ;
}
