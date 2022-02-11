static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
T_1 V_6 = V_7 | V_8 ;
V_5 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ( V_5 & V_6 ) == V_6 )
return 1 ;
F_4 ( V_2 -> V_11 , L_1 , V_5 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_9 = V_4 -> V_9 ;
T_1 V_5 ;
if ( ! F_6 ( V_2 ) ) {
V_5 = F_3 ( V_9 + V_12 ) ;
V_5 &= ~ ( V_13 ) ;
F_7 ( V_5 , V_9 + V_12 ) ;
}
V_5 = F_3 ( V_9 + V_12 ) ;
V_5 &= ~ ( V_14 << V_15 ) ;
V_5 |= V_16 << V_15 ;
F_7 ( V_5 , V_9 + V_12 ) ;
F_7 ( V_17 , V_9 + V_18 ) ;
F_7 ( V_19 , V_9 + V_20 ) ;
V_5 = F_3 ( V_9 + V_21 ) ;
V_5 &= ~ ( V_22 << V_23 ) ;
V_5 |= V_24 << V_23 ;
F_7 ( V_5 , V_9 + V_21 ) ;
V_5 = F_3 ( V_9 + V_25 ) ;
V_5 &= ~ ( V_22 << V_23 ) ;
V_5 |= V_24 << V_23 ;
F_7 ( V_5 , V_9 + V_25 ) ;
V_5 = F_3 ( V_9 + V_26 ) ;
V_5 |= V_27 | V_28 |
V_29 | V_30 ;
F_7 ( V_5 , V_9 + V_26 ) ;
if ( ! F_6 ( V_2 ) ) {
V_5 = F_3 ( V_9 + V_12 ) ;
V_5 |= V_13 ;
F_7 ( V_5 , V_9 + V_12 ) ;
}
if ( F_8 ( V_2 ) )
F_9 ( V_2 -> V_11 , L_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static T_3 F_12 ( int V_31 , void * V_32 )
{
struct V_1 * V_2 = V_32 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_2 * V_9 = V_4 -> V_9 ;
T_1 V_33 ;
V_33 = F_3 ( V_9 + V_34 ) ;
F_7 ( V_33 , V_9 + V_34 ) ;
return V_35 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_38 * V_11 = & V_37 -> V_11 ;
int V_39 ;
V_2 -> V_40 = - 1 ;
V_2 -> V_41 = & V_42 ;
V_2 -> V_31 = F_14 ( V_37 , 0 ) ;
if ( ! V_2 -> V_31 ) {
F_9 ( V_11 , L_3 ) ;
return - V_43 ;
}
V_39 = F_15 ( V_11 , V_2 -> V_31 , F_12 ,
V_44 , L_4 , V_2 ) ;
if ( V_39 ) {
F_9 ( V_11 , L_5 , V_2 -> V_31 ) ;
return V_39 ;
}
V_39 = F_16 ( V_2 ) ;
if ( V_39 ) {
F_9 ( V_11 , L_6 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
static int F_17 ( struct V_36 * V_37 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_38 * V_11 = & V_37 -> V_11 ;
struct V_45 * V_9 ;
int V_39 ;
V_4 = F_18 ( V_11 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
V_4 -> V_48 = F_19 ( V_11 , NULL ) ;
if ( F_20 ( V_4 -> V_48 ) )
return F_21 ( V_4 -> V_48 ) ;
F_22 ( V_4 -> V_48 ) ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_11 = V_11 ;
F_23 ( V_37 , V_4 ) ;
V_9 = F_24 ( V_37 , V_49 , L_7 ) ;
V_2 -> V_50 = F_25 ( V_11 , V_9 ) ;
if ( F_20 ( V_2 -> V_50 ) ) {
F_9 ( V_11 , L_8 , V_9 ) ;
V_39 = F_21 ( V_2 -> V_50 ) ;
goto V_51;
}
V_4 -> V_9 = V_2 -> V_50 + V_52 ;
V_39 = F_13 ( V_2 , V_37 ) ;
if ( V_39 )
goto V_51;
return 0 ;
V_51:
if ( ! F_20 ( V_4 -> V_48 ) )
F_26 ( V_4 -> V_48 ) ;
return V_39 ;
}
