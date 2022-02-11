static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 )
{
T_1 V_7 = ( V_5 + 1 ) * 4 ;
unsigned long V_8 ;
T_1 V_9 ;
F_4 ( & V_4 -> V_10 , V_8 ) ;
V_9 = F_5 ( V_4 -> V_11 ) ;
V_9 &= ~ ( 0xf << V_7 ) ;
V_9 |= V_6 << V_7 ;
F_6 ( V_9 , V_4 -> V_11 ) ;
F_7 ( & V_4 -> V_10 , V_8 ) ;
}
static unsigned int F_8 ( struct V_12 * V_13 , unsigned int V_6 )
{
return F_9 ( V_6 * 0xf , F_10 ( V_13 ) ) ;
}
static int F_11 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_14 = F_12 ( V_4 -> V_15 ) ;
if ( ! V_14 )
return - V_16 ;
F_13 ( V_13 , F_9 ( V_17 , V_14 ) ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_12 * V_13 ,
int V_18 , int V_19 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_20 ;
if ( V_19 != F_10 ( V_13 ) )
return - V_16 ;
V_20 = F_8 ( V_13 , V_18 ) ;
F_3 ( V_4 , V_13 -> V_21 , V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_20 ;
V_20 = F_8 ( V_13 , F_16 ( V_13 ) ) ;
F_3 ( V_4 , V_13 -> V_21 , V_20 ) ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , struct V_12 * V_13 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , V_13 -> V_21 , 0 ) ;
}
static struct V_12 * F_18 ( struct V_2 * V_3 ,
const struct V_22 * args )
{
if ( args -> args [ 0 ] >= V_3 -> V_23 )
return F_19 ( - V_16 ) ;
return F_20 ( V_3 , args -> args [ 0 ] , NULL ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_1 * V_4 ;
struct V_26 * V_27 ;
V_4 = F_22 ( & V_25 -> V_28 , sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_27 = F_23 ( V_25 , V_31 , 0 ) ;
V_4 -> V_11 = F_24 ( & V_25 -> V_28 , V_27 ) ;
if ( F_25 ( V_4 -> V_11 ) )
return F_26 ( V_4 -> V_11 ) ;
V_4 -> V_15 = F_27 ( & V_25 -> V_28 , NULL ) ;
if ( F_25 ( V_4 -> V_15 ) )
return F_26 ( V_4 -> V_15 ) ;
V_4 -> V_3 . V_32 = & V_33 ;
V_4 -> V_3 . V_28 = & V_25 -> V_28 ;
V_4 -> V_3 . V_34 = - 1 ;
V_4 -> V_3 . V_23 = 2 ;
V_4 -> V_3 . V_35 = F_18 ;
V_4 -> V_3 . V_36 = 1 ;
F_28 ( & V_4 -> V_10 ) ;
F_29 ( V_25 , V_4 ) ;
return F_30 ( & V_4 -> V_3 ) ;
}
static int F_31 ( struct V_24 * V_25 )
{
struct V_1 * V_4 = F_32 ( V_25 ) ;
return F_33 ( & V_4 -> V_3 ) ;
}
