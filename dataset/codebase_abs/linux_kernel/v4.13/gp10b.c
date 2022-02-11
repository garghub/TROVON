static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , 0x1200a8 , 0x0 ) ;
F_2 ( V_4 , 0x12004c , 0x4 ) ;
F_2 ( V_4 , 0x122204 , 0x2 ) ;
F_3 ( V_4 , 0x122204 ) ;
F_2 ( V_4 , 0x009080 , 0x800186a0 ) ;
return 0 ;
}
int
F_4 ( struct V_3 * V_4 , int V_5 ,
struct V_1 * * V_6 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_6 = F_5 ( sizeof( * V_2 ) , V_7 ) ) )
return - V_8 ;
F_6 ( & V_9 , V_4 , V_5 , V_2 ) ;
return 0 ;
}
