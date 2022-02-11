int
F_1 (
T_1 * V_1 ,
T_1 * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 , V_8 ;
register unsigned int V_9 , V_10 , V_11 , V_12 ;
register int V_13 , V_14 ;
register boolean V_15 = FALSE , V_16 = FALSE , V_17 = FALSE ;
boolean V_18 ;
F_2 ( V_1 , V_5 , V_6 ) ;
F_2 ( V_2 , V_7 , V_8 ) ;
if ( F_3 ( V_5 ) ^ F_3 ( V_7 ) )
F_4 ( V_11 ) ;
else F_5 ( V_11 ) ;
if ( F_6 ( V_5 ) ) {
if ( F_7 ( V_5 , V_6 ) ) {
if ( F_8 ( V_7 , V_8 ) ) {
if ( F_9 ( V_7 , V_8 ) ) {
if ( F_10 () )
return ( V_19 ) ;
F_11 () ;
F_12 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
F_14 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
}
else {
if ( F_15 ( V_5 ) ) {
if ( F_10 () )
return ( V_19 ) ;
F_11 () ;
F_16 ( V_5 ) ;
}
else if ( F_17 ( V_7 ) ) {
if ( F_10 () )
return ( V_19 ) ;
F_11 () ;
F_16 ( V_7 ) ;
F_13 ( V_7 , V_8 , V_3 ) ;
return ( V_20 ) ;
}
F_13 ( V_5 , V_6 , V_3 ) ;
return ( V_20 ) ;
}
}
if ( F_6 ( V_7 ) ) {
if ( F_7 ( V_7 , V_8 ) ) {
if ( F_9 ( V_5 , V_6 ) ) {
if ( F_10 () )
return ( V_19 ) ;
F_11 () ;
F_12 ( V_7 , V_8 ) ;
F_13 ( V_7 , V_8 , V_3 ) ;
return ( V_20 ) ;
}
F_14 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
if ( F_15 ( V_7 ) ) {
if ( F_10 () ) return ( V_19 ) ;
F_11 () ;
F_16 ( V_7 ) ;
}
F_13 ( V_7 , V_8 , V_3 ) ;
return ( V_20 ) ;
}
V_13 = F_18 ( V_5 ) + F_18 ( V_7 ) - V_21 ;
if ( F_19 ( V_5 ) ) {
F_20 ( V_5 ) ;
}
else {
if ( F_7 ( V_5 , V_6 ) ) {
F_21 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
F_22 ( V_5 ) ;
F_23 ( V_5 , V_6 ) ;
F_24 ( V_5 , V_6 , V_13 ) ;
}
if ( F_19 ( V_7 ) ) {
F_20 ( V_7 ) ;
}
else {
if ( F_7 ( V_7 , V_8 ) ) {
F_21 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
F_22 ( V_7 ) ;
F_23 ( V_7 , V_8 ) ;
F_24 ( V_7 , V_8 , V_13 ) ;
}
F_25 ( V_7 , V_8 ) ;
F_26 ( V_9 , V_10 ) ;
for ( V_14 = 1 ; V_14 <= V_22 ; V_14 += 4 ) {
V_17 |= F_27 ( V_10 ) ;
F_28 ( V_9 , V_10 ) ;
if ( F_29 ( V_6 ) ) {
F_30 ( V_9 , V_10 , V_7 << 3 | V_8 >> 29 ,
V_8 << 3 ) ;
}
if ( F_31 ( V_6 ) ) {
F_30 ( V_9 , V_10 , V_7 << 2 | V_8 >> 30 ,
V_8 << 2 ) ;
}
if ( F_32 ( V_6 ) ) {
F_30 ( V_9 , V_10 , V_7 << 1 | V_8 >> 31 ,
V_8 << 1 ) ;
}
if ( F_33 ( V_6 ) ) {
F_30 ( V_9 , V_10 , V_7 , V_8 ) ;
}
F_28 ( V_5 , V_6 ) ;
}
if ( F_34 ( V_9 ) == 0 ) {
F_23 ( V_9 , V_10 ) ;
}
else {
V_13 ++ ;
}
while ( F_34 ( V_9 ) == 0 ) {
F_23 ( V_9 , V_10 ) ;
V_13 -- ;
}
V_17 |= F_35 ( V_10 ) << 25 ;
V_16 = ( F_35 ( V_10 ) << 24 ) >> 31 ;
V_15 = V_16 | V_17 ;
F_36 ( V_9 , V_10 ) ;
if ( V_15 && ( V_13 > 0 || F_37 () ) ) {
F_22 ( V_9 ) ;
switch ( F_38 () ) {
case V_23 :
if ( F_39 ( V_11 ) )
F_40 ( V_9 , V_10 ) ;
break;
case V_24 :
if ( F_41 ( V_11 ) )
F_40 ( V_9 , V_10 ) ;
break;
case V_25 :
if ( V_16 ) {
if ( V_17 || F_42 ( V_10 ) )
F_40 ( V_9 , V_10 ) ;
}
}
if ( F_43 ( V_9 ) ) V_13 ++ ;
}
F_44 ( V_11 , V_12 , V_9 , V_10 ) ;
if ( V_13 >= V_26 ) {
if ( F_45 () ) {
F_46 ( V_11 , V_13 , V_27 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 )
if ( F_47 () )
return ( V_28 | V_29 ) ;
else F_48 () ;
return ( V_28 ) ;
}
V_15 = TRUE ;
F_49 () ;
F_50 ( V_11 , V_12 ) ;
}
else if ( V_13 <= 0 ) {
if ( F_37 () ) {
F_46 ( V_11 , V_13 , V_30 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 )
if ( F_47 () )
return ( V_31 | V_29 ) ;
else F_48 () ;
return ( V_31 ) ;
}
V_18 = TRUE ;
if ( V_13 == 0 && V_15 ) {
switch ( F_38 () ) {
case V_23 :
if ( F_39 ( V_11 ) ) {
F_40 ( V_9 , V_10 ) ;
if ( F_51 ( V_9 ) )
V_18 = FALSE ;
F_52 ( V_9 , V_10 ) ;
}
break;
case V_24 :
if ( F_41 ( V_11 ) ) {
F_40 ( V_9 , V_10 ) ;
if ( F_51 ( V_9 ) )
V_18 = FALSE ;
F_52 ( V_9 , V_10 ) ;
}
break;
case V_25 :
if ( V_16 && ( V_17 ||
F_42 ( V_10 ) ) ) {
F_40 ( V_9 , V_10 ) ;
if ( F_51 ( V_9 ) )
V_18 = FALSE ;
F_52 ( V_9 , V_10 ) ;
}
break;
}
}
V_17 = V_15 ;
F_53 ( V_9 , V_10 , V_13 , V_16 ,
V_17 , V_15 ) ;
if ( V_15 ) {
switch ( F_38 () ) {
case V_23 :
if ( F_39 ( V_11 ) ) {
F_40 ( V_9 , V_10 ) ;
}
break;
case V_24 :
if ( F_41 ( V_11 ) ) {
F_40 ( V_9 , V_10 ) ;
}
break;
case V_25 :
if ( V_16 && ( V_17 ||
F_42 ( V_10 ) ) ) {
F_40 ( V_9 , V_10 ) ;
}
break;
}
if ( V_18 ) F_54 () ;
}
F_55 ( V_11 , V_12 , V_9 , V_10 ) ;
}
else F_56 ( V_11 , V_13 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 ) {
if ( F_47 () ) return ( V_29 ) ;
else F_48 () ;
}
return ( V_20 ) ;
}
