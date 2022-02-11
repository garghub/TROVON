static inline struct V_1 * F_1 ( T_1 * V_2 )
{
F_2 ( sizeof( struct V_1 ) != 20 ) ;
return (struct V_1 * ) ( V_2 + 4 ) ;
}
static inline void F_3 ( T_2 * V_3 , int * V_4 )
{
F_4 () ;
* V_3 = F_5 ( V_5 ) - 1 ;
* V_4 = F_6 () ;
F_7 () ;
}
void F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
struct V_13 V_3 ;
struct V_6 * V_14 ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_21 ;
F_12 () ;
V_14 = F_13 ( V_7 -> V_22 ) ;
V_10 -> V_17 . V_23 . V_24 = V_14 -> V_25 ;
V_10 -> V_17 . V_23 . V_26 = V_14 -> V_27 ;
F_14 () ;
V_10 -> V_17 . V_23 . V_28 = V_7 -> V_25 ;
V_10 -> V_17 . V_23 . V_29 = V_7 -> V_27 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_13 V_3 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_37 ;
V_10 -> V_17 . V_38 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_38 . V_40 = V_7 -> V_27 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_17 ( struct V_6 * V_7 , int V_41 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
struct V_13 V_3 ;
const struct V_42 * V_42 ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
V_10 -> V_20 = V_41 ;
V_10 -> V_17 . V_30 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_30 . V_40 = V_7 -> V_27 ;
F_12 () ;
V_42 = F_18 ( V_7 ) ;
if ( V_41 == V_43 ) {
V_10 -> V_17 . V_30 . V_44 . V_45 = F_19 ( & V_46 , V_42 -> V_47 ) ;
V_10 -> V_17 . V_30 . V_48 . V_49 = F_19 ( & V_46 , V_42 -> V_49 ) ;
} else if ( V_41 == V_50 ) {
V_10 -> V_17 . V_30 . V_44 . V_51 = F_20 ( & V_46 , V_42 -> V_52 ) ;
V_10 -> V_17 . V_30 . V_48 . V_53 = F_20 ( & V_46 , V_42 -> V_53 ) ;
} else {
F_14 () ;
return;
}
F_14 () ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_21 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_13 V_3 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_54 ;
V_10 -> V_17 . V_55 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_55 . V_40 = V_7 -> V_27 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_22 ( struct V_6 * V_7 , int V_56 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_13 V_3 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_57 ;
V_10 -> V_17 . V_58 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_58 . V_40 = V_7 -> V_27 ;
if ( V_56 == V_59 ) {
V_10 -> V_17 . V_58 . V_60 = V_61 -> V_25 ;
V_10 -> V_17 . V_58 . V_62 = V_61 -> V_27 ;
} else if ( V_56 == V_63 ) {
V_10 -> V_17 . V_58 . V_60 = 0 ;
V_10 -> V_17 . V_58 . V_62 = 0 ;
} else
return;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_23 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
struct V_13 V_3 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_64 ;
V_10 -> V_17 . V_65 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_65 . V_40 = V_7 -> V_27 ;
F_24 ( V_10 -> V_17 . V_65 . V_65 , V_7 ) ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
struct V_13 V_3 ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_66 ;
V_10 -> V_17 . V_67 . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . V_67 . V_40 = V_7 -> V_27 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
void F_26 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
struct V_13 V_3 ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
F_3 ( & V_8 -> V_18 , & V_10 -> V_4 ) ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_20 = V_68 ;
V_10 -> V_17 . exit . V_39 = V_7 -> V_25 ;
V_10 -> V_17 . exit . V_40 = V_7 -> V_27 ;
V_10 -> V_17 . exit . V_69 = V_7 -> V_69 ;
V_10 -> V_17 . exit . V_70 = V_7 -> V_70 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = 0 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
static void F_27 ( int V_71 , int V_72 , int V_73 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
struct V_13 V_3 ;
if ( F_9 ( & V_15 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_16 ;
memset ( & V_10 -> V_17 , 0 , sizeof( V_10 -> V_17 ) ) ;
V_8 -> V_18 = V_72 ;
F_10 ( & V_3 ) ;
V_10 -> V_19 = F_11 ( & V_3 ) ;
V_10 -> V_4 = - 1 ;
V_10 -> V_20 = V_74 ;
V_10 -> V_17 . V_32 . V_71 = V_71 ;
memcpy ( & V_8 -> V_30 , & V_31 , sizeof( V_8 -> V_30 ) ) ;
V_8 -> V_32 = V_73 + 1 ;
V_8 -> V_33 = sizeof( * V_10 ) ;
V_8 -> V_34 = 0 ;
F_15 ( V_8 , V_35 , V_36 ) ;
}
static void F_28 ( struct V_1 * V_8 ,
struct V_75 * V_76 )
{
enum V_77 * V_78 = NULL ;
int V_71 = 0 ;
if ( V_8 -> V_33 != sizeof( * V_78 ) )
return;
if ( ( F_29 () != & V_46 ) ||
( F_30 ( V_61 ) != & V_79 ) )
return;
if ( ! F_31 ( V_80 ) ) {
V_71 = V_81 ;
goto V_82;
}
V_78 = (enum V_77 * ) V_8 -> V_16 ;
switch ( * V_78 ) {
case V_83 :
F_32 ( & V_15 ) ;
break;
case V_84 :
F_33 ( & V_15 ) ;
break;
default:
V_71 = V_85 ;
break;
}
V_82:
F_27 ( V_71 , V_8 -> V_18 , V_8 -> V_32 ) ;
}
static int T_3 F_34 ( void )
{
int V_71 = F_35 ( & V_31 ,
L_1 ,
& F_28 ) ;
if ( V_71 ) {
F_36 ( L_2 ) ;
return V_71 ;
}
return 0 ;
}
