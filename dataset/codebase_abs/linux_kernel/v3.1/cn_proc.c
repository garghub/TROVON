static inline void F_1 ( T_1 * V_1 , int * V_2 )
{
F_2 () ;
* V_1 = F_3 ( V_3 ) - 1 ;
* V_2 = F_4 () ;
F_5 () ;
}
void F_6 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
struct V_4 * V_13 ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_19 = V_20 ;
F_11 () ;
V_13 = F_12 ( V_5 -> V_21 ) ;
V_9 -> V_22 . V_23 . V_24 = V_13 -> V_25 ;
V_9 -> V_22 . V_23 . V_26 = V_13 -> V_27 ;
F_13 () ;
V_9 -> V_22 . V_23 . V_28 = V_5 -> V_25 ;
V_9 -> V_22 . V_23 . V_29 = V_5 -> V_27 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_15 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_12 V_1 ;
T_2 V_10 [ V_11 ] ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_19 = V_36 ;
V_9 -> V_22 . V_37 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_37 . V_39 = V_5 -> V_27 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_16 ( struct V_4 * V_5 , int V_40 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
const struct V_41 * V_41 ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
V_9 -> V_19 = V_40 ;
V_9 -> V_22 . V_30 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_30 . V_39 = V_5 -> V_27 ;
F_11 () ;
V_41 = F_17 ( V_5 ) ;
if ( V_40 == V_42 ) {
V_9 -> V_22 . V_30 . V_43 . V_44 = V_41 -> V_45 ;
V_9 -> V_22 . V_30 . V_46 . V_47 = V_41 -> V_47 ;
} else if ( V_40 == V_48 ) {
V_9 -> V_22 . V_30 . V_43 . V_49 = V_41 -> V_50 ;
V_9 -> V_22 . V_30 . V_46 . V_51 = V_41 -> V_51 ;
} else {
F_13 () ;
return;
}
F_13 () ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_12 V_1 ;
T_2 V_10 [ V_11 ] ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_19 = V_52 ;
V_9 -> V_22 . V_53 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_53 . V_39 = V_5 -> V_27 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_19 ( struct V_4 * V_5 , int V_54 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_12 V_1 ;
T_2 V_10 [ V_11 ] ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_19 = V_55 ;
V_9 -> V_22 . V_56 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_56 . V_39 = V_5 -> V_27 ;
if ( V_54 == V_57 ) {
V_9 -> V_22 . V_56 . V_58 = V_59 -> V_25 ;
V_9 -> V_22 . V_56 . V_60 = V_59 -> V_27 ;
} else if ( V_54 == V_61 ) {
V_9 -> V_22 . V_56 . V_58 = 0 ;
V_9 -> V_22 . V_56 . V_60 = 0 ;
} else
return;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_20 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
F_1 ( & V_7 -> V_16 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_19 = V_62 ;
V_9 -> V_22 . exit . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . exit . V_39 = V_5 -> V_27 ;
V_9 -> V_22 . exit . V_63 = V_5 -> V_63 ;
V_9 -> V_22 . exit . V_64 = V_5 -> V_64 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
static void F_21 ( int V_65 , int V_66 , int V_67 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
V_7 -> V_16 = V_66 ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_2 = - 1 ;
V_9 -> V_19 = V_68 ;
V_9 -> V_22 . V_32 . V_65 = V_65 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = V_67 + 1 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
static void F_22 ( struct V_6 * V_7 ,
struct V_69 * V_70 )
{
enum V_71 * V_72 = NULL ;
int V_65 = 0 ;
if ( V_7 -> V_33 != sizeof( * V_72 ) )
return;
V_72 = (enum V_71 * ) V_7 -> V_15 ;
switch ( * V_72 ) {
case V_73 :
F_23 ( & V_14 ) ;
break;
case V_74 :
F_24 ( & V_14 ) ;
break;
default:
V_65 = V_75 ;
break;
}
F_21 ( V_65 , V_7 -> V_16 , V_7 -> V_32 ) ;
}
static int T_3 F_25 ( void )
{
int V_65 ;
if ( ( V_65 = F_26 ( & V_31 , L_1 ,
& F_22 ) ) ) {
F_27 ( V_76 L_2 ) ;
return V_65 ;
}
return 0 ;
}
