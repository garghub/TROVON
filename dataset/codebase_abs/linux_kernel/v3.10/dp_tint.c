int F_1 ( T_1 V_1 )
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
if ( V_14 > 31 ) {
F_2 ( V_10 ) ;
return F_3 ( F_4 () , L_1 , V_1 ) ;
}
if ( V_14 > V_15 ) {
V_16 <<= V_14 - V_15 ;
} else if ( V_14 < V_15 ) {
T_2 V_17 ;
int V_18 ;
int V_19 ;
int V_20 ;
if ( V_14 < - 1 ) {
V_17 = V_16 ;
V_18 = 0 ;
V_19 = V_17 != 0 ;
V_16 = 0 ;
} else {
V_17 = V_16 << ( 64 - V_15 + V_14 ) ;
V_18 = ( V_17 >> 63 ) != 0 ;
V_19 = ( V_17 << 1 ) != 0 ;
V_16 >>= V_15 - V_14 ;
}
V_20 = ( V_16 & 0x1 ) != 0x0 ;
switch ( V_21 . V_22 ) {
case V_23 :
if ( V_18 && ( V_19 || V_20 ) )
V_16 ++ ;
break;
case V_24 :
break;
case V_25 :
if ( ( V_18 || V_19 ) && ! V_26 )
V_16 ++ ;
break;
case V_27 :
if ( ( V_18 || V_19 ) && V_26 )
V_16 ++ ;
break;
}
if ( ( V_16 >> 31 ) != 0 && ( V_26 == 0 || V_16 != 0x80000000 ) ) {
F_2 ( V_10 ) ;
return F_3 ( F_4 () , L_1 , V_1 ) ;
}
if ( V_18 || V_19 )
F_2 ( V_28 ) ;
}
if ( V_26 )
return - V_16 ;
else
return V_16 ;
}
unsigned int F_5 ( T_1 V_1 )
{
T_1 V_29 = F_6 () ;
if ( F_7 ( V_1 , V_29 ) )
return ( unsigned ) F_1 ( V_1 ) ;
return ( unsigned ) F_1 ( F_8 ( V_1 , V_29 ) ) |
( ( unsigned ) 1 << 31 ) ;
}
