static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 -> V_6 ) ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
F_4 ( V_2 , V_3 ) ;
if ( V_3 == V_11 ) {
T_2 V_12 = 0 ;
if ( V_8 && V_8 -> V_13 == 1 ) {
V_12 = F_5 ( V_2 -> V_14 + V_15 ) ;
V_12 &= ~ ( V_16 << V_17 ) ;
V_12 |= ( V_8 -> V_18 & V_16 )
<< V_17 ;
V_12 &= ~ ( V_19 << V_20 ) ;
V_12 |= ( 1 & V_19 ) << V_20 ;
F_6 ( V_12 , V_2 -> V_14 + V_15 ) ;
}
if ( V_8 && ( V_8 -> V_21 & V_22 ) ) {
V_12 = F_5 ( V_2 -> V_14 + V_23 ) ;
V_12 &= ~ V_24 ;
F_6 ( V_12 , V_2 -> V_14 + V_23 ) ;
} else {
V_12 = F_5 ( V_2 -> V_14 + V_23 ) ;
V_12 &= ~ V_24 ;
V_12 |= V_24 ;
F_6 ( V_12 , V_2 -> V_14 + V_23 ) ;
}
}
}
static void F_7 ( struct V_1 * V_2 , int V_25 )
{
T_1 V_26 ;
T_2 V_12 ;
V_26 = F_8 ( V_2 -> V_14 + V_27 ) ;
V_12 = F_5 ( V_2 -> V_14 + V_28 ) ;
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
F_6 ( V_12 , V_2 -> V_14 + V_28 ) ;
F_9 ( V_26 , V_2 -> V_14 + V_27 ) ;
}
static struct V_7 * F_10 ( struct V_34 * V_9 )
{
struct V_7 * V_8 ;
struct V_35 * V_36 = V_9 -> V_37 ;
T_3 V_38 ;
T_3 V_18 ;
V_8 = F_11 ( V_9 , sizeof( * V_8 ) , V_39 ) ;
if ( ! V_8 )
return NULL ;
if ( F_12 ( V_36 , L_1 , NULL ) )
V_8 -> V_21 |= V_40 ;
F_13 ( V_36 , L_2 , & V_38 ) ;
if ( V_38 == 8 )
V_8 -> V_21 |= V_41 ;
F_13 ( V_36 , L_3 , & V_18 ) ;
if ( V_18 > 0 ) {
V_8 -> V_13 = 1 ;
V_8 -> V_18 = V_18 ;
}
return V_8 ;
}
static inline struct V_7 * F_10 ( struct V_34 * V_9 )
{
return NULL ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_42 * V_43 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_34 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
const struct V_44 * V_45 ;
int V_46 ;
struct V_47 * V_47 ;
V_2 = F_15 ( V_5 , NULL , 0 ) ;
if ( F_16 ( V_2 ) )
return F_17 ( V_2 ) ;
V_43 = F_18 ( V_2 ) ;
V_47 = F_19 ( V_9 , L_4 ) ;
if ( F_16 ( V_47 ) ) {
F_20 ( V_9 , L_5 ) ;
V_46 = F_17 ( V_47 ) ;
goto free;
}
V_43 -> V_47 = V_47 ;
V_46 = F_21 ( V_47 ) ;
if ( V_46 ) {
F_20 ( & V_5 -> V_9 , L_6 ) ;
goto free;
}
V_2 -> V_48 = V_49
| V_50
| V_51 ;
V_45 = F_22 ( F_23 ( V_52 ) , & V_5 -> V_9 ) ;
if ( V_45 ) {
V_8 = F_10 ( V_9 ) ;
}
if ( V_8 ) {
if ( V_8 -> V_21 & V_40 ) {
V_2 -> V_48 |= V_53 ;
V_2 -> V_6 -> V_54 |= V_55 ;
}
if ( V_8 -> V_21 & V_41 )
V_2 -> V_6 -> V_54 |= V_56 ;
if ( V_8 -> V_48 )
V_2 -> V_48 |= V_8 -> V_48 ;
if ( V_8 -> V_57 )
V_2 -> V_6 -> V_54 |= V_8 -> V_57 ;
if ( V_8 -> V_58 )
V_2 -> V_6 -> V_58 |= V_8 -> V_58 ;
}
V_2 -> V_59 = & V_60 ;
V_46 = F_24 ( V_2 ) ;
if ( V_46 ) {
F_20 ( & V_5 -> V_9 , L_7 ) ;
goto V_61;
}
return 0 ;
V_61:
F_25 ( V_47 ) ;
free:
F_26 ( V_5 ) ;
return V_46 ;
}
