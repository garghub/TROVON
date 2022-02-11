T_1
F_1 ( char * V_1 ,
T_2 V_2 ,
T_2 V_3 , struct V_4 * * V_5 )
{
struct V_4 * V_6 ;
F_2 () ;
if ( ! V_1 || ! V_5 || ( V_2 < 16 ) ) {
return ( V_7 ) ;
}
V_6 = F_3 ( sizeof( struct V_4 ) ) ;
if ( ! V_6 ) {
return ( V_8 ) ;
}
F_4 ( V_6 , 0 , sizeof( struct V_4 ) ) ;
V_6 -> V_9 = 8 ;
V_6 -> V_10 = V_1 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
* V_5 = V_6 ;
return ( V_11 ) ;
}
T_1 F_5 ( struct V_4 * V_6 )
{
char * V_12 ;
T_1 V_13 ;
F_2 () ;
if ( ! V_6 ) {
return ( V_7 ) ;
}
V_13 = F_6 ( V_14 ) ;
if ( F_7 ( V_13 ) ) {
return ( V_13 ) ;
}
while ( V_6 -> V_15 ) {
V_12 = * ( F_8 ( char ,
& ( ( ( char * ) V_6 ->
V_15 ) [ V_6 ->
V_9 ] ) ) ) ;
F_9 ( V_6 -> V_15 ) ;
V_6 -> V_15 = V_12 ;
V_6 -> V_16 -- ;
}
( void ) F_10 ( V_14 ) ;
return ( V_11 ) ;
}
T_1 F_11 ( struct V_4 * V_6 )
{
T_1 V_13 ;
F_2 () ;
V_13 = F_5 ( V_6 ) ;
if ( F_7 ( V_13 ) ) {
return ( V_13 ) ;
}
F_12 ( V_6 ) ;
return ( V_11 ) ;
}
T_1
F_13 ( struct V_4 * V_6 , void * V_17 )
{
T_1 V_13 ;
F_2 () ;
if ( ! V_6 || ! V_17 ) {
return ( V_7 ) ;
}
if ( V_6 -> V_16 >= V_6 -> V_3 ) {
F_9 ( V_17 ) ;
F_14 ( V_6 -> V_18 ++ ) ;
}
else {
V_13 = F_6 ( V_14 ) ;
if ( F_7 ( V_13 ) ) {
return ( V_13 ) ;
}
F_4 ( V_17 , 0xCA , V_6 -> V_2 ) ;
F_15 ( V_17 , V_19 ) ;
* ( F_8 ( char ,
& ( ( ( char * ) V_17 ) [ V_6 ->
V_9 ] ) ) ) =
V_6 -> V_15 ;
V_6 -> V_15 = V_17 ;
V_6 -> V_16 ++ ;
( void ) F_10 ( V_14 ) ;
}
return ( V_11 ) ;
}
void * F_16 ( struct V_4 * V_6 )
{
T_1 V_13 ;
void * V_17 ;
F_17 ( V_20 ) ;
if ( ! V_6 ) {
return ( NULL ) ;
}
V_13 = F_6 ( V_14 ) ;
if ( F_7 ( V_13 ) ) {
return ( NULL ) ;
}
F_14 ( V_6 -> V_21 ++ ) ;
if ( V_6 -> V_15 ) {
V_17 = V_6 -> V_15 ;
V_6 -> V_15 = * ( F_8 ( char ,
& ( ( ( char * )
V_17 ) [ V_6 ->
V_9 ] ) ) ) ;
V_6 -> V_16 -- ;
F_14 ( V_6 -> V_22 ++ ) ;
F_18 ( ( V_23 ,
L_1 , V_17 ,
V_6 -> V_10 ) ) ;
V_13 = F_10 ( V_14 ) ;
if ( F_7 ( V_13 ) ) {
return ( NULL ) ;
}
F_4 ( V_17 , 0 , V_6 -> V_2 ) ;
} else {
F_14 ( V_6 -> V_24 ++ ) ;
#ifdef F_19
if ( ( V_6 -> V_24 - V_6 -> V_18 ) >
V_6 -> V_25 ) {
V_6 -> V_25 =
V_6 -> V_24 - V_6 -> V_18 ;
}
#endif
V_13 = F_10 ( V_14 ) ;
if ( F_7 ( V_13 ) ) {
return ( NULL ) ;
}
V_17 = F_20 ( V_6 -> V_2 ) ;
if ( ! V_17 ) {
return ( NULL ) ;
}
}
return ( V_17 ) ;
}
