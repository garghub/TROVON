struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_6 = V_3 -> V_7 >> V_8 ;
if ( F_3 ( ! V_5 -> V_9 ) )
return NULL ;
return F_4 ( V_5 -> V_9 , V_6 ) ;
}
void * F_5 ( struct V_2 * V_3 )
{
return F_6 ( V_3 ) ;
}
void F_7 ( struct V_2 * V_3 , void * V_10 )
{
}
int F_8 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
int V_13 ;
V_13 = F_9 ( V_3 , V_3 -> V_7 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
return F_10 ( V_12 -> V_14 , V_12 ) ;
}
struct V_2 * F_11 ( struct V_15 * V_16 ,
struct V_17 * V_18 , struct V_1 * V_19 )
{
return F_12 ( V_16 , V_18 -> V_20 -> V_7 , V_19 ) ;
}
int F_13 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_21 )
F_14 ( V_3 ) ;
return 0 ;
}
void F_15 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_21 )
F_16 ( V_3 ) ;
}
