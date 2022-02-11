int
F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * * V_5 )
{
struct V_4 * V_6 ;
if ( ! ( V_6 = * V_5 = F_2 ( sizeof( * V_6 ) , V_7 ) ) )
return - V_8 ;
F_3 ( & V_9 , V_2 , V_3 , 0 , V_6 ) ;
return 0 ;
}
