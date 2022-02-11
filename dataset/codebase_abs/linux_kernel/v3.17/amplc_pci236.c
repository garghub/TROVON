static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( V_3 ? V_7 : V_8 ,
V_5 -> V_9 + V_10 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! ( F_4 ( V_5 -> V_9 + V_10 ) &
V_11 ) )
return false ;
F_1 ( V_2 , V_5 -> V_12 ) ;
return true ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_14 * V_14 = F_6 ( V_2 ) ;
struct V_4 * V_5 ;
unsigned long V_15 ;
int V_16 ;
F_7 ( V_2 -> V_17 , L_1 ,
F_8 ( V_14 ) ) ;
V_5 = F_9 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_18 ;
V_2 -> V_19 = & V_20 ;
V_2 -> V_21 = V_20 . V_22 ;
V_16 = F_10 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_5 -> V_9 = F_11 ( V_14 , 1 ) ;
V_15 = F_11 ( V_14 , 2 ) ;
return F_12 ( V_2 , V_15 , V_14 -> V_23 ,
V_24 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
F_14 ( V_2 -> V_23 , V_2 ) ;
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_14 * V_2 ,
const struct V_25 * V_26 )
{
return F_17 ( V_2 , & V_27 ,
V_26 -> V_28 ) ;
}
