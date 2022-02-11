T_1 F_1 ( void )
{
T_1 V_1 ;
F_2 ( F_1 ) ;
V_1 = F_3 () ;
if ( F_4 ( V_1 ) ) {
F_5 ( ( V_2 , V_1 ,
L_1 ) ) ;
}
F_6 ( V_1 ) ;
}
static T_1 F_3 ( void )
{
T_1 V_1 ;
T_2 V_3 ;
struct V_4 * V_5 ;
F_2 ( V_6 ) ;
( void ) F_7 ( V_7 ) ;
if ( ! V_8 . V_9 ||
! F_8 ( &
( V_8 .
V_10 [ V_11 ] . V_12 ) ,
V_13 )
||
F_4 ( F_9
( & V_8 .
V_10 [ V_11 ] ) ) ) {
V_1 = V_14 ;
goto V_15;
}
V_16 =
V_8 . V_10 [ V_11 ] . V_17 ;
if ( V_18 ) {
V_5 = F_10 ( V_11 ) ;
if ( V_5 ) {
V_16 = V_5 ;
}
}
F_11 ( & V_19 , V_16 ,
sizeof( struct V_4 ) ) ;
( void ) F_12 ( V_7 ) ;
V_1 = F_13 ( V_11 , V_20 ) ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_1 ) ;
}
( void ) F_7 ( V_7 ) ;
for ( V_3 = 0 ; V_3 < V_8 . V_9 ; ++ V_3 ) {
if ( ( ! F_8
( & ( V_8 . V_10 [ V_3 ] . V_12 ) ,
V_21 )
&&
! F_8 ( &
( V_8 . V_10 [ V_3 ] .
V_12 ) , V_22 ) )
||
F_4 ( F_9
( & V_8 . V_10 [ V_3 ] ) ) ) {
continue;
}
if ( V_23 ) {
F_14 ( V_24 L_2 ) ;
continue;
}
( void ) F_12 ( V_7 ) ;
( void ) F_13 ( V_3 , V_20 ) ;
( void ) F_7 ( V_7 ) ;
}
F_15 ( ( V_25 , L_3 ) ) ;
V_15:
( void ) F_12 ( V_7 ) ;
F_6 ( V_1 ) ;
}
T_1 F_16 ( struct V_4 * V_26 )
{
T_1 V_1 ;
struct V_27 V_28 ;
T_2 V_29 ;
F_2 ( F_16 ) ;
if ( ! V_26 ) {
F_6 ( V_30 ) ;
}
F_17 ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_31 = F_18 ( V_26 ) ;
V_28 . V_17 = V_26 ;
V_28 . V_32 = V_26 -> V_32 ;
V_28 . V_33 = V_34 ;
V_1 = F_7 ( V_35 ) ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_1 ) ;
}
F_19 ( ( V_2 , L_4 ) ) ;
V_1 = F_20 ( & V_28 , & V_29 ) ;
if ( F_4 ( V_1 ) ) {
goto V_15;
}
V_1 = F_13 ( V_29 , V_20 ) ;
if ( V_36 ) {
( void ) V_36 ( V_37 , V_26 ,
V_38 ) ;
}
V_15:
( void ) F_12 ( V_35 ) ;
F_6 ( V_1 ) ;
}
T_1 F_21 ( T_3 V_39 )
{
struct V_40 * V_41 =
F_22 ( struct V_40 , V_39 ) ;
T_1 V_1 = V_42 ;
T_4 V_43 ;
T_2 V_3 ;
F_2 ( F_21 ) ;
if ( ! V_39 ) {
F_6 ( V_30 ) ;
}
V_43 = V_41 -> V_43 ;
if ( ! V_43 ) {
F_6 ( V_44 ) ;
}
V_1 = F_7 ( V_35 ) ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_1 ) ;
}
for ( V_3 = 0 ; V_3 < V_8 . V_9 ; V_3 ++ ) {
if ( V_43 != V_8 . V_10 [ V_3 ] . V_43 ) {
continue;
}
if ( F_8
( V_8 . V_10 [ V_3 ] . V_12 . V_45 ,
V_13 ) ) {
V_1 = V_44 ;
break;
}
if ( ! F_23 ( V_3 ) ) {
V_1 = V_42 ;
break;
}
if ( V_36 ) {
( void ) V_36 ( V_46 ,
V_8 .
V_10 [ V_3 ] . V_17 ,
V_38 ) ;
}
V_1 = F_24 ( V_3 ) ;
if ( F_4 ( V_1 ) ) {
break;
}
V_1 = F_25 ( V_3 ) ;
F_26 ( V_3 , FALSE ) ;
break;
}
( void ) F_12 ( V_35 ) ;
F_6 ( V_1 ) ;
}
static int T_5 F_27 ( char * V_47 ) {
F_14 ( V_48 L_5 ) ;
V_23 = 1 ;
return 1 ;
}
