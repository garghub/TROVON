static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
if ( F_3 ( & V_4 . V_5 ) )
;
}
static int F_4 ( T_1 V_6 )
{
switch ( V_6 ) {
case V_7 :
break;
default:
return - V_8 ;
}
F_5 ( L_1 ,
V_6 ) ;
V_4 . V_9 = false ;
if ( V_4 . V_10 )
F_6 ( V_4 . V_10 ) ;
V_11 = false ;
return 0 ;
}
static void F_7 ( void )
{
struct V_12 * V_13 = & V_4 . V_14 ;
int V_15 = V_4 . V_16 -> V_15 ;
struct V_12 * V_17 ;
switch ( V_15 ) {
case V_18 :
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_19 . V_15 = V_15 ;
V_17 = (struct V_12 * ) V_4 . V_16 ;
F_8 ( ( V_20 * ) V_17 -> V_21 , V_22 ,
V_23 ,
( V_24 * ) V_13 -> V_21 , V_22 - 1 ) ;
F_8 ( ( V_20 * ) V_17 -> V_25 , V_22 ,
V_23 ,
( V_24 * ) V_13 -> V_25 , V_22 - 1 ) ;
V_13 -> V_26 = V_17 -> V_26 ;
V_13 -> V_27 = V_17 -> V_27 ;
break;
default:
break;
}
F_9 ( & V_4 . V_5 ) ;
return;
}
static void
F_2 ( int error )
{
struct V_28 * V_29 ;
T_1 V_30 ;
struct V_31 * V_32 ;
T_2 V_33 ;
V_30 = V_4 . V_34 ;
V_32 = V_4 . V_35 ;
V_33 = V_4 . V_36 ;
V_4 . V_9 = false ;
V_29 = (struct V_28 * )
& V_37 [ sizeof( struct V_38 ) ] ;
if ( V_32 -> V_39 == NULL )
return;
V_29 -> V_40 = error ;
V_29 -> V_41 = V_42 | V_43 ;
F_10 ( V_32 , V_37 , V_30 , V_33 ,
V_44 , 0 ) ;
}
void F_6 ( void * V_45 )
{
struct V_31 * V_32 = V_45 ;
T_1 V_46 ;
T_2 V_47 ;
struct V_48 * V_16 ;
struct V_28 * V_29 ;
struct V_49 * V_50 = NULL ;
int V_51 ;
int V_52 ;
if ( V_4 . V_9 ) {
V_4 . V_10 = V_45 ;
return;
}
F_11 ( V_32 , V_37 , V_53 * 2 , & V_46 ,
& V_47 ) ;
if ( V_46 <= 0 )
return;
V_29 = (struct V_28 * ) & V_37 [
sizeof( struct V_38 ) ] ;
if ( V_29 -> V_54 == V_55 ) {
V_51 = V_56 ;
V_52 = V_57 ;
F_12 ( V_29 , V_50 , V_37 ,
V_51 , V_52 ) ;
} else {
V_16 = (struct V_48 * ) & V_37 [
sizeof( struct V_38 ) +
sizeof( struct V_28 ) ] ;
V_4 . V_9 = true ;
V_4 . V_34 = V_46 ;
V_4 . V_35 = V_32 ;
V_4 . V_36 = V_47 ;
V_4 . V_16 = V_16 ;
F_13 ( & V_58 , 5 * V_59 ) ;
F_7 () ;
return;
}
V_29 -> V_41 = V_42 | V_43 ;
F_10 ( V_32 , V_37 , V_46 , V_47 ,
V_44 , 0 ) ;
}
static T_3 F_14 ( struct V_60 * V_60 , char T_4 * V_61 ,
T_5 V_62 , T_6 * V_63 )
{
void * V_64 ;
T_5 V_65 ;
int V_15 ;
if ( F_15 ( & V_4 . V_5 ) )
return - V_66 ;
if ( ! V_67 )
return - V_68 ;
V_15 = V_4 . V_16 -> V_15 ;
if ( V_15 == V_18 ) {
V_64 = & V_4 . V_14 ;
V_65 = sizeof( struct V_12 ) ;
if ( V_62 < V_65 )
return 0 ;
} else {
V_64 = V_4 . V_16 ;
V_65 = sizeof( struct V_69 ) ;
if ( V_62 < V_65 )
return 0 ;
}
if ( F_16 ( V_61 , V_64 , V_65 ) )
return - V_70 ;
return V_65 ;
}
static T_3 F_17 ( struct V_60 * V_60 , const char T_4 * V_61 ,
T_5 V_62 , T_6 * V_63 )
{
int V_71 = 0 ;
if ( V_62 != sizeof( int ) )
return - V_8 ;
if ( F_18 ( & V_71 , V_61 , sizeof( int ) ) )
return - V_70 ;
if ( V_11 ) {
if ( F_4 ( V_71 ) )
return - V_8 ;
return sizeof( int ) ;
}
if ( F_19 ( & V_58 ) )
F_2 ( V_71 ) ;
return sizeof( int ) ;
}
static int F_20 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
if ( V_67 )
return - V_74 ;
V_67 = true ;
return 0 ;
}
static int F_21 ( struct V_72 * V_72 , struct V_60 * V_73 )
{
V_11 = true ;
V_67 = false ;
if ( F_19 ( & V_58 ) ) {
if ( F_3 ( & V_4 . V_5 ) )
;
F_2 ( V_3 ) ;
}
return 0 ;
}
static int F_22 ( void )
{
return F_23 ( & V_75 ) ;
}
static void F_24 ( void )
{
V_67 = false ;
F_9 ( & V_4 . V_5 ) ;
F_25 ( & V_75 ) ;
}
int F_26 ( struct V_76 * V_77 )
{
V_37 = V_77 -> V_37 ;
V_4 . V_9 = true ;
F_27 ( & V_4 . V_5 , 0 ) ;
return F_22 () ;
}
void F_28 ( void )
{
F_19 ( & V_58 ) ;
F_24 () ;
}
