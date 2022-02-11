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
if ( V_2 -> V_10 == 0 )
V_7 |= F_6 ( V_2 -> V_4 -> V_11 ) ;
F_3 ( V_2 , V_12 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_13 , V_14 | V_15 ) ;
F_3 ( V_2 , V_16 , V_17 | V_18 ) ;
F_3 ( V_2 , V_19 , V_20 | V_21 ) ;
F_3 ( V_2 , V_22 , V_23 ) ;
F_3 ( V_2 , V_24 , V_25 | V_26 ) ;
if ( F_8 ( V_2 -> V_4 , V_27 ) ) {
F_5 ( V_2 ) ;
F_3 ( V_2 , V_28 , V_29 |
F_9 ( 2 ) |
F_9 ( 1 ) |
F_9 ( 0 ) |
F_10 ( 2 , 0 ) |
F_10 ( 1 , 0 ) |
F_10 ( 0 , 0 ) ) ;
}
F_3 ( V_2 , V_30 , V_31 | V_32 ) ;
F_11 ( & V_2 -> V_33 ) ;
F_3 ( V_2 , V_34 , ( V_2 -> V_35 << 16 ) |
V_2 -> V_35 ) ;
F_12 ( & V_2 -> V_33 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_36 )
goto V_37;
F_7 ( V_2 ) ;
V_37:
V_2 -> V_36 ++ ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
-- V_2 -> V_36 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_38 )
{
F_3 ( V_2 , V_39 ,
( F_1 ( V_2 , V_39 ) & ~ ( V_40 | V_41 ) ) |
( V_38 ? V_41 : V_40 ) ) ;
}
void F_16 ( struct V_1 * V_2 , bool V_38 )
{
if ( V_38 ) {
if ( V_2 -> V_42 ++ != 0 )
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
} else {
if ( -- V_2 -> V_42 == 0 )
F_15 ( V_2 , false ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
}
static int F_18 ( struct V_43 * V_44 )
{
int V_45 ;
if ( ! F_8 ( V_44 , V_27 ) )
return 0 ;
V_45 = F_19 ( V_44 -> V_46 [ 0 ] . clock ) ;
if ( V_45 < 0 )
return V_45 ;
F_5 ( & V_44 -> V_47 [ 0 ] ) ;
F_20 ( V_44 -> V_46 [ 0 ] . clock ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = & V_2 -> V_4 -> V_46 [ V_2 -> V_10 * 2 ] ;
T_1 V_50 = F_1 ( V_2 , V_30 ) ;
V_50 &= ~ ( V_51 | V_52 | V_53 ) ;
if ( V_49 -> V_54 & F_22 ( V_55 ) )
V_50 |= V_56 ;
else
V_50 |= V_51 | V_52 | V_57 ;
F_3 ( V_2 , V_30 , V_50 ) ;
return F_18 ( V_2 -> V_4 ) ;
}
