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
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 -> V_8 -> V_9 , V_10 ,
F_6 ( 4 + V_3 ) , V_5 ? F_6 ( 4 + V_3 ) : 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_11 , V_12 ;
V_11 = F_8 ( V_7 -> V_8 -> V_9 , V_10 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_12 & F_6 ( 4 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 ,
int V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 -> V_8 -> V_9 , V_10 ,
F_6 ( 4 + V_3 ) , V_5 ? F_6 ( 4 + V_3 ) : 0 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
struct V_6 * V_7 ;
int V_11 ;
V_7 = F_11 ( & V_14 -> V_15 , sizeof( * V_7 ) , V_16 ) ;
if ( ! V_7 )
return - V_17 ;
F_12 ( V_14 , V_7 ) ;
V_7 -> V_8 = F_13 ( V_14 -> V_15 . V_18 ) ;
V_7 -> V_2 = V_19 ;
V_7 -> V_2 . V_18 = V_7 -> V_8 -> V_15 ;
V_11 = F_14 ( & V_7 -> V_2 , V_7 ) ;
if ( V_11 < 0 ) {
F_15 ( & V_14 -> V_15 , L_1 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_16 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_17 ( V_14 ) ;
F_18 ( & V_7 -> V_2 ) ;
return 0 ;
}
