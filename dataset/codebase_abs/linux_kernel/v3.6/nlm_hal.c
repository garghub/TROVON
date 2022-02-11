void F_1 ( void )
{
V_1 = F_2 ( V_2 ) ;
V_3 = F_3 ( 0 ) ;
V_4 = F_4 ( 0 ) ;
}
int F_5 ( int V_5 )
{
if ( ! F_6 ( V_5 ) )
return - 1 ;
switch ( V_5 ) {
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
default:
return - 1 ;
}
}
int F_7 ( int V_36 )
{
switch ( V_36 ) {
case V_7 :
return V_6 ;
case V_9 :
return V_8 ;
case V_11 :
return V_10 ;
case V_13 :
return V_12 ;
case V_15 :
return V_14 ;
case V_17 :
return V_16 ;
case V_19 :
return V_18 ;
case V_21 :
return V_20 ;
case V_23 :
return V_22 ;
case V_25 :
return V_24 ;
case V_27 :
return V_26 ;
case V_29 :
return V_28 ;
case V_31 :
return V_30 ;
case V_33 :
return V_32 ;
case V_35 :
return V_34 ;
default:
return - 1 ;
}
}
unsigned int F_8 ( int V_37 )
{
unsigned int V_38 , V_39 , V_40 , V_41 ;
unsigned int V_42 , V_43 , V_44 ;
T_1 V_45 ;
V_42 = F_9 ( V_3 , V_46 ) ;
V_43 = F_9 ( V_3 , V_47 ) ;
V_38 = ( ( V_42 >> 10 ) & 0x7f ) + 1 ;
V_39 = ( ( V_42 >> 8 ) & 0x3 ) + 1 ;
V_41 = ( ( V_42 >> 30 ) & 0x3 ) + 1 ;
V_40 = ( ( V_43 >> ( V_37 * 4 ) ) & 0xf ) + 1 ;
V_45 = 800000000ULL * V_38 ;
V_44 = 3 * V_39 * V_41 * V_40 ;
F_10 ( V_45 , V_44 ) ;
return ( unsigned int ) V_45 ;
}
unsigned int F_11 ( void )
{
return F_8 ( 0 ) ;
}
