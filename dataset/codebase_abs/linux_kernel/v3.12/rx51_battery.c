static int F_1 ( int V_1 )
{
struct V_2 V_3 ;
V_3 . V_4 = V_1 ;
V_3 . V_5 = 1 ;
V_3 . V_6 = V_7 ;
V_3 . V_8 = NULL ;
V_3 . type = V_9 ;
V_3 . V_10 = true ;
if ( F_2 ( & V_3 ) <= 0 )
return - V_11 ;
return V_3 . V_12 [ F_3 ( V_1 ) - 1 ] ;
}
static int F_4 ( struct V_13 * V_14 )
{
int V_15 = F_1 ( V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
return 1000 * ( 10000 * V_15 / 1705 ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
int V_17 = 0 ;
int V_18 = F_6 ( V_19 ) - 1 ;
int V_10 = F_1 ( V_20 ) ;
if ( V_10 <= 0 )
return V_21 ;
if ( V_10 >= ( 1 << 10 ) )
return V_22 ;
if ( V_10 < F_6 ( V_23 ) )
return V_23 [ V_10 ] * 10 ;
while ( V_18 - V_17 > 1 ) {
int V_24 = ( V_18 + V_17 ) / 2 ;
if ( V_19 [ V_24 ] <= V_10 )
V_17 = V_24 ;
else if ( V_19 [ V_24 ] > V_10 )
V_18 = V_24 ;
if ( V_19 [ V_24 ] == V_10 )
break;
}
return ( V_25 - V_17 ) * 10 ;
}
static int F_7 ( struct V_13 * V_14 )
{
int V_26 = F_1 ( V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
return 1280 * ( 1200 * V_26 ) / ( 1024 - V_26 ) ;
}
static int F_8 ( struct V_28 * V_29 ,
enum V_30 V_31 ,
union V_32 * V_33 )
{
struct V_13 * V_14 = F_9 ( ( V_29 ) ,
struct V_13 , V_34 ) ;
switch ( V_31 ) {
case V_35 :
V_33 -> V_36 = V_37 ;
break;
case V_38 :
V_33 -> V_36 = 4200000 ;
break;
case V_39 :
V_33 -> V_36 = F_4 ( V_14 ) ? 1 : 0 ;
break;
case V_40 :
V_33 -> V_36 = F_4 ( V_14 ) ;
break;
case V_41 :
V_33 -> V_36 = F_5 ( V_14 ) ;
break;
case V_42 :
V_33 -> V_36 = F_7 ( V_14 ) ;
break;
default:
return - V_43 ;
}
if ( V_33 -> V_36 == V_21 || V_33 -> V_36 == V_22 )
return - V_43 ;
return 0 ;
}
static int F_10 ( struct V_44 * V_45 )
{
struct V_13 * V_14 ;
int V_46 ;
V_14 = F_11 ( & V_45 -> V_47 , sizeof( * V_14 ) , V_48 ) ;
if ( ! V_14 )
return - V_49 ;
F_12 ( V_45 , V_14 ) ;
V_14 -> V_34 . V_50 = F_13 ( & V_45 -> V_47 ) ;
V_14 -> V_34 . type = V_51 ;
V_14 -> V_34 . V_52 = V_53 ;
V_14 -> V_34 . V_54 = F_6 ( V_53 ) ;
V_14 -> V_34 . V_55 = F_8 ;
V_46 = F_14 ( V_14 -> V_47 , & V_14 -> V_34 ) ;
if ( V_46 )
return V_46 ;
return 0 ;
}
static int F_15 ( struct V_44 * V_45 )
{
struct V_13 * V_14 = F_16 ( V_45 ) ;
F_17 ( & V_14 -> V_34 ) ;
return 0 ;
}
