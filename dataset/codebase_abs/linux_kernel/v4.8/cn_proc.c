static inline struct V_1 * F_1 ( T_1 * V_2 )
{
F_2 ( sizeof( struct V_1 ) != 20 ) ;
return (struct V_1 * ) ( V_2 + 4 ) ;
}
static inline void F_3 ( struct V_1 * V_3 )
{
F_4 () ;
V_3 -> V_4 = F_5 ( V_5 ) - 1 ;
( (struct V_6 * ) V_3 -> V_7 ) -> V_8 = F_6 () ;
F_7 ( V_3 , 0 , V_9 , V_10 ) ;
F_8 () ;
}
void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
struct V_11 * V_16 ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_21 ;
F_12 () ;
V_16 = F_13 ( V_12 -> V_22 ) ;
V_13 -> V_18 . V_23 . V_24 = V_16 -> V_25 ;
V_13 -> V_18 . V_23 . V_26 = V_16 -> V_27 ;
F_14 () ;
V_13 -> V_18 . V_23 . V_28 = V_12 -> V_25 ;
V_13 -> V_18 . V_23 . V_29 = V_12 -> V_27 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_35 ;
V_13 -> V_18 . V_36 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_36 . V_38 = V_12 -> V_27 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_16 ( struct V_11 * V_12 , int V_39 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
const struct V_40 * V_40 ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_20 = V_39 ;
V_13 -> V_18 . V_30 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_30 . V_38 = V_12 -> V_27 ;
F_12 () ;
V_40 = F_17 ( V_12 ) ;
if ( V_39 == V_41 ) {
V_13 -> V_18 . V_30 . V_42 . V_43 = F_18 ( & V_44 , V_40 -> V_45 ) ;
V_13 -> V_18 . V_30 . V_46 . V_47 = F_18 ( & V_44 , V_40 -> V_47 ) ;
} else if ( V_39 == V_48 ) {
V_13 -> V_18 . V_30 . V_42 . V_49 = F_19 ( & V_44 , V_40 -> V_50 ) ;
V_13 -> V_18 . V_30 . V_46 . V_51 = F_19 ( & V_44 , V_40 -> V_51 ) ;
} else {
F_14 () ;
return;
}
F_14 () ;
V_13 -> V_19 = F_11 () ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_52 ;
V_13 -> V_18 . V_53 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_53 . V_38 = V_12 -> V_27 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_21 ( struct V_11 * V_12 , int V_54 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_55 ;
V_13 -> V_18 . V_56 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_56 . V_38 = V_12 -> V_27 ;
if ( V_54 == V_57 ) {
V_13 -> V_18 . V_56 . V_58 = V_59 -> V_25 ;
V_13 -> V_18 . V_56 . V_60 = V_59 -> V_27 ;
} else if ( V_54 == V_61 ) {
V_13 -> V_18 . V_56 . V_58 = 0 ;
V_13 -> V_18 . V_56 . V_60 = 0 ;
} else
return;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_22 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_62 ;
V_13 -> V_18 . V_63 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_63 . V_38 = V_12 -> V_27 ;
F_23 ( V_13 -> V_18 . V_63 . V_63 , V_12 ) ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_64 ;
V_13 -> V_18 . V_65 . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . V_65 . V_38 = V_12 -> V_27 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
void F_25 ( struct V_11 * V_12 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_20 = V_66 ;
V_13 -> V_18 . exit . V_37 = V_12 -> V_25 ;
V_13 -> V_18 . exit . V_38 = V_12 -> V_27 ;
V_13 -> V_18 . exit . V_67 = V_12 -> V_67 ;
V_13 -> V_18 . exit . V_68 = V_12 -> V_68 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
static void F_26 ( int V_69 , int V_70 , int V_71 )
{
struct V_1 * V_3 ;
struct V_6 * V_13 ;
T_1 V_2 [ V_14 ] V_15 ( 8 ) ;
if ( F_10 ( & V_17 ) < 1 )
return;
V_3 = F_1 ( V_2 ) ;
V_13 = (struct V_6 * ) V_3 -> V_7 ;
memset ( & V_13 -> V_18 , 0 , sizeof( V_13 -> V_18 ) ) ;
V_3 -> V_4 = V_70 ;
V_13 -> V_19 = F_11 () ;
V_13 -> V_8 = - 1 ;
V_13 -> V_20 = V_72 ;
V_13 -> V_18 . V_32 . V_69 = V_69 ;
memcpy ( & V_3 -> V_30 , & V_31 , sizeof( V_3 -> V_30 ) ) ;
V_3 -> V_32 = V_71 + 1 ;
V_3 -> V_33 = sizeof( * V_13 ) ;
V_3 -> V_34 = 0 ;
F_3 ( V_3 ) ;
}
static void F_27 ( struct V_1 * V_3 ,
struct V_73 * V_74 )
{
enum V_75 * V_76 = NULL ;
int V_69 = 0 ;
if ( V_3 -> V_33 != sizeof( * V_76 ) )
return;
if ( ( F_28 () != & V_44 ) ||
( F_29 ( V_59 ) != & V_77 ) )
return;
if ( ! F_30 ( V_74 , & V_44 , V_78 ) ) {
V_69 = V_79 ;
goto V_80;
}
V_76 = (enum V_75 * ) V_3 -> V_7 ;
switch ( * V_76 ) {
case V_81 :
F_31 ( & V_17 ) ;
break;
case V_82 :
F_32 ( & V_17 ) ;
break;
default:
V_69 = V_83 ;
break;
}
V_80:
F_26 ( V_69 , V_3 -> V_4 , V_3 -> V_32 ) ;
}
static int T_2 F_33 ( void )
{
int V_69 = F_34 ( & V_31 ,
L_1 ,
& F_27 ) ;
if ( V_69 ) {
F_35 ( L_2 ) ;
return V_69 ;
}
return 0 ;
}
