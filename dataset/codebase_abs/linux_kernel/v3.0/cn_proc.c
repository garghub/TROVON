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
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
F_1 ( & V_7 -> V_15 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
V_9 -> V_18 = V_19 ;
V_9 -> V_20 . V_21 . V_22 = V_5 -> V_23 -> V_24 ;
V_9 -> V_20 . V_21 . V_25 = V_5 -> V_23 -> V_26 ;
V_9 -> V_20 . V_21 . V_27 = V_5 -> V_24 ;
V_9 -> V_20 . V_21 . V_28 = V_5 -> V_26 ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
void F_12 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_12 V_1 ;
T_2 V_10 [ V_11 ] ;
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
F_1 ( & V_7 -> V_15 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
V_9 -> V_18 = V_35 ;
V_9 -> V_20 . V_36 . V_37 = V_5 -> V_24 ;
V_9 -> V_20 . V_36 . V_38 = V_5 -> V_26 ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
void F_13 ( struct V_4 * V_5 , int V_39 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
const struct V_40 * V_40 ;
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
V_9 -> V_18 = V_39 ;
V_9 -> V_20 . V_29 . V_37 = V_5 -> V_24 ;
V_9 -> V_20 . V_29 . V_38 = V_5 -> V_26 ;
F_14 () ;
V_40 = F_15 ( V_5 ) ;
if ( V_39 == V_41 ) {
V_9 -> V_20 . V_29 . V_42 . V_43 = V_40 -> V_44 ;
V_9 -> V_20 . V_29 . V_45 . V_46 = V_40 -> V_46 ;
} else if ( V_39 == V_47 ) {
V_9 -> V_20 . V_29 . V_42 . V_48 = V_40 -> V_49 ;
V_9 -> V_20 . V_29 . V_45 . V_50 = V_40 -> V_50 ;
} else {
F_16 () ;
return;
}
F_16 () ;
F_1 ( & V_7 -> V_15 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
void F_17 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_12 V_1 ;
T_2 V_10 [ V_11 ] ;
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
F_1 ( & V_7 -> V_15 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
V_9 -> V_18 = V_51 ;
V_9 -> V_20 . V_52 . V_37 = V_5 -> V_24 ;
V_9 -> V_20 . V_52 . V_38 = V_5 -> V_26 ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
void F_18 ( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
F_1 ( & V_7 -> V_15 , & V_9 -> V_2 ) ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
V_9 -> V_18 = V_53 ;
V_9 -> V_20 . exit . V_37 = V_5 -> V_24 ;
V_9 -> V_20 . exit . V_38 = V_5 -> V_26 ;
V_9 -> V_20 . exit . V_54 = V_5 -> V_54 ;
V_9 -> V_20 . exit . V_55 = V_5 -> V_55 ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = 0 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
static void F_19 ( int V_56 , int V_57 , int V_58 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
if ( F_7 ( & V_13 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_14 ;
V_7 -> V_15 = V_57 ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_16 * ) & V_9 -> V_17 ) ;
V_9 -> V_2 = - 1 ;
V_9 -> V_18 = V_59 ;
V_9 -> V_20 . V_31 . V_56 = V_56 ;
memcpy ( & V_7 -> V_29 , & V_30 , sizeof( V_7 -> V_29 ) ) ;
V_7 -> V_31 = V_58 + 1 ;
V_7 -> V_32 = sizeof( * V_9 ) ;
F_11 ( V_7 , V_33 , V_34 ) ;
}
static void F_20 ( struct V_6 * V_7 ,
struct V_60 * V_61 )
{
enum V_62 * V_63 = NULL ;
int V_56 = 0 ;
if ( V_7 -> V_32 != sizeof( * V_63 ) )
return;
V_63 = (enum V_62 * ) V_7 -> V_14 ;
switch ( * V_63 ) {
case V_64 :
F_21 ( & V_13 ) ;
break;
case V_65 :
F_22 ( & V_13 ) ;
break;
default:
V_56 = V_66 ;
break;
}
F_19 ( V_56 , V_7 -> V_15 , V_7 -> V_31 ) ;
}
static int T_3 F_23 ( void )
{
int V_56 ;
if ( ( V_56 = F_24 ( & V_30 , L_1 ,
& F_20 ) ) ) {
F_25 ( V_67 L_2 ) ;
return V_56 ;
}
return 0 ;
}
