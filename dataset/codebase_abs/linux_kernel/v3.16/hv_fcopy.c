static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
}
static int F_3 ( T_1 V_4 )
{
switch ( V_4 ) {
case V_5 :
break;
default:
return - V_6 ;
}
F_4 ( L_1 ,
V_4 ) ;
V_7 . V_8 = false ;
if ( V_7 . V_9 )
F_5 ( V_7 . V_9 ) ;
V_10 = false ;
return 0 ;
}
static void F_6 ( void )
{
struct V_11 * V_12 = & V_7 . V_13 ;
int V_14 = V_7 . V_15 -> V_14 ;
struct V_11 * V_16 ;
switch ( V_14 ) {
case V_17 :
memset ( V_12 , 0 , sizeof( struct V_11 ) ) ;
V_12 -> V_18 . V_14 = V_14 ;
V_16 = (struct V_11 * ) V_7 . V_15 ;
F_7 ( ( V_19 * ) V_16 -> V_20 , V_21 ,
V_22 ,
( V_23 * ) V_12 -> V_20 , V_21 - 1 ) ;
F_7 ( ( V_19 * ) V_16 -> V_24 , V_21 ,
V_22 ,
( V_23 * ) V_12 -> V_24 , V_21 - 1 ) ;
V_12 -> V_25 = V_16 -> V_25 ;
V_12 -> V_26 = V_16 -> V_26 ;
break;
default:
break;
}
F_8 ( & V_7 . V_27 ) ;
return;
}
static void
F_2 ( int error )
{
struct V_28 * V_29 ;
T_1 V_30 ;
struct V_31 * V_32 ;
T_2 V_33 ;
V_30 = V_7 . V_34 ;
V_32 = V_7 . V_35 ;
V_33 = V_7 . V_36 ;
V_7 . V_8 = false ;
V_29 = (struct V_28 * )
& V_37 [ sizeof( struct V_38 ) ] ;
if ( V_32 -> V_39 == NULL )
return;
V_29 -> V_40 = error ;
V_29 -> V_41 = V_42 | V_43 ;
F_9 ( V_32 , V_37 , V_30 , V_33 ,
V_44 , 0 ) ;
}
void F_5 ( void * V_45 )
{
struct V_31 * V_32 = V_45 ;
T_1 V_46 ;
T_2 V_47 ;
struct V_48 * V_15 ;
struct V_28 * V_29 ;
struct V_49 * V_50 = NULL ;
int V_51 ;
int V_52 ;
if ( V_7 . V_8 ) {
V_7 . V_9 = V_45 ;
return;
}
F_10 ( V_32 , V_37 , V_53 * 2 , & V_46 ,
& V_47 ) ;
if ( V_46 <= 0 )
return;
V_29 = (struct V_28 * ) & V_37 [
sizeof( struct V_38 ) ] ;
if ( V_29 -> V_54 == V_55 ) {
V_51 = V_56 ;
V_52 = V_57 ;
F_11 ( V_29 , V_50 , V_37 ,
V_51 , V_52 ) ;
} else {
V_15 = (struct V_48 * ) & V_37 [
sizeof( struct V_38 ) +
sizeof( struct V_28 ) ] ;
V_7 . V_8 = true ;
V_7 . V_34 = V_46 ;
V_7 . V_35 = V_32 ;
V_7 . V_36 = V_47 ;
V_7 . V_15 = V_15 ;
F_12 ( & V_58 , 5 * V_59 ) ;
F_6 () ;
return;
}
V_29 -> V_41 = V_42 | V_43 ;
F_9 ( V_32 , V_37 , V_46 , V_47 ,
V_44 , 0 ) ;
}
static T_3 F_13 ( struct V_60 * V_60 , char T_4 * V_61 ,
T_5 V_62 , T_6 * V_63 )
{
void * V_64 ;
T_5 V_65 ;
int V_14 ;
if ( F_14 ( & V_7 . V_27 ) )
return - V_66 ;
if ( ! V_67 )
return - V_68 ;
V_14 = V_7 . V_15 -> V_14 ;
if ( V_14 == V_17 ) {
V_64 = & V_7 . V_13 ;
V_65 = sizeof( struct V_11 ) ;
if ( V_62 < V_65 )
return 0 ;
} else {
V_64 = V_7 . V_15 ;
V_65 = sizeof( struct V_69 ) ;
if ( V_62 < V_65 )
return 0 ;
}
if ( F_15 ( V_61 , V_64 , V_65 ) )
return - V_70 ;
return V_65 ;
}
static T_3 F_16 ( struct V_60 * V_60 , const char T_4 * V_61 ,
T_5 V_62 , T_6 * V_63 )
{
int V_71 = 0 ;
if ( V_62 != sizeof( int ) )
return - V_6 ;
if ( F_17 ( & V_71 , V_61 , sizeof( int ) ) )
return - V_70 ;
if ( V_10 ) {
if ( F_3 ( V_71 ) )
return - V_6 ;
return sizeof( int ) ;
}
if ( F_18 ( & V_58 ) )
F_2 ( V_71 ) ;
return sizeof( int ) ;
}
static int F_19 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
if ( V_67 )
return - V_74 ;
V_67 = true ;
return 0 ;
}
static int F_20 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
V_10 = true ;
V_67 = false ;
return 0 ;
}
static int F_21 ( void )
{
return F_22 ( & V_75 ) ;
}
static void F_23 ( void )
{
V_67 = false ;
F_8 ( & V_7 . V_27 ) ;
F_24 ( & V_75 ) ;
}
int F_25 ( struct V_76 * V_77 )
{
V_37 = V_77 -> V_37 ;
V_7 . V_8 = true ;
F_26 ( & V_7 . V_27 , 0 ) ;
return F_21 () ;
}
void F_27 ( void )
{
F_18 ( & V_58 ) ;
F_23 () ;
}
