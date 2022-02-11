static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 1 ;
V_4 -> V_11 = V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = F_3 ( V_2 ) -> V_16 ;
V_4 -> V_17 = 1 ;
}
static inline T_1 F_4 ( T_1 V_18 , T_1 V_19 )
{
return ( ( 7 * V_18 ) + V_19 ) >> 3 ;
}
static void F_5 ( struct V_3 * V_4 , T_1 V_20 )
{
if ( V_4 -> V_6 == 0 && V_4 -> V_7 == 0 ) {
V_4 -> V_6 = V_4 -> V_5 / V_20 ;
V_4 -> V_7 = V_4 -> V_6 ;
} else {
V_4 -> V_6 = F_4 ( V_4 -> V_6 , V_4 -> V_5 / V_20 ) ;
V_4 -> V_7 = F_4 ( V_4 -> V_7 , V_4 -> V_6 ) ;
}
}
static void F_6 ( struct V_1 * V_2 ,
const struct V_21 * V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_22 -> V_23 > 0 )
V_4 -> V_12 = F_7 ( V_22 -> V_23 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_2 V_20 = V_15 - V_4 -> V_14 ;
if ( V_4 -> V_17 ) {
V_4 -> V_16 = F_3 ( V_2 ) -> V_16 ;
V_4 -> V_17 = 0 ;
}
if ( V_4 -> V_12 && V_20 > F_9 ( T_1 , V_4 -> V_12 , V_24 ) ) {
F_5 ( V_4 , V_20 ) ;
V_4 -> V_5 = 0 ;
V_4 -> V_14 = V_15 ;
}
}
static inline void F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
V_4 -> V_11 = V_4 -> V_12 ;
V_4 -> V_10 = 0 ;
} else
V_4 -> V_11 = F_11 ( V_4 -> V_12 , V_4 -> V_11 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
V_4 -> V_5 += V_26 -> V_16 - V_4 -> V_16 ;
V_4 -> V_16 = V_26 -> V_16 ;
F_10 ( V_4 ) ;
}
static inline T_1 F_13 ( struct V_1 * V_2 )
{
const struct V_25 * V_26 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = V_26 -> V_16 - V_4 -> V_16 ;
if ( ! V_4 -> V_9 ) {
V_4 -> V_8 += V_26 -> V_27 ;
V_4 -> V_9 = V_26 -> V_27 ;
}
if ( V_4 -> V_9 > V_26 -> V_27 ) {
if ( V_4 -> V_8 >= V_4 -> V_9 ) {
V_4 -> V_8 -= V_4 -> V_9 ;
V_4 -> V_9 = V_26 -> V_27 ;
} else {
V_4 -> V_9 -= V_4 -> V_8 ;
V_4 -> V_8 = 0 ;
}
}
V_4 -> V_16 = V_26 -> V_16 ;
return V_4 -> V_9 ;
}
static T_1 F_14 ( const struct V_1 * V_2 )
{
const struct V_25 * V_26 = F_3 ( V_2 ) ;
const struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( T_1 , ( V_4 -> V_7 * V_4 -> V_11 ) / V_26 -> V_27 , 2 ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_28 )
{
if ( V_28 & V_29 ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_8 ( V_2 ) ;
V_4 -> V_5 += F_13 ( V_2 ) ;
F_10 ( V_4 ) ;
return;
}
F_12 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , enum V_30 V_31 )
{
struct V_25 * V_26 = F_3 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_31 ) {
case V_32 :
V_26 -> V_33 = V_26 -> V_34 = F_14 ( V_2 ) ;
break;
case V_35 :
V_26 -> V_34 = F_14 ( V_2 ) ;
V_4 -> V_10 = 1 ;
break;
default:
break;
}
}
static T_3 F_17 ( struct V_1 * V_2 , T_1 V_36 , int * V_37 ,
union V_38 * V_39 )
{
const struct V_3 * V_40 = F_2 ( V_2 ) ;
if ( V_36 & ( 1 << ( V_41 - 1 ) ) ) {
V_39 -> V_42 . V_43 = 1 ;
V_39 -> V_42 . V_44 = 0 ;
V_39 -> V_42 . V_45 = F_18 ( V_40 -> V_12 ) ,
V_39 -> V_42 . V_46 = F_18 ( V_40 -> V_11 ) ,
* V_37 = V_41 ;
return sizeof( struct V_47 ) ;
}
return 0 ;
}
static int T_4 F_19 ( void )
{
F_20 ( sizeof( struct V_3 ) > V_48 ) ;
return F_21 ( & V_49 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_49 ) ;
}
