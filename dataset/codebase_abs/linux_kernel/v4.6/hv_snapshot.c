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
static int F_7 ( struct V_9 * V_10 )
{
T_1 V_11 = V_12 ;
switch ( V_10 -> V_13 . V_14 ) {
case V_15 :
V_16 = V_15 ;
break;
case V_12 :
if ( F_8 ( V_17 , & V_11 , sizeof( V_11 ) ) )
return - V_18 ;
V_16 = V_12 ;
break;
default:
return - V_19 ;
}
F_6 ( V_2 . V_8 , F_1 ) ;
F_9 ( L_2 , V_16 ) ;
return 0 ;
}
static int F_10 ( void * V_20 , int V_21 )
{
struct V_9 * V_10 = (struct V_9 * ) V_20 ;
if ( V_21 != sizeof( * V_10 ) )
return - V_19 ;
if ( V_10 -> V_13 . V_14 == V_15 ||
V_10 -> V_13 . V_14 == V_12 ) {
if ( V_2 . V_3 > V_4 )
return - V_19 ;
return F_7 ( V_10 ) ;
} else if ( V_2 . V_3 == V_22 ) {
V_2 . V_3 = V_23 ;
if ( F_11 ( & V_24 ) ) {
F_5 ( V_10 -> error ) ;
F_6 ( V_2 . V_8 ,
F_1 ) ;
}
} else {
F_4 ( L_3 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_12 ( struct V_5 * V_6 )
{
int V_25 = V_2 . V_20 -> V_13 . V_14 ;
int V_26 ;
struct V_9 * V_10 ;
if ( V_2 . V_3 != V_27 )
return;
V_10 = F_13 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 )
return;
V_10 -> V_13 . V_14 = V_25 ;
V_2 . V_3 = V_22 ;
V_26 = F_8 ( V_17 , V_10 , sizeof( * V_10 ) ) ;
if ( V_26 ) {
F_4 ( L_4 , V_26 ) ;
if ( F_11 ( & V_24 ) ) {
F_5 ( V_7 ) ;
V_2 . V_3 = V_4 ;
}
}
F_14 ( V_10 ) ;
return;
}
static void
F_5 ( int error )
{
struct V_29 * V_30 ;
T_1 V_31 ;
struct V_32 * V_1 ;
T_2 V_33 ;
V_31 = V_2 . V_34 ;
V_1 = V_2 . V_8 ;
V_33 = V_2 . V_35 ;
V_30 = (struct V_29 * )
& V_36 [ sizeof( struct V_37 ) ] ;
if ( V_1 -> V_38 == NULL )
return;
V_30 -> V_39 = error ;
V_30 -> V_40 = V_41 | V_42 ;
F_15 ( V_1 , V_36 , V_31 , V_33 ,
V_43 , 0 ) ;
}
void F_2 ( void * V_44 )
{
struct V_32 * V_1 = V_44 ;
T_1 V_45 ;
T_2 V_46 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_47 * V_48 = NULL ;
if ( V_2 . V_3 > V_4 )
return;
F_16 ( V_1 , V_36 , V_49 * 2 , & V_45 ,
& V_46 ) ;
if ( V_45 > 0 ) {
V_30 = (struct V_29 * ) & V_36 [
sizeof( struct V_37 ) ] ;
if ( V_30 -> V_50 == V_51 ) {
F_17 ( V_30 , V_48 ,
V_36 , V_52 ,
V_53 ) ;
} else {
V_10 = (struct V_9 * ) & V_36 [
sizeof( struct V_37 ) +
sizeof( struct V_29 ) ] ;
V_2 . V_34 = V_45 ;
V_2 . V_35 = V_46 ;
V_2 . V_20 = (struct V_9 * ) V_10 ;
switch ( V_10 -> V_13 . V_14 ) {
case V_54 :
case V_55 :
if ( V_2 . V_3 < V_4 ) {
F_5 ( V_7 ) ;
return;
}
V_2 . V_3 = V_27 ;
F_18 ( & V_56 ) ;
F_19 ( & V_24 ,
V_57 ) ;
return;
case V_58 :
V_10 -> V_59 . V_60 =
V_61 ;
F_5 ( 0 ) ;
return;
case V_62 :
V_10 -> V_63 . V_60 = 0 ;
F_5 ( 0 ) ;
return;
default:
F_5 ( 0 ) ;
return;
}
}
V_30 -> V_40 = V_41
| V_42 ;
F_15 ( V_1 , V_36 ,
V_45 , V_46 ,
V_43 , 0 ) ;
}
}
static void F_20 ( void )
{
if ( F_11 ( & V_24 ) )
F_5 ( V_7 ) ;
V_2 . V_3 = V_64 ;
}
int
F_21 ( struct V_65 * V_66 )
{
if ( V_67 < V_68 ) {
F_4 ( L_5
L_6 ) ;
return - V_69 ;
}
V_36 = V_66 -> V_36 ;
V_2 . V_8 = V_66 -> V_1 ;
V_2 . V_3 = V_64 ;
V_17 = F_22 ( V_70 , V_71 , V_72 ,
F_10 , F_20 ) ;
if ( ! V_17 )
return - V_18 ;
return 0 ;
}
void F_23 ( void )
{
V_2 . V_3 = V_73 ;
F_11 ( & V_24 ) ;
F_24 ( & V_56 ) ;
F_25 ( V_17 ) ;
}
