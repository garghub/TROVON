int
F_1 (
T_1 * V_1 ,
unsigned int * V_2 ,
int * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 , V_8 ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_9 ;
if ( V_7 > V_10 ) {
if ( ( V_7 > V_10 + 1 ) ||
F_3 ( V_5 ) || F_4 ( V_5 ) ) {
if ( F_4 ( V_5 ) ) V_8 = 0x7fffffff ;
else V_8 = 0x80000000 ;
if ( F_5 () ) {
return ( V_11 ) ;
}
F_6 () ;
* V_3 = V_8 ;
return ( V_12 ) ;
}
}
if ( V_7 >= 0 ) {
V_6 = V_5 ;
F_7 ( V_6 ) ;
F_8 ( V_6 , V_7 ) ;
if ( F_9 ( V_5 ) ) V_8 = - F_10 ( V_6 ) ;
else V_8 = F_10 ( V_6 ) ;
* V_3 = V_8 ;
if ( F_11 ( V_5 , V_7 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
else {
* V_3 = 0 ;
if ( F_14 ( V_5 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
return ( V_12 ) ;
}
int
F_15 (
T_1 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 , V_14 ;
register unsigned int V_5 , V_6 , V_15 ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_9 ;
if ( V_7 > V_16 ) {
if ( ( V_7 > V_16 + 1 ) ||
F_3 ( V_5 ) || F_4 ( V_5 ) ) {
if ( F_4 ( V_5 ) ) {
V_14 = 0x7fffffff ;
V_15 = 0xffffffff ;
}
else {
V_14 = 0x80000000 ;
V_15 = 0 ;
}
if ( F_5 () ) {
return ( V_11 ) ;
}
F_6 () ;
F_16 ( V_14 , V_15 , V_3 ) ;
return ( V_12 ) ;
}
F_17 ( V_14 , V_15 ) ;
F_16 ( V_14 , V_15 , V_3 ) ;
return ( V_12 ) ;
}
if ( V_7 >= 0 ) {
V_6 = V_5 ;
F_7 ( V_6 ) ;
F_18 ( V_6 , V_7 , V_14 , V_15 ) ;
if ( F_9 ( V_5 ) ) {
F_19 ( V_14 , V_15 ) ;
}
F_16 ( V_14 , V_15 , V_3 ) ;
if ( F_11 ( V_5 , V_7 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
else {
F_20 ( V_14 , V_15 ) ;
F_16 ( V_14 , V_15 , V_3 ) ;
if ( F_14 ( V_5 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
return ( V_12 ) ;
}
int
F_21 (
T_3 * V_1 ,
unsigned int * V_2 ,
int * V_3 ,
unsigned int * V_4 )
{
register unsigned int V_17 , V_18 , V_19 , V_20 ;
register int V_7 , V_8 ;
F_22 ( V_1 , V_17 , V_18 ) ;
V_7 = F_23 ( V_17 ) - V_21 ;
if ( V_7 > V_10 ) {
if ( F_24 ( V_7 , V_17 , V_18 ) ) {
if ( F_25 ( V_17 ) ) V_8 = 0x7fffffff ;
else V_8 = 0x80000000 ;
if ( F_5 () ) {
return ( V_11 ) ;
}
F_6 () ;
* V_3 = V_8 ;
return ( V_12 ) ;
}
}
if ( V_7 >= 0 ) {
V_19 = V_17 ;
V_20 = V_18 ;
F_26 ( V_19 ) ;
F_27 ( V_19 , V_20 , V_7 ) ;
if ( F_28 ( V_17 ) && ( V_7 <= V_10 ) )
V_8 = - F_29 ( V_19 ) ;
else V_8 = F_29 ( V_19 ) ;
* V_3 = V_8 ;
if ( F_30 ( V_17 , V_18 , V_7 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
else {
* V_3 = 0 ;
if ( F_31 ( V_17 , V_18 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
return ( V_12 ) ;
}
int
F_32 (
T_3 * V_1 ,
unsigned int * V_2 ,
T_2 * V_3 ,
unsigned int * V_4 )
{
register int V_7 , V_14 ;
register unsigned int V_17 , V_18 , V_19 , V_20 , V_15 ;
F_22 ( V_1 , V_17 , V_18 ) ;
V_7 = F_23 ( V_17 ) - V_21 ;
if ( V_7 > V_16 ) {
if ( ( V_7 > V_16 + 1 ) ||
F_33 ( V_17 , V_18 ) || F_25 ( V_17 ) ) {
if ( F_25 ( V_17 ) ) {
V_14 = 0x7fffffff ;
V_15 = 0xffffffff ;
}
else {
V_14 = 0x80000000 ;
V_15 = 0 ;
}
if ( F_5 () ) {
return ( V_11 ) ;
}
F_6 () ;
F_16 ( V_14 , V_15 , V_3 ) ;
return ( V_12 ) ;
}
}
if ( V_7 >= 0 ) {
V_19 = V_17 ;
V_20 = V_18 ;
F_26 ( V_19 ) ;
F_34 ( V_19 , V_20 , V_7 ,
V_14 , V_15 ) ;
if ( F_28 ( V_17 ) ) {
F_19 ( V_14 , V_15 ) ;
}
F_16 ( V_14 , V_15 , V_3 ) ;
if ( F_30 ( V_17 , V_18 , V_7 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
else {
F_20 ( V_14 , V_15 ) ;
F_16 ( V_14 , V_15 , V_3 ) ;
if ( F_31 ( V_17 , V_18 ) ) {
if ( F_12 () ) return ( V_13 ) ;
else F_13 () ;
}
}
return ( V_12 ) ;
}
