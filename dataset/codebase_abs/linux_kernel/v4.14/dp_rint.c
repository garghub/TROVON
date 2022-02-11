union V_1 F_1 ( union V_1 V_2 )
{
union V_1 V_3 ;
T_1 V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
V_8 ;
F_2 () ;
V_9 ;
V_10 ;
if ( V_11 == V_12 )
return F_3 ( V_2 ) ;
if ( ( V_11 == V_13 ) ||
( V_11 == V_14 ) ||
( V_11 == V_15 ) )
return V_2 ;
if ( V_16 >= V_17 )
return V_2 ;
if ( V_16 < - 1 ) {
V_4 = V_18 ;
V_6 = 0 ;
V_5 = V_4 != 0 ;
V_18 = 0 ;
} else {
V_4 = V_18 << ( 64 - V_17 + V_16 ) ;
V_6 = ( V_4 >> 63 ) != 0 ;
V_5 = ( V_4 << 1 ) != 0 ;
V_18 >>= V_17 - V_16 ;
}
V_7 = ( V_18 & 0x1 ) != 0x0 ;
switch ( V_19 . V_20 ) {
case V_21 :
if ( V_6 && ( V_5 || V_7 ) )
V_18 ++ ;
break;
case V_22 :
break;
case V_23 :
if ( ( V_6 || V_5 ) && ! V_24 )
V_18 ++ ;
break;
case V_25 :
if ( ( V_6 || V_5 ) && V_24 )
V_18 ++ ;
break;
}
if ( V_6 || V_5 )
F_4 ( V_26 ) ;
V_3 = F_5 ( V_18 ) ;
F_6 ( V_3 ) = V_24 ;
return V_3 ;
}
