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
T_2 V_36 = V_4 -> V_7 ;
T_1 V_37 = V_4 -> V_20 ;
V_37 -= F_15 ( V_37 , V_37 >> V_38 ) ;
if ( V_36 ) {
V_36 <<= ( 10 - V_38 ) ;
F_16 ( V_36 , F_9 ( 1U , V_4 -> V_8 ) ) ;
V_37 = F_5 ( V_37 + ( T_1 ) V_36 , V_22 ) ;
}
F_17 ( V_4 -> V_20 , V_37 ) ;
F_1 ( V_2 , V_4 ) ;
}
}
static void F_18 ( struct V_9 * V_10 , T_3 V_39 )
{
if ( V_40 && V_39 == V_41 ) {
struct V_3 * V_4 = F_4 ( V_10 ) ;
V_4 -> V_20 = V_22 ;
}
}
static void F_19 ( struct V_9 * V_10 , enum V_42 V_43 )
{
struct V_3 * V_4 = F_4 ( V_10 ) ;
switch ( V_43 ) {
case V_44 :
if ( ! V_4 -> V_23 )
V_4 -> V_23 = 1 ;
break;
case V_45 :
if ( V_4 -> V_23 )
V_4 -> V_23 = 0 ;
break;
default:
break;
}
}
static void F_20 ( struct V_9 * V_10 , enum V_42 V_43 )
{
switch ( V_43 ) {
case V_46 :
F_10 ( V_10 ) ;
break;
case V_47 :
F_12 ( V_10 ) ;
break;
case V_44 :
case V_45 :
F_19 ( V_10 , V_43 ) ;
break;
default:
break;
}
}
static T_4 F_21 ( struct V_9 * V_10 , T_1 V_48 , int * V_49 ,
union V_50 * V_51 )
{
const struct V_3 * V_4 = F_4 ( V_10 ) ;
if ( V_48 & ( 1 << ( V_52 - 1 ) ) ||
V_48 & ( 1 << ( V_53 - 1 ) ) ) {
memset ( & V_51 -> V_3 , 0 , sizeof( V_51 -> V_3 ) ) ;
if ( F_6 ( V_10 ) -> V_25 != & V_26 ) {
V_51 -> V_3 . V_54 = 1 ;
V_51 -> V_3 . V_55 = ( V_56 ) V_4 -> V_24 ;
V_51 -> V_3 . V_20 = V_4 -> V_20 ;
V_51 -> V_3 . V_57 = V_4 -> V_7 ;
V_51 -> V_3 . V_58 = V_4 -> V_8 ;
}
* V_49 = V_52 ;
return sizeof( V_51 -> V_3 ) ;
}
return 0 ;
}
static int T_5 F_22 ( void )
{
F_23 ( sizeof( struct V_3 ) > V_59 ) ;
return F_24 ( & V_3 ) ;
}
static void T_6 F_25 ( void )
{
F_26 ( & V_3 ) ;
}
