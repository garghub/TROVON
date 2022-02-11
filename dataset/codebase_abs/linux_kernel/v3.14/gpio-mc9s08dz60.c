static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( int V_5 , T_1 * V_6 , T_1 * V_7 )
{
* V_6 = 0x20 + V_5 / V_8 ;
* V_7 = V_5 % V_8 ;
}
static int F_4 ( struct V_2 * V_3 , unsigned V_5 )
{
T_1 V_6 , V_7 ;
T_2 V_9 ;
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_3 ( V_5 , & V_6 , & V_7 ) ;
V_9 = F_5 ( V_10 -> V_11 , V_6 ) ;
return ( V_9 >= 0 ) ? ( V_9 >> V_7 ) & 0x1 : 0 ;
}
static int F_6 ( struct V_1 * V_10 , unsigned V_5 , int V_12 )
{
T_1 V_6 , V_7 ;
T_2 V_9 ;
F_3 ( V_5 , & V_6 , & V_7 ) ;
V_9 = F_5 ( V_10 -> V_11 , V_6 ) ;
if ( V_9 >= 0 ) {
if ( V_12 )
V_9 |= 1 << V_7 ;
else
V_9 &= ~ ( 1 << V_7 ) ;
return F_7 ( V_10 -> V_11 , V_6 , V_9 ) ;
} else
return V_9 ;
}
static void F_8 ( struct V_2 * V_3 , unsigned V_5 , int V_12 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
F_6 ( V_10 , V_5 , V_12 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
unsigned V_5 , int V_12 )
{
struct V_1 * V_10 = F_1 ( V_3 ) ;
return F_6 ( V_10 , V_5 , V_12 ) ;
}
static int F_10 ( struct V_13 * V_11 ,
const struct V_14 * V_15 )
{
struct V_1 * V_10 ;
V_10 = F_11 ( & V_11 -> V_16 , sizeof( * V_10 ) , V_17 ) ;
if ( ! V_10 )
return - V_18 ;
V_10 -> V_4 . V_19 = V_11 -> V_20 ;
V_10 -> V_4 . V_21 = - 1 ;
V_10 -> V_4 . V_16 = & V_11 -> V_16 ;
V_10 -> V_4 . V_22 = V_23 ;
V_10 -> V_4 . V_24 = V_25 ;
V_10 -> V_4 . V_26 = true ;
V_10 -> V_4 . V_27 = F_4 ;
V_10 -> V_4 . V_28 = F_8 ;
V_10 -> V_4 . V_29 = F_9 ;
V_10 -> V_11 = V_11 ;
F_12 ( V_11 , V_10 ) ;
return F_13 ( & V_10 -> V_4 ) ;
}
static int F_14 ( struct V_13 * V_11 )
{
struct V_1 * V_10 ;
V_10 = F_15 ( V_11 ) ;
return F_16 ( & V_10 -> V_4 ) ;
}
