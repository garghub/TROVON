T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_4 ;
F_2 ( V_5 ) ;
if ( ! V_2 -> V_6 ) {
if ( ( V_2 -> V_7 & V_8 ) ==
V_9 ) {
V_2 -> V_6 =
F_3 ( V_2 -> V_10 ,
V_2 -> V_11 ) ;
}
if ( ! V_2 -> V_6 ) {
F_4 ( V_12 ) ;
}
}
if ( ! F_5 ( & V_2 -> V_13 , V_14 ) ) {
V_3 =
F_6 ( V_2 -> V_6 ,
V_2 -> V_11 ) ;
}
F_4 ( V_3 ) ;
}
T_1
F_7 ( struct V_1 * V_2 , T_2 * V_15 )
{
T_2 V_16 ;
T_1 V_3 = V_4 ;
struct V_17 * V_18 = NULL ;
F_2 ( V_19 ) ;
if ( ! V_2 -> V_6 ) {
V_3 = F_1 ( V_2 ) ;
if ( F_8 ( V_3 ) || ! V_2 -> V_6 ) {
F_4 ( V_3 ) ;
}
}
( void ) F_9 ( V_20 ) ;
for ( V_16 = 0 ; V_16 < V_21 . V_22 ; ++ V_16 ) {
if ( ! V_21 . V_23 [ V_16 ] . V_6 ) {
V_3 =
F_1 ( & V_21 .
V_23 [ V_16 ] ) ;
if ( F_8 ( V_3 )
|| ! V_21 . V_23 [ V_16 ] . V_6 ) {
continue;
}
}
if ( V_2 -> V_11 !=
V_21 . V_23 [ V_16 ] . V_11 ) {
continue;
}
if ( F_10 ( V_2 -> V_6 ,
V_21 . V_23 [ V_16 ] . V_6 ,
V_21 . V_23 [ V_16 ] . V_11 ) ) {
continue;
}
F_11 ( V_2 ) ;
* V_15 = V_16 ;
if ( V_21 . V_23 [ V_16 ] .
V_7 & V_24 ) {
V_3 = V_25 ;
goto V_26;
} else {
V_2 -> V_6 =
V_21 . V_23 [ V_16 ] . V_6 ;
V_2 -> V_10 =
V_21 . V_23 [ V_16 ] . V_10 ;
V_3 = V_4 ;
goto V_27;
}
}
V_3 = F_12 ( V_2 -> V_6 , & V_18 ) ;
if ( F_13 ( V_3 ) && V_18 ) {
F_14 ( ( V_28 ,
L_1 ,
V_2 -> V_6 -> V_13 ,
F_15 ( void , V_2 -> V_10 ) ) ) ;
F_11 ( V_2 ) ;
V_2 -> V_10 = F_16 ( V_18 ) ;
V_2 -> V_6 = V_18 ;
V_2 -> V_11 = V_18 -> V_11 ;
V_2 -> V_7 = V_29 ;
}
V_3 = F_17 ( V_2 -> V_10 , V_2 -> V_6 ,
V_2 -> V_11 , V_2 -> V_7 ,
V_15 ) ;
if ( F_8 ( V_3 ) ) {
goto V_26;
}
V_27:
F_18 ( V_2 -> V_10 , V_2 -> V_6 ) ;
V_26:
( void ) F_19 ( V_20 ) ;
F_4 ( V_3 ) ;
}
T_1 F_20 ( void )
{
struct V_1 * V_23 ;
F_2 ( V_30 ) ;
if ( ! ( V_21 . V_7 & V_31 ) ) {
F_21 ( ( V_28 ,
L_2 ) ) ;
F_4 ( V_32 ) ;
}
V_23 = F_22 ( ( ( V_33 ) V_21 .
V_34 +
V_35 ) *
sizeof( struct V_1 ) ) ;
if ( ! V_23 ) {
F_21 ( ( V_28 ,
L_3 ) ) ;
F_4 ( V_12 ) ;
}
if ( V_21 . V_23 ) {
F_23 ( V_23 , V_21 . V_23 ,
( V_33 ) V_21 .
V_34 * sizeof( struct V_1 ) ) ;
if ( V_21 . V_7 & V_36 ) {
F_24 ( V_21 . V_23 ) ;
}
}
V_21 . V_23 = V_23 ;
V_21 . V_34 +=
V_35 ;
V_21 . V_7 |= ( V_37 ) V_36 ;
F_4 ( V_4 ) ;
}
T_1
F_17 ( T_3 V_10 ,
struct V_17 * V_38 ,
T_2 V_11 , V_37 V_7 , T_2 * V_15 )
{
T_1 V_3 ;
struct V_1 * V_39 ;
if ( V_21 . V_22 >=
V_21 . V_34 ) {
V_3 = F_20 () ;
if ( F_8 ( V_3 ) ) {
return ( V_3 ) ;
}
}
V_39 =
& V_21 . V_23 [ V_21 .
V_22 ] ;
V_39 -> V_10 = V_10 ;
V_39 -> V_6 = V_38 ;
V_39 -> V_11 = V_11 ;
V_39 -> V_40 = 0 ;
V_39 -> V_7 = V_7 ;
F_25 ( & V_39 -> V_13 , V_38 -> V_13 ) ;
* V_15 = V_21 . V_22 ;
V_21 . V_22 ++ ;
return ( V_4 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 ) {
return;
}
switch ( V_2 -> V_7 & V_8 ) {
case V_9 :
F_26 ( V_2 -> V_6 , V_2 -> V_11 ) ;
break;
case V_41 :
F_24 ( V_2 -> V_6 ) ;
break;
default: ;
}
V_2 -> V_6 = NULL ;
}
void F_27 ( void )
{
T_2 V_16 ;
F_2 ( V_42 ) ;
( void ) F_9 ( V_20 ) ;
for ( V_16 = 0 ; V_16 < V_21 . V_22 ; V_16 ++ ) {
F_11 ( & V_21 . V_23 [ V_16 ] ) ;
}
if ( V_21 . V_7 & V_36 ) {
F_24 ( V_21 . V_23 ) ;
}
V_21 . V_23 = NULL ;
V_21 . V_7 = 0 ;
V_21 . V_22 = 0 ;
F_28 ( ( V_43 , L_4 ) ) ;
( void ) F_19 ( V_20 ) ;
}
T_1 F_29 ( T_2 V_15 )
{
T_4 V_40 ;
T_1 V_3 ;
F_2 ( V_44 ) ;
V_3 = F_9 ( V_20 ) ;
if ( F_8 ( V_3 ) ) {
F_4 ( V_3 ) ;
}
if ( V_15 >= V_21 . V_22 ) {
( void ) F_19 ( V_20 ) ;
F_4 ( V_45 ) ;
}
V_40 = V_21 . V_23 [ V_15 ] . V_40 ;
( void ) F_19 ( V_20 ) ;
( void ) F_19 ( V_46 ) ;
V_3 = F_30 ( & V_47 ) ;
F_31 ( V_40 ) ;
if ( F_8 ( V_3 ) ) {
F_4 ( V_3 ) ;
}
F_32 ( & V_47 ) ;
V_3 = F_9 ( V_46 ) ;
F_4 ( V_3 ) ;
}
T_1 F_33 ( T_2 V_15 )
{
T_1 V_3 = V_48 ;
F_2 ( V_49 ) ;
( void ) F_9 ( V_20 ) ;
if ( V_15 < V_21 . V_22 ) {
V_3 = F_34
( & ( V_21 . V_23 [ V_15 ] . V_40 ) ) ;
}
( void ) F_19 ( V_20 ) ;
F_4 ( V_3 ) ;
}
T_1 F_35 ( T_2 V_15 )
{
T_1 V_3 = V_48 ;
F_2 ( V_50 ) ;
( void ) F_9 ( V_20 ) ;
if ( V_15 < V_21 . V_22 ) {
F_36 ( &
( V_21 .
V_23 [ V_15 ] . V_40 ) ) ;
V_3 = V_4 ;
}
( void ) F_19 ( V_20 ) ;
F_4 ( V_3 ) ;
}
T_1 F_37 ( T_2 V_15 , T_4 * V_40 )
{
T_1 V_3 = V_48 ;
F_2 ( V_51 ) ;
( void ) F_9 ( V_20 ) ;
if ( V_15 < V_21 . V_22 ) {
* V_40 =
V_21 . V_23 [ V_15 ] . V_40 ;
V_3 = V_4 ;
}
( void ) F_19 ( V_20 ) ;
F_4 ( V_3 ) ;
}
V_37 F_38 ( T_2 V_15 )
{
V_37 V_52 = FALSE ;
( void ) F_9 ( V_20 ) ;
if ( V_15 < V_21 . V_22 ) {
V_52 = ( V_37 )
( V_21 . V_23 [ V_15 ] . V_7 &
V_24 ) ;
}
( void ) F_19 ( V_20 ) ;
return ( V_52 ) ;
}
void F_39 ( T_2 V_15 , V_37 V_52 )
{
( void ) F_9 ( V_20 ) ;
if ( V_15 < V_21 . V_22 ) {
if ( V_52 ) {
V_21 . V_23 [ V_15 ] . V_7 |=
V_24 ;
} else {
V_21 . V_23 [ V_15 ] . V_7 &=
~ V_24 ;
}
}
( void ) F_19 ( V_20 ) ;
}
