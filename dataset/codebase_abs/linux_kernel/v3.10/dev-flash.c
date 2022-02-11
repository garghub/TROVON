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
V_1 = F_4 ( V_12 ) ;
if ( V_1 & V_13 )
return V_10 ;
else
return V_5 ;
case V_14 :
V_1 = F_3 ( V_15 ) ;
if ( V_1 & V_16 )
return V_5 ;
else
return V_6 ;
case V_17 :
V_1 = F_4 ( V_12 ) ;
switch ( V_1 & V_18 ) {
case V_19 :
return V_6 ;
case V_20 :
return V_5 ;
case V_21 :
return V_10 ;
}
default:
return - V_22 ;
}
}
int T_1 F_5 ( void )
{
int V_23 ;
T_2 V_1 ;
V_23 = F_1 () ;
switch ( V_23 ) {
case V_10 :
V_1 = F_6 ( F_7 ( 0 ) ) ;
V_1 &= V_24 ;
V_25 [ 0 ] . V_26 = V_1 ;
V_25 [ 0 ] . V_27 = 0x1FFFFFFF ;
return F_8 ( & V_28 ) ;
case V_5 :
F_9 ( L_1 ) ;
return - V_29 ;
case V_6 :
F_9 ( L_2 ) ;
return - V_29 ;
default:
F_10 ( L_3 ,
F_2 () , V_23 ) ;
return - V_29 ;
}
}
