static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_2 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_3 ;
}
static int F_3 ( struct V_5 * V_6 )
{
int V_7 = F_1 ( V_6 -> V_8 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_9 , L_1 , V_7 ) ;
return V_7 ;
}
return 1000 * ( 10000 * V_7 / 1705 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
int V_10 = 0 ;
int V_11 = F_6 ( V_12 ) - 1 ;
int V_13 = F_1 ( V_6 -> V_14 ) ;
if ( V_13 < 0 )
F_4 ( V_6 -> V_9 , L_1 , V_13 ) ;
if ( V_13 <= 0 )
return V_15 ;
if ( V_13 >= ( 1 << 10 ) )
return V_16 ;
if ( V_13 < F_6 ( V_17 ) )
return V_17 [ V_13 ] * 10 ;
while ( V_11 - V_10 > 1 ) {
int V_18 = ( V_11 + V_10 ) / 2 ;
if ( V_12 [ V_18 ] <= V_13 )
V_10 = V_18 ;
else if ( V_12 [ V_18 ] > V_13 )
V_11 = V_18 ;
if ( V_12 [ V_18 ] == V_13 )
break;
}
return ( V_19 - V_10 ) * 10 ;
}
static int F_7 ( struct V_5 * V_6 )
{
int V_20 = F_1 ( V_6 -> V_21 ) ;
if ( V_20 < 0 ) {
F_4 ( V_6 -> V_9 , L_1 , V_20 ) ;
return V_20 ;
}
return 1280 * ( 1200 * V_20 ) / ( 1024 - V_20 ) ;
}
static int F_8 ( struct V_22 * V_23 ,
enum V_24 V_25 ,
union V_26 * V_3 )
{
struct V_5 * V_6 = F_9 ( V_23 ) ;
switch ( V_25 ) {
case V_27 :
V_3 -> V_28 = V_29 ;
break;
case V_30 :
V_3 -> V_28 = 4200000 ;
break;
case V_31 :
V_3 -> V_28 = F_3 ( V_6 ) ? 1 : 0 ;
break;
case V_32 :
V_3 -> V_28 = F_3 ( V_6 ) ;
break;
case V_33 :
V_3 -> V_28 = F_5 ( V_6 ) ;
break;
case V_34 :
V_3 -> V_28 = F_7 ( V_6 ) ;
break;
default:
return - V_35 ;
}
if ( V_3 -> V_28 == V_15 || V_3 -> V_28 == V_16 )
return - V_35 ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 )
{
struct V_38 V_39 = {} ;
struct V_5 * V_6 ;
int V_40 ;
V_6 = F_11 ( & V_37 -> V_9 , sizeof( * V_6 ) , V_41 ) ;
if ( ! V_6 )
return - V_42 ;
F_12 ( V_37 , V_6 ) ;
V_6 -> V_9 = & V_37 -> V_9 ;
V_6 -> V_43 . V_44 = L_2 ;
V_6 -> V_43 . type = V_45 ;
V_6 -> V_43 . V_46 = V_47 ;
V_6 -> V_43 . V_48 = F_6 ( V_47 ) ;
V_6 -> V_43 . V_49 = F_8 ;
V_39 . V_50 = V_6 ;
V_6 -> V_14 = F_13 ( V_6 -> V_9 , L_3 ) ;
if ( F_14 ( V_6 -> V_14 ) ) {
V_40 = F_15 ( V_6 -> V_14 ) ;
goto error;
}
V_6 -> V_21 = F_13 ( V_6 -> V_9 , L_4 ) ;
if ( F_14 ( V_6 -> V_21 ) ) {
V_40 = F_15 ( V_6 -> V_21 ) ;
goto V_51;
}
V_6 -> V_8 = F_13 ( V_6 -> V_9 , L_5 ) ;
if ( F_14 ( V_6 -> V_8 ) ) {
V_40 = F_15 ( V_6 -> V_8 ) ;
goto V_52;
}
V_6 -> V_53 = F_16 ( V_6 -> V_9 , & V_6 -> V_43 , & V_39 ) ;
if ( F_14 ( V_6 -> V_53 ) ) {
V_40 = F_15 ( V_6 -> V_53 ) ;
goto V_54;
}
return 0 ;
V_54:
F_17 ( V_6 -> V_8 ) ;
V_52:
F_17 ( V_6 -> V_21 ) ;
V_51:
F_17 ( V_6 -> V_14 ) ;
error:
return V_40 ;
}
static int F_18 ( struct V_36 * V_37 )
{
struct V_5 * V_6 = F_19 ( V_37 ) ;
F_20 ( V_6 -> V_53 ) ;
F_17 ( V_6 -> V_8 ) ;
F_17 ( V_6 -> V_21 ) ;
F_17 ( V_6 -> V_14 ) ;
return 0 ;
}
