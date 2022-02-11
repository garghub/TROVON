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
static void F_4 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
F_6 ( & V_7 -> V_8 ) ;
if ( V_5 )
V_7 -> V_9 |= F_7 ( V_3 ) ;
else
V_7 -> V_9 &= ~ F_7 ( V_3 ) ;
F_8 ( V_7 -> V_10 , V_11 ,
V_7 -> V_9 ) ;
F_9 ( & V_7 -> V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned long * V_12 ,
unsigned long * V_13 )
{
struct V_6 * V_7 = F_5 ( V_2 ) ;
F_6 ( & V_7 -> V_8 ) ;
V_7 -> V_9 &= ~ ( * V_12 ) ;
V_7 -> V_9 |= ( ( * V_12 ) & ( * V_13 ) ) ;
F_8 ( V_7 -> V_10 , V_11 ,
V_7 -> V_9 ) ;
F_9 ( & V_7 -> V_8 ) ;
}
static int F_11 ( struct V_14 * V_10 ,
const struct V_15 * V_16 )
{
struct V_6 * V_7 ;
int V_17 ;
V_7 = F_12 ( & V_10 -> V_18 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
F_13 ( V_10 , V_7 ) ;
V_7 -> V_2 = V_21 ;
V_7 -> V_2 . V_22 = & V_10 -> V_18 ;
V_7 -> V_10 = V_10 ;
F_14 ( & V_7 -> V_8 ) ;
V_17 = F_15 ( & V_7 -> V_2 , V_7 ) ;
if ( V_17 < 0 ) {
F_16 ( & V_10 -> V_18 , L_1 ) ;
return V_17 ;
}
return 0 ;
}
static int F_17 ( struct V_14 * V_10 )
{
struct V_6 * V_7 = F_18 ( V_10 ) ;
F_19 ( & V_7 -> V_2 ) ;
return 0 ;
}
