static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 -> V_6 ) ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
if ( V_3 == V_11 ) {
T_2 V_12 = 0 ;
if ( V_8 && V_8 -> V_13 == 1 ) {
V_12 = F_4 ( V_2 -> V_14 + V_15 ) ;
V_12 &= ~ ( V_16 << V_17 ) ;
V_12 |= ( V_8 -> V_18 & V_16 )
<< V_17 ;
V_12 &= ~ ( V_19 << V_20 ) ;
V_12 |= ( 1 & V_19 ) << V_20 ;
F_5 ( V_12 , V_2 -> V_14 + V_15 ) ;
}
if ( V_8 && ( V_8 -> V_21 & V_22 ) ) {
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
static struct V_7 * F_12 ( struct V_37 * V_9 )
{
struct V_7 * V_8 ;
struct V_38 * V_39 = V_9 -> V_40 ;
T_3 V_41 ;
T_3 V_18 ;
V_8 = F_13 ( V_9 , sizeof( * V_8 ) , V_42 ) ;
if ( ! V_8 )
return NULL ;
if ( F_14 ( V_39 , L_1 , NULL ) )
V_8 -> V_21 |= V_43 ;
F_15 ( V_39 , L_2 , & V_41 ) ;
if ( V_41 == 8 )
V_8 -> V_21 |= V_44 ;
F_15 ( V_39 , L_3 , & V_18 ) ;
if ( V_18 > 0 ) {
V_8 -> V_13 = 1 ;
V_8 -> V_18 = V_18 ;
}
return V_8 ;
}
static inline struct V_7 * F_12 ( struct V_37 * V_9 )
{
return NULL ;
}
static int T_4 F_16 ( struct V_4 * V_5 )
{
struct V_34 * V_35 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_37 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_45 * V_46 = NULL ;
const struct V_47 * V_48 ;
int V_49 ;
struct V_36 * V_36 ;
V_46 = F_17 ( sizeof( struct V_45 ) , V_42 ) ;
if ( ! V_46 )
return - V_50 ;
V_2 = F_18 ( V_5 , NULL ) ;
if ( F_19 ( V_2 ) ) {
F_20 ( V_46 ) ;
return F_21 ( V_2 ) ;
}
V_35 = F_10 ( V_2 ) ;
V_35 -> V_51 = V_46 ;
V_36 = F_22 ( V_9 , L_4 ) ;
if ( F_19 ( V_36 ) ) {
F_23 ( V_9 , L_5 ) ;
V_49 = F_21 ( V_36 ) ;
goto V_52;
}
V_35 -> V_36 = V_36 ;
F_24 ( V_36 ) ;
V_2 -> V_53 = V_54
| V_55
| V_56 ;
V_48 = F_25 ( F_26 ( V_57 ) , & V_5 -> V_9 ) ;
if ( V_48 ) {
V_8 = F_12 ( V_9 ) ;
}
if ( V_8 ) {
if ( V_8 -> V_21 & V_43 ) {
V_2 -> V_53 |= V_58 ;
V_2 -> V_6 -> V_59 |= V_60 ;
}
if ( V_8 -> V_21 & V_44 )
V_2 -> V_6 -> V_59 |= V_61 ;
if ( V_8 -> V_53 )
V_2 -> V_53 |= V_8 -> V_53 ;
if ( V_8 -> V_62 )
V_2 -> V_6 -> V_59 |= V_8 -> V_62 ;
if ( V_8 -> V_63 )
V_2 -> V_6 -> V_63 |= V_8 -> V_63 ;
}
V_2 -> V_64 = & V_65 ;
V_49 = F_27 ( V_2 ) ;
if ( V_49 ) {
F_23 ( & V_5 -> V_9 , L_6 ) ;
goto V_66;
}
F_28 ( V_5 , V_2 ) ;
return 0 ;
V_66:
F_29 ( V_36 ) ;
F_30 ( V_36 ) ;
V_52:
F_31 ( V_5 ) ;
F_20 ( V_46 ) ;
return V_49 ;
}
static int T_5 F_32 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_33 ( V_5 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_45 * V_46 = V_35 -> V_51 ;
F_34 ( V_2 , 1 ) ;
F_29 ( V_35 -> V_36 ) ;
F_30 ( V_35 -> V_36 ) ;
F_31 ( V_5 ) ;
F_20 ( V_46 ) ;
F_28 ( V_5 , NULL ) ;
return 0 ;
}
