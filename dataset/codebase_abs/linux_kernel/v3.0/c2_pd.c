int F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * V_5 )
{
T_1 V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 . V_9 ) ;
V_6 = F_3 ( V_2 -> V_8 . V_10 , V_2 -> V_8 . V_11 ,
V_2 -> V_8 . V_12 ) ;
if ( V_6 >= V_2 -> V_8 . V_11 )
V_6 = F_4 ( V_2 -> V_8 . V_10 ,
V_2 -> V_8 . V_11 ) ;
if ( V_6 < V_2 -> V_8 . V_11 ) {
V_5 -> V_13 = V_6 ;
F_5 ( V_6 , V_2 -> V_8 . V_10 ) ;
V_2 -> V_8 . V_12 = V_6 + 1 ;
if ( V_2 -> V_8 . V_12 >= V_2 -> V_8 . V_11 )
V_2 -> V_8 . V_12 = 0 ;
} else
V_7 = - V_14 ;
F_6 ( & V_2 -> V_8 . V_9 ) ;
return V_7 ;
}
void F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_2 ( & V_2 -> V_8 . V_9 ) ;
F_8 ( V_5 -> V_13 , V_2 -> V_8 . V_10 ) ;
F_6 ( & V_2 -> V_8 . V_9 ) ;
}
int T_2 F_9 ( struct V_1 * V_2 )
{
V_2 -> V_8 . V_12 = 0 ;
V_2 -> V_8 . V_11 = V_2 -> V_15 . V_16 ;
F_10 ( & V_2 -> V_8 . V_9 ) ;
V_2 -> V_8 . V_10 = F_11 ( F_12 ( V_2 -> V_15 . V_16 ) *
sizeof( long ) , V_17 ) ;
if ( ! V_2 -> V_8 . V_10 )
return - V_14 ;
F_13 ( V_2 -> V_8 . V_10 , V_2 -> V_15 . V_16 ) ;
return 0 ;
}
void T_3 F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_8 . V_10 ) ;
}
