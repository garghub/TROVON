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
if ( F_7 ( V_10 -> V_12 != V_2 -> V_13 ) )
return - V_14 ;
V_6 = V_10 -> args [ 0 ] ;
V_11 = V_10 -> args [ 1 ] ;
if ( V_11 >= V_15 )
return - V_14 ;
return ( V_6 << 8 ) | V_11 ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_9 ( V_17 -> V_20 . V_21 ) ;
struct V_4 * V_5 ;
V_5 = F_10 ( & V_17 -> V_20 , sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
V_5 -> V_8 = F_11 ( V_19 ) ;
F_12 ( V_19 ) ;
if ( F_13 ( V_5 -> V_8 ) )
return F_14 ( V_5 -> V_8 ) ;
V_5 -> V_2 . V_24 = V_25 ;
V_5 -> V_2 . V_26 = & V_27 ;
V_5 -> V_2 . V_21 = V_17 -> V_20 . V_21 ;
V_5 -> V_2 . V_13 = 2 ;
V_5 -> V_2 . V_28 = F_6 ;
F_15 ( & V_5 -> V_2 ) ;
return 0 ;
}
