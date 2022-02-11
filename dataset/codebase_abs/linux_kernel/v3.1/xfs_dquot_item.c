static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
STATIC T_1
F_3 (
struct V_2 * V_3 )
{
return 2 ;
}
STATIC void
F_4 (
struct V_2 * V_3 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_6 -> V_8 = & V_7 -> V_9 ;
V_6 -> V_10 = sizeof( V_11 ) ;
V_6 -> V_12 = V_13 ;
V_6 ++ ;
V_6 -> V_8 = & V_7 -> V_14 -> V_15 ;
V_6 -> V_10 = sizeof( V_16 ) ;
V_6 -> V_12 = V_17 ;
ASSERT ( 2 == V_3 -> V_18 -> V_19 ) ;
V_7 -> V_9 . V_20 = 2 ;
}
STATIC void
F_5 (
struct V_2 * V_3 )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_22 ) ) ;
F_7 ( & V_22 -> V_23 ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int remove )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_9 ( & V_22 -> V_23 ) > 0 ) ;
if ( F_10 ( & V_22 -> V_23 ) )
F_11 ( & V_22 -> V_24 ) ;
}
STATIC void
F_12 (
struct V_2 * V_3 )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_14 ;
int error ;
ASSERT ( F_6 ( V_22 ) ) ;
ASSERT ( ! F_13 ( & V_22 -> V_25 ) ) ;
error = F_14 ( V_22 , 0 ) ;
if ( error )
F_15 ( V_22 -> V_26 , L_1 ,
V_27 , error , V_22 ) ;
F_16 ( V_22 ) ;
}
STATIC T_2
F_17 (
struct V_2 * V_3 ,
T_2 V_28 )
{
return V_28 ;
}
void
F_18 (
struct V_21 * V_22 )
{
ASSERT ( F_6 ( V_22 ) ) ;
if ( F_9 ( & V_22 -> V_23 ) == 0 )
return;
F_19 ( V_22 -> V_26 , 0 ) ;
F_20 ( V_22 -> V_24 , ( F_9 ( & V_22 -> V_23 ) == 0 ) ) ;
}
STATIC bool
F_21 (
struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_7 -> V_14 ;
struct V_29 * V_30 ;
bool V_31 = true ;
ASSERT ( F_6 ( V_22 ) ) ;
if ( F_13 ( & V_22 -> V_25 ) ||
! ( V_3 -> V_32 & V_33 ) ) {
F_16 ( V_22 ) ;
return true ;
}
V_30 = F_22 ( V_22 -> V_26 -> V_34 , V_7 -> V_9 . V_35 ,
V_22 -> V_26 -> V_36 -> V_37 , V_38 ) ;
F_16 ( V_22 ) ;
if ( ! V_30 )
return true ;
if ( F_23 ( V_30 ) )
F_24 ( V_30 ) ;
if ( F_25 ( V_30 ) )
V_31 = false ;
F_26 ( V_30 ) ;
return V_31 ;
}
STATIC T_1
F_27 (
struct V_2 * V_3 )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_14 ;
if ( F_9 ( & V_22 -> V_23 ) > 0 )
return V_39 ;
if ( ! F_28 ( V_22 ) )
return V_40 ;
if ( ! F_29 ( V_22 ) ) {
return V_41 ;
}
ASSERT ( V_3 -> V_32 & V_33 ) ;
return V_42 ;
}
STATIC void
F_30 (
struct V_2 * V_3 )
{
struct V_21 * V_22 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_22 ) ) ;
V_22 -> V_43 = NULL ;
F_16 ( V_22 ) ;
}
STATIC void
F_31 (
struct V_2 * V_3 ,
T_2 V_28 )
{
}
void
F_32 (
struct V_21 * V_22 )
{
struct V_1 * V_44 = & V_22 -> V_45 ;
F_33 ( V_22 -> V_26 , & V_44 -> V_4 , V_46 ,
& V_47 ) ;
V_44 -> V_14 = V_22 ;
V_44 -> V_9 . V_48 = V_46 ;
V_44 -> V_9 . V_49 = F_34 ( V_22 -> V_15 . V_50 ) ;
V_44 -> V_9 . V_35 = V_22 -> V_51 ;
V_44 -> V_9 . V_52 = 1 ;
V_44 -> V_9 . V_53 = ( V_54 ) V_22 -> V_55 ;
}
static inline struct V_56 * F_35 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_56 , V_57 ) ;
}
STATIC T_1
F_36 (
struct V_2 * V_3 )
{
return 1 ;
}
STATIC void
F_37 (
struct V_2 * V_3 ,
struct V_5 * V_58 )
{
struct V_56 * V_59 = F_35 ( V_3 ) ;
ASSERT ( V_59 -> V_60 . V_61 == V_62 ) ;
V_58 -> V_8 = & V_59 -> V_60 ;
V_58 -> V_10 = sizeof( V_63 ) ;
V_58 -> V_12 = V_64 ;
V_59 -> V_60 . V_65 = 1 ;
}
STATIC void
F_38 (
struct V_2 * V_3 )
{
}
STATIC void
F_39 (
struct V_2 * V_3 ,
int remove )
{
}
STATIC T_1
F_40 (
struct V_2 * V_3 )
{
return V_40 ;
}
STATIC void
F_41 (
struct V_2 * V_3 )
{
}
STATIC T_2
F_42 (
struct V_2 * V_3 ,
T_2 V_28 )
{
return V_28 ;
}
STATIC void
F_43 (
struct V_2 * V_3 )
{
}
STATIC T_2
F_44 (
struct V_2 * V_3 ,
T_2 V_28 )
{
struct V_56 * V_66 = F_35 ( V_3 ) ;
struct V_56 * V_67 = V_66 -> V_68 ;
struct V_69 * V_70 = V_67 -> V_57 . V_71 ;
F_45 ( & V_70 -> V_72 ) ;
F_46 ( V_70 , ( V_73 * ) V_67 ) ;
F_47 ( V_67 ) ;
F_47 ( V_66 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_48 (
struct V_2 * V_3 ,
T_2 V_74 )
{
}
struct V_56 *
F_49 (
struct V_75 * V_76 ,
struct V_56 * V_77 ,
T_1 V_78 )
{
struct V_56 * V_79 ;
V_79 = F_50 ( sizeof( struct V_56 ) , V_80 ) ;
F_33 ( V_76 , & V_79 -> V_57 , V_62 , V_77 ?
& V_81 : & V_82 ) ;
V_79 -> V_57 . V_83 = V_76 ;
V_79 -> V_60 . V_61 = V_62 ;
V_79 -> V_60 . V_84 = V_78 ;
V_79 -> V_68 = V_77 ;
return V_79 ;
}
