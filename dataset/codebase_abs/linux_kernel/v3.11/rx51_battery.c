static int F_1 ( int V_1 )
{
struct V_2 V_3 ;
V_3 . V_4 = 1 << V_1 ;
V_3 . V_5 = 1 ;
V_3 . V_6 = V_7 ;
V_3 . V_8 = NULL ;
V_3 . type = V_9 ;
V_3 . V_10 = true ;
if ( F_2 ( & V_3 ) <= 0 )
return - V_11 ;
return V_3 . V_12 [ V_1 ] ;
}
static int F_3 ( struct V_13 * V_14 )
{
int V_15 = F_1 ( 12 ) ;
if ( V_15 < 0 )
return V_15 ;
return 1000 * ( 10000 * V_15 / 1705 ) ;
}
static int F_4 ( struct V_13 * V_14 )
{
int V_16 = 0 ;
int V_17 = F_5 ( V_18 ) - 1 ;
int V_10 = F_1 ( 0 ) ;
if ( V_10 <= 0 )
return V_19 ;
if ( V_10 >= ( 1 << 10 ) )
return V_20 ;
if ( V_10 < F_5 ( V_21 ) )
return V_21 [ V_10 ] * 10 ;
while ( V_17 - V_16 > 1 ) {
int V_22 = ( V_17 + V_16 ) / 2 ;
if ( V_18 [ V_22 ] <= V_10 )
V_16 = V_22 ;
else if ( V_18 [ V_22 ] > V_10 )
V_17 = V_22 ;
if ( V_18 [ V_22 ] == V_10 )
break;
}
return ( V_23 - V_16 ) * 10 ;
}
static int F_6 ( struct V_13 * V_14 )
{
int V_24 = F_1 ( 4 ) ;
if ( V_24 < 0 )
return V_24 ;
return 1280 * ( 1200 * V_24 ) / ( 1024 - V_24 ) ;
}
static int F_7 ( struct V_25 * V_26 ,
enum V_27 V_28 ,
union V_29 * V_30 )
{
struct V_13 * V_14 = F_8 ( ( V_26 ) ,
struct V_13 , V_31 ) ;
switch ( V_28 ) {
case V_32 :
V_30 -> V_33 = V_34 ;
break;
case V_35 :
V_30 -> V_33 = 4200000 ;
break;
case V_36 :
V_30 -> V_33 = F_3 ( V_14 ) ? 1 : 0 ;
break;
case V_37 :
V_30 -> V_33 = F_3 ( V_14 ) ;
break;
case V_38 :
V_30 -> V_33 = F_4 ( V_14 ) ;
break;
case V_39 :
V_30 -> V_33 = F_6 ( V_14 ) ;
break;
default:
return - V_40 ;
}
if ( V_30 -> V_33 == V_19 || V_30 -> V_33 == V_20 )
return - V_40 ;
return 0 ;
}
static int F_9 ( struct V_41 * V_42 )
{
struct V_13 * V_14 ;
int V_43 ;
V_14 = F_10 ( & V_42 -> V_44 , sizeof( * V_14 ) , V_45 ) ;
if ( ! V_14 )
return - V_46 ;
F_11 ( V_42 , V_14 ) ;
V_14 -> V_31 . V_47 = F_12 ( & V_42 -> V_44 ) ;
V_14 -> V_31 . type = V_48 ;
V_14 -> V_31 . V_49 = V_50 ;
V_14 -> V_31 . V_51 = F_5 ( V_50 ) ;
V_14 -> V_31 . V_52 = F_7 ;
V_43 = F_13 ( V_14 -> V_44 , & V_14 -> V_31 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static int F_14 ( struct V_41 * V_42 )
{
struct V_13 * V_14 = F_15 ( V_42 ) ;
F_16 ( & V_14 -> V_31 ) ;
return 0 ;
}
