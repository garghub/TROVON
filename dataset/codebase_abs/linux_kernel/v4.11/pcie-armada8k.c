static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 = V_5 | V_6 ;
V_3 = F_2 ( V_2 , V_7 ) ;
if ( ( V_3 & V_4 ) == V_4 )
return 1 ;
F_3 ( V_2 -> V_8 , L_1 , V_3 ) ;
return 0 ;
}
static void F_4 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_3 ;
if ( ! F_5 ( V_2 ) ) {
V_3 = F_2 ( V_2 , V_11 ) ;
V_3 &= ~ ( V_12 ) ;
F_6 ( V_2 , V_11 , V_3 ) ;
}
V_3 = F_2 ( V_2 , V_11 ) ;
V_3 &= ~ ( V_13 << V_14 ) ;
V_3 |= V_15 << V_14 ;
F_6 ( V_2 , V_11 , V_3 ) ;
F_6 ( V_2 , V_16 , V_17 ) ;
F_6 ( V_2 , V_18 , V_19 ) ;
V_3 = F_2 ( V_2 , V_20 ) ;
V_3 &= ~ ( V_21 << V_22 ) ;
V_3 |= V_23 << V_22 ;
F_6 ( V_2 , V_20 , V_3 ) ;
V_3 = F_2 ( V_2 , V_24 ) ;
V_3 &= ~ ( V_21 << V_22 ) ;
V_3 |= V_23 << V_22 ;
F_6 ( V_2 , V_24 , V_3 ) ;
V_3 = F_2 ( V_2 , V_25 ) ;
V_3 |= V_26 | V_27 |
V_28 | V_29 ;
F_6 ( V_2 , V_25 , V_3 ) ;
if ( ! F_5 ( V_2 ) ) {
V_3 = F_2 ( V_2 , V_11 ) ;
V_3 |= V_12 ;
F_6 ( V_2 , V_11 , V_3 ) ;
}
if ( F_7 ( V_2 ) )
F_8 ( V_2 -> V_8 , L_2 ) ;
}
static void F_9 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_10 ( V_31 ) ;
struct V_9 * V_10 = F_11 ( V_2 ) ;
F_12 ( V_31 ) ;
F_4 ( V_10 ) ;
}
static T_2 F_13 ( int V_32 , void * V_33 )
{
struct V_9 * V_10 = V_33 ;
struct V_1 * V_2 = V_10 -> V_2 ;
T_1 V_34 ;
V_34 = F_2 ( V_2 , V_35 ) ;
F_6 ( V_2 , V_35 , V_34 ) ;
return V_36 ;
}
static int F_14 ( struct V_9 * V_10 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_30 * V_31 = & V_2 -> V_31 ;
struct V_39 * V_8 = & V_38 -> V_8 ;
int V_40 ;
V_31 -> V_41 = - 1 ;
V_31 -> V_42 = & V_43 ;
V_31 -> V_32 = F_15 ( V_38 , 0 ) ;
if ( ! V_31 -> V_32 ) {
F_8 ( V_8 , L_3 ) ;
return - V_44 ;
}
V_40 = F_16 ( V_8 , V_31 -> V_32 , F_13 ,
V_45 , L_4 , V_10 ) ;
if ( V_40 ) {
F_8 ( V_8 , L_5 , V_31 -> V_32 ) ;
return V_40 ;
}
V_40 = F_17 ( V_31 ) ;
if ( V_40 ) {
F_8 ( V_8 , L_6 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static int F_18 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_39 * V_8 = & V_38 -> V_8 ;
struct V_46 * V_47 ;
int V_40 ;
V_10 = F_19 ( V_8 , sizeof( * V_10 ) , V_48 ) ;
if ( ! V_10 )
return - V_49 ;
V_2 = F_19 ( V_8 , sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_42 = & V_50 ;
V_10 -> V_2 = V_2 ;
V_10 -> V_51 = F_20 ( V_8 , NULL ) ;
if ( F_21 ( V_10 -> V_51 ) )
return F_22 ( V_10 -> V_51 ) ;
F_23 ( V_10 -> V_51 ) ;
V_47 = F_24 ( V_38 , V_52 , L_7 ) ;
V_2 -> V_53 = F_25 ( V_8 , V_47 ) ;
if ( F_21 ( V_2 -> V_53 ) ) {
F_8 ( V_8 , L_8 , V_47 ) ;
V_40 = F_22 ( V_2 -> V_53 ) ;
goto V_54;
}
F_26 ( V_38 , V_10 ) ;
V_40 = F_14 ( V_10 , V_38 ) ;
if ( V_40 )
goto V_54;
return 0 ;
V_54:
if ( ! F_21 ( V_10 -> V_51 ) )
F_27 ( V_10 -> V_51 ) ;
return V_40 ;
}
