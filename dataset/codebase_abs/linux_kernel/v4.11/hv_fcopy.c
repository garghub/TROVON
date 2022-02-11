static void F_1 ( void * V_1 )
{
V_2 . V_3 = V_4 ;
F_2 ( V_1 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
F_4 ( V_7 ) ;
F_5 ( V_2 . V_8 , F_1 ) ;
}
static void F_6 ( void )
{
F_7 ( L_1 ) ;
F_5 ( V_2 . V_8 , F_1 ) ;
}
static int F_8 ( T_1 V_9 )
{
T_1 V_10 = V_11 ;
switch ( V_9 ) {
case V_12 :
V_13 = V_9 ;
break;
case V_14 :
if ( F_9 ( V_15 , & V_10 , sizeof( V_10 ) ,
F_6 ) )
return - V_16 ;
V_13 = V_9 ;
break;
default:
return - V_17 ;
}
F_7 ( L_2 , V_9 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = NULL ;
int V_20 = V_2 . V_21 -> V_20 ;
struct V_18 * V_22 ;
void * V_23 ;
int V_24 , V_25 ;
switch ( V_20 ) {
case V_26 :
V_25 = sizeof( struct V_18 ) ;
V_19 = F_11 ( sizeof( * V_19 ) , V_27 ) ;
if ( ! V_19 )
return;
V_19 -> V_28 . V_20 = V_20 ;
V_22 = (struct V_18 * ) V_2 . V_21 ;
F_12 ( ( V_29 * ) V_22 -> V_30 , V_31 ,
V_32 ,
( V_33 * ) & V_19 -> V_30 , V_31 - 1 ) ;
F_12 ( ( V_29 * ) V_22 -> V_34 , V_31 ,
V_32 ,
( V_33 * ) & V_19 -> V_34 , V_31 - 1 ) ;
V_19 -> V_35 = V_22 -> V_35 ;
V_19 -> V_36 = V_22 -> V_36 ;
V_23 = V_19 ;
break;
default:
V_23 = V_2 . V_21 ;
V_25 = V_2 . V_37 ;
break;
}
V_2 . V_3 = V_38 ;
V_24 = F_9 ( V_15 , V_23 , V_25 , NULL ) ;
if ( V_24 ) {
F_7 ( L_3 , V_24 ) ;
if ( F_13 ( & V_39 ) ) {
F_4 ( V_7 ) ;
V_2 . V_3 = V_4 ;
}
}
F_14 ( V_19 ) ;
return;
}
static void
F_4 ( int error )
{
struct V_40 * V_41 ;
T_1 V_42 ;
struct V_43 * V_1 ;
T_2 V_44 ;
V_42 = V_2 . V_37 ;
V_1 = V_2 . V_8 ;
V_44 = V_2 . V_45 ;
V_41 = (struct V_40 * )
& V_46 [ sizeof( struct V_47 ) ] ;
if ( V_1 -> V_48 == NULL )
return;
V_41 -> V_49 = error ;
V_41 -> V_50 = V_51 | V_52 ;
F_15 ( V_1 , V_46 , V_42 , V_44 ,
V_53 , 0 ) ;
}
void F_2 ( void * V_54 )
{
struct V_43 * V_1 = V_54 ;
T_1 V_55 ;
T_2 V_56 ;
struct V_57 * V_21 ;
struct V_40 * V_41 ;
int V_58 ;
if ( V_2 . V_3 > V_4 )
return;
F_16 ( V_1 , V_46 , V_59 * 2 , & V_55 ,
& V_56 ) ;
if ( V_55 <= 0 )
return;
V_41 = (struct V_40 * ) & V_46 [
sizeof( struct V_47 ) ] ;
if ( V_41 -> V_60 == V_61 ) {
if ( F_17 ( V_41 , V_46 ,
V_62 , V_63 ,
V_64 , V_65 ,
NULL , & V_58 ) ) {
F_18 ( L_4 ,
V_58 >> 16 ,
V_58 & 0xFFFF ) ;
}
} else {
V_21 = (struct V_57 * ) & V_46 [
sizeof( struct V_47 ) +
sizeof( struct V_40 ) ] ;
V_2 . V_37 = V_55 ;
V_2 . V_45 = V_56 ;
V_2 . V_21 = V_21 ;
if ( V_2 . V_3 < V_4 ) {
F_4 ( V_7 ) ;
return;
}
V_2 . V_3 = V_66 ;
F_19 ( & V_67 ) ;
F_20 ( & V_39 ,
V_68 * V_69 ) ;
return;
}
V_41 -> V_50 = V_51 | V_52 ;
F_15 ( V_1 , V_46 , V_55 , V_56 ,
V_53 , 0 ) ;
}
static int F_21 ( void * V_70 , int V_71 )
{
int * V_72 = ( int * ) V_70 ;
if ( V_71 != sizeof( int ) )
return - V_17 ;
if ( V_2 . V_3 == V_73 )
return F_8 ( * V_72 ) ;
if ( V_2 . V_3 != V_38 )
return - V_17 ;
if ( F_13 ( & V_39 ) ) {
V_2 . V_3 = V_74 ;
F_4 ( * V_72 ) ;
F_5 ( V_2 . V_8 ,
F_1 ) ;
}
return 0 ;
}
static void F_22 ( void )
{
V_2 . V_3 = V_73 ;
if ( F_13 ( & V_39 ) )
F_4 ( V_7 ) ;
}
int F_23 ( struct V_75 * V_76 )
{
V_46 = V_76 -> V_46 ;
V_2 . V_8 = V_76 -> V_1 ;
V_2 . V_3 = V_73 ;
V_15 = F_24 ( V_77 , 0 , 0 ,
F_21 , F_22 ) ;
if ( ! V_15 )
return - V_16 ;
return 0 ;
}
void F_25 ( void )
{
V_2 . V_3 = V_78 ;
F_13 ( & V_39 ) ;
F_26 ( V_15 ) ;
}
