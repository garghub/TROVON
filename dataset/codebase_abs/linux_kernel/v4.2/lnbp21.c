static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_10 , . V_11 = 0 ,
. V_12 = & V_5 -> V_13 ,
. V_14 = sizeof( V_5 -> V_13 ) } ;
V_5 -> V_13 &= ~ ( V_15 | V_16 ) ;
switch( V_4 ) {
case V_17 :
break;
case V_18 :
V_5 -> V_13 |= V_16 ;
break;
case V_19 :
V_5 -> V_13 |= ( V_16 | V_15 ) ;
break;
default:
return - V_20 ;
}
V_5 -> V_13 |= V_5 -> V_21 ;
V_5 -> V_13 &= V_5 -> V_22 ;
return ( F_2 ( V_5 -> V_23 , & V_8 , 1 ) == 1 ) ? 0 : - V_24 ;
}
static int F_3 ( struct V_1 * V_2 , long V_25 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_10 , . V_11 = 0 ,
. V_12 = & V_5 -> V_13 ,
. V_14 = sizeof( V_5 -> V_13 ) } ;
if ( V_25 )
V_5 -> V_13 |= V_26 ;
else
V_5 -> V_13 &= ~ V_26 ;
V_5 -> V_13 |= V_5 -> V_21 ;
V_5 -> V_13 &= V_5 -> V_22 ;
return ( F_2 ( V_5 -> V_23 , & V_8 , 1 ) == 1 ) ? 0 : - V_24 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_27 V_28 )
{
struct V_5 * V_5 = (struct V_5 * ) V_2 -> V_6 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_10 , . V_11 = 0 ,
. V_12 = & V_5 -> V_13 ,
. V_14 = sizeof( V_5 -> V_13 ) } ;
switch ( V_28 ) {
case V_29 :
V_5 -> V_13 &= ~ V_30 ;
break;
case V_31 :
V_5 -> V_13 |= V_30 ;
break;
default:
return - V_20 ;
}
V_5 -> V_13 |= V_5 -> V_21 ;
V_5 -> V_13 &= V_5 -> V_22 ;
return ( F_2 ( V_5 -> V_23 , & V_8 , 1 ) == 1 ) ? 0 : - V_24 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_17 ) ;
F_6 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
static struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_32 * V_23 , T_1 V_33 ,
T_1 V_34 , T_1 V_10 , T_1 V_13 )
{
struct V_5 * V_5 = F_8 ( sizeof( struct V_5 ) , V_35 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_13 = V_13 ;
V_5 -> V_23 = V_23 ;
V_5 -> V_10 = V_10 ;
V_2 -> V_6 = V_5 ;
V_5 -> V_21 = V_33 ;
V_5 -> V_22 = ~ V_34 ;
if ( F_1 ( V_2 , V_17 ) ) {
F_6 ( V_5 ) ;
return NULL ;
}
V_2 -> V_36 . V_37 = F_5 ;
V_2 -> V_36 . V_38 = F_1 ;
V_2 -> V_36 . V_39 = F_3 ;
if ( ! ( V_34 & V_40 ) )
V_2 -> V_36 . V_41 = F_4 ;
F_9 ( V_42 L_1 , V_5 -> V_10 ) ;
return V_2 ;
}
struct V_1 * F_10 ( struct V_1 * V_2 ,
struct V_32 * V_23 , T_1 V_33 ,
T_1 V_34 , T_1 V_10 )
{
return F_7 ( V_2 , V_23 , V_33 , V_34 ,
V_10 , V_43 ) ;
}
struct V_1 * F_11 ( struct V_1 * V_2 ,
struct V_32 * V_23 , T_1 V_33 ,
T_1 V_34 )
{
return F_7 ( V_2 , V_23 , V_33 , V_34 ,
0x08 , V_44 ) ;
}
