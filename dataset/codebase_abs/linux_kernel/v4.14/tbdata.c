static T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
T_3 V_4 = V_5 ;
T_1 V_6 ;
struct V_7 * V_8 ;
T_2 V_9 ;
T_1 V_10 ;
V_4 =
F_2 ( & V_11 . V_12 [ V_3 ] ,
& V_8 , & V_9 , & V_10 ) ;
if ( F_3 ( V_4 ) ) {
return ( FALSE ) ;
}
V_6 = ( T_1 ) ( ( V_2 -> V_13 != V_9 ||
memcmp ( V_2 -> V_14 , V_8 , V_9 ) ) ?
FALSE : TRUE ) ;
F_4 ( V_8 , V_9 , V_10 ) ;
return ( V_6 ) ;
}
void
F_5 ( struct V_1 * V_2 ,
T_4 V_15 ,
T_1 V_16 , struct V_7 * V_8 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_13 = V_8 -> V_13 ;
V_2 -> V_16 = V_16 ;
F_6 ( V_2 -> V_17 . V_18 , V_8 -> V_17 ) ;
}
T_3
F_2 ( struct V_1 * V_2 ,
struct V_7 * * V_19 ,
T_2 * V_9 , T_1 * V_10 )
{
struct V_7 * V_8 = NULL ;
switch ( V_2 -> V_16 & V_20 ) {
case V_21 :
V_8 =
F_7 ( V_2 -> V_15 , V_2 -> V_13 ) ;
break;
case V_22 :
case V_23 :
V_8 = F_8 ( struct V_7 ,
F_9 ( V_2 ->
V_15 ) ) ;
break;
default:
break;
}
if ( ! V_8 ) {
return ( V_24 ) ;
}
* V_19 = V_8 ;
* V_9 = V_2 -> V_13 ;
* V_10 = V_2 -> V_16 ;
return ( V_5 ) ;
}
void
F_4 ( struct V_7 * V_8 ,
T_2 V_9 , T_1 V_10 )
{
switch ( V_10 & V_20 ) {
case V_21 :
F_10 ( V_8 , V_9 ) ;
break;
case V_22 :
case V_23 :
default:
break;
}
}
T_3
F_11 ( struct V_1 * V_2 ,
T_4 V_15 , T_1 V_16 )
{
struct V_7 * V_25 ;
switch ( V_16 & V_20 ) {
case V_21 :
V_25 =
F_7 ( V_15 ,
sizeof( struct V_7 ) ) ;
if ( ! V_25 ) {
return ( V_24 ) ;
}
F_5 ( V_2 , V_15 , V_16 ,
V_25 ) ;
F_10 ( V_25 ,
sizeof( struct V_7 ) ) ;
return ( V_5 ) ;
case V_22 :
case V_23 :
V_25 = F_8 ( struct V_7 ,
F_9 ( V_15 ) ) ;
if ( ! V_25 ) {
return ( V_24 ) ;
}
F_5 ( V_2 , V_15 , V_16 ,
V_25 ) ;
return ( V_5 ) ;
default:
break;
}
return ( V_24 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
}
T_3 F_14 ( struct V_1 * V_2 )
{
T_3 V_4 = V_5 ;
F_15 ( V_26 ) ;
if ( ! V_2 -> V_14 ) {
V_4 = F_2 ( V_2 , & V_2 -> V_14 ,
& V_2 -> V_13 ,
& V_2 -> V_16 ) ;
if ( ! V_2 -> V_14 ) {
V_4 = V_24 ;
}
}
F_16 ( V_4 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_15 ( V_27 ) ;
if ( ! V_2 -> V_14 ) {
V_28 ;
}
F_4 ( V_2 -> V_14 , V_2 -> V_13 ,
V_2 -> V_16 ) ;
V_2 -> V_14 = NULL ;
V_28 ;
}
T_3 F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 && ! V_29 ) {
V_2 -> V_13 = sizeof( struct V_7 ) ;
}
return ( F_14 ( V_2 ) ) ;
}
static T_3
F_18 ( struct V_1 * V_2 , T_2 * V_3 )
{
T_2 V_30 ;
F_15 ( V_31 ) ;
for ( V_30 = 0 ; V_30 < V_11 . V_32 ; ++ V_30 ) {
if ( !
( V_11 . V_12 [ V_30 ] .
V_16 & V_33 ) ) {
continue;
}
if ( ! F_1 ( V_2 , V_30 ) ) {
continue;
}
if ( V_11 . V_12 [ V_30 ] . V_16 &
V_34 ) {
F_16 ( V_35 ) ;
} else {
* V_3 = V_30 ;
F_16 ( V_36 ) ;
}
}
F_16 ( V_5 ) ;
}
T_3
F_19 ( struct V_1 * V_2 ,
char * V_17 , T_2 * V_3 )
{
T_3 V_4 = V_5 ;
F_15 ( V_37 ) ;
V_4 = F_17 ( V_2 ) ;
if ( F_3 ( V_4 ) ) {
F_16 ( V_24 ) ;
}
if ( V_17 && ! F_20 ( & V_2 -> V_17 , V_17 ) ) {
F_21 ( ( V_38 ,
L_1 ,
V_2 -> V_17 . integer , V_17 ) ) ;
V_4 = V_39 ;
goto V_40;
}
if ( V_29 ) {
V_4 =
F_22 ( V_2 -> V_14 ,
V_2 -> V_13 ) ;
if ( F_3 ( V_4 ) ) {
F_23 ( ( V_38 , V_24 ,
L_2
L_3 ,
F_24 ( V_2 ->
V_17 .
V_18 ) ?
V_2 -> V_17 . V_18 : L_4 ,
F_25 ( V_2 ->
V_15 ) ) ) ;
goto V_40;
}
if ( V_3 ) {
V_4 =
F_18 ( V_2 , V_3 ) ;
if ( F_3 ( V_4 ) ) {
if ( V_4 != V_36 ) {
F_23 ( ( V_38 , V_24 ,
L_2
L_5 ,
F_24
( V_2 -> V_17 .
V_18 ) ? V_2 ->
V_17 .
V_18 : L_4 ,
F_25
( V_2 -> V_15 ) ) ) ;
}
goto V_40;
}
}
V_2 -> V_16 |= V_33 ;
}
F_16 ( V_4 ) ;
V_40:
F_13 ( V_2 ) ;
F_16 ( V_4 ) ;
}
T_3 F_26 ( void )
{
struct V_1 * V_12 ;
T_2 V_41 ;
T_2 V_32 , V_42 ;
T_2 V_30 ;
F_15 ( V_43 ) ;
if ( ! ( V_11 . V_16 & V_44 ) ) {
F_27 ( ( V_38 ,
L_6 ) ) ;
F_16 ( V_45 ) ;
}
if ( V_11 . V_16 & V_46 ) {
V_41 = V_11 . V_42 ;
} else {
V_41 = V_11 . V_32 ;
}
V_42 = V_41 + V_47 ;
V_12 = F_28 ( ( ( V_48 ) V_42 ) *
sizeof( struct V_1 ) ) ;
if ( ! V_12 ) {
F_27 ( ( V_38 ,
L_7 ) ) ;
F_16 ( V_24 ) ;
}
V_32 = 0 ;
if ( V_11 . V_12 ) {
for ( V_30 = 0 ; V_30 < V_41 ; V_30 ++ ) {
if ( V_11 . V_12 [ V_30 ] . V_15 ) {
memcpy ( V_12 + V_32 ,
V_11 . V_12 + V_30 ,
sizeof( struct V_1 ) ) ;
V_32 ++ ;
}
}
if ( V_11 . V_16 & V_46 ) {
F_29 ( V_11 . V_12 ) ;
}
}
V_11 . V_12 = V_12 ;
V_11 . V_42 = V_42 ;
V_11 . V_32 = V_32 ;
V_11 . V_16 |= V_46 ;
F_16 ( V_5 ) ;
}
T_3
F_30 ( T_2 * V_3 ,
struct V_1 * * V_2 )
{
T_3 V_4 ;
T_2 V_30 ;
if ( V_11 . V_32 >=
V_11 . V_42 ) {
V_4 = F_26 () ;
if ( F_3 ( V_4 ) ) {
return ( V_4 ) ;
}
}
V_30 = V_11 . V_32 ;
V_11 . V_32 ++ ;
if ( V_3 ) {
* V_3 = V_30 ;
}
if ( V_2 ) {
* V_2 = & V_11 . V_12 [ V_30 ] ;
}
return ( V_5 ) ;
}
void F_31 ( void )
{
T_2 V_30 ;
F_15 ( V_49 ) ;
( void ) F_32 ( V_50 ) ;
for ( V_30 = 0 ; V_30 < V_11 . V_32 ; V_30 ++ ) {
F_33 ( & V_11 . V_12 [ V_30 ] ) ;
}
if ( V_11 . V_16 & V_46 ) {
F_29 ( V_11 . V_12 ) ;
}
V_11 . V_12 = NULL ;
V_11 . V_16 = 0 ;
V_11 . V_32 = 0 ;
F_34 ( ( V_51 , L_8 ) ) ;
( void ) F_35 ( V_50 ) ;
V_28 ;
}
T_3 F_36 ( T_2 V_3 )
{
T_5 V_52 ;
T_3 V_4 ;
F_15 ( V_53 ) ;
V_4 = F_32 ( V_50 ) ;
if ( F_3 ( V_4 ) ) {
F_16 ( V_4 ) ;
}
if ( V_3 >= V_11 . V_32 ) {
( void ) F_35 ( V_50 ) ;
F_16 ( V_54 ) ;
}
V_52 = V_11 . V_12 [ V_3 ] . V_52 ;
( void ) F_35 ( V_50 ) ;
V_4 = F_37 ( & V_55 ) ;
if ( F_3 ( V_4 ) ) {
F_16 ( V_4 ) ;
}
F_38 ( V_52 ) ;
F_39 ( & V_55 ) ;
F_16 ( V_4 ) ;
}
T_3 F_40 ( T_2 V_3 )
{
T_3 V_4 = V_56 ;
F_15 ( V_57 ) ;
( void ) F_32 ( V_50 ) ;
if ( V_3 < V_11 . V_32 ) {
V_4 =
F_41 ( &
( V_11 .
V_12 [ V_3 ] . V_52 ) ) ;
}
( void ) F_35 ( V_50 ) ;
F_16 ( V_4 ) ;
}
T_3 F_42 ( T_2 V_3 )
{
T_3 V_4 = V_56 ;
F_15 ( V_58 ) ;
( void ) F_32 ( V_50 ) ;
if ( V_3 < V_11 . V_32 ) {
F_43 ( &
( V_11 .
V_12 [ V_3 ] . V_52 ) ) ;
V_4 = V_5 ;
}
( void ) F_35 ( V_50 ) ;
F_16 ( V_4 ) ;
}
T_3 F_44 ( T_2 V_3 , T_5 * V_52 )
{
T_3 V_4 = V_56 ;
F_15 ( V_59 ) ;
( void ) F_32 ( V_50 ) ;
if ( V_3 < V_11 . V_32 ) {
* V_52 =
V_11 . V_12 [ V_3 ] . V_52 ;
V_4 = V_5 ;
}
( void ) F_35 ( V_50 ) ;
F_16 ( V_4 ) ;
}
T_1 F_45 ( T_2 V_3 )
{
T_1 V_60 = FALSE ;
( void ) F_32 ( V_50 ) ;
if ( V_3 < V_11 . V_32 ) {
V_60 = ( T_1 )
( V_11 . V_12 [ V_3 ] . V_16 &
V_34 ) ;
}
( void ) F_35 ( V_50 ) ;
return ( V_60 ) ;
}
void F_46 ( T_2 V_3 , T_1 V_60 )
{
( void ) F_32 ( V_50 ) ;
if ( V_3 < V_11 . V_32 ) {
if ( V_60 ) {
V_11 . V_12 [ V_3 ] . V_16 |=
V_34 ;
} else {
V_11 . V_12 [ V_3 ] . V_16 &=
~ V_34 ;
}
}
( void ) F_35 ( V_50 ) ;
}
T_3
F_47 ( T_2 V_3 , struct V_61 * V_62 )
{
struct V_7 * V_8 ;
T_3 V_4 ;
T_5 V_52 ;
F_15 ( V_63 ) ;
V_4 = F_48 ( V_3 , & V_8 ) ;
if ( F_3 ( V_4 ) ) {
F_16 ( V_4 ) ;
}
V_4 = F_49 ( V_3 , V_62 ) ;
if ( ! V_64
&& V_65 ) {
F_50 () ;
}
V_4 = F_44 ( V_3 , & V_52 ) ;
if ( F_51 ( V_4 ) ) {
F_52 ( V_52 ) ;
}
F_53 ( V_66 , V_8 ) ;
F_16 ( V_4 ) ;
}
T_3
F_54 ( T_4 V_15 ,
T_1 V_16 , T_1 V_67 , T_2 * V_3 )
{
T_3 V_4 ;
T_2 V_30 ;
F_15 ( V_68 ) ;
V_4 = F_55 ( V_15 , V_16 , TRUE ,
V_67 , & V_30 ) ;
if ( F_3 ( V_4 ) ) {
goto exit;
}
V_4 = F_47 ( V_30 , V_69 ) ;
exit:
* V_3 = V_30 ;
F_16 ( V_4 ) ;
}
T_3 F_56 ( T_2 V_3 )
{
T_3 V_4 = V_5 ;
struct V_7 * V_8 ;
F_15 ( V_70 ) ;
if ( ! F_45 ( V_3 ) ) {
F_16 ( V_54 ) ;
}
V_4 = F_48 ( V_3 , & V_8 ) ;
if ( F_51 ( V_4 ) ) {
F_53 ( V_71 , V_8 ) ;
}
V_4 = F_36 ( V_3 ) ;
if ( F_3 ( V_4 ) ) {
F_16 ( V_4 ) ;
}
( void ) F_42 ( V_3 ) ;
F_46 ( V_3 , FALSE ) ;
F_16 ( V_4 ) ;
}
void F_53 ( T_2 V_72 , void * V_8 )
{
if ( V_73 ) {
( void ) V_73 ( V_72 , V_8 ,
V_74 ) ;
}
}
