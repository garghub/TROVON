static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
T_1 V_11 = F_2 ( V_7 , 0 , V_5 -> V_12 ) ;
if ( V_3 ) V_11 |= 0x20 ;
else V_11 &= 0xdf ;
F_3 ( V_7 , 0 , V_5 -> V_12 , V_11 | 0x01 ) ;
}
static void
F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
T_1 V_11 = F_2 ( V_7 , 0 , V_5 -> V_12 ) ;
if ( V_3 ) V_11 |= 0x10 ;
else V_11 &= 0xef ;
F_3 ( V_7 , 0 , V_5 -> V_12 , V_11 | 0x01 ) ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_2 ( V_7 , 0 , V_5 -> V_13 ) & 0x04 ) ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_2 ( V_7 , 0 , V_5 -> V_13 ) & 0x08 ) ;
}
int
F_7 ( struct V_14 * V_8 , int V_15 , T_1 V_12 , T_1 V_13 ,
struct V_1 * * V_16 )
{
struct V_4 * V_5 ;
if ( ! ( V_5 = F_8 ( sizeof( * V_5 ) , V_17 ) ) )
return - V_18 ;
* V_16 = & V_5 -> V_2 ;
F_9 ( & V_19 , V_8 , V_15 , & V_5 -> V_2 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_13 = V_13 ;
return 0 ;
}
