static unsigned int F_1 ( unsigned int V_1 )
{
if ( V_1 < 16 )
return 8 * V_1 ;
else
return 8 * ( V_1 - 16 ) + 0x100 ;
}
static int F_2 ( struct V_2 * V_3 , unsigned V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
F_4 ( V_5 -> V_6 + F_1 ( V_1 ) , 0 ) ;
return 0 ;
}
static void F_5 ( struct V_2 * V_3 , unsigned V_1 , int V_7 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
T_1 V_8 = 1ull << V_1 ;
T_1 V_9 = V_5 -> V_6 + ( V_7 ? V_10 : V_11 ) ;
F_4 ( V_9 , V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned V_1 ,
int V_7 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
union V_12 V_13 ;
F_5 ( V_3 , V_1 , V_7 ) ;
V_13 . T_1 = 0 ;
V_13 . V_14 . V_15 = 1 ;
F_4 ( V_5 -> V_6 + F_1 ( V_1 ) , V_13 . T_1 ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 , unsigned V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
T_1 V_16 = F_8 ( V_5 -> V_6 + V_17 ) ;
return ( ( 1ull << V_1 ) & V_16 ) != 0 ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
struct V_20 * V_21 ;
void T_2 * V_22 ;
int V_23 = 0 ;
V_5 = F_10 ( & V_19 -> V_24 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_3 = & V_5 -> V_3 ;
V_21 = F_11 ( V_19 , V_27 , 0 ) ;
V_22 = F_12 ( & V_19 -> V_24 , V_21 ) ;
if ( F_13 ( V_22 ) )
return F_14 ( V_22 ) ;
V_5 -> V_6 = ( T_1 ) V_22 ;
V_19 -> V_24 . V_28 = V_3 ;
V_3 -> V_29 = L_1 ;
V_3 -> V_30 = & V_19 -> V_24 ;
V_3 -> V_31 = V_32 ;
V_3 -> V_33 = 0 ;
V_3 -> V_34 = false ;
V_3 -> V_35 = 20 ;
V_3 -> V_36 = F_2 ;
V_3 -> V_37 = F_7 ;
V_3 -> V_38 = F_6 ;
V_3 -> V_39 = F_5 ;
V_23 = F_15 ( & V_19 -> V_24 , V_3 , V_5 ) ;
if ( V_23 )
return V_23 ;
F_16 ( & V_19 -> V_24 , L_2 ) ;
return 0 ;
}
