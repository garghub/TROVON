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
F_5 ( V_10 ) ;
V_6 -> V_11 . V_12 = * V_9 ;
* V_9 = V_6 ;
V_13 ;
}
union V_4 * F_6 ( union V_4
* * V_9 )
{
union V_4 * V_6 ;
F_5 ( V_14 ) ;
V_6 = * V_9 ;
if ( V_6 ) {
* V_9 = V_6 -> V_11 . V_12 ;
}
F_7 ( V_6 ) ;
}
union V_4 * F_8 ( void )
{
union V_4 * V_6 ;
F_2 () ;
V_6 = F_9 ( V_15 ) ;
if ( V_6 ) {
memset ( V_6 , 0 , sizeof( union V_4 ) ) ;
V_6 -> V_11 . V_16 = V_17 ;
}
return ( V_6 ) ;
}
struct V_18 * F_10 ( void )
{
union V_4 * V_6 ;
F_5 ( V_19 ) ;
V_6 = F_8 () ;
if ( ! V_6 ) {
F_7 ( NULL ) ;
}
V_6 -> V_11 . V_16 = V_20 ;
V_6 -> V_21 . V_22 = F_11 () ;
if ( ! V_6 -> V_21 . V_22 ) {
F_12 ( ( V_23 , L_1 ) ) ;
V_6 -> V_21 . V_22 = ( V_24 ) 1 ;
}
F_7 ( (struct V_18 * ) V_6 ) ;
}
union V_4 * F_13 ( union V_25
* V_26 , T_2 V_27 )
{
union V_4 * V_6 ;
F_14 ( V_28 , V_26 ) ;
V_6 = F_8 () ;
if ( ! V_6 ) {
F_7 ( NULL ) ;
}
V_6 -> V_11 . V_16 = V_29 ;
V_6 -> V_30 . V_26 = V_26 ;
V_6 -> V_30 . V_31 = V_27 ;
F_7 ( V_6 ) ;
}
union V_4 * F_3 ( void * V_1 ,
void * V_2 ,
T_2 V_3 )
{
union V_4 * V_6 ;
F_14 ( V_32 , V_1 ) ;
V_6 = F_8 () ;
if ( ! V_6 ) {
F_7 ( NULL ) ;
}
V_6 -> V_11 . V_16 = V_33 ;
V_6 -> V_34 . V_35 = (union V_25 * ) V_1 ;
V_6 -> V_34 . V_36 = V_2 ;
V_6 -> V_34 . V_3 = V_3 ;
V_6 -> V_34 . V_37 = 1 ;
F_7 ( V_6 ) ;
}
union V_4 * F_15 ( void )
{
union V_4 * V_6 ;
F_5 ( V_38 ) ;
V_6 = F_8 () ;
if ( ! V_6 ) {
F_7 ( NULL ) ;
}
V_6 -> V_11 . V_16 = V_39 ;
V_6 -> V_11 . V_6 = V_40 ;
F_7 ( V_6 ) ;
}
void F_16 ( union V_4 * V_6 )
{
F_5 ( V_41 ) ;
if ( V_6 ) {
( void ) F_17 ( V_15 , V_6 ) ;
}
V_13 ;
}
