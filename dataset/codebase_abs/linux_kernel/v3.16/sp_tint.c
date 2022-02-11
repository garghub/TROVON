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
case V_13 :
F_3 ( V_14 ) ;
return F_4 () ;
case V_15 :
return 0 ;
case V_16 :
case V_17 :
break;
}
if ( V_18 >= 31 ) {
if ( V_18 == 31 && V_19 && V_20 == V_21 )
return - 0x80000000 ;
F_3 ( V_14 ) ;
return F_4 () ;
}
if ( V_18 > V_22 ) {
V_20 <<= V_18 - V_22 ;
} else {
if ( V_18 < - 1 ) {
V_3 = V_20 ;
V_4 = 0 ;
V_5 = V_3 != 0 ;
V_20 = 0 ;
} else {
V_3 = V_20 << ( V_18 + 1 ) ;
V_3 <<= 31 - V_22 ;
V_4 = ( V_3 >> 31 ) != 0 ;
V_5 = ( V_3 << 1 ) != 0 ;
V_20 >>= V_22 - V_18 ;
}
V_6 = ( V_20 & 0x1 ) != 0x0 ;
switch ( V_23 . V_24 ) {
case V_25 :
if ( V_4 && ( V_5 || V_6 ) )
V_20 ++ ;
break;
case V_26 :
break;
case V_27 :
if ( ( V_4 || V_5 ) && ! V_19 )
V_20 ++ ;
break;
case V_28 :
if ( ( V_4 || V_5 ) && V_19 )
V_20 ++ ;
break;
}
if ( ( V_20 >> 31 ) != 0 ) {
F_3 ( V_14 ) ;
return F_4 () ;
}
if ( V_4 || V_5 )
F_3 ( V_29 ) ;
}
if ( V_19 )
return - V_20 ;
else
return V_20 ;
}
