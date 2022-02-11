static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_2 ( V_7 , V_5 -> V_11 , 0x2f , V_3 ? 0x21 : 0x01 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_2 ( V_7 , V_5 -> V_11 , 0x1f , V_3 ? 0x11 : 0x01 ) ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_11 ) & 0x00040000 ) ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_11 ) & 0x00080000 ) ;
}
int
F_7 ( struct V_12 * V_8 , int V_13 , T_1 V_14 ,
struct V_1 * * V_15 )
{
struct V_4 * V_5 ;
if ( ! ( V_5 = F_8 ( sizeof( * V_5 ) , V_16 ) ) )
return - V_17 ;
* V_15 = & V_5 -> V_2 ;
F_9 ( & V_18 , V_8 , V_13 , & V_5 -> V_2 ) ;
V_5 -> V_11 = 0x600800 + V_14 ;
return 0 ;
}
