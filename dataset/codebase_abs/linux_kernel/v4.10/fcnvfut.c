int
F_1 ( T_1 * V_1 , unsigned int * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
register unsigned int V_5 , V_6 ;
register int V_7 ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_8 ;
if ( V_7 > V_9 + 1 ) {
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
} else {
V_6 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
if ( F_3 ( V_5 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_11 ) ;
}
F_6 ( V_5 ) ;
F_7 ( V_5 , V_7 , V_6 ) ;
* V_3 = V_6 ;
if ( F_8 ( V_5 , V_7 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
else {
* V_3 = 0 ;
if ( F_11 ( V_5 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
return ( V_11 ) ;
}
int
F_12 ( T_1 * V_1 , unsigned int * V_2 ,
T_2 * V_3 , unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_5 , V_13 , V_14 ;
V_5 = * V_1 ;
V_7 = F_2 ( V_5 ) - V_8 ;
if ( V_7 > V_15 + 1 ) {
if ( F_3 ( V_5 ) ) {
V_13 = V_14 = 0 ;
} else {
V_13 = V_14 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
F_13 ( V_13 , V_14 , V_3 ) ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
if ( F_3 ( V_5 ) ) {
V_13 = V_14 = 0 ;
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
F_13 ( V_13 , V_14 , V_3 ) ;
return ( V_11 ) ;
}
F_6 ( V_5 ) ;
F_14 ( V_5 , V_7 , V_13 , V_14 ) ;
F_13 ( V_13 , V_14 , V_3 ) ;
if ( F_8 ( V_5 , V_7 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
else {
F_15 ( V_13 , V_14 ) ;
F_13 ( V_13 , V_14 , V_3 ) ;
if ( F_11 ( V_5 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
return ( V_11 ) ;
}
int
F_16 ( T_3 * V_1 , unsigned int * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
register unsigned int V_16 , V_17 , V_6 ;
register int V_7 ;
F_17 ( V_1 , V_16 , V_17 ) ;
V_7 = F_18 ( V_16 ) - V_18 ;
if ( V_7 > V_9 + 1 ) {
if ( F_19 ( V_16 ) ) {
V_6 = 0 ;
} else {
V_6 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
if ( F_19 ( V_16 ) ) {
V_6 = 0 ;
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
* V_3 = V_6 ;
return ( V_11 ) ;
}
F_20 ( V_16 ) ;
F_21 ( V_16 , V_17 , V_7 , V_6 ) ;
* V_3 = V_6 ;
if ( F_22 ( V_16 , V_17 , V_7 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
else {
* V_3 = 0 ;
if ( F_23 ( V_16 , V_17 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
return ( V_11 ) ;
}
int
F_24 ( T_3 * V_1 , unsigned int * V_2 ,
T_2 * V_3 , unsigned int * V_4 )
{
register int V_7 ;
register unsigned int V_16 , V_17 , V_13 , V_14 ;
F_17 ( V_1 , V_16 , V_17 ) ;
V_7 = F_18 ( V_16 ) - V_18 ;
if ( V_7 > V_15 + 1 ) {
if ( F_19 ( V_16 ) ) {
V_13 = V_14 = 0 ;
} else {
V_13 = V_14 = 0xffffffff ;
}
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
F_13 ( V_13 , V_14 , V_3 ) ;
return ( V_11 ) ;
}
if ( V_7 >= 0 ) {
if ( F_19 ( V_16 ) ) {
V_13 = V_14 = 0 ;
if ( F_4 () ) {
return ( V_10 ) ;
}
F_5 () ;
F_13 ( V_13 , V_14 , V_3 ) ;
return ( V_11 ) ;
}
F_20 ( V_16 ) ;
F_25 ( V_16 , V_17 , V_7 ,
V_13 , V_14 ) ;
F_13 ( V_13 , V_14 , V_3 ) ;
if ( F_22 ( V_16 , V_17 , V_7 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
else {
F_15 ( V_13 , V_14 ) ;
F_13 ( V_13 , V_14 , V_3 ) ;
if ( F_23 ( V_16 , V_17 ) ) {
if ( F_9 () ) return ( V_12 ) ;
else F_10 () ;
}
}
return ( V_11 ) ;
}
