static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 -> V_4 , V_3 ^ V_2 -> V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 , struct V_1 , V_7 ) ;
F_1 ( V_2 , V_2 -> V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 , unsigned int type ,
unsigned int V_11 , int V_12 )
{
struct V_1 * V_2 = F_6 ( V_10 ) ;
if ( type != V_13 || V_11 != V_14 )
return - V_15 ;
if ( V_12 < 0 )
return - V_16 ;
V_2 -> V_8 = V_12 ;
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
static void F_8 ( struct V_9 * V_17 )
{
struct V_1 * V_2 = F_6 ( V_17 ) ;
F_9 ( & V_2 -> V_7 ) ;
F_1 ( V_2 , false ) ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
enum V_20 V_21 ;
struct V_9 * V_17 ;
unsigned long V_22 ;
int V_23 ;
V_2 = F_11 ( & V_19 -> V_10 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_2 -> V_4 = F_12 ( V_19 -> V_10 . V_26 , 0 , & V_21 ) ;
if ( ! F_13 ( V_2 -> V_4 ) )
return V_2 -> V_4 ;
V_17 = F_14 ( & V_19 -> V_10 ) ;
if ( ! V_17 )
return - V_25 ;
F_15 ( & V_2 -> V_7 , F_3 ) ;
V_17 -> V_27 = V_19 -> V_27 ;
V_17 -> V_28 . V_29 = V_30 ;
V_17 -> V_28 . V_31 = 0x0001 ;
V_17 -> V_28 . V_32 = 0x0001 ;
V_17 -> V_28 . V_33 = 0x0100 ;
V_17 -> V_34 = F_8 ;
V_17 -> V_35 = F_5 ;
F_16 ( V_17 , V_13 , V_14 ) ;
V_2 -> V_5 = V_21 & V_36 ;
V_22 = V_2 -> V_5 ? V_37 : V_38 ;
V_23 = F_17 ( & V_19 -> V_10 , V_2 -> V_4 , V_22 , V_19 -> V_27 ) ;
if ( V_23 )
return V_23 ;
F_18 ( V_17 , V_2 ) ;
return F_19 ( V_17 ) ;
}
