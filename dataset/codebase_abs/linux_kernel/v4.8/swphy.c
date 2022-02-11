static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case 1000 :
return V_2 ;
case 100 :
return V_3 ;
case 10 :
return V_4 ;
default:
return - V_5 ;
}
}
int F_2 ( const struct V_6 * V_7 )
{
int V_8 ;
if ( V_7 -> V_9 ) {
V_8 = F_1 ( V_7 -> V_1 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 ) ;
return - V_5 ;
}
}
return 0 ;
}
int F_4 ( int V_10 , const struct V_6 * V_7 )
{
int V_11 , V_12 ;
T_1 V_13 = V_14 ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
if ( V_10 > V_18 )
return - 1 ;
V_11 = F_1 ( V_7 -> V_1 ) ;
if ( F_5 ( V_11 < 0 ) )
return 0 ;
V_12 = V_7 -> V_19 ? V_20 : V_21 ;
V_13 |= V_1 [ V_11 ] . V_13 & V_19 [ V_12 ] . V_13 ;
if ( V_7 -> V_9 ) {
V_13 |= V_22 | V_23 ;
V_15 |= V_1 [ V_11 ] . V_15 & V_19 [ V_12 ] . V_15 ;
V_17 |= V_1 [ V_11 ] . V_17 & V_19 [ V_12 ] . V_17 ;
V_16 |= V_1 [ V_11 ] . V_16 & V_19 [ V_12 ] . V_16 ;
if ( V_7 -> V_24 )
V_17 |= V_25 ;
if ( V_7 -> V_26 )
V_17 |= V_27 ;
}
switch ( V_10 ) {
case V_28 :
return V_15 ;
case V_29 :
return V_13 ;
case V_30 :
case V_31 :
return 0 ;
case V_32 :
return V_17 ;
case V_33 :
return V_16 ;
case V_34 :
case V_35 :
return - 1 ;
default:
return 0xffff ;
}
}
