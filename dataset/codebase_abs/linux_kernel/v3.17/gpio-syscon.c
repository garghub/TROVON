static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_6 , V_7 = V_5 -> V_8 -> V_9 + V_4 ;
int V_10 ;
V_10 = F_4 ( V_5 -> V_11 ,
( V_7 / V_12 ) * V_13 , & V_6 ) ;
if ( V_10 )
return V_10 ;
return ! ! ( V_6 & F_5 ( V_7 % V_12 ) ) ;
}
static void F_6 ( struct V_2 * V_3 , unsigned V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned int V_7 = V_5 -> V_8 -> V_9 + V_4 ;
F_7 ( V_5 -> V_11 ,
( V_7 / V_12 ) * V_13 ,
F_5 ( V_7 % V_12 ) ,
V_6 ? F_5 ( V_7 % V_12 ) : 0 ) ;
}
static int F_8 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_8 -> V_14 & V_15 ) {
unsigned int V_7 = V_5 -> V_8 -> V_16 + V_4 ;
F_7 ( V_5 -> V_11 ,
( V_7 / V_12 ) * V_13 ,
F_5 ( V_7 % V_12 ) , 0 ) ;
}
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned V_4 , int V_6 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 -> V_8 -> V_14 & V_15 ) {
unsigned int V_7 = V_5 -> V_8 -> V_16 + V_4 ;
F_7 ( V_5 -> V_11 ,
( V_7 / V_12 ) * V_13 ,
F_5 ( V_7 % V_12 ) ,
F_5 ( V_7 % V_12 ) ) ;
}
F_6 ( V_3 , V_4 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
const struct V_21 * V_22 = F_11 ( V_23 , V_20 ) ;
struct V_1 * V_5 ;
V_5 = F_12 ( V_20 , sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_5 -> V_8 = V_22 -> V_8 ;
V_5 -> V_11 =
F_13 ( V_5 -> V_8 -> V_26 ) ;
if ( F_14 ( V_5 -> V_11 ) )
return F_15 ( V_5 -> V_11 ) ;
V_5 -> V_3 . V_20 = V_20 ;
V_5 -> V_3 . V_27 = V_28 ;
V_5 -> V_3 . V_29 = F_16 ( V_20 ) ;
V_5 -> V_3 . V_30 = - 1 ;
V_5 -> V_3 . V_31 = V_5 -> V_8 -> V_32 ;
V_5 -> V_3 . V_33 = F_3 ;
if ( V_5 -> V_8 -> V_14 & V_34 )
V_5 -> V_3 . V_35 = F_8 ;
if ( V_5 -> V_8 -> V_14 & V_36 ) {
V_5 -> V_3 . V_37 = F_6 ;
V_5 -> V_3 . V_38 = F_9 ;
}
F_17 ( V_18 , V_5 ) ;
return F_18 ( & V_5 -> V_3 ) ;
}
static int F_19 ( struct V_17 * V_18 )
{
struct V_1 * V_5 = F_20 ( V_18 ) ;
F_21 ( & V_5 -> V_3 ) ;
return 0 ;
}
