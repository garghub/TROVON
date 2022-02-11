static inline union V_1 F_1 ( int V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_4 + 1 + V_5 ,
V_3 >> ( V_6 - V_7 ) ) ;
}
union V_1 F_3 ( union V_8 V_9 )
{
union V_1 V_10 ;
T_2 V_11 ;
V_12 ;
V_13 ;
V_14 ;
F_4 () ;
V_15 ;
switch ( V_16 ) {
case V_17 :
return F_5 ( F_1 ( V_2 , V_3 ) ) ;
case V_18 :
V_10 = F_1 ( V_2 , V_3 ) ;
V_19 ;
if ( ! F_6 ( V_20 ) )
V_10 = F_7 () ;
return V_10 ;
case V_21 :
return F_8 ( V_2 ) ;
case V_22 :
return F_9 ( V_2 ) ;
case V_23 :
F_10 ( V_24 ) ;
F_10 ( V_25 ) ;
if ( ( V_26 . V_11 == V_27 && ! V_2 ) ||
( V_26 . V_11 == V_28 && V_2 ) )
return F_11 ( V_2 ) ;
return F_9 ( V_2 ) ;
case V_29 :
break;
}
V_11 = ( V_3 >> ( V_6 - ( V_7 + 3 ) ) ) |
( ( V_3 << ( 64 - ( V_6 - ( V_7 + 3 ) ) ) ) != 0 ) ;
return F_12 ( V_2 , V_30 , V_11 ) ;
}
