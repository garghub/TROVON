static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 -> V_3 . V_4 + V_2 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_5 )
{
F_4 ( V_5 , V_1 -> V_3 . V_4 + V_2 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , T_2 V_2 )
{
return F_2 ( V_1 -> V_3 . V_6 + V_2 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_5 )
{
return F_4 ( V_5 , V_1 -> V_3 . V_6 + V_2 ) ;
}
static bool F_7 ( struct V_1 * V_1 )
{
if ( ( F_8 ( V_1 , V_7 ) &
( V_8 | V_9 ) ) != V_8 )
return false ;
if ( F_8 ( V_1 , V_10 ) & V_11 )
return false ;
return true ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_12 )
{
F_10 ( V_1 , V_7 ,
( V_8 | V_9 | V_12 ) ) ;
F_8 ( V_1 , V_7 ) ;
F_10 ( V_1 , V_10 , 0 ) ;
F_8 ( V_1 , V_10 ) ;
F_11 ( 1 ) ;
F_10 ( V_1 , V_7 , ( V_8 | V_12 ) ) ;
F_8 ( V_1 , V_7 ) ;
F_11 ( 1 ) ;
}
static void F_12 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_13 , T_1 V_14 )
{
F_13 ( 1 ) ;
}
static T_1 F_14 ( struct V_1 * V_1 )
{
F_13 ( 1 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_1 , T_2 V_2 ,
T_1 V_13 , T_1 V_14 )
{
F_13 ( 1 ) ;
}
static int F_16 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 . V_20 ;
struct V_1 * V_1 ;
struct V_21 * V_22 ;
const T_3 * V_23 ;
V_1 = F_17 ( & V_16 -> V_19 , sizeof( * V_1 ) , V_24 ) ;
if ( ! V_1 )
return - V_25 ;
F_18 ( V_16 , V_1 ) ;
V_1 -> V_26 |= V_27 ;
V_1 -> V_26 |= V_28 ;
V_1 -> V_26 |= V_29 ;
V_1 -> V_26 |= V_30 ;
V_1 -> V_26 |= V_31 ;
V_1 -> V_26 |= V_32 ;
V_1 -> V_19 = & V_16 -> V_19 ;
V_1 -> V_33 = & V_16 -> V_19 ;
V_23 = F_19 ( V_18 ) ;
if ( V_23 )
F_20 ( V_1 -> V_23 , V_23 ) ;
else
F_21 ( & V_16 -> V_19 , L_1 ) ;
V_1 -> V_34 = F_22 ( V_16 , 0 ) ;
if ( V_1 -> V_34 < 0 ) {
F_23 ( & V_16 -> V_19 , L_2 ) ;
return V_1 -> V_34 ;
}
V_22 = F_24 ( V_16 , V_35 , L_3 ) ;
if ( ! V_22 ) {
F_23 ( & V_16 -> V_19 , L_4 ) ;
return - V_36 ;
}
V_1 -> V_3 . V_4 = F_25 ( & V_16 -> V_19 , V_22 ) ;
if ( F_26 ( V_1 -> V_3 . V_4 ) )
return F_27 ( V_1 -> V_3 . V_4 ) ;
V_22 = F_24 ( V_16 , V_35 , L_5 ) ;
if ( ! V_22 ) {
F_23 ( & V_16 -> V_19 , L_6 ) ;
return - V_36 ;
}
V_1 -> V_3 . V_6 = F_25 ( & V_16 -> V_19 , V_22 ) ;
if ( F_26 ( V_1 -> V_3 . V_6 ) )
return F_27 ( V_1 -> V_3 . V_6 ) ;
V_1 -> V_37 = F_1 ;
V_1 -> V_38 = F_3 ;
V_1 -> V_39 = F_5 ;
V_1 -> V_40 = F_6 ;
V_1 -> V_41 = F_7 ;
V_1 -> V_42 = F_9 ;
V_1 -> V_43 = F_12 ;
V_1 -> V_44 = F_14 ;
V_1 -> V_45 = F_15 ;
return F_28 ( V_1 ) ;
}
static int F_29 ( struct V_15 * V_16 )
{
struct V_1 * V_1 = F_30 ( V_16 ) ;
F_31 ( V_1 ) ;
return 0 ;
}
