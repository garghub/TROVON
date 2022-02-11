static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_4 ( V_6 , struct V_1 , V_6 ) ;
F_1 ( V_2 , V_2 -> V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 , unsigned int type ,
unsigned int V_10 , int V_11 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( type != V_12 || V_10 != V_13 )
return - V_14 ;
if ( V_11 < 0 )
return - V_15 ;
V_2 -> V_7 = V_11 ;
F_7 ( & V_2 -> V_6 ) ;
return 0 ;
}
static void F_8 ( struct V_8 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_9 ( & V_2 -> V_6 ) ;
F_1 ( V_2 , false ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_8 * V_16 ;
int V_19 ;
V_2 = F_11 ( & V_18 -> V_9 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_4 = F_12 ( & V_18 -> V_9 , NULL ) ;
if ( F_13 ( V_2 -> V_4 ) )
return F_14 ( V_2 -> V_4 ) ;
V_16 = F_15 ( & V_18 -> V_9 ) ;
if ( ! V_16 )
return - V_21 ;
F_16 ( & V_2 -> V_6 , F_3 ) ;
V_16 -> V_22 = V_18 -> V_22 ;
V_16 -> V_23 . V_24 = V_25 ;
V_16 -> V_23 . V_26 = 0x0001 ;
V_16 -> V_23 . V_27 = 0x0001 ;
V_16 -> V_23 . V_28 = 0x0100 ;
V_16 -> V_29 = F_8 ;
V_16 -> V_30 = F_5 ;
F_17 ( V_16 , V_12 , V_13 ) ;
V_19 = F_18 ( V_2 -> V_4 , 0 ) ;
if ( V_19 )
return V_19 ;
F_19 ( V_16 , V_2 ) ;
return F_20 ( V_16 ) ;
}
