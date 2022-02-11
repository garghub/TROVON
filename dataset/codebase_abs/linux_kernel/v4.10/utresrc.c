T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 ,
T_3 V_4 ,
T_4 V_5 , void * * V_6 )
{
T_1 V_7 ;
T_2 * V_8 ;
T_2 V_9 ;
T_5 V_10 ;
T_5 V_11 = 0 ;
T_2 V_12 [ 2 ] = { 0x79 , 0x00 } ;
F_2 ( V_13 ) ;
if ( V_4 < sizeof( struct V_14 ) ) {
F_3 ( V_15 ) ;
}
V_8 = V_3 + V_4 ;
while ( V_3 < V_8 ) {
V_7 =
F_4 ( V_2 , V_3 , & V_9 ) ;
if ( F_5 ( V_7 ) ) {
F_3 ( V_7 ) ;
}
V_10 = F_6 ( V_3 ) ;
if ( V_5 ) {
V_7 =
V_5 ( V_3 , V_10 , V_11 , V_9 ,
V_6 ) ;
if ( F_5 ( V_7 ) ) {
F_3 ( V_7 ) ;
}
}
if ( F_7 ( V_3 ) ==
V_16 ) {
if ( ( V_3 + 1 ) >= V_8 ) {
F_3 ( V_15 ) ;
}
if ( ! V_5 ) {
* V_6 = V_3 ;
}
F_3 ( V_17 ) ;
}
V_3 += V_10 ;
V_11 += V_10 ;
}
if ( V_5 ) {
( void ) F_4 ( V_2 , V_12 ,
& V_9 ) ;
V_7 =
V_5 ( V_12 , 2 , V_11 , V_9 , V_6 ) ;
if ( F_5 ( V_7 ) ) {
F_3 ( V_7 ) ;
}
}
F_3 ( V_15 ) ;
}
T_1
F_4 ( struct V_1 * V_2 ,
void * V_3 , T_2 * V_18 )
{
union V_19 * V_19 ;
T_2 V_20 ;
T_2 V_9 ;
T_6 V_21 ;
T_6 V_22 ;
F_8 () ;
V_20 = F_9 ( V_3 ) ;
if ( V_20 & V_23 ) {
if ( V_20 > V_24 ) {
goto V_25;
}
V_9 = ( T_2 ) ( V_20 - 0x70 ) ;
} else {
V_9 = ( T_2 )
( ( V_20 & V_26 ) >> 3 ) ;
}
if ( ! V_27 [ V_9 ] ) {
goto V_25;
}
V_21 = F_10 ( V_3 ) ;
V_22 = V_28 [ V_9 ] ;
switch ( V_27 [ V_9 ] ) {
case V_29 :
if ( V_21 != V_22 ) {
goto V_30;
}
break;
case V_31 :
if ( V_21 < V_22 ) {
goto V_30;
}
break;
case V_32 :
if ( ( V_21 > V_22 ) ||
( V_21 < ( V_22 - 1 ) ) ) {
goto V_30;
}
break;
default:
goto V_25;
}
V_19 = F_11 ( union V_19 , V_3 ) ;
if ( V_20 == V_33 ) {
if ( ( V_19 -> V_34 . type == 0 ) ||
( V_19 -> V_34 . type >
V_35 ) ) {
if ( V_2 ) {
F_12 ( ( V_36 ,
L_1 ,
V_19 -> V_34 .
type ) ) ;
}
return ( V_37 ) ;
}
}
if ( V_18 ) {
* V_18 = V_9 ;
}
return ( V_17 ) ;
V_25:
if ( V_2 ) {
F_12 ( ( V_36 ,
L_2 ,
V_20 ) ) ;
}
return ( V_37 ) ;
V_30:
if ( V_2 ) {
F_12 ( ( V_36 ,
L_3
L_4 ,
V_20 , V_21 ,
V_22 ) ) ;
}
return ( V_38 ) ;
}
T_2 F_7 ( void * V_3 )
{
F_8 () ;
if ( F_9 ( V_3 ) & V_23 ) {
return ( F_9 ( V_3 ) ) ;
} else {
return ( ( T_2 ) ( F_9 ( V_3 ) & V_26 ) ) ;
}
}
T_7 F_10 ( void * V_3 )
{
T_6 V_21 ;
F_8 () ;
if ( F_9 ( V_3 ) & V_23 ) {
F_13 ( & V_21 , F_14 ( T_2 , V_3 , 1 ) ) ;
} else {
V_21 = ( T_7 ) ( F_9 ( V_3 ) &
V_39 ) ;
}
return ( V_21 ) ;
}
T_2 F_15 ( void * V_3 )
{
F_8 () ;
if ( F_9 ( V_3 ) & V_23 ) {
return ( sizeof( struct V_40 ) ) ;
} else {
return ( sizeof( struct V_41 ) ) ;
}
}
T_5 F_6 ( void * V_3 )
{
F_8 () ;
return ( F_10 ( V_3 ) +
F_15 ( V_3 ) ) ;
}
T_1
F_16 ( union V_42 * V_43 , T_2 * * V_12 )
{
T_1 V_7 ;
F_2 ( V_44 ) ;
if ( ! V_43 -> V_45 . V_10 ) {
* V_12 = V_43 -> V_45 . V_46 ;
F_3 ( V_17 ) ;
}
V_7 = F_1 ( NULL , V_43 -> V_45 . V_46 ,
V_43 -> V_45 . V_10 , NULL ,
( void * * ) V_12 ) ;
F_3 ( V_7 ) ;
}
