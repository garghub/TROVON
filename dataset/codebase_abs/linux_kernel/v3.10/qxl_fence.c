int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
F_3 ( & V_5 -> V_7 . V_8 -> V_9 ) ;
F_4 ( & V_2 -> V_10 , V_3 , V_2 ) ;
V_2 -> V_11 ++ ;
F_5 ( & V_5 -> V_7 . V_8 -> V_9 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
void * V_12 ;
int V_13 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
F_3 ( & V_5 -> V_7 . V_8 -> V_9 ) ;
V_12 = F_7 ( & V_2 -> V_10 , V_3 ) ;
if ( V_12 == V_2 )
V_2 -> V_11 -- ;
else {
F_8 ( L_1 , V_3 ) ;
V_13 = - V_14 ;
}
F_5 ( & V_5 -> V_7 . V_8 -> V_9 ) ;
return V_13 ;
}
int F_9 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
V_2 -> V_16 = V_16 ;
V_2 -> V_11 = 0 ;
F_10 ( & V_2 -> V_10 , V_17 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_11 = 0 ;
}
