void
F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 , struct V_5 * V_6 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_7 = V_6 -> V_7 ;
V_2 -> V_4 = V_4 ;
F_2 ( V_2 -> V_8 . V_9 , V_6 -> V_8 ) ;
}
T_3
F_3 ( struct V_1 * V_2 ,
struct V_5 * * V_10 ,
T_4 * V_11 , T_2 * V_12 )
{
struct V_5 * V_6 = NULL ;
switch ( V_2 -> V_4 & V_13 ) {
case V_14 :
V_6 =
F_4 ( V_2 -> V_3 , V_2 -> V_7 ) ;
break;
case V_15 :
case V_16 :
V_6 = F_5 ( struct V_5 ,
F_6 ( V_2 ->
V_3 ) ) ;
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
F_4 ( V_3 ,
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
V_19 = F_5 ( struct V_5 ,
F_6 ( V_3 ) ) ;
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
V_20 = F_3 ( V_2 , & V_2 -> V_22 ,
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
L_2
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
struct V_1 * V_30 ;
T_4 V_31 ;
F_13 ( V_32 ) ;
if ( ! ( V_33 . V_4 & V_34 ) ) {
F_25 ( ( V_27 ,
L_5 ) ) ;
F_14 ( V_35 ) ;
}
if ( V_33 . V_4 & V_36 ) {
V_31 = V_33 . V_37 ;
} else {
V_31 = V_33 . V_38 ;
}
V_30 = F_26 ( ( ( V_39 ) V_31 +
V_40 ) *
sizeof( struct V_1 ) ) ;
if ( ! V_30 ) {
F_25 ( ( V_27 ,
L_6 ) ) ;
F_14 ( V_17 ) ;
}
if ( V_33 . V_30 ) {
memcpy ( V_30 , V_33 . V_30 ,
( V_39 ) V_31 * sizeof( struct V_1 ) ) ;
if ( V_33 . V_4 & V_36 ) {
F_27 ( V_33 . V_30 ) ;
}
}
V_33 . V_30 = V_30 ;
V_33 . V_37 =
V_31 + V_40 ;
V_33 . V_4 |= V_36 ;
F_14 ( V_18 ) ;
}
T_3
F_28 ( T_4 * V_41 ,
struct V_1 * * V_2 )
{
T_3 V_20 ;
T_4 V_42 ;
if ( V_33 . V_38 >=
V_33 . V_37 ) {
V_20 = F_24 () ;
if ( F_17 ( V_20 ) ) {
return ( V_20 ) ;
}
}
V_42 = V_33 . V_38 ;
V_33 . V_38 ++ ;
if ( V_41 ) {
* V_41 = V_42 ;
}
if ( V_2 ) {
* V_2 = & V_33 . V_30 [ V_42 ] ;
}
return ( V_18 ) ;
}
void F_29 ( void )
{
T_4 V_42 ;
F_13 ( V_43 ) ;
( void ) F_30 ( V_44 ) ;
for ( V_42 = 0 ; V_42 < V_33 . V_38 ; V_42 ++ ) {
F_31 ( & V_33 . V_30 [ V_42 ] ) ;
}
if ( V_33 . V_4 & V_36 ) {
F_27 ( V_33 . V_30 ) ;
}
V_33 . V_30 = NULL ;
V_33 . V_4 = 0 ;
V_33 . V_38 = 0 ;
F_32 ( ( V_45 , L_7 ) ) ;
( void ) F_33 ( V_44 ) ;
V_24 ;
}
T_3 F_34 ( T_4 V_41 )
{
T_5 V_46 ;
T_3 V_20 ;
F_13 ( V_47 ) ;
V_20 = F_30 ( V_44 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_20 ) ;
}
if ( V_41 >= V_33 . V_38 ) {
( void ) F_33 ( V_44 ) ;
F_14 ( V_48 ) ;
}
V_46 = V_33 . V_30 [ V_41 ] . V_46 ;
( void ) F_33 ( V_44 ) ;
V_20 = F_35 ( & V_49 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_20 ) ;
}
F_36 ( V_46 ) ;
F_37 ( & V_49 ) ;
F_14 ( V_20 ) ;
}
T_3 F_38 ( T_4 V_41 )
{
T_3 V_20 = V_50 ;
F_13 ( V_51 ) ;
( void ) F_30 ( V_44 ) ;
if ( V_41 < V_33 . V_38 ) {
V_20 =
F_39 ( &
( V_33 .
V_30 [ V_41 ] . V_46 ) ) ;
}
( void ) F_33 ( V_44 ) ;
F_14 ( V_20 ) ;
}
T_3 F_40 ( T_4 V_41 )
{
T_3 V_20 = V_50 ;
F_13 ( V_52 ) ;
( void ) F_30 ( V_44 ) ;
if ( V_41 < V_33 . V_38 ) {
F_41 ( &
( V_33 .
V_30 [ V_41 ] . V_46 ) ) ;
V_20 = V_18 ;
}
( void ) F_33 ( V_44 ) ;
F_14 ( V_20 ) ;
}
T_3 F_42 ( T_4 V_41 , T_5 * V_46 )
{
T_3 V_20 = V_50 ;
F_13 ( V_53 ) ;
( void ) F_30 ( V_44 ) ;
if ( V_41 < V_33 . V_38 ) {
* V_46 =
V_33 . V_30 [ V_41 ] . V_46 ;
V_20 = V_18 ;
}
( void ) F_33 ( V_44 ) ;
F_14 ( V_20 ) ;
}
T_2 F_43 ( T_4 V_41 )
{
T_2 V_54 = FALSE ;
( void ) F_30 ( V_44 ) ;
if ( V_41 < V_33 . V_38 ) {
V_54 = ( T_2 )
( V_33 . V_30 [ V_41 ] . V_4 &
V_55 ) ;
}
( void ) F_33 ( V_44 ) ;
return ( V_54 ) ;
}
void F_44 ( T_4 V_41 , T_2 V_54 )
{
( void ) F_30 ( V_44 ) ;
if ( V_41 < V_33 . V_38 ) {
if ( V_54 ) {
V_33 . V_30 [ V_41 ] . V_4 |=
V_55 ;
} else {
V_33 . V_30 [ V_41 ] . V_4 &=
~ V_55 ;
}
}
( void ) F_33 ( V_44 ) ;
}
T_3
F_45 ( T_4 V_41 , struct V_56 * V_57 )
{
struct V_5 * V_6 ;
T_3 V_20 ;
T_5 V_46 ;
F_13 ( V_58 ) ;
V_20 = F_46 ( V_41 , & V_6 ) ;
if ( F_17 ( V_20 ) ) {
F_14 ( V_20 ) ;
}
V_20 = F_47 ( V_41 , V_57 ) ;
if ( ! V_59
&& V_60 ) {
F_48 () ;
}
V_20 = F_42 ( V_41 , & V_46 ) ;
if ( F_49 ( V_20 ) ) {
F_50 ( V_46 ) ;
}
if ( V_61 ) {
( void ) V_61 ( V_62 , V_6 ,
V_63 ) ;
}
F_14 ( V_20 ) ;
}
T_3
F_51 ( struct V_5 * V_6 ,
T_1 V_3 ,
T_2 V_4 , T_2 V_64 , T_4 * V_41 )
{
T_3 V_20 ;
T_4 V_42 ;
T_5 V_46 ;
F_13 ( V_65 ) ;
( void ) F_30 ( V_44 ) ;
V_20 = F_52 ( V_3 , V_4 , TRUE ,
V_64 , & V_42 ) ;
if ( F_17 ( V_20 ) ) {
goto V_66;
}
V_20 = F_12 ( & V_33 . V_30 [ V_42 ] ) ;
if ( F_17 ( V_20 ) ) {
goto V_66;
}
( void ) F_33 ( V_44 ) ;
V_20 = F_47 ( V_42 , V_67 ) ;
if ( ! V_59
&& V_60 ) {
F_48 () ;
}
V_20 = F_42 ( V_42 , & V_46 ) ;
if ( F_49 ( V_20 ) ) {
F_50 ( V_46 ) ;
}
if ( V_61 ) {
( void ) V_61 ( V_62 , V_6 ,
V_63 ) ;
}
( void ) F_30 ( V_44 ) ;
V_66:
* V_41 = V_42 ;
( void ) F_33 ( V_44 ) ;
F_14 ( V_20 ) ;
}
