static inline union V_1 F_1 ( int V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_4 + 1 + V_5 ,
V_3 << ( V_6 - V_7 ) ) ;
}
union V_1 F_3 ( union V_8 V_9 )
{
V_10 ;
V_11 ;
F_4 () ;
V_12 ;
switch ( V_13 ) {
case V_14 :
return F_5 ( F_1 ( V_2 , V_3 ) ) ;
case V_15 :
return F_1 ( V_2 , V_3 ) ;
case V_16 :
return F_6 ( V_2 ) ;
case V_17 :
return F_7 ( V_2 ) ;
case V_18 :
while ( ( V_3 >> V_7 ) == 0 ) {
V_3 <<= 1 ;
V_19 -- ;
}
break;
case V_20 :
break;
}
V_3 &= ~ V_21 ;
return F_2 ( V_2 , V_19 + V_5 ,
( T_1 ) V_3 << ( V_6 - V_7 ) ) ;
}
