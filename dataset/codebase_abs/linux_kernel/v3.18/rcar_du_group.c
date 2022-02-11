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
if ( ! F_6 ( V_2 -> V_4 , V_10 ) )
return;
if ( V_2 -> V_11 == 0 )
V_7 |= F_7 ( V_2 -> V_4 -> V_12 ) ;
F_3 ( V_2 , V_13 , V_7 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_14 , V_15 | V_16 ) ;
F_3 ( V_2 , V_17 , V_18 | V_19 ) ;
F_3 ( V_2 , V_20 , V_21 | V_22 ) ;
F_3 ( V_2 , V_23 , V_24 ) ;
F_3 ( V_2 , V_25 , V_26 | V_27 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_28 , V_29 | V_30 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_31 )
goto V_32;
F_8 ( V_2 ) ;
V_32:
V_2 -> V_31 ++ ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
-- V_2 -> V_31 ;
}
static void F_11 ( struct V_1 * V_2 , bool V_33 )
{
F_3 ( V_2 , V_34 ,
( F_1 ( V_2 , V_34 ) & ~ ( V_35 | V_36 ) ) |
( V_33 ? V_36 : V_35 ) ) ;
}
void F_12 ( struct V_1 * V_2 , bool V_33 )
{
if ( V_33 ) {
if ( V_2 -> V_37 ++ != 0 )
F_11 ( V_2 , false ) ;
F_11 ( V_2 , true ) ;
} else {
if ( -- V_2 -> V_37 == 0 )
F_11 ( V_2 , false ) ;
}
}
void F_13 ( struct V_1 * V_2 )
{
F_11 ( V_2 , false ) ;
F_11 ( V_2 , true ) ;
}
static int F_14 ( struct V_38 * V_39 )
{
int V_40 ;
V_40 = F_15 ( V_39 -> V_41 [ 0 ] . clock ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( & V_39 -> V_42 [ 0 ] ) ;
F_16 ( V_39 -> V_41 [ 0 ] . clock ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = & V_2 -> V_4 -> V_41 [ V_2 -> V_11 * 2 ] ;
T_1 V_45 = F_1 ( V_2 , V_28 ) ;
V_45 &= ~ ( V_46 | V_47 | V_48 ) ;
if ( V_44 -> V_49 & F_18 ( V_50 ) )
V_45 |= V_51 ;
else
V_45 |= V_46 | V_47 | V_52 ;
F_3 ( V_2 , V_28 , V_45 ) ;
return F_14 ( V_2 -> V_4 ) ;
}
