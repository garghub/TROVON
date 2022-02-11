int
F_1 ( T_1 * V_1 , T_1 * V_2 ,
T_1 * V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 , V_7 ;
register int V_8 , V_9 , V_10 , V_11 ;
register boolean V_12 = FALSE ;
V_5 = * V_1 ;
V_6 = * V_2 ;
if ( ( V_8 = F_2 ( V_5 ) ) == V_13 ) {
if ( F_3 ( V_5 ) ) {
if ( F_4 ( V_6 ) ) {
if ( F_5 () )
return ( V_14 ) ;
F_6 () ;
F_7 ( V_7 ) ;
* V_3 = V_7 ;
return ( V_15 ) ;
}
}
else {
if ( F_8 ( V_5 ) ) {
if ( F_5 () )
return ( V_14 ) ;
F_6 () ;
F_9 ( V_5 ) ;
}
else if ( F_10 ( V_6 ) ) {
if ( F_5 () )
return ( V_14 ) ;
F_6 () ;
F_9 ( V_6 ) ;
* V_3 = V_6 ;
return ( V_15 ) ;
}
* V_3 = V_5 ;
return ( V_15 ) ;
}
}
if ( ( V_9 = F_2 ( V_6 ) ) == V_13 ) {
if ( F_3 ( V_6 ) ) {
* V_3 = V_5 ;
return ( V_15 ) ;
}
if ( F_8 ( V_6 ) ) {
if ( F_5 () ) return ( V_14 ) ;
F_6 () ;
F_9 ( V_6 ) ;
}
* V_3 = V_6 ;
return ( V_15 ) ;
}
if ( F_11 ( V_6 ) ) {
if ( F_5 () ) return ( V_14 ) ;
F_6 () ;
F_7 ( V_7 ) ;
* V_3 = V_7 ;
return ( V_15 ) ;
}
V_7 = V_5 ;
if ( V_8 == 0 ) {
if ( F_3 ( V_5 ) ) {
* V_3 = V_5 ;
return ( V_15 ) ;
}
V_8 = 1 ;
F_12 ( V_5 , V_8 ) ;
}
else {
F_13 ( V_5 ) ;
}
if ( V_9 == 0 ) {
V_9 = 1 ;
F_12 ( V_6 , V_9 ) ;
}
else {
F_13 ( V_6 ) ;
}
V_10 = V_9 - 1 ;
V_11 = V_8 - V_9 ;
if ( V_11 < 0 ) {
if ( V_11 == - 1 && F_14 ( V_5 , V_6 ) ) {
F_15 ( V_7 ) = ~ F_15 ( V_7 ) ;
F_16 ( V_6 ) ;
F_17 ( V_6 , V_5 , V_6 ) ;
while ( F_18 ( V_6 ) ) {
F_16 ( V_6 ) ;
V_10 -- ;
}
F_19 ( V_7 , V_6 ) ;
goto V_16;
}
F_19 ( V_7 , V_5 ) ;
V_10 = V_8 ;
goto V_16;
}
while ( V_11 -- > 0 && F_15 ( V_5 ) ) {
if ( F_20 ( V_5 , V_6 ) )
F_17 ( V_5 , V_6 , V_5 ) ;
F_16 ( V_5 ) ;
}
if ( F_20 ( V_5 , V_6 ) ) {
F_17 ( V_5 , V_6 , V_5 ) ;
V_12 = TRUE ;
}
if ( V_11 > 0 || F_21 ( V_5 ) ) {
F_22 ( V_7 ) ;
* V_3 = V_7 ;
return ( V_15 ) ;
}
F_16 ( V_5 ) ;
if ( F_14 ( V_5 , V_6 ) ) {
F_23 ( V_7 ) ;
F_17 ( ( V_6 << 1 ) , V_5 , V_5 ) ;
}
else if ( F_24 ( V_5 , V_6 ) && V_12 ) {
F_23 ( V_7 ) ;
}
while ( F_18 ( V_5 ) ) {
V_10 -- ;
F_16 ( V_5 ) ;
}
F_19 ( V_7 , V_5 ) ;
V_16:
if ( V_10 <= 0 ) {
if ( F_25 () ) {
F_26 ( V_7 , V_10 , V_17 ) ;
* V_3 = V_7 ;
return ( V_18 ) ;
}
if ( V_10 >= ( 1 - V_19 ) ) {
F_27 ( V_7 , 1 - V_10 ) ;
}
else {
F_22 ( V_7 ) ;
}
}
else F_28 ( V_7 , V_10 ) ;
* V_3 = V_7 ;
return ( V_15 ) ;
}
