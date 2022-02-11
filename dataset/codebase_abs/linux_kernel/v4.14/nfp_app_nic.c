static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int V_7 )
{
int V_8 ;
if ( ! V_2 -> V_9 )
return 0 ;
V_6 -> V_10 = F_2 ( V_4 , V_11 , V_6 -> V_12 . V_13 ) ;
if ( F_3 ( V_6 -> V_10 ) )
return F_4 ( V_6 -> V_10 ) ;
V_8 = F_5 ( V_2 , V_4 , V_6 -> V_10 , V_7 ) ;
if ( V_8 ) {
F_6 ( V_6 -> V_10 ) ;
return V_8 ;
}
return V_6 -> V_10 -> type == V_14 ;
}
int F_7 ( struct V_3 * V_4 , struct V_5 * V_6 ,
unsigned int V_7 )
{
int V_8 ;
V_8 = F_1 ( V_4 -> V_2 , V_4 , V_6 , V_7 ) ;
if ( V_8 )
return V_8 < 0 ? V_8 : 0 ;
F_8 ( V_4 -> V_2 , V_6 -> V_10 ) ;
return 0 ;
}
