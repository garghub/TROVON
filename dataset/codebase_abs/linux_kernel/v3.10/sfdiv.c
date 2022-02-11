int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
T_1 * V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 , V_8 ;
register int V_9 , V_10 ;
register boolean V_11 = FALSE , V_12 = FALSE , V_13 = FALSE ;
boolean V_14 ;
V_5 = * V_1 ;
V_6 = * V_2 ;
if ( F_2 ( V_5 ) ^ F_2 ( V_6 ) ) F_3 ( V_8 ) ;
else F_4 ( V_8 ) ;
if ( F_5 ( V_5 ) ) {
if ( F_6 ( V_5 ) ) {
if ( F_7 ( V_6 ) ) {
if ( F_8 ( V_6 ) ) {
if ( F_9 () )
return ( V_15 ) ;
F_10 () ;
F_11 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
F_12 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
}
else {
if ( F_13 ( V_5 ) ) {
if ( F_9 () )
return ( V_15 ) ;
F_10 () ;
F_14 ( V_5 ) ;
}
else if ( F_15 ( V_6 ) ) {
if ( F_9 () )
return ( V_15 ) ;
F_10 () ;
F_14 ( V_6 ) ;
* V_3 = V_6 ;
return ( V_16 ) ;
}
* V_3 = V_5 ;
return ( V_16 ) ;
}
}
if ( F_5 ( V_6 ) ) {
if ( F_6 ( V_6 ) ) {
F_16 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
if ( F_13 ( V_6 ) ) {
if ( F_9 () ) return ( V_15 ) ;
F_10 () ;
F_14 ( V_6 ) ;
}
* V_3 = V_6 ;
return ( V_16 ) ;
}
if ( F_17 ( V_6 ) ) {
if ( F_17 ( V_5 ) ) {
if ( F_9 () ) return ( V_15 ) ;
F_10 () ;
F_11 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
if ( F_18 () )
return ( V_17 ) ;
F_19 () ;
F_12 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
V_9 = F_20 ( V_5 ) - F_20 ( V_6 ) + V_18 ;
if ( F_21 ( V_5 ) ) {
F_22 ( V_5 ) ;
}
else {
if ( F_6 ( V_5 ) ) {
F_16 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
F_23 ( V_5 ) ;
F_24 ( V_5 ) ;
F_25 ( V_5 , V_9 ) ;
}
if ( F_21 ( V_6 ) ) {
F_22 ( V_6 ) ;
}
else {
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
while( F_26 ( V_6 ) ) {
F_27 ( V_6 ) ;
V_9 += 8 ;
}
if( F_28 ( V_6 ) ) {
F_29 ( V_6 ) ;
V_9 += 4 ;
}
while( F_30 ( V_6 ) ) {
F_24 ( V_6 ) ;
V_9 += 1 ;
}
}
F_31 ( V_5 , V_6 , V_5 ) ;
F_4 ( V_7 ) ;
for ( V_10 = 1 ; V_10 <= V_19 && F_32 ( V_5 ) ; V_10 ++ ) {
F_24 ( V_5 ) ;
F_24 ( V_7 ) ;
if ( F_33 ( V_5 ) ) {
F_34 ( V_7 ) ;
F_31 ( V_5 , V_6 , V_5 ) ;
}
else F_35 ( V_5 , V_6 , V_5 ) ;
}
if ( V_10 <= V_19 ) {
F_24 ( V_7 ) ;
F_34 ( V_7 ) ;
F_36 ( V_7 , V_19 - V_10 ) ;
if ( F_30 ( V_7 ) ) {
F_24 ( V_7 ) ;
V_9 -- ;
}
}
else {
if ( F_30 ( V_7 ) ) {
F_24 ( V_5 ) ;
F_24 ( V_7 ) ;
if ( F_33 ( V_5 ) ) {
F_34 ( V_7 ) ;
F_31 ( V_5 , V_6 , V_5 ) ;
}
else F_35 ( V_5 , V_6 , V_5 ) ;
V_9 -- ;
}
if ( F_33 ( V_5 ) ) V_12 = TRUE ;
V_13 = F_32 ( V_5 ) ;
}
V_11 = V_12 | V_13 ;
if ( V_11 && ( V_9 > 0 || F_37 () ) ) {
F_23 ( V_7 ) ;
switch ( F_38 () ) {
case V_20 :
if ( F_33 ( V_8 ) )
F_39 ( V_7 ) ;
break;
case V_21 :
if ( F_40 ( V_8 ) )
F_39 ( V_7 ) ;
break;
case V_22 :
if ( V_12 ) {
if ( V_13 || F_41 ( V_7 ) )
F_39 ( V_7 ) ;
}
}
if ( F_42 ( V_7 ) ) V_9 ++ ;
}
F_43 ( V_8 , V_7 ) ;
if ( V_9 >= V_23 ) {
if ( F_44 () ) {
F_45 ( V_8 , V_9 , V_24 ) ;
* V_3 = V_8 ;
if ( V_11 )
if ( F_46 () )
return ( V_25 | V_26 ) ;
else F_47 () ;
return ( V_25 ) ;
}
F_48 () ;
F_49 ( V_8 ) ;
V_11 = TRUE ;
}
else if ( V_9 <= 0 ) {
if ( F_37 () ) {
F_45 ( V_8 , V_9 , V_27 ) ;
* V_3 = V_8 ;
if ( V_11 )
if ( F_46 () )
return ( V_28 | V_26 ) ;
else F_47 () ;
return ( V_28 ) ;
}
V_14 = TRUE ;
if ( V_9 == 0 && V_11 ) {
switch ( F_38 () ) {
case V_20 :
if ( F_33 ( V_8 ) ) {
F_50 ( V_7 ) ;
if ( F_51 ( V_7 ) )
V_14 = FALSE ;
F_52 ( V_7 ) ;
}
break;
case V_21 :
if ( F_40 ( V_8 ) ) {
F_50 ( V_7 ) ;
if ( F_51 ( V_7 ) )
V_14 = FALSE ;
F_52 ( V_7 ) ;
}
break;
case V_22 :
if ( V_12 && ( V_13 ||
F_41 ( V_7 ) ) ) {
F_50 ( V_7 ) ;
if ( F_51 ( V_7 ) )
V_14 = FALSE ;
F_52 ( V_7 ) ;
}
break;
}
}
V_13 = V_11 ;
F_53 ( V_7 , V_9 , V_12 , V_13 , V_11 ) ;
if ( V_11 ) {
switch ( F_38 () ) {
case V_20 :
if ( F_33 ( V_8 ) ) {
F_50 ( V_7 ) ;
}
break;
case V_21 :
if ( F_40 ( V_8 ) ) {
F_50 ( V_7 ) ;
}
break;
case V_22 :
if ( V_12 && ( V_13 ||
F_41 ( V_7 ) ) ) {
F_50 ( V_7 ) ;
}
break;
}
if ( V_14 ) F_54 () ;
}
F_55 ( V_8 , V_7 ) ;
}
else F_56 ( V_8 , V_9 ) ;
* V_3 = V_8 ;
if ( V_11 ) {
if ( F_46 () ) return ( V_26 ) ;
else F_47 () ;
}
return ( V_16 ) ;
}
