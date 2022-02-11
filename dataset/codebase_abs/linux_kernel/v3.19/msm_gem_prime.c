struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( ! V_5 -> V_6 ) ;
return V_5 -> V_6 ;
}
void * F_4 ( struct V_2 * V_3 )
{
return F_5 ( V_3 ) ;
}
void F_6 ( struct V_2 * V_3 , void * V_7 )
{
}
int F_7 ( struct V_2 * V_3 , struct V_8 * V_9 )
{
int V_10 ;
F_8 ( & V_3 -> V_11 -> V_12 ) ;
V_10 = F_9 ( V_3 , V_3 -> V_13 , V_9 ) ;
F_10 ( & V_3 -> V_11 -> V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_11 ( V_9 -> V_14 , V_9 ) ;
}
struct V_2 * F_12 ( struct V_15 * V_11 ,
struct V_16 * V_17 , struct V_1 * V_18 )
{
return F_13 ( V_11 , V_17 -> V_19 -> V_13 , V_18 ) ;
}
int F_14 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_20 )
F_15 ( V_3 ) ;
return 0 ;
}
void F_16 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_20 )
F_17 ( V_3 ) ;
}
