static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_10 , . V_11 = 0 ,
. V_12 = & V_5 -> V_13 ,
. V_14 = sizeof( V_5 -> V_13 ) } ;
if ( V_5 -> V_15 & 0x80 ) {
V_5 -> V_13 &= ~ ( V_16 | V_17 ) ;
switch ( V_4 ) {
case V_18 :
break;
case V_19 :
V_5 -> V_13 |= V_17 ;
break;
case V_20 :
V_5 -> V_13 |= ( V_17 | V_16 ) ;
break;
default:
return - V_21 ;
}
} else {
V_5 -> V_13 &= ~ ( V_22 | V_23 ) ;
switch ( V_4 ) {
case V_18 :
break;
case V_19 :
V_5 -> V_13 |= V_23 ;
break;
case V_20 :
V_5 -> V_13 |= ( V_23 | V_22 ) ;
break;
default:
return - V_21 ;
}
}
V_5 -> V_13 |= V_5 -> V_15 ;
V_5 -> V_13 &= V_5 -> V_24 ;
return ( F_2 ( V_5 -> V_25 , & V_8 , 1 ) == 1 ) ? 0 : - V_26 ;
}
static int F_3 ( struct V_1 * V_2 , long V_27 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_10 , . V_11 = 0 ,
. V_12 = & V_5 -> V_13 ,
. V_14 = sizeof( V_5 -> V_13 ) } ;
if ( V_5 -> V_15 & 0x80 ) {
if ( V_27 )
V_5 -> V_13 |= V_28 ;
else
V_5 -> V_13 &= ~ V_28 ;
} else {
if ( V_27 )
V_5 -> V_13 |= V_29 ;
else
V_5 -> V_13 &= ~ V_29 ;
}
V_5 -> V_13 |= V_5 -> V_15 ;
V_5 -> V_13 &= V_5 -> V_24 ;
return ( F_2 ( V_5 -> V_25 , & V_8 , 1 ) == 1 ) ? 0 : - V_26 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_18 ) ;
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
struct V_1 * F_6 ( struct V_1 * V_2 , struct V_30 * V_25 ,
T_1 V_10 , T_1 V_31 , T_1 V_32 )
{
struct V_5 * V_5 = F_7 ( sizeof( struct V_5 ) , V_33 ) ;
if ( ! V_5 )
return NULL ;
if ( V_31 & 0x80 )
V_5 -> V_13 = V_34 ;
else
V_5 -> V_13 = V_35 ;
V_5 -> V_25 = V_25 ;
V_5 -> V_10 = V_10 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_15 = V_31 ;
V_5 -> V_24 = ~ V_32 ;
if ( F_1 ( V_2 , V_18 ) ) {
F_5 ( V_5 ) ;
V_2 -> V_6 = NULL ;
return NULL ;
}
V_2 -> V_36 . V_37 = F_4 ;
V_2 -> V_36 . V_38 = F_1 ;
V_2 -> V_36 . V_39 = F_3 ;
return V_2 ;
}
