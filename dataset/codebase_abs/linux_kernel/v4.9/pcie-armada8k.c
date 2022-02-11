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
struct V_1 * V_2 = & V_10 -> V_2 ;
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
static void F_9 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
F_4 ( V_10 ) ;
}
static T_2 F_12 ( int V_30 , void * V_31 )
{
struct V_9 * V_10 = V_31 ;
struct V_1 * V_2 = & V_10 -> V_2 ;
T_1 V_32 ;
V_32 = F_2 ( V_2 , V_33 ) ;
F_6 ( V_2 , V_33 , V_32 ) ;
return V_34 ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = & V_10 -> V_2 ;
struct V_37 * V_8 = & V_36 -> V_8 ;
int V_38 ;
V_2 -> V_39 = - 1 ;
V_2 -> V_40 = & V_41 ;
V_2 -> V_30 = F_14 ( V_36 , 0 ) ;
if ( ! V_2 -> V_30 ) {
F_8 ( V_8 , L_3 ) ;
return - V_42 ;
}
V_38 = F_15 ( V_8 , V_2 -> V_30 , F_12 ,
V_43 , L_4 , V_10 ) ;
if ( V_38 ) {
F_8 ( V_8 , L_5 , V_2 -> V_30 ) ;
return V_38 ;
}
V_38 = F_16 ( V_2 ) ;
if ( V_38 ) {
F_8 ( V_8 , L_6 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_37 * V_8 = & V_36 -> V_8 ;
struct V_44 * V_45 ;
int V_38 ;
V_10 = F_18 ( V_8 , sizeof( * V_10 ) , V_46 ) ;
if ( ! V_10 )
return - V_47 ;
V_10 -> V_48 = F_19 ( V_8 , NULL ) ;
if ( F_20 ( V_10 -> V_48 ) )
return F_21 ( V_10 -> V_48 ) ;
F_22 ( V_10 -> V_48 ) ;
V_2 = & V_10 -> V_2 ;
V_2 -> V_8 = V_8 ;
V_45 = F_23 ( V_36 , V_49 , L_7 ) ;
V_2 -> V_50 = F_24 ( V_8 , V_45 ) ;
if ( F_20 ( V_2 -> V_50 ) ) {
F_8 ( V_8 , L_8 , V_45 ) ;
V_38 = F_21 ( V_2 -> V_50 ) ;
goto V_51;
}
V_38 = F_13 ( V_10 , V_36 ) ;
if ( V_38 )
goto V_51;
return 0 ;
V_51:
if ( ! F_20 ( V_10 -> V_48 ) )
F_25 ( V_10 -> V_48 ) ;
return V_38 ;
}
