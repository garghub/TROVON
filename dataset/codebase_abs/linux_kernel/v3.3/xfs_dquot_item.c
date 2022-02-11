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
V_7 -> V_9 . V_18 = 2 ;
}
STATIC void
F_5 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_20 ) ) ;
F_7 ( & V_20 -> V_21 ) ;
}
STATIC void
F_8 (
struct V_2 * V_3 ,
int remove )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_9 ( & V_20 -> V_21 ) > 0 ) ;
if ( F_10 ( & V_20 -> V_21 ) )
F_11 ( & V_20 -> V_22 ) ;
}
STATIC void
F_12 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
int error ;
ASSERT ( F_6 ( V_20 ) ) ;
ASSERT ( ! F_13 ( & V_20 -> V_23 ) ) ;
error = F_14 ( V_20 , V_24 ) ;
if ( error )
F_15 ( V_20 -> V_25 , L_1 ,
V_26 , error , V_20 ) ;
F_16 ( V_20 ) ;
}
STATIC T_2
F_17 (
struct V_2 * V_3 ,
T_2 V_27 )
{
return V_27 ;
}
void
F_18 (
struct V_19 * V_20 )
{
ASSERT ( F_6 ( V_20 ) ) ;
if ( F_9 ( & V_20 -> V_21 ) == 0 )
return;
F_19 ( V_20 -> V_25 , 0 ) ;
F_20 ( V_20 -> V_22 , ( F_9 ( & V_20 -> V_21 ) == 0 ) ) ;
}
STATIC bool
F_21 (
struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_19 * V_20 = V_7 -> V_14 ;
struct V_28 * V_29 ;
bool V_30 = true ;
ASSERT ( F_6 ( V_20 ) ) ;
if ( F_13 ( & V_20 -> V_23 ) ||
! ( V_3 -> V_31 & V_32 ) ) {
F_16 ( V_20 ) ;
return true ;
}
V_29 = F_22 ( V_20 -> V_25 -> V_33 , V_7 -> V_9 . V_34 ,
V_20 -> V_25 -> V_35 -> V_36 , V_37 ) ;
F_16 ( V_20 ) ;
if ( ! V_29 )
return true ;
if ( F_23 ( V_29 ) )
F_24 ( V_29 ) ;
if ( F_25 ( V_29 ) )
V_30 = false ;
F_26 ( V_29 ) ;
return V_30 ;
}
STATIC T_1
F_27 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
if ( F_9 ( & V_20 -> V_21 ) > 0 )
return V_38 ;
if ( ! F_28 ( V_20 ) )
return V_39 ;
if ( ! F_29 ( V_20 ) ) {
return V_40 ;
}
ASSERT ( V_3 -> V_31 & V_32 ) ;
return V_41 ;
}
STATIC void
F_30 (
struct V_2 * V_3 )
{
struct V_19 * V_20 = F_1 ( V_3 ) -> V_14 ;
ASSERT ( F_6 ( V_20 ) ) ;
V_20 -> V_42 = NULL ;
F_16 ( V_20 ) ;
}
STATIC void
F_31 (
struct V_2 * V_3 ,
T_2 V_27 )
{
}
void
F_32 (
struct V_19 * V_20 )
{
struct V_1 * V_43 = & V_20 -> V_44 ;
F_33 ( V_20 -> V_25 , & V_43 -> V_4 , V_45 ,
& V_46 ) ;
V_43 -> V_14 = V_20 ;
V_43 -> V_9 . V_47 = V_45 ;
V_43 -> V_9 . V_48 = F_34 ( V_20 -> V_15 . V_49 ) ;
V_43 -> V_9 . V_34 = V_20 -> V_50 ;
V_43 -> V_9 . V_51 = 1 ;
V_43 -> V_9 . V_52 = ( V_53 ) V_20 -> V_54 ;
}
static inline struct V_55 * F_35 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_55 , V_56 ) ;
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
struct V_5 * V_57 )
{
struct V_55 * V_58 = F_35 ( V_3 ) ;
ASSERT ( V_58 -> V_59 . V_60 == V_61 ) ;
V_57 -> V_8 = & V_58 -> V_59 ;
V_57 -> V_10 = sizeof( V_62 ) ;
V_57 -> V_12 = V_63 ;
V_58 -> V_59 . V_64 = 1 ;
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
return V_39 ;
}
STATIC void
F_41 (
struct V_2 * V_3 )
{
}
STATIC T_2
F_42 (
struct V_2 * V_3 ,
T_2 V_27 )
{
return V_27 ;
}
STATIC void
F_43 (
struct V_2 * V_3 )
{
}
STATIC T_2
F_44 (
struct V_2 * V_3 ,
T_2 V_27 )
{
struct V_55 * V_65 = F_35 ( V_3 ) ;
struct V_55 * V_66 = V_65 -> V_67 ;
struct V_68 * V_69 = V_66 -> V_56 . V_70 ;
F_45 ( & V_69 -> V_71 ) ;
F_46 ( V_69 , ( V_72 * ) V_66 ) ;
F_47 ( V_66 ) ;
F_47 ( V_65 ) ;
return ( T_2 ) - 1 ;
}
STATIC void
F_48 (
struct V_2 * V_3 ,
T_2 V_73 )
{
}
struct V_55 *
F_49 (
struct V_74 * V_75 ,
struct V_55 * V_76 ,
T_1 V_77 )
{
struct V_55 * V_78 ;
V_78 = F_50 ( sizeof( struct V_55 ) , V_79 ) ;
F_33 ( V_75 , & V_78 -> V_56 , V_61 , V_76 ?
& V_80 : & V_81 ) ;
V_78 -> V_56 . V_82 = V_75 ;
V_78 -> V_59 . V_60 = V_61 ;
V_78 -> V_59 . V_83 = V_77 ;
V_78 -> V_67 = V_76 ;
return V_78 ;
}
