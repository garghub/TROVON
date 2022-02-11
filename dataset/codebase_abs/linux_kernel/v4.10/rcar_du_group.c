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
if ( V_2 -> V_10 > 1 )
V_7 |= V_11 ;
F_3 ( V_2 , V_12 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
unsigned int V_15 =
V_14 -> V_16 -> V_17 [ V_18 ] . V_15 ;
T_1 V_19 = V_20 ;
if ( V_14 -> V_16 -> V_21 < 3 ) {
V_19 |= V_22 ;
if ( V_2 -> V_23 == 0 ) {
if ( V_15 > 1 )
V_19 |= F_7 ( V_14 -> V_24 ) ;
if ( V_2 -> V_4 -> V_25 == 2 )
V_19 |= V_26 ;
}
} else {
T_1 V_27 = F_8 ( V_15 ) - 1 ;
if ( V_27 / 2 == V_2 -> V_23 )
V_19 |= F_7 ( V_27 ) ;
}
F_3 ( V_2 , V_28 , V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_4 ;
F_3 ( V_2 , V_29 , V_30 | V_31 ) ;
if ( V_14 -> V_16 -> V_21 < 3 ) {
F_3 ( V_2 , V_32 , V_33 | V_34 ) ;
F_3 ( V_2 , V_35 , V_36 | V_37 ) ;
F_3 ( V_2 , V_38 , V_39 ) ;
}
F_3 ( V_2 , V_40 , V_41 | V_42 ) ;
F_5 ( V_2 ) ;
if ( F_10 ( V_2 -> V_4 , V_43 ) ) {
F_6 ( V_2 ) ;
if ( ( V_14 -> V_16 -> V_21 < 3 && V_2 -> V_23 == 0 ) ||
( V_14 -> V_16 -> V_21 == 3 && V_2 -> V_10 > 1 ) )
F_3 ( V_2 , V_44 , V_45 ) ;
}
if ( V_14 -> V_16 -> V_21 >= 3 )
F_3 ( V_2 , V_46 , V_47 | V_48 ) ;
F_3 ( V_2 , V_49 , V_50 | V_51 ) ;
F_11 ( & V_2 -> V_52 ) ;
F_3 ( V_2 , V_53 , ( V_2 -> V_54 << 16 ) |
V_2 -> V_54 ) ;
F_12 ( & V_2 -> V_52 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_55 )
goto V_56;
F_9 ( V_2 ) ;
V_56:
V_2 -> V_55 ++ ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
-- V_2 -> V_55 ;
}
static void F_15 ( struct V_1 * V_2 , bool V_57 )
{
F_3 ( V_2 , V_58 ,
( F_1 ( V_2 , V_58 ) & ~ ( V_59 | V_60 ) ) |
( V_57 ? V_60 : V_59 ) ) ;
}
void F_16 ( struct V_1 * V_2 , bool V_57 )
{
if ( V_57 ) {
if ( V_2 -> V_61 ++ != 0 )
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
} else {
if ( -- V_2 -> V_61 == 0 )
F_15 ( V_2 , false ) ;
}
}
void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_62 = false ;
F_15 ( V_2 , false ) ;
F_15 ( V_2 , true ) ;
}
int F_18 ( struct V_13 * V_14 )
{
int V_63 ;
if ( ! F_10 ( V_14 , V_43 ) )
return 0 ;
V_63 = F_19 ( V_14 -> V_64 [ 0 ] . clock ) ;
if ( V_63 < 0 )
return V_63 ;
F_6 ( & V_14 -> V_65 [ 0 ] ) ;
F_20 ( V_14 -> V_64 [ 0 ] . clock ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = & V_2 -> V_4 -> V_64 [ V_2 -> V_23 * 2 ] ;
T_1 V_68 = F_1 ( V_2 , V_49 ) ;
V_68 &= ~ ( V_69 | V_70 | V_71 ) ;
if ( V_67 -> V_72 & F_22 ( V_73 ) )
V_68 |= V_74 ;
else
V_68 |= V_69 | V_70 | V_75 ;
F_3 ( V_2 , V_49 , V_68 ) ;
return F_18 ( V_2 -> V_4 ) ;
}
