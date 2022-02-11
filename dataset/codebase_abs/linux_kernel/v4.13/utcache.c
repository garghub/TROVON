T_1
F_1 ( char * V_1 ,
T_2 V_2 ,
T_2 V_3 , struct V_4 * * V_5 )
{
struct V_4 * V_6 ;
F_2 () ;
if ( ! V_1 || ! V_5 || ! V_2 ) {
return ( V_7 ) ;
}
V_6 = F_3 ( sizeof( struct V_4 ) ) ;
if ( ! V_6 ) {
return ( V_8 ) ;
}
memset ( V_6 , 0 , sizeof( struct V_4 ) ) ;
V_6 -> V_9 = V_1 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
* V_5 = V_6 ;
return ( V_10 ) ;
}
T_1 F_4 ( struct V_4 * V_6 )
{
void * V_11 ;
T_1 V_12 ;
F_2 () ;
if ( ! V_6 ) {
return ( V_7 ) ;
}
V_12 = F_5 ( V_13 ) ;
if ( F_6 ( V_12 ) ) {
return ( V_12 ) ;
}
while ( V_6 -> V_14 ) {
V_11 = F_7 ( V_6 -> V_14 ) ;
F_8 ( V_6 -> V_14 ) ;
V_6 -> V_14 = V_11 ;
V_6 -> V_15 -- ;
}
( void ) F_9 ( V_13 ) ;
return ( V_10 ) ;
}
T_1 F_10 ( struct V_4 * V_6 )
{
T_1 V_12 ;
F_2 () ;
V_12 = F_4 ( V_6 ) ;
if ( F_6 ( V_12 ) ) {
return ( V_12 ) ;
}
F_11 ( V_6 ) ;
return ( V_10 ) ;
}
T_1 F_12 ( struct V_4 * V_6 , void * V_16 )
{
T_1 V_12 ;
F_2 () ;
if ( ! V_6 || ! V_16 ) {
return ( V_7 ) ;
}
if ( V_6 -> V_15 >= V_6 -> V_3 ) {
F_8 ( V_16 ) ;
F_13 ( V_6 -> V_17 ++ ) ;
}
else {
V_12 = F_5 ( V_13 ) ;
if ( F_6 ( V_12 ) ) {
return ( V_12 ) ;
}
memset ( V_16 , 0xCA , V_6 -> V_2 ) ;
F_14 ( V_16 , V_18 ) ;
F_15 ( V_16 , V_6 -> V_14 ) ;
V_6 -> V_14 = V_16 ;
V_6 -> V_15 ++ ;
( void ) F_9 ( V_13 ) ;
}
return ( V_10 ) ;
}
void * F_16 ( struct V_4 * V_6 )
{
T_1 V_12 ;
void * V_16 ;
F_17 ( V_19 ) ;
if ( ! V_6 ) {
F_18 ( NULL ) ;
}
V_12 = F_5 ( V_13 ) ;
if ( F_6 ( V_12 ) ) {
F_18 ( NULL ) ;
}
F_13 ( V_6 -> V_20 ++ ) ;
if ( V_6 -> V_14 ) {
V_16 = V_6 -> V_14 ;
V_6 -> V_14 = F_7 ( V_16 ) ;
V_6 -> V_15 -- ;
F_13 ( V_6 -> V_21 ++ ) ;
F_19 ( ( V_22 ,
L_1 , V_16 ,
V_6 -> V_9 ) ) ;
V_12 = F_9 ( V_13 ) ;
if ( F_6 ( V_12 ) ) {
F_18 ( NULL ) ;
}
memset ( V_16 , 0 , V_6 -> V_2 ) ;
} else {
F_13 ( V_6 -> V_23 ++ ) ;
#ifdef F_20
if ( ( V_6 -> V_23 - V_6 -> V_17 ) >
V_6 -> V_24 ) {
V_6 -> V_24 =
V_6 -> V_23 - V_6 -> V_17 ;
}
#endif
V_12 = F_9 ( V_13 ) ;
if ( F_6 ( V_12 ) ) {
F_18 ( NULL ) ;
}
V_16 = F_21 ( V_6 -> V_2 ) ;
if ( ! V_16 ) {
F_18 ( NULL ) ;
}
}
F_18 ( V_16 ) ;
}
