union V_1 F_1 ( union V_2 V_3 )
{
V_4 ;
V_5 ;
F_2 () ;
V_6 ;
switch ( V_7 ) {
case V_8 :
F_3 ( V_9 ) ;
return F_4 ( F_5 () ) ;
case V_10 :
return F_4 ( F_6 ( V_11 ,
V_12 + 1 + V_13 ,
( ( V_14 ) V_15
<< ( V_16 -
V_17 ) ) ) ) ;
case V_18 :
return F_7 ( V_11 ) ;
case V_19 :
return F_8 ( V_11 ) ;
case V_20 :
while ( ( V_15 >> V_17 ) == 0 ) {
V_15 <<= 1 ;
V_21 -- ;
}
break;
case V_22 :
break;
}
V_15 &= ~ V_23 ;
return F_6 ( V_11 , V_21 + V_13 ,
( V_14 ) V_15 << ( V_16 - V_17 ) ) ;
}
