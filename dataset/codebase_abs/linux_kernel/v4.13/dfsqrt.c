unsigned int
F_1 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 , V_8 ;
register unsigned int V_9 , V_10 , V_11 , V_12 ;
register int V_13 ;
register boolean V_14 = FALSE , V_15 ;
F_2 ( V_1 , V_5 , V_6 ) ;
if ( ( V_13 = F_3 ( V_5 ) ) == V_16 ) {
if ( F_4 ( V_5 ) ) {
if ( F_5 () ) return ( V_17 ) ;
F_6 () ;
F_7 ( V_5 ) ;
}
if ( F_8 ( V_5 ) ||
F_9 ( V_5 , V_6 ) ) {
F_10 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
}
if ( F_11 ( V_5 , V_6 ) ) {
F_10 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
if ( F_12 ( V_5 ) ) {
if ( F_5 () ) return ( V_17 ) ;
F_6 () ;
F_13 ( V_5 , V_6 ) ;
F_10 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
if ( V_13 > 0 ) {
V_15 = F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
}
else {
F_16 ( V_5 ) ;
V_13 ++ ;
F_17 ( V_5 , V_6 , V_13 ) ;
V_15 = V_13 & 1 ;
}
if ( V_15 ) {
F_18 ( V_5 , V_6 ) ;
}
F_19 ( V_7 , V_8 ) ;
F_20 ( V_9 ) = 1 << ( V_19 - 32 ) ;
F_21 ( V_10 ) ;
while ( F_22 ( V_9 , V_10 ) && F_22 ( V_5 , V_6 ) ) {
F_23 ( V_7 , V_8 , V_9 , V_10 , V_11 , V_12 ) ;
if( F_24 ( V_11 , V_12 , V_5 , V_6 ) ) {
F_18 ( V_9 , V_10 ) ;
F_23 ( V_7 , V_8 , V_9 , V_10 ,
V_7 , V_8 ) ;
F_25 ( V_5 , V_6 , V_11 , V_12 , V_5 , V_6 ) ;
F_26 ( V_9 , V_10 ) ;
}
else {
F_27 ( V_9 , V_10 ) ;
}
F_18 ( V_5 , V_6 ) ;
}
if ( V_15 ) {
F_27 ( V_7 , V_8 ) ;
}
if ( F_22 ( V_5 , V_6 ) ) {
if ( ! V_15 && F_28 ( V_7 , V_8 , V_5 , V_6 ) ) {
F_29 ( V_7 , V_8 ) ;
}
V_14 = F_30 ( V_8 ) ;
F_27 ( V_7 , V_8 ) ;
switch ( F_31 () ) {
case V_20 :
F_29 ( V_7 , V_8 ) ;
break;
case V_21 :
if ( V_14 ) {
F_29 ( V_7 , V_8 ) ;
}
break;
}
if ( F_32 ( V_7 ) ) V_13 += 2 ;
if ( F_33 () ) {
F_34 ( V_7 ,
( ( V_13 - V_22 ) >> 1 ) + V_22 ) ;
F_10 ( V_7 , V_8 , V_3 ) ;
return ( V_23 ) ;
}
else F_35 () ;
}
else {
F_27 ( V_7 , V_8 ) ;
}
F_34 ( V_7 , ( ( V_13 - V_22 ) >> 1 ) + V_22 ) ;
F_10 ( V_7 , V_8 , V_3 ) ;
return ( V_18 ) ;
}
