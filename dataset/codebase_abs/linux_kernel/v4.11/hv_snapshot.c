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
F_11 ( L_3 , V_16 ) ;
return 0 ;
}
static int F_12 ( void * V_20 , int V_21 )
{
struct V_9 * V_10 = (struct V_9 * ) V_20 ;
if ( V_21 != sizeof( * V_10 ) ) {
F_8 ( L_4 ) ;
return - V_19 ;
}
if ( V_10 -> V_13 . V_14 == V_15 ||
V_10 -> V_13 . V_14 == V_12 ) {
if ( V_2 . V_3 > V_4 ) {
F_8 ( L_5 ) ;
return - V_19 ;
}
return F_9 ( V_10 ) ;
} else if ( V_2 . V_3 == V_22 ) {
V_2 . V_3 = V_23 ;
if ( V_10 -> V_13 . V_14 == V_24 )
V_2 . V_20 -> V_25 . V_26 =
V_27 ;
if ( F_13 ( & V_28 ) ) {
F_5 ( V_10 -> error ) ;
F_6 ( V_2 . V_8 ,
F_1 ) ;
}
} else {
F_8 ( L_6 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_14 ( void )
{
int V_29 = V_2 . V_20 -> V_13 . V_14 ;
int V_30 ;
struct V_9 * V_10 ;
if ( V_2 . V_3 != V_31 ) {
F_8 ( L_7 ) ;
return;
}
V_10 = F_15 ( sizeof( * V_10 ) , V_32 ) ;
if ( ! V_10 )
return;
V_10 -> V_13 . V_14 = V_29 ;
V_2 . V_3 = V_22 ;
F_16 ( & V_28 , V_29 == V_33 ?
V_34 * V_35 : V_36 * V_35 ) ;
V_30 = F_10 ( V_17 , V_10 , sizeof( * V_10 ) , NULL ) ;
if ( V_30 ) {
F_4 ( L_8 , V_30 ) ;
if ( F_13 ( & V_28 ) ) {
F_5 ( V_7 ) ;
V_2 . V_3 = V_4 ;
}
}
F_17 ( V_10 ) ;
return;
}
static void F_18 ( struct V_5 * V_6 )
{
switch ( V_2 . V_20 -> V_13 . V_14 ) {
case V_37 :
case V_33 :
case V_24 :
if ( V_2 . V_3 < V_4 ) {
F_8 ( L_9 ) ;
F_5 ( V_7 ) ;
return;
}
F_8 ( L_10 ,
V_2 . V_20 -> V_13 . V_14 ) ;
V_2 . V_3 = V_31 ;
F_14 () ;
return;
case V_38 :
V_2 . V_20 -> V_39 . V_26 = 0 ;
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
struct V_40 * V_41 ;
T_1 V_42 ;
struct V_43 * V_1 ;
T_2 V_44 ;
V_42 = V_2 . V_45 ;
V_1 = V_2 . V_8 ;
V_44 = V_2 . V_46 ;
V_41 = (struct V_40 * )
& V_47 [ sizeof( struct V_48 ) ] ;
if ( V_1 -> V_49 == NULL )
return;
V_41 -> V_50 = error ;
V_41 -> V_51 = V_52 | V_53 ;
F_19 ( V_1 , V_47 , V_42 , V_44 ,
V_54 , 0 ) ;
}
void F_2 ( void * V_55 )
{
struct V_43 * V_1 = V_55 ;
T_1 V_56 ;
T_2 V_57 ;
struct V_9 * V_10 ;
int V_58 ;
struct V_40 * V_41 ;
if ( V_2 . V_3 > V_4 )
return;
F_20 ( V_1 , V_47 , V_59 * 2 , & V_56 ,
& V_57 ) ;
if ( V_56 > 0 ) {
V_41 = (struct V_40 * ) & V_47 [
sizeof( struct V_48 ) ] ;
if ( V_41 -> V_60 == V_61 ) {
if ( F_21 ( V_41 ,
V_47 , V_62 , V_63 ,
V_64 , V_65 ,
NULL , & V_58 ) ) {
F_11 ( L_11 ,
V_58 >> 16 ,
V_58 & 0xFFFF ) ;
}
} else {
V_10 = (struct V_9 * ) & V_47 [
sizeof( struct V_48 ) +
sizeof( struct V_40 ) ] ;
V_2 . V_45 = V_56 ;
V_2 . V_46 = V_57 ;
V_2 . V_20 = (struct V_9 * ) V_10 ;
F_22 ( & V_66 ) ;
return;
}
V_41 -> V_51 = V_52
| V_53 ;
F_19 ( V_1 , V_47 ,
V_56 , V_57 ,
V_54 , 0 ) ;
}
}
static void F_23 ( void )
{
if ( F_13 ( & V_28 ) )
F_5 ( V_7 ) ;
V_2 . V_3 = V_67 ;
}
int
F_24 ( struct V_68 * V_69 )
{
if ( V_70 < V_71 ) {
F_4 ( L_12
L_13 ) ;
return - V_72 ;
}
V_47 = V_69 -> V_47 ;
V_2 . V_8 = V_69 -> V_1 ;
V_2 . V_3 = V_67 ;
V_17 = F_25 ( V_73 , V_74 , V_75 ,
F_12 , F_23 ) ;
if ( ! V_17 ) {
F_4 ( L_14 ) ;
return - V_18 ;
}
return 0 ;
}
void F_26 ( void )
{
V_2 . V_3 = V_76 ;
F_13 ( & V_28 ) ;
F_27 ( & V_66 ) ;
F_28 ( V_17 ) ;
}
