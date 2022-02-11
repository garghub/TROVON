void
F_1 ( union V_1 * * V_2 ,
union V_1 * V_3 )
{
F_2 () ;
V_3 -> V_4 . V_5 = * V_2 ;
* V_2 = V_3 ;
return;
}
union V_1 * F_3 ( union V_1
* * V_2 )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = * V_2 ;
if ( V_3 ) {
* V_2 = V_3 -> V_4 . V_5 ;
}
return ( V_3 ) ;
}
union V_1 * F_4 ( void )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = F_5 ( V_6 ) ;
if ( V_3 ) {
V_3 -> V_4 . V_7 = V_8 ;
}
return ( V_3 ) ;
}
struct V_9 * F_6 ( void )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = F_4 () ;
if ( ! V_3 ) {
return ( NULL ) ;
}
V_3 -> V_4 . V_7 = V_10 ;
V_3 -> V_11 . V_12 = F_7 () ;
if ( ! V_3 -> V_11 . V_12 ) {
F_8 ( ( V_13 , L_1 ) ) ;
V_3 -> V_11 . V_12 = ( V_14 ) 1 ;
}
return ( (struct V_9 * ) V_3 ) ;
}
union V_1 * F_9 ( union V_15
* V_16 , T_1 V_17 )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = F_4 () ;
if ( ! V_3 ) {
return ( NULL ) ;
}
V_3 -> V_4 . V_7 = V_18 ;
V_3 -> V_19 . V_16 = V_16 ;
V_3 -> V_19 . V_20 = V_17 ;
return ( V_3 ) ;
}
union V_1 * F_10 ( void * V_21 ,
void * V_22 ,
T_2 V_23 )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = F_4 () ;
if ( ! V_3 ) {
return ( NULL ) ;
}
V_3 -> V_4 . V_7 = V_24 ;
V_3 -> V_25 . V_26 = (union V_15 * ) V_21 ;
V_3 -> V_25 . V_27 = V_22 ;
V_3 -> V_25 . V_23 = V_23 ;
V_3 -> V_25 . V_28 = 1 ;
return ( V_3 ) ;
}
union V_1 * F_11 ( void )
{
union V_1 * V_3 ;
F_2 () ;
V_3 = F_4 () ;
if ( ! V_3 ) {
return ( NULL ) ;
}
V_3 -> V_4 . V_7 = V_29 ;
V_3 -> V_4 . V_3 = V_30 ;
return ( V_3 ) ;
}
void F_12 ( union V_1 * V_3 )
{
F_2 () ;
if ( V_3 ) {
( void ) F_13 ( V_6 , V_3 ) ;
}
return;
}
