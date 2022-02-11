int
F_1 (
T_1 * V_1 ,
T_1 * V_2 ,
int * V_3 ,
T_1 * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 , V_8 ;
register boolean V_9 = FALSE ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_10 ;
if ( V_7 > V_11 ) {
if ( ( V_7 > V_11 + 1 ) ||
F_3 ( V_5 ) || F_4 ( V_5 ) ) {
if ( F_4 ( V_5 ) ) V_8 = 0x7fffffff ;
else V_8 = 0x80000000 ;
if ( F_5 () ) {
return ( V_12 ) ;
}
F_6 () ;
* V_3 = V_8 ;
return ( V_13 ) ;
}
}
if ( V_7 >= 0 ) {
V_6 = V_5 ;
F_7 ( V_6 ) ;
F_8 ( V_6 , V_7 ) ;
if ( F_9 ( V_5 ) ) V_8 = - F_10 ( V_6 ) ;
else V_8 = F_10 ( V_6 ) ;
if ( F_11 ( V_5 , V_7 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_4 ( V_5 ) ) V_8 ++ ;
break;
case V_15 :
if ( F_9 ( V_5 ) ) V_8 -- ;
break;
case V_16 :
if ( F_13 ( V_5 , V_7 ) ) {
if ( F_14 ( V_5 , V_7 )
|| ( F_15 ( V_6 ) ) )
if ( F_4 ( V_5 ) ) V_8 ++ ;
else V_8 -- ;
}
}
}
}
else {
V_8 = 0 ;
if ( F_16 ( V_5 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_4 ( V_5 ) ) V_8 ++ ;
break;
case V_15 :
if ( F_9 ( V_5 ) ) V_8 -- ;
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_3 ( V_5 ) )
if ( F_4 ( V_5 ) ) V_8 ++ ;
else V_8 -- ;
}
}
}
* V_3 = V_8 ;
if ( V_9 ) {
if ( F_17 () ) return ( V_17 ) ;
else F_18 () ;
}
return ( V_13 ) ;
}
int
F_19 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 , V_18 ;
register unsigned int V_5 , V_6 , V_19 ;
register boolean V_9 = FALSE ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_10 ;
if ( V_7 > V_20 ) {
if ( ( V_7 > V_20 + 1 ) ||
F_3 ( V_5 ) || F_4 ( V_5 ) ) {
if ( F_4 ( V_5 ) ) {
V_18 = 0x7fffffff ;
V_19 = 0xffffffff ;
}
else {
V_18 = 0x80000000 ;
V_19 = 0 ;
}
if ( F_5 () ) {
return ( V_12 ) ;
}
F_6 () ;
F_20 ( V_18 , V_19 , V_3 ) ;
return ( V_13 ) ;
}
F_21 ( V_18 , V_19 ) ;
F_20 ( V_18 , V_19 , V_3 ) ;
return ( V_13 ) ;
}
if ( V_7 >= 0 ) {
V_6 = V_5 ;
F_7 ( V_6 ) ;
F_22 ( V_6 , V_7 , V_18 , V_19 ) ;
if ( F_9 ( V_5 ) ) {
F_23 ( V_18 , V_19 ) ;
}
if ( F_11 ( V_5 , V_7 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_4 ( V_5 ) ) {
F_24 ( V_18 , V_19 ) ;
}
break;
case V_15 :
if ( F_9 ( V_5 ) ) {
F_25 ( V_18 , V_19 ) ;
}
break;
case V_16 :
if ( F_13 ( V_5 , V_7 ) )
if ( F_14 ( V_5 , V_7 ) ||
( F_26 ( V_19 ) ) )
if ( F_4 ( V_5 ) ) {
F_24 ( V_18 , V_19 ) ;
}
else {
F_25 ( V_18 , V_19 ) ;
}
}
}
}
else {
F_27 ( V_18 , V_19 ) ;
if ( F_16 ( V_5 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_4 ( V_5 ) ) {
F_24 ( V_18 , V_19 ) ;
}
break;
case V_15 :
if ( F_9 ( V_5 ) ) {
F_25 ( V_18 , V_19 ) ;
}
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_3 ( V_5 ) )
if ( F_4 ( V_5 ) ) {
F_24 ( V_18 , V_19 ) ;
}
else {
F_25 ( V_18 , V_19 ) ;
}
}
}
}
F_20 ( V_18 , V_19 , V_3 ) ;
if ( V_9 ) {
if ( F_17 () ) return ( V_17 ) ;
else F_18 () ;
}
return ( V_13 ) ;
}
int
F_28 (
T_3 * V_1 ,
unsigned int * V_2 ,
int * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_21 , V_22 , V_23 , V_24 ;
register int V_7 , V_8 ;
register boolean V_9 = FALSE ;
F_29 ( V_1 , V_21 , V_22 ) ;
V_7 = F_30 ( V_21 ) - V_25 ;
if ( V_7 > V_11 ) {
if ( F_31 ( V_7 , V_21 , V_22 ) ) {
if ( F_32 ( V_21 ) ) V_8 = 0x7fffffff ;
else V_8 = 0x80000000 ;
if ( F_5 () ) {
return ( V_12 ) ;
}
F_6 () ;
* V_3 = V_8 ;
return ( V_13 ) ;
}
}
if ( V_7 >= 0 ) {
V_23 = V_21 ;
V_24 = V_22 ;
F_33 ( V_23 ) ;
F_34 ( V_23 , V_24 , V_7 ) ;
if ( F_35 ( V_21 ) && ( V_7 <= V_11 ) )
V_8 = - F_36 ( V_23 ) ;
else V_8 = F_36 ( V_23 ) ;
if ( F_37 ( V_21 , V_22 , V_7 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_32 ( V_21 ) ) V_8 ++ ;
break;
case V_15 :
if ( F_35 ( V_21 ) ) V_8 -- ;
break;
case V_16 :
if ( F_38 ( V_21 , V_22 , V_7 ) )
if ( F_39 ( V_21 , V_22 , V_7 ) ||
( F_40 ( V_23 ) ) )
if ( F_32 ( V_21 ) ) V_8 ++ ;
else V_8 -- ;
}
if ( ( F_32 ( V_21 ) && V_8 < 0 ) ||
( F_35 ( V_21 ) && V_8 > 0 ) ) {
if ( F_32 ( V_21 ) ) V_8 = 0x7fffffff ;
else V_8 = 0x80000000 ;
if ( F_5 () ) {
return ( V_12 ) ;
}
F_6 () ;
* V_3 = V_8 ;
return ( V_13 ) ;
}
}
}
else {
V_8 = 0 ;
if ( F_41 ( V_21 , V_22 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_32 ( V_21 ) ) V_8 ++ ;
break;
case V_15 :
if ( F_35 ( V_21 ) ) V_8 -- ;
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_42 ( V_21 , V_22 ) )
if ( F_32 ( V_21 ) ) V_8 ++ ;
else V_8 -- ;
}
}
}
* V_3 = V_8 ;
if ( V_9 ) {
if ( F_17 () ) return ( V_17 ) ;
else F_18 () ;
}
return ( V_13 ) ;
}
int
F_43 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 , V_18 ;
register unsigned int V_21 , V_22 , V_23 , V_24 , V_19 ;
register boolean V_9 = FALSE ;
F_29 ( V_1 , V_21 , V_22 ) ;
V_7 = F_30 ( V_21 ) - V_25 ;
if ( V_7 > V_20 ) {
if ( ( V_7 > V_20 + 1 ) ||
F_42 ( V_21 , V_22 ) || F_32 ( V_21 ) ) {
if ( F_32 ( V_21 ) ) {
V_18 = 0x7fffffff ;
V_19 = 0xffffffff ;
}
else {
V_18 = 0x80000000 ;
V_19 = 0 ;
}
if ( F_5 () ) {
return ( V_12 ) ;
}
F_6 () ;
F_20 ( V_18 , V_19 , V_3 ) ;
return ( V_13 ) ;
}
}
if ( V_7 >= 0 ) {
V_23 = V_21 ;
V_24 = V_22 ;
F_33 ( V_23 ) ;
F_44 ( V_23 , V_24 , V_7 , V_18 ,
V_19 ) ;
if ( F_35 ( V_21 ) ) {
F_23 ( V_18 , V_19 ) ;
}
if ( F_37 ( V_21 , V_22 , V_7 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_32 ( V_21 ) ) {
F_24 ( V_18 , V_19 ) ;
}
break;
case V_15 :
if ( F_35 ( V_21 ) ) {
F_25 ( V_18 , V_19 ) ;
}
break;
case V_16 :
if ( F_38 ( V_21 , V_22 , V_7 ) )
if ( F_39 ( V_21 , V_22 , V_7 ) ||
( F_26 ( V_19 ) ) )
if ( F_32 ( V_21 ) ) {
F_24 ( V_18 , V_19 ) ;
}
else {
F_25 ( V_18 , V_19 ) ;
}
}
}
}
else {
F_27 ( V_18 , V_19 ) ;
if ( F_41 ( V_21 , V_22 ) ) {
V_9 = TRUE ;
switch ( F_12 () ) {
case V_14 :
if ( F_32 ( V_21 ) ) {
F_24 ( V_18 , V_19 ) ;
}
break;
case V_15 :
if ( F_35 ( V_21 ) ) {
F_25 ( V_18 , V_19 ) ;
}
break;
case V_16 :
if ( V_7 == - 1 )
if ( F_42 ( V_21 , V_22 ) )
if ( F_32 ( V_21 ) ) {
F_24 ( V_18 , V_19 ) ;
}
else {
F_25 ( V_18 , V_19 ) ;
}
}
}
}
F_20 ( V_18 , V_19 , V_3 ) ;
if ( V_9 ) {
if ( F_17 () ) return ( V_17 ) ;
else F_18 () ;
}
return ( V_13 ) ;
}
