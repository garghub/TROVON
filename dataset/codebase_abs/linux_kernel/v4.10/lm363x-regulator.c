static int F_1 ( struct V_1 * V_2 )
{
enum V_3 V_4 = F_2 ( V_2 ) ;
T_1 V_5 , V_6 , V_7 ;
switch ( V_4 ) {
case V_8 :
V_6 = V_9 ;
V_7 = V_10 ;
break;
case V_11 :
V_6 = V_12 ;
V_7 = V_13 ;
break;
case V_14 :
V_6 = V_15 ;
V_7 = V_13 ;
break;
case V_16 :
V_6 = V_17 ;
V_7 = V_13 ;
break;
default:
return 0 ;
}
if ( F_3 ( V_2 -> V_18 , V_6 , ( unsigned int * ) & V_5 ) )
return - V_19 ;
V_5 = ( V_5 & V_7 ) >> V_20 ;
if ( V_4 == V_8 )
return V_21 [ V_5 ] ;
else
return V_22 * V_5 ;
}
static int F_4 ( struct V_23 * V_24 , int V_4 )
{
switch ( V_4 ) {
case V_25 :
return F_5 ( V_24 , L_1 , 0 ) ;
case V_26 :
return F_5 ( V_24 , L_2 , 0 ) ;
default:
return - V_19 ;
}
}
static int F_6 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_7 ( V_28 -> V_31 . V_32 ) ;
struct V_18 * V_18 = V_30 -> V_18 ;
struct V_33 V_34 = { } ;
struct V_1 * V_2 ;
struct V_35 * V_31 = & V_28 -> V_31 ;
int V_4 = V_28 -> V_4 ;
int V_36 , V_37 ;
V_34 . V_31 = V_31 ;
V_34 . V_18 = V_18 ;
V_37 = F_4 ( V_31 -> V_38 , V_4 ) ;
if ( F_8 ( V_37 ) ) {
V_34 . V_37 = V_37 ;
V_34 . V_39 = V_40 ;
V_36 = F_9 ( V_18 , V_41 ,
V_42 ,
V_42 ) ;
if ( V_36 ) {
F_10 ( V_31 , L_3 , V_36 ) ;
return V_36 ;
}
}
V_2 = F_11 ( V_31 , & V_43 [ V_4 ] , & V_34 ) ;
if ( F_12 ( V_2 ) ) {
V_36 = F_13 ( V_2 ) ;
F_10 ( V_31 , L_4 , V_4 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
