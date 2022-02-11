int F_1 ( union V_1 V_2 )
{
T_1 V_3 ;
int V_4 ;
int V_5 ;
int V_6 ;
V_7 ;
F_2 () ;
V_8 ;
V_9 ;
switch ( V_10 ) {
case V_11 :
case V_12 :
F_3 ( V_13 ) ;
return F_4 () ;
case V_14 :
F_3 ( V_13 ) ;
return F_5 ( V_15 ) ;
case V_16 :
return 0 ;
case V_17 :
case V_18 :
break;
}
if ( V_19 > 31 ) {
F_3 ( V_13 ) ;
return F_5 ( V_15 ) ;
}
if ( V_19 > V_20 ) {
V_21 <<= V_19 - V_20 ;
} else if ( V_19 < V_20 ) {
if ( V_19 < - 1 ) {
V_3 = V_21 ;
V_4 = 0 ;
V_5 = V_3 != 0 ;
V_21 = 0 ;
} else {
V_3 = V_21 << ( 64 - V_20 + V_19 ) ;
V_4 = ( V_3 >> 63 ) != 0 ;
V_5 = ( V_3 << 1 ) != 0 ;
V_21 >>= V_20 - V_19 ;
}
V_6 = ( V_21 & 0x1 ) != 0x0 ;
switch ( V_22 . V_23 ) {
case V_24 :
if ( V_4 && ( V_5 || V_6 ) )
V_21 ++ ;
break;
case V_25 :
break;
case V_26 :
if ( ( V_4 || V_5 ) && ! V_15 )
V_21 ++ ;
break;
case V_27 :
if ( ( V_4 || V_5 ) && V_15 )
V_21 ++ ;
break;
}
if ( ( V_21 >> 31 ) != 0 && ( V_15 == 0 || V_21 != 0x80000000 ) ) {
F_3 ( V_13 ) ;
return F_5 ( V_15 ) ;
}
if ( V_4 || V_5 )
F_3 ( V_28 ) ;
}
if ( V_15 )
return - V_21 ;
else
return V_21 ;
}
