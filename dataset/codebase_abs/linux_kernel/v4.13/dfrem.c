int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
T_1 * V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 , V_8 ;
register unsigned int V_9 , V_10 ;
register int V_11 , V_12 , V_13 , V_14 ;
register boolean V_15 = FALSE ;
F_2 ( V_1 , V_5 , V_6 ) ;
F_2 ( V_2 , V_7 , V_8 ) ;
if ( ( V_11 = F_3 ( V_5 ) ) == V_16 ) {
if ( F_4 ( V_5 , V_6 ) ) {
if ( F_5 ( V_7 , V_8 ) ) {
if ( F_6 () )
return ( V_17 ) ;
F_7 () ;
F_8 ( V_9 , V_10 ) ;
F_9 ( V_9 , V_10 , V_3 ) ;
return ( V_18 ) ;
}
}
else {
if ( F_10 ( V_5 ) ) {
if ( F_6 () )
return ( V_17 ) ;
F_7 () ;
F_11 ( V_5 ) ;
}
else if ( F_12 ( V_7 ) ) {
if ( F_6 () )
return ( V_17 ) ;
F_7 () ;
F_11 ( V_7 ) ;
F_9 ( V_7 , V_8 , V_3 ) ;
return ( V_18 ) ;
}
F_9 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
}
if ( ( V_12 = F_3 ( V_7 ) ) == V_16 ) {
if ( F_4 ( V_7 , V_8 ) ) {
F_9 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
if ( F_10 ( V_7 ) ) {
if ( F_6 () ) return ( V_17 ) ;
F_7 () ;
F_11 ( V_7 ) ;
}
F_9 ( V_7 , V_8 , V_3 ) ;
return ( V_18 ) ;
}
if ( F_13 ( V_7 , V_8 ) ) {
if ( F_6 () ) return ( V_17 ) ;
F_7 () ;
F_8 ( V_9 , V_10 ) ;
F_9 ( V_9 , V_10 , V_3 ) ;
return ( V_18 ) ;
}
V_9 = V_5 ;
if ( V_11 == 0 ) {
if ( F_4 ( V_5 , V_6 ) ) {
F_9 ( V_5 , V_6 , V_3 ) ;
return ( V_18 ) ;
}
V_11 = 1 ;
F_14 ( V_5 , V_6 , V_11 ) ;
}
else {
F_15 ( V_5 ) ;
}
if ( V_12 == 0 ) {
V_12 = 1 ;
F_14 ( V_7 , V_8 , V_12 ) ;
}
else {
F_15 ( V_7 ) ;
}
V_13 = V_12 - 1 ;
V_14 = V_11 - V_12 ;
if ( V_14 < 0 ) {
if ( V_14 == - 1 &&
F_16 ( V_5 , V_6 , V_7 , V_8 ) ) {
F_17 ( V_9 ) = ~ F_17 ( V_9 ) ;
F_18 ( V_7 , V_8 ) ;
F_19 ( V_7 , V_8 , V_5 , V_6 ,
V_7 , V_8 ) ;
while ( F_20 ( V_7 ) ) {
F_18 ( V_7 , V_8 ) ;
V_13 -- ;
}
F_21 ( V_9 , V_10 , V_7 , V_8 ) ;
goto V_19;
}
F_21 ( V_9 , V_10 , V_5 , V_6 ) ;
V_13 = V_11 ;
goto V_19;
}
while ( V_14 -- > 0 && ( F_17 ( V_5 ) || F_22 ( V_6 ) ) ) {
if ( F_23 ( V_5 , V_6 , V_7 , V_8 ) ) {
F_19 ( V_5 , V_6 , V_7 , V_8 , V_5 , V_6 ) ;
}
F_18 ( V_5 , V_6 ) ;
}
if ( F_23 ( V_5 , V_6 , V_7 , V_8 ) ) {
F_19 ( V_5 , V_6 , V_7 , V_8 , V_5 , V_6 ) ;
V_15 = TRUE ;
}
if ( V_14 > 0 || F_24 ( V_5 , V_6 ) ) {
F_25 ( V_9 , V_10 ) ;
F_9 ( V_9 , V_10 , V_3 ) ;
return ( V_18 ) ;
}
F_18 ( V_5 , V_6 ) ;
if ( F_16 ( V_5 , V_6 , V_7 , V_8 ) ) {
F_26 ( V_9 ) ;
F_18 ( V_7 , V_8 ) ;
F_19 ( V_7 , V_8 , V_5 , V_6 , V_5 , V_6 ) ;
}
else if ( F_27 ( V_5 , V_6 , V_7 , V_8 ) && V_15 ) {
F_26 ( V_9 ) ;
}
while ( F_20 ( V_5 ) ) {
V_13 -- ;
F_18 ( V_5 , V_6 ) ;
}
F_21 ( V_9 , V_10 , V_5 , V_6 ) ;
V_19:
if ( V_13 <= 0 ) {
if ( F_28 () ) {
F_29 ( V_9 , V_13 , V_20 ) ;
F_9 ( V_9 , V_10 , V_3 ) ;
return ( V_21 ) ;
}
if ( V_13 >= ( 1 - V_22 ) ) {
F_30 ( V_9 , V_10 ,
1 - V_13 ) ;
}
else {
F_25 ( V_9 , V_10 ) ;
}
}
else F_31 ( V_9 , V_13 ) ;
F_9 ( V_9 , V_10 , V_3 ) ;
return ( V_18 ) ;
}
