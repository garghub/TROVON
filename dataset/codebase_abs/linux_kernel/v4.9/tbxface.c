T_1 F_1 ( T_2 V_1 )
{
V_2 . V_3 = V_1 ;
V_2 . V_4 = V_5 ;
return ( F_2 () ) ;
}
T_1 T_3
F_3 ( struct V_6 * V_7 ,
T_2 V_1 , T_4 V_8 )
{
T_5 V_9 ;
T_1 V_10 ;
F_4 ( F_3 ) ;
if ( ! V_7 ) {
V_10 = F_1 ( V_1 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
} else {
memset ( V_7 , 0 ,
( V_11 ) V_1 *
sizeof( struct V_6 ) ) ;
V_2 . V_12 = V_7 ;
V_2 . V_3 = V_1 ;
V_2 . V_4 = V_13 ;
if ( V_8 ) {
V_2 . V_4 |=
V_5 ;
}
}
V_9 = F_7 () ;
if ( ! V_9 ) {
F_6 ( V_14 ) ;
}
V_10 = F_8 ( V_9 ) ;
F_6 ( V_10 ) ;
}
T_1 T_3 F_9 ( void )
{
T_1 V_10 ;
F_4 ( F_9 ) ;
if ( V_2 . V_4 & V_15 ) {
F_6 ( V_16 ) ;
}
V_2 . V_4 |= V_5 ;
V_10 = F_2 () ;
F_6 ( V_10 ) ;
}
T_1
F_10 ( char * V_17 ,
T_2 V_18 , struct V_19 * V_20 )
{
T_2 V_21 ;
T_2 V_22 ;
struct V_19 * V_23 ;
if ( ! V_17 || ! V_20 ) {
return ( V_24 ) ;
}
for ( V_21 = 0 , V_22 = 0 ; V_21 < V_2 . V_25 ;
V_21 ++ ) {
if ( ! F_11
( & ( V_2 . V_12 [ V_21 ] . V_17 ) ,
V_17 ) ) {
continue;
}
if ( ++ V_22 < V_18 ) {
continue;
}
if ( ! V_2 . V_12 [ V_21 ] . V_26 ) {
if ( ( V_2 . V_12 [ V_21 ] . V_4 &
V_27 ) ==
V_28 ) {
V_23 =
F_12 ( V_2 .
V_12 [ V_21 ] . V_29 ,
sizeof( struct
V_19 ) ) ;
if ( ! V_23 ) {
return ( V_30 ) ;
}
memcpy ( V_20 , V_23 ,
sizeof( struct V_19 ) ) ;
F_13 ( V_23 ,
sizeof( struct
V_19 ) ) ;
} else {
return ( V_14 ) ;
}
} else {
memcpy ( V_20 ,
V_2 . V_12 [ V_21 ] . V_26 ,
sizeof( struct V_19 ) ) ;
}
return ( V_31 ) ;
}
return ( V_14 ) ;
}
T_1
F_14 ( char * V_17 ,
T_2 V_18 , struct V_19 * * V_32 ,
V_11 * V_33 )
{
T_2 V_21 ;
T_2 V_22 ;
T_1 V_10 ;
if ( ! V_17 || ! V_32 ) {
return ( V_24 ) ;
}
for ( V_21 = 0 , V_22 = 0 ; V_21 < V_2 . V_25 ;
V_21 ++ ) {
if ( ! F_11
( & ( V_2 . V_12 [ V_21 ] . V_17 ) ,
V_17 ) ) {
continue;
}
if ( ++ V_22 < V_18 ) {
continue;
}
V_10 =
F_15 ( & V_2 . V_12 [ V_21 ] ) ;
if ( F_16 ( V_10 ) ) {
* V_32 = V_2 . V_12 [ V_21 ] . V_26 ;
* V_33 = V_2 . V_12 [ V_21 ] . V_34 ;
}
if ( ! V_35 ) {
V_2 . V_12 [ V_21 ] . V_26 = NULL ;
}
return ( V_10 ) ;
}
return ( V_14 ) ;
}
T_1
F_17 ( char * V_17 ,
T_2 V_18 , struct V_19 * * V_32 )
{
V_11 V_33 ;
return F_14 ( V_17 ,
V_18 , V_32 , & V_33 ) ;
}
T_1
F_18 ( T_2 V_36 , struct V_19 * * V_37 )
{
T_1 V_10 ;
F_4 ( F_18 ) ;
if ( ! V_37 ) {
F_6 ( V_24 ) ;
}
( void ) F_19 ( V_38 ) ;
if ( V_36 >= V_2 . V_25 ) {
( void ) F_20 ( V_38 ) ;
F_6 ( V_24 ) ;
}
if ( ! V_2 . V_12 [ V_36 ] . V_26 ) {
V_10 =
F_15 ( & V_2 .
V_12 [ V_36 ] ) ;
if ( F_5 ( V_10 ) ) {
( void ) F_20 ( V_38 ) ;
F_6 ( V_10 ) ;
}
}
* V_37 = V_2 . V_12 [ V_36 ] . V_26 ;
( void ) F_20 ( V_38 ) ;
F_6 ( V_31 ) ;
}
T_1
F_21 ( T_6 V_39 , void * V_40 )
{
T_1 V_10 ;
F_4 ( F_21 ) ;
if ( ! V_39 ) {
F_6 ( V_24 ) ;
}
V_10 = F_19 ( V_41 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_42 ) {
V_10 = V_43 ;
goto V_44;
}
V_42 = V_39 ;
V_45 = V_40 ;
V_44:
( void ) F_20 ( V_41 ) ;
F_6 ( V_10 ) ;
}
T_1 F_22 ( T_6 V_39 )
{
T_1 V_10 ;
F_4 ( F_22 ) ;
V_10 = F_19 ( V_41 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_39 || V_39 != V_42 ) {
V_10 = V_24 ;
goto V_44;
}
V_42 = NULL ;
V_44:
( void ) F_20 ( V_41 ) ;
F_6 ( V_10 ) ;
}
