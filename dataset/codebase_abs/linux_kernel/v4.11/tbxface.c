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
T_2 V_15 ;
F_4 ( F_9 ) ;
if ( V_2 . V_4 & V_16 ) {
F_6 ( V_17 ) ;
}
for ( V_15 = 0 ; V_15 < V_2 . V_18 ; ++ V_15 ) {
if ( V_2 . V_12 [ V_15 ] . V_19 ) {
F_10 ( ( V_20 ,
L_1 ,
V_2 . V_12 [ V_15 ] .
V_21 . V_22 ) ) ;
}
}
V_2 . V_4 |= V_5 ;
V_10 = F_2 () ;
F_6 ( V_10 ) ;
}
T_1
F_11 ( char * V_21 ,
T_2 V_23 , struct V_24 * V_25 )
{
T_2 V_15 ;
T_2 V_26 ;
struct V_24 * V_27 ;
if ( ! V_21 || ! V_25 ) {
return ( V_28 ) ;
}
for ( V_15 = 0 , V_26 = 0 ; V_15 < V_2 . V_18 ;
V_15 ++ ) {
if ( ! F_12
( & ( V_2 . V_12 [ V_15 ] . V_21 ) ,
V_21 ) ) {
continue;
}
if ( ++ V_26 < V_23 ) {
continue;
}
if ( ! V_2 . V_12 [ V_15 ] . V_19 ) {
if ( ( V_2 . V_12 [ V_15 ] . V_4 &
V_29 ) ==
V_30 ) {
V_27 =
F_13 ( V_2 .
V_12 [ V_15 ] . V_31 ,
sizeof( struct
V_24 ) ) ;
if ( ! V_27 ) {
return ( V_32 ) ;
}
memcpy ( V_25 , V_27 ,
sizeof( struct V_24 ) ) ;
F_14 ( V_27 ,
sizeof( struct
V_24 ) ) ;
} else {
return ( V_14 ) ;
}
} else {
memcpy ( V_25 ,
V_2 . V_12 [ V_15 ] . V_19 ,
sizeof( struct V_24 ) ) ;
}
return ( V_33 ) ;
}
return ( V_14 ) ;
}
T_1
F_15 ( char * V_21 ,
T_2 V_23 , struct V_24 * * V_34 )
{
T_2 V_15 ;
T_2 V_26 ;
T_1 V_10 = V_14 ;
struct V_6 * V_35 ;
if ( ! V_21 || ! V_34 ) {
return ( V_28 ) ;
}
* V_34 = NULL ;
( void ) F_16 ( V_36 ) ;
for ( V_15 = 0 , V_26 = 0 ; V_15 < V_2 . V_18 ;
V_15 ++ ) {
V_35 = & V_2 . V_12 [ V_15 ] ;
if ( ! F_12 ( & V_35 -> V_21 , V_21 ) ) {
continue;
}
if ( ++ V_26 < V_23 ) {
continue;
}
V_10 = F_17 ( V_35 , V_34 ) ;
break;
}
( void ) F_18 ( V_36 ) ;
return ( V_10 ) ;
}
void F_19 ( struct V_24 * V_37 )
{
T_2 V_15 ;
struct V_6 * V_35 ;
F_4 ( F_19 ) ;
( void ) F_16 ( V_36 ) ;
for ( V_15 = 0 ; V_15 < V_2 . V_18 ; V_15 ++ ) {
V_35 = & V_2 . V_12 [ V_15 ] ;
if ( V_35 -> V_19 != V_37 ) {
continue;
}
F_20 ( V_35 ) ;
break;
}
( void ) F_18 ( V_36 ) ;
V_38 ;
}
T_1
F_21 ( T_2 V_39 , struct V_24 * * V_34 )
{
T_1 V_10 ;
F_4 ( F_21 ) ;
if ( ! V_34 ) {
F_6 ( V_28 ) ;
}
* V_34 = NULL ;
( void ) F_16 ( V_36 ) ;
if ( V_39 >= V_2 . V_18 ) {
V_10 = V_28 ;
goto V_40;
}
V_10 =
F_17 ( & V_2 . V_12 [ V_39 ] ,
V_34 ) ;
V_40:
( void ) F_18 ( V_36 ) ;
F_6 ( V_10 ) ;
}
T_1
F_22 ( T_6 V_41 , void * V_42 )
{
T_1 V_10 ;
F_4 ( F_22 ) ;
if ( ! V_41 ) {
F_6 ( V_28 ) ;
}
V_10 = F_16 ( V_43 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_44 ) {
V_10 = V_45 ;
goto V_46;
}
V_44 = V_41 ;
V_47 = V_42 ;
V_46:
( void ) F_18 ( V_43 ) ;
F_6 ( V_10 ) ;
}
T_1 F_23 ( T_6 V_41 )
{
T_1 V_10 ;
F_4 ( F_23 ) ;
V_10 = F_16 ( V_43 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_41 || V_41 != V_44 ) {
V_10 = V_28 ;
goto V_46;
}
V_44 = NULL ;
V_46:
( void ) F_18 ( V_43 ) ;
F_6 ( V_10 ) ;
}
