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
struct V_18 V_19 ;
int V_20 = V_4 . V_21 -> V_20 ;
struct V_18 * V_22 ;
void * V_23 ;
int V_24 , V_25 ;
switch ( V_20 ) {
case V_26 :
V_25 = sizeof( struct V_18 ) ;
memset ( & V_19 , 0 , V_25 ) ;
V_19 . V_27 . V_20 = V_20 ;
V_22 = (struct V_18 * ) V_4 . V_21 ;
F_8 ( ( V_28 * ) V_22 -> V_29 , V_30 ,
V_31 ,
( V_32 * ) & V_19 . V_29 , V_30 - 1 ) ;
F_8 ( ( V_28 * ) V_22 -> V_33 , V_30 ,
V_31 ,
( V_32 * ) & V_19 . V_33 , V_30 - 1 ) ;
V_19 . V_34 = V_22 -> V_34 ;
V_19 . V_35 = V_22 -> V_35 ;
V_23 = & V_19 ;
break;
default:
V_23 = V_4 . V_21 ;
V_25 = V_4 . V_36 ;
break;
}
V_4 . V_5 = V_37 ;
V_24 = F_5 ( V_15 , V_23 , V_25 ) ;
if ( V_24 ) {
F_6 ( L_2 , V_24 ) ;
if ( F_9 ( & V_38 ) ) {
F_2 ( V_3 ) ;
V_4 . V_5 = V_6 ;
}
}
return;
}
static void
F_2 ( int error )
{
struct V_39 * V_40 ;
T_1 V_41 ;
struct V_42 * V_43 ;
T_2 V_44 ;
V_41 = V_4 . V_36 ;
V_43 = V_4 . V_45 ;
V_44 = V_4 . V_46 ;
V_40 = (struct V_39 * )
& V_47 [ sizeof( struct V_48 ) ] ;
if ( V_43 -> V_49 == NULL )
return;
V_40 -> V_50 = error ;
V_40 -> V_51 = V_52 | V_53 ;
F_10 ( V_43 , V_47 , V_41 , V_44 ,
V_54 , 0 ) ;
}
void V_8 ( void * V_55 )
{
struct V_42 * V_43 = V_55 ;
T_1 V_56 ;
T_2 V_57 ;
struct V_58 * V_21 ;
struct V_39 * V_40 ;
struct V_59 * V_60 = NULL ;
int V_61 ;
int V_62 ;
if ( V_4 . V_5 > V_6 ) {
V_4 . V_7 = V_55 ;
return;
}
V_4 . V_7 = NULL ;
F_11 ( V_43 , V_47 , V_63 * 2 , & V_56 ,
& V_57 ) ;
if ( V_56 <= 0 )
return;
V_40 = (struct V_39 * ) & V_47 [
sizeof( struct V_48 ) ] ;
if ( V_40 -> V_64 == V_65 ) {
V_61 = V_66 ;
V_62 = V_67 ;
F_12 ( V_40 , V_60 , V_47 ,
V_61 , V_62 ) ;
} else {
V_21 = (struct V_58 * ) & V_47 [
sizeof( struct V_48 ) +
sizeof( struct V_39 ) ] ;
V_4 . V_36 = V_56 ;
V_4 . V_45 = V_43 ;
V_4 . V_46 = V_57 ;
V_4 . V_21 = V_21 ;
if ( V_4 . V_5 < V_6 ) {
F_2 ( V_3 ) ;
return;
}
V_4 . V_5 = V_68 ;
F_13 ( & V_69 ) ;
F_14 ( & V_38 , 5 * V_70 ) ;
return;
}
V_40 -> V_51 = V_52 | V_53 ;
F_10 ( V_43 , V_47 , V_56 , V_57 ,
V_54 , 0 ) ;
}
static int F_15 ( void * V_71 , int V_72 )
{
int * V_73 = ( int * ) V_71 ;
if ( V_72 != sizeof( int ) )
return - V_17 ;
if ( V_4 . V_5 == V_74 )
return F_4 ( * V_73 ) ;
if ( V_4 . V_5 != V_37 )
return - V_17 ;
if ( F_9 ( & V_38 ) ) {
V_4 . V_5 = V_75 ;
F_2 ( * V_73 ) ;
V_4 . V_5 = V_6 ;
F_3 ( V_4 . V_7 ,
V_8 ) ;
}
return 0 ;
}
static void F_16 ( void )
{
V_4 . V_5 = V_74 ;
if ( F_9 ( & V_38 ) )
F_2 ( V_3 ) ;
}
int F_17 ( struct V_76 * V_77 )
{
V_47 = V_77 -> V_47 ;
V_4 . V_5 = V_74 ;
V_15 = F_18 ( V_78 , 0 , 0 ,
F_15 , F_16 ) ;
if ( ! V_15 )
return - V_16 ;
return 0 ;
}
void F_19 ( void )
{
V_4 . V_5 = V_79 ;
F_9 ( & V_38 ) ;
F_20 ( V_15 ) ;
}
