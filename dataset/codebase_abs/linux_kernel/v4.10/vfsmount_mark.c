void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 ) ;
}
void F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
F_5 ( & V_5 -> V_8 -> V_9 ) ;
V_7 -> V_10 = F_6 ( & V_7 -> V_11 ) ;
F_7 ( & V_5 -> V_8 -> V_9 ) ;
}
void F_8 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = V_13 -> V_5 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
F_9 ( ! F_10 ( & V_13 -> V_2 -> V_14 ) ) ;
F_11 ( & V_13 -> V_15 ) ;
F_5 ( & V_5 -> V_8 -> V_9 ) ;
F_12 ( & V_13 -> V_16 ) ;
V_13 -> V_5 = NULL ;
V_7 -> V_10 = F_6 ( & V_7 -> V_11 ) ;
F_7 ( & V_5 -> V_8 -> V_9 ) ;
}
struct V_12 * F_13 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_12 * V_13 ;
F_5 ( & V_5 -> V_8 -> V_9 ) ;
V_13 = F_14 ( & V_7 -> V_11 , V_2 ) ;
F_7 ( & V_5 -> V_8 -> V_9 ) ;
return V_13 ;
}
int F_15 ( struct V_12 * V_13 ,
struct V_1 * V_2 , struct V_4 * V_5 ,
int V_17 )
{
struct V_6 * V_7 = F_4 ( V_5 ) ;
int V_18 ;
V_13 -> V_19 |= V_3 ;
F_9 ( ! F_10 ( & V_2 -> V_14 ) ) ;
F_11 ( & V_13 -> V_15 ) ;
F_5 ( & V_5 -> V_8 -> V_9 ) ;
V_13 -> V_5 = V_5 ;
V_18 = F_16 ( & V_7 -> V_11 , V_13 , V_17 ) ;
V_7 -> V_10 = F_6 ( & V_7 -> V_11 ) ;
F_7 ( & V_5 -> V_8 -> V_9 ) ;
return V_18 ;
}
