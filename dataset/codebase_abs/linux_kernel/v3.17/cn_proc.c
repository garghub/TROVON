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
struct V_6 * V_13 ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_20 ;
F_11 () ;
V_13 = F_12 ( V_7 -> V_21 ) ;
V_10 -> V_16 . V_22 . V_23 = V_13 -> V_24 ;
V_10 -> V_16 . V_22 . V_25 = V_13 -> V_26 ;
F_13 () ;
V_10 -> V_16 . V_22 . V_27 = V_7 -> V_24 ;
V_10 -> V_16 . V_22 . V_28 = V_7 -> V_26 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_36 ;
V_10 -> V_16 . V_37 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_37 . V_39 = V_7 -> V_26 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_16 ( struct V_6 * V_7 , int V_40 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
const struct V_41 * V_41 ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
V_10 -> V_19 = V_40 ;
V_10 -> V_16 . V_29 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_29 . V_39 = V_7 -> V_26 ;
F_11 () ;
V_41 = F_17 ( V_7 ) ;
if ( V_40 == V_42 ) {
V_10 -> V_16 . V_29 . V_43 . V_44 = F_18 ( & V_45 , V_41 -> V_46 ) ;
V_10 -> V_16 . V_29 . V_47 . V_48 = F_18 ( & V_45 , V_41 -> V_48 ) ;
} else if ( V_40 == V_49 ) {
V_10 -> V_16 . V_29 . V_43 . V_50 = F_19 ( & V_45 , V_41 -> V_51 ) ;
V_10 -> V_16 . V_29 . V_47 . V_52 = F_19 ( & V_45 , V_41 -> V_52 ) ;
} else {
F_13 () ;
return;
}
F_13 () ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_20 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_53 ;
V_10 -> V_16 . V_54 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_54 . V_39 = V_7 -> V_26 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_21 ( struct V_6 * V_7 , int V_55 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_56 ;
V_10 -> V_16 . V_57 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_57 . V_39 = V_7 -> V_26 ;
if ( V_55 == V_58 ) {
V_10 -> V_16 . V_57 . V_59 = V_60 -> V_24 ;
V_10 -> V_16 . V_57 . V_61 = V_60 -> V_26 ;
} else if ( V_55 == V_62 ) {
V_10 -> V_16 . V_57 . V_59 = 0 ;
V_10 -> V_16 . V_57 . V_61 = 0 ;
} else
return;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_22 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_63 ;
V_10 -> V_16 . V_64 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_64 . V_39 = V_7 -> V_26 ;
F_23 ( V_10 -> V_16 . V_64 . V_64 , V_7 ) ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_24 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_65 ;
V_10 -> V_16 . V_66 . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . V_66 . V_39 = V_7 -> V_26 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
void F_25 ( struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
F_3 ( & V_8 -> V_17 , & V_10 -> V_4 ) ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_19 = V_67 ;
V_10 -> V_16 . exit . V_38 = V_7 -> V_24 ;
V_10 -> V_16 . exit . V_39 = V_7 -> V_26 ;
V_10 -> V_16 . exit . V_68 = V_7 -> V_68 ;
V_10 -> V_16 . exit . V_69 = V_7 -> V_69 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = 0 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
static void F_26 ( int V_70 , int V_71 , int V_72 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 ;
T_1 V_2 [ V_11 ] V_12 ( 8 ) ;
if ( F_9 ( & V_14 ) < 1 )
return;
V_8 = F_1 ( V_2 ) ;
V_10 = (struct V_9 * ) V_8 -> V_15 ;
memset ( & V_10 -> V_16 , 0 , sizeof( V_10 -> V_16 ) ) ;
V_8 -> V_17 = V_71 ;
V_10 -> V_18 = F_10 () ;
V_10 -> V_4 = - 1 ;
V_10 -> V_19 = V_73 ;
V_10 -> V_16 . V_31 . V_70 = V_70 ;
memcpy ( & V_8 -> V_29 , & V_30 , sizeof( V_8 -> V_29 ) ) ;
V_8 -> V_31 = V_72 + 1 ;
V_8 -> V_32 = sizeof( * V_10 ) ;
V_8 -> V_33 = 0 ;
F_14 ( V_8 , 0 , V_34 , V_35 ) ;
}
static void F_27 ( struct V_1 * V_8 ,
struct V_74 * V_75 )
{
enum V_76 * V_77 = NULL ;
int V_70 = 0 ;
if ( V_8 -> V_32 != sizeof( * V_77 ) )
return;
if ( ( F_28 () != & V_45 ) ||
( F_29 ( V_60 ) != & V_78 ) )
return;
if ( ! F_30 ( V_75 , & V_45 , V_79 ) ) {
V_70 = V_80 ;
goto V_81;
}
V_77 = (enum V_76 * ) V_8 -> V_15 ;
switch ( * V_77 ) {
case V_82 :
F_31 ( & V_14 ) ;
break;
case V_83 :
F_32 ( & V_14 ) ;
break;
default:
V_70 = V_84 ;
break;
}
V_81:
F_26 ( V_70 , V_8 -> V_17 , V_8 -> V_31 ) ;
}
static int T_3 F_33 ( void )
{
int V_70 = F_34 ( & V_30 ,
L_1 ,
& F_27 ) ;
if ( V_70 ) {
F_35 ( L_2 ) ;
return V_70 ;
}
return 0 ;
}
