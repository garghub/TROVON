static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = (struct V_5 * ) V_2 -> V_7 ;
if ( V_6 -> V_8 . V_9 == V_10 ) {
F_2 ( L_1 ) ;
V_11 . V_12 = false ;
if ( V_11 . V_13 != NULL )
F_3 ( V_11 . V_13 ) ;
return;
}
F_4 ( V_6 -> error ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
int V_16 = V_11 . V_2 -> V_8 . V_9 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
V_2 = F_6 ( sizeof( * V_2 ) + sizeof( * V_6 ) , V_17 ) ;
if ( ! V_2 )
return;
V_6 = (struct V_5 * ) V_2 -> V_7 ;
V_2 -> V_18 . V_19 = V_20 ;
V_2 -> V_18 . V_21 = V_22 ;
V_6 -> V_8 . V_9 = V_16 ;
V_2 -> V_23 = sizeof( struct V_5 ) ;
F_7 ( V_2 , 0 , V_17 ) ;
F_8 ( V_2 ) ;
return;
}
static void
F_4 ( int error )
{
struct V_24 * V_25 ;
T_1 V_26 ;
struct V_27 * V_28 ;
T_2 V_29 ;
if ( ! V_11 . V_12 ) {
F_9 ( L_2 ) ;
return;
}
V_26 = V_11 . V_30 ;
V_28 = V_11 . V_13 ;
V_29 = V_11 . V_31 ;
V_11 . V_12 = false ;
V_25 = (struct V_24 * )
& V_32 [ sizeof( struct V_33 ) ] ;
if ( V_28 -> V_34 == NULL )
return;
V_25 -> V_35 = error ;
V_25 -> V_36 = V_37 | V_38 ;
F_10 ( V_28 , V_32 , V_26 , V_29 ,
V_39 , 0 ) ;
}
void F_3 ( void * V_40 )
{
struct V_27 * V_28 = V_40 ;
T_1 V_41 ;
T_2 V_42 ;
struct V_5 * V_6 ;
struct V_24 * V_25 ;
struct V_43 * V_44 = NULL ;
if ( V_11 . V_12 ) {
V_11 . V_13 = V_28 ;
return;
}
F_11 ( V_28 , V_32 , V_45 * 2 , & V_41 ,
& V_42 ) ;
if ( V_41 > 0 ) {
V_25 = (struct V_24 * ) & V_32 [
sizeof( struct V_33 ) ] ;
if ( V_25 -> V_46 == V_47 ) {
F_12 ( V_25 , V_44 ,
V_32 , V_48 , V_48 ) ;
V_44 = (struct V_43 * ) & V_32 [
sizeof( struct V_33 ) +
sizeof( struct V_24 ) ] ;
if ( V_44 -> V_49 [ 1 ] . V_50 < 5 )
V_44 -> V_51 = 0 ;
} else {
V_6 = (struct V_5 * ) & V_32 [
sizeof( struct V_33 ) +
sizeof( struct V_24 ) ] ;
V_11 . V_30 = V_41 ;
V_11 . V_13 = V_28 ;
V_11 . V_31 = V_42 ;
V_11 . V_12 = true ;
V_11 . V_2 = (struct V_5 * ) V_6 ;
switch ( V_6 -> V_8 . V_9 ) {
case V_52 :
case V_53 :
F_13 ( & V_54 ) ;
return;
case V_55 :
V_6 -> V_56 . V_57 =
V_58 ;
F_4 ( 0 ) ;
return;
case V_59 :
V_6 -> V_60 . V_57 = 0 ;
F_4 ( 0 ) ;
return;
default:
F_4 ( 0 ) ;
return;
}
}
V_25 -> V_36 = V_37
| V_38 ;
F_10 ( V_28 , V_32 ,
V_41 , V_42 ,
V_39 , 0 ) ;
}
}
int
F_14 ( struct V_61 * V_62 )
{
int V_63 ;
V_63 = F_15 ( & V_64 , V_65 , F_1 ) ;
if ( V_63 )
return V_63 ;
V_32 = V_62 -> V_32 ;
V_11 . V_12 = true ;
return 0 ;
}
void F_16 ( void )
{
F_17 ( & V_64 ) ;
F_18 ( & V_54 ) ;
}
