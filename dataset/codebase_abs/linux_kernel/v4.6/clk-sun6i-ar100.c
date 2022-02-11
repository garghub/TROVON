static void F_1 ( struct V_1 * V_2 )
{
unsigned long div ;
int V_3 ;
if ( V_2 -> V_4 > V_2 -> V_5 )
V_2 -> V_4 = V_2 -> V_5 ;
div = F_2 ( V_2 -> V_5 , V_2 -> V_4 ) ;
if ( div < 32 )
V_3 = 0 ;
else if ( div >> 1 < 32 )
V_3 = 1 ;
else if ( div >> 2 < 32 )
V_3 = 2 ;
else
V_3 = 3 ;
div >>= V_3 ;
if ( div > 32 )
div = 32 ;
V_2 -> V_4 = ( V_2 -> V_5 >> V_3 ) / div ;
V_2 -> V_6 = div - 1 ;
V_2 -> V_7 = V_3 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
struct V_14 * V_15 ;
void T_1 * V_16 ;
struct V_17 * V_17 ;
V_15 = F_4 ( V_9 , V_18 , 0 ) ;
V_16 = F_5 ( & V_9 -> V_12 , V_15 ) ;
if ( F_6 ( V_16 ) )
return F_7 ( V_16 ) ;
V_17 = F_8 ( V_11 , & V_19 , & V_20 ,
V_16 ) ;
if ( ! V_17 )
return - V_21 ;
F_9 ( V_9 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_12 . V_13 ;
struct V_17 * V_17 = F_11 ( V_9 ) ;
F_12 ( V_11 , V_17 ) ;
return 0 ;
}
