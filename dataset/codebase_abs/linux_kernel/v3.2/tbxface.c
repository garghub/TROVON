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
T_1 F_10 ( void )
{
struct V_6 * V_12 ;
V_11 V_15 ;
V_11 V_16 ;
F_4 ( F_10 ) ;
if ( V_2 . V_4 & V_17 ) {
F_6 ( V_18 ) ;
}
V_16 = ( V_11 )
V_2 . V_19 *
sizeof( struct V_6 ) ;
V_15 = V_16 +
( V_20 * sizeof( struct V_6 ) ) ;
V_12 = F_11 ( V_15 ) ;
if ( ! V_12 ) {
F_6 ( V_21 ) ;
}
F_12 ( V_12 , V_2 . V_12 , V_16 ) ;
V_2 . V_12 = V_12 ;
V_2 . V_3 =
V_2 . V_19 +
V_20 ;
V_2 . V_4 =
V_17 | V_5 ;
F_6 ( V_22 ) ;
}
T_1 F_13 ( struct V_23 * V_24 )
{
T_1 V_10 ;
T_2 V_25 ;
struct V_6 V_26 ;
if ( ! V_24 )
return V_27 ;
F_7 ( & V_26 , 0 , sizeof( struct V_6 ) ) ;
V_26 . V_28 = V_24 ;
V_26 . V_29 = V_24 -> V_29 ;
V_26 . V_4 = V_30 ;
V_10 = F_14 ( & V_26 , & V_25 ) ;
if ( F_5 ( V_10 ) ) {
return V_10 ;
}
V_10 = F_15 ( V_25 , V_31 ) ;
return V_10 ;
}
T_1
F_16 ( char * V_32 ,
T_2 V_33 , struct V_23 * V_34 )
{
T_2 V_35 ;
T_2 V_36 ;
struct V_23 * V_37 ;
if ( ! V_32 || ! V_34 ) {
return ( V_27 ) ;
}
for ( V_35 = 0 , V_36 = 0 ; V_35 < V_2 . V_19 ;
V_35 ++ ) {
if ( ! F_17
( & ( V_2 . V_12 [ V_35 ] . V_32 ) ,
V_32 ) ) {
continue;
}
if ( ++ V_36 < V_33 ) {
continue;
}
if ( ! V_2 . V_12 [ V_35 ] . V_28 ) {
if ( ( V_2 . V_12 [ V_35 ] . V_4 &
V_38 ) ==
V_39 ) {
V_37 =
F_18 ( V_2 .
V_12 [ V_35 ] . V_40 ,
sizeof( struct
V_23 ) ) ;
if ( ! V_37 ) {
return V_21 ;
}
F_12 ( V_34 , V_37 ,
sizeof( struct V_23 ) ) ;
F_19 ( V_37 ,
sizeof( struct
V_23 ) ) ;
} else {
return V_14 ;
}
} else {
F_12 ( V_34 ,
V_2 . V_12 [ V_35 ] . V_28 ,
sizeof( struct V_23 ) ) ;
}
return ( V_22 ) ;
}
return ( V_14 ) ;
}
T_1 F_20 ( T_6 V_41 )
{
int V_35 ;
T_1 V_10 = V_42 ;
F_4 ( F_20 ) ;
for ( V_35 = 0 ; V_35 < V_2 . V_19 ; ++ V_35 ) {
if ( V_41 != V_2 . V_12 [ V_35 ] . V_43 ) {
continue;
}
F_21 ( V_35 ) ;
V_10 = F_22 ( V_35 ) ;
F_23 ( V_35 , FALSE ) ;
break;
}
F_6 ( V_10 ) ;
}
T_1
F_24 ( char * V_32 ,
T_2 V_33 , struct V_23 * * V_44 ,
V_11 * V_45 )
{
T_2 V_35 ;
T_2 V_36 ;
T_1 V_10 ;
if ( ! V_32 || ! V_44 ) {
return ( V_27 ) ;
}
for ( V_35 = 0 , V_36 = 0 ; V_35 < V_2 . V_19 ;
V_35 ++ ) {
if ( ! F_17
( & ( V_2 . V_12 [ V_35 ] . V_32 ) ,
V_32 ) ) {
continue;
}
if ( ++ V_36 < V_33 ) {
continue;
}
V_10 =
F_25 ( & V_2 . V_12 [ V_35 ] ) ;
if ( F_26 ( V_10 ) ) {
* V_44 = V_2 . V_12 [ V_35 ] . V_28 ;
* V_45 = V_2 . V_12 [ V_35 ] . V_29 ;
}
if ( ! V_46 ) {
V_2 . V_12 [ V_35 ] . V_28 = NULL ;
}
return ( V_10 ) ;
}
return ( V_14 ) ;
}
T_1
F_27 ( char * V_32 ,
T_2 V_33 , struct V_23 * * V_44 )
{
V_11 V_45 ;
return F_24 ( V_32 ,
V_33 , V_44 , & V_45 ) ;
}
T_1
F_28 ( T_2 V_25 , struct V_23 * * V_47 )
{
T_1 V_10 ;
F_4 ( F_28 ) ;
if ( ! V_47 ) {
F_6 ( V_27 ) ;
}
( void ) F_29 ( V_48 ) ;
if ( V_25 >= V_2 . V_19 ) {
( void ) F_30 ( V_48 ) ;
F_6 ( V_27 ) ;
}
if ( ! V_2 . V_12 [ V_25 ] . V_28 ) {
V_10 =
F_25 ( & V_2 .
V_12 [ V_25 ] ) ;
if ( F_5 ( V_10 ) ) {
( void ) F_30 ( V_48 ) ;
F_6 ( V_10 ) ;
}
}
* V_47 = V_2 . V_12 [ V_25 ] . V_28 ;
( void ) F_30 ( V_48 ) ;
F_6 ( V_22 ) ;
}
static T_1 F_31 ( void )
{
T_1 V_10 ;
T_2 V_35 ;
struct V_23 * V_49 ;
F_4 ( V_50 ) ;
( void ) F_29 ( V_48 ) ;
if ( ! V_2 . V_19 ||
! F_17 ( &
( V_2 .
V_12 [ V_51 ] . V_32 ) ,
V_52 )
||
F_5 ( F_25
( & V_2 .
V_12 [ V_51 ] ) ) ) {
V_10 = V_53 ;
goto V_54;
}
V_55 =
V_2 . V_12 [ V_51 ] . V_28 ;
if ( V_56 ) {
V_49 = F_32 ( V_51 ) ;
if ( V_49 ) {
V_55 = V_49 ;
}
}
F_12 ( & V_57 , V_55 ,
sizeof( struct V_23 ) ) ;
( void ) F_30 ( V_48 ) ;
V_10 = F_15 ( V_51 , V_31 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
( void ) F_29 ( V_48 ) ;
for ( V_35 = 0 ; V_35 < V_2 . V_19 ; ++ V_35 ) {
if ( ( ! F_17
( & ( V_2 . V_12 [ V_35 ] . V_32 ) ,
V_58 )
&&
! F_17 ( &
( V_2 . V_12 [ V_35 ] .
V_32 ) , V_59 ) )
||
F_5 ( F_25
( & V_2 . V_12 [ V_35 ] ) ) ) {
continue;
}
if ( V_60 ) {
F_33 ( V_61 L_1 ) ;
continue;
}
( void ) F_30 ( V_48 ) ;
( void ) F_15 ( V_35 , V_31 ) ;
( void ) F_29 ( V_48 ) ;
}
F_34 ( ( V_62 , L_2 ) ) ;
V_54:
( void ) F_30 ( V_48 ) ;
F_6 ( V_10 ) ;
}
T_1 F_35 ( void )
{
T_1 V_10 ;
F_4 ( F_35 ) ;
V_10 = F_31 () ;
if ( F_5 ( V_10 ) ) {
F_36 ( ( V_63 , V_10 ,
L_3 ) ) ;
}
F_6 ( V_10 ) ;
}
T_1
F_37 ( T_7 V_64 , void * V_65 )
{
T_1 V_10 ;
F_4 ( F_37 ) ;
if ( ! V_64 ) {
F_6 ( V_27 ) ;
}
V_10 = F_29 ( V_66 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( V_67 ) {
V_10 = V_68 ;
goto V_69;
}
V_67 = V_64 ;
V_70 = V_65 ;
V_69:
( void ) F_30 ( V_66 ) ;
F_6 ( V_10 ) ;
}
T_1 F_38 ( T_7 V_64 )
{
T_1 V_10 ;
F_4 ( F_38 ) ;
V_10 = F_29 ( V_66 ) ;
if ( F_5 ( V_10 ) ) {
F_6 ( V_10 ) ;
}
if ( ! V_64 || V_64 != V_67 ) {
V_10 = V_27 ;
goto V_69;
}
V_67 = NULL ;
V_69:
( void ) F_30 ( V_66 ) ;
F_6 ( V_10 ) ;
}
static int T_3 F_39 ( char * V_71 ) {
F_33 ( V_72 L_4 ) ;
V_60 = 1 ;
return 1 ;
}
