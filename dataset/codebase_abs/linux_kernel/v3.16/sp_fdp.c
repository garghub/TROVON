union V_1 F_1 ( union V_2 V_3 )
{
T_1 V_4 ;
V_5 ;
union V_1 V_6 ;
V_7 ;
F_2 () ;
V_8 ;
switch ( V_9 ) {
case V_10 :
F_3 ( V_11 ) ;
return F_4 ( F_5 () ) ;
case V_12 :
V_6 = F_6 ( V_13 , V_14 + 1 + V_15 , ( T_1 )
( V_16 >> ( V_17 - V_18 ) ) ) ;
if ( ! F_7 ( V_6 ) )
V_6 = F_5 () ;
return F_4 ( V_6 ) ;
case V_19 :
return F_8 ( V_13 ) ;
case V_20 :
return F_9 ( V_13 ) ;
case V_21 :
F_3 ( V_22 ) ;
F_3 ( V_23 ) ;
if ( ( V_24 . V_4 == V_25 && ! V_13 ) ||
( V_24 . V_4 == V_26 && V_13 ) )
return F_10 ( V_13 ) ;
return F_9 ( V_13 ) ;
case V_27 :
break;
}
V_4 = ( V_16 >> ( V_17 - ( V_18 + 3 ) ) ) |
( ( V_16 << ( 64 - ( V_17 - ( V_18 + 3 ) ) ) ) != 0 ) ;
return F_11 ( V_13 , V_28 , V_4 ) ;
}
