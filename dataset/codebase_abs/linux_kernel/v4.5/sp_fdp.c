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
V_9 = F_5 ( V_9 ) ;
V_14 ;
case V_18 :
V_10 = F_1 ( V_2 , V_3 ) ;
if ( ! V_19 . V_20 ) {
V_21 ;
if ( ! F_6 ( V_22 ) )
V_10 = F_7 () ;
}
return V_10 ;
case V_23 :
return F_8 ( V_2 ) ;
case V_24 :
return F_9 ( V_2 ) ;
case V_25 :
F_10 ( V_26 ) ;
F_10 ( V_27 ) ;
if ( ( V_19 . V_11 == V_28 && ! V_2 ) ||
( V_19 . V_11 == V_29 && V_2 ) )
return F_11 ( V_2 ) ;
return F_9 ( V_2 ) ;
case V_30 :
break;
}
V_11 = ( V_3 >> ( V_6 - ( V_7 + 3 ) ) ) |
( ( V_3 << ( 64 - ( V_6 - ( V_7 + 3 ) ) ) ) != 0 ) ;
return F_12 ( V_2 , V_31 , V_11 ) ;
}
