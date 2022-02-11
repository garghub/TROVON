static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = { . V_8 = V_4 -> V_9 , . V_10 = 0 ,
. V_11 = & V_4 -> V_12 ,
. V_13 = sizeof( V_4 -> V_12 ) } ;
if ( V_4 -> V_14 & 0x80 ) {
V_4 -> V_12 &= ~ ( V_15 | V_16 ) ;
switch ( V_3 ) {
case V_17 :
break;
case V_18 :
V_4 -> V_12 |= V_16 ;
break;
case V_19 :
V_4 -> V_12 |= ( V_16 | V_15 ) ;
break;
default:
return - V_20 ;
}
} else {
V_4 -> V_12 &= ~ ( V_21 | V_22 ) ;
switch ( V_3 ) {
case V_17 :
break;
case V_18 :
V_4 -> V_12 |= V_22 ;
break;
case V_19 :
V_4 -> V_12 |= ( V_22 | V_21 ) ;
break;
default:
return - V_20 ;
} ;
}
V_4 -> V_12 |= V_4 -> V_14 ;
V_4 -> V_12 &= V_4 -> V_23 ;
return ( F_2 ( V_4 -> V_24 , & V_7 , 1 ) == 1 ) ? 0 : - V_25 ;
}
static int F_3 ( struct V_1 * V_2 , long V_26 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = { . V_8 = V_4 -> V_9 , . V_10 = 0 ,
. V_11 = & V_4 -> V_12 ,
. V_13 = sizeof( V_4 -> V_12 ) } ;
if ( V_4 -> V_14 & 0x80 ) {
if ( V_26 )
V_4 -> V_12 |= V_27 ;
else
V_4 -> V_12 &= ~ V_27 ;
} else {
if ( V_26 )
V_4 -> V_12 |= V_28 ;
else
V_4 -> V_12 &= ~ V_28 ;
}
V_4 -> V_12 |= V_4 -> V_14 ;
V_4 -> V_12 &= V_4 -> V_23 ;
return ( F_2 ( V_4 -> V_24 , & V_7 , 1 ) == 1 ) ? 0 : - V_25 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_17 ) ;
F_5 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
struct V_1 * F_6 ( struct V_1 * V_2 , struct V_29 * V_24 ,
T_2 V_9 , T_2 V_30 , T_2 V_31 )
{
struct V_4 * V_4 = F_7 ( sizeof( struct V_4 ) , V_32 ) ;
if ( ! V_4 )
return NULL ;
if ( V_30 & 0x80 )
V_4 -> V_12 = V_33 ;
else
V_4 -> V_12 = V_34 ;
V_4 -> V_24 = V_24 ;
V_4 -> V_9 = V_9 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_14 = V_30 ;
V_4 -> V_23 = ~ V_31 ;
if ( F_1 ( V_2 , V_17 ) ) {
F_5 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return NULL ;
}
V_2 -> V_35 . V_36 = F_4 ;
V_2 -> V_35 . V_37 = F_1 ;
V_2 -> V_35 . V_38 = F_3 ;
return V_2 ;
}
