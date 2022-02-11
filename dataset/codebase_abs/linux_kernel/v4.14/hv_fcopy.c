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
case V_37 :
V_23 = V_2 . V_21 ;
V_25 = sizeof( struct V_38 ) ;
break;
default:
V_23 = V_2 . V_21 ;
V_25 = V_2 . V_39 ;
break;
}
V_2 . V_3 = V_40 ;
V_24 = F_9 ( V_15 , V_23 , V_25 , NULL ) ;
if ( V_24 ) {
F_7 ( L_3 , V_24 ) ;
if ( F_13 ( & V_41 ) ) {
F_4 ( V_7 ) ;
V_2 . V_3 = V_4 ;
}
}
F_14 ( V_19 ) ;
}
static void
F_4 ( int error )
{
struct V_42 * V_43 ;
T_1 V_44 ;
struct V_45 * V_1 ;
T_2 V_46 ;
V_44 = V_2 . V_39 ;
V_1 = V_2 . V_8 ;
V_46 = V_2 . V_47 ;
V_43 = (struct V_42 * )
& V_48 [ sizeof( struct V_49 ) ] ;
if ( V_1 -> V_50 == NULL )
return;
V_43 -> V_51 = error ;
V_43 -> V_52 = V_53 | V_54 ;
F_15 ( V_1 , V_48 , V_44 , V_46 ,
V_55 , 0 ) ;
}
void F_2 ( void * V_56 )
{
struct V_45 * V_1 = V_56 ;
T_1 V_57 ;
T_2 V_58 ;
struct V_59 * V_21 ;
struct V_42 * V_43 ;
int V_60 ;
if ( V_2 . V_3 > V_4 )
return;
F_16 ( V_1 , V_48 , V_61 * 2 , & V_57 ,
& V_58 ) ;
if ( V_57 <= 0 )
return;
V_43 = (struct V_42 * ) & V_48 [
sizeof( struct V_49 ) ] ;
if ( V_43 -> V_62 == V_63 ) {
if ( F_17 ( V_43 , V_48 ,
V_64 , V_65 ,
V_66 , V_67 ,
NULL , & V_60 ) ) {
F_18 ( L_4 ,
V_60 >> 16 ,
V_60 & 0xFFFF ) ;
}
} else {
V_21 = (struct V_59 * ) & V_48 [
sizeof( struct V_49 ) +
sizeof( struct V_42 ) ] ;
V_2 . V_39 = V_57 ;
V_2 . V_47 = V_58 ;
V_2 . V_21 = V_21 ;
if ( V_2 . V_3 < V_4 ) {
F_4 ( V_7 ) ;
return;
}
V_2 . V_3 = V_68 ;
F_19 ( & V_69 ) ;
F_20 ( & V_41 ,
V_70 * V_71 ) ;
return;
}
V_43 -> V_52 = V_53 | V_54 ;
F_15 ( V_1 , V_48 , V_57 , V_58 ,
V_55 , 0 ) ;
}
static int F_21 ( void * V_72 , int V_73 )
{
int * V_74 = ( int * ) V_72 ;
if ( V_73 != sizeof( int ) )
return - V_17 ;
if ( V_2 . V_3 == V_75 )
return F_8 ( * V_74 ) ;
if ( V_2 . V_3 != V_40 )
return - V_17 ;
if ( F_13 ( & V_41 ) ) {
V_2 . V_3 = V_76 ;
F_4 ( * V_74 ) ;
F_5 ( V_2 . V_8 ,
F_1 ) ;
}
return 0 ;
}
static void F_22 ( void )
{
V_2 . V_3 = V_75 ;
if ( F_13 ( & V_41 ) )
F_4 ( V_7 ) ;
}
int F_23 ( struct V_77 * V_78 )
{
V_48 = V_78 -> V_48 ;
V_2 . V_8 = V_78 -> V_1 ;
V_2 . V_3 = V_75 ;
V_15 = F_24 ( V_79 , 0 , 0 ,
F_21 , F_22 ) ;
if ( ! V_15 )
return - V_16 ;
return 0 ;
}
void F_25 ( void )
{
V_2 . V_3 = V_80 ;
F_13 ( & V_41 ) ;
F_26 ( V_15 ) ;
}
