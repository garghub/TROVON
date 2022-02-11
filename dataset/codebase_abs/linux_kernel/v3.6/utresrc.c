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
T_2 V_10 [ 2 ] = { 0x79 , 0x00 } ;
F_2 ( V_11 ) ;
if ( V_2 < sizeof( struct V_12 ) ) {
F_3 ( V_13 ) ;
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
F_3 ( V_5 ) ;
}
}
if ( F_7 ( V_1 ) ==
V_14 ) {
if ( ( V_1 + 1 ) >= V_6 ) {
F_3 ( V_13 ) ;
}
if ( ! V_3 ) {
* V_4 = V_1 ;
}
F_3 ( V_15 ) ;
}
V_1 += V_8 ;
V_9 += V_8 ;
}
if ( V_3 ) {
( void ) F_4 ( V_10 , & V_7 ) ;
V_5 =
V_3 ( V_10 , 2 , V_9 , V_7 , V_4 ) ;
if ( F_5 ( V_5 ) ) {
F_3 ( V_5 ) ;
}
}
F_3 ( V_13 ) ;
}
T_1 F_4 ( void * V_1 , T_2 * V_16 )
{
union V_17 * V_17 ;
T_2 V_18 ;
T_2 V_7 ;
T_6 V_19 ;
T_6 V_20 ;
F_8 () ;
V_18 = F_9 ( V_1 ) ;
if ( V_18 & V_21 ) {
if ( V_18 > V_22 ) {
goto V_23;
}
V_7 = ( T_2 ) ( V_18 - 0x70 ) ;
} else {
V_7 = ( T_2 )
( ( V_18 & V_24 ) >> 3 ) ;
}
if ( ! V_25 [ V_7 ] ) {
goto V_23;
}
V_19 = F_10 ( V_1 ) ;
V_20 = V_26 [ V_7 ] ;
switch ( V_25 [ V_7 ] ) {
case V_27 :
if ( V_19 != V_20 ) {
goto V_28;
}
break;
case V_29 :
if ( V_19 < V_20 ) {
goto V_28;
}
break;
case V_30 :
if ( ( V_19 > V_20 ) ||
( V_19 < ( V_20 - 1 ) ) ) {
goto V_28;
}
break;
default:
goto V_23;
}
V_17 = F_11 ( union V_17 , V_1 ) ;
if ( V_18 == V_31 ) {
if ( ( V_17 -> V_32 . type == 0 ) ||
( V_17 -> V_32 . type >
V_33 ) ) {
F_12 ( ( V_34 ,
L_1 ,
V_17 -> V_32 .
type ) ) ;
return ( V_35 ) ;
}
}
if ( V_16 ) {
* V_16 = V_7 ;
}
return ( V_15 ) ;
V_23:
F_12 ( ( V_34 ,
L_2 ,
V_18 ) ) ;
return ( V_35 ) ;
V_28:
F_12 ( ( V_34 ,
L_3
L_4 ,
V_18 , V_19 ,
V_20 ) ) ;
return ( V_36 ) ;
}
T_2 F_7 ( void * V_1 )
{
F_8 () ;
if ( F_9 ( V_1 ) & V_21 ) {
return ( F_9 ( V_1 ) ) ;
} else {
return ( ( T_2 ) ( F_9 ( V_1 ) & V_24 ) ) ;
}
}
T_7 F_10 ( void * V_1 )
{
T_6 V_19 ;
F_8 () ;
if ( F_9 ( V_1 ) & V_21 ) {
F_13 ( & V_19 , F_14 ( T_2 , V_1 , 1 ) ) ;
} else {
V_19 = ( T_7 ) ( F_9 ( V_1 ) &
V_37 ) ;
}
return ( V_19 ) ;
}
T_2 F_15 ( void * V_1 )
{
F_8 () ;
if ( F_9 ( V_1 ) & V_21 ) {
return ( sizeof( struct V_38 ) ) ;
} else {
return ( sizeof( struct V_39 ) ) ;
}
}
T_5 F_6 ( void * V_1 )
{
F_8 () ;
return ( F_10 ( V_1 ) +
F_15 ( V_1 ) ) ;
}
T_1
F_16 ( union V_40 * V_41 ,
T_2 * * V_10 )
{
T_1 V_5 ;
F_2 ( V_42 ) ;
if ( ! V_41 -> V_43 . V_8 ) {
* V_10 = V_41 -> V_43 . V_44 ;
F_3 ( V_15 ) ;
}
V_5 = F_1 ( V_41 -> V_43 . V_44 ,
V_41 -> V_43 . V_8 , NULL ,
( void * * ) V_10 ) ;
F_3 ( V_5 ) ;
}
