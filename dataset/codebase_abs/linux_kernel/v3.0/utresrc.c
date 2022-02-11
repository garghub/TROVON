T_1
F_1 ( T_2 * V_1 ,
T_3 V_2 ,
T_4 V_3 , void * * V_4 )
{
T_1 V_5 ;
T_2 * V_6 ;
T_2 V_7 ;
T_5 V_8 ;
T_5 V_9 = 0 ;
F_2 ( V_10 ) ;
if ( V_2 < sizeof( struct V_11 ) ) {
F_3 ( V_12 ) ;
}
V_6 = V_1 + V_2 ;
while ( V_1 < V_6 ) {
V_5 = F_4 ( V_1 , & V_7 ) ;
if ( F_5 ( V_5 ) ) {
F_3 ( V_5 ) ;
}
V_8 = F_6 ( V_1 ) ;
if ( V_3 ) {
V_5 =
V_3 ( V_1 , V_8 , V_9 , V_7 ,
V_4 ) ;
if ( F_5 ( V_5 ) ) {
return ( V_5 ) ;
}
}
if ( F_7 ( V_1 ) ==
V_13 ) {
if ( ( V_1 + 1 ) >= V_6 ) {
F_3 ( V_12 ) ;
}
if ( ! V_3 ) {
* V_4 = V_1 ;
}
F_3 ( V_14 ) ;
}
V_1 += V_8 ;
V_9 += V_8 ;
}
return ( V_12 ) ;
}
T_1 F_4 ( void * V_1 , T_2 * V_15 )
{
T_2 V_16 ;
T_2 V_7 ;
T_6 V_17 ;
T_6 V_18 ;
F_8 () ;
V_16 = F_9 ( V_1 ) ;
if ( V_16 & V_19 ) {
if ( V_16 > V_20 ) {
return ( V_21 ) ;
}
V_7 = ( T_2 ) ( V_16 - 0x70 ) ;
} else {
V_7 = ( T_2 )
( ( V_16 & V_22 ) >> 3 ) ;
}
if ( ! V_23 [ V_7 ] ) {
return ( V_21 ) ;
}
V_17 = F_10 ( V_1 ) ;
V_18 = V_24 [ V_7 ] ;
switch ( V_23 [ V_7 ] ) {
case V_25 :
if ( V_17 != V_18 ) {
return ( V_26 ) ;
}
break;
case V_27 :
if ( V_17 < V_18 ) {
return ( V_26 ) ;
}
break;
case V_28 :
if ( ( V_17 > V_18 ) ||
( V_17 < ( V_18 - 1 ) ) ) {
return ( V_26 ) ;
}
break;
default:
return ( V_21 ) ;
}
if ( V_15 ) {
* V_15 = V_7 ;
}
return ( V_14 ) ;
}
T_2 F_7 ( void * V_1 )
{
F_8 () ;
if ( F_9 ( V_1 ) & V_19 ) {
return ( F_9 ( V_1 ) ) ;
} else {
return ( ( T_2 ) ( F_9 ( V_1 ) & V_22 ) ) ;
}
}
T_7 F_10 ( void * V_1 )
{
T_6 V_17 ;
F_8 () ;
if ( F_9 ( V_1 ) & V_19 ) {
F_11 ( & V_17 , F_12 ( T_2 , V_1 , 1 ) ) ;
} else {
V_17 = ( T_7 ) ( F_9 ( V_1 ) &
V_29 ) ;
}
return ( V_17 ) ;
}
T_2 F_13 ( void * V_1 )
{
F_8 () ;
if ( F_9 ( V_1 ) & V_19 ) {
return ( sizeof( struct V_30 ) ) ;
} else {
return ( sizeof( struct V_31 ) ) ;
}
}
T_5 F_6 ( void * V_1 )
{
F_8 () ;
return ( F_10 ( V_1 ) +
F_13 ( V_1 ) ) ;
}
T_1
F_14 ( union V_32 * V_33 ,
T_2 * * V_34 )
{
T_1 V_5 ;
F_2 ( V_35 ) ;
if ( ! V_33 -> V_36 . V_8 ) {
* V_34 = V_33 -> V_36 . V_37 ;
F_3 ( V_14 ) ;
}
V_5 = F_1 ( V_33 -> V_36 . V_37 ,
V_33 -> V_36 . V_8 , NULL ,
( void * * ) V_34 ) ;
F_3 ( V_5 ) ;
}
