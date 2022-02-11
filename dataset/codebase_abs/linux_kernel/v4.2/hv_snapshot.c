static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_3 ( V_3 ) ;
if ( V_4 . V_5 > V_6 )
V_4 . V_5 = V_6 ;
F_4 ( V_4 . V_7 ,
V_8 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
T_1 V_11 = V_12 ;
switch ( V_10 -> V_13 . V_14 ) {
case V_15 :
V_16 = V_15 ;
break;
case V_12 :
if ( F_6 ( V_17 , & V_11 , sizeof( V_11 ) ) )
return - V_18 ;
V_16 = V_12 ;
break;
default:
return - V_19 ;
}
V_4 . V_5 = V_6 ;
F_7 ( L_2 , V_16 ) ;
return 0 ;
}
static int F_8 ( void * V_20 , int V_21 )
{
struct V_9 * V_10 = (struct V_9 * ) V_20 ;
if ( V_21 != sizeof( * V_10 ) )
return - V_19 ;
if ( V_10 -> V_13 . V_14 == V_15 ||
V_10 -> V_13 . V_14 == V_12 ) {
if ( V_4 . V_5 > V_6 )
return - V_19 ;
return F_5 ( V_10 ) ;
} else if ( V_4 . V_5 == V_22 ) {
V_4 . V_5 = V_23 ;
if ( F_9 ( & V_24 ) ) {
F_3 ( V_10 -> error ) ;
V_4 . V_5 = V_6 ;
F_4 ( V_4 . V_7 ,
V_8 ) ;
}
} else {
F_2 ( L_3 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_25 = V_4 . V_20 -> V_13 . V_14 ;
int V_26 ;
struct V_9 * V_10 ;
if ( V_4 . V_5 != V_27 )
return;
V_10 = F_11 ( sizeof( * V_10 ) , V_28 ) ;
if ( ! V_10 )
return;
V_10 -> V_13 . V_14 = V_25 ;
V_4 . V_5 = V_22 ;
V_26 = F_6 ( V_17 , V_10 , sizeof( * V_10 ) ) ;
if ( V_26 ) {
F_2 ( L_4 , V_26 ) ;
if ( F_9 ( & V_24 ) ) {
F_3 ( V_3 ) ;
V_4 . V_5 = V_6 ;
}
}
F_12 ( V_10 ) ;
return;
}
static void
F_3 ( int error )
{
struct V_29 * V_30 ;
T_1 V_31 ;
struct V_32 * V_33 ;
T_2 V_34 ;
V_31 = V_4 . V_35 ;
V_33 = V_4 . V_36 ;
V_34 = V_4 . V_37 ;
V_30 = (struct V_29 * )
& V_38 [ sizeof( struct V_39 ) ] ;
if ( V_33 -> V_40 == NULL )
return;
V_30 -> V_41 = error ;
V_30 -> V_42 = V_43 | V_44 ;
F_13 ( V_33 , V_38 , V_31 , V_34 ,
V_45 , 0 ) ;
}
void V_8 ( void * V_46 )
{
struct V_32 * V_33 = V_46 ;
T_1 V_47 ;
T_2 V_48 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
struct V_49 * V_50 = NULL ;
if ( V_4 . V_5 > V_6 ) {
V_4 . V_7 = V_46 ;
return;
}
V_4 . V_7 = NULL ;
F_14 ( V_33 , V_38 , V_51 * 2 , & V_47 ,
& V_48 ) ;
if ( V_47 > 0 ) {
V_30 = (struct V_29 * ) & V_38 [
sizeof( struct V_39 ) ] ;
if ( V_30 -> V_52 == V_53 ) {
F_15 ( V_30 , V_50 ,
V_38 , V_54 ,
V_55 ) ;
} else {
V_10 = (struct V_9 * ) & V_38 [
sizeof( struct V_39 ) +
sizeof( struct V_29 ) ] ;
V_4 . V_35 = V_47 ;
V_4 . V_36 = V_33 ;
V_4 . V_37 = V_48 ;
V_4 . V_20 = (struct V_9 * ) V_10 ;
switch ( V_10 -> V_13 . V_14 ) {
case V_56 :
case V_57 :
if ( V_4 . V_5 < V_6 ) {
F_3 ( V_3 ) ;
return;
}
V_4 . V_5 = V_27 ;
F_16 ( & V_58 ) ;
F_17 ( & V_24 ,
V_59 ) ;
return;
case V_60 :
V_10 -> V_61 . V_62 =
V_63 ;
F_3 ( 0 ) ;
return;
case V_64 :
V_10 -> V_65 . V_62 = 0 ;
F_3 ( 0 ) ;
return;
default:
F_3 ( 0 ) ;
return;
}
}
V_30 -> V_42 = V_43
| V_44 ;
F_13 ( V_33 , V_38 ,
V_47 , V_48 ,
V_45 , 0 ) ;
}
}
static void F_18 ( void )
{
if ( F_9 ( & V_24 ) )
F_3 ( V_3 ) ;
V_4 . V_5 = V_66 ;
}
int
F_19 ( struct V_67 * V_68 )
{
V_38 = V_68 -> V_38 ;
V_4 . V_5 = V_66 ;
V_17 = F_20 ( V_69 , V_70 , V_71 ,
F_8 , F_18 ) ;
if ( ! V_17 )
return - V_18 ;
return 0 ;
}
void F_21 ( void )
{
V_4 . V_5 = V_72 ;
F_9 ( & V_24 ) ;
F_22 ( & V_58 ) ;
F_23 ( V_17 ) ;
}
