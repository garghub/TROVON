T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 , V_2 -> V_5 + V_3 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_2 -> V_4 , V_2 -> V_5 + V_3 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_7 = V_8 | V_9 ;
if ( V_2 -> V_4 -> V_10 -> V_11 [ V_12 ] . V_13 > 1 &&
V_2 -> V_14 == 0 )
V_7 |= F_6 ( V_2 -> V_4 -> V_15 ) ;
F_3 ( V_2 , V_16 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_17 , V_18 | V_19 ) ;
F_3 ( V_2 , V_20 , V_21 | V_22 ) ;
F_3 ( V_2 , V_23 , V_24 | V_25 ) ;
F_3 ( V_2 , V_26 , V_27 ) ;
F_3 ( V_2 , V_28 , V_29 | V_30 ) ;
if ( F_8 ( V_2 -> V_4 , V_31 ) ) {
F_5 ( V_2 ) ;
F_3 ( V_2 , V_32 , V_33 |
F_9 ( 2 ) |
F_9 ( 1 ) |
F_9 ( 0 ) |
F_10 ( 2 , 0 ) |
F_10 ( 1 , 0 ) |
F_10 ( 0 , 0 ) ) ;
}
F_3 ( V_2 , V_34 , V_35 | V_36 ) ;
F_11 ( & V_2 -> V_37 ) ;
F_3 ( V_2 , V_38 , ( V_2 -> V_39 << 16 ) |
V_2 -> V_39 ) ;
F_12 ( & V_2 -> V_37 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 )
goto V_41;
F_7 ( V_2 ) ;
V_41:
V_2 -> V_40 ++ ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
-- V_2 -> V_40 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_42 )
{
F_3 ( V_2 , V_43 ,
( F_1 ( V_2 , V_43 ) & ~ ( V_44 | V_45 ) ) |
( V_42 ? V_45 : V_44 ) ) ;
}
void F_16 ( struct V_1 * V_2 , bool V_42 )
{
if ( V_42 ) {
if ( V_2 -> V_46 ++ != 0 )
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
} else {
if ( -- V_2 -> V_46 == 0 )
F_15 ( V_2 , false ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
}
static int F_18 ( struct V_47 * V_48 )
{
int V_49 ;
if ( ! F_8 ( V_48 , V_31 ) )
return 0 ;
V_49 = F_19 ( V_48 -> V_50 [ 0 ] . clock ) ;
if ( V_49 < 0 )
return V_49 ;
F_5 ( & V_48 -> V_51 [ 0 ] ) ;
F_20 ( V_48 -> V_50 [ 0 ] . clock ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = & V_2 -> V_4 -> V_50 [ V_2 -> V_14 * 2 ] ;
T_1 V_54 = F_1 ( V_2 , V_34 ) ;
V_54 &= ~ ( V_55 | V_56 | V_57 ) ;
if ( V_53 -> V_58 & F_22 ( V_59 ) )
V_54 |= V_60 ;
else
V_54 |= V_55 | V_56 | V_61 ;
F_3 ( V_2 , V_34 , V_54 ) ;
return F_18 ( V_2 -> V_4 ) ;
}
