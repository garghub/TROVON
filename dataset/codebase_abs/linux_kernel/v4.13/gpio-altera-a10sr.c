static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 , V_9 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ! ( V_7 & F_4 ( V_3 - V_10 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 , V_12 ,
F_4 ( V_10 + V_3 ) ,
V_11 ? F_4 ( V_10 + V_3 )
: 0 ) ;
}
static int F_7 ( struct V_1 * V_13 ,
unsigned int V_14 )
{
if ( V_14 >= ( V_15 - V_10 ) )
return 0 ;
return - V_16 ;
}
static int F_8 ( struct V_1 * V_13 ,
unsigned int V_14 , int V_11 )
{
if ( V_14 <= ( V_17 - V_10 ) )
return 0 ;
return - V_16 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
int V_6 ;
struct V_20 * V_21 = F_10 ( V_19 -> V_22 . V_23 ) ;
V_5 = F_11 ( & V_19 -> V_22 , sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
V_5 -> V_8 = V_21 -> V_8 ;
V_5 -> V_26 = V_27 ;
V_5 -> V_26 . V_23 = V_19 -> V_22 . V_23 ;
V_5 -> V_26 . V_28 = V_19 -> V_22 . V_28 ;
V_6 = F_12 ( & V_19 -> V_22 , & V_5 -> V_26 , V_5 ) ;
if ( V_6 < 0 ) {
F_13 ( & V_19 -> V_22 , L_1 , V_6 ) ;
return V_6 ;
}
F_14 ( V_19 , V_5 ) ;
return 0 ;
}
