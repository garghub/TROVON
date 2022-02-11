int
F_1 (
unsigned int * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 = 0 ;
register int V_7 ;
V_5 = * V_1 ;
if ( V_5 == 0 ) {
F_2 ( V_6 ) ;
* V_3 = V_6 ;
return ( V_8 ) ;
}
V_7 = 16 ;
F_3 ( V_5 , V_7 ) ;
V_5 <<= V_7 + 1 ;
F_4 ( V_6 , V_5 >> V_9 ) ;
F_5 ( V_6 , 30 + V_10 - V_7 ) ;
if ( F_6 ( V_5 ) ) {
switch ( F_7 () ) {
case V_11 :
F_8 ( V_6 ) ;
break;
case V_12 :
break;
case V_13 :
F_9 ( V_5 , V_6 ) ;
break;
}
if ( F_10 () ) {
* V_3 = V_6 ;
return ( V_14 ) ;
}
else F_11 () ;
}
* V_3 = V_6 ;
return ( V_8 ) ;
}
int
F_12 (
unsigned int * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_5 , V_15 = 0 , V_16 = 0 ;
V_5 = * V_1 ;
if ( V_5 == 0 ) {
F_13 ( V_15 , V_16 ) ;
F_14 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
V_7 = 16 ;
F_3 ( V_5 , V_7 ) ;
V_5 <<= V_7 + 1 ;
F_15 ( V_15 , V_5 >> V_17 ) ;
F_16 ( V_16 , V_5 << ( 32 - V_17 ) ) ;
F_17 ( V_15 , ( 30 + V_18 ) - V_7 ) ;
F_14 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
int
F_18 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_1 * V_3 ,
unsigned int * V_4 )
{
int V_7 ;
unsigned int V_19 , V_20 , V_6 = 0 ;
F_19 ( V_1 , V_19 , V_20 ) ;
if ( V_19 == 0 && V_20 == 0 ) {
F_2 ( V_6 ) ;
* V_3 = V_6 ;
return ( V_8 ) ;
}
V_7 = 16 ;
if ( V_19 == 0 ) {
F_3 ( V_20 , V_7 ) ;
V_19 = V_20 << V_7 + 1 ;
V_20 = 0 ;
V_7 += 32 ;
}
else {
F_3 ( V_19 , V_7 ) ;
if ( V_7 >= 0 ) {
F_20 ( V_19 , V_20 , ( 31 - V_7 ) ,
V_19 ) ;
V_20 <<= V_7 + 1 ;
}
}
F_4 ( V_6 , V_19 >> V_9 ) ;
F_5 ( V_6 , ( 62 + V_10 ) - V_7 ) ;
if ( F_21 ( V_19 , V_20 ) ) {
switch ( F_7 () ) {
case V_11 :
F_8 ( V_6 ) ;
break;
case V_12 :
break;
case V_13 :
F_22 ( V_19 , V_20 , V_6 ) ;
break;
}
if ( F_10 () ) {
* V_3 = V_6 ;
return ( V_14 ) ;
}
else F_11 () ;
}
* V_3 = V_6 ;
return ( V_8 ) ;
}
int
F_23 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_19 , V_20 , V_15 = 0 , V_16 = 0 ;
F_19 ( V_1 , V_19 , V_20 ) ;
if ( V_19 == 0 && V_20 == 0 ) {
F_13 ( V_15 , V_16 ) ;
F_14 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
V_7 = 16 ;
if ( V_19 == 0 ) {
F_3 ( V_20 , V_7 ) ;
V_19 = V_20 << V_7 + 1 ;
V_20 = 0 ;
V_7 += 32 ;
}
else {
F_3 ( V_19 , V_7 ) ;
if ( V_7 >= 0 ) {
F_20 ( V_19 , V_20 , ( 31 - V_7 ) ,
V_19 ) ;
V_20 <<= V_7 + 1 ;
}
}
F_15 ( V_15 , V_19 >> V_17 ) ;
F_24 ( V_19 , V_20 , V_17 , V_16 ) ;
F_17 ( V_15 , ( 62 + V_18 ) - V_7 ) ;
if ( F_25 ( V_20 ) ) {
switch ( F_7 () ) {
case V_11 :
F_26 ( V_15 , V_16 ) ;
break;
case V_12 :
break;
case V_13 :
F_27 ( V_20 , V_15 ,
V_16 ) ;
break;
}
if ( F_10 () ) {
F_14 ( V_15 , V_16 , V_3 ) ;
return ( V_14 ) ;
}
else F_11 () ;
}
F_14 ( V_15 , V_16 , V_3 ) ;
return ( V_8 ) ;
}
