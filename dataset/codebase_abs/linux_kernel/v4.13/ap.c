int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 ;
F_2 ( V_7 ) ;
if ( ! V_2 -> V_10 -> V_11 )
return - V_12 ;
if ( V_4 -> V_8 -> V_13 != V_14 &&
V_4 -> V_8 -> V_13 != V_15 )
return - V_12 ;
if ( ! V_7 -> V_16 )
return - V_17 ;
V_9 = F_3 ( V_2 , V_4 ) ;
if ( ! V_9 ) {
V_7 -> V_16 = 0 ;
memset ( & V_7 -> V_18 , 0 , sizeof( V_7 -> V_18 ) ) ;
V_7 -> V_19 = 0 ;
F_4 ( V_2 , V_4 , NULL ) ;
if ( V_5 )
F_5 ( V_7 ) ;
F_6 ( V_2 ) ;
}
return V_9 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 ;
int V_9 ;
F_8 ( V_7 ) ;
V_9 = F_1 ( V_2 , V_4 , V_5 ) ;
F_9 ( V_7 ) ;
return V_9 ;
}
