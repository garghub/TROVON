static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned V_3 )
{
return - V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_3 , int V_5 )
{
F_4 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = F_6 ( V_2 ) ;
T_1 V_10 ;
int V_11 ;
F_7 ( & V_9 -> V_12 ) ;
V_10 = V_9 -> V_10 & ~ V_6 ;
V_10 |= ( V_6 & V_7 ) ;
V_11 = F_8 ( V_9 -> V_13 , V_14 ,
V_10 ) ;
if ( ! V_11 )
V_9 -> V_10 = V_10 ;
F_9 ( & V_9 -> V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
F_5 ( V_2 , F_10 ( V_3 ) , V_5 ? F_10 ( V_3 ) : 0 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned long * V_6 ,
unsigned long * V_7 )
{
F_5 ( V_2 , * V_6 , * V_7 ) ;
}
static int F_12 ( struct V_15 * V_13 ,
const struct V_16 * V_17 )
{
struct V_8 * V_9 ;
int V_18 ;
V_9 = F_13 ( & V_13 -> V_19 , sizeof( * V_9 ) , V_20 ) ;
if ( ! V_9 )
return - V_21 ;
F_14 ( V_13 , V_9 ) ;
V_9 -> V_2 = V_22 ;
V_9 -> V_2 . V_23 = & V_13 -> V_19 ;
V_9 -> V_13 = V_13 ;
F_15 ( & V_9 -> V_12 ) ;
V_18 = F_16 ( & V_9 -> V_2 , V_9 ) ;
if ( V_18 < 0 ) {
F_17 ( & V_13 -> V_19 , L_1 ) ;
return V_18 ;
}
return 0 ;
}
static int F_18 ( struct V_15 * V_13 )
{
struct V_8 * V_9 = F_19 ( V_13 ) ;
F_20 ( & V_9 -> V_2 ) ;
return 0 ;
}
