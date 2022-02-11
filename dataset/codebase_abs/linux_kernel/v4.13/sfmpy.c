int
F_1 (
T_1 * V_1 ,
T_1 * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
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
if ( F_8 ( V_5 ) ) {
if ( F_9 () )
return ( V_15 ) ;
F_10 () ;
F_11 ( V_6 ) ;
* V_3 = V_6 ;
return ( V_16 ) ;
}
F_12 ( V_8 ) ;
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
V_9 = F_16 ( V_5 ) + F_16 ( V_6 ) - V_17 ;
if ( F_17 ( V_5 ) ) {
F_18 ( V_5 ) ;
}
else {
if ( F_6 ( V_5 ) ) {
F_19 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
F_22 ( V_5 , V_9 ) ;
}
if ( F_17 ( V_6 ) ) {
F_18 ( V_6 ) ;
}
else {
if ( F_6 ( V_6 ) ) {
F_19 ( V_8 ) ;
* V_3 = V_8 ;
return ( V_16 ) ;
}
F_20 ( V_6 ) ;
F_21 ( V_6 ) ;
F_22 ( V_6 , V_9 ) ;
}
F_23 ( V_6 ) ;
F_4 ( V_7 ) ;
for ( V_10 = 1 ; V_10 < V_18 ; V_10 += 4 ) {
V_13 |= F_24 ( V_7 ) ;
F_25 ( V_7 ) ;
if ( F_26 ( V_5 ) ) F_27 ( V_7 ) += ( F_27 ( V_6 ) << 3 ) ;
if ( F_28 ( V_5 ) ) F_27 ( V_7 ) += ( F_27 ( V_6 ) << 2 ) ;
if ( F_29 ( V_5 ) ) F_27 ( V_7 ) += ( F_27 ( V_6 ) << 1 ) ;
if ( F_30 ( V_5 ) ) F_27 ( V_7 ) += F_27 ( V_6 ) ;
F_25 ( V_5 ) ;
}
if ( F_31 ( V_7 ) ) {
F_21 ( V_7 ) ;
}
else {
V_9 ++ ;
}
while ( F_31 ( V_7 ) ) {
F_21 ( V_7 ) ;
V_9 -- ;
}
V_13 |= F_32 ( V_7 ) << ( V_19 - V_20 + 1 ) ;
V_12 = F_33 ( V_7 ) ;
V_11 = V_12 | V_13 ;
F_34 ( V_7 ) ;
if ( V_11 && ( V_9 > 0 || F_35 () ) ) {
F_20 ( V_7 ) ;
switch ( F_36 () ) {
case V_21 :
if ( F_31 ( V_8 ) )
F_37 ( V_7 ) ;
break;
case V_22 :
if ( F_38 ( V_8 ) )
F_37 ( V_7 ) ;
break;
case V_23 :
if ( V_12 ) {
if ( V_13 || F_39 ( V_7 ) )
F_37 ( V_7 ) ;
}
}
if ( F_40 ( V_7 ) ) V_9 ++ ;
}
F_41 ( V_8 , V_7 ) ;
if ( V_9 >= V_24 ) {
if ( F_42 () ) {
F_43 ( V_8 , V_9 , V_25 ) ;
* V_3 = V_8 ;
if ( V_11 )
if ( F_44 () )
return ( V_26 | V_27 ) ;
else F_45 () ;
return ( V_26 ) ;
}
V_11 = TRUE ;
F_46 () ;
F_47 ( V_8 ) ;
}
else if ( V_9 <= 0 ) {
if ( F_35 () ) {
F_43 ( V_8 , V_9 , V_28 ) ;
* V_3 = V_8 ;
if ( V_11 )
if ( F_44 () )
return ( V_29 | V_27 ) ;
else F_45 () ;
return ( V_29 ) ;
}
V_14 = TRUE ;
if ( V_9 == 0 && V_11 ) {
switch ( F_36 () ) {
case V_21 :
if ( F_31 ( V_8 ) ) {
F_37 ( V_7 ) ;
if ( F_48 ( V_7 ) )
V_14 = FALSE ;
F_49 ( V_7 ) ;
}
break;
case V_22 :
if ( F_38 ( V_8 ) ) {
F_37 ( V_7 ) ;
if ( F_48 ( V_7 ) )
V_14 = FALSE ;
F_49 ( V_7 ) ;
}
break;
case V_23 :
if ( V_12 && ( V_13 ||
F_39 ( V_7 ) ) ) {
F_37 ( V_7 ) ;
if ( F_48 ( V_7 ) )
V_14 = FALSE ;
F_49 ( V_7 ) ;
}
break;
}
}
V_13 = V_11 ;
F_50 ( V_7 , V_9 , V_12 , V_13 , V_11 ) ;
if ( V_11 ) {
switch ( F_36 () ) {
case V_21 :
if ( F_31 ( V_8 ) ) {
F_37 ( V_7 ) ;
}
break;
case V_22 :
if ( F_38 ( V_8 ) ) {
F_37 ( V_7 ) ;
}
break;
case V_23 :
if ( V_12 && ( V_13 ||
F_39 ( V_7 ) ) ) {
F_37 ( V_7 ) ;
}
break;
}
if ( V_14 ) F_51 () ;
}
F_52 ( V_8 , V_7 ) ;
}
else F_53 ( V_8 , V_9 ) ;
* V_3 = V_8 ;
if ( V_11 ) {
if ( F_44 () ) return ( V_27 ) ;
else F_45 () ;
}
return ( V_16 ) ;
}
