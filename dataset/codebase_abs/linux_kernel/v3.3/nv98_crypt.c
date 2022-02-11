static int
F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
if ( ! ( F_2 ( V_2 , 0x000200 ) & 0x00004000 ) )
return 0 ;
F_3 ( V_2 , 0x000200 , 0x00004000 , 0x00000000 ) ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_3 )
{
F_3 ( V_2 , 0x000200 , 0x00004000 , 0x00000000 ) ;
F_3 ( V_2 , 0x000200 , 0x00004000 , 0x00004000 ) ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_6 = F_6 ( V_2 , V_3 ) ;
F_7 ( V_2 , V_7 ) ;
F_8 ( V_6 ) ;
}
int
F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_6 -> V_10 . V_11 = F_5 ;
V_6 -> V_10 . V_12 = F_4 ;
V_6 -> V_10 . V_13 = F_1 ;
F_11 ( V_2 , V_7 , & V_6 -> V_10 ) ;
return 0 ;
}
