static void F_1 ( int V_1 , T_1 * V_2 , T_1 * V_3 )
{
* V_2 = 0x20 + V_1 / V_4 ;
* V_3 = V_1 % V_4 ;
}
static int F_2 ( struct V_5 * V_6 , unsigned V_1 )
{
T_1 V_2 , V_3 ;
T_2 V_7 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
V_7 = F_4 ( V_9 -> V_10 , V_2 ) ;
return ( V_7 >= 0 ) ? ( V_7 >> V_3 ) & 0x1 : 0 ;
}
static int F_5 ( struct V_8 * V_9 , unsigned V_1 , int V_11 )
{
T_1 V_2 , V_3 ;
T_2 V_7 ;
F_1 ( V_1 , & V_2 , & V_3 ) ;
V_7 = F_4 ( V_9 -> V_10 , V_2 ) ;
if ( V_7 >= 0 ) {
if ( V_11 )
V_7 |= 1 << V_3 ;
else
V_7 &= ~ ( 1 << V_3 ) ;
return F_6 ( V_9 -> V_10 , V_2 , V_7 ) ;
} else
return V_7 ;
}
static void F_7 ( struct V_5 * V_6 , unsigned V_1 , int V_11 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_5 ( V_9 , V_1 , V_11 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned V_1 , int V_11 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
return F_5 ( V_9 , V_1 , V_11 ) ;
}
static int F_9 ( struct V_12 * V_10 ,
const struct V_13 * V_14 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( & V_10 -> V_15 , sizeof( * V_9 ) , V_16 ) ;
if ( ! V_9 )
return - V_17 ;
V_9 -> V_18 . V_19 = V_10 -> V_20 ;
V_9 -> V_18 . V_21 = - 1 ;
V_9 -> V_18 . V_22 = & V_10 -> V_15 ;
V_9 -> V_18 . V_23 = V_24 ;
V_9 -> V_18 . V_25 = V_26 ;
V_9 -> V_18 . V_27 = true ;
V_9 -> V_18 . V_28 = F_2 ;
V_9 -> V_18 . V_29 = F_7 ;
V_9 -> V_18 . V_30 = F_8 ;
V_9 -> V_10 = V_10 ;
F_11 ( V_10 , V_9 ) ;
return F_12 ( & V_9 -> V_18 , V_9 ) ;
}
static int F_13 ( struct V_12 * V_10 )
{
struct V_8 * V_9 ;
V_9 = F_14 ( V_10 ) ;
F_15 ( & V_9 -> V_18 ) ;
return 0 ;
}
