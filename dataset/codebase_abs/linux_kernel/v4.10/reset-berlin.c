static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 >> 8 ;
int V_7 = F_3 ( V_3 & 0x1f ) ;
F_4 ( V_5 -> V_8 , V_6 , V_7 ) ;
F_5 ( 10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
unsigned V_6 , V_11 ;
V_6 = V_10 -> args [ 0 ] ;
V_11 = V_10 -> args [ 1 ] ;
if ( V_11 >= V_12 )
return - V_13 ;
return ( V_6 << 8 ) | V_11 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_8 ( V_15 -> V_18 . V_19 ) ;
struct V_4 * V_5 ;
V_5 = F_9 ( & V_15 -> V_18 , sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
V_5 -> V_8 = F_10 ( V_17 ) ;
F_11 ( V_17 ) ;
if ( F_12 ( V_5 -> V_8 ) )
return F_13 ( V_5 -> V_8 ) ;
V_5 -> V_2 . V_22 = V_23 ;
V_5 -> V_2 . V_24 = & V_25 ;
V_5 -> V_2 . V_19 = V_15 -> V_18 . V_19 ;
V_5 -> V_2 . V_26 = 2 ;
V_5 -> V_2 . V_27 = F_6 ;
return F_14 ( & V_5 -> V_2 ) ;
}
