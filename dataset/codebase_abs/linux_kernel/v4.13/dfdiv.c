int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
T_1 * V_3 , unsigned int * V_4 )
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
F_18 ( V_11 , V_12 ) ;
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
if ( F_19 ( V_7 , V_8 ) ) {
if ( F_19 ( V_5 , V_6 ) ) {
if ( F_10 () ) return ( V_19 ) ;
F_11 () ;
F_12 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
if ( F_20 () )
return ( V_21 ) ;
F_21 () ;
F_14 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
V_13 = F_22 ( V_5 ) - F_22 ( V_7 ) + V_22 ;
if ( F_23 ( V_5 ) ) {
F_24 ( V_5 ) ;
}
else {
if ( F_7 ( V_5 , V_6 ) ) {
F_18 ( V_11 , V_12 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
return ( V_20 ) ;
}
F_25 ( V_5 ) ;
F_26 ( V_5 , V_6 ) ;
F_27 ( V_5 , V_6 , V_13 ) ;
}
if ( F_23 ( V_7 ) ) {
F_24 ( V_7 ) ;
}
else {
F_25 ( V_7 ) ;
F_26 ( V_7 , V_8 ) ;
while ( F_28 ( V_7 ) ) {
V_13 += 8 ;
F_29 ( V_7 , V_8 ) ;
}
if ( F_30 ( V_7 ) ) {
V_13 += 4 ;
F_31 ( V_7 , V_8 ) ;
}
while ( F_32 ( V_7 ) ) {
V_13 ++ ;
F_26 ( V_7 , V_8 ) ;
}
}
F_33 ( V_5 , V_6 , V_7 , V_8 ) ;
F_34 ( V_9 , V_10 ) ;
for ( V_14 = 1 ; V_14 <= V_23 && ( V_5 || V_6 ) ; V_14 ++ ) {
F_26 ( V_5 , V_6 ) ;
F_26 ( V_9 , V_10 ) ;
if ( F_35 ( V_5 ) ) {
F_36 ( V_10 ) ;
F_33 ( V_5 , V_6 , V_7 , V_8 ) ;
}
else {
F_37 ( V_5 , V_6 , V_7 , V_8 ) ;
}
}
if ( V_14 <= V_23 ) {
F_26 ( V_9 , V_10 ) ;
F_36 ( V_10 ) ;
F_38 ( V_9 , V_10 , ( V_23 - V_14 ) ) ;
if ( F_32 ( V_9 ) ) {
F_26 ( V_9 , V_10 ) ;
V_13 -- ;
}
}
else {
if ( F_32 ( V_9 ) ) {
F_26 ( V_5 , V_6 ) ;
F_26 ( V_9 , V_10 ) ;
if ( F_35 ( V_5 ) ) {
F_36 ( V_10 ) ;
F_33 ( V_5 , V_6 , V_7 , V_8 ) ;
}
else {
F_37 ( V_5 , V_6 , V_7 , V_8 ) ;
}
V_13 -- ;
}
if ( F_35 ( V_5 ) ) V_16 = TRUE ;
V_17 = F_39 ( V_5 ) || F_40 ( V_6 ) ;
}
V_15 = V_16 | V_17 ;
if ( V_15 && ( V_13 > 0 || F_41 () ) ) {
F_25 ( V_9 ) ;
switch ( F_42 () ) {
case V_24 :
if ( F_35 ( V_11 ) )
F_43 ( V_9 , V_10 ) ;
break;
case V_25 :
if ( F_44 ( V_11 ) )
F_43 ( V_9 , V_10 ) ;
break;
case V_26 :
if ( V_16 && ( V_17 ||
F_45 ( V_10 ) ) ) {
F_43 ( V_9 , V_10 ) ;
}
}
if ( F_46 ( V_9 ) ) V_13 ++ ;
}
F_47 ( V_11 , V_12 , V_9 , V_10 ) ;
if ( V_13 >= V_27 ) {
if ( F_48 () ) {
F_49 ( V_11 , V_13 , V_28 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 )
if ( F_50 () )
return ( V_29 | V_30 ) ;
else F_51 () ;
return ( V_29 ) ;
}
F_52 () ;
F_53 ( V_11 , V_12 ) ;
V_15 = TRUE ;
}
else if ( V_13 <= 0 ) {
if ( F_41 () ) {
F_49 ( V_11 , V_13 , V_31 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 )
if ( F_50 () )
return ( V_32 | V_30 ) ;
else F_51 () ;
return ( V_32 ) ;
}
V_18 = TRUE ;
if ( V_13 == 0 && V_15 ) {
switch ( F_42 () ) {
case V_24 :
if ( F_35 ( V_11 ) ) {
F_43 ( V_9 , V_10 ) ;
if ( F_54 ( V_9 ) )
V_18 = FALSE ;
F_55 ( V_9 , V_10 ) ;
}
break;
case V_25 :
if ( F_44 ( V_11 ) ) {
F_43 ( V_9 , V_10 ) ;
if ( F_54 ( V_9 ) )
V_18 = FALSE ;
F_55 ( V_9 , V_10 ) ;
}
break;
case V_26 :
if ( V_16 && ( V_17 ||
F_45 ( V_10 ) ) ) {
F_43 ( V_9 , V_10 ) ;
if ( F_54 ( V_9 ) )
V_18 = FALSE ;
F_55 ( V_9 , V_10 ) ;
}
break;
}
}
V_17 = V_15 ;
F_56 ( V_9 , V_10 , V_13 , V_16 ,
V_17 , V_15 ) ;
if ( V_15 ) {
switch ( F_42 () ) {
case V_24 :
if ( F_35 ( V_11 ) ) {
F_43 ( V_9 , V_10 ) ;
}
break;
case V_25 :
if ( F_44 ( V_11 ) ) {
F_43 ( V_9 , V_10 ) ;
}
break;
case V_26 :
if ( V_16 && ( V_17 ||
F_45 ( V_10 ) ) ) {
F_43 ( V_9 , V_10 ) ;
}
break;
}
if ( V_18 ) F_57 () ;
}
F_58 ( V_11 , V_12 , V_9 , V_10 ) ;
}
else F_59 ( V_11 , V_13 ) ;
F_13 ( V_11 , V_12 , V_3 ) ;
if ( V_15 ) {
if ( F_50 () ) return ( V_30 ) ;
else F_51 () ;
}
return ( V_20 ) ;
}
