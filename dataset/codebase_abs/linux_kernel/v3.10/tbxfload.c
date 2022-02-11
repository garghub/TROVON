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
F_15 ( ( V_2 , L_3 ) ) ;
V_15:
( void ) F_12 ( V_7 ) ;
F_6 ( V_1 ) ;
}
T_1 F_16 ( struct V_4 * V_25 )
{
T_1 V_1 ;
struct V_26 V_27 ;
T_2 V_28 ;
F_2 ( F_16 ) ;
if ( ! V_25 ) {
F_6 ( V_29 ) ;
}
F_17 ( & V_27 , 0 , sizeof( struct V_26 ) ) ;
V_27 . V_30 = F_18 ( V_25 ) ;
V_27 . V_17 = V_25 ;
V_27 . V_31 = V_25 -> V_31 ;
V_27 . V_32 = V_33 ;
V_1 = F_7 ( V_34 ) ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_1 ) ;
}
F_15 ( ( V_2 , L_4 ) ) ;
V_1 = F_19 ( & V_27 , & V_28 ) ;
if ( F_4 ( V_1 ) ) {
goto V_15;
}
V_1 = F_13 ( V_28 , V_20 ) ;
if ( V_35 ) {
( void ) V_35 ( V_36 , V_25 ,
V_37 ) ;
}
V_15:
( void ) F_12 ( V_34 ) ;
F_6 ( V_1 ) ;
}
T_1 F_20 ( T_3 V_38 )
{
struct V_39 * V_40 =
F_21 ( struct V_39 , V_38 ) ;
T_1 V_1 = V_41 ;
T_4 V_42 ;
T_2 V_3 ;
F_2 ( F_20 ) ;
if ( ! V_38 ) {
F_6 ( V_29 ) ;
}
V_42 = V_40 -> V_42 ;
if ( ! V_42 ) {
F_6 ( V_43 ) ;
}
V_1 = F_7 ( V_34 ) ;
if ( F_4 ( V_1 ) ) {
F_6 ( V_1 ) ;
}
for ( V_3 = 0 ; V_3 < V_8 . V_9 ; V_3 ++ ) {
if ( V_42 != V_8 . V_10 [ V_3 ] . V_42 ) {
continue;
}
if ( F_8
( V_8 . V_10 [ V_3 ] . V_12 . V_44 ,
V_13 ) ) {
V_1 = V_43 ;
break;
}
if ( ! F_22 ( V_3 ) ) {
V_1 = V_41 ;
break;
}
if ( V_35 ) {
( void ) V_35 ( V_45 ,
V_8 .
V_10 [ V_3 ] . V_17 ,
V_37 ) ;
}
V_1 = F_23 ( V_3 ) ;
if ( F_4 ( V_1 ) ) {
break;
}
V_1 = F_24 ( V_3 ) ;
F_25 ( V_3 , FALSE ) ;
break;
}
( void ) F_12 ( V_34 ) ;
F_6 ( V_1 ) ;
}
static int T_5 F_26 ( char * V_46 ) {
F_14 ( V_47 L_5 ) ;
V_23 = 1 ;
return 1 ;
}
