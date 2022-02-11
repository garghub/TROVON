int
F_1 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 ;
register int V_8 ;
V_5 = * V_1 ;
V_8 = F_2 ( V_5 ) ;
F_3 ( V_6 ) = F_4 ( V_5 ) ;
if ( V_8 == V_9 ) {
if ( F_5 ( V_5 ) ) {
F_6 ( V_6 , V_7 ) ;
F_7 ( V_6 , V_7 , V_3 ) ;
return ( V_10 ) ;
}
else {
if ( F_8 ( V_5 ) ) {
if ( F_9 () )
return ( V_11 ) ;
else {
F_10 () ;
F_11 ( V_5 ) ;
}
}
F_12 ( V_6 ) ;
F_13 ( V_5 , V_6 , V_7 ) ;
F_7 ( V_6 , V_7 , V_3 ) ;
return ( V_10 ) ;
}
}
if ( V_8 == 0 ) {
if ( F_14 ( V_5 ) ) {
F_15 ( V_5 ) ;
F_16 ( V_5 ) ;
F_17 ( V_5 , V_8 ) ;
F_18 ( V_8 , V_6 ) ;
F_13 ( V_5 , V_6 , V_7 ) ;
}
else {
F_19 ( V_6 , V_7 ) ;
}
F_7 ( V_6 , V_7 , V_3 ) ;
return ( V_10 ) ;
}
F_18 ( V_8 , V_6 ) ;
F_13 ( F_20 ( V_5 ) , V_6 , V_7 ) ;
F_7 ( V_6 , V_7 , V_3 ) ;
return ( V_10 ) ;
}
int
F_21 (
T_2 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_12 , V_13 , V_14 ;
register int V_8 , V_15 , V_16 ;
register boolean V_17 = FALSE , V_18 = FALSE , V_19 = FALSE ;
register boolean V_20 = FALSE ;
boolean V_21 ;
F_22 ( V_1 , V_12 , V_13 ) ;
V_8 = F_23 ( V_12 ) ;
F_4 ( V_14 ) = F_3 ( V_12 ) ;
if ( V_8 == V_22 ) {
if ( F_24 ( V_12 , V_13 ) ) {
F_25 ( V_14 ) ;
* V_3 = V_14 ;
return ( V_10 ) ;
}
if ( F_26 ( V_12 ) ) {
if ( F_9 () ) return ( V_11 ) ;
else {
F_10 () ;
F_27 ( V_12 ) ;
}
}
F_28 ( V_14 ) ;
F_29 ( V_14 , F_30 ( V_12 ) << 3 | F_31 ( V_13 ) >> 29 ) ;
if ( F_5 ( V_14 ) ) F_11 ( V_14 ) ;
* V_3 = V_14 ;
return ( V_10 ) ;
}
F_32 ( V_8 , V_15 ) ;
if ( V_15 > 0 ) {
F_33 ( V_12 , V_13 , V_16 , V_17 , V_18 ,
V_19 , V_20 ) ;
}
else {
if ( F_34 ( V_12 , V_13 ) ) {
F_35 ( V_14 ) ;
* V_3 = V_14 ;
return ( V_10 ) ;
}
if ( F_36 () ) {
F_33 ( V_12 , V_13 , V_16 , V_17 ,
V_18 , V_19 , V_20 ) ;
}
else {
F_37 ( V_12 , V_13 , V_15 ,
V_16 , V_17 , V_18 , V_19 , V_20 ,
V_21 ) ;
}
}
if ( V_17 ) {
switch ( F_38 () ) {
case V_23 :
if ( F_39 ( V_14 ) ) V_16 ++ ;
break;
case V_24 :
if ( F_40 ( V_14 ) ) V_16 ++ ;
break;
case V_25 :
if ( V_18 ) {
if ( V_19 || V_20 ) V_16 ++ ;
}
}
}
F_41 ( V_14 , V_16 ) ;
if ( ( V_15 > 0 || F_36 () ) &&
F_42 ( V_14 ) ) V_15 ++ ;
if ( V_15 >= V_9 ) {
if ( F_43 () ) {
if ( V_15 >= V_9 + V_26 )
return ( V_27 ) ;
F_44 ( V_14 , V_15 , V_28 ) ;
* V_3 = V_14 ;
if ( V_17 )
if ( F_45 () )
return ( V_29 | V_30 ) ;
else F_46 () ;
return ( V_29 ) ;
}
F_47 () ;
V_17 = TRUE ;
F_48 ( V_14 ) ;
}
else if ( V_15 <= 0 ) {
if ( F_36 () ) {
if ( V_15 <= - ( V_26 ) )
return ( V_27 ) ;
F_44 ( V_14 , V_15 , V_31 ) ;
* V_3 = V_14 ;
if ( V_17 )
if ( F_45 () )
return ( V_32 | V_30 ) ;
else F_46 () ;
return ( V_32 ) ;
}
if ( V_17 && V_21 ) F_49 () ;
}
else F_50 ( V_14 , V_15 ) ;
* V_3 = V_14 ;
if ( V_17 )
if ( F_45 () ) return ( V_30 ) ;
else F_46 () ;
return ( V_10 ) ;
}
