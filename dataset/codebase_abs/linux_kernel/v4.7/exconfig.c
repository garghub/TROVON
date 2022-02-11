static T_1
F_1 ( T_2 V_1 ,
struct V_2 * V_3 ,
union V_4 * * V_5 )
{
union V_4 * V_6 ;
T_1 V_7 ;
T_3 V_8 ;
F_2 ( V_9 ) ;
V_6 = F_3 ( V_10 ) ;
if ( ! V_6 ) {
F_4 ( V_11 ) ;
}
V_6 -> V_12 . V_13 |= V_14 ;
V_6 -> V_15 . V_16 = V_17 ;
* V_5 = V_6 ;
V_6 -> V_15 . V_18 = V_1 ;
V_7 = F_5 ( V_1 , V_3 ) ;
if ( F_6 ( V_7 ) ) {
F_7 ( V_6 ) ;
* V_5 = NULL ;
F_4 ( V_7 ) ;
}
F_8 () ;
if ( V_19 ) {
F_9 () ;
}
F_10 () ;
V_7 = F_11 ( V_1 , & V_8 ) ;
if ( F_12 ( V_7 ) ) {
F_13 ( V_8 ) ;
}
F_4 ( V_20 ) ;
}
T_1
F_14 ( struct V_21 * V_22 ,
union V_4 * * V_23 )
{
T_1 V_7 ;
union V_4 * * V_24 = & V_22 -> V_25 [ 0 ] ;
struct V_2 * V_3 ;
struct V_2 * V_26 ;
struct V_2 * V_27 = NULL ;
union V_4 * V_5 ;
struct V_28 * V_29 ;
T_2 V_1 ;
F_2 ( V_30 ) ;
V_7 = F_15 ( V_24 [ 0 ] -> string . V_31 ,
V_24 [ 1 ] -> string . V_31 ,
V_24 [ 2 ] -> string . V_31 , & V_1 ) ;
if ( F_6 ( V_7 ) ) {
if ( V_7 != V_32 ) {
F_4 ( V_7 ) ;
}
V_5 = F_16 ( ( V_33 ) 0 ) ;
if ( ! V_5 ) {
F_4 ( V_11 ) ;
}
* V_23 = V_5 ;
F_4 ( V_20 ) ;
}
V_26 = V_22 -> V_34 -> V_35 . V_36 ;
V_3 = V_37 ;
if ( V_24 [ 3 ] -> string . V_38 > 0 ) {
V_7 =
F_17 ( V_26 , V_24 [ 3 ] -> string . V_31 ,
V_39 , & V_3 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
}
if ( V_24 [ 4 ] -> string . V_38 > 0 ) {
if ( ( V_24 [ 4 ] -> string . V_31 [ 0 ] != V_40 ) &&
( V_24 [ 4 ] -> string . V_31 [ 0 ] != V_41 ) ) {
V_26 = V_3 ;
}
V_7 =
F_17 ( V_26 , V_24 [ 4 ] -> string . V_31 ,
V_39 , & V_27 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
}
V_7 = F_1 ( V_1 , V_3 , & V_5 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
if ( V_27 ) {
V_7 = F_18 ( V_24 [ 5 ] ,
F_19 ( union V_4 ,
V_27 ) ,
V_22 ) ;
if ( F_6 ( V_7 ) ) {
( void ) F_20 ( V_5 ) ;
F_7 ( V_5 ) ;
F_4 ( V_7 ) ;
}
}
V_7 = F_21 ( V_1 , & V_29 ) ;
if ( F_12 ( V_7 ) ) {
F_22 ( ( L_1 ) ) ;
F_23 ( 0 , V_29 ) ;
}
if ( V_42 ) {
( void ) V_42 ( V_43 , V_29 ,
V_44 ) ;
}
* V_23 = V_5 ;
F_4 ( V_7 ) ;
}
static T_1
F_24 ( union V_4 * V_6 , T_2 V_38 , T_4 * V_45 )
{
T_1 V_7 ;
V_33 V_18 ;
T_2 V_46 = 0 ;
T_2 V_47 ;
for ( V_47 = 0 ; V_47 < V_38 ; V_47 ++ ) {
V_7 =
F_25 ( V_6 , NULL , V_48 ,
V_46 , 8 , & V_18 ) ;
if ( F_6 ( V_7 ) ) {
return ( V_7 ) ;
}
* V_45 = ( T_4 ) V_18 ;
V_45 ++ ;
V_46 ++ ;
}
return ( V_20 ) ;
}
T_1
F_26 ( union V_4 * V_6 ,
union V_4 * V_49 ,
struct V_21 * V_22 )
{
union V_4 * V_5 ;
struct V_28 * V_50 ;
struct V_28 * V_29 ;
T_2 V_1 ;
T_1 V_7 ;
T_2 V_38 ;
F_2 ( V_51 ) ;
switch ( V_6 -> V_12 . type ) {
case V_52 :
F_27 ( ( V_53 ,
L_2 , V_6 ) ) ;
if ( V_6 -> V_54 . V_55 != V_56 ) {
F_4 ( V_57 ) ;
}
if ( ! ( V_6 -> V_12 . V_13 & V_14 ) ) {
V_7 = F_28 ( V_6 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
}
V_50 = F_29 ( sizeof( struct V_28 ) ) ;
if ( ! V_50 ) {
F_4 ( V_11 ) ;
}
V_7 =
F_24 ( V_6 ,
sizeof( struct V_28 ) ,
F_19 ( T_4 , V_50 ) ) ;
V_38 = V_50 -> V_38 ;
F_30 ( V_50 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
if ( V_38 < sizeof( struct V_28 ) ) {
F_4 ( V_58 ) ;
}
V_29 = F_29 ( V_38 ) ;
if ( ! V_29 ) {
F_4 ( V_11 ) ;
}
V_7 = F_24 ( V_6 , V_38 ,
F_19 ( T_4 , V_29 ) ) ;
if ( F_6 ( V_7 ) ) {
F_30 ( V_29 ) ;
F_4 ( V_7 ) ;
}
break;
case V_59 :
F_27 ( ( V_53 ,
L_3 ,
V_6 ) ) ;
if ( V_6 -> V_45 . V_38 < sizeof( struct V_28 ) ) {
F_4 ( V_58 ) ;
}
V_50 =
F_19 ( struct V_28 ,
V_6 -> V_45 . V_31 ) ;
V_38 = V_50 -> V_38 ;
if ( V_38 > V_6 -> V_45 . V_38 ) {
F_4 ( V_60 ) ;
}
if ( V_38 < sizeof( struct V_28 ) ) {
F_4 ( V_58 ) ;
}
V_29 = F_29 ( V_38 ) ;
if ( ! V_29 ) {
F_4 ( V_11 ) ;
}
memcpy ( V_29 , V_50 , V_38 ) ;
break;
default:
F_4 ( V_57 ) ;
}
F_22 ( ( L_1 ) ) ;
( void ) F_31 ( V_61 ) ;
V_7 = F_32 ( F_33 ( V_29 ) ,
V_62 ,
TRUE , TRUE , & V_1 ) ;
( void ) F_34 ( V_61 ) ;
if ( F_6 ( V_7 ) ) {
F_30 ( V_29 ) ;
F_4 ( V_7 ) ;
}
V_7 =
F_35 ( & V_63 .
V_64 [ V_1 ] ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
V_7 =
F_1 ( V_1 , V_37 , & V_5 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
V_7 = F_18 ( V_5 , V_49 , V_22 ) ;
if ( F_6 ( V_7 ) ) {
( void ) F_20 ( V_5 ) ;
F_7 ( V_5 ) ;
F_4 ( V_7 ) ;
}
F_7 ( V_5 ) ;
if ( V_42 ) {
( void ) V_42 ( V_43 , V_29 ,
V_44 ) ;
}
F_4 ( V_7 ) ;
}
T_1 F_20 ( union V_4 * V_5 )
{
T_1 V_7 = V_20 ;
union V_4 * V_65 = V_5 ;
T_2 V_1 ;
struct V_28 * V_29 ;
F_2 ( V_66 ) ;
F_36 ( ( V_67 , L_4 ) ) ;
if ( ( ! V_5 ) ||
( F_37 ( V_5 ) != V_68 ) ||
( V_5 -> V_12 . type != V_10 ) ||
( ! ( V_5 -> V_12 . V_13 & V_14 ) ) ) {
F_4 ( V_57 ) ;
}
V_1 = V_65 -> V_15 . V_18 ;
if ( ! F_38 ( V_1 ) ) {
F_4 ( V_69 ) ;
}
if ( V_42 ) {
V_7 = F_21 ( V_1 , & V_29 ) ;
if ( F_12 ( V_7 ) ) {
( void ) V_42 ( V_70 ,
V_29 ,
V_44 ) ;
}
}
V_7 = F_39 ( V_1 ) ;
if ( F_6 ( V_7 ) ) {
F_4 ( V_7 ) ;
}
( void ) F_40 ( V_1 ) ;
F_41 ( V_1 , FALSE ) ;
V_5 -> V_12 . V_13 &= ~ V_14 ;
F_4 ( V_20 ) ;
}
