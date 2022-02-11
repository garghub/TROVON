static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_3 - V_2 -> V_4 ;
}
static inline T_1 F_2 ( const struct V_1 * V_2 )
{
return F_1 ( V_2 ) / V_2 -> V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_4 ;
V_2 -> V_7 = V_2 -> V_8 ;
V_2 -> V_9 = V_2 -> V_10 ;
V_2 -> V_4 = V_3 ;
}
static T_1 F_4 ( struct V_11 * V_12 )
{
const struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_6 ) {
V_2 -> V_4 = V_2 -> V_6 ;
V_2 -> V_8 = V_2 -> V_7 ;
V_2 -> V_10 = V_2 -> V_9 ;
V_2 -> V_6 = 0 ;
}
return F_7 ( V_14 -> V_15 , ( V_14 -> V_16 << 7 ) / V_2 -> V_17 ) ;
}
static inline void F_8 ( struct V_11 * V_12 , T_1 V_18 )
{
const struct V_19 * V_20 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_5 > V_18 || ! V_2 -> V_5 )
V_2 -> V_5 = V_18 ;
if ( V_20 -> V_21 == V_22 ) {
if ( V_2 -> V_8 < V_2 -> V_5 )
V_2 -> V_8 = V_2 -> V_5 ;
if ( V_2 -> V_8 < V_18 &&
V_18 <= V_2 -> V_8 + F_10 ( 20 ) )
V_2 -> V_8 = V_18 ;
}
}
static void F_11 ( struct V_11 * V_12 , T_1 V_23 , T_2 V_24 )
{
const struct V_19 * V_20 = F_9 ( V_12 ) ;
const struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
T_1 V_25 = V_26 ;
if ( V_20 -> V_21 == V_22 )
V_2 -> V_23 = V_23 ;
if ( V_24 > 0 )
F_8 ( V_12 , F_12 ( V_24 ) ) ;
if ( ! V_27 )
return;
if ( ! ( ( 1 << V_20 -> V_21 ) & ( V_28 | V_29 ) ) ) {
V_2 -> V_30 = 0 ;
V_2 -> V_31 = V_25 ;
return;
}
V_2 -> V_30 += V_23 ;
if ( V_2 -> V_30 >= V_14 -> V_15 - ( V_2 -> V_32 >> 7 ? : 1 ) &&
V_25 - V_2 -> V_31 >= V_2 -> V_5 &&
V_2 -> V_5 > 0 ) {
T_3 V_33 = V_2 -> V_30 * V_34 / ( V_25 - V_2 -> V_31 ) ;
if ( F_2 ( V_2 ) <= 3 ) {
V_2 -> V_35 = V_2 -> V_36 = V_2 -> V_37 = V_33 ;
} else {
V_2 -> V_37 = ( 3 * V_2 -> V_37 + V_33 ) / 4 ;
if ( V_2 -> V_37 > V_2 -> V_36 )
V_2 -> V_36 = V_2 -> V_37 ;
if ( V_2 -> V_35 > V_2 -> V_36 )
V_2 -> V_35 = V_2 -> V_36 ;
}
V_2 -> V_30 = 0 ;
V_2 -> V_31 = V_25 ;
}
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_8 )
{
if ( V_27 ) {
T_1 V_36 = V_2 -> V_36 ;
T_1 V_10 = V_2 -> V_10 ;
V_2 -> V_10 = V_2 -> V_36 ;
if ( ! F_14 ( 5 * V_36 , 4 * V_10 , 6 * V_10 ) ) {
V_2 -> V_17 = V_38 ;
V_2 -> V_39 = 0 ;
return;
}
}
if ( V_2 -> V_39 && V_5 > F_10 ( 10 ) && V_8 ) {
V_2 -> V_17 = ( V_5 << 7 ) / V_8 ;
if ( V_2 -> V_17 < V_38 )
V_2 -> V_17 = V_38 ;
else if ( V_2 -> V_17 > V_40 )
V_2 -> V_17 = V_40 ;
} else {
V_2 -> V_17 = V_38 ;
V_2 -> V_39 = 1 ;
}
}
static inline void F_15 ( struct V_1 * V_2 )
{
T_1 V_5 = V_2 -> V_5 ;
T_1 V_41 = 1 ;
T_1 V_42 = F_1 ( V_2 ) ;
if ( V_42 > V_34 ) {
V_42 -= V_34 ;
V_41 = 1 + ( 10 * V_42 + ( ( V_42 / 2 ) * ( V_42 / 2 ) / V_34 ) ) / V_34 ;
}
if ( V_43 && V_5 ) {
T_1 V_44 = ( V_34 << 3 ) / ( 10 * V_5 ) ;
V_44 = F_16 ( F_7 ( V_44 , 1U << 2 ) , 10U << 3 ) ;
V_41 = ( V_41 << 3 ) / V_44 ;
if ( ! V_41 )
V_41 = 1 ;
}
V_2 -> V_32 = 2 * V_41 * ( ( 1 << 7 ) - V_2 -> V_17 ) ;
if ( ! V_2 -> V_32 )
V_2 -> V_32 = V_45 ;
}
static void F_17 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
T_1 V_5 = V_2 -> V_5 ;
T_1 V_8 = V_2 -> V_8 ;
F_13 ( V_2 , V_5 , V_8 ) ;
F_15 ( V_2 ) ;
if ( V_5 > 0 && V_8 > V_5 )
V_2 -> V_8 = V_5 + ( ( V_8 - V_5 ) * 95 ) / 100 ;
}
static T_1 F_18 ( struct V_11 * V_12 )
{
const struct V_13 * V_14 = F_5 ( V_12 ) ;
const struct V_1 * V_2 = F_6 ( V_12 ) ;
F_17 ( V_12 ) ;
return F_7 ( ( V_14 -> V_15 * V_2 -> V_17 ) >> 7 , 2U ) ;
}
static void F_19 ( struct V_11 * V_12 , T_1 V_46 , T_1 V_47 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( ! F_20 ( V_12 , V_47 ) )
return;
if ( V_14 -> V_15 <= V_14 -> V_16 )
F_21 ( V_14 ) ;
else {
if ( ( V_14 -> V_48 * V_2 -> V_32 ) >> 7 >= V_14 -> V_15 ) {
if ( V_14 -> V_15 < V_14 -> V_49 )
V_14 -> V_15 ++ ;
V_14 -> V_48 = 0 ;
F_15 ( V_2 ) ;
} else
V_14 -> V_48 += V_2 -> V_23 ;
V_2 -> V_23 = 1 ;
}
}
static void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_32 = V_45 ;
V_2 -> V_17 = V_38 ;
V_2 -> V_23 = 1 ;
V_2 -> V_4 = V_3 ;
}
static void F_23 ( struct V_11 * V_12 , T_4 V_50 )
{
switch ( V_50 ) {
case V_22 :
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_6 ) {
V_2 -> V_4 = V_3 ;
V_2 -> V_6 = 0 ;
}
}
break;
case V_51 :
case V_52 :
case V_53 :
F_3 ( F_6 ( V_12 ) ) ;
break;
}
}
static int T_5 F_24 ( void )
{
F_25 ( sizeof( struct V_1 ) > V_54 ) ;
F_25 ( V_38 >= V_40 ) ;
return F_26 ( & V_1 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_1 ) ;
}
