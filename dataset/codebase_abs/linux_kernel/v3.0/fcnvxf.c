int
F_1 (
int * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register int V_5 , V_6 ;
register unsigned int V_7 = 0 ;
V_5 = * V_1 ;
if ( V_5 < 0 ) {
F_2 ( V_7 ) ;
F_3 ( V_5 ) ;
}
else {
F_4 ( V_7 ) ;
if ( V_5 == 0 ) {
F_5 ( V_7 ) ;
* V_3 = V_7 ;
return ( V_8 ) ;
}
}
V_6 = 16 ;
F_6 ( V_5 , V_6 ) ;
if ( V_6 >= 0 ) V_5 <<= V_6 ;
else V_5 = 1 << 30 ;
F_7 ( V_7 , V_5 >> ( V_9 - 1 ) ) ;
F_8 ( V_7 , 30 + V_10 - V_6 ) ;
if ( F_9 ( V_5 ) ) {
switch ( F_10 () ) {
case V_11 :
if ( F_11 ( V_7 ) )
F_12 ( V_7 ) ;
break;
case V_12 :
if ( F_13 ( V_7 ) )
F_12 ( V_7 ) ;
break;
case V_13 :
F_14 ( V_5 , V_7 ) ;
}
if ( F_15 () ) {
* V_3 = V_7 ;
return ( V_14 ) ;
}
else F_16 () ;
}
* V_3 = V_7 ;
return ( V_8 ) ;
}
int
F_17 (
int * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_5 , V_6 ;
register unsigned int V_15 = 0 , V_16 = 0 ;
V_5 = * V_1 ;
if ( V_5 < 0 ) {
F_18 ( V_15 ) ;
F_3 ( V_5 ) ;
}
else {
F_19 ( V_15 ) ;
if ( V_5 == 0 ) {
F_20 ( V_15 , V_16 ) ;
F_21 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
}
V_6 = 16 ;
F_6 ( V_5 , V_6 ) ;
if ( V_6 >= 0 ) V_5 <<= V_6 ;
else V_5 = 1 << 30 ;
F_22 ( V_15 , V_5 >> V_17 - 1 ) ;
F_23 ( V_16 , V_5 << ( 33 - V_17 ) ) ;
F_24 ( V_15 , ( 30 + V_18 ) - V_6 ) ;
F_21 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
int
F_25 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
int V_6 , V_19 ;
unsigned int V_7 = 0 , V_20 ;
F_26 ( V_1 , V_19 , V_20 ) ;
if ( V_19 < 0 ) {
F_2 ( V_7 ) ;
F_27 ( V_19 , V_20 ) ;
}
else {
F_4 ( V_7 ) ;
if ( V_19 == 0 && V_20 == 0 ) {
F_5 ( V_7 ) ;
* V_3 = V_7 ;
return ( V_8 ) ;
}
}
V_6 = 16 ;
if ( V_19 == 0 ) {
F_6 ( V_20 , V_6 ) ;
if ( V_6 >= 0 ) {
V_19 = V_20 << V_6 ;
V_20 = 0 ;
}
else {
V_19 = V_20 >> 1 ;
V_20 <<= 31 ;
}
V_6 += 32 ;
}
else {
F_6 ( V_19 , V_6 ) ;
if ( V_6 > 0 ) {
F_28 ( V_19 , V_20 , ( 32 - V_6 ) ,
V_19 ) ;
V_20 <<= V_6 ;
}
else V_19 >>= - ( V_6 ) ;
}
F_7 ( V_7 , V_19 >> V_9 - 1 ) ;
F_8 ( V_7 , ( 62 + V_10 ) - V_6 ) ;
if ( F_29 ( V_19 , V_20 ) ) {
switch ( F_10 () ) {
case V_11 :
if ( F_11 ( V_7 ) )
F_12 ( V_7 ) ;
break;
case V_12 :
if ( F_13 ( V_7 ) )
F_12 ( V_7 ) ;
break;
case V_13 :
F_30 ( V_19 , V_20 , V_7 ) ;
}
if ( F_15 () ) {
* V_3 = V_7 ;
return ( V_14 ) ;
}
else F_16 () ;
}
* V_3 = V_7 ;
return ( V_8 ) ;
}
int
F_31 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_19 , V_6 ;
register unsigned int V_20 , V_15 = 0 , V_16 = 0 ;
F_26 ( V_1 , V_19 , V_20 ) ;
if ( V_19 < 0 ) {
F_18 ( V_15 ) ;
F_27 ( V_19 , V_20 ) ;
}
else {
F_19 ( V_15 ) ;
if ( V_19 == 0 && V_20 == 0 ) {
F_20 ( V_15 , V_16 ) ;
F_21 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
}
V_6 = 16 ;
if ( V_19 == 0 ) {
F_6 ( V_20 , V_6 ) ;
if ( V_6 >= 0 ) {
V_19 = V_20 << V_6 ;
V_20 = 0 ;
}
else {
V_19 = V_20 >> 1 ;
V_20 <<= 31 ;
}
V_6 += 32 ;
}
else {
F_6 ( V_19 , V_6 ) ;
if ( V_6 > 0 ) {
F_28 ( V_19 , V_20 , ( 32 - V_6 ) ,
V_19 ) ;
V_20 <<= V_6 ;
}
else V_19 >>= - ( V_6 ) ;
}
F_22 ( V_15 , V_19 >> ( V_17 - 1 ) ) ;
F_32 ( V_19 , V_20 , V_17 - 1 , V_16 ) ;
F_24 ( V_15 , ( 62 + V_18 ) - V_6 ) ;
if ( F_33 ( V_20 ) ) {
switch ( F_10 () ) {
case V_11 :
if ( F_34 ( V_15 ) ) {
F_35 ( V_15 , V_16 ) ;
}
break;
case V_12 :
if ( F_36 ( V_15 ) ) {
F_35 ( V_15 , V_16 ) ;
}
break;
case V_13 :
F_37 ( V_20 , V_15 ,
V_16 ) ;
}
if ( F_15 () ) {
F_21 ( V_15 , V_16 , V_3 ) ;
return ( V_14 ) ;
}
else F_16 () ;
}
F_21 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
