static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 , & V_4 -> V_5 ,
& V_4 -> V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_7 * V_8 )
{
int V_9 ;
struct V_3 * V_4 ;
V_4 = F_5 ( & V_8 -> V_10 ,
sizeof( struct V_3 ) , V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_9 = F_6 ( & V_8 -> V_10 ,
& V_13 , & V_14 , 1 ) ;
if ( V_9 )
return V_9 ;
F_7 ( V_8 , V_4 ) ;
return F_8 ( & V_8 -> V_10 , NULL , 0 ) ;
}
