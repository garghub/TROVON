int
F_1 ( T_1 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 ;
register boolean V_8 = FALSE ;
V_5 = * V_1 ;
if ( ( V_7 = F_2 ( V_5 ) ) == V_9 ) {
if ( F_3 ( V_5 ) ) {
if ( F_4 () ) return ( V_10 ) ;
F_5 () ;
F_6 ( V_5 ) ;
}
* V_3 = V_5 ;
return ( V_11 ) ;
}
if ( ( V_7 -= V_12 ) >= V_13 - 1 ) {
* V_3 = V_5 ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
F_7 ( V_5 ) ;
V_6 = V_5 ;
F_8 ( V_6 , ( V_13 - 1 ) - ( V_7 ) ) ;
if ( F_9 ( V_5 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_10 () ) {
case V_14 :
if ( F_11 ( V_5 ) ) F_12 ( V_6 ) ;
break;
case V_15 :
if ( F_13 ( V_5 ) ) F_12 ( V_6 ) ;
break;
case V_16 :
if ( F_14 ( V_5 , V_7 ) )
if ( F_15 ( V_5 , V_7 )
|| ( F_16 ( V_6 ) ) )
F_12 ( V_6 ) ;
}
}
F_17 ( V_6 , ( V_13 - 1 ) - ( V_7 ) ) ;
if ( F_18 ( V_6 ) )
F_19 ( V_6 , V_7 + ( V_12 + 1 ) ) ;
else F_19 ( V_6 , V_7 + V_12 ) ;
}
else {
V_6 = V_5 ;
F_20 ( V_6 ) ;
if ( F_21 ( V_5 ) ) {
V_8 = TRUE ;
switch ( F_10 () ) {
case V_14 :
if ( F_11 ( V_5 ) )
F_19 ( V_6 , V_12 ) ;
break;
case V_15 :
if ( F_13 ( V_5 ) )
F_19 ( V_6 , V_12 ) ;
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_22 ( V_5 ) )
F_19 ( V_6 , V_12 ) ;
}
}
}
* V_3 = V_6 ;
if ( V_8 ) {
if ( F_23 () ) return ( V_17 ) ;
else F_24 () ;
}
return ( V_11 ) ;
}
int
F_25 (
T_2 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_18 , V_19 , V_20 , V_21 ;
register int V_7 ;
register boolean V_8 = FALSE ;
F_26 ( V_1 , V_18 , V_19 ) ;
if ( ( V_7 = F_27 ( V_18 ) ) == V_22 ) {
if ( F_28 ( V_18 ) ) {
if ( F_4 () ) return ( V_10 ) ;
F_5 () ;
F_29 ( V_18 ) ;
}
F_30 ( V_18 , V_19 , V_3 ) ;
return ( V_11 ) ;
}
if ( ( V_7 -= V_23 ) >= V_24 - 1 ) {
F_30 ( V_18 , V_19 , V_3 ) ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
F_31 ( V_18 ) ;
V_20 = V_18 ;
V_21 = V_19 ;
F_32 ( V_20 , V_21 , ( V_24 - 1 ) - ( V_7 ) ) ;
if ( F_33 ( V_18 , V_19 , V_7 ) ) {
V_8 = TRUE ;
switch ( F_10 () ) {
case V_14 :
if ( F_34 ( V_18 ) )
F_35 ( V_20 , V_21 ) ;
break;
case V_15 :
if ( F_36 ( V_18 ) )
F_35 ( V_20 , V_21 ) ;
break;
case V_16 :
if ( F_37 ( V_18 , V_19 , V_7 ) )
if ( F_38 ( V_18 , V_19 , V_7 )
|| ( F_39 ( V_21 ) ) )
F_35 ( V_20 , V_21 ) ;
}
}
F_40 ( V_20 , V_21 , ( V_24 - 1 ) - ( V_7 ) ) ;
if ( F_41 ( V_20 ) )
F_42 ( V_20 , V_7 + ( V_23 + 1 ) ) ;
else F_42 ( V_20 , V_7 + V_23 ) ;
}
else {
V_20 = V_18 ;
F_43 ( V_20 , V_21 ) ;
if ( F_44 ( V_18 , V_19 ) ) {
V_8 = TRUE ;
switch ( F_10 () ) {
case V_14 :
if ( F_34 ( V_18 ) )
F_42 ( V_20 , V_23 ) ;
break;
case V_15 :
if ( F_36 ( V_18 ) )
F_42 ( V_20 , V_23 ) ;
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_45 ( V_18 , V_19 ) )
F_42 ( V_20 , V_23 ) ;
}
}
}
F_30 ( V_20 , V_21 , V_3 ) ;
if ( V_8 ) {
if ( F_23 () ) return ( V_17 ) ;
else F_24 () ;
}
return ( V_11 ) ;
}
