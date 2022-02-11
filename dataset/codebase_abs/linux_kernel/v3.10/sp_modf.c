T_1 F_1 ( T_1 V_1 , T_1 * V_2 )
{
V_3 ;
V_4 ;
V_5 ;
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
* V_2 = V_1 ;
return V_1 ;
case V_11 :
* V_2 = F_2 ( V_12 ) ;
return V_1 ;
case V_13 :
break;
}
if ( V_14 < 0 ) {
* V_2 = F_2 ( V_12 ) ;
return V_1 ;
}
if ( V_14 >= V_15 ) {
* V_2 = V_1 ;
return F_2 ( V_12 ) ;
}
* V_2 = F_3 ( V_12 , V_14 + V_16 ,
( ( V_17 >> ( V_15 - V_14 ) ) << ( V_15 - V_14 ) ) &
~ V_18 ) ;
V_17 = ( V_17 << ( 32 - ( V_15 - V_14 ) ) ) >> ( 32 - ( V_15 - V_14 ) ) ;
if ( V_17 == 0 )
return F_2 ( V_12 ) ;
while ( ( V_17 >> V_15 ) == 0 ) {
V_17 <<= 1 ;
V_14 -- ;
}
return F_3 ( V_12 , V_14 + V_16 , V_17 & ~ V_18 ) ;
}
