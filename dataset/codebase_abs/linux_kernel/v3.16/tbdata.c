void
F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 , struct V_5 * V_6 )
{
F_2 ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_6 -> V_7 ;
V_2 -> V_4 = V_4 ;
F_3 ( V_2 -> V_8 . V_9 , V_6 -> V_8 ) ;
}
T_3
F_4 ( struct V_1 * V_2 ,
struct V_5 * * V_10 ,
T_4 * V_11 , T_2 * V_12 )
{
struct V_5 * V_6 = NULL ;
switch ( V_2 -> V_4 & V_13 ) {
case V_14 :
V_6 =
F_5 ( V_2 -> V_3 , V_2 -> V_7 ) ;
break;
case V_15 :
case V_16 :
V_6 =
F_6 ( struct V_5 ,
V_2 -> V_3 ) ;
break;
default:
break;
}
if ( ! V_6 ) {
return ( V_17 ) ;
}
* V_10 = V_6 ;
* V_11 = V_2 -> V_7 ;
* V_12 = V_2 -> V_4 ;
return ( V_18 ) ;
}
void
F_7 ( struct V_5 * V_6 ,
T_4 V_11 , T_2 V_12 )
{
switch ( V_12 & V_13 ) {
case V_14 :
F_8 ( V_6 , V_11 ) ;
break;
case V_15 :
case V_16 :
default:
break;
}
}
T_3
F_9 ( struct V_1 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_19 ;
switch ( V_4 & V_13 ) {
case V_14 :
V_19 =
F_5 ( V_3 ,
sizeof( struct V_5 ) ) ;
if ( ! V_19 ) {
return ( V_17 ) ;
}
F_1 ( V_2 , V_3 , V_4 ,
V_19 ) ;
F_8 ( V_19 ,
sizeof( struct V_5 ) ) ;
return ( V_18 ) ;
case V_15 :
case V_16 :
V_19 = F_6 ( struct V_5 , V_3 ) ;
if ( ! V_19 ) {
return ( V_17 ) ;
}
F_1 ( V_2 , V_3 , V_4 ,
V_19 ) ;
return ( V_18 ) ;
default:
break;
}
return ( V_17 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
}
T_3 F_12 ( struct V_1 * V_2 )
{
T_3 V_20 = V_18 ;
F_13 ( V_21 ) ;
if ( ! V_2 -> V_22 ) {
V_20 = F_4 ( V_2 , & V_2 -> V_22 ,
& V_2 -> V_7 ,
& V_2 -> V_4 ) ;
if ( ! V_2 -> V_22 ) {
V_20 = V_17 ;
}
}
F_14 ( V_20 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
F_13 ( V_23 ) ;
if ( ! V_2 -> V_22 ) {
V_24 ;
}
F_7 ( V_2 -> V_22 , V_2 -> V_7 ,
V_2 -> V_4 ) ;
V_2 -> V_22 = NULL ;
V_24 ;
}
T_3 F_15 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 && ! V_25 ) {
V_2 -> V_7 = sizeof( struct V_5 ) ;
}
return ( F_12 ( V_2 ) ) ;
}
T_3
F_16 ( struct V_1 * V_2 , char * V_8 )
{
T_3 V_20 = V_18 ;
F_13 ( V_26 ) ;
V_20 = F_15 ( V_2 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_17 ) ;
}
if ( V_8 && ! F_18 ( & V_2 -> V_8 , V_8 ) ) {
F_19 ( ( V_27 ,
L_1 ,
V_2 -> V_8 . integer , V_8 ) ) ;
V_20 = V_28 ;
goto V_29;
}
if ( V_25 ) {
V_20 =
F_20 ( V_2 -> V_22 ,
V_2 -> V_7 ) ;
if ( F_17 ( V_20 ) ) {
F_21 ( ( V_27 , V_17 ,
L_2 V_30
L_3 ,
F_22 ( V_2 ->
V_8 .
V_9 ) ?
V_2 -> V_8 . V_9 : L_4 ,
F_23 ( V_2 ->
V_3 ) ) ) ;
goto V_29;
}
}
F_14 ( V_18 ) ;
V_29:
F_11 ( V_2 ) ;
F_14 ( V_20 ) ;
}
T_3 F_24 ( void )
{
struct V_1 * V_31 ;
T_4 V_32 ;
F_13 ( V_33 ) ;
if ( ! ( V_34 . V_4 & V_35 ) ) {
F_25 ( ( V_27 ,
L_5 ) ) ;
F_14 ( V_36 ) ;
}
if ( V_34 . V_4 & V_37 ) {
V_32 = V_34 . V_38 ;
} else {
V_32 = V_34 . V_39 ;
}
V_31 = F_26 ( ( ( V_40 ) V_32 +
V_41 ) *
sizeof( struct V_1 ) ) ;
if ( ! V_31 ) {
F_25 ( ( V_27 ,
L_6 ) ) ;
F_14 ( V_17 ) ;
}
if ( V_34 . V_31 ) {
F_27 ( V_31 , V_34 . V_31 ,
( V_40 ) V_32 *
sizeof( struct V_1 ) ) ;
if ( V_34 . V_4 & V_37 ) {
F_28 ( V_34 . V_31 ) ;
}
}
V_34 . V_31 = V_31 ;
V_34 . V_38 =
V_32 + V_41 ;
V_34 . V_4 |= V_37 ;
F_14 ( V_18 ) ;
}
T_3 F_29 ( T_4 * V_42 )
{
T_3 V_20 ;
if ( V_34 . V_39 >=
V_34 . V_38 ) {
V_20 = F_24 () ;
if ( F_17 ( V_20 ) ) {
return ( V_20 ) ;
}
}
* V_42 = V_34 . V_39 ;
V_34 . V_39 ++ ;
return ( V_18 ) ;
}
void F_30 ( void )
{
T_4 V_43 ;
F_13 ( V_44 ) ;
( void ) F_31 ( V_45 ) ;
for ( V_43 = 0 ; V_43 < V_34 . V_39 ; V_43 ++ ) {
F_32 ( & V_34 . V_31 [ V_43 ] ) ;
}
if ( V_34 . V_4 & V_37 ) {
F_28 ( V_34 . V_31 ) ;
}
V_34 . V_31 = NULL ;
V_34 . V_4 = 0 ;
V_34 . V_39 = 0 ;
F_33 ( ( V_46 , L_7 ) ) ;
( void ) F_34 ( V_45 ) ;
V_24 ;
}
T_3 F_35 ( T_4 V_42 )
{
T_5 V_47 ;
T_3 V_20 ;
F_13 ( V_48 ) ;
V_20 = F_31 ( V_45 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_20 ) ;
}
if ( V_42 >= V_34 . V_39 ) {
( void ) F_34 ( V_45 ) ;
F_14 ( V_49 ) ;
}
V_47 = V_34 . V_31 [ V_42 ] . V_47 ;
( void ) F_34 ( V_45 ) ;
( void ) F_34 ( V_50 ) ;
V_20 = F_36 ( & V_51 ) ;
F_37 ( V_47 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_20 ) ;
}
F_38 ( & V_51 ) ;
V_20 = F_31 ( V_50 ) ;
F_14 ( V_20 ) ;
}
T_3 F_39 ( T_4 V_42 )
{
T_3 V_20 = V_52 ;
F_13 ( V_53 ) ;
( void ) F_31 ( V_45 ) ;
if ( V_42 < V_34 . V_39 ) {
V_20 =
F_40 ( &
( V_34 .
V_31 [ V_42 ] . V_47 ) ) ;
}
( void ) F_34 ( V_45 ) ;
F_14 ( V_20 ) ;
}
T_3 F_41 ( T_4 V_42 )
{
T_3 V_20 = V_52 ;
F_13 ( V_54 ) ;
( void ) F_31 ( V_45 ) ;
if ( V_42 < V_34 . V_39 ) {
F_42 ( &
( V_34 .
V_31 [ V_42 ] . V_47 ) ) ;
V_20 = V_18 ;
}
( void ) F_34 ( V_45 ) ;
F_14 ( V_20 ) ;
}
T_3 F_43 ( T_4 V_42 , T_5 * V_47 )
{
T_3 V_20 = V_52 ;
F_13 ( V_55 ) ;
( void ) F_31 ( V_45 ) ;
if ( V_42 < V_34 . V_39 ) {
* V_47 =
V_34 . V_31 [ V_42 ] . V_47 ;
V_20 = V_18 ;
}
( void ) F_34 ( V_45 ) ;
F_14 ( V_20 ) ;
}
T_2 F_44 ( T_4 V_42 )
{
T_2 V_56 = FALSE ;
( void ) F_31 ( V_45 ) ;
if ( V_42 < V_34 . V_39 ) {
V_56 = ( T_2 )
( V_34 . V_31 [ V_42 ] . V_4 &
V_57 ) ;
}
( void ) F_34 ( V_45 ) ;
return ( V_56 ) ;
}
void F_45 ( T_4 V_42 , T_2 V_56 )
{
( void ) F_31 ( V_45 ) ;
if ( V_42 < V_34 . V_39 ) {
if ( V_56 ) {
V_34 . V_31 [ V_42 ] . V_4 |=
V_57 ;
} else {
V_34 . V_31 [ V_42 ] . V_4 &=
~ V_57 ;
}
}
( void ) F_34 ( V_45 ) ;
}
