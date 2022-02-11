static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 -> V_6 ) ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
if ( V_3 == V_11 ) {
T_2 V_12 = 0 ;
if ( V_8 -> V_13 == 1 ) {
V_12 = F_4 ( V_2 -> V_14 + V_15 ) ;
V_12 &= ~ ( V_16 << V_17 ) ;
V_12 |= ( V_8 -> V_18 & V_16 )
<< V_17 ;
V_12 &= ~ ( V_19 << V_20 ) ;
V_12 |= ( 1 & V_19 ) << V_20 ;
F_5 ( V_12 , V_2 -> V_14 + V_15 ) ;
}
if ( V_8 -> V_21 & V_22 ) {
V_12 = F_4 ( V_2 -> V_14 + V_23 ) ;
V_12 &= ~ V_24 ;
F_5 ( V_12 , V_2 -> V_14 + V_23 ) ;
} else {
V_12 = F_4 ( V_2 -> V_14 + V_23 ) ;
V_12 &= ~ V_24 ;
V_12 |= V_24 ;
F_5 ( V_12 , V_2 -> V_14 + V_23 ) ;
}
}
}
static int F_6 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_26 ;
T_2 V_12 ;
V_26 = F_7 ( V_2 -> V_14 + V_27 ) ;
V_12 = F_4 ( V_2 -> V_14 + V_28 ) ;
if ( V_25 == V_29 ) {
V_26 &= ~ V_30 ;
V_12 |= V_31 | V_32 ;
} else {
V_12 &= ~ ( V_31 | V_32 ) ;
if ( V_25 == V_33 )
V_26 |= V_30 ;
else
V_26 &= ~ V_30 ;
}
F_5 ( V_12 , V_2 -> V_14 + V_28 ) ;
F_8 ( V_26 , V_2 -> V_14 + V_27 ) ;
return 0 ;
}
static T_3 F_9 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
return F_11 ( V_35 -> V_36 ) ;
}
static int T_4 F_12 ( struct V_4 * V_5 )
{
struct V_34 * V_35 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_37 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_38 * V_39 = NULL ;
int V_40 ;
struct V_36 * V_36 ;
V_39 = F_13 ( sizeof( struct V_38 ) , V_41 ) ;
if ( ! V_39 )
return - V_42 ;
V_2 = F_14 ( V_5 , NULL ) ;
if ( F_15 ( V_2 ) ) {
F_16 ( V_39 ) ;
return F_17 ( V_2 ) ;
}
V_35 = F_10 ( V_2 ) ;
V_35 -> V_43 = V_39 ;
V_36 = F_18 ( V_9 , L_1 ) ;
if ( F_15 ( V_36 ) ) {
F_19 ( V_9 , L_2 ) ;
V_40 = F_17 ( V_36 ) ;
goto V_44;
}
V_35 -> V_36 = V_36 ;
F_20 ( V_36 ) ;
V_2 -> V_45 = V_46
| V_47
| V_48 ;
if ( V_8 ) {
if ( V_8 -> V_21 & V_49 ) {
V_2 -> V_45 |= V_50 ;
V_2 -> V_6 -> V_51 |= V_52 ;
}
if ( V_8 -> V_21 & V_53 )
V_2 -> V_6 -> V_51 |= V_54 ;
if ( V_8 -> V_45 )
V_2 -> V_45 |= V_8 -> V_45 ;
if ( V_8 -> V_55 )
V_2 -> V_6 -> V_51 |= V_8 -> V_55 ;
if ( V_8 -> V_56 )
V_2 -> V_6 -> V_56 |= V_8 -> V_56 ;
}
V_2 -> V_57 = & V_58 ;
V_40 = F_21 ( V_2 ) ;
if ( V_40 ) {
F_19 ( & V_5 -> V_9 , L_3 ) ;
goto V_59;
}
F_22 ( V_5 , V_2 ) ;
return 0 ;
V_59:
F_23 ( V_36 ) ;
F_24 ( V_36 ) ;
V_44:
F_25 ( V_5 ) ;
F_16 ( V_39 ) ;
return V_40 ;
}
static int T_5 F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_27 ( V_5 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_38 * V_39 = V_35 -> V_43 ;
F_28 ( V_2 , 1 ) ;
F_23 ( V_35 -> V_36 ) ;
F_24 ( V_35 -> V_36 ) ;
F_25 ( V_5 ) ;
F_16 ( V_39 ) ;
F_22 ( V_5 , NULL ) ;
return 0 ;
}
static int T_6 F_29 ( void )
{
return F_30 ( & V_60 ) ;
}
static void T_7 F_31 ( void )
{
F_32 ( & V_60 ) ;
}
