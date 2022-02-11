static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_7 = V_4 -> V_8 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_11 = V_12 ;
V_6 -> V_13 = V_14 ;
V_6 -> V_15 = 0x7fffffff ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
F_1 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_20 , T_2 V_21 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_17 = V_20 ;
if ( V_21 < 0 )
return;
if ( V_21 > V_22 )
V_21 = V_22 ;
if ( V_6 -> V_15 > V_21 )
V_6 -> V_15 = V_21 ;
if ( V_6 -> V_16 < V_21 )
V_6 -> V_16 = V_21 ;
++ V_6 -> V_9 ;
V_6 -> V_10 += V_21 ;
}
static inline T_1 F_6 ( const struct V_5 * V_6 )
{
return V_6 -> V_16 - V_6 -> V_15 ;
}
static inline T_1 F_7 ( const struct V_5 * V_6 )
{
T_3 V_23 = V_6 -> V_10 ;
F_8 ( V_23 , V_6 -> V_9 ) ;
return V_23 - V_6 -> V_15 ;
}
static T_1 V_11 ( struct V_5 * V_6 , T_1 V_24 , T_1 V_25 )
{
T_1 V_26 = V_25 / 100 ;
if ( V_24 <= V_26 ) {
if ( ! V_6 -> V_19 )
return V_12 ;
if ( ++ V_6 -> V_18 < V_27 )
return V_6 -> V_11 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
return V_12 ;
}
V_6 -> V_19 = 1 ;
V_25 -= V_26 ;
V_24 -= V_26 ;
return ( V_25 * V_12 ) /
( V_25 + ( V_24 * ( V_12 - V_28 ) ) / V_28 ) ;
}
static T_1 V_13 ( T_1 V_24 , T_1 V_25 )
{
T_1 V_29 , V_30 ;
V_29 = V_25 / 10 ;
if ( V_24 <= V_29 )
return V_31 ;
V_30 = ( 8 * V_25 ) / 10 ;
if ( V_24 >= V_30 || V_30 <= V_29 )
return V_32 ;
return ( V_31 * V_30 - V_32 * V_29 + ( V_32 - V_31 ) * V_24 )
/ ( V_30 - V_29 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_4 -> V_33 < V_34 ) {
V_6 -> V_11 = V_35 ;
V_6 -> V_13 = V_14 ;
} else if ( V_6 -> V_9 > 0 ) {
T_1 V_25 = F_6 ( V_6 ) ;
T_1 V_24 = F_7 ( V_6 ) ;
V_6 -> V_11 = V_11 ( V_6 , V_24 , V_25 ) ;
V_6 -> V_13 = V_13 ( V_24 , V_25 ) ;
}
F_1 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_4 V_36 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_36 == V_37 ) {
V_6 -> V_11 = V_35 ;
V_6 -> V_13 = V_14 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
F_1 ( V_2 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_1 V_38 , T_1 V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( F_12 ( V_38 , V_6 -> V_7 ) )
F_9 ( V_2 ) ;
if ( ! F_13 ( V_2 ) )
return;
if ( V_4 -> V_33 <= V_4 -> V_39 )
F_14 ( V_4 , V_17 ) ;
else {
T_1 V_40 ;
V_4 -> V_41 += V_6 -> V_17 ;
V_6 -> V_17 = 1 ;
V_40 = ( V_4 -> V_41 * V_6 -> V_11 ) >> V_42 ;
if ( V_40 >= V_4 -> V_33 ) {
V_4 -> V_33 = F_15 ( V_4 -> V_33 + V_40 / V_4 -> V_33 ,
( T_1 ) V_4 -> V_43 ) ;
V_4 -> V_41 = 0 ;
}
}
}
static T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
return F_17 ( V_4 -> V_33 - ( ( V_4 -> V_33 * V_6 -> V_13 ) >> V_44 ) , 2U ) ;
}
static T_5 F_18 ( struct V_1 * V_2 , T_1 V_45 , int * V_46 ,
union V_47 * V_48 )
{
const struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_45 & ( 1 << ( V_49 - 1 ) ) ) {
V_48 -> V_50 . V_51 = 1 ;
V_48 -> V_50 . V_52 = V_6 -> V_9 ;
V_48 -> V_50 . V_53 = V_6 -> V_15 ;
V_48 -> V_50 . V_54 = 0 ;
if ( V_48 -> V_50 . V_52 > 0 ) {
T_3 V_23 = V_6 -> V_10 ;
F_8 ( V_23 , V_48 -> V_50 . V_52 ) ;
V_48 -> V_50 . V_54 = V_23 ;
}
* V_46 = V_49 ;
return sizeof( struct V_55 ) ;
}
return 0 ;
}
static int T_6 F_19 ( void )
{
F_20 ( sizeof( struct V_5 ) > V_56 ) ;
return F_21 ( & V_57 ) ;
}
static void T_7 F_22 ( void )
{
F_23 ( & V_57 ) ;
}
