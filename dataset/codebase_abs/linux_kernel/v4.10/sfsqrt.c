unsigned int
F_1 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 ;
register unsigned int V_8 , V_9 ;
register boolean V_10 = FALSE , V_11 ;
V_5 = * V_1 ;
if ( ( V_7 = F_2 ( V_5 ) ) == V_12 ) {
if ( F_3 ( V_5 ) ) {
if ( F_4 () ) return ( V_13 ) ;
F_5 () ;
F_6 ( V_5 ) ;
}
if ( F_7 ( V_5 ) || F_8 ( V_5 ) ) {
* V_3 = V_5 ;
return ( V_14 ) ;
}
}
if ( F_9 ( V_5 ) ) {
* V_3 = V_5 ;
return ( V_14 ) ;
}
if ( F_10 ( V_5 ) ) {
if ( F_4 () ) return ( V_13 ) ;
F_5 () ;
F_11 ( V_5 ) ;
* V_3 = V_5 ;
return ( V_14 ) ;
}
if ( V_7 > 0 ) {
V_11 = F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
else {
F_14 ( V_5 ) ;
V_7 ++ ;
F_15 ( V_5 , V_7 ) ;
V_11 = V_7 & 1 ;
}
if ( V_11 ) {
F_16 ( V_5 ) ;
}
F_17 ( V_6 ) ;
V_8 = 1 << V_15 ;
while ( V_8 && F_18 ( V_5 ) ) {
F_19 ( V_6 , V_8 , V_9 ) ;
if( V_9 <= F_20 ( V_5 ) ) {
F_19 ( V_6 , ( V_8 << 1 ) , V_6 ) ;
F_21 ( V_5 , V_9 , V_5 ) ;
}
F_22 ( V_8 ) ;
F_16 ( V_5 ) ;
}
if ( V_11 ) {
F_22 ( V_6 ) ;
}
if ( F_18 ( V_5 ) ) {
if ( ! V_11 && F_23 ( V_6 , V_5 ) )
F_24 ( V_6 ) ;
V_10 = F_25 ( V_6 ) ;
F_22 ( V_6 ) ;
switch ( F_26 () ) {
case V_16 :
F_24 ( V_6 ) ;
break;
case V_17 :
if ( V_10 ) {
F_24 ( V_6 ) ;
}
break;
}
if ( F_27 ( V_6 ) ) V_7 += 2 ;
if ( F_28 () ) {
F_29 ( V_6 ,
( ( V_7 - V_18 ) >> 1 ) + V_18 ) ;
* V_3 = V_6 ;
return ( V_19 ) ;
}
else F_30 () ;
}
else {
F_22 ( V_6 ) ;
}
F_29 ( V_6 , ( ( V_7 - V_18 ) >> 1 ) + V_18 ) ;
* V_3 = V_6 ;
return ( V_14 ) ;
}
