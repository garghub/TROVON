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
V_1 = F_4 ( V_12 ) ;
switch ( V_1 & V_15 ) {
case V_16 :
return V_6 ;
case V_17 :
return V_5 ;
case V_18 :
return V_10 ;
}
default:
return - V_19 ;
}
}
int T_1 F_5 ( void )
{
int V_20 ;
T_2 V_1 ;
V_20 = F_1 () ;
switch ( V_20 ) {
case V_10 :
V_1 = F_6 ( F_7 ( 0 ) ) ;
V_1 &= V_21 ;
V_22 [ 0 ] . V_23 = V_1 ;
V_22 [ 0 ] . V_24 = 0x1FFFFFFF ;
return F_8 ( & V_25 ) ;
case V_5 :
F_9 ( L_1 ) ;
return - V_26 ;
case V_6 :
F_9 ( L_2 ) ;
return - V_26 ;
default:
F_10 ( L_3 ,
F_2 () , V_20 ) ;
return - V_26 ;
}
}
