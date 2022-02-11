static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , 0x122310 , 0x0003ffff , 0x00000800 ) ;
F_2 ( V_4 , 0x122348 , 0x0003ffff , 0x00000100 ) ;
F_2 ( V_4 , 0x1223b0 , 0x0003ffff , 0x00000fff ) ;
return 0 ;
}
int
F_3 ( struct V_3 * V_4 , int V_5 ,
struct V_1 * * V_6 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_6 = F_4 ( sizeof( * V_2 ) , V_7 ) ) )
return - V_8 ;
F_5 ( & V_9 , V_4 , V_5 , V_2 ) ;
return 0 ;
}
