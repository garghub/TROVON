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
static void F_5 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_22 = V_21 -> V_22 ;
V_6 -> V_17 = V_21 -> V_23 ;
if ( V_22 < 0 )
return;
if ( V_22 > V_24 )
V_22 = V_24 ;
if ( V_6 -> V_15 > V_22 )
V_6 -> V_15 = V_22 ;
if ( V_6 -> V_16 < V_22 )
V_6 -> V_16 = V_22 ;
++ V_6 -> V_9 ;
V_6 -> V_10 += V_22 ;
}
static inline T_2 F_6 ( const struct V_5 * V_6 )
{
return V_6 -> V_16 - V_6 -> V_15 ;
}
static inline T_2 F_7 ( const struct V_5 * V_6 )
{
T_3 V_25 = V_6 -> V_10 ;
F_8 ( V_25 , V_6 -> V_9 ) ;
return V_25 - V_6 -> V_15 ;
}
static T_2 V_11 ( struct V_5 * V_6 , T_2 V_26 , T_2 V_27 )
{
T_2 V_28 = V_27 / 100 ;
if ( V_26 <= V_28 ) {
if ( ! V_6 -> V_19 )
return V_12 ;
if ( ++ V_6 -> V_18 < V_29 )
return V_6 -> V_11 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
return V_12 ;
}
V_6 -> V_19 = 1 ;
V_27 -= V_28 ;
V_26 -= V_28 ;
return ( V_27 * V_12 ) /
( V_27 + ( V_26 * ( V_12 - V_30 ) ) / V_30 ) ;
}
static T_2 V_13 ( T_2 V_26 , T_2 V_27 )
{
T_2 V_31 , V_32 ;
V_31 = V_27 / 10 ;
if ( V_26 <= V_31 )
return V_33 ;
V_32 = ( 8 * V_27 ) / 10 ;
if ( V_26 >= V_32 || V_32 <= V_31 )
return V_34 ;
return ( V_33 * V_32 - V_34 * V_31 + ( V_34 - V_33 ) * V_26 )
/ ( V_32 - V_31 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_4 -> V_35 < V_36 ) {
V_6 -> V_11 = V_37 ;
V_6 -> V_13 = V_14 ;
} else if ( V_6 -> V_9 > 0 ) {
T_2 V_27 = F_6 ( V_6 ) ;
T_2 V_26 = F_7 ( V_6 ) ;
V_6 -> V_11 = V_11 ( V_6 , V_26 , V_27 ) ;
V_6 -> V_13 = V_13 ( V_26 , V_27 ) ;
}
F_1 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_4 V_38 )
{
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_38 == V_39 ) {
V_6 -> V_11 = V_37 ;
V_6 -> V_13 = V_14 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 0 ;
F_1 ( V_2 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_2 V_40 , T_2 V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( F_12 ( V_40 , V_6 -> V_7 ) )
F_9 ( V_2 ) ;
if ( ! F_13 ( V_2 ) )
return;
if ( F_14 ( V_4 ) )
F_15 ( V_4 , V_17 ) ;
else {
T_2 V_41 ;
V_4 -> V_42 += V_6 -> V_17 ;
V_6 -> V_17 = 1 ;
V_41 = ( V_4 -> V_42 * V_6 -> V_11 ) >> V_43 ;
if ( V_41 >= V_4 -> V_35 ) {
V_4 -> V_35 = F_16 ( V_4 -> V_35 + V_41 / V_4 -> V_35 ,
( T_2 ) V_4 -> V_44 ) ;
V_4 -> V_42 = 0 ;
}
}
}
static T_2 F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_45 = V_4 -> V_35 ;
return F_18 ( V_4 -> V_35 - ( ( V_4 -> V_35 * V_6 -> V_13 ) >> V_46 ) , 2U ) ;
}
static T_2 F_19 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = F_3 ( V_2 ) ;
return F_18 ( F_2 ( V_2 ) -> V_35 , V_6 -> V_45 ) ;
}
static T_5 F_20 ( struct V_1 * V_2 , T_2 V_47 , int * V_48 ,
union V_49 * V_50 )
{
const struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( V_47 & ( 1 << ( V_51 - 1 ) ) ) {
V_50 -> V_52 . V_53 = 1 ;
V_50 -> V_52 . V_54 = V_6 -> V_9 ;
V_50 -> V_52 . V_55 = V_6 -> V_15 ;
V_50 -> V_52 . V_56 = 0 ;
if ( V_50 -> V_52 . V_54 > 0 ) {
T_3 V_25 = V_6 -> V_10 ;
F_8 ( V_25 , V_50 -> V_52 . V_54 ) ;
V_50 -> V_52 . V_56 = V_25 ;
}
* V_48 = V_51 ;
return sizeof( struct V_57 ) ;
}
return 0 ;
}
static int T_6 F_21 ( void )
{
F_22 ( sizeof( struct V_5 ) > V_58 ) ;
return F_23 ( & V_59 ) ;
}
static void T_7 F_24 ( void )
{
F_25 ( & V_59 ) ;
}
