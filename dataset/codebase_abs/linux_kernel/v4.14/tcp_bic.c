static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = 0 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 2 << V_9 ;
}
static void F_2 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_3 ( V_11 ) ;
F_1 ( V_2 ) ;
if ( V_12 )
F_4 ( V_11 ) -> V_13 = V_12 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_14 )
{
if ( V_2 -> V_5 == V_14 &&
( V_15 ) ( V_16 - V_2 -> V_6 ) <= V_17 / 32 )
return;
V_2 -> V_5 = V_14 ;
V_2 -> V_6 = V_16 ;
if ( V_2 -> V_7 == 0 )
V_2 -> V_7 = V_16 ;
if ( V_14 <= V_18 ) {
V_2 -> V_3 = V_14 ;
return;
}
if ( V_14 < V_2 -> V_4 ) {
T_2 V_19 = ( V_2 -> V_4 - V_14 )
/ V_20 ;
if ( V_19 > V_21 )
V_2 -> V_3 = V_14 / V_21 ;
else if ( V_19 <= 1U )
V_2 -> V_3 = ( V_14 * V_22 ) / V_20 ;
else
V_2 -> V_3 = V_14 / V_19 ;
} else {
if ( V_14 < V_2 -> V_4 + V_20 )
V_2 -> V_3 = ( V_14 * V_22 ) / V_20 ;
else if ( V_14 < V_2 -> V_4 + V_21 * ( V_20 - 1 ) )
V_2 -> V_3 = ( V_14 * ( V_20 - 1 ) )
/ ( V_14 - V_2 -> V_4 ) ;
else
V_2 -> V_3 = V_14 / V_21 ;
}
if ( V_2 -> V_4 == 0 ) {
if ( V_2 -> V_3 > 20 )
V_2 -> V_3 = 20 ;
}
V_2 -> V_3 = ( V_2 -> V_3 << V_9 ) / V_2 -> V_8 ;
if ( V_2 -> V_3 == 0 )
V_2 -> V_3 = 1 ;
}
static void F_6 ( struct V_10 * V_11 , T_1 V_23 , T_1 V_24 )
{
struct V_25 * V_26 = F_4 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
if ( ! F_7 ( V_11 ) )
return;
if ( F_8 ( V_26 ) )
F_9 ( V_26 , V_24 ) ;
else {
F_5 ( V_2 , V_26 -> V_27 ) ;
F_10 ( V_26 , V_2 -> V_3 , 1 ) ;
}
}
static T_1 F_11 ( struct V_10 * V_11 )
{
const struct V_25 * V_26 = F_4 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
V_2 -> V_7 = 0 ;
if ( V_26 -> V_27 < V_2 -> V_4 && V_28 )
V_2 -> V_4 = ( V_26 -> V_27 * ( V_29 + V_30 ) )
/ ( 2 * V_29 ) ;
else
V_2 -> V_4 = V_26 -> V_27 ;
if ( V_26 -> V_27 <= V_18 )
return F_12 ( V_26 -> V_27 >> 1U , 2U ) ;
else
return F_12 ( ( V_26 -> V_27 * V_30 ) / V_29 , 2U ) ;
}
static void F_13 ( struct V_10 * V_11 , T_3 V_31 )
{
if ( V_31 == V_32 )
F_1 ( F_3 ( V_11 ) ) ;
}
static void F_14 ( struct V_10 * V_11 , const struct V_33 * V_34 )
{
const struct V_35 * V_36 = F_15 ( V_11 ) ;
if ( V_36 -> V_37 == V_38 ) {
struct V_1 * V_2 = F_3 ( V_11 ) ;
V_2 -> V_8 += V_34 -> V_39 -
( V_2 -> V_8 >> V_9 ) ;
}
}
static int T_4 F_16 ( void )
{
F_17 ( sizeof( struct V_1 ) > V_40 ) ;
return F_18 ( & V_1 ) ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_1 ) ;
}
