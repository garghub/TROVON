static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( 1 ) ;
F_2 ( V_2 -> V_3 , 0 ) ;
F_3 ( 200 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_5 ( V_5 -> V_2 ) ;
F_1 ( V_2 ) ;
}
static int F_6 ( struct V_6 * V_7 ,
unsigned long V_8 , void * V_9 )
{
struct V_1 * V_2 = F_7 ( V_7 ,
struct V_1 , V_10 ) ;
F_1 ( V_2 ) ;
return V_11 ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
V_2 = F_9 ( V_15 , sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
V_2 -> V_3 = F_10 ( V_15 , L_1 , V_18 ) ;
if ( F_11 ( V_2 -> V_3 ) )
return F_12 ( V_2 -> V_3 ) ;
V_2 -> V_10 . V_19 = F_6 ;
V_2 -> V_10 . V_20 = 255 ;
F_13 ( & V_2 -> V_10 ) ;
V_2 -> V_2 . V_21 = & V_22 ;
V_2 -> V_2 . V_15 = V_15 ;
V_2 -> V_2 . V_23 = V_24 ;
F_14 ( V_13 , V_2 ) ;
return F_15 ( & V_2 -> V_2 ) ;
}
static int F_16 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_17 ( V_13 ) ;
F_18 ( & V_2 -> V_10 ) ;
F_19 ( & V_2 -> V_2 ) ;
return 0 ;
}
