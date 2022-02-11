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
V_2 -> V_12 = 0 ;
if ( V_13 )
F_4 ( V_11 ) -> V_14 = V_13 ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_15 )
{
if ( V_2 -> V_5 == V_15 &&
( V_16 ) ( V_17 - V_2 -> V_6 ) <= V_18 / 32 )
return;
V_2 -> V_5 = V_15 ;
V_2 -> V_6 = V_17 ;
if ( V_2 -> V_7 == 0 )
V_2 -> V_7 = V_17 ;
if ( V_15 <= V_19 ) {
V_2 -> V_3 = V_15 ;
return;
}
if ( V_15 < V_2 -> V_4 ) {
T_2 V_20 = ( V_2 -> V_4 - V_15 )
/ V_21 ;
if ( V_20 > V_22 )
V_2 -> V_3 = V_15 / V_22 ;
else if ( V_20 <= 1U )
V_2 -> V_3 = ( V_15 * V_23 ) / V_21 ;
else
V_2 -> V_3 = V_15 / V_20 ;
} else {
if ( V_15 < V_2 -> V_4 + V_21 )
V_2 -> V_3 = ( V_15 * V_23 ) / V_21 ;
else if ( V_15 < V_2 -> V_4 + V_22 * ( V_21 - 1 ) )
V_2 -> V_3 = ( V_15 * ( V_21 - 1 ) )
/ ( V_15 - V_2 -> V_4 ) ;
else
V_2 -> V_3 = V_15 / V_22 ;
}
if ( V_2 -> V_4 == 0 ) {
if ( V_2 -> V_3 > 20 )
V_2 -> V_3 = 20 ;
}
V_2 -> V_3 = ( V_2 -> V_3 << V_9 ) / V_2 -> V_8 ;
if ( V_2 -> V_3 == 0 )
V_2 -> V_3 = 1 ;
}
static void F_6 ( struct V_10 * V_11 , T_1 V_24 , T_1 V_25 )
{
struct V_26 * V_27 = F_4 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
if ( ! F_7 ( V_11 ) )
return;
if ( F_8 ( V_27 ) )
F_9 ( V_27 , V_25 ) ;
else {
F_5 ( V_2 , V_27 -> V_28 ) ;
F_10 ( V_27 , V_2 -> V_3 , 1 ) ;
}
}
static T_1 F_11 ( struct V_10 * V_11 )
{
const struct V_26 * V_27 = F_4 ( V_11 ) ;
struct V_1 * V_2 = F_3 ( V_11 ) ;
V_2 -> V_7 = 0 ;
if ( V_27 -> V_28 < V_2 -> V_4 && V_29 )
V_2 -> V_4 = ( V_27 -> V_28 * ( V_30 + V_31 ) )
/ ( 2 * V_30 ) ;
else
V_2 -> V_4 = V_27 -> V_28 ;
V_2 -> V_12 = V_27 -> V_28 ;
if ( V_27 -> V_28 <= V_19 )
return F_12 ( V_27 -> V_28 >> 1U , 2U ) ;
else
return F_12 ( ( V_27 -> V_28 * V_31 ) / V_30 , 2U ) ;
}
static T_1 F_13 ( struct V_10 * V_11 )
{
const struct V_26 * V_27 = F_4 ( V_11 ) ;
const struct V_1 * V_2 = F_3 ( V_11 ) ;
return F_12 ( V_27 -> V_28 , V_2 -> V_12 ) ;
}
static void F_14 ( struct V_10 * V_11 , T_3 V_32 )
{
if ( V_32 == V_33 )
F_1 ( F_3 ( V_11 ) ) ;
}
static void F_15 ( struct V_10 * V_11 , const struct V_34 * V_35 )
{
const struct V_36 * V_37 = F_16 ( V_11 ) ;
if ( V_37 -> V_38 == V_39 ) {
struct V_1 * V_2 = F_3 ( V_11 ) ;
V_2 -> V_8 += V_35 -> V_40 -
( V_2 -> V_8 >> V_9 ) ;
}
}
static int T_4 F_17 ( void )
{
F_18 ( sizeof( struct V_1 ) > V_41 ) ;
return F_19 ( & V_1 ) ;
}
static void T_5 F_20 ( void )
{
F_21 ( & V_1 ) ;
}
