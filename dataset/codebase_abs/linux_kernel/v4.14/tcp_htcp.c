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
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_6 ) {
V_2 -> V_4 = V_2 -> V_6 ;
V_2 -> V_8 = V_2 -> V_7 ;
V_2 -> V_10 = V_2 -> V_9 ;
V_2 -> V_6 = 0 ;
}
return F_6 ( V_12 ) ;
}
static inline void F_7 ( struct V_11 * V_12 , T_1 V_13 )
{
const struct V_14 * V_15 = F_8 ( V_12 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_5 > V_13 || ! V_2 -> V_5 )
V_2 -> V_5 = V_13 ;
if ( V_15 -> V_16 == V_17 ) {
if ( V_2 -> V_8 < V_2 -> V_5 )
V_2 -> V_8 = V_2 -> V_5 ;
if ( V_2 -> V_8 < V_13 &&
V_13 <= V_2 -> V_8 + F_9 ( 20 ) )
V_2 -> V_8 = V_13 ;
}
}
static void F_10 ( struct V_11 * V_12 ,
const struct V_18 * V_19 )
{
const struct V_14 * V_15 = F_8 ( V_12 ) ;
const struct V_20 * V_21 = F_11 ( V_12 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
T_1 V_22 = V_23 ;
if ( V_15 -> V_16 == V_17 )
V_2 -> V_24 = V_19 -> V_24 ;
if ( V_19 -> V_25 > 0 )
F_7 ( V_12 , F_12 ( V_19 -> V_25 ) ) ;
if ( ! V_26 )
return;
if ( ! ( ( 1 << V_15 -> V_16 ) & ( V_27 | V_28 ) ) ) {
V_2 -> V_29 = 0 ;
V_2 -> V_30 = V_22 ;
return;
}
V_2 -> V_29 += V_19 -> V_24 ;
if ( V_2 -> V_29 >= V_21 -> V_31 - ( V_2 -> V_32 >> 7 ? : 1 ) &&
V_22 - V_2 -> V_30 >= V_2 -> V_5 &&
V_2 -> V_5 > 0 ) {
T_2 V_33 = V_2 -> V_29 * V_34 / ( V_22 - V_2 -> V_30 ) ;
if ( F_2 ( V_2 ) <= 3 ) {
V_2 -> V_35 = V_2 -> V_36 = V_2 -> V_37 = V_33 ;
} else {
V_2 -> V_37 = ( 3 * V_2 -> V_37 + V_33 ) / 4 ;
if ( V_2 -> V_37 > V_2 -> V_36 )
V_2 -> V_36 = V_2 -> V_37 ;
if ( V_2 -> V_35 > V_2 -> V_36 )
V_2 -> V_35 = V_2 -> V_36 ;
}
V_2 -> V_29 = 0 ;
V_2 -> V_30 = V_22 ;
}
}
static inline void F_13 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_8 )
{
if ( V_26 ) {
T_1 V_36 = V_2 -> V_36 ;
T_1 V_10 = V_2 -> V_10 ;
V_2 -> V_10 = V_2 -> V_36 ;
if ( ! F_14 ( 5 * V_36 , 4 * V_10 , 6 * V_10 ) ) {
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = 0 ;
return;
}
}
if ( V_2 -> V_40 && V_5 > F_9 ( 10 ) && V_8 ) {
V_2 -> V_38 = ( V_5 << 7 ) / V_8 ;
if ( V_2 -> V_38 < V_39 )
V_2 -> V_38 = V_39 ;
else if ( V_2 -> V_38 > V_41 )
V_2 -> V_38 = V_41 ;
} else {
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = 1 ;
}
}
static inline void F_15 ( struct V_1 * V_2 )
{
T_1 V_5 = V_2 -> V_5 ;
T_1 V_42 = 1 ;
T_1 V_43 = F_1 ( V_2 ) ;
if ( V_43 > V_34 ) {
V_43 -= V_34 ;
V_42 = 1 + ( 10 * V_43 + ( ( V_43 / 2 ) * ( V_43 / 2 ) / V_34 ) ) / V_34 ;
}
if ( V_44 && V_5 ) {
T_1 V_45 = ( V_34 << 3 ) / ( 10 * V_5 ) ;
V_45 = F_16 ( F_17 ( V_45 , 1U << 2 ) , 10U << 3 ) ;
V_42 = ( V_42 << 3 ) / V_45 ;
if ( ! V_42 )
V_42 = 1 ;
}
V_2 -> V_32 = 2 * V_42 * ( ( 1 << 7 ) - V_2 -> V_38 ) ;
if ( ! V_2 -> V_32 )
V_2 -> V_32 = V_46 ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
T_1 V_5 = V_2 -> V_5 ;
T_1 V_8 = V_2 -> V_8 ;
F_13 ( V_2 , V_5 , V_8 ) ;
F_15 ( V_2 ) ;
if ( V_5 > 0 && V_8 > V_5 )
V_2 -> V_8 = V_5 + ( ( V_8 - V_5 ) * 95 ) / 100 ;
}
static T_1 F_19 ( struct V_11 * V_12 )
{
const struct V_20 * V_21 = F_11 ( V_12 ) ;
const struct V_1 * V_2 = F_5 ( V_12 ) ;
F_18 ( V_12 ) ;
return F_17 ( ( V_21 -> V_31 * V_2 -> V_38 ) >> 7 , 2U ) ;
}
static void F_20 ( struct V_11 * V_12 , T_1 V_47 , T_1 V_48 )
{
struct V_20 * V_21 = F_11 ( V_12 ) ;
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( ! F_21 ( V_12 ) )
return;
if ( F_22 ( V_21 ) )
F_23 ( V_21 , V_48 ) ;
else {
if ( ( V_21 -> V_49 * V_2 -> V_32 ) >> 7 >= V_21 -> V_31 ) {
if ( V_21 -> V_31 < V_21 -> V_50 )
V_21 -> V_31 ++ ;
V_21 -> V_49 = 0 ;
F_15 ( V_2 ) ;
} else
V_21 -> V_49 += V_2 -> V_24 ;
V_2 -> V_24 = 1 ;
}
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_32 = V_46 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_24 = 1 ;
V_2 -> V_4 = V_3 ;
}
static void F_25 ( struct V_11 * V_12 , T_3 V_51 )
{
switch ( V_51 ) {
case V_17 :
{
struct V_1 * V_2 = F_5 ( V_12 ) ;
if ( V_2 -> V_6 ) {
V_2 -> V_4 = V_3 ;
V_2 -> V_6 = 0 ;
}
}
break;
case V_52 :
case V_53 :
case V_54 :
F_3 ( F_5 ( V_12 ) ) ;
break;
}
}
static int T_4 F_26 ( void )
{
F_27 ( sizeof( struct V_1 ) > V_55 ) ;
F_27 ( V_39 >= V_41 ) ;
return F_28 ( & V_1 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_1 ) ;
}
