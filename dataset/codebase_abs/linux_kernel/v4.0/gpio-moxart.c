static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_6 ( V_2 ) ;
T_1 V_6 = V_5 -> V_7 ( V_5 -> V_8 ) ;
if ( V_6 & F_7 ( V_3 ) )
return ! ! ( V_5 -> V_7 ( V_5 -> V_9 ) & F_7 ( V_3 ) ) ;
else
return ! ! ( V_5 -> V_7 ( V_5 -> V_10 ) & F_7 ( V_3 ) ) ;
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
void T_2 * V_17 ;
int V_6 ;
V_5 = F_9 ( V_14 , sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return - V_19 ;
V_16 = F_10 ( V_12 , V_20 , 0 ) ;
V_17 = F_11 ( V_14 , V_16 ) ;
if ( F_12 ( V_17 ) )
return F_13 ( V_17 ) ;
V_6 = F_14 ( V_5 , V_14 , 4 , V_17 + V_21 ,
V_17 + V_22 , NULL ,
V_17 + V_23 , NULL , 0 ) ;
if ( V_6 ) {
F_15 ( & V_12 -> V_14 , L_1 ) ;
return V_6 ;
}
V_5 -> V_24 . V_25 = L_2 ;
V_5 -> V_24 . V_26 = F_1 ;
V_5 -> V_24 . free = F_3 ;
V_5 -> V_24 . V_27 = F_5 ;
V_5 -> V_28 = V_5 -> V_7 ( V_5 -> V_9 ) ;
V_5 -> V_24 . V_17 = 0 ;
V_5 -> V_24 . V_29 = 32 ;
V_5 -> V_24 . V_14 = V_14 ;
V_5 -> V_24 . V_30 = V_31 ;
V_6 = F_16 ( & V_5 -> V_24 ) ;
if ( V_6 ) {
F_15 ( V_14 , L_3 ,
V_14 -> V_32 -> V_33 ) ;
return V_6 ;
}
return V_6 ;
}
