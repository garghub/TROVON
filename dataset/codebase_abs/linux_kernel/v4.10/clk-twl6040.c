static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
return V_4 -> V_6 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
int V_7 ;
V_7 = F_4 ( V_4 -> V_8 , 1 ) ;
if ( ! V_7 )
V_4 -> V_6 = 1 ;
return V_7 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
int V_7 ;
V_7 = F_4 ( V_4 -> V_8 , 0 ) ;
if ( ! V_7 )
V_4 -> V_6 = 0 ;
}
static unsigned long F_6 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 ,
V_5 ) ;
return F_7 ( V_4 -> V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_8 * V_8 = F_9 ( V_11 -> V_12 . V_13 ) ;
struct V_3 * V_14 ;
int V_7 ;
V_14 = F_10 ( & V_11 -> V_12 , sizeof( * V_14 ) , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_14 -> V_12 = & V_11 -> V_12 ;
V_14 -> V_8 = V_8 ;
V_14 -> V_5 . V_17 = & V_18 ;
V_7 = F_11 ( & V_11 -> V_12 , & V_14 -> V_5 ) ;
if ( V_7 )
return V_7 ;
F_12 ( V_11 , V_14 ) ;
return F_13 ( V_11 -> V_12 . V_13 -> V_19 ,
V_20 ,
& V_14 -> V_5 ) ;
}
