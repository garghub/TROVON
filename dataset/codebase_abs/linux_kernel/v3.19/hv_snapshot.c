static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_3 ) ;
}
static void
F_4 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) V_5 -> V_10 ;
if ( V_9 -> V_11 . V_12 == V_13 ) {
F_5 ( L_2 ) ;
V_14 . V_15 = false ;
if ( V_14 . V_16 != NULL )
F_6 ( V_14 . V_16 ) ;
return;
}
if ( F_7 ( & V_17 ) )
F_3 ( V_9 -> error ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_18 = V_14 . V_5 -> V_11 . V_12 ;
int V_19 ;
struct V_4 * V_5 ;
struct V_8 * V_9 ;
V_5 = F_9 ( sizeof( * V_5 ) + sizeof( * V_9 ) , V_20 ) ;
if ( ! V_5 )
return;
V_9 = (struct V_8 * ) V_5 -> V_10 ;
V_5 -> V_21 . V_22 = V_23 ;
V_5 -> V_21 . V_24 = V_25 ;
V_9 -> V_11 . V_12 = V_18 ;
V_5 -> V_26 = sizeof( struct V_8 ) ;
V_19 = F_10 ( V_5 , 0 , 0 , V_20 ) ;
if ( V_19 ) {
F_2 ( L_3 , V_19 ) ;
if ( F_7 ( & V_17 ) )
F_3 ( V_3 ) ;
}
F_11 ( V_5 ) ;
return;
}
static void
F_3 ( int error )
{
struct V_27 * V_28 ;
T_1 V_29 ;
struct V_30 * V_31 ;
T_2 V_32 ;
if ( ! V_14 . V_15 ) {
F_2 ( L_4 ) ;
return;
}
V_29 = V_14 . V_33 ;
V_31 = V_14 . V_16 ;
V_32 = V_14 . V_34 ;
V_14 . V_15 = false ;
V_28 = (struct V_27 * )
& V_35 [ sizeof( struct V_36 ) ] ;
if ( V_31 -> V_37 == NULL )
return;
V_28 -> V_38 = error ;
V_28 -> V_39 = V_40 | V_41 ;
F_12 ( V_31 , V_35 , V_29 , V_32 ,
V_42 , 0 ) ;
}
void F_6 ( void * V_43 )
{
struct V_30 * V_31 = V_43 ;
T_1 V_44 ;
T_2 V_45 ;
struct V_8 * V_9 ;
struct V_27 * V_28 ;
struct V_46 * V_47 = NULL ;
if ( V_14 . V_15 ) {
V_14 . V_16 = V_31 ;
return;
}
F_13 ( V_31 , V_35 , V_48 * 2 , & V_44 ,
& V_45 ) ;
if ( V_44 > 0 ) {
V_28 = (struct V_27 * ) & V_35 [
sizeof( struct V_36 ) ] ;
if ( V_28 -> V_49 == V_50 ) {
F_14 ( V_28 , V_47 ,
V_35 , V_51 ,
V_52 ) ;
} else {
V_9 = (struct V_8 * ) & V_35 [
sizeof( struct V_36 ) +
sizeof( struct V_27 ) ] ;
V_14 . V_33 = V_44 ;
V_14 . V_16 = V_31 ;
V_14 . V_34 = V_45 ;
V_14 . V_15 = true ;
V_14 . V_5 = (struct V_8 * ) V_9 ;
switch ( V_9 -> V_11 . V_12 ) {
case V_53 :
case V_54 :
F_15 ( & V_55 ) ;
F_16 ( & V_17 ,
V_56 ) ;
return;
case V_57 :
V_9 -> V_58 . V_59 =
V_60 ;
F_3 ( 0 ) ;
return;
case V_61 :
V_9 -> V_62 . V_59 = 0 ;
F_3 ( 0 ) ;
return;
default:
F_3 ( 0 ) ;
return;
}
}
V_28 -> V_39 = V_40
| V_41 ;
F_12 ( V_31 , V_35 ,
V_44 , V_45 ,
V_42 , 0 ) ;
}
}
int
F_17 ( struct V_63 * V_64 )
{
int V_65 ;
V_65 = F_18 ( & V_66 , V_67 , F_4 ) ;
if ( V_65 )
return V_65 ;
V_35 = V_64 -> V_35 ;
V_14 . V_15 = true ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( & V_66 ) ;
F_7 ( & V_17 ) ;
F_21 ( & V_55 ) ;
}
