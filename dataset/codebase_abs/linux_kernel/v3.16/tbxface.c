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
F_7 ( V_7 , 0 ,
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
V_9 = F_8 () ;
if ( ! V_9 ) {
F_6 ( V_14 ) ;
}
V_10 = F_9 ( V_9 ) ;
F_6 ( V_10 ) ;
}
T_1 T_3 F_10 ( void )
{
T_1 V_10 ;
F_4 ( F_10 ) ;
if ( V_2 . V_4 & V_15 ) {
F_6 ( V_16 ) ;
}
V_2 . V_4 |= V_5 ;
V_10 = F_2 () ;
F_6 ( V_10 ) ;
}
T_1
F_11 ( char * V_17 ,
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
if ( ! F_12
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
F_13 ( V_2 .
V_12 [ V_21 ] . V_29 ,
sizeof( struct
V_19 ) ) ;
if ( ! V_23 ) {
return ( V_30 ) ;
}
F_14 ( V_20 , V_23 ,
sizeof( struct V_19 ) ) ;
F_15 ( V_23 ,
sizeof( struct
V_19 ) ) ;
} else {
return ( V_14 ) ;
}
} else {
F_14 ( V_20 ,
V_2 . V_12 [ V_21 ] . V_26 ,
sizeof( struct V_19 ) ) ;
}
return ( V_31 ) ;
}
return ( V_14 ) ;
}
T_1 F_16 ( T_6 V_32 )
{
int V_21 ;
T_1 V_10 = V_33 ;
F_4 ( F_16 ) ;
for ( V_21 = 0 ; V_21 < V_2 . V_25 ; ++ V_21 ) {
if ( V_32 != V_2 . V_12 [ V_21 ] . V_34 ) {
continue;
}
F_17 ( V_21 ) ;
V_10 = F_18 ( V_21 ) ;
F_19 ( V_21 , FALSE ) ;
break;
}
F_6 ( V_10 ) ;
}
T_1
F_20 ( char * V_17 ,
T_2 V_18 , struct V_19 * * V_35 ,
V_11 * V_36 )
{
T_2 V_21 ;
T_2 V_22 ;
T_1 V_10 ;
if ( ! V_17 || ! V_35 ) {
return ( V_24 ) ;
}
for ( V_21 = 0 , V_22 = 0 ; V_21 < V_2 . V_25 ;
V_21 ++ ) {
if ( ! F_12
( & ( V_2 . V_12 [ V_21 ] . V_17 ) ,
V_17 ) ) {
continue;
}
if ( ++ V_22 < V_18 ) {
continue;
}
V_10 =
F_21 ( & V_2 . V_12 [ V_21 ] ) ;
if ( F_22 ( V_10 ) ) {
* V_35 = V_2 . V_12 [ V_21 ] . V_26 ;
* V_36 = V_2 . V_12 [ V_21 ] . V_37 ;
}
if ( ! V_38 ) {
V_2 . V_12 [ V_21 ] . V_26 = NULL ;
}
return ( V_10 ) ;
}
return ( V_14 ) ;
}
T_1
F_23 ( char * V_17 ,
T_2 V_18 , struct V_19 * * V_35 )
{
V_11 V_36 ;
return F_20 ( V_17 ,
V_18 , V_35 , & V_36 ) ;
}
T_1
F_24 ( T_2 V_39 , struct V_19 * * V_40 )
{
T_1 V_10 ;
F_4 ( F_24 ) ;
if ( ! V_40 ) {
F_6 ( V_24 ) ;
}
( void ) F_25 ( V_41 ) ;
if ( V_39 >= V_2 . V_25 ) {
( void ) F_26 ( V_41 ) ;
F_6 ( V_24 ) ;
}
if ( ! V_2 . V_12 [ V_39 ] . V_26 ) {
V_10 =
F_21 ( & V_2 .
V_12 [ V_39 ] ) ;
if ( F_5 ( V_10 ) ) {
( void ) F_26 ( V_41 ) ;
F_6 ( V_10 ) ;
}
}
* V_40 = V_2 . V_12 [ V_39 ] . V_26 ;
( void ) F_26 ( V_41 ) ;
F_6 ( V_31 ) ;
}
T_1
F_27 ( T_7 V_42 , void * V_43 )
{
T_1 V_10 ;
F_4 ( F_27 ) ;
if ( ! V_42 ) {
F_6 ( V_24 ) ;
}
V_10 = F_25 ( V_44 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_45 ) {
V_10 = V_46 ;
goto V_47;
}
V_45 = V_42 ;
V_48 = V_43 ;
V_47:
( void ) F_26 ( V_44 ) ;
F_6 ( V_10 ) ;
}
T_1 F_28 ( T_7 V_42 )
{
T_1 V_10 ;
F_4 ( F_28 ) ;
V_10 = F_25 ( V_44 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_42 || V_42 != V_45 ) {
V_10 = V_24 ;
goto V_47;
}
V_45 = NULL ;
V_47:
( void ) F_26 ( V_44 ) ;
F_6 ( V_10 ) ;
}
