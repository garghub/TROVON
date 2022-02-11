static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
void T_1 * V_12 ;
int V_13 ;
V_11 = F_6 ( V_7 , sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_9 = F_7 ( V_5 , V_16 , 0 ) ;
V_12 = F_8 ( V_7 , V_9 ) ;
if ( F_9 ( V_12 ) )
return F_10 ( V_12 ) ;
V_13 = F_11 ( V_11 , V_7 , 4 , V_12 + V_17 ,
V_12 + V_18 , NULL ,
V_12 + V_19 , NULL ,
V_20 ) ;
if ( V_13 ) {
F_12 ( & V_5 -> V_7 , L_1 ) ;
return V_13 ;
}
V_11 -> V_21 . V_22 = L_2 ;
V_11 -> V_21 . V_23 = F_1 ;
V_11 -> V_21 . free = F_3 ;
V_11 -> V_24 = V_11 -> V_25 ( V_11 -> V_26 ) ;
V_11 -> V_21 . V_12 = 0 ;
V_11 -> V_21 . V_27 = 32 ;
V_11 -> V_21 . V_7 = V_7 ;
V_11 -> V_21 . V_28 = V_29 ;
V_13 = F_13 ( & V_11 -> V_21 ) ;
if ( V_13 ) {
F_12 ( V_7 , L_3 ,
V_7 -> V_30 -> V_31 ) ;
return V_13 ;
}
return V_13 ;
}
