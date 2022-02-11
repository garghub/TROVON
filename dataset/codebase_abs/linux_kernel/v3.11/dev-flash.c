static int T_1 F_1 ( void )
{
T_2 V_1 ;
switch ( F_2 () ) {
case V_2 :
V_1 = F_3 ( V_3 ) ;
if ( V_1 & V_4 )
return V_5 ;
else
return V_6 ;
case V_7 :
case V_8 :
case V_9 :
return V_10 ;
case V_11 :
case V_12 :
V_1 = F_4 ( V_13 ) ;
if ( V_1 & V_14 )
return V_10 ;
else
return V_5 ;
case V_15 :
V_1 = F_3 ( V_16 ) ;
if ( V_1 & V_17 )
return V_5 ;
else
return V_6 ;
case V_18 :
V_1 = F_4 ( V_13 ) ;
switch ( V_1 & V_19 ) {
case V_20 :
return V_6 ;
case V_21 :
return V_5 ;
case V_22 :
return V_10 ;
}
default:
return - V_23 ;
}
}
int T_1 F_5 ( void )
{
int V_24 ;
T_2 V_1 ;
V_24 = F_1 () ;
switch ( V_24 ) {
case V_10 :
V_1 = F_6 ( F_7 ( 0 ) ) ;
V_1 &= V_25 ;
V_26 [ 0 ] . V_27 = V_1 ;
V_26 [ 0 ] . V_28 = 0x1FFFFFFF ;
return F_8 ( & V_29 ) ;
case V_5 :
F_9 ( L_1 ) ;
return - V_30 ;
case V_6 :
F_9 ( L_2 ) ;
return - V_30 ;
default:
F_10 ( L_3 ,
F_2 () , V_24 ) ;
return - V_30 ;
}
}
