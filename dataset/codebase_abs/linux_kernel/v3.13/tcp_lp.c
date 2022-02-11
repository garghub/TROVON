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
static void F_3 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 ,
T_1 V_16 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ! ( V_3 -> V_4 & V_17 ) )
F_4 ( V_2 , V_14 , V_15 , V_16 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_20 = V_3 -> V_9 << 6 ;
T_2 V_21 = 0 ;
if ( V_3 -> V_10 == 0 || V_3 -> V_11 == 0 )
goto V_22;
if ( V_19 -> V_23 . V_24 == V_3 -> V_10 ||
V_19 -> V_23 . V_25 == V_3 -> V_11 )
goto V_22;
V_21 = V_26 * ( V_19 -> V_23 . V_24 -
V_3 -> V_10 ) / ( V_19 -> V_23 . V_25 -
V_3 -> V_11 ) ;
if ( V_21 < 0 )
V_21 = - V_21 ;
if ( V_20 > 0 ) {
V_21 -= V_20 >> 6 ;
V_20 += V_21 ;
} else
V_20 = V_21 << 6 ;
V_22:
if ( ( V_20 >> 6 ) > 0 )
V_3 -> V_4 |= V_27 ;
else
V_3 -> V_4 &= ~ V_27 ;
V_3 -> V_10 = V_19 -> V_23 . V_24 ;
V_3 -> V_11 = V_19 -> V_23 . V_25 ;
return V_20 >> 6 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_28 = 0 ;
V_3 -> V_9 = F_5 ( V_2 ) ;
if ( V_3 -> V_4 & V_27 ) {
V_28 =
V_19 -> V_23 . V_24 * ( V_29 / V_3 -> V_9 ) -
V_19 -> V_23 . V_25 * ( V_29 / V_26 ) ;
if ( V_28 < 0 )
V_28 = - V_28 ;
}
if ( V_28 > 0 )
V_3 -> V_4 |= V_30 ;
else
V_3 -> V_4 &= ~ V_30 ;
return V_28 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_32 = F_7 ( V_2 ) ;
if ( ! ( V_3 -> V_4 & V_27 ) || ! ( V_3 -> V_4 & V_30 ) )
return;
if ( V_32 < V_3 -> V_6 )
V_3 -> V_6 = V_32 ;
if ( V_32 > V_3 -> V_7 ) {
if ( V_32 > V_3 -> V_8 ) {
if ( V_3 -> V_8 == 0 )
V_3 -> V_7 = V_32 ;
else
V_3 -> V_7 = V_3 -> V_8 ;
V_3 -> V_8 = V_32 ;
} else
V_3 -> V_7 = V_32 ;
}
if ( V_3 -> V_5 != 0 ) {
V_32 -= V_3 -> V_5 >> 3 ;
V_3 -> V_5 += V_32 ;
} else
V_3 -> V_5 = V_32 << 3 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_33 , T_3 V_34 )
{
struct V_18 * V_19 = F_6 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_34 > 0 )
F_8 ( V_2 , V_34 ) ;
if ( V_35 > V_19 -> V_23 . V_25 )
V_3 -> V_13 = 3 * ( V_35 - V_19 -> V_23 . V_25 ) ;
if ( V_3 -> V_12 && ( V_35 - V_3 -> V_12 < V_3 -> V_13 ) )
V_3 -> V_4 |= V_17 ;
else
V_3 -> V_4 &= ~ V_17 ;
if ( V_3 -> V_5 >> 3 <
V_3 -> V_6 + 15 * ( V_3 -> V_7 - V_3 -> V_6 ) / 100 )
V_3 -> V_4 |= V_36 ;
else
V_3 -> V_4 &= ~ V_36 ;
F_10 ( L_1 , V_3 -> V_4 ,
V_19 -> V_37 , V_3 -> V_9 , V_3 -> V_6 , V_3 -> V_7 ,
V_3 -> V_5 >> 3 ) ;
if ( V_3 -> V_4 & V_36 )
return;
V_3 -> V_6 = V_3 -> V_5 >> 3 ;
V_3 -> V_7 = V_3 -> V_5 >> 2 ;
V_3 -> V_8 = V_3 -> V_5 >> 2 ;
if ( V_3 -> V_4 & V_17 )
V_19 -> V_37 = 1U ;
else
V_19 -> V_37 = F_11 ( V_19 -> V_37 >> 1U , 1U ) ;
V_3 -> V_12 = V_35 ;
}
static int T_4 F_12 ( void )
{
F_13 ( sizeof( struct V_3 ) > V_38 ) ;
return F_14 ( & V_39 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_39 ) ;
}
