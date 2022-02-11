T_1
F_1 ( void * V_1 ,
void * V_2 ,
T_2 V_3 ,
union V_4 * * V_5 )
{
union V_4 * V_6 ;
F_2 () ;
V_6 =
F_3 ( V_1 , V_2 , V_3 ) ;
if ( ! V_6 ) {
return ( V_7 ) ;
}
F_4 ( V_5 , V_6 ) ;
return ( V_8 ) ;
}
void
F_4 ( union V_4 * * V_9 ,
union V_4 * V_6 )
{
F_2 () ;
V_6 -> V_10 . V_11 = * V_9 ;
* V_9 = V_6 ;
return;
}
union V_4 * F_5 ( union V_4
* * V_9 )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = * V_9 ;
if ( V_6 ) {
* V_9 = V_6 -> V_10 . V_11 ;
}
return ( V_6 ) ;
}
union V_4 * F_6 ( void )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_7 ( V_12 ) ;
if ( V_6 ) {
V_6 -> V_10 . V_13 = V_14 ;
}
return ( V_6 ) ;
}
struct V_15 * F_8 ( void )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_6 () ;
if ( ! V_6 ) {
return ( NULL ) ;
}
V_6 -> V_10 . V_13 = V_16 ;
V_6 -> V_17 . V_18 = F_9 () ;
if ( ! V_6 -> V_17 . V_18 ) {
F_10 ( ( V_19 , L_1 ) ) ;
V_6 -> V_17 . V_18 = ( V_20 ) 1 ;
}
return ( (struct V_15 * ) V_6 ) ;
}
union V_4 * F_11 ( union V_21
* V_22 , T_2 V_23 )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_6 () ;
if ( ! V_6 ) {
return ( NULL ) ;
}
V_6 -> V_10 . V_13 = V_24 ;
V_6 -> V_25 . V_22 = V_22 ;
V_6 -> V_25 . V_26 = V_23 ;
return ( V_6 ) ;
}
union V_4 * F_3 ( void * V_1 ,
void * V_2 ,
T_2 V_3 )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_6 () ;
if ( ! V_6 ) {
return ( NULL ) ;
}
V_6 -> V_10 . V_13 = V_27 ;
V_6 -> V_28 . V_29 = (union V_21 * ) V_1 ;
V_6 -> V_28 . V_30 = V_2 ;
V_6 -> V_28 . V_3 = V_3 ;
V_6 -> V_28 . V_31 = 1 ;
return ( V_6 ) ;
}
union V_4 * F_12 ( void )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_6 () ;
if ( ! V_6 ) {
return ( NULL ) ;
}
V_6 -> V_10 . V_13 = V_32 ;
V_6 -> V_10 . V_6 = V_33 ;
return ( V_6 ) ;
}
void F_13 ( union V_4 * V_6 )
{
F_2 () ;
if ( V_6 ) {
( void ) F_14 ( V_12 , V_6 ) ;
}
return;
}
