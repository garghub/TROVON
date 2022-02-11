T_1 F_1 ( T_2 V_1 )
{
V_2 ;
V_3 ;
V_4 ;
V_5 ;
switch ( V_6 ) {
case V_7 :
F_2 ( V_8 ) ;
return F_3 ( F_4 () , L_1 ) ;
case V_9 :
return F_3 ( F_5 ( V_10 ,
V_11 + 1 + V_12 ,
( ( V_13 ) V_14
<< ( V_15 -
V_16 ) ) ) , L_1 ,
V_1 ) ;
case V_17 :
return F_6 ( V_10 ) ;
case V_18 :
return F_7 ( V_10 ) ;
case V_19 :
while ( ( V_14 >> V_16 ) == 0 ) {
V_14 <<= 1 ;
V_20 -- ;
}
break;
case V_21 :
break;
}
V_14 &= ~ V_22 ;
return F_5 ( V_10 , V_20 + V_12 ,
( V_13 ) V_14 << ( V_15 - V_16 ) ) ;
}
