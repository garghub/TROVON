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
V_9 -> V_22 . V_30 . V_43 . V_44 = F_18 ( & V_45 , V_41 -> V_46 ) ;
V_9 -> V_22 . V_30 . V_47 . V_48 = F_18 ( & V_45 , V_41 -> V_48 ) ;
} else if ( V_40 == V_49 ) {
V_9 -> V_22 . V_30 . V_43 . V_50 = F_19 ( & V_45 , V_41 -> V_51 ) ;
V_9 -> V_22 . V_30 . V_47 . V_52 = F_19 ( & V_45 , V_41 -> V_52 ) ;
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
void F_20 ( struct V_4 * V_5 )
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
V_9 -> V_19 = V_53 ;
V_9 -> V_22 . V_54 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_54 . V_39 = V_5 -> V_27 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_21 ( struct V_4 * V_5 , int V_55 )
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
V_9 -> V_19 = V_56 ;
V_9 -> V_22 . V_57 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_57 . V_39 = V_5 -> V_27 ;
if ( V_55 == V_58 ) {
V_9 -> V_22 . V_57 . V_59 = V_60 -> V_25 ;
V_9 -> V_22 . V_57 . V_61 = V_60 -> V_27 ;
} else if ( V_55 == V_62 ) {
V_9 -> V_22 . V_57 . V_59 = 0 ;
V_9 -> V_22 . V_57 . V_61 = 0 ;
} else
return;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_22 ( struct V_4 * V_5 )
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
V_9 -> V_19 = V_63 ;
V_9 -> V_22 . V_64 . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . V_64 . V_39 = V_5 -> V_27 ;
F_23 ( V_9 -> V_22 . V_64 . V_64 , V_5 ) ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
void F_24 ( struct V_4 * V_5 )
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
V_9 -> V_19 = V_65 ;
V_9 -> V_22 . exit . V_38 = V_5 -> V_25 ;
V_9 -> V_22 . exit . V_39 = V_5 -> V_27 ;
V_9 -> V_22 . exit . V_66 = V_5 -> V_66 ;
V_9 -> V_22 . exit . V_67 = V_5 -> V_67 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
static void F_25 ( int V_68 , int V_69 , int V_70 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_2 V_10 [ V_11 ] ;
struct V_12 V_1 ;
if ( F_7 ( & V_14 ) < 1 )
return;
V_7 = (struct V_6 * ) V_10 ;
V_9 = (struct V_8 * ) V_7 -> V_15 ;
V_7 -> V_16 = V_69 ;
F_8 ( & V_1 ) ;
F_9 ( F_10 ( & V_1 ) , ( V_17 * ) & V_9 -> V_18 ) ;
V_9 -> V_2 = - 1 ;
V_9 -> V_19 = V_71 ;
V_9 -> V_22 . V_32 . V_68 = V_68 ;
memcpy ( & V_7 -> V_30 , & V_31 , sizeof( V_7 -> V_30 ) ) ;
V_7 -> V_32 = V_70 + 1 ;
V_7 -> V_33 = sizeof( * V_9 ) ;
F_14 ( V_7 , V_34 , V_35 ) ;
}
static void F_26 ( struct V_6 * V_7 ,
struct V_72 * V_73 )
{
enum V_74 * V_75 = NULL ;
int V_68 = 0 ;
if ( V_7 -> V_33 != sizeof( * V_75 ) )
return;
if ( ( F_27 () != & V_45 ) ||
( F_28 ( V_60 ) != & V_76 ) )
return;
V_75 = (enum V_74 * ) V_7 -> V_15 ;
switch ( * V_75 ) {
case V_77 :
F_29 ( & V_14 ) ;
break;
case V_78 :
F_30 ( & V_14 ) ;
break;
default:
V_68 = V_79 ;
break;
}
F_25 ( V_68 , V_7 -> V_16 , V_7 -> V_32 ) ;
}
static int T_3 F_31 ( void )
{
int V_68 = F_32 ( & V_31 ,
L_1 ,
& F_26 ) ;
if ( V_68 ) {
F_33 ( L_2 ) ;
return V_68 ;
}
return 0 ;
}
