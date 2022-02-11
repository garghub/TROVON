static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
V_2 -> V_5 . V_6 = 1 ;
V_2 -> V_5 . V_3 = V_3 ;
V_4 = V_3 >> 8 ;
V_2 -> V_7 . V_8 = V_2 -> V_7 . V_9 = V_3 ;
F_2 ( L_1 , V_10 , V_4 , V_2 ) ;
return F_3 ( V_2 -> V_11 , & V_2 -> V_11 -> V_12 , V_2 , V_4 ) ;
}
int F_4 ( struct V_13 * V_11 , struct V_14 * V_15 ,
struct V_1 * V_2 , int V_16 )
{
T_1 V_3 ;
int V_17 ;
if ( F_5 ( & V_11 -> V_18 ,
& V_3 , V_2 -> V_5 . V_19 ,
V_2 -> V_5 . V_20 ,
V_2 -> V_5 . V_21 ,
V_2 -> V_5 . V_22 ,
V_2 -> V_5 . V_23 ,
V_16 - 12 ,
V_2 -> V_5 . V_24 , V_2 -> V_5 . V_25 ) )
return - V_26 ;
V_17 = F_1 ( V_2 , V_3 ) ;
if ( V_17 )
F_6 ( & V_11 -> V_18 , V_2 -> V_5 . V_3 , V_2 -> V_5 . V_24 ,
V_2 -> V_5 . V_25 ) ;
return V_17 ;
}
int F_7 ( struct V_1 * V_2 , int V_27 )
{
V_2 -> V_5 . V_25 = F_8 ( & V_2 -> V_11 -> V_18 ,
V_27 << 3 ) ;
if ( ! V_2 -> V_5 . V_25 )
return - V_26 ;
V_2 -> V_5 . V_24 = V_27 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_11 -> V_18 , V_2 -> V_5 . V_25 ,
V_2 -> V_5 . V_24 << 3 ) ;
}
int F_11 ( struct V_1 * V_2 , T_2 * V_28 , int V_27 , int V_29 )
{
return F_12 ( & V_2 -> V_11 -> V_18 , V_28 ,
V_2 -> V_5 . V_25 + ( V_29 << 3 ) , V_27 ) ;
}
