void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 , V_3 , V_2 ) ;
V_2 -> V_5 ++ ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
void * V_6 ;
int V_7 = 0 ;
struct V_8 * V_9 = F_4 ( V_2 , struct V_8 , V_10 ) ;
F_5 ( & V_9 -> V_11 . V_12 -> V_13 ) ;
V_6 = F_6 ( & V_2 -> V_4 , V_3 ) ;
if ( V_6 == V_2 )
V_2 -> V_5 -- ;
else {
F_7 ( L_1 , V_3 ) ;
V_7 = - V_14 ;
}
F_8 ( & V_9 -> V_11 . V_12 -> V_13 ) ;
return V_7 ;
}
int F_9 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
V_2 -> V_16 = V_16 ;
V_2 -> V_5 = 0 ;
F_10 ( & V_2 -> V_4 , V_17 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_18 ) ;
V_2 -> V_5 = 0 ;
}
