static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_2 ( V_7 , V_5 -> V_11 , 0x00000001 , V_3 ? 0x00000001 : 0 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_2 ( V_7 , V_5 -> V_11 , 0x00000002 , V_3 ? 0x00000002 : 0 ) ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_11 ) & 0x00000010 ) ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_11 ) & 0x00000020 ) ;
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_8 ( V_7 , V_5 -> V_11 , 0x00000007 ) ;
}
int
F_9 ( struct V_12 * V_8 , int V_13 , T_1 V_14 ,
struct V_1 * * V_15 )
{
struct V_4 * V_5 ;
if ( ! ( V_5 = F_10 ( sizeof( * V_5 ) , V_16 ) ) )
return - V_17 ;
* V_15 = & V_5 -> V_2 ;
F_11 ( & V_18 , V_8 , V_13 , & V_5 -> V_2 ) ;
V_5 -> V_11 = 0x00d014 + ( V_14 * 0x20 ) ;
return 0 ;
}
