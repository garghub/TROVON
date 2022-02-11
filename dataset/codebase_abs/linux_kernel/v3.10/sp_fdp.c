T_1 F_1 ( T_2 V_1 )
{
V_2 ;
T_1 V_3 ;
V_4 ;
V_5 ;
V_6 ;
switch ( V_7 ) {
case V_8 :
F_2 ( V_9 ) ;
return F_3 ( F_4 () , L_1 ) ;
case V_10 :
V_3 = F_5 ( V_11 , V_12 + 1 + V_13 , ( V_14 )
( V_15 >> ( V_16 - V_17 ) ) ) ;
if ( ! F_6 ( V_3 ) )
V_3 = F_4 () ;
return F_3 ( V_3 , L_1 , V_1 ) ;
case V_18 :
return F_7 ( V_11 ) ;
case V_19 :
return F_8 ( V_11 ) ;
case V_20 :
F_2 ( V_21 ) ;
F_2 ( V_22 ) ;
if ( ( V_23 . V_24 == V_25 && ! V_11 ) ||
( V_23 . V_24 == V_26 && V_11 ) )
return F_9 ( F_10 ( V_11 ) , L_1 , V_1 ) ;
return F_9 ( F_8 ( V_11 ) , L_1 , V_1 ) ;
case V_27 :
break;
}
{
V_14 V_24 ;
V_24 = ( V_15 >> ( V_16 - ( V_17 + 3 ) ) ) |
( ( V_15 << ( 64 - ( V_16 - ( V_17 + 3 ) ) ) ) != 0 ) ;
F_11 ( V_11 , V_28 , V_24 , L_1 , V_1 ) ;
}
}
