static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 , T_1 V_5 ,
T_1 V_6 , T_1 V_7 )
{
void T_2 * V_8 = V_4 -> V_9 + V_5 ;
T_1 V_10 ;
V_10 = F_4 ( V_8 ) ;
V_10 &= ~ V_6 ;
V_10 |= V_7 ;
F_5 ( V_10 , V_8 ) ;
}
static int F_6 ( struct V_2 * V_3 , struct V_11 * V_12 ,
int V_13 , int V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_15 , V_16 , V_17 , V_10 ;
T_3 div , V_18 ;
int V_19 ;
V_18 = F_7 ( V_4 -> V_20 ) ;
V_15 = F_8 ( V_18 * V_14 , V_21 ) >>
V_22 ;
if ( V_15 > V_23 )
return - V_24 ;
div = V_21 * ( V_15 + 1 ) ;
V_16 = F_9 ( V_18 * V_14 , div ) ;
if ( V_16 > 0 )
V_16 -- ;
V_17 = F_9 ( V_18 * V_13 , div ) ;
V_10 = V_16 | ( V_17 << V_25 ) ;
V_19 = F_10 ( V_4 -> V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_10 ( V_4 -> V_26 ) ;
if ( V_19 < 0 ) {
F_11 ( V_4 -> V_20 ) ;
return V_19 ;
}
F_3 ( V_4 , V_27 , V_28 ,
V_15 << V_29 ) ;
F_3 ( V_4 , V_30 ,
V_31 | V_32 , V_10 ) ;
F_3 ( V_4 , V_33 , V_34 , 1 ) ;
F_3 ( V_4 , V_33 , V_34 , 0 ) ;
F_11 ( V_4 -> V_26 ) ;
F_11 ( V_4 -> V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_19 ;
V_19 = F_10 ( V_4 -> V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_10 ( V_4 -> V_26 ) ;
if ( V_19 < 0 ) {
F_11 ( V_4 -> V_20 ) ;
return V_19 ;
}
F_3 ( V_4 , V_35 , V_36 , 1 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 , struct V_11 * V_12 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 , V_35 , V_36 , 0 ) ;
F_11 ( V_4 -> V_26 ) ;
F_11 ( V_4 -> V_20 ) ;
}
static int F_14 ( struct V_37 * V_38 )
{
struct V_1 * V_4 ;
struct V_39 * V_40 ;
int V_41 ;
V_4 = F_15 ( & V_38 -> V_42 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
V_40 = F_16 ( V_38 , V_45 , 0 ) ;
V_4 -> V_9 = F_17 ( & V_38 -> V_42 , V_40 ) ;
if ( F_18 ( V_4 -> V_9 ) )
return F_19 ( V_4 -> V_9 ) ;
V_4 -> V_20 = F_20 ( & V_38 -> V_42 , L_1 ) ;
if ( F_18 ( V_4 -> V_20 ) )
return F_19 ( V_4 -> V_20 ) ;
V_4 -> V_26 = F_20 ( & V_38 -> V_42 , L_2 ) ;
if ( F_18 ( V_4 -> V_26 ) )
return F_19 ( V_4 -> V_26 ) ;
V_41 = F_21 ( V_4 -> V_20 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_21 ( V_4 -> V_26 ) ;
if ( V_41 < 0 )
goto V_46;
V_4 -> V_3 . V_42 = & V_38 -> V_42 ;
V_4 -> V_3 . V_47 = & V_48 ;
V_4 -> V_3 . V_9 = - 1 ;
V_4 -> V_3 . V_49 = 1 ;
V_41 = F_22 ( & V_4 -> V_3 ) ;
if ( V_41 < 0 ) {
F_23 ( & V_38 -> V_42 , L_3 , V_41 ) ;
goto V_50;
}
F_24 ( V_38 , V_4 ) ;
return 0 ;
V_50:
F_25 ( V_4 -> V_26 ) ;
V_46:
F_25 ( V_4 -> V_20 ) ;
return V_41 ;
}
static int F_26 ( struct V_37 * V_38 )
{
struct V_1 * V_4 = F_27 ( V_38 ) ;
int V_41 ;
V_41 = F_28 ( & V_4 -> V_3 ) ;
F_25 ( V_4 -> V_26 ) ;
F_25 ( V_4 -> V_20 ) ;
return V_41 ;
}
