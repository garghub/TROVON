static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_2 V_4 )
{
F_2 ( F_1 ) ;
V_2 -> V_5 = ( V_6 ) V_3 ;
if ( V_2 -> V_7 > 32 ) {
if ( V_2 -> V_8 >= 1 ) {
V_2 -> V_9 = V_4 ;
} else {
V_2 -> V_9 = 0 ;
}
}
F_3 ( V_10 ) ;
}
T_1
F_4 ( T_2 V_3 ,
T_2 V_4 )
{
F_2 ( F_4 ) ;
if ( V_11 ) {
F_3 ( V_10 ) ;
}
if ( V_12 ) {
( void ) F_1 ( V_12 ,
V_3 ,
V_4 ) ;
}
if ( V_13 ) {
( void ) F_1 ( V_13 ,
V_3 ,
V_4 ) ;
}
F_3 ( V_10 ) ;
}
T_1 F_5 ( V_6 V_3 )
{
T_1 V_14 ;
F_2 ( F_5 ) ;
V_14 = F_4 ( ( T_2 )
V_3 , 0 ) ;
F_3 ( V_14 ) ;
}
T_1 F_6 ( T_3 V_3 )
{
T_1 V_14 ;
F_2 ( F_6 ) ;
V_14 = F_4 ( 0 ,
( T_2 )
V_3 ) ;
F_3 ( V_14 ) ;
}
T_1 F_7 ( void )
{
V_6 V_15 ;
T_1 V_14 ;
F_2 ( F_7 ) ;
V_14 =
F_8 ( V_16 , V_17 ) ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
V_14 = F_10 () ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
V_14 = F_11 () ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
V_18 = FALSE ;
V_14 = F_12 () ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
F_13 () ;
V_14 = F_14 ( V_19 . V_20 ,
( V_6 ) V_19 . V_21 , 8 ) ;
do {
F_15 ( V_22 ) ;
V_14 =
F_16 ( V_16 , & V_15 ) ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
} while ( ! V_15 );
F_3 ( V_10 ) ;
}
static T_1 F_17 ( T_4 V_23 , V_6 V_24 )
{
T_1 V_14 ;
struct V_25 * V_26 =
& V_27 [ V_24 ] ;
#if ( ! V_28 )
if ( V_11 ) {
V_14 = V_26 -> V_29 ( V_23 ) ;
} else {
V_14 = V_26 -> V_30 ( V_23 ) ;
}
return ( V_14 ) ;
#else
V_14 = V_26 -> V_29 ( V_23 ) ;
return ( V_14 ) ;
#endif
}
T_1 F_18 ( T_4 V_23 )
{
T_1 V_14 ;
struct V_31 V_32 ;
union V_33 V_34 ;
V_6 V_35 ;
F_2 ( F_18 ) ;
V_14 = F_19 ( V_23 ,
& V_36 ,
& V_37 ) ;
if ( F_9 ( V_14 ) ) {
F_3 ( V_14 ) ;
}
V_32 . V_38 = 1 ;
V_32 . V_39 = & V_34 ;
V_34 . type = V_40 ;
V_34 . integer . V_41 = V_23 ;
V_14 =
F_20 ( NULL , V_42 , & V_32 , NULL ) ;
if ( F_9 ( V_14 ) && V_14 != V_43 ) {
F_3 ( V_14 ) ;
}
switch ( V_23 ) {
case V_44 :
V_35 = V_45 ;
break;
case V_46 :
case V_47 :
case V_48 :
V_35 = V_49 ;
break;
case V_50 :
V_35 = V_51 ;
break;
default:
V_35 = V_52 ;
break;
}
F_21 ( V_53 , V_35 ) ;
F_3 ( V_10 ) ;
}
T_1 F_22 ( T_4 V_23 )
{
T_1 V_14 ;
F_2 ( F_22 ) ;
if ( ( V_36 > V_54 ) ||
( V_37 > V_54 ) ) {
F_23 ( ( V_55 , L_1 ,
V_36 , V_37 ) ) ;
F_3 ( V_56 ) ;
}
V_14 = F_17 ( V_23 , V_57 ) ;
F_3 ( V_14 ) ;
}
T_1 F_24 ( T_4 V_23 )
{
T_1 V_14 ;
F_2 ( F_24 ) ;
V_14 =
F_17 ( V_23 , V_58 ) ;
F_3 ( V_14 ) ;
}
T_1 F_25 ( T_4 V_23 )
{
T_1 V_14 ;
F_2 ( F_25 ) ;
V_14 = F_17 ( V_23 , V_59 ) ;
F_3 ( V_14 ) ;
}
