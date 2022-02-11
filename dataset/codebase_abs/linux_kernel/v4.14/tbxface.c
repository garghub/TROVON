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
struct V_6 * V_15 ;
T_2 V_16 , V_17 ;
F_4 ( F_9 ) ;
if ( V_2 . V_4 & V_18 ) {
F_6 ( V_19 ) ;
}
( void ) F_10 ( V_20 ) ;
for ( V_16 = 0 ; V_16 < V_2 . V_21 ; ++ V_16 ) {
V_15 = & V_2 . V_12 [ V_16 ] ;
if ( V_15 -> V_22 ) {
F_11 ( ( V_23 ,
L_1 ,
V_15 -> V_24 . V_25 ) ) ;
}
}
if ( ! V_26 ) {
V_26 = TRUE ;
for ( V_16 = 0 ; V_16 < V_2 . V_21 ;
++ V_16 ) {
V_15 = & V_2 . V_12 [ V_16 ] ;
if ( ! ( V_15 -> V_4 & V_27 ) ) {
V_10 =
F_12 ( V_15 , NULL ,
& V_17 ) ;
if ( F_5 ( V_10 ) ) {
F_13 ( V_15 ) ;
}
}
}
}
V_2 . V_4 |= V_5 ;
V_10 = F_2 () ;
V_2 . V_4 |= V_18 ;
( void ) F_14 ( V_20 ) ;
F_6 ( V_10 ) ;
}
T_1
F_15 ( char * V_24 ,
T_2 V_28 , struct V_29 * V_30 )
{
T_2 V_16 ;
T_2 V_17 ;
struct V_29 * V_31 ;
if ( ! V_24 || ! V_30 ) {
return ( V_32 ) ;
}
for ( V_16 = 0 , V_17 = 0 ; V_16 < V_2 . V_21 ;
V_16 ++ ) {
if ( ! F_16
( & ( V_2 . V_12 [ V_16 ] . V_24 ) ,
V_24 ) ) {
continue;
}
if ( ++ V_17 < V_28 ) {
continue;
}
if ( ! V_2 . V_12 [ V_16 ] . V_22 ) {
if ( ( V_2 . V_12 [ V_16 ] . V_4 &
V_33 ) ==
V_34 ) {
V_31 =
F_17 ( V_2 .
V_12 [ V_16 ] . V_35 ,
sizeof( struct
V_29 ) ) ;
if ( ! V_31 ) {
return ( V_36 ) ;
}
memcpy ( V_30 , V_31 ,
sizeof( struct V_29 ) ) ;
F_18 ( V_31 ,
sizeof( struct
V_29 ) ) ;
} else {
return ( V_14 ) ;
}
} else {
memcpy ( V_30 ,
V_2 . V_12 [ V_16 ] . V_22 ,
sizeof( struct V_29 ) ) ;
}
return ( V_37 ) ;
}
return ( V_14 ) ;
}
T_1
F_19 ( char * V_24 ,
T_2 V_28 , struct V_29 * * V_38 )
{
T_2 V_16 ;
T_2 V_17 ;
T_1 V_10 = V_14 ;
struct V_6 * V_15 ;
if ( ! V_24 || ! V_38 ) {
return ( V_32 ) ;
}
* V_38 = NULL ;
( void ) F_10 ( V_20 ) ;
for ( V_16 = 0 , V_17 = 0 ; V_16 < V_2 . V_21 ;
V_16 ++ ) {
V_15 = & V_2 . V_12 [ V_16 ] ;
if ( ! F_16 ( & V_15 -> V_24 , V_24 ) ) {
continue;
}
if ( ++ V_17 < V_28 ) {
continue;
}
V_10 = F_20 ( V_15 , V_38 ) ;
break;
}
( void ) F_14 ( V_20 ) ;
return ( V_10 ) ;
}
void F_21 ( struct V_29 * V_39 )
{
T_2 V_16 ;
struct V_6 * V_15 ;
F_4 ( F_21 ) ;
if ( ! V_39 ) {
V_40 ;
}
( void ) F_10 ( V_20 ) ;
for ( V_16 = 0 ; V_16 < V_2 . V_21 ; V_16 ++ ) {
V_15 = & V_2 . V_12 [ V_16 ] ;
if ( V_15 -> V_22 != V_39 ) {
continue;
}
F_22 ( V_15 ) ;
break;
}
( void ) F_14 ( V_20 ) ;
V_40 ;
}
T_1
F_23 ( T_2 V_41 , struct V_29 * * V_38 )
{
T_1 V_10 ;
F_4 ( F_23 ) ;
if ( ! V_38 ) {
F_6 ( V_32 ) ;
}
* V_38 = NULL ;
( void ) F_10 ( V_20 ) ;
if ( V_41 >= V_2 . V_21 ) {
V_10 = V_32 ;
goto V_42;
}
V_10 =
F_20 ( & V_2 . V_12 [ V_41 ] ,
V_38 ) ;
V_42:
( void ) F_14 ( V_20 ) ;
F_6 ( V_10 ) ;
}
T_1
F_24 ( T_6 V_43 , void * V_44 )
{
T_1 V_10 ;
F_4 ( F_24 ) ;
if ( ! V_43 ) {
F_6 ( V_32 ) ;
}
V_10 = F_10 ( V_45 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_46 ) {
V_10 = V_47 ;
goto V_48;
}
V_46 = V_43 ;
V_49 = V_44 ;
V_48:
( void ) F_14 ( V_45 ) ;
F_6 ( V_10 ) ;
}
T_1 F_25 ( T_6 V_43 )
{
T_1 V_10 ;
F_4 ( F_25 ) ;
V_10 = F_10 ( V_45 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_43 || V_43 != V_46 ) {
V_10 = V_32 ;
goto V_48;
}
V_46 = NULL ;
V_48:
( void ) F_14 ( V_45 ) ;
F_6 ( V_10 ) ;
}
