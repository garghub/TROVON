T_1 F_1 ( T_2 V_1 )
{
V_2 ;
V_3 ;
V_4 ;
V_5 ;
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
F_2 ( V_10 ) ;
return F_3 ( F_4 () , L_1 , V_1 ) ;
case V_11 :
return 0 ;
case V_12 :
case V_13 :
break;
}
if ( V_14 >= 63 ) {
if ( V_14 == 63 && V_15 && V_16 == V_17 )
return - 0x8000000000000000LL ;
F_2 ( V_10 ) ;
return F_3 ( F_4 () , L_1 , V_1 ) ;
}
if ( V_14 > V_18 ) {
V_16 <<= V_14 - V_18 ;
} else if ( V_14 < V_18 ) {
T_3 V_19 ;
int V_20 ;
int V_21 ;
int V_22 ;
if ( V_14 < - 1 ) {
V_19 = V_16 ;
V_20 = 0 ;
V_21 = V_19 != 0 ;
V_16 = 0 ;
} else {
V_19 = V_16 << ( 32 - V_18 + V_14 ) ;
V_20 = ( V_19 >> 31 ) != 0 ;
V_21 = ( V_19 << 1 ) != 0 ;
V_16 >>= V_18 - V_14 ;
}
V_22 = ( V_16 & 0x1 ) != 0x0 ;
switch ( V_23 . V_24 ) {
case V_25 :
if ( V_20 && ( V_21 || V_22 ) )
V_16 ++ ;
break;
case V_26 :
break;
case V_27 :
if ( ( V_20 || V_21 ) && ! V_15 )
V_16 ++ ;
break;
case V_28 :
if ( ( V_20 || V_21 ) && V_15 )
V_16 ++ ;
break;
}
if ( ( V_16 >> 63 ) != 0 ) {
F_2 ( V_10 ) ;
return F_3 ( F_4 () , L_1 , V_1 ) ;
}
if ( V_20 || V_21 )
F_2 ( V_29 ) ;
}
if ( V_15 )
return - V_16 ;
else
return V_16 ;
}
T_4 F_5 ( T_2 V_1 )
{
T_2 V_30 = F_6 () ;
if ( F_7 ( V_1 , V_30 ) )
return ( T_4 ) F_1 ( V_1 ) ;
return ( T_4 ) F_1 ( F_8 ( V_1 , V_30 ) ) |
( 1ULL << 63 ) ;
}
