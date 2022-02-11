static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = { . V_8 = V_4 -> V_9 , . V_10 = 0 ,
. V_11 = & V_4 -> V_12 ,
. V_13 = sizeof( V_4 -> V_12 ) } ;
V_4 -> V_12 &= ~ ( V_14 | V_15 ) ;
switch( V_3 ) {
case V_16 :
break;
case V_17 :
V_4 -> V_12 |= V_15 ;
break;
case V_18 :
V_4 -> V_12 |= ( V_15 | V_14 ) ;
break;
default:
return - V_19 ;
} ;
V_4 -> V_12 |= V_4 -> V_20 ;
V_4 -> V_12 &= V_4 -> V_21 ;
return ( F_2 ( V_4 -> V_22 , & V_7 , 1 ) == 1 ) ? 0 : - V_23 ;
}
static int F_3 ( struct V_1 * V_2 , long V_24 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = { . V_8 = V_4 -> V_9 , . V_10 = 0 ,
. V_11 = & V_4 -> V_12 ,
. V_13 = sizeof( V_4 -> V_12 ) } ;
if ( V_24 )
V_4 -> V_12 |= V_25 ;
else
V_4 -> V_12 &= ~ V_25 ;
V_4 -> V_12 |= V_4 -> V_20 ;
V_4 -> V_12 &= V_4 -> V_21 ;
return ( F_2 ( V_4 -> V_22 , & V_7 , 1 ) == 1 ) ? 0 : - V_23 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_2 V_26 )
{
struct V_4 * V_4 = (struct V_4 * ) V_2 -> V_5 ;
struct V_6 V_7 = { . V_8 = V_4 -> V_9 , . V_10 = 0 ,
. V_11 = & V_4 -> V_12 ,
. V_13 = sizeof( V_4 -> V_12 ) } ;
switch ( V_26 ) {
case V_27 :
V_4 -> V_12 &= ~ V_28 ;
break;
case V_29 :
V_4 -> V_12 |= V_28 ;
break;
default:
return - V_19 ;
} ;
V_4 -> V_12 |= V_4 -> V_20 ;
V_4 -> V_12 &= V_4 -> V_21 ;
return ( F_2 ( V_4 -> V_22 , & V_7 , 1 ) == 1 ) ? 0 : - V_23 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_16 ) ;
F_6 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_30 * V_22 , T_3 V_31 ,
T_3 V_32 , T_3 V_9 , T_3 V_12 )
{
struct V_4 * V_4 = F_8 ( sizeof( struct V_4 ) , V_33 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_12 = V_12 ;
V_4 -> V_22 = V_22 ;
V_4 -> V_9 = V_9 ;
V_2 -> V_5 = V_4 ;
V_4 -> V_20 = V_31 ;
V_4 -> V_21 = ~ V_32 ;
if ( F_1 ( V_2 , V_16 ) ) {
F_6 ( V_4 ) ;
return NULL ;
}
V_2 -> V_34 . V_35 = F_5 ;
V_2 -> V_34 . V_36 = F_1 ;
V_2 -> V_34 . V_37 = F_3 ;
if ( ! ( V_32 & V_38 ) )
V_2 -> V_34 . V_39 = F_4 ;
F_9 ( V_40 L_1 , V_4 -> V_9 ) ;
return V_2 ;
}
struct V_1 * F_10 ( struct V_1 * V_2 ,
struct V_30 * V_22 , T_3 V_31 ,
T_3 V_32 , T_3 V_9 )
{
return F_7 ( V_2 , V_22 , V_31 , V_32 ,
V_9 , V_41 ) ;
}
struct V_1 * F_11 ( struct V_1 * V_2 ,
struct V_30 * V_22 , T_3 V_31 ,
T_3 V_32 )
{
return F_7 ( V_2 , V_22 , V_31 , V_32 ,
0x08 , V_42 ) ;
}
