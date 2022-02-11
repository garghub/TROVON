static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
if ( V_4 . V_5 > V_6 )
V_4 . V_5 = V_6 ;
F_3 ( V_4 . V_7 ,
V_8 ) ;
}
static int F_4 ( T_1 V_9 )
{
T_1 V_10 = V_11 ;
switch ( V_9 ) {
case V_12 :
V_13 = V_9 ;
break;
case V_14 :
if ( F_5 ( V_15 , & V_10 , sizeof( V_10 ) ) )
return - V_16 ;
V_13 = V_9 ;
break;
default:
return - V_17 ;
}
F_6 ( L_1 , V_9 ) ;
V_4 . V_5 = V_6 ;
F_3 ( V_4 . V_7 ,
V_8 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = NULL ;
int V_20 = V_4 . V_21 -> V_20 ;
struct V_18 * V_22 ;
void * V_23 ;
int V_24 , V_25 ;
switch ( V_20 ) {
case V_26 :
V_25 = sizeof( struct V_18 ) ;
V_19 = F_8 ( sizeof( * V_19 ) , V_27 ) ;
if ( ! V_19 )
return;
V_19 -> V_28 . V_20 = V_20 ;
V_22 = (struct V_18 * ) V_4 . V_21 ;
F_9 ( ( V_29 * ) V_22 -> V_30 , V_31 ,
V_32 ,
( V_33 * ) & V_19 -> V_30 , V_31 - 1 ) ;
F_9 ( ( V_29 * ) V_22 -> V_34 , V_31 ,
V_32 ,
( V_33 * ) & V_19 -> V_34 , V_31 - 1 ) ;
V_19 -> V_35 = V_22 -> V_35 ;
V_19 -> V_36 = V_22 -> V_36 ;
V_23 = V_19 ;
break;
default:
V_23 = V_4 . V_21 ;
V_25 = V_4 . V_37 ;
break;
}
V_4 . V_5 = V_38 ;
V_24 = F_5 ( V_15 , V_23 , V_25 ) ;
if ( V_24 ) {
F_6 ( L_2 , V_24 ) ;
if ( F_10 ( & V_39 ) ) {
F_2 ( V_3 ) ;
V_4 . V_5 = V_6 ;
}
}
F_11 ( V_19 ) ;
return;
}
static void
F_2 ( int error )
{
struct V_40 * V_41 ;
T_1 V_42 ;
struct V_43 * V_44 ;
T_2 V_45 ;
V_42 = V_4 . V_37 ;
V_44 = V_4 . V_46 ;
V_45 = V_4 . V_47 ;
V_41 = (struct V_40 * )
& V_48 [ sizeof( struct V_49 ) ] ;
if ( V_44 -> V_50 == NULL )
return;
V_41 -> V_51 = error ;
V_41 -> V_52 = V_53 | V_54 ;
F_12 ( V_44 , V_48 , V_42 , V_45 ,
V_55 , 0 ) ;
}
void V_8 ( void * V_56 )
{
struct V_43 * V_44 = V_56 ;
T_1 V_57 ;
T_2 V_58 ;
struct V_59 * V_21 ;
struct V_40 * V_41 ;
struct V_60 * V_61 = NULL ;
int V_62 ;
int V_63 ;
if ( V_4 . V_5 > V_6 ) {
V_4 . V_7 = V_56 ;
return;
}
V_4 . V_7 = NULL ;
F_13 ( V_44 , V_48 , V_64 * 2 , & V_57 ,
& V_58 ) ;
if ( V_57 <= 0 )
return;
V_41 = (struct V_40 * ) & V_48 [
sizeof( struct V_49 ) ] ;
if ( V_41 -> V_65 == V_66 ) {
V_62 = V_67 ;
V_63 = V_68 ;
F_14 ( V_41 , V_61 , V_48 ,
V_62 , V_63 ) ;
} else {
V_21 = (struct V_59 * ) & V_48 [
sizeof( struct V_49 ) +
sizeof( struct V_40 ) ] ;
V_4 . V_37 = V_57 ;
V_4 . V_46 = V_44 ;
V_4 . V_47 = V_58 ;
V_4 . V_21 = V_21 ;
if ( V_4 . V_5 < V_6 ) {
F_2 ( V_3 ) ;
return;
}
V_4 . V_5 = V_69 ;
F_15 ( & V_70 ) ;
F_16 ( & V_39 , 5 * V_71 ) ;
return;
}
V_41 -> V_52 = V_53 | V_54 ;
F_12 ( V_44 , V_48 , V_57 , V_58 ,
V_55 , 0 ) ;
}
static int F_17 ( void * V_72 , int V_73 )
{
int * V_74 = ( int * ) V_72 ;
if ( V_73 != sizeof( int ) )
return - V_17 ;
if ( V_4 . V_5 == V_75 )
return F_4 ( * V_74 ) ;
if ( V_4 . V_5 != V_38 )
return - V_17 ;
if ( F_10 ( & V_39 ) ) {
V_4 . V_5 = V_76 ;
F_2 ( * V_74 ) ;
V_4 . V_5 = V_6 ;
F_3 ( V_4 . V_7 ,
V_8 ) ;
}
return 0 ;
}
static void F_18 ( void )
{
V_4 . V_5 = V_75 ;
if ( F_10 ( & V_39 ) )
F_2 ( V_3 ) ;
}
int F_19 ( struct V_77 * V_78 )
{
V_48 = V_78 -> V_48 ;
V_4 . V_5 = V_75 ;
V_15 = F_20 ( V_79 , 0 , 0 ,
F_17 , F_18 ) ;
if ( ! V_15 )
return - V_16 ;
return 0 ;
}
void F_21 ( void )
{
V_4 . V_5 = V_80 ;
F_10 ( & V_39 ) ;
F_22 ( V_15 ) ;
}
