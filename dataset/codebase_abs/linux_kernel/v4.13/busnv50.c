static void
F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
if ( V_3 ) V_5 -> V_11 |= 0x01 ;
else V_5 -> V_11 &= 0xfe ;
F_2 ( V_7 , V_5 -> V_12 , V_5 -> V_11 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
if ( V_3 ) V_5 -> V_11 |= 0x02 ;
else V_5 -> V_11 &= 0xfd ;
F_2 ( V_7 , V_5 -> V_12 , V_5 -> V_11 ) ;
}
static int
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_12 ) & 0x00000001 ) ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
return ! ! ( F_5 ( V_7 , V_5 -> V_12 ) & 0x00000002 ) ;
}
static void
F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_2 . V_8 -> V_9 -> V_10 . V_7 ;
F_2 ( V_7 , V_5 -> V_12 , ( V_5 -> V_11 = 0x00000007 ) ) ;
}
int
F_8 ( struct V_13 * V_8 , int V_14 , T_1 V_15 ,
struct V_1 * * V_16 )
{
static const T_2 V_12 [] = {
0x00e138 , 0x00e150 , 0x00e168 , 0x00e180 ,
0x00e254 , 0x00e274 , 0x00e764 , 0x00e780 ,
0x00e79c , 0x00e7b8
} ;
struct V_4 * V_5 ;
if ( V_15 >= F_9 ( V_12 ) ) {
F_10 ( & V_8 -> V_9 -> V_10 , L_1 , V_15 ) ;
return - V_17 ;
}
if ( ! ( V_5 = F_11 ( sizeof( * V_5 ) , V_18 ) ) )
return - V_19 ;
* V_16 = & V_5 -> V_2 ;
F_12 ( & V_20 , V_8 , V_14 , & V_5 -> V_2 ) ;
V_5 -> V_12 = V_12 [ V_15 ] ;
V_5 -> V_11 = 0x00000007 ;
return 0 ;
}
