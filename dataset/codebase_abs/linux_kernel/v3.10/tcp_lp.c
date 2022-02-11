static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_4 = 0 ;
V_3 -> V_5 = 0 ;
V_3 -> V_6 = 0xffffffff ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = 0 ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
V_3 -> V_13 = 0 ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! ( V_3 -> V_4 & V_16 ) )
F_4 ( V_2 , V_14 , V_15 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_19 = V_3 -> V_9 << 6 ;
T_2 V_20 = 0 ;
if ( V_3 -> V_10 == 0 || V_3 -> V_11 == 0 )
goto V_21;
if ( V_18 -> V_22 . V_23 == V_3 -> V_10 ||
V_18 -> V_22 . V_24 == V_3 -> V_11 )
goto V_21;
V_20 = V_25 * ( V_18 -> V_22 . V_23 -
V_3 -> V_10 ) / ( V_18 -> V_22 . V_24 -
V_3 -> V_11 ) ;
if ( V_20 < 0 )
V_20 = - V_20 ;
if ( V_19 > 0 ) {
V_20 -= V_19 >> 6 ;
V_19 += V_20 ;
} else
V_19 = V_20 << 6 ;
V_21:
if ( ( V_19 >> 6 ) > 0 )
V_3 -> V_4 |= V_26 ;
else
V_3 -> V_4 &= ~ V_26 ;
V_3 -> V_10 = V_18 -> V_22 . V_23 ;
V_3 -> V_11 = V_18 -> V_22 . V_24 ;
return V_19 >> 6 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_27 = 0 ;
V_3 -> V_9 = F_5 ( V_2 ) ;
if ( V_3 -> V_4 & V_26 ) {
V_27 =
V_18 -> V_22 . V_23 * ( V_28 / V_3 -> V_9 ) -
V_18 -> V_22 . V_24 * ( V_28 / V_25 ) ;
if ( V_27 < 0 )
V_27 = - V_27 ;
}
if ( V_27 > 0 )
V_3 -> V_4 |= V_29 ;
else
V_3 -> V_4 &= ~ V_29 ;
return V_27 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_30 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_31 = F_7 ( V_2 ) ;
if ( ! ( V_3 -> V_4 & V_26 ) || ! ( V_3 -> V_4 & V_29 ) )
return;
if ( V_31 < V_3 -> V_6 )
V_3 -> V_6 = V_31 ;
if ( V_31 > V_3 -> V_7 ) {
if ( V_31 > V_3 -> V_8 ) {
if ( V_3 -> V_8 == 0 )
V_3 -> V_7 = V_31 ;
else
V_3 -> V_7 = V_3 -> V_8 ;
V_3 -> V_8 = V_31 ;
} else
V_3 -> V_7 = V_31 ;
}
if ( V_3 -> V_5 != 0 ) {
V_31 -= V_3 -> V_5 >> 3 ;
V_3 -> V_5 += V_31 ;
} else
V_3 -> V_5 = V_31 << 3 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_32 , T_3 V_33 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_33 > 0 )
F_8 ( V_2 , V_33 ) ;
if ( V_34 > V_18 -> V_22 . V_24 )
V_3 -> V_13 = 3 * ( V_34 - V_18 -> V_22 . V_24 ) ;
if ( V_3 -> V_12 && ( V_34 - V_3 -> V_12 < V_3 -> V_13 ) )
V_3 -> V_4 |= V_16 ;
else
V_3 -> V_4 &= ~ V_16 ;
if ( V_3 -> V_5 >> 3 <
V_3 -> V_6 + 15 * ( V_3 -> V_7 - V_3 -> V_6 ) / 100 )
V_3 -> V_4 |= V_35 ;
else
V_3 -> V_4 &= ~ V_35 ;
F_10 ( L_1 , V_3 -> V_4 ,
V_18 -> V_36 , V_3 -> V_9 , V_3 -> V_6 , V_3 -> V_7 ,
V_3 -> V_5 >> 3 ) ;
if ( V_3 -> V_4 & V_35 )
return;
V_3 -> V_6 = V_3 -> V_5 >> 3 ;
V_3 -> V_7 = V_3 -> V_5 >> 2 ;
V_3 -> V_8 = V_3 -> V_5 >> 2 ;
if ( V_3 -> V_4 & V_16 )
V_18 -> V_36 = 1U ;
else
V_18 -> V_36 = F_11 ( V_18 -> V_36 >> 1U , 1U ) ;
V_3 -> V_12 = V_34 ;
}
static int T_4 F_12 ( void )
{
F_13 ( sizeof( struct V_3 ) > V_37 ) ;
return F_14 ( & V_38 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_38 ) ;
}
