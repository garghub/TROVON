static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
T_1 V_6 ;
bool V_7 ;
struct V_8 * V_8 = (struct V_8 * ) V_2 -> V_9 ;
struct V_10 V_11 [ 2 ] = {
{
. V_12 = V_8 -> V_13 ,
. V_14 = 0 ,
. V_6 = & V_8 -> V_15 ,
. V_16 = 1 ,
} , {
. V_12 = V_8 -> V_13 ,
. V_14 = V_17 ,
. V_6 = & V_6 ,
. V_16 = 1 ,
}
} ;
V_8 -> V_15 &= ~ ( V_18 | V_19 ) ;
switch( V_4 ) {
case V_20 :
V_7 = true ;
break;
case V_21 :
V_7 = false ;
V_8 -> V_15 |= V_19 ;
break;
case V_22 :
V_7 = false ;
V_8 -> V_15 |= ( V_19 | V_18 ) ;
break;
default:
return - V_23 ;
}
if ( V_8 -> V_7 && ! V_7 )
V_8 -> V_15 |= V_24 ;
V_8 -> V_15 |= V_8 -> V_25 ;
V_8 -> V_15 &= V_8 -> V_26 ;
V_5 = F_2 ( V_8 -> V_27 , V_11 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_28 ;
V_8 -> V_7 = V_7 ;
if ( ! V_7 && ( V_6 & V_29 ) )
F_3 ( 1000 ) ;
if ( ( V_8 -> V_15 & V_24 ) &&
! ( V_8 -> V_25 & V_24 ) ) {
V_8 -> V_15 &= ~ V_24 ;
V_5 = F_2 ( V_8 -> V_27 , V_11 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 2 )
return - V_28 ;
}
if ( ! V_7 && ( V_6 & V_29 ) ) {
V_8 -> V_15 &= ~ ( V_18 | V_19 ) ;
V_5 = F_2 ( V_8 -> V_27 , V_11 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 1 )
return - V_28 ;
V_8 -> V_7 = true ;
F_4 ( & V_8 -> V_27 -> V_30 ,
L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , long V_31 )
{
struct V_8 * V_8 = (struct V_8 * ) V_2 -> V_9 ;
struct V_10 V_11 = { . V_12 = V_8 -> V_13 , . V_14 = 0 ,
. V_6 = & V_8 -> V_15 ,
. V_16 = sizeof( V_8 -> V_15 ) } ;
if ( V_31 )
V_8 -> V_15 |= V_32 ;
else
V_8 -> V_15 &= ~ V_32 ;
V_8 -> V_15 |= V_8 -> V_25 ;
V_8 -> V_15 &= V_8 -> V_26 ;
return ( F_2 ( V_8 -> V_27 , & V_11 , 1 ) == 1 ) ? 0 : - V_28 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_33 V_34 )
{
struct V_8 * V_8 = (struct V_8 * ) V_2 -> V_9 ;
struct V_10 V_11 = { . V_12 = V_8 -> V_13 , . V_14 = 0 ,
. V_6 = & V_8 -> V_15 ,
. V_16 = sizeof( V_8 -> V_15 ) } ;
switch ( V_34 ) {
case V_35 :
V_8 -> V_15 |= V_36 ;
break;
case V_37 :
V_8 -> V_15 &= ~ V_36 ;
break;
default:
return - V_23 ;
}
V_8 -> V_15 |= V_8 -> V_25 ;
V_8 -> V_15 &= V_8 -> V_26 ;
return ( F_2 ( V_8 -> V_27 , & V_11 , 1 ) == 1 ) ? 0 : - V_28 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_20 ) ;
F_8 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
struct V_1 * F_9 ( struct V_1 * V_2 , struct V_38 * V_27 , T_1 V_13 ,
T_1 V_39 , T_1 V_40 , bool V_41 )
{
struct V_8 * V_8 = F_10 ( sizeof( struct V_8 ) , V_42 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 = V_43 ;
V_8 -> V_27 = V_27 ;
V_8 -> V_13 = V_13 ;
V_2 -> V_9 = V_8 ;
V_8 -> V_25 = V_39 ;
V_8 -> V_26 = ~ V_40 ;
if ( F_1 ( V_2 , V_20 ) ) {
F_8 ( V_8 ) ;
V_2 -> V_9 = NULL ;
return NULL ;
}
V_8 -> V_7 = true ;
V_2 -> V_44 . V_45 = F_7 ;
V_2 -> V_44 . V_46 = F_1 ;
V_2 -> V_44 . V_47 = F_5 ;
if ( V_41 )
V_2 -> V_44 . V_48 = F_6 ;
return V_2 ;
}
