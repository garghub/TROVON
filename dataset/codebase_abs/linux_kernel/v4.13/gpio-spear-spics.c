static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return - V_4 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned V_3 , int V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
T_1 V_8 ;
V_8 = F_4 ( V_7 -> V_9 + V_7 -> V_10 ) ;
if ( V_7 -> V_11 != V_3 ) {
V_7 -> V_11 = V_3 ;
V_8 &= ~ ( V_7 -> V_12 << V_7 -> V_13 ) ;
V_8 |= V_3 << V_7 -> V_13 ;
}
V_8 &= ~ ( 0x1 << V_7 -> V_14 ) ;
V_8 |= V_5 << V_7 -> V_14 ;
F_5 ( V_8 , V_7 -> V_9 + V_7 -> V_10 ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
return - V_4 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_5 )
{
F_2 ( V_2 , V_3 , V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( ! V_7 -> V_15 ++ ) {
V_8 = F_4 ( V_7 -> V_9 + V_7 -> V_10 ) ;
V_8 |= 0x1 << V_7 -> V_16 ;
V_8 |= 0x1 << V_7 -> V_14 ;
F_5 ( V_8 , V_7 -> V_9 + V_7 -> V_10 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
T_1 V_8 ;
if ( ! -- V_7 -> V_15 ) {
V_8 = F_4 ( V_7 -> V_9 + V_7 -> V_10 ) ;
V_8 &= ~ ( 0x1 << V_7 -> V_16 ) ;
F_5 ( V_8 , V_7 -> V_9 + V_7 -> V_10 ) ;
}
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 . V_22 ;
struct V_6 * V_7 ;
struct V_23 * V_24 ;
int V_25 ;
V_7 = F_11 ( & V_18 -> V_21 , sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
return - V_27 ;
V_24 = F_12 ( V_18 , V_28 , 0 ) ;
V_7 -> V_9 = F_13 ( & V_18 -> V_21 , V_24 ) ;
if ( F_14 ( V_7 -> V_9 ) )
return F_15 ( V_7 -> V_9 ) ;
if ( F_16 ( V_20 , L_1 ,
& V_7 -> V_10 ) )
goto V_29;
if ( F_16 ( V_20 , L_2 ,
& V_7 -> V_16 ) )
goto V_29;
if ( F_16 ( V_20 , L_3 ,
& V_7 -> V_14 ) )
goto V_29;
if ( F_16 ( V_20 , L_4 ,
& V_7 -> V_12 ) )
goto V_29;
if ( F_16 ( V_20 , L_5 ,
& V_7 -> V_13 ) )
goto V_29;
F_17 ( V_18 , V_7 ) ;
V_7 -> V_2 . V_30 = V_31 ;
V_7 -> V_2 . V_9 = - 1 ;
V_7 -> V_2 . V_32 = F_8 ;
V_7 -> V_2 . free = F_9 ;
V_7 -> V_2 . V_33 = F_6 ;
V_7 -> V_2 . V_34 = F_7 ;
V_7 -> V_2 . V_35 = F_1 ;
V_7 -> V_2 . V_36 = F_2 ;
V_7 -> V_2 . V_37 = F_18 ( & V_18 -> V_21 ) ;
V_7 -> V_2 . V_38 = & V_18 -> V_21 ;
V_7 -> V_2 . V_39 = V_40 ;
V_7 -> V_11 = - 1 ;
V_25 = F_19 ( & V_18 -> V_21 , & V_7 -> V_2 , V_7 ) ;
if ( V_25 ) {
F_20 ( & V_18 -> V_21 , L_6 ) ;
return V_25 ;
}
F_21 ( & V_18 -> V_21 , L_7 ) ;
return 0 ;
V_29:
F_20 ( & V_18 -> V_21 , L_8 ) ;
return - V_41 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_42 ) ;
}
