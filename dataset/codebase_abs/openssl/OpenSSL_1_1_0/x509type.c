int F_1 ( const T_1 * V_1 , const T_2 * V_2 )
{
const T_2 * V_3 ;
int V_4 = 0 , V_5 ;
if ( V_1 == NULL )
return ( 0 ) ;
if ( V_2 == NULL )
V_3 = F_2 ( V_1 ) ;
else
V_3 = V_2 ;
if ( V_3 == NULL )
return ( 0 ) ;
switch ( F_3 ( V_3 ) ) {
case V_6 :
V_4 = V_7 | V_8 ;
V_4 |= V_9 ;
break;
case V_10 :
V_4 = V_11 | V_8 ;
break;
case V_12 :
V_4 = V_13 | V_8 | V_14 ;
break;
case V_15 :
V_4 = V_16 | V_14 ;
break;
case V_17 :
case V_18 :
case V_19 :
V_4 = V_14 | V_8 ;
break;
default:
break;
}
V_5 = F_4 ( V_1 ) ;
if ( V_5 && F_5 ( V_5 , NULL , & V_5 ) ) {
switch ( V_5 ) {
case V_20 :
case V_21 :
V_4 |= V_22 ;
break;
case V_23 :
case V_24 :
V_4 |= V_25 ;
break;
case V_26 :
V_4 |= V_27 ;
break;
default:
break;
}
}
return ( V_4 ) ;
}
