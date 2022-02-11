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
int V_16 = 0 ;
struct V_1 * V_10 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_17 ) ;
if ( ! V_10 )
return - V_18 ;
V_10 -> V_4 . V_19 = V_11 -> V_20 ;
V_10 -> V_4 . V_21 = - 1 ;
V_10 -> V_4 . V_22 = & V_11 -> V_22 ;
V_10 -> V_4 . V_23 = V_24 ;
V_10 -> V_4 . V_25 = V_26 ;
V_10 -> V_4 . V_27 = 1 ;
V_10 -> V_4 . V_28 = F_4 ;
V_10 -> V_4 . V_29 = F_8 ;
V_10 -> V_4 . V_30 = F_9 ;
V_10 -> V_11 = V_11 ;
F_12 ( V_11 , V_10 ) ;
V_16 = F_13 ( & V_10 -> V_4 ) ;
if ( V_16 )
goto error;
return 0 ;
error:
F_14 ( V_10 ) ;
return V_16 ;
}
static int F_15 ( struct V_13 * V_11 )
{
struct V_1 * V_10 ;
int V_16 ;
V_10 = F_16 ( V_11 ) ;
V_16 = F_17 ( & V_10 -> V_4 ) ;
if ( ! V_16 )
F_14 ( V_10 ) ;
return V_16 ;
}
