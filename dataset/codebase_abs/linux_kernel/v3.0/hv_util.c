static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
T_3 V_6 = false ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = NULL ;
F_2 ( V_3 , V_13 ,
V_14 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_10 = (struct V_9 * ) & V_13 [
sizeof( struct V_15 ) ] ;
if ( V_10 -> V_16 == V_17 ) {
F_3 ( V_10 , V_12 , V_13 ) ;
} else {
V_8 =
(struct V_7 * ) & V_13 [
sizeof( struct V_15 ) +
sizeof( struct V_9 ) ] ;
switch ( V_8 -> V_18 ) {
case 0 :
case 1 :
V_10 -> V_19 = V_20 ;
V_6 = true ;
F_4 ( L_1
L_2 ) ;
break;
default:
V_10 -> V_19 = V_21 ;
V_6 = false ;
F_4 ( L_1
L_3 ) ;
break;
}
}
V_10 -> V_22 = V_23
| V_24 ;
F_5 ( V_3 , V_13 ,
V_4 , V_5 ,
V_25 , 0 ) ;
}
if ( V_6 == true )
F_6 ( false ) ;
}
static inline void F_7 ( T_2 V_26 )
{
T_4 V_27 ;
struct V_28 V_29 ;
V_27 = ( V_26 - V_30 ) * 100 ;
V_29 = F_8 ( V_27 ) ;
F_9 ( & V_29 ) ;
}
static inline void F_10 ( T_2 V_26 , T_3 V_18 )
{
static T_5 V_31 = 50 ;
if ( ( V_18 & V_32 ) != 0 ) {
F_7 ( V_26 ) ;
return;
}
if ( ( V_18 & V_33 ) != 0 && V_31 > 0 ) {
V_31 -- ;
F_7 ( V_26 ) ;
}
}
static void F_11 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_9 * V_10 ;
struct V_34 * V_35 ;
F_2 ( V_3 , V_36 ,
V_14 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_10 = (struct V_9 * ) & V_36 [
sizeof( struct V_15 ) ] ;
if ( V_10 -> V_16 == V_17 ) {
F_3 ( V_10 , NULL , V_36 ) ;
} else {
V_35 = (struct V_34 * ) & V_36 [
sizeof( struct V_15 ) +
sizeof( struct V_9 ) ] ;
F_10 ( V_35 -> V_37 , V_35 -> V_18 ) ;
}
V_10 -> V_22 = V_23
| V_24 ;
F_5 ( V_3 , V_36 ,
V_4 , V_5 ,
V_25 , 0 ) ;
}
}
static void F_12 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
T_1 V_4 ;
T_2 V_5 ;
struct V_9 * V_10 ;
struct V_38 * V_39 ;
F_2 ( V_3 , V_40 ,
V_14 , & V_4 , & V_5 ) ;
if ( V_4 > 0 ) {
V_10 = (struct V_9 * ) & V_40 [
sizeof( struct V_15 ) ] ;
if ( V_10 -> V_16 == V_17 ) {
F_3 ( V_10 , NULL , V_40 ) ;
} else {
V_39 =
(struct V_38 * ) & V_40 [
sizeof( struct V_15 ) +
sizeof( struct V_9 ) ] ;
V_39 -> V_41 += 1 ;
}
V_10 -> V_22 = V_23
| V_24 ;
F_5 ( V_3 , V_40 ,
V_4 , V_5 ,
V_25 , 0 ) ;
}
}
static int T_6 F_13 ( void )
{
F_4 ( L_4 ) ;
if ( F_14 () )
return - V_42 ;
if ( ! F_15 ( V_43 ) )
return - V_42 ;
V_13 = F_16 ( V_14 , V_44 ) ;
V_36 = F_16 ( V_14 , V_44 ) ;
V_40 = F_16 ( V_14 , V_44 ) ;
if ( ! V_13 || ! V_36 || ! V_40 ) {
F_4 ( L_5 ) ;
F_17 ( V_13 ) ;
F_17 ( V_36 ) ;
F_17 ( V_40 ) ;
return - V_45 ;
}
V_46 [ V_47 ] . V_48 = & F_1 ;
V_46 [ V_49 ] . V_48 = & F_11 ;
V_46 [ V_50 ] . V_48 = & F_12 ;
V_46 [ V_51 ] . V_48 = & V_52 ;
return 0 ;
}
static void F_18 ( void )
{
F_4 ( L_6 ) ;
if ( V_46 [ V_47 ] . V_3 != NULL )
V_46 [ V_47 ] . V_3 -> V_53 =
& V_54 ;
V_46 [ V_47 ] . V_48 = NULL ;
if ( V_46 [ V_49 ] . V_3 != NULL )
V_46 [ V_49 ] . V_3 -> V_53 =
& V_54 ;
V_46 [ V_49 ] . V_48 = NULL ;
if ( V_46 [ V_50 ] . V_3 != NULL )
V_46 [ V_50 ] . V_3 -> V_53 =
& V_54 ;
V_46 [ V_50 ] . V_48 = NULL ;
if ( V_46 [ V_51 ] . V_3 != NULL )
V_46 [ V_51 ] . V_3 -> V_53 =
& V_54 ;
V_46 [ V_51 ] . V_48 = NULL ;
F_19 () ;
F_17 ( V_13 ) ;
F_17 ( V_36 ) ;
F_17 ( V_40 ) ;
}
