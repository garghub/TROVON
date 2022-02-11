static void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = V_2 -> V_6 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
}
static void F_2 ( struct V_9 * V_10 )
{
const struct V_1 * V_2 = F_3 ( V_10 ) ;
if ( ( V_2 -> V_11 & V_12 ) ||
( V_10 -> V_13 == V_14 ||
V_10 -> V_13 == V_15 ) ) {
struct V_3 * V_4 = F_4 ( V_10 ) ;
V_4 -> V_16 = V_2 -> V_17 ;
V_4 -> V_18 = V_2 -> V_19 ;
V_4 -> V_20 = F_5 ( V_21 , V_22 ) ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = 0 ;
F_1 ( V_2 , V_4 ) ;
return;
}
F_6 ( V_10 ) -> V_25 = & V_26 ;
F_7 ( V_10 ) ;
}
static T_1 F_8 ( struct V_9 * V_10 )
{
const struct V_3 * V_4 = F_4 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_10 ) ;
return F_9 ( V_2 -> V_27 - ( ( V_2 -> V_27 * V_4 -> V_20 ) >> 11U ) , 2U ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_10 ) ;
if ( ! V_4 -> V_24 && V_4 -> V_23 ) {
T_1 V_28 ;
V_28 = V_2 -> V_19 ;
V_2 -> V_11 &= ~ V_29 ;
V_2 -> V_19 = V_4 -> V_18 ;
F_11 ( V_10 ) ;
V_2 -> V_19 = V_28 ;
}
V_4 -> V_18 = V_2 -> V_19 ;
V_4 -> V_24 = 1 ;
V_2 -> V_11 |= V_29 ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_10 ) ;
struct V_1 * V_2 = F_3 ( V_10 ) ;
if ( V_4 -> V_24 && V_4 -> V_23 ) {
T_1 V_28 ;
V_28 = V_2 -> V_19 ;
V_2 -> V_11 |= V_29 ;
V_2 -> V_19 = V_4 -> V_18 ;
F_11 ( V_10 ) ;
V_2 -> V_19 = V_28 ;
}
V_4 -> V_18 = V_2 -> V_19 ;
V_4 -> V_24 = 0 ;
V_2 -> V_11 &= ~ V_29 ;
}
static void F_13 ( struct V_9 * V_10 , T_1 V_30 )
{
const struct V_1 * V_2 = F_3 ( V_10 ) ;
struct V_3 * V_4 = F_4 ( V_10 ) ;
T_1 V_31 = V_2 -> V_17 - V_4 -> V_16 ;
if ( V_31 == 0 && ! ( V_30 & V_32 ) )
V_31 = F_6 ( V_10 ) -> V_33 . V_34 ;
if ( V_31 ) {
V_4 -> V_8 += V_31 ;
V_4 -> V_16 = V_2 -> V_17 ;
if ( V_30 & V_35 )
V_4 -> V_7 += V_31 ;
}
if ( ! F_14 ( V_2 -> V_17 , V_4 -> V_5 ) ) {
if ( V_4 -> V_8 == 0 )
V_4 -> V_8 = 1 ;
V_4 -> V_20 = V_4 -> V_20 -
( V_4 -> V_20 >> V_36 ) +
( V_4 -> V_7 << ( 10U - V_36 ) ) /
V_4 -> V_8 ;
if ( V_4 -> V_20 > V_22 )
V_4 -> V_20 = V_22 ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_15 ( struct V_9 * V_10 , T_2 V_37 )
{
if ( V_38 && V_37 == V_39 ) {
struct V_3 * V_4 = F_4 ( V_10 ) ;
V_4 -> V_20 = V_22 ;
}
}
static void F_16 ( struct V_9 * V_10 , enum V_40 V_41 )
{
struct V_3 * V_4 = F_4 ( V_10 ) ;
switch ( V_41 ) {
case V_42 :
if ( ! V_4 -> V_23 )
V_4 -> V_23 = 1 ;
break;
case V_43 :
if ( V_4 -> V_23 )
V_4 -> V_23 = 0 ;
break;
default:
break;
}
}
static void F_17 ( struct V_9 * V_10 , enum V_40 V_41 )
{
switch ( V_41 ) {
case V_44 :
F_10 ( V_10 ) ;
break;
case V_45 :
F_12 ( V_10 ) ;
break;
case V_42 :
case V_43 :
F_16 ( V_10 , V_41 ) ;
break;
default:
break;
}
}
static void F_18 ( struct V_9 * V_10 , T_1 V_46 , struct V_47 * V_48 )
{
const struct V_3 * V_4 = F_4 ( V_10 ) ;
if ( V_46 & ( 1 << ( V_49 - 1 ) ) ||
V_46 & ( 1 << ( V_50 - 1 ) ) ) {
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
if ( F_6 ( V_10 ) -> V_25 != & V_26 ) {
V_52 . V_53 = 1 ;
V_52 . V_54 = ( V_55 ) V_4 -> V_24 ;
V_52 . V_20 = V_4 -> V_20 ;
V_52 . V_56 = V_4 -> V_7 ;
V_52 . V_57 = V_4 -> V_8 ;
}
F_19 ( V_48 , V_49 , sizeof( V_52 ) , & V_52 ) ;
}
}
static int T_3 F_20 ( void )
{
F_21 ( sizeof( struct V_3 ) > V_58 ) ;
return F_22 ( & V_3 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_3 ) ;
}
