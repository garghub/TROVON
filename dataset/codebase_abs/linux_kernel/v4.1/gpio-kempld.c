static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 , V_3 ) ;
if ( V_5 )
V_6 |= F_3 ( V_4 ) ;
else
V_6 &= ~ F_3 ( V_4 ) ;
F_4 ( V_2 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_6 ;
F_6 ( V_2 ) ;
V_6 = F_2 ( V_2 , V_3 ) ;
F_7 ( V_2 ) ;
return ! ! ( V_6 & F_3 ( V_4 ) ) ;
}
static int F_8 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11
= F_9 ( V_8 , struct V_10 , V_8 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
return F_5 ( V_2 , F_10 ( V_9 ) , V_9 ) ;
}
static void F_11 ( struct V_7 * V_8 , unsigned V_9 , int V_12 )
{
struct V_10 * V_11
= F_9 ( V_8 , struct V_10 , V_8 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_6 ( V_2 ) ;
F_1 ( V_2 , F_10 ( V_9 ) , V_9 , V_12 ) ;
F_7 ( V_2 ) ;
}
static int F_12 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11
= F_9 ( V_8 , struct V_10 , V_8 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_6 ( V_2 ) ;
F_1 ( V_2 , F_13 ( V_9 ) , V_9 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_9 ,
int V_12 )
{
struct V_10 * V_11
= F_9 ( V_8 , struct V_10 , V_8 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_6 ( V_2 ) ;
F_1 ( V_2 , F_10 ( V_9 ) , V_9 , V_12 ) ;
F_1 ( V_2 , F_13 ( V_9 ) , V_9 , 1 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11
= F_9 ( V_8 , struct V_10 , V_8 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
return ! F_5 ( V_2 , F_13 ( V_9 ) , V_9 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_13 , V_14 ;
F_6 ( V_2 ) ;
V_14 = F_17 ( V_2 , V_15 ) ;
F_18 ( V_2 , V_15 , 0x0000 ) ;
V_13 = F_17 ( V_2 , V_15 ) ;
F_18 ( V_2 , V_15 , V_14 ) ;
F_7 ( V_2 ) ;
return V_13 ? F_19 ( V_13 ) : 16 ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_1 * V_2 = F_21 ( V_19 -> V_20 ) ;
struct V_21 * V_22 = F_22 ( V_2 -> V_19 ) ;
struct V_10 * V_11 ;
struct V_7 * V_8 ;
int V_23 ;
if ( V_2 -> V_24 . V_25 < 2 ) {
F_23 ( V_19 ,
L_1 ) ;
return - V_26 ;
}
V_11 = F_24 ( V_19 , sizeof( * V_11 ) , V_27 ) ;
if ( ! V_11 )
return - V_28 ;
V_11 -> V_2 = V_2 ;
F_25 ( V_17 , V_11 ) ;
V_8 = & V_11 -> V_8 ;
V_8 -> V_29 = L_2 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_19 = V_19 ;
V_8 -> V_32 = true ;
if ( V_22 && V_22 -> V_33 )
V_8 -> V_34 = V_22 -> V_33 ;
else
V_8 -> V_34 = - 1 ;
V_8 -> V_35 = F_12 ;
V_8 -> V_36 = F_14 ;
V_8 -> V_37 = F_15 ;
V_8 -> V_38 = F_8 ;
V_8 -> V_39 = F_11 ;
V_8 -> V_40 = F_16 ( V_2 ) ;
if ( V_8 -> V_40 == 0 ) {
F_23 ( V_19 , L_3 ) ;
return - V_26 ;
}
V_23 = F_26 ( V_8 ) ;
if ( V_23 ) {
F_23 ( V_19 , L_4 ) ;
return V_23 ;
}
F_27 ( V_19 , L_5 ,
V_8 -> V_40 ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 )
{
struct V_10 * V_11 = F_29 ( V_17 ) ;
F_30 ( & V_11 -> V_8 ) ;
return 0 ;
}
