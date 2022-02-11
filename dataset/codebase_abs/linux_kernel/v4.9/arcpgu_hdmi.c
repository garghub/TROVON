int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
V_6 = F_2 ( V_2 -> V_10 , sizeof( * V_6 ) , V_11 ) ;
if ( V_6 == NULL )
return - V_12 ;
V_8 = F_3 ( V_4 ) ;
if ( ! V_8 )
return - V_13 ;
V_6 -> V_14 = 1 ;
V_6 -> V_15 = 0 ;
V_9 = F_4 ( V_2 , V_6 , & V_16 ,
V_17 , NULL ) ;
if ( V_9 )
return V_9 ;
V_8 -> V_6 = V_6 ;
V_6 -> V_8 = V_8 ;
V_9 = F_5 ( V_2 , V_8 ) ;
if ( V_9 )
F_6 ( V_6 ) ;
return V_9 ;
}
