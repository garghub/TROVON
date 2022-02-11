static void F_1 ( void * V_1 )
{
V_2 . V_3 = V_4 ;
F_2 ( V_1 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
F_4 ( L_1 ) ;
F_5 ( V_7 ) ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
static void F_7 ( void )
{
F_6 ( V_2 . V_8 , F_1 ) ;
F_8 ( L_2 ) ;
}
static int F_9 ( struct V_9 * V_10 )
{
T_1 V_11 = V_12 ;
switch ( V_10 -> V_13 . V_14 ) {
case V_15 :
V_16 = V_15 ;
break;
case V_12 :
if ( F_10 ( V_17 , & V_11 , sizeof( V_11 ) ,
F_7 ) )
return - V_18 ;
V_16 = V_12 ;
break;
default:
return - V_19 ;
}
F_8 ( L_3 , V_16 ) ;
return 0 ;
}
static int F_11 ( void * V_20 , int V_21 )
{
struct V_9 * V_10 = (struct V_9 * ) V_20 ;
if ( V_21 != sizeof( * V_10 ) )
return - V_19 ;
if ( V_10 -> V_13 . V_14 == V_15 ||
V_10 -> V_13 . V_14 == V_12 ) {
if ( V_2 . V_3 > V_4 )
return - V_19 ;
return F_9 ( V_10 ) ;
} else if ( V_2 . V_3 == V_22 ) {
V_2 . V_3 = V_23 ;
if ( V_10 -> V_13 . V_14 == V_24 )
V_2 . V_20 -> V_25 . V_26 =
V_27 ;
if ( F_12 ( & V_28 ) ) {
F_5 ( V_10 -> error ) ;
F_6 ( V_2 . V_8 ,
F_1 ) ;
}
} else {
F_4 ( L_4 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_13 ( void )
{
int V_29 = V_2 . V_20 -> V_13 . V_14 ;
int V_30 ;
struct V_9 * V_10 ;
if ( V_2 . V_3 != V_31 )
return;
V_10 = F_14 ( sizeof( * V_10 ) , V_32 ) ;
if ( ! V_10 )
return;
V_10 -> V_13 . V_14 = V_29 ;
V_2 . V_3 = V_22 ;
F_15 ( & V_28 , V_33 ) ;
V_30 = F_10 ( V_17 , V_10 , sizeof( * V_10 ) , NULL ) ;
if ( V_30 ) {
F_4 ( L_5 , V_30 ) ;
if ( F_12 ( & V_28 ) ) {
F_5 ( V_7 ) ;
V_2 . V_3 = V_4 ;
}
}
F_16 ( V_10 ) ;
return;
}
static void F_17 ( struct V_5 * V_6 )
{
switch ( V_2 . V_20 -> V_13 . V_14 ) {
case V_34 :
case V_35 :
case V_24 :
if ( V_2 . V_3 < V_4 ) {
F_5 ( V_7 ) ;
return;
}
V_2 . V_3 = V_31 ;
F_13 () ;
return;
case V_36 :
V_2 . V_20 -> V_37 . V_26 = 0 ;
break;
default:
break;
}
F_5 ( 0 ) ;
F_6 ( V_2 . V_8 , F_1 ) ;
}
static void
F_5 ( int error )
{
struct V_38 * V_39 ;
T_1 V_40 ;
struct V_41 * V_1 ;
T_2 V_42 ;
V_40 = V_2 . V_43 ;
V_1 = V_2 . V_8 ;
V_42 = V_2 . V_44 ;
V_39 = (struct V_38 * )
& V_45 [ sizeof( struct V_46 ) ] ;
if ( V_1 -> V_47 == NULL )
return;
V_39 -> V_48 = error ;
V_39 -> V_49 = V_50 | V_51 ;
F_18 ( V_1 , V_45 , V_40 , V_42 ,
V_52 , 0 ) ;
}
void F_2 ( void * V_53 )
{
struct V_41 * V_1 = V_53 ;
T_1 V_54 ;
T_2 V_55 ;
struct V_9 * V_10 ;
struct V_38 * V_39 ;
struct V_56 * V_57 = NULL ;
if ( V_2 . V_3 > V_4 )
return;
F_19 ( V_1 , V_45 , V_58 * 2 , & V_54 ,
& V_55 ) ;
if ( V_54 > 0 ) {
V_39 = (struct V_38 * ) & V_45 [
sizeof( struct V_46 ) ] ;
if ( V_39 -> V_59 == V_60 ) {
F_20 ( V_39 , V_57 ,
V_45 , V_61 ,
V_62 ) ;
} else {
V_10 = (struct V_9 * ) & V_45 [
sizeof( struct V_46 ) +
sizeof( struct V_38 ) ] ;
V_2 . V_43 = V_54 ;
V_2 . V_44 = V_55 ;
V_2 . V_20 = (struct V_9 * ) V_10 ;
F_21 ( & V_63 ) ;
return;
}
V_39 -> V_49 = V_50
| V_51 ;
F_18 ( V_1 , V_45 ,
V_54 , V_55 ,
V_52 , 0 ) ;
}
}
static void F_22 ( void )
{
if ( F_12 ( & V_28 ) )
F_5 ( V_7 ) ;
V_2 . V_3 = V_64 ;
}
int
F_23 ( struct V_65 * V_66 )
{
if ( V_67 < V_68 ) {
F_4 ( L_6
L_7 ) ;
return - V_69 ;
}
V_45 = V_66 -> V_45 ;
V_2 . V_8 = V_66 -> V_1 ;
V_2 . V_3 = V_64 ;
V_17 = F_24 ( V_70 , V_71 , V_72 ,
F_11 , F_22 ) ;
if ( ! V_17 )
return - V_18 ;
return 0 ;
}
void F_25 ( void )
{
V_2 . V_3 = V_73 ;
F_12 ( & V_28 ) ;
F_26 ( & V_63 ) ;
F_27 ( V_17 ) ;
}
